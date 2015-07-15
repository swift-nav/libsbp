module SwiftNav.SBP.System where

import Data.Binary
import Data.Int
import Data.Text
import Data.Word

msgStartup :: Word16
msgStartup = 0xFF00

data MsgStartup = MsgStartup
  { msgStartupReserved :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgStartup where
  get =
    undefined
  put MsgStartup {..} =
    undefined

msgHeartbeat :: Word16
msgHeartbeat = 0xFFFF

data MsgHeartbeat = MsgHeartbeat
  { msgHeartbeatFlags :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgHeartbeat where
  get =
    undefined
  put MsgHeartbeat {..} =
    undefined
