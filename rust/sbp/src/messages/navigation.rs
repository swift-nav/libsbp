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
// Automatically generated from yaml/swiftnav/sbp/navigation.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Geodetic navigation messages reporting GPS time, position, velocity, and
//! baseline position solutions. For position solutions, these messages define
//! several different position solutions: single-point (SPP), RTK, and pseudo-
//! absolute position solutions.
//!
//! The SPP is the standalone, absolute GPS position solution using only a
//! single receiver. The RTK solution is the differential GPS solution, which
//! can use either a fixed/integer or floating carrier phase ambiguity. The
//! pseudo-absolute position solution uses a user-provided, well-surveyed base
//! station position (if available) and the RTK solution in tandem.
//!
//! When the inertial navigation mode indicates that the IMU is used, all
//! messages are reported in the vehicle body frame as defined by device
//! settings.  By default, the vehicle body frame is configured to be
//! coincident with the antenna phase center.  When there is no inertial
//! navigation, the solution will be reported at the phase center of the
//! antenna. There is no inertial navigation capability on Piksi Multi or
//! Duro.
//!
//! The tow field, when valid, is most often the Time of Measurement. When
//! this is the case, the 5th bit of flags is set to the default value of 0.
//! When this is not the case, the tow may be a time of arrival or a local
//! system timestamp, irrespective of the time reference (GPS Week or else),
//! but not a Time of Measurement.

#[allow(unused_imports)]
use std::convert::TryFrom;

#[allow(unused_imports)]
use byteorder::{LittleEndian, ReadBytesExt};

#[allow(unused_imports)]
use crate::{messages::ConcreteMessage, serialize::SbpSerialize, SbpString};

#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct EstimatedHorizontalErrorEllipse {
    /// The semi major axis of the estimated horizontal error ellipse at the
    /// user-configured confidence level; zero implies invalid.
    pub semi_major: f32,
    /// The semi minor axis of the estimated horizontal error ellipse at the
    /// user-configured confidence level; zero implies invalid.
    pub semi_minor: f32,
    /// The orientation of the semi major axis of the estimated horizontal error
    /// ellipse with respect to North.
    pub orientation: f32,
}

impl EstimatedHorizontalErrorEllipse {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<EstimatedHorizontalErrorEllipse, crate::Error> {
        Ok( EstimatedHorizontalErrorEllipse{
            semi_major: _buf.read_f32::<LittleEndian>()?,
            semi_minor: _buf.read_f32::<LittleEndian>()?,
            orientation: _buf.read_f32::<LittleEndian>()?,
        } )
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<EstimatedHorizontalErrorEllipse>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(EstimatedHorizontalErrorEllipse::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<EstimatedHorizontalErrorEllipse>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(EstimatedHorizontalErrorEllipse::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for EstimatedHorizontalErrorEllipse {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.semi_major.append_to_sbp_buffer(buf);
        self.semi_minor.append_to_sbp_buffer(buf);
        self.orientation.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.semi_major.sbp_size();
        size += self.semi_minor.sbp_size();
        size += self.orientation.sbp_size();
        size
    }
}

/// Age of corrections
///
/// This message reports the Age of the corrections used for the current
/// Differential solution.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgAgeCorrections {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Age of the corrections (0xFFFF indicates invalid)
    pub age: u16,
}

impl MsgAgeCorrections {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAgeCorrections, crate::Error> {
        Ok( MsgAgeCorrections{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            age: _buf.read_u16::<LittleEndian>()?,
        } )
    }
}
impl super::SbpMessage for MsgAgeCorrections {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgAgeCorrections {
    const MESSAGE_TYPE: u16 = 528;
    const MESSAGE_NAME: &'static str = "MSG_AGE_CORRECTIONS";
}
impl TryFrom<super::Sbp> for MsgAgeCorrections {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgAgeCorrections(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgAgeCorrections {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.age.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.age.sbp_size();
        size
    }
}

/// Baseline Position in ECEF
///
/// This message reports the baseline solution in Earth Centered Earth Fixed
/// (ECEF) coordinates. This baseline is the relative vector distance from the
/// base station to the rover receiver. The full GPS time is given by the
/// preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgBaselineEcef {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Baseline ECEF X coordinate
    pub x: i32,
    /// Baseline ECEF Y coordinate
    pub y: i32,
    /// Baseline ECEF Z coordinate
    pub z: i32,
    /// Position estimated standard deviation
    pub accuracy: u16,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgBaselineEcef {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBaselineEcef, crate::Error> {
        Ok( MsgBaselineEcef{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgBaselineEcef {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgBaselineEcef {
    const MESSAGE_TYPE: u16 = 523;
    const MESSAGE_NAME: &'static str = "MSG_BASELINE_ECEF";
}
impl TryFrom<super::Sbp> for MsgBaselineEcef {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgBaselineEcef(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgBaselineEcef {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.x.append_to_sbp_buffer(buf);
        self.y.append_to_sbp_buffer(buf);
        self.z.append_to_sbp_buffer(buf);
        self.accuracy.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.x.sbp_size();
        size += self.y.sbp_size();
        size += self.z.sbp_size();
        size += self.accuracy.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Baseline Position in ECEF
///
/// This message reports the baseline solution in Earth Centered Earth Fixed
/// (ECEF) coordinates. This baseline is the relative vector distance from the
/// base station to the rover receiver. The full GPS time is given by the
/// preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgBaselineEcefDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Baseline ECEF X coordinate
    pub x: i32,
    /// Baseline ECEF Y coordinate
    pub y: i32,
    /// Baseline ECEF Z coordinate
    pub z: i32,
    /// Position accuracy estimate
    pub accuracy: u16,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgBaselineEcefDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBaselineEcefDepA, crate::Error> {
        Ok( MsgBaselineEcefDepA{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgBaselineEcefDepA {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgBaselineEcefDepA {
    const MESSAGE_TYPE: u16 = 514;
    const MESSAGE_NAME: &'static str = "MSG_BASELINE_ECEF_DEP_A";
}
impl TryFrom<super::Sbp> for MsgBaselineEcefDepA {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgBaselineEcefDepA(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgBaselineEcefDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.x.append_to_sbp_buffer(buf);
        self.y.append_to_sbp_buffer(buf);
        self.z.append_to_sbp_buffer(buf);
        self.accuracy.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.x.sbp_size();
        size += self.y.sbp_size();
        size += self.z.sbp_size();
        size += self.accuracy.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Heading relative to True North
///
/// This message reports the baseline heading pointing from the base station
/// to the rover relative to True North. The full GPS time is given by the
/// preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgBaselineHeadingDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Heading
    pub heading: u32,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgBaselineHeadingDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBaselineHeadingDepA, crate::Error> {
        Ok( MsgBaselineHeadingDepA{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            heading: _buf.read_u32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgBaselineHeadingDepA {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgBaselineHeadingDepA {
    const MESSAGE_TYPE: u16 = 519;
    const MESSAGE_NAME: &'static str = "MSG_BASELINE_HEADING_DEP_A";
}
impl TryFrom<super::Sbp> for MsgBaselineHeadingDepA {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgBaselineHeadingDepA(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgBaselineHeadingDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.heading.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.heading.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Baseline in NED
///
/// This message reports the baseline solution in North East Down (NED)
/// coordinates. This baseline is the relative vector distance from the base
/// station to the rover receiver, and NED coordinate system is defined at the
/// local WGS84 tangent plane centered at the base station position.  The full
/// GPS time is given by the preceding MSG_GPS_TIME with the matching time-of-
/// week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgBaselineNed {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Baseline North coordinate
    pub n: i32,
    /// Baseline East coordinate
    pub e: i32,
    /// Baseline Down coordinate
    pub d: i32,
    /// Horizontal position estimated standard deviation
    pub h_accuracy: u16,
    /// Vertical position estimated standard deviation
    pub v_accuracy: u16,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgBaselineNed {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBaselineNed, crate::Error> {
        Ok( MsgBaselineNed{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            n: _buf.read_i32::<LittleEndian>()?,
            e: _buf.read_i32::<LittleEndian>()?,
            d: _buf.read_i32::<LittleEndian>()?,
            h_accuracy: _buf.read_u16::<LittleEndian>()?,
            v_accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgBaselineNed {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgBaselineNed {
    const MESSAGE_TYPE: u16 = 524;
    const MESSAGE_NAME: &'static str = "MSG_BASELINE_NED";
}
impl TryFrom<super::Sbp> for MsgBaselineNed {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgBaselineNed(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgBaselineNed {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.n.append_to_sbp_buffer(buf);
        self.e.append_to_sbp_buffer(buf);
        self.d.append_to_sbp_buffer(buf);
        self.h_accuracy.append_to_sbp_buffer(buf);
        self.v_accuracy.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.n.sbp_size();
        size += self.e.sbp_size();
        size += self.d.sbp_size();
        size += self.h_accuracy.sbp_size();
        size += self.v_accuracy.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Baseline in NED
///
/// This message reports the baseline solution in North East Down (NED)
/// coordinates. This baseline is the relative vector distance from the base
/// station to the rover receiver, and NED coordinate system is defined at the
/// local WGS84 tangent plane centered at the base station position.  The full
/// GPS time is given by the preceding MSG_GPS_TIME with the matching time-of-
/// week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgBaselineNedDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Baseline North coordinate
    pub n: i32,
    /// Baseline East coordinate
    pub e: i32,
    /// Baseline Down coordinate
    pub d: i32,
    /// Horizontal position accuracy estimate (not implemented). Defaults to 0.
    pub h_accuracy: u16,
    /// Vertical position accuracy estimate (not implemented). Defaults to 0.
    pub v_accuracy: u16,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgBaselineNedDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBaselineNedDepA, crate::Error> {
        Ok( MsgBaselineNedDepA{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            n: _buf.read_i32::<LittleEndian>()?,
            e: _buf.read_i32::<LittleEndian>()?,
            d: _buf.read_i32::<LittleEndian>()?,
            h_accuracy: _buf.read_u16::<LittleEndian>()?,
            v_accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgBaselineNedDepA {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgBaselineNedDepA {
    const MESSAGE_TYPE: u16 = 515;
    const MESSAGE_NAME: &'static str = "MSG_BASELINE_NED_DEP_A";
}
impl TryFrom<super::Sbp> for MsgBaselineNedDepA {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgBaselineNedDepA(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgBaselineNedDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.n.append_to_sbp_buffer(buf);
        self.e.append_to_sbp_buffer(buf);
        self.d.append_to_sbp_buffer(buf);
        self.h_accuracy.append_to_sbp_buffer(buf);
        self.v_accuracy.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.n.sbp_size();
        size += self.e.sbp_size();
        size += self.d.sbp_size();
        size += self.h_accuracy.sbp_size();
        size += self.v_accuracy.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Dilution of Precision
///
/// This dilution of precision (DOP) message describes the effect of
/// navigation satellite geometry on positional measurement precision.  The
/// flags field indicated whether the DOP reported corresponds to differential
/// or SPP solution.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgDops {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Geometric Dilution of Precision
    pub gdop: u16,
    /// Position Dilution of Precision
    pub pdop: u16,
    /// Time Dilution of Precision
    pub tdop: u16,
    /// Horizontal Dilution of Precision
    pub hdop: u16,
    /// Vertical Dilution of Precision
    pub vdop: u16,
    /// Indicates the position solution with which the DOPS message corresponds
    pub flags: u8,
}

impl MsgDops {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgDops, crate::Error> {
        Ok( MsgDops{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            gdop: _buf.read_u16::<LittleEndian>()?,
            pdop: _buf.read_u16::<LittleEndian>()?,
            tdop: _buf.read_u16::<LittleEndian>()?,
            hdop: _buf.read_u16::<LittleEndian>()?,
            vdop: _buf.read_u16::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgDops {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgDops {
    const MESSAGE_TYPE: u16 = 520;
    const MESSAGE_NAME: &'static str = "MSG_DOPS";
}
impl TryFrom<super::Sbp> for MsgDops {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgDops(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgDops {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.gdop.append_to_sbp_buffer(buf);
        self.pdop.append_to_sbp_buffer(buf);
        self.tdop.append_to_sbp_buffer(buf);
        self.hdop.append_to_sbp_buffer(buf);
        self.vdop.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.gdop.sbp_size();
        size += self.pdop.sbp_size();
        size += self.tdop.sbp_size();
        size += self.hdop.sbp_size();
        size += self.vdop.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Dilution of Precision
///
/// This dilution of precision (DOP) message describes the effect of
/// navigation satellite geometry on positional measurement precision.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgDopsDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Geometric Dilution of Precision
    pub gdop: u16,
    /// Position Dilution of Precision
    pub pdop: u16,
    /// Time Dilution of Precision
    pub tdop: u16,
    /// Horizontal Dilution of Precision
    pub hdop: u16,
    /// Vertical Dilution of Precision
    pub vdop: u16,
}

impl MsgDopsDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgDopsDepA, crate::Error> {
        Ok( MsgDopsDepA{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            gdop: _buf.read_u16::<LittleEndian>()?,
            pdop: _buf.read_u16::<LittleEndian>()?,
            tdop: _buf.read_u16::<LittleEndian>()?,
            hdop: _buf.read_u16::<LittleEndian>()?,
            vdop: _buf.read_u16::<LittleEndian>()?,
        } )
    }
}
impl super::SbpMessage for MsgDopsDepA {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgDopsDepA {
    const MESSAGE_TYPE: u16 = 518;
    const MESSAGE_NAME: &'static str = "MSG_DOPS_DEP_A";
}
impl TryFrom<super::Sbp> for MsgDopsDepA {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgDopsDepA(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgDopsDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.gdop.append_to_sbp_buffer(buf);
        self.pdop.append_to_sbp_buffer(buf);
        self.tdop.append_to_sbp_buffer(buf);
        self.hdop.append_to_sbp_buffer(buf);
        self.vdop.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.gdop.sbp_size();
        size += self.pdop.sbp_size();
        size += self.tdop.sbp_size();
        size += self.hdop.sbp_size();
        size += self.vdop.sbp_size();
        size
    }
}

/// GPS Time
///
/// This message reports the GPS time, representing the time since the GPS
/// epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks and
/// seconds of the week. The weeks begin at the Saturday/Sunday transition.
/// GPS week 0 began at the beginning of the GPS time scale.
///
/// Within each week number, the GPS time of the week is between between 0 and
/// 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate leap
/// seconds, and as of now, has a small offset from UTC. In a message stream,
/// this message precedes a set of other navigation messages referenced to the
/// same time (but lacking the ns field) and indicates a more precise time of
/// these messages.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgGpsTime {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS week number
    pub wn: u16,
    /// GPS time of week rounded to the nearest millisecond
    pub tow: u32,
    /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    /// 500000)
    pub ns_residual: i32,
    /// Status flags (reserved)
    pub flags: u8,
}

impl MsgGpsTime {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgGpsTime, crate::Error> {
        Ok( MsgGpsTime{
            sender_id: None,
            wn: _buf.read_u16::<LittleEndian>()?,
            tow: _buf.read_u32::<LittleEndian>()?,
            ns_residual: _buf.read_i32::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgGpsTime {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgGpsTime {
    const MESSAGE_TYPE: u16 = 258;
    const MESSAGE_NAME: &'static str = "MSG_GPS_TIME";
}
impl TryFrom<super::Sbp> for MsgGpsTime {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgGpsTime(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgGpsTime {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.wn.append_to_sbp_buffer(buf);
        self.tow.append_to_sbp_buffer(buf);
        self.ns_residual.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.wn.sbp_size();
        size += self.tow.sbp_size();
        size += self.ns_residual.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// GPS Time (v1.0)
///
/// This message reports the GPS time, representing the time since the GPS
/// epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks and
/// seconds of the week. The weeks begin at the Saturday/Sunday transition.
/// GPS week 0 began at the beginning of the GPS time scale.
///
/// Within each week number, the GPS time of the week is between between 0 and
/// 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate leap
/// seconds, and as of now, has a small offset from UTC. In a message stream,
/// this message precedes a set of other navigation messages referenced to the
/// same time (but lacking the ns field) and indicates a more precise time of
/// these messages.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgGpsTimeDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS week number
    pub wn: u16,
    /// GPS time of week rounded to the nearest millisecond
    pub tow: u32,
    /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    /// 500000)
    pub ns_residual: i32,
    /// Status flags (reserved)
    pub flags: u8,
}

impl MsgGpsTimeDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgGpsTimeDepA, crate::Error> {
        Ok( MsgGpsTimeDepA{
            sender_id: None,
            wn: _buf.read_u16::<LittleEndian>()?,
            tow: _buf.read_u32::<LittleEndian>()?,
            ns_residual: _buf.read_i32::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgGpsTimeDepA {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgGpsTimeDepA {
    const MESSAGE_TYPE: u16 = 256;
    const MESSAGE_NAME: &'static str = "MSG_GPS_TIME_DEP_A";
}
impl TryFrom<super::Sbp> for MsgGpsTimeDepA {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgGpsTimeDepA(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgGpsTimeDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.wn.append_to_sbp_buffer(buf);
        self.tow.append_to_sbp_buffer(buf);
        self.ns_residual.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.wn.sbp_size();
        size += self.tow.sbp_size();
        size += self.ns_residual.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// GPS Time
///
/// This message reports the GPS time, representing the time since the GPS
/// epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks and
/// seconds of the week. The weeks begin at the Saturday/Sunday transition.
/// GPS week 0 began at the beginning of the GPS time scale.
///
/// Within each week number, the GPS time of the week is between between 0 and
/// 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate leap
/// seconds, and as of now, has a small offset from UTC. In a message stream,
/// this message precedes a set of other navigation messages referenced to the
/// same time (but lacking the ns field) and indicates a more precise time of
/// these messages.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgGpsTimeGnss {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS week number
    pub wn: u16,
    /// GPS time of week rounded to the nearest millisecond
    pub tow: u32,
    /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    /// 500000)
    pub ns_residual: i32,
    /// Status flags (reserved)
    pub flags: u8,
}

impl MsgGpsTimeGnss {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgGpsTimeGnss, crate::Error> {
        Ok( MsgGpsTimeGnss{
            sender_id: None,
            wn: _buf.read_u16::<LittleEndian>()?,
            tow: _buf.read_u32::<LittleEndian>()?,
            ns_residual: _buf.read_i32::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgGpsTimeGnss {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgGpsTimeGnss {
    const MESSAGE_TYPE: u16 = 260;
    const MESSAGE_NAME: &'static str = "MSG_GPS_TIME_GNSS";
}
impl TryFrom<super::Sbp> for MsgGpsTimeGnss {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgGpsTimeGnss(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgGpsTimeGnss {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.wn.append_to_sbp_buffer(buf);
        self.tow.append_to_sbp_buffer(buf);
        self.ns_residual.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.wn.sbp_size();
        size += self.tow.sbp_size();
        size += self.ns_residual.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Single-point position in ECEF
///
/// The position solution message reports absolute Earth Centered Earth Fixed
/// (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
/// the position solution. If the rover receiver knows the surveyed position
/// of the base station and has an RTK solution, this reports a pseudo-
/// absolute position solution using the base station position and the rover's
/// RTK baseline vector. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosEcef {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// ECEF X coordinate
    pub x: f64,
    /// ECEF Y coordinate
    pub y: f64,
    /// ECEF Z coordinate
    pub z: f64,
    /// Position estimated standard deviation
    pub accuracy: u16,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgPosEcef {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosEcef, crate::Error> {
        Ok( MsgPosEcef{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_f64::<LittleEndian>()?,
            y: _buf.read_f64::<LittleEndian>()?,
            z: _buf.read_f64::<LittleEndian>()?,
            accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgPosEcef {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgPosEcef {
    const MESSAGE_TYPE: u16 = 521;
    const MESSAGE_NAME: &'static str = "MSG_POS_ECEF";
}
impl TryFrom<super::Sbp> for MsgPosEcef {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgPosEcef(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgPosEcef {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.x.append_to_sbp_buffer(buf);
        self.y.append_to_sbp_buffer(buf);
        self.z.append_to_sbp_buffer(buf);
        self.accuracy.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.x.sbp_size();
        size += self.y.sbp_size();
        size += self.z.sbp_size();
        size += self.accuracy.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Single-point position in ECEF
///
/// The position solution message reports absolute Earth Centered Earth Fixed
/// (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
/// the position solution. The message also reports the upper triangular
/// portion of the 3x3 covariance matrix. If the receiver knows the surveyed
/// position of the base station and has an RTK solution, this reports a
/// pseudo-absolute position solution using the base station position and the
/// rover's RTK baseline vector. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosEcefCov {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// ECEF X coordinate
    pub x: f64,
    /// ECEF Y coordinate
    pub y: f64,
    /// ECEF Z coordinate
    pub z: f64,
    /// Estimated variance of x
    pub cov_x_x: f32,
    /// Estimated covariance of x and y
    pub cov_x_y: f32,
    /// Estimated covariance of x and z
    pub cov_x_z: f32,
    /// Estimated variance of y
    pub cov_y_y: f32,
    /// Estimated covariance of y and z
    pub cov_y_z: f32,
    /// Estimated variance of z
    pub cov_z_z: f32,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgPosEcefCov {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosEcefCov, crate::Error> {
        Ok( MsgPosEcefCov{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_f64::<LittleEndian>()?,
            y: _buf.read_f64::<LittleEndian>()?,
            z: _buf.read_f64::<LittleEndian>()?,
            cov_x_x: _buf.read_f32::<LittleEndian>()?,
            cov_x_y: _buf.read_f32::<LittleEndian>()?,
            cov_x_z: _buf.read_f32::<LittleEndian>()?,
            cov_y_y: _buf.read_f32::<LittleEndian>()?,
            cov_y_z: _buf.read_f32::<LittleEndian>()?,
            cov_z_z: _buf.read_f32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgPosEcefCov {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgPosEcefCov {
    const MESSAGE_TYPE: u16 = 532;
    const MESSAGE_NAME: &'static str = "MSG_POS_ECEF_COV";
}
impl TryFrom<super::Sbp> for MsgPosEcefCov {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgPosEcefCov(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgPosEcefCov {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.x.append_to_sbp_buffer(buf);
        self.y.append_to_sbp_buffer(buf);
        self.z.append_to_sbp_buffer(buf);
        self.cov_x_x.append_to_sbp_buffer(buf);
        self.cov_x_y.append_to_sbp_buffer(buf);
        self.cov_x_z.append_to_sbp_buffer(buf);
        self.cov_y_y.append_to_sbp_buffer(buf);
        self.cov_y_z.append_to_sbp_buffer(buf);
        self.cov_z_z.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.x.sbp_size();
        size += self.y.sbp_size();
        size += self.z.sbp_size();
        size += self.cov_x_x.sbp_size();
        size += self.cov_x_y.sbp_size();
        size += self.cov_x_z.sbp_size();
        size += self.cov_y_y.sbp_size();
        size += self.cov_y_z.sbp_size();
        size += self.cov_z_z.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// GNSS-only Position in ECEF
///
/// The position solution message reports absolute Earth Centered Earth Fixed
/// (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
/// the position solution. The message also reports the upper triangular
/// portion of the 3x3 covariance matrix. If the receiver knows the surveyed
/// position of the base station and has an RTK solution, this reports a
/// pseudo-absolute position solution using the base station position and the
/// rover's RTK baseline vector. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosEcefCovGnss {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// ECEF X coordinate
    pub x: f64,
    /// ECEF Y coordinate
    pub y: f64,
    /// ECEF Z coordinate
    pub z: f64,
    /// Estimated variance of x
    pub cov_x_x: f32,
    /// Estimated covariance of x and y
    pub cov_x_y: f32,
    /// Estimated covariance of x and z
    pub cov_x_z: f32,
    /// Estimated variance of y
    pub cov_y_y: f32,
    /// Estimated covariance of y and z
    pub cov_y_z: f32,
    /// Estimated variance of z
    pub cov_z_z: f32,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgPosEcefCovGnss {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosEcefCovGnss, crate::Error> {
        Ok( MsgPosEcefCovGnss{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_f64::<LittleEndian>()?,
            y: _buf.read_f64::<LittleEndian>()?,
            z: _buf.read_f64::<LittleEndian>()?,
            cov_x_x: _buf.read_f32::<LittleEndian>()?,
            cov_x_y: _buf.read_f32::<LittleEndian>()?,
            cov_x_z: _buf.read_f32::<LittleEndian>()?,
            cov_y_y: _buf.read_f32::<LittleEndian>()?,
            cov_y_z: _buf.read_f32::<LittleEndian>()?,
            cov_z_z: _buf.read_f32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgPosEcefCovGnss {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgPosEcefCovGnss {
    const MESSAGE_TYPE: u16 = 564;
    const MESSAGE_NAME: &'static str = "MSG_POS_ECEF_COV_GNSS";
}
impl TryFrom<super::Sbp> for MsgPosEcefCovGnss {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgPosEcefCovGnss(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgPosEcefCovGnss {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.x.append_to_sbp_buffer(buf);
        self.y.append_to_sbp_buffer(buf);
        self.z.append_to_sbp_buffer(buf);
        self.cov_x_x.append_to_sbp_buffer(buf);
        self.cov_x_y.append_to_sbp_buffer(buf);
        self.cov_x_z.append_to_sbp_buffer(buf);
        self.cov_y_y.append_to_sbp_buffer(buf);
        self.cov_y_z.append_to_sbp_buffer(buf);
        self.cov_z_z.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.x.sbp_size();
        size += self.y.sbp_size();
        size += self.z.sbp_size();
        size += self.cov_x_x.sbp_size();
        size += self.cov_x_y.sbp_size();
        size += self.cov_x_z.sbp_size();
        size += self.cov_y_y.sbp_size();
        size += self.cov_y_z.sbp_size();
        size += self.cov_z_z.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Single-point position in ECEF
///
/// The position solution message reports absolute Earth Centered Earth Fixed
/// (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
/// the position solution. If the rover receiver knows the surveyed position
/// of the base station and has an RTK solution, this reports a pseudo-
/// absolute position solution using the base station position and the rover's
/// RTK baseline vector. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosEcefDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// ECEF X coordinate
    pub x: f64,
    /// ECEF Y coordinate
    pub y: f64,
    /// ECEF Z coordinate
    pub z: f64,
    /// Position accuracy estimate (not implemented). Defaults to 0.
    pub accuracy: u16,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgPosEcefDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosEcefDepA, crate::Error> {
        Ok( MsgPosEcefDepA{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_f64::<LittleEndian>()?,
            y: _buf.read_f64::<LittleEndian>()?,
            z: _buf.read_f64::<LittleEndian>()?,
            accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgPosEcefDepA {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgPosEcefDepA {
    const MESSAGE_TYPE: u16 = 512;
    const MESSAGE_NAME: &'static str = "MSG_POS_ECEF_DEP_A";
}
impl TryFrom<super::Sbp> for MsgPosEcefDepA {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgPosEcefDepA(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgPosEcefDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.x.append_to_sbp_buffer(buf);
        self.y.append_to_sbp_buffer(buf);
        self.z.append_to_sbp_buffer(buf);
        self.accuracy.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.x.sbp_size();
        size += self.y.sbp_size();
        size += self.z.sbp_size();
        size += self.accuracy.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// GNSS-only Position in ECEF
///
/// The position solution message reports absolute Earth Centered Earth Fixed
/// (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
/// the position solution. If the rover receiver knows the surveyed position
/// of the base station and has an RTK solution, this reports a pseudo-
/// absolute position solution using the base station position and the rover's
/// RTK baseline vector. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosEcefGnss {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// ECEF X coordinate
    pub x: f64,
    /// ECEF Y coordinate
    pub y: f64,
    /// ECEF Z coordinate
    pub z: f64,
    /// Position estimated standard deviation
    pub accuracy: u16,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgPosEcefGnss {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosEcefGnss, crate::Error> {
        Ok( MsgPosEcefGnss{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_f64::<LittleEndian>()?,
            y: _buf.read_f64::<LittleEndian>()?,
            z: _buf.read_f64::<LittleEndian>()?,
            accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgPosEcefGnss {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgPosEcefGnss {
    const MESSAGE_TYPE: u16 = 553;
    const MESSAGE_NAME: &'static str = "MSG_POS_ECEF_GNSS";
}
impl TryFrom<super::Sbp> for MsgPosEcefGnss {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgPosEcefGnss(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgPosEcefGnss {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.x.append_to_sbp_buffer(buf);
        self.y.append_to_sbp_buffer(buf);
        self.z.append_to_sbp_buffer(buf);
        self.accuracy.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.x.sbp_size();
        size += self.y.sbp_size();
        size += self.z.sbp_size();
        size += self.accuracy.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Geodetic Position
///
/// This position solution message reports the absolute geodetic coordinates
/// and the status (single point vs pseudo-absolute RTK) of the position
/// solution. If the rover receiver knows the surveyed position of the base
/// station and has an RTK solution, this reports a pseudo-absolute position
/// solution using the base station position and the rover's RTK baseline
/// vector. The full GPS time is given by the preceding MSG_GPS_TIME with the
/// matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosLlh {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Latitude
    pub lat: f64,
    /// Longitude
    pub lon: f64,
    /// Height above WGS84 ellipsoid
    pub height: f64,
    /// Horizontal position estimated standard deviation
    pub h_accuracy: u16,
    /// Vertical position estimated standard deviation
    pub v_accuracy: u16,
    /// Number of satellites used in solution.
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgPosLlh {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosLlh, crate::Error> {
        Ok( MsgPosLlh{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            lat: _buf.read_f64::<LittleEndian>()?,
            lon: _buf.read_f64::<LittleEndian>()?,
            height: _buf.read_f64::<LittleEndian>()?,
            h_accuracy: _buf.read_u16::<LittleEndian>()?,
            v_accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgPosLlh {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgPosLlh {
    const MESSAGE_TYPE: u16 = 522;
    const MESSAGE_NAME: &'static str = "MSG_POS_LLH";
}
impl TryFrom<super::Sbp> for MsgPosLlh {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgPosLlh(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgPosLlh {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.lat.append_to_sbp_buffer(buf);
        self.lon.append_to_sbp_buffer(buf);
        self.height.append_to_sbp_buffer(buf);
        self.h_accuracy.append_to_sbp_buffer(buf);
        self.v_accuracy.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.lat.sbp_size();
        size += self.lon.sbp_size();
        size += self.height.sbp_size();
        size += self.h_accuracy.sbp_size();
        size += self.v_accuracy.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Geodetic Position and Accuracy
///
/// This position solution message reports the absolute geodetic coordinates
/// and the status (single point vs pseudo-absolute RTK) of the position
/// solution as well as the estimated horizontal, vertical, cross-track and
/// along-track errors.  The position information and Fix Mode flags  follow
/// the MSG_POS_LLH message. Since the covariance matrix is computed in the
/// local-level North, East, Down frame, the estimated error terms follow that
/// convention.
///
/// The estimated errors are reported at a user-configurable confidence level.
/// The user-configured percentile is encoded in the percentile field.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosLlhAcc {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Latitude
    pub lat: f64,
    /// Longitude
    pub lon: f64,
    /// Height above WGS84 ellipsoid
    pub height: f64,
    /// Height above the geoid (i.e. height above mean sea level). See
    /// confidence_and_geoid for geoid model used.
    pub orthometric_height: f64,
    /// Estimated horizontal error at the user-configured confidence level; zero
    /// implies invalid.
    pub h_accuracy: f32,
    /// Estimated vertical error at the user-configured confidence level; zero
    /// implies invalid.
    pub v_accuracy: f32,
    /// Estimated cross-track error at the user-configured confidence level;
    /// zero implies invalid.
    pub ct_accuracy: f32,
    /// Estimated along-track error at the user-configured confidence level;
    /// zero implies invalid.
    pub at_accuracy: f32,
    /// The estimated horizontal error ellipse at the user-configured confidence
    /// level.
    pub h_ellipse: EstimatedHorizontalErrorEllipse,
    /// The lower bits describe the configured confidence level for the
    /// estimated position error. The middle bits describe the geoid model used
    /// to calculate the orthometric height.
    pub confidence_and_geoid: u8,
    /// Number of satellites used in solution.
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgPosLlhAcc {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosLlhAcc, crate::Error> {
        Ok( MsgPosLlhAcc{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            lat: _buf.read_f64::<LittleEndian>()?,
            lon: _buf.read_f64::<LittleEndian>()?,
            height: _buf.read_f64::<LittleEndian>()?,
            orthometric_height: _buf.read_f64::<LittleEndian>()?,
            h_accuracy: _buf.read_f32::<LittleEndian>()?,
            v_accuracy: _buf.read_f32::<LittleEndian>()?,
            ct_accuracy: _buf.read_f32::<LittleEndian>()?,
            at_accuracy: _buf.read_f32::<LittleEndian>()?,
            h_ellipse: EstimatedHorizontalErrorEllipse::parse(_buf)?,
            confidence_and_geoid: _buf.read_u8()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgPosLlhAcc {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgPosLlhAcc {
    const MESSAGE_TYPE: u16 = 536;
    const MESSAGE_NAME: &'static str = "MSG_POS_LLH_ACC";
}
impl TryFrom<super::Sbp> for MsgPosLlhAcc {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgPosLlhAcc(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgPosLlhAcc {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.lat.append_to_sbp_buffer(buf);
        self.lon.append_to_sbp_buffer(buf);
        self.height.append_to_sbp_buffer(buf);
        self.orthometric_height.append_to_sbp_buffer(buf);
        self.h_accuracy.append_to_sbp_buffer(buf);
        self.v_accuracy.append_to_sbp_buffer(buf);
        self.ct_accuracy.append_to_sbp_buffer(buf);
        self.at_accuracy.append_to_sbp_buffer(buf);
        self.h_ellipse.append_to_sbp_buffer(buf);
        self.confidence_and_geoid.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.lat.sbp_size();
        size += self.lon.sbp_size();
        size += self.height.sbp_size();
        size += self.orthometric_height.sbp_size();
        size += self.h_accuracy.sbp_size();
        size += self.v_accuracy.sbp_size();
        size += self.ct_accuracy.sbp_size();
        size += self.at_accuracy.sbp_size();
        size += self.h_ellipse.sbp_size();
        size += self.confidence_and_geoid.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Geodetic Position
///
/// This position solution message reports the absolute geodetic coordinates
/// and the status (single point vs pseudo-absolute RTK) of the position
/// solution as well as the upper triangle of the 3x3 covariance matrix.  The
/// position information and Fix Mode flags follow the MSG_POS_LLH message.
/// Since the covariance matrix is computed in the local-level North, East,
/// Down frame, the covariance terms follow that convention. Thus, covariances
/// are reported against the "downward" measurement and care should be taken
/// with the sign convention.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosLlhCov {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Latitude
    pub lat: f64,
    /// Longitude
    pub lon: f64,
    /// Height above WGS84 ellipsoid
    pub height: f64,
    /// Estimated variance of northing
    pub cov_n_n: f32,
    /// Covariance of northing and easting
    pub cov_n_e: f32,
    /// Covariance of northing and downward measurement
    pub cov_n_d: f32,
    /// Estimated variance of easting
    pub cov_e_e: f32,
    /// Covariance of easting and downward measurement
    pub cov_e_d: f32,
    /// Estimated variance of downward measurement
    pub cov_d_d: f32,
    /// Number of satellites used in solution.
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgPosLlhCov {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosLlhCov, crate::Error> {
        Ok( MsgPosLlhCov{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            lat: _buf.read_f64::<LittleEndian>()?,
            lon: _buf.read_f64::<LittleEndian>()?,
            height: _buf.read_f64::<LittleEndian>()?,
            cov_n_n: _buf.read_f32::<LittleEndian>()?,
            cov_n_e: _buf.read_f32::<LittleEndian>()?,
            cov_n_d: _buf.read_f32::<LittleEndian>()?,
            cov_e_e: _buf.read_f32::<LittleEndian>()?,
            cov_e_d: _buf.read_f32::<LittleEndian>()?,
            cov_d_d: _buf.read_f32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgPosLlhCov {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgPosLlhCov {
    const MESSAGE_TYPE: u16 = 529;
    const MESSAGE_NAME: &'static str = "MSG_POS_LLH_COV";
}
impl TryFrom<super::Sbp> for MsgPosLlhCov {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgPosLlhCov(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgPosLlhCov {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.lat.append_to_sbp_buffer(buf);
        self.lon.append_to_sbp_buffer(buf);
        self.height.append_to_sbp_buffer(buf);
        self.cov_n_n.append_to_sbp_buffer(buf);
        self.cov_n_e.append_to_sbp_buffer(buf);
        self.cov_n_d.append_to_sbp_buffer(buf);
        self.cov_e_e.append_to_sbp_buffer(buf);
        self.cov_e_d.append_to_sbp_buffer(buf);
        self.cov_d_d.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.lat.sbp_size();
        size += self.lon.sbp_size();
        size += self.height.sbp_size();
        size += self.cov_n_n.sbp_size();
        size += self.cov_n_e.sbp_size();
        size += self.cov_n_d.sbp_size();
        size += self.cov_e_e.sbp_size();
        size += self.cov_e_d.sbp_size();
        size += self.cov_d_d.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// GNSS-only Geodetic Position
///
/// This position solution message reports the absolute geodetic coordinates
/// and the status (single point vs pseudo-absolute RTK) of the position
/// solution as well as the upper triangle of the 3x3 covariance matrix.  The
/// position information and Fix Mode flags should follow the MSG_POS_LLH
/// message.  Since the covariance matrix is computed in the local-level
/// North, East, Down frame, the covariance terms follow with that convention.
/// Thus, covariances are reported against the "downward" measurement and care
/// should be taken with the sign convention.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosLlhCovGnss {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Latitude
    pub lat: f64,
    /// Longitude
    pub lon: f64,
    /// Height above WGS84 ellipsoid
    pub height: f64,
    /// Estimated variance of northing
    pub cov_n_n: f32,
    /// Covariance of northing and easting
    pub cov_n_e: f32,
    /// Covariance of northing and downward measurement
    pub cov_n_d: f32,
    /// Estimated variance of easting
    pub cov_e_e: f32,
    /// Covariance of easting and downward measurement
    pub cov_e_d: f32,
    /// Estimated variance of downward measurement
    pub cov_d_d: f32,
    /// Number of satellites used in solution.
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgPosLlhCovGnss {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosLlhCovGnss, crate::Error> {
        Ok( MsgPosLlhCovGnss{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            lat: _buf.read_f64::<LittleEndian>()?,
            lon: _buf.read_f64::<LittleEndian>()?,
            height: _buf.read_f64::<LittleEndian>()?,
            cov_n_n: _buf.read_f32::<LittleEndian>()?,
            cov_n_e: _buf.read_f32::<LittleEndian>()?,
            cov_n_d: _buf.read_f32::<LittleEndian>()?,
            cov_e_e: _buf.read_f32::<LittleEndian>()?,
            cov_e_d: _buf.read_f32::<LittleEndian>()?,
            cov_d_d: _buf.read_f32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgPosLlhCovGnss {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgPosLlhCovGnss {
    const MESSAGE_TYPE: u16 = 561;
    const MESSAGE_NAME: &'static str = "MSG_POS_LLH_COV_GNSS";
}
impl TryFrom<super::Sbp> for MsgPosLlhCovGnss {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgPosLlhCovGnss(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgPosLlhCovGnss {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.lat.append_to_sbp_buffer(buf);
        self.lon.append_to_sbp_buffer(buf);
        self.height.append_to_sbp_buffer(buf);
        self.cov_n_n.append_to_sbp_buffer(buf);
        self.cov_n_e.append_to_sbp_buffer(buf);
        self.cov_n_d.append_to_sbp_buffer(buf);
        self.cov_e_e.append_to_sbp_buffer(buf);
        self.cov_e_d.append_to_sbp_buffer(buf);
        self.cov_d_d.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.lat.sbp_size();
        size += self.lon.sbp_size();
        size += self.height.sbp_size();
        size += self.cov_n_n.sbp_size();
        size += self.cov_n_e.sbp_size();
        size += self.cov_n_d.sbp_size();
        size += self.cov_e_e.sbp_size();
        size += self.cov_e_d.sbp_size();
        size += self.cov_d_d.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Geodetic Position
///
/// This position solution message reports the absolute geodetic coordinates
/// and the status (single point vs pseudo-absolute RTK) of the position
/// solution. If the rover receiver knows the surveyed position of the base
/// station and has an RTK solution, this reports a pseudo-absolute position
/// solution using the base station position and the rover's RTK baseline
/// vector. The full GPS time is given by the preceding MSG_GPS_TIME with the
/// matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosLlhDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Latitude
    pub lat: f64,
    /// Longitude
    pub lon: f64,
    /// Height
    pub height: f64,
    /// Horizontal position accuracy estimate (not implemented). Defaults to 0.
    pub h_accuracy: u16,
    /// Vertical position accuracy estimate (not implemented). Defaults to 0.
    pub v_accuracy: u16,
    /// Number of satellites used in solution.
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgPosLlhDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosLlhDepA, crate::Error> {
        Ok( MsgPosLlhDepA{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            lat: _buf.read_f64::<LittleEndian>()?,
            lon: _buf.read_f64::<LittleEndian>()?,
            height: _buf.read_f64::<LittleEndian>()?,
            h_accuracy: _buf.read_u16::<LittleEndian>()?,
            v_accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgPosLlhDepA {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgPosLlhDepA {
    const MESSAGE_TYPE: u16 = 513;
    const MESSAGE_NAME: &'static str = "MSG_POS_LLH_DEP_A";
}
impl TryFrom<super::Sbp> for MsgPosLlhDepA {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgPosLlhDepA(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgPosLlhDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.lat.append_to_sbp_buffer(buf);
        self.lon.append_to_sbp_buffer(buf);
        self.height.append_to_sbp_buffer(buf);
        self.h_accuracy.append_to_sbp_buffer(buf);
        self.v_accuracy.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.lat.sbp_size();
        size += self.lon.sbp_size();
        size += self.height.sbp_size();
        size += self.h_accuracy.sbp_size();
        size += self.v_accuracy.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// GNSS-only Geodetic Position
///
/// This position solution message reports the absolute geodetic coordinates
/// and the status (single point vs pseudo-absolute RTK) of the position
/// solution. If the rover receiver knows the surveyed position of the base
/// station and has an RTK solution, this reports a pseudo-absolute position
/// solution using the base station position and the rover's RTK baseline
/// vector. The full GPS time is given by the preceding MSG_GPS_TIME with the
/// matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosLlhGnss {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Latitude
    pub lat: f64,
    /// Longitude
    pub lon: f64,
    /// Height above WGS84 ellipsoid
    pub height: f64,
    /// Horizontal position estimated standard deviation
    pub h_accuracy: u16,
    /// Vertical position estimated standard deviation
    pub v_accuracy: u16,
    /// Number of satellites used in solution.
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgPosLlhGnss {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPosLlhGnss, crate::Error> {
        Ok( MsgPosLlhGnss{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            lat: _buf.read_f64::<LittleEndian>()?,
            lon: _buf.read_f64::<LittleEndian>()?,
            height: _buf.read_f64::<LittleEndian>()?,
            h_accuracy: _buf.read_u16::<LittleEndian>()?,
            v_accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgPosLlhGnss {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgPosLlhGnss {
    const MESSAGE_TYPE: u16 = 554;
    const MESSAGE_NAME: &'static str = "MSG_POS_LLH_GNSS";
}
impl TryFrom<super::Sbp> for MsgPosLlhGnss {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgPosLlhGnss(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgPosLlhGnss {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.lat.append_to_sbp_buffer(buf);
        self.lon.append_to_sbp_buffer(buf);
        self.height.append_to_sbp_buffer(buf);
        self.h_accuracy.append_to_sbp_buffer(buf);
        self.v_accuracy.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.lat.sbp_size();
        size += self.lon.sbp_size();
        size += self.height.sbp_size();
        size += self.h_accuracy.sbp_size();
        size += self.v_accuracy.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Computed state and Protection Levels
///
/// This message reports the protection levels associated to the given state
/// estimate. The full GPS time is given by the preceding MSG_GPS_TIME with
/// the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgProtectionLevel {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// GPS week number
    pub wn: i16,
    /// Horizontal protection level
    pub hpl: u16,
    /// Vertical protection level
    pub vpl: u16,
    /// Along-track position error protection level
    pub atpl: u16,
    /// Cross-track position error protection level
    pub ctpl: u16,
    /// Protection level for the error vector between estimated and true
    /// along/cross track velocity vector
    pub hvpl: u16,
    /// Protection level for the velocity in vehicle upright direction
    /// (different from vertical direction if on a slope)
    pub vvpl: u16,
    /// Heading orientation protection level
    pub hopl: u16,
    /// Pitch orientation protection level
    pub popl: u16,
    /// Roll orientation protection level
    pub ropl: u16,
    /// Latitude
    pub lat: f64,
    /// Longitude
    pub lon: f64,
    /// Height
    pub height: f64,
    /// Velocity in vehicle x direction
    pub v_x: i32,
    /// Velocity in vehicle y direction
    pub v_y: i32,
    /// Velocity in vehicle z direction
    pub v_z: i32,
    /// Roll angle
    pub roll: i32,
    /// Pitch angle
    pub pitch: i32,
    /// Heading angle
    pub heading: i32,
    /// Status flags
    pub flags: u32,
}

impl MsgProtectionLevel {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgProtectionLevel, crate::Error> {
        Ok( MsgProtectionLevel{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            wn: _buf.read_i16::<LittleEndian>()?,
            hpl: _buf.read_u16::<LittleEndian>()?,
            vpl: _buf.read_u16::<LittleEndian>()?,
            atpl: _buf.read_u16::<LittleEndian>()?,
            ctpl: _buf.read_u16::<LittleEndian>()?,
            hvpl: _buf.read_u16::<LittleEndian>()?,
            vvpl: _buf.read_u16::<LittleEndian>()?,
            hopl: _buf.read_u16::<LittleEndian>()?,
            popl: _buf.read_u16::<LittleEndian>()?,
            ropl: _buf.read_u16::<LittleEndian>()?,
            lat: _buf.read_f64::<LittleEndian>()?,
            lon: _buf.read_f64::<LittleEndian>()?,
            height: _buf.read_f64::<LittleEndian>()?,
            v_x: _buf.read_i32::<LittleEndian>()?,
            v_y: _buf.read_i32::<LittleEndian>()?,
            v_z: _buf.read_i32::<LittleEndian>()?,
            roll: _buf.read_i32::<LittleEndian>()?,
            pitch: _buf.read_i32::<LittleEndian>()?,
            heading: _buf.read_i32::<LittleEndian>()?,
            flags: _buf.read_u32::<LittleEndian>()?,
        } )
    }
}
impl super::SbpMessage for MsgProtectionLevel {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgProtectionLevel {
    const MESSAGE_TYPE: u16 = 535;
    const MESSAGE_NAME: &'static str = "MSG_PROTECTION_LEVEL";
}
impl TryFrom<super::Sbp> for MsgProtectionLevel {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgProtectionLevel(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgProtectionLevel {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.wn.append_to_sbp_buffer(buf);
        self.hpl.append_to_sbp_buffer(buf);
        self.vpl.append_to_sbp_buffer(buf);
        self.atpl.append_to_sbp_buffer(buf);
        self.ctpl.append_to_sbp_buffer(buf);
        self.hvpl.append_to_sbp_buffer(buf);
        self.vvpl.append_to_sbp_buffer(buf);
        self.hopl.append_to_sbp_buffer(buf);
        self.popl.append_to_sbp_buffer(buf);
        self.ropl.append_to_sbp_buffer(buf);
        self.lat.append_to_sbp_buffer(buf);
        self.lon.append_to_sbp_buffer(buf);
        self.height.append_to_sbp_buffer(buf);
        self.v_x.append_to_sbp_buffer(buf);
        self.v_y.append_to_sbp_buffer(buf);
        self.v_z.append_to_sbp_buffer(buf);
        self.roll.append_to_sbp_buffer(buf);
        self.pitch.append_to_sbp_buffer(buf);
        self.heading.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.wn.sbp_size();
        size += self.hpl.sbp_size();
        size += self.vpl.sbp_size();
        size += self.atpl.sbp_size();
        size += self.ctpl.sbp_size();
        size += self.hvpl.sbp_size();
        size += self.vvpl.sbp_size();
        size += self.hopl.sbp_size();
        size += self.popl.sbp_size();
        size += self.ropl.sbp_size();
        size += self.lat.sbp_size();
        size += self.lon.sbp_size();
        size += self.height.sbp_size();
        size += self.v_x.sbp_size();
        size += self.v_y.sbp_size();
        size += self.v_z.sbp_size();
        size += self.roll.sbp_size();
        size += self.pitch.sbp_size();
        size += self.heading.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Computed Position and Protection Level
///
/// This message reports the local vertical and horizontal protection levels
/// associated with a given LLH position solution. The full GPS time is given
/// by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgProtectionLevelDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Vertical protection level
    pub vpl: u16,
    /// Horizontal protection level
    pub hpl: u16,
    /// Latitude
    pub lat: f64,
    /// Longitude
    pub lon: f64,
    /// Height
    pub height: f64,
    /// Status flags
    pub flags: u8,
}

impl MsgProtectionLevelDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgProtectionLevelDepA, crate::Error> {
        Ok( MsgProtectionLevelDepA{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            vpl: _buf.read_u16::<LittleEndian>()?,
            hpl: _buf.read_u16::<LittleEndian>()?,
            lat: _buf.read_f64::<LittleEndian>()?,
            lon: _buf.read_f64::<LittleEndian>()?,
            height: _buf.read_f64::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgProtectionLevelDepA {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgProtectionLevelDepA {
    const MESSAGE_TYPE: u16 = 534;
    const MESSAGE_NAME: &'static str = "MSG_PROTECTION_LEVEL_DEP_A";
}
impl TryFrom<super::Sbp> for MsgProtectionLevelDepA {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgProtectionLevelDepA(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgProtectionLevelDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.vpl.append_to_sbp_buffer(buf);
        self.hpl.append_to_sbp_buffer(buf);
        self.lat.append_to_sbp_buffer(buf);
        self.lon.append_to_sbp_buffer(buf);
        self.height.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.vpl.sbp_size();
        size += self.hpl.sbp_size();
        size += self.lat.sbp_size();
        size += self.lon.sbp_size();
        size += self.height.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// UTC Time
///
/// This message reports the Universal Coordinated Time (UTC).  Note the flags
/// which indicate the source of the UTC offset value and source of the time
/// fix.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgUtcTime {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Indicates source and time validity
    pub flags: u8,
    /// GPS time of week rounded to the nearest millisecond
    pub tow: u32,
    /// Year
    pub year: u16,
    /// Month (range 1 .. 12)
    pub month: u8,
    /// days in the month (range 1-31)
    pub day: u8,
    /// hours of day (range 0-23)
    pub hours: u8,
    /// minutes of hour (range 0-59)
    pub minutes: u8,
    /// seconds of minute (range 0-60) rounded down
    pub seconds: u8,
    /// nanoseconds of second (range 0-999999999)
    pub ns: u32,
}

impl MsgUtcTime {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgUtcTime, crate::Error> {
        Ok( MsgUtcTime{
            sender_id: None,
            flags: _buf.read_u8()?,
            tow: _buf.read_u32::<LittleEndian>()?,
            year: _buf.read_u16::<LittleEndian>()?,
            month: _buf.read_u8()?,
            day: _buf.read_u8()?,
            hours: _buf.read_u8()?,
            minutes: _buf.read_u8()?,
            seconds: _buf.read_u8()?,
            ns: _buf.read_u32::<LittleEndian>()?,
        } )
    }
}
impl super::SbpMessage for MsgUtcTime {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgUtcTime {
    const MESSAGE_TYPE: u16 = 259;
    const MESSAGE_NAME: &'static str = "MSG_UTC_TIME";
}
impl TryFrom<super::Sbp> for MsgUtcTime {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgUtcTime(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgUtcTime {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.flags.append_to_sbp_buffer(buf);
        self.tow.append_to_sbp_buffer(buf);
        self.year.append_to_sbp_buffer(buf);
        self.month.append_to_sbp_buffer(buf);
        self.day.append_to_sbp_buffer(buf);
        self.hours.append_to_sbp_buffer(buf);
        self.minutes.append_to_sbp_buffer(buf);
        self.seconds.append_to_sbp_buffer(buf);
        self.ns.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.flags.sbp_size();
        size += self.tow.sbp_size();
        size += self.year.sbp_size();
        size += self.month.sbp_size();
        size += self.day.sbp_size();
        size += self.hours.sbp_size();
        size += self.minutes.sbp_size();
        size += self.seconds.sbp_size();
        size += self.ns.sbp_size();
        size
    }
}

/// UTC Time
///
/// This message reports the Universal Coordinated Time (UTC).  Note the flags
/// which indicate the source of the UTC offset value and source of the time
/// fix.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgUtcTimeGnss {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Indicates source and time validity
    pub flags: u8,
    /// GPS time of week rounded to the nearest millisecond
    pub tow: u32,
    /// Year
    pub year: u16,
    /// Month (range 1 .. 12)
    pub month: u8,
    /// days in the month (range 1-31)
    pub day: u8,
    /// hours of day (range 0-23)
    pub hours: u8,
    /// minutes of hour (range 0-59)
    pub minutes: u8,
    /// seconds of minute (range 0-60) rounded down
    pub seconds: u8,
    /// nanoseconds of second (range 0-999999999)
    pub ns: u32,
}

impl MsgUtcTimeGnss {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgUtcTimeGnss, crate::Error> {
        Ok( MsgUtcTimeGnss{
            sender_id: None,
            flags: _buf.read_u8()?,
            tow: _buf.read_u32::<LittleEndian>()?,
            year: _buf.read_u16::<LittleEndian>()?,
            month: _buf.read_u8()?,
            day: _buf.read_u8()?,
            hours: _buf.read_u8()?,
            minutes: _buf.read_u8()?,
            seconds: _buf.read_u8()?,
            ns: _buf.read_u32::<LittleEndian>()?,
        } )
    }
}
impl super::SbpMessage for MsgUtcTimeGnss {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgUtcTimeGnss {
    const MESSAGE_TYPE: u16 = 261;
    const MESSAGE_NAME: &'static str = "MSG_UTC_TIME_GNSS";
}
impl TryFrom<super::Sbp> for MsgUtcTimeGnss {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgUtcTimeGnss(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgUtcTimeGnss {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.flags.append_to_sbp_buffer(buf);
        self.tow.append_to_sbp_buffer(buf);
        self.year.append_to_sbp_buffer(buf);
        self.month.append_to_sbp_buffer(buf);
        self.day.append_to_sbp_buffer(buf);
        self.hours.append_to_sbp_buffer(buf);
        self.minutes.append_to_sbp_buffer(buf);
        self.seconds.append_to_sbp_buffer(buf);
        self.ns.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.flags.sbp_size();
        size += self.tow.sbp_size();
        size += self.year.sbp_size();
        size += self.month.sbp_size();
        size += self.day.sbp_size();
        size += self.hours.sbp_size();
        size += self.minutes.sbp_size();
        size += self.seconds.sbp_size();
        size += self.ns.sbp_size();
        size
    }
}

/// Velocity in User Frame
///
/// This message reports the velocity in the Vehicle Body Frame. By
/// convention, the x-axis should point out the nose of the vehicle and
/// represent the forward direction, while as the y-axis should point out the
/// right hand side of the vehicle. Since this is a right handed system, z
/// should point out the bottom of the vehicle. The orientation and origin of
/// the Vehicle Body Frame are specified via the device settings. The full GPS
/// time is given by the preceding MSG_GPS_TIME with the matching time-of-week
/// (tow). This message is only produced by inertial versions of Swift
/// products and is not available from Piksi Multi or Duro.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelBody {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Velocity in x direction
    pub x: i32,
    /// Velocity in y direction
    pub y: i32,
    /// Velocity in z direction
    pub z: i32,
    /// Estimated variance of x
    pub cov_x_x: f32,
    /// Covariance of x and y
    pub cov_x_y: f32,
    /// Covariance of x and z
    pub cov_x_z: f32,
    /// Estimated variance of y
    pub cov_y_y: f32,
    /// Covariance of y and z
    pub cov_y_z: f32,
    /// Estimated variance of z
    pub cov_z_z: f32,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgVelBody {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelBody, crate::Error> {
        Ok( MsgVelBody{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            cov_x_x: _buf.read_f32::<LittleEndian>()?,
            cov_x_y: _buf.read_f32::<LittleEndian>()?,
            cov_x_z: _buf.read_f32::<LittleEndian>()?,
            cov_y_y: _buf.read_f32::<LittleEndian>()?,
            cov_y_z: _buf.read_f32::<LittleEndian>()?,
            cov_z_z: _buf.read_f32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgVelBody {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgVelBody {
    const MESSAGE_TYPE: u16 = 531;
    const MESSAGE_NAME: &'static str = "MSG_VEL_BODY";
}
impl TryFrom<super::Sbp> for MsgVelBody {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgVelBody(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgVelBody {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.x.append_to_sbp_buffer(buf);
        self.y.append_to_sbp_buffer(buf);
        self.z.append_to_sbp_buffer(buf);
        self.cov_x_x.append_to_sbp_buffer(buf);
        self.cov_x_y.append_to_sbp_buffer(buf);
        self.cov_x_z.append_to_sbp_buffer(buf);
        self.cov_y_y.append_to_sbp_buffer(buf);
        self.cov_y_z.append_to_sbp_buffer(buf);
        self.cov_z_z.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.x.sbp_size();
        size += self.y.sbp_size();
        size += self.z.sbp_size();
        size += self.cov_x_x.sbp_size();
        size += self.cov_x_y.sbp_size();
        size += self.cov_x_z.sbp_size();
        size += self.cov_y_y.sbp_size();
        size += self.cov_y_z.sbp_size();
        size += self.cov_z_z.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Velocity in ECEF
///
/// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
/// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
/// the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelEcef {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Velocity ECEF X coordinate
    pub x: i32,
    /// Velocity ECEF Y coordinate
    pub y: i32,
    /// Velocity ECEF Z coordinate
    pub z: i32,
    /// Velocity estimated standard deviation
    pub accuracy: u16,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgVelEcef {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelEcef, crate::Error> {
        Ok( MsgVelEcef{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgVelEcef {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgVelEcef {
    const MESSAGE_TYPE: u16 = 525;
    const MESSAGE_NAME: &'static str = "MSG_VEL_ECEF";
}
impl TryFrom<super::Sbp> for MsgVelEcef {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgVelEcef(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgVelEcef {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.x.append_to_sbp_buffer(buf);
        self.y.append_to_sbp_buffer(buf);
        self.z.append_to_sbp_buffer(buf);
        self.accuracy.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.x.sbp_size();
        size += self.y.sbp_size();
        size += self.z.sbp_size();
        size += self.accuracy.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Velocity in ECEF
///
/// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
/// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
/// the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelEcefCov {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Velocity ECEF X coordinate
    pub x: i32,
    /// Velocity ECEF Y coordinate
    pub y: i32,
    /// Velocity ECEF Z coordinate
    pub z: i32,
    /// Estimated variance of x
    pub cov_x_x: f32,
    /// Estimated covariance of x and y
    pub cov_x_y: f32,
    /// Estimated covariance of x and z
    pub cov_x_z: f32,
    /// Estimated variance of y
    pub cov_y_y: f32,
    /// Estimated covariance of y and z
    pub cov_y_z: f32,
    /// Estimated variance of z
    pub cov_z_z: f32,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgVelEcefCov {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelEcefCov, crate::Error> {
        Ok( MsgVelEcefCov{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            cov_x_x: _buf.read_f32::<LittleEndian>()?,
            cov_x_y: _buf.read_f32::<LittleEndian>()?,
            cov_x_z: _buf.read_f32::<LittleEndian>()?,
            cov_y_y: _buf.read_f32::<LittleEndian>()?,
            cov_y_z: _buf.read_f32::<LittleEndian>()?,
            cov_z_z: _buf.read_f32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgVelEcefCov {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgVelEcefCov {
    const MESSAGE_TYPE: u16 = 533;
    const MESSAGE_NAME: &'static str = "MSG_VEL_ECEF_COV";
}
impl TryFrom<super::Sbp> for MsgVelEcefCov {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgVelEcefCov(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgVelEcefCov {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.x.append_to_sbp_buffer(buf);
        self.y.append_to_sbp_buffer(buf);
        self.z.append_to_sbp_buffer(buf);
        self.cov_x_x.append_to_sbp_buffer(buf);
        self.cov_x_y.append_to_sbp_buffer(buf);
        self.cov_x_z.append_to_sbp_buffer(buf);
        self.cov_y_y.append_to_sbp_buffer(buf);
        self.cov_y_z.append_to_sbp_buffer(buf);
        self.cov_z_z.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.x.sbp_size();
        size += self.y.sbp_size();
        size += self.z.sbp_size();
        size += self.cov_x_x.sbp_size();
        size += self.cov_x_y.sbp_size();
        size += self.cov_x_z.sbp_size();
        size += self.cov_y_y.sbp_size();
        size += self.cov_y_z.sbp_size();
        size += self.cov_z_z.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// GNSS-only Velocity in ECEF
///
/// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
/// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
/// the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelEcefCovGnss {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Velocity ECEF X coordinate
    pub x: i32,
    /// Velocity ECEF Y coordinate
    pub y: i32,
    /// Velocity ECEF Z coordinate
    pub z: i32,
    /// Estimated variance of x
    pub cov_x_x: f32,
    /// Estimated covariance of x and y
    pub cov_x_y: f32,
    /// Estimated covariance of x and z
    pub cov_x_z: f32,
    /// Estimated variance of y
    pub cov_y_y: f32,
    /// Estimated covariance of y and z
    pub cov_y_z: f32,
    /// Estimated variance of z
    pub cov_z_z: f32,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgVelEcefCovGnss {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelEcefCovGnss, crate::Error> {
        Ok( MsgVelEcefCovGnss{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            cov_x_x: _buf.read_f32::<LittleEndian>()?,
            cov_x_y: _buf.read_f32::<LittleEndian>()?,
            cov_x_z: _buf.read_f32::<LittleEndian>()?,
            cov_y_y: _buf.read_f32::<LittleEndian>()?,
            cov_y_z: _buf.read_f32::<LittleEndian>()?,
            cov_z_z: _buf.read_f32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgVelEcefCovGnss {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgVelEcefCovGnss {
    const MESSAGE_TYPE: u16 = 565;
    const MESSAGE_NAME: &'static str = "MSG_VEL_ECEF_COV_GNSS";
}
impl TryFrom<super::Sbp> for MsgVelEcefCovGnss {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgVelEcefCovGnss(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgVelEcefCovGnss {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.x.append_to_sbp_buffer(buf);
        self.y.append_to_sbp_buffer(buf);
        self.z.append_to_sbp_buffer(buf);
        self.cov_x_x.append_to_sbp_buffer(buf);
        self.cov_x_y.append_to_sbp_buffer(buf);
        self.cov_x_z.append_to_sbp_buffer(buf);
        self.cov_y_y.append_to_sbp_buffer(buf);
        self.cov_y_z.append_to_sbp_buffer(buf);
        self.cov_z_z.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.x.sbp_size();
        size += self.y.sbp_size();
        size += self.z.sbp_size();
        size += self.cov_x_x.sbp_size();
        size += self.cov_x_y.sbp_size();
        size += self.cov_x_z.sbp_size();
        size += self.cov_y_y.sbp_size();
        size += self.cov_y_z.sbp_size();
        size += self.cov_z_z.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Velocity in ECEF
///
/// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
/// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
/// the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelEcefDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Velocity ECEF X coordinate
    pub x: i32,
    /// Velocity ECEF Y coordinate
    pub y: i32,
    /// Velocity ECEF Z coordinate
    pub z: i32,
    /// Velocity accuracy estimate (not implemented). Defaults to 0.
    pub accuracy: u16,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags (reserved)
    pub flags: u8,
}

impl MsgVelEcefDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelEcefDepA, crate::Error> {
        Ok( MsgVelEcefDepA{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgVelEcefDepA {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgVelEcefDepA {
    const MESSAGE_TYPE: u16 = 516;
    const MESSAGE_NAME: &'static str = "MSG_VEL_ECEF_DEP_A";
}
impl TryFrom<super::Sbp> for MsgVelEcefDepA {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgVelEcefDepA(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgVelEcefDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.x.append_to_sbp_buffer(buf);
        self.y.append_to_sbp_buffer(buf);
        self.z.append_to_sbp_buffer(buf);
        self.accuracy.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.x.sbp_size();
        size += self.y.sbp_size();
        size += self.z.sbp_size();
        size += self.accuracy.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// GNSS-only Velocity in ECEF
///
/// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
/// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
/// the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelEcefGnss {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Velocity ECEF X coordinate
    pub x: i32,
    /// Velocity ECEF Y coordinate
    pub y: i32,
    /// Velocity ECEF Z coordinate
    pub z: i32,
    /// Velocity estimated standard deviation
    pub accuracy: u16,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgVelEcefGnss {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelEcefGnss, crate::Error> {
        Ok( MsgVelEcefGnss{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgVelEcefGnss {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgVelEcefGnss {
    const MESSAGE_TYPE: u16 = 557;
    const MESSAGE_NAME: &'static str = "MSG_VEL_ECEF_GNSS";
}
impl TryFrom<super::Sbp> for MsgVelEcefGnss {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgVelEcefGnss(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgVelEcefGnss {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.x.append_to_sbp_buffer(buf);
        self.y.append_to_sbp_buffer(buf);
        self.z.append_to_sbp_buffer(buf);
        self.accuracy.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.x.sbp_size();
        size += self.y.sbp_size();
        size += self.z.sbp_size();
        size += self.accuracy.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Velocity in NED
///
/// This message reports the velocity in local North East Down (NED)
/// coordinates. The NED coordinate system is defined as the local WGS84
/// tangent plane centered at the current position. The full GPS time is given
/// by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelNed {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Velocity North coordinate
    pub n: i32,
    /// Velocity East coordinate
    pub e: i32,
    /// Velocity Down coordinate
    pub d: i32,
    /// Horizontal velocity estimated standard deviation
    pub h_accuracy: u16,
    /// Vertical velocity estimated standard deviation
    pub v_accuracy: u16,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgVelNed {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelNed, crate::Error> {
        Ok( MsgVelNed{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            n: _buf.read_i32::<LittleEndian>()?,
            e: _buf.read_i32::<LittleEndian>()?,
            d: _buf.read_i32::<LittleEndian>()?,
            h_accuracy: _buf.read_u16::<LittleEndian>()?,
            v_accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgVelNed {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgVelNed {
    const MESSAGE_TYPE: u16 = 526;
    const MESSAGE_NAME: &'static str = "MSG_VEL_NED";
}
impl TryFrom<super::Sbp> for MsgVelNed {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgVelNed(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgVelNed {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.n.append_to_sbp_buffer(buf);
        self.e.append_to_sbp_buffer(buf);
        self.d.append_to_sbp_buffer(buf);
        self.h_accuracy.append_to_sbp_buffer(buf);
        self.v_accuracy.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.n.sbp_size();
        size += self.e.sbp_size();
        size += self.d.sbp_size();
        size += self.h_accuracy.sbp_size();
        size += self.v_accuracy.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Velocity in NED
///
/// This message reports the velocity in local North East Down (NED)
/// coordinates. The NED coordinate system is defined as the local WGS84
/// tangent plane centered at the current position. The full GPS time is given
/// by the preceding MSG_GPS_TIME with the matching time-of-week (tow). This
/// message is similar to the MSG_VEL_NED, but it includes the upper
/// triangular portion of the 3x3 covariance matrix.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelNedCov {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Velocity North coordinate
    pub n: i32,
    /// Velocity East coordinate
    pub e: i32,
    /// Velocity Down coordinate
    pub d: i32,
    /// Estimated variance of northward measurement
    pub cov_n_n: f32,
    /// Covariance of northward and eastward measurement
    pub cov_n_e: f32,
    /// Covariance of northward and downward measurement
    pub cov_n_d: f32,
    /// Estimated variance of eastward measurement
    pub cov_e_e: f32,
    /// Covariance of eastward and downward measurement
    pub cov_e_d: f32,
    /// Estimated variance of downward measurement
    pub cov_d_d: f32,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgVelNedCov {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelNedCov, crate::Error> {
        Ok( MsgVelNedCov{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            n: _buf.read_i32::<LittleEndian>()?,
            e: _buf.read_i32::<LittleEndian>()?,
            d: _buf.read_i32::<LittleEndian>()?,
            cov_n_n: _buf.read_f32::<LittleEndian>()?,
            cov_n_e: _buf.read_f32::<LittleEndian>()?,
            cov_n_d: _buf.read_f32::<LittleEndian>()?,
            cov_e_e: _buf.read_f32::<LittleEndian>()?,
            cov_e_d: _buf.read_f32::<LittleEndian>()?,
            cov_d_d: _buf.read_f32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgVelNedCov {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgVelNedCov {
    const MESSAGE_TYPE: u16 = 530;
    const MESSAGE_NAME: &'static str = "MSG_VEL_NED_COV";
}
impl TryFrom<super::Sbp> for MsgVelNedCov {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgVelNedCov(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgVelNedCov {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.n.append_to_sbp_buffer(buf);
        self.e.append_to_sbp_buffer(buf);
        self.d.append_to_sbp_buffer(buf);
        self.cov_n_n.append_to_sbp_buffer(buf);
        self.cov_n_e.append_to_sbp_buffer(buf);
        self.cov_n_d.append_to_sbp_buffer(buf);
        self.cov_e_e.append_to_sbp_buffer(buf);
        self.cov_e_d.append_to_sbp_buffer(buf);
        self.cov_d_d.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.n.sbp_size();
        size += self.e.sbp_size();
        size += self.d.sbp_size();
        size += self.cov_n_n.sbp_size();
        size += self.cov_n_e.sbp_size();
        size += self.cov_n_d.sbp_size();
        size += self.cov_e_e.sbp_size();
        size += self.cov_e_d.sbp_size();
        size += self.cov_d_d.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// GNSS-only Velocity in NED
///
/// This message reports the velocity in local North East Down (NED)
/// coordinates. The NED coordinate system is defined as the local WGS84
/// tangent plane centered at the current position. The full GPS time is given
/// by the preceding MSG_GPS_TIME with the matching time-of-week (tow). This
/// message is similar to the MSG_VEL_NED, but it includes the upper
/// triangular portion of the 3x3 covariance matrix.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelNedCovGnss {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Velocity North coordinate
    pub n: i32,
    /// Velocity East coordinate
    pub e: i32,
    /// Velocity Down coordinate
    pub d: i32,
    /// Estimated variance of northward measurement
    pub cov_n_n: f32,
    /// Covariance of northward and eastward measurement
    pub cov_n_e: f32,
    /// Covariance of northward and downward measurement
    pub cov_n_d: f32,
    /// Estimated variance of eastward measurement
    pub cov_e_e: f32,
    /// Covariance of eastward and downward measurement
    pub cov_e_d: f32,
    /// Estimated variance of downward measurement
    pub cov_d_d: f32,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgVelNedCovGnss {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelNedCovGnss, crate::Error> {
        Ok( MsgVelNedCovGnss{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            n: _buf.read_i32::<LittleEndian>()?,
            e: _buf.read_i32::<LittleEndian>()?,
            d: _buf.read_i32::<LittleEndian>()?,
            cov_n_n: _buf.read_f32::<LittleEndian>()?,
            cov_n_e: _buf.read_f32::<LittleEndian>()?,
            cov_n_d: _buf.read_f32::<LittleEndian>()?,
            cov_e_e: _buf.read_f32::<LittleEndian>()?,
            cov_e_d: _buf.read_f32::<LittleEndian>()?,
            cov_d_d: _buf.read_f32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgVelNedCovGnss {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgVelNedCovGnss {
    const MESSAGE_TYPE: u16 = 562;
    const MESSAGE_NAME: &'static str = "MSG_VEL_NED_COV_GNSS";
}
impl TryFrom<super::Sbp> for MsgVelNedCovGnss {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgVelNedCovGnss(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgVelNedCovGnss {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.n.append_to_sbp_buffer(buf);
        self.e.append_to_sbp_buffer(buf);
        self.d.append_to_sbp_buffer(buf);
        self.cov_n_n.append_to_sbp_buffer(buf);
        self.cov_n_e.append_to_sbp_buffer(buf);
        self.cov_n_d.append_to_sbp_buffer(buf);
        self.cov_e_e.append_to_sbp_buffer(buf);
        self.cov_e_d.append_to_sbp_buffer(buf);
        self.cov_d_d.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.n.sbp_size();
        size += self.e.sbp_size();
        size += self.d.sbp_size();
        size += self.cov_n_n.sbp_size();
        size += self.cov_n_e.sbp_size();
        size += self.cov_n_d.sbp_size();
        size += self.cov_e_e.sbp_size();
        size += self.cov_e_d.sbp_size();
        size += self.cov_d_d.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Velocity in NED
///
/// This message reports the velocity in local North East Down (NED)
/// coordinates. The NED coordinate system is defined as the local WGS84
/// tangent plane centered at the current position. The full GPS time is given
/// by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelNedDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Velocity North coordinate
    pub n: i32,
    /// Velocity East coordinate
    pub e: i32,
    /// Velocity Down coordinate
    pub d: i32,
    /// Horizontal velocity accuracy estimate (not implemented). Defaults to 0.
    pub h_accuracy: u16,
    /// Vertical velocity accuracy estimate (not implemented). Defaults to 0.
    pub v_accuracy: u16,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags (reserved)
    pub flags: u8,
}

impl MsgVelNedDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelNedDepA, crate::Error> {
        Ok( MsgVelNedDepA{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            n: _buf.read_i32::<LittleEndian>()?,
            e: _buf.read_i32::<LittleEndian>()?,
            d: _buf.read_i32::<LittleEndian>()?,
            h_accuracy: _buf.read_u16::<LittleEndian>()?,
            v_accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgVelNedDepA {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgVelNedDepA {
    const MESSAGE_TYPE: u16 = 517;
    const MESSAGE_NAME: &'static str = "MSG_VEL_NED_DEP_A";
}
impl TryFrom<super::Sbp> for MsgVelNedDepA {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgVelNedDepA(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgVelNedDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.n.append_to_sbp_buffer(buf);
        self.e.append_to_sbp_buffer(buf);
        self.d.append_to_sbp_buffer(buf);
        self.h_accuracy.append_to_sbp_buffer(buf);
        self.v_accuracy.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.n.sbp_size();
        size += self.e.sbp_size();
        size += self.d.sbp_size();
        size += self.h_accuracy.sbp_size();
        size += self.v_accuracy.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// GNSS-only Velocity in NED
///
/// This message reports the velocity in local North East Down (NED)
/// coordinates. The NED coordinate system is defined as the local WGS84
/// tangent plane centered at the current position. The full GPS time is given
/// by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelNedGnss {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Velocity North coordinate
    pub n: i32,
    /// Velocity East coordinate
    pub e: i32,
    /// Velocity Down coordinate
    pub d: i32,
    /// Horizontal velocity estimated standard deviation
    pub h_accuracy: u16,
    /// Vertical velocity estimated standard deviation
    pub v_accuracy: u16,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgVelNedGnss {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgVelNedGnss, crate::Error> {
        Ok( MsgVelNedGnss{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            n: _buf.read_i32::<LittleEndian>()?,
            e: _buf.read_i32::<LittleEndian>()?,
            d: _buf.read_i32::<LittleEndian>()?,
            h_accuracy: _buf.read_u16::<LittleEndian>()?,
            v_accuracy: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SbpMessage for MsgVelNedGnss {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgVelNedGnss {
    const MESSAGE_TYPE: u16 = 558;
    const MESSAGE_NAME: &'static str = "MSG_VEL_NED_GNSS";
}
impl TryFrom<super::Sbp> for MsgVelNedGnss {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgVelNedGnss(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgVelNedGnss {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.n.append_to_sbp_buffer(buf);
        self.e.append_to_sbp_buffer(buf);
        self.d.append_to_sbp_buffer(buf);
        self.h_accuracy.append_to_sbp_buffer(buf);
        self.v_accuracy.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.n.sbp_size();
        size += self.e.sbp_size();
        size += self.d.sbp_size();
        size += self.h_accuracy.sbp_size();
        size += self.v_accuracy.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}
