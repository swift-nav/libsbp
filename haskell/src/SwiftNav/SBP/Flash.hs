module SwiftNav.SBP.Flash where

import Data.Binary
import Data.Int
import Data.Text
import Data.Word

msgFlashProgram :: Word16
msgFlashProgram = 0x00E6

data MsgFlashProgram = MsgFlashProgram
  { msgFlashProgramTarget     :: Word8
  , msgFlashProgramAddrStart  :: [Word8]
  , msgFlashProgramAddrLen    :: Word8
  , msgFlashProgramData       :: [Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgFlashProgram where
  get =
    undefined
  put MsgFlashProgram {..} =
    undefined

msgFlashDone :: Word16
msgFlashDone = 0x00E0

data MsgFlashDone = MsgFlashDone
  { msgFlashDoneResponse :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgFlashDone where
  get =
    undefined
  put MsgFlashDone {..} =
    undefined

msgFlashReadReq :: Word16
msgFlashReadReq = 0x00E7

data MsgFlashReadReq = MsgFlashReadReq
  { msgFlashReadReqTarget     :: Word8
  , msgFlashReadReqAddrStart  :: [Word8]
  , msgFlashReadReqAddrLen    :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgFlashReadReq where
  get =
    undefined
  put MsgFlashReadReq {..} =
    undefined

msgFlashReadResp :: Word16
msgFlashReadResp = 0x00E1

data MsgFlashReadResp = MsgFlashReadResp
  { msgFlashReadRespTarget     :: Word8
  , msgFlashReadRespAddrStart  :: [Word8]
  , msgFlashReadRespAddrLen    :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgFlashReadResp where
  get =
    undefined
  put MsgFlashReadResp {..} =
    undefined

msgFlashErase :: Word16
msgFlashErase = 0x00E2

data MsgFlashErase = MsgFlashErase
  { msgFlashEraseTarget     :: Word8
  , msgFlashEraseSectorNum  :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgFlashErase where
  get =
    undefined
  put MsgFlashErase {..} =
    undefined

msgStmFlashLockSector :: Word16
msgStmFlashLockSector = 0x00E3

data MsgStmFlashLockSector = MsgStmFlashLockSector
  { msgStmFlashLockSectorSector :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgStmFlashLockSector where
  get =
    undefined
  put MsgStmFlashLockSector {..} =
    undefined

msgStmFlashUnlockSector :: Word16
msgStmFlashUnlockSector = 0x00E4

data MsgStmFlashUnlockSector = MsgStmFlashUnlockSector
  { msgStmFlashUnlockSectorSector :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgStmFlashUnlockSector where
  get =
    undefined
  put MsgStmFlashUnlockSector {..} =
    undefined

msgStmUniqueIdReq :: Word16
msgStmUniqueIdReq = 0x00E8

data MsgStmUniqueIdReq = MsgStmUniqueIdReq
  deriving ( Show, Read, Eq )

instance Binary MsgStmUniqueIdReq where
  get =
    undefined
  put MsgStmUniqueIdReq {..} =
    undefined

msgStmUniqueIdResp :: Word16
msgStmUniqueIdResp = 0x00E5

data MsgStmUniqueIdResp = MsgStmUniqueIdResp
  { msgStmUniqueIdRespStmId  :: [Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgStmUniqueIdResp where
  get =
    undefined
  put MsgStmUniqueIdResp {..} =
    undefined

msgM25FlashWriteStatus :: Word16
msgM25FlashWriteStatus = 0x00F3

data MsgM25FlashWriteStatus = MsgM25FlashWriteStatus
  { msgM25FlashWriteStatusStatus :: [Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgM25FlashWriteStatus where
  get =
    undefined
  put MsgM25FlashWriteStatus {..} =
    undefined
