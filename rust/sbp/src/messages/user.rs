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
// Automatically generated from yaml/swiftnav/sbp/user.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages reserved for use by the user.
//!

extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
#[cfg(feature = "serialize")]
use serde::{Deserialize, Serialize};

/// User data
///
/// This message can contain any application specific user data up to a
/// maximum length of 255 bytes per message.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgUserData {
    pub sender_id: Option<u16>,
    /// User data payload
    pub contents: Vec<u8>,
}

impl MsgUserData {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgUserData, crate::Error> {
        Ok(MsgUserData {
            sender_id: None,
            contents: crate::parser::read_u8_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgUserData {
    fn get_message_type(&self) -> u16 {
        2048
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
