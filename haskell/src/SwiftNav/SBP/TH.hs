-- |
-- Module:      SwiftNav.SBP.TH
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Templated generation of SBP interfaces.

module SwiftNav.SBP.TH where

import BasicPrelude
import Control.Lens
import Data.Binary
import Data.ByteString
import Data.ByteString.Lazy hiding (ByteString)
import Language.Haskell.TH
import SwiftNav.SBP.Types

-- | Derive ToSBP typeclass, given an SBP message type name and the
-- name of the implemented type.
deriveSBP :: Name -> Name -> Q [Dec]
deriveSBP msgType name =
  [d|instance ToSBP $(conT name) where
       toSBP m senderID = encoded & msgSBPCrc .~ checkCrc encoded
         where
           payload = toStrict $ encode m
           len = fromIntegral $ Data.ByteString.length payload
           encoded = Msg $(varE msgType) senderID len payload 0
    |]
