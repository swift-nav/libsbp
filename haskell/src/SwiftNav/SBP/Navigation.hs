{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Navigation
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Geodetic navigation messages reporting GPS time, position, velocity, and
-- baseline position solutions. For position solutions, these messages define
-- several different position solutions: single-point (SPP), RTK, and pseudo-
-- absolute position solutions.  The SPP is the standalone, absolute GPS
-- position solution using only a single receiver. The RTK solution is the
-- differential GPS solution, which can use either a fixed/integer or floating
-- carrier phase ambiguity. The pseudo-absolute position solution uses a user-
-- provided, well-surveyed base station position (if available) and the RTK
-- solution in tandem.

module SwiftNav.SBP.Navigation where

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
  { _msgGpsTime_wn        :: Word16
    -- ^ GPS week number
  , _msgGpsTime_tow       :: Word32
    -- ^ GPS time of week rounded to the nearest millisecond
  , _msgGpsTime_ns_residual :: Int32
    -- ^ Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    -- 500000)
  , _msgGpsTime_flags     :: Word8
    -- ^ Status flags (reserved)
  } deriving ( Show, Read, Eq )

instance Binary MsgGpsTime where
  get = do
    _msgGpsTime_wn <- getWord16le
    _msgGpsTime_tow <- getWord32le
    _msgGpsTime_ns_residual <- fromIntegral <$> getWord32le
    _msgGpsTime_flags <- getWord8
    return MsgGpsTime {..}

  put MsgGpsTime {..} = do
    putWord16le _msgGpsTime_wn
    putWord32le _msgGpsTime_tow
    putWord32le $ fromIntegral _msgGpsTime_ns_residual
    putWord8 _msgGpsTime_flags

$(deriveSBP 'msgGpsTime ''MsgGpsTime)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgGpsTime_" . P.stripPrefix "_msgGpsTime_"}
             ''MsgGpsTime)
$(makeLenses ''MsgGpsTime)

msgUtcTime :: Word16
msgUtcTime = 0x0103

-- | SBP class for message MSG_UTC_TIME (0x0103).
--
-- This message reports the Universal Coordinated Time (UTC).  Note the flags
-- which indicate the source of the UTC offset value and source of the time
-- fix.
data MsgUtcTime = MsgUtcTime
  { _msgUtcTime_flags :: Word8
    -- ^ Indicates source and time validity
  , _msgUtcTime_tow   :: Word32
    -- ^ GPS time of week rounded to the nearest millisecond
  , _msgUtcTime_year  :: Word16
    -- ^ Year
  , _msgUtcTime_month :: Word8
    -- ^ Month (range 1 .. 12)
  , _msgUtcTime_day   :: Word8
    -- ^ days in the month (range 1-31)
  , _msgUtcTime_hours :: Word8
    -- ^ hours of day (range 0-23)
  , _msgUtcTime_minutes :: Word8
    -- ^ minutes of hour (range 0-59)
  , _msgUtcTime_seconds :: Word8
    -- ^ seconds of minute (range 0-60) rounded down
  , _msgUtcTime_ns    :: Word32
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
    return MsgUtcTime {..}

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

$(deriveSBP 'msgUtcTime ''MsgUtcTime)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgUtcTime_" . P.stripPrefix "_msgUtcTime_"}
             ''MsgUtcTime)
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
  { _msgDops_tow :: Word32
    -- ^ GPS Time of Week
  , _msgDops_gdop :: Word16
    -- ^ Geometric Dilution of Precision
  , _msgDops_pdop :: Word16
    -- ^ Position Dilution of Precision
  , _msgDops_tdop :: Word16
    -- ^ Time Dilution of Precision
  , _msgDops_hdop :: Word16
    -- ^ Horizontal Dilution of Precision
  , _msgDops_vdop :: Word16
    -- ^ Vertical Dilution of Precision
  , _msgDops_flags :: Word8
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
    return MsgDops {..}

  put MsgDops {..} = do
    putWord32le _msgDops_tow
    putWord16le _msgDops_gdop
    putWord16le _msgDops_pdop
    putWord16le _msgDops_tdop
    putWord16le _msgDops_hdop
    putWord16le _msgDops_vdop
    putWord8 _msgDops_flags

$(deriveSBP 'msgDops ''MsgDops)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgDops_" . P.stripPrefix "_msgDops_"}
             ''MsgDops)
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
  { _msgPosEcef_tow    :: Word32
    -- ^ GPS Time of Week
  , _msgPosEcef_x      :: Double
    -- ^ ECEF X coordinate
  , _msgPosEcef_y      :: Double
    -- ^ ECEF Y coordinate
  , _msgPosEcef_z      :: Double
    -- ^ ECEF Z coordinate
  , _msgPosEcef_accuracy :: Word16
    -- ^ Position accuracy estimate.
  , _msgPosEcef_n_sats :: Word8
    -- ^ Number of satellites used in solution
  , _msgPosEcef_flags  :: Word8
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
    return MsgPosEcef {..}

  put MsgPosEcef {..} = do
    putWord32le _msgPosEcef_tow
    putFloat64le _msgPosEcef_x
    putFloat64le _msgPosEcef_y
    putFloat64le _msgPosEcef_z
    putWord16le _msgPosEcef_accuracy
    putWord8 _msgPosEcef_n_sats
    putWord8 _msgPosEcef_flags

$(deriveSBP 'msgPosEcef ''MsgPosEcef)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgPosEcef_" . P.stripPrefix "_msgPosEcef_"}
             ''MsgPosEcef)
$(makeLenses ''MsgPosEcef)

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
  { _msgPosLlh_tow      :: Word32
    -- ^ GPS Time of Week
  , _msgPosLlh_lat      :: Double
    -- ^ Latitude
  , _msgPosLlh_lon      :: Double
    -- ^ Longitude
  , _msgPosLlh_height   :: Double
    -- ^ Height above WGS84 ellipsoid
  , _msgPosLlh_h_accuracy :: Word16
    -- ^ Horizontal position accuracy estimate.
  , _msgPosLlh_v_accuracy :: Word16
    -- ^ Vertical position accuracy estimate.
  , _msgPosLlh_n_sats   :: Word8
    -- ^ Number of satellites used in solution.
  , _msgPosLlh_flags    :: Word8
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
    return MsgPosLlh {..}

  put MsgPosLlh {..} = do
    putWord32le _msgPosLlh_tow
    putFloat64le _msgPosLlh_lat
    putFloat64le _msgPosLlh_lon
    putFloat64le _msgPosLlh_height
    putWord16le _msgPosLlh_h_accuracy
    putWord16le _msgPosLlh_v_accuracy
    putWord8 _msgPosLlh_n_sats
    putWord8 _msgPosLlh_flags

$(deriveSBP 'msgPosLlh ''MsgPosLlh)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgPosLlh_" . P.stripPrefix "_msgPosLlh_"}
             ''MsgPosLlh)
$(makeLenses ''MsgPosLlh)

msgBaselineEcef :: Word16
msgBaselineEcef = 0x020B

-- | SBP class for message MSG_BASELINE_ECEF (0x020B).
--
-- This message reports the baseline solution in Earth Centered Earth Fixed
-- (ECEF) coordinates. This baseline is the relative vector distance from the
-- base station to the rover receiver. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow).
data MsgBaselineEcef = MsgBaselineEcef
  { _msgBaselineEcef_tow    :: Word32
    -- ^ GPS Time of Week
  , _msgBaselineEcef_x      :: Int32
    -- ^ Baseline ECEF X coordinate
  , _msgBaselineEcef_y      :: Int32
    -- ^ Baseline ECEF Y coordinate
  , _msgBaselineEcef_z      :: Int32
    -- ^ Baseline ECEF Z coordinate
  , _msgBaselineEcef_accuracy :: Word16
    -- ^ Position accuracy estimate
  , _msgBaselineEcef_n_sats :: Word8
    -- ^ Number of satellites used in solution
  , _msgBaselineEcef_flags  :: Word8
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
    return MsgBaselineEcef {..}

  put MsgBaselineEcef {..} = do
    putWord32le _msgBaselineEcef_tow
    putWord32le $ fromIntegral _msgBaselineEcef_x
    putWord32le $ fromIntegral _msgBaselineEcef_y
    putWord32le $ fromIntegral _msgBaselineEcef_z
    putWord16le _msgBaselineEcef_accuracy
    putWord8 _msgBaselineEcef_n_sats
    putWord8 _msgBaselineEcef_flags

$(deriveSBP 'msgBaselineEcef ''MsgBaselineEcef)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgBaselineEcef_" . P.stripPrefix "_msgBaselineEcef_"}
             ''MsgBaselineEcef)
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
  { _msgBaselineNed_tow      :: Word32
    -- ^ GPS Time of Week
  , _msgBaselineNed_n        :: Int32
    -- ^ Baseline North coordinate
  , _msgBaselineNed_e        :: Int32
    -- ^ Baseline East coordinate
  , _msgBaselineNed_d        :: Int32
    -- ^ Baseline Down coordinate
  , _msgBaselineNed_h_accuracy :: Word16
    -- ^ Horizontal position accuracy estimate
  , _msgBaselineNed_v_accuracy :: Word16
    -- ^ Vertical position accuracy estimate
  , _msgBaselineNed_n_sats   :: Word8
    -- ^ Number of satellites used in solution
  , _msgBaselineNed_flags    :: Word8
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
    return MsgBaselineNed {..}

  put MsgBaselineNed {..} = do
    putWord32le _msgBaselineNed_tow
    putWord32le $ fromIntegral _msgBaselineNed_n
    putWord32le $ fromIntegral _msgBaselineNed_e
    putWord32le $ fromIntegral _msgBaselineNed_d
    putWord16le _msgBaselineNed_h_accuracy
    putWord16le _msgBaselineNed_v_accuracy
    putWord8 _msgBaselineNed_n_sats
    putWord8 _msgBaselineNed_flags

$(deriveSBP 'msgBaselineNed ''MsgBaselineNed)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgBaselineNed_" . P.stripPrefix "_msgBaselineNed_"}
             ''MsgBaselineNed)
$(makeLenses ''MsgBaselineNed)

msgVelEcef :: Word16
msgVelEcef = 0x020D

-- | SBP class for message MSG_VEL_ECEF (0x020D).
--
-- This message reports the velocity in Earth Centered Earth Fixed (ECEF)
-- coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
-- the matching time-of-week (tow).
data MsgVelEcef = MsgVelEcef
  { _msgVelEcef_tow    :: Word32
    -- ^ GPS Time of Week
  , _msgVelEcef_x      :: Int32
    -- ^ Velocity ECEF X coordinate
  , _msgVelEcef_y      :: Int32
    -- ^ Velocity ECEF Y coordinate
  , _msgVelEcef_z      :: Int32
    -- ^ Velocity ECEF Z coordinate
  , _msgVelEcef_accuracy :: Word16
    -- ^ Velocity accuracy estimate
  , _msgVelEcef_n_sats :: Word8
    -- ^ Number of satellites used in solution
  , _msgVelEcef_flags  :: Word8
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
    return MsgVelEcef {..}

  put MsgVelEcef {..} = do
    putWord32le _msgVelEcef_tow
    putWord32le $ fromIntegral _msgVelEcef_x
    putWord32le $ fromIntegral _msgVelEcef_y
    putWord32le $ fromIntegral _msgVelEcef_z
    putWord16le _msgVelEcef_accuracy
    putWord8 _msgVelEcef_n_sats
    putWord8 _msgVelEcef_flags

$(deriveSBP 'msgVelEcef ''MsgVelEcef)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgVelEcef_" . P.stripPrefix "_msgVelEcef_"}
             ''MsgVelEcef)
$(makeLenses ''MsgVelEcef)

msgVelNed :: Word16
msgVelNed = 0x020E

-- | SBP class for message MSG_VEL_NED (0x020E).
--
-- This message reports the velocity in local North East Down (NED)
-- coordinates. The NED coordinate system is defined as the local WGS84 tangent
-- plane centered at the current position. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow).
data MsgVelNed = MsgVelNed
  { _msgVelNed_tow      :: Word32
    -- ^ GPS Time of Week
  , _msgVelNed_n        :: Int32
    -- ^ Velocity North coordinate
  , _msgVelNed_e        :: Int32
    -- ^ Velocity East coordinate
  , _msgVelNed_d        :: Int32
    -- ^ Velocity Down coordinate
  , _msgVelNed_h_accuracy :: Word16
    -- ^ Horizontal velocity accuracy estimate
  , _msgVelNed_v_accuracy :: Word16
    -- ^ Vertical velocity accuracy estimate
  , _msgVelNed_n_sats   :: Word8
    -- ^ Number of satellites used in solution
  , _msgVelNed_flags    :: Word8
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
    return MsgVelNed {..}

  put MsgVelNed {..} = do
    putWord32le _msgVelNed_tow
    putWord32le $ fromIntegral _msgVelNed_n
    putWord32le $ fromIntegral _msgVelNed_e
    putWord32le $ fromIntegral _msgVelNed_d
    putWord16le _msgVelNed_h_accuracy
    putWord16le _msgVelNed_v_accuracy
    putWord8 _msgVelNed_n_sats
    putWord8 _msgVelNed_flags

$(deriveSBP 'msgVelNed ''MsgVelNed)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgVelNed_" . P.stripPrefix "_msgVelNed_"}
             ''MsgVelNed)
$(makeLenses ''MsgVelNed)

msgBaselineHeading :: Word16
msgBaselineHeading = 0x020F

-- | SBP class for message MSG_BASELINE_HEADING (0x020F).
--
-- This message reports the baseline heading pointing from the base station to
-- the rover relative to True North. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow). It is intended
-- that time-matched RTK mode is used when the base station is moving.
data MsgBaselineHeading = MsgBaselineHeading
  { _msgBaselineHeading_tow   :: Word32
    -- ^ GPS Time of Week
  , _msgBaselineHeading_heading :: Word32
    -- ^ Heading
  , _msgBaselineHeading_n_sats :: Word8
    -- ^ Number of satellites used in solution
  , _msgBaselineHeading_flags :: Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgBaselineHeading where
  get = do
    _msgBaselineHeading_tow <- getWord32le
    _msgBaselineHeading_heading <- getWord32le
    _msgBaselineHeading_n_sats <- getWord8
    _msgBaselineHeading_flags <- getWord8
    return MsgBaselineHeading {..}

  put MsgBaselineHeading {..} = do
    putWord32le _msgBaselineHeading_tow
    putWord32le _msgBaselineHeading_heading
    putWord8 _msgBaselineHeading_n_sats
    putWord8 _msgBaselineHeading_flags

$(deriveSBP 'msgBaselineHeading ''MsgBaselineHeading)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgBaselineHeading_" . P.stripPrefix "_msgBaselineHeading_"}
             ''MsgBaselineHeading)
$(makeLenses ''MsgBaselineHeading)

msgAgeCorrections :: Word16
msgAgeCorrections = 0x0210

-- | SBP class for message MSG_AGE_CORRECTIONS (0x0210).
--
-- This message reports the Age of the corrections used for the current
-- Differential solution
data MsgAgeCorrections = MsgAgeCorrections
  { _msgAgeCorrections_tow :: Word32
    -- ^ GPS Time of Week
  , _msgAgeCorrections_age :: Word16
    -- ^ Age of the corrections (0xFFFF indicates invalid)
  } deriving ( Show, Read, Eq )

instance Binary MsgAgeCorrections where
  get = do
    _msgAgeCorrections_tow <- getWord32le
    _msgAgeCorrections_age <- getWord16le
    return MsgAgeCorrections {..}

  put MsgAgeCorrections {..} = do
    putWord32le _msgAgeCorrections_tow
    putWord16le _msgAgeCorrections_age

$(deriveSBP 'msgAgeCorrections ''MsgAgeCorrections)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgAgeCorrections_" . P.stripPrefix "_msgAgeCorrections_"}
             ''MsgAgeCorrections)
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
  { _msgGpsTimeDepA_wn        :: Word16
    -- ^ GPS week number
  , _msgGpsTimeDepA_tow       :: Word32
    -- ^ GPS time of week rounded to the nearest millisecond
  , _msgGpsTimeDepA_ns_residual :: Int32
    -- ^ Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    -- 500000)
  , _msgGpsTimeDepA_flags     :: Word8
    -- ^ Status flags (reserved)
  } deriving ( Show, Read, Eq )

instance Binary MsgGpsTimeDepA where
  get = do
    _msgGpsTimeDepA_wn <- getWord16le
    _msgGpsTimeDepA_tow <- getWord32le
    _msgGpsTimeDepA_ns_residual <- fromIntegral <$> getWord32le
    _msgGpsTimeDepA_flags <- getWord8
    return MsgGpsTimeDepA {..}

  put MsgGpsTimeDepA {..} = do
    putWord16le _msgGpsTimeDepA_wn
    putWord32le _msgGpsTimeDepA_tow
    putWord32le $ fromIntegral _msgGpsTimeDepA_ns_residual
    putWord8 _msgGpsTimeDepA_flags

$(deriveSBP 'msgGpsTimeDepA ''MsgGpsTimeDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgGpsTimeDepA_" . P.stripPrefix "_msgGpsTimeDepA_"}
             ''MsgGpsTimeDepA)
$(makeLenses ''MsgGpsTimeDepA)

msgDopsDepA :: Word16
msgDopsDepA = 0x0206

-- | SBP class for message MSG_DOPS_DEP_A (0x0206).
--
-- This dilution of precision (DOP) message describes the effect of navigation
-- satellite geometry on positional measurement precision.
data MsgDopsDepA = MsgDopsDepA
  { _msgDopsDepA_tow :: Word32
    -- ^ GPS Time of Week
  , _msgDopsDepA_gdop :: Word16
    -- ^ Geometric Dilution of Precision
  , _msgDopsDepA_pdop :: Word16
    -- ^ Position Dilution of Precision
  , _msgDopsDepA_tdop :: Word16
    -- ^ Time Dilution of Precision
  , _msgDopsDepA_hdop :: Word16
    -- ^ Horizontal Dilution of Precision
  , _msgDopsDepA_vdop :: Word16
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
    return MsgDopsDepA {..}

  put MsgDopsDepA {..} = do
    putWord32le _msgDopsDepA_tow
    putWord16le _msgDopsDepA_gdop
    putWord16le _msgDopsDepA_pdop
    putWord16le _msgDopsDepA_tdop
    putWord16le _msgDopsDepA_hdop
    putWord16le _msgDopsDepA_vdop

$(deriveSBP 'msgDopsDepA ''MsgDopsDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgDopsDepA_" . P.stripPrefix "_msgDopsDepA_"}
             ''MsgDopsDepA)
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
  { _msgPosEcefDepA_tow    :: Word32
    -- ^ GPS Time of Week
  , _msgPosEcefDepA_x      :: Double
    -- ^ ECEF X coordinate
  , _msgPosEcefDepA_y      :: Double
    -- ^ ECEF Y coordinate
  , _msgPosEcefDepA_z      :: Double
    -- ^ ECEF Z coordinate
  , _msgPosEcefDepA_accuracy :: Word16
    -- ^ Position accuracy estimate (not implemented). Defaults to 0.
  , _msgPosEcefDepA_n_sats :: Word8
    -- ^ Number of satellites used in solution
  , _msgPosEcefDepA_flags  :: Word8
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
    return MsgPosEcefDepA {..}

  put MsgPosEcefDepA {..} = do
    putWord32le _msgPosEcefDepA_tow
    putFloat64le _msgPosEcefDepA_x
    putFloat64le _msgPosEcefDepA_y
    putFloat64le _msgPosEcefDepA_z
    putWord16le _msgPosEcefDepA_accuracy
    putWord8 _msgPosEcefDepA_n_sats
    putWord8 _msgPosEcefDepA_flags

$(deriveSBP 'msgPosEcefDepA ''MsgPosEcefDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgPosEcefDepA_" . P.stripPrefix "_msgPosEcefDepA_"}
             ''MsgPosEcefDepA)
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
  { _msgPosLlhDepA_tow      :: Word32
    -- ^ GPS Time of Week
  , _msgPosLlhDepA_lat      :: Double
    -- ^ Latitude
  , _msgPosLlhDepA_lon      :: Double
    -- ^ Longitude
  , _msgPosLlhDepA_height   :: Double
    -- ^ Height
  , _msgPosLlhDepA_h_accuracy :: Word16
    -- ^ Horizontal position accuracy estimate (not implemented). Defaults to 0.
  , _msgPosLlhDepA_v_accuracy :: Word16
    -- ^ Vertical position accuracy estimate (not implemented). Defaults to 0.
  , _msgPosLlhDepA_n_sats   :: Word8
    -- ^ Number of satellites used in solution.
  , _msgPosLlhDepA_flags    :: Word8
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
    return MsgPosLlhDepA {..}

  put MsgPosLlhDepA {..} = do
    putWord32le _msgPosLlhDepA_tow
    putFloat64le _msgPosLlhDepA_lat
    putFloat64le _msgPosLlhDepA_lon
    putFloat64le _msgPosLlhDepA_height
    putWord16le _msgPosLlhDepA_h_accuracy
    putWord16le _msgPosLlhDepA_v_accuracy
    putWord8 _msgPosLlhDepA_n_sats
    putWord8 _msgPosLlhDepA_flags

$(deriveSBP 'msgPosLlhDepA ''MsgPosLlhDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgPosLlhDepA_" . P.stripPrefix "_msgPosLlhDepA_"}
             ''MsgPosLlhDepA)
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
  { _msgBaselineEcefDepA_tow    :: Word32
    -- ^ GPS Time of Week
  , _msgBaselineEcefDepA_x      :: Int32
    -- ^ Baseline ECEF X coordinate
  , _msgBaselineEcefDepA_y      :: Int32
    -- ^ Baseline ECEF Y coordinate
  , _msgBaselineEcefDepA_z      :: Int32
    -- ^ Baseline ECEF Z coordinate
  , _msgBaselineEcefDepA_accuracy :: Word16
    -- ^ Position accuracy estimate
  , _msgBaselineEcefDepA_n_sats :: Word8
    -- ^ Number of satellites used in solution
  , _msgBaselineEcefDepA_flags  :: Word8
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
    return MsgBaselineEcefDepA {..}

  put MsgBaselineEcefDepA {..} = do
    putWord32le _msgBaselineEcefDepA_tow
    putWord32le $ fromIntegral _msgBaselineEcefDepA_x
    putWord32le $ fromIntegral _msgBaselineEcefDepA_y
    putWord32le $ fromIntegral _msgBaselineEcefDepA_z
    putWord16le _msgBaselineEcefDepA_accuracy
    putWord8 _msgBaselineEcefDepA_n_sats
    putWord8 _msgBaselineEcefDepA_flags

$(deriveSBP 'msgBaselineEcefDepA ''MsgBaselineEcefDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgBaselineEcefDepA_" . P.stripPrefix "_msgBaselineEcefDepA_"}
             ''MsgBaselineEcefDepA)
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
  { _msgBaselineNedDepA_tow      :: Word32
    -- ^ GPS Time of Week
  , _msgBaselineNedDepA_n        :: Int32
    -- ^ Baseline North coordinate
  , _msgBaselineNedDepA_e        :: Int32
    -- ^ Baseline East coordinate
  , _msgBaselineNedDepA_d        :: Int32
    -- ^ Baseline Down coordinate
  , _msgBaselineNedDepA_h_accuracy :: Word16
    -- ^ Horizontal position accuracy estimate (not implemented). Defaults to 0.
  , _msgBaselineNedDepA_v_accuracy :: Word16
    -- ^ Vertical position accuracy estimate (not implemented). Defaults to 0.
  , _msgBaselineNedDepA_n_sats   :: Word8
    -- ^ Number of satellites used in solution
  , _msgBaselineNedDepA_flags    :: Word8
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
    return MsgBaselineNedDepA {..}

  put MsgBaselineNedDepA {..} = do
    putWord32le _msgBaselineNedDepA_tow
    putWord32le $ fromIntegral _msgBaselineNedDepA_n
    putWord32le $ fromIntegral _msgBaselineNedDepA_e
    putWord32le $ fromIntegral _msgBaselineNedDepA_d
    putWord16le _msgBaselineNedDepA_h_accuracy
    putWord16le _msgBaselineNedDepA_v_accuracy
    putWord8 _msgBaselineNedDepA_n_sats
    putWord8 _msgBaselineNedDepA_flags

$(deriveSBP 'msgBaselineNedDepA ''MsgBaselineNedDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgBaselineNedDepA_" . P.stripPrefix "_msgBaselineNedDepA_"}
             ''MsgBaselineNedDepA)
$(makeLenses ''MsgBaselineNedDepA)

msgVelEcefDepA :: Word16
msgVelEcefDepA = 0x0204

-- | SBP class for message MSG_VEL_ECEF_DEP_A (0x0204).
--
-- This message reports the velocity in Earth Centered Earth Fixed (ECEF)
-- coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
-- the matching time-of-week (tow).
data MsgVelEcefDepA = MsgVelEcefDepA
  { _msgVelEcefDepA_tow    :: Word32
    -- ^ GPS Time of Week
  , _msgVelEcefDepA_x      :: Int32
    -- ^ Velocity ECEF X coordinate
  , _msgVelEcefDepA_y      :: Int32
    -- ^ Velocity ECEF Y coordinate
  , _msgVelEcefDepA_z      :: Int32
    -- ^ Velocity ECEF Z coordinate
  , _msgVelEcefDepA_accuracy :: Word16
    -- ^ Velocity accuracy estimate (not implemented). Defaults to 0.
  , _msgVelEcefDepA_n_sats :: Word8
    -- ^ Number of satellites used in solution
  , _msgVelEcefDepA_flags  :: Word8
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
    return MsgVelEcefDepA {..}

  put MsgVelEcefDepA {..} = do
    putWord32le _msgVelEcefDepA_tow
    putWord32le $ fromIntegral _msgVelEcefDepA_x
    putWord32le $ fromIntegral _msgVelEcefDepA_y
    putWord32le $ fromIntegral _msgVelEcefDepA_z
    putWord16le _msgVelEcefDepA_accuracy
    putWord8 _msgVelEcefDepA_n_sats
    putWord8 _msgVelEcefDepA_flags

$(deriveSBP 'msgVelEcefDepA ''MsgVelEcefDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgVelEcefDepA_" . P.stripPrefix "_msgVelEcefDepA_"}
             ''MsgVelEcefDepA)
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
  { _msgVelNedDepA_tow      :: Word32
    -- ^ GPS Time of Week
  , _msgVelNedDepA_n        :: Int32
    -- ^ Velocity North coordinate
  , _msgVelNedDepA_e        :: Int32
    -- ^ Velocity East coordinate
  , _msgVelNedDepA_d        :: Int32
    -- ^ Velocity Down coordinate
  , _msgVelNedDepA_h_accuracy :: Word16
    -- ^ Horizontal velocity accuracy estimate (not implemented). Defaults to 0.
  , _msgVelNedDepA_v_accuracy :: Word16
    -- ^ Vertical velocity accuracy estimate (not implemented). Defaults to 0.
  , _msgVelNedDepA_n_sats   :: Word8
    -- ^ Number of satellites used in solution
  , _msgVelNedDepA_flags    :: Word8
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
    return MsgVelNedDepA {..}

  put MsgVelNedDepA {..} = do
    putWord32le _msgVelNedDepA_tow
    putWord32le $ fromIntegral _msgVelNedDepA_n
    putWord32le $ fromIntegral _msgVelNedDepA_e
    putWord32le $ fromIntegral _msgVelNedDepA_d
    putWord16le _msgVelNedDepA_h_accuracy
    putWord16le _msgVelNedDepA_v_accuracy
    putWord8 _msgVelNedDepA_n_sats
    putWord8 _msgVelNedDepA_flags

$(deriveSBP 'msgVelNedDepA ''MsgVelNedDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgVelNedDepA_" . P.stripPrefix "_msgVelNedDepA_"}
             ''MsgVelNedDepA)
$(makeLenses ''MsgVelNedDepA)

msgBaselineHeadingDepA :: Word16
msgBaselineHeadingDepA = 0x0207

-- | SBP class for message MSG_BASELINE_HEADING_DEP_A (0x0207).
--
-- This message reports the baseline heading pointing from the base station to
-- the rover relative to True North. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow).
data MsgBaselineHeadingDepA = MsgBaselineHeadingDepA
  { _msgBaselineHeadingDepA_tow   :: Word32
    -- ^ GPS Time of Week
  , _msgBaselineHeadingDepA_heading :: Word32
    -- ^ Heading
  , _msgBaselineHeadingDepA_n_sats :: Word8
    -- ^ Number of satellites used in solution
  , _msgBaselineHeadingDepA_flags :: Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgBaselineHeadingDepA where
  get = do
    _msgBaselineHeadingDepA_tow <- getWord32le
    _msgBaselineHeadingDepA_heading <- getWord32le
    _msgBaselineHeadingDepA_n_sats <- getWord8
    _msgBaselineHeadingDepA_flags <- getWord8
    return MsgBaselineHeadingDepA {..}

  put MsgBaselineHeadingDepA {..} = do
    putWord32le _msgBaselineHeadingDepA_tow
    putWord32le _msgBaselineHeadingDepA_heading
    putWord8 _msgBaselineHeadingDepA_n_sats
    putWord8 _msgBaselineHeadingDepA_flags

$(deriveSBP 'msgBaselineHeadingDepA ''MsgBaselineHeadingDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgBaselineHeadingDepA_" . P.stripPrefix "_msgBaselineHeadingDepA_"}
             ''MsgBaselineHeadingDepA)
$(makeLenses ''MsgBaselineHeadingDepA)
