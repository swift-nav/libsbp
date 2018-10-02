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
 * Automatically generated from piksi/yaml/swiftnav/sbp/orientation.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Orientation Messages
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;

/**
 * SBP class for message MSG_BASELINE_HEADING (0x020F).
 *
 * This message reports the baseline heading pointing from the base station to the
 * rover relative to True North. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow). It is intended that time-
 * matched RTK mode is used when the base station is moving.
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
MsgBaselineHeading.prototype.msg_type = 0x020F;
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

/**
 * SBP class for message MSG_ORIENT_QUAT (0x0220).
 *
 * This message reports the quaternion vector describing the vehicle body frame's
 * orientation with respect to a local-level NED frame. The components of the
 * vector should sum to a unit vector assuming that the LSB of each component as a
 * value of 2^-31. This message will only be available in future INS versions of
 * Swift Products and is not produced by Piksi Multi  or Duro.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field w number (signed 32-bit int, 4 bytes) Real component
 * @field x number (signed 32-bit int, 4 bytes) 1st imaginary component
 * @field y number (signed 32-bit int, 4 bytes) 2nd imaginary component
 * @field z number (signed 32-bit int, 4 bytes) 3rd imaginary component
 * @field w_accuracy number (float, 4 bytes) Estimated standard deviation of w
 * @field x_accuracy number (float, 4 bytes) Estimated standard deviation of x
 * @field y_accuracy number (float, 4 bytes) Estimated standard deviation of y
 * @field z_accuracy number (float, 4 bytes) Estimated standard deviation of z
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgOrientQuat = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ORIENT_QUAT";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgOrientQuat.prototype = Object.create(SBP.prototype);
MsgOrientQuat.prototype.messageType = "MSG_ORIENT_QUAT";
MsgOrientQuat.prototype.msg_type = 0x0220;
MsgOrientQuat.prototype.constructor = MsgOrientQuat;
MsgOrientQuat.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('w')
  .int32('x')
  .int32('y')
  .int32('z')
  .floatle('w_accuracy')
  .floatle('x_accuracy')
  .floatle('y_accuracy')
  .floatle('z_accuracy')
  .uint8('flags');
MsgOrientQuat.prototype.fieldSpec = [];
MsgOrientQuat.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['w', 'writeInt32LE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['w_accuracy', 'writeFloatLE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['x_accuracy', 'writeFloatLE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['y_accuracy', 'writeFloatLE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['z_accuracy', 'writeFloatLE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_ORIENT_EULER (0x0221).
 *
 * This message reports the yaw, pitch, and roll angles of the vehicle body frame.
 * The rotations should applied intrinsically in the order yaw, pitch, and roll  in
 * order to rotate the from a frame aligned with the local-level NED frame  to the
 * vehicle body frame.  This message will only be available in future  INS versions
 * of Swift Products and is not produced by Piksi Multi or Duro.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field roll number (signed 32-bit int, 4 bytes) rotation about the forward axis of the vehicle
 * @field pitch number (signed 32-bit int, 4 bytes) rotation about the rightward axis of the vehicle
 * @field yaw number (signed 32-bit int, 4 bytes) rotation about the downward axis of the vehicle
 * @field roll_accuracy number (float, 4 bytes) Estimated standard deviation of roll
 * @field pitch_accuracy number (float, 4 bytes) Estimated standard deviation of pitch
 * @field yaw_accuracy number (float, 4 bytes) Estimated standard deviation of yaw
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgOrientEuler = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ORIENT_EULER";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgOrientEuler.prototype = Object.create(SBP.prototype);
MsgOrientEuler.prototype.messageType = "MSG_ORIENT_EULER";
MsgOrientEuler.prototype.msg_type = 0x0221;
MsgOrientEuler.prototype.constructor = MsgOrientEuler;
MsgOrientEuler.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('roll')
  .int32('pitch')
  .int32('yaw')
  .floatle('roll_accuracy')
  .floatle('pitch_accuracy')
  .floatle('yaw_accuracy')
  .uint8('flags');
MsgOrientEuler.prototype.fieldSpec = [];
MsgOrientEuler.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgOrientEuler.prototype.fieldSpec.push(['roll', 'writeInt32LE', 4]);
MsgOrientEuler.prototype.fieldSpec.push(['pitch', 'writeInt32LE', 4]);
MsgOrientEuler.prototype.fieldSpec.push(['yaw', 'writeInt32LE', 4]);
MsgOrientEuler.prototype.fieldSpec.push(['roll_accuracy', 'writeFloatLE', 4]);
MsgOrientEuler.prototype.fieldSpec.push(['pitch_accuracy', 'writeFloatLE', 4]);
MsgOrientEuler.prototype.fieldSpec.push(['yaw_accuracy', 'writeFloatLE', 4]);
MsgOrientEuler.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_ANGULAR_RATE (0x0222).
 *
 * This message reports the orientation rates in the vehicle body frame.  The
 * values represent the measurements a strapped down gyroscope would  make and are
 * not equivalent to the time derivative of the Euler angles. The orientation and
 * origin of the user frame is specified via device settings. By convention, the
 * vehicle x-axis is expected to be aligned with the forward direction, while the
 * vehicle y-axis is expected to be aligned with the right direction, and the
 * vehicle z-axis should be aligned with the down direction. This message will only
 * be available in future INS versions of Swift Products  and is not produced by
 * Piksi Multi or Duro.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (signed 32-bit int, 4 bytes) angular rate about x axis
 * @field y number (signed 32-bit int, 4 bytes) angular rate about y axis
 * @field z number (signed 32-bit int, 4 bytes) angular rate about z axis
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAngularRate = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ANGULAR_RATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAngularRate.prototype = Object.create(SBP.prototype);
MsgAngularRate.prototype.messageType = "MSG_ANGULAR_RATE";
MsgAngularRate.prototype.msg_type = 0x0222;
MsgAngularRate.prototype.constructor = MsgAngularRate;
MsgAngularRate.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('x')
  .int32('y')
  .int32('z')
  .uint8('flags');
MsgAngularRate.prototype.fieldSpec = [];
MsgAngularRate.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgAngularRate.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgAngularRate.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgAngularRate.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgAngularRate.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

module.exports = {
  0x020F: MsgBaselineHeading,
  MsgBaselineHeading: MsgBaselineHeading,
  0x0220: MsgOrientQuat,
  MsgOrientQuat: MsgOrientQuat,
  0x0221: MsgOrientEuler,
  MsgOrientEuler: MsgOrientEuler,
  0x0222: MsgAngularRate,
  MsgAngularRate: MsgAngularRate,
}