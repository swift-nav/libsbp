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

import           BasicPrelude
import           Control.Monad.Trans.Resource
import           Data.Conduit
import           Data.Conduit.Binary
import qualified Data.Conduit.List as CL
import           Data.Conduit.Serialization.Binary
import           Data.Yaml
import           SwiftNav.SBP
import           System.IO

main :: IO ()
main =
  runResourceT $
    sourceHandle stdin                      =$=
    conduitDecode                           =$=
    CL.map (encode :: SBPMsg -> ByteString) $$
    sinkHandle stdout
