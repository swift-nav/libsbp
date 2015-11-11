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
 * Automatically generated from piksi/yaml/swiftnav/sbp/acquisition.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Satellite acquisition messages from the device.
***********************/

var SBP = require('./sbp');
var Parser = require('binary-parser').Parser;

/**
 * SBP class for message MSG_ACQ_RESULT (0x0014).
 *
 * This message describes the results from an attempted GPS signal acquisition
 * search for a satellite PRN over a code phase/carrier frequency range. It
 * contains the parameters of the point in the acquisition search space with the
 * best signal-to-noise (SNR) ratio.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field snr number (float, 4 bytes) SNR of best point. Currently in arbitrary SNR points, but will be in units of dB
 *   Hz in a later revision of this message.
 * @field cp number (float, 4 bytes) Code phase of best point
 * @field cf number (float, 4 bytes) Carrier frequency of best point
 * @field sid number (unsigned 32-bit int, 4 bytes) Signal identifier of the satellite signal for which acquisition was attempted -
 *   values 0x00 through 0x1F represent GPS PRNs 1 through 32 respectively (PRN-
 *   minus-1 notation); other values reserved for future use.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAcqResult = function (sbp) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ACQ_RESULT";
  this.fields = this.parser.parse(sbp.payload);

  return this;
};
MsgAcqResult.prototype = Object.create(SBP.prototype);
MsgAcqResult.prototype.constructor = MsgAcqResult;
MsgAcqResult.prototype.parser = new Parser()
  .endianess('little')
  .floatle('snr')
  .floatle('cp')
  .floatle('cf')
  .uint32('sid');
MsgAcqResult.prototype.fieldSpec = [];
MsgAcqResult.prototype.fieldSpec.push(['snr', 'writeFloatLE', 4]);
MsgAcqResult.prototype.fieldSpec.push(['cp', 'writeFloatLE', 4]);
MsgAcqResult.prototype.fieldSpec.push(['cf', 'writeFloatLE', 4]);
MsgAcqResult.prototype.fieldSpec.push(['sid', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_ACQ_RESULT_DEP_A (0x0015).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field snr number (float, 4 bytes) SNR of best point. Currently dimensonless, but will have units of dB Hz in the
 *   revision of this message.
 * @field cp number (float, 4 bytes) Code phase of best point
 * @field cf number (float, 4 bytes) Carrier frequency of best point
 * @field prn number (unsigned 8-bit int, 1 byte) PRN-1 identifier of the satellite signal for which acquisition was attempted
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAcqResultDepA = function (sbp) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ACQ_RESULT_DEP_A";
  this.fields = this.parser.parse(sbp.payload);

  return this;
};
MsgAcqResultDepA.prototype = Object.create(SBP.prototype);
MsgAcqResultDepA.prototype.constructor = MsgAcqResultDepA;
MsgAcqResultDepA.prototype.parser = new Parser()
  .endianess('little')
  .floatle('snr')
  .floatle('cp')
  .floatle('cf')
  .uint8('prn');
MsgAcqResultDepA.prototype.fieldSpec = [];
MsgAcqResultDepA.prototype.fieldSpec.push(['snr', 'writeFloatLE', 4]);
MsgAcqResultDepA.prototype.fieldSpec.push(['cp', 'writeFloatLE', 4]);
MsgAcqResultDepA.prototype.fieldSpec.push(['cf', 'writeFloatLE', 4]);
MsgAcqResultDepA.prototype.fieldSpec.push(['prn', 'writeUInt8', 1]);

module.exports = {
  0x0014: MsgAcqResult,
  0x0015: MsgAcqResultDepA,
}