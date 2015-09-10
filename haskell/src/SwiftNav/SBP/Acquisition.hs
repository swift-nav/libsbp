-- |
-- Module:      SwiftNav.SBP.Acquisition
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Satellite acquisition messages from the device.

module SwiftNav.SBP.Acquisition where

import BasicPrelude
import Control.Monad
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

msgAcqResult :: Word16
msgAcqResult = 0x0014

-- | SBP class for message MSG_ACQ_RESULT (0x0014).
--
-- This message describes the results from an attempted GPS signal acquisition
-- search for a satellite PRN over a code phase/carrier frequency range. It
-- contains the parameters of the point in the acquisition search space with
-- the best signal-to-noise (SNR) ratio.
data MsgAcqResult = MsgAcqResult
  { msgAcqResult_snr :: Float
    -- ^ SNR of best point. Currently dimensonless, but will have units of dB Hz
    -- in the revision of this message.
  , msgAcqResult_cp :: Float
    -- ^ Code phase of best point
  , msgAcqResult_cf :: Float
    -- ^ Carrier frequency of best point
  , msgAcqResult_sid :: Word32
    -- ^ Signal identifier of the satellite signal for which acquisition was
    -- attempted - values 0x00 through 0x1F represent GPS PRNs 1 through 32
    -- respectively (PRN-1 notation); other values reserved for future use.
  } deriving ( Show, Read, Eq )

instance Binary MsgAcqResult where
  get = do
    msgAcqResult_snr <- getFloat32le
    msgAcqResult_cp <- getFloat32le
    msgAcqResult_cf <- getFloat32le
    msgAcqResult_sid <- getWord32le
    return MsgAcqResult {..}

  put MsgAcqResult {..} = do
    putFloat32le msgAcqResult_snr
    putFloat32le msgAcqResult_cp
    putFloat32le msgAcqResult_cf
    putWord32le msgAcqResult_sid

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgAcqResult_" . stripPrefix "msgAcqResult_"}
             ''MsgAcqResult)

msgAcqResultDepA :: Word16
msgAcqResultDepA = 0x0015

-- | SBP class for message MSG_ACQ_RESULT_DEP_A (0x0015).
--
-- Deprecated.
data MsgAcqResultDepA = MsgAcqResultDepA
  { msgAcqResultDepA_snr :: Float
    -- ^ SNR of best point. Currently dimensonless, but will have units of dB Hz
    -- in the revision of this message.
  , msgAcqResultDepA_cp :: Float
    -- ^ Code phase of best point
  , msgAcqResultDepA_cf :: Float
    -- ^ Carrier frequency of best point
  , msgAcqResultDepA_prn :: Word8
    -- ^ PRN-1 identifier of the satellite signal for which acquisition was
    -- attempted
  } deriving ( Show, Read, Eq )

instance Binary MsgAcqResultDepA where
  get = do
    msgAcqResultDepA_snr <- getFloat32le
    msgAcqResultDepA_cp <- getFloat32le
    msgAcqResultDepA_cf <- getFloat32le
    msgAcqResultDepA_prn <- getWord8
    return MsgAcqResultDepA {..}

  put MsgAcqResultDepA {..} = do
    putFloat32le msgAcqResultDepA_snr
    putFloat32le msgAcqResultDepA_cp
    putFloat32le msgAcqResultDepA_cf
    putWord8 msgAcqResultDepA_prn

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "msgAcqResultDepA_" . stripPrefix "msgAcqResultDepA_"}
             ''MsgAcqResultDepA)
