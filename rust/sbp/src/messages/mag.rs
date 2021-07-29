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
// Automatically generated from yaml/swiftnav/sbp/mag.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Magnetometer (mag) messages.

#[allow(unused_imports)]
use std::convert::TryFrom;

#[allow(unused_imports)]
use byteorder::{LittleEndian, ReadBytesExt};

#[allow(unused_imports)]
use crate::serialize::SbpSerialize;
#[allow(unused_imports)]
use crate::SbpString;

/// Raw magnetometer data
///
/// Raw data from the magnetometer.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgMagRaw {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
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
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgMagRaw, crate::Error> {
        Ok( MsgMagRaw{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            tow_f: _buf.read_u8()?,
            mag_x: _buf.read_i16::<LittleEndian>()?,
            mag_y: _buf.read_i16::<LittleEndian>()?,
            mag_z: _buf.read_i16::<LittleEndian>()?,
        } )
    }
}
impl super::SBPMessage for MsgMagRaw {
    fn get_message_name(&self) -> &'static str {
        "MSG_MAG_RAW"
    }

    fn get_message_type(&self) -> u16 {
        2306
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
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match crate::time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(crate::time::MessageTime::Rover(gps_time.into())))
    }
}
impl super::ConcreteMessage for MsgMagRaw {
    const MESSAGE_TYPE: u16 = 2306;
    const MESSAGE_NAME: &'static str = "MSG_MAG_RAW";
}
impl TryFrom<super::SBP> for MsgMagRaw {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgMagRaw(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
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
