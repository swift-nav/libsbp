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
// Automatically generated from yaml/swiftnav/sbp/gnss.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/

// Various structs shared between modules
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian,ReadBytesExt};


// Represents all the relevant information about the signal
//
// Signal identifier containing constellation, band, and satellite identifier
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct GnssSignal {
    pub sat: u8,
        // ^ Constellation-specific satellite identifier
    pub code: u8,
        // ^ Signal constellation, band and code
}

impl GnssSignal {
    pub fn parse(_buf: &mut &[u8]) -> Result<GnssSignal, ::Error> {
        Ok( GnssSignal{
            sat: _buf.read_u8()?,
            code: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GnssSignal>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( GnssSignal::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<GnssSignal>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( GnssSignal::parse(buf)? );
        }
        Ok(v)
    }
}


// Deprecated
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct GnssSignalDep {
    pub sat: u16,
        // ^ Constellation-specific satellite identifier.  Note: unlike GnssSignal,
        // GPS satellites are encoded as (PRN - 1). Other constellations do not
        // have this offset.
    pub code: u8,
        // ^ Signal constellation, band and code
    pub reserved: u8,
        // ^ Reserved
}

impl GnssSignalDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<GnssSignalDep, ::Error> {
        Ok( GnssSignalDep{
            sat: _buf.read_u16::<LittleEndian>()?,
            code: _buf.read_u8()?,
            reserved: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GnssSignalDep>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( GnssSignalDep::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<GnssSignalDep>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( GnssSignalDep::parse(buf)? );
        }
        Ok(v)
    }
}


// Millisecond-accurate GPS time
//
// A wire-appropriate GPS time, defined as the number of
// milliseconds since beginning of the week on the Saturday/Sunday
// transition.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct GPSTimeDep {
    pub tow: u32,
        // ^ Milliseconds since start of GPS week
    pub wn: u16,
        // ^ GPS week number
}

impl GPSTimeDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<GPSTimeDep, ::Error> {
        Ok( GPSTimeDep{
            tow: _buf.read_u32::<LittleEndian>()?,
            wn: _buf.read_u16::<LittleEndian>()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GPSTimeDep>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( GPSTimeDep::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<GPSTimeDep>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( GPSTimeDep::parse(buf)? );
        }
        Ok(v)
    }
}


// Whole second accurate GPS time
//
// A GPS time, defined as the number of
// seconds since beginning of the week on the Saturday/Sunday
// transition.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct GPSTimeSec {
    pub tow: u32,
        // ^ Seconds since start of GPS week
    pub wn: u16,
        // ^ GPS week number
}

impl GPSTimeSec {
    pub fn parse(_buf: &mut &[u8]) -> Result<GPSTimeSec, ::Error> {
        Ok( GPSTimeSec{
            tow: _buf.read_u32::<LittleEndian>()?,
            wn: _buf.read_u16::<LittleEndian>()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GPSTimeSec>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( GPSTimeSec::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<GPSTimeSec>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( GPSTimeSec::parse(buf)? );
        }
        Ok(v)
    }
}


// Nanosecond-accurate receiver clock time
//
// A wire-appropriate receiver clock time, defined as the time
// since the beginning of the week on the Saturday/Sunday
// transition. In most cases, observations are epoch aligned
// so ns field will be 0.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct GPSTime {
    pub tow: u32,
        // ^ Milliseconds since start of GPS week
    pub ns_residual: i32,
        // ^ Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
        // 500000)
    pub wn: u16,
        // ^ GPS week number
}

impl GPSTime {
    pub fn parse(_buf: &mut &[u8]) -> Result<GPSTime, ::Error> {
        Ok( GPSTime{
            tow: _buf.read_u32::<LittleEndian>()?,
            ns_residual: _buf.read_i32::<LittleEndian>()?,
            wn: _buf.read_u16::<LittleEndian>()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GPSTime>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( GPSTime::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<GPSTime>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( GPSTime::parse(buf)? );
        }
        Ok(v)
    }
}


// GNSS carrier phase measurement.
//
// Carrier phase measurement in cycles represented as a 40-bit
// fixed point number with Q32.8 layout, i.e. 32-bits of whole
// cycles and 8-bits of fractional cycles. This phase has the
// same sign as the pseudorange.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct CarrierPhase {
    pub i: i32,
        // ^ Carrier phase whole cycles
    pub f: u8,
        // ^ Carrier phase fractional part
}

impl CarrierPhase {
    pub fn parse(_buf: &mut &[u8]) -> Result<CarrierPhase, ::Error> {
        Ok( CarrierPhase{
            i: _buf.read_i32::<LittleEndian>()?,
            f: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<CarrierPhase>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( CarrierPhase::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<CarrierPhase>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( CarrierPhase::parse(buf)? );
        }
        Ok(v)
    }
}

