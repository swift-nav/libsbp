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
// Automatically generated from yaml/swiftnav/sbp/observation.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Satellite observation messages from the device. The SBP sender ID of 0
//! indicates remote observations from a GNSS base station, correction
//! network, or Skylark, Swift's cloud GNSS correction product.

use super::gnss::*;

use super::lib::*;

/// Common fields for every almanac message
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct AlmanacCommonContent {
    /// GNSS signal identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// Reference time of almanac
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toa")))]
    pub toa: GpsTimeSec,
    /// User Range Accuracy
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ura")))]
    pub ura: f64,
    /// Curve fit interval
    #[cfg_attr(feature = "serde", serde(rename(serialize = "fit_interval")))]
    pub fit_interval: u32,
    /// Status of almanac, 1 = valid, 0 = invalid
    #[cfg_attr(feature = "serde", serde(rename(serialize = "valid")))]
    pub valid: u8,
    /// Satellite health status for GPS:
    ///   - bits 5-7: NAV data health status. See IS-GPS-200H
    ///     Table 20-VII: NAV Data Health Indications.
    ///   - bits 0-4: Signal health status. See IS-GPS-200H
    ///     Table 20-VIII. Codes for Health of SV Signal
    ///     Components.
    /// Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for details):
    ///   - bit 0: C(n), "unhealthy" flag that is transmitted within
    ///     non-immediate data and indicates overall constellation status
    ///     at the moment of almanac uploading.
    ///     '0' indicates malfunction of n-satellite.
    ///     '1' indicates that n-satellite is operational.
    ///   - bit 1: Bn(ln), '0' indicates the satellite is operational
    ///     and suitable for navigation.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "health_bits")))]
    pub health_bits: u8,
}

impl WireFormat for AlmanacCommonContent {
    const MIN_LEN: usize = <GnssSignal as WireFormat>::MIN_LEN
        + <GpsTimeSec as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sid)
            + WireFormat::len(&self.toa)
            + WireFormat::len(&self.ura)
            + WireFormat::len(&self.fit_interval)
            + WireFormat::len(&self.valid)
            + WireFormat::len(&self.health_bits)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.toa, buf);
        WireFormat::write(&self.ura, buf);
        WireFormat::write(&self.fit_interval, buf);
        WireFormat::write(&self.valid, buf);
        WireFormat::write(&self.health_bits, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        AlmanacCommonContent {
            sid: WireFormat::parse_unchecked(buf),
            toa: WireFormat::parse_unchecked(buf),
            ura: WireFormat::parse_unchecked(buf),
            fit_interval: WireFormat::parse_unchecked(buf),
            valid: WireFormat::parse_unchecked(buf),
            health_bits: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Common fields for every almanac message
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct AlmanacCommonContentDep {
    /// GNSS signal identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignalDep,
    /// Reference time of almanac
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toa")))]
    pub toa: GpsTimeSec,
    /// User Range Accuracy
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ura")))]
    pub ura: f64,
    /// Curve fit interval
    #[cfg_attr(feature = "serde", serde(rename(serialize = "fit_interval")))]
    pub fit_interval: u32,
    /// Status of almanac, 1 = valid, 0 = invalid
    #[cfg_attr(feature = "serde", serde(rename(serialize = "valid")))]
    pub valid: u8,
    /// Satellite health status for GPS:
    ///   - bits 5-7: NAV data health status. See IS-GPS-200H
    ///     Table 20-VII: NAV Data Health Indications.
    ///   - bits 0-4: Signal health status. See IS-GPS-200H
    ///     Table 20-VIII. Codes for Health of SV Signal
    ///     Components.
    /// Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for details):
    ///   - bit 0: C(n), "unhealthy" flag that is transmitted within
    ///     non-immediate data and indicates overall constellation status
    ///     at the moment of almanac uploading.
    ///     '0' indicates malfunction of n-satellite.
    ///     '1' indicates that n-satellite is operational.
    ///   - bit 1: Bn(ln), '0' indicates the satellite is operational
    ///     and suitable for navigation.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "health_bits")))]
    pub health_bits: u8,
}

impl WireFormat for AlmanacCommonContentDep {
    const MIN_LEN: usize = <GnssSignalDep as WireFormat>::MIN_LEN
        + <GpsTimeSec as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sid)
            + WireFormat::len(&self.toa)
            + WireFormat::len(&self.ura)
            + WireFormat::len(&self.fit_interval)
            + WireFormat::len(&self.valid)
            + WireFormat::len(&self.health_bits)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.toa, buf);
        WireFormat::write(&self.ura, buf);
        WireFormat::write(&self.fit_interval, buf);
        WireFormat::write(&self.valid, buf);
        WireFormat::write(&self.health_bits, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        AlmanacCommonContentDep {
            sid: WireFormat::parse_unchecked(buf),
            toa: WireFormat::parse_unchecked(buf),
            ura: WireFormat::parse_unchecked(buf),
            fit_interval: WireFormat::parse_unchecked(buf),
            valid: WireFormat::parse_unchecked(buf),
            health_bits: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GPS carrier phase measurement
///
/// Carrier phase measurement in cycles represented as a 40-bit fixed point
/// number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
/// fractional cycles. This has the opposite sign convention than a typical
/// GPS receiver and the phase has the opposite sign as the pseudorange.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct CarrierPhaseDepA {
    /// Carrier phase whole cycles
    #[cfg_attr(feature = "serde", serde(rename(serialize = "i")))]
    pub i: i32,
    /// Carrier phase fractional part
    #[cfg_attr(feature = "serde", serde(rename(serialize = "f")))]
    pub f: u8,
}

impl WireFormat for CarrierPhaseDepA {
    const MIN_LEN: usize = <i32 as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.i) + WireFormat::len(&self.f)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.i, buf);
        WireFormat::write(&self.f, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        CarrierPhaseDepA {
            i: WireFormat::parse_unchecked(buf),
            f: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GNSS doppler measurement
///
/// Doppler measurement in Hz represented as a 24-bit fixed point number with
/// Q16.8 layout, i.e. 16-bits of whole doppler and 8-bits of fractional
/// doppler. This doppler is defined as positive for approaching satellites.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct Doppler {
    /// Doppler whole Hz
    #[cfg_attr(feature = "serde", serde(rename(serialize = "i")))]
    pub i: i16,
    /// Doppler fractional part
    #[cfg_attr(feature = "serde", serde(rename(serialize = "f")))]
    pub f: u8,
}

impl WireFormat for Doppler {
    const MIN_LEN: usize = <i16 as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.i) + WireFormat::len(&self.f)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.i, buf);
        WireFormat::write(&self.f, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        Doppler {
            i: WireFormat::parse_unchecked(buf),
            f: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Common fields for every ephemeris message
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct EphemerisCommonContent {
    /// GNSS signal identifier (16 bit)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// Time of Ephemerides
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toe")))]
    pub toe: GpsTimeSec,
    /// User Range Accuracy
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ura")))]
    pub ura: f32,
    /// Curve fit interval
    #[cfg_attr(feature = "serde", serde(rename(serialize = "fit_interval")))]
    pub fit_interval: u32,
    /// Status of ephemeris, 1 = valid, 0 = invalid
    #[cfg_attr(feature = "serde", serde(rename(serialize = "valid")))]
    pub valid: u8,
    /// Satellite health status.
    /// GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
    /// SBAS: 0 = valid, non-zero = invalid
    /// GLO: 0 = valid, non-zero = invalid
    #[cfg_attr(feature = "serde", serde(rename(serialize = "health_bits")))]
    pub health_bits: u8,
}

impl WireFormat for EphemerisCommonContent {
    const MIN_LEN: usize = <GnssSignal as WireFormat>::MIN_LEN
        + <GpsTimeSec as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sid)
            + WireFormat::len(&self.toe)
            + WireFormat::len(&self.ura)
            + WireFormat::len(&self.fit_interval)
            + WireFormat::len(&self.valid)
            + WireFormat::len(&self.health_bits)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.toe, buf);
        WireFormat::write(&self.ura, buf);
        WireFormat::write(&self.fit_interval, buf);
        WireFormat::write(&self.valid, buf);
        WireFormat::write(&self.health_bits, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        EphemerisCommonContent {
            sid: WireFormat::parse_unchecked(buf),
            toe: WireFormat::parse_unchecked(buf),
            ura: WireFormat::parse_unchecked(buf),
            fit_interval: WireFormat::parse_unchecked(buf),
            valid: WireFormat::parse_unchecked(buf),
            health_bits: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Common fields for every ephemeris message
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct EphemerisCommonContentDepA {
    /// GNSS signal identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignalDep,
    /// Time of Ephemerides
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toe")))]
    pub toe: GpsTimeDep,
    /// User Range Accuracy
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ura")))]
    pub ura: f64,
    /// Curve fit interval
    #[cfg_attr(feature = "serde", serde(rename(serialize = "fit_interval")))]
    pub fit_interval: u32,
    /// Status of ephemeris, 1 = valid, 0 = invalid
    #[cfg_attr(feature = "serde", serde(rename(serialize = "valid")))]
    pub valid: u8,
    /// Satellite health status.
    /// GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
    /// SBAS: 0 = valid, non-zero = invalid
    /// GLO: 0 = valid, non-zero = invalid
    #[cfg_attr(feature = "serde", serde(rename(serialize = "health_bits")))]
    pub health_bits: u8,
}

impl WireFormat for EphemerisCommonContentDepA {
    const MIN_LEN: usize = <GnssSignalDep as WireFormat>::MIN_LEN
        + <GpsTimeDep as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sid)
            + WireFormat::len(&self.toe)
            + WireFormat::len(&self.ura)
            + WireFormat::len(&self.fit_interval)
            + WireFormat::len(&self.valid)
            + WireFormat::len(&self.health_bits)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.toe, buf);
        WireFormat::write(&self.ura, buf);
        WireFormat::write(&self.fit_interval, buf);
        WireFormat::write(&self.valid, buf);
        WireFormat::write(&self.health_bits, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        EphemerisCommonContentDepA {
            sid: WireFormat::parse_unchecked(buf),
            toe: WireFormat::parse_unchecked(buf),
            ura: WireFormat::parse_unchecked(buf),
            fit_interval: WireFormat::parse_unchecked(buf),
            valid: WireFormat::parse_unchecked(buf),
            health_bits: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Common fields for every ephemeris message
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct EphemerisCommonContentDepB {
    /// GNSS signal identifier (16 bit)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// Time of Ephemerides
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toe")))]
    pub toe: GpsTimeSec,
    /// User Range Accuracy
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ura")))]
    pub ura: f64,
    /// Curve fit interval
    #[cfg_attr(feature = "serde", serde(rename(serialize = "fit_interval")))]
    pub fit_interval: u32,
    /// Status of ephemeris, 1 = valid, 0 = invalid
    #[cfg_attr(feature = "serde", serde(rename(serialize = "valid")))]
    pub valid: u8,
    /// Satellite health status.
    /// GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
    /// Others: 0 = valid, non-zero = invalid
    #[cfg_attr(feature = "serde", serde(rename(serialize = "health_bits")))]
    pub health_bits: u8,
}

impl WireFormat for EphemerisCommonContentDepB {
    const MIN_LEN: usize = <GnssSignal as WireFormat>::MIN_LEN
        + <GpsTimeSec as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sid)
            + WireFormat::len(&self.toe)
            + WireFormat::len(&self.ura)
            + WireFormat::len(&self.fit_interval)
            + WireFormat::len(&self.valid)
            + WireFormat::len(&self.health_bits)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.toe, buf);
        WireFormat::write(&self.ura, buf);
        WireFormat::write(&self.fit_interval, buf);
        WireFormat::write(&self.valid, buf);
        WireFormat::write(&self.health_bits, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        EphemerisCommonContentDepB {
            sid: WireFormat::parse_unchecked(buf),
            toe: WireFormat::parse_unchecked(buf),
            ura: WireFormat::parse_unchecked(buf),
            fit_interval: WireFormat::parse_unchecked(buf),
            valid: WireFormat::parse_unchecked(buf),
            health_bits: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GNSS capabilities masks
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct GnssCapb {
    /// GPS SV active mask
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gps_active")))]
    pub gps_active: u64,
    /// GPS L2C active mask
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gps_l2c")))]
    pub gps_l2c: u64,
    /// GPS L5 active mask
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gps_l5")))]
    pub gps_l5: u64,
    /// GLO active mask
    #[cfg_attr(feature = "serde", serde(rename(serialize = "glo_active")))]
    pub glo_active: u32,
    /// GLO L2OF active mask
    #[cfg_attr(feature = "serde", serde(rename(serialize = "glo_l2of")))]
    pub glo_l2of: u32,
    /// GLO L3 active mask
    #[cfg_attr(feature = "serde", serde(rename(serialize = "glo_l3")))]
    pub glo_l3: u32,
    /// SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
    /// <https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf>)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sbas_active")))]
    pub sbas_active: u64,
    /// SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
    /// <https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf>)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sbas_l5")))]
    pub sbas_l5: u64,
    /// BDS active mask
    #[cfg_attr(feature = "serde", serde(rename(serialize = "bds_active")))]
    pub bds_active: u64,
    /// BDS D2NAV active mask
    #[cfg_attr(feature = "serde", serde(rename(serialize = "bds_d2nav")))]
    pub bds_d2nav: u64,
    /// BDS B2 active mask
    #[cfg_attr(feature = "serde", serde(rename(serialize = "bds_b2")))]
    pub bds_b2: u64,
    /// BDS B2A active mask
    #[cfg_attr(feature = "serde", serde(rename(serialize = "bds_b2a")))]
    pub bds_b2a: u64,
    /// QZSS active mask
    #[cfg_attr(feature = "serde", serde(rename(serialize = "qzss_active")))]
    pub qzss_active: u32,
    /// GAL active mask
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gal_active")))]
    pub gal_active: u64,
    /// GAL E5 active mask
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gal_e5")))]
    pub gal_e5: u64,
}

impl WireFormat for GnssCapb {
    const MIN_LEN: usize = <u64 as WireFormat>::MIN_LEN
        + <u64 as WireFormat>::MIN_LEN
        + <u64 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u64 as WireFormat>::MIN_LEN
        + <u64 as WireFormat>::MIN_LEN
        + <u64 as WireFormat>::MIN_LEN
        + <u64 as WireFormat>::MIN_LEN
        + <u64 as WireFormat>::MIN_LEN
        + <u64 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u64 as WireFormat>::MIN_LEN
        + <u64 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.gps_active)
            + WireFormat::len(&self.gps_l2c)
            + WireFormat::len(&self.gps_l5)
            + WireFormat::len(&self.glo_active)
            + WireFormat::len(&self.glo_l2of)
            + WireFormat::len(&self.glo_l3)
            + WireFormat::len(&self.sbas_active)
            + WireFormat::len(&self.sbas_l5)
            + WireFormat::len(&self.bds_active)
            + WireFormat::len(&self.bds_d2nav)
            + WireFormat::len(&self.bds_b2)
            + WireFormat::len(&self.bds_b2a)
            + WireFormat::len(&self.qzss_active)
            + WireFormat::len(&self.gal_active)
            + WireFormat::len(&self.gal_e5)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.gps_active, buf);
        WireFormat::write(&self.gps_l2c, buf);
        WireFormat::write(&self.gps_l5, buf);
        WireFormat::write(&self.glo_active, buf);
        WireFormat::write(&self.glo_l2of, buf);
        WireFormat::write(&self.glo_l3, buf);
        WireFormat::write(&self.sbas_active, buf);
        WireFormat::write(&self.sbas_l5, buf);
        WireFormat::write(&self.bds_active, buf);
        WireFormat::write(&self.bds_d2nav, buf);
        WireFormat::write(&self.bds_b2, buf);
        WireFormat::write(&self.bds_b2a, buf);
        WireFormat::write(&self.qzss_active, buf);
        WireFormat::write(&self.gal_active, buf);
        WireFormat::write(&self.gal_e5, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        GnssCapb {
            gps_active: WireFormat::parse_unchecked(buf),
            gps_l2c: WireFormat::parse_unchecked(buf),
            gps_l5: WireFormat::parse_unchecked(buf),
            glo_active: WireFormat::parse_unchecked(buf),
            glo_l2of: WireFormat::parse_unchecked(buf),
            glo_l3: WireFormat::parse_unchecked(buf),
            sbas_active: WireFormat::parse_unchecked(buf),
            sbas_l5: WireFormat::parse_unchecked(buf),
            bds_active: WireFormat::parse_unchecked(buf),
            bds_d2nav: WireFormat::parse_unchecked(buf),
            bds_b2: WireFormat::parse_unchecked(buf),
            bds_b2a: WireFormat::parse_unchecked(buf),
            qzss_active: WireFormat::parse_unchecked(buf),
            gal_active: WireFormat::parse_unchecked(buf),
            gal_e5: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris for GLO
///
/// The almanac message returns a set of satellite orbit parameters. Almanac
/// data is not very precise and is considered valid for up to several months.
/// Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
/// almanac" for details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgAlmanacGlo {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all almanac types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: AlmanacCommonContent,
    /// Longitude of the first ascending node of the orbit in PZ-90.02
    /// coordinate system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lambda_na")))]
    pub lambda_na: f64,
    /// Time of the first ascending node passage
    #[cfg_attr(feature = "serde", serde(rename(serialize = "t_lambda_na")))]
    pub t_lambda_na: f64,
    /// Value of inclination at instant of t_lambda
    #[cfg_attr(feature = "serde", serde(rename(serialize = "i")))]
    pub i: f64,
    /// Value of Draconian period at instant of t_lambda
    #[cfg_attr(feature = "serde", serde(rename(serialize = "t")))]
    pub t: f64,
    /// Rate of change of the Draconian period
    #[cfg_attr(feature = "serde", serde(rename(serialize = "t_dot")))]
    pub t_dot: f64,
    /// Eccentricity at instant of t_lambda
    #[cfg_attr(feature = "serde", serde(rename(serialize = "epsilon")))]
    pub epsilon: f64,
    /// Argument of perigee at instant of t_lambda
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omega")))]
    pub omega: f64,
}

impl ConcreteMessage for MsgAlmanacGlo {
    const MESSAGE_TYPE: u16 = 115;
    const MESSAGE_NAME: &'static str = "MSG_ALMANAC_GLO";
}

impl SbpMessage for MsgAlmanacGlo {
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

impl TryFrom<Sbp> for MsgAlmanacGlo {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgAlmanacGlo(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgAlmanacGlo {
    const MIN_LEN: usize = <AlmanacCommonContent as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.lambda_na)
            + WireFormat::len(&self.t_lambda_na)
            + WireFormat::len(&self.i)
            + WireFormat::len(&self.t)
            + WireFormat::len(&self.t_dot)
            + WireFormat::len(&self.epsilon)
            + WireFormat::len(&self.omega)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.lambda_na, buf);
        WireFormat::write(&self.t_lambda_na, buf);
        WireFormat::write(&self.i, buf);
        WireFormat::write(&self.t, buf);
        WireFormat::write(&self.t_dot, buf);
        WireFormat::write(&self.epsilon, buf);
        WireFormat::write(&self.omega, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgAlmanacGlo {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            lambda_na: WireFormat::parse_unchecked(buf),
            t_lambda_na: WireFormat::parse_unchecked(buf),
            i: WireFormat::parse_unchecked(buf),
            t: WireFormat::parse_unchecked(buf),
            t_dot: WireFormat::parse_unchecked(buf),
            epsilon: WireFormat::parse_unchecked(buf),
            omega: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris for GLO
///
/// The almanac message returns a set of satellite orbit parameters. Almanac
/// data is not very precise and is considered valid for up to several months.
/// Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
/// almanac" for details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgAlmanacGloDep {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all almanac types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: AlmanacCommonContentDep,
    /// Longitude of the first ascending node of the orbit in PZ-90.02
    /// coordinate system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lambda_na")))]
    pub lambda_na: f64,
    /// Time of the first ascending node passage
    #[cfg_attr(feature = "serde", serde(rename(serialize = "t_lambda_na")))]
    pub t_lambda_na: f64,
    /// Value of inclination at instant of t_lambda
    #[cfg_attr(feature = "serde", serde(rename(serialize = "i")))]
    pub i: f64,
    /// Value of Draconian period at instant of t_lambda
    #[cfg_attr(feature = "serde", serde(rename(serialize = "t")))]
    pub t: f64,
    /// Rate of change of the Draconian period
    #[cfg_attr(feature = "serde", serde(rename(serialize = "t_dot")))]
    pub t_dot: f64,
    /// Eccentricity at instant of t_lambda
    #[cfg_attr(feature = "serde", serde(rename(serialize = "epsilon")))]
    pub epsilon: f64,
    /// Argument of perigee at instant of t_lambda
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omega")))]
    pub omega: f64,
}

impl ConcreteMessage for MsgAlmanacGloDep {
    const MESSAGE_TYPE: u16 = 113;
    const MESSAGE_NAME: &'static str = "MSG_ALMANAC_GLO_DEP";
}

impl SbpMessage for MsgAlmanacGloDep {
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

impl TryFrom<Sbp> for MsgAlmanacGloDep {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgAlmanacGloDep(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgAlmanacGloDep {
    const MIN_LEN: usize = <AlmanacCommonContentDep as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.lambda_na)
            + WireFormat::len(&self.t_lambda_na)
            + WireFormat::len(&self.i)
            + WireFormat::len(&self.t)
            + WireFormat::len(&self.t_dot)
            + WireFormat::len(&self.epsilon)
            + WireFormat::len(&self.omega)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.lambda_na, buf);
        WireFormat::write(&self.t_lambda_na, buf);
        WireFormat::write(&self.i, buf);
        WireFormat::write(&self.t, buf);
        WireFormat::write(&self.t_dot, buf);
        WireFormat::write(&self.epsilon, buf);
        WireFormat::write(&self.omega, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgAlmanacGloDep {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            lambda_na: WireFormat::parse_unchecked(buf),
            t_lambda_na: WireFormat::parse_unchecked(buf),
            i: WireFormat::parse_unchecked(buf),
            t: WireFormat::parse_unchecked(buf),
            t_dot: WireFormat::parse_unchecked(buf),
            epsilon: WireFormat::parse_unchecked(buf),
            omega: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris for GPS
///
/// The almanac message returns a set of satellite orbit parameters. Almanac
/// data is not very precise and is considered valid for up to several months.
/// Please see the Navstar GPS Space Segment/Navigation user interfaces (ICD-
/// GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgAlmanacGps {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all almanac types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: AlmanacCommonContent,
    /// Mean anomaly at reference time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "m0")))]
    pub m0: f64,
    /// Eccentricity of satellite orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ecc")))]
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sqrta")))]
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omega0")))]
    pub omega0: f64,
    /// Rate of right ascension
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omegadot")))]
    pub omegadot: f64,
    /// Argument of perigee
    #[cfg_attr(feature = "serde", serde(rename(serialize = "w")))]
    pub w: f64,
    /// Inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc")))]
    pub inc: f64,
    /// Polynomial clock correction coefficient (clock bias)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af0")))]
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af1")))]
    pub af1: f64,
}

impl ConcreteMessage for MsgAlmanacGps {
    const MESSAGE_TYPE: u16 = 114;
    const MESSAGE_NAME: &'static str = "MSG_ALMANAC_GPS";
}

impl SbpMessage for MsgAlmanacGps {
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

impl TryFrom<Sbp> for MsgAlmanacGps {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgAlmanacGps(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgAlmanacGps {
    const MIN_LEN: usize = <AlmanacCommonContent as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.m0)
            + WireFormat::len(&self.ecc)
            + WireFormat::len(&self.sqrta)
            + WireFormat::len(&self.omega0)
            + WireFormat::len(&self.omegadot)
            + WireFormat::len(&self.w)
            + WireFormat::len(&self.inc)
            + WireFormat::len(&self.af0)
            + WireFormat::len(&self.af1)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.m0, buf);
        WireFormat::write(&self.ecc, buf);
        WireFormat::write(&self.sqrta, buf);
        WireFormat::write(&self.omega0, buf);
        WireFormat::write(&self.omegadot, buf);
        WireFormat::write(&self.w, buf);
        WireFormat::write(&self.inc, buf);
        WireFormat::write(&self.af0, buf);
        WireFormat::write(&self.af1, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgAlmanacGps {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            m0: WireFormat::parse_unchecked(buf),
            ecc: WireFormat::parse_unchecked(buf),
            sqrta: WireFormat::parse_unchecked(buf),
            omega0: WireFormat::parse_unchecked(buf),
            omegadot: WireFormat::parse_unchecked(buf),
            w: WireFormat::parse_unchecked(buf),
            inc: WireFormat::parse_unchecked(buf),
            af0: WireFormat::parse_unchecked(buf),
            af1: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris for GPS
///
/// The almanac message returns a set of satellite orbit parameters. Almanac
/// data is not very precise and is considered valid for up to several months.
/// Please see the Navstar GPS Space Segment/Navigation user interfaces (ICD-
/// GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgAlmanacGpsDep {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all almanac types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: AlmanacCommonContentDep,
    /// Mean anomaly at reference time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "m0")))]
    pub m0: f64,
    /// Eccentricity of satellite orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ecc")))]
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sqrta")))]
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omega0")))]
    pub omega0: f64,
    /// Rate of right ascension
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omegadot")))]
    pub omegadot: f64,
    /// Argument of perigee
    #[cfg_attr(feature = "serde", serde(rename(serialize = "w")))]
    pub w: f64,
    /// Inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc")))]
    pub inc: f64,
    /// Polynomial clock correction coefficient (clock bias)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af0")))]
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af1")))]
    pub af1: f64,
}

impl ConcreteMessage for MsgAlmanacGpsDep {
    const MESSAGE_TYPE: u16 = 112;
    const MESSAGE_NAME: &'static str = "MSG_ALMANAC_GPS_DEP";
}

impl SbpMessage for MsgAlmanacGpsDep {
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

impl TryFrom<Sbp> for MsgAlmanacGpsDep {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgAlmanacGpsDep(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgAlmanacGpsDep {
    const MIN_LEN: usize = <AlmanacCommonContentDep as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.m0)
            + WireFormat::len(&self.ecc)
            + WireFormat::len(&self.sqrta)
            + WireFormat::len(&self.omega0)
            + WireFormat::len(&self.omegadot)
            + WireFormat::len(&self.w)
            + WireFormat::len(&self.inc)
            + WireFormat::len(&self.af0)
            + WireFormat::len(&self.af1)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.m0, buf);
        WireFormat::write(&self.ecc, buf);
        WireFormat::write(&self.sqrta, buf);
        WireFormat::write(&self.omega0, buf);
        WireFormat::write(&self.omegadot, buf);
        WireFormat::write(&self.w, buf);
        WireFormat::write(&self.inc, buf);
        WireFormat::write(&self.af0, buf);
        WireFormat::write(&self.af1, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgAlmanacGpsDep {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            m0: WireFormat::parse_unchecked(buf),
            ecc: WireFormat::parse_unchecked(buf),
            sqrta: WireFormat::parse_unchecked(buf),
            omega0: WireFormat::parse_unchecked(buf),
            omegadot: WireFormat::parse_unchecked(buf),
            w: WireFormat::parse_unchecked(buf),
            inc: WireFormat::parse_unchecked(buf),
            af0: WireFormat::parse_unchecked(buf),
            af1: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Base station position in ECEF
///
/// The base station position message is the position reported by the base
/// station itself in absolute Earth Centered Earth Fixed coordinates. It is
/// used for pseudo-absolute RTK positioning, and is required to be a high-
/// accuracy surveyed location of the base station. Any error here will result
/// in an error in the pseudo-absolute position output.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgBasePosEcef {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// ECEF X coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "x")))]
    pub x: f64,
    /// ECEF Y coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "y")))]
    pub y: f64,
    /// ECEF Z coordinate
    #[cfg_attr(feature = "serde", serde(rename(serialize = "z")))]
    pub z: f64,
}

impl ConcreteMessage for MsgBasePosEcef {
    const MESSAGE_TYPE: u16 = 72;
    const MESSAGE_NAME: &'static str = "MSG_BASE_POS_ECEF";
}

impl SbpMessage for MsgBasePosEcef {
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

impl TryFrom<Sbp> for MsgBasePosEcef {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgBasePosEcef(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgBasePosEcef {
    const MIN_LEN: usize =
        <f64 as WireFormat>::MIN_LEN + <f64 as WireFormat>::MIN_LEN + <f64 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.x) + WireFormat::len(&self.y) + WireFormat::len(&self.z)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.x, buf);
        WireFormat::write(&self.y, buf);
        WireFormat::write(&self.z, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgBasePosEcef {
            sender_id: None,
            x: WireFormat::parse_unchecked(buf),
            y: WireFormat::parse_unchecked(buf),
            z: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Base station position
///
/// The base station position message is the position reported by the base
/// station itself. It is used for pseudo-absolute RTK positioning, and is
/// required to be a high-accuracy surveyed location of the base station. Any
/// error here will result in an error in the pseudo-absolute position output.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgBasePosLlh {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lat")))]
    pub lat: f64,
    /// Longitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lon")))]
    pub lon: f64,
    /// Height
    #[cfg_attr(feature = "serde", serde(rename(serialize = "height")))]
    pub height: f64,
}

impl ConcreteMessage for MsgBasePosLlh {
    const MESSAGE_TYPE: u16 = 68;
    const MESSAGE_NAME: &'static str = "MSG_BASE_POS_LLH";
}

impl SbpMessage for MsgBasePosLlh {
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

impl TryFrom<Sbp> for MsgBasePosLlh {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgBasePosLlh(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgBasePosLlh {
    const MIN_LEN: usize =
        <f64 as WireFormat>::MIN_LEN + <f64 as WireFormat>::MIN_LEN + <f64 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.lat) + WireFormat::len(&self.lon) + WireFormat::len(&self.height)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.lat, buf);
        WireFormat::write(&self.lon, buf);
        WireFormat::write(&self.height, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgBasePosLlh {
            sender_id: None,
            lat: WireFormat::parse_unchecked(buf),
            lon: WireFormat::parse_unchecked(buf),
            height: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris for BDS
///
/// The ephemeris message returns a set of satellite orbit parameters that is
/// used to calculate BDS satellite position, velocity, and clock offset.
/// Please see the BeiDou Navigation Satellite System SIS-ICD Version 2.1,
/// Table 5-9 for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisBds {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: EphemerisCommonContent,
    /// Group delay differential for B1
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tgd1")))]
    pub tgd1: f32,
    /// Group delay differential for B2
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tgd2")))]
    pub tgd2: f32,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rs")))]
    pub c_rs: f32,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rc")))]
    pub c_rc: f32,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_uc")))]
    pub c_uc: f32,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_us")))]
    pub c_us: f32,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_ic")))]
    pub c_ic: f32,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_is")))]
    pub c_is: f32,
    /// Mean motion difference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dn")))]
    pub dn: f64,
    /// Mean anomaly at reference time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "m0")))]
    pub m0: f64,
    /// Eccentricity of satellite orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ecc")))]
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sqrta")))]
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omega0")))]
    pub omega0: f64,
    /// Rate of right ascension
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omegadot")))]
    pub omegadot: f64,
    /// Argument of perigee
    #[cfg_attr(feature = "serde", serde(rename(serialize = "w")))]
    pub w: f64,
    /// Inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc")))]
    pub inc: f64,
    /// Inclination first derivative
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc_dot")))]
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af0")))]
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af1")))]
    pub af1: f32,
    /// Polynomial clock correction coefficient (rate of clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af2")))]
    pub af2: f32,
    /// Clock reference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toc")))]
    pub toc: GpsTimeSec,
    /// Issue of ephemeris data
    /// Calculated from the navigation data parameter t_oe per RTCM/CSNO
    /// recommendation: IODE = mod (t_oe / 720, 240)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iode")))]
    pub iode: u8,
    /// Issue of clock data
    /// Calculated from the navigation data parameter t_oe per RTCM/CSNO
    /// recommendation: IODE = mod (t_oc / 720, 240)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iodc")))]
    pub iodc: u16,
}

impl ConcreteMessage for MsgEphemerisBds {
    const MESSAGE_TYPE: u16 = 137;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_BDS";
}

impl SbpMessage for MsgEphemerisBds {
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

impl TryFrom<Sbp> for MsgEphemerisBds {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisBds(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisBds {
    const MIN_LEN: usize = <EphemerisCommonContent as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <GpsTimeSec as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.tgd1)
            + WireFormat::len(&self.tgd2)
            + WireFormat::len(&self.c_rs)
            + WireFormat::len(&self.c_rc)
            + WireFormat::len(&self.c_uc)
            + WireFormat::len(&self.c_us)
            + WireFormat::len(&self.c_ic)
            + WireFormat::len(&self.c_is)
            + WireFormat::len(&self.dn)
            + WireFormat::len(&self.m0)
            + WireFormat::len(&self.ecc)
            + WireFormat::len(&self.sqrta)
            + WireFormat::len(&self.omega0)
            + WireFormat::len(&self.omegadot)
            + WireFormat::len(&self.w)
            + WireFormat::len(&self.inc)
            + WireFormat::len(&self.inc_dot)
            + WireFormat::len(&self.af0)
            + WireFormat::len(&self.af1)
            + WireFormat::len(&self.af2)
            + WireFormat::len(&self.toc)
            + WireFormat::len(&self.iode)
            + WireFormat::len(&self.iodc)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.tgd1, buf);
        WireFormat::write(&self.tgd2, buf);
        WireFormat::write(&self.c_rs, buf);
        WireFormat::write(&self.c_rc, buf);
        WireFormat::write(&self.c_uc, buf);
        WireFormat::write(&self.c_us, buf);
        WireFormat::write(&self.c_ic, buf);
        WireFormat::write(&self.c_is, buf);
        WireFormat::write(&self.dn, buf);
        WireFormat::write(&self.m0, buf);
        WireFormat::write(&self.ecc, buf);
        WireFormat::write(&self.sqrta, buf);
        WireFormat::write(&self.omega0, buf);
        WireFormat::write(&self.omegadot, buf);
        WireFormat::write(&self.w, buf);
        WireFormat::write(&self.inc, buf);
        WireFormat::write(&self.inc_dot, buf);
        WireFormat::write(&self.af0, buf);
        WireFormat::write(&self.af1, buf);
        WireFormat::write(&self.af2, buf);
        WireFormat::write(&self.toc, buf);
        WireFormat::write(&self.iode, buf);
        WireFormat::write(&self.iodc, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisBds {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            tgd1: WireFormat::parse_unchecked(buf),
            tgd2: WireFormat::parse_unchecked(buf),
            c_rs: WireFormat::parse_unchecked(buf),
            c_rc: WireFormat::parse_unchecked(buf),
            c_uc: WireFormat::parse_unchecked(buf),
            c_us: WireFormat::parse_unchecked(buf),
            c_ic: WireFormat::parse_unchecked(buf),
            c_is: WireFormat::parse_unchecked(buf),
            dn: WireFormat::parse_unchecked(buf),
            m0: WireFormat::parse_unchecked(buf),
            ecc: WireFormat::parse_unchecked(buf),
            sqrta: WireFormat::parse_unchecked(buf),
            omega0: WireFormat::parse_unchecked(buf),
            omegadot: WireFormat::parse_unchecked(buf),
            w: WireFormat::parse_unchecked(buf),
            inc: WireFormat::parse_unchecked(buf),
            inc_dot: WireFormat::parse_unchecked(buf),
            af0: WireFormat::parse_unchecked(buf),
            af1: WireFormat::parse_unchecked(buf),
            af2: WireFormat::parse_unchecked(buf),
            toc: WireFormat::parse_unchecked(buf),
            iode: WireFormat::parse_unchecked(buf),
            iodc: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Group delay differential between L1 and L2
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tgd")))]
    pub tgd: f64,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rs")))]
    pub c_rs: f64,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rc")))]
    pub c_rc: f64,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_uc")))]
    pub c_uc: f64,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_us")))]
    pub c_us: f64,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_ic")))]
    pub c_ic: f64,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_is")))]
    pub c_is: f64,
    /// Mean motion difference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dn")))]
    pub dn: f64,
    /// Mean anomaly at reference time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "m0")))]
    pub m0: f64,
    /// Eccentricity of satellite orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ecc")))]
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sqrta")))]
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omega0")))]
    pub omega0: f64,
    /// Rate of right ascension
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omegadot")))]
    pub omegadot: f64,
    /// Argument of perigee
    #[cfg_attr(feature = "serde", serde(rename(serialize = "w")))]
    pub w: f64,
    /// Inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc")))]
    pub inc: f64,
    /// Inclination first derivative
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc_dot")))]
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af0")))]
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af1")))]
    pub af1: f64,
    /// Polynomial clock correction coefficient (rate of clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af2")))]
    pub af2: f64,
    /// Time of week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toe_tow")))]
    pub toe_tow: f64,
    /// Week number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toe_wn")))]
    pub toe_wn: u16,
    /// Clock reference time of week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toc_tow")))]
    pub toc_tow: f64,
    /// Clock reference week number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toc_wn")))]
    pub toc_wn: u16,
    /// Is valid?
    #[cfg_attr(feature = "serde", serde(rename(serialize = "valid")))]
    pub valid: u8,
    /// Satellite is healthy?
    #[cfg_attr(feature = "serde", serde(rename(serialize = "healthy")))]
    pub healthy: u8,
    /// PRN being tracked
    #[cfg_attr(feature = "serde", serde(rename(serialize = "prn")))]
    pub prn: u8,
}

impl ConcreteMessage for MsgEphemerisDepA {
    const MESSAGE_TYPE: u16 = 26;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_DEP_A";
}

impl SbpMessage for MsgEphemerisDepA {
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

impl TryFrom<Sbp> for MsgEphemerisDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisDepA {
    const MIN_LEN: usize = <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tgd)
            + WireFormat::len(&self.c_rs)
            + WireFormat::len(&self.c_rc)
            + WireFormat::len(&self.c_uc)
            + WireFormat::len(&self.c_us)
            + WireFormat::len(&self.c_ic)
            + WireFormat::len(&self.c_is)
            + WireFormat::len(&self.dn)
            + WireFormat::len(&self.m0)
            + WireFormat::len(&self.ecc)
            + WireFormat::len(&self.sqrta)
            + WireFormat::len(&self.omega0)
            + WireFormat::len(&self.omegadot)
            + WireFormat::len(&self.w)
            + WireFormat::len(&self.inc)
            + WireFormat::len(&self.inc_dot)
            + WireFormat::len(&self.af0)
            + WireFormat::len(&self.af1)
            + WireFormat::len(&self.af2)
            + WireFormat::len(&self.toe_tow)
            + WireFormat::len(&self.toe_wn)
            + WireFormat::len(&self.toc_tow)
            + WireFormat::len(&self.toc_wn)
            + WireFormat::len(&self.valid)
            + WireFormat::len(&self.healthy)
            + WireFormat::len(&self.prn)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tgd, buf);
        WireFormat::write(&self.c_rs, buf);
        WireFormat::write(&self.c_rc, buf);
        WireFormat::write(&self.c_uc, buf);
        WireFormat::write(&self.c_us, buf);
        WireFormat::write(&self.c_ic, buf);
        WireFormat::write(&self.c_is, buf);
        WireFormat::write(&self.dn, buf);
        WireFormat::write(&self.m0, buf);
        WireFormat::write(&self.ecc, buf);
        WireFormat::write(&self.sqrta, buf);
        WireFormat::write(&self.omega0, buf);
        WireFormat::write(&self.omegadot, buf);
        WireFormat::write(&self.w, buf);
        WireFormat::write(&self.inc, buf);
        WireFormat::write(&self.inc_dot, buf);
        WireFormat::write(&self.af0, buf);
        WireFormat::write(&self.af1, buf);
        WireFormat::write(&self.af2, buf);
        WireFormat::write(&self.toe_tow, buf);
        WireFormat::write(&self.toe_wn, buf);
        WireFormat::write(&self.toc_tow, buf);
        WireFormat::write(&self.toc_wn, buf);
        WireFormat::write(&self.valid, buf);
        WireFormat::write(&self.healthy, buf);
        WireFormat::write(&self.prn, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisDepA {
            sender_id: None,
            tgd: WireFormat::parse_unchecked(buf),
            c_rs: WireFormat::parse_unchecked(buf),
            c_rc: WireFormat::parse_unchecked(buf),
            c_uc: WireFormat::parse_unchecked(buf),
            c_us: WireFormat::parse_unchecked(buf),
            c_ic: WireFormat::parse_unchecked(buf),
            c_is: WireFormat::parse_unchecked(buf),
            dn: WireFormat::parse_unchecked(buf),
            m0: WireFormat::parse_unchecked(buf),
            ecc: WireFormat::parse_unchecked(buf),
            sqrta: WireFormat::parse_unchecked(buf),
            omega0: WireFormat::parse_unchecked(buf),
            omegadot: WireFormat::parse_unchecked(buf),
            w: WireFormat::parse_unchecked(buf),
            inc: WireFormat::parse_unchecked(buf),
            inc_dot: WireFormat::parse_unchecked(buf),
            af0: WireFormat::parse_unchecked(buf),
            af1: WireFormat::parse_unchecked(buf),
            af2: WireFormat::parse_unchecked(buf),
            toe_tow: WireFormat::parse_unchecked(buf),
            toe_wn: WireFormat::parse_unchecked(buf),
            toc_tow: WireFormat::parse_unchecked(buf),
            toc_wn: WireFormat::parse_unchecked(buf),
            valid: WireFormat::parse_unchecked(buf),
            healthy: WireFormat::parse_unchecked(buf),
            prn: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisDepB {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Group delay differential between L1 and L2
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tgd")))]
    pub tgd: f64,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rs")))]
    pub c_rs: f64,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rc")))]
    pub c_rc: f64,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_uc")))]
    pub c_uc: f64,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_us")))]
    pub c_us: f64,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_ic")))]
    pub c_ic: f64,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_is")))]
    pub c_is: f64,
    /// Mean motion difference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dn")))]
    pub dn: f64,
    /// Mean anomaly at reference time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "m0")))]
    pub m0: f64,
    /// Eccentricity of satellite orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ecc")))]
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sqrta")))]
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omega0")))]
    pub omega0: f64,
    /// Rate of right ascension
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omegadot")))]
    pub omegadot: f64,
    /// Argument of perigee
    #[cfg_attr(feature = "serde", serde(rename(serialize = "w")))]
    pub w: f64,
    /// Inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc")))]
    pub inc: f64,
    /// Inclination first derivative
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc_dot")))]
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af0")))]
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af1")))]
    pub af1: f64,
    /// Polynomial clock correction coefficient (rate of clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af2")))]
    pub af2: f64,
    /// Time of week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toe_tow")))]
    pub toe_tow: f64,
    /// Week number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toe_wn")))]
    pub toe_wn: u16,
    /// Clock reference time of week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toc_tow")))]
    pub toc_tow: f64,
    /// Clock reference week number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toc_wn")))]
    pub toc_wn: u16,
    /// Is valid?
    #[cfg_attr(feature = "serde", serde(rename(serialize = "valid")))]
    pub valid: u8,
    /// Satellite is healthy?
    #[cfg_attr(feature = "serde", serde(rename(serialize = "healthy")))]
    pub healthy: u8,
    /// PRN being tracked
    #[cfg_attr(feature = "serde", serde(rename(serialize = "prn")))]
    pub prn: u8,
    /// Issue of ephemeris data
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iode")))]
    pub iode: u8,
}

impl ConcreteMessage for MsgEphemerisDepB {
    const MESSAGE_TYPE: u16 = 70;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_DEP_B";
}

impl SbpMessage for MsgEphemerisDepB {
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

impl TryFrom<Sbp> for MsgEphemerisDepB {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisDepB(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisDepB {
    const MIN_LEN: usize = <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tgd)
            + WireFormat::len(&self.c_rs)
            + WireFormat::len(&self.c_rc)
            + WireFormat::len(&self.c_uc)
            + WireFormat::len(&self.c_us)
            + WireFormat::len(&self.c_ic)
            + WireFormat::len(&self.c_is)
            + WireFormat::len(&self.dn)
            + WireFormat::len(&self.m0)
            + WireFormat::len(&self.ecc)
            + WireFormat::len(&self.sqrta)
            + WireFormat::len(&self.omega0)
            + WireFormat::len(&self.omegadot)
            + WireFormat::len(&self.w)
            + WireFormat::len(&self.inc)
            + WireFormat::len(&self.inc_dot)
            + WireFormat::len(&self.af0)
            + WireFormat::len(&self.af1)
            + WireFormat::len(&self.af2)
            + WireFormat::len(&self.toe_tow)
            + WireFormat::len(&self.toe_wn)
            + WireFormat::len(&self.toc_tow)
            + WireFormat::len(&self.toc_wn)
            + WireFormat::len(&self.valid)
            + WireFormat::len(&self.healthy)
            + WireFormat::len(&self.prn)
            + WireFormat::len(&self.iode)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tgd, buf);
        WireFormat::write(&self.c_rs, buf);
        WireFormat::write(&self.c_rc, buf);
        WireFormat::write(&self.c_uc, buf);
        WireFormat::write(&self.c_us, buf);
        WireFormat::write(&self.c_ic, buf);
        WireFormat::write(&self.c_is, buf);
        WireFormat::write(&self.dn, buf);
        WireFormat::write(&self.m0, buf);
        WireFormat::write(&self.ecc, buf);
        WireFormat::write(&self.sqrta, buf);
        WireFormat::write(&self.omega0, buf);
        WireFormat::write(&self.omegadot, buf);
        WireFormat::write(&self.w, buf);
        WireFormat::write(&self.inc, buf);
        WireFormat::write(&self.inc_dot, buf);
        WireFormat::write(&self.af0, buf);
        WireFormat::write(&self.af1, buf);
        WireFormat::write(&self.af2, buf);
        WireFormat::write(&self.toe_tow, buf);
        WireFormat::write(&self.toe_wn, buf);
        WireFormat::write(&self.toc_tow, buf);
        WireFormat::write(&self.toc_wn, buf);
        WireFormat::write(&self.valid, buf);
        WireFormat::write(&self.healthy, buf);
        WireFormat::write(&self.prn, buf);
        WireFormat::write(&self.iode, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisDepB {
            sender_id: None,
            tgd: WireFormat::parse_unchecked(buf),
            c_rs: WireFormat::parse_unchecked(buf),
            c_rc: WireFormat::parse_unchecked(buf),
            c_uc: WireFormat::parse_unchecked(buf),
            c_us: WireFormat::parse_unchecked(buf),
            c_ic: WireFormat::parse_unchecked(buf),
            c_is: WireFormat::parse_unchecked(buf),
            dn: WireFormat::parse_unchecked(buf),
            m0: WireFormat::parse_unchecked(buf),
            ecc: WireFormat::parse_unchecked(buf),
            sqrta: WireFormat::parse_unchecked(buf),
            omega0: WireFormat::parse_unchecked(buf),
            omegadot: WireFormat::parse_unchecked(buf),
            w: WireFormat::parse_unchecked(buf),
            inc: WireFormat::parse_unchecked(buf),
            inc_dot: WireFormat::parse_unchecked(buf),
            af0: WireFormat::parse_unchecked(buf),
            af1: WireFormat::parse_unchecked(buf),
            af2: WireFormat::parse_unchecked(buf),
            toe_tow: WireFormat::parse_unchecked(buf),
            toe_wn: WireFormat::parse_unchecked(buf),
            toc_tow: WireFormat::parse_unchecked(buf),
            toc_wn: WireFormat::parse_unchecked(buf),
            valid: WireFormat::parse_unchecked(buf),
            healthy: WireFormat::parse_unchecked(buf),
            prn: WireFormat::parse_unchecked(buf),
            iode: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris
///
/// The ephemeris message returns a set of satellite orbit parameters that is
/// used to calculate GPS satellite position, velocity, and clock offset.
/// Please see the Navstar GPS Space Segment/Navigation user interfaces (ICD-
/// GPS-200, Table 20-III) for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisDepC {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Group delay differential between L1 and L2
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tgd")))]
    pub tgd: f64,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rs")))]
    pub c_rs: f64,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rc")))]
    pub c_rc: f64,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_uc")))]
    pub c_uc: f64,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_us")))]
    pub c_us: f64,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_ic")))]
    pub c_ic: f64,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_is")))]
    pub c_is: f64,
    /// Mean motion difference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dn")))]
    pub dn: f64,
    /// Mean anomaly at reference time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "m0")))]
    pub m0: f64,
    /// Eccentricity of satellite orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ecc")))]
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sqrta")))]
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omega0")))]
    pub omega0: f64,
    /// Rate of right ascension
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omegadot")))]
    pub omegadot: f64,
    /// Argument of perigee
    #[cfg_attr(feature = "serde", serde(rename(serialize = "w")))]
    pub w: f64,
    /// Inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc")))]
    pub inc: f64,
    /// Inclination first derivative
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc_dot")))]
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af0")))]
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af1")))]
    pub af1: f64,
    /// Polynomial clock correction coefficient (rate of clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af2")))]
    pub af2: f64,
    /// Time of week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toe_tow")))]
    pub toe_tow: f64,
    /// Week number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toe_wn")))]
    pub toe_wn: u16,
    /// Clock reference time of week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toc_tow")))]
    pub toc_tow: f64,
    /// Clock reference week number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toc_wn")))]
    pub toc_wn: u16,
    /// Is valid?
    #[cfg_attr(feature = "serde", serde(rename(serialize = "valid")))]
    pub valid: u8,
    /// Satellite is healthy?
    #[cfg_attr(feature = "serde", serde(rename(serialize = "healthy")))]
    pub healthy: u8,
    /// GNSS signal identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignalDep,
    /// Issue of ephemeris data
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iode")))]
    pub iode: u8,
    /// Issue of clock data
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iodc")))]
    pub iodc: u16,
    /// Reserved field
    #[cfg_attr(feature = "serde", serde(rename(serialize = "reserved")))]
    pub reserved: u32,
}

impl ConcreteMessage for MsgEphemerisDepC {
    const MESSAGE_TYPE: u16 = 71;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_DEP_C";
}

impl SbpMessage for MsgEphemerisDepC {
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

impl TryFrom<Sbp> for MsgEphemerisDepC {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisDepC(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisDepC {
    const MIN_LEN: usize = <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <GnssSignalDep as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tgd)
            + WireFormat::len(&self.c_rs)
            + WireFormat::len(&self.c_rc)
            + WireFormat::len(&self.c_uc)
            + WireFormat::len(&self.c_us)
            + WireFormat::len(&self.c_ic)
            + WireFormat::len(&self.c_is)
            + WireFormat::len(&self.dn)
            + WireFormat::len(&self.m0)
            + WireFormat::len(&self.ecc)
            + WireFormat::len(&self.sqrta)
            + WireFormat::len(&self.omega0)
            + WireFormat::len(&self.omegadot)
            + WireFormat::len(&self.w)
            + WireFormat::len(&self.inc)
            + WireFormat::len(&self.inc_dot)
            + WireFormat::len(&self.af0)
            + WireFormat::len(&self.af1)
            + WireFormat::len(&self.af2)
            + WireFormat::len(&self.toe_tow)
            + WireFormat::len(&self.toe_wn)
            + WireFormat::len(&self.toc_tow)
            + WireFormat::len(&self.toc_wn)
            + WireFormat::len(&self.valid)
            + WireFormat::len(&self.healthy)
            + WireFormat::len(&self.sid)
            + WireFormat::len(&self.iode)
            + WireFormat::len(&self.iodc)
            + WireFormat::len(&self.reserved)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tgd, buf);
        WireFormat::write(&self.c_rs, buf);
        WireFormat::write(&self.c_rc, buf);
        WireFormat::write(&self.c_uc, buf);
        WireFormat::write(&self.c_us, buf);
        WireFormat::write(&self.c_ic, buf);
        WireFormat::write(&self.c_is, buf);
        WireFormat::write(&self.dn, buf);
        WireFormat::write(&self.m0, buf);
        WireFormat::write(&self.ecc, buf);
        WireFormat::write(&self.sqrta, buf);
        WireFormat::write(&self.omega0, buf);
        WireFormat::write(&self.omegadot, buf);
        WireFormat::write(&self.w, buf);
        WireFormat::write(&self.inc, buf);
        WireFormat::write(&self.inc_dot, buf);
        WireFormat::write(&self.af0, buf);
        WireFormat::write(&self.af1, buf);
        WireFormat::write(&self.af2, buf);
        WireFormat::write(&self.toe_tow, buf);
        WireFormat::write(&self.toe_wn, buf);
        WireFormat::write(&self.toc_tow, buf);
        WireFormat::write(&self.toc_wn, buf);
        WireFormat::write(&self.valid, buf);
        WireFormat::write(&self.healthy, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.iode, buf);
        WireFormat::write(&self.iodc, buf);
        WireFormat::write(&self.reserved, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisDepC {
            sender_id: None,
            tgd: WireFormat::parse_unchecked(buf),
            c_rs: WireFormat::parse_unchecked(buf),
            c_rc: WireFormat::parse_unchecked(buf),
            c_uc: WireFormat::parse_unchecked(buf),
            c_us: WireFormat::parse_unchecked(buf),
            c_ic: WireFormat::parse_unchecked(buf),
            c_is: WireFormat::parse_unchecked(buf),
            dn: WireFormat::parse_unchecked(buf),
            m0: WireFormat::parse_unchecked(buf),
            ecc: WireFormat::parse_unchecked(buf),
            sqrta: WireFormat::parse_unchecked(buf),
            omega0: WireFormat::parse_unchecked(buf),
            omegadot: WireFormat::parse_unchecked(buf),
            w: WireFormat::parse_unchecked(buf),
            inc: WireFormat::parse_unchecked(buf),
            inc_dot: WireFormat::parse_unchecked(buf),
            af0: WireFormat::parse_unchecked(buf),
            af1: WireFormat::parse_unchecked(buf),
            af2: WireFormat::parse_unchecked(buf),
            toe_tow: WireFormat::parse_unchecked(buf),
            toe_wn: WireFormat::parse_unchecked(buf),
            toc_tow: WireFormat::parse_unchecked(buf),
            toc_wn: WireFormat::parse_unchecked(buf),
            valid: WireFormat::parse_unchecked(buf),
            healthy: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            iode: WireFormat::parse_unchecked(buf),
            iodc: WireFormat::parse_unchecked(buf),
            reserved: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris
///
/// The ephemeris message returns a set of satellite orbit parameters that is
/// used to calculate GPS satellite position, velocity, and clock offset.
/// Please see the Navstar GPS Space Segment/Navigation user interfaces (ICD-
/// GPS-200, Table 20-III) for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisDepD {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Group delay differential between L1 and L2
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tgd")))]
    pub tgd: f64,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rs")))]
    pub c_rs: f64,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rc")))]
    pub c_rc: f64,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_uc")))]
    pub c_uc: f64,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_us")))]
    pub c_us: f64,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_ic")))]
    pub c_ic: f64,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_is")))]
    pub c_is: f64,
    /// Mean motion difference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dn")))]
    pub dn: f64,
    /// Mean anomaly at reference time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "m0")))]
    pub m0: f64,
    /// Eccentricity of satellite orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ecc")))]
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sqrta")))]
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omega0")))]
    pub omega0: f64,
    /// Rate of right ascension
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omegadot")))]
    pub omegadot: f64,
    /// Argument of perigee
    #[cfg_attr(feature = "serde", serde(rename(serialize = "w")))]
    pub w: f64,
    /// Inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc")))]
    pub inc: f64,
    /// Inclination first derivative
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc_dot")))]
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af0")))]
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af1")))]
    pub af1: f64,
    /// Polynomial clock correction coefficient (rate of clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af2")))]
    pub af2: f64,
    /// Time of week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toe_tow")))]
    pub toe_tow: f64,
    /// Week number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toe_wn")))]
    pub toe_wn: u16,
    /// Clock reference time of week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toc_tow")))]
    pub toc_tow: f64,
    /// Clock reference week number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toc_wn")))]
    pub toc_wn: u16,
    /// Is valid?
    #[cfg_attr(feature = "serde", serde(rename(serialize = "valid")))]
    pub valid: u8,
    /// Satellite is healthy?
    #[cfg_attr(feature = "serde", serde(rename(serialize = "healthy")))]
    pub healthy: u8,
    /// GNSS signal identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignalDep,
    /// Issue of ephemeris data
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iode")))]
    pub iode: u8,
    /// Issue of clock data
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iodc")))]
    pub iodc: u16,
    /// Reserved field
    #[cfg_attr(feature = "serde", serde(rename(serialize = "reserved")))]
    pub reserved: u32,
}

impl ConcreteMessage for MsgEphemerisDepD {
    const MESSAGE_TYPE: u16 = 128;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_DEP_D";
}

impl SbpMessage for MsgEphemerisDepD {
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

impl TryFrom<Sbp> for MsgEphemerisDepD {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisDepD(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisDepD {
    const MIN_LEN: usize = <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <GnssSignalDep as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tgd)
            + WireFormat::len(&self.c_rs)
            + WireFormat::len(&self.c_rc)
            + WireFormat::len(&self.c_uc)
            + WireFormat::len(&self.c_us)
            + WireFormat::len(&self.c_ic)
            + WireFormat::len(&self.c_is)
            + WireFormat::len(&self.dn)
            + WireFormat::len(&self.m0)
            + WireFormat::len(&self.ecc)
            + WireFormat::len(&self.sqrta)
            + WireFormat::len(&self.omega0)
            + WireFormat::len(&self.omegadot)
            + WireFormat::len(&self.w)
            + WireFormat::len(&self.inc)
            + WireFormat::len(&self.inc_dot)
            + WireFormat::len(&self.af0)
            + WireFormat::len(&self.af1)
            + WireFormat::len(&self.af2)
            + WireFormat::len(&self.toe_tow)
            + WireFormat::len(&self.toe_wn)
            + WireFormat::len(&self.toc_tow)
            + WireFormat::len(&self.toc_wn)
            + WireFormat::len(&self.valid)
            + WireFormat::len(&self.healthy)
            + WireFormat::len(&self.sid)
            + WireFormat::len(&self.iode)
            + WireFormat::len(&self.iodc)
            + WireFormat::len(&self.reserved)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tgd, buf);
        WireFormat::write(&self.c_rs, buf);
        WireFormat::write(&self.c_rc, buf);
        WireFormat::write(&self.c_uc, buf);
        WireFormat::write(&self.c_us, buf);
        WireFormat::write(&self.c_ic, buf);
        WireFormat::write(&self.c_is, buf);
        WireFormat::write(&self.dn, buf);
        WireFormat::write(&self.m0, buf);
        WireFormat::write(&self.ecc, buf);
        WireFormat::write(&self.sqrta, buf);
        WireFormat::write(&self.omega0, buf);
        WireFormat::write(&self.omegadot, buf);
        WireFormat::write(&self.w, buf);
        WireFormat::write(&self.inc, buf);
        WireFormat::write(&self.inc_dot, buf);
        WireFormat::write(&self.af0, buf);
        WireFormat::write(&self.af1, buf);
        WireFormat::write(&self.af2, buf);
        WireFormat::write(&self.toe_tow, buf);
        WireFormat::write(&self.toe_wn, buf);
        WireFormat::write(&self.toc_tow, buf);
        WireFormat::write(&self.toc_wn, buf);
        WireFormat::write(&self.valid, buf);
        WireFormat::write(&self.healthy, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.iode, buf);
        WireFormat::write(&self.iodc, buf);
        WireFormat::write(&self.reserved, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisDepD {
            sender_id: None,
            tgd: WireFormat::parse_unchecked(buf),
            c_rs: WireFormat::parse_unchecked(buf),
            c_rc: WireFormat::parse_unchecked(buf),
            c_uc: WireFormat::parse_unchecked(buf),
            c_us: WireFormat::parse_unchecked(buf),
            c_ic: WireFormat::parse_unchecked(buf),
            c_is: WireFormat::parse_unchecked(buf),
            dn: WireFormat::parse_unchecked(buf),
            m0: WireFormat::parse_unchecked(buf),
            ecc: WireFormat::parse_unchecked(buf),
            sqrta: WireFormat::parse_unchecked(buf),
            omega0: WireFormat::parse_unchecked(buf),
            omegadot: WireFormat::parse_unchecked(buf),
            w: WireFormat::parse_unchecked(buf),
            inc: WireFormat::parse_unchecked(buf),
            inc_dot: WireFormat::parse_unchecked(buf),
            af0: WireFormat::parse_unchecked(buf),
            af1: WireFormat::parse_unchecked(buf),
            af2: WireFormat::parse_unchecked(buf),
            toe_tow: WireFormat::parse_unchecked(buf),
            toe_wn: WireFormat::parse_unchecked(buf),
            toc_tow: WireFormat::parse_unchecked(buf),
            toc_wn: WireFormat::parse_unchecked(buf),
            valid: WireFormat::parse_unchecked(buf),
            healthy: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            iode: WireFormat::parse_unchecked(buf),
            iodc: WireFormat::parse_unchecked(buf),
            reserved: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris for Galileo
///
/// The ephemeris message returns a set of satellite orbit parameters that is
/// used to calculate Galileo satellite position, velocity, and clock offset.
/// Please see the Signal In Space ICD OS SIS ICD, Issue 1.3, December 2016
/// for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisGal {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: EphemerisCommonContent,
    /// E1-E5a Broadcast Group Delay
    #[cfg_attr(feature = "serde", serde(rename(serialize = "bgd_e1e5a")))]
    pub bgd_e1e5a: f32,
    /// E1-E5b Broadcast Group Delay
    #[cfg_attr(feature = "serde", serde(rename(serialize = "bgd_e1e5b")))]
    pub bgd_e1e5b: f32,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rs")))]
    pub c_rs: f32,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rc")))]
    pub c_rc: f32,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_uc")))]
    pub c_uc: f32,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_us")))]
    pub c_us: f32,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_ic")))]
    pub c_ic: f32,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_is")))]
    pub c_is: f32,
    /// Mean motion difference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dn")))]
    pub dn: f64,
    /// Mean anomaly at reference time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "m0")))]
    pub m0: f64,
    /// Eccentricity of satellite orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ecc")))]
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sqrta")))]
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omega0")))]
    pub omega0: f64,
    /// Rate of right ascension
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omegadot")))]
    pub omegadot: f64,
    /// Argument of perigee
    #[cfg_attr(feature = "serde", serde(rename(serialize = "w")))]
    pub w: f64,
    /// Inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc")))]
    pub inc: f64,
    /// Inclination first derivative
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc_dot")))]
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af0")))]
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af1")))]
    pub af1: f64,
    /// Polynomial clock correction coefficient (rate of clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af2")))]
    pub af2: f32,
    /// Clock reference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toc")))]
    pub toc: GpsTimeSec,
    /// Issue of data (IODnav)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iode")))]
    pub iode: u16,
    /// Issue of data (IODnav). Always equal to iode
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iodc")))]
    pub iodc: u16,
    /// 0=I/NAV, 1=F/NAV
    #[cfg_attr(feature = "serde", serde(rename(serialize = "source")))]
    pub source: u8,
}

impl ConcreteMessage for MsgEphemerisGal {
    const MESSAGE_TYPE: u16 = 141;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_GAL";
}

impl SbpMessage for MsgEphemerisGal {
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

impl TryFrom<Sbp> for MsgEphemerisGal {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisGal(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisGal {
    const MIN_LEN: usize = <EphemerisCommonContent as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <GpsTimeSec as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.bgd_e1e5a)
            + WireFormat::len(&self.bgd_e1e5b)
            + WireFormat::len(&self.c_rs)
            + WireFormat::len(&self.c_rc)
            + WireFormat::len(&self.c_uc)
            + WireFormat::len(&self.c_us)
            + WireFormat::len(&self.c_ic)
            + WireFormat::len(&self.c_is)
            + WireFormat::len(&self.dn)
            + WireFormat::len(&self.m0)
            + WireFormat::len(&self.ecc)
            + WireFormat::len(&self.sqrta)
            + WireFormat::len(&self.omega0)
            + WireFormat::len(&self.omegadot)
            + WireFormat::len(&self.w)
            + WireFormat::len(&self.inc)
            + WireFormat::len(&self.inc_dot)
            + WireFormat::len(&self.af0)
            + WireFormat::len(&self.af1)
            + WireFormat::len(&self.af2)
            + WireFormat::len(&self.toc)
            + WireFormat::len(&self.iode)
            + WireFormat::len(&self.iodc)
            + WireFormat::len(&self.source)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.bgd_e1e5a, buf);
        WireFormat::write(&self.bgd_e1e5b, buf);
        WireFormat::write(&self.c_rs, buf);
        WireFormat::write(&self.c_rc, buf);
        WireFormat::write(&self.c_uc, buf);
        WireFormat::write(&self.c_us, buf);
        WireFormat::write(&self.c_ic, buf);
        WireFormat::write(&self.c_is, buf);
        WireFormat::write(&self.dn, buf);
        WireFormat::write(&self.m0, buf);
        WireFormat::write(&self.ecc, buf);
        WireFormat::write(&self.sqrta, buf);
        WireFormat::write(&self.omega0, buf);
        WireFormat::write(&self.omegadot, buf);
        WireFormat::write(&self.w, buf);
        WireFormat::write(&self.inc, buf);
        WireFormat::write(&self.inc_dot, buf);
        WireFormat::write(&self.af0, buf);
        WireFormat::write(&self.af1, buf);
        WireFormat::write(&self.af2, buf);
        WireFormat::write(&self.toc, buf);
        WireFormat::write(&self.iode, buf);
        WireFormat::write(&self.iodc, buf);
        WireFormat::write(&self.source, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisGal {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            bgd_e1e5a: WireFormat::parse_unchecked(buf),
            bgd_e1e5b: WireFormat::parse_unchecked(buf),
            c_rs: WireFormat::parse_unchecked(buf),
            c_rc: WireFormat::parse_unchecked(buf),
            c_uc: WireFormat::parse_unchecked(buf),
            c_us: WireFormat::parse_unchecked(buf),
            c_ic: WireFormat::parse_unchecked(buf),
            c_is: WireFormat::parse_unchecked(buf),
            dn: WireFormat::parse_unchecked(buf),
            m0: WireFormat::parse_unchecked(buf),
            ecc: WireFormat::parse_unchecked(buf),
            sqrta: WireFormat::parse_unchecked(buf),
            omega0: WireFormat::parse_unchecked(buf),
            omegadot: WireFormat::parse_unchecked(buf),
            w: WireFormat::parse_unchecked(buf),
            inc: WireFormat::parse_unchecked(buf),
            inc_dot: WireFormat::parse_unchecked(buf),
            af0: WireFormat::parse_unchecked(buf),
            af1: WireFormat::parse_unchecked(buf),
            af2: WireFormat::parse_unchecked(buf),
            toc: WireFormat::parse_unchecked(buf),
            iode: WireFormat::parse_unchecked(buf),
            iodc: WireFormat::parse_unchecked(buf),
            source: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// This observation message has been deprecated in favor of an ephemeris
/// message with explicit source of NAV data.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisGalDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: EphemerisCommonContent,
    /// E1-E5a Broadcast Group Delay
    #[cfg_attr(feature = "serde", serde(rename(serialize = "bgd_e1e5a")))]
    pub bgd_e1e5a: f32,
    /// E1-E5b Broadcast Group Delay
    #[cfg_attr(feature = "serde", serde(rename(serialize = "bgd_e1e5b")))]
    pub bgd_e1e5b: f32,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rs")))]
    pub c_rs: f32,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rc")))]
    pub c_rc: f32,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_uc")))]
    pub c_uc: f32,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_us")))]
    pub c_us: f32,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_ic")))]
    pub c_ic: f32,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_is")))]
    pub c_is: f32,
    /// Mean motion difference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dn")))]
    pub dn: f64,
    /// Mean anomaly at reference time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "m0")))]
    pub m0: f64,
    /// Eccentricity of satellite orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ecc")))]
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sqrta")))]
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omega0")))]
    pub omega0: f64,
    /// Rate of right ascension
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omegadot")))]
    pub omegadot: f64,
    /// Argument of perigee
    #[cfg_attr(feature = "serde", serde(rename(serialize = "w")))]
    pub w: f64,
    /// Inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc")))]
    pub inc: f64,
    /// Inclination first derivative
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc_dot")))]
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af0")))]
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af1")))]
    pub af1: f64,
    /// Polynomial clock correction coefficient (rate of clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af2")))]
    pub af2: f32,
    /// Clock reference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toc")))]
    pub toc: GpsTimeSec,
    /// Issue of data (IODnav)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iode")))]
    pub iode: u16,
    /// Issue of data (IODnav). Always equal to iode
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iodc")))]
    pub iodc: u16,
}

impl ConcreteMessage for MsgEphemerisGalDepA {
    const MESSAGE_TYPE: u16 = 149;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_GAL_DEP_A";
}

impl SbpMessage for MsgEphemerisGalDepA {
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

impl TryFrom<Sbp> for MsgEphemerisGalDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisGalDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisGalDepA {
    const MIN_LEN: usize = <EphemerisCommonContent as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <GpsTimeSec as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.bgd_e1e5a)
            + WireFormat::len(&self.bgd_e1e5b)
            + WireFormat::len(&self.c_rs)
            + WireFormat::len(&self.c_rc)
            + WireFormat::len(&self.c_uc)
            + WireFormat::len(&self.c_us)
            + WireFormat::len(&self.c_ic)
            + WireFormat::len(&self.c_is)
            + WireFormat::len(&self.dn)
            + WireFormat::len(&self.m0)
            + WireFormat::len(&self.ecc)
            + WireFormat::len(&self.sqrta)
            + WireFormat::len(&self.omega0)
            + WireFormat::len(&self.omegadot)
            + WireFormat::len(&self.w)
            + WireFormat::len(&self.inc)
            + WireFormat::len(&self.inc_dot)
            + WireFormat::len(&self.af0)
            + WireFormat::len(&self.af1)
            + WireFormat::len(&self.af2)
            + WireFormat::len(&self.toc)
            + WireFormat::len(&self.iode)
            + WireFormat::len(&self.iodc)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.bgd_e1e5a, buf);
        WireFormat::write(&self.bgd_e1e5b, buf);
        WireFormat::write(&self.c_rs, buf);
        WireFormat::write(&self.c_rc, buf);
        WireFormat::write(&self.c_uc, buf);
        WireFormat::write(&self.c_us, buf);
        WireFormat::write(&self.c_ic, buf);
        WireFormat::write(&self.c_is, buf);
        WireFormat::write(&self.dn, buf);
        WireFormat::write(&self.m0, buf);
        WireFormat::write(&self.ecc, buf);
        WireFormat::write(&self.sqrta, buf);
        WireFormat::write(&self.omega0, buf);
        WireFormat::write(&self.omegadot, buf);
        WireFormat::write(&self.w, buf);
        WireFormat::write(&self.inc, buf);
        WireFormat::write(&self.inc_dot, buf);
        WireFormat::write(&self.af0, buf);
        WireFormat::write(&self.af1, buf);
        WireFormat::write(&self.af2, buf);
        WireFormat::write(&self.toc, buf);
        WireFormat::write(&self.iode, buf);
        WireFormat::write(&self.iodc, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisGalDepA {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            bgd_e1e5a: WireFormat::parse_unchecked(buf),
            bgd_e1e5b: WireFormat::parse_unchecked(buf),
            c_rs: WireFormat::parse_unchecked(buf),
            c_rc: WireFormat::parse_unchecked(buf),
            c_uc: WireFormat::parse_unchecked(buf),
            c_us: WireFormat::parse_unchecked(buf),
            c_ic: WireFormat::parse_unchecked(buf),
            c_is: WireFormat::parse_unchecked(buf),
            dn: WireFormat::parse_unchecked(buf),
            m0: WireFormat::parse_unchecked(buf),
            ecc: WireFormat::parse_unchecked(buf),
            sqrta: WireFormat::parse_unchecked(buf),
            omega0: WireFormat::parse_unchecked(buf),
            omegadot: WireFormat::parse_unchecked(buf),
            w: WireFormat::parse_unchecked(buf),
            inc: WireFormat::parse_unchecked(buf),
            inc_dot: WireFormat::parse_unchecked(buf),
            af0: WireFormat::parse_unchecked(buf),
            af1: WireFormat::parse_unchecked(buf),
            af2: WireFormat::parse_unchecked(buf),
            toc: WireFormat::parse_unchecked(buf),
            iode: WireFormat::parse_unchecked(buf),
            iodc: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris for GLO
///
/// The ephemeris message returns a set of satellite orbit parameters that is
/// used to calculate GLO satellite position, velocity, and clock offset.
/// Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
/// immediate information (ephemeris parameters)" for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisGlo {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: EphemerisCommonContent,
    /// Relative deviation of predicted carrier frequency from nominal
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gamma")))]
    pub gamma: f32,
    /// Correction to the SV time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tau")))]
    pub tau: f32,
    /// Equipment delay between L1 and L2
    #[cfg_attr(feature = "serde", serde(rename(serialize = "d_tau")))]
    pub d_tau: f32,
    /// Position of the SV at tb in PZ-90.02 coordinates system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pos")))]
    pub pos: [f64; 3],
    /// Velocity vector of the SV at tb in PZ-90.02 coordinates system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vel")))]
    pub vel: [f64; 3],
    /// Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    #[cfg_attr(feature = "serde", serde(rename(serialize = "acc")))]
    pub acc: [f32; 3],
    /// Frequency slot. FCN+8 (that is \[1..14\]). 0 or 0xFF for invalid
    #[cfg_attr(feature = "serde", serde(rename(serialize = "fcn")))]
    pub fcn: u8,
    /// Issue of data. Equal to the 7 bits of the immediate data word t_b
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iod")))]
    pub iod: u8,
}

impl ConcreteMessage for MsgEphemerisGlo {
    const MESSAGE_TYPE: u16 = 139;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_GLO";
}

impl SbpMessage for MsgEphemerisGlo {
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

impl TryFrom<Sbp> for MsgEphemerisGlo {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisGlo(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisGlo {
    const MIN_LEN: usize = <EphemerisCommonContent as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <[f32; 3] as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.gamma)
            + WireFormat::len(&self.tau)
            + WireFormat::len(&self.d_tau)
            + WireFormat::len(&self.pos)
            + WireFormat::len(&self.vel)
            + WireFormat::len(&self.acc)
            + WireFormat::len(&self.fcn)
            + WireFormat::len(&self.iod)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.gamma, buf);
        WireFormat::write(&self.tau, buf);
        WireFormat::write(&self.d_tau, buf);
        WireFormat::write(&self.pos, buf);
        WireFormat::write(&self.vel, buf);
        WireFormat::write(&self.acc, buf);
        WireFormat::write(&self.fcn, buf);
        WireFormat::write(&self.iod, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisGlo {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            gamma: WireFormat::parse_unchecked(buf),
            tau: WireFormat::parse_unchecked(buf),
            d_tau: WireFormat::parse_unchecked(buf),
            pos: WireFormat::parse_unchecked(buf),
            vel: WireFormat::parse_unchecked(buf),
            acc: WireFormat::parse_unchecked(buf),
            fcn: WireFormat::parse_unchecked(buf),
            iod: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris for GLO
///
/// The ephemeris message returns a set of satellite orbit parameters that is
/// used to calculate GLO satellite position, velocity, and clock offset.
/// Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
/// immediate information (ephemeris parameters)" for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisGloDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: EphemerisCommonContentDepA,
    /// Relative deviation of predicted carrier frequency from nominal
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gamma")))]
    pub gamma: f64,
    /// Correction to the SV time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tau")))]
    pub tau: f64,
    /// Position of the SV at tb in PZ-90.02 coordinates system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pos")))]
    pub pos: [f64; 3],
    /// Velocity vector of the SV at tb in PZ-90.02 coordinates system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vel")))]
    pub vel: [f64; 3],
    /// Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    #[cfg_attr(feature = "serde", serde(rename(serialize = "acc")))]
    pub acc: [f64; 3],
}

impl ConcreteMessage for MsgEphemerisGloDepA {
    const MESSAGE_TYPE: u16 = 131;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_GLO_DEP_A";
}

impl SbpMessage for MsgEphemerisGloDepA {
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

impl TryFrom<Sbp> for MsgEphemerisGloDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisGloDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisGloDepA {
    const MIN_LEN: usize = <EphemerisCommonContentDepA as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.gamma)
            + WireFormat::len(&self.tau)
            + WireFormat::len(&self.pos)
            + WireFormat::len(&self.vel)
            + WireFormat::len(&self.acc)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.gamma, buf);
        WireFormat::write(&self.tau, buf);
        WireFormat::write(&self.pos, buf);
        WireFormat::write(&self.vel, buf);
        WireFormat::write(&self.acc, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisGloDepA {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            gamma: WireFormat::parse_unchecked(buf),
            tau: WireFormat::parse_unchecked(buf),
            pos: WireFormat::parse_unchecked(buf),
            vel: WireFormat::parse_unchecked(buf),
            acc: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris for GLO
///
/// The ephemeris message returns a set of satellite orbit parameters that is
/// used to calculate GLO satellite position, velocity, and clock offset.
/// Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
/// immediate information (ephemeris parameters)" for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisGloDepB {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: EphemerisCommonContentDepB,
    /// Relative deviation of predicted carrier frequency from nominal
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gamma")))]
    pub gamma: f64,
    /// Correction to the SV time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tau")))]
    pub tau: f64,
    /// Position of the SV at tb in PZ-90.02 coordinates system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pos")))]
    pub pos: [f64; 3],
    /// Velocity vector of the SV at tb in PZ-90.02 coordinates system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vel")))]
    pub vel: [f64; 3],
    /// Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    #[cfg_attr(feature = "serde", serde(rename(serialize = "acc")))]
    pub acc: [f64; 3],
}

impl ConcreteMessage for MsgEphemerisGloDepB {
    const MESSAGE_TYPE: u16 = 133;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_GLO_DEP_B";
}

impl SbpMessage for MsgEphemerisGloDepB {
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

impl TryFrom<Sbp> for MsgEphemerisGloDepB {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisGloDepB(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisGloDepB {
    const MIN_LEN: usize = <EphemerisCommonContentDepB as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.gamma)
            + WireFormat::len(&self.tau)
            + WireFormat::len(&self.pos)
            + WireFormat::len(&self.vel)
            + WireFormat::len(&self.acc)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.gamma, buf);
        WireFormat::write(&self.tau, buf);
        WireFormat::write(&self.pos, buf);
        WireFormat::write(&self.vel, buf);
        WireFormat::write(&self.acc, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisGloDepB {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            gamma: WireFormat::parse_unchecked(buf),
            tau: WireFormat::parse_unchecked(buf),
            pos: WireFormat::parse_unchecked(buf),
            vel: WireFormat::parse_unchecked(buf),
            acc: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris for GLO
///
/// The ephemeris message returns a set of satellite orbit parameters that is
/// used to calculate GLO satellite position, velocity, and clock offset.
/// Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
/// immediate information (ephemeris parameters)" for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisGloDepC {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: EphemerisCommonContentDepB,
    /// Relative deviation of predicted carrier frequency from nominal
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gamma")))]
    pub gamma: f64,
    /// Correction to the SV time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tau")))]
    pub tau: f64,
    /// Equipment delay between L1 and L2
    #[cfg_attr(feature = "serde", serde(rename(serialize = "d_tau")))]
    pub d_tau: f64,
    /// Position of the SV at tb in PZ-90.02 coordinates system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pos")))]
    pub pos: [f64; 3],
    /// Velocity vector of the SV at tb in PZ-90.02 coordinates system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vel")))]
    pub vel: [f64; 3],
    /// Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    #[cfg_attr(feature = "serde", serde(rename(serialize = "acc")))]
    pub acc: [f64; 3],
    /// Frequency slot. FCN+8 (that is \[1..14\]). 0 or 0xFF for invalid
    #[cfg_attr(feature = "serde", serde(rename(serialize = "fcn")))]
    pub fcn: u8,
}

impl ConcreteMessage for MsgEphemerisGloDepC {
    const MESSAGE_TYPE: u16 = 135;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_GLO_DEP_C";
}

impl SbpMessage for MsgEphemerisGloDepC {
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

impl TryFrom<Sbp> for MsgEphemerisGloDepC {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisGloDepC(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisGloDepC {
    const MIN_LEN: usize = <EphemerisCommonContentDepB as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.gamma)
            + WireFormat::len(&self.tau)
            + WireFormat::len(&self.d_tau)
            + WireFormat::len(&self.pos)
            + WireFormat::len(&self.vel)
            + WireFormat::len(&self.acc)
            + WireFormat::len(&self.fcn)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.gamma, buf);
        WireFormat::write(&self.tau, buf);
        WireFormat::write(&self.d_tau, buf);
        WireFormat::write(&self.pos, buf);
        WireFormat::write(&self.vel, buf);
        WireFormat::write(&self.acc, buf);
        WireFormat::write(&self.fcn, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisGloDepC {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            gamma: WireFormat::parse_unchecked(buf),
            tau: WireFormat::parse_unchecked(buf),
            d_tau: WireFormat::parse_unchecked(buf),
            pos: WireFormat::parse_unchecked(buf),
            vel: WireFormat::parse_unchecked(buf),
            acc: WireFormat::parse_unchecked(buf),
            fcn: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// This observation message has been deprecated in favor of ephemeris message
/// using floats for size reduction.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisGloDepD {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: EphemerisCommonContentDepB,
    /// Relative deviation of predicted carrier frequency from nominal
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gamma")))]
    pub gamma: f64,
    /// Correction to the SV time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tau")))]
    pub tau: f64,
    /// Equipment delay between L1 and L2
    #[cfg_attr(feature = "serde", serde(rename(serialize = "d_tau")))]
    pub d_tau: f64,
    /// Position of the SV at tb in PZ-90.02 coordinates system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pos")))]
    pub pos: [f64; 3],
    /// Velocity vector of the SV at tb in PZ-90.02 coordinates system
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vel")))]
    pub vel: [f64; 3],
    /// Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    #[cfg_attr(feature = "serde", serde(rename(serialize = "acc")))]
    pub acc: [f64; 3],
    /// Frequency slot. FCN+8 (that is \[1..14\]). 0 or 0xFF for invalid
    #[cfg_attr(feature = "serde", serde(rename(serialize = "fcn")))]
    pub fcn: u8,
    /// Issue of data. Equal to the 7 bits of the immediate data word t_b
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iod")))]
    pub iod: u8,
}

impl ConcreteMessage for MsgEphemerisGloDepD {
    const MESSAGE_TYPE: u16 = 136;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_GLO_DEP_D";
}

impl SbpMessage for MsgEphemerisGloDepD {
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

impl TryFrom<Sbp> for MsgEphemerisGloDepD {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisGloDepD(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisGloDepD {
    const MIN_LEN: usize = <EphemerisCommonContentDepB as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.gamma)
            + WireFormat::len(&self.tau)
            + WireFormat::len(&self.d_tau)
            + WireFormat::len(&self.pos)
            + WireFormat::len(&self.vel)
            + WireFormat::len(&self.acc)
            + WireFormat::len(&self.fcn)
            + WireFormat::len(&self.iod)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.gamma, buf);
        WireFormat::write(&self.tau, buf);
        WireFormat::write(&self.d_tau, buf);
        WireFormat::write(&self.pos, buf);
        WireFormat::write(&self.vel, buf);
        WireFormat::write(&self.acc, buf);
        WireFormat::write(&self.fcn, buf);
        WireFormat::write(&self.iod, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisGloDepD {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            gamma: WireFormat::parse_unchecked(buf),
            tau: WireFormat::parse_unchecked(buf),
            d_tau: WireFormat::parse_unchecked(buf),
            pos: WireFormat::parse_unchecked(buf),
            vel: WireFormat::parse_unchecked(buf),
            acc: WireFormat::parse_unchecked(buf),
            fcn: WireFormat::parse_unchecked(buf),
            iod: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris for GPS
///
/// The ephemeris message returns a set of satellite orbit parameters that is
/// used to calculate GPS satellite position, velocity, and clock offset.
/// Please see the Navstar GPS Space Segment/Navigation user interfaces (ICD-
/// GPS-200, Table 20-III) for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisGps {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: EphemerisCommonContent,
    /// Group delay differential between L1 and L2
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tgd")))]
    pub tgd: f32,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rs")))]
    pub c_rs: f32,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rc")))]
    pub c_rc: f32,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_uc")))]
    pub c_uc: f32,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_us")))]
    pub c_us: f32,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_ic")))]
    pub c_ic: f32,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_is")))]
    pub c_is: f32,
    /// Mean motion difference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dn")))]
    pub dn: f64,
    /// Mean anomaly at reference time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "m0")))]
    pub m0: f64,
    /// Eccentricity of satellite orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ecc")))]
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sqrta")))]
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omega0")))]
    pub omega0: f64,
    /// Rate of right ascension
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omegadot")))]
    pub omegadot: f64,
    /// Argument of perigee
    #[cfg_attr(feature = "serde", serde(rename(serialize = "w")))]
    pub w: f64,
    /// Inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc")))]
    pub inc: f64,
    /// Inclination first derivative
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc_dot")))]
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af0")))]
    pub af0: f32,
    /// Polynomial clock correction coefficient (clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af1")))]
    pub af1: f32,
    /// Polynomial clock correction coefficient (rate of clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af2")))]
    pub af2: f32,
    /// Clock reference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toc")))]
    pub toc: GpsTimeSec,
    /// Issue of ephemeris data
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iode")))]
    pub iode: u8,
    /// Issue of clock data
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iodc")))]
    pub iodc: u16,
}

impl ConcreteMessage for MsgEphemerisGps {
    const MESSAGE_TYPE: u16 = 138;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_GPS";
}

impl SbpMessage for MsgEphemerisGps {
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

impl TryFrom<Sbp> for MsgEphemerisGps {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisGps(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisGps {
    const MIN_LEN: usize = <EphemerisCommonContent as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <GpsTimeSec as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.tgd)
            + WireFormat::len(&self.c_rs)
            + WireFormat::len(&self.c_rc)
            + WireFormat::len(&self.c_uc)
            + WireFormat::len(&self.c_us)
            + WireFormat::len(&self.c_ic)
            + WireFormat::len(&self.c_is)
            + WireFormat::len(&self.dn)
            + WireFormat::len(&self.m0)
            + WireFormat::len(&self.ecc)
            + WireFormat::len(&self.sqrta)
            + WireFormat::len(&self.omega0)
            + WireFormat::len(&self.omegadot)
            + WireFormat::len(&self.w)
            + WireFormat::len(&self.inc)
            + WireFormat::len(&self.inc_dot)
            + WireFormat::len(&self.af0)
            + WireFormat::len(&self.af1)
            + WireFormat::len(&self.af2)
            + WireFormat::len(&self.toc)
            + WireFormat::len(&self.iode)
            + WireFormat::len(&self.iodc)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.tgd, buf);
        WireFormat::write(&self.c_rs, buf);
        WireFormat::write(&self.c_rc, buf);
        WireFormat::write(&self.c_uc, buf);
        WireFormat::write(&self.c_us, buf);
        WireFormat::write(&self.c_ic, buf);
        WireFormat::write(&self.c_is, buf);
        WireFormat::write(&self.dn, buf);
        WireFormat::write(&self.m0, buf);
        WireFormat::write(&self.ecc, buf);
        WireFormat::write(&self.sqrta, buf);
        WireFormat::write(&self.omega0, buf);
        WireFormat::write(&self.omegadot, buf);
        WireFormat::write(&self.w, buf);
        WireFormat::write(&self.inc, buf);
        WireFormat::write(&self.inc_dot, buf);
        WireFormat::write(&self.af0, buf);
        WireFormat::write(&self.af1, buf);
        WireFormat::write(&self.af2, buf);
        WireFormat::write(&self.toc, buf);
        WireFormat::write(&self.iode, buf);
        WireFormat::write(&self.iodc, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisGps {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            tgd: WireFormat::parse_unchecked(buf),
            c_rs: WireFormat::parse_unchecked(buf),
            c_rc: WireFormat::parse_unchecked(buf),
            c_uc: WireFormat::parse_unchecked(buf),
            c_us: WireFormat::parse_unchecked(buf),
            c_ic: WireFormat::parse_unchecked(buf),
            c_is: WireFormat::parse_unchecked(buf),
            dn: WireFormat::parse_unchecked(buf),
            m0: WireFormat::parse_unchecked(buf),
            ecc: WireFormat::parse_unchecked(buf),
            sqrta: WireFormat::parse_unchecked(buf),
            omega0: WireFormat::parse_unchecked(buf),
            omegadot: WireFormat::parse_unchecked(buf),
            w: WireFormat::parse_unchecked(buf),
            inc: WireFormat::parse_unchecked(buf),
            inc_dot: WireFormat::parse_unchecked(buf),
            af0: WireFormat::parse_unchecked(buf),
            af1: WireFormat::parse_unchecked(buf),
            af2: WireFormat::parse_unchecked(buf),
            toc: WireFormat::parse_unchecked(buf),
            iode: WireFormat::parse_unchecked(buf),
            iodc: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris for GPS
///
/// The ephemeris message returns a set of satellite orbit parameters that is
/// used to calculate GPS satellite position, velocity, and clock offset.
/// Please see the Navstar GPS Space Segment/Navigation user interfaces (ICD-
/// GPS-200, Table 20-III) for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisGpsDepE {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: EphemerisCommonContentDepA,
    /// Group delay differential between L1 and L2
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tgd")))]
    pub tgd: f64,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rs")))]
    pub c_rs: f64,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rc")))]
    pub c_rc: f64,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_uc")))]
    pub c_uc: f64,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_us")))]
    pub c_us: f64,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_ic")))]
    pub c_ic: f64,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_is")))]
    pub c_is: f64,
    /// Mean motion difference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dn")))]
    pub dn: f64,
    /// Mean anomaly at reference time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "m0")))]
    pub m0: f64,
    /// Eccentricity of satellite orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ecc")))]
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sqrta")))]
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omega0")))]
    pub omega0: f64,
    /// Rate of right ascension
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omegadot")))]
    pub omegadot: f64,
    /// Argument of perigee
    #[cfg_attr(feature = "serde", serde(rename(serialize = "w")))]
    pub w: f64,
    /// Inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc")))]
    pub inc: f64,
    /// Inclination first derivative
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc_dot")))]
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af0")))]
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af1")))]
    pub af1: f64,
    /// Polynomial clock correction coefficient (rate of clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af2")))]
    pub af2: f64,
    /// Clock reference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toc")))]
    pub toc: GpsTimeDep,
    /// Issue of ephemeris data
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iode")))]
    pub iode: u8,
    /// Issue of clock data
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iodc")))]
    pub iodc: u16,
}

impl ConcreteMessage for MsgEphemerisGpsDepE {
    const MESSAGE_TYPE: u16 = 129;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_GPS_DEP_E";
}

impl SbpMessage for MsgEphemerisGpsDepE {
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

impl TryFrom<Sbp> for MsgEphemerisGpsDepE {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisGpsDepE(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisGpsDepE {
    const MIN_LEN: usize = <EphemerisCommonContentDepA as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <GpsTimeDep as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.tgd)
            + WireFormat::len(&self.c_rs)
            + WireFormat::len(&self.c_rc)
            + WireFormat::len(&self.c_uc)
            + WireFormat::len(&self.c_us)
            + WireFormat::len(&self.c_ic)
            + WireFormat::len(&self.c_is)
            + WireFormat::len(&self.dn)
            + WireFormat::len(&self.m0)
            + WireFormat::len(&self.ecc)
            + WireFormat::len(&self.sqrta)
            + WireFormat::len(&self.omega0)
            + WireFormat::len(&self.omegadot)
            + WireFormat::len(&self.w)
            + WireFormat::len(&self.inc)
            + WireFormat::len(&self.inc_dot)
            + WireFormat::len(&self.af0)
            + WireFormat::len(&self.af1)
            + WireFormat::len(&self.af2)
            + WireFormat::len(&self.toc)
            + WireFormat::len(&self.iode)
            + WireFormat::len(&self.iodc)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.tgd, buf);
        WireFormat::write(&self.c_rs, buf);
        WireFormat::write(&self.c_rc, buf);
        WireFormat::write(&self.c_uc, buf);
        WireFormat::write(&self.c_us, buf);
        WireFormat::write(&self.c_ic, buf);
        WireFormat::write(&self.c_is, buf);
        WireFormat::write(&self.dn, buf);
        WireFormat::write(&self.m0, buf);
        WireFormat::write(&self.ecc, buf);
        WireFormat::write(&self.sqrta, buf);
        WireFormat::write(&self.omega0, buf);
        WireFormat::write(&self.omegadot, buf);
        WireFormat::write(&self.w, buf);
        WireFormat::write(&self.inc, buf);
        WireFormat::write(&self.inc_dot, buf);
        WireFormat::write(&self.af0, buf);
        WireFormat::write(&self.af1, buf);
        WireFormat::write(&self.af2, buf);
        WireFormat::write(&self.toc, buf);
        WireFormat::write(&self.iode, buf);
        WireFormat::write(&self.iodc, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisGpsDepE {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            tgd: WireFormat::parse_unchecked(buf),
            c_rs: WireFormat::parse_unchecked(buf),
            c_rc: WireFormat::parse_unchecked(buf),
            c_uc: WireFormat::parse_unchecked(buf),
            c_us: WireFormat::parse_unchecked(buf),
            c_ic: WireFormat::parse_unchecked(buf),
            c_is: WireFormat::parse_unchecked(buf),
            dn: WireFormat::parse_unchecked(buf),
            m0: WireFormat::parse_unchecked(buf),
            ecc: WireFormat::parse_unchecked(buf),
            sqrta: WireFormat::parse_unchecked(buf),
            omega0: WireFormat::parse_unchecked(buf),
            omegadot: WireFormat::parse_unchecked(buf),
            w: WireFormat::parse_unchecked(buf),
            inc: WireFormat::parse_unchecked(buf),
            inc_dot: WireFormat::parse_unchecked(buf),
            af0: WireFormat::parse_unchecked(buf),
            af1: WireFormat::parse_unchecked(buf),
            af2: WireFormat::parse_unchecked(buf),
            toc: WireFormat::parse_unchecked(buf),
            iode: WireFormat::parse_unchecked(buf),
            iodc: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// This observation message has been deprecated in favor of ephemeris message
/// using floats for size reduction.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisGpsDepF {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: EphemerisCommonContentDepB,
    /// Group delay differential between L1 and L2
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tgd")))]
    pub tgd: f64,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rs")))]
    pub c_rs: f64,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rc")))]
    pub c_rc: f64,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_uc")))]
    pub c_uc: f64,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_us")))]
    pub c_us: f64,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_ic")))]
    pub c_ic: f64,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_is")))]
    pub c_is: f64,
    /// Mean motion difference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dn")))]
    pub dn: f64,
    /// Mean anomaly at reference time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "m0")))]
    pub m0: f64,
    /// Eccentricity of satellite orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ecc")))]
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sqrta")))]
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omega0")))]
    pub omega0: f64,
    /// Rate of right ascension
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omegadot")))]
    pub omegadot: f64,
    /// Argument of perigee
    #[cfg_attr(feature = "serde", serde(rename(serialize = "w")))]
    pub w: f64,
    /// Inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc")))]
    pub inc: f64,
    /// Inclination first derivative
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc_dot")))]
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af0")))]
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af1")))]
    pub af1: f64,
    /// Polynomial clock correction coefficient (rate of clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af2")))]
    pub af2: f64,
    /// Clock reference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toc")))]
    pub toc: GpsTimeSec,
    /// Issue of ephemeris data
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iode")))]
    pub iode: u8,
    /// Issue of clock data
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iodc")))]
    pub iodc: u16,
}

impl ConcreteMessage for MsgEphemerisGpsDepF {
    const MESSAGE_TYPE: u16 = 134;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_GPS_DEP_F";
}

impl SbpMessage for MsgEphemerisGpsDepF {
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

impl TryFrom<Sbp> for MsgEphemerisGpsDepF {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisGpsDepF(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisGpsDepF {
    const MIN_LEN: usize = <EphemerisCommonContentDepB as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <GpsTimeSec as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.tgd)
            + WireFormat::len(&self.c_rs)
            + WireFormat::len(&self.c_rc)
            + WireFormat::len(&self.c_uc)
            + WireFormat::len(&self.c_us)
            + WireFormat::len(&self.c_ic)
            + WireFormat::len(&self.c_is)
            + WireFormat::len(&self.dn)
            + WireFormat::len(&self.m0)
            + WireFormat::len(&self.ecc)
            + WireFormat::len(&self.sqrta)
            + WireFormat::len(&self.omega0)
            + WireFormat::len(&self.omegadot)
            + WireFormat::len(&self.w)
            + WireFormat::len(&self.inc)
            + WireFormat::len(&self.inc_dot)
            + WireFormat::len(&self.af0)
            + WireFormat::len(&self.af1)
            + WireFormat::len(&self.af2)
            + WireFormat::len(&self.toc)
            + WireFormat::len(&self.iode)
            + WireFormat::len(&self.iodc)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.tgd, buf);
        WireFormat::write(&self.c_rs, buf);
        WireFormat::write(&self.c_rc, buf);
        WireFormat::write(&self.c_uc, buf);
        WireFormat::write(&self.c_us, buf);
        WireFormat::write(&self.c_ic, buf);
        WireFormat::write(&self.c_is, buf);
        WireFormat::write(&self.dn, buf);
        WireFormat::write(&self.m0, buf);
        WireFormat::write(&self.ecc, buf);
        WireFormat::write(&self.sqrta, buf);
        WireFormat::write(&self.omega0, buf);
        WireFormat::write(&self.omegadot, buf);
        WireFormat::write(&self.w, buf);
        WireFormat::write(&self.inc, buf);
        WireFormat::write(&self.inc_dot, buf);
        WireFormat::write(&self.af0, buf);
        WireFormat::write(&self.af1, buf);
        WireFormat::write(&self.af2, buf);
        WireFormat::write(&self.toc, buf);
        WireFormat::write(&self.iode, buf);
        WireFormat::write(&self.iodc, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisGpsDepF {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            tgd: WireFormat::parse_unchecked(buf),
            c_rs: WireFormat::parse_unchecked(buf),
            c_rc: WireFormat::parse_unchecked(buf),
            c_uc: WireFormat::parse_unchecked(buf),
            c_us: WireFormat::parse_unchecked(buf),
            c_ic: WireFormat::parse_unchecked(buf),
            c_is: WireFormat::parse_unchecked(buf),
            dn: WireFormat::parse_unchecked(buf),
            m0: WireFormat::parse_unchecked(buf),
            ecc: WireFormat::parse_unchecked(buf),
            sqrta: WireFormat::parse_unchecked(buf),
            omega0: WireFormat::parse_unchecked(buf),
            omegadot: WireFormat::parse_unchecked(buf),
            w: WireFormat::parse_unchecked(buf),
            inc: WireFormat::parse_unchecked(buf),
            inc_dot: WireFormat::parse_unchecked(buf),
            af0: WireFormat::parse_unchecked(buf),
            af1: WireFormat::parse_unchecked(buf),
            af2: WireFormat::parse_unchecked(buf),
            toc: WireFormat::parse_unchecked(buf),
            iode: WireFormat::parse_unchecked(buf),
            iodc: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris for QZSS
///
/// The ephemeris message returns a set of satellite orbit parameters that is
/// used to calculate QZSS satellite position, velocity, and clock offset.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisQzss {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: EphemerisCommonContent,
    /// Group delay differential between L1 and L2
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tgd")))]
    pub tgd: f32,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rs")))]
    pub c_rs: f32,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_rc")))]
    pub c_rc: f32,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_uc")))]
    pub c_uc: f32,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_us")))]
    pub c_us: f32,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_ic")))]
    pub c_ic: f32,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "c_is")))]
    pub c_is: f32,
    /// Mean motion difference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dn")))]
    pub dn: f64,
    /// Mean anomaly at reference time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "m0")))]
    pub m0: f64,
    /// Eccentricity of satellite orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "ecc")))]
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sqrta")))]
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omega0")))]
    pub omega0: f64,
    /// Rate of right ascension
    #[cfg_attr(feature = "serde", serde(rename(serialize = "omegadot")))]
    pub omegadot: f64,
    /// Argument of perigee
    #[cfg_attr(feature = "serde", serde(rename(serialize = "w")))]
    pub w: f64,
    /// Inclination
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc")))]
    pub inc: f64,
    /// Inclination first derivative
    #[cfg_attr(feature = "serde", serde(rename(serialize = "inc_dot")))]
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af0")))]
    pub af0: f32,
    /// Polynomial clock correction coefficient (clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af1")))]
    pub af1: f32,
    /// Polynomial clock correction coefficient (rate of clock drift)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "af2")))]
    pub af2: f32,
    /// Clock reference
    #[cfg_attr(feature = "serde", serde(rename(serialize = "toc")))]
    pub toc: GpsTimeSec,
    /// Issue of ephemeris data
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iode")))]
    pub iode: u8,
    /// Issue of clock data
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iodc")))]
    pub iodc: u16,
}

impl ConcreteMessage for MsgEphemerisQzss {
    const MESSAGE_TYPE: u16 = 142;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_QZSS";
}

impl SbpMessage for MsgEphemerisQzss {
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

impl TryFrom<Sbp> for MsgEphemerisQzss {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisQzss(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisQzss {
    const MIN_LEN: usize = <EphemerisCommonContent as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <GpsTimeSec as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.tgd)
            + WireFormat::len(&self.c_rs)
            + WireFormat::len(&self.c_rc)
            + WireFormat::len(&self.c_uc)
            + WireFormat::len(&self.c_us)
            + WireFormat::len(&self.c_ic)
            + WireFormat::len(&self.c_is)
            + WireFormat::len(&self.dn)
            + WireFormat::len(&self.m0)
            + WireFormat::len(&self.ecc)
            + WireFormat::len(&self.sqrta)
            + WireFormat::len(&self.omega0)
            + WireFormat::len(&self.omegadot)
            + WireFormat::len(&self.w)
            + WireFormat::len(&self.inc)
            + WireFormat::len(&self.inc_dot)
            + WireFormat::len(&self.af0)
            + WireFormat::len(&self.af1)
            + WireFormat::len(&self.af2)
            + WireFormat::len(&self.toc)
            + WireFormat::len(&self.iode)
            + WireFormat::len(&self.iodc)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.tgd, buf);
        WireFormat::write(&self.c_rs, buf);
        WireFormat::write(&self.c_rc, buf);
        WireFormat::write(&self.c_uc, buf);
        WireFormat::write(&self.c_us, buf);
        WireFormat::write(&self.c_ic, buf);
        WireFormat::write(&self.c_is, buf);
        WireFormat::write(&self.dn, buf);
        WireFormat::write(&self.m0, buf);
        WireFormat::write(&self.ecc, buf);
        WireFormat::write(&self.sqrta, buf);
        WireFormat::write(&self.omega0, buf);
        WireFormat::write(&self.omegadot, buf);
        WireFormat::write(&self.w, buf);
        WireFormat::write(&self.inc, buf);
        WireFormat::write(&self.inc_dot, buf);
        WireFormat::write(&self.af0, buf);
        WireFormat::write(&self.af1, buf);
        WireFormat::write(&self.af2, buf);
        WireFormat::write(&self.toc, buf);
        WireFormat::write(&self.iode, buf);
        WireFormat::write(&self.iodc, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisQzss {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            tgd: WireFormat::parse_unchecked(buf),
            c_rs: WireFormat::parse_unchecked(buf),
            c_rc: WireFormat::parse_unchecked(buf),
            c_uc: WireFormat::parse_unchecked(buf),
            c_us: WireFormat::parse_unchecked(buf),
            c_ic: WireFormat::parse_unchecked(buf),
            c_is: WireFormat::parse_unchecked(buf),
            dn: WireFormat::parse_unchecked(buf),
            m0: WireFormat::parse_unchecked(buf),
            ecc: WireFormat::parse_unchecked(buf),
            sqrta: WireFormat::parse_unchecked(buf),
            omega0: WireFormat::parse_unchecked(buf),
            omegadot: WireFormat::parse_unchecked(buf),
            w: WireFormat::parse_unchecked(buf),
            inc: WireFormat::parse_unchecked(buf),
            inc_dot: WireFormat::parse_unchecked(buf),
            af0: WireFormat::parse_unchecked(buf),
            af1: WireFormat::parse_unchecked(buf),
            af2: WireFormat::parse_unchecked(buf),
            toc: WireFormat::parse_unchecked(buf),
            iode: WireFormat::parse_unchecked(buf),
            iodc: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris for SBAS
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisSbas {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: EphemerisCommonContent,
    /// Position of the GEO at time toe
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pos")))]
    pub pos: [f64; 3],
    /// Velocity of the GEO at time toe
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vel")))]
    pub vel: [f32; 3],
    /// Acceleration of the GEO at time toe
    #[cfg_attr(feature = "serde", serde(rename(serialize = "acc")))]
    pub acc: [f32; 3],
    /// Time offset of the GEO clock w.r.t. SBAS Network Time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "a_gf0")))]
    pub a_gf0: f32,
    /// Drift of the GEO clock w.r.t. SBAS Network Time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "a_gf1")))]
    pub a_gf1: f32,
}

impl ConcreteMessage for MsgEphemerisSbas {
    const MESSAGE_TYPE: u16 = 140;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_SBAS";
}

impl SbpMessage for MsgEphemerisSbas {
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

impl TryFrom<Sbp> for MsgEphemerisSbas {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisSbas(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisSbas {
    const MIN_LEN: usize = <EphemerisCommonContent as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <[f32; 3] as WireFormat>::MIN_LEN
        + <[f32; 3] as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.pos)
            + WireFormat::len(&self.vel)
            + WireFormat::len(&self.acc)
            + WireFormat::len(&self.a_gf0)
            + WireFormat::len(&self.a_gf1)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.pos, buf);
        WireFormat::write(&self.vel, buf);
        WireFormat::write(&self.acc, buf);
        WireFormat::write(&self.a_gf0, buf);
        WireFormat::write(&self.a_gf1, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisSbas {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            pos: WireFormat::parse_unchecked(buf),
            vel: WireFormat::parse_unchecked(buf),
            acc: WireFormat::parse_unchecked(buf),
            a_gf0: WireFormat::parse_unchecked(buf),
            a_gf1: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite broadcast ephemeris for SBAS
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisSbasDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: EphemerisCommonContentDepA,
    /// Position of the GEO at time toe
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pos")))]
    pub pos: [f64; 3],
    /// Velocity of the GEO at time toe
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vel")))]
    pub vel: [f64; 3],
    /// Acceleration of the GEO at time toe
    #[cfg_attr(feature = "serde", serde(rename(serialize = "acc")))]
    pub acc: [f64; 3],
    /// Time offset of the GEO clock w.r.t. SBAS Network Time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "a_gf0")))]
    pub a_gf0: f64,
    /// Drift of the GEO clock w.r.t. SBAS Network Time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "a_gf1")))]
    pub a_gf1: f64,
}

impl ConcreteMessage for MsgEphemerisSbasDepA {
    const MESSAGE_TYPE: u16 = 130;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_SBAS_DEP_A";
}

impl SbpMessage for MsgEphemerisSbasDepA {
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

impl TryFrom<Sbp> for MsgEphemerisSbasDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisSbasDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisSbasDepA {
    const MIN_LEN: usize = <EphemerisCommonContentDepA as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.pos)
            + WireFormat::len(&self.vel)
            + WireFormat::len(&self.acc)
            + WireFormat::len(&self.a_gf0)
            + WireFormat::len(&self.a_gf1)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.pos, buf);
        WireFormat::write(&self.vel, buf);
        WireFormat::write(&self.acc, buf);
        WireFormat::write(&self.a_gf0, buf);
        WireFormat::write(&self.a_gf1, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisSbasDepA {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            pos: WireFormat::parse_unchecked(buf),
            vel: WireFormat::parse_unchecked(buf),
            acc: WireFormat::parse_unchecked(buf),
            a_gf0: WireFormat::parse_unchecked(buf),
            a_gf1: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// This observation message has been deprecated in favor of ephemeris message
/// using floats for size reduction.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgEphemerisSbasDepB {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    #[cfg_attr(feature = "serde", serde(rename(serialize = "common")))]
    pub common: EphemerisCommonContentDepB,
    /// Position of the GEO at time toe
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pos")))]
    pub pos: [f64; 3],
    /// Velocity of the GEO at time toe
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vel")))]
    pub vel: [f64; 3],
    /// Acceleration of the GEO at time toe
    #[cfg_attr(feature = "serde", serde(rename(serialize = "acc")))]
    pub acc: [f64; 3],
    /// Time offset of the GEO clock w.r.t. SBAS Network Time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "a_gf0")))]
    pub a_gf0: f64,
    /// Drift of the GEO clock w.r.t. SBAS Network Time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "a_gf1")))]
    pub a_gf1: f64,
}

impl ConcreteMessage for MsgEphemerisSbasDepB {
    const MESSAGE_TYPE: u16 = 132;
    const MESSAGE_NAME: &'static str = "MSG_EPHEMERIS_SBAS_DEP_B";
}

impl SbpMessage for MsgEphemerisSbasDepB {
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

impl TryFrom<Sbp> for MsgEphemerisSbasDepB {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgEphemerisSbasDepB(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgEphemerisSbasDepB {
    const MIN_LEN: usize = <EphemerisCommonContentDepB as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <[f64; 3] as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.common)
            + WireFormat::len(&self.pos)
            + WireFormat::len(&self.vel)
            + WireFormat::len(&self.acc)
            + WireFormat::len(&self.a_gf0)
            + WireFormat::len(&self.a_gf1)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.common, buf);
        WireFormat::write(&self.pos, buf);
        WireFormat::write(&self.vel, buf);
        WireFormat::write(&self.acc, buf);
        WireFormat::write(&self.a_gf0, buf);
        WireFormat::write(&self.a_gf1, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgEphemerisSbasDepB {
            sender_id: None,
            common: WireFormat::parse_unchecked(buf),
            pos: WireFormat::parse_unchecked(buf),
            vel: WireFormat::parse_unchecked(buf),
            acc: WireFormat::parse_unchecked(buf),
            a_gf0: WireFormat::parse_unchecked(buf),
            a_gf1: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GLONASS L1/L2 Code-Phase biases
///
/// The GLONASS L1/L2 Code-Phase biases allows to perform GPS+GLONASS integer
/// ambiguity resolution for baselines with mixed receiver types (e.g.
/// receiver of different manufacturers).
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgGloBiases {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GLONASS FDMA signals mask
    #[cfg_attr(feature = "serde", serde(rename(serialize = "mask")))]
    pub mask: u8,
    /// GLONASS L1 C/A Code-Phase Bias
    #[cfg_attr(feature = "serde", serde(rename(serialize = "l1ca_bias")))]
    pub l1ca_bias: i16,
    /// GLONASS L1 P Code-Phase Bias
    #[cfg_attr(feature = "serde", serde(rename(serialize = "l1p_bias")))]
    pub l1p_bias: i16,
    /// GLONASS L2 C/A Code-Phase Bias
    #[cfg_attr(feature = "serde", serde(rename(serialize = "l2ca_bias")))]
    pub l2ca_bias: i16,
    /// GLONASS L2 P Code-Phase Bias
    #[cfg_attr(feature = "serde", serde(rename(serialize = "l2p_bias")))]
    pub l2p_bias: i16,
}

impl ConcreteMessage for MsgGloBiases {
    const MESSAGE_TYPE: u16 = 117;
    const MESSAGE_NAME: &'static str = "MSG_GLO_BIASES";
}

impl SbpMessage for MsgGloBiases {
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

impl TryFrom<Sbp> for MsgGloBiases {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgGloBiases(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgGloBiases {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.mask)
            + WireFormat::len(&self.l1ca_bias)
            + WireFormat::len(&self.l1p_bias)
            + WireFormat::len(&self.l2ca_bias)
            + WireFormat::len(&self.l2p_bias)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.mask, buf);
        WireFormat::write(&self.l1ca_bias, buf);
        WireFormat::write(&self.l1p_bias, buf);
        WireFormat::write(&self.l2ca_bias, buf);
        WireFormat::write(&self.l2p_bias, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgGloBiases {
            sender_id: None,
            mask: WireFormat::parse_unchecked(buf),
            l1ca_bias: WireFormat::parse_unchecked(buf),
            l1p_bias: WireFormat::parse_unchecked(buf),
            l2ca_bias: WireFormat::parse_unchecked(buf),
            l2p_bias: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GNSS capabilities
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgGnssCapb {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Navigation Message Correction Table Validity Time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "t_nmct")))]
    pub t_nmct: GpsTimeSec,
    /// GNSS capabilities masks
    #[cfg_attr(feature = "serde", serde(rename(serialize = "gc")))]
    pub gc: GnssCapb,
}

impl ConcreteMessage for MsgGnssCapb {
    const MESSAGE_TYPE: u16 = 150;
    const MESSAGE_NAME: &'static str = "MSG_GNSS_CAPB";
}

impl SbpMessage for MsgGnssCapb {
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

impl TryFrom<Sbp> for MsgGnssCapb {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgGnssCapb(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgGnssCapb {
    const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN + <GnssCapb as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.t_nmct) + WireFormat::len(&self.gc)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.t_nmct, buf);
        WireFormat::write(&self.gc, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgGnssCapb {
            sender_id: None,
            t_nmct: WireFormat::parse_unchecked(buf),
            gc: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Group Delay
///
/// Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgGroupDelay {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Data Predict Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "t_op")))]
    pub t_op: GpsTimeSec,
    /// GNSS signal identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// bit-field indicating validity of the values, LSB indicating tgd validity
    /// etc. 1 = value is valid, 0 = value is not valid.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "valid")))]
    pub valid: u8,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tgd")))]
    pub tgd: i16,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "isc_l1ca")))]
    pub isc_l1ca: i16,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "isc_l2c")))]
    pub isc_l2c: i16,
}

impl ConcreteMessage for MsgGroupDelay {
    const MESSAGE_TYPE: u16 = 148;
    const MESSAGE_NAME: &'static str = "MSG_GROUP_DELAY";
}

impl SbpMessage for MsgGroupDelay {
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

impl TryFrom<Sbp> for MsgGroupDelay {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgGroupDelay(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgGroupDelay {
    const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN
        + <GnssSignal as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.t_op)
            + WireFormat::len(&self.sid)
            + WireFormat::len(&self.valid)
            + WireFormat::len(&self.tgd)
            + WireFormat::len(&self.isc_l1ca)
            + WireFormat::len(&self.isc_l2c)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.t_op, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.valid, buf);
        WireFormat::write(&self.tgd, buf);
        WireFormat::write(&self.isc_l1ca, buf);
        WireFormat::write(&self.isc_l2c, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgGroupDelay {
            sender_id: None,
            t_op: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            valid: WireFormat::parse_unchecked(buf),
            tgd: WireFormat::parse_unchecked(buf),
            isc_l1ca: WireFormat::parse_unchecked(buf),
            isc_l2c: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Group Delay
///
/// Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgGroupDelayDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Data Predict Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "t_op")))]
    pub t_op: GpsTimeDep,
    /// Satellite number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "prn")))]
    pub prn: u8,
    /// bit-field indicating validity of the values, LSB indicating tgd validity
    /// etc. 1 = value is valid, 0 = value is not valid.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "valid")))]
    pub valid: u8,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tgd")))]
    pub tgd: i16,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "isc_l1ca")))]
    pub isc_l1ca: i16,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "isc_l2c")))]
    pub isc_l2c: i16,
}

impl ConcreteMessage for MsgGroupDelayDepA {
    const MESSAGE_TYPE: u16 = 146;
    const MESSAGE_NAME: &'static str = "MSG_GROUP_DELAY_DEP_A";
}

impl SbpMessage for MsgGroupDelayDepA {
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

impl TryFrom<Sbp> for MsgGroupDelayDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgGroupDelayDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgGroupDelayDepA {
    const MIN_LEN: usize = <GpsTimeDep as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.t_op)
            + WireFormat::len(&self.prn)
            + WireFormat::len(&self.valid)
            + WireFormat::len(&self.tgd)
            + WireFormat::len(&self.isc_l1ca)
            + WireFormat::len(&self.isc_l2c)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.t_op, buf);
        WireFormat::write(&self.prn, buf);
        WireFormat::write(&self.valid, buf);
        WireFormat::write(&self.tgd, buf);
        WireFormat::write(&self.isc_l1ca, buf);
        WireFormat::write(&self.isc_l2c, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgGroupDelayDepA {
            sender_id: None,
            t_op: WireFormat::parse_unchecked(buf),
            prn: WireFormat::parse_unchecked(buf),
            valid: WireFormat::parse_unchecked(buf),
            tgd: WireFormat::parse_unchecked(buf),
            isc_l1ca: WireFormat::parse_unchecked(buf),
            isc_l2c: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Group Delay
///
/// Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgGroupDelayDepB {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Data Predict Time of Week
    #[cfg_attr(feature = "serde", serde(rename(serialize = "t_op")))]
    pub t_op: GpsTimeSec,
    /// GNSS signal identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignalDep,
    /// bit-field indicating validity of the values, LSB indicating tgd validity
    /// etc. 1 = value is valid, 0 = value is not valid.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "valid")))]
    pub valid: u8,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tgd")))]
    pub tgd: i16,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "isc_l1ca")))]
    pub isc_l1ca: i16,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "isc_l2c")))]
    pub isc_l2c: i16,
}

impl ConcreteMessage for MsgGroupDelayDepB {
    const MESSAGE_TYPE: u16 = 147;
    const MESSAGE_NAME: &'static str = "MSG_GROUP_DELAY_DEP_B";
}

impl SbpMessage for MsgGroupDelayDepB {
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

impl TryFrom<Sbp> for MsgGroupDelayDepB {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgGroupDelayDepB(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgGroupDelayDepB {
    const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN
        + <GnssSignalDep as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN
        + <i16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.t_op)
            + WireFormat::len(&self.sid)
            + WireFormat::len(&self.valid)
            + WireFormat::len(&self.tgd)
            + WireFormat::len(&self.isc_l1ca)
            + WireFormat::len(&self.isc_l2c)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.t_op, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.valid, buf);
        WireFormat::write(&self.tgd, buf);
        WireFormat::write(&self.isc_l1ca, buf);
        WireFormat::write(&self.isc_l2c, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgGroupDelayDepB {
            sender_id: None,
            t_op: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            valid: WireFormat::parse_unchecked(buf),
            tgd: WireFormat::parse_unchecked(buf),
            isc_l1ca: WireFormat::parse_unchecked(buf),
            isc_l2c: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Iono corrections
///
/// The ionospheric parameters which allow the "L1 only" or "L2 only" user to
/// utilize the ionospheric model for computation of the ionospheric delay.
/// Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgIono {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Navigation Message Correction Table Validity Time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "t_nmct")))]
    pub t_nmct: GpsTimeSec,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "a0")))]
    pub a0: f64,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "a1")))]
    pub a1: f64,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "a2")))]
    pub a2: f64,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "a3")))]
    pub a3: f64,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "b0")))]
    pub b0: f64,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "b1")))]
    pub b1: f64,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "b2")))]
    pub b2: f64,
    #[cfg_attr(feature = "serde", serde(rename(serialize = "b3")))]
    pub b3: f64,
}

impl ConcreteMessage for MsgIono {
    const MESSAGE_TYPE: u16 = 144;
    const MESSAGE_NAME: &'static str = "MSG_IONO";
}

impl SbpMessage for MsgIono {
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

impl TryFrom<Sbp> for MsgIono {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgIono(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgIono {
    const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN
        + <f64 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.t_nmct)
            + WireFormat::len(&self.a0)
            + WireFormat::len(&self.a1)
            + WireFormat::len(&self.a2)
            + WireFormat::len(&self.a3)
            + WireFormat::len(&self.b0)
            + WireFormat::len(&self.b1)
            + WireFormat::len(&self.b2)
            + WireFormat::len(&self.b3)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.t_nmct, buf);
        WireFormat::write(&self.a0, buf);
        WireFormat::write(&self.a1, buf);
        WireFormat::write(&self.a2, buf);
        WireFormat::write(&self.a3, buf);
        WireFormat::write(&self.b0, buf);
        WireFormat::write(&self.b1, buf);
        WireFormat::write(&self.b2, buf);
        WireFormat::write(&self.b3, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgIono {
            sender_id: None,
            t_nmct: WireFormat::parse_unchecked(buf),
            a0: WireFormat::parse_unchecked(buf),
            a1: WireFormat::parse_unchecked(buf),
            a2: WireFormat::parse_unchecked(buf),
            a3: WireFormat::parse_unchecked(buf),
            b0: WireFormat::parse_unchecked(buf),
            b1: WireFormat::parse_unchecked(buf),
            b2: WireFormat::parse_unchecked(buf),
            b3: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GPS satellite observations
///
/// The GPS observations message reports all the raw pseudorange and carrier
/// phase observations for the satellites being tracked by the device. Carrier
/// phase observation here is represented as a 40-bit fixed point number with
/// Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of fractional
/// cycles). The observations are be interoperable with 3rd party receivers
/// and conform with typical RTCMv3 GNSS observations.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgObs {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a GPS observation message
    #[cfg_attr(feature = "serde", serde(rename(serialize = "header")))]
    pub header: ObservationHeader,
    /// Pseudorange and carrier phase observation for a satellite being tracked.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "obs")))]
    pub obs: Vec<PackedObsContent>,
}

impl ConcreteMessage for MsgObs {
    const MESSAGE_TYPE: u16 = 74;
    const MESSAGE_NAME: &'static str = "MSG_OBS";
}

impl SbpMessage for MsgObs {
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
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.header.t.tow as f64) / 1000.0;
        let wn: i16 = match self.header.t.wn.try_into() {
            Ok(wn) => wn,
            Err(e) => return Some(Err(e.into())),
        };
        let gps_time = match time::GpsTime::new(wn, tow_s) {
            Ok(gps_time) => gps_time,
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Base(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgObs {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgObs(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgObs {
    const MIN_LEN: usize =
        <ObservationHeader as WireFormat>::MIN_LEN + <Vec<PackedObsContent> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.header) + WireFormat::len(&self.obs)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.header, buf);
        WireFormat::write(&self.obs, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgObs {
            sender_id: None,
            header: WireFormat::parse_unchecked(buf),
            obs: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgObsDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a GPS observation message
    #[cfg_attr(feature = "serde", serde(rename(serialize = "header")))]
    pub header: ObservationHeaderDep,
    /// Pseudorange and carrier phase observation for a satellite being tracked.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "obs")))]
    pub obs: Vec<PackedObsContentDepA>,
}

impl ConcreteMessage for MsgObsDepA {
    const MESSAGE_TYPE: u16 = 69;
    const MESSAGE_NAME: &'static str = "MSG_OBS_DEP_A";
}

impl SbpMessage for MsgObsDepA {
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
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.header.t.tow as f64) / 1000.0;
        let wn: i16 = match self.header.t.wn.try_into() {
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

impl TryFrom<Sbp> for MsgObsDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgObsDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgObsDepA {
    const MIN_LEN: usize = <ObservationHeaderDep as WireFormat>::MIN_LEN
        + <Vec<PackedObsContentDepA> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.header) + WireFormat::len(&self.obs)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.header, buf);
        WireFormat::write(&self.obs, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgObsDepA {
            sender_id: None,
            header: WireFormat::parse_unchecked(buf),
            obs: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// This observation message has been deprecated in favor of observations that
/// are more interoperable. This message should be used for observations
/// referenced to a nominal pseudorange which are not interoperable with most
/// 3rd party GNSS receivers or typical RTCMv3 observations.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgObsDepB {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a GPS observation message
    #[cfg_attr(feature = "serde", serde(rename(serialize = "header")))]
    pub header: ObservationHeaderDep,
    /// Pseudorange and carrier phase observation for a satellite being tracked.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "obs")))]
    pub obs: Vec<PackedObsContentDepB>,
}

impl ConcreteMessage for MsgObsDepB {
    const MESSAGE_TYPE: u16 = 67;
    const MESSAGE_NAME: &'static str = "MSG_OBS_DEP_B";
}

impl SbpMessage for MsgObsDepB {
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
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.header.t.tow as f64) / 1000.0;
        let wn: i16 = match self.header.t.wn.try_into() {
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

impl TryFrom<Sbp> for MsgObsDepB {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgObsDepB(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgObsDepB {
    const MIN_LEN: usize = <ObservationHeaderDep as WireFormat>::MIN_LEN
        + <Vec<PackedObsContentDepB> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.header) + WireFormat::len(&self.obs)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.header, buf);
        WireFormat::write(&self.obs, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgObsDepB {
            sender_id: None,
            header: WireFormat::parse_unchecked(buf),
            obs: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// The GPS observations message reports all the raw pseudorange and carrier
/// phase observations for the satellites being tracked by the device. Carrier
/// phase observation here is represented as a 40-bit fixed point number with
/// Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of fractional
/// cycles). The observations are interoperable with 3rd party receivers and
/// conform with typical RTCMv3 GNSS observations.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgObsDepC {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a GPS observation message
    #[cfg_attr(feature = "serde", serde(rename(serialize = "header")))]
    pub header: ObservationHeaderDep,
    /// Pseudorange and carrier phase observation for a satellite being tracked.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "obs")))]
    pub obs: Vec<PackedObsContentDepC>,
}

impl ConcreteMessage for MsgObsDepC {
    const MESSAGE_TYPE: u16 = 73;
    const MESSAGE_NAME: &'static str = "MSG_OBS_DEP_C";
}

impl SbpMessage for MsgObsDepC {
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
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.header.t.tow as f64) / 1000.0;
        let wn: i16 = match self.header.t.wn.try_into() {
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

impl TryFrom<Sbp> for MsgObsDepC {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgObsDepC(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgObsDepC {
    const MIN_LEN: usize = <ObservationHeaderDep as WireFormat>::MIN_LEN
        + <Vec<PackedObsContentDepC> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.header) + WireFormat::len(&self.obs)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.header, buf);
        WireFormat::write(&self.obs, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgObsDepC {
            sender_id: None,
            header: WireFormat::parse_unchecked(buf),
            obs: WireFormat::parse_unchecked(buf),
        }
    }
}

/// OSR corrections
///
/// The OSR message contains network corrections in an observation-like
/// format.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgOsr {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Header of a GPS observation message
    #[cfg_attr(feature = "serde", serde(rename(serialize = "header")))]
    pub header: ObservationHeader,
    /// Network correction for a satellite signal.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "obs")))]
    pub obs: Vec<PackedOsrContent>,
}

impl ConcreteMessage for MsgOsr {
    const MESSAGE_TYPE: u16 = 1600;
    const MESSAGE_NAME: &'static str = "MSG_OSR";
}

impl SbpMessage for MsgOsr {
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
    #[cfg(feature = "swiftnav")]
    fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {
        let tow_s = (self.header.t.tow as f64) / 1000.0;
        let wn: i16 = match self.header.t.wn.try_into() {
            Ok(wn) => wn,
            Err(e) => return Some(Err(e.into())),
        };
        let gps_time = match time::GpsTime::new(wn, tow_s) {
            Ok(gps_time) => gps_time,
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Base(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgOsr {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgOsr(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgOsr {
    const MIN_LEN: usize =
        <ObservationHeader as WireFormat>::MIN_LEN + <Vec<PackedOsrContent> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.header) + WireFormat::len(&self.obs)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.header, buf);
        WireFormat::write(&self.obs, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgOsr {
            sender_id: None,
            header: WireFormat::parse_unchecked(buf),
            obs: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite azimuths and elevations
///
/// Azimuth and elevation angles of all the visible satellites that the device
/// does have ephemeris or almanac for.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSvAzEl {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Azimuth and elevation per satellite
    #[cfg_attr(feature = "serde", serde(rename(serialize = "azel")))]
    pub azel: Vec<SvAzEl>,
}

impl ConcreteMessage for MsgSvAzEl {
    const MESSAGE_TYPE: u16 = 151;
    const MESSAGE_NAME: &'static str = "MSG_SV_AZ_EL";
}

impl SbpMessage for MsgSvAzEl {
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

impl TryFrom<Sbp> for MsgSvAzEl {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSvAzEl(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSvAzEl {
    const MIN_LEN: usize = <Vec<SvAzEl> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.azel)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.azel, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSvAzEl {
            sender_id: None,
            azel: WireFormat::parse_unchecked(buf),
        }
    }
}

/// L2C capability mask
///
/// Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSvConfigurationGpsDep {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Navigation Message Correction Table Validity Time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "t_nmct")))]
    pub t_nmct: GpsTimeSec,
    /// L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
    #[cfg_attr(feature = "serde", serde(rename(serialize = "l2c_mask")))]
    pub l2c_mask: u32,
}

impl ConcreteMessage for MsgSvConfigurationGpsDep {
    const MESSAGE_TYPE: u16 = 145;
    const MESSAGE_NAME: &'static str = "MSG_SV_CONFIGURATION_GPS_DEP";
}

impl SbpMessage for MsgSvConfigurationGpsDep {
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

impl TryFrom<Sbp> for MsgSvConfigurationGpsDep {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSvConfigurationGpsDep(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSvConfigurationGpsDep {
    const MIN_LEN: usize = <GpsTimeSec as WireFormat>::MIN_LEN + <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.t_nmct) + WireFormat::len(&self.l2c_mask)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.t_nmct, buf);
        WireFormat::write(&self.l2c_mask, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSvConfigurationGpsDep {
            sender_id: None,
            t_nmct: WireFormat::parse_unchecked(buf),
            l2c_mask: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Header for observation message
///
/// Header of a GNSS observation message.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct ObservationHeader {
    /// GNSS time of this observation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "t")))]
    pub t: GpsTime,
    /// Total number of observations. First nibble is the size of the sequence
    /// (n), second nibble is the zero-indexed counter (ith packet of n)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_obs")))]
    pub n_obs: u8,
}

impl WireFormat for ObservationHeader {
    const MIN_LEN: usize = <GpsTime as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.t) + WireFormat::len(&self.n_obs)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.t, buf);
        WireFormat::write(&self.n_obs, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        ObservationHeader {
            t: WireFormat::parse_unchecked(buf),
            n_obs: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Header for observation message
///
/// Header of a GPS observation message.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct ObservationHeaderDep {
    /// GPS time of this observation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "t")))]
    pub t: GpsTimeDep,
    /// Total number of observations. First nibble is the size of the sequence
    /// (n), second nibble is the zero-indexed counter (ith packet of n)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_obs")))]
    pub n_obs: u8,
}

impl WireFormat for ObservationHeaderDep {
    const MIN_LEN: usize = <GpsTimeDep as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.t) + WireFormat::len(&self.n_obs)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.t, buf);
        WireFormat::write(&self.n_obs, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        ObservationHeaderDep {
            t: WireFormat::parse_unchecked(buf),
            n_obs: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GNSS observations for a particular satellite signal
///
/// Pseudorange and carrier phase observation for a satellite being tracked.
/// The observations are interoperable with 3rd party receivers and conform
/// with typical RTCM 3.1 message GPS/GLO observations.
///
/// Carrier phase observations are not guaranteed to be aligned to the RINEX 3
/// or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are
/// currently performed.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct PackedObsContent {
    /// Pseudorange observation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "P")))]
    pub p: u32,
    /// Carrier phase observation with typical sign convention.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "L")))]
    pub l: CarrierPhase,
    /// Doppler observation with typical sign convention.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "D")))]
    pub d: Doppler,
    /// Carrier-to-Noise density.  Zero implies invalid cn0.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cn0")))]
    pub cn0: u8,
    /// Lock timer. This value gives an indication of the time for which a
    /// signal has maintained continuous phase lock. Whenever a signal has lost
    /// and regained lock, this value is reset to zero. It is encoded according
    /// to DF402 from the RTCM 10403.2 Amendment 2 specification.  Valid values
    /// range from 0 to 15 and the most significant nibble is reserved for
    /// future use.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lock")))]
    pub lock: u8,
    /// Measurement status flags. A bit field of flags providing the status of
    /// this observation.  If this field is 0 it means only the Cn0 estimate for
    /// the signal is valid.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
    /// GNSS signal identifier (16 bit)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
}

impl WireFormat for PackedObsContent {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <CarrierPhase as WireFormat>::MIN_LEN
        + <Doppler as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <GnssSignal as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.p)
            + WireFormat::len(&self.l)
            + WireFormat::len(&self.d)
            + WireFormat::len(&self.cn0)
            + WireFormat::len(&self.lock)
            + WireFormat::len(&self.flags)
            + WireFormat::len(&self.sid)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.p, buf);
        WireFormat::write(&self.l, buf);
        WireFormat::write(&self.d, buf);
        WireFormat::write(&self.cn0, buf);
        WireFormat::write(&self.lock, buf);
        WireFormat::write(&self.flags, buf);
        WireFormat::write(&self.sid, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        PackedObsContent {
            p: WireFormat::parse_unchecked(buf),
            l: WireFormat::parse_unchecked(buf),
            d: WireFormat::parse_unchecked(buf),
            cn0: WireFormat::parse_unchecked(buf),
            lock: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct PackedObsContentDepA {
    /// Pseudorange observation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "P")))]
    pub p: u32,
    /// Carrier phase observation with opposite sign from typical convention
    #[cfg_attr(feature = "serde", serde(rename(serialize = "L")))]
    pub l: CarrierPhaseDepA,
    /// Carrier-to-Noise density
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cn0")))]
    pub cn0: u8,
    /// Lock indicator. This value changes whenever a satellite signal has lost
    /// and regained lock, indicating that the carrier phase ambiguity may have
    /// changed.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lock")))]
    pub lock: u16,
    /// PRN-1 identifier of the satellite signal
    #[cfg_attr(feature = "serde", serde(rename(serialize = "prn")))]
    pub prn: u8,
}

impl WireFormat for PackedObsContentDepA {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <CarrierPhaseDepA as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.p)
            + WireFormat::len(&self.l)
            + WireFormat::len(&self.cn0)
            + WireFormat::len(&self.lock)
            + WireFormat::len(&self.prn)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.p, buf);
        WireFormat::write(&self.l, buf);
        WireFormat::write(&self.cn0, buf);
        WireFormat::write(&self.lock, buf);
        WireFormat::write(&self.prn, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        PackedObsContentDepA {
            p: WireFormat::parse_unchecked(buf),
            l: WireFormat::parse_unchecked(buf),
            cn0: WireFormat::parse_unchecked(buf),
            lock: WireFormat::parse_unchecked(buf),
            prn: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GPS observations for a particular satellite signal
///
/// Pseudorange and carrier phase observation for a satellite being tracked.
/// Pseudoranges are referenced to a nominal pseudorange.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct PackedObsContentDepB {
    /// Pseudorange observation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "P")))]
    pub p: u32,
    /// Carrier phase observation with opposite sign from typical convention.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "L")))]
    pub l: CarrierPhaseDepA,
    /// Carrier-to-Noise density
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cn0")))]
    pub cn0: u8,
    /// Lock indicator. This value changes whenever a satellite signal has lost
    /// and regained lock, indicating that the carrier phase ambiguity may have
    /// changed.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lock")))]
    pub lock: u16,
    /// GNSS signal identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignalDep,
}

impl WireFormat for PackedObsContentDepB {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <CarrierPhaseDepA as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <GnssSignalDep as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.p)
            + WireFormat::len(&self.l)
            + WireFormat::len(&self.cn0)
            + WireFormat::len(&self.lock)
            + WireFormat::len(&self.sid)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.p, buf);
        WireFormat::write(&self.l, buf);
        WireFormat::write(&self.cn0, buf);
        WireFormat::write(&self.lock, buf);
        WireFormat::write(&self.sid, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        PackedObsContentDepB {
            p: WireFormat::parse_unchecked(buf),
            l: WireFormat::parse_unchecked(buf),
            cn0: WireFormat::parse_unchecked(buf),
            lock: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
        }
    }
}

/// GPS observations for a particular satellite signal
///
/// Pseudorange and carrier phase observation for a satellite being tracked.
/// The observations are be interoperable with 3rd party receivers and conform
/// with typical RTCMv3 GNSS observations.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct PackedObsContentDepC {
    /// Pseudorange observation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "P")))]
    pub p: u32,
    /// Carrier phase observation with typical sign convention.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "L")))]
    pub l: CarrierPhase,
    /// Carrier-to-Noise density
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cn0")))]
    pub cn0: u8,
    /// Lock indicator. This value changes whenever a satellite signal has lost
    /// and regained lock, indicating that the carrier phase ambiguity may have
    /// changed.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lock")))]
    pub lock: u16,
    /// GNSS signal identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignalDep,
}

impl WireFormat for PackedObsContentDepC {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <CarrierPhase as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <GnssSignalDep as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.p)
            + WireFormat::len(&self.l)
            + WireFormat::len(&self.cn0)
            + WireFormat::len(&self.lock)
            + WireFormat::len(&self.sid)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.p, buf);
        WireFormat::write(&self.l, buf);
        WireFormat::write(&self.cn0, buf);
        WireFormat::write(&self.lock, buf);
        WireFormat::write(&self.sid, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        PackedObsContentDepC {
            p: WireFormat::parse_unchecked(buf),
            l: WireFormat::parse_unchecked(buf),
            cn0: WireFormat::parse_unchecked(buf),
            lock: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Network correction for a particular satellite signal
///
/// Pseudorange and carrier phase network corrections for a satellite signal.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct PackedOsrContent {
    /// Pseudorange observation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "P")))]
    pub p: u32,
    /// Carrier phase observation with typical sign convention.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "L")))]
    pub l: CarrierPhase,
    /// Lock timer. This value gives an indication of the time for which a
    /// signal has maintained continuous phase lock. Whenever a signal has lost
    /// and regained lock, this value is reset to zero. It is encoded according
    /// to DF402 from the RTCM 10403.2 Amendment 2 specification.  Valid values
    /// range from 0 to 15 and the most significant nibble is reserved for
    /// future use.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "lock")))]
    pub lock: u8,
    /// Correction flags.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
    /// GNSS signal identifier (16 bit)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// Slant ionospheric correction standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "iono_std")))]
    pub iono_std: u16,
    /// Slant tropospheric correction standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tropo_std")))]
    pub tropo_std: u16,
    /// Orbit/clock/bias correction projected on range standard deviation
    #[cfg_attr(feature = "serde", serde(rename(serialize = "range_std")))]
    pub range_std: u16,
}

impl WireFormat for PackedOsrContent {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <CarrierPhase as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <GnssSignal as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.p)
            + WireFormat::len(&self.l)
            + WireFormat::len(&self.lock)
            + WireFormat::len(&self.flags)
            + WireFormat::len(&self.sid)
            + WireFormat::len(&self.iono_std)
            + WireFormat::len(&self.tropo_std)
            + WireFormat::len(&self.range_std)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.p, buf);
        WireFormat::write(&self.l, buf);
        WireFormat::write(&self.lock, buf);
        WireFormat::write(&self.flags, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.iono_std, buf);
        WireFormat::write(&self.tropo_std, buf);
        WireFormat::write(&self.range_std, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        PackedOsrContent {
            p: WireFormat::parse_unchecked(buf),
            l: WireFormat::parse_unchecked(buf),
            lock: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            iono_std: WireFormat::parse_unchecked(buf),
            tropo_std: WireFormat::parse_unchecked(buf),
            range_std: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite azimuth and elevation
///
/// Satellite azimuth and elevation.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct SvAzEl {
    /// GNSS signal identifier
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// Azimuth angle (range 0..179)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "az")))]
    pub az: u8,
    /// Elevation angle (range -90..90)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "el")))]
    pub el: i8,
}

impl WireFormat for SvAzEl {
    const MIN_LEN: usize = <GnssSignal as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <i8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sid) + WireFormat::len(&self.az) + WireFormat::len(&self.el)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.az, buf);
        WireFormat::write(&self.el, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        SvAzEl {
            sid: WireFormat::parse_unchecked(buf),
            az: WireFormat::parse_unchecked(buf),
            el: WireFormat::parse_unchecked(buf),
        }
    }
}
