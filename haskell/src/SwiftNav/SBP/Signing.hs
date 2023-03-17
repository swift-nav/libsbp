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

{-# ANN module ("HLint: ignore Use camelCase"::String) #-}
{-# ANN module ("HLint: ignore Redundant do"::String) #-}
{-# ANN module ("HLint: ignore Use newtype instead of data"::String) #-}


data UtcTime = UtcTime
  { _utcTime_year  :: !Word16
    -- ^ Year
  , _utcTime_month :: !Word8
    -- ^ Month (range 1 .. 12)
  , _utcTime_day   :: !Word8
    -- ^ days in the month (range 1-31)
  , _utcTime_hours :: !Word8
    -- ^ hours of day (range 0-23)
  , _utcTime_minutes :: !Word8
    -- ^ minutes of hour (range 0-59)
  , _utcTime_seconds :: !Word8
    -- ^ seconds of minute (range 0-60) rounded down
  , _utcTime_ns    :: !Word32
    -- ^ nanoseconds of second (range 0-999999999)
  } deriving ( Show, Read, Eq )

instance Binary UtcTime where
  get = do
    _utcTime_year <- getWord16le
    _utcTime_month <- getWord8
    _utcTime_day <- getWord8
    _utcTime_hours <- getWord8
    _utcTime_minutes <- getWord8
    _utcTime_seconds <- getWord8
    _utcTime_ns <- getWord32le
    pure UtcTime {..}

  put UtcTime {..} = do
    putWord16le _utcTime_year
    putWord8 _utcTime_month
    putWord8 _utcTime_day
    putWord8 _utcTime_hours
    putWord8 _utcTime_minutes
    putWord8 _utcTime_seconds
    putWord32le _utcTime_ns

$(makeJSON "_utcTime_" ''UtcTime)
$(makeLenses ''UtcTime)

data ECDSASignature = ECDSASignature
  { _eCDSASignature_len :: !Word8
    -- ^ Number of bytes to use of the signature field.  The DER encoded
    -- signature has a maximum size of 72 bytes but can vary between 70 and 72
    -- bytes in length.
  , _eCDSASignature_data :: ![Word8]
    -- ^ DER encoded ECDSA signature for the messages using SHA-256 as the
    -- digest algorithm.
  } deriving ( Show, Read, Eq )

instance Binary ECDSASignature where
  get = do
    _eCDSASignature_len <- getWord8
    _eCDSASignature_data <- replicateM 72 getWord8
    pure ECDSASignature {..}

  put ECDSASignature {..} = do
    putWord8 _eCDSASignature_len
    mapM_ putWord8 _eCDSASignature_data

$(makeJSON "_eCDSASignature_" ''ECDSASignature)
$(makeLenses ''ECDSASignature)

msgEcdsaCertificate :: Word16
msgEcdsaCertificate = 0x0C04

-- | SBP class for message MSG_ECDSA_CERTIFICATE (0x0C04).
--
-- A DER encoded x.509 ECDSA-256 certificate (using curve secp256r1).
data MsgEcdsaCertificate = MsgEcdsaCertificate
  { _msgEcdsaCertificate_n_msg           :: !Word8
    -- ^ Total number messages that make up the certificate. The first nibble
    -- (mask 0xF0 or left shifted by 4 bits) is the size of the sequence (n),
    -- second nibble (mask 0x0F) is the zero-indexed counter (ith packet of
    -- n).
  , _msgEcdsaCertificate_certificate_id  :: ![Word8]
    -- ^ The last 4 bytes of the certificate's SHA-1 fingerprint
  , _msgEcdsaCertificate_flags           :: !Word8
  , _msgEcdsaCertificate_certificate_bytes :: ![Word8]
    -- ^ DER encoded x.509 ECDSA certificate bytes
  } deriving ( Show, Read, Eq )

instance Binary MsgEcdsaCertificate where
  get = do
    _msgEcdsaCertificate_n_msg <- getWord8
    _msgEcdsaCertificate_certificate_id <- replicateM 4 getWord8
    _msgEcdsaCertificate_flags <- getWord8
    _msgEcdsaCertificate_certificate_bytes <- whileM (not <$> isEmpty) getWord8
    pure MsgEcdsaCertificate {..}

  put MsgEcdsaCertificate {..} = do
    putWord8 _msgEcdsaCertificate_n_msg
    mapM_ putWord8 _msgEcdsaCertificate_certificate_id
    putWord8 _msgEcdsaCertificate_flags
    mapM_ putWord8 _msgEcdsaCertificate_certificate_bytes

$(makeSBP 'msgEcdsaCertificate ''MsgEcdsaCertificate)
$(makeJSON "_msgEcdsaCertificate_" ''MsgEcdsaCertificate)
$(makeLenses ''MsgEcdsaCertificate)

msgCertificateChain :: Word16
msgCertificateChain = 0x0C09

data MsgCertificateChain = MsgCertificateChain
  { _msgCertificateChain_root_certificate       :: ![Word8]
    -- ^ SHA-1 fingerprint of the root certificate
  , _msgCertificateChain_intermediate_certificate :: ![Word8]
    -- ^ SHA-1 fingerprint of the intermediate certificate
  , _msgCertificateChain_corrections_certificate :: ![Word8]
    -- ^ SHA-1 fingerprint of the corrections certificate
  , _msgCertificateChain_expiration             :: !UtcTime
    -- ^ The certificate chain comprised of three fingerprints: root
    -- certificate, intermediate certificate and corrections certificate.
  , _msgCertificateChain_signature              :: !ECDSASignature
    -- ^ Signature (created by the root certificate) over the concatenation of
    -- the SBP payload bytes preceding this field. That is, the concatenation
    -- of `root_certificate`, `intermediate_certificate`,
    -- `corrections_certificate` and `expiration`.  This certificate chain
    -- (allow list) can also be validated by fetching it from
    -- `http(s)://certs.swiftnav.com/chain`.
  } deriving ( Show, Read, Eq )

instance Binary MsgCertificateChain where
  get = do
    _msgCertificateChain_root_certificate <- replicateM 20 getWord8
    _msgCertificateChain_intermediate_certificate <- replicateM 20 getWord8
    _msgCertificateChain_corrections_certificate <- replicateM 20 getWord8
    _msgCertificateChain_expiration <- get
    _msgCertificateChain_signature <- get
    pure MsgCertificateChain {..}

  put MsgCertificateChain {..} = do
    mapM_ putWord8 _msgCertificateChain_root_certificate
    mapM_ putWord8 _msgCertificateChain_intermediate_certificate
    mapM_ putWord8 _msgCertificateChain_corrections_certificate
    put _msgCertificateChain_expiration
    put _msgCertificateChain_signature

$(makeSBP 'msgCertificateChain ''MsgCertificateChain)
$(makeJSON "_msgCertificateChain_" ''MsgCertificateChain)
$(makeLenses ''MsgCertificateChain)

msgCertificateChainDep :: Word16
msgCertificateChainDep = 0x0C05

data MsgCertificateChainDep = MsgCertificateChainDep
  { _msgCertificateChainDep_root_certificate       :: ![Word8]
    -- ^ SHA-1 fingerprint of the root certificate
  , _msgCertificateChainDep_intermediate_certificate :: ![Word8]
    -- ^ SHA-1 fingerprint of the intermediate certificate
  , _msgCertificateChainDep_corrections_certificate :: ![Word8]
    -- ^ SHA-1 fingerprint of the corrections certificate
  , _msgCertificateChainDep_expiration             :: !UtcTime
    -- ^ The certificate chain comprised of three fingerprints: root
    -- certificate, intermediate certificate and corrections certificate.
  , _msgCertificateChainDep_signature              :: ![Word8]
    -- ^ An ECDSA signature (created by the root certificate) over the
    -- concatenation of the SBP payload bytes preceding this field. That is,
    -- the concatenation of `root_certificate`, `intermediate_certificate`,
    -- `corrections_certificate` and `expiration`.  This certificate chain
    -- (allow list) can also be validated by fetching it from
    -- `http(s)://certs.swiftnav.com/chain`.
  } deriving ( Show, Read, Eq )

instance Binary MsgCertificateChainDep where
  get = do
    _msgCertificateChainDep_root_certificate <- replicateM 20 getWord8
    _msgCertificateChainDep_intermediate_certificate <- replicateM 20 getWord8
    _msgCertificateChainDep_corrections_certificate <- replicateM 20 getWord8
    _msgCertificateChainDep_expiration <- get
    _msgCertificateChainDep_signature <- replicateM 64 getWord8
    pure MsgCertificateChainDep {..}

  put MsgCertificateChainDep {..} = do
    mapM_ putWord8 _msgCertificateChainDep_root_certificate
    mapM_ putWord8 _msgCertificateChainDep_intermediate_certificate
    mapM_ putWord8 _msgCertificateChainDep_corrections_certificate
    put _msgCertificateChainDep_expiration
    mapM_ putWord8 _msgCertificateChainDep_signature

$(makeSBP 'msgCertificateChainDep ''MsgCertificateChainDep)
$(makeJSON "_msgCertificateChainDep_" ''MsgCertificateChainDep)
$(makeLenses ''MsgCertificateChainDep)

msgEcdsaSignature :: Word16
msgEcdsaSignature = 0x0C08

-- | SBP class for message MSG_ECDSA_SIGNATURE (0x0C08).
--
-- An ECDSA-256 signature using SHA-256 as the message digest algorithm.
data MsgEcdsaSignature = MsgEcdsaSignature
  { _msgEcdsaSignature_flags           :: !Word8
    -- ^ Describes the format of the `signed\_messages` field below.
  , _msgEcdsaSignature_stream_counter  :: !Word8
    -- ^ Signature message counter. Zero indexed and incremented with each
    -- signature message.  The counter will not increment if this message was
    -- in response to an on demand request.  The counter will roll over after
    -- 256 messages. Upon connection, the value of the counter may not
    -- initially be zero.
  , _msgEcdsaSignature_on_demand_counter :: !Word8
    -- ^ On demand message counter. Zero indexed and incremented with each
    -- signature message sent in response to an on demand message. The counter
    -- will roll over after 256 messages.  Upon connection, the value of the
    -- counter may not initially be zero.
  , _msgEcdsaSignature_certificate_id  :: ![Word8]
    -- ^ The last 4 bytes of the certificate's SHA-1 fingerprint
  , _msgEcdsaSignature_signature       :: !ECDSASignature
    -- ^ Signature over the frames of this message group.
  , _msgEcdsaSignature_signed_messages :: ![Word8]
    -- ^ CRCs of the messages covered by this signature.  For Skylark, which
    -- delivers SBP messages wrapped in Swift's proprietary RTCM message,
    -- these are the 24-bit CRCs from the RTCM message framing. For SBP only
    -- streams, this will be 16-bit CRCs from the SBP framing.  See the
    -- `flags` field to determine the type of CRCs covered.
  } deriving ( Show, Read, Eq )

instance Binary MsgEcdsaSignature where
  get = do
    _msgEcdsaSignature_flags <- getWord8
    _msgEcdsaSignature_stream_counter <- getWord8
    _msgEcdsaSignature_on_demand_counter <- getWord8
    _msgEcdsaSignature_certificate_id <- replicateM 4 getWord8
    _msgEcdsaSignature_signature <- get
    _msgEcdsaSignature_signed_messages <- whileM (not <$> isEmpty) getWord8
    pure MsgEcdsaSignature {..}

  put MsgEcdsaSignature {..} = do
    putWord8 _msgEcdsaSignature_flags
    putWord8 _msgEcdsaSignature_stream_counter
    putWord8 _msgEcdsaSignature_on_demand_counter
    mapM_ putWord8 _msgEcdsaSignature_certificate_id
    put _msgEcdsaSignature_signature
    mapM_ putWord8 _msgEcdsaSignature_signed_messages

$(makeSBP 'msgEcdsaSignature ''MsgEcdsaSignature)
$(makeJSON "_msgEcdsaSignature_" ''MsgEcdsaSignature)
$(makeLenses ''MsgEcdsaSignature)

msgEcdsaSignatureDepB :: Word16
msgEcdsaSignatureDepB = 0x0C07

-- | SBP class for message MSG_ECDSA_SIGNATURE_DEP_B (0x0C07).
--
-- An ECDSA-256 signature using SHA-256 as the message digest algorithm.
data MsgEcdsaSignatureDepB = MsgEcdsaSignatureDepB
  { _msgEcdsaSignatureDepB_flags           :: !Word8
    -- ^ Describes the format of the `signed\_messages` field below.
  , _msgEcdsaSignatureDepB_stream_counter  :: !Word8
    -- ^ Signature message counter. Zero indexed and incremented with each
    -- signature message.  The counter will not increment if this message was
    -- in response to an on demand request.  The counter will roll over after
    -- 256 messages. Upon connection, the value of the counter may not
    -- initially be zero.
  , _msgEcdsaSignatureDepB_on_demand_counter :: !Word8
    -- ^ On demand message counter. Zero indexed and incremented with each
    -- signature message sent in response to an on demand message. The counter
    -- will roll over after 256 messages.  Upon connection, the value of the
    -- counter may not initially be zero.
  , _msgEcdsaSignatureDepB_certificate_id  :: ![Word8]
    -- ^ The last 4 bytes of the certificate's SHA-1 fingerprint
  , _msgEcdsaSignatureDepB_n_signature_bytes :: !Word8
    -- ^ Number of bytes to use of the signature field.  The DER encoded
    -- signature has a maximum size of 72 bytes but can vary between 70 and 72
    -- bytes in length.
  , _msgEcdsaSignatureDepB_signature       :: ![Word8]
    -- ^ DER encoded ECDSA signature for the messages using SHA-256 as the
    -- digest algorithm.
  , _msgEcdsaSignatureDepB_signed_messages :: ![Word8]
    -- ^ CRCs of the messages covered by this signature.  For Skylark, which
    -- delivers SBP messages wrapped in Swift's proprietary RTCM message,
    -- these are the 24-bit CRCs from the RTCM message framing. For SBP only
    -- streams, this will be 16-bit CRCs from the SBP framing.  See the
    -- `flags` field to determine the type of CRCs covered.
  } deriving ( Show, Read, Eq )

instance Binary MsgEcdsaSignatureDepB where
  get = do
    _msgEcdsaSignatureDepB_flags <- getWord8
    _msgEcdsaSignatureDepB_stream_counter <- getWord8
    _msgEcdsaSignatureDepB_on_demand_counter <- getWord8
    _msgEcdsaSignatureDepB_certificate_id <- replicateM 4 getWord8
    _msgEcdsaSignatureDepB_n_signature_bytes <- getWord8
    _msgEcdsaSignatureDepB_signature <- replicateM 72 getWord8
    _msgEcdsaSignatureDepB_signed_messages <- whileM (not <$> isEmpty) getWord8
    pure MsgEcdsaSignatureDepB {..}

  put MsgEcdsaSignatureDepB {..} = do
    putWord8 _msgEcdsaSignatureDepB_flags
    putWord8 _msgEcdsaSignatureDepB_stream_counter
    putWord8 _msgEcdsaSignatureDepB_on_demand_counter
    mapM_ putWord8 _msgEcdsaSignatureDepB_certificate_id
    putWord8 _msgEcdsaSignatureDepB_n_signature_bytes
    mapM_ putWord8 _msgEcdsaSignatureDepB_signature
    mapM_ putWord8 _msgEcdsaSignatureDepB_signed_messages

$(makeSBP 'msgEcdsaSignatureDepB ''MsgEcdsaSignatureDepB)
$(makeJSON "_msgEcdsaSignatureDepB_" ''MsgEcdsaSignatureDepB)
$(makeLenses ''MsgEcdsaSignatureDepB)

msgEcdsaSignatureDepA :: Word16
msgEcdsaSignatureDepA = 0x0C06

-- | SBP class for message MSG_ECDSA_SIGNATURE_DEP_A (0x0C06).
--
-- An ECDSA-256 signature using SHA-256 as the message digest algorithm.
data MsgEcdsaSignatureDepA = MsgEcdsaSignatureDepA
  { _msgEcdsaSignatureDepA_flags           :: !Word8
    -- ^ Describes the format of the `signed\_messages` field below.
  , _msgEcdsaSignatureDepA_stream_counter  :: !Word8
    -- ^ Signature message counter. Zero indexed and incremented with each
    -- signature message.  The counter will not increment if this message was
    -- in response to an on demand request.  The counter will roll over after
    -- 256 messages. Upon connection, the value of the counter may not
    -- initially be zero.
  , _msgEcdsaSignatureDepA_on_demand_counter :: !Word8
    -- ^ On demand message counter. Zero indexed and incremented with each
    -- signature message sent in response to an on demand message. The counter
    -- will roll over after 256 messages.  Upon connection, the value of the
    -- counter may not initially be zero.
  , _msgEcdsaSignatureDepA_certificate_id  :: ![Word8]
    -- ^ The last 4 bytes of the certificate's SHA-1 fingerprint
  , _msgEcdsaSignatureDepA_signature       :: ![Word8]
    -- ^ ECDSA signature for the messages using SHA-256 as the digest algorithm.
  , _msgEcdsaSignatureDepA_signed_messages :: ![Word8]
    -- ^ CRCs of the messages covered by this signature.  For Skylark, which
    -- delivers SBP messages wrapped in Swift's proprietary RTCM message,
    -- these are the 24-bit CRCs from the RTCM message framing. For SBP only
    -- streams, this will be 16-bit CRCs from the SBP framing.  See the
    -- `flags` field to determine the type of CRCs covered.
  } deriving ( Show, Read, Eq )

instance Binary MsgEcdsaSignatureDepA where
  get = do
    _msgEcdsaSignatureDepA_flags <- getWord8
    _msgEcdsaSignatureDepA_stream_counter <- getWord8
    _msgEcdsaSignatureDepA_on_demand_counter <- getWord8
    _msgEcdsaSignatureDepA_certificate_id <- replicateM 4 getWord8
    _msgEcdsaSignatureDepA_signature <- replicateM 64 getWord8
    _msgEcdsaSignatureDepA_signed_messages <- whileM (not <$> isEmpty) getWord8
    pure MsgEcdsaSignatureDepA {..}

  put MsgEcdsaSignatureDepA {..} = do
    putWord8 _msgEcdsaSignatureDepA_flags
    putWord8 _msgEcdsaSignatureDepA_stream_counter
    putWord8 _msgEcdsaSignatureDepA_on_demand_counter
    mapM_ putWord8 _msgEcdsaSignatureDepA_certificate_id
    mapM_ putWord8 _msgEcdsaSignatureDepA_signature
    mapM_ putWord8 _msgEcdsaSignatureDepA_signed_messages

$(makeSBP 'msgEcdsaSignatureDepA ''MsgEcdsaSignatureDepA)
$(makeJSON "_msgEcdsaSignatureDepA_" ''MsgEcdsaSignatureDepA)
$(makeLenses ''MsgEcdsaSignatureDepA)

msgEd25519CertificateDep :: Word16
msgEd25519CertificateDep = 0x0C02

data MsgEd25519CertificateDep = MsgEd25519CertificateDep
  { _msgEd25519CertificateDep_n_msg           :: !Word8
    -- ^ Total number messages that make up the certificate. First nibble is the
    -- size of the sequence (n), second nibble is the zero-indexed counter
    -- (ith packet of n)
  , _msgEd25519CertificateDep_fingerprint     :: ![Word8]
    -- ^ SHA-1 fingerprint of the associated certificate.
  , _msgEd25519CertificateDep_certificate_bytes :: ![Word8]
    -- ^ ED25519 certificate bytes.
  } deriving ( Show, Read, Eq )

instance Binary MsgEd25519CertificateDep where
  get = do
    _msgEd25519CertificateDep_n_msg <- getWord8
    _msgEd25519CertificateDep_fingerprint <- replicateM 20 getWord8
    _msgEd25519CertificateDep_certificate_bytes <- whileM (not <$> isEmpty) getWord8
    pure MsgEd25519CertificateDep {..}

  put MsgEd25519CertificateDep {..} = do
    putWord8 _msgEd25519CertificateDep_n_msg
    mapM_ putWord8 _msgEd25519CertificateDep_fingerprint
    mapM_ putWord8 _msgEd25519CertificateDep_certificate_bytes

$(makeSBP 'msgEd25519CertificateDep ''MsgEd25519CertificateDep)
$(makeJSON "_msgEd25519CertificateDep_" ''MsgEd25519CertificateDep)
$(makeLenses ''MsgEd25519CertificateDep)

msgEd25519SignatureDepA :: Word16
msgEd25519SignatureDepA = 0x0C01

data MsgEd25519SignatureDepA = MsgEd25519SignatureDepA
  { _msgEd25519SignatureDepA_signature     :: ![Word8]
    -- ^ ED25519 signature for messages.
  , _msgEd25519SignatureDepA_fingerprint   :: ![Word8]
    -- ^ SHA-1 fingerprint of the associated certificate.
  , _msgEd25519SignatureDepA_signed_messages :: ![Word32]
    -- ^ CRCs of signed messages.
  } deriving ( Show, Read, Eq )

instance Binary MsgEd25519SignatureDepA where
  get = do
    _msgEd25519SignatureDepA_signature <- replicateM 64 getWord8
    _msgEd25519SignatureDepA_fingerprint <- replicateM 20 getWord8
    _msgEd25519SignatureDepA_signed_messages <- whileM (not <$> isEmpty) getWord32le
    pure MsgEd25519SignatureDepA {..}

  put MsgEd25519SignatureDepA {..} = do
    mapM_ putWord8 _msgEd25519SignatureDepA_signature
    mapM_ putWord8 _msgEd25519SignatureDepA_fingerprint
    mapM_ putWord32le _msgEd25519SignatureDepA_signed_messages

$(makeSBP 'msgEd25519SignatureDepA ''MsgEd25519SignatureDepA)
$(makeJSON "_msgEd25519SignatureDepA_" ''MsgEd25519SignatureDepA)
$(makeLenses ''MsgEd25519SignatureDepA)

msgEd25519SignatureDepB :: Word16
msgEd25519SignatureDepB = 0x0C03

data MsgEd25519SignatureDepB = MsgEd25519SignatureDepB
  { _msgEd25519SignatureDepB_stream_counter  :: !Word8
    -- ^ Signature message counter. Zero indexed and incremented with each
    -- signature message.  The counter will not increment if this message was
    -- in response to an on demand request.  The counter will roll over after
    -- 256 messages. Upon connection, the value of the counter may not
    -- initially be zero.
  , _msgEd25519SignatureDepB_on_demand_counter :: !Word8
    -- ^ On demand message counter. Zero indexed and incremented with each
    -- signature message sent in response to an on demand message. The counter
    -- will roll over after 256 messages.  Upon connection, the value of the
    -- counter may not initially be zero.
  , _msgEd25519SignatureDepB_signature       :: ![Word8]
    -- ^ ED25519 signature for messages.
  , _msgEd25519SignatureDepB_fingerprint     :: ![Word8]
    -- ^ SHA-1 fingerprint of the associated certificate.
  , _msgEd25519SignatureDepB_signed_messages :: ![Word32]
    -- ^ CRCs of signed messages.
  } deriving ( Show, Read, Eq )

instance Binary MsgEd25519SignatureDepB where
  get = do
    _msgEd25519SignatureDepB_stream_counter <- getWord8
    _msgEd25519SignatureDepB_on_demand_counter <- getWord8
    _msgEd25519SignatureDepB_signature <- replicateM 64 getWord8
    _msgEd25519SignatureDepB_fingerprint <- replicateM 20 getWord8
    _msgEd25519SignatureDepB_signed_messages <- whileM (not <$> isEmpty) getWord32le
    pure MsgEd25519SignatureDepB {..}

  put MsgEd25519SignatureDepB {..} = do
    putWord8 _msgEd25519SignatureDepB_stream_counter
    putWord8 _msgEd25519SignatureDepB_on_demand_counter
    mapM_ putWord8 _msgEd25519SignatureDepB_signature
    mapM_ putWord8 _msgEd25519SignatureDepB_fingerprint
    mapM_ putWord32le _msgEd25519SignatureDepB_signed_messages

$(makeSBP 'msgEd25519SignatureDepB ''MsgEd25519SignatureDepB)
$(makeJSON "_msgEd25519SignatureDepB_" ''MsgEd25519SignatureDepB)
$(makeLenses ''MsgEd25519SignatureDepB)
