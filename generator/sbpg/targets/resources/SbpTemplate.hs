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
import Data.ByteString.Builder
import Data.ByteString.Lazy hiding (ByteString)
import Data.Word
import SwiftNav.CRC16
((*- for m in modules *))
import (((m)))
((*- endfor *))

msgSBPPreamble :: Word8
msgSBPPreamble = 0x55

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

toBuilder :: Msg -> Builder
toBuilder Msg {..} = mconcat
  [ word16LE msgSBPType
  , word16LE msgSBPSender
  , word8 msgSBPLen
  , byteString msgSBPPayload
  ]

toCrc16 :: Msg -> Word16
toCrc16 = crc16 . toLazyByteString . toBuilder

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
    if preamble /= msgSBPPreamble then get else do
      sbp <- get
      if toCrc16 sbp /= msgSBPCrc sbp then get else
        return $ decode' sbp where
          decode' sbp
            ((*- for m in msgs *))
            | msgSBPType sbp == (((m | to_global))) = SBP(((m))) (decode (fromStrict (msgSBPPayload sbp))) sbp
            ((*- endfor *))
            | otherwise = SBPMsgUnknown sbp

  put msg = do
    putWord8 msgSBPPreamble
    put $ encode' msg
    where
      ((*- for m in msgs *))
      encode' (SBP(((m))) _ sbp) = sbp
      ((*- endfor *))
      encode' (SBPMsgUnknown sbp) = sbp
