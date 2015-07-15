module SwiftNav.SBP.Bootload where

import Data.Binary
import Data.Int
import Data.Text
import Data.Word

msgBootloaderHandshakeReq :: Word16
msgBootloaderHandshakeReq = 0x00B3

data MsgBootloaderHandshakeReq = MsgBootloaderHandshakeReq
  deriving ( Show, Read, Eq )

instance Binary MsgBootloaderHandshakeReq where
  get =
    undefined
  put MsgBootloaderHandshakeReq {..} =
    undefined

msgBootloaderHandshakeResp :: Word16
msgBootloaderHandshakeResp = 0x00B4

data MsgBootloaderHandshakeResp = MsgBootloaderHandshakeResp
  { msgBootloaderHandshakeRespFlags   :: Word32
  , msgBootloaderHandshakeRespVersion :: Text
  } deriving ( Show, Read, Eq )

instance Binary MsgBootloaderHandshakeResp where
  get =
    undefined
  put MsgBootloaderHandshakeResp {..} =
    undefined

msgBootloaderJumpToApp :: Word16
msgBootloaderJumpToApp = 0x00B1

data MsgBootloaderJumpToApp = MsgBootloaderJumpToApp
  { msgBootloaderJumpToAppJump :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgBootloaderJumpToApp where
  get =
    undefined
  put MsgBootloaderJumpToApp {..} =
    undefined

msgNapDeviceDnaReq :: Word16
msgNapDeviceDnaReq = 0x00DE

data MsgNapDeviceDnaReq = MsgNapDeviceDnaReq
  deriving ( Show, Read, Eq )

instance Binary MsgNapDeviceDnaReq where
  get =
    undefined
  put MsgNapDeviceDnaReq {..} =
    undefined

msgNapDeviceDnaResp :: Word16
msgNapDeviceDnaResp = 0x00DD

data MsgNapDeviceDnaResp = MsgNapDeviceDnaResp
  { msgNapDeviceDnaRespDna :: [Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgNapDeviceDnaResp where
  get =
    undefined
  put MsgNapDeviceDnaResp {..} =
    undefined

msgBootloaderHandshakeDepA :: Word16
msgBootloaderHandshakeDepA = 0x00B0

data MsgBootloaderHandshakeDepA = MsgBootloaderHandshakeDepA
  { msgBootloaderHandshakeDepAHandshake :: [Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgBootloaderHandshakeDepA where
  get =
    undefined
  put MsgBootloaderHandshakeDepA {..} =
    undefined
