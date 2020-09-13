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

extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
#[cfg(feature = "sbp_serde")]
use serde::{Deserialize, Serialize};

#[allow(unused_imports)]
use crate::SbpString;

/// Experimental telemetry message
///
/// The CSAC telemetry message has an implementation defined telemetry string
/// from a device. It is not produced or available on general Swift Products.
/// It is intended to be a low rate message for status purposes.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgCsacTelemetry {
    pub sender_id: Option<u16>,
    /// Index representing the type of telemetry in use.  It is implemention
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
    fn get_message_type(&self) -> u16 {
        65284
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
/// produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a lower
/// rate than the MSG_CSAC_TELEMETRY.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgCsacTelemetryLabels {
    pub sender_id: Option<u16>,
    /// Index representing the type of telemetry in use.  It is implemention
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
    fn get_message_type(&self) -> u16 {
        65285
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
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgDgnssStatus {
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
    fn get_message_type(&self) -> u16 {
        65282
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
/// The GNSS time offset message contains the information that is needed to translate messages
/// tagged with a local timestamp (e.g. IMU or wheeltick messages) to GNSS time for the sender
/// producing this message.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgGnssTimeOffset {
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
    fn get_message_type(&self) -> u16 {
        65287
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
/// This leading message lists the time metadata of the Solution Group.
/// It also lists the atomic contents (i.e. types of messages included) of the Solution Group.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgGroupMeta {
    pub sender_id: Option<u16>,
    /// Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss
    pub group_id: u8,
    /// Status flags (reserved)
    pub flags: u8,
    /// Size of list group_msgs
    pub n_group_msgs: u8,
    /// An inorder list of message types included in the Solution Group,
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
    fn get_message_type(&self) -> u16 {
        65290
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
/// The heartbeat message is sent periodically to inform the host
/// or other attached devices that the system is running. It is
/// used to monitor system malfunctions. It also contains status
/// flags that indicate to the host the status of the system and
/// whether it is operating correctly. Currently, the expected
/// heartbeat interval is 1 sec.
///
/// The system error flag is used to indicate that an error has
/// occurred in the system. To determine the source of the error,
/// the remaining error flags should be inspected.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgHeartbeat {
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
    fn get_message_type(&self) -> u16 {
        65535
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
/// The INS status message describes the state of the operation
/// and initialization of the inertial navigation system.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgInsStatus {
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
    fn get_message_type(&self) -> u16 {
        65283
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
/// The INS update status message contains informations about executed and rejected INS updates.
/// This message is expected to be extended in the future as new types of measurements are being added.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgInsUpdates {
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
    fn get_message_type(&self) -> u16 {
        65286
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

/// System start-up message
///
/// The system start-up message is sent once on system
/// start-up. It notifies the host or other attached devices that
/// the system has started and is now ready to respond to commands
/// or configuration requests.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgStartup {
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
    fn get_message_type(&self) -> u16 {
        65280
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
