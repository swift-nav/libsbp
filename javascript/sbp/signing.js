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
let CarrierPhase = require("./gnss").CarrierPhase;
let GnssSignal = require("./gnss").GnssSignal;
let GnssSignalDep = require("./gnss").GnssSignalDep;
let GPSTime = require("./gnss").GPSTime;
let GPSTimeDep = require("./gnss").GPSTimeDep;
let GPSTimeSec = require("./gnss").GPSTimeSec;
let SvId = require("./gnss").SvId;

/**
 * SBP class for message MSG_ED25519_SIGNATURE (0x0BD2).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field signature array ED25519 signature for messages.
 * @field fingerprint array SHA-1 fingerprint of the associated certificate.
 * @field signed_messages array CRCs of signed messages.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgEd25519Signature = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ED25519_SIGNATURE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEd25519Signature.prototype = Object.create(SBP.prototype);
MsgEd25519Signature.prototype.messageType = "MSG_ED25519_SIGNATURE";
MsgEd25519Signature.prototype.msg_type = 0x0BD2;
MsgEd25519Signature.prototype.constructor = MsgEd25519Signature;
MsgEd25519Signature.prototype.parser = new Parser()
  .endianess('little')
  .array('signature', { length: 64, type: 'uint8' })
  .array('fingerprint', { length: 20, type: 'uint8' })
  .array('signed_messages', { type: 'uint32le', readUntil: 'eof' });
MsgEd25519Signature.prototype.fieldSpec = [];
MsgEd25519Signature.prototype.fieldSpec.push(['signature', 'array', 'writeUInt8', function () { return 1; }, 64]);
MsgEd25519Signature.prototype.fieldSpec.push(['fingerprint', 'array', 'writeUInt8', function () { return 1; }, 20]);
MsgEd25519Signature.prototype.fieldSpec.push(['signed_messages', 'array', 'writeUInt32LE', function () { return 4; }, null]);

/**
 * SBP class for message MSG_ED25519_CERTIFICATE (0x0BD3).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field message_number number (unsigned 8-bit int, 1 byte) Message number out of total_messages (0 indexed).
 * @field total_messages number (unsigned 8-bit int, 1 byte) Total number of messages.
 * @field fingerprint array SHA-1 fingerprint of the associated certificate.
 * @field certificate_bytes array ED25519 certificate bytes.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgEd25519Certificate = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ED25519_CERTIFICATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEd25519Certificate.prototype = Object.create(SBP.prototype);
MsgEd25519Certificate.prototype.messageType = "MSG_ED25519_CERTIFICATE";
MsgEd25519Certificate.prototype.msg_type = 0x0BD3;
MsgEd25519Certificate.prototype.constructor = MsgEd25519Certificate;
MsgEd25519Certificate.prototype.parser = new Parser()
  .endianess('little')
  .uint8('message_number')
  .uint8('total_messages')
  .array('fingerprint', { length: 20, type: 'uint8' })
  .array('certificate_bytes', { type: 'uint8', readUntil: 'eof' });
MsgEd25519Certificate.prototype.fieldSpec = [];
MsgEd25519Certificate.prototype.fieldSpec.push(['message_number', 'writeUInt8', 1]);
MsgEd25519Certificate.prototype.fieldSpec.push(['total_messages', 'writeUInt8', 1]);
MsgEd25519Certificate.prototype.fieldSpec.push(['fingerprint', 'array', 'writeUInt8', function () { return 1; }, 20]);
MsgEd25519Certificate.prototype.fieldSpec.push(['certificate_bytes', 'array', 'writeUInt8', function () { return 1; }, null]);

module.exports = {
  0x0BD2: MsgEd25519Signature,
  MsgEd25519Signature: MsgEd25519Signature,
  0x0BD3: MsgEd25519Certificate,
  MsgEd25519Certificate: MsgEd25519Certificate,
}