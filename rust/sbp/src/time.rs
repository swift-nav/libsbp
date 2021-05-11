pub use swiftnav_rs::time::GpsTime;

pub use crate::swiftnav_rs_conversions::GpsTimeError;

#[derive(Debug, Clone, Copy)]
pub enum MessageTime {
    Rover(RoverTime),
    Base(BaseTime),
}

impl MessageTime {
    pub fn to_rover(self) -> Option<RoverTime> {
        if let Self::Rover(v) = self {
            Some(v)
        } else {
            None
        }
    }

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

#[derive(Debug, Clone, Copy)]
pub enum RoverTime {
    GpsTime(GpsTime),
    Tow(f64),
}

impl RoverTime {
    pub fn tow(&self) -> f64 {
        match self {
            RoverTime::GpsTime(time) => time.tow(),
            RoverTime::Tow(tow) => *tow,
        }
    }

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

#[derive(Debug, Clone, Copy, PartialEq, PartialOrd)]
pub struct BaseTime(GpsTime);

impl From<GpsTime> for BaseTime {
    fn from(gps_time: GpsTime) -> Self {
        BaseTime(gps_time)
    }
}
