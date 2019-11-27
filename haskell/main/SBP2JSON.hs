{-# LANGUAGE NoImplicitPrelude #-}
{-# LANGUAGE OverloadedStrings #-}

-- |
-- Module:      SBP2JSON
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- SBP to JSON tool - reads SBP binary from stdin and sends SBP JSON
-- to stdout.

import BasicPrelude                      hiding (map)
import Control.Monad.Trans.Resource
import Data.Aeson
import Data.ByteString.Lazy              hiding (ByteString, map)
import Data.Conduit
import Data.Conduit.Binary
import Data.Conduit.List
import Data.Conduit.Serialization.Binary
import SwiftNav.SBP
import System.IO

-- | Encode a SBPMsg to a line of JSON.
encodeLine :: SBPMsg -> ByteString
encodeLine v = toStrict $ encode v <> "\n"

main :: IO ()
main = do
  hSetBuffering stdin NoBuffering
  hSetBuffering stdout NoBuffering
  runResourceT $
    sourceHandle stdin
      =$= conduitDecode
      =$= map encodeLine
      $$  sinkHandle stdout
