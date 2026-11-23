//! Conversions from messages to types in `swiftnav`.

use std::{
    convert::{TryFrom, TryInto},
    fmt, num,
};

use crate::messages;

#[derive(Debug, Clone)]
pub enum GpsTimeError {
    InvalidGpsTime(swiftnav::time::InvalidGpsTime),
    TryFromIntError(num::TryFromIntError),
}

impl fmt::Display for GpsTimeError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            GpsTimeError::InvalidGpsTime(e) => e.fmt(f),
            GpsTimeError::TryFromIntError(e) => e.fmt(f),
        }
    }
}

impl std::error::Error for GpsTimeError {}

impl From<swiftnav::time::InvalidGpsTime> for GpsTimeError {
    fn from(e: swiftnav::time::InvalidGpsTime) -> Self {
        GpsTimeError::InvalidGpsTime(e)
    }
}

impl From<num::TryFromIntError> for GpsTimeError {
    fn from(e: num::TryFromIntError) -> Self {
        GpsTimeError::TryFromIntError(e)
    }
}

impl From<std::convert::Infallible> for GpsTimeError {
    fn from(_: std::convert::Infallible) -> Self {
        unreachable!()
    }
}

impl TryFrom<messages::gnss::GpsTime> for swiftnav::time::GpsTime {
    type Error = swiftnav::time::InvalidGpsTime;

    fn try_from(
        msg: messages::gnss::GpsTime,
    ) -> Result<swiftnav::time::GpsTime, swiftnav::time::InvalidGpsTime> {
        let tow = (msg.tow as f64) * 1e-3 + (msg.ns_residual as f64) * 1e-9;
        swiftnav::time::GpsTime::new(msg.wn as i16, tow)
    }
}

impl TryFrom<messages::gnss::GpsTimeSec> for swiftnav::time::GpsTime {
    type Error = swiftnav::time::InvalidGpsTime;

    fn try_from(
        msg: messages::gnss::GpsTimeSec,
    ) -> Result<swiftnav::time::GpsTime, swiftnav::time::InvalidGpsTime> {
        swiftnav::time::GpsTime::new(msg.wn as i16, msg.tow as f64)
    }
}

impl TryFrom<messages::gnss::GnssSignal> for swiftnav::signal::GnssSignal {
    type Error = swiftnav::signal::InvalidGnssSignal;

    fn try_from(
        value: messages::gnss::GnssSignal,
    ) -> Result<swiftnav::signal::GnssSignal, swiftnav::signal::InvalidGnssSignal> {
        Ok(swiftnav::signal::GnssSignal::new(
            value.sat as u16,
            value.code.try_into()?,
        )?)
    }
}
