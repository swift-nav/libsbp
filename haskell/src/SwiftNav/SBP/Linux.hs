{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Linux
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- \<Linux state monitoring. \>

module SwiftNav.SBP.Linux
  ( module SwiftNav.SBP.Linux
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


msgLinuxCpuState :: Word16
msgLinuxCpuState = 0x7F00

-- | SBP class for message MSG_LINUX_CPU_STATE (0x7F00).
--
-- This message indicates the process state of the top 10 heaviest consumers of
-- CPU on the system.
data MsgLinuxCpuState = MsgLinuxCpuState
  { _msgLinuxCpuState_index :: !Word8
    -- ^ sequence of this status message, values from 0-9
  , _msgLinuxCpuState_pid   :: !Word16
    -- ^ the PID of the process
  , _msgLinuxCpuState_pcpu  :: !Word8
    -- ^ percent of cpu used, expressed as a fraction of 256
  , _msgLinuxCpuState_tname :: !Text
    -- ^ fixed length string representing the thread name
  , _msgLinuxCpuState_cmdline :: !Text
    -- ^ the command line (as much as it fits in the remaining packet)
  } deriving ( Show, Read, Eq )

instance Binary MsgLinuxCpuState where
  get = do
    _msgLinuxCpuState_index <- getWord8
    _msgLinuxCpuState_pid <- getWord16le
    _msgLinuxCpuState_pcpu <- getWord8
    _msgLinuxCpuState_tname <- decodeUtf8 <$> getByteString 15
    _msgLinuxCpuState_cmdline <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgLinuxCpuState {..}

  put MsgLinuxCpuState {..} = do
    putWord8 _msgLinuxCpuState_index
    putWord16le _msgLinuxCpuState_pid
    putWord8 _msgLinuxCpuState_pcpu
    putByteString $ encodeUtf8 _msgLinuxCpuState_tname
    putByteString $ encodeUtf8 _msgLinuxCpuState_cmdline

$(makeSBP 'msgLinuxCpuState ''MsgLinuxCpuState)
$(makeJSON "_msgLinuxCpuState_" ''MsgLinuxCpuState)
$(makeLenses ''MsgLinuxCpuState)

msgLinuxMemState :: Word16
msgLinuxMemState = 0x7F01

-- | SBP class for message MSG_LINUX_MEM_STATE (0x7F01).
--
-- This message indicates the process state of the top 10 heaviest consumers of
-- memory on the system.
data MsgLinuxMemState = MsgLinuxMemState
  { _msgLinuxMemState_index :: !Word8
    -- ^ sequence of this status message, values from 0-9
  , _msgLinuxMemState_pid   :: !Word16
    -- ^ the PID of the process
  , _msgLinuxMemState_pmem  :: !Word8
    -- ^ percent of memory used, expressed as a fraction of 256
  , _msgLinuxMemState_tname :: !Text
    -- ^ fixed length string representing the thread name
  , _msgLinuxMemState_cmdline :: !Text
    -- ^ the command line (as much as it fits in the remaining packet)
  } deriving ( Show, Read, Eq )

instance Binary MsgLinuxMemState where
  get = do
    _msgLinuxMemState_index <- getWord8
    _msgLinuxMemState_pid <- getWord16le
    _msgLinuxMemState_pmem <- getWord8
    _msgLinuxMemState_tname <- decodeUtf8 <$> getByteString 15
    _msgLinuxMemState_cmdline <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgLinuxMemState {..}

  put MsgLinuxMemState {..} = do
    putWord8 _msgLinuxMemState_index
    putWord16le _msgLinuxMemState_pid
    putWord8 _msgLinuxMemState_pmem
    putByteString $ encodeUtf8 _msgLinuxMemState_tname
    putByteString $ encodeUtf8 _msgLinuxMemState_cmdline

$(makeSBP 'msgLinuxMemState ''MsgLinuxMemState)
$(makeJSON "_msgLinuxMemState_" ''MsgLinuxMemState)
$(makeLenses ''MsgLinuxMemState)

msgLinuxSysState :: Word16
msgLinuxSysState = 0x7F02

-- | SBP class for message MSG_LINUX_SYS_STATE (0x7F02).
--
-- This presents a summary of CPU and memory utilization.
data MsgLinuxSysState = MsgLinuxSysState
  { _msgLinuxSysState_mem_total    :: !Word16
    -- ^ total system memory
  , _msgLinuxSysState_pcpu         :: !Word8
    -- ^ percent of total cpu currently utilized
  , _msgLinuxSysState_pmem         :: !Word8
    -- ^ percent of total memory currently utilized
  , _msgLinuxSysState_procs_starting :: !Word16
    -- ^ number of processes that started during collection phase
  , _msgLinuxSysState_procs_stopping :: !Word16
    -- ^ number of processes that stopped during collection phase
  , _msgLinuxSysState_pid_count    :: !Word16
    -- ^ the count of processes on the system
  } deriving ( Show, Read, Eq )

instance Binary MsgLinuxSysState where
  get = do
    _msgLinuxSysState_mem_total <- getWord16le
    _msgLinuxSysState_pcpu <- getWord8
    _msgLinuxSysState_pmem <- getWord8
    _msgLinuxSysState_procs_starting <- getWord16le
    _msgLinuxSysState_procs_stopping <- getWord16le
    _msgLinuxSysState_pid_count <- getWord16le
    pure MsgLinuxSysState {..}

  put MsgLinuxSysState {..} = do
    putWord16le _msgLinuxSysState_mem_total
    putWord8 _msgLinuxSysState_pcpu
    putWord8 _msgLinuxSysState_pmem
    putWord16le _msgLinuxSysState_procs_starting
    putWord16le _msgLinuxSysState_procs_stopping
    putWord16le _msgLinuxSysState_pid_count

$(makeSBP 'msgLinuxSysState ''MsgLinuxSysState)
$(makeJSON "_msgLinuxSysState_" ''MsgLinuxSysState)
$(makeLenses ''MsgLinuxSysState)

msgLinuxProcessSocketCounts :: Word16
msgLinuxProcessSocketCounts = 0x7F03

-- | SBP class for message MSG_LINUX_PROCESS_SOCKET_COUNTS (0x7F03).
--
-- Top 10 list of processes with high socket counts.
data MsgLinuxProcessSocketCounts = MsgLinuxProcessSocketCounts
  { _msgLinuxProcessSocketCounts_index       :: !Word8
    -- ^ sequence of this status message, values from 0-9
  , _msgLinuxProcessSocketCounts_pid         :: !Word16
    -- ^ the PID of the process in question
  , _msgLinuxProcessSocketCounts_socket_count :: !Word16
    -- ^ the number of sockets the process is using
  , _msgLinuxProcessSocketCounts_socket_types :: !Word16
    -- ^ A bitfield indicating the socket types used:   0x1 (tcp), 0x2 (udp), 0x4
    -- (unix stream), 0x8 (unix dgram), 0x10 (netlink),   and 0x8000 (unknown)
  , _msgLinuxProcessSocketCounts_socket_states :: !Word16
    -- ^ A bitfield indicating the socket states:   0x1 (established), 0x2 (syn-
    -- sent), 0x4 (syn-recv), 0x8 (fin-wait-1),   0x10 (fin-wait-2), 0x20
    -- (time-wait), 0x40 (closed), 0x80 (close-wait),   0x100 (last-ack), 0x200
    -- (listen), 0x400 (closing), 0x800 (unconnected),   and 0x8000 (unknown)
  , _msgLinuxProcessSocketCounts_cmdline     :: !Text
    -- ^ the command line of the process in question
  } deriving ( Show, Read, Eq )

instance Binary MsgLinuxProcessSocketCounts where
  get = do
    _msgLinuxProcessSocketCounts_index <- getWord8
    _msgLinuxProcessSocketCounts_pid <- getWord16le
    _msgLinuxProcessSocketCounts_socket_count <- getWord16le
    _msgLinuxProcessSocketCounts_socket_types <- getWord16le
    _msgLinuxProcessSocketCounts_socket_states <- getWord16le
    _msgLinuxProcessSocketCounts_cmdline <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgLinuxProcessSocketCounts {..}

  put MsgLinuxProcessSocketCounts {..} = do
    putWord8 _msgLinuxProcessSocketCounts_index
    putWord16le _msgLinuxProcessSocketCounts_pid
    putWord16le _msgLinuxProcessSocketCounts_socket_count
    putWord16le _msgLinuxProcessSocketCounts_socket_types
    putWord16le _msgLinuxProcessSocketCounts_socket_states
    putByteString $ encodeUtf8 _msgLinuxProcessSocketCounts_cmdline

$(makeSBP 'msgLinuxProcessSocketCounts ''MsgLinuxProcessSocketCounts)
$(makeJSON "_msgLinuxProcessSocketCounts_" ''MsgLinuxProcessSocketCounts)
$(makeLenses ''MsgLinuxProcessSocketCounts)

msgLinuxProcessSocketQueues :: Word16
msgLinuxProcessSocketQueues = 0x7F04

-- | SBP class for message MSG_LINUX_PROCESS_SOCKET_QUEUES (0x7F04).
--
-- Top 10 list of sockets with deep queues.
data MsgLinuxProcessSocketQueues = MsgLinuxProcessSocketQueues
  { _msgLinuxProcessSocketQueues_index            :: !Word8
    -- ^ sequence of this status message, values from 0-9
  , _msgLinuxProcessSocketQueues_pid              :: !Word16
    -- ^ the PID of the process in question
  , _msgLinuxProcessSocketQueues_recv_queued      :: !Word16
    -- ^ the total amount of receive data queued for this process
  , _msgLinuxProcessSocketQueues_send_queued      :: !Word16
    -- ^ the total amount of send data queued for this process
  , _msgLinuxProcessSocketQueues_socket_types     :: !Word16
    -- ^ A bitfield indicating the socket types used:   0x1 (tcp), 0x2 (udp), 0x4
    -- (unix stream), 0x8 (unix dgram), 0x10 (netlink),   and 0x8000 (unknown)
  , _msgLinuxProcessSocketQueues_socket_states    :: !Word16
    -- ^ A bitfield indicating the socket states:   0x1 (established), 0x2 (syn-
    -- sent), 0x4 (syn-recv), 0x8 (fin-wait-1),   0x10 (fin-wait-2), 0x20
    -- (time-wait), 0x40 (closed), 0x80 (close-wait),   0x100 (last-ack), 0x200
    -- (listen), 0x400 (closing), 0x800 (unconnected),   and 0x8000 (unknown)
  , _msgLinuxProcessSocketQueues_address_of_largest :: !Text
    -- ^ Address of the largest queue, remote or local depending on the
    -- directionality of the connection.
  , _msgLinuxProcessSocketQueues_cmdline          :: !Text
    -- ^ the command line of the process in question
  } deriving ( Show, Read, Eq )

instance Binary MsgLinuxProcessSocketQueues where
  get = do
    _msgLinuxProcessSocketQueues_index <- getWord8
    _msgLinuxProcessSocketQueues_pid <- getWord16le
    _msgLinuxProcessSocketQueues_recv_queued <- getWord16le
    _msgLinuxProcessSocketQueues_send_queued <- getWord16le
    _msgLinuxProcessSocketQueues_socket_types <- getWord16le
    _msgLinuxProcessSocketQueues_socket_states <- getWord16le
    _msgLinuxProcessSocketQueues_address_of_largest <- decodeUtf8 <$> getByteString 64
    _msgLinuxProcessSocketQueues_cmdline <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgLinuxProcessSocketQueues {..}

  put MsgLinuxProcessSocketQueues {..} = do
    putWord8 _msgLinuxProcessSocketQueues_index
    putWord16le _msgLinuxProcessSocketQueues_pid
    putWord16le _msgLinuxProcessSocketQueues_recv_queued
    putWord16le _msgLinuxProcessSocketQueues_send_queued
    putWord16le _msgLinuxProcessSocketQueues_socket_types
    putWord16le _msgLinuxProcessSocketQueues_socket_states
    putByteString $ encodeUtf8 _msgLinuxProcessSocketQueues_address_of_largest
    putByteString $ encodeUtf8 _msgLinuxProcessSocketQueues_cmdline

$(makeSBP 'msgLinuxProcessSocketQueues ''MsgLinuxProcessSocketQueues)
$(makeJSON "_msgLinuxProcessSocketQueues_" ''MsgLinuxProcessSocketQueues)
$(makeLenses ''MsgLinuxProcessSocketQueues)

msgLinuxSocketUsage :: Word16
msgLinuxSocketUsage = 0x7F05

-- | SBP class for message MSG_LINUX_SOCKET_USAGE (0x7F05).
--
-- Summaries the socket usage across the system.
data MsgLinuxSocketUsage = MsgLinuxSocketUsage
  { _msgLinuxSocketUsage_avg_queue_depth   :: !Word32
    -- ^ average socket queue depths across all sockets on the system
  , _msgLinuxSocketUsage_max_queue_depth   :: !Word32
    -- ^ the max queue depth seen within the reporting period
  , _msgLinuxSocketUsage_socket_state_counts :: ![Word16]
    -- ^ A count for each socket type reported in the `socket_types_reported`
    -- field, the first entry corresponds to the first enabled bit in
    -- `types_reported`.
  , _msgLinuxSocketUsage_socket_type_counts :: ![Word16]
    -- ^ A count for each socket type reported in the `socket_types_reported`
    -- field, the first entry corresponds to the first enabled bit in
    -- `types_reported`.
  } deriving ( Show, Read, Eq )

instance Binary MsgLinuxSocketUsage where
  get = do
    _msgLinuxSocketUsage_avg_queue_depth <- getWord32le
    _msgLinuxSocketUsage_max_queue_depth <- getWord32le
    _msgLinuxSocketUsage_socket_state_counts <- replicateM 16 getWord16le
    _msgLinuxSocketUsage_socket_type_counts <- replicateM 16 getWord16le
    pure MsgLinuxSocketUsage {..}

  put MsgLinuxSocketUsage {..} = do
    putWord32le _msgLinuxSocketUsage_avg_queue_depth
    putWord32le _msgLinuxSocketUsage_max_queue_depth
    mapM_ putWord16le _msgLinuxSocketUsage_socket_state_counts
    mapM_ putWord16le _msgLinuxSocketUsage_socket_type_counts

$(makeSBP 'msgLinuxSocketUsage ''MsgLinuxSocketUsage)
$(makeJSON "_msgLinuxSocketUsage_" ''MsgLinuxSocketUsage)
$(makeLenses ''MsgLinuxSocketUsage)

msgLinuxProcessFdCount :: Word16
msgLinuxProcessFdCount = 0x7F06

-- | SBP class for message MSG_LINUX_PROCESS_FD_COUNT (0x7F06).
--
-- Top 10 list of processes with a large number of open file descriptors.
data MsgLinuxProcessFdCount = MsgLinuxProcessFdCount
  { _msgLinuxProcessFdCount_index  :: !Word8
    -- ^ sequence of this status message, values from 0-9
  , _msgLinuxProcessFdCount_pid    :: !Word16
    -- ^ the PID of the process in question
  , _msgLinuxProcessFdCount_fd_count :: !Word16
    -- ^ a count of the number of file descriptors opened by the process
  , _msgLinuxProcessFdCount_cmdline :: !Text
    -- ^ the command line of the process in question
  } deriving ( Show, Read, Eq )

instance Binary MsgLinuxProcessFdCount where
  get = do
    _msgLinuxProcessFdCount_index <- getWord8
    _msgLinuxProcessFdCount_pid <- getWord16le
    _msgLinuxProcessFdCount_fd_count <- getWord16le
    _msgLinuxProcessFdCount_cmdline <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgLinuxProcessFdCount {..}

  put MsgLinuxProcessFdCount {..} = do
    putWord8 _msgLinuxProcessFdCount_index
    putWord16le _msgLinuxProcessFdCount_pid
    putWord16le _msgLinuxProcessFdCount_fd_count
    putByteString $ encodeUtf8 _msgLinuxProcessFdCount_cmdline

$(makeSBP 'msgLinuxProcessFdCount ''MsgLinuxProcessFdCount)
$(makeJSON "_msgLinuxProcessFdCount_" ''MsgLinuxProcessFdCount)
$(makeLenses ''MsgLinuxProcessFdCount)

msgLinuxProcessFdSummary :: Word16
msgLinuxProcessFdSummary = 0x7F07

-- | SBP class for message MSG_LINUX_PROCESS_FD_SUMMARY (0x7F07).
--
-- Summary of open file descriptors on the system.
data MsgLinuxProcessFdSummary = MsgLinuxProcessFdSummary
  { _msgLinuxProcessFdSummary_sys_fd_count :: !Word32
    -- ^ count of total FDs open on the system
  , _msgLinuxProcessFdSummary_most_opened :: !Text
    -- ^ A null delimited list of strings which alternates between a string
    -- representation of the process count and the file name whose count it
    -- being reported.  That is, in C string syntax
    -- "32\0/var/log/syslog\012\0/tmp/foo\0" with the end of the list being 2
    -- NULL terminators in a row.
  } deriving ( Show, Read, Eq )

instance Binary MsgLinuxProcessFdSummary where
  get = do
    _msgLinuxProcessFdSummary_sys_fd_count <- getWord32le
    _msgLinuxProcessFdSummary_most_opened <- decodeUtf8 . toStrict <$> getRemainingLazyByteString
    pure MsgLinuxProcessFdSummary {..}

  put MsgLinuxProcessFdSummary {..} = do
    putWord32le _msgLinuxProcessFdSummary_sys_fd_count
    putByteString $ encodeUtf8 _msgLinuxProcessFdSummary_most_opened

$(makeSBP 'msgLinuxProcessFdSummary ''MsgLinuxProcessFdSummary)
$(makeJSON "_msgLinuxProcessFdSummary_" ''MsgLinuxProcessFdSummary)
$(makeLenses ''MsgLinuxProcessFdSummary)
