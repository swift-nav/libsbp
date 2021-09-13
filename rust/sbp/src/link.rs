use std::{
    borrow::{Borrow, Cow},
    convert::TryInto,
    sync::{Arc, Mutex},
};

use slotmap::DenseSlotMap;

use crate::messages::{ConcreteMessage, SBPMessage, SBP};

pub struct LinkSource<'link, S = ()> {
    link: Link<'link, S>,
    stateless_link: Link<'link, ()>,
}

impl<'link, S> LinkSource<'link, S>
where
    S: 'link,
{
    pub fn new() -> Self {
        Self {
            link: Link::new(),
            stateless_link: Link::new(),
        }
    }

    pub fn link(&self) -> Link<'link, S> {
        self.link.clone()
    }

    pub fn stateless_link(&self) -> Link<'link, ()> {
        self.stateless_link.clone()
    }

    pub fn send_with_state<M>(&self, state: &S, msg: M) -> bool
    where
        M: Borrow<SBP>,
    {
        let msg = msg.borrow();
        let mut sent = false;
        {
            let mut handlers = self.link.inner.handlers.lock().unwrap();
            for handler in handlers.values_mut() {
                if handler.can_run(&msg) {
                    handler.run(state, msg.clone());
                    sent = true;
                }
            }
        }
        {
            let mut handlers = self.stateless_link.inner.handlers.lock().unwrap();
            for handler in handlers.values_mut() {
                if handler.can_run(&msg) {
                    handler.run(&(), msg.clone());
                    sent = true;
                }
            }
        }
        sent
    }
}

impl<'link> LinkSource<'link, ()> {
    pub fn send<M>(&self, msg: M) -> bool
    where
        M: Borrow<SBP>,
    {
        self.send_with_state(&(), msg)
    }
}

pub struct Link<'link, S> {
    inner: Arc<LinkInner<'link, S>>,
}

impl<'link, S> Link<'link, S> {
    fn new() -> Self {
        Self {
            inner: Arc::new(LinkInner {
                handlers: Mutex::new(DenseSlotMap::with_key()),
            }),
        }
    }

    pub fn register<E, F, HandlerKind>(&self, callback: F) -> Key
    where
        E: Event,
        F: IntoHandler<'link, S, E, HandlerKind>,
    {
        let mut handlers = self.inner.handlers.lock().unwrap();
        let key = handlers.insert(callback.into_handler());
        Key { key }
    }

    pub fn register_by_id<E, F, HandlerKind>(&self, msg_types: &[u16], callback: F) -> Key
    where
        E: Event,
        F: IntoHandler<'link, S, E, HandlerKind>,
    {
        let mut handlers = self.inner.handlers.lock().unwrap();
        let key = handlers.insert(callback.into_handler_with_ids(msg_types));
        Key { key }
    }

    pub fn unregister(&self, key: Key) {
        self.inner.handlers.lock().unwrap().remove(key.key);
    }
}

impl<'link, S> Clone for Link<'link, S> {
    fn clone(&self) -> Self {
        Self {
            inner: Arc::clone(&self.inner),
        }
    }
}

struct LinkInner<'link, S> {
    handlers: Mutex<DenseSlotMap<KeyInner, Handler<'link, S>>>,
}

pub struct Handler<'link, S> {
    func: Box<dyn FnMut(&S, SBP) + Send + 'link>,
    msg_types: Cow<'static, [u16]>,
}

impl<'link, S> Handler<'link, S> {
    fn run(&mut self, state: &S, msg: SBP) {
        (self.func)(state, msg);
    }

    fn can_run(&self, msg: &SBP) -> bool {
        self.msg_types.contains(&msg.get_message_type()) || self.msg_types.is_empty()
    }
}

pub trait IntoHandler<'link, S, E, HandlerKind = WithState> {
    fn into_handler(self) -> Handler<'link, S>;
    fn into_handler_with_ids(self, msg_types: &[u16]) -> Handler<'link, S>;
}

pub struct WithState;

impl<'link, S, E, F> IntoHandler<'link, S, E, WithState> for F
where
    E: Event,
    F: FnMut(&S, E) + Send + 'link,
{
    fn into_handler(mut self) -> Handler<'link, S> {
        Handler {
            func: Box::new(move |state, msg| {
                let event = E::from_sbp(msg);
                self(state, event);
            }),
            msg_types: Cow::Borrowed(E::MESSAGE_TYPES),
        }
    }

    fn into_handler_with_ids(mut self, msg_types: &[u16]) -> Handler<'link, S> {
        Handler {
            func: Box::new(move |state, msg| {
                let event = E::from_sbp(msg);
                self(state, event);
            }),
            msg_types: Cow::Owned(msg_types.to_vec()),
        }
    }
}

pub struct WithoutState;

impl<'link, S, E, F> IntoHandler<'link, S, E, WithoutState> for F
where
    E: Event,
    F: FnMut(E) + Send + 'link,
{
    fn into_handler(mut self) -> Handler<'link, S> {
        Handler {
            func: Box::new(move |_state, msg| {
                let event = E::from_sbp(msg);
                self(event);
            }),
            msg_types: Cow::Borrowed(E::MESSAGE_TYPES),
        }
    }

    fn into_handler_with_ids(mut self, msg_types: &[u16]) -> Handler<'link, S> {
        Handler {
            func: Box::new(move |_state, msg| {
                let event = E::from_sbp(msg);
                self(event);
            }),
            msg_types: Cow::Owned(msg_types.to_vec()),
        }
    }
}

slotmap::new_key_type! {
    struct KeyInner;
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Key {
    key: KeyInner,
}

pub trait Event {
    const MESSAGE_TYPES: &'static [u16];

    fn from_sbp(msg: SBP) -> Self;
}

impl Event for SBP {
    const MESSAGE_TYPES: &'static [u16] = &[];

    fn from_sbp(msg: SBP) -> Self {
        msg
    }
}

impl<T> Event for T
where
    T: ConcreteMessage,
{
    const MESSAGE_TYPES: &'static [u16] = &[T::MESSAGE_TYPE];

    fn from_sbp(msg: SBP) -> Self {
        match msg.try_into() {
            Ok(event) => event,
            Err(_) => {
                panic!(
                    "invalid message type for event {}",
                    std::any::type_name::<T>()
                );
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use std::{cell::RefCell, sync::mpsc::channel, thread, time::Duration};

    use crate::messages::{
        self,
        observation::{MsgObs, MsgObsDepA, ObservationHeader, ObservationHeaderDep},
    };

    use super::*;

    #[test]
    fn test_link_triggered() {
        let source = LinkSource::new();
        let link = source.link();
        let triggered = RefCell::new(false);
        link.register(|triggered: &RefCell<bool>, _: SBP| {
            *triggered.borrow_mut() = true;
        });
        source.send_with_state(&triggered, SBP::from(make_msg_obs()));
        assert!(*triggered.borrow());
    }

    #[test]
    fn test_link_multi_thd() {
        let (s, r) = channel();

        let source = LinkSource::new();
        let link = source.link();
        let triggered = RefCell::new(false);

        let handle = thread::spawn(move || {
            link.register(|triggered: &RefCell<bool>, _: SBP| {
                *triggered.borrow_mut() = true;
            });
            s.send(()).unwrap();
        });
        r.recv_timeout(Duration::from_secs(1)).unwrap();

        source.send_with_state(&triggered, SBP::from(make_msg_obs()));

        handle.join().unwrap();

        assert!(*triggered.borrow());
    }

    #[test]
    fn test_link_no_state() {
        let mut triggered = false;
        {
            let source = LinkSource::new();
            let link = source.link();
            link.register(|_: SBP| {
                triggered = true;
            });
            source.send(SBP::from(make_msg_obs()));
        }
        assert!(triggered);
    }

    #[test]
    fn test_link_remove() {
        let source = LinkSource::new();
        let link = source.link();
        let count = RefCell::new(0);

        let key = link.register(|count: &RefCell<usize>, _: SBP| {
            *count.borrow_mut() += 1;
        });

        let msg = SBP::from(make_msg_obs());
        source.send_with_state(&count, &msg);
        assert_eq!(*count.borrow(), 1);

        link.unregister(key);
        source.send_with_state(&count, &msg);
        assert_eq!(*count.borrow(), 1);
    }

    #[test]
    fn test_custom_event() {
        enum ObsMsg {
            Obs(MsgObs),
            DepA(MsgObsDepA),
        }

        impl Event for ObsMsg {
            const MESSAGE_TYPES: &'static [u16] = &[MsgObs::MESSAGE_TYPE, MsgObsDepA::MESSAGE_TYPE];
            fn from_sbp(msg: SBP) -> Self {
                match msg {
                    SBP::MsgObs(m) => ObsMsg::Obs(m),
                    SBP::MsgObsDepA(m) => ObsMsg::DepA(m),
                    _ => unreachable!("wrong event keys"),
                }
            }
        }

        let source = LinkSource::new();
        let link = source.link();
        let count = RefCell::new(0);

        link.register(|count: &RefCell<usize>, _: ObsMsg| {
            *count.borrow_mut() += 1;
        });

        source.send_with_state(&count, SBP::from(make_msg_obs()));
        assert_eq!(*count.borrow(), 1);

        source.send_with_state(&count, SBP::from(make_msg_obs_dep_a()));
        assert_eq!(*count.borrow(), 2);
    }

    fn make_msg_obs() -> MsgObs {
        MsgObs {
            sender_id: Some(1),
            header: ObservationHeader {
                t: messages::gnss::GPSTime {
                    tow: 1,
                    ns_residual: 1,
                    wn: 1,
                },
                n_obs: 1,
            },
            obs: vec![],
        }
    }

    fn make_msg_obs_dep_a() -> MsgObsDepA {
        MsgObsDepA {
            sender_id: Some(1),
            header: ObservationHeaderDep {
                t: messages::gnss::GPSTimeDep { tow: 1, wn: 1 },
                n_obs: 1,
            },
            obs: vec![],
        }
    }
}
