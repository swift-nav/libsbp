{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Orientation
-- Copyright:   Copyright (C) 2015-2021 Swift Navigation, Inc.
-- License:     MIT
-- Contact:     https://support.swiftnav.com
-- Stability:   experimental
-- Portability: portable
--
-- \< Orientation Messages \>

module SwiftNav.SBP.Orientation
  ( module SwiftNav.SBP.Orientation
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


msgBaselineHeading :: Word16
msgBaselineHeading = 0x020F

-- | SBP class for message MSG_BASELINE_HEADING (0x020F).
--
-- This message reports the baseline heading pointing from the base station to
-- the rover relative to True North. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow). It is intended
-- that time-matched RTK mode is used when the base station is moving.
data MsgBaselineHeading = MsgBaselineHeading
  { _msgBaselineHeading_tow   :: !Word32
    -- ^ GPS Time of Week
  , _msgBaselineHeading_heading :: !Word32
    -- ^ Heading
  , _msgBaselineHeading_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgBaselineHeading_flags :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgBaselineHeading where
  get = do
    _msgBaselineHeading_tow <- getWord32le
    _msgBaselineHeading_heading <- getWord32le
    _msgBaselineHeading_n_sats <- getWord8
    _msgBaselineHeading_flags <- getWord8
    pure MsgBaselineHeading {..}

  put MsgBaselineHeading {..} = do
    putWord32le _msgBaselineHeading_tow
    putWord32le _msgBaselineHeading_heading
    putWord8 _msgBaselineHeading_n_sats
    putWord8 _msgBaselineHeading_flags

$(makeSBP 'msgBaselineHeading ''MsgBaselineHeading)
$(makeJSON "_msgBaselineHeading_" ''MsgBaselineHeading)
$(makeLenses ''MsgBaselineHeading)

msgOrientQuat :: Word16
msgOrientQuat = 0x0220

-- | SBP class for message MSG_ORIENT_QUAT (0x0220).
--
-- This message reports the quaternion vector describing the vehicle body
-- frame's orientation with respect to a local-level NED frame. The components
-- of the vector should sum to a unit vector assuming that the LSB of each
-- component as a value of 2^-31. This message will only be available in
-- future INS versions of Swift Products and is not produced by Piksi Multi or
-- Duro.
data MsgOrientQuat = MsgOrientQuat
  { _msgOrientQuat_tow      :: !Word32
    -- ^ GPS Time of Week
  , _msgOrientQuat_w        :: !Int32
    -- ^ Real component
  , _msgOrientQuat_x        :: !Int32
    -- ^ 1st imaginary component
  , _msgOrientQuat_y        :: !Int32
    -- ^ 2nd imaginary component
  , _msgOrientQuat_z        :: !Int32
    -- ^ 3rd imaginary component
  , _msgOrientQuat_w_accuracy :: !Float
    -- ^ Estimated standard deviation of w
  , _msgOrientQuat_x_accuracy :: !Float
    -- ^ Estimated standard deviation of x
  , _msgOrientQuat_y_accuracy :: !Float
    -- ^ Estimated standard deviation of y
  , _msgOrientQuat_z_accuracy :: !Float
    -- ^ Estimated standard deviation of z
  , _msgOrientQuat_flags    :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgOrientQuat where
  get = do
    _msgOrientQuat_tow <- getWord32le
    _msgOrientQuat_w <- (fromIntegral <$> getWord32le)
    _msgOrientQuat_x <- (fromIntegral <$> getWord32le)
    _msgOrientQuat_y <- (fromIntegral <$> getWord32le)
    _msgOrientQuat_z <- (fromIntegral <$> getWord32le)
    _msgOrientQuat_w_accuracy <- getFloat32le
    _msgOrientQuat_x_accuracy <- getFloat32le
    _msgOrientQuat_y_accuracy <- getFloat32le
    _msgOrientQuat_z_accuracy <- getFloat32le
    _msgOrientQuat_flags <- getWord8
    pure MsgOrientQuat {..}

  put MsgOrientQuat {..} = do
    putWord32le _msgOrientQuat_tow
    (putWord32le . fromIntegral) _msgOrientQuat_w
    (putWord32le . fromIntegral) _msgOrientQuat_x
    (putWord32le . fromIntegral) _msgOrientQuat_y
    (putWord32le . fromIntegral) _msgOrientQuat_z
    putFloat32le _msgOrientQuat_w_accuracy
    putFloat32le _msgOrientQuat_x_accuracy
    putFloat32le _msgOrientQuat_y_accuracy
    putFloat32le _msgOrientQuat_z_accuracy
    putWord8 _msgOrientQuat_flags

$(makeSBP 'msgOrientQuat ''MsgOrientQuat)
$(makeJSON "_msgOrientQuat_" ''MsgOrientQuat)
$(makeLenses ''MsgOrientQuat)

msgOrientEuler :: Word16
msgOrientEuler = 0x0221

-- | SBP class for message MSG_ORIENT_EULER (0x0221).
--
-- This message reports the yaw, pitch, and roll angles of the vehicle body
-- frame. The rotations should applied intrinsically in the order yaw, pitch,
-- and roll in order to rotate the from a frame aligned with the local-level
-- NED frame to the vehicle body frame.  This message will only be available
-- in future INS versions of Swift Products and is not produced by Piksi Multi
-- or Duro.
data MsgOrientEuler = MsgOrientEuler
  { _msgOrientEuler_tow          :: !Word32
    -- ^ GPS Time of Week
  , _msgOrientEuler_roll         :: !Int32
    -- ^ rotation about the forward axis of the vehicle
  , _msgOrientEuler_pitch        :: !Int32
    -- ^ rotation about the rightward axis of the vehicle
  , _msgOrientEuler_yaw          :: !Int32
    -- ^ rotation about the downward axis of the vehicle
  , _msgOrientEuler_roll_accuracy :: !Float
    -- ^ Estimated standard deviation of roll
  , _msgOrientEuler_pitch_accuracy :: !Float
    -- ^ Estimated standard deviation of pitch
  , _msgOrientEuler_yaw_accuracy :: !Float
    -- ^ Estimated standard deviation of yaw
  , _msgOrientEuler_flags        :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgOrientEuler where
  get = do
    _msgOrientEuler_tow <- getWord32le
    _msgOrientEuler_roll <- (fromIntegral <$> getWord32le)
    _msgOrientEuler_pitch <- (fromIntegral <$> getWord32le)
    _msgOrientEuler_yaw <- (fromIntegral <$> getWord32le)
    _msgOrientEuler_roll_accuracy <- getFloat32le
    _msgOrientEuler_pitch_accuracy <- getFloat32le
    _msgOrientEuler_yaw_accuracy <- getFloat32le
    _msgOrientEuler_flags <- getWord8
    pure MsgOrientEuler {..}

  put MsgOrientEuler {..} = do
    putWord32le _msgOrientEuler_tow
    (putWord32le . fromIntegral) _msgOrientEuler_roll
    (putWord32le . fromIntegral) _msgOrientEuler_pitch
    (putWord32le . fromIntegral) _msgOrientEuler_yaw
    putFloat32le _msgOrientEuler_roll_accuracy
    putFloat32le _msgOrientEuler_pitch_accuracy
    putFloat32le _msgOrientEuler_yaw_accuracy
    putWord8 _msgOrientEuler_flags

$(makeSBP 'msgOrientEuler ''MsgOrientEuler)
$(makeJSON "_msgOrientEuler_" ''MsgOrientEuler)
$(makeLenses ''MsgOrientEuler)

msgAngularRate :: Word16
msgAngularRate = 0x0222

-- | SBP class for message MSG_ANGULAR_RATE (0x0222).
--
-- This message reports the orientation rates in the vehicle body frame. The
-- values represent the measurements a strapped down gyroscope would make and
-- are not equivalent to the time derivative of the Euler angles. The
-- orientation and origin of the user frame is specified via device settings.
-- By convention, the vehicle x-axis is expected to be aligned with the
-- forward direction, while the vehicle y-axis is expected to be aligned with
-- the right direction, and the vehicle z-axis should be aligned with the down
-- direction. This message will only be available in future INS versions of
-- Swift Products and is not produced by Piksi Multi or Duro.
data MsgAngularRate = MsgAngularRate
  { _msgAngularRate_tow :: !Word32
    -- ^ GPS Time of Week
  , _msgAngularRate_x   :: !Int32
    -- ^ angular rate about x axis
  , _msgAngularRate_y   :: !Int32
    -- ^ angular rate about y axis
  , _msgAngularRate_z   :: !Int32
    -- ^ angular rate about z axis
  , _msgAngularRate_flags :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgAngularRate where
  get = do
    _msgAngularRate_tow <- getWord32le
    _msgAngularRate_x <- (fromIntegral <$> getWord32le)
    _msgAngularRate_y <- (fromIntegral <$> getWord32le)
    _msgAngularRate_z <- (fromIntegral <$> getWord32le)
    _msgAngularRate_flags <- getWord8
    pure MsgAngularRate {..}

  put MsgAngularRate {..} = do
    putWord32le _msgAngularRate_tow
    (putWord32le . fromIntegral) _msgAngularRate_x
    (putWord32le . fromIntegral) _msgAngularRate_y
    (putWord32le . fromIntegral) _msgAngularRate_z
    putWord8 _msgAngularRate_flags

$(makeSBP 'msgAngularRate ''MsgAngularRate)
$(makeJSON "_msgAngularRate_" ''MsgAngularRate)
$(makeLenses ''MsgAngularRate)

msgOrientQuatCov :: Word16
msgOrientQuatCov = 0x0223

-- | SBP class for message MSG_ORIENT_QUAT_COV (0x0223).
--
-- This message reports the orientation as a unit quaternion together with the
-- upper triangle of the symmetric 3x3 attitude covariance matrix and a GPS
-- time-of-week time-tag. The reference frame of the quaternion and the
-- parameterization of the covariance matrix are both encoded in the flags
-- field, allowing additional frames or parameterizations to be added later
-- without introducing a new message. By default the quaternion describes the
-- orientation of the vehicle body frame with respect to a local-level NED
-- frame (matching MSG_ORIENT_QUAT) and the covariance is expressed as small-
-- angle rotation errors about the axes of that NED frame; in this default
-- case the cov_xx, cov_yy, cov_zz diagonal entries correspond to the variance
-- of the rotation error about North, East, and Down respectively. The
-- components of the quaternion sum to a unit vector assuming that the LSB of
-- each component has a value of 2^-31. This message will only be available in
-- future INS versions of Swift Products and is not produced by Piksi Multi or
-- Duro.
data MsgOrientQuatCov = MsgOrientQuatCov
  { _msgOrientQuatCov_tow  :: !Word32
    -- ^ GPS Time of Week
  , _msgOrientQuatCov_w    :: !Int32
    -- ^ Real component
  , _msgOrientQuatCov_x    :: !Int32
    -- ^ 1st imaginary component
  , _msgOrientQuatCov_y    :: !Int32
    -- ^ 2nd imaginary component
  , _msgOrientQuatCov_z    :: !Int32
    -- ^ 3rd imaginary component
  , _msgOrientQuatCov_cov_xx :: !Float
    -- ^ Estimated variance of the rotation error about the 1st axis of the
    -- covariance frame
  , _msgOrientQuatCov_cov_xy :: !Float
    -- ^ Estimated covariance of the rotation errors about the 1st and 2nd axes
    -- of the covariance frame
  , _msgOrientQuatCov_cov_xz :: !Float
    -- ^ Estimated covariance of the rotation errors about the 1st and 3rd axes
    -- of the covariance frame
  , _msgOrientQuatCov_cov_yy :: !Float
    -- ^ Estimated variance of the rotation error about the 2nd axis of the
    -- covariance frame
  , _msgOrientQuatCov_cov_yz :: !Float
    -- ^ Estimated covariance of the rotation errors about the 2nd and 3rd axes
    -- of the covariance frame
  , _msgOrientQuatCov_cov_zz :: !Float
    -- ^ Estimated variance of the rotation error about the 3rd axis of the
    -- covariance frame
  , _msgOrientQuatCov_flags :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgOrientQuatCov where
  get = do
    _msgOrientQuatCov_tow <- getWord32le
    _msgOrientQuatCov_w <- (fromIntegral <$> getWord32le)
    _msgOrientQuatCov_x <- (fromIntegral <$> getWord32le)
    _msgOrientQuatCov_y <- (fromIntegral <$> getWord32le)
    _msgOrientQuatCov_z <- (fromIntegral <$> getWord32le)
    _msgOrientQuatCov_cov_xx <- getFloat32le
    _msgOrientQuatCov_cov_xy <- getFloat32le
    _msgOrientQuatCov_cov_xz <- getFloat32le
    _msgOrientQuatCov_cov_yy <- getFloat32le
    _msgOrientQuatCov_cov_yz <- getFloat32le
    _msgOrientQuatCov_cov_zz <- getFloat32le
    _msgOrientQuatCov_flags <- getWord8
    pure MsgOrientQuatCov {..}

  put MsgOrientQuatCov {..} = do
    putWord32le _msgOrientQuatCov_tow
    (putWord32le . fromIntegral) _msgOrientQuatCov_w
    (putWord32le . fromIntegral) _msgOrientQuatCov_x
    (putWord32le . fromIntegral) _msgOrientQuatCov_y
    (putWord32le . fromIntegral) _msgOrientQuatCov_z
    putFloat32le _msgOrientQuatCov_cov_xx
    putFloat32le _msgOrientQuatCov_cov_xy
    putFloat32le _msgOrientQuatCov_cov_xz
    putFloat32le _msgOrientQuatCov_cov_yy
    putFloat32le _msgOrientQuatCov_cov_yz
    putFloat32le _msgOrientQuatCov_cov_zz
    putWord8 _msgOrientQuatCov_flags

$(makeSBP 'msgOrientQuatCov ''MsgOrientQuatCov)
$(makeJSON "_msgOrientQuatCov_" ''MsgOrientQuatCov)
$(makeLenses ''MsgOrientQuatCov)

