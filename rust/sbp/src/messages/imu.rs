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
/// Inertial Measurement Unit (IMU) messages.
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};

/// Raw IMU data
///
/// Raw data from the Inertial Measurement Unit, containing accelerometer and
/// gyroscope readings. The sense of the measurements are to be aligned with
/// the indications on the device itself. Measurement units, which are specific to the
/// device hardware and settings, are communicated via the MSG_IMU_AUX message.
///
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgImuRaw, ::Error> {
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
    const MSG_ID: u16 = 2304;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Auxiliary IMU data
///
/// Auxiliary data specific to a particular IMU. The `imu_type` field will
/// always be consistent but the rest of the payload is device specific and
/// depends on the value of `imu_type`.
///
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgImuAux, ::Error> {
        Ok(MsgImuAux {
            sender_id: None,
            imu_type: _buf.read_u8()?,
            temp: _buf.read_i16::<LittleEndian>()?,
            imu_conf: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgImuAux {
    const MSG_ID: u16 = 2305;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}
