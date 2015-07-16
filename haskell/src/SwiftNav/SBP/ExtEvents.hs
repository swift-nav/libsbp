module SwiftNav.SBP.ExtEvents where

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
  get = do
    msgExtEventWn <- getWord16le
    msgExtEventTow <- getWord32le
    msgExtEventNs <- liftM fromIntegral getWord32le
    msgExtEventFlags <- getWord8
    msgExtEventPin <- getWord8
    return MsgExtEvent {..}

  put MsgExtEvent {..} = do
    putWord16le msgExtEventWn
    putWord32le msgExtEventTow
    putWord32le $ fromIntegral msgExtEventNs
    putWord8 msgExtEventFlags
    putWord8 msgExtEventPin
