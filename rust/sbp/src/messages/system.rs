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
// Automatically generated from yaml/swiftnav/sbp/system.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Standardized system messages from Swift Navigation devices.

extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};
#[cfg(feature = "serialize")]
use serde::{Deserialize, Serialize};

/// Experimental telemetry message
///
/// The CSAC telemetry message has an implementation defined telemetry string
/// from a device. It is not produced or available on general Swift Products.
/// It is intended to be a low rate message for status purposes.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgCsacTelemetry {
    pub sender_id: Option<u16>,
    /// Index representing the type of telemetry in use.  It is implemention
    /// defined.
    pub id: u8,
    /// Comma separated list of values as defined by the index
    pub telemetry: String,
}

impl MsgCsacTelemetry {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCsacTelemetry, crate::Error> {
        Ok(MsgCsacTelemetry {
            sender_id: None,
            id: _buf.read_u8()?,
            telemetry: crate::parser::read_string(_buf)?,
        })
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
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgCsacTelemetryLabels {
    pub sender_id: Option<u16>,
    /// Index representing the type of telemetry in use.  It is implemention
    /// defined.
    pub id: u8,
    /// Comma separated list of telemetry field values
    pub telemetry_labels: String,
}

impl MsgCsacTelemetryLabels {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCsacTelemetryLabels, crate::Error> {
        Ok(MsgCsacTelemetryLabels {
            sender_id: None,
            id: _buf.read_u8()?,
            telemetry_labels: crate::parser::read_string(_buf)?,
        })
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
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
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
    pub source: String,
}

impl MsgDgnssStatus {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgDgnssStatus, crate::Error> {
        Ok(MsgDgnssStatus {
            sender_id: None,
            flags: _buf.read_u8()?,
            latency: _buf.read_u16::<LittleEndian>()?,
            num_signals: _buf.read_u8()?,
            source: crate::parser::read_string(_buf)?,
        })
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
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgHeartbeat {
    pub sender_id: Option<u16>,
    /// Status flags
    pub flags: u32,
}

impl MsgHeartbeat {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgHeartbeat, crate::Error> {
        Ok(MsgHeartbeat {
            sender_id: None,
            flags: _buf.read_u32::<LittleEndian>()?,
        })
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
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgInsStatus {
    pub sender_id: Option<u16>,
    /// Status flags
    pub flags: u32,
}

impl MsgInsStatus {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgInsStatus, crate::Error> {
        Ok(MsgInsStatus {
            sender_id: None,
            flags: _buf.read_u32::<LittleEndian>()?,
        })
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

/// System start-up message
///
/// The system start-up message is sent once on system
/// start-up. It notifies the host or other attached devices that
/// the system has started and is now ready to respond to commands
/// or configuration requests.
///
#[cfg_attr(feature = "serialize", derive(Serialize, Deserialize))]
#[derive(Debug)]
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
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgStartup, crate::Error> {
        Ok(MsgStartup {
            sender_id: None,
            cause: _buf.read_u8()?,
            startup_type: _buf.read_u8()?,
            reserved: _buf.read_u16::<LittleEndian>()?,
        })
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
