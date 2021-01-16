// Copyright (C) 2015-2018 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
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

#[cfg(feature = "sbp_serde")]
use serde::{Deserialize, Serialize};

#[allow(unused_imports)]
use crate::{parser::SbpParse, BoundedSbpString, UnboundedSbpString};

/// Raw magnetometer data
///
/// Raw data from the magnetometer.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
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

impl SbpParse<MsgMagRaw> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgMagRaw> {
        Ok( MsgMagRaw{
            sender_id: None,
            tow: self.parse()?,
            tow_f: self.parse()?,
            mag_x: self.parse()?,
            mag_y: self.parse()?,
            mag_z: self.parse()?,
        } )
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
