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

module.exports = {
  0x0903: MsgOdometry,
  MsgOdometry: MsgOdometry,
}