{-# LANGUAGE NoImplicitPrelude #-}
{-# LANGUAGE OverloadedStrings #-}

-- |
-- Module:      JSON2SBP
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- JSON to SBP tool - reads SBP JSON from stdin and sends SBP JSON to
-- stdout.

import BasicPrelude                      hiding (lines, mapMaybe)
import Control.Monad.Trans.Resource
import Data.Aeson
import Data.Conduit
import Data.Conduit.Binary
import Data.Conduit.List
import Data.Conduit.Serialization.Binary
import SwiftNav.SBP
import System.IO

newtype SBPMsgData = SBPMsgData
  { sbpMsgData :: SBPMsg
  } deriving ( Show, Read, Eq )

instance FromJSON SBPMsgData where
  parseJSON (Object v) = SBPMsgData <$> v .: "data"
  parseJSON _ = mzero

-- | Decode a SBPMsg from JSON.
--
decodeSBPMsg :: ByteString -> Maybe SBPMsg
decodeSBPMsg v = decodeStrict v <|> sbpMsgData <$> decodeStrict v

main :: IO ()
main =
  runResourceT $
    sourceHandle stdin
      =$= lines
      =$= mapMaybe decodeSBPMsg
      =$= conduitEncode
      $$  sinkHandle stdout
