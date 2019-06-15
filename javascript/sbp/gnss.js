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
 * Automatically generated from piksi/yaml/swiftnav/sbp/gnss.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Various structs shared between modules
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;

/**
 * SBP class for message fragment GnssSignal
 *
 * Signal identifier containing constellation, band, and satellite identifier
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sat number (unsigned 8-bit int, 1 byte) Constellation-specific satellite identifier. This field for Glonass can   either
 *   be (100+FCN) where FCN is in [-7,+6] or  the Slot ID in [1,28]
 * @field code number (unsigned 8-bit int, 1 byte) Signal constellation, band and code
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var GnssSignal = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "GnssSignal";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
GnssSignal.prototype = Object.create(SBP.prototype);
GnssSignal.prototype.messageType = "GnssSignal";
GnssSignal.prototype.constructor = GnssSignal;
GnssSignal.prototype.parser = new Parser()
  .endianess('little')
  .uint8('sat')
  .uint8('code');
GnssSignal.prototype.fieldSpec = [];
GnssSignal.prototype.fieldSpec.push(['sat', 'writeUInt8', 1]);
GnssSignal.prototype.fieldSpec.push(['code', 'writeUInt8', 1]);

/**
 * SBP class for message fragment SvId
 *
 * A (Constellation ID, satellite ID) tuple that uniquely identifies a space
 * vehicle
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field satId number (unsigned 8-bit int, 1 byte) ID of the space vehicle within its constellation
 * @field constellation number (unsigned 8-bit int, 1 byte) Constellation ID to which the SV belongs
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var SvId = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "SvId";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
SvId.prototype = Object.create(SBP.prototype);
SvId.prototype.messageType = "SvId";
SvId.prototype.constructor = SvId;
SvId.prototype.parser = new Parser()
  .endianess('little')
  .uint8('satId')
  .uint8('constellation');
SvId.prototype.fieldSpec = [];
SvId.prototype.fieldSpec.push(['satId', 'writeUInt8', 1]);
SvId.prototype.fieldSpec.push(['constellation', 'writeUInt8', 1]);

/**
 * SBP class for message fragment GnssSignalDep
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sat number (unsigned 16-bit int, 2 bytes) Constellation-specific satellite identifier.  Note: unlike GnssSignal, GPS
 *   satellites are encoded as (PRN - 1). Other constellations do not have this
 *   offset.
 * @field code number (unsigned 8-bit int, 1 byte) Signal constellation, band and code
 * @field reserved number (unsigned 8-bit int, 1 byte) Reserved
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var GnssSignalDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "GnssSignalDep";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
GnssSignalDep.prototype = Object.create(SBP.prototype);
GnssSignalDep.prototype.messageType = "GnssSignalDep";
GnssSignalDep.prototype.constructor = GnssSignalDep;
GnssSignalDep.prototype.parser = new Parser()
  .endianess('little')
  .uint16('sat')
  .uint8('code')
  .uint8('reserved');
GnssSignalDep.prototype.fieldSpec = [];
GnssSignalDep.prototype.fieldSpec.push(['sat', 'writeUInt16LE', 2]);
GnssSignalDep.prototype.fieldSpec.push(['code', 'writeUInt8', 1]);
GnssSignalDep.prototype.fieldSpec.push(['reserved', 'writeUInt8', 1]);

/**
 * SBP class for message fragment GPSTimeDep
 *
 * A wire-appropriate GPS time, defined as the number of milliseconds since
 * beginning of the week on the Saturday/Sunday transition.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) Milliseconds since start of GPS week
 * @field wn number (unsigned 16-bit int, 2 bytes) GPS week number
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var GPSTimeDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "GPSTimeDep";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
GPSTimeDep.prototype = Object.create(SBP.prototype);
GPSTimeDep.prototype.messageType = "GPSTimeDep";
GPSTimeDep.prototype.constructor = GPSTimeDep;
GPSTimeDep.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint16('wn');
GPSTimeDep.prototype.fieldSpec = [];
GPSTimeDep.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
GPSTimeDep.prototype.fieldSpec.push(['wn', 'writeUInt16LE', 2]);

/**
 * SBP class for message fragment GPSTimeSec
 *
 * A GPS time, defined as the number of seconds since beginning of the week on the
 * Saturday/Sunday transition.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) Seconds since start of GPS week
 * @field wn number (unsigned 16-bit int, 2 bytes) GPS week number
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var GPSTimeSec = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "GPSTimeSec";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
GPSTimeSec.prototype = Object.create(SBP.prototype);
GPSTimeSec.prototype.messageType = "GPSTimeSec";
GPSTimeSec.prototype.constructor = GPSTimeSec;
GPSTimeSec.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint16('wn');
GPSTimeSec.prototype.fieldSpec = [];
GPSTimeSec.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
GPSTimeSec.prototype.fieldSpec.push(['wn', 'writeUInt16LE', 2]);

/**
 * SBP class for message fragment GPSTime
 *
 * A wire-appropriate receiver clock time, defined as the time since the beginning
 * of the week on the Saturday/Sunday transition. In most cases, observations are
 * epoch aligned so ns field will be 0.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) Milliseconds since start of GPS week
 * @field ns_residual number (signed 32-bit int, 4 bytes) Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000)
 * @field wn number (unsigned 16-bit int, 2 bytes) GPS week number
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var GPSTime = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "GPSTime";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
GPSTime.prototype = Object.create(SBP.prototype);
GPSTime.prototype.messageType = "GPSTime";
GPSTime.prototype.constructor = GPSTime;
GPSTime.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('ns_residual')
  .uint16('wn');
GPSTime.prototype.fieldSpec = [];
GPSTime.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
GPSTime.prototype.fieldSpec.push(['ns_residual', 'writeInt32LE', 4]);
GPSTime.prototype.fieldSpec.push(['wn', 'writeUInt16LE', 2]);

/**
 * SBP class for message fragment CarrierPhase
 *
 * Carrier phase measurement in cycles represented as a 40-bit fixed point number
 * with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of fractional cycles.
 * This phase has the same sign as the pseudorange.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field i number (signed 32-bit int, 4 bytes) Carrier phase whole cycles
 * @field f number (unsigned 8-bit int, 1 byte) Carrier phase fractional part
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var CarrierPhase = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "CarrierPhase";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
CarrierPhase.prototype = Object.create(SBP.prototype);
CarrierPhase.prototype.messageType = "CarrierPhase";
CarrierPhase.prototype.constructor = CarrierPhase;
CarrierPhase.prototype.parser = new Parser()
  .endianess('little')
  .int32('i')
  .uint8('f');
CarrierPhase.prototype.fieldSpec = [];
CarrierPhase.prototype.fieldSpec.push(['i', 'writeInt32LE', 4]);
CarrierPhase.prototype.fieldSpec.push(['f', 'writeUInt8', 1]);

module.exports = {
  GnssSignal: GnssSignal,
  SvId: SvId,
  GnssSignalDep: GnssSignalDep,
  GPSTimeDep: GPSTimeDep,
  GPSTimeSec: GPSTimeSec,
  GPSTime: GPSTime,
  CarrierPhase: CarrierPhase,
}