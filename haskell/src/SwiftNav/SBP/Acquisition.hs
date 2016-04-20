{-# OPTIONS_GHC -fno-warn-unused-imports #-}
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

msgAcqResult :: Word16
msgAcqResult = 0x0014

-- | SBP class for message MSG_ACQ_RESULT (0x0014).
--
-- This message describes the results from an attempted GPS signal acquisition
-- search for a satellite PRN over a code phase/carrier frequency range. It
-- contains the parameters of the point in the acquisition search space with
-- the best signal-to-noise (SNR) ratio.
data MsgAcqResult = MsgAcqResult
  { _msgAcqResult_snr :: Float
    -- ^ SNR of best point. Currently in arbitrary SNR points, but will be in
    -- units of dB Hz in a later revision of this message.
  , _msgAcqResult_cp :: Float
    -- ^ Code phase of best point
  , _msgAcqResult_cf :: Float
    -- ^ Carrier frequency of best point
  , _msgAcqResult_sid :: GnssSignal
    -- ^ GNSS signal for which acquisition was attempted
  } deriving ( Show, Read, Eq )

instance Binary MsgAcqResult where
  get = do
    _msgAcqResult_snr <- getFloat32le
    _msgAcqResult_cp <- getFloat32le
    _msgAcqResult_cf <- getFloat32le
    _msgAcqResult_sid <- get
    return MsgAcqResult {..}

  put MsgAcqResult {..} = do
    putFloat32le _msgAcqResult_snr
    putFloat32le _msgAcqResult_cp
    putFloat32le _msgAcqResult_cf
    put _msgAcqResult_sid

$(deriveSBP 'msgAcqResult ''MsgAcqResult)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgAcqResult_" . stripPrefix "_msgAcqResult_"}
             ''MsgAcqResult)
$(makeLenses ''MsgAcqResult)

msgAcqResultDepA :: Word16
msgAcqResultDepA = 0x0015

-- | SBP class for message MSG_ACQ_RESULT_DEP_A (0x0015).
--
-- Deprecated.
data MsgAcqResultDepA = MsgAcqResultDepA
  { _msgAcqResultDepA_snr :: Float
    -- ^ SNR of best point. Currently dimensonless, but will have units of dB Hz
    -- in the revision of this message.
  , _msgAcqResultDepA_cp :: Float
    -- ^ Code phase of best point
  , _msgAcqResultDepA_cf :: Float
    -- ^ Carrier frequency of best point
  , _msgAcqResultDepA_prn :: Word8
    -- ^ PRN-1 identifier of the satellite signal for which acquisition was
    -- attempted
  } deriving ( Show, Read, Eq )

instance Binary MsgAcqResultDepA where
  get = do
    _msgAcqResultDepA_snr <- getFloat32le
    _msgAcqResultDepA_cp <- getFloat32le
    _msgAcqResultDepA_cf <- getFloat32le
    _msgAcqResultDepA_prn <- getWord8
    return MsgAcqResultDepA {..}

  put MsgAcqResultDepA {..} = do
    putFloat32le _msgAcqResultDepA_snr
    putFloat32le _msgAcqResultDepA_cp
    putFloat32le _msgAcqResultDepA_cf
    putWord8 _msgAcqResultDepA_prn

$(deriveSBP 'msgAcqResultDepA ''MsgAcqResultDepA)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgAcqResultDepA_" . stripPrefix "_msgAcqResultDepA_"}
             ''MsgAcqResultDepA)
$(makeLenses ''MsgAcqResultDepA)
