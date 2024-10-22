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

/**
 * SBP class for message MSG_PROFILING_SYSTEM_INFO (0xCF01).
 *
 * Contains basic information about system resource usage. System is defined in
 * terms of the source of this message and may vary from  sender to sender. Refer
 * to product documentation to understand the exact scope and meaning of this
 * message.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field total_cpu_time number (unsigned 64-bit int, 8 bytes) Total cpu time in microseconds consumed by this system
 * @field age number (unsigned 64-bit int, 8 bytes) Age of the producing system in microseconds
 * @field n_threads number (unsigned 8-bit int, 1 byte) Number of threads being tracked by this system
 * @field heap_usage number (unsigned 32-bit int, 4 bytes) Number of bytes allocated on the heap
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgProfilingSystemInfo = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_PROFILING_SYSTEM_INFO";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgProfilingSystemInfo.prototype = Object.create(SBP.prototype);
MsgProfilingSystemInfo.prototype.messageType = "MSG_PROFILING_SYSTEM_INFO";
MsgProfilingSystemInfo.prototype.msg_type = 0xCF01;
MsgProfilingSystemInfo.prototype.constructor = MsgProfilingSystemInfo;
MsgProfilingSystemInfo.prototype.parser = new Parser()
  .endianess('little')
  .uint64('total_cpu_time')
  .uint64('age')
  .uint8('n_threads')
  .uint32('heap_usage');
MsgProfilingSystemInfo.prototype.fieldSpec = [];
MsgProfilingSystemInfo.prototype.fieldSpec.push(['total_cpu_time', 'writeUInt64LE', 8]);
MsgProfilingSystemInfo.prototype.fieldSpec.push(['age', 'writeUInt64LE', 8]);
MsgProfilingSystemInfo.prototype.fieldSpec.push(['n_threads', 'writeUInt8', 1]);
MsgProfilingSystemInfo.prototype.fieldSpec.push(['heap_usage', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_PROFILING_THREAD_INFO (0xCF02).
 *
 * Contains profiling information related to a single thread being tracked by the
 * producing system. Refer to product documentation to understand the exact scope
 * and meaning of this message.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field total_cpu_time number (unsigned 64-bit int, 8 bytes) Total cpu time in microseconds consumed by this thread
 * @field age number (unsigned 64-bit int, 8 bytes) Age of the thread in microseconds
 * @field state number (unsigned 8-bit int, 1 byte) Thread state
 * @field stack_size number (unsigned 32-bit int, 4 bytes) Stack size in bytes
 * @field stack_usage number (unsigned 32-bit int, 4 bytes) Stack high water usage in bytes
 * @field name string Thread name
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgProfilingThreadInfo = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_PROFILING_THREAD_INFO";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgProfilingThreadInfo.prototype = Object.create(SBP.prototype);
MsgProfilingThreadInfo.prototype.messageType = "MSG_PROFILING_THREAD_INFO";
MsgProfilingThreadInfo.prototype.msg_type = 0xCF02;
MsgProfilingThreadInfo.prototype.constructor = MsgProfilingThreadInfo;
MsgProfilingThreadInfo.prototype.parser = new Parser()
  .endianess('little')
  .uint64('total_cpu_time')
  .uint64('age')
  .uint8('state')
  .uint32('stack_size')
  .uint32('stack_usage')
  .string('name', { greedy: true });
MsgProfilingThreadInfo.prototype.fieldSpec = [];
MsgProfilingThreadInfo.prototype.fieldSpec.push(['total_cpu_time', 'writeUInt64LE', 8]);
MsgProfilingThreadInfo.prototype.fieldSpec.push(['age', 'writeUInt64LE', 8]);
MsgProfilingThreadInfo.prototype.fieldSpec.push(['state', 'writeUInt8', 1]);
MsgProfilingThreadInfo.prototype.fieldSpec.push(['stack_size', 'writeUInt32LE', 4]);
MsgProfilingThreadInfo.prototype.fieldSpec.push(['stack_usage', 'writeUInt32LE', 4]);
MsgProfilingThreadInfo.prototype.fieldSpec.push(['name', 'string', null]);

/**
 * SBP class for message fragment ResourceBucket
 *
 * Information about allocation of various resources grouped by buckets. Refer to
 * product documentation to understand the meaning and values in this message.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field name string Bucket name
 * @field thread number (unsigned 8-bit int, 1 byte) Number of threads
 * @field mutex number (unsigned 8-bit int, 1 byte) Number of mutexes
 * @field cv number (unsigned 8-bit int, 1 byte) Number of condition variables
 * @field io number (unsigned 8-bit int, 1 byte) Number of IO handles
 * @field heap_bytes_alloc number (unsigned 32-bit int, 4 bytes) Number of bytes allocated on the heap
 * @field heap_bytes_free number (unsigned 32-bit int, 4 bytes) Number of bytes freed on the heap
 * @field io_write number (unsigned 32-bit int, 4 bytes) Number of bytes written to IO handles
 * @field io_read number (unsigned 32-bit int, 4 bytes) Number of bytes read from IO handles
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let ResourceBucket = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "ResourceBucket";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
ResourceBucket.prototype = Object.create(SBP.prototype);
ResourceBucket.prototype.messageType = "ResourceBucket";
ResourceBucket.prototype.constructor = ResourceBucket;
ResourceBucket.prototype.parser = new Parser()
  .endianess('little')
  .string('name', { length: 21 })
  .uint8('thread')
  .uint8('mutex')
  .uint8('cv')
  .uint8('io')
  .uint32('heap_bytes_alloc')
  .uint32('heap_bytes_free')
  .uint32('io_write')
  .uint32('io_read');
ResourceBucket.prototype.fieldSpec = [];
ResourceBucket.prototype.fieldSpec.push(['name', 'string', 21]);
ResourceBucket.prototype.fieldSpec.push(['thread', 'writeUInt8', 1]);
ResourceBucket.prototype.fieldSpec.push(['mutex', 'writeUInt8', 1]);
ResourceBucket.prototype.fieldSpec.push(['cv', 'writeUInt8', 1]);
ResourceBucket.prototype.fieldSpec.push(['io', 'writeUInt8', 1]);
ResourceBucket.prototype.fieldSpec.push(['heap_bytes_alloc', 'writeUInt32LE', 4]);
ResourceBucket.prototype.fieldSpec.push(['heap_bytes_free', 'writeUInt32LE', 4]);
ResourceBucket.prototype.fieldSpec.push(['io_write', 'writeUInt32LE', 4]);
ResourceBucket.prototype.fieldSpec.push(['io_read', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_PROFILING_RESOURCE_COUNTER (0xCF03).
 *
 * Information about resource buckets. Refer to product documentation to understand
 * the meaning and values in this message.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field seq_no number (unsigned 8-bit int, 1 byte) Message number in complete sequence
 * @field seq_len number (unsigned 8-bit int, 1 byte) Length of message sequence
 * @field buckets array List of resource buckets
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgProfilingResourceCounter = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_PROFILING_RESOURCE_COUNTER";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgProfilingResourceCounter.prototype = Object.create(SBP.prototype);
MsgProfilingResourceCounter.prototype.messageType = "MSG_PROFILING_RESOURCE_COUNTER";
MsgProfilingResourceCounter.prototype.msg_type = 0xCF03;
MsgProfilingResourceCounter.prototype.constructor = MsgProfilingResourceCounter;
MsgProfilingResourceCounter.prototype.parser = new Parser()
  .endianess('little')
  .uint8('seq_no')
  .uint8('seq_len')
  .array('buckets', { type: ResourceBucket.prototype.parser, readUntil: 'eof' });
MsgProfilingResourceCounter.prototype.fieldSpec = [];
MsgProfilingResourceCounter.prototype.fieldSpec.push(['seq_no', 'writeUInt8', 1]);
MsgProfilingResourceCounter.prototype.fieldSpec.push(['seq_len', 'writeUInt8', 1]);
MsgProfilingResourceCounter.prototype.fieldSpec.push(['buckets', 'array', ResourceBucket.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

module.exports = {
  0xCF00: MsgMeasurementPoint,
  MsgMeasurementPoint: MsgMeasurementPoint,
  0xCF01: MsgProfilingSystemInfo,
  MsgProfilingSystemInfo: MsgProfilingSystemInfo,
  0xCF02: MsgProfilingThreadInfo,
  MsgProfilingThreadInfo: MsgProfilingThreadInfo,
  ResourceBucket: ResourceBucket,
  0xCF03: MsgProfilingResourceCounter,
  MsgProfilingResourceCounter: MsgProfilingResourceCounter,
}
