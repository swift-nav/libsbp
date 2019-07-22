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
// Automatically generated from yaml/swiftnav/sbp/logging.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
/// Logging and debugging messages from the device.
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};

/// Plaintext logging messages with levels
///
/// This message contains a human-readable payload string from the
/// device containing errors, warnings and informational messages at
/// ERROR, WARNING, DEBUG, INFO logging levels.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgLog {
    pub sender_id: Option<u16>,
    /// Logging level
    pub level: u8,
    /// Human-readable string
    pub text: String,
}

impl MsgLog {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgLog, ::parser::MessageError> {
        Ok(MsgLog {
            sender_id: None,
            level: _buf.read_u8()?,
            text: ::parser::read_string(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgLog {
    const MSG_ID: u16 = 1025;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Wrapper for FWD a separate stream of information over SBP
///
/// This message provides the ability to forward messages over SBP.  This may take the form
/// of wrapping up SBP messages received by Piksi for logging purposes or wrapping
/// another protocol with SBP.
///
/// The source identifier indicates from what interface a forwarded stream derived.
/// The protocol identifier identifies what the expected protocol the forwarded msg contains.
/// Protocol 0 represents SBP and the remaining values are implementation defined.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgFwd {
    pub sender_id: Option<u16>,
    /// source identifier
    pub source: u8,
    /// protocol identifier
    pub protocol: u8,
    /// variable length wrapped binary message
    pub fwd_payload: String,
}

impl MsgFwd {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFwd, ::parser::MessageError> {
        Ok(MsgFwd {
            sender_id: None,
            source: _buf.read_u8()?,
            protocol: _buf.read_u8()?,
            fwd_payload: ::parser::read_string(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgFwd {
    const MSG_ID: u16 = 1026;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Deprecated
///
/// Deprecated.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgPrintDep {
    pub sender_id: Option<u16>,
    /// Human-readable string
    pub text: String,
}

impl MsgPrintDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPrintDep, ::parser::MessageError> {
        Ok(MsgPrintDep {
            sender_id: None,
            text: ::parser::read_string(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgPrintDep {
    const MSG_ID: u16 = 16;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}
