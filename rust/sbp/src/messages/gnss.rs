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
// Automatically generated from yaml/swiftnav/sbp/gnss.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Various structs shared between modules
pub use carrier_phase::CarrierPhase;
pub use gnss_signal::GnssSignal;
pub use gnss_signal_dep::GnssSignalDep;
pub use gps_time::GpsTime;
pub use gps_time_dep::GpsTimeDep;
pub use gps_time_sec::GpsTimeSec;
pub use sv_id::SvId;

pub mod carrier_phase {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// GNSS carrier phase measurement
    ///
    /// Carrier phase measurement in cycles represented as a 40-bit fixed point
    /// number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
    /// fractional cycles. This phase has the same sign as the pseudorange.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct CarrierPhase {
        /// Carrier phase whole cycles
        #[cfg_attr(feature = "serde", serde(rename = "i"))]
        pub i: i32,
        /// Carrier phase fractional part
        #[cfg_attr(feature = "serde", serde(rename = "f"))]
        pub f: u8,
    }

    impl WireFormat for CarrierPhase {
        const MIN_LEN: usize = <i32 as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.i) + WireFormat::len(&self.f)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.i, buf);
            WireFormat::write(&self.f, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            CarrierPhase {
                i: WireFormat::parse_unchecked(buf),
                f: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod gps_time {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Nanosecond-accurate receiver clock time
    ///
    /// A wire-appropriate receiver clock time, defined as the time since the
    /// beginning of the week on the Saturday/Sunday transition. In most cases,
    /// observations are epoch aligned so ns field will be 0.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct GpsTime {
        /// Milliseconds since start of GPS week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
        /// 500000)
        #[cfg_attr(feature = "serde", serde(rename = "ns_residual"))]
        pub ns_residual: i32,
        /// GPS week number
        #[cfg_attr(feature = "serde", serde(rename = "wn"))]
        pub wn: u16,
    }

    impl WireFormat for GpsTime {
        const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
            + <i32 as WireFormat>::MIN_LEN
            + <u16 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.tow)
                + WireFormat::len(&self.ns_residual)
                + WireFormat::len(&self.wn)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.tow, buf);
            WireFormat::write(&self.ns_residual, buf);
            WireFormat::write(&self.wn, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            GpsTime {
                tow: WireFormat::parse_unchecked(buf),
                ns_residual: WireFormat::parse_unchecked(buf),
                wn: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod gps_time_dep {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Millisecond-accurate GPS time
    ///
    /// A wire-appropriate GPS time, defined as the number of milliseconds since
    /// beginning of the week on the Saturday/Sunday transition.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct GpsTimeDep {
        /// Milliseconds since start of GPS week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// GPS week number
        #[cfg_attr(feature = "serde", serde(rename = "wn"))]
        pub wn: u16,
    }

    impl WireFormat for GpsTimeDep {
        const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN + <u16 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.tow) + WireFormat::len(&self.wn)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.tow, buf);
            WireFormat::write(&self.wn, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            GpsTimeDep {
                tow: WireFormat::parse_unchecked(buf),
                wn: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod gps_time_sec {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Whole second accurate GPS time
    ///
    /// A GPS time, defined as the number of seconds since beginning of the week
    /// on the Saturday/Sunday transition.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct GpsTimeSec {
        /// Seconds since start of GPS week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// GPS week number
        #[cfg_attr(feature = "serde", serde(rename = "wn"))]
        pub wn: u16,
    }

    impl WireFormat for GpsTimeSec {
        const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN + <u16 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.tow) + WireFormat::len(&self.wn)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.tow, buf);
            WireFormat::write(&self.wn, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            GpsTimeSec {
                tow: WireFormat::parse_unchecked(buf),
                wn: WireFormat::parse_unchecked(buf),
            }
        }
    }
}

pub mod gnss_signal {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Represents all the relevant information about the signal
    ///
    /// Signal identifier containing constellation, band, and satellite
    /// identifier.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct GnssSignal {
        /// Constellation-specific satellite id. For GLO can either be (100+FCN)
        /// where FCN is in \[-7,+6\] or the Slot ID in \[1,28\].
        #[cfg_attr(feature = "serde", serde(rename = "sat"))]
        pub sat: u8,
        /// Signal constellation, band and code
        #[cfg_attr(feature = "serde", serde(rename = "code"))]
        pub code: u8,
    }

    impl GnssSignal {
        /// Gets the [Code][self::Code] stored in the `code` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `Code` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `Code` were added.
        pub fn code(&self) -> Result<Code, u8> {
            get_bit_range!(self.code, u8, u8, 7, 0).try_into()
        }

        /// Set the bitrange corresponding to the [Code][Code] of the `code` bitfield.
        pub fn set_code(&mut self, code: Code) {
            set_bit_range!(&mut self.code, code, u8, u8, 7, 0);
        }
    }

    impl WireFormat for GnssSignal {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.sat) + WireFormat::len(&self.code)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.sat, buf);
            WireFormat::write(&self.code, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            GnssSignal {
                sat: WireFormat::parse_unchecked(buf),
                code: WireFormat::parse_unchecked(buf),
            }
        }
    }

    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum Code {
        /// GPS L1CA
        GpsL1Ca = 0,

        /// GPS L2CM
        GpsL2Cm = 1,

        /// SBAS L1CA
        SbasL1Ca = 2,

        /// GLO L1CA
        GloL1Ca = 3,

        /// GLO L2CA
        GloL2Ca = 4,

        /// GPS L1P
        GpsL1P = 5,

        /// GPS L2P
        GpsL2P = 6,

        /// BDS2 B1
        Bds2B1 = 12,

        /// BDS2 B2
        Bds2B2 = 13,

        /// GAL E1B
        GalE1B = 14,

        /// GAL E7I
        GalE7I = 20,

        /// BDS3 B2a
        Bds3B2A = 47,
    }

    impl std::fmt::Display for Code {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                Code::GpsL1Ca => f.write_str("GPS L1CA"),
                Code::GpsL2Cm => f.write_str("GPS L2CM"),
                Code::SbasL1Ca => f.write_str("SBAS L1CA"),
                Code::GloL1Ca => f.write_str("GLO L1CA"),
                Code::GloL2Ca => f.write_str("GLO L2CA"),
                Code::GpsL1P => f.write_str("GPS L1P"),
                Code::GpsL2P => f.write_str("GPS L2P"),
                Code::Bds2B1 => f.write_str("BDS2 B1"),
                Code::Bds2B2 => f.write_str("BDS2 B2"),
                Code::GalE1B => f.write_str("GAL E1B"),
                Code::GalE7I => f.write_str("GAL E7I"),
                Code::Bds3B2A => f.write_str("BDS3 B2a"),
            }
        }
    }

    impl TryFrom<u8> for Code {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(Code::GpsL1Ca),
                1 => Ok(Code::GpsL2Cm),
                2 => Ok(Code::SbasL1Ca),
                3 => Ok(Code::GloL1Ca),
                4 => Ok(Code::GloL2Ca),
                5 => Ok(Code::GpsL1P),
                6 => Ok(Code::GpsL2P),
                12 => Ok(Code::Bds2B1),
                13 => Ok(Code::Bds2B2),
                14 => Ok(Code::GalE1B),
                20 => Ok(Code::GalE7I),
                47 => Ok(Code::Bds3B2A),
                i => Err(i),
            }
        }
    }
}

pub mod gnss_signal_dep {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Deprecated
    ///
    /// Deprecated.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct GnssSignalDep {
        /// Constellation-specific satellite identifier.
        ///
        /// Note: unlike GnssSignal, GPS satellites are encoded as (PRN - 1). Other
        /// constellations do not have this offset.
        #[cfg_attr(feature = "serde", serde(rename = "sat"))]
        pub sat: u16,
        /// Signal constellation, band and code
        #[cfg_attr(feature = "serde", serde(rename = "code"))]
        pub code: u8,
        /// Reserved
        #[cfg_attr(feature = "serde", serde(rename = "reserved"))]
        pub reserved: u8,
    }

    impl GnssSignalDep {
        /// Gets the [Code][self::Code] stored in the `code` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `Code` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `Code` were added.
        pub fn code(&self) -> Result<Code, u8> {
            get_bit_range!(self.code, u8, u8, 7, 0).try_into()
        }

        /// Set the bitrange corresponding to the [Code][Code] of the `code` bitfield.
        pub fn set_code(&mut self, code: Code) {
            set_bit_range!(&mut self.code, code, u8, u8, 7, 0);
        }
    }

    impl WireFormat for GnssSignalDep {
        const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.sat)
                + WireFormat::len(&self.code)
                + WireFormat::len(&self.reserved)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.sat, buf);
            WireFormat::write(&self.code, buf);
            WireFormat::write(&self.reserved, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            GnssSignalDep {
                sat: WireFormat::parse_unchecked(buf),
                code: WireFormat::parse_unchecked(buf),
                reserved: WireFormat::parse_unchecked(buf),
            }
        }
    }

    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum Code {
        /// GPS L1CA
        GpsL1Ca = 0,

        /// GPS L2CM
        GpsL2Cm = 1,

        /// SBAS L1CA
        SbasL1Ca = 2,

        /// GLO L1CA
        GloL1Ca = 3,

        /// GLO L2CA
        GloL2Ca = 4,

        /// GPS L1P
        GpsL1P = 5,

        /// GPS L2P
        GpsL2P = 6,
    }

    impl std::fmt::Display for Code {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                Code::GpsL1Ca => f.write_str("GPS L1CA"),
                Code::GpsL2Cm => f.write_str("GPS L2CM"),
                Code::SbasL1Ca => f.write_str("SBAS L1CA"),
                Code::GloL1Ca => f.write_str("GLO L1CA"),
                Code::GloL2Ca => f.write_str("GLO L2CA"),
                Code::GpsL1P => f.write_str("GPS L1P"),
                Code::GpsL2P => f.write_str("GPS L2P"),
            }
        }
    }

    impl TryFrom<u8> for Code {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(Code::GpsL1Ca),
                1 => Ok(Code::GpsL2Cm),
                2 => Ok(Code::SbasL1Ca),
                3 => Ok(Code::GloL1Ca),
                4 => Ok(Code::GloL2Ca),
                5 => Ok(Code::GpsL1P),
                6 => Ok(Code::GpsL2P),
                i => Err(i),
            }
        }
    }
}

pub mod sv_id {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::lib::*;

    /// Space vehicle identifier
    ///
    /// A (Constellation ID, satellite ID) tuple that uniquely identifies a space
    /// vehicle.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[derive(Debug, PartialEq, Clone)]
    pub struct SvId {
        /// Constellation-specific satellite id. For GLO can either be (100+FCN)
        /// where FCN is in \[-7,+6\] or the Slot ID in \[1,28\].
        #[cfg_attr(feature = "serde", serde(rename = "satId"))]
        pub sat_id: u8,
        /// Constellation ID to which the SV belongs
        #[cfg_attr(feature = "serde", serde(rename = "constellation"))]
        pub constellation: u8,
    }

    impl SvId {
        /// Gets the [Constellation][self::Constellation] stored in the `constellation` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `Constellation` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `Constellation` were added.
        pub fn constellation(&self) -> Result<Constellation, u8> {
            get_bit_range!(self.constellation, u8, u8, 7, 0).try_into()
        }

        /// Set the bitrange corresponding to the [Constellation][Constellation] of the `constellation` bitfield.
        pub fn set_constellation(&mut self, constellation: Constellation) {
            set_bit_range!(&mut self.constellation, constellation, u8, u8, 7, 0);
        }
    }

    impl WireFormat for SvId {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.sat_id) + WireFormat::len(&self.constellation)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.sat_id, buf);
            WireFormat::write(&self.constellation, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            SvId {
                sat_id: WireFormat::parse_unchecked(buf),
                constellation: WireFormat::parse_unchecked(buf),
            }
        }
    }

    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum Constellation {
        /// GPS
        Gps = 0,

        /// BDS
        Bds = 3,

        /// GAL
        Gal = 5,
    }

    impl std::fmt::Display for Constellation {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                Constellation::Gps => f.write_str("GPS"),
                Constellation::Bds => f.write_str("BDS"),
                Constellation::Gal => f.write_str("GAL"),
            }
        }
    }

    impl TryFrom<u8> for Constellation {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(Constellation::Gps),
                3 => Ok(Constellation::Bds),
                5 => Ok(Constellation::Gal),
                i => Err(i),
            }
        }
    }
}
