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
-- Messages from a vehicle.

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
