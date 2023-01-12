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
 * Automatically generated from spec/yaml/swiftnav/sbp/telemetry.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Telemetry messages reported by Starling engine. The messages include various
 * byproducts of state estimation and other logic across Starling and are aimed at
 * efficient issue diagnostics.
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
 * SBP class for message fragment TelemetrySV
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field az number (unsigned 8-bit int, 1 byte) Azimuth angle (range 0..179)
 * @field el number (signed 8-bit int, 1 byte) Elevation angle (range -90..90)
 * @field pseudorange_residual number (signed 16-bit int, 2 bytes) Pseudorange observation residual
 * @field phase_residual number (signed 16-bit int, 2 bytes) Carrier-phase or carrier-phase-derived observation residual
 * @field outlier_flags number (unsigned 8-bit int, 1 byte) Reports if observation is marked as an outlier and is excluded from the update.
 * @field ephemeris_flags number (unsigned 8-bit int, 1 byte) Ephemeris metadata
 * @field correction_flags number (unsigned 8-bit int, 1 byte) Reserved
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let TelemetrySV = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "TelemetrySV";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
TelemetrySV.prototype = Object.create(SBP.prototype);
TelemetrySV.prototype.messageType = "TelemetrySV";
TelemetrySV.prototype.constructor = TelemetrySV;
TelemetrySV.prototype.parser = new Parser()
  .endianess('little')
  .uint8('az')
  .int8('el')
  .int16('pseudorange_residual')
  .int16('phase_residual')
  .uint8('outlier_flags')
  .uint8('ephemeris_flags')
  .uint8('correction_flags')
  .nest('sid', { type: GnssSignal.prototype.parser });
TelemetrySV.prototype.fieldSpec = [];
TelemetrySV.prototype.fieldSpec.push(['az', 'writeUInt8', 1]);
TelemetrySV.prototype.fieldSpec.push(['el', 'writeInt8', 1]);
TelemetrySV.prototype.fieldSpec.push(['pseudorange_residual', 'writeInt16LE', 2]);
TelemetrySV.prototype.fieldSpec.push(['phase_residual', 'writeInt16LE', 2]);
TelemetrySV.prototype.fieldSpec.push(['outlier_flags', 'writeUInt8', 1]);
TelemetrySV.prototype.fieldSpec.push(['ephemeris_flags', 'writeUInt8', 1]);
TelemetrySV.prototype.fieldSpec.push(['correction_flags', 'writeUInt8', 1]);
TelemetrySV.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);

/**
 * SBP class for message MSG_TEL_SV (0x0120).
 *
 * This message includes telemetry pertinent to satellite signals available to
 * Starling.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field wn number (unsigned 16-bit int, 2 bytes) GPS week number
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field n_obs number (unsigned 8-bit int, 1 byte) Total number of observations. First nibble is the size of the sequence (n),
 *   second nibble is the zero-indexed counter (ith packet of n)
 * @field origin_flags number (unsigned 8-bit int, 1 byte) Flags to identify Starling component the telemetry is reported from.
 * @field sv_tel array Array of per-signal telemetry entries
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgTelSv = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TEL_SV";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTelSv.prototype = Object.create(SBP.prototype);
MsgTelSv.prototype.messageType = "MSG_TEL_SV";
MsgTelSv.prototype.msg_type = 0x0120;
MsgTelSv.prototype.constructor = MsgTelSv;
MsgTelSv.prototype.parser = new Parser()
  .endianess('little')
  .uint16('wn')
  .uint32('tow')
  .uint8('n_obs')
  .uint8('origin_flags')
  .array('sv_tel', { type: TelemetrySV.prototype.parser, readUntil: 'eof' });
MsgTelSv.prototype.fieldSpec = [];
MsgTelSv.prototype.fieldSpec.push(['wn', 'writeUInt16LE', 2]);
MsgTelSv.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgTelSv.prototype.fieldSpec.push(['n_obs', 'writeUInt8', 1]);
MsgTelSv.prototype.fieldSpec.push(['origin_flags', 'writeUInt8', 1]);
MsgTelSv.prototype.fieldSpec.push(['sv_tel', 'array', TelemetrySV.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

module.exports = {
  TelemetrySV: TelemetrySV,
  0x0120: MsgTelSv,
  MsgTelSv: MsgTelSv,
}