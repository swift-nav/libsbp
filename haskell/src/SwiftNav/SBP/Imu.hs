{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Imu
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- \<Inertial Measurement Unit (IMU) messages.\>

module SwiftNav.SBP.Imu
  ( module SwiftNav.SBP.Imu
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


msgImuRaw :: Word16
msgImuRaw = 0x0900

-- | SBP class for message MSG_IMU_RAW (0x0900).
--
-- Raw data from the Inertial Measurement Unit, containing accelerometer and
-- gyroscope readings. The sense of the measurements are to be aligned with
-- the indications on the device itself. Measurement units, which are specific
-- to the device hardware and settings, are communicated via the MSG_IMU_AUX
-- message.
data MsgImuRaw = MsgImuRaw
  { _msgImuRaw_tow :: !Word32
    -- ^ Milliseconds since start of GPS week. If the high bit is set, the time
    -- is unknown or invalid.
  , _msgImuRaw_tow_f :: !Word8
    -- ^ Milliseconds since start of GPS week, fractional part
  , _msgImuRaw_acc_x :: !Int16
    -- ^ Acceleration in the IMU frame X axis
  , _msgImuRaw_acc_y :: !Int16
    -- ^ Acceleration in the IMU frame Y axis
  , _msgImuRaw_acc_z :: !Int16
    -- ^ Acceleration in the IMU frame Z axis
  , _msgImuRaw_gyr_x :: !Int16
    -- ^ Angular rate around IMU frame X axis
  , _msgImuRaw_gyr_y :: !Int16
    -- ^ Angular rate around IMU frame Y axis
  , _msgImuRaw_gyr_z :: !Int16
    -- ^ Angular rate around IMU frame Z axis
  } deriving ( Show, Read, Eq )

instance Binary MsgImuRaw where
  get = do
    _msgImuRaw_tow <- getWord32le
    _msgImuRaw_tow_f <- getWord8
    _msgImuRaw_acc_x <- fromIntegral <$> getWord16le
    _msgImuRaw_acc_y <- fromIntegral <$> getWord16le
    _msgImuRaw_acc_z <- fromIntegral <$> getWord16le
    _msgImuRaw_gyr_x <- fromIntegral <$> getWord16le
    _msgImuRaw_gyr_y <- fromIntegral <$> getWord16le
    _msgImuRaw_gyr_z <- fromIntegral <$> getWord16le
    pure MsgImuRaw {..}

  put MsgImuRaw {..} = do
    putWord32le _msgImuRaw_tow
    putWord8 _msgImuRaw_tow_f
    (putWord16le . fromIntegral) _msgImuRaw_acc_x
    (putWord16le . fromIntegral) _msgImuRaw_acc_y
    (putWord16le . fromIntegral) _msgImuRaw_acc_z
    (putWord16le . fromIntegral) _msgImuRaw_gyr_x
    (putWord16le . fromIntegral) _msgImuRaw_gyr_y
    (putWord16le . fromIntegral) _msgImuRaw_gyr_z

$(makeSBP 'msgImuRaw ''MsgImuRaw)
$(makeJSON "_msgImuRaw_" ''MsgImuRaw)
$(makeLenses ''MsgImuRaw)

msgImuAux :: Word16
msgImuAux = 0x0901

-- | SBP class for message MSG_IMU_AUX (0x0901).
--
-- Auxiliary data specific to a particular IMU. The `imu_type` field will
-- always be consistent but the rest of the payload is device specific and
-- depends on the value of `imu_type`.
data MsgImuAux = MsgImuAux
  { _msgImuAux_imu_type :: !Word8
    -- ^ IMU type
  , _msgImuAux_temp   :: !Int16
    -- ^ Raw IMU temperature
  , _msgImuAux_imu_conf :: !Word8
    -- ^ IMU configuration
  } deriving ( Show, Read, Eq )

instance Binary MsgImuAux where
  get = do
    _msgImuAux_imu_type <- getWord8
    _msgImuAux_temp <- fromIntegral <$> getWord16le
    _msgImuAux_imu_conf <- getWord8
    pure MsgImuAux {..}

  put MsgImuAux {..} = do
    putWord8 _msgImuAux_imu_type
    (putWord16le . fromIntegral) _msgImuAux_temp
    putWord8 _msgImuAux_imu_conf

$(makeSBP 'msgImuAux ''MsgImuAux)
$(makeJSON "_msgImuAux_" ''MsgImuAux)
$(makeLenses ''MsgImuAux)
