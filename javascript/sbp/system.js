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
 * Automatically generated from spec/yaml/swiftnav/sbp/system.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Standardized system messages from Swift Navigation devices.
***********************/

let SBP = require('./sbp');
let Parser = require('./parser');
let Int64 = require('node-int64');
let UInt64 = require('cuint').UINT64;

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
let MsgStartup = function (sbp, fields) {
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
let MsgDgnssStatus = function (sbp, fields) {
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
let MsgHeartbeat = function (sbp, fields) {
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
 * SBP class for message fragment SubSystemReport
 *
 * Report the general and specific state of a subsystem.  If the generic state is
 * reported as initializing, the specific state should be ignored.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field component number (unsigned 16-bit int, 2 bytes) Identity of reporting subsystem
 * @field generic number (unsigned 8-bit int, 1 byte) Generic form status report
 * @field specific number (unsigned 8-bit int, 1 byte) Subsystem specific status code
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let SubSystemReport = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "SubSystemReport";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
SubSystemReport.prototype = Object.create(SBP.prototype);
SubSystemReport.prototype.messageType = "SubSystemReport";
SubSystemReport.prototype.constructor = SubSystemReport;
SubSystemReport.prototype.parser = new Parser()
  .endianess('little')
  .uint16('component')
  .uint8('generic')
  .uint8('specific');
SubSystemReport.prototype.fieldSpec = [];
SubSystemReport.prototype.fieldSpec.push(['component', 'writeUInt16LE', 2]);
SubSystemReport.prototype.fieldSpec.push(['generic', 'writeUInt8', 1]);
SubSystemReport.prototype.fieldSpec.push(['specific', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_STATUS_REPORT (0xFFFE).
 *
 * The status report is sent periodically to inform the host or other attached
 * devices that the system is running. It is used to monitor system malfunctions.
 * It contains status reports that indicate to the host the status of each
 * subsystem and whether it is operating correctly.  Interpretation of the
 * subsystem specific status code is product dependent, but if the generic status
 * code is initializing, it should be ignored.  Refer to product documentation for
 * details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field reporting_system number (unsigned 16-bit int, 2 bytes) Identity of reporting system
 * @field sbp_version number (unsigned 16-bit int, 2 bytes) SBP protocol version
 * @field sequence number (unsigned 32-bit int, 4 bytes) Increments on each status report sent
 * @field uptime number (unsigned 32-bit int, 4 bytes) Number of seconds since system start-up
 * @field status array Reported status of individual subsystems
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgStatusReport = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_STATUS_REPORT";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgStatusReport.prototype = Object.create(SBP.prototype);
MsgStatusReport.prototype.messageType = "MSG_STATUS_REPORT";
MsgStatusReport.prototype.msg_type = 0xFFFE;
MsgStatusReport.prototype.constructor = MsgStatusReport;
MsgStatusReport.prototype.parser = new Parser()
  .endianess('little')
  .uint16('reporting_system')
  .uint16('sbp_version')
  .uint32('sequence')
  .uint32('uptime')
  .array('status', { type: SubSystemReport.prototype.parser, readUntil: 'eof' });
MsgStatusReport.prototype.fieldSpec = [];
MsgStatusReport.prototype.fieldSpec.push(['reporting_system', 'writeUInt16LE', 2]);
MsgStatusReport.prototype.fieldSpec.push(['sbp_version', 'writeUInt16LE', 2]);
MsgStatusReport.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgStatusReport.prototype.fieldSpec.push(['uptime', 'writeUInt32LE', 4]);
MsgStatusReport.prototype.fieldSpec.push(['status', 'array', SubSystemReport.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message fragment StatusJournalItem
 *
 * Reports the uptime and the state of a subsystem via generic and specific status
 * codes.  If the generic state is reported as initializing, the specific state
 * should be ignored.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field uptime number (unsigned 32-bit int, 4 bytes) Milliseconds since system startup
 * @field report SubSystemReport
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let StatusJournalItem = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "StatusJournalItem";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
StatusJournalItem.prototype = Object.create(SBP.prototype);
StatusJournalItem.prototype.messageType = "StatusJournalItem";
StatusJournalItem.prototype.constructor = StatusJournalItem;
StatusJournalItem.prototype.parser = new Parser()
  .endianess('little')
  .uint32('uptime')
  .nest('report', { type: SubSystemReport.prototype.parser });
StatusJournalItem.prototype.fieldSpec = [];
StatusJournalItem.prototype.fieldSpec.push(['uptime', 'writeUInt32LE', 4]);
StatusJournalItem.prototype.fieldSpec.push(['report', SubSystemReport.prototype.fieldSpec]);

/**
 * SBP class for message MSG_STATUS_JOURNAL (0xFFFD).
 *
 * The status journal message contains past status reports (see MSG_STATUS_REPORT)
 * and functions as a error/event storage for telemetry purposes.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field reporting_system number (unsigned 16-bit int, 2 bytes) Identity of reporting system
 * @field sbp_version number (unsigned 16-bit int, 2 bytes) SBP protocol version
 * @field total_status_reports number (unsigned 32-bit int, 4 bytes) Total number of status reports sent since system startup
 * @field sequence_descriptor number (unsigned 8-bit int, 1 byte) Index and number of messages in this sequence. First nibble is the size of the
 *   sequence (n), second nibble is the zero-indexed counter (ith packet of n)
 * @field journal array Status journal
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgStatusJournal = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_STATUS_JOURNAL";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgStatusJournal.prototype = Object.create(SBP.prototype);
MsgStatusJournal.prototype.messageType = "MSG_STATUS_JOURNAL";
MsgStatusJournal.prototype.msg_type = 0xFFFD;
MsgStatusJournal.prototype.constructor = MsgStatusJournal;
MsgStatusJournal.prototype.parser = new Parser()
  .endianess('little')
  .uint16('reporting_system')
  .uint16('sbp_version')
  .uint32('total_status_reports')
  .uint8('sequence_descriptor')
  .array('journal', { type: StatusJournalItem.prototype.parser, readUntil: 'eof' });
MsgStatusJournal.prototype.fieldSpec = [];
MsgStatusJournal.prototype.fieldSpec.push(['reporting_system', 'writeUInt16LE', 2]);
MsgStatusJournal.prototype.fieldSpec.push(['sbp_version', 'writeUInt16LE', 2]);
MsgStatusJournal.prototype.fieldSpec.push(['total_status_reports', 'writeUInt32LE', 4]);
MsgStatusJournal.prototype.fieldSpec.push(['sequence_descriptor', 'writeUInt8', 1]);
MsgStatusJournal.prototype.fieldSpec.push(['journal', 'array', StatusJournalItem.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

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
let MsgInsStatus = function (sbp, fields) {
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
 * @field id number (unsigned 8-bit int, 1 byte) Index representing the type of telemetry in use.  It is implementation defined.
 * @field telemetry string Comma separated list of values as defined by the index
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgCsacTelemetry = function (sbp, fields) {
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
 * @field id number (unsigned 8-bit int, 1 byte) Index representing the type of telemetry in use.  It is implementation defined.
 * @field telemetry_labels string Comma separated list of telemetry field values
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgCsacTelemetryLabels = function (sbp, fields) {
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

/**
 * SBP class for message MSG_INS_UPDATES (0xFF06).
 *
 * The INS update status message contains information about executed and rejected
 * INS updates. This message is expected to be extended in the future as new types
 * of measurements are being added.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field gnsspos number (unsigned 8-bit int, 1 byte) GNSS position update status flags
 * @field gnssvel number (unsigned 8-bit int, 1 byte) GNSS velocity update status flags
 * @field wheelticks number (unsigned 8-bit int, 1 byte) Wheelticks update status flags
 * @field speed number (unsigned 8-bit int, 1 byte) Wheelticks update status flags
 * @field nhc number (unsigned 8-bit int, 1 byte) NHC update status flags
 * @field zerovel number (unsigned 8-bit int, 1 byte) Zero velocity update status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgInsUpdates = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_INS_UPDATES";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgInsUpdates.prototype = Object.create(SBP.prototype);
MsgInsUpdates.prototype.messageType = "MSG_INS_UPDATES";
MsgInsUpdates.prototype.msg_type = 0xFF06;
MsgInsUpdates.prototype.constructor = MsgInsUpdates;
MsgInsUpdates.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint8('gnsspos')
  .uint8('gnssvel')
  .uint8('wheelticks')
  .uint8('speed')
  .uint8('nhc')
  .uint8('zerovel');
MsgInsUpdates.prototype.fieldSpec = [];
MsgInsUpdates.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgInsUpdates.prototype.fieldSpec.push(['gnsspos', 'writeUInt8', 1]);
MsgInsUpdates.prototype.fieldSpec.push(['gnssvel', 'writeUInt8', 1]);
MsgInsUpdates.prototype.fieldSpec.push(['wheelticks', 'writeUInt8', 1]);
MsgInsUpdates.prototype.fieldSpec.push(['speed', 'writeUInt8', 1]);
MsgInsUpdates.prototype.fieldSpec.push(['nhc', 'writeUInt8', 1]);
MsgInsUpdates.prototype.fieldSpec.push(['zerovel', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_GNSS_TIME_OFFSET (0xFF07).
 *
 * The GNSS time offset message contains the information that is needed to
 * translate messages tagged with a local timestamp (e.g. IMU or wheeltick
 * messages) to GNSS time for the sender producing this message.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field weeks number (signed 16-bit int, 2 bytes) Weeks portion of the time offset
 * @field milliseconds number (signed 32-bit int, 4 bytes) Milliseconds portion of the time offset
 * @field microseconds number (signed 16-bit int, 2 bytes) Microseconds portion of the time offset
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags (reserved)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgGnssTimeOffset = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_GNSS_TIME_OFFSET";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgGnssTimeOffset.prototype = Object.create(SBP.prototype);
MsgGnssTimeOffset.prototype.messageType = "MSG_GNSS_TIME_OFFSET";
MsgGnssTimeOffset.prototype.msg_type = 0xFF07;
MsgGnssTimeOffset.prototype.constructor = MsgGnssTimeOffset;
MsgGnssTimeOffset.prototype.parser = new Parser()
  .endianess('little')
  .int16('weeks')
  .int32('milliseconds')
  .int16('microseconds')
  .uint8('flags');
MsgGnssTimeOffset.prototype.fieldSpec = [];
MsgGnssTimeOffset.prototype.fieldSpec.push(['weeks', 'writeInt16LE', 2]);
MsgGnssTimeOffset.prototype.fieldSpec.push(['milliseconds', 'writeInt32LE', 4]);
MsgGnssTimeOffset.prototype.fieldSpec.push(['microseconds', 'writeInt16LE', 2]);
MsgGnssTimeOffset.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_PPS_TIME (0xFF08).
 *
 * The PPS time message contains the value of the sender's local time in
 * microseconds at the moment a pulse is detected on the PPS input. This is to be
 * used for syncronisation of sensor data sampled with a local timestamp (e.g. IMU
 * or wheeltick messages) where GNSS time is unknown to the sender.  The local time
 * used to timestamp the PPS pulse must be generated by the same clock which is
 * used to timestamp the IMU/wheel sensor data and should follow the same roll-over
 * rules.  A separate MSG_PPS_TIME message should be sent for each source of sensor
 * data which uses PPS-relative timestamping.  The sender ID for each of these
 * MSG_PPS_TIME messages should match the sender ID of the respective sensor data.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field time number (unsigned 64-bit int, 8 bytes) Local time in microseconds
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgPpsTime = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_PPS_TIME";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPpsTime.prototype = Object.create(SBP.prototype);
MsgPpsTime.prototype.messageType = "MSG_PPS_TIME";
MsgPpsTime.prototype.msg_type = 0xFF08;
MsgPpsTime.prototype.constructor = MsgPpsTime;
MsgPpsTime.prototype.parser = new Parser()
  .endianess('little')
  .uint64('time')
  .uint8('flags');
MsgPpsTime.prototype.fieldSpec = [];
MsgPpsTime.prototype.fieldSpec.push(['time', 'writeUInt64LE', 8]);
MsgPpsTime.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_SENSOR_AID_EVENT (0xFF09).
 *
 * This diagnostic message contains state and update status information for all
 * sensors that are being used by the fusion engine. This message will be generated
 * asynchronously to the solution messages and will be emitted anytime a sensor
 * update is being processed.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field time number (unsigned 32-bit int, 4 bytes) Update timestamp in milliseconds.
 * @field sensor_type number (unsigned 8-bit int, 1 byte) Sensor type
 * @field sensor_id number (unsigned 16-bit int, 2 bytes) Sensor identifier
 * @field sensor_state number (unsigned 8-bit int, 1 byte) Reserved for future use
 * @field n_available_meas number (unsigned 8-bit int, 1 byte) Number of available measurements in this epoch
 * @field n_attempted_meas number (unsigned 8-bit int, 1 byte) Number of attempted measurements in this epoch
 * @field n_accepted_meas number (unsigned 8-bit int, 1 byte) Number of accepted measurements in this epoch
 * @field flags number (unsigned 32-bit int, 4 bytes) Reserved for future use
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgSensorAidEvent = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SENSOR_AID_EVENT";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSensorAidEvent.prototype = Object.create(SBP.prototype);
MsgSensorAidEvent.prototype.messageType = "MSG_SENSOR_AID_EVENT";
MsgSensorAidEvent.prototype.msg_type = 0xFF09;
MsgSensorAidEvent.prototype.constructor = MsgSensorAidEvent;
MsgSensorAidEvent.prototype.parser = new Parser()
  .endianess('little')
  .uint32('time')
  .uint8('sensor_type')
  .uint16('sensor_id')
  .uint8('sensor_state')
  .uint8('n_available_meas')
  .uint8('n_attempted_meas')
  .uint8('n_accepted_meas')
  .uint32('flags');
MsgSensorAidEvent.prototype.fieldSpec = [];
MsgSensorAidEvent.prototype.fieldSpec.push(['time', 'writeUInt32LE', 4]);
MsgSensorAidEvent.prototype.fieldSpec.push(['sensor_type', 'writeUInt8', 1]);
MsgSensorAidEvent.prototype.fieldSpec.push(['sensor_id', 'writeUInt16LE', 2]);
MsgSensorAidEvent.prototype.fieldSpec.push(['sensor_state', 'writeUInt8', 1]);
MsgSensorAidEvent.prototype.fieldSpec.push(['n_available_meas', 'writeUInt8', 1]);
MsgSensorAidEvent.prototype.fieldSpec.push(['n_attempted_meas', 'writeUInt8', 1]);
MsgSensorAidEvent.prototype.fieldSpec.push(['n_accepted_meas', 'writeUInt8', 1]);
MsgSensorAidEvent.prototype.fieldSpec.push(['flags', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_GROUP_META (0xFF0A).
 *
 * This leading message lists the time metadata of the Solution Group. It also
 * lists the atomic contents (i.e. types of messages included) of the Solution
 * Group.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field group_id number (unsigned 8-bit int, 1 byte) Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags (reserved)
 * @field n_group_msgs number (unsigned 8-bit int, 1 byte) Size of list group_msgs
 * @field group_msgs array An in-order list of message types included in the Solution Group, including
 *   GROUP_META itself
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgGroupMeta = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_GROUP_META";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgGroupMeta.prototype = Object.create(SBP.prototype);
MsgGroupMeta.prototype.messageType = "MSG_GROUP_META";
MsgGroupMeta.prototype.msg_type = 0xFF0A;
MsgGroupMeta.prototype.constructor = MsgGroupMeta;
MsgGroupMeta.prototype.parser = new Parser()
  .endianess('little')
  .uint8('group_id')
  .uint8('flags')
  .uint8('n_group_msgs')
  .array('group_msgs', { type: 'uint16le', length: 'n_group_msgs' });
MsgGroupMeta.prototype.fieldSpec = [];
MsgGroupMeta.prototype.fieldSpec.push(['group_id', 'writeUInt8', 1]);
MsgGroupMeta.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);
MsgGroupMeta.prototype.fieldSpec.push(['n_group_msgs', 'writeUInt8', 1]);
MsgGroupMeta.prototype.fieldSpec.push(['group_msgs', 'array', 'writeUInt16LE', function () { return 2; }, 'n_group_msgs']);

module.exports = {
  0xFF00: MsgStartup,
  MsgStartup: MsgStartup,
  0xFF02: MsgDgnssStatus,
  MsgDgnssStatus: MsgDgnssStatus,
  0xFFFF: MsgHeartbeat,
  MsgHeartbeat: MsgHeartbeat,
  SubSystemReport: SubSystemReport,
  0xFFFE: MsgStatusReport,
  MsgStatusReport: MsgStatusReport,
  StatusJournalItem: StatusJournalItem,
  0xFFFD: MsgStatusJournal,
  MsgStatusJournal: MsgStatusJournal,
  0xFF03: MsgInsStatus,
  MsgInsStatus: MsgInsStatus,
  0xFF04: MsgCsacTelemetry,
  MsgCsacTelemetry: MsgCsacTelemetry,
  0xFF05: MsgCsacTelemetryLabels,
  MsgCsacTelemetryLabels: MsgCsacTelemetryLabels,
  0xFF06: MsgInsUpdates,
  MsgInsUpdates: MsgInsUpdates,
  0xFF07: MsgGnssTimeOffset,
  MsgGnssTimeOffset: MsgGnssTimeOffset,
  0xFF08: MsgPpsTime,
  MsgPpsTime: MsgPpsTime,
  0xFF09: MsgSensorAidEvent,
  MsgSensorAidEvent: MsgSensorAidEvent,
  0xFF0A: MsgGroupMeta,
  MsgGroupMeta: MsgGroupMeta,
}