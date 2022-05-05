{-# LANGUAGE NoImplicitPrelude #-}
{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE RecordWildCards   #-}
{-# LANGUAGE TemplateHaskell   #-}

-- |
-- Module:      SwiftNav.SBP.Types
-- Copyright:   Copyright (C) 2015-2021 Swift Navigation, Inc.
-- License:     MIT
-- Contact:     https://support.swiftnav.com
-- Stability:   experimental
-- Portability: portable
--
-- Common SBP type requirements, containers, and serialization
-- utilities.
--

module SwiftNav.SBP.Types
  ( module SwiftNav.SBP.Types
  ) where

import BasicPrelude
import Control.Lens             hiding ((.=))
import Data.Aeson
import Data.Binary
import Data.Binary.Get
import Data.Binary.Put
import Data.ByteString.Base64   as Base64
import Data.ByteString.Builder
import Data.Text.Encoding
import Data.Text.Encoding.Error
import SwiftNav.CRC16

-- | Denotes the start of frame transmission. For v1.0, always 0x55.
msgSBPPreamble :: Word8
msgSBPPreamble = 0x55

-- | Default sender ID. Intended for messages sent from the host to
-- the device.
defaultSender :: Word16
defaultSender = 0x42

-- | Wrapper around ByteString for *JSON and Binary typeclass instances.
newtype Bytes = Bytes
  { unBytes :: ByteString
  } deriving ( Show, Read, Eq )

-- | Packet structure for Swift Navigation Binary Protocol (SBP).
--
-- Definition of the over-the-wire message framing format and packet
-- structure for Swift Navigation Binary Protocol (SBP), a minimal
-- binary protocol for communicating with Swift devices. It is used
-- to transmit solutions, observations, status and debugging
-- messages, as well as receive messages from the host operating
-- system.
data Msg = Msg
  { _msgSBPType    :: !Word16
    -- ^ Uniquely identifies the type of the payload contents
  , _msgSBPSender  :: !Word16
    -- ^ A unique identifier of the sending hardware. For v1.0,
    -- set to the 2 least significant bytes of the device serial
    -- number
  , _msgSBPLen     :: !Word8
    -- ^ Byte-length of the payload field
  , _msgSBPPayload :: !Bytes
    -- ^ Binary data of the message, as identified by Message Type and
    -- Length. Usually contains the in-memory binary representation of
    -- a C struct (see documentation on individual message types)
  , _msgSBPCrc     :: !Word16
    -- ^ Cyclic Redundancy Check (CRC) of the packet's binary data from
    -- the Message Type up to the end of Payload (does not include the
    -- Preamble)
  } deriving ( Show, Read, Eq )

$(makeClassy ''Msg)

instance Binary Msg where
  get = do
    _msgSBPType    <- getWord16le
    _msgSBPSender  <- getWord16le
    _msgSBPLen     <- getWord8
    _msgSBPPayload <- fmap Bytes $ getByteString $ fromIntegral _msgSBPLen
    _msgSBPCrc     <- getWord16le
    pure Msg {..}

  put Msg {..} = do
    putWord16le   _msgSBPType
    putWord16le   _msgSBPSender
    putWord8      _msgSBPLen
    putByteString (unBytes _msgSBPPayload)
    putWord16le   _msgSBPCrc

instance FromJSON Bytes where
  parseJSON = withText "ByteString" (pure . Bytes . Base64.decodeLenient . encodeUtf8)

instance FromJSON Msg where
  parseJSON (Object v) =
    Msg <$> v .: "msg_type"
        <*> v .: "sender"
        <*> v .: "length"
        <*> v .: "payload"
        <*> v .: "crc"
  parseJSON _ = mzero

instance ToJSON Bytes where
  toJSON = toJSON . decodeUtf8With ignore . Base64.encode . unBytes

instance ToJSON Msg where
  toJSON Msg {..} = object
    [ "preamble" .= msgSBPPreamble
    , "msg_type" .= _msgSBPType
    , "sender"   .= _msgSBPSender
    , "length"   .= _msgSBPLen
    , "payload"  .= _msgSBPPayload
    , "crc"      .= _msgSBPCrc
    ]

-- | Class of generic representation of specialized SBP messages into
-- SBP message frames.
class Binary a => ToSBP a where
    -- | Convert an SBP message record that is serializable and a two-byte
    -- senderID to a binary into an SBP message frame.
    toSBP :: a -> Word16 -> Msg

checkCrc :: Msg -> Word16
checkCrc Msg {..} =
  crc16 $ toLazyByteString $
    word16LE _msgSBPType   <>
    word16LE _msgSBPSender <>
    word8 _msgSBPLen       <>
    byteString (unBytes _msgSBPPayload)
