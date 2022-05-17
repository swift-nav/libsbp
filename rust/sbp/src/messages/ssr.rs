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
pub use code_biases_content::CodeBiasesContent;
pub use grid_definition_header_dep_a::GridDefinitionHeaderDepA;
pub use gridded_correction_header::GriddedCorrectionHeader;
pub use gridded_correction_header_dep_a::GriddedCorrectionHeaderDepA;
pub use msg_ssr_code_biases::MsgSsrCodeBiases;
pub use msg_ssr_code_phase_biases_bounds::MsgSsrCodePhaseBiasesBounds;
pub use msg_ssr_grid_definition_dep_a::MsgSsrGridDefinitionDepA;
pub use msg_ssr_gridded_correction::MsgSsrGriddedCorrection;
pub use msg_ssr_gridded_correction_bounds::MsgSsrGriddedCorrectionBounds;
pub use msg_ssr_gridded_correction_dep_a::MsgSsrGriddedCorrectionDepA;
pub use msg_ssr_gridded_correction_no_std_dep_a::MsgSsrGriddedCorrectionNoStdDepA;
pub use msg_ssr_orbit_clock::MsgSsrOrbitClock;
pub use msg_ssr_orbit_clock_bounds::MsgSsrOrbitClockBounds;
pub use msg_ssr_orbit_clock_bounds_degradation::MsgSsrOrbitClockBoundsDegradation;
pub use msg_ssr_orbit_clock_dep_a::MsgSsrOrbitClockDepA;
pub use msg_ssr_phase_biases::MsgSsrPhaseBiases;
pub use msg_ssr_satellite_apc::MsgSsrSatelliteApc;
pub use msg_ssr_stec_correction::MsgSsrStecCorrection;
pub use msg_ssr_stec_correction_dep::MsgSsrStecCorrectionDep;
pub use msg_ssr_stec_correction_dep_a::MsgSsrStecCorrectionDepA;
pub use msg_ssr_tile_definition::MsgSsrTileDefinition;
pub use msg_ssr_tile_definition_dep::MsgSsrTileDefinitionDep;
pub use phase_biases_content::PhaseBiasesContent;
pub use satellite_apc::SatelliteAPC;
pub use stec_header::STECHeader;
pub use stec_header_dep_a::STECHeaderDepA;
pub use stec_residual::STECResidual;
pub use stec_residual_no_std::STECResidualNoStd;
pub use stec_sat_element::STECSatElement;
pub use tropospheric_delay_correction::TroposphericDelayCorrection;
pub use tropospheric_delay_correction_no_std::TroposphericDelayCorrectionNoStd;

pub mod code_biases_content {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod grid_definition_header_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod gridded_correction_header {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod gridded_correction_header_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod msg_ssr_code_biases {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod msg_ssr_code_phase_biases_bounds {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
    /// Stubbed version of Combined Code and Phase Biases Bounds
    #[cfg_attr(feature = "serde", derive(serde::Serialize))]
    #[derive(Debug, Clone)]
    pub struct MsgSsrCodePhaseBiasesBounds {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing))]
        pub sender_id: Option<u16>,
        #[cfg_attr(feature = "serde", serde(rename(serialize = "stub")))]
        pub stub: Vec<u8>,
    }

    impl ConcreteMessage for MsgSsrCodePhaseBiasesBounds {
        const MESSAGE_TYPE: u16 = 1516;
        const MESSAGE_NAME: &'static str = "MSG_SSR_CODE_PHASE_BIASES_BOUNDS";
    }

    impl SbpMessage for MsgSsrCodePhaseBiasesBounds {
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

    impl TryFrom<Sbp> for MsgSsrCodePhaseBiasesBounds {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgSsrCodePhaseBiasesBounds(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgSsrCodePhaseBiasesBounds {
        const MIN_LEN: usize = <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.stub)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.stub, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrCodePhaseBiasesBounds {
                sender_id: None,
                stub: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_ssr_gridded_correction {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod msg_ssr_gridded_correction_bounds {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
    /// Gridded troposhere and STEC correction residuals bounds
    #[cfg_attr(feature = "serde", derive(serde::Serialize))]
    #[derive(Debug, Clone)]
    pub struct MsgSsrGriddedCorrectionBounds {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing))]
        pub sender_id: Option<u16>,
        #[cfg_attr(feature = "serde", serde(rename(serialize = "stub")))]
        pub stub: Vec<u8>,
    }

    impl ConcreteMessage for MsgSsrGriddedCorrectionBounds {
        const MESSAGE_TYPE: u16 = 1534;
        const MESSAGE_NAME: &'static str = "MSG_SSR_GRIDDED_CORRECTION_BOUNDS";
    }

    impl SbpMessage for MsgSsrGriddedCorrectionBounds {
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

    impl TryFrom<Sbp> for MsgSsrGriddedCorrectionBounds {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgSsrGriddedCorrectionBounds(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgSsrGriddedCorrectionBounds {
        const MIN_LEN: usize = <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.stub)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.stub, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrGriddedCorrectionBounds {
                sender_id: None,
                stub: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_ssr_gridded_correction_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
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
}

pub mod msg_ssr_gridded_correction_no_std_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
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
}

pub mod msg_ssr_grid_definition_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
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
}

pub mod msg_ssr_orbit_clock {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod msg_ssr_orbit_clock_bounds {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
    /// Stubbed version of Combined Orbit and Clock Bound
    #[cfg_attr(feature = "serde", derive(serde::Serialize))]
    #[derive(Debug, Clone)]
    pub struct MsgSsrOrbitClockBounds {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing))]
        pub sender_id: Option<u16>,
        #[cfg_attr(feature = "serde", serde(rename(serialize = "stub")))]
        pub stub: Vec<u8>,
    }

    impl ConcreteMessage for MsgSsrOrbitClockBounds {
        const MESSAGE_TYPE: u16 = 1502;
        const MESSAGE_NAME: &'static str = "MSG_SSR_ORBIT_CLOCK_BOUNDS";
    }

    impl SbpMessage for MsgSsrOrbitClockBounds {
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

    impl TryFrom<Sbp> for MsgSsrOrbitClockBounds {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgSsrOrbitClockBounds(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgSsrOrbitClockBounds {
        const MIN_LEN: usize = <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.stub)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.stub, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrOrbitClockBounds {
                sender_id: None,
                stub: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_ssr_orbit_clock_bounds_degradation {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
    /// Combined Orbit and Clock Bound Degradation Parameter
    #[cfg_attr(feature = "serde", derive(serde::Serialize))]
    #[derive(Debug, Clone)]
    pub struct MsgSsrOrbitClockBoundsDegradation {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing))]
        pub sender_id: Option<u16>,
        #[cfg_attr(feature = "serde", serde(rename(serialize = "stub")))]
        pub stub: Vec<u8>,
    }

    impl ConcreteMessage for MsgSsrOrbitClockBoundsDegradation {
        const MESSAGE_TYPE: u16 = 1503;
        const MESSAGE_NAME: &'static str = "MSG_SSR_ORBIT_CLOCK_BOUNDS_DEGRADATION";
    }

    impl SbpMessage for MsgSsrOrbitClockBoundsDegradation {
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

    impl TryFrom<Sbp> for MsgSsrOrbitClockBoundsDegradation {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgSsrOrbitClockBoundsDegradation(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgSsrOrbitClockBoundsDegradation {
        const MIN_LEN: usize = <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.stub)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.stub, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrOrbitClockBoundsDegradation {
                sender_id: None,
                stub: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_ssr_orbit_clock_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
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
}

pub mod msg_ssr_phase_biases {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod msg_ssr_satellite_apc {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
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
}

pub mod msg_ssr_stec_correction {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
    /// STEC correction polynomial coefficients
    #[cfg_attr(feature = "serde", derive(serde::Serialize))]
    #[derive(Debug, Clone)]
    pub struct MsgSsrStecCorrection {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing))]
        pub sender_id: Option<u16>,
        #[cfg_attr(feature = "serde", serde(rename(serialize = "stub")))]
        pub stub: Vec<u8>,
    }

    impl ConcreteMessage for MsgSsrStecCorrection {
        const MESSAGE_TYPE: u16 = 1533;
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
        const MIN_LEN: usize = <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.stub)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.stub, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrStecCorrection {
                sender_id: None,
                stub: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_ssr_stec_correction_dep {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
    pub struct MsgSsrStecCorrectionDep {
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

    impl ConcreteMessage for MsgSsrStecCorrectionDep {
        const MESSAGE_TYPE: u16 = 1531;
        const MESSAGE_NAME: &'static str = "MSG_SSR_STEC_CORRECTION_DEP";
    }

    impl SbpMessage for MsgSsrStecCorrectionDep {
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

    impl TryFrom<Sbp> for MsgSsrStecCorrectionDep {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgSsrStecCorrectionDep(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgSsrStecCorrectionDep {
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
            MsgSsrStecCorrectionDep {
                sender_id: None,
                header: WireFormat::parse_unchecked(buf),
                stec_sat_list: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_ssr_stec_correction_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
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
}

pub mod msg_ssr_tile_definition {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
        #[cfg_attr(feature = "serde", serde(rename(serialize = "stub")))]
        pub stub: Vec<u8>,
    }

    impl ConcreteMessage for MsgSsrTileDefinition {
        const MESSAGE_TYPE: u16 = 1527;
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
        const MIN_LEN: usize = <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.stub)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.stub, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrTileDefinition {
                sender_id: None,
                stub: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_ssr_tile_definition_dep {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Definition of a SSR atmospheric correction tile.

    ///
    /// Provides the correction point coordinates for the atmospheric correction
    /// values in the MSG_SSR_STEC_CORRECTION_DEP and MSG_SSR_GRIDDED_CORRECTION
    /// messages.
    ///
    /// Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
    /// element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
    /// correction points, not lists of points.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize))]
    #[derive(Debug, Clone)]
    pub struct MsgSsrTileDefinitionDep {
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

    impl ConcreteMessage for MsgSsrTileDefinitionDep {
        const MESSAGE_TYPE: u16 = 1526;
        const MESSAGE_NAME: &'static str = "MSG_SSR_TILE_DEFINITION_DEP";
    }

    impl SbpMessage for MsgSsrTileDefinitionDep {
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

    impl TryFrom<Sbp> for MsgSsrTileDefinitionDep {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgSsrTileDefinitionDep(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgSsrTileDefinitionDep {
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
            MsgSsrTileDefinitionDep {
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
}

pub mod phase_biases_content {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod stec_header {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod stec_header_dep_a {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod stec_residual {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
        const MIN_LEN: usize = <SvId as WireFormat>::MIN_LEN
            + <i16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN;
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
}

pub mod stec_residual_no_std {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod stec_sat_element {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}

pub mod satellite_apc {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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

    impl SatelliteAPC {
        /// Gets the [SatelliteType][self::SatelliteType] stored in the `sat_info` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `SatelliteType` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `SatelliteType` were added.
        pub fn satellite_type(&self) -> Result<SatelliteType, u8> {
            get_bit_range!(self.sat_info, u8, u8, 4, 0).try_into()
        }

        /// Set the bitrange corresponding to the [SatelliteType][SatelliteType] of the `sat_info` bitfield.
        pub fn set_satellite_type(&mut self, satellite_type: SatelliteType) {
            set_bit_range!(&mut self.sat_info, satellite_type, u8, u8, 4, 0);
        }
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

    /// Satellite Type
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum SatelliteType {
        /// Unknown Type
        UnknownType = 0,

        /// GPS I
        GpsI = 1,

        /// GPS II
        GpsIi = 2,

        /// GPS IIA
        GpsIia = 3,

        /// GPS IIR
        GpsIir = 4,

        /// GPS IIF
        GpsIif = 5,

        /// GPS III
        GpsIii = 6,

        /// GLONASS
        GLONASS = 7,

        /// GLONASS M
        GlonassM = 8,

        /// GLONASS K1
        GlonassK1 = 9,

        /// GALILEO
        GALILEO = 10,

        /// BEIDOU 2G
        Beidou2G = 11,

        /// BEIDOU 2I
        Beidou2I = 12,

        /// BEIDOU 2M
        Beidou2M = 13,

        /// BEIDOU 3M, SECM
        Beidou3MSecm = 14,

        /// BEIDOU 3G, SECM
        Beidou3GSecm = 15,

        /// BEIDOU 3M, CAST
        Beidou3MCast = 16,

        /// BEIDOU 3G, CAST
        Beidou3GCast = 17,

        /// BEIDOU 3I, CAST
        Beidou3ICast = 18,

        /// QZSS
        QZSS = 19,
    }

    impl std::fmt::Display for SatelliteType {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                SatelliteType::UnknownType => f.write_str("Unknown Type"),
                SatelliteType::GpsI => f.write_str("GPS I"),
                SatelliteType::GpsIi => f.write_str("GPS II"),
                SatelliteType::GpsIia => f.write_str("GPS IIA"),
                SatelliteType::GpsIir => f.write_str("GPS IIR"),
                SatelliteType::GpsIif => f.write_str("GPS IIF"),
                SatelliteType::GpsIii => f.write_str("GPS III"),
                SatelliteType::GLONASS => f.write_str("GLONASS"),
                SatelliteType::GlonassM => f.write_str("GLONASS M"),
                SatelliteType::GlonassK1 => f.write_str("GLONASS K1"),
                SatelliteType::GALILEO => f.write_str("GALILEO"),
                SatelliteType::Beidou2G => f.write_str("BEIDOU 2G"),
                SatelliteType::Beidou2I => f.write_str("BEIDOU 2I"),
                SatelliteType::Beidou2M => f.write_str("BEIDOU 2M"),
                SatelliteType::Beidou3MSecm => f.write_str("BEIDOU 3M, SECM"),
                SatelliteType::Beidou3GSecm => f.write_str("BEIDOU 3G, SECM"),
                SatelliteType::Beidou3MCast => f.write_str("BEIDOU 3M, CAST"),
                SatelliteType::Beidou3GCast => f.write_str("BEIDOU 3G, CAST"),
                SatelliteType::Beidou3ICast => f.write_str("BEIDOU 3I, CAST"),
                SatelliteType::QZSS => f.write_str("QZSS"),
            }
        }
    }

    impl TryFrom<u8> for SatelliteType {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, Self::Error> {
            match i {
                0 => Ok(SatelliteType::UnknownType),
                1 => Ok(SatelliteType::GpsI),
                2 => Ok(SatelliteType::GpsIi),
                3 => Ok(SatelliteType::GpsIia),
                4 => Ok(SatelliteType::GpsIir),
                5 => Ok(SatelliteType::GpsIif),
                6 => Ok(SatelliteType::GpsIii),
                7 => Ok(SatelliteType::GLONASS),
                8 => Ok(SatelliteType::GlonassM),
                9 => Ok(SatelliteType::GlonassK1),
                10 => Ok(SatelliteType::GALILEO),
                11 => Ok(SatelliteType::Beidou2G),
                12 => Ok(SatelliteType::Beidou2I),
                13 => Ok(SatelliteType::Beidou2M),
                14 => Ok(SatelliteType::Beidou3MSecm),
                15 => Ok(SatelliteType::Beidou3GSecm),
                16 => Ok(SatelliteType::Beidou3MCast),
                17 => Ok(SatelliteType::Beidou3GCast),
                18 => Ok(SatelliteType::Beidou3ICast),
                19 => Ok(SatelliteType::QZSS),
                i => Err(i),
            }
        }
    }
}

pub mod tropospheric_delay_correction {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
        const MIN_LEN: usize = <i16 as WireFormat>::MIN_LEN
            + <i8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.hydro)
                + WireFormat::len(&self.wet)
                + WireFormat::len(&self.stddev)
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
}

pub mod tropospheric_delay_correction_no_std {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

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
}
