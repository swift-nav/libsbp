module SwiftNav.SBP.FileIo where

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

msgFileioReadReq :: Word16
msgFileioReadReq = 0x00A8

data MsgFileioReadReq = MsgFileioReadReq
  { msgFileioReadReqSequence   :: Word32
  , msgFileioReadReqOffset     :: Word32
  , msgFileioReadReqChunkSize  :: Word8
  , msgFileioReadReqFilename   :: ByteString
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioReadReq where
  get = do
    msgFileioReadReqSequence <- getWord32le
    msgFileioReadReqOffset <- getWord32le
    msgFileioReadReqChunkSize <- getWord8
    msgFileioReadReqFilename <- liftM toStrict getRemainingLazyByteString
    return MsgFileioReadReq {..}

  put MsgFileioReadReq {..} = do
    putWord32le msgFileioReadReqSequence
    putWord32le msgFileioReadReqOffset
    putWord8 msgFileioReadReqChunkSize
    putByteString msgFileioReadReqFilename

msgFileioReadResp :: Word16
msgFileioReadResp = 0x00A3

data MsgFileioReadResp = MsgFileioReadResp
  { msgFileioReadRespSequence :: Word32
  , msgFileioReadRespContents :: [Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioReadResp where
  get = do
    msgFileioReadRespSequence <- getWord32le
    msgFileioReadRespContents <- whileM (liftM not isEmpty) getWord8
    return MsgFileioReadResp {..}

  put MsgFileioReadResp {..} = do
    putWord32le msgFileioReadRespSequence
    mapM_ putWord8 msgFileioReadRespContents

msgFileioReadDirReq :: Word16
msgFileioReadDirReq = 0x00A9

data MsgFileioReadDirReq = MsgFileioReadDirReq
  { msgFileioReadDirReqSequence :: Word32
  , msgFileioReadDirReqOffset   :: Word32
  , msgFileioReadDirReqDirname  :: ByteString
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioReadDirReq where
  get = do
    msgFileioReadDirReqSequence <- getWord32le
    msgFileioReadDirReqOffset <- getWord32le
    msgFileioReadDirReqDirname <- liftM toStrict getRemainingLazyByteString
    return MsgFileioReadDirReq {..}

  put MsgFileioReadDirReq {..} = do
    putWord32le msgFileioReadDirReqSequence
    putWord32le msgFileioReadDirReqOffset
    putByteString msgFileioReadDirReqDirname

msgFileioReadDirResp :: Word16
msgFileioReadDirResp = 0x00AA

data MsgFileioReadDirResp = MsgFileioReadDirResp
  { msgFileioReadDirRespSequence :: Word32
  , msgFileioReadDirRespContents :: [Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioReadDirResp where
  get = do
    msgFileioReadDirRespSequence <- getWord32le
    msgFileioReadDirRespContents <- whileM (liftM not isEmpty) getWord8
    return MsgFileioReadDirResp {..}

  put MsgFileioReadDirResp {..} = do
    putWord32le msgFileioReadDirRespSequence
    mapM_ putWord8 msgFileioReadDirRespContents

msgFileioRemove :: Word16
msgFileioRemove = 0x00AC

data MsgFileioRemove = MsgFileioRemove
  { msgFileioRemoveFilename :: ByteString
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioRemove where
  get = do
    msgFileioRemoveFilename <- liftM toStrict getRemainingLazyByteString
    return MsgFileioRemove {..}

  put MsgFileioRemove {..} = do
    putByteString msgFileioRemoveFilename

msgFileioWriteReq :: Word16
msgFileioWriteReq = 0x00AD

data MsgFileioWriteReq = MsgFileioWriteReq
  { msgFileioWriteReqSequence :: Word32
  , msgFileioWriteReqOffset   :: Word32
  , msgFileioWriteReqFilename :: ByteString
  , msgFileioWriteReqData     :: [Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioWriteReq where
  get = do
    msgFileioWriteReqSequence <- getWord32le
    msgFileioWriteReqOffset <- getWord32le
    msgFileioWriteReqFilename <- liftM toStrict getRemainingLazyByteString
    msgFileioWriteReqData <- whileM (liftM not isEmpty) getWord8
    return MsgFileioWriteReq {..}

  put MsgFileioWriteReq {..} = do
    putWord32le msgFileioWriteReqSequence
    putWord32le msgFileioWriteReqOffset
    putByteString msgFileioWriteReqFilename
    mapM_ putWord8 msgFileioWriteReqData

msgFileioWriteResp :: Word16
msgFileioWriteResp = 0x00AB

data MsgFileioWriteResp = MsgFileioWriteResp
  { msgFileioWriteRespSequence :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgFileioWriteResp where
  get = do
    msgFileioWriteRespSequence <- getWord32le
    return MsgFileioWriteResp {..}

  put MsgFileioWriteResp {..} = do
    putWord32le msgFileioWriteRespSequence
