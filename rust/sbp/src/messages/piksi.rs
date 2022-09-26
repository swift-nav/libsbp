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
pub use latency::Latency;
pub use msg_almanac::MsgAlmanac;
pub use msg_cell_modem_status::MsgCellModemStatus;
pub use msg_command_output::MsgCommandOutput;
pub use msg_command_req::MsgCommandReq;
pub use msg_command_resp::MsgCommandResp;
pub use msg_cw_results::MsgCwResults;
pub use msg_cw_start::MsgCwStart;
pub use msg_device_monitor::MsgDeviceMonitor;
pub use msg_front_end_gain::MsgFrontEndGain;
pub use msg_iar_state::MsgIarState;
pub use msg_init_base_dep::MsgInitBaseDep;
pub use msg_mask_satellite::MsgMaskSatellite;
pub use msg_mask_satellite_dep::MsgMaskSatelliteDep;
pub use msg_network_bandwidth_usage::MsgNetworkBandwidthUsage;
pub use msg_network_state_req::MsgNetworkStateReq;
pub use msg_network_state_resp::MsgNetworkStateResp;
pub use msg_reset::MsgReset;
pub use msg_reset_dep::MsgResetDep;
pub use msg_reset_filters::MsgResetFilters;
pub use msg_set_time::MsgSetTime;
pub use msg_specan::MsgSpecan;
pub use msg_specan_dep::MsgSpecanDep;
pub use msg_thread_state::MsgThreadState;
pub use msg_uart_state::MsgUartState;
pub use msg_uart_state_depa::MsgUartStateDepa;
pub use network_usage::NetworkUsage;
pub use period::Period;
pub use uart_channel::UARTChannel;

pub mod latency {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Receiver-to-base station latency
    ///
    /// Statistics on the latency of observations received from the base station.
    /// As observation packets are received their GPS time is compared to the
    /// current GPS time calculated locally by the receiver to give a precise
    /// measurement of the end-to-end communication latency in the system.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct Latency {
        /// Average latency
        #[cfg_attr(feature = "serde", serde(rename = "avg"))]
        pub avg: i32,
        /// Minimum latency
        #[cfg_attr(feature = "serde", serde(rename = "lmin"))]
        pub lmin: i32,
        /// Maximum latency
        #[cfg_attr(feature = "serde", serde(rename = "lmax"))]
        pub lmax: i32,
        /// Smoothed estimate of the current latency
        #[cfg_attr(feature = "serde", serde(rename = "current"))]
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
}

pub mod msg_almanac {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Legacy message to load satellite almanac (host => Piksi)
    ///
    /// This is a legacy message for sending and loading a satellite alamanac onto
    /// the Piksi's flash memory from the host.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgAlmanac {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
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
}

pub mod msg_cell_modem_status {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Cell modem information update message
    ///
    /// If a cell modem is present on a piksi device, this message will be send
    /// periodically to update the host on the status of the modem and its various
    /// parameters.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgCellModemStatus {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Received cell signal strength in dBm, zero translates to unknown
        #[cfg_attr(feature = "serde", serde(rename = "signal_strength"))]
        pub signal_strength: i8,
        /// BER as reported by the modem, zero translates to unknown
        #[cfg_attr(feature = "serde", serde(rename = "signal_error_rate"))]
        pub signal_error_rate: f32,
        /// Unspecified data TBD for this schema
        #[cfg_attr(feature = "serde", serde(rename = "reserved"))]
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
}

pub mod msg_command_output {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Command output
    ///
    /// Returns the standard output and standard error of the command requested by
    /// MSG_COMMAND_REQ. The sequence number can be used to filter for filtering
    /// the correct command.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgCommandOutput {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Sequence number
        #[cfg_attr(feature = "serde", serde(rename = "sequence"))]
        pub sequence: u32,
        /// Line of standard output or standard error
        #[cfg_attr(feature = "serde", serde(rename = "line"))]
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
        const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
            + <SbpString<Vec<u8>, Unterminated> as WireFormat>::MIN_LEN;
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
}

pub mod msg_command_req {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Execute a command (host => device)
    ///
    /// Request the recipient to execute an command. Output will be sent in
    /// MSG_LOG messages, and the exit code will be returned with
    /// MSG_COMMAND_RESP.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgCommandReq {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Sequence number
        #[cfg_attr(feature = "serde", serde(rename = "sequence"))]
        pub sequence: u32,
        /// Command line to execute
        #[cfg_attr(feature = "serde", serde(rename = "command"))]
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
        const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
            + <SbpString<Vec<u8>, NullTerminated> as WireFormat>::MIN_LEN;
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
}

pub mod msg_command_resp {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Exit code from executed command (device => host)
    ///
    /// The response to MSG_COMMAND_REQ with the return code of the command.  A
    /// return code of zero indicates success.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgCommandResp {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Sequence number
        #[cfg_attr(feature = "serde", serde(rename = "sequence"))]
        pub sequence: u32,
        /// Exit code
        #[cfg_attr(feature = "serde", serde(rename = "code"))]
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
}

pub mod msg_cw_results {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Legacy message for CW interference channel (Piksi => host)
    ///
    /// This is an unused legacy message for result reporting from the CW
    /// interference channel on the SwiftNAP. This message will be removed in a
    /// future release.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgCwResults {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
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
}

pub mod msg_cw_start {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Legacy message for CW interference channel (host => Piksi)
    ///
    /// This is an unused legacy message from the host for starting the CW
    /// interference channel on the SwiftNAP. This message will be removed in a
    /// future release.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgCwStart {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
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
}

pub mod msg_device_monitor {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Device temperature and voltage levels
    ///
    /// This message contains temperature and voltage level measurements from the
    /// processor's monitoring system and the RF frontend die temperature if
    /// available.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgDeviceMonitor {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Device V_in
        #[cfg_attr(feature = "serde", serde(rename = "dev_vin"))]
        pub dev_vin: i16,
        /// Processor V_int
        #[cfg_attr(feature = "serde", serde(rename = "cpu_vint"))]
        pub cpu_vint: i16,
        /// Processor V_aux
        #[cfg_attr(feature = "serde", serde(rename = "cpu_vaux"))]
        pub cpu_vaux: i16,
        /// Processor temperature
        #[cfg_attr(feature = "serde", serde(rename = "cpu_temperature"))]
        pub cpu_temperature: i16,
        /// Frontend temperature (if available)
        #[cfg_attr(feature = "serde", serde(rename = "fe_temperature"))]
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
}

pub mod msg_front_end_gain {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgFrontEndGain {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// RF gain for each frontend channel
        #[cfg_attr(feature = "serde", serde(rename = "rf_gain"))]
        pub rf_gain: [i8; 8],
        /// Intermediate frequency gain for each frontend channel
        #[cfg_attr(feature = "serde", serde(rename = "if_gain"))]
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
}

pub mod msg_iar_state {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// State of the Integer Ambiguity Resolution (IAR) process
    ///
    /// This message reports the state of the Integer Ambiguity Resolution (IAR)
    /// process, which resolves unknown integer ambiguities from double-
    /// differenced carrier-phase measurements from satellite observations.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgIarState {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Number of integer ambiguity hypotheses remaining
        #[cfg_attr(feature = "serde", serde(rename = "num_hyps"))]
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
}

pub mod msg_init_base_dep {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Deprecated
    ///
    /// Deprecated
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgInitBaseDep {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
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
}

pub mod msg_mask_satellite {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Mask a satellite from use in Piksi subsystems
    ///
    /// This message allows setting a mask to prevent a particular satellite from
    /// being used in various Piksi subsystems.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgMaskSatellite {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Mask of systems that should ignore this satellite.
        #[cfg_attr(feature = "serde", serde(rename = "mask"))]
        pub mask: u8,
        /// GNSS signal for which the mask is applied
        #[cfg_attr(feature = "serde", serde(rename = "sid"))]
        pub sid: GnssSignal,
    }

    impl MsgMaskSatellite {
        /// Gets the [TrackingChannels][self::TrackingChannels] stored in the `mask` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TrackingChannels` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TrackingChannels` were added.
        pub fn tracking_channels(&self) -> Result<TrackingChannels, u8> {
            get_bit_range!(self.mask, u8, u8, 1, 1).try_into()
        }

        /// Set the bitrange corresponding to the [TrackingChannels][TrackingChannels] of the `mask` bitfield.
        pub fn set_tracking_channels(&mut self, tracking_channels: TrackingChannels) {
            set_bit_range!(&mut self.mask, tracking_channels, u8, u8, 1, 1);
        }

        /// Gets the [AcquisitionChannel][self::AcquisitionChannel] stored in the `mask` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `AcquisitionChannel` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `AcquisitionChannel` were added.
        pub fn acquisition_channel(&self) -> Result<AcquisitionChannel, u8> {
            get_bit_range!(self.mask, u8, u8, 0, 0).try_into()
        }

        /// Set the bitrange corresponding to the [AcquisitionChannel][AcquisitionChannel] of the `mask` bitfield.
        pub fn set_acquisition_channel(&mut self, acquisition_channel: AcquisitionChannel) {
            set_bit_range!(&mut self.mask, acquisition_channel, u8, u8, 0, 0);
        }
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

    /// Tracking channels
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TrackingChannels {
        /// Enabled
        Enabled = 0,

        /// Drop this PRN if currently tracking
        DropThisPrnIfCurrentlyTracking = 1,
    }

    impl std::fmt::Display for TrackingChannels {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TrackingChannels::Enabled => f.write_str("Enabled"),
                TrackingChannels::DropThisPrnIfCurrentlyTracking => {
                    f.write_str("Drop this PRN if currently tracking")
                }
            }
        }
    }

    impl TryFrom<u8> for TrackingChannels {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TrackingChannels::Enabled),
                1 => Ok(TrackingChannels::DropThisPrnIfCurrentlyTracking),
                i => Err(i),
            }
        }
    }

    /// Acquisition channel
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum AcquisitionChannel {
        /// Enabled
        Enabled = 0,

        /// Skip this satellite on future acquisitions
        SkipThisSatelliteOnFutureAcquisitions = 1,
    }

    impl std::fmt::Display for AcquisitionChannel {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                AcquisitionChannel::Enabled => f.write_str("Enabled"),
                AcquisitionChannel::SkipThisSatelliteOnFutureAcquisitions => {
                    f.write_str("Skip this satellite on future acquisitions")
                }
            }
        }
    }

    impl TryFrom<u8> for AcquisitionChannel {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(AcquisitionChannel::Enabled),
                1 => Ok(AcquisitionChannel::SkipThisSatelliteOnFutureAcquisitions),
                i => Err(i),
            }
        }
    }
}

pub mod msg_mask_satellite_dep {
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
    pub struct MsgMaskSatelliteDep {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Mask of systems that should ignore this satellite.
        #[cfg_attr(feature = "serde", serde(rename = "mask"))]
        pub mask: u8,
        /// GNSS signal for which the mask is applied
        #[cfg_attr(feature = "serde", serde(rename = "sid"))]
        pub sid: GnssSignalDep,
    }

    impl MsgMaskSatelliteDep {
        /// Gets the [TrackingChannels][self::TrackingChannels] stored in the `mask` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `TrackingChannels` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `TrackingChannels` were added.
        pub fn tracking_channels(&self) -> Result<TrackingChannels, u8> {
            get_bit_range!(self.mask, u8, u8, 1, 1).try_into()
        }

        /// Set the bitrange corresponding to the [TrackingChannels][TrackingChannels] of the `mask` bitfield.
        pub fn set_tracking_channels(&mut self, tracking_channels: TrackingChannels) {
            set_bit_range!(&mut self.mask, tracking_channels, u8, u8, 1, 1);
        }

        /// Gets the [AcquisitionChannel][self::AcquisitionChannel] stored in the `mask` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `AcquisitionChannel` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `AcquisitionChannel` were added.
        pub fn acquisition_channel(&self) -> Result<AcquisitionChannel, u8> {
            get_bit_range!(self.mask, u8, u8, 0, 0).try_into()
        }

        /// Set the bitrange corresponding to the [AcquisitionChannel][AcquisitionChannel] of the `mask` bitfield.
        pub fn set_acquisition_channel(&mut self, acquisition_channel: AcquisitionChannel) {
            set_bit_range!(&mut self.mask, acquisition_channel, u8, u8, 0, 0);
        }
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

    /// Tracking channels
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum TrackingChannels {
        /// Enabled
        Enabled = 0,

        /// Drop this PRN if currently tracking
        DropThisPrnIfCurrentlyTracking = 1,
    }

    impl std::fmt::Display for TrackingChannels {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                TrackingChannels::Enabled => f.write_str("Enabled"),
                TrackingChannels::DropThisPrnIfCurrentlyTracking => {
                    f.write_str("Drop this PRN if currently tracking")
                }
            }
        }
    }

    impl TryFrom<u8> for TrackingChannels {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(TrackingChannels::Enabled),
                1 => Ok(TrackingChannels::DropThisPrnIfCurrentlyTracking),
                i => Err(i),
            }
        }
    }

    /// Acquisition channel
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum AcquisitionChannel {
        /// Enabled
        Enabled = 0,

        /// Skip this satellite on future acquisitions
        SkipThisSatelliteOnFutureAcquisitions = 1,
    }

    impl std::fmt::Display for AcquisitionChannel {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                AcquisitionChannel::Enabled => f.write_str("Enabled"),
                AcquisitionChannel::SkipThisSatelliteOnFutureAcquisitions => {
                    f.write_str("Skip this satellite on future acquisitions")
                }
            }
        }
    }

    impl TryFrom<u8> for AcquisitionChannel {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(AcquisitionChannel::Enabled),
                1 => Ok(AcquisitionChannel::SkipThisSatelliteOnFutureAcquisitions),
                i => Err(i),
            }
        }
    }
}

pub mod msg_network_bandwidth_usage {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Bandwidth usage reporting message
    ///
    /// The bandwidth usage, a list of usage by interface.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgNetworkBandwidthUsage {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Usage measurement array
        #[cfg_attr(feature = "serde", serde(rename = "interfaces"))]
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
}

pub mod msg_network_state_req {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Request state of Piksi network interfaces
    ///
    /// Request state of Piksi network interfaces. Output will be sent in
    /// MSG_NETWORK_STATE_RESP messages.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgNetworkStateReq {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
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
}

pub mod msg_network_state_resp {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// State of network interface
    ///
    /// The state of a network interface on the Piksi. Data is made to reflect
    /// output of ifaddrs struct returned by getifaddrs in c.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgNetworkStateResp {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// IPv4 address (all zero when unavailable)
        #[cfg_attr(feature = "serde", serde(rename = "ipv4_address"))]
        pub ipv4_address: [u8; 4],
        /// IPv4 netmask CIDR notation
        #[cfg_attr(feature = "serde", serde(rename = "ipv4_mask_size"))]
        pub ipv4_mask_size: u8,
        /// IPv6 address (all zero when unavailable)
        #[cfg_attr(feature = "serde", serde(rename = "ipv6_address"))]
        pub ipv6_address: [u8; 16],
        /// IPv6 netmask CIDR notation
        #[cfg_attr(feature = "serde", serde(rename = "ipv6_mask_size"))]
        pub ipv6_mask_size: u8,
        /// Number of Rx bytes
        #[cfg_attr(feature = "serde", serde(rename = "rx_bytes"))]
        pub rx_bytes: u32,
        /// Number of Tx bytes
        #[cfg_attr(feature = "serde", serde(rename = "tx_bytes"))]
        pub tx_bytes: u32,
        /// Interface Name
        #[cfg_attr(feature = "serde", serde(rename = "interface_name"))]
        pub interface_name: SbpString<[u8; 16], Unterminated>,
        /// Interface flags from SIOCGIFFLAGS
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u32,
    }

    impl MsgNetworkStateResp {
        /// Gets the `iff_multicast_supports_multicast` flag.
        pub fn iff_multicast_supports_multicast(&self) -> bool {
            ((self.flags >> 15) & 1) == 1
        }

        /// Sets the `iff_multicast_supports_multicast` flag.
        pub fn set_iff_multicast_supports_multicast(
            &mut self,
            iff_multicast_supports_multicast: bool,
        ) {
            self.flags ^= (!(iff_multicast_supports_multicast as u32)) & (1 << 15)
        }

        /// Gets the `iff_link2_per_link_layer_defined_bit` flag.
        pub fn iff_link2_per_link_layer_defined_bit(&self) -> bool {
            ((self.flags >> 14) & 1) == 1
        }

        /// Sets the `iff_link2_per_link_layer_defined_bit` flag.
        pub fn set_iff_link2_per_link_layer_defined_bit(
            &mut self,
            iff_link2_per_link_layer_defined_bit: bool,
        ) {
            self.flags ^= (!(iff_link2_per_link_layer_defined_bit as u32)) & (1 << 14)
        }

        /// Gets the `iff_link1_per_link_layer_defined_bit` flag.
        pub fn iff_link1_per_link_layer_defined_bit(&self) -> bool {
            ((self.flags >> 13) & 1) == 1
        }

        /// Sets the `iff_link1_per_link_layer_defined_bit` flag.
        pub fn set_iff_link1_per_link_layer_defined_bit(
            &mut self,
            iff_link1_per_link_layer_defined_bit: bool,
        ) {
            self.flags ^= (!(iff_link1_per_link_layer_defined_bit as u32)) & (1 << 13)
        }

        /// Gets the `iff_link0_per_link_layer_defined_bit` flag.
        pub fn iff_link0_per_link_layer_defined_bit(&self) -> bool {
            ((self.flags >> 12) & 1) == 1
        }

        /// Sets the `iff_link0_per_link_layer_defined_bit` flag.
        pub fn set_iff_link0_per_link_layer_defined_bit(
            &mut self,
            iff_link0_per_link_layer_defined_bit: bool,
        ) {
            self.flags ^= (!(iff_link0_per_link_layer_defined_bit as u32)) & (1 << 12)
        }

        /// Gets the `iff_simplex_cant_hear_own_transmissions` flag.
        pub fn iff_simplex_cant_hear_own_transmissions(&self) -> bool {
            ((self.flags >> 11) & 1) == 1
        }

        /// Sets the `iff_simplex_cant_hear_own_transmissions` flag.
        pub fn set_iff_simplex_cant_hear_own_transmissions(
            &mut self,
            iff_simplex_cant_hear_own_transmissions: bool,
        ) {
            self.flags ^= (!(iff_simplex_cant_hear_own_transmissions as u32)) & (1 << 11)
        }

        /// Gets the `iff_oactive_transmission_in_progress` flag.
        pub fn iff_oactive_transmission_in_progress(&self) -> bool {
            ((self.flags >> 10) & 1) == 1
        }

        /// Sets the `iff_oactive_transmission_in_progress` flag.
        pub fn set_iff_oactive_transmission_in_progress(
            &mut self,
            iff_oactive_transmission_in_progress: bool,
        ) {
            self.flags ^= (!(iff_oactive_transmission_in_progress as u32)) & (1 << 10)
        }

        /// Gets the `iff_allmulti_receive_all_multicast_packets` flag.
        pub fn iff_allmulti_receive_all_multicast_packets(&self) -> bool {
            ((self.flags >> 9) & 1) == 1
        }

        /// Sets the `iff_allmulti_receive_all_multicast_packets` flag.
        pub fn set_iff_allmulti_receive_all_multicast_packets(
            &mut self,
            iff_allmulti_receive_all_multicast_packets: bool,
        ) {
            self.flags ^= (!(iff_allmulti_receive_all_multicast_packets as u32)) & (1 << 9)
        }

        /// Gets the `iff_promisc_receive_all_packets` flag.
        pub fn iff_promisc_receive_all_packets(&self) -> bool {
            ((self.flags >> 8) & 1) == 1
        }

        /// Sets the `iff_promisc_receive_all_packets` flag.
        pub fn set_iff_promisc_receive_all_packets(
            &mut self,
            iff_promisc_receive_all_packets: bool,
        ) {
            self.flags ^= (!(iff_promisc_receive_all_packets as u32)) & (1 << 8)
        }

        /// Gets the `iff_noarp_no_address_resolution_protocol` flag.
        pub fn iff_noarp_no_address_resolution_protocol(&self) -> bool {
            ((self.flags >> 7) & 1) == 1
        }

        /// Sets the `iff_noarp_no_address_resolution_protocol` flag.
        pub fn set_iff_noarp_no_address_resolution_protocol(
            &mut self,
            iff_noarp_no_address_resolution_protocol: bool,
        ) {
            self.flags ^= (!(iff_noarp_no_address_resolution_protocol as u32)) & (1 << 7)
        }

        /// Gets the `iff_running_resources_allocated` flag.
        pub fn iff_running_resources_allocated(&self) -> bool {
            ((self.flags >> 6) & 1) == 1
        }

        /// Sets the `iff_running_resources_allocated` flag.
        pub fn set_iff_running_resources_allocated(
            &mut self,
            iff_running_resources_allocated: bool,
        ) {
            self.flags ^= (!(iff_running_resources_allocated as u32)) & (1 << 6)
        }

        /// Gets the `iff_notrailers_avoid_use_of_trailers` flag.
        pub fn iff_notrailers_avoid_use_of_trailers(&self) -> bool {
            ((self.flags >> 5) & 1) == 1
        }

        /// Sets the `iff_notrailers_avoid_use_of_trailers` flag.
        pub fn set_iff_notrailers_avoid_use_of_trailers(
            &mut self,
            iff_notrailers_avoid_use_of_trailers: bool,
        ) {
            self.flags ^= (!(iff_notrailers_avoid_use_of_trailers as u32)) & (1 << 5)
        }

        /// Gets the `iff_pointopoint_interface_is_pointtopoint_link` flag.
        pub fn iff_pointopoint_interface_is_pointtopoint_link(&self) -> bool {
            ((self.flags >> 4) & 1) == 1
        }

        /// Sets the `iff_pointopoint_interface_is_pointtopoint_link` flag.
        pub fn set_iff_pointopoint_interface_is_pointtopoint_link(
            &mut self,
            iff_pointopoint_interface_is_pointtopoint_link: bool,
        ) {
            self.flags ^= (!(iff_pointopoint_interface_is_pointtopoint_link as u32)) & (1 << 4)
        }

        /// Gets the `iff_loopback_is_a_loopback_net` flag.
        pub fn iff_loopback_is_a_loopback_net(&self) -> bool {
            ((self.flags >> 3) & 1) == 1
        }

        /// Sets the `iff_loopback_is_a_loopback_net` flag.
        pub fn set_iff_loopback_is_a_loopback_net(&mut self, iff_loopback_is_a_loopback_net: bool) {
            self.flags ^= (!(iff_loopback_is_a_loopback_net as u32)) & (1 << 3)
        }

        /// Gets the `iff_debug_broadcast_address_valid` flag.
        pub fn iff_debug_broadcast_address_valid(&self) -> bool {
            ((self.flags >> 2) & 1) == 1
        }

        /// Sets the `iff_debug_broadcast_address_valid` flag.
        pub fn set_iff_debug_broadcast_address_valid(
            &mut self,
            iff_debug_broadcast_address_valid: bool,
        ) {
            self.flags ^= (!(iff_debug_broadcast_address_valid as u32)) & (1 << 2)
        }

        /// Gets the `iff_broadcast_broadcast_address_valid` flag.
        pub fn iff_broadcast_broadcast_address_valid(&self) -> bool {
            ((self.flags >> 1) & 1) == 1
        }

        /// Sets the `iff_broadcast_broadcast_address_valid` flag.
        pub fn set_iff_broadcast_broadcast_address_valid(
            &mut self,
            iff_broadcast_broadcast_address_valid: bool,
        ) {
            self.flags ^= (!(iff_broadcast_broadcast_address_valid as u32)) & (1 << 1)
        }

        /// Gets the `iff_up_interface_is_up` flag.
        pub fn iff_up_interface_is_up(&self) -> bool {
            ((self.flags >> 0) & 1) == 1
        }

        /// Sets the `iff_up_interface_is_up` flag.
        pub fn set_iff_up_interface_is_up(&mut self, iff_up_interface_is_up: bool) {
            self.flags ^= (!(iff_up_interface_is_up as u32)) & (1 << 0)
        }
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
}

pub mod msg_reset {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Reset the device (host => Piksi)
    ///
    /// This message from the host resets the Piksi back into the bootloader.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgReset {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Reset flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u32,
    }

    impl MsgReset {
        /// Gets the [DefaultSettings][self::DefaultSettings] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `DefaultSettings` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `DefaultSettings` were added.
        pub fn default_settings(&self) -> Result<DefaultSettings, u8> {
            get_bit_range!(self.flags, u32, u8, 0, 0).try_into()
        }

        /// Set the bitrange corresponding to the [DefaultSettings][DefaultSettings] of the `flags` bitfield.
        pub fn set_default_settings(&mut self, default_settings: DefaultSettings) {
            set_bit_range!(&mut self.flags, default_settings, u32, u8, 0, 0);
        }
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

    /// Default settings.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum DefaultSettings {
        /// Preserve existing settings.
        PreserveExistingSettings = 0,

        /// Resore default settings.
        ResoreDefaultSettings = 1,
    }

    impl std::fmt::Display for DefaultSettings {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                DefaultSettings::PreserveExistingSettings => {
                    f.write_str("Preserve existing settings.")
                }
                DefaultSettings::ResoreDefaultSettings => f.write_str("Resore default settings."),
            }
        }
    }

    impl TryFrom<u8> for DefaultSettings {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(DefaultSettings::PreserveExistingSettings),
                1 => Ok(DefaultSettings::ResoreDefaultSettings),
                i => Err(i),
            }
        }
    }
}

pub mod msg_reset_dep {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Reset the device (host => Piksi)
    ///
    /// This message from the host resets the Piksi back into the bootloader.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgResetDep {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
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
}

pub mod msg_reset_filters {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Reset IAR filters (host => Piksi)
    ///
    /// This message resets either the DGNSS Kalman filters or Integer Ambiguity
    /// Resolution (IAR) process.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgResetFilters {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Filter flags
        #[cfg_attr(feature = "serde", serde(rename = "filter"))]
        pub filter: u8,
    }

    impl MsgResetFilters {
        /// Gets the [FilterOrProcessToReset][self::FilterOrProcessToReset] stored in the `filter` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FilterOrProcessToReset` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FilterOrProcessToReset` were added.
        pub fn filter_or_process_to_reset(&self) -> Result<FilterOrProcessToReset, u8> {
            get_bit_range!(self.filter, u8, u8, 1, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FilterOrProcessToReset][FilterOrProcessToReset] of the `filter` bitfield.
        pub fn set_filter_or_process_to_reset(
            &mut self,
            filter_or_process_to_reset: FilterOrProcessToReset,
        ) {
            set_bit_range!(&mut self.filter, filter_or_process_to_reset, u8, u8, 1, 0);
        }
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

    /// Filter or process to reset
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FilterOrProcessToReset {
        /// DGNSS filter
        DgnssFilter = 0,

        /// IAR process
        IarProcess = 1,

        /// Inertial filter
        InertialFilter = 2,
    }

    impl std::fmt::Display for FilterOrProcessToReset {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FilterOrProcessToReset::DgnssFilter => f.write_str("DGNSS filter"),
                FilterOrProcessToReset::IarProcess => f.write_str("IAR process"),
                FilterOrProcessToReset::InertialFilter => f.write_str("Inertial filter"),
            }
        }
    }

    impl TryFrom<u8> for FilterOrProcessToReset {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FilterOrProcessToReset::DgnssFilter),
                1 => Ok(FilterOrProcessToReset::IarProcess),
                2 => Ok(FilterOrProcessToReset::InertialFilter),
                i => Err(i),
            }
        }
    }
}

pub mod msg_set_time {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Send GPS time from host (host => Piksi)
    ///
    /// This message sets up timing functionality using a coarse GPS time estimate
    /// sent by the host.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgSetTime {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
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
}

pub mod msg_specan {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Spectrum analyzer
    ///
    /// Spectrum analyzer packet.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgSpecan {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Channel ID
        #[cfg_attr(feature = "serde", serde(rename = "channel_tag"))]
        pub channel_tag: u16,
        /// Receiver time of this observation
        #[cfg_attr(feature = "serde", serde(rename = "t"))]
        pub t: GpsTime,
        /// Reference frequency of this packet
        #[cfg_attr(feature = "serde", serde(rename = "freq_ref"))]
        pub freq_ref: f32,
        /// Frequency step of points in this packet
        #[cfg_attr(feature = "serde", serde(rename = "freq_step"))]
        pub freq_step: f32,
        /// Reference amplitude of this packet
        #[cfg_attr(feature = "serde", serde(rename = "amplitude_ref"))]
        pub amplitude_ref: f32,
        /// Amplitude unit value of points in this packet
        #[cfg_attr(feature = "serde", serde(rename = "amplitude_unit"))]
        pub amplitude_unit: f32,
        /// Amplitude values (in the above units) of points in this packet
        #[cfg_attr(feature = "serde", serde(rename = "amplitude_value"))]
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
}

pub mod msg_specan_dep {
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
    pub struct MsgSpecanDep {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Channel ID
        #[cfg_attr(feature = "serde", serde(rename = "channel_tag"))]
        pub channel_tag: u16,
        /// Receiver time of this observation
        #[cfg_attr(feature = "serde", serde(rename = "t"))]
        pub t: GpsTimeDep,
        /// Reference frequency of this packet
        #[cfg_attr(feature = "serde", serde(rename = "freq_ref"))]
        pub freq_ref: f32,
        /// Frequency step of points in this packet
        #[cfg_attr(feature = "serde", serde(rename = "freq_step"))]
        pub freq_step: f32,
        /// Reference amplitude of this packet
        #[cfg_attr(feature = "serde", serde(rename = "amplitude_ref"))]
        pub amplitude_ref: f32,
        /// Amplitude unit value of points in this packet
        #[cfg_attr(feature = "serde", serde(rename = "amplitude_unit"))]
        pub amplitude_unit: f32,
        /// Amplitude values (in the above units) of points in this packet
        #[cfg_attr(feature = "serde", serde(rename = "amplitude_value"))]
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
}

pub mod msg_thread_state {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// State of an RTOS thread
    ///
    /// The thread usage message from the device reports real-time operating
    /// system (RTOS) thread usage statistics for the named thread. The reported
    /// percentage values must be normalized.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgThreadState {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Thread name (NULL terminated)
        #[cfg_attr(feature = "serde", serde(rename = "name"))]
        pub name: SbpString<[u8; 20], NullTerminated>,
        /// Percentage cpu use for this thread. Values range from 0 - 1000 and needs
        /// to be renormalized to 100
        #[cfg_attr(feature = "serde", serde(rename = "cpu"))]
        pub cpu: u16,
        /// Free stack space for this thread
        #[cfg_attr(feature = "serde", serde(rename = "stack_free"))]
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
            WireFormat::len(&self.name)
                + WireFormat::len(&self.cpu)
                + WireFormat::len(&self.stack_free)
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
}

pub mod msg_uart_state {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgUartState {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// State of UART A
        #[cfg_attr(feature = "serde", serde(rename = "uart_a"))]
        pub uart_a: UARTChannel,
        /// State of UART B
        #[cfg_attr(feature = "serde", serde(rename = "uart_b"))]
        pub uart_b: UARTChannel,
        /// State of UART FTDI (USB logger)
        #[cfg_attr(feature = "serde", serde(rename = "uart_ftdi"))]
        pub uart_ftdi: UARTChannel,
        /// UART communication latency
        #[cfg_attr(feature = "serde", serde(rename = "latency"))]
        pub latency: Latency,
        /// Observation receipt period
        #[cfg_attr(feature = "serde", serde(rename = "obs_period"))]
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
}

pub mod msg_uart_state_depa {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Deprecated
    ///
    /// Deprecated
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgUartStateDepa {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// State of UART A
        #[cfg_attr(feature = "serde", serde(rename = "uart_a"))]
        pub uart_a: UARTChannel,
        /// State of UART B
        #[cfg_attr(feature = "serde", serde(rename = "uart_b"))]
        pub uart_b: UARTChannel,
        /// State of UART FTDI (USB logger)
        #[cfg_attr(feature = "serde", serde(rename = "uart_ftdi"))]
        pub uart_ftdi: UARTChannel,
        /// UART communication latency
        #[cfg_attr(feature = "serde", serde(rename = "latency"))]
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
}

pub mod network_usage {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Bandwidth usage measurement for a single interface
    ///
    /// The bandwidth usage for each interface can be reported within this struct
    /// and utilize multiple fields to fully specify the type of traffic that is
    /// being tracked. As either the interval of collection or the collection time
    /// may vary, both a timestamp and period field is provided, though may not
    /// necessarily be populated with a value.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct NetworkUsage {
        /// Duration over which the measurement was collected
        #[cfg_attr(feature = "serde", serde(rename = "duration"))]
        pub duration: u64,
        /// Number of bytes handled in total within period
        #[cfg_attr(feature = "serde", serde(rename = "total_bytes"))]
        pub total_bytes: u64,
        /// Number of bytes transmitted within period
        #[cfg_attr(feature = "serde", serde(rename = "rx_bytes"))]
        pub rx_bytes: u32,
        /// Number of bytes received within period
        #[cfg_attr(feature = "serde", serde(rename = "tx_bytes"))]
        pub tx_bytes: u32,
        /// Interface Name
        #[cfg_attr(feature = "serde", serde(rename = "interface_name"))]
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
}

pub mod period {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// base station observation message receipt period
    ///
    /// Statistics on the period of observations received from the base station.
    /// As complete observation sets are received, their time of reception is
    /// compared with the prior set''s time of reception. This measurement
    /// provides a proxy for link quality as incomplete or missing sets will
    /// increase the period.  Long periods can cause momentary RTK solution
    /// outages.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct Period {
        /// Average period
        #[cfg_attr(feature = "serde", serde(rename = "avg"))]
        pub avg: i32,
        /// Minimum period
        #[cfg_attr(feature = "serde", serde(rename = "pmin"))]
        pub pmin: i32,
        /// Maximum period
        #[cfg_attr(feature = "serde", serde(rename = "pmax"))]
        pub pmax: i32,
        /// Smoothed estimate of the current period
        #[cfg_attr(feature = "serde", serde(rename = "current"))]
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
}

pub mod uart_channel {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// State of the UART channel
    ///
    /// Throughput, utilization, and error counts on the RX/TX buffers of this
    /// UART channel. The reported percentage values must be normalized.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct UARTChannel {
        /// UART transmit throughput
        #[cfg_attr(feature = "serde", serde(rename = "tx_throughput"))]
        pub tx_throughput: f32,
        /// UART receive throughput
        #[cfg_attr(feature = "serde", serde(rename = "rx_throughput"))]
        pub rx_throughput: f32,
        /// UART CRC error count
        #[cfg_attr(feature = "serde", serde(rename = "crc_error_count"))]
        pub crc_error_count: u16,
        /// UART IO error count
        #[cfg_attr(feature = "serde", serde(rename = "io_error_count"))]
        pub io_error_count: u16,
        /// UART transmit buffer percentage utilization (ranges from 0 to 255)
        #[cfg_attr(feature = "serde", serde(rename = "tx_buffer_level"))]
        pub tx_buffer_level: u8,
        /// UART receive buffer percentage utilization (ranges from 0 to 255)
        #[cfg_attr(feature = "serde", serde(rename = "rx_buffer_level"))]
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
}
