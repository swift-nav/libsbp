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
// Automatically generated from yaml/swiftnav/sbp/orientation.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Orientation Messages

extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
#[cfg(feature = "serialize")]
use serde::{Deserialize, Serialize};

/// Vehicle Body Frame instantaneous angular rates
///
/// This message reports the orientation rates in the vehicle body frame.
/// The values represent the measurements a strapped down gyroscope would
/// make and are not equivalent to the time derivative of the Euler angles.
/// The orientation and origin of the user frame is specified via device settings.
/// By convention, the vehicle x-axis is expected to be aligned with the forward
/// direction, while the vehicle y-axis is expected to be aligned with the right
/// direction, and the vehicle z-axis should be aligned with the down direction.
/// This message will only be available in future INS versions of Swift Products
/// and is not produced by Piksi Multi or Duro.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgAngularRate {
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// angular rate about x axis
    pub x: i32,
    /// angular rate about y axis
    pub y: i32,
    /// angular rate about z axis
    pub z: i32,
    /// Status flags
    pub flags: u8,
}

impl MsgAngularRate {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAngularRate, crate::Error> {
        Ok(MsgAngularRate {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgAngularRate {
    fn get_message_type(&self) -> u16 {
        546
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

impl crate::serialize::SbpSerialize for MsgAngularRate {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.x.append_to_sbp_buffer(buf);
        self.y.append_to_sbp_buffer(buf);
        self.z.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.x.sbp_size();
        size += self.y.sbp_size();
        size += self.z.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Heading relative to True North
///
/// This message reports the baseline heading pointing from the base station
/// to the rover relative to True North. The full GPS time is given by the
/// preceding MSG_GPS_TIME with the matching time-of-week (tow). It is intended
/// that time-matched RTK mode is used when the base station is moving.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBaselineHeading {
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Heading
    pub heading: u32,
    /// Number of satellites used in solution
    pub n_sats: u8,
    /// Status flags
    pub flags: u8,
}

impl MsgBaselineHeading {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBaselineHeading, crate::Error> {
        Ok(MsgBaselineHeading {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            heading: _buf.read_u32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgBaselineHeading {
    fn get_message_type(&self) -> u16 {
        527
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

impl crate::serialize::SbpSerialize for MsgBaselineHeading {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.heading.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.heading.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Euler angles
///
/// This message reports the yaw, pitch, and roll angles of the vehicle body frame.
/// The rotations should applied intrinsically in the order yaw, pitch, and roll
/// in order to rotate the from a frame aligned with the local-level NED frame
/// to the vehicle body frame.  This message will only be available in future
/// INS versions of Swift Products and is not produced by Piksi Multi or Duro.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgOrientEuler {
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// rotation about the forward axis of the vehicle
    pub roll: i32,
    /// rotation about the rightward axis of the vehicle
    pub pitch: i32,
    /// rotation about the downward axis of the vehicle
    pub yaw: i32,
    /// Estimated standard deviation of roll
    pub roll_accuracy: f32,
    /// Estimated standard deviation of pitch
    pub pitch_accuracy: f32,
    /// Estimated standard deviation of yaw
    pub yaw_accuracy: f32,
    /// Status flags
    pub flags: u8,
}

impl MsgOrientEuler {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgOrientEuler, crate::Error> {
        Ok(MsgOrientEuler {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            roll: _buf.read_i32::<LittleEndian>()?,
            pitch: _buf.read_i32::<LittleEndian>()?,
            yaw: _buf.read_i32::<LittleEndian>()?,
            roll_accuracy: _buf.read_f32::<LittleEndian>()?,
            pitch_accuracy: _buf.read_f32::<LittleEndian>()?,
            yaw_accuracy: _buf.read_f32::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgOrientEuler {
    fn get_message_type(&self) -> u16 {
        545
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

impl crate::serialize::SbpSerialize for MsgOrientEuler {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.roll.append_to_sbp_buffer(buf);
        self.pitch.append_to_sbp_buffer(buf);
        self.yaw.append_to_sbp_buffer(buf);
        self.roll_accuracy.append_to_sbp_buffer(buf);
        self.pitch_accuracy.append_to_sbp_buffer(buf);
        self.yaw_accuracy.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.roll.sbp_size();
        size += self.pitch.sbp_size();
        size += self.yaw.sbp_size();
        size += self.roll_accuracy.sbp_size();
        size += self.pitch_accuracy.sbp_size();
        size += self.yaw_accuracy.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Quaternion 4 component vector
///
/// This message reports the quaternion vector describing the vehicle body frame's orientation
/// with respect to a local-level NED frame. The components of the vector should sum to a unit
/// vector assuming that the LSB of each component as a value of 2^-31. This message will only
/// be available in future INS versions of Swift Products and is not produced by Piksi Multi
/// or Duro.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgOrientQuat {
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// Real component
    pub w: i32,
    /// 1st imaginary component
    pub x: i32,
    /// 2nd imaginary component
    pub y: i32,
    /// 3rd imaginary component
    pub z: i32,
    /// Estimated standard deviation of w
    pub w_accuracy: f32,
    /// Estimated standard deviation of x
    pub x_accuracy: f32,
    /// Estimated standard deviation of y
    pub y_accuracy: f32,
    /// Estimated standard deviation of z
    pub z_accuracy: f32,
    /// Status flags
    pub flags: u8,
}

impl MsgOrientQuat {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgOrientQuat, crate::Error> {
        Ok(MsgOrientQuat {
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            w: _buf.read_i32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            w_accuracy: _buf.read_f32::<LittleEndian>()?,
            x_accuracy: _buf.read_f32::<LittleEndian>()?,
            y_accuracy: _buf.read_f32::<LittleEndian>()?,
            z_accuracy: _buf.read_f32::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgOrientQuat {
    fn get_message_type(&self) -> u16 {
        544
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

impl crate::serialize::SbpSerialize for MsgOrientQuat {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.w.append_to_sbp_buffer(buf);
        self.x.append_to_sbp_buffer(buf);
        self.y.append_to_sbp_buffer(buf);
        self.z.append_to_sbp_buffer(buf);
        self.w_accuracy.append_to_sbp_buffer(buf);
        self.x_accuracy.append_to_sbp_buffer(buf);
        self.y_accuracy.append_to_sbp_buffer(buf);
        self.z_accuracy.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.w.sbp_size();
        size += self.x.sbp_size();
        size += self.y.sbp_size();
        size += self.z.sbp_size();
        size += self.w_accuracy.sbp_size();
        size += self.x_accuracy.sbp_size();
        size += self.y_accuracy.sbp_size();
        size += self.z_accuracy.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}
