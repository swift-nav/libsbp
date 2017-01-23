/**
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Joshua Gross <josh@swift-nav.com>
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
var GnssSignal16 = require("./gnss").GnssSignal16;
var GPSTime = require("./gnss").GPSTime;
var CarrierPhase = require("./gnss").CarrierPhase;
var GPSTimeNano = require("./gnss").GPSTimeNano;

/**
 * SBP class for message MSG_TRACKING_STATE_DETAILED (0x0011).
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
var MsgTrackingStateDetailed = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TRACKING_STATE_DETAILED";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTrackingStateDetailed.prototype = Object.create(SBP.prototype);
MsgTrackingStateDetailed.prototype.messageType = "MSG_TRACKING_STATE_DETAILED";
MsgTrackingStateDetailed.prototype.msg_type = 0x0011;
MsgTrackingStateDetailed.prototype.constructor = MsgTrackingStateDetailed;
MsgTrackingStateDetailed.prototype.parser = new Parser()
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
MsgTrackingStateDetailed.prototype.fieldSpec = [];
MsgTrackingStateDetailed.prototype.fieldSpec.push(['recv_time', 'writeUInt64LE', 8]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['tot', GPSTime.prototype.fieldSpec]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['P', 'writeUInt32LE', 4]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['P_std', 'writeUInt16LE', 2]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['L', CarrierPhase.prototype.fieldSpec]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['lock', 'writeUInt16LE', 2]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['doppler', 'writeInt32LE', 4]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['doppler_std', 'writeUInt16LE', 2]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['uptime', 'writeUInt32LE', 4]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['clock_offset', 'writeInt16LE', 2]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['clock_drift', 'writeInt16LE', 2]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['corr_spacing', 'writeUInt16LE', 2]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['acceleration', 'writeInt8', 1]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['sync_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['tow_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['track_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['nav_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['pset_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailed.prototype.fieldSpec.push(['misc_flags', 'writeUInt8', 1]);

/**
 * SBP class for message fragment TrackingChannelState
 *
 * Tracking channel state for a specific satellite signal and measured signal
 * power.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field state number (unsigned 8-bit int, 1 byte) Status of tracking channel
 * @field sid GnssSignal GNSS signal being tracked
 * @field cn0 number (float, 4 bytes) Carrier-to-noise density
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
  .uint8('state')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .floatle('cn0');
TrackingChannelState.prototype.fieldSpec = [];
TrackingChannelState.prototype.fieldSpec.push(['state', 'writeUInt8', 1]);
TrackingChannelState.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
TrackingChannelState.prototype.fieldSpec.push(['cn0', 'writeFloatLE', 4]);

/**
 * SBP class for message MSG_TRACKING_STATE (0x0013).
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
MsgTrackingState.prototype.msg_type = 0x0013;
MsgTrackingState.prototype.constructor = MsgTrackingState;
MsgTrackingState.prototype.parser = new Parser()
  .endianess('little')
  .array('states', { type: TrackingChannelState.prototype.parser, readUntil: 'eof' });
MsgTrackingState.prototype.fieldSpec = [];
MsgTrackingState.prototype.fieldSpec.push(['states', 'array', TrackingChannelState.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message fragment TrackingChannelCorrelation
 *
 * Structure containing in-phase and quadrature correlation components.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field I number (signed 32-bit int, 4 bytes) In-phase correlation
 * @field Q number (signed 32-bit int, 4 bytes) Quadrature correlation
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
  .int32('I')
  .int32('Q');
TrackingChannelCorrelation.prototype.fieldSpec = [];
TrackingChannelCorrelation.prototype.fieldSpec.push(['I', 'writeInt32LE', 4]);
TrackingChannelCorrelation.prototype.fieldSpec.push(['Q', 'writeInt32LE', 4]);

/**
 * SBP class for message MSG_TRACKING_IQ (0x001C).
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
MsgTrackingIq.prototype.msg_type = 0x001C;
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

module.exports = {
  0x0011: MsgTrackingStateDetailed,
  MsgTrackingStateDetailed: MsgTrackingStateDetailed,
  TrackingChannelState: TrackingChannelState,
  0x0013: MsgTrackingState,
  MsgTrackingState: MsgTrackingState,
  TrackingChannelCorrelation: TrackingChannelCorrelation,
  0x001C: MsgTrackingIq,
  MsgTrackingIq: MsgTrackingIq,
  TrackingChannelStateDepA: TrackingChannelStateDepA,
  0x0016: MsgTrackingStateDepA,
  MsgTrackingStateDepA: MsgTrackingStateDepA,
}