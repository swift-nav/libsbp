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
        #[cfg_attr(feature = "serde", serde(rename(serialize = "stub")))]
        pub stub: Vec<u8>,
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
        const MIN_LEN: usize = <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.stub)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.stub, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrFlagHighLevel {
                sender_id: None,
                stub: WireFormat::parse_unchecked(buf),
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
        #[cfg_attr(feature = "serde", serde(rename(serialize = "stub")))]
        pub stub: Vec<u8>,
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
        const MIN_LEN: usize = <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.stub)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.stub, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrFlagIonoGridPoints {
                sender_id: None,
                stub: WireFormat::parse_unchecked(buf),
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
        #[cfg_attr(feature = "serde", serde(rename(serialize = "stub")))]
        pub stub: Vec<u8>,
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
        const MIN_LEN: usize = <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.stub)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.stub, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrFlagIonoGridPointSatLos {
                sender_id: None,
                stub: WireFormat::parse_unchecked(buf),
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
        #[cfg_attr(feature = "serde", serde(rename(serialize = "stub")))]
        pub stub: Vec<u8>,
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
        const MIN_LEN: usize = <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.stub)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.stub, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrFlagIonoTileSatLos {
                sender_id: None,
                stub: WireFormat::parse_unchecked(buf),
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
        #[cfg_attr(feature = "serde", serde(rename(serialize = "stub")))]
        pub stub: Vec<u8>,
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
        const MIN_LEN: usize = <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.stub)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.stub, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrFlagSatellites {
                sender_id: None,
                stub: WireFormat::parse_unchecked(buf),
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
        #[cfg_attr(feature = "serde", serde(rename(serialize = "stub")))]
        pub stub: Vec<u8>,
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
        const MIN_LEN: usize = <Vec<u8> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.stub)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.stub, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgSsrFlagTropoGridPoints {
                sender_id: None,
                stub: WireFormat::parse_unchecked(buf),
            }
        }
    }
}
