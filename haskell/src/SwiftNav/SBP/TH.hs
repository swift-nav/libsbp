{-# LANGUAGE NoImplicitPrelude #-}
{-# LANGUAGE TemplateHaskell   #-}

-- |
-- Module:      SwiftNav.SBP.TH
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Templated generation of SBP and JSON interfaces.

module SwiftNav.SBP.TH
  ( makeSBP
  , makeJSON
  ) where

import BasicPrelude         hiding (length)
import Control.Lens
import Data.Aeson.TH
import Data.Binary
import Data.ByteString
import Data.ByteString.Lazy hiding (length)
import Language.Haskell.TH
import SwiftNav.SBP.Types

-- | Derive ToSBP typeclass, given an SBP message type name and the
-- name of the implemented type.
makeSBP :: Name -> Name -> Q [Dec]
makeSBP msgType name =
  [d|instance ToSBP $(conT name) where
       toSBP m senderID = encoded & msgSBPCrc .~ checkCrc encoded
         where
           payload = toStrict $ encode m
           len     = fromIntegral $ length payload
           encoded = Msg $(varE msgType) senderID len (Bytes payload) 0
    |]

-- | Derive JSON stripping out prefixes of the implemented type.
makeJSON :: String -> Name -> Q [Dec]
makeJSON prefix = deriveJSON defaultOptions
  { fieldLabelModifier = ap fromMaybe $ stripPrefix prefix
  }
