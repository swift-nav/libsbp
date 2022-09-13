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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgMeasurementState {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// ME signal tracking channel state
        #[cfg_attr(feature = "serde", serde(rename = "states"))]
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgTrackingIq {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Tracking channel of origin
        #[cfg_attr(feature = "serde", serde(rename = "channel"))]
        pub channel: u8,
        /// GNSS signal identifier
        #[cfg_attr(feature = "serde", serde(rename = "sid"))]
        pub sid: GnssSignal,
        /// Early, Prompt and Late correlations
        #[cfg_attr(feature = "serde", serde(rename = "corrs"))]
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgTrackingIqDepA {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Tracking channel of origin
        #[cfg_attr(feature = "serde", serde(rename = "channel"))]
        pub channel: u8,
        /// GNSS signal identifier
        #[cfg_attr(feature = "serde", serde(rename = "sid"))]
        pub sid: GnssSignalDep,
        /// Early, Prompt and Late correlations
        #[cfg_attr(feature = "serde", serde(rename = "corrs"))]
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgTrackingIqDepB {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Tracking channel of origin
        #[cfg_attr(feature = "serde", serde(rename = "channel"))]
        pub channel: u8,
        /// GNSS signal identifier
        #[cfg_attr(feature = "serde", serde(rename = "sid"))]
        pub sid: GnssSignal,
        /// Early, Prompt and Late correlations
        #[cfg_attr(feature = "serde", serde(rename = "corrs"))]
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgTrackingState {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Signal tracking channel state
        #[cfg_attr(feature = "serde", serde(rename = "states"))]
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgTrackingStateDepA {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Satellite tracking channel state
        #[cfg_attr(feature = "serde", serde(rename = "states"))]
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgTrackingStateDepB {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Signal tracking channel state
        #[cfg_attr(feature = "serde", serde(rename = "states"))]
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgTrackingStateDetailedDep {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Receiver clock time.
        #[cfg_attr(feature = "serde", serde(rename = "recv_time"))]
        pub recv_time: u64,
        /// Time of transmission of signal from satellite. TOW only valid when TOW
        /// status is decoded or propagated. WN only valid when week number valid
        /// flag is set.
        #[cfg_attr(feature = "serde", serde(rename = "tot"))]
        pub tot: GpsTimeDep,
        /// Pseudorange observation. Valid only when pseudorange valid flag is set.
        #[cfg_attr(feature = "serde", serde(rename = "P"))]
        pub p: u32,
        /// Pseudorange observation standard deviation. Valid only when pseudorange
        /// valid flag is set.
        #[cfg_attr(feature = "serde", serde(rename = "P_std"))]
        pub p_std: u16,
        /// Carrier phase observation with typical sign convention. Valid only when
        /// PLL pessimistic lock is achieved.
        #[cfg_attr(feature = "serde", serde(rename = "L"))]
        pub l: CarrierPhase,
        /// Carrier-to-Noise density
        #[cfg_attr(feature = "serde", serde(rename = "cn0"))]
        pub cn0: u8,
        /// Lock time. It is encoded according to DF402 from the RTCM 10403.2
        /// Amendment 2 specification. Valid values range from 0 to 15.
        #[cfg_attr(feature = "serde", serde(rename = "lock"))]
        pub lock: u16,
        /// GNSS signal identifier.
        #[cfg_attr(feature = "serde", serde(rename = "sid"))]
        pub sid: GnssSignalDep,
        /// Carrier Doppler frequency.
        #[cfg_attr(feature = "serde", serde(rename = "doppler"))]
        pub doppler: i32,
        /// Carrier Doppler frequency standard deviation.
        #[cfg_attr(feature = "serde", serde(rename = "doppler_std"))]
        pub doppler_std: u16,
        /// Number of seconds of continuous tracking. Specifies how much time signal
        /// is in continuous track.
        #[cfg_attr(feature = "serde", serde(rename = "uptime"))]
        pub uptime: u32,
        /// TCXO clock offset. Valid only when valid clock valid flag is set.
        #[cfg_attr(feature = "serde", serde(rename = "clock_offset"))]
        pub clock_offset: i16,
        /// TCXO clock drift. Valid only when valid clock valid flag is set.
        #[cfg_attr(feature = "serde", serde(rename = "clock_drift"))]
        pub clock_drift: i16,
        /// Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
        #[cfg_attr(feature = "serde", serde(rename = "corr_spacing"))]
        pub corr_spacing: u16,
        /// Acceleration. Valid only when acceleration valid flag is set.
        #[cfg_attr(feature = "serde", serde(rename = "acceleration"))]
        pub acceleration: i8,
        /// Synchronization status flags.
        #[cfg_attr(feature = "serde", serde(rename = "sync_flags"))]
        pub sync_flags: u8,
        /// TOW status flags.
        #[cfg_attr(feature = "serde", serde(rename = "tow_flags"))]
        pub tow_flags: u8,
        /// Tracking loop status flags.
        #[cfg_attr(feature = "serde", serde(rename = "track_flags"))]
        pub track_flags: u8,
        /// Navigation data status flags.
        #[cfg_attr(feature = "serde", serde(rename = "nav_flags"))]
        pub nav_flags: u8,
        /// Parameters sets flags.
        #[cfg_attr(feature = "serde", serde(rename = "pset_flags"))]
        pub pset_flags: u8,
        /// Miscellaneous flags.
        #[cfg_attr(feature = "serde", serde(rename = "misc_flags"))]
        pub misc_flags: u8,
    }

    impl MsgTrackingStateDetailedDep {
        /// Gets the [SynchronizationStatus][self::SynchronizationStatus] stored in the `sync_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `SynchronizationStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `SynchronizationStatus` were added.
        pub fn synchronization_status(&self) -> Result<SynchronizationStatus, u8> {
            get_bit_range!(self.sync_flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [SynchronizationStatus][SynchronizationStatus] of the `sync_flags` bitfield.
        pub fn set_synchronization_status(
            &mut self,
            synchronization_status: SynchronizationStatus,
        ) {
            set_bit_range!(&mut self.sync_flags, synchronization_status, u8, u8, 2, 0);
        }

        /// Gets the [WeekNumberValidityStatus][self::WeekNumberValidityStatus] stored in the `tow_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `WeekNumberValidityStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `WeekNumberValidityStatus` were added.
        pub fn week_number_validity_status(&self) -> Result<WeekNumberValidityStatus, u8> {
            get_bit_range!(self.tow_flags, u8, u8, 3, 3).try_into()
        }

        /// Set the bitrange corresponding to the [WeekNumberValidityStatus][WeekNumberValidityStatus] of the `tow_flags` bitfield.
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
                3
            );
        }

        /// Gets the [TowStatus][self::TowStatus] stored in the `tow_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TowStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TowStatus` were added.
        pub fn tow_status(&self) -> Result<TowStatus, u8> {
            get_bit_range!(self.tow_flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [TowStatus][TowStatus] of the `tow_flags` bitfield.
        pub fn set_tow_status(&mut self, tow_status: TowStatus) {
            set_bit_range!(&mut self.tow_flags, tow_status, u8, u8, 2, 0);
        }

        /// Gets the [FllStatus][self::FllStatus] stored in the `track_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FllStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FllStatus` were added.
        pub fn fll_status(&self) -> Result<FllStatus, u8> {
            get_bit_range!(self.track_flags, u8, u8, 4, 4).try_into()
        }

        /// Set the bitrange corresponding to the [FllStatus][FllStatus] of the `track_flags` bitfield.
        pub fn set_fll_status(&mut self, fll_status: FllStatus) {
            set_bit_range!(&mut self.track_flags, fll_status, u8, u8, 4, 4);
        }

        /// Gets the [PllStatus][self::PllStatus] stored in the `track_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `PllStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `PllStatus` were added.
        pub fn pll_status(&self) -> Result<PllStatus, u8> {
            get_bit_range!(self.track_flags, u8, u8, 3, 3).try_into()
        }

        /// Set the bitrange corresponding to the [PllStatus][PllStatus] of the `track_flags` bitfield.
        pub fn set_pll_status(&mut self, pll_status: PllStatus) {
            set_bit_range!(&mut self.track_flags, pll_status, u8, u8, 3, 3);
        }

        /// Gets the [TrackingLoopStatus][self::TrackingLoopStatus] stored in the `track_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TrackingLoopStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TrackingLoopStatus` were added.
        pub fn tracking_loop_status(&self) -> Result<TrackingLoopStatus, u8> {
            get_bit_range!(self.track_flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [TrackingLoopStatus][TrackingLoopStatus] of the `track_flags` bitfield.
        pub fn set_tracking_loop_status(&mut self, tracking_loop_status: TrackingLoopStatus) {
            set_bit_range!(&mut self.track_flags, tracking_loop_status, u8, u8, 2, 0);
        }

        /// Gets the [AlmanacAvailabilityStatus][self::AlmanacAvailabilityStatus] stored in the `nav_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `AlmanacAvailabilityStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `AlmanacAvailabilityStatus` were added.
        pub fn almanac_availability_status(&self) -> Result<AlmanacAvailabilityStatus, u8> {
            get_bit_range!(self.nav_flags, u8, u8, 4, 4).try_into()
        }

        /// Set the bitrange corresponding to the [AlmanacAvailabilityStatus][AlmanacAvailabilityStatus] of the `nav_flags` bitfield.
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
                4
            );
        }

        /// Gets the [EphemerisAvailabilityStatus][self::EphemerisAvailabilityStatus] stored in the `nav_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `EphemerisAvailabilityStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `EphemerisAvailabilityStatus` were added.
        pub fn ephemeris_availability_status(&self) -> Result<EphemerisAvailabilityStatus, u8> {
            get_bit_range!(self.nav_flags, u8, u8, 3, 3).try_into()
        }

        /// Set the bitrange corresponding to the [EphemerisAvailabilityStatus][EphemerisAvailabilityStatus] of the `nav_flags` bitfield.
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
                3
            );
        }

        /// Gets the [HealthStatus][self::HealthStatus] stored in the `nav_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `HealthStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `HealthStatus` were added.
        pub fn health_status(&self) -> Result<HealthStatus, u8> {
            get_bit_range!(self.nav_flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [HealthStatus][HealthStatus] of the `nav_flags` bitfield.
        pub fn set_health_status(&mut self, health_status: HealthStatus) {
            set_bit_range!(&mut self.nav_flags, health_status, u8, u8, 2, 0);
        }

        /// Gets the [ParameterSets][self::ParameterSets] stored in the `pset_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `ParameterSets` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `ParameterSets` were added.
        pub fn parameter_sets(&self) -> Result<ParameterSets, u8> {
            get_bit_range!(self.pset_flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [ParameterSets][ParameterSets] of the `pset_flags` bitfield.
        pub fn set_parameter_sets(&mut self, parameter_sets: ParameterSets) {
            set_bit_range!(&mut self.pset_flags, parameter_sets, u8, u8, 2, 0);
        }

        /// Gets the [ClockValidityStatus][self::ClockValidityStatus] stored in the `misc_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `ClockValidityStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `ClockValidityStatus` were added.
        pub fn clock_validity_status(&self) -> Result<ClockValidityStatus, u8> {
            get_bit_range!(self.misc_flags, u8, u8, 5, 5).try_into()
        }

        /// Set the bitrange corresponding to the [ClockValidityStatus][ClockValidityStatus] of the `misc_flags` bitfield.
        pub fn set_clock_validity_status(&mut self, clock_validity_status: ClockValidityStatus) {
            set_bit_range!(&mut self.misc_flags, clock_validity_status, u8, u8, 5, 5);
        }

        /// Gets the [PseudorangeValidityStatus][self::PseudorangeValidityStatus] stored in the `misc_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `PseudorangeValidityStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `PseudorangeValidityStatus` were added.
        pub fn pseudorange_validity_status(&self) -> Result<PseudorangeValidityStatus, u8> {
            get_bit_range!(self.misc_flags, u8, u8, 4, 4).try_into()
        }

        /// Set the bitrange corresponding to the [PseudorangeValidityStatus][PseudorangeValidityStatus] of the `misc_flags` bitfield.
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
                4
            );
        }

        /// Gets the [AccelerationValidityStatus][self::AccelerationValidityStatus] stored in the `misc_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `AccelerationValidityStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `AccelerationValidityStatus` were added.
        pub fn acceleration_validity_status(&self) -> Result<AccelerationValidityStatus, u8> {
            get_bit_range!(self.misc_flags, u8, u8, 3, 3).try_into()
        }

        /// Set the bitrange corresponding to the [AccelerationValidityStatus][AccelerationValidityStatus] of the `misc_flags` bitfield.
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
                3
            );
        }

        /// Gets the [CarrierHalfCycleAmbiguityStatus][self::CarrierHalfCycleAmbiguityStatus] stored in the `misc_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `CarrierHalfCycleAmbiguityStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `CarrierHalfCycleAmbiguityStatus` were added.
        pub fn carrier_half_cycle_ambiguity_status(
            &self,
        ) -> Result<CarrierHalfCycleAmbiguityStatus, u8> {
            get_bit_range!(self.misc_flags, u8, u8, 2, 2).try_into()
        }

        /// Set the bitrange corresponding to the [CarrierHalfCycleAmbiguityStatus][CarrierHalfCycleAmbiguityStatus] of the `misc_flags` bitfield.
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
                2
            );
        }

        /// Gets the [TrackingChannelStatus][self::TrackingChannelStatus] stored in the `misc_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TrackingChannelStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TrackingChannelStatus` were added.
        pub fn tracking_channel_status(&self) -> Result<TrackingChannelStatus, u8> {
            get_bit_range!(self.misc_flags, u8, u8, 1, 0).try_into()
        }

        /// Set the bitrange corresponding to the [TrackingChannelStatus][TrackingChannelStatus] of the `misc_flags` bitfield.
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for SynchronizationStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(SynchronizationStatus::NoSynchronization),
                1 => Ok(SynchronizationStatus::BitSynchronization),
                2 => Ok(SynchronizationStatus::WordSynchronization),
                3 => Ok(SynchronizationStatus::SubFrameSynchronizationMessageSynchronization),
                i => Err(i),
            }
        }
    }

    /// Week number validity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for WeekNumberValidityStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(WeekNumberValidityStatus::WeekNumberIsNotValid),
                1 => Ok(WeekNumberValidityStatus::WeekNumberIsValid),
                i => Err(i),
            }
        }
    }

    /// TOW status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for TowStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TowStatus::TowIsNotAvailable),
                1 => Ok(TowStatus::DecodedTowIsAvailable),
                2 => Ok(TowStatus::PropagatedTowIsAvailable),
                i => Err(i),
            }
        }
    }

    /// FLL status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for FllStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FllStatus::FllIsInactive),
                1 => Ok(FllStatus::FllIsActive),
                i => Err(i),
            }
        }
    }

    /// PLL status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for PllStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(PllStatus::PllIsInactive),
                1 => Ok(PllStatus::PllIsActive),
                i => Err(i),
            }
        }
    }

    /// Tracking loop status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for TrackingLoopStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TrackingLoopStatus::NoLocks),
                1 => Ok(TrackingLoopStatus::FlldllLock),
                2 => Ok(TrackingLoopStatus::PllOptimisticLock),
                3 => Ok(TrackingLoopStatus::PllPessimisticLock),
                i => Err(i),
            }
        }
    }

    /// Almanac availability status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for AlmanacAvailabilityStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(AlmanacAvailabilityStatus::AlmanacIsNotAvailable),
                1 => Ok(AlmanacAvailabilityStatus::AlmanacIsAvailable),
                i => Err(i),
            }
        }
    }

    /// Ephemeris availability status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for EphemerisAvailabilityStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(EphemerisAvailabilityStatus::EphemerisIsNotAvailable),
                1 => Ok(EphemerisAvailabilityStatus::EphemerisIsAvailable),
                i => Err(i),
            }
        }
    }

    /// Health status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for HealthStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(HealthStatus::HealthIsUnknown),
                1 => Ok(HealthStatus::SignalIsUnhealthy),
                2 => Ok(HealthStatus::SignalIsHealthy),
                i => Err(i),
            }
        }
    }

    /// Parameter sets.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for ParameterSets {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(ParameterSets::_1MsIntegrationTime),
                1 => Ok(ParameterSets::_5MsIntegrationTime),
                2 => Ok(ParameterSets::_10MsIntegrationTime),
                3 => Ok(ParameterSets::_20MsIntegrationTime),
                i => Err(i),
            }
        }
    }

    /// Clock validity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for ClockValidityStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(ClockValidityStatus::ClockOffsetAndDriftIsNotValid),
                1 => Ok(ClockValidityStatus::ClockOffsetAndDriftIsValid),
                i => Err(i),
            }
        }
    }

    /// Pseudorange validity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for PseudorangeValidityStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(PseudorangeValidityStatus::PseudorangeIsNotValid),
                1 => Ok(PseudorangeValidityStatus::PseudorangeIsValid),
                i => Err(i),
            }
        }
    }

    /// Acceleration validity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for AccelerationValidityStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(AccelerationValidityStatus::AccelerationIsNotValid),
                1 => Ok(AccelerationValidityStatus::AccelerationIsValid),
                i => Err(i),
            }
        }
    }

    /// Carrier half cycle ambiguity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for CarrierHalfCycleAmbiguityStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(CarrierHalfCycleAmbiguityStatus::Unresolved),
                1 => Ok(CarrierHalfCycleAmbiguityStatus::Resolved),
                i => Err(i),
            }
        }
    }

    /// Tracking channel status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for TrackingChannelStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TrackingChannelStatus::ReAcquisition),
                1 => Ok(TrackingChannelStatus::Running),
                i => Err(i),
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgTrackingStateDetailedDepA {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Receiver clock time.
        #[cfg_attr(feature = "serde", serde(rename = "recv_time"))]
        pub recv_time: u64,
        /// Time of transmission of signal from satellite. TOW only valid when TOW
        /// status is decoded or propagated. WN only valid when week number valid
        /// flag is set.
        #[cfg_attr(feature = "serde", serde(rename = "tot"))]
        pub tot: GpsTime,
        /// Pseudorange observation. Valid only when pseudorange valid flag is set.
        #[cfg_attr(feature = "serde", serde(rename = "P"))]
        pub p: u32,
        /// Pseudorange observation standard deviation. Valid only when pseudorange
        /// valid flag is set.
        #[cfg_attr(feature = "serde", serde(rename = "P_std"))]
        pub p_std: u16,
        /// Carrier phase observation with typical sign convention. Valid only when
        /// PLL pessimistic lock is achieved.
        #[cfg_attr(feature = "serde", serde(rename = "L"))]
        pub l: CarrierPhase,
        /// Carrier-to-Noise density
        #[cfg_attr(feature = "serde", serde(rename = "cn0"))]
        pub cn0: u8,
        /// Lock time. It is encoded according to DF402 from the RTCM 10403.2
        /// Amendment 2 specification. Valid values range from 0 to 15.
        #[cfg_attr(feature = "serde", serde(rename = "lock"))]
        pub lock: u16,
        /// GNSS signal identifier.
        #[cfg_attr(feature = "serde", serde(rename = "sid"))]
        pub sid: GnssSignal,
        /// Carrier Doppler frequency.
        #[cfg_attr(feature = "serde", serde(rename = "doppler"))]
        pub doppler: i32,
        /// Carrier Doppler frequency standard deviation.
        #[cfg_attr(feature = "serde", serde(rename = "doppler_std"))]
        pub doppler_std: u16,
        /// Number of seconds of continuous tracking. Specifies how much time signal
        /// is in continuous track.
        #[cfg_attr(feature = "serde", serde(rename = "uptime"))]
        pub uptime: u32,
        /// TCXO clock offset. Valid only when valid clock valid flag is set.
        #[cfg_attr(feature = "serde", serde(rename = "clock_offset"))]
        pub clock_offset: i16,
        /// TCXO clock drift. Valid only when valid clock valid flag is set.
        #[cfg_attr(feature = "serde", serde(rename = "clock_drift"))]
        pub clock_drift: i16,
        /// Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
        #[cfg_attr(feature = "serde", serde(rename = "corr_spacing"))]
        pub corr_spacing: u16,
        /// Acceleration. Valid only when acceleration valid flag is set.
        #[cfg_attr(feature = "serde", serde(rename = "acceleration"))]
        pub acceleration: i8,
        /// Synchronization status flags.
        #[cfg_attr(feature = "serde", serde(rename = "sync_flags"))]
        pub sync_flags: u8,
        /// TOW status flags.
        #[cfg_attr(feature = "serde", serde(rename = "tow_flags"))]
        pub tow_flags: u8,
        /// Tracking loop status flags.
        #[cfg_attr(feature = "serde", serde(rename = "track_flags"))]
        pub track_flags: u8,
        /// Navigation data status flags.
        #[cfg_attr(feature = "serde", serde(rename = "nav_flags"))]
        pub nav_flags: u8,
        /// Parameters sets flags.
        #[cfg_attr(feature = "serde", serde(rename = "pset_flags"))]
        pub pset_flags: u8,
        /// Miscellaneous flags.
        #[cfg_attr(feature = "serde", serde(rename = "misc_flags"))]
        pub misc_flags: u8,
    }

    impl MsgTrackingStateDetailedDepA {
        /// Gets the [SynchronizationStatus][self::SynchronizationStatus] stored in the `sync_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `SynchronizationStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `SynchronizationStatus` were added.
        pub fn synchronization_status(&self) -> Result<SynchronizationStatus, u8> {
            get_bit_range!(self.sync_flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [SynchronizationStatus][SynchronizationStatus] of the `sync_flags` bitfield.
        pub fn set_synchronization_status(
            &mut self,
            synchronization_status: SynchronizationStatus,
        ) {
            set_bit_range!(&mut self.sync_flags, synchronization_status, u8, u8, 2, 0);
        }

        /// Gets the [WeekNumberValidityStatus][self::WeekNumberValidityStatus] stored in the `tow_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `WeekNumberValidityStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `WeekNumberValidityStatus` were added.
        pub fn week_number_validity_status(&self) -> Result<WeekNumberValidityStatus, u8> {
            get_bit_range!(self.tow_flags, u8, u8, 3, 3).try_into()
        }

        /// Set the bitrange corresponding to the [WeekNumberValidityStatus][WeekNumberValidityStatus] of the `tow_flags` bitfield.
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
                3
            );
        }

        /// Gets the [TowStatus][self::TowStatus] stored in the `tow_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TowStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TowStatus` were added.
        pub fn tow_status(&self) -> Result<TowStatus, u8> {
            get_bit_range!(self.tow_flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [TowStatus][TowStatus] of the `tow_flags` bitfield.
        pub fn set_tow_status(&mut self, tow_status: TowStatus) {
            set_bit_range!(&mut self.tow_flags, tow_status, u8, u8, 2, 0);
        }

        /// Gets the [FllStatus][self::FllStatus] stored in the `track_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FllStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FllStatus` were added.
        pub fn fll_status(&self) -> Result<FllStatus, u8> {
            get_bit_range!(self.track_flags, u8, u8, 4, 4).try_into()
        }

        /// Set the bitrange corresponding to the [FllStatus][FllStatus] of the `track_flags` bitfield.
        pub fn set_fll_status(&mut self, fll_status: FllStatus) {
            set_bit_range!(&mut self.track_flags, fll_status, u8, u8, 4, 4);
        }

        /// Gets the [PllStatus][self::PllStatus] stored in the `track_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `PllStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `PllStatus` were added.
        pub fn pll_status(&self) -> Result<PllStatus, u8> {
            get_bit_range!(self.track_flags, u8, u8, 3, 3).try_into()
        }

        /// Set the bitrange corresponding to the [PllStatus][PllStatus] of the `track_flags` bitfield.
        pub fn set_pll_status(&mut self, pll_status: PllStatus) {
            set_bit_range!(&mut self.track_flags, pll_status, u8, u8, 3, 3);
        }

        /// Gets the [TrackingLoopStatus][self::TrackingLoopStatus] stored in the `track_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TrackingLoopStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TrackingLoopStatus` were added.
        pub fn tracking_loop_status(&self) -> Result<TrackingLoopStatus, u8> {
            get_bit_range!(self.track_flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [TrackingLoopStatus][TrackingLoopStatus] of the `track_flags` bitfield.
        pub fn set_tracking_loop_status(&mut self, tracking_loop_status: TrackingLoopStatus) {
            set_bit_range!(&mut self.track_flags, tracking_loop_status, u8, u8, 2, 0);
        }

        /// Gets the [AlmanacAvailabilityStatus][self::AlmanacAvailabilityStatus] stored in the `nav_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `AlmanacAvailabilityStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `AlmanacAvailabilityStatus` were added.
        pub fn almanac_availability_status(&self) -> Result<AlmanacAvailabilityStatus, u8> {
            get_bit_range!(self.nav_flags, u8, u8, 4, 4).try_into()
        }

        /// Set the bitrange corresponding to the [AlmanacAvailabilityStatus][AlmanacAvailabilityStatus] of the `nav_flags` bitfield.
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
                4
            );
        }

        /// Gets the [EphemerisAvailabilityStatus][self::EphemerisAvailabilityStatus] stored in the `nav_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `EphemerisAvailabilityStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `EphemerisAvailabilityStatus` were added.
        pub fn ephemeris_availability_status(&self) -> Result<EphemerisAvailabilityStatus, u8> {
            get_bit_range!(self.nav_flags, u8, u8, 3, 3).try_into()
        }

        /// Set the bitrange corresponding to the [EphemerisAvailabilityStatus][EphemerisAvailabilityStatus] of the `nav_flags` bitfield.
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
                3
            );
        }

        /// Gets the [HealthStatus][self::HealthStatus] stored in the `nav_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `HealthStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `HealthStatus` were added.
        pub fn health_status(&self) -> Result<HealthStatus, u8> {
            get_bit_range!(self.nav_flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [HealthStatus][HealthStatus] of the `nav_flags` bitfield.
        pub fn set_health_status(&mut self, health_status: HealthStatus) {
            set_bit_range!(&mut self.nav_flags, health_status, u8, u8, 2, 0);
        }

        /// Gets the [ParameterSets][self::ParameterSets] stored in the `pset_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `ParameterSets` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `ParameterSets` were added.
        pub fn parameter_sets(&self) -> Result<ParameterSets, u8> {
            get_bit_range!(self.pset_flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [ParameterSets][ParameterSets] of the `pset_flags` bitfield.
        pub fn set_parameter_sets(&mut self, parameter_sets: ParameterSets) {
            set_bit_range!(&mut self.pset_flags, parameter_sets, u8, u8, 2, 0);
        }

        /// Gets the [ClockValidityStatus][self::ClockValidityStatus] stored in the `misc_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `ClockValidityStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `ClockValidityStatus` were added.
        pub fn clock_validity_status(&self) -> Result<ClockValidityStatus, u8> {
            get_bit_range!(self.misc_flags, u8, u8, 5, 5).try_into()
        }

        /// Set the bitrange corresponding to the [ClockValidityStatus][ClockValidityStatus] of the `misc_flags` bitfield.
        pub fn set_clock_validity_status(&mut self, clock_validity_status: ClockValidityStatus) {
            set_bit_range!(&mut self.misc_flags, clock_validity_status, u8, u8, 5, 5);
        }

        /// Gets the [PseudorangeValidityStatus][self::PseudorangeValidityStatus] stored in the `misc_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `PseudorangeValidityStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `PseudorangeValidityStatus` were added.
        pub fn pseudorange_validity_status(&self) -> Result<PseudorangeValidityStatus, u8> {
            get_bit_range!(self.misc_flags, u8, u8, 4, 4).try_into()
        }

        /// Set the bitrange corresponding to the [PseudorangeValidityStatus][PseudorangeValidityStatus] of the `misc_flags` bitfield.
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
                4
            );
        }

        /// Gets the [AccelerationValidityStatus][self::AccelerationValidityStatus] stored in the `misc_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `AccelerationValidityStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `AccelerationValidityStatus` were added.
        pub fn acceleration_validity_status(&self) -> Result<AccelerationValidityStatus, u8> {
            get_bit_range!(self.misc_flags, u8, u8, 3, 3).try_into()
        }

        /// Set the bitrange corresponding to the [AccelerationValidityStatus][AccelerationValidityStatus] of the `misc_flags` bitfield.
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
                3
            );
        }

        /// Gets the [CarrierHalfCycleAmbiguityStatus][self::CarrierHalfCycleAmbiguityStatus] stored in the `misc_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `CarrierHalfCycleAmbiguityStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `CarrierHalfCycleAmbiguityStatus` were added.
        pub fn carrier_half_cycle_ambiguity_status(
            &self,
        ) -> Result<CarrierHalfCycleAmbiguityStatus, u8> {
            get_bit_range!(self.misc_flags, u8, u8, 2, 2).try_into()
        }

        /// Set the bitrange corresponding to the [CarrierHalfCycleAmbiguityStatus][CarrierHalfCycleAmbiguityStatus] of the `misc_flags` bitfield.
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
                2
            );
        }

        /// Gets the [TrackingChannelStatus][self::TrackingChannelStatus] stored in the `misc_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TrackingChannelStatus` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TrackingChannelStatus` were added.
        pub fn tracking_channel_status(&self) -> Result<TrackingChannelStatus, u8> {
            get_bit_range!(self.misc_flags, u8, u8, 1, 0).try_into()
        }

        /// Set the bitrange corresponding to the [TrackingChannelStatus][TrackingChannelStatus] of the `misc_flags` bitfield.
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for SynchronizationStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(SynchronizationStatus::NoSynchronization),
                1 => Ok(SynchronizationStatus::BitSynchronization),
                2 => Ok(SynchronizationStatus::WordSynchronization),
                3 => Ok(SynchronizationStatus::SubFrameSynchronizationMessageSynchronization),
                i => Err(i),
            }
        }
    }

    /// Week number validity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for WeekNumberValidityStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(WeekNumberValidityStatus::WeekNumberIsNotValid),
                1 => Ok(WeekNumberValidityStatus::WeekNumberIsValid),
                i => Err(i),
            }
        }
    }

    /// TOW status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for TowStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TowStatus::TowIsNotAvailable),
                1 => Ok(TowStatus::DecodedTowIsAvailable),
                2 => Ok(TowStatus::PropagatedTowIsAvailable),
                i => Err(i),
            }
        }
    }

    /// FLL status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for FllStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FllStatus::FllIsInactive),
                1 => Ok(FllStatus::FllIsActive),
                i => Err(i),
            }
        }
    }

    /// PLL status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for PllStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(PllStatus::PllIsInactive),
                1 => Ok(PllStatus::PllIsActive),
                i => Err(i),
            }
        }
    }

    /// Tracking loop status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for TrackingLoopStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TrackingLoopStatus::NoLocks),
                1 => Ok(TrackingLoopStatus::FlldllLock),
                2 => Ok(TrackingLoopStatus::PllOptimisticLock),
                3 => Ok(TrackingLoopStatus::PllPessimisticLock),
                i => Err(i),
            }
        }
    }

    /// Almanac availability status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for AlmanacAvailabilityStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(AlmanacAvailabilityStatus::AlmanacIsNotAvailable),
                1 => Ok(AlmanacAvailabilityStatus::AlmanacIsAvailable),
                i => Err(i),
            }
        }
    }

    /// Ephemeris availability status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for EphemerisAvailabilityStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(EphemerisAvailabilityStatus::EphemerisIsNotAvailable),
                1 => Ok(EphemerisAvailabilityStatus::EphemerisIsAvailable),
                i => Err(i),
            }
        }
    }

    /// Health status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for HealthStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(HealthStatus::HealthIsUnknown),
                1 => Ok(HealthStatus::SignalIsUnhealthy),
                2 => Ok(HealthStatus::SignalIsHealthy),
                i => Err(i),
            }
        }
    }

    /// Parameter sets.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for ParameterSets {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(ParameterSets::_1MsIntegrationTime),
                1 => Ok(ParameterSets::_5MsIntegrationTime),
                2 => Ok(ParameterSets::_10MsIntegrationTime),
                3 => Ok(ParameterSets::_20MsIntegrationTime),
                i => Err(i),
            }
        }
    }

    /// Clock validity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for ClockValidityStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(ClockValidityStatus::ClockOffsetAndDriftIsNotValid),
                1 => Ok(ClockValidityStatus::ClockOffsetAndDriftIsValid),
                i => Err(i),
            }
        }
    }

    /// Pseudorange validity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for PseudorangeValidityStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(PseudorangeValidityStatus::PseudorangeIsNotValid),
                1 => Ok(PseudorangeValidityStatus::PseudorangeIsValid),
                i => Err(i),
            }
        }
    }

    /// Acceleration validity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for AccelerationValidityStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(AccelerationValidityStatus::AccelerationIsNotValid),
                1 => Ok(AccelerationValidityStatus::AccelerationIsValid),
                i => Err(i),
            }
        }
    }

    /// Carrier half cycle ambiguity status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for CarrierHalfCycleAmbiguityStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(CarrierHalfCycleAmbiguityStatus::Unresolved),
                1 => Ok(CarrierHalfCycleAmbiguityStatus::Resolved),
                i => Err(i),
            }
        }
    }

    /// Tracking channel status.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for TrackingChannelStatus {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TrackingChannelStatus::ReAcquisition),
                1 => Ok(TrackingChannelStatus::Running),
                i => Err(i),
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MeasurementState {
        /// Measurement Engine GNSS signal being tracked (carries either Glonass FCN
        /// or SLOT)
        #[cfg_attr(feature = "serde", serde(rename = "mesid"))]
        pub mesid: GnssSignal,
        /// Carrier-to-Noise density.  Zero implies invalid cn0.
        #[cfg_attr(feature = "serde", serde(rename = "cn0"))]
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct TrackingChannelCorrelation {
        /// In-phase correlation
        #[cfg_attr(feature = "serde", serde(rename = "I"))]
        pub i: i16,
        /// Quadrature correlation
        #[cfg_attr(feature = "serde", serde(rename = "Q"))]
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct TrackingChannelCorrelationDep {
        /// In-phase correlation
        #[cfg_attr(feature = "serde", serde(rename = "I"))]
        pub i: i32,
        /// Quadrature correlation
        #[cfg_attr(feature = "serde", serde(rename = "Q"))]
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct TrackingChannelState {
        /// GNSS signal being tracked
        #[cfg_attr(feature = "serde", serde(rename = "sid"))]
        pub sid: GnssSignal,
        /// Frequency channel number (GLONASS only)
        #[cfg_attr(feature = "serde", serde(rename = "fcn"))]
        pub fcn: u8,
        /// Carrier-to-Noise density.  Zero implies invalid cn0.
        #[cfg_attr(feature = "serde", serde(rename = "cn0"))]
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct TrackingChannelStateDepA {
        /// Status of tracking channel
        #[cfg_attr(feature = "serde", serde(rename = "state"))]
        pub state: u8,
        /// PRN-1 being tracked
        #[cfg_attr(feature = "serde", serde(rename = "prn"))]
        pub prn: u8,
        /// Carrier-to-noise density
        #[cfg_attr(feature = "serde", serde(rename = "cn0"))]
        pub cn0: f32,
    }

    impl TrackingChannelStateDepA {
        /// Gets the [TrackingMode][self::TrackingMode] stored in the `state` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TrackingMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TrackingMode` were added.
        pub fn tracking_mode(&self) -> Result<TrackingMode, u8> {
            get_bit_range!(self.state, u8, u8, 1, 0).try_into()
        }

        /// Set the bitrange corresponding to the [TrackingMode][TrackingMode] of the `state` bitfield.
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for TrackingMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TrackingMode::Disabled),
                1 => Ok(TrackingMode::Running),
                i => Err(i),
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct TrackingChannelStateDepB {
        /// Status of tracking channel
        #[cfg_attr(feature = "serde", serde(rename = "state"))]
        pub state: u8,
        /// GNSS signal being tracked
        #[cfg_attr(feature = "serde", serde(rename = "sid"))]
        pub sid: GnssSignalDep,
        /// Carrier-to-noise density
        #[cfg_attr(feature = "serde", serde(rename = "cn0"))]
        pub cn0: f32,
    }

    impl TrackingChannelStateDepB {
        /// Gets the [TrackingMode][self::TrackingMode] stored in the `state` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TrackingMode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TrackingMode` were added.
        pub fn tracking_mode(&self) -> Result<TrackingMode, u8> {
            get_bit_range!(self.state, u8, u8, 1, 0).try_into()
        }

        /// Set the bitrange corresponding to the [TrackingMode][TrackingMode] of the `state` bitfield.
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
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
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

    impl TryFrom<u8> for TrackingMode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TrackingMode::Disabled),
                1 => Ok(TrackingMode::Running),
                i => Err(i),
            }
        }
    }
}
