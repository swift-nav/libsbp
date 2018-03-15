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
use self::byteorder::{LittleEndian,ReadBytesExt};
use super::gnss::*;


// Legacy message to load satellite almanac (host => Piksi)
//
// This is a legacy message for sending and loading a satellite
// alamanac onto the Piksi's flash memory from the host.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgAlmanac {
}

impl MsgAlmanac {
    pub const TYPE: u16 = 105;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAlmanac, ::Error> {
        Ok( MsgAlmanac{
        } )
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
}

impl MsgSetTime {
    pub const TYPE: u16 = 104;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSetTime, ::Error> {
        Ok( MsgSetTime{
        } )
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
    pub flags: u32,
        // ^ Reset flags
}

impl MsgReset {
    pub const TYPE: u16 = 182;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgReset, ::Error> {
        Ok( MsgReset{
            flags: _buf.read_u32::<LittleEndian>()?,
        } )
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
}

impl MsgResetDep {
    pub const TYPE: u16 = 178;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgResetDep, ::Error> {
        Ok( MsgResetDep{
        } )
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
}

impl MsgCwResults {
    pub const TYPE: u16 = 192;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCwResults, ::Error> {
        Ok( MsgCwResults{
        } )
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
}

impl MsgCwStart {
    pub const TYPE: u16 = 193;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCwStart, ::Error> {
        Ok( MsgCwStart{
        } )
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
    pub filter: u8,
        // ^ Filter flags
}

impl MsgResetFilters {
    pub const TYPE: u16 = 34;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgResetFilters, ::Error> {
        Ok( MsgResetFilters{
            filter: _buf.read_u8()?,
        } )
    }
}


// Initialize IAR from known baseline (host => device)
//
// This message initializes the integer ambiguity resolution (IAR)
// process on the Piksi to use an assumed baseline position between
// the base station and rover receivers. Warns via MSG_PRINT if
// there aren't a shared minimum number (4) of satellite
// observations between the two.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgInitBase {
}

impl MsgInitBase {
    pub const TYPE: u16 = 35;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgInitBase, ::Error> {
        Ok( MsgInitBase{
        } )
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
    pub name: String,
        // ^ Thread name (NULL terminated)
    pub cpu: u16,
        // ^ Percentage cpu use for this thread. Values range from 0 - 1000 and needs
        // to be renormalized to 100
    pub stack_free: u32,
        // ^ Free stack space for this thread
}

impl MsgThreadState {
    pub const TYPE: u16 = 23;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgThreadState, ::Error> {
        Ok( MsgThreadState{
            name: ::read_string_limit(_buf, 20)?,
            cpu: _buf.read_u16::<LittleEndian>()?,
            stack_free: _buf.read_u32::<LittleEndian>()?,
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<UARTChannel, ::Error> {
        Ok( UARTChannel{
            tx_throughput: _buf.read_f32::<LittleEndian>()?,
            rx_throughput: _buf.read_f32::<LittleEndian>()?,
            crc_error_count: _buf.read_u16::<LittleEndian>()?,
            io_error_count: _buf.read_u16::<LittleEndian>()?,
            tx_buffer_level: _buf.read_u8()?,
            rx_buffer_level: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<UARTChannel>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( UARTChannel::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<UARTChannel>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( UARTChannel::parse(buf)? );
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
    pub fn parse(_buf: &mut &[u8]) -> Result<Period, ::Error> {
        Ok( Period{
            avg: _buf.read_i32::<LittleEndian>()?,
            pmin: _buf.read_i32::<LittleEndian>()?,
            pmax: _buf.read_i32::<LittleEndian>()?,
            current: _buf.read_i32::<LittleEndian>()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<Period>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( Period::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<Period>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( Period::parse(buf)? );
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
    pub fn parse(_buf: &mut &[u8]) -> Result<Latency, ::Error> {
        Ok( Latency{
            avg: _buf.read_i32::<LittleEndian>()?,
            lmin: _buf.read_i32::<LittleEndian>()?,
            lmax: _buf.read_i32::<LittleEndian>()?,
            current: _buf.read_i32::<LittleEndian>()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<Latency>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( Latency::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<Latency>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( Latency::parse(buf)? );
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
    pub const TYPE: u16 = 29;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgUartState, ::Error> {
        Ok( MsgUartState{
            uart_a: UARTChannel::parse(_buf)?,
            uart_b: UARTChannel::parse(_buf)?,
            uart_ftdi: UARTChannel::parse(_buf)?,
            latency: Latency::parse(_buf)?,
            obs_period: Period::parse(_buf)?,
        } )
    }
}


// Deprecated
//
// Deprecated
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgUartStateDepa {
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
    pub const TYPE: u16 = 24;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgUartStateDepa, ::Error> {
        Ok( MsgUartStateDepa{
            uart_a: UARTChannel::parse(_buf)?,
            uart_b: UARTChannel::parse(_buf)?,
            uart_ftdi: UARTChannel::parse(_buf)?,
            latency: Latency::parse(_buf)?,
        } )
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
    pub num_hyps: u32,
        // ^ Number of integer ambiguity hypotheses remaining
}

impl MsgIarState {
    pub const TYPE: u16 = 25;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgIarState, ::Error> {
        Ok( MsgIarState{
            num_hyps: _buf.read_u32::<LittleEndian>()?,
        } )
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
    pub mask: u8,
        // ^ Mask of systems that should ignore this satellite.
    pub sid: GnssSignal,
        // ^ GNSS signal for which the mask is applied
}

impl MsgMaskSatellite {
    pub const TYPE: u16 = 43;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgMaskSatellite, ::Error> {
        Ok( MsgMaskSatellite{
            mask: _buf.read_u8()?,
            sid: GnssSignal::parse(_buf)?,
        } )
    }
}


// Deprecated
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgMaskSatelliteDep {
    pub mask: u8,
        // ^ Mask of systems that should ignore this satellite.
    pub sid: GnssSignalDep,
        // ^ GNSS signal for which the mask is applied
}

impl MsgMaskSatelliteDep {
    pub const TYPE: u16 = 27;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgMaskSatelliteDep, ::Error> {
        Ok( MsgMaskSatelliteDep{
            mask: _buf.read_u8()?,
            sid: GnssSignalDep::parse(_buf)?,
        } )
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
    pub const TYPE: u16 = 181;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgDeviceMonitor, ::Error> {
        Ok( MsgDeviceMonitor{
            dev_vin: _buf.read_i16::<LittleEndian>()?,
            cpu_vint: _buf.read_i16::<LittleEndian>()?,
            cpu_vaux: _buf.read_i16::<LittleEndian>()?,
            cpu_temperature: _buf.read_i16::<LittleEndian>()?,
            fe_temperature: _buf.read_i16::<LittleEndian>()?,
        } )
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
    pub sequence: u32,
        // ^ Sequence number
    pub command: String,
        // ^ Command line to execute
}

impl MsgCommandReq {
    pub const TYPE: u16 = 184;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCommandReq, ::Error> {
        Ok( MsgCommandReq{
            sequence: _buf.read_u32::<LittleEndian>()?,
            command: ::read_string(_buf)?,
        } )
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
    pub sequence: u32,
        // ^ Sequence number
    pub code: i32,
        // ^ Exit code
}

impl MsgCommandResp {
    pub const TYPE: u16 = 185;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCommandResp, ::Error> {
        Ok( MsgCommandResp{
            sequence: _buf.read_u32::<LittleEndian>()?,
            code: _buf.read_i32::<LittleEndian>()?,
        } )
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
    pub sequence: u32,
        // ^ Sequence number
    pub line: String,
        // ^ Line of standard output or standard error
}

impl MsgCommandOutput {
    pub const TYPE: u16 = 188;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCommandOutput, ::Error> {
        Ok( MsgCommandOutput{
            sequence: _buf.read_u32::<LittleEndian>()?,
            line: ::read_string(_buf)?,
        } )
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
}

impl MsgNetworkStateReq {
    pub const TYPE: u16 = 186;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgNetworkStateReq, ::Error> {
        Ok( MsgNetworkStateReq{
        } )
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
    pub const TYPE: u16 = 187;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgNetworkStateResp, ::Error> {
        Ok( MsgNetworkStateResp{
            ipv4_address: ::read_u8_array_limit(_buf, 4)?,
            ipv4_mask_size: _buf.read_u8()?,
            ipv6_address: ::read_u8_array_limit(_buf, 16)?,
            ipv6_mask_size: _buf.read_u8()?,
            rx_bytes: _buf.read_u32::<LittleEndian>()?,
            tx_bytes: _buf.read_u32::<LittleEndian>()?,
            interface_name: ::read_string_limit(_buf, 16)?,
            flags: _buf.read_u32::<LittleEndian>()?,
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<NetworkUsage, ::Error> {
        Ok( NetworkUsage{
            duration: _buf.read_u64::<LittleEndian>()?,
            total_bytes: _buf.read_u64::<LittleEndian>()?,
            rx_bytes: _buf.read_u32::<LittleEndian>()?,
            tx_bytes: _buf.read_u32::<LittleEndian>()?,
            interface_name: ::read_string_limit(_buf, 16)?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<NetworkUsage>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( NetworkUsage::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<NetworkUsage>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( NetworkUsage::parse(buf)? );
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
    pub interfaces: Vec<NetworkUsage>,
        // ^ Usage measurement array
}

impl MsgNetworkBandwidthUsage {
    pub const TYPE: u16 = 189;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgNetworkBandwidthUsage, ::Error> {
        Ok( MsgNetworkBandwidthUsage{
            interfaces: NetworkUsage::parse_array(_buf)?,
        } )
    }
}


// Deprecated
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSpecanDep {
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
    pub const TYPE: u16 = 80;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSpecanDep, ::Error> {
        Ok( MsgSpecanDep{
            channel_tag: _buf.read_u16::<LittleEndian>()?,
            t: GPSTimeDep::parse(_buf)?,
            freq_ref: _buf.read_f32::<LittleEndian>()?,
            freq_step: _buf.read_f32::<LittleEndian>()?,
            amplitude_ref: _buf.read_f32::<LittleEndian>()?,
            amplitude_unit: _buf.read_f32::<LittleEndian>()?,
            amplitude_value: ::read_u8_array(_buf)?,
        } )
    }
}


// Spectrum analyzer
//
// Spectrum analyzer packet.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSpecan {
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
    pub const TYPE: u16 = 81;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSpecan, ::Error> {
        Ok( MsgSpecan{
            channel_tag: _buf.read_u16::<LittleEndian>()?,
            t: GPSTime::parse(_buf)?,
            freq_ref: _buf.read_f32::<LittleEndian>()?,
            freq_step: _buf.read_f32::<LittleEndian>()?,
            amplitude_ref: _buf.read_f32::<LittleEndian>()?,
            amplitude_unit: _buf.read_f32::<LittleEndian>()?,
            amplitude_value: ::read_u8_array(_buf)?,
        } )
    }
}

