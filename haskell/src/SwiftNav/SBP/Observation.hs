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

-- | ObsGPSTime.
--
-- A wire-appropriate GPS time, defined as the number of milliseconds since
-- beginning of the week on the Saturday/Sunday transition.
data ObsGPSTime = ObsGPSTime
  { obsGPSTimeTow :: Word32
    -- ^ Milliseconds since start of GPS week
  , obsGPSTimeWn  :: Word16
    -- ^ GPS week number
  } deriving ( Show, Read, Eq )

instance Binary ObsGPSTime where
  get = do
    obsGPSTimeTow <- getWord32le
    obsGPSTimeWn <- getWord16le
    return ObsGPSTime {..}

  put ObsGPSTime {..} = do
    putWord32le obsGPSTimeTow
    putWord16le obsGPSTimeWn

-- | CarrierPhase.
--
-- Carrier phase measurement in cycles represented as a 40-bit fixed point
-- number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
-- fractional cycles.
data CarrierPhase = CarrierPhase
  { carrierPhaseI :: Int32
    -- ^ Carrier phase whole cycles
  , carrierPhaseF :: Word8
    -- ^ Carrier phase fractional part
  } deriving ( Show, Read, Eq )

instance Binary CarrierPhase where
  get = do
    carrierPhaseI <- liftM fromIntegral getWord32le
    carrierPhaseF <- getWord8
    return CarrierPhase {..}

  put CarrierPhase {..} = do
    putWord32le $ fromIntegral carrierPhaseI
    putWord8 carrierPhaseF

-- | ObservationHeader.
--
-- Header of a GPS observation message.
data ObservationHeader = ObservationHeader
  { observationHeaderT     :: ObsGPSTime
    -- ^ GPS time of this observation
  , observationHeaderNObs  :: Word8
    -- ^ Total number of observations. First nibble is the size of the sequence
    -- (n), second nibble is the zero-indexed counter (ith packet of n)
  } deriving ( Show, Read, Eq )

instance Binary ObservationHeader where
  get = do
    observationHeaderT <- get
    observationHeaderNObs <- getWord8
    return ObservationHeader {..}

  put ObservationHeader {..} = do
    put observationHeaderT
    putWord8 observationHeaderNObs

-- | PackedObsContent.
--
-- Pseudorange and carrier phase observation for a satellite being tracked.
data PackedObsContent = PackedObsContent
  { packedObsContentP    :: Word32
    -- ^ Pseudorange observation
  , packedObsContentL    :: CarrierPhase
    -- ^ Carrier phase observation
  , packedObsContentCn0  :: Word8
    -- ^ Carrier-to-Noise density
  , packedObsContentLock :: Word16
    -- ^ Lock indicator. This value changes whenever a satellite signal has lost
    -- and regained lock, indicating that the carrier phase ambiguity may have
    -- changed.
  , packedObsContentSid  :: Word32
    -- ^ Signal identifier of the satellite signal - values 0x00 through 0x1F
    -- represent GPS PRNs 1 through 32 respectively (PRN-1 notation); other
    -- values reserved for future use.
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContent where
  get = do
    packedObsContentP <- getWord32le
    packedObsContentL <- get
    packedObsContentCn0 <- getWord8
    packedObsContentLock <- getWord16le
    packedObsContentSid <- getWord32le
    return PackedObsContent {..}

  put PackedObsContent {..} = do
    putWord32le packedObsContentP
    put packedObsContentL
    putWord8 packedObsContentCn0
    putWord16le packedObsContentLock
    putWord32le packedObsContentSid

msgObs :: Word16
msgObs = 0x0043

-- | SBP class for message MSG_OBS (0x0043).
--
-- The GPS observations message reports all the raw pseudorange and carrier
-- phase observations for the satellites being tracked by the device. Carrier
-- phase observation here is represented as a 40-bit fixed point number with
-- Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of fractional cycles).
data MsgObs = MsgObs
  { msgObsHeader :: ObservationHeader
    -- ^ Header of a GPS observation message
  , msgObsObs    :: [PackedObsContent]
    -- ^ Pseudorange and carrier phase observation for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgObs where
  get = do
    msgObsHeader <- get
    msgObsObs <- whileM (liftM not isEmpty) get
    return MsgObs {..}

  put MsgObs {..} = do
    put msgObsHeader
    mapM_ put msgObsObs

msgBasePos :: Word16
msgBasePos = 0x0044

-- | SBP class for message MSG_BASE_POS (0x0044).
--
-- The base station position message is the position reported by the base
-- station itself. It is used for pseudo-absolute RTK positioning, and is
-- required to be a high-accuracy surveyed location of the base station. Any
-- error here will result in an error in the pseudo-absolute position output.
data MsgBasePos = MsgBasePos
  { msgBasePosLat    :: Double
    -- ^ Latitude
  , msgBasePosLon    :: Double
    -- ^ Longitude
  , msgBasePosHeight :: Double
    -- ^ Height
  } deriving ( Show, Read, Eq )

instance Binary MsgBasePos where
  get = do
    msgBasePosLat <- getFloat64le
    msgBasePosLon <- getFloat64le
    msgBasePosHeight <- getFloat64le
    return MsgBasePos {..}

  put MsgBasePos {..} = do
    putFloat64le msgBasePosLat
    putFloat64le msgBasePosLon
    putFloat64le msgBasePosHeight

msgEphemeris :: Word16
msgEphemeris = 0x0047

-- | SBP class for message MSG_EPHEMERIS (0x0047).
--
-- The ephemeris message returns a set of satellite orbit parameters that is
-- used to calculate GPS satellite position, velocity, and clock offset. Please
-- see the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200,
-- Table 20-III) for more details.
data MsgEphemeris = MsgEphemeris
  { msgEphemerisTgd      :: Double
    -- ^ Group delay differential between L1 and L2
  , msgEphemerisCRs      :: Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , msgEphemerisCRc      :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , msgEphemerisCUc      :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , msgEphemerisCUs      :: Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , msgEphemerisCIc      :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , msgEphemerisCIs      :: Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , msgEphemerisDn       :: Double
    -- ^ Mean motion difference
  , msgEphemerisM0       :: Double
    -- ^ Mean anomaly at reference time
  , msgEphemerisEcc      :: Double
    -- ^ Eccentricity of satellite orbit
  , msgEphemerisSqrta    :: Double
    -- ^ Square root of the semi-major axis of orbit
  , msgEphemerisOmega0   :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , msgEphemerisOmegadot :: Double
    -- ^ Rate of right ascension
  , msgEphemerisW        :: Double
    -- ^ Argument of perigee
  , msgEphemerisInc      :: Double
    -- ^ Inclination
  , msgEphemerisIncDot   :: Double
    -- ^ Inclination first derivative
  , msgEphemerisAf0      :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , msgEphemerisAf1      :: Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , msgEphemerisAf2      :: Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , msgEphemerisToeTow   :: Double
    -- ^ Time of week
  , msgEphemerisToeWn    :: Word16
    -- ^ Week number
  , msgEphemerisTocTow   :: Double
    -- ^ Clock reference time of week
  , msgEphemerisTocWn    :: Word16
    -- ^ Clock reference week number
  , msgEphemerisValid    :: Word8
    -- ^ Is valid?
  , msgEphemerisHealthy  :: Word8
    -- ^ Satellite is healthy?
  , msgEphemerisSid      :: Word32
    -- ^ Signal identifier being tracked - values 0x00 through 0x1F represent GPS
    -- PRNs 1 through 32 respectively (PRN-1 notation); other values reserved
    -- for future use
  , msgEphemerisIode     :: Word8
    -- ^ Issue of ephemeris data
  , msgEphemerisIodc     :: Word16
    -- ^ Issue of clock data
  , msgEphemerisReserved :: Word32
    -- ^ Reserved field
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemeris where
  get = do
    msgEphemerisTgd <- getFloat64le
    msgEphemerisCRs <- getFloat64le
    msgEphemerisCRc <- getFloat64le
    msgEphemerisCUc <- getFloat64le
    msgEphemerisCUs <- getFloat64le
    msgEphemerisCIc <- getFloat64le
    msgEphemerisCIs <- getFloat64le
    msgEphemerisDn <- getFloat64le
    msgEphemerisM0 <- getFloat64le
    msgEphemerisEcc <- getFloat64le
    msgEphemerisSqrta <- getFloat64le
    msgEphemerisOmega0 <- getFloat64le
    msgEphemerisOmegadot <- getFloat64le
    msgEphemerisW <- getFloat64le
    msgEphemerisInc <- getFloat64le
    msgEphemerisIncDot <- getFloat64le
    msgEphemerisAf0 <- getFloat64le
    msgEphemerisAf1 <- getFloat64le
    msgEphemerisAf2 <- getFloat64le
    msgEphemerisToeTow <- getFloat64le
    msgEphemerisToeWn <- getWord16le
    msgEphemerisTocTow <- getFloat64le
    msgEphemerisTocWn <- getWord16le
    msgEphemerisValid <- getWord8
    msgEphemerisHealthy <- getWord8
    msgEphemerisSid <- getWord32le
    msgEphemerisIode <- getWord8
    msgEphemerisIodc <- getWord16le
    msgEphemerisReserved <- getWord32le
    return MsgEphemeris {..}

  put MsgEphemeris {..} = do
    putFloat64le msgEphemerisTgd
    putFloat64le msgEphemerisCRs
    putFloat64le msgEphemerisCRc
    putFloat64le msgEphemerisCUc
    putFloat64le msgEphemerisCUs
    putFloat64le msgEphemerisCIc
    putFloat64le msgEphemerisCIs
    putFloat64le msgEphemerisDn
    putFloat64le msgEphemerisM0
    putFloat64le msgEphemerisEcc
    putFloat64le msgEphemerisSqrta
    putFloat64le msgEphemerisOmega0
    putFloat64le msgEphemerisOmegadot
    putFloat64le msgEphemerisW
    putFloat64le msgEphemerisInc
    putFloat64le msgEphemerisIncDot
    putFloat64le msgEphemerisAf0
    putFloat64le msgEphemerisAf1
    putFloat64le msgEphemerisAf2
    putFloat64le msgEphemerisToeTow
    putWord16le msgEphemerisToeWn
    putFloat64le msgEphemerisTocTow
    putWord16le msgEphemerisTocWn
    putWord8 msgEphemerisValid
    putWord8 msgEphemerisHealthy
    putWord32le msgEphemerisSid
    putWord8 msgEphemerisIode
    putWord16le msgEphemerisIodc
    putWord32le msgEphemerisReserved

msgEphemerisDepA :: Word16
msgEphemerisDepA = 0x001A

-- | SBP class for message MSG_EPHEMERIS_DEP_A (0x001A).
--
-- Deprecated.
data MsgEphemerisDepA = MsgEphemerisDepA
  { msgEphemerisDepATgd      :: Double
    -- ^ Group delay differential between L1 and L2
  , msgEphemerisDepACRs      :: Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , msgEphemerisDepACRc      :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , msgEphemerisDepACUc      :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , msgEphemerisDepACUs      :: Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , msgEphemerisDepACIc      :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , msgEphemerisDepACIs      :: Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , msgEphemerisDepADn       :: Double
    -- ^ Mean motion difference
  , msgEphemerisDepAM0       :: Double
    -- ^ Mean anomaly at reference time
  , msgEphemerisDepAEcc      :: Double
    -- ^ Eccentricity of satellite orbit
  , msgEphemerisDepASqrta    :: Double
    -- ^ Square root of the semi-major axis of orbit
  , msgEphemerisDepAOmega0   :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , msgEphemerisDepAOmegadot :: Double
    -- ^ Rate of right ascension
  , msgEphemerisDepAW        :: Double
    -- ^ Argument of perigee
  , msgEphemerisDepAInc      :: Double
    -- ^ Inclination
  , msgEphemerisDepAIncDot   :: Double
    -- ^ Inclination first derivative
  , msgEphemerisDepAAf0      :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , msgEphemerisDepAAf1      :: Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , msgEphemerisDepAAf2      :: Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , msgEphemerisDepAToeTow   :: Double
    -- ^ Time of week
  , msgEphemerisDepAToeWn    :: Word16
    -- ^ Week number
  , msgEphemerisDepATocTow   :: Double
    -- ^ Clock reference time of week
  , msgEphemerisDepATocWn    :: Word16
    -- ^ Clock reference week number
  , msgEphemerisDepAValid    :: Word8
    -- ^ Is valid?
  , msgEphemerisDepAHealthy  :: Word8
    -- ^ Satellite is healthy?
  , msgEphemerisDepAPrn      :: Word8
    -- ^ PRN being tracked
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisDepA where
  get = do
    msgEphemerisDepATgd <- getFloat64le
    msgEphemerisDepACRs <- getFloat64le
    msgEphemerisDepACRc <- getFloat64le
    msgEphemerisDepACUc <- getFloat64le
    msgEphemerisDepACUs <- getFloat64le
    msgEphemerisDepACIc <- getFloat64le
    msgEphemerisDepACIs <- getFloat64le
    msgEphemerisDepADn <- getFloat64le
    msgEphemerisDepAM0 <- getFloat64le
    msgEphemerisDepAEcc <- getFloat64le
    msgEphemerisDepASqrta <- getFloat64le
    msgEphemerisDepAOmega0 <- getFloat64le
    msgEphemerisDepAOmegadot <- getFloat64le
    msgEphemerisDepAW <- getFloat64le
    msgEphemerisDepAInc <- getFloat64le
    msgEphemerisDepAIncDot <- getFloat64le
    msgEphemerisDepAAf0 <- getFloat64le
    msgEphemerisDepAAf1 <- getFloat64le
    msgEphemerisDepAAf2 <- getFloat64le
    msgEphemerisDepAToeTow <- getFloat64le
    msgEphemerisDepAToeWn <- getWord16le
    msgEphemerisDepATocTow <- getFloat64le
    msgEphemerisDepATocWn <- getWord16le
    msgEphemerisDepAValid <- getWord8
    msgEphemerisDepAHealthy <- getWord8
    msgEphemerisDepAPrn <- getWord8
    return MsgEphemerisDepA {..}

  put MsgEphemerisDepA {..} = do
    putFloat64le msgEphemerisDepATgd
    putFloat64le msgEphemerisDepACRs
    putFloat64le msgEphemerisDepACRc
    putFloat64le msgEphemerisDepACUc
    putFloat64le msgEphemerisDepACUs
    putFloat64le msgEphemerisDepACIc
    putFloat64le msgEphemerisDepACIs
    putFloat64le msgEphemerisDepADn
    putFloat64le msgEphemerisDepAM0
    putFloat64le msgEphemerisDepAEcc
    putFloat64le msgEphemerisDepASqrta
    putFloat64le msgEphemerisDepAOmega0
    putFloat64le msgEphemerisDepAOmegadot
    putFloat64le msgEphemerisDepAW
    putFloat64le msgEphemerisDepAInc
    putFloat64le msgEphemerisDepAIncDot
    putFloat64le msgEphemerisDepAAf0
    putFloat64le msgEphemerisDepAAf1
    putFloat64le msgEphemerisDepAAf2
    putFloat64le msgEphemerisDepAToeTow
    putWord16le msgEphemerisDepAToeWn
    putFloat64le msgEphemerisDepATocTow
    putWord16le msgEphemerisDepATocWn
    putWord8 msgEphemerisDepAValid
    putWord8 msgEphemerisDepAHealthy
    putWord8 msgEphemerisDepAPrn

msgEphemerisDepB :: Word16
msgEphemerisDepB = 0x0046

-- | SBP class for message MSG_EPHEMERIS_DEP_B (0x0046).
--
-- Deprecated.
data MsgEphemerisDepB = MsgEphemerisDepB
  { msgEphemerisDepBTgd      :: Double
    -- ^ Group delay differential between L1 and L2
  , msgEphemerisDepBCRs      :: Double
    -- ^ Amplitude of the sine harmonic correction term to the orbit radius
  , msgEphemerisDepBCRc      :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the orbit radius
  , msgEphemerisDepBCUc      :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the argument of
    -- latitude
  , msgEphemerisDepBCUs      :: Double
    -- ^ Amplitude of the sine harmonic correction term to the argument of
    -- latitude
  , msgEphemerisDepBCIc      :: Double
    -- ^ Amplitude of the cosine harmonic correction term to the angle of
    -- inclination
  , msgEphemerisDepBCIs      :: Double
    -- ^ Amplitude of the sine harmonic correction term to the angle of
    -- inclination
  , msgEphemerisDepBDn       :: Double
    -- ^ Mean motion difference
  , msgEphemerisDepBM0       :: Double
    -- ^ Mean anomaly at reference time
  , msgEphemerisDepBEcc      :: Double
    -- ^ Eccentricity of satellite orbit
  , msgEphemerisDepBSqrta    :: Double
    -- ^ Square root of the semi-major axis of orbit
  , msgEphemerisDepBOmega0   :: Double
    -- ^ Longitude of ascending node of orbit plane at weekly epoch
  , msgEphemerisDepBOmegadot :: Double
    -- ^ Rate of right ascension
  , msgEphemerisDepBW        :: Double
    -- ^ Argument of perigee
  , msgEphemerisDepBInc      :: Double
    -- ^ Inclination
  , msgEphemerisDepBIncDot   :: Double
    -- ^ Inclination first derivative
  , msgEphemerisDepBAf0      :: Double
    -- ^ Polynomial clock correction coefficient (clock bias)
  , msgEphemerisDepBAf1      :: Double
    -- ^ Polynomial clock correction coefficient (clock drift)
  , msgEphemerisDepBAf2      :: Double
    -- ^ Polynomial clock correction coefficient (rate of clock drift)
  , msgEphemerisDepBToeTow   :: Double
    -- ^ Time of week
  , msgEphemerisDepBToeWn    :: Word16
    -- ^ Week number
  , msgEphemerisDepBTocTow   :: Double
    -- ^ Clock reference time of week
  , msgEphemerisDepBTocWn    :: Word16
    -- ^ Clock reference week number
  , msgEphemerisDepBValid    :: Word8
    -- ^ Is valid?
  , msgEphemerisDepBHealthy  :: Word8
    -- ^ Satellite is healthy?
  , msgEphemerisDepBPrn      :: Word8
    -- ^ PRN being tracked
  , msgEphemerisDepBIode     :: Word8
    -- ^ Issue of ephemeris data
  } deriving ( Show, Read, Eq )

instance Binary MsgEphemerisDepB where
  get = do
    msgEphemerisDepBTgd <- getFloat64le
    msgEphemerisDepBCRs <- getFloat64le
    msgEphemerisDepBCRc <- getFloat64le
    msgEphemerisDepBCUc <- getFloat64le
    msgEphemerisDepBCUs <- getFloat64le
    msgEphemerisDepBCIc <- getFloat64le
    msgEphemerisDepBCIs <- getFloat64le
    msgEphemerisDepBDn <- getFloat64le
    msgEphemerisDepBM0 <- getFloat64le
    msgEphemerisDepBEcc <- getFloat64le
    msgEphemerisDepBSqrta <- getFloat64le
    msgEphemerisDepBOmega0 <- getFloat64le
    msgEphemerisDepBOmegadot <- getFloat64le
    msgEphemerisDepBW <- getFloat64le
    msgEphemerisDepBInc <- getFloat64le
    msgEphemerisDepBIncDot <- getFloat64le
    msgEphemerisDepBAf0 <- getFloat64le
    msgEphemerisDepBAf1 <- getFloat64le
    msgEphemerisDepBAf2 <- getFloat64le
    msgEphemerisDepBToeTow <- getFloat64le
    msgEphemerisDepBToeWn <- getWord16le
    msgEphemerisDepBTocTow <- getFloat64le
    msgEphemerisDepBTocWn <- getWord16le
    msgEphemerisDepBValid <- getWord8
    msgEphemerisDepBHealthy <- getWord8
    msgEphemerisDepBPrn <- getWord8
    msgEphemerisDepBIode <- getWord8
    return MsgEphemerisDepB {..}

  put MsgEphemerisDepB {..} = do
    putFloat64le msgEphemerisDepBTgd
    putFloat64le msgEphemerisDepBCRs
    putFloat64le msgEphemerisDepBCRc
    putFloat64le msgEphemerisDepBCUc
    putFloat64le msgEphemerisDepBCUs
    putFloat64le msgEphemerisDepBCIc
    putFloat64le msgEphemerisDepBCIs
    putFloat64le msgEphemerisDepBDn
    putFloat64le msgEphemerisDepBM0
    putFloat64le msgEphemerisDepBEcc
    putFloat64le msgEphemerisDepBSqrta
    putFloat64le msgEphemerisDepBOmega0
    putFloat64le msgEphemerisDepBOmegadot
    putFloat64le msgEphemerisDepBW
    putFloat64le msgEphemerisDepBInc
    putFloat64le msgEphemerisDepBIncDot
    putFloat64le msgEphemerisDepBAf0
    putFloat64le msgEphemerisDepBAf1
    putFloat64le msgEphemerisDepBAf2
    putFloat64le msgEphemerisDepBToeTow
    putWord16le msgEphemerisDepBToeWn
    putFloat64le msgEphemerisDepBTocTow
    putWord16le msgEphemerisDepBTocWn
    putWord8 msgEphemerisDepBValid
    putWord8 msgEphemerisDepBHealthy
    putWord8 msgEphemerisDepBPrn
    putWord8 msgEphemerisDepBIode

-- | PackedObsContentDepA.
--
-- Deprecated.
data PackedObsContentDepA = PackedObsContentDepA
  { packedObsContentDepAP    :: Word32
    -- ^ Pseudorange observation
  , packedObsContentDepAL    :: CarrierPhase
    -- ^ Carrier phase observation
  , packedObsContentDepACn0  :: Word8
    -- ^ Carrier-to-Noise density
  , packedObsContentDepALock :: Word16
    -- ^ Lock indicator. This value changes whenever a satellite signal has lost
    -- and regained lock, indicating that the carrier phase ambiguity may have
    -- changed.
  , packedObsContentDepAPrn  :: Word8
    -- ^ PRN-1 identifier of the satellite signal
  } deriving ( Show, Read, Eq )

instance Binary PackedObsContentDepA where
  get = do
    packedObsContentDepAP <- getWord32le
    packedObsContentDepAL <- get
    packedObsContentDepACn0 <- getWord8
    packedObsContentDepALock <- getWord16le
    packedObsContentDepAPrn <- getWord8
    return PackedObsContentDepA {..}

  put PackedObsContentDepA {..} = do
    putWord32le packedObsContentDepAP
    put packedObsContentDepAL
    putWord8 packedObsContentDepACn0
    putWord16le packedObsContentDepALock
    putWord8 packedObsContentDepAPrn

msgObsDepA :: Word16
msgObsDepA = 0x0045

-- | SBP class for message MSG_OBS_DEP_A (0x0045).
--
-- Deprecated.
data MsgObsDepA = MsgObsDepA
  { msgObsDepAHeader :: ObservationHeader
    -- ^ Header of a GPS observation message
  , msgObsDepAObs    :: [PackedObsContentDepA]
    -- ^ Pseudorange and carrier phase observation for a satellite being tracked.
  } deriving ( Show, Read, Eq )

instance Binary MsgObsDepA where
  get = do
    msgObsDepAHeader <- get
    msgObsDepAObs <- whileM (liftM not isEmpty) get
    return MsgObsDepA {..}

  put MsgObsDepA {..} = do
    put msgObsDepAHeader
    mapM_ put msgObsDepAObs
