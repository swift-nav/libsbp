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
// Automatically generated from yaml/swiftnav/sbp/system.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Standardized system messages from Swift Navigation devices.

use super::lib::*;

/// Experimental telemetry message
///
/// The CSAC telemetry message has an implementation defined telemetry string
/// from a device. It is not produced or available on general Swift Products.
/// It is intended to be a low rate message for status purposes.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgCsacTelemetry {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Index representing the type of telemetry in use.  It is implementation
    /// defined.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "id")))]
    pub id: u8,
    /// Comma separated list of values as defined by the index
    #[cfg_attr(feature = "serde", serde(rename(serialize = "telemetry")))]
    pub telemetry: SbpString<Vec<u8>, Unterminated>,
}

impl ConcreteMessage for MsgCsacTelemetry {
    const MESSAGE_TYPE: u16 = 65284;
    const MESSAGE_NAME: &'static str = "MSG_CSAC_TELEMETRY";
}

impl SbpMessage for MsgCsacTelemetry {
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

impl TryFrom<Sbp> for MsgCsacTelemetry {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgCsacTelemetry(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgCsacTelemetry {
    const MIN_LEN: usize =
        <u8 as WireFormat>::MIN_LEN + <SbpString<Vec<u8>, Unterminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.id) + WireFormat::len(&self.telemetry)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.id, buf);
        WireFormat::write(&self.telemetry, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgCsacTelemetry {
            sender_id: None,
            id: WireFormat::parse_unchecked(buf),
            telemetry: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Experimental telemetry message labels
///
/// The CSAC telemetry message provides labels for each member of the string
/// produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a
/// lower rate than the MSG_CSAC_TELEMETRY.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgCsacTelemetryLabels {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Index representing the type of telemetry in use.  It is implementation
    /// defined.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "id")))]
    pub id: u8,
    /// Comma separated list of telemetry field values
    #[cfg_attr(feature = "serde", serde(rename(serialize = "telemetry_labels")))]
    pub telemetry_labels: SbpString<Vec<u8>, Unterminated>,
}

impl ConcreteMessage for MsgCsacTelemetryLabels {
    const MESSAGE_TYPE: u16 = 65285;
    const MESSAGE_NAME: &'static str = "MSG_CSAC_TELEMETRY_LABELS";
}

impl SbpMessage for MsgCsacTelemetryLabels {
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

impl TryFrom<Sbp> for MsgCsacTelemetryLabels {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgCsacTelemetryLabels(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgCsacTelemetryLabels {
    const MIN_LEN: usize =
        <u8 as WireFormat>::MIN_LEN + <SbpString<Vec<u8>, Unterminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.id) + WireFormat::len(&self.telemetry_labels)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.id, buf);
        WireFormat::write(&self.telemetry_labels, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgCsacTelemetryLabels {
            sender_id: None,
            id: WireFormat::parse_unchecked(buf),
            telemetry_labels: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Status of received corrections
///
/// This message provides information about the receipt of Differential
/// corrections.  It is expected to be sent with each receipt of a complete
/// corrections packet.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgDgnssStatus {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
    /// Latency of observation receipt
    #[cfg_attr(feature = "serde", serde(rename(serialize = "latency")))]
    pub latency: u16,
    /// Number of signals from base station
    #[cfg_attr(feature = "serde", serde(rename(serialize = "num_signals")))]
    pub num_signals: u8,
    /// Corrections source string
    #[cfg_attr(feature = "serde", serde(rename(serialize = "source")))]
    pub source: SbpString<Vec<u8>, Unterminated>,
}

impl MsgDgnssStatus {
    pub fn differential_type(&self) -> Option<MsgDgnssStatusDifferentialType> {
        match get_bit_range!(self.flags, u8, u8, 3, 0) {
            0 => Some(MsgDgnssStatusDifferentialType::Invalid),
            1 => Some(MsgDgnssStatusDifferentialType::CodeDifference),
            2 => Some(MsgDgnssStatusDifferentialType::RTK),
            _ => None,
        }
    }

    pub fn set_differential_type(&mut self, differential_type: MsgDgnssStatusDifferentialType) {
        set_bit_range!(&mut self.flags, differential_type, u8, u8, 3, 0);
    }
}

impl ConcreteMessage for MsgDgnssStatus {
    const MESSAGE_TYPE: u16 = 65282;
    const MESSAGE_NAME: &'static str = "MSG_DGNSS_STATUS";
}

impl SbpMessage for MsgDgnssStatus {
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

impl TryFrom<Sbp> for MsgDgnssStatus {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgDgnssStatus(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgDgnssStatus {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <SbpString<Vec<u8>, Unterminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.flags)
            + WireFormat::len(&self.latency)
            + WireFormat::len(&self.num_signals)
            + WireFormat::len(&self.source)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.flags, buf);
        WireFormat::write(&self.latency, buf);
        WireFormat::write(&self.num_signals, buf);
        WireFormat::write(&self.source, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgDgnssStatus {
            sender_id: None,
            flags: WireFormat::parse_unchecked(buf),
            latency: WireFormat::parse_unchecked(buf),
            num_signals: WireFormat::parse_unchecked(buf),
            source: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Differential type
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgDgnssStatusDifferentialType {
    /// Invalid
    Invalid = 0,

    /// Code Difference
    CodeDifference = 1,

    /// RTK
    RTK = 2,
}

impl std::fmt::Display for MsgDgnssStatusDifferentialType {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgDgnssStatusDifferentialType::Invalid => f.write_str("Invalid"),
            MsgDgnssStatusDifferentialType::CodeDifference => f.write_str("Code Difference"),
            MsgDgnssStatusDifferentialType::RTK => f.write_str("RTK"),
        }
    }
}

/// Offset of the local time with respect to GNSS time
///
/// The GNSS time offset message contains the information that is needed to
/// translate messages tagged with a local timestamp (e.g. IMU or wheeltick
/// messages) to GNSS time for the sender producing this message.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgGnssTimeOffset {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Weeks portion of the time offset
    #[cfg_attr(feature = "serde", serde(rename(serialize = "weeks")))]
    pub weeks: i16,
    /// Milliseconds portion of the time offset
    #[cfg_attr(feature = "serde", serde(rename(serialize = "milliseconds")))]
    pub milliseconds: i32,
    /// Microseconds portion of the time offset
    #[cfg_attr(feature = "serde", serde(rename(serialize = "microseconds")))]
    pub microseconds: i16,
    /// Status flags (reserved)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgGnssTimeOffset {
    const MESSAGE_TYPE: u16 = 65287;
    const MESSAGE_NAME: &'static str = "MSG_GNSS_TIME_OFFSET";
}

impl SbpMessage for MsgGnssTimeOffset {
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

impl TryFrom<Sbp> for MsgGnssTimeOffset {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgGnssTimeOffset(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgGnssTimeOffset {
    const MIN_LEN: usize = <i16 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.weeks)
            + WireFormat::len(&self.milliseconds)
            + WireFormat::len(&self.microseconds)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.weeks, buf);
        WireFormat::write(&self.milliseconds, buf);
        WireFormat::write(&self.microseconds, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgGnssTimeOffset {
            sender_id: None,
            weeks: WireFormat::parse_unchecked(buf),
            milliseconds: WireFormat::parse_unchecked(buf),
            microseconds: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Solution Group Metadata
///
/// This leading message lists the time metadata of the Solution Group. It
/// also lists the atomic contents (i.e. types of messages included) of the
/// Solution Group.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgGroupMeta {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss
    #[cfg_attr(feature = "serde", serde(rename(serialize = "group_id")))]
    pub group_id: u8,
    /// Status flags (reserved)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
    /// Size of list group_msgs
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_group_msgs")))]
    pub n_group_msgs: u8,
    /// An in-order list of message types included in the Solution Group,
    /// including GROUP_META itself
    #[cfg_attr(feature = "serde", serde(rename(serialize = "group_msgs")))]
    pub group_msgs: Vec<u16>,
}

impl MsgGroupMeta {
    pub fn solution_group_type(&self) -> Option<MsgGroupMetaSolutionGroupType> {
        match get_bit_range!(self.flags, u8, u8, 1, 0) {
            0 => Some(MsgGroupMetaSolutionGroupType::None),
            1 => Some(MsgGroupMetaSolutionGroupType::GnssOnly),
            2 => Some(MsgGroupMetaSolutionGroupType::GnssINS),
            _ => None,
        }
    }

    pub fn set_solution_group_type(&mut self, solution_group_type: MsgGroupMetaSolutionGroupType) {
        set_bit_range!(&mut self.flags, solution_group_type, u8, u8, 1, 0);
    }
}

impl ConcreteMessage for MsgGroupMeta {
    const MESSAGE_TYPE: u16 = 65290;
    const MESSAGE_NAME: &'static str = "MSG_GROUP_META";
}

impl SbpMessage for MsgGroupMeta {
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

impl TryFrom<Sbp> for MsgGroupMeta {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgGroupMeta(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgGroupMeta {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <Vec<u16> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.group_id)
            + WireFormat::len(&self.flags)
            + WireFormat::len(&self.n_group_msgs)
            + WireFormat::len(&self.group_msgs)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.group_id, buf);
        WireFormat::write(&self.flags, buf);
        WireFormat::write(&self.n_group_msgs, buf);
        WireFormat::write(&self.group_msgs, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgGroupMeta {
            sender_id: None,
            group_id: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
            n_group_msgs: WireFormat::parse_unchecked(buf),
            group_msgs: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Solution Group type
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgGroupMetaSolutionGroupType {
    /// None (invalid)
    None = 0,

    /// GNSS only
    GnssOnly = 1,

    /// GNSS+INS (Fuzed)
    GnssINS = 2,
}

impl std::fmt::Display for MsgGroupMetaSolutionGroupType {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgGroupMetaSolutionGroupType::None => f.write_str("None (invalid)"),
            MsgGroupMetaSolutionGroupType::GnssOnly => f.write_str("GNSS only"),
            MsgGroupMetaSolutionGroupType::GnssINS => f.write_str("GNSS+INS (Fuzed)"),
        }
    }
}

/// System heartbeat message
///
/// The heartbeat message is sent periodically to inform the host or other
/// attached devices that the system is running. It is used to monitor system
/// malfunctions. It also contains status flags that indicate to the host the
/// status of the system and whether it is operating correctly. Currently, the
/// expected heartbeat interval is 1 sec.
///
/// The system error flag is used to indicate that an error has occurred in
/// the system. To determine the source of the error, the remaining error
/// flags should be inspected.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgHeartbeat {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u32,
}

impl MsgHeartbeat {
    pub fn external_antenna_present(&self) -> Option<MsgHeartbeatExternalAntennaPresent> {
        match get_bit_range!(self.flags, u32, u8, 31, 0) {
            0 => Some(MsgHeartbeatExternalAntennaPresent::NoExternalAntennaDetected),
            1 => Some(MsgHeartbeatExternalAntennaPresent::ExternalAntennaIsPresent),
            _ => None,
        }
    }

    pub fn set_external_antenna_present(
        &mut self,
        external_antenna_present: MsgHeartbeatExternalAntennaPresent,
    ) {
        set_bit_range!(&mut self.flags, external_antenna_present, u32, u8, 31, 0);
    }

    pub fn external_antenna_short(&self) -> Option<MsgHeartbeatExternalAntennaShort> {
        match get_bit_range!(self.flags, u32, u8, 30, 0) {
            0 => Some(MsgHeartbeatExternalAntennaShort::NoShortDetected),
            1 => Some(MsgHeartbeatExternalAntennaShort::ShortDetected),
            _ => None,
        }
    }

    pub fn set_external_antenna_short(
        &mut self,
        external_antenna_short: MsgHeartbeatExternalAntennaShort,
    ) {
        set_bit_range!(&mut self.flags, external_antenna_short, u32, u8, 30, 0);
    }

    pub fn sbp_major_protocol_version_number(&self) -> u8 {
        get_bit_range!(self.flags, u32, u8, 23, 16)
    }

    pub fn set_sbp_major_protocol_version_number(&mut self, sbp_major_protocol_version_number: u8) {
        set_bit_range!(
            &mut self.flags,
            sbp_major_protocol_version_number,
            u32,
            u8,
            23,
            16
        );
    }

    pub fn sbp_minor_protocol_version_number(&self) -> u8 {
        get_bit_range!(self.flags, u32, u8, 15, 8)
    }

    pub fn set_sbp_minor_protocol_version_number(&mut self, sbp_minor_protocol_version_number: u8) {
        set_bit_range!(
            &mut self.flags,
            sbp_minor_protocol_version_number,
            u32,
            u8,
            15,
            8
        );
    }

    pub fn swift_nap_error(&self) -> Option<MsgHeartbeatSwiftNapError> {
        match get_bit_range!(self.flags, u32, u8, 2, 0) {
            0 => Some(MsgHeartbeatSwiftNapError::SystemHealthy),
            1 => Some(MsgHeartbeatSwiftNapError::AnErrorHasOccurredInTheSwiftNap),
            _ => None,
        }
    }

    pub fn set_swift_nap_error(&mut self, swift_nap_error: MsgHeartbeatSwiftNapError) {
        set_bit_range!(&mut self.flags, swift_nap_error, u32, u8, 2, 0);
    }

    pub fn io_error(&self) -> Option<MsgHeartbeatIoError> {
        match get_bit_range!(self.flags, u32, u8, 1, 0) {
            0 => Some(MsgHeartbeatIoError::SystemHealthy),
            1 => Some(MsgHeartbeatIoError::AnIoErrorHasOccurred),
            _ => None,
        }
    }

    pub fn set_io_error(&mut self, io_error: MsgHeartbeatIoError) {
        set_bit_range!(&mut self.flags, io_error, u32, u8, 1, 0);
    }

    pub fn system_error_flag(&self) -> Option<MsgHeartbeatSystemErrorFlag> {
        match get_bit_range!(self.flags, u32, u8, 0, 0) {
            0 => Some(MsgHeartbeatSystemErrorFlag::SystemHealthy),
            1 => Some(MsgHeartbeatSystemErrorFlag::AnErrorHasOccurred),
            _ => None,
        }
    }

    pub fn set_system_error_flag(&mut self, system_error_flag: MsgHeartbeatSystemErrorFlag) {
        set_bit_range!(&mut self.flags, system_error_flag, u32, u8, 0, 0);
    }
}

impl ConcreteMessage for MsgHeartbeat {
    const MESSAGE_TYPE: u16 = 65535;
    const MESSAGE_NAME: &'static str = "MSG_HEARTBEAT";
}

impl SbpMessage for MsgHeartbeat {
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

impl TryFrom<Sbp> for MsgHeartbeat {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgHeartbeat(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgHeartbeat {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgHeartbeat {
            sender_id: None,
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// External antenna present
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgHeartbeatExternalAntennaPresent {
    /// No external antenna detected
    NoExternalAntennaDetected = 0,

    /// External antenna is present
    ExternalAntennaIsPresent = 1,
}

impl std::fmt::Display for MsgHeartbeatExternalAntennaPresent {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgHeartbeatExternalAntennaPresent::NoExternalAntennaDetected => {
                f.write_str("No external antenna detected")
            }
            MsgHeartbeatExternalAntennaPresent::ExternalAntennaIsPresent => {
                f.write_str("External antenna is present")
            }
        }
    }
}

/// External antenna short
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgHeartbeatExternalAntennaShort {
    /// No short detected
    NoShortDetected = 0,

    /// Short detected
    ShortDetected = 1,
}

impl std::fmt::Display for MsgHeartbeatExternalAntennaShort {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgHeartbeatExternalAntennaShort::NoShortDetected => f.write_str("No short detected"),
            MsgHeartbeatExternalAntennaShort::ShortDetected => f.write_str("Short detected"),
        }
    }
}

/// SwiftNAP Error
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgHeartbeatSwiftNapError {
    /// System Healthy
    SystemHealthy = 0,

    /// An error has occurred in the SwiftNAP
    AnErrorHasOccurredInTheSwiftNap = 1,
}

impl std::fmt::Display for MsgHeartbeatSwiftNapError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgHeartbeatSwiftNapError::SystemHealthy => f.write_str("System Healthy"),
            MsgHeartbeatSwiftNapError::AnErrorHasOccurredInTheSwiftNap => {
                f.write_str("An error has occurred in the SwiftNAP")
            }
        }
    }
}

/// IO Error
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgHeartbeatIoError {
    /// System Healthy
    SystemHealthy = 0,

    /// An IO error has occurred
    AnIoErrorHasOccurred = 1,
}

impl std::fmt::Display for MsgHeartbeatIoError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgHeartbeatIoError::SystemHealthy => f.write_str("System Healthy"),
            MsgHeartbeatIoError::AnIoErrorHasOccurred => f.write_str("An IO error has occurred"),
        }
    }
}

/// System Error Flag
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgHeartbeatSystemErrorFlag {
    /// System Healthy
    SystemHealthy = 0,

    /// An error has occurred
    AnErrorHasOccurred = 1,
}

impl std::fmt::Display for MsgHeartbeatSystemErrorFlag {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgHeartbeatSystemErrorFlag::SystemHealthy => f.write_str("System Healthy"),
            MsgHeartbeatSystemErrorFlag::AnErrorHasOccurred => f.write_str("An error has occurred"),
        }
    }
}

/// Inertial Navigation System status message
///
/// The INS status message describes the state of the operation and
/// initialization of the inertial navigation system.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgInsStatus {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u32,
}

impl MsgInsStatus {
    pub fn ins_type(&self) -> Option<MsgInsStatusInsType> {
        match get_bit_range!(self.flags, u32, u8, 31, 29) {
            0 => Some(MsgInsStatusInsType::SmoothposeLooselyCoupled),
            1 => Some(MsgInsStatusInsType::Starling),
            _ => None,
        }
    }

    pub fn set_ins_type(&mut self, ins_type: MsgInsStatusInsType) {
        set_bit_range!(&mut self.flags, ins_type, u32, u8, 31, 29);
    }

    pub fn motion_state(&self) -> Option<MsgInsStatusMotionState> {
        match get_bit_range!(self.flags, u32, u8, 13, 11) {
            0 => Some(MsgInsStatusMotionState::UnknownOrInit),
            1 => Some(MsgInsStatusMotionState::ArbitraryMotion),
            2 => Some(MsgInsStatusMotionState::StraightMotion),
            3 => Some(MsgInsStatusMotionState::Stationary),
            _ => None,
        }
    }

    pub fn set_motion_state(&mut self, motion_state: MsgInsStatusMotionState) {
        set_bit_range!(&mut self.flags, motion_state, u32, u8, 13, 11);
    }

    pub fn odometry_synch(&self) -> Option<MsgInsStatusOdometrySynch> {
        match get_bit_range!(self.flags, u32, u8, 10, 0) {
            0 => Some(MsgInsStatusOdometrySynch::OdometryTimestampNominal),
            1 => Some(MsgInsStatusOdometrySynch::OdometryTimestampOutOfBounds),
            _ => None,
        }
    }

    pub fn set_odometry_synch(&mut self, odometry_synch: MsgInsStatusOdometrySynch) {
        set_bit_range!(&mut self.flags, odometry_synch, u32, u8, 10, 0);
    }

    pub fn odometry_status(&self) -> Option<MsgInsStatusOdometryStatus> {
        match get_bit_range!(self.flags, u32, u8, 9, 8) {
            0 => Some(MsgInsStatusOdometryStatus::NoOdometry),
            1 => Some(MsgInsStatusOdometryStatus::OdometryReceivedWithinLastSecond),
            2 => Some(MsgInsStatusOdometryStatus::OdometryNotReceivedWithinLastSecond),
            _ => None,
        }
    }

    pub fn set_odometry_status(&mut self, odometry_status: MsgInsStatusOdometryStatus) {
        set_bit_range!(&mut self.flags, odometry_status, u32, u8, 9, 8);
    }

    pub fn ins_error(&self) -> Option<MsgInsStatusInsError> {
        match get_bit_range!(self.flags, u32, u8, 7, 4) {
            1 => Some(MsgInsStatusInsError::ImuDataError),
            2 => Some(MsgInsStatusInsError::InsLicenseError),
            3 => Some(MsgInsStatusInsError::ImuCalibrationDataError),
            _ => None,
        }
    }

    pub fn set_ins_error(&mut self, ins_error: MsgInsStatusInsError) {
        set_bit_range!(&mut self.flags, ins_error, u32, u8, 7, 4);
    }

    pub fn gnss_fix(&self) -> Option<MsgInsStatusGnssFix> {
        match get_bit_range!(self.flags, u32, u8, 3, 0) {
            0 => Some(MsgInsStatusGnssFix::NoGnssFixAvailable),
            1 => Some(MsgInsStatusGnssFix::GnssFix),
            _ => None,
        }
    }

    pub fn set_gnss_fix(&mut self, gnss_fix: MsgInsStatusGnssFix) {
        set_bit_range!(&mut self.flags, gnss_fix, u32, u8, 3, 0);
    }

    pub fn mode(&self) -> Option<MsgInsStatusMode> {
        match get_bit_range!(self.flags, u32, u8, 2, 0) {
            0 => Some(MsgInsStatusMode::AwaitingInitialization),
            1 => Some(MsgInsStatusMode::DynamicallyAligning),
            2 => Some(MsgInsStatusMode::Ready),
            3 => Some(MsgInsStatusMode::GnssOutageExceedsMaxDuration),
            4 => Some(MsgInsStatusMode::FastStartSeeding),
            5 => Some(MsgInsStatusMode::FastStartValidating),
            6 => Some(MsgInsStatusMode::ValidatingUnsafeFastStartSeed),
            _ => None,
        }
    }

    pub fn set_mode(&mut self, mode: MsgInsStatusMode) {
        set_bit_range!(&mut self.flags, mode, u32, u8, 2, 0);
    }
}

impl ConcreteMessage for MsgInsStatus {
    const MESSAGE_TYPE: u16 = 65283;
    const MESSAGE_NAME: &'static str = "MSG_INS_STATUS";
}

impl SbpMessage for MsgInsStatus {
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

impl TryFrom<Sbp> for MsgInsStatus {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgInsStatus(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgInsStatus {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgInsStatus {
            sender_id: None,
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// INS Type
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgInsStatusInsType {
    /// Smoothpose Loosely Coupled
    SmoothposeLooselyCoupled = 0,

    /// Starling
    Starling = 1,
}

impl std::fmt::Display for MsgInsStatusInsType {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgInsStatusInsType::SmoothposeLooselyCoupled => {
                f.write_str("Smoothpose Loosely Coupled")
            }
            MsgInsStatusInsType::Starling => f.write_str("Starling"),
        }
    }
}

/// Motion State
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgInsStatusMotionState {
    /// Unknown or Init
    UnknownOrInit = 0,

    /// Arbitrary Motion
    ArbitraryMotion = 1,

    /// Straight Motion
    StraightMotion = 2,

    /// Stationary
    Stationary = 3,
}

impl std::fmt::Display for MsgInsStatusMotionState {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgInsStatusMotionState::UnknownOrInit => f.write_str("Unknown or Init"),
            MsgInsStatusMotionState::ArbitraryMotion => f.write_str("Arbitrary Motion"),
            MsgInsStatusMotionState::StraightMotion => f.write_str("Straight Motion"),
            MsgInsStatusMotionState::Stationary => f.write_str("Stationary"),
        }
    }
}

/// Odometry Synch
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgInsStatusOdometrySynch {
    /// Odometry timestamp nominal
    OdometryTimestampNominal = 0,

    /// Odometry timestamp out of bounds
    OdometryTimestampOutOfBounds = 1,
}

impl std::fmt::Display for MsgInsStatusOdometrySynch {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgInsStatusOdometrySynch::OdometryTimestampNominal => {
                f.write_str("Odometry timestamp nominal")
            }
            MsgInsStatusOdometrySynch::OdometryTimestampOutOfBounds => {
                f.write_str("Odometry timestamp out of bounds")
            }
        }
    }
}

/// Odometry status
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgInsStatusOdometryStatus {
    /// No Odometry
    NoOdometry = 0,

    /// Odometry received within last second
    OdometryReceivedWithinLastSecond = 1,

    /// Odometry not received within last second
    OdometryNotReceivedWithinLastSecond = 2,
}

impl std::fmt::Display for MsgInsStatusOdometryStatus {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgInsStatusOdometryStatus::NoOdometry => f.write_str("No Odometry"),
            MsgInsStatusOdometryStatus::OdometryReceivedWithinLastSecond => {
                f.write_str("Odometry received within last second")
            }
            MsgInsStatusOdometryStatus::OdometryNotReceivedWithinLastSecond => {
                f.write_str("Odometry not received within last second")
            }
        }
    }
}

/// INS Error
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgInsStatusInsError {
    /// IMU Data Error
    ImuDataError = 1,

    /// INS License Error
    InsLicenseError = 2,

    /// IMU Calibration Data Error
    ImuCalibrationDataError = 3,
}

impl std::fmt::Display for MsgInsStatusInsError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgInsStatusInsError::ImuDataError => f.write_str("IMU Data Error"),
            MsgInsStatusInsError::InsLicenseError => f.write_str("INS License Error"),
            MsgInsStatusInsError::ImuCalibrationDataError => {
                f.write_str("IMU Calibration Data Error")
            }
        }
    }
}

/// GNSS Fix
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgInsStatusGnssFix {
    /// No GNSS fix available
    NoGnssFixAvailable = 0,

    /// GNSS fix
    GnssFix = 1,
}

impl std::fmt::Display for MsgInsStatusGnssFix {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgInsStatusGnssFix::NoGnssFixAvailable => f.write_str("No GNSS fix available"),
            MsgInsStatusGnssFix::GnssFix => f.write_str("GNSS fix"),
        }
    }
}

/// Mode
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgInsStatusMode {
    /// Awaiting initialization
    AwaitingInitialization = 0,

    /// Dynamically aligning
    DynamicallyAligning = 1,

    /// Ready
    Ready = 2,

    /// GNSS Outage exceeds max duration
    GnssOutageExceedsMaxDuration = 3,

    /// FastStart seeding
    FastStartSeeding = 4,

    /// FastStart validating
    FastStartValidating = 5,

    /// Validating unsafe fast start seed
    ValidatingUnsafeFastStartSeed = 6,
}

impl std::fmt::Display for MsgInsStatusMode {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgInsStatusMode::AwaitingInitialization => f.write_str("Awaiting initialization"),
            MsgInsStatusMode::DynamicallyAligning => f.write_str("Dynamically aligning"),
            MsgInsStatusMode::Ready => f.write_str("Ready"),
            MsgInsStatusMode::GnssOutageExceedsMaxDuration => {
                f.write_str("GNSS Outage exceeds max duration")
            }
            MsgInsStatusMode::FastStartSeeding => f.write_str("FastStart seeding"),
            MsgInsStatusMode::FastStartValidating => f.write_str("FastStart validating"),
            MsgInsStatusMode::ValidatingUnsafeFastStartSeed => {
                f.write_str("Validating unsafe fast start seed")
            }
        }
    }
}

/// Inertial Navigation System update status message
///
/// The INS update status message contains information about executed and
/// rejected INS updates. This message is expected to be extended in the
/// future as new types of measurements are being added.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgInsUpdates {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// GNSS position update status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gnsspos")))]
    pub gnsspos: u8,
    /// GNSS velocity update status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gnssvel")))]
    pub gnssvel: u8,
    /// Wheelticks update status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "wheelticks")))]
    pub wheelticks: u8,
    /// Wheelticks update status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "speed")))]
    pub speed: u8,
    /// NHC update status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "nhc")))]
    pub nhc: u8,
    /// Zero velocity update status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "zerovel")))]
    pub zerovel: u8,
}

impl MsgInsUpdates {
    pub fn number_of_attempted_gnss_position_updates_since_last_message(&self) -> u8 {
        get_bit_range!(self.gnsspos, u8, u8, 7, 4)
    }

    pub fn set_number_of_attempted_gnss_position_updates_since_last_message(
        &mut self,
        number_of_attempted_gnss_position_updates_since_last_message: u8,
    ) {
        set_bit_range!(
            &mut self.gnsspos,
            number_of_attempted_gnss_position_updates_since_last_message,
            u8,
            u8,
            7,
            4
        );
    }

    pub fn number_of_rejected_gnss_position_updates_since_last_message(&self) -> u8 {
        get_bit_range!(self.gnsspos, u8, u8, 3, 0)
    }

    pub fn set_number_of_rejected_gnss_position_updates_since_last_message(
        &mut self,
        number_of_rejected_gnss_position_updates_since_last_message: u8,
    ) {
        set_bit_range!(
            &mut self.gnsspos,
            number_of_rejected_gnss_position_updates_since_last_message,
            u8,
            u8,
            3,
            0
        );
    }

    pub fn number_of_attempted_gnss_velocity_updates_since_last_message(&self) -> u8 {
        get_bit_range!(self.gnssvel, u8, u8, 7, 4)
    }

    pub fn set_number_of_attempted_gnss_velocity_updates_since_last_message(
        &mut self,
        number_of_attempted_gnss_velocity_updates_since_last_message: u8,
    ) {
        set_bit_range!(
            &mut self.gnssvel,
            number_of_attempted_gnss_velocity_updates_since_last_message,
            u8,
            u8,
            7,
            4
        );
    }

    pub fn number_of_rejected_gnss_velocity_updates_since_last_message(&self) -> u8 {
        get_bit_range!(self.gnssvel, u8, u8, 3, 0)
    }

    pub fn set_number_of_rejected_gnss_velocity_updates_since_last_message(
        &mut self,
        number_of_rejected_gnss_velocity_updates_since_last_message: u8,
    ) {
        set_bit_range!(
            &mut self.gnssvel,
            number_of_rejected_gnss_velocity_updates_since_last_message,
            u8,
            u8,
            3,
            0
        );
    }

    pub fn number_of_attempted_wheeltick_updates_since_last_message(&self) -> u8 {
        get_bit_range!(self.wheelticks, u8, u8, 7, 4)
    }

    pub fn set_number_of_attempted_wheeltick_updates_since_last_message(
        &mut self,
        number_of_attempted_wheeltick_updates_since_last_message: u8,
    ) {
        set_bit_range!(
            &mut self.wheelticks,
            number_of_attempted_wheeltick_updates_since_last_message,
            u8,
            u8,
            7,
            4
        );
    }

    pub fn number_of_rejected_wheeltick_updates_since_last_message(&self) -> u8 {
        get_bit_range!(self.wheelticks, u8, u8, 3, 0)
    }

    pub fn set_number_of_rejected_wheeltick_updates_since_last_message(
        &mut self,
        number_of_rejected_wheeltick_updates_since_last_message: u8,
    ) {
        set_bit_range!(
            &mut self.wheelticks,
            number_of_rejected_wheeltick_updates_since_last_message,
            u8,
            u8,
            3,
            0
        );
    }

    pub fn number_of_attempted_speed_updates_since_last_message(&self) -> u8 {
        get_bit_range!(self.speed, u8, u8, 7, 4)
    }

    pub fn set_number_of_attempted_speed_updates_since_last_message(
        &mut self,
        number_of_attempted_speed_updates_since_last_message: u8,
    ) {
        set_bit_range!(
            &mut self.speed,
            number_of_attempted_speed_updates_since_last_message,
            u8,
            u8,
            7,
            4
        );
    }

    pub fn number_of_rejected_speed_updates_since_last_message(&self) -> u8 {
        get_bit_range!(self.speed, u8, u8, 3, 0)
    }

    pub fn set_number_of_rejected_speed_updates_since_last_message(
        &mut self,
        number_of_rejected_speed_updates_since_last_message: u8,
    ) {
        set_bit_range!(
            &mut self.speed,
            number_of_rejected_speed_updates_since_last_message,
            u8,
            u8,
            3,
            0
        );
    }

    pub fn number_of_attempted_nhc_updates_since_last_message(&self) -> u8 {
        get_bit_range!(self.nhc, u8, u8, 7, 4)
    }

    pub fn set_number_of_attempted_nhc_updates_since_last_message(
        &mut self,
        number_of_attempted_nhc_updates_since_last_message: u8,
    ) {
        set_bit_range!(
            &mut self.nhc,
            number_of_attempted_nhc_updates_since_last_message,
            u8,
            u8,
            7,
            4
        );
    }

    pub fn number_of_rejected_nhc_updates_since_last_message(&self) -> u8 {
        get_bit_range!(self.nhc, u8, u8, 3, 0)
    }

    pub fn set_number_of_rejected_nhc_updates_since_last_message(
        &mut self,
        number_of_rejected_nhc_updates_since_last_message: u8,
    ) {
        set_bit_range!(
            &mut self.nhc,
            number_of_rejected_nhc_updates_since_last_message,
            u8,
            u8,
            3,
            0
        );
    }

    pub fn number_of_attempted_zero_velocity_updates_since_last_message(&self) -> u8 {
        get_bit_range!(self.zerovel, u8, u8, 7, 4)
    }

    pub fn set_number_of_attempted_zero_velocity_updates_since_last_message(
        &mut self,
        number_of_attempted_zero_velocity_updates_since_last_message: u8,
    ) {
        set_bit_range!(
            &mut self.zerovel,
            number_of_attempted_zero_velocity_updates_since_last_message,
            u8,
            u8,
            7,
            4
        );
    }

    pub fn number_of_rejected_zero_velocity_updates_since_last_message(&self) -> u8 {
        get_bit_range!(self.zerovel, u8, u8, 3, 0)
    }

    pub fn set_number_of_rejected_zero_velocity_updates_since_last_message(
        &mut self,
        number_of_rejected_zero_velocity_updates_since_last_message: u8,
    ) {
        set_bit_range!(
            &mut self.zerovel,
            number_of_rejected_zero_velocity_updates_since_last_message,
            u8,
            u8,
            3,
            0
        );
    }
}

impl ConcreteMessage for MsgInsUpdates {
    const MESSAGE_TYPE: u16 = 65286;
    const MESSAGE_NAME: &'static str = "MSG_INS_UPDATES";
}

impl SbpMessage for MsgInsUpdates {
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
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgInsUpdates {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgInsUpdates(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgInsUpdates {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.gnsspos)
            + WireFormat::len(&self.gnssvel)
            + WireFormat::len(&self.wheelticks)
            + WireFormat::len(&self.speed)
            + WireFormat::len(&self.nhc)
            + WireFormat::len(&self.zerovel)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.gnsspos, buf);
        WireFormat::write(&self.gnssvel, buf);
        WireFormat::write(&self.wheelticks, buf);
        WireFormat::write(&self.speed, buf);
        WireFormat::write(&self.nhc, buf);
        WireFormat::write(&self.zerovel, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgInsUpdates {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            gnsspos: WireFormat::parse_unchecked(buf),
            gnssvel: WireFormat::parse_unchecked(buf),
            wheelticks: WireFormat::parse_unchecked(buf),
            speed: WireFormat::parse_unchecked(buf),
            nhc: WireFormat::parse_unchecked(buf),
            zerovel: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Local time at detection of PPS pulse
///
/// The PPS time message contains the value of the sender's local time in
/// microseconds at the moment a pulse is detected on the PPS input. This is
/// to be used for syncronisation of sensor data sampled with a local
/// timestamp (e.g. IMU or wheeltick messages) where GNSS time is unknown to
/// the sender.
///
/// The local time used to timestamp the PPS pulse must be generated by the
/// same clock which is used to timestamp the IMU/wheel sensor data and should
/// follow the same roll-over rules.  A separate MSG_PPS_TIME message should
/// be sent for each source of sensor data which uses PPS-relative
/// timestamping.  The sender ID for each of these MSG_PPS_TIME messages
/// should match the sender ID of the respective sensor data.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgPpsTime {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Local time in microseconds
    #[cfg_attr(feature = "serde", serde(rename(serialize = "time")))]
    pub time: u64,
    /// Status flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl MsgPpsTime {
    pub fn reserved_set_to_zero(&self) -> u8 {
        get_bit_range!(self.flags, u8, u8, 7, 2)
    }

    pub fn set_reserved_set_to_zero(&mut self, reserved_set_to_zero: u8) {
        set_bit_range!(&mut self.flags, reserved_set_to_zero, u8, u8, 7, 2);
    }

    pub fn time_uncertainty(&self) -> Option<MsgPpsTimeTimeUncertainty> {
        match get_bit_range!(self.flags, u8, u8, 1, 0) {
            0 => Some(MsgPpsTimeTimeUncertainty::Unknown),
            1 => Some(MsgPpsTimeTimeUncertainty::_10Milliseconds),
            2 => Some(MsgPpsTimeTimeUncertainty::_10Microseconds),
            3 => Some(MsgPpsTimeTimeUncertainty::_1Microseconds),
            _ => None,
        }
    }

    pub fn set_time_uncertainty(&mut self, time_uncertainty: MsgPpsTimeTimeUncertainty) {
        set_bit_range!(&mut self.flags, time_uncertainty, u8, u8, 1, 0);
    }
}

impl ConcreteMessage for MsgPpsTime {
    const MESSAGE_TYPE: u16 = 65288;
    const MESSAGE_NAME: &'static str = "MSG_PPS_TIME";
}

impl SbpMessage for MsgPpsTime {
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

impl TryFrom<Sbp> for MsgPpsTime {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgPpsTime(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgPpsTime {
    const MIN_LEN: usize = <u64 as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.time) + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.time, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgPpsTime {
            sender_id: None,
            time: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Sensor state and update status data
///
/// This diagnostic message contains state and update status information for
/// all sensors that are being used by the fusion engine. This message will be
/// generated asynchronously to the solution messages and will be emitted
/// anytime a sensor update is being processed.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSensorAidEvent {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Update timestamp in milliseconds.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "time")))]
    pub time: u32,
    /// Sensor type
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sensor_type")))]
    pub sensor_type: u8,
    /// Sensor identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sensor_id")))]
    pub sensor_id: u16,
    /// Reserved for future use
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sensor_state")))]
    pub sensor_state: u8,
    /// Number of available measurements in this epoch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_available_meas")))]
    pub n_available_meas: u8,
    /// Number of attempted measurements in this epoch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_attempted_meas")))]
    pub n_attempted_meas: u8,
    /// Number of accepted measurements in this epoch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_accepted_meas")))]
    pub n_accepted_meas: u8,
    /// Reserved for future use
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u32,
}

impl ConcreteMessage for MsgSensorAidEvent {
    const MESSAGE_TYPE: u16 = 65289;
    const MESSAGE_NAME: &'static str = "MSG_SENSOR_AID_EVENT";
}

impl SbpMessage for MsgSensorAidEvent {
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

impl TryFrom<Sbp> for MsgSensorAidEvent {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSensorAidEvent(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSensorAidEvent {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.time)
            + WireFormat::len(&self.sensor_type)
            + WireFormat::len(&self.sensor_id)
            + WireFormat::len(&self.sensor_state)
            + WireFormat::len(&self.n_available_meas)
            + WireFormat::len(&self.n_attempted_meas)
            + WireFormat::len(&self.n_accepted_meas)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.time, buf);
        WireFormat::write(&self.sensor_type, buf);
        WireFormat::write(&self.sensor_id, buf);
        WireFormat::write(&self.sensor_state, buf);
        WireFormat::write(&self.n_available_meas, buf);
        WireFormat::write(&self.n_attempted_meas, buf);
        WireFormat::write(&self.n_accepted_meas, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSensorAidEvent {
            sender_id: None,
            time: WireFormat::parse_unchecked(buf),
            sensor_type: WireFormat::parse_unchecked(buf),
            sensor_id: WireFormat::parse_unchecked(buf),
            sensor_state: WireFormat::parse_unchecked(buf),
            n_available_meas: WireFormat::parse_unchecked(buf),
            n_attempted_meas: WireFormat::parse_unchecked(buf),
            n_accepted_meas: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// System start-up message
///
/// The system start-up message is sent once on system start-up. It notifies
/// the host or other attached devices that the system has started and is now
/// ready to respond to commands or configuration requests.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgStartup {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Cause of startup
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cause")))]
    pub cause: u8,
    /// Startup type
    #[cfg_attr(feature = "serde", serde(rename(serialize = "startup_type")))]
    pub startup_type: u8,
    /// Reserved
    #[cfg_attr(feature = "serde", serde(rename(serialize = "reserved")))]
    pub reserved: u16,
}

impl MsgStartup {
    pub fn cause_of_startup(&self) -> Option<MsgStartupCauseOfStartup> {
        match get_bit_range!(self.cause, u8, u8, 8, 0) {
            0 => Some(MsgStartupCauseOfStartup::PowerOn),
            1 => Some(MsgStartupCauseOfStartup::SoftwareReset),
            2 => Some(MsgStartupCauseOfStartup::WatchdogReset),
            _ => None,
        }
    }

    pub fn set_cause_of_startup(&mut self, cause_of_startup: MsgStartupCauseOfStartup) {
        set_bit_range!(&mut self.cause, cause_of_startup, u8, u8, 8, 0);
    }

    pub fn startup_type(&self) -> Option<MsgStartupStartupType> {
        match get_bit_range!(self.startup_type, u8, u8, 8, 0) {
            0 => Some(MsgStartupStartupType::ColdStart),
            1 => Some(MsgStartupStartupType::WarmStart),
            2 => Some(MsgStartupStartupType::HotStart),
            _ => None,
        }
    }

    pub fn set_startup_type(&mut self, startup_type: MsgStartupStartupType) {
        set_bit_range!(&mut self.startup_type, startup_type, u8, u8, 8, 0);
    }
}

impl ConcreteMessage for MsgStartup {
    const MESSAGE_TYPE: u16 = 65280;
    const MESSAGE_NAME: &'static str = "MSG_STARTUP";
}

impl SbpMessage for MsgStartup {
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

impl TryFrom<Sbp> for MsgStartup {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgStartup(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgStartup {
    const MIN_LEN: usize =
        <u8 as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN + <u16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.cause)
            + WireFormat::len(&self.startup_type)
            + WireFormat::len(&self.reserved)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.cause, buf);
        WireFormat::write(&self.startup_type, buf);
        WireFormat::write(&self.reserved, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgStartup {
            sender_id: None,
            cause: WireFormat::parse_unchecked(buf),
            startup_type: WireFormat::parse_unchecked(buf),
            reserved: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Cause of startup
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgStartupCauseOfStartup {
    /// Power on
    PowerOn = 0,

    /// Software reset
    SoftwareReset = 1,

    /// Watchdog reset
    WatchdogReset = 2,
}

impl std::fmt::Display for MsgStartupCauseOfStartup {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgStartupCauseOfStartup::PowerOn => f.write_str("Power on"),
            MsgStartupCauseOfStartup::SoftwareReset => f.write_str("Software reset"),
            MsgStartupCauseOfStartup::WatchdogReset => f.write_str("Watchdog reset"),
        }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgStartupStartupType {
    /// Cold start
    ColdStart = 0,

    /// Warm start
    WarmStart = 1,

    /// Hot start
    HotStart = 2,
}

impl std::fmt::Display for MsgStartupStartupType {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgStartupStartupType::ColdStart => f.write_str("Cold start"),
            MsgStartupStartupType::WarmStart => f.write_str("Warm start"),
            MsgStartupStartupType::HotStart => f.write_str("Hot start"),
        }
    }
}

/// Status report message
///
/// The status report is sent periodically to inform the host or other
/// attached devices that the system is running. It is used to monitor system
/// malfunctions. It contains status reports that indicate to the host the
/// status of each sub-system and whether it is operating correctly.
///
/// Interpretation of the subsystem specific status code is product dependent,
/// but if the generic status code is initializing, it should be ignored.
/// Refer to product documentation for details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgStatusReport {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Identity of reporting system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "reporting_system")))]
    pub reporting_system: u16,
    /// SBP protocol version
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sbp_version")))]
    pub sbp_version: u16,
    /// Increments on each status report sent
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sequence")))]
    pub sequence: u32,
    /// Number of seconds since system start-up
    #[cfg_attr(feature = "serde", serde(rename(serialize = "uptime")))]
    pub uptime: u32,
    /// Reported status of individual subsystems
    #[cfg_attr(feature = "serde", serde(rename(serialize = "status")))]
    pub status: Vec<SubSystemReport>,
}

impl MsgStatusReport {
    pub fn system(&self) -> Option<MsgStatusReportSystem> {
        match get_bit_range!(self.reporting_system, u16, u16, 15, 0) {
            0 => Some(MsgStatusReportSystem::Starling),
            1 => Some(MsgStatusReportSystem::PrecisionGnssModule),
            _ => None,
        }
    }

    pub fn set_system(&mut self, system: MsgStatusReportSystem) {
        set_bit_range!(&mut self.reporting_system, system, u16, u16, 15, 0);
    }

    pub fn sbp_major_protocol_version_number(&self) -> u8 {
        get_bit_range!(self.sbp_version, u16, u8, 16, 8)
    }

    pub fn set_sbp_major_protocol_version_number(&mut self, sbp_major_protocol_version_number: u8) {
        set_bit_range!(
            &mut self.sbp_version,
            sbp_major_protocol_version_number,
            u16,
            u8,
            16,
            8
        );
    }

    pub fn sbp_minor_protocol_version_number(&self) -> u8 {
        get_bit_range!(self.sbp_version, u16, u8, 7, 0)
    }

    pub fn set_sbp_minor_protocol_version_number(&mut self, sbp_minor_protocol_version_number: u8) {
        set_bit_range!(
            &mut self.sbp_version,
            sbp_minor_protocol_version_number,
            u16,
            u8,
            7,
            0
        );
    }
}

impl ConcreteMessage for MsgStatusReport {
    const MESSAGE_TYPE: u16 = 65534;
    const MESSAGE_NAME: &'static str = "MSG_STATUS_REPORT";
}

impl SbpMessage for MsgStatusReport {
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

impl TryFrom<Sbp> for MsgStatusReport {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgStatusReport(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgStatusReport {
    const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <Vec<SubSystemReport> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.reporting_system)
            + WireFormat::len(&self.sbp_version)
            + WireFormat::len(&self.sequence)
            + WireFormat::len(&self.uptime)
            + WireFormat::len(&self.status)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.reporting_system, buf);
        WireFormat::write(&self.sbp_version, buf);
        WireFormat::write(&self.sequence, buf);
        WireFormat::write(&self.uptime, buf);
        WireFormat::write(&self.status, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgStatusReport {
            sender_id: None,
            reporting_system: WireFormat::parse_unchecked(buf),
            sbp_version: WireFormat::parse_unchecked(buf),
            sequence: WireFormat::parse_unchecked(buf),
            uptime: WireFormat::parse_unchecked(buf),
            status: WireFormat::parse_unchecked(buf),
        }
    }
}

/// System
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum MsgStatusReportSystem {
    /// Starling
    Starling = 0,

    /// Precision GNSS Module (PGM)
    PrecisionGnssModule = 1,
}

impl std::fmt::Display for MsgStatusReportSystem {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MsgStatusReportSystem::Starling => f.write_str("Starling"),
            MsgStatusReportSystem::PrecisionGnssModule => {
                f.write_str("Precision GNSS Module (PGM)")
            }
        }
    }
}

/// Sub-system Status report
///
/// Report the general and specific state of a sub-system.  If the generic
/// state is reported as initializing, the specific state should be ignored.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct SubSystemReport {
    /// Identity of reporting subsystem
    #[cfg_attr(feature = "serde", serde(rename(serialize = "component")))]
    pub component: u16,
    /// Generic form status report
    #[cfg_attr(feature = "serde", serde(rename(serialize = "generic")))]
    pub generic: u8,
    /// Subsystem specific status code
    #[cfg_attr(feature = "serde", serde(rename(serialize = "specific")))]
    pub specific: u8,
}

impl SubSystemReport {
    pub fn subsystem(&self) -> Option<SubSystemReportSubsystem> {
        match get_bit_range!(self.component, u16, u16, 15, 0) {
            0 => Some(SubSystemReportSubsystem::PrimaryGnssAntenna),
            1 => Some(SubSystemReportSubsystem::MeasurementEngine),
            2 => Some(SubSystemReportSubsystem::CorrectionsClient),
            3 => Some(SubSystemReportSubsystem::DifferentialGnssEngine),
            4 => Some(SubSystemReportSubsystem::CAN),
            5 => Some(SubSystemReportSubsystem::WheelOdometry),
            6 => Some(SubSystemReportSubsystem::SensorFusionEngine),
            _ => None,
        }
    }

    pub fn set_subsystem(&mut self, subsystem: SubSystemReportSubsystem) {
        set_bit_range!(&mut self.component, subsystem, u16, u16, 15, 0);
    }

    pub fn generic(&self) -> Option<SubSystemReportGeneric> {
        match get_bit_range!(self.generic, u8, u8, 7, 0) {
            0 => Some(SubSystemReportGeneric::OKNominal),
            1 => Some(SubSystemReportGeneric::Initializing),
            2 => Some(SubSystemReportGeneric::Unknown),
            3 => Some(SubSystemReportGeneric::Degraded),
            4 => Some(SubSystemReportGeneric::Unusable),
            _ => None,
        }
    }

    pub fn set_generic(&mut self, generic: SubSystemReportGeneric) {
        set_bit_range!(&mut self.generic, generic, u8, u8, 7, 0);
    }
}

impl WireFormat for SubSystemReport {
    const MIN_LEN: usize =
        <u16 as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.component)
            + WireFormat::len(&self.generic)
            + WireFormat::len(&self.specific)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.component, buf);
        WireFormat::write(&self.generic, buf);
        WireFormat::write(&self.specific, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        SubSystemReport {
            component: WireFormat::parse_unchecked(buf),
            generic: WireFormat::parse_unchecked(buf),
            specific: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Subsystem
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum SubSystemReportSubsystem {
    /// Primary GNSS Antenna
    PrimaryGnssAntenna = 0,

    /// Measurement Engine
    MeasurementEngine = 1,

    /// Corrections Client
    CorrectionsClient = 2,

    /// Differential GNSS Engine
    DifferentialGnssEngine = 3,

    /// CAN
    CAN = 4,

    /// Wheel Odometry
    WheelOdometry = 5,

    /// Sensor Fusion Engine
    SensorFusionEngine = 6,
}

impl std::fmt::Display for SubSystemReportSubsystem {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            SubSystemReportSubsystem::PrimaryGnssAntenna => f.write_str("Primary GNSS Antenna"),
            SubSystemReportSubsystem::MeasurementEngine => f.write_str("Measurement Engine"),
            SubSystemReportSubsystem::CorrectionsClient => f.write_str("Corrections Client"),
            SubSystemReportSubsystem::DifferentialGnssEngine => {
                f.write_str("Differential GNSS Engine")
            }
            SubSystemReportSubsystem::CAN => f.write_str("CAN"),
            SubSystemReportSubsystem::WheelOdometry => f.write_str("Wheel Odometry"),
            SubSystemReportSubsystem::SensorFusionEngine => f.write_str("Sensor Fusion Engine"),
        }
    }
}

/// Generic
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum SubSystemReportGeneric {
    /// OK/Nominal
    OKNominal = 0,

    /// Initializing
    Initializing = 1,

    /// Unknown
    Unknown = 2,

    /// Degraded
    Degraded = 3,

    /// Unusable
    Unusable = 4,
}

impl std::fmt::Display for SubSystemReportGeneric {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            SubSystemReportGeneric::OKNominal => f.write_str("OK/Nominal"),
            SubSystemReportGeneric::Initializing => f.write_str("Initializing"),
            SubSystemReportGeneric::Unknown => f.write_str("Unknown"),
            SubSystemReportGeneric::Degraded => f.write_str("Degraded"),
            SubSystemReportGeneric::Unusable => f.write_str("Unusable"),
        }
    }
}
