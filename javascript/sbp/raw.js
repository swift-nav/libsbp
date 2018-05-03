/**
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/**********************
 * Automatically generated from piksi/yaml/swiftnav/sbp/raw.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Raw GNSS navigation data
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;
var GnssSignal = require("./gnss").GnssSignal;
var GnssSignalDep = require("./gnss").GnssSignalDep;
var GPSTime = require("./gnss").GPSTime;
var CarrierPhase = require("./gnss").CarrierPhase;
var GPSTime = require("./gnss").GPSTime;
var GPSTimeSec = require("./gnss").GPSTimeSec;
var GPSTimeDep = require("./gnss").GPSTimeDep;

/**
 * SBP class for message MSG_GPS_L1CA_RAW (0x7778).
 *
 * This message is sent once per 6 seconds per GPS satellite. ME checks the parity
 * of the data block and sends only blocks that pass the check.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sid GnssSignal GNSS signal identifier.
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS time-of-week at the start of the subframe.
 * @field subframe_id number (unsigned 8-bit int, 1 byte) Subframe ID (1-5).
 * @field data array Raw subframe data field of 300 bits (last byte padded with zeros).
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgGpsL1caRaw = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_GPS_L1CA_RAW";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgGpsL1caRaw.prototype = Object.create(SBP.prototype);
MsgGpsL1caRaw.prototype.messageType = "MSG_GPS_L1CA_RAW";
MsgGpsL1caRaw.prototype.msg_type = 0x7778;
MsgGpsL1caRaw.prototype.constructor = MsgGpsL1caRaw;
MsgGpsL1caRaw.prototype.parser = new Parser()
  .endianess('little')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .uint32('tow')
  .uint8('subframe_id')
  .array('data', { length: 38, type: 'uint8' });
MsgGpsL1caRaw.prototype.fieldSpec = [];
MsgGpsL1caRaw.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgGpsL1caRaw.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgGpsL1caRaw.prototype.fieldSpec.push(['subframe_id', 'writeUInt8', 1]);
MsgGpsL1caRaw.prototype.fieldSpec.push(['data', 'array', 'writeUInt8', function () { return 1; }, 38]);

/**
 * SBP class for message MSG_GLO_L1OF_RAW (0x7779).
 *
 * This message is sent once per 2 seconds per GLONASS satellite. ME checks the
 * parity of the data block and sends only blocks that pass the check.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sid GnssSignal GNSS signal identifier.
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS time-of-week at the start of the subframe.
 * @field string_number number (unsigned 8-bit int, 1 byte) String number (1-15).
 * @field data array Raw string data field of 85 bits (last byte padded with zeros).
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgGloL1ofRaw = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_GLO_L1OF_RAW";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgGloL1ofRaw.prototype = Object.create(SBP.prototype);
MsgGloL1ofRaw.prototype.messageType = "MSG_GLO_L1OF_RAW";
MsgGloL1ofRaw.prototype.msg_type = 0x7779;
MsgGloL1ofRaw.prototype.constructor = MsgGloL1ofRaw;
MsgGloL1ofRaw.prototype.parser = new Parser()
  .endianess('little')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .uint32('tow')
  .uint8('string_number')
  .array('data', { length: 11, type: 'uint8' });
MsgGloL1ofRaw.prototype.fieldSpec = [];
MsgGloL1ofRaw.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgGloL1ofRaw.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgGloL1ofRaw.prototype.fieldSpec.push(['string_number', 'writeUInt8', 1]);
MsgGloL1ofRaw.prototype.fieldSpec.push(['data', 'array', 'writeUInt8', function () { return 1; }, 11]);

module.exports = {
  0x7778: MsgGpsL1caRaw,
  MsgGpsL1caRaw: MsgGpsL1caRaw,
  0x7779: MsgGloL1ofRaw,
  MsgGloL1ofRaw: MsgGloL1ofRaw,
}