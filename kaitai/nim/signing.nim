import kaitai_struct_nim_runtime
import options

type
  Signing* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Signing_MsgEd25519SignatureDepB* = ref object of KaitaiStruct
    `streamCounter`*: uint8
    `onDemandCounter`*: uint8
    `signature`*: seq[uint8]
    `fingerprint`*: seq[uint8]
    `signedMessages`*: seq[uint32]
    `parent`*: Sbp_Message
  Signing_MsgEd25519CertificateDep* = ref object of KaitaiStruct
    `nMsg`*: uint8
    `fingerprint`*: seq[uint8]
    `certificateBytes`*: seq[uint8]
    `parent`*: Sbp_Message
  Signing_UtcTime* = ref object of KaitaiStruct
    `year`*: uint16
    `month`*: uint8
    `day`*: uint8
    `hours`*: uint8
    `minutes`*: uint8
    `seconds`*: uint8
    `ns`*: uint32
    `parent`*: Signing_MsgCertificateChain
  Signing_MsgEd25519SignatureDepA* = ref object of KaitaiStruct
    `signature`*: seq[uint8]
    `fingerprint`*: seq[uint8]
    `signedMessages`*: seq[uint32]
    `parent`*: Sbp_Message
  Signing_MsgCertificateChain* = ref object of KaitaiStruct
    `rootCertificate`*: seq[uint8]
    `intermediateCertificate`*: seq[uint8]
    `correctionsCertificate`*: seq[uint8]
    `expiration`*: Signing_UtcTime
    `signature`*: seq[uint8]
    `parent`*: Sbp_Message
  Signing_MsgEcdsaCertificate* = ref object of KaitaiStruct
    `nMsg`*: uint8
    `certificateId`*: seq[uint8]
    `flags`*: uint8
    `certificateBytes`*: seq[uint8]
    `parent`*: Sbp_Message
  Signing_MsgEcdsaSignature* = ref object of KaitaiStruct
    `flags`*: uint8
    `streamCounter`*: uint8
    `onDemandCounter`*: uint8
    `certificateId`*: seq[uint8]
    `signature`*: seq[uint8]
    `signedMessages`*: seq[uint8]
    `parent`*: Sbp_Message

proc read*(_: typedesc[Signing], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Signing
proc read*(_: typedesc[Signing_MsgEd25519SignatureDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Signing_MsgEd25519SignatureDepB
proc read*(_: typedesc[Signing_MsgEd25519CertificateDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Signing_MsgEd25519CertificateDep
proc read*(_: typedesc[Signing_UtcTime], io: KaitaiStream, root: KaitaiStruct, parent: Signing_MsgCertificateChain): Signing_UtcTime
proc read*(_: typedesc[Signing_MsgEd25519SignatureDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Signing_MsgEd25519SignatureDepA
proc read*(_: typedesc[Signing_MsgCertificateChain], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Signing_MsgCertificateChain
proc read*(_: typedesc[Signing_MsgEcdsaCertificate], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Signing_MsgEcdsaCertificate
proc read*(_: typedesc[Signing_MsgEcdsaSignature], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Signing_MsgEcdsaSignature


proc read*(_: typedesc[Signing], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Signing =
  template this: untyped = result
  this = new(Signing)
  let root = if root == nil: cast[Signing](this) else: cast[Signing](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Signing], filename: string): Signing =
  Signing.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Signing_MsgEd25519SignatureDepB], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Signing_MsgEd25519SignatureDepB =
  template this: untyped = result
  this = new(Signing_MsgEd25519SignatureDepB)
  let root = if root == nil: cast[Signing](this) else: cast[Signing](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Signature message counter. Zero indexed and incremented with each
signature message.  The counter will not increment if this message
was in response to an on demand request.  The counter will roll over
after 256 messages. Upon connection, the value of the counter may
not initially be zero.

  ]##
  let streamCounterExpr = this.io.readU1()
  this.streamCounter = streamCounterExpr

  ##[
  On demand message counter. Zero indexed and incremented with each
signature message sent in response to an on demand message. The
counter will roll over after 256 messages.  Upon connection, the
value of the counter may not initially be zero.

  ]##
  let onDemandCounterExpr = this.io.readU1()
  this.onDemandCounter = onDemandCounterExpr

  ##[
  ED25519 signature for messages.

  ]##
  for i in 0 ..< int(64):
    let it = this.io.readU1()
    this.signature.add(it)

  ##[
  SHA-1 fingerprint of the associated certificate.

  ]##
  for i in 0 ..< int(20):
    let it = this.io.readU1()
    this.fingerprint.add(it)

  ##[
  CRCs of signed messages.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU4le()
      this.signedMessages.add(it)
      inc i

proc fromFile*(_: typedesc[Signing_MsgEd25519SignatureDepB], filename: string): Signing_MsgEd25519SignatureDepB =
  Signing_MsgEd25519SignatureDepB.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Signing_MsgEd25519CertificateDep], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Signing_MsgEd25519CertificateDep =
  template this: untyped = result
  this = new(Signing_MsgEd25519CertificateDep)
  let root = if root == nil: cast[Signing](this) else: cast[Signing](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Total number messages that make up the certificate. First nibble is
the size of the sequence (n), second nibble is the zero-indexed
counter (ith packet of n)

  ]##
  let nMsgExpr = this.io.readU1()
  this.nMsg = nMsgExpr

  ##[
  SHA-1 fingerprint of the associated certificate.

  ]##
  for i in 0 ..< int(20):
    let it = this.io.readU1()
    this.fingerprint.add(it)

  ##[
  ED25519 certificate bytes.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU1()
      this.certificateBytes.add(it)
      inc i

proc fromFile*(_: typedesc[Signing_MsgEd25519CertificateDep], filename: string): Signing_MsgEd25519CertificateDep =
  Signing_MsgEd25519CertificateDep.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Signing_UtcTime], io: KaitaiStream, root: KaitaiStruct, parent: Signing_MsgCertificateChain): Signing_UtcTime =
  template this: untyped = result
  this = new(Signing_UtcTime)
  let root = if root == nil: cast[Signing](this) else: cast[Signing](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Year

  ]##
  let yearExpr = this.io.readU2le()
  this.year = yearExpr

  ##[
  Month (range 1 .. 12)

  ]##
  let monthExpr = this.io.readU1()
  this.month = monthExpr

  ##[
  days in the month (range 1-31)

  ]##
  let dayExpr = this.io.readU1()
  this.day = dayExpr

  ##[
  hours of day (range 0-23)

  ]##
  let hoursExpr = this.io.readU1()
  this.hours = hoursExpr

  ##[
  minutes of hour (range 0-59)

  ]##
  let minutesExpr = this.io.readU1()
  this.minutes = minutesExpr

  ##[
  seconds of minute (range 0-60) rounded down

  ]##
  let secondsExpr = this.io.readU1()
  this.seconds = secondsExpr

  ##[
  nanoseconds of second (range 0-999999999)

  ]##
  let nsExpr = this.io.readU4le()
  this.ns = nsExpr

proc fromFile*(_: typedesc[Signing_UtcTime], filename: string): Signing_UtcTime =
  Signing_UtcTime.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Signing_MsgEd25519SignatureDepA], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Signing_MsgEd25519SignatureDepA =
  template this: untyped = result
  this = new(Signing_MsgEd25519SignatureDepA)
  let root = if root == nil: cast[Signing](this) else: cast[Signing](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  ED25519 signature for messages.

  ]##
  for i in 0 ..< int(64):
    let it = this.io.readU1()
    this.signature.add(it)

  ##[
  SHA-1 fingerprint of the associated certificate.

  ]##
  for i in 0 ..< int(20):
    let it = this.io.readU1()
    this.fingerprint.add(it)

  ##[
  CRCs of signed messages.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU4le()
      this.signedMessages.add(it)
      inc i

proc fromFile*(_: typedesc[Signing_MsgEd25519SignatureDepA], filename: string): Signing_MsgEd25519SignatureDepA =
  Signing_MsgEd25519SignatureDepA.read(newKaitaiFileStream(filename), nil, nil)

proc read*(_: typedesc[Signing_MsgCertificateChain], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Signing_MsgCertificateChain =
  template this: untyped = result
  this = new(Signing_MsgCertificateChain)
  let root = if root == nil: cast[Signing](this) else: cast[Signing](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  SHA-1 fingerprint of the root certificate

  ]##
  for i in 0 ..< int(20):
    let it = this.io.readU1()
    this.rootCertificate.add(it)

  ##[
  SHA-1 fingerprint of the intermediate certificate

  ]##
  for i in 0 ..< int(20):
    let it = this.io.readU1()
    this.intermediateCertificate.add(it)

  ##[
  SHA-1 fingerprint of the corrections certificate

  ]##
  for i in 0 ..< int(20):
    let it = this.io.readU1()
    this.correctionsCertificate.add(it)

  ##[
  The certificate chain comprised of three fingerprints: root
certificate, intermediate certificate and corrections certificate.

  ]##
  let expirationExpr = Signing_UtcTime.read(this.io, this.root, this)
  this.expiration = expirationExpr

  ##[
  An ECDSA signature (created by the root certificate) over the
concatenation of the SBP payload bytes preceding this field. That
is, the concatenation of `root_certificate`,
`intermediate_certificate`, `corrections_certificate` and
`expiration`.  This certificate chain (allow list) can also be
validated by fetching it from `http(s)://certs.swiftnav.com/chain`.

  ]##
  for i in 0 ..< int(64):
    let it = this.io.readU1()
    this.signature.add(it)

proc fromFile*(_: typedesc[Signing_MsgCertificateChain], filename: string): Signing_MsgCertificateChain =
  Signing_MsgCertificateChain.read(newKaitaiFileStream(filename), nil, nil)


##[
A DER encoded x.509 ECDSA-256 certificate (using curve secp256r1).

]##
proc read*(_: typedesc[Signing_MsgEcdsaCertificate], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Signing_MsgEcdsaCertificate =
  template this: untyped = result
  this = new(Signing_MsgEcdsaCertificate)
  let root = if root == nil: cast[Signing](this) else: cast[Signing](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Total number messages that make up the certificate. The first nibble
(mask 0xF0 or left shifted by 4 bits) is the size of the sequence
(n), second nibble (mask 0x0F) is the zero-indexed counter (ith
packet of n).

  ]##
  let nMsgExpr = this.io.readU1()
  this.nMsg = nMsgExpr

  ##[
  The last 4 bytes of the certificate's SHA-1 fingerprint

  ]##
  for i in 0 ..< int(4):
    let it = this.io.readU1()
    this.certificateId.add(it)
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

  ##[
  DER encoded x.509 ECDSA certificate bytes

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU1()
      this.certificateBytes.add(it)
      inc i

proc fromFile*(_: typedesc[Signing_MsgEcdsaCertificate], filename: string): Signing_MsgEcdsaCertificate =
  Signing_MsgEcdsaCertificate.read(newKaitaiFileStream(filename), nil, nil)


##[
An ECDSA-256 signature using SHA-256 as the message digest algorithm.

]##
proc read*(_: typedesc[Signing_MsgEcdsaSignature], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Signing_MsgEcdsaSignature =
  template this: untyped = result
  this = new(Signing_MsgEcdsaSignature)
  let root = if root == nil: cast[Signing](this) else: cast[Signing](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Describes the format of the `signed\_messages` field below.

  ]##
  let flagsExpr = this.io.readU1()
  this.flags = flagsExpr

  ##[
  Signature message counter. Zero indexed and incremented with each
signature message.  The counter will not increment if this message
was in response to an on demand request.  The counter will roll over
after 256 messages. Upon connection, the value of the counter may
not initially be zero.

  ]##
  let streamCounterExpr = this.io.readU1()
  this.streamCounter = streamCounterExpr

  ##[
  On demand message counter. Zero indexed and incremented with each
signature message sent in response to an on demand message. The
counter will roll over after 256 messages.  Upon connection, the
value of the counter may not initially be zero.

  ]##
  let onDemandCounterExpr = this.io.readU1()
  this.onDemandCounter = onDemandCounterExpr

  ##[
  The last 4 bytes of the certificate's SHA-1 fingerprint

  ]##
  for i in 0 ..< int(4):
    let it = this.io.readU1()
    this.certificateId.add(it)

  ##[
  ECDSA signature for the messages using SHA-256 as the digest
algorithm.

  ]##
  for i in 0 ..< int(64):
    let it = this.io.readU1()
    this.signature.add(it)

  ##[
  CRCs of the messages covered by this signature.  For Skylark, which
delivers SBP messages wrapped in Swift's proprietary RTCM message,
these are the 24-bit CRCs from the RTCM message framing. For SBP
only streams, this will be 16-bit CRCs from the SBP framing.  See
the `flags` field to determine the type of CRCs covered.

  ]##
  block:
    var i: int
    while not this.io.isEof:
      let it = this.io.readU1()
      this.signedMessages.add(it)
      inc i

proc fromFile*(_: typedesc[Signing_MsgEcdsaSignature], filename: string): Signing_MsgEcdsaSignature =
  Signing_MsgEcdsaSignature.read(newKaitaiFileStream(filename), nil, nil)

