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
 * Automatically generated from piksi/yaml/swiftnav/sbp/solution_meta.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Standardized Metadata messages for Fuzed Solution from Swift Navigation devices.
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;

/**
 * SBP class for message fragment SolutionInputType
 *
 * Metadata describing which sensors were involved in the solution. The structure
 * is fixed no matter what the actual sensor type is. The sensor_type field tells
 * you which sensor we are talking about. It also tells you whether the sensor data
 * was actually used or not. The flags field, always a u8, contains the sensor-
 * specific data. The content of flags, for each sensor type, is described in the
 * relevant structures in this section.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sensor_type number (unsigned 8-bit int, 1 byte) The type of sensor
 * @field flags number (unsigned 8-bit int, 1 byte) Refer to each InputType description
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var SolutionInputType = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "SolutionInputType";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
SolutionInputType.prototype = Object.create(SBP.prototype);
SolutionInputType.prototype.messageType = "SolutionInputType";
SolutionInputType.prototype.constructor = SolutionInputType;
SolutionInputType.prototype.parser = new Parser()
  .endianess('little')
  .uint8('sensor_type')
  .uint8('flags');
SolutionInputType.prototype.fieldSpec = [];
SolutionInputType.prototype.fieldSpec.push(['sensor_type', 'writeUInt8', 1]);
SolutionInputType.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_SOLN_META_DEP_A (0xFF0F).
 *
 * Deprecated.  This message contains all metadata about the sensors received
 * and/or used in computing the Fuzed Solution. It focuses primarily, but not only,
 * on GNSS metadata.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field pdop number (unsigned 16-bit int, 2 bytes) Position Dilution of Precision as per last available DOPS from PVT engine
 *   (0xFFFF indicates invalid)
 * @field hdop number (unsigned 16-bit int, 2 bytes) Horizontal Dilution of Precision as per last available DOPS from PVT engine
 *   (0xFFFF indicates invalid)
 * @field vdop number (unsigned 16-bit int, 2 bytes) Vertical Dilution of Precision as per last available DOPS from PVT engine
 *   (0xFFFF indicates invalid)
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites as per last available solution from PVT engine
 * @field age_corrections number (unsigned 16-bit int, 2 bytes) Age of corrections as per last available AGE_CORRECTIONS from PVT engine (0xFFFF
 *   indicates invalid)
 * @field alignment_status number (unsigned 8-bit int, 1 byte) State of alignment and the status and receipt of the alignment inputs
 * @field last_used_gnss_pos_tow number (unsigned 32-bit int, 4 bytes) Tow of last-used GNSS position measurement
 * @field last_used_gnss_vel_tow number (unsigned 32-bit int, 4 bytes) Tow of last-used GNSS velocity measurement
 * @field sol_in array Array of Metadata describing the sensors potentially involved in the solution.
 *   Each element in the array represents a single sensor type and consists of flags
 *   containing (meta)data pertaining to that specific single sensor. Refer to each
 *   (XX)InputType descriptor in the present doc.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSolnMetaDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SOLN_META_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSolnMetaDepA.prototype = Object.create(SBP.prototype);
MsgSolnMetaDepA.prototype.messageType = "MSG_SOLN_META_DEP_A";
MsgSolnMetaDepA.prototype.msg_type = 0xFF0F;
MsgSolnMetaDepA.prototype.constructor = MsgSolnMetaDepA;
MsgSolnMetaDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint16('pdop')
  .uint16('hdop')
  .uint16('vdop')
  .uint8('n_sats')
  .uint16('age_corrections')
  .uint8('alignment_status')
  .uint32('last_used_gnss_pos_tow')
  .uint32('last_used_gnss_vel_tow')
  .array('sol_in', { type: SolutionInputType.prototype.parser, readUntil: 'eof' });
MsgSolnMetaDepA.prototype.fieldSpec = [];
MsgSolnMetaDepA.prototype.fieldSpec.push(['pdop', 'writeUInt16LE', 2]);
MsgSolnMetaDepA.prototype.fieldSpec.push(['hdop', 'writeUInt16LE', 2]);
MsgSolnMetaDepA.prototype.fieldSpec.push(['vdop', 'writeUInt16LE', 2]);
MsgSolnMetaDepA.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgSolnMetaDepA.prototype.fieldSpec.push(['age_corrections', 'writeUInt16LE', 2]);
MsgSolnMetaDepA.prototype.fieldSpec.push(['alignment_status', 'writeUInt8', 1]);
MsgSolnMetaDepA.prototype.fieldSpec.push(['last_used_gnss_pos_tow', 'writeUInt32LE', 4]);
MsgSolnMetaDepA.prototype.fieldSpec.push(['last_used_gnss_vel_tow', 'writeUInt32LE', 4]);
MsgSolnMetaDepA.prototype.fieldSpec.push(['sol_in', 'array', SolutionInputType.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_SOLN_META (0xFF0E).
 *
 * This message contains all metadata about the sensors received and/or used in
 * computing the sensorfusion solution. It focuses primarily, but not only, on GNSS
 * metadata. Regarding the age of the last received valid GNSS solution, the
 * highest two bits are time status, indicating whether age gnss can or can not be
 * used to retrieve time of measurement (noted TOM, also known as time of validity)
 * If it can, subtract 'age gnss' from 'tow' in navigation messages to get TOM. Can
 * be used before alignment is complete in the Fusion Engine, when output solution
 * is the last received valid GNSS solution and its tow is not a TOM.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS time of week rounded to the nearest millisecond
 * @field pdop number (unsigned 16-bit int, 2 bytes) Position Dilution of Precision as per last available DOPS from PVT engine
 *   (0xFFFF indicates invalid)
 * @field hdop number (unsigned 16-bit int, 2 bytes) Horizontal Dilution of Precision as per last available DOPS from PVT engine
 *   (0xFFFF indicates invalid)
 * @field vdop number (unsigned 16-bit int, 2 bytes) Vertical Dilution of Precision as per last available DOPS from PVT engine
 *   (0xFFFF indicates invalid)
 * @field age_corrections number (unsigned 16-bit int, 2 bytes) Age of corrections as per last available AGE_CORRECTIONS from PVT engine (0xFFFF
 *   indicates invalid)
 * @field age_gnss number (unsigned 32-bit int, 4 bytes) Age and Time Status of the last received valid GNSS solution.
 * @field sol_in array Array of Metadata describing the sensors potentially involved in the solution.
 *   Each element in the array represents a single sensor type and consists of flags
 *   containing (meta)data pertaining to that specific single sensor. Refer to each
 *   (XX)InputType descriptor in the present doc.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSolnMeta = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SOLN_META";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSolnMeta.prototype = Object.create(SBP.prototype);
MsgSolnMeta.prototype.messageType = "MSG_SOLN_META";
MsgSolnMeta.prototype.msg_type = 0xFF0E;
MsgSolnMeta.prototype.constructor = MsgSolnMeta;
MsgSolnMeta.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint16('pdop')
  .uint16('hdop')
  .uint16('vdop')
  .uint16('age_corrections')
  .uint32('age_gnss')
  .array('sol_in', { type: SolutionInputType.prototype.parser, readUntil: 'eof' });
MsgSolnMeta.prototype.fieldSpec = [];
MsgSolnMeta.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgSolnMeta.prototype.fieldSpec.push(['pdop', 'writeUInt16LE', 2]);
MsgSolnMeta.prototype.fieldSpec.push(['hdop', 'writeUInt16LE', 2]);
MsgSolnMeta.prototype.fieldSpec.push(['vdop', 'writeUInt16LE', 2]);
MsgSolnMeta.prototype.fieldSpec.push(['age_corrections', 'writeUInt16LE', 2]);
MsgSolnMeta.prototype.fieldSpec.push(['age_gnss', 'writeUInt32LE', 4]);
MsgSolnMeta.prototype.fieldSpec.push(['sol_in', 'array', SolutionInputType.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message fragment GNSSInputType
 *
 * Metadata around the GNSS sensors involved in the fuzed solution. Accessible
 * through sol_in[N].flags in a MSG_SOLN_META.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field flags number (unsigned 8-bit int, 1 byte) flags that store all relevant info specific to this sensor type.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var GNSSInputType = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "GNSSInputType";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
GNSSInputType.prototype = Object.create(SBP.prototype);
GNSSInputType.prototype.messageType = "GNSSInputType";
GNSSInputType.prototype.constructor = GNSSInputType;
GNSSInputType.prototype.parser = new Parser()
  .endianess('little')
  .uint8('flags');
GNSSInputType.prototype.fieldSpec = [];
GNSSInputType.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message fragment IMUInputType
 *
 * Metadata around the IMU sensors involved in the fuzed solution. Accessible
 * through sol_in[N].flags in a MSG_SOLN_META.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field flags number (unsigned 8-bit int, 1 byte) Instrument time, grade, and architecture for a sensor.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var IMUInputType = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "IMUInputType";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
IMUInputType.prototype = Object.create(SBP.prototype);
IMUInputType.prototype.messageType = "IMUInputType";
IMUInputType.prototype.constructor = IMUInputType;
IMUInputType.prototype.parser = new Parser()
  .endianess('little')
  .uint8('flags');
IMUInputType.prototype.fieldSpec = [];
IMUInputType.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message fragment OdoInputType
 *
 * Metadata around the Odometry sensors involved in the fuzed solution. Accessible
 * through sol_in[N].flags in a MSG_SOLN_META.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field flags number (unsigned 8-bit int, 1 byte) Instrument ODO rate, grade, and quality.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var OdoInputType = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "OdoInputType";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
OdoInputType.prototype = Object.create(SBP.prototype);
OdoInputType.prototype.messageType = "OdoInputType";
OdoInputType.prototype.constructor = OdoInputType;
OdoInputType.prototype.parser = new Parser()
  .endianess('little')
  .uint8('flags');
OdoInputType.prototype.fieldSpec = [];
OdoInputType.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

module.exports = {
  SolutionInputType: SolutionInputType,
  0xFF0F: MsgSolnMetaDepA,
  MsgSolnMetaDepA: MsgSolnMetaDepA,
  0xFF0E: MsgSolnMeta,
  MsgSolnMeta: MsgSolnMeta,
  GNSSInputType: GNSSInputType,
  IMUInputType: IMUInputType,
  OdoInputType: OdoInputType,
}