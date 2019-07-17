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
// Automatically generated from yaml/swiftnav/sbp/vehicle.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
// Messages from a vehicle.
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};

// Vehicle forward (x-axis) velocity
//
// Message representing the x component of vehicle velocity in the user frame at the odometry
// reference point(s) specified by the user. The offset for the odometry reference point and
// the definition and origin of the user frame are defined through the device settings interface.
// There are 4 possible user-defined sources of this message  which are labeled arbitrarily
// source 0 through 3.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgOdometry {
    pub sender_id: Option<u16>,
    pub tow: u32,
    // ^ Time field representing either milliseconds in the GPS Week or local CPU
    // time from the producing system in milliseconds.  See the tow_source flag
    // for the exact source of this timestamp.
    pub velocity: i32,
    // ^ The signed forward component of vehicle velocity.
    pub flags: u8,
    // ^ Status flags
}

impl MsgOdometry {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgOdometry, ::parser::MessageError> {
        Ok(MsgOdometry {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            velocity: _buf.read_i32::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgOdometry {
    const MSG_ID: u16 = 2307;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}
