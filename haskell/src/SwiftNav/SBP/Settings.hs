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

data MsgSettingsSave = MsgSettingsSave
  deriving ( Show, Read, Eq )

instance Binary MsgSettingsSave where
  get =
    return MsgSettingsSave

  put MsgSettingsSave =
    return ()

msgSettingsWrite :: Word16
msgSettingsWrite = 0x00A0

data MsgSettingsWrite = MsgSettingsWrite
  { msgSettingsWriteSetting :: ByteString
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsWrite where
  get = do
    msgSettingsWriteSetting <- liftM toStrict getRemainingLazyByteString
    return MsgSettingsWrite {..}

  put MsgSettingsWrite {..} = do
    putByteString msgSettingsWriteSetting

msgSettingsReadReq :: Word16
msgSettingsReadReq = 0x00A4

data MsgSettingsReadReq = MsgSettingsReadReq
  { msgSettingsReadReqSetting :: ByteString
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadReq where
  get = do
    msgSettingsReadReqSetting <- liftM toStrict getRemainingLazyByteString
    return MsgSettingsReadReq {..}

  put MsgSettingsReadReq {..} = do
    putByteString msgSettingsReadReqSetting

msgSettingsReadResp :: Word16
msgSettingsReadResp = 0x00A5

data MsgSettingsReadResp = MsgSettingsReadResp
  { msgSettingsReadRespSetting :: ByteString
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadResp where
  get = do
    msgSettingsReadRespSetting <- liftM toStrict getRemainingLazyByteString
    return MsgSettingsReadResp {..}

  put MsgSettingsReadResp {..} = do
    putByteString msgSettingsReadRespSetting

msgSettingsReadByIndexReq :: Word16
msgSettingsReadByIndexReq = 0x00A2

data MsgSettingsReadByIndexReq = MsgSettingsReadByIndexReq
  { msgSettingsReadByIndexReqIndex :: Word16
  } deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadByIndexReq where
  get = do
    msgSettingsReadByIndexReqIndex <- getWord16le
    return MsgSettingsReadByIndexReq {..}

  put MsgSettingsReadByIndexReq {..} = do
    putWord16le msgSettingsReadByIndexReqIndex

msgSettingsReadByIndexResp :: Word16
msgSettingsReadByIndexResp = 0x00A7

data MsgSettingsReadByIndexResp = MsgSettingsReadByIndexResp
  { msgSettingsReadByIndexRespIndex   :: Word16
  , msgSettingsReadByIndexRespSetting :: ByteString
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

data MsgSettingsReadByIndexDone = MsgSettingsReadByIndexDone
  deriving ( Show, Read, Eq )

instance Binary MsgSettingsReadByIndexDone where
  get =
    return MsgSettingsReadByIndexDone

  put MsgSettingsReadByIndexDone =
    return ()
