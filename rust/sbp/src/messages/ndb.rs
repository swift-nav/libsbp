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
// Automatically generated from yaml/swiftnav/sbp/ndb.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages for logging NDB events.
//!

extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
use super::gnss::*;
#[cfg(feature = "serialize")]
use serde::{Deserialize, Serialize};

/// Navigation DataBase Event
///
/// This message is sent out when an object is stored into NDB. If needed
/// message could also be sent out when fetching an object from NDB.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgNdbEvent {
    pub sender_id: Option<u16>,
    /// HW time in milliseconds.
    pub recv_time: u64,
    /// Event type.
    pub event: u8,
    /// Event object type.
    pub object_type: u8,
    /// Event result.
    pub result: u8,
    /// Data source for STORE event, reserved for other events.
    pub data_source: u8,
    /// GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid
    /// indicates for which signal the object belongs to. Reserved in other
    /// cases.
    pub object_sid: GnssSignal,
    /// GNSS signal identifier, If object_type is Almanac, Almanac WN, Iono OR
    /// L2C capabilities AND data_source is NDB_DS_RECEIVER sid indicates from
    /// which SV data was decoded. Reserved in other cases.
    pub src_sid: GnssSignal,
    /// A unique identifier of the sending hardware. For v1.0, set to the 2
    /// least significant bytes of the device serial number, valid only if
    /// data_source is NDB_DS_SBP. Reserved in case of other data_source.
    pub original_sender: u16,
}

impl MsgNdbEvent {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgNdbEvent, crate::Error> {
        Ok(MsgNdbEvent {
            sender_id: None,
            recv_time: _buf.read_u64::<LittleEndian>()?,
            event: _buf.read_u8()?,
            object_type: _buf.read_u8()?,
            result: _buf.read_u8()?,
            data_source: _buf.read_u8()?,
            object_sid: GnssSignal::parse(_buf)?,
            src_sid: GnssSignal::parse(_buf)?,
            original_sender: _buf.read_u16::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgNdbEvent {
    fn get_message_type(&self) -> u16 {
        1024
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

impl crate::serialize::SbpSerialize for MsgNdbEvent {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.recv_time.append_to_sbp_buffer(buf);
        self.event.append_to_sbp_buffer(buf);
        self.object_type.append_to_sbp_buffer(buf);
        self.result.append_to_sbp_buffer(buf);
        self.data_source.append_to_sbp_buffer(buf);
        self.object_sid.append_to_sbp_buffer(buf);
        self.src_sid.append_to_sbp_buffer(buf);
        self.original_sender.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.recv_time.sbp_size();
        size += self.event.sbp_size();
        size += self.object_type.sbp_size();
        size += self.result.sbp_size();
        size += self.data_source.sbp_size();
        size += self.object_sid.sbp_size();
        size += self.src_sid.sbp_size();
        size += self.original_sender.sbp_size();
        size
    }
}
