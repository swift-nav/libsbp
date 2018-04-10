{-# LANGUAGE NoImplicitPrelude #-}
{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE TemplateHaskell   #-}

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

import BasicPrelude                 hiding (lines, map, mapMaybe)
import Control.Monad.Trans.Resource
import Data.Aeson
import Data.Aeson.TH
import Data.ByteString.Lazy         hiding (ByteString, drop, map)
import Data.Conduit
import Data.Conduit.Binary          hiding (drop)
import Data.Conduit.List            hiding (drop)
import Data.Time
import SwiftNav.SBP
import System.IO

data Data = Data
  { _data :: SBPMsg
  , _time :: UTCTime
  } deriving Show

deriveJSON defaultOptions { fieldLabelModifier = drop 1 } ''Data

-- | Encode a SBPMsg to a line of JSON.
encodeLine :: Data -> ByteString
encodeLine v = toStrict $ encode v <> "\n"

main :: IO ()
main =
  runResourceT $
    sourceHandle stdin
      =$= lines
      =$= mapMaybe decodeStrict
      =$= map encodeLine
      $$  sinkHandle stdout
