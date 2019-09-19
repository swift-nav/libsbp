{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Mag
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- \<Magnetometer (mag) messages.\>

module SwiftNav.SBP.Mag
  ( module SwiftNav.SBP.Mag
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
import SwiftNav.SBP.Types

{-# ANN module ("HLint: ignore Use camelCase"::String) #-}
{-# ANN module ("HLint: ignore Redundant do"::String) #-}
{-# ANN module ("HLint: ignore Use newtype instead of data"::String) #-}


msgMagRaw :: Word16
msgMagRaw = 0x0902

-- | SBP class for message MSG_MAG_RAW (0x0902).
--
-- Raw data from the magnetometer.
data MsgMagRaw = MsgMagRaw
  { _msgMagRaw_tow :: !Word32
    -- ^ Milliseconds since start of GPS week. If the high bit is set, the time
    -- is unknown or invalid.
  , _msgMagRaw_tow_f :: !Word8
    -- ^ Milliseconds since start of GPS week, fractional part
  , _msgMagRaw_mag_x :: !Int16
    -- ^ Magnetic field in the body frame X axis
  , _msgMagRaw_mag_y :: !Int16
    -- ^ Magnetic field in the body frame Y axis
  , _msgMagRaw_mag_z :: !Int16
    -- ^ Magnetic field in the body frame Z axis
  } deriving ( Show, Read, Eq )

instance Binary MsgMagRaw where
  get = do
    _msgMagRaw_tow <- getWord32le
    _msgMagRaw_tow_f <- getWord8
    _msgMagRaw_mag_x <- fromIntegral <$> getWord16le
    _msgMagRaw_mag_y <- fromIntegral <$> getWord16le
    _msgMagRaw_mag_z <- fromIntegral <$> getWord16le
    pure MsgMagRaw {..}

  put MsgMagRaw {..} = do
    putWord32le _msgMagRaw_tow
    putWord8 _msgMagRaw_tow_f
    (putWord16le . fromIntegral) _msgMagRaw_mag_x
    (putWord16le . fromIntegral) _msgMagRaw_mag_y
    (putWord16le . fromIntegral) _msgMagRaw_mag_z

$(makeSBP 'msgMagRaw ''MsgMagRaw)
$(makeJSON "_msgMagRaw_" ''MsgMagRaw)
$(makeLenses ''MsgMagRaw)
