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
// Automatically generated from yaml/swiftnav/sbp/tracking.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Satellite code and carrier-phase tracking messages from the device.
//!

extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
use super::gnss::*;
#[cfg(feature = "serialize")]
use serde::{Deserialize, Serialize};

/// Measurement Engine signal tracking channel states
///
/// The tracking message returns a variable-length array of tracking
/// channel states. It reports status and carrier-to-noise density
/// measurements for all tracked satellites.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgMeasurementState {
    pub sender_id: Option<u16>,
    /// ME signal tracking channel state
    pub states: Vec<MeasurementState>,
}

impl MsgMeasurementState {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgMeasurementState, crate::Error> {
        Ok(MsgMeasurementState {
            sender_id: None,
            states: MeasurementState::parse_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgMeasurementState {
    fn get_message_type(&self) -> u16 {
        97
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

impl crate::serialize::SbpSerialize for MsgMeasurementState {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.states.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.states.sbp_size();
        size
    }
}

/// Tracking channel correlations
///
/// When enabled, a tracking channel can output the correlations at each
/// update interval.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingIq {
    pub sender_id: Option<u16>,
    /// Tracking channel of origin
    pub channel: u8,
    /// GNSS signal identifier
    pub sid: GnssSignal,
    /// Early, Prompt and Late correlations
    pub corrs: Vec<TrackingChannelCorrelation>,
}

impl MsgTrackingIq {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingIq, crate::Error> {
        Ok(MsgTrackingIq {
            sender_id: None,
            channel: _buf.read_u8()?,
            sid: GnssSignal::parse(_buf)?,
            corrs: TrackingChannelCorrelation::parse_array_limit(_buf, 3)?,
        })
    }
}
impl super::SBPMessage for MsgTrackingIq {
    fn get_message_type(&self) -> u16 {
        45
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

impl crate::serialize::SbpSerialize for MsgTrackingIq {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.channel.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.corrs.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.channel.sbp_size();
        size += self.sid.sbp_size();
        size += self.corrs.sbp_size();
        size
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingIqDepA {
    pub sender_id: Option<u16>,
    /// Tracking channel of origin
    pub channel: u8,
    /// GNSS signal identifier
    pub sid: GnssSignalDep,
    /// Early, Prompt and Late correlations
    pub corrs: Vec<TrackingChannelCorrelationDep>,
}

impl MsgTrackingIqDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingIqDepA, crate::Error> {
        Ok(MsgTrackingIqDepA {
            sender_id: None,
            channel: _buf.read_u8()?,
            sid: GnssSignalDep::parse(_buf)?,
            corrs: TrackingChannelCorrelationDep::parse_array_limit(_buf, 3)?,
        })
    }
}
impl super::SBPMessage for MsgTrackingIqDepA {
    fn get_message_type(&self) -> u16 {
        28
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

impl crate::serialize::SbpSerialize for MsgTrackingIqDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.channel.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.corrs.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.channel.sbp_size();
        size += self.sid.sbp_size();
        size += self.corrs.sbp_size();
        size
    }
}

/// Tracking channel correlations
///
/// When enabled, a tracking channel can output the correlations at each
/// update interval.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingIqDepB {
    pub sender_id: Option<u16>,
    /// Tracking channel of origin
    pub channel: u8,
    /// GNSS signal identifier
    pub sid: GnssSignal,
    /// Early, Prompt and Late correlations
    pub corrs: Vec<TrackingChannelCorrelationDep>,
}

impl MsgTrackingIqDepB {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingIqDepB, crate::Error> {
        Ok(MsgTrackingIqDepB {
            sender_id: None,
            channel: _buf.read_u8()?,
            sid: GnssSignal::parse(_buf)?,
            corrs: TrackingChannelCorrelationDep::parse_array_limit(_buf, 3)?,
        })
    }
}
impl super::SBPMessage for MsgTrackingIqDepB {
    fn get_message_type(&self) -> u16 {
        44
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

impl crate::serialize::SbpSerialize for MsgTrackingIqDepB {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.channel.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.corrs.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.channel.sbp_size();
        size += self.sid.sbp_size();
        size += self.corrs.sbp_size();
        size
    }
}

/// Signal tracking channel states
///
/// The tracking message returns a variable-length array of tracking
/// channel states. It reports status and carrier-to-noise density
/// measurements for all tracked satellites.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingState {
    pub sender_id: Option<u16>,
    /// Signal tracking channel state
    pub states: Vec<TrackingChannelState>,
}

impl MsgTrackingState {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingState, crate::Error> {
        Ok(MsgTrackingState {
            sender_id: None,
            states: TrackingChannelState::parse_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgTrackingState {
    fn get_message_type(&self) -> u16 {
        65
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

impl crate::serialize::SbpSerialize for MsgTrackingState {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.states.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.states.sbp_size();
        size
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingStateDepA {
    pub sender_id: Option<u16>,
    /// Satellite tracking channel state
    pub states: Vec<TrackingChannelStateDepA>,
}

impl MsgTrackingStateDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingStateDepA, crate::Error> {
        Ok(MsgTrackingStateDepA {
            sender_id: None,
            states: TrackingChannelStateDepA::parse_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgTrackingStateDepA {
    fn get_message_type(&self) -> u16 {
        22
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

impl crate::serialize::SbpSerialize for MsgTrackingStateDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.states.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.states.sbp_size();
        size
    }
}

/// Deprecated.
///
/// Deprecated.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingStateDepB {
    pub sender_id: Option<u16>,
    /// Signal tracking channel state
    pub states: Vec<TrackingChannelStateDepB>,
}

impl MsgTrackingStateDepB {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingStateDepB, crate::Error> {
        Ok(MsgTrackingStateDepB {
            sender_id: None,
            states: TrackingChannelStateDepB::parse_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgTrackingStateDepB {
    fn get_message_type(&self) -> u16 {
        19
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

impl crate::serialize::SbpSerialize for MsgTrackingStateDepB {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.states.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.states.sbp_size();
        size
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingStateDetailedDep {
    pub sender_id: Option<u16>,
    /// Receiver clock time.
    pub recv_time: u64,
    /// Time of transmission of signal from satellite. TOW only valid when TOW
    /// status is decoded or propagated. WN only valid when week number valid
    /// flag is set.
    pub tot: GPSTimeDep,
    /// Pseudorange observation. Valid only when pseudorange valid flag is set.
    pub P: u32,
    /// Pseudorange observation standard deviation. Valid only when pseudorange
    /// valid flag is set.
    pub P_std: u16,
    /// Carrier phase observation with typical sign convention. Valid only when
    /// PLL pessimistic lock is achieved.
    pub L: CarrierPhase,
    /// Carrier-to-Noise density
    pub cn0: u8,
    /// Lock time. It is encoded according to DF402 from the RTCM 10403.2
    /// Amendment 2 specification. Valid values range from 0 to 15.
    pub lock: u16,
    /// GNSS signal identifier.
    pub sid: GnssSignalDep,
    /// Carrier Doppler frequency.
    pub doppler: i32,
    /// Carrier Doppler frequency standard deviation.
    pub doppler_std: u16,
    /// Number of seconds of continuous tracking. Specifies how much time signal
    /// is in continuous track.
    pub uptime: u32,
    /// TCXO clock offset. Valid only when valid clock valid flag is set.
    pub clock_offset: i16,
    /// TCXO clock drift. Valid only when valid clock valid flag is set.
    pub clock_drift: i16,
    /// Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
    pub corr_spacing: u16,
    /// Acceleration. Valid only when acceleration valid flag is set.
    pub acceleration: i8,
    /// Synchronization status flags.
    pub sync_flags: u8,
    /// TOW status flags.
    pub tow_flags: u8,
    /// Tracking loop status flags.
    pub track_flags: u8,
    /// Navigation data status flags.
    pub nav_flags: u8,
    /// Parameters sets flags.
    pub pset_flags: u8,
    /// Miscellaneous flags.
    pub misc_flags: u8,
}

impl MsgTrackingStateDetailedDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingStateDetailedDep, crate::Error> {
        Ok(MsgTrackingStateDetailedDep {
            sender_id: None,
            recv_time: _buf.read_u64::<LittleEndian>()?,
            tot: GPSTimeDep::parse(_buf)?,
            P: _buf.read_u32::<LittleEndian>()?,
            P_std: _buf.read_u16::<LittleEndian>()?,
            L: CarrierPhase::parse(_buf)?,
            cn0: _buf.read_u8()?,
            lock: _buf.read_u16::<LittleEndian>()?,
            sid: GnssSignalDep::parse(_buf)?,
            doppler: _buf.read_i32::<LittleEndian>()?,
            doppler_std: _buf.read_u16::<LittleEndian>()?,
            uptime: _buf.read_u32::<LittleEndian>()?,
            clock_offset: _buf.read_i16::<LittleEndian>()?,
            clock_drift: _buf.read_i16::<LittleEndian>()?,
            corr_spacing: _buf.read_u16::<LittleEndian>()?,
            acceleration: _buf.read_i8()?,
            sync_flags: _buf.read_u8()?,
            tow_flags: _buf.read_u8()?,
            track_flags: _buf.read_u8()?,
            nav_flags: _buf.read_u8()?,
            pset_flags: _buf.read_u8()?,
            misc_flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgTrackingStateDetailedDep {
    fn get_message_type(&self) -> u16 {
        17
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

impl crate::serialize::SbpSerialize for MsgTrackingStateDetailedDep {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.recv_time.append_to_sbp_buffer(buf);
        self.tot.append_to_sbp_buffer(buf);
        self.P.append_to_sbp_buffer(buf);
        self.P_std.append_to_sbp_buffer(buf);
        self.L.append_to_sbp_buffer(buf);
        self.cn0.append_to_sbp_buffer(buf);
        self.lock.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.doppler.append_to_sbp_buffer(buf);
        self.doppler_std.append_to_sbp_buffer(buf);
        self.uptime.append_to_sbp_buffer(buf);
        self.clock_offset.append_to_sbp_buffer(buf);
        self.clock_drift.append_to_sbp_buffer(buf);
        self.corr_spacing.append_to_sbp_buffer(buf);
        self.acceleration.append_to_sbp_buffer(buf);
        self.sync_flags.append_to_sbp_buffer(buf);
        self.tow_flags.append_to_sbp_buffer(buf);
        self.track_flags.append_to_sbp_buffer(buf);
        self.nav_flags.append_to_sbp_buffer(buf);
        self.pset_flags.append_to_sbp_buffer(buf);
        self.misc_flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.recv_time.sbp_size();
        size += self.tot.sbp_size();
        size += self.P.sbp_size();
        size += self.P_std.sbp_size();
        size += self.L.sbp_size();
        size += self.cn0.sbp_size();
        size += self.lock.sbp_size();
        size += self.sid.sbp_size();
        size += self.doppler.sbp_size();
        size += self.doppler_std.sbp_size();
        size += self.uptime.sbp_size();
        size += self.clock_offset.sbp_size();
        size += self.clock_drift.sbp_size();
        size += self.corr_spacing.sbp_size();
        size += self.acceleration.sbp_size();
        size += self.sync_flags.sbp_size();
        size += self.tow_flags.sbp_size();
        size += self.track_flags.sbp_size();
        size += self.nav_flags.sbp_size();
        size += self.pset_flags.sbp_size();
        size += self.misc_flags.sbp_size();
        size
    }
}

/// Detailed signal tracking channel states. DEPRECATED.
///
/// The tracking message returns a set tracking channel parameters for a
/// single tracking channel useful for debugging issues.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingStateDetailedDepA {
    pub sender_id: Option<u16>,
    /// Receiver clock time.
    pub recv_time: u64,
    /// Time of transmission of signal from satellite. TOW only valid when TOW
    /// status is decoded or propagated. WN only valid when week number valid
    /// flag is set.
    pub tot: GPSTime,
    /// Pseudorange observation. Valid only when pseudorange valid flag is set.
    pub P: u32,
    /// Pseudorange observation standard deviation. Valid only when pseudorange
    /// valid flag is set.
    pub P_std: u16,
    /// Carrier phase observation with typical sign convention. Valid only when
    /// PLL pessimistic lock is achieved.
    pub L: CarrierPhase,
    /// Carrier-to-Noise density
    pub cn0: u8,
    /// Lock time. It is encoded according to DF402 from the RTCM 10403.2
    /// Amendment 2 specification. Valid values range from 0 to 15.
    pub lock: u16,
    /// GNSS signal identifier.
    pub sid: GnssSignal,
    /// Carrier Doppler frequency.
    pub doppler: i32,
    /// Carrier Doppler frequency standard deviation.
    pub doppler_std: u16,
    /// Number of seconds of continuous tracking. Specifies how much time signal
    /// is in continuous track.
    pub uptime: u32,
    /// TCXO clock offset. Valid only when valid clock valid flag is set.
    pub clock_offset: i16,
    /// TCXO clock drift. Valid only when valid clock valid flag is set.
    pub clock_drift: i16,
    /// Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
    pub corr_spacing: u16,
    /// Acceleration. Valid only when acceleration valid flag is set.
    pub acceleration: i8,
    /// Synchronization status flags.
    pub sync_flags: u8,
    /// TOW status flags.
    pub tow_flags: u8,
    /// Tracking loop status flags.
    pub track_flags: u8,
    /// Navigation data status flags.
    pub nav_flags: u8,
    /// Parameters sets flags.
    pub pset_flags: u8,
    /// Miscellaneous flags.
    pub misc_flags: u8,
}

impl MsgTrackingStateDetailedDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingStateDetailedDepA, crate::Error> {
        Ok(MsgTrackingStateDetailedDepA {
            sender_id: None,
            recv_time: _buf.read_u64::<LittleEndian>()?,
            tot: GPSTime::parse(_buf)?,
            P: _buf.read_u32::<LittleEndian>()?,
            P_std: _buf.read_u16::<LittleEndian>()?,
            L: CarrierPhase::parse(_buf)?,
            cn0: _buf.read_u8()?,
            lock: _buf.read_u16::<LittleEndian>()?,
            sid: GnssSignal::parse(_buf)?,
            doppler: _buf.read_i32::<LittleEndian>()?,
            doppler_std: _buf.read_u16::<LittleEndian>()?,
            uptime: _buf.read_u32::<LittleEndian>()?,
            clock_offset: _buf.read_i16::<LittleEndian>()?,
            clock_drift: _buf.read_i16::<LittleEndian>()?,
            corr_spacing: _buf.read_u16::<LittleEndian>()?,
            acceleration: _buf.read_i8()?,
            sync_flags: _buf.read_u8()?,
            tow_flags: _buf.read_u8()?,
            track_flags: _buf.read_u8()?,
            nav_flags: _buf.read_u8()?,
            pset_flags: _buf.read_u8()?,
            misc_flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgTrackingStateDetailedDepA {
    fn get_message_type(&self) -> u16 {
        33
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

impl crate::serialize::SbpSerialize for MsgTrackingStateDetailedDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.recv_time.append_to_sbp_buffer(buf);
        self.tot.append_to_sbp_buffer(buf);
        self.P.append_to_sbp_buffer(buf);
        self.P_std.append_to_sbp_buffer(buf);
        self.L.append_to_sbp_buffer(buf);
        self.cn0.append_to_sbp_buffer(buf);
        self.lock.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.doppler.append_to_sbp_buffer(buf);
        self.doppler_std.append_to_sbp_buffer(buf);
        self.uptime.append_to_sbp_buffer(buf);
        self.clock_offset.append_to_sbp_buffer(buf);
        self.clock_drift.append_to_sbp_buffer(buf);
        self.corr_spacing.append_to_sbp_buffer(buf);
        self.acceleration.append_to_sbp_buffer(buf);
        self.sync_flags.append_to_sbp_buffer(buf);
        self.tow_flags.append_to_sbp_buffer(buf);
        self.track_flags.append_to_sbp_buffer(buf);
        self.nav_flags.append_to_sbp_buffer(buf);
        self.pset_flags.append_to_sbp_buffer(buf);
        self.misc_flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.recv_time.sbp_size();
        size += self.tot.sbp_size();
        size += self.P.sbp_size();
        size += self.P_std.sbp_size();
        size += self.L.sbp_size();
        size += self.cn0.sbp_size();
        size += self.lock.sbp_size();
        size += self.sid.sbp_size();
        size += self.doppler.sbp_size();
        size += self.doppler_std.sbp_size();
        size += self.uptime.sbp_size();
        size += self.clock_offset.sbp_size();
        size += self.clock_drift.sbp_size();
        size += self.corr_spacing.sbp_size();
        size += self.acceleration.sbp_size();
        size += self.sync_flags.sbp_size();
        size += self.tow_flags.sbp_size();
        size += self.track_flags.sbp_size();
        size += self.nav_flags.sbp_size();
        size += self.pset_flags.sbp_size();
        size += self.misc_flags.sbp_size();
        size
    }
}

/// Measurement Engine signal tracking channel state
///
/// Measurement Engine tracking channel state for a specific satellite signal
/// and measured signal power.
/// The mesid field for Glonass can either
/// carry the FCN as 100 + FCN where FCN is in [-7, +6] or
/// the Slot ID (from 1 to 28)
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MeasurementState {
    /// Measurement Engine GNSS signal being tracked (carries either Glonass FCN
    /// or SLOT)
    pub mesid: GnssSignal,
    /// Carrier-to-Noise density.  Zero implies invalid cn0.
    pub cn0: u8,
}

impl MeasurementState {
    pub fn parse(_buf: &mut &[u8]) -> Result<MeasurementState, crate::Error> {
        Ok(MeasurementState {
            mesid: GnssSignal::parse(_buf)?,
            cn0: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<MeasurementState>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(MeasurementState::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<MeasurementState>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(MeasurementState::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for MeasurementState {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.mesid.append_to_sbp_buffer(buf);
        self.cn0.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.mesid.sbp_size();
        size += self.cn0.sbp_size();
        size
    }
}

/// Complex correlation structure
///
/// Structure containing in-phase and quadrature correlation components.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct TrackingChannelCorrelation {
    /// In-phase correlation
    pub I: i16,
    /// Quadrature correlation
    pub Q: i16,
}

impl TrackingChannelCorrelation {
    pub fn parse(_buf: &mut &[u8]) -> Result<TrackingChannelCorrelation, crate::Error> {
        Ok(TrackingChannelCorrelation {
            I: _buf.read_i16::<LittleEndian>()?,
            Q: _buf.read_i16::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<TrackingChannelCorrelation>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TrackingChannelCorrelation::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TrackingChannelCorrelation>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TrackingChannelCorrelation::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for TrackingChannelCorrelation {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.I.append_to_sbp_buffer(buf);
        self.Q.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.I.sbp_size();
        size += self.Q.sbp_size();
        size
    }
}

/// Complex correlation structure
///
/// Structure containing in-phase and quadrature correlation components.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct TrackingChannelCorrelationDep {
    /// In-phase correlation
    pub I: i32,
    /// Quadrature correlation
    pub Q: i32,
}

impl TrackingChannelCorrelationDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<TrackingChannelCorrelationDep, crate::Error> {
        Ok(TrackingChannelCorrelationDep {
            I: _buf.read_i32::<LittleEndian>()?,
            Q: _buf.read_i32::<LittleEndian>()?,
        })
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<TrackingChannelCorrelationDep>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TrackingChannelCorrelationDep::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TrackingChannelCorrelationDep>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TrackingChannelCorrelationDep::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for TrackingChannelCorrelationDep {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.I.append_to_sbp_buffer(buf);
        self.Q.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.I.sbp_size();
        size += self.Q.sbp_size();
        size
    }
}

/// Signal tracking channel state
///
/// Tracking channel state for a specific satellite signal and
/// measured signal power.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct TrackingChannelState {
    /// GNSS signal being tracked
    pub sid: GnssSignal,
    /// Frequency channel number (GLONASS only)
    pub fcn: u8,
    /// Carrier-to-Noise density.  Zero implies invalid cn0.
    pub cn0: u8,
}

impl TrackingChannelState {
    pub fn parse(_buf: &mut &[u8]) -> Result<TrackingChannelState, crate::Error> {
        Ok(TrackingChannelState {
            sid: GnssSignal::parse(_buf)?,
            fcn: _buf.read_u8()?,
            cn0: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<TrackingChannelState>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TrackingChannelState::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TrackingChannelState>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TrackingChannelState::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for TrackingChannelState {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sid.append_to_sbp_buffer(buf);
        self.fcn.append_to_sbp_buffer(buf);
        self.cn0.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sid.sbp_size();
        size += self.fcn.sbp_size();
        size += self.cn0.sbp_size();
        size
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct TrackingChannelStateDepA {
    /// Status of tracking channel
    pub state: u8,
    /// PRN-1 being tracked
    pub prn: u8,
    /// Carrier-to-noise density
    pub cn0: f32,
}

impl TrackingChannelStateDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<TrackingChannelStateDepA, crate::Error> {
        Ok(TrackingChannelStateDepA {
            state: _buf.read_u8()?,
            prn: _buf.read_u8()?,
            cn0: _buf.read_f32::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<TrackingChannelStateDepA>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TrackingChannelStateDepA::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TrackingChannelStateDepA>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TrackingChannelStateDepA::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for TrackingChannelStateDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.state.append_to_sbp_buffer(buf);
        self.prn.append_to_sbp_buffer(buf);
        self.cn0.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.state.sbp_size();
        size += self.prn.sbp_size();
        size += self.cn0.sbp_size();
        size
    }
}

/// Deprecated.
///
/// Deprecated.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct TrackingChannelStateDepB {
    /// Status of tracking channel
    pub state: u8,
    /// GNSS signal being tracked
    pub sid: GnssSignalDep,
    /// Carrier-to-noise density
    pub cn0: f32,
}

impl TrackingChannelStateDepB {
    pub fn parse(_buf: &mut &[u8]) -> Result<TrackingChannelStateDepB, crate::Error> {
        Ok(TrackingChannelStateDepB {
            state: _buf.read_u8()?,
            sid: GnssSignalDep::parse(_buf)?,
            cn0: _buf.read_f32::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<TrackingChannelStateDepB>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TrackingChannelStateDepB::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TrackingChannelStateDepB>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TrackingChannelStateDepB::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for TrackingChannelStateDepB {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.state.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.cn0.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.state.sbp_size();
        size += self.sid.sbp_size();
        size += self.cn0.sbp_size();
        size
    }
}
