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
        /// Total time spent in measurement point
        #[cfg_attr(feature = "serde", serde(rename = "total_time"))]
        pub total_time: u32,
        /// Number of times measurement point has executed
        #[cfg_attr(feature = "serde", serde(rename = "num_executions"))]
        pub num_executions: u16,
        /// Minimum execution time
        #[cfg_attr(feature = "serde", serde(rename = "min"))]
        pub min: u32,
        /// Maximum execution time
        #[cfg_attr(feature = "serde", serde(rename = "max"))]
        pub max: u32,
        /// Return address
        #[cfg_attr(feature = "serde", serde(rename = "return_addr"))]
        pub return_addr: u64,
        /// Unique ID
        #[cfg_attr(feature = "serde", serde(rename = "id"))]
        pub id: u64,
        /// CPU slice time
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
