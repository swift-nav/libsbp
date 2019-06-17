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
// Automatically generated from yaml/swiftnav/sbp/flash.yaml
// with generate.py. Please do not hand edit!
//****************************************************************************/
// Messages for reading/writing the device's onboard flash memory. Many
// of these messages target specific flash memory peripherals used in
// Swift Navigation devices: the STM32 flash and the M25Pxx FPGA
// configuration flash from Piksi 2.3.1.  This module does not apply
// to Piksi Multi.
extern crate byteorder;
#[allow(unused_imports)]
use self::byteorder::{LittleEndian, ReadBytesExt};

// Program flash addresses
//
// The flash program message programs a set of addresses of either
// the STM or M25 flash. The device replies with either a
// MSG_FLASH_DONE message containing the return code FLASH_OK (0)
// on success, or FLASH_INVALID_LEN (2) if the maximum write size
// is exceeded. Note that the sector-containing addresses must be
// erased before addresses can be programmed.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgFlashProgram {
    pub target: u8,
    // ^ Target flags
    pub addr_start: Vec<u8>,
    // ^ Starting address offset to program
    pub addr_len: u8,
    // ^ Length of set of addresses to program, counting up from starting address
    pub data: Vec<u8>,
    // ^ Data to program addresses with, with length N=addr_len
}

impl MsgFlashProgram {
    pub const TYPE: u16 = 230;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFlashProgram, ::parser::MessageError> {
        Ok(MsgFlashProgram {
            target: _buf.read_u8()?,
            addr_start: ::parser::read_u8_array_limit(_buf, 3)?,
            addr_len: _buf.read_u8()?,
            data: ::parser::read_u8_array(_buf)?,
        })
    }
}

// Flash response message (host <= device).
//
// This message defines success or failure codes for a variety of
// flash memory requests from the host to the device. Flash read
// and write messages, such as MSG_FLASH_READ_REQ, or
// MSG_FLASH_PROGRAM, may return this message on failure.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgFlashDone {
    pub response: u8,
    // ^ Response flags
}

impl MsgFlashDone {
    pub const TYPE: u16 = 224;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFlashDone, ::parser::MessageError> {
        Ok(MsgFlashDone {
            response: _buf.read_u8()?,
        })
    }
}

// Read STM or M25 flash address request (host => device).
//
// The flash read message reads a set of addresses of either the
// STM or M25 onboard flash. The device replies with a
// MSG_FLASH_READ_RESP message containing either the read data on
// success or a MSG_FLASH_DONE message containing the return code
// FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
// FLASH_INVALID_ADDR (3) if the address is outside of the allowed
// range.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgFlashReadReq {
    pub target: u8,
    // ^ Target flags
    pub addr_start: Vec<u8>,
    // ^ Starting address offset to read from
    pub addr_len: u8,
    // ^ Length of set of addresses to read, counting up from starting address
}

impl MsgFlashReadReq {
    pub const TYPE: u16 = 231;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFlashReadReq, ::parser::MessageError> {
        Ok(MsgFlashReadReq {
            target: _buf.read_u8()?,
            addr_start: ::parser::read_u8_array_limit(_buf, 3)?,
            addr_len: _buf.read_u8()?,
        })
    }
}

// Read STM or M25 flash address response (host <= device).
//
// The flash read message reads a set of addresses of either the
// STM or M25 onboard flash. The device replies with a
// MSG_FLASH_READ_RESP message containing either the read data on
// success or a MSG_FLASH_DONE message containing the return code
// FLASH_INVALID_LEN (2) if the maximum read size is exceeded or
// FLASH_INVALID_ADDR (3) if the address is outside of the allowed
// range.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgFlashReadResp {
    pub target: u8,
    // ^ Target flags
    pub addr_start: Vec<u8>,
    // ^ Starting address offset to read from
    pub addr_len: u8,
    // ^ Length of set of addresses to read, counting up from starting address
}

impl MsgFlashReadResp {
    pub const TYPE: u16 = 225;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFlashReadResp, ::parser::MessageError> {
        Ok(MsgFlashReadResp {
            target: _buf.read_u8()?,
            addr_start: ::parser::read_u8_array_limit(_buf, 3)?,
            addr_len: _buf.read_u8()?,
        })
    }
}

// Erase sector of device flash memory (host => device).
//
// The flash erase message from the host erases a sector of either
// the STM or M25 onboard flash memory. The device will reply with a
// MSG_FLASH_DONE message containing the return code - FLASH_OK (0)
// on success or FLASH_INVALID_FLASH (1) if the flash specified is
// invalid.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgFlashErase {
    pub target: u8,
    // ^ Target flags
    pub sector_num: u32,
    // ^ Flash sector number to erase (0-11 for the STM, 0-15 for the M25)
}

impl MsgFlashErase {
    pub const TYPE: u16 = 226;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgFlashErase, ::parser::MessageError> {
        Ok(MsgFlashErase {
            target: _buf.read_u8()?,
            sector_num: _buf.read_u32::<LittleEndian>()?,
        })
    }
}

// Lock sector of STM flash memory (host => device)
//
// The flash lock message locks a sector of the STM flash
// memory. The device replies with a MSG_FLASH_DONE message.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgStmFlashLockSector {
    pub sector: u32,
    // ^ Flash sector number to lock
}

impl MsgStmFlashLockSector {
    pub const TYPE: u16 = 227;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgStmFlashLockSector, ::parser::MessageError> {
        Ok(MsgStmFlashLockSector {
            sector: _buf.read_u32::<LittleEndian>()?,
        })
    }
}

// Unlock sector of STM flash memory (host => device)
//
// The flash unlock message unlocks a sector of the STM flash
// memory. The device replies with a MSG_FLASH_DONE message.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgStmFlashUnlockSector {
    pub sector: u32,
    // ^ Flash sector number to unlock
}

impl MsgStmFlashUnlockSector {
    pub const TYPE: u16 = 228;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgStmFlashUnlockSector, ::parser::MessageError> {
        Ok(MsgStmFlashUnlockSector {
            sector: _buf.read_u32::<LittleEndian>()?,
        })
    }
}

// Read device's hardcoded unique ID request (host => device)

//
// This message reads the device's hardcoded unique ID. The host
// requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
// responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
// ID in the payload.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgStmUniqueIdReq {}

impl MsgStmUniqueIdReq {
    pub const TYPE: u16 = 232;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgStmUniqueIdReq, ::parser::MessageError> {
        Ok(MsgStmUniqueIdReq {})
    }
}

// Read device's hardcoded unique ID response (host <= device)

//
// This message reads the device's hardcoded unique ID. The host
// requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
// responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
// ID in the payload..
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgStmUniqueIdResp {
    pub stm_id: Vec<u8>,
    // ^ Device unique ID
}

impl MsgStmUniqueIdResp {
    pub const TYPE: u16 = 229;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgStmUniqueIdResp, ::parser::MessageError> {
        Ok(MsgStmUniqueIdResp {
            stm_id: ::parser::read_u8_array_limit(_buf, 12)?,
        })
    }
}

// Write M25 flash status register (host => device)
//
// The flash status message writes to the 8-bit M25 flash status
// register. The device replies with a MSG_FLASH_DONE message.
//
#[derive(Debug)]
#[allow(non_snake_case)]
pub struct MsgM25FlashWriteStatus {
    pub status: Vec<u8>,
    // ^ Byte to write to the M25 flash status register
}

impl MsgM25FlashWriteStatus {
    pub const TYPE: u16 = 243;
    pub fn parse(_buf: &mut &[u8]) -> Result<MsgM25FlashWriteStatus, ::parser::MessageError> {
        Ok(MsgM25FlashWriteStatus {
            status: ::parser::read_u8_array_limit(_buf, 1)?,
        })
    }
}
