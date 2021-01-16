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
// Automatically generated from yaml/swiftnav/sbp/observation.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Satellite observation messages from the device.

#[cfg(feature = "sbp_serde")]
use serde::{Deserialize, Serialize};

use super::gnss::*;
#[allow(unused_imports)]
use crate::{parser::SbpParse, BoundedSbpString, UnboundedSbpString};

#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct AlmanacCommonContent {
    /// GNSS signal identifier
    pub sid: GnssSignal,
    /// Reference time of almanac
    pub toa: GPSTimeSec,
    /// User Range Accuracy
    pub ura: f64,
    /// Curve fit interval
    pub fit_interval: u32,
    /// Status of almanac, 1 = valid, 0 = invalid
    pub valid: u8,
    /// Satellite health status for GPS:   - bits 5-7: NAV data health status.
    /// See IS-GPS-200H     Table 20-VII: NAV Data Health Indications.   - bits
    /// 0-4: Signal health status. See IS-GPS-200H     Table 20-VIII. Codes for
    /// Health of SV Signal     Components. Satellite health status for GLO:
    /// See GLO ICD 5.1 table 5.1 for details   - bit 0: C(n), "unhealthy" flag
    /// that is transmitted within     non-immediate data and indicates overall
    /// constellation status     at the moment of almanac uploading.     '0'
    /// indicates malfunction of n-satellite.     '1' indicates that n-satellite
    /// is operational.   - bit 1: Bn(ln), '0' indicates the satellite is
    /// operational     and suitable for navigation.
    pub health_bits: u8,
}

impl SbpParse<AlmanacCommonContent> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<AlmanacCommonContent> {
        Ok( AlmanacCommonContent{
            sid: self.parse()?,
            toa: self.parse()?,
            ura: self.parse()?,
            fit_interval: self.parse()?,
            valid: self.parse()?,
            health_bits: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for AlmanacCommonContent {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sid.append_to_sbp_buffer(buf);
        self.toa.append_to_sbp_buffer(buf);
        self.ura.append_to_sbp_buffer(buf);
        self.fit_interval.append_to_sbp_buffer(buf);
        self.valid.append_to_sbp_buffer(buf);
        self.health_bits.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sid.sbp_size();
        size += self.toa.sbp_size();
        size += self.ura.sbp_size();
        size += self.fit_interval.sbp_size();
        size += self.valid.sbp_size();
        size += self.health_bits.sbp_size();
        size
    }
}

#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct AlmanacCommonContentDep {
    /// GNSS signal identifier
    pub sid: GnssSignalDep,
    /// Reference time of almanac
    pub toa: GPSTimeSec,
    /// User Range Accuracy
    pub ura: f64,
    /// Curve fit interval
    pub fit_interval: u32,
    /// Status of almanac, 1 = valid, 0 = invalid
    pub valid: u8,
    /// Satellite health status for GPS:   - bits 5-7: NAV data health status.
    /// See IS-GPS-200H     Table 20-VII: NAV Data Health Indications.   - bits
    /// 0-4: Signal health status. See IS-GPS-200H     Table 20-VIII. Codes for
    /// Health of SV Signal     Components. Satellite health status for GLO:
    /// See GLO ICD 5.1 table 5.1 for details   - bit 0: C(n), "unhealthy" flag
    /// that is transmitted within     non-immediate data and indicates overall
    /// constellation status     at the moment of almanac uploading.     '0'
    /// indicates malfunction of n-satellite.     '1' indicates that n-satellite
    /// is operational.   - bit 1: Bn(ln), '0' indicates the satellite is
    /// operational     and suitable for navigation.
    pub health_bits: u8,
}

impl SbpParse<AlmanacCommonContentDep> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<AlmanacCommonContentDep> {
        Ok( AlmanacCommonContentDep{
            sid: self.parse()?,
            toa: self.parse()?,
            ura: self.parse()?,
            fit_interval: self.parse()?,
            valid: self.parse()?,
            health_bits: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for AlmanacCommonContentDep {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sid.append_to_sbp_buffer(buf);
        self.toa.append_to_sbp_buffer(buf);
        self.ura.append_to_sbp_buffer(buf);
        self.fit_interval.append_to_sbp_buffer(buf);
        self.valid.append_to_sbp_buffer(buf);
        self.health_bits.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sid.sbp_size();
        size += self.toa.sbp_size();
        size += self.ura.sbp_size();
        size += self.fit_interval.sbp_size();
        size += self.valid.sbp_size();
        size += self.health_bits.sbp_size();
        size
    }
}

/// GPS carrier phase measurement.
///
/// Carrier phase measurement in cycles represented as a 40-bit
/// fixed point number with Q32.8 layout, i.e. 32-bits of whole
/// cycles and 8-bits of fractional cycles. This has the opposite
/// sign convention than a typical GPS receiver and the phase has
/// the opposite sign as the pseudorange.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct CarrierPhaseDepA {
    /// Carrier phase whole cycles
    pub i: i32,
    /// Carrier phase fractional part
    pub f: u8,
}

impl SbpParse<CarrierPhaseDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<CarrierPhaseDepA> {
        Ok( CarrierPhaseDepA{
            i: self.parse()?,
            f: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for CarrierPhaseDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.i.append_to_sbp_buffer(buf);
        self.f.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.i.sbp_size();
        size += self.f.sbp_size();
        size
    }
}

/// GNSS doppler measurement.
///
/// Doppler measurement in Hz represented as a 24-bit
/// fixed point number with Q16.8 layout, i.e. 16-bits of whole
/// doppler and 8-bits of fractional doppler. This doppler is defined
/// as positive for approaching satellites.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct Doppler {
    /// Doppler whole Hz
    pub i: i16,
    /// Doppler fractional part
    pub f: u8,
}

impl SbpParse<Doppler> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<Doppler> {
        Ok( Doppler{
            i: self.parse()?,
            f: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for Doppler {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.i.append_to_sbp_buffer(buf);
        self.f.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.i.sbp_size();
        size += self.f.sbp_size();
        size
    }
}

#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct EphemerisCommonContent {
    /// GNSS signal identifier (16 bit)
    pub sid: GnssSignal,
    /// Time of Ephemerides
    pub toe: GPSTimeSec,
    /// User Range Accuracy
    pub ura: f32,
    /// Curve fit interval
    pub fit_interval: u32,
    /// Status of ephemeris, 1 = valid, 0 = invalid
    pub valid: u8,
    /// Satellite health status. GPS: ICD-GPS-200, chapter 20.3.3.3.1.4 SBAS: 0
    /// = valid, non-zero = invalid GLO: 0 = valid, non-zero = invalid
    pub health_bits: u8,
}

impl SbpParse<EphemerisCommonContent> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<EphemerisCommonContent> {
        Ok( EphemerisCommonContent{
            sid: self.parse()?,
            toe: self.parse()?,
            ura: self.parse()?,
            fit_interval: self.parse()?,
            valid: self.parse()?,
            health_bits: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for EphemerisCommonContent {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sid.append_to_sbp_buffer(buf);
        self.toe.append_to_sbp_buffer(buf);
        self.ura.append_to_sbp_buffer(buf);
        self.fit_interval.append_to_sbp_buffer(buf);
        self.valid.append_to_sbp_buffer(buf);
        self.health_bits.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sid.sbp_size();
        size += self.toe.sbp_size();
        size += self.ura.sbp_size();
        size += self.fit_interval.sbp_size();
        size += self.valid.sbp_size();
        size += self.health_bits.sbp_size();
        size
    }
}

#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct EphemerisCommonContentDepA {
    /// GNSS signal identifier
    pub sid: GnssSignalDep,
    /// Time of Ephemerides
    pub toe: GPSTimeDep,
    /// User Range Accuracy
    pub ura: f64,
    /// Curve fit interval
    pub fit_interval: u32,
    /// Status of ephemeris, 1 = valid, 0 = invalid
    pub valid: u8,
    /// Satellite health status. GPS: ICD-GPS-200, chapter 20.3.3.3.1.4 SBAS: 0
    /// = valid, non-zero = invalid GLO: 0 = valid, non-zero = invalid
    pub health_bits: u8,
}

impl SbpParse<EphemerisCommonContentDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<EphemerisCommonContentDepA> {
        Ok( EphemerisCommonContentDepA{
            sid: self.parse()?,
            toe: self.parse()?,
            ura: self.parse()?,
            fit_interval: self.parse()?,
            valid: self.parse()?,
            health_bits: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for EphemerisCommonContentDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sid.append_to_sbp_buffer(buf);
        self.toe.append_to_sbp_buffer(buf);
        self.ura.append_to_sbp_buffer(buf);
        self.fit_interval.append_to_sbp_buffer(buf);
        self.valid.append_to_sbp_buffer(buf);
        self.health_bits.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sid.sbp_size();
        size += self.toe.sbp_size();
        size += self.ura.sbp_size();
        size += self.fit_interval.sbp_size();
        size += self.valid.sbp_size();
        size += self.health_bits.sbp_size();
        size
    }
}

#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct EphemerisCommonContentDepB {
    /// GNSS signal identifier (16 bit)
    pub sid: GnssSignal,
    /// Time of Ephemerides
    pub toe: GPSTimeSec,
    /// User Range Accuracy
    pub ura: f64,
    /// Curve fit interval
    pub fit_interval: u32,
    /// Status of ephemeris, 1 = valid, 0 = invalid
    pub valid: u8,
    /// Satellite health status. GPS: ICD-GPS-200, chapter 20.3.3.3.1.4 Others:
    /// 0 = valid, non-zero = invalid
    pub health_bits: u8,
}

impl SbpParse<EphemerisCommonContentDepB> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<EphemerisCommonContentDepB> {
        Ok( EphemerisCommonContentDepB{
            sid: self.parse()?,
            toe: self.parse()?,
            ura: self.parse()?,
            fit_interval: self.parse()?,
            valid: self.parse()?,
            health_bits: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for EphemerisCommonContentDepB {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sid.append_to_sbp_buffer(buf);
        self.toe.append_to_sbp_buffer(buf);
        self.ura.append_to_sbp_buffer(buf);
        self.fit_interval.append_to_sbp_buffer(buf);
        self.valid.append_to_sbp_buffer(buf);
        self.health_bits.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sid.sbp_size();
        size += self.toe.sbp_size();
        size += self.ura.sbp_size();
        size += self.fit_interval.sbp_size();
        size += self.valid.sbp_size();
        size += self.health_bits.sbp_size();
        size
    }
}

#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct GnssCapb {
    /// GPS SV active mask
    pub gps_active: u64,
    /// GPS L2C active mask
    pub gps_l2c: u64,
    /// GPS L5 active mask
    pub gps_l5: u64,
    /// GLO active mask
    pub glo_active: u32,
    /// GLO L2OF active mask
    pub glo_l2of: u32,
    /// GLO L3 active mask
    pub glo_l3: u32,
    /// SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
    /// https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
    pub sbas_active: u64,
    /// SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
    /// https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
    pub sbas_l5: u64,
    /// BDS active mask
    pub bds_active: u64,
    /// BDS D2NAV active mask
    pub bds_d2nav: u64,
    /// BDS B2 active mask
    pub bds_b2: u64,
    /// BDS B2A active mask
    pub bds_b2a: u64,
    /// QZSS active mask
    pub qzss_active: u32,
    /// GAL active mask
    pub gal_active: u64,
    /// GAL E5 active mask
    pub gal_e5: u64,
}

impl SbpParse<GnssCapb> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<GnssCapb> {
        Ok( GnssCapb{
            gps_active: self.parse()?,
            gps_l2c: self.parse()?,
            gps_l5: self.parse()?,
            glo_active: self.parse()?,
            glo_l2of: self.parse()?,
            glo_l3: self.parse()?,
            sbas_active: self.parse()?,
            sbas_l5: self.parse()?,
            bds_active: self.parse()?,
            bds_d2nav: self.parse()?,
            bds_b2: self.parse()?,
            bds_b2a: self.parse()?,
            qzss_active: self.parse()?,
            gal_active: self.parse()?,
            gal_e5: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for GnssCapb {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.gps_active.append_to_sbp_buffer(buf);
        self.gps_l2c.append_to_sbp_buffer(buf);
        self.gps_l5.append_to_sbp_buffer(buf);
        self.glo_active.append_to_sbp_buffer(buf);
        self.glo_l2of.append_to_sbp_buffer(buf);
        self.glo_l3.append_to_sbp_buffer(buf);
        self.sbas_active.append_to_sbp_buffer(buf);
        self.sbas_l5.append_to_sbp_buffer(buf);
        self.bds_active.append_to_sbp_buffer(buf);
        self.bds_d2nav.append_to_sbp_buffer(buf);
        self.bds_b2.append_to_sbp_buffer(buf);
        self.bds_b2a.append_to_sbp_buffer(buf);
        self.qzss_active.append_to_sbp_buffer(buf);
        self.gal_active.append_to_sbp_buffer(buf);
        self.gal_e5.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.gps_active.sbp_size();
        size += self.gps_l2c.sbp_size();
        size += self.gps_l5.sbp_size();
        size += self.glo_active.sbp_size();
        size += self.glo_l2of.sbp_size();
        size += self.glo_l3.sbp_size();
        size += self.sbas_active.sbp_size();
        size += self.sbas_l5.sbp_size();
        size += self.bds_active.sbp_size();
        size += self.bds_d2nav.sbp_size();
        size += self.bds_b2.sbp_size();
        size += self.bds_b2a.sbp_size();
        size += self.qzss_active.sbp_size();
        size += self.gal_active.sbp_size();
        size += self.gal_e5.sbp_size();
        size
    }
}

/// Satellite broadcast ephemeris for GLO
///
/// The almanac message returns a set of satellite orbit parameters. Almanac
/// data is not very precise and is considered valid for up to several months.
/// Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
/// almanac" for details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgAlmanacGlo {
    pub sender_id: Option<u16>,
    /// Values common for all almanac types
    pub common: AlmanacCommonContent,
    /// Longitude of the first ascending node of the orbit in PZ-90.02
    /// coordinate system
    pub lambda_na: f64,
    /// Time of the first ascending node passage
    pub t_lambda_na: f64,
    /// Value of inclination at instant of t_lambda
    pub i: f64,
    /// Value of Draconian period at instant of t_lambda
    pub t: f64,
    /// Rate of change of the Draconian period
    pub t_dot: f64,
    /// Eccentricity at instant of t_lambda
    pub epsilon: f64,
    /// Argument of perigee at instant of t_lambda
    pub omega: f64,
}

impl SbpParse<MsgAlmanacGlo> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgAlmanacGlo> {
        Ok( MsgAlmanacGlo{
            sender_id: None,
            common: self.parse()?,
            lambda_na: self.parse()?,
            t_lambda_na: self.parse()?,
            i: self.parse()?,
            t: self.parse()?,
            t_dot: self.parse()?,
            epsilon: self.parse()?,
            omega: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgAlmanacGlo {
    fn get_message_type(&self) -> u16 {
        115
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

impl crate::serialize::SbpSerialize for MsgAlmanacGlo {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.lambda_na.append_to_sbp_buffer(buf);
        self.t_lambda_na.append_to_sbp_buffer(buf);
        self.i.append_to_sbp_buffer(buf);
        self.t.append_to_sbp_buffer(buf);
        self.t_dot.append_to_sbp_buffer(buf);
        self.epsilon.append_to_sbp_buffer(buf);
        self.omega.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.lambda_na.sbp_size();
        size += self.t_lambda_na.sbp_size();
        size += self.i.sbp_size();
        size += self.t.sbp_size();
        size += self.t_dot.sbp_size();
        size += self.epsilon.sbp_size();
        size += self.omega.sbp_size();
        size
    }
}

/// Satellite broadcast ephemeris for GLO
///
/// The almanac message returns a set of satellite orbit parameters. Almanac
/// data is not very precise and is considered valid for up to several months.
/// Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
/// almanac" for details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgAlmanacGloDep {
    pub sender_id: Option<u16>,
    /// Values common for all almanac types
    pub common: AlmanacCommonContentDep,
    /// Longitude of the first ascending node of the orbit in PZ-90.02
    /// coordinate system
    pub lambda_na: f64,
    /// Time of the first ascending node passage
    pub t_lambda_na: f64,
    /// Value of inclination at instant of t_lambda
    pub i: f64,
    /// Value of Draconian period at instant of t_lambda
    pub t: f64,
    /// Rate of change of the Draconian period
    pub t_dot: f64,
    /// Eccentricity at instant of t_lambda
    pub epsilon: f64,
    /// Argument of perigee at instant of t_lambda
    pub omega: f64,
}

impl SbpParse<MsgAlmanacGloDep> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgAlmanacGloDep> {
        Ok( MsgAlmanacGloDep{
            sender_id: None,
            common: self.parse()?,
            lambda_na: self.parse()?,
            t_lambda_na: self.parse()?,
            i: self.parse()?,
            t: self.parse()?,
            t_dot: self.parse()?,
            epsilon: self.parse()?,
            omega: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgAlmanacGloDep {
    fn get_message_type(&self) -> u16 {
        113
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

impl crate::serialize::SbpSerialize for MsgAlmanacGloDep {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.lambda_na.append_to_sbp_buffer(buf);
        self.t_lambda_na.append_to_sbp_buffer(buf);
        self.i.append_to_sbp_buffer(buf);
        self.t.append_to_sbp_buffer(buf);
        self.t_dot.append_to_sbp_buffer(buf);
        self.epsilon.append_to_sbp_buffer(buf);
        self.omega.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.lambda_na.sbp_size();
        size += self.t_lambda_na.sbp_size();
        size += self.i.sbp_size();
        size += self.t.sbp_size();
        size += self.t_dot.sbp_size();
        size += self.epsilon.sbp_size();
        size += self.omega.sbp_size();
        size
    }
}

/// Satellite broadcast ephemeris for GPS
///
/// The almanac message returns a set of satellite orbit parameters. Almanac
/// data is not very precise and is considered valid for up to several months.
/// Please see the Navstar GPS Space Segment/Navigation user interfaces
/// (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgAlmanacGPS {
    pub sender_id: Option<u16>,
    /// Values common for all almanac types
    pub common: AlmanacCommonContent,
    /// Mean anomaly at reference time
    pub m0: f64,
    /// Eccentricity of satellite orbit
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    pub omega0: f64,
    /// Rate of right ascension
    pub omegadot: f64,
    /// Argument of perigee
    pub w: f64,
    /// Inclination
    pub inc: f64,
    /// Polynomial clock correction coefficient (clock bias)
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    pub af1: f64,
}

impl SbpParse<MsgAlmanacGPS> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgAlmanacGPS> {
        Ok( MsgAlmanacGPS{
            sender_id: None,
            common: self.parse()?,
            m0: self.parse()?,
            ecc: self.parse()?,
            sqrta: self.parse()?,
            omega0: self.parse()?,
            omegadot: self.parse()?,
            w: self.parse()?,
            inc: self.parse()?,
            af0: self.parse()?,
            af1: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgAlmanacGPS {
    fn get_message_type(&self) -> u16 {
        114
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

impl crate::serialize::SbpSerialize for MsgAlmanacGPS {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.m0.append_to_sbp_buffer(buf);
        self.ecc.append_to_sbp_buffer(buf);
        self.sqrta.append_to_sbp_buffer(buf);
        self.omega0.append_to_sbp_buffer(buf);
        self.omegadot.append_to_sbp_buffer(buf);
        self.w.append_to_sbp_buffer(buf);
        self.inc.append_to_sbp_buffer(buf);
        self.af0.append_to_sbp_buffer(buf);
        self.af1.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.m0.sbp_size();
        size += self.ecc.sbp_size();
        size += self.sqrta.sbp_size();
        size += self.omega0.sbp_size();
        size += self.omegadot.sbp_size();
        size += self.w.sbp_size();
        size += self.inc.sbp_size();
        size += self.af0.sbp_size();
        size += self.af1.sbp_size();
        size
    }
}

/// Satellite broadcast ephemeris for GPS
///
/// The almanac message returns a set of satellite orbit parameters. Almanac
/// data is not very precise and is considered valid for up to several months.
/// Please see the Navstar GPS Space Segment/Navigation user interfaces
/// (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgAlmanacGPSDep {
    pub sender_id: Option<u16>,
    /// Values common for all almanac types
    pub common: AlmanacCommonContentDep,
    /// Mean anomaly at reference time
    pub m0: f64,
    /// Eccentricity of satellite orbit
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    pub omega0: f64,
    /// Rate of right ascension
    pub omegadot: f64,
    /// Argument of perigee
    pub w: f64,
    /// Inclination
    pub inc: f64,
    /// Polynomial clock correction coefficient (clock bias)
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    pub af1: f64,
}

impl SbpParse<MsgAlmanacGPSDep> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgAlmanacGPSDep> {
        Ok( MsgAlmanacGPSDep{
            sender_id: None,
            common: self.parse()?,
            m0: self.parse()?,
            ecc: self.parse()?,
            sqrta: self.parse()?,
            omega0: self.parse()?,
            omegadot: self.parse()?,
            w: self.parse()?,
            inc: self.parse()?,
            af0: self.parse()?,
            af1: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgAlmanacGPSDep {
    fn get_message_type(&self) -> u16 {
        112
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

impl crate::serialize::SbpSerialize for MsgAlmanacGPSDep {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.m0.append_to_sbp_buffer(buf);
        self.ecc.append_to_sbp_buffer(buf);
        self.sqrta.append_to_sbp_buffer(buf);
        self.omega0.append_to_sbp_buffer(buf);
        self.omegadot.append_to_sbp_buffer(buf);
        self.w.append_to_sbp_buffer(buf);
        self.inc.append_to_sbp_buffer(buf);
        self.af0.append_to_sbp_buffer(buf);
        self.af1.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.m0.sbp_size();
        size += self.ecc.sbp_size();
        size += self.sqrta.sbp_size();
        size += self.omega0.sbp_size();
        size += self.omegadot.sbp_size();
        size += self.w.sbp_size();
        size += self.inc.sbp_size();
        size += self.af0.sbp_size();
        size += self.af1.sbp_size();
        size
    }
}

/// Base station position in ECEF
///
/// The base station position message is the position reported by
/// the base station itself in absolute Earth Centered Earth Fixed
/// coordinates. It is used for pseudo-absolute RTK positioning, and
/// is required to be a high-accuracy surveyed location of the base
/// station. Any error here will result in an error in the
/// pseudo-absolute position output.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgBasePosECEF {
    pub sender_id: Option<u16>,
    /// ECEF X coodinate
    pub x: f64,
    /// ECEF Y coordinate
    pub y: f64,
    /// ECEF Z coordinate
    pub z: f64,
}

impl SbpParse<MsgBasePosECEF> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgBasePosECEF> {
        Ok( MsgBasePosECEF{
            sender_id: None,
            x: self.parse()?,
            y: self.parse()?,
            z: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgBasePosECEF {
    fn get_message_type(&self) -> u16 {
        72
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

impl crate::serialize::SbpSerialize for MsgBasePosECEF {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.x.append_to_sbp_buffer(buf);
        self.y.append_to_sbp_buffer(buf);
        self.z.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.x.sbp_size();
        size += self.y.sbp_size();
        size += self.z.sbp_size();
        size
    }
}

/// Base station position
///
/// The base station position message is the position reported by
/// the base station itself. It is used for pseudo-absolute RTK
/// positioning, and is required to be a high-accuracy surveyed
/// location of the base station. Any error here will result in an
/// error in the pseudo-absolute position output.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgBasePosLLH {
    pub sender_id: Option<u16>,
    /// Latitude
    pub lat: f64,
    /// Longitude
    pub lon: f64,
    /// Height
    pub height: f64,
}

impl SbpParse<MsgBasePosLLH> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgBasePosLLH> {
        Ok( MsgBasePosLLH{
            sender_id: None,
            lat: self.parse()?,
            lon: self.parse()?,
            height: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgBasePosLLH {
    fn get_message_type(&self) -> u16 {
        68
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

impl crate::serialize::SbpSerialize for MsgBasePosLLH {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.lat.append_to_sbp_buffer(buf);
        self.lon.append_to_sbp_buffer(buf);
        self.height.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.lat.sbp_size();
        size += self.lon.sbp_size();
        size += self.height.sbp_size();
        size
    }
}

/// Satellite broadcast ephemeris for BDS
///
/// The ephemeris message returns a set of satellite orbit
/// parameters that is used to calculate BDS satellite position,
/// velocity, and clock offset. Please see the BeiDou Navigation
/// Satellite System SIS-ICD Version 2.1, Table 5-9 for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisBds {
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    pub common: EphemerisCommonContent,
    /// Group delay differential for B1
    pub tgd1: f32,
    /// Group delay differential for B2
    pub tgd2: f32,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rs: f32,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_rc: f32,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    pub c_uc: f32,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    pub c_us: f32,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    pub c_ic: f32,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    pub c_is: f32,
    /// Mean motion difference
    pub dn: f64,
    /// Mean anomaly at reference time
    pub m0: f64,
    /// Eccentricity of satellite orbit
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    pub omega0: f64,
    /// Rate of right ascension
    pub omegadot: f64,
    /// Argument of perigee
    pub w: f64,
    /// Inclination
    pub inc: f64,
    /// Inclination first derivative
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    pub af1: f32,
    /// Polynomial clock correction coefficient (rate of clock drift)
    pub af2: f32,
    /// Clock reference
    pub toc: GPSTimeSec,
    /// Issue of ephemeris data  Calculated from the navigation data parameter
    /// t_oe per RTCM/CSNO recommendation: IODE = mod (t_oe / 720, 240)
    pub iode: u8,
    /// Issue of clock data  Calculated from the navigation data parameter t_oe
    /// per RTCM/CSNO recommendation: IODE = mod (t_oc / 720, 240)
    pub iodc: u16,
}

impl SbpParse<MsgEphemerisBds> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisBds> {
        Ok( MsgEphemerisBds{
            sender_id: None,
            common: self.parse()?,
            tgd1: self.parse()?,
            tgd2: self.parse()?,
            c_rs: self.parse()?,
            c_rc: self.parse()?,
            c_uc: self.parse()?,
            c_us: self.parse()?,
            c_ic: self.parse()?,
            c_is: self.parse()?,
            dn: self.parse()?,
            m0: self.parse()?,
            ecc: self.parse()?,
            sqrta: self.parse()?,
            omega0: self.parse()?,
            omegadot: self.parse()?,
            w: self.parse()?,
            inc: self.parse()?,
            inc_dot: self.parse()?,
            af0: self.parse()?,
            af1: self.parse()?,
            af2: self.parse()?,
            toc: self.parse()?,
            iode: self.parse()?,
            iodc: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisBds {
    fn get_message_type(&self) -> u16 {
        137
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

impl crate::serialize::SbpSerialize for MsgEphemerisBds {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.tgd1.append_to_sbp_buffer(buf);
        self.tgd2.append_to_sbp_buffer(buf);
        self.c_rs.append_to_sbp_buffer(buf);
        self.c_rc.append_to_sbp_buffer(buf);
        self.c_uc.append_to_sbp_buffer(buf);
        self.c_us.append_to_sbp_buffer(buf);
        self.c_ic.append_to_sbp_buffer(buf);
        self.c_is.append_to_sbp_buffer(buf);
        self.dn.append_to_sbp_buffer(buf);
        self.m0.append_to_sbp_buffer(buf);
        self.ecc.append_to_sbp_buffer(buf);
        self.sqrta.append_to_sbp_buffer(buf);
        self.omega0.append_to_sbp_buffer(buf);
        self.omegadot.append_to_sbp_buffer(buf);
        self.w.append_to_sbp_buffer(buf);
        self.inc.append_to_sbp_buffer(buf);
        self.inc_dot.append_to_sbp_buffer(buf);
        self.af0.append_to_sbp_buffer(buf);
        self.af1.append_to_sbp_buffer(buf);
        self.af2.append_to_sbp_buffer(buf);
        self.toc.append_to_sbp_buffer(buf);
        self.iode.append_to_sbp_buffer(buf);
        self.iodc.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.tgd1.sbp_size();
        size += self.tgd2.sbp_size();
        size += self.c_rs.sbp_size();
        size += self.c_rc.sbp_size();
        size += self.c_uc.sbp_size();
        size += self.c_us.sbp_size();
        size += self.c_ic.sbp_size();
        size += self.c_is.sbp_size();
        size += self.dn.sbp_size();
        size += self.m0.sbp_size();
        size += self.ecc.sbp_size();
        size += self.sqrta.sbp_size();
        size += self.omega0.sbp_size();
        size += self.omegadot.sbp_size();
        size += self.w.sbp_size();
        size += self.inc.sbp_size();
        size += self.inc_dot.sbp_size();
        size += self.af0.sbp_size();
        size += self.af1.sbp_size();
        size += self.af2.sbp_size();
        size += self.toc.sbp_size();
        size += self.iode.sbp_size();
        size += self.iodc.sbp_size();
        size
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisDepA {
    pub sender_id: Option<u16>,
    /// Group delay differential between L1 and L2
    pub tgd: f64,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rs: f64,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_rc: f64,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    pub c_uc: f64,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    pub c_us: f64,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    pub c_ic: f64,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    pub c_is: f64,
    /// Mean motion difference
    pub dn: f64,
    /// Mean anomaly at reference time
    pub m0: f64,
    /// Eccentricity of satellite orbit
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    pub omega0: f64,
    /// Rate of right ascension
    pub omegadot: f64,
    /// Argument of perigee
    pub w: f64,
    /// Inclination
    pub inc: f64,
    /// Inclination first derivative
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    pub af1: f64,
    /// Polynomial clock correction coefficient (rate of clock drift)
    pub af2: f64,
    /// Time of week
    pub toe_tow: f64,
    /// Week number
    pub toe_wn: u16,
    /// Clock reference time of week
    pub toc_tow: f64,
    /// Clock reference week number
    pub toc_wn: u16,
    /// Is valid?
    pub valid: u8,
    /// Satellite is healthy?
    pub healthy: u8,
    /// PRN being tracked
    pub prn: u8,
}

impl SbpParse<MsgEphemerisDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisDepA> {
        Ok( MsgEphemerisDepA{
            sender_id: None,
            tgd: self.parse()?,
            c_rs: self.parse()?,
            c_rc: self.parse()?,
            c_uc: self.parse()?,
            c_us: self.parse()?,
            c_ic: self.parse()?,
            c_is: self.parse()?,
            dn: self.parse()?,
            m0: self.parse()?,
            ecc: self.parse()?,
            sqrta: self.parse()?,
            omega0: self.parse()?,
            omegadot: self.parse()?,
            w: self.parse()?,
            inc: self.parse()?,
            inc_dot: self.parse()?,
            af0: self.parse()?,
            af1: self.parse()?,
            af2: self.parse()?,
            toe_tow: self.parse()?,
            toe_wn: self.parse()?,
            toc_tow: self.parse()?,
            toc_wn: self.parse()?,
            valid: self.parse()?,
            healthy: self.parse()?,
            prn: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisDepA {
    fn get_message_type(&self) -> u16 {
        26
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

impl crate::serialize::SbpSerialize for MsgEphemerisDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tgd.append_to_sbp_buffer(buf);
        self.c_rs.append_to_sbp_buffer(buf);
        self.c_rc.append_to_sbp_buffer(buf);
        self.c_uc.append_to_sbp_buffer(buf);
        self.c_us.append_to_sbp_buffer(buf);
        self.c_ic.append_to_sbp_buffer(buf);
        self.c_is.append_to_sbp_buffer(buf);
        self.dn.append_to_sbp_buffer(buf);
        self.m0.append_to_sbp_buffer(buf);
        self.ecc.append_to_sbp_buffer(buf);
        self.sqrta.append_to_sbp_buffer(buf);
        self.omega0.append_to_sbp_buffer(buf);
        self.omegadot.append_to_sbp_buffer(buf);
        self.w.append_to_sbp_buffer(buf);
        self.inc.append_to_sbp_buffer(buf);
        self.inc_dot.append_to_sbp_buffer(buf);
        self.af0.append_to_sbp_buffer(buf);
        self.af1.append_to_sbp_buffer(buf);
        self.af2.append_to_sbp_buffer(buf);
        self.toe_tow.append_to_sbp_buffer(buf);
        self.toe_wn.append_to_sbp_buffer(buf);
        self.toc_tow.append_to_sbp_buffer(buf);
        self.toc_wn.append_to_sbp_buffer(buf);
        self.valid.append_to_sbp_buffer(buf);
        self.healthy.append_to_sbp_buffer(buf);
        self.prn.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tgd.sbp_size();
        size += self.c_rs.sbp_size();
        size += self.c_rc.sbp_size();
        size += self.c_uc.sbp_size();
        size += self.c_us.sbp_size();
        size += self.c_ic.sbp_size();
        size += self.c_is.sbp_size();
        size += self.dn.sbp_size();
        size += self.m0.sbp_size();
        size += self.ecc.sbp_size();
        size += self.sqrta.sbp_size();
        size += self.omega0.sbp_size();
        size += self.omegadot.sbp_size();
        size += self.w.sbp_size();
        size += self.inc.sbp_size();
        size += self.inc_dot.sbp_size();
        size += self.af0.sbp_size();
        size += self.af1.sbp_size();
        size += self.af2.sbp_size();
        size += self.toe_tow.sbp_size();
        size += self.toe_wn.sbp_size();
        size += self.toc_tow.sbp_size();
        size += self.toc_wn.sbp_size();
        size += self.valid.sbp_size();
        size += self.healthy.sbp_size();
        size += self.prn.sbp_size();
        size
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisDepB {
    pub sender_id: Option<u16>,
    /// Group delay differential between L1 and L2
    pub tgd: f64,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rs: f64,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_rc: f64,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    pub c_uc: f64,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    pub c_us: f64,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    pub c_ic: f64,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    pub c_is: f64,
    /// Mean motion difference
    pub dn: f64,
    /// Mean anomaly at reference time
    pub m0: f64,
    /// Eccentricity of satellite orbit
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    pub omega0: f64,
    /// Rate of right ascension
    pub omegadot: f64,
    /// Argument of perigee
    pub w: f64,
    /// Inclination
    pub inc: f64,
    /// Inclination first derivative
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    pub af1: f64,
    /// Polynomial clock correction coefficient (rate of clock drift)
    pub af2: f64,
    /// Time of week
    pub toe_tow: f64,
    /// Week number
    pub toe_wn: u16,
    /// Clock reference time of week
    pub toc_tow: f64,
    /// Clock reference week number
    pub toc_wn: u16,
    /// Is valid?
    pub valid: u8,
    /// Satellite is healthy?
    pub healthy: u8,
    /// PRN being tracked
    pub prn: u8,
    /// Issue of ephemeris data
    pub iode: u8,
}

impl SbpParse<MsgEphemerisDepB> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisDepB> {
        Ok( MsgEphemerisDepB{
            sender_id: None,
            tgd: self.parse()?,
            c_rs: self.parse()?,
            c_rc: self.parse()?,
            c_uc: self.parse()?,
            c_us: self.parse()?,
            c_ic: self.parse()?,
            c_is: self.parse()?,
            dn: self.parse()?,
            m0: self.parse()?,
            ecc: self.parse()?,
            sqrta: self.parse()?,
            omega0: self.parse()?,
            omegadot: self.parse()?,
            w: self.parse()?,
            inc: self.parse()?,
            inc_dot: self.parse()?,
            af0: self.parse()?,
            af1: self.parse()?,
            af2: self.parse()?,
            toe_tow: self.parse()?,
            toe_wn: self.parse()?,
            toc_tow: self.parse()?,
            toc_wn: self.parse()?,
            valid: self.parse()?,
            healthy: self.parse()?,
            prn: self.parse()?,
            iode: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisDepB {
    fn get_message_type(&self) -> u16 {
        70
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

impl crate::serialize::SbpSerialize for MsgEphemerisDepB {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tgd.append_to_sbp_buffer(buf);
        self.c_rs.append_to_sbp_buffer(buf);
        self.c_rc.append_to_sbp_buffer(buf);
        self.c_uc.append_to_sbp_buffer(buf);
        self.c_us.append_to_sbp_buffer(buf);
        self.c_ic.append_to_sbp_buffer(buf);
        self.c_is.append_to_sbp_buffer(buf);
        self.dn.append_to_sbp_buffer(buf);
        self.m0.append_to_sbp_buffer(buf);
        self.ecc.append_to_sbp_buffer(buf);
        self.sqrta.append_to_sbp_buffer(buf);
        self.omega0.append_to_sbp_buffer(buf);
        self.omegadot.append_to_sbp_buffer(buf);
        self.w.append_to_sbp_buffer(buf);
        self.inc.append_to_sbp_buffer(buf);
        self.inc_dot.append_to_sbp_buffer(buf);
        self.af0.append_to_sbp_buffer(buf);
        self.af1.append_to_sbp_buffer(buf);
        self.af2.append_to_sbp_buffer(buf);
        self.toe_tow.append_to_sbp_buffer(buf);
        self.toe_wn.append_to_sbp_buffer(buf);
        self.toc_tow.append_to_sbp_buffer(buf);
        self.toc_wn.append_to_sbp_buffer(buf);
        self.valid.append_to_sbp_buffer(buf);
        self.healthy.append_to_sbp_buffer(buf);
        self.prn.append_to_sbp_buffer(buf);
        self.iode.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tgd.sbp_size();
        size += self.c_rs.sbp_size();
        size += self.c_rc.sbp_size();
        size += self.c_uc.sbp_size();
        size += self.c_us.sbp_size();
        size += self.c_ic.sbp_size();
        size += self.c_is.sbp_size();
        size += self.dn.sbp_size();
        size += self.m0.sbp_size();
        size += self.ecc.sbp_size();
        size += self.sqrta.sbp_size();
        size += self.omega0.sbp_size();
        size += self.omegadot.sbp_size();
        size += self.w.sbp_size();
        size += self.inc.sbp_size();
        size += self.inc_dot.sbp_size();
        size += self.af0.sbp_size();
        size += self.af1.sbp_size();
        size += self.af2.sbp_size();
        size += self.toe_tow.sbp_size();
        size += self.toe_wn.sbp_size();
        size += self.toc_tow.sbp_size();
        size += self.toc_wn.sbp_size();
        size += self.valid.sbp_size();
        size += self.healthy.sbp_size();
        size += self.prn.sbp_size();
        size += self.iode.sbp_size();
        size
    }
}

/// Satellite broadcast ephemeris
///
/// The ephemeris message returns a set of satellite orbit
/// parameters that is used to calculate GPS satellite position,
/// velocity, and clock offset. Please see the Navstar GPS
/// Space Segment/Navigation user interfaces (ICD-GPS-200, Table
/// 20-III) for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisDepC {
    pub sender_id: Option<u16>,
    /// Group delay differential between L1 and L2
    pub tgd: f64,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rs: f64,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_rc: f64,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    pub c_uc: f64,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    pub c_us: f64,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    pub c_ic: f64,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    pub c_is: f64,
    /// Mean motion difference
    pub dn: f64,
    /// Mean anomaly at reference time
    pub m0: f64,
    /// Eccentricity of satellite orbit
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    pub omega0: f64,
    /// Rate of right ascension
    pub omegadot: f64,
    /// Argument of perigee
    pub w: f64,
    /// Inclination
    pub inc: f64,
    /// Inclination first derivative
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    pub af1: f64,
    /// Polynomial clock correction coefficient (rate of clock drift)
    pub af2: f64,
    /// Time of week
    pub toe_tow: f64,
    /// Week number
    pub toe_wn: u16,
    /// Clock reference time of week
    pub toc_tow: f64,
    /// Clock reference week number
    pub toc_wn: u16,
    /// Is valid?
    pub valid: u8,
    /// Satellite is healthy?
    pub healthy: u8,
    /// GNSS signal identifier
    pub sid: GnssSignalDep,
    /// Issue of ephemeris data
    pub iode: u8,
    /// Issue of clock data
    pub iodc: u16,
    /// Reserved field
    pub reserved: u32,
}

impl SbpParse<MsgEphemerisDepC> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisDepC> {
        Ok( MsgEphemerisDepC{
            sender_id: None,
            tgd: self.parse()?,
            c_rs: self.parse()?,
            c_rc: self.parse()?,
            c_uc: self.parse()?,
            c_us: self.parse()?,
            c_ic: self.parse()?,
            c_is: self.parse()?,
            dn: self.parse()?,
            m0: self.parse()?,
            ecc: self.parse()?,
            sqrta: self.parse()?,
            omega0: self.parse()?,
            omegadot: self.parse()?,
            w: self.parse()?,
            inc: self.parse()?,
            inc_dot: self.parse()?,
            af0: self.parse()?,
            af1: self.parse()?,
            af2: self.parse()?,
            toe_tow: self.parse()?,
            toe_wn: self.parse()?,
            toc_tow: self.parse()?,
            toc_wn: self.parse()?,
            valid: self.parse()?,
            healthy: self.parse()?,
            sid: self.parse()?,
            iode: self.parse()?,
            iodc: self.parse()?,
            reserved: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisDepC {
    fn get_message_type(&self) -> u16 {
        71
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

impl crate::serialize::SbpSerialize for MsgEphemerisDepC {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tgd.append_to_sbp_buffer(buf);
        self.c_rs.append_to_sbp_buffer(buf);
        self.c_rc.append_to_sbp_buffer(buf);
        self.c_uc.append_to_sbp_buffer(buf);
        self.c_us.append_to_sbp_buffer(buf);
        self.c_ic.append_to_sbp_buffer(buf);
        self.c_is.append_to_sbp_buffer(buf);
        self.dn.append_to_sbp_buffer(buf);
        self.m0.append_to_sbp_buffer(buf);
        self.ecc.append_to_sbp_buffer(buf);
        self.sqrta.append_to_sbp_buffer(buf);
        self.omega0.append_to_sbp_buffer(buf);
        self.omegadot.append_to_sbp_buffer(buf);
        self.w.append_to_sbp_buffer(buf);
        self.inc.append_to_sbp_buffer(buf);
        self.inc_dot.append_to_sbp_buffer(buf);
        self.af0.append_to_sbp_buffer(buf);
        self.af1.append_to_sbp_buffer(buf);
        self.af2.append_to_sbp_buffer(buf);
        self.toe_tow.append_to_sbp_buffer(buf);
        self.toe_wn.append_to_sbp_buffer(buf);
        self.toc_tow.append_to_sbp_buffer(buf);
        self.toc_wn.append_to_sbp_buffer(buf);
        self.valid.append_to_sbp_buffer(buf);
        self.healthy.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.iode.append_to_sbp_buffer(buf);
        self.iodc.append_to_sbp_buffer(buf);
        self.reserved.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tgd.sbp_size();
        size += self.c_rs.sbp_size();
        size += self.c_rc.sbp_size();
        size += self.c_uc.sbp_size();
        size += self.c_us.sbp_size();
        size += self.c_ic.sbp_size();
        size += self.c_is.sbp_size();
        size += self.dn.sbp_size();
        size += self.m0.sbp_size();
        size += self.ecc.sbp_size();
        size += self.sqrta.sbp_size();
        size += self.omega0.sbp_size();
        size += self.omegadot.sbp_size();
        size += self.w.sbp_size();
        size += self.inc.sbp_size();
        size += self.inc_dot.sbp_size();
        size += self.af0.sbp_size();
        size += self.af1.sbp_size();
        size += self.af2.sbp_size();
        size += self.toe_tow.sbp_size();
        size += self.toe_wn.sbp_size();
        size += self.toc_tow.sbp_size();
        size += self.toc_wn.sbp_size();
        size += self.valid.sbp_size();
        size += self.healthy.sbp_size();
        size += self.sid.sbp_size();
        size += self.iode.sbp_size();
        size += self.iodc.sbp_size();
        size += self.reserved.sbp_size();
        size
    }
}

/// Satellite broadcast ephemeris
///
/// The ephemeris message returns a set of satellite orbit
/// parameters that is used to calculate GPS satellite position,
/// velocity, and clock offset. Please see the Navstar GPS
/// Space Segment/Navigation user interfaces (ICD-GPS-200, Table
/// 20-III) for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisDepD {
    pub sender_id: Option<u16>,
    /// Group delay differential between L1 and L2
    pub tgd: f64,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rs: f64,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_rc: f64,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    pub c_uc: f64,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    pub c_us: f64,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    pub c_ic: f64,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    pub c_is: f64,
    /// Mean motion difference
    pub dn: f64,
    /// Mean anomaly at reference time
    pub m0: f64,
    /// Eccentricity of satellite orbit
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    pub omega0: f64,
    /// Rate of right ascension
    pub omegadot: f64,
    /// Argument of perigee
    pub w: f64,
    /// Inclination
    pub inc: f64,
    /// Inclination first derivative
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    pub af1: f64,
    /// Polynomial clock correction coefficient (rate of clock drift)
    pub af2: f64,
    /// Time of week
    pub toe_tow: f64,
    /// Week number
    pub toe_wn: u16,
    /// Clock reference time of week
    pub toc_tow: f64,
    /// Clock reference week number
    pub toc_wn: u16,
    /// Is valid?
    pub valid: u8,
    /// Satellite is healthy?
    pub healthy: u8,
    /// GNSS signal identifier
    pub sid: GnssSignalDep,
    /// Issue of ephemeris data
    pub iode: u8,
    /// Issue of clock data
    pub iodc: u16,
    /// Reserved field
    pub reserved: u32,
}

impl SbpParse<MsgEphemerisDepD> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisDepD> {
        Ok( MsgEphemerisDepD{
            sender_id: None,
            tgd: self.parse()?,
            c_rs: self.parse()?,
            c_rc: self.parse()?,
            c_uc: self.parse()?,
            c_us: self.parse()?,
            c_ic: self.parse()?,
            c_is: self.parse()?,
            dn: self.parse()?,
            m0: self.parse()?,
            ecc: self.parse()?,
            sqrta: self.parse()?,
            omega0: self.parse()?,
            omegadot: self.parse()?,
            w: self.parse()?,
            inc: self.parse()?,
            inc_dot: self.parse()?,
            af0: self.parse()?,
            af1: self.parse()?,
            af2: self.parse()?,
            toe_tow: self.parse()?,
            toe_wn: self.parse()?,
            toc_tow: self.parse()?,
            toc_wn: self.parse()?,
            valid: self.parse()?,
            healthy: self.parse()?,
            sid: self.parse()?,
            iode: self.parse()?,
            iodc: self.parse()?,
            reserved: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisDepD {
    fn get_message_type(&self) -> u16 {
        128
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

impl crate::serialize::SbpSerialize for MsgEphemerisDepD {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tgd.append_to_sbp_buffer(buf);
        self.c_rs.append_to_sbp_buffer(buf);
        self.c_rc.append_to_sbp_buffer(buf);
        self.c_uc.append_to_sbp_buffer(buf);
        self.c_us.append_to_sbp_buffer(buf);
        self.c_ic.append_to_sbp_buffer(buf);
        self.c_is.append_to_sbp_buffer(buf);
        self.dn.append_to_sbp_buffer(buf);
        self.m0.append_to_sbp_buffer(buf);
        self.ecc.append_to_sbp_buffer(buf);
        self.sqrta.append_to_sbp_buffer(buf);
        self.omega0.append_to_sbp_buffer(buf);
        self.omegadot.append_to_sbp_buffer(buf);
        self.w.append_to_sbp_buffer(buf);
        self.inc.append_to_sbp_buffer(buf);
        self.inc_dot.append_to_sbp_buffer(buf);
        self.af0.append_to_sbp_buffer(buf);
        self.af1.append_to_sbp_buffer(buf);
        self.af2.append_to_sbp_buffer(buf);
        self.toe_tow.append_to_sbp_buffer(buf);
        self.toe_wn.append_to_sbp_buffer(buf);
        self.toc_tow.append_to_sbp_buffer(buf);
        self.toc_wn.append_to_sbp_buffer(buf);
        self.valid.append_to_sbp_buffer(buf);
        self.healthy.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.iode.append_to_sbp_buffer(buf);
        self.iodc.append_to_sbp_buffer(buf);
        self.reserved.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tgd.sbp_size();
        size += self.c_rs.sbp_size();
        size += self.c_rc.sbp_size();
        size += self.c_uc.sbp_size();
        size += self.c_us.sbp_size();
        size += self.c_ic.sbp_size();
        size += self.c_is.sbp_size();
        size += self.dn.sbp_size();
        size += self.m0.sbp_size();
        size += self.ecc.sbp_size();
        size += self.sqrta.sbp_size();
        size += self.omega0.sbp_size();
        size += self.omegadot.sbp_size();
        size += self.w.sbp_size();
        size += self.inc.sbp_size();
        size += self.inc_dot.sbp_size();
        size += self.af0.sbp_size();
        size += self.af1.sbp_size();
        size += self.af2.sbp_size();
        size += self.toe_tow.sbp_size();
        size += self.toe_wn.sbp_size();
        size += self.toc_tow.sbp_size();
        size += self.toc_wn.sbp_size();
        size += self.valid.sbp_size();
        size += self.healthy.sbp_size();
        size += self.sid.sbp_size();
        size += self.iode.sbp_size();
        size += self.iodc.sbp_size();
        size += self.reserved.sbp_size();
        size
    }
}

/// Satellite broadcast ephemeris for Galileo
///
/// The ephemeris message returns a set of satellite orbit
/// parameters that is used to calculate Galileo satellite position,
/// velocity, and clock offset. Please see the Signal In Space ICD
/// OS SIS ICD, Issue 1.3, December 2016 for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGal {
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    pub common: EphemerisCommonContent,
    /// E1-E5a Broadcast Group Delay
    pub bgd_e1e5a: f32,
    /// E1-E5b Broadcast Group Delay
    pub bgd_e1e5b: f32,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rs: f32,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_rc: f32,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    pub c_uc: f32,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    pub c_us: f32,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    pub c_ic: f32,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    pub c_is: f32,
    /// Mean motion difference
    pub dn: f64,
    /// Mean anomaly at reference time
    pub m0: f64,
    /// Eccentricity of satellite orbit
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    pub omega0: f64,
    /// Rate of right ascension
    pub omegadot: f64,
    /// Argument of perigee
    pub w: f64,
    /// Inclination
    pub inc: f64,
    /// Inclination first derivative
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    pub af1: f64,
    /// Polynomial clock correction coefficient (rate of clock drift)
    pub af2: f32,
    /// Clock reference
    pub toc: GPSTimeSec,
    /// Issue of data (IODnav)
    pub iode: u16,
    /// Issue of data (IODnav). Always equal to iode
    pub iodc: u16,
    /// 0=I/NAV, 1=F/NAV
    pub source: u8,
}

impl SbpParse<MsgEphemerisGal> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisGal> {
        Ok( MsgEphemerisGal{
            sender_id: None,
            common: self.parse()?,
            bgd_e1e5a: self.parse()?,
            bgd_e1e5b: self.parse()?,
            c_rs: self.parse()?,
            c_rc: self.parse()?,
            c_uc: self.parse()?,
            c_us: self.parse()?,
            c_ic: self.parse()?,
            c_is: self.parse()?,
            dn: self.parse()?,
            m0: self.parse()?,
            ecc: self.parse()?,
            sqrta: self.parse()?,
            omega0: self.parse()?,
            omegadot: self.parse()?,
            w: self.parse()?,
            inc: self.parse()?,
            inc_dot: self.parse()?,
            af0: self.parse()?,
            af1: self.parse()?,
            af2: self.parse()?,
            toc: self.parse()?,
            iode: self.parse()?,
            iodc: self.parse()?,
            source: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisGal {
    fn get_message_type(&self) -> u16 {
        141
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

impl crate::serialize::SbpSerialize for MsgEphemerisGal {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.bgd_e1e5a.append_to_sbp_buffer(buf);
        self.bgd_e1e5b.append_to_sbp_buffer(buf);
        self.c_rs.append_to_sbp_buffer(buf);
        self.c_rc.append_to_sbp_buffer(buf);
        self.c_uc.append_to_sbp_buffer(buf);
        self.c_us.append_to_sbp_buffer(buf);
        self.c_ic.append_to_sbp_buffer(buf);
        self.c_is.append_to_sbp_buffer(buf);
        self.dn.append_to_sbp_buffer(buf);
        self.m0.append_to_sbp_buffer(buf);
        self.ecc.append_to_sbp_buffer(buf);
        self.sqrta.append_to_sbp_buffer(buf);
        self.omega0.append_to_sbp_buffer(buf);
        self.omegadot.append_to_sbp_buffer(buf);
        self.w.append_to_sbp_buffer(buf);
        self.inc.append_to_sbp_buffer(buf);
        self.inc_dot.append_to_sbp_buffer(buf);
        self.af0.append_to_sbp_buffer(buf);
        self.af1.append_to_sbp_buffer(buf);
        self.af2.append_to_sbp_buffer(buf);
        self.toc.append_to_sbp_buffer(buf);
        self.iode.append_to_sbp_buffer(buf);
        self.iodc.append_to_sbp_buffer(buf);
        self.source.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.bgd_e1e5a.sbp_size();
        size += self.bgd_e1e5b.sbp_size();
        size += self.c_rs.sbp_size();
        size += self.c_rc.sbp_size();
        size += self.c_uc.sbp_size();
        size += self.c_us.sbp_size();
        size += self.c_ic.sbp_size();
        size += self.c_is.sbp_size();
        size += self.dn.sbp_size();
        size += self.m0.sbp_size();
        size += self.ecc.sbp_size();
        size += self.sqrta.sbp_size();
        size += self.omega0.sbp_size();
        size += self.omegadot.sbp_size();
        size += self.w.sbp_size();
        size += self.inc.sbp_size();
        size += self.inc_dot.sbp_size();
        size += self.af0.sbp_size();
        size += self.af1.sbp_size();
        size += self.af2.sbp_size();
        size += self.toc.sbp_size();
        size += self.iode.sbp_size();
        size += self.iodc.sbp_size();
        size += self.source.sbp_size();
        size
    }
}

/// Deprecated
///
/// This observation message has been deprecated in favor of
/// an ephemeris message with explicit source of NAV data.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGalDepA {
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    pub common: EphemerisCommonContent,
    /// E1-E5a Broadcast Group Delay
    pub bgd_e1e5a: f32,
    /// E1-E5b Broadcast Group Delay
    pub bgd_e1e5b: f32,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rs: f32,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_rc: f32,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    pub c_uc: f32,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    pub c_us: f32,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    pub c_ic: f32,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    pub c_is: f32,
    /// Mean motion difference
    pub dn: f64,
    /// Mean anomaly at reference time
    pub m0: f64,
    /// Eccentricity of satellite orbit
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    pub omega0: f64,
    /// Rate of right ascension
    pub omegadot: f64,
    /// Argument of perigee
    pub w: f64,
    /// Inclination
    pub inc: f64,
    /// Inclination first derivative
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    pub af1: f64,
    /// Polynomial clock correction coefficient (rate of clock drift)
    pub af2: f32,
    /// Clock reference
    pub toc: GPSTimeSec,
    /// Issue of data (IODnav)
    pub iode: u16,
    /// Issue of data (IODnav). Always equal to iode
    pub iodc: u16,
}

impl SbpParse<MsgEphemerisGalDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisGalDepA> {
        Ok( MsgEphemerisGalDepA{
            sender_id: None,
            common: self.parse()?,
            bgd_e1e5a: self.parse()?,
            bgd_e1e5b: self.parse()?,
            c_rs: self.parse()?,
            c_rc: self.parse()?,
            c_uc: self.parse()?,
            c_us: self.parse()?,
            c_ic: self.parse()?,
            c_is: self.parse()?,
            dn: self.parse()?,
            m0: self.parse()?,
            ecc: self.parse()?,
            sqrta: self.parse()?,
            omega0: self.parse()?,
            omegadot: self.parse()?,
            w: self.parse()?,
            inc: self.parse()?,
            inc_dot: self.parse()?,
            af0: self.parse()?,
            af1: self.parse()?,
            af2: self.parse()?,
            toc: self.parse()?,
            iode: self.parse()?,
            iodc: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisGalDepA {
    fn get_message_type(&self) -> u16 {
        149
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

impl crate::serialize::SbpSerialize for MsgEphemerisGalDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.bgd_e1e5a.append_to_sbp_buffer(buf);
        self.bgd_e1e5b.append_to_sbp_buffer(buf);
        self.c_rs.append_to_sbp_buffer(buf);
        self.c_rc.append_to_sbp_buffer(buf);
        self.c_uc.append_to_sbp_buffer(buf);
        self.c_us.append_to_sbp_buffer(buf);
        self.c_ic.append_to_sbp_buffer(buf);
        self.c_is.append_to_sbp_buffer(buf);
        self.dn.append_to_sbp_buffer(buf);
        self.m0.append_to_sbp_buffer(buf);
        self.ecc.append_to_sbp_buffer(buf);
        self.sqrta.append_to_sbp_buffer(buf);
        self.omega0.append_to_sbp_buffer(buf);
        self.omegadot.append_to_sbp_buffer(buf);
        self.w.append_to_sbp_buffer(buf);
        self.inc.append_to_sbp_buffer(buf);
        self.inc_dot.append_to_sbp_buffer(buf);
        self.af0.append_to_sbp_buffer(buf);
        self.af1.append_to_sbp_buffer(buf);
        self.af2.append_to_sbp_buffer(buf);
        self.toc.append_to_sbp_buffer(buf);
        self.iode.append_to_sbp_buffer(buf);
        self.iodc.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.bgd_e1e5a.sbp_size();
        size += self.bgd_e1e5b.sbp_size();
        size += self.c_rs.sbp_size();
        size += self.c_rc.sbp_size();
        size += self.c_uc.sbp_size();
        size += self.c_us.sbp_size();
        size += self.c_ic.sbp_size();
        size += self.c_is.sbp_size();
        size += self.dn.sbp_size();
        size += self.m0.sbp_size();
        size += self.ecc.sbp_size();
        size += self.sqrta.sbp_size();
        size += self.omega0.sbp_size();
        size += self.omegadot.sbp_size();
        size += self.w.sbp_size();
        size += self.inc.sbp_size();
        size += self.inc_dot.sbp_size();
        size += self.af0.sbp_size();
        size += self.af1.sbp_size();
        size += self.af2.sbp_size();
        size += self.toc.sbp_size();
        size += self.iode.sbp_size();
        size += self.iodc.sbp_size();
        size
    }
}

/// Satellite broadcast ephemeris for GLO
///
/// The ephemeris message returns a set of satellite orbit
/// parameters that is used to calculate GLO satellite position,
/// velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
/// Characteristics of words of immediate information (ephemeris parameters)"
/// for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGlo {
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    pub common: EphemerisCommonContent,
    /// Relative deviation of predicted carrier frequency from nominal
    pub gamma: f32,
    /// Correction to the SV time
    pub tau: f32,
    /// Equipment delay between L1 and L2
    pub d_tau: f32,
    /// Position of the SV at tb in PZ-90.02 coordinates system
    pub pos: [f64; 3],
    /// Velocity vector of the SV at tb in PZ-90.02 coordinates system
    pub vel: [f64; 3],
    /// Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    pub acc: [f32; 3],
    /// Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
    pub fcn: u8,
    /// Issue of data. Equal to the 7 bits of the immediate data word t_b
    pub iod: u8,
}

impl SbpParse<MsgEphemerisGlo> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisGlo> {
        Ok( MsgEphemerisGlo{
            sender_id: None,
            common: self.parse()?,
            gamma: self.parse()?,
            tau: self.parse()?,
            d_tau: self.parse()?,
            pos: self.parse()?,
            vel: self.parse()?,
            acc: self.parse()?,
            fcn: self.parse()?,
            iod: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisGlo {
    fn get_message_type(&self) -> u16 {
        139
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

impl crate::serialize::SbpSerialize for MsgEphemerisGlo {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.gamma.append_to_sbp_buffer(buf);
        self.tau.append_to_sbp_buffer(buf);
        self.d_tau.append_to_sbp_buffer(buf);
        self.pos.append_to_sbp_buffer(buf);
        self.vel.append_to_sbp_buffer(buf);
        self.acc.append_to_sbp_buffer(buf);
        self.fcn.append_to_sbp_buffer(buf);
        self.iod.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.gamma.sbp_size();
        size += self.tau.sbp_size();
        size += self.d_tau.sbp_size();
        size += self.pos.sbp_size();
        size += self.vel.sbp_size();
        size += self.acc.sbp_size();
        size += self.fcn.sbp_size();
        size += self.iod.sbp_size();
        size
    }
}

/// Satellite broadcast ephemeris for GLO
///
/// The ephemeris message returns a set of satellite orbit
/// parameters that is used to calculate GLO satellite position,
/// velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
/// Characteristics of words of immediate information (ephemeris parameters)"
/// for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGloDepA {
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    pub common: EphemerisCommonContentDepA,
    /// Relative deviation of predicted carrier frequency from nominal
    pub gamma: f64,
    /// Correction to the SV time
    pub tau: f64,
    /// Position of the SV at tb in PZ-90.02 coordinates system
    pub pos: [f64; 3],
    /// Velocity vector of the SV at tb in PZ-90.02 coordinates system
    pub vel: [f64; 3],
    /// Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    pub acc: [f64; 3],
}

impl SbpParse<MsgEphemerisGloDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisGloDepA> {
        Ok( MsgEphemerisGloDepA{
            sender_id: None,
            common: self.parse()?,
            gamma: self.parse()?,
            tau: self.parse()?,
            pos: self.parse()?,
            vel: self.parse()?,
            acc: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisGloDepA {
    fn get_message_type(&self) -> u16 {
        131
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

impl crate::serialize::SbpSerialize for MsgEphemerisGloDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.gamma.append_to_sbp_buffer(buf);
        self.tau.append_to_sbp_buffer(buf);
        self.pos.append_to_sbp_buffer(buf);
        self.vel.append_to_sbp_buffer(buf);
        self.acc.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.gamma.sbp_size();
        size += self.tau.sbp_size();
        size += self.pos.sbp_size();
        size += self.vel.sbp_size();
        size += self.acc.sbp_size();
        size
    }
}

/// Satellite broadcast ephemeris for GLO
///
/// The ephemeris message returns a set of satellite orbit
/// parameters that is used to calculate GLO satellite position,
/// velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
/// Characteristics of words of immediate information (ephemeris parameters)"
/// for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGloDepB {
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    pub common: EphemerisCommonContentDepB,
    /// Relative deviation of predicted carrier frequency from nominal
    pub gamma: f64,
    /// Correction to the SV time
    pub tau: f64,
    /// Position of the SV at tb in PZ-90.02 coordinates system
    pub pos: [f64; 3],
    /// Velocity vector of the SV at tb in PZ-90.02 coordinates system
    pub vel: [f64; 3],
    /// Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    pub acc: [f64; 3],
}

impl SbpParse<MsgEphemerisGloDepB> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisGloDepB> {
        Ok( MsgEphemerisGloDepB{
            sender_id: None,
            common: self.parse()?,
            gamma: self.parse()?,
            tau: self.parse()?,
            pos: self.parse()?,
            vel: self.parse()?,
            acc: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisGloDepB {
    fn get_message_type(&self) -> u16 {
        133
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

impl crate::serialize::SbpSerialize for MsgEphemerisGloDepB {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.gamma.append_to_sbp_buffer(buf);
        self.tau.append_to_sbp_buffer(buf);
        self.pos.append_to_sbp_buffer(buf);
        self.vel.append_to_sbp_buffer(buf);
        self.acc.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.gamma.sbp_size();
        size += self.tau.sbp_size();
        size += self.pos.sbp_size();
        size += self.vel.sbp_size();
        size += self.acc.sbp_size();
        size
    }
}

/// Satellite broadcast ephemeris for GLO
///
/// The ephemeris message returns a set of satellite orbit
/// parameters that is used to calculate GLO satellite position,
/// velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
/// Characteristics of words of immediate information (ephemeris parameters)"
/// for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGloDepC {
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    pub common: EphemerisCommonContentDepB,
    /// Relative deviation of predicted carrier frequency from nominal
    pub gamma: f64,
    /// Correction to the SV time
    pub tau: f64,
    /// Equipment delay between L1 and L2
    pub d_tau: f64,
    /// Position of the SV at tb in PZ-90.02 coordinates system
    pub pos: [f64; 3],
    /// Velocity vector of the SV at tb in PZ-90.02 coordinates system
    pub vel: [f64; 3],
    /// Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    pub acc: [f64; 3],
    /// Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
    pub fcn: u8,
}

impl SbpParse<MsgEphemerisGloDepC> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisGloDepC> {
        Ok( MsgEphemerisGloDepC{
            sender_id: None,
            common: self.parse()?,
            gamma: self.parse()?,
            tau: self.parse()?,
            d_tau: self.parse()?,
            pos: self.parse()?,
            vel: self.parse()?,
            acc: self.parse()?,
            fcn: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisGloDepC {
    fn get_message_type(&self) -> u16 {
        135
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

impl crate::serialize::SbpSerialize for MsgEphemerisGloDepC {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.gamma.append_to_sbp_buffer(buf);
        self.tau.append_to_sbp_buffer(buf);
        self.d_tau.append_to_sbp_buffer(buf);
        self.pos.append_to_sbp_buffer(buf);
        self.vel.append_to_sbp_buffer(buf);
        self.acc.append_to_sbp_buffer(buf);
        self.fcn.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.gamma.sbp_size();
        size += self.tau.sbp_size();
        size += self.d_tau.sbp_size();
        size += self.pos.sbp_size();
        size += self.vel.sbp_size();
        size += self.acc.sbp_size();
        size += self.fcn.sbp_size();
        size
    }
}

/// Deprecated
///
/// This observation message has been deprecated in favor of
/// ephemeris message using floats for size reduction.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGloDepD {
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    pub common: EphemerisCommonContentDepB,
    /// Relative deviation of predicted carrier frequency from nominal
    pub gamma: f64,
    /// Correction to the SV time
    pub tau: f64,
    /// Equipment delay between L1 and L2
    pub d_tau: f64,
    /// Position of the SV at tb in PZ-90.02 coordinates system
    pub pos: [f64; 3],
    /// Velocity vector of the SV at tb in PZ-90.02 coordinates system
    pub vel: [f64; 3],
    /// Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    pub acc: [f64; 3],
    /// Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
    pub fcn: u8,
    /// Issue of data. Equal to the 7 bits of the immediate data word t_b
    pub iod: u8,
}

impl SbpParse<MsgEphemerisGloDepD> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisGloDepD> {
        Ok( MsgEphemerisGloDepD{
            sender_id: None,
            common: self.parse()?,
            gamma: self.parse()?,
            tau: self.parse()?,
            d_tau: self.parse()?,
            pos: self.parse()?,
            vel: self.parse()?,
            acc: self.parse()?,
            fcn: self.parse()?,
            iod: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisGloDepD {
    fn get_message_type(&self) -> u16 {
        136
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

impl crate::serialize::SbpSerialize for MsgEphemerisGloDepD {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.gamma.append_to_sbp_buffer(buf);
        self.tau.append_to_sbp_buffer(buf);
        self.d_tau.append_to_sbp_buffer(buf);
        self.pos.append_to_sbp_buffer(buf);
        self.vel.append_to_sbp_buffer(buf);
        self.acc.append_to_sbp_buffer(buf);
        self.fcn.append_to_sbp_buffer(buf);
        self.iod.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.gamma.sbp_size();
        size += self.tau.sbp_size();
        size += self.d_tau.sbp_size();
        size += self.pos.sbp_size();
        size += self.vel.sbp_size();
        size += self.acc.sbp_size();
        size += self.fcn.sbp_size();
        size += self.iod.sbp_size();
        size
    }
}

/// Satellite broadcast ephemeris for GPS
///
/// The ephemeris message returns a set of satellite orbit
/// parameters that is used to calculate GPS satellite position,
/// velocity, and clock offset. Please see the Navstar GPS
/// Space Segment/Navigation user interfaces (ICD-GPS-200, Table
/// 20-III) for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGPS {
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    pub common: EphemerisCommonContent,
    /// Group delay differential between L1 and L2
    pub tgd: f32,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rs: f32,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_rc: f32,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    pub c_uc: f32,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    pub c_us: f32,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    pub c_ic: f32,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    pub c_is: f32,
    /// Mean motion difference
    pub dn: f64,
    /// Mean anomaly at reference time
    pub m0: f64,
    /// Eccentricity of satellite orbit
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    pub omega0: f64,
    /// Rate of right ascension
    pub omegadot: f64,
    /// Argument of perigee
    pub w: f64,
    /// Inclination
    pub inc: f64,
    /// Inclination first derivative
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    pub af0: f32,
    /// Polynomial clock correction coefficient (clock drift)
    pub af1: f32,
    /// Polynomial clock correction coefficient (rate of clock drift)
    pub af2: f32,
    /// Clock reference
    pub toc: GPSTimeSec,
    /// Issue of ephemeris data
    pub iode: u8,
    /// Issue of clock data
    pub iodc: u16,
}

impl SbpParse<MsgEphemerisGPS> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisGPS> {
        Ok( MsgEphemerisGPS{
            sender_id: None,
            common: self.parse()?,
            tgd: self.parse()?,
            c_rs: self.parse()?,
            c_rc: self.parse()?,
            c_uc: self.parse()?,
            c_us: self.parse()?,
            c_ic: self.parse()?,
            c_is: self.parse()?,
            dn: self.parse()?,
            m0: self.parse()?,
            ecc: self.parse()?,
            sqrta: self.parse()?,
            omega0: self.parse()?,
            omegadot: self.parse()?,
            w: self.parse()?,
            inc: self.parse()?,
            inc_dot: self.parse()?,
            af0: self.parse()?,
            af1: self.parse()?,
            af2: self.parse()?,
            toc: self.parse()?,
            iode: self.parse()?,
            iodc: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisGPS {
    fn get_message_type(&self) -> u16 {
        138
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

impl crate::serialize::SbpSerialize for MsgEphemerisGPS {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.tgd.append_to_sbp_buffer(buf);
        self.c_rs.append_to_sbp_buffer(buf);
        self.c_rc.append_to_sbp_buffer(buf);
        self.c_uc.append_to_sbp_buffer(buf);
        self.c_us.append_to_sbp_buffer(buf);
        self.c_ic.append_to_sbp_buffer(buf);
        self.c_is.append_to_sbp_buffer(buf);
        self.dn.append_to_sbp_buffer(buf);
        self.m0.append_to_sbp_buffer(buf);
        self.ecc.append_to_sbp_buffer(buf);
        self.sqrta.append_to_sbp_buffer(buf);
        self.omega0.append_to_sbp_buffer(buf);
        self.omegadot.append_to_sbp_buffer(buf);
        self.w.append_to_sbp_buffer(buf);
        self.inc.append_to_sbp_buffer(buf);
        self.inc_dot.append_to_sbp_buffer(buf);
        self.af0.append_to_sbp_buffer(buf);
        self.af1.append_to_sbp_buffer(buf);
        self.af2.append_to_sbp_buffer(buf);
        self.toc.append_to_sbp_buffer(buf);
        self.iode.append_to_sbp_buffer(buf);
        self.iodc.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.tgd.sbp_size();
        size += self.c_rs.sbp_size();
        size += self.c_rc.sbp_size();
        size += self.c_uc.sbp_size();
        size += self.c_us.sbp_size();
        size += self.c_ic.sbp_size();
        size += self.c_is.sbp_size();
        size += self.dn.sbp_size();
        size += self.m0.sbp_size();
        size += self.ecc.sbp_size();
        size += self.sqrta.sbp_size();
        size += self.omega0.sbp_size();
        size += self.omegadot.sbp_size();
        size += self.w.sbp_size();
        size += self.inc.sbp_size();
        size += self.inc_dot.sbp_size();
        size += self.af0.sbp_size();
        size += self.af1.sbp_size();
        size += self.af2.sbp_size();
        size += self.toc.sbp_size();
        size += self.iode.sbp_size();
        size += self.iodc.sbp_size();
        size
    }
}

/// Satellite broadcast ephemeris for GPS
///
/// The ephemeris message returns a set of satellite orbit
/// parameters that is used to calculate GPS satellite position,
/// velocity, and clock offset. Please see the Navstar GPS
/// Space Segment/Navigation user interfaces (ICD-GPS-200, Table
/// 20-III) for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGPSDepE {
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    pub common: EphemerisCommonContentDepA,
    /// Group delay differential between L1 and L2
    pub tgd: f64,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rs: f64,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_rc: f64,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    pub c_uc: f64,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    pub c_us: f64,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    pub c_ic: f64,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    pub c_is: f64,
    /// Mean motion difference
    pub dn: f64,
    /// Mean anomaly at reference time
    pub m0: f64,
    /// Eccentricity of satellite orbit
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    pub omega0: f64,
    /// Rate of right ascension
    pub omegadot: f64,
    /// Argument of perigee
    pub w: f64,
    /// Inclination
    pub inc: f64,
    /// Inclination first derivative
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    pub af1: f64,
    /// Polynomial clock correction coefficient (rate of clock drift)
    pub af2: f64,
    /// Clock reference
    pub toc: GPSTimeDep,
    /// Issue of ephemeris data
    pub iode: u8,
    /// Issue of clock data
    pub iodc: u16,
}

impl SbpParse<MsgEphemerisGPSDepE> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisGPSDepE> {
        Ok( MsgEphemerisGPSDepE{
            sender_id: None,
            common: self.parse()?,
            tgd: self.parse()?,
            c_rs: self.parse()?,
            c_rc: self.parse()?,
            c_uc: self.parse()?,
            c_us: self.parse()?,
            c_ic: self.parse()?,
            c_is: self.parse()?,
            dn: self.parse()?,
            m0: self.parse()?,
            ecc: self.parse()?,
            sqrta: self.parse()?,
            omega0: self.parse()?,
            omegadot: self.parse()?,
            w: self.parse()?,
            inc: self.parse()?,
            inc_dot: self.parse()?,
            af0: self.parse()?,
            af1: self.parse()?,
            af2: self.parse()?,
            toc: self.parse()?,
            iode: self.parse()?,
            iodc: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisGPSDepE {
    fn get_message_type(&self) -> u16 {
        129
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

impl crate::serialize::SbpSerialize for MsgEphemerisGPSDepE {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.tgd.append_to_sbp_buffer(buf);
        self.c_rs.append_to_sbp_buffer(buf);
        self.c_rc.append_to_sbp_buffer(buf);
        self.c_uc.append_to_sbp_buffer(buf);
        self.c_us.append_to_sbp_buffer(buf);
        self.c_ic.append_to_sbp_buffer(buf);
        self.c_is.append_to_sbp_buffer(buf);
        self.dn.append_to_sbp_buffer(buf);
        self.m0.append_to_sbp_buffer(buf);
        self.ecc.append_to_sbp_buffer(buf);
        self.sqrta.append_to_sbp_buffer(buf);
        self.omega0.append_to_sbp_buffer(buf);
        self.omegadot.append_to_sbp_buffer(buf);
        self.w.append_to_sbp_buffer(buf);
        self.inc.append_to_sbp_buffer(buf);
        self.inc_dot.append_to_sbp_buffer(buf);
        self.af0.append_to_sbp_buffer(buf);
        self.af1.append_to_sbp_buffer(buf);
        self.af2.append_to_sbp_buffer(buf);
        self.toc.append_to_sbp_buffer(buf);
        self.iode.append_to_sbp_buffer(buf);
        self.iodc.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.tgd.sbp_size();
        size += self.c_rs.sbp_size();
        size += self.c_rc.sbp_size();
        size += self.c_uc.sbp_size();
        size += self.c_us.sbp_size();
        size += self.c_ic.sbp_size();
        size += self.c_is.sbp_size();
        size += self.dn.sbp_size();
        size += self.m0.sbp_size();
        size += self.ecc.sbp_size();
        size += self.sqrta.sbp_size();
        size += self.omega0.sbp_size();
        size += self.omegadot.sbp_size();
        size += self.w.sbp_size();
        size += self.inc.sbp_size();
        size += self.inc_dot.sbp_size();
        size += self.af0.sbp_size();
        size += self.af1.sbp_size();
        size += self.af2.sbp_size();
        size += self.toc.sbp_size();
        size += self.iode.sbp_size();
        size += self.iodc.sbp_size();
        size
    }
}

/// Deprecated
///
/// This observation message has been deprecated in favor of
/// ephemeris message using floats for size reduction.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisGPSDepF {
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    pub common: EphemerisCommonContentDepB,
    /// Group delay differential between L1 and L2
    pub tgd: f64,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rs: f64,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_rc: f64,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    pub c_uc: f64,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    pub c_us: f64,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    pub c_ic: f64,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    pub c_is: f64,
    /// Mean motion difference
    pub dn: f64,
    /// Mean anomaly at reference time
    pub m0: f64,
    /// Eccentricity of satellite orbit
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    pub omega0: f64,
    /// Rate of right ascension
    pub omegadot: f64,
    /// Argument of perigee
    pub w: f64,
    /// Inclination
    pub inc: f64,
    /// Inclination first derivative
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    pub af0: f64,
    /// Polynomial clock correction coefficient (clock drift)
    pub af1: f64,
    /// Polynomial clock correction coefficient (rate of clock drift)
    pub af2: f64,
    /// Clock reference
    pub toc: GPSTimeSec,
    /// Issue of ephemeris data
    pub iode: u8,
    /// Issue of clock data
    pub iodc: u16,
}

impl SbpParse<MsgEphemerisGPSDepF> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisGPSDepF> {
        Ok( MsgEphemerisGPSDepF{
            sender_id: None,
            common: self.parse()?,
            tgd: self.parse()?,
            c_rs: self.parse()?,
            c_rc: self.parse()?,
            c_uc: self.parse()?,
            c_us: self.parse()?,
            c_ic: self.parse()?,
            c_is: self.parse()?,
            dn: self.parse()?,
            m0: self.parse()?,
            ecc: self.parse()?,
            sqrta: self.parse()?,
            omega0: self.parse()?,
            omegadot: self.parse()?,
            w: self.parse()?,
            inc: self.parse()?,
            inc_dot: self.parse()?,
            af0: self.parse()?,
            af1: self.parse()?,
            af2: self.parse()?,
            toc: self.parse()?,
            iode: self.parse()?,
            iodc: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisGPSDepF {
    fn get_message_type(&self) -> u16 {
        134
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

impl crate::serialize::SbpSerialize for MsgEphemerisGPSDepF {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.tgd.append_to_sbp_buffer(buf);
        self.c_rs.append_to_sbp_buffer(buf);
        self.c_rc.append_to_sbp_buffer(buf);
        self.c_uc.append_to_sbp_buffer(buf);
        self.c_us.append_to_sbp_buffer(buf);
        self.c_ic.append_to_sbp_buffer(buf);
        self.c_is.append_to_sbp_buffer(buf);
        self.dn.append_to_sbp_buffer(buf);
        self.m0.append_to_sbp_buffer(buf);
        self.ecc.append_to_sbp_buffer(buf);
        self.sqrta.append_to_sbp_buffer(buf);
        self.omega0.append_to_sbp_buffer(buf);
        self.omegadot.append_to_sbp_buffer(buf);
        self.w.append_to_sbp_buffer(buf);
        self.inc.append_to_sbp_buffer(buf);
        self.inc_dot.append_to_sbp_buffer(buf);
        self.af0.append_to_sbp_buffer(buf);
        self.af1.append_to_sbp_buffer(buf);
        self.af2.append_to_sbp_buffer(buf);
        self.toc.append_to_sbp_buffer(buf);
        self.iode.append_to_sbp_buffer(buf);
        self.iodc.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.tgd.sbp_size();
        size += self.c_rs.sbp_size();
        size += self.c_rc.sbp_size();
        size += self.c_uc.sbp_size();
        size += self.c_us.sbp_size();
        size += self.c_ic.sbp_size();
        size += self.c_is.sbp_size();
        size += self.dn.sbp_size();
        size += self.m0.sbp_size();
        size += self.ecc.sbp_size();
        size += self.sqrta.sbp_size();
        size += self.omega0.sbp_size();
        size += self.omegadot.sbp_size();
        size += self.w.sbp_size();
        size += self.inc.sbp_size();
        size += self.inc_dot.sbp_size();
        size += self.af0.sbp_size();
        size += self.af1.sbp_size();
        size += self.af2.sbp_size();
        size += self.toc.sbp_size();
        size += self.iode.sbp_size();
        size += self.iodc.sbp_size();
        size
    }
}

/// Satellite broadcast ephemeris for QZSS
///
/// The ephemeris message returns a set of satellite orbit
/// parameters that is used to calculate QZSS satellite position,
/// velocity, and clock offset.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisQzss {
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    pub common: EphemerisCommonContent,
    /// Group delay differential between L1 and L2
    pub tgd: f32,
    /// Amplitude of the sine harmonic correction term to the orbit radius
    pub c_rs: f32,
    /// Amplitude of the cosine harmonic correction term to the orbit radius
    pub c_rc: f32,
    /// Amplitude of the cosine harmonic correction term to the argument of
    /// latitude
    pub c_uc: f32,
    /// Amplitude of the sine harmonic correction term to the argument of
    /// latitude
    pub c_us: f32,
    /// Amplitude of the cosine harmonic correction term to the angle of
    /// inclination
    pub c_ic: f32,
    /// Amplitude of the sine harmonic correction term to the angle of
    /// inclination
    pub c_is: f32,
    /// Mean motion difference
    pub dn: f64,
    /// Mean anomaly at reference time
    pub m0: f64,
    /// Eccentricity of satellite orbit
    pub ecc: f64,
    /// Square root of the semi-major axis of orbit
    pub sqrta: f64,
    /// Longitude of ascending node of orbit plane at weekly epoch
    pub omega0: f64,
    /// Rate of right ascension
    pub omegadot: f64,
    /// Argument of perigee
    pub w: f64,
    /// Inclination
    pub inc: f64,
    /// Inclination first derivative
    pub inc_dot: f64,
    /// Polynomial clock correction coefficient (clock bias)
    pub af0: f32,
    /// Polynomial clock correction coefficient (clock drift)
    pub af1: f32,
    /// Polynomial clock correction coefficient (rate of clock drift)
    pub af2: f32,
    /// Clock reference
    pub toc: GPSTimeSec,
    /// Issue of ephemeris data
    pub iode: u8,
    /// Issue of clock data
    pub iodc: u16,
}

impl SbpParse<MsgEphemerisQzss> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisQzss> {
        Ok( MsgEphemerisQzss{
            sender_id: None,
            common: self.parse()?,
            tgd: self.parse()?,
            c_rs: self.parse()?,
            c_rc: self.parse()?,
            c_uc: self.parse()?,
            c_us: self.parse()?,
            c_ic: self.parse()?,
            c_is: self.parse()?,
            dn: self.parse()?,
            m0: self.parse()?,
            ecc: self.parse()?,
            sqrta: self.parse()?,
            omega0: self.parse()?,
            omegadot: self.parse()?,
            w: self.parse()?,
            inc: self.parse()?,
            inc_dot: self.parse()?,
            af0: self.parse()?,
            af1: self.parse()?,
            af2: self.parse()?,
            toc: self.parse()?,
            iode: self.parse()?,
            iodc: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisQzss {
    fn get_message_type(&self) -> u16 {
        142
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

impl crate::serialize::SbpSerialize for MsgEphemerisQzss {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.tgd.append_to_sbp_buffer(buf);
        self.c_rs.append_to_sbp_buffer(buf);
        self.c_rc.append_to_sbp_buffer(buf);
        self.c_uc.append_to_sbp_buffer(buf);
        self.c_us.append_to_sbp_buffer(buf);
        self.c_ic.append_to_sbp_buffer(buf);
        self.c_is.append_to_sbp_buffer(buf);
        self.dn.append_to_sbp_buffer(buf);
        self.m0.append_to_sbp_buffer(buf);
        self.ecc.append_to_sbp_buffer(buf);
        self.sqrta.append_to_sbp_buffer(buf);
        self.omega0.append_to_sbp_buffer(buf);
        self.omegadot.append_to_sbp_buffer(buf);
        self.w.append_to_sbp_buffer(buf);
        self.inc.append_to_sbp_buffer(buf);
        self.inc_dot.append_to_sbp_buffer(buf);
        self.af0.append_to_sbp_buffer(buf);
        self.af1.append_to_sbp_buffer(buf);
        self.af2.append_to_sbp_buffer(buf);
        self.toc.append_to_sbp_buffer(buf);
        self.iode.append_to_sbp_buffer(buf);
        self.iodc.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.tgd.sbp_size();
        size += self.c_rs.sbp_size();
        size += self.c_rc.sbp_size();
        size += self.c_uc.sbp_size();
        size += self.c_us.sbp_size();
        size += self.c_ic.sbp_size();
        size += self.c_is.sbp_size();
        size += self.dn.sbp_size();
        size += self.m0.sbp_size();
        size += self.ecc.sbp_size();
        size += self.sqrta.sbp_size();
        size += self.omega0.sbp_size();
        size += self.omegadot.sbp_size();
        size += self.w.sbp_size();
        size += self.inc.sbp_size();
        size += self.inc_dot.sbp_size();
        size += self.af0.sbp_size();
        size += self.af1.sbp_size();
        size += self.af2.sbp_size();
        size += self.toc.sbp_size();
        size += self.iode.sbp_size();
        size += self.iodc.sbp_size();
        size
    }
}

#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisSbas {
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    pub common: EphemerisCommonContent,
    /// Position of the GEO at time toe
    pub pos: [f64; 3],
    /// Velocity of the GEO at time toe
    pub vel: [f32; 3],
    /// Acceleration of the GEO at time toe
    pub acc: [f32; 3],
    /// Time offset of the GEO clock w.r.t. SBAS Network Time
    pub a_gf0: f32,
    /// Drift of the GEO clock w.r.t. SBAS Network Time
    pub a_gf1: f32,
}

impl SbpParse<MsgEphemerisSbas> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisSbas> {
        Ok( MsgEphemerisSbas{
            sender_id: None,
            common: self.parse()?,
            pos: self.parse()?,
            vel: self.parse()?,
            acc: self.parse()?,
            a_gf0: self.parse()?,
            a_gf1: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisSbas {
    fn get_message_type(&self) -> u16 {
        140
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

impl crate::serialize::SbpSerialize for MsgEphemerisSbas {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.pos.append_to_sbp_buffer(buf);
        self.vel.append_to_sbp_buffer(buf);
        self.acc.append_to_sbp_buffer(buf);
        self.a_gf0.append_to_sbp_buffer(buf);
        self.a_gf1.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.pos.sbp_size();
        size += self.vel.sbp_size();
        size += self.acc.sbp_size();
        size += self.a_gf0.sbp_size();
        size += self.a_gf1.sbp_size();
        size
    }
}

#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisSbasDepA {
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    pub common: EphemerisCommonContentDepA,
    /// Position of the GEO at time toe
    pub pos: [f64; 3],
    /// Velocity of the GEO at time toe
    pub vel: [f64; 3],
    /// Acceleration of the GEO at time toe
    pub acc: [f64; 3],
    /// Time offset of the GEO clock w.r.t. SBAS Network Time
    pub a_gf0: f64,
    /// Drift of the GEO clock w.r.t. SBAS Network Time
    pub a_gf1: f64,
}

impl SbpParse<MsgEphemerisSbasDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisSbasDepA> {
        Ok( MsgEphemerisSbasDepA{
            sender_id: None,
            common: self.parse()?,
            pos: self.parse()?,
            vel: self.parse()?,
            acc: self.parse()?,
            a_gf0: self.parse()?,
            a_gf1: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisSbasDepA {
    fn get_message_type(&self) -> u16 {
        130
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

impl crate::serialize::SbpSerialize for MsgEphemerisSbasDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.pos.append_to_sbp_buffer(buf);
        self.vel.append_to_sbp_buffer(buf);
        self.acc.append_to_sbp_buffer(buf);
        self.a_gf0.append_to_sbp_buffer(buf);
        self.a_gf1.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.pos.sbp_size();
        size += self.vel.sbp_size();
        size += self.acc.sbp_size();
        size += self.a_gf0.sbp_size();
        size += self.a_gf1.sbp_size();
        size
    }
}

/// Deprecated
///
/// This observation message has been deprecated in favor of
/// ephemeris message using floats for size reduction.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgEphemerisSbasDepB {
    pub sender_id: Option<u16>,
    /// Values common for all ephemeris types
    pub common: EphemerisCommonContentDepB,
    /// Position of the GEO at time toe
    pub pos: [f64; 3],
    /// Velocity of the GEO at time toe
    pub vel: [f64; 3],
    /// Acceleration of the GEO at time toe
    pub acc: [f64; 3],
    /// Time offset of the GEO clock w.r.t. SBAS Network Time
    pub a_gf0: f64,
    /// Drift of the GEO clock w.r.t. SBAS Network Time
    pub a_gf1: f64,
}

impl SbpParse<MsgEphemerisSbasDepB> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgEphemerisSbasDepB> {
        Ok( MsgEphemerisSbasDepB{
            sender_id: None,
            common: self.parse()?,
            pos: self.parse()?,
            vel: self.parse()?,
            acc: self.parse()?,
            a_gf0: self.parse()?,
            a_gf1: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgEphemerisSbasDepB {
    fn get_message_type(&self) -> u16 {
        132
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

impl crate::serialize::SbpSerialize for MsgEphemerisSbasDepB {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.common.append_to_sbp_buffer(buf);
        self.pos.append_to_sbp_buffer(buf);
        self.vel.append_to_sbp_buffer(buf);
        self.acc.append_to_sbp_buffer(buf);
        self.a_gf0.append_to_sbp_buffer(buf);
        self.a_gf1.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.common.sbp_size();
        size += self.pos.sbp_size();
        size += self.vel.sbp_size();
        size += self.acc.sbp_size();
        size += self.a_gf0.sbp_size();
        size += self.a_gf1.sbp_size();
        size
    }
}

/// GLONASS L1/L2 Code-Phase biases
///
/// The GLONASS L1/L2 Code-Phase biases allows to perform
/// GPS+GLONASS integer ambiguity resolution for baselines
/// with mixed receiver types (e.g. receiver of different
/// manufacturers)
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgGloBiases {
    pub sender_id: Option<u16>,
    /// GLONASS FDMA signals mask
    pub mask: u8,
    /// GLONASS L1 C/A Code-Phase Bias
    pub l1ca_bias: i16,
    /// GLONASS L1 P Code-Phase Bias
    pub l1p_bias: i16,
    /// GLONASS L2 C/A Code-Phase Bias
    pub l2ca_bias: i16,
    /// GLONASS L2 P Code-Phase Bias
    pub l2p_bias: i16,
}

impl SbpParse<MsgGloBiases> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgGloBiases> {
        Ok( MsgGloBiases{
            sender_id: None,
            mask: self.parse()?,
            l1ca_bias: self.parse()?,
            l1p_bias: self.parse()?,
            l2ca_bias: self.parse()?,
            l2p_bias: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgGloBiases {
    fn get_message_type(&self) -> u16 {
        117
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

impl crate::serialize::SbpSerialize for MsgGloBiases {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.mask.append_to_sbp_buffer(buf);
        self.l1ca_bias.append_to_sbp_buffer(buf);
        self.l1p_bias.append_to_sbp_buffer(buf);
        self.l2ca_bias.append_to_sbp_buffer(buf);
        self.l2p_bias.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.mask.sbp_size();
        size += self.l1ca_bias.sbp_size();
        size += self.l1p_bias.sbp_size();
        size += self.l2ca_bias.sbp_size();
        size += self.l2p_bias.sbp_size();
        size
    }
}

#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgGnssCapb {
    pub sender_id: Option<u16>,
    /// Navigation Message Correction Table Validity Time
    pub t_nmct: GPSTimeSec,
    /// GNSS capabilities masks
    pub gc: GnssCapb,
}

impl SbpParse<MsgGnssCapb> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgGnssCapb> {
        Ok( MsgGnssCapb{
            sender_id: None,
            t_nmct: self.parse()?,
            gc: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgGnssCapb {
    fn get_message_type(&self) -> u16 {
        150
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

impl crate::serialize::SbpSerialize for MsgGnssCapb {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.t_nmct.append_to_sbp_buffer(buf);
        self.gc.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.t_nmct.sbp_size();
        size += self.gc.sbp_size();
        size
    }
}

/// Group Delay
///
/// Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgGroupDelay {
    pub sender_id: Option<u16>,
    /// Data Predict Time of Week
    pub t_op: GPSTimeSec,
    /// GNSS signal identifier
    pub sid: GnssSignal,
    /// bit-field indicating validity of the values, LSB indicating tgd validity
    /// etc. 1 = value is valid, 0 = value is not valid.
    pub valid: u8,
    pub tgd: i16,
    pub isc_l1ca: i16,
    pub isc_l2c: i16,
}

impl SbpParse<MsgGroupDelay> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgGroupDelay> {
        Ok( MsgGroupDelay{
            sender_id: None,
            t_op: self.parse()?,
            sid: self.parse()?,
            valid: self.parse()?,
            tgd: self.parse()?,
            isc_l1ca: self.parse()?,
            isc_l2c: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgGroupDelay {
    fn get_message_type(&self) -> u16 {
        148
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

impl crate::serialize::SbpSerialize for MsgGroupDelay {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.t_op.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.valid.append_to_sbp_buffer(buf);
        self.tgd.append_to_sbp_buffer(buf);
        self.isc_l1ca.append_to_sbp_buffer(buf);
        self.isc_l2c.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.t_op.sbp_size();
        size += self.sid.sbp_size();
        size += self.valid.sbp_size();
        size += self.tgd.sbp_size();
        size += self.isc_l1ca.sbp_size();
        size += self.isc_l2c.sbp_size();
        size
    }
}

/// Group Delay
///
/// Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgGroupDelayDepA {
    pub sender_id: Option<u16>,
    /// Data Predict Time of Week
    pub t_op: GPSTimeDep,
    /// Satellite number
    pub prn: u8,
    /// bit-field indicating validity of the values, LSB indicating tgd validity
    /// etc. 1 = value is valid, 0 = value is not valid.
    pub valid: u8,
    pub tgd: i16,
    pub isc_l1ca: i16,
    pub isc_l2c: i16,
}

impl SbpParse<MsgGroupDelayDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgGroupDelayDepA> {
        Ok( MsgGroupDelayDepA{
            sender_id: None,
            t_op: self.parse()?,
            prn: self.parse()?,
            valid: self.parse()?,
            tgd: self.parse()?,
            isc_l1ca: self.parse()?,
            isc_l2c: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgGroupDelayDepA {
    fn get_message_type(&self) -> u16 {
        146
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

impl crate::serialize::SbpSerialize for MsgGroupDelayDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.t_op.append_to_sbp_buffer(buf);
        self.prn.append_to_sbp_buffer(buf);
        self.valid.append_to_sbp_buffer(buf);
        self.tgd.append_to_sbp_buffer(buf);
        self.isc_l1ca.append_to_sbp_buffer(buf);
        self.isc_l2c.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.t_op.sbp_size();
        size += self.prn.sbp_size();
        size += self.valid.sbp_size();
        size += self.tgd.sbp_size();
        size += self.isc_l1ca.sbp_size();
        size += self.isc_l2c.sbp_size();
        size
    }
}

/// Group Delay
///
/// Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgGroupDelayDepB {
    pub sender_id: Option<u16>,
    /// Data Predict Time of Week
    pub t_op: GPSTimeSec,
    /// GNSS signal identifier
    pub sid: GnssSignalDep,
    /// bit-field indicating validity of the values, LSB indicating tgd validity
    /// etc. 1 = value is valid, 0 = value is not valid.
    pub valid: u8,
    pub tgd: i16,
    pub isc_l1ca: i16,
    pub isc_l2c: i16,
}

impl SbpParse<MsgGroupDelayDepB> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgGroupDelayDepB> {
        Ok( MsgGroupDelayDepB{
            sender_id: None,
            t_op: self.parse()?,
            sid: self.parse()?,
            valid: self.parse()?,
            tgd: self.parse()?,
            isc_l1ca: self.parse()?,
            isc_l2c: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgGroupDelayDepB {
    fn get_message_type(&self) -> u16 {
        147
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

impl crate::serialize::SbpSerialize for MsgGroupDelayDepB {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.t_op.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.valid.append_to_sbp_buffer(buf);
        self.tgd.append_to_sbp_buffer(buf);
        self.isc_l1ca.append_to_sbp_buffer(buf);
        self.isc_l2c.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.t_op.sbp_size();
        size += self.sid.sbp_size();
        size += self.valid.sbp_size();
        size += self.tgd.sbp_size();
        size += self.isc_l1ca.sbp_size();
        size += self.isc_l2c.sbp_size();
        size
    }
}

/// Iono corrections
///
/// The ionospheric parameters which allow the "L1 only" or "L2 only" user to
/// utilize the ionospheric model for computation of the ionospheric delay.
/// Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgIono {
    pub sender_id: Option<u16>,
    /// Navigation Message Correction Table Valitidy Time
    pub t_nmct: GPSTimeSec,
    pub a0: f64,
    pub a1: f64,
    pub a2: f64,
    pub a3: f64,
    pub b0: f64,
    pub b1: f64,
    pub b2: f64,
    pub b3: f64,
}

impl SbpParse<MsgIono> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgIono> {
        Ok( MsgIono{
            sender_id: None,
            t_nmct: self.parse()?,
            a0: self.parse()?,
            a1: self.parse()?,
            a2: self.parse()?,
            a3: self.parse()?,
            b0: self.parse()?,
            b1: self.parse()?,
            b2: self.parse()?,
            b3: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgIono {
    fn get_message_type(&self) -> u16 {
        144
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

impl crate::serialize::SbpSerialize for MsgIono {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.t_nmct.append_to_sbp_buffer(buf);
        self.a0.append_to_sbp_buffer(buf);
        self.a1.append_to_sbp_buffer(buf);
        self.a2.append_to_sbp_buffer(buf);
        self.a3.append_to_sbp_buffer(buf);
        self.b0.append_to_sbp_buffer(buf);
        self.b1.append_to_sbp_buffer(buf);
        self.b2.append_to_sbp_buffer(buf);
        self.b3.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.t_nmct.sbp_size();
        size += self.a0.sbp_size();
        size += self.a1.sbp_size();
        size += self.a2.sbp_size();
        size += self.a3.sbp_size();
        size += self.b0.sbp_size();
        size += self.b1.sbp_size();
        size += self.b2.sbp_size();
        size += self.b3.sbp_size();
        size
    }
}

/// GPS satellite observations
///
/// The GPS observations message reports all the raw pseudorange and
/// carrier phase observations for the satellites being tracked by
/// the device. Carrier phase observation here is represented as a
/// 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
/// whole cycles and 8-bits of fractional cycles). The observations
/// are be interoperable with 3rd party receivers and conform
/// with typical RTCMv3 GNSS observations.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgObs {
    pub sender_id: Option<u16>,
    /// Header of a GPS observation message
    pub header: ObservationHeader,
    /// Pseudorange and carrier phase observation for a satellite being tracked.
    pub obs: Vec<PackedObsContent>,
}

impl SbpParse<MsgObs> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgObs> {
        Ok( MsgObs{
            sender_id: None,
            header: self.parse()?,
            obs: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgObs {
    fn get_message_type(&self) -> u16 {
        74
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

impl crate::serialize::SbpSerialize for MsgObs {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.header.append_to_sbp_buffer(buf);
        self.obs.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.header.sbp_size();
        size += self.obs.sbp_size();
        size
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgObsDepA {
    pub sender_id: Option<u16>,
    /// Header of a GPS observation message
    pub header: ObservationHeaderDep,
    /// Pseudorange and carrier phase observation for a satellite being tracked.
    pub obs: Vec<PackedObsContentDepA>,
}

impl SbpParse<MsgObsDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgObsDepA> {
        Ok( MsgObsDepA{
            sender_id: None,
            header: self.parse()?,
            obs: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgObsDepA {
    fn get_message_type(&self) -> u16 {
        69
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

impl crate::serialize::SbpSerialize for MsgObsDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.header.append_to_sbp_buffer(buf);
        self.obs.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.header.sbp_size();
        size += self.obs.sbp_size();
        size
    }
}

/// Deprecated
///
/// This observation message has been deprecated in favor of
/// observations that are more interoperable. This message
/// should be used for observations referenced to
/// a nominal pseudorange which are not interoperable with
/// most 3rd party GNSS receievers or typical RTCMv3
/// observations.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgObsDepB {
    pub sender_id: Option<u16>,
    /// Header of a GPS observation message
    pub header: ObservationHeaderDep,
    /// Pseudorange and carrier phase observation for a satellite being tracked.
    pub obs: Vec<PackedObsContentDepB>,
}

impl SbpParse<MsgObsDepB> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgObsDepB> {
        Ok( MsgObsDepB{
            sender_id: None,
            header: self.parse()?,
            obs: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgObsDepB {
    fn get_message_type(&self) -> u16 {
        67
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

impl crate::serialize::SbpSerialize for MsgObsDepB {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.header.append_to_sbp_buffer(buf);
        self.obs.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.header.sbp_size();
        size += self.obs.sbp_size();
        size
    }
}

/// Deprecated
///
/// The GPS observations message reports all the raw pseudorange and
/// carrier phase observations for the satellites being tracked by
/// the device. Carrier phase observation here is represented as a
/// 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
/// whole cycles and 8-bits of fractional cycles). The observations
/// are interoperable with 3rd party receivers and conform
/// with typical RTCMv3 GNSS observations.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgObsDepC {
    pub sender_id: Option<u16>,
    /// Header of a GPS observation message
    pub header: ObservationHeaderDep,
    /// Pseudorange and carrier phase observation for a satellite being tracked.
    pub obs: Vec<PackedObsContentDepC>,
}

impl SbpParse<MsgObsDepC> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgObsDepC> {
        Ok( MsgObsDepC{
            sender_id: None,
            header: self.parse()?,
            obs: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgObsDepC {
    fn get_message_type(&self) -> u16 {
        73
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

impl crate::serialize::SbpSerialize for MsgObsDepC {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.header.append_to_sbp_buffer(buf);
        self.obs.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.header.sbp_size();
        size += self.obs.sbp_size();
        size
    }
}

/// OSR corrections
///
/// The OSR message contains network corrections in an observation-like format
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgOsr {
    pub sender_id: Option<u16>,
    /// Header of a GPS observation message
    pub header: ObservationHeader,
    /// Network correction for a satellite signal.
    pub obs: Vec<PackedOsrContent>,
}

impl SbpParse<MsgOsr> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgOsr> {
        Ok( MsgOsr{
            sender_id: None,
            header: self.parse()?,
            obs: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgOsr {
    fn get_message_type(&self) -> u16 {
        1600
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

impl crate::serialize::SbpSerialize for MsgOsr {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.header.append_to_sbp_buffer(buf);
        self.obs.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.header.sbp_size();
        size += self.obs.sbp_size();
        size
    }
}

/// Satellite azimuths and elevations
///
/// Azimuth and elevation angles of all the visible satellites
/// that the device does have ephemeris or almanac for.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSvAzEl {
    pub sender_id: Option<u16>,
    /// Azimuth and elevation per satellite
    pub azel: Vec<SvAzEl>,
}

impl SbpParse<MsgSvAzEl> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSvAzEl> {
        Ok( MsgSvAzEl{
            sender_id: None,
            azel: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgSvAzEl {
    fn get_message_type(&self) -> u16 {
        151
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

impl crate::serialize::SbpSerialize for MsgSvAzEl {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.azel.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.azel.sbp_size();
        size
    }
}

/// L2C capability mask
///
/// Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSvConfigurationGPSDep {
    pub sender_id: Option<u16>,
    /// Navigation Message Correction Table Valitidy Time
    pub t_nmct: GPSTimeSec,
    /// L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
    pub l2c_mask: u32,
}

impl SbpParse<MsgSvConfigurationGPSDep> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSvConfigurationGPSDep> {
        Ok( MsgSvConfigurationGPSDep{
            sender_id: None,
            t_nmct: self.parse()?,
            l2c_mask: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgSvConfigurationGPSDep {
    fn get_message_type(&self) -> u16 {
        145
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

impl crate::serialize::SbpSerialize for MsgSvConfigurationGPSDep {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.t_nmct.append_to_sbp_buffer(buf);
        self.l2c_mask.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.t_nmct.sbp_size();
        size += self.l2c_mask.sbp_size();
        size
    }
}

/// Header for observation message.
///
/// Header of a GNSS observation message.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct ObservationHeader {
    /// GNSS time of this observation
    pub t: GPSTime,
    /// Total number of observations. First nibble is the size of the sequence
    /// (n), second nibble is the zero-indexed counter (ith packet of n)
    pub n_obs: u8,
}

impl SbpParse<ObservationHeader> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<ObservationHeader> {
        Ok( ObservationHeader{
            t: self.parse()?,
            n_obs: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for ObservationHeader {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.t.append_to_sbp_buffer(buf);
        self.n_obs.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.t.sbp_size();
        size += self.n_obs.sbp_size();
        size
    }
}

/// Header for observation message.
///
/// Header of a GPS observation message.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct ObservationHeaderDep {
    /// GPS time of this observation
    pub t: GPSTimeDep,
    /// Total number of observations. First nibble is the size of the sequence
    /// (n), second nibble is the zero-indexed counter (ith packet of n)
    pub n_obs: u8,
}

impl SbpParse<ObservationHeaderDep> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<ObservationHeaderDep> {
        Ok( ObservationHeaderDep{
            t: self.parse()?,
            n_obs: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for ObservationHeaderDep {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.t.append_to_sbp_buffer(buf);
        self.n_obs.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.t.sbp_size();
        size += self.n_obs.sbp_size();
        size
    }
}

/// GNSS observations for a particular satellite signal.
///
/// Pseudorange and carrier phase observation for a satellite being tracked.
/// The observations are interoperable with 3rd party receivers and conform with
/// typical RTCM 3.1 message GPS/GLO observations.
///
/// Carrier phase observations are not guaranteed to be aligned to the RINEX 3
/// or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are currently
/// peformed.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct PackedObsContent {
    /// Pseudorange observation
    pub P: u32,
    /// Carrier phase observation with typical sign convention.
    pub L: CarrierPhase,
    /// Doppler observation with typical sign convention.
    pub D: Doppler,
    /// Carrier-to-Noise density.  Zero implies invalid cn0.
    pub cn0: u8,
    /// Lock timer. This value gives an indication of the time for which a
    /// signal has maintained continuous phase lock. Whenever a signal has lost
    /// and regained lock, this value is reset to zero. It is encoded according
    /// to DF402 from the RTCM 10403.2 Amendment 2 specification.  Valid values
    /// range from 0 to 15 and the most significant nibble is reserved for
    /// future use.
    pub lock: u8,
    /// Measurement status flags. A bit field of flags providing the status of
    /// this observation.  If this field is 0 it means only the Cn0 estimate for
    /// the signal is valid.
    pub flags: u8,
    /// GNSS signal identifier (16 bit)
    pub sid: GnssSignal,
}

impl SbpParse<PackedObsContent> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<PackedObsContent> {
        Ok( PackedObsContent{
            P: self.parse()?,
            L: self.parse()?,
            D: self.parse()?,
            cn0: self.parse()?,
            lock: self.parse()?,
            flags: self.parse()?,
            sid: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for PackedObsContent {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.P.append_to_sbp_buffer(buf);
        self.L.append_to_sbp_buffer(buf);
        self.D.append_to_sbp_buffer(buf);
        self.cn0.append_to_sbp_buffer(buf);
        self.lock.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.P.sbp_size();
        size += self.L.sbp_size();
        size += self.D.sbp_size();
        size += self.cn0.sbp_size();
        size += self.lock.sbp_size();
        size += self.flags.sbp_size();
        size += self.sid.sbp_size();
        size
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct PackedObsContentDepA {
    /// Pseudorange observation
    pub P: u32,
    /// Carrier phase observation with opposite sign from typical convention
    pub L: CarrierPhaseDepA,
    /// Carrier-to-Noise density
    pub cn0: u8,
    /// Lock indicator. This value changes whenever a satellite signal has lost
    /// and regained lock, indicating that the carrier phase ambiguity may have
    /// changed.
    pub lock: u16,
    /// PRN-1 identifier of the satellite signal
    pub prn: u8,
}

impl SbpParse<PackedObsContentDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<PackedObsContentDepA> {
        Ok( PackedObsContentDepA{
            P: self.parse()?,
            L: self.parse()?,
            cn0: self.parse()?,
            lock: self.parse()?,
            prn: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for PackedObsContentDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.P.append_to_sbp_buffer(buf);
        self.L.append_to_sbp_buffer(buf);
        self.cn0.append_to_sbp_buffer(buf);
        self.lock.append_to_sbp_buffer(buf);
        self.prn.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.P.sbp_size();
        size += self.L.sbp_size();
        size += self.cn0.sbp_size();
        size += self.lock.sbp_size();
        size += self.prn.sbp_size();
        size
    }
}

/// GPS observations for a particular satellite signal.
///
/// Pseudorange and carrier phase observation for a satellite being
/// tracked.  Pseudoranges are referenced to a nominal pseudorange.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct PackedObsContentDepB {
    /// Pseudorange observation
    pub P: u32,
    /// Carrier phase observation with opposite sign from typical convention.
    pub L: CarrierPhaseDepA,
    /// Carrier-to-Noise density
    pub cn0: u8,
    /// Lock indicator. This value changes whenever a satellite signal has lost
    /// and regained lock, indicating that the carrier phase ambiguity may have
    /// changed.
    pub lock: u16,
    /// GNSS signal identifier
    pub sid: GnssSignalDep,
}

impl SbpParse<PackedObsContentDepB> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<PackedObsContentDepB> {
        Ok( PackedObsContentDepB{
            P: self.parse()?,
            L: self.parse()?,
            cn0: self.parse()?,
            lock: self.parse()?,
            sid: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for PackedObsContentDepB {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.P.append_to_sbp_buffer(buf);
        self.L.append_to_sbp_buffer(buf);
        self.cn0.append_to_sbp_buffer(buf);
        self.lock.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.P.sbp_size();
        size += self.L.sbp_size();
        size += self.cn0.sbp_size();
        size += self.lock.sbp_size();
        size += self.sid.sbp_size();
        size
    }
}

/// GPS observations for a particular satellite signal.
///
/// Pseudorange and carrier phase observation for a satellite being
/// tracked. The observations are be interoperable with 3rd party
/// receivers and conform with typical RTCMv3 GNSS observations.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct PackedObsContentDepC {
    /// Pseudorange observation
    pub P: u32,
    /// Carrier phase observation with typical sign convention.
    pub L: CarrierPhase,
    /// Carrier-to-Noise density
    pub cn0: u8,
    /// Lock indicator. This value changes whenever a satellite signal has lost
    /// and regained lock, indicating that the carrier phase ambiguity may have
    /// changed.
    pub lock: u16,
    /// GNSS signal identifier
    pub sid: GnssSignalDep,
}

impl SbpParse<PackedObsContentDepC> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<PackedObsContentDepC> {
        Ok( PackedObsContentDepC{
            P: self.parse()?,
            L: self.parse()?,
            cn0: self.parse()?,
            lock: self.parse()?,
            sid: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for PackedObsContentDepC {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.P.append_to_sbp_buffer(buf);
        self.L.append_to_sbp_buffer(buf);
        self.cn0.append_to_sbp_buffer(buf);
        self.lock.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.P.sbp_size();
        size += self.L.sbp_size();
        size += self.cn0.sbp_size();
        size += self.lock.sbp_size();
        size += self.sid.sbp_size();
        size
    }
}

/// Network correction for a particular satellite signal.
///
/// Pseudorange and carrier phase network corrections for a satellite signal.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct PackedOsrContent {
    /// Pseudorange observation
    pub P: u32,
    /// Carrier phase observation with typical sign convention.
    pub L: CarrierPhase,
    /// Lock timer. This value gives an indication of the time for which a
    /// signal has maintained continuous phase lock. Whenever a signal has lost
    /// and regained lock, this value is reset to zero. It is encoded according
    /// to DF402 from the RTCM 10403.2 Amendment 2 specification.  Valid values
    /// range from 0 to 15 and the most significant nibble is reserved for
    /// future use.
    pub lock: u8,
    /// Correction flags.
    pub flags: u8,
    /// GNSS signal identifier (16 bit)
    pub sid: GnssSignal,
    /// Slant ionospheric correction standard deviation
    pub iono_std: u16,
    /// Slant tropospheric correction standard deviation
    pub tropo_std: u16,
    /// Orbit/clock/bias correction projected on range standard deviation
    pub range_std: u16,
}

impl SbpParse<PackedOsrContent> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<PackedOsrContent> {
        Ok( PackedOsrContent{
            P: self.parse()?,
            L: self.parse()?,
            lock: self.parse()?,
            flags: self.parse()?,
            sid: self.parse()?,
            iono_std: self.parse()?,
            tropo_std: self.parse()?,
            range_std: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for PackedOsrContent {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.P.append_to_sbp_buffer(buf);
        self.L.append_to_sbp_buffer(buf);
        self.lock.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.iono_std.append_to_sbp_buffer(buf);
        self.tropo_std.append_to_sbp_buffer(buf);
        self.range_std.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.P.sbp_size();
        size += self.L.sbp_size();
        size += self.lock.sbp_size();
        size += self.flags.sbp_size();
        size += self.sid.sbp_size();
        size += self.iono_std.sbp_size();
        size += self.tropo_std.sbp_size();
        size += self.range_std.sbp_size();
        size
    }
}

/// Satellite azimuth and elevation.
///
/// Satellite azimuth and elevation.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct SvAzEl {
    /// GNSS signal identifier
    pub sid: GnssSignal,
    /// Azimuth angle (range 0..179)
    pub az: u8,
    /// Elevation angle (range -90..90)
    pub el: i8,
}

impl SbpParse<SvAzEl> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<SvAzEl> {
        Ok( SvAzEl{
            sid: self.parse()?,
            az: self.parse()?,
            el: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for SvAzEl {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sid.append_to_sbp_buffer(buf);
        self.az.append_to_sbp_buffer(buf);
        self.el.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sid.sbp_size();
        size += self.az.sbp_size();
        size += self.el.sbp_size();
        size
    }
}
