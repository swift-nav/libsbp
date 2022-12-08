{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Skylark
-- Copyright:   Copyright (C) 2015-2021 Swift Navigation, Inc.
-- License:     MIT
-- Contact:     https://support.swiftnav.com
-- Stability:   experimental
-- Portability: portable
--
-- \< Messages from the Skylark corrections service. \>

module SwiftNav.SBP.Skylark
  ( module SwiftNav.SBP.Skylark
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


msgAcknowledge :: Word16
msgAcknowledge = 0x0FA0

data MsgAcknowledge = MsgAcknowledge
  { _msgAcknowledge_request_counter         :: !Word8
    -- ^ Echo of the request counter field from the corresponding CRA message,
    -- or 255 if no request counter was provided.
  , _msgAcknowledge_area_id                 :: !Word32
    -- ^ Echo of the Area ID field from the corresponding CRA message.
  , _msgAcknowledge_response_code           :: !Word8
    -- ^ Reported status of the request.
  , _msgAcknowledge_correction_mask_on_demand :: !Word16
    -- ^ Contains the message group(s) that will be sent in response from the
    -- corresponding CRA correction mask. An echo of the correction mask field
    -- from the corresponding CRA message.
  , _msgAcknowledge_correction_mask_stream  :: !Word16
    -- ^ For future expansion. Always set to 0.
  , _msgAcknowledge_solution_id             :: !Word8
    -- ^ The solution ID of the instance providing the corrections.
  } deriving ( Show, Read, Eq )

instance Binary MsgAcknowledge where
  get = do
    _msgAcknowledge_request_counter <- getWord8
    _msgAcknowledge_area_id <- getWord32le
    _msgAcknowledge_response_code <- getWord8
    _msgAcknowledge_correction_mask_on_demand <- getWord16le
    _msgAcknowledge_correction_mask_stream <- getWord16le
    _msgAcknowledge_solution_id <- getWord8
    pure MsgAcknowledge {..}

  put MsgAcknowledge {..} = do
    putWord8 _msgAcknowledge_request_counter
    putWord32le _msgAcknowledge_area_id
    putWord8 _msgAcknowledge_response_code
    putWord16le _msgAcknowledge_correction_mask_on_demand
    putWord16le _msgAcknowledge_correction_mask_stream
    putWord8 _msgAcknowledge_solution_id

$(makeSBP 'msgAcknowledge ''MsgAcknowledge)
$(makeJSON "_msgAcknowledge_" ''MsgAcknowledge)
$(makeLenses ''MsgAcknowledge)
