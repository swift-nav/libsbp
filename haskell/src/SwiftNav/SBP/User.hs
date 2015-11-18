-- |
-- Module:      SwiftNav.SBP.User
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- Messages reserved for use by the user.

module SwiftNav.SBP.User where

import BasicPrelude
import Control.Lens
import Control.Monad.Loops
import Data.Aeson.TH (deriveJSON, defaultOptions, fieldLabelModifier)
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy hiding ( ByteString )
import Data.Int
import Data.Word
import SwiftNav.SBP.Encoding
import SwiftNav.SBP.TH
import SwiftNav.SBP.Types

msgUser :: Word16
msgUser = 0x0800

-- | SBP class for message MSG_USER (0x0800).
--
-- This message can contain any application specific user data.
data MsgUser = MsgUser
  { _msgUser_contents :: [Word8]
    -- ^ User data payload
  } deriving ( Show, Read, Eq )

instance Binary MsgUser where
  get = do
    _msgUser_contents <- whileM (liftM not isEmpty) getWord8
    return MsgUser {..}

  put MsgUser {..} = do
    mapM_ putWord8 _msgUser_contents

$(deriveSBP 'msgUser ''MsgUser)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgUser_" . stripPrefix "_msgUser_"}
             ''MsgUser)
$(makeLenses ''MsgUser)
