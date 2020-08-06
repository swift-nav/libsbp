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
// Automatically generated from yaml/swiftnav/sbp/solution_meta.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Standardized Metadata messages for Fuzed Solution from Swift Navigation devices.

extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
#[cfg(feature = "sbp_serde")]
use serde::{Deserialize, Serialize};

#[allow(unused_imports)]
use crate::SbpString;

/// Flags for a given GNSS sensor used as input for the fuzed solution.
///
/// Metadata around the GNSS sensors involved in the fuzed solution. Accessible through sol_in[N].flags
///                                                                         in a MSG_SOLN_META.
/// Note: Just to build descriptive tables in documentation and not actually used.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct GNSSInputType {
    pub sender_id: Option<u16>,
    /// flags that store all relevant info specific to this sensor type.
    pub flags: u8,
}

impl GNSSInputType {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<GNSSInputType, crate::Error> {
        Ok( GNSSInputType{
            sender_id: None,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SBPMessage for GNSSInputType {
    fn get_message_type(&self) -> u16 {
        65511
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

/// Flags for a given IMU sensor used as input for the fuzed solution.
///
/// Metadata around the IMU sensors involved in the fuzed solution. Accessible through sol_in[N].flags
///                                                                        in a MSG_SOLN_META.
/// Note: Just to build descriptive tables in documentation and not actually used.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct IMUInputType {
    pub sender_id: Option<u16>,
    /// flags that store all relevant info specific to this sensor type.
    pub flags: u8,
}

impl IMUInputType {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<IMUInputType, crate::Error> {
        Ok( IMUInputType{
            sender_id: None,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SBPMessage for IMUInputType {
    fn get_message_type(&self) -> u16 {
        65512
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
/// This message contains all metadata about the sensors received and/or used in computing the Fuzed Solution.
/// It focuses primarly, but not only, on GNSS metadata.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgSolnMeta {
    pub sender_id: Option<u16>,
    /// Position Dilution of Precision, as per last available DOPS from Starling
    /// GNSS engine
    pub pdop: u16,
    /// Horizontal Dilution of Precision, as per last available DOPS from
    /// Starling GNSS engine
    pub hdop: u16,
    /// Vertical Dilution of Precision, as per last available DOPS from Starling
    /// GNSS engine
    pub vdop: u16,
    /// Number of satellites used in solution, as per last available DOPS from
    /// Starling GNSS engine
    pub n_sats: u8,
    /// Age of the corrections (0xFFFF indicates invalid), as per last available
    /// AGE_CORRECTIONS from Starling GNSS engine
    pub age_corrections: u16,
    /// Bits for reason why it cannot align (yet)
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

impl MsgSolnMeta {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgSolnMeta, crate::Error> {
        Ok( MsgSolnMeta{
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
impl super::SBPMessage for MsgSolnMeta {
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

impl crate::serialize::SbpSerialize for MsgSolnMeta {
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

/// Flags for a given Odometry sensor used as input for the fuzed solution.
///
/// Metadata around the Odometry sensors involved in the fuzed solution. Accessible through sol_in[N].flags
///                                                                             in a MSG_SOLN_META.
/// Note: Just to build descriptive tables in documentation and not actually used.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct OdoInputType {
    pub sender_id: Option<u16>,
    /// flags that store all relevant info specific to this sensor type.
    pub flags: u8,
}

impl OdoInputType {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<OdoInputType, crate::Error> {
        Ok( OdoInputType{
            sender_id: None,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SBPMessage for OdoInputType {
    fn get_message_type(&self) -> u16 {
        65513
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
