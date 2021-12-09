// Copyright (C) 2015-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

//****************************************************************************
// Automatically generated from yaml/swiftnav/sbp/navigation.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Geodetic navigation messages reporting GPS time, position, velocity, and
//! baseline position solutions. For position solutions, these messages define
//! several different position solutions: single-point (SPP), RTK, and pseudo-
//! absolute position solutions.
//!
//! The SPP is the standalone, absolute GPS position solution using only a
//! single receiver. The RTK solution is the differential GPS solution, which
//! can use either a fixed/integer or floating carrier phase ambiguity. The
//! pseudo-absolute position solution uses a user-provided, well-surveyed base
//! station position (if available) and the RTK solution in tandem.
//!
//! When the inertial navigation mode indicates that the IMU is used, all
//! messages are reported in the vehicle body frame as defined by device
//! settings.  By default, the vehicle body frame is configured to be
//! coincident with the antenna phase center.  When there is no inertial
//! navigation, the solution will be reported at the phase center of the
//! antenna. There is no inertial navigation capability on Piksi Multi or
//! Duro.
//!
//! The tow field, when valid, is most often the Time of Measurement. When
//! this is the case, the 5th bit of flags is set to the default value of 0.
//! When this is not the case, the tow may be a time of arrival or a local
//! system timestamp, irrespective of the time reference (GPS Week or else),
//! but not a Time of Measurement.

use super::lib::*;

/// Horizontal estimated error ellipse
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct EstimatedHorizontalErrorEllipse {
    /// The semi major axis of the estimated horizontal error ellipse at the
    /// user-configured confidence level; zero implies invalid.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "semi_major")))]
    pub semi_major: f32,
    /// The semi minor axis of the estimated horizontal error ellipse at the
    /// user-configured confidence level; zero implies invalid.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "semi_minor")))]
    pub semi_minor: f32,
    /// The orientation of the semi major axis of the estimated horizontal error
    /// ellipse with respect to North.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "orientation")))]
    pub orientation: f32,
}

impl WireFormat for EstimatedHorizontalErrorEllipse {
    const MIN_LEN: usize =
        <f32 as WireFormat>::MIN_LEN + <f32 as WireFormat>::MIN_LEN + <f32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.semi_major)
            + WireFormat::len(&self.semi_minor)
            + WireFormat::len(&self.orientation)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.semi_major, buf);
        WireFormat::write(&self.semi_minor, buf);
        WireFormat::write(&self.orientation, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        EstimatedHorizontalErrorEllipse {
            semi_major: WireFormat::parse_unchecked(buf),
            semi_minor: WireFormat::parse_unchecked(buf),
            orientation: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Age of corrections
///
/// This message reports the Age of the corrections used for the current
/// Differential solution.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgAgeCorrections {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Age of the corrections (0xFFFF indicates invalid)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "age")))]
    pub age: u16,
}

impl ConcreteMessage for MsgAgeCorrections {
    const MESSAGE_TYPE: u16 = 528;
    const MESSAGE_NAME: &'static str = "MSG_AGE_CORRECTIONS";
}

impl SbpMessage for MsgAgeCorrections {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgAgeCorrections {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgAgeCorrections(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgAgeCorrections {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN + <u16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow) + WireFormat::len(&self.age)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.age, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgAgeCorrections {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            age: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Baseline Position in ECEF
///
/// This message reports the baseline solution in Earth Centered Earth Fixed
/// (ECEF) coordinates. This baseline is the relative vector distance from the
/// base station to the rover receiver. The full GPS time is given by the
/// preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgBaselineEcef {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Baseline ECEF X coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x")))]
    pub x: i32,
    /// Baseline ECEF Y coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y")))]
    pub y: i32,
    /// Baseline ECEF Z coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z")))]
    pub z: i32,
    /// Position estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "accuracy")))]
    pub accuracy: u16,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgBaselineEcef {
    const MESSAGE_TYPE: u16 = 523;
    const MESSAGE_NAME: &'static str = "MSG_BASELINE_ECEF";
}

impl SbpMessage for MsgBaselineEcef {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgBaselineEcef {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgBaselineEcef(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgBaselineEcef {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.x)
            + WireFormat::len(&self.y)
            + WireFormat::len(&self.z)
            + WireFormat::len(&self.accuracy)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.x, buf);
        WireFormat::write(&self.y, buf);
        WireFormat::write(&self.z, buf);
        WireFormat::write(&self.accuracy, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgBaselineEcef {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            x: WireFormat::parse_unchecked(buf),
            y: WireFormat::parse_unchecked(buf),
            z: WireFormat::parse_unchecked(buf),
            accuracy: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Baseline Position in ECEF
///
/// This message reports the baseline solution in Earth Centered Earth Fixed
/// (ECEF) coordinates. This baseline is the relative vector distance from the
/// base station to the rover receiver. The full GPS time is given by the
/// preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgBaselineEcefDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Baseline ECEF X coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x")))]
    pub x: i32,
    /// Baseline ECEF Y coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y")))]
    pub y: i32,
    /// Baseline ECEF Z coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z")))]
    pub z: i32,
    /// Position accuracy estimate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "accuracy")))]
    pub accuracy: u16,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgBaselineEcefDepA {
    const MESSAGE_TYPE: u16 = 514;
    const MESSAGE_NAME: &'static str = "MSG_BASELINE_ECEF_DEP_A";
}

impl SbpMessage for MsgBaselineEcefDepA {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgBaselineEcefDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgBaselineEcefDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgBaselineEcefDepA {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.x)
            + WireFormat::len(&self.y)
            + WireFormat::len(&self.z)
            + WireFormat::len(&self.accuracy)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.x, buf);
        WireFormat::write(&self.y, buf);
        WireFormat::write(&self.z, buf);
        WireFormat::write(&self.accuracy, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgBaselineEcefDepA {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            x: WireFormat::parse_unchecked(buf),
            y: WireFormat::parse_unchecked(buf),
            z: WireFormat::parse_unchecked(buf),
            accuracy: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Heading relative to True North
///
/// This message reports the baseline heading pointing from the base station
/// to the rover relative to True North. The full GPS time is given by the
/// preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgBaselineHeadingDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Heading
    #[cfg_attr(feature = "serde", serde(rename(serialize = "heading")))]
    pub heading: u32,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgBaselineHeadingDepA {
    const MESSAGE_TYPE: u16 = 519;
    const MESSAGE_NAME: &'static str = "MSG_BASELINE_HEADING_DEP_A";
}

impl SbpMessage for MsgBaselineHeadingDepA {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgBaselineHeadingDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgBaselineHeadingDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgBaselineHeadingDepA {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.heading)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.heading, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgBaselineHeadingDepA {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            heading: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Baseline in NED
///
/// This message reports the baseline solution in North East Down (NED)
/// coordinates. This baseline is the relative vector distance from the base
/// station to the rover receiver, and NED coordinate system is defined at the
/// local WGS84 tangent plane centered at the base station position.  The full
/// GPS time is given by the preceding MSG_GPS_TIME with the matching time-of-
/// week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgBaselineNed {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Baseline North coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n")))]
    pub n: i32,
    /// Baseline East coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "e")))]
    pub e: i32,
    /// Baseline Down coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "d")))]
    pub d: i32,
    /// Horizontal position estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "h_accuracy")))]
    pub h_accuracy: u16,
    /// Vertical position estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "v_accuracy")))]
    pub v_accuracy: u16,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgBaselineNed {
    const MESSAGE_TYPE: u16 = 524;
    const MESSAGE_NAME: &'static str = "MSG_BASELINE_NED";
}

impl SbpMessage for MsgBaselineNed {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgBaselineNed {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgBaselineNed(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgBaselineNed {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.n)
            + WireFormat::len(&self.e)
            + WireFormat::len(&self.d)
            + WireFormat::len(&self.h_accuracy)
            + WireFormat::len(&self.v_accuracy)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.n, buf);
        WireFormat::write(&self.e, buf);
        WireFormat::write(&self.d, buf);
        WireFormat::write(&self.h_accuracy, buf);
        WireFormat::write(&self.v_accuracy, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgBaselineNed {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            n: WireFormat::parse_unchecked(buf),
            e: WireFormat::parse_unchecked(buf),
            d: WireFormat::parse_unchecked(buf),
            h_accuracy: WireFormat::parse_unchecked(buf),
            v_accuracy: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Baseline in NED
///
/// This message reports the baseline solution in North East Down (NED)
/// coordinates. This baseline is the relative vector distance from the base
/// station to the rover receiver, and NED coordinate system is defined at the
/// local WGS84 tangent plane centered at the base station position.  The full
/// GPS time is given by the preceding MSG_GPS_TIME with the matching time-of-
/// week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgBaselineNedDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Baseline North coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n")))]
    pub n: i32,
    /// Baseline East coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "e")))]
    pub e: i32,
    /// Baseline Down coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "d")))]
    pub d: i32,
    /// Horizontal position accuracy estimate (not implemented). Defaults to 0.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "h_accuracy")))]
    pub h_accuracy: u16,
    /// Vertical position accuracy estimate (not implemented). Defaults to 0.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "v_accuracy")))]
    pub v_accuracy: u16,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgBaselineNedDepA {
    const MESSAGE_TYPE: u16 = 515;
    const MESSAGE_NAME: &'static str = "MSG_BASELINE_NED_DEP_A";
}

impl SbpMessage for MsgBaselineNedDepA {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgBaselineNedDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgBaselineNedDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgBaselineNedDepA {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.n)
            + WireFormat::len(&self.e)
            + WireFormat::len(&self.d)
            + WireFormat::len(&self.h_accuracy)
            + WireFormat::len(&self.v_accuracy)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.n, buf);
        WireFormat::write(&self.e, buf);
        WireFormat::write(&self.d, buf);
        WireFormat::write(&self.h_accuracy, buf);
        WireFormat::write(&self.v_accuracy, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgBaselineNedDepA {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            n: WireFormat::parse_unchecked(buf),
            e: WireFormat::parse_unchecked(buf),
            d: WireFormat::parse_unchecked(buf),
            h_accuracy: WireFormat::parse_unchecked(buf),
            v_accuracy: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Dilution of Precision
///
/// This dilution of precision (DOP) message describes the effect of
/// navigation satellite geometry on positional measurement precision.  The
/// flags field indicated whether the DOP reported corresponds to differential
/// or SPP solution.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgDops {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Geometric Dilution of Precision
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gdop")))]
    pub gdop: u16,
    /// Position Dilution of Precision
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pdop")))]
    pub pdop: u16,
    /// Time Dilution of Precision
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tdop")))]
    pub tdop: u16,
    /// Horizontal Dilution of Precision
    #[cfg_attr(feature = "serde", serde(rename(serialize = "hdop")))]
    pub hdop: u16,
    /// Vertical Dilution of Precision
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vdop")))]
    pub vdop: u16,
    /// Indicates the position solution with which the DOPS message corresponds
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgDops {
    const MESSAGE_TYPE: u16 = 520;
    const MESSAGE_NAME: &'static str = "MSG_DOPS";
}

impl SbpMessage for MsgDops {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgDops {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgDops(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgDops {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.gdop)
            + WireFormat::len(&self.pdop)
            + WireFormat::len(&self.tdop)
            + WireFormat::len(&self.hdop)
            + WireFormat::len(&self.vdop)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.gdop, buf);
        WireFormat::write(&self.pdop, buf);
        WireFormat::write(&self.tdop, buf);
        WireFormat::write(&self.hdop, buf);
        WireFormat::write(&self.vdop, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgDops {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            gdop: WireFormat::parse_unchecked(buf),
            pdop: WireFormat::parse_unchecked(buf),
            tdop: WireFormat::parse_unchecked(buf),
            hdop: WireFormat::parse_unchecked(buf),
            vdop: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Dilution of Precision
///
/// This dilution of precision (DOP) message describes the effect of
/// navigation satellite geometry on positional measurement precision.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgDopsDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Geometric Dilution of Precision
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gdop")))]
    pub gdop: u16,
    /// Position Dilution of Precision
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pdop")))]
    pub pdop: u16,
    /// Time Dilution of Precision
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tdop")))]
    pub tdop: u16,
    /// Horizontal Dilution of Precision
    #[cfg_attr(feature = "serde", serde(rename(serialize = "hdop")))]
    pub hdop: u16,
    /// Vertical Dilution of Precision
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vdop")))]
    pub vdop: u16,
}

impl ConcreteMessage for MsgDopsDepA {
    const MESSAGE_TYPE: u16 = 518;
    const MESSAGE_NAME: &'static str = "MSG_DOPS_DEP_A";
}

impl SbpMessage for MsgDopsDepA {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgDopsDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgDopsDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgDopsDepA {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.gdop)
            + WireFormat::len(&self.pdop)
            + WireFormat::len(&self.tdop)
            + WireFormat::len(&self.hdop)
            + WireFormat::len(&self.vdop)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.gdop, buf);
        WireFormat::write(&self.pdop, buf);
        WireFormat::write(&self.tdop, buf);
        WireFormat::write(&self.hdop, buf);
        WireFormat::write(&self.vdop, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgDopsDepA {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            gdop: WireFormat::parse_unchecked(buf),
            pdop: WireFormat::parse_unchecked(buf),
            tdop: WireFormat::parse_unchecked(buf),
            hdop: WireFormat::parse_unchecked(buf),
            vdop: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GPS Time
///
/// This message reports the GPS time, representing the time since the GPS
/// epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks and
/// seconds of the week. The weeks begin at the Saturday/Sunday transition.
/// GPS week 0 began at the beginning of the GPS time scale.
///
/// Within each week number, the GPS time of the week is between between 0 and
/// 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate leap
/// seconds, and as of now, has a small offset from UTC. In a message stream,
/// this message precedes a set of other navigation messages referenced to the
/// same time (but lacking the ns field) and indicates a more precise time of
/// these messages.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgGpsTime {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS week number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "wn")))]
    pub wn: u16,
    /// GPS time of week rounded to the nearest millisecond
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    /// 500000)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ns_residual")))]
    pub ns_residual: i32,
    /// Status flags (reserved)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgGpsTime {
    const MESSAGE_TYPE: u16 = 258;
    const MESSAGE_NAME: &'static str = "MSG_GPS_TIME";
}

impl SbpMessage for MsgGpsTime {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        #[allow(clippy::useless_conversion)]
        let wn: i16 = match self.wn.try_into() {
            Ok(wn) => wn,
            Err(e) => return Some(Err(e.into())),
        };
        let gps_time = match time::GpsTime::new(wn, tow_s) {
            Ok(gps_time) => gps_time,
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgGpsTime {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgGpsTime(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgGpsTime {
    const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.wn)
            + WireFormat::len(&self.tow)
            + WireFormat::len(&self.ns_residual)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.wn, buf);
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.ns_residual, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgGpsTime {
            sender_id: None,
            wn: WireFormat::parse_unchecked(buf),
            tow: WireFormat::parse_unchecked(buf),
            ns_residual: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GPS Time (v1.0)
///
/// This message reports the GPS time, representing the time since the GPS
/// epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks and
/// seconds of the week. The weeks begin at the Saturday/Sunday transition.
/// GPS week 0 began at the beginning of the GPS time scale.
///
/// Within each week number, the GPS time of the week is between between 0 and
/// 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate leap
/// seconds, and as of now, has a small offset from UTC. In a message stream,
/// this message precedes a set of other navigation messages referenced to the
/// same time (but lacking the ns field) and indicates a more precise time of
/// these messages.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgGpsTimeDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS week number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "wn")))]
    pub wn: u16,
    /// GPS time of week rounded to the nearest millisecond
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    /// 500000)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ns_residual")))]
    pub ns_residual: i32,
    /// Status flags (reserved)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgGpsTimeDepA {
    const MESSAGE_TYPE: u16 = 256;
    const MESSAGE_NAME: &'static str = "MSG_GPS_TIME_DEP_A";
}

impl SbpMessage for MsgGpsTimeDepA {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        #[allow(clippy::useless_conversion)]
        let wn: i16 = match self.wn.try_into() {
            Ok(wn) => wn,
            Err(e) => return Some(Err(e.into())),
        };
        let gps_time = match time::GpsTime::new(wn, tow_s) {
            Ok(gps_time) => gps_time,
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgGpsTimeDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgGpsTimeDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgGpsTimeDepA {
    const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.wn)
            + WireFormat::len(&self.tow)
            + WireFormat::len(&self.ns_residual)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.wn, buf);
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.ns_residual, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgGpsTimeDepA {
            sender_id: None,
            wn: WireFormat::parse_unchecked(buf),
            tow: WireFormat::parse_unchecked(buf),
            ns_residual: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GPS Time
///
/// This message reports the GPS time, representing the time since the GPS
/// epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks and
/// seconds of the week. The weeks begin at the Saturday/Sunday transition.
/// GPS week 0 began at the beginning of the GPS time scale.
///
/// Within each week number, the GPS time of the week is between between 0 and
/// 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate leap
/// seconds, and as of now, has a small offset from UTC. In a message stream,
/// this message precedes a set of other navigation messages referenced to the
/// same time (but lacking the ns field) and indicates a more precise time of
/// these messages.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgGpsTimeGnss {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS week number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "wn")))]
    pub wn: u16,
    /// GPS time of week rounded to the nearest millisecond
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    /// 500000)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ns_residual")))]
    pub ns_residual: i32,
    /// Status flags (reserved)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgGpsTimeGnss {
    const MESSAGE_TYPE: u16 = 260;
    const MESSAGE_NAME: &'static str = "MSG_GPS_TIME_GNSS";
}

impl SbpMessage for MsgGpsTimeGnss {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        #[allow(clippy::useless_conversion)]
        let wn: i16 = match self.wn.try_into() {
            Ok(wn) => wn,
            Err(e) => return Some(Err(e.into())),
        };
        let gps_time = match time::GpsTime::new(wn, tow_s) {
            Ok(gps_time) => gps_time,
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgGpsTimeGnss {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgGpsTimeGnss(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgGpsTimeGnss {
    const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.wn)
            + WireFormat::len(&self.tow)
            + WireFormat::len(&self.ns_residual)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.wn, buf);
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.ns_residual, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgGpsTimeGnss {
            sender_id: None,
            wn: WireFormat::parse_unchecked(buf),
            tow: WireFormat::parse_unchecked(buf),
            ns_residual: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Single-point position in ECEF
///
/// The position solution message reports absolute Earth Centered Earth Fixed
/// (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
/// the position solution. If the rover receiver knows the surveyed position
/// of the base station and has an RTK solution, this reports a pseudo-
/// absolute position solution using the base station position and the rover's
/// RTK baseline vector. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgPosEcef {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// ECEF X coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x")))]
    pub x: f64,
    /// ECEF Y coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y")))]
    pub y: f64,
    /// ECEF Z coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z")))]
    pub z: f64,
    /// Position estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "accuracy")))]
    pub accuracy: u16,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgPosEcef {
    const MESSAGE_TYPE: u16 = 521;
    const MESSAGE_NAME: &'static str = "MSG_POS_ECEF";
}

impl SbpMessage for MsgPosEcef {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgPosEcef {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgPosEcef(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgPosEcef {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.x)
            + WireFormat::len(&self.y)
            + WireFormat::len(&self.z)
            + WireFormat::len(&self.accuracy)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.x, buf);
        WireFormat::write(&self.y, buf);
        WireFormat::write(&self.z, buf);
        WireFormat::write(&self.accuracy, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgPosEcef {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            x: WireFormat::parse_unchecked(buf),
            y: WireFormat::parse_unchecked(buf),
            z: WireFormat::parse_unchecked(buf),
            accuracy: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Single-point position in ECEF
///
/// The position solution message reports absolute Earth Centered Earth Fixed
/// (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
/// the position solution. The message also reports the upper triangular
/// portion of the 3x3 covariance matrix. If the receiver knows the surveyed
/// position of the base station and has an RTK solution, this reports a
/// pseudo-absolute position solution using the base station position and the
/// rover's RTK baseline vector. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgPosEcefCov {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// ECEF X coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x")))]
    pub x: f64,
    /// ECEF Y coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y")))]
    pub y: f64,
    /// ECEF Z coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z")))]
    pub z: f64,
    /// Estimated variance of x
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_x_x")))]
    pub cov_x_x: f32,
    /// Estimated covariance of x and y
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_x_y")))]
    pub cov_x_y: f32,
    /// Estimated covariance of x and z
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_x_z")))]
    pub cov_x_z: f32,
    /// Estimated variance of y
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_y_y")))]
    pub cov_y_y: f32,
    /// Estimated covariance of y and z
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_y_z")))]
    pub cov_y_z: f32,
    /// Estimated variance of z
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_z_z")))]
    pub cov_z_z: f32,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgPosEcefCov {
    const MESSAGE_TYPE: u16 = 532;
    const MESSAGE_NAME: &'static str = "MSG_POS_ECEF_COV";
}

impl SbpMessage for MsgPosEcefCov {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgPosEcefCov {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgPosEcefCov(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgPosEcefCov {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.x)
            + WireFormat::len(&self.y)
            + WireFormat::len(&self.z)
            + WireFormat::len(&self.cov_x_x)
            + WireFormat::len(&self.cov_x_y)
            + WireFormat::len(&self.cov_x_z)
            + WireFormat::len(&self.cov_y_y)
            + WireFormat::len(&self.cov_y_z)
            + WireFormat::len(&self.cov_z_z)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.x, buf);
        WireFormat::write(&self.y, buf);
        WireFormat::write(&self.z, buf);
        WireFormat::write(&self.cov_x_x, buf);
        WireFormat::write(&self.cov_x_y, buf);
        WireFormat::write(&self.cov_x_z, buf);
        WireFormat::write(&self.cov_y_y, buf);
        WireFormat::write(&self.cov_y_z, buf);
        WireFormat::write(&self.cov_z_z, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgPosEcefCov {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            x: WireFormat::parse_unchecked(buf),
            y: WireFormat::parse_unchecked(buf),
            z: WireFormat::parse_unchecked(buf),
            cov_x_x: WireFormat::parse_unchecked(buf),
            cov_x_y: WireFormat::parse_unchecked(buf),
            cov_x_z: WireFormat::parse_unchecked(buf),
            cov_y_y: WireFormat::parse_unchecked(buf),
            cov_y_z: WireFormat::parse_unchecked(buf),
            cov_z_z: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GNSS-only Position in ECEF
///
/// The position solution message reports absolute Earth Centered Earth Fixed
/// (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
/// the position solution. The message also reports the upper triangular
/// portion of the 3x3 covariance matrix. If the receiver knows the surveyed
/// position of the base station and has an RTK solution, this reports a
/// pseudo-absolute position solution using the base station position and the
/// rover's RTK baseline vector. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgPosEcefCovGnss {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// ECEF X coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x")))]
    pub x: f64,
    /// ECEF Y coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y")))]
    pub y: f64,
    /// ECEF Z coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z")))]
    pub z: f64,
    /// Estimated variance of x
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_x_x")))]
    pub cov_x_x: f32,
    /// Estimated covariance of x and y
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_x_y")))]
    pub cov_x_y: f32,
    /// Estimated covariance of x and z
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_x_z")))]
    pub cov_x_z: f32,
    /// Estimated variance of y
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_y_y")))]
    pub cov_y_y: f32,
    /// Estimated covariance of y and z
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_y_z")))]
    pub cov_y_z: f32,
    /// Estimated variance of z
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_z_z")))]
    pub cov_z_z: f32,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgPosEcefCovGnss {
    const MESSAGE_TYPE: u16 = 564;
    const MESSAGE_NAME: &'static str = "MSG_POS_ECEF_COV_GNSS";
}

impl SbpMessage for MsgPosEcefCovGnss {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgPosEcefCovGnss {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgPosEcefCovGnss(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgPosEcefCovGnss {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.x)
            + WireFormat::len(&self.y)
            + WireFormat::len(&self.z)
            + WireFormat::len(&self.cov_x_x)
            + WireFormat::len(&self.cov_x_y)
            + WireFormat::len(&self.cov_x_z)
            + WireFormat::len(&self.cov_y_y)
            + WireFormat::len(&self.cov_y_z)
            + WireFormat::len(&self.cov_z_z)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.x, buf);
        WireFormat::write(&self.y, buf);
        WireFormat::write(&self.z, buf);
        WireFormat::write(&self.cov_x_x, buf);
        WireFormat::write(&self.cov_x_y, buf);
        WireFormat::write(&self.cov_x_z, buf);
        WireFormat::write(&self.cov_y_y, buf);
        WireFormat::write(&self.cov_y_z, buf);
        WireFormat::write(&self.cov_z_z, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgPosEcefCovGnss {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            x: WireFormat::parse_unchecked(buf),
            y: WireFormat::parse_unchecked(buf),
            z: WireFormat::parse_unchecked(buf),
            cov_x_x: WireFormat::parse_unchecked(buf),
            cov_x_y: WireFormat::parse_unchecked(buf),
            cov_x_z: WireFormat::parse_unchecked(buf),
            cov_y_y: WireFormat::parse_unchecked(buf),
            cov_y_z: WireFormat::parse_unchecked(buf),
            cov_z_z: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Single-point position in ECEF
///
/// The position solution message reports absolute Earth Centered Earth Fixed
/// (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
/// the position solution. If the rover receiver knows the surveyed position
/// of the base station and has an RTK solution, this reports a pseudo-
/// absolute position solution using the base station position and the rover's
/// RTK baseline vector. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgPosEcefDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// ECEF X coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x")))]
    pub x: f64,
    /// ECEF Y coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y")))]
    pub y: f64,
    /// ECEF Z coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z")))]
    pub z: f64,
    /// Position accuracy estimate (not implemented). Defaults to 0.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "accuracy")))]
    pub accuracy: u16,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgPosEcefDepA {
    const MESSAGE_TYPE: u16 = 512;
    const MESSAGE_NAME: &'static str = "MSG_POS_ECEF_DEP_A";
}

impl SbpMessage for MsgPosEcefDepA {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgPosEcefDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgPosEcefDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgPosEcefDepA {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.x)
            + WireFormat::len(&self.y)
            + WireFormat::len(&self.z)
            + WireFormat::len(&self.accuracy)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.x, buf);
        WireFormat::write(&self.y, buf);
        WireFormat::write(&self.z, buf);
        WireFormat::write(&self.accuracy, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgPosEcefDepA {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            x: WireFormat::parse_unchecked(buf),
            y: WireFormat::parse_unchecked(buf),
            z: WireFormat::parse_unchecked(buf),
            accuracy: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GNSS-only Position in ECEF
///
/// The position solution message reports absolute Earth Centered Earth Fixed
/// (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
/// the position solution. If the rover receiver knows the surveyed position
/// of the base station and has an RTK solution, this reports a pseudo-
/// absolute position solution using the base station position and the rover's
/// RTK baseline vector. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgPosEcefGnss {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// ECEF X coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x")))]
    pub x: f64,
    /// ECEF Y coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y")))]
    pub y: f64,
    /// ECEF Z coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z")))]
    pub z: f64,
    /// Position estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "accuracy")))]
    pub accuracy: u16,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgPosEcefGnss {
    const MESSAGE_TYPE: u16 = 553;
    const MESSAGE_NAME: &'static str = "MSG_POS_ECEF_GNSS";
}

impl SbpMessage for MsgPosEcefGnss {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgPosEcefGnss {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgPosEcefGnss(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgPosEcefGnss {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.x)
            + WireFormat::len(&self.y)
            + WireFormat::len(&self.z)
            + WireFormat::len(&self.accuracy)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.x, buf);
        WireFormat::write(&self.y, buf);
        WireFormat::write(&self.z, buf);
        WireFormat::write(&self.accuracy, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgPosEcefGnss {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            x: WireFormat::parse_unchecked(buf),
            y: WireFormat::parse_unchecked(buf),
            z: WireFormat::parse_unchecked(buf),
            accuracy: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Geodetic Position
///
/// This position solution message reports the absolute geodetic coordinates
/// and the status (single point vs pseudo-absolute RTK) of the position
/// solution. If the rover receiver knows the surveyed position of the base
/// station and has an RTK solution, this reports a pseudo-absolute position
/// solution using the base station position and the rover's RTK baseline
/// vector. The full GPS time is given by the preceding MSG_GPS_TIME with the
/// matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgPosLlh {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lat")))]
    pub lat: f64,
    /// Longitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lon")))]
    pub lon: f64,
    /// Height above WGS84 ellipsoid
    #[cfg_attr(feature = "serde", serde(rename(serialize = "height")))]
    pub height: f64,
    /// Horizontal position estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "h_accuracy")))]
    pub h_accuracy: u16,
    /// Vertical position estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "v_accuracy")))]
    pub v_accuracy: u16,
    /// Number of satellites used in solution.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgPosLlh {
    const MESSAGE_TYPE: u16 = 522;
    const MESSAGE_NAME: &'static str = "MSG_POS_LLH";
}

impl SbpMessage for MsgPosLlh {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgPosLlh {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgPosLlh(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgPosLlh {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.lat)
            + WireFormat::len(&self.lon)
            + WireFormat::len(&self.height)
            + WireFormat::len(&self.h_accuracy)
            + WireFormat::len(&self.v_accuracy)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.lat, buf);
        WireFormat::write(&self.lon, buf);
        WireFormat::write(&self.height, buf);
        WireFormat::write(&self.h_accuracy, buf);
        WireFormat::write(&self.v_accuracy, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgPosLlh {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            lat: WireFormat::parse_unchecked(buf),
            lon: WireFormat::parse_unchecked(buf),
            height: WireFormat::parse_unchecked(buf),
            h_accuracy: WireFormat::parse_unchecked(buf),
            v_accuracy: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Geodetic Position and Accuracy
///
/// This position solution message reports the absolute geodetic coordinates
/// and the status (single point vs pseudo-absolute RTK) of the position
/// solution as well as the estimated horizontal, vertical, cross-track and
/// along-track errors.  The position information and Fix Mode flags  follow
/// the MSG_POS_LLH message. Since the covariance matrix is computed in the
/// local-level North, East, Down frame, the estimated error terms follow that
/// convention.
///
/// The estimated errors are reported at a user-configurable confidence level.
/// The user-configured percentile is encoded in the percentile field.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgPosLlhAcc {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lat")))]
    pub lat: f64,
    /// Longitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lon")))]
    pub lon: f64,
    /// Height above WGS84 ellipsoid
    #[cfg_attr(feature = "serde", serde(rename(serialize = "height")))]
    pub height: f64,
    /// Height above the geoid (i.e. height above mean sea level). See
    /// confidence_and_geoid for geoid model used.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "orthometric_height")))]
    pub orthometric_height: f64,
    /// Estimated horizontal error at the user-configured confidence level; zero
    /// implies invalid.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "h_accuracy")))]
    pub h_accuracy: f32,
    /// Estimated vertical error at the user-configured confidence level; zero
    /// implies invalid.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "v_accuracy")))]
    pub v_accuracy: f32,
    /// Estimated cross-track error at the user-configured confidence level;
    /// zero implies invalid.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ct_accuracy")))]
    pub ct_accuracy: f32,
    /// Estimated along-track error at the user-configured confidence level;
    /// zero implies invalid.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "at_accuracy")))]
    pub at_accuracy: f32,
    /// The estimated horizontal error ellipse at the user-configured confidence
    /// level.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "h_ellipse")))]
    pub h_ellipse: EstimatedHorizontalErrorEllipse,
    /// The lower bits describe the configured confidence level for the
    /// estimated position error. The middle bits describe the geoid model used
    /// to calculate the orthometric height.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "confidence_and_geoid")))]
    pub confidence_and_geoid: u8,
    /// Number of satellites used in solution.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgPosLlhAcc {
    const MESSAGE_TYPE: u16 = 536;
    const MESSAGE_NAME: &'static str = "MSG_POS_LLH_ACC";
}

impl SbpMessage for MsgPosLlhAcc {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgPosLlhAcc {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgPosLlhAcc(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgPosLlhAcc {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <EstimatedHorizontalErrorEllipse as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.lat)
            + WireFormat::len(&self.lon)
            + WireFormat::len(&self.height)
            + WireFormat::len(&self.orthometric_height)
            + WireFormat::len(&self.h_accuracy)
            + WireFormat::len(&self.v_accuracy)
            + WireFormat::len(&self.ct_accuracy)
            + WireFormat::len(&self.at_accuracy)
            + WireFormat::len(&self.h_ellipse)
            + WireFormat::len(&self.confidence_and_geoid)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.lat, buf);
        WireFormat::write(&self.lon, buf);
        WireFormat::write(&self.height, buf);
        WireFormat::write(&self.orthometric_height, buf);
        WireFormat::write(&self.h_accuracy, buf);
        WireFormat::write(&self.v_accuracy, buf);
        WireFormat::write(&self.ct_accuracy, buf);
        WireFormat::write(&self.at_accuracy, buf);
        WireFormat::write(&self.h_ellipse, buf);
        WireFormat::write(&self.confidence_and_geoid, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgPosLlhAcc {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            lat: WireFormat::parse_unchecked(buf),
            lon: WireFormat::parse_unchecked(buf),
            height: WireFormat::parse_unchecked(buf),
            orthometric_height: WireFormat::parse_unchecked(buf),
            h_accuracy: WireFormat::parse_unchecked(buf),
            v_accuracy: WireFormat::parse_unchecked(buf),
            ct_accuracy: WireFormat::parse_unchecked(buf),
            at_accuracy: WireFormat::parse_unchecked(buf),
            h_ellipse: WireFormat::parse_unchecked(buf),
            confidence_and_geoid: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Geodetic Position
///
/// This position solution message reports the absolute geodetic coordinates
/// and the status (single point vs pseudo-absolute RTK) of the position
/// solution as well as the upper triangle of the 3x3 covariance matrix.  The
/// position information and Fix Mode flags follow the MSG_POS_LLH message.
/// Since the covariance matrix is computed in the local-level North, East,
/// Down frame, the covariance terms follow that convention. Thus, covariances
/// are reported against the "downward" measurement and care should be taken
/// with the sign convention.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgPosLlhCov {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lat")))]
    pub lat: f64,
    /// Longitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lon")))]
    pub lon: f64,
    /// Height above WGS84 ellipsoid
    #[cfg_attr(feature = "serde", serde(rename(serialize = "height")))]
    pub height: f64,
    /// Estimated variance of northing
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_n_n")))]
    pub cov_n_n: f32,
    /// Covariance of northing and easting
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_n_e")))]
    pub cov_n_e: f32,
    /// Covariance of northing and downward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_n_d")))]
    pub cov_n_d: f32,
    /// Estimated variance of easting
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_e_e")))]
    pub cov_e_e: f32,
    /// Covariance of easting and downward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_e_d")))]
    pub cov_e_d: f32,
    /// Estimated variance of downward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_d_d")))]
    pub cov_d_d: f32,
    /// Number of satellites used in solution.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgPosLlhCov {
    const MESSAGE_TYPE: u16 = 529;
    const MESSAGE_NAME: &'static str = "MSG_POS_LLH_COV";
}

impl SbpMessage for MsgPosLlhCov {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgPosLlhCov {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgPosLlhCov(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgPosLlhCov {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.lat)
            + WireFormat::len(&self.lon)
            + WireFormat::len(&self.height)
            + WireFormat::len(&self.cov_n_n)
            + WireFormat::len(&self.cov_n_e)
            + WireFormat::len(&self.cov_n_d)
            + WireFormat::len(&self.cov_e_e)
            + WireFormat::len(&self.cov_e_d)
            + WireFormat::len(&self.cov_d_d)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.lat, buf);
        WireFormat::write(&self.lon, buf);
        WireFormat::write(&self.height, buf);
        WireFormat::write(&self.cov_n_n, buf);
        WireFormat::write(&self.cov_n_e, buf);
        WireFormat::write(&self.cov_n_d, buf);
        WireFormat::write(&self.cov_e_e, buf);
        WireFormat::write(&self.cov_e_d, buf);
        WireFormat::write(&self.cov_d_d, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgPosLlhCov {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            lat: WireFormat::parse_unchecked(buf),
            lon: WireFormat::parse_unchecked(buf),
            height: WireFormat::parse_unchecked(buf),
            cov_n_n: WireFormat::parse_unchecked(buf),
            cov_n_e: WireFormat::parse_unchecked(buf),
            cov_n_d: WireFormat::parse_unchecked(buf),
            cov_e_e: WireFormat::parse_unchecked(buf),
            cov_e_d: WireFormat::parse_unchecked(buf),
            cov_d_d: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GNSS-only Geodetic Position
///
/// This position solution message reports the absolute geodetic coordinates
/// and the status (single point vs pseudo-absolute RTK) of the position
/// solution as well as the upper triangle of the 3x3 covariance matrix.  The
/// position information and Fix Mode flags should follow the MSG_POS_LLH
/// message.  Since the covariance matrix is computed in the local-level
/// North, East, Down frame, the covariance terms follow with that convention.
/// Thus, covariances are reported against the "downward" measurement and care
/// should be taken with the sign convention.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgPosLlhCovGnss {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lat")))]
    pub lat: f64,
    /// Longitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lon")))]
    pub lon: f64,
    /// Height above WGS84 ellipsoid
    #[cfg_attr(feature = "serde", serde(rename(serialize = "height")))]
    pub height: f64,
    /// Estimated variance of northing
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_n_n")))]
    pub cov_n_n: f32,
    /// Covariance of northing and easting
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_n_e")))]
    pub cov_n_e: f32,
    /// Covariance of northing and downward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_n_d")))]
    pub cov_n_d: f32,
    /// Estimated variance of easting
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_e_e")))]
    pub cov_e_e: f32,
    /// Covariance of easting and downward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_e_d")))]
    pub cov_e_d: f32,
    /// Estimated variance of downward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_d_d")))]
    pub cov_d_d: f32,
    /// Number of satellites used in solution.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgPosLlhCovGnss {
    const MESSAGE_TYPE: u16 = 561;
    const MESSAGE_NAME: &'static str = "MSG_POS_LLH_COV_GNSS";
}

impl SbpMessage for MsgPosLlhCovGnss {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgPosLlhCovGnss {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgPosLlhCovGnss(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgPosLlhCovGnss {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.lat)
            + WireFormat::len(&self.lon)
            + WireFormat::len(&self.height)
            + WireFormat::len(&self.cov_n_n)
            + WireFormat::len(&self.cov_n_e)
            + WireFormat::len(&self.cov_n_d)
            + WireFormat::len(&self.cov_e_e)
            + WireFormat::len(&self.cov_e_d)
            + WireFormat::len(&self.cov_d_d)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.lat, buf);
        WireFormat::write(&self.lon, buf);
        WireFormat::write(&self.height, buf);
        WireFormat::write(&self.cov_n_n, buf);
        WireFormat::write(&self.cov_n_e, buf);
        WireFormat::write(&self.cov_n_d, buf);
        WireFormat::write(&self.cov_e_e, buf);
        WireFormat::write(&self.cov_e_d, buf);
        WireFormat::write(&self.cov_d_d, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgPosLlhCovGnss {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            lat: WireFormat::parse_unchecked(buf),
            lon: WireFormat::parse_unchecked(buf),
            height: WireFormat::parse_unchecked(buf),
            cov_n_n: WireFormat::parse_unchecked(buf),
            cov_n_e: WireFormat::parse_unchecked(buf),
            cov_n_d: WireFormat::parse_unchecked(buf),
            cov_e_e: WireFormat::parse_unchecked(buf),
            cov_e_d: WireFormat::parse_unchecked(buf),
            cov_d_d: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Geodetic Position
///
/// This position solution message reports the absolute geodetic coordinates
/// and the status (single point vs pseudo-absolute RTK) of the position
/// solution. If the rover receiver knows the surveyed position of the base
/// station and has an RTK solution, this reports a pseudo-absolute position
/// solution using the base station position and the rover's RTK baseline
/// vector. The full GPS time is given by the preceding MSG_GPS_TIME with the
/// matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgPosLlhDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lat")))]
    pub lat: f64,
    /// Longitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lon")))]
    pub lon: f64,
    /// Height
    #[cfg_attr(feature = "serde", serde(rename(serialize = "height")))]
    pub height: f64,
    /// Horizontal position accuracy estimate (not implemented). Defaults to 0.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "h_accuracy")))]
    pub h_accuracy: u16,
    /// Vertical position accuracy estimate (not implemented). Defaults to 0.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "v_accuracy")))]
    pub v_accuracy: u16,
    /// Number of satellites used in solution.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgPosLlhDepA {
    const MESSAGE_TYPE: u16 = 513;
    const MESSAGE_NAME: &'static str = "MSG_POS_LLH_DEP_A";
}

impl SbpMessage for MsgPosLlhDepA {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgPosLlhDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgPosLlhDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgPosLlhDepA {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.lat)
            + WireFormat::len(&self.lon)
            + WireFormat::len(&self.height)
            + WireFormat::len(&self.h_accuracy)
            + WireFormat::len(&self.v_accuracy)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.lat, buf);
        WireFormat::write(&self.lon, buf);
        WireFormat::write(&self.height, buf);
        WireFormat::write(&self.h_accuracy, buf);
        WireFormat::write(&self.v_accuracy, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgPosLlhDepA {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            lat: WireFormat::parse_unchecked(buf),
            lon: WireFormat::parse_unchecked(buf),
            height: WireFormat::parse_unchecked(buf),
            h_accuracy: WireFormat::parse_unchecked(buf),
            v_accuracy: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GNSS-only Geodetic Position
///
/// This position solution message reports the absolute geodetic coordinates
/// and the status (single point vs pseudo-absolute RTK) of the position
/// solution. If the rover receiver knows the surveyed position of the base
/// station and has an RTK solution, this reports a pseudo-absolute position
/// solution using the base station position and the rover's RTK baseline
/// vector. The full GPS time is given by the preceding MSG_GPS_TIME with the
/// matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgPosLlhGnss {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lat")))]
    pub lat: f64,
    /// Longitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lon")))]
    pub lon: f64,
    /// Height above WGS84 ellipsoid
    #[cfg_attr(feature = "serde", serde(rename(serialize = "height")))]
    pub height: f64,
    /// Horizontal position estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "h_accuracy")))]
    pub h_accuracy: u16,
    /// Vertical position estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "v_accuracy")))]
    pub v_accuracy: u16,
    /// Number of satellites used in solution.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgPosLlhGnss {
    const MESSAGE_TYPE: u16 = 554;
    const MESSAGE_NAME: &'static str = "MSG_POS_LLH_GNSS";
}

impl SbpMessage for MsgPosLlhGnss {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgPosLlhGnss {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgPosLlhGnss(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgPosLlhGnss {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.lat)
            + WireFormat::len(&self.lon)
            + WireFormat::len(&self.height)
            + WireFormat::len(&self.h_accuracy)
            + WireFormat::len(&self.v_accuracy)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.lat, buf);
        WireFormat::write(&self.lon, buf);
        WireFormat::write(&self.height, buf);
        WireFormat::write(&self.h_accuracy, buf);
        WireFormat::write(&self.v_accuracy, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgPosLlhGnss {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            lat: WireFormat::parse_unchecked(buf),
            lon: WireFormat::parse_unchecked(buf),
            height: WireFormat::parse_unchecked(buf),
            h_accuracy: WireFormat::parse_unchecked(buf),
            v_accuracy: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Computed state and Protection Levels
///
/// This message reports the protection levels associated to the given state
/// estimate. The full GPS time is given by the preceding MSG_GPS_TIME with
/// the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgProtectionLevel {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// GPS week number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "wn")))]
    pub wn: i16,
    /// Horizontal protection level
    #[cfg_attr(feature = "serde", serde(rename(serialize = "hpl")))]
    pub hpl: u16,
    /// Vertical protection level
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vpl")))]
    pub vpl: u16,
    /// Along-track position error protection level
    #[cfg_attr(feature = "serde", serde(rename(serialize = "atpl")))]
    pub atpl: u16,
    /// Cross-track position error protection level
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ctpl")))]
    pub ctpl: u16,
    /// Protection level for the error vector between estimated and true
    /// along/cross track velocity vector
    #[cfg_attr(feature = "serde", serde(rename(serialize = "hvpl")))]
    pub hvpl: u16,
    /// Protection level for the velocity in vehicle upright direction
    /// (different from vertical direction if on a slope)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vvpl")))]
    pub vvpl: u16,
    /// Heading orientation protection level
    #[cfg_attr(feature = "serde", serde(rename(serialize = "hopl")))]
    pub hopl: u16,
    /// Pitch orientation protection level
    #[cfg_attr(feature = "serde", serde(rename(serialize = "popl")))]
    pub popl: u16,
    /// Roll orientation protection level
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ropl")))]
    pub ropl: u16,
    /// Latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lat")))]
    pub lat: f64,
    /// Longitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lon")))]
    pub lon: f64,
    /// Height
    #[cfg_attr(feature = "serde", serde(rename(serialize = "height")))]
    pub height: f64,
    /// Velocity in vehicle x direction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "v_x")))]
    pub v_x: i32,
    /// Velocity in vehicle y direction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "v_y")))]
    pub v_y: i32,
    /// Velocity in vehicle z direction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "v_z")))]
    pub v_z: i32,
    /// Roll angle
    #[cfg_attr(feature = "serde", serde(rename(serialize = "roll")))]
    pub roll: i32,
    /// Pitch angle
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pitch")))]
    pub pitch: i32,
    /// Heading angle
    #[cfg_attr(feature = "serde", serde(rename(serialize = "heading")))]
    pub heading: i32,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u32,
}

impl ConcreteMessage for MsgProtectionLevel {
    const MESSAGE_TYPE: u16 = 535;
    const MESSAGE_NAME: &'static str = "MSG_PROTECTION_LEVEL";
}

impl SbpMessage for MsgProtectionLevel {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        #[allow(clippy::useless_conversion)]
        let wn: i16 = match self.wn.try_into() {
            Ok(wn) => wn,
            Err(e) => return Some(Err(e.into())),
        };
        let gps_time = match time::GpsTime::new(wn, tow_s) {
            Ok(gps_time) => gps_time,
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgProtectionLevel {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgProtectionLevel(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgProtectionLevel {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.wn)
            + WireFormat::len(&self.hpl)
            + WireFormat::len(&self.vpl)
            + WireFormat::len(&self.atpl)
            + WireFormat::len(&self.ctpl)
            + WireFormat::len(&self.hvpl)
            + WireFormat::len(&self.vvpl)
            + WireFormat::len(&self.hopl)
            + WireFormat::len(&self.popl)
            + WireFormat::len(&self.ropl)
            + WireFormat::len(&self.lat)
            + WireFormat::len(&self.lon)
            + WireFormat::len(&self.height)
            + WireFormat::len(&self.v_x)
            + WireFormat::len(&self.v_y)
            + WireFormat::len(&self.v_z)
            + WireFormat::len(&self.roll)
            + WireFormat::len(&self.pitch)
            + WireFormat::len(&self.heading)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.wn, buf);
        WireFormat::write(&self.hpl, buf);
        WireFormat::write(&self.vpl, buf);
        WireFormat::write(&self.atpl, buf);
        WireFormat::write(&self.ctpl, buf);
        WireFormat::write(&self.hvpl, buf);
        WireFormat::write(&self.vvpl, buf);
        WireFormat::write(&self.hopl, buf);
        WireFormat::write(&self.popl, buf);
        WireFormat::write(&self.ropl, buf);
        WireFormat::write(&self.lat, buf);
        WireFormat::write(&self.lon, buf);
        WireFormat::write(&self.height, buf);
        WireFormat::write(&self.v_x, buf);
        WireFormat::write(&self.v_y, buf);
        WireFormat::write(&self.v_z, buf);
        WireFormat::write(&self.roll, buf);
        WireFormat::write(&self.pitch, buf);
        WireFormat::write(&self.heading, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgProtectionLevel {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            wn: WireFormat::parse_unchecked(buf),
            hpl: WireFormat::parse_unchecked(buf),
            vpl: WireFormat::parse_unchecked(buf),
            atpl: WireFormat::parse_unchecked(buf),
            ctpl: WireFormat::parse_unchecked(buf),
            hvpl: WireFormat::parse_unchecked(buf),
            vvpl: WireFormat::parse_unchecked(buf),
            hopl: WireFormat::parse_unchecked(buf),
            popl: WireFormat::parse_unchecked(buf),
            ropl: WireFormat::parse_unchecked(buf),
            lat: WireFormat::parse_unchecked(buf),
            lon: WireFormat::parse_unchecked(buf),
            height: WireFormat::parse_unchecked(buf),
            v_x: WireFormat::parse_unchecked(buf),
            v_y: WireFormat::parse_unchecked(buf),
            v_z: WireFormat::parse_unchecked(buf),
            roll: WireFormat::parse_unchecked(buf),
            pitch: WireFormat::parse_unchecked(buf),
            heading: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Computed Position and Protection Level
///
/// This message reports the local vertical and horizontal protection levels
/// associated with a given LLH position solution. The full GPS time is given
/// by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgProtectionLevelDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Vertical protection level
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vpl")))]
    pub vpl: u16,
    /// Horizontal protection level
    #[cfg_attr(feature = "serde", serde(rename(serialize = "hpl")))]
    pub hpl: u16,
    /// Latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lat")))]
    pub lat: f64,
    /// Longitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lon")))]
    pub lon: f64,
    /// Height
    #[cfg_attr(feature = "serde", serde(rename(serialize = "height")))]
    pub height: f64,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgProtectionLevelDepA {
    const MESSAGE_TYPE: u16 = 534;
    const MESSAGE_NAME: &'static str = "MSG_PROTECTION_LEVEL_DEP_A";
}

impl SbpMessage for MsgProtectionLevelDepA {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgProtectionLevelDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgProtectionLevelDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgProtectionLevelDepA {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.vpl)
            + WireFormat::len(&self.hpl)
            + WireFormat::len(&self.lat)
            + WireFormat::len(&self.lon)
            + WireFormat::len(&self.height)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.vpl, buf);
        WireFormat::write(&self.hpl, buf);
        WireFormat::write(&self.lat, buf);
        WireFormat::write(&self.lon, buf);
        WireFormat::write(&self.height, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgProtectionLevelDepA {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            vpl: WireFormat::parse_unchecked(buf),
            hpl: WireFormat::parse_unchecked(buf),
            lat: WireFormat::parse_unchecked(buf),
            lon: WireFormat::parse_unchecked(buf),
            height: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// UTC Time
///
/// This message reports the Universal Coordinated Time (UTC).  Note the flags
/// which indicate the source of the UTC offset value and source of the time
/// fix.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgUtcTime {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Indicates source and time validity
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
    /// GPS time of week rounded to the nearest millisecond
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Year
    #[cfg_attr(feature = "serde", serde(rename(serialize = "year")))]
    pub year: u16,
    /// Month (range 1 .. 12)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "month")))]
    pub month: u8,
    /// days in the month (range 1-31)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "day")))]
    pub day: u8,
    /// hours of day (range 0-23)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "hours")))]
    pub hours: u8,
    /// minutes of hour (range 0-59)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "minutes")))]
    pub minutes: u8,
    /// seconds of minute (range 0-60) rounded down
    #[cfg_attr(feature = "serde", serde(rename(serialize = "seconds")))]
    pub seconds: u8,
    /// nanoseconds of second (range 0-999999999)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ns")))]
    pub ns: u32,
}

impl ConcreteMessage for MsgUtcTime {
    const MESSAGE_TYPE: u16 = 259;
    const MESSAGE_NAME: &'static str = "MSG_UTC_TIME";
}

impl SbpMessage for MsgUtcTime {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgUtcTime {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgUtcTime(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgUtcTime {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.flags)
            + WireFormat::len(&self.tow)
            + WireFormat::len(&self.year)
            + WireFormat::len(&self.month)
            + WireFormat::len(&self.day)
            + WireFormat::len(&self.hours)
            + WireFormat::len(&self.minutes)
            + WireFormat::len(&self.seconds)
            + WireFormat::len(&self.ns)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.flags, buf);
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.year, buf);
        WireFormat::write(&self.month, buf);
        WireFormat::write(&self.day, buf);
        WireFormat::write(&self.hours, buf);
        WireFormat::write(&self.minutes, buf);
        WireFormat::write(&self.seconds, buf);
        WireFormat::write(&self.ns, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgUtcTime {
            sender_id: None,
            flags: WireFormat::parse_unchecked(buf),
            tow: WireFormat::parse_unchecked(buf),
            year: WireFormat::parse_unchecked(buf),
            month: WireFormat::parse_unchecked(buf),
            day: WireFormat::parse_unchecked(buf),
            hours: WireFormat::parse_unchecked(buf),
            minutes: WireFormat::parse_unchecked(buf),
            seconds: WireFormat::parse_unchecked(buf),
            ns: WireFormat::parse_unchecked(buf),
        }
    }
}

/// UTC Time
///
/// This message reports the Universal Coordinated Time (UTC).  Note the flags
/// which indicate the source of the UTC offset value and source of the time
/// fix.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgUtcTimeGnss {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Indicates source and time validity
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
    /// GPS time of week rounded to the nearest millisecond
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Year
    #[cfg_attr(feature = "serde", serde(rename(serialize = "year")))]
    pub year: u16,
    /// Month (range 1 .. 12)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "month")))]
    pub month: u8,
    /// days in the month (range 1-31)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "day")))]
    pub day: u8,
    /// hours of day (range 0-23)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "hours")))]
    pub hours: u8,
    /// minutes of hour (range 0-59)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "minutes")))]
    pub minutes: u8,
    /// seconds of minute (range 0-60) rounded down
    #[cfg_attr(feature = "serde", serde(rename(serialize = "seconds")))]
    pub seconds: u8,
    /// nanoseconds of second (range 0-999999999)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ns")))]
    pub ns: u32,
}

impl ConcreteMessage for MsgUtcTimeGnss {
    const MESSAGE_TYPE: u16 = 261;
    const MESSAGE_NAME: &'static str = "MSG_UTC_TIME_GNSS";
}

impl SbpMessage for MsgUtcTimeGnss {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgUtcTimeGnss {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgUtcTimeGnss(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgUtcTimeGnss {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.flags)
            + WireFormat::len(&self.tow)
            + WireFormat::len(&self.year)
            + WireFormat::len(&self.month)
            + WireFormat::len(&self.day)
            + WireFormat::len(&self.hours)
            + WireFormat::len(&self.minutes)
            + WireFormat::len(&self.seconds)
            + WireFormat::len(&self.ns)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.flags, buf);
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.year, buf);
        WireFormat::write(&self.month, buf);
        WireFormat::write(&self.day, buf);
        WireFormat::write(&self.hours, buf);
        WireFormat::write(&self.minutes, buf);
        WireFormat::write(&self.seconds, buf);
        WireFormat::write(&self.ns, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgUtcTimeGnss {
            sender_id: None,
            flags: WireFormat::parse_unchecked(buf),
            tow: WireFormat::parse_unchecked(buf),
            year: WireFormat::parse_unchecked(buf),
            month: WireFormat::parse_unchecked(buf),
            day: WireFormat::parse_unchecked(buf),
            hours: WireFormat::parse_unchecked(buf),
            minutes: WireFormat::parse_unchecked(buf),
            seconds: WireFormat::parse_unchecked(buf),
            ns: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Velocity in User Frame
///
/// This message reports the velocity in the Vehicle Body Frame. By
/// convention, the x-axis should point out the nose of the vehicle and
/// represent the forward direction, while as the y-axis should point out the
/// right hand side of the vehicle. Since this is a right handed system, z
/// should point out the bottom of the vehicle. The orientation and origin of
/// the Vehicle Body Frame are specified via the device settings. The full GPS
/// time is given by the preceding MSG_GPS_TIME with the matching time-of-week
/// (tow). This message is only produced by inertial versions of Swift
/// products and is not available from Piksi Multi or Duro.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgVelBody {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Velocity in x direction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x")))]
    pub x: i32,
    /// Velocity in y direction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y")))]
    pub y: i32,
    /// Velocity in z direction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z")))]
    pub z: i32,
    /// Estimated variance of x
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_x_x")))]
    pub cov_x_x: f32,
    /// Covariance of x and y
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_x_y")))]
    pub cov_x_y: f32,
    /// Covariance of x and z
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_x_z")))]
    pub cov_x_z: f32,
    /// Estimated variance of y
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_y_y")))]
    pub cov_y_y: f32,
    /// Covariance of y and z
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_y_z")))]
    pub cov_y_z: f32,
    /// Estimated variance of z
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_z_z")))]
    pub cov_z_z: f32,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgVelBody {
    const MESSAGE_TYPE: u16 = 531;
    const MESSAGE_NAME: &'static str = "MSG_VEL_BODY";
}

impl SbpMessage for MsgVelBody {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgVelBody {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgVelBody(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgVelBody {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.x)
            + WireFormat::len(&self.y)
            + WireFormat::len(&self.z)
            + WireFormat::len(&self.cov_x_x)
            + WireFormat::len(&self.cov_x_y)
            + WireFormat::len(&self.cov_x_z)
            + WireFormat::len(&self.cov_y_y)
            + WireFormat::len(&self.cov_y_z)
            + WireFormat::len(&self.cov_z_z)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.x, buf);
        WireFormat::write(&self.y, buf);
        WireFormat::write(&self.z, buf);
        WireFormat::write(&self.cov_x_x, buf);
        WireFormat::write(&self.cov_x_y, buf);
        WireFormat::write(&self.cov_x_z, buf);
        WireFormat::write(&self.cov_y_y, buf);
        WireFormat::write(&self.cov_y_z, buf);
        WireFormat::write(&self.cov_z_z, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgVelBody {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            x: WireFormat::parse_unchecked(buf),
            y: WireFormat::parse_unchecked(buf),
            z: WireFormat::parse_unchecked(buf),
            cov_x_x: WireFormat::parse_unchecked(buf),
            cov_x_y: WireFormat::parse_unchecked(buf),
            cov_x_z: WireFormat::parse_unchecked(buf),
            cov_y_y: WireFormat::parse_unchecked(buf),
            cov_y_z: WireFormat::parse_unchecked(buf),
            cov_z_z: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Velocity expressed as course over ground
///
/// This message reports the receiver course over ground (COG) and speed over
/// ground (SOG) based on the horizontal (N-E) components of the NED velocity
/// vector. It also includes the vertical velocity in the form of the
/// D-component of the NED velocity vector. The NED coordinate system is
/// defined as the local WGS84 tangent  plane centered at the current
/// position. The full GPS time is given by the  preceding MSG_GPS_TIME with
/// the matching time-of-week (tow). Note: course over ground represents the
/// receiver's direction of travel,  but not necessarily the device heading.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgVelCog {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Course over ground relative to local north
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cog")))]
    pub cog: u32,
    /// Speed over ground
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sog")))]
    pub sog: u32,
    /// Velocity Down coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vel_d")))]
    pub vel_d: i32,
    /// Course over ground estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cog_accuracy")))]
    pub cog_accuracy: u32,
    /// Speed over ground estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sog_accuracy")))]
    pub sog_accuracy: u32,
    /// Vertical velocity estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vel_d_accuracy")))]
    pub vel_d_accuracy: u32,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgVelCog {
    const MESSAGE_TYPE: u16 = 540;
    const MESSAGE_NAME: &'static str = "MSG_VEL_COG";
}

impl SbpMessage for MsgVelCog {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgVelCog {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgVelCog(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgVelCog {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.cog)
            + WireFormat::len(&self.sog)
            + WireFormat::len(&self.vel_d)
            + WireFormat::len(&self.cog_accuracy)
            + WireFormat::len(&self.sog_accuracy)
            + WireFormat::len(&self.vel_d_accuracy)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.cog, buf);
        WireFormat::write(&self.sog, buf);
        WireFormat::write(&self.vel_d, buf);
        WireFormat::write(&self.cog_accuracy, buf);
        WireFormat::write(&self.sog_accuracy, buf);
        WireFormat::write(&self.vel_d_accuracy, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgVelCog {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            cog: WireFormat::parse_unchecked(buf),
            sog: WireFormat::parse_unchecked(buf),
            vel_d: WireFormat::parse_unchecked(buf),
            cog_accuracy: WireFormat::parse_unchecked(buf),
            sog_accuracy: WireFormat::parse_unchecked(buf),
            vel_d_accuracy: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Velocity in ECEF
///
/// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
/// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
/// the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgVelEcef {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Velocity ECEF X coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x")))]
    pub x: i32,
    /// Velocity ECEF Y coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y")))]
    pub y: i32,
    /// Velocity ECEF Z coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z")))]
    pub z: i32,
    /// Velocity estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "accuracy")))]
    pub accuracy: u16,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgVelEcef {
    const MESSAGE_TYPE: u16 = 525;
    const MESSAGE_NAME: &'static str = "MSG_VEL_ECEF";
}

impl SbpMessage for MsgVelEcef {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgVelEcef {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgVelEcef(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgVelEcef {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.x)
            + WireFormat::len(&self.y)
            + WireFormat::len(&self.z)
            + WireFormat::len(&self.accuracy)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.x, buf);
        WireFormat::write(&self.y, buf);
        WireFormat::write(&self.z, buf);
        WireFormat::write(&self.accuracy, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgVelEcef {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            x: WireFormat::parse_unchecked(buf),
            y: WireFormat::parse_unchecked(buf),
            z: WireFormat::parse_unchecked(buf),
            accuracy: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Velocity in ECEF
///
/// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
/// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
/// the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgVelEcefCov {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Velocity ECEF X coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x")))]
    pub x: i32,
    /// Velocity ECEF Y coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y")))]
    pub y: i32,
    /// Velocity ECEF Z coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z")))]
    pub z: i32,
    /// Estimated variance of x
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_x_x")))]
    pub cov_x_x: f32,
    /// Estimated covariance of x and y
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_x_y")))]
    pub cov_x_y: f32,
    /// Estimated covariance of x and z
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_x_z")))]
    pub cov_x_z: f32,
    /// Estimated variance of y
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_y_y")))]
    pub cov_y_y: f32,
    /// Estimated covariance of y and z
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_y_z")))]
    pub cov_y_z: f32,
    /// Estimated variance of z
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_z_z")))]
    pub cov_z_z: f32,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgVelEcefCov {
    const MESSAGE_TYPE: u16 = 533;
    const MESSAGE_NAME: &'static str = "MSG_VEL_ECEF_COV";
}

impl SbpMessage for MsgVelEcefCov {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgVelEcefCov {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgVelEcefCov(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgVelEcefCov {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.x)
            + WireFormat::len(&self.y)
            + WireFormat::len(&self.z)
            + WireFormat::len(&self.cov_x_x)
            + WireFormat::len(&self.cov_x_y)
            + WireFormat::len(&self.cov_x_z)
            + WireFormat::len(&self.cov_y_y)
            + WireFormat::len(&self.cov_y_z)
            + WireFormat::len(&self.cov_z_z)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.x, buf);
        WireFormat::write(&self.y, buf);
        WireFormat::write(&self.z, buf);
        WireFormat::write(&self.cov_x_x, buf);
        WireFormat::write(&self.cov_x_y, buf);
        WireFormat::write(&self.cov_x_z, buf);
        WireFormat::write(&self.cov_y_y, buf);
        WireFormat::write(&self.cov_y_z, buf);
        WireFormat::write(&self.cov_z_z, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgVelEcefCov {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            x: WireFormat::parse_unchecked(buf),
            y: WireFormat::parse_unchecked(buf),
            z: WireFormat::parse_unchecked(buf),
            cov_x_x: WireFormat::parse_unchecked(buf),
            cov_x_y: WireFormat::parse_unchecked(buf),
            cov_x_z: WireFormat::parse_unchecked(buf),
            cov_y_y: WireFormat::parse_unchecked(buf),
            cov_y_z: WireFormat::parse_unchecked(buf),
            cov_z_z: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GNSS-only Velocity in ECEF
///
/// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
/// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
/// the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgVelEcefCovGnss {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Velocity ECEF X coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x")))]
    pub x: i32,
    /// Velocity ECEF Y coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y")))]
    pub y: i32,
    /// Velocity ECEF Z coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z")))]
    pub z: i32,
    /// Estimated variance of x
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_x_x")))]
    pub cov_x_x: f32,
    /// Estimated covariance of x and y
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_x_y")))]
    pub cov_x_y: f32,
    /// Estimated covariance of x and z
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_x_z")))]
    pub cov_x_z: f32,
    /// Estimated variance of y
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_y_y")))]
    pub cov_y_y: f32,
    /// Estimated covariance of y and z
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_y_z")))]
    pub cov_y_z: f32,
    /// Estimated variance of z
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_z_z")))]
    pub cov_z_z: f32,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgVelEcefCovGnss {
    const MESSAGE_TYPE: u16 = 565;
    const MESSAGE_NAME: &'static str = "MSG_VEL_ECEF_COV_GNSS";
}

impl SbpMessage for MsgVelEcefCovGnss {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgVelEcefCovGnss {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgVelEcefCovGnss(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgVelEcefCovGnss {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.x)
            + WireFormat::len(&self.y)
            + WireFormat::len(&self.z)
            + WireFormat::len(&self.cov_x_x)
            + WireFormat::len(&self.cov_x_y)
            + WireFormat::len(&self.cov_x_z)
            + WireFormat::len(&self.cov_y_y)
            + WireFormat::len(&self.cov_y_z)
            + WireFormat::len(&self.cov_z_z)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.x, buf);
        WireFormat::write(&self.y, buf);
        WireFormat::write(&self.z, buf);
        WireFormat::write(&self.cov_x_x, buf);
        WireFormat::write(&self.cov_x_y, buf);
        WireFormat::write(&self.cov_x_z, buf);
        WireFormat::write(&self.cov_y_y, buf);
        WireFormat::write(&self.cov_y_z, buf);
        WireFormat::write(&self.cov_z_z, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgVelEcefCovGnss {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            x: WireFormat::parse_unchecked(buf),
            y: WireFormat::parse_unchecked(buf),
            z: WireFormat::parse_unchecked(buf),
            cov_x_x: WireFormat::parse_unchecked(buf),
            cov_x_y: WireFormat::parse_unchecked(buf),
            cov_x_z: WireFormat::parse_unchecked(buf),
            cov_y_y: WireFormat::parse_unchecked(buf),
            cov_y_z: WireFormat::parse_unchecked(buf),
            cov_z_z: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Velocity in ECEF
///
/// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
/// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
/// the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgVelEcefDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Velocity ECEF X coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x")))]
    pub x: i32,
    /// Velocity ECEF Y coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y")))]
    pub y: i32,
    /// Velocity ECEF Z coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z")))]
    pub z: i32,
    /// Velocity accuracy estimate (not implemented). Defaults to 0.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "accuracy")))]
    pub accuracy: u16,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags (reserved)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgVelEcefDepA {
    const MESSAGE_TYPE: u16 = 516;
    const MESSAGE_NAME: &'static str = "MSG_VEL_ECEF_DEP_A";
}

impl SbpMessage for MsgVelEcefDepA {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgVelEcefDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgVelEcefDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgVelEcefDepA {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.x)
            + WireFormat::len(&self.y)
            + WireFormat::len(&self.z)
            + WireFormat::len(&self.accuracy)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.x, buf);
        WireFormat::write(&self.y, buf);
        WireFormat::write(&self.z, buf);
        WireFormat::write(&self.accuracy, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgVelEcefDepA {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            x: WireFormat::parse_unchecked(buf),
            y: WireFormat::parse_unchecked(buf),
            z: WireFormat::parse_unchecked(buf),
            accuracy: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GNSS-only Velocity in ECEF
///
/// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
/// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
/// the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgVelEcefGnss {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Velocity ECEF X coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x")))]
    pub x: i32,
    /// Velocity ECEF Y coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y")))]
    pub y: i32,
    /// Velocity ECEF Z coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z")))]
    pub z: i32,
    /// Velocity estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "accuracy")))]
    pub accuracy: u16,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgVelEcefGnss {
    const MESSAGE_TYPE: u16 = 557;
    const MESSAGE_NAME: &'static str = "MSG_VEL_ECEF_GNSS";
}

impl SbpMessage for MsgVelEcefGnss {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgVelEcefGnss {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgVelEcefGnss(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgVelEcefGnss {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.x)
            + WireFormat::len(&self.y)
            + WireFormat::len(&self.z)
            + WireFormat::len(&self.accuracy)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.x, buf);
        WireFormat::write(&self.y, buf);
        WireFormat::write(&self.z, buf);
        WireFormat::write(&self.accuracy, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgVelEcefGnss {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            x: WireFormat::parse_unchecked(buf),
            y: WireFormat::parse_unchecked(buf),
            z: WireFormat::parse_unchecked(buf),
            accuracy: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Velocity in NED
///
/// This message reports the velocity in local North East Down (NED)
/// coordinates. The NED coordinate system is defined as the local WGS84
/// tangent plane centered at the current position. The full GPS time is given
/// by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgVelNed {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Velocity North coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n")))]
    pub n: i32,
    /// Velocity East coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "e")))]
    pub e: i32,
    /// Velocity Down coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "d")))]
    pub d: i32,
    /// Horizontal velocity estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "h_accuracy")))]
    pub h_accuracy: u16,
    /// Vertical velocity estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "v_accuracy")))]
    pub v_accuracy: u16,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgVelNed {
    const MESSAGE_TYPE: u16 = 526;
    const MESSAGE_NAME: &'static str = "MSG_VEL_NED";
}

impl SbpMessage for MsgVelNed {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgVelNed {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgVelNed(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgVelNed {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.n)
            + WireFormat::len(&self.e)
            + WireFormat::len(&self.d)
            + WireFormat::len(&self.h_accuracy)
            + WireFormat::len(&self.v_accuracy)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.n, buf);
        WireFormat::write(&self.e, buf);
        WireFormat::write(&self.d, buf);
        WireFormat::write(&self.h_accuracy, buf);
        WireFormat::write(&self.v_accuracy, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgVelNed {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            n: WireFormat::parse_unchecked(buf),
            e: WireFormat::parse_unchecked(buf),
            d: WireFormat::parse_unchecked(buf),
            h_accuracy: WireFormat::parse_unchecked(buf),
            v_accuracy: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Velocity in NED
///
/// This message reports the velocity in local North East Down (NED)
/// coordinates. The NED coordinate system is defined as the local WGS84
/// tangent plane centered at the current position. The full GPS time is given
/// by the preceding MSG_GPS_TIME with the matching time-of-week (tow). This
/// message is similar to the MSG_VEL_NED, but it includes the upper
/// triangular portion of the 3x3 covariance matrix.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgVelNedCov {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Velocity North coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n")))]
    pub n: i32,
    /// Velocity East coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "e")))]
    pub e: i32,
    /// Velocity Down coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "d")))]
    pub d: i32,
    /// Estimated variance of northward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_n_n")))]
    pub cov_n_n: f32,
    /// Covariance of northward and eastward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_n_e")))]
    pub cov_n_e: f32,
    /// Covariance of northward and downward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_n_d")))]
    pub cov_n_d: f32,
    /// Estimated variance of eastward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_e_e")))]
    pub cov_e_e: f32,
    /// Covariance of eastward and downward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_e_d")))]
    pub cov_e_d: f32,
    /// Estimated variance of downward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_d_d")))]
    pub cov_d_d: f32,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgVelNedCov {
    const MESSAGE_TYPE: u16 = 530;
    const MESSAGE_NAME: &'static str = "MSG_VEL_NED_COV";
}

impl SbpMessage for MsgVelNedCov {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgVelNedCov {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgVelNedCov(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgVelNedCov {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.n)
            + WireFormat::len(&self.e)
            + WireFormat::len(&self.d)
            + WireFormat::len(&self.cov_n_n)
            + WireFormat::len(&self.cov_n_e)
            + WireFormat::len(&self.cov_n_d)
            + WireFormat::len(&self.cov_e_e)
            + WireFormat::len(&self.cov_e_d)
            + WireFormat::len(&self.cov_d_d)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.n, buf);
        WireFormat::write(&self.e, buf);
        WireFormat::write(&self.d, buf);
        WireFormat::write(&self.cov_n_n, buf);
        WireFormat::write(&self.cov_n_e, buf);
        WireFormat::write(&self.cov_n_d, buf);
        WireFormat::write(&self.cov_e_e, buf);
        WireFormat::write(&self.cov_e_d, buf);
        WireFormat::write(&self.cov_d_d, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgVelNedCov {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            n: WireFormat::parse_unchecked(buf),
            e: WireFormat::parse_unchecked(buf),
            d: WireFormat::parse_unchecked(buf),
            cov_n_n: WireFormat::parse_unchecked(buf),
            cov_n_e: WireFormat::parse_unchecked(buf),
            cov_n_d: WireFormat::parse_unchecked(buf),
            cov_e_e: WireFormat::parse_unchecked(buf),
            cov_e_d: WireFormat::parse_unchecked(buf),
            cov_d_d: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GNSS-only Velocity in NED
///
/// This message reports the velocity in local North East Down (NED)
/// coordinates. The NED coordinate system is defined as the local WGS84
/// tangent plane centered at the current position. The full GPS time is given
/// by the preceding MSG_GPS_TIME with the matching time-of-week (tow). This
/// message is similar to the MSG_VEL_NED, but it includes the upper
/// triangular portion of the 3x3 covariance matrix.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgVelNedCovGnss {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Velocity North coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n")))]
    pub n: i32,
    /// Velocity East coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "e")))]
    pub e: i32,
    /// Velocity Down coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "d")))]
    pub d: i32,
    /// Estimated variance of northward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_n_n")))]
    pub cov_n_n: f32,
    /// Covariance of northward and eastward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_n_e")))]
    pub cov_n_e: f32,
    /// Covariance of northward and downward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_n_d")))]
    pub cov_n_d: f32,
    /// Estimated variance of eastward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_e_e")))]
    pub cov_e_e: f32,
    /// Covariance of eastward and downward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_e_d")))]
    pub cov_e_d: f32,
    /// Estimated variance of downward measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cov_d_d")))]
    pub cov_d_d: f32,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgVelNedCovGnss {
    const MESSAGE_TYPE: u16 = 562;
    const MESSAGE_NAME: &'static str = "MSG_VEL_NED_COV_GNSS";
}

impl SbpMessage for MsgVelNedCovGnss {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgVelNedCovGnss {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgVelNedCovGnss(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgVelNedCovGnss {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.n)
            + WireFormat::len(&self.e)
            + WireFormat::len(&self.d)
            + WireFormat::len(&self.cov_n_n)
            + WireFormat::len(&self.cov_n_e)
            + WireFormat::len(&self.cov_n_d)
            + WireFormat::len(&self.cov_e_e)
            + WireFormat::len(&self.cov_e_d)
            + WireFormat::len(&self.cov_d_d)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.n, buf);
        WireFormat::write(&self.e, buf);
        WireFormat::write(&self.d, buf);
        WireFormat::write(&self.cov_n_n, buf);
        WireFormat::write(&self.cov_n_e, buf);
        WireFormat::write(&self.cov_n_d, buf);
        WireFormat::write(&self.cov_e_e, buf);
        WireFormat::write(&self.cov_e_d, buf);
        WireFormat::write(&self.cov_d_d, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgVelNedCovGnss {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            n: WireFormat::parse_unchecked(buf),
            e: WireFormat::parse_unchecked(buf),
            d: WireFormat::parse_unchecked(buf),
            cov_n_n: WireFormat::parse_unchecked(buf),
            cov_n_e: WireFormat::parse_unchecked(buf),
            cov_n_d: WireFormat::parse_unchecked(buf),
            cov_e_e: WireFormat::parse_unchecked(buf),
            cov_e_d: WireFormat::parse_unchecked(buf),
            cov_d_d: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Velocity in NED
///
/// This message reports the velocity in local North East Down (NED)
/// coordinates. The NED coordinate system is defined as the local WGS84
/// tangent plane centered at the current position. The full GPS time is given
/// by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgVelNedDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Velocity North coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n")))]
    pub n: i32,
    /// Velocity East coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "e")))]
    pub e: i32,
    /// Velocity Down coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "d")))]
    pub d: i32,
    /// Horizontal velocity accuracy estimate (not implemented). Defaults to 0.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "h_accuracy")))]
    pub h_accuracy: u16,
    /// Vertical velocity accuracy estimate (not implemented). Defaults to 0.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "v_accuracy")))]
    pub v_accuracy: u16,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags (reserved)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgVelNedDepA {
    const MESSAGE_TYPE: u16 = 517;
    const MESSAGE_NAME: &'static str = "MSG_VEL_NED_DEP_A";
}

impl SbpMessage for MsgVelNedDepA {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgVelNedDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgVelNedDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgVelNedDepA {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.n)
            + WireFormat::len(&self.e)
            + WireFormat::len(&self.d)
            + WireFormat::len(&self.h_accuracy)
            + WireFormat::len(&self.v_accuracy)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.n, buf);
        WireFormat::write(&self.e, buf);
        WireFormat::write(&self.d, buf);
        WireFormat::write(&self.h_accuracy, buf);
        WireFormat::write(&self.v_accuracy, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgVelNedDepA {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            n: WireFormat::parse_unchecked(buf),
            e: WireFormat::parse_unchecked(buf),
            d: WireFormat::parse_unchecked(buf),
            h_accuracy: WireFormat::parse_unchecked(buf),
            v_accuracy: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GNSS-only Velocity in NED
///
/// This message reports the velocity in local North East Down (NED)
/// coordinates. The NED coordinate system is defined as the local WGS84
/// tangent plane centered at the current position. The full GPS time is given
/// by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgVelNedGnss {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Velocity North coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n")))]
    pub n: i32,
    /// Velocity East coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "e")))]
    pub e: i32,
    /// Velocity Down coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "d")))]
    pub d: i32,
    /// Horizontal velocity estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "h_accuracy")))]
    pub h_accuracy: u16,
    /// Vertical velocity estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "v_accuracy")))]
    pub v_accuracy: u16,
    /// Number of satellites used in solution
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgVelNedGnss {
    const MESSAGE_TYPE: u16 = 558;
    const MESSAGE_NAME: &'static str = "MSG_VEL_NED_GNSS";
}

impl SbpMessage for MsgVelNedGnss {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgVelNedGnss {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgVelNedGnss(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgVelNedGnss {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.n)
            + WireFormat::len(&self.e)
            + WireFormat::len(&self.d)
            + WireFormat::len(&self.h_accuracy)
            + WireFormat::len(&self.v_accuracy)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.n, buf);
        WireFormat::write(&self.e, buf);
        WireFormat::write(&self.d, buf);
        WireFormat::write(&self.h_accuracy, buf);
        WireFormat::write(&self.v_accuracy, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgVelNedGnss {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            n: WireFormat::parse_unchecked(buf),
            e: WireFormat::parse_unchecked(buf),
            d: WireFormat::parse_unchecked(buf),
            h_accuracy: WireFormat::parse_unchecked(buf),
            v_accuracy: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}
