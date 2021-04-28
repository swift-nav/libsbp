//! Native implementation of decoding of SBP (Swift Binary Protocol) used by products
//! made by Swift Navigation. For language agnostic description of the protocol please
//! see the protocol specification documentation at https://github.com/swift-nav/libsbp/tree/master/docs

pub mod codec;
pub mod messages;
pub(crate) mod parser;
pub mod serialize;

use std::{
    convert::{From, Into},
    fmt, result,
};

#[cfg(feature = "sbp_serde")]
use serde::{Deserialize, Deserializer, Serialize, Serializer};

use crate::{messages::SBPMessage, serialize::SbpSerialize};

pub const SBP_MAX_PAYLOAD_SIZE: usize = 255;
pub const MSG_HEADER_LEN: usize = 1 /*preamble*/ + 2 /*msg_type*/ + 2 /*sender_id*/ + 1 /*len*/;
pub const MSG_CRC_LEN: usize = 2;

pub use codec::sbp::iter_messages;

#[cfg(feature = "async")]
pub use codec::sbp::stream_messages;

#[cfg(feature = "json")]
pub mod json {
    pub use crate::codec::json::iter_messages;

    #[cfg(feature = "async")]
    pub use crate::codec::json::stream_messages;
}

#[derive(Debug, Clone)]
pub struct SbpString(Vec<u8>);

impl SbpString {
    pub fn as_bytes(&self) -> &[u8] {
        &self.0
    }
    pub fn to_string(&self) -> String {
        String::from_utf8_lossy(&self.0).into()
    }
}

#[cfg(feature = "sbp_serde")]
impl Serialize for SbpString {
    fn serialize<S>(&self, serializer: S) -> result::Result<S::Ok, S::Error>
    where
        S: Serializer,
    {
        let s: String = self.clone().into();
        serializer.serialize_str(&s)
    }
}

#[cfg(feature = "sbp_serde")]
impl<'de> Deserialize<'de> for SbpString {
    fn deserialize<D>(deserializer: D) -> result::Result<Self, D::Error>
    where
        D: Deserializer<'de>,
    {
        Deserialize::deserialize(deserializer).map(|s: String| SbpString::from(s))
    }
}

impl From<String> for SbpString {
    fn from(s: String) -> SbpString {
        SbpString(s.as_bytes().to_vec())
    }
}

impl Into<String> for SbpString {
    fn into(self) -> String {
        self.to_string()
    }
}

impl Into<String> for &SbpString {
    fn into(self) -> String {
        self.to_string()
    }
}

impl Into<Vec<u8>> for SbpString {
    fn into(self) -> Vec<u8> {
        self.0
    }
}

impl fmt::Display for SbpString {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "SbpString({})", Into::<String>::into(self.clone()))
    }
}

pub type Result<T> = result::Result<T, Error>;

#[derive(Debug, thiserror::Error)]
pub enum Error {
    #[error("An error occured during parsing. Error kind: {kind:?}")]
    ParseError { kind: nom::error::ErrorKind },

    #[cfg(feature = "json")]
    #[error("Failed to parse sbp message from json: {details}")]
    JsonParseError { details: String },

    #[error(
        "CRC validation failed: sender_id={sender_id:#02X?} msg_type={msg_type:#02X?} crc={crc:#02X?}"
    )]
    CrcError {
        msg_type: u16,
        sender_id: u16,
        crc: u16,
    },

    #[error(transparent)]
    FramerError(#[from] FramerError),

    #[cfg(feature = "json")]
    #[error(transparent)]
    SerdeJsonError(#[from] serde_json::error::Error),

    #[error(transparent)]
    IoError(#[from] std::io::Error),
}

#[cfg(feature = "swiftnav-rs")]
#[derive(Debug, thiserror::Error)]
pub enum GpsTimeError {
    #[error(transparent)]
    InvalidGpsTime(#[from] swiftnav_rs::time::InvalidGpsTime),

    #[error("Failed to convert week number to i16")]
    TryFromIntError(#[from] std::num::TryFromIntError),
}

pub(crate) fn write_frame<M: SBPMessage>(
    msg: &M,
    frame: &mut Vec<u8>,
) -> std::result::Result<(), FramerError> {
    let len = msg.sbp_size();
    if len > SBP_MAX_PAYLOAD_SIZE {
        return Err(crate::FramerError::TooLarge);
    }
    let sender_id = msg.get_sender_id().ok_or(FramerError::NoSenderId)?;

    frame.reserve(len);

    (0x55 as u8).append_to_sbp_buffer(frame);
    msg.get_message_type().append_to_sbp_buffer(frame);
    sender_id.append_to_sbp_buffer(frame);
    (len as u8).append_to_sbp_buffer(frame);
    msg.append_to_sbp_buffer(frame);
    crc16::State::<crc16::XMODEM>::calculate(&frame[1..]).append_to_sbp_buffer(frame);

    Ok(())
}

#[derive(Debug, thiserror::Error)]
pub enum FramerError {
    #[error("Message is too large to fit into an SBP frame")]
    TooLarge,

    #[error("No sender ID is present in the message bring framed")]
    NoSenderId,
}

#[cfg(feature = "swiftnav-rs")]
mod swiftnav_rs_conversions {
    use std::convert::{TryFrom, TryInto};

    use crate::messages;

    impl TryFrom<messages::gnss::GPSTime> for swiftnav_rs::time::GpsTime {
        type Error = swiftnav_rs::time::InvalidGpsTime;

        fn try_from(
            msg: messages::gnss::GPSTime,
        ) -> Result<swiftnav_rs::time::GpsTime, swiftnav_rs::time::InvalidGpsTime> {
            let tow = (msg.tow as f64) * 1e-3 + (msg.ns_residual as f64) * 1e-9;
            swiftnav_rs::time::GpsTime::new(msg.wn as i16, tow)
        }
    }

    impl TryFrom<messages::gnss::GPSTimeSec> for swiftnav_rs::time::GpsTime {
        type Error = swiftnav_rs::time::InvalidGpsTime;

        fn try_from(
            msg: messages::gnss::GPSTimeSec,
        ) -> Result<swiftnav_rs::time::GpsTime, swiftnav_rs::time::InvalidGpsTime> {
            swiftnav_rs::time::GpsTime::new(msg.wn as i16, msg.tow as f64)
        }
    }

    impl TryFrom<messages::gnss::GnssSignal> for swiftnav_rs::signal::GnssSignal {
        type Error = swiftnav_rs::signal::InvalidGnssSignal;

        fn try_from(
            value: messages::gnss::GnssSignal,
        ) -> Result<swiftnav_rs::signal::GnssSignal, swiftnav_rs::signal::InvalidGnssSignal>
        {
            swiftnav_rs::signal::GnssSignal::new(value.sat as u16, value.code.try_into()?)
        }
    }

    impl TryFrom<messages::observation::MsgEphemerisGPS> for swiftnav_rs::ephemeris::Ephemeris {
        type Error = EphemerisDecodeError;

        fn try_from(
            eph: messages::observation::MsgEphemerisGPS,
        ) -> Result<swiftnav_rs::ephemeris::Ephemeris, EphemerisDecodeError> {
            Ok(swiftnav_rs::ephemeris::Ephemeris::new(
                eph.common.sid.try_into()?,
                eph.common.toe.try_into()?,
                eph.common.ura,
                eph.common.fit_interval,
                eph.common.valid,
                eph.common.health_bits,
                0,
                swiftnav_rs::ephemeris::EphemerisTerms::new_kepler(
                    swiftnav_rs::signal::Constellation::Gps,
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

    impl TryFrom<messages::observation::MsgEphemerisGal> for swiftnav_rs::ephemeris::Ephemeris {
        type Error = EphemerisDecodeError;

        fn try_from(
            eph: messages::observation::MsgEphemerisGal,
        ) -> Result<swiftnav_rs::ephemeris::Ephemeris, EphemerisDecodeError> {
            Ok(swiftnav_rs::ephemeris::Ephemeris::new(
                eph.common.sid.try_into()?,
                eph.common.toe.try_into()?,
                eph.common.ura,
                eph.common.fit_interval,
                eph.common.valid,
                eph.common.health_bits,
                eph.source,
                swiftnav_rs::ephemeris::EphemerisTerms::new_kepler(
                    swiftnav_rs::signal::Constellation::Gal,
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

    #[derive(Debug, Copy, Clone, PartialOrd, PartialEq, thiserror::Error)]
    pub enum EphemerisDecodeError {
        #[error(transparent)]
        InvalidTime(#[from] swiftnav_rs::time::InvalidGpsTime),

        #[error(transparent)]
        InvalidSignal(#[from] swiftnav_rs::signal::InvalidGnssSignal),
    }

    impl TryFrom<messages::observation::PackedObsContent>
        for swiftnav_rs::navmeas::NavigationMeasurement
    {
        type Error = swiftnav_rs::signal::InvalidGnssSignal;

        fn try_from(
            observation: messages::observation::PackedObsContent,
        ) -> Result<
            swiftnav_rs::navmeas::NavigationMeasurement,
            swiftnav_rs::signal::InvalidGnssSignal,
        > {
            let mut measurement = swiftnav_rs::navmeas::NavigationMeasurement::new();

            measurement.set_lock_time(swiftnav_rs::navmeas::decode_lock_time(observation.lock));
            measurement.set_sid(observation.sid.try_into()?);
            // A CN0 of 0 is considered invalid
            if observation.cn0 != 0 {
                measurement.set_cn0(observation.cn0 as f64 / 4.);
            }
            if observation.flags & 0x01 != 0 {
                measurement.set_pseudorange(observation.P as f64 / 5e1);
            }
            if observation.flags & 0x08 != 0 {
                measurement
                    .set_measured_doppler(observation.D.i as f64 + (observation.D.f as f64) / 256.);
            }
            if observation.flags & 0x80 != 0 {
                // measurement.0.flags and swiftnav_rs::navmeas::NAV_MEAS_FLAG_RAIM_EXCLUSION are private
                // measurement.0.flags |= swiftnav_rs::navmeas::NAV_MEAS_FLAG_RAIM_EXCLUSION;
            }

            Ok(measurement)
        }
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn test_making_frame() {
        use crate::messages::SBPMessage;

        let msg = crate::messages::system::MsgStartup {
            sender_id: Some(250),
            cause: 1,
            startup_type: 45,
            reserved: 0,
        };

        let frame = msg.to_frame().unwrap();

        let expected_frame = b"\x55\x00\xFF\xFA\x00\x04\x01\x2D\x00\x00\xBC\x73";

        assert_eq!(frame, expected_frame);
    }

    #[test]
    fn test_sbp_string() {
        use crate::SbpString;

        let sbp_str = SbpString(b"1234".to_vec());
        let s = sbp_str.to_string();

        assert_eq!("1234", s);

        let sbp_str = SbpString(b"1234\xFF".to_vec());
        let s = sbp_str.to_string();

        assert_eq!("1234\u{FFFD}", s);
    }
}
