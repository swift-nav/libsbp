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

impl MsgBaselineEcef {
    pub fn fix_mode(&self) -> Option<MsgBaselineEcefFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgBaselineEcefFixMode::Invalid),
            2 => Some(MsgBaselineEcefFixMode::DifferentialGnss),
            3 => Some(MsgBaselineEcefFixMode::FloatRtk),
            4 => Some(MsgBaselineEcefFixMode::FixedRtk),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgBaselineEcefFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgBaselineEcefFixMode {
    /// Invalid
    Invalid = 0,

    /// Differential GNSS (DGNSS)
    DifferentialGnss = 2,

    /// Float RTK
    FloatRtk = 3,

    /// Fixed RTK
    FixedRtk = 4,
}

impl std::fmt::Display for MsgBaselineEcefFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgBaselineEcefFixMode::Invalid => f.write_str("Invalid"),
            MsgBaselineEcefFixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
            MsgBaselineEcefFixMode::FloatRtk => f.write_str("Float RTK"),
            MsgBaselineEcefFixMode::FixedRtk => f.write_str("Fixed RTK"),
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

impl MsgBaselineEcefDepA {
    pub fn raim_repair_flag(&self) -> Option<MsgBaselineEcefDepARaimRepairFlag> {
        match get_bit_range!(self.flags, u8, u8, 4, 0) {
            0 => Some(MsgBaselineEcefDepARaimRepairFlag::NoRepair),
            1 => Some(MsgBaselineEcefDepARaimRepairFlag::SolutionCameFromRaimRepair),
            _ => None,
        }
    }

    pub fn set_raim_repair_flag(&mut self, raim_repair_flag: MsgBaselineEcefDepARaimRepairFlag) {
        set_bit_range!(&mut self.flags, raim_repair_flag, u8, u8, 4, 0);
    }

    pub fn raim_availability_flag(&self) -> Option<MsgBaselineEcefDepARaimAvailabilityFlag> {
        match get_bit_range!( self.flags,  u8, u8, 3, 0 ) {
            0 => Some( MsgBaselineEcefDepARaimAvailabilityFlag :: RaimCheckWasExplicitlyDisabledOrUnavailable ),
            1 => Some( MsgBaselineEcefDepARaimAvailabilityFlag :: RaimCheckWasAvailable ),
            _ => None,
        }
    }

    pub fn set_raim_availability_flag(
        &mut self,
        raim_availability_flag: MsgBaselineEcefDepARaimAvailabilityFlag,
    ) {
        set_bit_range!(&mut self.flags, raim_availability_flag, u8, u8, 3, 0);
    }

    pub fn fix_mode(&self) -> Option<MsgBaselineEcefDepAFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgBaselineEcefDepAFixMode::FloatRtk),
            1 => Some(MsgBaselineEcefDepAFixMode::FixedRtk),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgBaselineEcefDepAFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// RAIM repair flag
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgBaselineEcefDepARaimRepairFlag {
    /// No repair
    NoRepair = 0,

    /// Solution came from RAIM repair
    SolutionCameFromRaimRepair = 1,
}

impl std::fmt::Display for MsgBaselineEcefDepARaimRepairFlag {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgBaselineEcefDepARaimRepairFlag::NoRepair => f.write_str("No repair"),
            MsgBaselineEcefDepARaimRepairFlag::SolutionCameFromRaimRepair => {
                f.write_str("Solution came from RAIM repair")
            }
        }
    }
}

/// RAIM availability flag
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgBaselineEcefDepARaimAvailabilityFlag {
    /// RAIM check was explicitly disabled or unavailable
    RaimCheckWasExplicitlyDisabledOrUnavailable = 0,

    /// RAIM check was available
    RaimCheckWasAvailable = 1,
}

impl std::fmt::Display for MsgBaselineEcefDepARaimAvailabilityFlag {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgBaselineEcefDepARaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable => f.write_str("RAIM check was explicitly disabled or unavailable"),
            MsgBaselineEcefDepARaimAvailabilityFlag::RaimCheckWasAvailable => f.write_str("RAIM check was available"),
        }
    }
}

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgBaselineEcefDepAFixMode {
    /// Float RTK
    FloatRtk = 0,

    /// Fixed RTK
    FixedRtk = 1,
}

impl std::fmt::Display for MsgBaselineEcefDepAFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgBaselineEcefDepAFixMode::FloatRtk => f.write_str("Float RTK"),
            MsgBaselineEcefDepAFixMode::FixedRtk => f.write_str("Fixed RTK"),
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

impl MsgBaselineHeadingDepA {
    pub fn raim_repair_flag(&self) -> Option<MsgBaselineHeadingDepARaimRepairFlag> {
        match get_bit_range!(self.flags, u8, u8, 4, 0) {
            0 => Some(MsgBaselineHeadingDepARaimRepairFlag::NoRepair),
            1 => Some(MsgBaselineHeadingDepARaimRepairFlag::SolutionCameFromRaimRepair),
            _ => None,
        }
    }

    pub fn set_raim_repair_flag(&mut self, raim_repair_flag: MsgBaselineHeadingDepARaimRepairFlag) {
        set_bit_range!(&mut self.flags, raim_repair_flag, u8, u8, 4, 0);
    }

    pub fn raim_availability_flag(&self) -> Option<MsgBaselineHeadingDepARaimAvailabilityFlag> {
        match get_bit_range!( self.flags,  u8, u8, 3, 0 ) {
            0 => Some( MsgBaselineHeadingDepARaimAvailabilityFlag :: RaimCheckWasExplicitlyDisabledOrUnavailable ),
            1 => Some( MsgBaselineHeadingDepARaimAvailabilityFlag :: RaimCheckWasAvailable ),
            _ => None,
        }
    }

    pub fn set_raim_availability_flag(
        &mut self,
        raim_availability_flag: MsgBaselineHeadingDepARaimAvailabilityFlag,
    ) {
        set_bit_range!(&mut self.flags, raim_availability_flag, u8, u8, 3, 0);
    }

    pub fn fix_mode(&self) -> Option<MsgBaselineHeadingDepAFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgBaselineHeadingDepAFixMode::FloatRtk),
            1 => Some(MsgBaselineHeadingDepAFixMode::FixedRtk),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgBaselineHeadingDepAFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// RAIM repair flag
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgBaselineHeadingDepARaimRepairFlag {
    /// No repair
    NoRepair = 0,

    /// Solution came from RAIM repair
    SolutionCameFromRaimRepair = 1,
}

impl std::fmt::Display for MsgBaselineHeadingDepARaimRepairFlag {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgBaselineHeadingDepARaimRepairFlag::NoRepair => f.write_str("No repair"),
            MsgBaselineHeadingDepARaimRepairFlag::SolutionCameFromRaimRepair => {
                f.write_str("Solution came from RAIM repair")
            }
        }
    }
}

/// RAIM availability flag
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgBaselineHeadingDepARaimAvailabilityFlag {
    /// RAIM check was explicitly disabled or unavailable
    RaimCheckWasExplicitlyDisabledOrUnavailable = 0,

    /// RAIM check was available
    RaimCheckWasAvailable = 1,
}

impl std::fmt::Display for MsgBaselineHeadingDepARaimAvailabilityFlag {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgBaselineHeadingDepARaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable => f.write_str("RAIM check was explicitly disabled or unavailable"),
            MsgBaselineHeadingDepARaimAvailabilityFlag::RaimCheckWasAvailable => f.write_str("RAIM check was available"),
        }
    }
}

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgBaselineHeadingDepAFixMode {
    /// Float RTK
    FloatRtk = 0,

    /// Fixed RTK
    FixedRtk = 1,
}

impl std::fmt::Display for MsgBaselineHeadingDepAFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgBaselineHeadingDepAFixMode::FloatRtk => f.write_str("Float RTK"),
            MsgBaselineHeadingDepAFixMode::FixedRtk => f.write_str("Fixed RTK"),
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

impl MsgBaselineNed {
    pub fn fix_mode(&self) -> Option<MsgBaselineNedFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgBaselineNedFixMode::Invalid),
            2 => Some(MsgBaselineNedFixMode::DifferentialGnss),
            3 => Some(MsgBaselineNedFixMode::FloatRtk),
            4 => Some(MsgBaselineNedFixMode::FixedRtk),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgBaselineNedFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgBaselineNedFixMode {
    /// Invalid
    Invalid = 0,

    /// Differential GNSS (DGNSS)
    DifferentialGnss = 2,

    /// Float RTK
    FloatRtk = 3,

    /// Fixed RTK
    FixedRtk = 4,
}

impl std::fmt::Display for MsgBaselineNedFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgBaselineNedFixMode::Invalid => f.write_str("Invalid"),
            MsgBaselineNedFixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
            MsgBaselineNedFixMode::FloatRtk => f.write_str("Float RTK"),
            MsgBaselineNedFixMode::FixedRtk => f.write_str("Fixed RTK"),
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

impl MsgBaselineNedDepA {
    pub fn raim_repair_flag(&self) -> Option<MsgBaselineNedDepARaimRepairFlag> {
        match get_bit_range!(self.flags, u8, u8, 4, 0) {
            0 => Some(MsgBaselineNedDepARaimRepairFlag::NoRepair),
            1 => Some(MsgBaselineNedDepARaimRepairFlag::SolutionCameFromRaimRepair),
            _ => None,
        }
    }

    pub fn set_raim_repair_flag(&mut self, raim_repair_flag: MsgBaselineNedDepARaimRepairFlag) {
        set_bit_range!(&mut self.flags, raim_repair_flag, u8, u8, 4, 0);
    }

    pub fn raim_availability_flag(&self) -> Option<MsgBaselineNedDepARaimAvailabilityFlag> {
        match get_bit_range!(self.flags, u8, u8, 3, 0) {
            0 => Some(
                MsgBaselineNedDepARaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable,
            ),
            1 => Some(MsgBaselineNedDepARaimAvailabilityFlag::RaimCheckWasAvailable),
            _ => None,
        }
    }

    pub fn set_raim_availability_flag(
        &mut self,
        raim_availability_flag: MsgBaselineNedDepARaimAvailabilityFlag,
    ) {
        set_bit_range!(&mut self.flags, raim_availability_flag, u8, u8, 3, 0);
    }

    pub fn fix_mode(&self) -> Option<MsgBaselineNedDepAFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgBaselineNedDepAFixMode::FloatRtk),
            1 => Some(MsgBaselineNedDepAFixMode::FixedRtk),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgBaselineNedDepAFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// RAIM repair flag
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgBaselineNedDepARaimRepairFlag {
    /// No repair
    NoRepair = 0,

    /// Solution came from RAIM repair
    SolutionCameFromRaimRepair = 1,
}

impl std::fmt::Display for MsgBaselineNedDepARaimRepairFlag {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgBaselineNedDepARaimRepairFlag::NoRepair => f.write_str("No repair"),
            MsgBaselineNedDepARaimRepairFlag::SolutionCameFromRaimRepair => {
                f.write_str("Solution came from RAIM repair")
            }
        }
    }
}

/// RAIM availability flag
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgBaselineNedDepARaimAvailabilityFlag {
    /// RAIM check was explicitly disabled or unavailable
    RaimCheckWasExplicitlyDisabledOrUnavailable = 0,

    /// RAIM check was available
    RaimCheckWasAvailable = 1,
}

impl std::fmt::Display for MsgBaselineNedDepARaimAvailabilityFlag {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgBaselineNedDepARaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable => {
                f.write_str("RAIM check was explicitly disabled or unavailable")
            }
            MsgBaselineNedDepARaimAvailabilityFlag::RaimCheckWasAvailable => {
                f.write_str("RAIM check was available")
            }
        }
    }
}

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgBaselineNedDepAFixMode {
    /// Float RTK
    FloatRtk = 0,

    /// Fixed RTK
    FixedRtk = 1,
}

impl std::fmt::Display for MsgBaselineNedDepAFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgBaselineNedDepAFixMode::FloatRtk => f.write_str("Float RTK"),
            MsgBaselineNedDepAFixMode::FixedRtk => f.write_str("Fixed RTK"),
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

impl MsgDops {
    pub fn raim_repair_flag(&self) -> u8 {
        get_bit_range!(self.flags, u8, u8, 7, 0)
    }

    pub fn set_raim_repair_flag(&mut self, raim_repair_flag: u8) {
        set_bit_range!(&mut self.flags, raim_repair_flag, u8, u8, 7, 0);
    }

    pub fn fix_mode(&self) -> Option<MsgDopsFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgDopsFixMode::Invalid),
            1 => Some(MsgDopsFixMode::SinglePointPosition),
            2 => Some(MsgDopsFixMode::DifferentialGnss),
            3 => Some(MsgDopsFixMode::FloatRtk),
            4 => Some(MsgDopsFixMode::FixedRtk),
            5 => Some(MsgDopsFixMode::Undefined),
            6 => Some(MsgDopsFixMode::SbasPosition),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgDopsFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgDopsFixMode {
    /// Invalid
    Invalid = 0,

    /// Single Point Position (SPP)
    SinglePointPosition = 1,

    /// Differential GNSS (DGNSS)
    DifferentialGnss = 2,

    /// Float RTK
    FloatRtk = 3,

    /// Fixed RTK
    FixedRtk = 4,

    /// Undefined
    Undefined = 5,

    /// SBAS Position
    SbasPosition = 6,
}

impl std::fmt::Display for MsgDopsFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgDopsFixMode::Invalid => f.write_str("Invalid"),
            MsgDopsFixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
            MsgDopsFixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
            MsgDopsFixMode::FloatRtk => f.write_str("Float RTK"),
            MsgDopsFixMode::FixedRtk => f.write_str("Fixed RTK"),
            MsgDopsFixMode::Undefined => f.write_str("Undefined"),
            MsgDopsFixMode::SbasPosition => f.write_str("SBAS Position"),
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

impl MsgGpsTime {
    pub fn time_source(&self) -> Option<MsgGpsTimeTimeSource> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgGpsTimeTimeSource::None),
            1 => Some(MsgGpsTimeTimeSource::GnssSolution),
            2 => Some(MsgGpsTimeTimeSource::Propagated),
            _ => None,
        }
    }

    pub fn set_time_source(&mut self, time_source: MsgGpsTimeTimeSource) {
        set_bit_range!(&mut self.flags, time_source, u8, u8, 2, 0);
    }
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

/// Time source
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgGpsTimeTimeSource {
    /// None (invalid)
    None = 0,

    /// GNSS Solution
    GnssSolution = 1,

    /// Propagated
    Propagated = 2,
}

impl std::fmt::Display for MsgGpsTimeTimeSource {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgGpsTimeTimeSource::None => f.write_str("None (invalid)"),
            MsgGpsTimeTimeSource::GnssSolution => f.write_str("GNSS Solution"),
            MsgGpsTimeTimeSource::Propagated => f.write_str("Propagated"),
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

impl MsgGpsTimeGnss {
    pub fn time_source(&self) -> Option<MsgGpsTimeGnssTimeSource> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgGpsTimeGnssTimeSource::None),
            1 => Some(MsgGpsTimeGnssTimeSource::GnssSolution),
            2 => Some(MsgGpsTimeGnssTimeSource::Propagated),
            _ => None,
        }
    }

    pub fn set_time_source(&mut self, time_source: MsgGpsTimeGnssTimeSource) {
        set_bit_range!(&mut self.flags, time_source, u8, u8, 2, 0);
    }
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

/// Time source
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgGpsTimeGnssTimeSource {
    /// None (invalid)
    None = 0,

    /// GNSS Solution
    GnssSolution = 1,

    /// Propagated
    Propagated = 2,
}

impl std::fmt::Display for MsgGpsTimeGnssTimeSource {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgGpsTimeGnssTimeSource::None => f.write_str("None (invalid)"),
            MsgGpsTimeGnssTimeSource::GnssSolution => f.write_str("GNSS Solution"),
            MsgGpsTimeGnssTimeSource::Propagated => f.write_str("Propagated"),
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

impl MsgPosEcef {
    pub fn tow_type(&self) -> Option<MsgPosEcefTowType> {
        match get_bit_range!(self.flags, u8, u8, 5, 5) {
            0 => Some(MsgPosEcefTowType::TimeOfMeasurement),
            1 => Some(MsgPosEcefTowType::Other),
            _ => None,
        }
    }

    pub fn set_tow_type(&mut self, tow_type: MsgPosEcefTowType) {
        set_bit_range!(&mut self.flags, tow_type, u8, u8, 5, 5);
    }

    pub fn inertial_navigation_mode(&self) -> Option<MsgPosEcefInertialNavigationMode> {
        match get_bit_range!(self.flags, u8, u8, 4, 3) {
            0 => Some(MsgPosEcefInertialNavigationMode::None),
            1 => Some(MsgPosEcefInertialNavigationMode::InsUsed),
            _ => None,
        }
    }

    pub fn set_inertial_navigation_mode(
        &mut self,
        inertial_navigation_mode: MsgPosEcefInertialNavigationMode,
    ) {
        set_bit_range!(&mut self.flags, inertial_navigation_mode, u8, u8, 4, 3);
    }

    pub fn fix_mode(&self) -> Option<MsgPosEcefFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgPosEcefFixMode::Invalid),
            1 => Some(MsgPosEcefFixMode::SinglePointPosition),
            2 => Some(MsgPosEcefFixMode::DifferentialGnss),
            3 => Some(MsgPosEcefFixMode::FloatRtk),
            4 => Some(MsgPosEcefFixMode::FixedRtk),
            5 => Some(MsgPosEcefFixMode::DeadReckoning),
            6 => Some(MsgPosEcefFixMode::SbasPosition),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgPosEcefFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// TOW type
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosEcefTowType {
    /// Time of Measurement
    TimeOfMeasurement = 0,

    /// Other
    Other = 1,
}

impl std::fmt::Display for MsgPosEcefTowType {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosEcefTowType::TimeOfMeasurement => f.write_str("Time of Measurement"),
            MsgPosEcefTowType::Other => f.write_str("Other"),
        }
    }
}

/// Inertial Navigation Mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosEcefInertialNavigationMode {
    /// None
    None = 0,

    /// INS used
    InsUsed = 1,
}

impl std::fmt::Display for MsgPosEcefInertialNavigationMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosEcefInertialNavigationMode::None => f.write_str("None"),
            MsgPosEcefInertialNavigationMode::InsUsed => f.write_str("INS used"),
        }
    }
}

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosEcefFixMode {
    /// Invalid
    Invalid = 0,

    /// Single Point Position (SPP)
    SinglePointPosition = 1,

    /// Differential GNSS (DGNSS)
    DifferentialGnss = 2,

    /// Float RTK
    FloatRtk = 3,

    /// Fixed RTK
    FixedRtk = 4,

    /// Dead Reckoning
    DeadReckoning = 5,

    /// SBAS Position
    SbasPosition = 6,
}

impl std::fmt::Display for MsgPosEcefFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosEcefFixMode::Invalid => f.write_str("Invalid"),
            MsgPosEcefFixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
            MsgPosEcefFixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
            MsgPosEcefFixMode::FloatRtk => f.write_str("Float RTK"),
            MsgPosEcefFixMode::FixedRtk => f.write_str("Fixed RTK"),
            MsgPosEcefFixMode::DeadReckoning => f.write_str("Dead Reckoning"),
            MsgPosEcefFixMode::SbasPosition => f.write_str("SBAS Position"),
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

impl MsgPosEcefCov {
    pub fn type_of_reported_tow(&self) -> Option<MsgPosEcefCovTypeOfReportedTow> {
        match get_bit_range!(self.flags, u8, u8, 5, 5) {
            0 => Some(MsgPosEcefCovTypeOfReportedTow::TimeOfMeasurement),
            1 => Some(MsgPosEcefCovTypeOfReportedTow::Other),
            _ => None,
        }
    }

    pub fn set_type_of_reported_tow(
        &mut self,
        type_of_reported_tow: MsgPosEcefCovTypeOfReportedTow,
    ) {
        set_bit_range!(&mut self.flags, type_of_reported_tow, u8, u8, 5, 5);
    }

    pub fn inertial_navigation_mode(&self) -> Option<MsgPosEcefCovInertialNavigationMode> {
        match get_bit_range!(self.flags, u8, u8, 4, 3) {
            0 => Some(MsgPosEcefCovInertialNavigationMode::None),
            1 => Some(MsgPosEcefCovInertialNavigationMode::InsUsed),
            _ => None,
        }
    }

    pub fn set_inertial_navigation_mode(
        &mut self,
        inertial_navigation_mode: MsgPosEcefCovInertialNavigationMode,
    ) {
        set_bit_range!(&mut self.flags, inertial_navigation_mode, u8, u8, 4, 3);
    }

    pub fn fix_mode(&self) -> Option<MsgPosEcefCovFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgPosEcefCovFixMode::Invalid),
            1 => Some(MsgPosEcefCovFixMode::SinglePointPosition),
            2 => Some(MsgPosEcefCovFixMode::DifferentialGnss),
            3 => Some(MsgPosEcefCovFixMode::FloatRtk),
            4 => Some(MsgPosEcefCovFixMode::FixedRtk),
            5 => Some(MsgPosEcefCovFixMode::DeadReckoning),
            6 => Some(MsgPosEcefCovFixMode::SbasPosition),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgPosEcefCovFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// Type of reported TOW
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosEcefCovTypeOfReportedTow {
    /// Time of Measurement
    TimeOfMeasurement = 0,

    /// Other
    Other = 1,
}

impl std::fmt::Display for MsgPosEcefCovTypeOfReportedTow {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosEcefCovTypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
            MsgPosEcefCovTypeOfReportedTow::Other => f.write_str("Other"),
        }
    }
}

/// Inertial Navigation Mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosEcefCovInertialNavigationMode {
    /// None
    None = 0,

    /// INS used
    InsUsed = 1,
}

impl std::fmt::Display for MsgPosEcefCovInertialNavigationMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosEcefCovInertialNavigationMode::None => f.write_str("None"),
            MsgPosEcefCovInertialNavigationMode::InsUsed => f.write_str("INS used"),
        }
    }
}

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosEcefCovFixMode {
    /// Invalid
    Invalid = 0,

    /// Single Point Position (SPP)
    SinglePointPosition = 1,

    /// Differential GNSS (DGNSS)
    DifferentialGnss = 2,

    /// Float RTK
    FloatRtk = 3,

    /// Fixed RTK
    FixedRtk = 4,

    /// Dead Reckoning
    DeadReckoning = 5,

    /// SBAS Position
    SbasPosition = 6,
}

impl std::fmt::Display for MsgPosEcefCovFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosEcefCovFixMode::Invalid => f.write_str("Invalid"),
            MsgPosEcefCovFixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
            MsgPosEcefCovFixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
            MsgPosEcefCovFixMode::FloatRtk => f.write_str("Float RTK"),
            MsgPosEcefCovFixMode::FixedRtk => f.write_str("Fixed RTK"),
            MsgPosEcefCovFixMode::DeadReckoning => f.write_str("Dead Reckoning"),
            MsgPosEcefCovFixMode::SbasPosition => f.write_str("SBAS Position"),
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

impl MsgPosEcefCovGnss {
    pub fn fix_mode(&self) -> Option<MsgPosEcefCovGnssFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgPosEcefCovGnssFixMode::Invalid),
            1 => Some(MsgPosEcefCovGnssFixMode::SinglePointPosition),
            2 => Some(MsgPosEcefCovGnssFixMode::DifferentialGnss),
            3 => Some(MsgPosEcefCovGnssFixMode::FloatRtk),
            4 => Some(MsgPosEcefCovGnssFixMode::FixedRtk),
            6 => Some(MsgPosEcefCovGnssFixMode::SbasPosition),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgPosEcefCovGnssFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosEcefCovGnssFixMode {
    /// Invalid
    Invalid = 0,

    /// Single Point Position (SPP)
    SinglePointPosition = 1,

    /// Differential GNSS (DGNSS)
    DifferentialGnss = 2,

    /// Float RTK
    FloatRtk = 3,

    /// Fixed RTK
    FixedRtk = 4,

    /// SBAS Position
    SbasPosition = 6,
}

impl std::fmt::Display for MsgPosEcefCovGnssFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosEcefCovGnssFixMode::Invalid => f.write_str("Invalid"),
            MsgPosEcefCovGnssFixMode::SinglePointPosition => {
                f.write_str("Single Point Position (SPP)")
            }
            MsgPosEcefCovGnssFixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
            MsgPosEcefCovGnssFixMode::FloatRtk => f.write_str("Float RTK"),
            MsgPosEcefCovGnssFixMode::FixedRtk => f.write_str("Fixed RTK"),
            MsgPosEcefCovGnssFixMode::SbasPosition => f.write_str("SBAS Position"),
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

impl MsgPosEcefDepA {
    pub fn raim_repair_flag(&self) -> Option<MsgPosEcefDepARaimRepairFlag> {
        match get_bit_range!(self.flags, u8, u8, 4, 0) {
            0 => Some(MsgPosEcefDepARaimRepairFlag::NoRepair),
            1 => Some(MsgPosEcefDepARaimRepairFlag::SolutionCameFromRaimRepair),
            _ => None,
        }
    }

    pub fn set_raim_repair_flag(&mut self, raim_repair_flag: MsgPosEcefDepARaimRepairFlag) {
        set_bit_range!(&mut self.flags, raim_repair_flag, u8, u8, 4, 0);
    }

    pub fn raim_availability_flag(&self) -> Option<MsgPosEcefDepARaimAvailabilityFlag> {
        match get_bit_range!(self.flags, u8, u8, 3, 0) {
            0 => Some(
                MsgPosEcefDepARaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable,
            ),
            1 => Some(MsgPosEcefDepARaimAvailabilityFlag::RaimCheckWasAvailable),
            _ => None,
        }
    }

    pub fn set_raim_availability_flag(
        &mut self,
        raim_availability_flag: MsgPosEcefDepARaimAvailabilityFlag,
    ) {
        set_bit_range!(&mut self.flags, raim_availability_flag, u8, u8, 3, 0);
    }

    pub fn fix_mode(&self) -> Option<MsgPosEcefDepAFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgPosEcefDepAFixMode::SinglePointPositioning),
            1 => Some(MsgPosEcefDepAFixMode::FixedRtk),
            2 => Some(MsgPosEcefDepAFixMode::FloatRtk),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgPosEcefDepAFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// RAIM repair flag
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosEcefDepARaimRepairFlag {
    /// No repair
    NoRepair = 0,

    /// Solution came from RAIM repair
    SolutionCameFromRaimRepair = 1,
}

impl std::fmt::Display for MsgPosEcefDepARaimRepairFlag {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosEcefDepARaimRepairFlag::NoRepair => f.write_str("No repair"),
            MsgPosEcefDepARaimRepairFlag::SolutionCameFromRaimRepair => {
                f.write_str("Solution came from RAIM repair")
            }
        }
    }
}

/// RAIM availability flag
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosEcefDepARaimAvailabilityFlag {
    /// RAIM check was explicitly disabled or unavailable
    RaimCheckWasExplicitlyDisabledOrUnavailable = 0,

    /// RAIM check was available
    RaimCheckWasAvailable = 1,
}

impl std::fmt::Display for MsgPosEcefDepARaimAvailabilityFlag {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosEcefDepARaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable => {
                f.write_str("RAIM check was explicitly disabled or unavailable")
            }
            MsgPosEcefDepARaimAvailabilityFlag::RaimCheckWasAvailable => {
                f.write_str("RAIM check was available")
            }
        }
    }
}

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosEcefDepAFixMode {
    /// Single Point Positioning (SPP)
    SinglePointPositioning = 0,

    /// Fixed RTK
    FixedRtk = 1,

    /// Float RTK
    FloatRtk = 2,
}

impl std::fmt::Display for MsgPosEcefDepAFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosEcefDepAFixMode::SinglePointPositioning => {
                f.write_str("Single Point Positioning (SPP)")
            }
            MsgPosEcefDepAFixMode::FixedRtk => f.write_str("Fixed RTK"),
            MsgPosEcefDepAFixMode::FloatRtk => f.write_str("Float RTK"),
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

impl MsgPosEcefGnss {
    pub fn fix_mode(&self) -> Option<MsgPosEcefGnssFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgPosEcefGnssFixMode::Invalid),
            1 => Some(MsgPosEcefGnssFixMode::SinglePointPosition),
            2 => Some(MsgPosEcefGnssFixMode::DifferentialGnss),
            3 => Some(MsgPosEcefGnssFixMode::FloatRtk),
            4 => Some(MsgPosEcefGnssFixMode::FixedRtk),
            6 => Some(MsgPosEcefGnssFixMode::SbasPosition),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgPosEcefGnssFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosEcefGnssFixMode {
    /// Invalid
    Invalid = 0,

    /// Single Point Position (SPP)
    SinglePointPosition = 1,

    /// Differential GNSS (DGNSS)
    DifferentialGnss = 2,

    /// Float RTK
    FloatRtk = 3,

    /// Fixed RTK
    FixedRtk = 4,

    /// SBAS Position
    SbasPosition = 6,
}

impl std::fmt::Display for MsgPosEcefGnssFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosEcefGnssFixMode::Invalid => f.write_str("Invalid"),
            MsgPosEcefGnssFixMode::SinglePointPosition => {
                f.write_str("Single Point Position (SPP)")
            }
            MsgPosEcefGnssFixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
            MsgPosEcefGnssFixMode::FloatRtk => f.write_str("Float RTK"),
            MsgPosEcefGnssFixMode::FixedRtk => f.write_str("Fixed RTK"),
            MsgPosEcefGnssFixMode::SbasPosition => f.write_str("SBAS Position"),
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

impl MsgPosLlh {
    pub fn type_of_reported_tow(&self) -> Option<MsgPosLlhTypeOfReportedTow> {
        match get_bit_range!(self.flags, u8, u8, 5, 5) {
            0 => Some(MsgPosLlhTypeOfReportedTow::TimeOfMeasurement),
            1 => Some(MsgPosLlhTypeOfReportedTow::Other),
            _ => None,
        }
    }

    pub fn set_type_of_reported_tow(&mut self, type_of_reported_tow: MsgPosLlhTypeOfReportedTow) {
        set_bit_range!(&mut self.flags, type_of_reported_tow, u8, u8, 5, 5);
    }

    pub fn inertial_navigation_mode(&self) -> Option<MsgPosLlhInertialNavigationMode> {
        match get_bit_range!(self.flags, u8, u8, 4, 3) {
            0 => Some(MsgPosLlhInertialNavigationMode::None),
            1 => Some(MsgPosLlhInertialNavigationMode::InsUsed),
            _ => None,
        }
    }

    pub fn set_inertial_navigation_mode(
        &mut self,
        inertial_navigation_mode: MsgPosLlhInertialNavigationMode,
    ) {
        set_bit_range!(&mut self.flags, inertial_navigation_mode, u8, u8, 4, 3);
    }

    pub fn fix_mode(&self) -> Option<MsgPosLlhFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgPosLlhFixMode::Invalid),
            1 => Some(MsgPosLlhFixMode::SinglePointPosition),
            2 => Some(MsgPosLlhFixMode::DifferentialGnss),
            3 => Some(MsgPosLlhFixMode::FloatRtk),
            4 => Some(MsgPosLlhFixMode::FixedRtk),
            5 => Some(MsgPosLlhFixMode::DeadReckoning),
            6 => Some(MsgPosLlhFixMode::SbasPosition),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgPosLlhFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// Type of reported TOW
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhTypeOfReportedTow {
    /// Time of Measurement
    TimeOfMeasurement = 0,

    /// Other
    Other = 1,
}

impl std::fmt::Display for MsgPosLlhTypeOfReportedTow {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhTypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
            MsgPosLlhTypeOfReportedTow::Other => f.write_str("Other"),
        }
    }
}

/// Inertial Navigation Mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhInertialNavigationMode {
    /// None
    None = 0,

    /// INS used
    InsUsed = 1,
}

impl std::fmt::Display for MsgPosLlhInertialNavigationMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhInertialNavigationMode::None => f.write_str("None"),
            MsgPosLlhInertialNavigationMode::InsUsed => f.write_str("INS used"),
        }
    }
}

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhFixMode {
    /// Invalid
    Invalid = 0,

    /// Single Point Position (SPP)
    SinglePointPosition = 1,

    /// Differential GNSS (DGNSS)
    DifferentialGnss = 2,

    /// Float RTK
    FloatRtk = 3,

    /// Fixed RTK
    FixedRtk = 4,

    /// Dead Reckoning
    DeadReckoning = 5,

    /// SBAS Position
    SbasPosition = 6,
}

impl std::fmt::Display for MsgPosLlhFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhFixMode::Invalid => f.write_str("Invalid"),
            MsgPosLlhFixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
            MsgPosLlhFixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
            MsgPosLlhFixMode::FloatRtk => f.write_str("Float RTK"),
            MsgPosLlhFixMode::FixedRtk => f.write_str("Fixed RTK"),
            MsgPosLlhFixMode::DeadReckoning => f.write_str("Dead Reckoning"),
            MsgPosLlhFixMode::SbasPosition => f.write_str("SBAS Position"),
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

impl MsgPosLlhAcc {
    pub fn geoid_model(&self) -> Option<MsgPosLlhAccGeoidModel> {
        match get_bit_range!(self.confidence_and_geoid, u8, u8, 6, 4) {
            0 => Some(MsgPosLlhAccGeoidModel::NoModel),
            1 => Some(MsgPosLlhAccGeoidModel::EGM96),
            2 => Some(MsgPosLlhAccGeoidModel::EGM2008),
            _ => None,
        }
    }

    pub fn set_geoid_model(&mut self, geoid_model: MsgPosLlhAccGeoidModel) {
        set_bit_range!(&mut self.confidence_and_geoid, geoid_model, u8, u8, 6, 4);
    }

    pub fn confidence_level(&self) -> Option<MsgPosLlhAccConfidenceLevel> {
        match get_bit_range!(self.confidence_and_geoid, u8, u8, 3, 0) {
            1 => Some(MsgPosLlhAccConfidenceLevel::_3935),
            2 => Some(MsgPosLlhAccConfidenceLevel::_6827),
            3 => Some(MsgPosLlhAccConfidenceLevel::_9545),
            _ => None,
        }
    }

    pub fn set_confidence_level(&mut self, confidence_level: MsgPosLlhAccConfidenceLevel) {
        set_bit_range!(
            &mut self.confidence_and_geoid,
            confidence_level,
            u8,
            u8,
            3,
            0
        );
    }

    pub fn type_of_reported_tow(&self) -> Option<MsgPosLlhAccTypeOfReportedTow> {
        match get_bit_range!(self.flags, u8, u8, 5, 5) {
            0 => Some(MsgPosLlhAccTypeOfReportedTow::TimeOfMeasurement),
            1 => Some(MsgPosLlhAccTypeOfReportedTow::Other),
            _ => None,
        }
    }

    pub fn set_type_of_reported_tow(
        &mut self,
        type_of_reported_tow: MsgPosLlhAccTypeOfReportedTow,
    ) {
        set_bit_range!(&mut self.flags, type_of_reported_tow, u8, u8, 5, 5);
    }

    pub fn inertial_navigation_mode(&self) -> Option<MsgPosLlhAccInertialNavigationMode> {
        match get_bit_range!(self.flags, u8, u8, 4, 3) {
            0 => Some(MsgPosLlhAccInertialNavigationMode::None),
            1 => Some(MsgPosLlhAccInertialNavigationMode::InsUsed),
            _ => None,
        }
    }

    pub fn set_inertial_navigation_mode(
        &mut self,
        inertial_navigation_mode: MsgPosLlhAccInertialNavigationMode,
    ) {
        set_bit_range!(&mut self.flags, inertial_navigation_mode, u8, u8, 4, 3);
    }

    pub fn fix_mode(&self) -> Option<MsgPosLlhAccFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgPosLlhAccFixMode::Invalid),
            1 => Some(MsgPosLlhAccFixMode::SinglePointPosition),
            2 => Some(MsgPosLlhAccFixMode::DifferentialGnss),
            3 => Some(MsgPosLlhAccFixMode::FloatRtk),
            4 => Some(MsgPosLlhAccFixMode::FixedRtk),
            5 => Some(MsgPosLlhAccFixMode::DeadReckoning),
            6 => Some(MsgPosLlhAccFixMode::SbasPosition),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgPosLlhAccFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// Geoid model
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhAccGeoidModel {
    /// No model
    NoModel = 0,

    /// EGM96
    EGM96 = 1,

    /// EGM2008
    EGM2008 = 2,
}

impl std::fmt::Display for MsgPosLlhAccGeoidModel {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhAccGeoidModel::NoModel => f.write_str("No model"),
            MsgPosLlhAccGeoidModel::EGM96 => f.write_str("EGM96"),
            MsgPosLlhAccGeoidModel::EGM2008 => f.write_str("EGM2008"),
        }
    }
}

/// Confidence level
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhAccConfidenceLevel {
    /// 39.35%
    _3935 = 1,

    /// 68.27%
    _6827 = 2,

    /// 95.45%
    _9545 = 3,
}

impl std::fmt::Display for MsgPosLlhAccConfidenceLevel {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhAccConfidenceLevel::_3935 => f.write_str("39.35%"),
            MsgPosLlhAccConfidenceLevel::_6827 => f.write_str("68.27%"),
            MsgPosLlhAccConfidenceLevel::_9545 => f.write_str("95.45%"),
        }
    }
}

/// Type of reported TOW
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhAccTypeOfReportedTow {
    /// Time of Measurement
    TimeOfMeasurement = 0,

    /// Other
    Other = 1,
}

impl std::fmt::Display for MsgPosLlhAccTypeOfReportedTow {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhAccTypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
            MsgPosLlhAccTypeOfReportedTow::Other => f.write_str("Other"),
        }
    }
}

/// Inertial Navigation Mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhAccInertialNavigationMode {
    /// None
    None = 0,

    /// INS used
    InsUsed = 1,
}

impl std::fmt::Display for MsgPosLlhAccInertialNavigationMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhAccInertialNavigationMode::None => f.write_str("None"),
            MsgPosLlhAccInertialNavigationMode::InsUsed => f.write_str("INS used"),
        }
    }
}

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhAccFixMode {
    /// Invalid
    Invalid = 0,

    /// Single Point Position (SPP)
    SinglePointPosition = 1,

    /// Differential GNSS (DGNSS)
    DifferentialGnss = 2,

    /// Float RTK
    FloatRtk = 3,

    /// Fixed RTK
    FixedRtk = 4,

    /// Dead Reckoning
    DeadReckoning = 5,

    /// SBAS Position
    SbasPosition = 6,
}

impl std::fmt::Display for MsgPosLlhAccFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhAccFixMode::Invalid => f.write_str("Invalid"),
            MsgPosLlhAccFixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
            MsgPosLlhAccFixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
            MsgPosLlhAccFixMode::FloatRtk => f.write_str("Float RTK"),
            MsgPosLlhAccFixMode::FixedRtk => f.write_str("Fixed RTK"),
            MsgPosLlhAccFixMode::DeadReckoning => f.write_str("Dead Reckoning"),
            MsgPosLlhAccFixMode::SbasPosition => f.write_str("SBAS Position"),
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

impl MsgPosLlhCov {
    pub fn type_of_reported_tow(&self) -> Option<MsgPosLlhCovTypeOfReportedTow> {
        match get_bit_range!(self.flags, u8, u8, 5, 5) {
            0 => Some(MsgPosLlhCovTypeOfReportedTow::TimeOfMeasurement),
            1 => Some(MsgPosLlhCovTypeOfReportedTow::Other),
            _ => None,
        }
    }

    pub fn set_type_of_reported_tow(
        &mut self,
        type_of_reported_tow: MsgPosLlhCovTypeOfReportedTow,
    ) {
        set_bit_range!(&mut self.flags, type_of_reported_tow, u8, u8, 5, 5);
    }

    pub fn inertial_navigation_mode(&self) -> Option<MsgPosLlhCovInertialNavigationMode> {
        match get_bit_range!(self.flags, u8, u8, 4, 3) {
            0 => Some(MsgPosLlhCovInertialNavigationMode::None),
            1 => Some(MsgPosLlhCovInertialNavigationMode::InsUsed),
            _ => None,
        }
    }

    pub fn set_inertial_navigation_mode(
        &mut self,
        inertial_navigation_mode: MsgPosLlhCovInertialNavigationMode,
    ) {
        set_bit_range!(&mut self.flags, inertial_navigation_mode, u8, u8, 4, 3);
    }

    pub fn fix_mode(&self) -> Option<MsgPosLlhCovFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgPosLlhCovFixMode::Invalid),
            1 => Some(MsgPosLlhCovFixMode::SinglePointPosition),
            2 => Some(MsgPosLlhCovFixMode::DifferentialGnss),
            3 => Some(MsgPosLlhCovFixMode::FloatRtk),
            4 => Some(MsgPosLlhCovFixMode::FixedRtk),
            5 => Some(MsgPosLlhCovFixMode::DeadReckoning),
            6 => Some(MsgPosLlhCovFixMode::SbasPosition),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgPosLlhCovFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// Type of reported TOW
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhCovTypeOfReportedTow {
    /// Time of Measurement
    TimeOfMeasurement = 0,

    /// Other
    Other = 1,
}

impl std::fmt::Display for MsgPosLlhCovTypeOfReportedTow {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhCovTypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
            MsgPosLlhCovTypeOfReportedTow::Other => f.write_str("Other"),
        }
    }
}

/// Inertial Navigation Mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhCovInertialNavigationMode {
    /// None
    None = 0,

    /// INS used
    InsUsed = 1,
}

impl std::fmt::Display for MsgPosLlhCovInertialNavigationMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhCovInertialNavigationMode::None => f.write_str("None"),
            MsgPosLlhCovInertialNavigationMode::InsUsed => f.write_str("INS used"),
        }
    }
}

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhCovFixMode {
    /// Invalid
    Invalid = 0,

    /// Single Point Position (SPP)
    SinglePointPosition = 1,

    /// Differential GNSS (DGNSS)
    DifferentialGnss = 2,

    /// Float RTK
    FloatRtk = 3,

    /// Fixed RTK
    FixedRtk = 4,

    /// Dead Reckoning
    DeadReckoning = 5,

    /// SBAS Position
    SbasPosition = 6,
}

impl std::fmt::Display for MsgPosLlhCovFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhCovFixMode::Invalid => f.write_str("Invalid"),
            MsgPosLlhCovFixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
            MsgPosLlhCovFixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
            MsgPosLlhCovFixMode::FloatRtk => f.write_str("Float RTK"),
            MsgPosLlhCovFixMode::FixedRtk => f.write_str("Fixed RTK"),
            MsgPosLlhCovFixMode::DeadReckoning => f.write_str("Dead Reckoning"),
            MsgPosLlhCovFixMode::SbasPosition => f.write_str("SBAS Position"),
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

impl MsgPosLlhCovGnss {
    pub fn fix_mode(&self) -> Option<MsgPosLlhCovGnssFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgPosLlhCovGnssFixMode::Invalid),
            1 => Some(MsgPosLlhCovGnssFixMode::SinglePointPosition),
            2 => Some(MsgPosLlhCovGnssFixMode::DifferentialGnss),
            3 => Some(MsgPosLlhCovGnssFixMode::FloatRtk),
            4 => Some(MsgPosLlhCovGnssFixMode::FixedRtk),
            5 => Some(MsgPosLlhCovGnssFixMode::DeadReckoning),
            6 => Some(MsgPosLlhCovGnssFixMode::SbasPosition),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgPosLlhCovGnssFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhCovGnssFixMode {
    /// Invalid
    Invalid = 0,

    /// Single Point Position (SPP)
    SinglePointPosition = 1,

    /// Differential GNSS (DGNSS)
    DifferentialGnss = 2,

    /// Float RTK
    FloatRtk = 3,

    /// Fixed RTK
    FixedRtk = 4,

    /// Dead Reckoning
    DeadReckoning = 5,

    /// SBAS Position
    SbasPosition = 6,
}

impl std::fmt::Display for MsgPosLlhCovGnssFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhCovGnssFixMode::Invalid => f.write_str("Invalid"),
            MsgPosLlhCovGnssFixMode::SinglePointPosition => {
                f.write_str("Single Point Position (SPP)")
            }
            MsgPosLlhCovGnssFixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
            MsgPosLlhCovGnssFixMode::FloatRtk => f.write_str("Float RTK"),
            MsgPosLlhCovGnssFixMode::FixedRtk => f.write_str("Fixed RTK"),
            MsgPosLlhCovGnssFixMode::DeadReckoning => f.write_str("Dead Reckoning"),
            MsgPosLlhCovGnssFixMode::SbasPosition => f.write_str("SBAS Position"),
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

impl MsgPosLlhDepA {
    pub fn raim_repair_flag(&self) -> Option<MsgPosLlhDepARaimRepairFlag> {
        match get_bit_range!(self.flags, u8, u8, 5, 0) {
            0 => Some(MsgPosLlhDepARaimRepairFlag::NoRepair),
            1 => Some(MsgPosLlhDepARaimRepairFlag::SolutionCameFromRaimRepair),
            _ => None,
        }
    }

    pub fn set_raim_repair_flag(&mut self, raim_repair_flag: MsgPosLlhDepARaimRepairFlag) {
        set_bit_range!(&mut self.flags, raim_repair_flag, u8, u8, 5, 0);
    }

    pub fn raim_availability_flag(&self) -> Option<MsgPosLlhDepARaimAvailabilityFlag> {
        match get_bit_range!(self.flags, u8, u8, 4, 0) {
            0 => {
                Some(MsgPosLlhDepARaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable)
            }
            1 => Some(MsgPosLlhDepARaimAvailabilityFlag::RaimCheckWasAvailable),
            _ => None,
        }
    }

    pub fn set_raim_availability_flag(
        &mut self,
        raim_availability_flag: MsgPosLlhDepARaimAvailabilityFlag,
    ) {
        set_bit_range!(&mut self.flags, raim_availability_flag, u8, u8, 4, 0);
    }

    pub fn height_mode(&self) -> Option<MsgPosLlhDepAHeightMode> {
        match get_bit_range!(self.flags, u8, u8, 3, 0) {
            0 => Some(MsgPosLlhDepAHeightMode::HeightAboveWgs84Ellipsoid),
            1 => Some(MsgPosLlhDepAHeightMode::HeightAboveMeanSeaLevel),
            _ => None,
        }
    }

    pub fn set_height_mode(&mut self, height_mode: MsgPosLlhDepAHeightMode) {
        set_bit_range!(&mut self.flags, height_mode, u8, u8, 3, 0);
    }

    pub fn fix_mode(&self) -> Option<MsgPosLlhDepAFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgPosLlhDepAFixMode::SinglePointPositioning),
            1 => Some(MsgPosLlhDepAFixMode::FixedRtk),
            2 => Some(MsgPosLlhDepAFixMode::FloatRtk),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgPosLlhDepAFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// RAIM repair flag
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhDepARaimRepairFlag {
    /// No repair
    NoRepair = 0,

    /// Solution came from RAIM repair
    SolutionCameFromRaimRepair = 1,
}

impl std::fmt::Display for MsgPosLlhDepARaimRepairFlag {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhDepARaimRepairFlag::NoRepair => f.write_str("No repair"),
            MsgPosLlhDepARaimRepairFlag::SolutionCameFromRaimRepair => {
                f.write_str("Solution came from RAIM repair")
            }
        }
    }
}

/// RAIM availability flag
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhDepARaimAvailabilityFlag {
    /// RAIM check was explicitly disabled or unavailable
    RaimCheckWasExplicitlyDisabledOrUnavailable = 0,

    /// RAIM check was available
    RaimCheckWasAvailable = 1,
}

impl std::fmt::Display for MsgPosLlhDepARaimAvailabilityFlag {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhDepARaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable => {
                f.write_str("RAIM check was explicitly disabled or unavailable")
            }
            MsgPosLlhDepARaimAvailabilityFlag::RaimCheckWasAvailable => {
                f.write_str("RAIM check was available")
            }
        }
    }
}

/// Height Mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhDepAHeightMode {
    /// Height above WGS84 ellipsoid
    HeightAboveWgs84Ellipsoid = 0,

    /// Height above mean sea level
    HeightAboveMeanSeaLevel = 1,
}

impl std::fmt::Display for MsgPosLlhDepAHeightMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhDepAHeightMode::HeightAboveWgs84Ellipsoid => {
                f.write_str("Height above WGS84 ellipsoid")
            }
            MsgPosLlhDepAHeightMode::HeightAboveMeanSeaLevel => {
                f.write_str("Height above mean sea level")
            }
        }
    }
}

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhDepAFixMode {
    /// Single Point Positioning (SPP)
    SinglePointPositioning = 0,

    /// Fixed RTK
    FixedRtk = 1,

    /// Float RTK
    FloatRtk = 2,
}

impl std::fmt::Display for MsgPosLlhDepAFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhDepAFixMode::SinglePointPositioning => {
                f.write_str("Single Point Positioning (SPP)")
            }
            MsgPosLlhDepAFixMode::FixedRtk => f.write_str("Fixed RTK"),
            MsgPosLlhDepAFixMode::FloatRtk => f.write_str("Float RTK"),
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

impl MsgPosLlhGnss {
    pub fn fix_mode(&self) -> Option<MsgPosLlhGnssFixMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgPosLlhGnssFixMode::Invalid),
            1 => Some(MsgPosLlhGnssFixMode::SinglePointPosition),
            2 => Some(MsgPosLlhGnssFixMode::DifferentialGnss),
            3 => Some(MsgPosLlhGnssFixMode::FloatRtk),
            4 => Some(MsgPosLlhGnssFixMode::FixedRtk),
            6 => Some(MsgPosLlhGnssFixMode::SbasPosition),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgPosLlhGnssFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u8, u8, 2, 0);
    }
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

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgPosLlhGnssFixMode {
    /// Invalid
    Invalid = 0,

    /// Single Point Position (SPP)
    SinglePointPosition = 1,

    /// Differential GNSS (DGNSS)
    DifferentialGnss = 2,

    /// Float RTK
    FloatRtk = 3,

    /// Fixed RTK
    FixedRtk = 4,

    /// SBAS Position
    SbasPosition = 6,
}

impl std::fmt::Display for MsgPosLlhGnssFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgPosLlhGnssFixMode::Invalid => f.write_str("Invalid"),
            MsgPosLlhGnssFixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
            MsgPosLlhGnssFixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
            MsgPosLlhGnssFixMode::FloatRtk => f.write_str("Float RTK"),
            MsgPosLlhGnssFixMode::FixedRtk => f.write_str("Fixed RTK"),
            MsgPosLlhGnssFixMode::SbasPosition => f.write_str("SBAS Position"),
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

impl MsgProtectionLevel {
    pub fn target_integrity_risk_tir_level(&self) -> u8 {
        get_bit_range!(self.flags, u32, u8, 2, 0)
    }

    pub fn set_target_integrity_risk_tir_level(&mut self, target_integrity_risk_tir_level: u8) {
        set_bit_range!(
            &mut self.flags,
            target_integrity_risk_tir_level,
            u32,
            u8,
            2,
            0
        );
    }

    pub fn fix_mode(&self) -> Option<MsgProtectionLevelFixMode> {
        match get_bit_range!(self.flags, u32, u8, 17, 15) {
            0 => Some(MsgProtectionLevelFixMode::Invalid),
            1 => Some(MsgProtectionLevelFixMode::SinglePointPosition),
            2 => Some(MsgProtectionLevelFixMode::DifferentialGnss),
            3 => Some(MsgProtectionLevelFixMode::FloatRtk),
            4 => Some(MsgProtectionLevelFixMode::FixedRtk),
            5 => Some(MsgProtectionLevelFixMode::DeadReckoning),
            6 => Some(MsgProtectionLevelFixMode::SbasPosition),
            _ => None,
        }
    }

    pub fn set_fix_mode(&mut self, fix_mode: MsgProtectionLevelFixMode) {
        set_bit_range!(&mut self.flags, fix_mode, u32, u8, 17, 15);
    }

    pub fn inertial_navigation_mode(&self) -> Option<MsgProtectionLevelInertialNavigationMode> {
        match get_bit_range!(self.flags, u32, u8, 19, 18) {
            0 => Some(MsgProtectionLevelInertialNavigationMode::None),
            1 => Some(MsgProtectionLevelInertialNavigationMode::InsUsed),
            _ => None,
        }
    }

    pub fn set_inertial_navigation_mode(
        &mut self,
        inertial_navigation_mode: MsgProtectionLevelInertialNavigationMode,
    ) {
        set_bit_range!(&mut self.flags, inertial_navigation_mode, u32, u8, 19, 18);
    }

    pub fn time_status(&self) -> Option<MsgProtectionLevelTimeStatus> {
        match get_bit_range!(self.flags, u32, u8, 20, 0) {
            0 => Some(MsgProtectionLevelTimeStatus::GnssTimeOfValidity),
            1 => Some(MsgProtectionLevelTimeStatus::Other),
            _ => None,
        }
    }

    pub fn set_time_status(&mut self, time_status: MsgProtectionLevelTimeStatus) {
        set_bit_range!(&mut self.flags, time_status, u32, u8, 20, 0);
    }

    pub fn velocity_valid(&self) -> u8 {
        get_bit_range!(self.flags, u32, u8, 21, 0)
    }

    pub fn set_velocity_valid(&mut self, velocity_valid: u8) {
        set_bit_range!(&mut self.flags, velocity_valid, u32, u8, 21, 0);
    }

    pub fn attitude_valid(&self) -> u8 {
        get_bit_range!(self.flags, u32, u8, 22, 0)
    }

    pub fn set_attitude_valid(&mut self, attitude_valid: u8) {
        set_bit_range!(&mut self.flags, attitude_valid, u32, u8, 22, 0);
    }

    pub fn safe_state_hpl(&self) -> u8 {
        get_bit_range!(self.flags, u32, u8, 23, 0)
    }

    pub fn set_safe_state_hpl(&mut self, safe_state_hpl: u8) {
        set_bit_range!(&mut self.flags, safe_state_hpl, u32, u8, 23, 0);
    }

    pub fn safe_state_vpl(&self) -> u8 {
        get_bit_range!(self.flags, u32, u8, 24, 0)
    }

    pub fn set_safe_state_vpl(&mut self, safe_state_vpl: u8) {
        set_bit_range!(&mut self.flags, safe_state_vpl, u32, u8, 24, 0);
    }

    pub fn safe_state_atpl(&self) -> u8 {
        get_bit_range!(self.flags, u32, u8, 25, 0)
    }

    pub fn set_safe_state_atpl(&mut self, safe_state_atpl: u8) {
        set_bit_range!(&mut self.flags, safe_state_atpl, u32, u8, 25, 0);
    }

    pub fn safe_state_ctpl(&self) -> u8 {
        get_bit_range!(self.flags, u32, u8, 26, 0)
    }

    pub fn set_safe_state_ctpl(&mut self, safe_state_ctpl: u8) {
        set_bit_range!(&mut self.flags, safe_state_ctpl, u32, u8, 26, 0);
    }

    pub fn safe_state_hvpl(&self) -> u8 {
        get_bit_range!(self.flags, u32, u8, 27, 0)
    }

    pub fn set_safe_state_hvpl(&mut self, safe_state_hvpl: u8) {
        set_bit_range!(&mut self.flags, safe_state_hvpl, u32, u8, 27, 0);
    }

    pub fn safe_state_vvpl(&self) -> u8 {
        get_bit_range!(self.flags, u32, u8, 28, 0)
    }

    pub fn set_safe_state_vvpl(&mut self, safe_state_vvpl: u8) {
        set_bit_range!(&mut self.flags, safe_state_vvpl, u32, u8, 28, 0);
    }

    pub fn safe_state_hopl(&self) -> u8 {
        get_bit_range!(self.flags, u32, u8, 29, 0)
    }

    pub fn set_safe_state_hopl(&mut self, safe_state_hopl: u8) {
        set_bit_range!(&mut self.flags, safe_state_hopl, u32, u8, 29, 0);
    }

    pub fn safe_state_popl(&self) -> u8 {
        get_bit_range!(self.flags, u32, u8, 30, 0)
    }

    pub fn set_safe_state_popl(&mut self, safe_state_popl: u8) {
        set_bit_range!(&mut self.flags, safe_state_popl, u32, u8, 30, 0);
    }

    pub fn safe_state_ropl(&self) -> u8 {
        get_bit_range!(self.flags, u32, u8, 31, 0)
    }

    pub fn set_safe_state_ropl(&mut self, safe_state_ropl: u8) {
        set_bit_range!(&mut self.flags, safe_state_ropl, u32, u8, 31, 0);
    }
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

/// Fix mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgProtectionLevelFixMode {
    /// Invalid
    Invalid = 0,

    /// Single Point Position (SPP)
    SinglePointPosition = 1,

    /// Differential GNSS (DGNSS)
    DifferentialGnss = 2,

    /// Float RTK
    FloatRtk = 3,

    /// Fixed RTK
    FixedRtk = 4,

    /// Dead Reckoning
    DeadReckoning = 5,

    /// SBAS Position
    SbasPosition = 6,
}

impl std::fmt::Display for MsgProtectionLevelFixMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgProtectionLevelFixMode::Invalid => f.write_str("Invalid"),
            MsgProtectionLevelFixMode::SinglePointPosition => {
                f.write_str("Single Point Position (SPP)")
            }
            MsgProtectionLevelFixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
            MsgProtectionLevelFixMode::FloatRtk => f.write_str("Float RTK"),
            MsgProtectionLevelFixMode::FixedRtk => f.write_str("Fixed RTK"),
            MsgProtectionLevelFixMode::DeadReckoning => f.write_str("Dead Reckoning"),
            MsgProtectionLevelFixMode::SbasPosition => f.write_str("SBAS Position"),
        }
    }
}

/// Inertial Navigation Mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgProtectionLevelInertialNavigationMode {
    /// None
    None = 0,

    /// INS used
    InsUsed = 1,
}

impl std::fmt::Display for MsgProtectionLevelInertialNavigationMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgProtectionLevelInertialNavigationMode::None => f.write_str("None"),
            MsgProtectionLevelInertialNavigationMode::InsUsed => f.write_str("INS used"),
        }
    }
}

/// Time status
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgProtectionLevelTimeStatus {
    /// GNSS time of validity
    GnssTimeOfValidity = 0,

    /// Other
    Other = 1,
}

impl std::fmt::Display for MsgProtectionLevelTimeStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgProtectionLevelTimeStatus::GnssTimeOfValidity => {
                f.write_str("GNSS time of validity")
            }
            MsgProtectionLevelTimeStatus::Other => f.write_str("Other"),
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

impl MsgProtectionLevelDepA {
    pub fn target_integrity_risk_tir_level(
        &self,
    ) -> Option<MsgProtectionLevelDepATargetIntegrityRiskTirLevel> {
        match get_bit_range!( self.flags,  u8, u8, 2, 0 ) {
            0 => Some( MsgProtectionLevelDepATargetIntegrityRiskTirLevel :: SafeStateProtectionLevelShallNotBeUsedForSafetyCriticalApplication ),
            1 => Some( MsgProtectionLevelDepATargetIntegrityRiskTirLevel :: TirLevel1 ),
            2 => Some( MsgProtectionLevelDepATargetIntegrityRiskTirLevel :: TirLevel2 ),
            3 => Some( MsgProtectionLevelDepATargetIntegrityRiskTirLevel :: TirLevel3 ),
            _ => None,
        }
    }

    pub fn set_target_integrity_risk_tir_level(
        &mut self,
        target_integrity_risk_tir_level: MsgProtectionLevelDepATargetIntegrityRiskTirLevel,
    ) {
        set_bit_range!(
            &mut self.flags,
            target_integrity_risk_tir_level,
            u8,
            u8,
            2,
            0
        );
    }
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

/// Target Integrity Risk (TIR) Level
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgProtectionLevelDepATargetIntegrityRiskTirLevel {
    /// Safe state, protection level shall not be used for safety-critical
    /// application
    SafeStateProtectionLevelShallNotBeUsedForSafetyCriticalApplication = 0,

    /// TIR Level 1
    TirLevel1 = 1,

    /// TIR Level 2
    TirLevel2 = 2,

    /// TIR Level 3
    TirLevel3 = 3,
}

impl std::fmt::Display for MsgProtectionLevelDepATargetIntegrityRiskTirLevel {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgProtectionLevelDepATargetIntegrityRiskTirLevel::SafeStateProtectionLevelShallNotBeUsedForSafetyCriticalApplication => f.write_str("Safe state, protection level shall not be used for safety-critical application"),
            MsgProtectionLevelDepATargetIntegrityRiskTirLevel::TirLevel1 => f.write_str("TIR Level 1"),
            MsgProtectionLevelDepATargetIntegrityRiskTirLevel::TirLevel2 => f.write_str("TIR Level 2"),
            MsgProtectionLevelDepATargetIntegrityRiskTirLevel::TirLevel3 => f.write_str("TIR Level 3"),
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

impl MsgUtcTime {
    pub fn utc_offset_source(&self) -> Option<MsgUtcTimeUtcOffsetSource> {
        match get_bit_range!(self.flags, u8, u8, 4, 3) {
            0 => Some(MsgUtcTimeUtcOffsetSource::FactoryDefault),
            1 => Some(MsgUtcTimeUtcOffsetSource::NonVolatileMemory),
            2 => Some(MsgUtcTimeUtcOffsetSource::DecodedThisSession),
            _ => None,
        }
    }

    pub fn set_utc_offset_source(&mut self, utc_offset_source: MsgUtcTimeUtcOffsetSource) {
        set_bit_range!(&mut self.flags, utc_offset_source, u8, u8, 4, 3);
    }

    pub fn time_source(&self) -> Option<MsgUtcTimeTimeSource> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgUtcTimeTimeSource::None),
            1 => Some(MsgUtcTimeTimeSource::GnssSolution),
            2 => Some(MsgUtcTimeTimeSource::Propagated),
            _ => None,
        }
    }

    pub fn set_time_source(&mut self, time_source: MsgUtcTimeTimeSource) {
        set_bit_range!(&mut self.flags, time_source, u8, u8, 2, 0);
    }
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

/// UTC offset source
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgUtcTimeUtcOffsetSource {
    /// Factory Default
    FactoryDefault = 0,

    /// Non Volatile Memory
    NonVolatileMemory = 1,

    /// Decoded this Session
    DecodedThisSession = 2,
}

impl std::fmt::Display for MsgUtcTimeUtcOffsetSource {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgUtcTimeUtcOffsetSource::FactoryDefault => f.write_str("Factory Default"),
            MsgUtcTimeUtcOffsetSource::NonVolatileMemory => f.write_str("Non Volatile Memory"),
            MsgUtcTimeUtcOffsetSource::DecodedThisSession => f.write_str("Decoded this Session"),
        }
    }
}

/// Time source
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgUtcTimeTimeSource {
    /// None (invalid)
    None = 0,

    /// GNSS Solution
    GnssSolution = 1,

    /// Propagated
    Propagated = 2,
}

impl std::fmt::Display for MsgUtcTimeTimeSource {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgUtcTimeTimeSource::None => f.write_str("None (invalid)"),
            MsgUtcTimeTimeSource::GnssSolution => f.write_str("GNSS Solution"),
            MsgUtcTimeTimeSource::Propagated => f.write_str("Propagated"),
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

impl MsgUtcTimeGnss {
    pub fn utc_offset_source(&self) -> Option<MsgUtcTimeGnssUtcOffsetSource> {
        match get_bit_range!(self.flags, u8, u8, 4, 3) {
            0 => Some(MsgUtcTimeGnssUtcOffsetSource::FactoryDefault),
            1 => Some(MsgUtcTimeGnssUtcOffsetSource::NonVolatileMemory),
            2 => Some(MsgUtcTimeGnssUtcOffsetSource::DecodedThisSession),
            _ => None,
        }
    }

    pub fn set_utc_offset_source(&mut self, utc_offset_source: MsgUtcTimeGnssUtcOffsetSource) {
        set_bit_range!(&mut self.flags, utc_offset_source, u8, u8, 4, 3);
    }

    pub fn time_source(&self) -> Option<MsgUtcTimeGnssTimeSource> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgUtcTimeGnssTimeSource::None),
            1 => Some(MsgUtcTimeGnssTimeSource::GnssSolution),
            2 => Some(MsgUtcTimeGnssTimeSource::Propagated),
            _ => None,
        }
    }

    pub fn set_time_source(&mut self, time_source: MsgUtcTimeGnssTimeSource) {
        set_bit_range!(&mut self.flags, time_source, u8, u8, 2, 0);
    }
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

/// UTC offset source
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgUtcTimeGnssUtcOffsetSource {
    /// Factory Default
    FactoryDefault = 0,

    /// Non Volatile Memory
    NonVolatileMemory = 1,

    /// Decoded this Session
    DecodedThisSession = 2,
}

impl std::fmt::Display for MsgUtcTimeGnssUtcOffsetSource {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgUtcTimeGnssUtcOffsetSource::FactoryDefault => f.write_str("Factory Default"),
            MsgUtcTimeGnssUtcOffsetSource::NonVolatileMemory => f.write_str("Non Volatile Memory"),
            MsgUtcTimeGnssUtcOffsetSource::DecodedThisSession => {
                f.write_str("Decoded this Session")
            }
        }
    }
}

/// Time source
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgUtcTimeGnssTimeSource {
    /// None (invalid)
    None = 0,

    /// GNSS Solution
    GnssSolution = 1,

    /// Propagated
    Propagated = 2,
}

impl std::fmt::Display for MsgUtcTimeGnssTimeSource {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgUtcTimeGnssTimeSource::None => f.write_str("None (invalid)"),
            MsgUtcTimeGnssTimeSource::GnssSolution => f.write_str("GNSS Solution"),
            MsgUtcTimeGnssTimeSource::Propagated => f.write_str("Propagated"),
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

impl MsgVelBody {
    pub fn ins_navigation_mode(&self) -> Option<MsgVelBodyInsNavigationMode> {
        match get_bit_range!(self.flags, u8, u8, 4, 3) {
            0 => Some(MsgVelBodyInsNavigationMode::None),
            1 => Some(MsgVelBodyInsNavigationMode::InsUsed),
            _ => None,
        }
    }

    pub fn set_ins_navigation_mode(&mut self, ins_navigation_mode: MsgVelBodyInsNavigationMode) {
        set_bit_range!(&mut self.flags, ins_navigation_mode, u8, u8, 4, 3);
    }

    pub fn velocity_mode(&self) -> Option<MsgVelBodyVelocityMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgVelBodyVelocityMode::Invalid),
            1 => Some(MsgVelBodyVelocityMode::MeasuredDopplerDerived),
            2 => Some(MsgVelBodyVelocityMode::ComputedDopplerDerived),
            3 => Some(MsgVelBodyVelocityMode::DeadReckoning),
            _ => None,
        }
    }

    pub fn set_velocity_mode(&mut self, velocity_mode: MsgVelBodyVelocityMode) {
        set_bit_range!(&mut self.flags, velocity_mode, u8, u8, 2, 0);
    }
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

/// INS Navigation Mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelBodyInsNavigationMode {
    /// None
    None = 0,

    /// INS used
    InsUsed = 1,
}

impl std::fmt::Display for MsgVelBodyInsNavigationMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelBodyInsNavigationMode::None => f.write_str("None"),
            MsgVelBodyInsNavigationMode::InsUsed => f.write_str("INS used"),
        }
    }
}

/// Velocity mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelBodyVelocityMode {
    /// Invalid
    Invalid = 0,

    /// Measured Doppler derived
    MeasuredDopplerDerived = 1,

    /// Computed Doppler derived
    ComputedDopplerDerived = 2,

    /// Dead Reckoning
    DeadReckoning = 3,
}

impl std::fmt::Display for MsgVelBodyVelocityMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelBodyVelocityMode::Invalid => f.write_str("Invalid"),
            MsgVelBodyVelocityMode::MeasuredDopplerDerived => {
                f.write_str("Measured Doppler derived")
            }
            MsgVelBodyVelocityMode::ComputedDopplerDerived => {
                f.write_str("Computed Doppler derived")
            }
            MsgVelBodyVelocityMode::DeadReckoning => f.write_str("Dead Reckoning"),
        }
    }
}

/// Velocity expressed as course over ground
///
/// This message reports the receiver course over ground (COG) and speed over
/// ground (SOG) based on the horizontal (N-E) components of the NED velocity
/// vector. It also includes the vertical velocity coordinate. A flag is
/// provided to indicate whether the COG value has been frozen. When  the flag
/// is set to true, the COG field is set to its last valid value until  the
/// system exceeds a minimum velocity threshold. No other fields are  affected
/// by this flag.  The NED coordinate system is defined as the local WGS84
/// tangent  plane centered at the current position. The full GPS time is
/// given by the  preceding MSG_GPS_TIME with the matching time-of-week (tow).
/// Note: course over ground represents the receiver's direction of travel,
/// but not necessarily the device heading.
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
    /// Course over ground relative to north direction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cog")))]
    pub cog: u32,
    /// Speed over ground (based on horizontal velocity)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sog")))]
    pub sog: u32,
    /// Vertical velocity component (positive up)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "v_up")))]
    pub v_up: i32,
    /// Course over ground estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cog_accuracy")))]
    pub cog_accuracy: u32,
    /// Speed over ground estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sog_accuracy")))]
    pub sog_accuracy: u32,
    /// Vertical velocity estimated standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "v_up_accuracy")))]
    pub v_up_accuracy: u32,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u16,
}

impl MsgVelCog {
    pub fn vertical_velocity_validity(&self) -> Option<MsgVelCogVerticalVelocityValidity> {
        match get_bit_range!(self.flags, u8, u8, 5, 0) {
            0 => Some(MsgVelCogVerticalVelocityValidity::Invalid),
            1 => Some(MsgVelCogVerticalVelocityValidity::VerticalVelocityValid),
            _ => None,
        }
    }

    pub fn set_vertical_velocity_validity(
        &mut self,
        vertical_velocity_validity: MsgVelCogVerticalVelocityValidity,
    ) {
        set_bit_range!(&mut self.flags, vertical_velocity_validity, u8, u8, 5, 0);
    }

    pub fn sog_validity(&self) -> Option<MsgVelCogSogValidity> {
        match get_bit_range!(self.flags, u8, u8, 4, 0) {
            0 => Some(MsgVelCogSogValidity::Invalid),
            1 => Some(MsgVelCogSogValidity::SogValid),
            _ => None,
        }
    }

    pub fn set_sog_validity(&mut self, sog_validity: MsgVelCogSogValidity) {
        set_bit_range!(&mut self.flags, sog_validity, u8, u8, 4, 0);
    }

    pub fn cog_validity(&self) -> Option<MsgVelCogCogValidity> {
        match get_bit_range!(self.flags, u8, u8, 3, 0) {
            0 => Some(MsgVelCogCogValidity::Invalid),
            1 => Some(MsgVelCogCogValidity::CogValid),
            _ => None,
        }
    }

    pub fn set_cog_validity(&mut self, cog_validity: MsgVelCogCogValidity) {
        set_bit_range!(&mut self.flags, cog_validity, u8, u8, 3, 0);
    }

    pub fn ins_navigation_mode(&self) -> Option<MsgVelCogInsNavigationMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgVelCogInsNavigationMode::None),
            1 => Some(MsgVelCogInsNavigationMode::InsUsed),
            _ => None,
        }
    }

    pub fn set_ins_navigation_mode(&mut self, ins_navigation_mode: MsgVelCogInsNavigationMode) {
        set_bit_range!(&mut self.flags, ins_navigation_mode, u8, u8, 2, 0);
    }

    pub fn velocity_mode(&self) -> Option<MsgVelCogVelocityMode> {
        match get_bit_range!(self.flags, u8, u8, 1, 0) {
            0 => Some(MsgVelCogVelocityMode::Invalid),
            1 => Some(MsgVelCogVelocityMode::MeasuredDopplerDerived),
            2 => Some(MsgVelCogVelocityMode::ComputedDopplerDerived),
            3 => Some(MsgVelCogVelocityMode::DeadReckoning),
            _ => None,
        }
    }

    pub fn set_velocity_mode(&mut self, velocity_mode: MsgVelCogVelocityMode) {
        set_bit_range!(&mut self.flags, velocity_mode, u8, u8, 1, 0);
    }
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
        + <u16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.cog)
            + WireFormat::len(&self.sog)
            + WireFormat::len(&self.v_up)
            + WireFormat::len(&self.cog_accuracy)
            + WireFormat::len(&self.sog_accuracy)
            + WireFormat::len(&self.v_up_accuracy)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.cog, buf);
        WireFormat::write(&self.sog, buf);
        WireFormat::write(&self.v_up, buf);
        WireFormat::write(&self.cog_accuracy, buf);
        WireFormat::write(&self.sog_accuracy, buf);
        WireFormat::write(&self.v_up_accuracy, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgVelCog {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            cog: WireFormat::parse_unchecked(buf),
            sog: WireFormat::parse_unchecked(buf),
            v_up: WireFormat::parse_unchecked(buf),
            cog_accuracy: WireFormat::parse_unchecked(buf),
            sog_accuracy: WireFormat::parse_unchecked(buf),
            v_up_accuracy: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Vertical velocity validity
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelCogVerticalVelocityValidity {
    /// Invalid
    Invalid = 0,

    /// Vertical velocity valid
    VerticalVelocityValid = 1,
}

impl std::fmt::Display for MsgVelCogVerticalVelocityValidity {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelCogVerticalVelocityValidity::Invalid => f.write_str("Invalid"),
            MsgVelCogVerticalVelocityValidity::VerticalVelocityValid => {
                f.write_str("Vertical velocity valid")
            }
        }
    }
}

/// SOG validity
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelCogSogValidity {
    /// Invalid
    Invalid = 0,

    /// SOG valid
    SogValid = 1,
}

impl std::fmt::Display for MsgVelCogSogValidity {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelCogSogValidity::Invalid => f.write_str("Invalid"),
            MsgVelCogSogValidity::SogValid => f.write_str("SOG valid"),
        }
    }
}

/// COG validity
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelCogCogValidity {
    /// Invalid
    Invalid = 0,

    /// COG valid
    CogValid = 1,
}

impl std::fmt::Display for MsgVelCogCogValidity {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelCogCogValidity::Invalid => f.write_str("Invalid"),
            MsgVelCogCogValidity::CogValid => f.write_str("COG valid"),
        }
    }
}

/// INS Navigation Mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelCogInsNavigationMode {
    /// None
    None = 0,

    /// INS used
    InsUsed = 1,
}

impl std::fmt::Display for MsgVelCogInsNavigationMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelCogInsNavigationMode::None => f.write_str("None"),
            MsgVelCogInsNavigationMode::InsUsed => f.write_str("INS used"),
        }
    }
}

/// Velocity mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelCogVelocityMode {
    /// Invalid
    Invalid = 0,

    /// Measured Doppler derived
    MeasuredDopplerDerived = 1,

    /// Computed Doppler derived
    ComputedDopplerDerived = 2,

    /// Dead Reckoning
    DeadReckoning = 3,
}

impl std::fmt::Display for MsgVelCogVelocityMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelCogVelocityMode::Invalid => f.write_str("Invalid"),
            MsgVelCogVelocityMode::MeasuredDopplerDerived => {
                f.write_str("Measured Doppler derived")
            }
            MsgVelCogVelocityMode::ComputedDopplerDerived => {
                f.write_str("Computed Doppler derived")
            }
            MsgVelCogVelocityMode::DeadReckoning => f.write_str("Dead Reckoning"),
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

impl MsgVelEcef {
    pub fn type_of_reported_tow(&self) -> Option<MsgVelEcefTypeOfReportedTow> {
        match get_bit_range!(self.flags, u8, u8, 5, 5) {
            0 => Some(MsgVelEcefTypeOfReportedTow::TimeOfMeasurement),
            1 => Some(MsgVelEcefTypeOfReportedTow::Other),
            _ => None,
        }
    }

    pub fn set_type_of_reported_tow(&mut self, type_of_reported_tow: MsgVelEcefTypeOfReportedTow) {
        set_bit_range!(&mut self.flags, type_of_reported_tow, u8, u8, 5, 5);
    }

    pub fn ins_navigation_mode(&self) -> Option<MsgVelEcefInsNavigationMode> {
        match get_bit_range!(self.flags, u8, u8, 4, 3) {
            0 => Some(MsgVelEcefInsNavigationMode::None),
            1 => Some(MsgVelEcefInsNavigationMode::InsUsed),
            _ => None,
        }
    }

    pub fn set_ins_navigation_mode(&mut self, ins_navigation_mode: MsgVelEcefInsNavigationMode) {
        set_bit_range!(&mut self.flags, ins_navigation_mode, u8, u8, 4, 3);
    }

    pub fn velocity_mode(&self) -> Option<MsgVelEcefVelocityMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgVelEcefVelocityMode::Invalid),
            1 => Some(MsgVelEcefVelocityMode::MeasuredDopplerDerived),
            2 => Some(MsgVelEcefVelocityMode::ComputedDopplerDerived),
            3 => Some(MsgVelEcefVelocityMode::DeadReckoning),
            _ => None,
        }
    }

    pub fn set_velocity_mode(&mut self, velocity_mode: MsgVelEcefVelocityMode) {
        set_bit_range!(&mut self.flags, velocity_mode, u8, u8, 2, 0);
    }
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

/// Type of reported TOW
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelEcefTypeOfReportedTow {
    /// Time of Measurement
    TimeOfMeasurement = 0,

    /// Other
    Other = 1,
}

impl std::fmt::Display for MsgVelEcefTypeOfReportedTow {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelEcefTypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
            MsgVelEcefTypeOfReportedTow::Other => f.write_str("Other"),
        }
    }
}

/// INS Navigation Mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelEcefInsNavigationMode {
    /// None
    None = 0,

    /// INS used
    InsUsed = 1,
}

impl std::fmt::Display for MsgVelEcefInsNavigationMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelEcefInsNavigationMode::None => f.write_str("None"),
            MsgVelEcefInsNavigationMode::InsUsed => f.write_str("INS used"),
        }
    }
}

/// Velocity mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelEcefVelocityMode {
    /// Invalid
    Invalid = 0,

    /// Measured Doppler derived
    MeasuredDopplerDerived = 1,

    /// Computed Doppler derived
    ComputedDopplerDerived = 2,

    /// Dead Reckoning
    DeadReckoning = 3,
}

impl std::fmt::Display for MsgVelEcefVelocityMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelEcefVelocityMode::Invalid => f.write_str("Invalid"),
            MsgVelEcefVelocityMode::MeasuredDopplerDerived => {
                f.write_str("Measured Doppler derived")
            }
            MsgVelEcefVelocityMode::ComputedDopplerDerived => {
                f.write_str("Computed Doppler derived")
            }
            MsgVelEcefVelocityMode::DeadReckoning => f.write_str("Dead Reckoning"),
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

impl MsgVelEcefCov {
    pub fn type_of_reported_tow(&self) -> Option<MsgVelEcefCovTypeOfReportedTow> {
        match get_bit_range!(self.flags, u8, u8, 5, 5) {
            0 => Some(MsgVelEcefCovTypeOfReportedTow::TimeOfMeasurement),
            1 => Some(MsgVelEcefCovTypeOfReportedTow::Other),
            _ => None,
        }
    }

    pub fn set_type_of_reported_tow(
        &mut self,
        type_of_reported_tow: MsgVelEcefCovTypeOfReportedTow,
    ) {
        set_bit_range!(&mut self.flags, type_of_reported_tow, u8, u8, 5, 5);
    }

    pub fn ins_navigation_mode(&self) -> Option<MsgVelEcefCovInsNavigationMode> {
        match get_bit_range!(self.flags, u8, u8, 4, 3) {
            0 => Some(MsgVelEcefCovInsNavigationMode::None),
            1 => Some(MsgVelEcefCovInsNavigationMode::InsUsed),
            _ => None,
        }
    }

    pub fn set_ins_navigation_mode(&mut self, ins_navigation_mode: MsgVelEcefCovInsNavigationMode) {
        set_bit_range!(&mut self.flags, ins_navigation_mode, u8, u8, 4, 3);
    }

    pub fn velocity_mode(&self) -> Option<MsgVelEcefCovVelocityMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgVelEcefCovVelocityMode::Invalid),
            1 => Some(MsgVelEcefCovVelocityMode::MeasuredDopplerDerived),
            2 => Some(MsgVelEcefCovVelocityMode::ComputedDopplerDerived),
            3 => Some(MsgVelEcefCovVelocityMode::DeadReckoning),
            _ => None,
        }
    }

    pub fn set_velocity_mode(&mut self, velocity_mode: MsgVelEcefCovVelocityMode) {
        set_bit_range!(&mut self.flags, velocity_mode, u8, u8, 2, 0);
    }
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

/// Type of reported TOW
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelEcefCovTypeOfReportedTow {
    /// Time of Measurement
    TimeOfMeasurement = 0,

    /// Other
    Other = 1,
}

impl std::fmt::Display for MsgVelEcefCovTypeOfReportedTow {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelEcefCovTypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
            MsgVelEcefCovTypeOfReportedTow::Other => f.write_str("Other"),
        }
    }
}

/// INS Navigation Mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelEcefCovInsNavigationMode {
    /// None
    None = 0,

    /// INS used
    InsUsed = 1,
}

impl std::fmt::Display for MsgVelEcefCovInsNavigationMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelEcefCovInsNavigationMode::None => f.write_str("None"),
            MsgVelEcefCovInsNavigationMode::InsUsed => f.write_str("INS used"),
        }
    }
}

/// Velocity mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelEcefCovVelocityMode {
    /// Invalid
    Invalid = 0,

    /// Measured Doppler derived
    MeasuredDopplerDerived = 1,

    /// Computed Doppler derived
    ComputedDopplerDerived = 2,

    /// Dead Reckoning
    DeadReckoning = 3,
}

impl std::fmt::Display for MsgVelEcefCovVelocityMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelEcefCovVelocityMode::Invalid => f.write_str("Invalid"),
            MsgVelEcefCovVelocityMode::MeasuredDopplerDerived => {
                f.write_str("Measured Doppler derived")
            }
            MsgVelEcefCovVelocityMode::ComputedDopplerDerived => {
                f.write_str("Computed Doppler derived")
            }
            MsgVelEcefCovVelocityMode::DeadReckoning => f.write_str("Dead Reckoning"),
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

impl MsgVelEcefCovGnss {
    pub fn velocity_mode(&self) -> Option<MsgVelEcefCovGnssVelocityMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgVelEcefCovGnssVelocityMode::Invalid),
            1 => Some(MsgVelEcefCovGnssVelocityMode::MeasuredDopplerDerived),
            2 => Some(MsgVelEcefCovGnssVelocityMode::ComputedDopplerDerived),
            _ => None,
        }
    }

    pub fn set_velocity_mode(&mut self, velocity_mode: MsgVelEcefCovGnssVelocityMode) {
        set_bit_range!(&mut self.flags, velocity_mode, u8, u8, 2, 0);
    }
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

/// Velocity mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelEcefCovGnssVelocityMode {
    /// Invalid
    Invalid = 0,

    /// Measured Doppler derived
    MeasuredDopplerDerived = 1,

    /// Computed Doppler derived
    ComputedDopplerDerived = 2,
}

impl std::fmt::Display for MsgVelEcefCovGnssVelocityMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelEcefCovGnssVelocityMode::Invalid => f.write_str("Invalid"),
            MsgVelEcefCovGnssVelocityMode::MeasuredDopplerDerived => {
                f.write_str("Measured Doppler derived")
            }
            MsgVelEcefCovGnssVelocityMode::ComputedDopplerDerived => {
                f.write_str("Computed Doppler derived")
            }
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

impl MsgVelEcefGnss {
    pub fn velocity_mode(&self) -> Option<MsgVelEcefGnssVelocityMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgVelEcefGnssVelocityMode::Invalid),
            1 => Some(MsgVelEcefGnssVelocityMode::MeasuredDopplerDerived),
            2 => Some(MsgVelEcefGnssVelocityMode::ComputedDopplerDerived),
            _ => None,
        }
    }

    pub fn set_velocity_mode(&mut self, velocity_mode: MsgVelEcefGnssVelocityMode) {
        set_bit_range!(&mut self.flags, velocity_mode, u8, u8, 2, 0);
    }
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

/// Velocity mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelEcefGnssVelocityMode {
    /// Invalid
    Invalid = 0,

    /// Measured Doppler derived
    MeasuredDopplerDerived = 1,

    /// Computed Doppler derived
    ComputedDopplerDerived = 2,
}

impl std::fmt::Display for MsgVelEcefGnssVelocityMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelEcefGnssVelocityMode::Invalid => f.write_str("Invalid"),
            MsgVelEcefGnssVelocityMode::MeasuredDopplerDerived => {
                f.write_str("Measured Doppler derived")
            }
            MsgVelEcefGnssVelocityMode::ComputedDopplerDerived => {
                f.write_str("Computed Doppler derived")
            }
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

impl MsgVelNed {
    pub fn type_of_reported_tow(&self) -> Option<MsgVelNedTypeOfReportedTow> {
        match get_bit_range!(self.flags, u8, u8, 5, 5) {
            0 => Some(MsgVelNedTypeOfReportedTow::TimeOfMeasurement),
            1 => Some(MsgVelNedTypeOfReportedTow::Other),
            _ => None,
        }
    }

    pub fn set_type_of_reported_tow(&mut self, type_of_reported_tow: MsgVelNedTypeOfReportedTow) {
        set_bit_range!(&mut self.flags, type_of_reported_tow, u8, u8, 5, 5);
    }

    pub fn ins_navigation_mode(&self) -> Option<MsgVelNedInsNavigationMode> {
        match get_bit_range!(self.flags, u8, u8, 4, 3) {
            0 => Some(MsgVelNedInsNavigationMode::None),
            1 => Some(MsgVelNedInsNavigationMode::InsUsed),
            _ => None,
        }
    }

    pub fn set_ins_navigation_mode(&mut self, ins_navigation_mode: MsgVelNedInsNavigationMode) {
        set_bit_range!(&mut self.flags, ins_navigation_mode, u8, u8, 4, 3);
    }

    pub fn velocity_mode(&self) -> Option<MsgVelNedVelocityMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgVelNedVelocityMode::Invalid),
            1 => Some(MsgVelNedVelocityMode::MeasuredDopplerDerived),
            2 => Some(MsgVelNedVelocityMode::ComputedDopplerDerived),
            3 => Some(MsgVelNedVelocityMode::DeadReckoning),
            _ => None,
        }
    }

    pub fn set_velocity_mode(&mut self, velocity_mode: MsgVelNedVelocityMode) {
        set_bit_range!(&mut self.flags, velocity_mode, u8, u8, 2, 0);
    }
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

/// Type of reported TOW
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelNedTypeOfReportedTow {
    /// Time of Measurement
    TimeOfMeasurement = 0,

    /// Other
    Other = 1,
}

impl std::fmt::Display for MsgVelNedTypeOfReportedTow {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelNedTypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
            MsgVelNedTypeOfReportedTow::Other => f.write_str("Other"),
        }
    }
}

/// INS Navigation Mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelNedInsNavigationMode {
    /// None
    None = 0,

    /// INS used
    InsUsed = 1,
}

impl std::fmt::Display for MsgVelNedInsNavigationMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelNedInsNavigationMode::None => f.write_str("None"),
            MsgVelNedInsNavigationMode::InsUsed => f.write_str("INS used"),
        }
    }
}

/// Velocity mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelNedVelocityMode {
    /// Invalid
    Invalid = 0,

    /// Measured Doppler derived
    MeasuredDopplerDerived = 1,

    /// Computed Doppler derived
    ComputedDopplerDerived = 2,

    /// Dead Reckoning
    DeadReckoning = 3,
}

impl std::fmt::Display for MsgVelNedVelocityMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelNedVelocityMode::Invalid => f.write_str("Invalid"),
            MsgVelNedVelocityMode::MeasuredDopplerDerived => {
                f.write_str("Measured Doppler derived")
            }
            MsgVelNedVelocityMode::ComputedDopplerDerived => {
                f.write_str("Computed Doppler derived")
            }
            MsgVelNedVelocityMode::DeadReckoning => f.write_str("Dead Reckoning"),
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

impl MsgVelNedCov {
    pub fn type_of_reported_tow(&self) -> Option<MsgVelNedCovTypeOfReportedTow> {
        match get_bit_range!(self.flags, u8, u8, 5, 5) {
            0 => Some(MsgVelNedCovTypeOfReportedTow::TimeOfMeasurement),
            1 => Some(MsgVelNedCovTypeOfReportedTow::Other),
            _ => None,
        }
    }

    pub fn set_type_of_reported_tow(
        &mut self,
        type_of_reported_tow: MsgVelNedCovTypeOfReportedTow,
    ) {
        set_bit_range!(&mut self.flags, type_of_reported_tow, u8, u8, 5, 5);
    }

    pub fn ins_navigation_mode(&self) -> Option<MsgVelNedCovInsNavigationMode> {
        match get_bit_range!(self.flags, u8, u8, 4, 3) {
            0 => Some(MsgVelNedCovInsNavigationMode::None),
            1 => Some(MsgVelNedCovInsNavigationMode::InsUsed),
            _ => None,
        }
    }

    pub fn set_ins_navigation_mode(&mut self, ins_navigation_mode: MsgVelNedCovInsNavigationMode) {
        set_bit_range!(&mut self.flags, ins_navigation_mode, u8, u8, 4, 3);
    }

    pub fn velocity_mode(&self) -> Option<MsgVelNedCovVelocityMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgVelNedCovVelocityMode::Invalid),
            1 => Some(MsgVelNedCovVelocityMode::MeasuredDopplerDerived),
            2 => Some(MsgVelNedCovVelocityMode::ComputedDopplerDerived),
            3 => Some(MsgVelNedCovVelocityMode::DeadReckoning),
            _ => None,
        }
    }

    pub fn set_velocity_mode(&mut self, velocity_mode: MsgVelNedCovVelocityMode) {
        set_bit_range!(&mut self.flags, velocity_mode, u8, u8, 2, 0);
    }
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

/// Type of reported TOW
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelNedCovTypeOfReportedTow {
    /// Time of Measurement
    TimeOfMeasurement = 0,

    /// Other
    Other = 1,
}

impl std::fmt::Display for MsgVelNedCovTypeOfReportedTow {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelNedCovTypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
            MsgVelNedCovTypeOfReportedTow::Other => f.write_str("Other"),
        }
    }
}

/// INS Navigation Mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelNedCovInsNavigationMode {
    /// None
    None = 0,

    /// INS used
    InsUsed = 1,
}

impl std::fmt::Display for MsgVelNedCovInsNavigationMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelNedCovInsNavigationMode::None => f.write_str("None"),
            MsgVelNedCovInsNavigationMode::InsUsed => f.write_str("INS used"),
        }
    }
}

/// Velocity mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelNedCovVelocityMode {
    /// Invalid
    Invalid = 0,

    /// Measured Doppler derived
    MeasuredDopplerDerived = 1,

    /// Computed Doppler derived
    ComputedDopplerDerived = 2,

    /// Dead Reckoning
    DeadReckoning = 3,
}

impl std::fmt::Display for MsgVelNedCovVelocityMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelNedCovVelocityMode::Invalid => f.write_str("Invalid"),
            MsgVelNedCovVelocityMode::MeasuredDopplerDerived => {
                f.write_str("Measured Doppler derived")
            }
            MsgVelNedCovVelocityMode::ComputedDopplerDerived => {
                f.write_str("Computed Doppler derived")
            }
            MsgVelNedCovVelocityMode::DeadReckoning => f.write_str("Dead Reckoning"),
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

impl MsgVelNedCovGnss {
    pub fn velocity_mode(&self) -> Option<MsgVelNedCovGnssVelocityMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgVelNedCovGnssVelocityMode::Invalid),
            1 => Some(MsgVelNedCovGnssVelocityMode::MeasuredDopplerDerived),
            2 => Some(MsgVelNedCovGnssVelocityMode::ComputedDopplerDerived),
            _ => None,
        }
    }

    pub fn set_velocity_mode(&mut self, velocity_mode: MsgVelNedCovGnssVelocityMode) {
        set_bit_range!(&mut self.flags, velocity_mode, u8, u8, 2, 0);
    }
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

/// Velocity mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelNedCovGnssVelocityMode {
    /// Invalid
    Invalid = 0,

    /// Measured Doppler derived
    MeasuredDopplerDerived = 1,

    /// Computed Doppler derived
    ComputedDopplerDerived = 2,
}

impl std::fmt::Display for MsgVelNedCovGnssVelocityMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelNedCovGnssVelocityMode::Invalid => f.write_str("Invalid"),
            MsgVelNedCovGnssVelocityMode::MeasuredDopplerDerived => {
                f.write_str("Measured Doppler derived")
            }
            MsgVelNedCovGnssVelocityMode::ComputedDopplerDerived => {
                f.write_str("Computed Doppler derived")
            }
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

impl MsgVelNedGnss {
    pub fn velocity_mode(&self) -> Option<MsgVelNedGnssVelocityMode> {
        match get_bit_range!(self.flags, u8, u8, 2, 0) {
            0 => Some(MsgVelNedGnssVelocityMode::Invalid),
            1 => Some(MsgVelNedGnssVelocityMode::MeasuredDopplerDerived),
            2 => Some(MsgVelNedGnssVelocityMode::ComputedDopplerDerived),
            _ => None,
        }
    }

    pub fn set_velocity_mode(&mut self, velocity_mode: MsgVelNedGnssVelocityMode) {
        set_bit_range!(&mut self.flags, velocity_mode, u8, u8, 2, 0);
    }
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

/// Velocity mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgVelNedGnssVelocityMode {
    /// Invalid
    Invalid = 0,

    /// Measured Doppler derived
    MeasuredDopplerDerived = 1,

    /// Computed Doppler derived
    ComputedDopplerDerived = 2,
}

impl std::fmt::Display for MsgVelNedGnssVelocityMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgVelNedGnssVelocityMode::Invalid => f.write_str("Invalid"),
            MsgVelNedGnssVelocityMode::MeasuredDopplerDerived => {
                f.write_str("Measured Doppler derived")
            }
            MsgVelNedGnssVelocityMode::ComputedDopplerDerived => {
                f.write_str("Computed Doppler derived")
            }
        }
    }
}
