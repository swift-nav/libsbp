{-# OPTIONS_GHC -fno-warn-unused-imports #-}
-- |
-- Module:      SwiftNav.SBP.Settings
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Messages for reading and writing the device's device settings.  Note that
-- some of these messages share the same message type ID for both the host
-- request and the device response. See the accompanying document for
-- descriptions of settings configurations and examples:  https://github.com
-- /swift-nav/piksi\_firmware/blob/master/docs/settings.pdf

module SwiftNav.SBP.Settings where

import BasicPrelude
import Control.Lens
import Control.Monad.Loops
import Data.Aeson.TH           (defaultOptions, deriveJSON, fieldLabelModifier)
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy    hiding (ByteString)
import Data.Int
import Data.Word
import SwiftNav.SBP.Encoding
import SwiftNav.SBP.TH
import SwiftNav.SBP.Types

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

$(deriveSBP 'msgSettingsSave ''MsgSettingsSave)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgSettingsSave_" . stripPrefix "_msgSettingsSave_"}
             ''MsgSettingsSave)
$(makeLenses ''MsgSettingsSave)

msgSettingsWrite :: Word16
msgSettingsWrite = 0x00A0

-- | SBP class for message MSG_SETTINGS_WRITE (0x00A0).
--
-- The setting message writes the device configuration.
data MsgSettingsWrite = MsgSettingsWrite
  { _msgSettingsWrite_setting :: ByteString
    -- ^ A NULL-terminated and delimited string with contents [SECTION_SETTING,
    -- SETTING, VALUE]. A device will only process to this message when it is
    -- received from sender ID 0x42.
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsWrite where
  get = do
    _msgSettingsWrite_setting <- liftM toStrict getRemainingLazyByteString
    return MsgSettingsWrite {..}

  put MsgSettingsWrite {..} = do
    putByteString _msgSettingsWrite_setting

$(deriveSBP 'msgSettingsWrite ''MsgSettingsWrite)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgSettingsWrite_" . stripPrefix "_msgSettingsWrite_"}
             ''MsgSettingsWrite)
$(makeLenses ''MsgSettingsWrite)

msgSettingsReadReq :: Word16
msgSettingsReadReq = 0x00A4

-- | SBP class for message MSG_SETTINGS_READ_REQ (0x00A4).
--
-- The setting message reads the device configuration.
data MsgSettingsReadReq = MsgSettingsReadReq
  { _msgSettingsReadReq_setting :: ByteString
    -- ^ A NULL-terminated and delimited string with contents [SECTION_SETTING,
    -- SETTING]. A device will only respond to this message when it is received
    -- from sender ID 0x42.
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadReq where
  get = do
    _msgSettingsReadReq_setting <- liftM toStrict getRemainingLazyByteString
    return MsgSettingsReadReq {..}

  put MsgSettingsReadReq {..} = do
    putByteString _msgSettingsReadReq_setting

$(deriveSBP 'msgSettingsReadReq ''MsgSettingsReadReq)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgSettingsReadReq_" . stripPrefix "_msgSettingsReadReq_"}
             ''MsgSettingsReadReq)
$(makeLenses ''MsgSettingsReadReq)

msgSettingsReadResp :: Word16
msgSettingsReadResp = 0x00A5

-- | SBP class for message MSG_SETTINGS_READ_RESP (0x00A5).
--
-- The setting message reads the device configuration.
data MsgSettingsReadResp = MsgSettingsReadResp
  { _msgSettingsReadResp_setting :: ByteString
    -- ^ A NULL-terminated and delimited string with contents [SECTION_SETTING,
    -- SETTING, VALUE].
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadResp where
  get = do
    _msgSettingsReadResp_setting <- liftM toStrict getRemainingLazyByteString
    return MsgSettingsReadResp {..}

  put MsgSettingsReadResp {..} = do
    putByteString _msgSettingsReadResp_setting

$(deriveSBP 'msgSettingsReadResp ''MsgSettingsReadResp)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgSettingsReadResp_" . stripPrefix "_msgSettingsReadResp_"}
             ''MsgSettingsReadResp)
$(makeLenses ''MsgSettingsReadResp)

msgSettingsReadByIndexReq :: Word16
msgSettingsReadByIndexReq = 0x00A2

-- | SBP class for message MSG_SETTINGS_READ_BY_INDEX_REQ (0x00A2).
--
-- The settings message for iterating through the settings values. It will read
-- the setting at an index, returning a NULL-terminated and delimited string
-- with contents [SECTION_SETTING, SETTING, VALUE]. A device will only respond
-- to this message when it is received from sender ID 0x42.
data MsgSettingsReadByIndexReq = MsgSettingsReadByIndexReq
  { _msgSettingsReadByIndexReq_index :: Word16
    -- ^ An index into the device settings, with values ranging from 0 to
    -- length(settings)
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadByIndexReq where
  get = do
    _msgSettingsReadByIndexReq_index <- getWord16le
    return MsgSettingsReadByIndexReq {..}

  put MsgSettingsReadByIndexReq {..} = do
    putWord16le _msgSettingsReadByIndexReq_index

$(deriveSBP 'msgSettingsReadByIndexReq ''MsgSettingsReadByIndexReq)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgSettingsReadByIndexReq_" . stripPrefix "_msgSettingsReadByIndexReq_"}
             ''MsgSettingsReadByIndexReq)
$(makeLenses ''MsgSettingsReadByIndexReq)

msgSettingsReadByIndexResp :: Word16
msgSettingsReadByIndexResp = 0x00A7

-- | SBP class for message MSG_SETTINGS_READ_BY_INDEX_RESP (0x00A7).
--
-- The settings message for iterating through the settings values. It will read
-- the setting at an index, returning a NULL-terminated and delimited string
-- with contents [SECTION_SETTING, SETTING, VALUE].
data MsgSettingsReadByIndexResp = MsgSettingsReadByIndexResp
  { _msgSettingsReadByIndexResp_index :: Word16
    -- ^ An index into the device settings, with values ranging from 0 to
    -- length(settings)
  , _msgSettingsReadByIndexResp_setting :: ByteString
    -- ^ A NULL-terminated and delimited string with contents [SECTION_SETTING,
    -- SETTING, VALUE].
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadByIndexResp where
  get = do
    _msgSettingsReadByIndexResp_index <- getWord16le
    _msgSettingsReadByIndexResp_setting <- liftM toStrict getRemainingLazyByteString
    return MsgSettingsReadByIndexResp {..}

  put MsgSettingsReadByIndexResp {..} = do
    putWord16le _msgSettingsReadByIndexResp_index
    putByteString _msgSettingsReadByIndexResp_setting

$(deriveSBP 'msgSettingsReadByIndexResp ''MsgSettingsReadByIndexResp)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgSettingsReadByIndexResp_" . stripPrefix "_msgSettingsReadByIndexResp_"}
             ''MsgSettingsReadByIndexResp)
$(makeLenses ''MsgSettingsReadByIndexResp)

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

$(deriveSBP 'msgSettingsReadByIndexDone ''MsgSettingsReadByIndexDone)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgSettingsReadByIndexDone_" . stripPrefix "_msgSettingsReadByIndexDone_"}
             ''MsgSettingsReadByIndexDone)
$(makeLenses ''MsgSettingsReadByIndexDone)

msgSettingsRegister :: Word16
msgSettingsRegister = 0x00AE

-- | SBP class for message MSG_SETTINGS_REGISTER (0x00AE).
--
-- This message registers the presence and default value of a setting with a
-- settings daemon.  The host should reply with MSG_SETTINGS_WRITE for this
-- setting to set the initial value.
data MsgSettingsRegister = MsgSettingsRegister
  { _msgSettingsRegister_setting :: ByteString
    -- ^ A NULL-terminated and delimited string with contents [SECTION_SETTING,
    -- SETTING, VALUE].
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsRegister where
  get = do
    _msgSettingsRegister_setting <- liftM toStrict getRemainingLazyByteString
    return MsgSettingsRegister {..}

  put MsgSettingsRegister {..} = do
    putByteString _msgSettingsRegister_setting

$(deriveSBP 'msgSettingsRegister ''MsgSettingsRegister)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgSettingsRegister_" . stripPrefix "_msgSettingsRegister_"}
             ''MsgSettingsRegister)
$(makeLenses ''MsgSettingsRegister)
