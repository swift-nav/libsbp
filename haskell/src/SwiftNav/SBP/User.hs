{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.User
-- Copyright:   Copyright (C) 2015-2018 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Swift Navigation <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- \<Messages reserved for use by the user. \>

module SwiftNav.SBP.User
  ( module SwiftNav.SBP.User
  ) where

import BasicPrelude
import Control.Lens
import Control.Monad.Loops
import Data.Binary
import Data.Binary.Get
import Data.Binary.IEEE754
import Data.Binary.Put
import Data.ByteString.Lazy    hiding (ByteString)
import Data.Int
import Data.Word
import SwiftNav.SBP.TH
import SwiftNav.SBP.Types

{-# ANN module ("HLint: ignore Use camelCase"::String) #-}
{-# ANN module ("HLint: ignore Redundant do"::String) #-}
{-# ANN module ("HLint: ignore Use newtype instead of data"::String) #-}


msgUserData :: Word16
msgUserData = 0x0800

-- | SBP class for message MSG_USER_DATA (0x0800).
--
-- This message can contain any application specific user data up to a maximum
-- length of 255 bytes per message.
data MsgUserData = MsgUserData
  { _msgUserData_contents :: ![Word8]
    -- ^ User data payload
  } deriving ( Show, Read, Eq )

instance Binary MsgUserData where
  get = do
    _msgUserData_contents <- whileM (not <$> isEmpty) getWord8
    pure MsgUserData {..}

  put MsgUserData {..} = do
    mapM_ putWord8 _msgUserData_contents

$(makeSBP 'msgUserData ''MsgUserData)
$(makeJSON "_msgUserData_" ''MsgUserData)
$(makeLenses ''MsgUserData)
