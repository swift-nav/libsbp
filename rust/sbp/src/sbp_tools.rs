#[cfg(feature = "swiftnav-rs")]
use swiftnav_rs::time::GpsTime;

#[cfg(feature = "swiftnav-rs")]
use crate::{
    messages::SBPMessage,
    time::{GpsTimeError, MessageTime, RoverTime},
};

use crate::messages::SBP;

pub trait SBPTools: Iterator {
    fn ignore_errors(self) -> HandleErrorsIter<Self, fn(&crate::Error) -> ControlFlow>
    where
        Self: Iterator<Item = crate::Result<SBP>> + Sized,
    {
        HandleErrorsIter::new(self, |_| ControlFlow::Continue)
    }

    fn log_errors(
        self,
        level: log::Level,
    ) -> HandleErrorsIter<Self, Box<dyn Fn(&crate::Error) -> ControlFlow>>
    where
        Self: Iterator<Item = crate::Result<SBP>> + Sized,
    {
        HandleErrorsIter::new(
            self,
            Box::new(move |e| {
                log::log!(level, "{}", e);
                ControlFlow::Continue
            }),
        )
    }

    fn handle_errors<F>(self, on_err: F) -> HandleErrorsIter<Self, F>
    where
        Self: Iterator<Item = crate::Result<SBP>> + Sized,
        F: FnMut(&crate::Error) -> ControlFlow,
    {
        HandleErrorsIter::new(self, on_err)
    }

    #[cfg(feature = "swiftnav-rs")]
    fn with_rover_time(self) -> RoverTimeIter<Self>
    where
        Self: Sized,
    {
        RoverTimeIter::new(self)
    }
}

impl<I> SBPTools for I where I: Iterator + Sized {}

// A less general https://doc.rust-lang.org/std/ops/enum.ControlFlow.html
// could be replaced by that once it's stable
pub enum ControlFlow {
    Continue,
    Break,
}

pub struct HandleErrorsIter<I, F>
where
    I: Iterator,
{
    messages: I,
    on_err: F,
    err: crate::Result<()>,
}

impl<I, F> HandleErrorsIter<I, F>
where
    I: Iterator<Item = crate::Result<SBP>>,
{
    fn new(messages: I, on_err: F) -> HandleErrorsIter<I, F> {
        Self {
            messages,
            on_err,
            err: Ok(()),
        }
    }

    pub fn check_error(&mut self) -> crate::Result<()> {
        std::mem::replace(&mut self.err, Ok(()))
    }
}

impl<I, F> Iterator for HandleErrorsIter<I, F>
where
    I: Iterator<Item = crate::Result<SBP>>,
    F: FnMut(&crate::Error) -> ControlFlow,
{
    type Item = SBP;

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

#[cfg(feature = "swiftnav-rs")]
pub struct RoverTimeIter<I: Iterator> {
    messages: I,
    clock: Option<GpsTime>,
}

#[cfg(feature = "swiftnav-rs")]
impl<I> RoverTimeIter<I>
where
    I: Iterator,
{
    fn new(messages: I) -> RoverTimeIter<I> {
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

#[cfg(feature = "swiftnav-rs")]
impl<I> Iterator for RoverTimeIter<I>
where
    I: Iterator<Item = SBP>,
{
    type Item = (SBP, Option<Result<GpsTime, GpsTimeError>>);

    fn next(&mut self) -> Option<Self::Item> {
        let msg = self.messages.next()?;

        match msg.gps_time() {
            Some(Ok(time)) => match self.update(time) {
                Some(gps_time) => Some((msg, Some(Ok(gps_time)))),
                None => Some((msg, None)),
            },
            Some(Err(e)) => Some((msg, Some(Err(e)))),
            None => Some((msg, None)),
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
        assert_eq!(gps_time.tow(), 2567.8);

        assert!(with_time.next().map(|(_, t)| t).flatten().is_none());

        let gps_time = with_time.next().map(|(_, t)| t).flatten().unwrap().unwrap();
        assert_eq!(gps_time.wn(), 1787);
        assert_eq!(gps_time.tow(), 2567.9);

        let gps_time = with_time.next().map(|(_, t)| t).flatten().unwrap().unwrap();
        assert_eq!(gps_time.wn(), 1787);
        assert_eq!(gps_time.tow(), 2568.);
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

        while let Some(_) = messages.next() {
            msg_count += 1;
        }
        assert!(matches!(
            messages.check_error(),
            Err(crate::Error::CrcError { .. })
        ));
        assert_eq!(msg_count, 2);

        while let Some(_) = messages.next() {
            msg_count += 1;
        }
        assert!(messages.check_error().is_ok());
        assert_eq!(msg_count, 3);

        assert_eq!(messages.count(), 0);
        assert_eq!(err_count, 1);
    }
}
