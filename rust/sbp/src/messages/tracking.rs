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
// Automatically generated from yaml/swiftnav/sbp/tracking.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Satellite code and carrier-phase tracking messages from the device.
//!

#[cfg(feature = "sbp_serde")]
use serde::{Deserialize, Serialize};

use super::gnss::*;
#[allow(unused_imports)]
use crate::{parser::SbpParse, BoundedSbpString, UnboundedSbpString};

/// Measurement Engine signal tracking channel states
///
/// The tracking message returns a variable-length array of tracking
/// channel states. It reports status and carrier-to-noise density
/// measurements for all tracked satellites.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgMeasurementState {
    pub sender_id: Option<u16>,
    /// ME signal tracking channel state
    pub states: Vec<MeasurementState>,
}

impl SbpParse<MsgMeasurementState> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgMeasurementState> {
        Ok( MsgMeasurementState{
            sender_id: None,
            states: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgTrackingIq {
    pub sender_id: Option<u16>,
    /// Tracking channel of origin
    pub channel: u8,
    /// GNSS signal identifier
    pub sid: GnssSignal,
    /// Early, Prompt and Late correlations
    pub corrs: [TrackingChannelCorrelation; 3],
}

impl SbpParse<MsgTrackingIq> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgTrackingIq> {
        Ok( MsgTrackingIq{
            sender_id: None,
            channel: self.parse()?,
            sid: self.parse()?,
            corrs: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgTrackingIqDepA {
    pub sender_id: Option<u16>,
    /// Tracking channel of origin
    pub channel: u8,
    /// GNSS signal identifier
    pub sid: GnssSignalDep,
    /// Early, Prompt and Late correlations
    pub corrs: [TrackingChannelCorrelationDep; 3],
}

impl SbpParse<MsgTrackingIqDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgTrackingIqDepA> {
        Ok( MsgTrackingIqDepA{
            sender_id: None,
            channel: self.parse()?,
            sid: self.parse()?,
            corrs: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgTrackingIqDepB {
    pub sender_id: Option<u16>,
    /// Tracking channel of origin
    pub channel: u8,
    /// GNSS signal identifier
    pub sid: GnssSignal,
    /// Early, Prompt and Late correlations
    pub corrs: [TrackingChannelCorrelationDep; 3],
}

impl SbpParse<MsgTrackingIqDepB> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgTrackingIqDepB> {
        Ok( MsgTrackingIqDepB{
            sender_id: None,
            channel: self.parse()?,
            sid: self.parse()?,
            corrs: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgTrackingState {
    pub sender_id: Option<u16>,
    /// Signal tracking channel state
    pub states: Vec<TrackingChannelState>,
}

impl SbpParse<MsgTrackingState> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgTrackingState> {
        Ok( MsgTrackingState{
            sender_id: None,
            states: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgTrackingStateDepA {
    pub sender_id: Option<u16>,
    /// Satellite tracking channel state
    pub states: Vec<TrackingChannelStateDepA>,
}

impl SbpParse<MsgTrackingStateDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgTrackingStateDepA> {
        Ok( MsgTrackingStateDepA{
            sender_id: None,
            states: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgTrackingStateDepB {
    pub sender_id: Option<u16>,
    /// Signal tracking channel state
    pub states: Vec<TrackingChannelStateDepB>,
}

impl SbpParse<MsgTrackingStateDepB> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgTrackingStateDepB> {
        Ok( MsgTrackingStateDepB{
            sender_id: None,
            states: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
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

impl SbpParse<MsgTrackingStateDetailedDep> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgTrackingStateDetailedDep> {
        Ok( MsgTrackingStateDetailedDep{
            sender_id: None,
            recv_time: self.parse()?,
            tot: self.parse()?,
            P: self.parse()?,
            P_std: self.parse()?,
            L: self.parse()?,
            cn0: self.parse()?,
            lock: self.parse()?,
            sid: self.parse()?,
            doppler: self.parse()?,
            doppler_std: self.parse()?,
            uptime: self.parse()?,
            clock_offset: self.parse()?,
            clock_drift: self.parse()?,
            corr_spacing: self.parse()?,
            acceleration: self.parse()?,
            sync_flags: self.parse()?,
            tow_flags: self.parse()?,
            track_flags: self.parse()?,
            nav_flags: self.parse()?,
            pset_flags: self.parse()?,
            misc_flags: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
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

impl SbpParse<MsgTrackingStateDetailedDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgTrackingStateDetailedDepA> {
        Ok( MsgTrackingStateDetailedDepA{
            sender_id: None,
            recv_time: self.parse()?,
            tot: self.parse()?,
            P: self.parse()?,
            P_std: self.parse()?,
            L: self.parse()?,
            cn0: self.parse()?,
            lock: self.parse()?,
            sid: self.parse()?,
            doppler: self.parse()?,
            doppler_std: self.parse()?,
            uptime: self.parse()?,
            clock_offset: self.parse()?,
            clock_drift: self.parse()?,
            corr_spacing: self.parse()?,
            acceleration: self.parse()?,
            sync_flags: self.parse()?,
            tow_flags: self.parse()?,
            track_flags: self.parse()?,
            nav_flags: self.parse()?,
            pset_flags: self.parse()?,
            misc_flags: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MeasurementState {
    /// Measurement Engine GNSS signal being tracked (carries either Glonass FCN
    /// or SLOT)
    pub mesid: GnssSignal,
    /// Carrier-to-Noise density.  Zero implies invalid cn0.
    pub cn0: u8,
}

impl SbpParse<MeasurementState> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MeasurementState> {
        Ok( MeasurementState{
            mesid: self.parse()?,
            cn0: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct TrackingChannelCorrelation {
    /// In-phase correlation
    pub I: i16,
    /// Quadrature correlation
    pub Q: i16,
}

impl SbpParse<TrackingChannelCorrelation> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<TrackingChannelCorrelation> {
        Ok( TrackingChannelCorrelation{
            I: self.parse()?,
            Q: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct TrackingChannelCorrelationDep {
    /// In-phase correlation
    pub I: i32,
    /// Quadrature correlation
    pub Q: i32,
}

impl SbpParse<TrackingChannelCorrelationDep> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<TrackingChannelCorrelationDep> {
        Ok( TrackingChannelCorrelationDep{
            I: self.parse()?,
            Q: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct TrackingChannelState {
    /// GNSS signal being tracked
    pub sid: GnssSignal,
    /// Frequency channel number (GLONASS only)
    pub fcn: u8,
    /// Carrier-to-Noise density.  Zero implies invalid cn0.
    pub cn0: u8,
}

impl SbpParse<TrackingChannelState> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<TrackingChannelState> {
        Ok( TrackingChannelState{
            sid: self.parse()?,
            fcn: self.parse()?,
            cn0: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct TrackingChannelStateDepA {
    /// Status of tracking channel
    pub state: u8,
    /// PRN-1 being tracked
    pub prn: u8,
    /// Carrier-to-noise density
    pub cn0: f32,
}

impl SbpParse<TrackingChannelStateDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<TrackingChannelStateDepA> {
        Ok( TrackingChannelStateDepA{
            state: self.parse()?,
            prn: self.parse()?,
            cn0: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct TrackingChannelStateDepB {
    /// Status of tracking channel
    pub state: u8,
    /// GNSS signal being tracked
    pub sid: GnssSignalDep,
    /// Carrier-to-noise density
    pub cn0: f32,
}

impl SbpParse<TrackingChannelStateDepB> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<TrackingChannelStateDepB> {
        Ok( TrackingChannelStateDepB{
            state: self.parse()?,
            sid: self.parse()?,
            cn0: self.parse()?,
        } )
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
