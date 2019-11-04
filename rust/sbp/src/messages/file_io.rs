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
// Automatically generated from yaml/swiftnav/sbp/file_io.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages for using device's onboard flash filesystem
//! functionality. This allows data to be stored persistently in the
//! device's program flash with wear-levelling using a simple filesystem
//! interface. The file system interface (CFS) defines an abstract API
//! for reading directories and for reading and writing files.
//!
//! Note that some of these messages share the same message type ID for both the
//! host request and the device response.
//!

extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};

/// Request advice on the optimal configuration for FileIO.
///
/// Requests advice on the optimal configuration for a FileIO
/// transfer.  Newer version of FileIO can support greater
/// throughput by supporting a large window of FileIO data
/// that can be in-flight during read or write operations.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgFileioConfigReq {
    pub sender_id: Option<u16>,
    /// Advice sequence number
    pub sequence: u32,
}

impl MsgFileioConfigReq {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFileioConfigReq, ::Error> {
        Ok(MsgFileioConfigReq {
            sender_id: None,
            sequence: _buf.read_u32::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgFileioConfigReq {
    const MSG_ID: u16 = 4097;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Response with advice on the optimal configuration for FileIO.

///
/// The advice on the optimal configuration for a FileIO
/// transfer.  Newer version of FileIO can support greater
/// throughput by supporting a large window of FileIO data
/// that can be in-flight during read or write operations.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgFileioConfigResp {
    pub sender_id: Option<u16>,
    /// Advice sequence number
    pub sequence: u32,
    /// The number of SBP packets in the data in-flight window
    pub window_size: u32,
    /// The number of SBP packets sent in one PDU
    pub batch_size: u32,
    /// The version of FileIO that is supported
    pub fileio_version: u32,
}

impl MsgFileioConfigResp {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFileioConfigResp, ::Error> {
        Ok(MsgFileioConfigResp {
            sender_id: None,
            sequence: _buf.read_u32::<LittleEndian>()?,
            window_size: _buf.read_u32::<LittleEndian>()?,
            batch_size: _buf.read_u32::<LittleEndian>()?,
            fileio_version: _buf.read_u32::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgFileioConfigResp {
    const MSG_ID: u16 = 4098;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// List files in a directory (host => device)
///
/// The read directory message lists the files in a directory on the
/// device's onboard flash file system.  The offset parameter can be
/// used to skip the first n elements of the file list. Returns a
/// MSG_FILEIO_READ_DIR_RESP message containing the directory
/// listings as a NULL delimited list. The listing is chunked over
/// multiple SBP packets. The sequence number in the request will be
/// returned in the response.  If message is invalid, a followup
/// MSG_PRINT message will print "Invalid fileio read message".
/// A device will only respond to this message when it is received
/// from sender ID 0x42.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgFileioReadDirReq {
    pub sender_id: Option<u16>,
    /// Read sequence number
    pub sequence: u32,
    /// The offset to skip the first n elements of the file list
    pub offset: u32,
    /// Name of the directory to list
    pub dirname: String,
}

impl MsgFileioReadDirReq {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFileioReadDirReq, ::Error> {
        Ok(MsgFileioReadDirReq {
            sender_id: None,
            sequence: _buf.read_u32::<LittleEndian>()?,
            offset: _buf.read_u32::<LittleEndian>()?,
            dirname: ::parser::read_string(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgFileioReadDirReq {
    const MSG_ID: u16 = 169;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Files listed in a directory (host <= device)
///
/// The read directory message lists the files in a directory on the
/// device's onboard flash file system. Message contains the directory
/// listings as a NULL delimited list. The listing is chunked over
/// multiple SBP packets and the end of the list is identified by an
/// entry containing just the character 0xFF. The sequence number in
/// the response is preserved from the request.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgFileioReadDirResp {
    pub sender_id: Option<u16>,
    /// Read sequence number
    pub sequence: u32,
    /// Contents of read directory
    pub contents: Vec<u8>,
}

impl MsgFileioReadDirResp {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFileioReadDirResp, ::Error> {
        Ok(MsgFileioReadDirResp {
            sender_id: None,
            sequence: _buf.read_u32::<LittleEndian>()?,
            contents: ::parser::read_u8_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgFileioReadDirResp {
    const MSG_ID: u16 = 170;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Read file from the file system (host => device)
///
/// The file read message reads a certain length (up to 255 bytes)
/// from a given offset into a file, and returns the data in a
/// MSG_FILEIO_READ_RESP message where the message length field
/// indicates how many bytes were succesfully read.The sequence
/// number in the request will be returned in the response.
/// If the message is invalid, a followup MSG_PRINT message will
/// print "Invalid fileio read message". A device will only respond
/// to this message when it is received from sender ID 0x42.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgFileioReadReq {
    pub sender_id: Option<u16>,
    /// Read sequence number
    pub sequence: u32,
    /// File offset
    pub offset: u32,
    /// Chunk size to read
    pub chunk_size: u8,
    /// Name of the file to read from
    pub filename: String,
}

impl MsgFileioReadReq {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFileioReadReq, ::Error> {
        Ok(MsgFileioReadReq {
            sender_id: None,
            sequence: _buf.read_u32::<LittleEndian>()?,
            offset: _buf.read_u32::<LittleEndian>()?,
            chunk_size: _buf.read_u8()?,
            filename: ::parser::read_string(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgFileioReadReq {
    const MSG_ID: u16 = 168;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// File read from the file system (host <= device)
///
/// The file read message reads a certain length (up to 255 bytes)
/// from a given offset into a file, and returns the data in a
/// message where the message length field indicates how many bytes
/// were succesfully read. The sequence number in the response is
/// preserved from the request.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgFileioReadResp {
    pub sender_id: Option<u16>,
    /// Read sequence number
    pub sequence: u32,
    /// Contents of read file
    pub contents: Vec<u8>,
}

impl MsgFileioReadResp {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFileioReadResp, ::Error> {
        Ok(MsgFileioReadResp {
            sender_id: None,
            sequence: _buf.read_u32::<LittleEndian>()?,
            contents: ::parser::read_u8_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgFileioReadResp {
    const MSG_ID: u16 = 163;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Delete a file from the file system (host => device)
///
/// The file remove message deletes a file from the file system.
/// If the message is invalid, a followup MSG_PRINT message will
/// print "Invalid fileio remove message". A device will only
/// process this message when it is received from sender ID 0x42.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgFileioRemove {
    pub sender_id: Option<u16>,
    /// Name of the file to delete
    pub filename: String,
}

impl MsgFileioRemove {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFileioRemove, ::Error> {
        Ok(MsgFileioRemove {
            sender_id: None,
            filename: ::parser::read_string(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgFileioRemove {
    const MSG_ID: u16 = 172;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// Write to file (host => device)
///
/// The file write message writes a certain length (up to 255 bytes)
/// of data to a file at a given offset. Returns a copy of the
/// original MSG_FILEIO_WRITE_RESP message to check integrity of
/// the write. The sequence number in the request will be returned
/// in the response. If message is invalid, a followup MSG_PRINT
/// message will print "Invalid fileio write message". A device will
/// only  process this message when it is received from sender ID
/// 0x42.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgFileioWriteReq {
    pub sender_id: Option<u16>,
    /// Write sequence number
    pub sequence: u32,
    /// Offset into the file at which to start writing in bytes
    pub offset: u32,
    /// Name of the file to write to
    pub filename: String,
    /// Variable-length array of data to write
    pub data: Vec<u8>,
}

impl MsgFileioWriteReq {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFileioWriteReq, ::Error> {
        Ok(MsgFileioWriteReq {
            sender_id: None,
            sequence: _buf.read_u32::<LittleEndian>()?,
            offset: _buf.read_u32::<LittleEndian>()?,
            filename: ::parser::read_string(_buf)?,
            data: ::parser::read_u8_array(_buf)?,
        })
    }
}
impl super::SBPMessage for MsgFileioWriteReq {
    const MSG_ID: u16 = 173;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}

/// File written to (host <= device)
///
/// The file write message writes a certain length (up to 255 bytes)
/// of data to a file at a given offset. The message is a copy of the
/// original MSG_FILEIO_WRITE_REQ message to check integrity of the
/// write. The sequence number in the response is preserved from the
/// request.
///
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgFileioWriteResp {
    pub sender_id: Option<u16>,
    /// Write sequence number
    pub sequence: u32,
}

impl MsgFileioWriteResp {
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFileioWriteResp, ::Error> {
        Ok(MsgFileioWriteResp {
            sender_id: None,
            sequence: _buf.read_u32::<LittleEndian>()?,
        })
    }
}
impl super::SBPMessage for MsgFileioWriteResp {
    const MSG_ID: u16 = 171;

    fn get_sender_id(&self) -> Option<u16> {
        self.sender_id
    }

    fn set_sender_id(&mut self, new_id: u16) {
        self.sender_id = Some(new_id);
    }
}
