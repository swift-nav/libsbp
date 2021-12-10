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

use super::lib::*;

/// Raw magnetometer data
///
/// Raw data from the magnetometer.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgMagRaw {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Milliseconds since start of GPS week. If the high bit is set, the time
    /// is unknown or invalid.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Milliseconds since start of GPS week, fractional part
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow_f")))]
    pub tow_f: u8,
    /// Magnetic field in the body frame X axis
    #[cfg_attr(feature = "serde", serde(rename(serialize = "mag_x")))]
    pub mag_x: i16,
    /// Magnetic field in the body frame Y axis
    #[cfg_attr(feature = "serde", serde(rename(serialize = "mag_y")))]
    pub mag_y: i16,
    /// Magnetic field in the body frame Z axis
    #[cfg_attr(feature = "serde", serde(rename(serialize = "mag_z")))]
    pub mag_z: i16,
}

impl ConcreteMessage for MsgMagRaw {
    const MESSAGE_TYPE: u16 = 2306;
    const MESSAGE_NAME: &'static str = "MSG_MAG_RAW";
}

impl SbpMessage for MsgMagRaw {
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

impl TryFrom<Sbp> for MsgMagRaw {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgMagRaw(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgMagRaw {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.tow_f)
            + WireFormat::len(&self.mag_x)
            + WireFormat::len(&self.mag_y)
            + WireFormat::len(&self.mag_z)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.tow_f, buf);
        WireFormat::write(&self.mag_x, buf);
        WireFormat::write(&self.mag_y, buf);
        WireFormat::write(&self.mag_z, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgMagRaw {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            tow_f: WireFormat::parse_unchecked(buf),
            mag_x: WireFormat::parse_unchecked(buf),
            mag_y: WireFormat::parse_unchecked(buf),
            mag_z: WireFormat::parse_unchecked(buf),
        }
    }
}
