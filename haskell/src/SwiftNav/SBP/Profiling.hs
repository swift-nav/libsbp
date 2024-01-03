{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Profiling
-- Copyright:   Copyright (C) 2015-2021 Swift Navigation, Inc.
-- License:     MIT
-- Contact:     https://support.swiftnav.com
-- Stability:   experimental
-- Portability: portable
--
-- \< Standardized profiling messages from Swift Navigation devices. \>

module SwiftNav.SBP.Profiling
  ( module SwiftNav.SBP.Profiling
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

{-# ANN module ("HLint: ignore Use camelCase"::String) #-}
{-# ANN module ("HLint: ignore Redundant do"::String) #-}
{-# ANN module ("HLint: ignore Use newtype instead of data"::String) #-}


msgMeasurementPoint :: Word16
msgMeasurementPoint = 0xCF00

-- | SBP class for message MSG_MEASUREMENT_POINT (0xCF00).
--
-- Tracks execution time of certain code paths in specially built products.
-- This message should only be expected and processed on the direction of
-- Swift's engineering teams.
data MsgMeasurementPoint = MsgMeasurementPoint
  { _msgMeasurementPoint_total_time   :: !Word32
    -- ^ Total time spent in measurement point
  , _msgMeasurementPoint_num_executions :: !Word16
    -- ^ Number of times measurement point has executed
  , _msgMeasurementPoint_min          :: !Word32
    -- ^ Minimum execution time
  , _msgMeasurementPoint_max          :: !Word32
    -- ^ Maximum execution time
  , _msgMeasurementPoint_return_addr  :: !Word64
    -- ^ Return address
  , _msgMeasurementPoint_id           :: !Word64
    -- ^ Unique ID
  , _msgMeasurementPoint_slice_time   :: !Word64
    -- ^ CPU slice time
  , _msgMeasurementPoint_line         :: !Word16
    -- ^ Line number
  , _msgMeasurementPoint_func         :: !Text
    -- ^ Function name
  } deriving ( Show, Read, Eq )

instance Binary MsgMeasurementPoint where
  get = do
    _msgMeasurementPoint_total_time <- getWord32le
    _msgMeasurementPoint_num_executions <- getWord16le
    _msgMeasurementPoint_min <- getWord32le
    _msgMeasurementPoint_max <- getWord32le
    _msgMeasurementPoint_return_addr <- getWord64le
    _msgMeasurementPoint_id <- getWord64le
    _msgMeasurementPoint_slice_time <- getWord64le
    _msgMeasurementPoint_line <- getWord16le
    _msgMeasurementPoint_func <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgMeasurementPoint {..}

  put MsgMeasurementPoint {..} = do
    putWord32le _msgMeasurementPoint_total_time
    putWord16le _msgMeasurementPoint_num_executions
    putWord32le _msgMeasurementPoint_min
    putWord32le _msgMeasurementPoint_max
    putWord64le _msgMeasurementPoint_return_addr
    putWord64le _msgMeasurementPoint_id
    putWord64le _msgMeasurementPoint_slice_time
    putWord16le _msgMeasurementPoint_line
    putByteString $ encodeUtf8 _msgMeasurementPoint_func

$(makeSBP 'msgMeasurementPoint ''MsgMeasurementPoint)
$(makeJSON "_msgMeasurementPoint_" ''MsgMeasurementPoint)
$(makeLenses ''MsgMeasurementPoint)
