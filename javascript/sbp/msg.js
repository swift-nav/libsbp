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

var Parser = require('binary-parser').Parser;
var path = require('path');
var streams = require('stream');
var SBP = require('./sbp');

var SBP_PREAMBLE = 0x55;

// Default sender ID. Intended for messages sent from the host to the device.
var SENDER_ID = 0x42;

var crc16tab =  [0x0000,0x1021,0x2042,0x3063,0x4084,0x50a5,0x60c6,0x70e7,
                 0x8108,0x9129,0xa14a,0xb16b,0xc18c,0xd1ad,0xe1ce,0xf1ef,
                 0x1231,0x0210,0x3273,0x2252,0x52b5,0x4294,0x72f7,0x62d6,
                 0x9339,0x8318,0xb37b,0xa35a,0xd3bd,0xc39c,0xf3ff,0xe3de,
                 0x2462,0x3443,0x0420,0x1401,0x64e6,0x74c7,0x44a4,0x5485,
                 0xa56a,0xb54b,0x8528,0x9509,0xe5ee,0xf5cf,0xc5ac,0xd58d,
                 0x3653,0x2672,0x1611,0x0630,0x76d7,0x66f6,0x5695,0x46b4,
                 0xb75b,0xa77a,0x9719,0x8738,0xf7df,0xe7fe,0xd79d,0xc7bc,
                 0x48c4,0x58e5,0x6886,0x78a7,0x0840,0x1861,0x2802,0x3823,
                 0xc9cc,0xd9ed,0xe98e,0xf9af,0x8948,0x9969,0xa90a,0xb92b,
                 0x5af5,0x4ad4,0x7ab7,0x6a96,0x1a71,0x0a50,0x3a33,0x2a12,
                 0xdbfd,0xcbdc,0xfbbf,0xeb9e,0x9b79,0x8b58,0xbb3b,0xab1a,
                 0x6ca6,0x7c87,0x4ce4,0x5cc5,0x2c22,0x3c03,0x0c60,0x1c41,
                 0xedae,0xfd8f,0xcdec,0xddcd,0xad2a,0xbd0b,0x8d68,0x9d49,
                 0x7e97,0x6eb6,0x5ed5,0x4ef4,0x3e13,0x2e32,0x1e51,0x0e70,
                 0xff9f,0xefbe,0xdfdd,0xcffc,0xbf1b,0xaf3a,0x9f59,0x8f78,
                 0x9188,0x81a9,0xb1ca,0xa1eb,0xd10c,0xc12d,0xf14e,0xe16f,
                 0x1080,0x00a1,0x30c2,0x20e3,0x5004,0x4025,0x7046,0x6067,
                 0x83b9,0x9398,0xa3fb,0xb3da,0xc33d,0xd31c,0xe37f,0xf35e,
                 0x02b1,0x1290,0x22f3,0x32d2,0x4235,0x5214,0x6277,0x7256,
                 0xb5ea,0xa5cb,0x95a8,0x8589,0xf56e,0xe54f,0xd52c,0xc50d,
                 0x34e2,0x24c3,0x14a0,0x0481,0x7466,0x6447,0x5424,0x4405,
                 0xa7db,0xb7fa,0x8799,0x97b8,0xe75f,0xf77e,0xc71d,0xd73c,
                 0x26d3,0x36f2,0x0691,0x16b0,0x6657,0x7676,0x4615,0x5634,
                 0xd94c,0xc96d,0xf90e,0xe92f,0x99c8,0x89e9,0xb98a,0xa9ab,
                 0x5844,0x4865,0x7806,0x6827,0x18c0,0x08e1,0x3882,0x28a3,
                 0xcb7d,0xdb5c,0xeb3f,0xfb1e,0x8bf9,0x9bd8,0xabbb,0xbb9a,
                 0x4a75,0x5a54,0x6a37,0x7a16,0x0af1,0x1ad0,0x2ab3,0x3a92,
                 0xfd2e,0xed0f,0xdd6c,0xcd4d,0xbdaa,0xad8b,0x9de8,0x8dc9,
                 0x7c26,0x6c07,0x5c64,0x4c45,0x3ca2,0x2c83,0x1ce0,0x0cc1,
                 0xef1f,0xff3e,0xcf5d,0xdf7c,0xaf9b,0xbfba,0x8fd9,0x9ff8,
                 0x6e17,0x7e36,0x4e55,0x5e74,0x2e93,0x3eb2,0x0ed1,0x1ef0]

// TODO: CRC implementation and verify CRC

var mergeDict = function (dest, src) {
  for (var prop in src) {
    if (src.hasOwnProperty(prop)) {
      dest[prop] = src[prop];
    }
  }
  return dest;
};

function BufferTooShortError (message) {
  this.name = 'BufferTooShortError';
  this.message = message;
  this.stack = (new Error()).stack;
}
BufferTooShortError.prototype = Object.create(Error.prototype);
BufferTooShortError.prototype.constructor = BufferTooShortError;

function BufferCorruptError (message) {
  this.name = 'BufferCorruptError';
  this.message = message;
  this.stack = (new Error()).stack;
}
BufferCorruptError.prototype = Object.create(Error.prototype);
BufferCorruptError.prototype.constructor = BufferCorruptError;

var sbpImports = {
  acquisition: require('./acquisition.js'),
  bootload: require('./bootload.js'),
  ext_events: require('./ext_events.js'),
  file_io: require('./file_io.js'),
  flash: require('./flash.js'),
  logging: require('./logging.js'),
  navigation: require('./navigation.js'),
  observation: require('./observation.js'),
  piksi: require('./piksi.js'),
  settings: require('./settings.js'),
  system: require('./system.js'),
  tracking: require('./tracking.js')
};

var sbpIdTable = Object.keys(sbpImports).reduce(function (prev, key) {
  var curr = sbpImports[key];
  var numericKeysDict = {};
  Object.keys(curr).map(function (key) {
    if (parseInt(key) == key) {
      numericKeysDict[key] = curr[key];
    }
  });
  return mergeDict(prev, numericKeysDict);
}, {});

var sbpMessageTypesTable = Object.keys(sbpImports).reduce(function (prev, key) {
  var curr = sbpImports[key];
  var nonNumericKeysDict = {};
  Object.keys(curr).map(function (key) {
    if (parseInt(key) != key) {
      var messageType = curr[key].prototype.messageType || key;
      nonNumericKeysDict[messageType] = curr[key];
    }
  });
  return mergeDict(prev, nonNumericKeysDict);
}, {});

var parser = new Parser()
  .endianess('little')
  .uint8('preamble')
  .uint16('msg_type')
  .uint16('sender')
  .uint8('length')
  .buffer('payload', { length: 'length' })
  .uint16('crc');

/**
 * CRC16 implementation according to CCITT standards.
 * Based on msg.py implementation.
 */
function crc16 (buf, crc) {
  crc = crc || 0;

  for (var i = 0; i < buf.length; i++) {
    var ch = buf[i];
    crc = ((crc<<8)&0xFFFF) ^ (crc16tab[((crc>>8)&0xFF) ^ (ch&0xFF)]);
    crc &= 0xFFFF;
  }

  return crc;
}

module.exports = {
  preambleByte: SBP_PREAMBLE,
  crc16: crc16,

  sbpIdTable: sbpIdTable,
  sbpMessageTypesTable: sbpMessageTypesTable,

  decode: function decode (msg) {
    var sbp = parser.parse(msg);
    var msgTypeDecoder = sbpIdTable[sbp['msg_type']];

    if (typeof msgTypeDecoder === 'undefined') {
      console.log("Unknown message type: ", sbp['msg_type']);
      return new SBP(sbp);
    }

    return new msgTypeDecoder(sbp);
  },
  /**
   * Look for the beginning of a framed message in a stream, and parse it until the end. Verify
   *  that the CRC matches the message. If the framed message is good, invoke callback. Otherwise throw message away.
   *  Repeats until the stream has ended.
   *
   * Callback will be called with valid framed messages. Will not currently be called with errors.
   *
   * This corresponds to the logic in `framer.py`.
   *
   * @param stream: A Readable stream of bytes.
   * @param callback: a callback function invoked when a framed message is found and decoded in the stream.
   * @returns [parsed SBP object, Buffer]
   */
  dispatch: function dispatch (stream, callback) {
    var offset = 0;
    var streamBuffer = new Buffer(0);

    var getFramedMessage = function () {
      var headerBuf, payloadBuf;
      var preamble, msgType, sender, length, crc;
      var payloadCrc;

      // Find preamble byte
      var preamblePos;
      for (preamblePos = 0; preamblePos < streamBuffer.length; preamblePos++) {
        preamble = streamBuffer.readUInt8(preamblePos);
        if (preamble == SBP_PREAMBLE) {
          break;
        }
      }
      if (preamble != SBP_PREAMBLE) {
        throw new BufferTooShortError();
      }

      // Get msg_type, sender, length next
      if (preamblePos+6 > streamBuffer.length) {
        throw new BufferTooShortError();
      }
      headerBuf = streamBuffer.slice(preamblePos+1, preamblePos+6);
      msgType = streamBuffer.readUInt16LE(preamblePos+1);
      sender = streamBuffer.readUInt16LE(preamblePos+3);
      length = streamBuffer.readUInt8(preamblePos+5);

      // Get full payload
      // First, check payload length + CRC
      if (preamblePos+8+length > streamBuffer.length) {
        throw new BufferTooShortError();
      }
      payloadBuf = streamBuffer.slice(preamblePos+6, preamblePos+6+length);
      payloadCrc = crc16(payloadBuf, crc16(headerBuf));

      // Finally, get and verify CRC
      crc = streamBuffer.readUInt16LE(preamblePos+6+length);

      // Pull out full buffer
      var fullBuffer = streamBuffer.slice(preamblePos, preamblePos+6+length+2);

      // If the CRC looks correct, decode the full payload
      if (crc === payloadCrc) {
        // remove this chunk from the stream buffer
        streamBuffer = streamBuffer.slice(preamblePos+6+length+2);

        return [module.exports.decode(fullBuffer), fullBuffer];
      } else {
        // remove bad preamble from the stream buffer
        streamBuffer = streamBuffer.slice(preamblePos+1);

        throw new BufferCorruptError();
      }
    };

    var processData = function (data) {
      stream.pause();
      try {
        streamBuffer = Buffer.concat([streamBuffer, data]);
        if (streamBuffer.length < 2) {
          return;
        }
        var pair = getFramedMessage();
        var framedMessage = pair[0];
        var fullBuffer = pair[1];

        // If there is data left to process after a successful parse, process again
        if (streamBuffer.length > 0) {
          setTimeout(function () {
            processData(new Buffer(0));
          }, 0);
        }

        callback(null, framedMessage, fullBuffer);
      } catch (e) {
        // If the buffer was corrupt but there's more in the stream, try again immediately
        if (e instanceof BufferCorruptError && streamBuffer.length > 0) {
          setTimeout(function () {
            processData(new Buffer(0));
          }, 0);
        }
      } finally {
        offset = 0;
        stream.resume();
      }
    };

    stream.on('data', processData);
  }
};
