module SwiftNav.SBP.Bootload where

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

msgBootloaderHandshakeReq :: Word16
msgBootloaderHandshakeReq = 0x00B3

data MsgBootloaderHandshakeReq = MsgBootloaderHandshakeReq
  deriving ( Show, Read, Eq )

instance Binary MsgBootloaderHandshakeReq where
  get =
    return MsgBootloaderHandshakeReq

  put MsgBootloaderHandshakeReq =
    return ()

msgBootloaderHandshakeResp :: Word16
msgBootloaderHandshakeResp = 0x00B4

data MsgBootloaderHandshakeResp = MsgBootloaderHandshakeResp
  { msgBootloaderHandshakeRespFlags   :: Word32
  , msgBootloaderHandshakeRespVersion :: ByteString
  } deriving ( Show, Read, Eq )

instance Binary MsgBootloaderHandshakeResp where
  get = do
    msgBootloaderHandshakeRespFlags <- getWord32le
    msgBootloaderHandshakeRespVersion <- liftM toStrict getRemainingLazyByteString
    return MsgBootloaderHandshakeResp {..}

  put MsgBootloaderHandshakeResp {..} = do
    putWord32le msgBootloaderHandshakeRespFlags
    putByteString msgBootloaderHandshakeRespVersion

msgBootloaderJumpToApp :: Word16
msgBootloaderJumpToApp = 0x00B1

data MsgBootloaderJumpToApp = MsgBootloaderJumpToApp
  { msgBootloaderJumpToAppJump :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgBootloaderJumpToApp where
  get = do
    msgBootloaderJumpToAppJump <- getWord8
    return MsgBootloaderJumpToApp {..}

  put MsgBootloaderJumpToApp {..} = do
    putWord8 msgBootloaderJumpToAppJump

msgNapDeviceDnaReq :: Word16
msgNapDeviceDnaReq = 0x00DE

data MsgNapDeviceDnaReq = MsgNapDeviceDnaReq
  deriving ( Show, Read, Eq )

instance Binary MsgNapDeviceDnaReq where
  get =
    return MsgNapDeviceDnaReq

  put MsgNapDeviceDnaReq =
    return ()

msgNapDeviceDnaResp :: Word16
msgNapDeviceDnaResp = 0x00DD

data MsgNapDeviceDnaResp = MsgNapDeviceDnaResp
  { msgNapDeviceDnaRespDna :: [Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgNapDeviceDnaResp where
  get = do
    msgNapDeviceDnaRespDna <- replicateM 8 getWord8
    return MsgNapDeviceDnaResp {..}

  put MsgNapDeviceDnaResp {..} = do
    put msgNapDeviceDnaRespDna

msgBootloaderHandshakeDepA :: Word16
msgBootloaderHandshakeDepA = 0x00B0

data MsgBootloaderHandshakeDepA = MsgBootloaderHandshakeDepA
  { msgBootloaderHandshakeDepAHandshake :: [Word8]
  } deriving ( Show, Read, Eq )

instance Binary MsgBootloaderHandshakeDepA where
  get = do
    msgBootloaderHandshakeDepAHandshake <- whileM (liftM not isEmpty) getWord8
    return MsgBootloaderHandshakeDepA {..}

  put MsgBootloaderHandshakeDepA {..} = do
    put msgBootloaderHandshakeDepAHandshake
