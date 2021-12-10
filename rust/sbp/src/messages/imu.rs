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
// Automatically generated from yaml/swiftnav/sbp/imu.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Inertial Measurement Unit (IMU) messages.

use super::lib::*;

/// Auxiliary IMU data
///
/// Auxiliary data specific to a particular IMU. The `imu_type` field will
/// always be consistent but the rest of the payload is device specific and
/// depends on the value of `imu_type`.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgImuAux {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// IMU type
    #[cfg_attr(feature = "serde", serde(rename(serialize = "imu_type")))]
    pub imu_type: u8,
    /// Raw IMU temperature
    #[cfg_attr(feature = "serde", serde(rename(serialize = "temp")))]
    pub temp: i16,
    /// IMU configuration
    #[cfg_attr(feature = "serde", serde(rename(serialize = "imu_conf")))]
    pub imu_conf: u8,
}

impl ConcreteMessage for MsgImuAux {
    const MESSAGE_TYPE: u16 = 2305;
    const MESSAGE_NAME: &'static str = "MSG_IMU_AUX";
}

impl SbpMessage for MsgImuAux {
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

impl TryFrom<Sbp> for MsgImuAux {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgImuAux(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgImuAux {
    const MIN_LEN: usize =
        <u8 as WireFormat>::MIN_LEN + <i16 as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.imu_type)
            + WireFormat::len(&self.temp)
            + WireFormat::len(&self.imu_conf)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.imu_type, buf);
        WireFormat::write(&self.temp, buf);
        WireFormat::write(&self.imu_conf, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgImuAux {
            sender_id: None,
            imu_type: WireFormat::parse_unchecked(buf),
            temp: WireFormat::parse_unchecked(buf),
            imu_conf: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Raw IMU data
///
/// Raw data from the Inertial Measurement Unit, containing accelerometer and
/// gyroscope readings. The sense of the measurements are to be aligned with
/// the indications on the device itself. Measurement units, which are
/// specific to the device hardware and settings, are communicated via the
/// MSG_IMU_AUX message. If using "time since startup" time tags, the
/// receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes
/// available to synchronise IMU measurements with GNSS. The timestamp must
/// wrap around to zero when reaching one week (604800 seconds).
///
/// The time-tagging mode should not change throughout a run.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgImuRaw {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Milliseconds since reference epoch and time status.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Milliseconds since reference epoch, fractional part
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow_f")))]
    pub tow_f: u8,
    /// Acceleration in the IMU frame X axis
    #[cfg_attr(feature = "serde", serde(rename(serialize = "acc_x")))]
    pub acc_x: i16,
    /// Acceleration in the IMU frame Y axis
    #[cfg_attr(feature = "serde", serde(rename(serialize = "acc_y")))]
    pub acc_y: i16,
    /// Acceleration in the IMU frame Z axis
    #[cfg_attr(feature = "serde", serde(rename(serialize = "acc_z")))]
    pub acc_z: i16,
    /// Angular rate around IMU frame X axis
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gyr_x")))]
    pub gyr_x: i16,
    /// Angular rate around IMU frame Y axis
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gyr_y")))]
    pub gyr_y: i16,
    /// Angular rate around IMU frame Z axis
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gyr_z")))]
    pub gyr_z: i16,
}

impl ConcreteMessage for MsgImuRaw {
    const MESSAGE_TYPE: u16 = 2304;
    const MESSAGE_NAME: &'static str = "MSG_IMU_RAW";
}

impl SbpMessage for MsgImuRaw {
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
        const IMU_RAW_TIME_STATUS_MASK: u32 = (1 << 30) | (1 << 31);
        if self.tow & IMU_RAW_TIME_STATUS_MASK != 0 {
            return None;
        }
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgImuRaw {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgImuRaw(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgImuRaw {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.tow_f)
            + WireFormat::len(&self.acc_x)
            + WireFormat::len(&self.acc_y)
            + WireFormat::len(&self.acc_z)
            + WireFormat::len(&self.gyr_x)
            + WireFormat::len(&self.gyr_y)
            + WireFormat::len(&self.gyr_z)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.tow_f, buf);
        WireFormat::write(&self.acc_x, buf);
        WireFormat::write(&self.acc_y, buf);
        WireFormat::write(&self.acc_z, buf);
        WireFormat::write(&self.gyr_x, buf);
        WireFormat::write(&self.gyr_y, buf);
        WireFormat::write(&self.gyr_z, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgImuRaw {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            tow_f: WireFormat::parse_unchecked(buf),
            acc_x: WireFormat::parse_unchecked(buf),
            acc_y: WireFormat::parse_unchecked(buf),
            acc_z: WireFormat::parse_unchecked(buf),
            gyr_x: WireFormat::parse_unchecked(buf),
            gyr_y: WireFormat::parse_unchecked(buf),
            gyr_z: WireFormat::parse_unchecked(buf),
        }
    }
}
