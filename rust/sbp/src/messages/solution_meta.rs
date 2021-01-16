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
// Automatically generated from yaml/swiftnav/sbp/solution_meta.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Standardized Metadata messages for Fuzed Solution from Swift Navigation devices.

#[cfg(feature = "sbp_serde")]
use serde::{Deserialize, Serialize};

#[allow(unused_imports)]
use crate::{parser::SbpParse, BoundedSbpString, UnboundedSbpString};

/// Instruments the physical type of GNSS sensor input to the fuzed solution.
///
/// Metadata around the GNSS sensors involved in the fuzed solution.
/// Accessible through sol_in[N].flags in a MSG_SOLN_META.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct GNSSInputType {
    /// flags that store all relevant info specific to this sensor type.
    pub flags: u8,
}

impl SbpParse<GNSSInputType> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<GNSSInputType> {
        Ok( GNSSInputType{
            flags: self.parse()?,
        } )
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

/// Provides detail about the IMU sensor, its timestamping mode, and its quality for input to the fuzed solution.
///
/// Metadata around the IMU sensors involved in the fuzed solution.
/// Accessible through sol_in[N].flags in a MSG_SOLN_META.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct IMUInputType {
    /// Instrument time, grade, and architecture for a sensor.
    pub flags: u8,
}

impl SbpParse<IMUInputType> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<IMUInputType> {
        Ok( IMUInputType{
            flags: self.parse()?,
        } )
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
/// This message contains all metadata about the sensors received and/or used in computing the sensorfusion solution.
/// It focuses primarly, but not only, on GNSS metadata.
/// Regarding the age of the last received valid GNSS solution, the highest two bits are time status, indicating
/// whether age gnss can or can not be used to retrieve time of measurement (noted TOM, also known as time of validity)
/// If it can, substract 'age gnss' from 'tow' in navigation messages to get TOM. Can be used before alignment is
/// complete in the Fusion Engine, when output solution is the last received valid GNSS solution and its tow is not a TOM.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSolnMeta {
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

impl SbpParse<MsgSolnMeta> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSolnMeta> {
        Ok( MsgSolnMeta{
            sender_id: None,
            tow: self.parse()?,
            pdop: self.parse()?,
            hdop: self.parse()?,
            vdop: self.parse()?,
            age_corrections: self.parse()?,
            age_gnss: self.parse()?,
            sol_in: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgSolnMeta {
    fn get_message_type(&self) -> u16 {
        65294
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
/// This message contains all metadata about the sensors received and/or used in computing the Fuzed Solution.
/// It focuses primarly, but not only, on GNSS metadata.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSolnMetaDepA {
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

impl SbpParse<MsgSolnMetaDepA> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgSolnMetaDepA> {
        Ok( MsgSolnMetaDepA{
            sender_id: None,
            pdop: self.parse()?,
            hdop: self.parse()?,
            vdop: self.parse()?,
            n_sats: self.parse()?,
            age_corrections: self.parse()?,
            alignment_status: self.parse()?,
            last_used_gnss_pos_tow: self.parse()?,
            last_used_gnss_vel_tow: self.parse()?,
            sol_in: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgSolnMetaDepA {
    fn get_message_type(&self) -> u16 {
        65295
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

/// Provides detail about the Odometry sensor, its timestamping mode, and its quality for input to the fuzed solution.
///
/// Metadata around the Odometry sensors involved in the fuzed solution.
/// Accessible through sol_in[N].flags in a MSG_SOLN_META.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct OdoInputType {
    /// Instrument ODO rate, grade, and quality.
    pub flags: u8,
}

impl SbpParse<OdoInputType> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<OdoInputType> {
        Ok( OdoInputType{
            flags: self.parse()?,
        } )
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

/// Flags for a given solution input type.
///
/// Metadata describing which sensors were involved in the solution.
/// The structure is fixed no matter what the actual sensor type is.
/// The sensor_type field tells you which sensor we are talking about. It also tells you
/// whether the sensor data was actually used or not.
/// The flags field, always a u8, contains the sensor-specific data.
/// The content of flags, for each sensor type, is described in the relevant structures in this section.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct SolutionInputType {
    /// The type of sensor
    pub sensor_type: u8,
    /// Refer to each InputType description
    pub flags: u8,
}

impl SbpParse<SolutionInputType> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<SolutionInputType> {
        Ok( SolutionInputType{
            sensor_type: self.parse()?,
            flags: self.parse()?,
        } )
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
