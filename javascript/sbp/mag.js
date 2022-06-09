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
 * Automatically generated from spec/yaml/swiftnav/sbp/mag.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Magnetometer (mag) messages.
***********************/

let SBP = require('./sbp');
let Parser = require('./parser');
let Int64 = require('node-int64');
let UInt64 = require('cuint').UINT64;

/**
 * SBP class for message MSG_MAG_RAW (0x0902).
 *
 * Raw data from the magnetometer.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) Milliseconds since start of GPS week. If the high bit is set, the time is
 *   unknown or invalid.
 * @field tow_f number (unsigned 8-bit int, 1 byte) Milliseconds since start of GPS week, fractional part
 * @field mag_x number (signed 16-bit int, 2 bytes) Magnetic field in the body frame X axis
 * @field mag_y number (signed 16-bit int, 2 bytes) Magnetic field in the body frame Y axis
 * @field mag_z number (signed 16-bit int, 2 bytes) Magnetic field in the body frame Z axis
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgMagRaw = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_MAG_RAW";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgMagRaw.prototype = Object.create(SBP.prototype);
MsgMagRaw.prototype.messageType = "MSG_MAG_RAW";
MsgMagRaw.prototype.msg_type = 0x0902;
MsgMagRaw.prototype.constructor = MsgMagRaw;
MsgMagRaw.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint8('tow_f')
  .int16('mag_x')
  .int16('mag_y')
  .int16('mag_z');
MsgMagRaw.prototype.fieldSpec = [];
MsgMagRaw.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgMagRaw.prototype.fieldSpec.push(['tow_f', 'writeUInt8', 1]);
MsgMagRaw.prototype.fieldSpec.push(['mag_x', 'writeInt16LE', 2]);
MsgMagRaw.prototype.fieldSpec.push(['mag_y', 'writeInt16LE', 2]);
MsgMagRaw.prototype.fieldSpec.push(['mag_z', 'writeInt16LE', 2]);

module.exports = {
  0x0902: MsgMagRaw,
  MsgMagRaw: MsgMagRaw,
}