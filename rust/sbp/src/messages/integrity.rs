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
// Automatically generated from yaml/swiftnav/sbp/integrity.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Integrity flag messages
pub use integrity_ssr_header::IntegritySSRHeader;
pub use msg_ssr_flag_high_level::MsgSsrFlagHighLevel;
pub use msg_ssr_flag_iono_grid_point_sat_los::MsgSsrFlagIonoGridPointSatLos;
pub use msg_ssr_flag_iono_grid_points::MsgSsrFlagIonoGridPoints;
pub use msg_ssr_flag_iono_tile_sat_los::MsgSsrFlagIonoTileSatLos;
pub use msg_ssr_flag_satellites::MsgSsrFlagSatellites;
pub use msg_ssr_flag_tropo_grid_points::MsgSsrFlagTropoGridPoints;

pub mod integrity_ssr_header {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
    /// Common fields for SSR integrity messages
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct IntegritySSRHeader {
        /// GNSS reference time of the observation used to generate the flag.
        #[cfg_attr(feature = "serde", serde(rename = "obs_time"))]
        pub obs_time: GpsTimeSec,
        /// Number of messages in the dataset
        #[cfg_attr(feature = "serde", serde(rename = "num_msgs"))]
        pub num_msgs: u8,
        /// Position of this message in the dataset
        #[cfg_attr(feature = "serde", serde(rename = "seq_num"))]
        pub seq_num: u8,
        /// SSR Solution ID.
        #[cfg_attr(feature = "serde", serde(rename = "ssr_sol_id"))]
        pub ssr_sol_id: u8,
        /// Unique identifier of the set this tile belongs to.
        #[cfg_attr(feature = "serde", serde(rename = "tile_set_id"))]
        pub tile_set_id: u16,
        /// Unique identifier of this tile in the tile set.
        #[cfg_attr(feature = "serde", serde(rename = "tile_id"))]
        pub tile_id: u16,
        /// Chain and type of flag.
        #[cfg_attr(feature = "serde", serde(rename = "chain_id"))]
        pub chain_id: u8,
    }

    impl WireFormat for IntegritySSRHeader {
        const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.obs_time)
                + WireFormat::len(&self.num_msgs)
                + WireFormat::len(&self.seq_num)
                + WireFormat::len(&self.ssr_sol_id)
                + WireFormat::len(&self.tile_set_id)
                + WireFormat::len(&self.tile_id)
                + WireFormat::len(&self.chain_id)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.obs_time, buf);
            WireFormat::write(&self.num_msgs, buf);
            WireFormat::write(&self.seq_num, buf);
            WireFormat::write(&self.ssr_sol_id, buf);
            WireFormat::write(&self.tile_set_id, buf);
            WireFormat::write(&self.tile_id, buf);
            WireFormat::write(&self.chain_id, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            IntegritySSRHeader {
                obs_time: WireFormat::parse_unchecked(buf),
                num_msgs: WireFormat::parse_unchecked(buf),
                seq_num: WireFormat::parse_unchecked(buf),
                ssr_sol_id: WireFormat::parse_unchecked(buf),
                tile_set_id: WireFormat::parse_unchecked(buf),
                tile_id: WireFormat::parse_unchecked(buf),
                chain_id: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_ssr_flag_high_level {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// High level integrity flags
    ///
    /// Integrity monitoring flags for multiple aggregated elements. An element
    /// could be a satellite, SSR grid point, or SSR tile. A group of aggregated
    /// elements being monitored for integrity could refer to:
    ///
    /// - Satellites in a particular {GPS, GAL, BDS} constellation.
    ///
    /// - Satellites in the line-of-sight of a particular SSR tile.
    ///
    /// - Satellites in the line-of-sight of a particular SSR grid point.
    ///
    /// The integrity usage for a group of aggregated elements varies according to
    /// the integrity flag of the satellites comprising that group.
    ///
    /// SSR_INTEGRITY_USAGE_NOMINAL: All satellites received passed the integrity
    /// check and have flag INTEGRITY_FLAG_OK.
    ///
    /// SSR_INTEGRITY_USAGE_WARNING: A limited number of elements in the group
    /// failed the integrity check. Refer to more granular integrity messages for
    /// details on the specific failing elements.
    ///
    /// SSR_INTEGRITY_USAGE_ALERT: Most elements in the group failed the integrity
    /// check, do not use for positioning.
    ///
    /// SSR_INTEGRITY_USAGE_NOT_MONITORED: Unable to verify the integrity flag of
    /// elements in the group.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgSsrFlagHighLevel {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GNSS reference time of the observation used to generate the flag.
        #[cfg_attr(feature = "serde", serde(rename = "obs_time"))]
        pub obs_time: GpsTimeSec,
        /// GNSS reference time of the correction associated to the flag.
        #[cfg_attr(feature = "serde", serde(rename = "corr_time"))]
        pub corr_time: GpsTimeSec,
        /// SSR Solution ID.
        #[cfg_attr(feature = "serde", serde(rename = "ssr_sol_id"))]
        pub ssr_sol_id: u8,
        /// Unique identifier of the set this tile belongs to.
        #[cfg_attr(feature = "serde", serde(rename = "tile_set_id"))]
        pub tile_set_id: u16,
        /// Unique identifier of this tile in the tile set.
        #[cfg_attr(feature = "serde", serde(rename = "tile_id"))]
        pub tile_id: u16,
        /// Chain and type of flag.
        #[cfg_attr(feature = "serde", serde(rename = "chain_id"))]
        pub chain_id: u8,
        /// Use GPS satellites.
        #[cfg_attr(feature = "serde", serde(rename = "use_gps_sat"))]
        pub use_gps_sat: u8,
        /// Use GAL satellites.
        #[cfg_attr(feature = "serde", serde(rename = "use_gal_sat"))]
        pub use_gal_sat: u8,
        /// Use BDS satellites.
        #[cfg_attr(feature = "serde", serde(rename = "use_bds_sat"))]
        pub use_bds_sat: u8,
        /// Reserved
        #[cfg_attr(feature = "serde", serde(rename = "reserved"))]
        pub reserved: [u8; 6],
        /// Use tropo grid points.
        #[cfg_attr(feature = "serde", serde(rename = "use_tropo_grid_points"))]
        pub use_tropo_grid_points: u8,
        /// Use iono grid points.
        #[cfg_attr(feature = "serde", serde(rename = "use_iono_grid_points"))]
        pub use_iono_grid_points: u8,
        /// Use iono tile satellite LoS.
        #[cfg_attr(feature = "serde", serde(rename = "use_iono_tile_sat_los"))]
        pub use_iono_tile_sat_los: u8,
        /// Use iono grid point satellite LoS.
        #[cfg_attr(feature = "serde", serde(rename = "use_iono_grid_point_sat_los"))]
        pub use_iono_grid_point_sat_los: u8,
    }

    impl MsgSsrFlagHighLevel {
        /// Gets the [UseGpsSatellites][self::UseGpsSatellites] stored in the `use_gps_sat` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `UseGpsSatellites` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `UseGpsSatellites` were added.
        pub fn use_gps_satellites(&self) -> Result<UseGpsSatellites, u8> {
            get_bit_range!(self.use_gps_sat, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [UseGpsSatellites][UseGpsSatellites] of the `use_gps_sat` bitfield.
        pub fn set_use_gps_satellites(&mut self, use_gps_satellites: UseGpsSatellites) {
            set_bit_range!(&mut self.use_gps_sat, use_gps_satellites, u8, u8, 2, 0);
        }

        /// Gets the [UseGalSatellites][self::UseGalSatellites] stored in the `use_gal_sat` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `UseGalSatellites` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `UseGalSatellites` were added.
        pub fn use_gal_satellites(&self) -> Result<UseGalSatellites, u8> {
            get_bit_range!(self.use_gal_sat, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [UseGalSatellites][UseGalSatellites] of the `use_gal_sat` bitfield.
        pub fn set_use_gal_satellites(&mut self, use_gal_satellites: UseGalSatellites) {
            set_bit_range!(&mut self.use_gal_sat, use_gal_satellites, u8, u8, 2, 0);
        }

        /// Gets the [UseBdsSatellites][self::UseBdsSatellites] stored in the `use_bds_sat` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `UseBdsSatellites` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `UseBdsSatellites` were added.
        pub fn use_bds_satellites(&self) -> Result<UseBdsSatellites, u8> {
            get_bit_range!(self.use_bds_sat, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [UseBdsSatellites][UseBdsSatellites] of the `use_bds_sat` bitfield.
        pub fn set_use_bds_satellites(&mut self, use_bds_satellites: UseBdsSatellites) {
            set_bit_range!(&mut self.use_bds_sat, use_bds_satellites, u8, u8, 2, 0);
        }

        /// Gets the [UseTropoGridPoints][self::UseTropoGridPoints] stored in the `use_tropo_grid_points` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `UseTropoGridPoints` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `UseTropoGridPoints` were added.
        pub fn use_tropo_grid_points(&self) -> Result<UseTropoGridPoints, u8> {
            get_bit_range!(self.use_tropo_grid_points, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [UseTropoGridPoints][UseTropoGridPoints] of the `use_tropo_grid_points` bitfield.
        pub fn set_use_tropo_grid_points(&mut self, use_tropo_grid_points: UseTropoGridPoints) {
            set_bit_range!(
                &mut self.use_tropo_grid_points,
                use_tropo_grid_points,
                u8,
                u8,
                2,
                0
            );
        }

        /// Gets the [UseIonoGridPoints][self::UseIonoGridPoints] stored in the `use_iono_grid_points` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `UseIonoGridPoints` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `UseIonoGridPoints` were added.
        pub fn use_iono_grid_points(&self) -> Result<UseIonoGridPoints, u8> {
            get_bit_range!(self.use_iono_grid_points, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [UseIonoGridPoints][UseIonoGridPoints] of the `use_iono_grid_points` bitfield.
        pub fn set_use_iono_grid_points(&mut self, use_iono_grid_points: UseIonoGridPoints) {
            set_bit_range!(
                &mut self.use_iono_grid_points,
                use_iono_grid_points,
                u8,
                u8,
                2,
                0
            );
        }

        /// Gets the [UseIonoTileSatelliteLoS][self::UseIonoTileSatelliteLoS] stored in the `use_iono_tile_sat_los` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `UseIonoTileSatelliteLoS` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `UseIonoTileSatelliteLoS` were added.
        pub fn use_iono_tile_satellite_lo_s(&self) -> Result<UseIonoTileSatelliteLoS, u8> {
            get_bit_range!(self.use_iono_tile_sat_los, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [UseIonoTileSatelliteLoS][UseIonoTileSatelliteLoS] of the `use_iono_tile_sat_los` bitfield.
        pub fn set_use_iono_tile_satellite_lo_s(
            &mut self,
            use_iono_tile_satellite_lo_s: UseIonoTileSatelliteLoS,
        ) {
            set_bit_range!(
                &mut self.use_iono_tile_sat_los,
                use_iono_tile_satellite_lo_s,
                u8,
                u8,
                2,
                0
            );
        }

        /// Gets the [UseIonoGridPointSatelliteLoS][self::UseIonoGridPointSatelliteLoS] stored in the `use_iono_grid_point_sat_los` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `UseIonoGridPointSatelliteLoS` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `UseIonoGridPointSatelliteLoS` were added.
        pub fn use_iono_grid_point_satellite_lo_s(
            &self,
        ) -> Result<UseIonoGridPointSatelliteLoS, u8> {
            get_bit_range!(self.use_iono_grid_point_sat_los, u8, u8, 2, 0).try_into()
        }

        /// Set the bitrange corresponding to the [UseIonoGridPointSatelliteLoS][UseIonoGridPointSatelliteLoS] of the `use_iono_grid_point_sat_los` bitfield.
        pub fn set_use_iono_grid_point_satellite_lo_s(
            &mut self,
            use_iono_grid_point_satellite_lo_s: UseIonoGridPointSatelliteLoS,
        ) {
            set_bit_range!(
                &mut self.use_iono_grid_point_sat_los,
                use_iono_grid_point_satellite_lo_s,
                u8,
                u8,
                2,
                0
            );
        }
    }

    impl ConcreteMessage for MsgSsrFlagHighLevel {
        const MESSAGE_TYPE: u16 = 3001;
        const MESSAGE_NAME: &'static str = "MSG_SSR_FLAG_HIGH_LEVEL";
    }

    impl SbpMessage for MsgSsrFlagHighLevel {
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

    impl TryFrom<Sbp> for MsgSsrFlagHighLevel {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgSsrFlagHighLevel(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgSsrFlagHighLevel {
        const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN
            + <GpsTimeSec as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <[u8; 6] as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.obs_time)
                + WireFormat::len(&self.corr_time)
                + WireFormat::len(&self.ssr_sol_id)
                + WireFormat::len(&self.tile_set_id)
                + WireFormat::len(&self.tile_id)
                + WireFormat::len(&self.chain_id)
                + WireFormat::len(&self.use_gps_sat)
                + WireFormat::len(&self.use_gal_sat)
                + WireFormat::len(&self.use_bds_sat)
                + WireFormat::len(&self.reserved)
                + WireFormat::len(&self.use_tropo_grid_points)
                + WireFormat::len(&self.use_iono_grid_points)
                + WireFormat::len(&self.use_iono_tile_sat_los)
                + WireFormat::len(&self.use_iono_grid_point_sat_los)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.obs_time, buf);
            WireFormat::write(&self.corr_time, buf);
            WireFormat::write(&self.ssr_sol_id, buf);
            WireFormat::write(&self.tile_set_id, buf);
            WireFormat::write(&self.tile_id, buf);
            WireFormat::write(&self.chain_id, buf);
            WireFormat::write(&self.use_gps_sat, buf);
            WireFormat::write(&self.use_gal_sat, buf);
            WireFormat::write(&self.use_bds_sat, buf);
            WireFormat::write(&self.reserved, buf);
            WireFormat::write(&self.use_tropo_grid_points, buf);
            WireFormat::write(&self.use_iono_grid_points, buf);
            WireFormat::write(&self.use_iono_tile_sat_los, buf);
            WireFormat::write(&self.use_iono_grid_point_sat_los, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrFlagHighLevel {
                sender_id: None,
                obs_time: WireFormat::parse_unchecked(buf),
                corr_time: WireFormat::parse_unchecked(buf),
                ssr_sol_id: WireFormat::parse_unchecked(buf),
                tile_set_id: WireFormat::parse_unchecked(buf),
                tile_id: WireFormat::parse_unchecked(buf),
                chain_id: WireFormat::parse_unchecked(buf),
                use_gps_sat: WireFormat::parse_unchecked(buf),
                use_gal_sat: WireFormat::parse_unchecked(buf),
                use_bds_sat: WireFormat::parse_unchecked(buf),
                reserved: WireFormat::parse_unchecked(buf),
                use_tropo_grid_points: WireFormat::parse_unchecked(buf),
                use_iono_grid_points: WireFormat::parse_unchecked(buf),
                use_iono_tile_sat_los: WireFormat::parse_unchecked(buf),
                use_iono_grid_point_sat_los: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Use GPS satellites.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum UseGpsSatellites {
        /// Nominal
        Nominal = 0,

        /// Warning
        Warning = 1,

        /// Alert
        Alert = 2,

        /// Not monitored
        NotMonitored = 3,
    }

    impl std::fmt::Display for UseGpsSatellites {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                UseGpsSatellites::Nominal => f.write_str("Nominal"),
                UseGpsSatellites::Warning => f.write_str("Warning"),
                UseGpsSatellites::Alert => f.write_str("Alert"),
                UseGpsSatellites::NotMonitored => f.write_str("Not monitored"),
            }
        }
    }

    impl TryFrom<u8> for UseGpsSatellites {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(UseGpsSatellites::Nominal),
                1 => Ok(UseGpsSatellites::Warning),
                2 => Ok(UseGpsSatellites::Alert),
                3 => Ok(UseGpsSatellites::NotMonitored),
                i => Err(i),
            }
        }
    }

    /// Use GAL satellites.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum UseGalSatellites {
        /// Nominal
        Nominal = 0,

        /// Warning
        Warning = 1,

        /// Alert
        Alert = 2,

        /// Not monitored
        NotMonitored = 3,
    }

    impl std::fmt::Display for UseGalSatellites {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                UseGalSatellites::Nominal => f.write_str("Nominal"),
                UseGalSatellites::Warning => f.write_str("Warning"),
                UseGalSatellites::Alert => f.write_str("Alert"),
                UseGalSatellites::NotMonitored => f.write_str("Not monitored"),
            }
        }
    }

    impl TryFrom<u8> for UseGalSatellites {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(UseGalSatellites::Nominal),
                1 => Ok(UseGalSatellites::Warning),
                2 => Ok(UseGalSatellites::Alert),
                3 => Ok(UseGalSatellites::NotMonitored),
                i => Err(i),
            }
        }
    }

    /// Use BDS satellites.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum UseBdsSatellites {
        /// Nominal
        Nominal = 0,

        /// Warning
        Warning = 1,

        /// Alert
        Alert = 2,

        /// Not monitored
        NotMonitored = 3,
    }

    impl std::fmt::Display for UseBdsSatellites {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                UseBdsSatellites::Nominal => f.write_str("Nominal"),
                UseBdsSatellites::Warning => f.write_str("Warning"),
                UseBdsSatellites::Alert => f.write_str("Alert"),
                UseBdsSatellites::NotMonitored => f.write_str("Not monitored"),
            }
        }
    }

    impl TryFrom<u8> for UseBdsSatellites {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(UseBdsSatellites::Nominal),
                1 => Ok(UseBdsSatellites::Warning),
                2 => Ok(UseBdsSatellites::Alert),
                3 => Ok(UseBdsSatellites::NotMonitored),
                i => Err(i),
            }
        }
    }

    /// Use tropo grid points.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum UseTropoGridPoints {
        /// Nominal
        Nominal = 0,

        /// Warning
        Warning = 1,

        /// Alert
        Alert = 2,

        /// Not monitored
        NotMonitored = 3,
    }

    impl std::fmt::Display for UseTropoGridPoints {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                UseTropoGridPoints::Nominal => f.write_str("Nominal"),
                UseTropoGridPoints::Warning => f.write_str("Warning"),
                UseTropoGridPoints::Alert => f.write_str("Alert"),
                UseTropoGridPoints::NotMonitored => f.write_str("Not monitored"),
            }
        }
    }

    impl TryFrom<u8> for UseTropoGridPoints {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(UseTropoGridPoints::Nominal),
                1 => Ok(UseTropoGridPoints::Warning),
                2 => Ok(UseTropoGridPoints::Alert),
                3 => Ok(UseTropoGridPoints::NotMonitored),
                i => Err(i),
            }
        }
    }

    /// Use iono grid points.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum UseIonoGridPoints {
        /// Nominal
        Nominal = 0,

        /// Warning
        Warning = 1,

        /// Alert
        Alert = 2,

        /// Not monitored
        NotMonitored = 3,
    }

    impl std::fmt::Display for UseIonoGridPoints {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                UseIonoGridPoints::Nominal => f.write_str("Nominal"),
                UseIonoGridPoints::Warning => f.write_str("Warning"),
                UseIonoGridPoints::Alert => f.write_str("Alert"),
                UseIonoGridPoints::NotMonitored => f.write_str("Not monitored"),
            }
        }
    }

    impl TryFrom<u8> for UseIonoGridPoints {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(UseIonoGridPoints::Nominal),
                1 => Ok(UseIonoGridPoints::Warning),
                2 => Ok(UseIonoGridPoints::Alert),
                3 => Ok(UseIonoGridPoints::NotMonitored),
                i => Err(i),
            }
        }
    }

    /// Use iono tile satellite LoS.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum UseIonoTileSatelliteLoS {
        /// Nominal
        Nominal = 0,

        /// Warning
        Warning = 1,

        /// Alert
        Alert = 2,

        /// Not monitored
        NotMonitored = 3,
    }

    impl std::fmt::Display for UseIonoTileSatelliteLoS {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                UseIonoTileSatelliteLoS::Nominal => f.write_str("Nominal"),
                UseIonoTileSatelliteLoS::Warning => f.write_str("Warning"),
                UseIonoTileSatelliteLoS::Alert => f.write_str("Alert"),
                UseIonoTileSatelliteLoS::NotMonitored => f.write_str("Not monitored"),
            }
        }
    }

    impl TryFrom<u8> for UseIonoTileSatelliteLoS {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(UseIonoTileSatelliteLoS::Nominal),
                1 => Ok(UseIonoTileSatelliteLoS::Warning),
                2 => Ok(UseIonoTileSatelliteLoS::Alert),
                3 => Ok(UseIonoTileSatelliteLoS::NotMonitored),
                i => Err(i),
            }
        }
    }

    /// Use iono grid point satellite LoS.
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum UseIonoGridPointSatelliteLoS {
        /// Nominal
        Nominal = 0,

        /// Warning
        Warning = 1,

        /// Alert
        Alert = 2,

        /// Not monitored
        NotMonitored = 3,
    }

    impl std::fmt::Display for UseIonoGridPointSatelliteLoS {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                UseIonoGridPointSatelliteLoS::Nominal => f.write_str("Nominal"),
                UseIonoGridPointSatelliteLoS::Warning => f.write_str("Warning"),
                UseIonoGridPointSatelliteLoS::Alert => f.write_str("Alert"),
                UseIonoGridPointSatelliteLoS::NotMonitored => f.write_str("Not monitored"),
            }
        }
    }

    impl TryFrom<u8> for UseIonoGridPointSatelliteLoS {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(UseIonoGridPointSatelliteLoS::Nominal),
                1 => Ok(UseIonoGridPointSatelliteLoS::Warning),
                2 => Ok(UseIonoGridPointSatelliteLoS::Alert),
                3 => Ok(UseIonoGridPointSatelliteLoS::NotMonitored),
                i => Err(i),
            }
        }
    }
}

pub mod msg_ssr_flag_iono_grid_points {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
    /// List of grid points which are faulty
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgSsrFlagIonoGridPoints {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Header of an integrity message.
        #[cfg_attr(feature = "serde", serde(rename = "header"))]
        pub header: IntegritySSRHeader,
        /// Number of faulty grid points.
        #[cfg_attr(feature = "serde", serde(rename = "n_faulty_points"))]
        pub n_faulty_points: u8,
        /// List of faulty grid points.
        #[cfg_attr(feature = "serde", serde(rename = "faulty_points"))]
        pub faulty_points: Vec<u16>,
    }

    impl ConcreteMessage for MsgSsrFlagIonoGridPoints {
        const MESSAGE_TYPE: u16 = 3015;
        const MESSAGE_NAME: &'static str = "MSG_SSR_FLAG_IONO_GRID_POINTS";
    }

    impl SbpMessage for MsgSsrFlagIonoGridPoints {
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

    impl TryFrom<Sbp> for MsgSsrFlagIonoGridPoints {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgSsrFlagIonoGridPoints(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgSsrFlagIonoGridPoints {
        const MIN_LEN: usize = <IntegritySSRHeader as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <Vec<u16> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.header)
                + WireFormat::len(&self.n_faulty_points)
                + WireFormat::len(&self.faulty_points)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.header, buf);
            WireFormat::write(&self.n_faulty_points, buf);
            WireFormat::write(&self.faulty_points, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrFlagIonoGridPoints {
                sender_id: None,
                header: WireFormat::parse_unchecked(buf),
                n_faulty_points: WireFormat::parse_unchecked(buf),
                faulty_points: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_ssr_flag_iono_grid_point_sat_los {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
    /// List of all the grid points to satellite which are faulty
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgSsrFlagIonoGridPointSatLos {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Header of an integrity message.
        #[cfg_attr(feature = "serde", serde(rename = "header"))]
        pub header: IntegritySSRHeader,
        /// Index of the grid point.
        #[cfg_attr(feature = "serde", serde(rename = "grid_point_id"))]
        pub grid_point_id: u16,
        /// Number of faulty LOS.
        #[cfg_attr(feature = "serde", serde(rename = "n_faulty_los"))]
        pub n_faulty_los: u8,
        /// List of faulty LOS
        #[cfg_attr(feature = "serde", serde(rename = "faulty_los"))]
        pub faulty_los: Vec<SvId>,
    }

    impl ConcreteMessage for MsgSsrFlagIonoGridPointSatLos {
        const MESSAGE_TYPE: u16 = 3025;
        const MESSAGE_NAME: &'static str = "MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS";
    }

    impl SbpMessage for MsgSsrFlagIonoGridPointSatLos {
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

    impl TryFrom<Sbp> for MsgSsrFlagIonoGridPointSatLos {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgSsrFlagIonoGridPointSatLos(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgSsrFlagIonoGridPointSatLos {
        const MIN_LEN: usize = <IntegritySSRHeader as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <Vec<SvId> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.header)
                + WireFormat::len(&self.grid_point_id)
                + WireFormat::len(&self.n_faulty_los)
                + WireFormat::len(&self.faulty_los)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.header, buf);
            WireFormat::write(&self.grid_point_id, buf);
            WireFormat::write(&self.n_faulty_los, buf);
            WireFormat::write(&self.faulty_los, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrFlagIonoGridPointSatLos {
                sender_id: None,
                header: WireFormat::parse_unchecked(buf),
                grid_point_id: WireFormat::parse_unchecked(buf),
                n_faulty_los: WireFormat::parse_unchecked(buf),
                faulty_los: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_ssr_flag_iono_tile_sat_los {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
    /// List of all the LOS which are faulty
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgSsrFlagIonoTileSatLos {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Header of an integrity message.
        #[cfg_attr(feature = "serde", serde(rename = "header"))]
        pub header: IntegritySSRHeader,
        /// Number of faulty LOS.
        #[cfg_attr(feature = "serde", serde(rename = "n_faulty_los"))]
        pub n_faulty_los: u8,
        /// List of faulty LOS
        #[cfg_attr(feature = "serde", serde(rename = "faulty_los"))]
        pub faulty_los: Vec<SvId>,
    }

    impl ConcreteMessage for MsgSsrFlagIonoTileSatLos {
        const MESSAGE_TYPE: u16 = 3021;
        const MESSAGE_NAME: &'static str = "MSG_SSR_FLAG_IONO_TILE_SAT_LOS";
    }

    impl SbpMessage for MsgSsrFlagIonoTileSatLos {
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

    impl TryFrom<Sbp> for MsgSsrFlagIonoTileSatLos {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgSsrFlagIonoTileSatLos(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgSsrFlagIonoTileSatLos {
        const MIN_LEN: usize = <IntegritySSRHeader as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <Vec<SvId> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.header)
                + WireFormat::len(&self.n_faulty_los)
                + WireFormat::len(&self.faulty_los)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.header, buf);
            WireFormat::write(&self.n_faulty_los, buf);
            WireFormat::write(&self.faulty_los, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrFlagIonoTileSatLos {
                sender_id: None,
                header: WireFormat::parse_unchecked(buf),
                n_faulty_los: WireFormat::parse_unchecked(buf),
                faulty_los: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_ssr_flag_satellites {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
    /// List of satellites which are faulty, per constellation
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgSsrFlagSatellites {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GNSS reference time of the observation used to generate the flag.
        #[cfg_attr(feature = "serde", serde(rename = "obs_time"))]
        pub obs_time: GpsTimeSec,
        /// Number of messages in the dataset
        #[cfg_attr(feature = "serde", serde(rename = "num_msgs"))]
        pub num_msgs: u8,
        /// Position of this message in the dataset
        #[cfg_attr(feature = "serde", serde(rename = "seq_num"))]
        pub seq_num: u8,
        /// SSR Solution ID.
        #[cfg_attr(feature = "serde", serde(rename = "ssr_sol_id"))]
        pub ssr_sol_id: u8,
        /// Chain and type of flag.
        #[cfg_attr(feature = "serde", serde(rename = "chain_id"))]
        pub chain_id: u8,
        /// Constellation ID.
        #[cfg_attr(feature = "serde", serde(rename = "const_id"))]
        pub const_id: u8,
        /// Number of faulty satellites.
        #[cfg_attr(feature = "serde", serde(rename = "n_faulty_sats"))]
        pub n_faulty_sats: u8,
        /// List of faulty satellites.
        #[cfg_attr(feature = "serde", serde(rename = "faulty_sats"))]
        pub faulty_sats: Vec<u8>,
    }

    impl ConcreteMessage for MsgSsrFlagSatellites {
        const MESSAGE_TYPE: u16 = 3005;
        const MESSAGE_NAME: &'static str = "MSG_SSR_FLAG_SATELLITES";
    }

    impl SbpMessage for MsgSsrFlagSatellites {
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

    impl TryFrom<Sbp> for MsgSsrFlagSatellites {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgSsrFlagSatellites(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgSsrFlagSatellites {
        const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.obs_time)
                + WireFormat::len(&self.num_msgs)
                + WireFormat::len(&self.seq_num)
                + WireFormat::len(&self.ssr_sol_id)
                + WireFormat::len(&self.chain_id)
                + WireFormat::len(&self.const_id)
                + WireFormat::len(&self.n_faulty_sats)
                + WireFormat::len(&self.faulty_sats)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.obs_time, buf);
            WireFormat::write(&self.num_msgs, buf);
            WireFormat::write(&self.seq_num, buf);
            WireFormat::write(&self.ssr_sol_id, buf);
            WireFormat::write(&self.chain_id, buf);
            WireFormat::write(&self.const_id, buf);
            WireFormat::write(&self.n_faulty_sats, buf);
            WireFormat::write(&self.faulty_sats, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrFlagSatellites {
                sender_id: None,
                obs_time: WireFormat::parse_unchecked(buf),
                num_msgs: WireFormat::parse_unchecked(buf),
                seq_num: WireFormat::parse_unchecked(buf),
                ssr_sol_id: WireFormat::parse_unchecked(buf),
                chain_id: WireFormat::parse_unchecked(buf),
                const_id: WireFormat::parse_unchecked(buf),
                n_faulty_sats: WireFormat::parse_unchecked(buf),
                faulty_sats: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod msg_ssr_flag_tropo_grid_points {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
    /// List of grid points which are faulty
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgSsrFlagTropoGridPoints {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// Header of an integrity message.
        #[cfg_attr(feature = "serde", serde(rename = "header"))]
        pub header: IntegritySSRHeader,
        /// Number of faulty grid points.
        #[cfg_attr(feature = "serde", serde(rename = "n_faulty_points"))]
        pub n_faulty_points: u8,
        /// List of faulty grid points.
        #[cfg_attr(feature = "serde", serde(rename = "faulty_points"))]
        pub faulty_points: Vec<u16>,
    }

    impl ConcreteMessage for MsgSsrFlagTropoGridPoints {
        const MESSAGE_TYPE: u16 = 3011;
        const MESSAGE_NAME: &'static str = "MSG_SSR_FLAG_TROPO_GRID_POINTS";
    }

    impl SbpMessage for MsgSsrFlagTropoGridPoints {
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

    impl TryFrom<Sbp> for MsgSsrFlagTropoGridPoints {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgSsrFlagTropoGridPoints(m) => Ok(m),
                _ => Err(TryFromSbpError),
            }
        }
    }

    impl WireFormat for MsgSsrFlagTropoGridPoints {
        const MIN_LEN: usize = <IntegritySSRHeader as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <Vec<u16> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.header)
                + WireFormat::len(&self.n_faulty_points)
                + WireFormat::len(&self.faulty_points)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.header, buf);
            WireFormat::write(&self.n_faulty_points, buf);
            WireFormat::write(&self.faulty_points, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrFlagTropoGridPoints {
                sender_id: None,
                header: WireFormat::parse_unchecked(buf),
                n_faulty_points: WireFormat::parse_unchecked(buf),
                faulty_points: WireFormat::parse_unchecked(buf),
            }
        }
    }
}
