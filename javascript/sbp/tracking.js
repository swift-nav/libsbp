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
var Parser = require('binary-parser').Parser;
var GnssSignal = require("./gnss_signal").GnssSignal;

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
 * @field states array Satellite tracking channel state
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
MsgTrackingState.prototype.fieldSpec.push(['states', 'array', TrackingChannelState.prototype.fieldSpec, function () { return this.fields.array.length; }]);

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
MsgTrackingIq.prototype.fieldSpec.push(['corrs', 'array', TrackingChannelCorrelation.prototype.fieldSpec, function () { return this.fields.array.length; }]);

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
MsgTrackingStateDepA.prototype.fieldSpec.push(['states', 'array', TrackingChannelStateDepA.prototype.fieldSpec, function () { return this.fields.array.length; }]);

module.exports = {
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