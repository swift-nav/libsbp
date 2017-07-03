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

import           BasicPrelude hiding (lines)
import           Control.Monad.Trans.Resource
import           Data.Aeson
import           Data.Conduit
import           Data.Conduit.Binary
import qualified Data.Conduit.List as CL
import           Data.Conduit.Serialization.Binary
import           Debug.Trace
import           SwiftNav.SBP
import           System.IO

newtype SBPMsgData = SBPMsgData
  { sbpMsgData :: SBPMsg
  } deriving ( Show, Read, Eq )

instance FromJSON SBPMsgData where
  parseJSON (Object v) = SBPMsgData <$> v .: "data"
  parseJSON _ = mzero

-- | Decode a SBPMsg from JSON.
decodeSBPMsg :: ByteString -> Maybe SBPMsg
decodeSBPMsg v = result
  where parsed = eitherDecodeStrict v <|> sbpMsgData <$> eitherDecodeStrict v
        result = case parsed of
                   Left s -> trace s Nothing
                   Right x -> Just x

main :: IO ()
main =
  runResourceT $
    sourceHandle stdin       =$=
    lines                    =$=
    CL.mapMaybe decodeSBPMsg =$=
    conduitEncode            $$
    sinkHandle stdout
