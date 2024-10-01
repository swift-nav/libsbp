{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Imu
-- Copyright:   Copyright (C) 2015-2021 Swift Navigation, Inc.
-- License:     MIT
-- Contact:     https://support.swiftnav.com
-- Stability:   experimental
-- Portability: portable
--
-- \< Inertial Measurement Unit (IMU) messages. \>

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
-- message. If using "time since startup" local time tags, the receiving end
-- will expect either a MSG_GNSS_TIME_OFFSET or MSG_PPS_TIME to establish the
-- relationship between IMU time and GNSS time.
-- Regardless of the timestamping mode, the timestamp is required to roll over
-- to zero when reaching one week (604800 seconds, or 604800000 milliseconds).
-- The time-tagging mode should not change throughout a run.
data MsgImuRaw = MsgImuRaw
  { _msgImuRaw_tow :: !Word32
    -- ^ Milliseconds since reference epoch and time status.
  , _msgImuRaw_tow_f :: !Word8
    -- ^ Milliseconds since reference epoch, fractional part
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
    _msgImuRaw_acc_x <- (fromIntegral <$> getWord16le)
    _msgImuRaw_acc_y <- (fromIntegral <$> getWord16le)
    _msgImuRaw_acc_z <- (fromIntegral <$> getWord16le)
    _msgImuRaw_gyr_x <- (fromIntegral <$> getWord16le)
    _msgImuRaw_gyr_y <- (fromIntegral <$> getWord16le)
    _msgImuRaw_gyr_z <- (fromIntegral <$> getWord16le)
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
    _msgImuAux_temp <- (fromIntegral <$> getWord16le)
    _msgImuAux_imu_conf <- getWord8
    pure MsgImuAux {..}

  put MsgImuAux {..} = do
    putWord8 _msgImuAux_imu_type
    (putWord16le . fromIntegral) _msgImuAux_temp
    putWord8 _msgImuAux_imu_conf

$(makeSBP 'msgImuAux ''MsgImuAux)
$(makeJSON "_msgImuAux_" ''MsgImuAux)
$(makeLenses ''MsgImuAux)

msgImuComp :: Word16
msgImuComp = 0x0905

-- | SBP class for message MSG_IMU_COMP (0x0905).
--
-- Data from the Inertial Measurement Unit, containing accelerometer and
-- gyroscope readings compensated for estimated errors and constant  physical
-- effects. The output is valid for inertially referenced center  of
-- navigation (IMU body frame) represented in vehicle body frame.
data MsgImuComp = MsgImuComp
  { _msgImuComp_time     :: !Word64
    -- ^ Microseconds since reference epoch
  , _msgImuComp_flags    :: !Word16
    -- ^ Contains the applied compensation parameters and time synchronization
    -- mode
  , _msgImuComp_acc_comp_x :: !Int32
    -- ^ Compensated acceleration X axis
  , _msgImuComp_acc_comp_y :: !Int32
    -- ^ Compensated acceleration Y axis
  , _msgImuComp_acc_comp_z :: !Int32
    -- ^ Compensated acceleration Z axis
  , _msgImuComp_gyr_comp_x :: !Int32
    -- ^ Compensated angular rate X axis
  , _msgImuComp_gyr_comp_y :: !Int32
    -- ^ Compensated angular rate Y axis
  , _msgImuComp_gyr_comp_z :: !Int32
    -- ^ Compensated angular rate Z axis
  } deriving ( Show, Read, Eq )

instance Binary MsgImuComp where
  get = do
    _msgImuComp_time <- getWord64le
    _msgImuComp_flags <- getWord16le
    _msgImuComp_acc_comp_x <- (fromIntegral <$> getWord32le)
    _msgImuComp_acc_comp_y <- (fromIntegral <$> getWord32le)
    _msgImuComp_acc_comp_z <- (fromIntegral <$> getWord32le)
    _msgImuComp_gyr_comp_x <- (fromIntegral <$> getWord32le)
    _msgImuComp_gyr_comp_y <- (fromIntegral <$> getWord32le)
    _msgImuComp_gyr_comp_z <- (fromIntegral <$> getWord32le)
    pure MsgImuComp {..}

  put MsgImuComp {..} = do
    putWord64le _msgImuComp_time
    putWord16le _msgImuComp_flags
    (putWord32le . fromIntegral) _msgImuComp_acc_comp_x
    (putWord32le . fromIntegral) _msgImuComp_acc_comp_y
    (putWord32le . fromIntegral) _msgImuComp_acc_comp_z
    (putWord32le . fromIntegral) _msgImuComp_gyr_comp_x
    (putWord32le . fromIntegral) _msgImuComp_gyr_comp_y
    (putWord32le . fromIntegral) _msgImuComp_gyr_comp_z

$(makeSBP 'msgImuComp ''MsgImuComp)
$(makeJSON "_msgImuComp_" ''MsgImuComp)
$(makeLenses ''MsgImuComp)
