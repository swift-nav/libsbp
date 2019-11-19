// Copyright (C) 2015-2018 Swift Navigation Inc.
// Contact: Swift Navigation <dev@swiftnav.com>
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

extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
#[cfg(feature = "serialize")]
use serde::{Deserialize, Serialize};

/// Auxiliary IMU data
///
/// Auxiliary data specific to a particular IMU. The `imu_type` field will
/// always be consistent but the rest of the payload is device specific and
/// depends on the value of `imu_type`.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgImuAux {
    pub sender_id: Option<u16>,
    /// IMU type
    pub imu_type: u8,
    /// Raw IMU temperature
    pub temp: i16,
    /// IMU configuration
    pub imu_conf: u8,
}

impl MsgImuAux {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgImuAux, crate::Error> {
        Ok(MsgImuAux {
            sender_id: None,
            imu_type: _buf.read_u8()?,
            temp: _buf.read_i16::<LittleEndian>()?,
            imu_conf: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgImuAux {
    fn get_message_type(&self) -> u16 {
        2305
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
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
/// the indications on the device itself. Measurement units, which are specific to the
/// device hardware and settings, are communicated via the MSG_IMU_AUX message.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgImuRaw {
    pub sender_id: Option<u16>,
    /// Milliseconds since start of GPS week. If the high bit is set, the time
    /// is unknown or invalid.
    pub tow: u32,
    /// Milliseconds since start of GPS week, fractional part
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgImuRaw, crate::Error> {
        Ok(MsgImuRaw {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            tow_f: _buf.read_u8()?,
            acc_x: _buf.read_i16::<LittleEndian>()?,
            acc_y: _buf.read_i16::<LittleEndian>()?,
            acc_z: _buf.read_i16::<LittleEndian>()?,
            gyr_x: _buf.read_i16::<LittleEndian>()?,
            gyr_y: _buf.read_i16::<LittleEndian>()?,
            gyr_z: _buf.read_i16::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgImuRaw {
    fn get_message_type(&self) -> u16 {
        2304
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
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
