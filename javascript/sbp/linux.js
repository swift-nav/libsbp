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
 * Automatically generated from piksi/yaml/swiftnav/sbp/linux.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Linux state monitoring.
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;

/**
 * SBP class for message MSG_LINUX_CPU_STATE (0x7F00).
 *
 * This message indicates the process state of the top 10 heaviest consumers of CPU
 * on the system.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field index number (unsigned 8-bit int, 1 byte) sequence of this status message, values from 0-9
 * @field pid number (unsigned 16-bit int, 2 bytes) the PID of the process
 * @field pcpu number (unsigned 8-bit int, 1 byte) percent of cpu used, expressed as a fraction of 256
 * @field tname string fixed length string representing the thread name
 * @field cmdline string the command line (as much as it fits in the remaining packet)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgLinuxCpuState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_LINUX_CPU_STATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgLinuxCpuState.prototype = Object.create(SBP.prototype);
MsgLinuxCpuState.prototype.messageType = "MSG_LINUX_CPU_STATE";
MsgLinuxCpuState.prototype.msg_type = 0x7F00;
MsgLinuxCpuState.prototype.constructor = MsgLinuxCpuState;
MsgLinuxCpuState.prototype.parser = new Parser()
  .endianess('little')
  .uint8('index')
  .uint16('pid')
  .uint8('pcpu')
  .string('tname', { length: 15 })
  .string('cmdline', { greedy: true });
MsgLinuxCpuState.prototype.fieldSpec = [];
MsgLinuxCpuState.prototype.fieldSpec.push(['index', 'writeUInt8', 1]);
MsgLinuxCpuState.prototype.fieldSpec.push(['pid', 'writeUInt16LE', 2]);
MsgLinuxCpuState.prototype.fieldSpec.push(['pcpu', 'writeUInt8', 1]);
MsgLinuxCpuState.prototype.fieldSpec.push(['tname', 'string', 15]);
MsgLinuxCpuState.prototype.fieldSpec.push(['cmdline', 'string', null]);

/**
 * SBP class for message MSG_LINUX_MEM_STATE (0x7F01).
 *
 * This message indicates the process state of the top 10 heaviest consumers of
 * memory on the system.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field index number (unsigned 8-bit int, 1 byte) sequence of this status message, values from 0-9
 * @field pid number (unsigned 16-bit int, 2 bytes) the PID of the process
 * @field pmem number (unsigned 8-bit int, 1 byte) percent of memory used, expressed as a fraction of 256
 * @field tname string fixed length string representing the thread name
 * @field cmdline string the command line (as much as it fits in the remaining packet)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgLinuxMemState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_LINUX_MEM_STATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgLinuxMemState.prototype = Object.create(SBP.prototype);
MsgLinuxMemState.prototype.messageType = "MSG_LINUX_MEM_STATE";
MsgLinuxMemState.prototype.msg_type = 0x7F01;
MsgLinuxMemState.prototype.constructor = MsgLinuxMemState;
MsgLinuxMemState.prototype.parser = new Parser()
  .endianess('little')
  .uint8('index')
  .uint16('pid')
  .uint8('pmem')
  .string('tname', { length: 15 })
  .string('cmdline', { greedy: true });
MsgLinuxMemState.prototype.fieldSpec = [];
MsgLinuxMemState.prototype.fieldSpec.push(['index', 'writeUInt8', 1]);
MsgLinuxMemState.prototype.fieldSpec.push(['pid', 'writeUInt16LE', 2]);
MsgLinuxMemState.prototype.fieldSpec.push(['pmem', 'writeUInt8', 1]);
MsgLinuxMemState.prototype.fieldSpec.push(['tname', 'string', 15]);
MsgLinuxMemState.prototype.fieldSpec.push(['cmdline', 'string', null]);

/**
 * SBP class for message MSG_LINUX_SYS_STATE (0x7F02).
 *
 * This presents a summary of CPU and memory utilization.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field mem_total number (unsigned 16-bit int, 2 bytes) total system memory
 * @field pcpu number (unsigned 8-bit int, 1 byte) percent of total cpu currently utilized
 * @field pmem number (unsigned 8-bit int, 1 byte) percent of total memory currently utilized
 * @field procs_starting number (unsigned 16-bit int, 2 bytes) number of processes that started during collection phase
 * @field procs_stopping number (unsigned 16-bit int, 2 bytes) number of processes that stopped during collection phase
 * @field pid_count number (unsigned 16-bit int, 2 bytes) the count of processes on the system
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgLinuxSysState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_LINUX_SYS_STATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgLinuxSysState.prototype = Object.create(SBP.prototype);
MsgLinuxSysState.prototype.messageType = "MSG_LINUX_SYS_STATE";
MsgLinuxSysState.prototype.msg_type = 0x7F02;
MsgLinuxSysState.prototype.constructor = MsgLinuxSysState;
MsgLinuxSysState.prototype.parser = new Parser()
  .endianess('little')
  .uint16('mem_total')
  .uint8('pcpu')
  .uint8('pmem')
  .uint16('procs_starting')
  .uint16('procs_stopping')
  .uint16('pid_count');
MsgLinuxSysState.prototype.fieldSpec = [];
MsgLinuxSysState.prototype.fieldSpec.push(['mem_total', 'writeUInt16LE', 2]);
MsgLinuxSysState.prototype.fieldSpec.push(['pcpu', 'writeUInt8', 1]);
MsgLinuxSysState.prototype.fieldSpec.push(['pmem', 'writeUInt8', 1]);
MsgLinuxSysState.prototype.fieldSpec.push(['procs_starting', 'writeUInt16LE', 2]);
MsgLinuxSysState.prototype.fieldSpec.push(['procs_stopping', 'writeUInt16LE', 2]);
MsgLinuxSysState.prototype.fieldSpec.push(['pid_count', 'writeUInt16LE', 2]);

/**
 * SBP class for message MSG_LINUX_PROCESS_SOCKET_COUNTS (0x7F03).
 *
 * Top 10 list of processes with high socket counts.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field index number (unsigned 8-bit int, 1 byte) sequence of this status message, values from 0-9
 * @field pid number (unsigned 16-bit int, 2 bytes) the PID of the process in question
 * @field socket_count number (unsigned 16-bit int, 2 bytes) the number of sockets the process is using
 * @field socket_types number (unsigned 16-bit int, 2 bytes) A bitfield indicating the socket types used:   0x1 (tcp), 0x2 (udp), 0x4 (unix
 *   stream), 0x8 (unix dgram), 0x10 (netlink),   and 0x8000 (unknown)
 * @field socket_states number (unsigned 16-bit int, 2 bytes) A bitfield indicating the socket states:   0x1 (established), 0x2 (syn-sent),
 *   0x4 (syn-recv), 0x8 (fin-wait-1),   0x10 (fin-wait-2), 0x20 (time-wait), 0x40
 *   (closed), 0x80 (close-wait),   0x100 (last-ack), 0x200 (listen), 0x400
 *   (closing), 0x800 (unconnected),   and 0x8000 (unknown)
 * @field cmdline string the command line of the process in question
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgLinuxProcessSocketCounts = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_LINUX_PROCESS_SOCKET_COUNTS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgLinuxProcessSocketCounts.prototype = Object.create(SBP.prototype);
MsgLinuxProcessSocketCounts.prototype.messageType = "MSG_LINUX_PROCESS_SOCKET_COUNTS";
MsgLinuxProcessSocketCounts.prototype.msg_type = 0x7F03;
MsgLinuxProcessSocketCounts.prototype.constructor = MsgLinuxProcessSocketCounts;
MsgLinuxProcessSocketCounts.prototype.parser = new Parser()
  .endianess('little')
  .uint8('index')
  .uint16('pid')
  .uint16('socket_count')
  .uint16('socket_types')
  .uint16('socket_states')
  .string('cmdline', { greedy: true });
MsgLinuxProcessSocketCounts.prototype.fieldSpec = [];
MsgLinuxProcessSocketCounts.prototype.fieldSpec.push(['index', 'writeUInt8', 1]);
MsgLinuxProcessSocketCounts.prototype.fieldSpec.push(['pid', 'writeUInt16LE', 2]);
MsgLinuxProcessSocketCounts.prototype.fieldSpec.push(['socket_count', 'writeUInt16LE', 2]);
MsgLinuxProcessSocketCounts.prototype.fieldSpec.push(['socket_types', 'writeUInt16LE', 2]);
MsgLinuxProcessSocketCounts.prototype.fieldSpec.push(['socket_states', 'writeUInt16LE', 2]);
MsgLinuxProcessSocketCounts.prototype.fieldSpec.push(['cmdline', 'string', null]);

/**
 * SBP class for message MSG_LINUX_PROCESS_SOCKET_QUEUES (0x7F04).
 *
 * Top 10 list of sockets with deep queues.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field index number (unsigned 8-bit int, 1 byte) sequence of this status message, values from 0-9
 * @field pid number (unsigned 16-bit int, 2 bytes) the PID of the process in question
 * @field recv_queued number (unsigned 16-bit int, 2 bytes) the total amount of receive data queued for this process
 * @field send_queued number (unsigned 16-bit int, 2 bytes) the total amount of send data queued for this process
 * @field socket_types number (unsigned 16-bit int, 2 bytes) A bitfield indicating the socket types used:   0x1 (tcp), 0x2 (udp), 0x4 (unix
 *   stream), 0x8 (unix dgram), 0x10 (netlink),   and 0x8000 (unknown)
 * @field socket_states number (unsigned 16-bit int, 2 bytes) A bitfield indicating the socket states:   0x1 (established), 0x2 (syn-sent),
 *   0x4 (syn-recv), 0x8 (fin-wait-1),   0x10 (fin-wait-2), 0x20 (time-wait), 0x40
 *   (closed), 0x80 (close-wait),   0x100 (last-ack), 0x200 (listen), 0x400
 *   (closing), 0x800 (unconnected),   and 0x8000 (unknown)
 * @field address_of_largest string Address of the largest queue, remote or local depending on the directionality of
 *   the connection.
 * @field cmdline string the command line of the process in question
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgLinuxProcessSocketQueues = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_LINUX_PROCESS_SOCKET_QUEUES";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgLinuxProcessSocketQueues.prototype = Object.create(SBP.prototype);
MsgLinuxProcessSocketQueues.prototype.messageType = "MSG_LINUX_PROCESS_SOCKET_QUEUES";
MsgLinuxProcessSocketQueues.prototype.msg_type = 0x7F04;
MsgLinuxProcessSocketQueues.prototype.constructor = MsgLinuxProcessSocketQueues;
MsgLinuxProcessSocketQueues.prototype.parser = new Parser()
  .endianess('little')
  .uint8('index')
  .uint16('pid')
  .uint16('recv_queued')
  .uint16('send_queued')
  .uint16('socket_types')
  .uint16('socket_states')
  .string('address_of_largest', { length: 64 })
  .string('cmdline', { greedy: true });
MsgLinuxProcessSocketQueues.prototype.fieldSpec = [];
MsgLinuxProcessSocketQueues.prototype.fieldSpec.push(['index', 'writeUInt8', 1]);
MsgLinuxProcessSocketQueues.prototype.fieldSpec.push(['pid', 'writeUInt16LE', 2]);
MsgLinuxProcessSocketQueues.prototype.fieldSpec.push(['recv_queued', 'writeUInt16LE', 2]);
MsgLinuxProcessSocketQueues.prototype.fieldSpec.push(['send_queued', 'writeUInt16LE', 2]);
MsgLinuxProcessSocketQueues.prototype.fieldSpec.push(['socket_types', 'writeUInt16LE', 2]);
MsgLinuxProcessSocketQueues.prototype.fieldSpec.push(['socket_states', 'writeUInt16LE', 2]);
MsgLinuxProcessSocketQueues.prototype.fieldSpec.push(['address_of_largest', 'string', 64]);
MsgLinuxProcessSocketQueues.prototype.fieldSpec.push(['cmdline', 'string', null]);

/**
 * SBP class for message MSG_LINUX_SOCKET_USAGE (0x7F05).
 *
 * Summaries the socket usage across the system.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field avg_queue_depth number (unsigned 32-bit int, 4 bytes) average socket queue depths across all sockets on the system
 * @field max_queue_depth number (unsigned 32-bit int, 4 bytes) the max queue depth seen within the reporting period
 * @field socket_state_counts array A count for each socket type reported in the `socket_types_reported` field, the
 *   first entry corresponds to the first enabled bit in `types_reported`.
 * @field socket_type_counts array A count for each socket type reported in the `socket_types_reported` field, the
 *   first entry corresponds to the first enabled bit in `types_reported`.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgLinuxSocketUsage = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_LINUX_SOCKET_USAGE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgLinuxSocketUsage.prototype = Object.create(SBP.prototype);
MsgLinuxSocketUsage.prototype.messageType = "MSG_LINUX_SOCKET_USAGE";
MsgLinuxSocketUsage.prototype.msg_type = 0x7F05;
MsgLinuxSocketUsage.prototype.constructor = MsgLinuxSocketUsage;
MsgLinuxSocketUsage.prototype.parser = new Parser()
  .endianess('little')
  .uint32('avg_queue_depth')
  .uint32('max_queue_depth')
  .array('socket_state_counts', { length: 16, type: 'uint16le' })
  .array('socket_type_counts', { length: 16, type: 'uint16le' });
MsgLinuxSocketUsage.prototype.fieldSpec = [];
MsgLinuxSocketUsage.prototype.fieldSpec.push(['avg_queue_depth', 'writeUInt32LE', 4]);
MsgLinuxSocketUsage.prototype.fieldSpec.push(['max_queue_depth', 'writeUInt32LE', 4]);
MsgLinuxSocketUsage.prototype.fieldSpec.push(['socket_state_counts', 'array', 'writeUInt16LE', function () { return 2; }, 16]);
MsgLinuxSocketUsage.prototype.fieldSpec.push(['socket_type_counts', 'array', 'writeUInt16LE', function () { return 2; }, 16]);

/**
 * SBP class for message MSG_LINUX_PROCESS_FD_COUNT (0x7F06).
 *
 * Top 10 list of processes with a large number of open file descriptors.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field index number (unsigned 8-bit int, 1 byte) sequence of this status message, values from 0-9
 * @field pid number (unsigned 16-bit int, 2 bytes) the PID of the process in question
 * @field fd_count number (unsigned 16-bit int, 2 bytes) a count of the number of file descriptors opened by the process
 * @field cmdline string the command line of the process in question
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgLinuxProcessFdCount = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_LINUX_PROCESS_FD_COUNT";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgLinuxProcessFdCount.prototype = Object.create(SBP.prototype);
MsgLinuxProcessFdCount.prototype.messageType = "MSG_LINUX_PROCESS_FD_COUNT";
MsgLinuxProcessFdCount.prototype.msg_type = 0x7F06;
MsgLinuxProcessFdCount.prototype.constructor = MsgLinuxProcessFdCount;
MsgLinuxProcessFdCount.prototype.parser = new Parser()
  .endianess('little')
  .uint8('index')
  .uint16('pid')
  .uint16('fd_count')
  .string('cmdline', { greedy: true });
MsgLinuxProcessFdCount.prototype.fieldSpec = [];
MsgLinuxProcessFdCount.prototype.fieldSpec.push(['index', 'writeUInt8', 1]);
MsgLinuxProcessFdCount.prototype.fieldSpec.push(['pid', 'writeUInt16LE', 2]);
MsgLinuxProcessFdCount.prototype.fieldSpec.push(['fd_count', 'writeUInt16LE', 2]);
MsgLinuxProcessFdCount.prototype.fieldSpec.push(['cmdline', 'string', null]);

/**
 * SBP class for message MSG_LINUX_PROCESS_FD_SUMMARY (0x7F07).
 *
 * Summary of open file descriptors on the system.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sys_fd_count number (unsigned 32-bit int, 4 bytes) count of total FDs open on the system
 * @field most_opened string A null delimited list of strings which alternates between a string
 *   representation of the process count and the file name whose count it being
 *   reported.  That is, in C string syntax "32\0/var/log/syslog\012\0/tmp/foo\0"
 *   with the end of the list being 2 NULL terminators in a row.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgLinuxProcessFdSummary = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_LINUX_PROCESS_FD_SUMMARY";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgLinuxProcessFdSummary.prototype = Object.create(SBP.prototype);
MsgLinuxProcessFdSummary.prototype.messageType = "MSG_LINUX_PROCESS_FD_SUMMARY";
MsgLinuxProcessFdSummary.prototype.msg_type = 0x7F07;
MsgLinuxProcessFdSummary.prototype.constructor = MsgLinuxProcessFdSummary;
MsgLinuxProcessFdSummary.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sys_fd_count')
  .string('most_opened', { greedy: true });
MsgLinuxProcessFdSummary.prototype.fieldSpec = [];
MsgLinuxProcessFdSummary.prototype.fieldSpec.push(['sys_fd_count', 'writeUInt32LE', 4]);
MsgLinuxProcessFdSummary.prototype.fieldSpec.push(['most_opened', 'string', null]);

module.exports = {
  0x7F00: MsgLinuxCpuState,
  MsgLinuxCpuState: MsgLinuxCpuState,
  0x7F01: MsgLinuxMemState,
  MsgLinuxMemState: MsgLinuxMemState,
  0x7F02: MsgLinuxSysState,
  MsgLinuxSysState: MsgLinuxSysState,
  0x7F03: MsgLinuxProcessSocketCounts,
  MsgLinuxProcessSocketCounts: MsgLinuxProcessSocketCounts,
  0x7F04: MsgLinuxProcessSocketQueues,
  MsgLinuxProcessSocketQueues: MsgLinuxProcessSocketQueues,
  0x7F05: MsgLinuxSocketUsage,
  MsgLinuxSocketUsage: MsgLinuxSocketUsage,
  0x7F06: MsgLinuxProcessFdCount,
  MsgLinuxProcessFdCount: MsgLinuxProcessFdCount,
  0x7F07: MsgLinuxProcessFdSummary,
  MsgLinuxProcessFdSummary: MsgLinuxProcessFdSummary,
}