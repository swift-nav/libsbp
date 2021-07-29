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
// Automatically generated from yaml/swiftnav/sbp/logging.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Logging and debugging messages from the device.

#[allow(unused_imports)]
use std::convert::TryFrom;

#[allow(unused_imports)]
use byteorder::{LittleEndian, ReadBytesExt};

#[allow(unused_imports)]
use crate::serialize::SbpSerialize;
#[allow(unused_imports)]
use crate::SbpString;

/// Wrapper for FWD a separate stream of information over SBP
///
/// This message provides the ability to forward messages over SBP.  This may
/// take the form of wrapping up SBP messages received by Piksi for logging
/// purposes or wrapping another protocol with SBP.
///
/// The source identifier indicates from what interface a forwarded stream
/// derived. The protocol identifier identifies what the expected protocol the
/// forwarded msg contains. Protocol 0 represents SBP and the remaining values
/// are implementation defined.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgFwd {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// source identifier
    pub source: u8,
    /// protocol identifier
    pub protocol: u8,
    /// variable length wrapped binary message
    pub fwd_payload: Vec<u8>,
}

impl MsgFwd {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFwd, crate::Error> {
        Ok( MsgFwd{
            sender_id: None,
            source: _buf.read_u8()?,
            protocol: _buf.read_u8()?,
            fwd_payload: crate::parser::read_u8_array(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgFwd {
    fn get_message_name(&self) -> &'static str {
        "MSG_FWD"
    }

    fn get_message_type(&self) -> u16 {
        1026
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgFwd {
    const MESSAGE_TYPE: u16 = 1026;
    const MESSAGE_NAME: &'static str = "MSG_FWD";
}
impl TryFrom<super::SBP> for MsgFwd {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgFwd(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgFwd {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.source.append_to_sbp_buffer(buf);
        self.protocol.append_to_sbp_buffer(buf);
        self.fwd_payload.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.source.sbp_size();
        size += self.protocol.sbp_size();
        size += self.fwd_payload.sbp_size();
        size
    }
}

/// Plaintext logging messages with levels
///
/// This message contains a human-readable payload string from the device
/// containing errors, warnings and informational messages at ERROR, WARNING,
/// DEBUG, INFO logging levels.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgLog {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Logging level
    pub level: u8,
    /// Human-readable string
    pub text: SbpString,
}

impl MsgLog {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgLog, crate::Error> {
        Ok( MsgLog{
            sender_id: None,
            level: _buf.read_u8()?,
            text: crate::parser::read_string(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgLog {
    fn get_message_name(&self) -> &'static str {
        "MSG_LOG"
    }

    fn get_message_type(&self) -> u16 {
        1025
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgLog {
    const MESSAGE_TYPE: u16 = 1025;
    const MESSAGE_NAME: &'static str = "MSG_LOG";
}
impl TryFrom<super::SBP> for MsgLog {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgLog(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgLog {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.level.append_to_sbp_buffer(buf);
        self.text.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.level.sbp_size();
        size += self.text.sbp_size();
        size
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPrintDep {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Human-readable string
    pub text: SbpString,
}

impl MsgPrintDep {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPrintDep, crate::Error> {
        Ok( MsgPrintDep{
            sender_id: None,
            text: crate::parser::read_string(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgPrintDep {
    fn get_message_name(&self) -> &'static str {
        "MSG_PRINT_DEP"
    }

    fn get_message_type(&self) -> u16 {
        16
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgPrintDep {
    const MESSAGE_TYPE: u16 = 16;
    const MESSAGE_NAME: &'static str = "MSG_PRINT_DEP";
}
impl TryFrom<super::SBP> for MsgPrintDep {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgPrintDep(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgPrintDep {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.text.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.text.sbp_size();
        size
    }
}
