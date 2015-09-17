-- |
-- Module:      SwiftNav.SBP
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- SBP message containers.

module SwiftNav.SBP
  ( Msg (..)
  , SBPMsg (..)
  , msgSBPPreamble
  , defaultSender
((*- for m in modules *))
  , module (((m)))
((*- endfor *))
  ) where

import BasicPrelude hiding (lookup)
import Control.Lens hiding ((.=))
import Data.Aeson hiding (decode, decode')
import Data.Binary
import Data.Binary.Get
import Data.Binary.Put
import Data.ByteString.Lazy hiding (ByteString)
import Data.ByteString.Builder
import Data.HashMap.Strict
import SwiftNav.CRC16
((*- for m in modules *))
import (((m)))
((*- endfor *))

-- | Denotes the start of frame transmission. For v1.0, always 0x55.
msgSBPPreamble :: Word8
msgSBPPreamble = 0x55

-- | Default sender ID. Intended for messages sent from the host to
-- the device.
defaultSender :: Word16
defaultSender = 0x42

-- | Packet structure for Swift Navigation Binary Protocol (SBP).
--
-- Definition of the over-the-wire message framing format and packet
-- structure for Swift Navigation Binary Protocol (SBP), a minimal
-- binary protocol for communicating with Swift devices. It is used
-- to transmit solutions, observations, status and debugging
-- messages, as well as receive messages from the host operating
-- system.
data Msg = Msg
  { _msgSBPType    :: Word16
    -- ^ Uniquely identifies the type of the payload contents
  , _msgSBPSender  :: Word16
    -- ^ A unique identifier of the sending hardware. For v1.0,
    -- set to the 2 least significant bytes of the device serial
    -- number
  , _msgSBPLen     :: Word8
    -- ^ Byte-length of the payload field
  , _msgSBPPayload :: !ByteString
    -- ^ Binary data of the message, as identified by Message Type and
    -- Length. Usually contains the in-memory binary representation of
    -- a C struct (see documentation on individual message types)
  , _msgSBPCrc     :: Word16
    -- ^ Cyclic Redundancy Check (CRC) of the packet's binary data from
    -- the Message Type up to the end of Payload (does not include the
    -- Preamble)
  } deriving ( Show, Read, Eq )

$(makeLenses ''Msg)

instance Binary Msg where
  get = do
    _msgSBPType <- getWord16le
    _msgSBPSender <- getWord16le
    _msgSBPLen <- getWord8
    _msgSBPPayload <- getByteString $ fromIntegral _msgSBPLen
    _msgSBPCrc <- getWord16le
    return Msg {..}

  put Msg {..} = do
    putWord16le _msgSBPType
    putWord16le _msgSBPSender
    putWord8 _msgSBPLen
    putByteString _msgSBPPayload
    putWord16le _msgSBPCrc

checkCrc :: Msg -> Word16
checkCrc Msg {..} =
  crc16 $ toLazyByteString $
    word16LE _msgSBPType   <>
    word16LE _msgSBPSender <>
    word8 _msgSBPLen       <>
    byteString _msgSBPPayload

instance FromJSON Msg where
  parseJSON (Object v) = do
    Msg <$> v .: "msg_type"
        <*> v .: "sender"
        <*> v .: "length"
        <*> v .: "payload"
        <*> v .: "crc"
  parseJSON _ = mzero

instance ToJSON Msg where
  toJSON Msg {..} = object
    [ "preamble" .= msgSBPPreamble
    , "msg_type" .= _msgSBPType
    , "sender" .= _msgSBPSender
    , "length" .= _msgSBPLen
    , "payload" .= _msgSBPPayload
    , "crc" .= _msgSBPCrc
    ]
((* for m in msgs *))
((*- if loop.first *))
-- | An SBP message ADT composed of all defined SBP messages.
--
-- Includes SBPMsgUnknown for valid SBP messages with undefined message
-- types and SBPMsgBadCRC for SBP messages with invalid CRC checksums.
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
    if preamble /= msgSBPPreamble then get else do
      sbp <- get
      return $ decode' sbp where
        decode' sbp@Msg {..}
          | checkCrc sbp /= _msgSBPCrc = SBPMsgBadCrc sbp
          ((*- for m in msgs *))
          | _msgSBPType == (((m | to_global))) = SBP(((m))) (decode (fromStrict _msgSBPPayload)) sbp
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
      encode' (SBPMsgBadCrc  sbp) = sbp

instance FromJSON SBPMsg where
  parseJSON obj@(Object o) = do
    msgType <- o .: "msg_type"
    decode' msgType where
      decode' msgType
((*- for m in msgs *))
        | msgType == (((m | to_global))) = SBP(((m))) <$> parseJSON obj <*> parseJSON obj
((*- endfor *))
        | otherwise = SBPMsgUnknown <$> parseJSON obj
  parseJSON _ = mzero

merge :: Value -> Value -> Value
merge (Object one) (Object two) = Object (one <> two)
merge _ (Object two) = Object two
merge (Object one) _ = Object one
merge _ v = v

instance ToJSON SBPMsg where
((*- for m in msgs *))
   toJSON (SBP(((m))) msg sbp) = toJSON msg `merge` toJSON sbp
((*- endfor *))
   toJSON (SBPMsgBadCrc sbp) = toJSON sbp
   toJSON (SBPMsgUnknown sbp) = toJSON sbp
