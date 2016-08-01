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

var mkBuf = function (size, writer, payload, offset) {
  var b = new Buffer(size);
  b[writer](payload, offset || 0);
  return b;
}

/**
 * Parent prototypal class for all SBP message objects.
 */
function SBP (sbp) {
  this.messageType = "raw";
  this.sbp = sbp || {};
  this.fields = {};

  return this;
}

SBP.prototype.fieldSpec = [];

/**
 * Convert a payload to its binary representation, based on this object's fieldSpec.
 */
SBP.prototype.payloadToBuffer = function payloadToBuffer (fieldSpec, data) {
  var buffers = [];

  fieldSpec = fieldSpec || this.fieldSpec;
  data = data || this.fields;

  for (var k in fieldSpec) {
    var field = fieldSpec[k];
    var fieldName = field[0];
    var dataType = field[1];

    var fieldSize = function (sz) {
      return typeof sz === 'function' ? sz.apply(this) : sz;
    }.bind(this);

    if (typeof dataType === 'string' && dataType.indexOf('write') === 0) {
      var dataSize = fieldSize(field[2]);
      var b = new Buffer(dataSize);
      b[dataType](data[fieldName], 0);
      buffers.push(b);
    } else if (dataType === 'string') {
      var b = new Buffer(data[fieldName].length);
      b.write(data[fieldName]);
      buffers.push(b);
    } else if (dataType === 'array') {
      var dataFill = field[2];
      for (var i in data[fieldName]) {
        var iData = data[fieldName][i];
        if (Array.isArray(dataFill)) {
          // Nested type
          buffers = buffers.concat(this.payloadToBuffer(dataFill, iData));
        } else {
          // Built-in type
          var b = new Buffer(fieldSize(field[3]));
          b[dataFill](iData, 0);
          buffers.push(b);
        }
      }
    } else {
      // Nested type
      buffers = buffers.concat(this.payloadToBuffer(dataType, data[fieldName]));
    }
  }

  return Buffer.concat(buffers);
};

/**
 * Make a buffer for the message length field.
 */
SBP.prototype.getLengthBuffer = function getLengthBuffer () {
  return mkBuf(1, 'writeUInt8', this.length || this.sbp.length, 0);
};

/**
 * Make a buffer for the message sender field.
 */
SBP.prototype.getSenderBuffer = function getSenderBuffer () {
  return mkBuf(2, 'writeUInt16LE', this.sender || this.sbp.sender, 0);
};

/**
 * Make a buffer for the message preamble field.
 */
SBP.prototype.getPreambleBuffer = function getPreambleBuffer () {
  return mkBuf(1, 'writeUInt8', this.preamble || this.sbp.preamble, 0);
};

/**
 * Make a buffer for the message type field.
 */
SBP.prototype.getMsgTypeBuffer = function getMsgTypeBuffer () {
  return mkBuf(2, 'writeUInt16LE', this.msg_type || this.sbp.msg_type, 0);
};

/**
 * Convert a message to its binary representation.
 */
SBP.prototype.toBuffer = function toBuffer () {
  var payload = this.payloadToBuffer();
  var crcBuf = mkBuf(2, 'writeUInt16LE', this.crc || this.sbp.crc, 0);
  var buffers = [
    this.getPreambleBuffer(),
    this.getMsgTypeBuffer(),
    this.getSenderBuffer(),
    this.getLengthBuffer()
  ];


  return Buffer.concat(buffers.concat(payload).concat(crcBuf));
};

/**
 * Convert a message to JSON by iterating through `SBP` and `fields`.
 */
SBP.prototype.toJSON = function toJSON () {
  var dict = {};

  Object.keys(this.sbp).map(function (k) {
    if (this.sbp[k] instanceof Buffer) {
      dict[k] = this.sbp[k].toString('base64');
    } else {
      dict[k] = this.sbp[k];
    }
  }.bind(this));

  Object.keys(this.fields).map(function (k) {
    dict[k] = this.fields[k];
  }.bind(this));

  return JSON.stringify(dict);
};

/**
 * Serialize a message into base64. Note that this will convert the entire
 *  message - SBP fields and payload/fields, not just the payload.
 */
SBP.prototype.toBase64 = function toBase64 () {
  return this.toBuffer().toString('base64');
};

module.exports = SBP;
