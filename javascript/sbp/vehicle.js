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
 * Automatically generated from piksi/yaml/swiftnav/sbp/vehicle.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages from a vehicle.
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;

/**
 * SBP class for message MSG_ODOMETRY (0x0903).
 *
 * Message representing the x component of vehicle velocity in the user frame at
 * the odometry reference point(s) specified by the user. The offset for the
 * odometry reference point and  the definition and origin of the user frame are
 * defined through the device settings interface. There are 4 possible user-defined
 * sources of this message  which are labeled arbitrarily  source 0 through 3.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) Time field representing either milliseconds in the GPS Week or local CPU time
 *   from the producing system in milliseconds.  See the tow_source flag for the
 *   exact source of this timestamp.
 * @field velocity number (signed 32-bit int, 4 bytes) The signed forward component of vehicle velocity.
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgOdometry = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ODOMETRY";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgOdometry.prototype = Object.create(SBP.prototype);
MsgOdometry.prototype.messageType = "MSG_ODOMETRY";
MsgOdometry.prototype.msg_type = 0x0903;
MsgOdometry.prototype.constructor = MsgOdometry;
MsgOdometry.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('velocity')
  .uint8('flags');
MsgOdometry.prototype.fieldSpec = [];
MsgOdometry.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgOdometry.prototype.fieldSpec.push(['velocity', 'writeInt32LE', 4]);
MsgOdometry.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_WHEELTICK (0x0904).
 *
 * Message containing the accumulated distance travelled by a wheel located at an
 * odometry reference point defined by the user. The offset for the odometry
 * reference point and the definition and origin of the user frame are defined
 * through the device settings interface. The source of this message is identified
 * by the source field, which is an integer ranging from 0 to 255. The timestamp
 * associated with this message should represent the time when the accumulated tick
 * count reached the value given by the contents of this message as accurately as
 * possible.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field time number (unsigned 64-bit int, 8 bytes) Time field representing either microseconds since the last PPS, microseconds in
 *   the GPS Week or local CPU time from the producing system in microseconds. See
 *   the synch_type field for the exact meaning of this timestamp.
 * @field flags number (unsigned 8-bit int, 1 byte) Field indicating the type of timestamp contained in the time field.
 * @field source number (unsigned 8-bit int, 1 byte) ID of the sensor producing this message
 * @field ticks number (signed 32-bit int, 4 bytes) Free-running counter of the accumulated distance for this sensor. The counter
 *   should be incrementing if travelling into one direction and decrementing when
 *   travelling in the opposite direction.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgWheeltick = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_WHEELTICK";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgWheeltick.prototype = Object.create(SBP.prototype);
MsgWheeltick.prototype.messageType = "MSG_WHEELTICK";
MsgWheeltick.prototype.msg_type = 0x0904;
MsgWheeltick.prototype.constructor = MsgWheeltick;
MsgWheeltick.prototype.parser = new Parser()
  .endianess('little')
  .uint64('time')
  .uint8('flags')
  .uint8('source')
  .int32('ticks');
MsgWheeltick.prototype.fieldSpec = [];
MsgWheeltick.prototype.fieldSpec.push(['time', 'writeUInt64LE', 8]);
MsgWheeltick.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);
MsgWheeltick.prototype.fieldSpec.push(['source', 'writeUInt8', 1]);
MsgWheeltick.prototype.fieldSpec.push(['ticks', 'writeInt32LE', 4]);

module.exports = {
  0x0903: MsgOdometry,
  MsgOdometry: MsgOdometry,
  0x0904: MsgWheeltick,
  MsgWheeltick: MsgWheeltick,
}