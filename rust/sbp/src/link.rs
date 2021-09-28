//! Callback based message handler.

use std::{
    borrow::{Borrow, Cow},
    convert::TryInto,
    sync::{Arc, Mutex},
};

use slotmap::DenseSlotMap;

use crate::messages::{ConcreteMessage, Sbp, SbpMessage};

/// Used to send messages to callbacks registered via [Link]s created from this `LinkSource`.
pub struct LinkSource<'link, S = ()> {
    link: Link<'link, S>,
    stateless_link: Link<'link, ()>,
}

impl<'link, S> LinkSource<'link, S>
where
    S: 'link,
{
    /// Creates a new `LinkSource`.
    pub fn new() -> Self {
        Self {
            link: Link::new(),
            stateless_link: Link::new(),
        }
    }

    /// Creates a new [Link] associated with this source.
    pub fn link(&self) -> Link<'link, S> {
        self.link.clone()
    }

    /// Creates a new [Link] associated with this source. Handlers attached via this link
    /// will not receive the shared state associated with this LinkSource.
    pub fn stateless_link(&self) -> Link<'link, ()> {
        self.stateless_link.clone()
    }

    /// Send a message with state to all the links associated with this source.
    pub fn send_with_state<M>(&self, state: &S, msg: M) -> bool
    where
        M: Borrow<Sbp>,
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
    /// Send a message to all the links associated with this source.
    pub fn send<M>(&self, msg: M) -> bool
    where
        M: Borrow<Sbp>,
    {
        self.send_with_state(&(), msg)
    }
}

impl<'link, S> Default for LinkSource<'link, S>
where
    S: 'link,
{
    fn default() -> Self {
        Self::new()
    }
}

/// Used to attach message handlers.
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

    /// Register a new callback.
    pub fn register<E, F, HandlerKind>(&self, callback: F) -> Key
    where
        E: Event,
        F: IntoHandler<'link, S, E, HandlerKind>,
    {
        let mut handlers = self.inner.handlers.lock().unwrap();
        let key = handlers.insert(callback.into_handler());
        Key { key }
    }

    /// Register a new callback with manually specified message types.
    pub fn register_by_id<E, F, HandlerKind>(&self, msg_types: &[u16], callback: F) -> Key
    where
        E: Event,
        F: IntoHandler<'link, S, E, HandlerKind>,
    {
        let mut handlers = self.inner.handlers.lock().unwrap();
        let key = handlers.insert(callback.into_handler_with_ids(msg_types));
        Key { key }
    }

    /// Remove a previously registered callback.
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

/// A message handler and the message ids it responds to.
pub struct Handler<'link, S> {
    func: Box<dyn FnMut(&S, Sbp) + Send + 'link>,
    msg_types: Cow<'static, [u16]>,
}

impl<'link, S> Handler<'link, S> {
    fn run(&mut self, state: &S, msg: Sbp) {
        (self.func)(state, msg);
    }

    fn can_run(&self, msg: &Sbp) -> bool {
        self.msg_types.contains(&msg.message_type()) || self.msg_types.is_empty()
    }
}

pub trait IntoHandler<'link, S, E, HandlerKind = WithState> {
    fn into_handler(self) -> Handler<'link, S>;
    fn into_handler_with_ids(self, msg_types: &[u16]) -> Handler<'link, S>;
}

/// Marker type for handlers that receive the [LinkSource]'s shared state.
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

/// Marker type for handlers that do not receive the [LinkSource]'s shared state.
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

/// Returned when registering a callback. Can be used to unregister the callback.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Key {
    key: KeyInner,
}

/// Something derived from an SBP message.
pub trait Event {
    /// The message types that correspond to this event. An empty slice means all messages.
    const MESSAGE_TYPES: &'static [u16];

    /// Create an instance of this event from an SBP message. This message will only be called
    /// if the message type is in `Event::MESSAGE_TYPES`.
    fn from_sbp(msg: Sbp) -> Self;
}

impl Event for Sbp {
    const MESSAGE_TYPES: &'static [u16] = &[];

    fn from_sbp(msg: Sbp) -> Self {
        msg
    }
}

impl<T> Event for T
where
    T: ConcreteMessage,
{
    const MESSAGE_TYPES: &'static [u16] = &[T::MESSAGE_TYPE];

    fn from_sbp(msg: Sbp) -> Self {
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
        link.register(|triggered: &RefCell<bool>, _: Sbp| {
            *triggered.borrow_mut() = true;
        });
        source.send_with_state(&triggered, Sbp::from(make_msg_obs()));
        assert!(*triggered.borrow());
    }

    #[test]
    fn test_link_multi_thd() {
        let (s, r) = channel();

        let source = LinkSource::new();
        let link = source.link();
        let triggered = RefCell::new(false);

        let handle = thread::spawn(move || {
            link.register(|triggered: &RefCell<bool>, _: Sbp| {
                *triggered.borrow_mut() = true;
            });
            s.send(()).unwrap();
        });
        r.recv_timeout(Duration::from_secs(1)).unwrap();

        source.send_with_state(&triggered, Sbp::from(make_msg_obs()));

        handle.join().unwrap();

        assert!(*triggered.borrow());
    }

    #[test]
    fn test_link_no_state() {
        let mut triggered = false;
        {
            let source = LinkSource::new();
            let link = source.link();
            link.register(|_: Sbp| {
                triggered = true;
            });
            source.send(Sbp::from(make_msg_obs()));
        }
        assert!(triggered);
    }

    #[test]
    fn test_link_remove() {
        let source = LinkSource::new();
        let link = source.link();
        let count = RefCell::new(0);

        let key = link.register(|count: &RefCell<usize>, _: Sbp| {
            *count.borrow_mut() += 1;
        });

        let msg = Sbp::from(make_msg_obs());
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
            fn from_sbp(msg: Sbp) -> Self {
                match msg {
                    Sbp::MsgObs(m) => ObsMsg::Obs(m),
                    Sbp::MsgObsDepA(m) => ObsMsg::DepA(m),
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

        source.send_with_state(&count, Sbp::from(make_msg_obs()));
        assert_eq!(*count.borrow(), 1);

        source.send_with_state(&count, Sbp::from(make_msg_obs_dep_a()));
        assert_eq!(*count.borrow(), 2);
    }

    fn make_msg_obs() -> MsgObs {
        MsgObs {
            sender_id: Some(1),
            header: ObservationHeader {
                t: messages::gnss::GpsTime {
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
                t: messages::gnss::GpsTimeDep { tow: 1, wn: 1 },
                n_obs: 1,
            },
            obs: vec![],
        }
    }
}
