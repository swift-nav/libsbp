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
pub use estimated_horizontal_error_ellipse::EstimatedHorizontalErrorEllipse;
pub use msg_age_corrections::MsgAgeCorrections;
pub use msg_baseline_ecef::MsgBaselineEcef;
pub use msg_baseline_ecef_dep_a::MsgBaselineEcefDepA;
pub use msg_baseline_heading_dep_a::MsgBaselineHeadingDepA;
pub use msg_baseline_ned::MsgBaselineNed;
pub use msg_baseline_ned_dep_a::MsgBaselineNedDepA;
pub use msg_dops::MsgDops;
pub use msg_dops_dep_a::MsgDopsDepA;
pub use msg_gps_time::MsgGpsTime;
pub use msg_gps_time_dep_a::MsgGpsTimeDepA;
pub use msg_gps_time_gnss::MsgGpsTimeGnss;
pub use msg_pos_ecef::MsgPosEcef;
pub use msg_pos_ecef_cov::MsgPosEcefCov;
pub use msg_pos_ecef_cov_gnss::MsgPosEcefCovGnss;
pub use msg_pos_ecef_dep_a::MsgPosEcefDepA;
pub use msg_pos_ecef_gnss::MsgPosEcefGnss;
pub use msg_pos_llh::MsgPosLlh;
pub use msg_pos_llh_acc::MsgPosLlhAcc;
pub use msg_pos_llh_cov::MsgPosLlhCov;
pub use msg_pos_llh_cov_gnss::MsgPosLlhCovGnss;
pub use msg_pos_llh_dep_a::MsgPosLlhDepA;
pub use msg_pos_llh_gnss::MsgPosLlhGnss;
pub use msg_protection_level::MsgProtectionLevel;
pub use msg_protection_level_dep_a::MsgProtectionLevelDepA;
pub use msg_reference_frame_param::MsgReferenceFrameParam;
pub use msg_utc_leap_second::MsgUtcLeapSecond;
pub use msg_utc_time::MsgUtcTime;
pub use msg_utc_time_gnss::MsgUtcTimeGnss;
pub use msg_vel_body::MsgVelBody;
pub use msg_vel_cog::MsgVelCog;
pub use msg_vel_ecef::MsgVelEcef;
pub use msg_vel_ecef_cov::MsgVelEcefCov;
pub use msg_vel_ecef_cov_gnss::MsgVelEcefCovGnss;
pub use msg_vel_ecef_dep_a::MsgVelEcefDepA;
pub use msg_vel_ecef_gnss::MsgVelEcefGnss;
pub use msg_vel_ned::MsgVelNed;
pub use msg_vel_ned_cov::MsgVelNedCov;
pub use msg_vel_ned_cov_gnss::MsgVelNedCovGnss;
pub use msg_vel_ned_dep_a::MsgVelNedDepA;
pub use msg_vel_ned_gnss::MsgVelNedGnss;

pub mod estimated_horizontal_error_ellipse {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;
    /// Horizontal estimated error ellipse
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct EstimatedHorizontalErrorEllipse {
        /// The semi major axis of the estimated horizontal error ellipse at the
        /// user-configured confidence level; zero implies invalid.
        #[cfg_attr(feature = "serde", serde(rename = "semi_major"))]
        pub semi_major: f32,
        /// The semi minor axis of the estimated horizontal error ellipse at the
        /// user-configured confidence level; zero implies invalid.
        #[cfg_attr(feature = "serde", serde(rename = "semi_minor"))]
        pub semi_minor: f32,
        /// The orientation of the semi major axis of the estimated horizontal error
        /// ellipse with respect to North.
        #[cfg_attr(feature = "serde", serde(rename = "orientation"))]
        pub orientation: f32,
    }

    impl WireFormat for EstimatedHorizontalErrorEllipse {
        const MIN_LEN: usize = <f32 as WireFormat>::MIN_LEN
            + <f32 as WireFormat>::MIN_LEN
            + <f32 as WireFormat>::MIN_LEN;
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
}

pub mod msg_age_corrections {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Age of corrections
    ///
    /// This message reports the Age of the corrections used for the current
    /// Differential solution.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgAgeCorrections {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Age of the corrections (0xFFFF indicates invalid)
        #[cfg_attr(feature = "serde", serde(rename = "age"))]
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
}

pub mod msg_baseline_ecef {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Baseline Position in ECEF
    ///
    /// This message reports the baseline solution in Earth Centered Earth Fixed
    /// (ECEF) coordinates. This baseline is the relative vector distance from the
    /// base station to the rover receiver. The full GPS time is given by the
    /// preceding MSG_GPS_TIME with the matching time-of-week (tow).
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgBaselineEcef {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Baseline ECEF X coordinate
        #[cfg_attr(feature = "serde", serde(rename = "x"))]
        pub x: i32,
        /// Baseline ECEF Y coordinate
        #[cfg_attr(feature = "serde", serde(rename = "y"))]
        pub y: i32,
        /// Baseline ECEF Z coordinate
        #[cfg_attr(feature = "serde", serde(rename = "z"))]
        pub z: i32,
        /// Position estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "accuracy"))]
        pub accuracy: u16,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgBaselineEcef {
        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
        /// Invalid
        Invalid = 0,

        /// Differential GNSS (DGNSS)
        DifferentialGnss = 2,

        /// Float RTK
        FloatRtk = 3,

        /// Fixed RTK
        FixedRtk = 4,
    }

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::Invalid => f.write_str("Invalid"),
                FixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
                FixMode::FloatRtk => f.write_str("Float RTK"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::Invalid),
                2 => Ok(FixMode::DifferentialGnss),
                3 => Ok(FixMode::FloatRtk),
                4 => Ok(FixMode::FixedRtk),
                i => Err(i),
            }
        }
    }
}

pub mod msg_baseline_ecef_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Baseline Position in ECEF
    ///
    /// This message reports the baseline solution in Earth Centered Earth Fixed
    /// (ECEF) coordinates. This baseline is the relative vector distance from the
    /// base station to the rover receiver. The full GPS time is given by the
    /// preceding MSG_GPS_TIME with the matching time-of-week (tow).
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgBaselineEcefDepA {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Baseline ECEF X coordinate
        #[cfg_attr(feature = "serde", serde(rename = "x"))]
        pub x: i32,
        /// Baseline ECEF Y coordinate
        #[cfg_attr(feature = "serde", serde(rename = "y"))]
        pub y: i32,
        /// Baseline ECEF Z coordinate
        #[cfg_attr(feature = "serde", serde(rename = "z"))]
        pub z: i32,
        /// Position accuracy estimate
        #[cfg_attr(feature = "serde", serde(rename = "accuracy"))]
        pub accuracy: u16,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgBaselineEcefDepA {
        /// Gets the [RaimRepairFlag][self::RaimRepairFlag] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `RaimRepairFlag` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `RaimRepairFlag` were added.
        pub fn raim_repair_flag(&self) -> Result<RaimRepairFlag, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 4).try_into()
        }

        /// Set the bitrange corresponding to the [RaimRepairFlag][RaimRepairFlag] of the `flags` bitfield.
        pub fn set_raim_repair_flag(&mut self, raim_repair_flag: RaimRepairFlag) {
            set_bit_range!(&mut self.flags, raim_repair_flag, u8, u8, 4, 4);
        }

        /// Gets the [RaimAvailabilityFlag][self::RaimAvailabilityFlag] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `RaimAvailabilityFlag` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `RaimAvailabilityFlag` were added.
        pub fn raim_availability_flag(&self) -> Result<RaimAvailabilityFlag, u8> {
            get_bit_range!(self.flags, u8, u8, 3, 3).try_into()
        }

        /// Set the bitrange corresponding to the [RaimAvailabilityFlag][RaimAvailabilityFlag] of the `flags` bitfield.
        pub fn set_raim_availability_flag(&mut self, raim_availability_flag: RaimAvailabilityFlag) {
            set_bit_range!(&mut self.flags, raim_availability_flag, u8, u8, 3, 3);
        }

        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum RaimRepairFlag {
        /// No repair
        NoRepair = 0,

        /// Solution came from RAIM repair
        SolutionCameFromRaimRepair = 1,
    }

    impl std::fmt::Display for RaimRepairFlag {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                RaimRepairFlag::NoRepair => f.write_str("No repair"),
                RaimRepairFlag::SolutionCameFromRaimRepair => {
                    f.write_str("Solution came from RAIM repair")
                }
            }
        }
    }

    impl TryFrom<u8> for RaimRepairFlag {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(RaimRepairFlag::NoRepair),
                1 => Ok(RaimRepairFlag::SolutionCameFromRaimRepair),
                i => Err(i),
            }
        }
    }

    /// RAIM availability flag
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum RaimAvailabilityFlag {
        /// RAIM check was explicitly disabled or unavailable
        RaimCheckWasExplicitlyDisabledOrUnavailable = 0,

        /// RAIM check was available
        RaimCheckWasAvailable = 1,
    }

    impl std::fmt::Display for RaimAvailabilityFlag {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                RaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable => {
                    f.write_str("RAIM check was explicitly disabled or unavailable")
                }
                RaimAvailabilityFlag::RaimCheckWasAvailable => {
                    f.write_str("RAIM check was available")
                }
            }
        }
    }

    impl TryFrom<u8> for RaimAvailabilityFlag {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(RaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable),
                1 => Ok(RaimAvailabilityFlag::RaimCheckWasAvailable),
                i => Err(i),
            }
        }
    }

    /// Fix mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
        /// Float RTK
        FloatRtk = 0,

        /// Fixed RTK
        FixedRtk = 1,
    }

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::FloatRtk => f.write_str("Float RTK"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::FloatRtk),
                1 => Ok(FixMode::FixedRtk),
                i => Err(i),
            }
        }
    }
}

pub mod msg_baseline_heading_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Heading relative to True North
    ///
    /// This message reports the baseline heading pointing from the base station
    /// to the rover relative to True North. The full GPS time is given by the
    /// preceding MSG_GPS_TIME with the matching time-of-week (tow).
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgBaselineHeadingDepA {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Heading
        #[cfg_attr(feature = "serde", serde(rename = "heading"))]
        pub heading: u32,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgBaselineHeadingDepA {
        /// Gets the [RaimRepairFlag][self::RaimRepairFlag] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `RaimRepairFlag` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `RaimRepairFlag` were added.
        pub fn raim_repair_flag(&self) -> Result<RaimRepairFlag, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 4).try_into()
        }

        /// Set the bitrange corresponding to the [RaimRepairFlag][RaimRepairFlag] of the `flags` bitfield.
        pub fn set_raim_repair_flag(&mut self, raim_repair_flag: RaimRepairFlag) {
            set_bit_range!(&mut self.flags, raim_repair_flag, u8, u8, 4, 4);
        }

        /// Gets the [RaimAvailabilityFlag][self::RaimAvailabilityFlag] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `RaimAvailabilityFlag` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `RaimAvailabilityFlag` were added.
        pub fn raim_availability_flag(&self) -> Result<RaimAvailabilityFlag, u8> {
            get_bit_range!(self.flags, u8, u8, 3, 3).try_into()
        }

        /// Set the bitrange corresponding to the [RaimAvailabilityFlag][RaimAvailabilityFlag] of the `flags` bitfield.
        pub fn set_raim_availability_flag(&mut self, raim_availability_flag: RaimAvailabilityFlag) {
            set_bit_range!(&mut self.flags, raim_availability_flag, u8, u8, 3, 3);
        }

        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum RaimRepairFlag {
        /// No repair
        NoRepair = 0,

        /// Solution came from RAIM repair
        SolutionCameFromRaimRepair = 1,
    }

    impl std::fmt::Display for RaimRepairFlag {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                RaimRepairFlag::NoRepair => f.write_str("No repair"),
                RaimRepairFlag::SolutionCameFromRaimRepair => {
                    f.write_str("Solution came from RAIM repair")
                }
            }
        }
    }

    impl TryFrom<u8> for RaimRepairFlag {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(RaimRepairFlag::NoRepair),
                1 => Ok(RaimRepairFlag::SolutionCameFromRaimRepair),
                i => Err(i),
            }
        }
    }

    /// RAIM availability flag
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum RaimAvailabilityFlag {
        /// RAIM check was explicitly disabled or unavailable
        RaimCheckWasExplicitlyDisabledOrUnavailable = 0,

        /// RAIM check was available
        RaimCheckWasAvailable = 1,
    }

    impl std::fmt::Display for RaimAvailabilityFlag {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                RaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable => {
                    f.write_str("RAIM check was explicitly disabled or unavailable")
                }
                RaimAvailabilityFlag::RaimCheckWasAvailable => {
                    f.write_str("RAIM check was available")
                }
            }
        }
    }

    impl TryFrom<u8> for RaimAvailabilityFlag {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(RaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable),
                1 => Ok(RaimAvailabilityFlag::RaimCheckWasAvailable),
                i => Err(i),
            }
        }
    }

    /// Fix mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
        /// Float RTK
        FloatRtk = 0,

        /// Fixed RTK
        FixedRtk = 1,
    }

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::FloatRtk => f.write_str("Float RTK"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::FloatRtk),
                1 => Ok(FixMode::FixedRtk),
                i => Err(i),
            }
        }
    }
}

pub mod msg_baseline_ned {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Baseline in NED
    ///
    /// This message reports the baseline solution in North East Down (NED)
    /// coordinates. This baseline is the relative vector distance from the base
    /// station to the rover receiver, and NED coordinate system is defined at the
    /// local WGS84 tangent plane centered at the base station position.  The full
    /// GPS time is given by the preceding MSG_GPS_TIME with the matching time-of-
    /// week (tow).
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgBaselineNed {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Baseline North coordinate
        #[cfg_attr(feature = "serde", serde(rename = "n"))]
        pub n: i32,
        /// Baseline East coordinate
        #[cfg_attr(feature = "serde", serde(rename = "e"))]
        pub e: i32,
        /// Baseline Down coordinate
        #[cfg_attr(feature = "serde", serde(rename = "d"))]
        pub d: i32,
        /// Horizontal position estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "h_accuracy"))]
        pub h_accuracy: u16,
        /// Vertical position estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "v_accuracy"))]
        pub v_accuracy: u16,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgBaselineNed {
        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
        /// Invalid
        Invalid = 0,

        /// Differential GNSS (DGNSS)
        DifferentialGnss = 2,

        /// Float RTK
        FloatRtk = 3,

        /// Fixed RTK
        FixedRtk = 4,
    }

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::Invalid => f.write_str("Invalid"),
                FixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
                FixMode::FloatRtk => f.write_str("Float RTK"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::Invalid),
                2 => Ok(FixMode::DifferentialGnss),
                3 => Ok(FixMode::FloatRtk),
                4 => Ok(FixMode::FixedRtk),
                i => Err(i),
            }
        }
    }
}

pub mod msg_baseline_ned_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Baseline in NED
    ///
    /// This message reports the baseline solution in North East Down (NED)
    /// coordinates. This baseline is the relative vector distance from the base
    /// station to the rover receiver, and NED coordinate system is defined at the
    /// local WGS84 tangent plane centered at the base station position.  The full
    /// GPS time is given by the preceding MSG_GPS_TIME with the matching time-of-
    /// week (tow).
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgBaselineNedDepA {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Baseline North coordinate
        #[cfg_attr(feature = "serde", serde(rename = "n"))]
        pub n: i32,
        /// Baseline East coordinate
        #[cfg_attr(feature = "serde", serde(rename = "e"))]
        pub e: i32,
        /// Baseline Down coordinate
        #[cfg_attr(feature = "serde", serde(rename = "d"))]
        pub d: i32,
        /// Horizontal position accuracy estimate (not implemented). Defaults to 0.
        #[cfg_attr(feature = "serde", serde(rename = "h_accuracy"))]
        pub h_accuracy: u16,
        /// Vertical position accuracy estimate (not implemented). Defaults to 0.
        #[cfg_attr(feature = "serde", serde(rename = "v_accuracy"))]
        pub v_accuracy: u16,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgBaselineNedDepA {
        /// Gets the [RaimRepairFlag][self::RaimRepairFlag] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `RaimRepairFlag` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `RaimRepairFlag` were added.
        pub fn raim_repair_flag(&self) -> Result<RaimRepairFlag, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 4).try_into()
        }

        /// Set the bitrange corresponding to the [RaimRepairFlag][RaimRepairFlag] of the `flags` bitfield.
        pub fn set_raim_repair_flag(&mut self, raim_repair_flag: RaimRepairFlag) {
            set_bit_range!(&mut self.flags, raim_repair_flag, u8, u8, 4, 4);
        }

        /// Gets the [RaimAvailabilityFlag][self::RaimAvailabilityFlag] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `RaimAvailabilityFlag` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `RaimAvailabilityFlag` were added.
        pub fn raim_availability_flag(&self) -> Result<RaimAvailabilityFlag, u8> {
            get_bit_range!(self.flags, u8, u8, 3, 3).try_into()
        }

        /// Set the bitrange corresponding to the [RaimAvailabilityFlag][RaimAvailabilityFlag] of the `flags` bitfield.
        pub fn set_raim_availability_flag(&mut self, raim_availability_flag: RaimAvailabilityFlag) {
            set_bit_range!(&mut self.flags, raim_availability_flag, u8, u8, 3, 3);
        }

        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum RaimRepairFlag {
        /// No repair
        NoRepair = 0,

        /// Solution came from RAIM repair
        SolutionCameFromRaimRepair = 1,
    }

    impl std::fmt::Display for RaimRepairFlag {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                RaimRepairFlag::NoRepair => f.write_str("No repair"),
                RaimRepairFlag::SolutionCameFromRaimRepair => {
                    f.write_str("Solution came from RAIM repair")
                }
            }
        }
    }

    impl TryFrom<u8> for RaimRepairFlag {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(RaimRepairFlag::NoRepair),
                1 => Ok(RaimRepairFlag::SolutionCameFromRaimRepair),
                i => Err(i),
            }
        }
    }

    /// RAIM availability flag
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum RaimAvailabilityFlag {
        /// RAIM check was explicitly disabled or unavailable
        RaimCheckWasExplicitlyDisabledOrUnavailable = 0,

        /// RAIM check was available
        RaimCheckWasAvailable = 1,
    }

    impl std::fmt::Display for RaimAvailabilityFlag {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                RaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable => {
                    f.write_str("RAIM check was explicitly disabled or unavailable")
                }
                RaimAvailabilityFlag::RaimCheckWasAvailable => {
                    f.write_str("RAIM check was available")
                }
            }
        }
    }

    impl TryFrom<u8> for RaimAvailabilityFlag {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(RaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable),
                1 => Ok(RaimAvailabilityFlag::RaimCheckWasAvailable),
                i => Err(i),
            }
        }
    }

    /// Fix mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
        /// Float RTK
        FloatRtk = 0,

        /// Fixed RTK
        FixedRtk = 1,
    }

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::FloatRtk => f.write_str("Float RTK"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::FloatRtk),
                1 => Ok(FixMode::FixedRtk),
                i => Err(i),
            }
        }
    }
}

pub mod msg_dops {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Dilution of Precision
    ///
    /// This dilution of precision (DOP) message describes the effect of
    /// navigation satellite geometry on positional measurement precision.  The
    /// flags field indicated whether the DOP reported corresponds to differential
    /// or SPP solution.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgDops {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Geometric Dilution of Precision
        #[cfg_attr(feature = "serde", serde(rename = "gdop"))]
        pub gdop: u16,
        /// Position Dilution of Precision
        #[cfg_attr(feature = "serde", serde(rename = "pdop"))]
        pub pdop: u16,
        /// Time Dilution of Precision
        #[cfg_attr(feature = "serde", serde(rename = "tdop"))]
        pub tdop: u16,
        /// Horizontal Dilution of Precision
        #[cfg_attr(feature = "serde", serde(rename = "hdop"))]
        pub hdop: u16,
        /// Vertical Dilution of Precision
        #[cfg_attr(feature = "serde", serde(rename = "vdop"))]
        pub vdop: u16,
        /// Indicates the position solution with which the DOPS message corresponds
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgDops {
        /// Gets the `raim_repair_flag` flag.
        pub fn raim_repair_flag(&self) -> bool {
            ((self.flags >> 7) & 1) == 1
        }

        /// Sets the `raim_repair_flag` flag.
        pub fn set_raim_repair_flag(&mut self, raim_repair_flag: bool) {
            self.flags ^= (!(raim_repair_flag as u8)) & (1 << 7)
        }

        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
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

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::Invalid => f.write_str("Invalid"),
                FixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
                FixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
                FixMode::FloatRtk => f.write_str("Float RTK"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
                FixMode::Undefined => f.write_str("Undefined"),
                FixMode::SbasPosition => f.write_str("SBAS Position"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::Invalid),
                1 => Ok(FixMode::SinglePointPosition),
                2 => Ok(FixMode::DifferentialGnss),
                3 => Ok(FixMode::FloatRtk),
                4 => Ok(FixMode::FixedRtk),
                5 => Ok(FixMode::Undefined),
                6 => Ok(FixMode::SbasPosition),
                i => Err(i),
            }
        }
    }
}

pub mod msg_dops_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Dilution of Precision
    ///
    /// This dilution of precision (DOP) message describes the effect of
    /// navigation satellite geometry on positional measurement precision.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgDopsDepA {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Geometric Dilution of Precision
        #[cfg_attr(feature = "serde", serde(rename = "gdop"))]
        pub gdop: u16,
        /// Position Dilution of Precision
        #[cfg_attr(feature = "serde", serde(rename = "pdop"))]
        pub pdop: u16,
        /// Time Dilution of Precision
        #[cfg_attr(feature = "serde", serde(rename = "tdop"))]
        pub tdop: u16,
        /// Horizontal Dilution of Precision
        #[cfg_attr(feature = "serde", serde(rename = "hdop"))]
        pub hdop: u16,
        /// Vertical Dilution of Precision
        #[cfg_attr(feature = "serde", serde(rename = "vdop"))]
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
}

pub mod msg_gps_time {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgGpsTime {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS week number
        #[cfg_attr(feature = "serde", serde(rename = "wn"))]
        pub wn: u16,
        /// GPS time of week rounded to the nearest millisecond
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
        /// 500000)
        #[cfg_attr(feature = "serde", serde(rename = "ns_residual"))]
        pub ns_residual: i32,
        /// Status flags (reserved)
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgGpsTime {
        /// Gets the [TimeSource][self::TimeSource] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TimeSource` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TimeSource` were added.
        pub fn time_source(&self) -> Result<TimeSource, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [TimeSource][TimeSource] of the `flags` bitfield.
        pub fn set_time_source(&mut self, time_source: TimeSource) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TimeSource {
        /// None (invalid)
        None = 0,

        /// GNSS Solution
        GnssSolution = 1,

        /// Propagated
        Propagated = 2,
    }

    impl std::fmt::Display for TimeSource {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TimeSource::None => f.write_str("None (invalid)"),
                TimeSource::GnssSolution => f.write_str("GNSS Solution"),
                TimeSource::Propagated => f.write_str("Propagated"),
            }
        }
    }

    impl TryFrom<u8> for TimeSource {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TimeSource::None),
                1 => Ok(TimeSource::GnssSolution),
                2 => Ok(TimeSource::Propagated),
                i => Err(i),
            }
        }
    }
}

pub mod msg_gps_time_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgGpsTimeDepA {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS week number
        #[cfg_attr(feature = "serde", serde(rename = "wn"))]
        pub wn: u16,
        /// GPS time of week rounded to the nearest millisecond
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
        /// 500000)
        #[cfg_attr(feature = "serde", serde(rename = "ns_residual"))]
        pub ns_residual: i32,
        /// Status flags (reserved)
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
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
}

pub mod msg_gps_time_gnss {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgGpsTimeGnss {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS week number
        #[cfg_attr(feature = "serde", serde(rename = "wn"))]
        pub wn: u16,
        /// GPS time of week rounded to the nearest millisecond
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
        /// 500000)
        #[cfg_attr(feature = "serde", serde(rename = "ns_residual"))]
        pub ns_residual: i32,
        /// Status flags (reserved)
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgGpsTimeGnss {
        /// Gets the [TimeSource][self::TimeSource] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TimeSource` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TimeSource` were added.
        pub fn time_source(&self) -> Result<TimeSource, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [TimeSource][TimeSource] of the `flags` bitfield.
        pub fn set_time_source(&mut self, time_source: TimeSource) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TimeSource {
        /// None (invalid)
        None = 0,

        /// GNSS Solution
        GnssSolution = 1,

        /// Propagated
        Propagated = 2,
    }

    impl std::fmt::Display for TimeSource {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TimeSource::None => f.write_str("None (invalid)"),
                TimeSource::GnssSolution => f.write_str("GNSS Solution"),
                TimeSource::Propagated => f.write_str("Propagated"),
            }
        }
    }

    impl TryFrom<u8> for TimeSource {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TimeSource::None),
                1 => Ok(TimeSource::GnssSolution),
                2 => Ok(TimeSource::Propagated),
                i => Err(i),
            }
        }
    }
}

pub mod msg_pos_ecef {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgPosEcef {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// ECEF X coordinate
        #[cfg_attr(feature = "serde", serde(rename = "x"))]
        pub x: f64,
        /// ECEF Y coordinate
        #[cfg_attr(feature = "serde", serde(rename = "y"))]
        pub y: f64,
        /// ECEF Z coordinate
        #[cfg_attr(feature = "serde", serde(rename = "z"))]
        pub z: f64,
        /// Position estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "accuracy"))]
        pub accuracy: u16,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgPosEcef {
        /// Gets the [TowType][self::TowType] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TowType` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TowType` were added.
        pub fn tow_type(&self) -> Result<TowType, u8> {
            get_bit_range!(self.flags, u8, u8, 5, 5).try_into()
        }

        /// Set the bitrange corresponding to the [TowType][TowType] of the `flags` bitfield.
        pub fn set_tow_type(&mut self, tow_type: TowType) {
            set_bit_range!(&mut self.flags, tow_type, u8, u8, 5, 5);
        }

        /// Gets the [InertialNavigationMode][self::InertialNavigationMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `InertialNavigationMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `InertialNavigationMode` were added.
        pub fn inertial_navigation_mode(&self) -> Result<InertialNavigationMode, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 3).try_into()
        }

        /// Set the bitrange corresponding to the [InertialNavigationMode][InertialNavigationMode] of the `flags` bitfield.
        pub fn set_inertial_navigation_mode(
            &mut self,
            inertial_navigation_mode: InertialNavigationMode,
        ) {
            set_bit_range!(&mut self.flags, inertial_navigation_mode, u8, u8, 4, 3);
        }

        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TowType {
        /// Time of Measurement
        TimeOfMeasurement = 0,

        /// Other
        Other = 1,
    }

    impl std::fmt::Display for TowType {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TowType::TimeOfMeasurement => f.write_str("Time of Measurement"),
                TowType::Other => f.write_str("Other"),
            }
        }
    }

    impl TryFrom<u8> for TowType {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TowType::TimeOfMeasurement),
                1 => Ok(TowType::Other),
                i => Err(i),
            }
        }
    }

    /// Inertial Navigation Mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum InertialNavigationMode {
        /// None
        None = 0,

        /// INS used
        InsUsed = 1,
    }

    impl std::fmt::Display for InertialNavigationMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                InertialNavigationMode::None => f.write_str("None"),
                InertialNavigationMode::InsUsed => f.write_str("INS used"),
            }
        }
    }

    impl TryFrom<u8> for InertialNavigationMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(InertialNavigationMode::None),
                1 => Ok(InertialNavigationMode::InsUsed),
                i => Err(i),
            }
        }
    }

    /// Fix mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
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

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::Invalid => f.write_str("Invalid"),
                FixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
                FixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
                FixMode::FloatRtk => f.write_str("Float RTK"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
                FixMode::DeadReckoning => f.write_str("Dead Reckoning"),
                FixMode::SbasPosition => f.write_str("SBAS Position"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::Invalid),
                1 => Ok(FixMode::SinglePointPosition),
                2 => Ok(FixMode::DifferentialGnss),
                3 => Ok(FixMode::FloatRtk),
                4 => Ok(FixMode::FixedRtk),
                5 => Ok(FixMode::DeadReckoning),
                6 => Ok(FixMode::SbasPosition),
                i => Err(i),
            }
        }
    }
}

pub mod msg_pos_ecef_cov {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgPosEcefCov {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// ECEF X coordinate
        #[cfg_attr(feature = "serde", serde(rename = "x"))]
        pub x: f64,
        /// ECEF Y coordinate
        #[cfg_attr(feature = "serde", serde(rename = "y"))]
        pub y: f64,
        /// ECEF Z coordinate
        #[cfg_attr(feature = "serde", serde(rename = "z"))]
        pub z: f64,
        /// Estimated variance of x
        #[cfg_attr(feature = "serde", serde(rename = "cov_x_x"))]
        pub cov_x_x: f32,
        /// Estimated covariance of x and y
        #[cfg_attr(feature = "serde", serde(rename = "cov_x_y"))]
        pub cov_x_y: f32,
        /// Estimated covariance of x and z
        #[cfg_attr(feature = "serde", serde(rename = "cov_x_z"))]
        pub cov_x_z: f32,
        /// Estimated variance of y
        #[cfg_attr(feature = "serde", serde(rename = "cov_y_y"))]
        pub cov_y_y: f32,
        /// Estimated covariance of y and z
        #[cfg_attr(feature = "serde", serde(rename = "cov_y_z"))]
        pub cov_y_z: f32,
        /// Estimated variance of z
        #[cfg_attr(feature = "serde", serde(rename = "cov_z_z"))]
        pub cov_z_z: f32,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgPosEcefCov {
        /// Gets the [TypeOfReportedTow][self::TypeOfReportedTow] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TypeOfReportedTow` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TypeOfReportedTow` were added.
        pub fn type_of_reported_tow(&self) -> Result<TypeOfReportedTow, u8> {
            get_bit_range!(self.flags, u8, u8, 5, 5).try_into()
        }

        /// Set the bitrange corresponding to the [TypeOfReportedTow][TypeOfReportedTow] of the `flags` bitfield.
        pub fn set_type_of_reported_tow(&mut self, type_of_reported_tow: TypeOfReportedTow) {
            set_bit_range!(&mut self.flags, type_of_reported_tow, u8, u8, 5, 5);
        }

        /// Gets the [InertialNavigationMode][self::InertialNavigationMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `InertialNavigationMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `InertialNavigationMode` were added.
        pub fn inertial_navigation_mode(&self) -> Result<InertialNavigationMode, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 3).try_into()
        }

        /// Set the bitrange corresponding to the [InertialNavigationMode][InertialNavigationMode] of the `flags` bitfield.
        pub fn set_inertial_navigation_mode(
            &mut self,
            inertial_navigation_mode: InertialNavigationMode,
        ) {
            set_bit_range!(&mut self.flags, inertial_navigation_mode, u8, u8, 4, 3);
        }

        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TypeOfReportedTow {
        /// Time of Measurement
        TimeOfMeasurement = 0,

        /// Other
        Other = 1,
    }

    impl std::fmt::Display for TypeOfReportedTow {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
                TypeOfReportedTow::Other => f.write_str("Other"),
            }
        }
    }

    impl TryFrom<u8> for TypeOfReportedTow {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TypeOfReportedTow::TimeOfMeasurement),
                1 => Ok(TypeOfReportedTow::Other),
                i => Err(i),
            }
        }
    }

    /// Inertial Navigation Mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum InertialNavigationMode {
        /// None
        None = 0,

        /// INS used
        InsUsed = 1,
    }

    impl std::fmt::Display for InertialNavigationMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                InertialNavigationMode::None => f.write_str("None"),
                InertialNavigationMode::InsUsed => f.write_str("INS used"),
            }
        }
    }

    impl TryFrom<u8> for InertialNavigationMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(InertialNavigationMode::None),
                1 => Ok(InertialNavigationMode::InsUsed),
                i => Err(i),
            }
        }
    }

    /// Fix mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
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

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::Invalid => f.write_str("Invalid"),
                FixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
                FixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
                FixMode::FloatRtk => f.write_str("Float RTK"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
                FixMode::DeadReckoning => f.write_str("Dead Reckoning"),
                FixMode::SbasPosition => f.write_str("SBAS Position"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::Invalid),
                1 => Ok(FixMode::SinglePointPosition),
                2 => Ok(FixMode::DifferentialGnss),
                3 => Ok(FixMode::FloatRtk),
                4 => Ok(FixMode::FixedRtk),
                5 => Ok(FixMode::DeadReckoning),
                6 => Ok(FixMode::SbasPosition),
                i => Err(i),
            }
        }
    }
}

pub mod msg_pos_ecef_cov_gnss {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgPosEcefCovGnss {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// ECEF X coordinate
        #[cfg_attr(feature = "serde", serde(rename = "x"))]
        pub x: f64,
        /// ECEF Y coordinate
        #[cfg_attr(feature = "serde", serde(rename = "y"))]
        pub y: f64,
        /// ECEF Z coordinate
        #[cfg_attr(feature = "serde", serde(rename = "z"))]
        pub z: f64,
        /// Estimated variance of x
        #[cfg_attr(feature = "serde", serde(rename = "cov_x_x"))]
        pub cov_x_x: f32,
        /// Estimated covariance of x and y
        #[cfg_attr(feature = "serde", serde(rename = "cov_x_y"))]
        pub cov_x_y: f32,
        /// Estimated covariance of x and z
        #[cfg_attr(feature = "serde", serde(rename = "cov_x_z"))]
        pub cov_x_z: f32,
        /// Estimated variance of y
        #[cfg_attr(feature = "serde", serde(rename = "cov_y_y"))]
        pub cov_y_y: f32,
        /// Estimated covariance of y and z
        #[cfg_attr(feature = "serde", serde(rename = "cov_y_z"))]
        pub cov_y_z: f32,
        /// Estimated variance of z
        #[cfg_attr(feature = "serde", serde(rename = "cov_z_z"))]
        pub cov_z_z: f32,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgPosEcefCovGnss {
        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
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

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::Invalid => f.write_str("Invalid"),
                FixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
                FixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
                FixMode::FloatRtk => f.write_str("Float RTK"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
                FixMode::SbasPosition => f.write_str("SBAS Position"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::Invalid),
                1 => Ok(FixMode::SinglePointPosition),
                2 => Ok(FixMode::DifferentialGnss),
                3 => Ok(FixMode::FloatRtk),
                4 => Ok(FixMode::FixedRtk),
                6 => Ok(FixMode::SbasPosition),
                i => Err(i),
            }
        }
    }
}

pub mod msg_pos_ecef_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgPosEcefDepA {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// ECEF X coordinate
        #[cfg_attr(feature = "serde", serde(rename = "x"))]
        pub x: f64,
        /// ECEF Y coordinate
        #[cfg_attr(feature = "serde", serde(rename = "y"))]
        pub y: f64,
        /// ECEF Z coordinate
        #[cfg_attr(feature = "serde", serde(rename = "z"))]
        pub z: f64,
        /// Position accuracy estimate (not implemented). Defaults to 0.
        #[cfg_attr(feature = "serde", serde(rename = "accuracy"))]
        pub accuracy: u16,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgPosEcefDepA {
        /// Gets the [RaimRepairFlag][self::RaimRepairFlag] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `RaimRepairFlag` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `RaimRepairFlag` were added.
        pub fn raim_repair_flag(&self) -> Result<RaimRepairFlag, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 4).try_into()
        }

        /// Set the bitrange corresponding to the [RaimRepairFlag][RaimRepairFlag] of the `flags` bitfield.
        pub fn set_raim_repair_flag(&mut self, raim_repair_flag: RaimRepairFlag) {
            set_bit_range!(&mut self.flags, raim_repair_flag, u8, u8, 4, 4);
        }

        /// Gets the [RaimAvailabilityFlag][self::RaimAvailabilityFlag] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `RaimAvailabilityFlag` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `RaimAvailabilityFlag` were added.
        pub fn raim_availability_flag(&self) -> Result<RaimAvailabilityFlag, u8> {
            get_bit_range!(self.flags, u8, u8, 3, 3).try_into()
        }

        /// Set the bitrange corresponding to the [RaimAvailabilityFlag][RaimAvailabilityFlag] of the `flags` bitfield.
        pub fn set_raim_availability_flag(&mut self, raim_availability_flag: RaimAvailabilityFlag) {
            set_bit_range!(&mut self.flags, raim_availability_flag, u8, u8, 3, 3);
        }

        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum RaimRepairFlag {
        /// No repair
        NoRepair = 0,

        /// Solution came from RAIM repair
        SolutionCameFromRaimRepair = 1,
    }

    impl std::fmt::Display for RaimRepairFlag {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                RaimRepairFlag::NoRepair => f.write_str("No repair"),
                RaimRepairFlag::SolutionCameFromRaimRepair => {
                    f.write_str("Solution came from RAIM repair")
                }
            }
        }
    }

    impl TryFrom<u8> for RaimRepairFlag {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(RaimRepairFlag::NoRepair),
                1 => Ok(RaimRepairFlag::SolutionCameFromRaimRepair),
                i => Err(i),
            }
        }
    }

    /// RAIM availability flag
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum RaimAvailabilityFlag {
        /// RAIM check was explicitly disabled or unavailable
        RaimCheckWasExplicitlyDisabledOrUnavailable = 0,

        /// RAIM check was available
        RaimCheckWasAvailable = 1,
    }

    impl std::fmt::Display for RaimAvailabilityFlag {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                RaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable => {
                    f.write_str("RAIM check was explicitly disabled or unavailable")
                }
                RaimAvailabilityFlag::RaimCheckWasAvailable => {
                    f.write_str("RAIM check was available")
                }
            }
        }
    }

    impl TryFrom<u8> for RaimAvailabilityFlag {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(RaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable),
                1 => Ok(RaimAvailabilityFlag::RaimCheckWasAvailable),
                i => Err(i),
            }
        }
    }

    /// Fix mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
        /// Single Point Positioning (SPP)
        SinglePointPositioning = 0,

        /// Fixed RTK
        FixedRtk = 1,

        /// Float RTK
        FloatRtk = 2,
    }

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::SinglePointPositioning => f.write_str("Single Point Positioning (SPP)"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
                FixMode::FloatRtk => f.write_str("Float RTK"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::SinglePointPositioning),
                1 => Ok(FixMode::FixedRtk),
                2 => Ok(FixMode::FloatRtk),
                i => Err(i),
            }
        }
    }
}

pub mod msg_pos_ecef_gnss {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgPosEcefGnss {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// ECEF X coordinate
        #[cfg_attr(feature = "serde", serde(rename = "x"))]
        pub x: f64,
        /// ECEF Y coordinate
        #[cfg_attr(feature = "serde", serde(rename = "y"))]
        pub y: f64,
        /// ECEF Z coordinate
        #[cfg_attr(feature = "serde", serde(rename = "z"))]
        pub z: f64,
        /// Position estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "accuracy"))]
        pub accuracy: u16,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgPosEcefGnss {
        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
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

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::Invalid => f.write_str("Invalid"),
                FixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
                FixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
                FixMode::FloatRtk => f.write_str("Float RTK"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
                FixMode::SbasPosition => f.write_str("SBAS Position"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::Invalid),
                1 => Ok(FixMode::SinglePointPosition),
                2 => Ok(FixMode::DifferentialGnss),
                3 => Ok(FixMode::FloatRtk),
                4 => Ok(FixMode::FixedRtk),
                6 => Ok(FixMode::SbasPosition),
                i => Err(i),
            }
        }
    }
}

pub mod msg_pos_llh {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgPosLlh {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Latitude
        #[cfg_attr(feature = "serde", serde(rename = "lat"))]
        pub lat: f64,
        /// Longitude
        #[cfg_attr(feature = "serde", serde(rename = "lon"))]
        pub lon: f64,
        /// Height above WGS84 ellipsoid
        #[cfg_attr(feature = "serde", serde(rename = "height"))]
        pub height: f64,
        /// Horizontal position estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "h_accuracy"))]
        pub h_accuracy: u16,
        /// Vertical position estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "v_accuracy"))]
        pub v_accuracy: u16,
        /// Number of satellites used in solution.
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgPosLlh {
        /// Gets the [TypeOfReportedTow][self::TypeOfReportedTow] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TypeOfReportedTow` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TypeOfReportedTow` were added.
        pub fn type_of_reported_tow(&self) -> Result<TypeOfReportedTow, u8> {
            get_bit_range!(self.flags, u8, u8, 5, 5).try_into()
        }

        /// Set the bitrange corresponding to the [TypeOfReportedTow][TypeOfReportedTow] of the `flags` bitfield.
        pub fn set_type_of_reported_tow(&mut self, type_of_reported_tow: TypeOfReportedTow) {
            set_bit_range!(&mut self.flags, type_of_reported_tow, u8, u8, 5, 5);
        }

        /// Gets the [InertialNavigationMode][self::InertialNavigationMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `InertialNavigationMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `InertialNavigationMode` were added.
        pub fn inertial_navigation_mode(&self) -> Result<InertialNavigationMode, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 3).try_into()
        }

        /// Set the bitrange corresponding to the [InertialNavigationMode][InertialNavigationMode] of the `flags` bitfield.
        pub fn set_inertial_navigation_mode(
            &mut self,
            inertial_navigation_mode: InertialNavigationMode,
        ) {
            set_bit_range!(&mut self.flags, inertial_navigation_mode, u8, u8, 4, 3);
        }

        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TypeOfReportedTow {
        /// Time of Measurement
        TimeOfMeasurement = 0,

        /// Other
        Other = 1,
    }

    impl std::fmt::Display for TypeOfReportedTow {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
                TypeOfReportedTow::Other => f.write_str("Other"),
            }
        }
    }

    impl TryFrom<u8> for TypeOfReportedTow {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TypeOfReportedTow::TimeOfMeasurement),
                1 => Ok(TypeOfReportedTow::Other),
                i => Err(i),
            }
        }
    }

    /// Inertial Navigation Mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum InertialNavigationMode {
        /// None
        None = 0,

        /// INS used
        InsUsed = 1,
    }

    impl std::fmt::Display for InertialNavigationMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                InertialNavigationMode::None => f.write_str("None"),
                InertialNavigationMode::InsUsed => f.write_str("INS used"),
            }
        }
    }

    impl TryFrom<u8> for InertialNavigationMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(InertialNavigationMode::None),
                1 => Ok(InertialNavigationMode::InsUsed),
                i => Err(i),
            }
        }
    }

    /// Fix mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
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

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::Invalid => f.write_str("Invalid"),
                FixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
                FixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
                FixMode::FloatRtk => f.write_str("Float RTK"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
                FixMode::DeadReckoning => f.write_str("Dead Reckoning"),
                FixMode::SbasPosition => f.write_str("SBAS Position"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::Invalid),
                1 => Ok(FixMode::SinglePointPosition),
                2 => Ok(FixMode::DifferentialGnss),
                3 => Ok(FixMode::FloatRtk),
                4 => Ok(FixMode::FixedRtk),
                5 => Ok(FixMode::DeadReckoning),
                6 => Ok(FixMode::SbasPosition),
                i => Err(i),
            }
        }
    }
}

pub mod msg_pos_llh_acc {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgPosLlhAcc {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Latitude
        #[cfg_attr(feature = "serde", serde(rename = "lat"))]
        pub lat: f64,
        /// Longitude
        #[cfg_attr(feature = "serde", serde(rename = "lon"))]
        pub lon: f64,
        /// Height above WGS84 ellipsoid
        #[cfg_attr(feature = "serde", serde(rename = "height"))]
        pub height: f64,
        /// Height above the geoid (i.e. height above mean sea level). See
        /// confidence_and_geoid for geoid model used.
        #[cfg_attr(feature = "serde", serde(rename = "orthometric_height"))]
        pub orthometric_height: f64,
        /// Estimated horizontal error at the user-configured confidence level; zero
        /// implies invalid.
        #[cfg_attr(feature = "serde", serde(rename = "h_accuracy"))]
        pub h_accuracy: f32,
        /// Estimated vertical error at the user-configured confidence level; zero
        /// implies invalid.
        #[cfg_attr(feature = "serde", serde(rename = "v_accuracy"))]
        pub v_accuracy: f32,
        /// Estimated cross-track error at the user-configured confidence level;
        /// zero implies invalid.
        #[cfg_attr(feature = "serde", serde(rename = "ct_accuracy"))]
        pub ct_accuracy: f32,
        /// Estimated along-track error at the user-configured confidence level;
        /// zero implies invalid.
        #[cfg_attr(feature = "serde", serde(rename = "at_accuracy"))]
        pub at_accuracy: f32,
        /// The estimated horizontal error ellipse at the user-configured confidence
        /// level.
        #[cfg_attr(feature = "serde", serde(rename = "h_ellipse"))]
        pub h_ellipse: EstimatedHorizontalErrorEllipse,
        /// The lower bits describe the configured confidence level for the
        /// estimated position error. The middle bits describe the geoid model used
        /// to calculate the orthometric height.
        #[cfg_attr(feature = "serde", serde(rename = "confidence_and_geoid"))]
        pub confidence_and_geoid: u8,
        /// Number of satellites used in solution.
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgPosLlhAcc {
        /// Gets the [GeoidModel][self::GeoidModel] stored in the `confidence_and_geoid` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `GeoidModel` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `GeoidModel` were added.
        pub fn geoid_model(&self) -> Result<GeoidModel, u8> {
            get_bit_range!(self.confidence_and_geoid, u8, u8, 6, 4).try_into()
        }

        /// Set the bitrange corresponding to the [GeoidModel][GeoidModel] of the `confidence_and_geoid` bitfield.
        pub fn set_geoid_model(&mut self, geoid_model: GeoidModel) {
            set_bit_range!(&mut self.confidence_and_geoid, geoid_model, u8, u8, 6, 4);
        }

        /// Gets the [ConfidenceLevel][self::ConfidenceLevel] stored in the `confidence_and_geoid` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `ConfidenceLevel` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `ConfidenceLevel` were added.
        pub fn confidence_level(&self) -> Result<ConfidenceLevel, u8> {
            get_bit_range!(self.confidence_and_geoid, u8, u8, 3, 0).try_into()
        }

        /// Set the bitrange corresponding to the [ConfidenceLevel][ConfidenceLevel] of the `confidence_and_geoid` bitfield.
        pub fn set_confidence_level(&mut self, confidence_level: ConfidenceLevel) {
            set_bit_range!(
                &mut self.confidence_and_geoid,
                confidence_level,
                u8,
                u8,
                3,
                0
            );
        }

        /// Gets the [TypeOfReportedTow][self::TypeOfReportedTow] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TypeOfReportedTow` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TypeOfReportedTow` were added.
        pub fn type_of_reported_tow(&self) -> Result<TypeOfReportedTow, u8> {
            get_bit_range!(self.flags, u8, u8, 5, 5).try_into()
        }

        /// Set the bitrange corresponding to the [TypeOfReportedTow][TypeOfReportedTow] of the `flags` bitfield.
        pub fn set_type_of_reported_tow(&mut self, type_of_reported_tow: TypeOfReportedTow) {
            set_bit_range!(&mut self.flags, type_of_reported_tow, u8, u8, 5, 5);
        }

        /// Gets the [InertialNavigationMode][self::InertialNavigationMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `InertialNavigationMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `InertialNavigationMode` were added.
        pub fn inertial_navigation_mode(&self) -> Result<InertialNavigationMode, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 3).try_into()
        }

        /// Set the bitrange corresponding to the [InertialNavigationMode][InertialNavigationMode] of the `flags` bitfield.
        pub fn set_inertial_navigation_mode(
            &mut self,
            inertial_navigation_mode: InertialNavigationMode,
        ) {
            set_bit_range!(&mut self.flags, inertial_navigation_mode, u8, u8, 4, 3);
        }

        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum GeoidModel {
        /// No model
        NoModel = 0,

        /// EGM96
        EGM96 = 1,

        /// EGM2008
        EGM2008 = 2,
    }

    impl std::fmt::Display for GeoidModel {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                GeoidModel::NoModel => f.write_str("No model"),
                GeoidModel::EGM96 => f.write_str("EGM96"),
                GeoidModel::EGM2008 => f.write_str("EGM2008"),
            }
        }
    }

    impl TryFrom<u8> for GeoidModel {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(GeoidModel::NoModel),
                1 => Ok(GeoidModel::EGM96),
                2 => Ok(GeoidModel::EGM2008),
                i => Err(i),
            }
        }
    }

    /// Confidence level
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum ConfidenceLevel {
        /// 39.35%
        _3935 = 1,

        /// 68.27%
        _6827 = 2,

        /// 95.45%
        _9545 = 3,
    }

    impl std::fmt::Display for ConfidenceLevel {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                ConfidenceLevel::_3935 => f.write_str("39.35%"),
                ConfidenceLevel::_6827 => f.write_str("68.27%"),
                ConfidenceLevel::_9545 => f.write_str("95.45%"),
            }
        }
    }

    impl TryFrom<u8> for ConfidenceLevel {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                1 => Ok(ConfidenceLevel::_3935),
                2 => Ok(ConfidenceLevel::_6827),
                3 => Ok(ConfidenceLevel::_9545),
                i => Err(i),
            }
        }
    }

    /// Type of reported TOW
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TypeOfReportedTow {
        /// Time of Measurement
        TimeOfMeasurement = 0,

        /// Other
        Other = 1,
    }

    impl std::fmt::Display for TypeOfReportedTow {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
                TypeOfReportedTow::Other => f.write_str("Other"),
            }
        }
    }

    impl TryFrom<u8> for TypeOfReportedTow {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TypeOfReportedTow::TimeOfMeasurement),
                1 => Ok(TypeOfReportedTow::Other),
                i => Err(i),
            }
        }
    }

    /// Inertial Navigation Mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum InertialNavigationMode {
        /// None
        None = 0,

        /// INS used
        InsUsed = 1,
    }

    impl std::fmt::Display for InertialNavigationMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                InertialNavigationMode::None => f.write_str("None"),
                InertialNavigationMode::InsUsed => f.write_str("INS used"),
            }
        }
    }

    impl TryFrom<u8> for InertialNavigationMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(InertialNavigationMode::None),
                1 => Ok(InertialNavigationMode::InsUsed),
                i => Err(i),
            }
        }
    }

    /// Fix mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
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

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::Invalid => f.write_str("Invalid"),
                FixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
                FixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
                FixMode::FloatRtk => f.write_str("Float RTK"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
                FixMode::DeadReckoning => f.write_str("Dead Reckoning"),
                FixMode::SbasPosition => f.write_str("SBAS Position"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::Invalid),
                1 => Ok(FixMode::SinglePointPosition),
                2 => Ok(FixMode::DifferentialGnss),
                3 => Ok(FixMode::FloatRtk),
                4 => Ok(FixMode::FixedRtk),
                5 => Ok(FixMode::DeadReckoning),
                6 => Ok(FixMode::SbasPosition),
                i => Err(i),
            }
        }
    }
}

pub mod msg_pos_llh_cov {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgPosLlhCov {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Latitude
        #[cfg_attr(feature = "serde", serde(rename = "lat"))]
        pub lat: f64,
        /// Longitude
        #[cfg_attr(feature = "serde", serde(rename = "lon"))]
        pub lon: f64,
        /// Height above WGS84 ellipsoid
        #[cfg_attr(feature = "serde", serde(rename = "height"))]
        pub height: f64,
        /// Estimated variance of northing
        #[cfg_attr(feature = "serde", serde(rename = "cov_n_n"))]
        pub cov_n_n: f32,
        /// Covariance of northing and easting
        #[cfg_attr(feature = "serde", serde(rename = "cov_n_e"))]
        pub cov_n_e: f32,
        /// Covariance of northing and downward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_n_d"))]
        pub cov_n_d: f32,
        /// Estimated variance of easting
        #[cfg_attr(feature = "serde", serde(rename = "cov_e_e"))]
        pub cov_e_e: f32,
        /// Covariance of easting and downward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_e_d"))]
        pub cov_e_d: f32,
        /// Estimated variance of downward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_d_d"))]
        pub cov_d_d: f32,
        /// Number of satellites used in solution.
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgPosLlhCov {
        /// Gets the [TypeOfReportedTow][self::TypeOfReportedTow] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TypeOfReportedTow` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TypeOfReportedTow` were added.
        pub fn type_of_reported_tow(&self) -> Result<TypeOfReportedTow, u8> {
            get_bit_range!(self.flags, u8, u8, 5, 5).try_into()
        }

        /// Set the bitrange corresponding to the [TypeOfReportedTow][TypeOfReportedTow] of the `flags` bitfield.
        pub fn set_type_of_reported_tow(&mut self, type_of_reported_tow: TypeOfReportedTow) {
            set_bit_range!(&mut self.flags, type_of_reported_tow, u8, u8, 5, 5);
        }

        /// Gets the [InertialNavigationMode][self::InertialNavigationMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `InertialNavigationMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `InertialNavigationMode` were added.
        pub fn inertial_navigation_mode(&self) -> Result<InertialNavigationMode, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 3).try_into()
        }

        /// Set the bitrange corresponding to the [InertialNavigationMode][InertialNavigationMode] of the `flags` bitfield.
        pub fn set_inertial_navigation_mode(
            &mut self,
            inertial_navigation_mode: InertialNavigationMode,
        ) {
            set_bit_range!(&mut self.flags, inertial_navigation_mode, u8, u8, 4, 3);
        }

        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TypeOfReportedTow {
        /// Time of Measurement
        TimeOfMeasurement = 0,

        /// Other
        Other = 1,
    }

    impl std::fmt::Display for TypeOfReportedTow {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
                TypeOfReportedTow::Other => f.write_str("Other"),
            }
        }
    }

    impl TryFrom<u8> for TypeOfReportedTow {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TypeOfReportedTow::TimeOfMeasurement),
                1 => Ok(TypeOfReportedTow::Other),
                i => Err(i),
            }
        }
    }

    /// Inertial Navigation Mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum InertialNavigationMode {
        /// None
        None = 0,

        /// INS used
        InsUsed = 1,
    }

    impl std::fmt::Display for InertialNavigationMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                InertialNavigationMode::None => f.write_str("None"),
                InertialNavigationMode::InsUsed => f.write_str("INS used"),
            }
        }
    }

    impl TryFrom<u8> for InertialNavigationMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(InertialNavigationMode::None),
                1 => Ok(InertialNavigationMode::InsUsed),
                i => Err(i),
            }
        }
    }

    /// Fix mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
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

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::Invalid => f.write_str("Invalid"),
                FixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
                FixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
                FixMode::FloatRtk => f.write_str("Float RTK"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
                FixMode::DeadReckoning => f.write_str("Dead Reckoning"),
                FixMode::SbasPosition => f.write_str("SBAS Position"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::Invalid),
                1 => Ok(FixMode::SinglePointPosition),
                2 => Ok(FixMode::DifferentialGnss),
                3 => Ok(FixMode::FloatRtk),
                4 => Ok(FixMode::FixedRtk),
                5 => Ok(FixMode::DeadReckoning),
                6 => Ok(FixMode::SbasPosition),
                i => Err(i),
            }
        }
    }
}

pub mod msg_pos_llh_cov_gnss {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgPosLlhCovGnss {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Latitude
        #[cfg_attr(feature = "serde", serde(rename = "lat"))]
        pub lat: f64,
        /// Longitude
        #[cfg_attr(feature = "serde", serde(rename = "lon"))]
        pub lon: f64,
        /// Height above WGS84 ellipsoid
        #[cfg_attr(feature = "serde", serde(rename = "height"))]
        pub height: f64,
        /// Estimated variance of northing
        #[cfg_attr(feature = "serde", serde(rename = "cov_n_n"))]
        pub cov_n_n: f32,
        /// Covariance of northing and easting
        #[cfg_attr(feature = "serde", serde(rename = "cov_n_e"))]
        pub cov_n_e: f32,
        /// Covariance of northing and downward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_n_d"))]
        pub cov_n_d: f32,
        /// Estimated variance of easting
        #[cfg_attr(feature = "serde", serde(rename = "cov_e_e"))]
        pub cov_e_e: f32,
        /// Covariance of easting and downward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_e_d"))]
        pub cov_e_d: f32,
        /// Estimated variance of downward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_d_d"))]
        pub cov_d_d: f32,
        /// Number of satellites used in solution.
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgPosLlhCovGnss {
        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
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

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::Invalid => f.write_str("Invalid"),
                FixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
                FixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
                FixMode::FloatRtk => f.write_str("Float RTK"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
                FixMode::DeadReckoning => f.write_str("Dead Reckoning"),
                FixMode::SbasPosition => f.write_str("SBAS Position"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::Invalid),
                1 => Ok(FixMode::SinglePointPosition),
                2 => Ok(FixMode::DifferentialGnss),
                3 => Ok(FixMode::FloatRtk),
                4 => Ok(FixMode::FixedRtk),
                5 => Ok(FixMode::DeadReckoning),
                6 => Ok(FixMode::SbasPosition),
                i => Err(i),
            }
        }
    }
}

pub mod msg_pos_llh_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgPosLlhDepA {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Latitude
        #[cfg_attr(feature = "serde", serde(rename = "lat"))]
        pub lat: f64,
        /// Longitude
        #[cfg_attr(feature = "serde", serde(rename = "lon"))]
        pub lon: f64,
        /// Height
        #[cfg_attr(feature = "serde", serde(rename = "height"))]
        pub height: f64,
        /// Horizontal position accuracy estimate (not implemented). Defaults to 0.
        #[cfg_attr(feature = "serde", serde(rename = "h_accuracy"))]
        pub h_accuracy: u16,
        /// Vertical position accuracy estimate (not implemented). Defaults to 0.
        #[cfg_attr(feature = "serde", serde(rename = "v_accuracy"))]
        pub v_accuracy: u16,
        /// Number of satellites used in solution.
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgPosLlhDepA {
        /// Gets the [RaimRepairFlag][self::RaimRepairFlag] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `RaimRepairFlag` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `RaimRepairFlag` were added.
        pub fn raim_repair_flag(&self) -> Result<RaimRepairFlag, u8> {
            get_bit_range!(self.flags, u8, u8, 5, 5).try_into()
        }

        /// Set the bitrange corresponding to the [RaimRepairFlag][RaimRepairFlag] of the `flags` bitfield.
        pub fn set_raim_repair_flag(&mut self, raim_repair_flag: RaimRepairFlag) {
            set_bit_range!(&mut self.flags, raim_repair_flag, u8, u8, 5, 5);
        }

        /// Gets the [RaimAvailabilityFlag][self::RaimAvailabilityFlag] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `RaimAvailabilityFlag` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `RaimAvailabilityFlag` were added.
        pub fn raim_availability_flag(&self) -> Result<RaimAvailabilityFlag, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 4).try_into()
        }

        /// Set the bitrange corresponding to the [RaimAvailabilityFlag][RaimAvailabilityFlag] of the `flags` bitfield.
        pub fn set_raim_availability_flag(&mut self, raim_availability_flag: RaimAvailabilityFlag) {
            set_bit_range!(&mut self.flags, raim_availability_flag, u8, u8, 4, 4);
        }

        /// Gets the [HeightMode][self::HeightMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `HeightMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `HeightMode` were added.
        pub fn height_mode(&self) -> Result<HeightMode, u8> {
            get_bit_range!(self.flags, u8, u8, 3, 3).try_into()
        }

        /// Set the bitrange corresponding to the [HeightMode][HeightMode] of the `flags` bitfield.
        pub fn set_height_mode(&mut self, height_mode: HeightMode) {
            set_bit_range!(&mut self.flags, height_mode, u8, u8, 3, 3);
        }

        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum RaimRepairFlag {
        /// No repair
        NoRepair = 0,

        /// Solution came from RAIM repair
        SolutionCameFromRaimRepair = 1,
    }

    impl std::fmt::Display for RaimRepairFlag {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                RaimRepairFlag::NoRepair => f.write_str("No repair"),
                RaimRepairFlag::SolutionCameFromRaimRepair => {
                    f.write_str("Solution came from RAIM repair")
                }
            }
        }
    }

    impl TryFrom<u8> for RaimRepairFlag {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(RaimRepairFlag::NoRepair),
                1 => Ok(RaimRepairFlag::SolutionCameFromRaimRepair),
                i => Err(i),
            }
        }
    }

    /// RAIM availability flag
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum RaimAvailabilityFlag {
        /// RAIM check was explicitly disabled or unavailable
        RaimCheckWasExplicitlyDisabledOrUnavailable = 0,

        /// RAIM check was available
        RaimCheckWasAvailable = 1,
    }

    impl std::fmt::Display for RaimAvailabilityFlag {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                RaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable => {
                    f.write_str("RAIM check was explicitly disabled or unavailable")
                }
                RaimAvailabilityFlag::RaimCheckWasAvailable => {
                    f.write_str("RAIM check was available")
                }
            }
        }
    }

    impl TryFrom<u8> for RaimAvailabilityFlag {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(RaimAvailabilityFlag::RaimCheckWasExplicitlyDisabledOrUnavailable),
                1 => Ok(RaimAvailabilityFlag::RaimCheckWasAvailable),
                i => Err(i),
            }
        }
    }

    /// Height Mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum HeightMode {
        /// Height above WGS84 ellipsoid
        HeightAboveWgs84Ellipsoid = 0,

        /// Height above mean sea level
        HeightAboveMeanSeaLevel = 1,
    }

    impl std::fmt::Display for HeightMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                HeightMode::HeightAboveWgs84Ellipsoid => {
                    f.write_str("Height above WGS84 ellipsoid")
                }
                HeightMode::HeightAboveMeanSeaLevel => f.write_str("Height above mean sea level"),
            }
        }
    }

    impl TryFrom<u8> for HeightMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(HeightMode::HeightAboveWgs84Ellipsoid),
                1 => Ok(HeightMode::HeightAboveMeanSeaLevel),
                i => Err(i),
            }
        }
    }

    /// Fix mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
        /// Single Point Positioning (SPP)
        SinglePointPositioning = 0,

        /// Fixed RTK
        FixedRtk = 1,

        /// Float RTK
        FloatRtk = 2,
    }

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::SinglePointPositioning => f.write_str("Single Point Positioning (SPP)"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
                FixMode::FloatRtk => f.write_str("Float RTK"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::SinglePointPositioning),
                1 => Ok(FixMode::FixedRtk),
                2 => Ok(FixMode::FloatRtk),
                i => Err(i),
            }
        }
    }
}

pub mod msg_pos_llh_gnss {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgPosLlhGnss {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Latitude
        #[cfg_attr(feature = "serde", serde(rename = "lat"))]
        pub lat: f64,
        /// Longitude
        #[cfg_attr(feature = "serde", serde(rename = "lon"))]
        pub lon: f64,
        /// Height above WGS84 ellipsoid
        #[cfg_attr(feature = "serde", serde(rename = "height"))]
        pub height: f64,
        /// Horizontal position estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "h_accuracy"))]
        pub h_accuracy: u16,
        /// Vertical position estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "v_accuracy"))]
        pub v_accuracy: u16,
        /// Number of satellites used in solution.
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgPosLlhGnss {
        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
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

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::Invalid => f.write_str("Invalid"),
                FixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
                FixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
                FixMode::FloatRtk => f.write_str("Float RTK"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
                FixMode::SbasPosition => f.write_str("SBAS Position"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::Invalid),
                1 => Ok(FixMode::SinglePointPosition),
                2 => Ok(FixMode::DifferentialGnss),
                3 => Ok(FixMode::FloatRtk),
                4 => Ok(FixMode::FixedRtk),
                6 => Ok(FixMode::SbasPosition),
                i => Err(i),
            }
        }
    }
}

pub mod msg_protection_level {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Computed state and Protection Levels
    ///
    /// This message reports the protection levels associated to the given state
    /// estimate. The full GPS time is given by the preceding MSG_GPS_TIME with
    /// the matching time-of-week (tow).
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgProtectionLevel {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// GPS week number
        #[cfg_attr(feature = "serde", serde(rename = "wn"))]
        pub wn: i16,
        /// Horizontal protection level
        #[cfg_attr(feature = "serde", serde(rename = "hpl"))]
        pub hpl: u16,
        /// Vertical protection level
        #[cfg_attr(feature = "serde", serde(rename = "vpl"))]
        pub vpl: u16,
        /// Along-track position error protection level
        #[cfg_attr(feature = "serde", serde(rename = "atpl"))]
        pub atpl: u16,
        /// Cross-track position error protection level
        #[cfg_attr(feature = "serde", serde(rename = "ctpl"))]
        pub ctpl: u16,
        /// Protection level for the error vector between estimated and true
        /// along/cross track velocity vector
        #[cfg_attr(feature = "serde", serde(rename = "hvpl"))]
        pub hvpl: u16,
        /// Protection level for the velocity in vehicle upright direction
        /// (different from vertical direction if on a slope)
        #[cfg_attr(feature = "serde", serde(rename = "vvpl"))]
        pub vvpl: u16,
        /// Heading orientation protection level
        #[cfg_attr(feature = "serde", serde(rename = "hopl"))]
        pub hopl: u16,
        /// Pitch orientation protection level
        #[cfg_attr(feature = "serde", serde(rename = "popl"))]
        pub popl: u16,
        /// Roll orientation protection level
        #[cfg_attr(feature = "serde", serde(rename = "ropl"))]
        pub ropl: u16,
        /// Latitude
        #[cfg_attr(feature = "serde", serde(rename = "lat"))]
        pub lat: f64,
        /// Longitude
        #[cfg_attr(feature = "serde", serde(rename = "lon"))]
        pub lon: f64,
        /// Height
        #[cfg_attr(feature = "serde", serde(rename = "height"))]
        pub height: f64,
        /// Velocity in vehicle x direction
        #[cfg_attr(feature = "serde", serde(rename = "v_x"))]
        pub v_x: i32,
        /// Velocity in vehicle y direction
        #[cfg_attr(feature = "serde", serde(rename = "v_y"))]
        pub v_y: i32,
        /// Velocity in vehicle z direction
        #[cfg_attr(feature = "serde", serde(rename = "v_z"))]
        pub v_z: i32,
        /// Roll angle
        #[cfg_attr(feature = "serde", serde(rename = "roll"))]
        pub roll: i32,
        /// Pitch angle
        #[cfg_attr(feature = "serde", serde(rename = "pitch"))]
        pub pitch: i32,
        /// Heading angle
        #[cfg_attr(feature = "serde", serde(rename = "heading"))]
        pub heading: i32,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u32,
    }

    impl MsgProtectionLevel {
        /// Gets the `target_integrity_risk_tir_level` stored in `flags`.
        pub fn target_integrity_risk_tir_level(&self) -> u8 {
            get_bit_range!(self.flags, u32, u8, 2, 0)
        }

        /// Sets the `target_integrity_risk_tir_level` bitrange of `flags`.
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

        /// Gets the [FixMode][self::FixMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FixMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FixMode` were added.
        pub fn fix_mode(&self) -> Result<FixMode, u8> {
            get_bit_range!(self.flags, u32, u8, 17, 15).try_into()
        }

        /// Set the bitrange corresponding to the [FixMode][FixMode] of the `flags` bitfield.
        pub fn set_fix_mode(&mut self, fix_mode: FixMode) {
            set_bit_range!(&mut self.flags, fix_mode, u32, u8, 17, 15);
        }

        /// Gets the [InertialNavigationMode][self::InertialNavigationMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `InertialNavigationMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `InertialNavigationMode` were added.
        pub fn inertial_navigation_mode(&self) -> Result<InertialNavigationMode, u8> {
            get_bit_range!(self.flags, u32, u8, 19, 18).try_into()
        }

        /// Set the bitrange corresponding to the [InertialNavigationMode][InertialNavigationMode] of the `flags` bitfield.
        pub fn set_inertial_navigation_mode(
            &mut self,
            inertial_navigation_mode: InertialNavigationMode,
        ) {
            set_bit_range!(&mut self.flags, inertial_navigation_mode, u32, u8, 19, 18);
        }

        /// Gets the [TimeStatus][self::TimeStatus] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TimeStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TimeStatus` were added.
        pub fn time_status(&self) -> Result<TimeStatus, u8> {
            get_bit_range!(self.flags, u32, u8, 20, 20).try_into()
        }

        /// Set the bitrange corresponding to the [TimeStatus][TimeStatus] of the `flags` bitfield.
        pub fn set_time_status(&mut self, time_status: TimeStatus) {
            set_bit_range!(&mut self.flags, time_status, u32, u8, 20, 20);
        }

        /// Gets the `velocity_valid` flag.
        pub fn velocity_valid(&self) -> bool {
            ((self.flags >> 21) & 1) == 1
        }

        /// Sets the `velocity_valid` flag.
        pub fn set_velocity_valid(&mut self, velocity_valid: bool) {
            self.flags ^= (!(velocity_valid as u32)) & (1 << 21)
        }

        /// Gets the `attitude_valid` flag.
        pub fn attitude_valid(&self) -> bool {
            ((self.flags >> 22) & 1) == 1
        }

        /// Sets the `attitude_valid` flag.
        pub fn set_attitude_valid(&mut self, attitude_valid: bool) {
            self.flags ^= (!(attitude_valid as u32)) & (1 << 22)
        }

        /// Gets the `safe_state_hpl` flag.
        pub fn safe_state_hpl(&self) -> bool {
            ((self.flags >> 23) & 1) == 1
        }

        /// Sets the `safe_state_hpl` flag.
        pub fn set_safe_state_hpl(&mut self, safe_state_hpl: bool) {
            self.flags ^= (!(safe_state_hpl as u32)) & (1 << 23)
        }

        /// Gets the `safe_state_vpl` flag.
        pub fn safe_state_vpl(&self) -> bool {
            ((self.flags >> 24) & 1) == 1
        }

        /// Sets the `safe_state_vpl` flag.
        pub fn set_safe_state_vpl(&mut self, safe_state_vpl: bool) {
            self.flags ^= (!(safe_state_vpl as u32)) & (1 << 24)
        }

        /// Gets the `safe_state_atpl` flag.
        pub fn safe_state_atpl(&self) -> bool {
            ((self.flags >> 25) & 1) == 1
        }

        /// Sets the `safe_state_atpl` flag.
        pub fn set_safe_state_atpl(&mut self, safe_state_atpl: bool) {
            self.flags ^= (!(safe_state_atpl as u32)) & (1 << 25)
        }

        /// Gets the `safe_state_ctpl` flag.
        pub fn safe_state_ctpl(&self) -> bool {
            ((self.flags >> 26) & 1) == 1
        }

        /// Sets the `safe_state_ctpl` flag.
        pub fn set_safe_state_ctpl(&mut self, safe_state_ctpl: bool) {
            self.flags ^= (!(safe_state_ctpl as u32)) & (1 << 26)
        }

        /// Gets the `safe_state_hvpl` flag.
        pub fn safe_state_hvpl(&self) -> bool {
            ((self.flags >> 27) & 1) == 1
        }

        /// Sets the `safe_state_hvpl` flag.
        pub fn set_safe_state_hvpl(&mut self, safe_state_hvpl: bool) {
            self.flags ^= (!(safe_state_hvpl as u32)) & (1 << 27)
        }

        /// Gets the `safe_state_vvpl` flag.
        pub fn safe_state_vvpl(&self) -> bool {
            ((self.flags >> 28) & 1) == 1
        }

        /// Sets the `safe_state_vvpl` flag.
        pub fn set_safe_state_vvpl(&mut self, safe_state_vvpl: bool) {
            self.flags ^= (!(safe_state_vvpl as u32)) & (1 << 28)
        }

        /// Gets the `safe_state_hopl` flag.
        pub fn safe_state_hopl(&self) -> bool {
            ((self.flags >> 29) & 1) == 1
        }

        /// Sets the `safe_state_hopl` flag.
        pub fn set_safe_state_hopl(&mut self, safe_state_hopl: bool) {
            self.flags ^= (!(safe_state_hopl as u32)) & (1 << 29)
        }

        /// Gets the `safe_state_popl` flag.
        pub fn safe_state_popl(&self) -> bool {
            ((self.flags >> 30) & 1) == 1
        }

        /// Sets the `safe_state_popl` flag.
        pub fn set_safe_state_popl(&mut self, safe_state_popl: bool) {
            self.flags ^= (!(safe_state_popl as u32)) & (1 << 30)
        }

        /// Gets the `safe_state_ropl` flag.
        pub fn safe_state_ropl(&self) -> bool {
            ((self.flags >> 31) & 1) == 1
        }

        /// Sets the `safe_state_ropl` flag.
        pub fn set_safe_state_ropl(&mut self, safe_state_ropl: bool) {
            self.flags ^= (!(safe_state_ropl as u32)) & (1 << 31)
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FixMode {
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

    impl std::fmt::Display for FixMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FixMode::Invalid => f.write_str("Invalid"),
                FixMode::SinglePointPosition => f.write_str("Single Point Position (SPP)"),
                FixMode::DifferentialGnss => f.write_str("Differential GNSS (DGNSS)"),
                FixMode::FloatRtk => f.write_str("Float RTK"),
                FixMode::FixedRtk => f.write_str("Fixed RTK"),
                FixMode::DeadReckoning => f.write_str("Dead Reckoning"),
                FixMode::SbasPosition => f.write_str("SBAS Position"),
            }
        }
    }

    impl TryFrom<u8> for FixMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FixMode::Invalid),
                1 => Ok(FixMode::SinglePointPosition),
                2 => Ok(FixMode::DifferentialGnss),
                3 => Ok(FixMode::FloatRtk),
                4 => Ok(FixMode::FixedRtk),
                5 => Ok(FixMode::DeadReckoning),
                6 => Ok(FixMode::SbasPosition),
                i => Err(i),
            }
        }
    }

    /// Inertial Navigation Mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum InertialNavigationMode {
        /// None
        None = 0,

        /// INS used
        InsUsed = 1,
    }

    impl std::fmt::Display for InertialNavigationMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                InertialNavigationMode::None => f.write_str("None"),
                InertialNavigationMode::InsUsed => f.write_str("INS used"),
            }
        }
    }

    impl TryFrom<u8> for InertialNavigationMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(InertialNavigationMode::None),
                1 => Ok(InertialNavigationMode::InsUsed),
                i => Err(i),
            }
        }
    }

    /// Time status
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TimeStatus {
        /// GNSS time of validity
        GnssTimeOfValidity = 0,

        /// Other
        Other = 1,
    }

    impl std::fmt::Display for TimeStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TimeStatus::GnssTimeOfValidity => f.write_str("GNSS time of validity"),
                TimeStatus::Other => f.write_str("Other"),
            }
        }
    }

    impl TryFrom<u8> for TimeStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TimeStatus::GnssTimeOfValidity),
                1 => Ok(TimeStatus::Other),
                i => Err(i),
            }
        }
    }
}

pub mod msg_protection_level_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Computed Position and Protection Level
    ///
    /// This message reports the local vertical and horizontal protection levels
    /// associated with a given LLH position solution. The full GPS time is given
    /// by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgProtectionLevelDepA {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Vertical protection level
        #[cfg_attr(feature = "serde", serde(rename = "vpl"))]
        pub vpl: u16,
        /// Horizontal protection level
        #[cfg_attr(feature = "serde", serde(rename = "hpl"))]
        pub hpl: u16,
        /// Latitude
        #[cfg_attr(feature = "serde", serde(rename = "lat"))]
        pub lat: f64,
        /// Longitude
        #[cfg_attr(feature = "serde", serde(rename = "lon"))]
        pub lon: f64,
        /// Height
        #[cfg_attr(feature = "serde", serde(rename = "height"))]
        pub height: f64,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgProtectionLevelDepA {
        /// Gets the [TargetIntegrityRiskTirLevel][self::TargetIntegrityRiskTirLevel] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TargetIntegrityRiskTirLevel` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TargetIntegrityRiskTirLevel` were added.
        pub fn target_integrity_risk_tir_level(&self) -> Result<TargetIntegrityRiskTirLevel, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [TargetIntegrityRiskTirLevel][TargetIntegrityRiskTirLevel] of the `flags` bitfield.
        pub fn set_target_integrity_risk_tir_level(
            &mut self,
            target_integrity_risk_tir_level: TargetIntegrityRiskTirLevel,
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TargetIntegrityRiskTirLevel {
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

    impl std::fmt::Display for TargetIntegrityRiskTirLevel {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
            TargetIntegrityRiskTirLevel::SafeStateProtectionLevelShallNotBeUsedForSafetyCriticalApplication => f.write_str("Safe state, protection level shall not be used for safety-critical application"),
            TargetIntegrityRiskTirLevel::TirLevel1 => f.write_str("TIR Level 1"),
            TargetIntegrityRiskTirLevel::TirLevel2 => f.write_str("TIR Level 2"),
            TargetIntegrityRiskTirLevel::TirLevel3 => f.write_str("TIR Level 3"),
        }
        }
    }

    impl TryFrom<u8> for TargetIntegrityRiskTirLevel {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
            0 => Ok( TargetIntegrityRiskTirLevel :: SafeStateProtectionLevelShallNotBeUsedForSafetyCriticalApplication ),
            1 => Ok( TargetIntegrityRiskTirLevel :: TirLevel1 ),
            2 => Ok( TargetIntegrityRiskTirLevel :: TirLevel2 ),
            3 => Ok( TargetIntegrityRiskTirLevel :: TirLevel3 ),
            i => Err(i),
        }
        }
    }
}

pub mod msg_reference_frame_param {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;
    /// Reference Frame Transformation Parameters
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgReferenceFrameParam {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// SSR IOD parameter.
        #[cfg_attr(feature = "serde", serde(rename = "ssr_iod"))]
        pub ssr_iod: u8,
        /// Name of source coordinate-system.
        #[cfg_attr(feature = "serde", serde(rename = "sn"))]
        pub sn: SbpString<[u8; 32], NullTerminated>,
        /// Name of target coordinate-system.
        #[cfg_attr(feature = "serde", serde(rename = "tn"))]
        pub tn: SbpString<[u8; 32], NullTerminated>,
        /// System Identification Number.
        #[cfg_attr(feature = "serde", serde(rename = "sin"))]
        pub sin: u8,
        /// Utilized Transformation Message.
        #[cfg_attr(feature = "serde", serde(rename = "utn"))]
        pub utn: u16,
        /// Reference Epoch t0 for transformation parameter set given as Modified
        /// Julian Day (MJD) Number minus 44244 days.
        #[cfg_attr(feature = "serde", serde(rename = "re_t0"))]
        pub re_t0: u16,
        /// Translation in X for Reference Epoch t0.
        #[cfg_attr(feature = "serde", serde(rename = "delta_X0"))]
        pub delta_x0: i32,
        /// Translation in Y for Reference Epoch t0.
        #[cfg_attr(feature = "serde", serde(rename = "delta_Y0"))]
        pub delta_y0: i32,
        /// Translation in Z for Reference Epoch t0.
        #[cfg_attr(feature = "serde", serde(rename = "delta_Z0"))]
        pub delta_z0: i32,
        /// Rotation around the X-axis for Reference Epoch t0.
        #[cfg_attr(feature = "serde", serde(rename = "theta_01"))]
        pub theta_01: i32,
        /// Rotation around the Y-axis for Reference Epoch t0.
        #[cfg_attr(feature = "serde", serde(rename = "theta_02"))]
        pub theta_02: i32,
        /// Rotation around the Z-axis for Reference Epoch t0.
        #[cfg_attr(feature = "serde", serde(rename = "theta_03"))]
        pub theta_03: i32,
        /// Scale correction for Reference Epoch t0.
        #[cfg_attr(feature = "serde", serde(rename = "scale"))]
        pub scale: i32,
        /// Rate of change of translation in X.
        #[cfg_attr(feature = "serde", serde(rename = "dot_delta_X0"))]
        pub dot_delta_x0: i32,
        /// Rate of change of translation in Y.
        #[cfg_attr(feature = "serde", serde(rename = "dot_delta_Y0"))]
        pub dot_delta_y0: i32,
        /// Rate of change of translation in Z.
        #[cfg_attr(feature = "serde", serde(rename = "dot_delta_Z0"))]
        pub dot_delta_z0: i32,
        /// Rate of change of rotation around the X-axis.
        #[cfg_attr(feature = "serde", serde(rename = "dot_theta_01"))]
        pub dot_theta_01: i32,
        /// Rate of change of rotation around the Y-axis.
        #[cfg_attr(feature = "serde", serde(rename = "dot_theta_02"))]
        pub dot_theta_02: i32,
        /// Rate of change of rotation around the Z-axis.
        #[cfg_attr(feature = "serde", serde(rename = "dot_theta_03"))]
        pub dot_theta_03: i32,
        /// Rate of change of scale correction.
        #[cfg_attr(feature = "serde", serde(rename = "dot_scale"))]
        pub dot_scale: i16,
    }

    impl ConcreteMessage for MsgReferenceFrameParam {
        const MESSAGE_TYPE: u16 = 580;
        const MESSAGE_NAME: &'static str = "MSG_REFERENCE_FRAME_PARAM";
    }

    impl SbpMessage for MsgReferenceFrameParam {
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
    }

    impl TryFrom<Sbp> for MsgReferenceFrameParam {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgReferenceFrameParam(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgReferenceFrameParam {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
            + <SbpString<[u8; 32], NullTerminated> as WireFormat>::MIN_LEN
            + <SbpString<[u8; 32], NullTerminated> as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i16 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.ssr_iod)
                + WireFormat::len(&self.sn)
                + WireFormat::len(&self.tn)
                + WireFormat::len(&self.sin)
                + WireFormat::len(&self.utn)
                + WireFormat::len(&self.re_t0)
                + WireFormat::len(&self.delta_x0)
                + WireFormat::len(&self.delta_y0)
                + WireFormat::len(&self.delta_z0)
                + WireFormat::len(&self.theta_01)
                + WireFormat::len(&self.theta_02)
                + WireFormat::len(&self.theta_03)
                + WireFormat::len(&self.scale)
                + WireFormat::len(&self.dot_delta_x0)
                + WireFormat::len(&self.dot_delta_y0)
                + WireFormat::len(&self.dot_delta_z0)
                + WireFormat::len(&self.dot_theta_01)
                + WireFormat::len(&self.dot_theta_02)
                + WireFormat::len(&self.dot_theta_03)
                + WireFormat::len(&self.dot_scale)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.ssr_iod, buf);
            WireFormat::write(&self.sn, buf);
            WireFormat::write(&self.tn, buf);
            WireFormat::write(&self.sin, buf);
            WireFormat::write(&self.utn, buf);
            WireFormat::write(&self.re_t0, buf);
            WireFormat::write(&self.delta_x0, buf);
            WireFormat::write(&self.delta_y0, buf);
            WireFormat::write(&self.delta_z0, buf);
            WireFormat::write(&self.theta_01, buf);
            WireFormat::write(&self.theta_02, buf);
            WireFormat::write(&self.theta_03, buf);
            WireFormat::write(&self.scale, buf);
            WireFormat::write(&self.dot_delta_x0, buf);
            WireFormat::write(&self.dot_delta_y0, buf);
            WireFormat::write(&self.dot_delta_z0, buf);
            WireFormat::write(&self.dot_theta_01, buf);
            WireFormat::write(&self.dot_theta_02, buf);
            WireFormat::write(&self.dot_theta_03, buf);
            WireFormat::write(&self.dot_scale, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgReferenceFrameParam {
                sender_id: None,
                ssr_iod: WireFormat::parse_unchecked(buf),
                sn: WireFormat::parse_unchecked(buf),
                tn: WireFormat::parse_unchecked(buf),
                sin: WireFormat::parse_unchecked(buf),
                utn: WireFormat::parse_unchecked(buf),
                re_t0: WireFormat::parse_unchecked(buf),
                delta_x0: WireFormat::parse_unchecked(buf),
                delta_y0: WireFormat::parse_unchecked(buf),
                delta_z0: WireFormat::parse_unchecked(buf),
                theta_01: WireFormat::parse_unchecked(buf),
                theta_02: WireFormat::parse_unchecked(buf),
                theta_03: WireFormat::parse_unchecked(buf),
                scale: WireFormat::parse_unchecked(buf),
                dot_delta_x0: WireFormat::parse_unchecked(buf),
                dot_delta_y0: WireFormat::parse_unchecked(buf),
                dot_delta_z0: WireFormat::parse_unchecked(buf),
                dot_theta_01: WireFormat::parse_unchecked(buf),
                dot_theta_02: WireFormat::parse_unchecked(buf),
                dot_theta_03: WireFormat::parse_unchecked(buf),
                dot_scale: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_utc_leap_second {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Leap second SBP message.

    ///
    /// UTC-GPST leap seconds before and after the most recent (past, or future,
    /// for announced insertions) UTC leap second insertion.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgUtcLeapSecond {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Reserved.
        #[cfg_attr(feature = "serde", serde(rename = "reserved_0"))]
        pub reserved_0: i16,
        /// Reserved.
        #[cfg_attr(feature = "serde", serde(rename = "reserved_1"))]
        pub reserved_1: i16,
        /// Reserved.
        #[cfg_attr(feature = "serde", serde(rename = "reserved_2"))]
        pub reserved_2: i8,
        /// Leap second count before insertion.
        #[cfg_attr(feature = "serde", serde(rename = "count_before"))]
        pub count_before: i8,
        /// Reserved.
        #[cfg_attr(feature = "serde", serde(rename = "reserved_3"))]
        pub reserved_3: u16,
        /// Reserved.
        #[cfg_attr(feature = "serde", serde(rename = "reserved_4"))]
        pub reserved_4: u16,
        /// Leap second reference GPS week number.
        #[cfg_attr(feature = "serde", serde(rename = "ref_wn"))]
        pub ref_wn: u16,
        /// Leap second reference day number.
        #[cfg_attr(feature = "serde", serde(rename = "ref_dn"))]
        pub ref_dn: u8,
        /// Leap second count after insertion.
        #[cfg_attr(feature = "serde", serde(rename = "count_after"))]
        pub count_after: i8,
    }

    impl ConcreteMessage for MsgUtcLeapSecond {
        const MESSAGE_TYPE: u16 = 570;
        const MESSAGE_NAME: &'static str = "MSG_UTC_LEAP_SECOND";
    }

    impl SbpMessage for MsgUtcLeapSecond {
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
    }

    impl TryFrom<Sbp> for MsgUtcLeapSecond {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgUtcLeapSecond(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgUtcLeapSecond {
        const MIN_LEN: usize = <i16 as WireFormat>::MIN_LEN
            + <i16 as WireFormat>::MIN_LEN
            + <i8 as WireFormat>::MIN_LEN
            + <i8 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <i8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.reserved_0)
                + WireFormat::len(&self.reserved_1)
                + WireFormat::len(&self.reserved_2)
                + WireFormat::len(&self.count_before)
                + WireFormat::len(&self.reserved_3)
                + WireFormat::len(&self.reserved_4)
                + WireFormat::len(&self.ref_wn)
                + WireFormat::len(&self.ref_dn)
                + WireFormat::len(&self.count_after)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.reserved_0, buf);
            WireFormat::write(&self.reserved_1, buf);
            WireFormat::write(&self.reserved_2, buf);
            WireFormat::write(&self.count_before, buf);
            WireFormat::write(&self.reserved_3, buf);
            WireFormat::write(&self.reserved_4, buf);
            WireFormat::write(&self.ref_wn, buf);
            WireFormat::write(&self.ref_dn, buf);
            WireFormat::write(&self.count_after, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgUtcLeapSecond {
                sender_id: None,
                reserved_0: WireFormat::parse_unchecked(buf),
                reserved_1: WireFormat::parse_unchecked(buf),
                reserved_2: WireFormat::parse_unchecked(buf),
                count_before: WireFormat::parse_unchecked(buf),
                reserved_3: WireFormat::parse_unchecked(buf),
                reserved_4: WireFormat::parse_unchecked(buf),
                ref_wn: WireFormat::parse_unchecked(buf),
                ref_dn: WireFormat::parse_unchecked(buf),
                count_after: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_utc_time {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// UTC Time
    ///
    /// This message reports the Universal Coordinated Time (UTC).  Note the flags
    /// which indicate the source of the UTC offset value and source of the time
    /// fix.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgUtcTime {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Indicates source and time validity
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
        /// GPS time of week rounded to the nearest millisecond
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Year
        #[cfg_attr(feature = "serde", serde(rename = "year"))]
        pub year: u16,
        /// Month (range 1 .. 12)
        #[cfg_attr(feature = "serde", serde(rename = "month"))]
        pub month: u8,
        /// days in the month (range 1-31)
        #[cfg_attr(feature = "serde", serde(rename = "day"))]
        pub day: u8,
        /// hours of day (range 0-23)
        #[cfg_attr(feature = "serde", serde(rename = "hours"))]
        pub hours: u8,
        /// minutes of hour (range 0-59)
        #[cfg_attr(feature = "serde", serde(rename = "minutes"))]
        pub minutes: u8,
        /// seconds of minute (range 0-60) rounded down
        #[cfg_attr(feature = "serde", serde(rename = "seconds"))]
        pub seconds: u8,
        /// nanoseconds of second (range 0-999999999)
        #[cfg_attr(feature = "serde", serde(rename = "ns"))]
        pub ns: u32,
    }

    impl MsgUtcTime {
        /// Gets the [UtcOffsetSource][self::UtcOffsetSource] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `UtcOffsetSource` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `UtcOffsetSource` were added.
        pub fn utc_offset_source(&self) -> Result<UtcOffsetSource, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 3).try_into()
        }

        /// Set the bitrange corresponding to the [UtcOffsetSource][UtcOffsetSource] of the `flags` bitfield.
        pub fn set_utc_offset_source(&mut self, utc_offset_source: UtcOffsetSource) {
            set_bit_range!(&mut self.flags, utc_offset_source, u8, u8, 4, 3);
        }

        /// Gets the [TimeSource][self::TimeSource] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TimeSource` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TimeSource` were added.
        pub fn time_source(&self) -> Result<TimeSource, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [TimeSource][TimeSource] of the `flags` bitfield.
        pub fn set_time_source(&mut self, time_source: TimeSource) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum UtcOffsetSource {
        /// Factory Default
        FactoryDefault = 0,

        /// Non Volatile Memory
        NonVolatileMemory = 1,

        /// Decoded this Session
        DecodedThisSession = 2,
    }

    impl std::fmt::Display for UtcOffsetSource {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                UtcOffsetSource::FactoryDefault => f.write_str("Factory Default"),
                UtcOffsetSource::NonVolatileMemory => f.write_str("Non Volatile Memory"),
                UtcOffsetSource::DecodedThisSession => f.write_str("Decoded this Session"),
            }
        }
    }

    impl TryFrom<u8> for UtcOffsetSource {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(UtcOffsetSource::FactoryDefault),
                1 => Ok(UtcOffsetSource::NonVolatileMemory),
                2 => Ok(UtcOffsetSource::DecodedThisSession),
                i => Err(i),
            }
        }
    }

    /// Time source
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TimeSource {
        /// None (invalid)
        None = 0,

        /// GNSS Solution
        GnssSolution = 1,

        /// Propagated
        Propagated = 2,
    }

    impl std::fmt::Display for TimeSource {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TimeSource::None => f.write_str("None (invalid)"),
                TimeSource::GnssSolution => f.write_str("GNSS Solution"),
                TimeSource::Propagated => f.write_str("Propagated"),
            }
        }
    }

    impl TryFrom<u8> for TimeSource {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TimeSource::None),
                1 => Ok(TimeSource::GnssSolution),
                2 => Ok(TimeSource::Propagated),
                i => Err(i),
            }
        }
    }
}

pub mod msg_utc_time_gnss {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// UTC Time
    ///
    /// This message reports the Universal Coordinated Time (UTC).  Note the flags
    /// which indicate the source of the UTC offset value and source of the time
    /// fix.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgUtcTimeGnss {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Indicates source and time validity
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
        /// GPS time of week rounded to the nearest millisecond
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Year
        #[cfg_attr(feature = "serde", serde(rename = "year"))]
        pub year: u16,
        /// Month (range 1 .. 12)
        #[cfg_attr(feature = "serde", serde(rename = "month"))]
        pub month: u8,
        /// days in the month (range 1-31)
        #[cfg_attr(feature = "serde", serde(rename = "day"))]
        pub day: u8,
        /// hours of day (range 0-23)
        #[cfg_attr(feature = "serde", serde(rename = "hours"))]
        pub hours: u8,
        /// minutes of hour (range 0-59)
        #[cfg_attr(feature = "serde", serde(rename = "minutes"))]
        pub minutes: u8,
        /// seconds of minute (range 0-60) rounded down
        #[cfg_attr(feature = "serde", serde(rename = "seconds"))]
        pub seconds: u8,
        /// nanoseconds of second (range 0-999999999)
        #[cfg_attr(feature = "serde", serde(rename = "ns"))]
        pub ns: u32,
    }

    impl MsgUtcTimeGnss {
        /// Gets the [UtcOffsetSource][self::UtcOffsetSource] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `UtcOffsetSource` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `UtcOffsetSource` were added.
        pub fn utc_offset_source(&self) -> Result<UtcOffsetSource, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 3).try_into()
        }

        /// Set the bitrange corresponding to the [UtcOffsetSource][UtcOffsetSource] of the `flags` bitfield.
        pub fn set_utc_offset_source(&mut self, utc_offset_source: UtcOffsetSource) {
            set_bit_range!(&mut self.flags, utc_offset_source, u8, u8, 4, 3);
        }

        /// Gets the [TimeSource][self::TimeSource] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TimeSource` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TimeSource` were added.
        pub fn time_source(&self) -> Result<TimeSource, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [TimeSource][TimeSource] of the `flags` bitfield.
        pub fn set_time_source(&mut self, time_source: TimeSource) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum UtcOffsetSource {
        /// Factory Default
        FactoryDefault = 0,

        /// Non Volatile Memory
        NonVolatileMemory = 1,

        /// Decoded this Session
        DecodedThisSession = 2,
    }

    impl std::fmt::Display for UtcOffsetSource {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                UtcOffsetSource::FactoryDefault => f.write_str("Factory Default"),
                UtcOffsetSource::NonVolatileMemory => f.write_str("Non Volatile Memory"),
                UtcOffsetSource::DecodedThisSession => f.write_str("Decoded this Session"),
            }
        }
    }

    impl TryFrom<u8> for UtcOffsetSource {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(UtcOffsetSource::FactoryDefault),
                1 => Ok(UtcOffsetSource::NonVolatileMemory),
                2 => Ok(UtcOffsetSource::DecodedThisSession),
                i => Err(i),
            }
        }
    }

    /// Time source
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TimeSource {
        /// None (invalid)
        None = 0,

        /// GNSS Solution
        GnssSolution = 1,

        /// Propagated
        Propagated = 2,
    }

    impl std::fmt::Display for TimeSource {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TimeSource::None => f.write_str("None (invalid)"),
                TimeSource::GnssSolution => f.write_str("GNSS Solution"),
                TimeSource::Propagated => f.write_str("Propagated"),
            }
        }
    }

    impl TryFrom<u8> for TimeSource {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TimeSource::None),
                1 => Ok(TimeSource::GnssSolution),
                2 => Ok(TimeSource::Propagated),
                i => Err(i),
            }
        }
    }
}

pub mod msg_vel_body {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgVelBody {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Velocity in x direction
        #[cfg_attr(feature = "serde", serde(rename = "x"))]
        pub x: i32,
        /// Velocity in y direction
        #[cfg_attr(feature = "serde", serde(rename = "y"))]
        pub y: i32,
        /// Velocity in z direction
        #[cfg_attr(feature = "serde", serde(rename = "z"))]
        pub z: i32,
        /// Estimated variance of x
        #[cfg_attr(feature = "serde", serde(rename = "cov_x_x"))]
        pub cov_x_x: f32,
        /// Covariance of x and y
        #[cfg_attr(feature = "serde", serde(rename = "cov_x_y"))]
        pub cov_x_y: f32,
        /// Covariance of x and z
        #[cfg_attr(feature = "serde", serde(rename = "cov_x_z"))]
        pub cov_x_z: f32,
        /// Estimated variance of y
        #[cfg_attr(feature = "serde", serde(rename = "cov_y_y"))]
        pub cov_y_y: f32,
        /// Covariance of y and z
        #[cfg_attr(feature = "serde", serde(rename = "cov_y_z"))]
        pub cov_y_z: f32,
        /// Estimated variance of z
        #[cfg_attr(feature = "serde", serde(rename = "cov_z_z"))]
        pub cov_z_z: f32,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgVelBody {
        /// Gets the [InsNavigationMode][self::InsNavigationMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `InsNavigationMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `InsNavigationMode` were added.
        pub fn ins_navigation_mode(&self) -> Result<InsNavigationMode, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 3).try_into()
        }

        /// Set the bitrange corresponding to the [InsNavigationMode][InsNavigationMode] of the `flags` bitfield.
        pub fn set_ins_navigation_mode(&mut self, ins_navigation_mode: InsNavigationMode) {
            set_bit_range!(&mut self.flags, ins_navigation_mode, u8, u8, 4, 3);
        }

        /// Gets the [VelocityMode][self::VelocityMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `VelocityMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `VelocityMode` were added.
        pub fn velocity_mode(&self) -> Result<VelocityMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [VelocityMode][VelocityMode] of the `flags` bitfield.
        pub fn set_velocity_mode(&mut self, velocity_mode: VelocityMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum InsNavigationMode {
        /// None
        None = 0,

        /// INS used
        InsUsed = 1,
    }

    impl std::fmt::Display for InsNavigationMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                InsNavigationMode::None => f.write_str("None"),
                InsNavigationMode::InsUsed => f.write_str("INS used"),
            }
        }
    }

    impl TryFrom<u8> for InsNavigationMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(InsNavigationMode::None),
                1 => Ok(InsNavigationMode::InsUsed),
                i => Err(i),
            }
        }
    }

    /// Velocity mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum VelocityMode {
        /// Invalid
        Invalid = 0,

        /// Measured Doppler derived
        MeasuredDopplerDerived = 1,

        /// Computed Doppler derived
        ComputedDopplerDerived = 2,

        /// Dead Reckoning
        DeadReckoning = 3,
    }

    impl std::fmt::Display for VelocityMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                VelocityMode::Invalid => f.write_str("Invalid"),
                VelocityMode::MeasuredDopplerDerived => f.write_str("Measured Doppler derived"),
                VelocityMode::ComputedDopplerDerived => f.write_str("Computed Doppler derived"),
                VelocityMode::DeadReckoning => f.write_str("Dead Reckoning"),
            }
        }
    }

    impl TryFrom<u8> for VelocityMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(VelocityMode::Invalid),
                1 => Ok(VelocityMode::MeasuredDopplerDerived),
                2 => Ok(VelocityMode::ComputedDopplerDerived),
                3 => Ok(VelocityMode::DeadReckoning),
                i => Err(i),
            }
        }
    }
}

pub mod msg_vel_cog {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgVelCog {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Course over ground relative to north direction
        #[cfg_attr(feature = "serde", serde(rename = "cog"))]
        pub cog: u32,
        /// Speed over ground (based on horizontal velocity)
        #[cfg_attr(feature = "serde", serde(rename = "sog"))]
        pub sog: u32,
        /// Vertical velocity component (positive up)
        #[cfg_attr(feature = "serde", serde(rename = "v_up"))]
        pub v_up: i32,
        /// Course over ground estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "cog_accuracy"))]
        pub cog_accuracy: u32,
        /// Speed over ground estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "sog_accuracy"))]
        pub sog_accuracy: u32,
        /// Vertical velocity estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "v_up_accuracy"))]
        pub v_up_accuracy: u32,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u16,
    }

    impl MsgVelCog {
        /// Gets the [CogFrozen][self::CogFrozen] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `CogFrozen` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `CogFrozen` were added.
        pub fn cog_frozen(&self) -> Result<CogFrozen, u8> {
            get_bit_range!(self.flags, u16, u8, 9, 9).try_into()
        }

        /// Set the bitrange corresponding to the [CogFrozen][CogFrozen] of the `flags` bitfield.
        pub fn set_cog_frozen(&mut self, cog_frozen: CogFrozen) {
            set_bit_range!(&mut self.flags, cog_frozen, u16, u8, 9, 9);
        }

        /// Gets the [VerticalVelocityValidity][self::VerticalVelocityValidity] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `VerticalVelocityValidity` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `VerticalVelocityValidity` were added.
        pub fn vertical_velocity_validity(&self) -> Result<VerticalVelocityValidity, u8> {
            get_bit_range!(self.flags, u16, u8, 8, 8).try_into()
        }

        /// Set the bitrange corresponding to the [VerticalVelocityValidity][VerticalVelocityValidity] of the `flags` bitfield.
        pub fn set_vertical_velocity_validity(
            &mut self,
            vertical_velocity_validity: VerticalVelocityValidity,
        ) {
            set_bit_range!(&mut self.flags, vertical_velocity_validity, u16, u8, 8, 8);
        }

        /// Gets the [SogValidity][self::SogValidity] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `SogValidity` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `SogValidity` were added.
        pub fn sog_validity(&self) -> Result<SogValidity, u8> {
            get_bit_range!(self.flags, u16, u8, 7, 7).try_into()
        }

        /// Set the bitrange corresponding to the [SogValidity][SogValidity] of the `flags` bitfield.
        pub fn set_sog_validity(&mut self, sog_validity: SogValidity) {
            set_bit_range!(&mut self.flags, sog_validity, u16, u8, 7, 7);
        }

        /// Gets the [CogValidity][self::CogValidity] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `CogValidity` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `CogValidity` were added.
        pub fn cog_validity(&self) -> Result<CogValidity, u8> {
            get_bit_range!(self.flags, u16, u8, 6, 6).try_into()
        }

        /// Set the bitrange corresponding to the [CogValidity][CogValidity] of the `flags` bitfield.
        pub fn set_cog_validity(&mut self, cog_validity: CogValidity) {
            set_bit_range!(&mut self.flags, cog_validity, u16, u8, 6, 6);
        }

        /// Gets the [TypeOfReportedTow][self::TypeOfReportedTow] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TypeOfReportedTow` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TypeOfReportedTow` were added.
        pub fn type_of_reported_tow(&self) -> Result<TypeOfReportedTow, u8> {
            get_bit_range!(self.flags, u16, u8, 5, 5).try_into()
        }

        /// Set the bitrange corresponding to the [TypeOfReportedTow][TypeOfReportedTow] of the `flags` bitfield.
        pub fn set_type_of_reported_tow(&mut self, type_of_reported_tow: TypeOfReportedTow) {
            set_bit_range!(&mut self.flags, type_of_reported_tow, u16, u8, 5, 5);
        }

        /// Gets the [InsNavigationMode][self::InsNavigationMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `InsNavigationMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `InsNavigationMode` were added.
        pub fn ins_navigation_mode(&self) -> Result<InsNavigationMode, u8> {
            get_bit_range!(self.flags, u16, u8, 4, 3).try_into()
        }

        /// Set the bitrange corresponding to the [InsNavigationMode][InsNavigationMode] of the `flags` bitfield.
        pub fn set_ins_navigation_mode(&mut self, ins_navigation_mode: InsNavigationMode) {
            set_bit_range!(&mut self.flags, ins_navigation_mode, u16, u8, 4, 3);
        }

        /// Gets the [VelocityMode][self::VelocityMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `VelocityMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `VelocityMode` were added.
        pub fn velocity_mode(&self) -> Result<VelocityMode, u8> {
            get_bit_range!(self.flags, u16, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [VelocityMode][VelocityMode] of the `flags` bitfield.
        pub fn set_velocity_mode(&mut self, velocity_mode: VelocityMode) {
            set_bit_range!(&mut self.flags, velocity_mode, u16, u8, 2, 0);
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

    /// COG frozen
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum CogFrozen {
        /// Not frozen
        NotFrozen = 0,

        /// Frozen
        Frozen = 1,
    }

    impl std::fmt::Display for CogFrozen {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                CogFrozen::NotFrozen => f.write_str("Not frozen"),
                CogFrozen::Frozen => f.write_str("Frozen"),
            }
        }
    }

    impl TryFrom<u8> for CogFrozen {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(CogFrozen::NotFrozen),
                1 => Ok(CogFrozen::Frozen),
                i => Err(i),
            }
        }
    }

    /// Vertical velocity validity
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum VerticalVelocityValidity {
        /// Invalid
        Invalid = 0,

        /// Vertical velocity valid
        VerticalVelocityValid = 1,
    }

    impl std::fmt::Display for VerticalVelocityValidity {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                VerticalVelocityValidity::Invalid => f.write_str("Invalid"),
                VerticalVelocityValidity::VerticalVelocityValid => {
                    f.write_str("Vertical velocity valid")
                }
            }
        }
    }

    impl TryFrom<u8> for VerticalVelocityValidity {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(VerticalVelocityValidity::Invalid),
                1 => Ok(VerticalVelocityValidity::VerticalVelocityValid),
                i => Err(i),
            }
        }
    }

    /// SOG validity
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum SogValidity {
        /// Invalid
        Invalid = 0,

        /// SOG valid
        SogValid = 1,
    }

    impl std::fmt::Display for SogValidity {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                SogValidity::Invalid => f.write_str("Invalid"),
                SogValidity::SogValid => f.write_str("SOG valid"),
            }
        }
    }

    impl TryFrom<u8> for SogValidity {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(SogValidity::Invalid),
                1 => Ok(SogValidity::SogValid),
                i => Err(i),
            }
        }
    }

    /// COG validity
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum CogValidity {
        /// Invalid
        Invalid = 0,

        /// COG valid
        CogValid = 1,
    }

    impl std::fmt::Display for CogValidity {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                CogValidity::Invalid => f.write_str("Invalid"),
                CogValidity::CogValid => f.write_str("COG valid"),
            }
        }
    }

    impl TryFrom<u8> for CogValidity {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(CogValidity::Invalid),
                1 => Ok(CogValidity::CogValid),
                i => Err(i),
            }
        }
    }

    /// Type of reported TOW
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TypeOfReportedTow {
        /// Time of Measurement
        TimeOfMeasurement = 0,

        /// Other
        Other = 1,
    }

    impl std::fmt::Display for TypeOfReportedTow {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
                TypeOfReportedTow::Other => f.write_str("Other"),
            }
        }
    }

    impl TryFrom<u8> for TypeOfReportedTow {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TypeOfReportedTow::TimeOfMeasurement),
                1 => Ok(TypeOfReportedTow::Other),
                i => Err(i),
            }
        }
    }

    /// INS Navigation Mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum InsNavigationMode {
        /// None
        None = 0,

        /// INS used
        InsUsed = 1,
    }

    impl std::fmt::Display for InsNavigationMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                InsNavigationMode::None => f.write_str("None"),
                InsNavigationMode::InsUsed => f.write_str("INS used"),
            }
        }
    }

    impl TryFrom<u8> for InsNavigationMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(InsNavigationMode::None),
                1 => Ok(InsNavigationMode::InsUsed),
                i => Err(i),
            }
        }
    }

    /// Velocity mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum VelocityMode {
        /// Invalid
        Invalid = 0,

        /// Measured Doppler derived
        MeasuredDopplerDerived = 1,

        /// Computed Doppler derived
        ComputedDopplerDerived = 2,

        /// Dead Reckoning
        DeadReckoning = 3,
    }

    impl std::fmt::Display for VelocityMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                VelocityMode::Invalid => f.write_str("Invalid"),
                VelocityMode::MeasuredDopplerDerived => f.write_str("Measured Doppler derived"),
                VelocityMode::ComputedDopplerDerived => f.write_str("Computed Doppler derived"),
                VelocityMode::DeadReckoning => f.write_str("Dead Reckoning"),
            }
        }
    }

    impl TryFrom<u8> for VelocityMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(VelocityMode::Invalid),
                1 => Ok(VelocityMode::MeasuredDopplerDerived),
                2 => Ok(VelocityMode::ComputedDopplerDerived),
                3 => Ok(VelocityMode::DeadReckoning),
                i => Err(i),
            }
        }
    }
}

pub mod msg_vel_ecef {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Velocity in ECEF
    ///
    /// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
    /// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
    /// the matching time-of-week (tow).
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgVelEcef {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Velocity ECEF X coordinate
        #[cfg_attr(feature = "serde", serde(rename = "x"))]
        pub x: i32,
        /// Velocity ECEF Y coordinate
        #[cfg_attr(feature = "serde", serde(rename = "y"))]
        pub y: i32,
        /// Velocity ECEF Z coordinate
        #[cfg_attr(feature = "serde", serde(rename = "z"))]
        pub z: i32,
        /// Velocity estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "accuracy"))]
        pub accuracy: u16,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgVelEcef {
        /// Gets the [TypeOfReportedTow][self::TypeOfReportedTow] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TypeOfReportedTow` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TypeOfReportedTow` were added.
        pub fn type_of_reported_tow(&self) -> Result<TypeOfReportedTow, u8> {
            get_bit_range!(self.flags, u8, u8, 5, 5).try_into()
        }

        /// Set the bitrange corresponding to the [TypeOfReportedTow][TypeOfReportedTow] of the `flags` bitfield.
        pub fn set_type_of_reported_tow(&mut self, type_of_reported_tow: TypeOfReportedTow) {
            set_bit_range!(&mut self.flags, type_of_reported_tow, u8, u8, 5, 5);
        }

        /// Gets the [InsNavigationMode][self::InsNavigationMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `InsNavigationMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `InsNavigationMode` were added.
        pub fn ins_navigation_mode(&self) -> Result<InsNavigationMode, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 3).try_into()
        }

        /// Set the bitrange corresponding to the [InsNavigationMode][InsNavigationMode] of the `flags` bitfield.
        pub fn set_ins_navigation_mode(&mut self, ins_navigation_mode: InsNavigationMode) {
            set_bit_range!(&mut self.flags, ins_navigation_mode, u8, u8, 4, 3);
        }

        /// Gets the [VelocityMode][self::VelocityMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `VelocityMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `VelocityMode` were added.
        pub fn velocity_mode(&self) -> Result<VelocityMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [VelocityMode][VelocityMode] of the `flags` bitfield.
        pub fn set_velocity_mode(&mut self, velocity_mode: VelocityMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TypeOfReportedTow {
        /// Time of Measurement
        TimeOfMeasurement = 0,

        /// Other
        Other = 1,
    }

    impl std::fmt::Display for TypeOfReportedTow {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
                TypeOfReportedTow::Other => f.write_str("Other"),
            }
        }
    }

    impl TryFrom<u8> for TypeOfReportedTow {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TypeOfReportedTow::TimeOfMeasurement),
                1 => Ok(TypeOfReportedTow::Other),
                i => Err(i),
            }
        }
    }

    /// INS Navigation Mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum InsNavigationMode {
        /// None
        None = 0,

        /// INS used
        InsUsed = 1,
    }

    impl std::fmt::Display for InsNavigationMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                InsNavigationMode::None => f.write_str("None"),
                InsNavigationMode::InsUsed => f.write_str("INS used"),
            }
        }
    }

    impl TryFrom<u8> for InsNavigationMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(InsNavigationMode::None),
                1 => Ok(InsNavigationMode::InsUsed),
                i => Err(i),
            }
        }
    }

    /// Velocity mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum VelocityMode {
        /// Invalid
        Invalid = 0,

        /// Measured Doppler derived
        MeasuredDopplerDerived = 1,

        /// Computed Doppler derived
        ComputedDopplerDerived = 2,

        /// Dead Reckoning
        DeadReckoning = 3,
    }

    impl std::fmt::Display for VelocityMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                VelocityMode::Invalid => f.write_str("Invalid"),
                VelocityMode::MeasuredDopplerDerived => f.write_str("Measured Doppler derived"),
                VelocityMode::ComputedDopplerDerived => f.write_str("Computed Doppler derived"),
                VelocityMode::DeadReckoning => f.write_str("Dead Reckoning"),
            }
        }
    }

    impl TryFrom<u8> for VelocityMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(VelocityMode::Invalid),
                1 => Ok(VelocityMode::MeasuredDopplerDerived),
                2 => Ok(VelocityMode::ComputedDopplerDerived),
                3 => Ok(VelocityMode::DeadReckoning),
                i => Err(i),
            }
        }
    }
}

pub mod msg_vel_ecef_cov {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Velocity in ECEF
    ///
    /// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
    /// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
    /// the matching time-of-week (tow).
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgVelEcefCov {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Velocity ECEF X coordinate
        #[cfg_attr(feature = "serde", serde(rename = "x"))]
        pub x: i32,
        /// Velocity ECEF Y coordinate
        #[cfg_attr(feature = "serde", serde(rename = "y"))]
        pub y: i32,
        /// Velocity ECEF Z coordinate
        #[cfg_attr(feature = "serde", serde(rename = "z"))]
        pub z: i32,
        /// Estimated variance of x
        #[cfg_attr(feature = "serde", serde(rename = "cov_x_x"))]
        pub cov_x_x: f32,
        /// Estimated covariance of x and y
        #[cfg_attr(feature = "serde", serde(rename = "cov_x_y"))]
        pub cov_x_y: f32,
        /// Estimated covariance of x and z
        #[cfg_attr(feature = "serde", serde(rename = "cov_x_z"))]
        pub cov_x_z: f32,
        /// Estimated variance of y
        #[cfg_attr(feature = "serde", serde(rename = "cov_y_y"))]
        pub cov_y_y: f32,
        /// Estimated covariance of y and z
        #[cfg_attr(feature = "serde", serde(rename = "cov_y_z"))]
        pub cov_y_z: f32,
        /// Estimated variance of z
        #[cfg_attr(feature = "serde", serde(rename = "cov_z_z"))]
        pub cov_z_z: f32,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgVelEcefCov {
        /// Gets the [TypeOfReportedTow][self::TypeOfReportedTow] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TypeOfReportedTow` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TypeOfReportedTow` were added.
        pub fn type_of_reported_tow(&self) -> Result<TypeOfReportedTow, u8> {
            get_bit_range!(self.flags, u8, u8, 5, 5).try_into()
        }

        /// Set the bitrange corresponding to the [TypeOfReportedTow][TypeOfReportedTow] of the `flags` bitfield.
        pub fn set_type_of_reported_tow(&mut self, type_of_reported_tow: TypeOfReportedTow) {
            set_bit_range!(&mut self.flags, type_of_reported_tow, u8, u8, 5, 5);
        }

        /// Gets the [InsNavigationMode][self::InsNavigationMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `InsNavigationMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `InsNavigationMode` were added.
        pub fn ins_navigation_mode(&self) -> Result<InsNavigationMode, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 3).try_into()
        }

        /// Set the bitrange corresponding to the [InsNavigationMode][InsNavigationMode] of the `flags` bitfield.
        pub fn set_ins_navigation_mode(&mut self, ins_navigation_mode: InsNavigationMode) {
            set_bit_range!(&mut self.flags, ins_navigation_mode, u8, u8, 4, 3);
        }

        /// Gets the [VelocityMode][self::VelocityMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `VelocityMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `VelocityMode` were added.
        pub fn velocity_mode(&self) -> Result<VelocityMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [VelocityMode][VelocityMode] of the `flags` bitfield.
        pub fn set_velocity_mode(&mut self, velocity_mode: VelocityMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TypeOfReportedTow {
        /// Time of Measurement
        TimeOfMeasurement = 0,

        /// Other
        Other = 1,
    }

    impl std::fmt::Display for TypeOfReportedTow {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
                TypeOfReportedTow::Other => f.write_str("Other"),
            }
        }
    }

    impl TryFrom<u8> for TypeOfReportedTow {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TypeOfReportedTow::TimeOfMeasurement),
                1 => Ok(TypeOfReportedTow::Other),
                i => Err(i),
            }
        }
    }

    /// INS Navigation Mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum InsNavigationMode {
        /// None
        None = 0,

        /// INS used
        InsUsed = 1,
    }

    impl std::fmt::Display for InsNavigationMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                InsNavigationMode::None => f.write_str("None"),
                InsNavigationMode::InsUsed => f.write_str("INS used"),
            }
        }
    }

    impl TryFrom<u8> for InsNavigationMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(InsNavigationMode::None),
                1 => Ok(InsNavigationMode::InsUsed),
                i => Err(i),
            }
        }
    }

    /// Velocity mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum VelocityMode {
        /// Invalid
        Invalid = 0,

        /// Measured Doppler derived
        MeasuredDopplerDerived = 1,

        /// Computed Doppler derived
        ComputedDopplerDerived = 2,

        /// Dead Reckoning
        DeadReckoning = 3,
    }

    impl std::fmt::Display for VelocityMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                VelocityMode::Invalid => f.write_str("Invalid"),
                VelocityMode::MeasuredDopplerDerived => f.write_str("Measured Doppler derived"),
                VelocityMode::ComputedDopplerDerived => f.write_str("Computed Doppler derived"),
                VelocityMode::DeadReckoning => f.write_str("Dead Reckoning"),
            }
        }
    }

    impl TryFrom<u8> for VelocityMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(VelocityMode::Invalid),
                1 => Ok(VelocityMode::MeasuredDopplerDerived),
                2 => Ok(VelocityMode::ComputedDopplerDerived),
                3 => Ok(VelocityMode::DeadReckoning),
                i => Err(i),
            }
        }
    }
}

pub mod msg_vel_ecef_cov_gnss {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// GNSS-only Velocity in ECEF
    ///
    /// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
    /// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
    /// the matching time-of-week (tow).
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgVelEcefCovGnss {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Velocity ECEF X coordinate
        #[cfg_attr(feature = "serde", serde(rename = "x"))]
        pub x: i32,
        /// Velocity ECEF Y coordinate
        #[cfg_attr(feature = "serde", serde(rename = "y"))]
        pub y: i32,
        /// Velocity ECEF Z coordinate
        #[cfg_attr(feature = "serde", serde(rename = "z"))]
        pub z: i32,
        /// Estimated variance of x
        #[cfg_attr(feature = "serde", serde(rename = "cov_x_x"))]
        pub cov_x_x: f32,
        /// Estimated covariance of x and y
        #[cfg_attr(feature = "serde", serde(rename = "cov_x_y"))]
        pub cov_x_y: f32,
        /// Estimated covariance of x and z
        #[cfg_attr(feature = "serde", serde(rename = "cov_x_z"))]
        pub cov_x_z: f32,
        /// Estimated variance of y
        #[cfg_attr(feature = "serde", serde(rename = "cov_y_y"))]
        pub cov_y_y: f32,
        /// Estimated covariance of y and z
        #[cfg_attr(feature = "serde", serde(rename = "cov_y_z"))]
        pub cov_y_z: f32,
        /// Estimated variance of z
        #[cfg_attr(feature = "serde", serde(rename = "cov_z_z"))]
        pub cov_z_z: f32,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgVelEcefCovGnss {
        /// Gets the [VelocityMode][self::VelocityMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `VelocityMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `VelocityMode` were added.
        pub fn velocity_mode(&self) -> Result<VelocityMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [VelocityMode][VelocityMode] of the `flags` bitfield.
        pub fn set_velocity_mode(&mut self, velocity_mode: VelocityMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum VelocityMode {
        /// Invalid
        Invalid = 0,

        /// Measured Doppler derived
        MeasuredDopplerDerived = 1,

        /// Computed Doppler derived
        ComputedDopplerDerived = 2,
    }

    impl std::fmt::Display for VelocityMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                VelocityMode::Invalid => f.write_str("Invalid"),
                VelocityMode::MeasuredDopplerDerived => f.write_str("Measured Doppler derived"),
                VelocityMode::ComputedDopplerDerived => f.write_str("Computed Doppler derived"),
            }
        }
    }

    impl TryFrom<u8> for VelocityMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(VelocityMode::Invalid),
                1 => Ok(VelocityMode::MeasuredDopplerDerived),
                2 => Ok(VelocityMode::ComputedDopplerDerived),
                i => Err(i),
            }
        }
    }
}

pub mod msg_vel_ecef_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Velocity in ECEF
    ///
    /// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
    /// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
    /// the matching time-of-week (tow).
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgVelEcefDepA {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Velocity ECEF X coordinate
        #[cfg_attr(feature = "serde", serde(rename = "x"))]
        pub x: i32,
        /// Velocity ECEF Y coordinate
        #[cfg_attr(feature = "serde", serde(rename = "y"))]
        pub y: i32,
        /// Velocity ECEF Z coordinate
        #[cfg_attr(feature = "serde", serde(rename = "z"))]
        pub z: i32,
        /// Velocity accuracy estimate (not implemented). Defaults to 0.
        #[cfg_attr(feature = "serde", serde(rename = "accuracy"))]
        pub accuracy: u16,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags (reserved)
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
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
}

pub mod msg_vel_ecef_gnss {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// GNSS-only Velocity in ECEF
    ///
    /// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
    /// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
    /// the matching time-of-week (tow).
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgVelEcefGnss {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Velocity ECEF X coordinate
        #[cfg_attr(feature = "serde", serde(rename = "x"))]
        pub x: i32,
        /// Velocity ECEF Y coordinate
        #[cfg_attr(feature = "serde", serde(rename = "y"))]
        pub y: i32,
        /// Velocity ECEF Z coordinate
        #[cfg_attr(feature = "serde", serde(rename = "z"))]
        pub z: i32,
        /// Velocity estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "accuracy"))]
        pub accuracy: u16,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgVelEcefGnss {
        /// Gets the [VelocityMode][self::VelocityMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `VelocityMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `VelocityMode` were added.
        pub fn velocity_mode(&self) -> Result<VelocityMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [VelocityMode][VelocityMode] of the `flags` bitfield.
        pub fn set_velocity_mode(&mut self, velocity_mode: VelocityMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum VelocityMode {
        /// Invalid
        Invalid = 0,

        /// Measured Doppler derived
        MeasuredDopplerDerived = 1,

        /// Computed Doppler derived
        ComputedDopplerDerived = 2,
    }

    impl std::fmt::Display for VelocityMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                VelocityMode::Invalid => f.write_str("Invalid"),
                VelocityMode::MeasuredDopplerDerived => f.write_str("Measured Doppler derived"),
                VelocityMode::ComputedDopplerDerived => f.write_str("Computed Doppler derived"),
            }
        }
    }

    impl TryFrom<u8> for VelocityMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(VelocityMode::Invalid),
                1 => Ok(VelocityMode::MeasuredDopplerDerived),
                2 => Ok(VelocityMode::ComputedDopplerDerived),
                i => Err(i),
            }
        }
    }
}

pub mod msg_vel_ned {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Velocity in NED
    ///
    /// This message reports the velocity in local North East Down (NED)
    /// coordinates. The NED coordinate system is defined as the local WGS84
    /// tangent plane centered at the current position. The full GPS time is given
    /// by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgVelNed {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Velocity North coordinate
        #[cfg_attr(feature = "serde", serde(rename = "n"))]
        pub n: i32,
        /// Velocity East coordinate
        #[cfg_attr(feature = "serde", serde(rename = "e"))]
        pub e: i32,
        /// Velocity Down coordinate
        #[cfg_attr(feature = "serde", serde(rename = "d"))]
        pub d: i32,
        /// Horizontal velocity estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "h_accuracy"))]
        pub h_accuracy: u16,
        /// Vertical velocity estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "v_accuracy"))]
        pub v_accuracy: u16,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgVelNed {
        /// Gets the [TypeOfReportedTow][self::TypeOfReportedTow] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TypeOfReportedTow` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TypeOfReportedTow` were added.
        pub fn type_of_reported_tow(&self) -> Result<TypeOfReportedTow, u8> {
            get_bit_range!(self.flags, u8, u8, 5, 5).try_into()
        }

        /// Set the bitrange corresponding to the [TypeOfReportedTow][TypeOfReportedTow] of the `flags` bitfield.
        pub fn set_type_of_reported_tow(&mut self, type_of_reported_tow: TypeOfReportedTow) {
            set_bit_range!(&mut self.flags, type_of_reported_tow, u8, u8, 5, 5);
        }

        /// Gets the [InsNavigationMode][self::InsNavigationMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `InsNavigationMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `InsNavigationMode` were added.
        pub fn ins_navigation_mode(&self) -> Result<InsNavigationMode, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 3).try_into()
        }

        /// Set the bitrange corresponding to the [InsNavigationMode][InsNavigationMode] of the `flags` bitfield.
        pub fn set_ins_navigation_mode(&mut self, ins_navigation_mode: InsNavigationMode) {
            set_bit_range!(&mut self.flags, ins_navigation_mode, u8, u8, 4, 3);
        }

        /// Gets the [VelocityMode][self::VelocityMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `VelocityMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `VelocityMode` were added.
        pub fn velocity_mode(&self) -> Result<VelocityMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [VelocityMode][VelocityMode] of the `flags` bitfield.
        pub fn set_velocity_mode(&mut self, velocity_mode: VelocityMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TypeOfReportedTow {
        /// Time of Measurement
        TimeOfMeasurement = 0,

        /// Other
        Other = 1,
    }

    impl std::fmt::Display for TypeOfReportedTow {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
                TypeOfReportedTow::Other => f.write_str("Other"),
            }
        }
    }

    impl TryFrom<u8> for TypeOfReportedTow {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TypeOfReportedTow::TimeOfMeasurement),
                1 => Ok(TypeOfReportedTow::Other),
                i => Err(i),
            }
        }
    }

    /// INS Navigation Mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum InsNavigationMode {
        /// None
        None = 0,

        /// INS used
        InsUsed = 1,
    }

    impl std::fmt::Display for InsNavigationMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                InsNavigationMode::None => f.write_str("None"),
                InsNavigationMode::InsUsed => f.write_str("INS used"),
            }
        }
    }

    impl TryFrom<u8> for InsNavigationMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(InsNavigationMode::None),
                1 => Ok(InsNavigationMode::InsUsed),
                i => Err(i),
            }
        }
    }

    /// Velocity mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum VelocityMode {
        /// Invalid
        Invalid = 0,

        /// Measured Doppler derived
        MeasuredDopplerDerived = 1,

        /// Computed Doppler derived
        ComputedDopplerDerived = 2,

        /// Dead Reckoning
        DeadReckoning = 3,
    }

    impl std::fmt::Display for VelocityMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                VelocityMode::Invalid => f.write_str("Invalid"),
                VelocityMode::MeasuredDopplerDerived => f.write_str("Measured Doppler derived"),
                VelocityMode::ComputedDopplerDerived => f.write_str("Computed Doppler derived"),
                VelocityMode::DeadReckoning => f.write_str("Dead Reckoning"),
            }
        }
    }

    impl TryFrom<u8> for VelocityMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(VelocityMode::Invalid),
                1 => Ok(VelocityMode::MeasuredDopplerDerived),
                2 => Ok(VelocityMode::ComputedDopplerDerived),
                3 => Ok(VelocityMode::DeadReckoning),
                i => Err(i),
            }
        }
    }
}

pub mod msg_vel_ned_cov {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Velocity in NED
    ///
    /// This message reports the velocity in local North East Down (NED)
    /// coordinates. The NED coordinate system is defined as the local WGS84
    /// tangent plane centered at the current position. The full GPS time is given
    /// by the preceding MSG_GPS_TIME with the matching time-of-week (tow). This
    /// message is similar to the MSG_VEL_NED, but it includes the upper
    /// triangular portion of the 3x3 covariance matrix.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgVelNedCov {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Velocity North coordinate
        #[cfg_attr(feature = "serde", serde(rename = "n"))]
        pub n: i32,
        /// Velocity East coordinate
        #[cfg_attr(feature = "serde", serde(rename = "e"))]
        pub e: i32,
        /// Velocity Down coordinate
        #[cfg_attr(feature = "serde", serde(rename = "d"))]
        pub d: i32,
        /// Estimated variance of northward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_n_n"))]
        pub cov_n_n: f32,
        /// Covariance of northward and eastward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_n_e"))]
        pub cov_n_e: f32,
        /// Covariance of northward and downward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_n_d"))]
        pub cov_n_d: f32,
        /// Estimated variance of eastward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_e_e"))]
        pub cov_e_e: f32,
        /// Covariance of eastward and downward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_e_d"))]
        pub cov_e_d: f32,
        /// Estimated variance of downward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_d_d"))]
        pub cov_d_d: f32,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgVelNedCov {
        /// Gets the [TypeOfReportedTow][self::TypeOfReportedTow] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TypeOfReportedTow` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TypeOfReportedTow` were added.
        pub fn type_of_reported_tow(&self) -> Result<TypeOfReportedTow, u8> {
            get_bit_range!(self.flags, u8, u8, 5, 5).try_into()
        }

        /// Set the bitrange corresponding to the [TypeOfReportedTow][TypeOfReportedTow] of the `flags` bitfield.
        pub fn set_type_of_reported_tow(&mut self, type_of_reported_tow: TypeOfReportedTow) {
            set_bit_range!(&mut self.flags, type_of_reported_tow, u8, u8, 5, 5);
        }

        /// Gets the [InsNavigationMode][self::InsNavigationMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `InsNavigationMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `InsNavigationMode` were added.
        pub fn ins_navigation_mode(&self) -> Result<InsNavigationMode, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 3).try_into()
        }

        /// Set the bitrange corresponding to the [InsNavigationMode][InsNavigationMode] of the `flags` bitfield.
        pub fn set_ins_navigation_mode(&mut self, ins_navigation_mode: InsNavigationMode) {
            set_bit_range!(&mut self.flags, ins_navigation_mode, u8, u8, 4, 3);
        }

        /// Gets the [VelocityMode][self::VelocityMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `VelocityMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `VelocityMode` were added.
        pub fn velocity_mode(&self) -> Result<VelocityMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [VelocityMode][VelocityMode] of the `flags` bitfield.
        pub fn set_velocity_mode(&mut self, velocity_mode: VelocityMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TypeOfReportedTow {
        /// Time of Measurement
        TimeOfMeasurement = 0,

        /// Other
        Other = 1,
    }

    impl std::fmt::Display for TypeOfReportedTow {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TypeOfReportedTow::TimeOfMeasurement => f.write_str("Time of Measurement"),
                TypeOfReportedTow::Other => f.write_str("Other"),
            }
        }
    }

    impl TryFrom<u8> for TypeOfReportedTow {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TypeOfReportedTow::TimeOfMeasurement),
                1 => Ok(TypeOfReportedTow::Other),
                i => Err(i),
            }
        }
    }

    /// INS Navigation Mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum InsNavigationMode {
        /// None
        None = 0,

        /// INS used
        InsUsed = 1,
    }

    impl std::fmt::Display for InsNavigationMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                InsNavigationMode::None => f.write_str("None"),
                InsNavigationMode::InsUsed => f.write_str("INS used"),
            }
        }
    }

    impl TryFrom<u8> for InsNavigationMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(InsNavigationMode::None),
                1 => Ok(InsNavigationMode::InsUsed),
                i => Err(i),
            }
        }
    }

    /// Velocity mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum VelocityMode {
        /// Invalid
        Invalid = 0,

        /// Measured Doppler derived
        MeasuredDopplerDerived = 1,

        /// Computed Doppler derived
        ComputedDopplerDerived = 2,

        /// Dead Reckoning
        DeadReckoning = 3,
    }

    impl std::fmt::Display for VelocityMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                VelocityMode::Invalid => f.write_str("Invalid"),
                VelocityMode::MeasuredDopplerDerived => f.write_str("Measured Doppler derived"),
                VelocityMode::ComputedDopplerDerived => f.write_str("Computed Doppler derived"),
                VelocityMode::DeadReckoning => f.write_str("Dead Reckoning"),
            }
        }
    }

    impl TryFrom<u8> for VelocityMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(VelocityMode::Invalid),
                1 => Ok(VelocityMode::MeasuredDopplerDerived),
                2 => Ok(VelocityMode::ComputedDopplerDerived),
                3 => Ok(VelocityMode::DeadReckoning),
                i => Err(i),
            }
        }
    }
}

pub mod msg_vel_ned_cov_gnss {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// GNSS-only Velocity in NED
    ///
    /// This message reports the velocity in local North East Down (NED)
    /// coordinates. The NED coordinate system is defined as the local WGS84
    /// tangent plane centered at the current position. The full GPS time is given
    /// by the preceding MSG_GPS_TIME with the matching time-of-week (tow). This
    /// message is similar to the MSG_VEL_NED, but it includes the upper
    /// triangular portion of the 3x3 covariance matrix.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgVelNedCovGnss {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Velocity North coordinate
        #[cfg_attr(feature = "serde", serde(rename = "n"))]
        pub n: i32,
        /// Velocity East coordinate
        #[cfg_attr(feature = "serde", serde(rename = "e"))]
        pub e: i32,
        /// Velocity Down coordinate
        #[cfg_attr(feature = "serde", serde(rename = "d"))]
        pub d: i32,
        /// Estimated variance of northward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_n_n"))]
        pub cov_n_n: f32,
        /// Covariance of northward and eastward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_n_e"))]
        pub cov_n_e: f32,
        /// Covariance of northward and downward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_n_d"))]
        pub cov_n_d: f32,
        /// Estimated variance of eastward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_e_e"))]
        pub cov_e_e: f32,
        /// Covariance of eastward and downward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_e_d"))]
        pub cov_e_d: f32,
        /// Estimated variance of downward measurement
        #[cfg_attr(feature = "serde", serde(rename = "cov_d_d"))]
        pub cov_d_d: f32,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgVelNedCovGnss {
        /// Gets the [VelocityMode][self::VelocityMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `VelocityMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `VelocityMode` were added.
        pub fn velocity_mode(&self) -> Result<VelocityMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [VelocityMode][VelocityMode] of the `flags` bitfield.
        pub fn set_velocity_mode(&mut self, velocity_mode: VelocityMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum VelocityMode {
        /// Invalid
        Invalid = 0,

        /// Measured Doppler derived
        MeasuredDopplerDerived = 1,

        /// Computed Doppler derived
        ComputedDopplerDerived = 2,
    }

    impl std::fmt::Display for VelocityMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                VelocityMode::Invalid => f.write_str("Invalid"),
                VelocityMode::MeasuredDopplerDerived => f.write_str("Measured Doppler derived"),
                VelocityMode::ComputedDopplerDerived => f.write_str("Computed Doppler derived"),
            }
        }
    }

    impl TryFrom<u8> for VelocityMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(VelocityMode::Invalid),
                1 => Ok(VelocityMode::MeasuredDopplerDerived),
                2 => Ok(VelocityMode::ComputedDopplerDerived),
                i => Err(i),
            }
        }
    }
}

pub mod msg_vel_ned_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Velocity in NED
    ///
    /// This message reports the velocity in local North East Down (NED)
    /// coordinates. The NED coordinate system is defined as the local WGS84
    /// tangent plane centered at the current position. The full GPS time is given
    /// by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgVelNedDepA {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Velocity North coordinate
        #[cfg_attr(feature = "serde", serde(rename = "n"))]
        pub n: i32,
        /// Velocity East coordinate
        #[cfg_attr(feature = "serde", serde(rename = "e"))]
        pub e: i32,
        /// Velocity Down coordinate
        #[cfg_attr(feature = "serde", serde(rename = "d"))]
        pub d: i32,
        /// Horizontal velocity accuracy estimate (not implemented). Defaults to 0.
        #[cfg_attr(feature = "serde", serde(rename = "h_accuracy"))]
        pub h_accuracy: u16,
        /// Vertical velocity accuracy estimate (not implemented). Defaults to 0.
        #[cfg_attr(feature = "serde", serde(rename = "v_accuracy"))]
        pub v_accuracy: u16,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags (reserved)
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
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
}

pub mod msg_vel_ned_gnss {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// GNSS-only Velocity in NED
    ///
    /// This message reports the velocity in local North East Down (NED)
    /// coordinates. The NED coordinate system is defined as the local WGS84
    /// tangent plane centered at the current position. The full GPS time is given
    /// by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgVelNedGnss {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Velocity North coordinate
        #[cfg_attr(feature = "serde", serde(rename = "n"))]
        pub n: i32,
        /// Velocity East coordinate
        #[cfg_attr(feature = "serde", serde(rename = "e"))]
        pub e: i32,
        /// Velocity Down coordinate
        #[cfg_attr(feature = "serde", serde(rename = "d"))]
        pub d: i32,
        /// Horizontal velocity estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "h_accuracy"))]
        pub h_accuracy: u16,
        /// Vertical velocity estimated standard deviation
        #[cfg_attr(feature = "serde", serde(rename = "v_accuracy"))]
        pub v_accuracy: u16,
        /// Number of satellites used in solution
        #[cfg_attr(feature = "serde", serde(rename = "n_sats"))]
        pub n_sats: u8,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgVelNedGnss {
        /// Gets the [VelocityMode][self::VelocityMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `VelocityMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `VelocityMode` were added.
        pub fn velocity_mode(&self) -> Result<VelocityMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [VelocityMode][VelocityMode] of the `flags` bitfield.
        pub fn set_velocity_mode(&mut self, velocity_mode: VelocityMode) {
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum VelocityMode {
        /// Invalid
        Invalid = 0,

        /// Measured Doppler derived
        MeasuredDopplerDerived = 1,

        /// Computed Doppler derived
        ComputedDopplerDerived = 2,
    }

    impl std::fmt::Display for VelocityMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                VelocityMode::Invalid => f.write_str("Invalid"),
                VelocityMode::MeasuredDopplerDerived => f.write_str("Measured Doppler derived"),
                VelocityMode::ComputedDopplerDerived => f.write_str("Computed Doppler derived"),
            }
        }
    }

    impl TryFrom<u8> for VelocityMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(VelocityMode::Invalid),
                1 => Ok(VelocityMode::MeasuredDopplerDerived),
                2 => Ok(VelocityMode::ComputedDopplerDerived),
                i => Err(i),
            }
        }
    }
}
