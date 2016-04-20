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

import BasicPrelude             hiding (lookup)
import Control.Lens             hiding ((.=))
import Data.Aeson               hiding (decode, decode')
import Data.Binary
import Data.ByteString.Lazy     hiding (ByteString)
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

$(makePrisms ''SBPMsg)

instance Binary SBPMsg where
  get = do
    preamble <- getWord8
    if preamble /= msgSBPPreamble then get else do
      decode' <$> get where
        decode' m@Msg {..}
          | checkCrc m /= _msgSBPCrc = SBPMsgBadCrc m
          ((*- for m in msgs *))
          | _msgSBPType == (((m | to_global))) = SBP(((m))) (decode (fromStrict _msgSBPPayload)) m
          ((*- endfor *))
          | otherwise = SBPMsgUnknown m

  put sm = do
    putWord8 msgSBPPreamble
    encode' sm where
      ((*- for m in msgs *))
      encode' (SBP(((m))) _ m) = put m
      ((*- endfor *))
      encode' (SBPMsgUnknown m) = put m
      encode' (SBPMsgBadCrc m) = put m

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

mergeValues :: Value -> Value -> Value
mergeValues (Object a) (Object b) = Object (a <> b)
mergeValues (Object a) _          = Object a
mergeValues _          (Object b) = Object b
mergeValues _          v          = v

instance ToJSON SBPMsg where
((*- for m in msgs *))
  toJSON (SBP(((m))) n m) = toJSON n `mergeValues` toJSON m
((*- endfor *))
  toJSON (SBPMsgBadCrc m) = toJSON m
  toJSON (SBPMsgUnknown m) = toJSON m

instance HasMsg SBPMsg where
((*- for m in msgs *))
  msg f (SBP(((m))) n m) = SBP(((m))) n <$> f m
((*- endfor *))
  msg f (SBPMsgUnknown m) = SBPMsgUnknown <$> f m
  msg f (SBPMsgBadCrc m) = SBPMsgBadCrc <$> f m
