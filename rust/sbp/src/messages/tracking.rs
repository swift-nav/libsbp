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
// Satellite code and carrier-phase tracking messages from the device.
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
use super::gnss::*;

// Detailed signal tracking channel states. DEPRECATED.
//
// The tracking message returns a set tracking channel parameters for a
// single tracking channel useful for debugging issues.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingStateDetailedDepA {
    pub sender_id: Option<u16>,
    pub recv_time: u64,
    // ^ Receiver clock time.
    pub tot: GPSTime,
    // ^ Time of transmission of signal from satellite. TOW only valid when TOW
    // status is decoded or propagated. WN only valid when week number valid
    // flag is set.
    pub P: u32,
    // ^ Pseudorange observation. Valid only when pseudorange valid flag is set.
    pub P_std: u16,
    // ^ Pseudorange observation standard deviation. Valid only when pseudorange
    // valid flag is set.
    pub L: CarrierPhase,
    // ^ Carrier phase observation with typical sign convention. Valid only when
    // PLL pessimistic lock is achieved.
    pub cn0: u8,
    // ^ Carrier-to-Noise density
    pub lock: u16,
    // ^ Lock time. It is encoded according to DF402 from the RTCM 10403.2
    // Amendment 2 specification. Valid values range from 0 to 15.
    pub sid: GnssSignal,
    // ^ GNSS signal identifier.
    pub doppler: i32,
    // ^ Carrier Doppler frequency.
    pub doppler_std: u16,
    // ^ Carrier Doppler frequency standard deviation.
    pub uptime: u32,
    // ^ Number of seconds of continuous tracking. Specifies how much time signal
    // is in continuous track.
    pub clock_offset: i16,
    // ^ TCXO clock offset. Valid only when valid clock valid flag is set.
    pub clock_drift: i16,
    // ^ TCXO clock drift. Valid only when valid clock valid flag is set.
    pub corr_spacing: u16,
    // ^ Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
    pub acceleration: i8,
    // ^ Acceleration. Valid only when acceleration valid flag is set.
    pub sync_flags: u8,
    // ^ Synchronization status flags.
    pub tow_flags: u8,
    // ^ TOW status flags.
    pub track_flags: u8,
    // ^ Tracking loop status flags.
    pub nav_flags: u8,
    // ^ Navigation data status flags.
    pub pset_flags: u8,
    // ^ Parameters sets flags.
    pub misc_flags: u8,
    // ^ Miscellaneous flags.
}

impl MsgTrackingStateDetailedDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingStateDetailedDepA, ::parser::MessageError> {
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

// Deprecated
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingStateDetailedDep {
    pub sender_id: Option<u16>,
    pub recv_time: u64,
    // ^ Receiver clock time.
    pub tot: GPSTimeDep,
    // ^ Time of transmission of signal from satellite. TOW only valid when TOW
    // status is decoded or propagated. WN only valid when week number valid
    // flag is set.
    pub P: u32,
    // ^ Pseudorange observation. Valid only when pseudorange valid flag is set.
    pub P_std: u16,
    // ^ Pseudorange observation standard deviation. Valid only when pseudorange
    // valid flag is set.
    pub L: CarrierPhase,
    // ^ Carrier phase observation with typical sign convention. Valid only when
    // PLL pessimistic lock is achieved.
    pub cn0: u8,
    // ^ Carrier-to-Noise density
    pub lock: u16,
    // ^ Lock time. It is encoded according to DF402 from the RTCM 10403.2
    // Amendment 2 specification. Valid values range from 0 to 15.
    pub sid: GnssSignalDep,
    // ^ GNSS signal identifier.
    pub doppler: i32,
    // ^ Carrier Doppler frequency.
    pub doppler_std: u16,
    // ^ Carrier Doppler frequency standard deviation.
    pub uptime: u32,
    // ^ Number of seconds of continuous tracking. Specifies how much time signal
    // is in continuous track.
    pub clock_offset: i16,
    // ^ TCXO clock offset. Valid only when valid clock valid flag is set.
    pub clock_drift: i16,
    // ^ TCXO clock drift. Valid only when valid clock valid flag is set.
    pub corr_spacing: u16,
    // ^ Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
    pub acceleration: i8,
    // ^ Acceleration. Valid only when acceleration valid flag is set.
    pub sync_flags: u8,
    // ^ Synchronization status flags.
    pub tow_flags: u8,
    // ^ TOW status flags.
    pub track_flags: u8,
    // ^ Tracking loop status flags.
    pub nav_flags: u8,
    // ^ Navigation data status flags.
    pub pset_flags: u8,
    // ^ Parameters sets flags.
    pub misc_flags: u8,
    // ^ Miscellaneous flags.
}

impl MsgTrackingStateDetailedDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingStateDetailedDep, ::parser::MessageError> {
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

// Signal tracking channel state
//
// Tracking channel state for a specific satellite signal and
// measured signal power.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct TrackingChannelState {
    pub sid: GnssSignal,
    // ^ GNSS signal being tracked
    pub fcn: u8,
    // ^ Frequency channel number (GLONASS only)
    pub cn0: u8,
    // ^ Carrier-to-Noise density.  Zero implies invalid cn0.
}

impl TrackingChannelState {
    pub fn parse(_buf: &mut &[u8]) -> Result<TrackingChannelState, ::parser::MessageError> {
        Ok(TrackingChannelState {
            sid: GnssSignal::parse(_buf)?,
            fcn: _buf.read_u8()?,
            cn0: _buf.read_u8()?,
        })
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<TrackingChannelState>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TrackingChannelState::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TrackingChannelState>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TrackingChannelState::parse(buf)?);
        }
        Ok(v)
    }
}

// Signal tracking channel states
//
// The tracking message returns a variable-length array of tracking
// channel states. It reports status and carrier-to-noise density
// measurements for all tracked satellites.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingState {
    pub sender_id: Option<u16>,
    pub states: Vec<TrackingChannelState>,
    // ^ Signal tracking channel state
}

impl MsgTrackingState {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingState, ::parser::MessageError> {
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

// Measurement Engine signal tracking channel state
//
// Measurement Engine tracking channel state for a specific satellite signal
// and measured signal power.
// The mesid field for Glonass can either
// carry the FCN as 100 + FCN where FCN is in [-7, +6] or
// the Slot ID (from 1 to 28)
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MeasurementState {
    pub mesid: GnssSignal,
    // ^ Measurement Engine GNSS signal being tracked (carries either Glonass FCN
    // or SLOT)
    pub cn0: u8,
    // ^ Carrier-to-Noise density.  Zero implies invalid cn0.
}

impl MeasurementState {
    pub fn parse(_buf: &mut &[u8]) -> Result<MeasurementState, ::parser::MessageError> {
        Ok(MeasurementState {
            mesid: GnssSignal::parse(_buf)?,
            cn0: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<MeasurementState>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(MeasurementState::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<MeasurementState>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(MeasurementState::parse(buf)?);
        }
        Ok(v)
    }
}

// Measurement Engine signal tracking channel states
//
// The tracking message returns a variable-length array of tracking
// channel states. It reports status and carrier-to-noise density
// measurements for all tracked satellites.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgMeasurementState {
    pub sender_id: Option<u16>,
    pub states: Vec<MeasurementState>,
    // ^ ME signal tracking channel state
}

impl MsgMeasurementState {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgMeasurementState, ::parser::MessageError> {
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

// Complex correlation structure
//
// Structure containing in-phase and quadrature correlation components.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct TrackingChannelCorrelation {
    pub I: i16,
    // ^ In-phase correlation
    pub Q: i16,
    // ^ Quadrature correlation
}

impl TrackingChannelCorrelation {
    pub fn parse(_buf: &mut &[u8]) -> Result<TrackingChannelCorrelation, ::parser::MessageError> {
        Ok(TrackingChannelCorrelation {
            I: _buf.read_i16::<LittleEndian>()?,
            Q: _buf.read_i16::<LittleEndian>()?,
        })
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<TrackingChannelCorrelation>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TrackingChannelCorrelation::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TrackingChannelCorrelation>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TrackingChannelCorrelation::parse(buf)?);
        }
        Ok(v)
    }
}

// Tracking channel correlations
//
// When enabled, a tracking channel can output the correlations at each
// update interval.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingIq {
    pub sender_id: Option<u16>,
    pub channel: u8,
    // ^ Tracking channel of origin
    pub sid: GnssSignal,
    // ^ GNSS signal identifier
    pub corrs: Vec<TrackingChannelCorrelation>,
    // ^ Early, Prompt and Late correlations
}

impl MsgTrackingIq {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingIq, ::parser::MessageError> {
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

// Complex correlation structure
//
// Structure containing in-phase and quadrature correlation components.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct TrackingChannelCorrelationDep {
    pub I: i32,
    // ^ In-phase correlation
    pub Q: i32,
    // ^ Quadrature correlation
}

impl TrackingChannelCorrelationDep {
    pub fn parse(
        _buf: &mut &[u8],
    ) -> Result<TrackingChannelCorrelationDep, ::parser::MessageError> {
        Ok(TrackingChannelCorrelationDep {
            I: _buf.read_i32::<LittleEndian>()?,
            Q: _buf.read_i32::<LittleEndian>()?,
        })
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<TrackingChannelCorrelationDep>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TrackingChannelCorrelationDep::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TrackingChannelCorrelationDep>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TrackingChannelCorrelationDep::parse(buf)?);
        }
        Ok(v)
    }
}

// Tracking channel correlations
//
// When enabled, a tracking channel can output the correlations at each
// update interval.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingIqDepB {
    pub sender_id: Option<u16>,
    pub channel: u8,
    // ^ Tracking channel of origin
    pub sid: GnssSignal,
    // ^ GNSS signal identifier
    pub corrs: Vec<TrackingChannelCorrelationDep>,
    // ^ Early, Prompt and Late correlations
}

impl MsgTrackingIqDepB {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingIqDepB, ::parser::MessageError> {
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

// Deprecated
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingIqDepA {
    pub sender_id: Option<u16>,
    pub channel: u8,
    // ^ Tracking channel of origin
    pub sid: GnssSignalDep,
    // ^ GNSS signal identifier
    pub corrs: Vec<TrackingChannelCorrelationDep>,
    // ^ Early, Prompt and Late correlations
}

impl MsgTrackingIqDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingIqDepA, ::parser::MessageError> {
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

// Deprecated
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct TrackingChannelStateDepA {
    pub state: u8,
    // ^ Status of tracking channel
    pub prn: u8,
    // ^ PRN-1 being tracked
    pub cn0: f32,
    // ^ Carrier-to-noise density
}

impl TrackingChannelStateDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<TrackingChannelStateDepA, ::parser::MessageError> {
        Ok(TrackingChannelStateDepA {
            state: _buf.read_u8()?,
            prn: _buf.read_u8()?,
            cn0: _buf.read_f32::<LittleEndian>()?,
        })
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<TrackingChannelStateDepA>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TrackingChannelStateDepA::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TrackingChannelStateDepA>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TrackingChannelStateDepA::parse(buf)?);
        }
        Ok(v)
    }
}

// Deprecated
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingStateDepA {
    pub sender_id: Option<u16>,
    pub states: Vec<TrackingChannelStateDepA>,
    // ^ Satellite tracking channel state
}

impl MsgTrackingStateDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingStateDepA, ::parser::MessageError> {
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

// Deprecated.
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct TrackingChannelStateDepB {
    pub state: u8,
    // ^ Status of tracking channel
    pub sid: GnssSignalDep,
    // ^ GNSS signal being tracked
    pub cn0: f32,
    // ^ Carrier-to-noise density
}

impl TrackingChannelStateDepB {
    pub fn parse(_buf: &mut &[u8]) -> Result<TrackingChannelStateDepB, ::parser::MessageError> {
        Ok(TrackingChannelStateDepB {
            state: _buf.read_u8()?,
            sid: GnssSignalDep::parse(_buf)?,
            cn0: _buf.read_f32::<LittleEndian>()?,
        })
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<TrackingChannelStateDepB>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TrackingChannelStateDepB::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TrackingChannelStateDepB>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TrackingChannelStateDepB::parse(buf)?);
        }
        Ok(v)
    }
}

// Deprecated.
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgTrackingStateDepB {
    pub sender_id: Option<u16>,
    pub states: Vec<TrackingChannelStateDepB>,
    // ^ Signal tracking channel state
}

impl MsgTrackingStateDepB {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgTrackingStateDepB, ::parser::MessageError> {
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
