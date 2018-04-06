{-# LANGUAGE NoImplicitPrelude #-}
{-# LANGUAGE OverloadedStrings #-}

-- |
-- Module:      JSON2JSON
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- JSON to JSON tool - reads SBP JSON from stdin and sends SBP JSON to
-- stdout.

import BasicPrelude                      hiding (lines, map, mapMaybe)
import Control.Monad.Trans.Resource
import Data.Aeson
import Data.Conduit
import Data.Conduit.Binary
import Data.Conduit.List
import Data.ByteString.Lazy              hiding (ByteString, map)
import Data.Time
import SwiftNav.SBP
import System.IO

data SBPMsgData = SBPMsgData
  { sbpMsgData :: SBPMsg
  , sbpMsgTime :: UTCTime
  } deriving ( Show, Read, Eq )

instance FromJSON SBPMsgData where
  parseJSON (Object v) = SBPMsgData <$> v .: "data" <*> v .: "time"
  parseJSON _ = mzero

instance ToJSON SBPMsgData where
  toJSON d = object [ "data" .= sbpMsgData d, "time" .= sbpMsgTime d ]

-- | Encode a SBPMsg to a line of JSON.
encodeLine :: SBPMsgData -> ByteString
encodeLine v = toStrict $ encode v <> "\n"

main :: IO ()
main =
  runResourceT $
    sourceHandle stdin
      =$= lines
      =$= mapMaybe decodeStrict
      =$= map encodeLine
      $$  sinkHandle stdout
