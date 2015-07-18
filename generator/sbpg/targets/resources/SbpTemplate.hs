module SwiftNav.SBP where

import Data.Binary
import Data.Binary.Get
import Data.Binary.Put
import Data.ByteString
import Data.Word
((*- for m in modules *))
import (((m)))
((*- endfor *))

msgPreamble :: Word8
msgPreamble = 0x55

data Msg = Msg
  { msgSBPType    :: Word16
  , msgSBPSender  :: Word16
  , msgSBPLen     :: Word8
  , msgSBPPayload :: ByteString
  , msgSBPCrc     :: Word16
  } deriving ( Show, Read, Eq )

instance Binary Msg where
  get = do
    msgSBPType <- getWord16le
    msgSBPSender <- getWord16le
    msgSBPLen <- getWord8
    msgSBPPayload <- getByteString $ fromIntegral msgSBPLen
    msgSBPCrc <- getWord16le
    return Msg {..}

  put Msg {..} = do
    putWord16le msgSBPType
    putWord16le msgSBPSender
    putWord8 msgSBPLen
    putByteString msgSBPPayload
    putWord16le msgSBPCrc

getMsg :: Get Msg
getMsg = do
  preamble <- getWord8
  if preamble /= msgPreamble then getMsg else get

putMsg :: Msg -> Put
putMsg msg = do
  putWord8 msgPreamble
  put msg
((* for m in msgs *))
((*- if loop.first *))
data SBPMsg =
     SBP(((m))) (((m)))
((*- else *))
   | SBP(((m))) (((m)))
((*- endif *))
((*- if loop.last *))
  deriving ( Show, Read, Eq )
((*- endif *))
((*- endfor *))
