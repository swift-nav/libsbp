{-# OPTIONS_GHC -fno-warn-unused-imports #-}
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

module SwiftNav.SBP.Flash where

import BasicPrelude
import Control.Lens
import Control.Monad.Loops
import Data.Aeson.TH           (defaultOptions, deriveJSON, fieldLabelModifier)
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy    hiding (ByteString)
import Data.Int
import Data.Word
import SwiftNav.SBP.Encoding
import SwiftNav.SBP.TH
import SwiftNav.SBP.Types

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
  { _msgFlashProgram_target   :: Word8
    -- ^ Target flags
  , _msgFlashProgram_addr_start :: [Word8]
    -- ^ Starting address offset to program
  , _msgFlashProgram_addr_len :: Word8
    -- ^ Length of set of addresses to program, counting up from starting address
  , _msgFlashProgram_data     :: [Word8]
    -- ^ Data to program addresses with, with length N=addr_len
  } deriving ( Show, Read, Eq )

instance Binary MsgFlashProgram where
  get = do
    _msgFlashProgram_target <- getWord8
    _msgFlashProgram_addr_start <- replicateM 3 getWord8
    _msgFlashProgram_addr_len <- getWord8
    _msgFlashProgram_data <- whileM (liftM not isEmpty) getWord8
    return MsgFlashProgram {..}

  put MsgFlashProgram {..} = do
    putWord8 _msgFlashProgram_target
    mapM_ putWord8 _msgFlashProgram_addr_start
    putWord8 _msgFlashProgram_addr_len
    mapM_ putWord8 _msgFlashProgram_data

$(deriveSBP 'msgFlashProgram ''MsgFlashProgram)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgFlashProgram_" . stripPrefix "_msgFlashProgram_"}
             ''MsgFlashProgram)
$(makeLenses ''MsgFlashProgram)

msgFlashDone :: Word16
msgFlashDone = 0x00E0

-- | SBP class for message MSG_FLASH_DONE (0x00E0).
--
-- This message defines success or failure codes for a variety of flash memory
-- requests from the host to the device. Flash read and write messages, such as
-- MSG_FLASH_READ_REQ, or MSG_FLASH_PROGRAM, may return this message on
-- failure.
data MsgFlashDone = MsgFlashDone
  { _msgFlashDone_response :: Word8
    -- ^ Response flags
  } deriving ( Show, Read, Eq )

instance Binary MsgFlashDone where
  get = do
    _msgFlashDone_response <- getWord8
    return MsgFlashDone {..}

  put MsgFlashDone {..} = do
    putWord8 _msgFlashDone_response

$(deriveSBP 'msgFlashDone ''MsgFlashDone)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgFlashDone_" . stripPrefix "_msgFlashDone_"}
             ''MsgFlashDone)
$(makeLenses ''MsgFlashDone)

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
  { _msgFlashReadReq_target   :: Word8
    -- ^ Target flags
  , _msgFlashReadReq_addr_start :: [Word8]
    -- ^ Starting address offset to read from
  , _msgFlashReadReq_addr_len :: Word8
    -- ^ Length of set of addresses to read, counting up from starting address
  } deriving ( Show, Read, Eq )

instance Binary MsgFlashReadReq where
  get = do
    _msgFlashReadReq_target <- getWord8
    _msgFlashReadReq_addr_start <- replicateM 3 getWord8
    _msgFlashReadReq_addr_len <- getWord8
    return MsgFlashReadReq {..}

  put MsgFlashReadReq {..} = do
    putWord8 _msgFlashReadReq_target
    mapM_ putWord8 _msgFlashReadReq_addr_start
    putWord8 _msgFlashReadReq_addr_len

$(deriveSBP 'msgFlashReadReq ''MsgFlashReadReq)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgFlashReadReq_" . stripPrefix "_msgFlashReadReq_"}
             ''MsgFlashReadReq)
$(makeLenses ''MsgFlashReadReq)

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
  { _msgFlashReadResp_target   :: Word8
    -- ^ Target flags
  , _msgFlashReadResp_addr_start :: [Word8]
    -- ^ Starting address offset to read from
  , _msgFlashReadResp_addr_len :: Word8
    -- ^ Length of set of addresses to read, counting up from starting address
  } deriving ( Show, Read, Eq )

instance Binary MsgFlashReadResp where
  get = do
    _msgFlashReadResp_target <- getWord8
    _msgFlashReadResp_addr_start <- replicateM 3 getWord8
    _msgFlashReadResp_addr_len <- getWord8
    return MsgFlashReadResp {..}

  put MsgFlashReadResp {..} = do
    putWord8 _msgFlashReadResp_target
    mapM_ putWord8 _msgFlashReadResp_addr_start
    putWord8 _msgFlashReadResp_addr_len

$(deriveSBP 'msgFlashReadResp ''MsgFlashReadResp)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgFlashReadResp_" . stripPrefix "_msgFlashReadResp_"}
             ''MsgFlashReadResp)
$(makeLenses ''MsgFlashReadResp)

msgFlashErase :: Word16
msgFlashErase = 0x00E2

-- | SBP class for message MSG_FLASH_ERASE (0x00E2).
--
-- The flash erase message from the host erases a sector of either the STM or
-- M25 onboard flash memory. The device will reply with a MSG_FLASH_DONE
-- message containing the return code - FLASH_OK (0) on success or
-- FLASH_INVALID_FLASH (1) if the flash specified is invalid.
data MsgFlashErase = MsgFlashErase
  { _msgFlashErase_target   :: Word8
    -- ^ Target flags
  , _msgFlashErase_sector_num :: Word32
    -- ^ Flash sector number to erase (0-11 for the STM, 0-15 for the M25)
  } deriving ( Show, Read, Eq )

instance Binary MsgFlashErase where
  get = do
    _msgFlashErase_target <- getWord8
    _msgFlashErase_sector_num <- getWord32le
    return MsgFlashErase {..}

  put MsgFlashErase {..} = do
    putWord8 _msgFlashErase_target
    putWord32le _msgFlashErase_sector_num

$(deriveSBP 'msgFlashErase ''MsgFlashErase)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgFlashErase_" . stripPrefix "_msgFlashErase_"}
             ''MsgFlashErase)
$(makeLenses ''MsgFlashErase)

msgStmFlashLockSector :: Word16
msgStmFlashLockSector = 0x00E3

-- | SBP class for message MSG_STM_FLASH_LOCK_SECTOR (0x00E3).
--
-- The flash lock message locks a sector of the STM flash memory. The device
-- replies with a MSG_FLASH_DONE message.
data MsgStmFlashLockSector = MsgStmFlashLockSector
  { _msgStmFlashLockSector_sector :: Word32
    -- ^ Flash sector number to lock
  } deriving ( Show, Read, Eq )

instance Binary MsgStmFlashLockSector where
  get = do
    _msgStmFlashLockSector_sector <- getWord32le
    return MsgStmFlashLockSector {..}

  put MsgStmFlashLockSector {..} = do
    putWord32le _msgStmFlashLockSector_sector

$(deriveSBP 'msgStmFlashLockSector ''MsgStmFlashLockSector)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgStmFlashLockSector_" . stripPrefix "_msgStmFlashLockSector_"}
             ''MsgStmFlashLockSector)
$(makeLenses ''MsgStmFlashLockSector)

msgStmFlashUnlockSector :: Word16
msgStmFlashUnlockSector = 0x00E4

-- | SBP class for message MSG_STM_FLASH_UNLOCK_SECTOR (0x00E4).
--
-- The flash unlock message unlocks a sector of the STM flash memory. The
-- device replies with a MSG_FLASH_DONE message.
data MsgStmFlashUnlockSector = MsgStmFlashUnlockSector
  { _msgStmFlashUnlockSector_sector :: Word32
    -- ^ Flash sector number to unlock
  } deriving ( Show, Read, Eq )

instance Binary MsgStmFlashUnlockSector where
  get = do
    _msgStmFlashUnlockSector_sector <- getWord32le
    return MsgStmFlashUnlockSector {..}

  put MsgStmFlashUnlockSector {..} = do
    putWord32le _msgStmFlashUnlockSector_sector

$(deriveSBP 'msgStmFlashUnlockSector ''MsgStmFlashUnlockSector)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgStmFlashUnlockSector_" . stripPrefix "_msgStmFlashUnlockSector_"}
             ''MsgStmFlashUnlockSector)
$(makeLenses ''MsgStmFlashUnlockSector)

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

$(deriveSBP 'msgStmUniqueIdReq ''MsgStmUniqueIdReq)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgStmUniqueIdReq_" . stripPrefix "_msgStmUniqueIdReq_"}
             ''MsgStmUniqueIdReq)
$(makeLenses ''MsgStmUniqueIdReq)

msgStmUniqueIdResp :: Word16
msgStmUniqueIdResp = 0x00E5

-- | SBP class for message MSG_STM_UNIQUE_ID_RESP (0x00E5).
--
-- This message reads the device's hardcoded unique ID. The host requests the
-- ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
-- MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload..
data MsgStmUniqueIdResp = MsgStmUniqueIdResp
  { _msgStmUniqueIdResp_stm_id :: [Word8]
    -- ^ Device unique ID
  } deriving ( Show, Read, Eq )

instance Binary MsgStmUniqueIdResp where
  get = do
    _msgStmUniqueIdResp_stm_id <- replicateM 12 getWord8
    return MsgStmUniqueIdResp {..}

  put MsgStmUniqueIdResp {..} = do
    mapM_ putWord8 _msgStmUniqueIdResp_stm_id

$(deriveSBP 'msgStmUniqueIdResp ''MsgStmUniqueIdResp)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgStmUniqueIdResp_" . stripPrefix "_msgStmUniqueIdResp_"}
             ''MsgStmUniqueIdResp)
$(makeLenses ''MsgStmUniqueIdResp)

msgM25FlashWriteStatus :: Word16
msgM25FlashWriteStatus = 0x00F3

-- | SBP class for message MSG_M25_FLASH_WRITE_STATUS (0x00F3).
--
-- The flash status message writes to the 8-bit M25 flash status register. The
-- device replies with a MSG_FLASH_DONE message.
data MsgM25FlashWriteStatus = MsgM25FlashWriteStatus
  { _msgM25FlashWriteStatus_status :: [Word8]
    -- ^ Byte to write to the M25 flash status register
  } deriving ( Show, Read, Eq )

instance Binary MsgM25FlashWriteStatus where
  get = do
    _msgM25FlashWriteStatus_status <- replicateM 1 getWord8
    return MsgM25FlashWriteStatus {..}

  put MsgM25FlashWriteStatus {..} = do
    mapM_ putWord8 _msgM25FlashWriteStatus_status

$(deriveSBP 'msgM25FlashWriteStatus ''MsgM25FlashWriteStatus)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgM25FlashWriteStatus_" . stripPrefix "_msgM25FlashWriteStatus_"}
             ''MsgM25FlashWriteStatus)
$(makeLenses ''MsgM25FlashWriteStatus)
