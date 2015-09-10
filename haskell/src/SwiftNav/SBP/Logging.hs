-- |
-- Module:      SwiftNav.SBP.Logging
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Logging and debugging messages from the device. These are in the
-- implementation-defined range (0x0000-0x00FF).

module SwiftNav.SBP.Logging where

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

msgLog :: Word16
msgLog = 0x0401

-- | SBP class for message MSG_LOG (0x0401).
--
-- This message contains a human-readable payload string from the device
-- containing errors, warnings and informational messages at ERROR, WARNING,
-- DEBUG, INFO logging levels.
data MsgLog = MsgLog
  { msgLogLevel :: Word8
    -- ^ Logging level
  , msgLogText  :: ByteString
    -- ^ Human-readable string
  } deriving ( Show, Read, Eq )

instance Binary MsgLog where
  get = do
    msgLogLevel <- getWord8
    msgLogText <- liftM toStrict getRemainingLazyByteString
    return MsgLog {..}

  put MsgLog {..} = do
    putWord8 msgLogLevel
    putByteString msgLogText

msgTweet :: Word16
msgTweet = 0x0012

-- | SBP class for message MSG_TWEET (0x0012).
--
-- All the news fit to tweet.
data MsgTweet = MsgTweet
  { msgTweetTweet :: ByteString
    -- ^ Human-readable string
  } deriving ( Show, Read, Eq )

instance Binary MsgTweet where
  get = do
    msgTweetTweet <- getByteString 140
    return MsgTweet {..}

  put MsgTweet {..} = do
    putByteString msgTweetTweet

msgPrintDep :: Word16
msgPrintDep = 0x0010

-- | SBP class for message MSG_PRINT_DEP (0x0010).
--
-- Deprecated.
data MsgPrintDep = MsgPrintDep
  { msgPrintDepText :: ByteString
    -- ^ Human-readable string
  } deriving ( Show, Read, Eq )

instance Binary MsgPrintDep where
  get = do
    msgPrintDepText <- liftM toStrict getRemainingLazyByteString
    return MsgPrintDep {..}

  put MsgPrintDep {..} = do
    putByteString msgPrintDepText
