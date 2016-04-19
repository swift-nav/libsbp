{-# OPTIONS_GHC -fno-warn-unused-imports #-}
-- |
-- Module:      SwiftNav.SBP.System
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Standardized system messages from Swift Navigation devices.

module SwiftNav.SBP.System where

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

msgStartup :: Word16
msgStartup = 0xFF00

-- | SBP class for message MSG_STARTUP (0xFF00).
--
-- The system start-up message is sent once on system start-up. It notifies the
-- host or other attached devices that the system has started and is now ready
-- to respond to commands or configuration requests.
data MsgStartup = MsgStartup
  { _msgStartup_reserved :: Word32
    -- ^ Reserved
  } deriving ( Show, Read, Eq )

instance Binary MsgStartup where
  get = do
    _msgStartup_reserved <- getWord32le
    return MsgStartup {..}

  put MsgStartup {..} = do
    putWord32le _msgStartup_reserved

$(deriveSBP 'msgStartup ''MsgStartup)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgStartup_" . stripPrefix "_msgStartup_"}
             ''MsgStartup)
$(makeLenses ''MsgStartup)

msgHeartbeat :: Word16
msgHeartbeat = 0xFFFF

-- | SBP class for message MSG_HEARTBEAT (0xFFFF).
--
-- The heartbeat message is sent periodically to inform the host or other
-- attached devices that the system is running. It is used to monitor system
-- malfunctions. It also contains status flags that indicate to the host the
-- status of the system and whether it is operating correctly. Currently, the
-- expected heartbeat interval is 1 sec.  The system error flag is used to
-- indicate that an error has occurred in the system. To determine the source
-- of the error, the remaining error flags should be inspected.
data MsgHeartbeat = MsgHeartbeat
  { _msgHeartbeat_flags :: Word32
    -- ^ Status flags
  } deriving ( Show, Read, Eq )

instance Binary MsgHeartbeat where
  get = do
    _msgHeartbeat_flags <- getWord32le
    return MsgHeartbeat {..}

  put MsgHeartbeat {..} = do
    putWord32le _msgHeartbeat_flags

$(deriveSBP 'msgHeartbeat ''MsgHeartbeat)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgHeartbeat_" . stripPrefix "_msgHeartbeat_"}
             ''MsgHeartbeat)
$(makeLenses ''MsgHeartbeat)
