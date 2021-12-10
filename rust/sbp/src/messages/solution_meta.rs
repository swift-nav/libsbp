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

use super::lib::*;

/// Instruments the physical type of GNSS sensor input to the fuzed solution
///
/// Metadata around the GNSS sensors involved in the fuzed solution.
/// Accessible through sol_in\[N\].flags in a MSG_SOLN_META.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct GnssInputType {
    /// flags that store all relevant info specific to this sensor type.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl WireFormat for GnssInputType {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        GnssInputType {
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Provides detail about the IMU sensor, its timestamping mode, and its quality for input to the fuzed solution

///
/// Metadata around the IMU sensors involved in the fuzed solution. Accessible
/// through sol_in\[N\].flags in a MSG_SOLN_META.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct ImuInputType {
    /// Instrument time, grade, and architecture for a sensor.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl WireFormat for ImuInputType {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        ImuInputType {
            flags: WireFormat::parse_unchecked(buf),
        }
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
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSolnMeta {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS time of week rounded to the nearest millisecond
    #[cfg_attr(feature = "serde", serde(rename(serialize = "tow")))]
    pub tow: u32,
    /// Position Dilution of Precision as per last available DOPS from PVT
    /// engine (0xFFFF indicates invalid)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pdop")))]
    pub pdop: u16,
    /// Horizontal Dilution of Precision as per last available DOPS from PVT
    /// engine (0xFFFF indicates invalid)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "hdop")))]
    pub hdop: u16,
    /// Vertical Dilution of Precision as per last available DOPS from PVT
    /// engine (0xFFFF indicates invalid)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vdop")))]
    pub vdop: u16,
    /// Age of corrections as per last available AGE_CORRECTIONS from PVT engine
    /// (0xFFFF indicates invalid)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "age_corrections")))]
    pub age_corrections: u16,
    /// Age and Time Status of the last received valid GNSS solution.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "age_gnss")))]
    pub age_gnss: u32,
    /// Array of Metadata describing the sensors potentially involved in the
    /// solution. Each element in the array represents a single sensor type and
    /// consists of flags containing (meta)data pertaining to that specific
    /// single sensor. Refer to each (XX)InputType descriptor in the present
    /// doc.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sol_in")))]
    pub sol_in: Vec<SolutionInputType>,
}

impl ConcreteMessage for MsgSolnMeta {
    const MESSAGE_TYPE: u16 = 65294;
    const MESSAGE_NAME: &'static str = "MSG_SOLN_META";
}

impl SbpMessage for MsgSolnMeta {
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
        let tow_s = (self.tow as f64) / 1000.0;
        let gps_time = match time::GpsTime::new(0, tow_s) {
            Ok(gps_time) => gps_time.tow(),
            Err(e) => return Some(Err(e.into())),
        };
        Some(Ok(time::MessageTime::Rover(gps_time.into())))
    }
}

impl TryFrom<Sbp> for MsgSolnMeta {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSolnMeta(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSolnMeta {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <Vec<SolutionInputType> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.tow)
            + WireFormat::len(&self.pdop)
            + WireFormat::len(&self.hdop)
            + WireFormat::len(&self.vdop)
            + WireFormat::len(&self.age_corrections)
            + WireFormat::len(&self.age_gnss)
            + WireFormat::len(&self.sol_in)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.tow, buf);
        WireFormat::write(&self.pdop, buf);
        WireFormat::write(&self.hdop, buf);
        WireFormat::write(&self.vdop, buf);
        WireFormat::write(&self.age_corrections, buf);
        WireFormat::write(&self.age_gnss, buf);
        WireFormat::write(&self.sol_in, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSolnMeta {
            sender_id: None,
            tow: WireFormat::parse_unchecked(buf),
            pdop: WireFormat::parse_unchecked(buf),
            hdop: WireFormat::parse_unchecked(buf),
            vdop: WireFormat::parse_unchecked(buf),
            age_corrections: WireFormat::parse_unchecked(buf),
            age_gnss: WireFormat::parse_unchecked(buf),
            sol_in: WireFormat::parse_unchecked(buf),
        }
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
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgSolnMetaDepA {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Position Dilution of Precision as per last available DOPS from PVT
    /// engine (0xFFFF indicates invalid)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "pdop")))]
    pub pdop: u16,
    /// Horizontal Dilution of Precision as per last available DOPS from PVT
    /// engine (0xFFFF indicates invalid)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "hdop")))]
    pub hdop: u16,
    /// Vertical Dilution of Precision as per last available DOPS from PVT
    /// engine (0xFFFF indicates invalid)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "vdop")))]
    pub vdop: u16,
    /// Number of satellites as per last available solution from PVT engine
    #[cfg_attr(feature = "serde", serde(rename(serialize = "n_sats")))]
    pub n_sats: u8,
    /// Age of corrections as per last available AGE_CORRECTIONS from PVT engine
    /// (0xFFFF indicates invalid)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "age_corrections")))]
    pub age_corrections: u16,
    /// State of alignment and the status and receipt of the alignment inputs
    #[cfg_attr(feature = "serde", serde(rename(serialize = "alignment_status")))]
    pub alignment_status: u8,
    /// Tow of last-used GNSS position measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "last_used_gnss_pos_tow")))]
    pub last_used_gnss_pos_tow: u32,
    /// Tow of last-used GNSS velocity measurement
    #[cfg_attr(feature = "serde", serde(rename(serialize = "last_used_gnss_vel_tow")))]
    pub last_used_gnss_vel_tow: u32,
    /// Array of Metadata describing the sensors potentially involved in the
    /// solution. Each element in the array represents a single sensor type and
    /// consists of flags containing (meta)data pertaining to that specific
    /// single sensor. Refer to each (XX)InputType descriptor in the present
    /// doc.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sol_in")))]
    pub sol_in: Vec<SolutionInputType>,
}

impl ConcreteMessage for MsgSolnMetaDepA {
    const MESSAGE_TYPE: u16 = 65295;
    const MESSAGE_NAME: &'static str = "MSG_SOLN_META_DEP_A";
}

impl SbpMessage for MsgSolnMetaDepA {
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

impl TryFrom<Sbp> for MsgSolnMetaDepA {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgSolnMetaDepA(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgSolnMetaDepA {
    const MIN_LEN: usize = <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u16 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <Vec<SolutionInputType> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.pdop)
            + WireFormat::len(&self.hdop)
            + WireFormat::len(&self.vdop)
            + WireFormat::len(&self.n_sats)
            + WireFormat::len(&self.age_corrections)
            + WireFormat::len(&self.alignment_status)
            + WireFormat::len(&self.last_used_gnss_pos_tow)
            + WireFormat::len(&self.last_used_gnss_vel_tow)
            + WireFormat::len(&self.sol_in)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.pdop, buf);
        WireFormat::write(&self.hdop, buf);
        WireFormat::write(&self.vdop, buf);
        WireFormat::write(&self.n_sats, buf);
        WireFormat::write(&self.age_corrections, buf);
        WireFormat::write(&self.alignment_status, buf);
        WireFormat::write(&self.last_used_gnss_pos_tow, buf);
        WireFormat::write(&self.last_used_gnss_vel_tow, buf);
        WireFormat::write(&self.sol_in, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgSolnMetaDepA {
            sender_id: None,
            pdop: WireFormat::parse_unchecked(buf),
            hdop: WireFormat::parse_unchecked(buf),
            vdop: WireFormat::parse_unchecked(buf),
            n_sats: WireFormat::parse_unchecked(buf),
            age_corrections: WireFormat::parse_unchecked(buf),
            alignment_status: WireFormat::parse_unchecked(buf),
            last_used_gnss_pos_tow: WireFormat::parse_unchecked(buf),
            last_used_gnss_vel_tow: WireFormat::parse_unchecked(buf),
            sol_in: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Provides detail about the Odometry sensor, its timestamping mode, and its quality for input to the fuzed solution

///
/// Metadata around the Odometry sensors involved in the fuzed solution.
/// Accessible through sol_in\[N\].flags in a MSG_SOLN_META.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct OdoInputType {
    /// Instrument ODO rate, grade, and quality.
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl WireFormat for OdoInputType {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        OdoInputType {
            flags: WireFormat::parse_unchecked(buf),
        }
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
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct SolutionInputType {
    /// The type of sensor
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sensor_type")))]
    pub sensor_type: u8,
    /// Refer to each InputType description
    #[cfg_attr(feature = "serde", serde(rename(serialize = "flags")))]
    pub flags: u8,
}

impl WireFormat for SolutionInputType {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sensor_type) + WireFormat::len(&self.flags)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sensor_type, buf);
        WireFormat::write(&self.flags, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        SolutionInputType {
            sensor_type: WireFormat::parse_unchecked(buf),
            flags: WireFormat::parse_unchecked(buf),
        }
    }
}
