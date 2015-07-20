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

data MsgFlashProgram = MsgFlashProgram
  { msgFlashProgramTarget     :: Word8
  , msgFlashProgramAddrStart  :: [Word8]
  , msgFlashProgramAddrLen    :: Word8
  , msgFlashProgramData       :: [Word8]
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

data MsgFlashDone = MsgFlashDone
  { msgFlashDoneResponse :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgFlashDone where
  get = do
    msgFlashDoneResponse <- getWord8
    return MsgFlashDone {..}

  put MsgFlashDone {..} = do
    putWord8 msgFlashDoneResponse

msgFlashReadReq :: Word16
msgFlashReadReq = 0x00E7

data MsgFlashReadReq = MsgFlashReadReq
  { msgFlashReadReqTarget     :: Word8
  , msgFlashReadReqAddrStart  :: [Word8]
  , msgFlashReadReqAddrLen    :: Word8
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

data MsgFlashReadResp = MsgFlashReadResp
  { msgFlashReadRespTarget     :: Word8
  , msgFlashReadRespAddrStart  :: [Word8]
  , msgFlashReadRespAddrLen    :: Word8
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

data MsgFlashErase = MsgFlashErase
  { msgFlashEraseTarget     :: Word8
  , msgFlashEraseSectorNum  :: Word32
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

data MsgStmFlashLockSector = MsgStmFlashLockSector
  { msgStmFlashLockSectorSector :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgStmFlashLockSector where
  get = do
    msgStmFlashLockSectorSector <- getWord32le
    return MsgStmFlashLockSector {..}

  put MsgStmFlashLockSector {..} = do
    putWord32le msgStmFlashLockSectorSector

msgStmFlashUnlockSector :: Word16
msgStmFlashUnlockSector = 0x00E4

data MsgStmFlashUnlockSector = MsgStmFlashUnlockSector
  { msgStmFlashUnlockSectorSector :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgStmFlashUnlockSector where
  get = do
    msgStmFlashUnlockSectorSector <- getWord32le
    return MsgStmFlashUnlockSector {..}

  put MsgStmFlashUnlockSector {..} = do
    putWord32le msgStmFlashUnlockSectorSector

msgStmUniqueIdReq :: Word16
msgStmUniqueIdReq = 0x00E8

data MsgStmUniqueIdReq = MsgStmUniqueIdReq
  deriving ( Show, Read, Eq )

instance Binary MsgStmUniqueIdReq where
  get =
    return MsgStmUniqueIdReq

  put MsgStmUniqueIdReq =
    return ()

msgStmUniqueIdResp :: Word16
msgStmUniqueIdResp = 0x00E5

data MsgStmUniqueIdResp = MsgStmUniqueIdResp
  { msgStmUniqueIdRespStmId  :: [Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgStmUniqueIdResp where
  get = do
    msgStmUniqueIdRespStmId <- replicateM 12 getWord8
    return MsgStmUniqueIdResp {..}

  put MsgStmUniqueIdResp {..} = do
    mapM_ putWord8 msgStmUniqueIdRespStmId

msgM25FlashWriteStatus :: Word16
msgM25FlashWriteStatus = 0x00F3

data MsgM25FlashWriteStatus = MsgM25FlashWriteStatus
  { msgM25FlashWriteStatusStatus :: [Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgM25FlashWriteStatus where
  get = do
    msgM25FlashWriteStatusStatus <- replicateM 1 getWord8
    return MsgM25FlashWriteStatus {..}

  put MsgM25FlashWriteStatus {..} = do
    mapM_ putWord8 msgM25FlashWriteStatusStatus
