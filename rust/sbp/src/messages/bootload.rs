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
// Automatically generated from yaml/swiftnav/sbp/bootload.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages for the bootloading configuration of a Piksi 2.3.1.  This message
//! group does not apply to Piksi Multi.
//!
//! Note that some of these messages share the same message type ID for both
//! the host request and the device response.
pub use msg_bootloader_handshake_dep_a::MsgBootloaderHandshakeDepA;
pub use msg_bootloader_handshake_req::MsgBootloaderHandshakeReq;
pub use msg_bootloader_handshake_resp::MsgBootloaderHandshakeResp;
pub use msg_bootloader_jump_to_app::MsgBootloaderJumpToApp;
pub use msg_nap_device_dna_req::MsgNapDeviceDnaReq;
pub use msg_nap_device_dna_resp::MsgNapDeviceDnaResp;

pub mod msg_bootloader_handshake_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Deprecated
    ///
    /// Deprecated.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgBootloaderHandshakeDepA {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Version number string (not NULL terminated)
        #[cfg_attr(feature = "serde", serde(rename = "handshake"))]
        pub handshake: Vec<u8>,
    }

    impl ConcreteMessage for MsgBootloaderHandshakeDepA {
        const MESSAGE_TYPE: u16 = 176;
        const MESSAGE_NAME: &'static str = "MSG_BOOTLOADER_HANDSHAKE_DEP_A";
    }

    impl SbpMessage for MsgBootloaderHandshakeDepA {
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

    impl TryFrom<Sbp> for MsgBootloaderHandshakeDepA {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgBootloaderHandshakeDepA(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgBootloaderHandshakeDepA {
        const MIN_LEN: usize = <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.handshake)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.handshake, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgBootloaderHandshakeDepA {
                sender_id: None,
                handshake: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_bootloader_handshake_req {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Bootloading handshake request (host => device)
    ///
    /// The handshake message request from the host establishes a handshake
    /// between the device bootloader and the host. The response from the device
    /// is MSG_BOOTLOADER_HANDSHAKE_RESP.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgBootloaderHandshakeReq {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
    }

    impl ConcreteMessage for MsgBootloaderHandshakeReq {
        const MESSAGE_TYPE: u16 = 179;
        const MESSAGE_NAME: &'static str = "MSG_BOOTLOADER_HANDSHAKE_REQ";
    }

    impl SbpMessage for MsgBootloaderHandshakeReq {
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

    impl TryFrom<Sbp> for MsgBootloaderHandshakeReq {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgBootloaderHandshakeReq(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgBootloaderHandshakeReq {
        const MIN_LEN: usize = 0;
        fn len(&self) -> usize {
            0
        }
        fn write<B: BufMut>(&self, _buf: &mut B) {}
        fn parse_unchecked<B: Buf>(_buf: &mut B) -> Self {
            MsgBootloaderHandshakeReq { sender_id: None }
        }
    }
}

pub mod msg_bootloader_handshake_resp {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Bootloading handshake response (host <= device)
    ///
    /// The handshake message response from the device establishes a handshake
    /// between the device bootloader and the host. The request from the host is
    /// MSG_BOOTLOADER_HANDSHAKE_REQ.  The payload contains the bootloader version
    /// number and the SBP protocol version number.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgBootloaderHandshakeResp {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Bootloader flags
        #[cfg_attr(feature = "serde", serde(rename = "flags"))]
        pub flags: u32,
        /// Bootloader version number
        #[cfg_attr(feature = "serde", serde(rename = "version"))]
        pub version: SbpString<Vec<u8>, Unterminated>,
    }

    impl MsgBootloaderHandshakeResp {
        /// Gets the `sbp_major_protocol_version_number` stored in `flags`.
        pub fn sbp_major_protocol_version_number(&self) -> u8 {
            get_bit_range!(self.flags, u32, u8, 15, 8)
        }

        /// Sets the `sbp_major_protocol_version_number` bitrange of `flags`.
        pub fn set_sbp_major_protocol_version_number(
            &mut self,
            sbp_major_protocol_version_number: u8,
        ) {
            set_bit_range!(
                &mut self.flags,
                sbp_major_protocol_version_number,
                u32,
                u8,
                15,
                8
            );
        }

        /// Gets the `sbp_minor_protocol_version_number` stored in `flags`.
        pub fn sbp_minor_protocol_version_number(&self) -> u8 {
            get_bit_range!(self.flags, u32, u8, 7, 0)
        }

        /// Sets the `sbp_minor_protocol_version_number` bitrange of `flags`.
        pub fn set_sbp_minor_protocol_version_number(
            &mut self,
            sbp_minor_protocol_version_number: u8,
        ) {
            set_bit_range!(
                &mut self.flags,
                sbp_minor_protocol_version_number,
                u32,
                u8,
                7,
                0
            );
        }
    }

    impl ConcreteMessage for MsgBootloaderHandshakeResp {
        const MESSAGE_TYPE: u16 = 180;
        const MESSAGE_NAME: &'static str = "MSG_BOOTLOADER_HANDSHAKE_RESP";
    }

    impl SbpMessage for MsgBootloaderHandshakeResp {
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

    impl TryFrom<Sbp> for MsgBootloaderHandshakeResp {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgBootloaderHandshakeResp(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgBootloaderHandshakeResp {
        const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
            + <SbpString<Vec<u8>, Unterminated> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.flags) + WireFormat::len(&self.version)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.flags, buf);
            WireFormat::write(&self.version, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgBootloaderHandshakeResp {
                sender_id: None,
                flags: WireFormat::parse_unchecked(buf),
                version: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_bootloader_jump_to_app {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Bootloader jump to application (host => device)
    ///
    /// The host initiates the bootloader to jump to the application.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgBootloaderJumpToApp {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Ignored by the device
        #[cfg_attr(feature = "serde", serde(rename = "jump"))]
        pub jump: u8,
    }

    impl ConcreteMessage for MsgBootloaderJumpToApp {
        const MESSAGE_TYPE: u16 = 177;
        const MESSAGE_NAME: &'static str = "MSG_BOOTLOADER_JUMP_TO_APP";
    }

    impl SbpMessage for MsgBootloaderJumpToApp {
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

    impl TryFrom<Sbp> for MsgBootloaderJumpToApp {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgBootloaderJumpToApp(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgBootloaderJumpToApp {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.jump)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.jump, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgBootloaderJumpToApp {
                sender_id: None,
                jump: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_nap_device_dna_req {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Read FPGA device ID over UART request (host => device)
    ///
    /// The device message from the host reads a unique device identifier from the
    /// SwiftNAP, an FPGA. The host requests the ID by sending a
    /// MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
    /// MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
    /// that this ID is tied to the FPGA, and not related to the Piksi's serial
    /// number.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgNapDeviceDnaReq {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
    }

    impl ConcreteMessage for MsgNapDeviceDnaReq {
        const MESSAGE_TYPE: u16 = 222;
        const MESSAGE_NAME: &'static str = "MSG_NAP_DEVICE_DNA_REQ";
    }

    impl SbpMessage for MsgNapDeviceDnaReq {
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

    impl TryFrom<Sbp> for MsgNapDeviceDnaReq {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgNapDeviceDnaReq(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgNapDeviceDnaReq {
        const MIN_LEN: usize = 0;
        fn len(&self) -> usize {
            0
        }
        fn write<B: BufMut>(&self, _buf: &mut B) {}
        fn parse_unchecked<B: Buf>(_buf: &mut B) -> Self {
            MsgNapDeviceDnaReq { sender_id: None }
        }
    }
}

pub mod msg_nap_device_dna_resp {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Read FPGA device ID over UART response (host <= device)
    ///
    /// The device message from the host reads a unique device identifier from the
    /// SwiftNAP, an FPGA. The host requests the ID by sending a
    /// MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
    /// MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
    /// that this ID is tied to the FPGA, and not related to the Piksi's serial
    /// number.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgNapDeviceDnaResp {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the right.
        #[cfg_attr(feature = "serde", serde(rename = "dna"))]
        pub dna: [u8; 8],
    }

    impl ConcreteMessage for MsgNapDeviceDnaResp {
        const MESSAGE_TYPE: u16 = 221;
        const MESSAGE_NAME: &'static str = "MSG_NAP_DEVICE_DNA_RESP";
    }

    impl SbpMessage for MsgNapDeviceDnaResp {
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

    impl TryFrom<Sbp> for MsgNapDeviceDnaResp {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgNapDeviceDnaResp(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgNapDeviceDnaResp {
        const MIN_LEN: usize = <[u8; 8] as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.dna)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.dna, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgNapDeviceDnaResp {
                sender_id: None,
                dna: WireFormat::parse_unchecked(buf),
            }
        }
    }
}
