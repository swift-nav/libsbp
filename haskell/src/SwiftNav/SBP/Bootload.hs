-- |
-- Module:      SwiftNav.SBP.Bootload
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Messages for the bootloading configuration on the device.  These are in the
-- implementation-defined range (0x0000-0x00FF), and are intended for internal
-- use only. Note that some of these messages share the same message type ID
-- for both the host request and the device response.

module SwiftNav.SBP.Bootload where

import BasicPrelude
import Control.Monad.Loops
import Data.Aeson.TH (deriveJSON, defaultOptions, fieldLabelModifier)
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy hiding ( ByteString )
import Data.Int
import Data.Word
import SwiftNav.SBP.Encoding

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
    return MsgBootloaderHandshakeReq

  put MsgBootloaderHandshakeReq =
    return ()

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgBootloaderHandshakeReq_" . stripPrefix "msgBootloaderHandshakeReq_"}
             ''MsgBootloaderHandshakeReq)

msgBootloaderHandshakeResp :: Word16
msgBootloaderHandshakeResp = 0x00B4

-- | SBP class for message MSG_BOOTLOADER_HANDSHAKE_RESP (0x00B4).
--
-- The handshake message response from the device establishes a handshake
-- between the device bootloader and the host. The request from the host is
-- MSG_BOOTLOADER_HANDSHAKE_REQ.  The payload contains the bootloader version
-- number and the SBP protocol version number.
data MsgBootloaderHandshakeResp = MsgBootloaderHandshakeResp
  { msgBootloaderHandshakeResp_flags  :: Word32
    -- ^ Bootloader flags
  , msgBootloaderHandshakeResp_version :: ByteString
    -- ^ Bootloader version number
  } deriving ( Show, Read, Eq )

instance Binary MsgBootloaderHandshakeResp where
  get = do
    msgBootloaderHandshakeResp_flags <- getWord32le
    msgBootloaderHandshakeResp_version <- liftM toStrict getRemainingLazyByteString
    return MsgBootloaderHandshakeResp {..}

  put MsgBootloaderHandshakeResp {..} = do
    putWord32le msgBootloaderHandshakeResp_flags
    putByteString msgBootloaderHandshakeResp_version

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgBootloaderHandshakeResp_" . stripPrefix "msgBootloaderHandshakeResp_"}
             ''MsgBootloaderHandshakeResp)

msgBootloaderJumpToApp :: Word16
msgBootloaderJumpToApp = 0x00B1

-- | SBP class for message MSG_BOOTLOADER_JUMP_TO_APP (0x00B1).
--
-- The host initiates the bootloader to jump to the application.
data MsgBootloaderJumpToApp = MsgBootloaderJumpToApp
  { msgBootloaderJumpToApp_jump :: Word8
    -- ^ Ignored by the device
  } deriving ( Show, Read, Eq )

instance Binary MsgBootloaderJumpToApp where
  get = do
    msgBootloaderJumpToApp_jump <- getWord8
    return MsgBootloaderJumpToApp {..}

  put MsgBootloaderJumpToApp {..} = do
    putWord8 msgBootloaderJumpToApp_jump

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgBootloaderJumpToApp_" . stripPrefix "msgBootloaderJumpToApp_"}
             ''MsgBootloaderJumpToApp)

msgNapDeviceDnaReq :: Word16
msgNapDeviceDnaReq = 0x00DE

-- | SBP class for message MSG_NAP_DEVICE_DNA_REQ (0x00DE).
--
-- The device message from the host reads a unique device identifier from the
-- SwiftNAP, an FPGA. The host requests the ID by sending a
-- MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
-- MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note that
-- this ID is tied to the FPGA, and not related to the Piksi's serial number.
data MsgNapDeviceDnaReq = MsgNapDeviceDnaReq
  deriving ( Show, Read, Eq )

instance Binary MsgNapDeviceDnaReq where
  get =
    return MsgNapDeviceDnaReq

  put MsgNapDeviceDnaReq =
    return ()

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgNapDeviceDnaReq_" . stripPrefix "msgNapDeviceDnaReq_"}
             ''MsgNapDeviceDnaReq)

msgNapDeviceDnaResp :: Word16
msgNapDeviceDnaResp = 0x00DD

-- | SBP class for message MSG_NAP_DEVICE_DNA_RESP (0x00DD).
--
-- The device message from the host reads a unique device identifier from the
-- SwiftNAP, an FPGA. The host requests the ID by sending a
-- MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
-- MSG_NAP_DEVICE_DNA_RESP messagage with the device ID in the payload. Note
-- that this ID is tied to the FPGA, and not related to the Piksi's serial
-- number.
data MsgNapDeviceDnaResp = MsgNapDeviceDnaResp
  { msgNapDeviceDnaResp_dna :: [Word8]
    -- ^ 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the right.
  } deriving ( Show, Read, Eq )

instance Binary MsgNapDeviceDnaResp where
  get = do
    msgNapDeviceDnaResp_dna <- replicateM 8 getWord8
    return MsgNapDeviceDnaResp {..}

  put MsgNapDeviceDnaResp {..} = do
    mapM_ putWord8 msgNapDeviceDnaResp_dna

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgNapDeviceDnaResp_" . stripPrefix "msgNapDeviceDnaResp_"}
             ''MsgNapDeviceDnaResp)

msgBootloaderHandshakeDepA :: Word16
msgBootloaderHandshakeDepA = 0x00B0

-- | SBP class for message MSG_BOOTLOADER_HANDSHAKE_DEP_A (0x00B0).
--
-- Deprecated.
data MsgBootloaderHandshakeDepA = MsgBootloaderHandshakeDepA
  { msgBootloaderHandshakeDepA_handshake :: [Word8]
    -- ^ Version number string (not NULL terminated)
  } deriving ( Show, Read, Eq )

instance Binary MsgBootloaderHandshakeDepA where
  get = do
    msgBootloaderHandshakeDepA_handshake <- whileM (liftM not isEmpty) getWord8
    return MsgBootloaderHandshakeDepA {..}

  put MsgBootloaderHandshakeDepA {..} = do
    mapM_ putWord8 msgBootloaderHandshakeDepA_handshake

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgBootloaderHandshakeDepA_" . stripPrefix "msgBootloaderHandshakeDepA_"}
             ''MsgBootloaderHandshakeDepA)
