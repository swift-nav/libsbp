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
 * Automatically generated from piksi/yaml/swiftnav/sbp/ext_events.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages reporting accurately-timestamped external events, e.g. camera shutter
 * time.
***********************/

var SBP = require('./sbp');
var Parser = require('binary-parser').Parser;

/**
 * SBP class for message MSG_EXT_EVENT (0x0101).
 *
 * Reports detection of an external event, the GPS time it occurred, which pin it
 * was and whether it was rising or falling.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field wn number (unsigned 16-bit int, 2 bytes) GPS week number
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS time of week rounded to the nearest millisecond
 * @field ns number (signed 32-bit int, 4 bytes) Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000)
 * @field flags number (unsigned 8-bit int, 1 byte) Flags
 * @field pin number (unsigned 8-bit int, 1 byte) Pin number.  0..9 = DEBUG0..9.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgExtEvent = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EXT_EVENT";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgExtEvent.prototype = Object.create(SBP.prototype);
MsgExtEvent.prototype.messageType = "MSG_EXT_EVENT";
MsgExtEvent.prototype.msg_type = 0x0101;
MsgExtEvent.prototype.constructor = MsgExtEvent;
MsgExtEvent.prototype.parser = new Parser()
  .endianess('little')
  .uint16('wn')
  .uint32('tow')
  .int32('ns')
  .uint8('flags')
  .uint8('pin');
MsgExtEvent.prototype.fieldSpec = [];
MsgExtEvent.prototype.fieldSpec.push(['wn', 'writeUInt16LE', 2]);
MsgExtEvent.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgExtEvent.prototype.fieldSpec.push(['ns', 'writeInt32LE', 4]);
MsgExtEvent.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);
MsgExtEvent.prototype.fieldSpec.push(['pin', 'writeUInt8', 1]);

module.exports = {
  0x0101: MsgExtEvent,
  MsgExtEvent: MsgExtEvent,
}