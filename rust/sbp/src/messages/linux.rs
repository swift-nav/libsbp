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
// Automatically generated from yaml/swiftnav/sbp/linux.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Linux state monitoring.

use super::lib::*;

/// List CPU state on the system
///
/// This message indicates the process state of the top 10 heaviest consumers
/// of CPU on the system, including a timestamp.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgLinuxCpuState {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// sequence of this status message, values from 0-9
    #[cfg_attr(feature = "serde", serde(rename(serialize = "index")))]
    pub index: u8,
    /// the PID of the process
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pid")))]
    pub pid: u16,
    /// percent of CPU used, expressed as a fraction of 256
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pcpu")))]
    pub pcpu: u8,
    /// timestamp of message, refer to flags field for how to interpret
    #[cfg_attr(feature = "serde", serde(rename(serialize = "time")))]
    pub time: u32,
    /// flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
    /// fixed length string representing the thread name
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tname")))]
    pub tname: SbpString<[u8; 15], Unterminated>,
    /// the command line (as much as it fits in the remaining packet)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cmdline")))]
    pub cmdline: SbpString<Vec<u8>, Unterminated>,
}

impl ConcreteMessage for MsgLinuxCpuState {
    const MESSAGE_TYPE: u16 = 32520;
    const MESSAGE_NAME: &'static str = "MSG_LINUX_CPU_STATE";
}

impl SbpMessage for MsgLinuxCpuState {
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

impl TryFrom<Sbp> for MsgLinuxCpuState {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgLinuxCpuState(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgLinuxCpuState {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <SbpString<[u8; 15], Unterminated> as WireFormat>::MIN_LEN
        + <SbpString<Vec<u8>, Unterminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.index)
            + WireFormat::len(&self.pid)
            + WireFormat::len(&self.pcpu)
            + WireFormat::len(&self.time)
            + WireFormat::len(&self.flags)
            + WireFormat::len(&self.tname)
            + WireFormat::len(&self.cmdline)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.index, buf);
        WireFormat::write(&self.pid, buf);
        WireFormat::write(&self.pcpu, buf);
        WireFormat::write(&self.time, buf);
        WireFormat::write(&self.flags, buf);
        WireFormat::write(&self.tname, buf);
        WireFormat::write(&self.cmdline, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgLinuxCpuState {
            sender_id: None,
            index: WireFormat::parse_unchecked(buf),
            pid: WireFormat::parse_unchecked(buf),
            pcpu: WireFormat::parse_unchecked(buf),
            time: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
            tname: WireFormat::parse_unchecked(buf),
            cmdline: WireFormat::parse_unchecked(buf),
        }
    }
}

/// List CPU state on the system. DEPRECATED
///
/// This message indicates the process state of the top 10 heaviest consumers
/// of CPU on the system.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgLinuxCpuStateDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// sequence of this status message, values from 0-9
    #[cfg_attr(feature = "serde", serde(rename(serialize = "index")))]
    pub index: u8,
    /// the PID of the process
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pid")))]
    pub pid: u16,
    /// percent of cpu used, expressed as a fraction of 256
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pcpu")))]
    pub pcpu: u8,
    /// fixed length string representing the thread name
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tname")))]
    pub tname: SbpString<[u8; 15], Unterminated>,
    /// the command line (as much as it fits in the remaining packet)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cmdline")))]
    pub cmdline: SbpString<Vec<u8>, Unterminated>,
}

impl ConcreteMessage for MsgLinuxCpuStateDepA {
    const MESSAGE_TYPE: u16 = 32512;
    const MESSAGE_NAME: &'static str = "MSG_LINUX_CPU_STATE_DEP_A";
}

impl SbpMessage for MsgLinuxCpuStateDepA {
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

impl TryFrom<Sbp> for MsgLinuxCpuStateDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgLinuxCpuStateDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgLinuxCpuStateDepA {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <SbpString<[u8; 15], Unterminated> as WireFormat>::MIN_LEN
        + <SbpString<Vec<u8>, Unterminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.index)
            + WireFormat::len(&self.pid)
            + WireFormat::len(&self.pcpu)
            + WireFormat::len(&self.tname)
            + WireFormat::len(&self.cmdline)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.index, buf);
        WireFormat::write(&self.pid, buf);
        WireFormat::write(&self.pcpu, buf);
        WireFormat::write(&self.tname, buf);
        WireFormat::write(&self.cmdline, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgLinuxCpuStateDepA {
            sender_id: None,
            index: WireFormat::parse_unchecked(buf),
            pid: WireFormat::parse_unchecked(buf),
            pcpu: WireFormat::parse_unchecked(buf),
            tname: WireFormat::parse_unchecked(buf),
            cmdline: WireFormat::parse_unchecked(buf),
        }
    }
}

/// List memory state on the system
///
/// This message indicates the process state of the top 10 heaviest consumers
/// of memory on the system, including a timestamp.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgLinuxMemState {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// sequence of this status message, values from 0-9
    #[cfg_attr(feature = "serde", serde(rename(serialize = "index")))]
    pub index: u8,
    /// the PID of the process
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pid")))]
    pub pid: u16,
    /// percent of memory used, expressed as a fraction of 256
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pmem")))]
    pub pmem: u8,
    /// timestamp of message, refer to flags field for how to interpret
    #[cfg_attr(feature = "serde", serde(rename(serialize = "time")))]
    pub time: u32,
    /// flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
    /// fixed length string representing the thread name
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tname")))]
    pub tname: SbpString<[u8; 15], Unterminated>,
    /// the command line (as much as it fits in the remaining packet)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cmdline")))]
    pub cmdline: SbpString<Vec<u8>, Unterminated>,
}

impl ConcreteMessage for MsgLinuxMemState {
    const MESSAGE_TYPE: u16 = 32521;
    const MESSAGE_NAME: &'static str = "MSG_LINUX_MEM_STATE";
}

impl SbpMessage for MsgLinuxMemState {
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

impl TryFrom<Sbp> for MsgLinuxMemState {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgLinuxMemState(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgLinuxMemState {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <SbpString<[u8; 15], Unterminated> as WireFormat>::MIN_LEN
        + <SbpString<Vec<u8>, Unterminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.index)
            + WireFormat::len(&self.pid)
            + WireFormat::len(&self.pmem)
            + WireFormat::len(&self.time)
            + WireFormat::len(&self.flags)
            + WireFormat::len(&self.tname)
            + WireFormat::len(&self.cmdline)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.index, buf);
        WireFormat::write(&self.pid, buf);
        WireFormat::write(&self.pmem, buf);
        WireFormat::write(&self.time, buf);
        WireFormat::write(&self.flags, buf);
        WireFormat::write(&self.tname, buf);
        WireFormat::write(&self.cmdline, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgLinuxMemState {
            sender_id: None,
            index: WireFormat::parse_unchecked(buf),
            pid: WireFormat::parse_unchecked(buf),
            pmem: WireFormat::parse_unchecked(buf),
            time: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
            tname: WireFormat::parse_unchecked(buf),
            cmdline: WireFormat::parse_unchecked(buf),
        }
    }
}

/// List memory state on the system. DEPRECATED
///
/// This message indicates the process state of the top 10 heaviest consumers
/// of memory on the system.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgLinuxMemStateDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// sequence of this status message, values from 0-9
    #[cfg_attr(feature = "serde", serde(rename(serialize = "index")))]
    pub index: u8,
    /// the PID of the process
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pid")))]
    pub pid: u16,
    /// percent of memory used, expressed as a fraction of 256
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pmem")))]
    pub pmem: u8,
    /// fixed length string representing the thread name
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tname")))]
    pub tname: SbpString<[u8; 15], Unterminated>,
    /// the command line (as much as it fits in the remaining packet)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cmdline")))]
    pub cmdline: SbpString<Vec<u8>, Unterminated>,
}

impl ConcreteMessage for MsgLinuxMemStateDepA {
    const MESSAGE_TYPE: u16 = 32513;
    const MESSAGE_NAME: &'static str = "MSG_LINUX_MEM_STATE_DEP_A";
}

impl SbpMessage for MsgLinuxMemStateDepA {
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

impl TryFrom<Sbp> for MsgLinuxMemStateDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgLinuxMemStateDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgLinuxMemStateDepA {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <SbpString<[u8; 15], Unterminated> as WireFormat>::MIN_LEN
        + <SbpString<Vec<u8>, Unterminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.index)
            + WireFormat::len(&self.pid)
            + WireFormat::len(&self.pmem)
            + WireFormat::len(&self.tname)
            + WireFormat::len(&self.cmdline)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.index, buf);
        WireFormat::write(&self.pid, buf);
        WireFormat::write(&self.pmem, buf);
        WireFormat::write(&self.tname, buf);
        WireFormat::write(&self.cmdline, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgLinuxMemStateDepA {
            sender_id: None,
            index: WireFormat::parse_unchecked(buf),
            pid: WireFormat::parse_unchecked(buf),
            pmem: WireFormat::parse_unchecked(buf),
            tname: WireFormat::parse_unchecked(buf),
            cmdline: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Summary of processes with large amounts of open file descriptors
///
/// Top 10 list of processes with a large number of open file descriptors.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgLinuxProcessFdCount {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// sequence of this status message, values from 0-9
    #[cfg_attr(feature = "serde", serde(rename(serialize = "index")))]
    pub index: u8,
    /// the PID of the process in question
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pid")))]
    pub pid: u16,
    /// a count of the number of file descriptors opened by the process
    #[cfg_attr(feature = "serde", serde(rename(serialize = "fd_count")))]
    pub fd_count: u16,
    /// the command line of the process in question
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cmdline")))]
    pub cmdline: SbpString<Vec<u8>, Unterminated>,
}

impl ConcreteMessage for MsgLinuxProcessFdCount {
    const MESSAGE_TYPE: u16 = 32518;
    const MESSAGE_NAME: &'static str = "MSG_LINUX_PROCESS_FD_COUNT";
}

impl SbpMessage for MsgLinuxProcessFdCount {
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

impl TryFrom<Sbp> for MsgLinuxProcessFdCount {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgLinuxProcessFdCount(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgLinuxProcessFdCount {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <SbpString<Vec<u8>, Unterminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.index)
            + WireFormat::len(&self.pid)
            + WireFormat::len(&self.fd_count)
            + WireFormat::len(&self.cmdline)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.index, buf);
        WireFormat::write(&self.pid, buf);
        WireFormat::write(&self.fd_count, buf);
        WireFormat::write(&self.cmdline, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgLinuxProcessFdCount {
            sender_id: None,
            index: WireFormat::parse_unchecked(buf),
            pid: WireFormat::parse_unchecked(buf),
            fd_count: WireFormat::parse_unchecked(buf),
            cmdline: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Summary of open file descriptors on the system
///
/// Summary of open file descriptors on the system.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgLinuxProcessFdSummary {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// count of total FDs open on the system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sys_fd_count")))]
    pub sys_fd_count: u32,
    /// A null delimited list of strings which alternates between a string
    /// representation of the process count and the file name whose count it
    /// being reported.  That is, in C string syntax
    /// "32\0/var/log/syslog\012\0/tmp/foo\0" with the end of the list being 2
    /// NULL terminators in a row.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "most_opened")))]
    pub most_opened: SbpString<Vec<u8>, DoubleNullTerminated>,
}

impl ConcreteMessage for MsgLinuxProcessFdSummary {
    const MESSAGE_TYPE: u16 = 32519;
    const MESSAGE_NAME: &'static str = "MSG_LINUX_PROCESS_FD_SUMMARY";
}

impl SbpMessage for MsgLinuxProcessFdSummary {
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

impl TryFrom<Sbp> for MsgLinuxProcessFdSummary {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgLinuxProcessFdSummary(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgLinuxProcessFdSummary {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <SbpString<Vec<u8>, DoubleNullTerminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sys_fd_count) + WireFormat::len(&self.most_opened)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sys_fd_count, buf);
        WireFormat::write(&self.most_opened, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgLinuxProcessFdSummary {
            sender_id: None,
            sys_fd_count: WireFormat::parse_unchecked(buf),
            most_opened: WireFormat::parse_unchecked(buf),
        }
    }
}

/// A list of processes with high socket counts
///
/// Top 10 list of processes with high socket counts.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgLinuxProcessSocketCounts {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// sequence of this status message, values from 0-9
    #[cfg_attr(feature = "serde", serde(rename(serialize = "index")))]
    pub index: u8,
    /// the PID of the process in question
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pid")))]
    pub pid: u16,
    /// the number of sockets the process is using
    #[cfg_attr(feature = "serde", serde(rename(serialize = "socket_count")))]
    pub socket_count: u16,
    /// A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp), 0x4
    /// (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000 (unknown)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "socket_types")))]
    pub socket_types: u16,
    /// A bitfield indicating the socket states: 0x1 (established), 0x2 (syn-
    /// sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2), 0x20 (time-
    /// wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-ack), 0x200
    /// (listen), 0x400 (closing), 0x800 (unconnected), and 0x8000 (unknown)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "socket_states")))]
    pub socket_states: u16,
    /// the command line of the process in question
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cmdline")))]
    pub cmdline: SbpString<Vec<u8>, Unterminated>,
}

impl ConcreteMessage for MsgLinuxProcessSocketCounts {
    const MESSAGE_TYPE: u16 = 32515;
    const MESSAGE_NAME: &'static str = "MSG_LINUX_PROCESS_SOCKET_COUNTS";
}

impl SbpMessage for MsgLinuxProcessSocketCounts {
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

impl TryFrom<Sbp> for MsgLinuxProcessSocketCounts {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgLinuxProcessSocketCounts(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgLinuxProcessSocketCounts {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <SbpString<Vec<u8>, Unterminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.index)
            + WireFormat::len(&self.pid)
            + WireFormat::len(&self.socket_count)
            + WireFormat::len(&self.socket_types)
            + WireFormat::len(&self.socket_states)
            + WireFormat::len(&self.cmdline)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.index, buf);
        WireFormat::write(&self.pid, buf);
        WireFormat::write(&self.socket_count, buf);
        WireFormat::write(&self.socket_types, buf);
        WireFormat::write(&self.socket_states, buf);
        WireFormat::write(&self.cmdline, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgLinuxProcessSocketCounts {
            sender_id: None,
            index: WireFormat::parse_unchecked(buf),
            pid: WireFormat::parse_unchecked(buf),
            socket_count: WireFormat::parse_unchecked(buf),
            socket_types: WireFormat::parse_unchecked(buf),
            socket_states: WireFormat::parse_unchecked(buf),
            cmdline: WireFormat::parse_unchecked(buf),
        }
    }
}

/// A list of processes with deep socket queues
///
/// Top 10 list of sockets with deep queues.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgLinuxProcessSocketQueues {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// sequence of this status message, values from 0-9
    #[cfg_attr(feature = "serde", serde(rename(serialize = "index")))]
    pub index: u8,
    /// the PID of the process in question
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pid")))]
    pub pid: u16,
    /// the total amount of receive data queued for this process
    #[cfg_attr(feature = "serde", serde(rename(serialize = "recv_queued")))]
    pub recv_queued: u16,
    /// the total amount of send data queued for this process
    #[cfg_attr(feature = "serde", serde(rename(serialize = "send_queued")))]
    pub send_queued: u16,
    /// A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp), 0x4
    /// (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000 (unknown)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "socket_types")))]
    pub socket_types: u16,
    /// A bitfield indicating the socket states: 0x1 (established), 0x2 (syn-
    /// sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2), 0x20 (time-
    /// wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-ack), 0x200
    /// (listen), 0x400 (closing), 0x800 (unconnected), and 0x8000 (unknown)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "socket_states")))]
    pub socket_states: u16,
    /// Address of the largest queue, remote or local depending on the
    /// directionality of the connection.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "address_of_largest")))]
    pub address_of_largest: SbpString<[u8; 64], Unterminated>,
    /// the command line of the process in question
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cmdline")))]
    pub cmdline: SbpString<Vec<u8>, Unterminated>,
}

impl ConcreteMessage for MsgLinuxProcessSocketQueues {
    const MESSAGE_TYPE: u16 = 32516;
    const MESSAGE_NAME: &'static str = "MSG_LINUX_PROCESS_SOCKET_QUEUES";
}

impl SbpMessage for MsgLinuxProcessSocketQueues {
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

impl TryFrom<Sbp> for MsgLinuxProcessSocketQueues {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgLinuxProcessSocketQueues(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgLinuxProcessSocketQueues {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <SbpString<[u8; 64], Unterminated> as WireFormat>::MIN_LEN
        + <SbpString<Vec<u8>, Unterminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.index)
            + WireFormat::len(&self.pid)
            + WireFormat::len(&self.recv_queued)
            + WireFormat::len(&self.send_queued)
            + WireFormat::len(&self.socket_types)
            + WireFormat::len(&self.socket_states)
            + WireFormat::len(&self.address_of_largest)
            + WireFormat::len(&self.cmdline)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.index, buf);
        WireFormat::write(&self.pid, buf);
        WireFormat::write(&self.recv_queued, buf);
        WireFormat::write(&self.send_queued, buf);
        WireFormat::write(&self.socket_types, buf);
        WireFormat::write(&self.socket_states, buf);
        WireFormat::write(&self.address_of_largest, buf);
        WireFormat::write(&self.cmdline, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgLinuxProcessSocketQueues {
            sender_id: None,
            index: WireFormat::parse_unchecked(buf),
            pid: WireFormat::parse_unchecked(buf),
            recv_queued: WireFormat::parse_unchecked(buf),
            send_queued: WireFormat::parse_unchecked(buf),
            socket_types: WireFormat::parse_unchecked(buf),
            socket_states: WireFormat::parse_unchecked(buf),
            address_of_largest: WireFormat::parse_unchecked(buf),
            cmdline: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Summary of socket usage across the system
///
/// Summaries the socket usage across the system.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgLinuxSocketUsage {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// average socket queue depths across all sockets on the system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "avg_queue_depth")))]
    pub avg_queue_depth: u32,
    /// the max queue depth seen within the reporting period
    #[cfg_attr(feature = "serde", serde(rename(serialize = "max_queue_depth")))]
    pub max_queue_depth: u32,
    /// A count for each socket type reported in the `socket_types_reported`
    /// field, the first entry corresponds to the first enabled bit in
    /// `types_reported`.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "socket_state_counts")))]
    pub socket_state_counts: [u16; 16],
    /// A count for each socket type reported in the `socket_types_reported`
    /// field, the first entry corresponds to the first enabled bit in
    /// `types_reported`.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "socket_type_counts")))]
    pub socket_type_counts: [u16; 16],
}

impl ConcreteMessage for MsgLinuxSocketUsage {
    const MESSAGE_TYPE: u16 = 32517;
    const MESSAGE_NAME: &'static str = "MSG_LINUX_SOCKET_USAGE";
}

impl SbpMessage for MsgLinuxSocketUsage {
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

impl TryFrom<Sbp> for MsgLinuxSocketUsage {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgLinuxSocketUsage(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgLinuxSocketUsage {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <[u16; 16] as WireFormat>::MIN_LEN
        + <[u16; 16] as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.avg_queue_depth)
            + WireFormat::len(&self.max_queue_depth)
            + WireFormat::len(&self.socket_state_counts)
            + WireFormat::len(&self.socket_type_counts)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.avg_queue_depth, buf);
        WireFormat::write(&self.max_queue_depth, buf);
        WireFormat::write(&self.socket_state_counts, buf);
        WireFormat::write(&self.socket_type_counts, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgLinuxSocketUsage {
            sender_id: None,
            avg_queue_depth: WireFormat::parse_unchecked(buf),
            max_queue_depth: WireFormat::parse_unchecked(buf),
            socket_state_counts: WireFormat::parse_unchecked(buf),
            socket_type_counts: WireFormat::parse_unchecked(buf),
        }
    }
}

/// CPU, Memory and Process Starts/Stops
///
/// This presents a summary of CPU and memory utilization, including a
/// timestamp.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgLinuxSysState {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// total system memory, in MiB
    #[cfg_attr(feature = "serde", serde(rename(serialize = "mem_total")))]
    pub mem_total: u16,
    /// percent of CPU used, expressed as a fraction of 256
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pcpu")))]
    pub pcpu: u8,
    /// percent of memory used, expressed as a fraction of 256
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pmem")))]
    pub pmem: u8,
    /// number of processes that started during collection phase
    #[cfg_attr(feature = "serde", serde(rename(serialize = "procs_starting")))]
    pub procs_starting: u16,
    /// number of processes that stopped during collection phase
    #[cfg_attr(feature = "serde", serde(rename(serialize = "procs_stopping")))]
    pub procs_stopping: u16,
    /// the count of processes on the system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pid_count")))]
    pub pid_count: u16,
    /// timestamp of message, refer to flags field for how to interpret
    #[cfg_attr(feature = "serde", serde(rename(serialize = "time")))]
    pub time: u32,
    /// flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl ConcreteMessage for MsgLinuxSysState {
    const MESSAGE_TYPE: u16 = 32522;
    const MESSAGE_NAME: &'static str = "MSG_LINUX_SYS_STATE";
}

impl SbpMessage for MsgLinuxSysState {
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

impl TryFrom<Sbp> for MsgLinuxSysState {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgLinuxSysState(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgLinuxSysState {
    const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.mem_total)
            + WireFormat::len(&self.pcpu)
            + WireFormat::len(&self.pmem)
            + WireFormat::len(&self.procs_starting)
            + WireFormat::len(&self.procs_stopping)
            + WireFormat::len(&self.pid_count)
            + WireFormat::len(&self.time)
            + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.mem_total, buf);
        WireFormat::write(&self.pcpu, buf);
        WireFormat::write(&self.pmem, buf);
        WireFormat::write(&self.procs_starting, buf);
        WireFormat::write(&self.procs_stopping, buf);
        WireFormat::write(&self.pid_count, buf);
        WireFormat::write(&self.time, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgLinuxSysState {
            sender_id: None,
            mem_total: WireFormat::parse_unchecked(buf),
            pcpu: WireFormat::parse_unchecked(buf),
            pmem: WireFormat::parse_unchecked(buf),
            procs_starting: WireFormat::parse_unchecked(buf),
            procs_stopping: WireFormat::parse_unchecked(buf),
            pid_count: WireFormat::parse_unchecked(buf),
            time: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// CPU, Memory and Process Starts/Stops. DEPRECATED
///
/// This presents a summary of CPU and memory utilization.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgLinuxSysStateDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// total system memory
    #[cfg_attr(feature = "serde", serde(rename(serialize = "mem_total")))]
    pub mem_total: u16,
    /// percent of total cpu currently utilized
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pcpu")))]
    pub pcpu: u8,
    /// percent of total memory currently utilized
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pmem")))]
    pub pmem: u8,
    /// number of processes that started during collection phase
    #[cfg_attr(feature = "serde", serde(rename(serialize = "procs_starting")))]
    pub procs_starting: u16,
    /// number of processes that stopped during collection phase
    #[cfg_attr(feature = "serde", serde(rename(serialize = "procs_stopping")))]
    pub procs_stopping: u16,
    /// the count of processes on the system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pid_count")))]
    pub pid_count: u16,
}

impl ConcreteMessage for MsgLinuxSysStateDepA {
    const MESSAGE_TYPE: u16 = 32514;
    const MESSAGE_NAME: &'static str = "MSG_LINUX_SYS_STATE_DEP_A";
}

impl SbpMessage for MsgLinuxSysStateDepA {
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

impl TryFrom<Sbp> for MsgLinuxSysStateDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgLinuxSysStateDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgLinuxSysStateDepA {
    const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.mem_total)
            + WireFormat::len(&self.pcpu)
            + WireFormat::len(&self.pmem)
            + WireFormat::len(&self.procs_starting)
            + WireFormat::len(&self.procs_stopping)
            + WireFormat::len(&self.pid_count)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.mem_total, buf);
        WireFormat::write(&self.pcpu, buf);
        WireFormat::write(&self.pmem, buf);
        WireFormat::write(&self.procs_starting, buf);
        WireFormat::write(&self.procs_stopping, buf);
        WireFormat::write(&self.pid_count, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgLinuxSysStateDepA {
            sender_id: None,
            mem_total: WireFormat::parse_unchecked(buf),
            pcpu: WireFormat::parse_unchecked(buf),
            pmem: WireFormat::parse_unchecked(buf),
            procs_starting: WireFormat::parse_unchecked(buf),
            procs_stopping: WireFormat::parse_unchecked(buf),
            pid_count: WireFormat::parse_unchecked(buf),
        }
    }
}
