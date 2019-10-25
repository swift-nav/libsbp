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
//! Precise State Space Representation (SSR) corrections format

extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
use super::gnss::*;

/// SSR code biases corrections for a particular satellite.
///
/// Code biases are to be added to pseudorange.
/// The corrections conform with typical RTCMv3 MT1059 and 1065.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct CodeBiasesContent {
    /// Signal constellation, band and code
    pub code: u8,
    /// Code bias value
    pub value: i16,
}

impl CodeBiasesContent {
    pub fn parse(_buf: &mut &[u8]) -> Result<CodeBiasesContent, ::Error> {
        Ok(CodeBiasesContent {
            code: _buf.read_u8()?,
            value: _buf.read_i16::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<CodeBiasesContent>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(CodeBiasesContent::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<CodeBiasesContent>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(CodeBiasesContent::parse(buf)?);
        }
        Ok(v)
    }
}

/// SSR phase biases corrections for a particular satellite.
///
/// Phase biases are to be added to carrier phase measurements.
/// The corrections conform with typical RTCMv3 MT1059 and 1065.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct PhaseBiasesContent {
    /// Signal constellation, band and code
    pub code: u8,
    /// Indicator for integer property
    pub integer_indicator: u8,
    /// Indicator for two groups of Wide-Lane(s) integer property
    pub widelane_integer_indicator: u8,
    /// Signal phase discontinuity counter. Increased for every discontinuity in
    /// phase.
    pub discontinuity_counter: u8,
    /// Phase bias for specified signal
    pub bias: i32,
}

impl PhaseBiasesContent {
    pub fn parse(_buf: &mut &[u8]) -> Result<PhaseBiasesContent, ::Error> {
        Ok(PhaseBiasesContent {
            code: _buf.read_u8()?,
            integer_indicator: _buf.read_u8()?,
            widelane_integer_indicator: _buf.read_u8()?,
            discontinuity_counter: _buf.read_u8()?,
            bias: _buf.read_i32::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<PhaseBiasesContent>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(PhaseBiasesContent::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<PhaseBiasesContent>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(PhaseBiasesContent::parse(buf)?);
        }
        Ok(v)
    }
}

/// Header for MSG_SSR_STEC_CORRECTION message
///
/// A full set of STEC information will likely span multiple SBP
/// messages, since SBP message a limited to 255 bytes.  The header
/// is used to tie multiple SBP messages into a sequence.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct STECHeader {
    /// GNSS reference time of the correction
    pub time: GPSTimeSec,
    /// Number of messages in the dataset
    pub num_msgs: u8,
    /// Position of this message in the dataset
    pub seq_num: u8,
    /// Update interval between consecutive corrections. Encoded following RTCM
    /// DF391 specification.
    pub update_interval: u8,
    /// IOD of the SSR atmospheric correction
    pub iod_atmo: u8,
}

impl STECHeader {
    pub fn parse(_buf: &mut &[u8]) -> Result<STECHeader, ::Error> {
        Ok(STECHeader {
            time: GPSTimeSec::parse(_buf)?,
            num_msgs: _buf.read_u8()?,
            seq_num: _buf.read_u8()?,
            update_interval: _buf.read_u8()?,
            iod_atmo: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<STECHeader>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(STECHeader::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<STECHeader>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(STECHeader::parse(buf)?);
        }
        Ok(v)
    }
}

/// Header for MSG_SSR_GRIDDED_CORRECTION
///
/// The 3GPP message contains nested variable length arrays
/// which are not suppported in SBP, so each grid point will
/// be identified by the index.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct GriddedCorrectionHeader {
    /// GNSS reference time of the correction
    pub time: GPSTimeSec,
    /// Number of messages in the dataset
    pub num_msgs: u16,
    /// Position of this message in the dataset
    pub seq_num: u16,
    /// Update interval between consecutive corrections. Encoded following RTCM
    /// DF391 specification.
    pub update_interval: u8,
    /// IOD of the SSR atmospheric correction
    pub iod_atmo: u8,
    /// Quality of the troposphere data. Encoded following RTCM DF389
    /// specifcation in units of m.
    pub tropo_quality_indicator: u8,
}

impl GriddedCorrectionHeader {
    pub fn parse(_buf: &mut &[u8]) -> Result<GriddedCorrectionHeader, ::Error> {
        Ok(GriddedCorrectionHeader {
            time: GPSTimeSec::parse(_buf)?,
            num_msgs: _buf.read_u16::<LittleEndian>()?,
            seq_num: _buf.read_u16::<LittleEndian>()?,
            update_interval: _buf.read_u8()?,
            iod_atmo: _buf.read_u8()?,
            tropo_quality_indicator: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GriddedCorrectionHeader>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(GriddedCorrectionHeader::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<GriddedCorrectionHeader>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(GriddedCorrectionHeader::parse(buf)?);
        }
        Ok(v)
    }
}

/// None
///
/// STEC polynomial for the given satellite.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct STECSatElement {
    /// Unique space vehicle identifier
    pub sv_id: SvId,
    /// Quality of the STEC data. Encoded following RTCM DF389 specifcation but
    /// in units of TECU instead of m.
    pub stec_quality_indicator: u8,
    /// Coefficents of the STEC polynomial in the order of C00, C01, C10, C11
    pub stec_coeff: Vec<i16>,
}

impl STECSatElement {
    pub fn parse(_buf: &mut &[u8]) -> Result<STECSatElement, ::Error> {
        Ok(STECSatElement {
            sv_id: SvId::parse(_buf)?,
            stec_quality_indicator: _buf.read_u8()?,
            stec_coeff: ::parser::read_s16_array_limit(_buf, 4)?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<STECSatElement>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(STECSatElement::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<STECSatElement>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(STECSatElement::parse(buf)?);
        }
        Ok(v)
    }
}

/// None
///
/// Troposphere vertical delays at the grid point.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct TroposphericDelayCorrection {
    /// Hydrostatic vertical delay
    pub hydro: i16,
    /// Wet vertical delay
    pub wet: i8,
}

impl TroposphericDelayCorrection {
    pub fn parse(_buf: &mut &[u8]) -> Result<TroposphericDelayCorrection, ::Error> {
        Ok(TroposphericDelayCorrection {
            hydro: _buf.read_i16::<LittleEndian>()?,
            wet: _buf.read_i8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<TroposphericDelayCorrection>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TroposphericDelayCorrection::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TroposphericDelayCorrection>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TroposphericDelayCorrection::parse(buf)?);
        }
        Ok(v)
    }
}

/// None
///
/// STEC residual for the given satellite at the grid point.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct STECResidual {
    /// space vehicle identifier
    pub sv_id: SvId,
    /// STEC residual
    pub residual: i16,
}

impl STECResidual {
    pub fn parse(_buf: &mut &[u8]) -> Result<STECResidual, ::Error> {
        Ok(STECResidual {
            sv_id: SvId::parse(_buf)?,
            residual: _buf.read_i16::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<STECResidual>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(STECResidual::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<STECResidual>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(STECResidual::parse(buf)?);
        }
        Ok(v)
    }
}

/// Correction data for a single grid point.
///
/// Contains one tropo delay, plus STEC residuals for each satellite at the
/// grid point.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct GridElement {
    /// Index of the grid point
    pub index: u16,
    /// Wet and hydrostatic vertical delays
    pub tropo_delay_correction: TroposphericDelayCorrection,
    /// STEC residuals for each satellite
    pub stec_residuals: Vec<STECResidual>,
}

impl GridElement {
    pub fn parse(_buf: &mut &[u8]) -> Result<GridElement, ::Error> {
        Ok(GridElement {
            index: _buf.read_u16::<LittleEndian>()?,
            tropo_delay_correction: TroposphericDelayCorrection::parse(_buf)?,
            stec_residuals: STECResidual::parse_array(_buf)?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GridElement>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(GridElement::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<GridElement>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(GridElement::parse(buf)?);
        }
        Ok(v)
    }
}

/// Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages.
///
/// Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages.
/// Also includes an RLE encoded validity list.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct GridDefinitionHeader {
    /// region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
    pub region_size_inverse: u8,
    /// grid height (deg) = grid idth (deg) = area_width / region_size 0 is an
    /// invalid value.
    pub area_width: u16,
    /// North-West corner latitdue (deg) = region_size * lat_nw_corner_enc - 90
    pub lat_nw_corner_enc: u16,
    /// North-West corner longtitude (deg) = region_size * lon_nw_corner_enc -
    /// 180
    pub lon_nw_corner_enc: u16,
    /// Number of messages in the dataset
    pub num_msgs: u8,
    /// Postion of this message in the dataset
    pub seq_num: u8,
}

impl GridDefinitionHeader {
    pub fn parse(_buf: &mut &[u8]) -> Result<GridDefinitionHeader, ::Error> {
        Ok(GridDefinitionHeader {
            region_size_inverse: _buf.read_u8()?,
            area_width: _buf.read_u16::<LittleEndian>()?,
            lat_nw_corner_enc: _buf.read_u16::<LittleEndian>()?,
            lon_nw_corner_enc: _buf.read_u16::<LittleEndian>()?,
            num_msgs: _buf.read_u8()?,
            seq_num: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GridDefinitionHeader>, ::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(GridDefinitionHeader::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<GridDefinitionHeader>, ::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(GridDefinitionHeader::parse(buf)?);
        }
        Ok(v)
    }
}

/// Precise orbit and clock correction
///
/// The precise orbit and clock correction message is
/// to be applied as a delta correction to broadcast
/// ephemeris and is typically an equivalent to the 1060
/// and 1066 RTCM message types
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSsrOrbitClockDepA {
    pub sender_id: Option<u16>,
    /// GNSS reference time of the correction
    pub time: GPSTimeSec,
    /// GNSS signal identifier (16 bit)
    pub sid: GnssSignal,
    /// Update interval between consecutive corrections. Encoded following RTCM
    /// DF391 specification.
    pub update_interval: u8,
    /// IOD of the SSR correction. A change of Issue Of Data SSR is used to
    /// indicate a change in the SSR generating configuration
    pub iod_ssr: u8,
    /// Issue of broadcast ephemeris data
    pub iod: u8,
    /// Orbit radial delta correction
    pub radial: i32,
    /// Orbit along delta correction
    pub along: i32,
    /// Orbit along delta correction
    pub cross: i32,
    /// Velocity of orbit radial delta correction
    pub dot_radial: i32,
    /// Velocity of orbit along delta correction
    pub dot_along: i32,
    /// Velocity of orbit cross delta correction
    pub dot_cross: i32,
    /// C0 polynomial coefficient for correction of broadcast satellite clock
    pub c0: i32,
    /// C1 polynomial coefficient for correction of broadcast satellite clock
    pub c1: i32,
    /// C2 polynomial coefficient for correction of broadcast satellite clock
    pub c2: i32,
}

impl MsgSsrOrbitClockDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrOrbitClockDepA, ::Error> {
        Ok(MsgSsrOrbitClockDepA {
            sender_id: None,
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
        })
    }
}
impl super::SBPMessage for MsgSsrOrbitClockDepA {
    const MSG_ID: u16 = 1500;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Precise orbit and clock correction
///
/// The precise orbit and clock correction message is
/// to be applied as a delta correction to broadcast
/// ephemeris and is typically an equivalent to the 1060
/// and 1066 RTCM message types
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSsrOrbitClock {
    pub sender_id: Option<u16>,
    /// GNSS reference time of the correction
    pub time: GPSTimeSec,
    /// GNSS signal identifier (16 bit)
    pub sid: GnssSignal,
    /// Update interval between consecutive corrections. Encoded following RTCM
    /// DF391 specification.
    pub update_interval: u8,
    /// IOD of the SSR correction. A change of Issue Of Data SSR is used to
    /// indicate a change in the SSR generating configuration
    pub iod_ssr: u8,
    /// Issue of broadcast ephemeris data or IODCRC (Beidou)
    pub iod: u32,
    /// Orbit radial delta correction
    pub radial: i32,
    /// Orbit along delta correction
    pub along: i32,
    /// Orbit along delta correction
    pub cross: i32,
    /// Velocity of orbit radial delta correction
    pub dot_radial: i32,
    /// Velocity of orbit along delta correction
    pub dot_along: i32,
    /// Velocity of orbit cross delta correction
    pub dot_cross: i32,
    /// C0 polynomial coefficient for correction of broadcast satellite clock
    pub c0: i32,
    /// C1 polynomial coefficient for correction of broadcast satellite clock
    pub c1: i32,
    /// C2 polynomial coefficient for correction of broadcast satellite clock
    pub c2: i32,
}

impl MsgSsrOrbitClock {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrOrbitClock, ::Error> {
        Ok(MsgSsrOrbitClock {
            sender_id: None,
            time: GPSTimeSec::parse(_buf)?,
            sid: GnssSignal::parse(_buf)?,
            update_interval: _buf.read_u8()?,
            iod_ssr: _buf.read_u8()?,
            iod: _buf.read_u32::<LittleEndian>()?,
            radial: _buf.read_i32::<LittleEndian>()?,
            along: _buf.read_i32::<LittleEndian>()?,
            cross: _buf.read_i32::<LittleEndian>()?,
            dot_radial: _buf.read_i32::<LittleEndian>()?,
            dot_along: _buf.read_i32::<LittleEndian>()?,
            dot_cross: _buf.read_i32::<LittleEndian>()?,
            c0: _buf.read_i32::<LittleEndian>()?,
            c1: _buf.read_i32::<LittleEndian>()?,
            c2: _buf.read_i32::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgSsrOrbitClock {
    const MSG_ID: u16 = 1501;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Precise code biases correction
///
/// The precise code biases message is to be added
/// to the pseudorange of the corresponding signal
/// to get corrected pseudorange. It is typically
/// an equivalent to the 1059 and 1065 RTCM message types
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSsrCodeBiases {
    pub sender_id: Option<u16>,
    /// GNSS reference time of the correction
    pub time: GPSTimeSec,
    /// GNSS signal identifier (16 bit)
    pub sid: GnssSignal,
    /// Update interval between consecutive corrections. Encoded following RTCM
    /// DF391 specification.
    pub update_interval: u8,
    /// IOD of the SSR correction. A change of Issue Of Data SSR is used to
    /// indicate a change in the SSR generating configuration
    pub iod_ssr: u8,
    /// Code biases for the different satellite signals
    pub biases: Vec<CodeBiasesContent>,
}

impl MsgSsrCodeBiases {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrCodeBiases, ::Error> {
        Ok(MsgSsrCodeBiases {
            sender_id: None,
            time: GPSTimeSec::parse(_buf)?,
            sid: GnssSignal::parse(_buf)?,
            update_interval: _buf.read_u8()?,
            iod_ssr: _buf.read_u8()?,
            biases: CodeBiasesContent::parse_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgSsrCodeBiases {
    const MSG_ID: u16 = 1505;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Precise phase biases correction
///
/// The precise phase biases message contains the biases
/// to be added to the carrier phase of the corresponding
/// signal to get corrected carrier phase measurement, as
/// well as the satellite yaw angle to be applied to compute
/// the phase wind-up correction.
/// It is typically an equivalent to the 1265 RTCM message types
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSsrPhaseBiases {
    pub sender_id: Option<u16>,
    /// GNSS reference time of the correction
    pub time: GPSTimeSec,
    /// GNSS signal identifier (16 bit)
    pub sid: GnssSignal,
    /// Update interval between consecutive corrections. Encoded following RTCM
    /// DF391 specification.
    pub update_interval: u8,
    /// IOD of the SSR correction. A change of Issue Of Data SSR is used to
    /// indicate a change in the SSR generating configuration
    pub iod_ssr: u8,
    /// Indicator for the dispersive phase biases property.
    pub dispersive_bias: u8,
    /// Consistency indicator for Melbourne-Wubbena linear combinations
    pub mw_consistency: u8,
    /// Satellite yaw angle
    pub yaw: u16,
    /// Satellite yaw angle rate
    pub yaw_rate: i8,
    /// Phase biases corrections for a satellite being tracked.
    pub biases: Vec<PhaseBiasesContent>,
}

impl MsgSsrPhaseBiases {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrPhaseBiases, ::Error> {
        Ok(MsgSsrPhaseBiases {
            sender_id: None,
            time: GPSTimeSec::parse(_buf)?,
            sid: GnssSignal::parse(_buf)?,
            update_interval: _buf.read_u8()?,
            iod_ssr: _buf.read_u8()?,
            dispersive_bias: _buf.read_u8()?,
            mw_consistency: _buf.read_u8()?,
            yaw: _buf.read_u16::<LittleEndian>()?,
            yaw_rate: _buf.read_i8()?,
            biases: PhaseBiasesContent::parse_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgSsrPhaseBiases {
    const MSG_ID: u16 = 1510;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Slant Total Electron Content
///
/// The STEC per space vehicle, given as polynomial approximation for
/// a given grid.  This should be combined with MSG_SSR_GRIDDED_CORRECTION
/// message to get the state space representation of the atmospheric
/// delay. It is typically equivalent to the QZSS CLAS Sub Type 8 messages
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSsrStecCorrection {
    pub sender_id: Option<u16>,
    /// Header of a STEC message
    pub header: STECHeader,
    /// Array of STEC information for each space vehicle
    pub stec_sat_list: Vec<STECSatElement>,
}

impl MsgSsrStecCorrection {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrStecCorrection, ::Error> {
        Ok(MsgSsrStecCorrection {
            sender_id: None,
            header: STECHeader::parse(_buf)?,
            stec_sat_list: STECSatElement::parse_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgSsrStecCorrection {
    const MSG_ID: u16 = 1515;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Gridded troposphere and STEC residuals
///
/// STEC residuals are per space vehicle, tropo is not.
/// It is typically equivalent to the QZSS CLAS Sub Type 9 messages
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSsrGriddedCorrection {
    pub sender_id: Option<u16>,
    /// Header of a Gridded Correction message
    pub header: GriddedCorrectionHeader,
    /// Tropo and STEC residuals for the given grid point
    pub element: GridElement,
}

impl MsgSsrGriddedCorrection {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrGriddedCorrection, ::Error> {
        Ok(MsgSsrGriddedCorrection {
            sender_id: None,
            header: GriddedCorrectionHeader::parse(_buf)?,
            element: GridElement::parse(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgSsrGriddedCorrection {
    const MSG_ID: u16 = 1520;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Definition of the grid for STEC and tropo messages
///
/// Based on the 3GPP proposal R2-1906781 which is in turn based on
/// OMA-LPPe-ValidityArea from OMA-TS-LPPe-V2_0-20141202-C
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSsrGridDefinition {
    pub sender_id: Option<u16>,
    /// Header of a Gridded Correction message
    pub header: GridDefinitionHeader,
    /// Run Length Encode list of quadrants that contain valid data. The spec
    /// describes the encoding scheme in detail, but essentially the index of
    /// the quadrants that contain transitions between valid and invalid (and
    /// vice versa) are encoded as u8 integers.
    pub rle_list: Vec<u8>,
}

impl MsgSsrGridDefinition {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrGridDefinition, ::Error> {
        Ok(MsgSsrGridDefinition {
            sender_id: None,
            header: GridDefinitionHeader::parse(_buf)?,
            rle_list: ::parser::read_u8_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgSsrGridDefinition {
    const MSG_ID: u16 = 1525;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}
