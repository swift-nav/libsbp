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

impl MsgTrackingStateDetailedDep {
    pub fn synchronization_status(
        &self,
    ) -> Option<MsgTrackingStateDetailedDepSynchronizationStatus> {
        match get_bit_range!( self.sync_flags,  u8, u8, 2, 0 ) {
            0 => Some( MsgTrackingStateDetailedDepSynchronizationStatus :: NoSynchronization ),
            1 => Some( MsgTrackingStateDetailedDepSynchronizationStatus :: BitSynchronization ),
            2 => Some( MsgTrackingStateDetailedDepSynchronizationStatus :: WordSynchronization ),
            3 => Some( MsgTrackingStateDetailedDepSynchronizationStatus :: SubFrameSynchronizationMessageSynchronization ),
            _ => None,
        }
    }

    pub fn set_synchronization_status(
        &mut self,
        synchronization_status: MsgTrackingStateDetailedDepSynchronizationStatus,
    ) {
        set_bit_range!(&mut self.sync_flags, synchronization_status, u8, u8, 2, 0);
    }

    pub fn week_number_validity_status(
        &self,
    ) -> Option<MsgTrackingStateDetailedDepWeekNumberValidityStatus> {
        match get_bit_range!(self.tow_flags, u8, u8, 3, 0) {
            0 => Some(MsgTrackingStateDetailedDepWeekNumberValidityStatus::WeekNumberIsNotValid),
            1 => Some(MsgTrackingStateDetailedDepWeekNumberValidityStatus::WeekNumberIsValid),
            _ => None,
        }
    }

    pub fn set_week_number_validity_status(
        &mut self,
        week_number_validity_status: MsgTrackingStateDetailedDepWeekNumberValidityStatus,
    ) {
        set_bit_range!(
            &mut self.tow_flags,
            week_number_validity_status,
            u8,
            u8,
            3,
            0
        );
    }

    pub fn tow_status(&self) -> Option<MsgTrackingStateDetailedDepTowStatus> {
        match get_bit_range!(self.tow_flags, u8, u8, 2, 0) {
            0 => Some(MsgTrackingStateDetailedDepTowStatus::TowIsNotAvailable),
            1 => Some(MsgTrackingStateDetailedDepTowStatus::DecodedTowIsAvailable),
            2 => Some(MsgTrackingStateDetailedDepTowStatus::PropagatedTowIsAvailable),
            _ => None,
        }
    }

    pub fn set_tow_status(&mut self, tow_status: MsgTrackingStateDetailedDepTowStatus) {
        set_bit_range!(&mut self.tow_flags, tow_status, u8, u8, 2, 0);
    }

    pub fn fll_status(&self) -> Option<MsgTrackingStateDetailedDepFllStatus> {
        match get_bit_range!(self.track_flags, u8, u8, 4, 0) {
            0 => Some(MsgTrackingStateDetailedDepFllStatus::FllIsInactive),
            1 => Some(MsgTrackingStateDetailedDepFllStatus::FllIsActive),
            _ => None,
        }
    }

    pub fn set_fll_status(&mut self, fll_status: MsgTrackingStateDetailedDepFllStatus) {
        set_bit_range!(&mut self.track_flags, fll_status, u8, u8, 4, 0);
    }

    pub fn pll_status(&self) -> Option<MsgTrackingStateDetailedDepPllStatus> {
        match get_bit_range!(self.track_flags, u8, u8, 3, 0) {
            0 => Some(MsgTrackingStateDetailedDepPllStatus::PllIsInactive),
            1 => Some(MsgTrackingStateDetailedDepPllStatus::PllIsActive),
            _ => None,
        }
    }

    pub fn set_pll_status(&mut self, pll_status: MsgTrackingStateDetailedDepPllStatus) {
        set_bit_range!(&mut self.track_flags, pll_status, u8, u8, 3, 0);
    }

    pub fn tracking_loop_status(&self) -> Option<MsgTrackingStateDetailedDepTrackingLoopStatus> {
        match get_bit_range!(self.track_flags, u8, u8, 2, 0) {
            0 => Some(MsgTrackingStateDetailedDepTrackingLoopStatus::NoLocks),
            1 => Some(MsgTrackingStateDetailedDepTrackingLoopStatus::FlldllLock),
            2 => Some(MsgTrackingStateDetailedDepTrackingLoopStatus::PllOptimisticLock),
            3 => Some(MsgTrackingStateDetailedDepTrackingLoopStatus::PllPessimisticLock),
            _ => None,
        }
    }

    pub fn set_tracking_loop_status(
        &mut self,
        tracking_loop_status: MsgTrackingStateDetailedDepTrackingLoopStatus,
    ) {
        set_bit_range!(&mut self.track_flags, tracking_loop_status, u8, u8, 2, 0);
    }

    pub fn almanac_availability_status(
        &self,
    ) -> Option<MsgTrackingStateDetailedDepAlmanacAvailabilityStatus> {
        match get_bit_range!(self.nav_flags, u8, u8, 4, 0) {
            0 => Some(MsgTrackingStateDetailedDepAlmanacAvailabilityStatus::AlmanacIsNotAvailable),
            1 => Some(MsgTrackingStateDetailedDepAlmanacAvailabilityStatus::AlmanacIsAvailable),
            _ => None,
        }
    }

    pub fn set_almanac_availability_status(
        &mut self,
        almanac_availability_status: MsgTrackingStateDetailedDepAlmanacAvailabilityStatus,
    ) {
        set_bit_range!(
            &mut self.nav_flags,
            almanac_availability_status,
            u8,
            u8,
            4,
            0
        );
    }

    pub fn ephemeris_availability_status(
        &self,
    ) -> Option<MsgTrackingStateDetailedDepEphemerisAvailabilityStatus> {
        match get_bit_range!(self.nav_flags, u8, u8, 3, 0) {
            0 => Some(
                MsgTrackingStateDetailedDepEphemerisAvailabilityStatus::EphemerisIsNotAvailable,
            ),
            1 => Some(MsgTrackingStateDetailedDepEphemerisAvailabilityStatus::EphemerisIsAvailable),
            _ => None,
        }
    }

    pub fn set_ephemeris_availability_status(
        &mut self,
        ephemeris_availability_status: MsgTrackingStateDetailedDepEphemerisAvailabilityStatus,
    ) {
        set_bit_range!(
            &mut self.nav_flags,
            ephemeris_availability_status,
            u8,
            u8,
            3,
            0
        );
    }

    pub fn health_status(&self) -> Option<MsgTrackingStateDetailedDepHealthStatus> {
        match get_bit_range!(self.nav_flags, u8, u8, 2, 0) {
            0 => Some(MsgTrackingStateDetailedDepHealthStatus::HealthIsUnknown),
            1 => Some(MsgTrackingStateDetailedDepHealthStatus::SignalIsUnhealthy),
            2 => Some(MsgTrackingStateDetailedDepHealthStatus::SignalIsHealthy),
            _ => None,
        }
    }

    pub fn set_health_status(&mut self, health_status: MsgTrackingStateDetailedDepHealthStatus) {
        set_bit_range!(&mut self.nav_flags, health_status, u8, u8, 2, 0);
    }

    pub fn parameter_sets(&self) -> Option<MsgTrackingStateDetailedDepParameterSets> {
        match get_bit_range!(self.pset_flags, u8, u8, 2, 0) {
            0 => Some(MsgTrackingStateDetailedDepParameterSets::_1MsIntegrationTime),
            1 => Some(MsgTrackingStateDetailedDepParameterSets::_5MsIntegrationTime),
            2 => Some(MsgTrackingStateDetailedDepParameterSets::_10MsIntegrationTime),
            3 => Some(MsgTrackingStateDetailedDepParameterSets::_20MsIntegrationTime),
            _ => None,
        }
    }

    pub fn set_parameter_sets(&mut self, parameter_sets: MsgTrackingStateDetailedDepParameterSets) {
        set_bit_range!(&mut self.pset_flags, parameter_sets, u8, u8, 2, 0);
    }

    pub fn clock_validity_status(&self) -> Option<MsgTrackingStateDetailedDepClockValidityStatus> {
        match get_bit_range!(self.misc_flags, u8, u8, 5, 0) {
            0 => {
                Some(MsgTrackingStateDetailedDepClockValidityStatus::ClockOffsetAndDriftIsNotValid)
            }
            1 => Some(MsgTrackingStateDetailedDepClockValidityStatus::ClockOffsetAndDriftIsValid),
            _ => None,
        }
    }

    pub fn set_clock_validity_status(
        &mut self,
        clock_validity_status: MsgTrackingStateDetailedDepClockValidityStatus,
    ) {
        set_bit_range!(&mut self.misc_flags, clock_validity_status, u8, u8, 5, 0);
    }

    pub fn pseudorange_validity_status(
        &self,
    ) -> Option<MsgTrackingStateDetailedDepPseudorangeValidityStatus> {
        match get_bit_range!(self.misc_flags, u8, u8, 4, 0) {
            0 => Some(MsgTrackingStateDetailedDepPseudorangeValidityStatus::PseudorangeIsNotValid),
            1 => Some(MsgTrackingStateDetailedDepPseudorangeValidityStatus::PseudorangeIsValid),
            _ => None,
        }
    }

    pub fn set_pseudorange_validity_status(
        &mut self,
        pseudorange_validity_status: MsgTrackingStateDetailedDepPseudorangeValidityStatus,
    ) {
        set_bit_range!(
            &mut self.misc_flags,
            pseudorange_validity_status,
            u8,
            u8,
            4,
            0
        );
    }

    pub fn acceleration_validity_status(
        &self,
    ) -> Option<MsgTrackingStateDetailedDepAccelerationValidityStatus> {
        match get_bit_range!(self.misc_flags, u8, u8, 3, 0) {
            0 => {
                Some(MsgTrackingStateDetailedDepAccelerationValidityStatus::AccelerationIsNotValid)
            }
            1 => Some(MsgTrackingStateDetailedDepAccelerationValidityStatus::AccelerationIsValid),
            _ => None,
        }
    }

    pub fn set_acceleration_validity_status(
        &mut self,
        acceleration_validity_status: MsgTrackingStateDetailedDepAccelerationValidityStatus,
    ) {
        set_bit_range!(
            &mut self.misc_flags,
            acceleration_validity_status,
            u8,
            u8,
            3,
            0
        );
    }

    pub fn carrier_half_cycle_ambiguity_status(
        &self,
    ) -> Option<MsgTrackingStateDetailedDepCarrierHalfCycleAmbiguityStatus> {
        match get_bit_range!(self.misc_flags, u8, u8, 2, 0) {
            0 => Some(MsgTrackingStateDetailedDepCarrierHalfCycleAmbiguityStatus::Unresolved),
            1 => Some(MsgTrackingStateDetailedDepCarrierHalfCycleAmbiguityStatus::Resolved),
            _ => None,
        }
    }

    pub fn set_carrier_half_cycle_ambiguity_status(
        &mut self,
        carrier_half_cycle_ambiguity_status: MsgTrackingStateDetailedDepCarrierHalfCycleAmbiguityStatus,
    ) {
        set_bit_range!(
            &mut self.misc_flags,
            carrier_half_cycle_ambiguity_status,
            u8,
            u8,
            2,
            0
        );
    }

    pub fn tracking_channel_status(
        &self,
    ) -> Option<MsgTrackingStateDetailedDepTrackingChannelStatus> {
        match get_bit_range!(self.misc_flags, u8, u8, 1, 0) {
            0 => Some(MsgTrackingStateDetailedDepTrackingChannelStatus::ReAcquisition),
            1 => Some(MsgTrackingStateDetailedDepTrackingChannelStatus::Running),
            _ => None,
        }
    }

    pub fn set_tracking_channel_status(
        &mut self,
        tracking_channel_status: MsgTrackingStateDetailedDepTrackingChannelStatus,
    ) {
        set_bit_range!(&mut self.misc_flags, tracking_channel_status, u8, u8, 1, 0);
    }
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

/// Synchronization status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepSynchronizationStatus {
    /// No synchronization
    NoSynchronization = 0,

    /// Bit synchronization
    BitSynchronization = 1,

    /// Word synchronization (L1 C/A only)
    WordSynchronization = 2,

    /// Sub-frame synchronization (L1 C/A) / message synchronization (L2C)
    SubFrameSynchronizationMessageSynchronization = 3,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepSynchronizationStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepSynchronizationStatus::NoSynchronization => f.write_str("No synchronization"),
            MsgTrackingStateDetailedDepSynchronizationStatus::BitSynchronization => f.write_str("Bit synchronization"),
            MsgTrackingStateDetailedDepSynchronizationStatus::WordSynchronization => f.write_str("Word synchronization (L1 C/A only)"),
            MsgTrackingStateDetailedDepSynchronizationStatus::SubFrameSynchronizationMessageSynchronization => f.write_str("Sub-frame synchronization (L1 C/A) / message synchronization (L2C)
"),
        }
    }
}

/// Week number validity status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepWeekNumberValidityStatus {
    /// Week number is not valid
    WeekNumberIsNotValid = 0,

    /// Week number is valid
    WeekNumberIsValid = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepWeekNumberValidityStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepWeekNumberValidityStatus::WeekNumberIsNotValid => {
                f.write_str("Week number is not valid")
            }
            MsgTrackingStateDetailedDepWeekNumberValidityStatus::WeekNumberIsValid => {
                f.write_str("Week number is valid")
            }
        }
    }
}

/// TOW status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepTowStatus {
    /// TOW is not available
    TowIsNotAvailable = 0,

    /// Decoded TOW is available
    DecodedTowIsAvailable = 1,

    /// Propagated TOW is available
    PropagatedTowIsAvailable = 2,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepTowStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepTowStatus::TowIsNotAvailable => {
                f.write_str("TOW is not available")
            }
            MsgTrackingStateDetailedDepTowStatus::DecodedTowIsAvailable => {
                f.write_str("Decoded TOW is available")
            }
            MsgTrackingStateDetailedDepTowStatus::PropagatedTowIsAvailable => {
                f.write_str("Propagated TOW is available")
            }
        }
    }
}

/// FLL status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepFllStatus {
    /// FLL is inactive
    FllIsInactive = 0,

    /// FLL is active
    FllIsActive = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepFllStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepFllStatus::FllIsInactive => f.write_str("FLL is inactive"),
            MsgTrackingStateDetailedDepFllStatus::FllIsActive => f.write_str("FLL is active"),
        }
    }
}

/// PLL status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepPllStatus {
    /// PLL is inactive
    PllIsInactive = 0,

    /// PLL is active
    PllIsActive = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepPllStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepPllStatus::PllIsInactive => f.write_str("PLL is inactive"),
            MsgTrackingStateDetailedDepPllStatus::PllIsActive => f.write_str("PLL is active"),
        }
    }
}

/// Tracking loop status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepTrackingLoopStatus {
    /// No locks
    NoLocks = 0,

    /// FLL/DLL lock
    FlldllLock = 1,

    /// PLL optimistic lock
    PllOptimisticLock = 2,

    /// PLL pessimistic lock
    PllPessimisticLock = 3,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepTrackingLoopStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepTrackingLoopStatus::NoLocks => f.write_str("No locks"),
            MsgTrackingStateDetailedDepTrackingLoopStatus::FlldllLock => {
                f.write_str("FLL/DLL lock")
            }
            MsgTrackingStateDetailedDepTrackingLoopStatus::PllOptimisticLock => {
                f.write_str("PLL optimistic lock")
            }
            MsgTrackingStateDetailedDepTrackingLoopStatus::PllPessimisticLock => {
                f.write_str("PLL pessimistic lock")
            }
        }
    }
}

/// Almanac availability status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepAlmanacAvailabilityStatus {
    /// Almanac is not available
    AlmanacIsNotAvailable = 0,

    /// Almanac is available
    AlmanacIsAvailable = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepAlmanacAvailabilityStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepAlmanacAvailabilityStatus::AlmanacIsNotAvailable => {
                f.write_str("Almanac is not available")
            }
            MsgTrackingStateDetailedDepAlmanacAvailabilityStatus::AlmanacIsAvailable => {
                f.write_str("Almanac is available")
            }
        }
    }
}

/// Ephemeris availability status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepEphemerisAvailabilityStatus {
    /// Ephemeris is not available
    EphemerisIsNotAvailable = 0,

    /// Ephemeris is available
    EphemerisIsAvailable = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepEphemerisAvailabilityStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepEphemerisAvailabilityStatus::EphemerisIsNotAvailable => {
                f.write_str("Ephemeris is not available")
            }
            MsgTrackingStateDetailedDepEphemerisAvailabilityStatus::EphemerisIsAvailable => {
                f.write_str("Ephemeris is available")
            }
        }
    }
}

/// Health status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepHealthStatus {
    /// Health is unknown
    HealthIsUnknown = 0,

    /// Signal is unhealthy
    SignalIsUnhealthy = 1,

    /// Signal is healthy
    SignalIsHealthy = 2,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepHealthStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepHealthStatus::HealthIsUnknown => {
                f.write_str("Health is unknown")
            }
            MsgTrackingStateDetailedDepHealthStatus::SignalIsUnhealthy => {
                f.write_str("Signal is unhealthy")
            }
            MsgTrackingStateDetailedDepHealthStatus::SignalIsHealthy => {
                f.write_str("Signal is healthy")
            }
        }
    }
}

/// Parameter sets.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepParameterSets {
    /// 1 ms integration time
    _1MsIntegrationTime = 0,

    /// 5 ms integration time
    _5MsIntegrationTime = 1,

    /// 10 ms integration time
    _10MsIntegrationTime = 2,

    /// 20 ms integration time
    _20MsIntegrationTime = 3,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepParameterSets {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepParameterSets::_1MsIntegrationTime => {
                f.write_str("1 ms integration time")
            }
            MsgTrackingStateDetailedDepParameterSets::_5MsIntegrationTime => {
                f.write_str("5 ms integration time")
            }
            MsgTrackingStateDetailedDepParameterSets::_10MsIntegrationTime => {
                f.write_str("10 ms integration time")
            }
            MsgTrackingStateDetailedDepParameterSets::_20MsIntegrationTime => {
                f.write_str("20 ms integration time")
            }
        }
    }
}

/// Clock validity status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepClockValidityStatus {
    /// Clock offset and drift is not valid
    ClockOffsetAndDriftIsNotValid = 0,

    /// Clock offset and drift is valid
    ClockOffsetAndDriftIsValid = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepClockValidityStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepClockValidityStatus::ClockOffsetAndDriftIsNotValid => {
                f.write_str("Clock offset and drift is not valid")
            }
            MsgTrackingStateDetailedDepClockValidityStatus::ClockOffsetAndDriftIsValid => {
                f.write_str("Clock offset and drift is valid")
            }
        }
    }
}

/// Pseudorange validity status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepPseudorangeValidityStatus {
    /// Pseudorange is not valid
    PseudorangeIsNotValid = 0,

    /// Pseudorange is valid
    PseudorangeIsValid = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepPseudorangeValidityStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepPseudorangeValidityStatus::PseudorangeIsNotValid => {
                f.write_str("Pseudorange is not valid")
            }
            MsgTrackingStateDetailedDepPseudorangeValidityStatus::PseudorangeIsValid => {
                f.write_str("Pseudorange is valid")
            }
        }
    }
}

/// Acceleration validity status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepAccelerationValidityStatus {
    /// Acceleration is not valid
    AccelerationIsNotValid = 0,

    /// Acceleration is valid
    AccelerationIsValid = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepAccelerationValidityStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepAccelerationValidityStatus::AccelerationIsNotValid => {
                f.write_str("Acceleration is not valid")
            }
            MsgTrackingStateDetailedDepAccelerationValidityStatus::AccelerationIsValid => {
                f.write_str("Acceleration is valid")
            }
        }
    }
}

/// Carrier half cycle ambiguity status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepCarrierHalfCycleAmbiguityStatus {
    /// Unresolved
    Unresolved = 0,

    /// Resolved
    Resolved = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepCarrierHalfCycleAmbiguityStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepCarrierHalfCycleAmbiguityStatus::Unresolved => {
                f.write_str("Unresolved")
            }
            MsgTrackingStateDetailedDepCarrierHalfCycleAmbiguityStatus::Resolved => {
                f.write_str("Resolved")
            }
        }
    }
}

/// Tracking channel status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepTrackingChannelStatus {
    /// Re-acquisition
    ReAcquisition = 0,

    /// Running
    Running = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepTrackingChannelStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepTrackingChannelStatus::ReAcquisition => {
                f.write_str("Re-acquisition")
            }
            MsgTrackingStateDetailedDepTrackingChannelStatus::Running => f.write_str("Running"),
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

impl MsgTrackingStateDetailedDepA {
    pub fn synchronization_status(
        &self,
    ) -> Option<MsgTrackingStateDetailedDepASynchronizationStatus> {
        match get_bit_range!( self.sync_flags,  u8, u8, 2, 0 ) {
            0 => Some( MsgTrackingStateDetailedDepASynchronizationStatus :: NoSynchronization ),
            1 => Some( MsgTrackingStateDetailedDepASynchronizationStatus :: BitSynchronization ),
            2 => Some( MsgTrackingStateDetailedDepASynchronizationStatus :: WordSynchronization ),
            3 => Some( MsgTrackingStateDetailedDepASynchronizationStatus :: SubFrameSynchronizationMessageSynchronization ),
            _ => None,
        }
    }

    pub fn set_synchronization_status(
        &mut self,
        synchronization_status: MsgTrackingStateDetailedDepASynchronizationStatus,
    ) {
        set_bit_range!(&mut self.sync_flags, synchronization_status, u8, u8, 2, 0);
    }

    pub fn week_number_validity_status(
        &self,
    ) -> Option<MsgTrackingStateDetailedDepAWeekNumberValidityStatus> {
        match get_bit_range!(self.tow_flags, u8, u8, 3, 0) {
            0 => Some(MsgTrackingStateDetailedDepAWeekNumberValidityStatus::WeekNumberIsNotValid),
            1 => Some(MsgTrackingStateDetailedDepAWeekNumberValidityStatus::WeekNumberIsValid),
            _ => None,
        }
    }

    pub fn set_week_number_validity_status(
        &mut self,
        week_number_validity_status: MsgTrackingStateDetailedDepAWeekNumberValidityStatus,
    ) {
        set_bit_range!(
            &mut self.tow_flags,
            week_number_validity_status,
            u8,
            u8,
            3,
            0
        );
    }

    pub fn tow_status(&self) -> Option<MsgTrackingStateDetailedDepATowStatus> {
        match get_bit_range!(self.tow_flags, u8, u8, 2, 0) {
            0 => Some(MsgTrackingStateDetailedDepATowStatus::TowIsNotAvailable),
            1 => Some(MsgTrackingStateDetailedDepATowStatus::DecodedTowIsAvailable),
            2 => Some(MsgTrackingStateDetailedDepATowStatus::PropagatedTowIsAvailable),
            _ => None,
        }
    }

    pub fn set_tow_status(&mut self, tow_status: MsgTrackingStateDetailedDepATowStatus) {
        set_bit_range!(&mut self.tow_flags, tow_status, u8, u8, 2, 0);
    }

    pub fn fll_status(&self) -> Option<MsgTrackingStateDetailedDepAFllStatus> {
        match get_bit_range!(self.track_flags, u8, u8, 4, 0) {
            0 => Some(MsgTrackingStateDetailedDepAFllStatus::FllIsInactive),
            1 => Some(MsgTrackingStateDetailedDepAFllStatus::FllIsActive),
            _ => None,
        }
    }

    pub fn set_fll_status(&mut self, fll_status: MsgTrackingStateDetailedDepAFllStatus) {
        set_bit_range!(&mut self.track_flags, fll_status, u8, u8, 4, 0);
    }

    pub fn pll_status(&self) -> Option<MsgTrackingStateDetailedDepAPllStatus> {
        match get_bit_range!(self.track_flags, u8, u8, 3, 0) {
            0 => Some(MsgTrackingStateDetailedDepAPllStatus::PllIsInactive),
            1 => Some(MsgTrackingStateDetailedDepAPllStatus::PllIsActive),
            _ => None,
        }
    }

    pub fn set_pll_status(&mut self, pll_status: MsgTrackingStateDetailedDepAPllStatus) {
        set_bit_range!(&mut self.track_flags, pll_status, u8, u8, 3, 0);
    }

    pub fn tracking_loop_status(&self) -> Option<MsgTrackingStateDetailedDepATrackingLoopStatus> {
        match get_bit_range!(self.track_flags, u8, u8, 2, 0) {
            0 => Some(MsgTrackingStateDetailedDepATrackingLoopStatus::NoLocks),
            1 => Some(MsgTrackingStateDetailedDepATrackingLoopStatus::FlldllLock),
            2 => Some(MsgTrackingStateDetailedDepATrackingLoopStatus::PllOptimisticLock),
            3 => Some(MsgTrackingStateDetailedDepATrackingLoopStatus::PllPessimisticLock),
            _ => None,
        }
    }

    pub fn set_tracking_loop_status(
        &mut self,
        tracking_loop_status: MsgTrackingStateDetailedDepATrackingLoopStatus,
    ) {
        set_bit_range!(&mut self.track_flags, tracking_loop_status, u8, u8, 2, 0);
    }

    pub fn almanac_availability_status(
        &self,
    ) -> Option<MsgTrackingStateDetailedDepAAlmanacAvailabilityStatus> {
        match get_bit_range!(self.nav_flags, u8, u8, 4, 0) {
            0 => Some(MsgTrackingStateDetailedDepAAlmanacAvailabilityStatus::AlmanacIsNotAvailable),
            1 => Some(MsgTrackingStateDetailedDepAAlmanacAvailabilityStatus::AlmanacIsAvailable),
            _ => None,
        }
    }

    pub fn set_almanac_availability_status(
        &mut self,
        almanac_availability_status: MsgTrackingStateDetailedDepAAlmanacAvailabilityStatus,
    ) {
        set_bit_range!(
            &mut self.nav_flags,
            almanac_availability_status,
            u8,
            u8,
            4,
            0
        );
    }

    pub fn ephemeris_availability_status(
        &self,
    ) -> Option<MsgTrackingStateDetailedDepAEphemerisAvailabilityStatus> {
        match get_bit_range!(self.nav_flags, u8, u8, 3, 0) {
            0 => Some(
                MsgTrackingStateDetailedDepAEphemerisAvailabilityStatus::EphemerisIsNotAvailable,
            ),
            1 => {
                Some(MsgTrackingStateDetailedDepAEphemerisAvailabilityStatus::EphemerisIsAvailable)
            }
            _ => None,
        }
    }

    pub fn set_ephemeris_availability_status(
        &mut self,
        ephemeris_availability_status: MsgTrackingStateDetailedDepAEphemerisAvailabilityStatus,
    ) {
        set_bit_range!(
            &mut self.nav_flags,
            ephemeris_availability_status,
            u8,
            u8,
            3,
            0
        );
    }

    pub fn health_status(&self) -> Option<MsgTrackingStateDetailedDepAHealthStatus> {
        match get_bit_range!(self.nav_flags, u8, u8, 2, 0) {
            0 => Some(MsgTrackingStateDetailedDepAHealthStatus::HealthIsUnknown),
            1 => Some(MsgTrackingStateDetailedDepAHealthStatus::SignalIsUnhealthy),
            2 => Some(MsgTrackingStateDetailedDepAHealthStatus::SignalIsHealthy),
            _ => None,
        }
    }

    pub fn set_health_status(&mut self, health_status: MsgTrackingStateDetailedDepAHealthStatus) {
        set_bit_range!(&mut self.nav_flags, health_status, u8, u8, 2, 0);
    }

    pub fn parameter_sets(&self) -> Option<MsgTrackingStateDetailedDepAParameterSets> {
        match get_bit_range!(self.pset_flags, u8, u8, 2, 0) {
            0 => Some(MsgTrackingStateDetailedDepAParameterSets::_1MsIntegrationTime),
            1 => Some(MsgTrackingStateDetailedDepAParameterSets::_5MsIntegrationTime),
            2 => Some(MsgTrackingStateDetailedDepAParameterSets::_10MsIntegrationTime),
            3 => Some(MsgTrackingStateDetailedDepAParameterSets::_20MsIntegrationTime),
            _ => None,
        }
    }

    pub fn set_parameter_sets(
        &mut self,
        parameter_sets: MsgTrackingStateDetailedDepAParameterSets,
    ) {
        set_bit_range!(&mut self.pset_flags, parameter_sets, u8, u8, 2, 0);
    }

    pub fn clock_validity_status(&self) -> Option<MsgTrackingStateDetailedDepAClockValidityStatus> {
        match get_bit_range!(self.misc_flags, u8, u8, 5, 0) {
            0 => {
                Some(MsgTrackingStateDetailedDepAClockValidityStatus::ClockOffsetAndDriftIsNotValid)
            }
            1 => Some(MsgTrackingStateDetailedDepAClockValidityStatus::ClockOffsetAndDriftIsValid),
            _ => None,
        }
    }

    pub fn set_clock_validity_status(
        &mut self,
        clock_validity_status: MsgTrackingStateDetailedDepAClockValidityStatus,
    ) {
        set_bit_range!(&mut self.misc_flags, clock_validity_status, u8, u8, 5, 0);
    }

    pub fn pseudorange_validity_status(
        &self,
    ) -> Option<MsgTrackingStateDetailedDepAPseudorangeValidityStatus> {
        match get_bit_range!(self.misc_flags, u8, u8, 4, 0) {
            0 => Some(MsgTrackingStateDetailedDepAPseudorangeValidityStatus::PseudorangeIsNotValid),
            1 => Some(MsgTrackingStateDetailedDepAPseudorangeValidityStatus::PseudorangeIsValid),
            _ => None,
        }
    }

    pub fn set_pseudorange_validity_status(
        &mut self,
        pseudorange_validity_status: MsgTrackingStateDetailedDepAPseudorangeValidityStatus,
    ) {
        set_bit_range!(
            &mut self.misc_flags,
            pseudorange_validity_status,
            u8,
            u8,
            4,
            0
        );
    }

    pub fn acceleration_validity_status(
        &self,
    ) -> Option<MsgTrackingStateDetailedDepAAccelerationValidityStatus> {
        match get_bit_range!(self.misc_flags, u8, u8, 3, 0) {
            0 => {
                Some(MsgTrackingStateDetailedDepAAccelerationValidityStatus::AccelerationIsNotValid)
            }
            1 => Some(MsgTrackingStateDetailedDepAAccelerationValidityStatus::AccelerationIsValid),
            _ => None,
        }
    }

    pub fn set_acceleration_validity_status(
        &mut self,
        acceleration_validity_status: MsgTrackingStateDetailedDepAAccelerationValidityStatus,
    ) {
        set_bit_range!(
            &mut self.misc_flags,
            acceleration_validity_status,
            u8,
            u8,
            3,
            0
        );
    }

    pub fn carrier_half_cycle_ambiguity_status(
        &self,
    ) -> Option<MsgTrackingStateDetailedDepACarrierHalfCycleAmbiguityStatus> {
        match get_bit_range!(self.misc_flags, u8, u8, 2, 0) {
            0 => Some(MsgTrackingStateDetailedDepACarrierHalfCycleAmbiguityStatus::Unresolved),
            1 => Some(MsgTrackingStateDetailedDepACarrierHalfCycleAmbiguityStatus::Resolved),
            _ => None,
        }
    }

    pub fn set_carrier_half_cycle_ambiguity_status(
        &mut self,
        carrier_half_cycle_ambiguity_status: MsgTrackingStateDetailedDepACarrierHalfCycleAmbiguityStatus,
    ) {
        set_bit_range!(
            &mut self.misc_flags,
            carrier_half_cycle_ambiguity_status,
            u8,
            u8,
            2,
            0
        );
    }

    pub fn tracking_channel_status(
        &self,
    ) -> Option<MsgTrackingStateDetailedDepATrackingChannelStatus> {
        match get_bit_range!(self.misc_flags, u8, u8, 1, 0) {
            0 => Some(MsgTrackingStateDetailedDepATrackingChannelStatus::ReAcquisition),
            1 => Some(MsgTrackingStateDetailedDepATrackingChannelStatus::Running),
            _ => None,
        }
    }

    pub fn set_tracking_channel_status(
        &mut self,
        tracking_channel_status: MsgTrackingStateDetailedDepATrackingChannelStatus,
    ) {
        set_bit_range!(&mut self.misc_flags, tracking_channel_status, u8, u8, 1, 0);
    }
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

/// Synchronization status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepASynchronizationStatus {
    /// No synchronization
    NoSynchronization = 0,

    /// Bit synchronization
    BitSynchronization = 1,

    /// Word synchronization (L1 C/A only)
    WordSynchronization = 2,

    /// Sub-frame synchronization (L1 C/A) / message synchronization (L2C)
    SubFrameSynchronizationMessageSynchronization = 3,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepASynchronizationStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepASynchronizationStatus::NoSynchronization => f.write_str("No synchronization"),
            MsgTrackingStateDetailedDepASynchronizationStatus::BitSynchronization => f.write_str("Bit synchronization"),
            MsgTrackingStateDetailedDepASynchronizationStatus::WordSynchronization => f.write_str("Word synchronization (L1 C/A only)"),
            MsgTrackingStateDetailedDepASynchronizationStatus::SubFrameSynchronizationMessageSynchronization => f.write_str("Sub-frame synchronization (L1 C/A) / message synchronization (L2C)
"),
        }
    }
}

/// Week number validity status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepAWeekNumberValidityStatus {
    /// Week number is not valid
    WeekNumberIsNotValid = 0,

    /// Week number is valid
    WeekNumberIsValid = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepAWeekNumberValidityStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepAWeekNumberValidityStatus::WeekNumberIsNotValid => {
                f.write_str("Week number is not valid")
            }
            MsgTrackingStateDetailedDepAWeekNumberValidityStatus::WeekNumberIsValid => {
                f.write_str("Week number is valid")
            }
        }
    }
}

/// TOW status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepATowStatus {
    /// TOW is not available
    TowIsNotAvailable = 0,

    /// Decoded TOW is available
    DecodedTowIsAvailable = 1,

    /// Propagated TOW is available
    PropagatedTowIsAvailable = 2,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepATowStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepATowStatus::TowIsNotAvailable => {
                f.write_str("TOW is not available")
            }
            MsgTrackingStateDetailedDepATowStatus::DecodedTowIsAvailable => {
                f.write_str("Decoded TOW is available")
            }
            MsgTrackingStateDetailedDepATowStatus::PropagatedTowIsAvailable => {
                f.write_str("Propagated TOW is available")
            }
        }
    }
}

/// FLL status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepAFllStatus {
    /// FLL is inactive
    FllIsInactive = 0,

    /// FLL is active
    FllIsActive = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepAFllStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepAFllStatus::FllIsInactive => f.write_str("FLL is inactive"),
            MsgTrackingStateDetailedDepAFllStatus::FllIsActive => f.write_str("FLL is active"),
        }
    }
}

/// PLL status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepAPllStatus {
    /// PLL is inactive
    PllIsInactive = 0,

    /// PLL is active
    PllIsActive = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepAPllStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepAPllStatus::PllIsInactive => f.write_str("PLL is inactive"),
            MsgTrackingStateDetailedDepAPllStatus::PllIsActive => f.write_str("PLL is active"),
        }
    }
}

/// Tracking loop status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepATrackingLoopStatus {
    /// No locks
    NoLocks = 0,

    /// FLL/DLL lock
    FlldllLock = 1,

    /// PLL optimistic lock
    PllOptimisticLock = 2,

    /// PLL pessimistic lock
    PllPessimisticLock = 3,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepATrackingLoopStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepATrackingLoopStatus::NoLocks => f.write_str("No locks"),
            MsgTrackingStateDetailedDepATrackingLoopStatus::FlldllLock => {
                f.write_str("FLL/DLL lock")
            }
            MsgTrackingStateDetailedDepATrackingLoopStatus::PllOptimisticLock => {
                f.write_str("PLL optimistic lock")
            }
            MsgTrackingStateDetailedDepATrackingLoopStatus::PllPessimisticLock => {
                f.write_str("PLL pessimistic lock")
            }
        }
    }
}

/// Almanac availability status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepAAlmanacAvailabilityStatus {
    /// Almanac is not available
    AlmanacIsNotAvailable = 0,

    /// Almanac is available
    AlmanacIsAvailable = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepAAlmanacAvailabilityStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepAAlmanacAvailabilityStatus::AlmanacIsNotAvailable => {
                f.write_str("Almanac is not available")
            }
            MsgTrackingStateDetailedDepAAlmanacAvailabilityStatus::AlmanacIsAvailable => {
                f.write_str("Almanac is available")
            }
        }
    }
}

/// Ephemeris availability status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepAEphemerisAvailabilityStatus {
    /// Ephemeris is not available
    EphemerisIsNotAvailable = 0,

    /// Ephemeris is available
    EphemerisIsAvailable = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepAEphemerisAvailabilityStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepAEphemerisAvailabilityStatus::EphemerisIsNotAvailable => {
                f.write_str("Ephemeris is not available")
            }
            MsgTrackingStateDetailedDepAEphemerisAvailabilityStatus::EphemerisIsAvailable => {
                f.write_str("Ephemeris is available")
            }
        }
    }
}

/// Health status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepAHealthStatus {
    /// Health is unknown
    HealthIsUnknown = 0,

    /// Signal is unhealthy
    SignalIsUnhealthy = 1,

    /// Signal is healthy
    SignalIsHealthy = 2,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepAHealthStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepAHealthStatus::HealthIsUnknown => {
                f.write_str("Health is unknown")
            }
            MsgTrackingStateDetailedDepAHealthStatus::SignalIsUnhealthy => {
                f.write_str("Signal is unhealthy")
            }
            MsgTrackingStateDetailedDepAHealthStatus::SignalIsHealthy => {
                f.write_str("Signal is healthy")
            }
        }
    }
}

/// Parameter sets.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepAParameterSets {
    /// 1 ms integration time
    _1MsIntegrationTime = 0,

    /// 5 ms integration time
    _5MsIntegrationTime = 1,

    /// 10 ms integration time
    _10MsIntegrationTime = 2,

    /// 20 ms integration time
    _20MsIntegrationTime = 3,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepAParameterSets {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepAParameterSets::_1MsIntegrationTime => {
                f.write_str("1 ms integration time")
            }
            MsgTrackingStateDetailedDepAParameterSets::_5MsIntegrationTime => {
                f.write_str("5 ms integration time")
            }
            MsgTrackingStateDetailedDepAParameterSets::_10MsIntegrationTime => {
                f.write_str("10 ms integration time")
            }
            MsgTrackingStateDetailedDepAParameterSets::_20MsIntegrationTime => {
                f.write_str("20 ms integration time")
            }
        }
    }
}

/// Clock validity status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepAClockValidityStatus {
    /// Clock offset and drift is not valid
    ClockOffsetAndDriftIsNotValid = 0,

    /// Clock offset and drift is valid
    ClockOffsetAndDriftIsValid = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepAClockValidityStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepAClockValidityStatus::ClockOffsetAndDriftIsNotValid => {
                f.write_str("Clock offset and drift is not valid")
            }
            MsgTrackingStateDetailedDepAClockValidityStatus::ClockOffsetAndDriftIsValid => {
                f.write_str("Clock offset and drift is valid")
            }
        }
    }
}

/// Pseudorange validity status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepAPseudorangeValidityStatus {
    /// Pseudorange is not valid
    PseudorangeIsNotValid = 0,

    /// Pseudorange is valid
    PseudorangeIsValid = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepAPseudorangeValidityStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepAPseudorangeValidityStatus::PseudorangeIsNotValid => {
                f.write_str("Pseudorange is not valid")
            }
            MsgTrackingStateDetailedDepAPseudorangeValidityStatus::PseudorangeIsValid => {
                f.write_str("Pseudorange is valid")
            }
        }
    }
}

/// Acceleration validity status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepAAccelerationValidityStatus {
    /// Acceleration is not valid
    AccelerationIsNotValid = 0,

    /// Acceleration is valid
    AccelerationIsValid = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepAAccelerationValidityStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepAAccelerationValidityStatus::AccelerationIsNotValid => {
                f.write_str("Acceleration is not valid")
            }
            MsgTrackingStateDetailedDepAAccelerationValidityStatus::AccelerationIsValid => {
                f.write_str("Acceleration is valid")
            }
        }
    }
}

/// Carrier half cycle ambiguity status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepACarrierHalfCycleAmbiguityStatus {
    /// Unresolved
    Unresolved = 0,

    /// Resolved
    Resolved = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepACarrierHalfCycleAmbiguityStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepACarrierHalfCycleAmbiguityStatus::Unresolved => {
                f.write_str("Unresolved")
            }
            MsgTrackingStateDetailedDepACarrierHalfCycleAmbiguityStatus::Resolved => {
                f.write_str("Resolved")
            }
        }
    }
}

/// Tracking channel status.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgTrackingStateDetailedDepATrackingChannelStatus {
    /// Re-acquisition
    ReAcquisition = 0,

    /// Running
    Running = 1,
}

impl std::fmt::Display for MsgTrackingStateDetailedDepATrackingChannelStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgTrackingStateDetailedDepATrackingChannelStatus::ReAcquisition => {
                f.write_str("Re-acquisition")
            }
            MsgTrackingStateDetailedDepATrackingChannelStatus::Running => f.write_str("Running"),
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

impl TrackingChannelStateDepA {
    pub fn tracking_mode(&self) -> Option<TrackingChannelStateDepATrackingMode> {
        match get_bit_range!(self.state, u8, u8, 1, 0) {
            0 => Some(TrackingChannelStateDepATrackingMode::Disabled),
            1 => Some(TrackingChannelStateDepATrackingMode::Running),
            _ => None,
        }
    }

    pub fn set_tracking_mode(&mut self, tracking_mode: TrackingChannelStateDepATrackingMode) {
        set_bit_range!(&mut self.state, tracking_mode, u8, u8, 1, 0);
    }
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

/// Tracking mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum TrackingChannelStateDepATrackingMode {
    /// Disabled
    Disabled = 0,

    /// Running
    Running = 1,
}

impl std::fmt::Display for TrackingChannelStateDepATrackingMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            TrackingChannelStateDepATrackingMode::Disabled => f.write_str("Disabled"),
            TrackingChannelStateDepATrackingMode::Running => f.write_str("Running"),
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

impl TrackingChannelStateDepB {
    pub fn tracking_mode(&self) -> Option<TrackingChannelStateDepBTrackingMode> {
        match get_bit_range!(self.state, u8, u8, 1, 0) {
            0 => Some(TrackingChannelStateDepBTrackingMode::Disabled),
            1 => Some(TrackingChannelStateDepBTrackingMode::Running),
            _ => None,
        }
    }

    pub fn set_tracking_mode(&mut self, tracking_mode: TrackingChannelStateDepBTrackingMode) {
        set_bit_range!(&mut self.state, tracking_mode, u8, u8, 1, 0);
    }
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

/// Tracking mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum TrackingChannelStateDepBTrackingMode {
    /// Disabled
    Disabled = 0,

    /// Running
    Running = 1,
}

impl std::fmt::Display for TrackingChannelStateDepBTrackingMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            TrackingChannelStateDepBTrackingMode::Disabled => f.write_str("Disabled"),
            TrackingChannelStateDepBTrackingMode::Running => f.write_str("Running"),
        }
    }
}
