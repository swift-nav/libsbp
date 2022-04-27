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
        swiftnav::signal::GnssSignal::new(value.sat as u16, value.code.try_into()?)
    }
}

impl TryFrom<messages::observation::MsgEphemerisGps> for swiftnav::ephemeris::Ephemeris {
    type Error = EphemerisDecodeError;

    fn try_from(
        eph: messages::observation::MsgEphemerisGps,
    ) -> Result<swiftnav::ephemeris::Ephemeris, EphemerisDecodeError> {
        Ok(swiftnav::ephemeris::Ephemeris::new(
            eph.common.sid.try_into()?,
            eph.common.toe.try_into()?,
            eph.common.ura,
            eph.common.fit_interval,
            eph.common.valid,
            eph.common.health_bits,
            0,
            swiftnav::ephemeris::EphemerisTerms::new_kepler(
                swiftnav::signal::Constellation::Gps,
                [eph.tgd, 0.],
                eph.c_rc as f64,
                eph.c_rs as f64,
                eph.c_uc as f64,
                eph.c_us as f64,
                eph.c_ic as f64,
                eph.c_is as f64,
                eph.dn,
                eph.m0,
                eph.ecc,
                eph.sqrta,
                eph.omega0,
                eph.omegadot,
                eph.w,
                eph.inc,
                eph.inc_dot,
                eph.af0 as f64,
                eph.af1 as f64,
                eph.af2 as f64,
                eph.toc.try_into()?,
                eph.iodc,
                eph.iode as u16,
            ),
        ))
    }
}

impl TryFrom<messages::observation::MsgEphemerisGal> for swiftnav::ephemeris::Ephemeris {
    type Error = EphemerisDecodeError;

    fn try_from(
        eph: messages::observation::MsgEphemerisGal,
    ) -> Result<swiftnav::ephemeris::Ephemeris, EphemerisDecodeError> {
        Ok(swiftnav::ephemeris::Ephemeris::new(
            eph.common.sid.try_into()?,
            eph.common.toe.try_into()?,
            eph.common.ura,
            eph.common.fit_interval,
            eph.common.valid,
            eph.common.health_bits,
            eph.source,
            swiftnav::ephemeris::EphemerisTerms::new_kepler(
                swiftnav::signal::Constellation::Gal,
                [eph.bgd_e1e5a, eph.bgd_e1e5b],
                eph.c_rc as f64,
                eph.c_rs as f64,
                eph.c_uc as f64,
                eph.c_us as f64,
                eph.c_ic as f64,
                eph.c_is as f64,
                eph.dn,
                eph.m0,
                eph.ecc,
                eph.sqrta,
                eph.omega0,
                eph.omegadot,
                eph.w,
                eph.inc,
                eph.inc_dot,
                eph.af0 as f64,
                eph.af1 as f64,
                eph.af2 as f64,
                eph.toc.try_into()?,
                eph.iodc,
                eph.iode as u16,
            ),
        ))
    }
}

#[derive(Debug, Copy, Clone, PartialOrd, PartialEq)]
pub enum EphemerisDecodeError {
    InvalidTime(swiftnav::time::InvalidGpsTime),
    InvalidSignal(swiftnav::signal::InvalidGnssSignal),
}

impl fmt::Display for EphemerisDecodeError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            EphemerisDecodeError::InvalidTime(e) => e.fmt(f),
            EphemerisDecodeError::InvalidSignal(e) => e.fmt(f),
        }
    }
}

impl std::error::Error for EphemerisDecodeError {}

impl From<swiftnav::time::InvalidGpsTime> for EphemerisDecodeError {
    fn from(e: swiftnav::time::InvalidGpsTime) -> Self {
        EphemerisDecodeError::InvalidTime(e)
    }
}

impl From<swiftnav::signal::InvalidGnssSignal> for EphemerisDecodeError {
    fn from(e: swiftnav::signal::InvalidGnssSignal) -> Self {
        EphemerisDecodeError::InvalidSignal(e)
    }
}

impl TryFrom<messages::observation::PackedObsContent> for swiftnav::navmeas::NavigationMeasurement {
    type Error = swiftnav::signal::InvalidGnssSignal;

    fn try_from(
        observation: messages::observation::PackedObsContent,
    ) -> Result<swiftnav::navmeas::NavigationMeasurement, swiftnav::signal::InvalidGnssSignal> {
        let mut measurement = swiftnav::navmeas::NavigationMeasurement::new();

        measurement.set_lock_time(swiftnav::navmeas::decode_lock_time(observation.lock));
        measurement.set_sid(observation.sid.try_into()?);
        // A CN0 of 0 is considered invalid
        if observation.cn0 != 0 {
            measurement.set_cn0(observation.cn0 as f64 / 4.);
        }
        if observation.flags & 0x01 != 0 {
            measurement.set_pseudorange(observation.p as f64 / 5e1);
        }
        if observation.flags & 0x08 != 0 {
            measurement
                .set_measured_doppler(observation.d.i as f64 + (observation.d.f as f64) / 256.);
        }
        if observation.flags & 0x80 != 0 {
            measurement
                .set_flags(measurement.flags() | swiftnav::navmeas::NAV_MEAS_FLAG_RAIM_EXCLUSION);
        }

        Ok(measurement)
    }
}
