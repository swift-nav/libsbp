// Copyright (C) 2015-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
//
// This source is subject to the license found in the file 'LICENSE' which must
// be distributed together with this source. All other rights reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

//****************************************************************************
// Automatically generated from yaml/swiftnav/sbp/orientation.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Orientation Messages
pub use msg_angular_rate::MsgAngularRate;
pub use msg_baseline_heading::MsgBaselineHeading;
pub use msg_orient_euler::MsgOrientEuler;
pub use msg_orient_quat::MsgOrientQuat;
pub use msg_orient_quat_cov::MsgOrientQuatCov;

pub mod msg_angular_rate {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Vehicle Body Frame instantaneous angular rates
    ///
    /// This message reports the orientation rates in the vehicle body frame. The
    /// values represent the measurements a strapped down gyroscope would make and
    /// are not equivalent to the time derivative of the Euler angles. The
    /// orientation and origin of the user frame is specified via device settings.
    /// By convention, the vehicle x-axis is expected to be aligned with the
    /// forward direction, while the vehicle y-axis is expected to be aligned with
    /// the right direction, and the vehicle z-axis should be aligned with the
    /// down direction. This message will only be available in future INS versions
    /// of Swift Products and is not produced by Piksi Multi or Duro.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgAngularRate {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// angular rate about x axis
        #[cfg_attr(feature = "serde", serde(rename = "x"))]
        pub x: i32,
        /// angular rate about y axis
        #[cfg_attr(feature = "serde", serde(rename = "y"))]
        pub y: i32,
        /// angular rate about z axis
        #[cfg_attr(feature = "serde", serde(rename = "z"))]
        pub z: i32,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgAngularRate {
        /// Gets the [InsNavigationMode][self::InsNavigationMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `InsNavigationMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `InsNavigationMode` were added.
        pub fn ins_navigation_mode(&self) -> Result<InsNavigationMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [InsNavigationMode][InsNavigationMode] of the `flags` bitfield.
        pub fn set_ins_navigation_mode(&mut self, ins_navigation_mode: InsNavigationMode) {
            set_bit_range!(&mut self.flags, ins_navigation_mode, u8, u8, 2, 0);
        }
    }

    impl ConcreteMessage for MsgAngularRate {
        const MESSAGE_TYPE: u16 = 546;
        const MESSAGE_NAME: &'static str = "MSG_ANGULAR_RATE";
    }

    impl SbpMessage for MsgAngularRate {
        fn message_name(&self) -> &'static str {
            <Self as ConcreteMessage>::MESSAGE_NAME
        }
        fn message_type(&self) -> Option<u16> {
            Some(<Self as ConcreteMessage>::MESSAGE_TYPE)
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
        fn is_valid(&self) -> bool {
            true
        }
        fn into_valid_msg(self) -> Result<Self, crate::messages::invalid::Invalid> {
            Ok(self)
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

    impl FriendlyName for MsgAngularRate {
        fn friendly_name() -> &'static str {
            "ANGULAR RATE"
        }
    }

    impl TryFrom<Sbp> for MsgAngularRate {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgAngularRate(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgAngularRate {
        const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.tow)
                + WireFormat::len(&self.x)
                + WireFormat::len(&self.y)
                + WireFormat::len(&self.z)
                + WireFormat::len(&self.flags)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.tow, buf);
            WireFormat::write(&self.x, buf);
            WireFormat::write(&self.y, buf);
            WireFormat::write(&self.z, buf);
            WireFormat::write(&self.flags, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgAngularRate {
                sender_id: None,
                tow: WireFormat::parse_unchecked(buf),
                x: WireFormat::parse_unchecked(buf),
                y: WireFormat::parse_unchecked(buf),
                z: WireFormat::parse_unchecked(buf),
                flags: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// INS Navigation mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum InsNavigationMode {
        /// Invalid
        Invalid = 0,

        /// Valid
        Valid = 1,
    }

    impl std::fmt::Display for InsNavigationMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                InsNavigationMode::Invalid => f.write_str("Invalid"),
                InsNavigationMode::Valid => f.write_str("Valid"),
            }
        }
    }

    impl TryFrom<u8> for InsNavigationMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(InsNavigationMode::Invalid),
                1 => Ok(InsNavigationMode::Valid),
                i => Err(i),
            }
        }
    }
}

pub mod msg_baseline_heading {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Heading relative to True North
    ///
    /// This message reports the baseline heading pointing from the base station
    /// to the rover relative to True North. The full GPS time is given by the
    /// preceding MSG_GPS_TIME with the matching time-of-week (tow). It is
    /// intended that time-matched RTK mode is used when the base station is
    /// moving.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgBaselineHeading {
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

    impl MsgBaselineHeading {
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

    impl ConcreteMessage for MsgBaselineHeading {
        const MESSAGE_TYPE: u16 = 527;
        const MESSAGE_NAME: &'static str = "MSG_BASELINE_HEADING";
    }

    impl SbpMessage for MsgBaselineHeading {
        fn message_name(&self) -> &'static str {
            <Self as ConcreteMessage>::MESSAGE_NAME
        }
        fn message_type(&self) -> Option<u16> {
            Some(<Self as ConcreteMessage>::MESSAGE_TYPE)
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
        fn is_valid(&self) -> bool {
            true
        }
        fn into_valid_msg(self) -> Result<Self, crate::messages::invalid::Invalid> {
            Ok(self)
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

    impl FriendlyName for MsgBaselineHeading {
        fn friendly_name() -> &'static str {
            "BASELINE HEADING"
        }
    }

    impl TryFrom<Sbp> for MsgBaselineHeading {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgBaselineHeading(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgBaselineHeading {
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
            MsgBaselineHeading {
                sender_id: None,
                tow: WireFormat::parse_unchecked(buf),
                heading: WireFormat::parse_unchecked(buf),
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

pub mod msg_orient_euler {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Euler angles
    ///
    /// This message reports the yaw, pitch, and roll angles of the vehicle body
    /// frame. The rotations should applied intrinsically in the order yaw, pitch,
    /// and roll in order to rotate the from a frame aligned with the local-level
    /// NED frame to the vehicle body frame.  This message will only be available
    /// in future INS versions of Swift Products and is not produced by Piksi
    /// Multi or Duro.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgOrientEuler {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// rotation about the forward axis of the vehicle
        #[cfg_attr(feature = "serde", serde(rename = "roll"))]
        pub roll: i32,
        /// rotation about the rightward axis of the vehicle
        #[cfg_attr(feature = "serde", serde(rename = "pitch"))]
        pub pitch: i32,
        /// rotation about the downward axis of the vehicle
        #[cfg_attr(feature = "serde", serde(rename = "yaw"))]
        pub yaw: i32,
        /// Estimated standard deviation of roll
        #[cfg_attr(feature = "serde", serde(rename = "roll_accuracy"))]
        pub roll_accuracy: f32,
        /// Estimated standard deviation of pitch
        #[cfg_attr(feature = "serde", serde(rename = "pitch_accuracy"))]
        pub pitch_accuracy: f32,
        /// Estimated standard deviation of yaw
        #[cfg_attr(feature = "serde", serde(rename = "yaw_accuracy"))]
        pub yaw_accuracy: f32,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgOrientEuler {
        /// Gets the [InsNavigationMode][self::InsNavigationMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `InsNavigationMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `InsNavigationMode` were added.
        pub fn ins_navigation_mode(&self) -> Result<InsNavigationMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [InsNavigationMode][InsNavigationMode] of the `flags` bitfield.
        pub fn set_ins_navigation_mode(&mut self, ins_navigation_mode: InsNavigationMode) {
            set_bit_range!(&mut self.flags, ins_navigation_mode, u8, u8, 2, 0);
        }
    }

    impl ConcreteMessage for MsgOrientEuler {
        const MESSAGE_TYPE: u16 = 545;
        const MESSAGE_NAME: &'static str = "MSG_ORIENT_EULER";
    }

    impl SbpMessage for MsgOrientEuler {
        fn message_name(&self) -> &'static str {
            <Self as ConcreteMessage>::MESSAGE_NAME
        }
        fn message_type(&self) -> Option<u16> {
            Some(<Self as ConcreteMessage>::MESSAGE_TYPE)
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
        fn is_valid(&self) -> bool {
            true
        }
        fn into_valid_msg(self) -> Result<Self, crate::messages::invalid::Invalid> {
            Ok(self)
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

    impl FriendlyName for MsgOrientEuler {
        fn friendly_name() -> &'static str {
            "ORIENT EULER"
        }
    }

    impl TryFrom<Sbp> for MsgOrientEuler {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgOrientEuler(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgOrientEuler {
        const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <f32 as WireFormat>::MIN_LEN
            + <f32 as WireFormat>::MIN_LEN
            + <f32 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.tow)
                + WireFormat::len(&self.roll)
                + WireFormat::len(&self.pitch)
                + WireFormat::len(&self.yaw)
                + WireFormat::len(&self.roll_accuracy)
                + WireFormat::len(&self.pitch_accuracy)
                + WireFormat::len(&self.yaw_accuracy)
                + WireFormat::len(&self.flags)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.tow, buf);
            WireFormat::write(&self.roll, buf);
            WireFormat::write(&self.pitch, buf);
            WireFormat::write(&self.yaw, buf);
            WireFormat::write(&self.roll_accuracy, buf);
            WireFormat::write(&self.pitch_accuracy, buf);
            WireFormat::write(&self.yaw_accuracy, buf);
            WireFormat::write(&self.flags, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgOrientEuler {
                sender_id: None,
                tow: WireFormat::parse_unchecked(buf),
                roll: WireFormat::parse_unchecked(buf),
                pitch: WireFormat::parse_unchecked(buf),
                yaw: WireFormat::parse_unchecked(buf),
                roll_accuracy: WireFormat::parse_unchecked(buf),
                pitch_accuracy: WireFormat::parse_unchecked(buf),
                yaw_accuracy: WireFormat::parse_unchecked(buf),
                flags: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// INS Navigation mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum InsNavigationMode {
        /// Invalid
        Invalid = 0,

        /// Valid
        Valid = 1,
    }

    impl std::fmt::Display for InsNavigationMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                InsNavigationMode::Invalid => f.write_str("Invalid"),
                InsNavigationMode::Valid => f.write_str("Valid"),
            }
        }
    }

    impl TryFrom<u8> for InsNavigationMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(InsNavigationMode::Invalid),
                1 => Ok(InsNavigationMode::Valid),
                i => Err(i),
            }
        }
    }
}

pub mod msg_orient_quat {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Quaternion 4 component vector
    ///
    /// This message reports the quaternion vector describing the vehicle body
    /// frame's orientation with respect to a local-level NED frame. The
    /// components of the vector should sum to a unit vector assuming that the LSB
    /// of each component as a value of 2^-31. This message will only be available
    /// in future INS versions of Swift Products and is not produced by Piksi
    /// Multi or Duro.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgOrientQuat {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Real component
        #[cfg_attr(feature = "serde", serde(rename = "w"))]
        pub w: i32,
        /// 1st imaginary component
        #[cfg_attr(feature = "serde", serde(rename = "x"))]
        pub x: i32,
        /// 2nd imaginary component
        #[cfg_attr(feature = "serde", serde(rename = "y"))]
        pub y: i32,
        /// 3rd imaginary component
        #[cfg_attr(feature = "serde", serde(rename = "z"))]
        pub z: i32,
        /// Estimated standard deviation of w
        #[cfg_attr(feature = "serde", serde(rename = "w_accuracy"))]
        pub w_accuracy: f32,
        /// Estimated standard deviation of x
        #[cfg_attr(feature = "serde", serde(rename = "x_accuracy"))]
        pub x_accuracy: f32,
        /// Estimated standard deviation of y
        #[cfg_attr(feature = "serde", serde(rename = "y_accuracy"))]
        pub y_accuracy: f32,
        /// Estimated standard deviation of z
        #[cfg_attr(feature = "serde", serde(rename = "z_accuracy"))]
        pub z_accuracy: f32,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgOrientQuat {
        /// Gets the [InsNavigationMode][self::InsNavigationMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `InsNavigationMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `InsNavigationMode` were added.
        pub fn ins_navigation_mode(&self) -> Result<InsNavigationMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [InsNavigationMode][InsNavigationMode] of the `flags` bitfield.
        pub fn set_ins_navigation_mode(&mut self, ins_navigation_mode: InsNavigationMode) {
            set_bit_range!(&mut self.flags, ins_navigation_mode, u8, u8, 2, 0);
        }
    }

    impl ConcreteMessage for MsgOrientQuat {
        const MESSAGE_TYPE: u16 = 544;
        const MESSAGE_NAME: &'static str = "MSG_ORIENT_QUAT";
    }

    impl SbpMessage for MsgOrientQuat {
        fn message_name(&self) -> &'static str {
            <Self as ConcreteMessage>::MESSAGE_NAME
        }
        fn message_type(&self) -> Option<u16> {
            Some(<Self as ConcreteMessage>::MESSAGE_TYPE)
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
        fn is_valid(&self) -> bool {
            true
        }
        fn into_valid_msg(self) -> Result<Self, crate::messages::invalid::Invalid> {
            Ok(self)
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

    impl FriendlyName for MsgOrientQuat {
        fn friendly_name() -> &'static str {
            "ORIENT QUAT"
        }
    }

    impl TryFrom<Sbp> for MsgOrientQuat {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgOrientQuat(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgOrientQuat {
        const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <f32 as WireFormat>::MIN_LEN
            + <f32 as WireFormat>::MIN_LEN
            + <f32 as WireFormat>::MIN_LEN
            + <f32 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.tow)
                + WireFormat::len(&self.w)
                + WireFormat::len(&self.x)
                + WireFormat::len(&self.y)
                + WireFormat::len(&self.z)
                + WireFormat::len(&self.w_accuracy)
                + WireFormat::len(&self.x_accuracy)
                + WireFormat::len(&self.y_accuracy)
                + WireFormat::len(&self.z_accuracy)
                + WireFormat::len(&self.flags)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.tow, buf);
            WireFormat::write(&self.w, buf);
            WireFormat::write(&self.x, buf);
            WireFormat::write(&self.y, buf);
            WireFormat::write(&self.z, buf);
            WireFormat::write(&self.w_accuracy, buf);
            WireFormat::write(&self.x_accuracy, buf);
            WireFormat::write(&self.y_accuracy, buf);
            WireFormat::write(&self.z_accuracy, buf);
            WireFormat::write(&self.flags, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgOrientQuat {
                sender_id: None,
                tow: WireFormat::parse_unchecked(buf),
                w: WireFormat::parse_unchecked(buf),
                x: WireFormat::parse_unchecked(buf),
                y: WireFormat::parse_unchecked(buf),
                z: WireFormat::parse_unchecked(buf),
                w_accuracy: WireFormat::parse_unchecked(buf),
                x_accuracy: WireFormat::parse_unchecked(buf),
                y_accuracy: WireFormat::parse_unchecked(buf),
                z_accuracy: WireFormat::parse_unchecked(buf),
                flags: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// INS Navigation mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum InsNavigationMode {
        /// Invalid
        Invalid = 0,

        /// Valid
        Valid = 1,
    }

    impl std::fmt::Display for InsNavigationMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                InsNavigationMode::Invalid => f.write_str("Invalid"),
                InsNavigationMode::Valid => f.write_str("Valid"),
            }
        }
    }

    impl TryFrom<u8> for InsNavigationMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(InsNavigationMode::Invalid),
                1 => Ok(InsNavigationMode::Valid),
                i => Err(i),
            }
        }
    }
}

pub mod msg_orient_quat_cov {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Quaternion 4 component vector with full attitude covariance
    ///
    /// This message reports the orientation as a unit quaternion together with
    /// the upper triangle of the symmetric 3x3 attitude covariance matrix and a
    /// GPS time-of-week time-tag. The reference frame of the quaternion and the
    /// parameterization of the covariance matrix are both encoded in the flags
    /// field, allowing additional frames or parameterizations to be added later
    /// without introducing a new message. By default the quaternion describes the
    /// orientation of the vehicle body frame with respect to a local-level NED
    /// frame (matching MSG_ORIENT_QUAT) and the covariance is expressed as small-
    /// angle rotation errors about the axes of that NED frame; in this default
    /// case the cov_xx, cov_yy, cov_zz diagonal entries correspond to the
    /// variance of the rotation error about North, East, and Down respectively.
    /// The components of the quaternion sum to a unit vector assuming that the
    /// LSB of each component has a value of 2^-31. This message will only be
    /// available in future INS versions of Swift Products and is not produced by
    /// Piksi Multi or Duro.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgOrientQuatCov {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Real component
        #[cfg_attr(feature = "serde", serde(rename = "w"))]
        pub w: i32,
        /// 1st imaginary component
        #[cfg_attr(feature = "serde", serde(rename = "x"))]
        pub x: i32,
        /// 2nd imaginary component
        #[cfg_attr(feature = "serde", serde(rename = "y"))]
        pub y: i32,
        /// 3rd imaginary component
        #[cfg_attr(feature = "serde", serde(rename = "z"))]
        pub z: i32,
        /// Estimated variance of the rotation error about the 1st axis of the
        /// covariance frame
        #[cfg_attr(feature = "serde", serde(rename = "cov_xx"))]
        pub cov_xx: f32,
        /// Estimated covariance of the rotation errors about the 1st and 2nd axes
        /// of the covariance frame
        #[cfg_attr(feature = "serde", serde(rename = "cov_xy"))]
        pub cov_xy: f32,
        /// Estimated covariance of the rotation errors about the 1st and 3rd axes
        /// of the covariance frame
        #[cfg_attr(feature = "serde", serde(rename = "cov_xz"))]
        pub cov_xz: f32,
        /// Estimated variance of the rotation error about the 2nd axis of the
        /// covariance frame
        #[cfg_attr(feature = "serde", serde(rename = "cov_yy"))]
        pub cov_yy: f32,
        /// Estimated covariance of the rotation errors about the 2nd and 3rd axes
        /// of the covariance frame
        #[cfg_attr(feature = "serde", serde(rename = "cov_yz"))]
        pub cov_yz: f32,
        /// Estimated variance of the rotation error about the 3rd axis of the
        /// covariance frame
        #[cfg_attr(feature = "serde", serde(rename = "cov_zz"))]
        pub cov_zz: f32,
        /// Status flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
    }

    impl MsgOrientQuatCov {
        /// Gets the [CovarianceParameterization][self::CovarianceParameterization] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `CovarianceParameterization` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `CovarianceParameterization` were added.
        pub fn covariance_parameterization(&self) -> Result<CovarianceParameterization, u8> {
            get_bit_range!(self.flags, u8, u8, 6, 5).try_into()
        }

        /// Set the bitrange corresponding to the [CovarianceParameterization][CovarianceParameterization] of the `flags` bitfield.
        pub fn set_covariance_parameterization(
            &mut self,
            covariance_parameterization: CovarianceParameterization,
        ) {
            set_bit_range!(&mut self.flags, covariance_parameterization, u8, u8, 6, 5);
        }

        /// Gets the [QuaternionReferenceFrame][self::QuaternionReferenceFrame] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `QuaternionReferenceFrame` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `QuaternionReferenceFrame` were added.
        pub fn quaternion_reference_frame(&self) -> Result<QuaternionReferenceFrame, u8> {
            get_bit_range!(self.flags, u8, u8, 4, 3).try_into()
        }

        /// Set the bitrange corresponding to the [QuaternionReferenceFrame][QuaternionReferenceFrame] of the `flags` bitfield.
        pub fn set_quaternion_reference_frame(
            &mut self,
            quaternion_reference_frame: QuaternionReferenceFrame,
        ) {
            set_bit_range!(&mut self.flags, quaternion_reference_frame, u8, u8, 4, 3);
        }

        /// Gets the [InsNavigationMode][self::InsNavigationMode] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `InsNavigationMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `InsNavigationMode` were added.
        pub fn ins_navigation_mode(&self) -> Result<InsNavigationMode, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [InsNavigationMode][InsNavigationMode] of the `flags` bitfield.
        pub fn set_ins_navigation_mode(&mut self, ins_navigation_mode: InsNavigationMode) {
            set_bit_range!(&mut self.flags, ins_navigation_mode, u8, u8, 2, 0);
        }
    }

    impl ConcreteMessage for MsgOrientQuatCov {
        const MESSAGE_TYPE: u16 = 547;
        const MESSAGE_NAME: &'static str = "MSG_ORIENT_QUAT_COV";
    }

    impl SbpMessage for MsgOrientQuatCov {
        fn message_name(&self) -> &'static str {
            <Self as ConcreteMessage>::MESSAGE_NAME
        }
        fn message_type(&self) -> Option<u16> {
            Some(<Self as ConcreteMessage>::MESSAGE_TYPE)
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
        fn is_valid(&self) -> bool {
            true
        }
        fn into_valid_msg(self) -> Result<Self, crate::messages::invalid::Invalid> {
            Ok(self)
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

    impl FriendlyName for MsgOrientQuatCov {
        fn friendly_name() -> &'static str {
            "ORIENT QUAT COV"
        }
    }

    impl TryFrom<Sbp> for MsgOrientQuatCov {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgOrientQuatCov(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgOrientQuatCov {
        const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <f32 as WireFormat>::MIN_LEN
            + <f32 as WireFormat>::MIN_LEN
            + <f32 as WireFormat>::MIN_LEN
            + <f32 as WireFormat>::MIN_LEN
            + <f32 as WireFormat>::MIN_LEN
            + <f32 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.tow)
                + WireFormat::len(&self.w)
                + WireFormat::len(&self.x)
                + WireFormat::len(&self.y)
                + WireFormat::len(&self.z)
                + WireFormat::len(&self.cov_xx)
                + WireFormat::len(&self.cov_xy)
                + WireFormat::len(&self.cov_xz)
                + WireFormat::len(&self.cov_yy)
                + WireFormat::len(&self.cov_yz)
                + WireFormat::len(&self.cov_zz)
                + WireFormat::len(&self.flags)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.tow, buf);
            WireFormat::write(&self.w, buf);
            WireFormat::write(&self.x, buf);
            WireFormat::write(&self.y, buf);
            WireFormat::write(&self.z, buf);
            WireFormat::write(&self.cov_xx, buf);
            WireFormat::write(&self.cov_xy, buf);
            WireFormat::write(&self.cov_xz, buf);
            WireFormat::write(&self.cov_yy, buf);
            WireFormat::write(&self.cov_yz, buf);
            WireFormat::write(&self.cov_zz, buf);
            WireFormat::write(&self.flags, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgOrientQuatCov {
                sender_id: None,
                tow: WireFormat::parse_unchecked(buf),
                w: WireFormat::parse_unchecked(buf),
                x: WireFormat::parse_unchecked(buf),
                y: WireFormat::parse_unchecked(buf),
                z: WireFormat::parse_unchecked(buf),
                cov_xx: WireFormat::parse_unchecked(buf),
                cov_xy: WireFormat::parse_unchecked(buf),
                cov_xz: WireFormat::parse_unchecked(buf),
                cov_yy: WireFormat::parse_unchecked(buf),
                cov_yz: WireFormat::parse_unchecked(buf),
                cov_zz: WireFormat::parse_unchecked(buf),
                flags: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Covariance parameterization
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum CovarianceParameterization {
        /// Small-angle rotation errors about the axes of the global frame given by
        /// the quaternion frame field
        SmallAngleRotationErrorsAboutTheAxesOfTheGlobalFrameGivenByTheQuaternionFrameField = 0,

        /// Small-angle rotation errors about the body/vehicle frame axes
        SmallAngleRotationErrorsAboutTheBodyvehicleFrameAxes = 1,

        /// Roll/pitch/yaw Euler-angle covariance (radians)
        RollpitchyawEulerAngleCovariance = 2,
    }

    impl std::fmt::Display for CovarianceParameterization {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
            CovarianceParameterization::SmallAngleRotationErrorsAboutTheAxesOfTheGlobalFrameGivenByTheQuaternionFrameField => f.write_str("Small-angle rotation errors about the axes of the global frame given by the quaternion frame field"),
            CovarianceParameterization::SmallAngleRotationErrorsAboutTheBodyvehicleFrameAxes => f.write_str("Small-angle rotation errors about the body/vehicle frame axes"),
            CovarianceParameterization::RollpitchyawEulerAngleCovariance => f.write_str("Roll/pitch/yaw Euler-angle covariance (radians)"),
        }
        }
    }

    impl TryFrom<u8> for CovarianceParameterization {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
            0 => Ok( CovarianceParameterization :: SmallAngleRotationErrorsAboutTheAxesOfTheGlobalFrameGivenByTheQuaternionFrameField ),
            1 => Ok( CovarianceParameterization :: SmallAngleRotationErrorsAboutTheBodyvehicleFrameAxes ),
            2 => Ok( CovarianceParameterization :: RollpitchyawEulerAngleCovariance ),
            i => Err(i),
        }
        }
    }

    /// Quaternion reference frame
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum QuaternionReferenceFrame {
        /// Local-level NED
        LocalLevelNed = 0,

        /// Local-level ENU
        LocalLevelEnu = 1,

        /// ECEF
        Ecef = 2,
    }

    impl std::fmt::Display for QuaternionReferenceFrame {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                QuaternionReferenceFrame::LocalLevelNed => f.write_str("Local-level NED"),
                QuaternionReferenceFrame::LocalLevelEnu => f.write_str("Local-level ENU"),
                QuaternionReferenceFrame::Ecef => f.write_str("ECEF"),
            }
        }
    }

    impl TryFrom<u8> for QuaternionReferenceFrame {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(QuaternionReferenceFrame::LocalLevelNed),
                1 => Ok(QuaternionReferenceFrame::LocalLevelEnu),
                2 => Ok(QuaternionReferenceFrame::Ecef),
                i => Err(i),
            }
        }
    }

    /// INS Navigation mode
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum InsNavigationMode {
        /// Invalid
        Invalid = 0,

        /// Valid
        Valid = 1,
    }

    impl std::fmt::Display for InsNavigationMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                InsNavigationMode::Invalid => f.write_str("Invalid"),
                InsNavigationMode::Valid => f.write_str("Valid"),
            }
        }
    }

    impl TryFrom<u8> for InsNavigationMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(InsNavigationMode::Invalid),
                1 => Ok(InsNavigationMode::Valid),
                i => Err(i),
            }
        }
    }
}
