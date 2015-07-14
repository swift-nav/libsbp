module SwiftNav.SBP.Flash where

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

msgFlashDone :: Word16
msgFlashDone = 0x00E0

data MsgFlashDone = MsgFlashDone
  { msgFlashDoneResponse :: Word8
  } deriving ( Show, Read, Eq )

msgFlashReadReq :: Word16
msgFlashReadReq = 0x00E7

data MsgFlashReadReq = MsgFlashReadReq
  { msgFlashReadReqTarget     :: Word8
  , msgFlashReadReqAddrStart  :: [Word8]
  , msgFlashReadReqAddrLen    :: Word8
  } deriving ( Show, Read, Eq )

msgFlashReadResp :: Word16
msgFlashReadResp = 0x00E1

data MsgFlashReadResp = MsgFlashReadResp
  { msgFlashReadRespTarget     :: Word8
  , msgFlashReadRespAddrStart  :: [Word8]
  , msgFlashReadRespAddrLen    :: Word8
  } deriving ( Show, Read, Eq )

msgFlashErase :: Word16
msgFlashErase = 0x00E2

data MsgFlashErase = MsgFlashErase
  { msgFlashEraseTarget     :: Word8
  , msgFlashEraseSectorNum  :: Word32
  } deriving ( Show, Read, Eq )

msgStmFlashLockSector :: Word16
msgStmFlashLockSector = 0x00E3

data MsgStmFlashLockSector = MsgStmFlashLockSector
  { msgStmFlashLockSectorSector :: Word32
  } deriving ( Show, Read, Eq )

msgStmFlashUnlockSector :: Word16
msgStmFlashUnlockSector = 0x00E4

data MsgStmFlashUnlockSector = MsgStmFlashUnlockSector
  { msgStmFlashUnlockSectorSector :: Word32
  } deriving ( Show, Read, Eq )

msgStmUniqueIdReq :: Word16
msgStmUniqueIdReq = 0x00E8


msgStmUniqueIdResp :: Word16
msgStmUniqueIdResp = 0x00E5

data MsgStmUniqueIdResp = MsgStmUniqueIdResp
  { msgStmUniqueIdRespStmId  :: [Word8]
  } deriving ( Show, Read, Eq )

msgM25FlashWriteStatus :: Word16
msgM25FlashWriteStatus = 0x00F3

data MsgM25FlashWriteStatus = MsgM25FlashWriteStatus
  { msgM25FlashWriteStatusStatus :: [Word8]
  } deriving ( Show, Read, Eq )
