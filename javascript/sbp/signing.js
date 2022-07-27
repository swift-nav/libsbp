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
 * SBP class for message MSG_ED25519_SIGNATURE (0x0C01).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field stub array
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
MsgEd25519Signature.prototype.msg_type = 0x0C01;
MsgEd25519Signature.prototype.constructor = MsgEd25519Signature;
MsgEd25519Signature.prototype.parser = new Parser()
  .endianess('little')
  .array('stub', { type: 'uint8', readUntil: 'eof' });
MsgEd25519Signature.prototype.fieldSpec = [];
MsgEd25519Signature.prototype.fieldSpec.push(['stub', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_ED25519_CERTIFICATE (0x0C02).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field stub array
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
MsgEd25519Certificate.prototype.msg_type = 0x0C02;
MsgEd25519Certificate.prototype.constructor = MsgEd25519Certificate;
MsgEd25519Certificate.prototype.parser = new Parser()
  .endianess('little')
  .array('stub', { type: 'uint8', readUntil: 'eof' });
MsgEd25519Certificate.prototype.fieldSpec = [];
MsgEd25519Certificate.prototype.fieldSpec.push(['stub', 'array', 'writeUInt8', function () { return 1; }, null]);

module.exports = {
  0x0C01: MsgEd25519Signature,
  MsgEd25519Signature: MsgEd25519Signature,
  0x0C02: MsgEd25519Certificate,
  MsgEd25519Certificate: MsgEd25519Certificate,
}