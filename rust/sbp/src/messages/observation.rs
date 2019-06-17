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
// Automatically generated from yaml/swiftnav/sbp/observation.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
// Satellite observation messages from the device.
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
use super::gnss::*;

// Header for observation message.
//
// Header of a GNSS observation message.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct ObservationHeader {
    pub t: GPSTime,
    // ^ GNSS time of this observation
    pub n_obs: u8,
    // ^ Total number of observations. First nibble is the size of the sequence
    // (n), second nibble is the zero-indexed counter (ith packet of n)
}

impl ObservationHeader {
    pub fn parse(_buf: &mut &[u8]) -> Result<ObservationHeader, ::parser::MessageError> {
        Ok(ObservationHeader {
            t: GPSTime::parse(_buf)?,
            n_obs: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<ObservationHeader>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(ObservationHeader::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<ObservationHeader>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(ObservationHeader::parse(buf)?);
        }
        Ok(v)
    }
}

// GNSS doppler measurement.
//
// Doppler measurement in Hz represented as a 24-bit
// fixed point number with Q16.8 layout, i.e. 16-bits of whole
// doppler and 8-bits of fractional doppler. This doppler is defined
// as positive for approaching satellites.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct Doppler {
    pub i: i16,
    // ^ Doppler whole Hz
    pub f: u8,
    // ^ Doppler fractional part
}

impl Doppler {
    pub fn parse(_buf: &mut &[u8]) -> Result<Doppler, ::parser::MessageError> {
        Ok(Doppler {
            i: _buf.read_i16::<LittleEndian>()?,
            f: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<Doppler>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(Doppler::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<Doppler>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(Doppler::parse(buf)?);
        }
        Ok(v)
    }
}

// GNSS observations for a particular satellite signal.
//
// Pseudorange and carrier phase observation for a satellite being tracked.
// The observations are interoperable with 3rd party receivers and conform with
// typical RTCM 3.1 message GPS/GLO observations.
//
// Carrier phase observations are not guaranteed to be aligned to the RINEX 3
// or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are currently
// peformed.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct PackedObsContent {
    pub P: u32,
    // ^ Pseudorange observation
    pub L: CarrierPhase,
    // ^ Carrier phase observation with typical sign convention.
    pub D: Doppler,
    // ^ Doppler observation with typical sign convention.
    pub cn0: u8,
    // ^ Carrier-to-Noise density.  Zero implies invalid cn0.
    pub lock: u8,
    // ^ Lock timer. This value gives an indication of the time for which a
    // signal has maintained continuous phase lock. Whenever a signal has lost
    // and regained lock, this value is reset to zero. It is encoded according
    // to DF402 from the RTCM 10403.2 Amendment 2 specification.  Valid values
    // range from 0 to 15 and the most significant nibble is reserved for
    // future use.
    pub flags: u8,
    // ^ Measurement status flags. A bit field of flags providing the status of
    // this observation.  If this field is 0 it means only the Cn0 estimate for
    // the signal is valid.
    pub sid: GnssSignal,
    // ^ GNSS signal identifier (16 bit)
}

impl PackedObsContent {
    pub fn parse(_buf: &mut &[u8]) -> Result<PackedObsContent, ::parser::MessageError> {
        Ok(PackedObsContent {
            P: _buf.read_u32::<LittleEndian>()?,
            L: CarrierPhase::parse(_buf)?,
            D: Doppler::parse(_buf)?,
            cn0: _buf.read_u8()?,
            lock: _buf.read_u8()?,
            flags: _buf.read_u8()?,
            sid: GnssSignal::parse(_buf)?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<PackedObsContent>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(PackedObsContent::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<PackedObsContent>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(PackedObsContent::parse(buf)?);
        }
        Ok(v)
    }
}

// Network correction for a particular satellite signal.
//
// Pseudorange and carrier phase network corrections for a satellite signal.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct PackedOsrContent {
    pub P: u32,
    // ^ Pseudorange observation
    pub L: CarrierPhase,
    // ^ Carrier phase observation with typical sign convention.
    pub lock: u8,
    // ^ Lock timer. This value gives an indication of the time for which a
    // signal has maintained continuous phase lock. Whenever a signal has lost
    // and regained lock, this value is reset to zero. It is encoded according
    // to DF402 from the RTCM 10403.2 Amendment 2 specification.  Valid values
    // range from 0 to 15 and the most significant nibble is reserved for
    // future use.
    pub flags: u8,
    // ^ Correction flags.
    pub sid: GnssSignal,
    // ^ GNSS signal identifier (16 bit)
    pub iono_std: u16,
    // ^ Slant ionospheric correction standard deviation
    pub tropo_std: u16,
    // ^ Slant tropospheric correction standard deviation
    pub range_std: u16,
    // ^ Orbit/clock/bias correction projected on range standard deviation
}

impl PackedOsrContent {
    pub fn parse(_buf: &mut &[u8]) -> Result<PackedOsrContent, ::parser::MessageError> {
        Ok(PackedOsrContent {
            P: _buf.read_u32::<LittleEndian>()?,
            L: CarrierPhase::parse(_buf)?,
            lock: _buf.read_u8()?,
            flags: _buf.read_u8()?,
            sid: GnssSignal::parse(_buf)?,
            iono_std: _buf.read_u16::<LittleEndian>()?,
            tropo_std: _buf.read_u16::<LittleEndian>()?,
            range_std: _buf.read_u16::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<PackedOsrContent>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(PackedOsrContent::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<PackedOsrContent>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(PackedOsrContent::parse(buf)?);
        }
        Ok(v)
    }
}

// GPS satellite observations
//
// The GPS observations message reports all the raw pseudorange and
// carrier phase observations for the satellites being tracked by
// the device. Carrier phase observation here is represented as a
// 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
// whole cycles and 8-bits of fractional cycles). The observations
// are be interoperable with 3rd party receivers and conform
// with typical RTCMv3 GNSS observations.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgObs {
    pub header: ObservationHeader,
    // ^ Header of a GPS observation message
    pub obs: Vec<PackedObsContent>,
    // ^ Pseudorange and carrier phase observation for a satellite being tracked.
}

impl MsgObs {
    pub const TYPE: u16 = 74;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgObs, ::parser::MessageError> {
        Ok(MsgObs {
            header: ObservationHeader::parse(_buf)?,
            obs: PackedObsContent::parse_array(_buf)?,
        })
    }
}

// Base station position
//
// The base station position message is the position reported by
// the base station itself. It is used for pseudo-absolute RTK
// positioning, and is required to be a high-accuracy surveyed
// location of the base station. Any error here will result in an
// error in the pseudo-absolute position output.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBasePosLLH {
    pub lat: f64,
    // ^ Latitude
    pub lon: f64,
    // ^ Longitude
    pub height: f64,
    // ^ Height
}

impl MsgBasePosLLH {
    pub const TYPE: u16 = 68;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBasePosLLH, ::parser::MessageError> {
        Ok(MsgBasePosLLH {
            lat: _buf.read_f64::<LittleEndian>()?,
            lon: _buf.read_f64::<LittleEndian>()?,
            height: _buf.read_f64::<LittleEndian>()?,
        })
    }
}

// Base station position in ECEF
//
// The base station position message is the position reported by
// the base station itself in absolute Earth Centered Earth Fixed
// coordinates. It is used for pseudo-absolute RTK positioning, and
// is required to be a high-accuracy surveyed location of the base
// station. Any error here will result in an error in the
// pseudo-absolute position output.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgBasePosECEF {
    pub x: f64,
    // ^ ECEF X coodinate
    pub y: f64,
    // ^ ECEF Y coordinate
    pub z: f64,
    // ^ ECEF Z coordinate
}

impl MsgBasePosECEF {
    pub const TYPE: u16 = 72;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBasePosECEF, ::parser::MessageError> {
        Ok(MsgBasePosECEF {
            x: _buf.read_f64::<LittleEndian>()?,
            y: _buf.read_f64::<LittleEndian>()?,
            z: _buf.read_f64::<LittleEndian>()?,
        })
    }
}

#[derive(Debug)]
#[allow(non_snake_case)]
pub struct EphemerisCommonContent {
    pub sid: GnssSignal,
    // ^ GNSS signal identifier (16 bit)
    pub toe: GPSTimeSec,
    // ^ Time of Ephemerides
    pub ura: f32,
    // ^ User Range Accuracy
    pub fit_interval: u32,
    // ^ Curve fit interval
    pub valid: u8,
    // ^ Status of ephemeris, 1 = valid, 0 = invalid
    pub health_bits: u8,
    // ^ Satellite health status. GPS: ICD-GPS-200, chapter 20.3.3.3.1.4 SBAS: 0
    // = valid, non-zero = invalid GLO: 0 = valid, non-zero = invalid
}

impl EphemerisCommonContent {
    pub fn parse(_buf: &mut &[u8]) -> Result<EphemerisCommonContent, ::parser::MessageError> {
        Ok(EphemerisCommonContent {
            sid: GnssSignal::parse(_buf)?,
            toe: GPSTimeSec::parse(_buf)?,
            ura: _buf.read_f32::<LittleEndian>()?,
            fit_interval: _buf.read_u32::<LittleEndian>()?,
            valid: _buf.read_u8()?,
            health_bits: _buf.read_u8()?,
        })
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<EphemerisCommonContent>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(EphemerisCommonContent::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<EphemerisCommonContent>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(EphemerisCommonContent::parse(buf)?);
        }
        Ok(v)
    }
}

#[derive(Debug)]
#[allow(non_snake_case)]
pub struct EphemerisCommonContentDepB {
    pub sid: GnssSignal,
    // ^ GNSS signal identifier (16 bit)
    pub toe: GPSTimeSec,
    // ^ Time of Ephemerides
    pub ura: f64,
    // ^ User Range Accuracy
    pub fit_interval: u32,
    // ^ Curve fit interval
    pub valid: u8,
    // ^ Status of ephemeris, 1 = valid, 0 = invalid
    pub health_bits: u8,
    // ^ Satellite health status. GPS: ICD-GPS-200, chapter 20.3.3.3.1.4 Others:
    // 0 = valid, non-zero = invalid
}

impl EphemerisCommonContentDepB {
    pub fn parse(_buf: &mut &[u8]) -> Result<EphemerisCommonContentDepB, ::parser::MessageError> {
        Ok(EphemerisCommonContentDepB {
            sid: GnssSignal::parse(_buf)?,
            toe: GPSTimeSec::parse(_buf)?,
            ura: _buf.read_f64::<LittleEndian>()?,
            fit_interval: _buf.read_u32::<LittleEndian>()?,
            valid: _buf.read_u8()?,
            health_bits: _buf.read_u8()?,
        })
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<EphemerisCommonContentDepB>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(EphemerisCommonContentDepB::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<EphemerisCommonContentDepB>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(EphemerisCommonContentDepB::parse(buf)?);
        }
        Ok(v)
    }
}

#[derive(Debug)]
#[allow(non_snake_case)]
pub struct EphemerisCommonContentDepA {
    pub sid: GnssSignalDep,
    // ^ GNSS signal identifier
    pub toe: GPSTimeDep,
    // ^ Time of Ephemerides
    pub ura: f64,
    // ^ User Range Accuracy
    pub fit_interval: u32,
    // ^ Curve fit interval
    pub valid: u8,
    // ^ Status of ephemeris, 1 = valid, 0 = invalid
    pub health_bits: u8,
    // ^ Satellite health status. GPS: ICD-GPS-200, chapter 20.3.3.3.1.4 SBAS: 0
    // = valid, non-zero = invalid GLO: 0 = valid, non-zero = invalid
}

impl EphemerisCommonContentDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<EphemerisCommonContentDepA, ::parser::MessageError> {
        Ok(EphemerisCommonContentDepA {
            sid: GnssSignalDep::parse(_buf)?,
            toe: GPSTimeDep::parse(_buf)?,
            ura: _buf.read_f64::<LittleEndian>()?,
            fit_interval: _buf.read_u32::<LittleEndian>()?,
            valid: _buf.read_u8()?,
            health_bits: _buf.read_u8()?,
        })
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<EphemerisCommonContentDepA>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(EphemerisCommonContentDepA::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<EphemerisCommonContentDepA>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(EphemerisCommonContentDepA::parse(buf)?);
        }
        Ok(v)
    }
}

// Satellite broadcast ephemeris for GPS
//
// The ephemeris message returns a set of satellite orbit
// parameters that is used to calculate GPS satellite position,
// velocity, and clock offset. Please see the Navstar GPS
// Space Segment/Navigation user interfaces (ICD-GPS-200, Table
// 20-III) for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGPSDepE {
    pub common: EphemerisCommonContentDepA,
    // ^ Values common for all ephemeris types
    pub tgd: f64,
    // ^ Group delay differential between L1 and L2
    pub c_rs: f64,
    // ^ Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rc: f64,
    // ^ Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_uc: f64,
    // ^ Amplitude of the cosine harmonic correction term to the argument of
    // latitude
    pub c_us: f64,
    // ^ Amplitude of the sine harmonic correction term to the argument of
    // latitude
    pub c_ic: f64,
    // ^ Amplitude of the cosine harmonic correction term to the angle of
    // inclination
    pub c_is: f64,
    // ^ Amplitude of the sine harmonic correction term to the angle of
    // inclination
    pub dn: f64,
    // ^ Mean motion difference
    pub m0: f64,
    // ^ Mean anomaly at reference time
    pub ecc: f64,
    // ^ Eccentricity of satellite orbit
    pub sqrta: f64,
    // ^ Square root of the semi-major axis of orbit
    pub omega0: f64,
    // ^ Longitude of ascending node of orbit plane at weekly epoch
    pub omegadot: f64,
    // ^ Rate of right ascension
    pub w: f64,
    // ^ Argument of perigee
    pub inc: f64,
    // ^ Inclination
    pub inc_dot: f64,
    // ^ Inclination first derivative
    pub af0: f64,
    // ^ Polynomial clock correction coefficient (clock bias)
    pub af1: f64,
    // ^ Polynomial clock correction coefficient (clock drift)
    pub af2: f64,
    // ^ Polynomial clock correction coefficient (rate of clock drift)
    pub toc: GPSTimeDep,
    // ^ Clock reference
    pub iode: u8,
    // ^ Issue of ephemeris data
    pub iodc: u16,
    // ^ Issue of clock data
}

impl MsgEphemerisGPSDepE {
    pub const TYPE: u16 = 129;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisGPSDepE, ::parser::MessageError> {
        Ok(MsgEphemerisGPSDepE {
            common: EphemerisCommonContentDepA::parse(_buf)?,
            tgd: _buf.read_f64::<LittleEndian>()?,
            c_rs: _buf.read_f64::<LittleEndian>()?,
            c_rc: _buf.read_f64::<LittleEndian>()?,
            c_uc: _buf.read_f64::<LittleEndian>()?,
            c_us: _buf.read_f64::<LittleEndian>()?,
            c_ic: _buf.read_f64::<LittleEndian>()?,
            c_is: _buf.read_f64::<LittleEndian>()?,
            dn: _buf.read_f64::<LittleEndian>()?,
            m0: _buf.read_f64::<LittleEndian>()?,
            ecc: _buf.read_f64::<LittleEndian>()?,
            sqrta: _buf.read_f64::<LittleEndian>()?,
            omega0: _buf.read_f64::<LittleEndian>()?,
            omegadot: _buf.read_f64::<LittleEndian>()?,
            w: _buf.read_f64::<LittleEndian>()?,
            inc: _buf.read_f64::<LittleEndian>()?,
            inc_dot: _buf.read_f64::<LittleEndian>()?,
            af0: _buf.read_f64::<LittleEndian>()?,
            af1: _buf.read_f64::<LittleEndian>()?,
            af2: _buf.read_f64::<LittleEndian>()?,
            toc: GPSTimeDep::parse(_buf)?,
            iode: _buf.read_u8()?,
            iodc: _buf.read_u16::<LittleEndian>()?,
        })
    }
}

// Deprecated
//
// This observation message has been deprecated in favor of
// ephemeris message using floats for size reduction.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGPSDepF {
    pub common: EphemerisCommonContentDepB,
    // ^ Values common for all ephemeris types
    pub tgd: f64,
    // ^ Group delay differential between L1 and L2
    pub c_rs: f64,
    // ^ Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rc: f64,
    // ^ Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_uc: f64,
    // ^ Amplitude of the cosine harmonic correction term to the argument of
    // latitude
    pub c_us: f64,
    // ^ Amplitude of the sine harmonic correction term to the argument of
    // latitude
    pub c_ic: f64,
    // ^ Amplitude of the cosine harmonic correction term to the angle of
    // inclination
    pub c_is: f64,
    // ^ Amplitude of the sine harmonic correction term to the angle of
    // inclination
    pub dn: f64,
    // ^ Mean motion difference
    pub m0: f64,
    // ^ Mean anomaly at reference time
    pub ecc: f64,
    // ^ Eccentricity of satellite orbit
    pub sqrta: f64,
    // ^ Square root of the semi-major axis of orbit
    pub omega0: f64,
    // ^ Longitude of ascending node of orbit plane at weekly epoch
    pub omegadot: f64,
    // ^ Rate of right ascension
    pub w: f64,
    // ^ Argument of perigee
    pub inc: f64,
    // ^ Inclination
    pub inc_dot: f64,
    // ^ Inclination first derivative
    pub af0: f64,
    // ^ Polynomial clock correction coefficient (clock bias)
    pub af1: f64,
    // ^ Polynomial clock correction coefficient (clock drift)
    pub af2: f64,
    // ^ Polynomial clock correction coefficient (rate of clock drift)
    pub toc: GPSTimeSec,
    // ^ Clock reference
    pub iode: u8,
    // ^ Issue of ephemeris data
    pub iodc: u16,
    // ^ Issue of clock data
}

impl MsgEphemerisGPSDepF {
    pub const TYPE: u16 = 134;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisGPSDepF, ::parser::MessageError> {
        Ok(MsgEphemerisGPSDepF {
            common: EphemerisCommonContentDepB::parse(_buf)?,
            tgd: _buf.read_f64::<LittleEndian>()?,
            c_rs: _buf.read_f64::<LittleEndian>()?,
            c_rc: _buf.read_f64::<LittleEndian>()?,
            c_uc: _buf.read_f64::<LittleEndian>()?,
            c_us: _buf.read_f64::<LittleEndian>()?,
            c_ic: _buf.read_f64::<LittleEndian>()?,
            c_is: _buf.read_f64::<LittleEndian>()?,
            dn: _buf.read_f64::<LittleEndian>()?,
            m0: _buf.read_f64::<LittleEndian>()?,
            ecc: _buf.read_f64::<LittleEndian>()?,
            sqrta: _buf.read_f64::<LittleEndian>()?,
            omega0: _buf.read_f64::<LittleEndian>()?,
            omegadot: _buf.read_f64::<LittleEndian>()?,
            w: _buf.read_f64::<LittleEndian>()?,
            inc: _buf.read_f64::<LittleEndian>()?,
            inc_dot: _buf.read_f64::<LittleEndian>()?,
            af0: _buf.read_f64::<LittleEndian>()?,
            af1: _buf.read_f64::<LittleEndian>()?,
            af2: _buf.read_f64::<LittleEndian>()?,
            toc: GPSTimeSec::parse(_buf)?,
            iode: _buf.read_u8()?,
            iodc: _buf.read_u16::<LittleEndian>()?,
        })
    }
}

// Satellite broadcast ephemeris for GPS
//
// The ephemeris message returns a set of satellite orbit
// parameters that is used to calculate GPS satellite position,
// velocity, and clock offset. Please see the Navstar GPS
// Space Segment/Navigation user interfaces (ICD-GPS-200, Table
// 20-III) for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGPS {
    pub common: EphemerisCommonContent,
    // ^ Values common for all ephemeris types
    pub tgd: f32,
    // ^ Group delay differential between L1 and L2
    pub c_rs: f32,
    // ^ Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rc: f32,
    // ^ Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_uc: f32,
    // ^ Amplitude of the cosine harmonic correction term to the argument of
    // latitude
    pub c_us: f32,
    // ^ Amplitude of the sine harmonic correction term to the argument of
    // latitude
    pub c_ic: f32,
    // ^ Amplitude of the cosine harmonic correction term to the angle of
    // inclination
    pub c_is: f32,
    // ^ Amplitude of the sine harmonic correction term to the angle of
    // inclination
    pub dn: f64,
    // ^ Mean motion difference
    pub m0: f64,
    // ^ Mean anomaly at reference time
    pub ecc: f64,
    // ^ Eccentricity of satellite orbit
    pub sqrta: f64,
    // ^ Square root of the semi-major axis of orbit
    pub omega0: f64,
    // ^ Longitude of ascending node of orbit plane at weekly epoch
    pub omegadot: f64,
    // ^ Rate of right ascension
    pub w: f64,
    // ^ Argument of perigee
    pub inc: f64,
    // ^ Inclination
    pub inc_dot: f64,
    // ^ Inclination first derivative
    pub af0: f32,
    // ^ Polynomial clock correction coefficient (clock bias)
    pub af1: f32,
    // ^ Polynomial clock correction coefficient (clock drift)
    pub af2: f32,
    // ^ Polynomial clock correction coefficient (rate of clock drift)
    pub toc: GPSTimeSec,
    // ^ Clock reference
    pub iode: u8,
    // ^ Issue of ephemeris data
    pub iodc: u16,
    // ^ Issue of clock data
}

impl MsgEphemerisGPS {
    pub const TYPE: u16 = 138;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisGPS, ::parser::MessageError> {
        Ok(MsgEphemerisGPS {
            common: EphemerisCommonContent::parse(_buf)?,
            tgd: _buf.read_f32::<LittleEndian>()?,
            c_rs: _buf.read_f32::<LittleEndian>()?,
            c_rc: _buf.read_f32::<LittleEndian>()?,
            c_uc: _buf.read_f32::<LittleEndian>()?,
            c_us: _buf.read_f32::<LittleEndian>()?,
            c_ic: _buf.read_f32::<LittleEndian>()?,
            c_is: _buf.read_f32::<LittleEndian>()?,
            dn: _buf.read_f64::<LittleEndian>()?,
            m0: _buf.read_f64::<LittleEndian>()?,
            ecc: _buf.read_f64::<LittleEndian>()?,
            sqrta: _buf.read_f64::<LittleEndian>()?,
            omega0: _buf.read_f64::<LittleEndian>()?,
            omegadot: _buf.read_f64::<LittleEndian>()?,
            w: _buf.read_f64::<LittleEndian>()?,
            inc: _buf.read_f64::<LittleEndian>()?,
            inc_dot: _buf.read_f64::<LittleEndian>()?,
            af0: _buf.read_f32::<LittleEndian>()?,
            af1: _buf.read_f32::<LittleEndian>()?,
            af2: _buf.read_f32::<LittleEndian>()?,
            toc: GPSTimeSec::parse(_buf)?,
            iode: _buf.read_u8()?,
            iodc: _buf.read_u16::<LittleEndian>()?,
        })
    }
}

// Satellite broadcast ephemeris for QZSS
//
// The ephemeris message returns a set of satellite orbit
// parameters that is used to calculate QZSS satellite position,
// velocity, and clock offset.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisQzss {
    pub common: EphemerisCommonContent,
    // ^ Values common for all ephemeris types
    pub tgd: f32,
    // ^ Group delay differential between L1 and L2
    pub c_rs: f32,
    // ^ Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rc: f32,
    // ^ Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_uc: f32,
    // ^ Amplitude of the cosine harmonic correction term to the argument of
    // latitude
    pub c_us: f32,
    // ^ Amplitude of the sine harmonic correction term to the argument of
    // latitude
    pub c_ic: f32,
    // ^ Amplitude of the cosine harmonic correction term to the angle of
    // inclination
    pub c_is: f32,
    // ^ Amplitude of the sine harmonic correction term to the angle of
    // inclination
    pub dn: f64,
    // ^ Mean motion difference
    pub m0: f64,
    // ^ Mean anomaly at reference time
    pub ecc: f64,
    // ^ Eccentricity of satellite orbit
    pub sqrta: f64,
    // ^ Square root of the semi-major axis of orbit
    pub omega0: f64,
    // ^ Longitude of ascending node of orbit plane at weekly epoch
    pub omegadot: f64,
    // ^ Rate of right ascension
    pub w: f64,
    // ^ Argument of perigee
    pub inc: f64,
    // ^ Inclination
    pub inc_dot: f64,
    // ^ Inclination first derivative
    pub af0: f32,
    // ^ Polynomial clock correction coefficient (clock bias)
    pub af1: f32,
    // ^ Polynomial clock correction coefficient (clock drift)
    pub af2: f32,
    // ^ Polynomial clock correction coefficient (rate of clock drift)
    pub toc: GPSTimeSec,
    // ^ Clock reference
    pub iode: u8,
    // ^ Issue of ephemeris data
    pub iodc: u16,
    // ^ Issue of clock data
}

impl MsgEphemerisQzss {
    pub const TYPE: u16 = 142;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisQzss, ::parser::MessageError> {
        Ok(MsgEphemerisQzss {
            common: EphemerisCommonContent::parse(_buf)?,
            tgd: _buf.read_f32::<LittleEndian>()?,
            c_rs: _buf.read_f32::<LittleEndian>()?,
            c_rc: _buf.read_f32::<LittleEndian>()?,
            c_uc: _buf.read_f32::<LittleEndian>()?,
            c_us: _buf.read_f32::<LittleEndian>()?,
            c_ic: _buf.read_f32::<LittleEndian>()?,
            c_is: _buf.read_f32::<LittleEndian>()?,
            dn: _buf.read_f64::<LittleEndian>()?,
            m0: _buf.read_f64::<LittleEndian>()?,
            ecc: _buf.read_f64::<LittleEndian>()?,
            sqrta: _buf.read_f64::<LittleEndian>()?,
            omega0: _buf.read_f64::<LittleEndian>()?,
            omegadot: _buf.read_f64::<LittleEndian>()?,
            w: _buf.read_f64::<LittleEndian>()?,
            inc: _buf.read_f64::<LittleEndian>()?,
            inc_dot: _buf.read_f64::<LittleEndian>()?,
            af0: _buf.read_f32::<LittleEndian>()?,
            af1: _buf.read_f32::<LittleEndian>()?,
            af2: _buf.read_f32::<LittleEndian>()?,
            toc: GPSTimeSec::parse(_buf)?,
            iode: _buf.read_u8()?,
            iodc: _buf.read_u16::<LittleEndian>()?,
        })
    }
}

// Satellite broadcast ephemeris for BDS
//
// The ephemeris message returns a set of satellite orbit
// parameters that is used to calculate BDS satellite position,
// velocity, and clock offset. Please see the BeiDou Navigation
// Satellite System SIS-ICD Version 2.1, Table 5-9 for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisBds {
    pub common: EphemerisCommonContent,
    // ^ Values common for all ephemeris types
    pub tgd1: f32,
    // ^ Group delay differential for B1
    pub tgd2: f32,
    // ^ Group delay differential for B2
    pub c_rs: f32,
    // ^ Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rc: f32,
    // ^ Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_uc: f32,
    // ^ Amplitude of the cosine harmonic correction term to the argument of
    // latitude
    pub c_us: f32,
    // ^ Amplitude of the sine harmonic correction term to the argument of
    // latitude
    pub c_ic: f32,
    // ^ Amplitude of the cosine harmonic correction term to the angle of
    // inclination
    pub c_is: f32,
    // ^ Amplitude of the sine harmonic correction term to the angle of
    // inclination
    pub dn: f64,
    // ^ Mean motion difference
    pub m0: f64,
    // ^ Mean anomaly at reference time
    pub ecc: f64,
    // ^ Eccentricity of satellite orbit
    pub sqrta: f64,
    // ^ Square root of the semi-major axis of orbit
    pub omega0: f64,
    // ^ Longitude of ascending node of orbit plane at weekly epoch
    pub omegadot: f64,
    // ^ Rate of right ascension
    pub w: f64,
    // ^ Argument of perigee
    pub inc: f64,
    // ^ Inclination
    pub inc_dot: f64,
    // ^ Inclination first derivative
    pub af0: f64,
    // ^ Polynomial clock correction coefficient (clock bias)
    pub af1: f32,
    // ^ Polynomial clock correction coefficient (clock drift)
    pub af2: f32,
    // ^ Polynomial clock correction coefficient (rate of clock drift)
    pub toc: GPSTimeSec,
    // ^ Clock reference
    pub iode: u8,
    // ^ Issue of ephemeris data
    pub iodc: u16,
    // ^ Issue of clock data
}

impl MsgEphemerisBds {
    pub const TYPE: u16 = 137;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisBds, ::parser::MessageError> {
        Ok(MsgEphemerisBds {
            common: EphemerisCommonContent::parse(_buf)?,
            tgd1: _buf.read_f32::<LittleEndian>()?,
            tgd2: _buf.read_f32::<LittleEndian>()?,
            c_rs: _buf.read_f32::<LittleEndian>()?,
            c_rc: _buf.read_f32::<LittleEndian>()?,
            c_uc: _buf.read_f32::<LittleEndian>()?,
            c_us: _buf.read_f32::<LittleEndian>()?,
            c_ic: _buf.read_f32::<LittleEndian>()?,
            c_is: _buf.read_f32::<LittleEndian>()?,
            dn: _buf.read_f64::<LittleEndian>()?,
            m0: _buf.read_f64::<LittleEndian>()?,
            ecc: _buf.read_f64::<LittleEndian>()?,
            sqrta: _buf.read_f64::<LittleEndian>()?,
            omega0: _buf.read_f64::<LittleEndian>()?,
            omegadot: _buf.read_f64::<LittleEndian>()?,
            w: _buf.read_f64::<LittleEndian>()?,
            inc: _buf.read_f64::<LittleEndian>()?,
            inc_dot: _buf.read_f64::<LittleEndian>()?,
            af0: _buf.read_f64::<LittleEndian>()?,
            af1: _buf.read_f32::<LittleEndian>()?,
            af2: _buf.read_f32::<LittleEndian>()?,
            toc: GPSTimeSec::parse(_buf)?,
            iode: _buf.read_u8()?,
            iodc: _buf.read_u16::<LittleEndian>()?,
        })
    }
}

// Deprecated
//
// This observation message has been deprecated in favor of
// an ephemeris message with explicit source of NAV data.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGalDepA {
    pub common: EphemerisCommonContent,
    // ^ Values common for all ephemeris types
    pub bgd_e1e5a: f32,
    // ^ E1-E5a Broadcast Group Delay
    pub bgd_e1e5b: f32,
    // ^ E1-E5b Broadcast Group Delay
    pub c_rs: f32,
    // ^ Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rc: f32,
    // ^ Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_uc: f32,
    // ^ Amplitude of the cosine harmonic correction term to the argument of
    // latitude
    pub c_us: f32,
    // ^ Amplitude of the sine harmonic correction term to the argument of
    // latitude
    pub c_ic: f32,
    // ^ Amplitude of the cosine harmonic correction term to the angle of
    // inclination
    pub c_is: f32,
    // ^ Amplitude of the sine harmonic correction term to the angle of
    // inclination
    pub dn: f64,
    // ^ Mean motion difference
    pub m0: f64,
    // ^ Mean anomaly at reference time
    pub ecc: f64,
    // ^ Eccentricity of satellite orbit
    pub sqrta: f64,
    // ^ Square root of the semi-major axis of orbit
    pub omega0: f64,
    // ^ Longitude of ascending node of orbit plane at weekly epoch
    pub omegadot: f64,
    // ^ Rate of right ascension
    pub w: f64,
    // ^ Argument of perigee
    pub inc: f64,
    // ^ Inclination
    pub inc_dot: f64,
    // ^ Inclination first derivative
    pub af0: f64,
    // ^ Polynomial clock correction coefficient (clock bias)
    pub af1: f64,
    // ^ Polynomial clock correction coefficient (clock drift)
    pub af2: f32,
    // ^ Polynomial clock correction coefficient (rate of clock drift)
    pub toc: GPSTimeSec,
    // ^ Clock reference
    pub iode: u16,
    // ^ Issue of ephemeris data
    pub iodc: u16,
    // ^ Issue of clock data
}

impl MsgEphemerisGalDepA {
    pub const TYPE: u16 = 149;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisGalDepA, ::parser::MessageError> {
        Ok(MsgEphemerisGalDepA {
            common: EphemerisCommonContent::parse(_buf)?,
            bgd_e1e5a: _buf.read_f32::<LittleEndian>()?,
            bgd_e1e5b: _buf.read_f32::<LittleEndian>()?,
            c_rs: _buf.read_f32::<LittleEndian>()?,
            c_rc: _buf.read_f32::<LittleEndian>()?,
            c_uc: _buf.read_f32::<LittleEndian>()?,
            c_us: _buf.read_f32::<LittleEndian>()?,
            c_ic: _buf.read_f32::<LittleEndian>()?,
            c_is: _buf.read_f32::<LittleEndian>()?,
            dn: _buf.read_f64::<LittleEndian>()?,
            m0: _buf.read_f64::<LittleEndian>()?,
            ecc: _buf.read_f64::<LittleEndian>()?,
            sqrta: _buf.read_f64::<LittleEndian>()?,
            omega0: _buf.read_f64::<LittleEndian>()?,
            omegadot: _buf.read_f64::<LittleEndian>()?,
            w: _buf.read_f64::<LittleEndian>()?,
            inc: _buf.read_f64::<LittleEndian>()?,
            inc_dot: _buf.read_f64::<LittleEndian>()?,
            af0: _buf.read_f64::<LittleEndian>()?,
            af1: _buf.read_f64::<LittleEndian>()?,
            af2: _buf.read_f32::<LittleEndian>()?,
            toc: GPSTimeSec::parse(_buf)?,
            iode: _buf.read_u16::<LittleEndian>()?,
            iodc: _buf.read_u16::<LittleEndian>()?,
        })
    }
}

// Satellite broadcast ephemeris for Galileo
//
// The ephemeris message returns a set of satellite orbit
// parameters that is used to calculate Galileo satellite position,
// velocity, and clock offset. Please see the Signal In Space ICD
// OS SIS ICD, Issue 1.3, December 2016 for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGal {
    pub common: EphemerisCommonContent,
    // ^ Values common for all ephemeris types
    pub bgd_e1e5a: f32,
    // ^ E1-E5a Broadcast Group Delay
    pub bgd_e1e5b: f32,
    // ^ E1-E5b Broadcast Group Delay
    pub c_rs: f32,
    // ^ Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rc: f32,
    // ^ Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_uc: f32,
    // ^ Amplitude of the cosine harmonic correction term to the argument of
    // latitude
    pub c_us: f32,
    // ^ Amplitude of the sine harmonic correction term to the argument of
    // latitude
    pub c_ic: f32,
    // ^ Amplitude of the cosine harmonic correction term to the angle of
    // inclination
    pub c_is: f32,
    // ^ Amplitude of the sine harmonic correction term to the angle of
    // inclination
    pub dn: f64,
    // ^ Mean motion difference
    pub m0: f64,
    // ^ Mean anomaly at reference time
    pub ecc: f64,
    // ^ Eccentricity of satellite orbit
    pub sqrta: f64,
    // ^ Square root of the semi-major axis of orbit
    pub omega0: f64,
    // ^ Longitude of ascending node of orbit plane at weekly epoch
    pub omegadot: f64,
    // ^ Rate of right ascension
    pub w: f64,
    // ^ Argument of perigee
    pub inc: f64,
    // ^ Inclination
    pub inc_dot: f64,
    // ^ Inclination first derivative
    pub af0: f64,
    // ^ Polynomial clock correction coefficient (clock bias)
    pub af1: f64,
    // ^ Polynomial clock correction coefficient (clock drift)
    pub af2: f32,
    // ^ Polynomial clock correction coefficient (rate of clock drift)
    pub toc: GPSTimeSec,
    // ^ Clock reference
    pub iode: u16,
    // ^ Issue of ephemeris data
    pub iodc: u16,
    // ^ Issue of clock data
    pub source: u8,
    // ^ 0=I/NAV, 1=F/NAV, ...
}

impl MsgEphemerisGal {
    pub const TYPE: u16 = 141;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisGal, ::parser::MessageError> {
        Ok(MsgEphemerisGal {
            common: EphemerisCommonContent::parse(_buf)?,
            bgd_e1e5a: _buf.read_f32::<LittleEndian>()?,
            bgd_e1e5b: _buf.read_f32::<LittleEndian>()?,
            c_rs: _buf.read_f32::<LittleEndian>()?,
            c_rc: _buf.read_f32::<LittleEndian>()?,
            c_uc: _buf.read_f32::<LittleEndian>()?,
            c_us: _buf.read_f32::<LittleEndian>()?,
            c_ic: _buf.read_f32::<LittleEndian>()?,
            c_is: _buf.read_f32::<LittleEndian>()?,
            dn: _buf.read_f64::<LittleEndian>()?,
            m0: _buf.read_f64::<LittleEndian>()?,
            ecc: _buf.read_f64::<LittleEndian>()?,
            sqrta: _buf.read_f64::<LittleEndian>()?,
            omega0: _buf.read_f64::<LittleEndian>()?,
            omegadot: _buf.read_f64::<LittleEndian>()?,
            w: _buf.read_f64::<LittleEndian>()?,
            inc: _buf.read_f64::<LittleEndian>()?,
            inc_dot: _buf.read_f64::<LittleEndian>()?,
            af0: _buf.read_f64::<LittleEndian>()?,
            af1: _buf.read_f64::<LittleEndian>()?,
            af2: _buf.read_f32::<LittleEndian>()?,
            toc: GPSTimeSec::parse(_buf)?,
            iode: _buf.read_u16::<LittleEndian>()?,
            iodc: _buf.read_u16::<LittleEndian>()?,
            source: _buf.read_u8()?,
        })
    }
}

#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisSbasDepA {
    pub common: EphemerisCommonContentDepA,
    // ^ Values common for all ephemeris types
    pub pos: Vec<f64>,
    // ^ Position of the GEO at time toe
    pub vel: Vec<f64>,
    // ^ Velocity of the GEO at time toe
    pub acc: Vec<f64>,
    // ^ Acceleration of the GEO at time toe
    pub a_gf0: f64,
    // ^ Time offset of the GEO clock w.r.t. SBAS Network Time
    pub a_gf1: f64,
    // ^ Drift of the GEO clock w.r.t. SBAS Network Time
}

impl MsgEphemerisSbasDepA {
    pub const TYPE: u16 = 130;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisSbasDepA, ::parser::MessageError> {
        Ok(MsgEphemerisSbasDepA {
            common: EphemerisCommonContentDepA::parse(_buf)?,
            pos: ::parser::read_double_array_limit(_buf, 3)?,
            vel: ::parser::read_double_array_limit(_buf, 3)?,
            acc: ::parser::read_double_array_limit(_buf, 3)?,
            a_gf0: _buf.read_f64::<LittleEndian>()?,
            a_gf1: _buf.read_f64::<LittleEndian>()?,
        })
    }
}

// Satellite broadcast ephemeris for GLO
//
// The ephemeris message returns a set of satellite orbit
// parameters that is used to calculate GLO satellite position,
// velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
// Characteristics of words of immediate information (ephemeris parameters)"
// for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGloDepA {
    pub common: EphemerisCommonContentDepA,
    // ^ Values common for all ephemeris types
    pub gamma: f64,
    // ^ Relative deviation of predicted carrier frequency from nominal
    pub tau: f64,
    // ^ Correction to the SV time
    pub pos: Vec<f64>,
    // ^ Position of the SV at tb in PZ-90.02 coordinates system
    pub vel: Vec<f64>,
    // ^ Velocity vector of the SV at tb in PZ-90.02 coordinates system
    pub acc: Vec<f64>,
    // ^ Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
}

impl MsgEphemerisGloDepA {
    pub const TYPE: u16 = 131;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisGloDepA, ::parser::MessageError> {
        Ok(MsgEphemerisGloDepA {
            common: EphemerisCommonContentDepA::parse(_buf)?,
            gamma: _buf.read_f64::<LittleEndian>()?,
            tau: _buf.read_f64::<LittleEndian>()?,
            pos: ::parser::read_double_array_limit(_buf, 3)?,
            vel: ::parser::read_double_array_limit(_buf, 3)?,
            acc: ::parser::read_double_array_limit(_buf, 3)?,
        })
    }
}

// Deprecated
//
// This observation message has been deprecated in favor of
// ephemeris message using floats for size reduction.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisSbasDepB {
    pub common: EphemerisCommonContentDepB,
    // ^ Values common for all ephemeris types
    pub pos: Vec<f64>,
    // ^ Position of the GEO at time toe
    pub vel: Vec<f64>,
    // ^ Velocity of the GEO at time toe
    pub acc: Vec<f64>,
    // ^ Acceleration of the GEO at time toe
    pub a_gf0: f64,
    // ^ Time offset of the GEO clock w.r.t. SBAS Network Time
    pub a_gf1: f64,
    // ^ Drift of the GEO clock w.r.t. SBAS Network Time
}

impl MsgEphemerisSbasDepB {
    pub const TYPE: u16 = 132;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisSbasDepB, ::parser::MessageError> {
        Ok(MsgEphemerisSbasDepB {
            common: EphemerisCommonContentDepB::parse(_buf)?,
            pos: ::parser::read_double_array_limit(_buf, 3)?,
            vel: ::parser::read_double_array_limit(_buf, 3)?,
            acc: ::parser::read_double_array_limit(_buf, 3)?,
            a_gf0: _buf.read_f64::<LittleEndian>()?,
            a_gf1: _buf.read_f64::<LittleEndian>()?,
        })
    }
}

#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisSbas {
    pub common: EphemerisCommonContent,
    // ^ Values common for all ephemeris types
    pub pos: Vec<f64>,
    // ^ Position of the GEO at time toe
    pub vel: Vec<f32>,
    // ^ Velocity of the GEO at time toe
    pub acc: Vec<f32>,
    // ^ Acceleration of the GEO at time toe
    pub a_gf0: f32,
    // ^ Time offset of the GEO clock w.r.t. SBAS Network Time
    pub a_gf1: f32,
    // ^ Drift of the GEO clock w.r.t. SBAS Network Time
}

impl MsgEphemerisSbas {
    pub const TYPE: u16 = 140;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisSbas, ::parser::MessageError> {
        Ok(MsgEphemerisSbas {
            common: EphemerisCommonContent::parse(_buf)?,
            pos: ::parser::read_double_array_limit(_buf, 3)?,
            vel: ::parser::read_float_array_limit(_buf, 3)?,
            acc: ::parser::read_float_array_limit(_buf, 3)?,
            a_gf0: _buf.read_f32::<LittleEndian>()?,
            a_gf1: _buf.read_f32::<LittleEndian>()?,
        })
    }
}

// Satellite broadcast ephemeris for GLO
//
// The ephemeris message returns a set of satellite orbit
// parameters that is used to calculate GLO satellite position,
// velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
// Characteristics of words of immediate information (ephemeris parameters)"
// for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGloDepB {
    pub common: EphemerisCommonContentDepB,
    // ^ Values common for all ephemeris types
    pub gamma: f64,
    // ^ Relative deviation of predicted carrier frequency from nominal
    pub tau: f64,
    // ^ Correction to the SV time
    pub pos: Vec<f64>,
    // ^ Position of the SV at tb in PZ-90.02 coordinates system
    pub vel: Vec<f64>,
    // ^ Velocity vector of the SV at tb in PZ-90.02 coordinates system
    pub acc: Vec<f64>,
    // ^ Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
}

impl MsgEphemerisGloDepB {
    pub const TYPE: u16 = 133;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisGloDepB, ::parser::MessageError> {
        Ok(MsgEphemerisGloDepB {
            common: EphemerisCommonContentDepB::parse(_buf)?,
            gamma: _buf.read_f64::<LittleEndian>()?,
            tau: _buf.read_f64::<LittleEndian>()?,
            pos: ::parser::read_double_array_limit(_buf, 3)?,
            vel: ::parser::read_double_array_limit(_buf, 3)?,
            acc: ::parser::read_double_array_limit(_buf, 3)?,
        })
    }
}

// Satellite broadcast ephemeris for GLO
//
// The ephemeris message returns a set of satellite orbit
// parameters that is used to calculate GLO satellite position,
// velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
// Characteristics of words of immediate information (ephemeris parameters)"
// for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGloDepC {
    pub common: EphemerisCommonContentDepB,
    // ^ Values common for all ephemeris types
    pub gamma: f64,
    // ^ Relative deviation of predicted carrier frequency from nominal
    pub tau: f64,
    // ^ Correction to the SV time
    pub d_tau: f64,
    // ^ Equipment delay between L1 and L2
    pub pos: Vec<f64>,
    // ^ Position of the SV at tb in PZ-90.02 coordinates system
    pub vel: Vec<f64>,
    // ^ Velocity vector of the SV at tb in PZ-90.02 coordinates system
    pub acc: Vec<f64>,
    // ^ Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    pub fcn: u8,
    // ^ Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
}

impl MsgEphemerisGloDepC {
    pub const TYPE: u16 = 135;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisGloDepC, ::parser::MessageError> {
        Ok(MsgEphemerisGloDepC {
            common: EphemerisCommonContentDepB::parse(_buf)?,
            gamma: _buf.read_f64::<LittleEndian>()?,
            tau: _buf.read_f64::<LittleEndian>()?,
            d_tau: _buf.read_f64::<LittleEndian>()?,
            pos: ::parser::read_double_array_limit(_buf, 3)?,
            vel: ::parser::read_double_array_limit(_buf, 3)?,
            acc: ::parser::read_double_array_limit(_buf, 3)?,
            fcn: _buf.read_u8()?,
        })
    }
}

// Deprecated
//
// This observation message has been deprecated in favor of
// ephemeris message using floats for size reduction.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGloDepD {
    pub common: EphemerisCommonContentDepB,
    // ^ Values common for all ephemeris types
    pub gamma: f64,
    // ^ Relative deviation of predicted carrier frequency from nominal
    pub tau: f64,
    // ^ Correction to the SV time
    pub d_tau: f64,
    // ^ Equipment delay between L1 and L2
    pub pos: Vec<f64>,
    // ^ Position of the SV at tb in PZ-90.02 coordinates system
    pub vel: Vec<f64>,
    // ^ Velocity vector of the SV at tb in PZ-90.02 coordinates system
    pub acc: Vec<f64>,
    // ^ Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    pub fcn: u8,
    // ^ Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
    pub iod: u8,
    // ^ Issue of ephemeris data
}

impl MsgEphemerisGloDepD {
    pub const TYPE: u16 = 136;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisGloDepD, ::parser::MessageError> {
        Ok(MsgEphemerisGloDepD {
            common: EphemerisCommonContentDepB::parse(_buf)?,
            gamma: _buf.read_f64::<LittleEndian>()?,
            tau: _buf.read_f64::<LittleEndian>()?,
            d_tau: _buf.read_f64::<LittleEndian>()?,
            pos: ::parser::read_double_array_limit(_buf, 3)?,
            vel: ::parser::read_double_array_limit(_buf, 3)?,
            acc: ::parser::read_double_array_limit(_buf, 3)?,
            fcn: _buf.read_u8()?,
            iod: _buf.read_u8()?,
        })
    }
}

// Satellite broadcast ephemeris for GLO
//
// The ephemeris message returns a set of satellite orbit
// parameters that is used to calculate GLO satellite position,
// velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
// Characteristics of words of immediate information (ephemeris parameters)"
// for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGlo {
    pub common: EphemerisCommonContent,
    // ^ Values common for all ephemeris types
    pub gamma: f32,
    // ^ Relative deviation of predicted carrier frequency from nominal
    pub tau: f32,
    // ^ Correction to the SV time
    pub d_tau: f32,
    // ^ Equipment delay between L1 and L2
    pub pos: Vec<f64>,
    // ^ Position of the SV at tb in PZ-90.02 coordinates system
    pub vel: Vec<f64>,
    // ^ Velocity vector of the SV at tb in PZ-90.02 coordinates system
    pub acc: Vec<f32>,
    // ^ Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    pub fcn: u8,
    // ^ Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
    pub iod: u8,
    // ^ Issue of ephemeris data
}

impl MsgEphemerisGlo {
    pub const TYPE: u16 = 139;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisGlo, ::parser::MessageError> {
        Ok(MsgEphemerisGlo {
            common: EphemerisCommonContent::parse(_buf)?,
            gamma: _buf.read_f32::<LittleEndian>()?,
            tau: _buf.read_f32::<LittleEndian>()?,
            d_tau: _buf.read_f32::<LittleEndian>()?,
            pos: ::parser::read_double_array_limit(_buf, 3)?,
            vel: ::parser::read_double_array_limit(_buf, 3)?,
            acc: ::parser::read_float_array_limit(_buf, 3)?,
            fcn: _buf.read_u8()?,
            iod: _buf.read_u8()?,
        })
    }
}

// Satellite broadcast ephemeris
//
// The ephemeris message returns a set of satellite orbit
// parameters that is used to calculate GPS satellite position,
// velocity, and clock offset. Please see the Navstar GPS
// Space Segment/Navigation user interfaces (ICD-GPS-200, Table
// 20-III) for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisDepD {
    pub tgd: f64,
    // ^ Group delay differential between L1 and L2
    pub c_rs: f64,
    // ^ Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rc: f64,
    // ^ Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_uc: f64,
    // ^ Amplitude of the cosine harmonic correction term to the argument of
    // latitude
    pub c_us: f64,
    // ^ Amplitude of the sine harmonic correction term to the argument of
    // latitude
    pub c_ic: f64,
    // ^ Amplitude of the cosine harmonic correction term to the angle of
    // inclination
    pub c_is: f64,
    // ^ Amplitude of the sine harmonic correction term to the angle of
    // inclination
    pub dn: f64,
    // ^ Mean motion difference
    pub m0: f64,
    // ^ Mean anomaly at reference time
    pub ecc: f64,
    // ^ Eccentricity of satellite orbit
    pub sqrta: f64,
    // ^ Square root of the semi-major axis of orbit
    pub omega0: f64,
    // ^ Longitude of ascending node of orbit plane at weekly epoch
    pub omegadot: f64,
    // ^ Rate of right ascension
    pub w: f64,
    // ^ Argument of perigee
    pub inc: f64,
    // ^ Inclination
    pub inc_dot: f64,
    // ^ Inclination first derivative
    pub af0: f64,
    // ^ Polynomial clock correction coefficient (clock bias)
    pub af1: f64,
    // ^ Polynomial clock correction coefficient (clock drift)
    pub af2: f64,
    // ^ Polynomial clock correction coefficient (rate of clock drift)
    pub toe_tow: f64,
    // ^ Time of week
    pub toe_wn: u16,
    // ^ Week number
    pub toc_tow: f64,
    // ^ Clock reference time of week
    pub toc_wn: u16,
    // ^ Clock reference week number
    pub valid: u8,
    // ^ Is valid?
    pub healthy: u8,
    // ^ Satellite is healthy?
    pub sid: GnssSignalDep,
    // ^ GNSS signal identifier
    pub iode: u8,
    // ^ Issue of ephemeris data
    pub iodc: u16,
    // ^ Issue of clock data
    pub reserved: u32,
    // ^ Reserved field
}

impl MsgEphemerisDepD {
    pub const TYPE: u16 = 128;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisDepD, ::parser::MessageError> {
        Ok(MsgEphemerisDepD {
            tgd: _buf.read_f64::<LittleEndian>()?,
            c_rs: _buf.read_f64::<LittleEndian>()?,
            c_rc: _buf.read_f64::<LittleEndian>()?,
            c_uc: _buf.read_f64::<LittleEndian>()?,
            c_us: _buf.read_f64::<LittleEndian>()?,
            c_ic: _buf.read_f64::<LittleEndian>()?,
            c_is: _buf.read_f64::<LittleEndian>()?,
            dn: _buf.read_f64::<LittleEndian>()?,
            m0: _buf.read_f64::<LittleEndian>()?,
            ecc: _buf.read_f64::<LittleEndian>()?,
            sqrta: _buf.read_f64::<LittleEndian>()?,
            omega0: _buf.read_f64::<LittleEndian>()?,
            omegadot: _buf.read_f64::<LittleEndian>()?,
            w: _buf.read_f64::<LittleEndian>()?,
            inc: _buf.read_f64::<LittleEndian>()?,
            inc_dot: _buf.read_f64::<LittleEndian>()?,
            af0: _buf.read_f64::<LittleEndian>()?,
            af1: _buf.read_f64::<LittleEndian>()?,
            af2: _buf.read_f64::<LittleEndian>()?,
            toe_tow: _buf.read_f64::<LittleEndian>()?,
            toe_wn: _buf.read_u16::<LittleEndian>()?,
            toc_tow: _buf.read_f64::<LittleEndian>()?,
            toc_wn: _buf.read_u16::<LittleEndian>()?,
            valid: _buf.read_u8()?,
            healthy: _buf.read_u8()?,
            sid: GnssSignalDep::parse(_buf)?,
            iode: _buf.read_u8()?,
            iodc: _buf.read_u16::<LittleEndian>()?,
            reserved: _buf.read_u32::<LittleEndian>()?,
        })
    }
}

// Deprecated
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisDepA {
    pub tgd: f64,
    // ^ Group delay differential between L1 and L2
    pub c_rs: f64,
    // ^ Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rc: f64,
    // ^ Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_uc: f64,
    // ^ Amplitude of the cosine harmonic correction term to the argument of
    // latitude
    pub c_us: f64,
    // ^ Amplitude of the sine harmonic correction term to the argument of
    // latitude
    pub c_ic: f64,
    // ^ Amplitude of the cosine harmonic correction term to the angle of
    // inclination
    pub c_is: f64,
    // ^ Amplitude of the sine harmonic correction term to the angle of
    // inclination
    pub dn: f64,
    // ^ Mean motion difference
    pub m0: f64,
    // ^ Mean anomaly at reference time
    pub ecc: f64,
    // ^ Eccentricity of satellite orbit
    pub sqrta: f64,
    // ^ Square root of the semi-major axis of orbit
    pub omega0: f64,
    // ^ Longitude of ascending node of orbit plane at weekly epoch
    pub omegadot: f64,
    // ^ Rate of right ascension
    pub w: f64,
    // ^ Argument of perigee
    pub inc: f64,
    // ^ Inclination
    pub inc_dot: f64,
    // ^ Inclination first derivative
    pub af0: f64,
    // ^ Polynomial clock correction coefficient (clock bias)
    pub af1: f64,
    // ^ Polynomial clock correction coefficient (clock drift)
    pub af2: f64,
    // ^ Polynomial clock correction coefficient (rate of clock drift)
    pub toe_tow: f64,
    // ^ Time of week
    pub toe_wn: u16,
    // ^ Week number
    pub toc_tow: f64,
    // ^ Clock reference time of week
    pub toc_wn: u16,
    // ^ Clock reference week number
    pub valid: u8,
    // ^ Is valid?
    pub healthy: u8,
    // ^ Satellite is healthy?
    pub prn: u8,
    // ^ PRN being tracked
}

impl MsgEphemerisDepA {
    pub const TYPE: u16 = 26;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisDepA, ::parser::MessageError> {
        Ok(MsgEphemerisDepA {
            tgd: _buf.read_f64::<LittleEndian>()?,
            c_rs: _buf.read_f64::<LittleEndian>()?,
            c_rc: _buf.read_f64::<LittleEndian>()?,
            c_uc: _buf.read_f64::<LittleEndian>()?,
            c_us: _buf.read_f64::<LittleEndian>()?,
            c_ic: _buf.read_f64::<LittleEndian>()?,
            c_is: _buf.read_f64::<LittleEndian>()?,
            dn: _buf.read_f64::<LittleEndian>()?,
            m0: _buf.read_f64::<LittleEndian>()?,
            ecc: _buf.read_f64::<LittleEndian>()?,
            sqrta: _buf.read_f64::<LittleEndian>()?,
            omega0: _buf.read_f64::<LittleEndian>()?,
            omegadot: _buf.read_f64::<LittleEndian>()?,
            w: _buf.read_f64::<LittleEndian>()?,
            inc: _buf.read_f64::<LittleEndian>()?,
            inc_dot: _buf.read_f64::<LittleEndian>()?,
            af0: _buf.read_f64::<LittleEndian>()?,
            af1: _buf.read_f64::<LittleEndian>()?,
            af2: _buf.read_f64::<LittleEndian>()?,
            toe_tow: _buf.read_f64::<LittleEndian>()?,
            toe_wn: _buf.read_u16::<LittleEndian>()?,
            toc_tow: _buf.read_f64::<LittleEndian>()?,
            toc_wn: _buf.read_u16::<LittleEndian>()?,
            valid: _buf.read_u8()?,
            healthy: _buf.read_u8()?,
            prn: _buf.read_u8()?,
        })
    }
}

// Deprecated
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisDepB {
    pub tgd: f64,
    // ^ Group delay differential between L1 and L2
    pub c_rs: f64,
    // ^ Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rc: f64,
    // ^ Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_uc: f64,
    // ^ Amplitude of the cosine harmonic correction term to the argument of
    // latitude
    pub c_us: f64,
    // ^ Amplitude of the sine harmonic correction term to the argument of
    // latitude
    pub c_ic: f64,
    // ^ Amplitude of the cosine harmonic correction term to the angle of
    // inclination
    pub c_is: f64,
    // ^ Amplitude of the sine harmonic correction term to the angle of
    // inclination
    pub dn: f64,
    // ^ Mean motion difference
    pub m0: f64,
    // ^ Mean anomaly at reference time
    pub ecc: f64,
    // ^ Eccentricity of satellite orbit
    pub sqrta: f64,
    // ^ Square root of the semi-major axis of orbit
    pub omega0: f64,
    // ^ Longitude of ascending node of orbit plane at weekly epoch
    pub omegadot: f64,
    // ^ Rate of right ascension
    pub w: f64,
    // ^ Argument of perigee
    pub inc: f64,
    // ^ Inclination
    pub inc_dot: f64,
    // ^ Inclination first derivative
    pub af0: f64,
    // ^ Polynomial clock correction coefficient (clock bias)
    pub af1: f64,
    // ^ Polynomial clock correction coefficient (clock drift)
    pub af2: f64,
    // ^ Polynomial clock correction coefficient (rate of clock drift)
    pub toe_tow: f64,
    // ^ Time of week
    pub toe_wn: u16,
    // ^ Week number
    pub toc_tow: f64,
    // ^ Clock reference time of week
    pub toc_wn: u16,
    // ^ Clock reference week number
    pub valid: u8,
    // ^ Is valid?
    pub healthy: u8,
    // ^ Satellite is healthy?
    pub prn: u8,
    // ^ PRN being tracked
    pub iode: u8,
    // ^ Issue of ephemeris data
}

impl MsgEphemerisDepB {
    pub const TYPE: u16 = 70;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisDepB, ::parser::MessageError> {
        Ok(MsgEphemerisDepB {
            tgd: _buf.read_f64::<LittleEndian>()?,
            c_rs: _buf.read_f64::<LittleEndian>()?,
            c_rc: _buf.read_f64::<LittleEndian>()?,
            c_uc: _buf.read_f64::<LittleEndian>()?,
            c_us: _buf.read_f64::<LittleEndian>()?,
            c_ic: _buf.read_f64::<LittleEndian>()?,
            c_is: _buf.read_f64::<LittleEndian>()?,
            dn: _buf.read_f64::<LittleEndian>()?,
            m0: _buf.read_f64::<LittleEndian>()?,
            ecc: _buf.read_f64::<LittleEndian>()?,
            sqrta: _buf.read_f64::<LittleEndian>()?,
            omega0: _buf.read_f64::<LittleEndian>()?,
            omegadot: _buf.read_f64::<LittleEndian>()?,
            w: _buf.read_f64::<LittleEndian>()?,
            inc: _buf.read_f64::<LittleEndian>()?,
            inc_dot: _buf.read_f64::<LittleEndian>()?,
            af0: _buf.read_f64::<LittleEndian>()?,
            af1: _buf.read_f64::<LittleEndian>()?,
            af2: _buf.read_f64::<LittleEndian>()?,
            toe_tow: _buf.read_f64::<LittleEndian>()?,
            toe_wn: _buf.read_u16::<LittleEndian>()?,
            toc_tow: _buf.read_f64::<LittleEndian>()?,
            toc_wn: _buf.read_u16::<LittleEndian>()?,
            valid: _buf.read_u8()?,
            healthy: _buf.read_u8()?,
            prn: _buf.read_u8()?,
            iode: _buf.read_u8()?,
        })
    }
}

// Satellite broadcast ephemeris
//
// The ephemeris message returns a set of satellite orbit
// parameters that is used to calculate GPS satellite position,
// velocity, and clock offset. Please see the Navstar GPS
// Space Segment/Navigation user interfaces (ICD-GPS-200, Table
// 20-III) for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisDepC {
    pub tgd: f64,
    // ^ Group delay differential between L1 and L2
    pub c_rs: f64,
    // ^ Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rc: f64,
    // ^ Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_uc: f64,
    // ^ Amplitude of the cosine harmonic correction term to the argument of
    // latitude
    pub c_us: f64,
    // ^ Amplitude of the sine harmonic correction term to the argument of
    // latitude
    pub c_ic: f64,
    // ^ Amplitude of the cosine harmonic correction term to the angle of
    // inclination
    pub c_is: f64,
    // ^ Amplitude of the sine harmonic correction term to the angle of
    // inclination
    pub dn: f64,
    // ^ Mean motion difference
    pub m0: f64,
    // ^ Mean anomaly at reference time
    pub ecc: f64,
    // ^ Eccentricity of satellite orbit
    pub sqrta: f64,
    // ^ Square root of the semi-major axis of orbit
    pub omega0: f64,
    // ^ Longitude of ascending node of orbit plane at weekly epoch
    pub omegadot: f64,
    // ^ Rate of right ascension
    pub w: f64,
    // ^ Argument of perigee
    pub inc: f64,
    // ^ Inclination
    pub inc_dot: f64,
    // ^ Inclination first derivative
    pub af0: f64,
    // ^ Polynomial clock correction coefficient (clock bias)
    pub af1: f64,
    // ^ Polynomial clock correction coefficient (clock drift)
    pub af2: f64,
    // ^ Polynomial clock correction coefficient (rate of clock drift)
    pub toe_tow: f64,
    // ^ Time of week
    pub toe_wn: u16,
    // ^ Week number
    pub toc_tow: f64,
    // ^ Clock reference time of week
    pub toc_wn: u16,
    // ^ Clock reference week number
    pub valid: u8,
    // ^ Is valid?
    pub healthy: u8,
    // ^ Satellite is healthy?
    pub sid: GnssSignalDep,
    // ^ GNSS signal identifier
    pub iode: u8,
    // ^ Issue of ephemeris data
    pub iodc: u16,
    // ^ Issue of clock data
    pub reserved: u32,
    // ^ Reserved field
}

impl MsgEphemerisDepC {
    pub const TYPE: u16 = 71;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisDepC, ::parser::MessageError> {
        Ok(MsgEphemerisDepC {
            tgd: _buf.read_f64::<LittleEndian>()?,
            c_rs: _buf.read_f64::<LittleEndian>()?,
            c_rc: _buf.read_f64::<LittleEndian>()?,
            c_uc: _buf.read_f64::<LittleEndian>()?,
            c_us: _buf.read_f64::<LittleEndian>()?,
            c_ic: _buf.read_f64::<LittleEndian>()?,
            c_is: _buf.read_f64::<LittleEndian>()?,
            dn: _buf.read_f64::<LittleEndian>()?,
            m0: _buf.read_f64::<LittleEndian>()?,
            ecc: _buf.read_f64::<LittleEndian>()?,
            sqrta: _buf.read_f64::<LittleEndian>()?,
            omega0: _buf.read_f64::<LittleEndian>()?,
            omegadot: _buf.read_f64::<LittleEndian>()?,
            w: _buf.read_f64::<LittleEndian>()?,
            inc: _buf.read_f64::<LittleEndian>()?,
            inc_dot: _buf.read_f64::<LittleEndian>()?,
            af0: _buf.read_f64::<LittleEndian>()?,
            af1: _buf.read_f64::<LittleEndian>()?,
            af2: _buf.read_f64::<LittleEndian>()?,
            toe_tow: _buf.read_f64::<LittleEndian>()?,
            toe_wn: _buf.read_u16::<LittleEndian>()?,
            toc_tow: _buf.read_f64::<LittleEndian>()?,
            toc_wn: _buf.read_u16::<LittleEndian>()?,
            valid: _buf.read_u8()?,
            healthy: _buf.read_u8()?,
            sid: GnssSignalDep::parse(_buf)?,
            iode: _buf.read_u8()?,
            iodc: _buf.read_u16::<LittleEndian>()?,
            reserved: _buf.read_u32::<LittleEndian>()?,
        })
    }
}

// Header for observation message.
//
// Header of a GPS observation message.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct ObservationHeaderDep {
    pub t: GPSTimeDep,
    // ^ GPS time of this observation
    pub n_obs: u8,
    // ^ Total number of observations. First nibble is the size of the sequence
    // (n), second nibble is the zero-indexed counter (ith packet of n)
}

impl ObservationHeaderDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<ObservationHeaderDep, ::parser::MessageError> {
        Ok(ObservationHeaderDep {
            t: GPSTimeDep::parse(_buf)?,
            n_obs: _buf.read_u8()?,
        })
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<ObservationHeaderDep>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(ObservationHeaderDep::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<ObservationHeaderDep>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(ObservationHeaderDep::parse(buf)?);
        }
        Ok(v)
    }
}

// GPS carrier phase measurement.
//
// Carrier phase measurement in cycles represented as a 40-bit
// fixed point number with Q32.8 layout, i.e. 32-bits of whole
// cycles and 8-bits of fractional cycles. This has the opposite
// sign convention than a typical GPS receiver and the phase has
// the opposite sign as the pseudorange.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct CarrierPhaseDepA {
    pub i: i32,
    // ^ Carrier phase whole cycles
    pub f: u8,
    // ^ Carrier phase fractional part
}

impl CarrierPhaseDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<CarrierPhaseDepA, ::parser::MessageError> {
        Ok(CarrierPhaseDepA {
            i: _buf.read_i32::<LittleEndian>()?,
            f: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<CarrierPhaseDepA>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(CarrierPhaseDepA::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<CarrierPhaseDepA>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(CarrierPhaseDepA::parse(buf)?);
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
pub struct PackedObsContentDepA {
    pub P: u32,
    // ^ Pseudorange observation
    pub L: CarrierPhaseDepA,
    // ^ Carrier phase observation with opposite sign from typical convention
    pub cn0: u8,
    // ^ Carrier-to-Noise density
    pub lock: u16,
    // ^ Lock indicator. This value changes whenever a satellite signal has lost
    // and regained lock, indicating that the carrier phase ambiguity may have
    // changed.
    pub prn: u8,
    // ^ PRN-1 identifier of the satellite signal
}

impl PackedObsContentDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<PackedObsContentDepA, ::parser::MessageError> {
        Ok(PackedObsContentDepA {
            P: _buf.read_u32::<LittleEndian>()?,
            L: CarrierPhaseDepA::parse(_buf)?,
            cn0: _buf.read_u8()?,
            lock: _buf.read_u16::<LittleEndian>()?,
            prn: _buf.read_u8()?,
        })
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<PackedObsContentDepA>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(PackedObsContentDepA::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<PackedObsContentDepA>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(PackedObsContentDepA::parse(buf)?);
        }
        Ok(v)
    }
}

// GPS observations for a particular satellite signal.
//
// Pseudorange and carrier phase observation for a satellite being
// tracked.  Pseudoranges are referenced to a nominal pseudorange.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct PackedObsContentDepB {
    pub P: u32,
    // ^ Pseudorange observation
    pub L: CarrierPhaseDepA,
    // ^ Carrier phase observation with opposite sign from typical convention.
    pub cn0: u8,
    // ^ Carrier-to-Noise density
    pub lock: u16,
    // ^ Lock indicator. This value changes whenever a satellite signal has lost
    // and regained lock, indicating that the carrier phase ambiguity may have
    // changed.
    pub sid: GnssSignalDep,
    // ^ GNSS signal identifier
}

impl PackedObsContentDepB {
    pub fn parse(_buf: &mut &[u8]) -> Result<PackedObsContentDepB, ::parser::MessageError> {
        Ok(PackedObsContentDepB {
            P: _buf.read_u32::<LittleEndian>()?,
            L: CarrierPhaseDepA::parse(_buf)?,
            cn0: _buf.read_u8()?,
            lock: _buf.read_u16::<LittleEndian>()?,
            sid: GnssSignalDep::parse(_buf)?,
        })
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<PackedObsContentDepB>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(PackedObsContentDepB::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<PackedObsContentDepB>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(PackedObsContentDepB::parse(buf)?);
        }
        Ok(v)
    }
}

// GPS observations for a particular satellite signal.
//
// Pseudorange and carrier phase observation for a satellite being
// tracked. The observations are be interoperable with 3rd party
// receivers and conform with typical RTCMv3 GNSS observations.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct PackedObsContentDepC {
    pub P: u32,
    // ^ Pseudorange observation
    pub L: CarrierPhase,
    // ^ Carrier phase observation with typical sign convention.
    pub cn0: u8,
    // ^ Carrier-to-Noise density
    pub lock: u16,
    // ^ Lock indicator. This value changes whenever a satellite signal has lost
    // and regained lock, indicating that the carrier phase ambiguity may have
    // changed.
    pub sid: GnssSignalDep,
    // ^ GNSS signal identifier
}

impl PackedObsContentDepC {
    pub fn parse(_buf: &mut &[u8]) -> Result<PackedObsContentDepC, ::parser::MessageError> {
        Ok(PackedObsContentDepC {
            P: _buf.read_u32::<LittleEndian>()?,
            L: CarrierPhase::parse(_buf)?,
            cn0: _buf.read_u8()?,
            lock: _buf.read_u16::<LittleEndian>()?,
            sid: GnssSignalDep::parse(_buf)?,
        })
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<PackedObsContentDepC>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(PackedObsContentDepC::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<PackedObsContentDepC>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(PackedObsContentDepC::parse(buf)?);
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
pub struct MsgObsDepA {
    pub header: ObservationHeaderDep,
    // ^ Header of a GPS observation message
    pub obs: Vec<PackedObsContentDepA>,
    // ^ Pseudorange and carrier phase observation for a satellite being tracked.
}

impl MsgObsDepA {
    pub const TYPE: u16 = 69;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgObsDepA, ::parser::MessageError> {
        Ok(MsgObsDepA {
            header: ObservationHeaderDep::parse(_buf)?,
            obs: PackedObsContentDepA::parse_array(_buf)?,
        })
    }
}

// Deprecated
//
// This observation message has been deprecated in favor of
// observations that are more interoperable. This message
// should be used for observations referenced to
// a nominal pseudorange which are not interoperable with
// most 3rd party GNSS receievers or typical RTCMv3
// observations.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgObsDepB {
    pub header: ObservationHeaderDep,
    // ^ Header of a GPS observation message
    pub obs: Vec<PackedObsContentDepB>,
    // ^ Pseudorange and carrier phase observation for a satellite being tracked.
}

impl MsgObsDepB {
    pub const TYPE: u16 = 67;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgObsDepB, ::parser::MessageError> {
        Ok(MsgObsDepB {
            header: ObservationHeaderDep::parse(_buf)?,
            obs: PackedObsContentDepB::parse_array(_buf)?,
        })
    }
}

// Deprecated
//
// The GPS observations message reports all the raw pseudorange and
// carrier phase observations for the satellites being tracked by
// the device. Carrier phase observation here is represented as a
// 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
// whole cycles and 8-bits of fractional cycles). The observations
// are interoperable with 3rd party receivers and conform
// with typical RTCMv3 GNSS observations.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgObsDepC {
    pub header: ObservationHeaderDep,
    // ^ Header of a GPS observation message
    pub obs: Vec<PackedObsContentDepC>,
    // ^ Pseudorange and carrier phase observation for a satellite being tracked.
}

impl MsgObsDepC {
    pub const TYPE: u16 = 73;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgObsDepC, ::parser::MessageError> {
        Ok(MsgObsDepC {
            header: ObservationHeaderDep::parse(_buf)?,
            obs: PackedObsContentDepC::parse_array(_buf)?,
        })
    }
}

// Iono corrections
//
// The ionospheric parameters which allow the "L1 only" or "L2 only" user to
// utilize the ionospheric model for computation of the ionospheric delay.
// Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgIono {
    pub t_nmct: GPSTimeSec,
    // ^ Navigation Message Correction Table Valitidy Time
    pub a0: f64,
    pub a1: f64,
    pub a2: f64,
    pub a3: f64,
    pub b0: f64,
    pub b1: f64,
    pub b2: f64,
    pub b3: f64,
}

impl MsgIono {
    pub const TYPE: u16 = 144;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgIono, ::parser::MessageError> {
        Ok(MsgIono {
            t_nmct: GPSTimeSec::parse(_buf)?,
            a0: _buf.read_f64::<LittleEndian>()?,
            a1: _buf.read_f64::<LittleEndian>()?,
            a2: _buf.read_f64::<LittleEndian>()?,
            a3: _buf.read_f64::<LittleEndian>()?,
            b0: _buf.read_f64::<LittleEndian>()?,
            b1: _buf.read_f64::<LittleEndian>()?,
            b2: _buf.read_f64::<LittleEndian>()?,
            b3: _buf.read_f64::<LittleEndian>()?,
        })
    }
}

// L2C capability mask
//
// Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSvConfigurationGPSDep {
    pub t_nmct: GPSTimeSec,
    // ^ Navigation Message Correction Table Valitidy Time
    pub l2c_mask: u32,
    // ^ L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
}

impl MsgSvConfigurationGPSDep {
    pub const TYPE: u16 = 145;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSvConfigurationGPSDep, ::parser::MessageError> {
        Ok(MsgSvConfigurationGPSDep {
            t_nmct: GPSTimeSec::parse(_buf)?,
            l2c_mask: _buf.read_u32::<LittleEndian>()?,
        })
    }
}

#[derive(Debug)]
#[allow(non_snake_case)]
pub struct GnssCapb {
    pub gps_active: u64,
    // ^ GPS SV active mask
    pub gps_l2c: u64,
    // ^ GPS L2C active mask
    pub gps_l5: u64,
    // ^ GPS L5 active mask
    pub glo_active: u32,
    // ^ GLO active mask
    pub glo_l2of: u32,
    // ^ GLO L2OF active mask
    pub glo_l3: u32,
    // ^ GLO L3 active mask
    pub sbas_active: u64,
    // ^ SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
    // https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
    pub sbas_l5: u64,
    // ^ SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
    // https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
    pub bds_active: u64,
    // ^ BDS active mask
    pub bds_d2nav: u64,
    // ^ BDS D2NAV active mask
    pub bds_b2: u64,
    // ^ BDS B2 active mask
    pub bds_b2a: u64,
    // ^ BDS B2A active mask
    pub qzss_active: u32,
    // ^ QZSS active mask
    pub gal_active: u64,
    // ^ GAL active mask
    pub gal_e5: u64,
    // ^ GAL E5 active mask
}

impl GnssCapb {
    pub fn parse(_buf: &mut &[u8]) -> Result<GnssCapb, ::parser::MessageError> {
        Ok(GnssCapb {
            gps_active: _buf.read_u64::<LittleEndian>()?,
            gps_l2c: _buf.read_u64::<LittleEndian>()?,
            gps_l5: _buf.read_u64::<LittleEndian>()?,
            glo_active: _buf.read_u32::<LittleEndian>()?,
            glo_l2of: _buf.read_u32::<LittleEndian>()?,
            glo_l3: _buf.read_u32::<LittleEndian>()?,
            sbas_active: _buf.read_u64::<LittleEndian>()?,
            sbas_l5: _buf.read_u64::<LittleEndian>()?,
            bds_active: _buf.read_u64::<LittleEndian>()?,
            bds_d2nav: _buf.read_u64::<LittleEndian>()?,
            bds_b2: _buf.read_u64::<LittleEndian>()?,
            bds_b2a: _buf.read_u64::<LittleEndian>()?,
            qzss_active: _buf.read_u32::<LittleEndian>()?,
            gal_active: _buf.read_u64::<LittleEndian>()?,
            gal_e5: _buf.read_u64::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GnssCapb>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(GnssCapb::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<GnssCapb>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(GnssCapb::parse(buf)?);
        }
        Ok(v)
    }
}

#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgGnssCapb {
    pub t_nmct: GPSTimeSec,
    // ^ Navigation Message Correction Table Validity Time
    pub gc: GnssCapb,
    // ^ GNSS capabilities masks
}

impl MsgGnssCapb {
    pub const TYPE: u16 = 150;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgGnssCapb, ::parser::MessageError> {
        Ok(MsgGnssCapb {
            t_nmct: GPSTimeSec::parse(_buf)?,
            gc: GnssCapb::parse(_buf)?,
        })
    }
}

// Group Delay
//
// Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgGroupDelayDepA {
    pub t_op: GPSTimeDep,
    // ^ Data Predict Time of Week
    pub prn: u8,
    // ^ Satellite number
    pub valid: u8,
    // ^ bit-field indicating validity of the values, LSB indicating tgd validity
    // etc. 1 = value is valid, 0 = value is not valid.
    pub tgd: i16,
    pub isc_l1ca: i16,
    pub isc_l2c: i16,
}

impl MsgGroupDelayDepA {
    pub const TYPE: u16 = 146;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgGroupDelayDepA, ::parser::MessageError> {
        Ok(MsgGroupDelayDepA {
            t_op: GPSTimeDep::parse(_buf)?,
            prn: _buf.read_u8()?,
            valid: _buf.read_u8()?,
            tgd: _buf.read_i16::<LittleEndian>()?,
            isc_l1ca: _buf.read_i16::<LittleEndian>()?,
            isc_l2c: _buf.read_i16::<LittleEndian>()?,
        })
    }
}

// Group Delay
//
// Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgGroupDelayDepB {
    pub t_op: GPSTimeSec,
    // ^ Data Predict Time of Week
    pub sid: GnssSignalDep,
    // ^ GNSS signal identifier
    pub valid: u8,
    // ^ bit-field indicating validity of the values, LSB indicating tgd validity
    // etc. 1 = value is valid, 0 = value is not valid.
    pub tgd: i16,
    pub isc_l1ca: i16,
    pub isc_l2c: i16,
}

impl MsgGroupDelayDepB {
    pub const TYPE: u16 = 147;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgGroupDelayDepB, ::parser::MessageError> {
        Ok(MsgGroupDelayDepB {
            t_op: GPSTimeSec::parse(_buf)?,
            sid: GnssSignalDep::parse(_buf)?,
            valid: _buf.read_u8()?,
            tgd: _buf.read_i16::<LittleEndian>()?,
            isc_l1ca: _buf.read_i16::<LittleEndian>()?,
            isc_l2c: _buf.read_i16::<LittleEndian>()?,
        })
    }
}

// Group Delay
//
// Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgGroupDelay {
    pub t_op: GPSTimeSec,
    // ^ Data Predict Time of Week
    pub sid: GnssSignal,
    // ^ GNSS signal identifier
    pub valid: u8,
    // ^ bit-field indicating validity of the values, LSB indicating tgd validity
    // etc. 1 = value is valid, 0 = value is not valid.
    pub tgd: i16,
    pub isc_l1ca: i16,
    pub isc_l2c: i16,
}

impl MsgGroupDelay {
    pub const TYPE: u16 = 148;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgGroupDelay, ::parser::MessageError> {
        Ok(MsgGroupDelay {
            t_op: GPSTimeSec::parse(_buf)?,
            sid: GnssSignal::parse(_buf)?,
            valid: _buf.read_u8()?,
            tgd: _buf.read_i16::<LittleEndian>()?,
            isc_l1ca: _buf.read_i16::<LittleEndian>()?,
            isc_l2c: _buf.read_i16::<LittleEndian>()?,
        })
    }
}

#[derive(Debug)]
#[allow(non_snake_case)]
pub struct AlmanacCommonContent {
    pub sid: GnssSignal,
    // ^ GNSS signal identifier
    pub toa: GPSTimeSec,
    // ^ Reference time of almanac
    pub ura: f64,
    // ^ User Range Accuracy
    pub fit_interval: u32,
    // ^ Curve fit interval
    pub valid: u8,
    // ^ Status of almanac, 1 = valid, 0 = invalid
    pub health_bits: u8,
    // ^ Satellite health status for GPS:   - bits 5-7: NAV data health status.
    // See IS-GPS-200H     Table 20-VII: NAV Data Health Indications.   - bits
    // 0-4: Signal health status. See IS-GPS-200H     Table 20-VIII. Codes for
    // Health of SV Signal     Components. Satellite health status for GLO:
    // See GLO ICD 5.1 table 5.1 for details   - bit 0: C(n), "unhealthy" flag
    // that is transmitted within     non-immediate data and indicates overall
    // constellation status     at the moment of almanac uploading.     '0'
    // indicates malfunction of n-satellite.     '1' indicates that n-satellite
    // is operational.   - bit 1: Bn(ln), '0' indicates the satellite is
    // operational     and suitable for navigation.
}

impl AlmanacCommonContent {
    pub fn parse(_buf: &mut &[u8]) -> Result<AlmanacCommonContent, ::parser::MessageError> {
        Ok(AlmanacCommonContent {
            sid: GnssSignal::parse(_buf)?,
            toa: GPSTimeSec::parse(_buf)?,
            ura: _buf.read_f64::<LittleEndian>()?,
            fit_interval: _buf.read_u32::<LittleEndian>()?,
            valid: _buf.read_u8()?,
            health_bits: _buf.read_u8()?,
        })
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<AlmanacCommonContent>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(AlmanacCommonContent::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<AlmanacCommonContent>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(AlmanacCommonContent::parse(buf)?);
        }
        Ok(v)
    }
}

#[derive(Debug)]
#[allow(non_snake_case)]
pub struct AlmanacCommonContentDep {
    pub sid: GnssSignalDep,
    // ^ GNSS signal identifier
    pub toa: GPSTimeSec,
    // ^ Reference time of almanac
    pub ura: f64,
    // ^ User Range Accuracy
    pub fit_interval: u32,
    // ^ Curve fit interval
    pub valid: u8,
    // ^ Status of almanac, 1 = valid, 0 = invalid
    pub health_bits: u8,
    // ^ Satellite health status for GPS:   - bits 5-7: NAV data health status.
    // See IS-GPS-200H     Table 20-VII: NAV Data Health Indications.   - bits
    // 0-4: Signal health status. See IS-GPS-200H     Table 20-VIII. Codes for
    // Health of SV Signal     Components. Satellite health status for GLO:
    // See GLO ICD 5.1 table 5.1 for details   - bit 0: C(n), "unhealthy" flag
    // that is transmitted within     non-immediate data and indicates overall
    // constellation status     at the moment of almanac uploading.     '0'
    // indicates malfunction of n-satellite.     '1' indicates that n-satellite
    // is operational.   - bit 1: Bn(ln), '0' indicates the satellite is
    // operational     and suitable for navigation.
}

impl AlmanacCommonContentDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<AlmanacCommonContentDep, ::parser::MessageError> {
        Ok(AlmanacCommonContentDep {
            sid: GnssSignalDep::parse(_buf)?,
            toa: GPSTimeSec::parse(_buf)?,
            ura: _buf.read_f64::<LittleEndian>()?,
            fit_interval: _buf.read_u32::<LittleEndian>()?,
            valid: _buf.read_u8()?,
            health_bits: _buf.read_u8()?,
        })
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<AlmanacCommonContentDep>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(AlmanacCommonContentDep::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<AlmanacCommonContentDep>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(AlmanacCommonContentDep::parse(buf)?);
        }
        Ok(v)
    }
}

// Satellite broadcast ephemeris for GPS
//
// The almanac message returns a set of satellite orbit parameters. Almanac
// data is not very precise and is considered valid for up to several months.
// Please see the Navstar GPS Space Segment/Navigation user interfaces
// (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgAlmanacGPSDep {
    pub common: AlmanacCommonContentDep,
    // ^ Values common for all almanac types
    pub m0: f64,
    // ^ Mean anomaly at reference time
    pub ecc: f64,
    // ^ Eccentricity of satellite orbit
    pub sqrta: f64,
    // ^ Square root of the semi-major axis of orbit
    pub omega0: f64,
    // ^ Longitude of ascending node of orbit plane at weekly epoch
    pub omegadot: f64,
    // ^ Rate of right ascension
    pub w: f64,
    // ^ Argument of perigee
    pub inc: f64,
    // ^ Inclination
    pub af0: f64,
    // ^ Polynomial clock correction coefficient (clock bias)
    pub af1: f64,
    // ^ Polynomial clock correction coefficient (clock drift)
}

impl MsgAlmanacGPSDep {
    pub const TYPE: u16 = 112;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAlmanacGPSDep, ::parser::MessageError> {
        Ok(MsgAlmanacGPSDep {
            common: AlmanacCommonContentDep::parse(_buf)?,
            m0: _buf.read_f64::<LittleEndian>()?,
            ecc: _buf.read_f64::<LittleEndian>()?,
            sqrta: _buf.read_f64::<LittleEndian>()?,
            omega0: _buf.read_f64::<LittleEndian>()?,
            omegadot: _buf.read_f64::<LittleEndian>()?,
            w: _buf.read_f64::<LittleEndian>()?,
            inc: _buf.read_f64::<LittleEndian>()?,
            af0: _buf.read_f64::<LittleEndian>()?,
            af1: _buf.read_f64::<LittleEndian>()?,
        })
    }
}

// Satellite broadcast ephemeris for GPS
//
// The almanac message returns a set of satellite orbit parameters. Almanac
// data is not very precise and is considered valid for up to several months.
// Please see the Navstar GPS Space Segment/Navigation user interfaces
// (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgAlmanacGPS {
    pub common: AlmanacCommonContent,
    // ^ Values common for all almanac types
    pub m0: f64,
    // ^ Mean anomaly at reference time
    pub ecc: f64,
    // ^ Eccentricity of satellite orbit
    pub sqrta: f64,
    // ^ Square root of the semi-major axis of orbit
    pub omega0: f64,
    // ^ Longitude of ascending node of orbit plane at weekly epoch
    pub omegadot: f64,
    // ^ Rate of right ascension
    pub w: f64,
    // ^ Argument of perigee
    pub inc: f64,
    // ^ Inclination
    pub af0: f64,
    // ^ Polynomial clock correction coefficient (clock bias)
    pub af1: f64,
    // ^ Polynomial clock correction coefficient (clock drift)
}

impl MsgAlmanacGPS {
    pub const TYPE: u16 = 114;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAlmanacGPS, ::parser::MessageError> {
        Ok(MsgAlmanacGPS {
            common: AlmanacCommonContent::parse(_buf)?,
            m0: _buf.read_f64::<LittleEndian>()?,
            ecc: _buf.read_f64::<LittleEndian>()?,
            sqrta: _buf.read_f64::<LittleEndian>()?,
            omega0: _buf.read_f64::<LittleEndian>()?,
            omegadot: _buf.read_f64::<LittleEndian>()?,
            w: _buf.read_f64::<LittleEndian>()?,
            inc: _buf.read_f64::<LittleEndian>()?,
            af0: _buf.read_f64::<LittleEndian>()?,
            af1: _buf.read_f64::<LittleEndian>()?,
        })
    }
}

// Satellite broadcast ephemeris for GLO
//
// The almanac message returns a set of satellite orbit parameters. Almanac
// data is not very precise and is considered valid for up to several months.
// Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
// almanac" for details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgAlmanacGloDep {
    pub common: AlmanacCommonContentDep,
    // ^ Values common for all almanac types
    pub lambda_na: f64,
    // ^ Longitude of the first ascending node of the orbit in PZ-90.02
    // coordinate system
    pub t_lambda_na: f64,
    // ^ Time of the first ascending node passage
    pub i: f64,
    // ^ Value of inclination at instant of t_lambda
    pub t: f64,
    // ^ Value of Draconian period at instant of t_lambda
    pub t_dot: f64,
    // ^ Rate of change of the Draconian period
    pub epsilon: f64,
    // ^ Eccentricity at instant of t_lambda
    pub omega: f64,
    // ^ Argument of perigee at instant of t_lambda
}

impl MsgAlmanacGloDep {
    pub const TYPE: u16 = 113;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAlmanacGloDep, ::parser::MessageError> {
        Ok(MsgAlmanacGloDep {
            common: AlmanacCommonContentDep::parse(_buf)?,
            lambda_na: _buf.read_f64::<LittleEndian>()?,
            t_lambda_na: _buf.read_f64::<LittleEndian>()?,
            i: _buf.read_f64::<LittleEndian>()?,
            t: _buf.read_f64::<LittleEndian>()?,
            t_dot: _buf.read_f64::<LittleEndian>()?,
            epsilon: _buf.read_f64::<LittleEndian>()?,
            omega: _buf.read_f64::<LittleEndian>()?,
        })
    }
}

// Satellite broadcast ephemeris for GLO
//
// The almanac message returns a set of satellite orbit parameters. Almanac
// data is not very precise and is considered valid for up to several months.
// Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
// almanac" for details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgAlmanacGlo {
    pub common: AlmanacCommonContent,
    // ^ Values common for all almanac types
    pub lambda_na: f64,
    // ^ Longitude of the first ascending node of the orbit in PZ-90.02
    // coordinate system
    pub t_lambda_na: f64,
    // ^ Time of the first ascending node passage
    pub i: f64,
    // ^ Value of inclination at instant of t_lambda
    pub t: f64,
    // ^ Value of Draconian period at instant of t_lambda
    pub t_dot: f64,
    // ^ Rate of change of the Draconian period
    pub epsilon: f64,
    // ^ Eccentricity at instant of t_lambda
    pub omega: f64,
    // ^ Argument of perigee at instant of t_lambda
}

impl MsgAlmanacGlo {
    pub const TYPE: u16 = 115;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAlmanacGlo, ::parser::MessageError> {
        Ok(MsgAlmanacGlo {
            common: AlmanacCommonContent::parse(_buf)?,
            lambda_na: _buf.read_f64::<LittleEndian>()?,
            t_lambda_na: _buf.read_f64::<LittleEndian>()?,
            i: _buf.read_f64::<LittleEndian>()?,
            t: _buf.read_f64::<LittleEndian>()?,
            t_dot: _buf.read_f64::<LittleEndian>()?,
            epsilon: _buf.read_f64::<LittleEndian>()?,
            omega: _buf.read_f64::<LittleEndian>()?,
        })
    }
}

// GLONASS L1/L2 Code-Phase biases
//
// The GLONASS L1/L2 Code-Phase biases allows to perform
// GPS+GLONASS integer ambiguity resolution for baselines
// with mixed receiver types (e.g. receiver of different
// manufacturers)
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgGloBiases {
    pub mask: u8,
    // ^ GLONASS FDMA signals mask
    pub l1ca_bias: i16,
    // ^ GLONASS L1 C/A Code-Phase Bias
    pub l1p_bias: i16,
    // ^ GLONASS L1 P Code-Phase Bias
    pub l2ca_bias: i16,
    // ^ GLONASS L2 C/A Code-Phase Bias
    pub l2p_bias: i16,
    // ^ GLONASS L2 P Code-Phase Bias
}

impl MsgGloBiases {
    pub const TYPE: u16 = 117;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgGloBiases, ::parser::MessageError> {
        Ok(MsgGloBiases {
            mask: _buf.read_u8()?,
            l1ca_bias: _buf.read_i16::<LittleEndian>()?,
            l1p_bias: _buf.read_i16::<LittleEndian>()?,
            l2ca_bias: _buf.read_i16::<LittleEndian>()?,
            l2p_bias: _buf.read_i16::<LittleEndian>()?,
        })
    }
}

// Satellite azimuth and elevation.
//
// Satellite azimuth and elevation.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct SvAzEl {
    pub sid: GnssSignal,
    // ^ GNSS signal identifier
    pub az: u8,
    // ^ Azimuth angle (range 0..179)
    pub el: i8,
    // ^ Elevation angle (range -90..90)
}

impl SvAzEl {
    pub fn parse(_buf: &mut &[u8]) -> Result<SvAzEl, ::parser::MessageError> {
        Ok(SvAzEl {
            sid: GnssSignal::parse(_buf)?,
            az: _buf.read_u8()?,
            el: _buf.read_i8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<SvAzEl>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(SvAzEl::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<SvAzEl>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(SvAzEl::parse(buf)?);
        }
        Ok(v)
    }
}

// Satellite azimuths and elevations
//
// Azimuth and elevation angles of all the visible satellites
// that the device does have ephemeris or almanac for.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSvAzEl {
    pub azel: Vec<SvAzEl>,
    // ^ Azimuth and elevation per satellite
}

impl MsgSvAzEl {
    pub const TYPE: u16 = 151;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSvAzEl, ::parser::MessageError> {
        Ok(MsgSvAzEl {
            azel: SvAzEl::parse_array(_buf)?,
        })
    }
}

// OSR corrections
//
// The OSR message contains network corrections in an observation-like format
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgOsr {
    pub header: ObservationHeader,
    // ^ Header of a GPS observation message
    pub obs: Vec<PackedOsrContent>,
    // ^ Network correction for a satellite signal.
}

impl MsgOsr {
    pub const TYPE: u16 = 1600;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgOsr, ::parser::MessageError> {
        Ok(MsgOsr {
            header: ObservationHeader::parse(_buf)?,
            obs: PackedOsrContent::parse_array(_buf)?,
        })
    }
}
