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
// Automatically generated from yaml/swiftnav/sbp/linux.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Linux state monitoring.
//!

extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
#[cfg(feature = "serialize")]
use serde::{Deserialize, Serialize};

/// List CPU state on the system
///
/// This message indicates the process state of the top 10 heaviest
/// consumers of CPU on the system.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgLinuxCpuState {
    pub sender_id: Option<u16>,
    /// sequence of this status message, values from 0-9
    pub index: u8,
    /// the PID of the process
    pub pid: u16,
    /// percent of cpu used, expressed as a fraction of 256
    pub pcpu: u8,
    /// fixed length string representing the thread name
    pub tname: String,
    /// the command line (as much as it fits in the remaining packet)
    pub cmdline: String,
}

impl MsgLinuxCpuState {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgLinuxCpuState, crate::Error> {
        Ok(MsgLinuxCpuState {
            sender_id: None,
            index: _buf.read_u8()?,
            pid: _buf.read_u16::<LittleEndian>()?,
            pcpu: _buf.read_u8()?,
            tname: crate::parser::read_string_limit(_buf, 15)?,
            cmdline: crate::parser::read_string(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgLinuxCpuState {
    fn get_message_type(&self) -> u16 {
        32512
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgLinuxCpuState {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.index.append_to_sbp_buffer(buf);
        self.pid.append_to_sbp_buffer(buf);
        self.pcpu.append_to_sbp_buffer(buf);
        self.tname.append_to_sbp_buffer(buf);
        self.cmdline.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.index.sbp_size();
        size += self.pid.sbp_size();
        size += self.pcpu.sbp_size();
        size += self.tname.sbp_size();
        size += self.cmdline.sbp_size();
        size
    }
}

/// List CPU state on the system
///
/// This message indicates the process state of the top 10 heaviest
/// consumers of memory on the system.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgLinuxMemState {
    pub sender_id: Option<u16>,
    /// sequence of this status message, values from 0-9
    pub index: u8,
    /// the PID of the process
    pub pid: u16,
    /// percent of memory used, expressed as a fraction of 256
    pub pmem: u8,
    /// fixed length string representing the thread name
    pub tname: String,
    /// the command line (as much as it fits in the remaining packet)
    pub cmdline: String,
}

impl MsgLinuxMemState {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgLinuxMemState, crate::Error> {
        Ok(MsgLinuxMemState {
            sender_id: None,
            index: _buf.read_u8()?,
            pid: _buf.read_u16::<LittleEndian>()?,
            pmem: _buf.read_u8()?,
            tname: crate::parser::read_string_limit(_buf, 15)?,
            cmdline: crate::parser::read_string(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgLinuxMemState {
    fn get_message_type(&self) -> u16 {
        32513
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgLinuxMemState {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.index.append_to_sbp_buffer(buf);
        self.pid.append_to_sbp_buffer(buf);
        self.pmem.append_to_sbp_buffer(buf);
        self.tname.append_to_sbp_buffer(buf);
        self.cmdline.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.index.sbp_size();
        size += self.pid.sbp_size();
        size += self.pmem.sbp_size();
        size += self.tname.sbp_size();
        size += self.cmdline.sbp_size();
        size
    }
}

/// Summary of processes with large amounts of open file descriptors
///
/// Top 10 list of processes with a large number of open file descriptors.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgLinuxProcessFdCount {
    pub sender_id: Option<u16>,
    /// sequence of this status message, values from 0-9
    pub index: u8,
    /// the PID of the process in question
    pub pid: u16,
    /// a count of the number of file descriptors opened by the process
    pub fd_count: u16,
    /// the command line of the process in question
    pub cmdline: String,
}

impl MsgLinuxProcessFdCount {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgLinuxProcessFdCount, crate::Error> {
        Ok(MsgLinuxProcessFdCount {
            sender_id: None,
            index: _buf.read_u8()?,
            pid: _buf.read_u16::<LittleEndian>()?,
            fd_count: _buf.read_u16::<LittleEndian>()?,
            cmdline: crate::parser::read_string(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgLinuxProcessFdCount {
    fn get_message_type(&self) -> u16 {
        32518
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgLinuxProcessFdCount {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.index.append_to_sbp_buffer(buf);
        self.pid.append_to_sbp_buffer(buf);
        self.fd_count.append_to_sbp_buffer(buf);
        self.cmdline.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.index.sbp_size();
        size += self.pid.sbp_size();
        size += self.fd_count.sbp_size();
        size += self.cmdline.sbp_size();
        size
    }
}

/// Summary of open file descriptors on the system
///
/// Summary of open file descriptors on the system.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgLinuxProcessFdSummary {
    pub sender_id: Option<u16>,
    /// count of total FDs open on the system
    pub sys_fd_count: u32,
    /// A null delimited list of strings which alternates between a string
    /// representation of the process count and the file name whose count it
    /// being reported.  That is, in C string syntax
    /// "32\0/var/log/syslog\012\0/tmp/foo\0" with the end of the list being 2
    /// NULL terminators in a row.
    pub most_opened: String,
}

impl MsgLinuxProcessFdSummary {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgLinuxProcessFdSummary, crate::Error> {
        Ok(MsgLinuxProcessFdSummary {
            sender_id: None,
            sys_fd_count: _buf.read_u32::<LittleEndian>()?,
            most_opened: crate::parser::read_string(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgLinuxProcessFdSummary {
    fn get_message_type(&self) -> u16 {
        32519
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgLinuxProcessFdSummary {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sys_fd_count.append_to_sbp_buffer(buf);
        self.most_opened.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sys_fd_count.sbp_size();
        size += self.most_opened.sbp_size();
        size
    }
}

/// A list of processes with high socket counts
///
/// Top 10 list of processes with high socket counts.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgLinuxProcessSocketCounts {
    pub sender_id: Option<u16>,
    /// sequence of this status message, values from 0-9
    pub index: u8,
    /// the PID of the process in question
    pub pid: u16,
    /// the number of sockets the process is using
    pub socket_count: u16,
    /// A bitfield indicating the socket types used:   0x1 (tcp), 0x2 (udp), 0x4
    /// (unix stream), 0x8 (unix dgram), 0x10 (netlink),   and 0x8000 (unknown)
    pub socket_types: u16,
    /// A bitfield indicating the socket states:   0x1 (established), 0x2 (syn-
    /// sent), 0x4 (syn-recv), 0x8 (fin-wait-1),   0x10 (fin-wait-2), 0x20
    /// (time-wait), 0x40 (closed), 0x80 (close-wait),   0x100 (last-ack), 0x200
    /// (listen), 0x400 (closing), 0x800 (unconnected),   and 0x8000 (unknown)
    pub socket_states: u16,
    /// the command line of the process in question
    pub cmdline: String,
}

impl MsgLinuxProcessSocketCounts {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgLinuxProcessSocketCounts, crate::Error> {
        Ok(MsgLinuxProcessSocketCounts {
            sender_id: None,
            index: _buf.read_u8()?,
            pid: _buf.read_u16::<LittleEndian>()?,
            socket_count: _buf.read_u16::<LittleEndian>()?,
            socket_types: _buf.read_u16::<LittleEndian>()?,
            socket_states: _buf.read_u16::<LittleEndian>()?,
            cmdline: crate::parser::read_string(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgLinuxProcessSocketCounts {
    fn get_message_type(&self) -> u16 {
        32515
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgLinuxProcessSocketCounts {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.index.append_to_sbp_buffer(buf);
        self.pid.append_to_sbp_buffer(buf);
        self.socket_count.append_to_sbp_buffer(buf);
        self.socket_types.append_to_sbp_buffer(buf);
        self.socket_states.append_to_sbp_buffer(buf);
        self.cmdline.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.index.sbp_size();
        size += self.pid.sbp_size();
        size += self.socket_count.sbp_size();
        size += self.socket_types.sbp_size();
        size += self.socket_states.sbp_size();
        size += self.cmdline.sbp_size();
        size
    }
}

/// A list of processes with deep socket queues
///
/// Top 10 list of sockets with deep queues.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgLinuxProcessSocketQueues {
    pub sender_id: Option<u16>,
    /// sequence of this status message, values from 0-9
    pub index: u8,
    /// the PID of the process in question
    pub pid: u16,
    /// the total amount of receive data queued for this process
    pub recv_queued: u16,
    /// the total amount of send data queued for this process
    pub send_queued: u16,
    /// A bitfield indicating the socket types used:   0x1 (tcp), 0x2 (udp), 0x4
    /// (unix stream), 0x8 (unix dgram), 0x10 (netlink),   and 0x8000 (unknown)
    pub socket_types: u16,
    /// A bitfield indicating the socket states:   0x1 (established), 0x2 (syn-
    /// sent), 0x4 (syn-recv), 0x8 (fin-wait-1),   0x10 (fin-wait-2), 0x20
    /// (time-wait), 0x40 (closed), 0x80 (close-wait),   0x100 (last-ack), 0x200
    /// (listen), 0x400 (closing), 0x800 (unconnected),   and 0x8000 (unknown)
    pub socket_states: u16,
    /// Address of the largest queue, remote or local depending on the
    /// directionality of the connection.
    pub address_of_largest: String,
    /// the command line of the process in question
    pub cmdline: String,
}

impl MsgLinuxProcessSocketQueues {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgLinuxProcessSocketQueues, crate::Error> {
        Ok(MsgLinuxProcessSocketQueues {
            sender_id: None,
            index: _buf.read_u8()?,
            pid: _buf.read_u16::<LittleEndian>()?,
            recv_queued: _buf.read_u16::<LittleEndian>()?,
            send_queued: _buf.read_u16::<LittleEndian>()?,
            socket_types: _buf.read_u16::<LittleEndian>()?,
            socket_states: _buf.read_u16::<LittleEndian>()?,
            address_of_largest: crate::parser::read_string_limit(_buf, 64)?,
            cmdline: crate::parser::read_string(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgLinuxProcessSocketQueues {
    fn get_message_type(&self) -> u16 {
        32516
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgLinuxProcessSocketQueues {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.index.append_to_sbp_buffer(buf);
        self.pid.append_to_sbp_buffer(buf);
        self.recv_queued.append_to_sbp_buffer(buf);
        self.send_queued.append_to_sbp_buffer(buf);
        self.socket_types.append_to_sbp_buffer(buf);
        self.socket_states.append_to_sbp_buffer(buf);
        self.address_of_largest.append_to_sbp_buffer(buf);
        self.cmdline.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.index.sbp_size();
        size += self.pid.sbp_size();
        size += self.recv_queued.sbp_size();
        size += self.send_queued.sbp_size();
        size += self.socket_types.sbp_size();
        size += self.socket_states.sbp_size();
        size += self.address_of_largest.sbp_size();
        size += self.cmdline.sbp_size();
        size
    }
}

/// Summary of socket usage across the system
///
/// Summaries the socket usage across the system.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgLinuxSocketUsage {
    pub sender_id: Option<u16>,
    /// average socket queue depths across all sockets on the system
    pub avg_queue_depth: u32,
    /// the max queue depth seen within the reporting period
    pub max_queue_depth: u32,
    /// A count for each socket type reported in the `socket_types_reported`
    /// field, the first entry corresponds to the first enabled bit in
    /// `types_reported`.
    pub socket_state_counts: Vec<u16>,
    /// A count for each socket type reported in the `socket_types_reported`
    /// field, the first entry corresponds to the first enabled bit in
    /// `types_reported`.
    pub socket_type_counts: Vec<u16>,
}

impl MsgLinuxSocketUsage {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgLinuxSocketUsage, crate::Error> {
        Ok(MsgLinuxSocketUsage {
            sender_id: None,
            avg_queue_depth: _buf.read_u32::<LittleEndian>()?,
            max_queue_depth: _buf.read_u32::<LittleEndian>()?,
            socket_state_counts: crate::parser::read_u16_array_limit(_buf, 16)?,
            socket_type_counts: crate::parser::read_u16_array_limit(_buf, 16)?,
        })
    }
}
impl super::SBPMessage for MsgLinuxSocketUsage {
    fn get_message_type(&self) -> u16 {
        32517
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgLinuxSocketUsage {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.avg_queue_depth.append_to_sbp_buffer(buf);
        self.max_queue_depth.append_to_sbp_buffer(buf);
        self.socket_state_counts.append_to_sbp_buffer(buf);
        self.socket_type_counts.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.avg_queue_depth.sbp_size();
        size += self.max_queue_depth.sbp_size();
        size += self.socket_state_counts.sbp_size();
        size += self.socket_type_counts.sbp_size();
        size
    }
}

/// CPU, Memory and Process Starts/Stops
///
/// This presents a summary of CPU and memory utilization.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgLinuxSysState {
    pub sender_id: Option<u16>,
    /// total system memory
    pub mem_total: u16,
    /// percent of total cpu currently utilized
    pub pcpu: u8,
    /// percent of total memory currently utilized
    pub pmem: u8,
    /// number of processes that started during collection phase
    pub procs_starting: u16,
    /// number of processes that stopped during collection phase
    pub procs_stopping: u16,
    /// the count of processes on the system
    pub pid_count: u16,
}

impl MsgLinuxSysState {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgLinuxSysState, crate::Error> {
        Ok(MsgLinuxSysState {
            sender_id: None,
            mem_total: _buf.read_u16::<LittleEndian>()?,
            pcpu: _buf.read_u8()?,
            pmem: _buf.read_u8()?,
            procs_starting: _buf.read_u16::<LittleEndian>()?,
            procs_stopping: _buf.read_u16::<LittleEndian>()?,
            pid_count: _buf.read_u16::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgLinuxSysState {
    fn get_message_type(&self) -> u16 {
        32514
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::framer::FramerError> {
        let trait_object = self as &dyn super::SBPMessage;
        crate::framer::to_frame(trait_object)
    }
}

impl crate::serialize::SbpSerialize for MsgLinuxSysState {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.mem_total.append_to_sbp_buffer(buf);
        self.pcpu.append_to_sbp_buffer(buf);
        self.pmem.append_to_sbp_buffer(buf);
        self.procs_starting.append_to_sbp_buffer(buf);
        self.procs_stopping.append_to_sbp_buffer(buf);
        self.pid_count.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.mem_total.sbp_size();
        size += self.pcpu.sbp_size();
        size += self.pmem.sbp_size();
        size += self.procs_starting.sbp_size();
        size += self.procs_stopping.sbp_size();
        size += self.pid_count.sbp_size();
        size
    }
}
