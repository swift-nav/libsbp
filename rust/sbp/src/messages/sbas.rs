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

use super::gnss::*;

use super::lib::*;

/// Raw SBAS data
///
/// This message is sent once per second per SBAS satellite. ME checks the
/// parity of the data block and sends only blocks that pass the check.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSbasRaw {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GNSS signal identifier.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// GPS time-of-week at the start of the data block.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// SBAS message type (0-63)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "message_type")))]
    pub message_type: u8,
    /// Raw SBAS data field of 212 bits (last byte padded with zeros).
    #[cfg_attr(feature = "serde", serde(rename(serialize = "data")))]
    pub data: [u8; 27],
}

impl ConcreteMessage for MsgSbasRaw {
    const MESSAGE_TYPE: u16 = 30583;
    const MESSAGE_NAME: &'static str = "MSG_SBAS_RAW";
}

impl SbpMessage for MsgSbasRaw {
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
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgSbasRaw {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSbasRaw(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSbasRaw {
    const MIN_LEN: usize = <GnssSignal as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <[u8; 27] as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sid)
            + WireFormat::len(&self.tow)
            + WireFormat::len(&self.message_type)
            + WireFormat::len(&self.data)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.message_type, buf);
        WireFormat::write(&self.data, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSbasRaw {
            sender_id: None,
            sid: WireFormat::parse_unchecked(buf),
            tow: WireFormat::parse_unchecked(buf),
            message_type: WireFormat::parse_unchecked(buf),
            data: WireFormat::parse_unchecked(buf),
        }
    }
}
