-- |
-- Module:      SwiftNav.SBP
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable

module SwiftNav.SBP where

import BasicPrelude
import Data.Binary
import Data.Binary.Get
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy hiding (ByteString)
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
  , msgSBPPayload :: !ByteString
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
     SBP(((m))) (((m))) Msg
((*- else *))
   | SBP(((m))) (((m))) Msg
((*- endif *))
((*- if loop.last *))
   | SBPMsgUnknown Msg
  deriving ( Show, Read, Eq )
((*- endif *))
((*- endfor *))

instance Binary SBPMsg where
  get = do
    preamble <- getWord8
    if preamble /= msgPreamble then get else do
      t <- getWord16le
      s <- getWord16le
      l <- getWord8
      p <- getByteString $ fromIntegral l
      crc <- getWord16le
      let sbp = Msg t s l p crc
      return $ decode' t p sbp where
        decode' t p sbp
          ((*- for m in msgs *))
          | t == (((m | to_global))) = SBP(((m))) (decode (fromStrict p)) sbp
          ((*- endfor *))
          | otherwise = SBPMsgUnknown sbp

  put msg = do
    putWord8 msgPreamble
    put $ t msg
    where
      ((*- for m in msgs *))
      t (SBP(((m))) _ sbp) = sbp
      ((*- endfor *))
      t (SBPMsgUnknown sbp) = sbp
