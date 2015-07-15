module SwiftNav.SBP.Bootload where

import Data.Int
import Data.Text
import Data.Word


msgBootloaderHandshakeReq :: Word16
msgBootloaderHandshakeReq = 0x00B3
data MsgBootloaderHandshakeReq = MsgBootloaderHandshakeReq
  deriving ( Show, Read, Eq )

msgBootloaderHandshakeResp :: Word16
msgBootloaderHandshakeResp = 0x00B4
data MsgBootloaderHandshakeResp = MsgBootloaderHandshakeResp
  { msgBootloaderHandshakeRespFlags   :: Word32
  , msgBootloaderHandshakeRespVersion :: Text
  } deriving ( Show, Read, Eq )

msgBootloaderJumpToApp :: Word16
msgBootloaderJumpToApp = 0x00B1
data MsgBootloaderJumpToApp = MsgBootloaderJumpToApp
  { msgBootloaderJumpToAppJump :: Word8
  } deriving ( Show, Read, Eq )

msgNapDeviceDnaReq :: Word16
msgNapDeviceDnaReq = 0x00DE
data MsgNapDeviceDnaReq = MsgNapDeviceDnaReq
  deriving ( Show, Read, Eq )

msgNapDeviceDnaResp :: Word16
msgNapDeviceDnaResp = 0x00DD
data MsgNapDeviceDnaResp = MsgNapDeviceDnaResp
  { msgNapDeviceDnaRespDna :: [Word8]
  } deriving ( Show, Read, Eq )

msgBootloaderHandshakeDepA :: Word16
msgBootloaderHandshakeDepA = 0x00B0
data MsgBootloaderHandshakeDepA = MsgBootloaderHandshakeDepA
  { msgBootloaderHandshakeDepAHandshake :: [Word8]
  } deriving ( Show, Read, Eq )
