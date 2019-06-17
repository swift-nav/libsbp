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
// Messages reserved for use by the user.
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};

// User data
//
// This message can contain any application specific user data up to a
// maximum length of 255 bytes per message.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgUserData {
    pub contents: Vec<u8>,
    // ^ User data payload
}

impl MsgUserData {
    pub const TYPE: u16 = 2048;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgUserData, ::parser::MessageError> {
        Ok(MsgUserData {
            contents: ::parser::read_u8_array(_buf)?,
        })
    }
}
