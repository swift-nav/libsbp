{-# LANGUAGE NoImplicitPrelude #-}

-- |
-- Module:      SBP2YAML
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- SBP to YAML tool - reads SBP binary from stdin and sends SBP YAML
-- to stdout.

import BasicPrelude                      hiding (map)
import Control.Monad.Trans.Resource
import Data.Conduit
import Data.Conduit.Binary
import Data.Conduit.List
import Data.Conduit.Serialization.Binary
import Data.Yaml
import SwiftNav.SBP
import System.IO

main :: IO ()
main =
  runResourceT $
    sourceHandle stdin
      =$= conduitDecode
      =$= map (encode :: SBPMsg -> ByteString)
      $$  sinkHandle stdout
