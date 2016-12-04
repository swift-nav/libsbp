{-# OPTIONS_GHC -fno-warn-unused-imports #-}
-- |
-- Module:      SwiftNav.SBP.Imu
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Inertial Measurement Unit (IMU) messages.

module SwiftNav.SBP.Imu where

import BasicPrelude as P
import Control.Lens
import Control.Monad.Loops
import Data.Aeson.TH           (defaultOptions, deriveJSON, fieldLabelModifier)
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy    hiding (ByteString)
import Data.Int
import Data.Word
import SwiftNav.SBP.Encoding
import SwiftNav.SBP.TH
import SwiftNav.SBP.Types

msgImuRaw :: Word16
msgImuRaw = 0x0900

-- | SBP class for message MSG_IMU_RAW (0x0900).
--
-- Raw data from the Inertial Measurement Unit, containing accelerometer and
-- gyroscope readings.
data MsgImuRaw = MsgImuRaw
  { _msgImuRaw_tow :: Word32
    -- ^ Milliseconds since start of GPS week. If the high bit is set, the time
    -- is unknown or invalid.
  , _msgImuRaw_tow_f :: Word8
    -- ^ Milliseconds since start of GPS week, fractional part
  , _msgImuRaw_acc_x :: Int16
    -- ^ Acceleration in the body frame X axis
  , _msgImuRaw_acc_y :: Int16
    -- ^ Acceleration in the body frame Y axis
  , _msgImuRaw_acc_z :: Int16
    -- ^ Acceleration in the body frame Z axis
  , _msgImuRaw_gyr_x :: Int16
    -- ^ Angular rate around the body frame X axis
  , _msgImuRaw_gyr_y :: Int16
    -- ^ Angular rate around the body frame Y axis
  , _msgImuRaw_gyr_z :: Int16
    -- ^ Angular rate around the body frame Z axis
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
    return MsgImuRaw {..}

  put MsgImuRaw {..} = do
    putWord32le _msgImuRaw_tow
    putWord8 _msgImuRaw_tow_f
    putWord16le $ fromIntegral _msgImuRaw_acc_x
    putWord16le $ fromIntegral _msgImuRaw_acc_y
    putWord16le $ fromIntegral _msgImuRaw_acc_z
    putWord16le $ fromIntegral _msgImuRaw_gyr_x
    putWord16le $ fromIntegral _msgImuRaw_gyr_y
    putWord16le $ fromIntegral _msgImuRaw_gyr_z

$(deriveSBP 'msgImuRaw ''MsgImuRaw)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgImuRaw_" . P.stripPrefix "_msgImuRaw_"}
             ''MsgImuRaw)
$(makeLenses ''MsgImuRaw)
