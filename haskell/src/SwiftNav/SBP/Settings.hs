module SwiftNav.SBP.Settings where

import Data.Binary
import Data.Int
import Data.Text
import Data.Word

msgSettingsSave :: Word16
msgSettingsSave = 0x00A1

data MsgSettingsSave = MsgSettingsSave
  deriving ( Show, Read, Eq )

instance Binary MsgSettingsSave where
  get =
    undefined
  put MsgSettingsSave {..} =
    undefined

msgSettingsWrite :: Word16
msgSettingsWrite = 0x00A0

data MsgSettingsWrite = MsgSettingsWrite
  { msgSettingsWriteSetting :: Text
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsWrite where
  get =
    undefined
  put MsgSettingsWrite {..} =
    undefined

msgSettingsReadReq :: Word16
msgSettingsReadReq = 0x00A4

data MsgSettingsReadReq = MsgSettingsReadReq
  { msgSettingsReadReqSetting :: Text
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadReq where
  get =
    undefined
  put MsgSettingsReadReq {..} =
    undefined

msgSettingsReadResp :: Word16
msgSettingsReadResp = 0x00A5

data MsgSettingsReadResp = MsgSettingsReadResp
  { msgSettingsReadRespSetting :: Text
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadResp where
  get =
    undefined
  put MsgSettingsReadResp {..} =
    undefined

msgSettingsReadByIndexReq :: Word16
msgSettingsReadByIndexReq = 0x00A2

data MsgSettingsReadByIndexReq = MsgSettingsReadByIndexReq
  { msgSettingsReadByIndexReqIndex :: Word16
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadByIndexReq where
  get =
    undefined
  put MsgSettingsReadByIndexReq {..} =
    undefined

msgSettingsReadByIndexResp :: Word16
msgSettingsReadByIndexResp = 0x00A7

data MsgSettingsReadByIndexResp = MsgSettingsReadByIndexResp
  { msgSettingsReadByIndexRespIndex   :: Word16
  , msgSettingsReadByIndexRespSetting :: Text
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadByIndexResp where
  get =
    undefined
  put MsgSettingsReadByIndexResp {..} =
    undefined

msgSettingsReadByIndexDone :: Word16
msgSettingsReadByIndexDone = 0x00A6

data MsgSettingsReadByIndexDone = MsgSettingsReadByIndexDone
  deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadByIndexDone where
  get =
    undefined
  put MsgSettingsReadByIndexDone {..} =
    undefined
