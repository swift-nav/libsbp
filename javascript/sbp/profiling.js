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
 * Automatically generated from spec/yaml/swiftnav/sbp/profiling.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Standardized profiling messages from Swift Navigation devices.
***********************/

let SBP = require('./sbp');
let Parser = require('./parser');
let Int64 = require('node-int64');
let UInt64 = require('cuint').UINT64;

/**
 * SBP class for message MSG_MEASUREMENT_POINT (0xCF00).
 *
 * Tracks execution time of certain code paths in specially built products. This
 * message should only be expected and processed on the direction of Swift's
 * engineering teams.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field total_time number (unsigned 32-bit int, 4 bytes) Total time spent in measurement point (microseconds)
 * @field num_executions number (unsigned 16-bit int, 2 bytes) Number of times measurement point has executed
 * @field min number (unsigned 32-bit int, 4 bytes) Minimum execution time (microseconds)
 * @field max number (unsigned 32-bit int, 4 bytes) Maximum execution time (microseconds)
 * @field return_addr number (unsigned 64-bit int, 8 bytes) Return address
 * @field id number (unsigned 64-bit int, 8 bytes) Unique ID
 * @field slice_time number (unsigned 64-bit int, 8 bytes) CPU slice time (milliseconds)
 * @field line number (unsigned 16-bit int, 2 bytes) Line number
 * @field func string Function name
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgMeasurementPoint = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_MEASUREMENT_POINT";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgMeasurementPoint.prototype = Object.create(SBP.prototype);
MsgMeasurementPoint.prototype.messageType = "MSG_MEASUREMENT_POINT";
MsgMeasurementPoint.prototype.msg_type = 0xCF00;
MsgMeasurementPoint.prototype.constructor = MsgMeasurementPoint;
MsgMeasurementPoint.prototype.parser = new Parser()
  .endianess('little')
  .uint32('total_time')
  .uint16('num_executions')
  .uint32('min')
  .uint32('max')
  .uint64('return_addr')
  .uint64('id')
  .uint64('slice_time')
  .uint16('line')
  .string('func', { greedy: true });
MsgMeasurementPoint.prototype.fieldSpec = [];
MsgMeasurementPoint.prototype.fieldSpec.push(['total_time', 'writeUInt32LE', 4]);
MsgMeasurementPoint.prototype.fieldSpec.push(['num_executions', 'writeUInt16LE', 2]);
MsgMeasurementPoint.prototype.fieldSpec.push(['min', 'writeUInt32LE', 4]);
MsgMeasurementPoint.prototype.fieldSpec.push(['max', 'writeUInt32LE', 4]);
MsgMeasurementPoint.prototype.fieldSpec.push(['return_addr', 'writeUInt64LE', 8]);
MsgMeasurementPoint.prototype.fieldSpec.push(['id', 'writeUInt64LE', 8]);
MsgMeasurementPoint.prototype.fieldSpec.push(['slice_time', 'writeUInt64LE', 8]);
MsgMeasurementPoint.prototype.fieldSpec.push(['line', 'writeUInt16LE', 2]);
MsgMeasurementPoint.prototype.fieldSpec.push(['func', 'string', null]);

module.exports = {
  0xCF00: MsgMeasurementPoint,
  MsgMeasurementPoint: MsgMeasurementPoint,
}