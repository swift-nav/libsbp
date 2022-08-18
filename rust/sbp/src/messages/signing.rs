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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgEd25519Certificate {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Total number messages that make up the certificate. First nibble is the
        /// size of the sequence (n), second nibble is the zero-indexed counter (ith
        /// packet of n)
        #[cfg_attr(feature = "serde", serde(rename = "n_msg"))]
        pub n_msg: u8,
        /// SHA-1 fingerprint of the associated certificate.
        #[cfg_attr(feature = "serde", serde(rename = "fingerprint"))]
        pub fingerprint: [u8; 20],
        /// ED25519 certificate bytes.
        #[cfg_attr(feature = "serde", serde(rename = "certificate_bytes"))]
        pub certificate_bytes: Vec<u8>,
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
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
            + <[u8; 20] as WireFormat>::MIN_LEN
            + <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.n_msg)
                + WireFormat::len(&self.fingerprint)
                + WireFormat::len(&self.certificate_bytes)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.n_msg, buf);
            WireFormat::write(&self.fingerprint, buf);
            WireFormat::write(&self.certificate_bytes, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgEd25519Certificate {
                sender_id: None,
                n_msg: WireFormat::parse_unchecked(buf),
                fingerprint: WireFormat::parse_unchecked(buf),
                certificate_bytes: WireFormat::parse_unchecked(buf),
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgEd25519Signature {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// ED25519 signature for messages.
        #[cfg_attr(feature = "serde", serde(with = "BigArray", rename = "signature"))]
        pub signature: [u8; 64],
        /// SHA-1 fingerprint of the associated certificate.
        #[cfg_attr(feature = "serde", serde(rename = "fingerprint"))]
        pub fingerprint: [u8; 20],
        /// CRCs of signed messages.
        #[cfg_attr(feature = "serde", serde(rename = "signed_messages"))]
        pub signed_messages: Vec<u32>,
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
        const MIN_LEN: usize = <[u8; 64] as WireFormat>::MIN_LEN
            + <[u8; 20] as WireFormat>::MIN_LEN
            + <Vec<u32> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.signature)
                + WireFormat::len(&self.fingerprint)
                + WireFormat::len(&self.signed_messages)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.signature, buf);
            WireFormat::write(&self.fingerprint, buf);
            WireFormat::write(&self.signed_messages, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgEd25519Signature {
                sender_id: None,
                signature: WireFormat::parse_unchecked(buf),
                fingerprint: WireFormat::parse_unchecked(buf),
                signed_messages: WireFormat::parse_unchecked(buf),
            }
        }
    }
}
