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
 * Automatically generated from piksi/yaml/swiftnav/sbp/user.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages reserved for use by the user.
***********************/

var SBP = require('./sbp');
var Parser = require('binary-parser').Parser;

/**
 * SBP class for message MSG_USER_DATA (0x0800).
 *
 * This message can contain any application specific user data up to a maximum
 * length of 255 bytes per message.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field contents array User data payload
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgUserData = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_USER_DATA";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgUserData.prototype = Object.create(SBP.prototype);
MsgUserData.prototype.messageType = "MSG_USER_DATA";
MsgUserData.prototype.msg_type = 0x0800;
MsgUserData.prototype.constructor = MsgUserData;
MsgUserData.prototype.parser = new Parser()
  .endianess('little')
  .array('contents', { type: 'uint8', readUntil: 'eof' });
MsgUserData.prototype.fieldSpec = [];
MsgUserData.prototype.fieldSpec.push(['contents', 'array', 'writeUInt8', function () { return 1; }]);

module.exports = {
  0x0800: MsgUserData,
  MsgUserData: MsgUserData,
}