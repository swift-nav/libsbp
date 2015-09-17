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
import SwiftNav.SBP.TH
import SwiftNav.SBP.Types

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
-- fractional cycles.
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
-- Pseudorange and carrier phase observation for a satellite being tracked.
data PackedObsContent = PackedObsContent
  { _packedObsContent_P  :: Word32
    -- ^ Pseudorange observation
  , _packedObsContent_L  :: CarrierPhase
    -- ^ Carrier phase observation
  , _packedObsContent_cn0 :: Word8
    -- ^ Carrier-to-Noise density
  , _packedObsContent_lock :: Word16
    -- ^ Lock indicator. This value changes whenever a satellite signal has lost
    -- and regained lock, indicating that the carrier phase ambiguity may have
    -- changed.
  , _packedObsContent_sid :: Word32
    -- ^ Signal identifier of the satellite signal - values 0x00 through 0x1F
    -- represent GPS PRNs 1 through 32 respectively (PRN-1 notation); other
    -- values reserved for future use.
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContent where
  get = do
    _packedObsContent_P <- getWord32le
    _packedObsContent_L <- get
    _packedObsContent_cn0 <- getWord8
    _packedObsContent_lock <- getWord16le
    _packedObsContent_sid <- getWord32le
    return PackedObsContent {..}

  put PackedObsContent {..} = do
    putWord32le _packedObsContent_P
    put _packedObsContent_L
    putWord8 _packedObsContent_cn0
    putWord16le _packedObsContent_lock
    putWord32le _packedObsContent_sid
$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_packedObsContent_" . stripPrefix "_packedObsContent_"}
             ''PackedObsContent)
$(makeLenses ''PackedObsContent)

msgObs :: Word16
msgObs = 0x0043

-- | SBP class for message MSG_OBS (0x0043).
--
-- The GPS observations message reports all the raw pseudorange and carrier
-- phase observations for the satellites being tracked by the device. Carrier
-- phase observation here is represented as a 40-bit fixed point number with
-- Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of fractional cycles).
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

msgBasePos :: Word16
msgBasePos = 0x0044

-- | SBP class for message MSG_BASE_POS (0x0044).
--
-- The base station position message is the position reported by the base
-- station itself. It is used for pseudo-absolute RTK positioning, and is
-- required to be a high-accuracy surveyed location of the base station. Any
-- error here will result in an error in the pseudo-absolute position output.
data MsgBasePos = MsgBasePos
  { _msgBasePos_lat  :: Double
    -- ^ Latitude
  , _msgBasePos_lon  :: Double
    -- ^ Longitude
  , _msgBasePos_height :: Double
    -- ^ Height
  } deriving ( Show, Read, Eq )

instance Binary MsgBasePos where
  get = do
    _msgBasePos_lat <- getFloat64le
    _msgBasePos_lon <- getFloat64le
    _msgBasePos_height <- getFloat64le
    return MsgBasePos {..}

  put MsgBasePos {..} = do
    putFloat64le _msgBasePos_lat
    putFloat64le _msgBasePos_lon
    putFloat64le _msgBasePos_height

$(deriveSBP 'msgBasePos ''MsgBasePos)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgBasePos_" . stripPrefix "_msgBasePos_"}
             ''MsgBasePos)
$(makeLenses ''MsgBasePos)

msgEphemeris :: Word16
msgEphemeris = 0x0047

-- | SBP class for message MSG_EPHEMERIS (0x0047).
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
  , _msgEphemeris_sid    :: Word32
    -- ^ Signal identifier being tracked - values 0x00 through 0x1F represent GPS
    -- PRNs 1 through 32 respectively (PRN-1 notation); other values reserved
    -- for future use
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
    _msgEphemeris_sid <- getWord32le
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
    putWord32le _msgEphemeris_sid
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

-- | PackedObsContentDepA.
--
-- Deprecated.
data PackedObsContentDepA = PackedObsContentDepA
  { _packedObsContentDepA_P  :: Word32
    -- ^ Pseudorange observation
  , _packedObsContentDepA_L  :: CarrierPhase
    -- ^ Carrier phase observation
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
