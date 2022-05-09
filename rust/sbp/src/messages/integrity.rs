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
pub use msg_ssr_flag_high_level::MsgSsrFlagHighLevel;
pub use msg_ssr_flag_iono_grid_point_sat_los::MsgSsrFlagIonoGridPointSatLos;
pub use msg_ssr_flag_iono_grid_points::MsgSsrFlagIonoGridPoints;
pub use msg_ssr_flag_iono_tile_sat_los::MsgSsrFlagIonoTileSatLos;
pub use msg_ssr_flag_satellites::MsgSsrFlagSatellites;
pub use msg_ssr_flag_tropo_grid_points::MsgSsrFlagTropoGridPoints;

pub mod msg_ssr_flag_high_level {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
    /// High level integrity flags
    #[cfg_attr(feature = "serde", derive(serde::Serialize))]
    #[derive(Debug, Clone)]
    pub struct MsgSsrFlagHighLevel {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing))]
        pub sender_id: Option<u16>,
        /// GNSS reference time of the observation used to generate the flag.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "obs_time")))]
        pub obs_time: GpsTimeSec,
        /// GNSS reference time of the correction associated to the flag.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "corr_time")))]
        pub corr_time: GpsTimeSec,
        /// SSR Solution ID.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "ssr_sol_id")))]
        pub ssr_sol_id: u8,
        /// Unique identifier of the set this tile belongs to.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "tile_set_id")))]
        pub tile_set_id: u16,
        /// Unique identifier of this tile in the tile set.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "tile_id")))]
        pub tile_id: u16,
        /// Chain and type of flag.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "chain_id")))]
        pub chain_id: u8,
        /// Use GPS satellites.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "use_gps_sat")))]
        pub use_gps_sat: u8,
        /// Use GAL satellites.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "use_gal_sat")))]
        pub use_gal_sat: u8,
        /// Use BDS satellites.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "use_bds_sat")))]
        pub use_bds_sat: u8,
        /// Reserved
        #[cfg_attr(feature = "serde", serde(rename(serialize = "reserved")))]
        pub reserved: [u8; 6],
        /// Use tropo grid points.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "use_tropo_grid_points")))]
        pub use_tropo_grid_points: u8,
        /// Use iono grid points.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "use_iono_grid_points")))]
        pub use_iono_grid_points: u8,
        /// Use iono tile satellite LoS.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "use_iono_tile_sat_los")))]
        pub use_iono_tile_sat_los: u8,
        /// Use iono grid point satellite LoS.
        #[cfg_attr(
            feature = "serde",
            serde(rename(serialize = "use_iono_grid_point_sat_los"))
        )]
        pub use_iono_grid_point_sat_los: u8,
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
}

pub mod msg_ssr_flag_iono_grid_points {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
    /// List of grid points which are faulty
    #[cfg_attr(feature = "serde", derive(serde::Serialize))]
    #[derive(Debug, Clone)]
    pub struct MsgSsrFlagIonoGridPoints {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing))]
        pub sender_id: Option<u16>,
        /// GNSS reference time of the observation used to generate the flag.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "obs_time")))]
        pub obs_time: GpsTimeSec,
        /// Number of messages in the dataset
        #[cfg_attr(feature = "serde", serde(rename(serialize = "num_msgs")))]
        pub num_msgs: u8,
        /// Position of this message in the dataset
        #[cfg_attr(feature = "serde", serde(rename(serialize = "seq_num")))]
        pub seq_num: u8,
        /// SSR Solution ID.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "ssr_sol_id")))]
        pub ssr_sol_id: u8,
        /// Unique identifier of the set this tile belongs to.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "tile_set_id")))]
        pub tile_set_id: u16,
        /// Unique identifier of this tile in the tile set.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "tile_id")))]
        pub tile_id: u16,
        /// Chain and type of flag.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "chain_id")))]
        pub chain_id: u8,
        /// Number of faulty grid points.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "n_faulty_points")))]
        pub n_faulty_points: u8,
        /// List of faulty grid points.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "faulty_points")))]
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
        const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <Vec<u16> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.obs_time)
                + WireFormat::len(&self.num_msgs)
                + WireFormat::len(&self.seq_num)
                + WireFormat::len(&self.ssr_sol_id)
                + WireFormat::len(&self.tile_set_id)
                + WireFormat::len(&self.tile_id)
                + WireFormat::len(&self.chain_id)
                + WireFormat::len(&self.n_faulty_points)
                + WireFormat::len(&self.faulty_points)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.obs_time, buf);
            WireFormat::write(&self.num_msgs, buf);
            WireFormat::write(&self.seq_num, buf);
            WireFormat::write(&self.ssr_sol_id, buf);
            WireFormat::write(&self.tile_set_id, buf);
            WireFormat::write(&self.tile_id, buf);
            WireFormat::write(&self.chain_id, buf);
            WireFormat::write(&self.n_faulty_points, buf);
            WireFormat::write(&self.faulty_points, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrFlagIonoGridPoints {
                sender_id: None,
                obs_time: WireFormat::parse_unchecked(buf),
                num_msgs: WireFormat::parse_unchecked(buf),
                seq_num: WireFormat::parse_unchecked(buf),
                ssr_sol_id: WireFormat::parse_unchecked(buf),
                tile_set_id: WireFormat::parse_unchecked(buf),
                tile_id: WireFormat::parse_unchecked(buf),
                chain_id: WireFormat::parse_unchecked(buf),
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize))]
    #[derive(Debug, Clone)]
    pub struct MsgSsrFlagIonoGridPointSatLos {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing))]
        pub sender_id: Option<u16>,
        /// GNSS reference time of the observation used to generate the flag.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "obs_time")))]
        pub obs_time: GpsTimeSec,
        /// Number of messages in the dataset
        #[cfg_attr(feature = "serde", serde(rename(serialize = "num_msgs")))]
        pub num_msgs: u8,
        /// Position of this message in the dataset
        #[cfg_attr(feature = "serde", serde(rename(serialize = "seq_num")))]
        pub seq_num: u8,
        /// SSR Solution ID.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "ssr_sol_id")))]
        pub ssr_sol_id: u8,
        /// Unique identifier of the set this tile belongs to.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "tile_set_id")))]
        pub tile_set_id: u16,
        /// Unique identifier of this tile in the tile set.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "tile_id")))]
        pub tile_id: u16,
        /// Chain and type of flag.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "chain_id")))]
        pub chain_id: u8,
        /// Index of the grid point.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "grid_point_id")))]
        pub grid_point_id: u16,
        /// Number of faulty LOS.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "n_faulty_los")))]
        pub n_faulty_los: u8,
        /// List of faulty LOS
        #[cfg_attr(feature = "serde", serde(rename(serialize = "faulty_los")))]
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
        const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <Vec<SvId> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.obs_time)
                + WireFormat::len(&self.num_msgs)
                + WireFormat::len(&self.seq_num)
                + WireFormat::len(&self.ssr_sol_id)
                + WireFormat::len(&self.tile_set_id)
                + WireFormat::len(&self.tile_id)
                + WireFormat::len(&self.chain_id)
                + WireFormat::len(&self.grid_point_id)
                + WireFormat::len(&self.n_faulty_los)
                + WireFormat::len(&self.faulty_los)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.obs_time, buf);
            WireFormat::write(&self.num_msgs, buf);
            WireFormat::write(&self.seq_num, buf);
            WireFormat::write(&self.ssr_sol_id, buf);
            WireFormat::write(&self.tile_set_id, buf);
            WireFormat::write(&self.tile_id, buf);
            WireFormat::write(&self.chain_id, buf);
            WireFormat::write(&self.grid_point_id, buf);
            WireFormat::write(&self.n_faulty_los, buf);
            WireFormat::write(&self.faulty_los, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrFlagIonoGridPointSatLos {
                sender_id: None,
                obs_time: WireFormat::parse_unchecked(buf),
                num_msgs: WireFormat::parse_unchecked(buf),
                seq_num: WireFormat::parse_unchecked(buf),
                ssr_sol_id: WireFormat::parse_unchecked(buf),
                tile_set_id: WireFormat::parse_unchecked(buf),
                tile_id: WireFormat::parse_unchecked(buf),
                chain_id: WireFormat::parse_unchecked(buf),
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize))]
    #[derive(Debug, Clone)]
    pub struct MsgSsrFlagIonoTileSatLos {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing))]
        pub sender_id: Option<u16>,
        /// GNSS reference time of the observation used to generate the flag.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "obs_time")))]
        pub obs_time: GpsTimeSec,
        /// Number of messages in the dataset
        #[cfg_attr(feature = "serde", serde(rename(serialize = "num_msgs")))]
        pub num_msgs: u8,
        /// Position of this message in the dataset
        #[cfg_attr(feature = "serde", serde(rename(serialize = "seq_num")))]
        pub seq_num: u8,
        /// SSR Solution ID.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "ssr_sol_id")))]
        pub ssr_sol_id: u8,
        /// Unique identifier of the set this tile belongs to.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "tile_set_id")))]
        pub tile_set_id: u16,
        /// Unique identifier of this tile in the tile set.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "tile_id")))]
        pub tile_id: u16,
        /// Chain and type of flag.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "chain_id")))]
        pub chain_id: u8,
        /// Number of faulty LOS.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "n_faulty_los")))]
        pub n_faulty_los: u8,
        /// List of faulty LOS
        #[cfg_attr(feature = "serde", serde(rename(serialize = "faulty_los")))]
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
        const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <Vec<SvId> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.obs_time)
                + WireFormat::len(&self.num_msgs)
                + WireFormat::len(&self.seq_num)
                + WireFormat::len(&self.ssr_sol_id)
                + WireFormat::len(&self.tile_set_id)
                + WireFormat::len(&self.tile_id)
                + WireFormat::len(&self.chain_id)
                + WireFormat::len(&self.n_faulty_los)
                + WireFormat::len(&self.faulty_los)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.obs_time, buf);
            WireFormat::write(&self.num_msgs, buf);
            WireFormat::write(&self.seq_num, buf);
            WireFormat::write(&self.ssr_sol_id, buf);
            WireFormat::write(&self.tile_set_id, buf);
            WireFormat::write(&self.tile_id, buf);
            WireFormat::write(&self.chain_id, buf);
            WireFormat::write(&self.n_faulty_los, buf);
            WireFormat::write(&self.faulty_los, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrFlagIonoTileSatLos {
                sender_id: None,
                obs_time: WireFormat::parse_unchecked(buf),
                num_msgs: WireFormat::parse_unchecked(buf),
                seq_num: WireFormat::parse_unchecked(buf),
                ssr_sol_id: WireFormat::parse_unchecked(buf),
                tile_set_id: WireFormat::parse_unchecked(buf),
                tile_id: WireFormat::parse_unchecked(buf),
                chain_id: WireFormat::parse_unchecked(buf),
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize))]
    #[derive(Debug, Clone)]
    pub struct MsgSsrFlagSatellites {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing))]
        pub sender_id: Option<u16>,
        /// GNSS reference time of the observation used to generate the flag.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "obs_time")))]
        pub obs_time: GpsTimeSec,
        /// Number of messages in the dataset
        #[cfg_attr(feature = "serde", serde(rename(serialize = "num_msgs")))]
        pub num_msgs: u8,
        /// Position of this message in the dataset
        #[cfg_attr(feature = "serde", serde(rename(serialize = "seq_num")))]
        pub seq_num: u8,
        /// SSR Solution ID.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "ssr_sol_id")))]
        pub ssr_sol_id: u8,
        /// Chain and type of flag.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "chain_id")))]
        pub chain_id: u8,
        /// Constellation ID.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "const_id")))]
        pub const_id: u8,
        /// Number of faulty satellites.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "n_faulty_sats")))]
        pub n_faulty_sats: u8,
        /// List of faulty satellites.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "faulty_sats")))]
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
    #[cfg_attr(feature = "serde", derive(serde::Serialize))]
    #[derive(Debug, Clone)]
    pub struct MsgSsrFlagTropoGridPoints {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing))]
        pub sender_id: Option<u16>,
        /// GNSS reference time of the observation used to generate the flag.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "obs_time")))]
        pub obs_time: GpsTimeSec,
        /// Number of messages in the dataset
        #[cfg_attr(feature = "serde", serde(rename(serialize = "num_msgs")))]
        pub num_msgs: u8,
        /// Position of this message in the dataset
        #[cfg_attr(feature = "serde", serde(rename(serialize = "seq_num")))]
        pub seq_num: u8,
        /// SSR Solution ID.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "ssr_sol_id")))]
        pub ssr_sol_id: u8,
        /// Unique identifier of the set this tile belongs to.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "tile_set_id")))]
        pub tile_set_id: u16,
        /// Unique identifier of this tile in the tile set.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "tile_id")))]
        pub tile_id: u16,
        /// Chain and type of flag.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "chain_id")))]
        pub chain_id: u8,
        /// Number of faulty grid points.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "n_faulty_points")))]
        pub n_faulty_points: u8,
        /// List of faulty grid points.
        #[cfg_attr(feature = "serde", serde(rename(serialize = "faulty_points")))]
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
        const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <Vec<u16> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.obs_time)
                + WireFormat::len(&self.num_msgs)
                + WireFormat::len(&self.seq_num)
                + WireFormat::len(&self.ssr_sol_id)
                + WireFormat::len(&self.tile_set_id)
                + WireFormat::len(&self.tile_id)
                + WireFormat::len(&self.chain_id)
                + WireFormat::len(&self.n_faulty_points)
                + WireFormat::len(&self.faulty_points)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.obs_time, buf);
            WireFormat::write(&self.num_msgs, buf);
            WireFormat::write(&self.seq_num, buf);
            WireFormat::write(&self.ssr_sol_id, buf);
            WireFormat::write(&self.tile_set_id, buf);
            WireFormat::write(&self.tile_id, buf);
            WireFormat::write(&self.chain_id, buf);
            WireFormat::write(&self.n_faulty_points, buf);
            WireFormat::write(&self.faulty_points, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrFlagTropoGridPoints {
                sender_id: None,
                obs_time: WireFormat::parse_unchecked(buf),
                num_msgs: WireFormat::parse_unchecked(buf),
                seq_num: WireFormat::parse_unchecked(buf),
                ssr_sol_id: WireFormat::parse_unchecked(buf),
                tile_set_id: WireFormat::parse_unchecked(buf),
                tile_id: WireFormat::parse_unchecked(buf),
                chain_id: WireFormat::parse_unchecked(buf),
                n_faulty_points: WireFormat::parse_unchecked(buf),
                faulty_points: WireFormat::parse_unchecked(buf),
            }
        }
    }
}
