-- |
-- Module:      SwiftNav.SBP.Flash
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Messages for reading/writing the device's onboard flash memory. Many of
-- these messages target specific flash memory peripherals used in Swift
-- Navigation devices: the STM32 flash and the M25Pxx FPGA configuration flash.
-- These are in the implementation-defined range (0x0000-0x00FF), and are
-- intended for internal-use only.

module SwiftNav.SBP.Flash where

import Control.Monad
import Control.Monad.Loops
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy hiding ( ByteString )
import Data.Int
import Data.Word

msgFlashProgram :: Word16
msgFlashProgram = 0x00E6

-- | SBP class for message MSG_FLASH_PROGRAM (0x00E6).
--
-- The flash program message programs a set of addresses of either the STM or
-- M25 flash. The device replies with either a MSG_FLASH_DONE message
-- containing the return code FLASH_OK (0) on success, or FLASH_INVALID_LEN (2)
-- if the maximum write size is exceeded. Note that the sector-containing
-- addresses must be erased before addresses can be programmed.
data MsgFlashProgram = MsgFlashProgram
  { msgFlashProgramTarget     :: Word8
    -- ^ Target flags
  , msgFlashProgramAddrStart  :: [Word8]
    -- ^ Starting address offset to program
  , msgFlashProgramAddrLen    :: Word8
    -- ^ Length of set of addresses to program, counting up from starting address
  , msgFlashProgramData       :: [Word8]
    -- ^ Data to program addresses with, with length N=addr_len
  } deriving ( Show, Read, Eq )

instance Binary MsgFlashProgram where
  get = do
    msgFlashProgramTarget <- getWord8
    msgFlashProgramAddrStart <- replicateM 3 getWord8
    msgFlashProgramAddrLen <- getWord8
    msgFlashProgramData <- whileM (liftM not isEmpty) getWord8
    return MsgFlashProgram {..}

  put MsgFlashProgram {..} = do
    putWord8 msgFlashProgramTarget
    mapM_ putWord8 msgFlashProgramAddrStart
    putWord8 msgFlashProgramAddrLen
    mapM_ putWord8 msgFlashProgramData

msgFlashDone :: Word16
msgFlashDone = 0x00E0

-- | SBP class for message MSG_FLASH_DONE (0x00E0).
--
-- This message defines success or failure codes for a variety of flash memory
-- requests from the host to the device. Flash read and write messages, such as
-- MSG_FLASH_READ_REQ, or MSG_FLASH_PROGRAM, may return this message on
-- failure.
data MsgFlashDone = MsgFlashDone
  { msgFlashDoneResponse :: Word8
    -- ^ Response flags
  } deriving ( Show, Read, Eq )

instance Binary MsgFlashDone where
  get = do
    msgFlashDoneResponse <- getWord8
    return MsgFlashDone {..}

  put MsgFlashDone {..} = do
    putWord8 msgFlashDoneResponse

msgFlashReadReq :: Word16
msgFlashReadReq = 0x00E7

-- | SBP class for message MSG_FLASH_READ_REQ (0x00E7).
--
-- The flash read message reads a set of addresses of either the STM or M25
-- onboard flash. The device replies with a MSG_FLASH_READ_RESP message
-- containing either the read data on success or a MSG_FLASH_DONE message
-- containing the return code FLASH_INVALID_LEN (2) if the maximum read size is
-- exceeded or FLASH_INVALID_ADDR (3) if the address is outside of the allowed
-- range.
data MsgFlashReadReq = MsgFlashReadReq
  { msgFlashReadReqTarget     :: Word8
    -- ^ Target flags
  , msgFlashReadReqAddrStart  :: [Word8]
    -- ^ Starting address offset to read from
  , msgFlashReadReqAddrLen    :: Word8
    -- ^ Length of set of addresses to read, counting up from starting address
  } deriving ( Show, Read, Eq )

instance Binary MsgFlashReadReq where
  get = do
    msgFlashReadReqTarget <- getWord8
    msgFlashReadReqAddrStart <- replicateM 3 getWord8
    msgFlashReadReqAddrLen <- getWord8
    return MsgFlashReadReq {..}

  put MsgFlashReadReq {..} = do
    putWord8 msgFlashReadReqTarget
    mapM_ putWord8 msgFlashReadReqAddrStart
    putWord8 msgFlashReadReqAddrLen

msgFlashReadResp :: Word16
msgFlashReadResp = 0x00E1

-- | SBP class for message MSG_FLASH_READ_RESP (0x00E1).
--
-- The flash read message reads a set of addresses of either the STM or M25
-- onboard flash. The device replies with a MSG_FLASH_READ_RESP message
-- containing either the read data on success or a MSG_FLASH_DONE message
-- containing the return code FLASH_INVALID_LEN (2) if the maximum read size is
-- exceeded or FLASH_INVALID_ADDR (3) if the address is outside of the allowed
-- range.
data MsgFlashReadResp = MsgFlashReadResp
  { msgFlashReadRespTarget     :: Word8
    -- ^ Target flags
  , msgFlashReadRespAddrStart  :: [Word8]
    -- ^ Starting address offset to read from
  , msgFlashReadRespAddrLen    :: Word8
    -- ^ Length of set of addresses to read, counting up from starting address
  } deriving ( Show, Read, Eq )

instance Binary MsgFlashReadResp where
  get = do
    msgFlashReadRespTarget <- getWord8
    msgFlashReadRespAddrStart <- replicateM 3 getWord8
    msgFlashReadRespAddrLen <- getWord8
    return MsgFlashReadResp {..}

  put MsgFlashReadResp {..} = do
    putWord8 msgFlashReadRespTarget
    mapM_ putWord8 msgFlashReadRespAddrStart
    putWord8 msgFlashReadRespAddrLen

msgFlashErase :: Word16
msgFlashErase = 0x00E2

-- | SBP class for message MSG_FLASH_ERASE (0x00E2).
--
-- The flash erase message from the host erases a sector of either the STM or
-- M25 onboard flash memory. The device will reply with a MSG_FLASH_DONE
-- message containing the return code - FLASH_OK (0) on success or
-- FLASH_INVALID_FLASH (1) if the flash specified is invalid.
data MsgFlashErase = MsgFlashErase
  { msgFlashEraseTarget     :: Word8
    -- ^ Target flags
  , msgFlashEraseSectorNum  :: Word32
    -- ^ Flash sector number to erase (0-11 for the STM, 0-15 for the M25)
  } deriving ( Show, Read, Eq )

instance Binary MsgFlashErase where
  get = do
    msgFlashEraseTarget <- getWord8
    msgFlashEraseSectorNum <- getWord32le
    return MsgFlashErase {..}

  put MsgFlashErase {..} = do
    putWord8 msgFlashEraseTarget
    putWord32le msgFlashEraseSectorNum

msgStmFlashLockSector :: Word16
msgStmFlashLockSector = 0x00E3

-- | SBP class for message MSG_STM_FLASH_LOCK_SECTOR (0x00E3).
--
-- The flash lock message locks a sector of the STM flash memory. The device
-- replies with a MSG_FLASH_DONE message.
data MsgStmFlashLockSector = MsgStmFlashLockSector
  { msgStmFlashLockSectorSector :: Word32
    -- ^ Flash sector number to lock
  } deriving ( Show, Read, Eq )

instance Binary MsgStmFlashLockSector where
  get = do
    msgStmFlashLockSectorSector <- getWord32le
    return MsgStmFlashLockSector {..}

  put MsgStmFlashLockSector {..} = do
    putWord32le msgStmFlashLockSectorSector

msgStmFlashUnlockSector :: Word16
msgStmFlashUnlockSector = 0x00E4

-- | SBP class for message MSG_STM_FLASH_UNLOCK_SECTOR (0x00E4).
--
-- The flash unlock message unlocks a sector of the STM flash memory. The
-- device replies with a MSG_FLASH_DONE message.
data MsgStmFlashUnlockSector = MsgStmFlashUnlockSector
  { msgStmFlashUnlockSectorSector :: Word32
    -- ^ Flash sector number to unlock
  } deriving ( Show, Read, Eq )

instance Binary MsgStmFlashUnlockSector where
  get = do
    msgStmFlashUnlockSectorSector <- getWord32le
    return MsgStmFlashUnlockSector {..}

  put MsgStmFlashUnlockSector {..} = do
    putWord32le msgStmFlashUnlockSectorSector

msgStmUniqueIdReq :: Word16
msgStmUniqueIdReq = 0x00E8

-- | SBP class for message MSG_STM_UNIQUE_ID_REQ (0x00E8).
--
-- This message reads the device's hardcoded unique ID. The host requests the
-- ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
-- MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
data MsgStmUniqueIdReq = MsgStmUniqueIdReq
  deriving ( Show, Read, Eq )

instance Binary MsgStmUniqueIdReq where
  get =
    return MsgStmUniqueIdReq

  put MsgStmUniqueIdReq =
    return ()

msgStmUniqueIdResp :: Word16
msgStmUniqueIdResp = 0x00E5

-- | SBP class for message MSG_STM_UNIQUE_ID_RESP (0x00E5).
--
-- This message reads the device's hardcoded unique ID. The host requests the
-- ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
-- MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload..
data MsgStmUniqueIdResp = MsgStmUniqueIdResp
  { msgStmUniqueIdRespStmId  :: [Word8]
    -- ^ Device unique ID
  } deriving ( Show, Read, Eq )

instance Binary MsgStmUniqueIdResp where
  get = do
    msgStmUniqueIdRespStmId <- replicateM 12 getWord8
    return MsgStmUniqueIdResp {..}

  put MsgStmUniqueIdResp {..} = do
    mapM_ putWord8 msgStmUniqueIdRespStmId

msgM25FlashWriteStatus :: Word16
msgM25FlashWriteStatus = 0x00F3

-- | SBP class for message MSG_M25_FLASH_WRITE_STATUS (0x00F3).
--
-- The flash status message writes to the 8-bit M25 flash status register. The
-- device replies with a MSG_FLASH_DONE message.
data MsgM25FlashWriteStatus = MsgM25FlashWriteStatus
  { msgM25FlashWriteStatusStatus :: [Word8]
    -- ^ Byte to write to the M25 flash status register
  } deriving ( Show, Read, Eq )

instance Binary MsgM25FlashWriteStatus where
  get = do
    msgM25FlashWriteStatusStatus <- replicateM 1 getWord8
    return MsgM25FlashWriteStatus {..}

  put MsgM25FlashWriteStatus {..} = do
    mapM_ putWord8 msgM25FlashWriteStatusStatus
