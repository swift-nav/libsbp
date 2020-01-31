{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Navigation
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- \<Geodetic navigation messages reporting GPS time, position, velocity, and
-- baseline position solutions. For position solutions, these messages define
-- several different position solutions: single-point (SPP), RTK, and pseudo-
-- absolute position solutions.  The SPP is the standalone, absolute GPS
-- position solution using only a single receiver. The RTK solution is the
-- differential GPS solution, which can use either a fixed/integer or floating
-- carrier phase ambiguity. The pseudo-absolute position solution uses a user-
-- provided, well-surveyed base station position (if available) and the RTK
-- solution in tandem.  When the inertial navigation mode indicates that the
-- IMU is used, all messages are reported in the vehicle body frame as defined
-- by device settings.  By default, the vehicle body frame is configured to be
-- coincident with the antenna phase center.  When there is no inertial
-- navigation, the solution will be reported at the phase center of the
-- antenna. There is no inertial navigation capability on Piksi Multi or Duro.
-- \>

module SwiftNav.SBP.Navigation
  ( module SwiftNav.SBP.Navigation
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


msgGpsTime :: Word16
msgGpsTime = 0x0102

-- | SBP class for message MSG_GPS_TIME (0x0102).
--
-- This message reports the GPS time, representing the time since the GPS epoch
-- began on midnight January 6, 1980 UTC. GPS time counts the weeks and seconds
-- of the week. The weeks begin at the Saturday/Sunday transition. GPS week 0
-- began at the beginning of the GPS time scale.  Within each week number, the
-- GPS time of the week is between between 0 and 604800 seconds (=60*60*24*7).
-- Note that GPS time does not accumulate leap seconds, and as of now, has a
-- small offset from UTC. In a message stream, this message precedes a set of
-- other navigation messages referenced to the same time (but lacking the ns
-- field) and indicates a more precise time of these messages.
data MsgGpsTime = MsgGpsTime
  { _msgGpsTime_wn        :: !Word16
    -- ^ GPS week number
  , _msgGpsTime_tow       :: !Word32
    -- ^ GPS time of week rounded to the nearest millisecond
  , _msgGpsTime_ns_residual :: !Int32
    -- ^ Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    -- 500000)
  , _msgGpsTime_flags     :: !Word8
    -- ^ Status flags (reserved)
  } deriving ( Show, Read, Eq )

instance Binary MsgGpsTime where
  get = do
    _msgGpsTime_wn <- getWord16le
    _msgGpsTime_tow <- getWord32le
    _msgGpsTime_ns_residual <- fromIntegral <$> getWord32le
    _msgGpsTime_flags <- getWord8
    pure MsgGpsTime {..}

  put MsgGpsTime {..} = do
    putWord16le _msgGpsTime_wn
    putWord32le _msgGpsTime_tow
    (putWord32le . fromIntegral) _msgGpsTime_ns_residual
    putWord8 _msgGpsTime_flags

$(makeSBP 'msgGpsTime ''MsgGpsTime)
$(makeJSON "_msgGpsTime_" ''MsgGpsTime)
$(makeLenses ''MsgGpsTime)

msgUtcTime :: Word16
msgUtcTime = 0x0103

-- | SBP class for message MSG_UTC_TIME (0x0103).
--
-- This message reports the Universal Coordinated Time (UTC).  Note the flags
-- which indicate the source of the UTC offset value and source of the time
-- fix.
data MsgUtcTime = MsgUtcTime
  { _msgUtcTime_flags :: !Word8
    -- ^ Indicates source and time validity
  , _msgUtcTime_tow   :: !Word32
    -- ^ GPS time of week rounded to the nearest millisecond
  , _msgUtcTime_year  :: !Word16
    -- ^ Year
  , _msgUtcTime_month :: !Word8
    -- ^ Month (range 1 .. 12)
  , _msgUtcTime_day   :: !Word8
    -- ^ days in the month (range 1-31)
  , _msgUtcTime_hours :: !Word8
    -- ^ hours of day (range 0-23)
  , _msgUtcTime_minutes :: !Word8
    -- ^ minutes of hour (range 0-59)
  , _msgUtcTime_seconds :: !Word8
    -- ^ seconds of minute (range 0-60) rounded down
  , _msgUtcTime_ns    :: !Word32
    -- ^ nanoseconds of second (range 0-999999999)
  } deriving ( Show, Read, Eq )

instance Binary MsgUtcTime where
  get = do
    _msgUtcTime_flags <- getWord8
    _msgUtcTime_tow <- getWord32le
    _msgUtcTime_year <- getWord16le
    _msgUtcTime_month <- getWord8
    _msgUtcTime_day <- getWord8
    _msgUtcTime_hours <- getWord8
    _msgUtcTime_minutes <- getWord8
    _msgUtcTime_seconds <- getWord8
    _msgUtcTime_ns <- getWord32le
    pure MsgUtcTime {..}

  put MsgUtcTime {..} = do
    putWord8 _msgUtcTime_flags
    putWord32le _msgUtcTime_tow
    putWord16le _msgUtcTime_year
    putWord8 _msgUtcTime_month
    putWord8 _msgUtcTime_day
    putWord8 _msgUtcTime_hours
    putWord8 _msgUtcTime_minutes
    putWord8 _msgUtcTime_seconds
    putWord32le _msgUtcTime_ns

$(makeSBP 'msgUtcTime ''MsgUtcTime)
$(makeJSON "_msgUtcTime_" ''MsgUtcTime)
$(makeLenses ''MsgUtcTime)

msgDops :: Word16
msgDops = 0x0208

-- | SBP class for message MSG_DOPS (0x0208).
--
-- This dilution of precision (DOP) message describes the effect of navigation
-- satellite geometry on positional measurement precision.  The flags field
-- indicated whether the DOP reported corresponds to differential or SPP
-- solution.
data MsgDops = MsgDops
  { _msgDops_tow :: !Word32
    -- ^ GPS Time of Week
  , _msgDops_gdop :: !Word16
    -- ^ Geometric Dilution of Precision
  , _msgDops_pdop :: !Word16
    -- ^ Position Dilution of Precision
  , _msgDops_tdop :: !Word16
    -- ^ Time Dilution of Precision
  , _msgDops_hdop :: !Word16
    -- ^ Horizontal Dilution of Precision
  , _msgDops_vdop :: !Word16
    -- ^ Vertical Dilution of Precision
  , _msgDops_flags :: !Word8
    -- ^ Indicates the position solution with which the DOPS message corresponds
  } deriving ( Show, Read, Eq )

instance Binary MsgDops where
  get = do
    _msgDops_tow <- getWord32le
    _msgDops_gdop <- getWord16le
    _msgDops_pdop <- getWord16le
    _msgDops_tdop <- getWord16le
    _msgDops_hdop <- getWord16le
    _msgDops_vdop <- getWord16le
    _msgDops_flags <- getWord8
    pure MsgDops {..}

  put MsgDops {..} = do
    putWord32le _msgDops_tow
    putWord16le _msgDops_gdop
    putWord16le _msgDops_pdop
    putWord16le _msgDops_tdop
    putWord16le _msgDops_hdop
    putWord16le _msgDops_vdop
    putWord8 _msgDops_flags

$(makeSBP 'msgDops ''MsgDops)
$(makeJSON "_msgDops_" ''MsgDops)
$(makeLenses ''MsgDops)

msgPosEcef :: Word16
msgPosEcef = 0x0209

-- | SBP class for message MSG_POS_ECEF (0x0209).
--
-- The position solution message reports absolute Earth Centered Earth Fixed
-- (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
-- the position solution. If the rover receiver knows the surveyed position of
-- the base station and has an RTK solution, this reports a pseudo-absolute
-- position solution using the base station position and the rover's RTK
-- baseline vector. The full GPS time is given by the preceding MSG_GPS_TIME
-- with the matching time-of-week (tow).
data MsgPosEcef = MsgPosEcef
  { _msgPosEcef_tow    :: !Word32
    -- ^ GPS Time of Week
  , _msgPosEcef_x      :: !Double
    -- ^ ECEF X coordinate
  , _msgPosEcef_y      :: !Double
    -- ^ ECEF Y coordinate
  , _msgPosEcef_z      :: !Double
    -- ^ ECEF Z coordinate
  , _msgPosEcef_accuracy :: !Word16
    -- ^ Position estimated standard deviation
  , _msgPosEcef_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgPosEcef_flags  :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgPosEcef where
  get = do
    _msgPosEcef_tow <- getWord32le
    _msgPosEcef_x <- getFloat64le
    _msgPosEcef_y <- getFloat64le
    _msgPosEcef_z <- getFloat64le
    _msgPosEcef_accuracy <- getWord16le
    _msgPosEcef_n_sats <- getWord8
    _msgPosEcef_flags <- getWord8
    pure MsgPosEcef {..}

  put MsgPosEcef {..} = do
    putWord32le _msgPosEcef_tow
    putFloat64le _msgPosEcef_x
    putFloat64le _msgPosEcef_y
    putFloat64le _msgPosEcef_z
    putWord16le _msgPosEcef_accuracy
    putWord8 _msgPosEcef_n_sats
    putWord8 _msgPosEcef_flags

$(makeSBP 'msgPosEcef ''MsgPosEcef)
$(makeJSON "_msgPosEcef_" ''MsgPosEcef)
$(makeLenses ''MsgPosEcef)

msgPosEcefCov :: Word16
msgPosEcefCov = 0x0214

-- | SBP class for message MSG_POS_ECEF_COV (0x0214).
--
-- The position solution message reports absolute Earth Centered Earth Fixed
-- (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
-- the position solution. The message also reports the upper triangular portion
-- of the 3x3 covariance matrix. If the receiver knows the surveyed position of
-- the base station and has an RTK solution, this reports a pseudo-absolute
-- position solution using the base station position and the rover's RTK
-- baseline vector. The full GPS time is given by the preceding MSG_GPS_TIME
-- with the matching time-of-week (tow).
data MsgPosEcefCov = MsgPosEcefCov
  { _msgPosEcefCov_tow   :: !Word32
    -- ^ GPS Time of Week
  , _msgPosEcefCov_x     :: !Double
    -- ^ ECEF X coordinate
  , _msgPosEcefCov_y     :: !Double
    -- ^ ECEF Y coordinate
  , _msgPosEcefCov_z     :: !Double
    -- ^ ECEF Z coordinate
  , _msgPosEcefCov_cov_x_x :: !Float
    -- ^ Estimated variance of x
  , _msgPosEcefCov_cov_x_y :: !Float
    -- ^ Estimated covariance of x and y
  , _msgPosEcefCov_cov_x_z :: !Float
    -- ^ Estimated covariance of x and z
  , _msgPosEcefCov_cov_y_y :: !Float
    -- ^ Estimated variance of y
  , _msgPosEcefCov_cov_y_z :: !Float
    -- ^ Estimated covariance of y and z
  , _msgPosEcefCov_cov_z_z :: !Float
    -- ^ Estimated variance of z
  , _msgPosEcefCov_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgPosEcefCov_flags :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgPosEcefCov where
  get = do
    _msgPosEcefCov_tow <- getWord32le
    _msgPosEcefCov_x <- getFloat64le
    _msgPosEcefCov_y <- getFloat64le
    _msgPosEcefCov_z <- getFloat64le
    _msgPosEcefCov_cov_x_x <- getFloat32le
    _msgPosEcefCov_cov_x_y <- getFloat32le
    _msgPosEcefCov_cov_x_z <- getFloat32le
    _msgPosEcefCov_cov_y_y <- getFloat32le
    _msgPosEcefCov_cov_y_z <- getFloat32le
    _msgPosEcefCov_cov_z_z <- getFloat32le
    _msgPosEcefCov_n_sats <- getWord8
    _msgPosEcefCov_flags <- getWord8
    pure MsgPosEcefCov {..}

  put MsgPosEcefCov {..} = do
    putWord32le _msgPosEcefCov_tow
    putFloat64le _msgPosEcefCov_x
    putFloat64le _msgPosEcefCov_y
    putFloat64le _msgPosEcefCov_z
    putFloat32le _msgPosEcefCov_cov_x_x
    putFloat32le _msgPosEcefCov_cov_x_y
    putFloat32le _msgPosEcefCov_cov_x_z
    putFloat32le _msgPosEcefCov_cov_y_y
    putFloat32le _msgPosEcefCov_cov_y_z
    putFloat32le _msgPosEcefCov_cov_z_z
    putWord8 _msgPosEcefCov_n_sats
    putWord8 _msgPosEcefCov_flags

$(makeSBP 'msgPosEcefCov ''MsgPosEcefCov)
$(makeJSON "_msgPosEcefCov_" ''MsgPosEcefCov)
$(makeLenses ''MsgPosEcefCov)

msgPosLlh :: Word16
msgPosLlh = 0x020A

-- | SBP class for message MSG_POS_LLH (0x020A).
--
-- This position solution message reports the absolute geodetic coordinates and
-- the status (single point vs pseudo-absolute RTK) of the position solution.
-- If the rover receiver knows the surveyed position of the base station and
-- has an RTK solution, this reports a pseudo-absolute position solution using
-- the base station position and the rover's RTK baseline vector. The full GPS
-- time is given by the preceding MSG_GPS_TIME with the matching time-of-week
-- (tow).
data MsgPosLlh = MsgPosLlh
  { _msgPosLlh_tow      :: !Word32
    -- ^ GPS Time of Week
  , _msgPosLlh_lat      :: !Double
    -- ^ Latitude
  , _msgPosLlh_lon      :: !Double
    -- ^ Longitude
  , _msgPosLlh_height   :: !Double
    -- ^ Height above WGS84 ellipsoid
  , _msgPosLlh_h_accuracy :: !Word16
    -- ^ Horizontal position estimated standard deviation
  , _msgPosLlh_v_accuracy :: !Word16
    -- ^ Vertical position estimated standard deviation
  , _msgPosLlh_n_sats   :: !Word8
    -- ^ Number of satellites used in solution.
  , _msgPosLlh_flags    :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgPosLlh where
  get = do
    _msgPosLlh_tow <- getWord32le
    _msgPosLlh_lat <- getFloat64le
    _msgPosLlh_lon <- getFloat64le
    _msgPosLlh_height <- getFloat64le
    _msgPosLlh_h_accuracy <- getWord16le
    _msgPosLlh_v_accuracy <- getWord16le
    _msgPosLlh_n_sats <- getWord8
    _msgPosLlh_flags <- getWord8
    pure MsgPosLlh {..}

  put MsgPosLlh {..} = do
    putWord32le _msgPosLlh_tow
    putFloat64le _msgPosLlh_lat
    putFloat64le _msgPosLlh_lon
    putFloat64le _msgPosLlh_height
    putWord16le _msgPosLlh_h_accuracy
    putWord16le _msgPosLlh_v_accuracy
    putWord8 _msgPosLlh_n_sats
    putWord8 _msgPosLlh_flags

$(makeSBP 'msgPosLlh ''MsgPosLlh)
$(makeJSON "_msgPosLlh_" ''MsgPosLlh)
$(makeLenses ''MsgPosLlh)

msgPosLlhCov :: Word16
msgPosLlhCov = 0x0211

-- | SBP class for message MSG_POS_LLH_COV (0x0211).
--
-- This position solution message reports the absolute geodetic coordinates and
-- the status (single point vs pseudo-absolute RTK) of the position solution as
-- well as the upper triangle of the 3x3 covariance matrix.  The position
-- information and Fix Mode flags should follow the MSG_POS_LLH message.  Since
-- the covariance matrix is computed in the local-level North, East, Down
-- frame, the covariance terms follow with that convention. Thus, covariances
-- are reported against the "downward" measurement and care should be taken
-- with the sign convention.
data MsgPosLlhCov = MsgPosLlhCov
  { _msgPosLlhCov_tow   :: !Word32
    -- ^ GPS Time of Week
  , _msgPosLlhCov_lat   :: !Double
    -- ^ Latitude
  , _msgPosLlhCov_lon   :: !Double
    -- ^ Longitude
  , _msgPosLlhCov_height :: !Double
    -- ^ Height above WGS84 ellipsoid
  , _msgPosLlhCov_cov_n_n :: !Float
    -- ^ Estimated variance of northing
  , _msgPosLlhCov_cov_n_e :: !Float
    -- ^ Covariance of northing and easting
  , _msgPosLlhCov_cov_n_d :: !Float
    -- ^ Covariance of northing and downward measurement
  , _msgPosLlhCov_cov_e_e :: !Float
    -- ^ Estimated variance of easting
  , _msgPosLlhCov_cov_e_d :: !Float
    -- ^ Covariance of easting and downward measurement
  , _msgPosLlhCov_cov_d_d :: !Float
    -- ^ Estimated variance of downward measurement
  , _msgPosLlhCov_n_sats :: !Word8
    -- ^ Number of satellites used in solution.
  , _msgPosLlhCov_flags :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgPosLlhCov where
  get = do
    _msgPosLlhCov_tow <- getWord32le
    _msgPosLlhCov_lat <- getFloat64le
    _msgPosLlhCov_lon <- getFloat64le
    _msgPosLlhCov_height <- getFloat64le
    _msgPosLlhCov_cov_n_n <- getFloat32le
    _msgPosLlhCov_cov_n_e <- getFloat32le
    _msgPosLlhCov_cov_n_d <- getFloat32le
    _msgPosLlhCov_cov_e_e <- getFloat32le
    _msgPosLlhCov_cov_e_d <- getFloat32le
    _msgPosLlhCov_cov_d_d <- getFloat32le
    _msgPosLlhCov_n_sats <- getWord8
    _msgPosLlhCov_flags <- getWord8
    pure MsgPosLlhCov {..}

  put MsgPosLlhCov {..} = do
    putWord32le _msgPosLlhCov_tow
    putFloat64le _msgPosLlhCov_lat
    putFloat64le _msgPosLlhCov_lon
    putFloat64le _msgPosLlhCov_height
    putFloat32le _msgPosLlhCov_cov_n_n
    putFloat32le _msgPosLlhCov_cov_n_e
    putFloat32le _msgPosLlhCov_cov_n_d
    putFloat32le _msgPosLlhCov_cov_e_e
    putFloat32le _msgPosLlhCov_cov_e_d
    putFloat32le _msgPosLlhCov_cov_d_d
    putWord8 _msgPosLlhCov_n_sats
    putWord8 _msgPosLlhCov_flags

$(makeSBP 'msgPosLlhCov ''MsgPosLlhCov)
$(makeJSON "_msgPosLlhCov_" ''MsgPosLlhCov)
$(makeLenses ''MsgPosLlhCov)

msgBaselineEcef :: Word16
msgBaselineEcef = 0x020B

-- | SBP class for message MSG_BASELINE_ECEF (0x020B).
--
-- This message reports the baseline solution in Earth Centered Earth Fixed
-- (ECEF) coordinates. This baseline is the relative vector distance from the
-- base station to the rover receiver. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow).
data MsgBaselineEcef = MsgBaselineEcef
  { _msgBaselineEcef_tow    :: !Word32
    -- ^ GPS Time of Week
  , _msgBaselineEcef_x      :: !Int32
    -- ^ Baseline ECEF X coordinate
  , _msgBaselineEcef_y      :: !Int32
    -- ^ Baseline ECEF Y coordinate
  , _msgBaselineEcef_z      :: !Int32
    -- ^ Baseline ECEF Z coordinate
  , _msgBaselineEcef_accuracy :: !Word16
    -- ^ Position estimated standard deviation
  , _msgBaselineEcef_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgBaselineEcef_flags  :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgBaselineEcef where
  get = do
    _msgBaselineEcef_tow <- getWord32le
    _msgBaselineEcef_x <- fromIntegral <$> getWord32le
    _msgBaselineEcef_y <- fromIntegral <$> getWord32le
    _msgBaselineEcef_z <- fromIntegral <$> getWord32le
    _msgBaselineEcef_accuracy <- getWord16le
    _msgBaselineEcef_n_sats <- getWord8
    _msgBaselineEcef_flags <- getWord8
    pure MsgBaselineEcef {..}

  put MsgBaselineEcef {..} = do
    putWord32le _msgBaselineEcef_tow
    (putWord32le . fromIntegral) _msgBaselineEcef_x
    (putWord32le . fromIntegral) _msgBaselineEcef_y
    (putWord32le . fromIntegral) _msgBaselineEcef_z
    putWord16le _msgBaselineEcef_accuracy
    putWord8 _msgBaselineEcef_n_sats
    putWord8 _msgBaselineEcef_flags

$(makeSBP 'msgBaselineEcef ''MsgBaselineEcef)
$(makeJSON "_msgBaselineEcef_" ''MsgBaselineEcef)
$(makeLenses ''MsgBaselineEcef)

msgBaselineNed :: Word16
msgBaselineNed = 0x020C

-- | SBP class for message MSG_BASELINE_NED (0x020C).
--
-- This message reports the baseline solution in North East Down (NED)
-- coordinates. This baseline is the relative vector distance from the base
-- station to the rover receiver, and NED coordinate system is defined at the
-- local WGS84 tangent plane centered at the base station position.  The full
-- GPS time is given by the preceding MSG_GPS_TIME with the matching time-of-
-- week (tow).
data MsgBaselineNed = MsgBaselineNed
  { _msgBaselineNed_tow      :: !Word32
    -- ^ GPS Time of Week
  , _msgBaselineNed_n        :: !Int32
    -- ^ Baseline North coordinate
  , _msgBaselineNed_e        :: !Int32
    -- ^ Baseline East coordinate
  , _msgBaselineNed_d        :: !Int32
    -- ^ Baseline Down coordinate
  , _msgBaselineNed_h_accuracy :: !Word16
    -- ^ Horizontal position estimated standard deviation
  , _msgBaselineNed_v_accuracy :: !Word16
    -- ^ Vertical position estimated standard deviation
  , _msgBaselineNed_n_sats   :: !Word8
    -- ^ Number of satellites used in solution
  , _msgBaselineNed_flags    :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgBaselineNed where
  get = do
    _msgBaselineNed_tow <- getWord32le
    _msgBaselineNed_n <- fromIntegral <$> getWord32le
    _msgBaselineNed_e <- fromIntegral <$> getWord32le
    _msgBaselineNed_d <- fromIntegral <$> getWord32le
    _msgBaselineNed_h_accuracy <- getWord16le
    _msgBaselineNed_v_accuracy <- getWord16le
    _msgBaselineNed_n_sats <- getWord8
    _msgBaselineNed_flags <- getWord8
    pure MsgBaselineNed {..}

  put MsgBaselineNed {..} = do
    putWord32le _msgBaselineNed_tow
    (putWord32le . fromIntegral) _msgBaselineNed_n
    (putWord32le . fromIntegral) _msgBaselineNed_e
    (putWord32le . fromIntegral) _msgBaselineNed_d
    putWord16le _msgBaselineNed_h_accuracy
    putWord16le _msgBaselineNed_v_accuracy
    putWord8 _msgBaselineNed_n_sats
    putWord8 _msgBaselineNed_flags

$(makeSBP 'msgBaselineNed ''MsgBaselineNed)
$(makeJSON "_msgBaselineNed_" ''MsgBaselineNed)
$(makeLenses ''MsgBaselineNed)

msgVelEcef :: Word16
msgVelEcef = 0x020D

-- | SBP class for message MSG_VEL_ECEF (0x020D).
--
-- This message reports the velocity in Earth Centered Earth Fixed (ECEF)
-- coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
-- the matching time-of-week (tow).
data MsgVelEcef = MsgVelEcef
  { _msgVelEcef_tow    :: !Word32
    -- ^ GPS Time of Week
  , _msgVelEcef_x      :: !Int32
    -- ^ Velocity ECEF X coordinate
  , _msgVelEcef_y      :: !Int32
    -- ^ Velocity ECEF Y coordinate
  , _msgVelEcef_z      :: !Int32
    -- ^ Velocity ECEF Z coordinate
  , _msgVelEcef_accuracy :: !Word16
    -- ^ Velocity estimated standard deviation
  , _msgVelEcef_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgVelEcef_flags  :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgVelEcef where
  get = do
    _msgVelEcef_tow <- getWord32le
    _msgVelEcef_x <- fromIntegral <$> getWord32le
    _msgVelEcef_y <- fromIntegral <$> getWord32le
    _msgVelEcef_z <- fromIntegral <$> getWord32le
    _msgVelEcef_accuracy <- getWord16le
    _msgVelEcef_n_sats <- getWord8
    _msgVelEcef_flags <- getWord8
    pure MsgVelEcef {..}

  put MsgVelEcef {..} = do
    putWord32le _msgVelEcef_tow
    (putWord32le . fromIntegral) _msgVelEcef_x
    (putWord32le . fromIntegral) _msgVelEcef_y
    (putWord32le . fromIntegral) _msgVelEcef_z
    putWord16le _msgVelEcef_accuracy
    putWord8 _msgVelEcef_n_sats
    putWord8 _msgVelEcef_flags

$(makeSBP 'msgVelEcef ''MsgVelEcef)
$(makeJSON "_msgVelEcef_" ''MsgVelEcef)
$(makeLenses ''MsgVelEcef)

msgVelEcefCov :: Word16
msgVelEcefCov = 0x0215

-- | SBP class for message MSG_VEL_ECEF_COV (0x0215).
--
-- This message reports the velocity in Earth Centered Earth Fixed (ECEF)
-- coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
-- the matching time-of-week (tow).
data MsgVelEcefCov = MsgVelEcefCov
  { _msgVelEcefCov_tow   :: !Word32
    -- ^ GPS Time of Week
  , _msgVelEcefCov_x     :: !Int32
    -- ^ Velocity ECEF X coordinate
  , _msgVelEcefCov_y     :: !Int32
    -- ^ Velocity ECEF Y coordinate
  , _msgVelEcefCov_z     :: !Int32
    -- ^ Velocity ECEF Z coordinate
  , _msgVelEcefCov_cov_x_x :: !Float
    -- ^ Estimated variance of x
  , _msgVelEcefCov_cov_x_y :: !Float
    -- ^ Estimated covariance of x and y
  , _msgVelEcefCov_cov_x_z :: !Float
    -- ^ Estimated covariance of x and z
  , _msgVelEcefCov_cov_y_y :: !Float
    -- ^ Estimated variance of y
  , _msgVelEcefCov_cov_y_z :: !Float
    -- ^ Estimated covariance of y and z
  , _msgVelEcefCov_cov_z_z :: !Float
    -- ^ Estimated variance of z
  , _msgVelEcefCov_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgVelEcefCov_flags :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgVelEcefCov where
  get = do
    _msgVelEcefCov_tow <- getWord32le
    _msgVelEcefCov_x <- fromIntegral <$> getWord32le
    _msgVelEcefCov_y <- fromIntegral <$> getWord32le
    _msgVelEcefCov_z <- fromIntegral <$> getWord32le
    _msgVelEcefCov_cov_x_x <- getFloat32le
    _msgVelEcefCov_cov_x_y <- getFloat32le
    _msgVelEcefCov_cov_x_z <- getFloat32le
    _msgVelEcefCov_cov_y_y <- getFloat32le
    _msgVelEcefCov_cov_y_z <- getFloat32le
    _msgVelEcefCov_cov_z_z <- getFloat32le
    _msgVelEcefCov_n_sats <- getWord8
    _msgVelEcefCov_flags <- getWord8
    pure MsgVelEcefCov {..}

  put MsgVelEcefCov {..} = do
    putWord32le _msgVelEcefCov_tow
    (putWord32le . fromIntegral) _msgVelEcefCov_x
    (putWord32le . fromIntegral) _msgVelEcefCov_y
    (putWord32le . fromIntegral) _msgVelEcefCov_z
    putFloat32le _msgVelEcefCov_cov_x_x
    putFloat32le _msgVelEcefCov_cov_x_y
    putFloat32le _msgVelEcefCov_cov_x_z
    putFloat32le _msgVelEcefCov_cov_y_y
    putFloat32le _msgVelEcefCov_cov_y_z
    putFloat32le _msgVelEcefCov_cov_z_z
    putWord8 _msgVelEcefCov_n_sats
    putWord8 _msgVelEcefCov_flags

$(makeSBP 'msgVelEcefCov ''MsgVelEcefCov)
$(makeJSON "_msgVelEcefCov_" ''MsgVelEcefCov)
$(makeLenses ''MsgVelEcefCov)

msgVelNed :: Word16
msgVelNed = 0x020E

-- | SBP class for message MSG_VEL_NED (0x020E).
--
-- This message reports the velocity in local North East Down (NED)
-- coordinates. The NED coordinate system is defined as the local WGS84 tangent
-- plane centered at the current position. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow).
data MsgVelNed = MsgVelNed
  { _msgVelNed_tow      :: !Word32
    -- ^ GPS Time of Week
  , _msgVelNed_n        :: !Int32
    -- ^ Velocity North coordinate
  , _msgVelNed_e        :: !Int32
    -- ^ Velocity East coordinate
  , _msgVelNed_d        :: !Int32
    -- ^ Velocity Down coordinate
  , _msgVelNed_h_accuracy :: !Word16
    -- ^ Horizontal velocity estimated standard deviation
  , _msgVelNed_v_accuracy :: !Word16
    -- ^ Vertical velocity estimated standard deviation
  , _msgVelNed_n_sats   :: !Word8
    -- ^ Number of satellites used in solution
  , _msgVelNed_flags    :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgVelNed where
  get = do
    _msgVelNed_tow <- getWord32le
    _msgVelNed_n <- fromIntegral <$> getWord32le
    _msgVelNed_e <- fromIntegral <$> getWord32le
    _msgVelNed_d <- fromIntegral <$> getWord32le
    _msgVelNed_h_accuracy <- getWord16le
    _msgVelNed_v_accuracy <- getWord16le
    _msgVelNed_n_sats <- getWord8
    _msgVelNed_flags <- getWord8
    pure MsgVelNed {..}

  put MsgVelNed {..} = do
    putWord32le _msgVelNed_tow
    (putWord32le . fromIntegral) _msgVelNed_n
    (putWord32le . fromIntegral) _msgVelNed_e
    (putWord32le . fromIntegral) _msgVelNed_d
    putWord16le _msgVelNed_h_accuracy
    putWord16le _msgVelNed_v_accuracy
    putWord8 _msgVelNed_n_sats
    putWord8 _msgVelNed_flags

$(makeSBP 'msgVelNed ''MsgVelNed)
$(makeJSON "_msgVelNed_" ''MsgVelNed)
$(makeLenses ''MsgVelNed)

msgVelNedCov :: Word16
msgVelNedCov = 0x0212

-- | SBP class for message MSG_VEL_NED_COV (0x0212).
--
-- This message reports the velocity in local North East Down (NED)
-- coordinates. The NED coordinate system is defined as the local WGS84 tangent
-- plane centered at the current position. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow). This message is
-- similar to the MSG_VEL_NED, but it includes the upper triangular portion of
-- the 3x3 covariance matrix.
data MsgVelNedCov = MsgVelNedCov
  { _msgVelNedCov_tow   :: !Word32
    -- ^ GPS Time of Week
  , _msgVelNedCov_n     :: !Int32
    -- ^ Velocity North coordinate
  , _msgVelNedCov_e     :: !Int32
    -- ^ Velocity East coordinate
  , _msgVelNedCov_d     :: !Int32
    -- ^ Velocity Down coordinate
  , _msgVelNedCov_cov_n_n :: !Float
    -- ^ Estimated variance of northward measurement
  , _msgVelNedCov_cov_n_e :: !Float
    -- ^ Covariance of northward and eastward measurement
  , _msgVelNedCov_cov_n_d :: !Float
    -- ^ Covariance of northward and downward measurement
  , _msgVelNedCov_cov_e_e :: !Float
    -- ^ Estimated variance of eastward measurement
  , _msgVelNedCov_cov_e_d :: !Float
    -- ^ Covariance of eastward and downward measurement
  , _msgVelNedCov_cov_d_d :: !Float
    -- ^ Estimated variance of downward measurement
  , _msgVelNedCov_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgVelNedCov_flags :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgVelNedCov where
  get = do
    _msgVelNedCov_tow <- getWord32le
    _msgVelNedCov_n <- fromIntegral <$> getWord32le
    _msgVelNedCov_e <- fromIntegral <$> getWord32le
    _msgVelNedCov_d <- fromIntegral <$> getWord32le
    _msgVelNedCov_cov_n_n <- getFloat32le
    _msgVelNedCov_cov_n_e <- getFloat32le
    _msgVelNedCov_cov_n_d <- getFloat32le
    _msgVelNedCov_cov_e_e <- getFloat32le
    _msgVelNedCov_cov_e_d <- getFloat32le
    _msgVelNedCov_cov_d_d <- getFloat32le
    _msgVelNedCov_n_sats <- getWord8
    _msgVelNedCov_flags <- getWord8
    pure MsgVelNedCov {..}

  put MsgVelNedCov {..} = do
    putWord32le _msgVelNedCov_tow
    (putWord32le . fromIntegral) _msgVelNedCov_n
    (putWord32le . fromIntegral) _msgVelNedCov_e
    (putWord32le . fromIntegral) _msgVelNedCov_d
    putFloat32le _msgVelNedCov_cov_n_n
    putFloat32le _msgVelNedCov_cov_n_e
    putFloat32le _msgVelNedCov_cov_n_d
    putFloat32le _msgVelNedCov_cov_e_e
    putFloat32le _msgVelNedCov_cov_e_d
    putFloat32le _msgVelNedCov_cov_d_d
    putWord8 _msgVelNedCov_n_sats
    putWord8 _msgVelNedCov_flags

$(makeSBP 'msgVelNedCov ''MsgVelNedCov)
$(makeJSON "_msgVelNedCov_" ''MsgVelNedCov)
$(makeLenses ''MsgVelNedCov)

msgPosEcefGnss :: Word16
msgPosEcefGnss = 0x0229

-- | SBP class for message MSG_POS_ECEF_GNSS (0x0229).
--
-- The position solution message reports absolute Earth Centered Earth Fixed
-- (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
-- the position solution. If the rover receiver knows the surveyed position of
-- the base station and has an RTK solution, this reports a pseudo-absolute
-- position solution using the base station position and the rover's RTK
-- baseline vector. The full GPS time is given by the preceding MSG_GPS_TIME
-- with the matching time-of-week (tow).
data MsgPosEcefGnss = MsgPosEcefGnss
  { _msgPosEcefGnss_tow    :: !Word32
    -- ^ GPS Time of Week
  , _msgPosEcefGnss_x      :: !Double
    -- ^ ECEF X coordinate
  , _msgPosEcefGnss_y      :: !Double
    -- ^ ECEF Y coordinate
  , _msgPosEcefGnss_z      :: !Double
    -- ^ ECEF Z coordinate
  , _msgPosEcefGnss_accuracy :: !Word16
    -- ^ Position estimated standard deviation
  , _msgPosEcefGnss_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgPosEcefGnss_flags  :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgPosEcefGnss where
  get = do
    _msgPosEcefGnss_tow <- getWord32le
    _msgPosEcefGnss_x <- getFloat64le
    _msgPosEcefGnss_y <- getFloat64le
    _msgPosEcefGnss_z <- getFloat64le
    _msgPosEcefGnss_accuracy <- getWord16le
    _msgPosEcefGnss_n_sats <- getWord8
    _msgPosEcefGnss_flags <- getWord8
    pure MsgPosEcefGnss {..}

  put MsgPosEcefGnss {..} = do
    putWord32le _msgPosEcefGnss_tow
    putFloat64le _msgPosEcefGnss_x
    putFloat64le _msgPosEcefGnss_y
    putFloat64le _msgPosEcefGnss_z
    putWord16le _msgPosEcefGnss_accuracy
    putWord8 _msgPosEcefGnss_n_sats
    putWord8 _msgPosEcefGnss_flags

$(makeSBP 'msgPosEcefGnss ''MsgPosEcefGnss)
$(makeJSON "_msgPosEcefGnss_" ''MsgPosEcefGnss)
$(makeLenses ''MsgPosEcefGnss)

msgPosEcefCovGnss :: Word16
msgPosEcefCovGnss = 0x0234

-- | SBP class for message MSG_POS_ECEF_COV_GNSS (0x0234).
--
-- The position solution message reports absolute Earth Centered Earth Fixed
-- (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
-- the position solution. The message also reports the upper triangular portion
-- of the 3x3 covariance matrix. If the receiver knows the surveyed position of
-- the base station and has an RTK solution, this reports a pseudo-absolute
-- position solution using the base station position and the rover's RTK
-- baseline vector. The full GPS time is given by the preceding MSG_GPS_TIME
-- with the matching time-of-week (tow).
data MsgPosEcefCovGnss = MsgPosEcefCovGnss
  { _msgPosEcefCovGnss_tow   :: !Word32
    -- ^ GPS Time of Week
  , _msgPosEcefCovGnss_x     :: !Double
    -- ^ ECEF X coordinate
  , _msgPosEcefCovGnss_y     :: !Double
    -- ^ ECEF Y coordinate
  , _msgPosEcefCovGnss_z     :: !Double
    -- ^ ECEF Z coordinate
  , _msgPosEcefCovGnss_cov_x_x :: !Float
    -- ^ Estimated variance of x
  , _msgPosEcefCovGnss_cov_x_y :: !Float
    -- ^ Estimated covariance of x and y
  , _msgPosEcefCovGnss_cov_x_z :: !Float
    -- ^ Estimated covariance of x and z
  , _msgPosEcefCovGnss_cov_y_y :: !Float
    -- ^ Estimated variance of y
  , _msgPosEcefCovGnss_cov_y_z :: !Float
    -- ^ Estimated covariance of y and z
  , _msgPosEcefCovGnss_cov_z_z :: !Float
    -- ^ Estimated variance of z
  , _msgPosEcefCovGnss_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgPosEcefCovGnss_flags :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgPosEcefCovGnss where
  get = do
    _msgPosEcefCovGnss_tow <- getWord32le
    _msgPosEcefCovGnss_x <- getFloat64le
    _msgPosEcefCovGnss_y <- getFloat64le
    _msgPosEcefCovGnss_z <- getFloat64le
    _msgPosEcefCovGnss_cov_x_x <- getFloat32le
    _msgPosEcefCovGnss_cov_x_y <- getFloat32le
    _msgPosEcefCovGnss_cov_x_z <- getFloat32le
    _msgPosEcefCovGnss_cov_y_y <- getFloat32le
    _msgPosEcefCovGnss_cov_y_z <- getFloat32le
    _msgPosEcefCovGnss_cov_z_z <- getFloat32le
    _msgPosEcefCovGnss_n_sats <- getWord8
    _msgPosEcefCovGnss_flags <- getWord8
    pure MsgPosEcefCovGnss {..}

  put MsgPosEcefCovGnss {..} = do
    putWord32le _msgPosEcefCovGnss_tow
    putFloat64le _msgPosEcefCovGnss_x
    putFloat64le _msgPosEcefCovGnss_y
    putFloat64le _msgPosEcefCovGnss_z
    putFloat32le _msgPosEcefCovGnss_cov_x_x
    putFloat32le _msgPosEcefCovGnss_cov_x_y
    putFloat32le _msgPosEcefCovGnss_cov_x_z
    putFloat32le _msgPosEcefCovGnss_cov_y_y
    putFloat32le _msgPosEcefCovGnss_cov_y_z
    putFloat32le _msgPosEcefCovGnss_cov_z_z
    putWord8 _msgPosEcefCovGnss_n_sats
    putWord8 _msgPosEcefCovGnss_flags

$(makeSBP 'msgPosEcefCovGnss ''MsgPosEcefCovGnss)
$(makeJSON "_msgPosEcefCovGnss_" ''MsgPosEcefCovGnss)
$(makeLenses ''MsgPosEcefCovGnss)

msgPosLlhGnss :: Word16
msgPosLlhGnss = 0x022A

-- | SBP class for message MSG_POS_LLH_GNSS (0x022A).
--
-- This position solution message reports the absolute geodetic coordinates and
-- the status (single point vs pseudo-absolute RTK) of the position solution.
-- If the rover receiver knows the surveyed position of the base station and
-- has an RTK solution, this reports a pseudo-absolute position solution using
-- the base station position and the rover's RTK baseline vector. The full GPS
-- time is given by the preceding MSG_GPS_TIME with the matching time-of-week
-- (tow).
data MsgPosLlhGnss = MsgPosLlhGnss
  { _msgPosLlhGnss_tow      :: !Word32
    -- ^ GPS Time of Week
  , _msgPosLlhGnss_lat      :: !Double
    -- ^ Latitude
  , _msgPosLlhGnss_lon      :: !Double
    -- ^ Longitude
  , _msgPosLlhGnss_height   :: !Double
    -- ^ Height above WGS84 ellipsoid
  , _msgPosLlhGnss_h_accuracy :: !Word16
    -- ^ Horizontal position estimated standard deviation
  , _msgPosLlhGnss_v_accuracy :: !Word16
    -- ^ Vertical position estimated standard deviation
  , _msgPosLlhGnss_n_sats   :: !Word8
    -- ^ Number of satellites used in solution.
  , _msgPosLlhGnss_flags    :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgPosLlhGnss where
  get = do
    _msgPosLlhGnss_tow <- getWord32le
    _msgPosLlhGnss_lat <- getFloat64le
    _msgPosLlhGnss_lon <- getFloat64le
    _msgPosLlhGnss_height <- getFloat64le
    _msgPosLlhGnss_h_accuracy <- getWord16le
    _msgPosLlhGnss_v_accuracy <- getWord16le
    _msgPosLlhGnss_n_sats <- getWord8
    _msgPosLlhGnss_flags <- getWord8
    pure MsgPosLlhGnss {..}

  put MsgPosLlhGnss {..} = do
    putWord32le _msgPosLlhGnss_tow
    putFloat64le _msgPosLlhGnss_lat
    putFloat64le _msgPosLlhGnss_lon
    putFloat64le _msgPosLlhGnss_height
    putWord16le _msgPosLlhGnss_h_accuracy
    putWord16le _msgPosLlhGnss_v_accuracy
    putWord8 _msgPosLlhGnss_n_sats
    putWord8 _msgPosLlhGnss_flags

$(makeSBP 'msgPosLlhGnss ''MsgPosLlhGnss)
$(makeJSON "_msgPosLlhGnss_" ''MsgPosLlhGnss)
$(makeLenses ''MsgPosLlhGnss)

msgPosLlhCovGnss :: Word16
msgPosLlhCovGnss = 0x0231

-- | SBP class for message MSG_POS_LLH_COV_GNSS (0x0231).
--
-- This position solution message reports the absolute geodetic coordinates and
-- the status (single point vs pseudo-absolute RTK) of the position solution as
-- well as the upper triangle of the 3x3 covariance matrix.  The position
-- information and Fix Mode flags should follow the MSG_POS_LLH message.  Since
-- the covariance matrix is computed in the local-level North, East, Down
-- frame, the covariance terms follow with that convention. Thus, covariances
-- are reported against the "downward" measurement and care should be taken
-- with the sign convention.
data MsgPosLlhCovGnss = MsgPosLlhCovGnss
  { _msgPosLlhCovGnss_tow   :: !Word32
    -- ^ GPS Time of Week
  , _msgPosLlhCovGnss_lat   :: !Double
    -- ^ Latitude
  , _msgPosLlhCovGnss_lon   :: !Double
    -- ^ Longitude
  , _msgPosLlhCovGnss_height :: !Double
    -- ^ Height above WGS84 ellipsoid
  , _msgPosLlhCovGnss_cov_n_n :: !Float
    -- ^ Estimated variance of northing
  , _msgPosLlhCovGnss_cov_n_e :: !Float
    -- ^ Covariance of northing and easting
  , _msgPosLlhCovGnss_cov_n_d :: !Float
    -- ^ Covariance of northing and downward measurement
  , _msgPosLlhCovGnss_cov_e_e :: !Float
    -- ^ Estimated variance of easting
  , _msgPosLlhCovGnss_cov_e_d :: !Float
    -- ^ Covariance of easting and downward measurement
  , _msgPosLlhCovGnss_cov_d_d :: !Float
    -- ^ Estimated variance of downward measurement
  , _msgPosLlhCovGnss_n_sats :: !Word8
    -- ^ Number of satellites used in solution.
  , _msgPosLlhCovGnss_flags :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgPosLlhCovGnss where
  get = do
    _msgPosLlhCovGnss_tow <- getWord32le
    _msgPosLlhCovGnss_lat <- getFloat64le
    _msgPosLlhCovGnss_lon <- getFloat64le
    _msgPosLlhCovGnss_height <- getFloat64le
    _msgPosLlhCovGnss_cov_n_n <- getFloat32le
    _msgPosLlhCovGnss_cov_n_e <- getFloat32le
    _msgPosLlhCovGnss_cov_n_d <- getFloat32le
    _msgPosLlhCovGnss_cov_e_e <- getFloat32le
    _msgPosLlhCovGnss_cov_e_d <- getFloat32le
    _msgPosLlhCovGnss_cov_d_d <- getFloat32le
    _msgPosLlhCovGnss_n_sats <- getWord8
    _msgPosLlhCovGnss_flags <- getWord8
    pure MsgPosLlhCovGnss {..}

  put MsgPosLlhCovGnss {..} = do
    putWord32le _msgPosLlhCovGnss_tow
    putFloat64le _msgPosLlhCovGnss_lat
    putFloat64le _msgPosLlhCovGnss_lon
    putFloat64le _msgPosLlhCovGnss_height
    putFloat32le _msgPosLlhCovGnss_cov_n_n
    putFloat32le _msgPosLlhCovGnss_cov_n_e
    putFloat32le _msgPosLlhCovGnss_cov_n_d
    putFloat32le _msgPosLlhCovGnss_cov_e_e
    putFloat32le _msgPosLlhCovGnss_cov_e_d
    putFloat32le _msgPosLlhCovGnss_cov_d_d
    putWord8 _msgPosLlhCovGnss_n_sats
    putWord8 _msgPosLlhCovGnss_flags

$(makeSBP 'msgPosLlhCovGnss ''MsgPosLlhCovGnss)
$(makeJSON "_msgPosLlhCovGnss_" ''MsgPosLlhCovGnss)
$(makeLenses ''MsgPosLlhCovGnss)

msgVelEcefGnss :: Word16
msgVelEcefGnss = 0x022D

-- | SBP class for message MSG_VEL_ECEF_GNSS (0x022D).
--
-- This message reports the velocity in Earth Centered Earth Fixed (ECEF)
-- coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
-- the matching time-of-week (tow).
data MsgVelEcefGnss = MsgVelEcefGnss
  { _msgVelEcefGnss_tow    :: !Word32
    -- ^ GPS Time of Week
  , _msgVelEcefGnss_x      :: !Int32
    -- ^ Velocity ECEF X coordinate
  , _msgVelEcefGnss_y      :: !Int32
    -- ^ Velocity ECEF Y coordinate
  , _msgVelEcefGnss_z      :: !Int32
    -- ^ Velocity ECEF Z coordinate
  , _msgVelEcefGnss_accuracy :: !Word16
    -- ^ Velocity estimated standard deviation
  , _msgVelEcefGnss_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgVelEcefGnss_flags  :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgVelEcefGnss where
  get = do
    _msgVelEcefGnss_tow <- getWord32le
    _msgVelEcefGnss_x <- fromIntegral <$> getWord32le
    _msgVelEcefGnss_y <- fromIntegral <$> getWord32le
    _msgVelEcefGnss_z <- fromIntegral <$> getWord32le
    _msgVelEcefGnss_accuracy <- getWord16le
    _msgVelEcefGnss_n_sats <- getWord8
    _msgVelEcefGnss_flags <- getWord8
    pure MsgVelEcefGnss {..}

  put MsgVelEcefGnss {..} = do
    putWord32le _msgVelEcefGnss_tow
    (putWord32le . fromIntegral) _msgVelEcefGnss_x
    (putWord32le . fromIntegral) _msgVelEcefGnss_y
    (putWord32le . fromIntegral) _msgVelEcefGnss_z
    putWord16le _msgVelEcefGnss_accuracy
    putWord8 _msgVelEcefGnss_n_sats
    putWord8 _msgVelEcefGnss_flags

$(makeSBP 'msgVelEcefGnss ''MsgVelEcefGnss)
$(makeJSON "_msgVelEcefGnss_" ''MsgVelEcefGnss)
$(makeLenses ''MsgVelEcefGnss)

msgVelEcefCovGnss :: Word16
msgVelEcefCovGnss = 0x0235

-- | SBP class for message MSG_VEL_ECEF_COV_GNSS (0x0235).
--
-- This message reports the velocity in Earth Centered Earth Fixed (ECEF)
-- coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
-- the matching time-of-week (tow).
data MsgVelEcefCovGnss = MsgVelEcefCovGnss
  { _msgVelEcefCovGnss_tow   :: !Word32
    -- ^ GPS Time of Week
  , _msgVelEcefCovGnss_x     :: !Int32
    -- ^ Velocity ECEF X coordinate
  , _msgVelEcefCovGnss_y     :: !Int32
    -- ^ Velocity ECEF Y coordinate
  , _msgVelEcefCovGnss_z     :: !Int32
    -- ^ Velocity ECEF Z coordinate
  , _msgVelEcefCovGnss_cov_x_x :: !Float
    -- ^ Estimated variance of x
  , _msgVelEcefCovGnss_cov_x_y :: !Float
    -- ^ Estimated covariance of x and y
  , _msgVelEcefCovGnss_cov_x_z :: !Float
    -- ^ Estimated covariance of x and z
  , _msgVelEcefCovGnss_cov_y_y :: !Float
    -- ^ Estimated variance of y
  , _msgVelEcefCovGnss_cov_y_z :: !Float
    -- ^ Estimated covariance of y and z
  , _msgVelEcefCovGnss_cov_z_z :: !Float
    -- ^ Estimated variance of z
  , _msgVelEcefCovGnss_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgVelEcefCovGnss_flags :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgVelEcefCovGnss where
  get = do
    _msgVelEcefCovGnss_tow <- getWord32le
    _msgVelEcefCovGnss_x <- fromIntegral <$> getWord32le
    _msgVelEcefCovGnss_y <- fromIntegral <$> getWord32le
    _msgVelEcefCovGnss_z <- fromIntegral <$> getWord32le
    _msgVelEcefCovGnss_cov_x_x <- getFloat32le
    _msgVelEcefCovGnss_cov_x_y <- getFloat32le
    _msgVelEcefCovGnss_cov_x_z <- getFloat32le
    _msgVelEcefCovGnss_cov_y_y <- getFloat32le
    _msgVelEcefCovGnss_cov_y_z <- getFloat32le
    _msgVelEcefCovGnss_cov_z_z <- getFloat32le
    _msgVelEcefCovGnss_n_sats <- getWord8
    _msgVelEcefCovGnss_flags <- getWord8
    pure MsgVelEcefCovGnss {..}

  put MsgVelEcefCovGnss {..} = do
    putWord32le _msgVelEcefCovGnss_tow
    (putWord32le . fromIntegral) _msgVelEcefCovGnss_x
    (putWord32le . fromIntegral) _msgVelEcefCovGnss_y
    (putWord32le . fromIntegral) _msgVelEcefCovGnss_z
    putFloat32le _msgVelEcefCovGnss_cov_x_x
    putFloat32le _msgVelEcefCovGnss_cov_x_y
    putFloat32le _msgVelEcefCovGnss_cov_x_z
    putFloat32le _msgVelEcefCovGnss_cov_y_y
    putFloat32le _msgVelEcefCovGnss_cov_y_z
    putFloat32le _msgVelEcefCovGnss_cov_z_z
    putWord8 _msgVelEcefCovGnss_n_sats
    putWord8 _msgVelEcefCovGnss_flags

$(makeSBP 'msgVelEcefCovGnss ''MsgVelEcefCovGnss)
$(makeJSON "_msgVelEcefCovGnss_" ''MsgVelEcefCovGnss)
$(makeLenses ''MsgVelEcefCovGnss)

msgVelNedGnss :: Word16
msgVelNedGnss = 0x022E

-- | SBP class for message MSG_VEL_NED_GNSS (0x022E).
--
-- This message reports the velocity in local North East Down (NED)
-- coordinates. The NED coordinate system is defined as the local WGS84 tangent
-- plane centered at the current position. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow).
data MsgVelNedGnss = MsgVelNedGnss
  { _msgVelNedGnss_tow      :: !Word32
    -- ^ GPS Time of Week
  , _msgVelNedGnss_n        :: !Int32
    -- ^ Velocity North coordinate
  , _msgVelNedGnss_e        :: !Int32
    -- ^ Velocity East coordinate
  , _msgVelNedGnss_d        :: !Int32
    -- ^ Velocity Down coordinate
  , _msgVelNedGnss_h_accuracy :: !Word16
    -- ^ Horizontal velocity estimated standard deviation
  , _msgVelNedGnss_v_accuracy :: !Word16
    -- ^ Vertical velocity estimated standard deviation
  , _msgVelNedGnss_n_sats   :: !Word8
    -- ^ Number of satellites used in solution
  , _msgVelNedGnss_flags    :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgVelNedGnss where
  get = do
    _msgVelNedGnss_tow <- getWord32le
    _msgVelNedGnss_n <- fromIntegral <$> getWord32le
    _msgVelNedGnss_e <- fromIntegral <$> getWord32le
    _msgVelNedGnss_d <- fromIntegral <$> getWord32le
    _msgVelNedGnss_h_accuracy <- getWord16le
    _msgVelNedGnss_v_accuracy <- getWord16le
    _msgVelNedGnss_n_sats <- getWord8
    _msgVelNedGnss_flags <- getWord8
    pure MsgVelNedGnss {..}

  put MsgVelNedGnss {..} = do
    putWord32le _msgVelNedGnss_tow
    (putWord32le . fromIntegral) _msgVelNedGnss_n
    (putWord32le . fromIntegral) _msgVelNedGnss_e
    (putWord32le . fromIntegral) _msgVelNedGnss_d
    putWord16le _msgVelNedGnss_h_accuracy
    putWord16le _msgVelNedGnss_v_accuracy
    putWord8 _msgVelNedGnss_n_sats
    putWord8 _msgVelNedGnss_flags

$(makeSBP 'msgVelNedGnss ''MsgVelNedGnss)
$(makeJSON "_msgVelNedGnss_" ''MsgVelNedGnss)
$(makeLenses ''MsgVelNedGnss)

msgVelNedCovGnss :: Word16
msgVelNedCovGnss = 0x0232

-- | SBP class for message MSG_VEL_NED_COV_GNSS (0x0232).
--
-- This message reports the velocity in local North East Down (NED)
-- coordinates. The NED coordinate system is defined as the local WGS84 tangent
-- plane centered at the current position. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow). This message is
-- similar to the MSG_VEL_NED, but it includes the upper triangular portion of
-- the 3x3 covariance matrix.
data MsgVelNedCovGnss = MsgVelNedCovGnss
  { _msgVelNedCovGnss_tow   :: !Word32
    -- ^ GPS Time of Week
  , _msgVelNedCovGnss_n     :: !Int32
    -- ^ Velocity North coordinate
  , _msgVelNedCovGnss_e     :: !Int32
    -- ^ Velocity East coordinate
  , _msgVelNedCovGnss_d     :: !Int32
    -- ^ Velocity Down coordinate
  , _msgVelNedCovGnss_cov_n_n :: !Float
    -- ^ Estimated variance of northward measurement
  , _msgVelNedCovGnss_cov_n_e :: !Float
    -- ^ Covariance of northward and eastward measurement
  , _msgVelNedCovGnss_cov_n_d :: !Float
    -- ^ Covariance of northward and downward measurement
  , _msgVelNedCovGnss_cov_e_e :: !Float
    -- ^ Estimated variance of eastward measurement
  , _msgVelNedCovGnss_cov_e_d :: !Float
    -- ^ Covariance of eastward and downward measurement
  , _msgVelNedCovGnss_cov_d_d :: !Float
    -- ^ Estimated variance of downward measurement
  , _msgVelNedCovGnss_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgVelNedCovGnss_flags :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgVelNedCovGnss where
  get = do
    _msgVelNedCovGnss_tow <- getWord32le
    _msgVelNedCovGnss_n <- fromIntegral <$> getWord32le
    _msgVelNedCovGnss_e <- fromIntegral <$> getWord32le
    _msgVelNedCovGnss_d <- fromIntegral <$> getWord32le
    _msgVelNedCovGnss_cov_n_n <- getFloat32le
    _msgVelNedCovGnss_cov_n_e <- getFloat32le
    _msgVelNedCovGnss_cov_n_d <- getFloat32le
    _msgVelNedCovGnss_cov_e_e <- getFloat32le
    _msgVelNedCovGnss_cov_e_d <- getFloat32le
    _msgVelNedCovGnss_cov_d_d <- getFloat32le
    _msgVelNedCovGnss_n_sats <- getWord8
    _msgVelNedCovGnss_flags <- getWord8
    pure MsgVelNedCovGnss {..}

  put MsgVelNedCovGnss {..} = do
    putWord32le _msgVelNedCovGnss_tow
    (putWord32le . fromIntegral) _msgVelNedCovGnss_n
    (putWord32le . fromIntegral) _msgVelNedCovGnss_e
    (putWord32le . fromIntegral) _msgVelNedCovGnss_d
    putFloat32le _msgVelNedCovGnss_cov_n_n
    putFloat32le _msgVelNedCovGnss_cov_n_e
    putFloat32le _msgVelNedCovGnss_cov_n_d
    putFloat32le _msgVelNedCovGnss_cov_e_e
    putFloat32le _msgVelNedCovGnss_cov_e_d
    putFloat32le _msgVelNedCovGnss_cov_d_d
    putWord8 _msgVelNedCovGnss_n_sats
    putWord8 _msgVelNedCovGnss_flags

$(makeSBP 'msgVelNedCovGnss ''MsgVelNedCovGnss)
$(makeJSON "_msgVelNedCovGnss_" ''MsgVelNedCovGnss)
$(makeLenses ''MsgVelNedCovGnss)

msgVelBody :: Word16
msgVelBody = 0x0213

-- | SBP class for message MSG_VEL_BODY (0x0213).
--
-- This message reports the velocity in the Vehicle Body Frame. By convention,
-- the x-axis should point out the nose of the vehicle and represent the
-- forward direction, while as the y-axis should point out the right hand side
-- of the vehicle. Since this is a right handed system, z should point out the
-- bottom of the vehicle. The orientation and origin of the Vehicle Body Frame
-- are specified via the device settings. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow). This message is
-- only produced by inertial versions of Swift products and is not available
-- from Piksi Multi or Duro.
data MsgVelBody = MsgVelBody
  { _msgVelBody_tow   :: !Word32
    -- ^ GPS Time of Week
  , _msgVelBody_x     :: !Int32
    -- ^ Velocity in x direction
  , _msgVelBody_y     :: !Int32
    -- ^ Velocity in y direction
  , _msgVelBody_z     :: !Int32
    -- ^ Velocity in z direction
  , _msgVelBody_cov_x_x :: !Float
    -- ^ Estimated variance of x
  , _msgVelBody_cov_x_y :: !Float
    -- ^ Covariance of x and y
  , _msgVelBody_cov_x_z :: !Float
    -- ^ Covariance of x and z
  , _msgVelBody_cov_y_y :: !Float
    -- ^ Estimated variance of y
  , _msgVelBody_cov_y_z :: !Float
    -- ^ Covariance of y and z
  , _msgVelBody_cov_z_z :: !Float
    -- ^ Estimated variance of z
  , _msgVelBody_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgVelBody_flags :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgVelBody where
  get = do
    _msgVelBody_tow <- getWord32le
    _msgVelBody_x <- fromIntegral <$> getWord32le
    _msgVelBody_y <- fromIntegral <$> getWord32le
    _msgVelBody_z <- fromIntegral <$> getWord32le
    _msgVelBody_cov_x_x <- getFloat32le
    _msgVelBody_cov_x_y <- getFloat32le
    _msgVelBody_cov_x_z <- getFloat32le
    _msgVelBody_cov_y_y <- getFloat32le
    _msgVelBody_cov_y_z <- getFloat32le
    _msgVelBody_cov_z_z <- getFloat32le
    _msgVelBody_n_sats <- getWord8
    _msgVelBody_flags <- getWord8
    pure MsgVelBody {..}

  put MsgVelBody {..} = do
    putWord32le _msgVelBody_tow
    (putWord32le . fromIntegral) _msgVelBody_x
    (putWord32le . fromIntegral) _msgVelBody_y
    (putWord32le . fromIntegral) _msgVelBody_z
    putFloat32le _msgVelBody_cov_x_x
    putFloat32le _msgVelBody_cov_x_y
    putFloat32le _msgVelBody_cov_x_z
    putFloat32le _msgVelBody_cov_y_y
    putFloat32le _msgVelBody_cov_y_z
    putFloat32le _msgVelBody_cov_z_z
    putWord8 _msgVelBody_n_sats
    putWord8 _msgVelBody_flags

$(makeSBP 'msgVelBody ''MsgVelBody)
$(makeJSON "_msgVelBody_" ''MsgVelBody)
$(makeLenses ''MsgVelBody)

msgAgeCorrections :: Word16
msgAgeCorrections = 0x0210

-- | SBP class for message MSG_AGE_CORRECTIONS (0x0210).
--
-- This message reports the Age of the corrections used for the current
-- Differential solution
data MsgAgeCorrections = MsgAgeCorrections
  { _msgAgeCorrections_tow :: !Word32
    -- ^ GPS Time of Week
  , _msgAgeCorrections_age :: !Word16
    -- ^ Age of the corrections (0xFFFF indicates invalid)
  } deriving ( Show, Read, Eq )

instance Binary MsgAgeCorrections where
  get = do
    _msgAgeCorrections_tow <- getWord32le
    _msgAgeCorrections_age <- getWord16le
    pure MsgAgeCorrections {..}

  put MsgAgeCorrections {..} = do
    putWord32le _msgAgeCorrections_tow
    putWord16le _msgAgeCorrections_age

$(makeSBP 'msgAgeCorrections ''MsgAgeCorrections)
$(makeJSON "_msgAgeCorrections_" ''MsgAgeCorrections)
$(makeLenses ''MsgAgeCorrections)

msgGpsTimeDepA :: Word16
msgGpsTimeDepA = 0x0100

-- | SBP class for message MSG_GPS_TIME_DEP_A (0x0100).
--
-- This message reports the GPS time, representing the time since the GPS epoch
-- began on midnight January 6, 1980 UTC. GPS time counts the weeks and seconds
-- of the week. The weeks begin at the Saturday/Sunday transition. GPS week 0
-- began at the beginning of the GPS time scale.  Within each week number, the
-- GPS time of the week is between between 0 and 604800 seconds (=60*60*24*7).
-- Note that GPS time does not accumulate leap seconds, and as of now, has a
-- small offset from UTC. In a message stream, this message precedes a set of
-- other navigation messages referenced to the same time (but lacking the ns
-- field) and indicates a more precise time of these messages.
data MsgGpsTimeDepA = MsgGpsTimeDepA
  { _msgGpsTimeDepA_wn        :: !Word16
    -- ^ GPS week number
  , _msgGpsTimeDepA_tow       :: !Word32
    -- ^ GPS time of week rounded to the nearest millisecond
  , _msgGpsTimeDepA_ns_residual :: !Int32
    -- ^ Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    -- 500000)
  , _msgGpsTimeDepA_flags     :: !Word8
    -- ^ Status flags (reserved)
  } deriving ( Show, Read, Eq )

instance Binary MsgGpsTimeDepA where
  get = do
    _msgGpsTimeDepA_wn <- getWord16le
    _msgGpsTimeDepA_tow <- getWord32le
    _msgGpsTimeDepA_ns_residual <- fromIntegral <$> getWord32le
    _msgGpsTimeDepA_flags <- getWord8
    pure MsgGpsTimeDepA {..}

  put MsgGpsTimeDepA {..} = do
    putWord16le _msgGpsTimeDepA_wn
    putWord32le _msgGpsTimeDepA_tow
    (putWord32le . fromIntegral) _msgGpsTimeDepA_ns_residual
    putWord8 _msgGpsTimeDepA_flags

$(makeSBP 'msgGpsTimeDepA ''MsgGpsTimeDepA)
$(makeJSON "_msgGpsTimeDepA_" ''MsgGpsTimeDepA)
$(makeLenses ''MsgGpsTimeDepA)

msgDopsDepA :: Word16
msgDopsDepA = 0x0206

-- | SBP class for message MSG_DOPS_DEP_A (0x0206).
--
-- This dilution of precision (DOP) message describes the effect of navigation
-- satellite geometry on positional measurement precision.
data MsgDopsDepA = MsgDopsDepA
  { _msgDopsDepA_tow :: !Word32
    -- ^ GPS Time of Week
  , _msgDopsDepA_gdop :: !Word16
    -- ^ Geometric Dilution of Precision
  , _msgDopsDepA_pdop :: !Word16
    -- ^ Position Dilution of Precision
  , _msgDopsDepA_tdop :: !Word16
    -- ^ Time Dilution of Precision
  , _msgDopsDepA_hdop :: !Word16
    -- ^ Horizontal Dilution of Precision
  , _msgDopsDepA_vdop :: !Word16
    -- ^ Vertical Dilution of Precision
  } deriving ( Show, Read, Eq )

instance Binary MsgDopsDepA where
  get = do
    _msgDopsDepA_tow <- getWord32le
    _msgDopsDepA_gdop <- getWord16le
    _msgDopsDepA_pdop <- getWord16le
    _msgDopsDepA_tdop <- getWord16le
    _msgDopsDepA_hdop <- getWord16le
    _msgDopsDepA_vdop <- getWord16le
    pure MsgDopsDepA {..}

  put MsgDopsDepA {..} = do
    putWord32le _msgDopsDepA_tow
    putWord16le _msgDopsDepA_gdop
    putWord16le _msgDopsDepA_pdop
    putWord16le _msgDopsDepA_tdop
    putWord16le _msgDopsDepA_hdop
    putWord16le _msgDopsDepA_vdop

$(makeSBP 'msgDopsDepA ''MsgDopsDepA)
$(makeJSON "_msgDopsDepA_" ''MsgDopsDepA)
$(makeLenses ''MsgDopsDepA)

msgPosEcefDepA :: Word16
msgPosEcefDepA = 0x0200

-- | SBP class for message MSG_POS_ECEF_DEP_A (0x0200).
--
-- The position solution message reports absolute Earth Centered Earth Fixed
-- (ECEF) coordinates and the status (single point vs pseudo-absolute RTK) of
-- the position solution. If the rover receiver knows the surveyed position of
-- the base station and has an RTK solution, this reports a pseudo-absolute
-- position solution using the base station position and the rover's RTK
-- baseline vector. The full GPS time is given by the preceding MSG_GPS_TIME
-- with the matching time-of-week (tow).
data MsgPosEcefDepA = MsgPosEcefDepA
  { _msgPosEcefDepA_tow    :: !Word32
    -- ^ GPS Time of Week
  , _msgPosEcefDepA_x      :: !Double
    -- ^ ECEF X coordinate
  , _msgPosEcefDepA_y      :: !Double
    -- ^ ECEF Y coordinate
  , _msgPosEcefDepA_z      :: !Double
    -- ^ ECEF Z coordinate
  , _msgPosEcefDepA_accuracy :: !Word16
    -- ^ Position accuracy estimate (not implemented). Defaults to 0.
  , _msgPosEcefDepA_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgPosEcefDepA_flags  :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgPosEcefDepA where
  get = do
    _msgPosEcefDepA_tow <- getWord32le
    _msgPosEcefDepA_x <- getFloat64le
    _msgPosEcefDepA_y <- getFloat64le
    _msgPosEcefDepA_z <- getFloat64le
    _msgPosEcefDepA_accuracy <- getWord16le
    _msgPosEcefDepA_n_sats <- getWord8
    _msgPosEcefDepA_flags <- getWord8
    pure MsgPosEcefDepA {..}

  put MsgPosEcefDepA {..} = do
    putWord32le _msgPosEcefDepA_tow
    putFloat64le _msgPosEcefDepA_x
    putFloat64le _msgPosEcefDepA_y
    putFloat64le _msgPosEcefDepA_z
    putWord16le _msgPosEcefDepA_accuracy
    putWord8 _msgPosEcefDepA_n_sats
    putWord8 _msgPosEcefDepA_flags

$(makeSBP 'msgPosEcefDepA ''MsgPosEcefDepA)
$(makeJSON "_msgPosEcefDepA_" ''MsgPosEcefDepA)
$(makeLenses ''MsgPosEcefDepA)

msgPosLlhDepA :: Word16
msgPosLlhDepA = 0x0201

-- | SBP class for message MSG_POS_LLH_DEP_A (0x0201).
--
-- This position solution message reports the absolute geodetic coordinates and
-- the status (single point vs pseudo-absolute RTK) of the position solution.
-- If the rover receiver knows the surveyed position of the base station and
-- has an RTK solution, this reports a pseudo-absolute position solution using
-- the base station position and the rover's RTK baseline vector. The full GPS
-- time is given by the preceding MSG_GPS_TIME with the matching time-of-week
-- (tow).
data MsgPosLlhDepA = MsgPosLlhDepA
  { _msgPosLlhDepA_tow      :: !Word32
    -- ^ GPS Time of Week
  , _msgPosLlhDepA_lat      :: !Double
    -- ^ Latitude
  , _msgPosLlhDepA_lon      :: !Double
    -- ^ Longitude
  , _msgPosLlhDepA_height   :: !Double
    -- ^ Height
  , _msgPosLlhDepA_h_accuracy :: !Word16
    -- ^ Horizontal position accuracy estimate (not implemented). Defaults to 0.
  , _msgPosLlhDepA_v_accuracy :: !Word16
    -- ^ Vertical position accuracy estimate (not implemented). Defaults to 0.
  , _msgPosLlhDepA_n_sats   :: !Word8
    -- ^ Number of satellites used in solution.
  , _msgPosLlhDepA_flags    :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgPosLlhDepA where
  get = do
    _msgPosLlhDepA_tow <- getWord32le
    _msgPosLlhDepA_lat <- getFloat64le
    _msgPosLlhDepA_lon <- getFloat64le
    _msgPosLlhDepA_height <- getFloat64le
    _msgPosLlhDepA_h_accuracy <- getWord16le
    _msgPosLlhDepA_v_accuracy <- getWord16le
    _msgPosLlhDepA_n_sats <- getWord8
    _msgPosLlhDepA_flags <- getWord8
    pure MsgPosLlhDepA {..}

  put MsgPosLlhDepA {..} = do
    putWord32le _msgPosLlhDepA_tow
    putFloat64le _msgPosLlhDepA_lat
    putFloat64le _msgPosLlhDepA_lon
    putFloat64le _msgPosLlhDepA_height
    putWord16le _msgPosLlhDepA_h_accuracy
    putWord16le _msgPosLlhDepA_v_accuracy
    putWord8 _msgPosLlhDepA_n_sats
    putWord8 _msgPosLlhDepA_flags

$(makeSBP 'msgPosLlhDepA ''MsgPosLlhDepA)
$(makeJSON "_msgPosLlhDepA_" ''MsgPosLlhDepA)
$(makeLenses ''MsgPosLlhDepA)

msgBaselineEcefDepA :: Word16
msgBaselineEcefDepA = 0x0202

-- | SBP class for message MSG_BASELINE_ECEF_DEP_A (0x0202).
--
-- This message reports the baseline solution in Earth Centered Earth Fixed
-- (ECEF) coordinates. This baseline is the relative vector distance from the
-- base station to the rover receiver. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow).
data MsgBaselineEcefDepA = MsgBaselineEcefDepA
  { _msgBaselineEcefDepA_tow    :: !Word32
    -- ^ GPS Time of Week
  , _msgBaselineEcefDepA_x      :: !Int32
    -- ^ Baseline ECEF X coordinate
  , _msgBaselineEcefDepA_y      :: !Int32
    -- ^ Baseline ECEF Y coordinate
  , _msgBaselineEcefDepA_z      :: !Int32
    -- ^ Baseline ECEF Z coordinate
  , _msgBaselineEcefDepA_accuracy :: !Word16
    -- ^ Position accuracy estimate
  , _msgBaselineEcefDepA_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgBaselineEcefDepA_flags  :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgBaselineEcefDepA where
  get = do
    _msgBaselineEcefDepA_tow <- getWord32le
    _msgBaselineEcefDepA_x <- fromIntegral <$> getWord32le
    _msgBaselineEcefDepA_y <- fromIntegral <$> getWord32le
    _msgBaselineEcefDepA_z <- fromIntegral <$> getWord32le
    _msgBaselineEcefDepA_accuracy <- getWord16le
    _msgBaselineEcefDepA_n_sats <- getWord8
    _msgBaselineEcefDepA_flags <- getWord8
    pure MsgBaselineEcefDepA {..}

  put MsgBaselineEcefDepA {..} = do
    putWord32le _msgBaselineEcefDepA_tow
    (putWord32le . fromIntegral) _msgBaselineEcefDepA_x
    (putWord32le . fromIntegral) _msgBaselineEcefDepA_y
    (putWord32le . fromIntegral) _msgBaselineEcefDepA_z
    putWord16le _msgBaselineEcefDepA_accuracy
    putWord8 _msgBaselineEcefDepA_n_sats
    putWord8 _msgBaselineEcefDepA_flags

$(makeSBP 'msgBaselineEcefDepA ''MsgBaselineEcefDepA)
$(makeJSON "_msgBaselineEcefDepA_" ''MsgBaselineEcefDepA)
$(makeLenses ''MsgBaselineEcefDepA)

msgBaselineNedDepA :: Word16
msgBaselineNedDepA = 0x0203

-- | SBP class for message MSG_BASELINE_NED_DEP_A (0x0203).
--
-- This message reports the baseline solution in North East Down (NED)
-- coordinates. This baseline is the relative vector distance from the base
-- station to the rover receiver, and NED coordinate system is defined at the
-- local WGS84 tangent plane centered at the base station position.  The full
-- GPS time is given by the preceding MSG_GPS_TIME with the matching time-of-
-- week (tow).
data MsgBaselineNedDepA = MsgBaselineNedDepA
  { _msgBaselineNedDepA_tow      :: !Word32
    -- ^ GPS Time of Week
  , _msgBaselineNedDepA_n        :: !Int32
    -- ^ Baseline North coordinate
  , _msgBaselineNedDepA_e        :: !Int32
    -- ^ Baseline East coordinate
  , _msgBaselineNedDepA_d        :: !Int32
    -- ^ Baseline Down coordinate
  , _msgBaselineNedDepA_h_accuracy :: !Word16
    -- ^ Horizontal position accuracy estimate (not implemented). Defaults to 0.
  , _msgBaselineNedDepA_v_accuracy :: !Word16
    -- ^ Vertical position accuracy estimate (not implemented). Defaults to 0.
  , _msgBaselineNedDepA_n_sats   :: !Word8
    -- ^ Number of satellites used in solution
  , _msgBaselineNedDepA_flags    :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgBaselineNedDepA where
  get = do
    _msgBaselineNedDepA_tow <- getWord32le
    _msgBaselineNedDepA_n <- fromIntegral <$> getWord32le
    _msgBaselineNedDepA_e <- fromIntegral <$> getWord32le
    _msgBaselineNedDepA_d <- fromIntegral <$> getWord32le
    _msgBaselineNedDepA_h_accuracy <- getWord16le
    _msgBaselineNedDepA_v_accuracy <- getWord16le
    _msgBaselineNedDepA_n_sats <- getWord8
    _msgBaselineNedDepA_flags <- getWord8
    pure MsgBaselineNedDepA {..}

  put MsgBaselineNedDepA {..} = do
    putWord32le _msgBaselineNedDepA_tow
    (putWord32le . fromIntegral) _msgBaselineNedDepA_n
    (putWord32le . fromIntegral) _msgBaselineNedDepA_e
    (putWord32le . fromIntegral) _msgBaselineNedDepA_d
    putWord16le _msgBaselineNedDepA_h_accuracy
    putWord16le _msgBaselineNedDepA_v_accuracy
    putWord8 _msgBaselineNedDepA_n_sats
    putWord8 _msgBaselineNedDepA_flags

$(makeSBP 'msgBaselineNedDepA ''MsgBaselineNedDepA)
$(makeJSON "_msgBaselineNedDepA_" ''MsgBaselineNedDepA)
$(makeLenses ''MsgBaselineNedDepA)

msgVelEcefDepA :: Word16
msgVelEcefDepA = 0x0204

-- | SBP class for message MSG_VEL_ECEF_DEP_A (0x0204).
--
-- This message reports the velocity in Earth Centered Earth Fixed (ECEF)
-- coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
-- the matching time-of-week (tow).
data MsgVelEcefDepA = MsgVelEcefDepA
  { _msgVelEcefDepA_tow    :: !Word32
    -- ^ GPS Time of Week
  , _msgVelEcefDepA_x      :: !Int32
    -- ^ Velocity ECEF X coordinate
  , _msgVelEcefDepA_y      :: !Int32
    -- ^ Velocity ECEF Y coordinate
  , _msgVelEcefDepA_z      :: !Int32
    -- ^ Velocity ECEF Z coordinate
  , _msgVelEcefDepA_accuracy :: !Word16
    -- ^ Velocity accuracy estimate (not implemented). Defaults to 0.
  , _msgVelEcefDepA_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgVelEcefDepA_flags  :: !Word8
    -- ^ Status flags (reserved)
  } deriving ( Show, Read, Eq )

instance Binary MsgVelEcefDepA where
  get = do
    _msgVelEcefDepA_tow <- getWord32le
    _msgVelEcefDepA_x <- fromIntegral <$> getWord32le
    _msgVelEcefDepA_y <- fromIntegral <$> getWord32le
    _msgVelEcefDepA_z <- fromIntegral <$> getWord32le
    _msgVelEcefDepA_accuracy <- getWord16le
    _msgVelEcefDepA_n_sats <- getWord8
    _msgVelEcefDepA_flags <- getWord8
    pure MsgVelEcefDepA {..}

  put MsgVelEcefDepA {..} = do
    putWord32le _msgVelEcefDepA_tow
    (putWord32le . fromIntegral) _msgVelEcefDepA_x
    (putWord32le . fromIntegral) _msgVelEcefDepA_y
    (putWord32le . fromIntegral) _msgVelEcefDepA_z
    putWord16le _msgVelEcefDepA_accuracy
    putWord8 _msgVelEcefDepA_n_sats
    putWord8 _msgVelEcefDepA_flags

$(makeSBP 'msgVelEcefDepA ''MsgVelEcefDepA)
$(makeJSON "_msgVelEcefDepA_" ''MsgVelEcefDepA)
$(makeLenses ''MsgVelEcefDepA)

msgVelNedDepA :: Word16
msgVelNedDepA = 0x0205

-- | SBP class for message MSG_VEL_NED_DEP_A (0x0205).
--
-- This message reports the velocity in local North East Down (NED)
-- coordinates. The NED coordinate system is defined as the local WGS84 tangent
-- plane centered at the current position. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow).
data MsgVelNedDepA = MsgVelNedDepA
  { _msgVelNedDepA_tow      :: !Word32
    -- ^ GPS Time of Week
  , _msgVelNedDepA_n        :: !Int32
    -- ^ Velocity North coordinate
  , _msgVelNedDepA_e        :: !Int32
    -- ^ Velocity East coordinate
  , _msgVelNedDepA_d        :: !Int32
    -- ^ Velocity Down coordinate
  , _msgVelNedDepA_h_accuracy :: !Word16
    -- ^ Horizontal velocity accuracy estimate (not implemented). Defaults to 0.
  , _msgVelNedDepA_v_accuracy :: !Word16
    -- ^ Vertical velocity accuracy estimate (not implemented). Defaults to 0.
  , _msgVelNedDepA_n_sats   :: !Word8
    -- ^ Number of satellites used in solution
  , _msgVelNedDepA_flags    :: !Word8
    -- ^ Status flags (reserved)
  } deriving ( Show, Read, Eq )

instance Binary MsgVelNedDepA where
  get = do
    _msgVelNedDepA_tow <- getWord32le
    _msgVelNedDepA_n <- fromIntegral <$> getWord32le
    _msgVelNedDepA_e <- fromIntegral <$> getWord32le
    _msgVelNedDepA_d <- fromIntegral <$> getWord32le
    _msgVelNedDepA_h_accuracy <- getWord16le
    _msgVelNedDepA_v_accuracy <- getWord16le
    _msgVelNedDepA_n_sats <- getWord8
    _msgVelNedDepA_flags <- getWord8
    pure MsgVelNedDepA {..}

  put MsgVelNedDepA {..} = do
    putWord32le _msgVelNedDepA_tow
    (putWord32le . fromIntegral) _msgVelNedDepA_n
    (putWord32le . fromIntegral) _msgVelNedDepA_e
    (putWord32le . fromIntegral) _msgVelNedDepA_d
    putWord16le _msgVelNedDepA_h_accuracy
    putWord16le _msgVelNedDepA_v_accuracy
    putWord8 _msgVelNedDepA_n_sats
    putWord8 _msgVelNedDepA_flags

$(makeSBP 'msgVelNedDepA ''MsgVelNedDepA)
$(makeJSON "_msgVelNedDepA_" ''MsgVelNedDepA)
$(makeLenses ''MsgVelNedDepA)

msgBaselineHeadingDepA :: Word16
msgBaselineHeadingDepA = 0x0207

-- | SBP class for message MSG_BASELINE_HEADING_DEP_A (0x0207).
--
-- This message reports the baseline heading pointing from the base station to
-- the rover relative to True North. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow).
data MsgBaselineHeadingDepA = MsgBaselineHeadingDepA
  { _msgBaselineHeadingDepA_tow   :: !Word32
    -- ^ GPS Time of Week
  , _msgBaselineHeadingDepA_heading :: !Word32
    -- ^ Heading
  , _msgBaselineHeadingDepA_n_sats :: !Word8
    -- ^ Number of satellites used in solution
  , _msgBaselineHeadingDepA_flags :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgBaselineHeadingDepA where
  get = do
    _msgBaselineHeadingDepA_tow <- getWord32le
    _msgBaselineHeadingDepA_heading <- getWord32le
    _msgBaselineHeadingDepA_n_sats <- getWord8
    _msgBaselineHeadingDepA_flags <- getWord8
    pure MsgBaselineHeadingDepA {..}

  put MsgBaselineHeadingDepA {..} = do
    putWord32le _msgBaselineHeadingDepA_tow
    putWord32le _msgBaselineHeadingDepA_heading
    putWord8 _msgBaselineHeadingDepA_n_sats
    putWord8 _msgBaselineHeadingDepA_flags

$(makeSBP 'msgBaselineHeadingDepA ''MsgBaselineHeadingDepA)
$(makeJSON "_msgBaselineHeadingDepA_" ''MsgBaselineHeadingDepA)
$(makeLenses ''MsgBaselineHeadingDepA)

msgProtectionLevel :: Word16
msgProtectionLevel = 0x0216

-- | SBP class for message MSG_PROTECTION_LEVEL (0x0216).
--
-- This message reports the local vertical and horizontal protection levels
-- associated with a given LLH position solution. The full GPS time is given by
-- the preceding MSG_GPS_TIME with the matching time-of-week (tow).
data MsgProtectionLevel = MsgProtectionLevel
  { _msgProtectionLevel_tow  :: !Word32
    -- ^ GPS Time of Week
  , _msgProtectionLevel_vpl  :: !Word16
    -- ^ Vertical protection level
  , _msgProtectionLevel_hpl  :: !Word16
    -- ^ Horizontal protection level
  , _msgProtectionLevel_lat  :: !Double
    -- ^ Latitude
  , _msgProtectionLevel_lon  :: !Double
    -- ^ Longitude
  , _msgProtectionLevel_height :: !Double
    -- ^ Height
  , _msgProtectionLevel_flags :: !Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgProtectionLevel where
  get = do
    _msgProtectionLevel_tow <- getWord32le
    _msgProtectionLevel_vpl <- getWord16le
    _msgProtectionLevel_hpl <- getWord16le
    _msgProtectionLevel_lat <- getFloat64le
    _msgProtectionLevel_lon <- getFloat64le
    _msgProtectionLevel_height <- getFloat64le
    _msgProtectionLevel_flags <- getWord8
    pure MsgProtectionLevel {..}

  put MsgProtectionLevel {..} = do
    putWord32le _msgProtectionLevel_tow
    putWord16le _msgProtectionLevel_vpl
    putWord16le _msgProtectionLevel_hpl
    putFloat64le _msgProtectionLevel_lat
    putFloat64le _msgProtectionLevel_lon
    putFloat64le _msgProtectionLevel_height
    putWord8 _msgProtectionLevel_flags

$(makeSBP 'msgProtectionLevel ''MsgProtectionLevel)
$(makeJSON "_msgProtectionLevel_" ''MsgProtectionLevel)
$(makeLenses ''MsgProtectionLevel)
