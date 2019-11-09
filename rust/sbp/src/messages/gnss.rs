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
//! Various structs shared between modules

extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
#[cfg(feature = "serialize")]
use serde::{Deserialize, Serialize};

/// GNSS carrier phase measurement.
///
/// Carrier phase measurement in cycles represented as a 40-bit
/// fixed point number with Q32.8 layout, i.e. 32-bits of whole
/// cycles and 8-bits of fractional cycles. This phase has the
/// same sign as the pseudorange.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct CarrierPhase {
    /// Carrier phase whole cycles
    pub i: i32,
    /// Carrier phase fractional part
    pub f: u8,
}

impl CarrierPhase {
    pub fn parse(_buf: &mut &[u8]) -> Result<CarrierPhase, crate::Error> {
        Ok(CarrierPhase {
            i: _buf.read_i32::<LittleEndian>()?,
            f: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<CarrierPhase>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(CarrierPhase::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<CarrierPhase>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(CarrierPhase::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for CarrierPhase {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.i.append_to_sbp_buffer(buf);
        self.f.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.i.sbp_size();
        size += self.f.sbp_size();
        size
    }
}

/// Nanosecond-accurate receiver clock time
///
/// A wire-appropriate receiver clock time, defined as the time
/// since the beginning of the week on the Saturday/Sunday
/// transition. In most cases, observations are epoch aligned
/// so ns field will be 0.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct GPSTime {
    /// Milliseconds since start of GPS week
    pub tow: u32,
    /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    /// 500000)
    pub ns_residual: i32,
    /// GPS week number
    pub wn: u16,
}

impl GPSTime {
    pub fn parse(_buf: &mut &[u8]) -> Result<GPSTime, crate::Error> {
        Ok(GPSTime {
            tow: _buf.read_u32::<LittleEndian>()?,
            ns_residual: _buf.read_i32::<LittleEndian>()?,
            wn: _buf.read_u16::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GPSTime>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(GPSTime::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<GPSTime>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(GPSTime::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for GPSTime {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.ns_residual.append_to_sbp_buffer(buf);
        self.wn.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.ns_residual.sbp_size();
        size += self.wn.sbp_size();
        size
    }
}

/// Millisecond-accurate GPS time
///
/// A wire-appropriate GPS time, defined as the number of
/// milliseconds since beginning of the week on the Saturday/Sunday
/// transition.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct GPSTimeDep {
    /// Milliseconds since start of GPS week
    pub tow: u32,
    /// GPS week number
    pub wn: u16,
}

impl GPSTimeDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<GPSTimeDep, crate::Error> {
        Ok(GPSTimeDep {
            tow: _buf.read_u32::<LittleEndian>()?,
            wn: _buf.read_u16::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GPSTimeDep>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(GPSTimeDep::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<GPSTimeDep>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(GPSTimeDep::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for GPSTimeDep {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.wn.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.wn.sbp_size();
        size
    }
}

/// Whole second accurate GPS time
///
/// A GPS time, defined as the number of
/// seconds since beginning of the week on the Saturday/Sunday
/// transition.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct GPSTimeSec {
    /// Seconds since start of GPS week
    pub tow: u32,
    /// GPS week number
    pub wn: u16,
}

impl GPSTimeSec {
    pub fn parse(_buf: &mut &[u8]) -> Result<GPSTimeSec, crate::Error> {
        Ok(GPSTimeSec {
            tow: _buf.read_u32::<LittleEndian>()?,
            wn: _buf.read_u16::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GPSTimeSec>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(GPSTimeSec::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<GPSTimeSec>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(GPSTimeSec::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for GPSTimeSec {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.wn.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.wn.sbp_size();
        size
    }
}

/// Represents all the relevant information about the signal
///
/// Signal identifier containing constellation, band, and satellite identifier
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct GnssSignal {
    /// Constellation-specific satellite identifier. This field for Glonass can
    /// either be (100+FCN) where FCN is in [-7,+6] or  the Slot ID in [1,28]
    pub sat: u8,
    /// Signal constellation, band and code
    pub code: u8,
}

impl GnssSignal {
    pub fn parse(_buf: &mut &[u8]) -> Result<GnssSignal, crate::Error> {
        Ok(GnssSignal {
            sat: _buf.read_u8()?,
            code: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GnssSignal>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(GnssSignal::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<GnssSignal>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(GnssSignal::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for GnssSignal {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sat.append_to_sbp_buffer(buf);
        self.code.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sat.sbp_size();
        size += self.code.sbp_size();
        size
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct GnssSignalDep {
    /// Constellation-specific satellite identifier.  Note: unlike GnssSignal,
    /// GPS satellites are encoded as (PRN - 1). Other constellations do not
    /// have this offset.
    pub sat: u16,
    /// Signal constellation, band and code
    pub code: u8,
    /// Reserved
    pub reserved: u8,
}

impl GnssSignalDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<GnssSignalDep, crate::Error> {
        Ok(GnssSignalDep {
            sat: _buf.read_u16::<LittleEndian>()?,
            code: _buf.read_u8()?,
            reserved: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GnssSignalDep>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(GnssSignalDep::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<GnssSignalDep>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(GnssSignalDep::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for GnssSignalDep {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sat.append_to_sbp_buffer(buf);
        self.code.append_to_sbp_buffer(buf);
        self.reserved.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sat.sbp_size();
        size += self.code.sbp_size();
        size += self.reserved.sbp_size();
        size
    }
}

/// Space vehicle identifier
///
/// A (Constellation ID, satellite ID) tuple that uniquely identifies
/// a space vehicle
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct SvId {
    /// ID of the space vehicle within its constellation
    pub satId: u8,
    /// Constellation ID to which the SV belongs
    pub constellation: u8,
}

impl SvId {
    pub fn parse(_buf: &mut &[u8]) -> Result<SvId, crate::Error> {
        Ok(SvId {
            satId: _buf.read_u8()?,
            constellation: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<SvId>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(SvId::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<SvId>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(SvId::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for SvId {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.satId.append_to_sbp_buffer(buf);
        self.constellation.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.satId.sbp_size();
        size += self.constellation.sbp_size();
        size
    }
}
