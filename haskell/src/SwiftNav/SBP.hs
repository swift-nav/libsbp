module SwiftNav.SBP where

import Data.Binary
import Data.Binary.Get
import Data.Binary.Put
import Data.ByteString
import Data.Word

msgPreamble :: Word8
msgPreamble = 0x55

data MsgSBP = MsgSBP
  { msgSBPType    :: Word16
  , msgSBPSender  :: Word16
  , msgSBPLen     :: Word8
  , msgSBPPayload :: ByteString
  , msgSBPCrc     :: Word16
  } deriving ( Show, Read, Eq )

instance Binary MsgSBP where
  get = do
    msgSBPType <- getWord16le
    msgSBPSender <- getWord16le
    msgSBPLen <- getWord8
    msgSBPPayload <- getByteString $ fromIntegral msgSBPLen
    msgSBPCrc <- getWord16le
    return MsgSBP {..}

  put MsgSBP {..} = do
    putWord16le msgSBPType
    putWord16le msgSBPSender
    putWord8 msgSBPLen
    putByteString msgSBPPayload
    putWord16le msgSBPCrc

getMsgSBP :: Get MsgSBP
getMsgSBP = do
  preamble <- getWord8
  if preamble /= msgPreamble then getMsgSBP else get

putMsgSBP :: MsgSBP -> Put
putMsgSBP msg = do
  putWord8 msgPreamble
  put msg
