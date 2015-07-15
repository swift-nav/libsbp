module SwiftNav.SBP.FileIo where

import Data.Int
import Data.Text
import Data.Word


msgFileioReadReq :: Word16
msgFileioReadReq = 0x00A8
data MsgFileioReadReq = MsgFileioReadReq
  { msgFileioReadReqSequence   :: Word32
  , msgFileioReadReqOffset     :: Word32
  , msgFileioReadReqChunkSize  :: Word8
  , msgFileioReadReqFilename   :: Text
  } deriving ( Show, Read, Eq )

msgFileioReadResp :: Word16
msgFileioReadResp = 0x00A3
data MsgFileioReadResp = MsgFileioReadResp
  { msgFileioReadRespSequence :: Word32
  , msgFileioReadRespContents :: [Word8]
  } deriving ( Show, Read, Eq )

msgFileioReadDirReq :: Word16
msgFileioReadDirReq = 0x00A9
data MsgFileioReadDirReq = MsgFileioReadDirReq
  { msgFileioReadDirReqSequence :: Word32
  , msgFileioReadDirReqOffset   :: Word32
  , msgFileioReadDirReqDirname  :: Text
  } deriving ( Show, Read, Eq )

msgFileioReadDirResp :: Word16
msgFileioReadDirResp = 0x00AA
data MsgFileioReadDirResp = MsgFileioReadDirResp
  { msgFileioReadDirRespSequence :: Word32
  , msgFileioReadDirRespContents :: [Word8]
  } deriving ( Show, Read, Eq )

msgFileioRemove :: Word16
msgFileioRemove = 0x00AC
data MsgFileioRemove = MsgFileioRemove
  { msgFileioRemoveFilename :: Text
  } deriving ( Show, Read, Eq )

msgFileioWriteReq :: Word16
msgFileioWriteReq = 0x00AD
data MsgFileioWriteReq = MsgFileioWriteReq
  { msgFileioWriteReqSequence :: Word32
  , msgFileioWriteReqOffset   :: Word32
  , msgFileioWriteReqFilename :: Text
  , msgFileioWriteReqData     :: [Word8]
  } deriving ( Show, Read, Eq )

msgFileioWriteResp :: Word16
msgFileioWriteResp = 0x00AB
data MsgFileioWriteResp = MsgFileioWriteResp
  { msgFileioWriteRespSequence :: Word32
  } deriving ( Show, Read, Eq )
