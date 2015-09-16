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

import BasicPrelude
import Control.Monad.Loops
import Data.Aeson.TH (deriveJSON, defaultOptions, fieldLabelModifier)
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy hiding ( ByteString )
import Data.Int
import Data.Word
import SwiftNav.SBP.Encoding

msgExtEvent :: Word16
msgExtEvent = 0x0101

-- | SBP class for message MSG_EXT_EVENT (0x0101).
--
-- Reports detection of an external event, the GPS time it occurred, which pin
-- it was and whether it was rising or falling.
data MsgExtEvent = MsgExtEvent
  { msgExtEvent_wn   :: Word16
    -- ^ GPS week number
  , msgExtEvent_tow  :: Word32
    -- ^ GPS time of week rounded to the nearest millisecond
  , msgExtEvent_ns   :: Int32
    -- ^ Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    -- 500000)
  , msgExtEvent_flags :: Word8
    -- ^ Flags
  , msgExtEvent_pin  :: Word8
    -- ^ Pin number.  0..9 = DEBUG0..9.
  } deriving ( Show, Read, Eq )

instance Binary MsgExtEvent where
  get = do
    msgExtEvent_wn <- getWord16le
    msgExtEvent_tow <- getWord32le
    msgExtEvent_ns <- liftM fromIntegral getWord32le
    msgExtEvent_flags <- getWord8
    msgExtEvent_pin <- getWord8
    return MsgExtEvent {..}

  put MsgExtEvent {..} = do
    putWord16le msgExtEvent_wn
    putWord32le msgExtEvent_tow
    putWord32le $ fromIntegral msgExtEvent_ns
    putWord8 msgExtEvent_flags
    putWord8 msgExtEvent_pin

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgExtEvent_" . stripPrefix "msgExtEvent_"}
             ''MsgExtEvent)
