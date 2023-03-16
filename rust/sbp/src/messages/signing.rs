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
pub use msg_certificate_chain::MsgCertificateChain;
pub use msg_ecdsa_certificate::MsgEcdsaCertificate;
pub use msg_ecdsa_signature::MsgEcdsaSignature;
pub use msg_ecdsa_signature_dep::MsgEcdsaSignatureDep;
pub use msg_ed25519_certificate_dep::MsgEd25519CertificateDep;
pub use msg_ed25519_signature_dep_a::MsgEd25519SignatureDepA;
pub use msg_ed25519_signature_dep_b::MsgEd25519SignatureDepB;
pub use utc_time::UtcTime;

pub mod msg_certificate_chain {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;
    /// The certificate chain
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgCertificateChain {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// SHA-1 fingerprint of the root certificate
        #[cfg_attr(feature = "serde", serde(rename = "root_certificate"))]
        pub root_certificate: [u8; 20],
        /// SHA-1 fingerprint of the intermediate certificate
        #[cfg_attr(feature = "serde", serde(rename = "intermediate_certificate"))]
        pub intermediate_certificate: [u8; 20],
        /// SHA-1 fingerprint of the corrections certificate
        #[cfg_attr(feature = "serde", serde(rename = "corrections_certificate"))]
        pub corrections_certificate: [u8; 20],
        /// The certificate chain comprised of three fingerprints: root certificate,
        /// intermediate certificate and corrections certificate.
        #[cfg_attr(feature = "serde", serde(rename = "expiration"))]
        pub expiration: UtcTime,
        /// An ECDSA signature (created by the root certificate) over the
        /// concatenation of the SBP payload bytes preceding this field. That is,
        /// the concatenation of `root_certificate`, `intermediate_certificate`,
        /// `corrections_certificate` and `expiration`.  This certificate chain
        /// (allow list) can also be validated by fetching it from
        /// `http(s)://certs.swiftnav.com/chain`.
        #[cfg_attr(feature = "serde", serde(with = "BigArray", rename = "signature"))]
        pub signature: [u8; 64],
    }

    impl ConcreteMessage for MsgCertificateChain {
        const MESSAGE_TYPE: u16 = 3077;
        const MESSAGE_NAME: &'static str = "MSG_CERTIFICATE_CHAIN";
    }

    impl SbpMessage for MsgCertificateChain {
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

    impl FriendlyName for MsgCertificateChain {
        fn friendly_name() -> &'static str {
            "CERTIFICATE CHAIN"
        }
    }

    impl TryFrom<Sbp> for MsgCertificateChain {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgCertificateChain(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgCertificateChain {
        const MIN_LEN: usize = <[u8; 20] as WireFormat>::MIN_LEN
            + <[u8; 20] as WireFormat>::MIN_LEN
            + <[u8; 20] as WireFormat>::MIN_LEN
            + <UtcTime as WireFormat>::MIN_LEN
            + <[u8; 64] as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.root_certificate)
                + WireFormat::len(&self.intermediate_certificate)
                + WireFormat::len(&self.corrections_certificate)
                + WireFormat::len(&self.expiration)
                + WireFormat::len(&self.signature)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.root_certificate, buf);
            WireFormat::write(&self.intermediate_certificate, buf);
            WireFormat::write(&self.corrections_certificate, buf);
            WireFormat::write(&self.expiration, buf);
            WireFormat::write(&self.signature, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgCertificateChain {
                sender_id: None,
                root_certificate: WireFormat::parse_unchecked(buf),
                intermediate_certificate: WireFormat::parse_unchecked(buf),
                corrections_certificate: WireFormat::parse_unchecked(buf),
                expiration: WireFormat::parse_unchecked(buf),
                signature: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_ecdsa_certificate {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// An ECDSA certificate split over multiple messages
    ///
    /// A DER encoded x.509 ECDSA-256 certificate (using curve secp256r1).
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgEcdsaCertificate {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Total number messages that make up the certificate. The first nibble
        /// (mask 0xF0 or left shifted by 4 bits) is the size of the sequence (n),
        /// second nibble (mask 0x0F) is the zero-indexed counter (ith packet of n).
        #[cfg_attr(feature = "serde", serde(rename = "n_msg"))]
        pub n_msg: u8,
        /// The last 4 bytes of the certificate's SHA-1 fingerprint
        #[cfg_attr(feature = "serde", serde(rename = "certificate_id"))]
        pub certificate_id: [u8; 4],
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
        /// DER encoded x.509 ECDSA certificate bytes
        #[cfg_attr(feature = "serde", serde(rename = "certificate_bytes"))]
        pub certificate_bytes: Vec<u8>,
    }

    impl MsgEcdsaCertificate {
        /// Gets the [CertificateType][self::CertificateType] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `CertificateType` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `CertificateType` were added.
        pub fn certificate_type(&self) -> Result<CertificateType, u8> {
            get_bit_range!(self.flags, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [CertificateType][CertificateType] of the `flags` bitfield.
        pub fn set_certificate_type(&mut self, certificate_type: CertificateType) {
            set_bit_range!(&mut self.flags, certificate_type, u8, u8, 2, 0);
        }
    }

    impl ConcreteMessage for MsgEcdsaCertificate {
        const MESSAGE_TYPE: u16 = 3076;
        const MESSAGE_NAME: &'static str = "MSG_ECDSA_CERTIFICATE";
    }

    impl SbpMessage for MsgEcdsaCertificate {
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

    impl FriendlyName for MsgEcdsaCertificate {
        fn friendly_name() -> &'static str {
            "ECDSA CERTIFICATE"
        }
    }

    impl TryFrom<Sbp> for MsgEcdsaCertificate {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgEcdsaCertificate(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgEcdsaCertificate {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
            + <[u8; 4] as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.n_msg)
                + WireFormat::len(&self.certificate_id)
                + WireFormat::len(&self.flags)
                + WireFormat::len(&self.certificate_bytes)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.n_msg, buf);
            WireFormat::write(&self.certificate_id, buf);
            WireFormat::write(&self.flags, buf);
            WireFormat::write(&self.certificate_bytes, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgEcdsaCertificate {
                sender_id: None,
                n_msg: WireFormat::parse_unchecked(buf),
                certificate_id: WireFormat::parse_unchecked(buf),
                flags: WireFormat::parse_unchecked(buf),
                certificate_bytes: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Certificate type
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum CertificateType {
        /// Corrections certificate
        CorrectionsCertificate = 0,

        /// Root certificate
        RootCertificate = 1,

        /// Intermediate certificate
        IntermediateCertificate = 2,
    }

    impl std::fmt::Display for CertificateType {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                CertificateType::CorrectionsCertificate => f.write_str("Corrections certificate"),
                CertificateType::RootCertificate => f.write_str("Root certificate"),
                CertificateType::IntermediateCertificate => f.write_str("Intermediate certificate"),
            }
        }
    }

    impl TryFrom<u8> for CertificateType {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(CertificateType::CorrectionsCertificate),
                1 => Ok(CertificateType::RootCertificate),
                2 => Ok(CertificateType::IntermediateCertificate),
                i => Err(i),
            }
        }
    }
}

pub mod msg_ecdsa_signature {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// An ECDSA signature
    ///
    /// An ECDSA-256 signature using SHA-256 as the message digest algorithm.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgEcdsaSignature {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Describes the format of the `signed\_messages` field below.
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
        /// Signature message counter. Zero indexed and incremented with each
        /// signature message.  The counter will not increment if this message was
        /// in response to an on demand request.  The counter will roll over after
        /// 256 messages. Upon connection, the value of the counter may not
        /// initially be zero.
        #[cfg_attr(feature = "serde", serde(rename = "stream_counter"))]
        pub stream_counter: u8,
        /// On demand message counter. Zero indexed and incremented with each
        /// signature message sent in response to an on demand message. The counter
        /// will roll over after 256 messages.  Upon connection, the value of the
        /// counter may not initially be zero.
        #[cfg_attr(feature = "serde", serde(rename = "on_demand_counter"))]
        pub on_demand_counter: u8,
        /// The last 4 bytes of the certificate's SHA-1 fingerprint
        #[cfg_attr(feature = "serde", serde(rename = "certificate_id"))]
        pub certificate_id: [u8; 4],
        /// Number of bytes to use of the signature field.
        #[cfg_attr(feature = "serde", serde(rename = "n_signature_bytes"))]
        pub n_signature_bytes: u8,
        /// DER encoded ECDSA signature for the messages using SHA-256 as the digest
        /// algorithm.
        #[cfg_attr(feature = "serde", serde(with = "BigArray", rename = "signature"))]
        pub signature: [u8; 72],
        /// CRCs of the messages covered by this signature.  For Skylark, which
        /// delivers SBP messages wrapped in Swift's proprietary RTCM message, these
        /// are the 24-bit CRCs from the RTCM message framing. For SBP only streams,
        /// this will be 16-bit CRCs from the SBP framing.  See the `flags` field to
        /// determine the type of CRCs covered.
        #[cfg_attr(feature = "serde", serde(rename = "signed_messages"))]
        pub signed_messages: Vec<u8>,
    }

    impl MsgEcdsaSignature {
        /// Gets the [CrcType][self::CrcType] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `CrcType` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `CrcType` were added.
        pub fn crc_type(&self) -> Result<CrcType, u8> {
            get_bit_range!(self.flags, u8, u8, 1, 0).try_into()
        }

        /// Set the bitrange corresponding to the [CrcType][CrcType] of the `flags` bitfield.
        pub fn set_crc_type(&mut self, crc_type: CrcType) {
            set_bit_range!(&mut self.flags, crc_type, u8, u8, 1, 0);
        }
    }

    impl ConcreteMessage for MsgEcdsaSignature {
        const MESSAGE_TYPE: u16 = 3079;
        const MESSAGE_NAME: &'static str = "MSG_ECDSA_SIGNATURE";
    }

    impl SbpMessage for MsgEcdsaSignature {
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

    impl FriendlyName for MsgEcdsaSignature {
        fn friendly_name() -> &'static str {
            "ECDSA SIGNATURE"
        }
    }

    impl TryFrom<Sbp> for MsgEcdsaSignature {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgEcdsaSignature(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgEcdsaSignature {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <[u8; 4] as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <[u8; 72] as WireFormat>::MIN_LEN
            + <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.flags)
                + WireFormat::len(&self.stream_counter)
                + WireFormat::len(&self.on_demand_counter)
                + WireFormat::len(&self.certificate_id)
                + WireFormat::len(&self.n_signature_bytes)
                + WireFormat::len(&self.signature)
                + WireFormat::len(&self.signed_messages)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.flags, buf);
            WireFormat::write(&self.stream_counter, buf);
            WireFormat::write(&self.on_demand_counter, buf);
            WireFormat::write(&self.certificate_id, buf);
            WireFormat::write(&self.n_signature_bytes, buf);
            WireFormat::write(&self.signature, buf);
            WireFormat::write(&self.signed_messages, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgEcdsaSignature {
                sender_id: None,
                flags: WireFormat::parse_unchecked(buf),
                stream_counter: WireFormat::parse_unchecked(buf),
                on_demand_counter: WireFormat::parse_unchecked(buf),
                certificate_id: WireFormat::parse_unchecked(buf),
                n_signature_bytes: WireFormat::parse_unchecked(buf),
                signature: WireFormat::parse_unchecked(buf),
                signed_messages: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// CRC type
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum CrcType {
        /// 24-bit CRCs from RTCM framing
        _24BitCrcsFromRtcmFraming = 0,

        /// 16-bit CRCs from SBP framing
        _16BitCrcsFromSbpFraming = 1,
    }

    impl std::fmt::Display for CrcType {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                CrcType::_24BitCrcsFromRtcmFraming => f.write_str("24-bit CRCs from RTCM framing"),
                CrcType::_16BitCrcsFromSbpFraming => f.write_str("16-bit CRCs from SBP framing"),
            }
        }
    }

    impl TryFrom<u8> for CrcType {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(CrcType::_24BitCrcsFromRtcmFraming),
                1 => Ok(CrcType::_16BitCrcsFromSbpFraming),
                i => Err(i),
            }
        }
    }
}

pub mod msg_ecdsa_signature_dep {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// An ECDSA signature
    ///
    /// An ECDSA-256 signature using SHA-256 as the message digest algorithm.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgEcdsaSignatureDep {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Describes the format of the `signed\_messages` field below.
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u8,
        /// Signature message counter. Zero indexed and incremented with each
        /// signature message.  The counter will not increment if this message was
        /// in response to an on demand request.  The counter will roll over after
        /// 256 messages. Upon connection, the value of the counter may not
        /// initially be zero.
        #[cfg_attr(feature = "serde", serde(rename = "stream_counter"))]
        pub stream_counter: u8,
        /// On demand message counter. Zero indexed and incremented with each
        /// signature message sent in response to an on demand message. The counter
        /// will roll over after 256 messages.  Upon connection, the value of the
        /// counter may not initially be zero.
        #[cfg_attr(feature = "serde", serde(rename = "on_demand_counter"))]
        pub on_demand_counter: u8,
        /// The last 4 bytes of the certificate's SHA-1 fingerprint
        #[cfg_attr(feature = "serde", serde(rename = "certificate_id"))]
        pub certificate_id: [u8; 4],
        /// ECDSA signature for the messages using SHA-256 as the digest algorithm.
        #[cfg_attr(feature = "serde", serde(with = "BigArray", rename = "signature"))]
        pub signature: [u8; 64],
        /// CRCs of the messages covered by this signature.  For Skylark, which
        /// delivers SBP messages wrapped in Swift's proprietary RTCM message, these
        /// are the 24-bit CRCs from the RTCM message framing. For SBP only streams,
        /// this will be 16-bit CRCs from the SBP framing.  See the `flags` field to
        /// determine the type of CRCs covered.
        #[cfg_attr(feature = "serde", serde(rename = "signed_messages"))]
        pub signed_messages: Vec<u8>,
    }

    impl MsgEcdsaSignatureDep {
        /// Gets the [CrcType][self::CrcType] stored in the `flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `CrcType` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `CrcType` were added.
        pub fn crc_type(&self) -> Result<CrcType, u8> {
            get_bit_range!(self.flags, u8, u8, 1, 0).try_into()
        }

        /// Set the bitrange corresponding to the [CrcType][CrcType] of the `flags` bitfield.
        pub fn set_crc_type(&mut self, crc_type: CrcType) {
            set_bit_range!(&mut self.flags, crc_type, u8, u8, 1, 0);
        }
    }

    impl ConcreteMessage for MsgEcdsaSignatureDep {
        const MESSAGE_TYPE: u16 = 3078;
        const MESSAGE_NAME: &'static str = "MSG_ECDSA_SIGNATURE_DEP";
    }

    impl SbpMessage for MsgEcdsaSignatureDep {
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

    impl FriendlyName for MsgEcdsaSignatureDep {
        fn friendly_name() -> &'static str {
            "ECDSA SIGNATURE DEP"
        }
    }

    impl TryFrom<Sbp> for MsgEcdsaSignatureDep {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgEcdsaSignatureDep(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgEcdsaSignatureDep {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <[u8; 4] as WireFormat>::MIN_LEN
            + <[u8; 64] as WireFormat>::MIN_LEN
            + <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.flags)
                + WireFormat::len(&self.stream_counter)
                + WireFormat::len(&self.on_demand_counter)
                + WireFormat::len(&self.certificate_id)
                + WireFormat::len(&self.signature)
                + WireFormat::len(&self.signed_messages)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.flags, buf);
            WireFormat::write(&self.stream_counter, buf);
            WireFormat::write(&self.on_demand_counter, buf);
            WireFormat::write(&self.certificate_id, buf);
            WireFormat::write(&self.signature, buf);
            WireFormat::write(&self.signed_messages, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgEcdsaSignatureDep {
                sender_id: None,
                flags: WireFormat::parse_unchecked(buf),
                stream_counter: WireFormat::parse_unchecked(buf),
                on_demand_counter: WireFormat::parse_unchecked(buf),
                certificate_id: WireFormat::parse_unchecked(buf),
                signature: WireFormat::parse_unchecked(buf),
                signed_messages: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// CRC type
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum CrcType {
        /// 24-bit CRCs from RTCM framing
        _24BitCrcsFromRtcmFraming = 0,

        /// 16-bit CRCs from SBP framing
        _16BitCrcsFromSbpFraming = 1,
    }

    impl std::fmt::Display for CrcType {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                CrcType::_24BitCrcsFromRtcmFraming => f.write_str("24-bit CRCs from RTCM framing"),
                CrcType::_16BitCrcsFromSbpFraming => f.write_str("16-bit CRCs from SBP framing"),
            }
        }
    }

    impl TryFrom<u8> for CrcType {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(CrcType::_24BitCrcsFromRtcmFraming),
                1 => Ok(CrcType::_16BitCrcsFromSbpFraming),
                i => Err(i),
            }
        }
    }
}

pub mod msg_ed25519_certificate_dep {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgEd25519CertificateDep {
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

    impl ConcreteMessage for MsgEd25519CertificateDep {
        const MESSAGE_TYPE: u16 = 3074;
        const MESSAGE_NAME: &'static str = "MSG_ED25519_CERTIFICATE_DEP";
    }

    impl SbpMessage for MsgEd25519CertificateDep {
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

    impl FriendlyName for MsgEd25519CertificateDep {
        fn friendly_name() -> &'static str {
            "ED25519 CERTIFICATE DEP"
        }
    }

    impl TryFrom<Sbp> for MsgEd25519CertificateDep {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgEd25519CertificateDep(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgEd25519CertificateDep {
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
            MsgEd25519CertificateDep {
                sender_id: None,
                n_msg: WireFormat::parse_unchecked(buf),
                fingerprint: WireFormat::parse_unchecked(buf),
                certificate_bytes: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_ed25519_signature_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;
    /// Deprecated
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgEd25519SignatureDepA {
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

    impl ConcreteMessage for MsgEd25519SignatureDepA {
        const MESSAGE_TYPE: u16 = 3073;
        const MESSAGE_NAME: &'static str = "MSG_ED25519_SIGNATURE_DEP_A";
    }

    impl SbpMessage for MsgEd25519SignatureDepA {
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

    impl FriendlyName for MsgEd25519SignatureDepA {
        fn friendly_name() -> &'static str {
            "ED25519 SIGNATURE DEP A"
        }
    }

    impl TryFrom<Sbp> for MsgEd25519SignatureDepA {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgEd25519SignatureDepA(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgEd25519SignatureDepA {
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
            MsgEd25519SignatureDepA {
                sender_id: None,
                signature: WireFormat::parse_unchecked(buf),
                fingerprint: WireFormat::parse_unchecked(buf),
                signed_messages: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_ed25519_signature_dep_b {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgEd25519SignatureDepB {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Signature message counter. Zero indexed and incremented with each
        /// signature message.  The counter will not increment if this message was
        /// in response to an on demand request.  The counter will roll over after
        /// 256 messages. Upon connection, the value of the counter may not
        /// initially be zero.
        #[cfg_attr(feature = "serde", serde(rename = "stream_counter"))]
        pub stream_counter: u8,
        /// On demand message counter. Zero indexed and incremented with each
        /// signature message sent in response to an on demand message. The counter
        /// will roll over after 256 messages.  Upon connection, the value of the
        /// counter may not initially be zero.
        #[cfg_attr(feature = "serde", serde(rename = "on_demand_counter"))]
        pub on_demand_counter: u8,
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

    impl ConcreteMessage for MsgEd25519SignatureDepB {
        const MESSAGE_TYPE: u16 = 3075;
        const MESSAGE_NAME: &'static str = "MSG_ED25519_SIGNATURE_DEP_B";
    }

    impl SbpMessage for MsgEd25519SignatureDepB {
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

    impl FriendlyName for MsgEd25519SignatureDepB {
        fn friendly_name() -> &'static str {
            "ED25519 SIGNATURE DEP B"
        }
    }

    impl TryFrom<Sbp> for MsgEd25519SignatureDepB {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgEd25519SignatureDepB(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgEd25519SignatureDepB {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <[u8; 64] as WireFormat>::MIN_LEN
            + <[u8; 20] as WireFormat>::MIN_LEN
            + <Vec<u32> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.stream_counter)
                + WireFormat::len(&self.on_demand_counter)
                + WireFormat::len(&self.signature)
                + WireFormat::len(&self.fingerprint)
                + WireFormat::len(&self.signed_messages)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.stream_counter, buf);
            WireFormat::write(&self.on_demand_counter, buf);
            WireFormat::write(&self.signature, buf);
            WireFormat::write(&self.fingerprint, buf);
            WireFormat::write(&self.signed_messages, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgEd25519SignatureDepB {
                sender_id: None,
                stream_counter: WireFormat::parse_unchecked(buf),
                on_demand_counter: WireFormat::parse_unchecked(buf),
                signature: WireFormat::parse_unchecked(buf),
                fingerprint: WireFormat::parse_unchecked(buf),
                signed_messages: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod utc_time {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;
    /// UTC Time
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct UtcTime {
        /// Year
        #[cfg_attr(feature = "serde", serde(rename = "year"))]
        pub year: u16,
        /// Month (range 1 .. 12)
        #[cfg_attr(feature = "serde", serde(rename = "month"))]
        pub month: u8,
        /// days in the month (range 1-31)
        #[cfg_attr(feature = "serde", serde(rename = "day"))]
        pub day: u8,
        /// hours of day (range 0-23)
        #[cfg_attr(feature = "serde", serde(rename = "hours"))]
        pub hours: u8,
        /// minutes of hour (range 0-59)
        #[cfg_attr(feature = "serde", serde(rename = "minutes"))]
        pub minutes: u8,
        /// seconds of minute (range 0-60) rounded down
        #[cfg_attr(feature = "serde", serde(rename = "seconds"))]
        pub seconds: u8,
        /// nanoseconds of second (range 0-999999999)
        #[cfg_attr(feature = "serde", serde(rename = "ns"))]
        pub ns: u32,
    }

    impl WireFormat for UtcTime {
        const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u32 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.year)
                + WireFormat::len(&self.month)
                + WireFormat::len(&self.day)
                + WireFormat::len(&self.hours)
                + WireFormat::len(&self.minutes)
                + WireFormat::len(&self.seconds)
                + WireFormat::len(&self.ns)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.year, buf);
            WireFormat::write(&self.month, buf);
            WireFormat::write(&self.day, buf);
            WireFormat::write(&self.hours, buf);
            WireFormat::write(&self.minutes, buf);
            WireFormat::write(&self.seconds, buf);
            WireFormat::write(&self.ns, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            UtcTime {
                year: WireFormat::parse_unchecked(buf),
                month: WireFormat::parse_unchecked(buf),
                day: WireFormat::parse_unchecked(buf),
                hours: WireFormat::parse_unchecked(buf),
                minutes: WireFormat::parse_unchecked(buf),
                seconds: WireFormat::parse_unchecked(buf),
                ns: WireFormat::parse_unchecked(buf),
            }
        }
    }
}
