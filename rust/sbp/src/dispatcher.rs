use std::{borrow::Borrow, collections::HashMap, convert::TryInto, marker::PhantomData};

use slotmap::SlotMap;

use crate::messages::{RealMessage, SBPMessage, SBP};

#[derive(Default)]
pub struct Dispatcher<'a> {
    handlers: SlotMap<HandlerKeyInner, Handler<'a>>,
    msg_map: HashMap<u16, Vec<HandlerKeyInner>>,
}

impl<'a> Dispatcher<'a> {
    pub fn new() -> Dispatcher<'a> {
        Default::default()
    }

    pub fn run<B>(&mut self, msg: B) -> bool
    where
        B: Borrow<SBP>,
    {
        let msg = msg.borrow();
        let msg_type = msg.get_message_type();

        let keys = match self.msg_map.get(&msg_type) {
            Some(keys) if keys.len() > 0 => keys,
            _ => return false,
        };

        for key in keys {
            (self.handlers[*key])(msg.clone());
        }

        true
    }

    pub fn add<F, E, O>(&mut self, mut func: F) -> HandlerKey<E>
    where
        F: FnMut(E) -> O + Send + 'a,
        E: Event,
    {
        let key = self.handlers.insert(Box::new(move |msg: SBP| {
            let event = E::from_sbp(msg);
            func(event);
        }));
        for msg_type in E::MESSAGE_TYPES {
            self.msg_map.entry(*msg_type).or_default().push(key);
        }
        HandlerKey {
            key,
            marker: PhantomData,
        }
    }

    pub fn remove<E>(&mut self, key: HandlerKey<E>)
    where
        E: Event,
    {
        for msg_type in E::MESSAGE_TYPES {
            if let Some(keys) = self.msg_map.get_mut(msg_type) {
                keys.iter_mut()
                    .position(|k| k == &key.key)
                    .map(|i| keys.swap_remove(i));
            }
        }
        self.handlers.remove(key.key);
    }
}

pub type Handler<'a> = Box<dyn FnMut(SBP) + Send + 'a>;

pub struct HandlerKey<E> {
    key: HandlerKeyInner,
    marker: PhantomData<E>,
}

slotmap::new_key_type! {
    struct HandlerKeyInner;
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
        d.add(move |_: MsgObs| tx.send(true));

        assert!(d.run(make_msg_obs()));
        assert!(rx.recv().unwrap());

        assert!(!d.run(make_msg_obs_dep_a()));
        assert!(rx.try_recv().is_err());
    }

    #[test]
    fn test_dispatcher_capture() {
        let mut d = Dispatcher::new();

        let mut counter = 0;
        d.add(|_: MsgObs| counter += 1);

        assert!(d.run(make_msg_obs()));
        assert!(!d.run(make_msg_obs_dep_a()));

        drop(d);
        assert_eq!(counter, 1);
    }

    #[test]
    fn test_fn_pointer_dispatcher() {
        let mut d = Dispatcher::new();

        static mut COUNTER: usize = 0;
        fn dont_do_this(_: MsgObs) {
            unsafe { COUNTER += 1 }
        }

        d.add(dont_do_this);
        d.run(make_msg_obs());
        d.run(make_msg_obs_dep_a());

        assert_eq!(unsafe { COUNTER }, 1);
    }

    #[test]
    fn test_custom_event() {
        let mut d = Dispatcher::new();

        let (tx_custom, rx_custom) = test_channel();
        d.add(move |_: ObsMsg| tx_custom.send(true));

        let (tx_obs, rx_obs) = test_channel();
        d.add(move |_: MsgObs| tx_obs.send(true));

        d.run(make_msg_obs());
        d.run(make_msg_obs_dep_a());

        assert!(rx_custom.recv().unwrap());
        assert!(rx_custom.recv().unwrap());
        assert!(rx_obs.recv().unwrap());
        assert!(rx_obs.try_recv().is_err());
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
