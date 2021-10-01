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
// Automatically generated from yaml/swiftnav/sbp/user.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages reserved for use by the user.

use super::lib::*;

/// User data
///
/// This message can contain any application specific user data up to a
/// maximum length of 255 bytes per message.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgUserData {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// User data payload
    #[cfg_attr(feature = "serde", serde(rename(serialize = "contents")))]
    pub contents: Vec<u8>,
}

impl ConcreteMessage for MsgUserData {
    const MESSAGE_TYPE: u16 = 2048;
    const MESSAGE_NAME: &'static str = "MSG_USER_DATA";
}

impl SbpMessage for MsgUserData {
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

impl TryFrom<Sbp> for MsgUserData {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgUserData(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgUserData {
    const MIN_LEN: usize = <Vec<u8> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.contents)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.contents, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgUserData {
            sender_id: None,
            contents: WireFormat::parse_unchecked(buf),
        }
    }
}
