{-# OPTIONS_GHC -fno-warn-unused-imports #-}
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
import Data.Aeson.TH           (defaultOptions, deriveJSON, fieldLabelModifier)
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString
import Data.ByteString.Lazy    hiding (ByteString)
import Data.Int
import Data.Word
import SwiftNav.SBP.Encoding
import SwiftNav.SBP.TH
import SwiftNav.SBP.Types

msgUserData :: Word16
msgUserData = 0x0800

-- | SBP class for message MSG_USER_DATA (0x0800).
--
-- This message can contain any application specific user data up to a maximum
-- length of 255 bytes per message.
data MsgUserData = MsgUserData
  { _msgUserData_contents :: [Word8]
    -- ^ User data payload
  } deriving ( Show, Read, Eq )

instance Binary MsgUserData where
  get = do
    _msgUserData_contents <- whileM (liftM not isEmpty) getWord8
    return MsgUserData {..}

  put MsgUserData {..} = do
    mapM_ putWord8 _msgUserData_contents

$(deriveSBP 'msgUserData ''MsgUserData)

$(deriveJSON defaultOptions {fieldLabelModifier = fromMaybe "_msgUserData_" . stripPrefix "_msgUserData_"}
             ''MsgUserData)
$(makeLenses ''MsgUserData)
