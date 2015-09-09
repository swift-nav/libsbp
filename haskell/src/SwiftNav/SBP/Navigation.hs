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

import Control.Monad
import Control.Monad.Loops
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy hiding ( ByteString )
import Data.Int
import Data.Word

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
  { msgGpsTimeWn    :: Word16
    -- ^ GPS week number
  , msgGpsTimeTow   :: Word32
    -- ^ GPS time of week rounded to the nearest millisecond
  , msgGpsTimeNs    :: Int32
    -- ^ Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
    -- 500000)
  , msgGpsTimeFlags :: Word8
    -- ^ Status flags (reserved)
  } deriving ( Show, Read, Eq )

instance Binary MsgGpsTime where
  get = do
    msgGpsTimeWn <- getWord16le
    msgGpsTimeTow <- getWord32le
    msgGpsTimeNs <- liftM fromIntegral getWord32le
    msgGpsTimeFlags <- getWord8
    return MsgGpsTime {..}

  put MsgGpsTime {..} = do
    putWord16le msgGpsTimeWn
    putWord32le msgGpsTimeTow
    putWord32le $ fromIntegral msgGpsTimeNs
    putWord8 msgGpsTimeFlags

msgDops :: Word16
msgDops = 0x0206

-- | SBP class for message MSG_DOPS (0x0206).
--
-- This dilution of precision (DOP) message describes the effect of navigation
-- satellite geometry on positional measurement precision.
data MsgDops = MsgDops
  { msgDopsTow  :: Word32
    -- ^ GPS Time of Week
  , msgDopsGdop :: Word16
    -- ^ Geometric Dilution of Precision
  , msgDopsPdop :: Word16
    -- ^ Position Dilution of Precision
  , msgDopsTdop :: Word16
    -- ^ Time Dilution of Precision
  , msgDopsHdop :: Word16
    -- ^ Horizontal Dilution of Precision
  , msgDopsVdop :: Word16
    -- ^ Vertical Dilution of Precision
  } deriving ( Show, Read, Eq )

instance Binary MsgDops where
  get = do
    msgDopsTow <- getWord32le
    msgDopsGdop <- getWord16le
    msgDopsPdop <- getWord16le
    msgDopsTdop <- getWord16le
    msgDopsHdop <- getWord16le
    msgDopsVdop <- getWord16le
    return MsgDops {..}

  put MsgDops {..} = do
    putWord32le msgDopsTow
    putWord16le msgDopsGdop
    putWord16le msgDopsPdop
    putWord16le msgDopsTdop
    putWord16le msgDopsHdop
    putWord16le msgDopsVdop

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
  { msgPosEcefTow      :: Word32
    -- ^ GPS Time of Week
  , msgPosEcefX        :: Double
    -- ^ ECEF X coordinate
  , msgPosEcefY        :: Double
    -- ^ ECEF Y coordinate
  , msgPosEcefZ        :: Double
    -- ^ ECEF Z coordinate
  , msgPosEcefAccuracy :: Word16
    -- ^ Position accuracy estimate (not implemented). Defaults to 0.
  , msgPosEcefNSats    :: Word8
    -- ^ Number of satellites used in solution
  , msgPosEcefFlags    :: Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgPosEcef where
  get = do
    msgPosEcefTow <- getWord32le
    msgPosEcefX <- getFloat64le
    msgPosEcefY <- getFloat64le
    msgPosEcefZ <- getFloat64le
    msgPosEcefAccuracy <- getWord16le
    msgPosEcefNSats <- getWord8
    msgPosEcefFlags <- getWord8
    return MsgPosEcef {..}

  put MsgPosEcef {..} = do
    putWord32le msgPosEcefTow
    putFloat64le msgPosEcefX
    putFloat64le msgPosEcefY
    putFloat64le msgPosEcefZ
    putWord16le msgPosEcefAccuracy
    putWord8 msgPosEcefNSats
    putWord8 msgPosEcefFlags

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
  { msgPosLlhTow        :: Word32
    -- ^ GPS Time of Week
  , msgPosLlhLat        :: Double
    -- ^ Latitude
  , msgPosLlhLon        :: Double
    -- ^ Longitude
  , msgPosLlhHeight     :: Double
    -- ^ Height
  , msgPosLlhHAccuracy  :: Word16
    -- ^ Horizontal position accuracy estimate (not implemented). Defaults to 0.
  , msgPosLlhVAccuracy  :: Word16
    -- ^ Vertical position accuracy estimate (not implemented). Defaults to 0.
  , msgPosLlhNSats      :: Word8
    -- ^ Number of satellites used in solution.
  , msgPosLlhFlags      :: Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgPosLlh where
  get = do
    msgPosLlhTow <- getWord32le
    msgPosLlhLat <- getFloat64le
    msgPosLlhLon <- getFloat64le
    msgPosLlhHeight <- getFloat64le
    msgPosLlhHAccuracy <- getWord16le
    msgPosLlhVAccuracy <- getWord16le
    msgPosLlhNSats <- getWord8
    msgPosLlhFlags <- getWord8
    return MsgPosLlh {..}

  put MsgPosLlh {..} = do
    putWord32le msgPosLlhTow
    putFloat64le msgPosLlhLat
    putFloat64le msgPosLlhLon
    putFloat64le msgPosLlhHeight
    putWord16le msgPosLlhHAccuracy
    putWord16le msgPosLlhVAccuracy
    putWord8 msgPosLlhNSats
    putWord8 msgPosLlhFlags

msgBaselineEcef :: Word16
msgBaselineEcef = 0x0202

-- | SBP class for message MSG_BASELINE_ECEF (0x0202).
--
-- This message reports the baseline solution in Earth Centered Earth Fixed
-- (ECEF) coordinates. This baseline is the relative vector distance from the
-- base station to the rover receiver. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow).
data MsgBaselineEcef = MsgBaselineEcef
  { msgBaselineEcefTow      :: Word32
    -- ^ GPS Time of Week
  , msgBaselineEcefX        :: Int32
    -- ^ Baseline ECEF X coordinate
  , msgBaselineEcefY        :: Int32
    -- ^ Baseline ECEF Y coordinate
  , msgBaselineEcefZ        :: Int32
    -- ^ Baseline ECEF Z coordinate
  , msgBaselineEcefAccuracy :: Word16
    -- ^ Position accuracy estimate (not implemented). Defaults to 0.
  , msgBaselineEcefNSats    :: Word8
    -- ^ Number of satellites used in solution
  , msgBaselineEcefFlags    :: Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgBaselineEcef where
  get = do
    msgBaselineEcefTow <- getWord32le
    msgBaselineEcefX <- liftM fromIntegral getWord32le
    msgBaselineEcefY <- liftM fromIntegral getWord32le
    msgBaselineEcefZ <- liftM fromIntegral getWord32le
    msgBaselineEcefAccuracy <- getWord16le
    msgBaselineEcefNSats <- getWord8
    msgBaselineEcefFlags <- getWord8
    return MsgBaselineEcef {..}

  put MsgBaselineEcef {..} = do
    putWord32le msgBaselineEcefTow
    putWord32le $ fromIntegral msgBaselineEcefX
    putWord32le $ fromIntegral msgBaselineEcefY
    putWord32le $ fromIntegral msgBaselineEcefZ
    putWord16le msgBaselineEcefAccuracy
    putWord8 msgBaselineEcefNSats
    putWord8 msgBaselineEcefFlags

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
  { msgBaselineNedTow        :: Word32
    -- ^ GPS Time of Week
  , msgBaselineNedN          :: Int32
    -- ^ Baseline North coordinate
  , msgBaselineNedE          :: Int32
    -- ^ Baseline East coordinate
  , msgBaselineNedD          :: Int32
    -- ^ Baseline Down coordinate
  , msgBaselineNedHAccuracy  :: Word16
    -- ^ Horizontal position accuracy estimate (not implemented). Defaults to 0.
  , msgBaselineNedVAccuracy  :: Word16
    -- ^ Vertical position accuracy estimate (not implemented). Defaults to 0.
  , msgBaselineNedNSats      :: Word8
    -- ^ Number of satellites used in solution
  , msgBaselineNedFlags      :: Word8
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgBaselineNed where
  get = do
    msgBaselineNedTow <- getWord32le
    msgBaselineNedN <- liftM fromIntegral getWord32le
    msgBaselineNedE <- liftM fromIntegral getWord32le
    msgBaselineNedD <- liftM fromIntegral getWord32le
    msgBaselineNedHAccuracy <- getWord16le
    msgBaselineNedVAccuracy <- getWord16le
    msgBaselineNedNSats <- getWord8
    msgBaselineNedFlags <- getWord8
    return MsgBaselineNed {..}

  put MsgBaselineNed {..} = do
    putWord32le msgBaselineNedTow
    putWord32le $ fromIntegral msgBaselineNedN
    putWord32le $ fromIntegral msgBaselineNedE
    putWord32le $ fromIntegral msgBaselineNedD
    putWord16le msgBaselineNedHAccuracy
    putWord16le msgBaselineNedVAccuracy
    putWord8 msgBaselineNedNSats
    putWord8 msgBaselineNedFlags

msgVelEcef :: Word16
msgVelEcef = 0x0204

-- | SBP class for message MSG_VEL_ECEF (0x0204).
--
-- This message reports the velocity in Earth Centered Earth Fixed (ECEF)
-- coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
-- the matching time-of-week (tow).
data MsgVelEcef = MsgVelEcef
  { msgVelEcefTow      :: Word32
    -- ^ GPS Time of Week
  , msgVelEcefX        :: Int32
    -- ^ Velocity ECEF X coordinate
  , msgVelEcefY        :: Int32
    -- ^ Velocity ECEF Y coordinate
  , msgVelEcefZ        :: Int32
    -- ^ Velocity ECEF Z coordinate
  , msgVelEcefAccuracy :: Word16
    -- ^ Velocity accuracy estimate (not implemented). Defaults to 0.
  , msgVelEcefNSats    :: Word8
    -- ^ Number of satellites used in solution
  , msgVelEcefFlags    :: Word8
    -- ^ Status flags (reserved)
  } deriving ( Show, Read, Eq )

instance Binary MsgVelEcef where
  get = do
    msgVelEcefTow <- getWord32le
    msgVelEcefX <- liftM fromIntegral getWord32le
    msgVelEcefY <- liftM fromIntegral getWord32le
    msgVelEcefZ <- liftM fromIntegral getWord32le
    msgVelEcefAccuracy <- getWord16le
    msgVelEcefNSats <- getWord8
    msgVelEcefFlags <- getWord8
    return MsgVelEcef {..}

  put MsgVelEcef {..} = do
    putWord32le msgVelEcefTow
    putWord32le $ fromIntegral msgVelEcefX
    putWord32le $ fromIntegral msgVelEcefY
    putWord32le $ fromIntegral msgVelEcefZ
    putWord16le msgVelEcefAccuracy
    putWord8 msgVelEcefNSats
    putWord8 msgVelEcefFlags

msgVelNed :: Word16
msgVelNed = 0x0205

-- | SBP class for message MSG_VEL_NED (0x0205).
--
-- This message reports the velocity in local North East Down (NED)
-- coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with
-- the matching time-of-week (tow).
data MsgVelNed = MsgVelNed
  { msgVelNedTow        :: Word32
    -- ^ GPS Time of Week
  , msgVelNedN          :: Int32
    -- ^ Velocity North coordinate
  , msgVelNedE          :: Int32
    -- ^ Velocity East coordinate
  , msgVelNedD          :: Int32
    -- ^ Velocity Down coordinate
  , msgVelNedHAccuracy  :: Word16
    -- ^ Horizontal velocity accuracy estimate (not implemented). Defaults to 0.
  , msgVelNedVAccuracy  :: Word16
    -- ^ Vertical velocity accuracy estimate (not implemented). Defaults to 0.
  , msgVelNedNSats      :: Word8
    -- ^ Number of satellites used in solution
  , msgVelNedFlags      :: Word8
    -- ^ Status flags (reserved)
  } deriving ( Show, Read, Eq )

instance Binary MsgVelNed where
  get = do
    msgVelNedTow <- getWord32le
    msgVelNedN <- liftM fromIntegral getWord32le
    msgVelNedE <- liftM fromIntegral getWord32le
    msgVelNedD <- liftM fromIntegral getWord32le
    msgVelNedHAccuracy <- getWord16le
    msgVelNedVAccuracy <- getWord16le
    msgVelNedNSats <- getWord8
    msgVelNedFlags <- getWord8
    return MsgVelNed {..}

  put MsgVelNed {..} = do
    putWord32le msgVelNedTow
    putWord32le $ fromIntegral msgVelNedN
    putWord32le $ fromIntegral msgVelNedE
    putWord32le $ fromIntegral msgVelNedD
    putWord16le msgVelNedHAccuracy
    putWord16le msgVelNedVAccuracy
    putWord8 msgVelNedNSats
    putWord8 msgVelNedFlags
