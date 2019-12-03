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
 * When the inertial navigation mode indicates that the IMU is used, all messages
 * are reported in the vehicle body frame as defined by device settings.  By
 * default, the vehicle body frame is configured to be coincident with the antenna
 * phase center.  When there is no inertial navigation, the solution will be
 * reported at the phase center of the antenna. There is no inertial navigation
 * capability on Piksi Multi or Duro.
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;

/**
 * SBP class for message MSG_GPS_TIME (0x0102).
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
 * @field ns_residual number (signed 32-bit int, 4 bytes) Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000)
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
MsgGpsTime.prototype.msg_type = 0x0102;
MsgGpsTime.prototype.constructor = MsgGpsTime;
MsgGpsTime.prototype.parser = new Parser()
  .endianess('little')
  .uint16('wn')
  .uint32('tow')
  .int32('ns_residual')
  .uint8('flags');
MsgGpsTime.prototype.fieldSpec = [];
MsgGpsTime.prototype.fieldSpec.push(['wn', 'writeUInt16LE', 2]);
MsgGpsTime.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgGpsTime.prototype.fieldSpec.push(['ns_residual', 'writeInt32LE', 4]);
MsgGpsTime.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_UTC_TIME (0x0103).
 *
 * This message reports the Universal Coordinated Time (UTC).  Note the flags which
 * indicate the source of the UTC offset value and source of the time fix.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field flags number (unsigned 8-bit int, 1 byte) Indicates source and time validity
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS time of week rounded to the nearest millisecond
 * @field year number (unsigned 16-bit int, 2 bytes) Year
 * @field month number (unsigned 8-bit int, 1 byte) Month (range 1 .. 12)
 * @field day number (unsigned 8-bit int, 1 byte) days in the month (range 1-31)
 * @field hours number (unsigned 8-bit int, 1 byte) hours of day (range 0-23)
 * @field minutes number (unsigned 8-bit int, 1 byte) minutes of hour (range 0-59)
 * @field seconds number (unsigned 8-bit int, 1 byte) seconds of minute (range 0-60) rounded down
 * @field ns number (unsigned 32-bit int, 4 bytes) nanoseconds of second (range 0-999999999)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgUtcTime = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_UTC_TIME";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgUtcTime.prototype = Object.create(SBP.prototype);
MsgUtcTime.prototype.messageType = "MSG_UTC_TIME";
MsgUtcTime.prototype.msg_type = 0x0103;
MsgUtcTime.prototype.constructor = MsgUtcTime;
MsgUtcTime.prototype.parser = new Parser()
  .endianess('little')
  .uint8('flags')
  .uint32('tow')
  .uint16('year')
  .uint8('month')
  .uint8('day')
  .uint8('hours')
  .uint8('minutes')
  .uint8('seconds')
  .uint32('ns');
MsgUtcTime.prototype.fieldSpec = [];
MsgUtcTime.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);
MsgUtcTime.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgUtcTime.prototype.fieldSpec.push(['year', 'writeUInt16LE', 2]);
MsgUtcTime.prototype.fieldSpec.push(['month', 'writeUInt8', 1]);
MsgUtcTime.prototype.fieldSpec.push(['day', 'writeUInt8', 1]);
MsgUtcTime.prototype.fieldSpec.push(['hours', 'writeUInt8', 1]);
MsgUtcTime.prototype.fieldSpec.push(['minutes', 'writeUInt8', 1]);
MsgUtcTime.prototype.fieldSpec.push(['seconds', 'writeUInt8', 1]);
MsgUtcTime.prototype.fieldSpec.push(['ns', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_DOPS (0x0208).
 *
 * This dilution of precision (DOP) message describes the effect of navigation
 * satellite geometry on positional measurement precision.  The flags field
 * indicated whether the DOP reported corresponds to differential or SPP solution.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field gdop number (unsigned 16-bit int, 2 bytes) Geometric Dilution of Precision
 * @field pdop number (unsigned 16-bit int, 2 bytes) Position Dilution of Precision
 * @field tdop number (unsigned 16-bit int, 2 bytes) Time Dilution of Precision
 * @field hdop number (unsigned 16-bit int, 2 bytes) Horizontal Dilution of Precision
 * @field vdop number (unsigned 16-bit int, 2 bytes) Vertical Dilution of Precision
 * @field flags number (unsigned 8-bit int, 1 byte) Indicates the position solution with which the DOPS message corresponds
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
MsgDops.prototype.msg_type = 0x0208;
MsgDops.prototype.constructor = MsgDops;
MsgDops.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint16('gdop')
  .uint16('pdop')
  .uint16('tdop')
  .uint16('hdop')
  .uint16('vdop')
  .uint8('flags');
MsgDops.prototype.fieldSpec = [];
MsgDops.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgDops.prototype.fieldSpec.push(['gdop', 'writeUInt16LE', 2]);
MsgDops.prototype.fieldSpec.push(['pdop', 'writeUInt16LE', 2]);
MsgDops.prototype.fieldSpec.push(['tdop', 'writeUInt16LE', 2]);
MsgDops.prototype.fieldSpec.push(['hdop', 'writeUInt16LE', 2]);
MsgDops.prototype.fieldSpec.push(['vdop', 'writeUInt16LE', 2]);
MsgDops.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_POS_ECEF (0x0209).
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
 * @field accuracy number (unsigned 16-bit int, 2 bytes) Position estimated standard deviation
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
MsgPosEcef.prototype.msg_type = 0x0209;
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
 * SBP class for message MSG_POS_ECEF_COV (0x0214).
 *
 * The position solution message reports absolute Earth Centered Earth Fixed (ECEF)
 * coordinates and the status (single point vs pseudo-absolute RTK) of the position
 * solution. The message also reports the upper triangular portion of the 3x3
 * covariance matrix. If the receiver knows the surveyed position of the base
 * station and has an RTK solution, this reports a pseudo-absolute position
 * solution using the base station position and the rover's RTK baseline vector.
 * The full GPS time is given by the preceding MSG_GPS_TIME with the matching time-
 * of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (float, 8 bytes) ECEF X coordinate
 * @field y number (float, 8 bytes) ECEF Y coordinate
 * @field z number (float, 8 bytes) ECEF Z coordinate
 * @field cov_x_x number (float, 4 bytes) Estimated variance of x
 * @field cov_x_y number (float, 4 bytes) Estimated covariance of x and y
 * @field cov_x_z number (float, 4 bytes) Estimated covariance of x and z
 * @field cov_y_y number (float, 4 bytes) Estimated variance of y
 * @field cov_y_z number (float, 4 bytes) Estimated covariance of y and z
 * @field cov_z_z number (float, 4 bytes) Estimated variance of z
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgPosEcefCov = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_POS_ECEF_COV";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPosEcefCov.prototype = Object.create(SBP.prototype);
MsgPosEcefCov.prototype.messageType = "MSG_POS_ECEF_COV";
MsgPosEcefCov.prototype.msg_type = 0x0214;
MsgPosEcefCov.prototype.constructor = MsgPosEcefCov;
MsgPosEcefCov.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .doublele('x')
  .doublele('y')
  .doublele('z')
  .floatle('cov_x_x')
  .floatle('cov_x_y')
  .floatle('cov_x_z')
  .floatle('cov_y_y')
  .floatle('cov_y_z')
  .floatle('cov_z_z')
  .uint8('n_sats')
  .uint8('flags');
MsgPosEcefCov.prototype.fieldSpec = [];
MsgPosEcefCov.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgPosEcefCov.prototype.fieldSpec.push(['x', 'writeDoubleLE', 8]);
MsgPosEcefCov.prototype.fieldSpec.push(['y', 'writeDoubleLE', 8]);
MsgPosEcefCov.prototype.fieldSpec.push(['z', 'writeDoubleLE', 8]);
MsgPosEcefCov.prototype.fieldSpec.push(['cov_x_x', 'writeFloatLE', 4]);
MsgPosEcefCov.prototype.fieldSpec.push(['cov_x_y', 'writeFloatLE', 4]);
MsgPosEcefCov.prototype.fieldSpec.push(['cov_x_z', 'writeFloatLE', 4]);
MsgPosEcefCov.prototype.fieldSpec.push(['cov_y_y', 'writeFloatLE', 4]);
MsgPosEcefCov.prototype.fieldSpec.push(['cov_y_z', 'writeFloatLE', 4]);
MsgPosEcefCov.prototype.fieldSpec.push(['cov_z_z', 'writeFloatLE', 4]);
MsgPosEcefCov.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgPosEcefCov.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_POS_LLH (0x020A).
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
 * @field height number (float, 8 bytes) Height above WGS84 ellipsoid
 * @field h_accuracy number (unsigned 16-bit int, 2 bytes) Horizontal position estimated standard deviation
 * @field v_accuracy number (unsigned 16-bit int, 2 bytes) Vertical position estimated standard deviation
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
MsgPosLlh.prototype.msg_type = 0x020A;
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
 * SBP class for message MSG_POS_LLH_COV (0x0211).
 *
 * This position solution message reports the absolute geodetic coordinates and the
 * status (single point vs pseudo-absolute RTK) of the position solution as well as
 * the upper triangle of the 3x3 covariance matrix.  The position information and
 * Fix Mode flags should follow the MSG_POS_LLH message.  Since the covariance
 * matrix is computed in the local-level North, East, Down frame, the covariance
 * terms follow with that convention. Thus, covariances are reported against the
 * "downward" measurement and care should be taken with the sign convention.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field lat number (float, 8 bytes) Latitude
 * @field lon number (float, 8 bytes) Longitude
 * @field height number (float, 8 bytes) Height above WGS84 ellipsoid
 * @field cov_n_n number (float, 4 bytes) Estimated variance of northing
 * @field cov_n_e number (float, 4 bytes) Covariance of northing and easting
 * @field cov_n_d number (float, 4 bytes) Covariance of northing and downward measurement
 * @field cov_e_e number (float, 4 bytes) Estimated variance of easting
 * @field cov_e_d number (float, 4 bytes) Covariance of easting and downward measurement
 * @field cov_d_d number (float, 4 bytes) Estimated variance of downward measurement
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution.
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgPosLlhCov = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_POS_LLH_COV";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPosLlhCov.prototype = Object.create(SBP.prototype);
MsgPosLlhCov.prototype.messageType = "MSG_POS_LLH_COV";
MsgPosLlhCov.prototype.msg_type = 0x0211;
MsgPosLlhCov.prototype.constructor = MsgPosLlhCov;
MsgPosLlhCov.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .doublele('lat')
  .doublele('lon')
  .doublele('height')
  .floatle('cov_n_n')
  .floatle('cov_n_e')
  .floatle('cov_n_d')
  .floatle('cov_e_e')
  .floatle('cov_e_d')
  .floatle('cov_d_d')
  .uint8('n_sats')
  .uint8('flags');
MsgPosLlhCov.prototype.fieldSpec = [];
MsgPosLlhCov.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgPosLlhCov.prototype.fieldSpec.push(['lat', 'writeDoubleLE', 8]);
MsgPosLlhCov.prototype.fieldSpec.push(['lon', 'writeDoubleLE', 8]);
MsgPosLlhCov.prototype.fieldSpec.push(['height', 'writeDoubleLE', 8]);
MsgPosLlhCov.prototype.fieldSpec.push(['cov_n_n', 'writeFloatLE', 4]);
MsgPosLlhCov.prototype.fieldSpec.push(['cov_n_e', 'writeFloatLE', 4]);
MsgPosLlhCov.prototype.fieldSpec.push(['cov_n_d', 'writeFloatLE', 4]);
MsgPosLlhCov.prototype.fieldSpec.push(['cov_e_e', 'writeFloatLE', 4]);
MsgPosLlhCov.prototype.fieldSpec.push(['cov_e_d', 'writeFloatLE', 4]);
MsgPosLlhCov.prototype.fieldSpec.push(['cov_d_d', 'writeFloatLE', 4]);
MsgPosLlhCov.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgPosLlhCov.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_BASELINE_ECEF (0x020B).
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
 * @field accuracy number (unsigned 16-bit int, 2 bytes) Position estimated standard deviation
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
MsgBaselineEcef.prototype.msg_type = 0x020B;
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
 * SBP class for message MSG_BASELINE_NED (0x020C).
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
 * @field h_accuracy number (unsigned 16-bit int, 2 bytes) Horizontal position estimated standard deviation
 * @field v_accuracy number (unsigned 16-bit int, 2 bytes) Vertical position estimated standard deviation
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
MsgBaselineNed.prototype.msg_type = 0x020C;
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
 * SBP class for message MSG_VEL_ECEF (0x020D).
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
 * @field accuracy number (unsigned 16-bit int, 2 bytes) Velocity estimated standard deviation
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
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
MsgVelEcef.prototype.msg_type = 0x020D;
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
 * SBP class for message MSG_VEL_ECEF_COV (0x0215).
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
 * @field cov_x_x number (float, 4 bytes) Estimated variance of x
 * @field cov_x_y number (float, 4 bytes) Estimated covariance of x and y
 * @field cov_x_z number (float, 4 bytes) Estimated covariance of x and z
 * @field cov_y_y number (float, 4 bytes) Estimated variance of y
 * @field cov_y_z number (float, 4 bytes) Estimated covariance of y and z
 * @field cov_z_z number (float, 4 bytes) Estimated variance of z
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgVelEcefCov = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_ECEF_COV";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelEcefCov.prototype = Object.create(SBP.prototype);
MsgVelEcefCov.prototype.messageType = "MSG_VEL_ECEF_COV";
MsgVelEcefCov.prototype.msg_type = 0x0215;
MsgVelEcefCov.prototype.constructor = MsgVelEcefCov;
MsgVelEcefCov.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('x')
  .int32('y')
  .int32('z')
  .floatle('cov_x_x')
  .floatle('cov_x_y')
  .floatle('cov_x_z')
  .floatle('cov_y_y')
  .floatle('cov_y_z')
  .floatle('cov_z_z')
  .uint8('n_sats')
  .uint8('flags');
MsgVelEcefCov.prototype.fieldSpec = [];
MsgVelEcefCov.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['cov_x_x', 'writeFloatLE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['cov_x_y', 'writeFloatLE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['cov_x_z', 'writeFloatLE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['cov_y_y', 'writeFloatLE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['cov_y_z', 'writeFloatLE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['cov_z_z', 'writeFloatLE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelEcefCov.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_NED (0x020E).
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
 * @field h_accuracy number (unsigned 16-bit int, 2 bytes) Horizontal velocity estimated standard deviation
 * @field v_accuracy number (unsigned 16-bit int, 2 bytes) Vertical velocity estimated standard deviation
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
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
MsgVelNed.prototype.msg_type = 0x020E;
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
 * SBP class for message MSG_VEL_NED_COV (0x0212).
 *
 * This message reports the velocity in local North East Down (NED) coordinates.
 * The NED coordinate system is defined as the local WGS84 tangent plane centered
 * at the current position. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow). This message is similar to
 * the MSG_VEL_NED, but it includes the upper triangular portion of the 3x3
 * covariance matrix.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field n number (signed 32-bit int, 4 bytes) Velocity North coordinate
 * @field e number (signed 32-bit int, 4 bytes) Velocity East coordinate
 * @field d number (signed 32-bit int, 4 bytes) Velocity Down coordinate
 * @field cov_n_n number (float, 4 bytes) Estimated variance of northward measurement
 * @field cov_n_e number (float, 4 bytes) Covariance of northward and eastward measurement
 * @field cov_n_d number (float, 4 bytes) Covariance of northward and downward measurement
 * @field cov_e_e number (float, 4 bytes) Estimated variance of eastward measurement
 * @field cov_e_d number (float, 4 bytes) Covariance of eastward and downward measurement
 * @field cov_d_d number (float, 4 bytes) Estimated variance of downward measurement
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgVelNedCov = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_NED_COV";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelNedCov.prototype = Object.create(SBP.prototype);
MsgVelNedCov.prototype.messageType = "MSG_VEL_NED_COV";
MsgVelNedCov.prototype.msg_type = 0x0212;
MsgVelNedCov.prototype.constructor = MsgVelNedCov;
MsgVelNedCov.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('n')
  .int32('e')
  .int32('d')
  .floatle('cov_n_n')
  .floatle('cov_n_e')
  .floatle('cov_n_d')
  .floatle('cov_e_e')
  .floatle('cov_e_d')
  .floatle('cov_d_d')
  .uint8('n_sats')
  .uint8('flags');
MsgVelNedCov.prototype.fieldSpec = [];
MsgVelNedCov.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['n', 'writeInt32LE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['e', 'writeInt32LE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['d', 'writeInt32LE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['cov_n_n', 'writeFloatLE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['cov_n_e', 'writeFloatLE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['cov_n_d', 'writeFloatLE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['cov_e_e', 'writeFloatLE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['cov_e_d', 'writeFloatLE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['cov_d_d', 'writeFloatLE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelNedCov.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_POS_ECEF_GNSS (0x0229).
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
 * @field accuracy number (unsigned 16-bit int, 2 bytes) Position estimated standard deviation
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgPosEcefGnss = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_POS_ECEF_GNSS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPosEcefGnss.prototype = Object.create(SBP.prototype);
MsgPosEcefGnss.prototype.messageType = "MSG_POS_ECEF_GNSS";
MsgPosEcefGnss.prototype.msg_type = 0x0229;
MsgPosEcefGnss.prototype.constructor = MsgPosEcefGnss;
MsgPosEcefGnss.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .doublele('x')
  .doublele('y')
  .doublele('z')
  .uint16('accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgPosEcefGnss.prototype.fieldSpec = [];
MsgPosEcefGnss.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgPosEcefGnss.prototype.fieldSpec.push(['x', 'writeDoubleLE', 8]);
MsgPosEcefGnss.prototype.fieldSpec.push(['y', 'writeDoubleLE', 8]);
MsgPosEcefGnss.prototype.fieldSpec.push(['z', 'writeDoubleLE', 8]);
MsgPosEcefGnss.prototype.fieldSpec.push(['accuracy', 'writeUInt16LE', 2]);
MsgPosEcefGnss.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgPosEcefGnss.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_POS_ECEF_COV_GNSS (0x0234).
 *
 * The position solution message reports absolute Earth Centered Earth Fixed (ECEF)
 * coordinates and the status (single point vs pseudo-absolute RTK) of the position
 * solution. The message also reports the upper triangular portion of the 3x3
 * covariance matrix. If the receiver knows the surveyed position of the base
 * station and has an RTK solution, this reports a pseudo-absolute position
 * solution using the base station position and the rover's RTK baseline vector.
 * The full GPS time is given by the preceding MSG_GPS_TIME with the matching time-
 * of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (float, 8 bytes) ECEF X coordinate
 * @field y number (float, 8 bytes) ECEF Y coordinate
 * @field z number (float, 8 bytes) ECEF Z coordinate
 * @field cov_x_x number (float, 4 bytes) Estimated variance of x
 * @field cov_x_y number (float, 4 bytes) Estimated covariance of x and y
 * @field cov_x_z number (float, 4 bytes) Estimated covariance of x and z
 * @field cov_y_y number (float, 4 bytes) Estimated variance of y
 * @field cov_y_z number (float, 4 bytes) Estimated covariance of y and z
 * @field cov_z_z number (float, 4 bytes) Estimated variance of z
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgPosEcefCovGnss = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_POS_ECEF_COV_GNSS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPosEcefCovGnss.prototype = Object.create(SBP.prototype);
MsgPosEcefCovGnss.prototype.messageType = "MSG_POS_ECEF_COV_GNSS";
MsgPosEcefCovGnss.prototype.msg_type = 0x0234;
MsgPosEcefCovGnss.prototype.constructor = MsgPosEcefCovGnss;
MsgPosEcefCovGnss.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .doublele('x')
  .doublele('y')
  .doublele('z')
  .floatle('cov_x_x')
  .floatle('cov_x_y')
  .floatle('cov_x_z')
  .floatle('cov_y_y')
  .floatle('cov_y_z')
  .floatle('cov_z_z')
  .uint8('n_sats')
  .uint8('flags');
MsgPosEcefCovGnss.prototype.fieldSpec = [];
MsgPosEcefCovGnss.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgPosEcefCovGnss.prototype.fieldSpec.push(['x', 'writeDoubleLE', 8]);
MsgPosEcefCovGnss.prototype.fieldSpec.push(['y', 'writeDoubleLE', 8]);
MsgPosEcefCovGnss.prototype.fieldSpec.push(['z', 'writeDoubleLE', 8]);
MsgPosEcefCovGnss.prototype.fieldSpec.push(['cov_x_x', 'writeFloatLE', 4]);
MsgPosEcefCovGnss.prototype.fieldSpec.push(['cov_x_y', 'writeFloatLE', 4]);
MsgPosEcefCovGnss.prototype.fieldSpec.push(['cov_x_z', 'writeFloatLE', 4]);
MsgPosEcefCovGnss.prototype.fieldSpec.push(['cov_y_y', 'writeFloatLE', 4]);
MsgPosEcefCovGnss.prototype.fieldSpec.push(['cov_y_z', 'writeFloatLE', 4]);
MsgPosEcefCovGnss.prototype.fieldSpec.push(['cov_z_z', 'writeFloatLE', 4]);
MsgPosEcefCovGnss.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgPosEcefCovGnss.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_POS_LLH_GNSS (0x022A).
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
 * @field height number (float, 8 bytes) Height above WGS84 ellipsoid
 * @field h_accuracy number (unsigned 16-bit int, 2 bytes) Horizontal position estimated standard deviation
 * @field v_accuracy number (unsigned 16-bit int, 2 bytes) Vertical position estimated standard deviation
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution.
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgPosLlhGnss = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_POS_LLH_GNSS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPosLlhGnss.prototype = Object.create(SBP.prototype);
MsgPosLlhGnss.prototype.messageType = "MSG_POS_LLH_GNSS";
MsgPosLlhGnss.prototype.msg_type = 0x022A;
MsgPosLlhGnss.prototype.constructor = MsgPosLlhGnss;
MsgPosLlhGnss.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .doublele('lat')
  .doublele('lon')
  .doublele('height')
  .uint16('h_accuracy')
  .uint16('v_accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgPosLlhGnss.prototype.fieldSpec = [];
MsgPosLlhGnss.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgPosLlhGnss.prototype.fieldSpec.push(['lat', 'writeDoubleLE', 8]);
MsgPosLlhGnss.prototype.fieldSpec.push(['lon', 'writeDoubleLE', 8]);
MsgPosLlhGnss.prototype.fieldSpec.push(['height', 'writeDoubleLE', 8]);
MsgPosLlhGnss.prototype.fieldSpec.push(['h_accuracy', 'writeUInt16LE', 2]);
MsgPosLlhGnss.prototype.fieldSpec.push(['v_accuracy', 'writeUInt16LE', 2]);
MsgPosLlhGnss.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgPosLlhGnss.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_POS_LLH_COV_GNSS (0x0231).
 *
 * This position solution message reports the absolute geodetic coordinates and the
 * status (single point vs pseudo-absolute RTK) of the position solution as well as
 * the upper triangle of the 3x3 covariance matrix.  The position information and
 * Fix Mode flags should follow the MSG_POS_LLH message.  Since the covariance
 * matrix is computed in the local-level North, East, Down frame, the covariance
 * terms follow with that convention. Thus, covariances are reported against the
 * "downward" measurement and care should be taken with the sign convention.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field lat number (float, 8 bytes) Latitude
 * @field lon number (float, 8 bytes) Longitude
 * @field height number (float, 8 bytes) Height above WGS84 ellipsoid
 * @field cov_n_n number (float, 4 bytes) Estimated variance of northing
 * @field cov_n_e number (float, 4 bytes) Covariance of northing and easting
 * @field cov_n_d number (float, 4 bytes) Covariance of northing and downward measurement
 * @field cov_e_e number (float, 4 bytes) Estimated variance of easting
 * @field cov_e_d number (float, 4 bytes) Covariance of easting and downward measurement
 * @field cov_d_d number (float, 4 bytes) Estimated variance of downward measurement
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution.
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgPosLlhCovGnss = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_POS_LLH_COV_GNSS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPosLlhCovGnss.prototype = Object.create(SBP.prototype);
MsgPosLlhCovGnss.prototype.messageType = "MSG_POS_LLH_COV_GNSS";
MsgPosLlhCovGnss.prototype.msg_type = 0x0231;
MsgPosLlhCovGnss.prototype.constructor = MsgPosLlhCovGnss;
MsgPosLlhCovGnss.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .doublele('lat')
  .doublele('lon')
  .doublele('height')
  .floatle('cov_n_n')
  .floatle('cov_n_e')
  .floatle('cov_n_d')
  .floatle('cov_e_e')
  .floatle('cov_e_d')
  .floatle('cov_d_d')
  .uint8('n_sats')
  .uint8('flags');
MsgPosLlhCovGnss.prototype.fieldSpec = [];
MsgPosLlhCovGnss.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgPosLlhCovGnss.prototype.fieldSpec.push(['lat', 'writeDoubleLE', 8]);
MsgPosLlhCovGnss.prototype.fieldSpec.push(['lon', 'writeDoubleLE', 8]);
MsgPosLlhCovGnss.prototype.fieldSpec.push(['height', 'writeDoubleLE', 8]);
MsgPosLlhCovGnss.prototype.fieldSpec.push(['cov_n_n', 'writeFloatLE', 4]);
MsgPosLlhCovGnss.prototype.fieldSpec.push(['cov_n_e', 'writeFloatLE', 4]);
MsgPosLlhCovGnss.prototype.fieldSpec.push(['cov_n_d', 'writeFloatLE', 4]);
MsgPosLlhCovGnss.prototype.fieldSpec.push(['cov_e_e', 'writeFloatLE', 4]);
MsgPosLlhCovGnss.prototype.fieldSpec.push(['cov_e_d', 'writeFloatLE', 4]);
MsgPosLlhCovGnss.prototype.fieldSpec.push(['cov_d_d', 'writeFloatLE', 4]);
MsgPosLlhCovGnss.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgPosLlhCovGnss.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_ECEF_GNSS (0x022D).
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
 * @field accuracy number (unsigned 16-bit int, 2 bytes) Velocity estimated standard deviation
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgVelEcefGnss = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_ECEF_GNSS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelEcefGnss.prototype = Object.create(SBP.prototype);
MsgVelEcefGnss.prototype.messageType = "MSG_VEL_ECEF_GNSS";
MsgVelEcefGnss.prototype.msg_type = 0x022D;
MsgVelEcefGnss.prototype.constructor = MsgVelEcefGnss;
MsgVelEcefGnss.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('x')
  .int32('y')
  .int32('z')
  .uint16('accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgVelEcefGnss.prototype.fieldSpec = [];
MsgVelEcefGnss.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelEcefGnss.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgVelEcefGnss.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgVelEcefGnss.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgVelEcefGnss.prototype.fieldSpec.push(['accuracy', 'writeUInt16LE', 2]);
MsgVelEcefGnss.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelEcefGnss.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_ECEF_COV_GNSS (0x0235).
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
 * @field cov_x_x number (float, 4 bytes) Estimated variance of x
 * @field cov_x_y number (float, 4 bytes) Estimated covariance of x and y
 * @field cov_x_z number (float, 4 bytes) Estimated covariance of x and z
 * @field cov_y_y number (float, 4 bytes) Estimated variance of y
 * @field cov_y_z number (float, 4 bytes) Estimated covariance of y and z
 * @field cov_z_z number (float, 4 bytes) Estimated variance of z
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgVelEcefCovGnss = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_ECEF_COV_GNSS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelEcefCovGnss.prototype = Object.create(SBP.prototype);
MsgVelEcefCovGnss.prototype.messageType = "MSG_VEL_ECEF_COV_GNSS";
MsgVelEcefCovGnss.prototype.msg_type = 0x0235;
MsgVelEcefCovGnss.prototype.constructor = MsgVelEcefCovGnss;
MsgVelEcefCovGnss.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('x')
  .int32('y')
  .int32('z')
  .floatle('cov_x_x')
  .floatle('cov_x_y')
  .floatle('cov_x_z')
  .floatle('cov_y_y')
  .floatle('cov_y_z')
  .floatle('cov_z_z')
  .uint8('n_sats')
  .uint8('flags');
MsgVelEcefCovGnss.prototype.fieldSpec = [];
MsgVelEcefCovGnss.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelEcefCovGnss.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgVelEcefCovGnss.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgVelEcefCovGnss.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgVelEcefCovGnss.prototype.fieldSpec.push(['cov_x_x', 'writeFloatLE', 4]);
MsgVelEcefCovGnss.prototype.fieldSpec.push(['cov_x_y', 'writeFloatLE', 4]);
MsgVelEcefCovGnss.prototype.fieldSpec.push(['cov_x_z', 'writeFloatLE', 4]);
MsgVelEcefCovGnss.prototype.fieldSpec.push(['cov_y_y', 'writeFloatLE', 4]);
MsgVelEcefCovGnss.prototype.fieldSpec.push(['cov_y_z', 'writeFloatLE', 4]);
MsgVelEcefCovGnss.prototype.fieldSpec.push(['cov_z_z', 'writeFloatLE', 4]);
MsgVelEcefCovGnss.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelEcefCovGnss.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_NED_GNSS (0x022E).
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
 * @field h_accuracy number (unsigned 16-bit int, 2 bytes) Horizontal velocity estimated standard deviation
 * @field v_accuracy number (unsigned 16-bit int, 2 bytes) Vertical velocity estimated standard deviation
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgVelNedGnss = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_NED_GNSS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelNedGnss.prototype = Object.create(SBP.prototype);
MsgVelNedGnss.prototype.messageType = "MSG_VEL_NED_GNSS";
MsgVelNedGnss.prototype.msg_type = 0x022E;
MsgVelNedGnss.prototype.constructor = MsgVelNedGnss;
MsgVelNedGnss.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('n')
  .int32('e')
  .int32('d')
  .uint16('h_accuracy')
  .uint16('v_accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgVelNedGnss.prototype.fieldSpec = [];
MsgVelNedGnss.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelNedGnss.prototype.fieldSpec.push(['n', 'writeInt32LE', 4]);
MsgVelNedGnss.prototype.fieldSpec.push(['e', 'writeInt32LE', 4]);
MsgVelNedGnss.prototype.fieldSpec.push(['d', 'writeInt32LE', 4]);
MsgVelNedGnss.prototype.fieldSpec.push(['h_accuracy', 'writeUInt16LE', 2]);
MsgVelNedGnss.prototype.fieldSpec.push(['v_accuracy', 'writeUInt16LE', 2]);
MsgVelNedGnss.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelNedGnss.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_NED_COV_GNSS (0x0232).
 *
 * This message reports the velocity in local North East Down (NED) coordinates.
 * The NED coordinate system is defined as the local WGS84 tangent plane centered
 * at the current position. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow). This message is similar to
 * the MSG_VEL_NED, but it includes the upper triangular portion of the 3x3
 * covariance matrix.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field n number (signed 32-bit int, 4 bytes) Velocity North coordinate
 * @field e number (signed 32-bit int, 4 bytes) Velocity East coordinate
 * @field d number (signed 32-bit int, 4 bytes) Velocity Down coordinate
 * @field cov_n_n number (float, 4 bytes) Estimated variance of northward measurement
 * @field cov_n_e number (float, 4 bytes) Covariance of northward and eastward measurement
 * @field cov_n_d number (float, 4 bytes) Covariance of northward and downward measurement
 * @field cov_e_e number (float, 4 bytes) Estimated variance of eastward measurement
 * @field cov_e_d number (float, 4 bytes) Covariance of eastward and downward measurement
 * @field cov_d_d number (float, 4 bytes) Estimated variance of downward measurement
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgVelNedCovGnss = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_NED_COV_GNSS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelNedCovGnss.prototype = Object.create(SBP.prototype);
MsgVelNedCovGnss.prototype.messageType = "MSG_VEL_NED_COV_GNSS";
MsgVelNedCovGnss.prototype.msg_type = 0x0232;
MsgVelNedCovGnss.prototype.constructor = MsgVelNedCovGnss;
MsgVelNedCovGnss.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('n')
  .int32('e')
  .int32('d')
  .floatle('cov_n_n')
  .floatle('cov_n_e')
  .floatle('cov_n_d')
  .floatle('cov_e_e')
  .floatle('cov_e_d')
  .floatle('cov_d_d')
  .uint8('n_sats')
  .uint8('flags');
MsgVelNedCovGnss.prototype.fieldSpec = [];
MsgVelNedCovGnss.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelNedCovGnss.prototype.fieldSpec.push(['n', 'writeInt32LE', 4]);
MsgVelNedCovGnss.prototype.fieldSpec.push(['e', 'writeInt32LE', 4]);
MsgVelNedCovGnss.prototype.fieldSpec.push(['d', 'writeInt32LE', 4]);
MsgVelNedCovGnss.prototype.fieldSpec.push(['cov_n_n', 'writeFloatLE', 4]);
MsgVelNedCovGnss.prototype.fieldSpec.push(['cov_n_e', 'writeFloatLE', 4]);
MsgVelNedCovGnss.prototype.fieldSpec.push(['cov_n_d', 'writeFloatLE', 4]);
MsgVelNedCovGnss.prototype.fieldSpec.push(['cov_e_e', 'writeFloatLE', 4]);
MsgVelNedCovGnss.prototype.fieldSpec.push(['cov_e_d', 'writeFloatLE', 4]);
MsgVelNedCovGnss.prototype.fieldSpec.push(['cov_d_d', 'writeFloatLE', 4]);
MsgVelNedCovGnss.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelNedCovGnss.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_BODY (0x0213).
 *
 * This message reports the velocity in the Vehicle Body Frame. By convention, the
 * x-axis should point out the nose of the vehicle and represent the forward
 * direction, while as the y-axis should point out the right hand side of the
 * vehicle. Since this is a right handed system, z should point out the bottom of
 * the vehicle. The orientation and origin of the Vehicle Body Frame are specified
 * via the device settings. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow). This message is only produced
 * by inertial versions of Swift products and is not available from Piksi Multi or
 * Duro.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (signed 32-bit int, 4 bytes) Velocity in x direction
 * @field y number (signed 32-bit int, 4 bytes) Velocity in y direction
 * @field z number (signed 32-bit int, 4 bytes) Velocity in z direction
 * @field cov_x_x number (float, 4 bytes) Estimated variance of x
 * @field cov_x_y number (float, 4 bytes) Covariance of x and y
 * @field cov_x_z number (float, 4 bytes) Covariance of x and z
 * @field cov_y_y number (float, 4 bytes) Estimated variance of y
 * @field cov_y_z number (float, 4 bytes) Covariance of y and z
 * @field cov_z_z number (float, 4 bytes) Estimated variance of z
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgVelBody = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_BODY";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelBody.prototype = Object.create(SBP.prototype);
MsgVelBody.prototype.messageType = "MSG_VEL_BODY";
MsgVelBody.prototype.msg_type = 0x0213;
MsgVelBody.prototype.constructor = MsgVelBody;
MsgVelBody.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('x')
  .int32('y')
  .int32('z')
  .floatle('cov_x_x')
  .floatle('cov_x_y')
  .floatle('cov_x_z')
  .floatle('cov_y_y')
  .floatle('cov_y_z')
  .floatle('cov_z_z')
  .uint8('n_sats')
  .uint8('flags');
MsgVelBody.prototype.fieldSpec = [];
MsgVelBody.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelBody.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgVelBody.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgVelBody.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgVelBody.prototype.fieldSpec.push(['cov_x_x', 'writeFloatLE', 4]);
MsgVelBody.prototype.fieldSpec.push(['cov_x_y', 'writeFloatLE', 4]);
MsgVelBody.prototype.fieldSpec.push(['cov_x_z', 'writeFloatLE', 4]);
MsgVelBody.prototype.fieldSpec.push(['cov_y_y', 'writeFloatLE', 4]);
MsgVelBody.prototype.fieldSpec.push(['cov_y_z', 'writeFloatLE', 4]);
MsgVelBody.prototype.fieldSpec.push(['cov_z_z', 'writeFloatLE', 4]);
MsgVelBody.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelBody.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_AGE_CORRECTIONS (0x0210).
 *
 * This message reports the Age of the corrections used for the current
 * Differential solution
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field age number (unsigned 16-bit int, 2 bytes) Age of the corrections (0xFFFF indicates invalid)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAgeCorrections = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_AGE_CORRECTIONS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAgeCorrections.prototype = Object.create(SBP.prototype);
MsgAgeCorrections.prototype.messageType = "MSG_AGE_CORRECTIONS";
MsgAgeCorrections.prototype.msg_type = 0x0210;
MsgAgeCorrections.prototype.constructor = MsgAgeCorrections;
MsgAgeCorrections.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint16('age');
MsgAgeCorrections.prototype.fieldSpec = [];
MsgAgeCorrections.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgAgeCorrections.prototype.fieldSpec.push(['age', 'writeUInt16LE', 2]);

/**
 * SBP class for message MSG_GPS_TIME_DEP_A (0x0100).
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
 * @field ns_residual number (signed 32-bit int, 4 bytes) Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000)
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags (reserved)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgGpsTimeDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_GPS_TIME_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgGpsTimeDepA.prototype = Object.create(SBP.prototype);
MsgGpsTimeDepA.prototype.messageType = "MSG_GPS_TIME_DEP_A";
MsgGpsTimeDepA.prototype.msg_type = 0x0100;
MsgGpsTimeDepA.prototype.constructor = MsgGpsTimeDepA;
MsgGpsTimeDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint16('wn')
  .uint32('tow')
  .int32('ns_residual')
  .uint8('flags');
MsgGpsTimeDepA.prototype.fieldSpec = [];
MsgGpsTimeDepA.prototype.fieldSpec.push(['wn', 'writeUInt16LE', 2]);
MsgGpsTimeDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgGpsTimeDepA.prototype.fieldSpec.push(['ns_residual', 'writeInt32LE', 4]);
MsgGpsTimeDepA.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_DOPS_DEP_A (0x0206).
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
var MsgDopsDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_DOPS_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgDopsDepA.prototype = Object.create(SBP.prototype);
MsgDopsDepA.prototype.messageType = "MSG_DOPS_DEP_A";
MsgDopsDepA.prototype.msg_type = 0x0206;
MsgDopsDepA.prototype.constructor = MsgDopsDepA;
MsgDopsDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint16('gdop')
  .uint16('pdop')
  .uint16('tdop')
  .uint16('hdop')
  .uint16('vdop');
MsgDopsDepA.prototype.fieldSpec = [];
MsgDopsDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgDopsDepA.prototype.fieldSpec.push(['gdop', 'writeUInt16LE', 2]);
MsgDopsDepA.prototype.fieldSpec.push(['pdop', 'writeUInt16LE', 2]);
MsgDopsDepA.prototype.fieldSpec.push(['tdop', 'writeUInt16LE', 2]);
MsgDopsDepA.prototype.fieldSpec.push(['hdop', 'writeUInt16LE', 2]);
MsgDopsDepA.prototype.fieldSpec.push(['vdop', 'writeUInt16LE', 2]);

/**
 * SBP class for message MSG_POS_ECEF_DEP_A (0x0200).
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
var MsgPosEcefDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_POS_ECEF_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPosEcefDepA.prototype = Object.create(SBP.prototype);
MsgPosEcefDepA.prototype.messageType = "MSG_POS_ECEF_DEP_A";
MsgPosEcefDepA.prototype.msg_type = 0x0200;
MsgPosEcefDepA.prototype.constructor = MsgPosEcefDepA;
MsgPosEcefDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .doublele('x')
  .doublele('y')
  .doublele('z')
  .uint16('accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgPosEcefDepA.prototype.fieldSpec = [];
MsgPosEcefDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgPosEcefDepA.prototype.fieldSpec.push(['x', 'writeDoubleLE', 8]);
MsgPosEcefDepA.prototype.fieldSpec.push(['y', 'writeDoubleLE', 8]);
MsgPosEcefDepA.prototype.fieldSpec.push(['z', 'writeDoubleLE', 8]);
MsgPosEcefDepA.prototype.fieldSpec.push(['accuracy', 'writeUInt16LE', 2]);
MsgPosEcefDepA.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgPosEcefDepA.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_POS_LLH_DEP_A (0x0201).
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
var MsgPosLlhDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_POS_LLH_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPosLlhDepA.prototype = Object.create(SBP.prototype);
MsgPosLlhDepA.prototype.messageType = "MSG_POS_LLH_DEP_A";
MsgPosLlhDepA.prototype.msg_type = 0x0201;
MsgPosLlhDepA.prototype.constructor = MsgPosLlhDepA;
MsgPosLlhDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .doublele('lat')
  .doublele('lon')
  .doublele('height')
  .uint16('h_accuracy')
  .uint16('v_accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgPosLlhDepA.prototype.fieldSpec = [];
MsgPosLlhDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgPosLlhDepA.prototype.fieldSpec.push(['lat', 'writeDoubleLE', 8]);
MsgPosLlhDepA.prototype.fieldSpec.push(['lon', 'writeDoubleLE', 8]);
MsgPosLlhDepA.prototype.fieldSpec.push(['height', 'writeDoubleLE', 8]);
MsgPosLlhDepA.prototype.fieldSpec.push(['h_accuracy', 'writeUInt16LE', 2]);
MsgPosLlhDepA.prototype.fieldSpec.push(['v_accuracy', 'writeUInt16LE', 2]);
MsgPosLlhDepA.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgPosLlhDepA.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_BASELINE_ECEF_DEP_A (0x0202).
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
 * @field accuracy number (unsigned 16-bit int, 2 bytes) Position accuracy estimate
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBaselineEcefDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BASELINE_ECEF_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBaselineEcefDepA.prototype = Object.create(SBP.prototype);
MsgBaselineEcefDepA.prototype.messageType = "MSG_BASELINE_ECEF_DEP_A";
MsgBaselineEcefDepA.prototype.msg_type = 0x0202;
MsgBaselineEcefDepA.prototype.constructor = MsgBaselineEcefDepA;
MsgBaselineEcefDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('x')
  .int32('y')
  .int32('z')
  .uint16('accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgBaselineEcefDepA.prototype.fieldSpec = [];
MsgBaselineEcefDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgBaselineEcefDepA.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgBaselineEcefDepA.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgBaselineEcefDepA.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgBaselineEcefDepA.prototype.fieldSpec.push(['accuracy', 'writeUInt16LE', 2]);
MsgBaselineEcefDepA.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgBaselineEcefDepA.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_BASELINE_NED_DEP_A (0x0203).
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
var MsgBaselineNedDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BASELINE_NED_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBaselineNedDepA.prototype = Object.create(SBP.prototype);
MsgBaselineNedDepA.prototype.messageType = "MSG_BASELINE_NED_DEP_A";
MsgBaselineNedDepA.prototype.msg_type = 0x0203;
MsgBaselineNedDepA.prototype.constructor = MsgBaselineNedDepA;
MsgBaselineNedDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('n')
  .int32('e')
  .int32('d')
  .uint16('h_accuracy')
  .uint16('v_accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgBaselineNedDepA.prototype.fieldSpec = [];
MsgBaselineNedDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgBaselineNedDepA.prototype.fieldSpec.push(['n', 'writeInt32LE', 4]);
MsgBaselineNedDepA.prototype.fieldSpec.push(['e', 'writeInt32LE', 4]);
MsgBaselineNedDepA.prototype.fieldSpec.push(['d', 'writeInt32LE', 4]);
MsgBaselineNedDepA.prototype.fieldSpec.push(['h_accuracy', 'writeUInt16LE', 2]);
MsgBaselineNedDepA.prototype.fieldSpec.push(['v_accuracy', 'writeUInt16LE', 2]);
MsgBaselineNedDepA.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgBaselineNedDepA.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_ECEF_DEP_A (0x0204).
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
var MsgVelEcefDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_ECEF_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelEcefDepA.prototype = Object.create(SBP.prototype);
MsgVelEcefDepA.prototype.messageType = "MSG_VEL_ECEF_DEP_A";
MsgVelEcefDepA.prototype.msg_type = 0x0204;
MsgVelEcefDepA.prototype.constructor = MsgVelEcefDepA;
MsgVelEcefDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('x')
  .int32('y')
  .int32('z')
  .uint16('accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgVelEcefDepA.prototype.fieldSpec = [];
MsgVelEcefDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelEcefDepA.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgVelEcefDepA.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgVelEcefDepA.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgVelEcefDepA.prototype.fieldSpec.push(['accuracy', 'writeUInt16LE', 2]);
MsgVelEcefDepA.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelEcefDepA.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_NED_DEP_A (0x0205).
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
var MsgVelNedDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_NED_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelNedDepA.prototype = Object.create(SBP.prototype);
MsgVelNedDepA.prototype.messageType = "MSG_VEL_NED_DEP_A";
MsgVelNedDepA.prototype.msg_type = 0x0205;
MsgVelNedDepA.prototype.constructor = MsgVelNedDepA;
MsgVelNedDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('n')
  .int32('e')
  .int32('d')
  .uint16('h_accuracy')
  .uint16('v_accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgVelNedDepA.prototype.fieldSpec = [];
MsgVelNedDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelNedDepA.prototype.fieldSpec.push(['n', 'writeInt32LE', 4]);
MsgVelNedDepA.prototype.fieldSpec.push(['e', 'writeInt32LE', 4]);
MsgVelNedDepA.prototype.fieldSpec.push(['d', 'writeInt32LE', 4]);
MsgVelNedDepA.prototype.fieldSpec.push(['h_accuracy', 'writeUInt16LE', 2]);
MsgVelNedDepA.prototype.fieldSpec.push(['v_accuracy', 'writeUInt16LE', 2]);
MsgVelNedDepA.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelNedDepA.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_BASELINE_HEADING_DEP_A (0x0207).
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
var MsgBaselineHeadingDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BASELINE_HEADING_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBaselineHeadingDepA.prototype = Object.create(SBP.prototype);
MsgBaselineHeadingDepA.prototype.messageType = "MSG_BASELINE_HEADING_DEP_A";
MsgBaselineHeadingDepA.prototype.msg_type = 0x0207;
MsgBaselineHeadingDepA.prototype.constructor = MsgBaselineHeadingDepA;
MsgBaselineHeadingDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint32('heading')
  .uint8('n_sats')
  .uint8('flags');
MsgBaselineHeadingDepA.prototype.fieldSpec = [];
MsgBaselineHeadingDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgBaselineHeadingDepA.prototype.fieldSpec.push(['heading', 'writeUInt32LE', 4]);
MsgBaselineHeadingDepA.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgBaselineHeadingDepA.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_PROTECTION_LEVEL (0x0216).
 *
 * This message reports the local vertical and horizontal protection levels
 * associated with a given LLH position solution. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field vpl number (unsigned 16-bit int, 2 bytes) Vertical protection level
 * @field hpl number (unsigned 16-bit int, 2 bytes) Horizontal protection level
 * @field lat number (float, 8 bytes) Latitude
 * @field lon number (float, 8 bytes) Longitude
 * @field height number (float, 8 bytes) Height
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgProtectionLevel = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_PROTECTION_LEVEL";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgProtectionLevel.prototype = Object.create(SBP.prototype);
MsgProtectionLevel.prototype.messageType = "MSG_PROTECTION_LEVEL";
MsgProtectionLevel.prototype.msg_type = 0x0216;
MsgProtectionLevel.prototype.constructor = MsgProtectionLevel;
MsgProtectionLevel.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint16('vpl')
  .uint16('hpl')
  .doublele('lat')
  .doublele('lon')
  .doublele('height')
  .uint8('flags');
MsgProtectionLevel.prototype.fieldSpec = [];
MsgProtectionLevel.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgProtectionLevel.prototype.fieldSpec.push(['vpl', 'writeUInt16LE', 2]);
MsgProtectionLevel.prototype.fieldSpec.push(['hpl', 'writeUInt16LE', 2]);
MsgProtectionLevel.prototype.fieldSpec.push(['lat', 'writeDoubleLE', 8]);
MsgProtectionLevel.prototype.fieldSpec.push(['lon', 'writeDoubleLE', 8]);
MsgProtectionLevel.prototype.fieldSpec.push(['height', 'writeDoubleLE', 8]);
MsgProtectionLevel.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

module.exports = {
  0x0102: MsgGpsTime,
  MsgGpsTime: MsgGpsTime,
  0x0103: MsgUtcTime,
  MsgUtcTime: MsgUtcTime,
  0x0208: MsgDops,
  MsgDops: MsgDops,
  0x0209: MsgPosEcef,
  MsgPosEcef: MsgPosEcef,
  0x0214: MsgPosEcefCov,
  MsgPosEcefCov: MsgPosEcefCov,
  0x020A: MsgPosLlh,
  MsgPosLlh: MsgPosLlh,
  0x0211: MsgPosLlhCov,
  MsgPosLlhCov: MsgPosLlhCov,
  0x020B: MsgBaselineEcef,
  MsgBaselineEcef: MsgBaselineEcef,
  0x020C: MsgBaselineNed,
  MsgBaselineNed: MsgBaselineNed,
  0x020D: MsgVelEcef,
  MsgVelEcef: MsgVelEcef,
  0x0215: MsgVelEcefCov,
  MsgVelEcefCov: MsgVelEcefCov,
  0x020E: MsgVelNed,
  MsgVelNed: MsgVelNed,
  0x0212: MsgVelNedCov,
  MsgVelNedCov: MsgVelNedCov,
  0x0229: MsgPosEcefGnss,
  MsgPosEcefGnss: MsgPosEcefGnss,
  0x0234: MsgPosEcefCovGnss,
  MsgPosEcefCovGnss: MsgPosEcefCovGnss,
  0x022A: MsgPosLlhGnss,
  MsgPosLlhGnss: MsgPosLlhGnss,
  0x0231: MsgPosLlhCovGnss,
  MsgPosLlhCovGnss: MsgPosLlhCovGnss,
  0x022D: MsgVelEcefGnss,
  MsgVelEcefGnss: MsgVelEcefGnss,
  0x0235: MsgVelEcefCovGnss,
  MsgVelEcefCovGnss: MsgVelEcefCovGnss,
  0x022E: MsgVelNedGnss,
  MsgVelNedGnss: MsgVelNedGnss,
  0x0232: MsgVelNedCovGnss,
  MsgVelNedCovGnss: MsgVelNedCovGnss,
  0x0213: MsgVelBody,
  MsgVelBody: MsgVelBody,
  0x0210: MsgAgeCorrections,
  MsgAgeCorrections: MsgAgeCorrections,
  0x0100: MsgGpsTimeDepA,
  MsgGpsTimeDepA: MsgGpsTimeDepA,
  0x0206: MsgDopsDepA,
  MsgDopsDepA: MsgDopsDepA,
  0x0200: MsgPosEcefDepA,
  MsgPosEcefDepA: MsgPosEcefDepA,
  0x0201: MsgPosLlhDepA,
  MsgPosLlhDepA: MsgPosLlhDepA,
  0x0202: MsgBaselineEcefDepA,
  MsgBaselineEcefDepA: MsgBaselineEcefDepA,
  0x0203: MsgBaselineNedDepA,
  MsgBaselineNedDepA: MsgBaselineNedDepA,
  0x0204: MsgVelEcefDepA,
  MsgVelEcefDepA: MsgVelEcefDepA,
  0x0205: MsgVelNedDepA,
  MsgVelNedDepA: MsgVelNedDepA,
  0x0207: MsgBaselineHeadingDepA,
  MsgBaselineHeadingDepA: MsgBaselineHeadingDepA,
  0x0216: MsgProtectionLevel,
  MsgProtectionLevel: MsgProtectionLevel,
}