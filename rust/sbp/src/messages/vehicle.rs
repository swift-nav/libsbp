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
//! Messages from a vehicle.

extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
#[cfg(feature = "serialize")]
use serde::{Deserialize, Serialize};

/// Vehicle forward (x-axis) velocity
///
/// Message representing the x component of vehicle velocity in the user frame at the odometry
/// reference point(s) specified by the user. The offset for the odometry reference point and
/// the definition and origin of the user frame are defined through the device settings interface.
/// There are 4 possible user-defined sources of this message  which are labeled arbitrarily
/// source 0 through 3.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgOdometry {
    pub sender_id: Option<u16>,
    /// Time field representing either milliseconds in the GPS Week or local CPU
    /// time from the producing system in milliseconds.  See the tow_source flag
    /// for the exact source of this timestamp.
    pub tow: u32,
    /// The signed forward component of vehicle velocity.
    pub velocity: i32,
    /// Status flags
    pub flags: u8,
}

impl MsgOdometry {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgOdometry, crate::Error> {
        Ok(MsgOdometry {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            velocity: _buf.read_i32::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgOdometry {
    fn get_message_type(&self) -> u16 {
        2307
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

impl crate::serialize::SbpSerialize for MsgOdometry {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.velocity.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.velocity.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}
