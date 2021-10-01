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
// Automatically generated from yaml/swiftnav/sbp/orientation.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Orientation Messages

use super::lib::*;

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
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgAngularRate {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// angular rate about x axis
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x")))]
    pub x: i32,
    /// angular rate about y axis
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y")))]
    pub y: i32,
    /// angular rate about z axis
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z")))]
    pub z: i32,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgAngularRate {
    const MESSAGE_TYPE: u16 = 546;
    const MESSAGE_NAME: &'static str = "MSG_ANGULAR_RATE";
}

impl SbpMessage for MsgAngularRate {
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

impl TryFrom<Sbp> for MsgAngularRate {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgAngularRate(m) => Ok(m),
            _ => Err(TryFromSbpError),
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

/// Heading relative to True North
///
/// This message reports the baseline heading pointing from the base station
/// to the rover relative to True North. The full GPS time is given by the
/// preceding MSG_GPS_TIME with the matching time-of-week (tow). It is
/// intended that time-matched RTK mode is used when the base station is
/// moving.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgBaselineHeading {
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

impl ConcreteMessage for MsgBaselineHeading {
    const MESSAGE_TYPE: u16 = 527;
    const MESSAGE_NAME: &'static str = "MSG_BASELINE_HEADING";
}

impl SbpMessage for MsgBaselineHeading {
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

impl TryFrom<Sbp> for MsgBaselineHeading {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgBaselineHeading(m) => Ok(m),
            _ => Err(TryFromSbpError),
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

/// Euler angles
///
/// This message reports the yaw, pitch, and roll angles of the vehicle body
/// frame. The rotations should applied intrinsically in the order yaw, pitch,
/// and roll in order to rotate the from a frame aligned with the local-level
/// NED frame to the vehicle body frame.  This message will only be available
/// in future INS versions of Swift Products and is not produced by Piksi
/// Multi or Duro.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgOrientEuler {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// rotation about the forward axis of the vehicle
    #[cfg_attr(feature = "serde", serde(rename(serialize = "roll")))]
    pub roll: i32,
    /// rotation about the rightward axis of the vehicle
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pitch")))]
    pub pitch: i32,
    /// rotation about the downward axis of the vehicle
    #[cfg_attr(feature = "serde", serde(rename(serialize = "yaw")))]
    pub yaw: i32,
    /// Estimated standard deviation of roll
    #[cfg_attr(feature = "serde", serde(rename(serialize = "roll_accuracy")))]
    pub roll_accuracy: f32,
    /// Estimated standard deviation of pitch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pitch_accuracy")))]
    pub pitch_accuracy: f32,
    /// Estimated standard deviation of yaw
    #[cfg_attr(feature = "serde", serde(rename(serialize = "yaw_accuracy")))]
    pub yaw_accuracy: f32,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgOrientEuler {
    const MESSAGE_TYPE: u16 = 545;
    const MESSAGE_NAME: &'static str = "MSG_ORIENT_EULER";
}

impl SbpMessage for MsgOrientEuler {
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

impl TryFrom<Sbp> for MsgOrientEuler {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgOrientEuler(m) => Ok(m),
            _ => Err(TryFromSbpError),
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

/// Quaternion 4 component vector
///
/// This message reports the quaternion vector describing the vehicle body
/// frame's orientation with respect to a local-level NED frame. The
/// components of the vector should sum to a unit vector assuming that the LSB
/// of each component as a value of 2^-31. This message will only be available
/// in future INS versions of Swift Products and is not produced by Piksi
/// Multi or Duro.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgOrientQuat {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Real component
    #[cfg_attr(feature = "serde", serde(rename(serialize = "w")))]
    pub w: i32,
    /// 1st imaginary component
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x")))]
    pub x: i32,
    /// 2nd imaginary component
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y")))]
    pub y: i32,
    /// 3rd imaginary component
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z")))]
    pub z: i32,
    /// Estimated standard deviation of w
    #[cfg_attr(feature = "serde", serde(rename(serialize = "w_accuracy")))]
    pub w_accuracy: f32,
    /// Estimated standard deviation of x
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x_accuracy")))]
    pub x_accuracy: f32,
    /// Estimated standard deviation of y
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y_accuracy")))]
    pub y_accuracy: f32,
    /// Estimated standard deviation of z
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z_accuracy")))]
    pub z_accuracy: f32,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgOrientQuat {
    const MESSAGE_TYPE: u16 = 544;
    const MESSAGE_NAME: &'static str = "MSG_ORIENT_QUAT";
}

impl SbpMessage for MsgOrientQuat {
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

impl TryFrom<Sbp> for MsgOrientQuat {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgOrientQuat(m) => Ok(m),
            _ => Err(TryFromSbpError),
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
