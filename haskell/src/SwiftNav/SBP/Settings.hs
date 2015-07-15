module SwiftNav.SBP.Settings where

import Data.Int
import Data.Text
import Data.Word


msgSettingsSave :: Word16
msgSettingsSave = 0x00A1
data MsgSettingsSave = MsgSettingsSave
  deriving ( Show, Read, Eq )

msgSettingsWrite :: Word16
msgSettingsWrite = 0x00A0
data MsgSettingsWrite = MsgSettingsWrite
  { msgSettingsWriteSetting :: Text
  } deriving ( Show, Read, Eq )

msgSettingsReadReq :: Word16
msgSettingsReadReq = 0x00A4
data MsgSettingsReadReq = MsgSettingsReadReq
  { msgSettingsReadReqSetting :: Text
  } deriving ( Show, Read, Eq )

msgSettingsReadResp :: Word16
msgSettingsReadResp = 0x00A5
data MsgSettingsReadResp = MsgSettingsReadResp
  { msgSettingsReadRespSetting :: Text
  } deriving ( Show, Read, Eq )

msgSettingsReadByIndexReq :: Word16
msgSettingsReadByIndexReq = 0x00A2
data MsgSettingsReadByIndexReq = MsgSettingsReadByIndexReq
  { msgSettingsReadByIndexReqIndex :: Word16
  } deriving ( Show, Read, Eq )

msgSettingsReadByIndexResp :: Word16
msgSettingsReadByIndexResp = 0x00A7
data MsgSettingsReadByIndexResp = MsgSettingsReadByIndexResp
  { msgSettingsReadByIndexRespIndex   :: Word16
  , msgSettingsReadByIndexRespSetting :: Text
  } deriving ( Show, Read, Eq )

msgSettingsReadByIndexDone :: Word16
msgSettingsReadByIndexDone = 0x00A6
data MsgSettingsReadByIndexDone = MsgSettingsReadByIndexDone
  deriving ( Show, Read, Eq )
