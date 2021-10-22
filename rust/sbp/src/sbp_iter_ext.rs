//! Extra adaptors for iterators of [Sbp] messages.

use crate::{DeserializeError, Sbp};

/// An [Iterator] blanket implementation that provides extra adaptors for iterators of [Sbp] messages.
pub trait SbpIterExt: Iterator {
    /// Lift an `Iterator<Item = Result<Sbp>>` into an `Iterator<Item = Sbp>` by ignoring all the errors.
    /// The iterator will terminate if an io error is encountered.
    fn ignore_errors<'a>(self) -> HandleErrorsIter<'a, Self, DeserializeError>
    where
        Self: Iterator<Item = Result<Sbp, DeserializeError>> + Sized,
    {
        HandleErrorsIter::new(self, |e| match e {
            DeserializeError::IoError(_) => ControlFlow::Break,
            _ => ControlFlow::Continue,
        })
    }

    /// Lift an `Iterator<Item = Result<Sbp>>` into an `Iterator<Item = Sbp>` by logging all the errors.
    /// The iterator will terminate if an io error is encountered.
    fn log_errors<'a>(self, level: log::Level) -> HandleErrorsIter<'a, Self, DeserializeError>
    where
        Self: Iterator<Item = Result<Sbp, DeserializeError>> + Sized,
    {
        HandleErrorsIter::new(self, move |e| {
            log::log!(level, "{}", e);
            match e {
                DeserializeError::IoError(_) => ControlFlow::Break,
                _ => ControlFlow::Continue,
            }
        })
    }

    /// Lift an `Iterator<Item = Result<Sbp>>` into an `Iterator<Item = Sbp>` with a custom error handler.
    /// You can use (ControlFlow)[self::ControlFlow] to determine if the iterator should continue or break on error.
    fn handle_errors<'a, E, F>(self, on_err: F) -> HandleErrorsIter<'a, Self, E>
    where
        Self: Iterator<Item = Result<Sbp, E>> + Sized,
        F: FnMut(&E) -> ControlFlow + 'a,
    {
        HandleErrorsIter::new(self, on_err)
    }

    /// Return an iterable that also includes [GpsTime]s. This method calls [SbpMessage::gps_time] on each message.
    /// If the message has a complete GpsTime it is returned. If the message only has a TOW, this itertor will use the
    /// last week number it has seen, or return `None` if it hasn't seen any.
    #[cfg(feature = "swiftnav")]
    fn with_rover_time<T>(self) -> swiftnav_impl::RoverTimeIter<Self>
    where
        T: swiftnav_impl::HasTime,
        Self: Iterator<Item = T> + Sized,
    {
        swiftnav_impl::RoverTimeIter::new(self)
    }
}

impl<I> SbpIterExt for I where I: Iterator + Sized {}

// A less general https://doc.rust-lang.org/std/ops/enum.ControlFlow.html
// could be replaced by that once it's stable
/// Used to tell [HandleErrorsIter] whether it should exit early or go on as usual.
pub enum ControlFlow {
    Continue,
    Break,
}

/// See [SbpIterExt::handle_errors] for more information.
pub struct HandleErrorsIter<'a, I, E>
where
    I: Iterator,
{
    messages: I,
    on_err: Box<dyn FnMut(&E) -> ControlFlow + 'a>,
    err: Result<(), E>,
}

impl<'a, I, E> HandleErrorsIter<'a, I, E>
where
    I: Iterator<Item = Result<Sbp, E>>,
{
    fn new<F>(messages: I, on_err: F) -> HandleErrorsIter<'a, I, E>
    where
        F: FnMut(&E) -> ControlFlow + 'a,
    {
        Self {
            messages,
            on_err: Box::new(on_err),
            err: Ok(()),
        }
    }

    pub fn take_err(&mut self) -> Result<(), E> {
        std::mem::replace(&mut self.err, Ok(()))
    }
}

impl<'a, I, E> Iterator for HandleErrorsIter<'a, I, E>
where
    I: Iterator<Item = Result<Sbp, E>>,
{
    type Item = Sbp;

    fn next(&mut self) -> Option<Self::Item> {
        match self.messages.next()? {
            Ok(msg) => Some(msg),
            Err(e) => {
                let flow = (self.on_err)(&e);
                self.err = Err(e);
                match flow {
                    ControlFlow::Continue => self.next(),
                    ControlFlow::Break => None,
                }
            }
        }
    }
}

#[cfg(feature = "swiftnav")]
mod swiftnav_impl {
    use swiftnav::time::GpsTime;

    use crate::{
        messages::SbpMessage,
        time::{GpsTimeError, MessageTime, RoverTime},
        Sbp,
    };

    /// See [SbpIterExt::with_rover_time] for more information.
    pub struct RoverTimeIter<I: Iterator> {
        messages: I,
        clock: Option<GpsTime>,
    }

    impl<I> RoverTimeIter<I>
    where
        I: Iterator,
    {
        pub fn new(messages: I) -> RoverTimeIter<I> {
            Self {
                messages,
                clock: None,
            }
        }

        fn update(&mut self, time: MessageTime) -> Option<GpsTime> {
            match time {
                MessageTime::Rover(time) => match time {
                    RoverTime::GpsTime(time) => {
                        self.clock = Some(time);
                        Some(time)
                    }
                    RoverTime::Tow(tow) => {
                        if let Some(clock) = self.clock {
                            // tow came from a `GpsTime` so it must be valid
                            let time = GpsTime::new(clock.wn(), tow).unwrap();
                            self.clock = Some(time);
                            Some(time)
                        } else {
                            // no previous time to use wn from
                            None
                        }
                    }
                },
                _ => None,
            }
        }
    }

    impl<I> Iterator for RoverTimeIter<I>
    where
        I: Iterator,
        I::Item: HasTime,
    {
        type Item = (I::Item, Option<Result<GpsTime, GpsTimeError>>);

        fn next(&mut self) -> Option<Self::Item> {
            let msg = self.messages.next()?;
            match msg.time() {
                Some(Ok(time)) => match self.update(time) {
                    Some(gps_time) => Some((msg, Some(Ok(gps_time)))),
                    None => Some((msg, None)),
                },
                Some(Err(e)) => Some((msg, Some(Err(e)))),
                None => Some((msg, None)),
            }
        }
    }

    pub trait HasTime {
        fn time(&self) -> Option<Result<MessageTime, GpsTimeError>>;
    }

    impl HasTime for Sbp {
        fn time(&self) -> Option<Result<MessageTime, GpsTimeError>> {
            self.gps_time()
        }
    }

    impl<E> HasTime for Result<Sbp, E> {
        fn time(&self) -> Option<Result<MessageTime, GpsTimeError>> {
            match self {
                Ok(m) => m.gps_time(),
                Err(_) => None,
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use std::io::Cursor;

    use crate::iter_messages;

    use super::*;

    #[test]
    fn test_rover_time_wn() {
        #[rustfmt::skip]
        let data = Cursor::new(vec![
            // MsgGPSTimeDepA TOW: 2567800 WN: 1787
            85, 0, 1, 246, 215, 11, 251, 6, 120, 46, 39, 0, 0, 0, 0, 0, 0, 133, 36,
            // MsgHeartbeat
            85, 255, 255, 246, 215, 4, 0, 50, 0, 0, 249, 216,
            // MsgPosECEFDepA TOW: 2567900
            85, 0, 2, 246, 215, 32, 220, 46, 39, 0, 216, 41, 227, 254, 33, 154, 68, 193, 9, 151,
            154, 124, 231, 95, 80, 193, 1, 183, 214, 139, 255, 105, 77, 65, 0, 0, 9, 0, 7, 98,
            // MsgGPSTimeDepA TOW: 2568000 WN: 1787
            85, 0, 1, 246, 215, 11, 251, 6, 64, 47, 39, 0, 0, 0, 0, 0, 0, 171, 190,
        ]);

        let mut with_time = iter_messages(data).ignore_errors().with_rover_time();

        let gps_time = with_time.next().map(|(_, t)| t).flatten().unwrap().unwrap();
        assert_eq!(gps_time.wn(), 1787);
        assert!((gps_time.tow() - 2567.8).abs() < f64::EPSILON);

        assert!(with_time.next().map(|(_, t)| t).flatten().is_none());

        let gps_time = with_time.next().map(|(_, t)| t).flatten().unwrap().unwrap();
        assert_eq!(gps_time.wn(), 1787);
        assert!((gps_time.tow() - 2567.9).abs() < f64::EPSILON);

        let gps_time = with_time.next().map(|(_, t)| t).flatten().unwrap().unwrap();
        assert_eq!(gps_time.wn(), 1787);
        assert!((gps_time.tow() - 2568.).abs() < f64::EPSILON);
    }

    #[test]
    fn test_rover_time_result() {
        let data = Cursor::new(vec![
            // MsgGPSTimeDepA TOW: 2567800 WN: 1787
            85, 0, 1, 246, 215, 11, 251, 6, 120, 46, 39, 0, 0, 0, 0, 0, 0, 133, 36,
        ]);

        let mut with_time = iter_messages(data).with_rover_time();

        let msg = with_time.next().unwrap();
        assert!(msg.0.is_ok());

        let gps_time = msg.1.unwrap().unwrap();
        assert_eq!(gps_time.wn(), 1787);
        assert!((gps_time.tow() - 2567.8).abs() < f64::EPSILON);
    }

    #[test]
    fn test_handle_errors() {
        #[rustfmt::skip]
        let data = Cursor::new(vec![
            85, 0, 1, 246, 215, 11, 251, 6, 120, 46, 39, 0, 0, 0, 0, 0, 0, 133, 36,
            85, 0, 1, 246, 215, 11, 251, 6, 220, 46, 39, 0, 0, 0, 0, 0, 0, 36, 159, // crc error
            85, 0, 1, 246, 215, 11, 251, 6, 220, 46, 39, 0, 0, 0, 0, 0, 0, 36, 160,
        ]);

        let mut errors: usize = 0;
        let messages = iter_messages(data.clone())
            .handle_errors(|_| {
                errors += 1;
                ControlFlow::Continue
            })
            .count();
        assert_eq!(messages, 2);
        assert_eq!(errors, 1);

        let messages = iter_messages(data).ignore_errors().count();
        assert_eq!(messages, 2);
    }

    #[test]
    fn test_stop_on_errors() {
        #[rustfmt::skip]
        let data = Cursor::new(vec![
            85, 0, 1, 246, 215, 11, 251, 6, 120, 46, 39, 0, 0, 0, 0, 0, 0, 133, 36,
            85, 0, 1, 246, 215, 11, 251, 6, 120, 46, 39, 0, 0, 0, 0, 0, 0, 133, 36,
            85, 0, 1, 246, 215, 11, 251, 6, 220, 46, 39, 0, 0, 0, 0, 0, 0, 36, 159, // wrong
            85, 0, 1, 246, 215, 11, 251, 6, 220, 46, 39, 0, 0, 0, 0, 0, 0, 36, 160,
        ]);

        let mut err_count: usize = 0;
        let mut msg_count: usize = 0;

        let mut messages = iter_messages(data).handle_errors(|_| {
            err_count += 1;
            ControlFlow::Break
        });

        for _ in &mut messages {
            msg_count += 1;
        }
        assert!(matches!(
            messages.take_err(),
            Err(DeserializeError::CrcError { .. })
        ));
        assert_eq!(msg_count, 2);

        for _ in &mut messages {
            msg_count += 1;
        }
        assert!(messages.take_err().is_ok());
        assert_eq!(msg_count, 3);

        assert_eq!(messages.count(), 0);
        assert_eq!(err_count, 1);
    }
}
