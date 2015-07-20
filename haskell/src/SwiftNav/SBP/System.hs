module SwiftNav.SBP.System where

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

msgStartup :: Word16
msgStartup = 0xFF00

data MsgStartup = MsgStartup
  { msgStartupReserved :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgStartup where
  get = do
    msgStartupReserved <- getWord32le
    return MsgStartup {..}

  put MsgStartup {..} = do
    putWord32le msgStartupReserved

msgHeartbeat :: Word16
msgHeartbeat = 0xFFFF

data MsgHeartbeat = MsgHeartbeat
  { msgHeartbeatFlags :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgHeartbeat where
  get = do
    msgHeartbeatFlags <- getWord32le
    return MsgHeartbeat {..}

  put MsgHeartbeat {..} = do
    putWord32le msgHeartbeatFlags
