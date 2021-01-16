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
// Automatically generated from yaml/swiftnav/sbp/flash.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
//! Messages for reading/writing the device's onboard flash memory. Many
//! of these messages target specific flash memory peripherals used in
//! Swift Navigation devices: the STM32 flash and the M25Pxx FPGA
//! configuration flash from Piksi 2.3.1.  This module does not apply
//! to Piksi Multi.
//!

#[cfg(feature = "sbp_serde")]
use serde::{Deserialize, Serialize};

#[allow(unused_imports)]
use crate::{parser::SbpParse, BoundedSbpString, UnboundedSbpString};

/// Flash response message (host <= device).
///
/// This message defines success or failure codes for a variety of
/// flash memory requests from the host to the device. Flash read
/// and write messages, such as MSG_FLASH_READ_REQ, or
/// MSG_FLASH_PROGRAM, may return this message on failure.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgFlashDone {
    pub sender_id: Option<u16>,
    /// Response flags
    pub response: u8,
}

impl SbpParse<MsgFlashDone> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgFlashDone> {
        Ok( MsgFlashDone{
            sender_id: None,
            response: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgFlashDone {
    fn get_message_type(&self) -> u16 {
        224
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

impl crate::serialize::SbpSerialize for MsgFlashDone {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.response.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.response.sbp_size();
        size
    }
}

/// Erase sector of device flash memory (host => device).
///
/// The flash erase message from the host erases a sector of either
/// the STM or M25 onboard flash memory. The device will reply with a
/// MSG_FLASH_DONE message containing the return code - FLASH_OK (0)
/// on success or FLASH_INVALID_FLASH (1) if the flash specified is
/// invalid.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgFlashErase {
    pub sender_id: Option<u16>,
    /// Target flags
    pub target: u8,
    /// Flash sector number to erase (0-11 for the STM, 0-15 for the M25)
    pub sector_num: u32,
}

impl SbpParse<MsgFlashErase> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgFlashErase> {
        Ok( MsgFlashErase{
            sender_id: None,
            target: self.parse()?,
            sector_num: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgFlashErase {
    fn get_message_type(&self) -> u16 {
        226
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

impl crate::serialize::SbpSerialize for MsgFlashErase {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.target.append_to_sbp_buffer(buf);
        self.sector_num.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.target.sbp_size();
        size += self.sector_num.sbp_size();
        size
    }
}

/// Program flash addresses
///
/// The flash program message programs a set of addresses of either
/// the STM or M25 flash. The device replies with either a
/// MSG_FLASH_DONE message containing the return code FLASH_OK (0)
/// on success, or FLASH_INVALID_LEN (2) if the maximum write size
/// is exceeded. Note that the sector-containing addresses must be
/// erased before addresses can be programmed.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgFlashProgram {
    pub sender_id: Option<u16>,
    /// Target flags
    pub target: u8,
    /// Starting address offset to program
    pub addr_start: [u8; 3],
    /// Length of set of addresses to program, counting up from starting address
    pub addr_len: u8,
    /// Data to program addresses with, with length N=addr_len
    pub data: Vec<u8>,
}

impl SbpParse<MsgFlashProgram> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgFlashProgram> {
        Ok( MsgFlashProgram{
            sender_id: None,
            target: self.parse()?,
            addr_start: self.parse()?,
            addr_len: self.parse()?,
            data: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgFlashProgram {
    fn get_message_type(&self) -> u16 {
        230
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

impl crate::serialize::SbpSerialize for MsgFlashProgram {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.target.append_to_sbp_buffer(buf);
        self.addr_start.append_to_sbp_buffer(buf);
        self.addr_len.append_to_sbp_buffer(buf);
        self.data.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.target.sbp_size();
        size += self.addr_start.sbp_size();
        size += self.addr_len.sbp_size();
        size += self.data.sbp_size();
        size
    }
}

/// Read STM or M25 flash address request (host => device).
///
/// The flash read message reads a set of addresses of either the
/// STM or M25 onboard flash. The device replies with a
/// MSG_FLASH_READ_RESP message containing either the read data on
/// success or a MSG_FLASH_DONE message containing the return code
/// FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
/// FLASH_INVALID_ADDR (3) if the address is outside of the allowed
/// range.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgFlashReadReq {
    pub sender_id: Option<u16>,
    /// Target flags
    pub target: u8,
    /// Starting address offset to read from
    pub addr_start: [u8; 3],
    /// Length of set of addresses to read, counting up from starting address
    pub addr_len: u8,
}

impl SbpParse<MsgFlashReadReq> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgFlashReadReq> {
        Ok( MsgFlashReadReq{
            sender_id: None,
            target: self.parse()?,
            addr_start: self.parse()?,
            addr_len: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgFlashReadReq {
    fn get_message_type(&self) -> u16 {
        231
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

impl crate::serialize::SbpSerialize for MsgFlashReadReq {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.target.append_to_sbp_buffer(buf);
        self.addr_start.append_to_sbp_buffer(buf);
        self.addr_len.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.target.sbp_size();
        size += self.addr_start.sbp_size();
        size += self.addr_len.sbp_size();
        size
    }
}

/// Read STM or M25 flash address response (host <= device).
///
/// The flash read message reads a set of addresses of either the
/// STM or M25 onboard flash. The device replies with a
/// MSG_FLASH_READ_RESP message containing either the read data on
/// success or a MSG_FLASH_DONE message containing the return code
/// FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
/// FLASH_INVALID_ADDR (3) if the address is outside of the allowed
/// range.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgFlashReadResp {
    pub sender_id: Option<u16>,
    /// Target flags
    pub target: u8,
    /// Starting address offset to read from
    pub addr_start: [u8; 3],
    /// Length of set of addresses to read, counting up from starting address
    pub addr_len: u8,
}

impl SbpParse<MsgFlashReadResp> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgFlashReadResp> {
        Ok( MsgFlashReadResp{
            sender_id: None,
            target: self.parse()?,
            addr_start: self.parse()?,
            addr_len: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgFlashReadResp {
    fn get_message_type(&self) -> u16 {
        225
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

impl crate::serialize::SbpSerialize for MsgFlashReadResp {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.target.append_to_sbp_buffer(buf);
        self.addr_start.append_to_sbp_buffer(buf);
        self.addr_len.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.target.sbp_size();
        size += self.addr_start.sbp_size();
        size += self.addr_len.sbp_size();
        size
    }
}

/// Write M25 flash status register (host => device)
///
/// The flash status message writes to the 8-bit M25 flash status
/// register. The device replies with a MSG_FLASH_DONE message.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgM25FlashWriteStatus {
    pub sender_id: Option<u16>,
    /// Byte to write to the M25 flash status register
    pub status: [u8; 1],
}

impl SbpParse<MsgM25FlashWriteStatus> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgM25FlashWriteStatus> {
        Ok( MsgM25FlashWriteStatus{
            sender_id: None,
            status: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgM25FlashWriteStatus {
    fn get_message_type(&self) -> u16 {
        243
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

impl crate::serialize::SbpSerialize for MsgM25FlashWriteStatus {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.status.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.status.sbp_size();
        size
    }
}

/// Lock sector of STM flash memory (host => device)
///
/// The flash lock message locks a sector of the STM flash
/// memory. The device replies with a MSG_FLASH_DONE message.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgStmFlashLockSector {
    pub sender_id: Option<u16>,
    /// Flash sector number to lock
    pub sector: u32,
}

impl SbpParse<MsgStmFlashLockSector> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgStmFlashLockSector> {
        Ok( MsgStmFlashLockSector{
            sender_id: None,
            sector: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgStmFlashLockSector {
    fn get_message_type(&self) -> u16 {
        227
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

impl crate::serialize::SbpSerialize for MsgStmFlashLockSector {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sector.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sector.sbp_size();
        size
    }
}

/// Unlock sector of STM flash memory (host => device)
///
/// The flash unlock message unlocks a sector of the STM flash
/// memory. The device replies with a MSG_FLASH_DONE message.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgStmFlashUnlockSector {
    pub sender_id: Option<u16>,
    /// Flash sector number to unlock
    pub sector: u32,
}

impl SbpParse<MsgStmFlashUnlockSector> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgStmFlashUnlockSector> {
        Ok( MsgStmFlashUnlockSector{
            sender_id: None,
            sector: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgStmFlashUnlockSector {
    fn get_message_type(&self) -> u16 {
        228
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

impl crate::serialize::SbpSerialize for MsgStmFlashUnlockSector {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.sector.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.sector.sbp_size();
        size
    }
}

/// Read device's hardcoded unique ID request (host => device)

///
/// This message reads the device's hardcoded unique ID. The host
/// requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
/// responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
/// ID in the payload.
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgStmUniqueIdReq {
    pub sender_id: Option<u16>,
}

impl SbpParse<MsgStmUniqueIdReq> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgStmUniqueIdReq> {
        Ok( MsgStmUniqueIdReq{
            sender_id: None,
        } )
    }
}
impl super::SBPMessage for MsgStmUniqueIdReq {
    fn get_message_type(&self) -> u16 {
        232
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

impl crate::serialize::SbpSerialize for MsgStmUniqueIdReq {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {}

    fn sbp_size(&self) -> usize {
        0
    }
}

/// Read device's hardcoded unique ID response (host <= device)

///
/// This message reads the device's hardcoded unique ID. The host
/// requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
/// responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
/// ID in the payload..
///
#[cfg_attr(feature = "sbp_serde", derive(Serialize, Deserialize))]
#[derive(Debug, Clone)]
#[allow(non_snake_case)]
pub struct MsgStmUniqueIdResp {
    pub sender_id: Option<u16>,
    /// Device unique ID
    pub stm_id: [u8; 12],
}

impl SbpParse<MsgStmUniqueIdResp> for &[u8] {
    #[rustfmt::skip]
    fn parse(&mut self) -> crate::Result<MsgStmUniqueIdResp> {
        Ok( MsgStmUniqueIdResp{
            sender_id: None,
            stm_id: self.parse()?,
        } )
    }
}
impl super::SBPMessage for MsgStmUniqueIdResp {
    fn get_message_type(&self) -> u16 {
        229
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

impl crate::serialize::SbpSerialize for MsgStmUniqueIdResp {
    #[allow(unused_variables)]
    fn append_to_sbp_buffer(&self, buf: &mut Vec<u8>) {
        self.stm_id.append_to_sbp_buffer(buf);
    }

    fn sbp_size(&self) -> usize {
        let mut size = 0;
        size += self.stm_id.sbp_size();
        size
    }
}
