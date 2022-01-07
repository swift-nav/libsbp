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
pub use measurement_state::MeasurementState;
pub use msg_measurement_state::MsgMeasurementState;
pub use msg_tracking_iq::MsgTrackingIq;
pub use msg_tracking_iq_dep_a::MsgTrackingIqDepA;
pub use msg_tracking_iq_dep_b::MsgTrackingIqDepB;
pub use msg_tracking_state::MsgTrackingState;
pub use msg_tracking_state_dep_a::MsgTrackingStateDepA;
pub use msg_tracking_state_dep_b::MsgTrackingStateDepB;
pub use msg_tracking_state_detailed_dep::MsgTrackingStateDetailedDep;
pub use msg_tracking_state_detailed_dep_a::MsgTrackingStateDetailedDepA;
pub use tracking_channel_correlation::TrackingChannelCorrelation;
pub use tracking_channel_correlation_dep::TrackingChannelCorrelationDep;
pub use tracking_channel_state::TrackingChannelState;
pub use tracking_channel_state_dep_a::TrackingChannelStateDepA;
pub use tracking_channel_state_dep_b::TrackingChannelStateDepB;

pub mod msg_measurement_state {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod msg_tracking_iq {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
            WireFormat::len(&self.channel)
                + WireFormat::len(&self.sid)
                + WireFormat::len(&self.corrs)
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
}

pub mod msg_tracking_iq_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
            WireFormat::len(&self.channel)
                + WireFormat::len(&self.sid)
                + WireFormat::len(&self.corrs)
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
}

pub mod msg_tracking_iq_dep_b {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
            WireFormat::len(&self.channel)
                + WireFormat::len(&self.sid)
                + WireFormat::len(&self.corrs)
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
}

pub mod msg_tracking_state {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod msg_tracking_state_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod msg_tracking_state_dep_b {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod msg_tracking_state_detailed_dep {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
        pub fn synchronization_status(&self) -> Option<SynchronizationStatus> {
            match get_bit_range!(self.sync_flags, u8, u8, 2, 0) {
                0 => Some(SynchronizationStatus::NoSynchronization),
                1 => Some(SynchronizationStatus::BitSynchronization),
                2 => Some(SynchronizationStatus::WordSynchronization),
                3 => Some(SynchronizationStatus::SubFrameSynchronizationMessageSynchronization),
                _ => None,
            }
        }

        pub fn set_synchronization_status(
            &mut self,
            synchronization_status: SynchronizationStatus,
        ) {
            set_bit_range!(&mut self.sync_flags, synchronization_status, u8, u8, 2, 0);
        }

        pub fn week_number_validity_status(&self) -> Option<WeekNumberValidityStatus> {
            match get_bit_range!(self.tow_flags, u8, u8, 3, 0) {
                0 => Some(WeekNumberValidityStatus::WeekNumberIsNotValid),
                1 => Some(WeekNumberValidityStatus::WeekNumberIsValid),
                _ => None,
            }
        }

        pub fn set_week_number_validity_status(
            &mut self,
            week_number_validity_status: WeekNumberValidityStatus,
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

        pub fn tow_status(&self) -> Option<TowStatus> {
            match get_bit_range!(self.tow_flags, u8, u8, 2, 0) {
                0 => Some(TowStatus::TowIsNotAvailable),
                1 => Some(TowStatus::DecodedTowIsAvailable),
                2 => Some(TowStatus::PropagatedTowIsAvailable),
                _ => None,
            }
        }

        pub fn set_tow_status(&mut self, tow_status: TowStatus) {
            set_bit_range!(&mut self.tow_flags, tow_status, u8, u8, 2, 0);
        }

        pub fn fll_status(&self) -> Option<FllStatus> {
            match get_bit_range!(self.track_flags, u8, u8, 4, 0) {
                0 => Some(FllStatus::FllIsInactive),
                1 => Some(FllStatus::FllIsActive),
                _ => None,
            }
        }

        pub fn set_fll_status(&mut self, fll_status: FllStatus) {
            set_bit_range!(&mut self.track_flags, fll_status, u8, u8, 4, 0);
        }

        pub fn pll_status(&self) -> Option<PllStatus> {
            match get_bit_range!(self.track_flags, u8, u8, 3, 0) {
                0 => Some(PllStatus::PllIsInactive),
                1 => Some(PllStatus::PllIsActive),
                _ => None,
            }
        }

        pub fn set_pll_status(&mut self, pll_status: PllStatus) {
            set_bit_range!(&mut self.track_flags, pll_status, u8, u8, 3, 0);
        }

        pub fn tracking_loop_status(&self) -> Option<TrackingLoopStatus> {
            match get_bit_range!(self.track_flags, u8, u8, 2, 0) {
                0 => Some(TrackingLoopStatus::NoLocks),
                1 => Some(TrackingLoopStatus::FlldllLock),
                2 => Some(TrackingLoopStatus::PllOptimisticLock),
                3 => Some(TrackingLoopStatus::PllPessimisticLock),
                _ => None,
            }
        }

        pub fn set_tracking_loop_status(&mut self, tracking_loop_status: TrackingLoopStatus) {
            set_bit_range!(&mut self.track_flags, tracking_loop_status, u8, u8, 2, 0);
        }

        pub fn almanac_availability_status(&self) -> Option<AlmanacAvailabilityStatus> {
            match get_bit_range!(self.nav_flags, u8, u8, 4, 0) {
                0 => Some(AlmanacAvailabilityStatus::AlmanacIsNotAvailable),
                1 => Some(AlmanacAvailabilityStatus::AlmanacIsAvailable),
                _ => None,
            }
        }

        pub fn set_almanac_availability_status(
            &mut self,
            almanac_availability_status: AlmanacAvailabilityStatus,
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

        pub fn ephemeris_availability_status(&self) -> Option<EphemerisAvailabilityStatus> {
            match get_bit_range!(self.nav_flags, u8, u8, 3, 0) {
                0 => Some(EphemerisAvailabilityStatus::EphemerisIsNotAvailable),
                1 => Some(EphemerisAvailabilityStatus::EphemerisIsAvailable),
                _ => None,
            }
        }

        pub fn set_ephemeris_availability_status(
            &mut self,
            ephemeris_availability_status: EphemerisAvailabilityStatus,
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

        pub fn health_status(&self) -> Option<HealthStatus> {
            match get_bit_range!(self.nav_flags, u8, u8, 2, 0) {
                0 => Some(HealthStatus::HealthIsUnknown),
                1 => Some(HealthStatus::SignalIsUnhealthy),
                2 => Some(HealthStatus::SignalIsHealthy),
                _ => None,
            }
        }

        pub fn set_health_status(&mut self, health_status: HealthStatus) {
            set_bit_range!(&mut self.nav_flags, health_status, u8, u8, 2, 0);
        }

        pub fn parameter_sets(&self) -> Option<ParameterSets> {
            match get_bit_range!(self.pset_flags, u8, u8, 2, 0) {
                0 => Some(ParameterSets::_1MsIntegrationTime),
                1 => Some(ParameterSets::_5MsIntegrationTime),
                2 => Some(ParameterSets::_10MsIntegrationTime),
                3 => Some(ParameterSets::_20MsIntegrationTime),
                _ => None,
            }
        }

        pub fn set_parameter_sets(&mut self, parameter_sets: ParameterSets) {
            set_bit_range!(&mut self.pset_flags, parameter_sets, u8, u8, 2, 0);
        }

        pub fn clock_validity_status(&self) -> Option<ClockValidityStatus> {
            match get_bit_range!(self.misc_flags, u8, u8, 5, 0) {
                0 => Some(ClockValidityStatus::ClockOffsetAndDriftIsNotValid),
                1 => Some(ClockValidityStatus::ClockOffsetAndDriftIsValid),
                _ => None,
            }
        }

        pub fn set_clock_validity_status(&mut self, clock_validity_status: ClockValidityStatus) {
            set_bit_range!(&mut self.misc_flags, clock_validity_status, u8, u8, 5, 0);
        }

        pub fn pseudorange_validity_status(&self) -> Option<PseudorangeValidityStatus> {
            match get_bit_range!(self.misc_flags, u8, u8, 4, 0) {
                0 => Some(PseudorangeValidityStatus::PseudorangeIsNotValid),
                1 => Some(PseudorangeValidityStatus::PseudorangeIsValid),
                _ => None,
            }
        }

        pub fn set_pseudorange_validity_status(
            &mut self,
            pseudorange_validity_status: PseudorangeValidityStatus,
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

        pub fn acceleration_validity_status(&self) -> Option<AccelerationValidityStatus> {
            match get_bit_range!(self.misc_flags, u8, u8, 3, 0) {
                0 => Some(AccelerationValidityStatus::AccelerationIsNotValid),
                1 => Some(AccelerationValidityStatus::AccelerationIsValid),
                _ => None,
            }
        }

        pub fn set_acceleration_validity_status(
            &mut self,
            acceleration_validity_status: AccelerationValidityStatus,
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
        ) -> Option<CarrierHalfCycleAmbiguityStatus> {
            match get_bit_range!(self.misc_flags, u8, u8, 2, 0) {
                0 => Some(CarrierHalfCycleAmbiguityStatus::Unresolved),
                1 => Some(CarrierHalfCycleAmbiguityStatus::Resolved),
                _ => None,
            }
        }

        pub fn set_carrier_half_cycle_ambiguity_status(
            &mut self,
            carrier_half_cycle_ambiguity_status: CarrierHalfCycleAmbiguityStatus,
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

        pub fn tracking_channel_status(&self) -> Option<TrackingChannelStatus> {
            match get_bit_range!(self.misc_flags, u8, u8, 1, 0) {
                0 => Some(TrackingChannelStatus::ReAcquisition),
                1 => Some(TrackingChannelStatus::Running),
                _ => None,
            }
        }

        pub fn set_tracking_channel_status(
            &mut self,
            tracking_channel_status: TrackingChannelStatus,
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
    pub enum SynchronizationStatus {
        /// No synchronization
        NoSynchronization = 0,

        /// Bit synchronization
        BitSynchronization = 1,

        /// Word synchronization (L1 C/A only)
        WordSynchronization = 2,

        /// Sub-frame synchronization (L1 C/A) / message synchronization (L2C)
        SubFrameSynchronizationMessageSynchronization = 3,
    }

    impl std::fmt::Display for SynchronizationStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                SynchronizationStatus::NoSynchronization => f.write_str("No synchronization"),
                SynchronizationStatus::BitSynchronization => f.write_str("Bit synchronization"),
                SynchronizationStatus::WordSynchronization => {
                    f.write_str("Word synchronization (L1 C/A only)")
                }
                SynchronizationStatus::SubFrameSynchronizationMessageSynchronization => f
                    .write_str(
                        "Sub-frame synchronization (L1 C/A) / message synchronization (L2C)
",
                    ),
            }
        }
    }

    /// Week number validity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum WeekNumberValidityStatus {
        /// Week number is not valid
        WeekNumberIsNotValid = 0,

        /// Week number is valid
        WeekNumberIsValid = 1,
    }

    impl std::fmt::Display for WeekNumberValidityStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                WeekNumberValidityStatus::WeekNumberIsNotValid => {
                    f.write_str("Week number is not valid")
                }
                WeekNumberValidityStatus::WeekNumberIsValid => f.write_str("Week number is valid"),
            }
        }
    }

    /// TOW status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum TowStatus {
        /// TOW is not available
        TowIsNotAvailable = 0,

        /// Decoded TOW is available
        DecodedTowIsAvailable = 1,

        /// Propagated TOW is available
        PropagatedTowIsAvailable = 2,
    }

    impl std::fmt::Display for TowStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TowStatus::TowIsNotAvailable => f.write_str("TOW is not available"),
                TowStatus::DecodedTowIsAvailable => f.write_str("Decoded TOW is available"),
                TowStatus::PropagatedTowIsAvailable => f.write_str("Propagated TOW is available"),
            }
        }
    }

    /// FLL status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum FllStatus {
        /// FLL is inactive
        FllIsInactive = 0,

        /// FLL is active
        FllIsActive = 1,
    }

    impl std::fmt::Display for FllStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FllStatus::FllIsInactive => f.write_str("FLL is inactive"),
                FllStatus::FllIsActive => f.write_str("FLL is active"),
            }
        }
    }

    /// PLL status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum PllStatus {
        /// PLL is inactive
        PllIsInactive = 0,

        /// PLL is active
        PllIsActive = 1,
    }

    impl std::fmt::Display for PllStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                PllStatus::PllIsInactive => f.write_str("PLL is inactive"),
                PllStatus::PllIsActive => f.write_str("PLL is active"),
            }
        }
    }

    /// Tracking loop status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum TrackingLoopStatus {
        /// No locks
        NoLocks = 0,

        /// FLL/DLL lock
        FlldllLock = 1,

        /// PLL optimistic lock
        PllOptimisticLock = 2,

        /// PLL pessimistic lock
        PllPessimisticLock = 3,
    }

    impl std::fmt::Display for TrackingLoopStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TrackingLoopStatus::NoLocks => f.write_str("No locks"),
                TrackingLoopStatus::FlldllLock => f.write_str("FLL/DLL lock"),
                TrackingLoopStatus::PllOptimisticLock => f.write_str("PLL optimistic lock"),
                TrackingLoopStatus::PllPessimisticLock => f.write_str("PLL pessimistic lock"),
            }
        }
    }

    /// Almanac availability status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum AlmanacAvailabilityStatus {
        /// Almanac is not available
        AlmanacIsNotAvailable = 0,

        /// Almanac is available
        AlmanacIsAvailable = 1,
    }

    impl std::fmt::Display for AlmanacAvailabilityStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                AlmanacAvailabilityStatus::AlmanacIsNotAvailable => {
                    f.write_str("Almanac is not available")
                }
                AlmanacAvailabilityStatus::AlmanacIsAvailable => {
                    f.write_str("Almanac is available")
                }
            }
        }
    }

    /// Ephemeris availability status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum EphemerisAvailabilityStatus {
        /// Ephemeris is not available
        EphemerisIsNotAvailable = 0,

        /// Ephemeris is available
        EphemerisIsAvailable = 1,
    }

    impl std::fmt::Display for EphemerisAvailabilityStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                EphemerisAvailabilityStatus::EphemerisIsNotAvailable => {
                    f.write_str("Ephemeris is not available")
                }
                EphemerisAvailabilityStatus::EphemerisIsAvailable => {
                    f.write_str("Ephemeris is available")
                }
            }
        }
    }

    /// Health status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum HealthStatus {
        /// Health is unknown
        HealthIsUnknown = 0,

        /// Signal is unhealthy
        SignalIsUnhealthy = 1,

        /// Signal is healthy
        SignalIsHealthy = 2,
    }

    impl std::fmt::Display for HealthStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                HealthStatus::HealthIsUnknown => f.write_str("Health is unknown"),
                HealthStatus::SignalIsUnhealthy => f.write_str("Signal is unhealthy"),
                HealthStatus::SignalIsHealthy => f.write_str("Signal is healthy"),
            }
        }
    }

    /// Parameter sets.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum ParameterSets {
        /// 1 ms integration time
        _1MsIntegrationTime = 0,

        /// 5 ms integration time
        _5MsIntegrationTime = 1,

        /// 10 ms integration time
        _10MsIntegrationTime = 2,

        /// 20 ms integration time
        _20MsIntegrationTime = 3,
    }

    impl std::fmt::Display for ParameterSets {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                ParameterSets::_1MsIntegrationTime => f.write_str("1 ms integration time"),
                ParameterSets::_5MsIntegrationTime => f.write_str("5 ms integration time"),
                ParameterSets::_10MsIntegrationTime => f.write_str("10 ms integration time"),
                ParameterSets::_20MsIntegrationTime => f.write_str("20 ms integration time"),
            }
        }
    }

    /// Clock validity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum ClockValidityStatus {
        /// Clock offset and drift is not valid
        ClockOffsetAndDriftIsNotValid = 0,

        /// Clock offset and drift is valid
        ClockOffsetAndDriftIsValid = 1,
    }

    impl std::fmt::Display for ClockValidityStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                ClockValidityStatus::ClockOffsetAndDriftIsNotValid => {
                    f.write_str("Clock offset and drift is not valid")
                }
                ClockValidityStatus::ClockOffsetAndDriftIsValid => {
                    f.write_str("Clock offset and drift is valid")
                }
            }
        }
    }

    /// Pseudorange validity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum PseudorangeValidityStatus {
        /// Pseudorange is not valid
        PseudorangeIsNotValid = 0,

        /// Pseudorange is valid
        PseudorangeIsValid = 1,
    }

    impl std::fmt::Display for PseudorangeValidityStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                PseudorangeValidityStatus::PseudorangeIsNotValid => {
                    f.write_str("Pseudorange is not valid")
                }
                PseudorangeValidityStatus::PseudorangeIsValid => {
                    f.write_str("Pseudorange is valid")
                }
            }
        }
    }

    /// Acceleration validity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum AccelerationValidityStatus {
        /// Acceleration is not valid
        AccelerationIsNotValid = 0,

        /// Acceleration is valid
        AccelerationIsValid = 1,
    }

    impl std::fmt::Display for AccelerationValidityStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                AccelerationValidityStatus::AccelerationIsNotValid => {
                    f.write_str("Acceleration is not valid")
                }
                AccelerationValidityStatus::AccelerationIsValid => {
                    f.write_str("Acceleration is valid")
                }
            }
        }
    }

    /// Carrier half cycle ambiguity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum CarrierHalfCycleAmbiguityStatus {
        /// Unresolved
        Unresolved = 0,

        /// Resolved
        Resolved = 1,
    }

    impl std::fmt::Display for CarrierHalfCycleAmbiguityStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                CarrierHalfCycleAmbiguityStatus::Unresolved => f.write_str("Unresolved"),
                CarrierHalfCycleAmbiguityStatus::Resolved => f.write_str("Resolved"),
            }
        }
    }

    /// Tracking channel status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum TrackingChannelStatus {
        /// Re-acquisition
        ReAcquisition = 0,

        /// Running
        Running = 1,
    }

    impl std::fmt::Display for TrackingChannelStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TrackingChannelStatus::ReAcquisition => f.write_str("Re-acquisition"),
                TrackingChannelStatus::Running => f.write_str("Running"),
            }
        }
    }
}

pub mod msg_tracking_state_detailed_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
        pub fn synchronization_status(&self) -> Option<SynchronizationStatus> {
            match get_bit_range!(self.sync_flags, u8, u8, 2, 0) {
                0 => Some(SynchronizationStatus::NoSynchronization),
                1 => Some(SynchronizationStatus::BitSynchronization),
                2 => Some(SynchronizationStatus::WordSynchronization),
                3 => Some(SynchronizationStatus::SubFrameSynchronizationMessageSynchronization),
                _ => None,
            }
        }

        pub fn set_synchronization_status(
            &mut self,
            synchronization_status: SynchronizationStatus,
        ) {
            set_bit_range!(&mut self.sync_flags, synchronization_status, u8, u8, 2, 0);
        }

        pub fn week_number_validity_status(&self) -> Option<WeekNumberValidityStatus> {
            match get_bit_range!(self.tow_flags, u8, u8, 3, 0) {
                0 => Some(WeekNumberValidityStatus::WeekNumberIsNotValid),
                1 => Some(WeekNumberValidityStatus::WeekNumberIsValid),
                _ => None,
            }
        }

        pub fn set_week_number_validity_status(
            &mut self,
            week_number_validity_status: WeekNumberValidityStatus,
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

        pub fn tow_status(&self) -> Option<TowStatus> {
            match get_bit_range!(self.tow_flags, u8, u8, 2, 0) {
                0 => Some(TowStatus::TowIsNotAvailable),
                1 => Some(TowStatus::DecodedTowIsAvailable),
                2 => Some(TowStatus::PropagatedTowIsAvailable),
                _ => None,
            }
        }

        pub fn set_tow_status(&mut self, tow_status: TowStatus) {
            set_bit_range!(&mut self.tow_flags, tow_status, u8, u8, 2, 0);
        }

        pub fn fll_status(&self) -> Option<FllStatus> {
            match get_bit_range!(self.track_flags, u8, u8, 4, 0) {
                0 => Some(FllStatus::FllIsInactive),
                1 => Some(FllStatus::FllIsActive),
                _ => None,
            }
        }

        pub fn set_fll_status(&mut self, fll_status: FllStatus) {
            set_bit_range!(&mut self.track_flags, fll_status, u8, u8, 4, 0);
        }

        pub fn pll_status(&self) -> Option<PllStatus> {
            match get_bit_range!(self.track_flags, u8, u8, 3, 0) {
                0 => Some(PllStatus::PllIsInactive),
                1 => Some(PllStatus::PllIsActive),
                _ => None,
            }
        }

        pub fn set_pll_status(&mut self, pll_status: PllStatus) {
            set_bit_range!(&mut self.track_flags, pll_status, u8, u8, 3, 0);
        }

        pub fn tracking_loop_status(&self) -> Option<TrackingLoopStatus> {
            match get_bit_range!(self.track_flags, u8, u8, 2, 0) {
                0 => Some(TrackingLoopStatus::NoLocks),
                1 => Some(TrackingLoopStatus::FlldllLock),
                2 => Some(TrackingLoopStatus::PllOptimisticLock),
                3 => Some(TrackingLoopStatus::PllPessimisticLock),
                _ => None,
            }
        }

        pub fn set_tracking_loop_status(&mut self, tracking_loop_status: TrackingLoopStatus) {
            set_bit_range!(&mut self.track_flags, tracking_loop_status, u8, u8, 2, 0);
        }

        pub fn almanac_availability_status(&self) -> Option<AlmanacAvailabilityStatus> {
            match get_bit_range!(self.nav_flags, u8, u8, 4, 0) {
                0 => Some(AlmanacAvailabilityStatus::AlmanacIsNotAvailable),
                1 => Some(AlmanacAvailabilityStatus::AlmanacIsAvailable),
                _ => None,
            }
        }

        pub fn set_almanac_availability_status(
            &mut self,
            almanac_availability_status: AlmanacAvailabilityStatus,
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

        pub fn ephemeris_availability_status(&self) -> Option<EphemerisAvailabilityStatus> {
            match get_bit_range!(self.nav_flags, u8, u8, 3, 0) {
                0 => Some(EphemerisAvailabilityStatus::EphemerisIsNotAvailable),
                1 => Some(EphemerisAvailabilityStatus::EphemerisIsAvailable),
                _ => None,
            }
        }

        pub fn set_ephemeris_availability_status(
            &mut self,
            ephemeris_availability_status: EphemerisAvailabilityStatus,
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

        pub fn health_status(&self) -> Option<HealthStatus> {
            match get_bit_range!(self.nav_flags, u8, u8, 2, 0) {
                0 => Some(HealthStatus::HealthIsUnknown),
                1 => Some(HealthStatus::SignalIsUnhealthy),
                2 => Some(HealthStatus::SignalIsHealthy),
                _ => None,
            }
        }

        pub fn set_health_status(&mut self, health_status: HealthStatus) {
            set_bit_range!(&mut self.nav_flags, health_status, u8, u8, 2, 0);
        }

        pub fn parameter_sets(&self) -> Option<ParameterSets> {
            match get_bit_range!(self.pset_flags, u8, u8, 2, 0) {
                0 => Some(ParameterSets::_1MsIntegrationTime),
                1 => Some(ParameterSets::_5MsIntegrationTime),
                2 => Some(ParameterSets::_10MsIntegrationTime),
                3 => Some(ParameterSets::_20MsIntegrationTime),
                _ => None,
            }
        }

        pub fn set_parameter_sets(&mut self, parameter_sets: ParameterSets) {
            set_bit_range!(&mut self.pset_flags, parameter_sets, u8, u8, 2, 0);
        }

        pub fn clock_validity_status(&self) -> Option<ClockValidityStatus> {
            match get_bit_range!(self.misc_flags, u8, u8, 5, 0) {
                0 => Some(ClockValidityStatus::ClockOffsetAndDriftIsNotValid),
                1 => Some(ClockValidityStatus::ClockOffsetAndDriftIsValid),
                _ => None,
            }
        }

        pub fn set_clock_validity_status(&mut self, clock_validity_status: ClockValidityStatus) {
            set_bit_range!(&mut self.misc_flags, clock_validity_status, u8, u8, 5, 0);
        }

        pub fn pseudorange_validity_status(&self) -> Option<PseudorangeValidityStatus> {
            match get_bit_range!(self.misc_flags, u8, u8, 4, 0) {
                0 => Some(PseudorangeValidityStatus::PseudorangeIsNotValid),
                1 => Some(PseudorangeValidityStatus::PseudorangeIsValid),
                _ => None,
            }
        }

        pub fn set_pseudorange_validity_status(
            &mut self,
            pseudorange_validity_status: PseudorangeValidityStatus,
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

        pub fn acceleration_validity_status(&self) -> Option<AccelerationValidityStatus> {
            match get_bit_range!(self.misc_flags, u8, u8, 3, 0) {
                0 => Some(AccelerationValidityStatus::AccelerationIsNotValid),
                1 => Some(AccelerationValidityStatus::AccelerationIsValid),
                _ => None,
            }
        }

        pub fn set_acceleration_validity_status(
            &mut self,
            acceleration_validity_status: AccelerationValidityStatus,
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
        ) -> Option<CarrierHalfCycleAmbiguityStatus> {
            match get_bit_range!(self.misc_flags, u8, u8, 2, 0) {
                0 => Some(CarrierHalfCycleAmbiguityStatus::Unresolved),
                1 => Some(CarrierHalfCycleAmbiguityStatus::Resolved),
                _ => None,
            }
        }

        pub fn set_carrier_half_cycle_ambiguity_status(
            &mut self,
            carrier_half_cycle_ambiguity_status: CarrierHalfCycleAmbiguityStatus,
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

        pub fn tracking_channel_status(&self) -> Option<TrackingChannelStatus> {
            match get_bit_range!(self.misc_flags, u8, u8, 1, 0) {
                0 => Some(TrackingChannelStatus::ReAcquisition),
                1 => Some(TrackingChannelStatus::Running),
                _ => None,
            }
        }

        pub fn set_tracking_channel_status(
            &mut self,
            tracking_channel_status: TrackingChannelStatus,
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
    pub enum SynchronizationStatus {
        /// No synchronization
        NoSynchronization = 0,

        /// Bit synchronization
        BitSynchronization = 1,

        /// Word synchronization (L1 C/A only)
        WordSynchronization = 2,

        /// Sub-frame synchronization (L1 C/A) / message synchronization (L2C)
        SubFrameSynchronizationMessageSynchronization = 3,
    }

    impl std::fmt::Display for SynchronizationStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                SynchronizationStatus::NoSynchronization => f.write_str("No synchronization"),
                SynchronizationStatus::BitSynchronization => f.write_str("Bit synchronization"),
                SynchronizationStatus::WordSynchronization => {
                    f.write_str("Word synchronization (L1 C/A only)")
                }
                SynchronizationStatus::SubFrameSynchronizationMessageSynchronization => f
                    .write_str(
                        "Sub-frame synchronization (L1 C/A) / message synchronization (L2C)
",
                    ),
            }
        }
    }

    /// Week number validity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum WeekNumberValidityStatus {
        /// Week number is not valid
        WeekNumberIsNotValid = 0,

        /// Week number is valid
        WeekNumberIsValid = 1,
    }

    impl std::fmt::Display for WeekNumberValidityStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                WeekNumberValidityStatus::WeekNumberIsNotValid => {
                    f.write_str("Week number is not valid")
                }
                WeekNumberValidityStatus::WeekNumberIsValid => f.write_str("Week number is valid"),
            }
        }
    }

    /// TOW status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum TowStatus {
        /// TOW is not available
        TowIsNotAvailable = 0,

        /// Decoded TOW is available
        DecodedTowIsAvailable = 1,

        /// Propagated TOW is available
        PropagatedTowIsAvailable = 2,
    }

    impl std::fmt::Display for TowStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TowStatus::TowIsNotAvailable => f.write_str("TOW is not available"),
                TowStatus::DecodedTowIsAvailable => f.write_str("Decoded TOW is available"),
                TowStatus::PropagatedTowIsAvailable => f.write_str("Propagated TOW is available"),
            }
        }
    }

    /// FLL status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum FllStatus {
        /// FLL is inactive
        FllIsInactive = 0,

        /// FLL is active
        FllIsActive = 1,
    }

    impl std::fmt::Display for FllStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FllStatus::FllIsInactive => f.write_str("FLL is inactive"),
                FllStatus::FllIsActive => f.write_str("FLL is active"),
            }
        }
    }

    /// PLL status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum PllStatus {
        /// PLL is inactive
        PllIsInactive = 0,

        /// PLL is active
        PllIsActive = 1,
    }

    impl std::fmt::Display for PllStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                PllStatus::PllIsInactive => f.write_str("PLL is inactive"),
                PllStatus::PllIsActive => f.write_str("PLL is active"),
            }
        }
    }

    /// Tracking loop status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum TrackingLoopStatus {
        /// No locks
        NoLocks = 0,

        /// FLL/DLL lock
        FlldllLock = 1,

        /// PLL optimistic lock
        PllOptimisticLock = 2,

        /// PLL pessimistic lock
        PllPessimisticLock = 3,
    }

    impl std::fmt::Display for TrackingLoopStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TrackingLoopStatus::NoLocks => f.write_str("No locks"),
                TrackingLoopStatus::FlldllLock => f.write_str("FLL/DLL lock"),
                TrackingLoopStatus::PllOptimisticLock => f.write_str("PLL optimistic lock"),
                TrackingLoopStatus::PllPessimisticLock => f.write_str("PLL pessimistic lock"),
            }
        }
    }

    /// Almanac availability status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum AlmanacAvailabilityStatus {
        /// Almanac is not available
        AlmanacIsNotAvailable = 0,

        /// Almanac is available
        AlmanacIsAvailable = 1,
    }

    impl std::fmt::Display for AlmanacAvailabilityStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                AlmanacAvailabilityStatus::AlmanacIsNotAvailable => {
                    f.write_str("Almanac is not available")
                }
                AlmanacAvailabilityStatus::AlmanacIsAvailable => {
                    f.write_str("Almanac is available")
                }
            }
        }
    }

    /// Ephemeris availability status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum EphemerisAvailabilityStatus {
        /// Ephemeris is not available
        EphemerisIsNotAvailable = 0,

        /// Ephemeris is available
        EphemerisIsAvailable = 1,
    }

    impl std::fmt::Display for EphemerisAvailabilityStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                EphemerisAvailabilityStatus::EphemerisIsNotAvailable => {
                    f.write_str("Ephemeris is not available")
                }
                EphemerisAvailabilityStatus::EphemerisIsAvailable => {
                    f.write_str("Ephemeris is available")
                }
            }
        }
    }

    /// Health status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum HealthStatus {
        /// Health is unknown
        HealthIsUnknown = 0,

        /// Signal is unhealthy
        SignalIsUnhealthy = 1,

        /// Signal is healthy
        SignalIsHealthy = 2,
    }

    impl std::fmt::Display for HealthStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                HealthStatus::HealthIsUnknown => f.write_str("Health is unknown"),
                HealthStatus::SignalIsUnhealthy => f.write_str("Signal is unhealthy"),
                HealthStatus::SignalIsHealthy => f.write_str("Signal is healthy"),
            }
        }
    }

    /// Parameter sets.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum ParameterSets {
        /// 1 ms integration time
        _1MsIntegrationTime = 0,

        /// 5 ms integration time
        _5MsIntegrationTime = 1,

        /// 10 ms integration time
        _10MsIntegrationTime = 2,

        /// 20 ms integration time
        _20MsIntegrationTime = 3,
    }

    impl std::fmt::Display for ParameterSets {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                ParameterSets::_1MsIntegrationTime => f.write_str("1 ms integration time"),
                ParameterSets::_5MsIntegrationTime => f.write_str("5 ms integration time"),
                ParameterSets::_10MsIntegrationTime => f.write_str("10 ms integration time"),
                ParameterSets::_20MsIntegrationTime => f.write_str("20 ms integration time"),
            }
        }
    }

    /// Clock validity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum ClockValidityStatus {
        /// Clock offset and drift is not valid
        ClockOffsetAndDriftIsNotValid = 0,

        /// Clock offset and drift is valid
        ClockOffsetAndDriftIsValid = 1,
    }

    impl std::fmt::Display for ClockValidityStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                ClockValidityStatus::ClockOffsetAndDriftIsNotValid => {
                    f.write_str("Clock offset and drift is not valid")
                }
                ClockValidityStatus::ClockOffsetAndDriftIsValid => {
                    f.write_str("Clock offset and drift is valid")
                }
            }
        }
    }

    /// Pseudorange validity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum PseudorangeValidityStatus {
        /// Pseudorange is not valid
        PseudorangeIsNotValid = 0,

        /// Pseudorange is valid
        PseudorangeIsValid = 1,
    }

    impl std::fmt::Display for PseudorangeValidityStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                PseudorangeValidityStatus::PseudorangeIsNotValid => {
                    f.write_str("Pseudorange is not valid")
                }
                PseudorangeValidityStatus::PseudorangeIsValid => {
                    f.write_str("Pseudorange is valid")
                }
            }
        }
    }

    /// Acceleration validity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum AccelerationValidityStatus {
        /// Acceleration is not valid
        AccelerationIsNotValid = 0,

        /// Acceleration is valid
        AccelerationIsValid = 1,
    }

    impl std::fmt::Display for AccelerationValidityStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                AccelerationValidityStatus::AccelerationIsNotValid => {
                    f.write_str("Acceleration is not valid")
                }
                AccelerationValidityStatus::AccelerationIsValid => {
                    f.write_str("Acceleration is valid")
                }
            }
        }
    }

    /// Carrier half cycle ambiguity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum CarrierHalfCycleAmbiguityStatus {
        /// Unresolved
        Unresolved = 0,

        /// Resolved
        Resolved = 1,
    }

    impl std::fmt::Display for CarrierHalfCycleAmbiguityStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                CarrierHalfCycleAmbiguityStatus::Unresolved => f.write_str("Unresolved"),
                CarrierHalfCycleAmbiguityStatus::Resolved => f.write_str("Resolved"),
            }
        }
    }

    /// Tracking channel status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq)]
    pub enum TrackingChannelStatus {
        /// Re-acquisition
        ReAcquisition = 0,

        /// Running
        Running = 1,
    }

    impl std::fmt::Display for TrackingChannelStatus {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TrackingChannelStatus::ReAcquisition => f.write_str("Re-acquisition"),
                TrackingChannelStatus::Running => f.write_str("Running"),
            }
        }
    }
}

pub mod measurement_state {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod tracking_channel_correlation {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod tracking_channel_correlation_dep {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod tracking_channel_state {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod tracking_channel_state_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
        pub fn tracking_mode(&self) -> Option<TrackingMode> {
            match get_bit_range!(self.state, u8, u8, 1, 0) {
                0 => Some(TrackingMode::Disabled),
                1 => Some(TrackingMode::Running),
                _ => None,
            }
        }

        pub fn set_tracking_mode(&mut self, tracking_mode: TrackingMode) {
            set_bit_range!(&mut self.state, tracking_mode, u8, u8, 1, 0);
        }
    }

    impl WireFormat for TrackingChannelStateDepA {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <f32 as WireFormat>::MIN_LEN;
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
    pub enum TrackingMode {
        /// Disabled
        Disabled = 0,

        /// Running
        Running = 1,
    }

    impl std::fmt::Display for TrackingMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TrackingMode::Disabled => f.write_str("Disabled"),
                TrackingMode::Running => f.write_str("Running"),
            }
        }
    }
}

pub mod tracking_channel_state_dep_b {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
        pub fn tracking_mode(&self) -> Option<TrackingMode> {
            match get_bit_range!(self.state, u8, u8, 1, 0) {
                0 => Some(TrackingMode::Disabled),
                1 => Some(TrackingMode::Running),
                _ => None,
            }
        }

        pub fn set_tracking_mode(&mut self, tracking_mode: TrackingMode) {
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
    pub enum TrackingMode {
        /// Disabled
        Disabled = 0,

        /// Running
        Running = 1,
    }

    impl std::fmt::Display for TrackingMode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TrackingMode::Disabled => f.write_str("Disabled"),
                TrackingMode::Running => f.write_str("Running"),
            }
        }
    }
}
