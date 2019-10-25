{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Settings
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- \< Messages for reading, writing, and discovering device settings. Settings
-- with a "string" field have multiple values in this field delimited with a
-- null character (the c style null terminator).  For instance, when querying
-- the 'firmware_version' setting in the 'system_info' section, the following
-- array of characters needs to be sent for the string field in
-- MSG_SETTINGS_READ: "system_info\0firmware_version\0", where the delimiting
-- null characters are specified with the escape sequence '\0' and all
-- quotation marks should be omitted.    In the message descriptions below, the
-- generic strings SECTION_SETTING and SETTING are used to refer to the two
-- strings that comprise the identifier of an individual setting.In
-- firmware_version example above, SECTION_SETTING is the 'system_info', and
-- the SETTING portion is 'firmware_version'.   See the "Software Settings
-- Manual" on support.swiftnav.com for detailed documentation about all
-- settings and sections available for each Swift firmware version. Settings
-- manuals are available for each firmware version at the following link:
-- https://support.swiftnav.com/customer/en/portal/articles/2628580-piksi-
-- multi-specifications#settings. The latest settings document is also
-- available at the following link:  http://swiftnav.com/latest/piksi-multi-
-- settings . See lastly https://github.com/swift-
-- nav/piksi_tools/blob/master/piksi_tools/settings.py ,  the open source
-- python command line utility for reading, writing, and saving settings in the
-- piksi_tools repository on github as a helpful reference and example. \>

module SwiftNav.SBP.Settings
  ( module SwiftNav.SBP.Settings
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
    pure MsgSettingsSave

  put MsgSettingsSave =
    pure ()
$(makeSBP 'msgSettingsSave ''MsgSettingsSave)
$(makeJSON "_msgSettingsSave_" ''MsgSettingsSave)
$(makeLenses ''MsgSettingsSave)

msgSettingsWrite :: Word16
msgSettingsWrite = 0x00A0

-- | SBP class for message MSG_SETTINGS_WRITE (0x00A0).
--
-- The setting message writes the device configuration for a particular setting
-- via A NULL-terminated and NULL-delimited string with contents
-- "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes
-- the NULL character and where quotation marks are omitted. A device will only
-- process to this message when it is received from sender ID 0x42. An example
-- string that could be sent to a device is "solution\0soln_freq\010\0".
data MsgSettingsWrite = MsgSettingsWrite
  { _msgSettingsWrite_setting :: !Text
    -- ^ A NULL-terminated and NULL-delimited string with contents
    -- "SECTION_SETTING\0SETTING\0VALUE\0"
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsWrite where
  get = do
    _msgSettingsWrite_setting <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgSettingsWrite {..}

  put MsgSettingsWrite {..} = do
    putByteString $ encodeUtf8 _msgSettingsWrite_setting

$(makeSBP 'msgSettingsWrite ''MsgSettingsWrite)
$(makeJSON "_msgSettingsWrite_" ''MsgSettingsWrite)
$(makeLenses ''MsgSettingsWrite)

msgSettingsWriteResp :: Word16
msgSettingsWriteResp = 0x00AF

-- | SBP class for message MSG_SETTINGS_WRITE_RESP (0x00AF).
--
-- Return the status of a write request with the new value of the setting.  If
-- the requested value is rejected, the current value will be returned. The
-- string field is a NULL-terminated and NULL-delimited string with contents
-- "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes
-- the NULL character and where quotation marks are omitted. An example string
-- that could be sent from device is "solution\0soln_freq\010\0".
data MsgSettingsWriteResp = MsgSettingsWriteResp
  { _msgSettingsWriteResp_status :: !Word8
    -- ^ Write status
  , _msgSettingsWriteResp_setting :: !Text
    -- ^ A NULL-terminated and delimited string with contents
    -- "SECTION_SETTING\0SETTING\0VALUE\0"
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsWriteResp where
  get = do
    _msgSettingsWriteResp_status <- getWord8
    _msgSettingsWriteResp_setting <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgSettingsWriteResp {..}

  put MsgSettingsWriteResp {..} = do
    putWord8 _msgSettingsWriteResp_status
    putByteString $ encodeUtf8 _msgSettingsWriteResp_setting

$(makeSBP 'msgSettingsWriteResp ''MsgSettingsWriteResp)
$(makeJSON "_msgSettingsWriteResp_" ''MsgSettingsWriteResp)
$(makeLenses ''MsgSettingsWriteResp)

msgSettingsReadReq :: Word16
msgSettingsReadReq = 0x00A4

-- | SBP class for message MSG_SETTINGS_READ_REQ (0x00A4).
--
-- The setting message that reads the device configuration. The string field is
-- a NULL-terminated and NULL-delimited string with contents
-- "SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the NULL
-- character and where quotation marks are omitted. An example string that
-- could be sent to a device is "solution\0soln_freq\0". A device will only
-- respond to this message when it is received from sender ID 0x42. A device
-- should respond with a MSG_SETTINGS_READ_RESP message (msg_id 0x00A5).
data MsgSettingsReadReq = MsgSettingsReadReq
  { _msgSettingsReadReq_setting :: !Text
    -- ^ A NULL-terminated and NULL-delimited string with contents
    -- "SECTION_SETTING\0SETTING\0"
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadReq where
  get = do
    _msgSettingsReadReq_setting <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgSettingsReadReq {..}

  put MsgSettingsReadReq {..} = do
    putByteString $ encodeUtf8 _msgSettingsReadReq_setting

$(makeSBP 'msgSettingsReadReq ''MsgSettingsReadReq)
$(makeJSON "_msgSettingsReadReq_" ''MsgSettingsReadReq)
$(makeLenses ''MsgSettingsReadReq)

msgSettingsReadResp :: Word16
msgSettingsReadResp = 0x00A5

-- | SBP class for message MSG_SETTINGS_READ_RESP (0x00A5).
--
-- The setting message wich which the device responds after a
-- MSG_SETTING_READ_REQ is sent to device. The string field is a NULL-
-- terminated and NULL-delimited string with contents
-- "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes
-- the NULL character and where quotation marks are omitted. An example string
-- that could be sent from device is "solution\0soln_freq\010\0".
data MsgSettingsReadResp = MsgSettingsReadResp
  { _msgSettingsReadResp_setting :: !Text
    -- ^ A NULL-terminated and NULL-delimited string with contents
    -- "SECTION_SETTING\0SETTING\0VALUE\0"
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadResp where
  get = do
    _msgSettingsReadResp_setting <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgSettingsReadResp {..}

  put MsgSettingsReadResp {..} = do
    putByteString $ encodeUtf8 _msgSettingsReadResp_setting

$(makeSBP 'msgSettingsReadResp ''MsgSettingsReadResp)
$(makeJSON "_msgSettingsReadResp_" ''MsgSettingsReadResp)
$(makeLenses ''MsgSettingsReadResp)

msgSettingsReadByIndexReq :: Word16
msgSettingsReadByIndexReq = 0x00A2

-- | SBP class for message MSG_SETTINGS_READ_BY_INDEX_REQ (0x00A2).
--
-- The settings message for iterating through the settings values. A device
-- will respond to this message with a  "MSG_SETTINGS_READ_BY_INDEX_RESP".
data MsgSettingsReadByIndexReq = MsgSettingsReadByIndexReq
  { _msgSettingsReadByIndexReq_index :: !Word16
    -- ^ An index into the device settings, with values ranging from 0 to
    -- length(settings)
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadByIndexReq where
  get = do
    _msgSettingsReadByIndexReq_index <- getWord16le
    pure MsgSettingsReadByIndexReq {..}

  put MsgSettingsReadByIndexReq {..} = do
    putWord16le _msgSettingsReadByIndexReq_index

$(makeSBP 'msgSettingsReadByIndexReq ''MsgSettingsReadByIndexReq)
$(makeJSON "_msgSettingsReadByIndexReq_" ''MsgSettingsReadByIndexReq)
$(makeLenses ''MsgSettingsReadByIndexReq)

msgSettingsReadByIndexResp :: Word16
msgSettingsReadByIndexResp = 0x00A7

-- | SBP class for message MSG_SETTINGS_READ_BY_INDEX_RESP (0x00A7).
--
-- The settings message that reports the value of a setting at an index.  In
-- the string field, it reports NULL-terminated and delimited string with
-- contents "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where the '\0'
-- escape sequence denotes the NULL character and where quotation marks are
-- omitted. The FORMAT_TYPE field is optional and denotes possible string
-- values of the setting as a hint to the user. If included, the format type
-- portion of the string has the format "enum:value1,value2,value3". An example
-- string that could be sent from the device is
-- "simulator\0enabled\0True\0enum:True,False\0"
data MsgSettingsReadByIndexResp = MsgSettingsReadByIndexResp
  { _msgSettingsReadByIndexResp_index :: !Word16
    -- ^ An index into the device settings, with values ranging from 0 to
    -- length(settings)
  , _msgSettingsReadByIndexResp_setting :: !Text
    -- ^ A NULL-terminated and delimited string with contents
    -- "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadByIndexResp where
  get = do
    _msgSettingsReadByIndexResp_index <- getWord16le
    _msgSettingsReadByIndexResp_setting <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgSettingsReadByIndexResp {..}

  put MsgSettingsReadByIndexResp {..} = do
    putWord16le _msgSettingsReadByIndexResp_index
    putByteString $ encodeUtf8 _msgSettingsReadByIndexResp_setting

$(makeSBP 'msgSettingsReadByIndexResp ''MsgSettingsReadByIndexResp)
$(makeJSON "_msgSettingsReadByIndexResp_" ''MsgSettingsReadByIndexResp)
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
    pure MsgSettingsReadByIndexDone

  put MsgSettingsReadByIndexDone =
    pure ()
$(makeSBP 'msgSettingsReadByIndexDone ''MsgSettingsReadByIndexDone)
$(makeJSON "_msgSettingsReadByIndexDone_" ''MsgSettingsReadByIndexDone)
$(makeLenses ''MsgSettingsReadByIndexDone)

msgSettingsRegister :: Word16
msgSettingsRegister = 0x00AE

-- | SBP class for message MSG_SETTINGS_REGISTER (0x00AE).
--
-- This message registers the presence and default value of a setting with a
-- settings daemon.  The host should reply with MSG_SETTINGS_WRITE for this
-- setting to set the initial value.
data MsgSettingsRegister = MsgSettingsRegister
  { _msgSettingsRegister_setting :: !Text
    -- ^ A NULL-terminated and delimited string with contents
    -- "SECTION_SETTING\0SETTING\0VALUE".
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsRegister where
  get = do
    _msgSettingsRegister_setting <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgSettingsRegister {..}

  put MsgSettingsRegister {..} = do
    putByteString $ encodeUtf8 _msgSettingsRegister_setting

$(makeSBP 'msgSettingsRegister ''MsgSettingsRegister)
$(makeJSON "_msgSettingsRegister_" ''MsgSettingsRegister)
$(makeLenses ''MsgSettingsRegister)

msgSettingsRegisterResp :: Word16
msgSettingsRegisterResp = 0x01AF

-- | SBP class for message MSG_SETTINGS_REGISTER_RESP (0x01AF).
--
-- This message responds to setting registration with the effective value. The
-- effective value shall differ from the given default value if setting was
-- already registered or is available in the permanent setting storage and had
-- a different value.
data MsgSettingsRegisterResp = MsgSettingsRegisterResp
  { _msgSettingsRegisterResp_status :: !Word8
    -- ^ Register status
  , _msgSettingsRegisterResp_setting :: !Text
    -- ^ A NULL-terminated and delimited string with contents
    -- "SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
    -- according to the status field.
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsRegisterResp where
  get = do
    _msgSettingsRegisterResp_status <- getWord8
    _msgSettingsRegisterResp_setting <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgSettingsRegisterResp {..}

  put MsgSettingsRegisterResp {..} = do
    putWord8 _msgSettingsRegisterResp_status
    putByteString $ encodeUtf8 _msgSettingsRegisterResp_setting

$(makeSBP 'msgSettingsRegisterResp ''MsgSettingsRegisterResp)
$(makeJSON "_msgSettingsRegisterResp_" ''MsgSettingsRegisterResp)
$(makeLenses ''MsgSettingsRegisterResp)
