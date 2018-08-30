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
// Automatically generated from yaml/swiftnav/sbp/ssr.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/

// Precise State Space Representation (SSR) corrections format
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian,ReadBytesExt};
use super::gnss::*;


// SSR code biases corrections for a particular satellite.
//
// Code biases are to be added to pseudorange.
// The corrections are conform with typical RTCMv3 MT1059 and 1065.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct CodeBiasesContent {
    pub code: u8,
        // ^ Signal constellation, band and code
    pub value: i16,
        // ^ Code bias value
}

impl CodeBiasesContent {
    pub fn parse(_buf: &mut &[u8]) -> Result<CodeBiasesContent, ::Error> {
        Ok( CodeBiasesContent{
            code: _buf.read_u8()?,
            value: _buf.read_i16::<LittleEndian>()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<CodeBiasesContent>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( CodeBiasesContent::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<CodeBiasesContent>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( CodeBiasesContent::parse(buf)? );
        }
        Ok(v)
    }
}


// SSR phase biases corrections for a particular satellite.
//
// Phase biases are to be added to carrier phase measurements.
// The corrections are conform with typical RTCMv3 MT1059 and 1065.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct PhaseBiasesContent {
    pub code: u8,
        // ^ Signal constellation, band and code
    pub integer_indicator: u8,
        // ^ Indicator for integer property
    pub widelane_integer_indicator: u8,
        // ^ Indicator for two groups of Wide-Lane(s) integer property
    pub discontinuity_counter: u8,
        // ^ Signal phase discontinuity counter.  Increased for every discontinuity
        // in phase.
    pub bias: i32,
        // ^ Phase bias for specified signal
}

impl PhaseBiasesContent {
    pub fn parse(_buf: &mut &[u8]) -> Result<PhaseBiasesContent, ::Error> {
        Ok( PhaseBiasesContent{
            code: _buf.read_u8()?,
            integer_indicator: _buf.read_u8()?,
            widelane_integer_indicator: _buf.read_u8()?,
            discontinuity_counter: _buf.read_u8()?,
            bias: _buf.read_i32::<LittleEndian>()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<PhaseBiasesContent>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( PhaseBiasesContent::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<PhaseBiasesContent>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( PhaseBiasesContent::parse(buf)? );
        }
        Ok(v)
    }
}


// Precise orbit and clock correction
//
// The precise orbit and clock correction message is 
// to be applied as a delta correction to broadcast 
// ephemeris and is typically an equivalent to the 1060
// and 1066 RTCM message types
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSsrOrbitClock {
    pub time: GPSTimeSec,
        // ^ GNSS reference time of the correction
    pub sid: GnssSignal,
        // ^ GNSS signal identifier (16 bit)
    pub update_interval: u8,
        // ^ Update interval between consecutive corrections
    pub iod_ssr: u8,
        // ^ IOD of the SSR correction. A change of Issue Of Data SSR is used to
        // indicate a change in the SSR  generating configuration
    pub iod: u8,
        // ^ Issue of broadcast ephemeris data
    pub radial: i32,
        // ^ Orbit radial delta correction
    pub along: i32,
        // ^ Orbit along delta correction
    pub cross: i32,
        // ^ Orbit along delta correction
    pub dot_radial: i32,
        // ^ Velocity of orbit radial delta correction
    pub dot_along: i32,
        // ^ Velocity of orbit along delta correction
    pub dot_cross: i32,
        // ^ Velocity of orbit cross delta correction
    pub c0: i32,
        // ^ C0 polynomial coefficient for correction of broadcast satellite clock
    pub c1: i32,
        // ^ C1 polynomial coefficient for correction of broadcast satellite clock
    pub c2: i32,
        // ^ C2 polynomial coefficient for correction of broadcast satellite clock
}

impl MsgSsrOrbitClock {
    pub const TYPE: u16 = 1500;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrOrbitClock, ::Error> {
        Ok( MsgSsrOrbitClock{
            time: GPSTimeSec::parse(_buf)?,
            sid: GnssSignal::parse(_buf)?,
            update_interval: _buf.read_u8()?,
            iod_ssr: _buf.read_u8()?,
            iod: _buf.read_u8()?,
            radial: _buf.read_i32::<LittleEndian>()?,
            along: _buf.read_i32::<LittleEndian>()?,
            cross: _buf.read_i32::<LittleEndian>()?,
            dot_radial: _buf.read_i32::<LittleEndian>()?,
            dot_along: _buf.read_i32::<LittleEndian>()?,
            dot_cross: _buf.read_i32::<LittleEndian>()?,
            c0: _buf.read_i32::<LittleEndian>()?,
            c1: _buf.read_i32::<LittleEndian>()?,
            c2: _buf.read_i32::<LittleEndian>()?,
        } )
    }
}


// Precise code biases correction
//
// The precise code biases message is to be added
// to the pseudorange of the corresponding signal
// to get corrected pseudorange. It is typically 
// an equivalent to the 1059 and 1065 RTCM message types
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSsrCodeBiases {
    pub time: GPSTimeSec,
        // ^ GNSS reference time of the correction
    pub sid: GnssSignal,
        // ^ GNSS signal identifier (16 bit)
    pub update_interval: u8,
        // ^ Update interval between consecutive corrections
    pub iod_ssr: u8,
        // ^ IOD of the SSR correction. A change of Issue Of Data SSR is used to
        // indicate a change in the SSR  generating configuration
    pub biases: Vec<CodeBiasesContent>,
        // ^ Code biases for the different satellite signals
}

impl MsgSsrCodeBiases {
    pub const TYPE: u16 = 1505;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrCodeBiases, ::Error> {
        Ok( MsgSsrCodeBiases{
            time: GPSTimeSec::parse(_buf)?,
            sid: GnssSignal::parse(_buf)?,
            update_interval: _buf.read_u8()?,
            iod_ssr: _buf.read_u8()?,
            biases: CodeBiasesContent::parse_array(_buf)?,
        } )
    }
}


// Precise phase biases correction
//
// The precise phase biases message contains the biases
// to be added to the carrier phase of the corresponding
// signal to get corrected carrier phase measurement, as 
// well as the satellite yaw angle to be applied to compute 
// the phase wind-up correction. 
// It is typically an equivalent to the 1265 RTCM message types
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSsrPhaseBiases {
    pub time: GPSTimeSec,
        // ^ GNSS reference time of the correction
    pub sid: GnssSignal,
        // ^ GNSS signal identifier (16 bit)
    pub update_interval: u8,
        // ^ Update interval between consecutive corrections
    pub iod_ssr: u8,
        // ^ IOD of the SSR correction. A change of Issue Of Data SSR is used to
        // indicate a change in the SSR  generating configuration
    pub dispersive_bias: u8,
        // ^ Indicator for the dispersive phase biases property.
    pub mw_consistency: u8,
        // ^ Consistency indicator for Melbourne-Wubbena linear combinations
    pub yaw: u16,
        // ^ Satellite yaw angle
    pub yaw_rate: i8,
        // ^ Satellite yaw angle rate
    pub biases: Vec<PhaseBiasesContent>,
        // ^ Phase biases corrections for a satellite being tracked.
}

impl MsgSsrPhaseBiases {
    pub const TYPE: u16 = 1510;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrPhaseBiases, ::Error> {
        Ok( MsgSsrPhaseBiases{
            time: GPSTimeSec::parse(_buf)?,
            sid: GnssSignal::parse(_buf)?,
            update_interval: _buf.read_u8()?,
            iod_ssr: _buf.read_u8()?,
            dispersive_bias: _buf.read_u8()?,
            mw_consistency: _buf.read_u8()?,
            yaw: _buf.read_u16::<LittleEndian>()?,
            yaw_rate: _buf.read_i8()?,
            biases: PhaseBiasesContent::parse_array(_buf)?,
        } )
    }
}

