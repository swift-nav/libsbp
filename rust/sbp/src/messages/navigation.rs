// Copyright (C) 2015-2018 Swift Navigation Inc.
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
//! Geodetic navigation messages reporting GPS time, position, velocity,
//! and baseline position solutions. For position solutions, these
//! messages define several different position solutions: single-point
//! (SPP), RTK, and pseudo-absolute position solutions.
//!
//! The SPP is the standalone, absolute GPS position solution using only
//! a single receiver. The RTK solution is the differential GPS
//! solution, which can use either a fixed/integer or floating carrier
//! phase ambiguity. The pseudo-absolute position solution uses a
//! user-provided, well-surveyed base station position (if available)
//! and the RTK solution in tandem.
//!
//! When the inertial navigation mode indicates that the IMU is used,
//! all messages are reported in the vehicle body frame as defined by
//! device settings.  By default, the vehicle body frame is configured to be
//! coincident with the antenna phase center.  When there is no inertial
//! navigation, the solution will be reported at the phase center of the antenna.
//! There is no inertial navigation capability on Piksi Multi or Duro.
//!
//! The tow field, when valid, is most often the Time of Measurement. When this
//! is the case, the 5th bit of flags is set to the default value of 0.
//! When this is not the case, the tow may be a time of arrival or a local
//! system timestamp, irrespective of the time reference (GPS Week or else),
//! but not a Time of Measurement.
//!

#[cfg(feature = "sbp_serde")]
use serde::{Deserialize, Serialize};

#[allow(unused_imports)]
use crate::{parser::SbpParse, BoundedSbpString, UnboundedSbpString};

/// Age of corrections
///
/// This message reports the Age of the corrections used for the current
/// Differential solution
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgAgeCorrections {
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Age of the corrections (0xFFFF indicates invalid)
    pub age: u16,
}

impl SbpParse<MsgAgeCorrections> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgAgeCorrections> {
        Ok( MsgAgeCorrections{
            sender_id: None,
            tow: self.parse()?,
            age: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgAgeCorrections {
    fn get_message_type(&self) -> u16 {
        528
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
/// This message reports the baseline solution in Earth Centered
/// Earth Fixed (ECEF) coordinates. This baseline is the relative
/// vector distance from the base station to the rover receiver. The
/// full GPS time is given by the preceding MSG_GPS_TIME with the
/// matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgBaselineECEF {
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

impl SbpParse<MsgBaselineECEF> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgBaselineECEF> {
        Ok( MsgBaselineECEF{
            sender_id: None,
            tow: self.parse()?,
            x: self.parse()?,
            y: self.parse()?,
            z: self.parse()?,
            accuracy: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgBaselineECEF {
    fn get_message_type(&self) -> u16 {
        523
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

impl crate::serialize::SbpSerialize for MsgBaselineECEF {
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
/// This message reports the baseline solution in Earth Centered
/// Earth Fixed (ECEF) coordinates. This baseline is the relative
/// vector distance from the base station to the rover receiver. The
/// full GPS time is given by the preceding MSG_GPS_TIME with the
/// matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgBaselineECEFDepA {
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

impl SbpParse<MsgBaselineECEFDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgBaselineECEFDepA> {
        Ok( MsgBaselineECEFDepA{
            sender_id: None,
            tow: self.parse()?,
            x: self.parse()?,
            y: self.parse()?,
            z: self.parse()?,
            accuracy: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgBaselineECEFDepA {
    fn get_message_type(&self) -> u16 {
        514
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

impl crate::serialize::SbpSerialize for MsgBaselineECEFDepA {
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgBaselineHeadingDepA {
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

impl SbpParse<MsgBaselineHeadingDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgBaselineHeadingDepA> {
        Ok( MsgBaselineHeadingDepA{
            sender_id: None,
            tow: self.parse()?,
            heading: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgBaselineHeadingDepA {
    fn get_message_type(&self) -> u16 {
        519
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
/// This message reports the baseline solution in North East Down
/// (NED) coordinates. This baseline is the relative vector distance
/// from the base station to the rover receiver, and NED coordinate
/// system is defined at the local WGS84 tangent plane centered at the
/// base station position.  The full GPS time is given by the
/// preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgBaselineNED {
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

impl SbpParse<MsgBaselineNED> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgBaselineNED> {
        Ok( MsgBaselineNED{
            sender_id: None,
            tow: self.parse()?,
            n: self.parse()?,
            e: self.parse()?,
            d: self.parse()?,
            h_accuracy: self.parse()?,
            v_accuracy: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgBaselineNED {
    fn get_message_type(&self) -> u16 {
        524
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

impl crate::serialize::SbpSerialize for MsgBaselineNED {
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
/// This message reports the baseline solution in North East Down
/// (NED) coordinates. This baseline is the relative vector distance
/// from the base station to the rover receiver, and NED coordinate
/// system is defined at the local WGS84 tangent plane centered at the
/// base station position.  The full GPS time is given by the
/// preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgBaselineNEDDepA {
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

impl SbpParse<MsgBaselineNEDDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgBaselineNEDDepA> {
        Ok( MsgBaselineNEDDepA{
            sender_id: None,
            tow: self.parse()?,
            n: self.parse()?,
            e: self.parse()?,
            d: self.parse()?,
            h_accuracy: self.parse()?,
            v_accuracy: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgBaselineNEDDepA {
    fn get_message_type(&self) -> u16 {
        515
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

impl crate::serialize::SbpSerialize for MsgBaselineNEDDepA {
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
/// navigation satellite geometry on positional measurement
/// precision.  The flags field indicated whether the DOP reported
/// corresponds to differential or SPP solution.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgDops {
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

impl SbpParse<MsgDops> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgDops> {
        Ok( MsgDops{
            sender_id: None,
            tow: self.parse()?,
            gdop: self.parse()?,
            pdop: self.parse()?,
            tdop: self.parse()?,
            hdop: self.parse()?,
            vdop: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgDops {
    fn get_message_type(&self) -> u16 {
        520
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
/// navigation satellite geometry on positional measurement
/// precision.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgDopsDepA {
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

impl SbpParse<MsgDopsDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgDopsDepA> {
        Ok( MsgDopsDepA{
            sender_id: None,
            tow: self.parse()?,
            gdop: self.parse()?,
            pdop: self.parse()?,
            tdop: self.parse()?,
            hdop: self.parse()?,
            vdop: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgDopsDepA {
    fn get_message_type(&self) -> u16 {
        518
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
/// This message reports the GPS time, representing the time since
/// the GPS epoch began on midnight January 6, 1980 UTC. GPS time
/// counts the weeks and seconds of the week. The weeks begin at the
/// Saturday/Sunday transition. GPS week 0 began at the beginning of
/// the GPS time scale.
///
/// Within each week number, the GPS time of the week is between
/// between 0 and 604800 seconds (=60*60*24*7). Note that GPS time
/// does not accumulate leap seconds, and as of now, has a small
/// offset from UTC. In a message stream, this message precedes a
/// set of other navigation messages referenced to the same time
/// (but lacking the ns field) and indicates a more precise time of
/// these messages.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgGPSTime {
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

impl SbpParse<MsgGPSTime> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgGPSTime> {
        Ok( MsgGPSTime{
            sender_id: None,
            wn: self.parse()?,
            tow: self.parse()?,
            ns_residual: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgGPSTime {
    fn get_message_type(&self) -> u16 {
        258
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

impl crate::serialize::SbpSerialize for MsgGPSTime {
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
/// This message reports the GPS time, representing the time since
/// the GPS epoch began on midnight January 6, 1980 UTC. GPS time
/// counts the weeks and seconds of the week. The weeks begin at the
/// Saturday/Sunday transition. GPS week 0 began at the beginning of
/// the GPS time scale.
///
/// Within each week number, the GPS time of the week is between
/// between 0 and 604800 seconds (=60*60*24*7). Note that GPS time
/// does not accumulate leap seconds, and as of now, has a small
/// offset from UTC. In a message stream, this message precedes a
/// set of other navigation messages referenced to the same time
/// (but lacking the ns field) and indicates a more precise time of
/// these messages.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgGPSTimeDepA {
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

impl SbpParse<MsgGPSTimeDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgGPSTimeDepA> {
        Ok( MsgGPSTimeDepA{
            sender_id: None,
            wn: self.parse()?,
            tow: self.parse()?,
            ns_residual: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgGPSTimeDepA {
    fn get_message_type(&self) -> u16 {
        256
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

impl crate::serialize::SbpSerialize for MsgGPSTimeDepA {
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
/// This message reports the GPS time, representing the time since
/// the GPS epoch began on midnight January 6, 1980 UTC. GPS time
/// counts the weeks and seconds of the week. The weeks begin at the
/// Saturday/Sunday transition. GPS week 0 began at the beginning of
/// the GPS time scale.
///
/// Within each week number, the GPS time of the week is between
/// between 0 and 604800 seconds (=60*60*24*7). Note that GPS time
/// does not accumulate leap seconds, and as of now, has a small
/// offset from UTC. In a message stream, this message precedes a
/// set of other navigation messages referenced to the same time
/// (but lacking the ns field) and indicates a more precise time of
/// these messages.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgGPSTimeGnss {
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

impl SbpParse<MsgGPSTimeGnss> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgGPSTimeGnss> {
        Ok( MsgGPSTimeGnss{
            sender_id: None,
            wn: self.parse()?,
            tow: self.parse()?,
            ns_residual: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgGPSTimeGnss {
    fn get_message_type(&self) -> u16 {
        260
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

impl crate::serialize::SbpSerialize for MsgGPSTimeGnss {
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
/// The position solution message reports absolute Earth Centered
/// Earth Fixed (ECEF) coordinates and the status (single point vs
/// pseudo-absolute RTK) of the position solution. If the rover
/// receiver knows the surveyed position of the base station and has
/// an RTK solution, this reports a pseudo-absolute position
/// solution using the base station position and the rover's RTK
/// baseline vector. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosECEF {
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

impl SbpParse<MsgPosECEF> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgPosECEF> {
        Ok( MsgPosECEF{
            sender_id: None,
            tow: self.parse()?,
            x: self.parse()?,
            y: self.parse()?,
            z: self.parse()?,
            accuracy: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgPosECEF {
    fn get_message_type(&self) -> u16 {
        521
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

impl crate::serialize::SbpSerialize for MsgPosECEF {
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
/// The position solution message reports absolute Earth Centered
/// Earth Fixed (ECEF) coordinates and the status (single point vs
/// pseudo-absolute RTK) of the position solution. The message also
/// reports the upper triangular portion of the 3x3 covariance matrix.
/// If the receiver knows the surveyed position of the base station and has
/// an RTK solution, this reports a pseudo-absolute position
/// solution using the base station position and the rover's RTK
/// baseline vector. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosECEFCov {
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

impl SbpParse<MsgPosECEFCov> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgPosECEFCov> {
        Ok( MsgPosECEFCov{
            sender_id: None,
            tow: self.parse()?,
            x: self.parse()?,
            y: self.parse()?,
            z: self.parse()?,
            cov_x_x: self.parse()?,
            cov_x_y: self.parse()?,
            cov_x_z: self.parse()?,
            cov_y_y: self.parse()?,
            cov_y_z: self.parse()?,
            cov_z_z: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgPosECEFCov {
    fn get_message_type(&self) -> u16 {
        532
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

impl crate::serialize::SbpSerialize for MsgPosECEFCov {
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
/// The position solution message reports absolute Earth Centered
/// Earth Fixed (ECEF) coordinates and the status (single point vs
/// pseudo-absolute RTK) of the position solution. The message also
/// reports the upper triangular portion of the 3x3 covariance matrix.
/// If the receiver knows the surveyed position of the base station and has
/// an RTK solution, this reports a pseudo-absolute position
/// solution using the base station position and the rover's RTK
/// baseline vector. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosECEFCovGnss {
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

impl SbpParse<MsgPosECEFCovGnss> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgPosECEFCovGnss> {
        Ok( MsgPosECEFCovGnss{
            sender_id: None,
            tow: self.parse()?,
            x: self.parse()?,
            y: self.parse()?,
            z: self.parse()?,
            cov_x_x: self.parse()?,
            cov_x_y: self.parse()?,
            cov_x_z: self.parse()?,
            cov_y_y: self.parse()?,
            cov_y_z: self.parse()?,
            cov_z_z: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgPosECEFCovGnss {
    fn get_message_type(&self) -> u16 {
        564
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

impl crate::serialize::SbpSerialize for MsgPosECEFCovGnss {
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
/// The position solution message reports absolute Earth Centered
/// Earth Fixed (ECEF) coordinates and the status (single point vs
/// pseudo-absolute RTK) of the position solution. If the rover
/// receiver knows the surveyed position of the base station and has
/// an RTK solution, this reports a pseudo-absolute position
/// solution using the base station position and the rover's RTK
/// baseline vector. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosECEFDepA {
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

impl SbpParse<MsgPosECEFDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgPosECEFDepA> {
        Ok( MsgPosECEFDepA{
            sender_id: None,
            tow: self.parse()?,
            x: self.parse()?,
            y: self.parse()?,
            z: self.parse()?,
            accuracy: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgPosECEFDepA {
    fn get_message_type(&self) -> u16 {
        512
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

impl crate::serialize::SbpSerialize for MsgPosECEFDepA {
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
/// The position solution message reports absolute Earth Centered
/// Earth Fixed (ECEF) coordinates and the status (single point vs
/// pseudo-absolute RTK) of the position solution. If the rover
/// receiver knows the surveyed position of the base station and has
/// an RTK solution, this reports a pseudo-absolute position
/// solution using the base station position and the rover's RTK
/// baseline vector. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosECEFGnss {
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

impl SbpParse<MsgPosECEFGnss> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgPosECEFGnss> {
        Ok( MsgPosECEFGnss{
            sender_id: None,
            tow: self.parse()?,
            x: self.parse()?,
            y: self.parse()?,
            z: self.parse()?,
            accuracy: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgPosECEFGnss {
    fn get_message_type(&self) -> u16 {
        553
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

impl crate::serialize::SbpSerialize for MsgPosECEFGnss {
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
/// This position solution message reports the absolute geodetic
/// coordinates and the status (single point vs pseudo-absolute RTK)
/// of the position solution. If the rover receiver knows the
/// surveyed position of the base station and has an RTK solution,
/// this reports a pseudo-absolute position solution using the base
/// station position and the rover's RTK baseline vector. The full
/// GPS time is given by the preceding MSG_GPS_TIME with the
/// matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosLLH {
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

impl SbpParse<MsgPosLLH> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgPosLLH> {
        Ok( MsgPosLLH{
            sender_id: None,
            tow: self.parse()?,
            lat: self.parse()?,
            lon: self.parse()?,
            height: self.parse()?,
            h_accuracy: self.parse()?,
            v_accuracy: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgPosLLH {
    fn get_message_type(&self) -> u16 {
        522
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

impl crate::serialize::SbpSerialize for MsgPosLLH {
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

/// Geodetic Position
///
/// This position solution message reports the absolute geodetic
/// coordinates and the status (single point vs pseudo-absolute RTK)
/// of the position solution as well as the upper triangle of the 3x3
/// covariance matrix.  The position information and Fix Mode flags should
/// follow the MSG_POS_LLH message.  Since the covariance matrix is computed
/// in the local-level North, East, Down frame, the covariance terms follow
/// with that convention. Thus, covariances are reported against the "downward"
/// measurement and care should be taken with the sign convention.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosLLHCov {
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

impl SbpParse<MsgPosLLHCov> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgPosLLHCov> {
        Ok( MsgPosLLHCov{
            sender_id: None,
            tow: self.parse()?,
            lat: self.parse()?,
            lon: self.parse()?,
            height: self.parse()?,
            cov_n_n: self.parse()?,
            cov_n_e: self.parse()?,
            cov_n_d: self.parse()?,
            cov_e_e: self.parse()?,
            cov_e_d: self.parse()?,
            cov_d_d: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgPosLLHCov {
    fn get_message_type(&self) -> u16 {
        529
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

impl crate::serialize::SbpSerialize for MsgPosLLHCov {
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
/// This position solution message reports the absolute geodetic
/// coordinates and the status (single point vs pseudo-absolute RTK)
/// of the position solution as well as the upper triangle of the 3x3
/// covariance matrix.  The position information and Fix Mode flags should
/// follow the MSG_POS_LLH message.  Since the covariance matrix is computed
/// in the local-level North, East, Down frame, the covariance terms follow
/// with that convention. Thus, covariances are reported against the "downward"
/// measurement and care should be taken with the sign convention.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosLLHCovGnss {
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

impl SbpParse<MsgPosLLHCovGnss> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgPosLLHCovGnss> {
        Ok( MsgPosLLHCovGnss{
            sender_id: None,
            tow: self.parse()?,
            lat: self.parse()?,
            lon: self.parse()?,
            height: self.parse()?,
            cov_n_n: self.parse()?,
            cov_n_e: self.parse()?,
            cov_n_d: self.parse()?,
            cov_e_e: self.parse()?,
            cov_e_d: self.parse()?,
            cov_d_d: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgPosLLHCovGnss {
    fn get_message_type(&self) -> u16 {
        561
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

impl crate::serialize::SbpSerialize for MsgPosLLHCovGnss {
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
/// This position solution message reports the absolute geodetic
/// coordinates and the status (single point vs pseudo-absolute RTK)
/// of the position solution. If the rover receiver knows the
/// surveyed position of the base station and has an RTK solution,
/// this reports a pseudo-absolute position solution using the base
/// station position and the rover's RTK baseline vector. The full
/// GPS time is given by the preceding MSG_GPS_TIME with the
/// matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosLLHDepA {
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

impl SbpParse<MsgPosLLHDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgPosLLHDepA> {
        Ok( MsgPosLLHDepA{
            sender_id: None,
            tow: self.parse()?,
            lat: self.parse()?,
            lon: self.parse()?,
            height: self.parse()?,
            h_accuracy: self.parse()?,
            v_accuracy: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgPosLLHDepA {
    fn get_message_type(&self) -> u16 {
        513
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

impl crate::serialize::SbpSerialize for MsgPosLLHDepA {
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
/// This position solution message reports the absolute geodetic
/// coordinates and the status (single point vs pseudo-absolute RTK)
/// of the position solution. If the rover receiver knows the
/// surveyed position of the base station and has an RTK solution,
/// this reports a pseudo-absolute position solution using the base
/// station position and the rover's RTK baseline vector. The full
/// GPS time is given by the preceding MSG_GPS_TIME with the
/// matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPosLLHGnss {
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

impl SbpParse<MsgPosLLHGnss> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgPosLLHGnss> {
        Ok( MsgPosLLHGnss{
            sender_id: None,
            tow: self.parse()?,
            lat: self.parse()?,
            lon: self.parse()?,
            height: self.parse()?,
            h_accuracy: self.parse()?,
            v_accuracy: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgPosLLHGnss {
    fn get_message_type(&self) -> u16 {
        554
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

impl crate::serialize::SbpSerialize for MsgPosLLHGnss {
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

/// Computed Position and Protection Level
///
/// This message reports the local vertical and horizontal protection levels
/// associated with a given LLH position solution. The full GPS time is given
/// by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgProtectionLevel {
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

impl SbpParse<MsgProtectionLevel> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgProtectionLevel> {
        Ok( MsgProtectionLevel{
            sender_id: None,
            tow: self.parse()?,
            vpl: self.parse()?,
            hpl: self.parse()?,
            lat: self.parse()?,
            lon: self.parse()?,
            height: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgProtectionLevel {
    fn get_message_type(&self) -> u16 {
        534
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

impl crate::serialize::SbpSerialize for MsgProtectionLevel {
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
/// which indicate the source of the UTC offset value and source of the time fix.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgUtcTime {
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

impl SbpParse<MsgUtcTime> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgUtcTime> {
        Ok( MsgUtcTime{
            sender_id: None,
            flags: self.parse()?,
            tow: self.parse()?,
            year: self.parse()?,
            month: self.parse()?,
            day: self.parse()?,
            hours: self.parse()?,
            minutes: self.parse()?,
            seconds: self.parse()?,
            ns: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgUtcTime {
    fn get_message_type(&self) -> u16 {
        259
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
/// which indicate the source of the UTC offset value and source of the time fix.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgUtcTimeGnss {
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

impl SbpParse<MsgUtcTimeGnss> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgUtcTimeGnss> {
        Ok( MsgUtcTimeGnss{
            sender_id: None,
            flags: self.parse()?,
            tow: self.parse()?,
            year: self.parse()?,
            month: self.parse()?,
            day: self.parse()?,
            hours: self.parse()?,
            minutes: self.parse()?,
            seconds: self.parse()?,
            ns: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgUtcTimeGnss {
    fn get_message_type(&self) -> u16 {
        261
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
/// This message reports the velocity in the Vehicle Body Frame. By convention,
/// the x-axis should point out the nose of the vehicle and represent the forward
/// direction, while as the y-axis should point out the right hand side of the vehicle.
/// Since this is a right handed system, z should point out the bottom of the vehicle.
/// The orientation and origin of the Vehicle Body Frame are specified via the device settings.
/// The full GPS time is given by the preceding MSG_GPS_TIME with the
/// matching time-of-week (tow). This message is only produced by inertial versions of Swift
/// products and is not available from Piksi Multi or Duro.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelBody {
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

impl SbpParse<MsgVelBody> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgVelBody> {
        Ok( MsgVelBody{
            sender_id: None,
            tow: self.parse()?,
            x: self.parse()?,
            y: self.parse()?,
            z: self.parse()?,
            cov_x_x: self.parse()?,
            cov_x_y: self.parse()?,
            cov_x_z: self.parse()?,
            cov_y_y: self.parse()?,
            cov_y_z: self.parse()?,
            cov_z_z: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgVelBody {
    fn get_message_type(&self) -> u16 {
        531
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
/// This message reports the velocity in Earth Centered Earth Fixed
/// (ECEF) coordinates. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelECEF {
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

impl SbpParse<MsgVelECEF> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgVelECEF> {
        Ok( MsgVelECEF{
            sender_id: None,
            tow: self.parse()?,
            x: self.parse()?,
            y: self.parse()?,
            z: self.parse()?,
            accuracy: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgVelECEF {
    fn get_message_type(&self) -> u16 {
        525
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

impl crate::serialize::SbpSerialize for MsgVelECEF {
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
/// This message reports the velocity in Earth Centered Earth Fixed
/// (ECEF) coordinates. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelECEFCov {
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

impl SbpParse<MsgVelECEFCov> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgVelECEFCov> {
        Ok( MsgVelECEFCov{
            sender_id: None,
            tow: self.parse()?,
            x: self.parse()?,
            y: self.parse()?,
            z: self.parse()?,
            cov_x_x: self.parse()?,
            cov_x_y: self.parse()?,
            cov_x_z: self.parse()?,
            cov_y_y: self.parse()?,
            cov_y_z: self.parse()?,
            cov_z_z: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgVelECEFCov {
    fn get_message_type(&self) -> u16 {
        533
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

impl crate::serialize::SbpSerialize for MsgVelECEFCov {
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
/// This message reports the velocity in Earth Centered Earth Fixed
/// (ECEF) coordinates. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelECEFCovGnss {
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

impl SbpParse<MsgVelECEFCovGnss> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgVelECEFCovGnss> {
        Ok( MsgVelECEFCovGnss{
            sender_id: None,
            tow: self.parse()?,
            x: self.parse()?,
            y: self.parse()?,
            z: self.parse()?,
            cov_x_x: self.parse()?,
            cov_x_y: self.parse()?,
            cov_x_z: self.parse()?,
            cov_y_y: self.parse()?,
            cov_y_z: self.parse()?,
            cov_z_z: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgVelECEFCovGnss {
    fn get_message_type(&self) -> u16 {
        565
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

impl crate::serialize::SbpSerialize for MsgVelECEFCovGnss {
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
/// This message reports the velocity in Earth Centered Earth Fixed
/// (ECEF) coordinates. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelECEFDepA {
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

impl SbpParse<MsgVelECEFDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgVelECEFDepA> {
        Ok( MsgVelECEFDepA{
            sender_id: None,
            tow: self.parse()?,
            x: self.parse()?,
            y: self.parse()?,
            z: self.parse()?,
            accuracy: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgVelECEFDepA {
    fn get_message_type(&self) -> u16 {
        516
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

impl crate::serialize::SbpSerialize for MsgVelECEFDepA {
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
/// This message reports the velocity in Earth Centered Earth Fixed
/// (ECEF) coordinates. The full GPS time is given by the preceding
/// MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelECEFGnss {
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

impl SbpParse<MsgVelECEFGnss> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgVelECEFGnss> {
        Ok( MsgVelECEFGnss{
            sender_id: None,
            tow: self.parse()?,
            x: self.parse()?,
            y: self.parse()?,
            z: self.parse()?,
            accuracy: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgVelECEFGnss {
    fn get_message_type(&self) -> u16 {
        557
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

impl crate::serialize::SbpSerialize for MsgVelECEFGnss {
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
/// tangent plane centered at the current position. The full GPS time is
/// given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelNED {
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

impl SbpParse<MsgVelNED> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgVelNED> {
        Ok( MsgVelNED{
            sender_id: None,
            tow: self.parse()?,
            n: self.parse()?,
            e: self.parse()?,
            d: self.parse()?,
            h_accuracy: self.parse()?,
            v_accuracy: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgVelNED {
    fn get_message_type(&self) -> u16 {
        526
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

impl crate::serialize::SbpSerialize for MsgVelNED {
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
/// tangent plane centered at the current position. The full GPS time is
/// given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
/// This message is similar to the MSG_VEL_NED, but it includes the upper triangular
/// portion of the 3x3 covariance matrix.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelNEDCov {
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

impl SbpParse<MsgVelNEDCov> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgVelNEDCov> {
        Ok( MsgVelNEDCov{
            sender_id: None,
            tow: self.parse()?,
            n: self.parse()?,
            e: self.parse()?,
            d: self.parse()?,
            cov_n_n: self.parse()?,
            cov_n_e: self.parse()?,
            cov_n_d: self.parse()?,
            cov_e_e: self.parse()?,
            cov_e_d: self.parse()?,
            cov_d_d: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgVelNEDCov {
    fn get_message_type(&self) -> u16 {
        530
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

impl crate::serialize::SbpSerialize for MsgVelNEDCov {
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
/// tangent plane centered at the current position. The full GPS time is
/// given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
/// This message is similar to the MSG_VEL_NED, but it includes the upper triangular
/// portion of the 3x3 covariance matrix.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelNEDCovGnss {
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

impl SbpParse<MsgVelNEDCovGnss> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgVelNEDCovGnss> {
        Ok( MsgVelNEDCovGnss{
            sender_id: None,
            tow: self.parse()?,
            n: self.parse()?,
            e: self.parse()?,
            d: self.parse()?,
            cov_n_n: self.parse()?,
            cov_n_e: self.parse()?,
            cov_n_d: self.parse()?,
            cov_e_e: self.parse()?,
            cov_e_d: self.parse()?,
            cov_d_d: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgVelNEDCovGnss {
    fn get_message_type(&self) -> u16 {
        562
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

impl crate::serialize::SbpSerialize for MsgVelNEDCovGnss {
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
/// tangent plane centered at the current position. The full GPS time is
/// given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelNEDDepA {
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

impl SbpParse<MsgVelNEDDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgVelNEDDepA> {
        Ok( MsgVelNEDDepA{
            sender_id: None,
            tow: self.parse()?,
            n: self.parse()?,
            e: self.parse()?,
            d: self.parse()?,
            h_accuracy: self.parse()?,
            v_accuracy: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgVelNEDDepA {
    fn get_message_type(&self) -> u16 {
        517
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

impl crate::serialize::SbpSerialize for MsgVelNEDDepA {
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
/// tangent plane centered at the current position. The full GPS time is
/// given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgVelNEDGnss {
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

impl SbpParse<MsgVelNEDGnss> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgVelNEDGnss> {
        Ok( MsgVelNEDGnss{
            sender_id: None,
            tow: self.parse()?,
            n: self.parse()?,
            e: self.parse()?,
            d: self.parse()?,
            h_accuracy: self.parse()?,
            v_accuracy: self.parse()?,
            n_sats: self.parse()?,
            flags: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgVelNEDGnss {
    fn get_message_type(&self) -> u16 {
        558
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

impl crate::serialize::SbpSerialize for MsgVelNEDGnss {
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
