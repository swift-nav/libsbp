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
// Automatically generated from yaml/swiftnav/sbp/mag.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
// Magnetometer (mag) messages.
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};

// Raw magnetometer data
//
// Raw data from the magnetometer.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgMagRaw {
    pub tow: u32,
    // ^ Milliseconds since start of GPS week. If the high bit is set, the time
    // is unknown or invalid.
    pub tow_f: u8,
    // ^ Milliseconds since start of GPS week, fractional part
    pub mag_x: i16,
    // ^ Magnetic field in the body frame X axis
    pub mag_y: i16,
    // ^ Magnetic field in the body frame Y axis
    pub mag_z: i16,
    // ^ Magnetic field in the body frame Z axis
}

impl MsgMagRaw {
    pub const TYPE: u16 = 2306;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgMagRaw, ::parser::MessageError> {
        Ok(MsgMagRaw {
            tow: _buf.read_u32::<LittleEndian>()?,
            tow_f: _buf.read_u8()?,
            mag_x: _buf.read_i16::<LittleEndian>()?,
            mag_y: _buf.read_i16::<LittleEndian>()?,
            mag_z: _buf.read_i16::<LittleEndian>()?,
        })
    }
}
