-- |
-- Module:      SwiftNav.SBP
-- Copyright:   Copyright (C) 2015 Swift Navigation, Inc.
-- License:     LGPL-3
-- Maintainer:  Mark Fine <dev@swiftnav.com>
-- Stability:   experimental
-- Portability: portable
--
-- SBP message containers.

module SwiftNav.SBP
  ( SBPMsg (..)
  , module SwiftNav.SBP.Types
  ((*- for m in modules *))
  , module (((m)))
  ((*- endfor *))
  ) where

import BasicPrelude hiding (lookup)
import Control.Lens hiding ((.=))
import Data.Aeson hiding (decode, decode')
import Data.Binary
import Data.Binary.Get
import Data.Binary.Put
import Data.ByteString.Lazy hiding (ByteString)
import Data.ByteString.Builder
import Data.HashMap.Strict
import SwiftNav.CRC16
((*- for m in modules *))
import (((m)))
((*- endfor *))
import SwiftNav.SBP.Types

((* for m in msgs *))
((*- if loop.first *))
-- | An SBP message ADT composed of all defined SBP messages.
--
-- Includes SBPMsgUnknown for valid SBP messages with undefined message
-- types and SBPMsgBadCRC for SBP messages with invalid CRC checksums.
data SBPMsg =
     SBP(((m))) (((m))) Msg
((*- else *))
   | SBP(((m))) (((m))) Msg
((*- endif *))
((*- if loop.last *))
   | SBPMsgBadCrc Msg
   | SBPMsgUnknown Msg
  deriving ( Show, Read, Eq )
((*- endif *))
((*- endfor *))

instance Binary SBPMsg where
  get = do
    preamble <- getWord8
    if preamble /= msgSBPPreamble then get else do
      sbp <- get
      return $ decode' sbp where
        decode' sbp@Msg {..}
          | checkCrc sbp /= _msgSBPCrc = SBPMsgBadCrc sbp
          ((*- for m in msgs *))
          | _msgSBPType == (((m | to_global))) = SBP(((m))) (decode (fromStrict _msgSBPPayload)) sbp
          ((*- endfor *))
          | otherwise = SBPMsgUnknown sbp

  put msg = do
    putWord8 msgSBPPreamble
    put $ encode' msg
    where
      ((*- for m in msgs *))
      encode' (SBP(((m))) _ sbp) = sbp
      ((*- endfor *))
      encode' (SBPMsgUnknown sbp) = sbp
      encode' (SBPMsgBadCrc sbp) = sbp

instance FromJSON SBPMsg where
  parseJSON obj@(Object o) = do
    msgType <- o .: "msg_type"
    decode' msgType where
      decode' msgType
((*- for m in msgs *))
        | msgType == (((m | to_global))) = SBP(((m))) <$> parseJSON obj <*> parseJSON obj
((*- endfor *))
        | otherwise = SBPMsgUnknown <$> parseJSON obj
  parseJSON _ = mzero

merge :: Value -> Value -> Value
merge (Object one) (Object two) = Object (one <> two)
merge _ (Object two) = Object two
merge (Object one) _ = Object one
merge _ v = v

instance ToJSON SBPMsg where
((*- for m in msgs *))
   toJSON (SBP(((m))) msg sbp) = toJSON msg `merge` toJSON sbp
((*- endfor *))
   toJSON (SBPMsgBadCrc sbp) = toJSON sbp
   toJSON (SBPMsgUnknown sbp) = toJSON sbp
