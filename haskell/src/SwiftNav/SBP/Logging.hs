{-# OPTIONS_GHC -fno-warn-unused-imports #-}
-- |
-- Module:      SwiftNav.SBP.Logging
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Logging and debugging messages from the device.

module SwiftNav.SBP.Logging where

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

msgLog :: Word16
msgLog = 0x0401

-- | SBP class for message MSG_LOG (0x0401).
--
-- This message contains a human-readable payload string from the device
-- containing errors, warnings and informational messages at ERROR, WARNING,
-- DEBUG, INFO logging levels.
data MsgLog = MsgLog
  { _msgLog_level :: Word8
    -- ^ Logging level
  , _msgLog_text :: ByteString
    -- ^ Human-readable string
  } deriving ( Show, Read, Eq )

instance Binary MsgLog where
  get = do
    _msgLog_level <- getWord8
    _msgLog_text <- liftM toStrict getRemainingLazyByteString
    return MsgLog {..}

  put MsgLog {..} = do
    putWord8 _msgLog_level
    putByteString _msgLog_text

$(deriveSBP 'msgLog ''MsgLog)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgLog_" . stripPrefix "_msgLog_"}
             ''MsgLog)
$(makeLenses ''MsgLog)

msgTweet :: Word16
msgTweet = 0x0012

-- | SBP class for message MSG_TWEET (0x0012).
--
-- All the news fit to tweet.
data MsgTweet = MsgTweet
  { _msgTweet_tweet :: ByteString
    -- ^ Human-readable string
  } deriving ( Show, Read, Eq )

instance Binary MsgTweet where
  get = do
    _msgTweet_tweet <- getByteString 140
    return MsgTweet {..}

  put MsgTweet {..} = do
    putByteString _msgTweet_tweet

$(deriveSBP 'msgTweet ''MsgTweet)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgTweet_" . stripPrefix "_msgTweet_"}
             ''MsgTweet)
$(makeLenses ''MsgTweet)

msgPrintDep :: Word16
msgPrintDep = 0x0010

-- | SBP class for message MSG_PRINT_DEP (0x0010).
--
-- Deprecated.
data MsgPrintDep = MsgPrintDep
  { _msgPrintDep_text :: ByteString
    -- ^ Human-readable string
  } deriving ( Show, Read, Eq )

instance Binary MsgPrintDep where
  get = do
    _msgPrintDep_text <- liftM toStrict getRemainingLazyByteString
    return MsgPrintDep {..}

  put MsgPrintDep {..} = do
    putByteString _msgPrintDep_text

$(deriveSBP 'msgPrintDep ''MsgPrintDep)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgPrintDep_" . stripPrefix "_msgPrintDep_"}
             ''MsgPrintDep)
$(makeLenses ''MsgPrintDep)
