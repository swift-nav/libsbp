{-# OPTIONS_GHC -fno-warn-unused-imports #-}
-- |
-- Module:      SwiftNav.SBP.Observation
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Satellite observation messages from the device.

module SwiftNav.SBP.Observation where

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
import SwiftNav.SBP.GnssSignal

-- | ObsGPSTime.
--
-- A wire-appropriate GPS time, defined as the number of milliseconds since
-- beginning of the week on the Saturday/Sunday transition.
data ObsGPSTime = ObsGPSTime
  { _obsGPSTime_tow :: Word32
    -- ^ Milliseconds since start of GPS week
  , _obsGPSTime_wn :: Word16
    -- ^ GPS week number
  } deriving ( Show, Read, Eq )

instance Binary ObsGPSTime where
  get = do
    _obsGPSTime_tow <- getWord32le
    _obsGPSTime_wn <- getWord16le
    return ObsGPSTime {..}

  put ObsGPSTime {..} = do
    putWord32le _obsGPSTime_tow
    putWord16le _obsGPSTime_wn
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_obsGPSTime_" . stripPrefix "_obsGPSTime_"}
             ''ObsGPSTime)
$(makeLenses ''ObsGPSTime)

-- | CarrierPhase.
--
-- Carrier phase measurement in cycles represented as a 40-bit fixed point
-- number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
-- fractional cycles.  This phase has the  same sign as the pseudorange.
data CarrierPhase = CarrierPhase
  { _carrierPhase_i :: Int32
    -- ^ Carrier phase whole cycles
  , _carrierPhase_f :: Word8
    -- ^ Carrier phase fractional part
  } deriving ( Show, Read, Eq )

instance Binary CarrierPhase where
  get = do
    _carrierPhase_i <- liftM fromIntegral getWord32le
    _carrierPhase_f <- getWord8
    return CarrierPhase {..}

  put CarrierPhase {..} = do
    putWord32le $ fromIntegral _carrierPhase_i
    putWord8 _carrierPhase_f
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_carrierPhase_" . stripPrefix "_carrierPhase_"}
             ''CarrierPhase)
$(makeLenses ''CarrierPhase)

-- | ObservationHeader.
--
-- Header of a GPS observation message.
data ObservationHeader = ObservationHeader
  { _observationHeader_t   :: ObsGPSTime
    -- ^ GPS time of this observation
  , _observationHeader_n_obs :: Word8
    -- ^ Total number of observations. First nibble is the size of the sequence
    -- (n), second nibble is the zero-indexed counter (ith packet of n)
  } deriving ( Show, Read, Eq )

instance Binary ObservationHeader where
  get = do
    _observationHeader_t <- get
    _observationHeader_n_obs <- getWord8
    return ObservationHeader {..}

  put ObservationHeader {..} = do
    put _observationHeader_t
    putWord8 _observationHeader_n_obs
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_observationHeader_" . stripPrefix "_observationHeader_"}
             ''ObservationHeader)
$(makeLenses ''ObservationHeader)

-- | PackedObsContent.
--
-- Pseudorange and carrier phase observation for a satellite being tracked. The
-- observations should be interoperable with 3rd party  receivers and conform
-- with typical RTCMv3 GNSS observations.
data PackedObsContent = PackedObsContent
  { _packedObsContent_P  :: Word32
    -- ^ Pseudorange observation
  , _packedObsContent_L  :: CarrierPhase
    -- ^ Carrier phase observation with typical sign convention.
  , _packedObsContent_cn0 :: Word8
    -- ^ Carrier-to-Noise density
  , _packedObsContent_lock :: Word16
    -- ^ Lock indicator. This value changes whenever a satellite signal has lost
    -- and regained lock, indicating that the carrier phase ambiguity may have
    -- changed.
  , _packedObsContent_sid :: GnssSignal
    -- ^ GNSS signal identifier
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContent where
  get = do
    _packedObsContent_P <- getWord32le
    _packedObsContent_L <- get
    _packedObsContent_cn0 <- getWord8
    _packedObsContent_lock <- getWord16le
    _packedObsContent_sid <- get
    return PackedObsContent {..}

  put PackedObsContent {..} = do
    putWord32le _packedObsContent_P
    put _packedObsContent_L
    putWord8 _packedObsContent_cn0
    putWord16le _packedObsContent_lock
    put _packedObsContent_sid
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_packedObsContent_" . stripPrefix "_packedObsContent_"}
             ''PackedObsContent)
$(makeLenses ''PackedObsContent)

msgObs :: Word16
msgObs = 0x0049

-- | SBP class for message MSG_OBS (0x0049).
--
-- The GPS observations message reports all the raw pseudorange and carrier
-- phase observations for the satellites being tracked by the device. Carrier
-- phase observation here is represented as a 40-bit fixed point number with
-- Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of fractional cycles).
-- The observations  should be interoperable with 3rd party receivers and
-- conform  with typical RTCMv3 GNSS observations.
data MsgObs = MsgObs
  { _msgObs_header :: ObservationHeader
    -- ^ Header of a GPS observation message
  , _msgObs_obs  :: [PackedObsContent]
    -- ^ Pseudorange and carrier phase observation for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgObs where
  get = do
    _msgObs_header <- get
    _msgObs_obs <- whileM (liftM not isEmpty) get
    return MsgObs {..}

  put MsgObs {..} = do
    put _msgObs_header
    mapM_ put _msgObs_obs

$(deriveSBP 'msgObs ''MsgObs)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgObs_" . stripPrefix "_msgObs_"}
             ''MsgObs)
$(makeLenses ''MsgObs)

msgBasePosLlh :: Word16
msgBasePosLlh = 0x0044

-- | SBP class for message MSG_BASE_POS_LLH (0x0044).
--
-- The base station position message is the position reported by the base
-- station itself. It is used for pseudo-absolute RTK positioning, and is
-- required to be a high-accuracy surveyed location of the base station. Any
-- error here will result in an error in the pseudo-absolute position output.
data MsgBasePosLlh = MsgBasePosLlh
  { _msgBasePosLlh_lat  :: Double
    -- ^ Latitude
  , _msgBasePosLlh_lon  :: Double
    -- ^ Longitude
  , _msgBasePosLlh_height :: Double
    -- ^ Height
  } deriving ( Show, Read, Eq )

instance Binary MsgBasePosLlh where
  get = do
    _msgBasePosLlh_lat <- getFloat64le
    _msgBasePosLlh_lon <- getFloat64le
    _msgBasePosLlh_height <- getFloat64le
    return MsgBasePosLlh {..}

  put MsgBasePosLlh {..} = do
    putFloat64le _msgBasePosLlh_lat
    putFloat64le _msgBasePosLlh_lon
    putFloat64le _msgBasePosLlh_height

$(deriveSBP 'msgBasePosLlh ''MsgBasePosLlh)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgBasePosLlh_" . stripPrefix "_msgBasePosLlh_"}
             ''MsgBasePosLlh)
$(makeLenses ''MsgBasePosLlh)

msgBasePosEcef :: Word16
msgBasePosEcef = 0x0048

-- | SBP class for message MSG_BASE_POS_ECEF (0x0048).
--
-- The base station position message is the position reported by the base
-- station itself in absolute Earth Centered Earth Fixed coordinates. It is
-- used for pseudo-absolute RTK positioning, and is required to be a high-
-- accuracy surveyed location of the base station. Any error here will result
-- in an error in the pseudo-absolute position output.
data MsgBasePosEcef = MsgBasePosEcef
  { _msgBasePosEcef_x :: Double
    -- ^ ECEF X coodinate
  , _msgBasePosEcef_y :: Double
    -- ^ ECEF Y coordinate
  , _msgBasePosEcef_z :: Double
    -- ^ ECEF Z coordinate
  } deriving ( Show, Read, Eq )

instance Binary MsgBasePosEcef where
  get = do
    _msgBasePosEcef_x <- getFloat64le
    _msgBasePosEcef_y <- getFloat64le
    _msgBasePosEcef_z <- getFloat64le
    return MsgBasePosEcef {..}

  put MsgBasePosEcef {..} = do
    putFloat64le _msgBasePosEcef_x
    putFloat64le _msgBasePosEcef_y
    putFloat64le _msgBasePosEcef_z

$(deriveSBP 'msgBasePosEcef ''MsgBasePosEcef)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgBasePosEcef_" . stripPrefix "_msgBasePosEcef_"}
             ''MsgBasePosEcef)
$(makeLenses ''MsgBasePosEcef)

msgEphemeris :: Word16
msgEphemeris = 0x0080

-- | SBP class for message MSG_EPHEMERIS (0x0080).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate GPS satellite position, velocity, and clock offset. Please
-- see the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200,
-- Table 20-III) for more details.
data MsgEphemeris = MsgEphemeris
  { _msgEphemeris_tgd    :: Double
    -- ^ Group delay differential between L1 and L2
  , _msgEphemeris_c_rs   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemeris_c_rc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemeris_c_uc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemeris_c_us   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemeris_c_ic   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemeris_c_is   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemeris_dn     :: Double
    -- ^ Mean motion difference
  , _msgEphemeris_m0     :: Double
    -- ^ Mean anomaly at reference time
  , _msgEphemeris_ecc    :: Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemeris_sqrta  :: Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemeris_omega0 :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemeris_omegadot :: Double
    -- ^ Rate of right ascension
  , _msgEphemeris_w      :: Double
    -- ^ Argument of perigee
  , _msgEphemeris_inc    :: Double
    -- ^ Inclination
  , _msgEphemeris_inc_dot :: Double
    -- ^ Inclination first derivative
  , _msgEphemeris_af0    :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemeris_af1    :: Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemeris_af2    :: Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemeris_toe_tow :: Double
    -- ^ Time of week
  , _msgEphemeris_toe_wn :: Word16
    -- ^ Week number
  , _msgEphemeris_toc_tow :: Double
    -- ^ Clock reference time of week
  , _msgEphemeris_toc_wn :: Word16
    -- ^ Clock reference week number
  , _msgEphemeris_valid  :: Word8
    -- ^ Is valid?
  , _msgEphemeris_healthy :: Word8
    -- ^ Satellite is healthy?
  , _msgEphemeris_sid    :: GnssSignal
    -- ^ GNSS signal identifier
  , _msgEphemeris_iode   :: Word8
    -- ^ Issue of ephemeris data
  , _msgEphemeris_iodc   :: Word16
    -- ^ Issue of clock data
  , _msgEphemeris_reserved :: Word32
    -- ^ Reserved field
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemeris where
  get = do
    _msgEphemeris_tgd <- getFloat64le
    _msgEphemeris_c_rs <- getFloat64le
    _msgEphemeris_c_rc <- getFloat64le
    _msgEphemeris_c_uc <- getFloat64le
    _msgEphemeris_c_us <- getFloat64le
    _msgEphemeris_c_ic <- getFloat64le
    _msgEphemeris_c_is <- getFloat64le
    _msgEphemeris_dn <- getFloat64le
    _msgEphemeris_m0 <- getFloat64le
    _msgEphemeris_ecc <- getFloat64le
    _msgEphemeris_sqrta <- getFloat64le
    _msgEphemeris_omega0 <- getFloat64le
    _msgEphemeris_omegadot <- getFloat64le
    _msgEphemeris_w <- getFloat64le
    _msgEphemeris_inc <- getFloat64le
    _msgEphemeris_inc_dot <- getFloat64le
    _msgEphemeris_af0 <- getFloat64le
    _msgEphemeris_af1 <- getFloat64le
    _msgEphemeris_af2 <- getFloat64le
    _msgEphemeris_toe_tow <- getFloat64le
    _msgEphemeris_toe_wn <- getWord16le
    _msgEphemeris_toc_tow <- getFloat64le
    _msgEphemeris_toc_wn <- getWord16le
    _msgEphemeris_valid <- getWord8
    _msgEphemeris_healthy <- getWord8
    _msgEphemeris_sid <- get
    _msgEphemeris_iode <- getWord8
    _msgEphemeris_iodc <- getWord16le
    _msgEphemeris_reserved <- getWord32le
    return MsgEphemeris {..}

  put MsgEphemeris {..} = do
    putFloat64le _msgEphemeris_tgd
    putFloat64le _msgEphemeris_c_rs
    putFloat64le _msgEphemeris_c_rc
    putFloat64le _msgEphemeris_c_uc
    putFloat64le _msgEphemeris_c_us
    putFloat64le _msgEphemeris_c_ic
    putFloat64le _msgEphemeris_c_is
    putFloat64le _msgEphemeris_dn
    putFloat64le _msgEphemeris_m0
    putFloat64le _msgEphemeris_ecc
    putFloat64le _msgEphemeris_sqrta
    putFloat64le _msgEphemeris_omega0
    putFloat64le _msgEphemeris_omegadot
    putFloat64le _msgEphemeris_w
    putFloat64le _msgEphemeris_inc
    putFloat64le _msgEphemeris_inc_dot
    putFloat64le _msgEphemeris_af0
    putFloat64le _msgEphemeris_af1
    putFloat64le _msgEphemeris_af2
    putFloat64le _msgEphemeris_toe_tow
    putWord16le _msgEphemeris_toe_wn
    putFloat64le _msgEphemeris_toc_tow
    putWord16le _msgEphemeris_toc_wn
    putWord8 _msgEphemeris_valid
    putWord8 _msgEphemeris_healthy
    put _msgEphemeris_sid
    putWord8 _msgEphemeris_iode
    putWord16le _msgEphemeris_iodc
    putWord32le _msgEphemeris_reserved

$(deriveSBP 'msgEphemeris ''MsgEphemeris)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgEphemeris_" . stripPrefix "_msgEphemeris_"}
             ''MsgEphemeris)
$(makeLenses ''MsgEphemeris)

msgEphemerisDepA :: Word16
msgEphemerisDepA = 0x001A

-- | SBP class for message MSG_EPHEMERIS_DEP_A (0x001A).
--
-- Deprecated.
data MsgEphemerisDepA = MsgEphemerisDepA
  { _msgEphemerisDepA_tgd    :: Double
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisDepA_c_rs   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisDepA_c_rc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisDepA_c_uc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepA_c_us   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepA_c_ic   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepA_c_is   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepA_dn     :: Double
    -- ^ Mean motion difference
  , _msgEphemerisDepA_m0     :: Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisDepA_ecc    :: Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisDepA_sqrta  :: Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisDepA_omega0 :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisDepA_omegadot :: Double
    -- ^ Rate of right ascension
  , _msgEphemerisDepA_w      :: Double
    -- ^ Argument of perigee
  , _msgEphemerisDepA_inc    :: Double
    -- ^ Inclination
  , _msgEphemerisDepA_inc_dot :: Double
    -- ^ Inclination first derivative
  , _msgEphemerisDepA_af0    :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisDepA_af1    :: Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisDepA_af2    :: Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisDepA_toe_tow :: Double
    -- ^ Time of week
  , _msgEphemerisDepA_toe_wn :: Word16
    -- ^ Week number
  , _msgEphemerisDepA_toc_tow :: Double
    -- ^ Clock reference time of week
  , _msgEphemerisDepA_toc_wn :: Word16
    -- ^ Clock reference week number
  , _msgEphemerisDepA_valid  :: Word8
    -- ^ Is valid?
  , _msgEphemerisDepA_healthy :: Word8
    -- ^ Satellite is healthy?
  , _msgEphemerisDepA_prn    :: Word8
    -- ^ PRN being tracked
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisDepA where
  get = do
    _msgEphemerisDepA_tgd <- getFloat64le
    _msgEphemerisDepA_c_rs <- getFloat64le
    _msgEphemerisDepA_c_rc <- getFloat64le
    _msgEphemerisDepA_c_uc <- getFloat64le
    _msgEphemerisDepA_c_us <- getFloat64le
    _msgEphemerisDepA_c_ic <- getFloat64le
    _msgEphemerisDepA_c_is <- getFloat64le
    _msgEphemerisDepA_dn <- getFloat64le
    _msgEphemerisDepA_m0 <- getFloat64le
    _msgEphemerisDepA_ecc <- getFloat64le
    _msgEphemerisDepA_sqrta <- getFloat64le
    _msgEphemerisDepA_omega0 <- getFloat64le
    _msgEphemerisDepA_omegadot <- getFloat64le
    _msgEphemerisDepA_w <- getFloat64le
    _msgEphemerisDepA_inc <- getFloat64le
    _msgEphemerisDepA_inc_dot <- getFloat64le
    _msgEphemerisDepA_af0 <- getFloat64le
    _msgEphemerisDepA_af1 <- getFloat64le
    _msgEphemerisDepA_af2 <- getFloat64le
    _msgEphemerisDepA_toe_tow <- getFloat64le
    _msgEphemerisDepA_toe_wn <- getWord16le
    _msgEphemerisDepA_toc_tow <- getFloat64le
    _msgEphemerisDepA_toc_wn <- getWord16le
    _msgEphemerisDepA_valid <- getWord8
    _msgEphemerisDepA_healthy <- getWord8
    _msgEphemerisDepA_prn <- getWord8
    return MsgEphemerisDepA {..}

  put MsgEphemerisDepA {..} = do
    putFloat64le _msgEphemerisDepA_tgd
    putFloat64le _msgEphemerisDepA_c_rs
    putFloat64le _msgEphemerisDepA_c_rc
    putFloat64le _msgEphemerisDepA_c_uc
    putFloat64le _msgEphemerisDepA_c_us
    putFloat64le _msgEphemerisDepA_c_ic
    putFloat64le _msgEphemerisDepA_c_is
    putFloat64le _msgEphemerisDepA_dn
    putFloat64le _msgEphemerisDepA_m0
    putFloat64le _msgEphemerisDepA_ecc
    putFloat64le _msgEphemerisDepA_sqrta
    putFloat64le _msgEphemerisDepA_omega0
    putFloat64le _msgEphemerisDepA_omegadot
    putFloat64le _msgEphemerisDepA_w
    putFloat64le _msgEphemerisDepA_inc
    putFloat64le _msgEphemerisDepA_inc_dot
    putFloat64le _msgEphemerisDepA_af0
    putFloat64le _msgEphemerisDepA_af1
    putFloat64le _msgEphemerisDepA_af2
    putFloat64le _msgEphemerisDepA_toe_tow
    putWord16le _msgEphemerisDepA_toe_wn
    putFloat64le _msgEphemerisDepA_toc_tow
    putWord16le _msgEphemerisDepA_toc_wn
    putWord8 _msgEphemerisDepA_valid
    putWord8 _msgEphemerisDepA_healthy
    putWord8 _msgEphemerisDepA_prn

$(deriveSBP 'msgEphemerisDepA ''MsgEphemerisDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgEphemerisDepA_" . stripPrefix "_msgEphemerisDepA_"}
             ''MsgEphemerisDepA)
$(makeLenses ''MsgEphemerisDepA)

msgEphemerisDepB :: Word16
msgEphemerisDepB = 0x0046

-- | SBP class for message MSG_EPHEMERIS_DEP_B (0x0046).
--
-- Deprecated.
data MsgEphemerisDepB = MsgEphemerisDepB
  { _msgEphemerisDepB_tgd    :: Double
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisDepB_c_rs   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisDepB_c_rc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisDepB_c_uc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepB_c_us   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepB_c_ic   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepB_c_is   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepB_dn     :: Double
    -- ^ Mean motion difference
  , _msgEphemerisDepB_m0     :: Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisDepB_ecc    :: Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisDepB_sqrta  :: Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisDepB_omega0 :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisDepB_omegadot :: Double
    -- ^ Rate of right ascension
  , _msgEphemerisDepB_w      :: Double
    -- ^ Argument of perigee
  , _msgEphemerisDepB_inc    :: Double
    -- ^ Inclination
  , _msgEphemerisDepB_inc_dot :: Double
    -- ^ Inclination first derivative
  , _msgEphemerisDepB_af0    :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisDepB_af1    :: Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisDepB_af2    :: Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisDepB_toe_tow :: Double
    -- ^ Time of week
  , _msgEphemerisDepB_toe_wn :: Word16
    -- ^ Week number
  , _msgEphemerisDepB_toc_tow :: Double
    -- ^ Clock reference time of week
  , _msgEphemerisDepB_toc_wn :: Word16
    -- ^ Clock reference week number
  , _msgEphemerisDepB_valid  :: Word8
    -- ^ Is valid?
  , _msgEphemerisDepB_healthy :: Word8
    -- ^ Satellite is healthy?
  , _msgEphemerisDepB_prn    :: Word8
    -- ^ PRN being tracked
  , _msgEphemerisDepB_iode   :: Word8
    -- ^ Issue of ephemeris data
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisDepB where
  get = do
    _msgEphemerisDepB_tgd <- getFloat64le
    _msgEphemerisDepB_c_rs <- getFloat64le
    _msgEphemerisDepB_c_rc <- getFloat64le
    _msgEphemerisDepB_c_uc <- getFloat64le
    _msgEphemerisDepB_c_us <- getFloat64le
    _msgEphemerisDepB_c_ic <- getFloat64le
    _msgEphemerisDepB_c_is <- getFloat64le
    _msgEphemerisDepB_dn <- getFloat64le
    _msgEphemerisDepB_m0 <- getFloat64le
    _msgEphemerisDepB_ecc <- getFloat64le
    _msgEphemerisDepB_sqrta <- getFloat64le
    _msgEphemerisDepB_omega0 <- getFloat64le
    _msgEphemerisDepB_omegadot <- getFloat64le
    _msgEphemerisDepB_w <- getFloat64le
    _msgEphemerisDepB_inc <- getFloat64le
    _msgEphemerisDepB_inc_dot <- getFloat64le
    _msgEphemerisDepB_af0 <- getFloat64le
    _msgEphemerisDepB_af1 <- getFloat64le
    _msgEphemerisDepB_af2 <- getFloat64le
    _msgEphemerisDepB_toe_tow <- getFloat64le
    _msgEphemerisDepB_toe_wn <- getWord16le
    _msgEphemerisDepB_toc_tow <- getFloat64le
    _msgEphemerisDepB_toc_wn <- getWord16le
    _msgEphemerisDepB_valid <- getWord8
    _msgEphemerisDepB_healthy <- getWord8
    _msgEphemerisDepB_prn <- getWord8
    _msgEphemerisDepB_iode <- getWord8
    return MsgEphemerisDepB {..}

  put MsgEphemerisDepB {..} = do
    putFloat64le _msgEphemerisDepB_tgd
    putFloat64le _msgEphemerisDepB_c_rs
    putFloat64le _msgEphemerisDepB_c_rc
    putFloat64le _msgEphemerisDepB_c_uc
    putFloat64le _msgEphemerisDepB_c_us
    putFloat64le _msgEphemerisDepB_c_ic
    putFloat64le _msgEphemerisDepB_c_is
    putFloat64le _msgEphemerisDepB_dn
    putFloat64le _msgEphemerisDepB_m0
    putFloat64le _msgEphemerisDepB_ecc
    putFloat64le _msgEphemerisDepB_sqrta
    putFloat64le _msgEphemerisDepB_omega0
    putFloat64le _msgEphemerisDepB_omegadot
    putFloat64le _msgEphemerisDepB_w
    putFloat64le _msgEphemerisDepB_inc
    putFloat64le _msgEphemerisDepB_inc_dot
    putFloat64le _msgEphemerisDepB_af0
    putFloat64le _msgEphemerisDepB_af1
    putFloat64le _msgEphemerisDepB_af2
    putFloat64le _msgEphemerisDepB_toe_tow
    putWord16le _msgEphemerisDepB_toe_wn
    putFloat64le _msgEphemerisDepB_toc_tow
    putWord16le _msgEphemerisDepB_toc_wn
    putWord8 _msgEphemerisDepB_valid
    putWord8 _msgEphemerisDepB_healthy
    putWord8 _msgEphemerisDepB_prn
    putWord8 _msgEphemerisDepB_iode

$(deriveSBP 'msgEphemerisDepB ''MsgEphemerisDepB)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgEphemerisDepB_" . stripPrefix "_msgEphemerisDepB_"}
             ''MsgEphemerisDepB)
$(makeLenses ''MsgEphemerisDepB)

msgEphemerisDepC :: Word16
msgEphemerisDepC = 0x0047

-- | SBP class for message MSG_EPHEMERIS_DEP_C (0x0047).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate GPS satellite position, velocity, and clock offset. Please
-- see the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200,
-- Table 20-III) for more details.
data MsgEphemerisDepC = MsgEphemerisDepC
  { _msgEphemerisDepC_tgd    :: Double
    -- ^ Group delay differential between L1 and L2
  , _msgEphemerisDepC_c_rs   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , _msgEphemerisDepC_c_rc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , _msgEphemerisDepC_c_uc   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepC_c_us   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , _msgEphemerisDepC_c_ic   :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepC_c_is   :: Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , _msgEphemerisDepC_dn     :: Double
    -- ^ Mean motion difference
  , _msgEphemerisDepC_m0     :: Double
    -- ^ Mean anomaly at reference time
  , _msgEphemerisDepC_ecc    :: Double
    -- ^ Eccentricity of satellite orbit
  , _msgEphemerisDepC_sqrta  :: Double
    -- ^ Square root of the semi-major axis of orbit
  , _msgEphemerisDepC_omega0 :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , _msgEphemerisDepC_omegadot :: Double
    -- ^ Rate of right ascension
  , _msgEphemerisDepC_w      :: Double
    -- ^ Argument of perigee
  , _msgEphemerisDepC_inc    :: Double
    -- ^ Inclination
  , _msgEphemerisDepC_inc_dot :: Double
    -- ^ Inclination first derivative
  , _msgEphemerisDepC_af0    :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , _msgEphemerisDepC_af1    :: Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , _msgEphemerisDepC_af2    :: Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , _msgEphemerisDepC_toe_tow :: Double
    -- ^ Time of week
  , _msgEphemerisDepC_toe_wn :: Word16
    -- ^ Week number
  , _msgEphemerisDepC_toc_tow :: Double
    -- ^ Clock reference time of week
  , _msgEphemerisDepC_toc_wn :: Word16
    -- ^ Clock reference week number
  , _msgEphemerisDepC_valid  :: Word8
    -- ^ Is valid?
  , _msgEphemerisDepC_healthy :: Word8
    -- ^ Satellite is healthy?
  , _msgEphemerisDepC_sid    :: GnssSignal
    -- ^ GNSS signal identifier
  , _msgEphemerisDepC_iode   :: Word8
    -- ^ Issue of ephemeris data
  , _msgEphemerisDepC_iodc   :: Word16
    -- ^ Issue of clock data
  , _msgEphemerisDepC_reserved :: Word32
    -- ^ Reserved field
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisDepC where
  get = do
    _msgEphemerisDepC_tgd <- getFloat64le
    _msgEphemerisDepC_c_rs <- getFloat64le
    _msgEphemerisDepC_c_rc <- getFloat64le
    _msgEphemerisDepC_c_uc <- getFloat64le
    _msgEphemerisDepC_c_us <- getFloat64le
    _msgEphemerisDepC_c_ic <- getFloat64le
    _msgEphemerisDepC_c_is <- getFloat64le
    _msgEphemerisDepC_dn <- getFloat64le
    _msgEphemerisDepC_m0 <- getFloat64le
    _msgEphemerisDepC_ecc <- getFloat64le
    _msgEphemerisDepC_sqrta <- getFloat64le
    _msgEphemerisDepC_omega0 <- getFloat64le
    _msgEphemerisDepC_omegadot <- getFloat64le
    _msgEphemerisDepC_w <- getFloat64le
    _msgEphemerisDepC_inc <- getFloat64le
    _msgEphemerisDepC_inc_dot <- getFloat64le
    _msgEphemerisDepC_af0 <- getFloat64le
    _msgEphemerisDepC_af1 <- getFloat64le
    _msgEphemerisDepC_af2 <- getFloat64le
    _msgEphemerisDepC_toe_tow <- getFloat64le
    _msgEphemerisDepC_toe_wn <- getWord16le
    _msgEphemerisDepC_toc_tow <- getFloat64le
    _msgEphemerisDepC_toc_wn <- getWord16le
    _msgEphemerisDepC_valid <- getWord8
    _msgEphemerisDepC_healthy <- getWord8
    _msgEphemerisDepC_sid <- get
    _msgEphemerisDepC_iode <- getWord8
    _msgEphemerisDepC_iodc <- getWord16le
    _msgEphemerisDepC_reserved <- getWord32le
    return MsgEphemerisDepC {..}

  put MsgEphemerisDepC {..} = do
    putFloat64le _msgEphemerisDepC_tgd
    putFloat64le _msgEphemerisDepC_c_rs
    putFloat64le _msgEphemerisDepC_c_rc
    putFloat64le _msgEphemerisDepC_c_uc
    putFloat64le _msgEphemerisDepC_c_us
    putFloat64le _msgEphemerisDepC_c_ic
    putFloat64le _msgEphemerisDepC_c_is
    putFloat64le _msgEphemerisDepC_dn
    putFloat64le _msgEphemerisDepC_m0
    putFloat64le _msgEphemerisDepC_ecc
    putFloat64le _msgEphemerisDepC_sqrta
    putFloat64le _msgEphemerisDepC_omega0
    putFloat64le _msgEphemerisDepC_omegadot
    putFloat64le _msgEphemerisDepC_w
    putFloat64le _msgEphemerisDepC_inc
    putFloat64le _msgEphemerisDepC_inc_dot
    putFloat64le _msgEphemerisDepC_af0
    putFloat64le _msgEphemerisDepC_af1
    putFloat64le _msgEphemerisDepC_af2
    putFloat64le _msgEphemerisDepC_toe_tow
    putWord16le _msgEphemerisDepC_toe_wn
    putFloat64le _msgEphemerisDepC_toc_tow
    putWord16le _msgEphemerisDepC_toc_wn
    putWord8 _msgEphemerisDepC_valid
    putWord8 _msgEphemerisDepC_healthy
    put _msgEphemerisDepC_sid
    putWord8 _msgEphemerisDepC_iode
    putWord16le _msgEphemerisDepC_iodc
    putWord32le _msgEphemerisDepC_reserved

$(deriveSBP 'msgEphemerisDepC ''MsgEphemerisDepC)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgEphemerisDepC_" . stripPrefix "_msgEphemerisDepC_"}
             ''MsgEphemerisDepC)
$(makeLenses ''MsgEphemerisDepC)

-- | CarrierPhaseDepA.
--
-- Carrier phase measurement in cycles represented as a 40-bit fixed point
-- number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
-- fractional cycles. This has the opposite sign convention than a typical GPS
-- receiver and the phase has the opposite sign as the pseudorange.
data CarrierPhaseDepA = CarrierPhaseDepA
  { _carrierPhaseDepA_i :: Int32
    -- ^ Carrier phase whole cycles
  , _carrierPhaseDepA_f :: Word8
    -- ^ Carrier phase fractional part
  } deriving ( Show, Read, Eq )

instance Binary CarrierPhaseDepA where
  get = do
    _carrierPhaseDepA_i <- liftM fromIntegral getWord32le
    _carrierPhaseDepA_f <- getWord8
    return CarrierPhaseDepA {..}

  put CarrierPhaseDepA {..} = do
    putWord32le $ fromIntegral _carrierPhaseDepA_i
    putWord8 _carrierPhaseDepA_f
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_carrierPhaseDepA_" . stripPrefix "_carrierPhaseDepA_"}
             ''CarrierPhaseDepA)
$(makeLenses ''CarrierPhaseDepA)

-- | PackedObsContentDepA.
--
-- Deprecated.
data PackedObsContentDepA = PackedObsContentDepA
  { _packedObsContentDepA_P  :: Word32
    -- ^ Pseudorange observation
  , _packedObsContentDepA_L  :: CarrierPhaseDepA
    -- ^ Carrier phase observation with opposite sign from typical convention
  , _packedObsContentDepA_cn0 :: Word8
    -- ^ Carrier-to-Noise density
  , _packedObsContentDepA_lock :: Word16
    -- ^ Lock indicator. This value changes whenever a satellite signal has lost
    -- and regained lock, indicating that the carrier phase ambiguity may have
    -- changed.
  , _packedObsContentDepA_prn :: Word8
    -- ^ PRN-1 identifier of the satellite signal
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContentDepA where
  get = do
    _packedObsContentDepA_P <- getWord32le
    _packedObsContentDepA_L <- get
    _packedObsContentDepA_cn0 <- getWord8
    _packedObsContentDepA_lock <- getWord16le
    _packedObsContentDepA_prn <- getWord8
    return PackedObsContentDepA {..}

  put PackedObsContentDepA {..} = do
    putWord32le _packedObsContentDepA_P
    put _packedObsContentDepA_L
    putWord8 _packedObsContentDepA_cn0
    putWord16le _packedObsContentDepA_lock
    putWord8 _packedObsContentDepA_prn
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_packedObsContentDepA_" . stripPrefix "_packedObsContentDepA_"}
             ''PackedObsContentDepA)
$(makeLenses ''PackedObsContentDepA)

-- | PackedObsContentDepB.
--
-- Pseudorange and carrier phase observation for a satellite being tracked.
-- Pseudoranges are referenced to a nominal pseudorange.
data PackedObsContentDepB = PackedObsContentDepB
  { _packedObsContentDepB_P  :: Word32
    -- ^ Pseudorange observation
  , _packedObsContentDepB_L  :: CarrierPhaseDepA
    -- ^ Carrier phase observation with opposite sign from typical convention.
  , _packedObsContentDepB_cn0 :: Word8
    -- ^ Carrier-to-Noise density
  , _packedObsContentDepB_lock :: Word16
    -- ^ Lock indicator. This value changes whenever a satellite signal has lost
    -- and regained lock, indicating that the carrier phase ambiguity may have
    -- changed.
  , _packedObsContentDepB_sid :: GnssSignal
    -- ^ GNSS signal identifier
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContentDepB where
  get = do
    _packedObsContentDepB_P <- getWord32le
    _packedObsContentDepB_L <- get
    _packedObsContentDepB_cn0 <- getWord8
    _packedObsContentDepB_lock <- getWord16le
    _packedObsContentDepB_sid <- get
    return PackedObsContentDepB {..}

  put PackedObsContentDepB {..} = do
    putWord32le _packedObsContentDepB_P
    put _packedObsContentDepB_L
    putWord8 _packedObsContentDepB_cn0
    putWord16le _packedObsContentDepB_lock
    put _packedObsContentDepB_sid
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_packedObsContentDepB_" . stripPrefix "_packedObsContentDepB_"}
             ''PackedObsContentDepB)
$(makeLenses ''PackedObsContentDepB)

msgObsDepA :: Word16
msgObsDepA = 0x0045

-- | SBP class for message MSG_OBS_DEP_A (0x0045).
--
-- Deprecated.
data MsgObsDepA = MsgObsDepA
  { _msgObsDepA_header :: ObservationHeader
    -- ^ Header of a GPS observation message
  , _msgObsDepA_obs  :: [PackedObsContentDepA]
    -- ^ Pseudorange and carrier phase observation for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgObsDepA where
  get = do
    _msgObsDepA_header <- get
    _msgObsDepA_obs <- whileM (liftM not isEmpty) get
    return MsgObsDepA {..}

  put MsgObsDepA {..} = do
    put _msgObsDepA_header
    mapM_ put _msgObsDepA_obs

$(deriveSBP 'msgObsDepA ''MsgObsDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgObsDepA_" . stripPrefix "_msgObsDepA_"}
             ''MsgObsDepA)
$(makeLenses ''MsgObsDepA)

msgObsDepB :: Word16
msgObsDepB = 0x0043

-- | SBP class for message MSG_OBS_DEP_B (0x0043).
--
-- This observation message has been deprecated in favor of  observations that
-- are more interoperable. This message should be used for observations
-- referenced to  a nominal pseudorange which are not interoperable with most
-- 3rd party GNSS receievers or typical RTCMv3  observations.
data MsgObsDepB = MsgObsDepB
  { _msgObsDepB_header :: ObservationHeader
    -- ^ Header of a GPS observation message
  , _msgObsDepB_obs  :: [PackedObsContentDepB]
    -- ^ Pseudorange and carrier phase observation for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgObsDepB where
  get = do
    _msgObsDepB_header <- get
    _msgObsDepB_obs <- whileM (liftM not isEmpty) get
    return MsgObsDepB {..}

  put MsgObsDepB {..} = do
    put _msgObsDepB_header
    mapM_ put _msgObsDepB_obs

$(deriveSBP 'msgObsDepB ''MsgObsDepB)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgObsDepB_" . stripPrefix "_msgObsDepB_"}
             ''MsgObsDepB)
$(makeLenses ''MsgObsDepB)
