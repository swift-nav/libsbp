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
import Control.Monad.Loops
import Data.Aeson.TH (deriveJSON, defaultOptions, fieldLabelModifier)
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy hiding ( ByteString )
import Data.Int
import Data.Word
import SwiftNav.SBP.Encoding

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
  { msgGpsTime_wn   :: Word16
    -- ^ GPS week number
  , msgGpsTime_tow  :: Word32
    -- ^ GPS time of week rounded to the nearest millisecond
  , msgGpsTime_ns   :: Int32
    -- ^ Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    -- 500000)
  , msgGpsTime_flags :: Word8
    -- ^ Status flags (reserved)
  } deriving ( Show, Read, Eq )

instance Binary MsgGpsTime where
  get = do
    msgGpsTime_wn <- getWord16le
    msgGpsTime_tow <- getWord32le
    msgGpsTime_ns <- liftM fromIntegral getWord32le
    msgGpsTime_flags <- getWord8
    return MsgGpsTime {..}

  put MsgGpsTime {..} = do
    putWord16le msgGpsTime_wn
    putWord32le msgGpsTime_tow
    putWord32le $ fromIntegral msgGpsTime_ns
    putWord8 msgGpsTime_flags

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgGpsTime_" . stripPrefix "msgGpsTime_"}
             ''MsgGpsTime)

msgDops :: Word16
msgDops = 0x0206

-- | SBP class for message MSG_DOPS (0x0206).
--
-- This dilution of precision (DOP) message describes the effect of navigation
-- satellite geometry on positional measurement precision.
data MsgDops = MsgDops
  { msgDops_tow :: Word32
    -- ^ GPS Time of Week
  , msgDops_gdop :: Word16
    -- ^ Geometric Dilution of Precision
  , msgDops_pdop :: Word16
    -- ^ Position Dilution of Precision
  , msgDops_tdop :: Word16
    -- ^ Time Dilution of Precision
  , msgDops_hdop :: Word16
    -- ^ Horizontal Dilution of Precision
  , msgDops_vdop :: Word16
    -- ^ Vertical Dilution of Precision
  } deriving ( Show, Read, Eq )

instance Binary MsgDops where
  get = do
    msgDops_tow <- getWord32le
    msgDops_gdop <- getWord16le
    msgDops_pdop <- getWord16le
    msgDops_tdop <- getWord16le
    msgDops_hdop <- getWord16le
    msgDops_vdop <- getWord16le
    return MsgDops {..}

  put MsgDops {..} = do
    putWord32le msgDops_tow
    putWord16le msgDops_gdop
    putWord16le msgDops_pdop
    putWord16le msgDops_tdop
    putWord16le msgDops_hdop
    putWord16le msgDops_vdop

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgDops_" . stripPrefix "msgDops_"}
             ''MsgDops)

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
  { msgPosEcef_tow     :: Word32
    -- ^ GPS Time of Week
  , msgPosEcef_x       :: Double
    -- ^ ECEF X coordinate
  , msgPosEcef_y       :: Double
    -- ^ ECEF Y coordinate
  , msgPosEcef_z       :: Double
    -- ^ ECEF Z coordinate
  , msgPosEcef_accuracy :: Word16
    -- ^ Position accuracy estimate (not implemented). Defaults to 0.
  , msgPosEcef_n_sats  :: Word8
    -- ^ Number of satellites used in solution
  , msgPosEcef_flags   :: Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgPosEcef where
  get = do
    msgPosEcef_tow <- getWord32le
    msgPosEcef_x <- getFloat64le
    msgPosEcef_y <- getFloat64le
    msgPosEcef_z <- getFloat64le
    msgPosEcef_accuracy <- getWord16le
    msgPosEcef_n_sats <- getWord8
    msgPosEcef_flags <- getWord8
    return MsgPosEcef {..}

  put MsgPosEcef {..} = do
    putWord32le msgPosEcef_tow
    putFloat64le msgPosEcef_x
    putFloat64le msgPosEcef_y
    putFloat64le msgPosEcef_z
    putWord16le msgPosEcef_accuracy
    putWord8 msgPosEcef_n_sats
    putWord8 msgPosEcef_flags

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgPosEcef_" . stripPrefix "msgPosEcef_"}
             ''MsgPosEcef)

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
  { msgPosLlh_tow       :: Word32
    -- ^ GPS Time of Week
  , msgPosLlh_lat       :: Double
    -- ^ Latitude
  , msgPosLlh_lon       :: Double
    -- ^ Longitude
  , msgPosLlh_height    :: Double
    -- ^ Height
  , msgPosLlh_h_accuracy :: Word16
    -- ^ Horizontal position accuracy estimate (not implemented). Defaults to 0.
  , msgPosLlh_v_accuracy :: Word16
    -- ^ Vertical position accuracy estimate (not implemented). Defaults to 0.
  , msgPosLlh_n_sats    :: Word8
    -- ^ Number of satellites used in solution.
  , msgPosLlh_flags     :: Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgPosLlh where
  get = do
    msgPosLlh_tow <- getWord32le
    msgPosLlh_lat <- getFloat64le
    msgPosLlh_lon <- getFloat64le
    msgPosLlh_height <- getFloat64le
    msgPosLlh_h_accuracy <- getWord16le
    msgPosLlh_v_accuracy <- getWord16le
    msgPosLlh_n_sats <- getWord8
    msgPosLlh_flags <- getWord8
    return MsgPosLlh {..}

  put MsgPosLlh {..} = do
    putWord32le msgPosLlh_tow
    putFloat64le msgPosLlh_lat
    putFloat64le msgPosLlh_lon
    putFloat64le msgPosLlh_height
    putWord16le msgPosLlh_h_accuracy
    putWord16le msgPosLlh_v_accuracy
    putWord8 msgPosLlh_n_sats
    putWord8 msgPosLlh_flags

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgPosLlh_" . stripPrefix "msgPosLlh_"}
             ''MsgPosLlh)

msgBaselineEcef :: Word16
msgBaselineEcef = 0x0202

-- | SBP class for message MSG_BASELINE_ECEF (0x0202).
--
-- This message reports the baseline solution in Earth Centered Earth Fixed
-- (ECEF) coordinates. This baseline is the relative vector distance from the
-- base station to the rover receiver. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow).
data MsgBaselineEcef = MsgBaselineEcef
  { msgBaselineEcef_tow     :: Word32
    -- ^ GPS Time of Week
  , msgBaselineEcef_x       :: Int32
    -- ^ Baseline ECEF X coordinate
  , msgBaselineEcef_y       :: Int32
    -- ^ Baseline ECEF Y coordinate
  , msgBaselineEcef_z       :: Int32
    -- ^ Baseline ECEF Z coordinate
  , msgBaselineEcef_accuracy :: Word16
    -- ^ Position accuracy estimate (not implemented). Defaults to 0.
  , msgBaselineEcef_n_sats  :: Word8
    -- ^ Number of satellites used in solution
  , msgBaselineEcef_flags   :: Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgBaselineEcef where
  get = do
    msgBaselineEcef_tow <- getWord32le
    msgBaselineEcef_x <- liftM fromIntegral getWord32le
    msgBaselineEcef_y <- liftM fromIntegral getWord32le
    msgBaselineEcef_z <- liftM fromIntegral getWord32le
    msgBaselineEcef_accuracy <- getWord16le
    msgBaselineEcef_n_sats <- getWord8
    msgBaselineEcef_flags <- getWord8
    return MsgBaselineEcef {..}

  put MsgBaselineEcef {..} = do
    putWord32le msgBaselineEcef_tow
    putWord32le $ fromIntegral msgBaselineEcef_x
    putWord32le $ fromIntegral msgBaselineEcef_y
    putWord32le $ fromIntegral msgBaselineEcef_z
    putWord16le msgBaselineEcef_accuracy
    putWord8 msgBaselineEcef_n_sats
    putWord8 msgBaselineEcef_flags

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgBaselineEcef_" . stripPrefix "msgBaselineEcef_"}
             ''MsgBaselineEcef)

msgBaselineNed :: Word16
msgBaselineNed = 0x0203

-- | SBP class for message MSG_BASELINE_NED (0x0203).
--
-- This message reports the baseline solution in North East Down (NED)
-- coordinates. This baseline is the relative vector distance from the base
-- station to the rover receiver, and NED coordinate system is defined at the
-- local tangent plane centered at the base station position.  The full GPS
-- time is given by the preceding MSG_GPS_TIME with the matching time-of-week
-- (tow).
data MsgBaselineNed = MsgBaselineNed
  { msgBaselineNed_tow       :: Word32
    -- ^ GPS Time of Week
  , msgBaselineNed_n         :: Int32
    -- ^ Baseline North coordinate
  , msgBaselineNed_e         :: Int32
    -- ^ Baseline East coordinate
  , msgBaselineNed_d         :: Int32
    -- ^ Baseline Down coordinate
  , msgBaselineNed_h_accuracy :: Word16
    -- ^ Horizontal position accuracy estimate (not implemented). Defaults to 0.
  , msgBaselineNed_v_accuracy :: Word16
    -- ^ Vertical position accuracy estimate (not implemented). Defaults to 0.
  , msgBaselineNed_n_sats    :: Word8
    -- ^ Number of satellites used in solution
  , msgBaselineNed_flags     :: Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgBaselineNed where
  get = do
    msgBaselineNed_tow <- getWord32le
    msgBaselineNed_n <- liftM fromIntegral getWord32le
    msgBaselineNed_e <- liftM fromIntegral getWord32le
    msgBaselineNed_d <- liftM fromIntegral getWord32le
    msgBaselineNed_h_accuracy <- getWord16le
    msgBaselineNed_v_accuracy <- getWord16le
    msgBaselineNed_n_sats <- getWord8
    msgBaselineNed_flags <- getWord8
    return MsgBaselineNed {..}

  put MsgBaselineNed {..} = do
    putWord32le msgBaselineNed_tow
    putWord32le $ fromIntegral msgBaselineNed_n
    putWord32le $ fromIntegral msgBaselineNed_e
    putWord32le $ fromIntegral msgBaselineNed_d
    putWord16le msgBaselineNed_h_accuracy
    putWord16le msgBaselineNed_v_accuracy
    putWord8 msgBaselineNed_n_sats
    putWord8 msgBaselineNed_flags

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgBaselineNed_" . stripPrefix "msgBaselineNed_"}
             ''MsgBaselineNed)

msgVelEcef :: Word16
msgVelEcef = 0x0204

-- | SBP class for message MSG_VEL_ECEF (0x0204).
--
-- This message reports the velocity in Earth Centered Earth Fixed (ECEF)
-- coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
-- the matching time-of-week (tow).
data MsgVelEcef = MsgVelEcef
  { msgVelEcef_tow     :: Word32
    -- ^ GPS Time of Week
  , msgVelEcef_x       :: Int32
    -- ^ Velocity ECEF X coordinate
  , msgVelEcef_y       :: Int32
    -- ^ Velocity ECEF Y coordinate
  , msgVelEcef_z       :: Int32
    -- ^ Velocity ECEF Z coordinate
  , msgVelEcef_accuracy :: Word16
    -- ^ Velocity accuracy estimate (not implemented). Defaults to 0.
  , msgVelEcef_n_sats  :: Word8
    -- ^ Number of satellites used in solution
  , msgVelEcef_flags   :: Word8
    -- ^ Status flags (reserved)
  } deriving ( Show, Read, Eq )

instance Binary MsgVelEcef where
  get = do
    msgVelEcef_tow <- getWord32le
    msgVelEcef_x <- liftM fromIntegral getWord32le
    msgVelEcef_y <- liftM fromIntegral getWord32le
    msgVelEcef_z <- liftM fromIntegral getWord32le
    msgVelEcef_accuracy <- getWord16le
    msgVelEcef_n_sats <- getWord8
    msgVelEcef_flags <- getWord8
    return MsgVelEcef {..}

  put MsgVelEcef {..} = do
    putWord32le msgVelEcef_tow
    putWord32le $ fromIntegral msgVelEcef_x
    putWord32le $ fromIntegral msgVelEcef_y
    putWord32le $ fromIntegral msgVelEcef_z
    putWord16le msgVelEcef_accuracy
    putWord8 msgVelEcef_n_sats
    putWord8 msgVelEcef_flags

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgVelEcef_" . stripPrefix "msgVelEcef_"}
             ''MsgVelEcef)

msgVelNed :: Word16
msgVelNed = 0x0205

-- | SBP class for message MSG_VEL_NED (0x0205).
--
-- This message reports the velocity in local North East Down (NED)
-- coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
-- the matching time-of-week (tow).
data MsgVelNed = MsgVelNed
  { msgVelNed_tow       :: Word32
    -- ^ GPS Time of Week
  , msgVelNed_n         :: Int32
    -- ^ Velocity North coordinate
  , msgVelNed_e         :: Int32
    -- ^ Velocity East coordinate
  , msgVelNed_d         :: Int32
    -- ^ Velocity Down coordinate
  , msgVelNed_h_accuracy :: Word16
    -- ^ Horizontal velocity accuracy estimate (not implemented). Defaults to 0.
  , msgVelNed_v_accuracy :: Word16
    -- ^ Vertical velocity accuracy estimate (not implemented). Defaults to 0.
  , msgVelNed_n_sats    :: Word8
    -- ^ Number of satellites used in solution
  , msgVelNed_flags     :: Word8
    -- ^ Status flags (reserved)
  } deriving ( Show, Read, Eq )

instance Binary MsgVelNed where
  get = do
    msgVelNed_tow <- getWord32le
    msgVelNed_n <- liftM fromIntegral getWord32le
    msgVelNed_e <- liftM fromIntegral getWord32le
    msgVelNed_d <- liftM fromIntegral getWord32le
    msgVelNed_h_accuracy <- getWord16le
    msgVelNed_v_accuracy <- getWord16le
    msgVelNed_n_sats <- getWord8
    msgVelNed_flags <- getWord8
    return MsgVelNed {..}

  put MsgVelNed {..} = do
    putWord32le msgVelNed_tow
    putWord32le $ fromIntegral msgVelNed_n
    putWord32le $ fromIntegral msgVelNed_e
    putWord32le $ fromIntegral msgVelNed_d
    putWord16le msgVelNed_h_accuracy
    putWord16le msgVelNed_v_accuracy
    putWord8 msgVelNed_n_sats
    putWord8 msgVelNed_flags

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgVelNed_" . stripPrefix "msgVelNed_"}
             ''MsgVelNed)
