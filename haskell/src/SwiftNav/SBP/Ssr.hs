{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Ssr
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Precise State Space Representation (SSR) corrections format

module SwiftNav.SBP.Ssr
  ( module SwiftNav.SBP.Ssr
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
import SwiftNav.SBP.Gnss

{-# ANN module ("HLint: ignore Use camelCase"::String) #-}
{-# ANN module ("HLint: ignore Redundant do"::String) #-}
{-# ANN module ("HLint: ignore Use newtype instead of data"::String) #-}


-- | CodeBiasesContent.
--
-- Code biases are to be added to pseudorange. The corrections are conform with
-- typical RTCMv3 MT1059 and 1065.
data CodeBiasesContent = CodeBiasesContent
  { _codeBiasesContent_code :: !Word8
    -- ^ Signal constellation, band and code
  , _codeBiasesContent_value :: !Int16
    -- ^ Code bias value
  } deriving ( Show, Read, Eq )

instance Binary CodeBiasesContent where
  get = do
    _codeBiasesContent_code <- getWord8
    _codeBiasesContent_value <- fromIntegral <$> getWord16le
    pure CodeBiasesContent {..}

  put CodeBiasesContent {..} = do
    putWord8 _codeBiasesContent_code
    (putWord16le . fromIntegral) _codeBiasesContent_value

$(makeJSON "_codeBiasesContent_" ''CodeBiasesContent)
$(makeLenses ''CodeBiasesContent)

-- | PhaseBiasesContent.
--
-- Phase biases are to be added to carrier phase measurements. The corrections
-- are conform with typical RTCMv3 MT1059 and 1065.
data PhaseBiasesContent = PhaseBiasesContent
  { _phaseBiasesContent_code                     :: !Word8
    -- ^ Signal constellation, band and code
  , _phaseBiasesContent_integer_indicator        :: !Word8
    -- ^ Indicator for integer property
  , _phaseBiasesContent_widelane_integer_indicator :: !Word8
    -- ^ Indicator for two groups of Wide-Lane(s) integer property
  , _phaseBiasesContent_discontinuity_counter    :: !Word8
    -- ^ Signal phase discontinuity counter.  Increased for every discontinuity
    -- in phase.
  , _phaseBiasesContent_bias                     :: !Int32
    -- ^ Phase bias for specified signal
  } deriving ( Show, Read, Eq )

instance Binary PhaseBiasesContent where
  get = do
    _phaseBiasesContent_code <- getWord8
    _phaseBiasesContent_integer_indicator <- getWord8
    _phaseBiasesContent_widelane_integer_indicator <- getWord8
    _phaseBiasesContent_discontinuity_counter <- getWord8
    _phaseBiasesContent_bias <- fromIntegral <$> getWord32le
    pure PhaseBiasesContent {..}

  put PhaseBiasesContent {..} = do
    putWord8 _phaseBiasesContent_code
    putWord8 _phaseBiasesContent_integer_indicator
    putWord8 _phaseBiasesContent_widelane_integer_indicator
    putWord8 _phaseBiasesContent_discontinuity_counter
    (putWord32le . fromIntegral) _phaseBiasesContent_bias

$(makeJSON "_phaseBiasesContent_" ''PhaseBiasesContent)
$(makeLenses ''PhaseBiasesContent)

msgSsrOrbitClock :: Word16
msgSsrOrbitClock = 0x05DD

-- | SBP class for message MSG_SSR_ORBIT_CLOCK (0x05DD).
--
-- The precise orbit and clock correction message is  to be applied as a delta
-- correction to broadcast  ephemeris and is typically an equivalent to the
-- 1060 and 1066 RTCM message types
data MsgSsrOrbitClock = MsgSsrOrbitClock
  { _msgSsrOrbitClock_time          :: !GpsTimeSec
    -- ^ GNSS reference time of the correction
  , _msgSsrOrbitClock_sid           :: !GnssSignal
    -- ^ GNSS signal identifier (16 bit)
  , _msgSsrOrbitClock_update_interval :: !Word8
    -- ^ Update interval between consecutive corrections
  , _msgSsrOrbitClock_iod_ssr       :: !Word8
    -- ^ IOD of the SSR correction. A change of Issue Of Data SSR is used to
    -- indicate a change in the SSR  generating configuration
  , _msgSsrOrbitClock_iod           :: !Word32
    -- ^ Issue of broadcast ephemeris data or IODCRC (Beidou)
  , _msgSsrOrbitClock_radial        :: !Int32
    -- ^ Orbit radial delta correction
  , _msgSsrOrbitClock_along         :: !Int32
    -- ^ Orbit along delta correction
  , _msgSsrOrbitClock_cross         :: !Int32
    -- ^ Orbit along delta correction
  , _msgSsrOrbitClock_dot_radial    :: !Int32
    -- ^ Velocity of orbit radial delta correction
  , _msgSsrOrbitClock_dot_along     :: !Int32
    -- ^ Velocity of orbit along delta correction
  , _msgSsrOrbitClock_dot_cross     :: !Int32
    -- ^ Velocity of orbit cross delta correction
  , _msgSsrOrbitClock_c0            :: !Int32
    -- ^ C0 polynomial coefficient for correction of broadcast satellite clock
  , _msgSsrOrbitClock_c1            :: !Int32
    -- ^ C1 polynomial coefficient for correction of broadcast satellite clock
  , _msgSsrOrbitClock_c2            :: !Int32
    -- ^ C2 polynomial coefficient for correction of broadcast satellite clock
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrOrbitClock where
  get = do
    _msgSsrOrbitClock_time <- get
    _msgSsrOrbitClock_sid <- get
    _msgSsrOrbitClock_update_interval <- getWord8
    _msgSsrOrbitClock_iod_ssr <- getWord8
    _msgSsrOrbitClock_iod <- getWord32le
    _msgSsrOrbitClock_radial <- fromIntegral <$> getWord32le
    _msgSsrOrbitClock_along <- fromIntegral <$> getWord32le
    _msgSsrOrbitClock_cross <- fromIntegral <$> getWord32le
    _msgSsrOrbitClock_dot_radial <- fromIntegral <$> getWord32le
    _msgSsrOrbitClock_dot_along <- fromIntegral <$> getWord32le
    _msgSsrOrbitClock_dot_cross <- fromIntegral <$> getWord32le
    _msgSsrOrbitClock_c0 <- fromIntegral <$> getWord32le
    _msgSsrOrbitClock_c1 <- fromIntegral <$> getWord32le
    _msgSsrOrbitClock_c2 <- fromIntegral <$> getWord32le
    pure MsgSsrOrbitClock {..}

  put MsgSsrOrbitClock {..} = do
    put _msgSsrOrbitClock_time
    put _msgSsrOrbitClock_sid
    putWord8 _msgSsrOrbitClock_update_interval
    putWord8 _msgSsrOrbitClock_iod_ssr
    putWord32le _msgSsrOrbitClock_iod
    (putWord32le . fromIntegral) _msgSsrOrbitClock_radial
    (putWord32le . fromIntegral) _msgSsrOrbitClock_along
    (putWord32le . fromIntegral) _msgSsrOrbitClock_cross
    (putWord32le . fromIntegral) _msgSsrOrbitClock_dot_radial
    (putWord32le . fromIntegral) _msgSsrOrbitClock_dot_along
    (putWord32le . fromIntegral) _msgSsrOrbitClock_dot_cross
    (putWord32le . fromIntegral) _msgSsrOrbitClock_c0
    (putWord32le . fromIntegral) _msgSsrOrbitClock_c1
    (putWord32le . fromIntegral) _msgSsrOrbitClock_c2

$(makeSBP 'msgSsrOrbitClock ''MsgSsrOrbitClock)
$(makeJSON "_msgSsrOrbitClock_" ''MsgSsrOrbitClock)
$(makeLenses ''MsgSsrOrbitClock)

msgSsrOrbitClockDepA :: Word16
msgSsrOrbitClockDepA = 0x05DC

-- | SBP class for message MSG_SSR_ORBIT_CLOCK_DEP_A (0x05DC).
--
-- The precise orbit and clock correction message is  to be applied as a delta
-- correction to broadcast  ephemeris and is typically an equivalent to the
-- 1060 and 1066 RTCM message types
data MsgSsrOrbitClockDepA = MsgSsrOrbitClockDepA
  { _msgSsrOrbitClockDepA_time          :: !GpsTimeSec
    -- ^ GNSS reference time of the correction
  , _msgSsrOrbitClockDepA_sid           :: !GnssSignal
    -- ^ GNSS signal identifier (16 bit)
  , _msgSsrOrbitClockDepA_update_interval :: !Word8
    -- ^ Update interval between consecutive corrections
  , _msgSsrOrbitClockDepA_iod_ssr       :: !Word8
    -- ^ IOD of the SSR correction. A change of Issue Of Data SSR is used to
    -- indicate a change in the SSR  generating configuration
  , _msgSsrOrbitClockDepA_iod           :: !Word8
    -- ^ Issue of broadcast ephemeris data
  , _msgSsrOrbitClockDepA_radial        :: !Int32
    -- ^ Orbit radial delta correction
  , _msgSsrOrbitClockDepA_along         :: !Int32
    -- ^ Orbit along delta correction
  , _msgSsrOrbitClockDepA_cross         :: !Int32
    -- ^ Orbit along delta correction
  , _msgSsrOrbitClockDepA_dot_radial    :: !Int32
    -- ^ Velocity of orbit radial delta correction
  , _msgSsrOrbitClockDepA_dot_along     :: !Int32
    -- ^ Velocity of orbit along delta correction
  , _msgSsrOrbitClockDepA_dot_cross     :: !Int32
    -- ^ Velocity of orbit cross delta correction
  , _msgSsrOrbitClockDepA_c0            :: !Int32
    -- ^ C0 polynomial coefficient for correction of broadcast satellite clock
  , _msgSsrOrbitClockDepA_c1            :: !Int32
    -- ^ C1 polynomial coefficient for correction of broadcast satellite clock
  , _msgSsrOrbitClockDepA_c2            :: !Int32
    -- ^ C2 polynomial coefficient for correction of broadcast satellite clock
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrOrbitClockDepA where
  get = do
    _msgSsrOrbitClockDepA_time <- get
    _msgSsrOrbitClockDepA_sid <- get
    _msgSsrOrbitClockDepA_update_interval <- getWord8
    _msgSsrOrbitClockDepA_iod_ssr <- getWord8
    _msgSsrOrbitClockDepA_iod <- getWord8
    _msgSsrOrbitClockDepA_radial <- fromIntegral <$> getWord32le
    _msgSsrOrbitClockDepA_along <- fromIntegral <$> getWord32le
    _msgSsrOrbitClockDepA_cross <- fromIntegral <$> getWord32le
    _msgSsrOrbitClockDepA_dot_radial <- fromIntegral <$> getWord32le
    _msgSsrOrbitClockDepA_dot_along <- fromIntegral <$> getWord32le
    _msgSsrOrbitClockDepA_dot_cross <- fromIntegral <$> getWord32le
    _msgSsrOrbitClockDepA_c0 <- fromIntegral <$> getWord32le
    _msgSsrOrbitClockDepA_c1 <- fromIntegral <$> getWord32le
    _msgSsrOrbitClockDepA_c2 <- fromIntegral <$> getWord32le
    pure MsgSsrOrbitClockDepA {..}

  put MsgSsrOrbitClockDepA {..} = do
    put _msgSsrOrbitClockDepA_time
    put _msgSsrOrbitClockDepA_sid
    putWord8 _msgSsrOrbitClockDepA_update_interval
    putWord8 _msgSsrOrbitClockDepA_iod_ssr
    putWord8 _msgSsrOrbitClockDepA_iod
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_radial
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_along
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_cross
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_dot_radial
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_dot_along
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_dot_cross
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_c0
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_c1
    (putWord32le . fromIntegral) _msgSsrOrbitClockDepA_c2

$(makeSBP 'msgSsrOrbitClockDepA ''MsgSsrOrbitClockDepA)
$(makeJSON "_msgSsrOrbitClockDepA_" ''MsgSsrOrbitClockDepA)
$(makeLenses ''MsgSsrOrbitClockDepA)

msgSsrCodeBiases :: Word16
msgSsrCodeBiases = 0x05E1

-- | SBP class for message MSG_SSR_CODE_BIASES (0x05E1).
--
-- The precise code biases message is to be added to the pseudorange of the
-- corresponding signal to get corrected pseudorange. It is typically  an
-- equivalent to the 1059 and 1065 RTCM message types
data MsgSsrCodeBiases = MsgSsrCodeBiases
  { _msgSsrCodeBiases_time          :: !GpsTimeSec
    -- ^ GNSS reference time of the correction
  , _msgSsrCodeBiases_sid           :: !GnssSignal
    -- ^ GNSS signal identifier (16 bit)
  , _msgSsrCodeBiases_update_interval :: !Word8
    -- ^ Update interval between consecutive corrections
  , _msgSsrCodeBiases_iod_ssr       :: !Word8
    -- ^ IOD of the SSR correction. A change of Issue Of Data SSR is used to
    -- indicate a change in the SSR  generating configuration
  , _msgSsrCodeBiases_biases        :: ![CodeBiasesContent]
    -- ^ Code biases for the different satellite signals
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrCodeBiases where
  get = do
    _msgSsrCodeBiases_time <- get
    _msgSsrCodeBiases_sid <- get
    _msgSsrCodeBiases_update_interval <- getWord8
    _msgSsrCodeBiases_iod_ssr <- getWord8
    _msgSsrCodeBiases_biases <- whileM (not <$> isEmpty) get
    pure MsgSsrCodeBiases {..}

  put MsgSsrCodeBiases {..} = do
    put _msgSsrCodeBiases_time
    put _msgSsrCodeBiases_sid
    putWord8 _msgSsrCodeBiases_update_interval
    putWord8 _msgSsrCodeBiases_iod_ssr
    mapM_ put _msgSsrCodeBiases_biases

$(makeSBP 'msgSsrCodeBiases ''MsgSsrCodeBiases)
$(makeJSON "_msgSsrCodeBiases_" ''MsgSsrCodeBiases)
$(makeLenses ''MsgSsrCodeBiases)

msgSsrPhaseBiases :: Word16
msgSsrPhaseBiases = 0x05E6

-- | SBP class for message MSG_SSR_PHASE_BIASES (0x05E6).
--
-- The precise phase biases message contains the biases to be added to the
-- carrier phase of the corresponding signal to get corrected carrier phase
-- measurement, as  well as the satellite yaw angle to be applied to compute
-- the phase wind-up correction.  It is typically an equivalent to the 1265
-- RTCM message types
data MsgSsrPhaseBiases = MsgSsrPhaseBiases
  { _msgSsrPhaseBiases_time          :: !GpsTimeSec
    -- ^ GNSS reference time of the correction
  , _msgSsrPhaseBiases_sid           :: !GnssSignal
    -- ^ GNSS signal identifier (16 bit)
  , _msgSsrPhaseBiases_update_interval :: !Word8
    -- ^ Update interval between consecutive corrections
  , _msgSsrPhaseBiases_iod_ssr       :: !Word8
    -- ^ IOD of the SSR correction. A change of Issue Of Data SSR is used to
    -- indicate a change in the SSR  generating configuration
  , _msgSsrPhaseBiases_dispersive_bias :: !Word8
    -- ^ Indicator for the dispersive phase biases property.
  , _msgSsrPhaseBiases_mw_consistency :: !Word8
    -- ^ Consistency indicator for Melbourne-Wubbena linear combinations
  , _msgSsrPhaseBiases_yaw           :: !Word16
    -- ^ Satellite yaw angle
  , _msgSsrPhaseBiases_yaw_rate      :: !Int8
    -- ^ Satellite yaw angle rate
  , _msgSsrPhaseBiases_biases        :: ![PhaseBiasesContent]
    -- ^ Phase biases corrections for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgSsrPhaseBiases where
  get = do
    _msgSsrPhaseBiases_time <- get
    _msgSsrPhaseBiases_sid <- get
    _msgSsrPhaseBiases_update_interval <- getWord8
    _msgSsrPhaseBiases_iod_ssr <- getWord8
    _msgSsrPhaseBiases_dispersive_bias <- getWord8
    _msgSsrPhaseBiases_mw_consistency <- getWord8
    _msgSsrPhaseBiases_yaw <- getWord16le
    _msgSsrPhaseBiases_yaw_rate <- fromIntegral <$> getWord8
    _msgSsrPhaseBiases_biases <- whileM (not <$> isEmpty) get
    pure MsgSsrPhaseBiases {..}

  put MsgSsrPhaseBiases {..} = do
    put _msgSsrPhaseBiases_time
    put _msgSsrPhaseBiases_sid
    putWord8 _msgSsrPhaseBiases_update_interval
    putWord8 _msgSsrPhaseBiases_iod_ssr
    putWord8 _msgSsrPhaseBiases_dispersive_bias
    putWord8 _msgSsrPhaseBiases_mw_consistency
    putWord16le _msgSsrPhaseBiases_yaw
    (putWord8 . fromIntegral) _msgSsrPhaseBiases_yaw_rate
    mapM_ put _msgSsrPhaseBiases_biases

$(makeSBP 'msgSsrPhaseBiases ''MsgSsrPhaseBiases)
$(makeJSON "_msgSsrPhaseBiases_" ''MsgSsrPhaseBiases)
$(makeLenses ''MsgSsrPhaseBiases)
