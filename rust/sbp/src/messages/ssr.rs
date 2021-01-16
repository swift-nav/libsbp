// Copyright (C) 2015-2018 Swift Navigation Inc.
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

#[cfg(feature = "sbp_serde")]
use serde::{Deserialize, Serialize};

use super::gnss::*;
#[allow(unused_imports)]
use crate::{parser::SbpParse, BoundedSbpString, UnboundedSbpString};

/// SSR code biases corrections for a particular satellite.
///
/// Code biases are to be added to pseudorange.
/// The corrections conform with typical RTCMv3 MT1059 and 1065.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct CodeBiasesContent {
    /// Signal constellation, band and code
    pub code: u8,
    /// Code bias value
    pub value: i16,
}

impl SbpParse<CodeBiasesContent> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<CodeBiasesContent> {
        Ok( CodeBiasesContent{
            code: self.parse()?,
            value: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
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
    /// North-West corner longtitude (deg) = region_size * lon_nw_corner_enc -
    /// 180
    pub lon_nw_corner_enc: u16,
    /// Number of messages in the dataset
    pub num_msgs: u8,
    /// Postion of this message in the dataset
    pub seq_num: u8,
}

impl SbpParse<GridDefinitionHeaderDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<GridDefinitionHeaderDepA> {
        Ok( GridDefinitionHeaderDepA{
            region_size_inverse: self.parse()?,
            area_width: self.parse()?,
            lat_nw_corner_enc: self.parse()?,
            lon_nw_corner_enc: self.parse()?,
            num_msgs: self.parse()?,
            seq_num: self.parse()?,
        } )
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

/// Correction data for a single grid point.
///
/// Contains one tropo delay (mean and stddev), plus STEC residuals (mean and
/// stddev) for each satellite at the grid point.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
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

impl SbpParse<GridElement> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<GridElement> {
        Ok( GridElement{
            index: self.parse()?,
            tropo_delay_correction: self.parse()?,
            stec_residuals: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
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

impl SbpParse<GridElementNoStd> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<GridElementNoStd> {
        Ok( GridElementNoStd{
            index: self.parse()?,
            tropo_delay_correction: self.parse()?,
            stec_residuals: self.parse()?,
        } )
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

/// Header for the MSG_SSR_GRIDDED_CORRECTION message.
///
/// The LPP message contains nested variable length arrays
/// which are not suppported in SBP, so each grid point will
/// be identified by the index.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
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
    /// specifcation in units of m.
    pub tropo_quality_indicator: u8,
}

impl SbpParse<GriddedCorrectionHeader> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<GriddedCorrectionHeader> {
        Ok( GriddedCorrectionHeader{
            tile_set_id: self.parse()?,
            tile_id: self.parse()?,
            time: self.parse()?,
            num_msgs: self.parse()?,
            seq_num: self.parse()?,
            update_interval: self.parse()?,
            iod_atmo: self.parse()?,
            tropo_quality_indicator: self.parse()?,
        } )
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
/// The 3GPP message contains nested variable length arrays
/// which are not suppported in SBP, so each grid point will
/// be identified by the index.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
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
    /// specifcation in units of m.
    pub tropo_quality_indicator: u8,
}

impl SbpParse<GriddedCorrectionHeaderDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<GriddedCorrectionHeaderDepA> {
        Ok( GriddedCorrectionHeaderDepA{
            time: self.parse()?,
            num_msgs: self.parse()?,
            seq_num: self.parse()?,
            update_interval: self.parse()?,
            iod_atmo: self.parse()?,
            tropo_quality_indicator: self.parse()?,
        } )
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
/// The precise code biases message is to be added
/// to the pseudorange of the corresponding signal
/// to get corrected pseudorange. It is typically
/// an equivalent to the 1059 and 1065 RTCM message types
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
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

impl SbpParse<MsgSsrCodeBiases> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSsrCodeBiases> {
        Ok( MsgSsrCodeBiases{
            sender_id: None,
            time: self.parse()?,
            sid: self.parse()?,
            update_interval: self.parse()?,
            iod_ssr: self.parse()?,
            biases: self.parse()?,
        } )
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

/// Gridded troposphere and STEC correction residuals.
///
/// STEC residuals are per space vehicle, troposphere is not.
///
/// It is typically equivalent to the QZSS CLAS Sub Type 9 messages
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrGriddedCorrection {
    pub sender_id: Option<u16>,
    /// Header of a gridded correction message
    pub header: GriddedCorrectionHeader,
    /// Tropo and STEC residuals for the given grid point.
    pub element: GridElement,
}

impl SbpParse<MsgSsrGriddedCorrection> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSsrGriddedCorrection> {
        Ok( MsgSsrGriddedCorrection{
            sender_id: None,
            header: self.parse()?,
            element: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgSsrGriddedCorrection {
    fn get_message_type(&self) -> u16 {
        1532
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

#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrGriddedCorrectionDepA {
    pub sender_id: Option<u16>,
    /// Header of a Gridded Correction message
    pub header: GriddedCorrectionHeaderDepA,
    /// Tropo and STEC residuals for the given grid point (mean and standard
    /// deviation)
    pub element: GridElement,
}

impl SbpParse<MsgSsrGriddedCorrectionDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSsrGriddedCorrectionDepA> {
        Ok( MsgSsrGriddedCorrectionDepA{
            sender_id: None,
            header: self.parse()?,
            element: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgSsrGriddedCorrectionDepA {
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

#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrGriddedCorrectionNoStdDepA {
    pub sender_id: Option<u16>,
    /// Header of a Gridded Correction message
    pub header: GriddedCorrectionHeaderDepA,
    /// Tropo and STEC residuals for the given grid point
    pub element: GridElementNoStd,
}

impl SbpParse<MsgSsrGriddedCorrectionNoStdDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSsrGriddedCorrectionNoStdDepA> {
        Ok( MsgSsrGriddedCorrectionNoStdDepA{
            sender_id: None,
            header: self.parse()?,
            element: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgSsrGriddedCorrectionNoStdDepA {
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

#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrGridDefinitionDepA {
    pub sender_id: Option<u16>,
    /// Header of a Gridded Correction message
    pub header: GridDefinitionHeaderDepA,
    /// Run Length Encode list of quadrants that contain valid data. The spec
    /// describes the encoding scheme in detail, but essentially the index of
    /// the quadrants that contain transitions between valid and invalid (and
    /// vice versa) are encoded as u8 integers.
    pub rle_list: Vec<u8>,
}

impl SbpParse<MsgSsrGridDefinitionDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSsrGridDefinitionDepA> {
        Ok( MsgSsrGridDefinitionDepA{
            sender_id: None,
            header: self.parse()?,
            rle_list: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgSsrGridDefinitionDepA {
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
/// The precise orbit and clock correction message is
/// to be applied as a delta correction to broadcast
/// ephemeris and is typically an equivalent to the 1060
/// and 1066 RTCM message types
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
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

impl SbpParse<MsgSsrOrbitClock> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSsrOrbitClock> {
        Ok( MsgSsrOrbitClock{
            sender_id: None,
            time: self.parse()?,
            sid: self.parse()?,
            update_interval: self.parse()?,
            iod_ssr: self.parse()?,
            iod: self.parse()?,
            radial: self.parse()?,
            along: self.parse()?,
            cross: self.parse()?,
            dot_radial: self.parse()?,
            dot_along: self.parse()?,
            dot_cross: self.parse()?,
            c0: self.parse()?,
            c1: self.parse()?,
            c2: self.parse()?,
        } )
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

#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
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

impl SbpParse<MsgSsrOrbitClockDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSsrOrbitClockDepA> {
        Ok( MsgSsrOrbitClockDepA{
            sender_id: None,
            time: self.parse()?,
            sid: self.parse()?,
            update_interval: self.parse()?,
            iod_ssr: self.parse()?,
            iod: self.parse()?,
            radial: self.parse()?,
            along: self.parse()?,
            cross: self.parse()?,
            dot_radial: self.parse()?,
            dot_along: self.parse()?,
            dot_cross: self.parse()?,
            c0: self.parse()?,
            c1: self.parse()?,
            c2: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
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

impl SbpParse<MsgSsrPhaseBiases> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSsrPhaseBiases> {
        Ok( MsgSsrPhaseBiases{
            sender_id: None,
            time: self.parse()?,
            sid: self.parse()?,
            update_interval: self.parse()?,
            iod_ssr: self.parse()?,
            dispersive_bias: self.parse()?,
            mw_consistency: self.parse()?,
            yaw: self.parse()?,
            yaw_rate: self.parse()?,
            biases: self.parse()?,
        } )
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

/// STEC correction polynomial coeffcients.
///
/// The Slant Total Electron Content per space vehicle, given as polynomial
/// approximation for a given tile. This should be combined with the
/// MSG_SSR_GRIDDED_CORRECTION message to get the state space representation
/// of the atmospheric delay.
///
/// It is typically equivalent to the QZSS CLAS Sub Type 8 messages.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrStecCorrection {
    pub sender_id: Option<u16>,
    /// Header of a STEC polynomial coeffcient message.
    pub header: STECHeader,
    /// Array of STEC polynomial coeffcients for each space vehicle.
    pub stec_sat_list: Vec<STECSatElement>,
}

impl SbpParse<MsgSsrStecCorrection> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSsrStecCorrection> {
        Ok( MsgSsrStecCorrection{
            sender_id: None,
            header: self.parse()?,
            stec_sat_list: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgSsrStecCorrection {
    fn get_message_type(&self) -> u16 {
        1531
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

#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrStecCorrectionDepA {
    pub sender_id: Option<u16>,
    /// Header of a STEC message
    pub header: STECHeaderDepA,
    /// Array of STEC information for each space vehicle
    pub stec_sat_list: Vec<STECSatElement>,
}

impl SbpParse<MsgSsrStecCorrectionDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSsrStecCorrectionDepA> {
        Ok( MsgSsrStecCorrectionDepA{
            sender_id: None,
            header: self.parse()?,
            stec_sat_list: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgSsrStecCorrectionDepA {
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSsrTileDefinition {
    pub sender_id: Option<u16>,
    /// Unique identifier of the tile set this tile belongs to.
    pub tile_set_id: u16,
    /// Unique identifier of this tile in the tile set.  See GNSS-SSR-
    /// ArrayOfCorrectionPoints field correctionPointSetID.
    pub tile_id: u16,
    /// North-West corner correction point latitude.  The relation between the
    /// latitude X in the range [-90, 90] and the coded number N is:  N =
    /// floor((X / 90) * 2^14)  See GNSS-SSR-ArrayOfCorrectionPoints field
    /// referencePointLatitude.
    pub corner_nw_lat: i16,
    /// North-West corner correction point longtitude.  The relation between the
    /// longtitude X in the range [-180, 180] and the coded number N is:  N =
    /// floor((X / 180) * 2^15)  See GNSS-SSR-ArrayOfCorrectionPoints field
    /// referencePointLongitude.
    pub corner_nw_lon: i16,
    /// Spacing of the correction points in the latitude direction.  See GNSS-
    /// SSR-ArrayOfCorrectionPoints field stepOfLatitude.
    pub spacing_lat: u16,
    /// Spacing of the correction points in the longtitude direction.  See GNSS-
    /// SSR-ArrayOfCorrectionPoints field stepOfLongtitude.
    pub spacing_lon: u16,
    /// Number of steps in the latitude direction.  See GNSS-SSR-
    /// ArrayOfCorrectionPoints field numberOfStepsLatitude.
    pub rows: u16,
    /// Number of steps in the longtitude direction.  See GNSS-SSR-
    /// ArrayOfCorrectionPoints field numberOfStepsLongtitude.
    pub cols: u16,
    /// Specifies the availability of correction data at the correction points
    /// in the array.  If a specific bit is enabled (set to 1), the correction
    /// is not available. Only the first rows * cols bits are used, the
    /// remainder are set to 0. If there are more then 64 correction points the
    /// remaining corrections are always available.  Starting with the northwest
    /// corner of the array (top left on a north oriented map) the correction
    /// points are enumerated with row precedence - first row west to east,
    /// second row west to east, until last row west to east - ending with the
    /// southeast corner of the array.  See GNSS-SSR-ArrayOfCorrectionPoints
    /// field bitmaskOfGrids but note the definition of the bits is inverted.
    pub bitmask: u64,
}

impl SbpParse<MsgSsrTileDefinition> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSsrTileDefinition> {
        Ok( MsgSsrTileDefinition{
            sender_id: None,
            tile_set_id: self.parse()?,
            tile_id: self.parse()?,
            corner_nw_lat: self.parse()?,
            corner_nw_lon: self.parse()?,
            spacing_lat: self.parse()?,
            spacing_lon: self.parse()?,
            rows: self.parse()?,
            cols: self.parse()?,
            bitmask: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgSsrTileDefinition {
    fn get_message_type(&self) -> u16 {
        1526
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

/// SSR phase biases corrections for a particular satellite.
///
/// Phase biases are to be added to carrier phase measurements.
/// The corrections conform with typical RTCMv3 MT1059 and 1065.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
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

impl SbpParse<PhaseBiasesContent> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<PhaseBiasesContent> {
        Ok( PhaseBiasesContent{
            code: self.parse()?,
            integer_indicator: self.parse()?,
            widelane_integer_indicator: self.parse()?,
            discontinuity_counter: self.parse()?,
            bias: self.parse()?,
        } )
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

/// Header for the MSG_SSR_STEC_CORRECTION message.
///
/// A full set of STEC information will likely span multiple SBP
/// messages, since SBP message a limited to 255 bytes.  The header
/// is used to tie multiple SBP messages into a sequence.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
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

impl SbpParse<STECHeader> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<STECHeader> {
        Ok( STECHeader{
            tile_set_id: self.parse()?,
            tile_id: self.parse()?,
            time: self.parse()?,
            num_msgs: self.parse()?,
            seq_num: self.parse()?,
            update_interval: self.parse()?,
            iod_atmo: self.parse()?,
        } )
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
/// A full set of STEC information will likely span multiple SBP
/// messages, since SBP message a limited to 255 bytes.  The header
/// is used to tie multiple SBP messages into a sequence.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
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

impl SbpParse<STECHeaderDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<STECHeaderDepA> {
        Ok( STECHeaderDepA{
            time: self.parse()?,
            num_msgs: self.parse()?,
            seq_num: self.parse()?,
            update_interval: self.parse()?,
            iod_atmo: self.parse()?,
        } )
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
/// STEC residual (mean and standard deviation) for the given satellite
/// at the grid point,
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
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

impl SbpParse<STECResidual> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<STECResidual> {
        Ok( STECResidual{
            sv_id: self.parse()?,
            residual: self.parse()?,
            stddev: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct STECResidualNoStd {
    /// space vehicle identifier
    pub sv_id: SvId,
    /// STEC residual
    pub residual: i16,
}

impl SbpParse<STECResidualNoStd> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<STECResidualNoStd> {
        Ok( STECResidualNoStd{
            sv_id: self.parse()?,
            residual: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct STECSatElement {
    /// Unique space vehicle identifier
    pub sv_id: SvId,
    /// Quality of the STEC data. Encoded following RTCM DF389 specifcation but
    /// in units of TECU instead of m.
    pub stec_quality_indicator: u8,
    /// Coefficents of the STEC polynomial in the order of C00, C01, C10, C11
    pub stec_coeff: [i16; 4],
}

impl SbpParse<STECSatElement> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<STECSatElement> {
        Ok( STECSatElement{
            sv_id: self.parse()?,
            stec_quality_indicator: self.parse()?,
            stec_coeff: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
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

impl SbpParse<TroposphericDelayCorrection> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<TroposphericDelayCorrection> {
        Ok( TroposphericDelayCorrection{
            hydro: self.parse()?,
            wet: self.parse()?,
            stddev: self.parse()?,
        } )
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct TroposphericDelayCorrectionNoStd {
    /// Hydrostatic vertical delay
    pub hydro: i16,
    /// Wet vertical delay
    pub wet: i8,
}

impl SbpParse<TroposphericDelayCorrectionNoStd> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<TroposphericDelayCorrectionNoStd> {
        Ok( TroposphericDelayCorrectionNoStd{
            hydro: self.parse()?,
            wet: self.parse()?,
        } )
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
