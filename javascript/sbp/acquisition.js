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
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;
var GnssSignal = require("./gnss_signal").GnssSignal;

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
 * @field sid GnssSignal GNSS signal for which acquisition was attempted
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAcqResult = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ACQ_RESULT";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAcqResult.prototype = Object.create(SBP.prototype);
MsgAcqResult.prototype.messageType = "MSG_ACQ_RESULT";
MsgAcqResult.prototype.msg_type = 0x0014;
MsgAcqResult.prototype.constructor = MsgAcqResult;
MsgAcqResult.prototype.parser = new Parser()
  .endianess('little')
  .floatle('snr')
  .floatle('cp')
  .floatle('cf')
  .nest('sid', { type: GnssSignal.prototype.parser });
MsgAcqResult.prototype.fieldSpec = [];
MsgAcqResult.prototype.fieldSpec.push(['snr', 'writeFloatLE', 4]);
MsgAcqResult.prototype.fieldSpec.push(['cp', 'writeFloatLE', 4]);
MsgAcqResult.prototype.fieldSpec.push(['cf', 'writeFloatLE', 4]);
MsgAcqResult.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);

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
var MsgAcqResultDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ACQ_RESULT_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAcqResultDepA.prototype = Object.create(SBP.prototype);
MsgAcqResultDepA.prototype.messageType = "MSG_ACQ_RESULT_DEP_A";
MsgAcqResultDepA.prototype.msg_type = 0x0015;
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

/**
 * SBP class for message fragment AcqSvProfile
 *
 * Profile for a specific SV for debugging purposes The message describes SV
 * profile during acquisition time. The message is used to debug and measure the
 * performance.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field job_type number (unsigned 8-bit int, 1 byte) SV search job type (deep, fallback, etc)
 * @field status number (unsigned 8-bit int, 1 byte) Acquisition status 1 is Success, 0 is Failure
 * @field cn0 number (unsigned 16-bit int, 2 bytes) CN0 value. Only valid if status is '1'
 * @field int_time number (unsigned 8-bit int, 1 byte) Acquisition integration time
 * @field sid GnssSignal GNSS signal for which acquisition was attempted
 * @field bin_width number (unsigned 16-bit int, 2 bytes) Acq frequency bin width
 * @field timestamp number (unsigned 32-bit int, 4 bytes) Timestamp of the job complete event
 * @field time_spent number (unsigned 32-bit int, 4 bytes) Time spent to search for sid.code
 * @field cf_min number (signed 32-bit int, 4 bytes) Doppler range lowest frequency
 * @field cf_max number (signed 32-bit int, 4 bytes) Doppler range highest frequency
 * @field cf number (signed 32-bit int, 4 bytes) Doppler value of detected peak. Only valid if status is '1'
 * @field cp number (unsigned 32-bit int, 4 bytes) Codephase of detected peak. Only valid if status is '1'
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var AcqSvProfile = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "AcqSvProfile";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
AcqSvProfile.prototype = Object.create(SBP.prototype);
AcqSvProfile.prototype.messageType = "AcqSvProfile";
AcqSvProfile.prototype.constructor = AcqSvProfile;
AcqSvProfile.prototype.parser = new Parser()
  .endianess('little')
  .uint8('job_type')
  .uint8('status')
  .uint16('cn0')
  .uint8('int_time')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .uint16('bin_width')
  .uint32('timestamp')
  .uint32('time_spent')
  .int32('cf_min')
  .int32('cf_max')
  .int32('cf')
  .uint32('cp');
AcqSvProfile.prototype.fieldSpec = [];
AcqSvProfile.prototype.fieldSpec.push(['job_type', 'writeUInt8', 1]);
AcqSvProfile.prototype.fieldSpec.push(['status', 'writeUInt8', 1]);
AcqSvProfile.prototype.fieldSpec.push(['cn0', 'writeUInt16LE', 2]);
AcqSvProfile.prototype.fieldSpec.push(['int_time', 'writeUInt8', 1]);
AcqSvProfile.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
AcqSvProfile.prototype.fieldSpec.push(['bin_width', 'writeUInt16LE', 2]);
AcqSvProfile.prototype.fieldSpec.push(['timestamp', 'writeUInt32LE', 4]);
AcqSvProfile.prototype.fieldSpec.push(['time_spent', 'writeUInt32LE', 4]);
AcqSvProfile.prototype.fieldSpec.push(['cf_min', 'writeInt32LE', 4]);
AcqSvProfile.prototype.fieldSpec.push(['cf_max', 'writeInt32LE', 4]);
AcqSvProfile.prototype.fieldSpec.push(['cf', 'writeInt32LE', 4]);
AcqSvProfile.prototype.fieldSpec.push(['cp', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_ACQ_SV_PROFILE (0x001E).
 *
 * The message describes all SV profiles during acquisition time. The message is
 * used to debug and measure the performance.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field acq_sv_profile array SV profiles during acquisition time
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAcqSvProfile = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ACQ_SV_PROFILE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAcqSvProfile.prototype = Object.create(SBP.prototype);
MsgAcqSvProfile.prototype.messageType = "MSG_ACQ_SV_PROFILE";
MsgAcqSvProfile.prototype.msg_type = 0x001E;
MsgAcqSvProfile.prototype.constructor = MsgAcqSvProfile;
MsgAcqSvProfile.prototype.parser = new Parser()
  .endianess('little')
  .array('acq_sv_profile', { type: AcqSvProfile.prototype.parser, readUntil: 'eof' });
MsgAcqSvProfile.prototype.fieldSpec = [];
MsgAcqSvProfile.prototype.fieldSpec.push(['acq_sv_profile', 'array', AcqSvProfile.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

module.exports = {
  0x0014: MsgAcqResult,
  MsgAcqResult: MsgAcqResult,
  0x0015: MsgAcqResultDepA,
  MsgAcqResultDepA: MsgAcqResultDepA,
  AcqSvProfile: AcqSvProfile,
  0x001E: MsgAcqSvProfile,
  MsgAcqSvProfile: MsgAcqSvProfile,
}