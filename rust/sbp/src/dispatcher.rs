use std::{any::{self, Any}, borrow::Borrow, collections::HashMap, convert::TryInto, marker::PhantomData};

use any::TypeId;
use slotmap::SlotMap;

use crate::messages::{RealMessage, SBPMessage, SBP};

#[derive(Default)]
pub struct Dispatcher {
    handlers: SlotMap<HandlerKeyInner, Box<dyn SbpHandler>>,
    msg_map: HashMap<u16, Vec<HandlerKeyInner>>,
}

impl Dispatcher {
    pub fn new() -> Dispatcher {
        Default::default()
    }

    pub fn run(&mut self, msg: impl Borrow<SBP>) -> bool {
        let msg = msg.borrow();
        let msg_type = msg.get_message_type();

        let keys = match self.msg_map.get(&msg_type) {
            Some(keys) if keys.len() > 0 => keys,
            _ => return false,
        };

        for key in keys {
            self.handlers[*key].recv(msg.clone());
        }

        true
    }

    pub fn add_handler<T, H, E>(&mut self, h: T) -> HandlerKey<H>
    where
        T: IntoHandler<SBP, H, E>,
        H: Handler<Event = E>,
        E: Event + Any,
    {
        let key = self.handlers.insert(Box::new(h.handler()));
        let id = TypeId::of::<E>();
        for msg_type in E::MESSAGE_TYPES {
            self.msg_map.entry(*msg_type).or_default().push(key);
        }
        HandlerKey {
            key,
            marker: PhantomData,
        }
    }

    pub fn remove_handler<H, E>(&mut self, key: HandlerKey<H>)
    where
        H: Handler<Event = E>,
        E: Event,
    {
        self.remove_boxed(key);
    }

    pub fn take_handler<H, E>(&mut self, key: HandlerKey<H>) -> H
    where
        H: Handler<Event = E>,
        E: Event,
    {
        *self
            .remove_boxed(key)
            .into_any()
            .downcast::<H>()
            .expect("failed to downcast handler")
    }

    fn remove_boxed<H, E>(&mut self, key: HandlerKey<H>) -> Box<dyn SbpHandler>
    where
        H: Handler<Event = E>,
        E: Event,
    {
        for msg_type in E::MESSAGE_TYPES {
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

pub struct HandlerKey<H> {
    key: HandlerKeyInner,
    marker: PhantomData<H>,
}

slotmap::new_key_type! {
    struct HandlerKeyInner;
}

pub trait EventHandler<E>
where
    E: Event,
{
    fn recv(&mut self, event: E);
}

pub trait Handler: 'static {
    type Event: Event;

    fn recv(&mut self, event: Self::Event);
}

/// A handler without the associated type, replaced by the concrete type SBP
trait SbpHandler {
    fn recv(&mut self, msg: SBP);

    fn into_any(self: Box<Self>) -> Box<dyn Any>;
}

impl<H> SbpHandler for H
where
    H: Handler,
{
    fn recv(&mut self, msg: SBP) {
        let event = H::Event::from_sbp(msg);
        self.recv(event);
    }

    fn into_any(self: Box<Self>) -> Box<dyn Any> {
        self
    }
}

pub trait Event {
    /// The message types from which the event can be derived.
    const MESSAGE_TYPES: &'static [u16];

    /// Conversion from SBP. The message type of `msg` is guaranteed to be in
    /// `Self::MESSAGE_TYPES`.
    fn from_sbp(msg: SBP) -> Self;
}

// All concrete message types can be used as events.
impl<T> Event for T
where
    T: RealMessage,
{
    const MESSAGE_TYPES: &'static [u16] = &[T::MESSAGE_TYPE];

    fn from_sbp(msg: SBP) -> Self {
        msg.try_into().unwrap()
    }
}

/// Something that can be used as an event handler.
pub trait IntoHandler<M, H, E>
where
    H: Handler<Event = E>,
    E: Event,
{
    fn handler(self) -> H;
}

// All handlers can be used as handlers.
impl<H, E> IntoHandler<SBP, H, E> for H
where
    H: Handler<Event = E>,
    E: Event,
{
    fn handler(self) -> H {
        self
    }
}

/// A handler from a closure or function pointer.
struct FuncHandler<F, E, O> {
    func: F,
    marker: PhantomData<fn(E) -> O>,
}

impl<F, E, O> Handler for FuncHandler<F, E, O>
where
    F: FnMut(E) -> O + 'static,
    E: Event + 'static,
    O: 'static,
{
    type Event = E;

    fn recv(&mut self, event: E) {
        (self.func)(event);
    }
}

impl<F, E, O> IntoHandler<SBP, FuncHandler<F, E, O>, E> for F
where
    F: FnMut(E) -> O + 'static,
    E: Event + 'static,
    O: 'static,
{
    fn handler(self) -> FuncHandler<F, E, O> {
        FuncHandler {
            func: self,
            marker: PhantomData,
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

        impl Counter {
            fn on_msg_obs(&mut self, msg: MsgObs) {
                self.0 += 1;
            }
            fn on_msg_obs_dep_a(&mut self, msg: MsgObsDepA) {
                self.0 += 1;
            }
        }

        impl Handler for Counter {
            type Event = MsgObs;

            fn recv(&mut self, _: MsgObs) {
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
