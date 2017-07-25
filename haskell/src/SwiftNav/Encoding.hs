{-# OPTIONS -fno-warn-orphans  #-}
{-# LANGUAGE NoImplicitPrelude #-}

-- |
-- Module:      SwiftNav.Encoding
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Encoding utilities.

module SwiftNav.Encoding where

import BasicPrelude
import Data.Aeson
import Data.ByteString.Base64   as Base64
import Data.Text.Encoding
import Data.Text.Encoding.Error

-- ByteString doesn't have Aeson instances defined for it since
-- arbitrary ByteString's aren't really valid JSON. This defines
-- orphaned instances for ByteStrings that are expected to be valid
-- text.

instance ToJSON ByteString where
  toJSON = toJSON . decodeUtf8With ignore . Base64.encode

instance FromJSON ByteString where
  parseJSON = withText "ByteString" (pure . Base64.decodeLenient . encodeUtf8)
