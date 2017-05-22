/**
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Joshua Gross <josh@swift-nav.com>
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/**********************
 * Automatically generated from piksi/yaml/swiftnav/sbp/specan.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Spectrum analyzer and related interference messages
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;
var GnssSignal = require("./gnss").GnssSignal;
var GnssSignal16 = require("./gnss").GnssSignal16;
var GPSTime = require("./gnss").GPSTime;
var CarrierPhase = require("./gnss").CarrierPhase;
var GPSTimeNano = require("./gnss").GPSTimeNano;

/**
 * SBP class for message MSG_SPECAN (0x0050).
 *
 * Spectrum analyzer packet.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field t GPSTime Receiver time of this observation
 * @field freq_ref number (float, 4 bytes) Reference frequency of this packet
 * @field freq_step number (float, 4 bytes) Frequency step of points in this packet
 * @field amplitude_ref number (float, 4 bytes) Reference amplitude of this packet
 * @field amplitude_unit number (float, 4 bytes) Amplitude unit value of points in this packet
 * @field amplitude_value array Amplitude values (in the above units) of points in this packet
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSpecan = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SPECAN";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSpecan.prototype = Object.create(SBP.prototype);
MsgSpecan.prototype.messageType = "MSG_SPECAN";
MsgSpecan.prototype.msg_type = 0x0050;
MsgSpecan.prototype.constructor = MsgSpecan;
MsgSpecan.prototype.parser = new Parser()
  .endianess('little')
  .nest('t', { type: GPSTime.prototype.parser })
  .floatle('freq_ref')
  .floatle('freq_step')
  .floatle('amplitude_ref')
  .floatle('amplitude_unit')
  .array('amplitude_value', { type: 'uint8', readUntil: 'eof' });
MsgSpecan.prototype.fieldSpec = [];
MsgSpecan.prototype.fieldSpec.push(['t', GPSTime.prototype.fieldSpec]);
MsgSpecan.prototype.fieldSpec.push(['freq_ref', 'writeFloatLE', 4]);
MsgSpecan.prototype.fieldSpec.push(['freq_step', 'writeFloatLE', 4]);
MsgSpecan.prototype.fieldSpec.push(['amplitude_ref', 'writeFloatLE', 4]);
MsgSpecan.prototype.fieldSpec.push(['amplitude_unit', 'writeFloatLE', 4]);
MsgSpecan.prototype.fieldSpec.push(['amplitude_value', 'array', 'writeUInt8', function () { return 1; }, null]);

module.exports = {
  0x0050: MsgSpecan,
  MsgSpecan: MsgSpecan,
}