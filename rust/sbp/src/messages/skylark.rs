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
// Automatically generated from yaml/swiftnav/sbp/skylark.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages from the Skylark corrections service.
pub use msg_acknowledge::MsgAcknowledge;

pub mod msg_acknowledge {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;
    /// Acknowledgement message in response to a request for corrections
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgAcknowledge {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Echo of the request ID field from the corresponding CRA message, or 255
        /// if no request ID was provided.
        #[cfg_attr(feature = "serde", serde(rename = "request_id"))]
        pub request_id: u8,
        /// Echo of the Area ID field from the corresponding CRA message.
        #[cfg_attr(feature = "serde", serde(rename = "area_id"))]
        pub area_id: u32,
        /// Reported status of the request.
        #[cfg_attr(feature = "serde", serde(rename = "response_code"))]
        pub response_code: u8,
        /// Contains the message group(s) that will be sent in response from the
        /// corresponding CRA correction mask. An echo of the correction mask field
        /// from the corresponding CRA message.
        #[cfg_attr(feature = "serde", serde(rename = "correction_mask_on_demand"))]
        pub correction_mask_on_demand: u16,
        /// For future expansion. Always set to 0.
        #[cfg_attr(feature = "serde", serde(rename = "correction_mask_stream"))]
        pub correction_mask_stream: u16,
        /// The solution ID of the instance providing the corrections.
        #[cfg_attr(feature = "serde", serde(rename = "solution_id"))]
        pub solution_id: u8,
    }

    impl MsgAcknowledge {
        /// Gets the [ResponseCode][self::ResponseCode] stored in the `response_code` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `ResponseCode` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `ResponseCode` were added.
        pub fn response_code(&self) -> Result<ResponseCode, u8> {
            get_bit_range!(self.response_code, u8, u8, 7, 0).try_into()
        }

        /// Set the bitrange corresponding to the [ResponseCode][ResponseCode] of the `response_code` bitfield.
        pub fn set_response_code(&mut self, response_code: ResponseCode) {
            set_bit_range!(&mut self.response_code, response_code, u8, u8, 7, 0);
        }
    }

    impl ConcreteMessage for MsgAcknowledge {
        const MESSAGE_TYPE: u16 = 4000;
        const MESSAGE_NAME: &'static str = "MSG_ACKNOWLEDGE";
    }

    impl SbpMessage for MsgAcknowledge {
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

    impl TryFrom<Sbp> for MsgAcknowledge {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgAcknowledge(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgAcknowledge {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
            + <u32 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.request_id)
                + WireFormat::len(&self.area_id)
                + WireFormat::len(&self.response_code)
                + WireFormat::len(&self.correction_mask_on_demand)
                + WireFormat::len(&self.correction_mask_stream)
                + WireFormat::len(&self.solution_id)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.request_id, buf);
            WireFormat::write(&self.area_id, buf);
            WireFormat::write(&self.response_code, buf);
            WireFormat::write(&self.correction_mask_on_demand, buf);
            WireFormat::write(&self.correction_mask_stream, buf);
            WireFormat::write(&self.solution_id, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgAcknowledge {
                sender_id: None,
                request_id: WireFormat::parse_unchecked(buf),
                area_id: WireFormat::parse_unchecked(buf),
                response_code: WireFormat::parse_unchecked(buf),
                correction_mask_on_demand: WireFormat::parse_unchecked(buf),
                correction_mask_stream: WireFormat::parse_unchecked(buf),
                solution_id: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Response code
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum ResponseCode {
        /// Ok
        Ok = 0,

        /// Out of coverage
        OutOfCoverage = 1,

        /// Forbidden
        Forbidden = 2,

        /// Invalid request
        InvalidRequest = 3,

        /// Invalid area id
        InvalidAreaId = 4,
    }

    impl std::fmt::Display for ResponseCode {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                ResponseCode::Ok => f.write_str("Ok"),
                ResponseCode::OutOfCoverage => f.write_str("Out of coverage"),
                ResponseCode::Forbidden => f.write_str("Forbidden"),
                ResponseCode::InvalidRequest => f.write_str("Invalid request"),
                ResponseCode::InvalidAreaId => f.write_str("Invalid area id"),
            }
        }
    }

    impl TryFrom<u8> for ResponseCode {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(ResponseCode::Ok),
                1 => Ok(ResponseCode::OutOfCoverage),
                2 => Ok(ResponseCode::Forbidden),
                3 => Ok(ResponseCode::InvalidRequest),
                4 => Ok(ResponseCode::InvalidAreaId),
                i => Err(i),
            }
        }
    }
}
