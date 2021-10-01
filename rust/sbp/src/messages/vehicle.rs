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
// Automatically generated from yaml/swiftnav/sbp/vehicle.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages from a vehicle.

use super::lib::*;

/// Vehicle forward (x-axis) velocity
///
/// Message representing the x component of vehicle velocity in the user frame
/// at the odometry reference point(s) specified by the user. The offset for
/// the odometry reference point and the definition and origin of the user
/// frame are defined through the device settings interface. There are 4
/// possible user-defined sources of this message which are labeled
/// arbitrarily source 0 through 3. If using "processor time" time tags, the
/// receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes
/// available to synchronise odometry measurements with GNSS. Processor time
/// shall roll over to zero after one week.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgOdometry {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Time field representing either milliseconds in the GPS Week or local CPU
    /// time from the producing system in milliseconds.  See the tow_source flag
    /// for the exact source of this timestamp.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// The signed forward component of vehicle velocity.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "velocity")))]
    pub velocity: i32,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgOdometry {
    const MESSAGE_TYPE: u16 = 2307;
    const MESSAGE_NAME: &'static str = "MSG_ODOMETRY";
}

impl SbpMessage for MsgOdometry {
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

impl TryFrom<Sbp> for MsgOdometry {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgOdometry(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgOdometry {
    const MIN_LEN: usize =
        <u32 as WireFormat>::MIN_LEN + <i32 as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow) + WireFormat::len(&self.velocity) + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.velocity, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgOdometry {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            velocity: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Accumulated wheeltick count message
///
/// Message containing the accumulated distance travelled by a wheel located
/// at an odometry reference point defined by the user. The offset for the
/// odometry reference point and the definition and origin of the user frame
/// are defined through the device settings interface. The source of this
/// message is identified by the source field, which is an integer ranging
/// from 0 to 255. The timestamp associated with this message should represent
/// the time when the accumulated tick count reached the value given by the
/// contents of this message as accurately as possible. If using "local CPU
/// time" time tags, the receiving end will expect a `MSG_GNSS_TIME_OFFSET`
/// when a PVT fix becomes available to synchronise wheeltick measurements
/// with GNSS. Local CPU time shall roll over to zero after one week.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgWheeltick {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Time field representing either microseconds since the last PPS,
    /// microseconds in the GPS Week or local CPU time from the producing system
    /// in microseconds. See the synch_type field for the exact meaning of this
    /// timestamp.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "time")))]
    pub time: u64,
    /// Field indicating the type of timestamp contained in the time field.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
    /// ID of the sensor producing this message
    #[cfg_attr(feature = "serde", serde(rename(serialize = "source")))]
    pub source: u8,
    /// Free-running counter of the accumulated distance for this sensor. The
    /// counter should be incrementing if travelling into one direction and
    /// decrementing when travelling in the opposite direction.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ticks")))]
    pub ticks: i32,
}

impl ConcreteMessage for MsgWheeltick {
    const MESSAGE_TYPE: u16 = 2308;
    const MESSAGE_NAME: &'static str = "MSG_WHEELTICK";
}

impl SbpMessage for MsgWheeltick {
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
        // only consider wheelticks with synchronization type value "microsec in GPS week"
        if self.flags != 1 {
            return None;
        }
        let tow_s = (self.time as f64) / 1000000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgWheeltick {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgWheeltick(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgWheeltick {
    const MIN_LEN: usize = <u64 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.time)
            + WireFormat::len(&self.flags)
            + WireFormat::len(&self.source)
            + WireFormat::len(&self.ticks)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.time, buf);
        WireFormat::write(&self.flags, buf);
        WireFormat::write(&self.source, buf);
        WireFormat::write(&self.ticks, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgWheeltick {
            sender_id: None,
            time: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
            source: WireFormat::parse_unchecked(buf),
            ticks: WireFormat::parse_unchecked(buf),
        }
    }
}
