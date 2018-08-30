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
use self::byteorder::{LittleEndian,ReadBytesExt};
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
    pub fn parse(_buf: &mut &[u8]) -> Result<ObservationHeader, ::Error> {
        Ok( ObservationHeader{
            t: GPSTime::parse(_buf)?,
            n_obs: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<ObservationHeader>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( ObservationHeader::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<ObservationHeader>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( ObservationHeader::parse(buf)? );
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
    pub fn parse(_buf: &mut &[u8]) -> Result<Doppler, ::Error> {
        Ok( Doppler{
            i: _buf.read_i16::<LittleEndian>()?,
            f: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<Doppler>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( Doppler::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<Doppler>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( Doppler::parse(buf)? );
        }
        Ok(v)
    }
}


// GNSS observations for a particular satellite signal.
//
// Pseudorange and carrier phase observation for a satellite being
// tracked. The observations are interoperable with 3rd party
// receivers and conform with typical RTCMv3 GNSS observations.
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
    pub fn parse(_buf: &mut &[u8]) -> Result<PackedObsContent, ::Error> {
        Ok( PackedObsContent{
            P: _buf.read_u32::<LittleEndian>()?,
            L: CarrierPhase::parse(_buf)?,
            D: Doppler::parse(_buf)?,
            cn0: _buf.read_u8()?,
            lock: _buf.read_u8()?,
            flags: _buf.read_u8()?,
            sid: GnssSignal::parse(_buf)?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<PackedObsContent>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( PackedObsContent::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<PackedObsContent>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( PackedObsContent::parse(buf)? );
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgObs, ::Error> {
        Ok( MsgObs{
            header: ObservationHeader::parse(_buf)?,
            obs: PackedObsContent::parse_array(_buf)?,
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBasePosLLH, ::Error> {
        Ok( MsgBasePosLLH{
            lat: _buf.read_f64::<LittleEndian>()?,
            lon: _buf.read_f64::<LittleEndian>()?,
            height: _buf.read_f64::<LittleEndian>()?,
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgBasePosECEF, ::Error> {
        Ok( MsgBasePosECEF{
            x: _buf.read_f64::<LittleEndian>()?,
            y: _buf.read_f64::<LittleEndian>()?,
            z: _buf.read_f64::<LittleEndian>()?,
        } )
    }
}


#[derive(Debug)]
#[allow(non_snake_case)]
pub struct EphemerisCommonContent {
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
        // ^ Satellite health status. GPS: ICD-GPS-200, chapter 20.3.3.3.1.4 SBAS: 0
        // = valid, non-zero = invalid GLO: 0 = valid, non-zero = invalid
}

impl EphemerisCommonContent {
    pub fn parse(_buf: &mut &[u8]) -> Result<EphemerisCommonContent, ::Error> {
        Ok( EphemerisCommonContent{
            sid: GnssSignal::parse(_buf)?,
            toe: GPSTimeSec::parse(_buf)?,
            ura: _buf.read_f64::<LittleEndian>()?,
            fit_interval: _buf.read_u32::<LittleEndian>()?,
            valid: _buf.read_u8()?,
            health_bits: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<EphemerisCommonContent>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( EphemerisCommonContent::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<EphemerisCommonContent>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( EphemerisCommonContent::parse(buf)? );
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
    pub fn parse(_buf: &mut &[u8]) -> Result<EphemerisCommonContentDepA, ::Error> {
        Ok( EphemerisCommonContentDepA{
            sid: GnssSignalDep::parse(_buf)?,
            toe: GPSTimeDep::parse(_buf)?,
            ura: _buf.read_f64::<LittleEndian>()?,
            fit_interval: _buf.read_u32::<LittleEndian>()?,
            valid: _buf.read_u8()?,
            health_bits: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<EphemerisCommonContentDepA>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( EphemerisCommonContentDepA::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<EphemerisCommonContentDepA>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( EphemerisCommonContentDepA::parse(buf)? );
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisGPSDepE, ::Error> {
        Ok( MsgEphemerisGPSDepE{
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
        } )
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

impl MsgEphemerisGPS {
    pub const TYPE: u16 = 134;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisGPS, ::Error> {
        Ok( MsgEphemerisGPS{
            common: EphemerisCommonContent::parse(_buf)?,
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
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisSbasDepA, ::Error> {
        Ok( MsgEphemerisSbasDepA{
            common: EphemerisCommonContentDepA::parse(_buf)?,
            pos: ::read_double_array_limit(_buf, 3)?,
            vel: ::read_double_array_limit(_buf, 3)?,
            acc: ::read_double_array_limit(_buf, 3)?,
            a_gf0: _buf.read_f64::<LittleEndian>()?,
            a_gf1: _buf.read_f64::<LittleEndian>()?,
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisGloDepA, ::Error> {
        Ok( MsgEphemerisGloDepA{
            common: EphemerisCommonContentDepA::parse(_buf)?,
            gamma: _buf.read_f64::<LittleEndian>()?,
            tau: _buf.read_f64::<LittleEndian>()?,
            pos: ::read_double_array_limit(_buf, 3)?,
            vel: ::read_double_array_limit(_buf, 3)?,
            acc: ::read_double_array_limit(_buf, 3)?,
        } )
    }
}


#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgEphemerisSbas {
    pub common: EphemerisCommonContent,
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

impl MsgEphemerisSbas {
    pub const TYPE: u16 = 132;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisSbas, ::Error> {
        Ok( MsgEphemerisSbas{
            common: EphemerisCommonContent::parse(_buf)?,
            pos: ::read_double_array_limit(_buf, 3)?,
            vel: ::read_double_array_limit(_buf, 3)?,
            acc: ::read_double_array_limit(_buf, 3)?,
            a_gf0: _buf.read_f64::<LittleEndian>()?,
            a_gf1: _buf.read_f64::<LittleEndian>()?,
        } )
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
    pub common: EphemerisCommonContent,
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisGloDepB, ::Error> {
        Ok( MsgEphemerisGloDepB{
            common: EphemerisCommonContent::parse(_buf)?,
            gamma: _buf.read_f64::<LittleEndian>()?,
            tau: _buf.read_f64::<LittleEndian>()?,
            pos: ::read_double_array_limit(_buf, 3)?,
            vel: ::read_double_array_limit(_buf, 3)?,
            acc: ::read_double_array_limit(_buf, 3)?,
        } )
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
    pub common: EphemerisCommonContent,
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisGloDepC, ::Error> {
        Ok( MsgEphemerisGloDepC{
            common: EphemerisCommonContent::parse(_buf)?,
            gamma: _buf.read_f64::<LittleEndian>()?,
            tau: _buf.read_f64::<LittleEndian>()?,
            d_tau: _buf.read_f64::<LittleEndian>()?,
            pos: ::read_double_array_limit(_buf, 3)?,
            vel: ::read_double_array_limit(_buf, 3)?,
            acc: ::read_double_array_limit(_buf, 3)?,
            fcn: _buf.read_u8()?,
        } )
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

impl MsgEphemerisGlo {
    pub const TYPE: u16 = 136;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisGlo, ::Error> {
        Ok( MsgEphemerisGlo{
            common: EphemerisCommonContent::parse(_buf)?,
            gamma: _buf.read_f64::<LittleEndian>()?,
            tau: _buf.read_f64::<LittleEndian>()?,
            d_tau: _buf.read_f64::<LittleEndian>()?,
            pos: ::read_double_array_limit(_buf, 3)?,
            vel: ::read_double_array_limit(_buf, 3)?,
            acc: ::read_double_array_limit(_buf, 3)?,
            fcn: _buf.read_u8()?,
            iod: _buf.read_u8()?,
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisDepD, ::Error> {
        Ok( MsgEphemerisDepD{
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
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisDepA, ::Error> {
        Ok( MsgEphemerisDepA{
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
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisDepB, ::Error> {
        Ok( MsgEphemerisDepB{
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
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgEphemerisDepC, ::Error> {
        Ok( MsgEphemerisDepC{
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
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<ObservationHeaderDep, ::Error> {
        Ok( ObservationHeaderDep{
            t: GPSTimeDep::parse(_buf)?,
            n_obs: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<ObservationHeaderDep>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( ObservationHeaderDep::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<ObservationHeaderDep>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( ObservationHeaderDep::parse(buf)? );
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
    pub fn parse(_buf: &mut &[u8]) -> Result<CarrierPhaseDepA, ::Error> {
        Ok( CarrierPhaseDepA{
            i: _buf.read_i32::<LittleEndian>()?,
            f: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<CarrierPhaseDepA>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( CarrierPhaseDepA::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<CarrierPhaseDepA>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( CarrierPhaseDepA::parse(buf)? );
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
    pub fn parse(_buf: &mut &[u8]) -> Result<PackedObsContentDepA, ::Error> {
        Ok( PackedObsContentDepA{
            P: _buf.read_u32::<LittleEndian>()?,
            L: CarrierPhaseDepA::parse(_buf)?,
            cn0: _buf.read_u8()?,
            lock: _buf.read_u16::<LittleEndian>()?,
            prn: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<PackedObsContentDepA>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( PackedObsContentDepA::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<PackedObsContentDepA>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( PackedObsContentDepA::parse(buf)? );
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
    pub fn parse(_buf: &mut &[u8]) -> Result<PackedObsContentDepB, ::Error> {
        Ok( PackedObsContentDepB{
            P: _buf.read_u32::<LittleEndian>()?,
            L: CarrierPhaseDepA::parse(_buf)?,
            cn0: _buf.read_u8()?,
            lock: _buf.read_u16::<LittleEndian>()?,
            sid: GnssSignalDep::parse(_buf)?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<PackedObsContentDepB>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( PackedObsContentDepB::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<PackedObsContentDepB>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( PackedObsContentDepB::parse(buf)? );
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
    pub fn parse(_buf: &mut &[u8]) -> Result<PackedObsContentDepC, ::Error> {
        Ok( PackedObsContentDepC{
            P: _buf.read_u32::<LittleEndian>()?,
            L: CarrierPhase::parse(_buf)?,
            cn0: _buf.read_u8()?,
            lock: _buf.read_u16::<LittleEndian>()?,
            sid: GnssSignalDep::parse(_buf)?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<PackedObsContentDepC>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( PackedObsContentDepC::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<PackedObsContentDepC>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( PackedObsContentDepC::parse(buf)? );
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgObsDepA, ::Error> {
        Ok( MsgObsDepA{
            header: ObservationHeaderDep::parse(_buf)?,
            obs: PackedObsContentDepA::parse_array(_buf)?,
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgObsDepB, ::Error> {
        Ok( MsgObsDepB{
            header: ObservationHeaderDep::parse(_buf)?,
            obs: PackedObsContentDepB::parse_array(_buf)?,
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgObsDepC, ::Error> {
        Ok( MsgObsDepC{
            header: ObservationHeaderDep::parse(_buf)?,
            obs: PackedObsContentDepC::parse_array(_buf)?,
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgIono, ::Error> {
        Ok( MsgIono{
            t_nmct: GPSTimeSec::parse(_buf)?,
            a0: _buf.read_f64::<LittleEndian>()?,
            a1: _buf.read_f64::<LittleEndian>()?,
            a2: _buf.read_f64::<LittleEndian>()?,
            a3: _buf.read_f64::<LittleEndian>()?,
            b0: _buf.read_f64::<LittleEndian>()?,
            b1: _buf.read_f64::<LittleEndian>()?,
            b2: _buf.read_f64::<LittleEndian>()?,
            b3: _buf.read_f64::<LittleEndian>()?,
        } )
    }
}


// L2C capability mask
//
// Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSvConfigurationGPS {
    pub t_nmct: GPSTimeSec,
        // ^ Navigation Message Correction Table Valitidy Time
    pub l2c_mask: u32,
        // ^ L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
}

impl MsgSvConfigurationGPS {
    pub const TYPE: u16 = 145;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSvConfigurationGPS, ::Error> {
        Ok( MsgSvConfigurationGPS{
            t_nmct: GPSTimeSec::parse(_buf)?,
            l2c_mask: _buf.read_u32::<LittleEndian>()?,
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgGroupDelayDepA, ::Error> {
        Ok( MsgGroupDelayDepA{
            t_op: GPSTimeDep::parse(_buf)?,
            prn: _buf.read_u8()?,
            valid: _buf.read_u8()?,
            tgd: _buf.read_i16::<LittleEndian>()?,
            isc_l1ca: _buf.read_i16::<LittleEndian>()?,
            isc_l2c: _buf.read_i16::<LittleEndian>()?,
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgGroupDelayDepB, ::Error> {
        Ok( MsgGroupDelayDepB{
            t_op: GPSTimeSec::parse(_buf)?,
            sid: GnssSignalDep::parse(_buf)?,
            valid: _buf.read_u8()?,
            tgd: _buf.read_i16::<LittleEndian>()?,
            isc_l1ca: _buf.read_i16::<LittleEndian>()?,
            isc_l2c: _buf.read_i16::<LittleEndian>()?,
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgGroupDelay, ::Error> {
        Ok( MsgGroupDelay{
            t_op: GPSTimeSec::parse(_buf)?,
            sid: GnssSignal::parse(_buf)?,
            valid: _buf.read_u8()?,
            tgd: _buf.read_i16::<LittleEndian>()?,
            isc_l1ca: _buf.read_i16::<LittleEndian>()?,
            isc_l2c: _buf.read_i16::<LittleEndian>()?,
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<AlmanacCommonContent, ::Error> {
        Ok( AlmanacCommonContent{
            sid: GnssSignal::parse(_buf)?,
            toa: GPSTimeSec::parse(_buf)?,
            ura: _buf.read_f64::<LittleEndian>()?,
            fit_interval: _buf.read_u32::<LittleEndian>()?,
            valid: _buf.read_u8()?,
            health_bits: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<AlmanacCommonContent>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( AlmanacCommonContent::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<AlmanacCommonContent>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( AlmanacCommonContent::parse(buf)? );
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
    pub fn parse(_buf: &mut &[u8]) -> Result<AlmanacCommonContentDep, ::Error> {
        Ok( AlmanacCommonContentDep{
            sid: GnssSignalDep::parse(_buf)?,
            toa: GPSTimeSec::parse(_buf)?,
            ura: _buf.read_f64::<LittleEndian>()?,
            fit_interval: _buf.read_u32::<LittleEndian>()?,
            valid: _buf.read_u8()?,
            health_bits: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<AlmanacCommonContentDep>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push( AlmanacCommonContentDep::parse(buf)? );
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<AlmanacCommonContentDep>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push( AlmanacCommonContentDep::parse(buf)? );
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAlmanacGPSDep, ::Error> {
        Ok( MsgAlmanacGPSDep{
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
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAlmanacGPS, ::Error> {
        Ok( MsgAlmanacGPS{
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
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAlmanacGloDep, ::Error> {
        Ok( MsgAlmanacGloDep{
            common: AlmanacCommonContentDep::parse(_buf)?,
            lambda_na: _buf.read_f64::<LittleEndian>()?,
            t_lambda_na: _buf.read_f64::<LittleEndian>()?,
            i: _buf.read_f64::<LittleEndian>()?,
            t: _buf.read_f64::<LittleEndian>()?,
            t_dot: _buf.read_f64::<LittleEndian>()?,
            epsilon: _buf.read_f64::<LittleEndian>()?,
            omega: _buf.read_f64::<LittleEndian>()?,
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAlmanacGlo, ::Error> {
        Ok( MsgAlmanacGlo{
            common: AlmanacCommonContent::parse(_buf)?,
            lambda_na: _buf.read_f64::<LittleEndian>()?,
            t_lambda_na: _buf.read_f64::<LittleEndian>()?,
            i: _buf.read_f64::<LittleEndian>()?,
            t: _buf.read_f64::<LittleEndian>()?,
            t_dot: _buf.read_f64::<LittleEndian>()?,
            epsilon: _buf.read_f64::<LittleEndian>()?,
            omega: _buf.read_f64::<LittleEndian>()?,
        } )
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgGloBiases, ::Error> {
        Ok( MsgGloBiases{
            mask: _buf.read_u8()?,
            l1ca_bias: _buf.read_i16::<LittleEndian>()?,
            l1p_bias: _buf.read_i16::<LittleEndian>()?,
            l2ca_bias: _buf.read_i16::<LittleEndian>()?,
            l2p_bias: _buf.read_i16::<LittleEndian>()?,
        } )
    }
}

