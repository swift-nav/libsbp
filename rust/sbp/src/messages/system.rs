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
