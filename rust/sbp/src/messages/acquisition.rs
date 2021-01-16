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
// Automatically generated from yaml/swiftnav/sbp/acquisition.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Satellite acquisition messages from the device.

#[cfg(feature = "sbp_serde")]
use serde::{Deserialize, Serialize};

use super::gnss::*;
#[allow(unused_imports)]
use crate::{parser::SbpParse, BoundedSbpString, UnboundedSbpString};

/// Acq perfomance measurement and debug
///
/// Profile for a specific SV for debugging purposes
/// The message describes SV profile during acquisition time.
/// The message is used to debug and measure the performance.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct AcqSvProfile {
    /// SV search job type (deep, fallback, etc)
    pub job_type: u8,
    /// Acquisition status 1 is Success, 0 is Failure
    pub status: u8,
    /// CN0 value. Only valid if status is '1'
    pub cn0: u16,
    /// Acquisition integration time
    pub int_time: u8,
    /// GNSS signal for which acquisition was attempted
    pub sid: GnssSignal,
    /// Acq frequency bin width
    pub bin_width: u16,
    /// Timestamp of the job complete event
    pub timestamp: u32,
    /// Time spent to search for sid.code
    pub time_spent: u32,
    /// Doppler range lowest frequency
    pub cf_min: i32,
    /// Doppler range highest frequency
    pub cf_max: i32,
    /// Doppler value of detected peak. Only valid if status is '1'
    pub cf: i32,
    /// Codephase of detected peak. Only valid if status is '1'
    pub cp: u32,
}

impl SbpParse<AcqSvProfile> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<AcqSvProfile> {
        Ok( AcqSvProfile{
            job_type: self.parse()?,
            status: self.parse()?,
            cn0: self.parse()?,
            int_time: self.parse()?,
            sid: self.parse()?,
            bin_width: self.parse()?,
            timestamp: self.parse()?,
            time_spent: self.parse()?,
            cf_min: self.parse()?,
            cf_max: self.parse()?,
            cf: self.parse()?,
            cp: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for AcqSvProfile {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.job_type.append_to_sbp_buffer(buf);
        self.status.append_to_sbp_buffer(buf);
        self.cn0.append_to_sbp_buffer(buf);
        self.int_time.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.bin_width.append_to_sbp_buffer(buf);
        self.timestamp.append_to_sbp_buffer(buf);
        self.time_spent.append_to_sbp_buffer(buf);
        self.cf_min.append_to_sbp_buffer(buf);
        self.cf_max.append_to_sbp_buffer(buf);
        self.cf.append_to_sbp_buffer(buf);
        self.cp.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.job_type.sbp_size();
        size += self.status.sbp_size();
        size += self.cn0.sbp_size();
        size += self.int_time.sbp_size();
        size += self.sid.sbp_size();
        size += self.bin_width.sbp_size();
        size += self.timestamp.sbp_size();
        size += self.time_spent.sbp_size();
        size += self.cf_min.sbp_size();
        size += self.cf_max.sbp_size();
        size += self.cf.sbp_size();
        size += self.cp.sbp_size();
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
pub struct AcqSvProfileDep {
    /// SV search job type (deep, fallback, etc)
    pub job_type: u8,
    /// Acquisition status 1 is Success, 0 is Failure
    pub status: u8,
    /// CN0 value. Only valid if status is '1'
    pub cn0: u16,
    /// Acquisition integration time
    pub int_time: u8,
    /// GNSS signal for which acquisition was attempted
    pub sid: GnssSignalDep,
    /// Acq frequency bin width
    pub bin_width: u16,
    /// Timestamp of the job complete event
    pub timestamp: u32,
    /// Time spent to search for sid.code
    pub time_spent: u32,
    /// Doppler range lowest frequency
    pub cf_min: i32,
    /// Doppler range highest frequency
    pub cf_max: i32,
    /// Doppler value of detected peak. Only valid if status is '1'
    pub cf: i32,
    /// Codephase of detected peak. Only valid if status is '1'
    pub cp: u32,
}

impl SbpParse<AcqSvProfileDep> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<AcqSvProfileDep> {
        Ok( AcqSvProfileDep{
            job_type: self.parse()?,
            status: self.parse()?,
            cn0: self.parse()?,
            int_time: self.parse()?,
            sid: self.parse()?,
            bin_width: self.parse()?,
            timestamp: self.parse()?,
            time_spent: self.parse()?,
            cf_min: self.parse()?,
            cf_max: self.parse()?,
            cf: self.parse()?,
            cp: self.parse()?,
        } )
    }
}

impl crate::serialize::SbpSerialize for AcqSvProfileDep {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.job_type.append_to_sbp_buffer(buf);
        self.status.append_to_sbp_buffer(buf);
        self.cn0.append_to_sbp_buffer(buf);
        self.int_time.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
        self.bin_width.append_to_sbp_buffer(buf);
        self.timestamp.append_to_sbp_buffer(buf);
        self.time_spent.append_to_sbp_buffer(buf);
        self.cf_min.append_to_sbp_buffer(buf);
        self.cf_max.append_to_sbp_buffer(buf);
        self.cf.append_to_sbp_buffer(buf);
        self.cp.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.job_type.sbp_size();
        size += self.status.sbp_size();
        size += self.cn0.sbp_size();
        size += self.int_time.sbp_size();
        size += self.sid.sbp_size();
        size += self.bin_width.sbp_size();
        size += self.timestamp.sbp_size();
        size += self.time_spent.sbp_size();
        size += self.cf_min.sbp_size();
        size += self.cf_max.sbp_size();
        size += self.cf.sbp_size();
        size += self.cp.sbp_size();
        size
    }
}

/// Satellite acquisition result
///
/// This message describes the results from an attempted GPS signal
/// acquisition search for a satellite PRN over a code phase/carrier
/// frequency range. It contains the parameters of the point in the
/// acquisition search space with the best carrier-to-noise (CN/0)
/// ratio.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgAcqResult {
    pub sender_id: Option<u16>,
    /// CN/0 of best point
    pub cn0: f32,
    /// Code phase of best point
    pub cp: f32,
    /// Carrier frequency of best point
    pub cf: f32,
    /// GNSS signal for which acquisition was attempted
    pub sid: GnssSignal,
}

impl SbpParse<MsgAcqResult> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgAcqResult> {
        Ok( MsgAcqResult{
            sender_id: None,
            cn0: self.parse()?,
            cp: self.parse()?,
            cf: self.parse()?,
            sid: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgAcqResult {
    fn get_message_type(&self) -> u16 {
        47
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

impl crate::serialize::SbpSerialize for MsgAcqResult {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.cn0.append_to_sbp_buffer(buf);
        self.cp.append_to_sbp_buffer(buf);
        self.cf.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.cn0.sbp_size();
        size += self.cp.sbp_size();
        size += self.cf.sbp_size();
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
pub struct MsgAcqResultDepA {
    pub sender_id: Option<u16>,
    /// SNR of best point. Currently dimensonless, but will have units of dB Hz
    /// in the revision of this message.
    pub snr: f32,
    /// Code phase of best point
    pub cp: f32,
    /// Carrier frequency of best point
    pub cf: f32,
    /// PRN-1 identifier of the satellite signal for which acquisition was
    /// attempted
    pub prn: u8,
}

impl SbpParse<MsgAcqResultDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgAcqResultDepA> {
        Ok( MsgAcqResultDepA{
            sender_id: None,
            snr: self.parse()?,
            cp: self.parse()?,
            cf: self.parse()?,
            prn: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgAcqResultDepA {
    fn get_message_type(&self) -> u16 {
        21
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

impl crate::serialize::SbpSerialize for MsgAcqResultDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.snr.append_to_sbp_buffer(buf);
        self.cp.append_to_sbp_buffer(buf);
        self.cf.append_to_sbp_buffer(buf);
        self.prn.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.snr.sbp_size();
        size += self.cp.sbp_size();
        size += self.cf.sbp_size();
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
pub struct MsgAcqResultDepB {
    pub sender_id: Option<u16>,
    /// SNR of best point. Currently in arbitrary SNR points, but will be in
    /// units of dB Hz in a later revision of this message.
    pub snr: f32,
    /// Code phase of best point
    pub cp: f32,
    /// Carrier frequency of best point
    pub cf: f32,
    /// GNSS signal for which acquisition was attempted
    pub sid: GnssSignalDep,
}

impl SbpParse<MsgAcqResultDepB> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgAcqResultDepB> {
        Ok( MsgAcqResultDepB{
            sender_id: None,
            snr: self.parse()?,
            cp: self.parse()?,
            cf: self.parse()?,
            sid: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgAcqResultDepB {
    fn get_message_type(&self) -> u16 {
        20
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

impl crate::serialize::SbpSerialize for MsgAcqResultDepB {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.snr.append_to_sbp_buffer(buf);
        self.cp.append_to_sbp_buffer(buf);
        self.cf.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.snr.sbp_size();
        size += self.cp.sbp_size();
        size += self.cf.sbp_size();
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
pub struct MsgAcqResultDepC {
    pub sender_id: Option<u16>,
    /// CN/0 of best point
    pub cn0: f32,
    /// Code phase of best point
    pub cp: f32,
    /// Carrier frequency of best point
    pub cf: f32,
    /// GNSS signal for which acquisition was attempted
    pub sid: GnssSignalDep,
}

impl SbpParse<MsgAcqResultDepC> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgAcqResultDepC> {
        Ok( MsgAcqResultDepC{
            sender_id: None,
            cn0: self.parse()?,
            cp: self.parse()?,
            cf: self.parse()?,
            sid: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgAcqResultDepC {
    fn get_message_type(&self) -> u16 {
        31
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

impl crate::serialize::SbpSerialize for MsgAcqResultDepC {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.cn0.append_to_sbp_buffer(buf);
        self.cp.append_to_sbp_buffer(buf);
        self.cf.append_to_sbp_buffer(buf);
        self.sid.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.cn0.sbp_size();
        size += self.cp.sbp_size();
        size += self.cf.sbp_size();
        size += self.sid.sbp_size();
        size
    }
}

/// Acquisition perfomance measurement and debug
///
/// The message describes all SV profiles during acquisition time.
/// The message is used to debug and measure the performance.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgAcqSvProfile {
    pub sender_id: Option<u16>,
    /// SV profiles during acquisition time
    pub acq_sv_profile: Vec<AcqSvProfile>,
}

impl SbpParse<MsgAcqSvProfile> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgAcqSvProfile> {
        Ok( MsgAcqSvProfile{
            sender_id: None,
            acq_sv_profile: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgAcqSvProfile {
    fn get_message_type(&self) -> u16 {
        46
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

impl crate::serialize::SbpSerialize for MsgAcqSvProfile {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.acq_sv_profile.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.acq_sv_profile.sbp_size();
        size
    }
}

/// Deprecated.
///
/// Deprecated.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgAcqSvProfileDep {
    pub sender_id: Option<u16>,
    /// SV profiles during acquisition time
    pub acq_sv_profile: Vec<AcqSvProfileDep>,
}

impl SbpParse<MsgAcqSvProfileDep> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgAcqSvProfileDep> {
        Ok( MsgAcqSvProfileDep{
            sender_id: None,
            acq_sv_profile: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgAcqSvProfileDep {
    fn get_message_type(&self) -> u16 {
        30
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

impl crate::serialize::SbpSerialize for MsgAcqSvProfileDep {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.acq_sv_profile.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.acq_sv_profile.sbp_size();
        size
    }
}
