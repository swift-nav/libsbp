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
// Automatically generated from yaml/swiftnav/sbp/bootload.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages for the bootloading configuration of a Piksi 2.3.1.  This message
//! group does not apply to Piksi Multi.
//!
//! Note that some of these messages share the same message type ID for both the
//! host request and the device response.
//!

extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
#[cfg(feature = "serialize")]
use serde::{Deserialize, Serialize};

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBootloaderHandshakeDepA {
    pub sender_id: Option<u16>,
    /// Version number string (not NULL terminated)
    pub handshake: Vec<u8>,
}

impl MsgBootloaderHandshakeDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBootloaderHandshakeDepA, crate::Error> {
        Ok(MsgBootloaderHandshakeDepA {
            sender_id: None,
            handshake: crate::parser::read_u8_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgBootloaderHandshakeDepA {
    fn get_message_type(&self) -> u16 {
        176
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

impl crate::serialize::SbpSerialize for MsgBootloaderHandshakeDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.handshake.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.handshake.sbp_size();
        size
    }
}

/// Bootloading handshake request (host => device)
///
/// The handshake message request from the host establishes a
/// handshake between the device bootloader and the host. The
/// response from the device is MSG_BOOTLOADER_HANDSHAKE_RESP.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBootloaderHandshakeReq {
    pub sender_id: Option<u16>,
}

impl MsgBootloaderHandshakeReq {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBootloaderHandshakeReq, crate::Error> {
        Ok(MsgBootloaderHandshakeReq { sender_id: None })
    }
}
impl super::SBPMessage for MsgBootloaderHandshakeReq {
    fn get_message_type(&self) -> u16 {
        179
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

impl crate::serialize::SbpSerialize for MsgBootloaderHandshakeReq {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {}

    fn sbp_size(&self) -> usize {
        0
    }
}

/// Bootloading handshake response (host <= device)
///
/// The handshake message response from the device establishes a
/// handshake between the device bootloader and the host. The
/// request from the host is MSG_BOOTLOADER_HANDSHAKE_REQ.  The
/// payload contains the bootloader version number and the SBP
/// protocol version number.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBootloaderHandshakeResp {
    pub sender_id: Option<u16>,
    /// Bootloader flags
    pub flags: u32,
    /// Bootloader version number
    pub version: String,
}

impl MsgBootloaderHandshakeResp {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBootloaderHandshakeResp, crate::Error> {
        Ok(MsgBootloaderHandshakeResp {
            sender_id: None,
            flags: _buf.read_u32::<LittleEndian>()?,
            version: crate::parser::read_string(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgBootloaderHandshakeResp {
    fn get_message_type(&self) -> u16 {
        180
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

impl crate::serialize::SbpSerialize for MsgBootloaderHandshakeResp {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.flags.append_to_sbp_buffer(buf);
        self.version.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.flags.sbp_size();
        size += self.version.sbp_size();
        size
    }
}

/// Bootloader jump to application (host => device)
///
/// The host initiates the bootloader to jump to the application.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBootloaderJumpToApp {
    pub sender_id: Option<u16>,
    /// Ignored by the device
    pub jump: u8,
}

impl MsgBootloaderJumpToApp {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBootloaderJumpToApp, crate::Error> {
        Ok(MsgBootloaderJumpToApp {
            sender_id: None,
            jump: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgBootloaderJumpToApp {
    fn get_message_type(&self) -> u16 {
        177
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

impl crate::serialize::SbpSerialize for MsgBootloaderJumpToApp {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.jump.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.jump.sbp_size();
        size
    }
}

/// Read FPGA device ID over UART request (host => device)
///
/// The device message from the host reads a unique device
/// identifier from the SwiftNAP, an FPGA. The host requests the ID
/// by sending a MSG_NAP_DEVICE_DNA_REQ message. The device
/// responds with a MSG_NAP_DEVICE_DNA_RESP message with the
/// device ID in the payload. Note that this ID is tied to the FPGA,
/// and not related to the Piksi's serial number.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgNapDeviceDnaReq {
    pub sender_id: Option<u16>,
}

impl MsgNapDeviceDnaReq {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgNapDeviceDnaReq, crate::Error> {
        Ok(MsgNapDeviceDnaReq { sender_id: None })
    }
}
impl super::SBPMessage for MsgNapDeviceDnaReq {
    fn get_message_type(&self) -> u16 {
        222
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

impl crate::serialize::SbpSerialize for MsgNapDeviceDnaReq {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {}

    fn sbp_size(&self) -> usize {
        0
    }
}

/// Read FPGA device ID over UART response (host <= device)
///
/// The device message from the host reads a unique device
/// identifier from the SwiftNAP, an FPGA. The host requests the ID
/// by sending a MSG_NAP_DEVICE_DNA_REQ message. The device
/// responds with a MSG_NAP_DEVICE_DNA_RESP messagage with the
/// device ID in the payload. Note that this ID is tied to the FPGA,
/// and not related to the Piksi's serial number.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgNapDeviceDnaResp {
    pub sender_id: Option<u16>,
    /// 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the right.
    pub dna: Vec<u8>,
}

impl MsgNapDeviceDnaResp {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgNapDeviceDnaResp, crate::Error> {
        Ok(MsgNapDeviceDnaResp {
            sender_id: None,
            dna: crate::parser::read_u8_array_limit(_buf, 8)?,
        })
    }
}
impl super::SBPMessage for MsgNapDeviceDnaResp {
    fn get_message_type(&self) -> u16 {
        221
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

impl crate::serialize::SbpSerialize for MsgNapDeviceDnaResp {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.dna.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.dna.sbp_size();
        size
    }
}
