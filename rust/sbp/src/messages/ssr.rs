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
#[cfg(feature = "serialize")]
use serde::{Deserialize, Serialize};

/// SSR code biases corrections for a particular satellite.
///
/// Code biases are to be added to pseudorange.
/// The corrections conform with typical RTCMv3 MT1059 and 1065.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct CodeBiasesContent {
    /// Signal constellation, band and code
    pub code: u8,
    /// Code bias value
    pub value: i16,
}

impl CodeBiasesContent {
    pub fn parse(_buf: &mut &[u8]) -> Result<CodeBiasesContent, crate::Error> {
        Ok(CodeBiasesContent {
            code: _buf.read_u8()?,
            value: _buf.read_i16::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<CodeBiasesContent>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(CodeBiasesContent::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<CodeBiasesContent>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(CodeBiasesContent::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for CodeBiasesContent {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.code.append_to_sbp_buffer(buf);
        self.value.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.code.sbp_size();
        size += self.value.sbp_size();
        size
    }
}

/// Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages.
///
/// Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages.
/// Also includes an RLE encoded validity list.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
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
    pub fn parse(_buf: &mut &[u8]) -> Result<GridDefinitionHeader, crate::Error> {
        Ok(GridDefinitionHeader {
            region_size_inverse: _buf.read_u8()?,
            area_width: _buf.read_u16::<LittleEndian>()?,
            lat_nw_corner_enc: _buf.read_u16::<LittleEndian>()?,
            lon_nw_corner_enc: _buf.read_u16::<LittleEndian>()?,
            num_msgs: _buf.read_u8()?,
            seq_num: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GridDefinitionHeader>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(GridDefinitionHeader::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<GridDefinitionHeader>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(GridDefinitionHeader::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for GridDefinitionHeader {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.region_size_inverse.append_to_sbp_buffer(buf);
        self.area_width.append_to_sbp_buffer(buf);
        self.lat_nw_corner_enc.append_to_sbp_buffer(buf);
        self.lon_nw_corner_enc.append_to_sbp_buffer(buf);
        self.num_msgs.append_to_sbp_buffer(buf);
        self.seq_num.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.region_size_inverse.sbp_size();
        size += self.area_width.sbp_size();
        size += self.lat_nw_corner_enc.sbp_size();
        size += self.lon_nw_corner_enc.sbp_size();
        size += self.num_msgs.sbp_size();
        size += self.seq_num.sbp_size();
        size
    }
}

/// Correction data for a single grid point.
///
/// Contains one tropo delay (mean and stddev), plus STEC residuals (mean and
/// stddev) for each satellite at the grid point.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct GridElement {
    /// Index of the grid point
    pub index: u16,
    /// Wet and hydrostatic vertical delays (mean, stddev)
    pub tropo_delay_correction: TroposphericDelayCorrection,
    /// STEC residuals for each satellite (mean, stddev)
    pub stec_residuals: Vec<STECResidual>,
}

impl GridElement {
    pub fn parse(_buf: &mut &[u8]) -> Result<GridElement, crate::Error> {
        Ok(GridElement {
            index: _buf.read_u16::<LittleEndian>()?,
            tropo_delay_correction: TroposphericDelayCorrection::parse(_buf)?,
            stec_residuals: STECResidual::parse_array(_buf)?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GridElement>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(GridElement::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<GridElement>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(GridElement::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for GridElement {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.index.append_to_sbp_buffer(buf);
        self.tropo_delay_correction.append_to_sbp_buffer(buf);
        self.stec_residuals.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.index.sbp_size();
        size += self.tropo_delay_correction.sbp_size();
        size += self.stec_residuals.sbp_size();
        size
    }
}

/// Correction data for a single grid point.
///
/// Contains one tropo delay, plus STEC residuals for each satellite at the
/// grid point.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct GridElementNoStd {
    /// Index of the grid point
    pub index: u16,
    /// Wet and hydrostatic vertical delays
    pub tropo_delay_correction: TroposphericDelayCorrectionNoStd,
    /// STEC residuals for each satellite
    pub stec_residuals: Vec<STECResidualNoStd>,
}

impl GridElementNoStd {
    pub fn parse(_buf: &mut &[u8]) -> Result<GridElementNoStd, crate::Error> {
        Ok(GridElementNoStd {
            index: _buf.read_u16::<LittleEndian>()?,
            tropo_delay_correction: TroposphericDelayCorrectionNoStd::parse(_buf)?,
            stec_residuals: STECResidualNoStd::parse_array(_buf)?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GridElementNoStd>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(GridElementNoStd::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<GridElementNoStd>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(GridElementNoStd::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for GridElementNoStd {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.index.append_to_sbp_buffer(buf);
        self.tropo_delay_correction.append_to_sbp_buffer(buf);
        self.stec_residuals.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.index.sbp_size();
        size += self.tropo_delay_correction.sbp_size();
        size += self.stec_residuals.sbp_size();
        size
    }
}

/// Header for MSG_SSR_GRIDDED_CORRECTION
///
/// The 3GPP message contains nested variable length arrays
/// which are not suppported in SBP, so each grid point will
/// be identified by the index.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
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
    pub fn parse(_buf: &mut &[u8]) -> Result<GriddedCorrectionHeader, crate::Error> {
        Ok(GriddedCorrectionHeader {
            time: GPSTimeSec::parse(_buf)?,
            num_msgs: _buf.read_u16::<LittleEndian>()?,
            seq_num: _buf.read_u16::<LittleEndian>()?,
            update_interval: _buf.read_u8()?,
            iod_atmo: _buf.read_u8()?,
            tropo_quality_indicator: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GriddedCorrectionHeader>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(GriddedCorrectionHeader::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<GriddedCorrectionHeader>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(GriddedCorrectionHeader::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for GriddedCorrectionHeader {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.time.append_to_sbp_buffer(buf);
        self.num_msgs.append_to_sbp_buffer(buf);
        self.seq_num.append_to_sbp_buffer(buf);
        self.update_interval.append_to_sbp_buffer(buf);
        self.iod_atmo.append_to_sbp_buffer(buf);
        self.tropo_quality_indicator.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.time.sbp_size();
        size += self.num_msgs.sbp_size();
        size += self.seq_num.sbp_size();
        size += self.update_interval.sbp_size();
        size += self.iod_atmo.sbp_size();
        size += self.tropo_quality_indicator.sbp_size();
        size
    }
}

/// Precise code biases correction
///
/// The precise code biases message is to be added
/// to the pseudorange of the corresponding signal
/// to get corrected pseudorange. It is typically
/// an equivalent to the 1059 and 1065 RTCM message types
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrCodeBiases, crate::Error> {
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
    fn get_message_type(&self) -> u16 {
        1505
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

impl crate::serialize::SbpSerialize for MsgSsrCodeBiases {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.time.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.update_interval.append_to_sbp_buffer(buf);
        self.iod_ssr.append_to_sbp_buffer(buf);
        self.biases.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.time.sbp_size();
        size += self.sid.sbp_size();
        size += self.update_interval.sbp_size();
        size += self.iod_ssr.sbp_size();
        size += self.biases.sbp_size();
        size
    }
}

/// Gridded troposphere and STEC residuals
///
/// STEC residuals are per space vehicle, tropo is not.
/// It is typically equivalent to the QZSS CLAS Sub Type 9 messages
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSsrGriddedCorrection {
    pub sender_id: Option<u16>,
    /// Header of a Gridded Correction message
    pub header: GriddedCorrectionHeader,
    /// Tropo and STEC residuals for the given grid point (mean and standard
    /// deviation)
    pub element: GridElement,
}

impl MsgSsrGriddedCorrection {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrGriddedCorrection, crate::Error> {
        Ok(MsgSsrGriddedCorrection {
            sender_id: None,
            header: GriddedCorrectionHeader::parse(_buf)?,
            element: GridElement::parse(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgSsrGriddedCorrection {
    fn get_message_type(&self) -> u16 {
        1530
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

impl crate::serialize::SbpSerialize for MsgSsrGriddedCorrection {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.header.append_to_sbp_buffer(buf);
        self.element.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.header.sbp_size();
        size += self.element.sbp_size();
        size
    }
}

/// Gridded troposphere and STEC residuals
///
/// This message was deprecated when variances (stddev)
/// were added.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgSsrGriddedCorrectionNoStd {
    pub sender_id: Option<u16>,
    /// Header of a Gridded Correction message
    pub header: GriddedCorrectionHeader,
    /// Tropo and STEC residuals for the given grid point
    pub element: GridElementNoStd,
}

impl MsgSsrGriddedCorrectionNoStd {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrGriddedCorrectionNoStd, crate::Error> {
        Ok(MsgSsrGriddedCorrectionNoStd {
            sender_id: None,
            header: GriddedCorrectionHeader::parse(_buf)?,
            element: GridElementNoStd::parse(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgSsrGriddedCorrectionNoStd {
    fn get_message_type(&self) -> u16 {
        1520
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

impl crate::serialize::SbpSerialize for MsgSsrGriddedCorrectionNoStd {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.header.append_to_sbp_buffer(buf);
        self.element.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.header.sbp_size();
        size += self.element.sbp_size();
        size
    }
}

/// Definition of the grid for STEC and tropo messages
///
/// Based on the 3GPP proposal R2-1906781 which is in turn based on
/// OMA-LPPe-ValidityArea from OMA-TS-LPPe-V2_0-20141202-C
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrGridDefinition, crate::Error> {
        Ok(MsgSsrGridDefinition {
            sender_id: None,
            header: GridDefinitionHeader::parse(_buf)?,
            rle_list: crate::parser::read_u8_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgSsrGridDefinition {
    fn get_message_type(&self) -> u16 {
        1525
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

impl crate::serialize::SbpSerialize for MsgSsrGridDefinition {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.header.append_to_sbp_buffer(buf);
        self.rle_list.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.header.sbp_size();
        size += self.rle_list.sbp_size();
        size
    }
}

/// Precise orbit and clock correction
///
/// The precise orbit and clock correction message is
/// to be applied as a delta correction to broadcast
/// ephemeris and is typically an equivalent to the 1060
/// and 1066 RTCM message types
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrOrbitClock, crate::Error> {
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
    fn get_message_type(&self) -> u16 {
        1501
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

impl crate::serialize::SbpSerialize for MsgSsrOrbitClock {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.time.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.update_interval.append_to_sbp_buffer(buf);
        self.iod_ssr.append_to_sbp_buffer(buf);
        self.iod.append_to_sbp_buffer(buf);
        self.radial.append_to_sbp_buffer(buf);
        self.along.append_to_sbp_buffer(buf);
        self.cross.append_to_sbp_buffer(buf);
        self.dot_radial.append_to_sbp_buffer(buf);
        self.dot_along.append_to_sbp_buffer(buf);
        self.dot_cross.append_to_sbp_buffer(buf);
        self.c0.append_to_sbp_buffer(buf);
        self.c1.append_to_sbp_buffer(buf);
        self.c2.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.time.sbp_size();
        size += self.sid.sbp_size();
        size += self.update_interval.sbp_size();
        size += self.iod_ssr.sbp_size();
        size += self.iod.sbp_size();
        size += self.radial.sbp_size();
        size += self.along.sbp_size();
        size += self.cross.sbp_size();
        size += self.dot_radial.sbp_size();
        size += self.dot_along.sbp_size();
        size += self.dot_cross.sbp_size();
        size += self.c0.sbp_size();
        size += self.c1.sbp_size();
        size += self.c2.sbp_size();
        size
    }
}

/// Precise orbit and clock correction
///
/// The precise orbit and clock correction message is
/// to be applied as a delta correction to broadcast
/// ephemeris and is typically an equivalent to the 1060
/// and 1066 RTCM message types
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrOrbitClockDepA, crate::Error> {
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
    fn get_message_type(&self) -> u16 {
        1500
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

impl crate::serialize::SbpSerialize for MsgSsrOrbitClockDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.time.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.update_interval.append_to_sbp_buffer(buf);
        self.iod_ssr.append_to_sbp_buffer(buf);
        self.iod.append_to_sbp_buffer(buf);
        self.radial.append_to_sbp_buffer(buf);
        self.along.append_to_sbp_buffer(buf);
        self.cross.append_to_sbp_buffer(buf);
        self.dot_radial.append_to_sbp_buffer(buf);
        self.dot_along.append_to_sbp_buffer(buf);
        self.dot_cross.append_to_sbp_buffer(buf);
        self.c0.append_to_sbp_buffer(buf);
        self.c1.append_to_sbp_buffer(buf);
        self.c2.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.time.sbp_size();
        size += self.sid.sbp_size();
        size += self.update_interval.sbp_size();
        size += self.iod_ssr.sbp_size();
        size += self.iod.sbp_size();
        size += self.radial.sbp_size();
        size += self.along.sbp_size();
        size += self.cross.sbp_size();
        size += self.dot_radial.sbp_size();
        size += self.dot_along.sbp_size();
        size += self.dot_cross.sbp_size();
        size += self.c0.sbp_size();
        size += self.c1.sbp_size();
        size += self.c2.sbp_size();
        size
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
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrPhaseBiases, crate::Error> {
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
    fn get_message_type(&self) -> u16 {
        1510
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

impl crate::serialize::SbpSerialize for MsgSsrPhaseBiases {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.time.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.update_interval.append_to_sbp_buffer(buf);
        self.iod_ssr.append_to_sbp_buffer(buf);
        self.dispersive_bias.append_to_sbp_buffer(buf);
        self.mw_consistency.append_to_sbp_buffer(buf);
        self.yaw.append_to_sbp_buffer(buf);
        self.yaw_rate.append_to_sbp_buffer(buf);
        self.biases.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.time.sbp_size();
        size += self.sid.sbp_size();
        size += self.update_interval.sbp_size();
        size += self.iod_ssr.sbp_size();
        size += self.dispersive_bias.sbp_size();
        size += self.mw_consistency.sbp_size();
        size += self.yaw.sbp_size();
        size += self.yaw_rate.sbp_size();
        size += self.biases.sbp_size();
        size
    }
}

/// Slant Total Electron Content
///
/// The STEC per space vehicle, given as polynomial approximation for
/// a given grid.  This should be combined with MSG_SSR_GRIDDED_CORRECTION
/// message to get the state space representation of the atmospheric
/// delay. It is typically equivalent to the QZSS CLAS Sub Type 8 messages
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrStecCorrection, crate::Error> {
        Ok(MsgSsrStecCorrection {
            sender_id: None,
            header: STECHeader::parse(_buf)?,
            stec_sat_list: STECSatElement::parse_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgSsrStecCorrection {
    fn get_message_type(&self) -> u16 {
        1515
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

impl crate::serialize::SbpSerialize for MsgSsrStecCorrection {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.header.append_to_sbp_buffer(buf);
        self.stec_sat_list.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.header.sbp_size();
        size += self.stec_sat_list.sbp_size();
        size
    }
}

/// SSR phase biases corrections for a particular satellite.
///
/// Phase biases are to be added to carrier phase measurements.
/// The corrections conform with typical RTCMv3 MT1059 and 1065.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
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
    pub fn parse(_buf: &mut &[u8]) -> Result<PhaseBiasesContent, crate::Error> {
        Ok(PhaseBiasesContent {
            code: _buf.read_u8()?,
            integer_indicator: _buf.read_u8()?,
            widelane_integer_indicator: _buf.read_u8()?,
            discontinuity_counter: _buf.read_u8()?,
            bias: _buf.read_i32::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<PhaseBiasesContent>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(PhaseBiasesContent::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<PhaseBiasesContent>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(PhaseBiasesContent::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for PhaseBiasesContent {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.code.append_to_sbp_buffer(buf);
        self.integer_indicator.append_to_sbp_buffer(buf);
        self.widelane_integer_indicator.append_to_sbp_buffer(buf);
        self.discontinuity_counter.append_to_sbp_buffer(buf);
        self.bias.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.code.sbp_size();
        size += self.integer_indicator.sbp_size();
        size += self.widelane_integer_indicator.sbp_size();
        size += self.discontinuity_counter.sbp_size();
        size += self.bias.sbp_size();
        size
    }
}

/// Header for MSG_SSR_STEC_CORRECTION message
///
/// A full set of STEC information will likely span multiple SBP
/// messages, since SBP message a limited to 255 bytes.  The header
/// is used to tie multiple SBP messages into a sequence.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
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
    pub fn parse(_buf: &mut &[u8]) -> Result<STECHeader, crate::Error> {
        Ok(STECHeader {
            time: GPSTimeSec::parse(_buf)?,
            num_msgs: _buf.read_u8()?,
            seq_num: _buf.read_u8()?,
            update_interval: _buf.read_u8()?,
            iod_atmo: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<STECHeader>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(STECHeader::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<STECHeader>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(STECHeader::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for STECHeader {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.time.append_to_sbp_buffer(buf);
        self.num_msgs.append_to_sbp_buffer(buf);
        self.seq_num.append_to_sbp_buffer(buf);
        self.update_interval.append_to_sbp_buffer(buf);
        self.iod_atmo.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.time.sbp_size();
        size += self.num_msgs.sbp_size();
        size += self.seq_num.sbp_size();
        size += self.update_interval.sbp_size();
        size += self.iod_atmo.sbp_size();
        size
    }
}

/// None
///
/// STEC residual (mean and standard deviation) for the given satellite
/// at the grid point,
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct STECResidual {
    /// space vehicle identifier
    pub sv_id: SvId,
    /// STEC residual
    pub residual: i16,
    /// stddev
    pub stddev: u8,
}

impl STECResidual {
    pub fn parse(_buf: &mut &[u8]) -> Result<STECResidual, crate::Error> {
        Ok(STECResidual {
            sv_id: SvId::parse(_buf)?,
            residual: _buf.read_i16::<LittleEndian>()?,
            stddev: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<STECResidual>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(STECResidual::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<STECResidual>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(STECResidual::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for STECResidual {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sv_id.append_to_sbp_buffer(buf);
        self.residual.append_to_sbp_buffer(buf);
        self.stddev.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sv_id.sbp_size();
        size += self.residual.sbp_size();
        size += self.stddev.sbp_size();
        size
    }
}

/// None
///
/// STEC residual for the given satellite at the grid point.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct STECResidualNoStd {
    /// space vehicle identifier
    pub sv_id: SvId,
    /// STEC residual
    pub residual: i16,
}

impl STECResidualNoStd {
    pub fn parse(_buf: &mut &[u8]) -> Result<STECResidualNoStd, crate::Error> {
        Ok(STECResidualNoStd {
            sv_id: SvId::parse(_buf)?,
            residual: _buf.read_i16::<LittleEndian>()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<STECResidualNoStd>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(STECResidualNoStd::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<STECResidualNoStd>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(STECResidualNoStd::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for STECResidualNoStd {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sv_id.append_to_sbp_buffer(buf);
        self.residual.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sv_id.sbp_size();
        size += self.residual.sbp_size();
        size
    }
}

/// None
///
/// STEC polynomial for the given satellite.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
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
    pub fn parse(_buf: &mut &[u8]) -> Result<STECSatElement, crate::Error> {
        Ok(STECSatElement {
            sv_id: SvId::parse(_buf)?,
            stec_quality_indicator: _buf.read_u8()?,
            stec_coeff: crate::parser::read_s16_array_limit(_buf, 4)?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<STECSatElement>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(STECSatElement::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<STECSatElement>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(STECSatElement::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for STECSatElement {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sv_id.append_to_sbp_buffer(buf);
        self.stec_quality_indicator.append_to_sbp_buffer(buf);
        self.stec_coeff.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sv_id.sbp_size();
        size += self.stec_quality_indicator.sbp_size();
        size += self.stec_coeff.sbp_size();
        size
    }
}

/// None
///
/// Troposphere vertical delays (mean and standard deviation) at the grid
/// point.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct TroposphericDelayCorrection {
    /// Hydrostatic vertical delay
    pub hydro: i16,
    /// Wet vertical delay
    pub wet: i8,
    /// stddev
    pub stddev: u8,
}

impl TroposphericDelayCorrection {
    pub fn parse(_buf: &mut &[u8]) -> Result<TroposphericDelayCorrection, crate::Error> {
        Ok(TroposphericDelayCorrection {
            hydro: _buf.read_i16::<LittleEndian>()?,
            wet: _buf.read_i8()?,
            stddev: _buf.read_u8()?,
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<TroposphericDelayCorrection>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TroposphericDelayCorrection::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TroposphericDelayCorrection>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TroposphericDelayCorrection::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for TroposphericDelayCorrection {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.hydro.append_to_sbp_buffer(buf);
        self.wet.append_to_sbp_buffer(buf);
        self.stddev.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.hydro.sbp_size();
        size += self.wet.sbp_size();
        size += self.stddev.sbp_size();
        size
    }
}

/// None
///
/// Troposphere vertical delays at the grid point.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct TroposphericDelayCorrectionNoStd {
    /// Hydrostatic vertical delay
    pub hydro: i16,
    /// Wet vertical delay
    pub wet: i8,
}

impl TroposphericDelayCorrectionNoStd {
    pub fn parse(_buf: &mut &[u8]) -> Result<TroposphericDelayCorrectionNoStd, crate::Error> {
        Ok(TroposphericDelayCorrectionNoStd {
            hydro: _buf.read_i16::<LittleEndian>()?,
            wet: _buf.read_i8()?,
        })
    }
    pub fn parse_array(
        buf: &mut &[u8],
    ) -> Result<Vec<TroposphericDelayCorrectionNoStd>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(TroposphericDelayCorrectionNoStd::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<TroposphericDelayCorrectionNoStd>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(TroposphericDelayCorrectionNoStd::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for TroposphericDelayCorrectionNoStd {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.hydro.append_to_sbp_buffer(buf);
        self.wet.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.hydro.sbp_size();
        size += self.wet.sbp_size();
        size
    }
}
