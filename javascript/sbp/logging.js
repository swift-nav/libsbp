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
 * Automatically generated from piksi/yaml/swiftnav/sbp/logging.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Logging and debugging messages from the device.
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;

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
MsgLog.prototype.fieldSpec.push(['text', 'string', null]);

/**
 * SBP class for message MSG_FWD (0x0402).
 *
 * This message provides the ability to forward messages over SBP.  This may take
 * the form of wrapping up SBP messages received by Piksi for logging purposes or
 * wrapping  another protocol with SBP.  The source identifier indicates from what
 * interface a forwarded stream derived. The protocol identifier identifies what
 * the expected protocol the forwarded msg contains. Protocol 0 represents SBP and
 * the remaining values are implementation defined.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field source number (unsigned 8-bit int, 1 byte) source identifier
 * @field protocol number (unsigned 8-bit int, 1 byte) protocol identifier
 * @field fwd_payload string variable length wrapped binary message
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFwd = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FWD";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFwd.prototype = Object.create(SBP.prototype);
MsgFwd.prototype.messageType = "MSG_FWD";
MsgFwd.prototype.msg_type = 0x0402;
MsgFwd.prototype.constructor = MsgFwd;
MsgFwd.prototype.parser = new Parser()
  .endianess('little')
  .uint8('source')
  .uint8('protocol')
  .string('fwd_payload', { greedy: true });
MsgFwd.prototype.fieldSpec = [];
MsgFwd.prototype.fieldSpec.push(['source', 'writeUInt8', 1]);
MsgFwd.prototype.fieldSpec.push(['protocol', 'writeUInt8', 1]);
MsgFwd.prototype.fieldSpec.push(['fwd_payload', 'string', null]);

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
MsgPrintDep.prototype.fieldSpec.push(['text', 'string', null]);

module.exports = {
  0x0401: MsgLog,
  MsgLog: MsgLog,
  0x0402: MsgFwd,
  MsgFwd: MsgFwd,
  0x0010: MsgPrintDep,
  MsgPrintDep: MsgPrintDep,
}