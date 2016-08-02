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
 * Automatically generated from piksi/yaml/swiftnav/sbp/navigation.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Geodetic navigation messages reporting GPS time, position, velocity, and
 * baseline position solutions. For position solutions, these messages define
 * several different position solutions: single-point (SPP), RTK, and pseudo-
 * absolute position solutions.  The SPP is the standalone, absolute GPS position
 * solution using only a single receiver. The RTK solution is the differential GPS
 * solution, which can use either a fixed/integer or floating carrier phase
 * ambiguity. The pseudo-absolute position solution uses a user-provided, well-
 * surveyed base station position (if available) and the RTK solution in tandem.
***********************/

var SBP = require('./sbp');
var Parser = require('binary-parser').Parser;

/**
 * SBP class for message MSG_GPS_TIME (0x0100).
 *
 * This message reports the GPS time, representing the time since the GPS epoch
 * began on midnight January 6, 1980 UTC. GPS time counts the weeks and seconds of
 * the week. The weeks begin at the Saturday/Sunday transition. GPS week 0 began at
 * the beginning of the GPS time scale.  Within each week number, the GPS time of
 * the week is between between 0 and 604800 seconds (=60*60*24*7). Note that GPS
 * time does not accumulate leap seconds, and as of now, has a small offset from
 * UTC. In a message stream, this message precedes a set of other navigation
 * messages referenced to the same time (but lacking the ns field) and indicates a
 * more precise time of these messages.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field wn number (unsigned 16-bit int, 2 bytes) GPS week number
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS time of week rounded to the nearest millisecond
 * @field ns number (signed 32-bit int, 4 bytes) Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000)
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags (reserved)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgGpsTime = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_GPS_TIME";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgGpsTime.prototype = Object.create(SBP.prototype);
MsgGpsTime.prototype.messageType = "MSG_GPS_TIME";
MsgGpsTime.prototype.msg_type = 0x0100;
MsgGpsTime.prototype.constructor = MsgGpsTime;
MsgGpsTime.prototype.parser = new Parser()
  .endianess('little')
  .uint16('wn')
  .uint32('tow')
  .int32('ns')
  .uint8('flags');
MsgGpsTime.prototype.fieldSpec = [];
MsgGpsTime.prototype.fieldSpec.push(['wn', 'writeUInt16LE', 2]);
MsgGpsTime.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgGpsTime.prototype.fieldSpec.push(['ns', 'writeInt32LE', 4]);
MsgGpsTime.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_DOPS (0x0206).
 *
 * This dilution of precision (DOP) message describes the effect of navigation
 * satellite geometry on positional measurement precision.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field gdop number (unsigned 16-bit int, 2 bytes) Geometric Dilution of Precision
 * @field pdop number (unsigned 16-bit int, 2 bytes) Position Dilution of Precision
 * @field tdop number (unsigned 16-bit int, 2 bytes) Time Dilution of Precision
 * @field hdop number (unsigned 16-bit int, 2 bytes) Horizontal Dilution of Precision
 * @field vdop number (unsigned 16-bit int, 2 bytes) Vertical Dilution of Precision
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgDops = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_DOPS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgDops.prototype = Object.create(SBP.prototype);
MsgDops.prototype.messageType = "MSG_DOPS";
MsgDops.prototype.msg_type = 0x0206;
MsgDops.prototype.constructor = MsgDops;
MsgDops.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint16('gdop')
  .uint16('pdop')
  .uint16('tdop')
  .uint16('hdop')
  .uint16('vdop');
MsgDops.prototype.fieldSpec = [];
MsgDops.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgDops.prototype.fieldSpec.push(['gdop', 'writeUInt16LE', 2]);
MsgDops.prototype.fieldSpec.push(['pdop', 'writeUInt16LE', 2]);
MsgDops.prototype.fieldSpec.push(['tdop', 'writeUInt16LE', 2]);
MsgDops.prototype.fieldSpec.push(['hdop', 'writeUInt16LE', 2]);
MsgDops.prototype.fieldSpec.push(['vdop', 'writeUInt16LE', 2]);

/**
 * SBP class for message MSG_POS_ECEF (0x0200).
 *
 * The position solution message reports absolute Earth Centered Earth Fixed (ECEF)
 * coordinates and the status (single point vs pseudo-absolute RTK) of the position
 * solution. If the rover receiver knows the surveyed position of the base station
 * and has an RTK solution, this reports a pseudo-absolute position solution using
 * the base station position and the rover's RTK baseline vector. The full GPS time
 * is given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (float, 8 bytes) ECEF X coordinate
 * @field y number (float, 8 bytes) ECEF Y coordinate
 * @field z number (float, 8 bytes) ECEF Z coordinate
 * @field accuracy number (unsigned 16-bit int, 2 bytes) Position accuracy estimate (not implemented). Defaults to 0.
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgPosEcef = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_POS_ECEF";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPosEcef.prototype = Object.create(SBP.prototype);
MsgPosEcef.prototype.messageType = "MSG_POS_ECEF";
MsgPosEcef.prototype.msg_type = 0x0200;
MsgPosEcef.prototype.constructor = MsgPosEcef;
MsgPosEcef.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .doublele('x')
  .doublele('y')
  .doublele('z')
  .uint16('accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgPosEcef.prototype.fieldSpec = [];
MsgPosEcef.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgPosEcef.prototype.fieldSpec.push(['x', 'writeDoubleLE', 8]);
MsgPosEcef.prototype.fieldSpec.push(['y', 'writeDoubleLE', 8]);
MsgPosEcef.prototype.fieldSpec.push(['z', 'writeDoubleLE', 8]);
MsgPosEcef.prototype.fieldSpec.push(['accuracy', 'writeUInt16LE', 2]);
MsgPosEcef.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgPosEcef.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_POS_LLH (0x0201).
 *
 * This position solution message reports the absolute geodetic coordinates and the
 * status (single point vs pseudo-absolute RTK) of the position solution. If the
 * rover receiver knows the surveyed position of the base station and has an RTK
 * solution, this reports a pseudo-absolute position solution using the base
 * station position and the rover's RTK baseline vector. The full GPS time is given
 * by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field lat number (float, 8 bytes) Latitude
 * @field lon number (float, 8 bytes) Longitude
 * @field height number (float, 8 bytes) Height
 * @field h_accuracy number (unsigned 16-bit int, 2 bytes) Horizontal position accuracy estimate (not implemented). Defaults to 0.
 * @field v_accuracy number (unsigned 16-bit int, 2 bytes) Vertical position accuracy estimate (not implemented). Defaults to 0.
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution.
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgPosLlh = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_POS_LLH";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPosLlh.prototype = Object.create(SBP.prototype);
MsgPosLlh.prototype.messageType = "MSG_POS_LLH";
MsgPosLlh.prototype.msg_type = 0x0201;
MsgPosLlh.prototype.constructor = MsgPosLlh;
MsgPosLlh.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .doublele('lat')
  .doublele('lon')
  .doublele('height')
  .uint16('h_accuracy')
  .uint16('v_accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgPosLlh.prototype.fieldSpec = [];
MsgPosLlh.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgPosLlh.prototype.fieldSpec.push(['lat', 'writeDoubleLE', 8]);
MsgPosLlh.prototype.fieldSpec.push(['lon', 'writeDoubleLE', 8]);
MsgPosLlh.prototype.fieldSpec.push(['height', 'writeDoubleLE', 8]);
MsgPosLlh.prototype.fieldSpec.push(['h_accuracy', 'writeUInt16LE', 2]);
MsgPosLlh.prototype.fieldSpec.push(['v_accuracy', 'writeUInt16LE', 2]);
MsgPosLlh.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgPosLlh.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_BASELINE_ECEF (0x0202).
 *
 * This message reports the baseline solution in Earth Centered Earth Fixed (ECEF)
 * coordinates. This baseline is the relative vector distance from the base station
 * to the rover receiver. The full GPS time is given by the preceding MSG_GPS_TIME
 * with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (signed 32-bit int, 4 bytes) Baseline ECEF X coordinate
 * @field y number (signed 32-bit int, 4 bytes) Baseline ECEF Y coordinate
 * @field z number (signed 32-bit int, 4 bytes) Baseline ECEF Z coordinate
 * @field accuracy number (unsigned 16-bit int, 2 bytes) Position accuracy estimate (not implemented). Defaults to 0.
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBaselineEcef = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BASELINE_ECEF";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBaselineEcef.prototype = Object.create(SBP.prototype);
MsgBaselineEcef.prototype.messageType = "MSG_BASELINE_ECEF";
MsgBaselineEcef.prototype.msg_type = 0x0202;
MsgBaselineEcef.prototype.constructor = MsgBaselineEcef;
MsgBaselineEcef.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('x')
  .int32('y')
  .int32('z')
  .uint16('accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgBaselineEcef.prototype.fieldSpec = [];
MsgBaselineEcef.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgBaselineEcef.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgBaselineEcef.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgBaselineEcef.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgBaselineEcef.prototype.fieldSpec.push(['accuracy', 'writeUInt16LE', 2]);
MsgBaselineEcef.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgBaselineEcef.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_BASELINE_NED (0x0203).
 *
 * This message reports the baseline solution in North East Down (NED) coordinates.
 * This baseline is the relative vector distance from the base station to the rover
 * receiver, and NED coordinate system is defined at the local WGS84 tangent plane
 * centered at the base station position.  The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field n number (signed 32-bit int, 4 bytes) Baseline North coordinate
 * @field e number (signed 32-bit int, 4 bytes) Baseline East coordinate
 * @field d number (signed 32-bit int, 4 bytes) Baseline Down coordinate
 * @field h_accuracy number (unsigned 16-bit int, 2 bytes) Horizontal position accuracy estimate (not implemented). Defaults to 0.
 * @field v_accuracy number (unsigned 16-bit int, 2 bytes) Vertical position accuracy estimate (not implemented). Defaults to 0.
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBaselineNed = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BASELINE_NED";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBaselineNed.prototype = Object.create(SBP.prototype);
MsgBaselineNed.prototype.messageType = "MSG_BASELINE_NED";
MsgBaselineNed.prototype.msg_type = 0x0203;
MsgBaselineNed.prototype.constructor = MsgBaselineNed;
MsgBaselineNed.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('n')
  .int32('e')
  .int32('d')
  .uint16('h_accuracy')
  .uint16('v_accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgBaselineNed.prototype.fieldSpec = [];
MsgBaselineNed.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgBaselineNed.prototype.fieldSpec.push(['n', 'writeInt32LE', 4]);
MsgBaselineNed.prototype.fieldSpec.push(['e', 'writeInt32LE', 4]);
MsgBaselineNed.prototype.fieldSpec.push(['d', 'writeInt32LE', 4]);
MsgBaselineNed.prototype.fieldSpec.push(['h_accuracy', 'writeUInt16LE', 2]);
MsgBaselineNed.prototype.fieldSpec.push(['v_accuracy', 'writeUInt16LE', 2]);
MsgBaselineNed.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgBaselineNed.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_ECEF (0x0204).
 *
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
 * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (signed 32-bit int, 4 bytes) Velocity ECEF X coordinate
 * @field y number (signed 32-bit int, 4 bytes) Velocity ECEF Y coordinate
 * @field z number (signed 32-bit int, 4 bytes) Velocity ECEF Z coordinate
 * @field accuracy number (unsigned 16-bit int, 2 bytes) Velocity accuracy estimate (not implemented). Defaults to 0.
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags (reserved)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgVelEcef = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_ECEF";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelEcef.prototype = Object.create(SBP.prototype);
MsgVelEcef.prototype.messageType = "MSG_VEL_ECEF";
MsgVelEcef.prototype.msg_type = 0x0204;
MsgVelEcef.prototype.constructor = MsgVelEcef;
MsgVelEcef.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('x')
  .int32('y')
  .int32('z')
  .uint16('accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgVelEcef.prototype.fieldSpec = [];
MsgVelEcef.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelEcef.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgVelEcef.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgVelEcef.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgVelEcef.prototype.fieldSpec.push(['accuracy', 'writeUInt16LE', 2]);
MsgVelEcef.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelEcef.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_NED (0x0205).
 *
 * This message reports the velocity in local North East Down (NED) coordinates.
 * The NED coordinate system is defined as the local WGS84 tangent plane centered
 * at the current position. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field n number (signed 32-bit int, 4 bytes) Velocity North coordinate
 * @field e number (signed 32-bit int, 4 bytes) Velocity East coordinate
 * @field d number (signed 32-bit int, 4 bytes) Velocity Down coordinate
 * @field h_accuracy number (unsigned 16-bit int, 2 bytes) Horizontal velocity accuracy estimate (not implemented). Defaults to 0.
 * @field v_accuracy number (unsigned 16-bit int, 2 bytes) Vertical velocity accuracy estimate (not implemented). Defaults to 0.
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags (reserved)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgVelNed = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_NED";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelNed.prototype = Object.create(SBP.prototype);
MsgVelNed.prototype.messageType = "MSG_VEL_NED";
MsgVelNed.prototype.msg_type = 0x0205;
MsgVelNed.prototype.constructor = MsgVelNed;
MsgVelNed.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('n')
  .int32('e')
  .int32('d')
  .uint16('h_accuracy')
  .uint16('v_accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgVelNed.prototype.fieldSpec = [];
MsgVelNed.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelNed.prototype.fieldSpec.push(['n', 'writeInt32LE', 4]);
MsgVelNed.prototype.fieldSpec.push(['e', 'writeInt32LE', 4]);
MsgVelNed.prototype.fieldSpec.push(['d', 'writeInt32LE', 4]);
MsgVelNed.prototype.fieldSpec.push(['h_accuracy', 'writeUInt16LE', 2]);
MsgVelNed.prototype.fieldSpec.push(['v_accuracy', 'writeUInt16LE', 2]);
MsgVelNed.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelNed.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_BASELINE_HEADING (0x0207).
 *
 * This message reports the baseline heading pointing from the base station to the
 * rover relative to True North. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field heading number (unsigned 32-bit int, 4 bytes) Heading
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBaselineHeading = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BASELINE_HEADING";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBaselineHeading.prototype = Object.create(SBP.prototype);
MsgBaselineHeading.prototype.messageType = "MSG_BASELINE_HEADING";
MsgBaselineHeading.prototype.msg_type = 0x0207;
MsgBaselineHeading.prototype.constructor = MsgBaselineHeading;
MsgBaselineHeading.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint32('heading')
  .uint8('n_sats')
  .uint8('flags');
MsgBaselineHeading.prototype.fieldSpec = [];
MsgBaselineHeading.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgBaselineHeading.prototype.fieldSpec.push(['heading', 'writeUInt32LE', 4]);
MsgBaselineHeading.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgBaselineHeading.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

module.exports = {
  0x0100: MsgGpsTime,
  MsgGpsTime: MsgGpsTime,
  0x0206: MsgDops,
  MsgDops: MsgDops,
  0x0200: MsgPosEcef,
  MsgPosEcef: MsgPosEcef,
  0x0201: MsgPosLlh,
  MsgPosLlh: MsgPosLlh,
  0x0202: MsgBaselineEcef,
  MsgBaselineEcef: MsgBaselineEcef,
  0x0203: MsgBaselineNed,
  MsgBaselineNed: MsgBaselineNed,
  0x0204: MsgVelEcef,
  MsgVelEcef: MsgVelEcef,
  0x0205: MsgVelNed,
  MsgVelNed: MsgVelNed,
  0x0207: MsgBaselineHeading,
  MsgBaselineHeading: MsgBaselineHeading,
}