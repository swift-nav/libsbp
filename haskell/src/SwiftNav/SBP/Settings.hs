-- |
-- Module:      SwiftNav.SBP.Settings
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Messages for reading and writing the device's device settings.  These are in
-- the implementation-defined range (0x0000-0x00FF). Note that some of these
-- messages share the same message type ID for both the host request and the
-- device response. See the accompanying document for descriptions of settings
-- configurations and examples: https://github.com/swift-
-- nav/piksi\_firmware/blob/master/docs/settings.pdf

module SwiftNav.SBP.Settings where

import Control.Monad
import Control.Monad.Loops
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy hiding ( ByteString )
import Data.Int
import Data.Word

msgSettingsSave :: Word16
msgSettingsSave = 0x00A1

-- | SBP class for message MSG_SETTINGS_SAVE (0x00A1).
--
-- The save settings message persists the device's current settings
-- configuration to its onboard flash memory file system.
data MsgSettingsSave = MsgSettingsSave
  deriving ( Show, Read, Eq )

instance Binary MsgSettingsSave where
  get =
    return MsgSettingsSave

  put MsgSettingsSave =
    return ()

msgSettingsWrite :: Word16
msgSettingsWrite = 0x00A0

-- | SBP class for message MSG_SETTINGS_WRITE (0x00A0).
--
-- The setting message writes the device's configuration.
data MsgSettingsWrite = MsgSettingsWrite
  { msgSettingsWriteSetting :: ByteString
    -- ^ A NULL-terminated and delimited string with contents [SECTION_SETTING,
    -- SETTING, VALUE].
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsWrite where
  get = do
    msgSettingsWriteSetting <- liftM toStrict getRemainingLazyByteString
    return MsgSettingsWrite {..}

  put MsgSettingsWrite {..} = do
    putByteString msgSettingsWriteSetting

msgSettingsReadReq :: Word16
msgSettingsReadReq = 0x00A4

-- | SBP class for message MSG_SETTINGS_READ_REQ (0x00A4).
--
-- The setting message reads the device's configuration.
data MsgSettingsReadReq = MsgSettingsReadReq
  { msgSettingsReadReqSetting :: ByteString
    -- ^ A NULL-terminated and delimited string with contents [SECTION_SETTING,
    -- SETTING].
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadReq where
  get = do
    msgSettingsReadReqSetting <- liftM toStrict getRemainingLazyByteString
    return MsgSettingsReadReq {..}

  put MsgSettingsReadReq {..} = do
    putByteString msgSettingsReadReqSetting

msgSettingsReadResp :: Word16
msgSettingsReadResp = 0x00A5

-- | SBP class for message MSG_SETTINGS_READ_RESP (0x00A5).
--
-- The setting message reads the device's configuration.
data MsgSettingsReadResp = MsgSettingsReadResp
  { msgSettingsReadRespSetting :: ByteString
    -- ^ A NULL-terminated and delimited string with contents [SECTION_SETTING,
    -- SETTING, VALUE].
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadResp where
  get = do
    msgSettingsReadRespSetting <- liftM toStrict getRemainingLazyByteString
    return MsgSettingsReadResp {..}

  put MsgSettingsReadResp {..} = do
    putByteString msgSettingsReadRespSetting

msgSettingsReadByIndexReq :: Word16
msgSettingsReadByIndexReq = 0x00A2

-- | SBP class for message MSG_SETTINGS_READ_BY_INDEX_REQ (0x00A2).
--
-- The settings message for iterating through the settings values. It will read
-- the setting at an index, returning a NULL-terminated and delimited string
-- with contents [SECTION_SETTING, SETTING, VALUE].
data MsgSettingsReadByIndexReq = MsgSettingsReadByIndexReq
  { msgSettingsReadByIndexReqIndex :: Word16
    -- ^ An index into the device settings, with values ranging from 0 to
    -- length(settings)
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadByIndexReq where
  get = do
    msgSettingsReadByIndexReqIndex <- getWord16le
    return MsgSettingsReadByIndexReq {..}

  put MsgSettingsReadByIndexReq {..} = do
    putWord16le msgSettingsReadByIndexReqIndex

msgSettingsReadByIndexResp :: Word16
msgSettingsReadByIndexResp = 0x00A7

-- | SBP class for message MSG_SETTINGS_READ_BY_INDEX_RESP (0x00A7).
--
-- The settings message for iterating through the settings values. It will read
-- the setting at an index, returning a NULL-terminated and delimited string
-- with contents [SECTION_SETTING, SETTING, VALUE].
data MsgSettingsReadByIndexResp = MsgSettingsReadByIndexResp
  { msgSettingsReadByIndexRespIndex   :: Word16
    -- ^ An index into the device settings, with values ranging from 0 to
    -- length(settings)
  , msgSettingsReadByIndexRespSetting :: ByteString
    -- ^ A NULL-terminated and delimited string with contents [SECTION_SETTING,
    -- SETTING, VALUE].
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadByIndexResp where
  get = do
    msgSettingsReadByIndexRespIndex <- getWord16le
    msgSettingsReadByIndexRespSetting <- liftM toStrict getRemainingLazyByteString
    return MsgSettingsReadByIndexResp {..}

  put MsgSettingsReadByIndexResp {..} = do
    putWord16le msgSettingsReadByIndexRespIndex
    putByteString msgSettingsReadByIndexRespSetting

msgSettingsReadByIndexDone :: Word16
msgSettingsReadByIndexDone = 0x00A6

-- | SBP class for message MSG_SETTINGS_READ_BY_INDEX_DONE (0x00A6).
--
-- The settings message for indicating end of the settings values.
data MsgSettingsReadByIndexDone = MsgSettingsReadByIndexDone
  deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadByIndexDone where
  get =
    return MsgSettingsReadByIndexDone

  put MsgSettingsReadByIndexDone =
    return ()
