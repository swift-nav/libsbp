/**
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/**********************
 * Automatically generated from spec/yaml/swiftnav/sbp/signing.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages relating to signatures
***********************/

let SBP = require('./sbp');
let Parser = require('./parser');
let Int64 = require('node-int64');
let UInt64 = require('cuint').UINT64;

/**
 * SBP class for message fragment UtcTime
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field year number (unsigned 16-bit int, 2 bytes) Year
 * @field month number (unsigned 8-bit int, 1 byte) Month (range 1 .. 12)
 * @field day number (unsigned 8-bit int, 1 byte) days in the month (range 1-31)
 * @field hours number (unsigned 8-bit int, 1 byte) hours of day (range 0-23)
 * @field minutes number (unsigned 8-bit int, 1 byte) minutes of hour (range 0-59)
 * @field seconds number (unsigned 8-bit int, 1 byte) seconds of minute (range 0-60) rounded down
 * @field ns number (unsigned 32-bit int, 4 bytes) nanoseconds of second (range 0-999999999)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let UtcTime = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "UtcTime";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
UtcTime.prototype = Object.create(SBP.prototype);
UtcTime.prototype.messageType = "UtcTime";
UtcTime.prototype.constructor = UtcTime;
UtcTime.prototype.parser = new Parser()
  .endianess('little')
  .uint16('year')
  .uint8('month')
  .uint8('day')
  .uint8('hours')
  .uint8('minutes')
  .uint8('seconds')
  .uint32('ns');
UtcTime.prototype.fieldSpec = [];
UtcTime.prototype.fieldSpec.push(['year', 'writeUInt16LE', 2]);
UtcTime.prototype.fieldSpec.push(['month', 'writeUInt8', 1]);
UtcTime.prototype.fieldSpec.push(['day', 'writeUInt8', 1]);
UtcTime.prototype.fieldSpec.push(['hours', 'writeUInt8', 1]);
UtcTime.prototype.fieldSpec.push(['minutes', 'writeUInt8', 1]);
UtcTime.prototype.fieldSpec.push(['seconds', 'writeUInt8', 1]);
UtcTime.prototype.fieldSpec.push(['ns', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_ECDSA_CERTIFICATE (0x0C04).
 *
 * A DER encoded x.509 ECDSA-256 certificate (using curve secp256r1).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field n_msg number (unsigned 8-bit int, 1 byte) Total number messages that make up the certificate. The first nibble (mask 0xF0
 *   or left shifted by 4 bits) is the size of the sequence (n), second nibble (mask
 *   0x0F) is the zero-indexed counter (ith packet of n).
 * @field certificate_id array The last 4 bytes of the certificate's SHA-1 fingerprint
 * @field flags number (unsigned 8-bit int, 1 byte)
 * @field certificate_bytes array DER encoded x.509 ECDSA certificate bytes
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgEcdsaCertificate = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ECDSA_CERTIFICATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEcdsaCertificate.prototype = Object.create(SBP.prototype);
MsgEcdsaCertificate.prototype.messageType = "MSG_ECDSA_CERTIFICATE";
MsgEcdsaCertificate.prototype.msg_type = 0x0C04;
MsgEcdsaCertificate.prototype.constructor = MsgEcdsaCertificate;
MsgEcdsaCertificate.prototype.parser = new Parser()
  .endianess('little')
  .uint8('n_msg')
  .array('certificate_id', { length: 4, type: 'uint8' })
  .uint8('flags')
  .array('certificate_bytes', { type: 'uint8', readUntil: 'eof' });
MsgEcdsaCertificate.prototype.fieldSpec = [];
MsgEcdsaCertificate.prototype.fieldSpec.push(['n_msg', 'writeUInt8', 1]);
MsgEcdsaCertificate.prototype.fieldSpec.push(['certificate_id', 'array', 'writeUInt8', function () { return 1; }, 4]);
MsgEcdsaCertificate.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);
MsgEcdsaCertificate.prototype.fieldSpec.push(['certificate_bytes', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_CERTIFICATE_CHAIN (0x0C05).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field root_certificate array SHA-1 fingerprint of the root certificate
 * @field intermediate_certificate array SHA-1 fingerprint of the intermediate certificate
 * @field corrections_certificate array SHA-1 fingerprint of the corrections certificate
 * @field expiration UtcTime The certificate chain comprised of three fingerprints: root certificate,
 *   intermediate certificate and corrections certificate.
 * @field signature array An ECDSA signature (created by the root certificate) over the concatenation of
 *   the SBP payload bytes preceding this field. That is, the concatenation of
 *   `root_certificate`, `intermediate_certificate`, `corrections_certificate` and
 *   `expiration`.  This certificate chain (allow list) can also be validated by
 *   fetching it from `http(s)://certs.swiftnav.com/chain`.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgCertificateChain = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_CERTIFICATE_CHAIN";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgCertificateChain.prototype = Object.create(SBP.prototype);
MsgCertificateChain.prototype.messageType = "MSG_CERTIFICATE_CHAIN";
MsgCertificateChain.prototype.msg_type = 0x0C05;
MsgCertificateChain.prototype.constructor = MsgCertificateChain;
MsgCertificateChain.prototype.parser = new Parser()
  .endianess('little')
  .array('root_certificate', { length: 20, type: 'uint8' })
  .array('intermediate_certificate', { length: 20, type: 'uint8' })
  .array('corrections_certificate', { length: 20, type: 'uint8' })
  .nest('expiration', { type: UtcTime.prototype.parser })
  .array('signature', { length: 64, type: 'uint8' });
MsgCertificateChain.prototype.fieldSpec = [];
MsgCertificateChain.prototype.fieldSpec.push(['root_certificate', 'array', 'writeUInt8', function () { return 1; }, 20]);
MsgCertificateChain.prototype.fieldSpec.push(['intermediate_certificate', 'array', 'writeUInt8', function () { return 1; }, 20]);
MsgCertificateChain.prototype.fieldSpec.push(['corrections_certificate', 'array', 'writeUInt8', function () { return 1; }, 20]);
MsgCertificateChain.prototype.fieldSpec.push(['expiration', UtcTime.prototype.fieldSpec]);
MsgCertificateChain.prototype.fieldSpec.push(['signature', 'array', 'writeUInt8', function () { return 1; }, 64]);

/**
 * SBP class for message MSG_ECDSA_SIGNATURE (0x0C07).
 *
 * An ECDSA-256 signature using SHA-256 as the message digest algorithm.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field flags number (unsigned 8-bit int, 1 byte) Describes the format of the `signed\_messages` field below.
 * @field stream_counter number (unsigned 8-bit int, 1 byte) Signature message counter. Zero indexed and incremented with each signature
 *   message.  The counter will not increment if this message was in response to an
 *   on demand request.  The counter will roll over after 256 messages. Upon
 *   connection, the value of the counter may not initially be zero.
 * @field on_demand_counter number (unsigned 8-bit int, 1 byte) On demand message counter. Zero indexed and incremented with each signature
 *   message sent in response to an on demand message. The counter will roll over
 *   after 256 messages.  Upon connection, the value of the counter may not initially
 *   be zero.
 * @field certificate_id array The last 4 bytes of the certificate's SHA-1 fingerprint
 * @field n_signature_bytes number (unsigned 8-bit int, 1 byte) Number of bytes to use of the signature field.
 * @field signature array DER encoded ECDSA signature for the messages using SHA-256 as the digest
 *   algorithm.
 * @field signed_messages array CRCs of the messages covered by this signature.  For Skylark, which delivers SBP
 *   messages wrapped in Swift's proprietary RTCM message, these are the 24-bit CRCs
 *   from the RTCM message framing. For SBP only streams, this will be 16-bit CRCs
 *   from the SBP framing.  See the `flags` field to determine the type of CRCs
 *   covered.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgEcdsaSignature = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ECDSA_SIGNATURE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEcdsaSignature.prototype = Object.create(SBP.prototype);
MsgEcdsaSignature.prototype.messageType = "MSG_ECDSA_SIGNATURE";
MsgEcdsaSignature.prototype.msg_type = 0x0C07;
MsgEcdsaSignature.prototype.constructor = MsgEcdsaSignature;
MsgEcdsaSignature.prototype.parser = new Parser()
  .endianess('little')
  .uint8('flags')
  .uint8('stream_counter')
  .uint8('on_demand_counter')
  .array('certificate_id', { length: 4, type: 'uint8' })
  .uint8('n_signature_bytes')
  .array('signature', { length: 72, type: 'uint8' })
  .array('signed_messages', { type: 'uint8', readUntil: 'eof' });
MsgEcdsaSignature.prototype.fieldSpec = [];
MsgEcdsaSignature.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);
MsgEcdsaSignature.prototype.fieldSpec.push(['stream_counter', 'writeUInt8', 1]);
MsgEcdsaSignature.prototype.fieldSpec.push(['on_demand_counter', 'writeUInt8', 1]);
MsgEcdsaSignature.prototype.fieldSpec.push(['certificate_id', 'array', 'writeUInt8', function () { return 1; }, 4]);
MsgEcdsaSignature.prototype.fieldSpec.push(['n_signature_bytes', 'writeUInt8', 1]);
MsgEcdsaSignature.prototype.fieldSpec.push(['signature', 'array', 'writeUInt8', function () { return 1; }, 72]);
MsgEcdsaSignature.prototype.fieldSpec.push(['signed_messages', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_ECDSA_SIGNATURE_DEP (0x0C06).
 *
 * An ECDSA-256 signature using SHA-256 as the message digest algorithm.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field flags number (unsigned 8-bit int, 1 byte) Describes the format of the `signed\_messages` field below.
 * @field stream_counter number (unsigned 8-bit int, 1 byte) Signature message counter. Zero indexed and incremented with each signature
 *   message.  The counter will not increment if this message was in response to an
 *   on demand request.  The counter will roll over after 256 messages. Upon
 *   connection, the value of the counter may not initially be zero.
 * @field on_demand_counter number (unsigned 8-bit int, 1 byte) On demand message counter. Zero indexed and incremented with each signature
 *   message sent in response to an on demand message. The counter will roll over
 *   after 256 messages.  Upon connection, the value of the counter may not initially
 *   be zero.
 * @field certificate_id array The last 4 bytes of the certificate's SHA-1 fingerprint
 * @field signature array ECDSA signature for the messages using SHA-256 as the digest algorithm.
 * @field signed_messages array CRCs of the messages covered by this signature.  For Skylark, which delivers SBP
 *   messages wrapped in Swift's proprietary RTCM message, these are the 24-bit CRCs
 *   from the RTCM message framing. For SBP only streams, this will be 16-bit CRCs
 *   from the SBP framing.  See the `flags` field to determine the type of CRCs
 *   covered.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgEcdsaSignatureDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ECDSA_SIGNATURE_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEcdsaSignatureDep.prototype = Object.create(SBP.prototype);
MsgEcdsaSignatureDep.prototype.messageType = "MSG_ECDSA_SIGNATURE_DEP";
MsgEcdsaSignatureDep.prototype.msg_type = 0x0C06;
MsgEcdsaSignatureDep.prototype.constructor = MsgEcdsaSignatureDep;
MsgEcdsaSignatureDep.prototype.parser = new Parser()
  .endianess('little')
  .uint8('flags')
  .uint8('stream_counter')
  .uint8('on_demand_counter')
  .array('certificate_id', { length: 4, type: 'uint8' })
  .array('signature', { length: 64, type: 'uint8' })
  .array('signed_messages', { type: 'uint8', readUntil: 'eof' });
MsgEcdsaSignatureDep.prototype.fieldSpec = [];
MsgEcdsaSignatureDep.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);
MsgEcdsaSignatureDep.prototype.fieldSpec.push(['stream_counter', 'writeUInt8', 1]);
MsgEcdsaSignatureDep.prototype.fieldSpec.push(['on_demand_counter', 'writeUInt8', 1]);
MsgEcdsaSignatureDep.prototype.fieldSpec.push(['certificate_id', 'array', 'writeUInt8', function () { return 1; }, 4]);
MsgEcdsaSignatureDep.prototype.fieldSpec.push(['signature', 'array', 'writeUInt8', function () { return 1; }, 64]);
MsgEcdsaSignatureDep.prototype.fieldSpec.push(['signed_messages', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_ED25519_CERTIFICATE_DEP (0x0C02).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field n_msg number (unsigned 8-bit int, 1 byte) Total number messages that make up the certificate. First nibble is the size of
 *   the sequence (n), second nibble is the zero-indexed counter (ith packet of n)
 * @field fingerprint array SHA-1 fingerprint of the associated certificate.
 * @field certificate_bytes array ED25519 certificate bytes.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgEd25519CertificateDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ED25519_CERTIFICATE_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEd25519CertificateDep.prototype = Object.create(SBP.prototype);
MsgEd25519CertificateDep.prototype.messageType = "MSG_ED25519_CERTIFICATE_DEP";
MsgEd25519CertificateDep.prototype.msg_type = 0x0C02;
MsgEd25519CertificateDep.prototype.constructor = MsgEd25519CertificateDep;
MsgEd25519CertificateDep.prototype.parser = new Parser()
  .endianess('little')
  .uint8('n_msg')
  .array('fingerprint', { length: 20, type: 'uint8' })
  .array('certificate_bytes', { type: 'uint8', readUntil: 'eof' });
MsgEd25519CertificateDep.prototype.fieldSpec = [];
MsgEd25519CertificateDep.prototype.fieldSpec.push(['n_msg', 'writeUInt8', 1]);
MsgEd25519CertificateDep.prototype.fieldSpec.push(['fingerprint', 'array', 'writeUInt8', function () { return 1; }, 20]);
MsgEd25519CertificateDep.prototype.fieldSpec.push(['certificate_bytes', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_ED25519_SIGNATURE_DEP_A (0x0C01).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field signature array ED25519 signature for messages.
 * @field fingerprint array SHA-1 fingerprint of the associated certificate.
 * @field signed_messages array CRCs of signed messages.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgEd25519SignatureDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ED25519_SIGNATURE_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEd25519SignatureDepA.prototype = Object.create(SBP.prototype);
MsgEd25519SignatureDepA.prototype.messageType = "MSG_ED25519_SIGNATURE_DEP_A";
MsgEd25519SignatureDepA.prototype.msg_type = 0x0C01;
MsgEd25519SignatureDepA.prototype.constructor = MsgEd25519SignatureDepA;
MsgEd25519SignatureDepA.prototype.parser = new Parser()
  .endianess('little')
  .array('signature', { length: 64, type: 'uint8' })
  .array('fingerprint', { length: 20, type: 'uint8' })
  .array('signed_messages', { type: 'uint32le', readUntil: 'eof' });
MsgEd25519SignatureDepA.prototype.fieldSpec = [];
MsgEd25519SignatureDepA.prototype.fieldSpec.push(['signature', 'array', 'writeUInt8', function () { return 1; }, 64]);
MsgEd25519SignatureDepA.prototype.fieldSpec.push(['fingerprint', 'array', 'writeUInt8', function () { return 1; }, 20]);
MsgEd25519SignatureDepA.prototype.fieldSpec.push(['signed_messages', 'array', 'writeUInt32LE', function () { return 4; }, null]);

/**
 * SBP class for message MSG_ED25519_SIGNATURE_DEP_B (0x0C03).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field stream_counter number (unsigned 8-bit int, 1 byte) Signature message counter. Zero indexed and incremented with each signature
 *   message.  The counter will not increment if this message was in response to an
 *   on demand request.  The counter will roll over after 256 messages. Upon
 *   connection, the value of the counter may not initially be zero.
 * @field on_demand_counter number (unsigned 8-bit int, 1 byte) On demand message counter. Zero indexed and incremented with each signature
 *   message sent in response to an on demand message. The counter will roll over
 *   after 256 messages.  Upon connection, the value of the counter may not initially
 *   be zero.
 * @field signature array ED25519 signature for messages.
 * @field fingerprint array SHA-1 fingerprint of the associated certificate.
 * @field signed_messages array CRCs of signed messages.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgEd25519SignatureDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ED25519_SIGNATURE_DEP_B";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEd25519SignatureDepB.prototype = Object.create(SBP.prototype);
MsgEd25519SignatureDepB.prototype.messageType = "MSG_ED25519_SIGNATURE_DEP_B";
MsgEd25519SignatureDepB.prototype.msg_type = 0x0C03;
MsgEd25519SignatureDepB.prototype.constructor = MsgEd25519SignatureDepB;
MsgEd25519SignatureDepB.prototype.parser = new Parser()
  .endianess('little')
  .uint8('stream_counter')
  .uint8('on_demand_counter')
  .array('signature', { length: 64, type: 'uint8' })
  .array('fingerprint', { length: 20, type: 'uint8' })
  .array('signed_messages', { type: 'uint32le', readUntil: 'eof' });
MsgEd25519SignatureDepB.prototype.fieldSpec = [];
MsgEd25519SignatureDepB.prototype.fieldSpec.push(['stream_counter', 'writeUInt8', 1]);
MsgEd25519SignatureDepB.prototype.fieldSpec.push(['on_demand_counter', 'writeUInt8', 1]);
MsgEd25519SignatureDepB.prototype.fieldSpec.push(['signature', 'array', 'writeUInt8', function () { return 1; }, 64]);
MsgEd25519SignatureDepB.prototype.fieldSpec.push(['fingerprint', 'array', 'writeUInt8', function () { return 1; }, 20]);
MsgEd25519SignatureDepB.prototype.fieldSpec.push(['signed_messages', 'array', 'writeUInt32LE', function () { return 4; }, null]);

module.exports = {
  UtcTime: UtcTime,
  0x0C04: MsgEcdsaCertificate,
  MsgEcdsaCertificate: MsgEcdsaCertificate,
  0x0C05: MsgCertificateChain,
  MsgCertificateChain: MsgCertificateChain,
  0x0C07: MsgEcdsaSignature,
  MsgEcdsaSignature: MsgEcdsaSignature,
  0x0C06: MsgEcdsaSignatureDep,
  MsgEcdsaSignatureDep: MsgEcdsaSignatureDep,
  0x0C02: MsgEd25519CertificateDep,
  MsgEd25519CertificateDep: MsgEd25519CertificateDep,
  0x0C01: MsgEd25519SignatureDepA,
  MsgEd25519SignatureDepA: MsgEd25519SignatureDepA,
  0x0C03: MsgEd25519SignatureDepB,
  MsgEd25519SignatureDepB: MsgEd25519SignatureDepB,
}