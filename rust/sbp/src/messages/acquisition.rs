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
// Automatically generated from yaml/swiftnav/sbp/acquisition.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Satellite acquisition messages from the device.

use super::gnss::*;

use super::lib::*;

/// Acq perfomance measurement and debug
///
/// Profile for a specific SV for debugging purposes. The message describes SV
/// profile during acquisition time. The message is used to debug and measure
/// the performance.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct AcqSvProfile {
    /// SV search job type (deep, fallback, etc)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "job_type")))]
    pub job_type: u8,
    /// Acquisition status 1 is Success, 0 is Failure
    #[cfg_attr(feature = "serde", serde(rename(serialize = "status")))]
    pub status: u8,
    /// CN0 value. Only valid if status is '1'
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cn0")))]
    pub cn0: u16,
    /// Acquisition integration time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "int_time")))]
    pub int_time: u8,
    /// GNSS signal for which acquisition was attempted
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
    /// Acq frequency bin width
    #[cfg_attr(feature = "serde", serde(rename(serialize = "bin_width")))]
    pub bin_width: u16,
    /// Timestamp of the job complete event
    #[cfg_attr(feature = "serde", serde(rename(serialize = "timestamp")))]
    pub timestamp: u32,
    /// Time spent to search for sid.code
    #[cfg_attr(feature = "serde", serde(rename(serialize = "time_spent")))]
    pub time_spent: u32,
    /// Doppler range lowest frequency
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cf_min")))]
    pub cf_min: i32,
    /// Doppler range highest frequency
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cf_max")))]
    pub cf_max: i32,
    /// Doppler value of detected peak. Only valid if status is '1'
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cf")))]
    pub cf: i32,
    /// Codephase of detected peak. Only valid if status is '1'
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cp")))]
    pub cp: u32,
}

impl WireFormat for AcqSvProfile {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <GnssSignal as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.job_type)
            + WireFormat::len(&self.status)
            + WireFormat::len(&self.cn0)
            + WireFormat::len(&self.int_time)
            + WireFormat::len(&self.sid)
            + WireFormat::len(&self.bin_width)
            + WireFormat::len(&self.timestamp)
            + WireFormat::len(&self.time_spent)
            + WireFormat::len(&self.cf_min)
            + WireFormat::len(&self.cf_max)
            + WireFormat::len(&self.cf)
            + WireFormat::len(&self.cp)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.job_type, buf);
        WireFormat::write(&self.status, buf);
        WireFormat::write(&self.cn0, buf);
        WireFormat::write(&self.int_time, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.bin_width, buf);
        WireFormat::write(&self.timestamp, buf);
        WireFormat::write(&self.time_spent, buf);
        WireFormat::write(&self.cf_min, buf);
        WireFormat::write(&self.cf_max, buf);
        WireFormat::write(&self.cf, buf);
        WireFormat::write(&self.cp, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        AcqSvProfile {
            job_type: WireFormat::parse_unchecked(buf),
            status: WireFormat::parse_unchecked(buf),
            cn0: WireFormat::parse_unchecked(buf),
            int_time: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            bin_width: WireFormat::parse_unchecked(buf),
            timestamp: WireFormat::parse_unchecked(buf),
            time_spent: WireFormat::parse_unchecked(buf),
            cf_min: WireFormat::parse_unchecked(buf),
            cf_max: WireFormat::parse_unchecked(buf),
            cf: WireFormat::parse_unchecked(buf),
            cp: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct AcqSvProfileDep {
    /// SV search job type (deep, fallback, etc)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "job_type")))]
    pub job_type: u8,
    /// Acquisition status 1 is Success, 0 is Failure
    #[cfg_attr(feature = "serde", serde(rename(serialize = "status")))]
    pub status: u8,
    /// CN0 value. Only valid if status is '1'
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cn0")))]
    pub cn0: u16,
    /// Acquisition integration time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "int_time")))]
    pub int_time: u8,
    /// GNSS signal for which acquisition was attempted
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignalDep,
    /// Acq frequency bin width
    #[cfg_attr(feature = "serde", serde(rename(serialize = "bin_width")))]
    pub bin_width: u16,
    /// Timestamp of the job complete event
    #[cfg_attr(feature = "serde", serde(rename(serialize = "timestamp")))]
    pub timestamp: u32,
    /// Time spent to search for sid.code
    #[cfg_attr(feature = "serde", serde(rename(serialize = "time_spent")))]
    pub time_spent: u32,
    /// Doppler range lowest frequency
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cf_min")))]
    pub cf_min: i32,
    /// Doppler range highest frequency
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cf_max")))]
    pub cf_max: i32,
    /// Doppler value of detected peak. Only valid if status is '1'
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cf")))]
    pub cf: i32,
    /// Codephase of detected peak. Only valid if status is '1'
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cp")))]
    pub cp: u32,
}

impl WireFormat for AcqSvProfileDep {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <GnssSignalDep as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <i32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.job_type)
            + WireFormat::len(&self.status)
            + WireFormat::len(&self.cn0)
            + WireFormat::len(&self.int_time)
            + WireFormat::len(&self.sid)
            + WireFormat::len(&self.bin_width)
            + WireFormat::len(&self.timestamp)
            + WireFormat::len(&self.time_spent)
            + WireFormat::len(&self.cf_min)
            + WireFormat::len(&self.cf_max)
            + WireFormat::len(&self.cf)
            + WireFormat::len(&self.cp)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.job_type, buf);
        WireFormat::write(&self.status, buf);
        WireFormat::write(&self.cn0, buf);
        WireFormat::write(&self.int_time, buf);
        WireFormat::write(&self.sid, buf);
        WireFormat::write(&self.bin_width, buf);
        WireFormat::write(&self.timestamp, buf);
        WireFormat::write(&self.time_spent, buf);
        WireFormat::write(&self.cf_min, buf);
        WireFormat::write(&self.cf_max, buf);
        WireFormat::write(&self.cf, buf);
        WireFormat::write(&self.cp, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        AcqSvProfileDep {
            job_type: WireFormat::parse_unchecked(buf),
            status: WireFormat::parse_unchecked(buf),
            cn0: WireFormat::parse_unchecked(buf),
            int_time: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
            bin_width: WireFormat::parse_unchecked(buf),
            timestamp: WireFormat::parse_unchecked(buf),
            time_spent: WireFormat::parse_unchecked(buf),
            cf_min: WireFormat::parse_unchecked(buf),
            cf_max: WireFormat::parse_unchecked(buf),
            cf: WireFormat::parse_unchecked(buf),
            cp: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Satellite acquisition result
///
/// This message describes the results from an attempted GPS signal
/// acquisition search for a satellite PRN over a code phase/carrier frequency
/// range. It contains the parameters of the point in the acquisition search
/// space with the best carrier-to-noise (CN/0) ratio.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgAcqResult {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// CN/0 of best point
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cn0")))]
    pub cn0: f32,
    /// Code phase of best point
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cp")))]
    pub cp: f32,
    /// Carrier frequency of best point
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cf")))]
    pub cf: f32,
    /// GNSS signal for which acquisition was attempted
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignal,
}

impl ConcreteMessage for MsgAcqResult {
    const MESSAGE_TYPE: u16 = 47;
    const MESSAGE_NAME: &'static str = "MSG_ACQ_RESULT";
}

impl SbpMessage for MsgAcqResult {
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

impl TryFrom<Sbp> for MsgAcqResult {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgAcqResult(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgAcqResult {
    const MIN_LEN: usize = <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <GnssSignal as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.cn0)
            + WireFormat::len(&self.cp)
            + WireFormat::len(&self.cf)
            + WireFormat::len(&self.sid)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.cn0, buf);
        WireFormat::write(&self.cp, buf);
        WireFormat::write(&self.cf, buf);
        WireFormat::write(&self.sid, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgAcqResult {
            sender_id: None,
            cn0: WireFormat::parse_unchecked(buf),
            cp: WireFormat::parse_unchecked(buf),
            cf: WireFormat::parse_unchecked(buf),
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
pub struct MsgAcqResultDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// SNR of best point. Currently dimensionless, but will have units of dB Hz
    /// in the revision of this message.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "snr")))]
    pub snr: f32,
    /// Code phase of best point
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cp")))]
    pub cp: f32,
    /// Carrier frequency of best point
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cf")))]
    pub cf: f32,
    /// PRN-1 identifier of the satellite signal for which acquisition was
    /// attempted
    #[cfg_attr(feature = "serde", serde(rename(serialize = "prn")))]
    pub prn: u8,
}

impl ConcreteMessage for MsgAcqResultDepA {
    const MESSAGE_TYPE: u16 = 21;
    const MESSAGE_NAME: &'static str = "MSG_ACQ_RESULT_DEP_A";
}

impl SbpMessage for MsgAcqResultDepA {
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

impl TryFrom<Sbp> for MsgAcqResultDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgAcqResultDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgAcqResultDepA {
    const MIN_LEN: usize = <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.snr)
            + WireFormat::len(&self.cp)
            + WireFormat::len(&self.cf)
            + WireFormat::len(&self.prn)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.snr, buf);
        WireFormat::write(&self.cp, buf);
        WireFormat::write(&self.cf, buf);
        WireFormat::write(&self.prn, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgAcqResultDepA {
            sender_id: None,
            snr: WireFormat::parse_unchecked(buf),
            cp: WireFormat::parse_unchecked(buf),
            cf: WireFormat::parse_unchecked(buf),
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
pub struct MsgAcqResultDepB {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// SNR of best point. Currently in arbitrary SNR points, but will be in
    /// units of dB Hz in a later revision of this message.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "snr")))]
    pub snr: f32,
    /// Code phase of best point
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cp")))]
    pub cp: f32,
    /// Carrier frequency of best point
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cf")))]
    pub cf: f32,
    /// GNSS signal for which acquisition was attempted
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignalDep,
}

impl ConcreteMessage for MsgAcqResultDepB {
    const MESSAGE_TYPE: u16 = 20;
    const MESSAGE_NAME: &'static str = "MSG_ACQ_RESULT_DEP_B";
}

impl SbpMessage for MsgAcqResultDepB {
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

impl TryFrom<Sbp> for MsgAcqResultDepB {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgAcqResultDepB(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgAcqResultDepB {
    const MIN_LEN: usize = <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <GnssSignalDep as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.snr)
            + WireFormat::len(&self.cp)
            + WireFormat::len(&self.cf)
            + WireFormat::len(&self.sid)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.snr, buf);
        WireFormat::write(&self.cp, buf);
        WireFormat::write(&self.cf, buf);
        WireFormat::write(&self.sid, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgAcqResultDepB {
            sender_id: None,
            snr: WireFormat::parse_unchecked(buf),
            cp: WireFormat::parse_unchecked(buf),
            cf: WireFormat::parse_unchecked(buf),
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
pub struct MsgAcqResultDepC {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// CN/0 of best point
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cn0")))]
    pub cn0: f32,
    /// Code phase of best point
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cp")))]
    pub cp: f32,
    /// Carrier frequency of best point
    #[cfg_attr(feature = "serde", serde(rename(serialize = "cf")))]
    pub cf: f32,
    /// GNSS signal for which acquisition was attempted
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sid")))]
    pub sid: GnssSignalDep,
}

impl ConcreteMessage for MsgAcqResultDepC {
    const MESSAGE_TYPE: u16 = 31;
    const MESSAGE_NAME: &'static str = "MSG_ACQ_RESULT_DEP_C";
}

impl SbpMessage for MsgAcqResultDepC {
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

impl TryFrom<Sbp> for MsgAcqResultDepC {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgAcqResultDepC(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgAcqResultDepC {
    const MIN_LEN: usize = <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <f32 as WireFormat>::MIN_LEN
        + <GnssSignalDep as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.cn0)
            + WireFormat::len(&self.cp)
            + WireFormat::len(&self.cf)
            + WireFormat::len(&self.sid)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.cn0, buf);
        WireFormat::write(&self.cp, buf);
        WireFormat::write(&self.cf, buf);
        WireFormat::write(&self.sid, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgAcqResultDepC {
            sender_id: None,
            cn0: WireFormat::parse_unchecked(buf),
            cp: WireFormat::parse_unchecked(buf),
            cf: WireFormat::parse_unchecked(buf),
            sid: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Acquisition perfomance measurement and debug
///
/// The message describes all SV profiles during acquisition time. The message
/// is used to debug and measure the performance.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgAcqSvProfile {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// SV profiles during acquisition time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "acq_sv_profile")))]
    pub acq_sv_profile: Vec<AcqSvProfile>,
}

impl ConcreteMessage for MsgAcqSvProfile {
    const MESSAGE_TYPE: u16 = 46;
    const MESSAGE_NAME: &'static str = "MSG_ACQ_SV_PROFILE";
}

impl SbpMessage for MsgAcqSvProfile {
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

impl TryFrom<Sbp> for MsgAcqSvProfile {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgAcqSvProfile(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgAcqSvProfile {
    const MIN_LEN: usize = <Vec<AcqSvProfile> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.acq_sv_profile)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.acq_sv_profile, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgAcqSvProfile {
            sender_id: None,
            acq_sv_profile: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Deprecated
///
/// Deprecated.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgAcqSvProfileDep {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// SV profiles during acquisition time
    #[cfg_attr(feature = "serde", serde(rename(serialize = "acq_sv_profile")))]
    pub acq_sv_profile: Vec<AcqSvProfileDep>,
}

impl ConcreteMessage for MsgAcqSvProfileDep {
    const MESSAGE_TYPE: u16 = 30;
    const MESSAGE_NAME: &'static str = "MSG_ACQ_SV_PROFILE_DEP";
}

impl SbpMessage for MsgAcqSvProfileDep {
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

impl TryFrom<Sbp> for MsgAcqSvProfileDep {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgAcqSvProfileDep(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgAcqSvProfileDep {
    const MIN_LEN: usize = <Vec<AcqSvProfileDep> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.acq_sv_profile)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.acq_sv_profile, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgAcqSvProfileDep {
            sender_id: None,
            acq_sv_profile: WireFormat::parse_unchecked(buf),
        }
    }
}
