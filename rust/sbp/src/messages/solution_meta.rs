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
// Automatically generated from yaml/swiftnav/sbp/solution_meta.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Standardized Metadata messages for Fuzed Solution from Swift Navigation
//! devices.

#[allow(unused_imports)]
use std::convert::TryFrom;

#[allow(unused_imports)]
use byteorder::{LittleEndian, ReadBytesExt};

#[allow(unused_imports)]
use crate::serialize::SbpSerialize;
#[allow(unused_imports)]
use crate::SbpString;

/// Instruments the physical type of GNSS sensor input to the fuzed solution
///
/// Metadata around the GNSS sensors involved in the fuzed solution.
/// Accessible through sol_in[N].flags in a MSG_SOLN_META.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct GNSSInputType {
    /// flags that store all relevant info specific to this sensor type.
    pub flags: u8,
}

impl GNSSInputType {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<GNSSInputType, crate::Error> {
        Ok( GNSSInputType{
            flags: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<GNSSInputType>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(GNSSInputType::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<GNSSInputType>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(GNSSInputType::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for GNSSInputType {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.flags.sbp_size();
        size
    }
}

/// Provides detail about the IMU sensor, its timestamping mode, and its quality for input to the fuzed solution

///
/// Metadata around the IMU sensors involved in the fuzed solution. Accessible
/// through sol_in[N].flags in a MSG_SOLN_META.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct IMUInputType {
    /// Instrument time, grade, and architecture for a sensor.
    pub flags: u8,
}

impl IMUInputType {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<IMUInputType, crate::Error> {
        Ok( IMUInputType{
            flags: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<IMUInputType>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(IMUInputType::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<IMUInputType>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(IMUInputType::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for IMUInputType {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.flags.sbp_size();
        size
    }
}

/// Solution Sensors Metadata
///
/// This message contains all metadata about the sensors received and/or used
/// in computing the sensorfusion solution. It focuses primarily, but not
/// only, on GNSS metadata. Regarding the age of the last received valid GNSS
/// solution, the highest two bits are time status, indicating whether age
/// gnss can or can not be used to retrieve time of measurement (noted TOM,
/// also known as time of validity) If it can, subtract 'age gnss' from 'tow'
/// in navigation messages to get TOM. Can be used before alignment is
/// complete in the Fusion Engine, when output solution is the last received
/// valid GNSS solution and its tow is not a TOM.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSolnMeta {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS time of week rounded to the nearest millisecond
    pub tow: u32,
    /// Position Dilution of Precision as per last available DOPS from PVT
    /// engine (0xFFFF indicates invalid)
    pub pdop: u16,
    /// Horizontal Dilution of Precision as per last available DOPS from PVT
    /// engine (0xFFFF indicates invalid)
    pub hdop: u16,
    /// Vertical Dilution of Precision as per last available DOPS from PVT
    /// engine (0xFFFF indicates invalid)
    pub vdop: u16,
    /// Age of corrections as per last available AGE_CORRECTIONS from PVT engine
    /// (0xFFFF indicates invalid)
    pub age_corrections: u16,
    /// Age and Time Status of the last received valid GNSS solution.
    pub age_gnss: u32,
    /// Array of Metadata describing the sensors potentially involved in the
    /// solution. Each element in the array represents a single sensor type and
    /// consists of flags containing (meta)data pertaining to that specific
    /// single sensor. Refer to each (XX)InputType descriptor in the present
    /// doc.
    pub sol_in: Vec<SolutionInputType>,
}

impl MsgSolnMeta {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSolnMeta, crate::Error> {
        Ok( MsgSolnMeta{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            pdop: _buf.read_u16::<LittleEndian>()?,
            hdop: _buf.read_u16::<LittleEndian>()?,
            vdop: _buf.read_u16::<LittleEndian>()?,
            age_corrections: _buf.read_u16::<LittleEndian>()?,
            age_gnss: _buf.read_u32::<LittleEndian>()?,
            sol_in: SolutionInputType::parse_array(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSolnMeta {
    fn get_message_name(&self) -> &'static str {
        "MSG_SOLN_META"
    }

    fn get_message_type(&self) -> u16 {
        65294
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

    #[cfg(feature = "swiftnav-rs")]
    fn gps_time(
        &self,
    ) -> Option<std::result::Result<crate::time::MessageTime, crate::time::GpsTimeError>> {
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match crate::time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(crate::time::MessageTime::Rover(gps_time.into())))
    }
}
impl super::ConcreteMessage for MsgSolnMeta {
    const MESSAGE_TYPE: u16 = 65294;
    const MESSAGE_NAME: &'static str = "MSG_SOLN_META";
}
impl TryFrom<super::SBP> for MsgSolnMeta {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSolnMeta(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSolnMeta {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.pdop.append_to_sbp_buffer(buf);
        self.hdop.append_to_sbp_buffer(buf);
        self.vdop.append_to_sbp_buffer(buf);
        self.age_corrections.append_to_sbp_buffer(buf);
        self.age_gnss.append_to_sbp_buffer(buf);
        self.sol_in.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.pdop.sbp_size();
        size += self.hdop.sbp_size();
        size += self.vdop.sbp_size();
        size += self.age_corrections.sbp_size();
        size += self.age_gnss.sbp_size();
        size += self.sol_in.sbp_size();
        size
    }
}

/// Deprecated
///
/// Deprecated.
///
/// This message contains all metadata about the sensors received and/or used
/// in computing the Fuzed Solution. It focuses primarily, but not only, on
/// GNSS metadata.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSolnMetaDepA {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Position Dilution of Precision as per last available DOPS from PVT
    /// engine (0xFFFF indicates invalid)
    pub pdop: u16,
    /// Horizontal Dilution of Precision as per last available DOPS from PVT
    /// engine (0xFFFF indicates invalid)
    pub hdop: u16,
    /// Vertical Dilution of Precision as per last available DOPS from PVT
    /// engine (0xFFFF indicates invalid)
    pub vdop: u16,
    /// Number of satellites as per last available solution from PVT engine
    pub n_sats: u8,
    /// Age of corrections as per last available AGE_CORRECTIONS from PVT engine
    /// (0xFFFF indicates invalid)
    pub age_corrections: u16,
    /// State of alignment and the status and receipt of the alignment inputs
    pub alignment_status: u8,
    /// Tow of last-used GNSS position measurement
    pub last_used_gnss_pos_tow: u32,
    /// Tow of last-used GNSS velocity measurement
    pub last_used_gnss_vel_tow: u32,
    /// Array of Metadata describing the sensors potentially involved in the
    /// solution. Each element in the array represents a single sensor type and
    /// consists of flags containing (meta)data pertaining to that specific
    /// single sensor. Refer to each (XX)InputType descriptor in the present
    /// doc.
    pub sol_in: Vec<SolutionInputType>,
}

impl MsgSolnMetaDepA {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSolnMetaDepA, crate::Error> {
        Ok( MsgSolnMetaDepA{
            sender_id: None,
            pdop: _buf.read_u16::<LittleEndian>()?,
            hdop: _buf.read_u16::<LittleEndian>()?,
            vdop: _buf.read_u16::<LittleEndian>()?,
            n_sats: _buf.read_u8()?,
            age_corrections: _buf.read_u16::<LittleEndian>()?,
            alignment_status: _buf.read_u8()?,
            last_used_gnss_pos_tow: _buf.read_u32::<LittleEndian>()?,
            last_used_gnss_vel_tow: _buf.read_u32::<LittleEndian>()?,
            sol_in: SolutionInputType::parse_array(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgSolnMetaDepA {
    fn get_message_name(&self) -> &'static str {
        "MSG_SOLN_META_DEP_A"
    }

    fn get_message_type(&self) -> u16 {
        65295
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
impl super::ConcreteMessage for MsgSolnMetaDepA {
    const MESSAGE_TYPE: u16 = 65295;
    const MESSAGE_NAME: &'static str = "MSG_SOLN_META_DEP_A";
}
impl TryFrom<super::SBP> for MsgSolnMetaDepA {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgSolnMetaDepA(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgSolnMetaDepA {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.pdop.append_to_sbp_buffer(buf);
        self.hdop.append_to_sbp_buffer(buf);
        self.vdop.append_to_sbp_buffer(buf);
        self.n_sats.append_to_sbp_buffer(buf);
        self.age_corrections.append_to_sbp_buffer(buf);
        self.alignment_status.append_to_sbp_buffer(buf);
        self.last_used_gnss_pos_tow.append_to_sbp_buffer(buf);
        self.last_used_gnss_vel_tow.append_to_sbp_buffer(buf);
        self.sol_in.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.pdop.sbp_size();
        size += self.hdop.sbp_size();
        size += self.vdop.sbp_size();
        size += self.n_sats.sbp_size();
        size += self.age_corrections.sbp_size();
        size += self.alignment_status.sbp_size();
        size += self.last_used_gnss_pos_tow.sbp_size();
        size += self.last_used_gnss_vel_tow.sbp_size();
        size += self.sol_in.sbp_size();
        size
    }
}

/// Provides detail about the Odometry sensor, its timestamping mode, and its quality for input to the fuzed solution

///
/// Metadata around the Odometry sensors involved in the fuzed solution.
/// Accessible through sol_in[N].flags in a MSG_SOLN_META.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct OdoInputType {
    /// Instrument ODO rate, grade, and quality.
    pub flags: u8,
}

impl OdoInputType {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<OdoInputType, crate::Error> {
        Ok( OdoInputType{
            flags: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<OdoInputType>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(OdoInputType::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(buf: &mut &[u8], n: usize) -> Result<Vec<OdoInputType>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(OdoInputType::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for OdoInputType {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.flags.sbp_size();
        size
    }
}

/// Flags for a given solution input type
///
/// Metadata describing which sensors were involved in the solution. The
/// structure is fixed no matter what the actual sensor type is. The
/// sensor_type field tells you which sensor we are talking about. It also
/// tells you whether the sensor data was actually used or not. The flags
/// field, always a u8, contains the sensor-specific data. The content of
/// flags, for each sensor type, is described in the relevant structures in
/// this section.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct SolutionInputType {
    /// The type of sensor
    pub sensor_type: u8,
    /// Refer to each InputType description
    pub flags: u8,
}

impl SolutionInputType {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<SolutionInputType, crate::Error> {
        Ok( SolutionInputType{
            sensor_type: _buf.read_u8()?,
            flags: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<SolutionInputType>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(SolutionInputType::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<SolutionInputType>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(SolutionInputType::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for SolutionInputType {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sensor_type.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sensor_type.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}
