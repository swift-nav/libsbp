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
// Automatically generated from yaml/swiftnav/sbp/ndb.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages for logging NDB events.

use super::gnss::*;

use super::lib::*;

/// Navigation DataBase Event
///
/// This message is sent out when an object is stored into NDB. If needed
/// message could also be sent out when fetching an object from NDB.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgNdbEvent {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// HW time in milliseconds.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "recv_time")))]
    pub recv_time: u64,
    /// Event type.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "event")))]
    pub event: u8,
    /// Event object type.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "object_type")))]
    pub object_type: u8,
    /// Event result.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "result")))]
    pub result: u8,
    /// Data source for STORE event, reserved for other events.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "data_source")))]
    pub data_source: u8,
    /// GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid
    /// indicates for which signal the object belongs to. Reserved in other
    /// cases.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "object_sid")))]
    pub object_sid: GnssSignal,
    /// GNSS signal identifier, If object_type is Almanac, Almanac WN, Iono OR
    /// L2C capabilities AND data_source is NDB_DS_RECEIVER sid indicates from
    /// which SV data was decoded. Reserved in other cases.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "src_sid")))]
    pub src_sid: GnssSignal,
    /// A unique identifier of the sending hardware. For v1.0, set to the 2
    /// least significant bytes of the device serial number, valid only if
    /// data_source is NDB_DS_SBP. Reserved in case of other data_source.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "original_sender")))]
    pub original_sender: u16,
}

impl ConcreteMessage for MsgNdbEvent {
    const MESSAGE_TYPE: u16 = 1024;
    const MESSAGE_NAME: &'static str = "MSG_NDB_EVENT";
}

impl SbpMessage for MsgNdbEvent {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
}

impl TryFrom<Sbp> for MsgNdbEvent {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgNdbEvent(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgNdbEvent {
    const MIN_LEN: usize = <u64 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <GnssSignal as WireFormat>::MIN_LEN
        + <GnssSignal as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.recv_time)
            + WireFormat::len(&self.event)
            + WireFormat::len(&self.object_type)
            + WireFormat::len(&self.result)
            + WireFormat::len(&self.data_source)
            + WireFormat::len(&self.object_sid)
            + WireFormat::len(&self.src_sid)
            + WireFormat::len(&self.original_sender)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.recv_time, buf);
        WireFormat::write(&self.event, buf);
        WireFormat::write(&self.object_type, buf);
        WireFormat::write(&self.result, buf);
        WireFormat::write(&self.data_source, buf);
        WireFormat::write(&self.object_sid, buf);
        WireFormat::write(&self.src_sid, buf);
        WireFormat::write(&self.original_sender, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgNdbEvent {
            sender_id: None,
            recv_time: WireFormat::parse_unchecked(buf),
            event: WireFormat::parse_unchecked(buf),
            object_type: WireFormat::parse_unchecked(buf),
            result: WireFormat::parse_unchecked(buf),
            data_source: WireFormat::parse_unchecked(buf),
            object_sid: WireFormat::parse_unchecked(buf),
            src_sid: WireFormat::parse_unchecked(buf),
            original_sender: WireFormat::parse_unchecked(buf),
        }
    }
}
