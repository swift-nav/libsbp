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
// Automatically generated from yaml/swiftnav/sbp/ext_events.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages reporting accurately-timestamped external events, e.g. camera
//! shutter time.

#[allow(unused_imports)]
use std::convert::TryFrom;

#[allow(unused_imports)]
use byteorder::{LittleEndian, ReadBytesExt};

#[allow(unused_imports)]
use crate::serialize::SbpSerialize;
#[allow(unused_imports)]
use crate::SbpString;

/// Reports timestamped external pin event
///
/// Reports detection of an external event, the GPS time it occurred, which
/// pin it was and whether it was rising or falling.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgExtEvent {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS week number
    pub wn: u16,
    /// GPS time of week rounded to the nearest millisecond
    pub tow: u32,
    /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    /// 500000)
    pub ns_residual: i32,
    /// Flags
    pub flags: u8,
    /// Pin number.  0..9 = DEBUG0..9.
    pub pin: u8,
}

impl MsgExtEvent {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgExtEvent, crate::Error> {
        Ok( MsgExtEvent{
            sender_id: None,
            wn: _buf.read_u16::<LittleEndian>()?,
            tow: _buf.read_u32::<LittleEndian>()?,
            ns_residual: _buf.read_i32::<LittleEndian>()?,
            flags: _buf.read_u8()?,
            pin: _buf.read_u8()?,
        } )
    }
}
impl super::SBPMessage for MsgExtEvent {
    fn get_message_name(&self) -> &'static str {
        "MSG_EXT_EVENT"
    }

    fn get_message_type(&self) -> u16 {
        257
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
        let wn = match i16::try_from(self.wn) {
            Ok(wn) => wn,
            Err(e) => return Some(Err(e.into())),
        };
        let gps_time = match crate::time::GpsTime::new(wn, tow_s) {
            Ok(gps_time) => gps_time,
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(crate::time::MessageTime::Rover(gps_time.into())))
    }
}
impl super::ConcreteMessage for MsgExtEvent {
    const MESSAGE_TYPE: u16 = 257;
    const MESSAGE_NAME: &'static str = "MSG_EXT_EVENT";
}
impl TryFrom<super::SBP> for MsgExtEvent {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgExtEvent(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgExtEvent {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.wn.append_to_sbp_buffer(buf);
        self.tow.append_to_sbp_buffer(buf);
        self.ns_residual.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
        self.pin.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.wn.sbp_size();
        size += self.tow.sbp_size();
        size += self.ns_residual.sbp_size();
        size += self.flags.sbp_size();
        size += self.pin.sbp_size();
        size
    }
}
