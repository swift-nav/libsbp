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
 * Automatically generated from piksi/yaml/swiftnav/sbp/integrity.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Integrity flag messages
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;
var CarrierPhase = require("./gnss").CarrierPhase;
var GnssSignal = require("./gnss").GnssSignal;
var GnssSignalDep = require("./gnss").GnssSignalDep;
var GPSTime = require("./gnss").GPSTime;
var GPSTimeDep = require("./gnss").GPSTimeDep;
var GPSTimeSec = require("./gnss").GPSTimeSec;
var SvId = require("./gnss").SvId;

/**
 * SBP class for message MSG_SSR_FLAG_HIGH_LEVEL (0x0BB9).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field stub array
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSsrFlagHighLevel = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_FLAG_HIGH_LEVEL";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrFlagHighLevel.prototype = Object.create(SBP.prototype);
MsgSsrFlagHighLevel.prototype.messageType = "MSG_SSR_FLAG_HIGH_LEVEL";
MsgSsrFlagHighLevel.prototype.msg_type = 0x0BB9;
MsgSsrFlagHighLevel.prototype.constructor = MsgSsrFlagHighLevel;
MsgSsrFlagHighLevel.prototype.parser = new Parser()
  .endianess('little')
  .array('stub', { type: 'uint8', readUntil: 'eof' });
MsgSsrFlagHighLevel.prototype.fieldSpec = [];
MsgSsrFlagHighLevel.prototype.fieldSpec.push(['stub', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_SSR_FLAG_SATELLITES (0x0BBD).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field stub array
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSsrFlagSatellites = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_FLAG_SATELLITES";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrFlagSatellites.prototype = Object.create(SBP.prototype);
MsgSsrFlagSatellites.prototype.messageType = "MSG_SSR_FLAG_SATELLITES";
MsgSsrFlagSatellites.prototype.msg_type = 0x0BBD;
MsgSsrFlagSatellites.prototype.constructor = MsgSsrFlagSatellites;
MsgSsrFlagSatellites.prototype.parser = new Parser()
  .endianess('little')
  .array('stub', { type: 'uint8', readUntil: 'eof' });
MsgSsrFlagSatellites.prototype.fieldSpec = [];
MsgSsrFlagSatellites.prototype.fieldSpec.push(['stub', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_SSR_FLAG_TROPO_GRID_POINTS (0x0BC3).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field stub array
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSsrFlagTropoGridPoints = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_FLAG_TROPO_GRID_POINTS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrFlagTropoGridPoints.prototype = Object.create(SBP.prototype);
MsgSsrFlagTropoGridPoints.prototype.messageType = "MSG_SSR_FLAG_TROPO_GRID_POINTS";
MsgSsrFlagTropoGridPoints.prototype.msg_type = 0x0BC3;
MsgSsrFlagTropoGridPoints.prototype.constructor = MsgSsrFlagTropoGridPoints;
MsgSsrFlagTropoGridPoints.prototype.parser = new Parser()
  .endianess('little')
  .array('stub', { type: 'uint8', readUntil: 'eof' });
MsgSsrFlagTropoGridPoints.prototype.fieldSpec = [];
MsgSsrFlagTropoGridPoints.prototype.fieldSpec.push(['stub', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_SSR_FLAG_IONO_GRID_POINTS (0x0BC7).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field stub array
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSsrFlagIonoGridPoints = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_FLAG_IONO_GRID_POINTS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrFlagIonoGridPoints.prototype = Object.create(SBP.prototype);
MsgSsrFlagIonoGridPoints.prototype.messageType = "MSG_SSR_FLAG_IONO_GRID_POINTS";
MsgSsrFlagIonoGridPoints.prototype.msg_type = 0x0BC7;
MsgSsrFlagIonoGridPoints.prototype.constructor = MsgSsrFlagIonoGridPoints;
MsgSsrFlagIonoGridPoints.prototype.parser = new Parser()
  .endianess('little')
  .array('stub', { type: 'uint8', readUntil: 'eof' });
MsgSsrFlagIonoGridPoints.prototype.fieldSpec = [];
MsgSsrFlagIonoGridPoints.prototype.fieldSpec.push(['stub', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_SSR_FLAG_IONO_TILE_SAT_LOS (0x0BCD).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field stub array
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSsrFlagIonoTileSatLos = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_FLAG_IONO_TILE_SAT_LOS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrFlagIonoTileSatLos.prototype = Object.create(SBP.prototype);
MsgSsrFlagIonoTileSatLos.prototype.messageType = "MSG_SSR_FLAG_IONO_TILE_SAT_LOS";
MsgSsrFlagIonoTileSatLos.prototype.msg_type = 0x0BCD;
MsgSsrFlagIonoTileSatLos.prototype.constructor = MsgSsrFlagIonoTileSatLos;
MsgSsrFlagIonoTileSatLos.prototype.parser = new Parser()
  .endianess('little')
  .array('stub', { type: 'uint8', readUntil: 'eof' });
MsgSsrFlagIonoTileSatLos.prototype.fieldSpec = [];
MsgSsrFlagIonoTileSatLos.prototype.fieldSpec.push(['stub', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS (0x0BD1).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field stub array
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSsrFlagIonoGridPointSatLos = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrFlagIonoGridPointSatLos.prototype = Object.create(SBP.prototype);
MsgSsrFlagIonoGridPointSatLos.prototype.messageType = "MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS";
MsgSsrFlagIonoGridPointSatLos.prototype.msg_type = 0x0BD1;
MsgSsrFlagIonoGridPointSatLos.prototype.constructor = MsgSsrFlagIonoGridPointSatLos;
MsgSsrFlagIonoGridPointSatLos.prototype.parser = new Parser()
  .endianess('little')
  .array('stub', { type: 'uint8', readUntil: 'eof' });
MsgSsrFlagIonoGridPointSatLos.prototype.fieldSpec = [];
MsgSsrFlagIonoGridPointSatLos.prototype.fieldSpec.push(['stub', 'array', 'writeUInt8', function () { return 1; }, null]);

module.exports = {
  0x0BB9: MsgSsrFlagHighLevel,
  MsgSsrFlagHighLevel: MsgSsrFlagHighLevel,
  0x0BBD: MsgSsrFlagSatellites,
  MsgSsrFlagSatellites: MsgSsrFlagSatellites,
  0x0BC3: MsgSsrFlagTropoGridPoints,
  MsgSsrFlagTropoGridPoints: MsgSsrFlagTropoGridPoints,
  0x0BC7: MsgSsrFlagIonoGridPoints,
  MsgSsrFlagIonoGridPoints: MsgSsrFlagIonoGridPoints,
  0x0BCD: MsgSsrFlagIonoTileSatLos,
  MsgSsrFlagIonoTileSatLos: MsgSsrFlagIonoTileSatLos,
  0x0BD1: MsgSsrFlagIonoGridPointSatLos,
  MsgSsrFlagIonoGridPointSatLos: MsgSsrFlagIonoGridPointSatLos,
}