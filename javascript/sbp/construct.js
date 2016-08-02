/**
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Joshua Gross <josh@swift-nav.com>
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 *
 * This module is for constructing arbitrary SBP messages.
 */

var sbp = require('./index.js');
var SBP = require('./sbp.js');
var crc = sbp.crc16;

/**
 * Construct a full SBP message, including the message envelope
 *  and internal fields. Also calculates the CRC for you.
 *
 * @param MsgType {Function} The message type you want to construct.
 * @param fields {Object} Optional key-value pairs of message fields.
 */
module.exports = function constructMsg (MsgType, fields, sender) {
  if (typeof MsgType !== 'function') {
    throw new Error('The MsgType parameter must be a valid SBP message type constructor.');
  }

  if (typeof MsgType.prototype.msg_type !== 'number') {
    throw new Error('The MsgType must have a valid `msg_type` field.');
  }

  fields = fields || {};

  // Msg envelope
  var msgEnvelope = new SBP({});

  // Message
  var msg = new MsgType(msgEnvelope, fields);
  msgEnvelope.payload = msg.payloadToBuffer();

  // Construct message envelope
  msgEnvelope.preamble = sbp.preambleByte;
  msgEnvelope.msg_type = MsgType.prototype.msg_type;
  msgEnvelope.sender = sender || 0; // see SBP.pdf documentation
  msgEnvelope.length = msgEnvelope.payload.length;
  msgEnvelope.crc = crc(msgEnvelope.payload,
                      crc(msgEnvelope.getLengthBuffer(),
                        crc(msgEnvelope.getSenderBuffer(),
                          crc(msgEnvelope.getMsgTypeBuffer()))));

  return msg;
};
