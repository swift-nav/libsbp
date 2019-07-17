// Copyright (C) 2015-2018 Swift Navigation Inc.
// Contact: Swift Navigation <dev@swiftnav.com>
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
// Satellite acquisition messages from the device.
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
use super::gnss::*;

// Satellite acquisition result
//
// This message describes the results from an attempted GPS signal
// acquisition search for a satellite PRN over a code phase/carrier
// frequency range. It contains the parameters of the point in the
// acquisition search space with the best carrier-to-noise (CN/0)
// ratio.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgAcqResult {
    pub sender_id: Option<u16>,
    pub cn0: f32,
    // ^ CN/0 of best point
    pub cp: f32,
    // ^ Code phase of best point
    pub cf: f32,
    // ^ Carrier frequency of best point
    pub sid: GnssSignal,
    // ^ GNSS signal for which acquisition was attempted
}

impl MsgAcqResult {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAcqResult, ::parser::MessageError> {
        Ok(MsgAcqResult {
            sender_id: None,
            cn0: _buf.read_f32::<LittleEndian>()?,
            cp: _buf.read_f32::<LittleEndian>()?,
            cf: _buf.read_f32::<LittleEndian>()?,
            sid: GnssSignal::parse(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgAcqResult {
    const MSG_ID: u16 = 47;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Deprecated
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgAcqResultDepC {
    pub sender_id: Option<u16>,
    pub cn0: f32,
    // ^ CN/0 of best point
    pub cp: f32,
    // ^ Code phase of best point
    pub cf: f32,
    // ^ Carrier frequency of best point
    pub sid: GnssSignalDep,
    // ^ GNSS signal for which acquisition was attempted
}

impl MsgAcqResultDepC {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAcqResultDepC, ::parser::MessageError> {
        Ok(MsgAcqResultDepC {
            sender_id: None,
            cn0: _buf.read_f32::<LittleEndian>()?,
            cp: _buf.read_f32::<LittleEndian>()?,
            cf: _buf.read_f32::<LittleEndian>()?,
            sid: GnssSignalDep::parse(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgAcqResultDepC {
    const MSG_ID: u16 = 31;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Deprecated
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgAcqResultDepB {
    pub sender_id: Option<u16>,
    pub snr: f32,
    // ^ SNR of best point. Currently in arbitrary SNR points, but will be in
    // units of dB Hz in a later revision of this message.
    pub cp: f32,
    // ^ Code phase of best point
    pub cf: f32,
    // ^ Carrier frequency of best point
    pub sid: GnssSignalDep,
    // ^ GNSS signal for which acquisition was attempted
}

impl MsgAcqResultDepB {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAcqResultDepB, ::parser::MessageError> {
        Ok(MsgAcqResultDepB {
            sender_id: None,
            snr: _buf.read_f32::<LittleEndian>()?,
            cp: _buf.read_f32::<LittleEndian>()?,
            cf: _buf.read_f32::<LittleEndian>()?,
            sid: GnssSignalDep::parse(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgAcqResultDepB {
    const MSG_ID: u16 = 20;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Deprecated
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgAcqResultDepA {
    pub sender_id: Option<u16>,
    pub snr: f32,
    // ^ SNR of best point. Currently dimensonless, but will have units of dB Hz
    // in the revision of this message.
    pub cp: f32,
    // ^ Code phase of best point
    pub cf: f32,
    // ^ Carrier frequency of best point
    pub prn: u8,
    // ^ PRN-1 identifier of the satellite signal for which acquisition was
    // attempted
}

impl MsgAcqResultDepA {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAcqResultDepA, ::parser::MessageError> {
        Ok(MsgAcqResultDepA {
            sender_id: None,
            snr: _buf.read_f32::<LittleEndian>()?,
            cp: _buf.read_f32::<LittleEndian>()?,
            cf: _buf.read_f32::<LittleEndian>()?,
            prn: _buf.read_u8()?,
        })
    }
}
impl super::SBPMessage for MsgAcqResultDepA {
    const MSG_ID: u16 = 21;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Acq perfomance measurement and debug
//
// Profile for a specific SV for debugging purposes
// The message describes SV profile during acquisition time.
// The message is used to debug and measure the performance.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct AcqSvProfile {
    pub job_type: u8,
    // ^ SV search job type (deep, fallback, etc)
    pub status: u8,
    // ^ Acquisition status 1 is Success, 0 is Failure
    pub cn0: u16,
    // ^ CN0 value. Only valid if status is '1'
    pub int_time: u8,
    // ^ Acquisition integration time
    pub sid: GnssSignal,
    // ^ GNSS signal for which acquisition was attempted
    pub bin_width: u16,
    // ^ Acq frequency bin width
    pub timestamp: u32,
    // ^ Timestamp of the job complete event
    pub time_spent: u32,
    // ^ Time spent to search for sid.code
    pub cf_min: i32,
    // ^ Doppler range lowest frequency
    pub cf_max: i32,
    // ^ Doppler range highest frequency
    pub cf: i32,
    // ^ Doppler value of detected peak. Only valid if status is '1'
    pub cp: u32,
    // ^ Codephase of detected peak. Only valid if status is '1'
}

impl AcqSvProfile {
    pub fn parse(_buf: &mut &[u8]) -> Result<AcqSvProfile, ::parser::MessageError> {
        Ok(AcqSvProfile {
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
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<AcqSvProfile>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(AcqSvProfile::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<AcqSvProfile>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(AcqSvProfile::parse(buf)?);
        }
        Ok(v)
    }
}

// Deprecated
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct AcqSvProfileDep {
    pub job_type: u8,
    // ^ SV search job type (deep, fallback, etc)
    pub status: u8,
    // ^ Acquisition status 1 is Success, 0 is Failure
    pub cn0: u16,
    // ^ CN0 value. Only valid if status is '1'
    pub int_time: u8,
    // ^ Acquisition integration time
    pub sid: GnssSignalDep,
    // ^ GNSS signal for which acquisition was attempted
    pub bin_width: u16,
    // ^ Acq frequency bin width
    pub timestamp: u32,
    // ^ Timestamp of the job complete event
    pub time_spent: u32,
    // ^ Time spent to search for sid.code
    pub cf_min: i32,
    // ^ Doppler range lowest frequency
    pub cf_max: i32,
    // ^ Doppler range highest frequency
    pub cf: i32,
    // ^ Doppler value of detected peak. Only valid if status is '1'
    pub cp: u32,
    // ^ Codephase of detected peak. Only valid if status is '1'
}

impl AcqSvProfileDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<AcqSvProfileDep, ::parser::MessageError> {
        Ok(AcqSvProfileDep {
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
        })
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<AcqSvProfileDep>, ::parser::MessageError> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(AcqSvProfileDep::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<AcqSvProfileDep>, ::parser::MessageError> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(AcqSvProfileDep::parse(buf)?);
        }
        Ok(v)
    }
}

// Acquisition perfomance measurement and debug
//
// The message describes all SV profiles during acquisition time.
// The message is used to debug and measure the performance.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgAcqSvProfile {
    pub sender_id: Option<u16>,
    pub acq_sv_profile: Vec<AcqSvProfile>,
    // ^ SV profiles during acquisition time
}

impl MsgAcqSvProfile {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAcqSvProfile, ::parser::MessageError> {
        Ok(MsgAcqSvProfile {
            sender_id: None,
            acq_sv_profile: AcqSvProfile::parse_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgAcqSvProfile {
    const MSG_ID: u16 = 46;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

// Deprecated.
//
// Deprecated.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgAcqSvProfileDep {
    pub sender_id: Option<u16>,
    pub acq_sv_profile: Vec<AcqSvProfileDep>,
    // ^ SV profiles during acquisition time
}

impl MsgAcqSvProfileDep {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgAcqSvProfileDep, ::parser::MessageError> {
        Ok(MsgAcqSvProfileDep {
            sender_id: None,
            acq_sv_profile: AcqSvProfileDep::parse_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgAcqSvProfileDep {
    const MSG_ID: u16 = 30;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}
