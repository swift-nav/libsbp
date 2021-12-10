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

use super::gnss::*;

use super::lib::*;

/// SSR code biases corrections for a particular satellite
///
/// Code biases are to be added to pseudorange. The corrections conform with
/// RTCMv3 MT 1059 / 1065.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct CodeBiasesContent {
    /// Signal encoded following RTCM specifications (DF380, DF381, DF382 and
    /// DF467).
    #[cfg_attr(feature = "serde", serde(rename(serialize = "code")))]
    pub code: u8,
    /// Code bias value
    #[cfg_attr(feature = "serde", serde(rename(serialize = "value")))]
    pub value: i16,
}

impl WireFormat for CodeBiasesContent {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN + <i16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.code) + WireFormat::len(&self.value)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.code, buf);
        WireFormat::write(&self.value, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        CodeBiasesContent {
            code: WireFormat::parse_unchecked(buf),
            value: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages
///
/// Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes an
/// RLE encoded validity list.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct GridDefinitionHeaderDepA {
    /// region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "region_size_inverse")))]
    pub region_size_inverse: u8,
    /// grid height (deg) = grid width (deg) = area_width / region_size 0 is an
    /// invalid value.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "area_width")))]
    pub area_width: u16,
    /// North-West corner latitude (deg) = region_size * lat_nw_corner_enc - 90
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lat_nw_corner_enc")))]
    pub lat_nw_corner_enc: u16,
    /// North-West corner longitude (deg) = region_size * lon_nw_corner_enc -
    /// 180
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lon_nw_corner_enc")))]
    pub lon_nw_corner_enc: u16,
    /// Number of messages in the dataset
    #[cfg_attr(feature = "serde", serde(rename(serialize = "num_msgs")))]
    pub num_msgs: u8,
    /// Position of this message in the dataset
    #[cfg_attr(feature = "serde", serde(rename(serialize = "seq_num")))]
    pub seq_num: u8,
}

impl WireFormat for GridDefinitionHeaderDepA {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.region_size_inverse)
            + WireFormat::len(&self.area_width)
            + WireFormat::len(&self.lat_nw_corner_enc)
            + WireFormat::len(&self.lon_nw_corner_enc)
            + WireFormat::len(&self.num_msgs)
            + WireFormat::len(&self.seq_num)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.region_size_inverse, buf);
        WireFormat::write(&self.area_width, buf);
        WireFormat::write(&self.lat_nw_corner_enc, buf);
        WireFormat::write(&self.lon_nw_corner_enc, buf);
        WireFormat::write(&self.num_msgs, buf);
        WireFormat::write(&self.seq_num, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        GridDefinitionHeaderDepA {
            region_size_inverse: WireFormat::parse_unchecked(buf),
            area_width: WireFormat::parse_unchecked(buf),
            lat_nw_corner_enc: WireFormat::parse_unchecked(buf),
            lon_nw_corner_enc: WireFormat::parse_unchecked(buf),
            num_msgs: WireFormat::parse_unchecked(buf),
            seq_num: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Header for the MSG_SSR_GRIDDED_CORRECTION message
///
/// The LPP message contains nested variable length arrays which are not
/// supported in SBP, so each grid point will be identified by the index.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct GriddedCorrectionHeader {
    /// Unique identifier of the tile set this tile belongs to.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tile_set_id")))]
    pub tile_set_id: u16,
    /// Unique identifier of this tile in the tile set.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tile_id")))]
    pub tile_id: u16,
    /// GNSS reference time of the correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "time")))]
    pub time: GpsTimeSec,
    /// Number of messages in the dataset
    #[cfg_attr(feature = "serde", serde(rename(serialize = "num_msgs")))]
    pub num_msgs: u16,
    /// Position of this message in the dataset
    #[cfg_attr(feature = "serde", serde(rename(serialize = "seq_num")))]
    pub seq_num: u16,
    /// Update interval between consecutive corrections. Encoded following RTCM
    /// DF391 specification.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "update_interval")))]
    pub update_interval: u8,
    /// IOD of the SSR atmospheric correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iod_atmo")))]
    pub iod_atmo: u8,
    /// Quality of the troposphere data. Encoded following RTCM DF389
    /// specification in units of m.
    #[cfg_attr(
        feature = "serde",
        serde(rename(serialize = "tropo_quality_indicator"))
    )]
    pub tropo_quality_indicator: u8,
}

impl WireFormat for GriddedCorrectionHeader {
    const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <GpsTimeSec as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tile_set_id)
            + WireFormat::len(&self.tile_id)
            + WireFormat::len(&self.time)
            + WireFormat::len(&self.num_msgs)
            + WireFormat::len(&self.seq_num)
            + WireFormat::len(&self.update_interval)
            + WireFormat::len(&self.iod_atmo)
            + WireFormat::len(&self.tropo_quality_indicator)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tile_set_id, buf);
        WireFormat::write(&self.tile_id, buf);
        WireFormat::write(&self.time, buf);
        WireFormat::write(&self.num_msgs, buf);
        WireFormat::write(&self.seq_num, buf);
        WireFormat::write(&self.update_interval, buf);
        WireFormat::write(&self.iod_atmo, buf);
        WireFormat::write(&self.tropo_quality_indicator, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        GriddedCorrectionHeader {
            tile_set_id: WireFormat::parse_unchecked(buf),
            tile_id: WireFormat::parse_unchecked(buf),
            time: WireFormat::parse_unchecked(buf),
            num_msgs: WireFormat::parse_unchecked(buf),
            seq_num: WireFormat::parse_unchecked(buf),
            update_interval: WireFormat::parse_unchecked(buf),
            iod_atmo: WireFormat::parse_unchecked(buf),
            tropo_quality_indicator: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Header for MSG_SSR_GRIDDED_CORRECTION_DEP
///
/// The 3GPP message contains nested variable length arrays which are not
/// supported in SBP, so each grid point will be identified by the index.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct GriddedCorrectionHeaderDepA {
    /// GNSS reference time of the correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "time")))]
    pub time: GpsTimeSec,
    /// Number of messages in the dataset
    #[cfg_attr(feature = "serde", serde(rename(serialize = "num_msgs")))]
    pub num_msgs: u16,
    /// Position of this message in the dataset
    #[cfg_attr(feature = "serde", serde(rename(serialize = "seq_num")))]
    pub seq_num: u16,
    /// Update interval between consecutive corrections. Encoded following RTCM
    /// DF391 specification.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "update_interval")))]
    pub update_interval: u8,
    /// IOD of the SSR atmospheric correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iod_atmo")))]
    pub iod_atmo: u8,
    /// Quality of the troposphere data. Encoded following RTCM DF389
    /// specification in units of m.
    #[cfg_attr(
        feature = "serde",
        serde(rename(serialize = "tropo_quality_indicator"))
    )]
    pub tropo_quality_indicator: u8,
}

impl WireFormat for GriddedCorrectionHeaderDepA {
    const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.time)
            + WireFormat::len(&self.num_msgs)
            + WireFormat::len(&self.seq_num)
            + WireFormat::len(&self.update_interval)
            + WireFormat::len(&self.iod_atmo)
            + WireFormat::len(&self.tropo_quality_indicator)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.time, buf);
        WireFormat::write(&self.num_msgs, buf);
        WireFormat::write(&self.seq_num, buf);
        WireFormat::write(&self.update_interval, buf);
        WireFormat::write(&self.iod_atmo, buf);
        WireFormat::write(&self.tropo_quality_indicator, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        GriddedCorrectionHeaderDepA {
            time: WireFormat::parse_unchecked(buf),
            num_msgs: WireFormat::parse_unchecked(buf),
            seq_num: WireFormat::parse_unchecked(buf),
            update_interval: WireFormat::parse_unchecked(buf),
            iod_atmo: WireFormat::parse_unchecked(buf),
            tropo_quality_indicator: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Precise code biases correction
///
/// The precise code biases message is to be added to the pseudorange of the
/// corresponding signal to get corrected pseudorange. It is an equivalent to
/// the 1059 / 1065 RTCM message types.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSsrCodeBiases {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GNSS reference time of the correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "time")))]
    pub time: GpsTimeSec,
    /// GNSS signal identifier (16 bit)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// Update interval between consecutive corrections. Encoded following RTCM
    /// DF391 specification.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "update_interval")))]
    pub update_interval: u8,
    /// IOD of the SSR correction. A change of Issue Of Data SSR is used to
    /// indicate a change in the SSR generating configuration
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iod_ssr")))]
    pub iod_ssr: u8,
    /// Code biases for the different satellite signals
    #[cfg_attr(feature = "serde", serde(rename(serialize = "biases")))]
    pub biases: Vec<CodeBiasesContent>,
}

impl ConcreteMessage for MsgSsrCodeBiases {
    const MESSAGE_TYPE: u16 = 1505;
    const MESSAGE_NAME: &'static str = "MSG_SSR_CODE_BIASES";
}

impl SbpMessage for MsgSsrCodeBiases {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
}

impl TryFrom<Sbp> for MsgSsrCodeBiases {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSsrCodeBiases(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSsrCodeBiases {
    const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN
        + <GnssSignal as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <Vec<CodeBiasesContent> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.time)
            + WireFormat::len(&self.sid)
            + WireFormat::len(&self.update_interval)
            + WireFormat::len(&self.iod_ssr)
            + WireFormat::len(&self.biases)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.time, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.update_interval, buf);
        WireFormat::write(&self.iod_ssr, buf);
        WireFormat::write(&self.biases, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSsrCodeBiases {
            sender_id: None,
            time: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            update_interval: WireFormat::parse_unchecked(buf),
            iod_ssr: WireFormat::parse_unchecked(buf),
            biases: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Gridded troposphere and STEC correction residuals
///
/// STEC residuals are per space vehicle, troposphere is not.
///
/// It is typically equivalent to the QZSS CLAS Sub Type 9 messages.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSsrGriddedCorrection {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a gridded correction message
    #[cfg_attr(feature = "serde", serde(rename(serialize = "header")))]
    pub header: GriddedCorrectionHeader,
    /// Index of the grid point.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "index")))]
    pub index: u16,
    /// Wet and hydrostatic vertical delays (mean, stddev).
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tropo_delay_correction")))]
    pub tropo_delay_correction: TroposphericDelayCorrection,
    /// STEC residuals for each satellite (mean, stddev).
    #[cfg_attr(feature = "serde", serde(rename(serialize = "stec_residuals")))]
    pub stec_residuals: Vec<STECResidual>,
}

impl ConcreteMessage for MsgSsrGriddedCorrection {
    const MESSAGE_TYPE: u16 = 1532;
    const MESSAGE_NAME: &'static str = "MSG_SSR_GRIDDED_CORRECTION";
}

impl SbpMessage for MsgSsrGriddedCorrection {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
}

impl TryFrom<Sbp> for MsgSsrGriddedCorrection {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSsrGriddedCorrection(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSsrGriddedCorrection {
    const MIN_LEN: usize = <GriddedCorrectionHeader as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <TroposphericDelayCorrection as WireFormat>::MIN_LEN
        + <Vec<STECResidual> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.header)
            + WireFormat::len(&self.index)
            + WireFormat::len(&self.tropo_delay_correction)
            + WireFormat::len(&self.stec_residuals)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.header, buf);
        WireFormat::write(&self.index, buf);
        WireFormat::write(&self.tropo_delay_correction, buf);
        WireFormat::write(&self.stec_residuals, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSsrGriddedCorrection {
            sender_id: None,
            header: WireFormat::parse_unchecked(buf),
            index: WireFormat::parse_unchecked(buf),
            tropo_delay_correction: WireFormat::parse_unchecked(buf),
            stec_residuals: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSsrGriddedCorrectionDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a Gridded Correction message
    #[cfg_attr(feature = "serde", serde(rename(serialize = "header")))]
    pub header: GriddedCorrectionHeaderDepA,
    /// Index of the grid point
    #[cfg_attr(feature = "serde", serde(rename(serialize = "index")))]
    pub index: u16,
    /// Wet and hydrostatic vertical delays (mean, stddev)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tropo_delay_correction")))]
    pub tropo_delay_correction: TroposphericDelayCorrection,
    /// STEC residuals for each satellite (mean, stddev)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "stec_residuals")))]
    pub stec_residuals: Vec<STECResidual>,
}

impl ConcreteMessage for MsgSsrGriddedCorrectionDepA {
    const MESSAGE_TYPE: u16 = 1530;
    const MESSAGE_NAME: &'static str = "MSG_SSR_GRIDDED_CORRECTION_DEP_A";
}

impl SbpMessage for MsgSsrGriddedCorrectionDepA {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
}

impl TryFrom<Sbp> for MsgSsrGriddedCorrectionDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSsrGriddedCorrectionDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSsrGriddedCorrectionDepA {
    const MIN_LEN: usize = <GriddedCorrectionHeaderDepA as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <TroposphericDelayCorrection as WireFormat>::MIN_LEN
        + <Vec<STECResidual> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.header)
            + WireFormat::len(&self.index)
            + WireFormat::len(&self.tropo_delay_correction)
            + WireFormat::len(&self.stec_residuals)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.header, buf);
        WireFormat::write(&self.index, buf);
        WireFormat::write(&self.tropo_delay_correction, buf);
        WireFormat::write(&self.stec_residuals, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSsrGriddedCorrectionDepA {
            sender_id: None,
            header: WireFormat::parse_unchecked(buf),
            index: WireFormat::parse_unchecked(buf),
            tropo_delay_correction: WireFormat::parse_unchecked(buf),
            stec_residuals: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSsrGriddedCorrectionNoStdDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a Gridded Correction message
    #[cfg_attr(feature = "serde", serde(rename(serialize = "header")))]
    pub header: GriddedCorrectionHeaderDepA,
    /// Index of the grid point
    #[cfg_attr(feature = "serde", serde(rename(serialize = "index")))]
    pub index: u16,
    /// Wet and hydrostatic vertical delays
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tropo_delay_correction")))]
    pub tropo_delay_correction: TroposphericDelayCorrectionNoStd,
    /// STEC residuals for each satellite
    #[cfg_attr(feature = "serde", serde(rename(serialize = "stec_residuals")))]
    pub stec_residuals: Vec<STECResidualNoStd>,
}

impl ConcreteMessage for MsgSsrGriddedCorrectionNoStdDepA {
    const MESSAGE_TYPE: u16 = 1520;
    const MESSAGE_NAME: &'static str = "MSG_SSR_GRIDDED_CORRECTION_NO_STD_DEP_A";
}

impl SbpMessage for MsgSsrGriddedCorrectionNoStdDepA {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
}

impl TryFrom<Sbp> for MsgSsrGriddedCorrectionNoStdDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSsrGriddedCorrectionNoStdDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSsrGriddedCorrectionNoStdDepA {
    const MIN_LEN: usize = <GriddedCorrectionHeaderDepA as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <TroposphericDelayCorrectionNoStd as WireFormat>::MIN_LEN
        + <Vec<STECResidualNoStd> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.header)
            + WireFormat::len(&self.index)
            + WireFormat::len(&self.tropo_delay_correction)
            + WireFormat::len(&self.stec_residuals)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.header, buf);
        WireFormat::write(&self.index, buf);
        WireFormat::write(&self.tropo_delay_correction, buf);
        WireFormat::write(&self.stec_residuals, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSsrGriddedCorrectionNoStdDepA {
            sender_id: None,
            header: WireFormat::parse_unchecked(buf),
            index: WireFormat::parse_unchecked(buf),
            tropo_delay_correction: WireFormat::parse_unchecked(buf),
            stec_residuals: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSsrGridDefinitionDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a Gridded Correction message
    #[cfg_attr(feature = "serde", serde(rename(serialize = "header")))]
    pub header: GridDefinitionHeaderDepA,
    /// Run Length Encode list of quadrants that contain valid data. The spec
    /// describes the encoding scheme in detail, but essentially the index of
    /// the quadrants that contain transitions between valid and invalid (and
    /// vice versa) are encoded as u8 integers.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "rle_list")))]
    pub rle_list: Vec<u8>,
}

impl ConcreteMessage for MsgSsrGridDefinitionDepA {
    const MESSAGE_TYPE: u16 = 1525;
    const MESSAGE_NAME: &'static str = "MSG_SSR_GRID_DEFINITION_DEP_A";
}

impl SbpMessage for MsgSsrGridDefinitionDepA {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
}

impl TryFrom<Sbp> for MsgSsrGridDefinitionDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSsrGridDefinitionDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSsrGridDefinitionDepA {
    const MIN_LEN: usize =
        <GridDefinitionHeaderDepA as WireFormat>::MIN_LEN + <Vec<u8> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.header) + WireFormat::len(&self.rle_list)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.header, buf);
        WireFormat::write(&self.rle_list, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSsrGridDefinitionDepA {
            sender_id: None,
            header: WireFormat::parse_unchecked(buf),
            rle_list: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Precise orbit and clock correction
///
/// The precise orbit and clock correction message is to be applied as a delta
/// correction to broadcast ephemeris and is an equivalent to the 1060 /1066
/// RTCM message types.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSsrOrbitClock {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GNSS reference time of the correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "time")))]
    pub time: GpsTimeSec,
    /// GNSS signal identifier (16 bit)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// Update interval between consecutive corrections. Encoded following RTCM
    /// DF391 specification.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "update_interval")))]
    pub update_interval: u8,
    /// IOD of the SSR correction. A change of Issue Of Data SSR is used to
    /// indicate a change in the SSR generating configuration
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iod_ssr")))]
    pub iod_ssr: u8,
    /// Issue of broadcast ephemeris data or IODCRC (Beidou)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iod")))]
    pub iod: u32,
    /// Orbit radial delta correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "radial")))]
    pub radial: i32,
    /// Orbit along delta correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "along")))]
    pub along: i32,
    /// Orbit along delta correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cross")))]
    pub cross: i32,
    /// Velocity of orbit radial delta correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dot_radial")))]
    pub dot_radial: i32,
    /// Velocity of orbit along delta correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dot_along")))]
    pub dot_along: i32,
    /// Velocity of orbit cross delta correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dot_cross")))]
    pub dot_cross: i32,
    /// C0 polynomial coefficient for correction of broadcast satellite clock
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c0")))]
    pub c0: i32,
    /// C1 polynomial coefficient for correction of broadcast satellite clock
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c1")))]
    pub c1: i32,
    /// C2 polynomial coefficient for correction of broadcast satellite clock
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c2")))]
    pub c2: i32,
}

impl ConcreteMessage for MsgSsrOrbitClock {
    const MESSAGE_TYPE: u16 = 1501;
    const MESSAGE_NAME: &'static str = "MSG_SSR_ORBIT_CLOCK";
}

impl SbpMessage for MsgSsrOrbitClock {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
}

impl TryFrom<Sbp> for MsgSsrOrbitClock {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSsrOrbitClock(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSsrOrbitClock {
    const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN
        + <GnssSignal as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.time)
            + WireFormat::len(&self.sid)
            + WireFormat::len(&self.update_interval)
            + WireFormat::len(&self.iod_ssr)
            + WireFormat::len(&self.iod)
            + WireFormat::len(&self.radial)
            + WireFormat::len(&self.along)
            + WireFormat::len(&self.cross)
            + WireFormat::len(&self.dot_radial)
            + WireFormat::len(&self.dot_along)
            + WireFormat::len(&self.dot_cross)
            + WireFormat::len(&self.c0)
            + WireFormat::len(&self.c1)
            + WireFormat::len(&self.c2)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.time, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.update_interval, buf);
        WireFormat::write(&self.iod_ssr, buf);
        WireFormat::write(&self.iod, buf);
        WireFormat::write(&self.radial, buf);
        WireFormat::write(&self.along, buf);
        WireFormat::write(&self.cross, buf);
        WireFormat::write(&self.dot_radial, buf);
        WireFormat::write(&self.dot_along, buf);
        WireFormat::write(&self.dot_cross, buf);
        WireFormat::write(&self.c0, buf);
        WireFormat::write(&self.c1, buf);
        WireFormat::write(&self.c2, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSsrOrbitClock {
            sender_id: None,
            time: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            update_interval: WireFormat::parse_unchecked(buf),
            iod_ssr: WireFormat::parse_unchecked(buf),
            iod: WireFormat::parse_unchecked(buf),
            radial: WireFormat::parse_unchecked(buf),
            along: WireFormat::parse_unchecked(buf),
            cross: WireFormat::parse_unchecked(buf),
            dot_radial: WireFormat::parse_unchecked(buf),
            dot_along: WireFormat::parse_unchecked(buf),
            dot_cross: WireFormat::parse_unchecked(buf),
            c0: WireFormat::parse_unchecked(buf),
            c1: WireFormat::parse_unchecked(buf),
            c2: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSsrOrbitClockDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GNSS reference time of the correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "time")))]
    pub time: GpsTimeSec,
    /// GNSS signal identifier (16 bit)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// Update interval between consecutive corrections. Encoded following RTCM
    /// DF391 specification.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "update_interval")))]
    pub update_interval: u8,
    /// IOD of the SSR correction. A change of Issue Of Data SSR is used to
    /// indicate a change in the SSR generating configuration
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iod_ssr")))]
    pub iod_ssr: u8,
    /// Issue of broadcast ephemeris data
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iod")))]
    pub iod: u8,
    /// Orbit radial delta correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "radial")))]
    pub radial: i32,
    /// Orbit along delta correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "along")))]
    pub along: i32,
    /// Orbit along delta correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cross")))]
    pub cross: i32,
    /// Velocity of orbit radial delta correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dot_radial")))]
    pub dot_radial: i32,
    /// Velocity of orbit along delta correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dot_along")))]
    pub dot_along: i32,
    /// Velocity of orbit cross delta correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dot_cross")))]
    pub dot_cross: i32,
    /// C0 polynomial coefficient for correction of broadcast satellite clock
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c0")))]
    pub c0: i32,
    /// C1 polynomial coefficient for correction of broadcast satellite clock
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c1")))]
    pub c1: i32,
    /// C2 polynomial coefficient for correction of broadcast satellite clock
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c2")))]
    pub c2: i32,
}

impl ConcreteMessage for MsgSsrOrbitClockDepA {
    const MESSAGE_TYPE: u16 = 1500;
    const MESSAGE_NAME: &'static str = "MSG_SSR_ORBIT_CLOCK_DEP_A";
}

impl SbpMessage for MsgSsrOrbitClockDepA {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
}

impl TryFrom<Sbp> for MsgSsrOrbitClockDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSsrOrbitClockDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSsrOrbitClockDepA {
    const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN
        + <GnssSignal as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.time)
            + WireFormat::len(&self.sid)
            + WireFormat::len(&self.update_interval)
            + WireFormat::len(&self.iod_ssr)
            + WireFormat::len(&self.iod)
            + WireFormat::len(&self.radial)
            + WireFormat::len(&self.along)
            + WireFormat::len(&self.cross)
            + WireFormat::len(&self.dot_radial)
            + WireFormat::len(&self.dot_along)
            + WireFormat::len(&self.dot_cross)
            + WireFormat::len(&self.c0)
            + WireFormat::len(&self.c1)
            + WireFormat::len(&self.c2)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.time, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.update_interval, buf);
        WireFormat::write(&self.iod_ssr, buf);
        WireFormat::write(&self.iod, buf);
        WireFormat::write(&self.radial, buf);
        WireFormat::write(&self.along, buf);
        WireFormat::write(&self.cross, buf);
        WireFormat::write(&self.dot_radial, buf);
        WireFormat::write(&self.dot_along, buf);
        WireFormat::write(&self.dot_cross, buf);
        WireFormat::write(&self.c0, buf);
        WireFormat::write(&self.c1, buf);
        WireFormat::write(&self.c2, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSsrOrbitClockDepA {
            sender_id: None,
            time: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            update_interval: WireFormat::parse_unchecked(buf),
            iod_ssr: WireFormat::parse_unchecked(buf),
            iod: WireFormat::parse_unchecked(buf),
            radial: WireFormat::parse_unchecked(buf),
            along: WireFormat::parse_unchecked(buf),
            cross: WireFormat::parse_unchecked(buf),
            dot_radial: WireFormat::parse_unchecked(buf),
            dot_along: WireFormat::parse_unchecked(buf),
            dot_cross: WireFormat::parse_unchecked(buf),
            c0: WireFormat::parse_unchecked(buf),
            c1: WireFormat::parse_unchecked(buf),
            c2: WireFormat::parse_unchecked(buf),
        }
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
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSsrPhaseBiases {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GNSS reference time of the correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "time")))]
    pub time: GpsTimeSec,
    /// GNSS signal identifier (16 bit)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// Update interval between consecutive corrections. Encoded following RTCM
    /// DF391 specification.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "update_interval")))]
    pub update_interval: u8,
    /// IOD of the SSR correction. A change of Issue Of Data SSR is used to
    /// indicate a change in the SSR generating configuration
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iod_ssr")))]
    pub iod_ssr: u8,
    /// Indicator for the dispersive phase biases property.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dispersive_bias")))]
    pub dispersive_bias: u8,
    /// Consistency indicator for Melbourne-Wubbena linear combinations
    #[cfg_attr(feature = "serde", serde(rename(serialize = "mw_consistency")))]
    pub mw_consistency: u8,
    /// Satellite yaw angle
    #[cfg_attr(feature = "serde", serde(rename(serialize = "yaw")))]
    pub yaw: u16,
    /// Satellite yaw angle rate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "yaw_rate")))]
    pub yaw_rate: i8,
    /// Phase biases corrections for a satellite being tracked.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "biases")))]
    pub biases: Vec<PhaseBiasesContent>,
}

impl ConcreteMessage for MsgSsrPhaseBiases {
    const MESSAGE_TYPE: u16 = 1510;
    const MESSAGE_NAME: &'static str = "MSG_SSR_PHASE_BIASES";
}

impl SbpMessage for MsgSsrPhaseBiases {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
}

impl TryFrom<Sbp> for MsgSsrPhaseBiases {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSsrPhaseBiases(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSsrPhaseBiases {
    const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN
        + <GnssSignal as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <i8 as WireFormat>::MIN_LEN
        + <Vec<PhaseBiasesContent> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.time)
            + WireFormat::len(&self.sid)
            + WireFormat::len(&self.update_interval)
            + WireFormat::len(&self.iod_ssr)
            + WireFormat::len(&self.dispersive_bias)
            + WireFormat::len(&self.mw_consistency)
            + WireFormat::len(&self.yaw)
            + WireFormat::len(&self.yaw_rate)
            + WireFormat::len(&self.biases)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.time, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.update_interval, buf);
        WireFormat::write(&self.iod_ssr, buf);
        WireFormat::write(&self.dispersive_bias, buf);
        WireFormat::write(&self.mw_consistency, buf);
        WireFormat::write(&self.yaw, buf);
        WireFormat::write(&self.yaw_rate, buf);
        WireFormat::write(&self.biases, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSsrPhaseBiases {
            sender_id: None,
            time: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            update_interval: WireFormat::parse_unchecked(buf),
            iod_ssr: WireFormat::parse_unchecked(buf),
            dispersive_bias: WireFormat::parse_unchecked(buf),
            mw_consistency: WireFormat::parse_unchecked(buf),
            yaw: WireFormat::parse_unchecked(buf),
            yaw_rate: WireFormat::parse_unchecked(buf),
            biases: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite antenna phase center corrections
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSsrSatelliteApc {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Satellite antenna phase center corrections
    #[cfg_attr(feature = "serde", serde(rename(serialize = "apc")))]
    pub apc: Vec<SatelliteAPC>,
}

impl ConcreteMessage for MsgSsrSatelliteApc {
    const MESSAGE_TYPE: u16 = 1540;
    const MESSAGE_NAME: &'static str = "MSG_SSR_SATELLITE_APC";
}

impl SbpMessage for MsgSsrSatelliteApc {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
}

impl TryFrom<Sbp> for MsgSsrSatelliteApc {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSsrSatelliteApc(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSsrSatelliteApc {
    const MIN_LEN: usize = <Vec<SatelliteAPC> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.apc)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.apc, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSsrSatelliteApc {
            sender_id: None,
            apc: WireFormat::parse_unchecked(buf),
        }
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
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSsrStecCorrection {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a STEC polynomial coefficient message.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "header")))]
    pub header: STECHeader,
    /// Array of STEC polynomial coefficients for each space vehicle.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "stec_sat_list")))]
    pub stec_sat_list: Vec<STECSatElement>,
}

impl ConcreteMessage for MsgSsrStecCorrection {
    const MESSAGE_TYPE: u16 = 1531;
    const MESSAGE_NAME: &'static str = "MSG_SSR_STEC_CORRECTION";
}

impl SbpMessage for MsgSsrStecCorrection {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
}

impl TryFrom<Sbp> for MsgSsrStecCorrection {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSsrStecCorrection(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSsrStecCorrection {
    const MIN_LEN: usize =
        <STECHeader as WireFormat>::MIN_LEN + <Vec<STECSatElement> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.header) + WireFormat::len(&self.stec_sat_list)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.header, buf);
        WireFormat::write(&self.stec_sat_list, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSsrStecCorrection {
            sender_id: None,
            header: WireFormat::parse_unchecked(buf),
            stec_sat_list: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSsrStecCorrectionDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a STEC message
    #[cfg_attr(feature = "serde", serde(rename(serialize = "header")))]
    pub header: STECHeaderDepA,
    /// Array of STEC information for each space vehicle
    #[cfg_attr(feature = "serde", serde(rename(serialize = "stec_sat_list")))]
    pub stec_sat_list: Vec<STECSatElement>,
}

impl ConcreteMessage for MsgSsrStecCorrectionDepA {
    const MESSAGE_TYPE: u16 = 1515;
    const MESSAGE_NAME: &'static str = "MSG_SSR_STEC_CORRECTION_DEP_A";
}

impl SbpMessage for MsgSsrStecCorrectionDepA {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
}

impl TryFrom<Sbp> for MsgSsrStecCorrectionDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSsrStecCorrectionDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSsrStecCorrectionDepA {
    const MIN_LEN: usize =
        <STECHeaderDepA as WireFormat>::MIN_LEN + <Vec<STECSatElement> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.header) + WireFormat::len(&self.stec_sat_list)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.header, buf);
        WireFormat::write(&self.stec_sat_list, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSsrStecCorrectionDepA {
            sender_id: None,
            header: WireFormat::parse_unchecked(buf),
            stec_sat_list: WireFormat::parse_unchecked(buf),
        }
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
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSsrTileDefinition {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Unique identifier of the tile set this tile belongs to.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tile_set_id")))]
    pub tile_set_id: u16,
    /// Unique identifier of this tile in the tile set.
    /// See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tile_id")))]
    pub tile_id: u16,
    /// North-West corner correction point latitude.
    ///
    /// The relation between the latitude X in the range \[-90, 90\] and the coded
    /// number N is:
    ///
    /// N = floor((X / 90) * 2^14)
    ///
    /// See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "corner_nw_lat")))]
    pub corner_nw_lat: i16,
    /// North-West corner correction point longitude.
    ///
    /// The relation between the longitude X in the range \[-180, 180\] and the
    /// coded number N is:
    ///
    /// N = floor((X / 180) * 2^15)
    ///
    /// See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "corner_nw_lon")))]
    pub corner_nw_lon: i16,
    /// Spacing of the correction points in the latitude direction.
    ///
    /// See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "spacing_lat")))]
    pub spacing_lat: u16,
    /// Spacing of the correction points in the longitude direction.
    ///
    /// See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "spacing_lon")))]
    pub spacing_lon: u16,
    /// Number of steps in the latitude direction.
    ///
    /// See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "rows")))]
    pub rows: u16,
    /// Number of steps in the longitude direction.
    ///
    /// See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cols")))]
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
    #[cfg_attr(feature = "serde", serde(rename(serialize = "bitmask")))]
    pub bitmask: u64,
}

impl ConcreteMessage for MsgSsrTileDefinition {
    const MESSAGE_TYPE: u16 = 1526;
    const MESSAGE_NAME: &'static str = "MSG_SSR_TILE_DEFINITION";
}

impl SbpMessage for MsgSsrTileDefinition {
    fn message_name(&self) -> &'static str {
        <Self as ConcreteMessage>::MESSAGE_NAME
    }
    fn message_type(&self) -> u16 {
        <Self as ConcreteMessage>::MESSAGE_TYPE
    }
    fn sender_id(&self) -> Option<u16> {
        self.sender_id
    }
    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
    fn encoded_len(&self) -> usize {
        WireFormat::len(self) + crate::HEADER_LEN + crate::CRC_LEN
    }
}

impl TryFrom<Sbp> for MsgSsrTileDefinition {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSsrTileDefinition(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSsrTileDefinition {
    const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u64 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tile_set_id)
            + WireFormat::len(&self.tile_id)
            + WireFormat::len(&self.corner_nw_lat)
            + WireFormat::len(&self.corner_nw_lon)
            + WireFormat::len(&self.spacing_lat)
            + WireFormat::len(&self.spacing_lon)
            + WireFormat::len(&self.rows)
            + WireFormat::len(&self.cols)
            + WireFormat::len(&self.bitmask)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tile_set_id, buf);
        WireFormat::write(&self.tile_id, buf);
        WireFormat::write(&self.corner_nw_lat, buf);
        WireFormat::write(&self.corner_nw_lon, buf);
        WireFormat::write(&self.spacing_lat, buf);
        WireFormat::write(&self.spacing_lon, buf);
        WireFormat::write(&self.rows, buf);
        WireFormat::write(&self.cols, buf);
        WireFormat::write(&self.bitmask, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSsrTileDefinition {
            sender_id: None,
            tile_set_id: WireFormat::parse_unchecked(buf),
            tile_id: WireFormat::parse_unchecked(buf),
            corner_nw_lat: WireFormat::parse_unchecked(buf),
            corner_nw_lon: WireFormat::parse_unchecked(buf),
            spacing_lat: WireFormat::parse_unchecked(buf),
            spacing_lon: WireFormat::parse_unchecked(buf),
            rows: WireFormat::parse_unchecked(buf),
            cols: WireFormat::parse_unchecked(buf),
            bitmask: WireFormat::parse_unchecked(buf),
        }
    }
}

/// SSR phase biases corrections for a particular satellite
///
/// Phase biases are to be added to carrier phase measurements.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct PhaseBiasesContent {
    /// Signal encoded following RTCM specifications (DF380, DF381, DF382 and
    /// DF467)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "code")))]
    pub code: u8,
    /// Indicator for integer property
    #[cfg_attr(feature = "serde", serde(rename(serialize = "integer_indicator")))]
    pub integer_indicator: u8,
    /// Indicator for two groups of Wide-Lane(s) integer property
    #[cfg_attr(
        feature = "serde",
        serde(rename(serialize = "widelane_integer_indicator"))
    )]
    pub widelane_integer_indicator: u8,
    /// Signal phase discontinuity counter. Increased for every discontinuity in
    /// phase.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "discontinuity_counter")))]
    pub discontinuity_counter: u8,
    /// Phase bias for specified signal
    #[cfg_attr(feature = "serde", serde(rename(serialize = "bias")))]
    pub bias: i32,
}

impl WireFormat for PhaseBiasesContent {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.code)
            + WireFormat::len(&self.integer_indicator)
            + WireFormat::len(&self.widelane_integer_indicator)
            + WireFormat::len(&self.discontinuity_counter)
            + WireFormat::len(&self.bias)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.code, buf);
        WireFormat::write(&self.integer_indicator, buf);
        WireFormat::write(&self.widelane_integer_indicator, buf);
        WireFormat::write(&self.discontinuity_counter, buf);
        WireFormat::write(&self.bias, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        PhaseBiasesContent {
            code: WireFormat::parse_unchecked(buf),
            integer_indicator: WireFormat::parse_unchecked(buf),
            widelane_integer_indicator: WireFormat::parse_unchecked(buf),
            discontinuity_counter: WireFormat::parse_unchecked(buf),
            bias: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Header for the MSG_SSR_STEC_CORRECTION message
///
/// A full set of STEC information will likely span multiple SBP messages,
/// since SBP message a limited to 255 bytes.  The header is used to tie
/// multiple SBP messages into a sequence.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct STECHeader {
    /// Unique identifier of the tile set this tile belongs to.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tile_set_id")))]
    pub tile_set_id: u16,
    /// Unique identifier of this tile in the tile set.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tile_id")))]
    pub tile_id: u16,
    /// GNSS reference time of the correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "time")))]
    pub time: GpsTimeSec,
    /// Number of messages in the dataset
    #[cfg_attr(feature = "serde", serde(rename(serialize = "num_msgs")))]
    pub num_msgs: u8,
    /// Position of this message in the dataset
    #[cfg_attr(feature = "serde", serde(rename(serialize = "seq_num")))]
    pub seq_num: u8,
    /// Update interval between consecutive corrections. Encoded following RTCM
    /// DF391 specification.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "update_interval")))]
    pub update_interval: u8,
    /// IOD of the SSR atmospheric correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iod_atmo")))]
    pub iod_atmo: u8,
}

impl WireFormat for STECHeader {
    const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <GpsTimeSec as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tile_set_id)
            + WireFormat::len(&self.tile_id)
            + WireFormat::len(&self.time)
            + WireFormat::len(&self.num_msgs)
            + WireFormat::len(&self.seq_num)
            + WireFormat::len(&self.update_interval)
            + WireFormat::len(&self.iod_atmo)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tile_set_id, buf);
        WireFormat::write(&self.tile_id, buf);
        WireFormat::write(&self.time, buf);
        WireFormat::write(&self.num_msgs, buf);
        WireFormat::write(&self.seq_num, buf);
        WireFormat::write(&self.update_interval, buf);
        WireFormat::write(&self.iod_atmo, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        STECHeader {
            tile_set_id: WireFormat::parse_unchecked(buf),
            tile_id: WireFormat::parse_unchecked(buf),
            time: WireFormat::parse_unchecked(buf),
            num_msgs: WireFormat::parse_unchecked(buf),
            seq_num: WireFormat::parse_unchecked(buf),
            update_interval: WireFormat::parse_unchecked(buf),
            iod_atmo: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Header for MSG_SSR_STEC_CORRECTION_DEP message
///
/// A full set of STEC information will likely span multiple SBP messages,
/// since SBP message a limited to 255 bytes.  The header is used to tie
/// multiple SBP messages into a sequence.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct STECHeaderDepA {
    /// GNSS reference time of the correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "time")))]
    pub time: GpsTimeSec,
    /// Number of messages in the dataset
    #[cfg_attr(feature = "serde", serde(rename(serialize = "num_msgs")))]
    pub num_msgs: u8,
    /// Position of this message in the dataset
    #[cfg_attr(feature = "serde", serde(rename(serialize = "seq_num")))]
    pub seq_num: u8,
    /// Update interval between consecutive corrections. Encoded following RTCM
    /// DF391 specification.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "update_interval")))]
    pub update_interval: u8,
    /// IOD of the SSR atmospheric correction
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iod_atmo")))]
    pub iod_atmo: u8,
}

impl WireFormat for STECHeaderDepA {
    const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.time)
            + WireFormat::len(&self.num_msgs)
            + WireFormat::len(&self.seq_num)
            + WireFormat::len(&self.update_interval)
            + WireFormat::len(&self.iod_atmo)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.time, buf);
        WireFormat::write(&self.num_msgs, buf);
        WireFormat::write(&self.seq_num, buf);
        WireFormat::write(&self.update_interval, buf);
        WireFormat::write(&self.iod_atmo, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        STECHeaderDepA {
            time: WireFormat::parse_unchecked(buf),
            num_msgs: WireFormat::parse_unchecked(buf),
            seq_num: WireFormat::parse_unchecked(buf),
            update_interval: WireFormat::parse_unchecked(buf),
            iod_atmo: WireFormat::parse_unchecked(buf),
        }
    }
}

/// None
///
/// STEC residual (mean and standard deviation) for the given satellite at the
/// grid point.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct STECResidual {
    /// space vehicle identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sv_id")))]
    pub sv_id: SvId,
    /// STEC residual
    #[cfg_attr(feature = "serde", serde(rename(serialize = "residual")))]
    pub residual: i16,
    /// stddev
    #[cfg_attr(feature = "serde", serde(rename(serialize = "stddev")))]
    pub stddev: u8,
}

impl WireFormat for STECResidual {
    const MIN_LEN: usize =
        <SvId as WireFormat>::MIN_LEN + <i16 as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sv_id)
            + WireFormat::len(&self.residual)
            + WireFormat::len(&self.stddev)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sv_id, buf);
        WireFormat::write(&self.residual, buf);
        WireFormat::write(&self.stddev, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        STECResidual {
            sv_id: WireFormat::parse_unchecked(buf),
            residual: WireFormat::parse_unchecked(buf),
            stddev: WireFormat::parse_unchecked(buf),
        }
    }
}

/// None
///
/// STEC residual for the given satellite at the grid point.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct STECResidualNoStd {
    /// space vehicle identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sv_id")))]
    pub sv_id: SvId,
    /// STEC residual
    #[cfg_attr(feature = "serde", serde(rename(serialize = "residual")))]
    pub residual: i16,
}

impl WireFormat for STECResidualNoStd {
    const MIN_LEN: usize = <SvId as WireFormat>::MIN_LEN + <i16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sv_id) + WireFormat::len(&self.residual)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sv_id, buf);
        WireFormat::write(&self.residual, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        STECResidualNoStd {
            sv_id: WireFormat::parse_unchecked(buf),
            residual: WireFormat::parse_unchecked(buf),
        }
    }
}

/// None
///
/// STEC polynomial for the given satellite.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct STECSatElement {
    /// Unique space vehicle identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sv_id")))]
    pub sv_id: SvId,
    /// Quality of the STEC data. Encoded following RTCM DF389 specification but
    /// in units of TECU instead of m.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "stec_quality_indicator")))]
    pub stec_quality_indicator: u8,
    /// Coefficients of the STEC polynomial in the order of C00, C01, C10, C11
    #[cfg_attr(feature = "serde", serde(rename(serialize = "stec_coeff")))]
    pub stec_coeff: [i16; 4],
}

impl WireFormat for STECSatElement {
    const MIN_LEN: usize = <SvId as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <[i16; 4] as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sv_id)
            + WireFormat::len(&self.stec_quality_indicator)
            + WireFormat::len(&self.stec_coeff)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sv_id, buf);
        WireFormat::write(&self.stec_quality_indicator, buf);
        WireFormat::write(&self.stec_coeff, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        STECSatElement {
            sv_id: WireFormat::parse_unchecked(buf),
            stec_quality_indicator: WireFormat::parse_unchecked(buf),
            stec_coeff: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Antenna phase center correction
///
/// Contains phase center offset and elevation variation corrections for one
/// signal on a satellite.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct SatelliteAPC {
    /// GNSS signal identifier (16 bit)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// Additional satellite information
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sat_info")))]
    pub sat_info: u8,
    /// Satellite Code, as defined by IGS. Typically the space vehicle number.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "svn")))]
    pub svn: u16,
    /// Mean phase center offset, X Y and Z axes. See IGS ANTEX file format
    /// description for coordinate system definition.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pco")))]
    pub pco: [i16; 3],
    /// Elevation dependent phase center variations. First element is 0 degrees
    /// separation from the Z axis, subsequent elements represent elevation
    /// variations in 1 degree increments.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pcv")))]
    pub pcv: [i8; 21],
}

impl WireFormat for SatelliteAPC {
    const MIN_LEN: usize = <GnssSignal as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <[i16; 3] as WireFormat>::MIN_LEN
        + <[i8; 21] as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sid)
            + WireFormat::len(&self.sat_info)
            + WireFormat::len(&self.svn)
            + WireFormat::len(&self.pco)
            + WireFormat::len(&self.pcv)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.sat_info, buf);
        WireFormat::write(&self.svn, buf);
        WireFormat::write(&self.pco, buf);
        WireFormat::write(&self.pcv, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        SatelliteAPC {
            sid: WireFormat::parse_unchecked(buf),
            sat_info: WireFormat::parse_unchecked(buf),
            svn: WireFormat::parse_unchecked(buf),
            pco: WireFormat::parse_unchecked(buf),
            pcv: WireFormat::parse_unchecked(buf),
        }
    }
}

/// None
///
/// Troposphere vertical delays (mean and standard deviation) at the grid
/// point.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct TroposphericDelayCorrection {
    /// Hydrostatic vertical delay
    #[cfg_attr(feature = "serde", serde(rename(serialize = "hydro")))]
    pub hydro: i16,
    /// Wet vertical delay
    #[cfg_attr(feature = "serde", serde(rename(serialize = "wet")))]
    pub wet: i8,
    /// stddev
    #[cfg_attr(feature = "serde", serde(rename(serialize = "stddev")))]
    pub stddev: u8,
}

impl WireFormat for TroposphericDelayCorrection {
    const MIN_LEN: usize =
        <i16 as WireFormat>::MIN_LEN + <i8 as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.hydro) + WireFormat::len(&self.wet) + WireFormat::len(&self.stddev)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.hydro, buf);
        WireFormat::write(&self.wet, buf);
        WireFormat::write(&self.stddev, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        TroposphericDelayCorrection {
            hydro: WireFormat::parse_unchecked(buf),
            wet: WireFormat::parse_unchecked(buf),
            stddev: WireFormat::parse_unchecked(buf),
        }
    }
}

/// None
///
/// Troposphere vertical delays at the grid point.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct TroposphericDelayCorrectionNoStd {
    /// Hydrostatic vertical delay
    #[cfg_attr(feature = "serde", serde(rename(serialize = "hydro")))]
    pub hydro: i16,
    /// Wet vertical delay
    #[cfg_attr(feature = "serde", serde(rename(serialize = "wet")))]
    pub wet: i8,
}

impl WireFormat for TroposphericDelayCorrectionNoStd {
    const MIN_LEN: usize = <i16 as WireFormat>::MIN_LEN + <i8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.hydro) + WireFormat::len(&self.wet)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.hydro, buf);
        WireFormat::write(&self.wet, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        TroposphericDelayCorrectionNoStd {
            hydro: WireFormat::parse_unchecked(buf),
            wet: WireFormat::parse_unchecked(buf),
        }
    }
}
