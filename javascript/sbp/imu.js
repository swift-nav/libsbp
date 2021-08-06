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
 * Automatically generated from piksi/yaml/swiftnav/sbp/imu.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Inertial Measurement Unit (IMU) messages.
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;

/**
 * SBP class for message MSG_IMU_RAW (0x0900).
 *
 * Raw data from the Inertial Measurement Unit, containing accelerometer and
 * gyroscope readings. The sense of the measurements are to be aligned with the
 * indications on the device itself. Measurement units, which are specific to the
 * device hardware and settings, are communicated via the MSG_IMU_AUX message. If
 * using "time since startup" time tags, the receiving end will expect a
 * `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to synchronise IMU
 * measurements with GNSS. The timestamp must wrap around to zero when reaching one
 * week (604800 seconds).  The time-tagging mode should not change throughout a
 * run.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) Milliseconds since reference epoch and time status.
 * @field tow_f number (unsigned 8-bit int, 1 byte) Milliseconds since reference epoch, fractional part
 * @field acc_x number (signed 16-bit int, 2 bytes) Acceleration in the IMU frame X axis
 * @field acc_y number (signed 16-bit int, 2 bytes) Acceleration in the IMU frame Y axis
 * @field acc_z number (signed 16-bit int, 2 bytes) Acceleration in the IMU frame Z axis
 * @field gyr_x number (signed 16-bit int, 2 bytes) Angular rate around IMU frame X axis
 * @field gyr_y number (signed 16-bit int, 2 bytes) Angular rate around IMU frame Y axis
 * @field gyr_z number (signed 16-bit int, 2 bytes) Angular rate around IMU frame Z axis
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgImuRaw = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_IMU_RAW";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgImuRaw.prototype = Object.create(SBP.prototype);
MsgImuRaw.prototype.messageType = "MSG_IMU_RAW";
MsgImuRaw.prototype.msg_type = 0x0900;
MsgImuRaw.prototype.constructor = MsgImuRaw;
MsgImuRaw.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint8('tow_f')
  .int16('acc_x')
  .int16('acc_y')
  .int16('acc_z')
  .int16('gyr_x')
  .int16('gyr_y')
  .int16('gyr_z');
MsgImuRaw.prototype.fieldSpec = [];
MsgImuRaw.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgImuRaw.prototype.fieldSpec.push(['tow_f', 'writeUInt8', 1]);
MsgImuRaw.prototype.fieldSpec.push(['acc_x', 'writeInt16LE', 2]);
MsgImuRaw.prototype.fieldSpec.push(['acc_y', 'writeInt16LE', 2]);
MsgImuRaw.prototype.fieldSpec.push(['acc_z', 'writeInt16LE', 2]);
MsgImuRaw.prototype.fieldSpec.push(['gyr_x', 'writeInt16LE', 2]);
MsgImuRaw.prototype.fieldSpec.push(['gyr_y', 'writeInt16LE', 2]);
MsgImuRaw.prototype.fieldSpec.push(['gyr_z', 'writeInt16LE', 2]);

/**
 * SBP class for message MSG_IMU_AUX (0x0901).
 *
 * Auxiliary data specific to a particular IMU. The `imu_type` field will always be
 * consistent but the rest of the payload is device specific and depends on the
 * value of `imu_type`.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field imu_type number (unsigned 8-bit int, 1 byte) IMU type
 * @field temp number (signed 16-bit int, 2 bytes) Raw IMU temperature
 * @field imu_conf number (unsigned 8-bit int, 1 byte) IMU configuration
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgImuAux = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_IMU_AUX";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgImuAux.prototype = Object.create(SBP.prototype);
MsgImuAux.prototype.messageType = "MSG_IMU_AUX";
MsgImuAux.prototype.msg_type = 0x0901;
MsgImuAux.prototype.constructor = MsgImuAux;
MsgImuAux.prototype.parser = new Parser()
  .endianess('little')
  .uint8('imu_type')
  .int16('temp')
  .uint8('imu_conf');
MsgImuAux.prototype.fieldSpec = [];
MsgImuAux.prototype.fieldSpec.push(['imu_type', 'writeUInt8', 1]);
MsgImuAux.prototype.fieldSpec.push(['temp', 'writeInt16LE', 2]);
MsgImuAux.prototype.fieldSpec.push(['imu_conf', 'writeUInt8', 1]);

module.exports = {
  0x0900: MsgImuRaw,
  MsgImuRaw: MsgImuRaw,
  0x0901: MsgImuAux,
  MsgImuAux: MsgImuAux,
}