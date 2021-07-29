// Copyright (C) 2015-2021 Swift Navigation Inc.
// Contact: https://support.swiftnav.com
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

#[allow(unused_imports)]
use std::convert::TryFrom;

#[allow(unused_imports)]
use byteorder::{LittleEndian, ReadBytesExt};

use super::gnss::*;
#[allow(unused_imports)]
use crate::serialize::SbpSerialize;
#[allow(unused_imports)]
use crate::SbpString;

/// SSR code biases corrections for a particular satellite
///
/// Code biases are to be added to pseudorange. The corrections conform with
/// RTCMv3 MT 1059 / 1065.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct CodeBiasesContent {
    /// Signal encoded following RTCM specifications (DF380, DF381, DF382 and
    /// DF467).
    pub code: u8,
    /// Code bias value
    pub value: i16,
}

impl CodeBiasesContent {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<CodeBiasesContent, crate::Error> {
        Ok( CodeBiasesContent{
            code: _buf.read_u8()?,
            value: _buf.read_i16::<LittleEndian>()?,
        } )
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

/// Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages
///
/// Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes an
/// RLE encoded validity list.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct GridDefinitionHeaderDepA {
    /// region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
    pub region_size_inverse: u8,
    /// grid height (deg) = grid width (deg) = area_width / region_size 0 is an
    /// invalid value.
    pub area_width: u16,
    /// North-West corner latitude (deg) = region_size * lat_nw_corner_enc - 90
    pub lat_nw_corner_enc: u16,
    /// North-West corner longitude (deg) = region_size * lon_nw_corner_enc -
    /// 180
    pub lon_nw_corner_enc: u16,
    /// Number of messages in the dataset
    pub num_msgs: u8,
    /// Position of this message in the dataset
    pub seq_num: u8,
}

impl GridDefinitionHeaderDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<GridDefinitionHeaderDepA, crate::Error> {
        Ok( GridDefinitionHeaderDepA{
            region_size_inverse: _buf.read_u8()?,
            area_width: _buf.read_u16::<LittleEndian>()?,
            lat_nw_corner_enc: _buf.read_u16::<LittleEndian>()?,
            lon_nw_corner_enc: _buf.read_u16::<LittleEndian>()?,
            num_msgs: _buf.read_u8()?,
            seq_num: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GridDefinitionHeaderDepA>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(GridDefinitionHeaderDepA::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<GridDefinitionHeaderDepA>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(GridDefinitionHeaderDepA::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for GridDefinitionHeaderDepA {
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

/// Correction data for a single grid point
///
/// Contains one tropo delay (mean and stddev), plus STEC residuals (mean and
/// stddev) for each satellite at the grid point.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
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
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<GridElement, crate::Error> {
        Ok( GridElement{
            index: _buf.read_u16::<LittleEndian>()?,
            tropo_delay_correction: TroposphericDelayCorrection::parse(_buf)?,
            stec_residuals: STECResidual::parse_array(_buf)?,
        } )
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

/// Correction data for a single grid point
///
/// Contains one tropo delay, plus STEC residuals for each satellite at the
/// grid point.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
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
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<GridElementNoStd, crate::Error> {
        Ok( GridElementNoStd{
            index: _buf.read_u16::<LittleEndian>()?,
            tropo_delay_correction: TroposphericDelayCorrectionNoStd::parse(_buf)?,
            stec_residuals: STECResidualNoStd::parse_array(_buf)?,
        } )
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

/// Header for the MSG_SSR_GRIDDED_CORRECTION message
///
/// The LPP message contains nested variable length arrays which are not
/// supported in SBP, so each grid point will be identified by the index.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct GriddedCorrectionHeader {
    /// Unique identifier of the tile set this tile belongs to.
    pub tile_set_id: u16,
    /// Unique identifier of this tile in the tile set.
    pub tile_id: u16,
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
    /// specification in units of m.
    pub tropo_quality_indicator: u8,
}

impl GriddedCorrectionHeader {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<GriddedCorrectionHeader, crate::Error> {
        Ok( GriddedCorrectionHeader{
            tile_set_id: _buf.read_u16::<LittleEndian>()?,
            tile_id: _buf.read_u16::<LittleEndian>()?,
            time: GPSTimeSec::parse(_buf)?,
            num_msgs: _buf.read_u16::<LittleEndian>()?,
            seq_num: _buf.read_u16::<LittleEndian>()?,
            update_interval: _buf.read_u8()?,
            iod_atmo: _buf.read_u8()?,
            tropo_quality_indicator: _buf.read_u8()?,
        } )
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
        self.tile_set_id.append_to_sbp_buffer(buf);
        self.tile_id.append_to_sbp_buffer(buf);
        self.time.append_to_sbp_buffer(buf);
        self.num_msgs.append_to_sbp_buffer(buf);
        self.seq_num.append_to_sbp_buffer(buf);
        self.update_interval.append_to_sbp_buffer(buf);
        self.iod_atmo.append_to_sbp_buffer(buf);
        self.tropo_quality_indicator.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tile_set_id.sbp_size();
        size += self.tile_id.sbp_size();
        size += self.time.sbp_size();
        size += self.num_msgs.sbp_size();
        size += self.seq_num.sbp_size();
        size += self.update_interval.sbp_size();
        size += self.iod_atmo.sbp_size();
        size += self.tropo_quality_indicator.sbp_size();
        size
    }
}

/// Header for MSG_SSR_GRIDDED_CORRECTION_DEP
///
/// The 3GPP message contains nested variable length arrays which are not
/// supported in SBP, so each grid point will be identified by the index.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct GriddedCorrectionHeaderDepA {
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
    /// specification in units of m.
    pub tropo_quality_indicator: u8,
}

impl GriddedCorrectionHeaderDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<GriddedCorrectionHeaderDepA, crate::Error> {
        Ok( GriddedCorrectionHeaderDepA{
            time: GPSTimeSec::parse(_buf)?,
            num_msgs: _buf.read_u16::<LittleEndian>()?,
            seq_num: _buf.read_u16::<LittleEndian>()?,
            update_interval: _buf.read_u8()?,
            iod_atmo: _buf.read_u8()?,
            tropo_quality_indicator: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GriddedCorrectionHeaderDepA>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(GriddedCorrectionHeaderDepA::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<GriddedCorrectionHeaderDepA>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(GriddedCorrectionHeaderDepA::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for GriddedCorrectionHeaderDepA {
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
/// The precise code biases message is to be added to the pseudorange of the
/// corresponding signal to get corrected pseudorange. It is an equivalent to
/// the 1059 / 1065 RTCM message types.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrCodeBiases {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
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
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrCodeBiases, crate::Error> {
        Ok( MsgSsrCodeBiases{
            sender_id: None,
            time: GPSTimeSec::parse(_buf)?,
            sid: GnssSignal::parse(_buf)?,
            update_interval: _buf.read_u8()?,
            iod_ssr: _buf.read_u8()?,
            biases: CodeBiasesContent::parse_array(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSsrCodeBiases {
    fn get_message_name(&self) -> &'static str {
        "MSG_SSR_CODE_BIASES"
    }

    fn get_message_type(&self) -> u16 {
        1505
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSsrCodeBiases {
    const MESSAGE_TYPE: u16 = 1505;
    const MESSAGE_NAME: &'static str = "MSG_SSR_CODE_BIASES";
}
impl TryFrom<super::SBP> for MsgSsrCodeBiases {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSsrCodeBiases(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
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

/// Gridded troposphere and STEC correction residuals
///
/// STEC residuals are per space vehicle, troposphere is not.
///
/// It is typically equivalent to the QZSS CLAS Sub Type 9 messages.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrGriddedCorrection {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a gridded correction message
    pub header: GriddedCorrectionHeader,
    /// Tropo and STEC residuals for the given grid point.
    pub element: GridElement,
}

impl MsgSsrGriddedCorrection {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrGriddedCorrection, crate::Error> {
        Ok( MsgSsrGriddedCorrection{
            sender_id: None,
            header: GriddedCorrectionHeader::parse(_buf)?,
            element: GridElement::parse(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSsrGriddedCorrection {
    fn get_message_name(&self) -> &'static str {
        "MSG_SSR_GRIDDED_CORRECTION"
    }

    fn get_message_type(&self) -> u16 {
        1532
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSsrGriddedCorrection {
    const MESSAGE_TYPE: u16 = 1532;
    const MESSAGE_NAME: &'static str = "MSG_SSR_GRIDDED_CORRECTION";
}
impl TryFrom<super::SBP> for MsgSsrGriddedCorrection {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSsrGriddedCorrection(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
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

#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrGriddedCorrectionDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a Gridded Correction message
    pub header: GriddedCorrectionHeaderDepA,
    /// Tropo and STEC residuals for the given grid point (mean and standard
    /// deviation)
    pub element: GridElement,
}

impl MsgSsrGriddedCorrectionDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrGriddedCorrectionDepA, crate::Error> {
        Ok( MsgSsrGriddedCorrectionDepA{
            sender_id: None,
            header: GriddedCorrectionHeaderDepA::parse(_buf)?,
            element: GridElement::parse(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSsrGriddedCorrectionDepA {
    fn get_message_name(&self) -> &'static str {
        "MSG_SSR_GRIDDED_CORRECTION_DEP_A"
    }

    fn get_message_type(&self) -> u16 {
        1530
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSsrGriddedCorrectionDepA {
    const MESSAGE_TYPE: u16 = 1530;
    const MESSAGE_NAME: &'static str = "MSG_SSR_GRIDDED_CORRECTION_DEP_A";
}
impl TryFrom<super::SBP> for MsgSsrGriddedCorrectionDepA {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSsrGriddedCorrectionDepA(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSsrGriddedCorrectionDepA {
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

#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrGriddedCorrectionNoStdDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a Gridded Correction message
    pub header: GriddedCorrectionHeaderDepA,
    /// Tropo and STEC residuals for the given grid point
    pub element: GridElementNoStd,
}

impl MsgSsrGriddedCorrectionNoStdDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrGriddedCorrectionNoStdDepA, crate::Error> {
        Ok( MsgSsrGriddedCorrectionNoStdDepA{
            sender_id: None,
            header: GriddedCorrectionHeaderDepA::parse(_buf)?,
            element: GridElementNoStd::parse(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSsrGriddedCorrectionNoStdDepA {
    fn get_message_name(&self) -> &'static str {
        "MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A"
    }

    fn get_message_type(&self) -> u16 {
        1520
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSsrGriddedCorrectionNoStdDepA {
    const MESSAGE_TYPE: u16 = 1520;
    const MESSAGE_NAME: &'static str = "MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A";
}
impl TryFrom<super::SBP> for MsgSsrGriddedCorrectionNoStdDepA {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSsrGriddedCorrectionNoStdDepA(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSsrGriddedCorrectionNoStdDepA {
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

#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrGridDefinitionDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a Gridded Correction message
    pub header: GridDefinitionHeaderDepA,
    /// Run Length Encode list of quadrants that contain valid data. The spec
    /// describes the encoding scheme in detail, but essentially the index of
    /// the quadrants that contain transitions between valid and invalid (and
    /// vice versa) are encoded as u8 integers.
    pub rle_list: Vec<u8>,
}

impl MsgSsrGridDefinitionDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrGridDefinitionDepA, crate::Error> {
        Ok( MsgSsrGridDefinitionDepA{
            sender_id: None,
            header: GridDefinitionHeaderDepA::parse(_buf)?,
            rle_list: crate::parser::read_u8_array(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSsrGridDefinitionDepA {
    fn get_message_name(&self) -> &'static str {
        "MSG_SSR_GRID_DEFINITION_DEP_A"
    }

    fn get_message_type(&self) -> u16 {
        1525
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSsrGridDefinitionDepA {
    const MESSAGE_TYPE: u16 = 1525;
    const MESSAGE_NAME: &'static str = "MSG_SSR_GRID_DEFINITION_DEP_A";
}
impl TryFrom<super::SBP> for MsgSsrGridDefinitionDepA {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSsrGridDefinitionDepA(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSsrGridDefinitionDepA {
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
/// The precise orbit and clock correction message is to be applied as a delta
/// correction to broadcast ephemeris and is an equivalent to the 1060 /1066
/// RTCM message types.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrOrbitClock {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
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
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrOrbitClock, crate::Error> {
        Ok( MsgSsrOrbitClock{
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
        } )
    }
}
impl super::SBPMessage for MsgSsrOrbitClock {
    fn get_message_name(&self) -> &'static str {
        "MSG_SSR_ORBIT_CLOCK"
    }

    fn get_message_type(&self) -> u16 {
        1501
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSsrOrbitClock {
    const MESSAGE_TYPE: u16 = 1501;
    const MESSAGE_NAME: &'static str = "MSG_SSR_ORBIT_CLOCK";
}
impl TryFrom<super::SBP> for MsgSsrOrbitClock {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSsrOrbitClock(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
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

#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrOrbitClockDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
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
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrOrbitClockDepA, crate::Error> {
        Ok( MsgSsrOrbitClockDepA{
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
        } )
    }
}
impl super::SBPMessage for MsgSsrOrbitClockDepA {
    fn get_message_name(&self) -> &'static str {
        "MSG_SSR_ORBIT_CLOCK_DEP_A"
    }

    fn get_message_type(&self) -> u16 {
        1500
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSsrOrbitClockDepA {
    const MESSAGE_TYPE: u16 = 1500;
    const MESSAGE_NAME: &'static str = "MSG_SSR_ORBIT_CLOCK_DEP_A";
}
impl TryFrom<super::SBP> for MsgSsrOrbitClockDepA {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSsrOrbitClockDepA(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
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
/// The precise phase biases message contains the biases to be added to the
/// carrier phase of the corresponding signal to get corrected carrier phase
/// measurement, as well as the satellite yaw angle to be applied to compute
/// the phase wind-up correction. It is typically an equivalent to the 1265
/// RTCM message types.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrPhaseBiases {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
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
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrPhaseBiases, crate::Error> {
        Ok( MsgSsrPhaseBiases{
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
        } )
    }
}
impl super::SBPMessage for MsgSsrPhaseBiases {
    fn get_message_name(&self) -> &'static str {
        "MSG_SSR_PHASE_BIASES"
    }

    fn get_message_type(&self) -> u16 {
        1510
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSsrPhaseBiases {
    const MESSAGE_TYPE: u16 = 1510;
    const MESSAGE_NAME: &'static str = "MSG_SSR_PHASE_BIASES";
}
impl TryFrom<super::SBP> for MsgSsrPhaseBiases {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSsrPhaseBiases(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
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

#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrSatelliteApc {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Satellite antenna phase center corrections
    pub apc: Vec<SatelliteAPC>,
}

impl MsgSsrSatelliteApc {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrSatelliteApc, crate::Error> {
        Ok( MsgSsrSatelliteApc{
            sender_id: None,
            apc: SatelliteAPC::parse_array(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSsrSatelliteApc {
    fn get_message_name(&self) -> &'static str {
        "MSG_SSR_SATELLITE_APC"
    }

    fn get_message_type(&self) -> u16 {
        1540
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSsrSatelliteApc {
    const MESSAGE_TYPE: u16 = 1540;
    const MESSAGE_NAME: &'static str = "MSG_SSR_SATELLITE_APC";
}
impl TryFrom<super::SBP> for MsgSsrSatelliteApc {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSsrSatelliteApc(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSsrSatelliteApc {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.apc.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.apc.sbp_size();
        size
    }
}

/// STEC correction polynomial coefficients
///
/// The Slant Total Electron Content per space vehicle, given as polynomial
/// approximation for a given tile. This should be combined with the
/// MSG_SSR_GRIDDED_CORRECTION message to get the state space representation
/// of the atmospheric delay.
///
/// It is typically equivalent to the QZSS CLAS Sub Type 8 messages.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrStecCorrection {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a STEC polynomial coefficient message.
    pub header: STECHeader,
    /// Array of STEC polynomial coefficients for each space vehicle.
    pub stec_sat_list: Vec<STECSatElement>,
}

impl MsgSsrStecCorrection {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrStecCorrection, crate::Error> {
        Ok( MsgSsrStecCorrection{
            sender_id: None,
            header: STECHeader::parse(_buf)?,
            stec_sat_list: STECSatElement::parse_array(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSsrStecCorrection {
    fn get_message_name(&self) -> &'static str {
        "MSG_SSR_STEC_CORRECTION"
    }

    fn get_message_type(&self) -> u16 {
        1531
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSsrStecCorrection {
    const MESSAGE_TYPE: u16 = 1531;
    const MESSAGE_NAME: &'static str = "MSG_SSR_STEC_CORRECTION";
}
impl TryFrom<super::SBP> for MsgSsrStecCorrection {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSsrStecCorrection(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
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

#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrStecCorrectionDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a STEC message
    pub header: STECHeaderDepA,
    /// Array of STEC information for each space vehicle
    pub stec_sat_list: Vec<STECSatElement>,
}

impl MsgSsrStecCorrectionDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrStecCorrectionDepA, crate::Error> {
        Ok( MsgSsrStecCorrectionDepA{
            sender_id: None,
            header: STECHeaderDepA::parse(_buf)?,
            stec_sat_list: STECSatElement::parse_array(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSsrStecCorrectionDepA {
    fn get_message_name(&self) -> &'static str {
        "MSG_SSR_STEC_CORRECTION_DEP_A"
    }

    fn get_message_type(&self) -> u16 {
        1515
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSsrStecCorrectionDepA {
    const MESSAGE_TYPE: u16 = 1515;
    const MESSAGE_NAME: &'static str = "MSG_SSR_STEC_CORRECTION_DEP_A";
}
impl TryFrom<super::SBP> for MsgSsrStecCorrectionDepA {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSsrStecCorrectionDepA(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSsrStecCorrectionDepA {
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

/// Definition of a SSR atmospheric correction tile.

///
/// Provides the correction point coordinates for the atmospheric correction
/// values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
/// messages.
///
/// Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
/// element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
/// correction points, not lists of points.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrTileDefinition {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Unique identifier of the tile set this tile belongs to.
    pub tile_set_id: u16,
    /// Unique identifier of this tile in the tile set.
    /// See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
    pub tile_id: u16,
    /// North-West corner correction point latitude.
    ///
    /// The relation between the latitude X in the range [-90, 90] and the coded
    /// number N is:
    ///
    /// N = floor((X / 90) * 2^14)
    ///
    /// See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
    pub corner_nw_lat: i16,
    /// North-West corner correction point longitude.
    ///
    /// The relation between the longitude X in the range [-180, 180] and the
    /// coded number N is:
    ///
    /// N = floor((X / 180) * 2^15)
    ///
    /// See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
    pub corner_nw_lon: i16,
    /// Spacing of the correction points in the latitude direction.
    ///
    /// See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
    pub spacing_lat: u16,
    /// Spacing of the correction points in the longitude direction.
    ///
    /// See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
    pub spacing_lon: u16,
    /// Number of steps in the latitude direction.
    ///
    /// See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
    pub rows: u16,
    /// Number of steps in the longitude direction.
    ///
    /// See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
    pub cols: u16,
    /// Specifies the availability of correction data at the correction points
    /// in the array.
    ///
    /// If a specific bit is enabled (set to 1), the correction is not
    /// available. Only the first rows * cols bits are used, the remainder are
    /// set to 0. If there are more then 64 correction points the remaining
    /// corrections are always available.
    ///
    /// Starting with the northwest corner of the array (top left on a north
    /// oriented map) the correction points are enumerated with row precedence -
    /// first row west to east, second row west to east, until last row west to
    /// east - ending with the southeast corner of the array.
    ///
    /// See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note the
    /// definition of the bits is inverted.
    pub bitmask: u64,
}

impl MsgSsrTileDefinition {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSsrTileDefinition, crate::Error> {
        Ok( MsgSsrTileDefinition{
            sender_id: None,
            tile_set_id: _buf.read_u16::<LittleEndian>()?,
            tile_id: _buf.read_u16::<LittleEndian>()?,
            corner_nw_lat: _buf.read_i16::<LittleEndian>()?,
            corner_nw_lon: _buf.read_i16::<LittleEndian>()?,
            spacing_lat: _buf.read_u16::<LittleEndian>()?,
            spacing_lon: _buf.read_u16::<LittleEndian>()?,
            rows: _buf.read_u16::<LittleEndian>()?,
            cols: _buf.read_u16::<LittleEndian>()?,
            bitmask: _buf.read_u64::<LittleEndian>()?,
        } )
    }
}
impl super::SBPMessage for MsgSsrTileDefinition {
    fn get_message_name(&self) -> &'static str {
        "MSG_SSR_TILE_DEFINITION"
    }

    fn get_message_type(&self) -> u16 {
        1526
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgSsrTileDefinition {
    const MESSAGE_TYPE: u16 = 1526;
    const MESSAGE_NAME: &'static str = "MSG_SSR_TILE_DEFINITION";
}
impl TryFrom<super::SBP> for MsgSsrTileDefinition {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSsrTileDefinition(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSsrTileDefinition {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tile_set_id.append_to_sbp_buffer(buf);
        self.tile_id.append_to_sbp_buffer(buf);
        self.corner_nw_lat.append_to_sbp_buffer(buf);
        self.corner_nw_lon.append_to_sbp_buffer(buf);
        self.spacing_lat.append_to_sbp_buffer(buf);
        self.spacing_lon.append_to_sbp_buffer(buf);
        self.rows.append_to_sbp_buffer(buf);
        self.cols.append_to_sbp_buffer(buf);
        self.bitmask.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tile_set_id.sbp_size();
        size += self.tile_id.sbp_size();
        size += self.corner_nw_lat.sbp_size();
        size += self.corner_nw_lon.sbp_size();
        size += self.spacing_lat.sbp_size();
        size += self.spacing_lon.sbp_size();
        size += self.rows.sbp_size();
        size += self.cols.sbp_size();
        size += self.bitmask.sbp_size();
        size
    }
}

/// SSR phase biases corrections for a particular satellite
///
/// Phase biases are to be added to carrier phase measurements.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct PhaseBiasesContent {
    /// Signal encoded following RTCM specifications (DF380, DF381, DF382 and
    /// DF467)
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
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<PhaseBiasesContent, crate::Error> {
        Ok( PhaseBiasesContent{
            code: _buf.read_u8()?,
            integer_indicator: _buf.read_u8()?,
            widelane_integer_indicator: _buf.read_u8()?,
            discontinuity_counter: _buf.read_u8()?,
            bias: _buf.read_i32::<LittleEndian>()?,
        } )
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

/// Header for the MSG_SSR_STEC_CORRECTION message
///
/// A full set of STEC information will likely span multiple SBP messages,
/// since SBP message a limited to 255 bytes.  The header is used to tie
/// multiple SBP messages into a sequence.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct STECHeader {
    /// Unique identifier of the tile set this tile belongs to.
    pub tile_set_id: u16,
    /// Unique identifier of this tile in the tile set.
    pub tile_id: u16,
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
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<STECHeader, crate::Error> {
        Ok( STECHeader{
            tile_set_id: _buf.read_u16::<LittleEndian>()?,
            tile_id: _buf.read_u16::<LittleEndian>()?,
            time: GPSTimeSec::parse(_buf)?,
            num_msgs: _buf.read_u8()?,
            seq_num: _buf.read_u8()?,
            update_interval: _buf.read_u8()?,
            iod_atmo: _buf.read_u8()?,
        } )
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
        self.tile_set_id.append_to_sbp_buffer(buf);
        self.tile_id.append_to_sbp_buffer(buf);
        self.time.append_to_sbp_buffer(buf);
        self.num_msgs.append_to_sbp_buffer(buf);
        self.seq_num.append_to_sbp_buffer(buf);
        self.update_interval.append_to_sbp_buffer(buf);
        self.iod_atmo.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tile_set_id.sbp_size();
        size += self.tile_id.sbp_size();
        size += self.time.sbp_size();
        size += self.num_msgs.sbp_size();
        size += self.seq_num.sbp_size();
        size += self.update_interval.sbp_size();
        size += self.iod_atmo.sbp_size();
        size
    }
}

/// Header for MSG_SSR_STEC_CORRECTION_DEP message
///
/// A full set of STEC information will likely span multiple SBP messages,
/// since SBP message a limited to 255 bytes.  The header is used to tie
/// multiple SBP messages into a sequence.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct STECHeaderDepA {
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

impl STECHeaderDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<STECHeaderDepA, crate::Error> {
        Ok( STECHeaderDepA{
            time: GPSTimeSec::parse(_buf)?,
            num_msgs: _buf.read_u8()?,
            seq_num: _buf.read_u8()?,
            update_interval: _buf.read_u8()?,
            iod_atmo: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<STECHeaderDepA>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(STECHeaderDepA::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<STECHeaderDepA>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(STECHeaderDepA::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for STECHeaderDepA {
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
/// STEC residual (mean and standard deviation) for the given satellite at the
/// grid point.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
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
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<STECResidual, crate::Error> {
        Ok( STECResidual{
            sv_id: SvId::parse(_buf)?,
            residual: _buf.read_i16::<LittleEndian>()?,
            stddev: _buf.read_u8()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct STECResidualNoStd {
    /// space vehicle identifier
    pub sv_id: SvId,
    /// STEC residual
    pub residual: i16,
}

impl STECResidualNoStd {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<STECResidualNoStd, crate::Error> {
        Ok( STECResidualNoStd{
            sv_id: SvId::parse(_buf)?,
            residual: _buf.read_i16::<LittleEndian>()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct STECSatElement {
    /// Unique space vehicle identifier
    pub sv_id: SvId,
    /// Quality of the STEC data. Encoded following RTCM DF389 specification but
    /// in units of TECU instead of m.
    pub stec_quality_indicator: u8,
    /// Coefficients of the STEC polynomial in the order of C00, C01, C10, C11
    pub stec_coeff: Vec<i16>,
}

impl STECSatElement {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<STECSatElement, crate::Error> {
        Ok( STECSatElement{
            sv_id: SvId::parse(_buf)?,
            stec_quality_indicator: _buf.read_u8()?,
            stec_coeff: crate::parser::read_s16_array_limit(_buf, 4)?,
        } )
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

/// Antenna phase center correction
///
/// Contains phase center offset and elevation variation corrections for one
/// signal on a satellite.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct SatelliteAPC {
    /// GNSS signal identifier (16 bit)
    pub sid: GnssSignal,
    /// Additional satellite information
    pub sat_info: u8,
    /// Satellite Code, as defined by IGS. Typically the space vehicle number.
    pub svn: u16,
    /// Mean phase center offset, X Y and Z axes. See IGS ANTEX file format
    /// description for coordinate system definition.
    pub pco: Vec<i16>,
    /// Elevation dependent phase center variations. First element is 0 degrees
    /// separation from the Z axis, subsequent elements represent elevation
    /// variations in 1 degree increments.
    pub pcv: Vec<i8>,
}

impl SatelliteAPC {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<SatelliteAPC, crate::Error> {
        Ok( SatelliteAPC{
            sid: GnssSignal::parse(_buf)?,
            sat_info: _buf.read_u8()?,
            svn: _buf.read_u16::<LittleEndian>()?,
            pco: crate::parser::read_s16_array_limit(_buf, 3)?,
            pcv: crate::parser::read_s8_array_limit(_buf, 21)?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<SatelliteAPC>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(SatelliteAPC::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<SatelliteAPC>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(SatelliteAPC::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for SatelliteAPC {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sid.append_to_sbp_buffer(buf);
        self.sat_info.append_to_sbp_buffer(buf);
        self.svn.append_to_sbp_buffer(buf);
        self.pco.append_to_sbp_buffer(buf);
        self.pcv.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sid.sbp_size();
        size += self.sat_info.sbp_size();
        size += self.svn.sbp_size();
        size += self.pco.sbp_size();
        size += self.pcv.sbp_size();
        size
    }
}

/// None
///
/// Troposphere vertical delays (mean and standard deviation) at the grid
/// point.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
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
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<TroposphericDelayCorrection, crate::Error> {
        Ok( TroposphericDelayCorrection{
            hydro: _buf.read_i16::<LittleEndian>()?,
            wet: _buf.read_i8()?,
            stddev: _buf.read_u8()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct TroposphericDelayCorrectionNoStd {
    /// Hydrostatic vertical delay
    pub hydro: i16,
    /// Wet vertical delay
    pub wet: i8,
}

impl TroposphericDelayCorrectionNoStd {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<TroposphericDelayCorrectionNoStd, crate::Error> {
        Ok( TroposphericDelayCorrectionNoStd{
            hydro: _buf.read_i16::<LittleEndian>()?,
            wet: _buf.read_i8()?,
        } )
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
