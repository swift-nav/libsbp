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
// Automatically generated from yaml/swiftnav/sbp/system.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Standardized system messages from Swift Navigation devices.

#[allow(unused_imports)]
use std::convert::TryFrom;

#[allow(unused_imports)]
use byteorder::{LittleEndian, ReadBytesExt};

#[allow(unused_imports)]
use crate::serialize::SbpSerialize;
#[allow(unused_imports)]
use crate::SbpString;

/// Experimental telemetry message
///
/// The CSAC telemetry message has an implementation defined telemetry string
/// from a device. It is not produced or available on general Swift Products.
/// It is intended to be a low rate message for status purposes.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgCsacTelemetry {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Index representing the type of telemetry in use.  It is implementation
    /// defined.
    pub id: u8,
    /// Comma separated list of values as defined by the index
    pub telemetry: SbpString,
}

impl MsgCsacTelemetry {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCsacTelemetry, crate::Error> {
        Ok( MsgCsacTelemetry{
            sender_id: None,
            id: _buf.read_u8()?,
            telemetry: crate::parser::read_string(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgCsacTelemetry {
    fn get_message_name(&self) -> &'static str {
        "MSG_CSAC_TELEMETRY"
    }

    fn get_message_type(&self) -> u16 {
        65284
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
impl super::ConcreteMessage for MsgCsacTelemetry {
    const MESSAGE_TYPE: u16 = 65284;
    const MESSAGE_NAME: &'static str = "MSG_CSAC_TELEMETRY";
}
impl TryFrom<super::SBP> for MsgCsacTelemetry {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgCsacTelemetry(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgCsacTelemetry {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.id.append_to_sbp_buffer(buf);
        self.telemetry.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.id.sbp_size();
        size += self.telemetry.sbp_size();
        size
    }
}

/// Experimental telemetry message labels
///
/// The CSAC telemetry message provides labels for each member of the string
/// produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a
/// lower rate than the MSG_CSAC_TELEMETRY.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgCsacTelemetryLabels {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Index representing the type of telemetry in use.  It is implementation
    /// defined.
    pub id: u8,
    /// Comma separated list of telemetry field values
    pub telemetry_labels: SbpString,
}

impl MsgCsacTelemetryLabels {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCsacTelemetryLabels, crate::Error> {
        Ok( MsgCsacTelemetryLabels{
            sender_id: None,
            id: _buf.read_u8()?,
            telemetry_labels: crate::parser::read_string(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgCsacTelemetryLabels {
    fn get_message_name(&self) -> &'static str {
        "MSG_CSAC_TELEMETRY_LABELS"
    }

    fn get_message_type(&self) -> u16 {
        65285
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
impl super::ConcreteMessage for MsgCsacTelemetryLabels {
    const MESSAGE_TYPE: u16 = 65285;
    const MESSAGE_NAME: &'static str = "MSG_CSAC_TELEMETRY_LABELS";
}
impl TryFrom<super::SBP> for MsgCsacTelemetryLabels {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgCsacTelemetryLabels(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgCsacTelemetryLabels {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.id.append_to_sbp_buffer(buf);
        self.telemetry_labels.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.id.sbp_size();
        size += self.telemetry_labels.sbp_size();
        size
    }
}

/// Status of received corrections
///
/// This message provides information about the receipt of Differential
/// corrections.  It is expected to be sent with each receipt of a complete
/// corrections packet.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgDgnssStatus {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Status flags
    pub flags: u8,
    /// Latency of observation receipt
    pub latency: u16,
    /// Number of signals from base station
    pub num_signals: u8,
    /// Corrections source string
    pub source: SbpString,
}

impl MsgDgnssStatus {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgDgnssStatus, crate::Error> {
        Ok( MsgDgnssStatus{
            sender_id: None,
            flags: _buf.read_u8()?,
            latency: _buf.read_u16::<LittleEndian>()?,
            num_signals: _buf.read_u8()?,
            source: crate::parser::read_string(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgDgnssStatus {
    fn get_message_name(&self) -> &'static str {
        "MSG_DGNSS_STATUS"
    }

    fn get_message_type(&self) -> u16 {
        65282
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
impl super::ConcreteMessage for MsgDgnssStatus {
    const MESSAGE_TYPE: u16 = 65282;
    const MESSAGE_NAME: &'static str = "MSG_DGNSS_STATUS";
}
impl TryFrom<super::SBP> for MsgDgnssStatus {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgDgnssStatus(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgDgnssStatus {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.flags.append_to_sbp_buffer(buf);
        self.latency.append_to_sbp_buffer(buf);
        self.num_signals.append_to_sbp_buffer(buf);
        self.source.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.flags.sbp_size();
        size += self.latency.sbp_size();
        size += self.num_signals.sbp_size();
        size += self.source.sbp_size();
        size
    }
}

/// Offset of the local time with respect to GNSS time
///
/// The GNSS time offset message contains the information that is needed to
/// translate messages tagged with a local timestamp (e.g. IMU or wheeltick
/// messages) to GNSS time for the sender producing this message.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgGnssTimeOffset {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Weeks portion of the time offset
    pub weeks: i16,
    /// Milliseconds portion of the time offset
    pub milliseconds: i32,
    /// Microseconds portion of the time offset
    pub microseconds: i16,
    /// Status flags (reserved)
    pub flags: u8,
}

impl MsgGnssTimeOffset {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgGnssTimeOffset, crate::Error> {
        Ok( MsgGnssTimeOffset{
            sender_id: None,
            weeks: _buf.read_i16::<LittleEndian>()?,
            milliseconds: _buf.read_i32::<LittleEndian>()?,
            microseconds: _buf.read_i16::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SBPMessage for MsgGnssTimeOffset {
    fn get_message_name(&self) -> &'static str {
        "MSG_GNSS_TIME_OFFSET"
    }

    fn get_message_type(&self) -> u16 {
        65287
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
impl super::ConcreteMessage for MsgGnssTimeOffset {
    const MESSAGE_TYPE: u16 = 65287;
    const MESSAGE_NAME: &'static str = "MSG_GNSS_TIME_OFFSET";
}
impl TryFrom<super::SBP> for MsgGnssTimeOffset {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgGnssTimeOffset(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgGnssTimeOffset {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.weeks.append_to_sbp_buffer(buf);
        self.milliseconds.append_to_sbp_buffer(buf);
        self.microseconds.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.weeks.sbp_size();
        size += self.milliseconds.sbp_size();
        size += self.microseconds.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// Solution Group Metadata
///
/// This leading message lists the time metadata of the Solution Group. It
/// also lists the atomic contents (i.e. types of messages included) of the
/// Solution Group.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgGroupMeta {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss
    pub group_id: u8,
    /// Status flags (reserved)
    pub flags: u8,
    /// Size of list group_msgs
    pub n_group_msgs: u8,
    /// An in-order list of message types included in the Solution Group,
    /// including GROUP_META itself
    pub group_msgs: Vec<u16>,
}

impl MsgGroupMeta {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgGroupMeta, crate::Error> {
        Ok( MsgGroupMeta{
            sender_id: None,
            group_id: _buf.read_u8()?,
            flags: _buf.read_u8()?,
            n_group_msgs: _buf.read_u8()?,
            group_msgs: crate::parser::read_u16_array(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgGroupMeta {
    fn get_message_name(&self) -> &'static str {
        "MSG_GROUP_META"
    }

    fn get_message_type(&self) -> u16 {
        65290
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
impl super::ConcreteMessage for MsgGroupMeta {
    const MESSAGE_TYPE: u16 = 65290;
    const MESSAGE_NAME: &'static str = "MSG_GROUP_META";
}
impl TryFrom<super::SBP> for MsgGroupMeta {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgGroupMeta(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgGroupMeta {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.group_id.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
        self.n_group_msgs.append_to_sbp_buffer(buf);
        self.group_msgs.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.group_id.sbp_size();
        size += self.flags.sbp_size();
        size += self.n_group_msgs.sbp_size();
        size += self.group_msgs.sbp_size();
        size
    }
}

/// System heartbeat message
///
/// The heartbeat message is sent periodically to inform the host or other
/// attached devices that the system is running. It is used to monitor system
/// malfunctions. It also contains status flags that indicate to the host the
/// status of the system and whether it is operating correctly. Currently, the
/// expected heartbeat interval is 1 sec.
///
/// The system error flag is used to indicate that an error has occurred in
/// the system. To determine the source of the error, the remaining error
/// flags should be inspected.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgHeartbeat {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Status flags
    pub flags: u32,
}

impl MsgHeartbeat {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgHeartbeat, crate::Error> {
        Ok( MsgHeartbeat{
            sender_id: None,
            flags: _buf.read_u32::<LittleEndian>()?,
        } )
    }
}
impl super::SBPMessage for MsgHeartbeat {
    fn get_message_name(&self) -> &'static str {
        "MSG_HEARTBEAT"
    }

    fn get_message_type(&self) -> u16 {
        65535
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
impl super::ConcreteMessage for MsgHeartbeat {
    const MESSAGE_TYPE: u16 = 65535;
    const MESSAGE_NAME: &'static str = "MSG_HEARTBEAT";
}
impl TryFrom<super::SBP> for MsgHeartbeat {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgHeartbeat(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgHeartbeat {
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

/// Inertial Navigation System status message
///
/// The INS status message describes the state of the operation and
/// initialization of the inertial navigation system.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgInsStatus {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Status flags
    pub flags: u32,
}

impl MsgInsStatus {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgInsStatus, crate::Error> {
        Ok( MsgInsStatus{
            sender_id: None,
            flags: _buf.read_u32::<LittleEndian>()?,
        } )
    }
}
impl super::SBPMessage for MsgInsStatus {
    fn get_message_name(&self) -> &'static str {
        "MSG_INS_STATUS"
    }

    fn get_message_type(&self) -> u16 {
        65283
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
impl super::ConcreteMessage for MsgInsStatus {
    const MESSAGE_TYPE: u16 = 65283;
    const MESSAGE_NAME: &'static str = "MSG_INS_STATUS";
}
impl TryFrom<super::SBP> for MsgInsStatus {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgInsStatus(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgInsStatus {
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

/// Inertial Navigation System update status message
///
/// The INS update status message contains information about executed and
/// rejected INS updates. This message is expected to be extended in the
/// future as new types of measurements are being added.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgInsUpdates {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// GPS Time of Week
    pub tow: u32,
    /// GNSS position update status flags
    pub gnsspos: u8,
    /// GNSS velocity update status flags
    pub gnssvel: u8,
    /// Wheelticks update status flags
    pub wheelticks: u8,
    /// Wheelticks update status flags
    pub speed: u8,
    /// NHC update status flags
    pub nhc: u8,
    /// Zero velocity update status flags
    pub zerovel: u8,
}

impl MsgInsUpdates {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgInsUpdates, crate::Error> {
        Ok( MsgInsUpdates{
            sender_id: None,
            tow: _buf.read_u32::<LittleEndian>()?,
            gnsspos: _buf.read_u8()?,
            gnssvel: _buf.read_u8()?,
            wheelticks: _buf.read_u8()?,
            speed: _buf.read_u8()?,
            nhc: _buf.read_u8()?,
            zerovel: _buf.read_u8()?,
        } )
    }
}
impl super::SBPMessage for MsgInsUpdates {
    fn get_message_name(&self) -> &'static str {
        "MSG_INS_UPDATES"
    }

    fn get_message_type(&self) -> u16 {
        65286
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
impl super::ConcreteMessage for MsgInsUpdates {
    const MESSAGE_TYPE: u16 = 65286;
    const MESSAGE_NAME: &'static str = "MSG_INS_UPDATES";
}
impl TryFrom<super::SBP> for MsgInsUpdates {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgInsUpdates(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgInsUpdates {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.tow.append_to_sbp_buffer(buf);
        self.gnsspos.append_to_sbp_buffer(buf);
        self.gnssvel.append_to_sbp_buffer(buf);
        self.wheelticks.append_to_sbp_buffer(buf);
        self.speed.append_to_sbp_buffer(buf);
        self.nhc.append_to_sbp_buffer(buf);
        self.zerovel.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.tow.sbp_size();
        size += self.gnsspos.sbp_size();
        size += self.gnssvel.sbp_size();
        size += self.wheelticks.sbp_size();
        size += self.speed.sbp_size();
        size += self.nhc.sbp_size();
        size += self.zerovel.sbp_size();
        size
    }
}

/// Local time at detection of PPS pulse
///
/// The PPS time message contains the value of the sender's local time in
/// microseconds at the moment a pulse is detected on the PPS input. This is
/// to be used for syncronisation of sensor data sampled with a local
/// timestamp (e.g. IMU or wheeltick messages) where GNSS time is unknown to
/// the sender.
///
/// The local time used to timestamp the PPS pulse must be generated by the
/// same clock which is used to timestamp the IMU/wheel sensor data and should
/// follow the same roll-over rules.  A separate MSG_PPS_TIME message should
/// be sent for each source of sensor data which uses PPS-relative
/// timestamping.  The sender ID for each of these MSG_PPS_TIME messages
/// should match the sender ID of the respective sensor data.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgPpsTime {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Local time in microseconds
    pub time: u64,
    /// Status flags
    pub flags: u8,
}

impl MsgPpsTime {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgPpsTime, crate::Error> {
        Ok( MsgPpsTime{
            sender_id: None,
            time: _buf.read_u64::<LittleEndian>()?,
            flags: _buf.read_u8()?,
        } )
    }
}
impl super::SBPMessage for MsgPpsTime {
    fn get_message_name(&self) -> &'static str {
        "MSG_PPS_TIME"
    }

    fn get_message_type(&self) -> u16 {
        65288
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
impl super::ConcreteMessage for MsgPpsTime {
    const MESSAGE_TYPE: u16 = 65288;
    const MESSAGE_NAME: &'static str = "MSG_PPS_TIME";
}
impl TryFrom<super::SBP> for MsgPpsTime {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgPpsTime(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgPpsTime {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.time.append_to_sbp_buffer(buf);
        self.flags.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.time.sbp_size();
        size += self.flags.sbp_size();
        size
    }
}

/// System start-up message
///
/// The system start-up message is sent once on system start-up. It notifies
/// the host or other attached devices that the system has started and is now
/// ready to respond to commands or configuration requests.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgStartup {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Cause of startup
    pub cause: u8,
    /// Startup type
    pub startup_type: u8,
    /// Reserved
    pub reserved: u16,
}

impl MsgStartup {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgStartup, crate::Error> {
        Ok( MsgStartup{
            sender_id: None,
            cause: _buf.read_u8()?,
            startup_type: _buf.read_u8()?,
            reserved: _buf.read_u16::<LittleEndian>()?,
        } )
    }
}
impl super::SBPMessage for MsgStartup {
    fn get_message_name(&self) -> &'static str {
        "MSG_STARTUP"
    }

    fn get_message_type(&self) -> u16 {
        65280
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
impl super::ConcreteMessage for MsgStartup {
    const MESSAGE_TYPE: u16 = 65280;
    const MESSAGE_NAME: &'static str = "MSG_STARTUP";
}
impl TryFrom<super::SBP> for MsgStartup {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgStartup(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgStartup {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.cause.append_to_sbp_buffer(buf);
        self.startup_type.append_to_sbp_buffer(buf);
        self.reserved.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.cause.sbp_size();
        size += self.startup_type.sbp_size();
        size += self.reserved.sbp_size();
        size
    }
}

/// Status report message
///
/// The status report is sent periodically to inform the host or other
/// attached devices that the system is running. It is used to monitor system
/// malfunctions. It contains status reports that indicate to the host the
/// status of each sub-system and whether it is operating correctly.
///
/// Interpretation of the subsystem specific status code is product dependent,
/// but if the generic status code is initializing, it should be ignored.
/// Refer to product documentation for details.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgStatusReport {
    #[cfg_attr(feature = "sbp_serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Identity of reporting system
    pub reporting_system: u16,
    /// SBP protocol version
    pub sbp_version: u16,
    /// Increments on each status report sent
    pub sequence: u32,
    /// Number of seconds since system start-up
    pub uptime: u32,
    /// Reported status of individual subsystems
    pub status: Vec<SubSystemReport>,
}

impl MsgStatusReport {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgStatusReport, crate::Error> {
        Ok( MsgStatusReport{
            sender_id: None,
            reporting_system: _buf.read_u16::<LittleEndian>()?,
            sbp_version: _buf.read_u16::<LittleEndian>()?,
            sequence: _buf.read_u32::<LittleEndian>()?,
            uptime: _buf.read_u32::<LittleEndian>()?,
            status: SubSystemReport::parse_array(_buf)?,
        } )
    }
}
impl super::SBPMessage for MsgStatusReport {
    fn get_message_name(&self) -> &'static str {
        "MSG_STATUS_REPORT"
    }

    fn get_message_type(&self) -> u16 {
        65534
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
impl super::ConcreteMessage for MsgStatusReport {
    const MESSAGE_TYPE: u16 = 65534;
    const MESSAGE_NAME: &'static str = "MSG_STATUS_REPORT";
}
impl TryFrom<super::SBP> for MsgStatusReport {
    type Error = super::TryFromSBPError;

    fn try_from(msg: super::SBP) -> Result<Self, Self::Error> {
        match msg {
            super::SBP::MsgStatusReport(m) => Ok(m),
            _ => Err(super::TryFromSBPError),
        }
    }
}

impl crate::serialize::SbpSerialize for MsgStatusReport {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.reporting_system.append_to_sbp_buffer(buf);
        self.sbp_version.append_to_sbp_buffer(buf);
        self.sequence.append_to_sbp_buffer(buf);
        self.uptime.append_to_sbp_buffer(buf);
        self.status.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.reporting_system.sbp_size();
        size += self.sbp_version.sbp_size();
        size += self.sequence.sbp_size();
        size += self.uptime.sbp_size();
        size += self.status.sbp_size();
        size
    }
}

/// Sub-system Status report
///
/// Report the general and specific state of a sub-system.  If the generic
/// state is reported as initializing, the specific state should be ignored.
///
#[cfg_attr(feature = "sbp_serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct SubSystemReport {
    /// Identity of reporting subsystem
    pub component: u16,
    /// Generic form status report
    pub generic: u8,
    /// Subsystem specific status code
    pub specific: u8,
}

impl SubSystemReport {
    #[rustfmt::skip]
    pub fn parse(_buf: &mut &[u8]) -> Result<SubSystemReport, crate::Error> {
        Ok( SubSystemReport{
            component: _buf.read_u16::<LittleEndian>()?,
            generic: _buf.read_u8()?,
            specific: _buf.read_u8()?,
        } )
    }
    pub fn parse_array(buf: &mut &[u8]) -> Result<Vec<SubSystemReport>, crate::Error> {
        let mut v = Vec::new();
        while buf.len() > 0 {
            v.push(SubSystemReport::parse(buf)?);
        }
        Ok(v)
    }

    pub fn parse_array_limit(
        buf: &mut &[u8],
        n: usize,
    ) -> Result<Vec<SubSystemReport>, crate::Error> {
        let mut v = Vec::new();
        for _ in 0..n {
            v.push(SubSystemReport::parse(buf)?);
        }
        Ok(v)
    }
}

impl crate::serialize::SbpSerialize for SubSystemReport {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.component.append_to_sbp_buffer(buf);
        self.generic.append_to_sbp_buffer(buf);
        self.specific.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.component.sbp_size();
        size += self.generic.sbp_size();
        size += self.specific.sbp_size();
        size
    }
}
