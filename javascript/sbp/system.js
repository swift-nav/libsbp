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
 * Automatically generated from piksi/yaml/swiftnav/sbp/system.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Standardized system messages from Swift Navigation devices.
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;

/**
 * SBP class for message MSG_STARTUP (0xFF00).
 *
 * The system start-up message is sent once on system start-up. It notifies the
 * host or other attached devices that the system has started and is now ready to
 * respond to commands or configuration requests.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field cause number (unsigned 8-bit int, 1 byte) Cause of startup
 * @field startup_type number (unsigned 8-bit int, 1 byte) Startup type
 * @field reserved number (unsigned 16-bit int, 2 bytes) Reserved
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgStartup = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_STARTUP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgStartup.prototype = Object.create(SBP.prototype);
MsgStartup.prototype.messageType = "MSG_STARTUP";
MsgStartup.prototype.msg_type = 0xFF00;
MsgStartup.prototype.constructor = MsgStartup;
MsgStartup.prototype.parser = new Parser()
  .endianess('little')
  .uint8('cause')
  .uint8('startup_type')
  .uint16('reserved');
MsgStartup.prototype.fieldSpec = [];
MsgStartup.prototype.fieldSpec.push(['cause', 'writeUInt8', 1]);
MsgStartup.prototype.fieldSpec.push(['startup_type', 'writeUInt8', 1]);
MsgStartup.prototype.fieldSpec.push(['reserved', 'writeUInt16LE', 2]);

/**
 * SBP class for message MSG_DGNSS_STATUS (0xFF02).
 *
 * This message provides information about the receipt of Differential corrections.
 * It is expected to be sent with each receipt of a complete corrections packet.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 * @field latency number (unsigned 16-bit int, 2 bytes) Latency of observation receipt
 * @field num_signals number (unsigned 8-bit int, 1 byte) Number of signals from base station
 * @field source string Corrections source string
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgDgnssStatus = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_DGNSS_STATUS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgDgnssStatus.prototype = Object.create(SBP.prototype);
MsgDgnssStatus.prototype.messageType = "MSG_DGNSS_STATUS";
MsgDgnssStatus.prototype.msg_type = 0xFF02;
MsgDgnssStatus.prototype.constructor = MsgDgnssStatus;
MsgDgnssStatus.prototype.parser = new Parser()
  .endianess('little')
  .uint8('flags')
  .uint16('latency')
  .uint8('num_signals')
  .string('source', { greedy: true });
MsgDgnssStatus.prototype.fieldSpec = [];
MsgDgnssStatus.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);
MsgDgnssStatus.prototype.fieldSpec.push(['latency', 'writeUInt16LE', 2]);
MsgDgnssStatus.prototype.fieldSpec.push(['num_signals', 'writeUInt8', 1]);
MsgDgnssStatus.prototype.fieldSpec.push(['source', 'string', null]);

/**
 * SBP class for message MSG_HEARTBEAT (0xFFFF).
 *
 * The heartbeat message is sent periodically to inform the host or other attached
 * devices that the system is running. It is used to monitor system malfunctions.
 * It also contains status flags that indicate to the host the status of the system
 * and whether it is operating correctly. Currently, the expected heartbeat
 * interval is 1 sec.  The system error flag is used to indicate that an error has
 * occurred in the system. To determine the source of the error, the remaining
 * error flags should be inspected.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field flags number (unsigned 32-bit int, 4 bytes) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgHeartbeat = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_HEARTBEAT";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgHeartbeat.prototype = Object.create(SBP.prototype);
MsgHeartbeat.prototype.messageType = "MSG_HEARTBEAT";
MsgHeartbeat.prototype.msg_type = 0xFFFF;
MsgHeartbeat.prototype.constructor = MsgHeartbeat;
MsgHeartbeat.prototype.parser = new Parser()
  .endianess('little')
  .uint32('flags');
MsgHeartbeat.prototype.fieldSpec = [];
MsgHeartbeat.prototype.fieldSpec.push(['flags', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_INS_STATUS (0xFF03).
 *
 * The INS status message describes the state of the operation and initialization
 * of the inertial navigation system.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field flags number (unsigned 32-bit int, 4 bytes) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgInsStatus = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_INS_STATUS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgInsStatus.prototype = Object.create(SBP.prototype);
MsgInsStatus.prototype.messageType = "MSG_INS_STATUS";
MsgInsStatus.prototype.msg_type = 0xFF03;
MsgInsStatus.prototype.constructor = MsgInsStatus;
MsgInsStatus.prototype.parser = new Parser()
  .endianess('little')
  .uint32('flags');
MsgInsStatus.prototype.fieldSpec = [];
MsgInsStatus.prototype.fieldSpec.push(['flags', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_CSAC_TELEMETRY (0xFF04).
 *
 * The CSAC telemetry message has an implementation defined telemetry string from a
 * device. It is not produced or available on general Swift Products. It is
 * intended to be a low rate message for status purposes.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field id number (unsigned 8-bit int, 1 byte) Index representing the type of telemetry in use.  It is implemention defined.
 * @field telemetry string Comma separated list of values as defined by the index
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgCsacTelemetry = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_CSAC_TELEMETRY";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgCsacTelemetry.prototype = Object.create(SBP.prototype);
MsgCsacTelemetry.prototype.messageType = "MSG_CSAC_TELEMETRY";
MsgCsacTelemetry.prototype.msg_type = 0xFF04;
MsgCsacTelemetry.prototype.constructor = MsgCsacTelemetry;
MsgCsacTelemetry.prototype.parser = new Parser()
  .endianess('little')
  .uint8('id')
  .string('telemetry', { greedy: true });
MsgCsacTelemetry.prototype.fieldSpec = [];
MsgCsacTelemetry.prototype.fieldSpec.push(['id', 'writeUInt8', 1]);
MsgCsacTelemetry.prototype.fieldSpec.push(['telemetry', 'string', null]);

/**
 * SBP class for message MSG_CSAC_TELEMETRY_LABELS (0xFF05).
 *
 * The CSAC telemetry message provides labels for each member of the string
 * produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a lower
 * rate than the MSG_CSAC_TELEMETRY.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field id number (unsigned 8-bit int, 1 byte) Index representing the type of telemetry in use.  It is implemention defined.
 * @field telemetry_labels string Comma separated list of telemetry field values
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgCsacTelemetryLabels = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_CSAC_TELEMETRY_LABELS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgCsacTelemetryLabels.prototype = Object.create(SBP.prototype);
MsgCsacTelemetryLabels.prototype.messageType = "MSG_CSAC_TELEMETRY_LABELS";
MsgCsacTelemetryLabels.prototype.msg_type = 0xFF05;
MsgCsacTelemetryLabels.prototype.constructor = MsgCsacTelemetryLabels;
MsgCsacTelemetryLabels.prototype.parser = new Parser()
  .endianess('little')
  .uint8('id')
  .string('telemetry_labels', { greedy: true });
MsgCsacTelemetryLabels.prototype.fieldSpec = [];
MsgCsacTelemetryLabels.prototype.fieldSpec.push(['id', 'writeUInt8', 1]);
MsgCsacTelemetryLabels.prototype.fieldSpec.push(['telemetry_labels', 'string', null]);

module.exports = {
  0xFF00: MsgStartup,
  MsgStartup: MsgStartup,
  0xFF02: MsgDgnssStatus,
  MsgDgnssStatus: MsgDgnssStatus,
  0xFFFF: MsgHeartbeat,
  MsgHeartbeat: MsgHeartbeat,
  0xFF03: MsgInsStatus,
  MsgInsStatus: MsgInsStatus,
  0xFF04: MsgCsacTelemetry,
  MsgCsacTelemetry: MsgCsacTelemetry,
  0xFF05: MsgCsacTelemetryLabels,
  MsgCsacTelemetryLabels: MsgCsacTelemetryLabels,
}