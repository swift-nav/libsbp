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
 * Automatically generated from piksi/yaml/swiftnav/sbp/tracking.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Satellite code and carrier-phase tracking messages from the device.
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;
var GnssSignal = require("./gnss").GnssSignal;
var GnssSignalDep = require("./gnss").GnssSignalDep;
var GPSTime = require("./gnss").GPSTime;
var CarrierPhase = require("./gnss").CarrierPhase;
var GPSTime = require("./gnss").GPSTime;
var GPSTimeSec = require("./gnss").GPSTimeSec;
var GPSTimeDep = require("./gnss").GPSTimeDep;
var SvId = require("./gnss").SvId;

/**
 * SBP class for message MSG_TRACKING_STATE_DETAILED_DEP_A (0x0021).
 *
 * The tracking message returns a set tracking channel parameters for a single
 * tracking channel useful for debugging issues.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field recv_time number (unsigned 64-bit int, 8 bytes) Receiver clock time.
 * @field tot GPSTime Time of transmission of signal from satellite. TOW only valid when TOW status is
 *   decoded or propagated. WN only valid when week number valid flag is set.
 * @field P number (unsigned 32-bit int, 4 bytes) Pseudorange observation. Valid only when pseudorange valid flag is set.
 * @field P_std number (unsigned 16-bit int, 2 bytes) Pseudorange observation standard deviation. Valid only when pseudorange valid
 *   flag is set.
 * @field L CarrierPhase Carrier phase observation with typical sign convention. Valid only when PLL
 *   pessimistic lock is achieved.
 * @field cn0 number (unsigned 8-bit int, 1 byte) Carrier-to-Noise density
 * @field lock number (unsigned 16-bit int, 2 bytes) Lock time. It is encoded according to DF402 from the RTCM 10403.2 Amendment 2
 *   specification. Valid values range from 0 to 15.
 * @field sid GnssSignal GNSS signal identifier.
 * @field doppler number (signed 32-bit int, 4 bytes) Carrier Doppler frequency.
 * @field doppler_std number (unsigned 16-bit int, 2 bytes) Carrier Doppler frequency standard deviation.
 * @field uptime number (unsigned 32-bit int, 4 bytes) Number of seconds of continuous tracking. Specifies how much time signal is in
 *   continuous track.
 * @field clock_offset number (signed 16-bit int, 2 bytes) TCXO clock offset. Valid only when valid clock valid flag is set.
 * @field clock_drift number (signed 16-bit int, 2 bytes) TCXO clock drift. Valid only when valid clock valid flag is set.
 * @field corr_spacing number (unsigned 16-bit int, 2 bytes) Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
 * @field acceleration number (signed 8-bit int, 1 byte) Acceleration. Valid only when acceleration valid flag is set.
 * @field sync_flags number (unsigned 8-bit int, 1 byte) Synchronization status flags.
 * @field tow_flags number (unsigned 8-bit int, 1 byte) TOW status flags.
 * @field track_flags number (unsigned 8-bit int, 1 byte) Tracking loop status flags.
 * @field nav_flags number (unsigned 8-bit int, 1 byte) Navigation data status flags.
 * @field pset_flags number (unsigned 8-bit int, 1 byte) Parameters sets flags.
 * @field misc_flags number (unsigned 8-bit int, 1 byte) Miscellaneous flags.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgTrackingStateDetailedDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TRACKING_STATE_DETAILED_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTrackingStateDetailedDepA.prototype = Object.create(SBP.prototype);
MsgTrackingStateDetailedDepA.prototype.messageType = "MSG_TRACKING_STATE_DETAILED_DEP_A";
MsgTrackingStateDetailedDepA.prototype.msg_type = 0x0021;
MsgTrackingStateDetailedDepA.prototype.constructor = MsgTrackingStateDetailedDepA;
MsgTrackingStateDetailedDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint64('recv_time')
  .nest('tot', { type: GPSTime.prototype.parser })
  .uint32('P')
  .uint16('P_std')
  .nest('L', { type: CarrierPhase.prototype.parser })
  .uint8('cn0')
  .uint16('lock')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .int32('doppler')
  .uint16('doppler_std')
  .uint32('uptime')
  .int16('clock_offset')
  .int16('clock_drift')
  .uint16('corr_spacing')
  .int8('acceleration')
  .uint8('sync_flags')
  .uint8('tow_flags')
  .uint8('track_flags')
  .uint8('nav_flags')
  .uint8('pset_flags')
  .uint8('misc_flags');
MsgTrackingStateDetailedDepA.prototype.fieldSpec = [];
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['recv_time', 'writeUInt64LE', 8]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['tot', GPSTime.prototype.fieldSpec]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['P', 'writeUInt32LE', 4]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['P_std', 'writeUInt16LE', 2]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['L', CarrierPhase.prototype.fieldSpec]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['lock', 'writeUInt16LE', 2]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['doppler', 'writeInt32LE', 4]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['doppler_std', 'writeUInt16LE', 2]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['uptime', 'writeUInt32LE', 4]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['clock_offset', 'writeInt16LE', 2]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['clock_drift', 'writeInt16LE', 2]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['corr_spacing', 'writeUInt16LE', 2]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['acceleration', 'writeInt8', 1]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['sync_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['tow_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['track_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['nav_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['pset_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['misc_flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_TRACKING_STATE_DETAILED_DEP (0x0011).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field recv_time number (unsigned 64-bit int, 8 bytes) Receiver clock time.
 * @field tot GPSTimeDep Time of transmission of signal from satellite. TOW only valid when TOW status is
 *   decoded or propagated. WN only valid when week number valid flag is set.
 * @field P number (unsigned 32-bit int, 4 bytes) Pseudorange observation. Valid only when pseudorange valid flag is set.
 * @field P_std number (unsigned 16-bit int, 2 bytes) Pseudorange observation standard deviation. Valid only when pseudorange valid
 *   flag is set.
 * @field L CarrierPhase Carrier phase observation with typical sign convention. Valid only when PLL
 *   pessimistic lock is achieved.
 * @field cn0 number (unsigned 8-bit int, 1 byte) Carrier-to-Noise density
 * @field lock number (unsigned 16-bit int, 2 bytes) Lock time. It is encoded according to DF402 from the RTCM 10403.2 Amendment 2
 *   specification. Valid values range from 0 to 15.
 * @field sid GnssSignalDep GNSS signal identifier.
 * @field doppler number (signed 32-bit int, 4 bytes) Carrier Doppler frequency.
 * @field doppler_std number (unsigned 16-bit int, 2 bytes) Carrier Doppler frequency standard deviation.
 * @field uptime number (unsigned 32-bit int, 4 bytes) Number of seconds of continuous tracking. Specifies how much time signal is in
 *   continuous track.
 * @field clock_offset number (signed 16-bit int, 2 bytes) TCXO clock offset. Valid only when valid clock valid flag is set.
 * @field clock_drift number (signed 16-bit int, 2 bytes) TCXO clock drift. Valid only when valid clock valid flag is set.
 * @field corr_spacing number (unsigned 16-bit int, 2 bytes) Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
 * @field acceleration number (signed 8-bit int, 1 byte) Acceleration. Valid only when acceleration valid flag is set.
 * @field sync_flags number (unsigned 8-bit int, 1 byte) Synchronization status flags.
 * @field tow_flags number (unsigned 8-bit int, 1 byte) TOW status flags.
 * @field track_flags number (unsigned 8-bit int, 1 byte) Tracking loop status flags.
 * @field nav_flags number (unsigned 8-bit int, 1 byte) Navigation data status flags.
 * @field pset_flags number (unsigned 8-bit int, 1 byte) Parameters sets flags.
 * @field misc_flags number (unsigned 8-bit int, 1 byte) Miscellaneous flags.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgTrackingStateDetailedDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TRACKING_STATE_DETAILED_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTrackingStateDetailedDep.prototype = Object.create(SBP.prototype);
MsgTrackingStateDetailedDep.prototype.messageType = "MSG_TRACKING_STATE_DETAILED_DEP";
MsgTrackingStateDetailedDep.prototype.msg_type = 0x0011;
MsgTrackingStateDetailedDep.prototype.constructor = MsgTrackingStateDetailedDep;
MsgTrackingStateDetailedDep.prototype.parser = new Parser()
  .endianess('little')
  .uint64('recv_time')
  .nest('tot', { type: GPSTimeDep.prototype.parser })
  .uint32('P')
  .uint16('P_std')
  .nest('L', { type: CarrierPhase.prototype.parser })
  .uint8('cn0')
  .uint16('lock')
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .int32('doppler')
  .uint16('doppler_std')
  .uint32('uptime')
  .int16('clock_offset')
  .int16('clock_drift')
  .uint16('corr_spacing')
  .int8('acceleration')
  .uint8('sync_flags')
  .uint8('tow_flags')
  .uint8('track_flags')
  .uint8('nav_flags')
  .uint8('pset_flags')
  .uint8('misc_flags');
MsgTrackingStateDetailedDep.prototype.fieldSpec = [];
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['recv_time', 'writeUInt64LE', 8]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['tot', GPSTimeDep.prototype.fieldSpec]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['P', 'writeUInt32LE', 4]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['P_std', 'writeUInt16LE', 2]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['L', CarrierPhase.prototype.fieldSpec]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['lock', 'writeUInt16LE', 2]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['doppler', 'writeInt32LE', 4]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['doppler_std', 'writeUInt16LE', 2]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['uptime', 'writeUInt32LE', 4]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['clock_offset', 'writeInt16LE', 2]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['clock_drift', 'writeInt16LE', 2]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['corr_spacing', 'writeUInt16LE', 2]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['acceleration', 'writeInt8', 1]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['sync_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['tow_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['track_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['nav_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['pset_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['misc_flags', 'writeUInt8', 1]);

/**
 * SBP class for message fragment TrackingChannelState
 *
 * Tracking channel state for a specific satellite signal and measured signal
 * power.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sid GnssSignal GNSS signal being tracked
 * @field fcn number (unsigned 8-bit int, 1 byte) Frequency channel number (GLONASS only)
 * @field cn0 number (unsigned 8-bit int, 1 byte) Carrier-to-Noise density.  Zero implies invalid cn0.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var TrackingChannelState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "TrackingChannelState";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
TrackingChannelState.prototype = Object.create(SBP.prototype);
TrackingChannelState.prototype.messageType = "TrackingChannelState";
TrackingChannelState.prototype.constructor = TrackingChannelState;
TrackingChannelState.prototype.parser = new Parser()
  .endianess('little')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .uint8('fcn')
  .uint8('cn0');
TrackingChannelState.prototype.fieldSpec = [];
TrackingChannelState.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
TrackingChannelState.prototype.fieldSpec.push(['fcn', 'writeUInt8', 1]);
TrackingChannelState.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_TRACKING_STATE (0x0041).
 *
 * The tracking message returns a variable-length array of tracking channel states.
 * It reports status and carrier-to-noise density measurements for all tracked
 * satellites.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field states array Signal tracking channel state
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgTrackingState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TRACKING_STATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTrackingState.prototype = Object.create(SBP.prototype);
MsgTrackingState.prototype.messageType = "MSG_TRACKING_STATE";
MsgTrackingState.prototype.msg_type = 0x0041;
MsgTrackingState.prototype.constructor = MsgTrackingState;
MsgTrackingState.prototype.parser = new Parser()
  .endianess('little')
  .array('states', { type: TrackingChannelState.prototype.parser, readUntil: 'eof' });
MsgTrackingState.prototype.fieldSpec = [];
MsgTrackingState.prototype.fieldSpec.push(['states', 'array', TrackingChannelState.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message fragment MeasurementState
 *
 * Measurement Engine tracking channel state for a specific satellite signal and
 * measured signal power. The mesid field for Glonass can either carry the FCN as
 * 100 + FCN where FCN is in [-7, +6] or the Slot ID (from 1 to 28)
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field mesid GnssSignal Measurement Engine GNSS signal being tracked (carries either Glonass FCN or
 *   SLOT)
 * @field cn0 number (unsigned 8-bit int, 1 byte) Carrier-to-Noise density.  Zero implies invalid cn0.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MeasurementState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MeasurementState";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MeasurementState.prototype = Object.create(SBP.prototype);
MeasurementState.prototype.messageType = "MeasurementState";
MeasurementState.prototype.constructor = MeasurementState;
MeasurementState.prototype.parser = new Parser()
  .endianess('little')
  .nest('mesid', { type: GnssSignal.prototype.parser })
  .uint8('cn0');
MeasurementState.prototype.fieldSpec = [];
MeasurementState.prototype.fieldSpec.push(['mesid', GnssSignal.prototype.fieldSpec]);
MeasurementState.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_MEASUREMENT_STATE (0x0061).
 *
 * The tracking message returns a variable-length array of tracking channel states.
 * It reports status and carrier-to-noise density measurements for all tracked
 * satellites.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field states array ME signal tracking channel state
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgMeasurementState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_MEASUREMENT_STATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgMeasurementState.prototype = Object.create(SBP.prototype);
MsgMeasurementState.prototype.messageType = "MSG_MEASUREMENT_STATE";
MsgMeasurementState.prototype.msg_type = 0x0061;
MsgMeasurementState.prototype.constructor = MsgMeasurementState;
MsgMeasurementState.prototype.parser = new Parser()
  .endianess('little')
  .array('states', { type: MeasurementState.prototype.parser, readUntil: 'eof' });
MsgMeasurementState.prototype.fieldSpec = [];
MsgMeasurementState.prototype.fieldSpec.push(['states', 'array', MeasurementState.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message fragment TrackingChannelCorrelation
 *
 * Structure containing in-phase and quadrature correlation components.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field I number (signed 16-bit int, 2 bytes) In-phase correlation
 * @field Q number (signed 16-bit int, 2 bytes) Quadrature correlation
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var TrackingChannelCorrelation = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "TrackingChannelCorrelation";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
TrackingChannelCorrelation.prototype = Object.create(SBP.prototype);
TrackingChannelCorrelation.prototype.messageType = "TrackingChannelCorrelation";
TrackingChannelCorrelation.prototype.constructor = TrackingChannelCorrelation;
TrackingChannelCorrelation.prototype.parser = new Parser()
  .endianess('little')
  .int16('I')
  .int16('Q');
TrackingChannelCorrelation.prototype.fieldSpec = [];
TrackingChannelCorrelation.prototype.fieldSpec.push(['I', 'writeInt16LE', 2]);
TrackingChannelCorrelation.prototype.fieldSpec.push(['Q', 'writeInt16LE', 2]);

/**
 * SBP class for message MSG_TRACKING_IQ (0x002D).
 *
 * When enabled, a tracking channel can output the correlations at each update
 * interval.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field channel number (unsigned 8-bit int, 1 byte) Tracking channel of origin
 * @field sid GnssSignal GNSS signal identifier
 * @field corrs array Early, Prompt and Late correlations
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgTrackingIq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TRACKING_IQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTrackingIq.prototype = Object.create(SBP.prototype);
MsgTrackingIq.prototype.messageType = "MSG_TRACKING_IQ";
MsgTrackingIq.prototype.msg_type = 0x002D;
MsgTrackingIq.prototype.constructor = MsgTrackingIq;
MsgTrackingIq.prototype.parser = new Parser()
  .endianess('little')
  .uint8('channel')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .array('corrs', { length: 3, type: TrackingChannelCorrelation.prototype.parser });
MsgTrackingIq.prototype.fieldSpec = [];
MsgTrackingIq.prototype.fieldSpec.push(['channel', 'writeUInt8', 1]);
MsgTrackingIq.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgTrackingIq.prototype.fieldSpec.push(['corrs', 'array', TrackingChannelCorrelation.prototype.fieldSpec, function () { return this.fields.array.length; }, 3]);

/**
 * SBP class for message fragment TrackingChannelCorrelationDep
 *
 * Structure containing in-phase and quadrature correlation components.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field I number (signed 32-bit int, 4 bytes) In-phase correlation
 * @field Q number (signed 32-bit int, 4 bytes) Quadrature correlation
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var TrackingChannelCorrelationDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "TrackingChannelCorrelationDep";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
TrackingChannelCorrelationDep.prototype = Object.create(SBP.prototype);
TrackingChannelCorrelationDep.prototype.messageType = "TrackingChannelCorrelationDep";
TrackingChannelCorrelationDep.prototype.constructor = TrackingChannelCorrelationDep;
TrackingChannelCorrelationDep.prototype.parser = new Parser()
  .endianess('little')
  .int32('I')
  .int32('Q');
TrackingChannelCorrelationDep.prototype.fieldSpec = [];
TrackingChannelCorrelationDep.prototype.fieldSpec.push(['I', 'writeInt32LE', 4]);
TrackingChannelCorrelationDep.prototype.fieldSpec.push(['Q', 'writeInt32LE', 4]);

/**
 * SBP class for message MSG_TRACKING_IQ_DEP_B (0x002C).
 *
 * When enabled, a tracking channel can output the correlations at each update
 * interval.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field channel number (unsigned 8-bit int, 1 byte) Tracking channel of origin
 * @field sid GnssSignal GNSS signal identifier
 * @field corrs array Early, Prompt and Late correlations
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgTrackingIqDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TRACKING_IQ_DEP_B";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTrackingIqDepB.prototype = Object.create(SBP.prototype);
MsgTrackingIqDepB.prototype.messageType = "MSG_TRACKING_IQ_DEP_B";
MsgTrackingIqDepB.prototype.msg_type = 0x002C;
MsgTrackingIqDepB.prototype.constructor = MsgTrackingIqDepB;
MsgTrackingIqDepB.prototype.parser = new Parser()
  .endianess('little')
  .uint8('channel')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .array('corrs', { length: 3, type: TrackingChannelCorrelationDep.prototype.parser });
MsgTrackingIqDepB.prototype.fieldSpec = [];
MsgTrackingIqDepB.prototype.fieldSpec.push(['channel', 'writeUInt8', 1]);
MsgTrackingIqDepB.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgTrackingIqDepB.prototype.fieldSpec.push(['corrs', 'array', TrackingChannelCorrelationDep.prototype.fieldSpec, function () { return this.fields.array.length; }, 3]);

/**
 * SBP class for message MSG_TRACKING_IQ_DEP_A (0x001C).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field channel number (unsigned 8-bit int, 1 byte) Tracking channel of origin
 * @field sid GnssSignalDep GNSS signal identifier
 * @field corrs array Early, Prompt and Late correlations
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgTrackingIqDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TRACKING_IQ_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTrackingIqDepA.prototype = Object.create(SBP.prototype);
MsgTrackingIqDepA.prototype.messageType = "MSG_TRACKING_IQ_DEP_A";
MsgTrackingIqDepA.prototype.msg_type = 0x001C;
MsgTrackingIqDepA.prototype.constructor = MsgTrackingIqDepA;
MsgTrackingIqDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint8('channel')
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .array('corrs', { length: 3, type: TrackingChannelCorrelationDep.prototype.parser });
MsgTrackingIqDepA.prototype.fieldSpec = [];
MsgTrackingIqDepA.prototype.fieldSpec.push(['channel', 'writeUInt8', 1]);
MsgTrackingIqDepA.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
MsgTrackingIqDepA.prototype.fieldSpec.push(['corrs', 'array', TrackingChannelCorrelationDep.prototype.fieldSpec, function () { return this.fields.array.length; }, 3]);

/**
 * SBP class for message fragment TrackingChannelStateDepA
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field state number (unsigned 8-bit int, 1 byte) Status of tracking channel
 * @field prn number (unsigned 8-bit int, 1 byte) PRN-1 being tracked
 * @field cn0 number (float, 4 bytes) Carrier-to-noise density
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var TrackingChannelStateDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "TrackingChannelStateDepA";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
TrackingChannelStateDepA.prototype = Object.create(SBP.prototype);
TrackingChannelStateDepA.prototype.messageType = "TrackingChannelStateDepA";
TrackingChannelStateDepA.prototype.constructor = TrackingChannelStateDepA;
TrackingChannelStateDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint8('state')
  .uint8('prn')
  .floatle('cn0');
TrackingChannelStateDepA.prototype.fieldSpec = [];
TrackingChannelStateDepA.prototype.fieldSpec.push(['state', 'writeUInt8', 1]);
TrackingChannelStateDepA.prototype.fieldSpec.push(['prn', 'writeUInt8', 1]);
TrackingChannelStateDepA.prototype.fieldSpec.push(['cn0', 'writeFloatLE', 4]);

/**
 * SBP class for message MSG_TRACKING_STATE_DEP_A (0x0016).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field states array Satellite tracking channel state
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgTrackingStateDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TRACKING_STATE_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTrackingStateDepA.prototype = Object.create(SBP.prototype);
MsgTrackingStateDepA.prototype.messageType = "MSG_TRACKING_STATE_DEP_A";
MsgTrackingStateDepA.prototype.msg_type = 0x0016;
MsgTrackingStateDepA.prototype.constructor = MsgTrackingStateDepA;
MsgTrackingStateDepA.prototype.parser = new Parser()
  .endianess('little')
  .array('states', { type: TrackingChannelStateDepA.prototype.parser, readUntil: 'eof' });
MsgTrackingStateDepA.prototype.fieldSpec = [];
MsgTrackingStateDepA.prototype.fieldSpec.push(['states', 'array', TrackingChannelStateDepA.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message fragment TrackingChannelStateDepB
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field state number (unsigned 8-bit int, 1 byte) Status of tracking channel
 * @field sid GnssSignalDep GNSS signal being tracked
 * @field cn0 number (float, 4 bytes) Carrier-to-noise density
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var TrackingChannelStateDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "TrackingChannelStateDepB";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
TrackingChannelStateDepB.prototype = Object.create(SBP.prototype);
TrackingChannelStateDepB.prototype.messageType = "TrackingChannelStateDepB";
TrackingChannelStateDepB.prototype.constructor = TrackingChannelStateDepB;
TrackingChannelStateDepB.prototype.parser = new Parser()
  .endianess('little')
  .uint8('state')
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .floatle('cn0');
TrackingChannelStateDepB.prototype.fieldSpec = [];
TrackingChannelStateDepB.prototype.fieldSpec.push(['state', 'writeUInt8', 1]);
TrackingChannelStateDepB.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
TrackingChannelStateDepB.prototype.fieldSpec.push(['cn0', 'writeFloatLE', 4]);

/**
 * SBP class for message MSG_TRACKING_STATE_DEP_B (0x0013).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field states array Signal tracking channel state
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgTrackingStateDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TRACKING_STATE_DEP_B";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTrackingStateDepB.prototype = Object.create(SBP.prototype);
MsgTrackingStateDepB.prototype.messageType = "MSG_TRACKING_STATE_DEP_B";
MsgTrackingStateDepB.prototype.msg_type = 0x0013;
MsgTrackingStateDepB.prototype.constructor = MsgTrackingStateDepB;
MsgTrackingStateDepB.prototype.parser = new Parser()
  .endianess('little')
  .array('states', { type: TrackingChannelStateDepB.prototype.parser, readUntil: 'eof' });
MsgTrackingStateDepB.prototype.fieldSpec = [];
MsgTrackingStateDepB.prototype.fieldSpec.push(['states', 'array', TrackingChannelStateDepB.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

module.exports = {
  0x0021: MsgTrackingStateDetailedDepA,
  MsgTrackingStateDetailedDepA: MsgTrackingStateDetailedDepA,
  0x0011: MsgTrackingStateDetailedDep,
  MsgTrackingStateDetailedDep: MsgTrackingStateDetailedDep,
  TrackingChannelState: TrackingChannelState,
  0x0041: MsgTrackingState,
  MsgTrackingState: MsgTrackingState,
  MeasurementState: MeasurementState,
  0x0061: MsgMeasurementState,
  MsgMeasurementState: MsgMeasurementState,
  TrackingChannelCorrelation: TrackingChannelCorrelation,
  0x002D: MsgTrackingIq,
  MsgTrackingIq: MsgTrackingIq,
  TrackingChannelCorrelationDep: TrackingChannelCorrelationDep,
  0x002C: MsgTrackingIqDepB,
  MsgTrackingIqDepB: MsgTrackingIqDepB,
  0x001C: MsgTrackingIqDepA,
  MsgTrackingIqDepA: MsgTrackingIqDepA,
  TrackingChannelStateDepA: TrackingChannelStateDepA,
  0x0016: MsgTrackingStateDepA,
  MsgTrackingStateDepA: MsgTrackingStateDepA,
  TrackingChannelStateDepB: TrackingChannelStateDepB,
  0x0013: MsgTrackingStateDepB,
  MsgTrackingStateDepB: MsgTrackingStateDepB,
}