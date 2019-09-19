{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Acquisition
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- \<Satellite acquisition messages from the device.\>

module SwiftNav.SBP.Acquisition
  ( module SwiftNav.SBP.Acquisition
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


msgAcqResult :: Word16
msgAcqResult = 0x002F

-- | SBP class for message MSG_ACQ_RESULT (0x002F).
--
-- This message describes the results from an attempted GPS signal acquisition
-- search for a satellite PRN over a code phase/carrier frequency range. It
-- contains the parameters of the point in the acquisition search space with
-- the best carrier-to-noise (CN/0) ratio.
data MsgAcqResult = MsgAcqResult
  { _msgAcqResult_cn0 :: !Float
    -- ^ CN/0 of best point
  , _msgAcqResult_cp :: !Float
    -- ^ Code phase of best point
  , _msgAcqResult_cf :: !Float
    -- ^ Carrier frequency of best point
  , _msgAcqResult_sid :: !GnssSignal
    -- ^ GNSS signal for which acquisition was attempted
  } deriving ( Show, Read, Eq )

instance Binary MsgAcqResult where
  get = do
    _msgAcqResult_cn0 <- getFloat32le
    _msgAcqResult_cp <- getFloat32le
    _msgAcqResult_cf <- getFloat32le
    _msgAcqResult_sid <- get
    pure MsgAcqResult {..}

  put MsgAcqResult {..} = do
    putFloat32le _msgAcqResult_cn0
    putFloat32le _msgAcqResult_cp
    putFloat32le _msgAcqResult_cf
    put _msgAcqResult_sid

$(makeSBP 'msgAcqResult ''MsgAcqResult)
$(makeJSON "_msgAcqResult_" ''MsgAcqResult)
$(makeLenses ''MsgAcqResult)

msgAcqResultDepC :: Word16
msgAcqResultDepC = 0x001F

-- | SBP class for message MSG_ACQ_RESULT_DEP_C (0x001F).
--
-- Deprecated.
data MsgAcqResultDepC = MsgAcqResultDepC
  { _msgAcqResultDepC_cn0 :: !Float
    -- ^ CN/0 of best point
  , _msgAcqResultDepC_cp :: !Float
    -- ^ Code phase of best point
  , _msgAcqResultDepC_cf :: !Float
    -- ^ Carrier frequency of best point
  , _msgAcqResultDepC_sid :: !GnssSignalDep
    -- ^ GNSS signal for which acquisition was attempted
  } deriving ( Show, Read, Eq )

instance Binary MsgAcqResultDepC where
  get = do
    _msgAcqResultDepC_cn0 <- getFloat32le
    _msgAcqResultDepC_cp <- getFloat32le
    _msgAcqResultDepC_cf <- getFloat32le
    _msgAcqResultDepC_sid <- get
    pure MsgAcqResultDepC {..}

  put MsgAcqResultDepC {..} = do
    putFloat32le _msgAcqResultDepC_cn0
    putFloat32le _msgAcqResultDepC_cp
    putFloat32le _msgAcqResultDepC_cf
    put _msgAcqResultDepC_sid

$(makeSBP 'msgAcqResultDepC ''MsgAcqResultDepC)
$(makeJSON "_msgAcqResultDepC_" ''MsgAcqResultDepC)
$(makeLenses ''MsgAcqResultDepC)

msgAcqResultDepB :: Word16
msgAcqResultDepB = 0x0014

-- | SBP class for message MSG_ACQ_RESULT_DEP_B (0x0014).
--
-- Deprecated.
data MsgAcqResultDepB = MsgAcqResultDepB
  { _msgAcqResultDepB_snr :: !Float
    -- ^ SNR of best point. Currently in arbitrary SNR points, but will be in
    -- units of dB Hz in a later revision of this message.
  , _msgAcqResultDepB_cp :: !Float
    -- ^ Code phase of best point
  , _msgAcqResultDepB_cf :: !Float
    -- ^ Carrier frequency of best point
  , _msgAcqResultDepB_sid :: !GnssSignalDep
    -- ^ GNSS signal for which acquisition was attempted
  } deriving ( Show, Read, Eq )

instance Binary MsgAcqResultDepB where
  get = do
    _msgAcqResultDepB_snr <- getFloat32le
    _msgAcqResultDepB_cp <- getFloat32le
    _msgAcqResultDepB_cf <- getFloat32le
    _msgAcqResultDepB_sid <- get
    pure MsgAcqResultDepB {..}

  put MsgAcqResultDepB {..} = do
    putFloat32le _msgAcqResultDepB_snr
    putFloat32le _msgAcqResultDepB_cp
    putFloat32le _msgAcqResultDepB_cf
    put _msgAcqResultDepB_sid

$(makeSBP 'msgAcqResultDepB ''MsgAcqResultDepB)
$(makeJSON "_msgAcqResultDepB_" ''MsgAcqResultDepB)
$(makeLenses ''MsgAcqResultDepB)

msgAcqResultDepA :: Word16
msgAcqResultDepA = 0x0015

-- | SBP class for message MSG_ACQ_RESULT_DEP_A (0x0015).
--
-- Deprecated.
data MsgAcqResultDepA = MsgAcqResultDepA
  { _msgAcqResultDepA_snr :: !Float
    -- ^ SNR of best point. Currently dimensonless, but will have units of dB Hz
    -- in the revision of this message.
  , _msgAcqResultDepA_cp :: !Float
    -- ^ Code phase of best point
  , _msgAcqResultDepA_cf :: !Float
    -- ^ Carrier frequency of best point
  , _msgAcqResultDepA_prn :: !Word8
    -- ^ PRN-1 identifier of the satellite signal for which acquisition was
    -- attempted
  } deriving ( Show, Read, Eq )

instance Binary MsgAcqResultDepA where
  get = do
    _msgAcqResultDepA_snr <- getFloat32le
    _msgAcqResultDepA_cp <- getFloat32le
    _msgAcqResultDepA_cf <- getFloat32le
    _msgAcqResultDepA_prn <- getWord8
    pure MsgAcqResultDepA {..}

  put MsgAcqResultDepA {..} = do
    putFloat32le _msgAcqResultDepA_snr
    putFloat32le _msgAcqResultDepA_cp
    putFloat32le _msgAcqResultDepA_cf
    putWord8 _msgAcqResultDepA_prn

$(makeSBP 'msgAcqResultDepA ''MsgAcqResultDepA)
$(makeJSON "_msgAcqResultDepA_" ''MsgAcqResultDepA)
$(makeLenses ''MsgAcqResultDepA)

-- | AcqSvProfile.
--
-- Profile for a specific SV for debugging purposes The message describes SV
-- profile during acquisition time. The message is used to debug and measure
-- the performance.
data AcqSvProfile = AcqSvProfile
  { _acqSvProfile_job_type :: !Word8
    -- ^ SV search job type (deep, fallback, etc)
  , _acqSvProfile_status   :: !Word8
    -- ^ Acquisition status 1 is Success, 0 is Failure
  , _acqSvProfile_cn0      :: !Word16
    -- ^ CN0 value. Only valid if status is '1'
  , _acqSvProfile_int_time :: !Word8
    -- ^ Acquisition integration time
  , _acqSvProfile_sid      :: !GnssSignal
    -- ^ GNSS signal for which acquisition was attempted
  , _acqSvProfile_bin_width :: !Word16
    -- ^ Acq frequency bin width
  , _acqSvProfile_timestamp :: !Word32
    -- ^ Timestamp of the job complete event
  , _acqSvProfile_time_spent :: !Word32
    -- ^ Time spent to search for sid.code
  , _acqSvProfile_cf_min   :: !Int32
    -- ^ Doppler range lowest frequency
  , _acqSvProfile_cf_max   :: !Int32
    -- ^ Doppler range highest frequency
  , _acqSvProfile_cf       :: !Int32
    -- ^ Doppler value of detected peak. Only valid if status is '1'
  , _acqSvProfile_cp       :: !Word32
    -- ^ Codephase of detected peak. Only valid if status is '1'
  } deriving ( Show, Read, Eq )

instance Binary AcqSvProfile where
  get = do
    _acqSvProfile_job_type <- getWord8
    _acqSvProfile_status <- getWord8
    _acqSvProfile_cn0 <- getWord16le
    _acqSvProfile_int_time <- getWord8
    _acqSvProfile_sid <- get
    _acqSvProfile_bin_width <- getWord16le
    _acqSvProfile_timestamp <- getWord32le
    _acqSvProfile_time_spent <- getWord32le
    _acqSvProfile_cf_min <- fromIntegral <$> getWord32le
    _acqSvProfile_cf_max <- fromIntegral <$> getWord32le
    _acqSvProfile_cf <- fromIntegral <$> getWord32le
    _acqSvProfile_cp <- getWord32le
    pure AcqSvProfile {..}

  put AcqSvProfile {..} = do
    putWord8 _acqSvProfile_job_type
    putWord8 _acqSvProfile_status
    putWord16le _acqSvProfile_cn0
    putWord8 _acqSvProfile_int_time
    put _acqSvProfile_sid
    putWord16le _acqSvProfile_bin_width
    putWord32le _acqSvProfile_timestamp
    putWord32le _acqSvProfile_time_spent
    (putWord32le . fromIntegral) _acqSvProfile_cf_min
    (putWord32le . fromIntegral) _acqSvProfile_cf_max
    (putWord32le . fromIntegral) _acqSvProfile_cf
    putWord32le _acqSvProfile_cp

$(makeJSON "_acqSvProfile_" ''AcqSvProfile)
$(makeLenses ''AcqSvProfile)

-- | AcqSvProfileDep.
--
-- Deprecated.
data AcqSvProfileDep = AcqSvProfileDep
  { _acqSvProfileDep_job_type :: !Word8
    -- ^ SV search job type (deep, fallback, etc)
  , _acqSvProfileDep_status   :: !Word8
    -- ^ Acquisition status 1 is Success, 0 is Failure
  , _acqSvProfileDep_cn0      :: !Word16
    -- ^ CN0 value. Only valid if status is '1'
  , _acqSvProfileDep_int_time :: !Word8
    -- ^ Acquisition integration time
  , _acqSvProfileDep_sid      :: !GnssSignalDep
    -- ^ GNSS signal for which acquisition was attempted
  , _acqSvProfileDep_bin_width :: !Word16
    -- ^ Acq frequency bin width
  , _acqSvProfileDep_timestamp :: !Word32
    -- ^ Timestamp of the job complete event
  , _acqSvProfileDep_time_spent :: !Word32
    -- ^ Time spent to search for sid.code
  , _acqSvProfileDep_cf_min   :: !Int32
    -- ^ Doppler range lowest frequency
  , _acqSvProfileDep_cf_max   :: !Int32
    -- ^ Doppler range highest frequency
  , _acqSvProfileDep_cf       :: !Int32
    -- ^ Doppler value of detected peak. Only valid if status is '1'
  , _acqSvProfileDep_cp       :: !Word32
    -- ^ Codephase of detected peak. Only valid if status is '1'
  } deriving ( Show, Read, Eq )

instance Binary AcqSvProfileDep where
  get = do
    _acqSvProfileDep_job_type <- getWord8
    _acqSvProfileDep_status <- getWord8
    _acqSvProfileDep_cn0 <- getWord16le
    _acqSvProfileDep_int_time <- getWord8
    _acqSvProfileDep_sid <- get
    _acqSvProfileDep_bin_width <- getWord16le
    _acqSvProfileDep_timestamp <- getWord32le
    _acqSvProfileDep_time_spent <- getWord32le
    _acqSvProfileDep_cf_min <- fromIntegral <$> getWord32le
    _acqSvProfileDep_cf_max <- fromIntegral <$> getWord32le
    _acqSvProfileDep_cf <- fromIntegral <$> getWord32le
    _acqSvProfileDep_cp <- getWord32le
    pure AcqSvProfileDep {..}

  put AcqSvProfileDep {..} = do
    putWord8 _acqSvProfileDep_job_type
    putWord8 _acqSvProfileDep_status
    putWord16le _acqSvProfileDep_cn0
    putWord8 _acqSvProfileDep_int_time
    put _acqSvProfileDep_sid
    putWord16le _acqSvProfileDep_bin_width
    putWord32le _acqSvProfileDep_timestamp
    putWord32le _acqSvProfileDep_time_spent
    (putWord32le . fromIntegral) _acqSvProfileDep_cf_min
    (putWord32le . fromIntegral) _acqSvProfileDep_cf_max
    (putWord32le . fromIntegral) _acqSvProfileDep_cf
    putWord32le _acqSvProfileDep_cp

$(makeJSON "_acqSvProfileDep_" ''AcqSvProfileDep)
$(makeLenses ''AcqSvProfileDep)

msgAcqSvProfile :: Word16
msgAcqSvProfile = 0x002E

-- | SBP class for message MSG_ACQ_SV_PROFILE (0x002E).
--
-- The message describes all SV profiles during acquisition time. The message
-- is used to debug and measure the performance.
data MsgAcqSvProfile = MsgAcqSvProfile
  { _msgAcqSvProfile_acq_sv_profile :: ![AcqSvProfile]
    -- ^ SV profiles during acquisition time
  } deriving ( Show, Read, Eq )

instance Binary MsgAcqSvProfile where
  get = do
    _msgAcqSvProfile_acq_sv_profile <- whileM (not <$> isEmpty) get
    pure MsgAcqSvProfile {..}

  put MsgAcqSvProfile {..} = do
    mapM_ put _msgAcqSvProfile_acq_sv_profile

$(makeSBP 'msgAcqSvProfile ''MsgAcqSvProfile)
$(makeJSON "_msgAcqSvProfile_" ''MsgAcqSvProfile)
$(makeLenses ''MsgAcqSvProfile)

msgAcqSvProfileDep :: Word16
msgAcqSvProfileDep = 0x001E

-- | SBP class for message MSG_ACQ_SV_PROFILE_DEP (0x001E).
--
-- Deprecated.
data MsgAcqSvProfileDep = MsgAcqSvProfileDep
  { _msgAcqSvProfileDep_acq_sv_profile :: ![AcqSvProfileDep]
    -- ^ SV profiles during acquisition time
  } deriving ( Show, Read, Eq )

instance Binary MsgAcqSvProfileDep where
  get = do
    _msgAcqSvProfileDep_acq_sv_profile <- whileM (not <$> isEmpty) get
    pure MsgAcqSvProfileDep {..}

  put MsgAcqSvProfileDep {..} = do
    mapM_ put _msgAcqSvProfileDep_acq_sv_profile

$(makeSBP 'msgAcqSvProfileDep ''MsgAcqSvProfileDep)
$(makeJSON "_msgAcqSvProfileDep_" ''MsgAcqSvProfileDep)
$(makeLenses ''MsgAcqSvProfileDep)
