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

// Inertial Measurement Unit (IMU) messages.
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian,ReadBytesExt};


// Raw IMU data
//
// Raw data from the Inertial Measurement Unit, containing accelerometer and
// gyroscope readings. The sense of the measurements are to be aligned with 
// the indications on the device itself.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgImuRaw {
    pub tow: u32,
        // ^ Milliseconds since start of GPS week. If the high bit is set, the time
        // is unknown or invalid.
    pub tow_f: u8,
        // ^ Milliseconds since start of GPS week, fractional part
    pub acc_x: i16,
        // ^ Acceleration in the IMU frame X axis
    pub acc_y: i16,
        // ^ Acceleration in the IMU frame Y axis
    pub acc_z: i16,
        // ^ Acceleration in the IMU frame Z axis
    pub gyr_x: i16,
        // ^ Angular rate around IMU frame X axis
    pub gyr_y: i16,
        // ^ Angular rate around IMU frame Y axis
    pub gyr_z: i16,
        // ^ Angular rate around IMU frame Z axis
}

impl MsgImuRaw {
    pub const TYPE: u16 = 2304;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgImuRaw, ::Error> {
        Ok( MsgImuRaw{
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


// Auxiliary IMU data
//
// Auxiliary data specific to a particular IMU. The `imu_type` field will
// always be consistent but the rest of the payload is device specific and
// depends on the value of `imu_type`.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgImuAux {
    pub imu_type: u8,
        // ^ IMU type
    pub temp: i16,
        // ^ Raw IMU temperature
    pub imu_conf: u8,
        // ^ IMU configuration
}

impl MsgImuAux {
    pub const TYPE: u16 = 2305;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgImuAux, ::Error> {
        Ok( MsgImuAux{
            imu_type: _buf.read_u8()?,
            temp: _buf.read_i16::<LittleEndian>()?,
            imu_conf: _buf.read_u8()?,
        } )
    }
}

