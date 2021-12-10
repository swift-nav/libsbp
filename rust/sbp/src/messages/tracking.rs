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
// Automatically generated from yaml/swiftnav/sbp/tracking.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Satellite code and carrier-phase tracking messages from the device.

use super::gnss::*;

use super::lib::*;

/// Measurement Engine signal tracking channel states
///
/// The tracking message returns a variable-length array of tracking channel
/// states. It reports status and carrier-to-noise density measurements for
/// all tracked satellites.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgMeasurementState {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// ME signal tracking channel state
    #[cfg_attr(feature = "serde", serde(rename(serialize = "states")))]
    pub states: Vec<MeasurementState>,
}

impl ConcreteMessage for MsgMeasurementState {
    const MESSAGE_TYPE: u16 = 97;
    const MESSAGE_NAME: &'static str = "MSG_MEASUREMENT_STATE";
}

impl SbpMessage for MsgMeasurementState {
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
}

impl TryFrom<Sbp> for MsgMeasurementState {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgMeasurementState(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgMeasurementState {
    const MIN_LEN: usize = <Vec<MeasurementState> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.states)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.states, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgMeasurementState {
            sender_id: None,
            states: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Tracking channel correlations
///
/// When enabled, a tracking channel can output the correlations at each
/// update interval.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgTrackingIq {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Tracking channel of origin
    #[cfg_attr(feature = "serde", serde(rename(serialize = "channel")))]
    pub channel: u8,
    /// GNSS signal identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// Early, Prompt and Late correlations
    #[cfg_attr(feature = "serde", serde(rename(serialize = "corrs")))]
    pub corrs: [TrackingChannelCorrelation; 3],
}

impl ConcreteMessage for MsgTrackingIq {
    const MESSAGE_TYPE: u16 = 45;
    const MESSAGE_NAME: &'static str = "MSG_TRACKING_IQ";
}

impl SbpMessage for MsgTrackingIq {
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
}

impl TryFrom<Sbp> for MsgTrackingIq {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgTrackingIq(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgTrackingIq {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <GnssSignal as WireFormat>::MIN_LEN
        + <[TrackingChannelCorrelation; 3] as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.channel) + WireFormat::len(&self.sid) + WireFormat::len(&self.corrs)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.channel, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.corrs, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgTrackingIq {
            sender_id: None,
            channel: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            corrs: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgTrackingIqDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Tracking channel of origin
    #[cfg_attr(feature = "serde", serde(rename(serialize = "channel")))]
    pub channel: u8,
    /// GNSS signal identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignalDep,
    /// Early, Prompt and Late correlations
    #[cfg_attr(feature = "serde", serde(rename(serialize = "corrs")))]
    pub corrs: [TrackingChannelCorrelationDep; 3],
}

impl ConcreteMessage for MsgTrackingIqDepA {
    const MESSAGE_TYPE: u16 = 28;
    const MESSAGE_NAME: &'static str = "MSG_TRACKING_IQ_DEP_A";
}

impl SbpMessage for MsgTrackingIqDepA {
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
}

impl TryFrom<Sbp> for MsgTrackingIqDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgTrackingIqDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgTrackingIqDepA {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <GnssSignalDep as WireFormat>::MIN_LEN
        + <[TrackingChannelCorrelationDep; 3] as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.channel) + WireFormat::len(&self.sid) + WireFormat::len(&self.corrs)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.channel, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.corrs, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgTrackingIqDepA {
            sender_id: None,
            channel: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            corrs: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Tracking channel correlations
///
/// When enabled, a tracking channel can output the correlations at each
/// update interval.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgTrackingIqDepB {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Tracking channel of origin
    #[cfg_attr(feature = "serde", serde(rename(serialize = "channel")))]
    pub channel: u8,
    /// GNSS signal identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// Early, Prompt and Late correlations
    #[cfg_attr(feature = "serde", serde(rename(serialize = "corrs")))]
    pub corrs: [TrackingChannelCorrelationDep; 3],
}

impl ConcreteMessage for MsgTrackingIqDepB {
    const MESSAGE_TYPE: u16 = 44;
    const MESSAGE_NAME: &'static str = "MSG_TRACKING_IQ_DEP_B";
}

impl SbpMessage for MsgTrackingIqDepB {
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
}

impl TryFrom<Sbp> for MsgTrackingIqDepB {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgTrackingIqDepB(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgTrackingIqDepB {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <GnssSignal as WireFormat>::MIN_LEN
        + <[TrackingChannelCorrelationDep; 3] as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.channel) + WireFormat::len(&self.sid) + WireFormat::len(&self.corrs)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.channel, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.corrs, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgTrackingIqDepB {
            sender_id: None,
            channel: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            corrs: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Signal tracking channel states
///
/// The tracking message returns a variable-length array of tracking channel
/// states. It reports status and carrier-to-noise density measurements for
/// all tracked satellites.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgTrackingState {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Signal tracking channel state
    #[cfg_attr(feature = "serde", serde(rename(serialize = "states")))]
    pub states: Vec<TrackingChannelState>,
}

impl ConcreteMessage for MsgTrackingState {
    const MESSAGE_TYPE: u16 = 65;
    const MESSAGE_NAME: &'static str = "MSG_TRACKING_STATE";
}

impl SbpMessage for MsgTrackingState {
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
}

impl TryFrom<Sbp> for MsgTrackingState {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgTrackingState(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgTrackingState {
    const MIN_LEN: usize = <Vec<TrackingChannelState> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.states)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.states, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgTrackingState {
            sender_id: None,
            states: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgTrackingStateDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Satellite tracking channel state
    #[cfg_attr(feature = "serde", serde(rename(serialize = "states")))]
    pub states: Vec<TrackingChannelStateDepA>,
}

impl ConcreteMessage for MsgTrackingStateDepA {
    const MESSAGE_TYPE: u16 = 22;
    const MESSAGE_NAME: &'static str = "MSG_TRACKING_STATE_DEP_A";
}

impl SbpMessage for MsgTrackingStateDepA {
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
}

impl TryFrom<Sbp> for MsgTrackingStateDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgTrackingStateDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgTrackingStateDepA {
    const MIN_LEN: usize = <Vec<TrackingChannelStateDepA> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.states)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.states, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgTrackingStateDepA {
            sender_id: None,
            states: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgTrackingStateDepB {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Signal tracking channel state
    #[cfg_attr(feature = "serde", serde(rename(serialize = "states")))]
    pub states: Vec<TrackingChannelStateDepB>,
}

impl ConcreteMessage for MsgTrackingStateDepB {
    const MESSAGE_TYPE: u16 = 19;
    const MESSAGE_NAME: &'static str = "MSG_TRACKING_STATE_DEP_B";
}

impl SbpMessage for MsgTrackingStateDepB {
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
}

impl TryFrom<Sbp> for MsgTrackingStateDepB {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgTrackingStateDepB(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgTrackingStateDepB {
    const MIN_LEN: usize = <Vec<TrackingChannelStateDepB> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.states)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.states, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgTrackingStateDepB {
            sender_id: None,
            states: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgTrackingStateDetailedDep {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Receiver clock time.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "recv_time")))]
    pub recv_time: u64,
    /// Time of transmission of signal from satellite. TOW only valid when TOW
    /// status is decoded or propagated. WN only valid when week number valid
    /// flag is set.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tot")))]
    pub tot: GpsTimeDep,
    /// Pseudorange observation. Valid only when pseudorange valid flag is set.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "P")))]
    pub p: u32,
    /// Pseudorange observation standard deviation. Valid only when pseudorange
    /// valid flag is set.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "P_std")))]
    pub p_std: u16,
    /// Carrier phase observation with typical sign convention. Valid only when
    /// PLL pessimistic lock is achieved.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "L")))]
    pub l: CarrierPhase,
    /// Carrier-to-Noise density
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cn0")))]
    pub cn0: u8,
    /// Lock time. It is encoded according to DF402 from the RTCM 10403.2
    /// Amendment 2 specification. Valid values range from 0 to 15.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lock")))]
    pub lock: u16,
    /// GNSS signal identifier.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignalDep,
    /// Carrier Doppler frequency.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "doppler")))]
    pub doppler: i32,
    /// Carrier Doppler frequency standard deviation.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "doppler_std")))]
    pub doppler_std: u16,
    /// Number of seconds of continuous tracking. Specifies how much time signal
    /// is in continuous track.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "uptime")))]
    pub uptime: u32,
    /// TCXO clock offset. Valid only when valid clock valid flag is set.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "clock_offset")))]
    pub clock_offset: i16,
    /// TCXO clock drift. Valid only when valid clock valid flag is set.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "clock_drift")))]
    pub clock_drift: i16,
    /// Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "corr_spacing")))]
    pub corr_spacing: u16,
    /// Acceleration. Valid only when acceleration valid flag is set.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "acceleration")))]
    pub acceleration: i8,
    /// Synchronization status flags.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sync_flags")))]
    pub sync_flags: u8,
    /// TOW status flags.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow_flags")))]
    pub tow_flags: u8,
    /// Tracking loop status flags.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "track_flags")))]
    pub track_flags: u8,
    /// Navigation data status flags.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "nav_flags")))]
    pub nav_flags: u8,
    /// Parameters sets flags.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pset_flags")))]
    pub pset_flags: u8,
    /// Miscellaneous flags.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "misc_flags")))]
    pub misc_flags: u8,
}

impl ConcreteMessage for MsgTrackingStateDetailedDep {
    const MESSAGE_TYPE: u16 = 17;
    const MESSAGE_NAME: &'static str = "MSG_TRACKING_STATE_DETAILED_DEP";
}

impl SbpMessage for MsgTrackingStateDetailedDep {
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
}

impl TryFrom<Sbp> for MsgTrackingStateDetailedDep {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgTrackingStateDetailedDep(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgTrackingStateDetailedDep {
    const MIN_LEN: usize = <u64 as WireFormat>::MIN_LEN
        + <GpsTimeDep as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <CarrierPhase as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <GnssSignalDep as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <i8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.recv_time)
            + WireFormat::len(&self.tot)
            + WireFormat::len(&self.p)
            + WireFormat::len(&self.p_std)
            + WireFormat::len(&self.l)
            + WireFormat::len(&self.cn0)
            + WireFormat::len(&self.lock)
            + WireFormat::len(&self.sid)
            + WireFormat::len(&self.doppler)
            + WireFormat::len(&self.doppler_std)
            + WireFormat::len(&self.uptime)
            + WireFormat::len(&self.clock_offset)
            + WireFormat::len(&self.clock_drift)
            + WireFormat::len(&self.corr_spacing)
            + WireFormat::len(&self.acceleration)
            + WireFormat::len(&self.sync_flags)
            + WireFormat::len(&self.tow_flags)
            + WireFormat::len(&self.track_flags)
            + WireFormat::len(&self.nav_flags)
            + WireFormat::len(&self.pset_flags)
            + WireFormat::len(&self.misc_flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.recv_time, buf);
        WireFormat::write(&self.tot, buf);
        WireFormat::write(&self.p, buf);
        WireFormat::write(&self.p_std, buf);
        WireFormat::write(&self.l, buf);
        WireFormat::write(&self.cn0, buf);
        WireFormat::write(&self.lock, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.doppler, buf);
        WireFormat::write(&self.doppler_std, buf);
        WireFormat::write(&self.uptime, buf);
        WireFormat::write(&self.clock_offset, buf);
        WireFormat::write(&self.clock_drift, buf);
        WireFormat::write(&self.corr_spacing, buf);
        WireFormat::write(&self.acceleration, buf);
        WireFormat::write(&self.sync_flags, buf);
        WireFormat::write(&self.tow_flags, buf);
        WireFormat::write(&self.track_flags, buf);
        WireFormat::write(&self.nav_flags, buf);
        WireFormat::write(&self.pset_flags, buf);
        WireFormat::write(&self.misc_flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgTrackingStateDetailedDep {
            sender_id: None,
            recv_time: WireFormat::parse_unchecked(buf),
            tot: WireFormat::parse_unchecked(buf),
            p: WireFormat::parse_unchecked(buf),
            p_std: WireFormat::parse_unchecked(buf),
            l: WireFormat::parse_unchecked(buf),
            cn0: WireFormat::parse_unchecked(buf),
            lock: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            doppler: WireFormat::parse_unchecked(buf),
            doppler_std: WireFormat::parse_unchecked(buf),
            uptime: WireFormat::parse_unchecked(buf),
            clock_offset: WireFormat::parse_unchecked(buf),
            clock_drift: WireFormat::parse_unchecked(buf),
            corr_spacing: WireFormat::parse_unchecked(buf),
            acceleration: WireFormat::parse_unchecked(buf),
            sync_flags: WireFormat::parse_unchecked(buf),
            tow_flags: WireFormat::parse_unchecked(buf),
            track_flags: WireFormat::parse_unchecked(buf),
            nav_flags: WireFormat::parse_unchecked(buf),
            pset_flags: WireFormat::parse_unchecked(buf),
            misc_flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Detailed signal tracking channel states. DEPRECATED
///
/// The tracking message returns a set tracking channel parameters for a
/// single tracking channel useful for debugging issues.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgTrackingStateDetailedDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Receiver clock time.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "recv_time")))]
    pub recv_time: u64,
    /// Time of transmission of signal from satellite. TOW only valid when TOW
    /// status is decoded or propagated. WN only valid when week number valid
    /// flag is set.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tot")))]
    pub tot: GpsTime,
    /// Pseudorange observation. Valid only when pseudorange valid flag is set.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "P")))]
    pub p: u32,
    /// Pseudorange observation standard deviation. Valid only when pseudorange
    /// valid flag is set.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "P_std")))]
    pub p_std: u16,
    /// Carrier phase observation with typical sign convention. Valid only when
    /// PLL pessimistic lock is achieved.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "L")))]
    pub l: CarrierPhase,
    /// Carrier-to-Noise density
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cn0")))]
    pub cn0: u8,
    /// Lock time. It is encoded according to DF402 from the RTCM 10403.2
    /// Amendment 2 specification. Valid values range from 0 to 15.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lock")))]
    pub lock: u16,
    /// GNSS signal identifier.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// Carrier Doppler frequency.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "doppler")))]
    pub doppler: i32,
    /// Carrier Doppler frequency standard deviation.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "doppler_std")))]
    pub doppler_std: u16,
    /// Number of seconds of continuous tracking. Specifies how much time signal
    /// is in continuous track.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "uptime")))]
    pub uptime: u32,
    /// TCXO clock offset. Valid only when valid clock valid flag is set.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "clock_offset")))]
    pub clock_offset: i16,
    /// TCXO clock drift. Valid only when valid clock valid flag is set.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "clock_drift")))]
    pub clock_drift: i16,
    /// Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "corr_spacing")))]
    pub corr_spacing: u16,
    /// Acceleration. Valid only when acceleration valid flag is set.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "acceleration")))]
    pub acceleration: i8,
    /// Synchronization status flags.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sync_flags")))]
    pub sync_flags: u8,
    /// TOW status flags.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow_flags")))]
    pub tow_flags: u8,
    /// Tracking loop status flags.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "track_flags")))]
    pub track_flags: u8,
    /// Navigation data status flags.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "nav_flags")))]
    pub nav_flags: u8,
    /// Parameters sets flags.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pset_flags")))]
    pub pset_flags: u8,
    /// Miscellaneous flags.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "misc_flags")))]
    pub misc_flags: u8,
}

impl ConcreteMessage for MsgTrackingStateDetailedDepA {
    const MESSAGE_TYPE: u16 = 33;
    const MESSAGE_NAME: &'static str = "MSG_TRACKING_STATE_DETAILED_DEP_A";
}

impl SbpMessage for MsgTrackingStateDetailedDepA {
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
}

impl TryFrom<Sbp> for MsgTrackingStateDetailedDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgTrackingStateDetailedDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgTrackingStateDetailedDepA {
    const MIN_LEN: usize = <u64 as WireFormat>::MIN_LEN
        + <GpsTime as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <CarrierPhase as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <GnssSignal as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <i8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.recv_time)
            + WireFormat::len(&self.tot)
            + WireFormat::len(&self.p)
            + WireFormat::len(&self.p_std)
            + WireFormat::len(&self.l)
            + WireFormat::len(&self.cn0)
            + WireFormat::len(&self.lock)
            + WireFormat::len(&self.sid)
            + WireFormat::len(&self.doppler)
            + WireFormat::len(&self.doppler_std)
            + WireFormat::len(&self.uptime)
            + WireFormat::len(&self.clock_offset)
            + WireFormat::len(&self.clock_drift)
            + WireFormat::len(&self.corr_spacing)
            + WireFormat::len(&self.acceleration)
            + WireFormat::len(&self.sync_flags)
            + WireFormat::len(&self.tow_flags)
            + WireFormat::len(&self.track_flags)
            + WireFormat::len(&self.nav_flags)
            + WireFormat::len(&self.pset_flags)
            + WireFormat::len(&self.misc_flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.recv_time, buf);
        WireFormat::write(&self.tot, buf);
        WireFormat::write(&self.p, buf);
        WireFormat::write(&self.p_std, buf);
        WireFormat::write(&self.l, buf);
        WireFormat::write(&self.cn0, buf);
        WireFormat::write(&self.lock, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.doppler, buf);
        WireFormat::write(&self.doppler_std, buf);
        WireFormat::write(&self.uptime, buf);
        WireFormat::write(&self.clock_offset, buf);
        WireFormat::write(&self.clock_drift, buf);
        WireFormat::write(&self.corr_spacing, buf);
        WireFormat::write(&self.acceleration, buf);
        WireFormat::write(&self.sync_flags, buf);
        WireFormat::write(&self.tow_flags, buf);
        WireFormat::write(&self.track_flags, buf);
        WireFormat::write(&self.nav_flags, buf);
        WireFormat::write(&self.pset_flags, buf);
        WireFormat::write(&self.misc_flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgTrackingStateDetailedDepA {
            sender_id: None,
            recv_time: WireFormat::parse_unchecked(buf),
            tot: WireFormat::parse_unchecked(buf),
            p: WireFormat::parse_unchecked(buf),
            p_std: WireFormat::parse_unchecked(buf),
            l: WireFormat::parse_unchecked(buf),
            cn0: WireFormat::parse_unchecked(buf),
            lock: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            doppler: WireFormat::parse_unchecked(buf),
            doppler_std: WireFormat::parse_unchecked(buf),
            uptime: WireFormat::parse_unchecked(buf),
            clock_offset: WireFormat::parse_unchecked(buf),
            clock_drift: WireFormat::parse_unchecked(buf),
            corr_spacing: WireFormat::parse_unchecked(buf),
            acceleration: WireFormat::parse_unchecked(buf),
            sync_flags: WireFormat::parse_unchecked(buf),
            tow_flags: WireFormat::parse_unchecked(buf),
            track_flags: WireFormat::parse_unchecked(buf),
            nav_flags: WireFormat::parse_unchecked(buf),
            pset_flags: WireFormat::parse_unchecked(buf),
            misc_flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Measurement Engine signal tracking channel state
///
/// Measurement Engine tracking channel state for a specific satellite signal
/// and measured signal power. The mesid field for Glonass can either carry
/// the FCN as 100 + FCN where FCN is in \[-7, +6\] or the Slot ID (from 1 to
/// 28).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MeasurementState {
    /// Measurement Engine GNSS signal being tracked (carries either Glonass FCN
    /// or SLOT)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "mesid")))]
    pub mesid: GnssSignal,
    /// Carrier-to-Noise density.  Zero implies invalid cn0.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cn0")))]
    pub cn0: u8,
}

impl WireFormat for MeasurementState {
    const MIN_LEN: usize = <GnssSignal as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.mesid) + WireFormat::len(&self.cn0)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.mesid, buf);
        WireFormat::write(&self.cn0, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MeasurementState {
            mesid: WireFormat::parse_unchecked(buf),
            cn0: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Complex correlation structure
///
/// Structure containing in-phase and quadrature correlation components.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct TrackingChannelCorrelation {
    /// In-phase correlation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "I")))]
    pub i: i16,
    /// Quadrature correlation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "Q")))]
    pub q: i16,
}

impl WireFormat for TrackingChannelCorrelation {
    const MIN_LEN: usize = <i16 as WireFormat>::MIN_LEN + <i16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.i) + WireFormat::len(&self.q)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.i, buf);
        WireFormat::write(&self.q, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        TrackingChannelCorrelation {
            i: WireFormat::parse_unchecked(buf),
            q: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Complex correlation structure
///
/// Structure containing in-phase and quadrature correlation components.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct TrackingChannelCorrelationDep {
    /// In-phase correlation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "I")))]
    pub i: i32,
    /// Quadrature correlation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "Q")))]
    pub q: i32,
}

impl WireFormat for TrackingChannelCorrelationDep {
    const MIN_LEN: usize = <i32 as WireFormat>::MIN_LEN + <i32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.i) + WireFormat::len(&self.q)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.i, buf);
        WireFormat::write(&self.q, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        TrackingChannelCorrelationDep {
            i: WireFormat::parse_unchecked(buf),
            q: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Signal tracking channel state
///
/// Tracking channel state for a specific satellite signal and measured signal
/// power.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct TrackingChannelState {
    /// GNSS signal being tracked
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// Frequency channel number (GLONASS only)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "fcn")))]
    pub fcn: u8,
    /// Carrier-to-Noise density.  Zero implies invalid cn0.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cn0")))]
    pub cn0: u8,
}

impl WireFormat for TrackingChannelState {
    const MIN_LEN: usize = <GnssSignal as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sid) + WireFormat::len(&self.fcn) + WireFormat::len(&self.cn0)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.fcn, buf);
        WireFormat::write(&self.cn0, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        TrackingChannelState {
            sid: WireFormat::parse_unchecked(buf),
            fcn: WireFormat::parse_unchecked(buf),
            cn0: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct TrackingChannelStateDepA {
    /// Status of tracking channel
    #[cfg_attr(feature = "serde", serde(rename(serialize = "state")))]
    pub state: u8,
    /// PRN-1 being tracked
    #[cfg_attr(feature = "serde", serde(rename(serialize = "prn")))]
    pub prn: u8,
    /// Carrier-to-noise density
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cn0")))]
    pub cn0: f32,
}

impl WireFormat for TrackingChannelStateDepA {
    const MIN_LEN: usize =
        <u8 as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN + <f32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.state) + WireFormat::len(&self.prn) + WireFormat::len(&self.cn0)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.state, buf);
        WireFormat::write(&self.prn, buf);
        WireFormat::write(&self.cn0, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        TrackingChannelStateDepA {
            state: WireFormat::parse_unchecked(buf),
            prn: WireFormat::parse_unchecked(buf),
            cn0: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct TrackingChannelStateDepB {
    /// Status of tracking channel
    #[cfg_attr(feature = "serde", serde(rename(serialize = "state")))]
    pub state: u8,
    /// GNSS signal being tracked
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignalDep,
    /// Carrier-to-noise density
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cn0")))]
    pub cn0: f32,
}

impl WireFormat for TrackingChannelStateDepB {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <GnssSignalDep as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.state) + WireFormat::len(&self.sid) + WireFormat::len(&self.cn0)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.state, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.cn0, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        TrackingChannelStateDepB {
            state: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            cn0: WireFormat::parse_unchecked(buf),
        }
    }
}
