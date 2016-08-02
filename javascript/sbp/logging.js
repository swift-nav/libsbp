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
 * Automatically generated from piksi/yaml/swiftnav/sbp/logging.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Logging and debugging messages from the device.
***********************/

var SBP = require('./sbp');
var Parser = require('binary-parser').Parser;

/**
 * SBP class for message MSG_LOG (0x0401).
 *
 * This message contains a human-readable payload string from the device containing
 * errors, warnings and informational messages at ERROR, WARNING, DEBUG, INFO
 * logging levels.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field level number (unsigned 8-bit int, 1 byte) Logging level
 * @field text string Human-readable string
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgLog = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_LOG";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgLog.prototype = Object.create(SBP.prototype);
MsgLog.prototype.messageType = "MSG_LOG";
MsgLog.prototype.msg_type = 0x0401;
MsgLog.prototype.constructor = MsgLog;
MsgLog.prototype.parser = new Parser()
  .endianess('little')
  .uint8('level')
  .string('text', { greedy: true });
MsgLog.prototype.fieldSpec = [];
MsgLog.prototype.fieldSpec.push(['level', 'writeUInt8', 1]);
MsgLog.prototype.fieldSpec.push(['text', 'string']);

/**
 * SBP class for message MSG_TWEET (0x0012).
 *
 * All the news fit to tweet.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tweet string Human-readable string
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgTweet = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TWEET";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTweet.prototype = Object.create(SBP.prototype);
MsgTweet.prototype.messageType = "MSG_TWEET";
MsgTweet.prototype.msg_type = 0x0012;
MsgTweet.prototype.constructor = MsgTweet;
MsgTweet.prototype.parser = new Parser()
  .endianess('little')
  .string('tweet', { length: 140 });
MsgTweet.prototype.fieldSpec = [];
MsgTweet.prototype.fieldSpec.push(['tweet', 'string']);

/**
 * SBP class for message MSG_PRINT_DEP (0x0010).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field text string Human-readable string
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgPrintDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_PRINT_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPrintDep.prototype = Object.create(SBP.prototype);
MsgPrintDep.prototype.messageType = "MSG_PRINT_DEP";
MsgPrintDep.prototype.msg_type = 0x0010;
MsgPrintDep.prototype.constructor = MsgPrintDep;
MsgPrintDep.prototype.parser = new Parser()
  .endianess('little')
  .string('text', { greedy: true });
MsgPrintDep.prototype.fieldSpec = [];
MsgPrintDep.prototype.fieldSpec.push(['text', 'string']);

module.exports = {
  0x0401: MsgLog,
  MsgLog: MsgLog,
  0x0012: MsgTweet,
  MsgTweet: MsgTweet,
  0x0010: MsgPrintDep,
  MsgPrintDep: MsgPrintDep,
}