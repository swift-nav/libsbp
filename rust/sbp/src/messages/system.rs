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
// Standardized system messages from Swift Navigation devices.
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};

// System start-up message
//
// The system start-up message is sent once on system
// start-up. It notifies the host or other attached devices that
// the system has started and is now ready to respond to commands
// or configuration requests.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgStartup {
    pub cause: u8,
    // ^ Cause of startup
    pub startup_type: u8,
    // ^ Startup type
    pub reserved: u16,
    // ^ Reserved
}

impl MsgStartup {
    pub const TYPE: u16 = 65280;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgStartup, ::parser::MessageError> {
        Ok(MsgStartup {
            cause: _buf.read_u8()?,
            startup_type: _buf.read_u8()?,
            reserved: _buf.read_u16::<LittleEndian>()?,
        })
    }
}

// Status of received corrections
//
// This message provides information about the receipt of Differential
// corrections.  It is expected to be sent with each receipt of a complete
// corrections packet.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgDgnssStatus {
    pub flags: u8,
    // ^ Status flags
    pub latency: u16,
    // ^ Latency of observation receipt
    pub num_signals: u8,
    // ^ Number of signals from base station
    pub source: String,
    // ^ Corrections source string
}

impl MsgDgnssStatus {
    pub const TYPE: u16 = 65282;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgDgnssStatus, ::parser::MessageError> {
        Ok(MsgDgnssStatus {
            flags: _buf.read_u8()?,
            latency: _buf.read_u16::<LittleEndian>()?,
            num_signals: _buf.read_u8()?,
            source: ::parser::read_string(_buf)?,
        })
    }
}

// System heartbeat message
//
// The heartbeat message is sent periodically to inform the host
// or other attached devices that the system is running. It is
// used to monitor system malfunctions. It also contains status
// flags that indicate to the host the status of the system and
// whether it is operating correctly. Currently, the expected
// heartbeat interval is 1 sec.
//
// The system error flag is used to indicate that an error has
// occurred in the system. To determine the source of the error,
// the remaining error flags should be inspected.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgHeartbeat {
    pub flags: u32,
    // ^ Status flags
}

impl MsgHeartbeat {
    pub const TYPE: u16 = 65535;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgHeartbeat, ::parser::MessageError> {
        Ok(MsgHeartbeat {
            flags: _buf.read_u32::<LittleEndian>()?,
        })
    }
}

// Inertial Navigation System status message
//
// The INS status message describes the state of the operation
// and initialization of the inertial navigation system.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgInsStatus {
    pub flags: u32,
    // ^ Status flags
}

impl MsgInsStatus {
    pub const TYPE: u16 = 65283;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgInsStatus, ::parser::MessageError> {
        Ok(MsgInsStatus {
            flags: _buf.read_u32::<LittleEndian>()?,
        })
    }
}

// Experimental telemetry message
//
// The CSAC telemetry message has an implementation defined telemetry string
// from a device. It is not produced or available on general Swift Products.
// It is intended to be a low rate message for status purposes.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgCsacTelemetry {
    pub id: u8,
    // ^ Index representing the type of telemetry in use.  It is implemention
    // defined.
    pub telemetry: String,
    // ^ Comma separated list of values as defined by the index
}

impl MsgCsacTelemetry {
    pub const TYPE: u16 = 65284;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCsacTelemetry, ::parser::MessageError> {
        Ok(MsgCsacTelemetry {
            id: _buf.read_u8()?,
            telemetry: ::parser::read_string(_buf)?,
        })
    }
}

// Experimental telemetry message labels
//
// The CSAC telemetry message provides labels for each member of the string
// produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a lower
// rate than the MSG_CSAC_TELEMETRY.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgCsacTelemetryLabels {
    pub id: u8,
    // ^ Index representing the type of telemetry in use.  It is implemention
    // defined.
    pub telemetry_labels: String,
    // ^ Comma separated list of telemetry field values
}

impl MsgCsacTelemetryLabels {
    pub const TYPE: u16 = 65285;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgCsacTelemetryLabels, ::parser::MessageError> {
        Ok(MsgCsacTelemetryLabels {
            id: _buf.read_u8()?,
            telemetry_labels: ::parser::read_string(_buf)?,
        })
    }
}
