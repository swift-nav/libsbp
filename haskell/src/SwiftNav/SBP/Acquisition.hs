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

msgAcqResult :: Word16
msgAcqResult = 0x0014

-- | SBP class for message MSG_ACQ_RESULT (0x0014).
--
-- This message describes the results from an attempted GPS signal acquisition
-- search for a satellite PRN over a code phase/carrier frequency range. It
-- contains the parameters of the point in the acquisition search space with
-- the best signal-to-noise (SNR) ratio.
data MsgAcqResult = MsgAcqResult
  { msgAcqResultSnr :: Float
    -- ^ SNR of best point. Currently dimensonless, but will have units of dB Hz
    -- in the revision of this message.
  , msgAcqResultCp  :: Float
    -- ^ Code phase of best point
  , msgAcqResultCf  :: Float
    -- ^ Carrier frequency of best point
  , msgAcqResultSid :: Word32
    -- ^ Signal identifier of the satellite signal for which acquisition was
    -- attempted - values 0x00 through 0x1F represent GPS PRNs 1 through 32
    -- respectively (PRN-1 notation); other values reserved for future use.
  } deriving ( Show, Read, Eq )

instance Binary MsgAcqResult where
  get = do
    msgAcqResultSnr <- getFloat32le
    msgAcqResultCp <- getFloat32le
    msgAcqResultCf <- getFloat32le
    msgAcqResultSid <- getWord32le
    return MsgAcqResult {..}

  put MsgAcqResult {..} = do
    putFloat32le msgAcqResultSnr
    putFloat32le msgAcqResultCp
    putFloat32le msgAcqResultCf
    putWord32le msgAcqResultSid

msgAcqResultDepA :: Word16
msgAcqResultDepA = 0x0015

-- | SBP class for message MSG_ACQ_RESULT_DEP_A (0x0015).
--
-- Deprecated.
data MsgAcqResultDepA = MsgAcqResultDepA
  { msgAcqResultDepASnr :: Float
    -- ^ SNR of best point. Currently dimensonless, but will have units of dB Hz
    -- in the revision of this message.
  , msgAcqResultDepACp  :: Float
    -- ^ Code phase of best point
  , msgAcqResultDepACf  :: Float
    -- ^ Carrier frequency of best point
  , msgAcqResultDepAPrn :: Word8
    -- ^ PRN-1 identifier of the satellite signal for which acquisition was
    -- attempted
  } deriving ( Show, Read, Eq )

instance Binary MsgAcqResultDepA where
  get = do
    msgAcqResultDepASnr <- getFloat32le
    msgAcqResultDepACp <- getFloat32le
    msgAcqResultDepACf <- getFloat32le
    msgAcqResultDepAPrn <- getWord8
    return MsgAcqResultDepA {..}

  put MsgAcqResultDepA {..} = do
    putFloat32le msgAcqResultDepASnr
    putFloat32le msgAcqResultDepACp
    putFloat32le msgAcqResultDepACf
    putWord8 msgAcqResultDepAPrn
