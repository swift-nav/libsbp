//! Types representing GPS times embedded in messsages.

pub use swiftnav::time::GpsTime;

pub use crate::swiftnav_conversions::GpsTimeError;

/// The time returned by [SbpMessage::gps_time](crate::SbpMessage::gps_time).
#[derive(Debug, Clone, Copy)]
pub enum MessageTime {
    /// Time received via a message from a rover.
    Rover(RoverTime),

    /// Time received via a message from a base station.
    Base(BaseTime),
}

impl MessageTime {
    /// If the `MessageTime` is from a rover return it. Otherwise return None.
    pub fn to_rover(self) -> Option<RoverTime> {
        if let Self::Rover(v) = self {
            Some(v)
        } else {
            None
        }
    }

    /// If the `MessageTime` is from a base station return it. Otherwise return None.
    pub fn to_base(self) -> Option<BaseTime> {
        if let Self::Base(v) = self {
            Some(v)
        } else {
            None
        }
    }
}

impl From<RoverTime> for MessageTime {
    fn from(rt: RoverTime) -> Self {
        MessageTime::Rover(rt)
    }
}

impl From<BaseTime> for MessageTime {
    fn from(bt: BaseTime) -> Self {
        MessageTime::Base(bt)
    }
}

/// Time received via a message from a rover, like
/// [MsgAngularRate](crate::messages::orientation::MsgAngularRate)
#[derive(Debug, Clone, Copy)]
pub enum RoverTime {
    /// The [GpsTime] of the message.
    GpsTime(GpsTime),
    /// The message had no week number.
    Tow(f64),
}

impl RoverTime {
    /// Get the time of week.
    pub fn tow(&self) -> f64 {
        match self {
            RoverTime::GpsTime(time) => time.tow(),
            RoverTime::Tow(tow) => *tow,
        }
    }

    /// Get the week number if the message included it. Otherwise return None.
    pub fn wn(&self) -> Option<i16> {
        match self {
            RoverTime::GpsTime(time) => Some(time.wn()),
            RoverTime::Tow(_) => None,
        }
    }
}

impl From<GpsTime> for RoverTime {
    fn from(gps_time: GpsTime) -> Self {
        RoverTime::GpsTime(gps_time)
    }
}

impl From<f64> for RoverTime {
    fn from(tow: f64) -> Self {
        RoverTime::Tow(tow)
    }
}

/// Time received via a message from a base station, like
/// [MsgObs](crate::messages::observation::MsgObs).
#[derive(Debug, Clone, Copy, PartialEq, PartialOrd)]
pub struct BaseTime(GpsTime);

impl From<GpsTime> for BaseTime {
    fn from(gps_time: GpsTime) -> Self {
        BaseTime(gps_time)
    }
}
