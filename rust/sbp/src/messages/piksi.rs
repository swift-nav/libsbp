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
// Automatically generated from yaml/swiftnav/sbp/piksi.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! System health, configuration, and diagnostic messages specific to the
//! Piksi L1 receiver, including a variety of legacy messages that may no
//! longer be used.

use super::gnss::*;

use super::lib::*;

/// Receiver-to-base station latency
///
/// Statistics on the latency of observations received from the base station.
/// As observation packets are received their GPS time is compared to the
/// current GPS time calculated locally by the receiver to give a precise
/// measurement of the end-to-end communication latency in the system.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct Latency {
    /// Average latency
    #[cfg_attr(feature = "serde", serde(rename(serialize = "avg")))]
    pub avg: i32,
    /// Minimum latency
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lmin")))]
    pub lmin: i32,
    /// Maximum latency
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lmax")))]
    pub lmax: i32,
    /// Smoothed estimate of the current latency
    #[cfg_attr(feature = "serde", serde(rename(serialize = "current")))]
    pub current: i32,
}

impl WireFormat for Latency {
    const MIN_LEN: usize = <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.avg)
            + WireFormat::len(&self.lmin)
            + WireFormat::len(&self.lmax)
            + WireFormat::len(&self.current)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.avg, buf);
        WireFormat::write(&self.lmin, buf);
        WireFormat::write(&self.lmax, buf);
        WireFormat::write(&self.current, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        Latency {
            avg: WireFormat::parse_unchecked(buf),
            lmin: WireFormat::parse_unchecked(buf),
            lmax: WireFormat::parse_unchecked(buf),
            current: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Legacy message to load satellite almanac (host => Piksi)
///
/// This is a legacy message for sending and loading a satellite alamanac onto
/// the Piksi's flash memory from the host.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgAlmanac {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
}

impl ConcreteMessage for MsgAlmanac {
    const MESSAGE_TYPE: u16 = 105;
    const MESSAGE_NAME: &'static str = "MSG_ALMANAC";
}

impl SbpMessage for MsgAlmanac {
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

impl TryFrom<Sbp> for MsgAlmanac {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgAlmanac(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgAlmanac {
    const MIN_LEN: usize = 0;
    fn len(&self) -> usize {
        0
    }
    fn write<B: BufMut>(&self, _buf: &mut B) {}
    fn parse_unchecked<B: Buf>(_buf: &mut B) -> Self {
        MsgAlmanac { sender_id: None }
    }
}

/// Cell modem information update message
///
/// If a cell modem is present on a piksi device, this message will be send
/// periodically to update the host on the status of the modem and its various
/// parameters.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgCellModemStatus {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Received cell signal strength in dBm, zero translates to unknown
    #[cfg_attr(feature = "serde", serde(rename(serialize = "signal_strength")))]
    pub signal_strength: i8,
    /// BER as reported by the modem, zero translates to unknown
    #[cfg_attr(feature = "serde", serde(rename(serialize = "signal_error_rate")))]
    pub signal_error_rate: f32,
    /// Unspecified data TBD for this schema
    #[cfg_attr(feature = "serde", serde(rename(serialize = "reserved")))]
    pub reserved: Vec<u8>,
}

impl ConcreteMessage for MsgCellModemStatus {
    const MESSAGE_TYPE: u16 = 190;
    const MESSAGE_NAME: &'static str = "MSG_CELL_MODEM_STATUS";
}

impl SbpMessage for MsgCellModemStatus {
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

impl TryFrom<Sbp> for MsgCellModemStatus {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgCellModemStatus(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgCellModemStatus {
    const MIN_LEN: usize = <i8 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <Vec<u8> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.signal_strength)
            + WireFormat::len(&self.signal_error_rate)
            + WireFormat::len(&self.reserved)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.signal_strength, buf);
        WireFormat::write(&self.signal_error_rate, buf);
        WireFormat::write(&self.reserved, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgCellModemStatus {
            sender_id: None,
            signal_strength: WireFormat::parse_unchecked(buf),
            signal_error_rate: WireFormat::parse_unchecked(buf),
            reserved: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Command output
///
/// Returns the standard output and standard error of the command requested by
/// MSG_COMMAND_REQ. The sequence number can be used to filter for filtering
/// the correct command.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgCommandOutput {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Sequence number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sequence")))]
    pub sequence: u32,
    /// Line of standard output or standard error
    #[cfg_attr(feature = "serde", serde(rename(serialize = "line")))]
    pub line: SbpString<Vec<u8>, Unterminated>,
}

impl ConcreteMessage for MsgCommandOutput {
    const MESSAGE_TYPE: u16 = 188;
    const MESSAGE_NAME: &'static str = "MSG_COMMAND_OUTPUT";
}

impl SbpMessage for MsgCommandOutput {
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

impl TryFrom<Sbp> for MsgCommandOutput {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgCommandOutput(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgCommandOutput {
    const MIN_LEN: usize =
        <u32 as WireFormat>::MIN_LEN + <SbpString<Vec<u8>, Unterminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sequence) + WireFormat::len(&self.line)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sequence, buf);
        WireFormat::write(&self.line, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgCommandOutput {
            sender_id: None,
            sequence: WireFormat::parse_unchecked(buf),
            line: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Execute a command (host => device)
///
/// Request the recipient to execute an command. Output will be sent in
/// MSG_LOG messages, and the exit code will be returned with
/// MSG_COMMAND_RESP.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgCommandReq {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Sequence number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sequence")))]
    pub sequence: u32,
    /// Command line to execute
    #[cfg_attr(feature = "serde", serde(rename(serialize = "command")))]
    pub command: SbpString<Vec<u8>, NullTerminated>,
}

impl ConcreteMessage for MsgCommandReq {
    const MESSAGE_TYPE: u16 = 184;
    const MESSAGE_NAME: &'static str = "MSG_COMMAND_REQ";
}

impl SbpMessage for MsgCommandReq {
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

impl TryFrom<Sbp> for MsgCommandReq {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgCommandReq(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgCommandReq {
    const MIN_LEN: usize =
        <u32 as WireFormat>::MIN_LEN + <SbpString<Vec<u8>, NullTerminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sequence) + WireFormat::len(&self.command)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sequence, buf);
        WireFormat::write(&self.command, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgCommandReq {
            sender_id: None,
            sequence: WireFormat::parse_unchecked(buf),
            command: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Exit code from executed command (device => host)
///
/// The response to MSG_COMMAND_REQ with the return code of the command.  A
/// return code of zero indicates success.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgCommandResp {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Sequence number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sequence")))]
    pub sequence: u32,
    /// Exit code
    #[cfg_attr(feature = "serde", serde(rename(serialize = "code")))]
    pub code: i32,
}

impl ConcreteMessage for MsgCommandResp {
    const MESSAGE_TYPE: u16 = 185;
    const MESSAGE_NAME: &'static str = "MSG_COMMAND_RESP";
}

impl SbpMessage for MsgCommandResp {
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

impl TryFrom<Sbp> for MsgCommandResp {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgCommandResp(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgCommandResp {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN + <i32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sequence) + WireFormat::len(&self.code)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sequence, buf);
        WireFormat::write(&self.code, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgCommandResp {
            sender_id: None,
            sequence: WireFormat::parse_unchecked(buf),
            code: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Legacy message for CW interference channel (Piksi => host)
///
/// This is an unused legacy message for result reporting from the CW
/// interference channel on the SwiftNAP. This message will be removed in a
/// future release.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgCwResults {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
}

impl ConcreteMessage for MsgCwResults {
    const MESSAGE_TYPE: u16 = 192;
    const MESSAGE_NAME: &'static str = "MSG_CW_RESULTS";
}

impl SbpMessage for MsgCwResults {
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

impl TryFrom<Sbp> for MsgCwResults {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgCwResults(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgCwResults {
    const MIN_LEN: usize = 0;
    fn len(&self) -> usize {
        0
    }
    fn write<B: BufMut>(&self, _buf: &mut B) {}
    fn parse_unchecked<B: Buf>(_buf: &mut B) -> Self {
        MsgCwResults { sender_id: None }
    }
}

/// Legacy message for CW interference channel (host => Piksi)
///
/// This is an unused legacy message from the host for starting the CW
/// interference channel on the SwiftNAP. This message will be removed in a
/// future release.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgCwStart {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
}

impl ConcreteMessage for MsgCwStart {
    const MESSAGE_TYPE: u16 = 193;
    const MESSAGE_NAME: &'static str = "MSG_CW_START";
}

impl SbpMessage for MsgCwStart {
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

impl TryFrom<Sbp> for MsgCwStart {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgCwStart(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgCwStart {
    const MIN_LEN: usize = 0;
    fn len(&self) -> usize {
        0
    }
    fn write<B: BufMut>(&self, _buf: &mut B) {}
    fn parse_unchecked<B: Buf>(_buf: &mut B) -> Self {
        MsgCwStart { sender_id: None }
    }
}

/// Device temperature and voltage levels
///
/// This message contains temperature and voltage level measurements from the
/// processor's monitoring system and the RF frontend die temperature if
/// available.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgDeviceMonitor {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Device V_in
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dev_vin")))]
    pub dev_vin: i16,
    /// Processor V_int
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cpu_vint")))]
    pub cpu_vint: i16,
    /// Processor V_aux
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cpu_vaux")))]
    pub cpu_vaux: i16,
    /// Processor temperature
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cpu_temperature")))]
    pub cpu_temperature: i16,
    /// Frontend temperature (if available)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "fe_temperature")))]
    pub fe_temperature: i16,
}

impl ConcreteMessage for MsgDeviceMonitor {
    const MESSAGE_TYPE: u16 = 181;
    const MESSAGE_NAME: &'static str = "MSG_DEVICE_MONITOR";
}

impl SbpMessage for MsgDeviceMonitor {
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

impl TryFrom<Sbp> for MsgDeviceMonitor {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgDeviceMonitor(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgDeviceMonitor {
    const MIN_LEN: usize = <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.dev_vin)
            + WireFormat::len(&self.cpu_vint)
            + WireFormat::len(&self.cpu_vaux)
            + WireFormat::len(&self.cpu_temperature)
            + WireFormat::len(&self.fe_temperature)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.dev_vin, buf);
        WireFormat::write(&self.cpu_vint, buf);
        WireFormat::write(&self.cpu_vaux, buf);
        WireFormat::write(&self.cpu_temperature, buf);
        WireFormat::write(&self.fe_temperature, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgDeviceMonitor {
            sender_id: None,
            dev_vin: WireFormat::parse_unchecked(buf),
            cpu_vint: WireFormat::parse_unchecked(buf),
            cpu_vaux: WireFormat::parse_unchecked(buf),
            cpu_temperature: WireFormat::parse_unchecked(buf),
            fe_temperature: WireFormat::parse_unchecked(buf),
        }
    }
}

/// RF AGC status
///
/// This message describes the gain of each channel in the receiver frontend.
/// Each gain is encoded as a non-dimensional percentage relative to the
/// maximum range possible for the gain stage of the frontend. By convention,
/// each gain array has 8 entries and the index of the array corresponding to
/// the index of the rf channel in the frontend. A gain of 127 percent encodes
/// that rf channel is not present in the hardware. A negative value implies
/// an error for the particular gain stage as reported by the frontend.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgFrontEndGain {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// RF gain for each frontend channel
    #[cfg_attr(feature = "serde", serde(rename(serialize = "rf_gain")))]
    pub rf_gain: [i8; 8],
    /// Intermediate frequency gain for each frontend channel
    #[cfg_attr(feature = "serde", serde(rename(serialize = "if_gain")))]
    pub if_gain: [i8; 8],
}

impl ConcreteMessage for MsgFrontEndGain {
    const MESSAGE_TYPE: u16 = 191;
    const MESSAGE_NAME: &'static str = "MSG_FRONT_END_GAIN";
}

impl SbpMessage for MsgFrontEndGain {
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

impl TryFrom<Sbp> for MsgFrontEndGain {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgFrontEndGain(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgFrontEndGain {
    const MIN_LEN: usize = <[i8; 8] as WireFormat>::MIN_LEN + <[i8; 8] as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.rf_gain) + WireFormat::len(&self.if_gain)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.rf_gain, buf);
        WireFormat::write(&self.if_gain, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgFrontEndGain {
            sender_id: None,
            rf_gain: WireFormat::parse_unchecked(buf),
            if_gain: WireFormat::parse_unchecked(buf),
        }
    }
}

/// State of the Integer Ambiguity Resolution (IAR) process
///
/// This message reports the state of the Integer Ambiguity Resolution (IAR)
/// process, which resolves unknown integer ambiguities from double-
/// differenced carrier-phase measurements from satellite observations.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgIarState {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Number of integer ambiguity hypotheses remaining
    #[cfg_attr(feature = "serde", serde(rename(serialize = "num_hyps")))]
    pub num_hyps: u32,
}

impl ConcreteMessage for MsgIarState {
    const MESSAGE_TYPE: u16 = 25;
    const MESSAGE_NAME: &'static str = "MSG_IAR_STATE";
}

impl SbpMessage for MsgIarState {
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

impl TryFrom<Sbp> for MsgIarState {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgIarState(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgIarState {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.num_hyps)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.num_hyps, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgIarState {
            sender_id: None,
            num_hyps: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgInitBaseDep {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
}

impl ConcreteMessage for MsgInitBaseDep {
    const MESSAGE_TYPE: u16 = 35;
    const MESSAGE_NAME: &'static str = "MSG_INIT_BASE_DEP";
}

impl SbpMessage for MsgInitBaseDep {
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

impl TryFrom<Sbp> for MsgInitBaseDep {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgInitBaseDep(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgInitBaseDep {
    const MIN_LEN: usize = 0;
    fn len(&self) -> usize {
        0
    }
    fn write<B: BufMut>(&self, _buf: &mut B) {}
    fn parse_unchecked<B: Buf>(_buf: &mut B) -> Self {
        MsgInitBaseDep { sender_id: None }
    }
}

/// Mask a satellite from use in Piksi subsystems
///
/// This message allows setting a mask to prevent a particular satellite from
/// being used in various Piksi subsystems.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgMaskSatellite {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Mask of systems that should ignore this satellite.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "mask")))]
    pub mask: u8,
    /// GNSS signal for which the mask is applied
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
}

impl ConcreteMessage for MsgMaskSatellite {
    const MESSAGE_TYPE: u16 = 43;
    const MESSAGE_NAME: &'static str = "MSG_MASK_SATELLITE";
}

impl SbpMessage for MsgMaskSatellite {
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

impl TryFrom<Sbp> for MsgMaskSatellite {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgMaskSatellite(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgMaskSatellite {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN + <GnssSignal as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.mask) + WireFormat::len(&self.sid)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.mask, buf);
        WireFormat::write(&self.sid, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgMaskSatellite {
            sender_id: None,
            mask: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgMaskSatelliteDep {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Mask of systems that should ignore this satellite.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "mask")))]
    pub mask: u8,
    /// GNSS signal for which the mask is applied
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignalDep,
}

impl ConcreteMessage for MsgMaskSatelliteDep {
    const MESSAGE_TYPE: u16 = 27;
    const MESSAGE_NAME: &'static str = "MSG_MASK_SATELLITE_DEP";
}

impl SbpMessage for MsgMaskSatelliteDep {
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

impl TryFrom<Sbp> for MsgMaskSatelliteDep {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgMaskSatelliteDep(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgMaskSatelliteDep {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN + <GnssSignalDep as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.mask) + WireFormat::len(&self.sid)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.mask, buf);
        WireFormat::write(&self.sid, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgMaskSatelliteDep {
            sender_id: None,
            mask: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Bandwidth usage reporting message
///
/// The bandwidth usage, a list of usage by interface.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgNetworkBandwidthUsage {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Usage measurement array
    #[cfg_attr(feature = "serde", serde(rename(serialize = "interfaces")))]
    pub interfaces: Vec<NetworkUsage>,
}

impl ConcreteMessage for MsgNetworkBandwidthUsage {
    const MESSAGE_TYPE: u16 = 189;
    const MESSAGE_NAME: &'static str = "MSG_NETWORK_BANDWIDTH_USAGE";
}

impl SbpMessage for MsgNetworkBandwidthUsage {
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

impl TryFrom<Sbp> for MsgNetworkBandwidthUsage {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgNetworkBandwidthUsage(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgNetworkBandwidthUsage {
    const MIN_LEN: usize = <Vec<NetworkUsage> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.interfaces)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.interfaces, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgNetworkBandwidthUsage {
            sender_id: None,
            interfaces: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Request state of Piksi network interfaces
///
/// Request state of Piksi network interfaces. Output will be sent in
/// MSG_NETWORK_STATE_RESP messages.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgNetworkStateReq {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
}

impl ConcreteMessage for MsgNetworkStateReq {
    const MESSAGE_TYPE: u16 = 186;
    const MESSAGE_NAME: &'static str = "MSG_NETWORK_STATE_REQ";
}

impl SbpMessage for MsgNetworkStateReq {
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

impl TryFrom<Sbp> for MsgNetworkStateReq {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgNetworkStateReq(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgNetworkStateReq {
    const MIN_LEN: usize = 0;
    fn len(&self) -> usize {
        0
    }
    fn write<B: BufMut>(&self, _buf: &mut B) {}
    fn parse_unchecked<B: Buf>(_buf: &mut B) -> Self {
        MsgNetworkStateReq { sender_id: None }
    }
}

/// State of network interface
///
/// The state of a network interface on the Piksi. Data is made to reflect
/// output of ifaddrs struct returned by getifaddrs in c.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgNetworkStateResp {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// IPv4 address (all zero when unavailable)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ipv4_address")))]
    pub ipv4_address: [u8; 4],
    /// IPv4 netmask CIDR notation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ipv4_mask_size")))]
    pub ipv4_mask_size: u8,
    /// IPv6 address (all zero when unavailable)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ipv6_address")))]
    pub ipv6_address: [u8; 16],
    /// IPv6 netmask CIDR notation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ipv6_mask_size")))]
    pub ipv6_mask_size: u8,
    /// Number of Rx bytes
    #[cfg_attr(feature = "serde", serde(rename(serialize = "rx_bytes")))]
    pub rx_bytes: u32,
    /// Number of Tx bytes
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tx_bytes")))]
    pub tx_bytes: u32,
    /// Interface Name
    #[cfg_attr(feature = "serde", serde(rename(serialize = "interface_name")))]
    pub interface_name: SbpString<[u8; 16], Unterminated>,
    /// Interface flags from SIOCGIFFLAGS
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u32,
}

impl ConcreteMessage for MsgNetworkStateResp {
    const MESSAGE_TYPE: u16 = 187;
    const MESSAGE_NAME: &'static str = "MSG_NETWORK_STATE_RESP";
}

impl SbpMessage for MsgNetworkStateResp {
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

impl TryFrom<Sbp> for MsgNetworkStateResp {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgNetworkStateResp(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgNetworkStateResp {
    const MIN_LEN: usize = <[u8; 4] as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <[u8; 16] as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <SbpString<[u8; 16], Unterminated> as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.ipv4_address)
            + WireFormat::len(&self.ipv4_mask_size)
            + WireFormat::len(&self.ipv6_address)
            + WireFormat::len(&self.ipv6_mask_size)
            + WireFormat::len(&self.rx_bytes)
            + WireFormat::len(&self.tx_bytes)
            + WireFormat::len(&self.interface_name)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.ipv4_address, buf);
        WireFormat::write(&self.ipv4_mask_size, buf);
        WireFormat::write(&self.ipv6_address, buf);
        WireFormat::write(&self.ipv6_mask_size, buf);
        WireFormat::write(&self.rx_bytes, buf);
        WireFormat::write(&self.tx_bytes, buf);
        WireFormat::write(&self.interface_name, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgNetworkStateResp {
            sender_id: None,
            ipv4_address: WireFormat::parse_unchecked(buf),
            ipv4_mask_size: WireFormat::parse_unchecked(buf),
            ipv6_address: WireFormat::parse_unchecked(buf),
            ipv6_mask_size: WireFormat::parse_unchecked(buf),
            rx_bytes: WireFormat::parse_unchecked(buf),
            tx_bytes: WireFormat::parse_unchecked(buf),
            interface_name: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Reset the device (host => Piksi)
///
/// This message from the host resets the Piksi back into the bootloader.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgReset {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Reset flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u32,
}

impl ConcreteMessage for MsgReset {
    const MESSAGE_TYPE: u16 = 182;
    const MESSAGE_NAME: &'static str = "MSG_RESET";
}

impl SbpMessage for MsgReset {
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

impl TryFrom<Sbp> for MsgReset {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgReset(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgReset {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgReset {
            sender_id: None,
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Reset the device (host => Piksi)
///
/// This message from the host resets the Piksi back into the bootloader.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgResetDep {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
}

impl ConcreteMessage for MsgResetDep {
    const MESSAGE_TYPE: u16 = 178;
    const MESSAGE_NAME: &'static str = "MSG_RESET_DEP";
}

impl SbpMessage for MsgResetDep {
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

impl TryFrom<Sbp> for MsgResetDep {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgResetDep(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgResetDep {
    const MIN_LEN: usize = 0;
    fn len(&self) -> usize {
        0
    }
    fn write<B: BufMut>(&self, _buf: &mut B) {}
    fn parse_unchecked<B: Buf>(_buf: &mut B) -> Self {
        MsgResetDep { sender_id: None }
    }
}

/// Reset IAR filters (host => Piksi)
///
/// This message resets either the DGNSS Kalman filters or Integer Ambiguity
/// Resolution (IAR) process.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgResetFilters {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Filter flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "filter")))]
    pub filter: u8,
}

impl ConcreteMessage for MsgResetFilters {
    const MESSAGE_TYPE: u16 = 34;
    const MESSAGE_NAME: &'static str = "MSG_RESET_FILTERS";
}

impl SbpMessage for MsgResetFilters {
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

impl TryFrom<Sbp> for MsgResetFilters {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgResetFilters(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgResetFilters {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.filter)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.filter, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgResetFilters {
            sender_id: None,
            filter: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Send GPS time from host (host => Piksi)
///
/// This message sets up timing functionality using a coarse GPS time estimate
/// sent by the host.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSetTime {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
}

impl ConcreteMessage for MsgSetTime {
    const MESSAGE_TYPE: u16 = 104;
    const MESSAGE_NAME: &'static str = "MSG_SET_TIME";
}

impl SbpMessage for MsgSetTime {
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

impl TryFrom<Sbp> for MsgSetTime {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSetTime(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSetTime {
    const MIN_LEN: usize = 0;
    fn len(&self) -> usize {
        0
    }
    fn write<B: BufMut>(&self, _buf: &mut B) {}
    fn parse_unchecked<B: Buf>(_buf: &mut B) -> Self {
        MsgSetTime { sender_id: None }
    }
}

/// Spectrum analyzer
///
/// Spectrum analyzer packet.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSpecan {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Channel ID
    #[cfg_attr(feature = "serde", serde(rename(serialize = "channel_tag")))]
    pub channel_tag: u16,
    /// Receiver time of this observation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "t")))]
    pub t: GpsTime,
    /// Reference frequency of this packet
    #[cfg_attr(feature = "serde", serde(rename(serialize = "freq_ref")))]
    pub freq_ref: f32,
    /// Frequency step of points in this packet
    #[cfg_attr(feature = "serde", serde(rename(serialize = "freq_step")))]
    pub freq_step: f32,
    /// Reference amplitude of this packet
    #[cfg_attr(feature = "serde", serde(rename(serialize = "amplitude_ref")))]
    pub amplitude_ref: f32,
    /// Amplitude unit value of points in this packet
    #[cfg_attr(feature = "serde", serde(rename(serialize = "amplitude_unit")))]
    pub amplitude_unit: f32,
    /// Amplitude values (in the above units) of points in this packet
    #[cfg_attr(feature = "serde", serde(rename(serialize = "amplitude_value")))]
    pub amplitude_value: Vec<u8>,
}

impl ConcreteMessage for MsgSpecan {
    const MESSAGE_TYPE: u16 = 81;
    const MESSAGE_NAME: &'static str = "MSG_SPECAN";
}

impl SbpMessage for MsgSpecan {
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

impl TryFrom<Sbp> for MsgSpecan {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSpecan(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSpecan {
    const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
        + <GpsTime as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <Vec<u8> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.channel_tag)
            + WireFormat::len(&self.t)
            + WireFormat::len(&self.freq_ref)
            + WireFormat::len(&self.freq_step)
            + WireFormat::len(&self.amplitude_ref)
            + WireFormat::len(&self.amplitude_unit)
            + WireFormat::len(&self.amplitude_value)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.channel_tag, buf);
        WireFormat::write(&self.t, buf);
        WireFormat::write(&self.freq_ref, buf);
        WireFormat::write(&self.freq_step, buf);
        WireFormat::write(&self.amplitude_ref, buf);
        WireFormat::write(&self.amplitude_unit, buf);
        WireFormat::write(&self.amplitude_value, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSpecan {
            sender_id: None,
            channel_tag: WireFormat::parse_unchecked(buf),
            t: WireFormat::parse_unchecked(buf),
            freq_ref: WireFormat::parse_unchecked(buf),
            freq_step: WireFormat::parse_unchecked(buf),
            amplitude_ref: WireFormat::parse_unchecked(buf),
            amplitude_unit: WireFormat::parse_unchecked(buf),
            amplitude_value: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSpecanDep {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Channel ID
    #[cfg_attr(feature = "serde", serde(rename(serialize = "channel_tag")))]
    pub channel_tag: u16,
    /// Receiver time of this observation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "t")))]
    pub t: GpsTimeDep,
    /// Reference frequency of this packet
    #[cfg_attr(feature = "serde", serde(rename(serialize = "freq_ref")))]
    pub freq_ref: f32,
    /// Frequency step of points in this packet
    #[cfg_attr(feature = "serde", serde(rename(serialize = "freq_step")))]
    pub freq_step: f32,
    /// Reference amplitude of this packet
    #[cfg_attr(feature = "serde", serde(rename(serialize = "amplitude_ref")))]
    pub amplitude_ref: f32,
    /// Amplitude unit value of points in this packet
    #[cfg_attr(feature = "serde", serde(rename(serialize = "amplitude_unit")))]
    pub amplitude_unit: f32,
    /// Amplitude values (in the above units) of points in this packet
    #[cfg_attr(feature = "serde", serde(rename(serialize = "amplitude_value")))]
    pub amplitude_value: Vec<u8>,
}

impl ConcreteMessage for MsgSpecanDep {
    const MESSAGE_TYPE: u16 = 80;
    const MESSAGE_NAME: &'static str = "MSG_SPECAN_DEP";
}

impl SbpMessage for MsgSpecanDep {
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

impl TryFrom<Sbp> for MsgSpecanDep {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSpecanDep(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSpecanDep {
    const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
        + <GpsTimeDep as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <Vec<u8> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.channel_tag)
            + WireFormat::len(&self.t)
            + WireFormat::len(&self.freq_ref)
            + WireFormat::len(&self.freq_step)
            + WireFormat::len(&self.amplitude_ref)
            + WireFormat::len(&self.amplitude_unit)
            + WireFormat::len(&self.amplitude_value)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.channel_tag, buf);
        WireFormat::write(&self.t, buf);
        WireFormat::write(&self.freq_ref, buf);
        WireFormat::write(&self.freq_step, buf);
        WireFormat::write(&self.amplitude_ref, buf);
        WireFormat::write(&self.amplitude_unit, buf);
        WireFormat::write(&self.amplitude_value, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSpecanDep {
            sender_id: None,
            channel_tag: WireFormat::parse_unchecked(buf),
            t: WireFormat::parse_unchecked(buf),
            freq_ref: WireFormat::parse_unchecked(buf),
            freq_step: WireFormat::parse_unchecked(buf),
            amplitude_ref: WireFormat::parse_unchecked(buf),
            amplitude_unit: WireFormat::parse_unchecked(buf),
            amplitude_value: WireFormat::parse_unchecked(buf),
        }
    }
}

/// State of an RTOS thread
///
/// The thread usage message from the device reports real-time operating
/// system (RTOS) thread usage statistics for the named thread. The reported
/// percentage values must be normalized.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgThreadState {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Thread name (NULL terminated)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "name")))]
    pub name: SbpString<[u8; 20], NullTerminated>,
    /// Percentage cpu use for this thread. Values range from 0 - 1000 and needs
    /// to be renormalized to 100
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cpu")))]
    pub cpu: u16,
    /// Free stack space for this thread
    #[cfg_attr(feature = "serde", serde(rename(serialize = "stack_free")))]
    pub stack_free: u32,
}

impl ConcreteMessage for MsgThreadState {
    const MESSAGE_TYPE: u16 = 23;
    const MESSAGE_NAME: &'static str = "MSG_THREAD_STATE";
}

impl SbpMessage for MsgThreadState {
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

impl TryFrom<Sbp> for MsgThreadState {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgThreadState(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgThreadState {
    const MIN_LEN: usize = <SbpString<[u8; 20], NullTerminated> as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.name) + WireFormat::len(&self.cpu) + WireFormat::len(&self.stack_free)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.name, buf);
        WireFormat::write(&self.cpu, buf);
        WireFormat::write(&self.stack_free, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgThreadState {
            sender_id: None,
            name: WireFormat::parse_unchecked(buf),
            cpu: WireFormat::parse_unchecked(buf),
            stack_free: WireFormat::parse_unchecked(buf),
        }
    }
}

/// State of the UART channels
///
/// The UART message reports data latency and throughput of the UART channels
/// providing SBP I/O. On the default Piksi configuration, UARTs A and B are
/// used for telemetry radios, but can also be host access ports for embedded
/// hosts, or other interfaces in future. The reported percentage values must
/// be normalized. Observations latency and period can be used to assess the
/// health of the differential corrections link. Latency provides the
/// timeliness of received base observations while the period indicates their
/// likelihood of transmission.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgUartState {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// State of UART A
    #[cfg_attr(feature = "serde", serde(rename(serialize = "uart_a")))]
    pub uart_a: UARTChannel,
    /// State of UART B
    #[cfg_attr(feature = "serde", serde(rename(serialize = "uart_b")))]
    pub uart_b: UARTChannel,
    /// State of UART FTDI (USB logger)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "uart_ftdi")))]
    pub uart_ftdi: UARTChannel,
    /// UART communication latency
    #[cfg_attr(feature = "serde", serde(rename(serialize = "latency")))]
    pub latency: Latency,
    /// Observation receipt period
    #[cfg_attr(feature = "serde", serde(rename(serialize = "obs_period")))]
    pub obs_period: Period,
}

impl ConcreteMessage for MsgUartState {
    const MESSAGE_TYPE: u16 = 29;
    const MESSAGE_NAME: &'static str = "MSG_UART_STATE";
}

impl SbpMessage for MsgUartState {
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

impl TryFrom<Sbp> for MsgUartState {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgUartState(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgUartState {
    const MIN_LEN: usize = <UARTChannel as WireFormat>::MIN_LEN
        + <UARTChannel as WireFormat>::MIN_LEN
        + <UARTChannel as WireFormat>::MIN_LEN
        + <Latency as WireFormat>::MIN_LEN
        + <Period as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.uart_a)
            + WireFormat::len(&self.uart_b)
            + WireFormat::len(&self.uart_ftdi)
            + WireFormat::len(&self.latency)
            + WireFormat::len(&self.obs_period)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.uart_a, buf);
        WireFormat::write(&self.uart_b, buf);
        WireFormat::write(&self.uart_ftdi, buf);
        WireFormat::write(&self.latency, buf);
        WireFormat::write(&self.obs_period, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgUartState {
            sender_id: None,
            uart_a: WireFormat::parse_unchecked(buf),
            uart_b: WireFormat::parse_unchecked(buf),
            uart_ftdi: WireFormat::parse_unchecked(buf),
            latency: WireFormat::parse_unchecked(buf),
            obs_period: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgUartStateDepa {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// State of UART A
    #[cfg_attr(feature = "serde", serde(rename(serialize = "uart_a")))]
    pub uart_a: UARTChannel,
    /// State of UART B
    #[cfg_attr(feature = "serde", serde(rename(serialize = "uart_b")))]
    pub uart_b: UARTChannel,
    /// State of UART FTDI (USB logger)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "uart_ftdi")))]
    pub uart_ftdi: UARTChannel,
    /// UART communication latency
    #[cfg_attr(feature = "serde", serde(rename(serialize = "latency")))]
    pub latency: Latency,
}

impl ConcreteMessage for MsgUartStateDepa {
    const MESSAGE_TYPE: u16 = 24;
    const MESSAGE_NAME: &'static str = "MSG_UART_STATE_DEPA";
}

impl SbpMessage for MsgUartStateDepa {
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

impl TryFrom<Sbp> for MsgUartStateDepa {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgUartStateDepa(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgUartStateDepa {
    const MIN_LEN: usize = <UARTChannel as WireFormat>::MIN_LEN
        + <UARTChannel as WireFormat>::MIN_LEN
        + <UARTChannel as WireFormat>::MIN_LEN
        + <Latency as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.uart_a)
            + WireFormat::len(&self.uart_b)
            + WireFormat::len(&self.uart_ftdi)
            + WireFormat::len(&self.latency)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.uart_a, buf);
        WireFormat::write(&self.uart_b, buf);
        WireFormat::write(&self.uart_ftdi, buf);
        WireFormat::write(&self.latency, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgUartStateDepa {
            sender_id: None,
            uart_a: WireFormat::parse_unchecked(buf),
            uart_b: WireFormat::parse_unchecked(buf),
            uart_ftdi: WireFormat::parse_unchecked(buf),
            latency: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Bandwidth usage measurement for a single interface
///
/// The bandwidth usage for each interface can be reported within this struct
/// and utilize multiple fields to fully specify the type of traffic that is
/// being tracked. As either the interval of collection or the collection time
/// may vary, both a timestamp and period field is provided, though may not
/// necessarily be populated with a value.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct NetworkUsage {
    /// Duration over which the measurement was collected
    #[cfg_attr(feature = "serde", serde(rename(serialize = "duration")))]
    pub duration: u64,
    /// Number of bytes handled in total within period
    #[cfg_attr(feature = "serde", serde(rename(serialize = "total_bytes")))]
    pub total_bytes: u64,
    /// Number of bytes transmitted within period
    #[cfg_attr(feature = "serde", serde(rename(serialize = "rx_bytes")))]
    pub rx_bytes: u32,
    /// Number of bytes received within period
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tx_bytes")))]
    pub tx_bytes: u32,
    /// Interface Name
    #[cfg_attr(feature = "serde", serde(rename(serialize = "interface_name")))]
    pub interface_name: SbpString<[u8; 16], Unterminated>,
}

impl WireFormat for NetworkUsage {
    const MIN_LEN: usize = <u64 as WireFormat>::MIN_LEN
        + <u64 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <SbpString<[u8; 16], Unterminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.duration)
            + WireFormat::len(&self.total_bytes)
            + WireFormat::len(&self.rx_bytes)
            + WireFormat::len(&self.tx_bytes)
            + WireFormat::len(&self.interface_name)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.duration, buf);
        WireFormat::write(&self.total_bytes, buf);
        WireFormat::write(&self.rx_bytes, buf);
        WireFormat::write(&self.tx_bytes, buf);
        WireFormat::write(&self.interface_name, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        NetworkUsage {
            duration: WireFormat::parse_unchecked(buf),
            total_bytes: WireFormat::parse_unchecked(buf),
            rx_bytes: WireFormat::parse_unchecked(buf),
            tx_bytes: WireFormat::parse_unchecked(buf),
            interface_name: WireFormat::parse_unchecked(buf),
        }
    }
}

/// base station observation message receipt period
///
/// Statistics on the period of observations received from the base station.
/// As complete observation sets are received, their time of reception is
/// compared with the prior set''s time of reception. This measurement
/// provides a proxy for link quality as incomplete or missing sets will
/// increase the period.  Long periods can cause momentary RTK solution
/// outages.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct Period {
    /// Average period
    #[cfg_attr(feature = "serde", serde(rename(serialize = "avg")))]
    pub avg: i32,
    /// Minimum period
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pmin")))]
    pub pmin: i32,
    /// Maximum period
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pmax")))]
    pub pmax: i32,
    /// Smoothed estimate of the current period
    #[cfg_attr(feature = "serde", serde(rename(serialize = "current")))]
    pub current: i32,
}

impl WireFormat for Period {
    const MIN_LEN: usize = <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.avg)
            + WireFormat::len(&self.pmin)
            + WireFormat::len(&self.pmax)
            + WireFormat::len(&self.current)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.avg, buf);
        WireFormat::write(&self.pmin, buf);
        WireFormat::write(&self.pmax, buf);
        WireFormat::write(&self.current, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        Period {
            avg: WireFormat::parse_unchecked(buf),
            pmin: WireFormat::parse_unchecked(buf),
            pmax: WireFormat::parse_unchecked(buf),
            current: WireFormat::parse_unchecked(buf),
        }
    }
}

/// State of the UART channel
///
/// Throughput, utilization, and error counts on the RX/TX buffers of this
/// UART channel. The reported percentage values must be normalized.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct UARTChannel {
    /// UART transmit throughput
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tx_throughput")))]
    pub tx_throughput: f32,
    /// UART receive throughput
    #[cfg_attr(feature = "serde", serde(rename(serialize = "rx_throughput")))]
    pub rx_throughput: f32,
    /// UART CRC error count
    #[cfg_attr(feature = "serde", serde(rename(serialize = "crc_error_count")))]
    pub crc_error_count: u16,
    /// UART IO error count
    #[cfg_attr(feature = "serde", serde(rename(serialize = "io_error_count")))]
    pub io_error_count: u16,
    /// UART transmit buffer percentage utilization (ranges from 0 to 255)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tx_buffer_level")))]
    pub tx_buffer_level: u8,
    /// UART receive buffer percentage utilization (ranges from 0 to 255)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "rx_buffer_level")))]
    pub rx_buffer_level: u8,
}

impl WireFormat for UARTChannel {
    const MIN_LEN: usize = <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tx_throughput)
            + WireFormat::len(&self.rx_throughput)
            + WireFormat::len(&self.crc_error_count)
            + WireFormat::len(&self.io_error_count)
            + WireFormat::len(&self.tx_buffer_level)
            + WireFormat::len(&self.rx_buffer_level)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tx_throughput, buf);
        WireFormat::write(&self.rx_throughput, buf);
        WireFormat::write(&self.crc_error_count, buf);
        WireFormat::write(&self.io_error_count, buf);
        WireFormat::write(&self.tx_buffer_level, buf);
        WireFormat::write(&self.rx_buffer_level, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        UARTChannel {
            tx_throughput: WireFormat::parse_unchecked(buf),
            rx_throughput: WireFormat::parse_unchecked(buf),
            crc_error_count: WireFormat::parse_unchecked(buf),
            io_error_count: WireFormat::parse_unchecked(buf),
            tx_buffer_level: WireFormat::parse_unchecked(buf),
            rx_buffer_level: WireFormat::parse_unchecked(buf),
        }
    }
}
