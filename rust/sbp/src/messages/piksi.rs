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
// Automatically generated from yaml/swiftnav/sbp/piksi.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
// System health, configuration, and diagnostic messages specific to
// the Piksi L1 receiver, including a variety of legacy messages that
// may no longer be used.
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
use super::gnss::*;

// Legacy message to load satellite almanac (host => Piksi)
//
// This is a legacy message for sending and loading a satellite
// alamanac onto the Piksi's flash memory from the host.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgAlmanac {
    pub sender_id: Option<u16>,
}

impl MsgAlmanac {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAlmanac, ::parser::MessageError> {
        Ok(MsgAlmanac { sender_id: None })
    }
}
impl super::SBPMessage for MsgAlmanac {
    const MSG_ID: u16 = 105;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Send GPS time from host (host => Piksi)
//
// This message sets up timing functionality using a coarse GPS
// time estimate sent by the host.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSetTime {
    pub sender_id: Option<u16>,
}

impl MsgSetTime {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSetTime, ::parser::MessageError> {
        Ok(MsgSetTime { sender_id: None })
    }
}
impl super::SBPMessage for MsgSetTime {
    const MSG_ID: u16 = 104;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Reset the device (host => Piksi)
//
// This message from the host resets the Piksi back into the
// bootloader.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgReset {
    pub sender_id: Option<u16>,
    pub flags: u32,
    // ^ Reset flags
}

impl MsgReset {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgReset, ::parser::MessageError> {
        Ok(MsgReset {
            sender_id: None,
            flags: _buf.read_u32::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgReset {
    const MSG_ID: u16 = 182;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Reset the device (host => Piksi)
//
// This message from the host resets the Piksi back into the
// bootloader.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgResetDep {
    pub sender_id: Option<u16>,
}

impl MsgResetDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgResetDep, ::parser::MessageError> {
        Ok(MsgResetDep { sender_id: None })
    }
}
impl super::SBPMessage for MsgResetDep {
    const MSG_ID: u16 = 178;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Legacy message for CW interference channel (Piksi => host)
//
// This is an unused legacy message for result reporting from the
// CW interference channel on the SwiftNAP. This message will be
// removed in a future release.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgCwResults {
    pub sender_id: Option<u16>,
}

impl MsgCwResults {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCwResults, ::parser::MessageError> {
        Ok(MsgCwResults { sender_id: None })
    }
}
impl super::SBPMessage for MsgCwResults {
    const MSG_ID: u16 = 192;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Legacy message for CW interference channel (host => Piksi)
//
// This is an unused legacy message from the host for starting
// the CW interference channel on the SwiftNAP. This message will
// be removed in a future release.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgCwStart {
    pub sender_id: Option<u16>,
}

impl MsgCwStart {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCwStart, ::parser::MessageError> {
        Ok(MsgCwStart { sender_id: None })
    }
}
impl super::SBPMessage for MsgCwStart {
    const MSG_ID: u16 = 193;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Reset IAR filters (host => Piksi)
//
// This message resets either the DGNSS Kalman filters or Integer
// Ambiguity Resolution (IAR) process.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgResetFilters {
    pub sender_id: Option<u16>,
    pub filter: u8,
    // ^ Filter flags
}

impl MsgResetFilters {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgResetFilters, ::parser::MessageError> {
        Ok(MsgResetFilters {
            sender_id: None,
            filter: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgResetFilters {
    const MSG_ID: u16 = 34;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Deprecated
//
// Deprecated
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgInitBaseDep {
    pub sender_id: Option<u16>,
}

impl MsgInitBaseDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgInitBaseDep, ::parser::MessageError> {
        Ok(MsgInitBaseDep { sender_id: None })
    }
}
impl super::SBPMessage for MsgInitBaseDep {
    const MSG_ID: u16 = 35;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// State of an RTOS thread
//
// The thread usage message from the device reports real-time
// operating system (RTOS) thread usage statistics for the named
// thread. The reported percentage values must be normalized.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgThreadState {
    pub sender_id: Option<u16>,
    pub name: String,
    // ^ Thread name (NULL terminated)
    pub cpu: u16,
    // ^ Percentage cpu use for this thread. Values range from 0 - 1000 and needs
    // to be renormalized to 100
    pub stack_free: u32,
    // ^ Free stack space for this thread
}

impl MsgThreadState {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgThreadState, ::parser::MessageError> {
        Ok(MsgThreadState {
            sender_id: None,
            name: ::parser::read_string_limit(_buf, 20)?,
            cpu: _buf.read_u16::<LittleEndian>()?,
            stack_free: _buf.read_u32::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgThreadState {
    const MSG_ID: u16 = 23;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// State of the UART channel
//
// Throughput, utilization, and error counts on the RX/TX buffers
// of this UART channel. The reported percentage values must
// be normalized.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct UARTChannel {
    pub tx_throughput: f32,
    // ^ UART transmit throughput
    pub rx_throughput: f32,
    // ^ UART receive throughput
    pub crc_error_count: u16,
    // ^ UART CRC error count
    pub io_error_count: u16,
    // ^ UART IO error count
    pub tx_buffer_level: u8,
    // ^ UART transmit buffer percentage utilization (ranges from 0 to 255)
    pub rx_buffer_level: u8,
    // ^ UART receive buffer percentage utilization (ranges from 0 to 255)
}

impl UARTChannel {
    pub fn parse(_buf: &mut &[u8]) -> Result<UARTChannel, ::parser::MessageError> {
        Ok(UARTChannel {
            tx_throughput: _buf.read_f32::<LittleEndian>()?,
            rx_throughput: _buf.read_f32::<LittleEndian>()?,
            crc_error_count: _buf.read_u16::<LittleEndian>()?,
            io_error_count: _buf.read_u16::<LittleEndian>()?,
            tx_buffer_level: _buf.read_u8()?,
            rx_buffer_level: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<UARTChannel>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(UARTChannel::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<UARTChannel>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(UARTChannel::parse(buf)?);
        }
        Ok(v)
    }
}

// base station observation message receipt period
//
// Statistics on the period of observations received from the base
// station. As complete observation sets are received, their time
// of reception is compared with the prior set''s time of reception.
// This measurement provides a proxy for link quality as incomplete
// or missing sets will increase the period.  Long periods
// can cause momentary RTK solution outages.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct Period {
    pub avg: i32,
    // ^ Average period
    pub pmin: i32,
    // ^ Minimum period
    pub pmax: i32,
    // ^ Maximum period
    pub current: i32,
    // ^ Smoothed estimate of the current period
}

impl Period {
    pub fn parse(_buf: &mut &[u8]) -> Result<Period, ::parser::MessageError> {
        Ok(Period {
            avg: _buf.read_i32::<LittleEndian>()?,
            pmin: _buf.read_i32::<LittleEndian>()?,
            pmax: _buf.read_i32::<LittleEndian>()?,
            current: _buf.read_i32::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<Period>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(Period::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<Period>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(Period::parse(buf)?);
        }
        Ok(v)
    }
}

// Receiver-to-base station latency
//
// Statistics on the latency of observations received from the base
// station. As observation packets are received their GPS time is
// compared to the current GPS time calculated locally by the
// receiver to give a precise measurement of the end-to-end
// communication latency in the system.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct Latency {
    pub avg: i32,
    // ^ Average latency
    pub lmin: i32,
    // ^ Minimum latency
    pub lmax: i32,
    // ^ Maximum latency
    pub current: i32,
    // ^ Smoothed estimate of the current latency
}

impl Latency {
    pub fn parse(_buf: &mut &[u8]) -> Result<Latency, ::parser::MessageError> {
        Ok(Latency {
            avg: _buf.read_i32::<LittleEndian>()?,
            lmin: _buf.read_i32::<LittleEndian>()?,
            lmax: _buf.read_i32::<LittleEndian>()?,
            current: _buf.read_i32::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<Latency>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(Latency::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<Latency>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(Latency::parse(buf)?);
        }
        Ok(v)
    }
}

// State of the UART channels
//
// The UART message reports data latency and throughput of the UART
// channels providing SBP I/O. On the default Piksi configuration,
// UARTs A and B are used for telemetry radios, but can also be
// host access ports for embedded hosts, or other interfaces in
// future. The reported percentage values must be normalized.
// Observations latency and period can be used to assess the
// health of the differential corrections link. Latency provides
// the timeliness of received base observations while the
// period indicates their likelihood of transmission.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgUartState {
    pub sender_id: Option<u16>,
    pub uart_a: UARTChannel,
    // ^ State of UART A
    pub uart_b: UARTChannel,
    // ^ State of UART B
    pub uart_ftdi: UARTChannel,
    // ^ State of UART FTDI (USB logger)
    pub latency: Latency,
    // ^ UART communication latency
    pub obs_period: Period,
    // ^ Observation receipt period
}

impl MsgUartState {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgUartState, ::parser::MessageError> {
        Ok(MsgUartState {
            sender_id: None,
            uart_a: UARTChannel::parse(_buf)?,
            uart_b: UARTChannel::parse(_buf)?,
            uart_ftdi: UARTChannel::parse(_buf)?,
            latency: Latency::parse(_buf)?,
            obs_period: Period::parse(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgUartState {
    const MSG_ID: u16 = 29;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Deprecated
//
// Deprecated
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgUartStateDepa {
    pub sender_id: Option<u16>,
    pub uart_a: UARTChannel,
    // ^ State of UART A
    pub uart_b: UARTChannel,
    // ^ State of UART B
    pub uart_ftdi: UARTChannel,
    // ^ State of UART FTDI (USB logger)
    pub latency: Latency,
    // ^ UART communication latency
}

impl MsgUartStateDepa {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgUartStateDepa, ::parser::MessageError> {
        Ok(MsgUartStateDepa {
            sender_id: None,
            uart_a: UARTChannel::parse(_buf)?,
            uart_b: UARTChannel::parse(_buf)?,
            uart_ftdi: UARTChannel::parse(_buf)?,
            latency: Latency::parse(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgUartStateDepa {
    const MSG_ID: u16 = 24;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// State of the Integer Ambiguity Resolution (IAR) process
//
// This message reports the state of the Integer Ambiguity
// Resolution (IAR) process, which resolves unknown integer
// ambiguities from double-differenced carrier-phase measurements
// from satellite observations.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgIarState {
    pub sender_id: Option<u16>,
    pub num_hyps: u32,
    // ^ Number of integer ambiguity hypotheses remaining
}

impl MsgIarState {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgIarState, ::parser::MessageError> {
        Ok(MsgIarState {
            sender_id: None,
            num_hyps: _buf.read_u32::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgIarState {
    const MSG_ID: u16 = 25;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Mask a satellite from use in Piksi subsystems
//
// This message allows setting a mask to prevent a particular satellite
// from being used in various Piksi subsystems.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgMaskSatellite {
    pub sender_id: Option<u16>,
    pub mask: u8,
    // ^ Mask of systems that should ignore this satellite.
    pub sid: GnssSignal,
    // ^ GNSS signal for which the mask is applied
}

impl MsgMaskSatellite {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgMaskSatellite, ::parser::MessageError> {
        Ok(MsgMaskSatellite {
            sender_id: None,
            mask: _buf.read_u8()?,
            sid: GnssSignal::parse(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgMaskSatellite {
    const MSG_ID: u16 = 43;

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
pub struct MsgMaskSatelliteDep {
    pub sender_id: Option<u16>,
    pub mask: u8,
    // ^ Mask of systems that should ignore this satellite.
    pub sid: GnssSignalDep,
    // ^ GNSS signal for which the mask is applied
}

impl MsgMaskSatelliteDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgMaskSatelliteDep, ::parser::MessageError> {
        Ok(MsgMaskSatelliteDep {
            sender_id: None,
            mask: _buf.read_u8()?,
            sid: GnssSignalDep::parse(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgMaskSatelliteDep {
    const MSG_ID: u16 = 27;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Device temperature and voltage levels
//
// This message contains temperature and voltage level measurements from the
// processor's monitoring system and the RF frontend die temperature if
// available.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgDeviceMonitor {
    pub sender_id: Option<u16>,
    pub dev_vin: i16,
    // ^ Device V_in
    pub cpu_vint: i16,
    // ^ Processor V_int
    pub cpu_vaux: i16,
    // ^ Processor V_aux
    pub cpu_temperature: i16,
    // ^ Processor temperature
    pub fe_temperature: i16,
    // ^ Frontend temperature (if available)
}

impl MsgDeviceMonitor {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgDeviceMonitor, ::parser::MessageError> {
        Ok(MsgDeviceMonitor {
            sender_id: None,
            dev_vin: _buf.read_i16::<LittleEndian>()?,
            cpu_vint: _buf.read_i16::<LittleEndian>()?,
            cpu_vaux: _buf.read_i16::<LittleEndian>()?,
            cpu_temperature: _buf.read_i16::<LittleEndian>()?,
            fe_temperature: _buf.read_i16::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgDeviceMonitor {
    const MSG_ID: u16 = 181;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Execute a command (host => device)
//
// Request the recipient to execute an command.
// Output will be sent in MSG_LOG messages, and the exit
// code will be returned with MSG_COMMAND_RESP.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgCommandReq {
    pub sender_id: Option<u16>,
    pub sequence: u32,
    // ^ Sequence number
    pub command: String,
    // ^ Command line to execute
}

impl MsgCommandReq {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCommandReq, ::parser::MessageError> {
        Ok(MsgCommandReq {
            sender_id: None,
            sequence: _buf.read_u32::<LittleEndian>()?,
            command: ::parser::read_string(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgCommandReq {
    const MSG_ID: u16 = 184;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Exit code from executed command (device => host)
//
// The response to MSG_COMMAND_REQ with the return code of
// the command.  A return code of zero indicates success.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgCommandResp {
    pub sender_id: Option<u16>,
    pub sequence: u32,
    // ^ Sequence number
    pub code: i32,
    // ^ Exit code
}

impl MsgCommandResp {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCommandResp, ::parser::MessageError> {
        Ok(MsgCommandResp {
            sender_id: None,
            sequence: _buf.read_u32::<LittleEndian>()?,
            code: _buf.read_i32::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgCommandResp {
    const MSG_ID: u16 = 185;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Command output
//
// Returns the standard output and standard error of the
// command requested by MSG_COMMAND_REQ.
// The sequence number can be used to filter for filtering
// the correct command.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgCommandOutput {
    pub sender_id: Option<u16>,
    pub sequence: u32,
    // ^ Sequence number
    pub line: String,
    // ^ Line of standard output or standard error
}

impl MsgCommandOutput {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCommandOutput, ::parser::MessageError> {
        Ok(MsgCommandOutput {
            sender_id: None,
            sequence: _buf.read_u32::<LittleEndian>()?,
            line: ::parser::read_string(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgCommandOutput {
    const MSG_ID: u16 = 188;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Request state of Piksi network interfaces
//
// Request state of Piksi network interfaces.
// Output will be sent in MSG_NETWORK_STATE_RESP messages
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgNetworkStateReq {
    pub sender_id: Option<u16>,
}

impl MsgNetworkStateReq {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgNetworkStateReq, ::parser::MessageError> {
        Ok(MsgNetworkStateReq { sender_id: None })
    }
}
impl super::SBPMessage for MsgNetworkStateReq {
    const MSG_ID: u16 = 186;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// State of network interface
//
// The state of a network interface on the Piksi.
// Data is made to reflect output of ifaddrs struct returned by getifaddrs
// in c.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgNetworkStateResp {
    pub sender_id: Option<u16>,
    pub ipv4_address: Vec<u8>,
    // ^ IPv4 address (all zero when unavailable)
    pub ipv4_mask_size: u8,
    // ^ IPv4 netmask CIDR notation
    pub ipv6_address: Vec<u8>,
    // ^ IPv6 address (all zero when unavailable)
    pub ipv6_mask_size: u8,
    // ^ IPv6 netmask CIDR notation
    pub rx_bytes: u32,
    // ^ Number of Rx bytes
    pub tx_bytes: u32,
    // ^ Number of Tx bytes
    pub interface_name: String,
    // ^ Interface Name
    pub flags: u32,
    // ^ Interface flags from SIOCGIFFLAGS
}

impl MsgNetworkStateResp {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgNetworkStateResp, ::parser::MessageError> {
        Ok(MsgNetworkStateResp {
            sender_id: None,
            ipv4_address: ::parser::read_u8_array_limit(_buf, 4)?,
            ipv4_mask_size: _buf.read_u8()?,
            ipv6_address: ::parser::read_u8_array_limit(_buf, 16)?,
            ipv6_mask_size: _buf.read_u8()?,
            rx_bytes: _buf.read_u32::<LittleEndian>()?,
            tx_bytes: _buf.read_u32::<LittleEndian>()?,
            interface_name: ::parser::read_string_limit(_buf, 16)?,
            flags: _buf.read_u32::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgNetworkStateResp {
    const MSG_ID: u16 = 187;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Bandwidth usage measurement for a single interface.
//
// The bandwidth usage for each interface can be reported
// within this struct and utilize multiple fields to fully
// specify the type of traffic that is being tracked. As
// either the interval of collection or the collection time
// may vary, both a timestamp and period field is provided,
// though may not necessarily be populated with a value.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct NetworkUsage {
    pub duration: u64,
    // ^ Duration over which the measurement was collected
    pub total_bytes: u64,
    // ^ Number of bytes handled in total within period
    pub rx_bytes: u32,
    // ^ Number of bytes transmitted within period
    pub tx_bytes: u32,
    // ^ Number of bytes received within period
    pub interface_name: String,
    // ^ Interface Name
}

impl NetworkUsage {
    pub fn parse(_buf: &mut &[u8]) -> Result<NetworkUsage, ::parser::MessageError> {
        Ok(NetworkUsage {
            duration: _buf.read_u64::<LittleEndian>()?,
            total_bytes: _buf.read_u64::<LittleEndian>()?,
            rx_bytes: _buf.read_u32::<LittleEndian>()?,
            tx_bytes: _buf.read_u32::<LittleEndian>()?,
            interface_name: ::parser::read_string_limit(_buf, 16)?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<NetworkUsage>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(NetworkUsage::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<NetworkUsage>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(NetworkUsage::parse(buf)?);
        }
        Ok(v)
    }
}

// Bandwidth usage reporting message
//
// The bandwidth usage, a list of usage by interface.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgNetworkBandwidthUsage {
    pub sender_id: Option<u16>,
    pub interfaces: Vec<NetworkUsage>,
    // ^ Usage measurement array
}

impl MsgNetworkBandwidthUsage {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgNetworkBandwidthUsage, ::parser::MessageError> {
        Ok(MsgNetworkBandwidthUsage {
            sender_id: None,
            interfaces: NetworkUsage::parse_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgNetworkBandwidthUsage {
    const MSG_ID: u16 = 189;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Cell modem information update message
//
// If a cell modem is present on a piksi device, this message
// will be send periodically to update the host on the status
// of the modem and its various parameters.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgCellModemStatus {
    pub sender_id: Option<u16>,
    pub signal_strength: i8,
    // ^ Received cell signal strength in dBm, zero translates to unknown
    pub signal_error_rate: f32,
    // ^ BER as reported by the modem, zero translates to unknown
    pub reserved: Vec<u8>,
    // ^ Unspecified data TBD for this schema
}

impl MsgCellModemStatus {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCellModemStatus, ::parser::MessageError> {
        Ok(MsgCellModemStatus {
            sender_id: None,
            signal_strength: _buf.read_i8()?,
            signal_error_rate: _buf.read_f32::<LittleEndian>()?,
            reserved: ::parser::read_u8_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgCellModemStatus {
    const MSG_ID: u16 = 190;

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
pub struct MsgSpecanDep {
    pub sender_id: Option<u16>,
    pub channel_tag: u16,
    // ^ Channel ID
    pub t: GPSTimeDep,
    // ^ Receiver time of this observation
    pub freq_ref: f32,
    // ^ Reference frequency of this packet
    pub freq_step: f32,
    // ^ Frequency step of points in this packet
    pub amplitude_ref: f32,
    // ^ Reference amplitude of this packet
    pub amplitude_unit: f32,
    // ^ Amplitude unit value of points in this packet
    pub amplitude_value: Vec<u8>,
    // ^ Amplitude values (in the above units) of points in this packet
}

impl MsgSpecanDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSpecanDep, ::parser::MessageError> {
        Ok(MsgSpecanDep {
            sender_id: None,
            channel_tag: _buf.read_u16::<LittleEndian>()?,
            t: GPSTimeDep::parse(_buf)?,
            freq_ref: _buf.read_f32::<LittleEndian>()?,
            freq_step: _buf.read_f32::<LittleEndian>()?,
            amplitude_ref: _buf.read_f32::<LittleEndian>()?,
            amplitude_unit: _buf.read_f32::<LittleEndian>()?,
            amplitude_value: ::parser::read_u8_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgSpecanDep {
    const MSG_ID: u16 = 80;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Spectrum analyzer
//
// Spectrum analyzer packet.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSpecan {
    pub sender_id: Option<u16>,
    pub channel_tag: u16,
    // ^ Channel ID
    pub t: GPSTime,
    // ^ Receiver time of this observation
    pub freq_ref: f32,
    // ^ Reference frequency of this packet
    pub freq_step: f32,
    // ^ Frequency step of points in this packet
    pub amplitude_ref: f32,
    // ^ Reference amplitude of this packet
    pub amplitude_unit: f32,
    // ^ Amplitude unit value of points in this packet
    pub amplitude_value: Vec<u8>,
    // ^ Amplitude values (in the above units) of points in this packet
}

impl MsgSpecan {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSpecan, ::parser::MessageError> {
        Ok(MsgSpecan {
            sender_id: None,
            channel_tag: _buf.read_u16::<LittleEndian>()?,
            t: GPSTime::parse(_buf)?,
            freq_ref: _buf.read_f32::<LittleEndian>()?,
            freq_step: _buf.read_f32::<LittleEndian>()?,
            amplitude_ref: _buf.read_f32::<LittleEndian>()?,
            amplitude_unit: _buf.read_f32::<LittleEndian>()?,
            amplitude_value: ::parser::read_u8_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgSpecan {
    const MSG_ID: u16 = 81;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// RF AGC status
//
// This message describes the gain of each channel in the receiver frontend. Each
// gain is encoded as a non-dimensional percentage relative to the maximum range
// possible for the gain stage of the frontend. By convention, each gain array
// has 8 entries and the index of the array corresponding to the index of the rf channel
// in the frontend. A gain of 127 percent encodes that rf channel is not present in the hardware.
// A negative value implies an error for the particular gain stage as reported by the frontend.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgFrontEndGain {
    pub sender_id: Option<u16>,
    pub rf_gain: Vec<i8>,
    // ^ RF gain for each frontend channel
    pub if_gain: Vec<i8>,
    // ^ Intermediate frequency gain for each frontend channel
}

impl MsgFrontEndGain {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFrontEndGain, ::parser::MessageError> {
        Ok(MsgFrontEndGain {
            sender_id: None,
            rf_gain: ::parser::read_s8_array_limit(_buf, 8)?,
            if_gain: ::parser::read_s8_array_limit(_buf, 8)?,
        })
    }
}
impl super::SBPMessage for MsgFrontEndGain {
    const MSG_ID: u16 = 191;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}
