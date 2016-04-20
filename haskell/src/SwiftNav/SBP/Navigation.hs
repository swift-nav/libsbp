{-# OPTIONS_GHC -fno-warn-unused-imports #-}
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

import BasicPrelude
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
msgGpsTime = 0x0100

-- | SBP class for message MSG_GPS_TIME (0x0100).
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
  { _msgGpsTime_wn  :: Word16
    -- ^ GPS week number
  , _msgGpsTime_tow :: Word32
    -- ^ GPS time of week rounded to the nearest millisecond
  , _msgGpsTime_ns  :: Int32
    -- ^ Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    -- 500000)
  , _msgGpsTime_flags :: Word8
    -- ^ Status flags (reserved)
  } deriving ( Show, Read, Eq )

instance Binary MsgGpsTime where
  get = do
    _msgGpsTime_wn <- getWord16le
    _msgGpsTime_tow <- getWord32le
    _msgGpsTime_ns <- liftM fromIntegral getWord32le
    _msgGpsTime_flags <- getWord8
    return MsgGpsTime {..}

  put MsgGpsTime {..} = do
    putWord16le _msgGpsTime_wn
    putWord32le _msgGpsTime_tow
    putWord32le $ fromIntegral _msgGpsTime_ns
    putWord8 _msgGpsTime_flags

$(deriveSBP 'msgGpsTime ''MsgGpsTime)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgGpsTime_" . stripPrefix "_msgGpsTime_"}
             ''MsgGpsTime)
$(makeLenses ''MsgGpsTime)

msgDops :: Word16
msgDops = 0x0206

-- | SBP class for message MSG_DOPS (0x0206).
--
-- This dilution of precision (DOP) message describes the effect of navigation
-- satellite geometry on positional measurement precision.
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
  } deriving ( Show, Read, Eq )

instance Binary MsgDops where
  get = do
    _msgDops_tow <- getWord32le
    _msgDops_gdop <- getWord16le
    _msgDops_pdop <- getWord16le
    _msgDops_tdop <- getWord16le
    _msgDops_hdop <- getWord16le
    _msgDops_vdop <- getWord16le
    return MsgDops {..}

  put MsgDops {..} = do
    putWord32le _msgDops_tow
    putWord16le _msgDops_gdop
    putWord16le _msgDops_pdop
    putWord16le _msgDops_tdop
    putWord16le _msgDops_hdop
    putWord16le _msgDops_vdop

$(deriveSBP 'msgDops ''MsgDops)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgDops_" . stripPrefix "_msgDops_"}
             ''MsgDops)
$(makeLenses ''MsgDops)

msgPosEcef :: Word16
msgPosEcef = 0x0200

-- | SBP class for message MSG_POS_ECEF (0x0200).
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
    -- ^ Position accuracy estimate (not implemented). Defaults to 0.
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

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgPosEcef_" . stripPrefix "_msgPosEcef_"}
             ''MsgPosEcef)
$(makeLenses ''MsgPosEcef)

msgPosLlh :: Word16
msgPosLlh = 0x0201

-- | SBP class for message MSG_POS_LLH (0x0201).
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
    -- ^ Height
  , _msgPosLlh_h_accuracy :: Word16
    -- ^ Horizontal position accuracy estimate (not implemented). Defaults to 0.
  , _msgPosLlh_v_accuracy :: Word16
    -- ^ Vertical position accuracy estimate (not implemented). Defaults to 0.
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

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgPosLlh_" . stripPrefix "_msgPosLlh_"}
             ''MsgPosLlh)
$(makeLenses ''MsgPosLlh)

msgBaselineEcef :: Word16
msgBaselineEcef = 0x0202

-- | SBP class for message MSG_BASELINE_ECEF (0x0202).
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
    -- ^ Position accuracy estimate (not implemented). Defaults to 0.
  , _msgBaselineEcef_n_sats :: Word8
    -- ^ Number of satellites used in solution
  , _msgBaselineEcef_flags  :: Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgBaselineEcef where
  get = do
    _msgBaselineEcef_tow <- getWord32le
    _msgBaselineEcef_x <- liftM fromIntegral getWord32le
    _msgBaselineEcef_y <- liftM fromIntegral getWord32le
    _msgBaselineEcef_z <- liftM fromIntegral getWord32le
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

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgBaselineEcef_" . stripPrefix "_msgBaselineEcef_"}
             ''MsgBaselineEcef)
$(makeLenses ''MsgBaselineEcef)

msgBaselineNed :: Word16
msgBaselineNed = 0x0203

-- | SBP class for message MSG_BASELINE_NED (0x0203).
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
    -- ^ Horizontal position accuracy estimate (not implemented). Defaults to 0.
  , _msgBaselineNed_v_accuracy :: Word16
    -- ^ Vertical position accuracy estimate (not implemented). Defaults to 0.
  , _msgBaselineNed_n_sats   :: Word8
    -- ^ Number of satellites used in solution
  , _msgBaselineNed_flags    :: Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgBaselineNed where
  get = do
    _msgBaselineNed_tow <- getWord32le
    _msgBaselineNed_n <- liftM fromIntegral getWord32le
    _msgBaselineNed_e <- liftM fromIntegral getWord32le
    _msgBaselineNed_d <- liftM fromIntegral getWord32le
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

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgBaselineNed_" . stripPrefix "_msgBaselineNed_"}
             ''MsgBaselineNed)
$(makeLenses ''MsgBaselineNed)

msgVelEcef :: Word16
msgVelEcef = 0x0204

-- | SBP class for message MSG_VEL_ECEF (0x0204).
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
    -- ^ Velocity accuracy estimate (not implemented). Defaults to 0.
  , _msgVelEcef_n_sats :: Word8
    -- ^ Number of satellites used in solution
  , _msgVelEcef_flags  :: Word8
    -- ^ Status flags (reserved)
  } deriving ( Show, Read, Eq )

instance Binary MsgVelEcef where
  get = do
    _msgVelEcef_tow <- getWord32le
    _msgVelEcef_x <- liftM fromIntegral getWord32le
    _msgVelEcef_y <- liftM fromIntegral getWord32le
    _msgVelEcef_z <- liftM fromIntegral getWord32le
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

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgVelEcef_" . stripPrefix "_msgVelEcef_"}
             ''MsgVelEcef)
$(makeLenses ''MsgVelEcef)

msgVelNed :: Word16
msgVelNed = 0x0205

-- | SBP class for message MSG_VEL_NED (0x0205).
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
    -- ^ Horizontal velocity accuracy estimate (not implemented). Defaults to 0.
  , _msgVelNed_v_accuracy :: Word16
    -- ^ Vertical velocity accuracy estimate (not implemented). Defaults to 0.
  , _msgVelNed_n_sats   :: Word8
    -- ^ Number of satellites used in solution
  , _msgVelNed_flags    :: Word8
    -- ^ Status flags (reserved)
  } deriving ( Show, Read, Eq )

instance Binary MsgVelNed where
  get = do
    _msgVelNed_tow <- getWord32le
    _msgVelNed_n <- liftM fromIntegral getWord32le
    _msgVelNed_e <- liftM fromIntegral getWord32le
    _msgVelNed_d <- liftM fromIntegral getWord32le
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

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgVelNed_" . stripPrefix "_msgVelNed_"}
             ''MsgVelNed)
$(makeLenses ''MsgVelNed)

msgBaselineHeading :: Word16
msgBaselineHeading = 0x0207

-- | SBP class for message MSG_BASELINE_HEADING (0x0207).
--
-- This message reports the baseline heading pointing from the base station to
-- the rover relative to True North. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow).
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

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgBaselineHeading_" . stripPrefix "_msgBaselineHeading_"}
             ''MsgBaselineHeading)
$(makeLenses ''MsgBaselineHeading)
