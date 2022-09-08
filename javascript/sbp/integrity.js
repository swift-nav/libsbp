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
 * Automatically generated from spec/yaml/swiftnav/sbp/integrity.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Integrity flag messages
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
 * SBP class for message fragment IntegritySSRHeader
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field obs_time GPSTimeSec GNSS reference time of the observation used to generate the flag.
 * @field num_msgs number (unsigned 8-bit int, 1 byte) Number of messages in the dataset
 * @field seq_num number (unsigned 8-bit int, 1 byte) Position of this message in the dataset
 * @field ssr_sol_id number (unsigned 8-bit int, 1 byte) SSR Solution ID.
 * @field tile_set_id number (unsigned 16-bit int, 2 bytes) Unique identifier of the set this tile belongs to.
 * @field tile_id number (unsigned 16-bit int, 2 bytes) Unique identifier of this tile in the tile set.
 * @field chain_id number (unsigned 8-bit int, 1 byte) Chain and type of flag.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let IntegritySSRHeader = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "IntegritySSRHeader";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
IntegritySSRHeader.prototype = Object.create(SBP.prototype);
IntegritySSRHeader.prototype.messageType = "IntegritySSRHeader";
IntegritySSRHeader.prototype.constructor = IntegritySSRHeader;
IntegritySSRHeader.prototype.parser = new Parser()
  .endianess('little')
  .nest('obs_time', { type: GPSTimeSec.prototype.parser })
  .uint8('num_msgs')
  .uint8('seq_num')
  .uint8('ssr_sol_id')
  .uint16('tile_set_id')
  .uint16('tile_id')
  .uint8('chain_id');
IntegritySSRHeader.prototype.fieldSpec = [];
IntegritySSRHeader.prototype.fieldSpec.push(['obs_time', GPSTimeSec.prototype.fieldSpec]);
IntegritySSRHeader.prototype.fieldSpec.push(['num_msgs', 'writeUInt8', 1]);
IntegritySSRHeader.prototype.fieldSpec.push(['seq_num', 'writeUInt8', 1]);
IntegritySSRHeader.prototype.fieldSpec.push(['ssr_sol_id', 'writeUInt8', 1]);
IntegritySSRHeader.prototype.fieldSpec.push(['tile_set_id', 'writeUInt16LE', 2]);
IntegritySSRHeader.prototype.fieldSpec.push(['tile_id', 'writeUInt16LE', 2]);
IntegritySSRHeader.prototype.fieldSpec.push(['chain_id', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_SSR_FLAG_HIGH_LEVEL (0x0BB9).
 *
 * Integrity monitoring flags for multiple aggregated elements. An element could be
 * a satellite, SSR grid point, or SSR tile. A group of aggregated elements being
 * monitored for integrity could refer to:  - Satellites in a particular {GPS, GAL,
 * BDS} constellation.  - Satellites in the line-of-sight of a particular SSR tile.
 * - Satellites in the line-of-sight of a particular SSR grid point.  The integrity
 * usage for a group of aggregated elements varies according to the integrity flag
 * of the satellites comprising that group.  SSR_INTEGRITY_USAGE_NOMINAL: All
 * satellites received passed the integrity check and have flag INTEGRITY_FLAG_OK.
 * SSR_INTEGRITY_USAGE_WARNING: A limited number of elements in the group failed
 * the integrity check. Refer to more granular integrity messages for details on
 * the specific failing elements.  SSR_INTEGRITY_USAGE_ALERT: Most elements in the
 * group failed the integrity check, do not use for positioning.
 * SSR_INTEGRITY_USAGE_NOT_MONITORED: Unable to verify the integrity flag of
 * elements in the group.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field obs_time GPSTimeSec GNSS reference time of the observation used to generate the flag.
 * @field corr_time GPSTimeSec GNSS reference time of the correction associated to the flag.
 * @field ssr_sol_id number (unsigned 8-bit int, 1 byte) SSR Solution ID.
 * @field tile_set_id number (unsigned 16-bit int, 2 bytes) Unique identifier of the set this tile belongs to.
 * @field tile_id number (unsigned 16-bit int, 2 bytes) Unique identifier of this tile in the tile set.
 * @field chain_id number (unsigned 8-bit int, 1 byte) Chain and type of flag.
 * @field use_gps_sat number (unsigned 8-bit int, 1 byte) Use GPS satellites.
 * @field use_gal_sat number (unsigned 8-bit int, 1 byte) Use GAL satellites.
 * @field use_bds_sat number (unsigned 8-bit int, 1 byte) Use BDS satellites.
 * @field reserved array Reserved
 * @field use_tropo_grid_points number (unsigned 8-bit int, 1 byte) Use tropo grid points.
 * @field use_iono_grid_points number (unsigned 8-bit int, 1 byte) Use iono grid points.
 * @field use_iono_tile_sat_los number (unsigned 8-bit int, 1 byte) Use iono tile satellite LoS.
 * @field use_iono_grid_point_sat_los number (unsigned 8-bit int, 1 byte) Use iono grid point satellite LoS.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrFlagHighLevel = function (sbp, fields) {
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
  .nest('obs_time', { type: GPSTimeSec.prototype.parser })
  .nest('corr_time', { type: GPSTimeSec.prototype.parser })
  .uint8('ssr_sol_id')
  .uint16('tile_set_id')
  .uint16('tile_id')
  .uint8('chain_id')
  .uint8('use_gps_sat')
  .uint8('use_gal_sat')
  .uint8('use_bds_sat')
  .array('reserved', { length: 6, type: 'uint8' })
  .uint8('use_tropo_grid_points')
  .uint8('use_iono_grid_points')
  .uint8('use_iono_tile_sat_los')
  .uint8('use_iono_grid_point_sat_los');
MsgSsrFlagHighLevel.prototype.fieldSpec = [];
MsgSsrFlagHighLevel.prototype.fieldSpec.push(['obs_time', GPSTimeSec.prototype.fieldSpec]);
MsgSsrFlagHighLevel.prototype.fieldSpec.push(['corr_time', GPSTimeSec.prototype.fieldSpec]);
MsgSsrFlagHighLevel.prototype.fieldSpec.push(['ssr_sol_id', 'writeUInt8', 1]);
MsgSsrFlagHighLevel.prototype.fieldSpec.push(['tile_set_id', 'writeUInt16LE', 2]);
MsgSsrFlagHighLevel.prototype.fieldSpec.push(['tile_id', 'writeUInt16LE', 2]);
MsgSsrFlagHighLevel.prototype.fieldSpec.push(['chain_id', 'writeUInt8', 1]);
MsgSsrFlagHighLevel.prototype.fieldSpec.push(['use_gps_sat', 'writeUInt8', 1]);
MsgSsrFlagHighLevel.prototype.fieldSpec.push(['use_gal_sat', 'writeUInt8', 1]);
MsgSsrFlagHighLevel.prototype.fieldSpec.push(['use_bds_sat', 'writeUInt8', 1]);
MsgSsrFlagHighLevel.prototype.fieldSpec.push(['reserved', 'array', 'writeUInt8', function () { return 1; }, 6]);
MsgSsrFlagHighLevel.prototype.fieldSpec.push(['use_tropo_grid_points', 'writeUInt8', 1]);
MsgSsrFlagHighLevel.prototype.fieldSpec.push(['use_iono_grid_points', 'writeUInt8', 1]);
MsgSsrFlagHighLevel.prototype.fieldSpec.push(['use_iono_tile_sat_los', 'writeUInt8', 1]);
MsgSsrFlagHighLevel.prototype.fieldSpec.push(['use_iono_grid_point_sat_los', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_SSR_FLAG_SATELLITES (0x0BBD).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field obs_time GPSTimeSec GNSS reference time of the observation used to generate the flag.
 * @field num_msgs number (unsigned 8-bit int, 1 byte) Number of messages in the dataset
 * @field seq_num number (unsigned 8-bit int, 1 byte) Position of this message in the dataset
 * @field ssr_sol_id number (unsigned 8-bit int, 1 byte) SSR Solution ID.
 * @field chain_id number (unsigned 8-bit int, 1 byte) Chain and type of flag.
 * @field const_id number (unsigned 8-bit int, 1 byte) Constellation ID.
 * @field n_faulty_sats number (unsigned 8-bit int, 1 byte) Number of faulty satellites.
 * @field faulty_sats array List of faulty satellites.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrFlagSatellites = function (sbp, fields) {
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
  .nest('obs_time', { type: GPSTimeSec.prototype.parser })
  .uint8('num_msgs')
  .uint8('seq_num')
  .uint8('ssr_sol_id')
  .uint8('chain_id')
  .uint8('const_id')
  .uint8('n_faulty_sats')
  .array('faulty_sats', { type: 'uint8', length: 'n_faulty_sats' });
MsgSsrFlagSatellites.prototype.fieldSpec = [];
MsgSsrFlagSatellites.prototype.fieldSpec.push(['obs_time', GPSTimeSec.prototype.fieldSpec]);
MsgSsrFlagSatellites.prototype.fieldSpec.push(['num_msgs', 'writeUInt8', 1]);
MsgSsrFlagSatellites.prototype.fieldSpec.push(['seq_num', 'writeUInt8', 1]);
MsgSsrFlagSatellites.prototype.fieldSpec.push(['ssr_sol_id', 'writeUInt8', 1]);
MsgSsrFlagSatellites.prototype.fieldSpec.push(['chain_id', 'writeUInt8', 1]);
MsgSsrFlagSatellites.prototype.fieldSpec.push(['const_id', 'writeUInt8', 1]);
MsgSsrFlagSatellites.prototype.fieldSpec.push(['n_faulty_sats', 'writeUInt8', 1]);
MsgSsrFlagSatellites.prototype.fieldSpec.push(['faulty_sats', 'array', 'writeUInt8', function () { return 1; }, 'n_faulty_sats']);

/**
 * SBP class for message MSG_SSR_FLAG_TROPO_GRID_POINTS (0x0BC3).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field header IntegritySSRHeader Header of an integrity message.
 * @field n_faulty_points number (unsigned 8-bit int, 1 byte) Number of faulty grid points.
 * @field faulty_points array List of faulty grid points.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrFlagTropoGridPoints = function (sbp, fields) {
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
  .nest('header', { type: IntegritySSRHeader.prototype.parser })
  .uint8('n_faulty_points')
  .array('faulty_points', { type: 'uint16le', length: 'n_faulty_points' });
MsgSsrFlagTropoGridPoints.prototype.fieldSpec = [];
MsgSsrFlagTropoGridPoints.prototype.fieldSpec.push(['header', IntegritySSRHeader.prototype.fieldSpec]);
MsgSsrFlagTropoGridPoints.prototype.fieldSpec.push(['n_faulty_points', 'writeUInt8', 1]);
MsgSsrFlagTropoGridPoints.prototype.fieldSpec.push(['faulty_points', 'array', 'writeUInt16LE', function () { return 2; }, 'n_faulty_points']);

/**
 * SBP class for message MSG_SSR_FLAG_IONO_GRID_POINTS (0x0BC7).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field header IntegritySSRHeader Header of an integrity message.
 * @field n_faulty_points number (unsigned 8-bit int, 1 byte) Number of faulty grid points.
 * @field faulty_points array List of faulty grid points.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrFlagIonoGridPoints = function (sbp, fields) {
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
  .nest('header', { type: IntegritySSRHeader.prototype.parser })
  .uint8('n_faulty_points')
  .array('faulty_points', { type: 'uint16le', length: 'n_faulty_points' });
MsgSsrFlagIonoGridPoints.prototype.fieldSpec = [];
MsgSsrFlagIonoGridPoints.prototype.fieldSpec.push(['header', IntegritySSRHeader.prototype.fieldSpec]);
MsgSsrFlagIonoGridPoints.prototype.fieldSpec.push(['n_faulty_points', 'writeUInt8', 1]);
MsgSsrFlagIonoGridPoints.prototype.fieldSpec.push(['faulty_points', 'array', 'writeUInt16LE', function () { return 2; }, 'n_faulty_points']);

/**
 * SBP class for message MSG_SSR_FLAG_IONO_TILE_SAT_LOS (0x0BCD).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field header IntegritySSRHeader Header of an integrity message.
 * @field n_faulty_los number (unsigned 8-bit int, 1 byte) Number of faulty LOS.
 * @field faulty_los array List of faulty LOS
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrFlagIonoTileSatLos = function (sbp, fields) {
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
  .nest('header', { type: IntegritySSRHeader.prototype.parser })
  .uint8('n_faulty_los')
  .array('faulty_los', { type: SvId.prototype.parser, length: 'n_faulty_los' });
MsgSsrFlagIonoTileSatLos.prototype.fieldSpec = [];
MsgSsrFlagIonoTileSatLos.prototype.fieldSpec.push(['header', IntegritySSRHeader.prototype.fieldSpec]);
MsgSsrFlagIonoTileSatLos.prototype.fieldSpec.push(['n_faulty_los', 'writeUInt8', 1]);
MsgSsrFlagIonoTileSatLos.prototype.fieldSpec.push(['faulty_los', 'array', SvId.prototype.fieldSpec, function () { return this.fields.array.length; }, 'n_faulty_los']);

/**
 * SBP class for message MSG_SSR_FLAG_IONO_GRID_POINT_SAT_LOS (0x0BD1).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field header IntegritySSRHeader Header of an integrity message.
 * @field grid_point_id number (unsigned 16-bit int, 2 bytes) Index of the grid point.
 * @field n_faulty_los number (unsigned 8-bit int, 1 byte) Number of faulty LOS.
 * @field faulty_los array List of faulty LOS
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSsrFlagIonoGridPointSatLos = function (sbp, fields) {
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
  .nest('header', { type: IntegritySSRHeader.prototype.parser })
  .uint16('grid_point_id')
  .uint8('n_faulty_los')
  .array('faulty_los', { type: SvId.prototype.parser, length: 'n_faulty_los' });
MsgSsrFlagIonoGridPointSatLos.prototype.fieldSpec = [];
MsgSsrFlagIonoGridPointSatLos.prototype.fieldSpec.push(['header', IntegritySSRHeader.prototype.fieldSpec]);
MsgSsrFlagIonoGridPointSatLos.prototype.fieldSpec.push(['grid_point_id', 'writeUInt16LE', 2]);
MsgSsrFlagIonoGridPointSatLos.prototype.fieldSpec.push(['n_faulty_los', 'writeUInt8', 1]);
MsgSsrFlagIonoGridPointSatLos.prototype.fieldSpec.push(['faulty_los', 'array', SvId.prototype.fieldSpec, function () { return this.fields.array.length; }, 'n_faulty_los']);

module.exports = {
  IntegritySSRHeader: IntegritySSRHeader,
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