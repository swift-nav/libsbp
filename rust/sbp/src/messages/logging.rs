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

use super::lib::*;

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
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgFwd {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// source identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "source")))]
    pub source: u8,
    /// protocol identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "protocol")))]
    pub protocol: u8,
    /// variable length wrapped binary message
    #[cfg_attr(feature = "serde", serde(rename(serialize = "fwd_payload")))]
    pub fwd_payload: Vec<u8>,
}

impl ConcreteMessage for MsgFwd {
    const MESSAGE_TYPE: u16 = 1026;
    const MESSAGE_NAME: &'static str = "MSG_FWD";
}

impl SbpMessage for MsgFwd {
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

impl TryFrom<Sbp> for MsgFwd {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgFwd(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgFwd {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <Vec<u8> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.source)
            + WireFormat::len(&self.protocol)
            + WireFormat::len(&self.fwd_payload)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.source, buf);
        WireFormat::write(&self.protocol, buf);
        WireFormat::write(&self.fwd_payload, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgFwd {
            sender_id: None,
            source: WireFormat::parse_unchecked(buf),
            protocol: WireFormat::parse_unchecked(buf),
            fwd_payload: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Plaintext logging messages with levels
///
/// This message contains a human-readable payload string from the device
/// containing errors, warnings and informational messages at ERROR, WARNING,
/// DEBUG, INFO logging levels.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgLog {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Logging level
    #[cfg_attr(feature = "serde", serde(rename(serialize = "level")))]
    pub level: u8,
    /// Human-readable string
    #[cfg_attr(feature = "serde", serde(rename(serialize = "text")))]
    pub text: SbpString<Vec<u8>, Unterminated>,
}

impl ConcreteMessage for MsgLog {
    const MESSAGE_TYPE: u16 = 1025;
    const MESSAGE_NAME: &'static str = "MSG_LOG";
}

impl SbpMessage for MsgLog {
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

impl TryFrom<Sbp> for MsgLog {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgLog(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgLog {
    const MIN_LEN: usize =
        <u8 as WireFormat>::MIN_LEN + <SbpString<Vec<u8>, Unterminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.level) + WireFormat::len(&self.text)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.level, buf);
        WireFormat::write(&self.text, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgLog {
            sender_id: None,
            level: WireFormat::parse_unchecked(buf),
            text: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgPrintDep {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Human-readable string
    #[cfg_attr(feature = "serde", serde(rename(serialize = "text")))]
    pub text: SbpString<Vec<u8>, Unterminated>,
}

impl ConcreteMessage for MsgPrintDep {
    const MESSAGE_TYPE: u16 = 16;
    const MESSAGE_NAME: &'static str = "MSG_PRINT_DEP";
}

impl SbpMessage for MsgPrintDep {
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

impl TryFrom<Sbp> for MsgPrintDep {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgPrintDep(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgPrintDep {
    const MIN_LEN: usize = <SbpString<Vec<u8>, Unterminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.text)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.text, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgPrintDep {
            sender_id: None,
            text: WireFormat::parse_unchecked(buf),
        }
    }
}
