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

use super::lib::*;

/// Reports timestamped external pin event
///
/// Reports detection of an external event, the GPS time it occurred, which
/// pin it was and whether it was rising or falling.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgExtEvent {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS week number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "wn")))]
    pub wn: u16,
    /// GPS time of week rounded to the nearest millisecond
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    /// 500000)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ns_residual")))]
    pub ns_residual: i32,
    /// Flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
    /// Pin number.  0..9 = DEBUG0..9.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pin")))]
    pub pin: u8,
}

impl ConcreteMessage for MsgExtEvent {
    const MESSAGE_TYPE: u16 = 257;
    const MESSAGE_NAME: &'static str = "MSG_EXT_EVENT";
}

impl SbpMessage for MsgExtEvent {
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
        #[allow(clippy::useless_conversion)]
        let wn: i16 = match self.wn.try_into() {
            Ok(wn) => wn,
            Err(e) => return Some(Err(e.into())),
        };
        let gps_time = match time::GpsTime::new(wn, tow_s) {
            Ok(gps_time) => gps_time,
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgExtEvent {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgExtEvent(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgExtEvent {
    const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.wn)
            + WireFormat::len(&self.tow)
            + WireFormat::len(&self.ns_residual)
            + WireFormat::len(&self.flags)
            + WireFormat::len(&self.pin)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.wn, buf);
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.ns_residual, buf);
        WireFormat::write(&self.flags, buf);
        WireFormat::write(&self.pin, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgExtEvent {
            sender_id: None,
            wn: WireFormat::parse_unchecked(buf),
            tow: WireFormat::parse_unchecked(buf),
            ns_residual: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
            pin: WireFormat::parse_unchecked(buf),
        }
    }
}
