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
// Automatically generated from yaml/swiftnav/sbp/file_io.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages for using device's onboard flash filesystem functionality. This
//! allows data to be stored persistently in the device's program flash with
//! wear-levelling using a simple filesystem interface. The file system
//! interface (CFS) defines an abstract API for reading directories and for
//! reading and writing files.
//!
//! Note that some of these messages share the same message type ID for both
//! the host request and the device response.

use super::lib::*;

/// Request advice on the optimal configuration for FileIO
///
/// Requests advice on the optimal configuration for a FileIO transfer.  Newer
/// version of FileIO can support greater throughput by supporting a large
/// window of FileIO data that can be in-flight during read or write
/// operations.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgFileioConfigReq {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Advice sequence number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sequence")))]
    pub sequence: u32,
}

impl ConcreteMessage for MsgFileioConfigReq {
    const MESSAGE_TYPE: u16 = 4097;
    const MESSAGE_NAME: &'static str = "MSG_FILEIO_CONFIG_REQ";
}

impl SbpMessage for MsgFileioConfigReq {
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

impl TryFrom<Sbp> for MsgFileioConfigReq {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgFileioConfigReq(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgFileioConfigReq {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sequence)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sequence, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgFileioConfigReq {
            sender_id: None,
            sequence: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Response with advice on the optimal configuration for FileIO.

///
/// The advice on the optimal configuration for a FileIO transfer.  Newer
/// version of FileIO can support greater throughput by supporting a large
/// window of FileIO data that can be in-flight during read or write
/// operations.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgFileioConfigResp {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Advice sequence number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sequence")))]
    pub sequence: u32,
    /// The number of SBP packets in the data in-flight window
    #[cfg_attr(feature = "serde", serde(rename(serialize = "window_size")))]
    pub window_size: u32,
    /// The number of SBP packets sent in one PDU
    #[cfg_attr(feature = "serde", serde(rename(serialize = "batch_size")))]
    pub batch_size: u32,
    /// The version of FileIO that is supported
    #[cfg_attr(feature = "serde", serde(rename(serialize = "fileio_version")))]
    pub fileio_version: u32,
}

impl ConcreteMessage for MsgFileioConfigResp {
    const MESSAGE_TYPE: u16 = 4098;
    const MESSAGE_NAME: &'static str = "MSG_FILEIO_CONFIG_RESP";
}

impl SbpMessage for MsgFileioConfigResp {
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

impl TryFrom<Sbp> for MsgFileioConfigResp {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgFileioConfigResp(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgFileioConfigResp {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sequence)
            + WireFormat::len(&self.window_size)
            + WireFormat::len(&self.batch_size)
            + WireFormat::len(&self.fileio_version)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sequence, buf);
        WireFormat::write(&self.window_size, buf);
        WireFormat::write(&self.batch_size, buf);
        WireFormat::write(&self.fileio_version, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgFileioConfigResp {
            sender_id: None,
            sequence: WireFormat::parse_unchecked(buf),
            window_size: WireFormat::parse_unchecked(buf),
            batch_size: WireFormat::parse_unchecked(buf),
            fileio_version: WireFormat::parse_unchecked(buf),
        }
    }
}

/// List files in a directory (host => device)
///
/// The read directory message lists the files in a directory on the device's
/// onboard flash file system.  The offset parameter can be used to skip the
/// first n elements of the file list. Returns a MSG_FILEIO_READ_DIR_RESP
/// message containing the directory listings as a NULL delimited list. The
/// listing is chunked over multiple SBP packets. The sequence number in the
/// request will be returned in the response.  If message is invalid, a
/// followup MSG_PRINT message will print "Invalid fileio read message". A
/// device will only respond to this message when it is received from sender
/// ID 0x42.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgFileioReadDirReq {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Read sequence number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sequence")))]
    pub sequence: u32,
    /// The offset to skip the first n elements of the file list
    #[cfg_attr(feature = "serde", serde(rename(serialize = "offset")))]
    pub offset: u32,
    /// Name of the directory to list
    #[cfg_attr(feature = "serde", serde(rename(serialize = "dirname")))]
    pub dirname: SbpString<Vec<u8>, NullTerminated>,
}

impl ConcreteMessage for MsgFileioReadDirReq {
    const MESSAGE_TYPE: u16 = 169;
    const MESSAGE_NAME: &'static str = "MSG_FILEIO_READ_DIR_REQ";
}

impl SbpMessage for MsgFileioReadDirReq {
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

impl TryFrom<Sbp> for MsgFileioReadDirReq {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgFileioReadDirReq(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgFileioReadDirReq {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <SbpString<Vec<u8>, NullTerminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sequence)
            + WireFormat::len(&self.offset)
            + WireFormat::len(&self.dirname)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sequence, buf);
        WireFormat::write(&self.offset, buf);
        WireFormat::write(&self.dirname, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgFileioReadDirReq {
            sender_id: None,
            sequence: WireFormat::parse_unchecked(buf),
            offset: WireFormat::parse_unchecked(buf),
            dirname: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Files listed in a directory (host <= device)
///
/// The read directory message lists the files in a directory on the device's
/// onboard flash file system. Message contains the directory listings as a
/// NULL delimited list. The listing is chunked over multiple SBP packets and
/// the end of the list is identified by an packet with no entries. The
/// sequence number in the response is preserved from the request.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgFileioReadDirResp {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Read sequence number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sequence")))]
    pub sequence: u32,
    /// Contents of read directory
    #[cfg_attr(feature = "serde", serde(rename(serialize = "contents")))]
    pub contents: Vec<u8>,
}

impl ConcreteMessage for MsgFileioReadDirResp {
    const MESSAGE_TYPE: u16 = 170;
    const MESSAGE_NAME: &'static str = "MSG_FILEIO_READ_DIR_RESP";
}

impl SbpMessage for MsgFileioReadDirResp {
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

impl TryFrom<Sbp> for MsgFileioReadDirResp {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgFileioReadDirResp(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgFileioReadDirResp {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN + <Vec<u8> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sequence) + WireFormat::len(&self.contents)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sequence, buf);
        WireFormat::write(&self.contents, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgFileioReadDirResp {
            sender_id: None,
            sequence: WireFormat::parse_unchecked(buf),
            contents: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Read file from the file system (host => device)
///
/// The file read message reads a certain length (up to 255 bytes) from a
/// given offset into a file, and returns the data in a MSG_FILEIO_READ_RESP
/// message where the message length field indicates how many bytes were
/// successfully read. The sequence number in the request will be returned in
/// the response. If the message is invalid, a followup MSG_PRINT message will
/// print "Invalid fileio read message". A device will only respond to this
/// message when it is received from sender ID 0x42.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgFileioReadReq {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Read sequence number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sequence")))]
    pub sequence: u32,
    /// File offset
    #[cfg_attr(feature = "serde", serde(rename(serialize = "offset")))]
    pub offset: u32,
    /// Chunk size to read
    #[cfg_attr(feature = "serde", serde(rename(serialize = "chunk_size")))]
    pub chunk_size: u8,
    /// Name of the file to read from
    #[cfg_attr(feature = "serde", serde(rename(serialize = "filename")))]
    pub filename: SbpString<Vec<u8>, NullTerminated>,
}

impl ConcreteMessage for MsgFileioReadReq {
    const MESSAGE_TYPE: u16 = 168;
    const MESSAGE_NAME: &'static str = "MSG_FILEIO_READ_REQ";
}

impl SbpMessage for MsgFileioReadReq {
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

impl TryFrom<Sbp> for MsgFileioReadReq {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgFileioReadReq(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgFileioReadReq {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <SbpString<Vec<u8>, NullTerminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sequence)
            + WireFormat::len(&self.offset)
            + WireFormat::len(&self.chunk_size)
            + WireFormat::len(&self.filename)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sequence, buf);
        WireFormat::write(&self.offset, buf);
        WireFormat::write(&self.chunk_size, buf);
        WireFormat::write(&self.filename, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgFileioReadReq {
            sender_id: None,
            sequence: WireFormat::parse_unchecked(buf),
            offset: WireFormat::parse_unchecked(buf),
            chunk_size: WireFormat::parse_unchecked(buf),
            filename: WireFormat::parse_unchecked(buf),
        }
    }
}

/// File read from the file system (host <= device)
///
/// The file read message reads a certain length (up to 255 bytes) from a
/// given offset into a file, and returns the data in a message where the
/// message length field indicates how many bytes were successfully read. The
/// sequence number in the response is preserved from the request.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgFileioReadResp {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Read sequence number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sequence")))]
    pub sequence: u32,
    /// Contents of read file
    #[cfg_attr(feature = "serde", serde(rename(serialize = "contents")))]
    pub contents: Vec<u8>,
}

impl ConcreteMessage for MsgFileioReadResp {
    const MESSAGE_TYPE: u16 = 163;
    const MESSAGE_NAME: &'static str = "MSG_FILEIO_READ_RESP";
}

impl SbpMessage for MsgFileioReadResp {
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

impl TryFrom<Sbp> for MsgFileioReadResp {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgFileioReadResp(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgFileioReadResp {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN + <Vec<u8> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sequence) + WireFormat::len(&self.contents)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sequence, buf);
        WireFormat::write(&self.contents, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgFileioReadResp {
            sender_id: None,
            sequence: WireFormat::parse_unchecked(buf),
            contents: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Delete a file from the file system (host => device)
///
/// The file remove message deletes a file from the file system. If the
/// message is invalid, a followup MSG_PRINT message will print "Invalid
/// fileio remove message". A device will only process this message when it is
/// received from sender ID 0x42.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgFileioRemove {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Name of the file to delete
    #[cfg_attr(feature = "serde", serde(rename(serialize = "filename")))]
    pub filename: SbpString<Vec<u8>, NullTerminated>,
}

impl ConcreteMessage for MsgFileioRemove {
    const MESSAGE_TYPE: u16 = 172;
    const MESSAGE_NAME: &'static str = "MSG_FILEIO_REMOVE";
}

impl SbpMessage for MsgFileioRemove {
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

impl TryFrom<Sbp> for MsgFileioRemove {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgFileioRemove(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgFileioRemove {
    const MIN_LEN: usize = <SbpString<Vec<u8>, NullTerminated> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.filename)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.filename, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgFileioRemove {
            sender_id: None,
            filename: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Write to file (host => device)
///
/// The file write message writes a certain length (up to 255 bytes) of data
/// to a file at a given offset. Returns a copy of the original
/// MSG_FILEIO_WRITE_RESP message to check integrity of the write. The
/// sequence number in the request will be returned in the response. If
/// message is invalid, a followup MSG_PRINT message will print "Invalid
/// fileio write message". A device will only process this message when it is
/// received from sender ID 0x42.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgFileioWriteReq {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Write sequence number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sequence")))]
    pub sequence: u32,
    /// Offset into the file at which to start writing in bytes
    #[cfg_attr(feature = "serde", serde(rename(serialize = "offset")))]
    pub offset: u32,
    /// Name of the file to write to
    #[cfg_attr(feature = "serde", serde(rename(serialize = "filename")))]
    pub filename: SbpString<Vec<u8>, NullTerminated>,
    /// Variable-length array of data to write
    #[cfg_attr(feature = "serde", serde(rename(serialize = "data")))]
    pub data: Vec<u8>,
}

impl ConcreteMessage for MsgFileioWriteReq {
    const MESSAGE_TYPE: u16 = 173;
    const MESSAGE_NAME: &'static str = "MSG_FILEIO_WRITE_REQ";
}

impl SbpMessage for MsgFileioWriteReq {
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

impl TryFrom<Sbp> for MsgFileioWriteReq {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgFileioWriteReq(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgFileioWriteReq {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN
        + <u32 as WireFormat>::MIN_LEN
        + <SbpString<Vec<u8>, NullTerminated> as WireFormat>::MIN_LEN
        + <Vec<u8> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sequence)
            + WireFormat::len(&self.offset)
            + WireFormat::len(&self.filename)
            + WireFormat::len(&self.data)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sequence, buf);
        WireFormat::write(&self.offset, buf);
        WireFormat::write(&self.filename, buf);
        WireFormat::write(&self.data, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgFileioWriteReq {
            sender_id: None,
            sequence: WireFormat::parse_unchecked(buf),
            offset: WireFormat::parse_unchecked(buf),
            filename: WireFormat::parse_unchecked(buf),
            data: WireFormat::parse_unchecked(buf),
        }
    }
}

/// File written to (host <= device)
///
/// The file write message writes a certain length (up to 255 bytes) of data
/// to a file at a given offset. The message is a copy of the original
/// MSG_FILEIO_WRITE_REQ message to check integrity of the write. The sequence
/// number in the response is preserved from the request.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgFileioWriteResp {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Write sequence number
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sequence")))]
    pub sequence: u32,
}

impl ConcreteMessage for MsgFileioWriteResp {
    const MESSAGE_TYPE: u16 = 171;
    const MESSAGE_NAME: &'static str = "MSG_FILEIO_WRITE_RESP";
}

impl SbpMessage for MsgFileioWriteResp {
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

impl TryFrom<Sbp> for MsgFileioWriteResp {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgFileioWriteResp(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgFileioWriteResp {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sequence)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sequence, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgFileioWriteResp {
            sender_id: None,
            sequence: WireFormat::parse_unchecked(buf),
        }
    }
}
