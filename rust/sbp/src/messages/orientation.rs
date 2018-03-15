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

// Orientation Messages
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian,ReadBytesExt};


// Heading relative to True North
//
// This message reports the baseline heading pointing from the base station
// to the rover relative to True North. The full GPS time is given by the
// preceding MSG_GPS_TIME with the matching time-of-week (tow). It is intended
// that time-matched RTK mode is used when the base station is moving.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBaselineHeading {
    pub tow: u32,
        // ^ GPS Time of Week
    pub heading: u32,
        // ^ Heading
    pub n_sats: u8,
        // ^ Number of satellites used in solution
    pub flags: u8,
        // ^ Status flags
}

impl MsgBaselineHeading {
    pub const TYPE: u16 = 527;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBaselineHeading, ::Error> {
        Ok( MsgBaselineHeading{
            tow: _buf.read_u32::<LittleEndian>()?,
            heading: _buf.read_u32::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
}


// Quaternion 4 component vector
//
// This message reports the quaternion vector describing the vehicle body frame's orientation
// with respect to a local-level NED frame. The components of the vector should sum to a unit
// vector assuming that the LSB of each component as a value of 2^-31. 
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgOrientQuat {
    pub tow: u32,
        // ^ GPS Time of Week
    pub w: i32,
        // ^ Real component
    pub x: i32,
        // ^ 1st imaginary component
    pub y: i32,
        // ^ 2nd imaginary component
    pub z: i32,
        // ^ 3rd imaginary component
    pub acc_w: f32,
        // ^ Estimated standard deviation of w
    pub acc_x: f32,
        // ^ Estimated standard deviation of x
    pub acc_y: f32,
        // ^ Estimated standard deviation of y
    pub acc_z: f32,
        // ^ Estimated standard deviation of z
    pub flags: u8,
        // ^ Status flags
}

impl MsgOrientQuat {
    pub const TYPE: u16 = 544;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgOrientQuat, ::Error> {
        Ok( MsgOrientQuat{
            tow: _buf.read_u32::<LittleEndian>()?,
            w: _buf.read_i32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            acc_w: _buf.read_f32::<LittleEndian>()?,
            acc_x: _buf.read_f32::<LittleEndian>()?,
            acc_y: _buf.read_f32::<LittleEndian>()?,
            acc_z: _buf.read_f32::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        } )
    }
}


// Euler angles
//
// This message reports the yaw, pitch, and roll angles of the vehicle body frame.
// The rotations should applied intrinsically in the order yaw, pitch, and roll 
// in order to rotate the from a frame aligned with the local-level NED frame 
// to the vehicle body frame.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgOrientEuler {
    pub tow: u32,
        // ^ GPS Time of Week
    pub roll: i32,
        // ^ rotation about the forward axis of the vehicle
    pub pitch: i32,
        // ^ rotation about the rightward axis of the vehicle
    pub yaw: i32,
        // ^ rotation about the downward axis of the vehicle
    pub var_roll: f32,
        // ^ Estimated standard deviation of roll
    pub var_pitch: f32,
        // ^ Estimated standard deviation of pitch
    pub var_yaw: f32,
        // ^ Estimated standard deviation of yaw
    pub flags: u8,
        // ^ Status flags
}

impl MsgOrientEuler {
    pub const TYPE: u16 = 545;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgOrientEuler, ::Error> {
        Ok( MsgOrientEuler{
            tow: _buf.read_u32::<LittleEndian>()?,
            roll: _buf.read_i32::<LittleEndian>()?,
            pitch: _buf.read_i32::<LittleEndian>()?,
            yaw: _buf.read_i32::<LittleEndian>()?,
            var_roll: _buf.read_f32::<LittleEndian>()?,
            var_pitch: _buf.read_f32::<LittleEndian>()?,
            var_yaw: _buf.read_f32::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        } )
    }
}


// Vehicle Body Frame instantaneous angular rates
//
// This message reports the orientation rates in the vehicle body frame. 
// The values represent the measurements a strapped down gyroscope would 
// make and are not equivalent to the time derivative of the Euler angles.
// The orientation and origin of the user frame is specified via device settings.
// By convention, the vehicle x-axis is expected to be aligned with the forward
// direction, while the vehicle y-axis is expected to be aligned with the right
// direction, and the vehicle z-axis should be aligned with the down direction.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgAngularRate {
    pub tow: u32,
        // ^ GPS Time of Week
    pub x: i32,
        // ^ angular rate about x axis
    pub y: i32,
        // ^ angular rate about y axis
    pub z: i32,
        // ^ angular rate about z axis
    pub flags: u8,
        // ^ Status flags
}

impl MsgAngularRate {
    pub const TYPE: u16 = 546;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAngularRate, ::Error> {
        Ok( MsgAngularRate{
            tow: _buf.read_u32::<LittleEndian>()?,
            x: _buf.read_i32::<LittleEndian>()?,
            y: _buf.read_i32::<LittleEndian>()?,
            z: _buf.read_i32::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        } )
    }
}

