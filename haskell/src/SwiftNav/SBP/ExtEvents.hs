module SwiftNav.SBP.ExtEvents where

import Data.Binary
import Data.Int
import Data.Text
import Data.Word

msgExtEvent :: Word16
msgExtEvent = 0x0101

data MsgExtEvent = MsgExtEvent
  { msgExtEventWn    :: Word16
  , msgExtEventTow   :: Word32
  , msgExtEventNs    :: Int32
  , msgExtEventFlags :: Word8
  , msgExtEventPin   :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgExtEvent where
  get =
    undefined
  put MsgExtEvent {..} =
    undefined
