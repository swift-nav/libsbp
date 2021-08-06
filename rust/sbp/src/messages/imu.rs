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

#[allow(unused_imports)]
use std::convert::TryFrom;

#[allow(unused_imports)]
use byteorder::{LittleEndian, ReadBytesExt};

#[allow(unused_imports)]
use crate::serialize::SbpSerialize;
#[allow(unused_imports)]
use crate::SbpString;

/// Auxiliary IMU data
///
/// Auxiliary data specific to a particular IMU. The `imu_type` field will
/// always be consistent but the rest of the payload is device specific and
/// depends on the value of `imu_type`.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgImuAux {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// IMU type
    pub imu_type: u8,
    /// Raw IMU temperature
    pub temp: i16,
    /// IMU configuration
    pub imu_conf: u8,
}

impl MsgImuAux {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgImuAux, crate::Error> {
        Ok( MsgImuAux{
            sender_id: None,
            imu_type: _buf.read_u8()?,
            temp: _buf.read_i16::<LittleEndian>()?,
            imu_conf: _buf.read_u8()?,
        } )
    }
}
impl super::SBPMessage for MsgImuAux {
    fn get_message_name(&self) -> &'static str {
        "MSG_IMU_AUX"
    }

    fn get_message_type(&self) -> u16 {
        2305
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgImuAux {
    const MESSAGE_TYPE: u16 = 2305;
    const MESSAGE_NAME: &'static str = "MSG_IMU_AUX";
}
impl TryFrom<super::SBP> for MsgImuAux {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgImuAux(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgImuAux {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.imu_type.append_to_sbp_buffer(buf);
        self.temp.append_to_sbp_buffer(buf);
        self.imu_conf.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.imu_type.sbp_size();
        size += self.temp.sbp_size();
        size += self.imu_conf.sbp_size();
        size
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
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgImuRaw {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Milliseconds since reference epoch and time status.
    pub tow: u32,
    /// Milliseconds since reference epoch, fractional part
    pub tow_f: u8,
    /// Acceleration in the IMU frame X axis
    pub acc_x: i16,
    /// Acceleration in the IMU frame Y axis
    pub acc_y: i16,
    /// Acceleration in the IMU frame Z axis
    pub acc_z: i16,
    /// Angular rate around IMU frame X axis
    pub gyr_x: i16,
    /// Angular rate around IMU frame Y axis
    pub gyr_y: i16,
    /// Angular rate around IMU frame Z axis
    pub gyr_z: i16,
}

impl MsgImuRaw {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgImuRaw, crate::Error> {
        Ok( MsgImuRaw{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            tow_f: _buf.read_u8()?,
            acc_x: _buf.read_i16::<LittleEndian>()?,
            acc_y: _buf.read_i16::<LittleEndian>()?,
            acc_z: _buf.read_i16::<LittleEndian>()?,
            gyr_x: _buf.read_i16::<LittleEndian>()?,
            gyr_y: _buf.read_i16::<LittleEndian>()?,
            gyr_z: _buf.read_i16::<LittleEndian>()?,
        } )
    }
}
impl super::SBPMessage for MsgImuRaw {
    fn get_message_name(&self) -> &'static str {
        "MSG_IMU_RAW"
    }

    fn get_message_type(&self) -> u16 {
        2304
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }

    #[cfg(feature = "swiftnav-rs")]
    fn gps_time(
        &self,
    ) -> Option<std::result::Result<crate::time::MessageTime, crate::time::GpsTimeError>> {
        const IMU_RAW_TIME_STATUS_MASK: u32 = (1 << 30) | (1 << 31);
        if self.tow & IMU_RAW_TIME_STATUS_MASK != 0 {
            return None;
        }
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match crate::time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(crate::time::MessageTime::Rover(gps_time.into())))
    }
}
impl super::ConcreteMessage for MsgImuRaw {
    const MESSAGE_TYPE: u16 = 2304;
    const MESSAGE_NAME: &'static str = "MSG_IMU_RAW";
}
impl TryFrom<super::SBP> for MsgImuRaw {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgImuRaw(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgImuRaw {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.tow_f.append_to_sbp_buffer(buf);
        self.acc_x.append_to_sbp_buffer(buf);
        self.acc_y.append_to_sbp_buffer(buf);
        self.acc_z.append_to_sbp_buffer(buf);
        self.gyr_x.append_to_sbp_buffer(buf);
        self.gyr_y.append_to_sbp_buffer(buf);
        self.gyr_z.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.tow_f.sbp_size();
        size += self.acc_x.sbp_size();
        size += self.acc_y.sbp_size();
        size += self.acc_z.sbp_size();
        size += self.gyr_x.sbp_size();
        size += self.gyr_y.sbp_size();
        size += self.gyr_z.sbp_size();
        size
    }
}
