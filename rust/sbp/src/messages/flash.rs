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
// Automatically generated from yaml/swiftnav/sbp/flash.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages for reading/writing the device's onboard flash memory. Many of
//! these messages target specific flash memory peripherals used in Swift
//! Navigation devices: the STM32 flash and the M25Pxx FPGA configuration
//! flash from Piksi 2.3.1.  This module does not apply to Piksi Multi.

use super::lib::*;

/// Flash response message (host <= device)
///
/// This message defines success or failure codes for a variety of flash
/// memory requests from the host to the device. Flash read and write
/// messages, such as MSG_FLASH_READ_REQ, or MSG_FLASH_PROGRAM, may return
/// this message on failure.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgFlashDone {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Response flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "response")))]
    pub response: u8,
}

impl ConcreteMessage for MsgFlashDone {
    const MESSAGE_TYPE: u16 = 224;
    const MESSAGE_NAME: &'static str = "MSG_FLASH_DONE";
}

impl SbpMessage for MsgFlashDone {
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

impl TryFrom<Sbp> for MsgFlashDone {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgFlashDone(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgFlashDone {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.response)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.response, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgFlashDone {
            sender_id: None,
            response: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Erase sector of device flash memory (host => device)
///
/// The flash erase message from the host erases a sector of either the STM or
/// M25 onboard flash memory. The device will reply with a MSG_FLASH_DONE
/// message containing the return code - FLASH_OK (0) on success or
/// FLASH_INVALID_FLASH (1) if the flash specified is invalid.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgFlashErase {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Target flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "target")))]
    pub target: u8,
    /// Flash sector number to erase (0-11 for the STM, 0-15 for the M25)
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sector_num")))]
    pub sector_num: u32,
}

impl ConcreteMessage for MsgFlashErase {
    const MESSAGE_TYPE: u16 = 226;
    const MESSAGE_NAME: &'static str = "MSG_FLASH_ERASE";
}

impl SbpMessage for MsgFlashErase {
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

impl TryFrom<Sbp> for MsgFlashErase {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgFlashErase(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgFlashErase {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN + <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.target) + WireFormat::len(&self.sector_num)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.target, buf);
        WireFormat::write(&self.sector_num, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgFlashErase {
            sender_id: None,
            target: WireFormat::parse_unchecked(buf),
            sector_num: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Program flash addresses
///
/// The flash program message programs a set of addresses of either the STM or
/// M25 flash. The device replies with either a MSG_FLASH_DONE message
/// containing the return code FLASH_OK (0) on success, or FLASH_INVALID_LEN
/// (2) if the maximum write size is exceeded. Note that the sector-containing
/// addresses must be erased before addresses can be programmed.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgFlashProgram {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Target flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "target")))]
    pub target: u8,
    /// Starting address offset to program
    #[cfg_attr(feature = "serde", serde(rename(serialize = "addr_start")))]
    pub addr_start: [u8; 3],
    /// Length of set of addresses to program, counting up from starting address
    #[cfg_attr(feature = "serde", serde(rename(serialize = "addr_len")))]
    pub addr_len: u8,
    /// Data to program addresses with, with length N=addr_len
    #[cfg_attr(feature = "serde", serde(rename(serialize = "data")))]
    pub data: Vec<u8>,
}

impl ConcreteMessage for MsgFlashProgram {
    const MESSAGE_TYPE: u16 = 230;
    const MESSAGE_NAME: &'static str = "MSG_FLASH_PROGRAM";
}

impl SbpMessage for MsgFlashProgram {
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

impl TryFrom<Sbp> for MsgFlashProgram {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgFlashProgram(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgFlashProgram {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <[u8; 3] as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN
        + <Vec<u8> as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.target)
            + WireFormat::len(&self.addr_start)
            + WireFormat::len(&self.addr_len)
            + WireFormat::len(&self.data)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.target, buf);
        WireFormat::write(&self.addr_start, buf);
        WireFormat::write(&self.addr_len, buf);
        WireFormat::write(&self.data, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgFlashProgram {
            sender_id: None,
            target: WireFormat::parse_unchecked(buf),
            addr_start: WireFormat::parse_unchecked(buf),
            addr_len: WireFormat::parse_unchecked(buf),
            data: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Read STM or M25 flash address request (host => device)
///
/// The flash read message reads a set of addresses of either the STM or M25
/// onboard flash. The device replies with a MSG_FLASH_READ_RESP message
/// containing either the read data on success or a MSG_FLASH_DONE message
/// containing the return code FLASH_INVALID_LEN (2) if the maximum read size
/// is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of the
/// allowed range.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgFlashReadReq {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Target flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "target")))]
    pub target: u8,
    /// Starting address offset to read from
    #[cfg_attr(feature = "serde", serde(rename(serialize = "addr_start")))]
    pub addr_start: [u8; 3],
    /// Length of set of addresses to read, counting up from starting address
    #[cfg_attr(feature = "serde", serde(rename(serialize = "addr_len")))]
    pub addr_len: u8,
}

impl ConcreteMessage for MsgFlashReadReq {
    const MESSAGE_TYPE: u16 = 231;
    const MESSAGE_NAME: &'static str = "MSG_FLASH_READ_REQ";
}

impl SbpMessage for MsgFlashReadReq {
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

impl TryFrom<Sbp> for MsgFlashReadReq {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgFlashReadReq(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgFlashReadReq {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <[u8; 3] as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.target)
            + WireFormat::len(&self.addr_start)
            + WireFormat::len(&self.addr_len)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.target, buf);
        WireFormat::write(&self.addr_start, buf);
        WireFormat::write(&self.addr_len, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgFlashReadReq {
            sender_id: None,
            target: WireFormat::parse_unchecked(buf),
            addr_start: WireFormat::parse_unchecked(buf),
            addr_len: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Read STM or M25 flash address response (host <= device)
///
/// The flash read message reads a set of addresses of either the STM or M25
/// onboard flash. The device replies with a MSG_FLASH_READ_RESP message
/// containing either the read data on success or a MSG_FLASH_DONE message
/// containing the return code FLASH_INVALID_LEN (2) if the maximum read size
/// is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of the
/// allowed range.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgFlashReadResp {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Target flags
    #[cfg_attr(feature = "serde", serde(rename(serialize = "target")))]
    pub target: u8,
    /// Starting address offset to read from
    #[cfg_attr(feature = "serde", serde(rename(serialize = "addr_start")))]
    pub addr_start: [u8; 3],
    /// Length of set of addresses to read, counting up from starting address
    #[cfg_attr(feature = "serde", serde(rename(serialize = "addr_len")))]
    pub addr_len: u8,
}

impl ConcreteMessage for MsgFlashReadResp {
    const MESSAGE_TYPE: u16 = 225;
    const MESSAGE_NAME: &'static str = "MSG_FLASH_READ_RESP";
}

impl SbpMessage for MsgFlashReadResp {
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

impl TryFrom<Sbp> for MsgFlashReadResp {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgFlashReadResp(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgFlashReadResp {
    const MIN_LEN: usize = <u8 as WireFormat>::MIN_LEN
        + <[u8; 3] as WireFormat>::MIN_LEN
        + <u8 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.target)
            + WireFormat::len(&self.addr_start)
            + WireFormat::len(&self.addr_len)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.target, buf);
        WireFormat::write(&self.addr_start, buf);
        WireFormat::write(&self.addr_len, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgFlashReadResp {
            sender_id: None,
            target: WireFormat::parse_unchecked(buf),
            addr_start: WireFormat::parse_unchecked(buf),
            addr_len: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Write M25 flash status register (host => device)
///
/// The flash status message writes to the 8-bit M25 flash status register.
/// The device replies with a MSG_FLASH_DONE message.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgM25FlashWriteStatus {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Byte to write to the M25 flash status register
    #[cfg_attr(feature = "serde", serde(rename(serialize = "status")))]
    pub status: [u8; 1],
}

impl ConcreteMessage for MsgM25FlashWriteStatus {
    const MESSAGE_TYPE: u16 = 243;
    const MESSAGE_NAME: &'static str = "MSG_M25_FLASH_WRITE_STATUS";
}

impl SbpMessage for MsgM25FlashWriteStatus {
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

impl TryFrom<Sbp> for MsgM25FlashWriteStatus {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgM25FlashWriteStatus(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgM25FlashWriteStatus {
    const MIN_LEN: usize = <[u8; 1] as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.status)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.status, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgM25FlashWriteStatus {
            sender_id: None,
            status: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Lock sector of STM flash memory (host => device)
///
/// The flash lock message locks a sector of the STM flash memory. The device
/// replies with a MSG_FLASH_DONE message.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgStmFlashLockSector {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Flash sector number to lock
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sector")))]
    pub sector: u32,
}

impl ConcreteMessage for MsgStmFlashLockSector {
    const MESSAGE_TYPE: u16 = 227;
    const MESSAGE_NAME: &'static str = "MSG_STM_FLASH_LOCK_SECTOR";
}

impl SbpMessage for MsgStmFlashLockSector {
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

impl TryFrom<Sbp> for MsgStmFlashLockSector {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgStmFlashLockSector(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgStmFlashLockSector {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sector)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sector, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgStmFlashLockSector {
            sender_id: None,
            sector: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Unlock sector of STM flash memory (host => device)
///
/// The flash unlock message unlocks a sector of the STM flash memory. The
/// device replies with a MSG_FLASH_DONE message.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgStmFlashUnlockSector {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Flash sector number to unlock
    #[cfg_attr(feature = "serde", serde(rename(serialize = "sector")))]
    pub sector: u32,
}

impl ConcreteMessage for MsgStmFlashUnlockSector {
    const MESSAGE_TYPE: u16 = 228;
    const MESSAGE_NAME: &'static str = "MSG_STM_FLASH_UNLOCK_SECTOR";
}

impl SbpMessage for MsgStmFlashUnlockSector {
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

impl TryFrom<Sbp> for MsgStmFlashUnlockSector {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgStmFlashUnlockSector(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgStmFlashUnlockSector {
    const MIN_LEN: usize = <u32 as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.sector)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.sector, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgStmFlashUnlockSector {
            sender_id: None,
            sector: WireFormat::parse_unchecked(buf),
        }
    }
}

/// Read device's hard-coded unique ID request (host => device)

///
/// This message reads the device's hard-coded unique ID. The host requests
/// the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
/// MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgStmUniqueIdReq {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
}

impl ConcreteMessage for MsgStmUniqueIdReq {
    const MESSAGE_TYPE: u16 = 232;
    const MESSAGE_NAME: &'static str = "MSG_STM_UNIQUE_ID_REQ";
}

impl SbpMessage for MsgStmUniqueIdReq {
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

impl TryFrom<Sbp> for MsgStmUniqueIdReq {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgStmUniqueIdReq(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgStmUniqueIdReq {
    const MIN_LEN: usize = 0;
    fn len(&self) -> usize {
        0
    }
    fn write<B: BufMut>(&self, _buf: &mut B) {}
    fn parse_unchecked<B: Buf>(_buf: &mut B) -> Self {
        MsgStmUniqueIdReq { sender_id: None }
    }
}

/// Read device's hard-coded unique ID response (host <= device)

///
/// This message reads the device's hard-coded unique ID. The host requests
/// the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
/// MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
///
#[cfg_attr(feature = "serde", derive(serde::Serialize))]
#[derive(Debug, Clone)]
pub struct MsgStmUniqueIdResp {
    /// The message sender_id
    #[cfg_attr(feature = "serde", serde(skip_serializing))]
    pub sender_id: Option<u16>,
    /// Device unique ID
    #[cfg_attr(feature = "serde", serde(rename(serialize = "stm_id")))]
    pub stm_id: [u8; 12],
}

impl ConcreteMessage for MsgStmUniqueIdResp {
    const MESSAGE_TYPE: u16 = 229;
    const MESSAGE_NAME: &'static str = "MSG_STM_UNIQUE_ID_RESP";
}

impl SbpMessage for MsgStmUniqueIdResp {
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

impl TryFrom<Sbp> for MsgStmUniqueIdResp {
    type Error = TryFromSbpError;
    fn try_from(msg: Sbp) -> Result<Self, Self::Error> {
        match msg {
            Sbp::MsgStmUniqueIdResp(m) => Ok(m),
            _ => Err(TryFromSbpError),
        }
    }
}

impl WireFormat for MsgStmUniqueIdResp {
    const MIN_LEN: usize = <[u8; 12] as WireFormat>::MIN_LEN;
    fn len(&self) -> usize {
        WireFormat::len(&self.stm_id)
    }
    fn write<B: BufMut>(&self, buf: &mut B) {
        WireFormat::write(&self.stm_id, buf);
    }
    fn parse_unchecked<B: Buf>(buf: &mut B) -> Self {
        MsgStmUniqueIdResp {
            sender_id: None,
            stm_id: WireFormat::parse_unchecked(buf),
        }
    }
}
