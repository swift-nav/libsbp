{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Bootload
-- Copyright:   Copyright (C) 2015-2021 Swift Navigation, Inc.
-- License:     MIT
-- Contact:     https://support.swiftnav.com
-- Stability:   experimental
-- Portability: portable
--
-- \< Messages for the bootloading configuration of a Piksi 2.3.1.  This message
-- group does not apply to Piksi Multi.
--
-- Note that some of these messages share the same message type ID for both
-- the host request and the device response. \>

module SwiftNav.SBP.Bootload
  ( module SwiftNav.SBP.Bootload
  ) where

import BasicPrelude
import Control.Lens
import Control.Monad.Loops
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString.Lazy    hiding (ByteString)
import Data.Int
import Data.Word
import SwiftNav.SBP.TH
import SwiftNav.SBP.Types

{-# ANN module ("HLint: ignore Use camelCase"::String) #-}
{-# ANN module ("HLint: ignore Redundant do"::String) #-}
{-# ANN module ("HLint: ignore Use newtype instead of data"::String) #-}


msgBootloaderHandshakeReq :: Word16
msgBootloaderHandshakeReq = 0x00B3

-- | SBP class for message MSG_BOOTLOADER_HANDSHAKE_REQ (0x00B3).
--
-- The handshake message request from the host establishes a handshake between
-- the device bootloader and the host. The response from the device is
-- MSG_BOOTLOADER_HANDSHAKE_RESP.
data MsgBootloaderHandshakeReq = MsgBootloaderHandshakeReq
  deriving ( Show, Read, Eq )

instance Binary MsgBootloaderHandshakeReq where
  get =
    pure MsgBootloaderHandshakeReq

  put MsgBootloaderHandshakeReq =
    pure ()
$(makeSBP 'msgBootloaderHandshakeReq ''MsgBootloaderHandshakeReq)
$(makeJSON "_msgBootloaderHandshakeReq_" ''MsgBootloaderHandshakeReq)
$(makeLenses ''MsgBootloaderHandshakeReq)

msgBootloaderHandshakeResp :: Word16
msgBootloaderHandshakeResp = 0x00B4

-- | SBP class for message MSG_BOOTLOADER_HANDSHAKE_RESP (0x00B4).
--
-- The handshake message response from the device establishes a handshake
-- between the device bootloader and the host. The request from the host is
-- MSG_BOOTLOADER_HANDSHAKE_REQ.  The payload contains the bootloader version
-- number and the SBP protocol version number.
data MsgBootloaderHandshakeResp = MsgBootloaderHandshakeResp
  { _msgBootloaderHandshakeResp_flags :: !Word32
    -- ^ Bootloader flags
  , _msgBootloaderHandshakeResp_version :: !Text
    -- ^ Bootloader version number
  } deriving ( Show, Read, Eq )

instance Binary MsgBootloaderHandshakeResp where
  get = do
    _msgBootloaderHandshakeResp_flags <- getWord32le
    _msgBootloaderHandshakeResp_version <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgBootloaderHandshakeResp {..}

  put MsgBootloaderHandshakeResp {..} = do
    putWord32le _msgBootloaderHandshakeResp_flags
    putByteString $ encodeUtf8 _msgBootloaderHandshakeResp_version

$(makeSBP 'msgBootloaderHandshakeResp ''MsgBootloaderHandshakeResp)
$(makeJSON "_msgBootloaderHandshakeResp_" ''MsgBootloaderHandshakeResp)
$(makeLenses ''MsgBootloaderHandshakeResp)

msgBootloaderJumpToApp :: Word16
msgBootloaderJumpToApp = 0x00B1

-- | SBP class for message MSG_BOOTLOADER_JUMP_TO_APP (0x00B1).
--
-- The host initiates the bootloader to jump to the application.
data MsgBootloaderJumpToApp = MsgBootloaderJumpToApp
  { _msgBootloaderJumpToApp_jump :: !Word8
    -- ^ Ignored by the device
  } deriving ( Show, Read, Eq )

instance Binary MsgBootloaderJumpToApp where
  get = do
    _msgBootloaderJumpToApp_jump <- getWord8
    pure MsgBootloaderJumpToApp {..}

  put MsgBootloaderJumpToApp {..} = do
    putWord8 _msgBootloaderJumpToApp_jump

$(makeSBP 'msgBootloaderJumpToApp ''MsgBootloaderJumpToApp)
$(makeJSON "_msgBootloaderJumpToApp_" ''MsgBootloaderJumpToApp)
$(makeLenses ''MsgBootloaderJumpToApp)

msgNapDeviceDnaReq :: Word16
msgNapDeviceDnaReq = 0x00DE

-- | SBP class for message MSG_NAP_DEVICE_DNA_REQ (0x00DE).
--
-- The device message from the host reads a unique device identifier from the
-- SwiftNAP, an FPGA. The host requests the ID by sending a
-- MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
-- MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
-- that this ID is tied to the FPGA, and not related to the Piksi's serial
-- number.
data MsgNapDeviceDnaReq = MsgNapDeviceDnaReq
  deriving ( Show, Read, Eq )

instance Binary MsgNapDeviceDnaReq where
  get =
    pure MsgNapDeviceDnaReq

  put MsgNapDeviceDnaReq =
    pure ()
$(makeSBP 'msgNapDeviceDnaReq ''MsgNapDeviceDnaReq)
$(makeJSON "_msgNapDeviceDnaReq_" ''MsgNapDeviceDnaReq)
$(makeLenses ''MsgNapDeviceDnaReq)

msgNapDeviceDnaResp :: Word16
msgNapDeviceDnaResp = 0x00DD

-- | SBP class for message MSG_NAP_DEVICE_DNA_RESP (0x00DD).
--
-- The device message from the host reads a unique device identifier from the
-- SwiftNAP, an FPGA. The host requests the ID by sending a
-- MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
-- MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
-- that this ID is tied to the FPGA, and not related to the Piksi's serial
-- number.
data MsgNapDeviceDnaResp = MsgNapDeviceDnaResp
  { _msgNapDeviceDnaResp_dna :: ![Word8]
    -- ^ 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the right.
  } deriving ( Show, Read, Eq )

instance Binary MsgNapDeviceDnaResp where
  get = do
    _msgNapDeviceDnaResp_dna <- replicateM 8 getWord8
    pure MsgNapDeviceDnaResp {..}

  put MsgNapDeviceDnaResp {..} = do
    mapM_ putWord8 _msgNapDeviceDnaResp_dna

$(makeSBP 'msgNapDeviceDnaResp ''MsgNapDeviceDnaResp)
$(makeJSON "_msgNapDeviceDnaResp_" ''MsgNapDeviceDnaResp)
$(makeLenses ''MsgNapDeviceDnaResp)

msgBootloaderHandshakeDepA :: Word16
msgBootloaderHandshakeDepA = 0x00B0

-- | SBP class for message MSG_BOOTLOADER_HANDSHAKE_DEP_A (0x00B0).
--
-- Deprecated.
data MsgBootloaderHandshakeDepA = MsgBootloaderHandshakeDepA
  { _msgBootloaderHandshakeDepA_handshake :: ![Word8]
    -- ^ Version number string (not NULL terminated)
  } deriving ( Show, Read, Eq )

instance Binary MsgBootloaderHandshakeDepA where
  get = do
    _msgBootloaderHandshakeDepA_handshake <- whileM (not <$> isEmpty) getWord8
    pure MsgBootloaderHandshakeDepA {..}

  put MsgBootloaderHandshakeDepA {..} = do
    mapM_ putWord8 _msgBootloaderHandshakeDepA_handshake

$(makeSBP 'msgBootloaderHandshakeDepA ''MsgBootloaderHandshakeDepA)
$(makeJSON "_msgBootloaderHandshakeDepA_" ''MsgBootloaderHandshakeDepA)
$(makeLenses ''MsgBootloaderHandshakeDepA)

