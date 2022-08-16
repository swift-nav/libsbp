{-# OPTIONS_GHC -fno-warn-unused-imports #-}
{-# LANGUAGE NoImplicitPrelude           #-}
{-# LANGUAGE TemplateHaskell             #-}
{-# LANGUAGE RecordWildCards             #-}

-- |
-- Module:      SwiftNav.SBP.Signing
-- Copyright:   Copyright (C) 2015-2021 Swift Navigation, Inc.
-- License:     MIT
-- Contact:     https://support.swiftnav.com
-- Stability:   experimental
-- Portability: portable
--
-- \< Messages relating to signatures \>

module SwiftNav.SBP.Signing
  ( module SwiftNav.SBP.Signing
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
import SwiftNav.SBP.Gnss

{-# ANN module ("HLint: ignore Use camelCase"::String) #-}
{-# ANN module ("HLint: ignore Redundant do"::String) #-}
{-# ANN module ("HLint: ignore Use newtype instead of data"::String) #-}


msgEd25519Signature :: Word16
msgEd25519Signature = 0x0C01

data MsgEd25519Signature = MsgEd25519Signature
  { _msgEd25519Signature_signature     :: ![Word8]
    -- ^ ED25519 signature for messages.
  , _msgEd25519Signature_fingerprint   :: ![Word8]
    -- ^ SHA-1 fingerprint of the associated certificate.
  , _msgEd25519Signature_signed_messages :: ![Word32]
    -- ^ CRCs of signed messages.
  } deriving ( Show, Read, Eq )

instance Binary MsgEd25519Signature where
  get = do
    _msgEd25519Signature_signature <- replicateM 64 getWord8
    _msgEd25519Signature_fingerprint <- replicateM 20 getWord8
    _msgEd25519Signature_signed_messages <- whileM (not <$> isEmpty) getWord32le
    pure MsgEd25519Signature {..}

  put MsgEd25519Signature {..} = do
    mapM_ putWord8 _msgEd25519Signature_signature
    mapM_ putWord8 _msgEd25519Signature_fingerprint
    mapM_ putWord32le _msgEd25519Signature_signed_messages

$(makeSBP 'msgEd25519Signature ''MsgEd25519Signature)
$(makeJSON "_msgEd25519Signature_" ''MsgEd25519Signature)
$(makeLenses ''MsgEd25519Signature)

msgEd25519Certificate :: Word16
msgEd25519Certificate = 0x0C02

data MsgEd25519Certificate = MsgEd25519Certificate
  { _msgEd25519Certificate_n_msg           :: !Word8
    -- ^ Total number messages that make up the certificate. First nibble is the
    -- size of the sequence (n), second nibble is the zero-indexed counter
    -- (ith packet of n)
  , _msgEd25519Certificate_fingerprint     :: ![Word8]
    -- ^ SHA-1 fingerprint of the associated certificate.
  , _msgEd25519Certificate_certificate_bytes :: ![Word8]
    -- ^ ED25519 certificate bytes.
  } deriving ( Show, Read, Eq )

instance Binary MsgEd25519Certificate where
  get = do
    _msgEd25519Certificate_n_msg <- getWord8
    _msgEd25519Certificate_fingerprint <- replicateM 20 getWord8
    _msgEd25519Certificate_certificate_bytes <- whileM (not <$> isEmpty) getWord8
    pure MsgEd25519Certificate {..}

  put MsgEd25519Certificate {..} = do
    putWord8 _msgEd25519Certificate_n_msg
    mapM_ putWord8 _msgEd25519Certificate_fingerprint
    mapM_ putWord8 _msgEd25519Certificate_certificate_bytes

$(makeSBP 'msgEd25519Certificate ''MsgEd25519Certificate)
$(makeJSON "_msgEd25519Certificate_" ''MsgEd25519Certificate)
$(makeLenses ''MsgEd25519Certificate)
