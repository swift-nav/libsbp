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
 * Automatically generated from piksi/yaml/swiftnav/sbp/sbas.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * SBAS data
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
var SvId = require("./gnss").SvId;

/**
 * SBP class for message MSG_SBAS_RAW (0x7777).
 *
 * This message is sent once per second per SBAS satellite. ME checks the parity of
 * the data block and sends only blocks that pass the check.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sid GnssSignal GNSS signal identifier.
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS time-of-week at the start of the data block.
 * @field message_type number (unsigned 8-bit int, 1 byte) SBAS message type (0-63)
 * @field data array Raw SBAS data field of 212 bits (last byte padded with zeros).
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSbasRaw = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SBAS_RAW";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSbasRaw.prototype = Object.create(SBP.prototype);
MsgSbasRaw.prototype.messageType = "MSG_SBAS_RAW";
MsgSbasRaw.prototype.msg_type = 0x7777;
MsgSbasRaw.prototype.constructor = MsgSbasRaw;
MsgSbasRaw.prototype.parser = new Parser()
  .endianess('little')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .uint32('tow')
  .uint8('message_type')
  .array('data', { length: 27, type: 'uint8' });
MsgSbasRaw.prototype.fieldSpec = [];
MsgSbasRaw.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgSbasRaw.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgSbasRaw.prototype.fieldSpec.push(['message_type', 'writeUInt8', 1]);
MsgSbasRaw.prototype.fieldSpec.push(['data', 'array', 'writeUInt8', function () { return 1; }, 27]);

module.exports = {
  0x7777: MsgSbasRaw,
  MsgSbasRaw: MsgSbasRaw,
}