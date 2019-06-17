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
// Messages for the bootloading configuration of a Piksi 2.3.1.  This message
// group does not apply to Piksi Multi.
//
// Note that some of these messages share the same message type ID for both the
// host request and the device response.
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};

// Bootloading handshake request (host => device)
//
// The handshake message request from the host establishes a
// handshake between the device bootloader and the host. The
// response from the device is MSG_BOOTLOADER_HANDSHAKE_RESP.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBootloaderHandshakeReq {}

impl MsgBootloaderHandshakeReq {
    pub const TYPE: u16 = 179;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBootloaderHandshakeReq, ::parser::MessageError> {
        Ok(MsgBootloaderHandshakeReq {})
    }
}

// Bootloading handshake response (host <= device)
//
// The handshake message response from the device establishes a
// handshake between the device bootloader and the host. The
// request from the host is MSG_BOOTLOADER_HANDSHAKE_REQ.  The
// payload contains the bootloader version number and the SBP
// protocol version number.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBootloaderHandshakeResp {
    pub flags: u32,
    // ^ Bootloader flags
    pub version: String,
    // ^ Bootloader version number
}

impl MsgBootloaderHandshakeResp {
    pub const TYPE: u16 = 180;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBootloaderHandshakeResp, ::parser::MessageError> {
        Ok(MsgBootloaderHandshakeResp {
            flags: _buf.read_u32::<LittleEndian>()?,
            version: ::parser::read_string(_buf)?,
        })
    }
}

// Bootloader jump to application (host => device)
//
// The host initiates the bootloader to jump to the application.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBootloaderJumpToApp {
    pub jump: u8,
    // ^ Ignored by the device
}

impl MsgBootloaderJumpToApp {
    pub const TYPE: u16 = 177;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBootloaderJumpToApp, ::parser::MessageError> {
        Ok(MsgBootloaderJumpToApp {
            jump: _buf.read_u8()?,
        })
    }
}

// Read FPGA device ID over UART request (host => device)
//
// The device message from the host reads a unique device
// identifier from the SwiftNAP, an FPGA. The host requests the ID
// by sending a MSG_NAP_DEVICE_DNA_REQ message. The device
// responds with a MSG_NAP_DEVICE_DNA_RESP message with the
// device ID in the payload. Note that this ID is tied to the FPGA,
// and not related to the Piksi's serial number.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgNapDeviceDnaReq {}

impl MsgNapDeviceDnaReq {
    pub const TYPE: u16 = 222;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgNapDeviceDnaReq, ::parser::MessageError> {
        Ok(MsgNapDeviceDnaReq {})
    }
}

// Read FPGA device ID over UART response (host <= device)
//
// The device message from the host reads a unique device
// identifier from the SwiftNAP, an FPGA. The host requests the ID
// by sending a MSG_NAP_DEVICE_DNA_REQ message. The device
// responds with a MSG_NAP_DEVICE_DNA_RESP messagage with the
// device ID in the payload. Note that this ID is tied to the FPGA,
// and not related to the Piksi's serial number.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgNapDeviceDnaResp {
    pub dna: Vec<u8>,
    // ^ 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the right.
}

impl MsgNapDeviceDnaResp {
    pub const TYPE: u16 = 221;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgNapDeviceDnaResp, ::parser::MessageError> {
        Ok(MsgNapDeviceDnaResp {
            dna: ::parser::read_u8_array_limit(_buf, 8)?,
        })
    }
}

// Deprecated
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBootloaderHandshakeDepA {
    pub handshake: Vec<u8>,
    // ^ Version number string (not NULL terminated)
}

impl MsgBootloaderHandshakeDepA {
    pub const TYPE: u16 = 176;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBootloaderHandshakeDepA, ::parser::MessageError> {
        Ok(MsgBootloaderHandshakeDepA {
            handshake: ::parser::read_u8_array(_buf)?,
        })
    }
}
