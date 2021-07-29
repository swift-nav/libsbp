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

#[allow(unused_imports)]
use std::convert::TryFrom;

#[allow(unused_imports)]
use byteorder::{LittleEndian, ReadBytesExt};

#[allow(unused_imports)]
use crate::serialize::SbpSerialize;
#[allow(unused_imports)]
use crate::SbpString;

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
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgOdometry {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Time field representing either milliseconds in the GPS Week or local CPU
    /// time from the producing system in milliseconds.  See the tow_source flag
    /// for the exact source of this timestamp.
    pub tow: u32,
    /// The signed forward component of vehicle velocity.
    pub velocity: i32,
    /// Status flags
    pub flags: u8,
}

impl MsgOdometry {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgOdometry, crate::Error> {
        Ok( MsgOdometry{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            velocity: _buf.read_i32::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SBPMessage for MsgOdometry {
    fn get_message_name(&self) -> &'static str {
        "MSG_ODOMETRY"
    }

    fn get_message_type(&self) -> u16 {
        2307
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
impl super::ConcreteMessage for MsgOdometry {
    const MESSAGE_TYPE: u16 = 2307;
    const MESSAGE_NAME: &'static str = "MSG_ODOMETRY";
}
impl TryFrom<super::SBP> for MsgOdometry {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgOdometry(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgOdometry {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.velocity.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.velocity.sbp_size();
        size += self.flags.sbp_size();
        size
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
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgWheeltick {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Time field representing either microseconds since the last PPS,
    /// microseconds in the GPS Week or local CPU time from the producing system
    /// in microseconds. See the synch_type field for the exact meaning of this
    /// timestamp.
    pub time: u64,
    /// Field indicating the type of timestamp contained in the time field.
    pub flags: u8,
    /// ID of the sensor producing this message
    pub source: u8,
    /// Free-running counter of the accumulated distance for this sensor. The
    /// counter should be incrementing if travelling into one direction and
    /// decrementing when travelling in the opposite direction.
    pub ticks: i32,
}

impl MsgWheeltick {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgWheeltick, crate::Error> {
        Ok( MsgWheeltick{
            sender_id: None,
            time: _buf.read_u64::<LittleEndian>()?,
            flags: _buf.read_u8()?,
            source: _buf.read_u8()?,
            ticks: _buf.read_i32::<LittleEndian>()?,
        } )
    }
}
impl super::SBPMessage for MsgWheeltick {
    fn get_message_name(&self) -> &'static str {
        "MSG_WHEELTICK"
    }

    fn get_message_type(&self) -> u16 {
        2308
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
        // only consider wheelticks with synchronization type value "microsec in GPS week"
        if self.flags != 1 {
            return None;
        }
        let tow_s = (self.time as f64) / 1000000.0;
        let gps_time = match crate::time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(crate::time::MessageTime::Rover(gps_time.into())))
    }
}
impl super::ConcreteMessage for MsgWheeltick {
    const MESSAGE_TYPE: u16 = 2308;
    const MESSAGE_NAME: &'static str = "MSG_WHEELTICK";
}
impl TryFrom<super::SBP> for MsgWheeltick {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgWheeltick(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgWheeltick {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.time.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
        self.source.append_to_sbp_buffer(buf);
        self.ticks.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.time.sbp_size();
        size += self.flags.sbp_size();
        size += self.source.sbp_size();
        size += self.ticks.sbp_size();
        size
    }
}
