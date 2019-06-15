{-# LANGUAGE DeriveDataTypeable #-}
{-# OPTIONS_GHC -fno-cse #-}
{-# LANGUAGE NoImplicitPrelude #-}
{-# LANGUAGE OverloadedStrings #-}

-- |
-- Module:      SBP2PRETTYJSON
-- Copyright:   Copyright (C) 2019 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Pasi Miettinen <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- SBP to JSON tool - reads SBP binary from stdin and sends SBP JSON
-- to stdout.

import BasicPrelude                      hiding (map, print)
import Control.Monad.Trans.Resource
import Data.Aeson.Encode.Pretty
import Data.ByteString.Lazy              hiding (ByteString, map)
import Data.Conduit
import Data.Conduit.Binary
import Data.Conduit.List
import Data.Conduit.Serialization.Binary
import SwiftNav.SBP
import System.Console.CmdArgs
import System.IO

data Cfg = Cfg { skiporder :: Bool
               , spaces :: Int
               , skipfilter :: Bool }
           deriving (Show, Data, Typeable)

defaultCfg :: Cfg
defaultCfg = Cfg { skiporder = False
                 , spaces = 0
                 , skipfilter = False }

-- | Encode a SBPMsg to a line of JSON.
encodeLine :: Cfg -> SBPMsg -> ByteString
encodeLine c (SBPMsgBadCrc _v)  | not (skipfilter c) = mempty
encodeLine c (SBPMsgUnknown _v) | not (skipfilter c) = mempty
encodeLine c v = toStrict $ encodePretty' (defConfig
  { confIndent = Spaces (spaces c)
  , confCompare = if (skiporder c) then mempty else compare
  }) v <> "\n"

main :: IO ()
main = do
  cfg <- cmdArgs defaultCfg
  runResourceT $
    sourceHandle stdin
      =$= conduitDecode
      =$= map (encodeLine cfg)
      $$  sinkHandle stdout
