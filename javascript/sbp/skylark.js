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
 * Automatically generated from spec/yaml/swiftnav/sbp/skylark.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages from the Skylark corrections service.
***********************/

let SBP = require('./sbp');
let Parser = require('./parser');
let Int64 = require('node-int64');
let UInt64 = require('cuint').UINT64;

/**
 * SBP class for message MSG_ACKNOWLEDGE (0x0FA0).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field request_id number (unsigned 8-bit int, 1 byte) Echo of the request ID field from the corresponding CRA message, or 255 if no
 *   request ID was provided.
 * @field area_id number (unsigned 32-bit int, 4 bytes) Echo of the Area ID field from the corresponding CRA message.
 * @field response_code number (unsigned 8-bit int, 1 byte) Reported status of the request.
 * @field correction_mask_on_demand number (unsigned 16-bit int, 2 bytes) Contains the message group(s) that will be sent in response from the
 *   corresponding CRA correction mask. An echo of the correction mask field from the
 *   corresponding CRA message.
 * @field correction_mask_stream number (unsigned 16-bit int, 2 bytes) For future expansion. Always set to 0.
 * @field solution_id number (unsigned 8-bit int, 1 byte) The solution ID of the instance providing the corrections.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
let MsgAcknowledge = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ACKNOWLEDGE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAcknowledge.prototype = Object.create(SBP.prototype);
MsgAcknowledge.prototype.messageType = "MSG_ACKNOWLEDGE";
MsgAcknowledge.prototype.msg_type = 0x0FA0;
MsgAcknowledge.prototype.constructor = MsgAcknowledge;
MsgAcknowledge.prototype.parser = new Parser()
  .endianess('little')
  .uint8('request_id')
  .uint32('area_id')
  .uint8('response_code')
  .uint16('correction_mask_on_demand')
  .uint16('correction_mask_stream')
  .uint8('solution_id');
MsgAcknowledge.prototype.fieldSpec = [];
MsgAcknowledge.prototype.fieldSpec.push(['request_id', 'writeUInt8', 1]);
MsgAcknowledge.prototype.fieldSpec.push(['area_id', 'writeUInt32LE', 4]);
MsgAcknowledge.prototype.fieldSpec.push(['response_code', 'writeUInt8', 1]);
MsgAcknowledge.prototype.fieldSpec.push(['correction_mask_on_demand', 'writeUInt16LE', 2]);
MsgAcknowledge.prototype.fieldSpec.push(['correction_mask_stream', 'writeUInt16LE', 2]);
MsgAcknowledge.prototype.fieldSpec.push(['solution_id', 'writeUInt8', 1]);

module.exports = {
  0x0FA0: MsgAcknowledge,
  MsgAcknowledge: MsgAcknowledge,
}