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
 * Automatically generated from piksi/yaml/swiftnav/sbp/system.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Standardized system messages from Swift Navigation devices.
***********************/

var SBP = require('./sbp');
var Parser = require('binary-parser').Parser;

/**
 * SBP class for message MSG_STARTUP (0xFF00).
 *
 * The system start-up message is sent once on system start-up. It notifies the
 * host or other attached devices that the system has started and is now ready to
 * respond to commands or configuration requests.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field reserved number (unsigned 32-bit int, 4 bytes) Reserved
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
  .uint32('reserved');
MsgStartup.prototype.fieldSpec = [];
MsgStartup.prototype.fieldSpec.push(['reserved', 'writeUInt32LE', 4]);

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

module.exports = {
  0xFF00: MsgStartup,
  MsgStartup: MsgStartup,
  0xFFFF: MsgHeartbeat,
  MsgHeartbeat: MsgHeartbeat,
}