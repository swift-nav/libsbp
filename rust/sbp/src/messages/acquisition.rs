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

#[allow(unused_imports)]
use std::convert::TryFrom;

#[allow(unused_imports)]
use byteorder::{LittleEndian, ReadBytesExt};

use super::gnss::*;
#[allow(unused_imports)]
use crate::serialize::SbpSerialize;
#[allow(unused_imports)]
use crate::SbpString;

/// Acq perfomance measurement and debug
///
/// Profile for a specific SV for debugging purposes. The message describes SV
/// profile during acquisition time. The message is used to debug and measure
/// the performance.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
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

impl AcqSvProfile {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<AcqSvProfile, crate::Error> {
        Ok( AcqSvProfile{
            job_type: _buf.read_u8()?,
            status: _buf.read_u8()?,
            cn0: _buf.read_u16::<LittleEndian>()?,
            int_time: _buf.read_u8()?,
            sid: GnssSignal::parse(_buf)?,
            bin_width: _buf.read_u16::<LittleEndian>()?,
            timestamp: _buf.read_u32::<LittleEndian>()?,
            time_spent: _buf.read_u32::<LittleEndian>()?,
            cf_min: _buf.read_i32::<LittleEndian>()?,
            cf_max: _buf.read_i32::<LittleEndian>()?,
            cf: _buf.read_i32::<LittleEndian>()?,
            cp: _buf.read_u32::<LittleEndian>()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<AcqSvProfile>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(AcqSvProfile::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<AcqSvProfile>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(AcqSvProfile::parse(buf)?);
        }
        Ok(v)
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
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
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

impl AcqSvProfileDep {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<AcqSvProfileDep, crate::Error> {
        Ok( AcqSvProfileDep{
            job_type: _buf.read_u8()?,
            status: _buf.read_u8()?,
            cn0: _buf.read_u16::<LittleEndian>()?,
            int_time: _buf.read_u8()?,
            sid: GnssSignalDep::parse(_buf)?,
            bin_width: _buf.read_u16::<LittleEndian>()?,
            timestamp: _buf.read_u32::<LittleEndian>()?,
            time_spent: _buf.read_u32::<LittleEndian>()?,
            cf_min: _buf.read_i32::<LittleEndian>()?,
            cf_max: _buf.read_i32::<LittleEndian>()?,
            cf: _buf.read_i32::<LittleEndian>()?,
            cp: _buf.read_u32::<LittleEndian>()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<AcqSvProfileDep>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(AcqSvProfileDep::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<AcqSvProfileDep>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(AcqSvProfileDep::parse(buf)?);
        }
        Ok(v)
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
/// acquisition search for a satellite PRN over a code phase/carrier frequency
/// range. It contains the parameters of the point in the acquisition search
/// space with the best carrier-to-noise (CN/0) ratio.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgAcqResult {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
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

impl MsgAcqResult {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAcqResult, crate::Error> {
        Ok( MsgAcqResult{
            sender_id: None,
            cn0: _buf.read_f32::<LittleEndian>()?,
            cp: _buf.read_f32::<LittleEndian>()?,
            cf: _buf.read_f32::<LittleEndian>()?,
            sid: GnssSignal::parse(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgAcqResult {
    fn get_message_name(&self) -> &'static str {
        "MSG_ACQ_RESULT"
    }

    fn get_message_type(&self) -> u16 {
        47
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgAcqResult {
    const MESSAGE_TYPE: u16 = 47;
    const MESSAGE_NAME: &'static str = "MSG_ACQ_RESULT";
}
impl TryFrom<super::SBP> for MsgAcqResult {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgAcqResult(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
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
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgAcqResultDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// SNR of best point. Currently dimensionless, but will have units of dB Hz
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

impl MsgAcqResultDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAcqResultDepA, crate::Error> {
        Ok( MsgAcqResultDepA{
            sender_id: None,
            snr: _buf.read_f32::<LittleEndian>()?,
            cp: _buf.read_f32::<LittleEndian>()?,
            cf: _buf.read_f32::<LittleEndian>()?,
            prn: _buf.read_u8()?,
        } )
    }
}
impl super::SBPMessage for MsgAcqResultDepA {
    fn get_message_name(&self) -> &'static str {
        "MSG_ACQ_RESULT_DEP_A"
    }

    fn get_message_type(&self) -> u16 {
        21
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgAcqResultDepA {
    const MESSAGE_TYPE: u16 = 21;
    const MESSAGE_NAME: &'static str = "MSG_ACQ_RESULT_DEP_A";
}
impl TryFrom<super::SBP> for MsgAcqResultDepA {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgAcqResultDepA(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
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
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgAcqResultDepB {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
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

impl MsgAcqResultDepB {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAcqResultDepB, crate::Error> {
        Ok( MsgAcqResultDepB{
            sender_id: None,
            snr: _buf.read_f32::<LittleEndian>()?,
            cp: _buf.read_f32::<LittleEndian>()?,
            cf: _buf.read_f32::<LittleEndian>()?,
            sid: GnssSignalDep::parse(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgAcqResultDepB {
    fn get_message_name(&self) -> &'static str {
        "MSG_ACQ_RESULT_DEP_B"
    }

    fn get_message_type(&self) -> u16 {
        20
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgAcqResultDepB {
    const MESSAGE_TYPE: u16 = 20;
    const MESSAGE_NAME: &'static str = "MSG_ACQ_RESULT_DEP_B";
}
impl TryFrom<super::SBP> for MsgAcqResultDepB {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgAcqResultDepB(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
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
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgAcqResultDepC {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
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

impl MsgAcqResultDepC {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAcqResultDepC, crate::Error> {
        Ok( MsgAcqResultDepC{
            sender_id: None,
            cn0: _buf.read_f32::<LittleEndian>()?,
            cp: _buf.read_f32::<LittleEndian>()?,
            cf: _buf.read_f32::<LittleEndian>()?,
            sid: GnssSignalDep::parse(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgAcqResultDepC {
    fn get_message_name(&self) -> &'static str {
        "MSG_ACQ_RESULT_DEP_C"
    }

    fn get_message_type(&self) -> u16 {
        31
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgAcqResultDepC {
    const MESSAGE_TYPE: u16 = 31;
    const MESSAGE_NAME: &'static str = "MSG_ACQ_RESULT_DEP_C";
}
impl TryFrom<super::SBP> for MsgAcqResultDepC {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgAcqResultDepC(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
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
/// The message describes all SV profiles during acquisition time. The message
/// is used to debug and measure the performance.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgAcqSvProfile {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// SV profiles during acquisition time
    pub acq_sv_profile: Vec<AcqSvProfile>,
}

impl MsgAcqSvProfile {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAcqSvProfile, crate::Error> {
        Ok( MsgAcqSvProfile{
            sender_id: None,
            acq_sv_profile: AcqSvProfile::parse_array(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgAcqSvProfile {
    fn get_message_name(&self) -> &'static str {
        "MSG_ACQ_SV_PROFILE"
    }

    fn get_message_type(&self) -> u16 {
        46
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgAcqSvProfile {
    const MESSAGE_TYPE: u16 = 46;
    const MESSAGE_NAME: &'static str = "MSG_ACQ_SV_PROFILE";
}
impl TryFrom<super::SBP> for MsgAcqSvProfile {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgAcqSvProfile(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
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

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgAcqSvProfileDep {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// SV profiles during acquisition time
    pub acq_sv_profile: Vec<AcqSvProfileDep>,
}

impl MsgAcqSvProfileDep {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAcqSvProfileDep, crate::Error> {
        Ok( MsgAcqSvProfileDep{
            sender_id: None,
            acq_sv_profile: AcqSvProfileDep::parse_array(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgAcqSvProfileDep {
    fn get_message_name(&self) -> &'static str {
        "MSG_ACQ_SV_PROFILE_DEP"
    }

    fn get_message_type(&self) -> u16 {
        30
    }

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }

    fn to_frame(&self) -> std::result::Result<Vec<u8>, crate::FramerError> {
        let mut frame = Vec::new();
        self.write_frame(&mut frame)?;
        Ok(frame)
    }

    fn write_frame(&self, frame: &mut Vec<u8>) -> std::result::Result<(), crate::FramerError> {
        crate::write_frame(self, frame)
    }
}
impl super::ConcreteMessage for MsgAcqSvProfileDep {
    const MESSAGE_TYPE: u16 = 30;
    const MESSAGE_NAME: &'static str = "MSG_ACQ_SV_PROFILE_DEP";
}
impl TryFrom<super::SBP> for MsgAcqSvProfileDep {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgAcqSvProfileDep(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
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
