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
// Automatically generated from yaml/swiftnav/sbp/profiling.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Standardized profiling messages from Swift Navigation devices.
pub use msg_measurement_point::MsgMeasurementPoint;
pub use msg_profiling_resource_counter::MsgProfilingResourceCounter;
pub use msg_profiling_system_info::MsgProfilingSystemInfo;
pub use msg_profiling_thread_info::MsgProfilingThreadInfo;
pub use resource_bucket::ResourceBucket;

pub mod msg_measurement_point {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Profiling Measurement Point
    ///
    /// Tracks execution time of certain code paths in specially built products.
    /// This message should only be expected and processed on the direction of
    /// Swift's engineering teams.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgMeasurementPoint {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Total time spent in measurement point (microseconds)
        #[cfg_attr(feature = "serde", serde(rename = "total_time"))]
        pub total_time: u32,
        /// Number of times measurement point has executed
        #[cfg_attr(feature = "serde", serde(rename = "num_executions"))]
        pub num_executions: u16,
        /// Minimum execution time (microseconds)
        #[cfg_attr(feature = "serde", serde(rename = "min"))]
        pub min: u32,
        /// Maximum execution time (microseconds)
        #[cfg_attr(feature = "serde", serde(rename = "max"))]
        pub max: u32,
        /// Return address
        #[cfg_attr(feature = "serde", serde(rename = "return_addr"))]
        pub return_addr: u64,
        /// Unique ID
        #[cfg_attr(feature = "serde", serde(rename = "id"))]
        pub id: u64,
        /// CPU slice time (milliseconds)
        #[cfg_attr(feature = "serde", serde(rename = "slice_time"))]
        pub slice_time: u64,
        /// Line number
        #[cfg_attr(feature = "serde", serde(rename = "line"))]
        pub line: u16,
        /// Function name
        #[cfg_attr(feature = "serde", serde(rename = "func"))]
        pub func: SbpString<Vec<u8>, NullTerminated>,
    }

    impl ConcreteMessage for MsgMeasurementPoint {
        const MESSAGE_TYPE: u16 = 52992;
        const MESSAGE_NAME: &'static str = "MSG_MEASUREMENT_POINT";
    }

    impl SbpMessage for MsgMeasurementPoint {
        fn message_name(&self) -> &'static str {
            <Self as ConcreteMessage>::MESSAGE_NAME
        }
        fn message_type(&self) -> Option<u16> {
            Some(<Self as ConcreteMessage>::MESSAGE_TYPE)
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
        fn is_valid(&self) -> bool {
            true
        }
        fn into_valid_msg(self) -> Result<Self, crate::messages::invalid::Invalid> {
            Ok(self)
        }
    }

    impl FriendlyName for MsgMeasurementPoint {
        fn friendly_name() -> &'static str {
            "MEAS POINT"
        }
    }

    impl TryFrom<Sbp> for MsgMeasurementPoint {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgMeasurementPoint(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgMeasurementPoint {
        const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u32 as WireFormat>::MIN_LEN
            + <u32 as WireFormat>::MIN_LEN
            + <u64 as WireFormat>::MIN_LEN
            + <u64 as WireFormat>::MIN_LEN
            + <u64 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <SbpString<Vec<u8>, NullTerminated> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.total_time)
                + WireFormat::len(&self.num_executions)
                + WireFormat::len(&self.min)
                + WireFormat::len(&self.max)
                + WireFormat::len(&self.return_addr)
                + WireFormat::len(&self.id)
                + WireFormat::len(&self.slice_time)
                + WireFormat::len(&self.line)
                + WireFormat::len(&self.func)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.total_time, buf);
            WireFormat::write(&self.num_executions, buf);
            WireFormat::write(&self.min, buf);
            WireFormat::write(&self.max, buf);
            WireFormat::write(&self.return_addr, buf);
            WireFormat::write(&self.id, buf);
            WireFormat::write(&self.slice_time, buf);
            WireFormat::write(&self.line, buf);
            WireFormat::write(&self.func, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgMeasurementPoint {
                sender_id: None,
                total_time: WireFormat::parse_unchecked(buf),
                num_executions: WireFormat::parse_unchecked(buf),
                min: WireFormat::parse_unchecked(buf),
                max: WireFormat::parse_unchecked(buf),
                return_addr: WireFormat::parse_unchecked(buf),
                id: WireFormat::parse_unchecked(buf),
                slice_time: WireFormat::parse_unchecked(buf),
                line: WireFormat::parse_unchecked(buf),
                func: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_profiling_resource_counter {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Information about resource buckets
    ///
    /// Information about resource buckets. Refer to product documentation to
    /// understand the meaning and values in this message.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgProfilingResourceCounter {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Message number in complete sequence
        #[cfg_attr(feature = "serde", serde(rename = "seq_no"))]
        pub seq_no: u8,
        /// Length of message sequence
        #[cfg_attr(feature = "serde", serde(rename = "seq_len"))]
        pub seq_len: u8,
        /// List of resource buckets
        #[cfg_attr(feature = "serde", serde(rename = "buckets"))]
        pub buckets: Vec<ResourceBucket>,
    }

    impl ConcreteMessage for MsgProfilingResourceCounter {
        const MESSAGE_TYPE: u16 = 52995;
        const MESSAGE_NAME: &'static str = "MSG_PROFILING_RESOURCE_COUNTER";
    }

    impl SbpMessage for MsgProfilingResourceCounter {
        fn message_name(&self) -> &'static str {
            <Self as ConcreteMessage>::MESSAGE_NAME
        }
        fn message_type(&self) -> Option<u16> {
            Some(<Self as ConcreteMessage>::MESSAGE_TYPE)
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
        fn is_valid(&self) -> bool {
            true
        }
        fn into_valid_msg(self) -> Result<Self, crate::messages::invalid::Invalid> {
            Ok(self)
        }
    }

    impl FriendlyName for MsgProfilingResourceCounter {
        fn friendly_name() -> &'static str {
            "PROFILING RESOURCE COUNTER"
        }
    }

    impl TryFrom<Sbp> for MsgProfilingResourceCounter {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgProfilingResourceCounter(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgProfilingResourceCounter {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <Vec<ResourceBucket> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.seq_no)
                + WireFormat::len(&self.seq_len)
                + WireFormat::len(&self.buckets)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.seq_no, buf);
            WireFormat::write(&self.seq_len, buf);
            WireFormat::write(&self.buckets, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgProfilingResourceCounter {
                sender_id: None,
                seq_no: WireFormat::parse_unchecked(buf),
                seq_len: WireFormat::parse_unchecked(buf),
                buckets: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_profiling_system_info {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// System Profiling Information
    ///
    /// Contains basic information about system resource usage. System is defined
    /// in terms of the source of this message and may vary from  sender to
    /// sender. Refer to product documentation to understand the exact scope and
    /// meaning of this message.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgProfilingSystemInfo {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Total cpu time in microseconds consumed by this system
        #[cfg_attr(feature = "serde", serde(rename = "total_cpu_time"))]
        pub total_cpu_time: u64,
        /// Age of the producing system in microseconds
        #[cfg_attr(feature = "serde", serde(rename = "age"))]
        pub age: u64,
        /// Number of threads being tracked by this system
        #[cfg_attr(feature = "serde", serde(rename = "n_threads"))]
        pub n_threads: u8,
        /// Number of bytes allocated on the heap
        #[cfg_attr(feature = "serde", serde(rename = "heap_usage"))]
        pub heap_usage: u32,
    }

    impl ConcreteMessage for MsgProfilingSystemInfo {
        const MESSAGE_TYPE: u16 = 52993;
        const MESSAGE_NAME: &'static str = "MSG_PROFILING_SYSTEM_INFO";
    }

    impl SbpMessage for MsgProfilingSystemInfo {
        fn message_name(&self) -> &'static str {
            <Self as ConcreteMessage>::MESSAGE_NAME
        }
        fn message_type(&self) -> Option<u16> {
            Some(<Self as ConcreteMessage>::MESSAGE_TYPE)
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
        fn is_valid(&self) -> bool {
            true
        }
        fn into_valid_msg(self) -> Result<Self, crate::messages::invalid::Invalid> {
            Ok(self)
        }
    }

    impl FriendlyName for MsgProfilingSystemInfo {
        fn friendly_name() -> &'static str {
            "PROFILING SYSTEM INFO"
        }
    }

    impl TryFrom<Sbp> for MsgProfilingSystemInfo {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgProfilingSystemInfo(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgProfilingSystemInfo {
        const MIN_LEN: usize = <u64 as WireFormat>::MIN_LEN
            + <u64 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u32 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.total_cpu_time)
                + WireFormat::len(&self.age)
                + WireFormat::len(&self.n_threads)
                + WireFormat::len(&self.heap_usage)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.total_cpu_time, buf);
            WireFormat::write(&self.age, buf);
            WireFormat::write(&self.n_threads, buf);
            WireFormat::write(&self.heap_usage, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgProfilingSystemInfo {
                sender_id: None,
                total_cpu_time: WireFormat::parse_unchecked(buf),
                age: WireFormat::parse_unchecked(buf),
                n_threads: WireFormat::parse_unchecked(buf),
                heap_usage: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_profiling_thread_info {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Thread Profiling Information
    ///
    /// Contains profiling information related to a single thread being tracked by
    /// the producing system. Refer to product documentation to understand the
    /// exact scope and meaning of this message.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgProfilingThreadInfo {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Total cpu time in microseconds consumed by this thread
        #[cfg_attr(feature = "serde", serde(rename = "total_cpu_time"))]
        pub total_cpu_time: u64,
        /// Age of the thread in microseconds
        #[cfg_attr(feature = "serde", serde(rename = "age"))]
        pub age: u64,
        /// Thread state
        #[cfg_attr(feature = "serde", serde(rename = "state"))]
        pub state: u8,
        /// Stack size in bytes
        #[cfg_attr(feature = "serde", serde(rename = "stack_size"))]
        pub stack_size: u32,
        /// Stack high water usage in bytes
        #[cfg_attr(feature = "serde", serde(rename = "stack_usage"))]
        pub stack_usage: u32,
        /// Thread name
        #[cfg_attr(feature = "serde", serde(rename = "name"))]
        pub name: SbpString<Vec<u8>, NullTerminated>,
    }

    impl MsgProfilingThreadInfo {
        /// Gets the [ThreadState][self::ThreadState] stored in the `state` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `ThreadState` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `ThreadState` were added.
        pub fn thread_state(&self) -> Result<ThreadState, u8> {
            get_bit_range!(self.state, u8, u8, 1, 0).try_into()
        }

        /// Set the bitrange corresponding to the [ThreadState][ThreadState] of the `state` bitfield.
        pub fn set_thread_state(&mut self, thread_state: ThreadState) {
            set_bit_range!(&mut self.state, thread_state, u8, u8, 1, 0);
        }
    }

    impl ConcreteMessage for MsgProfilingThreadInfo {
        const MESSAGE_TYPE: u16 = 52994;
        const MESSAGE_NAME: &'static str = "MSG_PROFILING_THREAD_INFO";
    }

    impl SbpMessage for MsgProfilingThreadInfo {
        fn message_name(&self) -> &'static str {
            <Self as ConcreteMessage>::MESSAGE_NAME
        }
        fn message_type(&self) -> Option<u16> {
            Some(<Self as ConcreteMessage>::MESSAGE_TYPE)
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
        fn is_valid(&self) -> bool {
            true
        }
        fn into_valid_msg(self) -> Result<Self, crate::messages::invalid::Invalid> {
            Ok(self)
        }
    }

    impl FriendlyName for MsgProfilingThreadInfo {
        fn friendly_name() -> &'static str {
            "PROFILING THREAD INFO"
        }
    }

    impl TryFrom<Sbp> for MsgProfilingThreadInfo {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgProfilingThreadInfo(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgProfilingThreadInfo {
        const MIN_LEN: usize = <u64 as WireFormat>::MIN_LEN
            + <u64 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u32 as WireFormat>::MIN_LEN
            + <u32 as WireFormat>::MIN_LEN
            + <SbpString<Vec<u8>, NullTerminated> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.total_cpu_time)
                + WireFormat::len(&self.age)
                + WireFormat::len(&self.state)
                + WireFormat::len(&self.stack_size)
                + WireFormat::len(&self.stack_usage)
                + WireFormat::len(&self.name)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.total_cpu_time, buf);
            WireFormat::write(&self.age, buf);
            WireFormat::write(&self.state, buf);
            WireFormat::write(&self.stack_size, buf);
            WireFormat::write(&self.stack_usage, buf);
            WireFormat::write(&self.name, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgProfilingThreadInfo {
                sender_id: None,
                total_cpu_time: WireFormat::parse_unchecked(buf),
                age: WireFormat::parse_unchecked(buf),
                state: WireFormat::parse_unchecked(buf),
                stack_size: WireFormat::parse_unchecked(buf),
                stack_usage: WireFormat::parse_unchecked(buf),
                name: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Thread state
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum ThreadState {
        /// External
        External = 0,

        /// Running
        Running = 1,

        /// Stopped
        Stopped = 2,
    }

    impl std::fmt::Display for ThreadState {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                ThreadState::External => f.write_str("External"),
                ThreadState::Running => f.write_str("Running"),
                ThreadState::Stopped => f.write_str("Stopped"),
            }
        }
    }

    impl TryFrom<u8> for ThreadState {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(ThreadState::External),
                1 => Ok(ThreadState::Running),
                2 => Ok(ThreadState::Stopped),
                i => Err(i),
            }
        }
    }
}

pub mod resource_bucket {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// A bucket containing various resources
    ///
    /// Information about allocation of various resources grouped by buckets.
    /// Refer to product documentation to understand the meaning and values in
    /// this message.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct ResourceBucket {
        /// Bucket name
        #[cfg_attr(feature = "serde", serde(rename = "name"))]
        pub name: SbpString<[u8; 21], NullTerminated>,
        /// Number of threads
        #[cfg_attr(feature = "serde", serde(rename = "thread"))]
        pub thread: u8,
        /// Number of mutexes
        #[cfg_attr(feature = "serde", serde(rename = "mutex"))]
        pub mutex: u8,
        /// Number of condition variables
        #[cfg_attr(feature = "serde", serde(rename = "cv"))]
        pub cv: u8,
        /// Number of IO handles
        #[cfg_attr(feature = "serde", serde(rename = "io"))]
        pub io: u8,
        /// Number of bytes allocated on the heap
        #[cfg_attr(feature = "serde", serde(rename = "heap_bytes_alloc"))]
        pub heap_bytes_alloc: u32,
        /// Number of bytes freed on the heap
        #[cfg_attr(feature = "serde", serde(rename = "heap_bytes_free"))]
        pub heap_bytes_free: u32,
        /// Number of bytes written to IO handles
        #[cfg_attr(feature = "serde", serde(rename = "io_write"))]
        pub io_write: u32,
        /// Number of bytes read from IO handles
        #[cfg_attr(feature = "serde", serde(rename = "io_read"))]
        pub io_read: u32,
    }

    impl WireFormat for ResourceBucket {
        const MIN_LEN: usize = <SbpString<[u8; 21], NullTerminated> as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u32 as WireFormat>::MIN_LEN
            + <u32 as WireFormat>::MIN_LEN
            + <u32 as WireFormat>::MIN_LEN
            + <u32 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.name)
                + WireFormat::len(&self.thread)
                + WireFormat::len(&self.mutex)
                + WireFormat::len(&self.cv)
                + WireFormat::len(&self.io)
                + WireFormat::len(&self.heap_bytes_alloc)
                + WireFormat::len(&self.heap_bytes_free)
                + WireFormat::len(&self.io_write)
                + WireFormat::len(&self.io_read)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.name, buf);
            WireFormat::write(&self.thread, buf);
            WireFormat::write(&self.mutex, buf);
            WireFormat::write(&self.cv, buf);
            WireFormat::write(&self.io, buf);
            WireFormat::write(&self.heap_bytes_alloc, buf);
            WireFormat::write(&self.heap_bytes_free, buf);
            WireFormat::write(&self.io_write, buf);
            WireFormat::write(&self.io_read, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            ResourceBucket {
                name: WireFormat::parse_unchecked(buf),
                thread: WireFormat::parse_unchecked(buf),
                mutex: WireFormat::parse_unchecked(buf),
                cv: WireFormat::parse_unchecked(buf),
                io: WireFormat::parse_unchecked(buf),
                heap_bytes_alloc: WireFormat::parse_unchecked(buf),
                heap_bytes_free: WireFormat::parse_unchecked(buf),
                io_write: WireFormat::parse_unchecked(buf),
                io_read: WireFormat::parse_unchecked(buf),
            }
        }
    }
}
