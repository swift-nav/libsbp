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

#[allow(unused_imports)]
use std::convert::TryFrom;

#[allow(unused_imports)]
use byteorder::{LittleEndian, ReadBytesExt};

#[allow(unused_imports)]
use crate::{messages::ConcreteMessage, serialize::SbpSerialize, SbpString};

/// User data
///
/// This message can contain any application specific user data up to a
/// maximum length of 255 bytes per message.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgUserData {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// User data payload
    pub contents: Vec<u8>,
}

impl MsgUserData {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgUserData, crate::Error> {
        Ok( MsgUserData{
            sender_id: None,
            contents: crate::parser::read_u8_array(_buf)?,
        } )
    }
}
impl super::SbpMessage for MsgUserData {
    fn message_name(&self) -> &'static str {
        Self::MESSAGE_NAME
    }

    fn message_type(&self) -> u16 {
        Self::MESSAGE_TYPE
    }

    fn sender_id(&self) -> Option<u16> {
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
impl super::ConcreteMessage for MsgUserData {
    const MESSAGE_TYPE: u16 = 2048;
    const MESSAGE_NAME: &'static str = "MSG_USER_DATA";
}
impl TryFrom<super::Sbp> for MsgUserData {
    type Error = super::TryFromSbpError;

    fn try_from(msg: super::Sbp) -> Result<Self, Self::Error> {
        match msg {
            super::Sbp::MsgUserData(m) => Ok(m),
            _ => Err(super::TryFromSbpError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgUserData {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.contents.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.contents.sbp_size();
        size
    }
}
