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
// Automatically generated from yaml/swiftnav/sbp/sbas.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! SBAS data

#[allow(unused_imports)]
use std::convert::TryFrom;

#[allow(unused_imports)]
use byteorder::{LittleEndian, ReadBytesExt};

use super::gnss::*;
#[allow(unused_imports)]
use crate::serialize::SbpSerialize;
#[allow(unused_imports)]
use crate::SbpString;

/// Raw SBAS data
///
/// This message is sent once per second per SBAS satellite. ME checks the
/// parity of the data block and sends only blocks that pass the check.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSbasRaw {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GNSS signal identifier.
    pub sid: GnssSignal,
    /// GPS time-of-week at the start of the data block.
    pub tow: u32,
    /// SBAS message type (0-63)
    pub message_type: u8,
    /// Raw SBAS data field of 212 bits (last byte padded with zeros).
    pub data: Vec<u8>,
}

impl MsgSbasRaw {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSbasRaw, crate::Error> {
        Ok( MsgSbasRaw{
            sender_id: None,
            sid: GnssSignal::parse(_buf)?,
            tow: _buf.read_u32::<LittleEndian>()?,
            message_type: _buf.read_u8()?,
            data: crate::parser::read_u8_array_limit(_buf, 27)?,
        } )
    }
}
impl super::SBPMessage for MsgSbasRaw {
    fn get_message_name(&self) -> &'static str {
        "MSG_SBAS_RAW"
    }

    fn get_message_type(&self) -> u16 {
        30583
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
impl super::ConcreteMessage for MsgSbasRaw {
    const MESSAGE_TYPE: u16 = 30583;
    const MESSAGE_NAME: &'static str = "MSG_SBAS_RAW";
}
impl TryFrom<super::SBP> for MsgSbasRaw {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSbasRaw(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSbasRaw {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sid.append_to_sbp_buffer(buf);
        self.tow.append_to_sbp_buffer(buf);
        self.message_type.append_to_sbp_buffer(buf);
        self.data.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sid.sbp_size();
        size += self.tow.sbp_size();
        size += self.message_type.sbp_size();
        size += self.data.sbp_size();
        size
    }
}
