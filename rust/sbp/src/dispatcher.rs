use std::{any::Any, borrow::Borrow, collections::HashMap, convert::TryInto, marker::PhantomData};

use slotmap::SlotMap;

use crate::messages::{RealMessage, SBPMessage, SBP};

#[derive(Default)]
pub struct Dispatcher {
    handlers: SlotMap<HandlerKeyInner, Box<dyn StoredHandler>>,
    msg_map: HashMap<u16, Vec<HandlerKeyInner>>,
}

impl Dispatcher {
    pub fn new() -> Dispatcher {
        Default::default()
    }

    pub fn run<M>(&mut self, msg: M) -> bool
    where
        M: Borrow<SBP>,
    {
        let msg = msg.borrow();
        let msg_type = msg.get_message_type();

        let keys = match self.msg_map.get(&msg_type) {
            Some(keys) if keys.len() > 0 => keys,
            _ => return false,
        };

        for key in keys {
            self.handlers[*key].run(msg.clone());
        }

        true
    }

    pub fn add_handler<T, H, E, const N: usize>(&mut self, h: T) -> HandlerKey<H, E>
    where
        T: IntoHandler<SBP, H>,
        H: Handler<Event = E> + Any,
        E: Event<N> + FromSbp,
    {
        let key = self.handlers.insert(Box::new(h.handler()));
        for msg_type in E::MESSAGE_TYPES {
            self.msg_map.entry(msg_type).or_default().push(key);
        }
        HandlerKey {
            key,
            marker: PhantomData,
        }
    }

    pub fn remove_handler<H, E, const N: usize>(&mut self, key: HandlerKey<H, E>)
    where
        H: Handler<Event = E>,
        E: Event<N> + FromSbp,
    {
        self.remove_boxed(key);
    }

    pub fn take_handler<H, E, const N: usize>(&mut self, key: HandlerKey<H, E>) -> H
    where
        H: Handler<Event = E> + Any,
        E: Event<N> + FromSbp,
    {
        *self
            .remove_boxed(key)
            .into_any()
            .downcast::<H>()
            .expect("failed to downcast handler")
    }

    fn remove_boxed<H, E, const N: usize>(
        &mut self,
        key: HandlerKey<H, E>,
    ) -> Box<dyn StoredHandler>
    where
        H: Handler<Event = E>,
        E: Event<N>,
    {
        for msg_type in &E::MESSAGE_TYPES {
            if let Some(keys) = self.msg_map.get_mut(msg_type) {
                keys.iter_mut()
                    .position(|k| k == &key.key)
                    .map(|i| keys.swap_remove(i))
                    .expect("handler already removed");
            }
        }
        self.handlers.remove(key.key).expect("handler not found")
    }
}

pub struct HandlerKey<H, E> {
    key: HandlerKeyInner,
    marker: PhantomData<(H, E)>,
}

slotmap::new_key_type! {
    struct HandlerKeyInner;
}

trait StoredHandler {
    fn run(&mut self, msg: SBP);

    fn into_any(self: Box<Self>) -> Box<dyn Any>;
}

impl<H> StoredHandler for H
where
    H: Handler + 'static,
    H::Event: FromSbp,
{
    fn run(&mut self, msg: SBP) {
        self.run(msg);
    }

    fn into_any(self: Box<Self>) -> Box<dyn Any> {
        self
    }
}

pub trait Handler {
    type Event;

    fn recv(&mut self, event: Self::Event);

    fn run(&mut self, msg: SBP)
    where
        Self::Event: FromSbp,
    {
        let event = Self::Event::from_sbp(msg);
        self.recv(event);
    }
}

pub trait FromSbp {
    fn from_sbp(msg: SBP) -> Self;
}

impl<T> FromSbp for T
where
    T: RealMessage,
{
    fn from_sbp(msg: SBP) -> Self {
        msg.try_into().unwrap()
    }
}

pub trait Event<const N: usize> {
    const MESSAGE_TYPES: [u16; N];
}

impl<T> Event<1> for T
where
    T: RealMessage,
{
    const MESSAGE_TYPES: [u16; 1] = [T::MESSAGE_TYPE];
}

pub trait IntoHandler<M, H>
where
    H: Handler,
{
    fn handler(self) -> H;
}

impl<H> IntoHandler<SBP, H> for H
where
    H: Handler,
{
    fn handler(self) -> H {
        self
    }
}

struct FuncHandler<E, O, F, const N: usize> {
    func: F,
    func_marker: PhantomData<fn(E) -> O>,
    msg_types_marker: PhantomData<[u16; N]>,
}

impl<E, O, F, const N: usize> Handler for FuncHandler<E, O, F, N>
where
    E: Event<N>,
    F: FnMut(E) -> O,
{
    type Event = E;

    fn recv(&mut self, event: Self::Event) {
        (self.func)(event);
    }
}

impl<E, O, F, const N: usize> IntoHandler<SBP, FuncHandler<E, O, F, N>> for F
where
    E: Event<N>,
    F: FnMut(E) -> O,
{
    fn handler(self) -> FuncHandler<E, O, F, N> {
        FuncHandler {
            func: self,
            func_marker: PhantomData,
            msg_types_marker: PhantomData,
        }
    }
}

#[cfg(test)]
mod tests {
    use std::sync::mpsc::{self, Receiver, Sender};

    use crate::messages::{
        self,
        observation::{MsgObs, MsgObsDepA, ObservationHeader, ObservationHeaderDep},
    };

    use super::*;

    #[test]
    fn test_dispatcher() {
        let mut d = Dispatcher::new();

        let (tx, rx) = test_channel();
        d.add_handler(move |_: MsgObs| tx.send(true));

        assert!(d.run(make_msg_obs()));
        assert!(rx.recv().unwrap());

        assert!(!d.run(make_msg_obs_dep_a()));
        assert!(rx.try_recv().is_err());
    }

    #[test]
    fn test_fn_pointer_dispatcher() {
        let mut d = Dispatcher::new();

        static mut COUNTER: usize = 0;
        fn dont_do_this(_: MsgObs) {
            unsafe { COUNTER += 1 }
        }

        d.add_handler(dont_do_this);
        d.run(make_msg_obs());
        d.run(make_msg_obs_dep_a());

        assert_eq!(unsafe { COUNTER }, 1);
    }

    #[test]
    fn test_custom_event() {
        let mut d = Dispatcher::new();

        let (tx_custom, rx_custom) = test_channel();
        d.add_handler(move |_: ObsMsg| tx_custom.send(true));

        let (tx_obs, rx_obs) = test_channel();
        d.add_handler(move |_: MsgObs| tx_obs.send(true));

        d.run(make_msg_obs());
        d.run(make_msg_obs_dep_a());

        assert!(rx_custom.recv().unwrap());
        assert!(rx_custom.recv().unwrap());
        assert!(rx_obs.recv().unwrap());
        assert!(rx_obs.try_recv().is_err());
    }

    #[test]
    fn test_struct_handler() {
        struct Counter(usize);

        impl Handler for Counter {
            type Event = MsgObs;

            fn recv(&mut self, _: Self::Event) {
                self.0 += 1;
            }
        }

        let mut d = Dispatcher::new();
        let key = d.add_handler(Counter(0));

        d.run(make_msg_obs());
        d.run(make_msg_obs_dep_a());

        let counter = d.take_handler(key);

        assert_eq!(counter.0, 1);
        assert!(!d.run(make_msg_obs()));

        let key = d.add_handler(counter);

        d.run(make_msg_obs());

        let counter = d.take_handler(key);

        assert_eq!(counter.0, 2);
    }

    enum ObsMsg {
        Obs(MsgObs),
        DepA(MsgObsDepA),
    }

    impl Event<2> for ObsMsg {
        const MESSAGE_TYPES: [u16; 2] = [MsgObs::MESSAGE_TYPE, MsgObsDepA::MESSAGE_TYPE];
    }

    impl FromSbp for ObsMsg {
        fn from_sbp(msg: SBP) -> Self {
            match msg {
                SBP::MsgObs(m) => ObsMsg::Obs(m),
                SBP::MsgObsDepA(m) => ObsMsg::DepA(m),
                _ => unreachable!("wrong event keys"),
            }
        }
    }

    fn make_msg_obs() -> SBP {
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
        .into()
    }

    fn make_msg_obs_dep_a() -> SBP {
        MsgObsDepA {
            sender_id: Some(1),
            header: ObservationHeaderDep {
                t: messages::gnss::GPSTimeDep { tow: 1, wn: 1 },
                n_obs: 1,
            },
            obs: vec![],
        }
        .into()
    }

    fn test_channel() -> (Sender<bool>, Receiver<bool>) {
        mpsc::channel::<bool>()
    }
}
