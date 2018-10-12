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
-- Linux state monitoring.

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
    -- ^ percent of cpu used
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
    _msgLinuxCpuState_tname <- decodeUtf8 <$> getByteString 32
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
