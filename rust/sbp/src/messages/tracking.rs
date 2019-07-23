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

/// Detailed signal tracking channel states. DEPRECATED.
///
/// The tracking message returns a set tracking channel parameters for a
/// single tracking channel useful for debugging issues.
///
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingStateDetailedDepA, ::Error> {
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
    const MSG_ID: u16 = 33;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Deprecated
///
/// Deprecated.
///
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingStateDetailedDep, ::Error> {
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
    const MSG_ID: u16 = 17;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Signal tracking channel state
///
/// Tracking channel state for a specific satellite signal and
/// measured signal power.
///
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
    pub fn parse(_buf: &mut &[u8]) -> Result<TrackingChannelState, ::Error> {
        Ok(TrackingChannelState {
            sid: GnssSignal::parse(_buf)?,
            fcn: _buf.read_u8()?,
            cn0: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<TrackingChannelState>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TrackingChannelState::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TrackingChannelState>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TrackingChannelState::parse(buf)?);
        }
        Ok(v)
    }
}

/// Signal tracking channel states
///
/// The tracking message returns a variable-length array of tracking
/// channel states. It reports status and carrier-to-noise density
/// measurements for all tracked satellites.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingState {
    pub sender_id: Option<u16>,
    /// Signal tracking channel state
    pub states: Vec<TrackingChannelState>,
}

impl MsgTrackingState {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingState, ::Error> {
        Ok(MsgTrackingState {
            sender_id: None,
            states: TrackingChannelState::parse_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgTrackingState {
    const MSG_ID: u16 = 65;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MeasurementState, ::Error> {
        Ok(MeasurementState {
            mesid: GnssSignal::parse(_buf)?,
            cn0: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<MeasurementState>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(MeasurementState::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<MeasurementState>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(MeasurementState::parse(buf)?);
        }
        Ok(v)
    }
}

/// Measurement Engine signal tracking channel states
///
/// The tracking message returns a variable-length array of tracking
/// channel states. It reports status and carrier-to-noise density
/// measurements for all tracked satellites.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgMeasurementState {
    pub sender_id: Option<u16>,
    /// ME signal tracking channel state
    pub states: Vec<MeasurementState>,
}

impl MsgMeasurementState {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgMeasurementState, ::Error> {
        Ok(MsgMeasurementState {
            sender_id: None,
            states: MeasurementState::parse_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgMeasurementState {
    const MSG_ID: u16 = 97;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Complex correlation structure
///
/// Structure containing in-phase and quadrature correlation components.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct TrackingChannelCorrelation {
    /// In-phase correlation
    pub I: i16,
    /// Quadrature correlation
    pub Q: i16,
}

impl TrackingChannelCorrelation {
    pub fn parse(_buf: &mut &[u8]) -> Result<TrackingChannelCorrelation, ::Error> {
        Ok(TrackingChannelCorrelation {
            I: _buf.read_i16::<LittleEndian>()?,
            Q: _buf.read_i16::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<TrackingChannelCorrelation>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TrackingChannelCorrelation::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TrackingChannelCorrelation>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TrackingChannelCorrelation::parse(buf)?);
        }
        Ok(v)
    }
}

/// Tracking channel correlations
///
/// When enabled, a tracking channel can output the correlations at each
/// update interval.
///
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingIq, ::Error> {
        Ok(MsgTrackingIq {
            sender_id: None,
            channel: _buf.read_u8()?,
            sid: GnssSignal::parse(_buf)?,
            corrs: TrackingChannelCorrelation::parse_array_limit(_buf, 3)?,
        })
    }
}
impl super::SBPMessage for MsgTrackingIq {
    const MSG_ID: u16 = 45;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Complex correlation structure
///
/// Structure containing in-phase and quadrature correlation components.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct TrackingChannelCorrelationDep {
    /// In-phase correlation
    pub I: i32,
    /// Quadrature correlation
    pub Q: i32,
}

impl TrackingChannelCorrelationDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<TrackingChannelCorrelationDep, ::Error> {
        Ok(TrackingChannelCorrelationDep {
            I: _buf.read_i32::<LittleEndian>()?,
            Q: _buf.read_i32::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<TrackingChannelCorrelationDep>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TrackingChannelCorrelationDep::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TrackingChannelCorrelationDep>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TrackingChannelCorrelationDep::parse(buf)?);
        }
        Ok(v)
    }
}

/// Tracking channel correlations
///
/// When enabled, a tracking channel can output the correlations at each
/// update interval.
///
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingIqDepB, ::Error> {
        Ok(MsgTrackingIqDepB {
            sender_id: None,
            channel: _buf.read_u8()?,
            sid: GnssSignal::parse(_buf)?,
            corrs: TrackingChannelCorrelationDep::parse_array_limit(_buf, 3)?,
        })
    }
}
impl super::SBPMessage for MsgTrackingIqDepB {
    const MSG_ID: u16 = 44;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Deprecated
///
/// Deprecated.
///
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingIqDepA, ::Error> {
        Ok(MsgTrackingIqDepA {
            sender_id: None,
            channel: _buf.read_u8()?,
            sid: GnssSignalDep::parse(_buf)?,
            corrs: TrackingChannelCorrelationDep::parse_array_limit(_buf, 3)?,
        })
    }
}
impl super::SBPMessage for MsgTrackingIqDepA {
    const MSG_ID: u16 = 28;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Deprecated
///
/// Deprecated.
///
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
    pub fn parse(_buf: &mut &[u8]) -> Result<TrackingChannelStateDepA, ::Error> {
        Ok(TrackingChannelStateDepA {
            state: _buf.read_u8()?,
            prn: _buf.read_u8()?,
            cn0: _buf.read_f32::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<TrackingChannelStateDepA>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TrackingChannelStateDepA::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TrackingChannelStateDepA>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TrackingChannelStateDepA::parse(buf)?);
        }
        Ok(v)
    }
}

/// Deprecated
///
/// Deprecated.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingStateDepA {
    pub sender_id: Option<u16>,
    /// Satellite tracking channel state
    pub states: Vec<TrackingChannelStateDepA>,
}

impl MsgTrackingStateDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingStateDepA, ::Error> {
        Ok(MsgTrackingStateDepA {
            sender_id: None,
            states: TrackingChannelStateDepA::parse_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgTrackingStateDepA {
    const MSG_ID: u16 = 22;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Deprecated.
///
/// Deprecated.
///
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
    pub fn parse(_buf: &mut &[u8]) -> Result<TrackingChannelStateDepB, ::Error> {
        Ok(TrackingChannelStateDepB {
            state: _buf.read_u8()?,
            sid: GnssSignalDep::parse(_buf)?,
            cn0: _buf.read_f32::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<TrackingChannelStateDepB>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TrackingChannelStateDepB::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TrackingChannelStateDepB>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TrackingChannelStateDepB::parse(buf)?);
        }
        Ok(v)
    }
}

/// Deprecated.
///
/// Deprecated.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingStateDepB {
    pub sender_id: Option<u16>,
    /// Signal tracking channel state
    pub states: Vec<TrackingChannelStateDepB>,
}

impl MsgTrackingStateDepB {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingStateDepB, ::Error> {
        Ok(MsgTrackingStateDepB {
            sender_id: None,
            states: TrackingChannelStateDepB::parse_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgTrackingStateDepB {
    const MSG_ID: u16 = 19;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}
