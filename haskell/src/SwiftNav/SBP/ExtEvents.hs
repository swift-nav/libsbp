-- |
-- Module:      SwiftNav.SBP.ExtEvents
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Messages reporting accurately-timestamped external events, e.g. camera
-- shutter time.

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

-- | SBP class for message MSG_EXT_EVENT (0x0101).
--
-- Reports detection of an external event, the GPS time it occurred, which pin
-- it was and whether it was rising or falling.
data MsgExtEvent = MsgExtEvent
  { msgExtEventWn    :: Word16
    -- ^ GPS week number
  , msgExtEventTow   :: Word32
    -- ^ GPS time of week rounded to the nearest millisecond
  , msgExtEventNs    :: Int32
    -- ^ Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    -- 500000)
  , msgExtEventFlags :: Word8
    -- ^ Flags
  , msgExtEventPin   :: Word8
    -- ^ Pin number.  0..9 = DEBUG0..9.
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
