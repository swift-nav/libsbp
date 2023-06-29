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
// Automatically generated from yaml/swiftnav/sbp/telemetry.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Telemetry messages reported by Starling engine. The messages include
//! various byproducts of state estimation and other logic across Starling and
//! are aimed at efficient issue diagnostics.
pub use msg_tel_sv::MsgTelSv;
pub use telemetry_sv::TelemetrySV;

pub mod msg_tel_sv {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;

    /// Per-signal telemetry
    ///
    /// This message includes telemetry pertinent to satellite signals available
    /// to Starling.
    ///
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct MsgTelSv {
        /// The message sender_id
        #[cfg_attr(feature = "serde", serde(skip_serializing, alias = "sender"))]
        pub sender_id: Option<u16>,
        /// GPS week number
        #[cfg_attr(feature = "serde", serde(rename = "wn"))]
        pub wn: u16,
        /// GPS Time of Week
        #[cfg_attr(feature = "serde", serde(rename = "tow"))]
        pub tow: u32,
        /// Total number of observations. First nibble is the size of the sequence
        /// (n), second nibble is the zero-indexed counter (ith packet of n)
        #[cfg_attr(feature = "serde", serde(rename = "n_obs"))]
        pub n_obs: u8,
        /// Flags to identify the filter type from which the telemetry is reported
        /// from
        #[cfg_attr(feature = "serde", serde(rename = "origin_flags"))]
        pub origin_flags: u8,
        /// Array of per-signal telemetry entries
        #[cfg_attr(feature = "serde", serde(rename = "sv_tel"))]
        pub sv_tel: Vec<TelemetrySV>,
    }

    impl MsgTelSv {
        /// Gets the [FilterType][self::FilterType] stored in the `origin_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `FilterType` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `FilterType` were added.
        pub fn filter_type(&self) -> Result<FilterType, u8> {
            get_bit_range!(self.origin_flags, u8, u8, 7, 0).try_into()
        }

        /// Set the bitrange corresponding to the [FilterType][FilterType] of the `origin_flags` bitfield.
        pub fn set_filter_type(&mut self, filter_type: FilterType) {
            set_bit_range!(&mut self.origin_flags, filter_type, u8, u8, 7, 0);
        }
    }

    impl ConcreteMessage for MsgTelSv {
        const MESSAGE_TYPE: u16 = 288;
        const MESSAGE_NAME: &'static str = "MSG_TEL_SV";
    }

    impl SbpMessage for MsgTelSv {
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
        fn is_invalid(&self) -> bool {
            false
        }
        #[cfg(feature = "swiftnav")]
        fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
            let tow_s = (self.tow as f64) / 1000.0;
            #[allow(clippy::useless_conversion)]
            let wn: i16 = match self.wn.try_into() {
                Ok(wn) => wn,
                Err(e) => return Some(Err(e.into())),
            };
            let gps_time = match time::GpsTime::new(wn, tow_s) {
                Ok(gps_time) => gps_time,
                Err(e) => return Some(Err(e.into())),
            };
            Some(Ok(time::MessageTime::Rover(gps_time.into())))
        }
    }

    impl FriendlyName for MsgTelSv {
        fn friendly_name() -> &'static str {
            "TEL SV"
        }
    }

    impl TryFrom<Sbp> for MsgTelSv {
        type Error = TryFromSbpError;
        fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
            match msg {
                Sbp::MsgTelSv(m) => Ok(m),
                _ => Err(TryFromSbpError(msg)),
            }
        }
    }

    impl WireFormat for MsgTelSv {
        const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
            + <u32 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <Vec<TelemetrySV> as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.wn)
                + WireFormat::len(&self.tow)
                + WireFormat::len(&self.n_obs)
                + WireFormat::len(&self.origin_flags)
                + WireFormat::len(&self.sv_tel)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.wn, buf);
            WireFormat::write(&self.tow, buf);
            WireFormat::write(&self.n_obs, buf);
            WireFormat::write(&self.origin_flags, buf);
            WireFormat::write(&self.sv_tel, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            MsgTelSv {
                sender_id: None,
                wn: WireFormat::parse_unchecked(buf),
                tow: WireFormat::parse_unchecked(buf),
                n_obs: WireFormat::parse_unchecked(buf),
                origin_flags: WireFormat::parse_unchecked(buf),
                sv_tel: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Filter type
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum FilterType {
        /// Standalone
        Standalone = 0,

        /// Differential
        Differential = 1,
    }

    impl std::fmt::Display for FilterType {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                FilterType::Standalone => f.write_str("Standalone"),
                FilterType::Differential => f.write_str("Differential"),
            }
        }
    }

    impl TryFrom<u8> for FilterType {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(FilterType::Standalone),
                1 => Ok(FilterType::Differential),
                i => Err(i),
            }
        }
    }
}

pub mod telemetry_sv {
    #![allow(unused_imports)]

    use super::*;
    use crate::messages::gnss::*;
    use crate::messages::lib::*;
    /// Array of per-signal telemetry entries
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
    #[allow(clippy::derive_partial_eq_without_eq)]
    #[derive(Debug, PartialEq, Clone)]
    pub struct TelemetrySV {
        /// Azimuth angle (range 0..179)
        #[cfg_attr(feature = "serde", serde(rename = "az"))]
        pub az: u8,
        /// Elevation angle (range -90..90)
        #[cfg_attr(feature = "serde", serde(rename = "el"))]
        pub el: i8,
        /// Observation availability at filter update
        #[cfg_attr(feature = "serde", serde(rename = "availability_flags"))]
        pub availability_flags: u8,
        /// Pseudorange observation residual
        #[cfg_attr(feature = "serde", serde(rename = "pseudorange_residual"))]
        pub pseudorange_residual: i16,
        /// Carrier-phase or carrier-phase-derived observation residual
        #[cfg_attr(feature = "serde", serde(rename = "phase_residual"))]
        pub phase_residual: i16,
        /// Reports if observation is marked as an outlier and is excluded from the
        /// update
        #[cfg_attr(feature = "serde", serde(rename = "outlier_flags"))]
        pub outlier_flags: u8,
        /// Ephemeris metadata
        #[cfg_attr(feature = "serde", serde(rename = "ephemeris_flags"))]
        pub ephemeris_flags: u8,
        /// Reserved
        #[cfg_attr(feature = "serde", serde(rename = "correction_flags"))]
        pub correction_flags: u8,
        /// GNSS signal identifier (16 bit)
        #[cfg_attr(feature = "serde", serde(rename = "sid"))]
        pub sid: GnssSignal,
    }

    impl TelemetrySV {
        /// Gets the [MeasuredDopplerAvailability][self::MeasuredDopplerAvailability] stored in the `availability_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `MeasuredDopplerAvailability` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `MeasuredDopplerAvailability` were added.
        pub fn measured_doppler_availability(&self) -> Result<MeasuredDopplerAvailability, u8> {
            get_bit_range!(self.availability_flags, u8, u8, 3, 3).try_into()
        }

        /// Set the bitrange corresponding to the [MeasuredDopplerAvailability][MeasuredDopplerAvailability] of the `availability_flags` bitfield.
        pub fn set_measured_doppler_availability(
            &mut self,
            measured_doppler_availability: MeasuredDopplerAvailability,
        ) {
            set_bit_range!(
                &mut self.availability_flags,
                measured_doppler_availability,
                u8,
                u8,
                3,
                3
            );
        }

        /// Gets the [ComputedDopplerAvailability][self::ComputedDopplerAvailability] stored in the `availability_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `ComputedDopplerAvailability` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `ComputedDopplerAvailability` were added.
        pub fn computed_doppler_availability(&self) -> Result<ComputedDopplerAvailability, u8> {
            get_bit_range!(self.availability_flags, u8, u8, 2, 2).try_into()
        }

        /// Set the bitrange corresponding to the [ComputedDopplerAvailability][ComputedDopplerAvailability] of the `availability_flags` bitfield.
        pub fn set_computed_doppler_availability(
            &mut self,
            computed_doppler_availability: ComputedDopplerAvailability,
        ) {
            set_bit_range!(
                &mut self.availability_flags,
                computed_doppler_availability,
                u8,
                u8,
                2,
                2
            );
        }

        /// Gets the [CarrierPhaseAvailability][self::CarrierPhaseAvailability] stored in the `availability_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `CarrierPhaseAvailability` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `CarrierPhaseAvailability` were added.
        pub fn carrierphase_availability(&self) -> Result<CarrierPhaseAvailability, u8> {
            get_bit_range!(self.availability_flags, u8, u8, 1, 1).try_into()
        }

        /// Set the bitrange corresponding to the [CarrierPhaseAvailability][CarrierPhaseAvailability] of the `availability_flags` bitfield.
        pub fn set_carrierphase_availability(
            &mut self,
            carrierphase_availability: CarrierPhaseAvailability,
        ) {
            set_bit_range!(
                &mut self.availability_flags,
                carrierphase_availability,
                u8,
                u8,
                1,
                1
            );
        }

        /// Gets the [PseudorangeAvailability][self::PseudorangeAvailability] stored in the `availability_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `PseudorangeAvailability` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `PseudorangeAvailability` were added.
        pub fn pseudorange_availability(&self) -> Result<PseudorangeAvailability, u8> {
            get_bit_range!(self.availability_flags, u8, u8, 0, 0).try_into()
        }

        /// Set the bitrange corresponding to the [PseudorangeAvailability][PseudorangeAvailability] of the `availability_flags` bitfield.
        pub fn set_pseudorange_availability(
            &mut self,
            pseudorange_availability: PseudorangeAvailability,
        ) {
            set_bit_range!(
                &mut self.availability_flags,
                pseudorange_availability,
                u8,
                u8,
                0,
                0
            );
        }

        /// Gets the [MeasuredDopplerOutlier][self::MeasuredDopplerOutlier] stored in the `outlier_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `MeasuredDopplerOutlier` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `MeasuredDopplerOutlier` were added.
        pub fn measured_doppler_outlier(&self) -> Result<MeasuredDopplerOutlier, u8> {
            get_bit_range!(self.outlier_flags, u8, u8, 4, 4).try_into()
        }

        /// Set the bitrange corresponding to the [MeasuredDopplerOutlier][MeasuredDopplerOutlier] of the `outlier_flags` bitfield.
        pub fn set_measured_doppler_outlier(
            &mut self,
            measured_doppler_outlier: MeasuredDopplerOutlier,
        ) {
            set_bit_range!(
                &mut self.outlier_flags,
                measured_doppler_outlier,
                u8,
                u8,
                4,
                4
            );
        }

        /// Gets the [ComputedDopplerOutlier][self::ComputedDopplerOutlier] stored in the `outlier_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `ComputedDopplerOutlier` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `ComputedDopplerOutlier` were added.
        pub fn computed_doppler_outlier(&self) -> Result<ComputedDopplerOutlier, u8> {
            get_bit_range!(self.outlier_flags, u8, u8, 3, 3).try_into()
        }

        /// Set the bitrange corresponding to the [ComputedDopplerOutlier][ComputedDopplerOutlier] of the `outlier_flags` bitfield.
        pub fn set_computed_doppler_outlier(
            &mut self,
            computed_doppler_outlier: ComputedDopplerOutlier,
        ) {
            set_bit_range!(
                &mut self.outlier_flags,
                computed_doppler_outlier,
                u8,
                u8,
                3,
                3
            );
        }

        /// Gets the [CarrierPhaseOutlier][self::CarrierPhaseOutlier] stored in the `outlier_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `CarrierPhaseOutlier` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `CarrierPhaseOutlier` were added.
        pub fn carrierphase_outlier(&self) -> Result<CarrierPhaseOutlier, u8> {
            get_bit_range!(self.outlier_flags, u8, u8, 2, 2).try_into()
        }

        /// Set the bitrange corresponding to the [CarrierPhaseOutlier][CarrierPhaseOutlier] of the `outlier_flags` bitfield.
        pub fn set_carrierphase_outlier(&mut self, carrierphase_outlier: CarrierPhaseOutlier) {
            set_bit_range!(&mut self.outlier_flags, carrierphase_outlier, u8, u8, 2, 2);
        }

        /// Gets the [PseudorangeOutlier][self::PseudorangeOutlier] stored in the `outlier_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `PseudorangeOutlier` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `PseudorangeOutlier` were added.
        pub fn pseudorange_outlier(&self) -> Result<PseudorangeOutlier, u8> {
            get_bit_range!(self.outlier_flags, u8, u8, 1, 0).try_into()
        }

        /// Set the bitrange corresponding to the [PseudorangeOutlier][PseudorangeOutlier] of the `outlier_flags` bitfield.
        pub fn set_pseudorange_outlier(&mut self, pseudorange_outlier: PseudorangeOutlier) {
            set_bit_range!(&mut self.outlier_flags, pseudorange_outlier, u8, u8, 1, 0);
        }

        /// Gets the [EphemerisAvailable][self::EphemerisAvailable] stored in the `ephemeris_flags` bitfield.
        ///
        /// Returns `Ok` if the bitrange contains a known `EphemerisAvailable` variant.
        /// Otherwise the value of the bitrange is returned as an `Err(u8)`. This may be because of a malformed message,
        /// or because new variants of `EphemerisAvailable` were added.
        pub fn ephemeris_available(&self) -> Result<EphemerisAvailable, u8> {
            get_bit_range!(self.ephemeris_flags, u8, u8, 0, 0).try_into()
        }

        /// Set the bitrange corresponding to the [EphemerisAvailable][EphemerisAvailable] of the `ephemeris_flags` bitfield.
        pub fn set_ephemeris_available(&mut self, ephemeris_available: EphemerisAvailable) {
            set_bit_range!(&mut self.ephemeris_flags, ephemeris_available, u8, u8, 0, 0);
        }
    }

    impl WireFormat for TelemetrySV {
        const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
            + <i8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <i16 as WireFormat>::MIN_LEN
            + <i16 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <u8 as WireFormat>::MIN_LEN
            + <GnssSignal as WireFormat>::MIN_LEN;
        fn len(&self) -> usize {
            WireFormat::len(&self.az)
                + WireFormat::len(&self.el)
                + WireFormat::len(&self.availability_flags)
                + WireFormat::len(&self.pseudorange_residual)
                + WireFormat::len(&self.phase_residual)
                + WireFormat::len(&self.outlier_flags)
                + WireFormat::len(&self.ephemeris_flags)
                + WireFormat::len(&self.correction_flags)
                + WireFormat::len(&self.sid)
        }
        fn write<B: BufMut>(&self, buf: &mut B) {
            WireFormat::write(&self.az, buf);
            WireFormat::write(&self.el, buf);
            WireFormat::write(&self.availability_flags, buf);
            WireFormat::write(&self.pseudorange_residual, buf);
            WireFormat::write(&self.phase_residual, buf);
            WireFormat::write(&self.outlier_flags, buf);
            WireFormat::write(&self.ephemeris_flags, buf);
            WireFormat::write(&self.correction_flags, buf);
            WireFormat::write(&self.sid, buf);
        }
        fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
            TelemetrySV {
                az: WireFormat::parse_unchecked(buf),
                el: WireFormat::parse_unchecked(buf),
                availability_flags: WireFormat::parse_unchecked(buf),
                pseudorange_residual: WireFormat::parse_unchecked(buf),
                phase_residual: WireFormat::parse_unchecked(buf),
                outlier_flags: WireFormat::parse_unchecked(buf),
                ephemeris_flags: WireFormat::parse_unchecked(buf),
                correction_flags: WireFormat::parse_unchecked(buf),
                sid: WireFormat::parse_unchecked(buf),
            }
        }
    }

    /// Measured-Doppler availability
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum MeasuredDopplerAvailability {
        /// Measured-Doppler unavailable
        MeasuredDopplerUnavailable = 0,

        /// Measured-Doppler available
        MeasuredDopplerAvailable = 1,
    }

    impl std::fmt::Display for MeasuredDopplerAvailability {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                MeasuredDopplerAvailability::MeasuredDopplerUnavailable => {
                    f.write_str("Measured-Doppler unavailable")
                }
                MeasuredDopplerAvailability::MeasuredDopplerAvailable => {
                    f.write_str("Measured-Doppler available")
                }
            }
        }
    }

    impl TryFrom<u8> for MeasuredDopplerAvailability {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(MeasuredDopplerAvailability::MeasuredDopplerUnavailable),
                1 => Ok(MeasuredDopplerAvailability::MeasuredDopplerAvailable),
                i => Err(i),
            }
        }
    }

    /// Computed-Doppler availability
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum ComputedDopplerAvailability {
        /// Computed-Doppler unavailable
        ComputedDopplerUnavailable = 0,

        /// Computed-Doppler available
        ComputedDopplerAvailable = 1,
    }

    impl std::fmt::Display for ComputedDopplerAvailability {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                ComputedDopplerAvailability::ComputedDopplerUnavailable => {
                    f.write_str("Computed-Doppler unavailable")
                }
                ComputedDopplerAvailability::ComputedDopplerAvailable => {
                    f.write_str("Computed-Doppler available")
                }
            }
        }
    }

    impl TryFrom<u8> for ComputedDopplerAvailability {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(ComputedDopplerAvailability::ComputedDopplerUnavailable),
                1 => Ok(ComputedDopplerAvailability::ComputedDopplerAvailable),
                i => Err(i),
            }
        }
    }

    /// Carrier-phase availability
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum CarrierPhaseAvailability {
        /// Carrier-phase unavailable
        CarrierPhaseUnavailable = 0,

        /// Carrier-phase available
        CarrierPhaseAvailable = 1,
    }

    impl std::fmt::Display for CarrierPhaseAvailability {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                CarrierPhaseAvailability::CarrierPhaseUnavailable => {
                    f.write_str("Carrier-phase unavailable")
                }
                CarrierPhaseAvailability::CarrierPhaseAvailable => {
                    f.write_str("Carrier-phase available")
                }
            }
        }
    }

    impl TryFrom<u8> for CarrierPhaseAvailability {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(CarrierPhaseAvailability::CarrierPhaseUnavailable),
                1 => Ok(CarrierPhaseAvailability::CarrierPhaseAvailable),
                i => Err(i),
            }
        }
    }

    /// Pseudorange availability
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum PseudorangeAvailability {
        /// Pseudorange unavailable
        PseudorangeUnavailable = 0,

        /// Pseudorange available
        PseudorangeAvailable = 1,
    }

    impl std::fmt::Display for PseudorangeAvailability {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                PseudorangeAvailability::PseudorangeUnavailable => {
                    f.write_str("Pseudorange unavailable")
                }
                PseudorangeAvailability::PseudorangeAvailable => {
                    f.write_str("Pseudorange available")
                }
            }
        }
    }

    impl TryFrom<u8> for PseudorangeAvailability {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(PseudorangeAvailability::PseudorangeUnavailable),
                1 => Ok(PseudorangeAvailability::PseudorangeAvailable),
                i => Err(i),
            }
        }
    }

    /// Measured-Doppler outlier
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum MeasuredDopplerOutlier {
        /// Measured-Doppler accepted
        MeasuredDopplerAccepted = 0,

        /// Measured-Doppler marked as outlier
        MeasuredDopplerMarkedAsOutlier = 1,
    }

    impl std::fmt::Display for MeasuredDopplerOutlier {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                MeasuredDopplerOutlier::MeasuredDopplerAccepted => {
                    f.write_str("Measured-Doppler accepted")
                }
                MeasuredDopplerOutlier::MeasuredDopplerMarkedAsOutlier => {
                    f.write_str("Measured-Doppler marked as outlier")
                }
            }
        }
    }

    impl TryFrom<u8> for MeasuredDopplerOutlier {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(MeasuredDopplerOutlier::MeasuredDopplerAccepted),
                1 => Ok(MeasuredDopplerOutlier::MeasuredDopplerMarkedAsOutlier),
                i => Err(i),
            }
        }
    }

    /// Computed-Doppler outlier
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum ComputedDopplerOutlier {
        /// Computed-Doppler accepted
        ComputedDopplerAccepted = 0,

        /// Computed-Doppler marked as outlier
        ComputedDopplerMarkedAsOutlier = 1,
    }

    impl std::fmt::Display for ComputedDopplerOutlier {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                ComputedDopplerOutlier::ComputedDopplerAccepted => {
                    f.write_str("Computed-Doppler accepted")
                }
                ComputedDopplerOutlier::ComputedDopplerMarkedAsOutlier => {
                    f.write_str("Computed-Doppler marked as outlier")
                }
            }
        }
    }

    impl TryFrom<u8> for ComputedDopplerOutlier {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(ComputedDopplerOutlier::ComputedDopplerAccepted),
                1 => Ok(ComputedDopplerOutlier::ComputedDopplerMarkedAsOutlier),
                i => Err(i),
            }
        }
    }

    /// Carrier-phase outlier
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum CarrierPhaseOutlier {
        /// Carrier-phase accepted
        CarrierPhaseAccepted = 0,

        /// Carrier-phase marked as outlier
        CarrierPhaseMarkedAsOutlier = 1,
    }

    impl std::fmt::Display for CarrierPhaseOutlier {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                CarrierPhaseOutlier::CarrierPhaseAccepted => f.write_str("Carrier-phase accepted"),
                CarrierPhaseOutlier::CarrierPhaseMarkedAsOutlier => {
                    f.write_str("Carrier-phase marked as outlier")
                }
            }
        }
    }

    impl TryFrom<u8> for CarrierPhaseOutlier {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(CarrierPhaseOutlier::CarrierPhaseAccepted),
                1 => Ok(CarrierPhaseOutlier::CarrierPhaseMarkedAsOutlier),
                i => Err(i),
            }
        }
    }

    /// Pseudorange outlier
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum PseudorangeOutlier {
        /// Pseudorange accepted
        PseudorangeAccepted = 0,

        /// Pseudorange marked as outlier
        PseudorangeMarkedAsOutlier = 1,

        /// Pseudorange marked as major outlier
        PseudorangeMarkedAsMajorOutlier = 2,
    }

    impl std::fmt::Display for PseudorangeOutlier {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                PseudorangeOutlier::PseudorangeAccepted => f.write_str("Pseudorange accepted"),
                PseudorangeOutlier::PseudorangeMarkedAsOutlier => {
                    f.write_str("Pseudorange marked as outlier")
                }
                PseudorangeOutlier::PseudorangeMarkedAsMajorOutlier => {
                    f.write_str("Pseudorange marked as major outlier")
                }
            }
        }
    }

    impl TryFrom<u8> for PseudorangeOutlier {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(PseudorangeOutlier::PseudorangeAccepted),
                1 => Ok(PseudorangeOutlier::PseudorangeMarkedAsOutlier),
                2 => Ok(PseudorangeOutlier::PseudorangeMarkedAsMajorOutlier),
                i => Err(i),
            }
        }
    }

    /// Ephemeris available
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub enum EphemerisAvailable {
        /// Valid ephemeris available
        ValidEphemerisAvailable = 0,

        /// No valid ephemeris available (general status)
        NoValidEphemerisAvailable = 1,
    }

    impl std::fmt::Display for EphemerisAvailable {
        fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
            match self {
                EphemerisAvailable::ValidEphemerisAvailable => {
                    f.write_str("Valid ephemeris available")
                }
                EphemerisAvailable::NoValidEphemerisAvailable => {
                    f.write_str("No valid ephemeris available (general status)")
                }
            }
        }
    }

    impl TryFrom<u8> for EphemerisAvailable {
        type Error = u8;
        fn try_from(i: u8) -> Result<Self, u8> {
            match i {
                0 => Ok(EphemerisAvailable::ValidEphemerisAvailable),
                1 => Ok(EphemerisAvailable::NoValidEphemerisAvailable),
                i => Err(i),
            }
        }
    }
}
