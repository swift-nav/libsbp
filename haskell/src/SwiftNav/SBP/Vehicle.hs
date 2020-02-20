{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Vehicle
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- \<Messages from a vehicle.\>

module SwiftNav.SBP.Vehicle
  ( module SwiftNav.SBP.Vehicle
  ) where

import BasicPrelude
import Control.Lens
import Control.Monad.Loops
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString.Lazy    hiding (ByteString)
import Data.Int
import Data.Word
import SwiftNav.SBP.TH

{-# ANN module ("HLint: ignore Use camelCase"::String) #-}
{-# ANN module ("HLint: ignore Redundant do"::String) #-}
{-# ANN module ("HLint: ignore Use newtype instead of data"::String) #-}


msgOdometry :: Word16
msgOdometry = 0x0903

-- | SBP class for message MSG_ODOMETRY (0x0903).
--
-- Message representing the x component of vehicle velocity in the user frame
-- at the odometry reference point(s) specified by the user. The offset for the
-- odometry reference point and  the definition and origin of the user frame
-- are defined through the device settings interface. There are 4 possible
-- user-defined sources of this message  which are labeled arbitrarily  source
-- 0 through 3.
data MsgOdometry = MsgOdometry
  { _msgOdometry_tow    :: !Word32
    -- ^ Time field representing either milliseconds in the GPS Week or local CPU
    -- time from the producing system in milliseconds.  See the tow_source flag
    -- for the exact source of this timestamp.
  , _msgOdometry_velocity :: !Int32
    -- ^ The signed forward component of vehicle velocity.
  , _msgOdometry_flags  :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgOdometry where
  get = do
    _msgOdometry_tow <- getWord32le
    _msgOdometry_velocity <- fromIntegral <$> getWord32le
    _msgOdometry_flags <- getWord8
    pure MsgOdometry {..}

  put MsgOdometry {..} = do
    putWord32le _msgOdometry_tow
    (putWord32le . fromIntegral) _msgOdometry_velocity
    putWord8 _msgOdometry_flags

$(makeSBP 'msgOdometry ''MsgOdometry)
$(makeJSON "_msgOdometry_" ''MsgOdometry)
$(makeLenses ''MsgOdometry)

msgWheeltick :: Word16
msgWheeltick = 0x0904

-- | SBP class for message MSG_WHEELTICK (0x0904).
--
-- Message containing the accumulated distance travelled by a wheel located at
-- an odometry reference point defined by the user. The offset for the odometry
-- reference point and the definition and origin of the user frame are defined
-- through the device settings interface. The source of this message is
-- identified by the source field, which is an integer ranging from 0 to 255.
-- The timestamp associated with this message should represent the time when
-- the accumulated tick count reached the value given by the contents of this
-- message as accurately as possible.
data MsgWheeltick = MsgWheeltick
  { _msgWheeltick_time :: !Word64
    -- ^ Time field representing either microseconds since the last PPS,
    -- microseconds in the GPS Week or local CPU time from the producing system
    -- in microseconds. See the synch_type field for the exact meaning of this
    -- timestamp.
  , _msgWheeltick_flags :: !Word8
    -- ^ Field indicating the type of timestamp contained in the time field.
  , _msgWheeltick_source :: !Word8
    -- ^ ID of the sensor producing this message
  , _msgWheeltick_ticks :: !Int32
    -- ^ Free-running counter of the accumulated distance for this sensor. The
    -- counter should be incrementing if travelling into one direction and
    -- decrementing when travelling in the opposite direction.
  } deriving ( Show, Read, Eq )

instance Binary MsgWheeltick where
  get = do
    _msgWheeltick_time <- getWord64le
    _msgWheeltick_flags <- getWord8
    _msgWheeltick_source <- getWord8
    _msgWheeltick_ticks <- fromIntegral <$> getWord32le
    pure MsgWheeltick {..}

  put MsgWheeltick {..} = do
    putWord64le _msgWheeltick_time
    putWord8 _msgWheeltick_flags
    putWord8 _msgWheeltick_source
    (putWord32le . fromIntegral) _msgWheeltick_ticks

$(makeSBP 'msgWheeltick ''MsgWheeltick)
$(makeJSON "_msgWheeltick_" ''MsgWheeltick)
$(makeLenses ''MsgWheeltick)
