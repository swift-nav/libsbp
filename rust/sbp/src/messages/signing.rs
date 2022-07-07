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
// Automatically generated from yaml/swiftnav/sbp/signing.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages relating to signatures
pub use msg_ed25519_certificate::MsgEd25519Certificate;
pub use msg_ed25519_signature::MsgEd25519Signature;

pub mod msg_ed25519_certificate {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
    /// ED25519 certificate, split over multiple messages
    #[cfg_attr(feature = "serde", derive(serde::Serialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgEd25519Certificate {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing))]
        pub sender_id: Option<u16>,
        #[cfg_attr(feature = "serde", serde(rename(serialize = "stub")))]
        pub stub: Vec<u8>,
    }

    impl ConcreteMessage for MsgEd25519Certificate {
        const MESSAGE_TYPE: u16 = 3074;
        const MESSAGE_NAME: &'static str = "MSG_ED25519_CERTIFICATE";
    }

    impl SbpMessage for MsgEd25519Certificate {
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

    impl TryFrom<Sbp> for MsgEd25519Certificate {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgEd25519Certificate(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgEd25519Certificate {
        const MIN_LEN: usize = <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.stub)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.stub, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgEd25519Certificate {
                sender_id: None,
                stub: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_ed25519_signature {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
    /// ED25519 signature for groups of RTCM messages
    #[cfg_attr(feature = "serde", derive(serde::Serialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgEd25519Signature {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing))]
        pub sender_id: Option<u16>,
        #[cfg_attr(feature = "serde", serde(rename(serialize = "stub")))]
        pub stub: Vec<u8>,
    }

    impl ConcreteMessage for MsgEd25519Signature {
        const MESSAGE_TYPE: u16 = 3073;
        const MESSAGE_NAME: &'static str = "MSG_ED25519_SIGNATURE";
    }

    impl SbpMessage for MsgEd25519Signature {
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

    impl TryFrom<Sbp> for MsgEd25519Signature {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgEd25519Signature(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgEd25519Signature {
        const MIN_LEN: usize = <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.stub)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.stub, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgEd25519Signature {
                sender_id: None,
                stub: WireFormat::parse_unchecked(buf),
            }
        }
    }
}
