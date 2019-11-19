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
//! Magnetometer (mag) messages.

extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
#[cfg(feature = "serialize")]
use serde::{Deserialize, Serialize};

/// Raw magnetometer data
///
/// Raw data from the magnetometer.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgMagRaw {
    pub sender_id: Option<u16>,
    /// Milliseconds since start of GPS week. If the high bit is set, the time
    /// is unknown or invalid.
    pub tow: u32,
    /// Milliseconds since start of GPS week, fractional part
    pub tow_f: u8,
    /// Magnetic field in the body frame X axis
    pub mag_x: i16,
    /// Magnetic field in the body frame Y axis
    pub mag_y: i16,
    /// Magnetic field in the body frame Z axis
    pub mag_z: i16,
}

impl MsgMagRaw {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgMagRaw, crate::Error> {
        Ok(MsgMagRaw {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            tow_f: _buf.read_u8()?,
            mag_x: _buf.read_i16::<LittleEndian>()?,
            mag_y: _buf.read_i16::<LittleEndian>()?,
            mag_z: _buf.read_i16::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgMagRaw {
    fn get_message_type(&self) -> u16 {
        2306
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

impl crate::serialize::SbpSerialize for MsgMagRaw {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.tow_f.append_to_sbp_buffer(buf);
        self.mag_x.append_to_sbp_buffer(buf);
        self.mag_y.append_to_sbp_buffer(buf);
        self.mag_z.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.tow_f.sbp_size();
        size += self.mag_x.sbp_size();
        size += self.mag_y.sbp_size();
        size += self.mag_z.sbp_size();
        size
    }
}
