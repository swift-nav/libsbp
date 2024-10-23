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
    -- ^ Total time spent in measurement point (microseconds)
  , _msgMeasurementPoint_num_executions :: !Word16
    -- ^ Number of times measurement point has executed
  , _msgMeasurementPoint_min          :: !Word32
    -- ^ Minimum execution time (microseconds)
  , _msgMeasurementPoint_max          :: !Word32
    -- ^ Maximum execution time (microseconds)
  , _msgMeasurementPoint_return_addr  :: !Word64
    -- ^ Return address
  , _msgMeasurementPoint_id           :: !Word64
    -- ^ Unique ID
  , _msgMeasurementPoint_slice_time   :: !Word64
    -- ^ CPU slice time (milliseconds)
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

msgProfilingSystemInfo :: Word16
msgProfilingSystemInfo = 0xCF01

-- | SBP class for message MSG_PROFILING_SYSTEM_INFO (0xCF01).
--
-- Contains basic information about system resource usage. System is defined
-- in terms of the source of this message and may vary from  sender to sender.
-- Refer to product documentation to understand the exact scope and meaning of
-- this message.
data MsgProfilingSystemInfo = MsgProfilingSystemInfo
  { _msgProfilingSystemInfo_total_cpu_time :: !Word64
    -- ^ Total cpu time in microseconds consumed by this system
  , _msgProfilingSystemInfo_age          :: !Word64
    -- ^ Age of the producing system in microseconds
  , _msgProfilingSystemInfo_n_threads    :: !Word8
    -- ^ Number of threads being tracked by this system
  , _msgProfilingSystemInfo_heap_usage   :: !Word32
    -- ^ Number of bytes allocated on the heap
  } deriving ( Show, Read, Eq )

instance Binary MsgProfilingSystemInfo where
  get = do
    _msgProfilingSystemInfo_total_cpu_time <- getWord64le
    _msgProfilingSystemInfo_age <- getWord64le
    _msgProfilingSystemInfo_n_threads <- getWord8
    _msgProfilingSystemInfo_heap_usage <- getWord32le
    pure MsgProfilingSystemInfo {..}

  put MsgProfilingSystemInfo {..} = do
    putWord64le _msgProfilingSystemInfo_total_cpu_time
    putWord64le _msgProfilingSystemInfo_age
    putWord8 _msgProfilingSystemInfo_n_threads
    putWord32le _msgProfilingSystemInfo_heap_usage

$(makeSBP 'msgProfilingSystemInfo ''MsgProfilingSystemInfo)
$(makeJSON "_msgProfilingSystemInfo_" ''MsgProfilingSystemInfo)
$(makeLenses ''MsgProfilingSystemInfo)

msgProfilingThreadInfo :: Word16
msgProfilingThreadInfo = 0xCF02

-- | SBP class for message MSG_PROFILING_THREAD_INFO (0xCF02).
--
-- Contains profiling information related to a single thread being tracked by
-- the producing system. Refer to product documentation to understand the
-- exact scope and meaning of this message.
data MsgProfilingThreadInfo = MsgProfilingThreadInfo
  { _msgProfilingThreadInfo_total_cpu_time :: !Word64
    -- ^ Total cpu time in microseconds consumed by this thread
  , _msgProfilingThreadInfo_age          :: !Word64
    -- ^ Age of the thread in microseconds
  , _msgProfilingThreadInfo_state        :: !Word8
    -- ^ Thread state
  , _msgProfilingThreadInfo_stack_size   :: !Word32
    -- ^ Stack size in bytes
  , _msgProfilingThreadInfo_stack_usage  :: !Word32
    -- ^ Stack high water usage in bytes
  , _msgProfilingThreadInfo_name         :: !Text
    -- ^ Thread name
  } deriving ( Show, Read, Eq )

instance Binary MsgProfilingThreadInfo where
  get = do
    _msgProfilingThreadInfo_total_cpu_time <- getWord64le
    _msgProfilingThreadInfo_age <- getWord64le
    _msgProfilingThreadInfo_state <- getWord8
    _msgProfilingThreadInfo_stack_size <- getWord32le
    _msgProfilingThreadInfo_stack_usage <- getWord32le
    _msgProfilingThreadInfo_name <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgProfilingThreadInfo {..}

  put MsgProfilingThreadInfo {..} = do
    putWord64le _msgProfilingThreadInfo_total_cpu_time
    putWord64le _msgProfilingThreadInfo_age
    putWord8 _msgProfilingThreadInfo_state
    putWord32le _msgProfilingThreadInfo_stack_size
    putWord32le _msgProfilingThreadInfo_stack_usage
    putByteString $ encodeUtf8 _msgProfilingThreadInfo_name

$(makeSBP 'msgProfilingThreadInfo ''MsgProfilingThreadInfo)
$(makeJSON "_msgProfilingThreadInfo_" ''MsgProfilingThreadInfo)
$(makeLenses ''MsgProfilingThreadInfo)

-- | ResourceBucket.
--
-- Information about allocation of various resources grouped by buckets. Refer
-- to product documentation to understand the meaning and values in this
-- message.
data ResourceBucket = ResourceBucket
  { _resourceBucket_name           :: !Text
    -- ^ Bucket name
  , _resourceBucket_thread         :: !Word8
    -- ^ Number of threads
  , _resourceBucket_mutex          :: !Word8
    -- ^ Number of mutexes
  , _resourceBucket_cv             :: !Word8
    -- ^ Number of condition variables
  , _resourceBucket_io             :: !Word8
    -- ^ Number of IO handles
  , _resourceBucket_heap_bytes_alloc :: !Word32
    -- ^ Number of bytes allocated on the heap
  , _resourceBucket_heap_bytes_free :: !Word32
    -- ^ Number of bytes freed on the heap
  , _resourceBucket_io_write       :: !Word32
    -- ^ Number of bytes written to IO handles
  , _resourceBucket_io_read        :: !Word32
    -- ^ Number of bytes read from IO handles
  } deriving ( Show, Read, Eq )

instance Binary ResourceBucket where
  get = do
    _resourceBucket_name <- decodeUtf8 <$> getByteString 21
    _resourceBucket_thread <- getWord8
    _resourceBucket_mutex <- getWord8
    _resourceBucket_cv <- getWord8
    _resourceBucket_io <- getWord8
    _resourceBucket_heap_bytes_alloc <- getWord32le
    _resourceBucket_heap_bytes_free <- getWord32le
    _resourceBucket_io_write <- getWord32le
    _resourceBucket_io_read <- getWord32le
    pure ResourceBucket {..}

  put ResourceBucket {..} = do
    putByteString $ encodeUtf8 _resourceBucket_name
    putWord8 _resourceBucket_thread
    putWord8 _resourceBucket_mutex
    putWord8 _resourceBucket_cv
    putWord8 _resourceBucket_io
    putWord32le _resourceBucket_heap_bytes_alloc
    putWord32le _resourceBucket_heap_bytes_free
    putWord32le _resourceBucket_io_write
    putWord32le _resourceBucket_io_read

$(makeJSON "_resourceBucket_" ''ResourceBucket)
$(makeLenses ''ResourceBucket)

msgProfilingResourceCounter :: Word16
msgProfilingResourceCounter = 0xCF03

-- | SBP class for message MSG_PROFILING_RESOURCE_COUNTER (0xCF03).
--
-- Information about resource buckets. Refer to product documentation to
-- understand the meaning and values in this message.
data MsgProfilingResourceCounter = MsgProfilingResourceCounter
  { _msgProfilingResourceCounter_seq_no :: !Word8
    -- ^ Message number in complete sequence
  , _msgProfilingResourceCounter_seq_len :: !Word8
    -- ^ Length of message sequence
  , _msgProfilingResourceCounter_buckets :: ![ResourceBucket]
    -- ^ List of resource buckets
  } deriving ( Show, Read, Eq )

instance Binary MsgProfilingResourceCounter where
  get = do
    _msgProfilingResourceCounter_seq_no <- getWord8
    _msgProfilingResourceCounter_seq_len <- getWord8
    _msgProfilingResourceCounter_buckets <- whileM (not <$> isEmpty) get
    pure MsgProfilingResourceCounter {..}

  put MsgProfilingResourceCounter {..} = do
    putWord8 _msgProfilingResourceCounter_seq_no
    putWord8 _msgProfilingResourceCounter_seq_len
    mapM_ put _msgProfilingResourceCounter_buckets

$(makeSBP 'msgProfilingResourceCounter ''MsgProfilingResourceCounter)
$(makeJSON "_msgProfilingResourceCounter_" ''MsgProfilingResourceCounter)
$(makeLenses ''MsgProfilingResourceCounter)

