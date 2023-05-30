-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

Signing = class.class(KaitaiStruct)

function Signing:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Signing:_read()
end


Signing.MsgEd25519SignatureDepB = class.class(KaitaiStruct)

function Signing.MsgEd25519SignatureDepB:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Signing.MsgEd25519SignatureDepB:_read()
  self.stream_counter = self._io:read_u1()
  self.on_demand_counter = self._io:read_u1()
  self.signature = {}
  for i = 0, 64 - 1 do
    self.signature[i + 1] = self._io:read_u1()
  end
  self.fingerprint = {}
  for i = 0, 20 - 1 do
    self.fingerprint[i + 1] = self._io:read_u1()
  end
  self.signed_messages = {}
  local i = 0
  while not self._io:is_eof() do
    self.signed_messages[i + 1] = self._io:read_u4le()
    i = i + 1
  end
end

-- 
-- Signature message counter. Zero indexed and incremented with each
-- signature message.  The counter will not increment if this message
-- was in response to an on demand request.  The counter will roll over
-- after 256 messages. Upon connection, the value of the counter may
-- not initially be zero.
-- 
-- On demand message counter. Zero indexed and incremented with each
-- signature message sent in response to an on demand message. The
-- counter will roll over after 256 messages.  Upon connection, the
-- value of the counter may not initially be zero.
-- 
-- ED25519 signature for messages.
-- 
-- SHA-1 fingerprint of the associated certificate.
-- 
-- CRCs of signed messages.

Signing.MsgEd25519CertificateDep = class.class(KaitaiStruct)

function Signing.MsgEd25519CertificateDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Signing.MsgEd25519CertificateDep:_read()
  self.n_msg = self._io:read_u1()
  self.fingerprint = {}
  for i = 0, 20 - 1 do
    self.fingerprint[i + 1] = self._io:read_u1()
  end
  self.certificate_bytes = {}
  local i = 0
  while not self._io:is_eof() do
    self.certificate_bytes[i + 1] = self._io:read_u1()
    i = i + 1
  end
end

-- 
-- Total number messages that make up the certificate. First nibble is
-- the size of the sequence (n), second nibble is the zero-indexed
-- counter (ith packet of n)
-- 
-- SHA-1 fingerprint of the associated certificate.
-- 
-- ED25519 certificate bytes.

Signing.UtcTime = class.class(KaitaiStruct)

function Signing.UtcTime:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Signing.UtcTime:_read()
  self.year = self._io:read_u2le()
  self.month = self._io:read_u1()
  self.day = self._io:read_u1()
  self.hours = self._io:read_u1()
  self.minutes = self._io:read_u1()
  self.seconds = self._io:read_u1()
  self.ns = self._io:read_u4le()
end

-- 
-- Year
-- 
-- Month (range 1 .. 12)
-- 
-- days in the month (range 1-31)
-- 
-- hours of day (range 0-23)
-- 
-- minutes of hour (range 0-59)
-- 
-- seconds of minute (range 0-60) rounded down
-- 
-- nanoseconds of second (range 0-999999999)

Signing.MsgEd25519SignatureDepA = class.class(KaitaiStruct)

function Signing.MsgEd25519SignatureDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Signing.MsgEd25519SignatureDepA:_read()
  self.signature = {}
  for i = 0, 64 - 1 do
    self.signature[i + 1] = self._io:read_u1()
  end
  self.fingerprint = {}
  for i = 0, 20 - 1 do
    self.fingerprint[i + 1] = self._io:read_u1()
  end
  self.signed_messages = {}
  local i = 0
  while not self._io:is_eof() do
    self.signed_messages[i + 1] = self._io:read_u4le()
    i = i + 1
  end
end

-- 
-- ED25519 signature for messages.
-- 
-- SHA-1 fingerprint of the associated certificate.
-- 
-- CRCs of signed messages.

Signing.MsgCertificateChain = class.class(KaitaiStruct)

function Signing.MsgCertificateChain:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Signing.MsgCertificateChain:_read()
  self.root_certificate = {}
  for i = 0, 20 - 1 do
    self.root_certificate[i + 1] = self._io:read_u1()
  end
  self.intermediate_certificate = {}
  for i = 0, 20 - 1 do
    self.intermediate_certificate[i + 1] = self._io:read_u1()
  end
  self.corrections_certificate = {}
  for i = 0, 20 - 1 do
    self.corrections_certificate[i + 1] = self._io:read_u1()
  end
  self.expiration = Signing.UtcTime(self._io, self, self._root)
  self.signature = {}
  for i = 0, 64 - 1 do
    self.signature[i + 1] = self._io:read_u1()
  end
end

-- 
-- SHA-1 fingerprint of the root certificate
-- 
-- SHA-1 fingerprint of the intermediate certificate
-- 
-- SHA-1 fingerprint of the corrections certificate
-- 
-- The certificate chain comprised of three fingerprints: root
-- certificate, intermediate certificate and corrections certificate.
-- 
-- An ECDSA signature (created by the root certificate) over the
-- concatenation of the SBP payload bytes preceding this field. That
-- is, the concatenation of `root_certificate`,
-- `intermediate_certificate`, `corrections_certificate` and
-- `expiration`.  This certificate chain (allow list) can also be
-- validated by fetching it from `http(s)://certs.swiftnav.com/chain`.

-- 
-- A DER encoded x.509 ECDSA-256 certificate (using curve secp256r1).
Signing.MsgEcdsaCertificate = class.class(KaitaiStruct)

function Signing.MsgEcdsaCertificate:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Signing.MsgEcdsaCertificate:_read()
  self.n_msg = self._io:read_u1()
  self.certificate_id = {}
  for i = 0, 4 - 1 do
    self.certificate_id[i + 1] = self._io:read_u1()
  end
  self.flags = self._io:read_u1()
  self.certificate_bytes = {}
  local i = 0
  while not self._io:is_eof() do
    self.certificate_bytes[i + 1] = self._io:read_u1()
    i = i + 1
  end
end

-- 
-- Total number messages that make up the certificate. The first nibble
-- (mask 0xF0 or left shifted by 4 bits) is the size of the sequence
-- (n), second nibble (mask 0x0F) is the zero-indexed counter (ith
-- packet of n).
-- 
-- The last 4 bytes of the certificate's SHA-1 fingerprint
-- 
-- DER encoded x.509 ECDSA certificate bytes

-- 
-- An ECDSA-256 signature using SHA-256 as the message digest algorithm.
Signing.MsgEcdsaSignature = class.class(KaitaiStruct)

function Signing.MsgEcdsaSignature:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Signing.MsgEcdsaSignature:_read()
  self.flags = self._io:read_u1()
  self.stream_counter = self._io:read_u1()
  self.on_demand_counter = self._io:read_u1()
  self.certificate_id = {}
  for i = 0, 4 - 1 do
    self.certificate_id[i + 1] = self._io:read_u1()
  end
  self.signature = {}
  for i = 0, 64 - 1 do
    self.signature[i + 1] = self._io:read_u1()
  end
  self.signed_messages = {}
  local i = 0
  while not self._io:is_eof() do
    self.signed_messages[i + 1] = self._io:read_u1()
    i = i + 1
  end
end

-- 
-- Describes the format of the `signed\_messages` field below.
-- 
-- Signature message counter. Zero indexed and incremented with each
-- signature message.  The counter will not increment if this message
-- was in response to an on demand request.  The counter will roll over
-- after 256 messages. Upon connection, the value of the counter may
-- not initially be zero.
-- 
-- On demand message counter. Zero indexed and incremented with each
-- signature message sent in response to an on demand message. The
-- counter will roll over after 256 messages.  Upon connection, the
-- value of the counter may not initially be zero.
-- 
-- The last 4 bytes of the certificate's SHA-1 fingerprint
-- 
-- ECDSA signature for the messages using SHA-256 as the digest
-- algorithm.
-- 
-- CRCs of the messages covered by this signature.  For Skylark, which
-- delivers SBP messages wrapped in Swift's proprietary RTCM message,
-- these are the 24-bit CRCs from the RTCM message framing. For SBP
-- only streams, this will be 16-bit CRCs from the SBP framing.  See
-- the `flags` field to determine the type of CRCs covered.

