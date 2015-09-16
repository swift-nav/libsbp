-- |
-- Module:      SwiftNav.SBP
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- SBP message containers and serialization utilities.

module SwiftNav.SBP where

import BasicPrelude hiding (lookup)
import Data.Aeson hiding (decode)
import Data.Binary
import Data.Binary.Get
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy hiding (ByteString)
import Data.ByteString.Builder
import Data.HashMap.Strict
import Data.Scientific
import Data.Word
import SwiftNav.CRC16
((*- for m in modules *))
import (((m)))
((*- endfor *))

msgPreamble :: Word8
msgPreamble = 0x55

-- | Default sender ID. Intended for messages sent from the host to
-- the device.
defaultSenderID :: Word16
defaultSenderID = 0x42

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

checkCrc :: Msg -> Word16
checkCrc Msg {..} =
  crc16 $ toLazyByteString $
    word16LE msgSBPType   <>
    word16LE msgSBPSender <>
    word8 msgSBPLen       <>
    byteString msgSBPPayload

instance FromJSON Msg where
  parseJSON (Object v) = do
    Msg <$> v .: "msg_type"
        <*> v .: "sender"
        <*> v .: "length"
        <*> v .: "payload"
        <*> v .: "crc"
  parseJSON _ = mzero

instance ToJSON Msg where
  toJSON Msg {..} = object [ "preamble" .= msgPreamble
                           , "msg_type" .= msgSBPType
                           , "sender" .= msgSBPSender
                           , "length" .= msgSBPLen
                           , "payload" .= msgSBPPayload
                           , "crc" .= msgSBPCrc
                           ]
((* for m in msgs *))
((*- if loop.first *))
data SBPMsg =
     SBP(((m))) (((m))) Msg
((*- else *))
   | SBP(((m))) (((m))) Msg
((*- endif *))
((*- if loop.last *))
   | SBPMsgBadCrc Msg
   | SBPMsgUnknown Msg
  deriving ( Show, Read, Eq )
((*- endif *))
((*- endfor *))

instance Binary SBPMsg where
  get = do
    preamble <- getWord8
    if preamble /= msgPreamble then get else do
      sbp <- get
      return $ decode' sbp where
        decode' sbp@Msg {..}
          | checkCrc sbp /= msgSBPCrc = SBPMsgBadCrc sbp
          ((*- for m in msgs *))
          | msgSBPType == (((m | to_global))) = SBP(((m))) (decode (fromStrict msgSBPPayload)) sbp
          ((*- endfor *))
          | otherwise = SBPMsgUnknown sbp

  put msg = do
    putWord8 msgPreamble
    put $ encode' msg
    where
      ((*- for m in msgs *))
      encode' (SBP(((m))) _ sbp) = sbp
      ((*- endfor *))
      encode' (SBPMsgUnknown sbp) = sbp
      encode' (SBPMsgBadCrc  sbp) = sbp

instance FromJSON SBPMsg where
  parseJSON (Object o) = case lookup "msg_type" o of
    Nothing         -> mzero
    Just (Number msgType) -> decode' (toBoundedInteger msgType) where
                               decode' Nothing = mzero
                               decode' (Just t)
                         ((*- for m in msgs *))
                                 | t == (((m | to_global))) = SBP(((m))) <$> parseJSON (Object o) <*> parseJSON (Object o)
                         ((*- endfor *))
                                 | otherwise = SBPMsgUnknown <$> parseJSON (Object o)
    Just _ -> mzero
  parseJSON (_) = mzero

merge :: Value -> Value -> Value
merge (Object one) (Object two) = Object $ one <> two
merge _ _ = undefined

instance ToJSON SBPMsg where
  ((*- for m in msgs *))
   toJSON (SBP(((m))) msg sbp) = merge (toJSON msg) (toJSON sbp)
  ((*- endfor *))
   toJSON (SBPMsgBadCrc sbp) = toJSON sbp
   toJSON (SBPMsgUnknown sbp) = toJSON sbp
