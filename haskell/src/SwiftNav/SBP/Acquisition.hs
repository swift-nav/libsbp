module SwiftNav.SBP.Acquisition where

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

msgAcqResult :: Word16
msgAcqResult = 0x0014

data MsgAcqResult = MsgAcqResult
  { msgAcqResultSnr :: Float
  , msgAcqResultCp  :: Float
  , msgAcqResultCf  :: Float
  , msgAcqResultSid :: Word32
  } deriving ( Show, Read, Eq )

instance Binary MsgAcqResult where
  get = do
    msgAcqResultSnr <- getFloat32le
    msgAcqResultCp <- getFloat32le
    msgAcqResultCf <- getFloat32le
    msgAcqResultSid <- getWord32le
    return MsgAcqResult {..}

  put MsgAcqResult {..} = do
    putFloat32le msgAcqResultSnr
    putFloat32le msgAcqResultCp
    putFloat32le msgAcqResultCf
    putWord32le msgAcqResultSid

msgAcqResultDepA :: Word16
msgAcqResultDepA = 0x0015

data MsgAcqResultDepA = MsgAcqResultDepA
  { msgAcqResultDepASnr :: Float
  , msgAcqResultDepACp  :: Float
  , msgAcqResultDepACf  :: Float
  , msgAcqResultDepAPrn :: Word8
  } deriving ( Show, Read, Eq )

instance Binary MsgAcqResultDepA where
  get = do
    msgAcqResultDepASnr <- getFloat32le
    msgAcqResultDepACp <- getFloat32le
    msgAcqResultDepACf <- getFloat32le
    msgAcqResultDepAPrn <- getWord8
    return MsgAcqResultDepA {..}

  put MsgAcqResultDepA {..} = do
    putFloat32le msgAcqResultDepASnr
    putFloat32le msgAcqResultDepACp
    putFloat32le msgAcqResultDepACf
    putWord8 msgAcqResultDepAPrn
