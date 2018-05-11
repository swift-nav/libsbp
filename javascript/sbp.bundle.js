/******/ (function(modules) { // webpackBootstrap
/******/ 	// The module cache
/******/ 	var installedModules = {};
/******/
/******/ 	// The require function
/******/ 	function __webpack_require__(moduleId) {
/******/
/******/ 		// Check if module is in cache
/******/ 		if(installedModules[moduleId]) {
/******/ 			return installedModules[moduleId].exports;
/******/ 		}
/******/ 		// Create a new module (and put it into the cache)
/******/ 		var module = installedModules[moduleId] = {
/******/ 			i: moduleId,
/******/ 			l: false,
/******/ 			exports: {}
/******/ 		};
/******/
/******/ 		// Execute the module function
/******/ 		modules[moduleId].call(module.exports, module, module.exports, __webpack_require__);
/******/
/******/ 		// Flag the module as loaded
/******/ 		module.l = true;
/******/
/******/ 		// Return the exports of the module
/******/ 		return module.exports;
/******/ 	}
/******/
/******/
/******/ 	// expose the modules object (__webpack_modules__)
/******/ 	__webpack_require__.m = modules;
/******/
/******/ 	// expose the module cache
/******/ 	__webpack_require__.c = installedModules;
/******/
/******/ 	// identity function for calling harmony imports with the correct context
/******/ 	__webpack_require__.i = function(value) { return value; };
/******/
/******/ 	// define getter function for harmony exports
/******/ 	__webpack_require__.d = function(exports, name, getter) {
/******/ 		if(!__webpack_require__.o(exports, name)) {
/******/ 			Object.defineProperty(exports, name, {
/******/ 				configurable: false,
/******/ 				enumerable: true,
/******/ 				get: getter
/******/ 			});
/******/ 		}
/******/ 	};
/******/
/******/ 	// getDefaultExport function for compatibility with non-harmony modules
/******/ 	__webpack_require__.n = function(module) {
/******/ 		var getter = module && module.__esModule ?
/******/ 			function getDefault() { return module['default']; } :
/******/ 			function getModuleExports() { return module; };
/******/ 		__webpack_require__.d(getter, 'a', getter);
/******/ 		return getter;
/******/ 	};
/******/
/******/ 	// Object.prototype.hasOwnProperty.call
/******/ 	__webpack_require__.o = function(object, property) { return Object.prototype.hasOwnProperty.call(object, property); };
/******/
/******/ 	// __webpack_public_path__
/******/ 	__webpack_require__.p = "";
/******/
/******/ 	// Load entry module and return exports
/******/ 	return __webpack_require__(__webpack_require__.s = 46);
/******/ })
/************************************************************************/
/******/ ([
/* 0 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/gnss.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Various structs shared between modules
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;

/**
 * SBP class for message fragment GnssSignal
 *
 * Signal identifier containing constellation, band, and satellite identifier
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sat number (unsigned 8-bit int, 1 byte) Constellation-specific satellite identifier. This field for Glonass can   either
 *   be (100+FCN) where FCN is in [-7,+6] or  the Slot ID in [1,28]
 * @field code number (unsigned 8-bit int, 1 byte) Signal constellation, band and code
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var GnssSignal = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "GnssSignal";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
GnssSignal.prototype = Object.create(SBP.prototype);
GnssSignal.prototype.messageType = "GnssSignal";
GnssSignal.prototype.constructor = GnssSignal;
GnssSignal.prototype.parser = new Parser()
  .endianess('little')
  .uint8('sat')
  .uint8('code');
GnssSignal.prototype.fieldSpec = [];
GnssSignal.prototype.fieldSpec.push(['sat', 'writeUInt8', 1]);
GnssSignal.prototype.fieldSpec.push(['code', 'writeUInt8', 1]);

/**
 * SBP class for message fragment GnssSignalDep
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sat number (unsigned 16-bit int, 2 bytes) Constellation-specific satellite identifier.  Note: unlike GnssSignal, GPS
 *   satellites are encoded as (PRN - 1). Other constellations do not have this
 *   offset.
 * @field code number (unsigned 8-bit int, 1 byte) Signal constellation, band and code
 * @field reserved number (unsigned 8-bit int, 1 byte) Reserved
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var GnssSignalDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "GnssSignalDep";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
GnssSignalDep.prototype = Object.create(SBP.prototype);
GnssSignalDep.prototype.messageType = "GnssSignalDep";
GnssSignalDep.prototype.constructor = GnssSignalDep;
GnssSignalDep.prototype.parser = new Parser()
  .endianess('little')
  .uint16('sat')
  .uint8('code')
  .uint8('reserved');
GnssSignalDep.prototype.fieldSpec = [];
GnssSignalDep.prototype.fieldSpec.push(['sat', 'writeUInt16LE', 2]);
GnssSignalDep.prototype.fieldSpec.push(['code', 'writeUInt8', 1]);
GnssSignalDep.prototype.fieldSpec.push(['reserved', 'writeUInt8', 1]);

/**
 * SBP class for message fragment GPSTimeDep
 *
 * A wire-appropriate GPS time, defined as the number of milliseconds since
 * beginning of the week on the Saturday/Sunday transition.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) Milliseconds since start of GPS week
 * @field wn number (unsigned 16-bit int, 2 bytes) GPS week number
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var GPSTimeDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "GPSTimeDep";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
GPSTimeDep.prototype = Object.create(SBP.prototype);
GPSTimeDep.prototype.messageType = "GPSTimeDep";
GPSTimeDep.prototype.constructor = GPSTimeDep;
GPSTimeDep.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint16('wn');
GPSTimeDep.prototype.fieldSpec = [];
GPSTimeDep.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
GPSTimeDep.prototype.fieldSpec.push(['wn', 'writeUInt16LE', 2]);

/**
 * SBP class for message fragment GPSTimeSec
 *
 * A GPS time, defined as the number of seconds since beginning of the week on the
 * Saturday/Sunday transition.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) Seconds since start of GPS week
 * @field wn number (unsigned 16-bit int, 2 bytes) GPS week number
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var GPSTimeSec = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "GPSTimeSec";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
GPSTimeSec.prototype = Object.create(SBP.prototype);
GPSTimeSec.prototype.messageType = "GPSTimeSec";
GPSTimeSec.prototype.constructor = GPSTimeSec;
GPSTimeSec.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint16('wn');
GPSTimeSec.prototype.fieldSpec = [];
GPSTimeSec.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
GPSTimeSec.prototype.fieldSpec.push(['wn', 'writeUInt16LE', 2]);

/**
 * SBP class for message fragment GPSTime
 *
 * A wire-appropriate receiver clock time, defined as the time since the beginning
 * of the week on the Saturday/Sunday transition. In most cases, observations are
 * epoch aligned so ns field will be 0.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) Milliseconds since start of GPS week
 * @field ns_residual number (signed 32-bit int, 4 bytes) Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000)
 * @field wn number (unsigned 16-bit int, 2 bytes) GPS week number
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var GPSTime = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "GPSTime";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
GPSTime.prototype = Object.create(SBP.prototype);
GPSTime.prototype.messageType = "GPSTime";
GPSTime.prototype.constructor = GPSTime;
GPSTime.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('ns_residual')
  .uint16('wn');
GPSTime.prototype.fieldSpec = [];
GPSTime.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
GPSTime.prototype.fieldSpec.push(['ns_residual', 'writeInt32LE', 4]);
GPSTime.prototype.fieldSpec.push(['wn', 'writeUInt16LE', 2]);

/**
 * SBP class for message fragment CarrierPhase
 *
 * Carrier phase measurement in cycles represented as a 40-bit fixed point number
 * with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of fractional cycles.
 * This phase has the same sign as the pseudorange.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field i number (signed 32-bit int, 4 bytes) Carrier phase whole cycles
 * @field f number (unsigned 8-bit int, 1 byte) Carrier phase fractional part
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var CarrierPhase = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "CarrierPhase";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
CarrierPhase.prototype = Object.create(SBP.prototype);
CarrierPhase.prototype.messageType = "CarrierPhase";
CarrierPhase.prototype.constructor = CarrierPhase;
CarrierPhase.prototype.parser = new Parser()
  .endianess('little')
  .int32('i')
  .uint8('f');
CarrierPhase.prototype.fieldSpec = [];
CarrierPhase.prototype.fieldSpec.push(['i', 'writeInt32LE', 4]);
CarrierPhase.prototype.fieldSpec.push(['f', 'writeUInt8', 1]);

module.exports = {
  GnssSignal: GnssSignal,
  GnssSignalDep: GnssSignalDep,
  GPSTimeDep: GPSTimeDep,
  GPSTimeSec: GPSTimeSec,
  GPSTime: GPSTime,
  CarrierPhase: CarrierPhase,
}

/***/ }),
/* 1 */
/***/ (function(module, exports, __webpack_require__) {

exports.UINT32 = __webpack_require__(50)
exports.UINT64 = __webpack_require__(51)

/***/ }),
/* 2 */
/***/ (function(module, exports, __webpack_require__) {

/* WEBPACK VAR INJECTION */(function(Buffer) {/**
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Joshua Gross <josh@swift-nav.com>
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

var assert = __webpack_require__(47);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;

var mkBuf = function (size, writer, payload, offset) {
  var b = new Buffer(size);
  b[writer](payload, offset || 0);
  return b;
}

/**
 * Augment UInt64's prototype - it should have toJSON
 */
UInt64.prototype.toJSON = function () {
  return this.toString();
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
      if (dataType === 'writeUInt64LE') {
        assert(data[fieldName] instanceof UInt64, 'uint64 type must be represented by cuint.UINT64');
        var high = data[fieldName].clone().shiftRight(32).and(new UInt64(0xffffffff, 0)).toNumber();
        var low = data[fieldName].clone().and(new UInt64(0xffffffff, 0)).toNumber();
        var b = new Buffer(8);
        b.writeUInt32LE(low);
        b.writeUInt32LE(high, 4);
        buffers.push(b);
      } else {
        var b = new Buffer(dataSize);
        b[dataType](data[fieldName], 0);
        buffers.push(b);
      }
    } else if (dataType === 'string') {
      var b = new Buffer(data[fieldName].length);
      b.write(data[fieldName], 0, 'utf8');
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

  return dict;
};

/**
 * Serialize a message into base64. Note that this will convert the entire
 *  message - SBP fields and payload/fields, not just the payload.
 */
SBP.prototype.toBase64 = function toBase64 () {
  return this.toBuffer().toString('base64');
};

module.exports = SBP;

/* WEBPACK VAR INJECTION */}.call(exports, __webpack_require__(7).Buffer))

/***/ }),
/* 3 */
/***/ (function(module, exports, __webpack_require__) {

/* WEBPACK VAR INJECTION */(function(Buffer) {//     Int64.js
//
//     Copyright (c) 2012 Robert Kieffer
//     MIT License - http://opensource.org/licenses/mit-license.php

/**
 * Support for handling 64-bit int numbers in Javascript (node.js)
 *
 * JS Numbers are IEEE-754 binary double-precision floats, which limits the
 * range of values that can be represented with integer precision to:
 *
 * 2^^53 <= N <= 2^53
 *
 * Int64 objects wrap a node Buffer that holds the 8-bytes of int64 data.  These
 * objects operate directly on the buffer which means that if they are created
 * using an existing buffer then setting the value will modify the Buffer, and
 * vice-versa.
 *
 * Internal Representation
 *
 * The internal buffer format is Big Endian.  I.e. the most-significant byte is
 * at buffer[0], the least-significant at buffer[7].  For the purposes of
 * converting to/from JS native numbers, the value is assumed to be a signed
 * integer stored in 2's complement form.
 *
 * For details about IEEE-754 see:
 * http://en.wikipedia.org/wiki/Double_precision_floating-point_format
 */

// Useful masks and values for bit twiddling
var MASK31 =  0x7fffffff, VAL31 = 0x80000000;
var MASK32 =  0xffffffff, VAL32 = 0x100000000;

// Map for converting hex octets to strings
var _HEX = [];
for (var i = 0; i < 256; i++) {
  _HEX[i] = (i > 0xF ? '' : '0') + i.toString(16);
}

//
// Int64
//

/**
 * Constructor accepts any of the following argument types:
 *
 * new Int64(buffer[, offset=0]) - Existing Buffer with byte offset
 * new Int64(Uint8Array[, offset=0]) - Existing Uint8Array with a byte offset
 * new Int64(string)             - Hex string (throws if n is outside int64 range)
 * new Int64(number)             - Number (throws if n is outside int64 range)
 * new Int64(hi, lo)             - Raw bits as two 32-bit values
 */
var Int64 = module.exports = function(a1, a2) {
  if (a1 instanceof Buffer) {
    this.buffer = a1;
    this.offset = a2 || 0;
  } else if (Object.prototype.toString.call(a1) == '[object Uint8Array]') {
    // Under Browserify, Buffers can extend Uint8Arrays rather than an
    // instance of Buffer. We could assume the passed in Uint8Array is actually
    // a buffer but that won't handle the case where a raw Uint8Array is passed
    // in. We construct a new Buffer just in case.
    this.buffer = new Buffer(a1);
    this.offset = a2 || 0;
  } else {
    this.buffer = this.buffer || new Buffer(8);
    this.offset = 0;
    this.setValue.apply(this, arguments);
  }
};


// Max integer value that JS can accurately represent
Int64.MAX_INT = Math.pow(2, 53);

// Min integer value that JS can accurately represent
Int64.MIN_INT = -Math.pow(2, 53);

Int64.prototype = {

  constructor: Int64,

  /**
   * Do in-place 2's compliment.  See
   * http://en.wikipedia.org/wiki/Two's_complement
   */
  _2scomp: function() {
    var b = this.buffer, o = this.offset, carry = 1;
    for (var i = o + 7; i >= o; i--) {
      var v = (b[i] ^ 0xff) + carry;
      b[i] = v & 0xff;
      carry = v >> 8;
    }
  },

  /**
   * Set the value. Takes any of the following arguments:
   *
   * setValue(string) - A hexidecimal string
   * setValue(number) - Number (throws if n is outside int64 range)
   * setValue(hi, lo) - Raw bits as two 32-bit values
   */
  setValue: function(hi, lo) {
    var negate = false;
    if (arguments.length == 1) {
      if (typeof(hi) == 'number') {
        // Simplify bitfield retrieval by using abs() value.  We restore sign
        // later
        negate = hi < 0;
        hi = Math.abs(hi);
        lo = hi % VAL32;
        hi = hi / VAL32;
        if (hi > VAL32) throw new RangeError(hi  + ' is outside Int64 range');
        hi = hi | 0;
      } else if (typeof(hi) == 'string') {
        hi = (hi + '').replace(/^0x/, '');
        lo = hi.substr(-8);
        hi = hi.length > 8 ? hi.substr(0, hi.length - 8) : '';
        hi = parseInt(hi, 16);
        lo = parseInt(lo, 16);
      } else {
        throw new Error(hi + ' must be a Number or String');
      }
    }

    // Technically we should throw if hi or lo is outside int32 range here, but
    // it's not worth the effort. Anything past the 32'nd bit is ignored.

    // Copy bytes to buffer
    var b = this.buffer, o = this.offset;
    for (var i = 7; i >= 0; i--) {
      b[o+i] = lo & 0xff;
      lo = i == 4 ? hi : lo >>> 8;
    }

    // Restore sign of passed argument
    if (negate) this._2scomp();
  },

  /**
   * Convert to a native JS number.
   *
   * WARNING: Do not expect this value to be accurate to integer precision for
   * large (positive or negative) numbers!
   *
   * @param allowImprecise If true, no check is performed to verify the
   * returned value is accurate to integer precision.  If false, imprecise
   * numbers (very large positive or negative numbers) will be forced to +/-
   * Infinity.
   */
  toNumber: function(allowImprecise) {
    var b = this.buffer, o = this.offset;

    // Running sum of octets, doing a 2's complement
    var negate = b[o] & 0x80, x = 0, carry = 1;
    for (var i = 7, m = 1; i >= 0; i--, m *= 256) {
      var v = b[o+i];

      // 2's complement for negative numbers
      if (negate) {
        v = (v ^ 0xff) + carry;
        carry = v >> 8;
        v = v & 0xff;
      }

      x += v * m;
    }

    // Return Infinity if we've lost integer precision
    if (!allowImprecise && x >= Int64.MAX_INT) {
      return negate ? -Infinity : Infinity;
    }

    return negate ? -x : x;
  },

  /**
   * Convert to a JS Number. Returns +/-Infinity for values that can't be
   * represented to integer precision.
   */
  valueOf: function() {
    return this.toNumber(false);
  },

  /**
   * Return string value
   *
   * @param radix Just like Number#toString()'s radix
   */
  toString: function(radix) {
    return this.valueOf().toString(radix || 10);
  },

  /**
   * Return a string showing the buffer octets, with MSB on the left.
   *
   * @param sep separator string. default is '' (empty string)
   */
  toOctetString: function(sep) {
    var out = new Array(8);
    var b = this.buffer, o = this.offset;
    for (var i = 0; i < 8; i++) {
      out[i] = _HEX[b[o+i]];
    }
    return out.join(sep || '');
  },

  /**
   * Returns the int64's 8 bytes in a buffer.
   *
   * @param {bool} [rawBuffer=false]  If no offset and this is true, return the internal buffer.  Should only be used if
   *                                  you're discarding the Int64 afterwards, as it breaks encapsulation.
   */
  toBuffer: function(rawBuffer) {
    if (rawBuffer && this.offset === 0) return this.buffer;

    var out = new Buffer(8);
    this.buffer.copy(out, 0, this.offset, this.offset + 8);
    return out;
  },

  /**
   * Copy 8 bytes of int64 into target buffer at target offset.
   *
   * @param {Buffer} targetBuffer       Buffer to copy into.
   * @param {number} [targetOffset=0]   Offset into target buffer.
   */
  copy: function(targetBuffer, targetOffset) {
    this.buffer.copy(targetBuffer, targetOffset || 0, this.offset, this.offset + 8);
  },

  /**
   * Returns a number indicating whether this comes before or after or is the
   * same as the other in sort order.
   *
   * @param {Int64} other  Other Int64 to compare.
   */
  compare: function(other) {

    // If sign bits differ ...
    if ((this.buffer[this.offset] & 0x80) != (other.buffer[other.offset] & 0x80)) {
      return other.buffer[other.offset] - this.buffer[this.offset];
    }

    // otherwise, compare bytes lexicographically
    for (var i = 0; i < 8; i++) {
      if (this.buffer[this.offset+i] !== other.buffer[other.offset+i]) {
        return this.buffer[this.offset+i] - other.buffer[other.offset+i];
      }
    }
    return 0;
  },

  /**
   * Returns a boolean indicating if this integer is equal to other.
   *
   * @param {Int64} other  Other Int64 to compare.
   */
  equals: function(other) {
    return this.compare(other) === 0;
  },

  /**
   * Pretty output in console.log
   */
  inspect: function() {
    return '[Int64 value:' + this + ' octets:' + this.toOctetString(' ') + ']';
  }
};

/* WEBPACK VAR INJECTION */}.call(exports, __webpack_require__(7).Buffer))

/***/ }),
/* 4 */
/***/ (function(module, exports, __webpack_require__) {

/* WEBPACK VAR INJECTION */(function(Buffer) {/**
 * Copyright (C) 2016 Swift Navigation Inc.
 * Contact: Joshua Gross <josh@swift-nav.com>
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

var Parser = __webpack_require__(13).Parser;

/**
 * Add `uint64` to Parser prototype.
 */
Parser.prototype.uint64 = function uint64 (fieldName, options) {
  return this.setNextParser('uint64', fieldName, Object.assign({}, options, {
    formatter: function (recv_time) {
      var UInt64 = __webpack_require__(1).UINT64;
      var low = buffer.readUInt32LE(offset);
      offset += 4;
      var high = buffer.readUInt32LE(offset);
      offset += 4;
      return new UInt64(low, high);
    }
  }));
}

/**
 * Replace the original compile function to pass in `require` (???)
 */
Parser.prototype.compile = function() {
  var compiledCode = this.getCode();
  this.compiled = function (buffer, callback, constructorFn) {
    // Need to statically provide dependencies for webpack.
    var _require = function (x) { if (x === 'cuint') return __webpack_require__(1); throw new Error('Unknown module required: ' + x); };

    // Needed for browser support. Webpack will polyfill Buffer, but we need it to
    // be accessible in this eval'd context.
    if (typeof window !== 'undefined' && typeof window.Buffer === 'undefined') window.Buffer = Buffer;

    return (new Function('buffer', 'callback', 'constructorFn', 'require', compiledCode)).call(this, buffer, callback, constructorFn, _require);
  };
};

module.exports = Parser;

/* WEBPACK VAR INJECTION */}.call(exports, __webpack_require__(7).Buffer))

/***/ }),
/* 5 */
/***/ (function(module, exports) {

var g;

// This works in non-strict mode
g = (function() {
	return this;
})();

try {
	// This works if eval is allowed (see CSP)
	g = g || Function("return this")() || (1,eval)("this");
} catch(e) {
	// This works if the window reference is available
	if(typeof window === "object")
		g = window;
}

// g can still be undefined, but nothing to do about it...
// We return undefined, instead of nothing here, so it's
// easier to handle this case. if(!global) { ...}

module.exports = g;


/***/ }),
/* 6 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
// Copyright Joyent, Inc. and other Node contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.

// a duplex stream is just a stream that is both readable and writable.
// Since JS doesn't have multiple prototypal inheritance, this class
// prototypally inherits from Readable, and then parasitically from
// Writable.



/*<replacement>*/

var pna = __webpack_require__(11);
/*</replacement>*/

/*<replacement>*/
var objectKeys = Object.keys || function (obj) {
  var keys = [];
  for (var key in obj) {
    keys.push(key);
  }return keys;
};
/*</replacement>*/

module.exports = Duplex;

/*<replacement>*/
var util = __webpack_require__(10);
util.inherits = __webpack_require__(8);
/*</replacement>*/

var Readable = __webpack_require__(18);
var Writable = __webpack_require__(15);

util.inherits(Duplex, Readable);

{
  // avoid scope creep, the keys array can then be collected
  var keys = objectKeys(Writable.prototype);
  for (var v = 0; v < keys.length; v++) {
    var method = keys[v];
    if (!Duplex.prototype[method]) Duplex.prototype[method] = Writable.prototype[method];
  }
}

function Duplex(options) {
  if (!(this instanceof Duplex)) return new Duplex(options);

  Readable.call(this, options);
  Writable.call(this, options);

  if (options && options.readable === false) this.readable = false;

  if (options && options.writable === false) this.writable = false;

  this.allowHalfOpen = true;
  if (options && options.allowHalfOpen === false) this.allowHalfOpen = false;

  this.once('end', onend);
}

Object.defineProperty(Duplex.prototype, 'writableHighWaterMark', {
  // making it explicit this property is not enumerable
  // because otherwise some prototype manipulation in
  // userland will fail
  enumerable: false,
  get: function () {
    return this._writableState.highWaterMark;
  }
});

// the no-half-open enforcer
function onend() {
  // if we allow half-open state, or if the writable side ended,
  // then we're ok.
  if (this.allowHalfOpen || this._writableState.ended) return;

  // no more data can be written.
  // But allow more writes to happen in this tick.
  pna.nextTick(onEndNT, this);
}

function onEndNT(self) {
  self.end();
}

Object.defineProperty(Duplex.prototype, 'destroyed', {
  get: function () {
    if (this._readableState === undefined || this._writableState === undefined) {
      return false;
    }
    return this._readableState.destroyed && this._writableState.destroyed;
  },
  set: function (value) {
    // we ignore the value if the stream
    // has not been initialized yet
    if (this._readableState === undefined || this._writableState === undefined) {
      return;
    }

    // backward compatibility, the user is explicitly
    // managing destroyed
    this._readableState.destroyed = value;
    this._writableState.destroyed = value;
  }
});

Duplex.prototype._destroy = function (err, cb) {
  this.push(null);
  this.end();

  pna.nextTick(cb, err);
};

/***/ }),
/* 7 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/* WEBPACK VAR INJECTION */(function(global) {/*!
 * The buffer module from node.js, for the browser.
 *
 * @author   Feross Aboukhadijeh <feross@feross.org> <http://feross.org>
 * @license  MIT
 */
/* eslint-disable no-proto */



var base64 = __webpack_require__(48)
var ieee754 = __webpack_require__(52)
var isArray = __webpack_require__(17)

exports.Buffer = Buffer
exports.SlowBuffer = SlowBuffer
exports.INSPECT_MAX_BYTES = 50

/**
 * If `Buffer.TYPED_ARRAY_SUPPORT`:
 *   === true    Use Uint8Array implementation (fastest)
 *   === false   Use Object implementation (most compatible, even IE6)
 *
 * Browsers that support typed arrays are IE 10+, Firefox 4+, Chrome 7+, Safari 5.1+,
 * Opera 11.6+, iOS 4.2+.
 *
 * Due to various browser bugs, sometimes the Object implementation will be used even
 * when the browser supports typed arrays.
 *
 * Note:
 *
 *   - Firefox 4-29 lacks support for adding new properties to `Uint8Array` instances,
 *     See: https://bugzilla.mozilla.org/show_bug.cgi?id=695438.
 *
 *   - Chrome 9-10 is missing the `TypedArray.prototype.subarray` function.
 *
 *   - IE10 has a broken `TypedArray.prototype.subarray` function which returns arrays of
 *     incorrect length in some situations.

 * We detect these buggy browsers and set `Buffer.TYPED_ARRAY_SUPPORT` to `false` so they
 * get the Object implementation, which is slower but behaves correctly.
 */
Buffer.TYPED_ARRAY_SUPPORT = global.TYPED_ARRAY_SUPPORT !== undefined
  ? global.TYPED_ARRAY_SUPPORT
  : typedArraySupport()

/*
 * Export kMaxLength after typed array support is determined.
 */
exports.kMaxLength = kMaxLength()

function typedArraySupport () {
  try {
    var arr = new Uint8Array(1)
    arr.__proto__ = {__proto__: Uint8Array.prototype, foo: function () { return 42 }}
    return arr.foo() === 42 && // typed array instances can be augmented
        typeof arr.subarray === 'function' && // chrome 9-10 lack `subarray`
        arr.subarray(1, 1).byteLength === 0 // ie10 has broken `subarray`
  } catch (e) {
    return false
  }
}

function kMaxLength () {
  return Buffer.TYPED_ARRAY_SUPPORT
    ? 0x7fffffff
    : 0x3fffffff
}

function createBuffer (that, length) {
  if (kMaxLength() < length) {
    throw new RangeError('Invalid typed array length')
  }
  if (Buffer.TYPED_ARRAY_SUPPORT) {
    // Return an augmented `Uint8Array` instance, for best performance
    that = new Uint8Array(length)
    that.__proto__ = Buffer.prototype
  } else {
    // Fallback: Return an object instance of the Buffer class
    if (that === null) {
      that = new Buffer(length)
    }
    that.length = length
  }

  return that
}

/**
 * The Buffer constructor returns instances of `Uint8Array` that have their
 * prototype changed to `Buffer.prototype`. Furthermore, `Buffer` is a subclass of
 * `Uint8Array`, so the returned instances will have all the node `Buffer` methods
 * and the `Uint8Array` methods. Square bracket notation works as expected -- it
 * returns a single octet.
 *
 * The `Uint8Array` prototype remains unmodified.
 */

function Buffer (arg, encodingOrOffset, length) {
  if (!Buffer.TYPED_ARRAY_SUPPORT && !(this instanceof Buffer)) {
    return new Buffer(arg, encodingOrOffset, length)
  }

  // Common case.
  if (typeof arg === 'number') {
    if (typeof encodingOrOffset === 'string') {
      throw new Error(
        'If encoding is specified then the first argument must be a string'
      )
    }
    return allocUnsafe(this, arg)
  }
  return from(this, arg, encodingOrOffset, length)
}

Buffer.poolSize = 8192 // not used by this implementation

// TODO: Legacy, not needed anymore. Remove in next major version.
Buffer._augment = function (arr) {
  arr.__proto__ = Buffer.prototype
  return arr
}

function from (that, value, encodingOrOffset, length) {
  if (typeof value === 'number') {
    throw new TypeError('"value" argument must not be a number')
  }

  if (typeof ArrayBuffer !== 'undefined' && value instanceof ArrayBuffer) {
    return fromArrayBuffer(that, value, encodingOrOffset, length)
  }

  if (typeof value === 'string') {
    return fromString(that, value, encodingOrOffset)
  }

  return fromObject(that, value)
}

/**
 * Functionally equivalent to Buffer(arg, encoding) but throws a TypeError
 * if value is a number.
 * Buffer.from(str[, encoding])
 * Buffer.from(array)
 * Buffer.from(buffer)
 * Buffer.from(arrayBuffer[, byteOffset[, length]])
 **/
Buffer.from = function (value, encodingOrOffset, length) {
  return from(null, value, encodingOrOffset, length)
}

if (Buffer.TYPED_ARRAY_SUPPORT) {
  Buffer.prototype.__proto__ = Uint8Array.prototype
  Buffer.__proto__ = Uint8Array
  if (typeof Symbol !== 'undefined' && Symbol.species &&
      Buffer[Symbol.species] === Buffer) {
    // Fix subarray() in ES2016. See: https://github.com/feross/buffer/pull/97
    Object.defineProperty(Buffer, Symbol.species, {
      value: null,
      configurable: true
    })
  }
}

function assertSize (size) {
  if (typeof size !== 'number') {
    throw new TypeError('"size" argument must be a number')
  } else if (size < 0) {
    throw new RangeError('"size" argument must not be negative')
  }
}

function alloc (that, size, fill, encoding) {
  assertSize(size)
  if (size <= 0) {
    return createBuffer(that, size)
  }
  if (fill !== undefined) {
    // Only pay attention to encoding if it's a string. This
    // prevents accidentally sending in a number that would
    // be interpretted as a start offset.
    return typeof encoding === 'string'
      ? createBuffer(that, size).fill(fill, encoding)
      : createBuffer(that, size).fill(fill)
  }
  return createBuffer(that, size)
}

/**
 * Creates a new filled Buffer instance.
 * alloc(size[, fill[, encoding]])
 **/
Buffer.alloc = function (size, fill, encoding) {
  return alloc(null, size, fill, encoding)
}

function allocUnsafe (that, size) {
  assertSize(size)
  that = createBuffer(that, size < 0 ? 0 : checked(size) | 0)
  if (!Buffer.TYPED_ARRAY_SUPPORT) {
    for (var i = 0; i < size; ++i) {
      that[i] = 0
    }
  }
  return that
}

/**
 * Equivalent to Buffer(num), by default creates a non-zero-filled Buffer instance.
 * */
Buffer.allocUnsafe = function (size) {
  return allocUnsafe(null, size)
}
/**
 * Equivalent to SlowBuffer(num), by default creates a non-zero-filled Buffer instance.
 */
Buffer.allocUnsafeSlow = function (size) {
  return allocUnsafe(null, size)
}

function fromString (that, string, encoding) {
  if (typeof encoding !== 'string' || encoding === '') {
    encoding = 'utf8'
  }

  if (!Buffer.isEncoding(encoding)) {
    throw new TypeError('"encoding" must be a valid string encoding')
  }

  var length = byteLength(string, encoding) | 0
  that = createBuffer(that, length)

  var actual = that.write(string, encoding)

  if (actual !== length) {
    // Writing a hex string, for example, that contains invalid characters will
    // cause everything after the first invalid character to be ignored. (e.g.
    // 'abxxcd' will be treated as 'ab')
    that = that.slice(0, actual)
  }

  return that
}

function fromArrayLike (that, array) {
  var length = array.length < 0 ? 0 : checked(array.length) | 0
  that = createBuffer(that, length)
  for (var i = 0; i < length; i += 1) {
    that[i] = array[i] & 255
  }
  return that
}

function fromArrayBuffer (that, array, byteOffset, length) {
  array.byteLength // this throws if `array` is not a valid ArrayBuffer

  if (byteOffset < 0 || array.byteLength < byteOffset) {
    throw new RangeError('\'offset\' is out of bounds')
  }

  if (array.byteLength < byteOffset + (length || 0)) {
    throw new RangeError('\'length\' is out of bounds')
  }

  if (byteOffset === undefined && length === undefined) {
    array = new Uint8Array(array)
  } else if (length === undefined) {
    array = new Uint8Array(array, byteOffset)
  } else {
    array = new Uint8Array(array, byteOffset, length)
  }

  if (Buffer.TYPED_ARRAY_SUPPORT) {
    // Return an augmented `Uint8Array` instance, for best performance
    that = array
    that.__proto__ = Buffer.prototype
  } else {
    // Fallback: Return an object instance of the Buffer class
    that = fromArrayLike(that, array)
  }
  return that
}

function fromObject (that, obj) {
  if (Buffer.isBuffer(obj)) {
    var len = checked(obj.length) | 0
    that = createBuffer(that, len)

    if (that.length === 0) {
      return that
    }

    obj.copy(that, 0, 0, len)
    return that
  }

  if (obj) {
    if ((typeof ArrayBuffer !== 'undefined' &&
        obj.buffer instanceof ArrayBuffer) || 'length' in obj) {
      if (typeof obj.length !== 'number' || isnan(obj.length)) {
        return createBuffer(that, 0)
      }
      return fromArrayLike(that, obj)
    }

    if (obj.type === 'Buffer' && isArray(obj.data)) {
      return fromArrayLike(that, obj.data)
    }
  }

  throw new TypeError('First argument must be a string, Buffer, ArrayBuffer, Array, or array-like object.')
}

function checked (length) {
  // Note: cannot use `length < kMaxLength()` here because that fails when
  // length is NaN (which is otherwise coerced to zero.)
  if (length >= kMaxLength()) {
    throw new RangeError('Attempt to allocate Buffer larger than maximum ' +
                         'size: 0x' + kMaxLength().toString(16) + ' bytes')
  }
  return length | 0
}

function SlowBuffer (length) {
  if (+length != length) { // eslint-disable-line eqeqeq
    length = 0
  }
  return Buffer.alloc(+length)
}

Buffer.isBuffer = function isBuffer (b) {
  return !!(b != null && b._isBuffer)
}

Buffer.compare = function compare (a, b) {
  if (!Buffer.isBuffer(a) || !Buffer.isBuffer(b)) {
    throw new TypeError('Arguments must be Buffers')
  }

  if (a === b) return 0

  var x = a.length
  var y = b.length

  for (var i = 0, len = Math.min(x, y); i < len; ++i) {
    if (a[i] !== b[i]) {
      x = a[i]
      y = b[i]
      break
    }
  }

  if (x < y) return -1
  if (y < x) return 1
  return 0
}

Buffer.isEncoding = function isEncoding (encoding) {
  switch (String(encoding).toLowerCase()) {
    case 'hex':
    case 'utf8':
    case 'utf-8':
    case 'ascii':
    case 'latin1':
    case 'binary':
    case 'base64':
    case 'ucs2':
    case 'ucs-2':
    case 'utf16le':
    case 'utf-16le':
      return true
    default:
      return false
  }
}

Buffer.concat = function concat (list, length) {
  if (!isArray(list)) {
    throw new TypeError('"list" argument must be an Array of Buffers')
  }

  if (list.length === 0) {
    return Buffer.alloc(0)
  }

  var i
  if (length === undefined) {
    length = 0
    for (i = 0; i < list.length; ++i) {
      length += list[i].length
    }
  }

  var buffer = Buffer.allocUnsafe(length)
  var pos = 0
  for (i = 0; i < list.length; ++i) {
    var buf = list[i]
    if (!Buffer.isBuffer(buf)) {
      throw new TypeError('"list" argument must be an Array of Buffers')
    }
    buf.copy(buffer, pos)
    pos += buf.length
  }
  return buffer
}

function byteLength (string, encoding) {
  if (Buffer.isBuffer(string)) {
    return string.length
  }
  if (typeof ArrayBuffer !== 'undefined' && typeof ArrayBuffer.isView === 'function' &&
      (ArrayBuffer.isView(string) || string instanceof ArrayBuffer)) {
    return string.byteLength
  }
  if (typeof string !== 'string') {
    string = '' + string
  }

  var len = string.length
  if (len === 0) return 0

  // Use a for loop to avoid recursion
  var loweredCase = false
  for (;;) {
    switch (encoding) {
      case 'ascii':
      case 'latin1':
      case 'binary':
        return len
      case 'utf8':
      case 'utf-8':
      case undefined:
        return utf8ToBytes(string).length
      case 'ucs2':
      case 'ucs-2':
      case 'utf16le':
      case 'utf-16le':
        return len * 2
      case 'hex':
        return len >>> 1
      case 'base64':
        return base64ToBytes(string).length
      default:
        if (loweredCase) return utf8ToBytes(string).length // assume utf8
        encoding = ('' + encoding).toLowerCase()
        loweredCase = true
    }
  }
}
Buffer.byteLength = byteLength

function slowToString (encoding, start, end) {
  var loweredCase = false

  // No need to verify that "this.length <= MAX_UINT32" since it's a read-only
  // property of a typed array.

  // This behaves neither like String nor Uint8Array in that we set start/end
  // to their upper/lower bounds if the value passed is out of range.
  // undefined is handled specially as per ECMA-262 6th Edition,
  // Section 13.3.3.7 Runtime Semantics: KeyedBindingInitialization.
  if (start === undefined || start < 0) {
    start = 0
  }
  // Return early if start > this.length. Done here to prevent potential uint32
  // coercion fail below.
  if (start > this.length) {
    return ''
  }

  if (end === undefined || end > this.length) {
    end = this.length
  }

  if (end <= 0) {
    return ''
  }

  // Force coersion to uint32. This will also coerce falsey/NaN values to 0.
  end >>>= 0
  start >>>= 0

  if (end <= start) {
    return ''
  }

  if (!encoding) encoding = 'utf8'

  while (true) {
    switch (encoding) {
      case 'hex':
        return hexSlice(this, start, end)

      case 'utf8':
      case 'utf-8':
        return utf8Slice(this, start, end)

      case 'ascii':
        return asciiSlice(this, start, end)

      case 'latin1':
      case 'binary':
        return latin1Slice(this, start, end)

      case 'base64':
        return base64Slice(this, start, end)

      case 'ucs2':
      case 'ucs-2':
      case 'utf16le':
      case 'utf-16le':
        return utf16leSlice(this, start, end)

      default:
        if (loweredCase) throw new TypeError('Unknown encoding: ' + encoding)
        encoding = (encoding + '').toLowerCase()
        loweredCase = true
    }
  }
}

// The property is used by `Buffer.isBuffer` and `is-buffer` (in Safari 5-7) to detect
// Buffer instances.
Buffer.prototype._isBuffer = true

function swap (b, n, m) {
  var i = b[n]
  b[n] = b[m]
  b[m] = i
}

Buffer.prototype.swap16 = function swap16 () {
  var len = this.length
  if (len % 2 !== 0) {
    throw new RangeError('Buffer size must be a multiple of 16-bits')
  }
  for (var i = 0; i < len; i += 2) {
    swap(this, i, i + 1)
  }
  return this
}

Buffer.prototype.swap32 = function swap32 () {
  var len = this.length
  if (len % 4 !== 0) {
    throw new RangeError('Buffer size must be a multiple of 32-bits')
  }
  for (var i = 0; i < len; i += 4) {
    swap(this, i, i + 3)
    swap(this, i + 1, i + 2)
  }
  return this
}

Buffer.prototype.swap64 = function swap64 () {
  var len = this.length
  if (len % 8 !== 0) {
    throw new RangeError('Buffer size must be a multiple of 64-bits')
  }
  for (var i = 0; i < len; i += 8) {
    swap(this, i, i + 7)
    swap(this, i + 1, i + 6)
    swap(this, i + 2, i + 5)
    swap(this, i + 3, i + 4)
  }
  return this
}

Buffer.prototype.toString = function toString () {
  var length = this.length | 0
  if (length === 0) return ''
  if (arguments.length === 0) return utf8Slice(this, 0, length)
  return slowToString.apply(this, arguments)
}

Buffer.prototype.equals = function equals (b) {
  if (!Buffer.isBuffer(b)) throw new TypeError('Argument must be a Buffer')
  if (this === b) return true
  return Buffer.compare(this, b) === 0
}

Buffer.prototype.inspect = function inspect () {
  var str = ''
  var max = exports.INSPECT_MAX_BYTES
  if (this.length > 0) {
    str = this.toString('hex', 0, max).match(/.{2}/g).join(' ')
    if (this.length > max) str += ' ... '
  }
  return '<Buffer ' + str + '>'
}

Buffer.prototype.compare = function compare (target, start, end, thisStart, thisEnd) {
  if (!Buffer.isBuffer(target)) {
    throw new TypeError('Argument must be a Buffer')
  }

  if (start === undefined) {
    start = 0
  }
  if (end === undefined) {
    end = target ? target.length : 0
  }
  if (thisStart === undefined) {
    thisStart = 0
  }
  if (thisEnd === undefined) {
    thisEnd = this.length
  }

  if (start < 0 || end > target.length || thisStart < 0 || thisEnd > this.length) {
    throw new RangeError('out of range index')
  }

  if (thisStart >= thisEnd && start >= end) {
    return 0
  }
  if (thisStart >= thisEnd) {
    return -1
  }
  if (start >= end) {
    return 1
  }

  start >>>= 0
  end >>>= 0
  thisStart >>>= 0
  thisEnd >>>= 0

  if (this === target) return 0

  var x = thisEnd - thisStart
  var y = end - start
  var len = Math.min(x, y)

  var thisCopy = this.slice(thisStart, thisEnd)
  var targetCopy = target.slice(start, end)

  for (var i = 0; i < len; ++i) {
    if (thisCopy[i] !== targetCopy[i]) {
      x = thisCopy[i]
      y = targetCopy[i]
      break
    }
  }

  if (x < y) return -1
  if (y < x) return 1
  return 0
}

// Finds either the first index of `val` in `buffer` at offset >= `byteOffset`,
// OR the last index of `val` in `buffer` at offset <= `byteOffset`.
//
// Arguments:
// - buffer - a Buffer to search
// - val - a string, Buffer, or number
// - byteOffset - an index into `buffer`; will be clamped to an int32
// - encoding - an optional encoding, relevant is val is a string
// - dir - true for indexOf, false for lastIndexOf
function bidirectionalIndexOf (buffer, val, byteOffset, encoding, dir) {
  // Empty buffer means no match
  if (buffer.length === 0) return -1

  // Normalize byteOffset
  if (typeof byteOffset === 'string') {
    encoding = byteOffset
    byteOffset = 0
  } else if (byteOffset > 0x7fffffff) {
    byteOffset = 0x7fffffff
  } else if (byteOffset < -0x80000000) {
    byteOffset = -0x80000000
  }
  byteOffset = +byteOffset  // Coerce to Number.
  if (isNaN(byteOffset)) {
    // byteOffset: it it's undefined, null, NaN, "foo", etc, search whole buffer
    byteOffset = dir ? 0 : (buffer.length - 1)
  }

  // Normalize byteOffset: negative offsets start from the end of the buffer
  if (byteOffset < 0) byteOffset = buffer.length + byteOffset
  if (byteOffset >= buffer.length) {
    if (dir) return -1
    else byteOffset = buffer.length - 1
  } else if (byteOffset < 0) {
    if (dir) byteOffset = 0
    else return -1
  }

  // Normalize val
  if (typeof val === 'string') {
    val = Buffer.from(val, encoding)
  }

  // Finally, search either indexOf (if dir is true) or lastIndexOf
  if (Buffer.isBuffer(val)) {
    // Special case: looking for empty string/buffer always fails
    if (val.length === 0) {
      return -1
    }
    return arrayIndexOf(buffer, val, byteOffset, encoding, dir)
  } else if (typeof val === 'number') {
    val = val & 0xFF // Search for a byte value [0-255]
    if (Buffer.TYPED_ARRAY_SUPPORT &&
        typeof Uint8Array.prototype.indexOf === 'function') {
      if (dir) {
        return Uint8Array.prototype.indexOf.call(buffer, val, byteOffset)
      } else {
        return Uint8Array.prototype.lastIndexOf.call(buffer, val, byteOffset)
      }
    }
    return arrayIndexOf(buffer, [ val ], byteOffset, encoding, dir)
  }

  throw new TypeError('val must be string, number or Buffer')
}

function arrayIndexOf (arr, val, byteOffset, encoding, dir) {
  var indexSize = 1
  var arrLength = arr.length
  var valLength = val.length

  if (encoding !== undefined) {
    encoding = String(encoding).toLowerCase()
    if (encoding === 'ucs2' || encoding === 'ucs-2' ||
        encoding === 'utf16le' || encoding === 'utf-16le') {
      if (arr.length < 2 || val.length < 2) {
        return -1
      }
      indexSize = 2
      arrLength /= 2
      valLength /= 2
      byteOffset /= 2
    }
  }

  function read (buf, i) {
    if (indexSize === 1) {
      return buf[i]
    } else {
      return buf.readUInt16BE(i * indexSize)
    }
  }

  var i
  if (dir) {
    var foundIndex = -1
    for (i = byteOffset; i < arrLength; i++) {
      if (read(arr, i) === read(val, foundIndex === -1 ? 0 : i - foundIndex)) {
        if (foundIndex === -1) foundIndex = i
        if (i - foundIndex + 1 === valLength) return foundIndex * indexSize
      } else {
        if (foundIndex !== -1) i -= i - foundIndex
        foundIndex = -1
      }
    }
  } else {
    if (byteOffset + valLength > arrLength) byteOffset = arrLength - valLength
    for (i = byteOffset; i >= 0; i--) {
      var found = true
      for (var j = 0; j < valLength; j++) {
        if (read(arr, i + j) !== read(val, j)) {
          found = false
          break
        }
      }
      if (found) return i
    }
  }

  return -1
}

Buffer.prototype.includes = function includes (val, byteOffset, encoding) {
  return this.indexOf(val, byteOffset, encoding) !== -1
}

Buffer.prototype.indexOf = function indexOf (val, byteOffset, encoding) {
  return bidirectionalIndexOf(this, val, byteOffset, encoding, true)
}

Buffer.prototype.lastIndexOf = function lastIndexOf (val, byteOffset, encoding) {
  return bidirectionalIndexOf(this, val, byteOffset, encoding, false)
}

function hexWrite (buf, string, offset, length) {
  offset = Number(offset) || 0
  var remaining = buf.length - offset
  if (!length) {
    length = remaining
  } else {
    length = Number(length)
    if (length > remaining) {
      length = remaining
    }
  }

  // must be an even number of digits
  var strLen = string.length
  if (strLen % 2 !== 0) throw new TypeError('Invalid hex string')

  if (length > strLen / 2) {
    length = strLen / 2
  }
  for (var i = 0; i < length; ++i) {
    var parsed = parseInt(string.substr(i * 2, 2), 16)
    if (isNaN(parsed)) return i
    buf[offset + i] = parsed
  }
  return i
}

function utf8Write (buf, string, offset, length) {
  return blitBuffer(utf8ToBytes(string, buf.length - offset), buf, offset, length)
}

function asciiWrite (buf, string, offset, length) {
  return blitBuffer(asciiToBytes(string), buf, offset, length)
}

function latin1Write (buf, string, offset, length) {
  return asciiWrite(buf, string, offset, length)
}

function base64Write (buf, string, offset, length) {
  return blitBuffer(base64ToBytes(string), buf, offset, length)
}

function ucs2Write (buf, string, offset, length) {
  return blitBuffer(utf16leToBytes(string, buf.length - offset), buf, offset, length)
}

Buffer.prototype.write = function write (string, offset, length, encoding) {
  // Buffer#write(string)
  if (offset === undefined) {
    encoding = 'utf8'
    length = this.length
    offset = 0
  // Buffer#write(string, encoding)
  } else if (length === undefined && typeof offset === 'string') {
    encoding = offset
    length = this.length
    offset = 0
  // Buffer#write(string, offset[, length][, encoding])
  } else if (isFinite(offset)) {
    offset = offset | 0
    if (isFinite(length)) {
      length = length | 0
      if (encoding === undefined) encoding = 'utf8'
    } else {
      encoding = length
      length = undefined
    }
  // legacy write(string, encoding, offset, length) - remove in v0.13
  } else {
    throw new Error(
      'Buffer.write(string, encoding, offset[, length]) is no longer supported'
    )
  }

  var remaining = this.length - offset
  if (length === undefined || length > remaining) length = remaining

  if ((string.length > 0 && (length < 0 || offset < 0)) || offset > this.length) {
    throw new RangeError('Attempt to write outside buffer bounds')
  }

  if (!encoding) encoding = 'utf8'

  var loweredCase = false
  for (;;) {
    switch (encoding) {
      case 'hex':
        return hexWrite(this, string, offset, length)

      case 'utf8':
      case 'utf-8':
        return utf8Write(this, string, offset, length)

      case 'ascii':
        return asciiWrite(this, string, offset, length)

      case 'latin1':
      case 'binary':
        return latin1Write(this, string, offset, length)

      case 'base64':
        // Warning: maxLength not taken into account in base64Write
        return base64Write(this, string, offset, length)

      case 'ucs2':
      case 'ucs-2':
      case 'utf16le':
      case 'utf-16le':
        return ucs2Write(this, string, offset, length)

      default:
        if (loweredCase) throw new TypeError('Unknown encoding: ' + encoding)
        encoding = ('' + encoding).toLowerCase()
        loweredCase = true
    }
  }
}

Buffer.prototype.toJSON = function toJSON () {
  return {
    type: 'Buffer',
    data: Array.prototype.slice.call(this._arr || this, 0)
  }
}

function base64Slice (buf, start, end) {
  if (start === 0 && end === buf.length) {
    return base64.fromByteArray(buf)
  } else {
    return base64.fromByteArray(buf.slice(start, end))
  }
}

function utf8Slice (buf, start, end) {
  end = Math.min(buf.length, end)
  var res = []

  var i = start
  while (i < end) {
    var firstByte = buf[i]
    var codePoint = null
    var bytesPerSequence = (firstByte > 0xEF) ? 4
      : (firstByte > 0xDF) ? 3
      : (firstByte > 0xBF) ? 2
      : 1

    if (i + bytesPerSequence <= end) {
      var secondByte, thirdByte, fourthByte, tempCodePoint

      switch (bytesPerSequence) {
        case 1:
          if (firstByte < 0x80) {
            codePoint = firstByte
          }
          break
        case 2:
          secondByte = buf[i + 1]
          if ((secondByte & 0xC0) === 0x80) {
            tempCodePoint = (firstByte & 0x1F) << 0x6 | (secondByte & 0x3F)
            if (tempCodePoint > 0x7F) {
              codePoint = tempCodePoint
            }
          }
          break
        case 3:
          secondByte = buf[i + 1]
          thirdByte = buf[i + 2]
          if ((secondByte & 0xC0) === 0x80 && (thirdByte & 0xC0) === 0x80) {
            tempCodePoint = (firstByte & 0xF) << 0xC | (secondByte & 0x3F) << 0x6 | (thirdByte & 0x3F)
            if (tempCodePoint > 0x7FF && (tempCodePoint < 0xD800 || tempCodePoint > 0xDFFF)) {
              codePoint = tempCodePoint
            }
          }
          break
        case 4:
          secondByte = buf[i + 1]
          thirdByte = buf[i + 2]
          fourthByte = buf[i + 3]
          if ((secondByte & 0xC0) === 0x80 && (thirdByte & 0xC0) === 0x80 && (fourthByte & 0xC0) === 0x80) {
            tempCodePoint = (firstByte & 0xF) << 0x12 | (secondByte & 0x3F) << 0xC | (thirdByte & 0x3F) << 0x6 | (fourthByte & 0x3F)
            if (tempCodePoint > 0xFFFF && tempCodePoint < 0x110000) {
              codePoint = tempCodePoint
            }
          }
      }
    }

    if (codePoint === null) {
      // we did not generate a valid codePoint so insert a
      // replacement char (U+FFFD) and advance only 1 byte
      codePoint = 0xFFFD
      bytesPerSequence = 1
    } else if (codePoint > 0xFFFF) {
      // encode to utf16 (surrogate pair dance)
      codePoint -= 0x10000
      res.push(codePoint >>> 10 & 0x3FF | 0xD800)
      codePoint = 0xDC00 | codePoint & 0x3FF
    }

    res.push(codePoint)
    i += bytesPerSequence
  }

  return decodeCodePointsArray(res)
}

// Based on http://stackoverflow.com/a/22747272/680742, the browser with
// the lowest limit is Chrome, with 0x10000 args.
// We go 1 magnitude less, for safety
var MAX_ARGUMENTS_LENGTH = 0x1000

function decodeCodePointsArray (codePoints) {
  var len = codePoints.length
  if (len <= MAX_ARGUMENTS_LENGTH) {
    return String.fromCharCode.apply(String, codePoints) // avoid extra slice()
  }

  // Decode in chunks to avoid "call stack size exceeded".
  var res = ''
  var i = 0
  while (i < len) {
    res += String.fromCharCode.apply(
      String,
      codePoints.slice(i, i += MAX_ARGUMENTS_LENGTH)
    )
  }
  return res
}

function asciiSlice (buf, start, end) {
  var ret = ''
  end = Math.min(buf.length, end)

  for (var i = start; i < end; ++i) {
    ret += String.fromCharCode(buf[i] & 0x7F)
  }
  return ret
}

function latin1Slice (buf, start, end) {
  var ret = ''
  end = Math.min(buf.length, end)

  for (var i = start; i < end; ++i) {
    ret += String.fromCharCode(buf[i])
  }
  return ret
}

function hexSlice (buf, start, end) {
  var len = buf.length

  if (!start || start < 0) start = 0
  if (!end || end < 0 || end > len) end = len

  var out = ''
  for (var i = start; i < end; ++i) {
    out += toHex(buf[i])
  }
  return out
}

function utf16leSlice (buf, start, end) {
  var bytes = buf.slice(start, end)
  var res = ''
  for (var i = 0; i < bytes.length; i += 2) {
    res += String.fromCharCode(bytes[i] + bytes[i + 1] * 256)
  }
  return res
}

Buffer.prototype.slice = function slice (start, end) {
  var len = this.length
  start = ~~start
  end = end === undefined ? len : ~~end

  if (start < 0) {
    start += len
    if (start < 0) start = 0
  } else if (start > len) {
    start = len
  }

  if (end < 0) {
    end += len
    if (end < 0) end = 0
  } else if (end > len) {
    end = len
  }

  if (end < start) end = start

  var newBuf
  if (Buffer.TYPED_ARRAY_SUPPORT) {
    newBuf = this.subarray(start, end)
    newBuf.__proto__ = Buffer.prototype
  } else {
    var sliceLen = end - start
    newBuf = new Buffer(sliceLen, undefined)
    for (var i = 0; i < sliceLen; ++i) {
      newBuf[i] = this[i + start]
    }
  }

  return newBuf
}

/*
 * Need to make sure that buffer isn't trying to write out of bounds.
 */
function checkOffset (offset, ext, length) {
  if ((offset % 1) !== 0 || offset < 0) throw new RangeError('offset is not uint')
  if (offset + ext > length) throw new RangeError('Trying to access beyond buffer length')
}

Buffer.prototype.readUIntLE = function readUIntLE (offset, byteLength, noAssert) {
  offset = offset | 0
  byteLength = byteLength | 0
  if (!noAssert) checkOffset(offset, byteLength, this.length)

  var val = this[offset]
  var mul = 1
  var i = 0
  while (++i < byteLength && (mul *= 0x100)) {
    val += this[offset + i] * mul
  }

  return val
}

Buffer.prototype.readUIntBE = function readUIntBE (offset, byteLength, noAssert) {
  offset = offset | 0
  byteLength = byteLength | 0
  if (!noAssert) {
    checkOffset(offset, byteLength, this.length)
  }

  var val = this[offset + --byteLength]
  var mul = 1
  while (byteLength > 0 && (mul *= 0x100)) {
    val += this[offset + --byteLength] * mul
  }

  return val
}

Buffer.prototype.readUInt8 = function readUInt8 (offset, noAssert) {
  if (!noAssert) checkOffset(offset, 1, this.length)
  return this[offset]
}

Buffer.prototype.readUInt16LE = function readUInt16LE (offset, noAssert) {
  if (!noAssert) checkOffset(offset, 2, this.length)
  return this[offset] | (this[offset + 1] << 8)
}

Buffer.prototype.readUInt16BE = function readUInt16BE (offset, noAssert) {
  if (!noAssert) checkOffset(offset, 2, this.length)
  return (this[offset] << 8) | this[offset + 1]
}

Buffer.prototype.readUInt32LE = function readUInt32LE (offset, noAssert) {
  if (!noAssert) checkOffset(offset, 4, this.length)

  return ((this[offset]) |
      (this[offset + 1] << 8) |
      (this[offset + 2] << 16)) +
      (this[offset + 3] * 0x1000000)
}

Buffer.prototype.readUInt32BE = function readUInt32BE (offset, noAssert) {
  if (!noAssert) checkOffset(offset, 4, this.length)

  return (this[offset] * 0x1000000) +
    ((this[offset + 1] << 16) |
    (this[offset + 2] << 8) |
    this[offset + 3])
}

Buffer.prototype.readIntLE = function readIntLE (offset, byteLength, noAssert) {
  offset = offset | 0
  byteLength = byteLength | 0
  if (!noAssert) checkOffset(offset, byteLength, this.length)

  var val = this[offset]
  var mul = 1
  var i = 0
  while (++i < byteLength && (mul *= 0x100)) {
    val += this[offset + i] * mul
  }
  mul *= 0x80

  if (val >= mul) val -= Math.pow(2, 8 * byteLength)

  return val
}

Buffer.prototype.readIntBE = function readIntBE (offset, byteLength, noAssert) {
  offset = offset | 0
  byteLength = byteLength | 0
  if (!noAssert) checkOffset(offset, byteLength, this.length)

  var i = byteLength
  var mul = 1
  var val = this[offset + --i]
  while (i > 0 && (mul *= 0x100)) {
    val += this[offset + --i] * mul
  }
  mul *= 0x80

  if (val >= mul) val -= Math.pow(2, 8 * byteLength)

  return val
}

Buffer.prototype.readInt8 = function readInt8 (offset, noAssert) {
  if (!noAssert) checkOffset(offset, 1, this.length)
  if (!(this[offset] & 0x80)) return (this[offset])
  return ((0xff - this[offset] + 1) * -1)
}

Buffer.prototype.readInt16LE = function readInt16LE (offset, noAssert) {
  if (!noAssert) checkOffset(offset, 2, this.length)
  var val = this[offset] | (this[offset + 1] << 8)
  return (val & 0x8000) ? val | 0xFFFF0000 : val
}

Buffer.prototype.readInt16BE = function readInt16BE (offset, noAssert) {
  if (!noAssert) checkOffset(offset, 2, this.length)
  var val = this[offset + 1] | (this[offset] << 8)
  return (val & 0x8000) ? val | 0xFFFF0000 : val
}

Buffer.prototype.readInt32LE = function readInt32LE (offset, noAssert) {
  if (!noAssert) checkOffset(offset, 4, this.length)

  return (this[offset]) |
    (this[offset + 1] << 8) |
    (this[offset + 2] << 16) |
    (this[offset + 3] << 24)
}

Buffer.prototype.readInt32BE = function readInt32BE (offset, noAssert) {
  if (!noAssert) checkOffset(offset, 4, this.length)

  return (this[offset] << 24) |
    (this[offset + 1] << 16) |
    (this[offset + 2] << 8) |
    (this[offset + 3])
}

Buffer.prototype.readFloatLE = function readFloatLE (offset, noAssert) {
  if (!noAssert) checkOffset(offset, 4, this.length)
  return ieee754.read(this, offset, true, 23, 4)
}

Buffer.prototype.readFloatBE = function readFloatBE (offset, noAssert) {
  if (!noAssert) checkOffset(offset, 4, this.length)
  return ieee754.read(this, offset, false, 23, 4)
}

Buffer.prototype.readDoubleLE = function readDoubleLE (offset, noAssert) {
  if (!noAssert) checkOffset(offset, 8, this.length)
  return ieee754.read(this, offset, true, 52, 8)
}

Buffer.prototype.readDoubleBE = function readDoubleBE (offset, noAssert) {
  if (!noAssert) checkOffset(offset, 8, this.length)
  return ieee754.read(this, offset, false, 52, 8)
}

function checkInt (buf, value, offset, ext, max, min) {
  if (!Buffer.isBuffer(buf)) throw new TypeError('"buffer" argument must be a Buffer instance')
  if (value > max || value < min) throw new RangeError('"value" argument is out of bounds')
  if (offset + ext > buf.length) throw new RangeError('Index out of range')
}

Buffer.prototype.writeUIntLE = function writeUIntLE (value, offset, byteLength, noAssert) {
  value = +value
  offset = offset | 0
  byteLength = byteLength | 0
  if (!noAssert) {
    var maxBytes = Math.pow(2, 8 * byteLength) - 1
    checkInt(this, value, offset, byteLength, maxBytes, 0)
  }

  var mul = 1
  var i = 0
  this[offset] = value & 0xFF
  while (++i < byteLength && (mul *= 0x100)) {
    this[offset + i] = (value / mul) & 0xFF
  }

  return offset + byteLength
}

Buffer.prototype.writeUIntBE = function writeUIntBE (value, offset, byteLength, noAssert) {
  value = +value
  offset = offset | 0
  byteLength = byteLength | 0
  if (!noAssert) {
    var maxBytes = Math.pow(2, 8 * byteLength) - 1
    checkInt(this, value, offset, byteLength, maxBytes, 0)
  }

  var i = byteLength - 1
  var mul = 1
  this[offset + i] = value & 0xFF
  while (--i >= 0 && (mul *= 0x100)) {
    this[offset + i] = (value / mul) & 0xFF
  }

  return offset + byteLength
}

Buffer.prototype.writeUInt8 = function writeUInt8 (value, offset, noAssert) {
  value = +value
  offset = offset | 0
  if (!noAssert) checkInt(this, value, offset, 1, 0xff, 0)
  if (!Buffer.TYPED_ARRAY_SUPPORT) value = Math.floor(value)
  this[offset] = (value & 0xff)
  return offset + 1
}

function objectWriteUInt16 (buf, value, offset, littleEndian) {
  if (value < 0) value = 0xffff + value + 1
  for (var i = 0, j = Math.min(buf.length - offset, 2); i < j; ++i) {
    buf[offset + i] = (value & (0xff << (8 * (littleEndian ? i : 1 - i)))) >>>
      (littleEndian ? i : 1 - i) * 8
  }
}

Buffer.prototype.writeUInt16LE = function writeUInt16LE (value, offset, noAssert) {
  value = +value
  offset = offset | 0
  if (!noAssert) checkInt(this, value, offset, 2, 0xffff, 0)
  if (Buffer.TYPED_ARRAY_SUPPORT) {
    this[offset] = (value & 0xff)
    this[offset + 1] = (value >>> 8)
  } else {
    objectWriteUInt16(this, value, offset, true)
  }
  return offset + 2
}

Buffer.prototype.writeUInt16BE = function writeUInt16BE (value, offset, noAssert) {
  value = +value
  offset = offset | 0
  if (!noAssert) checkInt(this, value, offset, 2, 0xffff, 0)
  if (Buffer.TYPED_ARRAY_SUPPORT) {
    this[offset] = (value >>> 8)
    this[offset + 1] = (value & 0xff)
  } else {
    objectWriteUInt16(this, value, offset, false)
  }
  return offset + 2
}

function objectWriteUInt32 (buf, value, offset, littleEndian) {
  if (value < 0) value = 0xffffffff + value + 1
  for (var i = 0, j = Math.min(buf.length - offset, 4); i < j; ++i) {
    buf[offset + i] = (value >>> (littleEndian ? i : 3 - i) * 8) & 0xff
  }
}

Buffer.prototype.writeUInt32LE = function writeUInt32LE (value, offset, noAssert) {
  value = +value
  offset = offset | 0
  if (!noAssert) checkInt(this, value, offset, 4, 0xffffffff, 0)
  if (Buffer.TYPED_ARRAY_SUPPORT) {
    this[offset + 3] = (value >>> 24)
    this[offset + 2] = (value >>> 16)
    this[offset + 1] = (value >>> 8)
    this[offset] = (value & 0xff)
  } else {
    objectWriteUInt32(this, value, offset, true)
  }
  return offset + 4
}

Buffer.prototype.writeUInt32BE = function writeUInt32BE (value, offset, noAssert) {
  value = +value
  offset = offset | 0
  if (!noAssert) checkInt(this, value, offset, 4, 0xffffffff, 0)
  if (Buffer.TYPED_ARRAY_SUPPORT) {
    this[offset] = (value >>> 24)
    this[offset + 1] = (value >>> 16)
    this[offset + 2] = (value >>> 8)
    this[offset + 3] = (value & 0xff)
  } else {
    objectWriteUInt32(this, value, offset, false)
  }
  return offset + 4
}

Buffer.prototype.writeIntLE = function writeIntLE (value, offset, byteLength, noAssert) {
  value = +value
  offset = offset | 0
  if (!noAssert) {
    var limit = Math.pow(2, 8 * byteLength - 1)

    checkInt(this, value, offset, byteLength, limit - 1, -limit)
  }

  var i = 0
  var mul = 1
  var sub = 0
  this[offset] = value & 0xFF
  while (++i < byteLength && (mul *= 0x100)) {
    if (value < 0 && sub === 0 && this[offset + i - 1] !== 0) {
      sub = 1
    }
    this[offset + i] = ((value / mul) >> 0) - sub & 0xFF
  }

  return offset + byteLength
}

Buffer.prototype.writeIntBE = function writeIntBE (value, offset, byteLength, noAssert) {
  value = +value
  offset = offset | 0
  if (!noAssert) {
    var limit = Math.pow(2, 8 * byteLength - 1)

    checkInt(this, value, offset, byteLength, limit - 1, -limit)
  }

  var i = byteLength - 1
  var mul = 1
  var sub = 0
  this[offset + i] = value & 0xFF
  while (--i >= 0 && (mul *= 0x100)) {
    if (value < 0 && sub === 0 && this[offset + i + 1] !== 0) {
      sub = 1
    }
    this[offset + i] = ((value / mul) >> 0) - sub & 0xFF
  }

  return offset + byteLength
}

Buffer.prototype.writeInt8 = function writeInt8 (value, offset, noAssert) {
  value = +value
  offset = offset | 0
  if (!noAssert) checkInt(this, value, offset, 1, 0x7f, -0x80)
  if (!Buffer.TYPED_ARRAY_SUPPORT) value = Math.floor(value)
  if (value < 0) value = 0xff + value + 1
  this[offset] = (value & 0xff)
  return offset + 1
}

Buffer.prototype.writeInt16LE = function writeInt16LE (value, offset, noAssert) {
  value = +value
  offset = offset | 0
  if (!noAssert) checkInt(this, value, offset, 2, 0x7fff, -0x8000)
  if (Buffer.TYPED_ARRAY_SUPPORT) {
    this[offset] = (value & 0xff)
    this[offset + 1] = (value >>> 8)
  } else {
    objectWriteUInt16(this, value, offset, true)
  }
  return offset + 2
}

Buffer.prototype.writeInt16BE = function writeInt16BE (value, offset, noAssert) {
  value = +value
  offset = offset | 0
  if (!noAssert) checkInt(this, value, offset, 2, 0x7fff, -0x8000)
  if (Buffer.TYPED_ARRAY_SUPPORT) {
    this[offset] = (value >>> 8)
    this[offset + 1] = (value & 0xff)
  } else {
    objectWriteUInt16(this, value, offset, false)
  }
  return offset + 2
}

Buffer.prototype.writeInt32LE = function writeInt32LE (value, offset, noAssert) {
  value = +value
  offset = offset | 0
  if (!noAssert) checkInt(this, value, offset, 4, 0x7fffffff, -0x80000000)
  if (Buffer.TYPED_ARRAY_SUPPORT) {
    this[offset] = (value & 0xff)
    this[offset + 1] = (value >>> 8)
    this[offset + 2] = (value >>> 16)
    this[offset + 3] = (value >>> 24)
  } else {
    objectWriteUInt32(this, value, offset, true)
  }
  return offset + 4
}

Buffer.prototype.writeInt32BE = function writeInt32BE (value, offset, noAssert) {
  value = +value
  offset = offset | 0
  if (!noAssert) checkInt(this, value, offset, 4, 0x7fffffff, -0x80000000)
  if (value < 0) value = 0xffffffff + value + 1
  if (Buffer.TYPED_ARRAY_SUPPORT) {
    this[offset] = (value >>> 24)
    this[offset + 1] = (value >>> 16)
    this[offset + 2] = (value >>> 8)
    this[offset + 3] = (value & 0xff)
  } else {
    objectWriteUInt32(this, value, offset, false)
  }
  return offset + 4
}

function checkIEEE754 (buf, value, offset, ext, max, min) {
  if (offset + ext > buf.length) throw new RangeError('Index out of range')
  if (offset < 0) throw new RangeError('Index out of range')
}

function writeFloat (buf, value, offset, littleEndian, noAssert) {
  if (!noAssert) {
    checkIEEE754(buf, value, offset, 4, 3.4028234663852886e+38, -3.4028234663852886e+38)
  }
  ieee754.write(buf, value, offset, littleEndian, 23, 4)
  return offset + 4
}

Buffer.prototype.writeFloatLE = function writeFloatLE (value, offset, noAssert) {
  return writeFloat(this, value, offset, true, noAssert)
}

Buffer.prototype.writeFloatBE = function writeFloatBE (value, offset, noAssert) {
  return writeFloat(this, value, offset, false, noAssert)
}

function writeDouble (buf, value, offset, littleEndian, noAssert) {
  if (!noAssert) {
    checkIEEE754(buf, value, offset, 8, 1.7976931348623157E+308, -1.7976931348623157E+308)
  }
  ieee754.write(buf, value, offset, littleEndian, 52, 8)
  return offset + 8
}

Buffer.prototype.writeDoubleLE = function writeDoubleLE (value, offset, noAssert) {
  return writeDouble(this, value, offset, true, noAssert)
}

Buffer.prototype.writeDoubleBE = function writeDoubleBE (value, offset, noAssert) {
  return writeDouble(this, value, offset, false, noAssert)
}

// copy(targetBuffer, targetStart=0, sourceStart=0, sourceEnd=buffer.length)
Buffer.prototype.copy = function copy (target, targetStart, start, end) {
  if (!start) start = 0
  if (!end && end !== 0) end = this.length
  if (targetStart >= target.length) targetStart = target.length
  if (!targetStart) targetStart = 0
  if (end > 0 && end < start) end = start

  // Copy 0 bytes; we're done
  if (end === start) return 0
  if (target.length === 0 || this.length === 0) return 0

  // Fatal error conditions
  if (targetStart < 0) {
    throw new RangeError('targetStart out of bounds')
  }
  if (start < 0 || start >= this.length) throw new RangeError('sourceStart out of bounds')
  if (end < 0) throw new RangeError('sourceEnd out of bounds')

  // Are we oob?
  if (end > this.length) end = this.length
  if (target.length - targetStart < end - start) {
    end = target.length - targetStart + start
  }

  var len = end - start
  var i

  if (this === target && start < targetStart && targetStart < end) {
    // descending copy from end
    for (i = len - 1; i >= 0; --i) {
      target[i + targetStart] = this[i + start]
    }
  } else if (len < 1000 || !Buffer.TYPED_ARRAY_SUPPORT) {
    // ascending copy from start
    for (i = 0; i < len; ++i) {
      target[i + targetStart] = this[i + start]
    }
  } else {
    Uint8Array.prototype.set.call(
      target,
      this.subarray(start, start + len),
      targetStart
    )
  }

  return len
}

// Usage:
//    buffer.fill(number[, offset[, end]])
//    buffer.fill(buffer[, offset[, end]])
//    buffer.fill(string[, offset[, end]][, encoding])
Buffer.prototype.fill = function fill (val, start, end, encoding) {
  // Handle string cases:
  if (typeof val === 'string') {
    if (typeof start === 'string') {
      encoding = start
      start = 0
      end = this.length
    } else if (typeof end === 'string') {
      encoding = end
      end = this.length
    }
    if (val.length === 1) {
      var code = val.charCodeAt(0)
      if (code < 256) {
        val = code
      }
    }
    if (encoding !== undefined && typeof encoding !== 'string') {
      throw new TypeError('encoding must be a string')
    }
    if (typeof encoding === 'string' && !Buffer.isEncoding(encoding)) {
      throw new TypeError('Unknown encoding: ' + encoding)
    }
  } else if (typeof val === 'number') {
    val = val & 255
  }

  // Invalid ranges are not set to a default, so can range check early.
  if (start < 0 || this.length < start || this.length < end) {
    throw new RangeError('Out of range index')
  }

  if (end <= start) {
    return this
  }

  start = start >>> 0
  end = end === undefined ? this.length : end >>> 0

  if (!val) val = 0

  var i
  if (typeof val === 'number') {
    for (i = start; i < end; ++i) {
      this[i] = val
    }
  } else {
    var bytes = Buffer.isBuffer(val)
      ? val
      : utf8ToBytes(new Buffer(val, encoding).toString())
    var len = bytes.length
    for (i = 0; i < end - start; ++i) {
      this[i + start] = bytes[i % len]
    }
  }

  return this
}

// HELPER FUNCTIONS
// ================

var INVALID_BASE64_RE = /[^+\/0-9A-Za-z-_]/g

function base64clean (str) {
  // Node strips out invalid characters like \n and \t from the string, base64-js does not
  str = stringtrim(str).replace(INVALID_BASE64_RE, '')
  // Node converts strings with length < 2 to ''
  if (str.length < 2) return ''
  // Node allows for non-padded base64 strings (missing trailing ===), base64-js does not
  while (str.length % 4 !== 0) {
    str = str + '='
  }
  return str
}

function stringtrim (str) {
  if (str.trim) return str.trim()
  return str.replace(/^\s+|\s+$/g, '')
}

function toHex (n) {
  if (n < 16) return '0' + n.toString(16)
  return n.toString(16)
}

function utf8ToBytes (string, units) {
  units = units || Infinity
  var codePoint
  var length = string.length
  var leadSurrogate = null
  var bytes = []

  for (var i = 0; i < length; ++i) {
    codePoint = string.charCodeAt(i)

    // is surrogate component
    if (codePoint > 0xD7FF && codePoint < 0xE000) {
      // last char was a lead
      if (!leadSurrogate) {
        // no lead yet
        if (codePoint > 0xDBFF) {
          // unexpected trail
          if ((units -= 3) > -1) bytes.push(0xEF, 0xBF, 0xBD)
          continue
        } else if (i + 1 === length) {
          // unpaired lead
          if ((units -= 3) > -1) bytes.push(0xEF, 0xBF, 0xBD)
          continue
        }

        // valid lead
        leadSurrogate = codePoint

        continue
      }

      // 2 leads in a row
      if (codePoint < 0xDC00) {
        if ((units -= 3) > -1) bytes.push(0xEF, 0xBF, 0xBD)
        leadSurrogate = codePoint
        continue
      }

      // valid surrogate pair
      codePoint = (leadSurrogate - 0xD800 << 10 | codePoint - 0xDC00) + 0x10000
    } else if (leadSurrogate) {
      // valid bmp char, but last char was a lead
      if ((units -= 3) > -1) bytes.push(0xEF, 0xBF, 0xBD)
    }

    leadSurrogate = null

    // encode utf8
    if (codePoint < 0x80) {
      if ((units -= 1) < 0) break
      bytes.push(codePoint)
    } else if (codePoint < 0x800) {
      if ((units -= 2) < 0) break
      bytes.push(
        codePoint >> 0x6 | 0xC0,
        codePoint & 0x3F | 0x80
      )
    } else if (codePoint < 0x10000) {
      if ((units -= 3) < 0) break
      bytes.push(
        codePoint >> 0xC | 0xE0,
        codePoint >> 0x6 & 0x3F | 0x80,
        codePoint & 0x3F | 0x80
      )
    } else if (codePoint < 0x110000) {
      if ((units -= 4) < 0) break
      bytes.push(
        codePoint >> 0x12 | 0xF0,
        codePoint >> 0xC & 0x3F | 0x80,
        codePoint >> 0x6 & 0x3F | 0x80,
        codePoint & 0x3F | 0x80
      )
    } else {
      throw new Error('Invalid code point')
    }
  }

  return bytes
}

function asciiToBytes (str) {
  var byteArray = []
  for (var i = 0; i < str.length; ++i) {
    // Node's code seems to be doing this and not & 0x7F..
    byteArray.push(str.charCodeAt(i) & 0xFF)
  }
  return byteArray
}

function utf16leToBytes (str, units) {
  var c, hi, lo
  var byteArray = []
  for (var i = 0; i < str.length; ++i) {
    if ((units -= 2) < 0) break

    c = str.charCodeAt(i)
    hi = c >> 8
    lo = c % 256
    byteArray.push(lo)
    byteArray.push(hi)
  }

  return byteArray
}

function base64ToBytes (str) {
  return base64.toByteArray(base64clean(str))
}

function blitBuffer (src, dst, offset, length) {
  for (var i = 0; i < length; ++i) {
    if ((i + offset >= dst.length) || (i >= src.length)) break
    dst[i + offset] = src[i]
  }
  return i
}

function isnan (val) {
  return val !== val // eslint-disable-line no-self-compare
}

/* WEBPACK VAR INJECTION */}.call(exports, __webpack_require__(5)))

/***/ }),
/* 8 */
/***/ (function(module, exports) {

if (typeof Object.create === 'function') {
  // implementation from standard node.js 'util' module
  module.exports = function inherits(ctor, superCtor) {
    ctor.super_ = superCtor
    ctor.prototype = Object.create(superCtor.prototype, {
      constructor: {
        value: ctor,
        enumerable: false,
        writable: true,
        configurable: true
      }
    });
  };
} else {
  // old school shim for old browsers
  module.exports = function inherits(ctor, superCtor) {
    ctor.super_ = superCtor
    var TempCtor = function () {}
    TempCtor.prototype = superCtor.prototype
    ctor.prototype = new TempCtor()
    ctor.prototype.constructor = ctor
  }
}


/***/ }),
/* 9 */
/***/ (function(module, exports) {

// shim for using process in browser
var process = module.exports = {};

// cached from whatever global is present so that test runners that stub it
// don't break things.  But we need to wrap it in a try catch in case it is
// wrapped in strict mode code which doesn't define any globals.  It's inside a
// function because try/catches deoptimize in certain engines.

var cachedSetTimeout;
var cachedClearTimeout;

function defaultSetTimout() {
    throw new Error('setTimeout has not been defined');
}
function defaultClearTimeout () {
    throw new Error('clearTimeout has not been defined');
}
(function () {
    try {
        if (typeof setTimeout === 'function') {
            cachedSetTimeout = setTimeout;
        } else {
            cachedSetTimeout = defaultSetTimout;
        }
    } catch (e) {
        cachedSetTimeout = defaultSetTimout;
    }
    try {
        if (typeof clearTimeout === 'function') {
            cachedClearTimeout = clearTimeout;
        } else {
            cachedClearTimeout = defaultClearTimeout;
        }
    } catch (e) {
        cachedClearTimeout = defaultClearTimeout;
    }
} ())
function runTimeout(fun) {
    if (cachedSetTimeout === setTimeout) {
        //normal enviroments in sane situations
        return setTimeout(fun, 0);
    }
    // if setTimeout wasn't available but was latter defined
    if ((cachedSetTimeout === defaultSetTimout || !cachedSetTimeout) && setTimeout) {
        cachedSetTimeout = setTimeout;
        return setTimeout(fun, 0);
    }
    try {
        // when when somebody has screwed with setTimeout but no I.E. maddness
        return cachedSetTimeout(fun, 0);
    } catch(e){
        try {
            // When we are in I.E. but the script has been evaled so I.E. doesn't trust the global object when called normally
            return cachedSetTimeout.call(null, fun, 0);
        } catch(e){
            // same as above but when it's a version of I.E. that must have the global object for 'this', hopfully our context correct otherwise it will throw a global error
            return cachedSetTimeout.call(this, fun, 0);
        }
    }


}
function runClearTimeout(marker) {
    if (cachedClearTimeout === clearTimeout) {
        //normal enviroments in sane situations
        return clearTimeout(marker);
    }
    // if clearTimeout wasn't available but was latter defined
    if ((cachedClearTimeout === defaultClearTimeout || !cachedClearTimeout) && clearTimeout) {
        cachedClearTimeout = clearTimeout;
        return clearTimeout(marker);
    }
    try {
        // when when somebody has screwed with setTimeout but no I.E. maddness
        return cachedClearTimeout(marker);
    } catch (e){
        try {
            // When we are in I.E. but the script has been evaled so I.E. doesn't  trust the global object when called normally
            return cachedClearTimeout.call(null, marker);
        } catch (e){
            // same as above but when it's a version of I.E. that must have the global object for 'this', hopfully our context correct otherwise it will throw a global error.
            // Some versions of I.E. have different rules for clearTimeout vs setTimeout
            return cachedClearTimeout.call(this, marker);
        }
    }



}
var queue = [];
var draining = false;
var currentQueue;
var queueIndex = -1;

function cleanUpNextTick() {
    if (!draining || !currentQueue) {
        return;
    }
    draining = false;
    if (currentQueue.length) {
        queue = currentQueue.concat(queue);
    } else {
        queueIndex = -1;
    }
    if (queue.length) {
        drainQueue();
    }
}

function drainQueue() {
    if (draining) {
        return;
    }
    var timeout = runTimeout(cleanUpNextTick);
    draining = true;

    var len = queue.length;
    while(len) {
        currentQueue = queue;
        queue = [];
        while (++queueIndex < len) {
            if (currentQueue) {
                currentQueue[queueIndex].run();
            }
        }
        queueIndex = -1;
        len = queue.length;
    }
    currentQueue = null;
    draining = false;
    runClearTimeout(timeout);
}

process.nextTick = function (fun) {
    var args = new Array(arguments.length - 1);
    if (arguments.length > 1) {
        for (var i = 1; i < arguments.length; i++) {
            args[i - 1] = arguments[i];
        }
    }
    queue.push(new Item(fun, args));
    if (queue.length === 1 && !draining) {
        runTimeout(drainQueue);
    }
};

// v8 likes predictible objects
function Item(fun, array) {
    this.fun = fun;
    this.array = array;
}
Item.prototype.run = function () {
    this.fun.apply(null, this.array);
};
process.title = 'browser';
process.browser = true;
process.env = {};
process.argv = [];
process.version = ''; // empty string to avoid regexp issues
process.versions = {};

function noop() {}

process.on = noop;
process.addListener = noop;
process.once = noop;
process.off = noop;
process.removeListener = noop;
process.removeAllListeners = noop;
process.emit = noop;
process.prependListener = noop;
process.prependOnceListener = noop;

process.listeners = function (name) { return [] }

process.binding = function (name) {
    throw new Error('process.binding is not supported');
};

process.cwd = function () { return '/' };
process.chdir = function (dir) {
    throw new Error('process.chdir is not supported');
};
process.umask = function() { return 0; };


/***/ }),
/* 10 */
/***/ (function(module, exports, __webpack_require__) {

/* WEBPACK VAR INJECTION */(function(Buffer) {// Copyright Joyent, Inc. and other Node contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.

// NOTE: These type checking functions intentionally don't use `instanceof`
// because it is fragile and can be easily faked with `Object.create()`.

function isArray(arg) {
  if (Array.isArray) {
    return Array.isArray(arg);
  }
  return objectToString(arg) === '[object Array]';
}
exports.isArray = isArray;

function isBoolean(arg) {
  return typeof arg === 'boolean';
}
exports.isBoolean = isBoolean;

function isNull(arg) {
  return arg === null;
}
exports.isNull = isNull;

function isNullOrUndefined(arg) {
  return arg == null;
}
exports.isNullOrUndefined = isNullOrUndefined;

function isNumber(arg) {
  return typeof arg === 'number';
}
exports.isNumber = isNumber;

function isString(arg) {
  return typeof arg === 'string';
}
exports.isString = isString;

function isSymbol(arg) {
  return typeof arg === 'symbol';
}
exports.isSymbol = isSymbol;

function isUndefined(arg) {
  return arg === void 0;
}
exports.isUndefined = isUndefined;

function isRegExp(re) {
  return objectToString(re) === '[object RegExp]';
}
exports.isRegExp = isRegExp;

function isObject(arg) {
  return typeof arg === 'object' && arg !== null;
}
exports.isObject = isObject;

function isDate(d) {
  return objectToString(d) === '[object Date]';
}
exports.isDate = isDate;

function isError(e) {
  return (objectToString(e) === '[object Error]' || e instanceof Error);
}
exports.isError = isError;

function isFunction(arg) {
  return typeof arg === 'function';
}
exports.isFunction = isFunction;

function isPrimitive(arg) {
  return arg === null ||
         typeof arg === 'boolean' ||
         typeof arg === 'number' ||
         typeof arg === 'string' ||
         typeof arg === 'symbol' ||  // ES6 symbol
         typeof arg === 'undefined';
}
exports.isPrimitive = isPrimitive;

exports.isBuffer = Buffer.isBuffer;

function objectToString(o) {
  return Object.prototype.toString.call(o);
}

/* WEBPACK VAR INJECTION */}.call(exports, __webpack_require__(7).Buffer))

/***/ }),
/* 11 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/* WEBPACK VAR INJECTION */(function(process) {

if (!process.version ||
    process.version.indexOf('v0.') === 0 ||
    process.version.indexOf('v1.') === 0 && process.version.indexOf('v1.8.') !== 0) {
  module.exports = { nextTick: nextTick };
} else {
  module.exports = process
}

function nextTick(fn, arg1, arg2, arg3) {
  if (typeof fn !== 'function') {
    throw new TypeError('"callback" argument must be a function');
  }
  var len = arguments.length;
  var args, i;
  switch (len) {
  case 0:
  case 1:
    return process.nextTick(fn);
  case 2:
    return process.nextTick(function afterTickOne() {
      fn.call(null, arg1);
    });
  case 3:
    return process.nextTick(function afterTickTwo() {
      fn.call(null, arg1, arg2);
    });
  case 4:
    return process.nextTick(function afterTickThree() {
      fn.call(null, arg1, arg2, arg3);
    });
  default:
    args = new Array(len - 1);
    i = 0;
    while (i < args.length) {
      args[i++] = arguments[i];
    }
    return process.nextTick(function afterTick() {
      fn.apply(null, args);
    });
  }
}


/* WEBPACK VAR INJECTION */}.call(exports, __webpack_require__(9)))

/***/ }),
/* 12 */
/***/ (function(module, exports, __webpack_require__) {

/* eslint-disable node/no-deprecated-api */
var buffer = __webpack_require__(7)
var Buffer = buffer.Buffer

// alternative to using Object.keys for old browsers
function copyProps (src, dst) {
  for (var key in src) {
    dst[key] = src[key]
  }
}
if (Buffer.from && Buffer.alloc && Buffer.allocUnsafe && Buffer.allocUnsafeSlow) {
  module.exports = buffer
} else {
  // Copy properties from require('buffer')
  copyProps(buffer, exports)
  exports.Buffer = SafeBuffer
}

function SafeBuffer (arg, encodingOrOffset, length) {
  return Buffer(arg, encodingOrOffset, length)
}

// Copy static methods from Buffer
copyProps(Buffer, SafeBuffer)

SafeBuffer.from = function (arg, encodingOrOffset, length) {
  if (typeof arg === 'number') {
    throw new TypeError('Argument must not be a number')
  }
  return Buffer(arg, encodingOrOffset, length)
}

SafeBuffer.alloc = function (size, fill, encoding) {
  if (typeof size !== 'number') {
    throw new TypeError('Argument must be a number')
  }
  var buf = Buffer(size)
  if (fill !== undefined) {
    if (typeof encoding === 'string') {
      buf.fill(fill, encoding)
    } else {
      buf.fill(fill)
    }
  } else {
    buf.fill(0)
  }
  return buf
}

SafeBuffer.allocUnsafe = function (size) {
  if (typeof size !== 'number') {
    throw new TypeError('Argument must be a number')
  }
  return Buffer(size)
}

SafeBuffer.allocUnsafeSlow = function (size) {
  if (typeof size !== 'number') {
    throw new TypeError('Argument must be a number')
  }
  return buffer.SlowBuffer(size)
}


/***/ }),
/* 13 */
/***/ (function(module, exports, __webpack_require__) {

//========================================================================================
// Globals
//========================================================================================

var Context = __webpack_require__(49).Context;

var PRIMITIVE_TYPES = {
    'UInt8'    : 1,
    'UInt16LE' : 2,
    'UInt16BE' : 2,
    'UInt32LE' : 4,
    'UInt32BE' : 4,
    'Int8'     : 1,
    'Int16LE'  : 2,
    'Int16BE'  : 2,
    'Int32LE'  : 4,
    'Int32BE'  : 4,
    'FloatLE'  : 4,
    'FloatBE'  : 4,
    'DoubleLE' : 8,
    'DoubleBE' : 8
};

var SPECIAL_TYPES = {
    'String'   : null,
    'Buffer'   : null,
    'Array'    : null,
    'Skip'     : null,
    'Choice'   : null,
    'Nest'     : null,
    'Bit'      : null
};

var BIT_RANGE = [];
(function() {
    var i;
    for (i = 1; i <= 32; i++) {
        BIT_RANGE.push(i);
    }
})();

// Converts Parser's method names to internal type names
var NAME_MAP = {};
Object.keys(PRIMITIVE_TYPES)
    .concat(Object.keys(SPECIAL_TYPES))
    .forEach(function(type) {
        NAME_MAP[type.toLowerCase()] = type;
    });

//========================================================================================
// class Parser
//========================================================================================

//----------------------------------------------------------------------------------------
// constructor
//----------------------------------------------------------------------------------------

var Parser = function() {
    this.varName = '';
    this.type = '';
    this.options = {};
    this.next = null;
    this.head = null;
    this.compiled = null;
    this.endian = 'be';
    this.constructorFn = null;
};

//----------------------------------------------------------------------------------------
// public methods
//----------------------------------------------------------------------------------------

Parser.start = function() {
    return new Parser();
};

Object.keys(PRIMITIVE_TYPES)
    .forEach(function(type) {
        Parser.prototype[type.toLowerCase()] = function(varName, options) {
            return this.setNextParser(type.toLowerCase(), varName, options);
        };

        var typeWithoutEndian = type.replace(/BE|LE/, '').toLowerCase();
        if (!(typeWithoutEndian in Parser.prototype)) {
            Parser.prototype[typeWithoutEndian] = function(varName, options) {
                return this[typeWithoutEndian + this.endian](varName, options);
            };
        }
    });

BIT_RANGE.forEach(function(i) {
    Parser.prototype['bit' + i.toString()] = function(varName, options) {
        if (!options) {
            options = {};
        }
        options.length = i;
        return this.setNextParser('bit', varName, options);
    };
});

Parser.prototype.skip = function(length, options) {
    if (options && options.assert) {
        throw new Error('assert option on skip is not allowed.');
    }

    return this.setNextParser('skip', '', {length: length});
};

Parser.prototype.string = function(varName, options) {
    if (!options.zeroTerminated && !options.length && !options.greedy) {
        throw new Error('Neither length, zeroTerminated, nor greedy is defined for string.');
    }
    if ((options.zeroTerminated || options.length) && options.greedy) {
        throw new Error('greedy is mutually exclusive with length and zeroTerminated for string.');
    }
    if (options.stripNull && !(options.length || options.greedy)) {
        throw new Error('Length or greedy must be defined if stripNull is defined.');
    }
    options.encoding = options.encoding || 'utf8';

    return this.setNextParser('string', varName, options);
};

Parser.prototype.buffer = function(varName, options) {
    if (!options.length && !options.readUntil) {
        throw new Error('Length nor readUntil is defined in buffer parser');
    }

    return this.setNextParser('buffer', varName, options);
};

Parser.prototype.array = function(varName, options) {
    if (!options.readUntil && !options.length) {
        throw new Error('Length option of array is not defined.');
    }
    if (!options.type) {
        throw new Error('Type option of array is not defined.');
    }
    if (typeof options.type === 'string' && Object.keys(PRIMITIVE_TYPES).indexOf(NAME_MAP[options.type]) < 0) {
        throw new Error('Specified primitive type "' + options.type + '" is not supported.');
    }

    return this.setNextParser('array', varName, options);
};

Parser.prototype.choice = function(varName, options) {
    if (!options.tag) {
        throw new Error('Tag option of array is not defined.');
    }
    if (!options.choices) {
        throw new Error('Choices option of array is not defined.');
    }
    Object.keys(options.choices).forEach(function(key) {
        if (isNaN(parseInt(key, 10))) {
            throw new Error('Key of choices must be a number.');
        }
        if (!options.choices[key]) {
            throw new Error('Choice Case ' + key + ' of ' + varName + ' is not valid.');
        }

        if (typeof options.choices[key] === 'string' && Object.keys(PRIMITIVE_TYPES).indexOf(NAME_MAP[options.choices[key]]) < 0) {
            throw new Error('Specified primitive type "' +  options.choices[key] + '" is not supported.');
        }
    });

    return this.setNextParser('choice', varName, options);
};

Parser.prototype.nest = function(varName, options) {
    if (!options.type) {
        throw new Error('Type option of nest is not defined.');
    }
    if (!(options.type instanceof Parser)) {
        throw new Error('Type option of nest must be a Parser object.');
    }

    return this.setNextParser('nest', varName, options);
};

Parser.prototype.endianess = function(endianess) {
    switch (endianess.toLowerCase()) {
    case 'little':
        this.endian = 'le';
        break;
    case 'big':
        this.endian = 'be';
        break;
    default:
        throw new Error('Invalid endianess: ' + endianess);
    }

    return this;
};

Parser.prototype.create = function(constructorFn) {
    if (!(constructorFn instanceof Function)) {
        throw new Error('Constructor must be a Function object.');
    }

    this.constructorFn = constructorFn;

    return this;
};

Parser.prototype.getCode = function() {
    var ctx = new Context();

    if (this.constructorFn) {
        ctx.pushCode('var vars = new constructorFn();');
    } else {
        ctx.pushCode('var vars = {};');
    }
    ctx.pushCode('var offset = 0;');
    ctx.pushCode('if (!Buffer.isBuffer(buffer)) {');
    ctx.generateError('"argument buffer is not a Buffer object"');
    ctx.pushCode('}');

    this.generate(ctx);

    ctx.pushCode('return vars;');

    return ctx.code;
};

Parser.prototype.compile = function() {
    this.compiled = new Function('buffer', 'callback', 'constructorFn', this.getCode());
};

Parser.prototype.sizeOf = function() {
    var size = NaN;

    if (Object.keys(PRIMITIVE_TYPES).indexOf(this.type) >= 0) {
        size = PRIMITIVE_TYPES[this.type];

    // if this is a fixed length string
    } else if (this.type === 'String' && typeof this.options.length === 'number') {
        size = this.options.length;

    // if this is a fixed length array
    } else if (this.type === 'Array' && typeof this.options.length === 'number') {
        var elementSize = NaN;
        if (typeof this.options.type === 'string'){
            elementSize = PRIMITIVE_TYPES[NAME_MAP[this.options.type]];
        } else if (this.options.type instanceof Parser) {
            elementSize = this.options.type.sizeOf();
        }
        size = this.options.length * elementSize;

    // if this a skip
    } else if (this.type === 'Skip') {
        size = this.options.length;

    } else if (!this.type) {
        size = 0;
    }

    if (this.next) {
        size += this.next.sizeOf();
    }

    return size;
};

// Follow the parser chain till the root and start parsing from there
Parser.prototype.parse = function(buffer, callback) {
    if (!this.compiled) {
        this.compile();
    }

    return this.compiled(buffer, callback, this.constructorFn);
};

//----------------------------------------------------------------------------------------
// private methods
//----------------------------------------------------------------------------------------

Parser.prototype.setNextParser = function(type, varName, options) {
    var parser = new Parser();

    parser.type = NAME_MAP[type];
    parser.varName = varName;
    parser.options = options || parser.options;
    parser.endian = this.endian;

    if (this.head) {
        this.head.next = parser;
    } else {
        this.next = parser;
    }
    this.head = parser;

    return this;
};

// Call code generator for this parser
Parser.prototype.generate = function(ctx) {
    if (this.type) {
        this['generate' + this.type](ctx);
        this.generateAssert(ctx);
    }

    var varName = ctx.generateVariable(this.varName);
    if (this.options.formatter) {
        this.generateFormatter(ctx, varName, this.options.formatter);
    }

    return this.generateNext(ctx);
};

Parser.prototype.generateAssert = function(ctx) {
    if (!this.options.assert) {
        return;
    }

    var varName = ctx.generateVariable(this.varName);

    switch (typeof this.options.assert) {
        case 'function':
            ctx.pushCode('if (!({0}).call(vars, {1})) {', this.options.assert, varName);
        break;
        case 'number':
            ctx.pushCode('if ({0} !== {1}) {', this.options.assert, varName);
        break;
        case 'string':
            ctx.pushCode('if ("{0}" !== {1}) {', this.options.assert, varName);
        break;
        default:
            throw new Error('Assert option supports only strings, numbers and assert functions.');
    }
    ctx.generateError('"Assert error: {0} is " + {0}', varName);
    ctx.pushCode('}');
};

// Recursively call code generators and append results
Parser.prototype.generateNext = function(ctx) {
    if (this.next) {
        ctx = this.next.generate(ctx);
    }

    return ctx;
};

Object.keys(PRIMITIVE_TYPES).forEach(function(type) {
    Parser.prototype['generate' + type] = function(ctx) {
        ctx.pushCode('{0} = buffer.read{1}(offset);', ctx.generateVariable(this.varName), type);
        ctx.pushCode('offset += {0};', PRIMITIVE_TYPES[type]);
    };
});

Parser.prototype.generateBit = function(ctx) {
    // TODO find better method to handle nested bit fields
    var parser = JSON.parse(JSON.stringify(this));
    parser.varName = ctx.generateVariable(parser.varName);
    ctx.bitFields.push(parser);

    if (!this.next || (this.next && ['Bit', 'Nest'].indexOf(this.next.type) < 0)) {
        var sum = 0;
        ctx.bitFields.forEach(function(parser) {
            sum += parser.options.length;
        });

        var val = ctx.generateTmpVariable();

        if (sum <= 8) {
            ctx.pushCode('var {0} = buffer.readUInt8(offset);', val);
            sum = 8;
        } else if (sum <= 16) {
            ctx.pushCode('var {0} = buffer.readUInt16BE(offset);', val);
            sum = 16;
        } else if (sum <= 24) {
            var val1 = ctx.generateTmpVariable();
            var val2 = ctx.generateTmpVariable();
            ctx.pushCode('var {0} = buffer.readUInt16BE(offset);', val1);
            ctx.pushCode('var {0} = buffer.readUInt8(offset + 2);', val2);
            ctx.pushCode('var {2} = ({0} << 8) | {1};', val1, val2, val);
            sum = 24;
        } else if (sum <= 32) {
            ctx.pushCode('var {0} = buffer.readUInt32BE(offset);', val);
            sum = 32;
        } else {
            throw new Error('Currently, bit field sequence longer than 4-bytes is not supported.');
        }
        ctx.pushCode('offset += {0};', sum / 8);

        var bitOffset = 0;
        var isBigEndian = this.endian === 'be';
        ctx.bitFields.forEach(function(parser) {
            ctx.pushCode('{0} = {1} >> {2} & {3};',
                parser.varName,
                val,
                isBigEndian ? sum - bitOffset - parser.options.length : bitOffset,
                (1 << parser.options.length) - 1
            );
            bitOffset += parser.options.length;
        });

        ctx.bitFields = [];
    }
};

Parser.prototype.generateSkip = function(ctx) {
    var length = ctx.generateOption(this.options.length);
    ctx.pushCode('offset += {0};', length);
};

Parser.prototype.generateString = function(ctx) {
    var name = ctx.generateVariable(this.varName);
    var start = ctx.generateTmpVariable();

    if (this.options.length && this.options.zeroTerminated) {
        ctx.pushCode('var {0} = offset;', start);
        ctx.pushCode('while(buffer.readUInt8(offset++) !== 0 && offset - {0}  < {1});',
            start,
            this.options.length
        );
        ctx.pushCode('{0} = buffer.toString(\'{1}\', {2}, offset - {2} < {3} ? offset - 1 : offset);',
            name,
            this.options.encoding,
            start,
            this.options.length
        );
    } else if(this.options.length) {
        ctx.pushCode('{0} = buffer.toString(\'{1}\', offset, offset + {2});',
                            name,
                            this.options.encoding,
                            ctx.generateOption(this.options.length)
                        );
        ctx.pushCode('offset += {0};', ctx.generateOption(this.options.length));
    } else if (this.options.zeroTerminated) {
        ctx.pushCode('var {0} = offset;', start);
        ctx.pushCode('while(buffer.readUInt8(offset++) !== 0);');
        ctx.pushCode('{0} = buffer.toString(\'{1}\', {2}, offset - 1);',
            name,
            this.options.encoding,
            start
        );
    } else if (this.options.greedy) {
        ctx.pushCode('var {0} = offset;', start);
        ctx.pushCode('while(buffer.length > offset++);');
        ctx.pushCode('{0} = buffer.toString(\'{1}\', {2}, offset);',
            name,
            this.options.encoding,
            start
        );
    }
    if(this.options.stripNull) {
        ctx.pushCode('{0} = {0}.replace(/\\x00+$/g, \'\')', name);
    }
};

Parser.prototype.generateBuffer = function(ctx) {
    if (this.options.readUntil === 'eof') {
        ctx.pushCode('{0} = buffer.slice(offset, buffer.length - 1);',
            ctx.generateVariable(this.varName)
            );
    } else {
        ctx.pushCode('{0} = buffer.slice(offset, offset + {1});',
            ctx.generateVariable(this.varName),
            ctx.generateOption(this.options.length)
            );
        ctx.pushCode('offset += {0};', ctx.generateOption(this.options.length));
    }

    if (this.options.clone) {
        var buf = ctx.generateTmpVariable();

        ctx.pushCode('var {0} = new Buffer({1}.length);', buf, ctx.generateVariable(this.varName));
        ctx.pushCode('{0}.copy({1});', ctx.generateVariable(this.varName), buf);
        ctx.pushCode('{0} = {1}', ctx.generateVariable(this.varName), buf);
    }
};

Parser.prototype.generateArray = function(ctx) {
    var length = ctx.generateOption(this.options.length);
    var type = this.options.type;
    var counter = ctx.generateTmpVariable();
    var lhs = ctx.generateVariable(this.varName);
    var item = ctx.generateTmpVariable();
    var key = this.options.key;
    var isHash = typeof key === 'string';

    if (isHash) {
        ctx.pushCode('{0} = {};', lhs);
    } else {
        ctx.pushCode('{0} = [];', lhs);
    }
    if (typeof this.options.readUntil === 'function') {
        ctx.pushCode('do {');
    } else if (this.options.readUntil === 'eof') {
        ctx.pushCode('for (var {0} = 0; offset < buffer.length; {0}++) {', counter);
    } else {
        ctx.pushCode('for (var {0} = 0; {0} < {1}; {0}++) {', counter, length);
    }

    if (typeof type === 'string') {
        ctx.pushCode('var {0} = buffer.read{1}(offset);', item, NAME_MAP[type]);
        ctx.pushCode('offset += {0};', PRIMITIVE_TYPES[NAME_MAP[type]]);
    } else if (type instanceof Parser) {
        ctx.pushCode('var {0} = {};', item);

        ctx.pushScope(item);
        type.generate(ctx);
        ctx.popScope();
    }

    if (isHash) {
        ctx.pushCode('{0}[{2}.{1}] = {2};', lhs, key, item);
    } else {
        ctx.pushCode('{0}.push({1});', lhs, item);
    }

    ctx.pushCode('}');

    if (typeof this.options.readUntil === 'function') {
        ctx.pushCode(' while (!({0}).call(this, {1}, buffer.slice(offset)));', this.options.readUntil, item);
    }
};

Parser.prototype.generateChoiceCase = function(ctx, varName, type) {
    if (typeof type === 'string') {
        ctx.pushCode('{0} = buffer.read{1}(offset);', ctx.generateVariable(this.varName), NAME_MAP[type]);
        ctx.pushCode('offset += {0};', PRIMITIVE_TYPES[NAME_MAP[type]]);
    } else if (type instanceof Parser) {
        ctx.pushPath(varName);
        type.generate(ctx);
        ctx.popPath();
    }
};

Parser.prototype.generateChoice = function(ctx) {
    var tag = ctx.generateOption(this.options.tag);

    ctx.pushCode('{0} = {};', ctx.generateVariable(this.varName));
    ctx.pushCode('switch({0}) {', tag);
    Object.keys(this.options.choices).forEach(function(tag) {
        var type = this.options.choices[tag];

        ctx.pushCode('case {0}:', tag);
        this.generateChoiceCase(ctx, this.varName, type);
        ctx.pushCode('break;');
    }, this);
    ctx.pushCode('default:');
    if (this.options.defaultChoice) {
        this.generateChoiceCase(ctx, this.varName, this.options.defaultChoice);
    } else {
        ctx.generateError('"Met undefined tag value " + {0} + " at choice"', tag);
    }
    ctx.pushCode('}');
};

Parser.prototype.generateNest = function(ctx) {
    var nestVar = ctx.generateVariable(this.varName);
    ctx.pushCode('{0} = {};', nestVar);
    ctx.pushPath(this.varName);
    this.options.type.generate(ctx);
    ctx.popPath();
};

Parser.prototype.generateFormatter = function(ctx, varName, formatter) {
    if (typeof formatter === 'function') {
        ctx.pushCode('{0} = ({1}).call(this, {0});', varName, formatter);
    }
};

Parser.prototype.isInteger = function() {
    return !!this.type.match(/U?Int[8|16|32][BE|LE]?|Bit\d+/);
};

//========================================================================================
// Exports
//========================================================================================

exports.Parser = Parser;


/***/ }),
/* 14 */
/***/ (function(module, exports) {

// Copyright Joyent, Inc. and other Node contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.

function EventEmitter() {
  this._events = this._events || {};
  this._maxListeners = this._maxListeners || undefined;
}
module.exports = EventEmitter;

// Backwards-compat with node 0.10.x
EventEmitter.EventEmitter = EventEmitter;

EventEmitter.prototype._events = undefined;
EventEmitter.prototype._maxListeners = undefined;

// By default EventEmitters will print a warning if more than 10 listeners are
// added to it. This is a useful default which helps finding memory leaks.
EventEmitter.defaultMaxListeners = 10;

// Obviously not all Emitters should be limited to 10. This function allows
// that to be increased. Set to zero for unlimited.
EventEmitter.prototype.setMaxListeners = function(n) {
  if (!isNumber(n) || n < 0 || isNaN(n))
    throw TypeError('n must be a positive number');
  this._maxListeners = n;
  return this;
};

EventEmitter.prototype.emit = function(type) {
  var er, handler, len, args, i, listeners;

  if (!this._events)
    this._events = {};

  // If there is no 'error' event listener then throw.
  if (type === 'error') {
    if (!this._events.error ||
        (isObject(this._events.error) && !this._events.error.length)) {
      er = arguments[1];
      if (er instanceof Error) {
        throw er; // Unhandled 'error' event
      } else {
        // At least give some kind of context to the user
        var err = new Error('Uncaught, unspecified "error" event. (' + er + ')');
        err.context = er;
        throw err;
      }
    }
  }

  handler = this._events[type];

  if (isUndefined(handler))
    return false;

  if (isFunction(handler)) {
    switch (arguments.length) {
      // fast cases
      case 1:
        handler.call(this);
        break;
      case 2:
        handler.call(this, arguments[1]);
        break;
      case 3:
        handler.call(this, arguments[1], arguments[2]);
        break;
      // slower
      default:
        args = Array.prototype.slice.call(arguments, 1);
        handler.apply(this, args);
    }
  } else if (isObject(handler)) {
    args = Array.prototype.slice.call(arguments, 1);
    listeners = handler.slice();
    len = listeners.length;
    for (i = 0; i < len; i++)
      listeners[i].apply(this, args);
  }

  return true;
};

EventEmitter.prototype.addListener = function(type, listener) {
  var m;

  if (!isFunction(listener))
    throw TypeError('listener must be a function');

  if (!this._events)
    this._events = {};

  // To avoid recursion in the case that type === "newListener"! Before
  // adding it to the listeners, first emit "newListener".
  if (this._events.newListener)
    this.emit('newListener', type,
              isFunction(listener.listener) ?
              listener.listener : listener);

  if (!this._events[type])
    // Optimize the case of one listener. Don't need the extra array object.
    this._events[type] = listener;
  else if (isObject(this._events[type]))
    // If we've already got an array, just append.
    this._events[type].push(listener);
  else
    // Adding the second element, need to change to array.
    this._events[type] = [this._events[type], listener];

  // Check for listener leak
  if (isObject(this._events[type]) && !this._events[type].warned) {
    if (!isUndefined(this._maxListeners)) {
      m = this._maxListeners;
    } else {
      m = EventEmitter.defaultMaxListeners;
    }

    if (m && m > 0 && this._events[type].length > m) {
      this._events[type].warned = true;
      console.error('(node) warning: possible EventEmitter memory ' +
                    'leak detected. %d listeners added. ' +
                    'Use emitter.setMaxListeners() to increase limit.',
                    this._events[type].length);
      if (typeof console.trace === 'function') {
        // not supported in IE 10
        console.trace();
      }
    }
  }

  return this;
};

EventEmitter.prototype.on = EventEmitter.prototype.addListener;

EventEmitter.prototype.once = function(type, listener) {
  if (!isFunction(listener))
    throw TypeError('listener must be a function');

  var fired = false;

  function g() {
    this.removeListener(type, g);

    if (!fired) {
      fired = true;
      listener.apply(this, arguments);
    }
  }

  g.listener = listener;
  this.on(type, g);

  return this;
};

// emits a 'removeListener' event iff the listener was removed
EventEmitter.prototype.removeListener = function(type, listener) {
  var list, position, length, i;

  if (!isFunction(listener))
    throw TypeError('listener must be a function');

  if (!this._events || !this._events[type])
    return this;

  list = this._events[type];
  length = list.length;
  position = -1;

  if (list === listener ||
      (isFunction(list.listener) && list.listener === listener)) {
    delete this._events[type];
    if (this._events.removeListener)
      this.emit('removeListener', type, listener);

  } else if (isObject(list)) {
    for (i = length; i-- > 0;) {
      if (list[i] === listener ||
          (list[i].listener && list[i].listener === listener)) {
        position = i;
        break;
      }
    }

    if (position < 0)
      return this;

    if (list.length === 1) {
      list.length = 0;
      delete this._events[type];
    } else {
      list.splice(position, 1);
    }

    if (this._events.removeListener)
      this.emit('removeListener', type, listener);
  }

  return this;
};

EventEmitter.prototype.removeAllListeners = function(type) {
  var key, listeners;

  if (!this._events)
    return this;

  // not listening for removeListener, no need to emit
  if (!this._events.removeListener) {
    if (arguments.length === 0)
      this._events = {};
    else if (this._events[type])
      delete this._events[type];
    return this;
  }

  // emit removeListener for all listeners on all events
  if (arguments.length === 0) {
    for (key in this._events) {
      if (key === 'removeListener') continue;
      this.removeAllListeners(key);
    }
    this.removeAllListeners('removeListener');
    this._events = {};
    return this;
  }

  listeners = this._events[type];

  if (isFunction(listeners)) {
    this.removeListener(type, listeners);
  } else if (listeners) {
    // LIFO order
    while (listeners.length)
      this.removeListener(type, listeners[listeners.length - 1]);
  }
  delete this._events[type];

  return this;
};

EventEmitter.prototype.listeners = function(type) {
  var ret;
  if (!this._events || !this._events[type])
    ret = [];
  else if (isFunction(this._events[type]))
    ret = [this._events[type]];
  else
    ret = this._events[type].slice();
  return ret;
};

EventEmitter.prototype.listenerCount = function(type) {
  if (this._events) {
    var evlistener = this._events[type];

    if (isFunction(evlistener))
      return 1;
    else if (evlistener)
      return evlistener.length;
  }
  return 0;
};

EventEmitter.listenerCount = function(emitter, type) {
  return emitter.listenerCount(type);
};

function isFunction(arg) {
  return typeof arg === 'function';
}

function isNumber(arg) {
  return typeof arg === 'number';
}

function isObject(arg) {
  return typeof arg === 'object' && arg !== null;
}

function isUndefined(arg) {
  return arg === void 0;
}


/***/ }),
/* 15 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/* WEBPACK VAR INJECTION */(function(process, setImmediate, global) {// Copyright Joyent, Inc. and other Node contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.

// A bit simpler than readable streams.
// Implement an async ._write(chunk, encoding, cb), and it'll handle all
// the drain event emission and buffering.



/*<replacement>*/

var pna = __webpack_require__(11);
/*</replacement>*/

module.exports = Writable;

/* <replacement> */
function WriteReq(chunk, encoding, cb) {
  this.chunk = chunk;
  this.encoding = encoding;
  this.callback = cb;
  this.next = null;
}

// It seems a linked list but it is not
// there will be only 2 of these for each stream
function CorkedRequest(state) {
  var _this = this;

  this.next = null;
  this.entry = null;
  this.finish = function () {
    onCorkedFinish(_this, state);
  };
}
/* </replacement> */

/*<replacement>*/
var asyncWrite = !process.browser && ['v0.10', 'v0.9.'].indexOf(process.version.slice(0, 5)) > -1 ? setImmediate : pna.nextTick;
/*</replacement>*/

/*<replacement>*/
var Duplex;
/*</replacement>*/

Writable.WritableState = WritableState;

/*<replacement>*/
var util = __webpack_require__(10);
util.inherits = __webpack_require__(8);
/*</replacement>*/

/*<replacement>*/
var internalUtil = {
  deprecate: __webpack_require__(61)
};
/*</replacement>*/

/*<replacement>*/
var Stream = __webpack_require__(21);
/*</replacement>*/

/*<replacement>*/

var Buffer = __webpack_require__(12).Buffer;
var OurUint8Array = global.Uint8Array || function () {};
function _uint8ArrayToBuffer(chunk) {
  return Buffer.from(chunk);
}
function _isUint8Array(obj) {
  return Buffer.isBuffer(obj) || obj instanceof OurUint8Array;
}

/*</replacement>*/

var destroyImpl = __webpack_require__(20);

util.inherits(Writable, Stream);

function nop() {}

function WritableState(options, stream) {
  Duplex = Duplex || __webpack_require__(6);

  options = options || {};

  // Duplex streams are both readable and writable, but share
  // the same options object.
  // However, some cases require setting options to different
  // values for the readable and the writable sides of the duplex stream.
  // These options can be provided separately as readableXXX and writableXXX.
  var isDuplex = stream instanceof Duplex;

  // object stream flag to indicate whether or not this stream
  // contains buffers or objects.
  this.objectMode = !!options.objectMode;

  if (isDuplex) this.objectMode = this.objectMode || !!options.writableObjectMode;

  // the point at which write() starts returning false
  // Note: 0 is a valid value, means that we always return false if
  // the entire buffer is not flushed immediately on write()
  var hwm = options.highWaterMark;
  var writableHwm = options.writableHighWaterMark;
  var defaultHwm = this.objectMode ? 16 : 16 * 1024;

  if (hwm || hwm === 0) this.highWaterMark = hwm;else if (isDuplex && (writableHwm || writableHwm === 0)) this.highWaterMark = writableHwm;else this.highWaterMark = defaultHwm;

  // cast to ints.
  this.highWaterMark = Math.floor(this.highWaterMark);

  // if _final has been called
  this.finalCalled = false;

  // drain event flag.
  this.needDrain = false;
  // at the start of calling end()
  this.ending = false;
  // when end() has been called, and returned
  this.ended = false;
  // when 'finish' is emitted
  this.finished = false;

  // has it been destroyed
  this.destroyed = false;

  // should we decode strings into buffers before passing to _write?
  // this is here so that some node-core streams can optimize string
  // handling at a lower level.
  var noDecode = options.decodeStrings === false;
  this.decodeStrings = !noDecode;

  // Crypto is kind of old and crusty.  Historically, its default string
  // encoding is 'binary' so we have to make this configurable.
  // Everything else in the universe uses 'utf8', though.
  this.defaultEncoding = options.defaultEncoding || 'utf8';

  // not an actual buffer we keep track of, but a measurement
  // of how much we're waiting to get pushed to some underlying
  // socket or file.
  this.length = 0;

  // a flag to see when we're in the middle of a write.
  this.writing = false;

  // when true all writes will be buffered until .uncork() call
  this.corked = 0;

  // a flag to be able to tell if the onwrite cb is called immediately,
  // or on a later tick.  We set this to true at first, because any
  // actions that shouldn't happen until "later" should generally also
  // not happen before the first write call.
  this.sync = true;

  // a flag to know if we're processing previously buffered items, which
  // may call the _write() callback in the same tick, so that we don't
  // end up in an overlapped onwrite situation.
  this.bufferProcessing = false;

  // the callback that's passed to _write(chunk,cb)
  this.onwrite = function (er) {
    onwrite(stream, er);
  };

  // the callback that the user supplies to write(chunk,encoding,cb)
  this.writecb = null;

  // the amount that is being written when _write is called.
  this.writelen = 0;

  this.bufferedRequest = null;
  this.lastBufferedRequest = null;

  // number of pending user-supplied write callbacks
  // this must be 0 before 'finish' can be emitted
  this.pendingcb = 0;

  // emit prefinish if the only thing we're waiting for is _write cbs
  // This is relevant for synchronous Transform streams
  this.prefinished = false;

  // True if the error was already emitted and should not be thrown again
  this.errorEmitted = false;

  // count buffered requests
  this.bufferedRequestCount = 0;

  // allocate the first CorkedRequest, there is always
  // one allocated and free to use, and we maintain at most two
  this.corkedRequestsFree = new CorkedRequest(this);
}

WritableState.prototype.getBuffer = function getBuffer() {
  var current = this.bufferedRequest;
  var out = [];
  while (current) {
    out.push(current);
    current = current.next;
  }
  return out;
};

(function () {
  try {
    Object.defineProperty(WritableState.prototype, 'buffer', {
      get: internalUtil.deprecate(function () {
        return this.getBuffer();
      }, '_writableState.buffer is deprecated. Use _writableState.getBuffer ' + 'instead.', 'DEP0003')
    });
  } catch (_) {}
})();

// Test _writableState for inheritance to account for Duplex streams,
// whose prototype chain only points to Readable.
var realHasInstance;
if (typeof Symbol === 'function' && Symbol.hasInstance && typeof Function.prototype[Symbol.hasInstance] === 'function') {
  realHasInstance = Function.prototype[Symbol.hasInstance];
  Object.defineProperty(Writable, Symbol.hasInstance, {
    value: function (object) {
      if (realHasInstance.call(this, object)) return true;
      if (this !== Writable) return false;

      return object && object._writableState instanceof WritableState;
    }
  });
} else {
  realHasInstance = function (object) {
    return object instanceof this;
  };
}

function Writable(options) {
  Duplex = Duplex || __webpack_require__(6);

  // Writable ctor is applied to Duplexes, too.
  // `realHasInstance` is necessary because using plain `instanceof`
  // would return false, as no `_writableState` property is attached.

  // Trying to use the custom `instanceof` for Writable here will also break the
  // Node.js LazyTransform implementation, which has a non-trivial getter for
  // `_writableState` that would lead to infinite recursion.
  if (!realHasInstance.call(Writable, this) && !(this instanceof Duplex)) {
    return new Writable(options);
  }

  this._writableState = new WritableState(options, this);

  // legacy.
  this.writable = true;

  if (options) {
    if (typeof options.write === 'function') this._write = options.write;

    if (typeof options.writev === 'function') this._writev = options.writev;

    if (typeof options.destroy === 'function') this._destroy = options.destroy;

    if (typeof options.final === 'function') this._final = options.final;
  }

  Stream.call(this);
}

// Otherwise people can pipe Writable streams, which is just wrong.
Writable.prototype.pipe = function () {
  this.emit('error', new Error('Cannot pipe, not readable'));
};

function writeAfterEnd(stream, cb) {
  var er = new Error('write after end');
  // TODO: defer error events consistently everywhere, not just the cb
  stream.emit('error', er);
  pna.nextTick(cb, er);
}

// Checks that a user-supplied chunk is valid, especially for the particular
// mode the stream is in. Currently this means that `null` is never accepted
// and undefined/non-string values are only allowed in object mode.
function validChunk(stream, state, chunk, cb) {
  var valid = true;
  var er = false;

  if (chunk === null) {
    er = new TypeError('May not write null values to stream');
  } else if (typeof chunk !== 'string' && chunk !== undefined && !state.objectMode) {
    er = new TypeError('Invalid non-string/buffer chunk');
  }
  if (er) {
    stream.emit('error', er);
    pna.nextTick(cb, er);
    valid = false;
  }
  return valid;
}

Writable.prototype.write = function (chunk, encoding, cb) {
  var state = this._writableState;
  var ret = false;
  var isBuf = !state.objectMode && _isUint8Array(chunk);

  if (isBuf && !Buffer.isBuffer(chunk)) {
    chunk = _uint8ArrayToBuffer(chunk);
  }

  if (typeof encoding === 'function') {
    cb = encoding;
    encoding = null;
  }

  if (isBuf) encoding = 'buffer';else if (!encoding) encoding = state.defaultEncoding;

  if (typeof cb !== 'function') cb = nop;

  if (state.ended) writeAfterEnd(this, cb);else if (isBuf || validChunk(this, state, chunk, cb)) {
    state.pendingcb++;
    ret = writeOrBuffer(this, state, isBuf, chunk, encoding, cb);
  }

  return ret;
};

Writable.prototype.cork = function () {
  var state = this._writableState;

  state.corked++;
};

Writable.prototype.uncork = function () {
  var state = this._writableState;

  if (state.corked) {
    state.corked--;

    if (!state.writing && !state.corked && !state.finished && !state.bufferProcessing && state.bufferedRequest) clearBuffer(this, state);
  }
};

Writable.prototype.setDefaultEncoding = function setDefaultEncoding(encoding) {
  // node::ParseEncoding() requires lower case.
  if (typeof encoding === 'string') encoding = encoding.toLowerCase();
  if (!(['hex', 'utf8', 'utf-8', 'ascii', 'binary', 'base64', 'ucs2', 'ucs-2', 'utf16le', 'utf-16le', 'raw'].indexOf((encoding + '').toLowerCase()) > -1)) throw new TypeError('Unknown encoding: ' + encoding);
  this._writableState.defaultEncoding = encoding;
  return this;
};

function decodeChunk(state, chunk, encoding) {
  if (!state.objectMode && state.decodeStrings !== false && typeof chunk === 'string') {
    chunk = Buffer.from(chunk, encoding);
  }
  return chunk;
}

Object.defineProperty(Writable.prototype, 'writableHighWaterMark', {
  // making it explicit this property is not enumerable
  // because otherwise some prototype manipulation in
  // userland will fail
  enumerable: false,
  get: function () {
    return this._writableState.highWaterMark;
  }
});

// if we're already writing something, then just put this
// in the queue, and wait our turn.  Otherwise, call _write
// If we return false, then we need a drain event, so set that flag.
function writeOrBuffer(stream, state, isBuf, chunk, encoding, cb) {
  if (!isBuf) {
    var newChunk = decodeChunk(state, chunk, encoding);
    if (chunk !== newChunk) {
      isBuf = true;
      encoding = 'buffer';
      chunk = newChunk;
    }
  }
  var len = state.objectMode ? 1 : chunk.length;

  state.length += len;

  var ret = state.length < state.highWaterMark;
  // we must ensure that previous needDrain will not be reset to false.
  if (!ret) state.needDrain = true;

  if (state.writing || state.corked) {
    var last = state.lastBufferedRequest;
    state.lastBufferedRequest = {
      chunk: chunk,
      encoding: encoding,
      isBuf: isBuf,
      callback: cb,
      next: null
    };
    if (last) {
      last.next = state.lastBufferedRequest;
    } else {
      state.bufferedRequest = state.lastBufferedRequest;
    }
    state.bufferedRequestCount += 1;
  } else {
    doWrite(stream, state, false, len, chunk, encoding, cb);
  }

  return ret;
}

function doWrite(stream, state, writev, len, chunk, encoding, cb) {
  state.writelen = len;
  state.writecb = cb;
  state.writing = true;
  state.sync = true;
  if (writev) stream._writev(chunk, state.onwrite);else stream._write(chunk, encoding, state.onwrite);
  state.sync = false;
}

function onwriteError(stream, state, sync, er, cb) {
  --state.pendingcb;

  if (sync) {
    // defer the callback if we are being called synchronously
    // to avoid piling up things on the stack
    pna.nextTick(cb, er);
    // this can emit finish, and it will always happen
    // after error
    pna.nextTick(finishMaybe, stream, state);
    stream._writableState.errorEmitted = true;
    stream.emit('error', er);
  } else {
    // the caller expect this to happen before if
    // it is async
    cb(er);
    stream._writableState.errorEmitted = true;
    stream.emit('error', er);
    // this can emit finish, but finish must
    // always follow error
    finishMaybe(stream, state);
  }
}

function onwriteStateUpdate(state) {
  state.writing = false;
  state.writecb = null;
  state.length -= state.writelen;
  state.writelen = 0;
}

function onwrite(stream, er) {
  var state = stream._writableState;
  var sync = state.sync;
  var cb = state.writecb;

  onwriteStateUpdate(state);

  if (er) onwriteError(stream, state, sync, er, cb);else {
    // Check if we're actually ready to finish, but don't emit yet
    var finished = needFinish(state);

    if (!finished && !state.corked && !state.bufferProcessing && state.bufferedRequest) {
      clearBuffer(stream, state);
    }

    if (sync) {
      /*<replacement>*/
      asyncWrite(afterWrite, stream, state, finished, cb);
      /*</replacement>*/
    } else {
      afterWrite(stream, state, finished, cb);
    }
  }
}

function afterWrite(stream, state, finished, cb) {
  if (!finished) onwriteDrain(stream, state);
  state.pendingcb--;
  cb();
  finishMaybe(stream, state);
}

// Must force callback to be called on nextTick, so that we don't
// emit 'drain' before the write() consumer gets the 'false' return
// value, and has a chance to attach a 'drain' listener.
function onwriteDrain(stream, state) {
  if (state.length === 0 && state.needDrain) {
    state.needDrain = false;
    stream.emit('drain');
  }
}

// if there's something in the buffer waiting, then process it
function clearBuffer(stream, state) {
  state.bufferProcessing = true;
  var entry = state.bufferedRequest;

  if (stream._writev && entry && entry.next) {
    // Fast case, write everything using _writev()
    var l = state.bufferedRequestCount;
    var buffer = new Array(l);
    var holder = state.corkedRequestsFree;
    holder.entry = entry;

    var count = 0;
    var allBuffers = true;
    while (entry) {
      buffer[count] = entry;
      if (!entry.isBuf) allBuffers = false;
      entry = entry.next;
      count += 1;
    }
    buffer.allBuffers = allBuffers;

    doWrite(stream, state, true, state.length, buffer, '', holder.finish);

    // doWrite is almost always async, defer these to save a bit of time
    // as the hot path ends with doWrite
    state.pendingcb++;
    state.lastBufferedRequest = null;
    if (holder.next) {
      state.corkedRequestsFree = holder.next;
      holder.next = null;
    } else {
      state.corkedRequestsFree = new CorkedRequest(state);
    }
    state.bufferedRequestCount = 0;
  } else {
    // Slow case, write chunks one-by-one
    while (entry) {
      var chunk = entry.chunk;
      var encoding = entry.encoding;
      var cb = entry.callback;
      var len = state.objectMode ? 1 : chunk.length;

      doWrite(stream, state, false, len, chunk, encoding, cb);
      entry = entry.next;
      state.bufferedRequestCount--;
      // if we didn't call the onwrite immediately, then
      // it means that we need to wait until it does.
      // also, that means that the chunk and cb are currently
      // being processed, so move the buffer counter past them.
      if (state.writing) {
        break;
      }
    }

    if (entry === null) state.lastBufferedRequest = null;
  }

  state.bufferedRequest = entry;
  state.bufferProcessing = false;
}

Writable.prototype._write = function (chunk, encoding, cb) {
  cb(new Error('_write() is not implemented'));
};

Writable.prototype._writev = null;

Writable.prototype.end = function (chunk, encoding, cb) {
  var state = this._writableState;

  if (typeof chunk === 'function') {
    cb = chunk;
    chunk = null;
    encoding = null;
  } else if (typeof encoding === 'function') {
    cb = encoding;
    encoding = null;
  }

  if (chunk !== null && chunk !== undefined) this.write(chunk, encoding);

  // .end() fully uncorks
  if (state.corked) {
    state.corked = 1;
    this.uncork();
  }

  // ignore unnecessary end() calls.
  if (!state.ending && !state.finished) endWritable(this, state, cb);
};

function needFinish(state) {
  return state.ending && state.length === 0 && state.bufferedRequest === null && !state.finished && !state.writing;
}
function callFinal(stream, state) {
  stream._final(function (err) {
    state.pendingcb--;
    if (err) {
      stream.emit('error', err);
    }
    state.prefinished = true;
    stream.emit('prefinish');
    finishMaybe(stream, state);
  });
}
function prefinish(stream, state) {
  if (!state.prefinished && !state.finalCalled) {
    if (typeof stream._final === 'function') {
      state.pendingcb++;
      state.finalCalled = true;
      pna.nextTick(callFinal, stream, state);
    } else {
      state.prefinished = true;
      stream.emit('prefinish');
    }
  }
}

function finishMaybe(stream, state) {
  var need = needFinish(state);
  if (need) {
    prefinish(stream, state);
    if (state.pendingcb === 0) {
      state.finished = true;
      stream.emit('finish');
    }
  }
  return need;
}

function endWritable(stream, state, cb) {
  state.ending = true;
  finishMaybe(stream, state);
  if (cb) {
    if (state.finished) pna.nextTick(cb);else stream.once('finish', cb);
  }
  state.ended = true;
  stream.writable = false;
}

function onCorkedFinish(corkReq, state, err) {
  var entry = corkReq.entry;
  corkReq.entry = null;
  while (entry) {
    var cb = entry.callback;
    state.pendingcb--;
    cb(err);
    entry = entry.next;
  }
  if (state.corkedRequestsFree) {
    state.corkedRequestsFree.next = corkReq;
  } else {
    state.corkedRequestsFree = corkReq;
  }
}

Object.defineProperty(Writable.prototype, 'destroyed', {
  get: function () {
    if (this._writableState === undefined) {
      return false;
    }
    return this._writableState.destroyed;
  },
  set: function (value) {
    // we ignore the value if the stream
    // has not been initialized yet
    if (!this._writableState) {
      return;
    }

    // backward compatibility, the user is explicitly
    // managing destroyed
    this._writableState.destroyed = value;
  }
});

Writable.prototype.destroy = destroyImpl.destroy;
Writable.prototype._undestroy = destroyImpl.undestroy;
Writable.prototype._destroy = function (err, cb) {
  this.end();
  cb(err);
};
/* WEBPACK VAR INJECTION */}.call(exports, __webpack_require__(9), __webpack_require__(60).setImmediate, __webpack_require__(5)))

/***/ }),
/* 16 */
/***/ (function(module, exports, __webpack_require__) {

exports = module.exports = __webpack_require__(18);
exports.Stream = exports;
exports.Readable = exports;
exports.Writable = __webpack_require__(15);
exports.Duplex = __webpack_require__(6);
exports.Transform = __webpack_require__(19);
exports.PassThrough = __webpack_require__(54);


/***/ }),
/* 17 */
/***/ (function(module, exports) {

var toString = {}.toString;

module.exports = Array.isArray || function (arr) {
  return toString.call(arr) == '[object Array]';
};


/***/ }),
/* 18 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/* WEBPACK VAR INJECTION */(function(global, process) {// Copyright Joyent, Inc. and other Node contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.



/*<replacement>*/

var pna = __webpack_require__(11);
/*</replacement>*/

module.exports = Readable;

/*<replacement>*/
var isArray = __webpack_require__(17);
/*</replacement>*/

/*<replacement>*/
var Duplex;
/*</replacement>*/

Readable.ReadableState = ReadableState;

/*<replacement>*/
var EE = __webpack_require__(14).EventEmitter;

var EElistenerCount = function (emitter, type) {
  return emitter.listeners(type).length;
};
/*</replacement>*/

/*<replacement>*/
var Stream = __webpack_require__(21);
/*</replacement>*/

/*<replacement>*/

var Buffer = __webpack_require__(12).Buffer;
var OurUint8Array = global.Uint8Array || function () {};
function _uint8ArrayToBuffer(chunk) {
  return Buffer.from(chunk);
}
function _isUint8Array(obj) {
  return Buffer.isBuffer(obj) || obj instanceof OurUint8Array;
}

/*</replacement>*/

/*<replacement>*/
var util = __webpack_require__(10);
util.inherits = __webpack_require__(8);
/*</replacement>*/

/*<replacement>*/
var debugUtil = __webpack_require__(65);
var debug = void 0;
if (debugUtil && debugUtil.debuglog) {
  debug = debugUtil.debuglog('stream');
} else {
  debug = function () {};
}
/*</replacement>*/

var BufferList = __webpack_require__(55);
var destroyImpl = __webpack_require__(20);
var StringDecoder;

util.inherits(Readable, Stream);

var kProxyEvents = ['error', 'close', 'destroy', 'pause', 'resume'];

function prependListener(emitter, event, fn) {
  // Sadly this is not cacheable as some libraries bundle their own
  // event emitter implementation with them.
  if (typeof emitter.prependListener === 'function') return emitter.prependListener(event, fn);

  // This is a hack to make sure that our error handler is attached before any
  // userland ones.  NEVER DO THIS. This is here only because this code needs
  // to continue to work with older versions of Node.js that do not include
  // the prependListener() method. The goal is to eventually remove this hack.
  if (!emitter._events || !emitter._events[event]) emitter.on(event, fn);else if (isArray(emitter._events[event])) emitter._events[event].unshift(fn);else emitter._events[event] = [fn, emitter._events[event]];
}

function ReadableState(options, stream) {
  Duplex = Duplex || __webpack_require__(6);

  options = options || {};

  // Duplex streams are both readable and writable, but share
  // the same options object.
  // However, some cases require setting options to different
  // values for the readable and the writable sides of the duplex stream.
  // These options can be provided separately as readableXXX and writableXXX.
  var isDuplex = stream instanceof Duplex;

  // object stream flag. Used to make read(n) ignore n and to
  // make all the buffer merging and length checks go away
  this.objectMode = !!options.objectMode;

  if (isDuplex) this.objectMode = this.objectMode || !!options.readableObjectMode;

  // the point at which it stops calling _read() to fill the buffer
  // Note: 0 is a valid value, means "don't call _read preemptively ever"
  var hwm = options.highWaterMark;
  var readableHwm = options.readableHighWaterMark;
  var defaultHwm = this.objectMode ? 16 : 16 * 1024;

  if (hwm || hwm === 0) this.highWaterMark = hwm;else if (isDuplex && (readableHwm || readableHwm === 0)) this.highWaterMark = readableHwm;else this.highWaterMark = defaultHwm;

  // cast to ints.
  this.highWaterMark = Math.floor(this.highWaterMark);

  // A linked list is used to store data chunks instead of an array because the
  // linked list can remove elements from the beginning faster than
  // array.shift()
  this.buffer = new BufferList();
  this.length = 0;
  this.pipes = null;
  this.pipesCount = 0;
  this.flowing = null;
  this.ended = false;
  this.endEmitted = false;
  this.reading = false;

  // a flag to be able to tell if the event 'readable'/'data' is emitted
  // immediately, or on a later tick.  We set this to true at first, because
  // any actions that shouldn't happen until "later" should generally also
  // not happen before the first read call.
  this.sync = true;

  // whenever we return null, then we set a flag to say
  // that we're awaiting a 'readable' event emission.
  this.needReadable = false;
  this.emittedReadable = false;
  this.readableListening = false;
  this.resumeScheduled = false;

  // has it been destroyed
  this.destroyed = false;

  // Crypto is kind of old and crusty.  Historically, its default string
  // encoding is 'binary' so we have to make this configurable.
  // Everything else in the universe uses 'utf8', though.
  this.defaultEncoding = options.defaultEncoding || 'utf8';

  // the number of writers that are awaiting a drain event in .pipe()s
  this.awaitDrain = 0;

  // if true, a maybeReadMore has been scheduled
  this.readingMore = false;

  this.decoder = null;
  this.encoding = null;
  if (options.encoding) {
    if (!StringDecoder) StringDecoder = __webpack_require__(22).StringDecoder;
    this.decoder = new StringDecoder(options.encoding);
    this.encoding = options.encoding;
  }
}

function Readable(options) {
  Duplex = Duplex || __webpack_require__(6);

  if (!(this instanceof Readable)) return new Readable(options);

  this._readableState = new ReadableState(options, this);

  // legacy
  this.readable = true;

  if (options) {
    if (typeof options.read === 'function') this._read = options.read;

    if (typeof options.destroy === 'function') this._destroy = options.destroy;
  }

  Stream.call(this);
}

Object.defineProperty(Readable.prototype, 'destroyed', {
  get: function () {
    if (this._readableState === undefined) {
      return false;
    }
    return this._readableState.destroyed;
  },
  set: function (value) {
    // we ignore the value if the stream
    // has not been initialized yet
    if (!this._readableState) {
      return;
    }

    // backward compatibility, the user is explicitly
    // managing destroyed
    this._readableState.destroyed = value;
  }
});

Readable.prototype.destroy = destroyImpl.destroy;
Readable.prototype._undestroy = destroyImpl.undestroy;
Readable.prototype._destroy = function (err, cb) {
  this.push(null);
  cb(err);
};

// Manually shove something into the read() buffer.
// This returns true if the highWaterMark has not been hit yet,
// similar to how Writable.write() returns true if you should
// write() some more.
Readable.prototype.push = function (chunk, encoding) {
  var state = this._readableState;
  var skipChunkCheck;

  if (!state.objectMode) {
    if (typeof chunk === 'string') {
      encoding = encoding || state.defaultEncoding;
      if (encoding !== state.encoding) {
        chunk = Buffer.from(chunk, encoding);
        encoding = '';
      }
      skipChunkCheck = true;
    }
  } else {
    skipChunkCheck = true;
  }

  return readableAddChunk(this, chunk, encoding, false, skipChunkCheck);
};

// Unshift should *always* be something directly out of read()
Readable.prototype.unshift = function (chunk) {
  return readableAddChunk(this, chunk, null, true, false);
};

function readableAddChunk(stream, chunk, encoding, addToFront, skipChunkCheck) {
  var state = stream._readableState;
  if (chunk === null) {
    state.reading = false;
    onEofChunk(stream, state);
  } else {
    var er;
    if (!skipChunkCheck) er = chunkInvalid(state, chunk);
    if (er) {
      stream.emit('error', er);
    } else if (state.objectMode || chunk && chunk.length > 0) {
      if (typeof chunk !== 'string' && !state.objectMode && Object.getPrototypeOf(chunk) !== Buffer.prototype) {
        chunk = _uint8ArrayToBuffer(chunk);
      }

      if (addToFront) {
        if (state.endEmitted) stream.emit('error', new Error('stream.unshift() after end event'));else addChunk(stream, state, chunk, true);
      } else if (state.ended) {
        stream.emit('error', new Error('stream.push() after EOF'));
      } else {
        state.reading = false;
        if (state.decoder && !encoding) {
          chunk = state.decoder.write(chunk);
          if (state.objectMode || chunk.length !== 0) addChunk(stream, state, chunk, false);else maybeReadMore(stream, state);
        } else {
          addChunk(stream, state, chunk, false);
        }
      }
    } else if (!addToFront) {
      state.reading = false;
    }
  }

  return needMoreData(state);
}

function addChunk(stream, state, chunk, addToFront) {
  if (state.flowing && state.length === 0 && !state.sync) {
    stream.emit('data', chunk);
    stream.read(0);
  } else {
    // update the buffer info.
    state.length += state.objectMode ? 1 : chunk.length;
    if (addToFront) state.buffer.unshift(chunk);else state.buffer.push(chunk);

    if (state.needReadable) emitReadable(stream);
  }
  maybeReadMore(stream, state);
}

function chunkInvalid(state, chunk) {
  var er;
  if (!_isUint8Array(chunk) && typeof chunk !== 'string' && chunk !== undefined && !state.objectMode) {
    er = new TypeError('Invalid non-string/buffer chunk');
  }
  return er;
}

// if it's past the high water mark, we can push in some more.
// Also, if we have no data yet, we can stand some
// more bytes.  This is to work around cases where hwm=0,
// such as the repl.  Also, if the push() triggered a
// readable event, and the user called read(largeNumber) such that
// needReadable was set, then we ought to push more, so that another
// 'readable' event will be triggered.
function needMoreData(state) {
  return !state.ended && (state.needReadable || state.length < state.highWaterMark || state.length === 0);
}

Readable.prototype.isPaused = function () {
  return this._readableState.flowing === false;
};

// backwards compatibility.
Readable.prototype.setEncoding = function (enc) {
  if (!StringDecoder) StringDecoder = __webpack_require__(22).StringDecoder;
  this._readableState.decoder = new StringDecoder(enc);
  this._readableState.encoding = enc;
  return this;
};

// Don't raise the hwm > 8MB
var MAX_HWM = 0x800000;
function computeNewHighWaterMark(n) {
  if (n >= MAX_HWM) {
    n = MAX_HWM;
  } else {
    // Get the next highest power of 2 to prevent increasing hwm excessively in
    // tiny amounts
    n--;
    n |= n >>> 1;
    n |= n >>> 2;
    n |= n >>> 4;
    n |= n >>> 8;
    n |= n >>> 16;
    n++;
  }
  return n;
}

// This function is designed to be inlinable, so please take care when making
// changes to the function body.
function howMuchToRead(n, state) {
  if (n <= 0 || state.length === 0 && state.ended) return 0;
  if (state.objectMode) return 1;
  if (n !== n) {
    // Only flow one buffer at a time
    if (state.flowing && state.length) return state.buffer.head.data.length;else return state.length;
  }
  // If we're asking for more than the current hwm, then raise the hwm.
  if (n > state.highWaterMark) state.highWaterMark = computeNewHighWaterMark(n);
  if (n <= state.length) return n;
  // Don't have enough
  if (!state.ended) {
    state.needReadable = true;
    return 0;
  }
  return state.length;
}

// you can override either this method, or the async _read(n) below.
Readable.prototype.read = function (n) {
  debug('read', n);
  n = parseInt(n, 10);
  var state = this._readableState;
  var nOrig = n;

  if (n !== 0) state.emittedReadable = false;

  // if we're doing read(0) to trigger a readable event, but we
  // already have a bunch of data in the buffer, then just trigger
  // the 'readable' event and move on.
  if (n === 0 && state.needReadable && (state.length >= state.highWaterMark || state.ended)) {
    debug('read: emitReadable', state.length, state.ended);
    if (state.length === 0 && state.ended) endReadable(this);else emitReadable(this);
    return null;
  }

  n = howMuchToRead(n, state);

  // if we've ended, and we're now clear, then finish it up.
  if (n === 0 && state.ended) {
    if (state.length === 0) endReadable(this);
    return null;
  }

  // All the actual chunk generation logic needs to be
  // *below* the call to _read.  The reason is that in certain
  // synthetic stream cases, such as passthrough streams, _read
  // may be a completely synchronous operation which may change
  // the state of the read buffer, providing enough data when
  // before there was *not* enough.
  //
  // So, the steps are:
  // 1. Figure out what the state of things will be after we do
  // a read from the buffer.
  //
  // 2. If that resulting state will trigger a _read, then call _read.
  // Note that this may be asynchronous, or synchronous.  Yes, it is
  // deeply ugly to write APIs this way, but that still doesn't mean
  // that the Readable class should behave improperly, as streams are
  // designed to be sync/async agnostic.
  // Take note if the _read call is sync or async (ie, if the read call
  // has returned yet), so that we know whether or not it's safe to emit
  // 'readable' etc.
  //
  // 3. Actually pull the requested chunks out of the buffer and return.

  // if we need a readable event, then we need to do some reading.
  var doRead = state.needReadable;
  debug('need readable', doRead);

  // if we currently have less than the highWaterMark, then also read some
  if (state.length === 0 || state.length - n < state.highWaterMark) {
    doRead = true;
    debug('length less than watermark', doRead);
  }

  // however, if we've ended, then there's no point, and if we're already
  // reading, then it's unnecessary.
  if (state.ended || state.reading) {
    doRead = false;
    debug('reading or ended', doRead);
  } else if (doRead) {
    debug('do read');
    state.reading = true;
    state.sync = true;
    // if the length is currently zero, then we *need* a readable event.
    if (state.length === 0) state.needReadable = true;
    // call internal read method
    this._read(state.highWaterMark);
    state.sync = false;
    // If _read pushed data synchronously, then `reading` will be false,
    // and we need to re-evaluate how much data we can return to the user.
    if (!state.reading) n = howMuchToRead(nOrig, state);
  }

  var ret;
  if (n > 0) ret = fromList(n, state);else ret = null;

  if (ret === null) {
    state.needReadable = true;
    n = 0;
  } else {
    state.length -= n;
  }

  if (state.length === 0) {
    // If we have nothing in the buffer, then we want to know
    // as soon as we *do* get something into the buffer.
    if (!state.ended) state.needReadable = true;

    // If we tried to read() past the EOF, then emit end on the next tick.
    if (nOrig !== n && state.ended) endReadable(this);
  }

  if (ret !== null) this.emit('data', ret);

  return ret;
};

function onEofChunk(stream, state) {
  if (state.ended) return;
  if (state.decoder) {
    var chunk = state.decoder.end();
    if (chunk && chunk.length) {
      state.buffer.push(chunk);
      state.length += state.objectMode ? 1 : chunk.length;
    }
  }
  state.ended = true;

  // emit 'readable' now to make sure it gets picked up.
  emitReadable(stream);
}

// Don't emit readable right away in sync mode, because this can trigger
// another read() call => stack overflow.  This way, it might trigger
// a nextTick recursion warning, but that's not so bad.
function emitReadable(stream) {
  var state = stream._readableState;
  state.needReadable = false;
  if (!state.emittedReadable) {
    debug('emitReadable', state.flowing);
    state.emittedReadable = true;
    if (state.sync) pna.nextTick(emitReadable_, stream);else emitReadable_(stream);
  }
}

function emitReadable_(stream) {
  debug('emit readable');
  stream.emit('readable');
  flow(stream);
}

// at this point, the user has presumably seen the 'readable' event,
// and called read() to consume some data.  that may have triggered
// in turn another _read(n) call, in which case reading = true if
// it's in progress.
// However, if we're not ended, or reading, and the length < hwm,
// then go ahead and try to read some more preemptively.
function maybeReadMore(stream, state) {
  if (!state.readingMore) {
    state.readingMore = true;
    pna.nextTick(maybeReadMore_, stream, state);
  }
}

function maybeReadMore_(stream, state) {
  var len = state.length;
  while (!state.reading && !state.flowing && !state.ended && state.length < state.highWaterMark) {
    debug('maybeReadMore read 0');
    stream.read(0);
    if (len === state.length)
      // didn't get any data, stop spinning.
      break;else len = state.length;
  }
  state.readingMore = false;
}

// abstract method.  to be overridden in specific implementation classes.
// call cb(er, data) where data is <= n in length.
// for virtual (non-string, non-buffer) streams, "length" is somewhat
// arbitrary, and perhaps not very meaningful.
Readable.prototype._read = function (n) {
  this.emit('error', new Error('_read() is not implemented'));
};

Readable.prototype.pipe = function (dest, pipeOpts) {
  var src = this;
  var state = this._readableState;

  switch (state.pipesCount) {
    case 0:
      state.pipes = dest;
      break;
    case 1:
      state.pipes = [state.pipes, dest];
      break;
    default:
      state.pipes.push(dest);
      break;
  }
  state.pipesCount += 1;
  debug('pipe count=%d opts=%j', state.pipesCount, pipeOpts);

  var doEnd = (!pipeOpts || pipeOpts.end !== false) && dest !== process.stdout && dest !== process.stderr;

  var endFn = doEnd ? onend : unpipe;
  if (state.endEmitted) pna.nextTick(endFn);else src.once('end', endFn);

  dest.on('unpipe', onunpipe);
  function onunpipe(readable, unpipeInfo) {
    debug('onunpipe');
    if (readable === src) {
      if (unpipeInfo && unpipeInfo.hasUnpiped === false) {
        unpipeInfo.hasUnpiped = true;
        cleanup();
      }
    }
  }

  function onend() {
    debug('onend');
    dest.end();
  }

  // when the dest drains, it reduces the awaitDrain counter
  // on the source.  This would be more elegant with a .once()
  // handler in flow(), but adding and removing repeatedly is
  // too slow.
  var ondrain = pipeOnDrain(src);
  dest.on('drain', ondrain);

  var cleanedUp = false;
  function cleanup() {
    debug('cleanup');
    // cleanup event handlers once the pipe is broken
    dest.removeListener('close', onclose);
    dest.removeListener('finish', onfinish);
    dest.removeListener('drain', ondrain);
    dest.removeListener('error', onerror);
    dest.removeListener('unpipe', onunpipe);
    src.removeListener('end', onend);
    src.removeListener('end', unpipe);
    src.removeListener('data', ondata);

    cleanedUp = true;

    // if the reader is waiting for a drain event from this
    // specific writer, then it would cause it to never start
    // flowing again.
    // So, if this is awaiting a drain, then we just call it now.
    // If we don't know, then assume that we are waiting for one.
    if (state.awaitDrain && (!dest._writableState || dest._writableState.needDrain)) ondrain();
  }

  // If the user pushes more data while we're writing to dest then we'll end up
  // in ondata again. However, we only want to increase awaitDrain once because
  // dest will only emit one 'drain' event for the multiple writes.
  // => Introduce a guard on increasing awaitDrain.
  var increasedAwaitDrain = false;
  src.on('data', ondata);
  function ondata(chunk) {
    debug('ondata');
    increasedAwaitDrain = false;
    var ret = dest.write(chunk);
    if (false === ret && !increasedAwaitDrain) {
      // If the user unpiped during `dest.write()`, it is possible
      // to get stuck in a permanently paused state if that write
      // also returned false.
      // => Check whether `dest` is still a piping destination.
      if ((state.pipesCount === 1 && state.pipes === dest || state.pipesCount > 1 && indexOf(state.pipes, dest) !== -1) && !cleanedUp) {
        debug('false write response, pause', src._readableState.awaitDrain);
        src._readableState.awaitDrain++;
        increasedAwaitDrain = true;
      }
      src.pause();
    }
  }

  // if the dest has an error, then stop piping into it.
  // however, don't suppress the throwing behavior for this.
  function onerror(er) {
    debug('onerror', er);
    unpipe();
    dest.removeListener('error', onerror);
    if (EElistenerCount(dest, 'error') === 0) dest.emit('error', er);
  }

  // Make sure our error handler is attached before userland ones.
  prependListener(dest, 'error', onerror);

  // Both close and finish should trigger unpipe, but only once.
  function onclose() {
    dest.removeListener('finish', onfinish);
    unpipe();
  }
  dest.once('close', onclose);
  function onfinish() {
    debug('onfinish');
    dest.removeListener('close', onclose);
    unpipe();
  }
  dest.once('finish', onfinish);

  function unpipe() {
    debug('unpipe');
    src.unpipe(dest);
  }

  // tell the dest that it's being piped to
  dest.emit('pipe', src);

  // start the flow if it hasn't been started already.
  if (!state.flowing) {
    debug('pipe resume');
    src.resume();
  }

  return dest;
};

function pipeOnDrain(src) {
  return function () {
    var state = src._readableState;
    debug('pipeOnDrain', state.awaitDrain);
    if (state.awaitDrain) state.awaitDrain--;
    if (state.awaitDrain === 0 && EElistenerCount(src, 'data')) {
      state.flowing = true;
      flow(src);
    }
  };
}

Readable.prototype.unpipe = function (dest) {
  var state = this._readableState;
  var unpipeInfo = { hasUnpiped: false };

  // if we're not piping anywhere, then do nothing.
  if (state.pipesCount === 0) return this;

  // just one destination.  most common case.
  if (state.pipesCount === 1) {
    // passed in one, but it's not the right one.
    if (dest && dest !== state.pipes) return this;

    if (!dest) dest = state.pipes;

    // got a match.
    state.pipes = null;
    state.pipesCount = 0;
    state.flowing = false;
    if (dest) dest.emit('unpipe', this, unpipeInfo);
    return this;
  }

  // slow case. multiple pipe destinations.

  if (!dest) {
    // remove all.
    var dests = state.pipes;
    var len = state.pipesCount;
    state.pipes = null;
    state.pipesCount = 0;
    state.flowing = false;

    for (var i = 0; i < len; i++) {
      dests[i].emit('unpipe', this, unpipeInfo);
    }return this;
  }

  // try to find the right one.
  var index = indexOf(state.pipes, dest);
  if (index === -1) return this;

  state.pipes.splice(index, 1);
  state.pipesCount -= 1;
  if (state.pipesCount === 1) state.pipes = state.pipes[0];

  dest.emit('unpipe', this, unpipeInfo);

  return this;
};

// set up data events if they are asked for
// Ensure readable listeners eventually get something
Readable.prototype.on = function (ev, fn) {
  var res = Stream.prototype.on.call(this, ev, fn);

  if (ev === 'data') {
    // Start flowing on next tick if stream isn't explicitly paused
    if (this._readableState.flowing !== false) this.resume();
  } else if (ev === 'readable') {
    var state = this._readableState;
    if (!state.endEmitted && !state.readableListening) {
      state.readableListening = state.needReadable = true;
      state.emittedReadable = false;
      if (!state.reading) {
        pna.nextTick(nReadingNextTick, this);
      } else if (state.length) {
        emitReadable(this);
      }
    }
  }

  return res;
};
Readable.prototype.addListener = Readable.prototype.on;

function nReadingNextTick(self) {
  debug('readable nexttick read 0');
  self.read(0);
}

// pause() and resume() are remnants of the legacy readable stream API
// If the user uses them, then switch into old mode.
Readable.prototype.resume = function () {
  var state = this._readableState;
  if (!state.flowing) {
    debug('resume');
    state.flowing = true;
    resume(this, state);
  }
  return this;
};

function resume(stream, state) {
  if (!state.resumeScheduled) {
    state.resumeScheduled = true;
    pna.nextTick(resume_, stream, state);
  }
}

function resume_(stream, state) {
  if (!state.reading) {
    debug('resume read 0');
    stream.read(0);
  }

  state.resumeScheduled = false;
  state.awaitDrain = 0;
  stream.emit('resume');
  flow(stream);
  if (state.flowing && !state.reading) stream.read(0);
}

Readable.prototype.pause = function () {
  debug('call pause flowing=%j', this._readableState.flowing);
  if (false !== this._readableState.flowing) {
    debug('pause');
    this._readableState.flowing = false;
    this.emit('pause');
  }
  return this;
};

function flow(stream) {
  var state = stream._readableState;
  debug('flow', state.flowing);
  while (state.flowing && stream.read() !== null) {}
}

// wrap an old-style stream as the async data source.
// This is *not* part of the readable stream interface.
// It is an ugly unfortunate mess of history.
Readable.prototype.wrap = function (stream) {
  var _this = this;

  var state = this._readableState;
  var paused = false;

  stream.on('end', function () {
    debug('wrapped end');
    if (state.decoder && !state.ended) {
      var chunk = state.decoder.end();
      if (chunk && chunk.length) _this.push(chunk);
    }

    _this.push(null);
  });

  stream.on('data', function (chunk) {
    debug('wrapped data');
    if (state.decoder) chunk = state.decoder.write(chunk);

    // don't skip over falsy values in objectMode
    if (state.objectMode && (chunk === null || chunk === undefined)) return;else if (!state.objectMode && (!chunk || !chunk.length)) return;

    var ret = _this.push(chunk);
    if (!ret) {
      paused = true;
      stream.pause();
    }
  });

  // proxy all the other methods.
  // important when wrapping filters and duplexes.
  for (var i in stream) {
    if (this[i] === undefined && typeof stream[i] === 'function') {
      this[i] = function (method) {
        return function () {
          return stream[method].apply(stream, arguments);
        };
      }(i);
    }
  }

  // proxy certain important events.
  for (var n = 0; n < kProxyEvents.length; n++) {
    stream.on(kProxyEvents[n], this.emit.bind(this, kProxyEvents[n]));
  }

  // when we try to consume some more bytes, simply unpause the
  // underlying stream.
  this._read = function (n) {
    debug('wrapped _read', n);
    if (paused) {
      paused = false;
      stream.resume();
    }
  };

  return this;
};

Object.defineProperty(Readable.prototype, 'readableHighWaterMark', {
  // making it explicit this property is not enumerable
  // because otherwise some prototype manipulation in
  // userland will fail
  enumerable: false,
  get: function () {
    return this._readableState.highWaterMark;
  }
});

// exposed for testing purposes only.
Readable._fromList = fromList;

// Pluck off n bytes from an array of buffers.
// Length is the combined lengths of all the buffers in the list.
// This function is designed to be inlinable, so please take care when making
// changes to the function body.
function fromList(n, state) {
  // nothing buffered
  if (state.length === 0) return null;

  var ret;
  if (state.objectMode) ret = state.buffer.shift();else if (!n || n >= state.length) {
    // read it all, truncate the list
    if (state.decoder) ret = state.buffer.join('');else if (state.buffer.length === 1) ret = state.buffer.head.data;else ret = state.buffer.concat(state.length);
    state.buffer.clear();
  } else {
    // read part of list
    ret = fromListPartial(n, state.buffer, state.decoder);
  }

  return ret;
}

// Extracts only enough buffered data to satisfy the amount requested.
// This function is designed to be inlinable, so please take care when making
// changes to the function body.
function fromListPartial(n, list, hasStrings) {
  var ret;
  if (n < list.head.data.length) {
    // slice is the same for buffers and strings
    ret = list.head.data.slice(0, n);
    list.head.data = list.head.data.slice(n);
  } else if (n === list.head.data.length) {
    // first chunk is a perfect match
    ret = list.shift();
  } else {
    // result spans more than one buffer
    ret = hasStrings ? copyFromBufferString(n, list) : copyFromBuffer(n, list);
  }
  return ret;
}

// Copies a specified amount of characters from the list of buffered data
// chunks.
// This function is designed to be inlinable, so please take care when making
// changes to the function body.
function copyFromBufferString(n, list) {
  var p = list.head;
  var c = 1;
  var ret = p.data;
  n -= ret.length;
  while (p = p.next) {
    var str = p.data;
    var nb = n > str.length ? str.length : n;
    if (nb === str.length) ret += str;else ret += str.slice(0, n);
    n -= nb;
    if (n === 0) {
      if (nb === str.length) {
        ++c;
        if (p.next) list.head = p.next;else list.head = list.tail = null;
      } else {
        list.head = p;
        p.data = str.slice(nb);
      }
      break;
    }
    ++c;
  }
  list.length -= c;
  return ret;
}

// Copies a specified amount of bytes from the list of buffered data chunks.
// This function is designed to be inlinable, so please take care when making
// changes to the function body.
function copyFromBuffer(n, list) {
  var ret = Buffer.allocUnsafe(n);
  var p = list.head;
  var c = 1;
  p.data.copy(ret);
  n -= p.data.length;
  while (p = p.next) {
    var buf = p.data;
    var nb = n > buf.length ? buf.length : n;
    buf.copy(ret, ret.length - n, 0, nb);
    n -= nb;
    if (n === 0) {
      if (nb === buf.length) {
        ++c;
        if (p.next) list.head = p.next;else list.head = list.tail = null;
      } else {
        list.head = p;
        p.data = buf.slice(nb);
      }
      break;
    }
    ++c;
  }
  list.length -= c;
  return ret;
}

function endReadable(stream) {
  var state = stream._readableState;

  // If we get here before consuming all the bytes, then that is a
  // bug in node.  Should never happen.
  if (state.length > 0) throw new Error('"endReadable()" called on non-empty stream');

  if (!state.endEmitted) {
    state.ended = true;
    pna.nextTick(endReadableNT, state, stream);
  }
}

function endReadableNT(state, stream) {
  // Check that we didn't get one last unshift.
  if (!state.endEmitted && state.length === 0) {
    state.endEmitted = true;
    stream.readable = false;
    stream.emit('end');
  }
}

function indexOf(xs, x) {
  for (var i = 0, l = xs.length; i < l; i++) {
    if (xs[i] === x) return i;
  }
  return -1;
}
/* WEBPACK VAR INJECTION */}.call(exports, __webpack_require__(5), __webpack_require__(9)))

/***/ }),
/* 19 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
// Copyright Joyent, Inc. and other Node contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.

// a transform stream is a readable/writable stream where you do
// something with the data.  Sometimes it's called a "filter",
// but that's not a great name for it, since that implies a thing where
// some bits pass through, and others are simply ignored.  (That would
// be a valid example of a transform, of course.)
//
// While the output is causally related to the input, it's not a
// necessarily symmetric or synchronous transformation.  For example,
// a zlib stream might take multiple plain-text writes(), and then
// emit a single compressed chunk some time in the future.
//
// Here's how this works:
//
// The Transform stream has all the aspects of the readable and writable
// stream classes.  When you write(chunk), that calls _write(chunk,cb)
// internally, and returns false if there's a lot of pending writes
// buffered up.  When you call read(), that calls _read(n) until
// there's enough pending readable data buffered up.
//
// In a transform stream, the written data is placed in a buffer.  When
// _read(n) is called, it transforms the queued up data, calling the
// buffered _write cb's as it consumes chunks.  If consuming a single
// written chunk would result in multiple output chunks, then the first
// outputted bit calls the readcb, and subsequent chunks just go into
// the read buffer, and will cause it to emit 'readable' if necessary.
//
// This way, back-pressure is actually determined by the reading side,
// since _read has to be called to start processing a new chunk.  However,
// a pathological inflate type of transform can cause excessive buffering
// here.  For example, imagine a stream where every byte of input is
// interpreted as an integer from 0-255, and then results in that many
// bytes of output.  Writing the 4 bytes {ff,ff,ff,ff} would result in
// 1kb of data being output.  In this case, you could write a very small
// amount of input, and end up with a very large amount of output.  In
// such a pathological inflating mechanism, there'd be no way to tell
// the system to stop doing the transform.  A single 4MB write could
// cause the system to run out of memory.
//
// However, even in such a pathological case, only a single written chunk
// would be consumed, and then the rest would wait (un-transformed) until
// the results of the previous transformed chunk were consumed.



module.exports = Transform;

var Duplex = __webpack_require__(6);

/*<replacement>*/
var util = __webpack_require__(10);
util.inherits = __webpack_require__(8);
/*</replacement>*/

util.inherits(Transform, Duplex);

function afterTransform(er, data) {
  var ts = this._transformState;
  ts.transforming = false;

  var cb = ts.writecb;

  if (!cb) {
    return this.emit('error', new Error('write callback called multiple times'));
  }

  ts.writechunk = null;
  ts.writecb = null;

  if (data != null) // single equals check for both `null` and `undefined`
    this.push(data);

  cb(er);

  var rs = this._readableState;
  rs.reading = false;
  if (rs.needReadable || rs.length < rs.highWaterMark) {
    this._read(rs.highWaterMark);
  }
}

function Transform(options) {
  if (!(this instanceof Transform)) return new Transform(options);

  Duplex.call(this, options);

  this._transformState = {
    afterTransform: afterTransform.bind(this),
    needTransform: false,
    transforming: false,
    writecb: null,
    writechunk: null,
    writeencoding: null
  };

  // start out asking for a readable event once data is transformed.
  this._readableState.needReadable = true;

  // we have implemented the _read method, and done the other things
  // that Readable wants before the first _read call, so unset the
  // sync guard flag.
  this._readableState.sync = false;

  if (options) {
    if (typeof options.transform === 'function') this._transform = options.transform;

    if (typeof options.flush === 'function') this._flush = options.flush;
  }

  // When the writable side finishes, then flush out anything remaining.
  this.on('prefinish', prefinish);
}

function prefinish() {
  var _this = this;

  if (typeof this._flush === 'function') {
    this._flush(function (er, data) {
      done(_this, er, data);
    });
  } else {
    done(this, null, null);
  }
}

Transform.prototype.push = function (chunk, encoding) {
  this._transformState.needTransform = false;
  return Duplex.prototype.push.call(this, chunk, encoding);
};

// This is the part where you do stuff!
// override this function in implementation classes.
// 'chunk' is an input chunk.
//
// Call `push(newChunk)` to pass along transformed output
// to the readable side.  You may call 'push' zero or more times.
//
// Call `cb(err)` when you are done with this chunk.  If you pass
// an error, then that'll put the hurt on the whole operation.  If you
// never call cb(), then you'll never get another chunk.
Transform.prototype._transform = function (chunk, encoding, cb) {
  throw new Error('_transform() is not implemented');
};

Transform.prototype._write = function (chunk, encoding, cb) {
  var ts = this._transformState;
  ts.writecb = cb;
  ts.writechunk = chunk;
  ts.writeencoding = encoding;
  if (!ts.transforming) {
    var rs = this._readableState;
    if (ts.needTransform || rs.needReadable || rs.length < rs.highWaterMark) this._read(rs.highWaterMark);
  }
};

// Doesn't matter what the args are here.
// _transform does all the work.
// That we got here means that the readable side wants more data.
Transform.prototype._read = function (n) {
  var ts = this._transformState;

  if (ts.writechunk !== null && ts.writecb && !ts.transforming) {
    ts.transforming = true;
    this._transform(ts.writechunk, ts.writeencoding, ts.afterTransform);
  } else {
    // mark that we need a transform, so that any data that comes in
    // will get processed, now that we've asked for it.
    ts.needTransform = true;
  }
};

Transform.prototype._destroy = function (err, cb) {
  var _this2 = this;

  Duplex.prototype._destroy.call(this, err, function (err2) {
    cb(err2);
    _this2.emit('close');
  });
};

function done(stream, er, data) {
  if (er) return stream.emit('error', er);

  if (data != null) // single equals check for both `null` and `undefined`
    stream.push(data);

  // if there's nothing in the write buffer, then that means
  // that nothing more will ever be provided
  if (stream._writableState.length) throw new Error('Calling transform done when ws.length != 0');

  if (stream._transformState.transforming) throw new Error('Calling transform done when still transforming');

  return stream.push(null);
}

/***/ }),
/* 20 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


/*<replacement>*/

var pna = __webpack_require__(11);
/*</replacement>*/

// undocumented cb() API, needed for core, not for public API
function destroy(err, cb) {
  var _this = this;

  var readableDestroyed = this._readableState && this._readableState.destroyed;
  var writableDestroyed = this._writableState && this._writableState.destroyed;

  if (readableDestroyed || writableDestroyed) {
    if (cb) {
      cb(err);
    } else if (err && (!this._writableState || !this._writableState.errorEmitted)) {
      pna.nextTick(emitErrorNT, this, err);
    }
    return this;
  }

  // we set destroyed to true before firing error callbacks in order
  // to make it re-entrance safe in case destroy() is called within callbacks

  if (this._readableState) {
    this._readableState.destroyed = true;
  }

  // if this is a duplex stream mark the writable part as destroyed as well
  if (this._writableState) {
    this._writableState.destroyed = true;
  }

  this._destroy(err || null, function (err) {
    if (!cb && err) {
      pna.nextTick(emitErrorNT, _this, err);
      if (_this._writableState) {
        _this._writableState.errorEmitted = true;
      }
    } else if (cb) {
      cb(err);
    }
  });

  return this;
}

function undestroy() {
  if (this._readableState) {
    this._readableState.destroyed = false;
    this._readableState.reading = false;
    this._readableState.ended = false;
    this._readableState.endEmitted = false;
  }

  if (this._writableState) {
    this._writableState.destroyed = false;
    this._writableState.ended = false;
    this._writableState.ending = false;
    this._writableState.finished = false;
    this._writableState.errorEmitted = false;
  }
}

function emitErrorNT(self, err) {
  self.emit('error', err);
}

module.exports = {
  destroy: destroy,
  undestroy: undestroy
};

/***/ }),
/* 21 */
/***/ (function(module, exports, __webpack_require__) {

module.exports = __webpack_require__(14).EventEmitter;


/***/ }),
/* 22 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
// Copyright Joyent, Inc. and other Node contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.



/*<replacement>*/

var Buffer = __webpack_require__(12).Buffer;
/*</replacement>*/

var isEncoding = Buffer.isEncoding || function (encoding) {
  encoding = '' + encoding;
  switch (encoding && encoding.toLowerCase()) {
    case 'hex':case 'utf8':case 'utf-8':case 'ascii':case 'binary':case 'base64':case 'ucs2':case 'ucs-2':case 'utf16le':case 'utf-16le':case 'raw':
      return true;
    default:
      return false;
  }
};

function _normalizeEncoding(enc) {
  if (!enc) return 'utf8';
  var retried;
  while (true) {
    switch (enc) {
      case 'utf8':
      case 'utf-8':
        return 'utf8';
      case 'ucs2':
      case 'ucs-2':
      case 'utf16le':
      case 'utf-16le':
        return 'utf16le';
      case 'latin1':
      case 'binary':
        return 'latin1';
      case 'base64':
      case 'ascii':
      case 'hex':
        return enc;
      default:
        if (retried) return; // undefined
        enc = ('' + enc).toLowerCase();
        retried = true;
    }
  }
};

// Do not cache `Buffer.isEncoding` when checking encoding names as some
// modules monkey-patch it to support additional encodings
function normalizeEncoding(enc) {
  var nenc = _normalizeEncoding(enc);
  if (typeof nenc !== 'string' && (Buffer.isEncoding === isEncoding || !isEncoding(enc))) throw new Error('Unknown encoding: ' + enc);
  return nenc || enc;
}

// StringDecoder provides an interface for efficiently splitting a series of
// buffers into a series of JS strings without breaking apart multi-byte
// characters.
exports.StringDecoder = StringDecoder;
function StringDecoder(encoding) {
  this.encoding = normalizeEncoding(encoding);
  var nb;
  switch (this.encoding) {
    case 'utf16le':
      this.text = utf16Text;
      this.end = utf16End;
      nb = 4;
      break;
    case 'utf8':
      this.fillLast = utf8FillLast;
      nb = 4;
      break;
    case 'base64':
      this.text = base64Text;
      this.end = base64End;
      nb = 3;
      break;
    default:
      this.write = simpleWrite;
      this.end = simpleEnd;
      return;
  }
  this.lastNeed = 0;
  this.lastTotal = 0;
  this.lastChar = Buffer.allocUnsafe(nb);
}

StringDecoder.prototype.write = function (buf) {
  if (buf.length === 0) return '';
  var r;
  var i;
  if (this.lastNeed) {
    r = this.fillLast(buf);
    if (r === undefined) return '';
    i = this.lastNeed;
    this.lastNeed = 0;
  } else {
    i = 0;
  }
  if (i < buf.length) return r ? r + this.text(buf, i) : this.text(buf, i);
  return r || '';
};

StringDecoder.prototype.end = utf8End;

// Returns only complete characters in a Buffer
StringDecoder.prototype.text = utf8Text;

// Attempts to complete a partial non-UTF-8 character using bytes from a Buffer
StringDecoder.prototype.fillLast = function (buf) {
  if (this.lastNeed <= buf.length) {
    buf.copy(this.lastChar, this.lastTotal - this.lastNeed, 0, this.lastNeed);
    return this.lastChar.toString(this.encoding, 0, this.lastTotal);
  }
  buf.copy(this.lastChar, this.lastTotal - this.lastNeed, 0, buf.length);
  this.lastNeed -= buf.length;
};

// Checks the type of a UTF-8 byte, whether it's ASCII, a leading byte, or a
// continuation byte. If an invalid byte is detected, -2 is returned.
function utf8CheckByte(byte) {
  if (byte <= 0x7F) return 0;else if (byte >> 5 === 0x06) return 2;else if (byte >> 4 === 0x0E) return 3;else if (byte >> 3 === 0x1E) return 4;
  return byte >> 6 === 0x02 ? -1 : -2;
}

// Checks at most 3 bytes at the end of a Buffer in order to detect an
// incomplete multi-byte UTF-8 character. The total number of bytes (2, 3, or 4)
// needed to complete the UTF-8 character (if applicable) are returned.
function utf8CheckIncomplete(self, buf, i) {
  var j = buf.length - 1;
  if (j < i) return 0;
  var nb = utf8CheckByte(buf[j]);
  if (nb >= 0) {
    if (nb > 0) self.lastNeed = nb - 1;
    return nb;
  }
  if (--j < i || nb === -2) return 0;
  nb = utf8CheckByte(buf[j]);
  if (nb >= 0) {
    if (nb > 0) self.lastNeed = nb - 2;
    return nb;
  }
  if (--j < i || nb === -2) return 0;
  nb = utf8CheckByte(buf[j]);
  if (nb >= 0) {
    if (nb > 0) {
      if (nb === 2) nb = 0;else self.lastNeed = nb - 3;
    }
    return nb;
  }
  return 0;
}

// Validates as many continuation bytes for a multi-byte UTF-8 character as
// needed or are available. If we see a non-continuation byte where we expect
// one, we "replace" the validated continuation bytes we've seen so far with
// a single UTF-8 replacement character ('\ufffd'), to match v8's UTF-8 decoding
// behavior. The continuation byte check is included three times in the case
// where all of the continuation bytes for a character exist in the same buffer.
// It is also done this way as a slight performance increase instead of using a
// loop.
function utf8CheckExtraBytes(self, buf, p) {
  if ((buf[0] & 0xC0) !== 0x80) {
    self.lastNeed = 0;
    return '\ufffd';
  }
  if (self.lastNeed > 1 && buf.length > 1) {
    if ((buf[1] & 0xC0) !== 0x80) {
      self.lastNeed = 1;
      return '\ufffd';
    }
    if (self.lastNeed > 2 && buf.length > 2) {
      if ((buf[2] & 0xC0) !== 0x80) {
        self.lastNeed = 2;
        return '\ufffd';
      }
    }
  }
}

// Attempts to complete a multi-byte UTF-8 character using bytes from a Buffer.
function utf8FillLast(buf) {
  var p = this.lastTotal - this.lastNeed;
  var r = utf8CheckExtraBytes(this, buf, p);
  if (r !== undefined) return r;
  if (this.lastNeed <= buf.length) {
    buf.copy(this.lastChar, p, 0, this.lastNeed);
    return this.lastChar.toString(this.encoding, 0, this.lastTotal);
  }
  buf.copy(this.lastChar, p, 0, buf.length);
  this.lastNeed -= buf.length;
}

// Returns all complete UTF-8 characters in a Buffer. If the Buffer ended on a
// partial character, the character's bytes are buffered until the required
// number of bytes are available.
function utf8Text(buf, i) {
  var total = utf8CheckIncomplete(this, buf, i);
  if (!this.lastNeed) return buf.toString('utf8', i);
  this.lastTotal = total;
  var end = buf.length - (total - this.lastNeed);
  buf.copy(this.lastChar, 0, end);
  return buf.toString('utf8', i, end);
}

// For UTF-8, a replacement character is added when ending on a partial
// character.
function utf8End(buf) {
  var r = buf && buf.length ? this.write(buf) : '';
  if (this.lastNeed) return r + '\ufffd';
  return r;
}

// UTF-16LE typically needs two bytes per character, but even if we have an even
// number of bytes available, we need to check if we end on a leading/high
// surrogate. In that case, we need to wait for the next two bytes in order to
// decode the last character properly.
function utf16Text(buf, i) {
  if ((buf.length - i) % 2 === 0) {
    var r = buf.toString('utf16le', i);
    if (r) {
      var c = r.charCodeAt(r.length - 1);
      if (c >= 0xD800 && c <= 0xDBFF) {
        this.lastNeed = 2;
        this.lastTotal = 4;
        this.lastChar[0] = buf[buf.length - 2];
        this.lastChar[1] = buf[buf.length - 1];
        return r.slice(0, -1);
      }
    }
    return r;
  }
  this.lastNeed = 1;
  this.lastTotal = 2;
  this.lastChar[0] = buf[buf.length - 1];
  return buf.toString('utf16le', i, buf.length - 1);
}

// For UTF-16LE we do not explicitly append special replacement characters if we
// end on a partial character, we simply let v8 handle that.
function utf16End(buf) {
  var r = buf && buf.length ? this.write(buf) : '';
  if (this.lastNeed) {
    var end = this.lastTotal - this.lastNeed;
    return r + this.lastChar.toString('utf16le', 0, end);
  }
  return r;
}

function base64Text(buf, i) {
  var n = (buf.length - i) % 3;
  if (n === 0) return buf.toString('base64', i);
  this.lastNeed = 3 - n;
  this.lastTotal = 3;
  if (n === 1) {
    this.lastChar[0] = buf[buf.length - 1];
  } else {
    this.lastChar[0] = buf[buf.length - 2];
    this.lastChar[1] = buf[buf.length - 1];
  }
  return buf.toString('base64', i, buf.length - n);
}

function base64End(buf) {
  var r = buf && buf.length ? this.write(buf) : '';
  if (this.lastNeed) return r + this.lastChar.toString('base64', 0, 3 - this.lastNeed);
  return r;
}

// Pass bytes on through for single-byte encodings (e.g. ascii, latin1, hex)
function simpleWrite(buf) {
  return buf.toString(this.encoding);
}

function simpleEnd(buf) {
  return buf && buf.length ? this.write(buf) : '';
}

/***/ }),
/* 23 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/acquisition.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Satellite acquisition messages from the device.
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;
var GnssSignal = __webpack_require__(0).GnssSignal;
var GnssSignalDep = __webpack_require__(0).GnssSignalDep;
var GPSTime = __webpack_require__(0).GPSTime;
var CarrierPhase = __webpack_require__(0).CarrierPhase;
var GPSTime = __webpack_require__(0).GPSTime;
var GPSTimeSec = __webpack_require__(0).GPSTimeSec;
var GPSTimeDep = __webpack_require__(0).GPSTimeDep;

/**
 * SBP class for message MSG_ACQ_RESULT (0x002F).
 *
 * This message describes the results from an attempted GPS signal acquisition
 * search for a satellite PRN over a code phase/carrier frequency range. It
 * contains the parameters of the point in the acquisition search space with the
 * best carrier-to-noise (CN/0) ratio.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field cn0 number (float, 4 bytes) CN/0 of best point
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
MsgAcqResult.prototype.msg_type = 0x002F;
MsgAcqResult.prototype.constructor = MsgAcqResult;
MsgAcqResult.prototype.parser = new Parser()
  .endianess('little')
  .floatle('cn0')
  .floatle('cp')
  .floatle('cf')
  .nest('sid', { type: GnssSignal.prototype.parser });
MsgAcqResult.prototype.fieldSpec = [];
MsgAcqResult.prototype.fieldSpec.push(['cn0', 'writeFloatLE', 4]);
MsgAcqResult.prototype.fieldSpec.push(['cp', 'writeFloatLE', 4]);
MsgAcqResult.prototype.fieldSpec.push(['cf', 'writeFloatLE', 4]);
MsgAcqResult.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);

/**
 * SBP class for message MSG_ACQ_RESULT_DEP_C (0x001F).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field cn0 number (float, 4 bytes) CN/0 of best point
 * @field cp number (float, 4 bytes) Code phase of best point
 * @field cf number (float, 4 bytes) Carrier frequency of best point
 * @field sid GnssSignalDep GNSS signal for which acquisition was attempted
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAcqResultDepC = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ACQ_RESULT_DEP_C";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAcqResultDepC.prototype = Object.create(SBP.prototype);
MsgAcqResultDepC.prototype.messageType = "MSG_ACQ_RESULT_DEP_C";
MsgAcqResultDepC.prototype.msg_type = 0x001F;
MsgAcqResultDepC.prototype.constructor = MsgAcqResultDepC;
MsgAcqResultDepC.prototype.parser = new Parser()
  .endianess('little')
  .floatle('cn0')
  .floatle('cp')
  .floatle('cf')
  .nest('sid', { type: GnssSignalDep.prototype.parser });
MsgAcqResultDepC.prototype.fieldSpec = [];
MsgAcqResultDepC.prototype.fieldSpec.push(['cn0', 'writeFloatLE', 4]);
MsgAcqResultDepC.prototype.fieldSpec.push(['cp', 'writeFloatLE', 4]);
MsgAcqResultDepC.prototype.fieldSpec.push(['cf', 'writeFloatLE', 4]);
MsgAcqResultDepC.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);

/**
 * SBP class for message MSG_ACQ_RESULT_DEP_B (0x0014).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field snr number (float, 4 bytes) SNR of best point. Currently in arbitrary SNR points, but will be in units of dB
 *   Hz in a later revision of this message.
 * @field cp number (float, 4 bytes) Code phase of best point
 * @field cf number (float, 4 bytes) Carrier frequency of best point
 * @field sid GnssSignalDep GNSS signal for which acquisition was attempted
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAcqResultDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ACQ_RESULT_DEP_B";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAcqResultDepB.prototype = Object.create(SBP.prototype);
MsgAcqResultDepB.prototype.messageType = "MSG_ACQ_RESULT_DEP_B";
MsgAcqResultDepB.prototype.msg_type = 0x0014;
MsgAcqResultDepB.prototype.constructor = MsgAcqResultDepB;
MsgAcqResultDepB.prototype.parser = new Parser()
  .endianess('little')
  .floatle('snr')
  .floatle('cp')
  .floatle('cf')
  .nest('sid', { type: GnssSignalDep.prototype.parser });
MsgAcqResultDepB.prototype.fieldSpec = [];
MsgAcqResultDepB.prototype.fieldSpec.push(['snr', 'writeFloatLE', 4]);
MsgAcqResultDepB.prototype.fieldSpec.push(['cp', 'writeFloatLE', 4]);
MsgAcqResultDepB.prototype.fieldSpec.push(['cf', 'writeFloatLE', 4]);
MsgAcqResultDepB.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);

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
 * SBP class for message fragment AcqSvProfileDep
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field job_type number (unsigned 8-bit int, 1 byte) SV search job type (deep, fallback, etc)
 * @field status number (unsigned 8-bit int, 1 byte) Acquisition status 1 is Success, 0 is Failure
 * @field cn0 number (unsigned 16-bit int, 2 bytes) CN0 value. Only valid if status is '1'
 * @field int_time number (unsigned 8-bit int, 1 byte) Acquisition integration time
 * @field sid GnssSignalDep GNSS signal for which acquisition was attempted
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
var AcqSvProfileDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "AcqSvProfileDep";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
AcqSvProfileDep.prototype = Object.create(SBP.prototype);
AcqSvProfileDep.prototype.messageType = "AcqSvProfileDep";
AcqSvProfileDep.prototype.constructor = AcqSvProfileDep;
AcqSvProfileDep.prototype.parser = new Parser()
  .endianess('little')
  .uint8('job_type')
  .uint8('status')
  .uint16('cn0')
  .uint8('int_time')
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .uint16('bin_width')
  .uint32('timestamp')
  .uint32('time_spent')
  .int32('cf_min')
  .int32('cf_max')
  .int32('cf')
  .uint32('cp');
AcqSvProfileDep.prototype.fieldSpec = [];
AcqSvProfileDep.prototype.fieldSpec.push(['job_type', 'writeUInt8', 1]);
AcqSvProfileDep.prototype.fieldSpec.push(['status', 'writeUInt8', 1]);
AcqSvProfileDep.prototype.fieldSpec.push(['cn0', 'writeUInt16LE', 2]);
AcqSvProfileDep.prototype.fieldSpec.push(['int_time', 'writeUInt8', 1]);
AcqSvProfileDep.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
AcqSvProfileDep.prototype.fieldSpec.push(['bin_width', 'writeUInt16LE', 2]);
AcqSvProfileDep.prototype.fieldSpec.push(['timestamp', 'writeUInt32LE', 4]);
AcqSvProfileDep.prototype.fieldSpec.push(['time_spent', 'writeUInt32LE', 4]);
AcqSvProfileDep.prototype.fieldSpec.push(['cf_min', 'writeInt32LE', 4]);
AcqSvProfileDep.prototype.fieldSpec.push(['cf_max', 'writeInt32LE', 4]);
AcqSvProfileDep.prototype.fieldSpec.push(['cf', 'writeInt32LE', 4]);
AcqSvProfileDep.prototype.fieldSpec.push(['cp', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_ACQ_SV_PROFILE (0x002E).
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
MsgAcqSvProfile.prototype.msg_type = 0x002E;
MsgAcqSvProfile.prototype.constructor = MsgAcqSvProfile;
MsgAcqSvProfile.prototype.parser = new Parser()
  .endianess('little')
  .array('acq_sv_profile', { type: AcqSvProfile.prototype.parser, readUntil: 'eof' });
MsgAcqSvProfile.prototype.fieldSpec = [];
MsgAcqSvProfile.prototype.fieldSpec.push(['acq_sv_profile', 'array', AcqSvProfile.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_ACQ_SV_PROFILE_DEP (0x001E).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field acq_sv_profile array SV profiles during acquisition time
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAcqSvProfileDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ACQ_SV_PROFILE_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAcqSvProfileDep.prototype = Object.create(SBP.prototype);
MsgAcqSvProfileDep.prototype.messageType = "MSG_ACQ_SV_PROFILE_DEP";
MsgAcqSvProfileDep.prototype.msg_type = 0x001E;
MsgAcqSvProfileDep.prototype.constructor = MsgAcqSvProfileDep;
MsgAcqSvProfileDep.prototype.parser = new Parser()
  .endianess('little')
  .array('acq_sv_profile', { type: AcqSvProfileDep.prototype.parser, readUntil: 'eof' });
MsgAcqSvProfileDep.prototype.fieldSpec = [];
MsgAcqSvProfileDep.prototype.fieldSpec.push(['acq_sv_profile', 'array', AcqSvProfileDep.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

module.exports = {
  0x002F: MsgAcqResult,
  MsgAcqResult: MsgAcqResult,
  0x001F: MsgAcqResultDepC,
  MsgAcqResultDepC: MsgAcqResultDepC,
  0x0014: MsgAcqResultDepB,
  MsgAcqResultDepB: MsgAcqResultDepB,
  0x0015: MsgAcqResultDepA,
  MsgAcqResultDepA: MsgAcqResultDepA,
  AcqSvProfile: AcqSvProfile,
  AcqSvProfileDep: AcqSvProfileDep,
  0x002E: MsgAcqSvProfile,
  MsgAcqSvProfile: MsgAcqSvProfile,
  0x001E: MsgAcqSvProfileDep,
  MsgAcqSvProfileDep: MsgAcqSvProfileDep,
}

/***/ }),
/* 24 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/bootload.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages for the bootloading configuration of a Piksi 2.3.1.  This message group
 * does not apply to Piksi Multi.  Note that some of these messages share the same
 * message type ID for both the host request and the device response.
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;

/**
 * SBP class for message MSG_BOOTLOADER_HANDSHAKE_REQ (0x00B3).
 *
 * The handshake message request from the host establishes a handshake between the
 * device bootloader and the host. The response from the device is
 * MSG_BOOTLOADER_HANDSHAKE_RESP.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBootloaderHandshakeReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BOOTLOADER_HANDSHAKE_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBootloaderHandshakeReq.prototype = Object.create(SBP.prototype);
MsgBootloaderHandshakeReq.prototype.messageType = "MSG_BOOTLOADER_HANDSHAKE_REQ";
MsgBootloaderHandshakeReq.prototype.msg_type = 0x00B3;
MsgBootloaderHandshakeReq.prototype.constructor = MsgBootloaderHandshakeReq;
MsgBootloaderHandshakeReq.prototype.parser = new Parser()
  .endianess('little');
MsgBootloaderHandshakeReq.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_BOOTLOADER_HANDSHAKE_RESP (0x00B4).
 *
 * The handshake message response from the device establishes a handshake between
 * the device bootloader and the host. The request from the host is
 * MSG_BOOTLOADER_HANDSHAKE_REQ.  The payload contains the bootloader version
 * number and the SBP protocol version number.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field flags number (unsigned 32-bit int, 4 bytes) Bootloader flags
 * @field version string Bootloader version number
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBootloaderHandshakeResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BOOTLOADER_HANDSHAKE_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBootloaderHandshakeResp.prototype = Object.create(SBP.prototype);
MsgBootloaderHandshakeResp.prototype.messageType = "MSG_BOOTLOADER_HANDSHAKE_RESP";
MsgBootloaderHandshakeResp.prototype.msg_type = 0x00B4;
MsgBootloaderHandshakeResp.prototype.constructor = MsgBootloaderHandshakeResp;
MsgBootloaderHandshakeResp.prototype.parser = new Parser()
  .endianess('little')
  .uint32('flags')
  .string('version', { greedy: true });
MsgBootloaderHandshakeResp.prototype.fieldSpec = [];
MsgBootloaderHandshakeResp.prototype.fieldSpec.push(['flags', 'writeUInt32LE', 4]);
MsgBootloaderHandshakeResp.prototype.fieldSpec.push(['version', 'string', null]);

/**
 * SBP class for message MSG_BOOTLOADER_JUMP_TO_APP (0x00B1).
 *
 * The host initiates the bootloader to jump to the application.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field jump number (unsigned 8-bit int, 1 byte) Ignored by the device
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBootloaderJumpToApp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BOOTLOADER_JUMP_TO_APP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBootloaderJumpToApp.prototype = Object.create(SBP.prototype);
MsgBootloaderJumpToApp.prototype.messageType = "MSG_BOOTLOADER_JUMP_TO_APP";
MsgBootloaderJumpToApp.prototype.msg_type = 0x00B1;
MsgBootloaderJumpToApp.prototype.constructor = MsgBootloaderJumpToApp;
MsgBootloaderJumpToApp.prototype.parser = new Parser()
  .endianess('little')
  .uint8('jump');
MsgBootloaderJumpToApp.prototype.fieldSpec = [];
MsgBootloaderJumpToApp.prototype.fieldSpec.push(['jump', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_NAP_DEVICE_DNA_REQ (0x00DE).
 *
 * The device message from the host reads a unique device identifier from the
 * SwiftNAP, an FPGA. The host requests the ID by sending a MSG_NAP_DEVICE_DNA_REQ
 * message. The device responds with a MSG_NAP_DEVICE_DNA_RESP message with the
 * device ID in the payload. Note that this ID is tied to the FPGA, and not related
 * to the Piksi's serial number.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgNapDeviceDnaReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_NAP_DEVICE_DNA_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgNapDeviceDnaReq.prototype = Object.create(SBP.prototype);
MsgNapDeviceDnaReq.prototype.messageType = "MSG_NAP_DEVICE_DNA_REQ";
MsgNapDeviceDnaReq.prototype.msg_type = 0x00DE;
MsgNapDeviceDnaReq.prototype.constructor = MsgNapDeviceDnaReq;
MsgNapDeviceDnaReq.prototype.parser = new Parser()
  .endianess('little');
MsgNapDeviceDnaReq.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_NAP_DEVICE_DNA_RESP (0x00DD).
 *
 * The device message from the host reads a unique device identifier from the
 * SwiftNAP, an FPGA. The host requests the ID by sending a MSG_NAP_DEVICE_DNA_REQ
 * message. The device responds with a MSG_NAP_DEVICE_DNA_RESP messagage with the
 * device ID in the payload. Note that this ID is tied to the FPGA, and not related
 * to the Piksi's serial number.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field dna array 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the right.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgNapDeviceDnaResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_NAP_DEVICE_DNA_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgNapDeviceDnaResp.prototype = Object.create(SBP.prototype);
MsgNapDeviceDnaResp.prototype.messageType = "MSG_NAP_DEVICE_DNA_RESP";
MsgNapDeviceDnaResp.prototype.msg_type = 0x00DD;
MsgNapDeviceDnaResp.prototype.constructor = MsgNapDeviceDnaResp;
MsgNapDeviceDnaResp.prototype.parser = new Parser()
  .endianess('little')
  .array('dna', { length: 8, type: 'uint8' });
MsgNapDeviceDnaResp.prototype.fieldSpec = [];
MsgNapDeviceDnaResp.prototype.fieldSpec.push(['dna', 'array', 'writeUInt8', function () { return 1; }, 8]);

/**
 * SBP class for message MSG_BOOTLOADER_HANDSHAKE_DEP_A (0x00B0).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field handshake array Version number string (not NULL terminated)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBootloaderHandshakeDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BOOTLOADER_HANDSHAKE_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBootloaderHandshakeDepA.prototype = Object.create(SBP.prototype);
MsgBootloaderHandshakeDepA.prototype.messageType = "MSG_BOOTLOADER_HANDSHAKE_DEP_A";
MsgBootloaderHandshakeDepA.prototype.msg_type = 0x00B0;
MsgBootloaderHandshakeDepA.prototype.constructor = MsgBootloaderHandshakeDepA;
MsgBootloaderHandshakeDepA.prototype.parser = new Parser()
  .endianess('little')
  .array('handshake', { type: 'uint8', readUntil: 'eof' });
MsgBootloaderHandshakeDepA.prototype.fieldSpec = [];
MsgBootloaderHandshakeDepA.prototype.fieldSpec.push(['handshake', 'array', 'writeUInt8', function () { return 1; }, null]);

module.exports = {
  0x00B3: MsgBootloaderHandshakeReq,
  MsgBootloaderHandshakeReq: MsgBootloaderHandshakeReq,
  0x00B4: MsgBootloaderHandshakeResp,
  MsgBootloaderHandshakeResp: MsgBootloaderHandshakeResp,
  0x00B1: MsgBootloaderJumpToApp,
  MsgBootloaderJumpToApp: MsgBootloaderJumpToApp,
  0x00DE: MsgNapDeviceDnaReq,
  MsgNapDeviceDnaReq: MsgNapDeviceDnaReq,
  0x00DD: MsgNapDeviceDnaResp,
  MsgNapDeviceDnaResp: MsgNapDeviceDnaResp,
  0x00B0: MsgBootloaderHandshakeDepA,
  MsgBootloaderHandshakeDepA: MsgBootloaderHandshakeDepA,
}

/***/ }),
/* 25 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/ext_events.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages reporting accurately-timestamped external events, e.g. camera shutter
 * time.
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;

/**
 * SBP class for message MSG_EXT_EVENT (0x0101).
 *
 * Reports detection of an external event, the GPS time it occurred, which pin it
 * was and whether it was rising or falling.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field wn number (unsigned 16-bit int, 2 bytes) GPS week number
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS time of week rounded to the nearest millisecond
 * @field ns_residual number (signed 32-bit int, 4 bytes) Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000)
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
  .int32('ns_residual')
  .uint8('flags')
  .uint8('pin');
MsgExtEvent.prototype.fieldSpec = [];
MsgExtEvent.prototype.fieldSpec.push(['wn', 'writeUInt16LE', 2]);
MsgExtEvent.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgExtEvent.prototype.fieldSpec.push(['ns_residual', 'writeInt32LE', 4]);
MsgExtEvent.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);
MsgExtEvent.prototype.fieldSpec.push(['pin', 'writeUInt8', 1]);

module.exports = {
  0x0101: MsgExtEvent,
  MsgExtEvent: MsgExtEvent,
}

/***/ }),
/* 26 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/file_io.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages for using device's onboard flash filesystem functionality. This allows
 * data to be stored persistently in the device's program flash with wear-levelling
 * using a simple filesystem interface. The file system interface (CFS) defines an
 * abstract API for reading directories and for reading and writing files.  Note
 * that some of these messages share the same message type ID for both the host
 * request and the device response.
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;

/**
 * SBP class for message MSG_FILEIO_READ_REQ (0x00A8).
 *
 * The file read message reads a certain length (up to 255 bytes) from a given
 * offset into a file, and returns the data in a MSG_FILEIO_READ_RESP message where
 * the message length field indicates how many bytes were succesfully read.The
 * sequence number in the request will be returned in the response. If the message
 * is invalid, a followup MSG_PRINT message will print "Invalid fileio read
 * message". A device will only respond to this message when it is received from
 * sender ID 0x42.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Read sequence number
 * @field offset number (unsigned 32-bit int, 4 bytes) File offset
 * @field chunk_size number (unsigned 8-bit int, 1 byte) Chunk size to read
 * @field filename string Name of the file to read from
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFileioReadReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FILEIO_READ_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFileioReadReq.prototype = Object.create(SBP.prototype);
MsgFileioReadReq.prototype.messageType = "MSG_FILEIO_READ_REQ";
MsgFileioReadReq.prototype.msg_type = 0x00A8;
MsgFileioReadReq.prototype.constructor = MsgFileioReadReq;
MsgFileioReadReq.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence')
  .uint32('offset')
  .uint8('chunk_size')
  .string('filename', { greedy: true });
MsgFileioReadReq.prototype.fieldSpec = [];
MsgFileioReadReq.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgFileioReadReq.prototype.fieldSpec.push(['offset', 'writeUInt32LE', 4]);
MsgFileioReadReq.prototype.fieldSpec.push(['chunk_size', 'writeUInt8', 1]);
MsgFileioReadReq.prototype.fieldSpec.push(['filename', 'string', null]);

/**
 * SBP class for message MSG_FILEIO_READ_RESP (0x00A3).
 *
 * The file read message reads a certain length (up to 255 bytes) from a given
 * offset into a file, and returns the data in a message where the message length
 * field indicates how many bytes were succesfully read. The sequence number in the
 * response is preserved from the request.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Read sequence number
 * @field contents array Contents of read file
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFileioReadResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FILEIO_READ_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFileioReadResp.prototype = Object.create(SBP.prototype);
MsgFileioReadResp.prototype.messageType = "MSG_FILEIO_READ_RESP";
MsgFileioReadResp.prototype.msg_type = 0x00A3;
MsgFileioReadResp.prototype.constructor = MsgFileioReadResp;
MsgFileioReadResp.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence')
  .array('contents', { type: 'uint8', readUntil: 'eof' });
MsgFileioReadResp.prototype.fieldSpec = [];
MsgFileioReadResp.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgFileioReadResp.prototype.fieldSpec.push(['contents', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_FILEIO_READ_DIR_REQ (0x00A9).
 *
 * The read directory message lists the files in a directory on the device's
 * onboard flash file system.  The offset parameter can be used to skip the first n
 * elements of the file list. Returns a MSG_FILEIO_READ_DIR_RESP message containing
 * the directory listings as a NULL delimited list. The listing is chunked over
 * multiple SBP packets. The sequence number in the request will be returned in the
 * response.  If message is invalid, a followup MSG_PRINT message will print
 * "Invalid fileio read message". A device will only respond to this message when
 * it is received from sender ID 0x42.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Read sequence number
 * @field offset number (unsigned 32-bit int, 4 bytes) The offset to skip the first n elements of the file list
 * @field dirname string Name of the directory to list
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFileioReadDirReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FILEIO_READ_DIR_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFileioReadDirReq.prototype = Object.create(SBP.prototype);
MsgFileioReadDirReq.prototype.messageType = "MSG_FILEIO_READ_DIR_REQ";
MsgFileioReadDirReq.prototype.msg_type = 0x00A9;
MsgFileioReadDirReq.prototype.constructor = MsgFileioReadDirReq;
MsgFileioReadDirReq.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence')
  .uint32('offset')
  .string('dirname', { greedy: true });
MsgFileioReadDirReq.prototype.fieldSpec = [];
MsgFileioReadDirReq.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgFileioReadDirReq.prototype.fieldSpec.push(['offset', 'writeUInt32LE', 4]);
MsgFileioReadDirReq.prototype.fieldSpec.push(['dirname', 'string', null]);

/**
 * SBP class for message MSG_FILEIO_READ_DIR_RESP (0x00AA).
 *
 * The read directory message lists the files in a directory on the device's
 * onboard flash file system. Message contains the directory listings as a NULL
 * delimited list. The listing is chunked over multiple SBP packets and the end of
 * the list is identified by an entry containing just the character 0xFF. The
 * sequence number in the response is preserved from the request.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Read sequence number
 * @field contents array Contents of read directory
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFileioReadDirResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FILEIO_READ_DIR_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFileioReadDirResp.prototype = Object.create(SBP.prototype);
MsgFileioReadDirResp.prototype.messageType = "MSG_FILEIO_READ_DIR_RESP";
MsgFileioReadDirResp.prototype.msg_type = 0x00AA;
MsgFileioReadDirResp.prototype.constructor = MsgFileioReadDirResp;
MsgFileioReadDirResp.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence')
  .array('contents', { type: 'uint8', readUntil: 'eof' });
MsgFileioReadDirResp.prototype.fieldSpec = [];
MsgFileioReadDirResp.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgFileioReadDirResp.prototype.fieldSpec.push(['contents', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_FILEIO_REMOVE (0x00AC).
 *
 * The file remove message deletes a file from the file system. If the message is
 * invalid, a followup MSG_PRINT message will print "Invalid fileio remove
 * message". A device will only process this message when it is received from
 * sender ID 0x42.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field filename string Name of the file to delete
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFileioRemove = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FILEIO_REMOVE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFileioRemove.prototype = Object.create(SBP.prototype);
MsgFileioRemove.prototype.messageType = "MSG_FILEIO_REMOVE";
MsgFileioRemove.prototype.msg_type = 0x00AC;
MsgFileioRemove.prototype.constructor = MsgFileioRemove;
MsgFileioRemove.prototype.parser = new Parser()
  .endianess('little')
  .string('filename', { greedy: true });
MsgFileioRemove.prototype.fieldSpec = [];
MsgFileioRemove.prototype.fieldSpec.push(['filename', 'string', null]);

/**
 * SBP class for message MSG_FILEIO_WRITE_REQ (0x00AD).
 *
 * The file write message writes a certain length (up to 255 bytes) of data to a
 * file at a given offset. Returns a copy of the original MSG_FILEIO_WRITE_RESP
 * message to check integrity of the write. The sequence number in the request will
 * be returned in the response. If message is invalid, a followup MSG_PRINT message
 * will print "Invalid fileio write message". A device will only  process this
 * message when it is received from sender ID 0x42.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Write sequence number
 * @field offset number (unsigned 32-bit int, 4 bytes) Offset into the file at which to start writing in bytes
 * @field filename string Name of the file to write to
 * @field data array Variable-length array of data to write
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFileioWriteReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FILEIO_WRITE_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFileioWriteReq.prototype = Object.create(SBP.prototype);
MsgFileioWriteReq.prototype.messageType = "MSG_FILEIO_WRITE_REQ";
MsgFileioWriteReq.prototype.msg_type = 0x00AD;
MsgFileioWriteReq.prototype.constructor = MsgFileioWriteReq;
MsgFileioWriteReq.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence')
  .uint32('offset')
  .string('filename', { greedy: true })
  .array('data', { type: 'uint8', readUntil: 'eof' });
MsgFileioWriteReq.prototype.fieldSpec = [];
MsgFileioWriteReq.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgFileioWriteReq.prototype.fieldSpec.push(['offset', 'writeUInt32LE', 4]);
MsgFileioWriteReq.prototype.fieldSpec.push(['filename', 'string', null]);
MsgFileioWriteReq.prototype.fieldSpec.push(['data', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_FILEIO_WRITE_RESP (0x00AB).
 *
 * The file write message writes a certain length (up to 255 bytes) of data to a
 * file at a given offset. The message is a copy of the original
 * MSG_FILEIO_WRITE_REQ message to check integrity of the write. The sequence
 * number in the response is preserved from the request.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Write sequence number
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFileioWriteResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FILEIO_WRITE_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFileioWriteResp.prototype = Object.create(SBP.prototype);
MsgFileioWriteResp.prototype.messageType = "MSG_FILEIO_WRITE_RESP";
MsgFileioWriteResp.prototype.msg_type = 0x00AB;
MsgFileioWriteResp.prototype.constructor = MsgFileioWriteResp;
MsgFileioWriteResp.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence');
MsgFileioWriteResp.prototype.fieldSpec = [];
MsgFileioWriteResp.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);

module.exports = {
  0x00A8: MsgFileioReadReq,
  MsgFileioReadReq: MsgFileioReadReq,
  0x00A3: MsgFileioReadResp,
  MsgFileioReadResp: MsgFileioReadResp,
  0x00A9: MsgFileioReadDirReq,
  MsgFileioReadDirReq: MsgFileioReadDirReq,
  0x00AA: MsgFileioReadDirResp,
  MsgFileioReadDirResp: MsgFileioReadDirResp,
  0x00AC: MsgFileioRemove,
  MsgFileioRemove: MsgFileioRemove,
  0x00AD: MsgFileioWriteReq,
  MsgFileioWriteReq: MsgFileioWriteReq,
  0x00AB: MsgFileioWriteResp,
  MsgFileioWriteResp: MsgFileioWriteResp,
}

/***/ }),
/* 27 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/flash.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages for reading/writing the device's onboard flash memory. Many of these
 * messages target specific flash memory peripherals used in Swift Navigation
 * devices: the STM32 flash and the M25Pxx FPGA configuration flash from Piksi
 * 2.3.1.  This module does not apply  to Piksi Multi.
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;

/**
 * SBP class for message MSG_FLASH_PROGRAM (0x00E6).
 *
 * The flash program message programs a set of addresses of either the STM or M25
 * flash. The device replies with either a MSG_FLASH_DONE message containing the
 * return code FLASH_OK (0) on success, or FLASH_INVALID_LEN (2) if the maximum
 * write size is exceeded. Note that the sector-containing addresses must be erased
 * before addresses can be programmed.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field target number (unsigned 8-bit int, 1 byte) Target flags
 * @field addr_start array Starting address offset to program
 * @field addr_len number (unsigned 8-bit int, 1 byte) Length of set of addresses to program, counting up from starting address
 * @field data array Data to program addresses with, with length N=addr_len
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFlashProgram = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FLASH_PROGRAM";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFlashProgram.prototype = Object.create(SBP.prototype);
MsgFlashProgram.prototype.messageType = "MSG_FLASH_PROGRAM";
MsgFlashProgram.prototype.msg_type = 0x00E6;
MsgFlashProgram.prototype.constructor = MsgFlashProgram;
MsgFlashProgram.prototype.parser = new Parser()
  .endianess('little')
  .uint8('target')
  .array('addr_start', { length: 3, type: 'uint8' })
  .uint8('addr_len')
  .array('data', { type: 'uint8', length: 'addr_len' });
MsgFlashProgram.prototype.fieldSpec = [];
MsgFlashProgram.prototype.fieldSpec.push(['target', 'writeUInt8', 1]);
MsgFlashProgram.prototype.fieldSpec.push(['addr_start', 'array', 'writeUInt8', function () { return 1; }, 3]);
MsgFlashProgram.prototype.fieldSpec.push(['addr_len', 'writeUInt8', 1]);
MsgFlashProgram.prototype.fieldSpec.push(['data', 'array', 'writeUInt8', function () { return 1; }, 'addr_len']);

/**
 * SBP class for message MSG_FLASH_DONE (0x00E0).
 *
 * This message defines success or failure codes for a variety of flash memory
 * requests from the host to the device. Flash read and write messages, such as
 * MSG_FLASH_READ_REQ, or MSG_FLASH_PROGRAM, may return this message on failure.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field response number (unsigned 8-bit int, 1 byte) Response flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFlashDone = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FLASH_DONE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFlashDone.prototype = Object.create(SBP.prototype);
MsgFlashDone.prototype.messageType = "MSG_FLASH_DONE";
MsgFlashDone.prototype.msg_type = 0x00E0;
MsgFlashDone.prototype.constructor = MsgFlashDone;
MsgFlashDone.prototype.parser = new Parser()
  .endianess('little')
  .uint8('response');
MsgFlashDone.prototype.fieldSpec = [];
MsgFlashDone.prototype.fieldSpec.push(['response', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_FLASH_READ_REQ (0x00E7).
 *
 * The flash read message reads a set of addresses of either the STM or M25 onboard
 * flash. The device replies with a MSG_FLASH_READ_RESP message containing either
 * the read data on success or a MSG_FLASH_DONE message containing the return code
 * FLASH_INVALID_LEN (2) if the maximum read size is exceeded or FLASH_INVALID_ADDR
 * (3) if the address is outside of the allowed range.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field target number (unsigned 8-bit int, 1 byte) Target flags
 * @field addr_start array Starting address offset to read from
 * @field addr_len number (unsigned 8-bit int, 1 byte) Length of set of addresses to read, counting up from starting address
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFlashReadReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FLASH_READ_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFlashReadReq.prototype = Object.create(SBP.prototype);
MsgFlashReadReq.prototype.messageType = "MSG_FLASH_READ_REQ";
MsgFlashReadReq.prototype.msg_type = 0x00E7;
MsgFlashReadReq.prototype.constructor = MsgFlashReadReq;
MsgFlashReadReq.prototype.parser = new Parser()
  .endianess('little')
  .uint8('target')
  .array('addr_start', { length: 3, type: 'uint8' })
  .uint8('addr_len');
MsgFlashReadReq.prototype.fieldSpec = [];
MsgFlashReadReq.prototype.fieldSpec.push(['target', 'writeUInt8', 1]);
MsgFlashReadReq.prototype.fieldSpec.push(['addr_start', 'array', 'writeUInt8', function () { return 1; }, 3]);
MsgFlashReadReq.prototype.fieldSpec.push(['addr_len', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_FLASH_READ_RESP (0x00E1).
 *
 * The flash read message reads a set of addresses of either the STM or M25 onboard
 * flash. The device replies with a MSG_FLASH_READ_RESP message containing either
 * the read data on success or a MSG_FLASH_DONE message containing the return code
 * FLASH_INVALID_LEN (2) if the maximum read size is exceeded or FLASH_INVALID_ADDR
 * (3) if the address is outside of the allowed range.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field target number (unsigned 8-bit int, 1 byte) Target flags
 * @field addr_start array Starting address offset to read from
 * @field addr_len number (unsigned 8-bit int, 1 byte) Length of set of addresses to read, counting up from starting address
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFlashReadResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FLASH_READ_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFlashReadResp.prototype = Object.create(SBP.prototype);
MsgFlashReadResp.prototype.messageType = "MSG_FLASH_READ_RESP";
MsgFlashReadResp.prototype.msg_type = 0x00E1;
MsgFlashReadResp.prototype.constructor = MsgFlashReadResp;
MsgFlashReadResp.prototype.parser = new Parser()
  .endianess('little')
  .uint8('target')
  .array('addr_start', { length: 3, type: 'uint8' })
  .uint8('addr_len');
MsgFlashReadResp.prototype.fieldSpec = [];
MsgFlashReadResp.prototype.fieldSpec.push(['target', 'writeUInt8', 1]);
MsgFlashReadResp.prototype.fieldSpec.push(['addr_start', 'array', 'writeUInt8', function () { return 1; }, 3]);
MsgFlashReadResp.prototype.fieldSpec.push(['addr_len', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_FLASH_ERASE (0x00E2).
 *
 * The flash erase message from the host erases a sector of either the STM or M25
 * onboard flash memory. The device will reply with a MSG_FLASH_DONE message
 * containing the return code - FLASH_OK (0) on success or FLASH_INVALID_FLASH (1)
 * if the flash specified is invalid.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field target number (unsigned 8-bit int, 1 byte) Target flags
 * @field sector_num number (unsigned 32-bit int, 4 bytes) Flash sector number to erase (0-11 for the STM, 0-15 for the M25)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgFlashErase = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_FLASH_ERASE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgFlashErase.prototype = Object.create(SBP.prototype);
MsgFlashErase.prototype.messageType = "MSG_FLASH_ERASE";
MsgFlashErase.prototype.msg_type = 0x00E2;
MsgFlashErase.prototype.constructor = MsgFlashErase;
MsgFlashErase.prototype.parser = new Parser()
  .endianess('little')
  .uint8('target')
  .uint32('sector_num');
MsgFlashErase.prototype.fieldSpec = [];
MsgFlashErase.prototype.fieldSpec.push(['target', 'writeUInt8', 1]);
MsgFlashErase.prototype.fieldSpec.push(['sector_num', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_STM_FLASH_LOCK_SECTOR (0x00E3).
 *
 * The flash lock message locks a sector of the STM flash memory. The device
 * replies with a MSG_FLASH_DONE message.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sector number (unsigned 32-bit int, 4 bytes) Flash sector number to lock
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgStmFlashLockSector = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_STM_FLASH_LOCK_SECTOR";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgStmFlashLockSector.prototype = Object.create(SBP.prototype);
MsgStmFlashLockSector.prototype.messageType = "MSG_STM_FLASH_LOCK_SECTOR";
MsgStmFlashLockSector.prototype.msg_type = 0x00E3;
MsgStmFlashLockSector.prototype.constructor = MsgStmFlashLockSector;
MsgStmFlashLockSector.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sector');
MsgStmFlashLockSector.prototype.fieldSpec = [];
MsgStmFlashLockSector.prototype.fieldSpec.push(['sector', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_STM_FLASH_UNLOCK_SECTOR (0x00E4).
 *
 * The flash unlock message unlocks a sector of the STM flash memory. The device
 * replies with a MSG_FLASH_DONE message.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sector number (unsigned 32-bit int, 4 bytes) Flash sector number to unlock
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgStmFlashUnlockSector = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_STM_FLASH_UNLOCK_SECTOR";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgStmFlashUnlockSector.prototype = Object.create(SBP.prototype);
MsgStmFlashUnlockSector.prototype.messageType = "MSG_STM_FLASH_UNLOCK_SECTOR";
MsgStmFlashUnlockSector.prototype.msg_type = 0x00E4;
MsgStmFlashUnlockSector.prototype.constructor = MsgStmFlashUnlockSector;
MsgStmFlashUnlockSector.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sector');
MsgStmFlashUnlockSector.prototype.fieldSpec = [];
MsgStmFlashUnlockSector.prototype.fieldSpec.push(['sector', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_STM_UNIQUE_ID_REQ (0x00E8).
 *
 * This message reads the device's hardcoded unique ID. The host requests the ID by
 * sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
 * MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgStmUniqueIdReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_STM_UNIQUE_ID_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgStmUniqueIdReq.prototype = Object.create(SBP.prototype);
MsgStmUniqueIdReq.prototype.messageType = "MSG_STM_UNIQUE_ID_REQ";
MsgStmUniqueIdReq.prototype.msg_type = 0x00E8;
MsgStmUniqueIdReq.prototype.constructor = MsgStmUniqueIdReq;
MsgStmUniqueIdReq.prototype.parser = new Parser()
  .endianess('little');
MsgStmUniqueIdReq.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_STM_UNIQUE_ID_RESP (0x00E5).
 *
 * This message reads the device's hardcoded unique ID. The host requests the ID by
 * sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
 * MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload..
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field stm_id array Device unique ID
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgStmUniqueIdResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_STM_UNIQUE_ID_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgStmUniqueIdResp.prototype = Object.create(SBP.prototype);
MsgStmUniqueIdResp.prototype.messageType = "MSG_STM_UNIQUE_ID_RESP";
MsgStmUniqueIdResp.prototype.msg_type = 0x00E5;
MsgStmUniqueIdResp.prototype.constructor = MsgStmUniqueIdResp;
MsgStmUniqueIdResp.prototype.parser = new Parser()
  .endianess('little')
  .array('stm_id', { length: 12, type: 'uint8' });
MsgStmUniqueIdResp.prototype.fieldSpec = [];
MsgStmUniqueIdResp.prototype.fieldSpec.push(['stm_id', 'array', 'writeUInt8', function () { return 1; }, 12]);

/**
 * SBP class for message MSG_M25_FLASH_WRITE_STATUS (0x00F3).
 *
 * The flash status message writes to the 8-bit M25 flash status register. The
 * device replies with a MSG_FLASH_DONE message.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field status array Byte to write to the M25 flash status register
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgM25FlashWriteStatus = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_M25_FLASH_WRITE_STATUS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgM25FlashWriteStatus.prototype = Object.create(SBP.prototype);
MsgM25FlashWriteStatus.prototype.messageType = "MSG_M25_FLASH_WRITE_STATUS";
MsgM25FlashWriteStatus.prototype.msg_type = 0x00F3;
MsgM25FlashWriteStatus.prototype.constructor = MsgM25FlashWriteStatus;
MsgM25FlashWriteStatus.prototype.parser = new Parser()
  .endianess('little')
  .array('status', { length: 1, type: 'uint8' });
MsgM25FlashWriteStatus.prototype.fieldSpec = [];
MsgM25FlashWriteStatus.prototype.fieldSpec.push(['status', 'array', 'writeUInt8', function () { return 1; }, 1]);

module.exports = {
  0x00E6: MsgFlashProgram,
  MsgFlashProgram: MsgFlashProgram,
  0x00E0: MsgFlashDone,
  MsgFlashDone: MsgFlashDone,
  0x00E7: MsgFlashReadReq,
  MsgFlashReadReq: MsgFlashReadReq,
  0x00E1: MsgFlashReadResp,
  MsgFlashReadResp: MsgFlashReadResp,
  0x00E2: MsgFlashErase,
  MsgFlashErase: MsgFlashErase,
  0x00E3: MsgStmFlashLockSector,
  MsgStmFlashLockSector: MsgStmFlashLockSector,
  0x00E4: MsgStmFlashUnlockSector,
  MsgStmFlashUnlockSector: MsgStmFlashUnlockSector,
  0x00E8: MsgStmUniqueIdReq,
  MsgStmUniqueIdReq: MsgStmUniqueIdReq,
  0x00E5: MsgStmUniqueIdResp,
  MsgStmUniqueIdResp: MsgStmUniqueIdResp,
  0x00F3: MsgM25FlashWriteStatus,
  MsgM25FlashWriteStatus: MsgM25FlashWriteStatus,
}

/***/ }),
/* 28 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/imu.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Inertial Measurement Unit (IMU) messages.
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;

/**
 * SBP class for message MSG_IMU_RAW (0x0900).
 *
 * Raw data from the Inertial Measurement Unit, containing accelerometer and
 * gyroscope readings. The sense of the measurements are to be aligned with  the
 * indications on the device itself.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) Milliseconds since start of GPS week. If the high bit is set, the time is
 *   unknown or invalid.
 * @field tow_f number (unsigned 8-bit int, 1 byte) Milliseconds since start of GPS week, fractional part
 * @field acc_x number (signed 16-bit int, 2 bytes) Acceleration in the IMU frame X axis
 * @field acc_y number (signed 16-bit int, 2 bytes) Acceleration in the IMU frame Y axis
 * @field acc_z number (signed 16-bit int, 2 bytes) Acceleration in the IMU frame Z axis
 * @field gyr_x number (signed 16-bit int, 2 bytes) Angular rate around IMU frame X axis
 * @field gyr_y number (signed 16-bit int, 2 bytes) Angular rate around IMU frame Y axis
 * @field gyr_z number (signed 16-bit int, 2 bytes) Angular rate around IMU frame Z axis
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgImuRaw = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_IMU_RAW";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgImuRaw.prototype = Object.create(SBP.prototype);
MsgImuRaw.prototype.messageType = "MSG_IMU_RAW";
MsgImuRaw.prototype.msg_type = 0x0900;
MsgImuRaw.prototype.constructor = MsgImuRaw;
MsgImuRaw.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint8('tow_f')
  .int16('acc_x')
  .int16('acc_y')
  .int16('acc_z')
  .int16('gyr_x')
  .int16('gyr_y')
  .int16('gyr_z');
MsgImuRaw.prototype.fieldSpec = [];
MsgImuRaw.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgImuRaw.prototype.fieldSpec.push(['tow_f', 'writeUInt8', 1]);
MsgImuRaw.prototype.fieldSpec.push(['acc_x', 'writeInt16LE', 2]);
MsgImuRaw.prototype.fieldSpec.push(['acc_y', 'writeInt16LE', 2]);
MsgImuRaw.prototype.fieldSpec.push(['acc_z', 'writeInt16LE', 2]);
MsgImuRaw.prototype.fieldSpec.push(['gyr_x', 'writeInt16LE', 2]);
MsgImuRaw.prototype.fieldSpec.push(['gyr_y', 'writeInt16LE', 2]);
MsgImuRaw.prototype.fieldSpec.push(['gyr_z', 'writeInt16LE', 2]);

/**
 * SBP class for message MSG_IMU_AUX (0x0901).
 *
 * Auxiliary data specific to a particular IMU. The `imu_type` field will always be
 * consistent but the rest of the payload is device specific and depends on the
 * value of `imu_type`.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field imu_type number (unsigned 8-bit int, 1 byte) IMU type
 * @field temp number (signed 16-bit int, 2 bytes) Raw IMU temperature
 * @field imu_conf number (unsigned 8-bit int, 1 byte) IMU configuration
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgImuAux = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_IMU_AUX";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgImuAux.prototype = Object.create(SBP.prototype);
MsgImuAux.prototype.messageType = "MSG_IMU_AUX";
MsgImuAux.prototype.msg_type = 0x0901;
MsgImuAux.prototype.constructor = MsgImuAux;
MsgImuAux.prototype.parser = new Parser()
  .endianess('little')
  .uint8('imu_type')
  .int16('temp')
  .uint8('imu_conf');
MsgImuAux.prototype.fieldSpec = [];
MsgImuAux.prototype.fieldSpec.push(['imu_type', 'writeUInt8', 1]);
MsgImuAux.prototype.fieldSpec.push(['temp', 'writeInt16LE', 2]);
MsgImuAux.prototype.fieldSpec.push(['imu_conf', 'writeUInt8', 1]);

module.exports = {
  0x0900: MsgImuRaw,
  MsgImuRaw: MsgImuRaw,
  0x0901: MsgImuAux,
  MsgImuAux: MsgImuAux,
}

/***/ }),
/* 29 */
/***/ (function(module, exports, __webpack_require__) {

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

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;

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
MsgTweet.prototype.fieldSpec.push(['tweet', 'string', 140]);

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
  0x0012: MsgTweet,
  MsgTweet: MsgTweet,
  0x0010: MsgPrintDep,
  MsgPrintDep: MsgPrintDep,
}

/***/ }),
/* 30 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/mag.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Magnetometer (mag) messages.
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;

/**
 * SBP class for message MSG_MAG_RAW (0x0902).
 *
 * Raw data from the magnetometer.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) Milliseconds since start of GPS week. If the high bit is set, the time is
 *   unknown or invalid.
 * @field tow_f number (unsigned 8-bit int, 1 byte) Milliseconds since start of GPS week, fractional part
 * @field mag_x number (signed 16-bit int, 2 bytes) Magnetic field in the body frame X axis
 * @field mag_y number (signed 16-bit int, 2 bytes) Magnetic field in the body frame Y axis
 * @field mag_z number (signed 16-bit int, 2 bytes) Magnetic field in the body frame Z axis
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgMagRaw = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_MAG_RAW";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgMagRaw.prototype = Object.create(SBP.prototype);
MsgMagRaw.prototype.messageType = "MSG_MAG_RAW";
MsgMagRaw.prototype.msg_type = 0x0902;
MsgMagRaw.prototype.constructor = MsgMagRaw;
MsgMagRaw.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint8('tow_f')
  .int16('mag_x')
  .int16('mag_y')
  .int16('mag_z');
MsgMagRaw.prototype.fieldSpec = [];
MsgMagRaw.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgMagRaw.prototype.fieldSpec.push(['tow_f', 'writeUInt8', 1]);
MsgMagRaw.prototype.fieldSpec.push(['mag_x', 'writeInt16LE', 2]);
MsgMagRaw.prototype.fieldSpec.push(['mag_y', 'writeInt16LE', 2]);
MsgMagRaw.prototype.fieldSpec.push(['mag_z', 'writeInt16LE', 2]);

module.exports = {
  0x0902: MsgMagRaw,
  MsgMagRaw: MsgMagRaw,
}

/***/ }),
/* 31 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/navigation.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Geodetic navigation messages reporting GPS time, position, velocity, and
 * baseline position solutions. For position solutions, these messages define
 * several different position solutions: single-point (SPP), RTK, and pseudo-
 * absolute position solutions.  The SPP is the standalone, absolute GPS position
 * solution using only a single receiver. The RTK solution is the differential GPS
 * solution, which can use either a fixed/integer or floating carrier phase
 * ambiguity. The pseudo-absolute position solution uses a user-provided, well-
 * surveyed base station position (if available) and the RTK solution in tandem.
 * When the inertial navigation mode indicates that the IMU is used, all messages
 * are reported in the vehicle body frame as defined by device settings.  By
 * default, the vehicle body frame is configured to be coincident with the antenna
 * phase center.  When there is no inertial navigation, the solution will be
 * reported at the phase center of the antenna.
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;

/**
 * SBP class for message MSG_GPS_TIME (0x0102).
 *
 * This message reports the GPS time, representing the time since the GPS epoch
 * began on midnight January 6, 1980 UTC. GPS time counts the weeks and seconds of
 * the week. The weeks begin at the Saturday/Sunday transition. GPS week 0 began at
 * the beginning of the GPS time scale.  Within each week number, the GPS time of
 * the week is between between 0 and 604800 seconds (=60*60*24*7). Note that GPS
 * time does not accumulate leap seconds, and as of now, has a small offset from
 * UTC. In a message stream, this message precedes a set of other navigation
 * messages referenced to the same time (but lacking the ns field) and indicates a
 * more precise time of these messages.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field wn number (unsigned 16-bit int, 2 bytes) GPS week number
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS time of week rounded to the nearest millisecond
 * @field ns_residual number (signed 32-bit int, 4 bytes) Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000)
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags (reserved)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgGpsTime = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_GPS_TIME";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgGpsTime.prototype = Object.create(SBP.prototype);
MsgGpsTime.prototype.messageType = "MSG_GPS_TIME";
MsgGpsTime.prototype.msg_type = 0x0102;
MsgGpsTime.prototype.constructor = MsgGpsTime;
MsgGpsTime.prototype.parser = new Parser()
  .endianess('little')
  .uint16('wn')
  .uint32('tow')
  .int32('ns_residual')
  .uint8('flags');
MsgGpsTime.prototype.fieldSpec = [];
MsgGpsTime.prototype.fieldSpec.push(['wn', 'writeUInt16LE', 2]);
MsgGpsTime.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgGpsTime.prototype.fieldSpec.push(['ns_residual', 'writeInt32LE', 4]);
MsgGpsTime.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_UTC_TIME (0x0103).
 *
 * This message reports the Universal Coordinated Time (UTC).  Note the flags which
 * indicate the source of the UTC offset value and source of the time fix.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field flags number (unsigned 8-bit int, 1 byte) Indicates source and time validity
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS time of week rounded to the nearest millisecond
 * @field year number (unsigned 16-bit int, 2 bytes) Year
 * @field month number (unsigned 8-bit int, 1 byte) Month (range 1 .. 12)
 * @field day number (unsigned 8-bit int, 1 byte) days in the month (range 1-31)
 * @field hours number (unsigned 8-bit int, 1 byte) hours of day (range 0-23)
 * @field minutes number (unsigned 8-bit int, 1 byte) minutes of hour (range 0-59)
 * @field seconds number (unsigned 8-bit int, 1 byte) seconds of minute (range 0-60) rounded down
 * @field ns number (unsigned 32-bit int, 4 bytes) nanoseconds of second (range 0-999999999)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgUtcTime = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_UTC_TIME";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgUtcTime.prototype = Object.create(SBP.prototype);
MsgUtcTime.prototype.messageType = "MSG_UTC_TIME";
MsgUtcTime.prototype.msg_type = 0x0103;
MsgUtcTime.prototype.constructor = MsgUtcTime;
MsgUtcTime.prototype.parser = new Parser()
  .endianess('little')
  .uint8('flags')
  .uint32('tow')
  .uint16('year')
  .uint8('month')
  .uint8('day')
  .uint8('hours')
  .uint8('minutes')
  .uint8('seconds')
  .uint32('ns');
MsgUtcTime.prototype.fieldSpec = [];
MsgUtcTime.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);
MsgUtcTime.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgUtcTime.prototype.fieldSpec.push(['year', 'writeUInt16LE', 2]);
MsgUtcTime.prototype.fieldSpec.push(['month', 'writeUInt8', 1]);
MsgUtcTime.prototype.fieldSpec.push(['day', 'writeUInt8', 1]);
MsgUtcTime.prototype.fieldSpec.push(['hours', 'writeUInt8', 1]);
MsgUtcTime.prototype.fieldSpec.push(['minutes', 'writeUInt8', 1]);
MsgUtcTime.prototype.fieldSpec.push(['seconds', 'writeUInt8', 1]);
MsgUtcTime.prototype.fieldSpec.push(['ns', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_DOPS (0x0208).
 *
 * This dilution of precision (DOP) message describes the effect of navigation
 * satellite geometry on positional measurement precision.  The flags field
 * indicated whether the DOP reported corresponds to differential or SPP solution.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field gdop number (unsigned 16-bit int, 2 bytes) Geometric Dilution of Precision
 * @field pdop number (unsigned 16-bit int, 2 bytes) Position Dilution of Precision
 * @field tdop number (unsigned 16-bit int, 2 bytes) Time Dilution of Precision
 * @field hdop number (unsigned 16-bit int, 2 bytes) Horizontal Dilution of Precision
 * @field vdop number (unsigned 16-bit int, 2 bytes) Vertical Dilution of Precision
 * @field flags number (unsigned 8-bit int, 1 byte) Indicates the position solution with which the DOPS message corresponds
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgDops = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_DOPS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgDops.prototype = Object.create(SBP.prototype);
MsgDops.prototype.messageType = "MSG_DOPS";
MsgDops.prototype.msg_type = 0x0208;
MsgDops.prototype.constructor = MsgDops;
MsgDops.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint16('gdop')
  .uint16('pdop')
  .uint16('tdop')
  .uint16('hdop')
  .uint16('vdop')
  .uint8('flags');
MsgDops.prototype.fieldSpec = [];
MsgDops.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgDops.prototype.fieldSpec.push(['gdop', 'writeUInt16LE', 2]);
MsgDops.prototype.fieldSpec.push(['pdop', 'writeUInt16LE', 2]);
MsgDops.prototype.fieldSpec.push(['tdop', 'writeUInt16LE', 2]);
MsgDops.prototype.fieldSpec.push(['hdop', 'writeUInt16LE', 2]);
MsgDops.prototype.fieldSpec.push(['vdop', 'writeUInt16LE', 2]);
MsgDops.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_POS_ECEF (0x0209).
 *
 * The position solution message reports absolute Earth Centered Earth Fixed (ECEF)
 * coordinates and the status (single point vs pseudo-absolute RTK) of the position
 * solution. If the rover receiver knows the surveyed position of the base station
 * and has an RTK solution, this reports a pseudo-absolute position solution using
 * the base station position and the rover's RTK baseline vector. The full GPS time
 * is given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (float, 8 bytes) ECEF X coordinate
 * @field y number (float, 8 bytes) ECEF Y coordinate
 * @field z number (float, 8 bytes) ECEF Z coordinate
 * @field accuracy number (unsigned 16-bit int, 2 bytes) Position estimated standard deviation
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgPosEcef = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_POS_ECEF";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPosEcef.prototype = Object.create(SBP.prototype);
MsgPosEcef.prototype.messageType = "MSG_POS_ECEF";
MsgPosEcef.prototype.msg_type = 0x0209;
MsgPosEcef.prototype.constructor = MsgPosEcef;
MsgPosEcef.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .doublele('x')
  .doublele('y')
  .doublele('z')
  .uint16('accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgPosEcef.prototype.fieldSpec = [];
MsgPosEcef.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgPosEcef.prototype.fieldSpec.push(['x', 'writeDoubleLE', 8]);
MsgPosEcef.prototype.fieldSpec.push(['y', 'writeDoubleLE', 8]);
MsgPosEcef.prototype.fieldSpec.push(['z', 'writeDoubleLE', 8]);
MsgPosEcef.prototype.fieldSpec.push(['accuracy', 'writeUInt16LE', 2]);
MsgPosEcef.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgPosEcef.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_POS_ECEF_COV (0x0214).
 *
 * The position solution message reports absolute Earth Centered Earth Fixed (ECEF)
 * coordinates and the status (single point vs pseudo-absolute RTK) of the position
 * solution. The message also reports the upper triangular portion of the 3x3
 * covariance matrix. If the receiver knows the surveyed position of the base
 * station and has an RTK solution, this reports a pseudo-absolute position
 * solution using the base station position and the rover's RTK baseline vector.
 * The full GPS time is given by the preceding MSG_GPS_TIME with the matching time-
 * of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (float, 8 bytes) ECEF X coordinate
 * @field y number (float, 8 bytes) ECEF Y coordinate
 * @field z number (float, 8 bytes) ECEF Z coordinate
 * @field cov_x_x number (float, 4 bytes) Estimated variance of x
 * @field cov_x_y number (float, 4 bytes) Estimated covariance of x and y
 * @field cov_x_z number (float, 4 bytes) Estimated covariance of x and z
 * @field cov_y_y number (float, 4 bytes) Estimated variance of y
 * @field cov_y_z number (float, 4 bytes) Estimated covariance of y and z
 * @field cov_z_z number (float, 4 bytes) Estimated variance of z
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgPosEcefCov = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_POS_ECEF_COV";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPosEcefCov.prototype = Object.create(SBP.prototype);
MsgPosEcefCov.prototype.messageType = "MSG_POS_ECEF_COV";
MsgPosEcefCov.prototype.msg_type = 0x0214;
MsgPosEcefCov.prototype.constructor = MsgPosEcefCov;
MsgPosEcefCov.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .doublele('x')
  .doublele('y')
  .doublele('z')
  .floatle('cov_x_x')
  .floatle('cov_x_y')
  .floatle('cov_x_z')
  .floatle('cov_y_y')
  .floatle('cov_y_z')
  .floatle('cov_z_z')
  .uint8('n_sats')
  .uint8('flags');
MsgPosEcefCov.prototype.fieldSpec = [];
MsgPosEcefCov.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgPosEcefCov.prototype.fieldSpec.push(['x', 'writeDoubleLE', 8]);
MsgPosEcefCov.prototype.fieldSpec.push(['y', 'writeDoubleLE', 8]);
MsgPosEcefCov.prototype.fieldSpec.push(['z', 'writeDoubleLE', 8]);
MsgPosEcefCov.prototype.fieldSpec.push(['cov_x_x', 'writeFloatLE', 4]);
MsgPosEcefCov.prototype.fieldSpec.push(['cov_x_y', 'writeFloatLE', 4]);
MsgPosEcefCov.prototype.fieldSpec.push(['cov_x_z', 'writeFloatLE', 4]);
MsgPosEcefCov.prototype.fieldSpec.push(['cov_y_y', 'writeFloatLE', 4]);
MsgPosEcefCov.prototype.fieldSpec.push(['cov_y_z', 'writeFloatLE', 4]);
MsgPosEcefCov.prototype.fieldSpec.push(['cov_z_z', 'writeFloatLE', 4]);
MsgPosEcefCov.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgPosEcefCov.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_POS_LLH (0x020A).
 *
 * This position solution message reports the absolute geodetic coordinates and the
 * status (single point vs pseudo-absolute RTK) of the position solution. If the
 * rover receiver knows the surveyed position of the base station and has an RTK
 * solution, this reports a pseudo-absolute position solution using the base
 * station position and the rover's RTK baseline vector. The full GPS time is given
 * by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field lat number (float, 8 bytes) Latitude
 * @field lon number (float, 8 bytes) Longitude
 * @field height number (float, 8 bytes) Height above WGS84 ellipsoid
 * @field h_accuracy number (unsigned 16-bit int, 2 bytes) Horizontal position estimated standard deviation
 * @field v_accuracy number (unsigned 16-bit int, 2 bytes) Vertical position estimated standard deviation
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution.
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgPosLlh = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_POS_LLH";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPosLlh.prototype = Object.create(SBP.prototype);
MsgPosLlh.prototype.messageType = "MSG_POS_LLH";
MsgPosLlh.prototype.msg_type = 0x020A;
MsgPosLlh.prototype.constructor = MsgPosLlh;
MsgPosLlh.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .doublele('lat')
  .doublele('lon')
  .doublele('height')
  .uint16('h_accuracy')
  .uint16('v_accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgPosLlh.prototype.fieldSpec = [];
MsgPosLlh.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgPosLlh.prototype.fieldSpec.push(['lat', 'writeDoubleLE', 8]);
MsgPosLlh.prototype.fieldSpec.push(['lon', 'writeDoubleLE', 8]);
MsgPosLlh.prototype.fieldSpec.push(['height', 'writeDoubleLE', 8]);
MsgPosLlh.prototype.fieldSpec.push(['h_accuracy', 'writeUInt16LE', 2]);
MsgPosLlh.prototype.fieldSpec.push(['v_accuracy', 'writeUInt16LE', 2]);
MsgPosLlh.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgPosLlh.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_POS_LLH_COV (0x0211).
 *
 * This position solution message reports the absolute geodetic coordinates and the
 * status (single point vs pseudo-absolute RTK) of the position solution as well as
 * the upper triangle of the 3x3 covariance matrix.  The position information and
 * Fix Mode flags should follow the MSG_POS_LLH message.  Since the covariance
 * matrix is computed in the local-level North, East, Down frame, the covariance
 * terms follow with that convention. Thus, covariances are reported against the
 * "downward" measurement and care should be taken with the sign convention.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field lat number (float, 8 bytes) Latitude
 * @field lon number (float, 8 bytes) Longitude
 * @field height number (float, 8 bytes) Height above WGS84 ellipsoid
 * @field cov_n_n number (float, 4 bytes) Estimated variance of northing
 * @field cov_n_e number (float, 4 bytes) Covariance of northing and easting
 * @field cov_n_d number (float, 4 bytes) Covariance of northing and downward measurement
 * @field cov_e_e number (float, 4 bytes) Estimated variance of easting
 * @field cov_e_d number (float, 4 bytes) Covariance of easting and downward measurement
 * @field cov_d_d number (float, 4 bytes) Estimated variance of downward measurement
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution.
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgPosLlhCov = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_POS_LLH_COV";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPosLlhCov.prototype = Object.create(SBP.prototype);
MsgPosLlhCov.prototype.messageType = "MSG_POS_LLH_COV";
MsgPosLlhCov.prototype.msg_type = 0x0211;
MsgPosLlhCov.prototype.constructor = MsgPosLlhCov;
MsgPosLlhCov.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .doublele('lat')
  .doublele('lon')
  .doublele('height')
  .floatle('cov_n_n')
  .floatle('cov_n_e')
  .floatle('cov_n_d')
  .floatle('cov_e_e')
  .floatle('cov_e_d')
  .floatle('cov_d_d')
  .uint8('n_sats')
  .uint8('flags');
MsgPosLlhCov.prototype.fieldSpec = [];
MsgPosLlhCov.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgPosLlhCov.prototype.fieldSpec.push(['lat', 'writeDoubleLE', 8]);
MsgPosLlhCov.prototype.fieldSpec.push(['lon', 'writeDoubleLE', 8]);
MsgPosLlhCov.prototype.fieldSpec.push(['height', 'writeDoubleLE', 8]);
MsgPosLlhCov.prototype.fieldSpec.push(['cov_n_n', 'writeFloatLE', 4]);
MsgPosLlhCov.prototype.fieldSpec.push(['cov_n_e', 'writeFloatLE', 4]);
MsgPosLlhCov.prototype.fieldSpec.push(['cov_n_d', 'writeFloatLE', 4]);
MsgPosLlhCov.prototype.fieldSpec.push(['cov_e_e', 'writeFloatLE', 4]);
MsgPosLlhCov.prototype.fieldSpec.push(['cov_e_d', 'writeFloatLE', 4]);
MsgPosLlhCov.prototype.fieldSpec.push(['cov_d_d', 'writeFloatLE', 4]);
MsgPosLlhCov.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgPosLlhCov.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_BASELINE_ECEF (0x020B).
 *
 * This message reports the baseline solution in Earth Centered Earth Fixed (ECEF)
 * coordinates. This baseline is the relative vector distance from the base station
 * to the rover receiver. The full GPS time is given by the preceding MSG_GPS_TIME
 * with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (signed 32-bit int, 4 bytes) Baseline ECEF X coordinate
 * @field y number (signed 32-bit int, 4 bytes) Baseline ECEF Y coordinate
 * @field z number (signed 32-bit int, 4 bytes) Baseline ECEF Z coordinate
 * @field accuracy number (unsigned 16-bit int, 2 bytes) Position estimated standard deviation
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBaselineEcef = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BASELINE_ECEF";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBaselineEcef.prototype = Object.create(SBP.prototype);
MsgBaselineEcef.prototype.messageType = "MSG_BASELINE_ECEF";
MsgBaselineEcef.prototype.msg_type = 0x020B;
MsgBaselineEcef.prototype.constructor = MsgBaselineEcef;
MsgBaselineEcef.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('x')
  .int32('y')
  .int32('z')
  .uint16('accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgBaselineEcef.prototype.fieldSpec = [];
MsgBaselineEcef.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgBaselineEcef.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgBaselineEcef.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgBaselineEcef.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgBaselineEcef.prototype.fieldSpec.push(['accuracy', 'writeUInt16LE', 2]);
MsgBaselineEcef.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgBaselineEcef.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_BASELINE_NED (0x020C).
 *
 * This message reports the baseline solution in North East Down (NED) coordinates.
 * This baseline is the relative vector distance from the base station to the rover
 * receiver, and NED coordinate system is defined at the local WGS84 tangent plane
 * centered at the base station position.  The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field n number (signed 32-bit int, 4 bytes) Baseline North coordinate
 * @field e number (signed 32-bit int, 4 bytes) Baseline East coordinate
 * @field d number (signed 32-bit int, 4 bytes) Baseline Down coordinate
 * @field h_accuracy number (unsigned 16-bit int, 2 bytes) Horizontal position estimated standard deviation
 * @field v_accuracy number (unsigned 16-bit int, 2 bytes) Vertical position estimated standard deviation
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBaselineNed = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BASELINE_NED";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBaselineNed.prototype = Object.create(SBP.prototype);
MsgBaselineNed.prototype.messageType = "MSG_BASELINE_NED";
MsgBaselineNed.prototype.msg_type = 0x020C;
MsgBaselineNed.prototype.constructor = MsgBaselineNed;
MsgBaselineNed.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('n')
  .int32('e')
  .int32('d')
  .uint16('h_accuracy')
  .uint16('v_accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgBaselineNed.prototype.fieldSpec = [];
MsgBaselineNed.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgBaselineNed.prototype.fieldSpec.push(['n', 'writeInt32LE', 4]);
MsgBaselineNed.prototype.fieldSpec.push(['e', 'writeInt32LE', 4]);
MsgBaselineNed.prototype.fieldSpec.push(['d', 'writeInt32LE', 4]);
MsgBaselineNed.prototype.fieldSpec.push(['h_accuracy', 'writeUInt16LE', 2]);
MsgBaselineNed.prototype.fieldSpec.push(['v_accuracy', 'writeUInt16LE', 2]);
MsgBaselineNed.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgBaselineNed.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_ECEF (0x020D).
 *
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
 * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (signed 32-bit int, 4 bytes) Velocity ECEF X coordinate
 * @field y number (signed 32-bit int, 4 bytes) Velocity ECEF Y coordinate
 * @field z number (signed 32-bit int, 4 bytes) Velocity ECEF Z coordinate
 * @field accuracy number (unsigned 16-bit int, 2 bytes) Velocity estimated standard deviation
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgVelEcef = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_ECEF";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelEcef.prototype = Object.create(SBP.prototype);
MsgVelEcef.prototype.messageType = "MSG_VEL_ECEF";
MsgVelEcef.prototype.msg_type = 0x020D;
MsgVelEcef.prototype.constructor = MsgVelEcef;
MsgVelEcef.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('x')
  .int32('y')
  .int32('z')
  .uint16('accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgVelEcef.prototype.fieldSpec = [];
MsgVelEcef.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelEcef.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgVelEcef.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgVelEcef.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgVelEcef.prototype.fieldSpec.push(['accuracy', 'writeUInt16LE', 2]);
MsgVelEcef.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelEcef.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_ECEF_COV (0x0215).
 *
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
 * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (signed 32-bit int, 4 bytes) Velocity ECEF X coordinate
 * @field y number (signed 32-bit int, 4 bytes) Velocity ECEF Y coordinate
 * @field z number (signed 32-bit int, 4 bytes) Velocity ECEF Z coordinate
 * @field cov_x_x number (float, 4 bytes) Estimated variance of x
 * @field cov_x_y number (float, 4 bytes) Estimated covariance of x and y
 * @field cov_x_z number (float, 4 bytes) Estimated covariance of x and z
 * @field cov_y_y number (float, 4 bytes) Estimated variance of y
 * @field cov_y_z number (float, 4 bytes) Estimated covariance of y and z
 * @field cov_z_z number (float, 4 bytes) Estimated variance of z
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgVelEcefCov = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_ECEF_COV";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelEcefCov.prototype = Object.create(SBP.prototype);
MsgVelEcefCov.prototype.messageType = "MSG_VEL_ECEF_COV";
MsgVelEcefCov.prototype.msg_type = 0x0215;
MsgVelEcefCov.prototype.constructor = MsgVelEcefCov;
MsgVelEcefCov.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('x')
  .int32('y')
  .int32('z')
  .floatle('cov_x_x')
  .floatle('cov_x_y')
  .floatle('cov_x_z')
  .floatle('cov_y_y')
  .floatle('cov_y_z')
  .floatle('cov_z_z')
  .uint8('n_sats')
  .uint8('flags');
MsgVelEcefCov.prototype.fieldSpec = [];
MsgVelEcefCov.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['cov_x_x', 'writeFloatLE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['cov_x_y', 'writeFloatLE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['cov_x_z', 'writeFloatLE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['cov_y_y', 'writeFloatLE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['cov_y_z', 'writeFloatLE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['cov_z_z', 'writeFloatLE', 4]);
MsgVelEcefCov.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelEcefCov.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_NED (0x020E).
 *
 * This message reports the velocity in local North East Down (NED) coordinates.
 * The NED coordinate system is defined as the local WGS84 tangent plane centered
 * at the current position. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field n number (signed 32-bit int, 4 bytes) Velocity North coordinate
 * @field e number (signed 32-bit int, 4 bytes) Velocity East coordinate
 * @field d number (signed 32-bit int, 4 bytes) Velocity Down coordinate
 * @field h_accuracy number (unsigned 16-bit int, 2 bytes) Horizontal velocity estimated standard deviation
 * @field v_accuracy number (unsigned 16-bit int, 2 bytes) Vertical velocity estimated standard deviation
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgVelNed = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_NED";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelNed.prototype = Object.create(SBP.prototype);
MsgVelNed.prototype.messageType = "MSG_VEL_NED";
MsgVelNed.prototype.msg_type = 0x020E;
MsgVelNed.prototype.constructor = MsgVelNed;
MsgVelNed.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('n')
  .int32('e')
  .int32('d')
  .uint16('h_accuracy')
  .uint16('v_accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgVelNed.prototype.fieldSpec = [];
MsgVelNed.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelNed.prototype.fieldSpec.push(['n', 'writeInt32LE', 4]);
MsgVelNed.prototype.fieldSpec.push(['e', 'writeInt32LE', 4]);
MsgVelNed.prototype.fieldSpec.push(['d', 'writeInt32LE', 4]);
MsgVelNed.prototype.fieldSpec.push(['h_accuracy', 'writeUInt16LE', 2]);
MsgVelNed.prototype.fieldSpec.push(['v_accuracy', 'writeUInt16LE', 2]);
MsgVelNed.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelNed.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_NED_COV (0x0212).
 *
 * This message reports the velocity in local North East Down (NED) coordinates.
 * The NED coordinate system is defined as the local WGS84 tangent plane centered
 * at the current position. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow). This message is similar to
 * the MSG_VEL_NED, but it includes the upper triangular portion of the 3x3
 * covariance matrix.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field n number (signed 32-bit int, 4 bytes) Velocity North coordinate
 * @field e number (signed 32-bit int, 4 bytes) Velocity East coordinate
 * @field d number (signed 32-bit int, 4 bytes) Velocity Down coordinate
 * @field cov_n_n number (float, 4 bytes) Estimated variance of northward measurement
 * @field cov_n_e number (float, 4 bytes) Covariance of northward and eastward measurement
 * @field cov_n_d number (float, 4 bytes) Covariance of northward and downward measurement
 * @field cov_e_e number (float, 4 bytes) Estimated variance of eastward measurement
 * @field cov_e_d number (float, 4 bytes) Covariance of eastward and downward measurement
 * @field cov_d_d number (float, 4 bytes) Estimated variance of downward measurement
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgVelNedCov = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_NED_COV";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelNedCov.prototype = Object.create(SBP.prototype);
MsgVelNedCov.prototype.messageType = "MSG_VEL_NED_COV";
MsgVelNedCov.prototype.msg_type = 0x0212;
MsgVelNedCov.prototype.constructor = MsgVelNedCov;
MsgVelNedCov.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('n')
  .int32('e')
  .int32('d')
  .floatle('cov_n_n')
  .floatle('cov_n_e')
  .floatle('cov_n_d')
  .floatle('cov_e_e')
  .floatle('cov_e_d')
  .floatle('cov_d_d')
  .uint8('n_sats')
  .uint8('flags');
MsgVelNedCov.prototype.fieldSpec = [];
MsgVelNedCov.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['n', 'writeInt32LE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['e', 'writeInt32LE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['d', 'writeInt32LE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['cov_n_n', 'writeFloatLE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['cov_n_e', 'writeFloatLE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['cov_n_d', 'writeFloatLE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['cov_e_e', 'writeFloatLE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['cov_e_d', 'writeFloatLE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['cov_d_d', 'writeFloatLE', 4]);
MsgVelNedCov.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelNedCov.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_BODY (0x0213).
 *
 * This message reports the velocity in the Vehicle Body Frame. By convention, the
 * x-axis should point out the nose of the vehicle and represent the forward
 * direction, while as the y-axis should point out the right hand side of the
 * vehicle. Since this is a right handed system, z should point out the bottom of
 * the vehicle. The orientation and origin of the Vehicle Body Frame are specified
 * via the device settings. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (signed 32-bit int, 4 bytes) Velocity in x direction
 * @field y number (signed 32-bit int, 4 bytes) Velocity in y direction
 * @field z number (signed 32-bit int, 4 bytes) Velocity in z direction
 * @field cov_x_x number (float, 4 bytes) Estimated variance of x
 * @field cov_x_y number (float, 4 bytes) Covariance of x and y
 * @field cov_x_z number (float, 4 bytes) Covariance of x and z
 * @field cov_y_y number (float, 4 bytes) Estimated variance of y
 * @field cov_y_z number (float, 4 bytes) Covariance of y and z
 * @field cov_z_z number (float, 4 bytes) Estimated variance of z
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgVelBody = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_BODY";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelBody.prototype = Object.create(SBP.prototype);
MsgVelBody.prototype.messageType = "MSG_VEL_BODY";
MsgVelBody.prototype.msg_type = 0x0213;
MsgVelBody.prototype.constructor = MsgVelBody;
MsgVelBody.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('x')
  .int32('y')
  .int32('z')
  .floatle('cov_x_x')
  .floatle('cov_x_y')
  .floatle('cov_x_z')
  .floatle('cov_y_y')
  .floatle('cov_y_z')
  .floatle('cov_z_z')
  .uint8('n_sats')
  .uint8('flags');
MsgVelBody.prototype.fieldSpec = [];
MsgVelBody.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelBody.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgVelBody.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgVelBody.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgVelBody.prototype.fieldSpec.push(['cov_x_x', 'writeFloatLE', 4]);
MsgVelBody.prototype.fieldSpec.push(['cov_x_y', 'writeFloatLE', 4]);
MsgVelBody.prototype.fieldSpec.push(['cov_x_z', 'writeFloatLE', 4]);
MsgVelBody.prototype.fieldSpec.push(['cov_y_y', 'writeFloatLE', 4]);
MsgVelBody.prototype.fieldSpec.push(['cov_y_z', 'writeFloatLE', 4]);
MsgVelBody.prototype.fieldSpec.push(['cov_z_z', 'writeFloatLE', 4]);
MsgVelBody.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelBody.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_AGE_CORRECTIONS (0x0210).
 *
 * This message reports the Age of the corrections used for the current
 * Differential solution
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field age number (unsigned 16-bit int, 2 bytes) Age of the corrections (0xFFFF indicates invalid)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAgeCorrections = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_AGE_CORRECTIONS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAgeCorrections.prototype = Object.create(SBP.prototype);
MsgAgeCorrections.prototype.messageType = "MSG_AGE_CORRECTIONS";
MsgAgeCorrections.prototype.msg_type = 0x0210;
MsgAgeCorrections.prototype.constructor = MsgAgeCorrections;
MsgAgeCorrections.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint16('age');
MsgAgeCorrections.prototype.fieldSpec = [];
MsgAgeCorrections.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgAgeCorrections.prototype.fieldSpec.push(['age', 'writeUInt16LE', 2]);

/**
 * SBP class for message MSG_GPS_TIME_DEP_A (0x0100).
 *
 * This message reports the GPS time, representing the time since the GPS epoch
 * began on midnight January 6, 1980 UTC. GPS time counts the weeks and seconds of
 * the week. The weeks begin at the Saturday/Sunday transition. GPS week 0 began at
 * the beginning of the GPS time scale.  Within each week number, the GPS time of
 * the week is between between 0 and 604800 seconds (=60*60*24*7). Note that GPS
 * time does not accumulate leap seconds, and as of now, has a small offset from
 * UTC. In a message stream, this message precedes a set of other navigation
 * messages referenced to the same time (but lacking the ns field) and indicates a
 * more precise time of these messages.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field wn number (unsigned 16-bit int, 2 bytes) GPS week number
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS time of week rounded to the nearest millisecond
 * @field ns_residual number (signed 32-bit int, 4 bytes) Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000)
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags (reserved)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgGpsTimeDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_GPS_TIME_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgGpsTimeDepA.prototype = Object.create(SBP.prototype);
MsgGpsTimeDepA.prototype.messageType = "MSG_GPS_TIME_DEP_A";
MsgGpsTimeDepA.prototype.msg_type = 0x0100;
MsgGpsTimeDepA.prototype.constructor = MsgGpsTimeDepA;
MsgGpsTimeDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint16('wn')
  .uint32('tow')
  .int32('ns_residual')
  .uint8('flags');
MsgGpsTimeDepA.prototype.fieldSpec = [];
MsgGpsTimeDepA.prototype.fieldSpec.push(['wn', 'writeUInt16LE', 2]);
MsgGpsTimeDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgGpsTimeDepA.prototype.fieldSpec.push(['ns_residual', 'writeInt32LE', 4]);
MsgGpsTimeDepA.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_DOPS_DEP_A (0x0206).
 *
 * This dilution of precision (DOP) message describes the effect of navigation
 * satellite geometry on positional measurement precision.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field gdop number (unsigned 16-bit int, 2 bytes) Geometric Dilution of Precision
 * @field pdop number (unsigned 16-bit int, 2 bytes) Position Dilution of Precision
 * @field tdop number (unsigned 16-bit int, 2 bytes) Time Dilution of Precision
 * @field hdop number (unsigned 16-bit int, 2 bytes) Horizontal Dilution of Precision
 * @field vdop number (unsigned 16-bit int, 2 bytes) Vertical Dilution of Precision
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgDopsDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_DOPS_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgDopsDepA.prototype = Object.create(SBP.prototype);
MsgDopsDepA.prototype.messageType = "MSG_DOPS_DEP_A";
MsgDopsDepA.prototype.msg_type = 0x0206;
MsgDopsDepA.prototype.constructor = MsgDopsDepA;
MsgDopsDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint16('gdop')
  .uint16('pdop')
  .uint16('tdop')
  .uint16('hdop')
  .uint16('vdop');
MsgDopsDepA.prototype.fieldSpec = [];
MsgDopsDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgDopsDepA.prototype.fieldSpec.push(['gdop', 'writeUInt16LE', 2]);
MsgDopsDepA.prototype.fieldSpec.push(['pdop', 'writeUInt16LE', 2]);
MsgDopsDepA.prototype.fieldSpec.push(['tdop', 'writeUInt16LE', 2]);
MsgDopsDepA.prototype.fieldSpec.push(['hdop', 'writeUInt16LE', 2]);
MsgDopsDepA.prototype.fieldSpec.push(['vdop', 'writeUInt16LE', 2]);

/**
 * SBP class for message MSG_POS_ECEF_DEP_A (0x0200).
 *
 * The position solution message reports absolute Earth Centered Earth Fixed (ECEF)
 * coordinates and the status (single point vs pseudo-absolute RTK) of the position
 * solution. If the rover receiver knows the surveyed position of the base station
 * and has an RTK solution, this reports a pseudo-absolute position solution using
 * the base station position and the rover's RTK baseline vector. The full GPS time
 * is given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (float, 8 bytes) ECEF X coordinate
 * @field y number (float, 8 bytes) ECEF Y coordinate
 * @field z number (float, 8 bytes) ECEF Z coordinate
 * @field accuracy number (unsigned 16-bit int, 2 bytes) Position accuracy estimate (not implemented). Defaults to 0.
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgPosEcefDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_POS_ECEF_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPosEcefDepA.prototype = Object.create(SBP.prototype);
MsgPosEcefDepA.prototype.messageType = "MSG_POS_ECEF_DEP_A";
MsgPosEcefDepA.prototype.msg_type = 0x0200;
MsgPosEcefDepA.prototype.constructor = MsgPosEcefDepA;
MsgPosEcefDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .doublele('x')
  .doublele('y')
  .doublele('z')
  .uint16('accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgPosEcefDepA.prototype.fieldSpec = [];
MsgPosEcefDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgPosEcefDepA.prototype.fieldSpec.push(['x', 'writeDoubleLE', 8]);
MsgPosEcefDepA.prototype.fieldSpec.push(['y', 'writeDoubleLE', 8]);
MsgPosEcefDepA.prototype.fieldSpec.push(['z', 'writeDoubleLE', 8]);
MsgPosEcefDepA.prototype.fieldSpec.push(['accuracy', 'writeUInt16LE', 2]);
MsgPosEcefDepA.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgPosEcefDepA.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_POS_LLH_DEP_A (0x0201).
 *
 * This position solution message reports the absolute geodetic coordinates and the
 * status (single point vs pseudo-absolute RTK) of the position solution. If the
 * rover receiver knows the surveyed position of the base station and has an RTK
 * solution, this reports a pseudo-absolute position solution using the base
 * station position and the rover's RTK baseline vector. The full GPS time is given
 * by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field lat number (float, 8 bytes) Latitude
 * @field lon number (float, 8 bytes) Longitude
 * @field height number (float, 8 bytes) Height
 * @field h_accuracy number (unsigned 16-bit int, 2 bytes) Horizontal position accuracy estimate (not implemented). Defaults to 0.
 * @field v_accuracy number (unsigned 16-bit int, 2 bytes) Vertical position accuracy estimate (not implemented). Defaults to 0.
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution.
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgPosLlhDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_POS_LLH_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgPosLlhDepA.prototype = Object.create(SBP.prototype);
MsgPosLlhDepA.prototype.messageType = "MSG_POS_LLH_DEP_A";
MsgPosLlhDepA.prototype.msg_type = 0x0201;
MsgPosLlhDepA.prototype.constructor = MsgPosLlhDepA;
MsgPosLlhDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .doublele('lat')
  .doublele('lon')
  .doublele('height')
  .uint16('h_accuracy')
  .uint16('v_accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgPosLlhDepA.prototype.fieldSpec = [];
MsgPosLlhDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgPosLlhDepA.prototype.fieldSpec.push(['lat', 'writeDoubleLE', 8]);
MsgPosLlhDepA.prototype.fieldSpec.push(['lon', 'writeDoubleLE', 8]);
MsgPosLlhDepA.prototype.fieldSpec.push(['height', 'writeDoubleLE', 8]);
MsgPosLlhDepA.prototype.fieldSpec.push(['h_accuracy', 'writeUInt16LE', 2]);
MsgPosLlhDepA.prototype.fieldSpec.push(['v_accuracy', 'writeUInt16LE', 2]);
MsgPosLlhDepA.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgPosLlhDepA.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_BASELINE_ECEF_DEP_A (0x0202).
 *
 * This message reports the baseline solution in Earth Centered Earth Fixed (ECEF)
 * coordinates. This baseline is the relative vector distance from the base station
 * to the rover receiver. The full GPS time is given by the preceding MSG_GPS_TIME
 * with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (signed 32-bit int, 4 bytes) Baseline ECEF X coordinate
 * @field y number (signed 32-bit int, 4 bytes) Baseline ECEF Y coordinate
 * @field z number (signed 32-bit int, 4 bytes) Baseline ECEF Z coordinate
 * @field accuracy number (unsigned 16-bit int, 2 bytes) Position accuracy estimate
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBaselineEcefDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BASELINE_ECEF_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBaselineEcefDepA.prototype = Object.create(SBP.prototype);
MsgBaselineEcefDepA.prototype.messageType = "MSG_BASELINE_ECEF_DEP_A";
MsgBaselineEcefDepA.prototype.msg_type = 0x0202;
MsgBaselineEcefDepA.prototype.constructor = MsgBaselineEcefDepA;
MsgBaselineEcefDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('x')
  .int32('y')
  .int32('z')
  .uint16('accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgBaselineEcefDepA.prototype.fieldSpec = [];
MsgBaselineEcefDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgBaselineEcefDepA.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgBaselineEcefDepA.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgBaselineEcefDepA.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgBaselineEcefDepA.prototype.fieldSpec.push(['accuracy', 'writeUInt16LE', 2]);
MsgBaselineEcefDepA.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgBaselineEcefDepA.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_BASELINE_NED_DEP_A (0x0203).
 *
 * This message reports the baseline solution in North East Down (NED) coordinates.
 * This baseline is the relative vector distance from the base station to the rover
 * receiver, and NED coordinate system is defined at the local WGS84 tangent plane
 * centered at the base station position.  The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field n number (signed 32-bit int, 4 bytes) Baseline North coordinate
 * @field e number (signed 32-bit int, 4 bytes) Baseline East coordinate
 * @field d number (signed 32-bit int, 4 bytes) Baseline Down coordinate
 * @field h_accuracy number (unsigned 16-bit int, 2 bytes) Horizontal position accuracy estimate (not implemented). Defaults to 0.
 * @field v_accuracy number (unsigned 16-bit int, 2 bytes) Vertical position accuracy estimate (not implemented). Defaults to 0.
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBaselineNedDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BASELINE_NED_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBaselineNedDepA.prototype = Object.create(SBP.prototype);
MsgBaselineNedDepA.prototype.messageType = "MSG_BASELINE_NED_DEP_A";
MsgBaselineNedDepA.prototype.msg_type = 0x0203;
MsgBaselineNedDepA.prototype.constructor = MsgBaselineNedDepA;
MsgBaselineNedDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('n')
  .int32('e')
  .int32('d')
  .uint16('h_accuracy')
  .uint16('v_accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgBaselineNedDepA.prototype.fieldSpec = [];
MsgBaselineNedDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgBaselineNedDepA.prototype.fieldSpec.push(['n', 'writeInt32LE', 4]);
MsgBaselineNedDepA.prototype.fieldSpec.push(['e', 'writeInt32LE', 4]);
MsgBaselineNedDepA.prototype.fieldSpec.push(['d', 'writeInt32LE', 4]);
MsgBaselineNedDepA.prototype.fieldSpec.push(['h_accuracy', 'writeUInt16LE', 2]);
MsgBaselineNedDepA.prototype.fieldSpec.push(['v_accuracy', 'writeUInt16LE', 2]);
MsgBaselineNedDepA.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgBaselineNedDepA.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_ECEF_DEP_A (0x0204).
 *
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
 * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (signed 32-bit int, 4 bytes) Velocity ECEF X coordinate
 * @field y number (signed 32-bit int, 4 bytes) Velocity ECEF Y coordinate
 * @field z number (signed 32-bit int, 4 bytes) Velocity ECEF Z coordinate
 * @field accuracy number (unsigned 16-bit int, 2 bytes) Velocity accuracy estimate (not implemented). Defaults to 0.
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags (reserved)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgVelEcefDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_ECEF_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelEcefDepA.prototype = Object.create(SBP.prototype);
MsgVelEcefDepA.prototype.messageType = "MSG_VEL_ECEF_DEP_A";
MsgVelEcefDepA.prototype.msg_type = 0x0204;
MsgVelEcefDepA.prototype.constructor = MsgVelEcefDepA;
MsgVelEcefDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('x')
  .int32('y')
  .int32('z')
  .uint16('accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgVelEcefDepA.prototype.fieldSpec = [];
MsgVelEcefDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelEcefDepA.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgVelEcefDepA.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgVelEcefDepA.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgVelEcefDepA.prototype.fieldSpec.push(['accuracy', 'writeUInt16LE', 2]);
MsgVelEcefDepA.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelEcefDepA.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_VEL_NED_DEP_A (0x0205).
 *
 * This message reports the velocity in local North East Down (NED) coordinates.
 * The NED coordinate system is defined as the local WGS84 tangent plane centered
 * at the current position. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field n number (signed 32-bit int, 4 bytes) Velocity North coordinate
 * @field e number (signed 32-bit int, 4 bytes) Velocity East coordinate
 * @field d number (signed 32-bit int, 4 bytes) Velocity Down coordinate
 * @field h_accuracy number (unsigned 16-bit int, 2 bytes) Horizontal velocity accuracy estimate (not implemented). Defaults to 0.
 * @field v_accuracy number (unsigned 16-bit int, 2 bytes) Vertical velocity accuracy estimate (not implemented). Defaults to 0.
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags (reserved)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgVelNedDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_VEL_NED_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgVelNedDepA.prototype = Object.create(SBP.prototype);
MsgVelNedDepA.prototype.messageType = "MSG_VEL_NED_DEP_A";
MsgVelNedDepA.prototype.msg_type = 0x0205;
MsgVelNedDepA.prototype.constructor = MsgVelNedDepA;
MsgVelNedDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('n')
  .int32('e')
  .int32('d')
  .uint16('h_accuracy')
  .uint16('v_accuracy')
  .uint8('n_sats')
  .uint8('flags');
MsgVelNedDepA.prototype.fieldSpec = [];
MsgVelNedDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgVelNedDepA.prototype.fieldSpec.push(['n', 'writeInt32LE', 4]);
MsgVelNedDepA.prototype.fieldSpec.push(['e', 'writeInt32LE', 4]);
MsgVelNedDepA.prototype.fieldSpec.push(['d', 'writeInt32LE', 4]);
MsgVelNedDepA.prototype.fieldSpec.push(['h_accuracy', 'writeUInt16LE', 2]);
MsgVelNedDepA.prototype.fieldSpec.push(['v_accuracy', 'writeUInt16LE', 2]);
MsgVelNedDepA.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgVelNedDepA.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_BASELINE_HEADING_DEP_A (0x0207).
 *
 * This message reports the baseline heading pointing from the base station to the
 * rover relative to True North. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field heading number (unsigned 32-bit int, 4 bytes) Heading
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBaselineHeadingDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BASELINE_HEADING_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBaselineHeadingDepA.prototype = Object.create(SBP.prototype);
MsgBaselineHeadingDepA.prototype.messageType = "MSG_BASELINE_HEADING_DEP_A";
MsgBaselineHeadingDepA.prototype.msg_type = 0x0207;
MsgBaselineHeadingDepA.prototype.constructor = MsgBaselineHeadingDepA;
MsgBaselineHeadingDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint32('heading')
  .uint8('n_sats')
  .uint8('flags');
MsgBaselineHeadingDepA.prototype.fieldSpec = [];
MsgBaselineHeadingDepA.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgBaselineHeadingDepA.prototype.fieldSpec.push(['heading', 'writeUInt32LE', 4]);
MsgBaselineHeadingDepA.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgBaselineHeadingDepA.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

module.exports = {
  0x0102: MsgGpsTime,
  MsgGpsTime: MsgGpsTime,
  0x0103: MsgUtcTime,
  MsgUtcTime: MsgUtcTime,
  0x0208: MsgDops,
  MsgDops: MsgDops,
  0x0209: MsgPosEcef,
  MsgPosEcef: MsgPosEcef,
  0x0214: MsgPosEcefCov,
  MsgPosEcefCov: MsgPosEcefCov,
  0x020A: MsgPosLlh,
  MsgPosLlh: MsgPosLlh,
  0x0211: MsgPosLlhCov,
  MsgPosLlhCov: MsgPosLlhCov,
  0x020B: MsgBaselineEcef,
  MsgBaselineEcef: MsgBaselineEcef,
  0x020C: MsgBaselineNed,
  MsgBaselineNed: MsgBaselineNed,
  0x020D: MsgVelEcef,
  MsgVelEcef: MsgVelEcef,
  0x0215: MsgVelEcefCov,
  MsgVelEcefCov: MsgVelEcefCov,
  0x020E: MsgVelNed,
  MsgVelNed: MsgVelNed,
  0x0212: MsgVelNedCov,
  MsgVelNedCov: MsgVelNedCov,
  0x0213: MsgVelBody,
  MsgVelBody: MsgVelBody,
  0x0210: MsgAgeCorrections,
  MsgAgeCorrections: MsgAgeCorrections,
  0x0100: MsgGpsTimeDepA,
  MsgGpsTimeDepA: MsgGpsTimeDepA,
  0x0206: MsgDopsDepA,
  MsgDopsDepA: MsgDopsDepA,
  0x0200: MsgPosEcefDepA,
  MsgPosEcefDepA: MsgPosEcefDepA,
  0x0201: MsgPosLlhDepA,
  MsgPosLlhDepA: MsgPosLlhDepA,
  0x0202: MsgBaselineEcefDepA,
  MsgBaselineEcefDepA: MsgBaselineEcefDepA,
  0x0203: MsgBaselineNedDepA,
  MsgBaselineNedDepA: MsgBaselineNedDepA,
  0x0204: MsgVelEcefDepA,
  MsgVelEcefDepA: MsgVelEcefDepA,
  0x0205: MsgVelNedDepA,
  MsgVelNedDepA: MsgVelNedDepA,
  0x0207: MsgBaselineHeadingDepA,
  MsgBaselineHeadingDepA: MsgBaselineHeadingDepA,
}

/***/ }),
/* 32 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/ndb.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages for logging NDB events.
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;
var GnssSignal = __webpack_require__(0).GnssSignal;
var GnssSignalDep = __webpack_require__(0).GnssSignalDep;
var GPSTime = __webpack_require__(0).GPSTime;
var CarrierPhase = __webpack_require__(0).CarrierPhase;
var GPSTime = __webpack_require__(0).GPSTime;
var GPSTimeSec = __webpack_require__(0).GPSTimeSec;
var GPSTimeDep = __webpack_require__(0).GPSTimeDep;

/**
 * SBP class for message MSG_NDB_EVENT (0x0400).
 *
 * This message is sent out when an object is stored into NDB. If needed message
 * could also be sent out when fetching an object from NDB.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field recv_time number (unsigned 64-bit int, 8 bytes) HW time in milliseconds.
 * @field event number (unsigned 8-bit int, 1 byte) Event type.
 * @field object_type number (unsigned 8-bit int, 1 byte) Event object type.
 * @field result number (unsigned 8-bit int, 1 byte) Event result.
 * @field data_source number (unsigned 8-bit int, 1 byte) Data source for STORE event, reserved for other events.
 * @field object_sid GnssSignal GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid indicates
 *   for which signal the object belongs to. Reserved in other cases.
 * @field src_sid GnssSignal GNSS signal identifier, If object_type is Almanac, Almanac WN, Iono OR L2C
 *   capabilities AND data_source is NDB_DS_RECEIVER sid indicates from which SV data
 *   was decoded. Reserved in other cases.
 * @field original_sender number (unsigned 16-bit int, 2 bytes) A unique identifier of the sending hardware. For v1.0, set to the 2 least
 *   significant bytes of the device serial number, valid only if data_source is
 *   NDB_DS_SBP. Reserved in case of other data_source.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgNdbEvent = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_NDB_EVENT";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgNdbEvent.prototype = Object.create(SBP.prototype);
MsgNdbEvent.prototype.messageType = "MSG_NDB_EVENT";
MsgNdbEvent.prototype.msg_type = 0x0400;
MsgNdbEvent.prototype.constructor = MsgNdbEvent;
MsgNdbEvent.prototype.parser = new Parser()
  .endianess('little')
  .uint64('recv_time')
  .uint8('event')
  .uint8('object_type')
  .uint8('result')
  .uint8('data_source')
  .nest('object_sid', { type: GnssSignal.prototype.parser })
  .nest('src_sid', { type: GnssSignal.prototype.parser })
  .uint16('original_sender');
MsgNdbEvent.prototype.fieldSpec = [];
MsgNdbEvent.prototype.fieldSpec.push(['recv_time', 'writeUInt64LE', 8]);
MsgNdbEvent.prototype.fieldSpec.push(['event', 'writeUInt8', 1]);
MsgNdbEvent.prototype.fieldSpec.push(['object_type', 'writeUInt8', 1]);
MsgNdbEvent.prototype.fieldSpec.push(['result', 'writeUInt8', 1]);
MsgNdbEvent.prototype.fieldSpec.push(['data_source', 'writeUInt8', 1]);
MsgNdbEvent.prototype.fieldSpec.push(['object_sid', GnssSignal.prototype.fieldSpec]);
MsgNdbEvent.prototype.fieldSpec.push(['src_sid', GnssSignal.prototype.fieldSpec]);
MsgNdbEvent.prototype.fieldSpec.push(['original_sender', 'writeUInt16LE', 2]);

module.exports = {
  0x0400: MsgNdbEvent,
  MsgNdbEvent: MsgNdbEvent,
}

/***/ }),
/* 33 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/observation.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Satellite observation messages from the device.
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;
var GnssSignal = __webpack_require__(0).GnssSignal;
var GnssSignalDep = __webpack_require__(0).GnssSignalDep;
var GPSTime = __webpack_require__(0).GPSTime;
var CarrierPhase = __webpack_require__(0).CarrierPhase;
var GPSTime = __webpack_require__(0).GPSTime;
var GPSTimeSec = __webpack_require__(0).GPSTimeSec;
var GPSTimeDep = __webpack_require__(0).GPSTimeDep;

/**
 * SBP class for message fragment ObservationHeader
 *
 * Header of a GNSS observation message.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field t GPSTime GNSS time of this observation
 * @field n_obs number (unsigned 8-bit int, 1 byte) Total number of observations. First nibble is the size of the sequence (n),
 *   second nibble is the zero-indexed counter (ith packet of n)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var ObservationHeader = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "ObservationHeader";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
ObservationHeader.prototype = Object.create(SBP.prototype);
ObservationHeader.prototype.messageType = "ObservationHeader";
ObservationHeader.prototype.constructor = ObservationHeader;
ObservationHeader.prototype.parser = new Parser()
  .endianess('little')
  .nest('t', { type: GPSTime.prototype.parser })
  .uint8('n_obs');
ObservationHeader.prototype.fieldSpec = [];
ObservationHeader.prototype.fieldSpec.push(['t', GPSTime.prototype.fieldSpec]);
ObservationHeader.prototype.fieldSpec.push(['n_obs', 'writeUInt8', 1]);

/**
 * SBP class for message fragment Doppler
 *
 * Doppler measurement in Hz represented as a 24-bit fixed point number with Q16.8
 * layout, i.e. 16-bits of whole doppler and 8-bits of fractional doppler. This
 * doppler is defined as positive for approaching satellites.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field i number (signed 16-bit int, 2 bytes) Doppler whole Hz
 * @field f number (unsigned 8-bit int, 1 byte) Doppler fractional part
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var Doppler = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "Doppler";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
Doppler.prototype = Object.create(SBP.prototype);
Doppler.prototype.messageType = "Doppler";
Doppler.prototype.constructor = Doppler;
Doppler.prototype.parser = new Parser()
  .endianess('little')
  .int16('i')
  .uint8('f');
Doppler.prototype.fieldSpec = [];
Doppler.prototype.fieldSpec.push(['i', 'writeInt16LE', 2]);
Doppler.prototype.fieldSpec.push(['f', 'writeUInt8', 1]);

/**
 * SBP class for message fragment PackedObsContent
 *
 * Pseudorange and carrier phase observation for a satellite being tracked. The
 * observations are interoperable with 3rd party receivers and conform with typical
 * RTCMv3 GNSS observations.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field P number (unsigned 32-bit int, 4 bytes) Pseudorange observation
 * @field L CarrierPhase Carrier phase observation with typical sign convention.
 * @field D Doppler Doppler observation with typical sign convention.
 * @field cn0 number (unsigned 8-bit int, 1 byte) Carrier-to-Noise density.  Zero implies invalid cn0.
 * @field lock number (unsigned 8-bit int, 1 byte) Lock timer. This value gives an indication of the time for which a signal has
 *   maintained continuous phase lock. Whenever a signal has lost and regained lock,
 *   this value is reset to zero. It is encoded according to DF402 from the RTCM
 *   10403.2 Amendment 2 specification.  Valid values range from 0 to 15 and the most
 *   significant nibble is reserved for future use.
 * @field flags number (unsigned 8-bit int, 1 byte) Measurement status flags. A bit field of flags providing the status of this
 *   observation.  If this field is 0 it means only the Cn0 estimate for the signal
 *   is valid.
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var PackedObsContent = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "PackedObsContent";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
PackedObsContent.prototype = Object.create(SBP.prototype);
PackedObsContent.prototype.messageType = "PackedObsContent";
PackedObsContent.prototype.constructor = PackedObsContent;
PackedObsContent.prototype.parser = new Parser()
  .endianess('little')
  .uint32('P')
  .nest('L', { type: CarrierPhase.prototype.parser })
  .nest('D', { type: Doppler.prototype.parser })
  .uint8('cn0')
  .uint8('lock')
  .uint8('flags')
  .nest('sid', { type: GnssSignal.prototype.parser });
PackedObsContent.prototype.fieldSpec = [];
PackedObsContent.prototype.fieldSpec.push(['P', 'writeUInt32LE', 4]);
PackedObsContent.prototype.fieldSpec.push(['L', CarrierPhase.prototype.fieldSpec]);
PackedObsContent.prototype.fieldSpec.push(['D', Doppler.prototype.fieldSpec]);
PackedObsContent.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);
PackedObsContent.prototype.fieldSpec.push(['lock', 'writeUInt8', 1]);
PackedObsContent.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);
PackedObsContent.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);

/**
 * SBP class for message MSG_OBS (0x004A).
 *
 * The GPS observations message reports all the raw pseudorange and carrier phase
 * observations for the satellites being tracked by the device. Carrier phase
 * observation here is represented as a 40-bit fixed point number with Q32.8 layout
 * (i.e. 32-bits of whole cycles and 8-bits of fractional cycles). The observations
 * are be interoperable with 3rd party receivers and conform with typical RTCMv3
 * GNSS observations.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field header ObservationHeader Header of a GPS observation message
 * @field obs array Pseudorange and carrier phase observation for a satellite being tracked.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgObs = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_OBS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgObs.prototype = Object.create(SBP.prototype);
MsgObs.prototype.messageType = "MSG_OBS";
MsgObs.prototype.msg_type = 0x004A;
MsgObs.prototype.constructor = MsgObs;
MsgObs.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: ObservationHeader.prototype.parser })
  .array('obs', { type: PackedObsContent.prototype.parser, readUntil: 'eof' });
MsgObs.prototype.fieldSpec = [];
MsgObs.prototype.fieldSpec.push(['header', ObservationHeader.prototype.fieldSpec]);
MsgObs.prototype.fieldSpec.push(['obs', 'array', PackedObsContent.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_BASE_POS_LLH (0x0044).
 *
 * The base station position message is the position reported by the base station
 * itself. It is used for pseudo-absolute RTK positioning, and is required to be a
 * high-accuracy surveyed location of the base station. Any error here will result
 * in an error in the pseudo-absolute position output.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field lat number (float, 8 bytes) Latitude
 * @field lon number (float, 8 bytes) Longitude
 * @field height number (float, 8 bytes) Height
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBasePosLlh = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BASE_POS_LLH";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBasePosLlh.prototype = Object.create(SBP.prototype);
MsgBasePosLlh.prototype.messageType = "MSG_BASE_POS_LLH";
MsgBasePosLlh.prototype.msg_type = 0x0044;
MsgBasePosLlh.prototype.constructor = MsgBasePosLlh;
MsgBasePosLlh.prototype.parser = new Parser()
  .endianess('little')
  .doublele('lat')
  .doublele('lon')
  .doublele('height');
MsgBasePosLlh.prototype.fieldSpec = [];
MsgBasePosLlh.prototype.fieldSpec.push(['lat', 'writeDoubleLE', 8]);
MsgBasePosLlh.prototype.fieldSpec.push(['lon', 'writeDoubleLE', 8]);
MsgBasePosLlh.prototype.fieldSpec.push(['height', 'writeDoubleLE', 8]);

/**
 * SBP class for message MSG_BASE_POS_ECEF (0x0048).
 *
 * The base station position message is the position reported by the base station
 * itself in absolute Earth Centered Earth Fixed coordinates. It is used for
 * pseudo-absolute RTK positioning, and is required to be a high-accuracy surveyed
 * location of the base station. Any error here will result in an error in the
 * pseudo-absolute position output.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field x number (float, 8 bytes) ECEF X coodinate
 * @field y number (float, 8 bytes) ECEF Y coordinate
 * @field z number (float, 8 bytes) ECEF Z coordinate
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBasePosEcef = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BASE_POS_ECEF";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBasePosEcef.prototype = Object.create(SBP.prototype);
MsgBasePosEcef.prototype.messageType = "MSG_BASE_POS_ECEF";
MsgBasePosEcef.prototype.msg_type = 0x0048;
MsgBasePosEcef.prototype.constructor = MsgBasePosEcef;
MsgBasePosEcef.prototype.parser = new Parser()
  .endianess('little')
  .doublele('x')
  .doublele('y')
  .doublele('z');
MsgBasePosEcef.prototype.fieldSpec = [];
MsgBasePosEcef.prototype.fieldSpec.push(['x', 'writeDoubleLE', 8]);
MsgBasePosEcef.prototype.fieldSpec.push(['y', 'writeDoubleLE', 8]);
MsgBasePosEcef.prototype.fieldSpec.push(['z', 'writeDoubleLE', 8]);

/**
 * SBP class for message fragment EphemerisCommonContent
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 * @field toe GPSTimeSec Time of Ephemerides
 * @field ura number (float, 4 bytes) User Range Accuracy
 * @field fit_interval number (unsigned 32-bit int, 4 bytes) Curve fit interval
 * @field valid number (unsigned 8-bit int, 1 byte) Status of ephemeris, 1 = valid, 0 = invalid
 * @field health_bits number (unsigned 8-bit int, 1 byte) Satellite health status. GPS: ICD-GPS-200, chapter 20.3.3.3.1.4 SBAS: 0 = valid,
 *   non-zero = invalid GLO: 0 = valid, non-zero = invalid
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var EphemerisCommonContent = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "EphemerisCommonContent";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
EphemerisCommonContent.prototype = Object.create(SBP.prototype);
EphemerisCommonContent.prototype.messageType = "EphemerisCommonContent";
EphemerisCommonContent.prototype.constructor = EphemerisCommonContent;
EphemerisCommonContent.prototype.parser = new Parser()
  .endianess('little')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .nest('toe', { type: GPSTimeSec.prototype.parser })
  .floatle('ura')
  .uint32('fit_interval')
  .uint8('valid')
  .uint8('health_bits');
EphemerisCommonContent.prototype.fieldSpec = [];
EphemerisCommonContent.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
EphemerisCommonContent.prototype.fieldSpec.push(['toe', GPSTimeSec.prototype.fieldSpec]);
EphemerisCommonContent.prototype.fieldSpec.push(['ura', 'writeFloatLE', 4]);
EphemerisCommonContent.prototype.fieldSpec.push(['fit_interval', 'writeUInt32LE', 4]);
EphemerisCommonContent.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
EphemerisCommonContent.prototype.fieldSpec.push(['health_bits', 'writeUInt8', 1]);

/**
 * SBP class for message fragment EphemerisCommonContentDepB
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 * @field toe GPSTimeSec Time of Ephemerides
 * @field ura number (float, 8 bytes) User Range Accuracy
 * @field fit_interval number (unsigned 32-bit int, 4 bytes) Curve fit interval
 * @field valid number (unsigned 8-bit int, 1 byte) Status of ephemeris, 1 = valid, 0 = invalid
 * @field health_bits number (unsigned 8-bit int, 1 byte) Satellite health status. GPS: ICD-GPS-200, chapter 20.3.3.3.1.4 SBAS: 0 = valid,
 *   non-zero = invalid GLO: 0 = valid, non-zero = invalid
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var EphemerisCommonContentDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "EphemerisCommonContentDepB";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
EphemerisCommonContentDepB.prototype = Object.create(SBP.prototype);
EphemerisCommonContentDepB.prototype.messageType = "EphemerisCommonContentDepB";
EphemerisCommonContentDepB.prototype.constructor = EphemerisCommonContentDepB;
EphemerisCommonContentDepB.prototype.parser = new Parser()
  .endianess('little')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .nest('toe', { type: GPSTimeSec.prototype.parser })
  .doublele('ura')
  .uint32('fit_interval')
  .uint8('valid')
  .uint8('health_bits');
EphemerisCommonContentDepB.prototype.fieldSpec = [];
EphemerisCommonContentDepB.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
EphemerisCommonContentDepB.prototype.fieldSpec.push(['toe', GPSTimeSec.prototype.fieldSpec]);
EphemerisCommonContentDepB.prototype.fieldSpec.push(['ura', 'writeDoubleLE', 8]);
EphemerisCommonContentDepB.prototype.fieldSpec.push(['fit_interval', 'writeUInt32LE', 4]);
EphemerisCommonContentDepB.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
EphemerisCommonContentDepB.prototype.fieldSpec.push(['health_bits', 'writeUInt8', 1]);

/**
 * SBP class for message fragment EphemerisCommonContentDepA
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field sid GnssSignalDep GNSS signal identifier
 * @field toe GPSTimeDep Time of Ephemerides
 * @field ura number (float, 8 bytes) User Range Accuracy
 * @field fit_interval number (unsigned 32-bit int, 4 bytes) Curve fit interval
 * @field valid number (unsigned 8-bit int, 1 byte) Status of ephemeris, 1 = valid, 0 = invalid
 * @field health_bits number (unsigned 8-bit int, 1 byte) Satellite health status. GPS: ICD-GPS-200, chapter 20.3.3.3.1.4 SBAS: 0 = valid,
 *   non-zero = invalid GLO: 0 = valid, non-zero = invalid
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var EphemerisCommonContentDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "EphemerisCommonContentDepA";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
EphemerisCommonContentDepA.prototype = Object.create(SBP.prototype);
EphemerisCommonContentDepA.prototype.messageType = "EphemerisCommonContentDepA";
EphemerisCommonContentDepA.prototype.constructor = EphemerisCommonContentDepA;
EphemerisCommonContentDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .nest('toe', { type: GPSTimeDep.prototype.parser })
  .doublele('ura')
  .uint32('fit_interval')
  .uint8('valid')
  .uint8('health_bits');
EphemerisCommonContentDepA.prototype.fieldSpec = [];
EphemerisCommonContentDepA.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
EphemerisCommonContentDepA.prototype.fieldSpec.push(['toe', GPSTimeDep.prototype.fieldSpec]);
EphemerisCommonContentDepA.prototype.fieldSpec.push(['ura', 'writeDoubleLE', 8]);
EphemerisCommonContentDepA.prototype.fieldSpec.push(['fit_interval', 'writeUInt32LE', 4]);
EphemerisCommonContentDepA.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
EphemerisCommonContentDepA.prototype.fieldSpec.push(['health_bits', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_EPHEMERIS_GPS_DEP_E (0x0081).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate GPS satellite position, velocity, and clock offset. Please see the
 * Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200, Table 20-III)
 * for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContentDepA Values common for all ephemeris types
 * @field tgd number (float, 8 bytes) Group delay differential between L1 and L2
 * @field c_rs number (float, 8 bytes) Amplitude of the sine harmonic correction term to the orbit radius
 * @field c_rc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the orbit radius
 * @field c_uc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the argument of latitude
 * @field c_us number (float, 8 bytes) Amplitude of the sine harmonic correction term to the argument of latitude
 * @field c_ic number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the angle of inclination
 * @field c_is number (float, 8 bytes) Amplitude of the sine harmonic correction term to the angle of inclination
 * @field dn number (float, 8 bytes) Mean motion difference
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field inc_dot number (float, 8 bytes) Inclination first derivative
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 * @field af2 number (float, 8 bytes) Polynomial clock correction coefficient (rate of clock drift)
 * @field toc GPSTimeDep Clock reference
 * @field iode number (unsigned 8-bit int, 1 byte) Issue of ephemeris data
 * @field iodc number (unsigned 16-bit int, 2 bytes) Issue of clock data
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisGpsDepE = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_GPS_DEP_E";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisGpsDepE.prototype = Object.create(SBP.prototype);
MsgEphemerisGpsDepE.prototype.messageType = "MSG_EPHEMERIS_GPS_DEP_E";
MsgEphemerisGpsDepE.prototype.msg_type = 0x0081;
MsgEphemerisGpsDepE.prototype.constructor = MsgEphemerisGpsDepE;
MsgEphemerisGpsDepE.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContentDepA.prototype.parser })
  .doublele('tgd')
  .doublele('c_rs')
  .doublele('c_rc')
  .doublele('c_uc')
  .doublele('c_us')
  .doublele('c_ic')
  .doublele('c_is')
  .doublele('dn')
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .doublele('inc_dot')
  .doublele('af0')
  .doublele('af1')
  .doublele('af2')
  .nest('toc', { type: GPSTimeDep.prototype.parser })
  .uint8('iode')
  .uint16('iodc');
MsgEphemerisGpsDepE.prototype.fieldSpec = [];
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['common', EphemerisCommonContentDepA.prototype.fieldSpec]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['tgd', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['c_rs', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['c_rc', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['c_uc', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['c_us', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['c_ic', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['c_is', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['dn', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['inc_dot', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['af2', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['toc', GPSTimeDep.prototype.fieldSpec]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['iode', 'writeUInt8', 1]);
MsgEphemerisGpsDepE.prototype.fieldSpec.push(['iodc', 'writeUInt16LE', 2]);

/**
 * SBP class for message MSG_EPHEMERIS_GPS_DEP_F (0x0086).
 *
 * This observation message has been deprecated in favor of ephemeris message using
 * floats for size reduction.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContentDepB Values common for all ephemeris types
 * @field tgd number (float, 8 bytes) Group delay differential between L1 and L2
 * @field c_rs number (float, 8 bytes) Amplitude of the sine harmonic correction term to the orbit radius
 * @field c_rc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the orbit radius
 * @field c_uc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the argument of latitude
 * @field c_us number (float, 8 bytes) Amplitude of the sine harmonic correction term to the argument of latitude
 * @field c_ic number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the angle of inclination
 * @field c_is number (float, 8 bytes) Amplitude of the sine harmonic correction term to the angle of inclination
 * @field dn number (float, 8 bytes) Mean motion difference
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field inc_dot number (float, 8 bytes) Inclination first derivative
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 * @field af2 number (float, 8 bytes) Polynomial clock correction coefficient (rate of clock drift)
 * @field toc GPSTimeSec Clock reference
 * @field iode number (unsigned 8-bit int, 1 byte) Issue of ephemeris data
 * @field iodc number (unsigned 16-bit int, 2 bytes) Issue of clock data
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisGpsDepF = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_GPS_DEP_F";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisGpsDepF.prototype = Object.create(SBP.prototype);
MsgEphemerisGpsDepF.prototype.messageType = "MSG_EPHEMERIS_GPS_DEP_F";
MsgEphemerisGpsDepF.prototype.msg_type = 0x0086;
MsgEphemerisGpsDepF.prototype.constructor = MsgEphemerisGpsDepF;
MsgEphemerisGpsDepF.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContentDepB.prototype.parser })
  .doublele('tgd')
  .doublele('c_rs')
  .doublele('c_rc')
  .doublele('c_uc')
  .doublele('c_us')
  .doublele('c_ic')
  .doublele('c_is')
  .doublele('dn')
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .doublele('inc_dot')
  .doublele('af0')
  .doublele('af1')
  .doublele('af2')
  .nest('toc', { type: GPSTimeSec.prototype.parser })
  .uint8('iode')
  .uint16('iodc');
MsgEphemerisGpsDepF.prototype.fieldSpec = [];
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['common', EphemerisCommonContentDepB.prototype.fieldSpec]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['tgd', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['c_rs', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['c_rc', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['c_uc', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['c_us', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['c_ic', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['c_is', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['dn', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['inc_dot', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['af2', 'writeDoubleLE', 8]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['toc', GPSTimeSec.prototype.fieldSpec]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['iode', 'writeUInt8', 1]);
MsgEphemerisGpsDepF.prototype.fieldSpec.push(['iodc', 'writeUInt16LE', 2]);

/**
 * SBP class for message MSG_EPHEMERIS_GPS (0x008A).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate GPS satellite position, velocity, and clock offset. Please see the
 * Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200, Table 20-III)
 * for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContent Values common for all ephemeris types
 * @field tgd number (float, 4 bytes) Group delay differential between L1 and L2
 * @field c_rs number (float, 4 bytes) Amplitude of the sine harmonic correction term to the orbit radius
 * @field c_rc number (float, 4 bytes) Amplitude of the cosine harmonic correction term to the orbit radius
 * @field c_uc number (float, 4 bytes) Amplitude of the cosine harmonic correction term to the argument of latitude
 * @field c_us number (float, 4 bytes) Amplitude of the sine harmonic correction term to the argument of latitude
 * @field c_ic number (float, 4 bytes) Amplitude of the cosine harmonic correction term to the angle of inclination
 * @field c_is number (float, 4 bytes) Amplitude of the sine harmonic correction term to the angle of inclination
 * @field dn number (float, 4 bytes) Mean motion difference
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field inc_dot number (float, 4 bytes) Inclination first derivative
 * @field af0 number (float, 4 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 4 bytes) Polynomial clock correction coefficient (clock drift)
 * @field af2 number (float, 4 bytes) Polynomial clock correction coefficient (rate of clock drift)
 * @field toc GPSTimeSec Clock reference
 * @field iode number (unsigned 8-bit int, 1 byte) Issue of ephemeris data
 * @field iodc number (unsigned 16-bit int, 2 bytes) Issue of clock data
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisGps = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_GPS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisGps.prototype = Object.create(SBP.prototype);
MsgEphemerisGps.prototype.messageType = "MSG_EPHEMERIS_GPS";
MsgEphemerisGps.prototype.msg_type = 0x008A;
MsgEphemerisGps.prototype.constructor = MsgEphemerisGps;
MsgEphemerisGps.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContent.prototype.parser })
  .floatle('tgd')
  .floatle('c_rs')
  .floatle('c_rc')
  .floatle('c_uc')
  .floatle('c_us')
  .floatle('c_ic')
  .floatle('c_is')
  .floatle('dn')
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .floatle('inc_dot')
  .floatle('af0')
  .floatle('af1')
  .floatle('af2')
  .nest('toc', { type: GPSTimeSec.prototype.parser })
  .uint8('iode')
  .uint16('iodc');
MsgEphemerisGps.prototype.fieldSpec = [];
MsgEphemerisGps.prototype.fieldSpec.push(['common', EphemerisCommonContent.prototype.fieldSpec]);
MsgEphemerisGps.prototype.fieldSpec.push(['tgd', 'writeFloatLE', 4]);
MsgEphemerisGps.prototype.fieldSpec.push(['c_rs', 'writeFloatLE', 4]);
MsgEphemerisGps.prototype.fieldSpec.push(['c_rc', 'writeFloatLE', 4]);
MsgEphemerisGps.prototype.fieldSpec.push(['c_uc', 'writeFloatLE', 4]);
MsgEphemerisGps.prototype.fieldSpec.push(['c_us', 'writeFloatLE', 4]);
MsgEphemerisGps.prototype.fieldSpec.push(['c_ic', 'writeFloatLE', 4]);
MsgEphemerisGps.prototype.fieldSpec.push(['c_is', 'writeFloatLE', 4]);
MsgEphemerisGps.prototype.fieldSpec.push(['dn', 'writeFloatLE', 4]);
MsgEphemerisGps.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgEphemerisGps.prototype.fieldSpec.push(['inc_dot', 'writeFloatLE', 4]);
MsgEphemerisGps.prototype.fieldSpec.push(['af0', 'writeFloatLE', 4]);
MsgEphemerisGps.prototype.fieldSpec.push(['af1', 'writeFloatLE', 4]);
MsgEphemerisGps.prototype.fieldSpec.push(['af2', 'writeFloatLE', 4]);
MsgEphemerisGps.prototype.fieldSpec.push(['toc', GPSTimeSec.prototype.fieldSpec]);
MsgEphemerisGps.prototype.fieldSpec.push(['iode', 'writeUInt8', 1]);
MsgEphemerisGps.prototype.fieldSpec.push(['iodc', 'writeUInt16LE', 2]);

/**
 * SBP class for message MSG_EPHEMERIS_SBAS_DEP_A (0x0082).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContentDepA Values common for all ephemeris types
 * @field pos array Position of the GEO at time toe
 * @field vel array Velocity of the GEO at time toe
 * @field acc array Acceleration of the GEO at time toe
 * @field a_gf0 number (float, 8 bytes) Time offset of the GEO clock w.r.t. SBAS Network Time
 * @field a_gf1 number (float, 8 bytes) Drift of the GEO clock w.r.t. SBAS Network Time
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisSbasDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_SBAS_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisSbasDepA.prototype = Object.create(SBP.prototype);
MsgEphemerisSbasDepA.prototype.messageType = "MSG_EPHEMERIS_SBAS_DEP_A";
MsgEphemerisSbasDepA.prototype.msg_type = 0x0082;
MsgEphemerisSbasDepA.prototype.constructor = MsgEphemerisSbasDepA;
MsgEphemerisSbasDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContentDepA.prototype.parser })
  .array('pos', { length: 3, type: 'doublele' })
  .array('vel', { length: 3, type: 'doublele' })
  .array('acc', { length: 3, type: 'doublele' })
  .doublele('a_gf0')
  .doublele('a_gf1');
MsgEphemerisSbasDepA.prototype.fieldSpec = [];
MsgEphemerisSbasDepA.prototype.fieldSpec.push(['common', EphemerisCommonContentDepA.prototype.fieldSpec]);
MsgEphemerisSbasDepA.prototype.fieldSpec.push(['pos', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisSbasDepA.prototype.fieldSpec.push(['vel', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisSbasDepA.prototype.fieldSpec.push(['acc', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisSbasDepA.prototype.fieldSpec.push(['a_gf0', 'writeDoubleLE', 8]);
MsgEphemerisSbasDepA.prototype.fieldSpec.push(['a_gf1', 'writeDoubleLE', 8]);

/**
 * SBP class for message MSG_EPHEMERIS_GLO_DEP_A (0x0083).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate GLO satellite position, velocity, and clock offset. Please see the
 * GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate information
 * (ephemeris parameters)" for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContentDepA Values common for all ephemeris types
 * @field gamma number (float, 8 bytes) Relative deviation of predicted carrier frequency from nominal
 * @field tau number (float, 8 bytes) Correction to the SV time
 * @field pos array Position of the SV at tb in PZ-90.02 coordinates system
 * @field vel array Velocity vector of the SV at tb in PZ-90.02 coordinates system
 * @field acc array Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisGloDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_GLO_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisGloDepA.prototype = Object.create(SBP.prototype);
MsgEphemerisGloDepA.prototype.messageType = "MSG_EPHEMERIS_GLO_DEP_A";
MsgEphemerisGloDepA.prototype.msg_type = 0x0083;
MsgEphemerisGloDepA.prototype.constructor = MsgEphemerisGloDepA;
MsgEphemerisGloDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContentDepA.prototype.parser })
  .doublele('gamma')
  .doublele('tau')
  .array('pos', { length: 3, type: 'doublele' })
  .array('vel', { length: 3, type: 'doublele' })
  .array('acc', { length: 3, type: 'doublele' });
MsgEphemerisGloDepA.prototype.fieldSpec = [];
MsgEphemerisGloDepA.prototype.fieldSpec.push(['common', EphemerisCommonContentDepA.prototype.fieldSpec]);
MsgEphemerisGloDepA.prototype.fieldSpec.push(['gamma', 'writeDoubleLE', 8]);
MsgEphemerisGloDepA.prototype.fieldSpec.push(['tau', 'writeDoubleLE', 8]);
MsgEphemerisGloDepA.prototype.fieldSpec.push(['pos', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepA.prototype.fieldSpec.push(['vel', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepA.prototype.fieldSpec.push(['acc', 'array', 'writeDoubleLE', function () { return 8; }, 3]);

/**
 * SBP class for message MSG_EPHEMERIS_SBAS_DEP_B (0x0084).
 *
 * This observation message has been deprecated in favor of ephemeris message using
 * floats for size reduction.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContentDepB Values common for all ephemeris types
 * @field pos array Position of the GEO at time toe
 * @field vel array Velocity of the GEO at time toe
 * @field acc array Acceleration of the GEO at time toe
 * @field a_gf0 number (float, 8 bytes) Time offset of the GEO clock w.r.t. SBAS Network Time
 * @field a_gf1 number (float, 8 bytes) Drift of the GEO clock w.r.t. SBAS Network Time
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisSbasDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_SBAS_DEP_B";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisSbasDepB.prototype = Object.create(SBP.prototype);
MsgEphemerisSbasDepB.prototype.messageType = "MSG_EPHEMERIS_SBAS_DEP_B";
MsgEphemerisSbasDepB.prototype.msg_type = 0x0084;
MsgEphemerisSbasDepB.prototype.constructor = MsgEphemerisSbasDepB;
MsgEphemerisSbasDepB.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContentDepB.prototype.parser })
  .array('pos', { length: 3, type: 'doublele' })
  .array('vel', { length: 3, type: 'doublele' })
  .array('acc', { length: 3, type: 'doublele' })
  .doublele('a_gf0')
  .doublele('a_gf1');
MsgEphemerisSbasDepB.prototype.fieldSpec = [];
MsgEphemerisSbasDepB.prototype.fieldSpec.push(['common', EphemerisCommonContentDepB.prototype.fieldSpec]);
MsgEphemerisSbasDepB.prototype.fieldSpec.push(['pos', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisSbasDepB.prototype.fieldSpec.push(['vel', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisSbasDepB.prototype.fieldSpec.push(['acc', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisSbasDepB.prototype.fieldSpec.push(['a_gf0', 'writeDoubleLE', 8]);
MsgEphemerisSbasDepB.prototype.fieldSpec.push(['a_gf1', 'writeDoubleLE', 8]);

/**
 * SBP class for message MSG_EPHEMERIS_SBAS (0x008C).
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContent Values common for all ephemeris types
 * @field pos array Position of the GEO at time toe
 * @field vel array Velocity of the GEO at time toe
 * @field acc array Acceleration of the GEO at time toe
 * @field a_gf0 number (float, 4 bytes) Time offset of the GEO clock w.r.t. SBAS Network Time
 * @field a_gf1 number (float, 4 bytes) Drift of the GEO clock w.r.t. SBAS Network Time
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisSbas = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_SBAS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisSbas.prototype = Object.create(SBP.prototype);
MsgEphemerisSbas.prototype.messageType = "MSG_EPHEMERIS_SBAS";
MsgEphemerisSbas.prototype.msg_type = 0x008C;
MsgEphemerisSbas.prototype.constructor = MsgEphemerisSbas;
MsgEphemerisSbas.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContent.prototype.parser })
  .array('pos', { length: 3, type: 'doublele' })
  .array('vel', { length: 3, type: 'floatle' })
  .array('acc', { length: 3, type: 'floatle' })
  .floatle('a_gf0')
  .floatle('a_gf1');
MsgEphemerisSbas.prototype.fieldSpec = [];
MsgEphemerisSbas.prototype.fieldSpec.push(['common', EphemerisCommonContent.prototype.fieldSpec]);
MsgEphemerisSbas.prototype.fieldSpec.push(['pos', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisSbas.prototype.fieldSpec.push(['vel', 'array', 'writeFloatLE', function () { return 4; }, 3]);
MsgEphemerisSbas.prototype.fieldSpec.push(['acc', 'array', 'writeFloatLE', function () { return 4; }, 3]);
MsgEphemerisSbas.prototype.fieldSpec.push(['a_gf0', 'writeFloatLE', 4]);
MsgEphemerisSbas.prototype.fieldSpec.push(['a_gf1', 'writeFloatLE', 4]);

/**
 * SBP class for message MSG_EPHEMERIS_GLO_DEP_B (0x0085).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate GLO satellite position, velocity, and clock offset. Please see the
 * GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate information
 * (ephemeris parameters)" for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContentDepB Values common for all ephemeris types
 * @field gamma number (float, 8 bytes) Relative deviation of predicted carrier frequency from nominal
 * @field tau number (float, 8 bytes) Correction to the SV time
 * @field pos array Position of the SV at tb in PZ-90.02 coordinates system
 * @field vel array Velocity vector of the SV at tb in PZ-90.02 coordinates system
 * @field acc array Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisGloDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_GLO_DEP_B";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisGloDepB.prototype = Object.create(SBP.prototype);
MsgEphemerisGloDepB.prototype.messageType = "MSG_EPHEMERIS_GLO_DEP_B";
MsgEphemerisGloDepB.prototype.msg_type = 0x0085;
MsgEphemerisGloDepB.prototype.constructor = MsgEphemerisGloDepB;
MsgEphemerisGloDepB.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContentDepB.prototype.parser })
  .doublele('gamma')
  .doublele('tau')
  .array('pos', { length: 3, type: 'doublele' })
  .array('vel', { length: 3, type: 'doublele' })
  .array('acc', { length: 3, type: 'doublele' });
MsgEphemerisGloDepB.prototype.fieldSpec = [];
MsgEphemerisGloDepB.prototype.fieldSpec.push(['common', EphemerisCommonContentDepB.prototype.fieldSpec]);
MsgEphemerisGloDepB.prototype.fieldSpec.push(['gamma', 'writeDoubleLE', 8]);
MsgEphemerisGloDepB.prototype.fieldSpec.push(['tau', 'writeDoubleLE', 8]);
MsgEphemerisGloDepB.prototype.fieldSpec.push(['pos', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepB.prototype.fieldSpec.push(['vel', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepB.prototype.fieldSpec.push(['acc', 'array', 'writeDoubleLE', function () { return 8; }, 3]);

/**
 * SBP class for message MSG_EPHEMERIS_GLO_DEP_C (0x0087).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate GLO satellite position, velocity, and clock offset. Please see the
 * GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate information
 * (ephemeris parameters)" for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContentDepB Values common for all ephemeris types
 * @field gamma number (float, 8 bytes) Relative deviation of predicted carrier frequency from nominal
 * @field tau number (float, 8 bytes) Correction to the SV time
 * @field d_tau number (float, 8 bytes) Equipment delay between L1 and L2
 * @field pos array Position of the SV at tb in PZ-90.02 coordinates system
 * @field vel array Velocity vector of the SV at tb in PZ-90.02 coordinates system
 * @field acc array Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
 * @field fcn number (unsigned 8-bit int, 1 byte) Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisGloDepC = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_GLO_DEP_C";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisGloDepC.prototype = Object.create(SBP.prototype);
MsgEphemerisGloDepC.prototype.messageType = "MSG_EPHEMERIS_GLO_DEP_C";
MsgEphemerisGloDepC.prototype.msg_type = 0x0087;
MsgEphemerisGloDepC.prototype.constructor = MsgEphemerisGloDepC;
MsgEphemerisGloDepC.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContentDepB.prototype.parser })
  .doublele('gamma')
  .doublele('tau')
  .doublele('d_tau')
  .array('pos', { length: 3, type: 'doublele' })
  .array('vel', { length: 3, type: 'doublele' })
  .array('acc', { length: 3, type: 'doublele' })
  .uint8('fcn');
MsgEphemerisGloDepC.prototype.fieldSpec = [];
MsgEphemerisGloDepC.prototype.fieldSpec.push(['common', EphemerisCommonContentDepB.prototype.fieldSpec]);
MsgEphemerisGloDepC.prototype.fieldSpec.push(['gamma', 'writeDoubleLE', 8]);
MsgEphemerisGloDepC.prototype.fieldSpec.push(['tau', 'writeDoubleLE', 8]);
MsgEphemerisGloDepC.prototype.fieldSpec.push(['d_tau', 'writeDoubleLE', 8]);
MsgEphemerisGloDepC.prototype.fieldSpec.push(['pos', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepC.prototype.fieldSpec.push(['vel', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepC.prototype.fieldSpec.push(['acc', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepC.prototype.fieldSpec.push(['fcn', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_EPHEMERIS_GLO_DEP_D (0x0088).
 *
 * This observation message has been deprecated in favor of ephemeris message using
 * floats for size reduction.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContentDepB Values common for all ephemeris types
 * @field gamma number (float, 8 bytes) Relative deviation of predicted carrier frequency from nominal
 * @field tau number (float, 8 bytes) Correction to the SV time
 * @field d_tau number (float, 8 bytes) Equipment delay between L1 and L2
 * @field pos array Position of the SV at tb in PZ-90.02 coordinates system
 * @field vel array Velocity vector of the SV at tb in PZ-90.02 coordinates system
 * @field acc array Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
 * @field fcn number (unsigned 8-bit int, 1 byte) Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
 * @field iod number (unsigned 8-bit int, 1 byte) Issue of ephemeris data
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisGloDepD = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_GLO_DEP_D";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisGloDepD.prototype = Object.create(SBP.prototype);
MsgEphemerisGloDepD.prototype.messageType = "MSG_EPHEMERIS_GLO_DEP_D";
MsgEphemerisGloDepD.prototype.msg_type = 0x0088;
MsgEphemerisGloDepD.prototype.constructor = MsgEphemerisGloDepD;
MsgEphemerisGloDepD.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContentDepB.prototype.parser })
  .doublele('gamma')
  .doublele('tau')
  .doublele('d_tau')
  .array('pos', { length: 3, type: 'doublele' })
  .array('vel', { length: 3, type: 'doublele' })
  .array('acc', { length: 3, type: 'doublele' })
  .uint8('fcn')
  .uint8('iod');
MsgEphemerisGloDepD.prototype.fieldSpec = [];
MsgEphemerisGloDepD.prototype.fieldSpec.push(['common', EphemerisCommonContentDepB.prototype.fieldSpec]);
MsgEphemerisGloDepD.prototype.fieldSpec.push(['gamma', 'writeDoubleLE', 8]);
MsgEphemerisGloDepD.prototype.fieldSpec.push(['tau', 'writeDoubleLE', 8]);
MsgEphemerisGloDepD.prototype.fieldSpec.push(['d_tau', 'writeDoubleLE', 8]);
MsgEphemerisGloDepD.prototype.fieldSpec.push(['pos', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepD.prototype.fieldSpec.push(['vel', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepD.prototype.fieldSpec.push(['acc', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGloDepD.prototype.fieldSpec.push(['fcn', 'writeUInt8', 1]);
MsgEphemerisGloDepD.prototype.fieldSpec.push(['iod', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_EPHEMERIS_GLO (0x008B).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate GLO satellite position, velocity, and clock offset. Please see the
 * GLO ICD 5.1 "Table 4.5 Characteristics of words of immediate information
 * (ephemeris parameters)" for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common EphemerisCommonContent Values common for all ephemeris types
 * @field gamma number (float, 4 bytes) Relative deviation of predicted carrier frequency from nominal
 * @field tau number (float, 4 bytes) Correction to the SV time
 * @field d_tau number (float, 4 bytes) Equipment delay between L1 and L2
 * @field pos array Position of the SV at tb in PZ-90.02 coordinates system
 * @field vel array Velocity vector of the SV at tb in PZ-90.02 coordinates system
 * @field acc array Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
 * @field fcn number (unsigned 8-bit int, 1 byte) Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
 * @field iod number (unsigned 8-bit int, 1 byte) Issue of ephemeris data
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisGlo = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_GLO";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisGlo.prototype = Object.create(SBP.prototype);
MsgEphemerisGlo.prototype.messageType = "MSG_EPHEMERIS_GLO";
MsgEphemerisGlo.prototype.msg_type = 0x008B;
MsgEphemerisGlo.prototype.constructor = MsgEphemerisGlo;
MsgEphemerisGlo.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: EphemerisCommonContent.prototype.parser })
  .floatle('gamma')
  .floatle('tau')
  .floatle('d_tau')
  .array('pos', { length: 3, type: 'doublele' })
  .array('vel', { length: 3, type: 'doublele' })
  .array('acc', { length: 3, type: 'floatle' })
  .uint8('fcn')
  .uint8('iod');
MsgEphemerisGlo.prototype.fieldSpec = [];
MsgEphemerisGlo.prototype.fieldSpec.push(['common', EphemerisCommonContent.prototype.fieldSpec]);
MsgEphemerisGlo.prototype.fieldSpec.push(['gamma', 'writeFloatLE', 4]);
MsgEphemerisGlo.prototype.fieldSpec.push(['tau', 'writeFloatLE', 4]);
MsgEphemerisGlo.prototype.fieldSpec.push(['d_tau', 'writeFloatLE', 4]);
MsgEphemerisGlo.prototype.fieldSpec.push(['pos', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGlo.prototype.fieldSpec.push(['vel', 'array', 'writeDoubleLE', function () { return 8; }, 3]);
MsgEphemerisGlo.prototype.fieldSpec.push(['acc', 'array', 'writeFloatLE', function () { return 4; }, 3]);
MsgEphemerisGlo.prototype.fieldSpec.push(['fcn', 'writeUInt8', 1]);
MsgEphemerisGlo.prototype.fieldSpec.push(['iod', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_EPHEMERIS_DEP_D (0x0080).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate GPS satellite position, velocity, and clock offset. Please see the
 * Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200, Table 20-III)
 * for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tgd number (float, 8 bytes) Group delay differential between L1 and L2
 * @field c_rs number (float, 8 bytes) Amplitude of the sine harmonic correction term to the orbit radius
 * @field c_rc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the orbit radius
 * @field c_uc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the argument of latitude
 * @field c_us number (float, 8 bytes) Amplitude of the sine harmonic correction term to the argument of latitude
 * @field c_ic number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the angle of inclination
 * @field c_is number (float, 8 bytes) Amplitude of the sine harmonic correction term to the angle of inclination
 * @field dn number (float, 8 bytes) Mean motion difference
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field inc_dot number (float, 8 bytes) Inclination first derivative
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 * @field af2 number (float, 8 bytes) Polynomial clock correction coefficient (rate of clock drift)
 * @field toe_tow number (float, 8 bytes) Time of week
 * @field toe_wn number (unsigned 16-bit int, 2 bytes) Week number
 * @field toc_tow number (float, 8 bytes) Clock reference time of week
 * @field toc_wn number (unsigned 16-bit int, 2 bytes) Clock reference week number
 * @field valid number (unsigned 8-bit int, 1 byte) Is valid?
 * @field healthy number (unsigned 8-bit int, 1 byte) Satellite is healthy?
 * @field sid GnssSignalDep GNSS signal identifier
 * @field iode number (unsigned 8-bit int, 1 byte) Issue of ephemeris data
 * @field iodc number (unsigned 16-bit int, 2 bytes) Issue of clock data
 * @field reserved number (unsigned 32-bit int, 4 bytes) Reserved field
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisDepD = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_DEP_D";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisDepD.prototype = Object.create(SBP.prototype);
MsgEphemerisDepD.prototype.messageType = "MSG_EPHEMERIS_DEP_D";
MsgEphemerisDepD.prototype.msg_type = 0x0080;
MsgEphemerisDepD.prototype.constructor = MsgEphemerisDepD;
MsgEphemerisDepD.prototype.parser = new Parser()
  .endianess('little')
  .doublele('tgd')
  .doublele('c_rs')
  .doublele('c_rc')
  .doublele('c_uc')
  .doublele('c_us')
  .doublele('c_ic')
  .doublele('c_is')
  .doublele('dn')
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .doublele('inc_dot')
  .doublele('af0')
  .doublele('af1')
  .doublele('af2')
  .doublele('toe_tow')
  .uint16('toe_wn')
  .doublele('toc_tow')
  .uint16('toc_wn')
  .uint8('valid')
  .uint8('healthy')
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .uint8('iode')
  .uint16('iodc')
  .uint32('reserved');
MsgEphemerisDepD.prototype.fieldSpec = [];
MsgEphemerisDepD.prototype.fieldSpec.push(['tgd', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['c_rs', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['c_rc', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['c_uc', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['c_us', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['c_ic', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['c_is', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['dn', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['inc_dot', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['af2', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['toe_tow', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['toe_wn', 'writeUInt16LE', 2]);
MsgEphemerisDepD.prototype.fieldSpec.push(['toc_tow', 'writeDoubleLE', 8]);
MsgEphemerisDepD.prototype.fieldSpec.push(['toc_wn', 'writeUInt16LE', 2]);
MsgEphemerisDepD.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
MsgEphemerisDepD.prototype.fieldSpec.push(['healthy', 'writeUInt8', 1]);
MsgEphemerisDepD.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
MsgEphemerisDepD.prototype.fieldSpec.push(['iode', 'writeUInt8', 1]);
MsgEphemerisDepD.prototype.fieldSpec.push(['iodc', 'writeUInt16LE', 2]);
MsgEphemerisDepD.prototype.fieldSpec.push(['reserved', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_EPHEMERIS_DEP_A (0x001A).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tgd number (float, 8 bytes) Group delay differential between L1 and L2
 * @field c_rs number (float, 8 bytes) Amplitude of the sine harmonic correction term to the orbit radius
 * @field c_rc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the orbit radius
 * @field c_uc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the argument of latitude
 * @field c_us number (float, 8 bytes) Amplitude of the sine harmonic correction term to the argument of latitude
 * @field c_ic number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the angle of inclination
 * @field c_is number (float, 8 bytes) Amplitude of the sine harmonic correction term to the angle of inclination
 * @field dn number (float, 8 bytes) Mean motion difference
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field inc_dot number (float, 8 bytes) Inclination first derivative
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 * @field af2 number (float, 8 bytes) Polynomial clock correction coefficient (rate of clock drift)
 * @field toe_tow number (float, 8 bytes) Time of week
 * @field toe_wn number (unsigned 16-bit int, 2 bytes) Week number
 * @field toc_tow number (float, 8 bytes) Clock reference time of week
 * @field toc_wn number (unsigned 16-bit int, 2 bytes) Clock reference week number
 * @field valid number (unsigned 8-bit int, 1 byte) Is valid?
 * @field healthy number (unsigned 8-bit int, 1 byte) Satellite is healthy?
 * @field prn number (unsigned 8-bit int, 1 byte) PRN being tracked
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisDepA.prototype = Object.create(SBP.prototype);
MsgEphemerisDepA.prototype.messageType = "MSG_EPHEMERIS_DEP_A";
MsgEphemerisDepA.prototype.msg_type = 0x001A;
MsgEphemerisDepA.prototype.constructor = MsgEphemerisDepA;
MsgEphemerisDepA.prototype.parser = new Parser()
  .endianess('little')
  .doublele('tgd')
  .doublele('c_rs')
  .doublele('c_rc')
  .doublele('c_uc')
  .doublele('c_us')
  .doublele('c_ic')
  .doublele('c_is')
  .doublele('dn')
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .doublele('inc_dot')
  .doublele('af0')
  .doublele('af1')
  .doublele('af2')
  .doublele('toe_tow')
  .uint16('toe_wn')
  .doublele('toc_tow')
  .uint16('toc_wn')
  .uint8('valid')
  .uint8('healthy')
  .uint8('prn');
MsgEphemerisDepA.prototype.fieldSpec = [];
MsgEphemerisDepA.prototype.fieldSpec.push(['tgd', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['c_rs', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['c_rc', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['c_uc', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['c_us', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['c_ic', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['c_is', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['dn', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['inc_dot', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['af2', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['toe_tow', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['toe_wn', 'writeUInt16LE', 2]);
MsgEphemerisDepA.prototype.fieldSpec.push(['toc_tow', 'writeDoubleLE', 8]);
MsgEphemerisDepA.prototype.fieldSpec.push(['toc_wn', 'writeUInt16LE', 2]);
MsgEphemerisDepA.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
MsgEphemerisDepA.prototype.fieldSpec.push(['healthy', 'writeUInt8', 1]);
MsgEphemerisDepA.prototype.fieldSpec.push(['prn', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_EPHEMERIS_DEP_B (0x0046).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tgd number (float, 8 bytes) Group delay differential between L1 and L2
 * @field c_rs number (float, 8 bytes) Amplitude of the sine harmonic correction term to the orbit radius
 * @field c_rc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the orbit radius
 * @field c_uc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the argument of latitude
 * @field c_us number (float, 8 bytes) Amplitude of the sine harmonic correction term to the argument of latitude
 * @field c_ic number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the angle of inclination
 * @field c_is number (float, 8 bytes) Amplitude of the sine harmonic correction term to the angle of inclination
 * @field dn number (float, 8 bytes) Mean motion difference
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field inc_dot number (float, 8 bytes) Inclination first derivative
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 * @field af2 number (float, 8 bytes) Polynomial clock correction coefficient (rate of clock drift)
 * @field toe_tow number (float, 8 bytes) Time of week
 * @field toe_wn number (unsigned 16-bit int, 2 bytes) Week number
 * @field toc_tow number (float, 8 bytes) Clock reference time of week
 * @field toc_wn number (unsigned 16-bit int, 2 bytes) Clock reference week number
 * @field valid number (unsigned 8-bit int, 1 byte) Is valid?
 * @field healthy number (unsigned 8-bit int, 1 byte) Satellite is healthy?
 * @field prn number (unsigned 8-bit int, 1 byte) PRN being tracked
 * @field iode number (unsigned 8-bit int, 1 byte) Issue of ephemeris data
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_DEP_B";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisDepB.prototype = Object.create(SBP.prototype);
MsgEphemerisDepB.prototype.messageType = "MSG_EPHEMERIS_DEP_B";
MsgEphemerisDepB.prototype.msg_type = 0x0046;
MsgEphemerisDepB.prototype.constructor = MsgEphemerisDepB;
MsgEphemerisDepB.prototype.parser = new Parser()
  .endianess('little')
  .doublele('tgd')
  .doublele('c_rs')
  .doublele('c_rc')
  .doublele('c_uc')
  .doublele('c_us')
  .doublele('c_ic')
  .doublele('c_is')
  .doublele('dn')
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .doublele('inc_dot')
  .doublele('af0')
  .doublele('af1')
  .doublele('af2')
  .doublele('toe_tow')
  .uint16('toe_wn')
  .doublele('toc_tow')
  .uint16('toc_wn')
  .uint8('valid')
  .uint8('healthy')
  .uint8('prn')
  .uint8('iode');
MsgEphemerisDepB.prototype.fieldSpec = [];
MsgEphemerisDepB.prototype.fieldSpec.push(['tgd', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['c_rs', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['c_rc', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['c_uc', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['c_us', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['c_ic', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['c_is', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['dn', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['inc_dot', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['af2', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['toe_tow', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['toe_wn', 'writeUInt16LE', 2]);
MsgEphemerisDepB.prototype.fieldSpec.push(['toc_tow', 'writeDoubleLE', 8]);
MsgEphemerisDepB.prototype.fieldSpec.push(['toc_wn', 'writeUInt16LE', 2]);
MsgEphemerisDepB.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
MsgEphemerisDepB.prototype.fieldSpec.push(['healthy', 'writeUInt8', 1]);
MsgEphemerisDepB.prototype.fieldSpec.push(['prn', 'writeUInt8', 1]);
MsgEphemerisDepB.prototype.fieldSpec.push(['iode', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_EPHEMERIS_DEP_C (0x0047).
 *
 * The ephemeris message returns a set of satellite orbit parameters that is used
 * to calculate GPS satellite position, velocity, and clock offset. Please see the
 * Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200, Table 20-III)
 * for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tgd number (float, 8 bytes) Group delay differential between L1 and L2
 * @field c_rs number (float, 8 bytes) Amplitude of the sine harmonic correction term to the orbit radius
 * @field c_rc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the orbit radius
 * @field c_uc number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the argument of latitude
 * @field c_us number (float, 8 bytes) Amplitude of the sine harmonic correction term to the argument of latitude
 * @field c_ic number (float, 8 bytes) Amplitude of the cosine harmonic correction term to the angle of inclination
 * @field c_is number (float, 8 bytes) Amplitude of the sine harmonic correction term to the angle of inclination
 * @field dn number (float, 8 bytes) Mean motion difference
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field inc_dot number (float, 8 bytes) Inclination first derivative
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 * @field af2 number (float, 8 bytes) Polynomial clock correction coefficient (rate of clock drift)
 * @field toe_tow number (float, 8 bytes) Time of week
 * @field toe_wn number (unsigned 16-bit int, 2 bytes) Week number
 * @field toc_tow number (float, 8 bytes) Clock reference time of week
 * @field toc_wn number (unsigned 16-bit int, 2 bytes) Clock reference week number
 * @field valid number (unsigned 8-bit int, 1 byte) Is valid?
 * @field healthy number (unsigned 8-bit int, 1 byte) Satellite is healthy?
 * @field sid GnssSignalDep GNSS signal identifier
 * @field iode number (unsigned 8-bit int, 1 byte) Issue of ephemeris data
 * @field iodc number (unsigned 16-bit int, 2 bytes) Issue of clock data
 * @field reserved number (unsigned 32-bit int, 4 bytes) Reserved field
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgEphemerisDepC = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_EPHEMERIS_DEP_C";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgEphemerisDepC.prototype = Object.create(SBP.prototype);
MsgEphemerisDepC.prototype.messageType = "MSG_EPHEMERIS_DEP_C";
MsgEphemerisDepC.prototype.msg_type = 0x0047;
MsgEphemerisDepC.prototype.constructor = MsgEphemerisDepC;
MsgEphemerisDepC.prototype.parser = new Parser()
  .endianess('little')
  .doublele('tgd')
  .doublele('c_rs')
  .doublele('c_rc')
  .doublele('c_uc')
  .doublele('c_us')
  .doublele('c_ic')
  .doublele('c_is')
  .doublele('dn')
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .doublele('inc_dot')
  .doublele('af0')
  .doublele('af1')
  .doublele('af2')
  .doublele('toe_tow')
  .uint16('toe_wn')
  .doublele('toc_tow')
  .uint16('toc_wn')
  .uint8('valid')
  .uint8('healthy')
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .uint8('iode')
  .uint16('iodc')
  .uint32('reserved');
MsgEphemerisDepC.prototype.fieldSpec = [];
MsgEphemerisDepC.prototype.fieldSpec.push(['tgd', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['c_rs', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['c_rc', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['c_uc', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['c_us', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['c_ic', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['c_is', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['dn', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['inc_dot', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['af2', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['toe_tow', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['toe_wn', 'writeUInt16LE', 2]);
MsgEphemerisDepC.prototype.fieldSpec.push(['toc_tow', 'writeDoubleLE', 8]);
MsgEphemerisDepC.prototype.fieldSpec.push(['toc_wn', 'writeUInt16LE', 2]);
MsgEphemerisDepC.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
MsgEphemerisDepC.prototype.fieldSpec.push(['healthy', 'writeUInt8', 1]);
MsgEphemerisDepC.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
MsgEphemerisDepC.prototype.fieldSpec.push(['iode', 'writeUInt8', 1]);
MsgEphemerisDepC.prototype.fieldSpec.push(['iodc', 'writeUInt16LE', 2]);
MsgEphemerisDepC.prototype.fieldSpec.push(['reserved', 'writeUInt32LE', 4]);

/**
 * SBP class for message fragment ObservationHeaderDep
 *
 * Header of a GPS observation message.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field t GPSTimeDep GPS time of this observation
 * @field n_obs number (unsigned 8-bit int, 1 byte) Total number of observations. First nibble is the size of the sequence (n),
 *   second nibble is the zero-indexed counter (ith packet of n)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var ObservationHeaderDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "ObservationHeaderDep";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
ObservationHeaderDep.prototype = Object.create(SBP.prototype);
ObservationHeaderDep.prototype.messageType = "ObservationHeaderDep";
ObservationHeaderDep.prototype.constructor = ObservationHeaderDep;
ObservationHeaderDep.prototype.parser = new Parser()
  .endianess('little')
  .nest('t', { type: GPSTimeDep.prototype.parser })
  .uint8('n_obs');
ObservationHeaderDep.prototype.fieldSpec = [];
ObservationHeaderDep.prototype.fieldSpec.push(['t', GPSTimeDep.prototype.fieldSpec]);
ObservationHeaderDep.prototype.fieldSpec.push(['n_obs', 'writeUInt8', 1]);

/**
 * SBP class for message fragment CarrierPhaseDepA
 *
 * Carrier phase measurement in cycles represented as a 40-bit fixed point number
 * with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of fractional cycles.
 * This has the opposite sign convention than a typical GPS receiver and the phase
 * has the opposite sign as the pseudorange.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field i number (signed 32-bit int, 4 bytes) Carrier phase whole cycles
 * @field f number (unsigned 8-bit int, 1 byte) Carrier phase fractional part
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var CarrierPhaseDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "CarrierPhaseDepA";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
CarrierPhaseDepA.prototype = Object.create(SBP.prototype);
CarrierPhaseDepA.prototype.messageType = "CarrierPhaseDepA";
CarrierPhaseDepA.prototype.constructor = CarrierPhaseDepA;
CarrierPhaseDepA.prototype.parser = new Parser()
  .endianess('little')
  .int32('i')
  .uint8('f');
CarrierPhaseDepA.prototype.fieldSpec = [];
CarrierPhaseDepA.prototype.fieldSpec.push(['i', 'writeInt32LE', 4]);
CarrierPhaseDepA.prototype.fieldSpec.push(['f', 'writeUInt8', 1]);

/**
 * SBP class for message fragment PackedObsContentDepA
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field P number (unsigned 32-bit int, 4 bytes) Pseudorange observation
 * @field L CarrierPhaseDepA Carrier phase observation with opposite sign from typical convention
 * @field cn0 number (unsigned 8-bit int, 1 byte) Carrier-to-Noise density
 * @field lock number (unsigned 16-bit int, 2 bytes) Lock indicator. This value changes whenever a satellite signal has lost and
 *   regained lock, indicating that the carrier phase ambiguity may have changed.
 * @field prn number (unsigned 8-bit int, 1 byte) PRN-1 identifier of the satellite signal
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var PackedObsContentDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "PackedObsContentDepA";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
PackedObsContentDepA.prototype = Object.create(SBP.prototype);
PackedObsContentDepA.prototype.messageType = "PackedObsContentDepA";
PackedObsContentDepA.prototype.constructor = PackedObsContentDepA;
PackedObsContentDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint32('P')
  .nest('L', { type: CarrierPhaseDepA.prototype.parser })
  .uint8('cn0')
  .uint16('lock')
  .uint8('prn');
PackedObsContentDepA.prototype.fieldSpec = [];
PackedObsContentDepA.prototype.fieldSpec.push(['P', 'writeUInt32LE', 4]);
PackedObsContentDepA.prototype.fieldSpec.push(['L', CarrierPhaseDepA.prototype.fieldSpec]);
PackedObsContentDepA.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);
PackedObsContentDepA.prototype.fieldSpec.push(['lock', 'writeUInt16LE', 2]);
PackedObsContentDepA.prototype.fieldSpec.push(['prn', 'writeUInt8', 1]);

/**
 * SBP class for message fragment PackedObsContentDepB
 *
 * Pseudorange and carrier phase observation for a satellite being tracked.
 * Pseudoranges are referenced to a nominal pseudorange.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field P number (unsigned 32-bit int, 4 bytes) Pseudorange observation
 * @field L CarrierPhaseDepA Carrier phase observation with opposite sign from typical convention.
 * @field cn0 number (unsigned 8-bit int, 1 byte) Carrier-to-Noise density
 * @field lock number (unsigned 16-bit int, 2 bytes) Lock indicator. This value changes whenever a satellite signal has lost and
 *   regained lock, indicating that the carrier phase ambiguity may have changed.
 * @field sid GnssSignalDep GNSS signal identifier
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var PackedObsContentDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "PackedObsContentDepB";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
PackedObsContentDepB.prototype = Object.create(SBP.prototype);
PackedObsContentDepB.prototype.messageType = "PackedObsContentDepB";
PackedObsContentDepB.prototype.constructor = PackedObsContentDepB;
PackedObsContentDepB.prototype.parser = new Parser()
  .endianess('little')
  .uint32('P')
  .nest('L', { type: CarrierPhaseDepA.prototype.parser })
  .uint8('cn0')
  .uint16('lock')
  .nest('sid', { type: GnssSignalDep.prototype.parser });
PackedObsContentDepB.prototype.fieldSpec = [];
PackedObsContentDepB.prototype.fieldSpec.push(['P', 'writeUInt32LE', 4]);
PackedObsContentDepB.prototype.fieldSpec.push(['L', CarrierPhaseDepA.prototype.fieldSpec]);
PackedObsContentDepB.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);
PackedObsContentDepB.prototype.fieldSpec.push(['lock', 'writeUInt16LE', 2]);
PackedObsContentDepB.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);

/**
 * SBP class for message fragment PackedObsContentDepC
 *
 * Pseudorange and carrier phase observation for a satellite being tracked. The
 * observations are be interoperable with 3rd party receivers and conform with
 * typical RTCMv3 GNSS observations.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field P number (unsigned 32-bit int, 4 bytes) Pseudorange observation
 * @field L CarrierPhase Carrier phase observation with typical sign convention.
 * @field cn0 number (unsigned 8-bit int, 1 byte) Carrier-to-Noise density
 * @field lock number (unsigned 16-bit int, 2 bytes) Lock indicator. This value changes whenever a satellite signal has lost and
 *   regained lock, indicating that the carrier phase ambiguity may have changed.
 * @field sid GnssSignalDep GNSS signal identifier
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var PackedObsContentDepC = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "PackedObsContentDepC";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
PackedObsContentDepC.prototype = Object.create(SBP.prototype);
PackedObsContentDepC.prototype.messageType = "PackedObsContentDepC";
PackedObsContentDepC.prototype.constructor = PackedObsContentDepC;
PackedObsContentDepC.prototype.parser = new Parser()
  .endianess('little')
  .uint32('P')
  .nest('L', { type: CarrierPhase.prototype.parser })
  .uint8('cn0')
  .uint16('lock')
  .nest('sid', { type: GnssSignalDep.prototype.parser });
PackedObsContentDepC.prototype.fieldSpec = [];
PackedObsContentDepC.prototype.fieldSpec.push(['P', 'writeUInt32LE', 4]);
PackedObsContentDepC.prototype.fieldSpec.push(['L', CarrierPhase.prototype.fieldSpec]);
PackedObsContentDepC.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);
PackedObsContentDepC.prototype.fieldSpec.push(['lock', 'writeUInt16LE', 2]);
PackedObsContentDepC.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);

/**
 * SBP class for message MSG_OBS_DEP_A (0x0045).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field header ObservationHeaderDep Header of a GPS observation message
 * @field obs array Pseudorange and carrier phase observation for a satellite being tracked.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgObsDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_OBS_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgObsDepA.prototype = Object.create(SBP.prototype);
MsgObsDepA.prototype.messageType = "MSG_OBS_DEP_A";
MsgObsDepA.prototype.msg_type = 0x0045;
MsgObsDepA.prototype.constructor = MsgObsDepA;
MsgObsDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: ObservationHeaderDep.prototype.parser })
  .array('obs', { type: PackedObsContentDepA.prototype.parser, readUntil: 'eof' });
MsgObsDepA.prototype.fieldSpec = [];
MsgObsDepA.prototype.fieldSpec.push(['header', ObservationHeaderDep.prototype.fieldSpec]);
MsgObsDepA.prototype.fieldSpec.push(['obs', 'array', PackedObsContentDepA.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_OBS_DEP_B (0x0043).
 *
 * This observation message has been deprecated in favor of observations that are
 * more interoperable. This message should be used for observations referenced to a
 * nominal pseudorange which are not interoperable with most 3rd party GNSS
 * receievers or typical RTCMv3 observations.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field header ObservationHeaderDep Header of a GPS observation message
 * @field obs array Pseudorange and carrier phase observation for a satellite being tracked.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgObsDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_OBS_DEP_B";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgObsDepB.prototype = Object.create(SBP.prototype);
MsgObsDepB.prototype.messageType = "MSG_OBS_DEP_B";
MsgObsDepB.prototype.msg_type = 0x0043;
MsgObsDepB.prototype.constructor = MsgObsDepB;
MsgObsDepB.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: ObservationHeaderDep.prototype.parser })
  .array('obs', { type: PackedObsContentDepB.prototype.parser, readUntil: 'eof' });
MsgObsDepB.prototype.fieldSpec = [];
MsgObsDepB.prototype.fieldSpec.push(['header', ObservationHeaderDep.prototype.fieldSpec]);
MsgObsDepB.prototype.fieldSpec.push(['obs', 'array', PackedObsContentDepB.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_OBS_DEP_C (0x0049).
 *
 * The GPS observations message reports all the raw pseudorange and carrier phase
 * observations for the satellites being tracked by the device. Carrier phase
 * observation here is represented as a 40-bit fixed point number with Q32.8 layout
 * (i.e. 32-bits of whole cycles and 8-bits of fractional cycles). The observations
 * are interoperable with 3rd party receivers and conform with typical RTCMv3 GNSS
 * observations.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field header ObservationHeaderDep Header of a GPS observation message
 * @field obs array Pseudorange and carrier phase observation for a satellite being tracked.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgObsDepC = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_OBS_DEP_C";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgObsDepC.prototype = Object.create(SBP.prototype);
MsgObsDepC.prototype.messageType = "MSG_OBS_DEP_C";
MsgObsDepC.prototype.msg_type = 0x0049;
MsgObsDepC.prototype.constructor = MsgObsDepC;
MsgObsDepC.prototype.parser = new Parser()
  .endianess('little')
  .nest('header', { type: ObservationHeaderDep.prototype.parser })
  .array('obs', { type: PackedObsContentDepC.prototype.parser, readUntil: 'eof' });
MsgObsDepC.prototype.fieldSpec = [];
MsgObsDepC.prototype.fieldSpec.push(['header', ObservationHeaderDep.prototype.fieldSpec]);
MsgObsDepC.prototype.fieldSpec.push(['obs', 'array', PackedObsContentDepC.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_IONO (0x0090).
 *
 * The ionospheric parameters which allow the "L1 only" or "L2 only" user to
 * utilize the ionospheric model for computation of the ionospheric delay. Please
 * see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field t_nmct GPSTimeSec Navigation Message Correction Table Valitidy Time
 * @field a0 number (float, 8 bytes)
 * @field a1 number (float, 8 bytes)
 * @field a2 number (float, 8 bytes)
 * @field a3 number (float, 8 bytes)
 * @field b0 number (float, 8 bytes)
 * @field b1 number (float, 8 bytes)
 * @field b2 number (float, 8 bytes)
 * @field b3 number (float, 8 bytes)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgIono = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_IONO";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgIono.prototype = Object.create(SBP.prototype);
MsgIono.prototype.messageType = "MSG_IONO";
MsgIono.prototype.msg_type = 0x0090;
MsgIono.prototype.constructor = MsgIono;
MsgIono.prototype.parser = new Parser()
  .endianess('little')
  .nest('t_nmct', { type: GPSTimeSec.prototype.parser })
  .doublele('a0')
  .doublele('a1')
  .doublele('a2')
  .doublele('a3')
  .doublele('b0')
  .doublele('b1')
  .doublele('b2')
  .doublele('b3');
MsgIono.prototype.fieldSpec = [];
MsgIono.prototype.fieldSpec.push(['t_nmct', GPSTimeSec.prototype.fieldSpec]);
MsgIono.prototype.fieldSpec.push(['a0', 'writeDoubleLE', 8]);
MsgIono.prototype.fieldSpec.push(['a1', 'writeDoubleLE', 8]);
MsgIono.prototype.fieldSpec.push(['a2', 'writeDoubleLE', 8]);
MsgIono.prototype.fieldSpec.push(['a3', 'writeDoubleLE', 8]);
MsgIono.prototype.fieldSpec.push(['b0', 'writeDoubleLE', 8]);
MsgIono.prototype.fieldSpec.push(['b1', 'writeDoubleLE', 8]);
MsgIono.prototype.fieldSpec.push(['b2', 'writeDoubleLE', 8]);
MsgIono.prototype.fieldSpec.push(['b3', 'writeDoubleLE', 8]);

/**
 * SBP class for message MSG_SV_CONFIGURATION_GPS (0x0091).
 *
 * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field t_nmct GPSTimeSec Navigation Message Correction Table Valitidy Time
 * @field l2c_mask number (unsigned 32-bit int, 4 bytes) L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSvConfigurationGps = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SV_CONFIGURATION_GPS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSvConfigurationGps.prototype = Object.create(SBP.prototype);
MsgSvConfigurationGps.prototype.messageType = "MSG_SV_CONFIGURATION_GPS";
MsgSvConfigurationGps.prototype.msg_type = 0x0091;
MsgSvConfigurationGps.prototype.constructor = MsgSvConfigurationGps;
MsgSvConfigurationGps.prototype.parser = new Parser()
  .endianess('little')
  .nest('t_nmct', { type: GPSTimeSec.prototype.parser })
  .uint32('l2c_mask');
MsgSvConfigurationGps.prototype.fieldSpec = [];
MsgSvConfigurationGps.prototype.fieldSpec.push(['t_nmct', GPSTimeSec.prototype.fieldSpec]);
MsgSvConfigurationGps.prototype.fieldSpec.push(['l2c_mask', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_GROUP_DELAY_DEP_A (0x0092).
 *
 * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field t_op GPSTimeDep Data Predict Time of Week
 * @field prn number (unsigned 8-bit int, 1 byte) Satellite number
 * @field valid number (unsigned 8-bit int, 1 byte) bit-field indicating validity of the values, LSB indicating tgd validity etc. 1
 *   = value is valid, 0 = value is not valid.
 * @field tgd number (signed 16-bit int, 2 bytes)
 * @field isc_l1ca number (signed 16-bit int, 2 bytes)
 * @field isc_l2c number (signed 16-bit int, 2 bytes)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgGroupDelayDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_GROUP_DELAY_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgGroupDelayDepA.prototype = Object.create(SBP.prototype);
MsgGroupDelayDepA.prototype.messageType = "MSG_GROUP_DELAY_DEP_A";
MsgGroupDelayDepA.prototype.msg_type = 0x0092;
MsgGroupDelayDepA.prototype.constructor = MsgGroupDelayDepA;
MsgGroupDelayDepA.prototype.parser = new Parser()
  .endianess('little')
  .nest('t_op', { type: GPSTimeDep.prototype.parser })
  .uint8('prn')
  .uint8('valid')
  .int16('tgd')
  .int16('isc_l1ca')
  .int16('isc_l2c');
MsgGroupDelayDepA.prototype.fieldSpec = [];
MsgGroupDelayDepA.prototype.fieldSpec.push(['t_op', GPSTimeDep.prototype.fieldSpec]);
MsgGroupDelayDepA.prototype.fieldSpec.push(['prn', 'writeUInt8', 1]);
MsgGroupDelayDepA.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
MsgGroupDelayDepA.prototype.fieldSpec.push(['tgd', 'writeInt16LE', 2]);
MsgGroupDelayDepA.prototype.fieldSpec.push(['isc_l1ca', 'writeInt16LE', 2]);
MsgGroupDelayDepA.prototype.fieldSpec.push(['isc_l2c', 'writeInt16LE', 2]);

/**
 * SBP class for message MSG_GROUP_DELAY_DEP_B (0x0093).
 *
 * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field t_op GPSTimeSec Data Predict Time of Week
 * @field sid GnssSignalDep GNSS signal identifier
 * @field valid number (unsigned 8-bit int, 1 byte) bit-field indicating validity of the values, LSB indicating tgd validity etc. 1
 *   = value is valid, 0 = value is not valid.
 * @field tgd number (signed 16-bit int, 2 bytes)
 * @field isc_l1ca number (signed 16-bit int, 2 bytes)
 * @field isc_l2c number (signed 16-bit int, 2 bytes)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgGroupDelayDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_GROUP_DELAY_DEP_B";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgGroupDelayDepB.prototype = Object.create(SBP.prototype);
MsgGroupDelayDepB.prototype.messageType = "MSG_GROUP_DELAY_DEP_B";
MsgGroupDelayDepB.prototype.msg_type = 0x0093;
MsgGroupDelayDepB.prototype.constructor = MsgGroupDelayDepB;
MsgGroupDelayDepB.prototype.parser = new Parser()
  .endianess('little')
  .nest('t_op', { type: GPSTimeSec.prototype.parser })
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .uint8('valid')
  .int16('tgd')
  .int16('isc_l1ca')
  .int16('isc_l2c');
MsgGroupDelayDepB.prototype.fieldSpec = [];
MsgGroupDelayDepB.prototype.fieldSpec.push(['t_op', GPSTimeSec.prototype.fieldSpec]);
MsgGroupDelayDepB.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
MsgGroupDelayDepB.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
MsgGroupDelayDepB.prototype.fieldSpec.push(['tgd', 'writeInt16LE', 2]);
MsgGroupDelayDepB.prototype.fieldSpec.push(['isc_l1ca', 'writeInt16LE', 2]);
MsgGroupDelayDepB.prototype.fieldSpec.push(['isc_l2c', 'writeInt16LE', 2]);

/**
 * SBP class for message MSG_GROUP_DELAY (0x0094).
 *
 * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field t_op GPSTimeSec Data Predict Time of Week
 * @field sid GnssSignal GNSS signal identifier
 * @field valid number (unsigned 8-bit int, 1 byte) bit-field indicating validity of the values, LSB indicating tgd validity etc. 1
 *   = value is valid, 0 = value is not valid.
 * @field tgd number (signed 16-bit int, 2 bytes)
 * @field isc_l1ca number (signed 16-bit int, 2 bytes)
 * @field isc_l2c number (signed 16-bit int, 2 bytes)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgGroupDelay = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_GROUP_DELAY";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgGroupDelay.prototype = Object.create(SBP.prototype);
MsgGroupDelay.prototype.messageType = "MSG_GROUP_DELAY";
MsgGroupDelay.prototype.msg_type = 0x0094;
MsgGroupDelay.prototype.constructor = MsgGroupDelay;
MsgGroupDelay.prototype.parser = new Parser()
  .endianess('little')
  .nest('t_op', { type: GPSTimeSec.prototype.parser })
  .nest('sid', { type: GnssSignal.prototype.parser })
  .uint8('valid')
  .int16('tgd')
  .int16('isc_l1ca')
  .int16('isc_l2c');
MsgGroupDelay.prototype.fieldSpec = [];
MsgGroupDelay.prototype.fieldSpec.push(['t_op', GPSTimeSec.prototype.fieldSpec]);
MsgGroupDelay.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgGroupDelay.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
MsgGroupDelay.prototype.fieldSpec.push(['tgd', 'writeInt16LE', 2]);
MsgGroupDelay.prototype.fieldSpec.push(['isc_l1ca', 'writeInt16LE', 2]);
MsgGroupDelay.prototype.fieldSpec.push(['isc_l2c', 'writeInt16LE', 2]);

/**
 * SBP class for message fragment AlmanacCommonContent
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field sid GnssSignal GNSS signal identifier
 * @field toa GPSTimeSec Reference time of almanac
 * @field ura number (float, 8 bytes) User Range Accuracy
 * @field fit_interval number (unsigned 32-bit int, 4 bytes) Curve fit interval
 * @field valid number (unsigned 8-bit int, 1 byte) Status of almanac, 1 = valid, 0 = invalid
 * @field health_bits number (unsigned 8-bit int, 1 byte) Satellite health status for GPS:   - bits 5-7: NAV data health status. See IS-
 *   GPS-200H     Table 20-VII: NAV Data Health Indications.   - bits 0-4: Signal
 *   health status. See IS-GPS-200H     Table 20-VIII. Codes for Health of SV Signal
 *   Components. Satellite health status for GLO:   See GLO ICD 5.1 table 5.1 for
 *   details   - bit 0: C(n), "unhealthy" flag that is transmitted within     non-
 *   immediate data and indicates overall constellation status     at the moment of
 *   almanac uploading.     '0' indicates malfunction of n-satellite.     '1'
 *   indicates that n-satellite is operational.   - bit 1: Bn(ln), '0' indicates the
 *   satellite is operational     and suitable for navigation.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var AlmanacCommonContent = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "AlmanacCommonContent";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
AlmanacCommonContent.prototype = Object.create(SBP.prototype);
AlmanacCommonContent.prototype.messageType = "AlmanacCommonContent";
AlmanacCommonContent.prototype.constructor = AlmanacCommonContent;
AlmanacCommonContent.prototype.parser = new Parser()
  .endianess('little')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .nest('toa', { type: GPSTimeSec.prototype.parser })
  .doublele('ura')
  .uint32('fit_interval')
  .uint8('valid')
  .uint8('health_bits');
AlmanacCommonContent.prototype.fieldSpec = [];
AlmanacCommonContent.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
AlmanacCommonContent.prototype.fieldSpec.push(['toa', GPSTimeSec.prototype.fieldSpec]);
AlmanacCommonContent.prototype.fieldSpec.push(['ura', 'writeDoubleLE', 8]);
AlmanacCommonContent.prototype.fieldSpec.push(['fit_interval', 'writeUInt32LE', 4]);
AlmanacCommonContent.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
AlmanacCommonContent.prototype.fieldSpec.push(['health_bits', 'writeUInt8', 1]);

/**
 * SBP class for message fragment AlmanacCommonContentDep
 *
 
 * Fields in the SBP payload (`sbp.payload`):
 * @field sid GnssSignalDep GNSS signal identifier
 * @field toa GPSTimeSec Reference time of almanac
 * @field ura number (float, 8 bytes) User Range Accuracy
 * @field fit_interval number (unsigned 32-bit int, 4 bytes) Curve fit interval
 * @field valid number (unsigned 8-bit int, 1 byte) Status of almanac, 1 = valid, 0 = invalid
 * @field health_bits number (unsigned 8-bit int, 1 byte) Satellite health status for GPS:   - bits 5-7: NAV data health status. See IS-
 *   GPS-200H     Table 20-VII: NAV Data Health Indications.   - bits 0-4: Signal
 *   health status. See IS-GPS-200H     Table 20-VIII. Codes for Health of SV Signal
 *   Components. Satellite health status for GLO:   See GLO ICD 5.1 table 5.1 for
 *   details   - bit 0: C(n), "unhealthy" flag that is transmitted within     non-
 *   immediate data and indicates overall constellation status     at the moment of
 *   almanac uploading.     '0' indicates malfunction of n-satellite.     '1'
 *   indicates that n-satellite is operational.   - bit 1: Bn(ln), '0' indicates the
 *   satellite is operational     and suitable for navigation.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var AlmanacCommonContentDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "AlmanacCommonContentDep";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
AlmanacCommonContentDep.prototype = Object.create(SBP.prototype);
AlmanacCommonContentDep.prototype.messageType = "AlmanacCommonContentDep";
AlmanacCommonContentDep.prototype.constructor = AlmanacCommonContentDep;
AlmanacCommonContentDep.prototype.parser = new Parser()
  .endianess('little')
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .nest('toa', { type: GPSTimeSec.prototype.parser })
  .doublele('ura')
  .uint32('fit_interval')
  .uint8('valid')
  .uint8('health_bits');
AlmanacCommonContentDep.prototype.fieldSpec = [];
AlmanacCommonContentDep.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
AlmanacCommonContentDep.prototype.fieldSpec.push(['toa', GPSTimeSec.prototype.fieldSpec]);
AlmanacCommonContentDep.prototype.fieldSpec.push(['ura', 'writeDoubleLE', 8]);
AlmanacCommonContentDep.prototype.fieldSpec.push(['fit_interval', 'writeUInt32LE', 4]);
AlmanacCommonContentDep.prototype.fieldSpec.push(['valid', 'writeUInt8', 1]);
AlmanacCommonContentDep.prototype.fieldSpec.push(['health_bits', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_ALMANAC_GPS_DEP (0x0070).
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac data is
 * not very precise and is considered valid for up to several months. Please see
 * the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200, Chapter
 * 20.3.3.5.1.2 Almanac Data) for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common AlmanacCommonContentDep Values common for all almanac types
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAlmanacGpsDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ALMANAC_GPS_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAlmanacGpsDep.prototype = Object.create(SBP.prototype);
MsgAlmanacGpsDep.prototype.messageType = "MSG_ALMANAC_GPS_DEP";
MsgAlmanacGpsDep.prototype.msg_type = 0x0070;
MsgAlmanacGpsDep.prototype.constructor = MsgAlmanacGpsDep;
MsgAlmanacGpsDep.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: AlmanacCommonContentDep.prototype.parser })
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .doublele('af0')
  .doublele('af1');
MsgAlmanacGpsDep.prototype.fieldSpec = [];
MsgAlmanacGpsDep.prototype.fieldSpec.push(['common', AlmanacCommonContentDep.prototype.fieldSpec]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgAlmanacGpsDep.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);

/**
 * SBP class for message MSG_ALMANAC_GPS (0x0072).
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac data is
 * not very precise and is considered valid for up to several months. Please see
 * the Navstar GPS Space Segment/Navigation user interfaces (ICD-GPS-200, Chapter
 * 20.3.3.5.1.2 Almanac Data) for more details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common AlmanacCommonContent Values common for all almanac types
 * @field m0 number (float, 8 bytes) Mean anomaly at reference time
 * @field ecc number (float, 8 bytes) Eccentricity of satellite orbit
 * @field sqrta number (float, 8 bytes) Square root of the semi-major axis of orbit
 * @field omega0 number (float, 8 bytes) Longitude of ascending node of orbit plane at weekly epoch
 * @field omegadot number (float, 8 bytes) Rate of right ascension
 * @field w number (float, 8 bytes) Argument of perigee
 * @field inc number (float, 8 bytes) Inclination
 * @field af0 number (float, 8 bytes) Polynomial clock correction coefficient (clock bias)
 * @field af1 number (float, 8 bytes) Polynomial clock correction coefficient (clock drift)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAlmanacGps = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ALMANAC_GPS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAlmanacGps.prototype = Object.create(SBP.prototype);
MsgAlmanacGps.prototype.messageType = "MSG_ALMANAC_GPS";
MsgAlmanacGps.prototype.msg_type = 0x0072;
MsgAlmanacGps.prototype.constructor = MsgAlmanacGps;
MsgAlmanacGps.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: AlmanacCommonContent.prototype.parser })
  .doublele('m0')
  .doublele('ecc')
  .doublele('sqrta')
  .doublele('omega0')
  .doublele('omegadot')
  .doublele('w')
  .doublele('inc')
  .doublele('af0')
  .doublele('af1');
MsgAlmanacGps.prototype.fieldSpec = [];
MsgAlmanacGps.prototype.fieldSpec.push(['common', AlmanacCommonContent.prototype.fieldSpec]);
MsgAlmanacGps.prototype.fieldSpec.push(['m0', 'writeDoubleLE', 8]);
MsgAlmanacGps.prototype.fieldSpec.push(['ecc', 'writeDoubleLE', 8]);
MsgAlmanacGps.prototype.fieldSpec.push(['sqrta', 'writeDoubleLE', 8]);
MsgAlmanacGps.prototype.fieldSpec.push(['omega0', 'writeDoubleLE', 8]);
MsgAlmanacGps.prototype.fieldSpec.push(['omegadot', 'writeDoubleLE', 8]);
MsgAlmanacGps.prototype.fieldSpec.push(['w', 'writeDoubleLE', 8]);
MsgAlmanacGps.prototype.fieldSpec.push(['inc', 'writeDoubleLE', 8]);
MsgAlmanacGps.prototype.fieldSpec.push(['af0', 'writeDoubleLE', 8]);
MsgAlmanacGps.prototype.fieldSpec.push(['af1', 'writeDoubleLE', 8]);

/**
 * SBP class for message MSG_ALMANAC_GLO_DEP (0x0071).
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac data is
 * not very precise and is considered valid for up to several months. Please see
 * the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and almanac" for details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common AlmanacCommonContentDep Values common for all almanac types
 * @field lambda_na number (float, 8 bytes) Longitude of the first ascending node of the orbit in PZ-90.02 coordinate system
 * @field t_lambda_na number (float, 8 bytes) Time of the first ascending node passage
 * @field i number (float, 8 bytes) Value of inclination at instant of t_lambda
 * @field t number (float, 8 bytes) Value of Draconian period at instant of t_lambda
 * @field t_dot number (float, 8 bytes) Rate of change of the Draconian period
 * @field epsilon number (float, 8 bytes) Eccentricity at instant of t_lambda
 * @field omega number (float, 8 bytes) Argument of perigee at instant of t_lambda
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAlmanacGloDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ALMANAC_GLO_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAlmanacGloDep.prototype = Object.create(SBP.prototype);
MsgAlmanacGloDep.prototype.messageType = "MSG_ALMANAC_GLO_DEP";
MsgAlmanacGloDep.prototype.msg_type = 0x0071;
MsgAlmanacGloDep.prototype.constructor = MsgAlmanacGloDep;
MsgAlmanacGloDep.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: AlmanacCommonContentDep.prototype.parser })
  .doublele('lambda_na')
  .doublele('t_lambda_na')
  .doublele('i')
  .doublele('t')
  .doublele('t_dot')
  .doublele('epsilon')
  .doublele('omega');
MsgAlmanacGloDep.prototype.fieldSpec = [];
MsgAlmanacGloDep.prototype.fieldSpec.push(['common', AlmanacCommonContentDep.prototype.fieldSpec]);
MsgAlmanacGloDep.prototype.fieldSpec.push(['lambda_na', 'writeDoubleLE', 8]);
MsgAlmanacGloDep.prototype.fieldSpec.push(['t_lambda_na', 'writeDoubleLE', 8]);
MsgAlmanacGloDep.prototype.fieldSpec.push(['i', 'writeDoubleLE', 8]);
MsgAlmanacGloDep.prototype.fieldSpec.push(['t', 'writeDoubleLE', 8]);
MsgAlmanacGloDep.prototype.fieldSpec.push(['t_dot', 'writeDoubleLE', 8]);
MsgAlmanacGloDep.prototype.fieldSpec.push(['epsilon', 'writeDoubleLE', 8]);
MsgAlmanacGloDep.prototype.fieldSpec.push(['omega', 'writeDoubleLE', 8]);

/**
 * SBP class for message MSG_ALMANAC_GLO (0x0073).
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac data is
 * not very precise and is considered valid for up to several months. Please see
 * the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and almanac" for details.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field common AlmanacCommonContent Values common for all almanac types
 * @field lambda_na number (float, 8 bytes) Longitude of the first ascending node of the orbit in PZ-90.02 coordinate system
 * @field t_lambda_na number (float, 8 bytes) Time of the first ascending node passage
 * @field i number (float, 8 bytes) Value of inclination at instant of t_lambda
 * @field t number (float, 8 bytes) Value of Draconian period at instant of t_lambda
 * @field t_dot number (float, 8 bytes) Rate of change of the Draconian period
 * @field epsilon number (float, 8 bytes) Eccentricity at instant of t_lambda
 * @field omega number (float, 8 bytes) Argument of perigee at instant of t_lambda
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAlmanacGlo = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ALMANAC_GLO";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAlmanacGlo.prototype = Object.create(SBP.prototype);
MsgAlmanacGlo.prototype.messageType = "MSG_ALMANAC_GLO";
MsgAlmanacGlo.prototype.msg_type = 0x0073;
MsgAlmanacGlo.prototype.constructor = MsgAlmanacGlo;
MsgAlmanacGlo.prototype.parser = new Parser()
  .endianess('little')
  .nest('common', { type: AlmanacCommonContent.prototype.parser })
  .doublele('lambda_na')
  .doublele('t_lambda_na')
  .doublele('i')
  .doublele('t')
  .doublele('t_dot')
  .doublele('epsilon')
  .doublele('omega');
MsgAlmanacGlo.prototype.fieldSpec = [];
MsgAlmanacGlo.prototype.fieldSpec.push(['common', AlmanacCommonContent.prototype.fieldSpec]);
MsgAlmanacGlo.prototype.fieldSpec.push(['lambda_na', 'writeDoubleLE', 8]);
MsgAlmanacGlo.prototype.fieldSpec.push(['t_lambda_na', 'writeDoubleLE', 8]);
MsgAlmanacGlo.prototype.fieldSpec.push(['i', 'writeDoubleLE', 8]);
MsgAlmanacGlo.prototype.fieldSpec.push(['t', 'writeDoubleLE', 8]);
MsgAlmanacGlo.prototype.fieldSpec.push(['t_dot', 'writeDoubleLE', 8]);
MsgAlmanacGlo.prototype.fieldSpec.push(['epsilon', 'writeDoubleLE', 8]);
MsgAlmanacGlo.prototype.fieldSpec.push(['omega', 'writeDoubleLE', 8]);

/**
 * SBP class for message MSG_GLO_BIASES (0x0075).
 *
 * The GLONASS L1/L2 Code-Phase biases allows to perform  GPS+GLONASS integer
 * ambiguity resolution for baselines with mixed receiver types (e.g. receiver of
 * different manufacturers)
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field mask number (unsigned 8-bit int, 1 byte) GLONASS FDMA signals mask
 * @field l1ca_bias number (signed 16-bit int, 2 bytes) GLONASS L1 C/A Code-Phase Bias
 * @field l1p_bias number (signed 16-bit int, 2 bytes) GLONASS L1 P Code-Phase Bias
 * @field l2ca_bias number (signed 16-bit int, 2 bytes) GLONASS L2 C/A Code-Phase Bias
 * @field l2p_bias number (signed 16-bit int, 2 bytes) GLONASS L2 P Code-Phase Bias
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgGloBiases = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_GLO_BIASES";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgGloBiases.prototype = Object.create(SBP.prototype);
MsgGloBiases.prototype.messageType = "MSG_GLO_BIASES";
MsgGloBiases.prototype.msg_type = 0x0075;
MsgGloBiases.prototype.constructor = MsgGloBiases;
MsgGloBiases.prototype.parser = new Parser()
  .endianess('little')
  .uint8('mask')
  .int16('l1ca_bias')
  .int16('l1p_bias')
  .int16('l2ca_bias')
  .int16('l2p_bias');
MsgGloBiases.prototype.fieldSpec = [];
MsgGloBiases.prototype.fieldSpec.push(['mask', 'writeUInt8', 1]);
MsgGloBiases.prototype.fieldSpec.push(['l1ca_bias', 'writeInt16LE', 2]);
MsgGloBiases.prototype.fieldSpec.push(['l1p_bias', 'writeInt16LE', 2]);
MsgGloBiases.prototype.fieldSpec.push(['l2ca_bias', 'writeInt16LE', 2]);
MsgGloBiases.prototype.fieldSpec.push(['l2p_bias', 'writeInt16LE', 2]);

module.exports = {
  ObservationHeader: ObservationHeader,
  Doppler: Doppler,
  PackedObsContent: PackedObsContent,
  0x004A: MsgObs,
  MsgObs: MsgObs,
  0x0044: MsgBasePosLlh,
  MsgBasePosLlh: MsgBasePosLlh,
  0x0048: MsgBasePosEcef,
  MsgBasePosEcef: MsgBasePosEcef,
  EphemerisCommonContent: EphemerisCommonContent,
  EphemerisCommonContentDepB: EphemerisCommonContentDepB,
  EphemerisCommonContentDepA: EphemerisCommonContentDepA,
  0x0081: MsgEphemerisGpsDepE,
  MsgEphemerisGpsDepE: MsgEphemerisGpsDepE,
  0x0086: MsgEphemerisGpsDepF,
  MsgEphemerisGpsDepF: MsgEphemerisGpsDepF,
  0x008A: MsgEphemerisGps,
  MsgEphemerisGps: MsgEphemerisGps,
  0x0082: MsgEphemerisSbasDepA,
  MsgEphemerisSbasDepA: MsgEphemerisSbasDepA,
  0x0083: MsgEphemerisGloDepA,
  MsgEphemerisGloDepA: MsgEphemerisGloDepA,
  0x0084: MsgEphemerisSbasDepB,
  MsgEphemerisSbasDepB: MsgEphemerisSbasDepB,
  0x008C: MsgEphemerisSbas,
  MsgEphemerisSbas: MsgEphemerisSbas,
  0x0085: MsgEphemerisGloDepB,
  MsgEphemerisGloDepB: MsgEphemerisGloDepB,
  0x0087: MsgEphemerisGloDepC,
  MsgEphemerisGloDepC: MsgEphemerisGloDepC,
  0x0088: MsgEphemerisGloDepD,
  MsgEphemerisGloDepD: MsgEphemerisGloDepD,
  0x008B: MsgEphemerisGlo,
  MsgEphemerisGlo: MsgEphemerisGlo,
  0x0080: MsgEphemerisDepD,
  MsgEphemerisDepD: MsgEphemerisDepD,
  0x001A: MsgEphemerisDepA,
  MsgEphemerisDepA: MsgEphemerisDepA,
  0x0046: MsgEphemerisDepB,
  MsgEphemerisDepB: MsgEphemerisDepB,
  0x0047: MsgEphemerisDepC,
  MsgEphemerisDepC: MsgEphemerisDepC,
  ObservationHeaderDep: ObservationHeaderDep,
  CarrierPhaseDepA: CarrierPhaseDepA,
  PackedObsContentDepA: PackedObsContentDepA,
  PackedObsContentDepB: PackedObsContentDepB,
  PackedObsContentDepC: PackedObsContentDepC,
  0x0045: MsgObsDepA,
  MsgObsDepA: MsgObsDepA,
  0x0043: MsgObsDepB,
  MsgObsDepB: MsgObsDepB,
  0x0049: MsgObsDepC,
  MsgObsDepC: MsgObsDepC,
  0x0090: MsgIono,
  MsgIono: MsgIono,
  0x0091: MsgSvConfigurationGps,
  MsgSvConfigurationGps: MsgSvConfigurationGps,
  0x0092: MsgGroupDelayDepA,
  MsgGroupDelayDepA: MsgGroupDelayDepA,
  0x0093: MsgGroupDelayDepB,
  MsgGroupDelayDepB: MsgGroupDelayDepB,
  0x0094: MsgGroupDelay,
  MsgGroupDelay: MsgGroupDelay,
  AlmanacCommonContent: AlmanacCommonContent,
  AlmanacCommonContentDep: AlmanacCommonContentDep,
  0x0070: MsgAlmanacGpsDep,
  MsgAlmanacGpsDep: MsgAlmanacGpsDep,
  0x0072: MsgAlmanacGps,
  MsgAlmanacGps: MsgAlmanacGps,
  0x0071: MsgAlmanacGloDep,
  MsgAlmanacGloDep: MsgAlmanacGloDep,
  0x0073: MsgAlmanacGlo,
  MsgAlmanacGlo: MsgAlmanacGlo,
  0x0075: MsgGloBiases,
  MsgGloBiases: MsgGloBiases,
}

/***/ }),
/* 34 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/orientation.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Orientation Messages
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;

/**
 * SBP class for message MSG_BASELINE_HEADING (0x020F).
 *
 * This message reports the baseline heading pointing from the base station to the
 * rover relative to True North. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow). It is intended that time-
 * matched RTK mode is used when the base station is moving.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field heading number (unsigned 32-bit int, 4 bytes) Heading
 * @field n_sats number (unsigned 8-bit int, 1 byte) Number of satellites used in solution
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBaselineHeading = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BASELINE_HEADING";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBaselineHeading.prototype = Object.create(SBP.prototype);
MsgBaselineHeading.prototype.messageType = "MSG_BASELINE_HEADING";
MsgBaselineHeading.prototype.msg_type = 0x020F;
MsgBaselineHeading.prototype.constructor = MsgBaselineHeading;
MsgBaselineHeading.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .uint32('heading')
  .uint8('n_sats')
  .uint8('flags');
MsgBaselineHeading.prototype.fieldSpec = [];
MsgBaselineHeading.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgBaselineHeading.prototype.fieldSpec.push(['heading', 'writeUInt32LE', 4]);
MsgBaselineHeading.prototype.fieldSpec.push(['n_sats', 'writeUInt8', 1]);
MsgBaselineHeading.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_ORIENT_QUAT (0x0220).
 *
 * This message reports the quaternion vector describing the vehicle body frame's
 * orientation with respect to a local-level NED frame. The components of the
 * vector should sum to a unit vector assuming that the LSB of each component as a
 * value of 2^-31.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field w number (signed 32-bit int, 4 bytes) Real component
 * @field x number (signed 32-bit int, 4 bytes) 1st imaginary component
 * @field y number (signed 32-bit int, 4 bytes) 2nd imaginary component
 * @field z number (signed 32-bit int, 4 bytes) 3rd imaginary component
 * @field w_accuracy number (float, 4 bytes) Estimated standard deviation of w
 * @field x_accuracy number (float, 4 bytes) Estimated standard deviation of x
 * @field y_accuracy number (float, 4 bytes) Estimated standard deviation of y
 * @field z_accuracy number (float, 4 bytes) Estimated standard deviation of z
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgOrientQuat = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ORIENT_QUAT";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgOrientQuat.prototype = Object.create(SBP.prototype);
MsgOrientQuat.prototype.messageType = "MSG_ORIENT_QUAT";
MsgOrientQuat.prototype.msg_type = 0x0220;
MsgOrientQuat.prototype.constructor = MsgOrientQuat;
MsgOrientQuat.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('w')
  .int32('x')
  .int32('y')
  .int32('z')
  .floatle('w_accuracy')
  .floatle('x_accuracy')
  .floatle('y_accuracy')
  .floatle('z_accuracy')
  .uint8('flags');
MsgOrientQuat.prototype.fieldSpec = [];
MsgOrientQuat.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['w', 'writeInt32LE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['w_accuracy', 'writeFloatLE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['x_accuracy', 'writeFloatLE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['y_accuracy', 'writeFloatLE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['z_accuracy', 'writeFloatLE', 4]);
MsgOrientQuat.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_ORIENT_EULER (0x0221).
 *
 * This message reports the yaw, pitch, and roll angles of the vehicle body frame.
 * The rotations should applied intrinsically in the order yaw, pitch, and roll  in
 * order to rotate the from a frame aligned with the local-level NED frame  to the
 * vehicle body frame.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field roll number (signed 32-bit int, 4 bytes) rotation about the forward axis of the vehicle
 * @field pitch number (signed 32-bit int, 4 bytes) rotation about the rightward axis of the vehicle
 * @field yaw number (signed 32-bit int, 4 bytes) rotation about the downward axis of the vehicle
 * @field roll_accuracy number (float, 4 bytes) Estimated standard deviation of roll
 * @field pitch_accuracy number (float, 4 bytes) Estimated standard deviation of pitch
 * @field yaw_accuracy number (float, 4 bytes) Estimated standard deviation of yaw
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgOrientEuler = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ORIENT_EULER";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgOrientEuler.prototype = Object.create(SBP.prototype);
MsgOrientEuler.prototype.messageType = "MSG_ORIENT_EULER";
MsgOrientEuler.prototype.msg_type = 0x0221;
MsgOrientEuler.prototype.constructor = MsgOrientEuler;
MsgOrientEuler.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('roll')
  .int32('pitch')
  .int32('yaw')
  .floatle('roll_accuracy')
  .floatle('pitch_accuracy')
  .floatle('yaw_accuracy')
  .uint8('flags');
MsgOrientEuler.prototype.fieldSpec = [];
MsgOrientEuler.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgOrientEuler.prototype.fieldSpec.push(['roll', 'writeInt32LE', 4]);
MsgOrientEuler.prototype.fieldSpec.push(['pitch', 'writeInt32LE', 4]);
MsgOrientEuler.prototype.fieldSpec.push(['yaw', 'writeInt32LE', 4]);
MsgOrientEuler.prototype.fieldSpec.push(['roll_accuracy', 'writeFloatLE', 4]);
MsgOrientEuler.prototype.fieldSpec.push(['pitch_accuracy', 'writeFloatLE', 4]);
MsgOrientEuler.prototype.fieldSpec.push(['yaw_accuracy', 'writeFloatLE', 4]);
MsgOrientEuler.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_ANGULAR_RATE (0x0222).
 *
 * This message reports the orientation rates in the vehicle body frame.  The
 * values represent the measurements a strapped down gyroscope would  make and are
 * not equivalent to the time derivative of the Euler angles. The orientation and
 * origin of the user frame is specified via device settings. By convention, the
 * vehicle x-axis is expected to be aligned with the forward direction, while the
 * vehicle y-axis is expected to be aligned with the right direction, and the
 * vehicle z-axis should be aligned with the down direction.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) GPS Time of Week
 * @field x number (signed 32-bit int, 4 bytes) angular rate about x axis
 * @field y number (signed 32-bit int, 4 bytes) angular rate about y axis
 * @field z number (signed 32-bit int, 4 bytes) angular rate about z axis
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAngularRate = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ANGULAR_RATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAngularRate.prototype = Object.create(SBP.prototype);
MsgAngularRate.prototype.messageType = "MSG_ANGULAR_RATE";
MsgAngularRate.prototype.msg_type = 0x0222;
MsgAngularRate.prototype.constructor = MsgAngularRate;
MsgAngularRate.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('x')
  .int32('y')
  .int32('z')
  .uint8('flags');
MsgAngularRate.prototype.fieldSpec = [];
MsgAngularRate.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgAngularRate.prototype.fieldSpec.push(['x', 'writeInt32LE', 4]);
MsgAngularRate.prototype.fieldSpec.push(['y', 'writeInt32LE', 4]);
MsgAngularRate.prototype.fieldSpec.push(['z', 'writeInt32LE', 4]);
MsgAngularRate.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

module.exports = {
  0x020F: MsgBaselineHeading,
  MsgBaselineHeading: MsgBaselineHeading,
  0x0220: MsgOrientQuat,
  MsgOrientQuat: MsgOrientQuat,
  0x0221: MsgOrientEuler,
  MsgOrientEuler: MsgOrientEuler,
  0x0222: MsgAngularRate,
  MsgAngularRate: MsgAngularRate,
}

/***/ }),
/* 35 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/piksi.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * System health, configuration, and diagnostic messages specific to the Piksi L1
 * receiver, including a variety of legacy messages that may no longer be used.
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;
var GnssSignal = __webpack_require__(0).GnssSignal;
var GnssSignalDep = __webpack_require__(0).GnssSignalDep;
var GPSTime = __webpack_require__(0).GPSTime;
var CarrierPhase = __webpack_require__(0).CarrierPhase;
var GPSTime = __webpack_require__(0).GPSTime;
var GPSTimeSec = __webpack_require__(0).GPSTimeSec;
var GPSTimeDep = __webpack_require__(0).GPSTimeDep;

/**
 * SBP class for message MSG_ALMANAC (0x0069).
 *
 * This is a legacy message for sending and loading a satellite alamanac onto the
 * Piksi's flash memory from the host.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgAlmanac = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ALMANAC";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgAlmanac.prototype = Object.create(SBP.prototype);
MsgAlmanac.prototype.messageType = "MSG_ALMANAC";
MsgAlmanac.prototype.msg_type = 0x0069;
MsgAlmanac.prototype.constructor = MsgAlmanac;
MsgAlmanac.prototype.parser = new Parser()
  .endianess('little');
MsgAlmanac.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_SET_TIME (0x0068).
 *
 * This message sets up timing functionality using a coarse GPS time estimate sent
 * by the host.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSetTime = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SET_TIME";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSetTime.prototype = Object.create(SBP.prototype);
MsgSetTime.prototype.messageType = "MSG_SET_TIME";
MsgSetTime.prototype.msg_type = 0x0068;
MsgSetTime.prototype.constructor = MsgSetTime;
MsgSetTime.prototype.parser = new Parser()
  .endianess('little');
MsgSetTime.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_RESET (0x00B6).
 *
 * This message from the host resets the Piksi back into the bootloader.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field flags number (unsigned 32-bit int, 4 bytes) Reset flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgReset = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_RESET";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgReset.prototype = Object.create(SBP.prototype);
MsgReset.prototype.messageType = "MSG_RESET";
MsgReset.prototype.msg_type = 0x00B6;
MsgReset.prototype.constructor = MsgReset;
MsgReset.prototype.parser = new Parser()
  .endianess('little')
  .uint32('flags');
MsgReset.prototype.fieldSpec = [];
MsgReset.prototype.fieldSpec.push(['flags', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_RESET_DEP (0x00B2).
 *
 * This message from the host resets the Piksi back into the bootloader.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgResetDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_RESET_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgResetDep.prototype = Object.create(SBP.prototype);
MsgResetDep.prototype.messageType = "MSG_RESET_DEP";
MsgResetDep.prototype.msg_type = 0x00B2;
MsgResetDep.prototype.constructor = MsgResetDep;
MsgResetDep.prototype.parser = new Parser()
  .endianess('little');
MsgResetDep.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_CW_RESULTS (0x00C0).
 *
 * This is an unused legacy message for result reporting from the CW interference
 * channel on the SwiftNAP. This message will be removed in a future release.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgCwResults = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_CW_RESULTS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgCwResults.prototype = Object.create(SBP.prototype);
MsgCwResults.prototype.messageType = "MSG_CW_RESULTS";
MsgCwResults.prototype.msg_type = 0x00C0;
MsgCwResults.prototype.constructor = MsgCwResults;
MsgCwResults.prototype.parser = new Parser()
  .endianess('little');
MsgCwResults.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_CW_START (0x00C1).
 *
 * This is an unused legacy message from the host for starting the CW interference
 * channel on the SwiftNAP. This message will be removed in a future release.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgCwStart = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_CW_START";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgCwStart.prototype = Object.create(SBP.prototype);
MsgCwStart.prototype.messageType = "MSG_CW_START";
MsgCwStart.prototype.msg_type = 0x00C1;
MsgCwStart.prototype.constructor = MsgCwStart;
MsgCwStart.prototype.parser = new Parser()
  .endianess('little');
MsgCwStart.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_RESET_FILTERS (0x0022).
 *
 * This message resets either the DGNSS Kalman filters or Integer Ambiguity
 * Resolution (IAR) process.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field filter number (unsigned 8-bit int, 1 byte) Filter flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgResetFilters = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_RESET_FILTERS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgResetFilters.prototype = Object.create(SBP.prototype);
MsgResetFilters.prototype.messageType = "MSG_RESET_FILTERS";
MsgResetFilters.prototype.msg_type = 0x0022;
MsgResetFilters.prototype.constructor = MsgResetFilters;
MsgResetFilters.prototype.parser = new Parser()
  .endianess('little')
  .uint8('filter');
MsgResetFilters.prototype.fieldSpec = [];
MsgResetFilters.prototype.fieldSpec.push(['filter', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_INIT_BASE (0x0023).
 *
 * This message initializes the integer ambiguity resolution (IAR) process on the
 * Piksi to use an assumed baseline position between the base station and rover
 * receivers. Warns via MSG_PRINT if there aren't a shared minimum number (4) of
 * satellite observations between the two.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgInitBase = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_INIT_BASE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgInitBase.prototype = Object.create(SBP.prototype);
MsgInitBase.prototype.messageType = "MSG_INIT_BASE";
MsgInitBase.prototype.msg_type = 0x0023;
MsgInitBase.prototype.constructor = MsgInitBase;
MsgInitBase.prototype.parser = new Parser()
  .endianess('little');
MsgInitBase.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_THREAD_STATE (0x0017).
 *
 * The thread usage message from the device reports real-time operating system
 * (RTOS) thread usage statistics for the named thread. The reported percentage
 * values must be normalized.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field name string Thread name (NULL terminated)
 * @field cpu number (unsigned 16-bit int, 2 bytes) Percentage cpu use for this thread. Values range from 0 - 1000 and needs to be
 *   renormalized to 100
 * @field stack_free number (unsigned 32-bit int, 4 bytes) Free stack space for this thread
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgThreadState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_THREAD_STATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgThreadState.prototype = Object.create(SBP.prototype);
MsgThreadState.prototype.messageType = "MSG_THREAD_STATE";
MsgThreadState.prototype.msg_type = 0x0017;
MsgThreadState.prototype.constructor = MsgThreadState;
MsgThreadState.prototype.parser = new Parser()
  .endianess('little')
  .string('name', { length: 20 })
  .uint16('cpu')
  .uint32('stack_free');
MsgThreadState.prototype.fieldSpec = [];
MsgThreadState.prototype.fieldSpec.push(['name', 'string', 20]);
MsgThreadState.prototype.fieldSpec.push(['cpu', 'writeUInt16LE', 2]);
MsgThreadState.prototype.fieldSpec.push(['stack_free', 'writeUInt32LE', 4]);

/**
 * SBP class for message fragment UARTChannel
 *
 * Throughput, utilization, and error counts on the RX/TX buffers of this UART
 * channel. The reported percentage values must be normalized.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tx_throughput number (float, 4 bytes) UART transmit throughput
 * @field rx_throughput number (float, 4 bytes) UART receive throughput
 * @field crc_error_count number (unsigned 16-bit int, 2 bytes) UART CRC error count
 * @field io_error_count number (unsigned 16-bit int, 2 bytes) UART IO error count
 * @field tx_buffer_level number (unsigned 8-bit int, 1 byte) UART transmit buffer percentage utilization (ranges from 0 to 255)
 * @field rx_buffer_level number (unsigned 8-bit int, 1 byte) UART receive buffer percentage utilization (ranges from 0 to 255)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var UARTChannel = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "UARTChannel";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
UARTChannel.prototype = Object.create(SBP.prototype);
UARTChannel.prototype.messageType = "UARTChannel";
UARTChannel.prototype.constructor = UARTChannel;
UARTChannel.prototype.parser = new Parser()
  .endianess('little')
  .floatle('tx_throughput')
  .floatle('rx_throughput')
  .uint16('crc_error_count')
  .uint16('io_error_count')
  .uint8('tx_buffer_level')
  .uint8('rx_buffer_level');
UARTChannel.prototype.fieldSpec = [];
UARTChannel.prototype.fieldSpec.push(['tx_throughput', 'writeFloatLE', 4]);
UARTChannel.prototype.fieldSpec.push(['rx_throughput', 'writeFloatLE', 4]);
UARTChannel.prototype.fieldSpec.push(['crc_error_count', 'writeUInt16LE', 2]);
UARTChannel.prototype.fieldSpec.push(['io_error_count', 'writeUInt16LE', 2]);
UARTChannel.prototype.fieldSpec.push(['tx_buffer_level', 'writeUInt8', 1]);
UARTChannel.prototype.fieldSpec.push(['rx_buffer_level', 'writeUInt8', 1]);

/**
 * SBP class for message fragment Period
 *
 * Statistics on the period of observations received from the base station. As
 * complete observation sets are received, their time of reception is compared with
 * the prior set''s time of reception. This measurement provides a proxy for link
 * quality as incomplete or missing sets will increase the period.  Long periods
 * can cause momentary RTK solution outages.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field avg number (signed 32-bit int, 4 bytes) Average period
 * @field pmin number (signed 32-bit int, 4 bytes) Minimum period
 * @field pmax number (signed 32-bit int, 4 bytes) Maximum period
 * @field current number (signed 32-bit int, 4 bytes) Smoothed estimate of the current period
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var Period = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "Period";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
Period.prototype = Object.create(SBP.prototype);
Period.prototype.messageType = "Period";
Period.prototype.constructor = Period;
Period.prototype.parser = new Parser()
  .endianess('little')
  .int32('avg')
  .int32('pmin')
  .int32('pmax')
  .int32('current');
Period.prototype.fieldSpec = [];
Period.prototype.fieldSpec.push(['avg', 'writeInt32LE', 4]);
Period.prototype.fieldSpec.push(['pmin', 'writeInt32LE', 4]);
Period.prototype.fieldSpec.push(['pmax', 'writeInt32LE', 4]);
Period.prototype.fieldSpec.push(['current', 'writeInt32LE', 4]);

/**
 * SBP class for message fragment Latency
 *
 * Statistics on the latency of observations received from the base station. As
 * observation packets are received their GPS time is compared to the current GPS
 * time calculated locally by the receiver to give a precise measurement of the
 * end-to-end communication latency in the system.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field avg number (signed 32-bit int, 4 bytes) Average latency
 * @field lmin number (signed 32-bit int, 4 bytes) Minimum latency
 * @field lmax number (signed 32-bit int, 4 bytes) Maximum latency
 * @field current number (signed 32-bit int, 4 bytes) Smoothed estimate of the current latency
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var Latency = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "Latency";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
Latency.prototype = Object.create(SBP.prototype);
Latency.prototype.messageType = "Latency";
Latency.prototype.constructor = Latency;
Latency.prototype.parser = new Parser()
  .endianess('little')
  .int32('avg')
  .int32('lmin')
  .int32('lmax')
  .int32('current');
Latency.prototype.fieldSpec = [];
Latency.prototype.fieldSpec.push(['avg', 'writeInt32LE', 4]);
Latency.prototype.fieldSpec.push(['lmin', 'writeInt32LE', 4]);
Latency.prototype.fieldSpec.push(['lmax', 'writeInt32LE', 4]);
Latency.prototype.fieldSpec.push(['current', 'writeInt32LE', 4]);

/**
 * SBP class for message MSG_UART_STATE (0x001D).
 *
 * The UART message reports data latency and throughput of the UART channels
 * providing SBP I/O. On the default Piksi configuration, UARTs A and B are used
 * for telemetry radios, but can also be host access ports for embedded hosts, or
 * other interfaces in future. The reported percentage values must be normalized.
 * Observations latency and period can be used to assess the health of the
 * differential corrections link. Latency provides the timeliness of received base
 * observations while the period indicates their likelihood of transmission.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field uart_a UARTChannel State of UART A
 * @field uart_b UARTChannel State of UART B
 * @field uart_ftdi UARTChannel State of UART FTDI (USB logger)
 * @field latency Latency UART communication latency
 * @field obs_period Period Observation receipt period
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgUartState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_UART_STATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgUartState.prototype = Object.create(SBP.prototype);
MsgUartState.prototype.messageType = "MSG_UART_STATE";
MsgUartState.prototype.msg_type = 0x001D;
MsgUartState.prototype.constructor = MsgUartState;
MsgUartState.prototype.parser = new Parser()
  .endianess('little')
  .nest('uart_a', { type: UARTChannel.prototype.parser })
  .nest('uart_b', { type: UARTChannel.prototype.parser })
  .nest('uart_ftdi', { type: UARTChannel.prototype.parser })
  .nest('latency', { type: Latency.prototype.parser })
  .nest('obs_period', { type: Period.prototype.parser });
MsgUartState.prototype.fieldSpec = [];
MsgUartState.prototype.fieldSpec.push(['uart_a', UARTChannel.prototype.fieldSpec]);
MsgUartState.prototype.fieldSpec.push(['uart_b', UARTChannel.prototype.fieldSpec]);
MsgUartState.prototype.fieldSpec.push(['uart_ftdi', UARTChannel.prototype.fieldSpec]);
MsgUartState.prototype.fieldSpec.push(['latency', Latency.prototype.fieldSpec]);
MsgUartState.prototype.fieldSpec.push(['obs_period', Period.prototype.fieldSpec]);

/**
 * SBP class for message MSG_UART_STATE_DEPA (0x0018).
 *
 * Deprecated
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field uart_a UARTChannel State of UART A
 * @field uart_b UARTChannel State of UART B
 * @field uart_ftdi UARTChannel State of UART FTDI (USB logger)
 * @field latency Latency UART communication latency
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgUartStateDepa = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_UART_STATE_DEPA";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgUartStateDepa.prototype = Object.create(SBP.prototype);
MsgUartStateDepa.prototype.messageType = "MSG_UART_STATE_DEPA";
MsgUartStateDepa.prototype.msg_type = 0x0018;
MsgUartStateDepa.prototype.constructor = MsgUartStateDepa;
MsgUartStateDepa.prototype.parser = new Parser()
  .endianess('little')
  .nest('uart_a', { type: UARTChannel.prototype.parser })
  .nest('uart_b', { type: UARTChannel.prototype.parser })
  .nest('uart_ftdi', { type: UARTChannel.prototype.parser })
  .nest('latency', { type: Latency.prototype.parser });
MsgUartStateDepa.prototype.fieldSpec = [];
MsgUartStateDepa.prototype.fieldSpec.push(['uart_a', UARTChannel.prototype.fieldSpec]);
MsgUartStateDepa.prototype.fieldSpec.push(['uart_b', UARTChannel.prototype.fieldSpec]);
MsgUartStateDepa.prototype.fieldSpec.push(['uart_ftdi', UARTChannel.prototype.fieldSpec]);
MsgUartStateDepa.prototype.fieldSpec.push(['latency', Latency.prototype.fieldSpec]);

/**
 * SBP class for message MSG_IAR_STATE (0x0019).
 *
 * This message reports the state of the Integer Ambiguity Resolution (IAR)
 * process, which resolves unknown integer ambiguities from double-differenced
 * carrier-phase measurements from satellite observations.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field num_hyps number (unsigned 32-bit int, 4 bytes) Number of integer ambiguity hypotheses remaining
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgIarState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_IAR_STATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgIarState.prototype = Object.create(SBP.prototype);
MsgIarState.prototype.messageType = "MSG_IAR_STATE";
MsgIarState.prototype.msg_type = 0x0019;
MsgIarState.prototype.constructor = MsgIarState;
MsgIarState.prototype.parser = new Parser()
  .endianess('little')
  .uint32('num_hyps');
MsgIarState.prototype.fieldSpec = [];
MsgIarState.prototype.fieldSpec.push(['num_hyps', 'writeUInt32LE', 4]);

/**
 * SBP class for message MSG_MASK_SATELLITE (0x002B).
 *
 * This message allows setting a mask to prevent a particular satellite from being
 * used in various Piksi subsystems.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field mask number (unsigned 8-bit int, 1 byte) Mask of systems that should ignore this satellite.
 * @field sid GnssSignal GNSS signal for which the mask is applied
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgMaskSatellite = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_MASK_SATELLITE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgMaskSatellite.prototype = Object.create(SBP.prototype);
MsgMaskSatellite.prototype.messageType = "MSG_MASK_SATELLITE";
MsgMaskSatellite.prototype.msg_type = 0x002B;
MsgMaskSatellite.prototype.constructor = MsgMaskSatellite;
MsgMaskSatellite.prototype.parser = new Parser()
  .endianess('little')
  .uint8('mask')
  .nest('sid', { type: GnssSignal.prototype.parser });
MsgMaskSatellite.prototype.fieldSpec = [];
MsgMaskSatellite.prototype.fieldSpec.push(['mask', 'writeUInt8', 1]);
MsgMaskSatellite.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);

/**
 * SBP class for message MSG_MASK_SATELLITE_DEP (0x001B).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field mask number (unsigned 8-bit int, 1 byte) Mask of systems that should ignore this satellite.
 * @field sid GnssSignalDep GNSS signal for which the mask is applied
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgMaskSatelliteDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_MASK_SATELLITE_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgMaskSatelliteDep.prototype = Object.create(SBP.prototype);
MsgMaskSatelliteDep.prototype.messageType = "MSG_MASK_SATELLITE_DEP";
MsgMaskSatelliteDep.prototype.msg_type = 0x001B;
MsgMaskSatelliteDep.prototype.constructor = MsgMaskSatelliteDep;
MsgMaskSatelliteDep.prototype.parser = new Parser()
  .endianess('little')
  .uint8('mask')
  .nest('sid', { type: GnssSignalDep.prototype.parser });
MsgMaskSatelliteDep.prototype.fieldSpec = [];
MsgMaskSatelliteDep.prototype.fieldSpec.push(['mask', 'writeUInt8', 1]);
MsgMaskSatelliteDep.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);

/**
 * SBP class for message MSG_DEVICE_MONITOR (0x00B5).
 *
 * This message contains temperature and voltage level measurements from the
 * processor's monitoring system and the RF frontend die temperature if available.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field dev_vin number (signed 16-bit int, 2 bytes) Device V_in
 * @field cpu_vint number (signed 16-bit int, 2 bytes) Processor V_int
 * @field cpu_vaux number (signed 16-bit int, 2 bytes) Processor V_aux
 * @field cpu_temperature number (signed 16-bit int, 2 bytes) Processor temperature
 * @field fe_temperature number (signed 16-bit int, 2 bytes) Frontend temperature (if available)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgDeviceMonitor = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_DEVICE_MONITOR";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgDeviceMonitor.prototype = Object.create(SBP.prototype);
MsgDeviceMonitor.prototype.messageType = "MSG_DEVICE_MONITOR";
MsgDeviceMonitor.prototype.msg_type = 0x00B5;
MsgDeviceMonitor.prototype.constructor = MsgDeviceMonitor;
MsgDeviceMonitor.prototype.parser = new Parser()
  .endianess('little')
  .int16('dev_vin')
  .int16('cpu_vint')
  .int16('cpu_vaux')
  .int16('cpu_temperature')
  .int16('fe_temperature');
MsgDeviceMonitor.prototype.fieldSpec = [];
MsgDeviceMonitor.prototype.fieldSpec.push(['dev_vin', 'writeInt16LE', 2]);
MsgDeviceMonitor.prototype.fieldSpec.push(['cpu_vint', 'writeInt16LE', 2]);
MsgDeviceMonitor.prototype.fieldSpec.push(['cpu_vaux', 'writeInt16LE', 2]);
MsgDeviceMonitor.prototype.fieldSpec.push(['cpu_temperature', 'writeInt16LE', 2]);
MsgDeviceMonitor.prototype.fieldSpec.push(['fe_temperature', 'writeInt16LE', 2]);

/**
 * SBP class for message MSG_COMMAND_REQ (0x00B8).
 *
 * Request the recipient to execute an command. Output will be sent in MSG_LOG
 * messages, and the exit code will be returned with MSG_COMMAND_RESP.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Sequence number
 * @field command string Command line to execute
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgCommandReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_COMMAND_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgCommandReq.prototype = Object.create(SBP.prototype);
MsgCommandReq.prototype.messageType = "MSG_COMMAND_REQ";
MsgCommandReq.prototype.msg_type = 0x00B8;
MsgCommandReq.prototype.constructor = MsgCommandReq;
MsgCommandReq.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence')
  .string('command', { greedy: true });
MsgCommandReq.prototype.fieldSpec = [];
MsgCommandReq.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgCommandReq.prototype.fieldSpec.push(['command', 'string', null]);

/**
 * SBP class for message MSG_COMMAND_RESP (0x00B9).
 *
 * The response to MSG_COMMAND_REQ with the return code of the command.  A return
 * code of zero indicates success.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Sequence number
 * @field code number (signed 32-bit int, 4 bytes) Exit code
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgCommandResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_COMMAND_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgCommandResp.prototype = Object.create(SBP.prototype);
MsgCommandResp.prototype.messageType = "MSG_COMMAND_RESP";
MsgCommandResp.prototype.msg_type = 0x00B9;
MsgCommandResp.prototype.constructor = MsgCommandResp;
MsgCommandResp.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence')
  .int32('code');
MsgCommandResp.prototype.fieldSpec = [];
MsgCommandResp.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgCommandResp.prototype.fieldSpec.push(['code', 'writeInt32LE', 4]);

/**
 * SBP class for message MSG_COMMAND_OUTPUT (0x00BC).
 *
 * Returns the standard output and standard error of the command requested by
 * MSG_COMMAND_REQ. The sequence number can be used to filter for filtering the
 * correct command.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sequence number (unsigned 32-bit int, 4 bytes) Sequence number
 * @field line string Line of standard output or standard error
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgCommandOutput = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_COMMAND_OUTPUT";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgCommandOutput.prototype = Object.create(SBP.prototype);
MsgCommandOutput.prototype.messageType = "MSG_COMMAND_OUTPUT";
MsgCommandOutput.prototype.msg_type = 0x00BC;
MsgCommandOutput.prototype.constructor = MsgCommandOutput;
MsgCommandOutput.prototype.parser = new Parser()
  .endianess('little')
  .uint32('sequence')
  .string('line', { greedy: true });
MsgCommandOutput.prototype.fieldSpec = [];
MsgCommandOutput.prototype.fieldSpec.push(['sequence', 'writeUInt32LE', 4]);
MsgCommandOutput.prototype.fieldSpec.push(['line', 'string', null]);

/**
 * SBP class for message MSG_NETWORK_STATE_REQ (0x00BA).
 *
 * Request state of Piksi network interfaces. Output will be sent in
 * MSG_NETWORK_STATE_RESP messages
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgNetworkStateReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_NETWORK_STATE_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgNetworkStateReq.prototype = Object.create(SBP.prototype);
MsgNetworkStateReq.prototype.messageType = "MSG_NETWORK_STATE_REQ";
MsgNetworkStateReq.prototype.msg_type = 0x00BA;
MsgNetworkStateReq.prototype.constructor = MsgNetworkStateReq;
MsgNetworkStateReq.prototype.parser = new Parser()
  .endianess('little');
MsgNetworkStateReq.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_NETWORK_STATE_RESP (0x00BB).
 *
 * The state of a network interface on the Piksi. Data is made to reflect output of
 * ifaddrs struct returned by getifaddrs in c.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field ipv4_address array IPv4 address (all zero when unavailable)
 * @field ipv4_mask_size number (unsigned 8-bit int, 1 byte) IPv4 netmask CIDR notation
 * @field ipv6_address array IPv6 address (all zero when unavailable)
 * @field ipv6_mask_size number (unsigned 8-bit int, 1 byte) IPv6 netmask CIDR notation
 * @field rx_bytes number (unsigned 32-bit int, 4 bytes) Number of Rx bytes
 * @field tx_bytes number (unsigned 32-bit int, 4 bytes) Number of Tx bytes
 * @field interface_name string Interface Name
 * @field flags number (unsigned 32-bit int, 4 bytes) Interface flags from SIOCGIFFLAGS
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgNetworkStateResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_NETWORK_STATE_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgNetworkStateResp.prototype = Object.create(SBP.prototype);
MsgNetworkStateResp.prototype.messageType = "MSG_NETWORK_STATE_RESP";
MsgNetworkStateResp.prototype.msg_type = 0x00BB;
MsgNetworkStateResp.prototype.constructor = MsgNetworkStateResp;
MsgNetworkStateResp.prototype.parser = new Parser()
  .endianess('little')
  .array('ipv4_address', { length: 4, type: 'uint8' })
  .uint8('ipv4_mask_size')
  .array('ipv6_address', { length: 16, type: 'uint8' })
  .uint8('ipv6_mask_size')
  .uint32('rx_bytes')
  .uint32('tx_bytes')
  .string('interface_name', { length: 16 })
  .uint32('flags');
MsgNetworkStateResp.prototype.fieldSpec = [];
MsgNetworkStateResp.prototype.fieldSpec.push(['ipv4_address', 'array', 'writeUInt8', function () { return 1; }, 4]);
MsgNetworkStateResp.prototype.fieldSpec.push(['ipv4_mask_size', 'writeUInt8', 1]);
MsgNetworkStateResp.prototype.fieldSpec.push(['ipv6_address', 'array', 'writeUInt8', function () { return 1; }, 16]);
MsgNetworkStateResp.prototype.fieldSpec.push(['ipv6_mask_size', 'writeUInt8', 1]);
MsgNetworkStateResp.prototype.fieldSpec.push(['rx_bytes', 'writeUInt32LE', 4]);
MsgNetworkStateResp.prototype.fieldSpec.push(['tx_bytes', 'writeUInt32LE', 4]);
MsgNetworkStateResp.prototype.fieldSpec.push(['interface_name', 'string', 16]);
MsgNetworkStateResp.prototype.fieldSpec.push(['flags', 'writeUInt32LE', 4]);

/**
 * SBP class for message fragment NetworkUsage
 *
 * The bandwidth usage for each interface can be reported within this struct and
 * utilize multiple fields to fully specify the type of traffic that is being
 * tracked. As either the interval of collection or the collection time may vary,
 * both a timestamp and period field is provided, though may not necessarily be
 * populated with a value.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field duration number (unsigned 64-bit int, 8 bytes) Duration over which the measurement was collected
 * @field total_bytes number (unsigned 64-bit int, 8 bytes) Number of bytes handled in total within period
 * @field rx_bytes number (unsigned 32-bit int, 4 bytes) Number of bytes transmitted within period
 * @field tx_bytes number (unsigned 32-bit int, 4 bytes) Number of bytes received within period
 * @field interface_name string Interface Name
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var NetworkUsage = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "NetworkUsage";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
NetworkUsage.prototype = Object.create(SBP.prototype);
NetworkUsage.prototype.messageType = "NetworkUsage";
NetworkUsage.prototype.constructor = NetworkUsage;
NetworkUsage.prototype.parser = new Parser()
  .endianess('little')
  .uint64('duration')
  .uint64('total_bytes')
  .uint32('rx_bytes')
  .uint32('tx_bytes')
  .string('interface_name', { length: 16 });
NetworkUsage.prototype.fieldSpec = [];
NetworkUsage.prototype.fieldSpec.push(['duration', 'writeUInt64LE', 8]);
NetworkUsage.prototype.fieldSpec.push(['total_bytes', 'writeUInt64LE', 8]);
NetworkUsage.prototype.fieldSpec.push(['rx_bytes', 'writeUInt32LE', 4]);
NetworkUsage.prototype.fieldSpec.push(['tx_bytes', 'writeUInt32LE', 4]);
NetworkUsage.prototype.fieldSpec.push(['interface_name', 'string', 16]);

/**
 * SBP class for message MSG_NETWORK_BANDWIDTH_USAGE (0x00BD).
 *
 * The bandwidth usage, a list of usage by interface.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field interfaces array Usage measurement array
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgNetworkBandwidthUsage = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_NETWORK_BANDWIDTH_USAGE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgNetworkBandwidthUsage.prototype = Object.create(SBP.prototype);
MsgNetworkBandwidthUsage.prototype.messageType = "MSG_NETWORK_BANDWIDTH_USAGE";
MsgNetworkBandwidthUsage.prototype.msg_type = 0x00BD;
MsgNetworkBandwidthUsage.prototype.constructor = MsgNetworkBandwidthUsage;
MsgNetworkBandwidthUsage.prototype.parser = new Parser()
  .endianess('little')
  .array('interfaces', { type: NetworkUsage.prototype.parser, readUntil: 'eof' });
MsgNetworkBandwidthUsage.prototype.fieldSpec = [];
MsgNetworkBandwidthUsage.prototype.fieldSpec.push(['interfaces', 'array', NetworkUsage.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_CELL_MODEM_STATUS (0x00BE).
 *
 * If a cell modem is present on a piksi device, this message will be send
 * periodically to update the host on the status of the modem and its various
 * parameters.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field signal_strength number (signed 8-bit int, 1 byte) Received cell signal strength in dBm, zero translates to unknown
 * @field signal_error_rate number (float, 4 bytes) BER as reported by the modem, zero translates to unknown
 * @field reserved array Unspecified data TBD for this schema
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgCellModemStatus = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_CELL_MODEM_STATUS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgCellModemStatus.prototype = Object.create(SBP.prototype);
MsgCellModemStatus.prototype.messageType = "MSG_CELL_MODEM_STATUS";
MsgCellModemStatus.prototype.msg_type = 0x00BE;
MsgCellModemStatus.prototype.constructor = MsgCellModemStatus;
MsgCellModemStatus.prototype.parser = new Parser()
  .endianess('little')
  .int8('signal_strength')
  .floatle('signal_error_rate')
  .array('reserved', { type: 'uint8', readUntil: 'eof' });
MsgCellModemStatus.prototype.fieldSpec = [];
MsgCellModemStatus.prototype.fieldSpec.push(['signal_strength', 'writeInt8', 1]);
MsgCellModemStatus.prototype.fieldSpec.push(['signal_error_rate', 'writeFloatLE', 4]);
MsgCellModemStatus.prototype.fieldSpec.push(['reserved', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_SPECAN_DEP (0x0050).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field channel_tag number (unsigned 16-bit int, 2 bytes) Channel ID
 * @field t GPSTimeDep Receiver time of this observation
 * @field freq_ref number (float, 4 bytes) Reference frequency of this packet
 * @field freq_step number (float, 4 bytes) Frequency step of points in this packet
 * @field amplitude_ref number (float, 4 bytes) Reference amplitude of this packet
 * @field amplitude_unit number (float, 4 bytes) Amplitude unit value of points in this packet
 * @field amplitude_value array Amplitude values (in the above units) of points in this packet
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSpecanDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SPECAN_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSpecanDep.prototype = Object.create(SBP.prototype);
MsgSpecanDep.prototype.messageType = "MSG_SPECAN_DEP";
MsgSpecanDep.prototype.msg_type = 0x0050;
MsgSpecanDep.prototype.constructor = MsgSpecanDep;
MsgSpecanDep.prototype.parser = new Parser()
  .endianess('little')
  .uint16('channel_tag')
  .nest('t', { type: GPSTimeDep.prototype.parser })
  .floatle('freq_ref')
  .floatle('freq_step')
  .floatle('amplitude_ref')
  .floatle('amplitude_unit')
  .array('amplitude_value', { type: 'uint8', readUntil: 'eof' });
MsgSpecanDep.prototype.fieldSpec = [];
MsgSpecanDep.prototype.fieldSpec.push(['channel_tag', 'writeUInt16LE', 2]);
MsgSpecanDep.prototype.fieldSpec.push(['t', GPSTimeDep.prototype.fieldSpec]);
MsgSpecanDep.prototype.fieldSpec.push(['freq_ref', 'writeFloatLE', 4]);
MsgSpecanDep.prototype.fieldSpec.push(['freq_step', 'writeFloatLE', 4]);
MsgSpecanDep.prototype.fieldSpec.push(['amplitude_ref', 'writeFloatLE', 4]);
MsgSpecanDep.prototype.fieldSpec.push(['amplitude_unit', 'writeFloatLE', 4]);
MsgSpecanDep.prototype.fieldSpec.push(['amplitude_value', 'array', 'writeUInt8', function () { return 1; }, null]);

/**
 * SBP class for message MSG_SPECAN (0x0051).
 *
 * Spectrum analyzer packet.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field channel_tag number (unsigned 16-bit int, 2 bytes) Channel ID
 * @field t GPSTime Receiver time of this observation
 * @field freq_ref number (float, 4 bytes) Reference frequency of this packet
 * @field freq_step number (float, 4 bytes) Frequency step of points in this packet
 * @field amplitude_ref number (float, 4 bytes) Reference amplitude of this packet
 * @field amplitude_unit number (float, 4 bytes) Amplitude unit value of points in this packet
 * @field amplitude_value array Amplitude values (in the above units) of points in this packet
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSpecan = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SPECAN";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSpecan.prototype = Object.create(SBP.prototype);
MsgSpecan.prototype.messageType = "MSG_SPECAN";
MsgSpecan.prototype.msg_type = 0x0051;
MsgSpecan.prototype.constructor = MsgSpecan;
MsgSpecan.prototype.parser = new Parser()
  .endianess('little')
  .uint16('channel_tag')
  .nest('t', { type: GPSTime.prototype.parser })
  .floatle('freq_ref')
  .floatle('freq_step')
  .floatle('amplitude_ref')
  .floatle('amplitude_unit')
  .array('amplitude_value', { type: 'uint8', readUntil: 'eof' });
MsgSpecan.prototype.fieldSpec = [];
MsgSpecan.prototype.fieldSpec.push(['channel_tag', 'writeUInt16LE', 2]);
MsgSpecan.prototype.fieldSpec.push(['t', GPSTime.prototype.fieldSpec]);
MsgSpecan.prototype.fieldSpec.push(['freq_ref', 'writeFloatLE', 4]);
MsgSpecan.prototype.fieldSpec.push(['freq_step', 'writeFloatLE', 4]);
MsgSpecan.prototype.fieldSpec.push(['amplitude_ref', 'writeFloatLE', 4]);
MsgSpecan.prototype.fieldSpec.push(['amplitude_unit', 'writeFloatLE', 4]);
MsgSpecan.prototype.fieldSpec.push(['amplitude_value', 'array', 'writeUInt8', function () { return 1; }, null]);

module.exports = {
  0x0069: MsgAlmanac,
  MsgAlmanac: MsgAlmanac,
  0x0068: MsgSetTime,
  MsgSetTime: MsgSetTime,
  0x00B6: MsgReset,
  MsgReset: MsgReset,
  0x00B2: MsgResetDep,
  MsgResetDep: MsgResetDep,
  0x00C0: MsgCwResults,
  MsgCwResults: MsgCwResults,
  0x00C1: MsgCwStart,
  MsgCwStart: MsgCwStart,
  0x0022: MsgResetFilters,
  MsgResetFilters: MsgResetFilters,
  0x0023: MsgInitBase,
  MsgInitBase: MsgInitBase,
  0x0017: MsgThreadState,
  MsgThreadState: MsgThreadState,
  UARTChannel: UARTChannel,
  Period: Period,
  Latency: Latency,
  0x001D: MsgUartState,
  MsgUartState: MsgUartState,
  0x0018: MsgUartStateDepa,
  MsgUartStateDepa: MsgUartStateDepa,
  0x0019: MsgIarState,
  MsgIarState: MsgIarState,
  0x002B: MsgMaskSatellite,
  MsgMaskSatellite: MsgMaskSatellite,
  0x001B: MsgMaskSatelliteDep,
  MsgMaskSatelliteDep: MsgMaskSatelliteDep,
  0x00B5: MsgDeviceMonitor,
  MsgDeviceMonitor: MsgDeviceMonitor,
  0x00B8: MsgCommandReq,
  MsgCommandReq: MsgCommandReq,
  0x00B9: MsgCommandResp,
  MsgCommandResp: MsgCommandResp,
  0x00BC: MsgCommandOutput,
  MsgCommandOutput: MsgCommandOutput,
  0x00BA: MsgNetworkStateReq,
  MsgNetworkStateReq: MsgNetworkStateReq,
  0x00BB: MsgNetworkStateResp,
  MsgNetworkStateResp: MsgNetworkStateResp,
  NetworkUsage: NetworkUsage,
  0x00BD: MsgNetworkBandwidthUsage,
  MsgNetworkBandwidthUsage: MsgNetworkBandwidthUsage,
  0x00BE: MsgCellModemStatus,
  MsgCellModemStatus: MsgCellModemStatus,
  0x0050: MsgSpecanDep,
  MsgSpecanDep: MsgSpecanDep,
  0x0051: MsgSpecan,
  MsgSpecan: MsgSpecan,
}

/***/ }),
/* 36 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/settings.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 *  Messages for reading, writing, and discovering device settings. Settings with a
 * "string" field have multiple values in this field delimited with a null
 * character (the c style null terminator).  For instance, when querying the
 * 'firmware_version' setting in the 'system_info' section, the following array of
 * characters needs to be sent for the string field in MSG_SETTINGS_READ:
 * "system_info\0firmware_version\0", where the delimiting  null characters are
 * specified with the escape sequence '\0' and all quotation marks should be
 * omitted.    In the message descriptions below, the generic strings
 * SECTION_SETTING and SETTING are used to refer to the two strings that comprise
 * the identifier of an individual setting.In firmware_version example above,
 * SECTION_SETTING is the 'system_info', and the SETTING portion is
 * 'firmware_version'.   See the "Software Settings Manual" on support.swiftnav.com
 * for detailed documentation about all settings and sections available for each
 * Swift firmware version. Settings manuals are available for each firmware version
 * at the following link:
 * https://support.swiftnav.com/customer/en/portal/articles/2628580-piksi-multi-
 * specifications#settings. The latest settings document is also available at the
 * following link:  http://swiftnav.com/latest/piksi-multi-settings . See lastly
 * https://github.com/swift-nav/piksi_tools/blob/master/piksi_tools/settings.py ,
 * the open source python command line utility for reading, writing, and saving
 * settings in the piksi_tools repository on github as a helpful reference and
 * example.
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;

/**
 * SBP class for message MSG_SETTINGS_SAVE (0x00A1).
 *
 * The save settings message persists the device's current settings configuration
 * to its onboard flash memory file system.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsSave = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_SAVE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsSave.prototype = Object.create(SBP.prototype);
MsgSettingsSave.prototype.messageType = "MSG_SETTINGS_SAVE";
MsgSettingsSave.prototype.msg_type = 0x00A1;
MsgSettingsSave.prototype.constructor = MsgSettingsSave;
MsgSettingsSave.prototype.parser = new Parser()
  .endianess('little');
MsgSettingsSave.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_SETTINGS_WRITE (0x00A0).
 *
 * The setting message writes the device configuration for a particular setting via
 * A NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes  the
 * NULL character and where quotation marks are omitted. A device will only process
 * to this message when it is received from sender ID 0x42. An example string that
 * could be sent to a device is "solution\0soln_freq\010\0".
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field setting string A NULL-terminated and NULL-delimited string with contents
 *   "SECTION_SETTING\0SETTING\0VALUE\0"
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsWrite = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_WRITE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsWrite.prototype = Object.create(SBP.prototype);
MsgSettingsWrite.prototype.messageType = "MSG_SETTINGS_WRITE";
MsgSettingsWrite.prototype.msg_type = 0x00A0;
MsgSettingsWrite.prototype.constructor = MsgSettingsWrite;
MsgSettingsWrite.prototype.parser = new Parser()
  .endianess('little')
  .string('setting', { greedy: true });
MsgSettingsWrite.prototype.fieldSpec = [];
MsgSettingsWrite.prototype.fieldSpec.push(['setting', 'string', null]);

/**
 * SBP class for message MSG_SETTINGS_WRITE_RESP (0x00AF).
 *
 * Return the status of a write request with the new value of the setting.  If the
 * requested value is rejected, the current value will be returned. The string
 * field is a NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes the
 * NULL character and where quotation marks are omitted. An example string that
 * could be sent from device is "solution\0soln_freq\010\0".
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field status number (unsigned 8-bit int, 1 byte) Write status
 * @field setting string A NULL-terminated and delimited string with contents
 *   "SECTION_SETTING\0SETTING\0VALUE\0"
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsWriteResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_WRITE_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsWriteResp.prototype = Object.create(SBP.prototype);
MsgSettingsWriteResp.prototype.messageType = "MSG_SETTINGS_WRITE_RESP";
MsgSettingsWriteResp.prototype.msg_type = 0x00AF;
MsgSettingsWriteResp.prototype.constructor = MsgSettingsWriteResp;
MsgSettingsWriteResp.prototype.parser = new Parser()
  .endianess('little')
  .uint8('status')
  .string('setting', { greedy: true });
MsgSettingsWriteResp.prototype.fieldSpec = [];
MsgSettingsWriteResp.prototype.fieldSpec.push(['status', 'writeUInt8', 1]);
MsgSettingsWriteResp.prototype.fieldSpec.push(['setting', 'string', null]);

/**
 * SBP class for message MSG_SETTINGS_READ_REQ (0x00A4).
 *
 * The setting message that reads the device configuration. The string field is a
 * NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the NULL
 * character and where quotation marks are omitted. An example string that could be
 * sent to a device is "solution\0soln_freq\0". A device will only respond to this
 * message when it is received from sender ID 0x42. A device should respond with a
 * MSG_SETTINGS_READ_RESP message (msg_id 0x00A5).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field setting string A NULL-terminated and NULL-delimited string with contents
 *   "SECTION_SETTING\0SETTING\0"
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsReadReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_READ_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsReadReq.prototype = Object.create(SBP.prototype);
MsgSettingsReadReq.prototype.messageType = "MSG_SETTINGS_READ_REQ";
MsgSettingsReadReq.prototype.msg_type = 0x00A4;
MsgSettingsReadReq.prototype.constructor = MsgSettingsReadReq;
MsgSettingsReadReq.prototype.parser = new Parser()
  .endianess('little')
  .string('setting', { greedy: true });
MsgSettingsReadReq.prototype.fieldSpec = [];
MsgSettingsReadReq.prototype.fieldSpec.push(['setting', 'string', null]);

/**
 * SBP class for message MSG_SETTINGS_READ_RESP (0x00A5).
 *
 * The setting message wich which the device responds after a MSG_SETTING_READ_REQ
 * is sent to device. The string field is a NULL-terminated and NULL-delimited
 * string with contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape
 * sequence denotes the NULL character and where quotation marks are omitted. An
 * example string that could be sent from device is "solution\0soln_freq\010\0".
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field setting string A NULL-terminated and NULL-delimited string with contents
 *   "SECTION_SETTING\0SETTING\0VALUE\0"
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsReadResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_READ_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsReadResp.prototype = Object.create(SBP.prototype);
MsgSettingsReadResp.prototype.messageType = "MSG_SETTINGS_READ_RESP";
MsgSettingsReadResp.prototype.msg_type = 0x00A5;
MsgSettingsReadResp.prototype.constructor = MsgSettingsReadResp;
MsgSettingsReadResp.prototype.parser = new Parser()
  .endianess('little')
  .string('setting', { greedy: true });
MsgSettingsReadResp.prototype.fieldSpec = [];
MsgSettingsReadResp.prototype.fieldSpec.push(['setting', 'string', null]);

/**
 * SBP class for message MSG_SETTINGS_READ_BY_INDEX_REQ (0x00A2).
 *
 * The settings message for iterating through the settings values. A device will
 * respond to this message with a  "MSG_SETTINGS_READ_BY_INDEX_RESP".
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field index number (unsigned 16-bit int, 2 bytes) An index into the device settings, with values ranging from 0 to
 *   length(settings)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsReadByIndexReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_READ_BY_INDEX_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsReadByIndexReq.prototype = Object.create(SBP.prototype);
MsgSettingsReadByIndexReq.prototype.messageType = "MSG_SETTINGS_READ_BY_INDEX_REQ";
MsgSettingsReadByIndexReq.prototype.msg_type = 0x00A2;
MsgSettingsReadByIndexReq.prototype.constructor = MsgSettingsReadByIndexReq;
MsgSettingsReadByIndexReq.prototype.parser = new Parser()
  .endianess('little')
  .uint16('index');
MsgSettingsReadByIndexReq.prototype.fieldSpec = [];
MsgSettingsReadByIndexReq.prototype.fieldSpec.push(['index', 'writeUInt16LE', 2]);

/**
 * SBP class for message MSG_SETTINGS_READ_BY_INDEX_RESP (0x00A7).
 *
 * The settings message that reports the value of a setting at an index.  In the
 * string field, it reports NULL-terminated and delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where the '\0' escape sequence
 * denotes the NULL character and where quotation marks are omitted. The
 * FORMAT_TYPE field is optional and denotes possible string values of the setting
 * as a hint to the user. If included, the format type portion of the string has
 * the format "enum:value1,value2,value3". An example string that could be sent
 * from the device is "simulator\0enabled\0True\0enum:True,False\0"
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field index number (unsigned 16-bit int, 2 bytes) An index into the device settings, with values ranging from 0 to
 *   length(settings)
 * @field setting string A NULL-terminated and delimited string with contents
 *   "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsReadByIndexResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_READ_BY_INDEX_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsReadByIndexResp.prototype = Object.create(SBP.prototype);
MsgSettingsReadByIndexResp.prototype.messageType = "MSG_SETTINGS_READ_BY_INDEX_RESP";
MsgSettingsReadByIndexResp.prototype.msg_type = 0x00A7;
MsgSettingsReadByIndexResp.prototype.constructor = MsgSettingsReadByIndexResp;
MsgSettingsReadByIndexResp.prototype.parser = new Parser()
  .endianess('little')
  .uint16('index')
  .string('setting', { greedy: true });
MsgSettingsReadByIndexResp.prototype.fieldSpec = [];
MsgSettingsReadByIndexResp.prototype.fieldSpec.push(['index', 'writeUInt16LE', 2]);
MsgSettingsReadByIndexResp.prototype.fieldSpec.push(['setting', 'string', null]);

/**
 * SBP class for message MSG_SETTINGS_READ_BY_INDEX_DONE (0x00A6).
 *
 * The settings message for indicating end of the settings values.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsReadByIndexDone = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_READ_BY_INDEX_DONE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsReadByIndexDone.prototype = Object.create(SBP.prototype);
MsgSettingsReadByIndexDone.prototype.messageType = "MSG_SETTINGS_READ_BY_INDEX_DONE";
MsgSettingsReadByIndexDone.prototype.msg_type = 0x00A6;
MsgSettingsReadByIndexDone.prototype.constructor = MsgSettingsReadByIndexDone;
MsgSettingsReadByIndexDone.prototype.parser = new Parser()
  .endianess('little');
MsgSettingsReadByIndexDone.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_SETTINGS_REGISTER (0x00AE).
 *
 * This message registers the presence and default value of a setting with a
 * settings daemon.  The host should reply with MSG_SETTINGS_WRITE for this setting
 * to set the initial value.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field setting string A NULL-terminated and delimited string with contents
 *   "SECTION_SETTING\0SETTING\0VALUE".
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsRegister = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_REGISTER";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsRegister.prototype = Object.create(SBP.prototype);
MsgSettingsRegister.prototype.messageType = "MSG_SETTINGS_REGISTER";
MsgSettingsRegister.prototype.msg_type = 0x00AE;
MsgSettingsRegister.prototype.constructor = MsgSettingsRegister;
MsgSettingsRegister.prototype.parser = new Parser()
  .endianess('little')
  .string('setting', { greedy: true });
MsgSettingsRegister.prototype.fieldSpec = [];
MsgSettingsRegister.prototype.fieldSpec.push(['setting', 'string', null]);

module.exports = {
  0x00A1: MsgSettingsSave,
  MsgSettingsSave: MsgSettingsSave,
  0x00A0: MsgSettingsWrite,
  MsgSettingsWrite: MsgSettingsWrite,
  0x00AF: MsgSettingsWriteResp,
  MsgSettingsWriteResp: MsgSettingsWriteResp,
  0x00A4: MsgSettingsReadReq,
  MsgSettingsReadReq: MsgSettingsReadReq,
  0x00A5: MsgSettingsReadResp,
  MsgSettingsReadResp: MsgSettingsReadResp,
  0x00A2: MsgSettingsReadByIndexReq,
  MsgSettingsReadByIndexReq: MsgSettingsReadByIndexReq,
  0x00A7: MsgSettingsReadByIndexResp,
  MsgSettingsReadByIndexResp: MsgSettingsReadByIndexResp,
  0x00A6: MsgSettingsReadByIndexDone,
  MsgSettingsReadByIndexDone: MsgSettingsReadByIndexDone,
  0x00AE: MsgSettingsRegister,
  MsgSettingsRegister: MsgSettingsRegister,
}

/***/ }),
/* 37 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/signal.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Struct to represent the signal (constellation, band, satellite identifier).
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(13).Parser;

/**
 * SBP class for message fragment SBPSignal
 *
 * Signal identifier containing constellation, band, and satellite identifier
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sat number (unsigned 16-bit int, 2 bytes) Constellation-specific satellite identifier
 * @field band number (unsigned 8-bit int, 1 byte) Signal band
 * @field constellation number (unsigned 8-bit int, 1 byte) Constellation to which the satellite belongs
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var SBPSignal = function (sbp) {
  SBP.call(this, sbp);
  this.messageType = "SBPSignal";
  this.fields = this.parser.parse(sbp.payload);

  return this;
};
SBPSignal.prototype = Object.create(SBP.prototype);
SBPSignal.prototype.constructor = SBPSignal;
SBPSignal.prototype.parser = new Parser()
  .endianess('little')
  .uint16('sat')
  .uint8('band')
  .uint8('constellation');
SBPSignal.prototype.fieldSpec = [];
SBPSignal.prototype.fieldSpec.push(['sat', 'writeUInt16LE', 2]);
SBPSignal.prototype.fieldSpec.push(['band', 'writeUInt8', 1]);
SBPSignal.prototype.fieldSpec.push(['constellation', 'writeUInt8', 1]);

module.exports = {
  SBPSignal: SBPSignal,
}


/***/ }),
/* 38 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/ssr.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Precise State Space Representation (SSR) corrections format
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;
var GnssSignal = __webpack_require__(0).GnssSignal;
var GnssSignalDep = __webpack_require__(0).GnssSignalDep;
var GPSTime = __webpack_require__(0).GPSTime;
var CarrierPhase = __webpack_require__(0).CarrierPhase;
var GPSTime = __webpack_require__(0).GPSTime;
var GPSTimeSec = __webpack_require__(0).GPSTimeSec;
var GPSTimeDep = __webpack_require__(0).GPSTimeDep;

/**
 * SBP class for message fragment CodeBiasesContent
 *
 * Code biases are to be added to pseudorange. The corrections are conform with
 * typical RTCMv3 MT1059 and 1065.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field code number (unsigned 8-bit int, 1 byte) Signal constellation, band and code
 * @field value number (signed 16-bit int, 2 bytes) Code bias value
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var CodeBiasesContent = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "CodeBiasesContent";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
CodeBiasesContent.prototype = Object.create(SBP.prototype);
CodeBiasesContent.prototype.messageType = "CodeBiasesContent";
CodeBiasesContent.prototype.constructor = CodeBiasesContent;
CodeBiasesContent.prototype.parser = new Parser()
  .endianess('little')
  .uint8('code')
  .int16('value');
CodeBiasesContent.prototype.fieldSpec = [];
CodeBiasesContent.prototype.fieldSpec.push(['code', 'writeUInt8', 1]);
CodeBiasesContent.prototype.fieldSpec.push(['value', 'writeInt16LE', 2]);

/**
 * SBP class for message fragment PhaseBiasesContent
 *
 * Phase biases are to be added to carrier phase measurements. The corrections are
 * conform with typical RTCMv3 MT1059 and 1065.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field code number (unsigned 8-bit int, 1 byte) Signal constellation, band and code
 * @field integer_indicator number (unsigned 8-bit int, 1 byte) Indicator for integer property
 * @field widelane_integer_indicator number (unsigned 8-bit int, 1 byte) Indicator for two groups of Wide-Lane(s) integer property
 * @field discontinuity_counter number (unsigned 8-bit int, 1 byte) Signal phase discontinuity counter.  Increased for every discontinuity in phase.
 * @field bias number (signed 32-bit int, 4 bytes) Phase bias for specified signal
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var PhaseBiasesContent = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "PhaseBiasesContent";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
PhaseBiasesContent.prototype = Object.create(SBP.prototype);
PhaseBiasesContent.prototype.messageType = "PhaseBiasesContent";
PhaseBiasesContent.prototype.constructor = PhaseBiasesContent;
PhaseBiasesContent.prototype.parser = new Parser()
  .endianess('little')
  .uint8('code')
  .uint8('integer_indicator')
  .uint8('widelane_integer_indicator')
  .uint8('discontinuity_counter')
  .int32('bias');
PhaseBiasesContent.prototype.fieldSpec = [];
PhaseBiasesContent.prototype.fieldSpec.push(['code', 'writeUInt8', 1]);
PhaseBiasesContent.prototype.fieldSpec.push(['integer_indicator', 'writeUInt8', 1]);
PhaseBiasesContent.prototype.fieldSpec.push(['widelane_integer_indicator', 'writeUInt8', 1]);
PhaseBiasesContent.prototype.fieldSpec.push(['discontinuity_counter', 'writeUInt8', 1]);
PhaseBiasesContent.prototype.fieldSpec.push(['bias', 'writeInt32LE', 4]);

/**
 * SBP class for message MSG_SSR_ORBIT_CLOCK (0x05DC).
 *
 * The precise orbit and clock correction message is  to be applied as a delta
 * correction to broadcast  ephemeris and is typically an equivalent to the 1060
 * and 1066 RTCM message types
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field time GPSTimeSec GNSS reference time of the correction
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 * @field update_interval number (unsigned 8-bit int, 1 byte) Update interval between consecutive corrections
 * @field iod_ssr number (unsigned 8-bit int, 1 byte) IOD of the SSR correction. A change of Issue Of Data SSR is used to indicate a
 *   change in the SSR  generating configuration
 * @field iod number (unsigned 8-bit int, 1 byte) Issue of broadcast ephemeris data
 * @field radial number (signed 32-bit int, 4 bytes) Orbit radial delta correction
 * @field along number (signed 32-bit int, 4 bytes) Orbit along delta correction
 * @field cross number (signed 32-bit int, 4 bytes) Orbit along delta correction
 * @field dot_radial number (signed 32-bit int, 4 bytes) Velocity of orbit radial delta correction
 * @field dot_along number (signed 32-bit int, 4 bytes) Velocity of orbit along delta correction
 * @field dot_cross number (signed 32-bit int, 4 bytes) Velocity of orbit cross delta correction
 * @field c0 number (signed 32-bit int, 4 bytes) C0 polynomial coefficient for correction of broadcast satellite clock
 * @field c1 number (signed 32-bit int, 4 bytes) C1 polynomial coefficient for correction of broadcast satellite clock
 * @field c2 number (signed 32-bit int, 4 bytes) C2 polynomial coefficient for correction of broadcast satellite clock
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSsrOrbitClock = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_ORBIT_CLOCK";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrOrbitClock.prototype = Object.create(SBP.prototype);
MsgSsrOrbitClock.prototype.messageType = "MSG_SSR_ORBIT_CLOCK";
MsgSsrOrbitClock.prototype.msg_type = 0x05DC;
MsgSsrOrbitClock.prototype.constructor = MsgSsrOrbitClock;
MsgSsrOrbitClock.prototype.parser = new Parser()
  .endianess('little')
  .nest('time', { type: GPSTimeSec.prototype.parser })
  .nest('sid', { type: GnssSignal.prototype.parser })
  .uint8('update_interval')
  .uint8('iod_ssr')
  .uint8('iod')
  .int32('radial')
  .int32('along')
  .int32('cross')
  .int32('dot_radial')
  .int32('dot_along')
  .int32('dot_cross')
  .int32('c0')
  .int32('c1')
  .int32('c2');
MsgSsrOrbitClock.prototype.fieldSpec = [];
MsgSsrOrbitClock.prototype.fieldSpec.push(['time', GPSTimeSec.prototype.fieldSpec]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['update_interval', 'writeUInt8', 1]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['iod_ssr', 'writeUInt8', 1]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['iod', 'writeUInt8', 1]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['radial', 'writeInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['along', 'writeInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['cross', 'writeInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['dot_radial', 'writeInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['dot_along', 'writeInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['dot_cross', 'writeInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['c0', 'writeInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['c1', 'writeInt32LE', 4]);
MsgSsrOrbitClock.prototype.fieldSpec.push(['c2', 'writeInt32LE', 4]);

/**
 * SBP class for message MSG_SSR_CODE_BIASES (0x05E1).
 *
 * The precise code biases message is to be added to the pseudorange of the
 * corresponding signal to get corrected pseudorange. It is typically  an
 * equivalent to the 1059 and 1065 RTCM message types
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field time GPSTimeSec GNSS reference time of the correction
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 * @field update_interval number (unsigned 8-bit int, 1 byte) Update interval between consecutive corrections
 * @field iod_ssr number (unsigned 8-bit int, 1 byte) IOD of the SSR correction. A change of Issue Of Data SSR is used to indicate a
 *   change in the SSR  generating configuration
 * @field biases array Code biases for the different satellite signals
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSsrCodeBiases = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_CODE_BIASES";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrCodeBiases.prototype = Object.create(SBP.prototype);
MsgSsrCodeBiases.prototype.messageType = "MSG_SSR_CODE_BIASES";
MsgSsrCodeBiases.prototype.msg_type = 0x05E1;
MsgSsrCodeBiases.prototype.constructor = MsgSsrCodeBiases;
MsgSsrCodeBiases.prototype.parser = new Parser()
  .endianess('little')
  .nest('time', { type: GPSTimeSec.prototype.parser })
  .nest('sid', { type: GnssSignal.prototype.parser })
  .uint8('update_interval')
  .uint8('iod_ssr')
  .array('biases', { type: CodeBiasesContent.prototype.parser, readUntil: 'eof' });
MsgSsrCodeBiases.prototype.fieldSpec = [];
MsgSsrCodeBiases.prototype.fieldSpec.push(['time', GPSTimeSec.prototype.fieldSpec]);
MsgSsrCodeBiases.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgSsrCodeBiases.prototype.fieldSpec.push(['update_interval', 'writeUInt8', 1]);
MsgSsrCodeBiases.prototype.fieldSpec.push(['iod_ssr', 'writeUInt8', 1]);
MsgSsrCodeBiases.prototype.fieldSpec.push(['biases', 'array', CodeBiasesContent.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message MSG_SSR_PHASE_BIASES (0x05E6).
 *
 * The precise phase biases message contains the biases to be added to the carrier
 * phase of the corresponding signal to get corrected carrier phase measurement, as
 * well as the satellite yaw angle to be applied to compute  the phase wind-up
 * correction.  It is typically an equivalent to the 1265 RTCM message types
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field time GPSTimeSec GNSS reference time of the correction
 * @field sid GnssSignal GNSS signal identifier (16 bit)
 * @field update_interval number (unsigned 8-bit int, 1 byte) Update interval between consecutive corrections
 * @field iod_ssr number (unsigned 8-bit int, 1 byte) IOD of the SSR correction. A change of Issue Of Data SSR is used to indicate a
 *   change in the SSR  generating configuration
 * @field dispersive_bias number (unsigned 8-bit int, 1 byte) Indicator for the dispersive phase biases property.
 * @field mw_consistency number (unsigned 8-bit int, 1 byte) Consistency indicator for Melbourne-Wubbena linear combinations
 * @field yaw number (unsigned 16-bit int, 2 bytes) Satellite yaw angle
 * @field yaw_rate number (signed 8-bit int, 1 byte) Satellite yaw angle rate
 * @field biases array Phase biases corrections for a satellite being tracked.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSsrPhaseBiases = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SSR_PHASE_BIASES";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSsrPhaseBiases.prototype = Object.create(SBP.prototype);
MsgSsrPhaseBiases.prototype.messageType = "MSG_SSR_PHASE_BIASES";
MsgSsrPhaseBiases.prototype.msg_type = 0x05E6;
MsgSsrPhaseBiases.prototype.constructor = MsgSsrPhaseBiases;
MsgSsrPhaseBiases.prototype.parser = new Parser()
  .endianess('little')
  .nest('time', { type: GPSTimeSec.prototype.parser })
  .nest('sid', { type: GnssSignal.prototype.parser })
  .uint8('update_interval')
  .uint8('iod_ssr')
  .uint8('dispersive_bias')
  .uint8('mw_consistency')
  .uint16('yaw')
  .int8('yaw_rate')
  .array('biases', { type: PhaseBiasesContent.prototype.parser, readUntil: 'eof' });
MsgSsrPhaseBiases.prototype.fieldSpec = [];
MsgSsrPhaseBiases.prototype.fieldSpec.push(['time', GPSTimeSec.prototype.fieldSpec]);
MsgSsrPhaseBiases.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgSsrPhaseBiases.prototype.fieldSpec.push(['update_interval', 'writeUInt8', 1]);
MsgSsrPhaseBiases.prototype.fieldSpec.push(['iod_ssr', 'writeUInt8', 1]);
MsgSsrPhaseBiases.prototype.fieldSpec.push(['dispersive_bias', 'writeUInt8', 1]);
MsgSsrPhaseBiases.prototype.fieldSpec.push(['mw_consistency', 'writeUInt8', 1]);
MsgSsrPhaseBiases.prototype.fieldSpec.push(['yaw', 'writeUInt16LE', 2]);
MsgSsrPhaseBiases.prototype.fieldSpec.push(['yaw_rate', 'writeInt8', 1]);
MsgSsrPhaseBiases.prototype.fieldSpec.push(['biases', 'array', PhaseBiasesContent.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

module.exports = {
  CodeBiasesContent: CodeBiasesContent,
  PhaseBiasesContent: PhaseBiasesContent,
  0x05DC: MsgSsrOrbitClock,
  MsgSsrOrbitClock: MsgSsrOrbitClock,
  0x05E1: MsgSsrCodeBiases,
  MsgSsrCodeBiases: MsgSsrCodeBiases,
  0x05E6: MsgSsrPhaseBiases,
  MsgSsrPhaseBiases: MsgSsrPhaseBiases,
}

/***/ }),
/* 39 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/system.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Standardized system messages from Swift Navigation devices.
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;

/**
 * SBP class for message MSG_STARTUP (0xFF00).
 *
 * The system start-up message is sent once on system start-up. It notifies the
 * host or other attached devices that the system has started and is now ready to
 * respond to commands or configuration requests.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field cause number (unsigned 8-bit int, 1 byte) Cause of startup
 * @field startup_type number (unsigned 8-bit int, 1 byte) Startup type
 * @field reserved number (unsigned 16-bit int, 2 bytes) Reserved
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
  .uint8('cause')
  .uint8('startup_type')
  .uint16('reserved');
MsgStartup.prototype.fieldSpec = [];
MsgStartup.prototype.fieldSpec.push(['cause', 'writeUInt8', 1]);
MsgStartup.prototype.fieldSpec.push(['startup_type', 'writeUInt8', 1]);
MsgStartup.prototype.fieldSpec.push(['reserved', 'writeUInt16LE', 2]);

/**
 * SBP class for message MSG_DGNSS_STATUS (0xFF02).
 *
 * This message provides information about the receipt of Differential corrections.
 * It is expected to be sent with each receipt of a complete corrections packet.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 * @field latency number (unsigned 16-bit int, 2 bytes) Latency of observation receipt
 * @field num_signals number (unsigned 8-bit int, 1 byte) Number of signals from base station
 * @field source string Corrections source string
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgDgnssStatus = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_DGNSS_STATUS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgDgnssStatus.prototype = Object.create(SBP.prototype);
MsgDgnssStatus.prototype.messageType = "MSG_DGNSS_STATUS";
MsgDgnssStatus.prototype.msg_type = 0xFF02;
MsgDgnssStatus.prototype.constructor = MsgDgnssStatus;
MsgDgnssStatus.prototype.parser = new Parser()
  .endianess('little')
  .uint8('flags')
  .uint16('latency')
  .uint8('num_signals')
  .string('source', { greedy: true });
MsgDgnssStatus.prototype.fieldSpec = [];
MsgDgnssStatus.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);
MsgDgnssStatus.prototype.fieldSpec.push(['latency', 'writeUInt16LE', 2]);
MsgDgnssStatus.prototype.fieldSpec.push(['num_signals', 'writeUInt8', 1]);
MsgDgnssStatus.prototype.fieldSpec.push(['source', 'string', null]);

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

/**
 * SBP class for message MSG_INS_STATUS (0xFF03).
 *
 * The INS status message describes the state of the operation and initialization
 * of the inertial navigation system.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field flags number (unsigned 32-bit int, 4 bytes) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgInsStatus = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_INS_STATUS";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgInsStatus.prototype = Object.create(SBP.prototype);
MsgInsStatus.prototype.messageType = "MSG_INS_STATUS";
MsgInsStatus.prototype.msg_type = 0xFF03;
MsgInsStatus.prototype.constructor = MsgInsStatus;
MsgInsStatus.prototype.parser = new Parser()
  .endianess('little')
  .uint32('flags');
MsgInsStatus.prototype.fieldSpec = [];
MsgInsStatus.prototype.fieldSpec.push(['flags', 'writeUInt32LE', 4]);

module.exports = {
  0xFF00: MsgStartup,
  MsgStartup: MsgStartup,
  0xFF02: MsgDgnssStatus,
  MsgDgnssStatus: MsgDgnssStatus,
  0xFFFF: MsgHeartbeat,
  MsgHeartbeat: MsgHeartbeat,
  0xFF03: MsgInsStatus,
  MsgInsStatus: MsgInsStatus,
}

/***/ }),
/* 40 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/tracking.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Satellite code and carrier-phase tracking messages from the device.
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;
var GnssSignal = __webpack_require__(0).GnssSignal;
var GnssSignalDep = __webpack_require__(0).GnssSignalDep;
var GPSTime = __webpack_require__(0).GPSTime;
var CarrierPhase = __webpack_require__(0).CarrierPhase;
var GPSTime = __webpack_require__(0).GPSTime;
var GPSTimeSec = __webpack_require__(0).GPSTimeSec;
var GPSTimeDep = __webpack_require__(0).GPSTimeDep;

/**
 * SBP class for message MSG_TRACKING_STATE_DETAILED_DEP_A (0x0021).
 *
 * The tracking message returns a set tracking channel parameters for a single
 * tracking channel useful for debugging issues.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field recv_time number (unsigned 64-bit int, 8 bytes) Receiver clock time.
 * @field tot GPSTime Time of transmission of signal from satellite. TOW only valid when TOW status is
 *   decoded or propagated. WN only valid when week number valid flag is set.
 * @field P number (unsigned 32-bit int, 4 bytes) Pseudorange observation. Valid only when pseudorange valid flag is set.
 * @field P_std number (unsigned 16-bit int, 2 bytes) Pseudorange observation standard deviation. Valid only when pseudorange valid
 *   flag is set.
 * @field L CarrierPhase Carrier phase observation with typical sign convention. Valid only when PLL
 *   pessimistic lock is achieved.
 * @field cn0 number (unsigned 8-bit int, 1 byte) Carrier-to-Noise density
 * @field lock number (unsigned 16-bit int, 2 bytes) Lock time. It is encoded according to DF402 from the RTCM 10403.2 Amendment 2
 *   specification. Valid values range from 0 to 15.
 * @field sid GnssSignal GNSS signal identifier.
 * @field doppler number (signed 32-bit int, 4 bytes) Carrier Doppler frequency.
 * @field doppler_std number (unsigned 16-bit int, 2 bytes) Carrier Doppler frequency standard deviation.
 * @field uptime number (unsigned 32-bit int, 4 bytes) Number of seconds of continuous tracking. Specifies how much time signal is in
 *   continuous track.
 * @field clock_offset number (signed 16-bit int, 2 bytes) TCXO clock offset. Valid only when valid clock valid flag is set.
 * @field clock_drift number (signed 16-bit int, 2 bytes) TCXO clock drift. Valid only when valid clock valid flag is set.
 * @field corr_spacing number (unsigned 16-bit int, 2 bytes) Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
 * @field acceleration number (signed 8-bit int, 1 byte) Acceleration. Valid only when acceleration valid flag is set.
 * @field sync_flags number (unsigned 8-bit int, 1 byte) Synchronization status flags.
 * @field tow_flags number (unsigned 8-bit int, 1 byte) TOW status flags.
 * @field track_flags number (unsigned 8-bit int, 1 byte) Tracking loop status flags.
 * @field nav_flags number (unsigned 8-bit int, 1 byte) Navigation data status flags.
 * @field pset_flags number (unsigned 8-bit int, 1 byte) Parameters sets flags.
 * @field misc_flags number (unsigned 8-bit int, 1 byte) Miscellaneous flags.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgTrackingStateDetailedDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TRACKING_STATE_DETAILED_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTrackingStateDetailedDepA.prototype = Object.create(SBP.prototype);
MsgTrackingStateDetailedDepA.prototype.messageType = "MSG_TRACKING_STATE_DETAILED_DEP_A";
MsgTrackingStateDetailedDepA.prototype.msg_type = 0x0021;
MsgTrackingStateDetailedDepA.prototype.constructor = MsgTrackingStateDetailedDepA;
MsgTrackingStateDetailedDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint64('recv_time')
  .nest('tot', { type: GPSTime.prototype.parser })
  .uint32('P')
  .uint16('P_std')
  .nest('L', { type: CarrierPhase.prototype.parser })
  .uint8('cn0')
  .uint16('lock')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .int32('doppler')
  .uint16('doppler_std')
  .uint32('uptime')
  .int16('clock_offset')
  .int16('clock_drift')
  .uint16('corr_spacing')
  .int8('acceleration')
  .uint8('sync_flags')
  .uint8('tow_flags')
  .uint8('track_flags')
  .uint8('nav_flags')
  .uint8('pset_flags')
  .uint8('misc_flags');
MsgTrackingStateDetailedDepA.prototype.fieldSpec = [];
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['recv_time', 'writeUInt64LE', 8]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['tot', GPSTime.prototype.fieldSpec]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['P', 'writeUInt32LE', 4]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['P_std', 'writeUInt16LE', 2]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['L', CarrierPhase.prototype.fieldSpec]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['lock', 'writeUInt16LE', 2]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['doppler', 'writeInt32LE', 4]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['doppler_std', 'writeUInt16LE', 2]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['uptime', 'writeUInt32LE', 4]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['clock_offset', 'writeInt16LE', 2]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['clock_drift', 'writeInt16LE', 2]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['corr_spacing', 'writeUInt16LE', 2]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['acceleration', 'writeInt8', 1]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['sync_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['tow_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['track_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['nav_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['pset_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDepA.prototype.fieldSpec.push(['misc_flags', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_TRACKING_STATE_DETAILED_DEP (0x0011).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field recv_time number (unsigned 64-bit int, 8 bytes) Receiver clock time.
 * @field tot GPSTimeDep Time of transmission of signal from satellite. TOW only valid when TOW status is
 *   decoded or propagated. WN only valid when week number valid flag is set.
 * @field P number (unsigned 32-bit int, 4 bytes) Pseudorange observation. Valid only when pseudorange valid flag is set.
 * @field P_std number (unsigned 16-bit int, 2 bytes) Pseudorange observation standard deviation. Valid only when pseudorange valid
 *   flag is set.
 * @field L CarrierPhase Carrier phase observation with typical sign convention. Valid only when PLL
 *   pessimistic lock is achieved.
 * @field cn0 number (unsigned 8-bit int, 1 byte) Carrier-to-Noise density
 * @field lock number (unsigned 16-bit int, 2 bytes) Lock time. It is encoded according to DF402 from the RTCM 10403.2 Amendment 2
 *   specification. Valid values range from 0 to 15.
 * @field sid GnssSignalDep GNSS signal identifier.
 * @field doppler number (signed 32-bit int, 4 bytes) Carrier Doppler frequency.
 * @field doppler_std number (unsigned 16-bit int, 2 bytes) Carrier Doppler frequency standard deviation.
 * @field uptime number (unsigned 32-bit int, 4 bytes) Number of seconds of continuous tracking. Specifies how much time signal is in
 *   continuous track.
 * @field clock_offset number (signed 16-bit int, 2 bytes) TCXO clock offset. Valid only when valid clock valid flag is set.
 * @field clock_drift number (signed 16-bit int, 2 bytes) TCXO clock drift. Valid only when valid clock valid flag is set.
 * @field corr_spacing number (unsigned 16-bit int, 2 bytes) Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
 * @field acceleration number (signed 8-bit int, 1 byte) Acceleration. Valid only when acceleration valid flag is set.
 * @field sync_flags number (unsigned 8-bit int, 1 byte) Synchronization status flags.
 * @field tow_flags number (unsigned 8-bit int, 1 byte) TOW status flags.
 * @field track_flags number (unsigned 8-bit int, 1 byte) Tracking loop status flags.
 * @field nav_flags number (unsigned 8-bit int, 1 byte) Navigation data status flags.
 * @field pset_flags number (unsigned 8-bit int, 1 byte) Parameters sets flags.
 * @field misc_flags number (unsigned 8-bit int, 1 byte) Miscellaneous flags.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgTrackingStateDetailedDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TRACKING_STATE_DETAILED_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTrackingStateDetailedDep.prototype = Object.create(SBP.prototype);
MsgTrackingStateDetailedDep.prototype.messageType = "MSG_TRACKING_STATE_DETAILED_DEP";
MsgTrackingStateDetailedDep.prototype.msg_type = 0x0011;
MsgTrackingStateDetailedDep.prototype.constructor = MsgTrackingStateDetailedDep;
MsgTrackingStateDetailedDep.prototype.parser = new Parser()
  .endianess('little')
  .uint64('recv_time')
  .nest('tot', { type: GPSTimeDep.prototype.parser })
  .uint32('P')
  .uint16('P_std')
  .nest('L', { type: CarrierPhase.prototype.parser })
  .uint8('cn0')
  .uint16('lock')
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .int32('doppler')
  .uint16('doppler_std')
  .uint32('uptime')
  .int16('clock_offset')
  .int16('clock_drift')
  .uint16('corr_spacing')
  .int8('acceleration')
  .uint8('sync_flags')
  .uint8('tow_flags')
  .uint8('track_flags')
  .uint8('nav_flags')
  .uint8('pset_flags')
  .uint8('misc_flags');
MsgTrackingStateDetailedDep.prototype.fieldSpec = [];
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['recv_time', 'writeUInt64LE', 8]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['tot', GPSTimeDep.prototype.fieldSpec]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['P', 'writeUInt32LE', 4]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['P_std', 'writeUInt16LE', 2]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['L', CarrierPhase.prototype.fieldSpec]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['lock', 'writeUInt16LE', 2]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['doppler', 'writeInt32LE', 4]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['doppler_std', 'writeUInt16LE', 2]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['uptime', 'writeUInt32LE', 4]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['clock_offset', 'writeInt16LE', 2]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['clock_drift', 'writeInt16LE', 2]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['corr_spacing', 'writeUInt16LE', 2]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['acceleration', 'writeInt8', 1]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['sync_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['tow_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['track_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['nav_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['pset_flags', 'writeUInt8', 1]);
MsgTrackingStateDetailedDep.prototype.fieldSpec.push(['misc_flags', 'writeUInt8', 1]);

/**
 * SBP class for message fragment TrackingChannelState
 *
 * Tracking channel state for a specific satellite signal and measured signal
 * power.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field sid GnssSignal GNSS signal being tracked
 * @field fcn number (unsigned 8-bit int, 1 byte) Frequency channel number (GLONASS only)
 * @field cn0 number (unsigned 8-bit int, 1 byte) Carrier-to-Noise density.  Zero implies invalid cn0.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var TrackingChannelState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "TrackingChannelState";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
TrackingChannelState.prototype = Object.create(SBP.prototype);
TrackingChannelState.prototype.messageType = "TrackingChannelState";
TrackingChannelState.prototype.constructor = TrackingChannelState;
TrackingChannelState.prototype.parser = new Parser()
  .endianess('little')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .uint8('fcn')
  .uint8('cn0');
TrackingChannelState.prototype.fieldSpec = [];
TrackingChannelState.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
TrackingChannelState.prototype.fieldSpec.push(['fcn', 'writeUInt8', 1]);
TrackingChannelState.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_TRACKING_STATE (0x0041).
 *
 * The tracking message returns a variable-length array of tracking channel states.
 * It reports status and carrier-to-noise density measurements for all tracked
 * satellites.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field states array Signal tracking channel state
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgTrackingState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TRACKING_STATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTrackingState.prototype = Object.create(SBP.prototype);
MsgTrackingState.prototype.messageType = "MSG_TRACKING_STATE";
MsgTrackingState.prototype.msg_type = 0x0041;
MsgTrackingState.prototype.constructor = MsgTrackingState;
MsgTrackingState.prototype.parser = new Parser()
  .endianess('little')
  .array('states', { type: TrackingChannelState.prototype.parser, readUntil: 'eof' });
MsgTrackingState.prototype.fieldSpec = [];
MsgTrackingState.prototype.fieldSpec.push(['states', 'array', TrackingChannelState.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message fragment MeasurementState
 *
 * Measurement Engine tracking channel state for a specific satellite signal  and
 * measured signal power.  The mesid field for Glonass can either  carry the FCN as
 * 100 + FCN where FCN is in [-7, +6] or  the Slot ID (from 1 to 28)
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field mesid GnssSignal Measurement Engine GNSS signal being tracked (carries either Glonass FCN or
 *   SLOT)
 * @field cn0 number (unsigned 8-bit int, 1 byte) Carrier-to-Noise density.  Zero implies invalid cn0.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MeasurementState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MeasurementState";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MeasurementState.prototype = Object.create(SBP.prototype);
MeasurementState.prototype.messageType = "MeasurementState";
MeasurementState.prototype.constructor = MeasurementState;
MeasurementState.prototype.parser = new Parser()
  .endianess('little')
  .nest('mesid', { type: GnssSignal.prototype.parser })
  .uint8('cn0');
MeasurementState.prototype.fieldSpec = [];
MeasurementState.prototype.fieldSpec.push(['mesid', GnssSignal.prototype.fieldSpec]);
MeasurementState.prototype.fieldSpec.push(['cn0', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_MEASUREMENT_STATE (0x0061).
 *
 * The tracking message returns a variable-length array of tracking channel states.
 * It reports status and carrier-to-noise density measurements for all tracked
 * satellites.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field states array ME signal tracking channel state
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgMeasurementState = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_MEASUREMENT_STATE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgMeasurementState.prototype = Object.create(SBP.prototype);
MsgMeasurementState.prototype.messageType = "MSG_MEASUREMENT_STATE";
MsgMeasurementState.prototype.msg_type = 0x0061;
MsgMeasurementState.prototype.constructor = MsgMeasurementState;
MsgMeasurementState.prototype.parser = new Parser()
  .endianess('little')
  .array('states', { type: MeasurementState.prototype.parser, readUntil: 'eof' });
MsgMeasurementState.prototype.fieldSpec = [];
MsgMeasurementState.prototype.fieldSpec.push(['states', 'array', MeasurementState.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message fragment TrackingChannelCorrelation
 *
 * Structure containing in-phase and quadrature correlation components.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field I number (signed 32-bit int, 4 bytes) In-phase correlation
 * @field Q number (signed 32-bit int, 4 bytes) Quadrature correlation
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var TrackingChannelCorrelation = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "TrackingChannelCorrelation";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
TrackingChannelCorrelation.prototype = Object.create(SBP.prototype);
TrackingChannelCorrelation.prototype.messageType = "TrackingChannelCorrelation";
TrackingChannelCorrelation.prototype.constructor = TrackingChannelCorrelation;
TrackingChannelCorrelation.prototype.parser = new Parser()
  .endianess('little')
  .int32('I')
  .int32('Q');
TrackingChannelCorrelation.prototype.fieldSpec = [];
TrackingChannelCorrelation.prototype.fieldSpec.push(['I', 'writeInt32LE', 4]);
TrackingChannelCorrelation.prototype.fieldSpec.push(['Q', 'writeInt32LE', 4]);

/**
 * SBP class for message MSG_TRACKING_IQ (0x002C).
 *
 * When enabled, a tracking channel can output the correlations at each update
 * interval.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field channel number (unsigned 8-bit int, 1 byte) Tracking channel of origin
 * @field sid GnssSignal GNSS signal identifier
 * @field corrs array Early, Prompt and Late correlations
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgTrackingIq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TRACKING_IQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTrackingIq.prototype = Object.create(SBP.prototype);
MsgTrackingIq.prototype.messageType = "MSG_TRACKING_IQ";
MsgTrackingIq.prototype.msg_type = 0x002C;
MsgTrackingIq.prototype.constructor = MsgTrackingIq;
MsgTrackingIq.prototype.parser = new Parser()
  .endianess('little')
  .uint8('channel')
  .nest('sid', { type: GnssSignal.prototype.parser })
  .array('corrs', { length: 3, type: TrackingChannelCorrelation.prototype.parser });
MsgTrackingIq.prototype.fieldSpec = [];
MsgTrackingIq.prototype.fieldSpec.push(['channel', 'writeUInt8', 1]);
MsgTrackingIq.prototype.fieldSpec.push(['sid', GnssSignal.prototype.fieldSpec]);
MsgTrackingIq.prototype.fieldSpec.push(['corrs', 'array', TrackingChannelCorrelation.prototype.fieldSpec, function () { return this.fields.array.length; }, 3]);

/**
 * SBP class for message MSG_TRACKING_IQ_DEP (0x001C).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field channel number (unsigned 8-bit int, 1 byte) Tracking channel of origin
 * @field sid GnssSignalDep GNSS signal identifier
 * @field corrs array Early, Prompt and Late correlations
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgTrackingIqDep = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TRACKING_IQ_DEP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTrackingIqDep.prototype = Object.create(SBP.prototype);
MsgTrackingIqDep.prototype.messageType = "MSG_TRACKING_IQ_DEP";
MsgTrackingIqDep.prototype.msg_type = 0x001C;
MsgTrackingIqDep.prototype.constructor = MsgTrackingIqDep;
MsgTrackingIqDep.prototype.parser = new Parser()
  .endianess('little')
  .uint8('channel')
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .array('corrs', { length: 3, type: TrackingChannelCorrelation.prototype.parser });
MsgTrackingIqDep.prototype.fieldSpec = [];
MsgTrackingIqDep.prototype.fieldSpec.push(['channel', 'writeUInt8', 1]);
MsgTrackingIqDep.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
MsgTrackingIqDep.prototype.fieldSpec.push(['corrs', 'array', TrackingChannelCorrelation.prototype.fieldSpec, function () { return this.fields.array.length; }, 3]);

/**
 * SBP class for message fragment TrackingChannelStateDepA
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field state number (unsigned 8-bit int, 1 byte) Status of tracking channel
 * @field prn number (unsigned 8-bit int, 1 byte) PRN-1 being tracked
 * @field cn0 number (float, 4 bytes) Carrier-to-noise density
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var TrackingChannelStateDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "TrackingChannelStateDepA";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
TrackingChannelStateDepA.prototype = Object.create(SBP.prototype);
TrackingChannelStateDepA.prototype.messageType = "TrackingChannelStateDepA";
TrackingChannelStateDepA.prototype.constructor = TrackingChannelStateDepA;
TrackingChannelStateDepA.prototype.parser = new Parser()
  .endianess('little')
  .uint8('state')
  .uint8('prn')
  .floatle('cn0');
TrackingChannelStateDepA.prototype.fieldSpec = [];
TrackingChannelStateDepA.prototype.fieldSpec.push(['state', 'writeUInt8', 1]);
TrackingChannelStateDepA.prototype.fieldSpec.push(['prn', 'writeUInt8', 1]);
TrackingChannelStateDepA.prototype.fieldSpec.push(['cn0', 'writeFloatLE', 4]);

/**
 * SBP class for message MSG_TRACKING_STATE_DEP_A (0x0016).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field states array Satellite tracking channel state
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgTrackingStateDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TRACKING_STATE_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTrackingStateDepA.prototype = Object.create(SBP.prototype);
MsgTrackingStateDepA.prototype.messageType = "MSG_TRACKING_STATE_DEP_A";
MsgTrackingStateDepA.prototype.msg_type = 0x0016;
MsgTrackingStateDepA.prototype.constructor = MsgTrackingStateDepA;
MsgTrackingStateDepA.prototype.parser = new Parser()
  .endianess('little')
  .array('states', { type: TrackingChannelStateDepA.prototype.parser, readUntil: 'eof' });
MsgTrackingStateDepA.prototype.fieldSpec = [];
MsgTrackingStateDepA.prototype.fieldSpec.push(['states', 'array', TrackingChannelStateDepA.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

/**
 * SBP class for message fragment TrackingChannelStateDepB
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field state number (unsigned 8-bit int, 1 byte) Status of tracking channel
 * @field sid GnssSignalDep GNSS signal being tracked
 * @field cn0 number (float, 4 bytes) Carrier-to-noise density
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var TrackingChannelStateDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "TrackingChannelStateDepB";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
TrackingChannelStateDepB.prototype = Object.create(SBP.prototype);
TrackingChannelStateDepB.prototype.messageType = "TrackingChannelStateDepB";
TrackingChannelStateDepB.prototype.constructor = TrackingChannelStateDepB;
TrackingChannelStateDepB.prototype.parser = new Parser()
  .endianess('little')
  .uint8('state')
  .nest('sid', { type: GnssSignalDep.prototype.parser })
  .floatle('cn0');
TrackingChannelStateDepB.prototype.fieldSpec = [];
TrackingChannelStateDepB.prototype.fieldSpec.push(['state', 'writeUInt8', 1]);
TrackingChannelStateDepB.prototype.fieldSpec.push(['sid', GnssSignalDep.prototype.fieldSpec]);
TrackingChannelStateDepB.prototype.fieldSpec.push(['cn0', 'writeFloatLE', 4]);

/**
 * SBP class for message MSG_TRACKING_STATE_DEP_B (0x0013).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field states array Signal tracking channel state
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgTrackingStateDepB = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_TRACKING_STATE_DEP_B";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgTrackingStateDepB.prototype = Object.create(SBP.prototype);
MsgTrackingStateDepB.prototype.messageType = "MSG_TRACKING_STATE_DEP_B";
MsgTrackingStateDepB.prototype.msg_type = 0x0013;
MsgTrackingStateDepB.prototype.constructor = MsgTrackingStateDepB;
MsgTrackingStateDepB.prototype.parser = new Parser()
  .endianess('little')
  .array('states', { type: TrackingChannelStateDepB.prototype.parser, readUntil: 'eof' });
MsgTrackingStateDepB.prototype.fieldSpec = [];
MsgTrackingStateDepB.prototype.fieldSpec.push(['states', 'array', TrackingChannelStateDepB.prototype.fieldSpec, function () { return this.fields.array.length; }, null]);

module.exports = {
  0x0021: MsgTrackingStateDetailedDepA,
  MsgTrackingStateDetailedDepA: MsgTrackingStateDetailedDepA,
  0x0011: MsgTrackingStateDetailedDep,
  MsgTrackingStateDetailedDep: MsgTrackingStateDetailedDep,
  TrackingChannelState: TrackingChannelState,
  0x0041: MsgTrackingState,
  MsgTrackingState: MsgTrackingState,
  MeasurementState: MeasurementState,
  0x0061: MsgMeasurementState,
  MsgMeasurementState: MsgMeasurementState,
  TrackingChannelCorrelation: TrackingChannelCorrelation,
  0x002C: MsgTrackingIq,
  MsgTrackingIq: MsgTrackingIq,
  0x001C: MsgTrackingIqDep,
  MsgTrackingIqDep: MsgTrackingIqDep,
  TrackingChannelStateDepA: TrackingChannelStateDepA,
  0x0016: MsgTrackingStateDepA,
  MsgTrackingStateDepA: MsgTrackingStateDepA,
  TrackingChannelStateDepB: TrackingChannelStateDepB,
  0x0013: MsgTrackingStateDepB,
  MsgTrackingStateDepB: MsgTrackingStateDepB,
}

/***/ }),
/* 41 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/user.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages reserved for use by the user.
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;

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
MsgUserData.prototype.fieldSpec.push(['contents', 'array', 'writeUInt8', function () { return 1; }, null]);

module.exports = {
  0x0800: MsgUserData,
  MsgUserData: MsgUserData,
}

/***/ }),
/* 42 */
/***/ (function(module, exports, __webpack_require__) {

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
 * Automatically generated from piksi/yaml/swiftnav/sbp/vehicle.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages from a vehicle.
***********************/

var SBP = __webpack_require__(2);
var Parser = __webpack_require__(4);
var Int64 = __webpack_require__(3);
var UInt64 = __webpack_require__(1).UINT64;

/**
 * SBP class for message MSG_ODOMETRY (0x0903).
 *
 * Message representing the x component of vehicle velocity in the user frame at
 * the odometry reference point(s) specified by the user. The offset for the
 * odometry reference point and  the definition and origin of the user frame are
 * defined through the device settings interface. There are 4 possible user-defined
 * sources of this message  which are labeled arbitrarily  source 0 through 3.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field tow number (unsigned 32-bit int, 4 bytes) Time field representing either milliseconds in the GPS Week or local CPU time
 *   from the producing system in milliseconds.  See the tow_source flag for the
 *   exact source of this timestamp.
 * @field velocity number (signed 32-bit int, 4 bytes) The signed forward component of vehicle velocity.
 * @field flags number (unsigned 8-bit int, 1 byte) Status flags
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgOdometry = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_ODOMETRY";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgOdometry.prototype = Object.create(SBP.prototype);
MsgOdometry.prototype.messageType = "MSG_ODOMETRY";
MsgOdometry.prototype.msg_type = 0x0903;
MsgOdometry.prototype.constructor = MsgOdometry;
MsgOdometry.prototype.parser = new Parser()
  .endianess('little')
  .uint32('tow')
  .int32('velocity')
  .uint8('flags');
MsgOdometry.prototype.fieldSpec = [];
MsgOdometry.prototype.fieldSpec.push(['tow', 'writeUInt32LE', 4]);
MsgOdometry.prototype.fieldSpec.push(['velocity', 'writeInt32LE', 4]);
MsgOdometry.prototype.fieldSpec.push(['flags', 'writeUInt8', 1]);

module.exports = {
  0x0903: MsgOdometry,
  MsgOdometry: MsgOdometry,
}

/***/ }),
/* 43 */
/***/ (function(module, exports, __webpack_require__) {

/* WEBPACK VAR INJECTION */(function(process) {// Copyright Joyent, Inc. and other Node contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.

// resolves . and .. elements in a path array with directory names there
// must be no slashes, empty elements, or device names (c:\) in the array
// (so also no leading and trailing slashes - it does not distinguish
// relative and absolute paths)
function normalizeArray(parts, allowAboveRoot) {
  // if the path tries to go above the root, `up` ends up > 0
  var up = 0;
  for (var i = parts.length - 1; i >= 0; i--) {
    var last = parts[i];
    if (last === '.') {
      parts.splice(i, 1);
    } else if (last === '..') {
      parts.splice(i, 1);
      up++;
    } else if (up) {
      parts.splice(i, 1);
      up--;
    }
  }

  // if the path is allowed to go above the root, restore leading ..s
  if (allowAboveRoot) {
    for (; up--; up) {
      parts.unshift('..');
    }
  }

  return parts;
}

// Split a filename into [root, dir, basename, ext], unix version
// 'root' is just a slash, or nothing.
var splitPathRe =
    /^(\/?|)([\s\S]*?)((?:\.{1,2}|[^\/]+?|)(\.[^.\/]*|))(?:[\/]*)$/;
var splitPath = function(filename) {
  return splitPathRe.exec(filename).slice(1);
};

// path.resolve([from ...], to)
// posix version
exports.resolve = function() {
  var resolvedPath = '',
      resolvedAbsolute = false;

  for (var i = arguments.length - 1; i >= -1 && !resolvedAbsolute; i--) {
    var path = (i >= 0) ? arguments[i] : process.cwd();

    // Skip empty and invalid entries
    if (typeof path !== 'string') {
      throw new TypeError('Arguments to path.resolve must be strings');
    } else if (!path) {
      continue;
    }

    resolvedPath = path + '/' + resolvedPath;
    resolvedAbsolute = path.charAt(0) === '/';
  }

  // At this point the path should be resolved to a full absolute path, but
  // handle relative paths to be safe (might happen when process.cwd() fails)

  // Normalize the path
  resolvedPath = normalizeArray(filter(resolvedPath.split('/'), function(p) {
    return !!p;
  }), !resolvedAbsolute).join('/');

  return ((resolvedAbsolute ? '/' : '') + resolvedPath) || '.';
};

// path.normalize(path)
// posix version
exports.normalize = function(path) {
  var isAbsolute = exports.isAbsolute(path),
      trailingSlash = substr(path, -1) === '/';

  // Normalize the path
  path = normalizeArray(filter(path.split('/'), function(p) {
    return !!p;
  }), !isAbsolute).join('/');

  if (!path && !isAbsolute) {
    path = '.';
  }
  if (path && trailingSlash) {
    path += '/';
  }

  return (isAbsolute ? '/' : '') + path;
};

// posix version
exports.isAbsolute = function(path) {
  return path.charAt(0) === '/';
};

// posix version
exports.join = function() {
  var paths = Array.prototype.slice.call(arguments, 0);
  return exports.normalize(filter(paths, function(p, index) {
    if (typeof p !== 'string') {
      throw new TypeError('Arguments to path.join must be strings');
    }
    return p;
  }).join('/'));
};


// path.relative(from, to)
// posix version
exports.relative = function(from, to) {
  from = exports.resolve(from).substr(1);
  to = exports.resolve(to).substr(1);

  function trim(arr) {
    var start = 0;
    for (; start < arr.length; start++) {
      if (arr[start] !== '') break;
    }

    var end = arr.length - 1;
    for (; end >= 0; end--) {
      if (arr[end] !== '') break;
    }

    if (start > end) return [];
    return arr.slice(start, end - start + 1);
  }

  var fromParts = trim(from.split('/'));
  var toParts = trim(to.split('/'));

  var length = Math.min(fromParts.length, toParts.length);
  var samePartsLength = length;
  for (var i = 0; i < length; i++) {
    if (fromParts[i] !== toParts[i]) {
      samePartsLength = i;
      break;
    }
  }

  var outputParts = [];
  for (var i = samePartsLength; i < fromParts.length; i++) {
    outputParts.push('..');
  }

  outputParts = outputParts.concat(toParts.slice(samePartsLength));

  return outputParts.join('/');
};

exports.sep = '/';
exports.delimiter = ':';

exports.dirname = function(path) {
  var result = splitPath(path),
      root = result[0],
      dir = result[1];

  if (!root && !dir) {
    // No dirname whatsoever
    return '.';
  }

  if (dir) {
    // It has a dirname, strip trailing slash
    dir = dir.substr(0, dir.length - 1);
  }

  return root + dir;
};


exports.basename = function(path, ext) {
  var f = splitPath(path)[2];
  // TODO: make this comparison case-insensitive on windows?
  if (ext && f.substr(-1 * ext.length) === ext) {
    f = f.substr(0, f.length - ext.length);
  }
  return f;
};


exports.extname = function(path) {
  return splitPath(path)[3];
};

function filter (xs, f) {
    if (xs.filter) return xs.filter(f);
    var res = [];
    for (var i = 0; i < xs.length; i++) {
        if (f(xs[i], i, xs)) res.push(xs[i]);
    }
    return res;
}

// String.prototype.substr - negative index don't work in IE8
var substr = 'ab'.substr(-1) === 'b'
    ? function (str, start, len) { return str.substr(start, len) }
    : function (str, start, len) {
        if (start < 0) start = str.length + start;
        return str.substr(start, len);
    }
;

/* WEBPACK VAR INJECTION */}.call(exports, __webpack_require__(9)))

/***/ }),
/* 44 */
/***/ (function(module, exports, __webpack_require__) {

// Copyright Joyent, Inc. and other Node contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.

module.exports = Stream;

var EE = __webpack_require__(14).EventEmitter;
var inherits = __webpack_require__(8);

inherits(Stream, EE);
Stream.Readable = __webpack_require__(16);
Stream.Writable = __webpack_require__(58);
Stream.Duplex = __webpack_require__(53);
Stream.Transform = __webpack_require__(57);
Stream.PassThrough = __webpack_require__(56);

// Backwards-compat with node 0.4.x
Stream.Stream = Stream;



// old-style streams.  Note that the pipe method (the only relevant
// part of this class) is overridden in the Readable class.

function Stream() {
  EE.call(this);
}

Stream.prototype.pipe = function(dest, options) {
  var source = this;

  function ondata(chunk) {
    if (dest.writable) {
      if (false === dest.write(chunk) && source.pause) {
        source.pause();
      }
    }
  }

  source.on('data', ondata);

  function ondrain() {
    if (source.readable && source.resume) {
      source.resume();
    }
  }

  dest.on('drain', ondrain);

  // If the 'end' option is not supplied, dest.end() will be called when
  // source gets the 'end' or 'close' events.  Only dest.end() once.
  if (!dest._isStdio && (!options || options.end !== false)) {
    source.on('end', onend);
    source.on('close', onclose);
  }

  var didOnEnd = false;
  function onend() {
    if (didOnEnd) return;
    didOnEnd = true;

    dest.end();
  }


  function onclose() {
    if (didOnEnd) return;
    didOnEnd = true;

    if (typeof dest.destroy === 'function') dest.destroy();
  }

  // don't leave dangling pipes when there are errors.
  function onerror(er) {
    cleanup();
    if (EE.listenerCount(this, 'error') === 0) {
      throw er; // Unhandled stream error in pipe.
    }
  }

  source.on('error', onerror);
  dest.on('error', onerror);

  // remove all the event listeners that were added.
  function cleanup() {
    source.removeListener('data', ondata);
    dest.removeListener('drain', ondrain);

    source.removeListener('end', onend);
    source.removeListener('close', onclose);

    source.removeListener('error', onerror);
    dest.removeListener('error', onerror);

    source.removeListener('end', cleanup);
    source.removeListener('close', cleanup);

    dest.removeListener('close', cleanup);
  }

  source.on('end', cleanup);
  source.on('close', cleanup);

  dest.on('close', cleanup);

  dest.emit('pipe', source);

  // Allow for unix-like usage: A.pipe(B).pipe(C)
  return dest;
};


/***/ }),
/* 45 */
/***/ (function(module, exports) {

module.exports = function(module) {
	if(!module.webpackPolyfill) {
		module.deprecate = function() {};
		module.paths = [];
		// module.parent = undefined by default
		if(!module.children) module.children = [];
		Object.defineProperty(module, "loaded", {
			enumerable: true,
			get: function() {
				return module.l;
			}
		});
		Object.defineProperty(module, "id", {
			enumerable: true,
			get: function() {
				return module.i;
			}
		});
		module.webpackPolyfill = 1;
	}
	return module;
};


/***/ }),
/* 46 */
/***/ (function(module, exports, __webpack_require__) {

/* WEBPACK VAR INJECTION */(function(Buffer, module, global) {/**
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Joshua Gross <josh@swift-nav.com>
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

var Parser = __webpack_require__(13).Parser;
var path = __webpack_require__(43);
var streams = __webpack_require__(44);
var SBP = __webpack_require__(2);

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

function ParameterValidationError (message) {
  this.name = 'ParameterValidationError';
  this.message = message;
  this.stack = (new Error()).stack;
}
ParameterValidationError.prototype = Object.create(Error.prototype);
ParameterValidationError.prototype.constructor = ParameterValidationError;

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
  acquisition: __webpack_require__(23),
  bootload: __webpack_require__(24),
  ext_events: __webpack_require__(25),
  file_io: __webpack_require__(26),
  flash: __webpack_require__(27),
  gnss: __webpack_require__(0),
  imu: __webpack_require__(28),
  logging: __webpack_require__(29),
  mag: __webpack_require__(30),
  navigation: __webpack_require__(31),
  ndb: __webpack_require__(32),
  observation: __webpack_require__(33),
  piksi: __webpack_require__(35),
  settings: __webpack_require__(36),
  signal: __webpack_require__(37),
  ssr: __webpack_require__(38),
  system: __webpack_require__(39),
  tracking: __webpack_require__(40),
  user: __webpack_require__(41),
  vehicle: __webpack_require__(42),
  orientation: __webpack_require__(34)
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
   * @param {Stream} stream - A Readable stream of bytes.
   * @param {function|Array|number} [messageWhitelist]: An optional parameter that will filter
   *   messages. Filtered messages will not be fully decoded, improving performance. Whitelist
   *   can be an array of message types, a numeric mask that will be applied to the message type,
   *   or a function that takes the message type and returns a boolean.
   * @param {function} callback: a callback function invoked when a framed message is found and decoded in the stream.
   * @returns [parsed SBP object, Buffer]
   */
  dispatch: function dispatch (stream, messageWhitelistIn, callbackIn) {
    var offset = 0;
    var streamBuffer = new Buffer(0);

    var callback, messageWhitelist;

    if (typeof callbackIn === 'undefined' && typeof messageWhitelistIn === 'function') {
      callback = messageWhitelistIn;
    } else {
      callback = callbackIn;
      messageWhitelist = messageWhitelistIn;
    }

    if (messageWhitelist && !(Array.isArray(messageWhitelist) || ['function', 'number'].indexOf(typeof messageWhitelist) !== -1)) {
      throw ParameterValidationError('dispatch: messageWhitelist must be function, number, or array');
    }

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

      // Don't continue if message isn't whitelisted...
      var whitelistedArray = messageWhitelist && Array.isArray(messageWhitelist) && messageWhitelist.indexOf(msgType) !== -1;
      var whitelistedMask = messageWhitelist && typeof messageWhitelist === 'number' && (messageWhitelist & msgType);
      var whitelistedFn = messageWhitelist && typeof messageWhitelist === 'function' && messageWhitelist(msgType);
      if (messageWhitelist && !(whitelistedArray || whitelistedMask || whitelistedFn)) {
        streamBuffer = streamBuffer.slice(preamblePos+6+length+2);
        return null;
      }

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

        // pair may have been filtered and not fully decoded
        if (pair === null) {
          return;
        }

        var framedMessage = pair[0];
        var fullBuffer = pair[1];

        callback(null, framedMessage, fullBuffer);
      } catch (e) {
        if (!(e instanceof BufferTooShortError || e instanceof BufferCorruptError)) {
          throw e;
        }
      } finally {
        offset = 0;
        stream.resume();

        // If there's more in the stream, try again immediately
        if (streamBuffer.length > 0) {
          setTimeout(function () {
            processData(new Buffer(0));
          }, 0);
        }
      }
    };

    stream.on('data', processData);
  }
};

/**
 * For frontend code: expose SBP object in a global context.
 * This is a noop in a non-browser context.
 *
 * Cribbed from Benchmark.js (MIT Licensed).
 */
function exposeGlobally (x) {
  var objectTypes = { 'function': true, 'object': true };
  var root = (objectTypes[typeof window] && window) || this;
  var freeExports = objectTypes[typeof exports] && exports && !exports.nodeType && exports;
  var freeModule = objectTypes[typeof module] && module && !module.nodeType && module;
  var freeGlobal = freeExports && freeModule && typeof global == 'object' && global;
  if (freeGlobal && (freeGlobal.global === freeGlobal || freeGlobal.window === freeGlobal || freeGlobal.self === freeGlobal)) {
    root = freeGlobal;
  }
  root.SBP = x;
}

exposeGlobally(module.exports);

/* WEBPACK VAR INJECTION */}.call(exports, __webpack_require__(7).Buffer, __webpack_require__(45)(module), __webpack_require__(5)))

/***/ }),
/* 47 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
/* WEBPACK VAR INJECTION */(function(global) {

// compare and isBuffer taken from https://github.com/feross/buffer/blob/680e9e5e488f22aac27599a57dc844a6315928dd/index.js
// original notice:

/*!
 * The buffer module from node.js, for the browser.
 *
 * @author   Feross Aboukhadijeh <feross@feross.org> <http://feross.org>
 * @license  MIT
 */
function compare(a, b) {
  if (a === b) {
    return 0;
  }

  var x = a.length;
  var y = b.length;

  for (var i = 0, len = Math.min(x, y); i < len; ++i) {
    if (a[i] !== b[i]) {
      x = a[i];
      y = b[i];
      break;
    }
  }

  if (x < y) {
    return -1;
  }
  if (y < x) {
    return 1;
  }
  return 0;
}
function isBuffer(b) {
  if (global.Buffer && typeof global.Buffer.isBuffer === 'function') {
    return global.Buffer.isBuffer(b);
  }
  return !!(b != null && b._isBuffer);
}

// based on node assert, original notice:

// http://wiki.commonjs.org/wiki/Unit_Testing/1.0
//
// THIS IS NOT TESTED NOR LIKELY TO WORK OUTSIDE V8!
//
// Originally from narwhal.js (http://narwhaljs.org)
// Copyright (c) 2009 Thomas Robinson <280north.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the 'Software'), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

var util = __webpack_require__(64);
var hasOwn = Object.prototype.hasOwnProperty;
var pSlice = Array.prototype.slice;
var functionsHaveNames = (function () {
  return function foo() {}.name === 'foo';
}());
function pToString (obj) {
  return Object.prototype.toString.call(obj);
}
function isView(arrbuf) {
  if (isBuffer(arrbuf)) {
    return false;
  }
  if (typeof global.ArrayBuffer !== 'function') {
    return false;
  }
  if (typeof ArrayBuffer.isView === 'function') {
    return ArrayBuffer.isView(arrbuf);
  }
  if (!arrbuf) {
    return false;
  }
  if (arrbuf instanceof DataView) {
    return true;
  }
  if (arrbuf.buffer && arrbuf.buffer instanceof ArrayBuffer) {
    return true;
  }
  return false;
}
// 1. The assert module provides functions that throw
// AssertionError's when particular conditions are not met. The
// assert module must conform to the following interface.

var assert = module.exports = ok;

// 2. The AssertionError is defined in assert.
// new assert.AssertionError({ message: message,
//                             actual: actual,
//                             expected: expected })

var regex = /\s*function\s+([^\(\s]*)\s*/;
// based on https://github.com/ljharb/function.prototype.name/blob/adeeeec8bfcc6068b187d7d9fb3d5bb1d3a30899/implementation.js
function getName(func) {
  if (!util.isFunction(func)) {
    return;
  }
  if (functionsHaveNames) {
    return func.name;
  }
  var str = func.toString();
  var match = str.match(regex);
  return match && match[1];
}
assert.AssertionError = function AssertionError(options) {
  this.name = 'AssertionError';
  this.actual = options.actual;
  this.expected = options.expected;
  this.operator = options.operator;
  if (options.message) {
    this.message = options.message;
    this.generatedMessage = false;
  } else {
    this.message = getMessage(this);
    this.generatedMessage = true;
  }
  var stackStartFunction = options.stackStartFunction || fail;
  if (Error.captureStackTrace) {
    Error.captureStackTrace(this, stackStartFunction);
  } else {
    // non v8 browsers so we can have a stacktrace
    var err = new Error();
    if (err.stack) {
      var out = err.stack;

      // try to strip useless frames
      var fn_name = getName(stackStartFunction);
      var idx = out.indexOf('\n' + fn_name);
      if (idx >= 0) {
        // once we have located the function frame
        // we need to strip out everything before it (and its line)
        var next_line = out.indexOf('\n', idx + 1);
        out = out.substring(next_line + 1);
      }

      this.stack = out;
    }
  }
};

// assert.AssertionError instanceof Error
util.inherits(assert.AssertionError, Error);

function truncate(s, n) {
  if (typeof s === 'string') {
    return s.length < n ? s : s.slice(0, n);
  } else {
    return s;
  }
}
function inspect(something) {
  if (functionsHaveNames || !util.isFunction(something)) {
    return util.inspect(something);
  }
  var rawname = getName(something);
  var name = rawname ? ': ' + rawname : '';
  return '[Function' +  name + ']';
}
function getMessage(self) {
  return truncate(inspect(self.actual), 128) + ' ' +
         self.operator + ' ' +
         truncate(inspect(self.expected), 128);
}

// At present only the three keys mentioned above are used and
// understood by the spec. Implementations or sub modules can pass
// other keys to the AssertionError's constructor - they will be
// ignored.

// 3. All of the following functions must throw an AssertionError
// when a corresponding condition is not met, with a message that
// may be undefined if not provided.  All assertion methods provide
// both the actual and expected values to the assertion error for
// display purposes.

function fail(actual, expected, message, operator, stackStartFunction) {
  throw new assert.AssertionError({
    message: message,
    actual: actual,
    expected: expected,
    operator: operator,
    stackStartFunction: stackStartFunction
  });
}

// EXTENSION! allows for well behaved errors defined elsewhere.
assert.fail = fail;

// 4. Pure assertion tests whether a value is truthy, as determined
// by !!guard.
// assert.ok(guard, message_opt);
// This statement is equivalent to assert.equal(true, !!guard,
// message_opt);. To test strictly for the value true, use
// assert.strictEqual(true, guard, message_opt);.

function ok(value, message) {
  if (!value) fail(value, true, message, '==', assert.ok);
}
assert.ok = ok;

// 5. The equality assertion tests shallow, coercive equality with
// ==.
// assert.equal(actual, expected, message_opt);

assert.equal = function equal(actual, expected, message) {
  if (actual != expected) fail(actual, expected, message, '==', assert.equal);
};

// 6. The non-equality assertion tests for whether two objects are not equal
// with != assert.notEqual(actual, expected, message_opt);

assert.notEqual = function notEqual(actual, expected, message) {
  if (actual == expected) {
    fail(actual, expected, message, '!=', assert.notEqual);
  }
};

// 7. The equivalence assertion tests a deep equality relation.
// assert.deepEqual(actual, expected, message_opt);

assert.deepEqual = function deepEqual(actual, expected, message) {
  if (!_deepEqual(actual, expected, false)) {
    fail(actual, expected, message, 'deepEqual', assert.deepEqual);
  }
};

assert.deepStrictEqual = function deepStrictEqual(actual, expected, message) {
  if (!_deepEqual(actual, expected, true)) {
    fail(actual, expected, message, 'deepStrictEqual', assert.deepStrictEqual);
  }
};

function _deepEqual(actual, expected, strict, memos) {
  // 7.1. All identical values are equivalent, as determined by ===.
  if (actual === expected) {
    return true;
  } else if (isBuffer(actual) && isBuffer(expected)) {
    return compare(actual, expected) === 0;

  // 7.2. If the expected value is a Date object, the actual value is
  // equivalent if it is also a Date object that refers to the same time.
  } else if (util.isDate(actual) && util.isDate(expected)) {
    return actual.getTime() === expected.getTime();

  // 7.3 If the expected value is a RegExp object, the actual value is
  // equivalent if it is also a RegExp object with the same source and
  // properties (`global`, `multiline`, `lastIndex`, `ignoreCase`).
  } else if (util.isRegExp(actual) && util.isRegExp(expected)) {
    return actual.source === expected.source &&
           actual.global === expected.global &&
           actual.multiline === expected.multiline &&
           actual.lastIndex === expected.lastIndex &&
           actual.ignoreCase === expected.ignoreCase;

  // 7.4. Other pairs that do not both pass typeof value == 'object',
  // equivalence is determined by ==.
  } else if ((actual === null || typeof actual !== 'object') &&
             (expected === null || typeof expected !== 'object')) {
    return strict ? actual === expected : actual == expected;

  // If both values are instances of typed arrays, wrap their underlying
  // ArrayBuffers in a Buffer each to increase performance
  // This optimization requires the arrays to have the same type as checked by
  // Object.prototype.toString (aka pToString). Never perform binary
  // comparisons for Float*Arrays, though, since e.g. +0 === -0 but their
  // bit patterns are not identical.
  } else if (isView(actual) && isView(expected) &&
             pToString(actual) === pToString(expected) &&
             !(actual instanceof Float32Array ||
               actual instanceof Float64Array)) {
    return compare(new Uint8Array(actual.buffer),
                   new Uint8Array(expected.buffer)) === 0;

  // 7.5 For all other Object pairs, including Array objects, equivalence is
  // determined by having the same number of owned properties (as verified
  // with Object.prototype.hasOwnProperty.call), the same set of keys
  // (although not necessarily the same order), equivalent values for every
  // corresponding key, and an identical 'prototype' property. Note: this
  // accounts for both named and indexed properties on Arrays.
  } else if (isBuffer(actual) !== isBuffer(expected)) {
    return false;
  } else {
    memos = memos || {actual: [], expected: []};

    var actualIndex = memos.actual.indexOf(actual);
    if (actualIndex !== -1) {
      if (actualIndex === memos.expected.indexOf(expected)) {
        return true;
      }
    }

    memos.actual.push(actual);
    memos.expected.push(expected);

    return objEquiv(actual, expected, strict, memos);
  }
}

function isArguments(object) {
  return Object.prototype.toString.call(object) == '[object Arguments]';
}

function objEquiv(a, b, strict, actualVisitedObjects) {
  if (a === null || a === undefined || b === null || b === undefined)
    return false;
  // if one is a primitive, the other must be same
  if (util.isPrimitive(a) || util.isPrimitive(b))
    return a === b;
  if (strict && Object.getPrototypeOf(a) !== Object.getPrototypeOf(b))
    return false;
  var aIsArgs = isArguments(a);
  var bIsArgs = isArguments(b);
  if ((aIsArgs && !bIsArgs) || (!aIsArgs && bIsArgs))
    return false;
  if (aIsArgs) {
    a = pSlice.call(a);
    b = pSlice.call(b);
    return _deepEqual(a, b, strict);
  }
  var ka = objectKeys(a);
  var kb = objectKeys(b);
  var key, i;
  // having the same number of owned properties (keys incorporates
  // hasOwnProperty)
  if (ka.length !== kb.length)
    return false;
  //the same set of keys (although not necessarily the same order),
  ka.sort();
  kb.sort();
  //~~~cheap key test
  for (i = ka.length - 1; i >= 0; i--) {
    if (ka[i] !== kb[i])
      return false;
  }
  //equivalent values for every corresponding key, and
  //~~~possibly expensive deep test
  for (i = ka.length - 1; i >= 0; i--) {
    key = ka[i];
    if (!_deepEqual(a[key], b[key], strict, actualVisitedObjects))
      return false;
  }
  return true;
}

// 8. The non-equivalence assertion tests for any deep inequality.
// assert.notDeepEqual(actual, expected, message_opt);

assert.notDeepEqual = function notDeepEqual(actual, expected, message) {
  if (_deepEqual(actual, expected, false)) {
    fail(actual, expected, message, 'notDeepEqual', assert.notDeepEqual);
  }
};

assert.notDeepStrictEqual = notDeepStrictEqual;
function notDeepStrictEqual(actual, expected, message) {
  if (_deepEqual(actual, expected, true)) {
    fail(actual, expected, message, 'notDeepStrictEqual', notDeepStrictEqual);
  }
}


// 9. The strict equality assertion tests strict equality, as determined by ===.
// assert.strictEqual(actual, expected, message_opt);

assert.strictEqual = function strictEqual(actual, expected, message) {
  if (actual !== expected) {
    fail(actual, expected, message, '===', assert.strictEqual);
  }
};

// 10. The strict non-equality assertion tests for strict inequality, as
// determined by !==.  assert.notStrictEqual(actual, expected, message_opt);

assert.notStrictEqual = function notStrictEqual(actual, expected, message) {
  if (actual === expected) {
    fail(actual, expected, message, '!==', assert.notStrictEqual);
  }
};

function expectedException(actual, expected) {
  if (!actual || !expected) {
    return false;
  }

  if (Object.prototype.toString.call(expected) == '[object RegExp]') {
    return expected.test(actual);
  }

  try {
    if (actual instanceof expected) {
      return true;
    }
  } catch (e) {
    // Ignore.  The instanceof check doesn't work for arrow functions.
  }

  if (Error.isPrototypeOf(expected)) {
    return false;
  }

  return expected.call({}, actual) === true;
}

function _tryBlock(block) {
  var error;
  try {
    block();
  } catch (e) {
    error = e;
  }
  return error;
}

function _throws(shouldThrow, block, expected, message) {
  var actual;

  if (typeof block !== 'function') {
    throw new TypeError('"block" argument must be a function');
  }

  if (typeof expected === 'string') {
    message = expected;
    expected = null;
  }

  actual = _tryBlock(block);

  message = (expected && expected.name ? ' (' + expected.name + ').' : '.') +
            (message ? ' ' + message : '.');

  if (shouldThrow && !actual) {
    fail(actual, expected, 'Missing expected exception' + message);
  }

  var userProvidedMessage = typeof message === 'string';
  var isUnwantedException = !shouldThrow && util.isError(actual);
  var isUnexpectedException = !shouldThrow && actual && !expected;

  if ((isUnwantedException &&
      userProvidedMessage &&
      expectedException(actual, expected)) ||
      isUnexpectedException) {
    fail(actual, expected, 'Got unwanted exception' + message);
  }

  if ((shouldThrow && actual && expected &&
      !expectedException(actual, expected)) || (!shouldThrow && actual)) {
    throw actual;
  }
}

// 11. Expected to throw an error:
// assert.throws(block, Error_opt, message_opt);

assert.throws = function(block, /*optional*/error, /*optional*/message) {
  _throws(true, block, error, message);
};

// EXTENSION! This is annoying to write outside this module.
assert.doesNotThrow = function(block, /*optional*/error, /*optional*/message) {
  _throws(false, block, error, message);
};

assert.ifError = function(err) { if (err) throw err; };

var objectKeys = Object.keys || function (obj) {
  var keys = [];
  for (var key in obj) {
    if (hasOwn.call(obj, key)) keys.push(key);
  }
  return keys;
};

/* WEBPACK VAR INJECTION */}.call(exports, __webpack_require__(5)))

/***/ }),
/* 48 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


exports.byteLength = byteLength
exports.toByteArray = toByteArray
exports.fromByteArray = fromByteArray

var lookup = []
var revLookup = []
var Arr = typeof Uint8Array !== 'undefined' ? Uint8Array : Array

var code = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/'
for (var i = 0, len = code.length; i < len; ++i) {
  lookup[i] = code[i]
  revLookup[code.charCodeAt(i)] = i
}

// Support decoding URL-safe base64 strings, as Node.js does.
// See: https://en.wikipedia.org/wiki/Base64#URL_applications
revLookup['-'.charCodeAt(0)] = 62
revLookup['_'.charCodeAt(0)] = 63

function getLens (b64) {
  var len = b64.length

  if (len % 4 > 0) {
    throw new Error('Invalid string. Length must be a multiple of 4')
  }

  // Trim off extra bytes after placeholder bytes are found
  // See: https://github.com/beatgammit/base64-js/issues/42
  var validLen = b64.indexOf('=')
  if (validLen === -1) validLen = len

  var placeHoldersLen = validLen === len
    ? 0
    : 4 - (validLen % 4)

  return [validLen, placeHoldersLen]
}

// base64 is 4/3 + up to two characters of the original data
function byteLength (b64) {
  var lens = getLens(b64)
  var validLen = lens[0]
  var placeHoldersLen = lens[1]
  return ((validLen + placeHoldersLen) * 3 / 4) - placeHoldersLen
}

function _byteLength (b64, validLen, placeHoldersLen) {
  return ((validLen + placeHoldersLen) * 3 / 4) - placeHoldersLen
}

function toByteArray (b64) {
  var tmp
  var lens = getLens(b64)
  var validLen = lens[0]
  var placeHoldersLen = lens[1]

  var arr = new Arr(_byteLength(b64, validLen, placeHoldersLen))

  var curByte = 0

  // if there are placeholders, only get up to the last complete 4 chars
  var len = placeHoldersLen > 0
    ? validLen - 4
    : validLen

  for (var i = 0; i < len; i += 4) {
    tmp =
      (revLookup[b64.charCodeAt(i)] << 18) |
      (revLookup[b64.charCodeAt(i + 1)] << 12) |
      (revLookup[b64.charCodeAt(i + 2)] << 6) |
      revLookup[b64.charCodeAt(i + 3)]
    arr[curByte++] = (tmp >> 16) & 0xFF
    arr[curByte++] = (tmp >> 8) & 0xFF
    arr[curByte++] = tmp & 0xFF
  }

  if (placeHoldersLen === 2) {
    tmp =
      (revLookup[b64.charCodeAt(i)] << 2) |
      (revLookup[b64.charCodeAt(i + 1)] >> 4)
    arr[curByte++] = tmp & 0xFF
  }

  if (placeHoldersLen === 1) {
    tmp =
      (revLookup[b64.charCodeAt(i)] << 10) |
      (revLookup[b64.charCodeAt(i + 1)] << 4) |
      (revLookup[b64.charCodeAt(i + 2)] >> 2)
    arr[curByte++] = (tmp >> 8) & 0xFF
    arr[curByte++] = tmp & 0xFF
  }

  return arr
}

function tripletToBase64 (num) {
  return lookup[num >> 18 & 0x3F] +
    lookup[num >> 12 & 0x3F] +
    lookup[num >> 6 & 0x3F] +
    lookup[num & 0x3F]
}

function encodeChunk (uint8, start, end) {
  var tmp
  var output = []
  for (var i = start; i < end; i += 3) {
    tmp =
      ((uint8[i] << 16) & 0xFF0000) +
      ((uint8[i + 1] << 8) & 0xFF00) +
      (uint8[i + 2] & 0xFF)
    output.push(tripletToBase64(tmp))
  }
  return output.join('')
}

function fromByteArray (uint8) {
  var tmp
  var len = uint8.length
  var extraBytes = len % 3 // if we have 1 byte left, pad 2 bytes
  var parts = []
  var maxChunkLength = 16383 // must be multiple of 3

  // go through the array every three bytes, we'll deal with trailing stuff later
  for (var i = 0, len2 = len - extraBytes; i < len2; i += maxChunkLength) {
    parts.push(encodeChunk(
      uint8, i, (i + maxChunkLength) > len2 ? len2 : (i + maxChunkLength)
    ))
  }

  // pad the end with zeros, but make sure to not forget the extra bytes
  if (extraBytes === 1) {
    tmp = uint8[len - 1]
    parts.push(
      lookup[tmp >> 2] +
      lookup[(tmp << 4) & 0x3F] +
      '=='
    )
  } else if (extraBytes === 2) {
    tmp = (uint8[len - 2] << 8) + uint8[len - 1]
    parts.push(
      lookup[tmp >> 10] +
      lookup[(tmp >> 4) & 0x3F] +
      lookup[(tmp << 2) & 0x3F] +
      '='
    )
  }

  return parts.join('')
}


/***/ }),
/* 49 */
/***/ (function(module, exports) {

//========================================================================================
// class Context
//========================================================================================

//----------------------------------------------------------------------------------------
// constructor
//----------------------------------------------------------------------------------------

var Context = function() {
    this.code = '';
    this.scopes = [['vars']];
    this.isAsync = false;
    this.bitFields = [];
    this.tmpVariableCount = 0;
};

//----------------------------------------------------------------------------------------
// public methods
//----------------------------------------------------------------------------------------

Context.prototype.generateVariable = function(name) {
    var arr = [];

    Array.prototype.push.apply(arr, this.scopes[this.scopes.length - 1]);
    if (name) {
        arr.push(name);
    }

    return arr.join('.');
};

Context.prototype.generateOption = function(val) {
    switch(typeof val) {
        case 'number':
            return val.toString();
        case 'string':
            return this.generateVariable(val);
        case 'function':
            return '(' + val + ').call(' + this.generateVariable() + ')';
    }
};

Context.prototype.generateError = function() {
    var args = Array.prototype.slice.call(arguments);
    var err = Context.interpolate.apply(this, args);

    if (this.isAsync) {
        this.pushCode('return process.nextTick(function() { callback(new Error(' + err + '), vars); });');
    } else {
        this.pushCode('throw new Error(' + err + ');');
    }
};

Context.prototype.generateTmpVariable = function() {
    return '$tmp' + (this.tmpVariableCount++);
};

Context.prototype.pushCode = function() {
    var args = Array.prototype.slice.call(arguments);
 
    this.code += Context.interpolate.apply(this, args) + '\n';
};

Context.prototype.pushPath = function(name) {
    this.scopes[this.scopes.length - 1].push(name);
};

Context.prototype.popPath = function() {
    this.scopes[this.scopes.length - 1].pop();
};

Context.prototype.pushScope = function(name) {
    this.scopes.push([name]);
};

Context.prototype.popScope = function() {
    this.scopes.pop();
};

//----------------------------------------------------------------------------------------
// private methods
//----------------------------------------------------------------------------------------

Context.interpolate = function(s) {
    var re = /{\d+}/g;
    var matches = s.match(re);
    var params = Array.prototype.slice.call(arguments, 1);

    if (matches) {
        matches.forEach(function(match) {
            var index = parseInt(match.substr(1, match.length - 2), 10);
            s = s.replace(match, params[index].toString());
        });
    }

    return s;
};

exports.Context = Context;


/***/ }),
/* 50 */
/***/ (function(module, exports, __webpack_require__) {

var __WEBPACK_AMD_DEFINE_ARRAY__, __WEBPACK_AMD_DEFINE_RESULT__;/**
	C-like unsigned 32 bits integers in Javascript
	Copyright (C) 2013, Pierre Curto
	MIT license
 */
;(function (root) {

	// Local cache for typical radices
	var radixPowerCache = {
		36: UINT32( Math.pow(36, 5) )
	,	16: UINT32( Math.pow(16, 7) )
	,	10: UINT32( Math.pow(10, 9) )
	,	2:  UINT32( Math.pow(2, 30) )
	}
	var radixCache = {
		36: UINT32(36)
	,	16: UINT32(16)
	,	10: UINT32(10)
	,	2:  UINT32(2)
	}

	/**
	 *	Represents an unsigned 32 bits integer
	 * @constructor
	 * @param {Number|String|Number} low bits     | integer as a string 		 | integer as a number
	 * @param {Number|Number|Undefined} high bits | radix (optional, default=10)
	 * @return 
	 */
	function UINT32 (l, h) {
		if ( !(this instanceof UINT32) )
			return new UINT32(l, h)

		this._low = 0
		this._high = 0
		this.remainder = null
		if (typeof h == 'undefined')
			return fromNumber.call(this, l)

		if (typeof l == 'string')
			return fromString.call(this, l, h)

		fromBits.call(this, l, h)
	}

	/**
	 * Set the current _UINT32_ object with its low and high bits
	 * @method fromBits
	 * @param {Number} low bits
	 * @param {Number} high bits
	 * @return ThisExpression
	 */
	function fromBits (l, h) {
		this._low = l | 0
		this._high = h | 0

		return this
	}
	UINT32.prototype.fromBits = fromBits

	/**
	 * Set the current _UINT32_ object from a number
	 * @method fromNumber
	 * @param {Number} number
	 * @return ThisExpression
	 */
	function fromNumber (value) {
		this._low = value & 0xFFFF
		this._high = value >>> 16

		return this
	}
	UINT32.prototype.fromNumber = fromNumber

	/**
	 * Set the current _UINT32_ object from a string
	 * @method fromString
	 * @param {String} integer as a string
	 * @param {Number} radix (optional, default=10)
	 * @return ThisExpression
	 */
	function fromString (s, radix) {
		var value = parseInt(s, radix || 10)

		this._low = value & 0xFFFF
		this._high = value >>> 16

		return this
	}
	UINT32.prototype.fromString = fromString

	/**
	 * Convert this _UINT32_ to a number
	 * @method toNumber
	 * @return {Number} the converted UINT32
	 */
	UINT32.prototype.toNumber = function () {
		return (this._high * 65536) + this._low
	}

	/**
	 * Convert this _UINT32_ to a string
	 * @method toString
	 * @param {Number} radix (optional, default=10)
	 * @return {String} the converted UINT32
	 */
	UINT32.prototype.toString = function (radix) {
		return this.toNumber().toString(radix || 10)
	}

	/**
	 * Add two _UINT32_. The current _UINT32_ stores the result
	 * @method add
	 * @param {Object} other UINT32
	 * @return ThisExpression
	 */
	UINT32.prototype.add = function (other) {
		var a00 = this._low + other._low
		var a16 = a00 >>> 16

		a16 += this._high + other._high

		this._low = a00 & 0xFFFF
		this._high = a16 & 0xFFFF

		return this
	}

	/**
	 * Subtract two _UINT32_. The current _UINT32_ stores the result
	 * @method subtract
	 * @param {Object} other UINT32
	 * @return ThisExpression
	 */
	UINT32.prototype.subtract = function (other) {
		//TODO inline
		return this.add( other.clone().negate() )
	}

	/**
	 * Multiply two _UINT32_. The current _UINT32_ stores the result
	 * @method multiply
	 * @param {Object} other UINT32
	 * @return ThisExpression
	 */
	UINT32.prototype.multiply = function (other) {
		/*
			a = a00 + a16
			b = b00 + b16
			a*b = (a00 + a16)(b00 + b16)
				= a00b00 + a00b16 + a16b00 + a16b16

			a16b16 overflows the 32bits
		 */
		var a16 = this._high
		var a00 = this._low
		var b16 = other._high
		var b00 = other._low

/* Removed to increase speed under normal circumstances (i.e. not multiplying by 0 or 1)
		// this == 0 or other == 1: nothing to do
		if ((a00 == 0 && a16 == 0) || (b00 == 1 && b16 == 0)) return this

		// other == 0 or this == 1: this = other
		if ((b00 == 0 && b16 == 0) || (a00 == 1 && a16 == 0)) {
			this._low = other._low
			this._high = other._high
			return this
		}
*/

		var c16, c00
		c00 = a00 * b00
		c16 = c00 >>> 16

		c16 += a16 * b00
		c16 &= 0xFFFF		// Not required but improves performance
		c16 += a00 * b16

		this._low = c00 & 0xFFFF
		this._high = c16 & 0xFFFF

		return this
	}

	/**
	 * Divide two _UINT32_. The current _UINT32_ stores the result.
	 * The remainder is made available as the _remainder_ property on
	 * the _UINT32_ object. It can be null, meaning there are no remainder.
	 * @method div
	 * @param {Object} other UINT32
	 * @return ThisExpression
	 */
	UINT32.prototype.div = function (other) {
		if ( (other._low == 0) && (other._high == 0) ) throw Error('division by zero')

		// other == 1
		if (other._high == 0 && other._low == 1) {
			this.remainder = new UINT32(0)
			return this
		}

		// other > this: 0
		if ( other.gt(this) ) {
			this.remainder = this.clone()
			this._low = 0
			this._high = 0
			return this
		}
		// other == this: 1
		if ( this.eq(other) ) {
			this.remainder = new UINT32(0)
			this._low = 1
			this._high = 0
			return this
		}

		// Shift the divisor left until it is higher than the dividend
		var _other = other.clone()
		var i = -1
		while ( !this.lt(_other) ) {
			// High bit can overflow the default 16bits
			// Its ok since we right shift after this loop
			// The overflown bit must be kept though
			_other.shiftLeft(1, true)
			i++
		}

		// Set the remainder
		this.remainder = this.clone()
		// Initialize the current result to 0
		this._low = 0
		this._high = 0
		for (; i >= 0; i--) {
			_other.shiftRight(1)
			// If shifted divisor is smaller than the dividend
			// then subtract it from the dividend
			if ( !this.remainder.lt(_other) ) {
				this.remainder.subtract(_other)
				// Update the current result
				if (i >= 16) {
					this._high |= 1 << (i - 16)
				} else {
					this._low |= 1 << i
				}
			}
		}

		return this
	}

	/**
	 * Negate the current _UINT32_
	 * @method negate
	 * @return ThisExpression
	 */
	UINT32.prototype.negate = function () {
		var v = ( ~this._low & 0xFFFF ) + 1
		this._low = v & 0xFFFF
		this._high = (~this._high + (v >>> 16)) & 0xFFFF

		return this
	}

	/**
	 * Equals
	 * @method eq
	 * @param {Object} other UINT32
	 * @return {Boolean}
	 */
	UINT32.prototype.equals = UINT32.prototype.eq = function (other) {
		return (this._low == other._low) && (this._high == other._high)
	}

	/**
	 * Greater than (strict)
	 * @method gt
	 * @param {Object} other UINT32
	 * @return {Boolean}
	 */
	UINT32.prototype.greaterThan = UINT32.prototype.gt = function (other) {
		if (this._high > other._high) return true
		if (this._high < other._high) return false
		return this._low > other._low
	}

	/**
	 * Less than (strict)
	 * @method lt
	 * @param {Object} other UINT32
	 * @return {Boolean}
	 */
	UINT32.prototype.lessThan = UINT32.prototype.lt = function (other) {
		if (this._high < other._high) return true
		if (this._high > other._high) return false
		return this._low < other._low
	}

	/**
	 * Bitwise OR
	 * @method or
	 * @param {Object} other UINT32
	 * @return ThisExpression
	 */
	UINT32.prototype.or = function (other) {
		this._low |= other._low
		this._high |= other._high

		return this
	}

	/**
	 * Bitwise AND
	 * @method and
	 * @param {Object} other UINT32
	 * @return ThisExpression
	 */
	UINT32.prototype.and = function (other) {
		this._low &= other._low
		this._high &= other._high

		return this
	}

	/**
	 * Bitwise NOT
	 * @method not
	 * @return ThisExpression
	 */
	UINT32.prototype.not = function() {
		this._low = ~this._low & 0xFFFF
		this._high = ~this._high & 0xFFFF

		return this
	}

	/**
	 * Bitwise XOR
	 * @method xor
	 * @param {Object} other UINT32
	 * @return ThisExpression
	 */
	UINT32.prototype.xor = function (other) {
		this._low ^= other._low
		this._high ^= other._high

		return this
	}

	/**
	 * Bitwise shift right
	 * @method shiftRight
	 * @param {Number} number of bits to shift
	 * @return ThisExpression
	 */
	UINT32.prototype.shiftRight = UINT32.prototype.shiftr = function (n) {
		if (n > 16) {
			this._low = this._high >> (n - 16)
			this._high = 0
		} else if (n == 16) {
			this._low = this._high
			this._high = 0
		} else {
			this._low = (this._low >> n) | ( (this._high << (16-n)) & 0xFFFF )
			this._high >>= n
		}

		return this
	}

	/**
	 * Bitwise shift left
	 * @method shiftLeft
	 * @param {Number} number of bits to shift
	 * @param {Boolean} allow overflow
	 * @return ThisExpression
	 */
	UINT32.prototype.shiftLeft = UINT32.prototype.shiftl = function (n, allowOverflow) {
		if (n > 16) {
			this._high = this._low << (n - 16)
			this._low = 0
			if (!allowOverflow) {
				this._high &= 0xFFFF
			}
		} else if (n == 16) {
			this._high = this._low
			this._low = 0
		} else {
			this._high = (this._high << n) | (this._low >> (16-n))
			this._low = (this._low << n) & 0xFFFF
			if (!allowOverflow) {
				// Overflow only allowed on the high bits...
				this._high &= 0xFFFF
			}
		}

		return this
	}

	/**
	 * Bitwise rotate left
	 * @method rotl
	 * @param {Number} number of bits to rotate
	 * @return ThisExpression
	 */
	UINT32.prototype.rotateLeft = UINT32.prototype.rotl = function (n) {
		var v = (this._high << 16) | this._low
		v = (v << n) | (v >>> (32 - n))
		this._low = v & 0xFFFF
		this._high = v >>> 16

		return this
	}

	/**
	 * Bitwise rotate right
	 * @method rotr
	 * @param {Number} number of bits to rotate
	 * @return ThisExpression
	 */
	UINT32.prototype.rotateRight = UINT32.prototype.rotr = function (n) {
		var v = (this._high << 16) | this._low
		v = (v >>> n) | (v << (32 - n))
		this._low = v & 0xFFFF
		this._high = v >>> 16

		return this
	}

	/**
	 * Clone the current _UINT32_
	 * @method clone
	 * @return {Object} cloned UINT32
	 */
	UINT32.prototype.clone = function () {
		return new UINT32(this._low, this._high)
	}

	if (true) {
		// AMD / RequireJS
		!(__WEBPACK_AMD_DEFINE_ARRAY__ = [], __WEBPACK_AMD_DEFINE_RESULT__ = function () {
			return UINT32
		}.apply(exports, __WEBPACK_AMD_DEFINE_ARRAY__),
				__WEBPACK_AMD_DEFINE_RESULT__ !== undefined && (module.exports = __WEBPACK_AMD_DEFINE_RESULT__))
	} else if (typeof module != 'undefined' && module.exports) {
		// Node.js
		module.exports = UINT32
	} else {
		// Browser
		root['UINT32'] = UINT32
	}

})(this)


/***/ }),
/* 51 */
/***/ (function(module, exports, __webpack_require__) {

var __WEBPACK_AMD_DEFINE_ARRAY__, __WEBPACK_AMD_DEFINE_RESULT__;/**
	C-like unsigned 64 bits integers in Javascript
	Copyright (C) 2013, Pierre Curto
	MIT license
 */
;(function (root) {

	// Local cache for typical radices
	var radixPowerCache = {
		16: UINT64( Math.pow(16, 5) )
	,	10: UINT64( Math.pow(10, 5) )
	,	2:  UINT64( Math.pow(2, 5) )
	}
	var radixCache = {
		16: UINT64(16)
	,	10: UINT64(10)
	,	2:  UINT64(2)
	}

	/**
	 *	Represents an unsigned 64 bits integer
	 * @constructor
	 * @param {Number} first low bits (8)
	 * @param {Number} second low bits (8)
	 * @param {Number} first high bits (8)
	 * @param {Number} second high bits (8)
	 * or
	 * @param {Number} low bits (32)
	 * @param {Number} high bits (32)
	 * or
	 * @param {String|Number} integer as a string 		 | integer as a number
	 * @param {Number|Undefined} radix (optional, default=10)
	 * @return 
	 */
	function UINT64 (a00, a16, a32, a48) {
		if ( !(this instanceof UINT64) )
			return new UINT64(a00, a16, a32, a48)

		this.remainder = null
		if (typeof a00 == 'string')
			return fromString.call(this, a00, a16)

		if (typeof a16 == 'undefined')
			return fromNumber.call(this, a00)

		fromBits.apply(this, arguments)
	}

	/**
	 * Set the current _UINT64_ object with its low and high bits
	 * @method fromBits
	 * @param {Number} first low bits (8)
	 * @param {Number} second low bits (8)
	 * @param {Number} first high bits (8)
	 * @param {Number} second high bits (8)
	 * or
	 * @param {Number} low bits (32)
	 * @param {Number} high bits (32)
	 * @return ThisExpression
	 */
	function fromBits (a00, a16, a32, a48) {
		if (typeof a32 == 'undefined') {
			this._a00 = a00 & 0xFFFF
			this._a16 = a00 >>> 16
			this._a32 = a16 & 0xFFFF
			this._a48 = a16 >>> 16
			return this
		}

		this._a00 = a00 | 0
		this._a16 = a16 | 0
		this._a32 = a32 | 0
		this._a48 = a48 | 0

		return this
	}
	UINT64.prototype.fromBits = fromBits

	/**
	 * Set the current _UINT64_ object from a number
	 * @method fromNumber
	 * @param {Number} number
	 * @return ThisExpression
	 */
	function fromNumber (value) {
		this._a00 = value & 0xFFFF
		this._a16 = value >>> 16
		this._a32 = 0
		this._a48 = 0

		return this
	}
	UINT64.prototype.fromNumber = fromNumber

	/**
	 * Set the current _UINT64_ object from a string
	 * @method fromString
	 * @param {String} integer as a string
	 * @param {Number} radix (optional, default=10)
	 * @return ThisExpression
	 */
	function fromString (s, radix) {
		radix = radix || 10

		this._a00 = 0
		this._a16 = 0
		this._a32 = 0
		this._a48 = 0

		/*
			In Javascript, bitwise operators only operate on the first 32 bits 
			of a number, even though parseInt() encodes numbers with a 53 bits 
			mantissa.
			Therefore UINT64(<Number>) can only work on 32 bits.
			The radix maximum value is 36 (as per ECMA specs) (26 letters + 10 digits)
			maximum input value is m = 32bits as 1 = 2^32 - 1
			So the maximum substring length n is:
			36^(n+1) - 1 = 2^32 - 1
			36^(n+1) = 2^32
			(n+1)ln(36) = 32ln(2)
			n = 32ln(2)/ln(36) - 1
			n = 5.189644915687692
			n = 5
		 */
		var radixUint = radixPowerCache[radix] || new UINT64( Math.pow(radix, 5) )

		for (var i = 0, len = s.length; i < len; i += 5) {
			var size = Math.min(5, len - i)
			var value = parseInt( s.slice(i, i + size), radix )
			this.multiply(
					size < 5
						? new UINT64( Math.pow(radix, size) )
						: radixUint
				)
				.add( new UINT64(value) )
		}

		return this
	}
	UINT64.prototype.fromString = fromString

	/**
	 * Convert this _UINT64_ to a number (last 32 bits are dropped)
	 * @method toNumber
	 * @return {Number} the converted UINT64
	 */
	UINT64.prototype.toNumber = function () {
		return (this._a16 * 65536) + this._a00
	}

	/**
	 * Convert this _UINT64_ to a string
	 * @method toString
	 * @param {Number} radix (optional, default=10)
	 * @return {String} the converted UINT64
	 */
	UINT64.prototype.toString = function (radix) {
		radix = radix || 10
		var radixUint = radixCache[radix] || new UINT64(radix)

		if ( !this.gt(radixUint) ) return this.toNumber().toString(radix)

		var self = this.clone()
		var res = new Array(64)
		for (var i = 63; i >= 0; i--) {
			self.div(radixUint)
			res[i] = self.remainder.toNumber().toString(radix)
			if ( !self.gt(radixUint) ) break
		}
		res[i-1] = self.toNumber().toString(radix)

		return res.join('')
	}

	/**
	 * Add two _UINT64_. The current _UINT64_ stores the result
	 * @method add
	 * @param {Object} other UINT64
	 * @return ThisExpression
	 */
	UINT64.prototype.add = function (other) {
		var a00 = this._a00 + other._a00

		var a16 = a00 >>> 16
		a16 += this._a16 + other._a16

		var a32 = a16 >>> 16
		a32 += this._a32 + other._a32

		var a48 = a32 >>> 16
		a48 += this._a48 + other._a48

		this._a00 = a00 & 0xFFFF
		this._a16 = a16 & 0xFFFF
		this._a32 = a32 & 0xFFFF
		this._a48 = a48 & 0xFFFF

		return this
	}

	/**
	 * Subtract two _UINT64_. The current _UINT64_ stores the result
	 * @method subtract
	 * @param {Object} other UINT64
	 * @return ThisExpression
	 */
	UINT64.prototype.subtract = function (other) {
		return this.add( other.clone().negate() )
	}

	/**
	 * Multiply two _UINT64_. The current _UINT64_ stores the result
	 * @method multiply
	 * @param {Object} other UINT64
	 * @return ThisExpression
	 */
	UINT64.prototype.multiply = function (other) {
		/*
			a = a00 + a16 + a32 + a48
			b = b00 + b16 + b32 + b48
			a*b = (a00 + a16 + a32 + a48)(b00 + b16 + b32 + b48)
				= a00b00 + a00b16 + a00b32 + a00b48
				+ a16b00 + a16b16 + a16b32 + a16b48
				+ a32b00 + a32b16 + a32b32 + a32b48
				+ a48b00 + a48b16 + a48b32 + a48b48

			a16b48, a32b32, a48b16, a48b32 and a48b48 overflow the 64 bits
			so it comes down to:
			a*b	= a00b00 + a00b16 + a00b32 + a00b48
				+ a16b00 + a16b16 + a16b32
				+ a32b00 + a32b16
				+ a48b00
				= a00b00
				+ a00b16 + a16b00
				+ a00b32 + a16b16 + a32b00
				+ a00b48 + a16b32 + a32b16 + a48b00
		 */
		var a00 = this._a00
		var a16 = this._a16
		var a32 = this._a32
		var a48 = this._a48
		var b00 = other._a00
		var b16 = other._a16
		var b32 = other._a32
		var b48 = other._a48

		var c00 = a00 * b00

		var c16 = c00 >>> 16
		c16 += a00 * b16
		var c32 = c16 >>> 16
		c16 &= 0xFFFF
		c16 += a16 * b00

		c32 += c16 >>> 16
		c32 += a00 * b32
		var c48 = c32 >>> 16
		c32 &= 0xFFFF
		c32 += a16 * b16
		c48 += c32 >>> 16
		c32 &= 0xFFFF
		c32 += a32 * b00

		c48 += c32 >>> 16
		c48 += a00 * b48
		c48 &= 0xFFFF
		c48 += a16 * b32
		c48 &= 0xFFFF
		c48 += a32 * b16
		c48 &= 0xFFFF
		c48 += a48 * b00

		this._a00 = c00 & 0xFFFF
		this._a16 = c16 & 0xFFFF
		this._a32 = c32 & 0xFFFF
		this._a48 = c48 & 0xFFFF

		return this
	}

	/**
	 * Divide two _UINT64_. The current _UINT64_ stores the result.
	 * The remainder is made available as the _remainder_ property on
	 * the _UINT64_ object. It can be null, meaning there are no remainder.
	 * @method div
	 * @param {Object} other UINT64
	 * @return ThisExpression
	 */
	UINT64.prototype.div = function (other) {
		if ( (other._a16 == 0) && (other._a32 == 0) && (other._a48 == 0) ) {
			if (other._a00 == 0) throw Error('division by zero')

			// other == 1: this
			if (other._a00 == 1) {
				this.remainder = new UINT64(0)
				return this
			}
		}

		// other > this: 0
		if ( other.gt(this) ) {
			this.remainder = this.clone()
			this._a00 = 0
			this._a16 = 0
			this._a32 = 0
			this._a48 = 0
			return this
		}
		// other == this: 1
		if ( this.eq(other) ) {
			this.remainder = new UINT64(0)
			this._a00 = 1
			this._a16 = 0
			this._a32 = 0
			this._a48 = 0
			return this
		}

		// Shift the divisor left until it is higher than the dividend
		var _other = other.clone()
		var i = -1
		while ( !this.lt(_other) ) {
			// High bit can overflow the default 16bits
			// Its ok since we right shift after this loop
			// The overflown bit must be kept though
			_other.shiftLeft(1, true)
			i++
		}

		// Set the remainder
		this.remainder = this.clone()
		// Initialize the current result to 0
		this._a00 = 0
		this._a16 = 0
		this._a32 = 0
		this._a48 = 0
		for (; i >= 0; i--) {
			_other.shiftRight(1)
			// If shifted divisor is smaller than the dividend
			// then subtract it from the dividend
			if ( !this.remainder.lt(_other) ) {
				this.remainder.subtract(_other)
				// Update the current result
				if (i >= 48) {
					this._a48 |= 1 << (i - 48)
				} else if (i >= 32) {
					this._a32 |= 1 << (i - 32)
				} else if (i >= 16) {
					this._a16 |= 1 << (i - 16)
				} else {
					this._a00 |= 1 << i
				}
			}
		}

		return this
	}

	/**
	 * Negate the current _UINT64_
	 * @method negate
	 * @return ThisExpression
	 */
	UINT64.prototype.negate = function () {
		var v = ( ~this._a00 & 0xFFFF ) + 1
		this._a00 = v & 0xFFFF
		v = (~this._a16 & 0xFFFF) + (v >>> 16)
		this._a16 = v & 0xFFFF
		v = (~this._a32 & 0xFFFF) + (v >>> 16)
		this._a32 = v & 0xFFFF
		this._a48 = (~this._a48 + (v >>> 16)) & 0xFFFF

		return this
	}

	/**

	 * @method eq
	 * @param {Object} other UINT64
	 * @return {Boolean}
	 */
	UINT64.prototype.equals = UINT64.prototype.eq = function (other) {
		return (this._a48 == other._a48) && (this._a00 == other._a00)
			 && (this._a32 == other._a32) && (this._a16 == other._a16)
	}

	/**
	 * Greater than (strict)
	 * @method gt
	 * @param {Object} other UINT64
	 * @return {Boolean}
	 */
	UINT64.prototype.greaterThan = UINT64.prototype.gt = function (other) {
		if (this._a48 > other._a48) return true
		if (this._a48 < other._a48) return false
		if (this._a32 > other._a32) return true
		if (this._a32 < other._a32) return false
		if (this._a16 > other._a16) return true
		if (this._a16 < other._a16) return false
		return this._a00 > other._a00
	}

	/**
	 * Less than (strict)
	 * @method lt
	 * @param {Object} other UINT64
	 * @return {Boolean}
	 */
	UINT64.prototype.lessThan = UINT64.prototype.lt = function (other) {
		if (this._a48 < other._a48) return true
		if (this._a48 > other._a48) return false
		if (this._a32 < other._a32) return true
		if (this._a32 > other._a32) return false
		if (this._a16 < other._a16) return true
		if (this._a16 > other._a16) return false
		return this._a00 < other._a00
	}

	/**
	 * Bitwise OR
	 * @method or
	 * @param {Object} other UINT64
	 * @return ThisExpression
	 */
	UINT64.prototype.or = function (other) {
		this._a00 |= other._a00
		this._a16 |= other._a16
		this._a32 |= other._a32
		this._a48 |= other._a48

		return this
	}

	/**
	 * Bitwise AND
	 * @method and
	 * @param {Object} other UINT64
	 * @return ThisExpression
	 */
	UINT64.prototype.and = function (other) {
		this._a00 &= other._a00
		this._a16 &= other._a16
		this._a32 &= other._a32
		this._a48 &= other._a48

		return this
	}

	/**
	 * Bitwise XOR
	 * @method xor
	 * @param {Object} other UINT64
	 * @return ThisExpression
	 */
	UINT64.prototype.xor = function (other) {
		this._a00 ^= other._a00
		this._a16 ^= other._a16
		this._a32 ^= other._a32
		this._a48 ^= other._a48

		return this
	}

	/**
	 * Bitwise NOT
	 * @method not
	 * @return ThisExpression
	 */
	UINT64.prototype.not = function() {
		this._a00 = ~this._a00 & 0xFFFF
		this._a16 = ~this._a16 & 0xFFFF
		this._a32 = ~this._a32 & 0xFFFF
		this._a48 = ~this._a48 & 0xFFFF

		return this
	}

	/**
	 * Bitwise shift right
	 * @method shiftRight
	 * @param {Number} number of bits to shift
	 * @return ThisExpression
	 */
	UINT64.prototype.shiftRight = UINT64.prototype.shiftr = function (n) {
		n %= 64
		if (n >= 48) {
			this._a00 = this._a48 >> (n - 48)
			this._a16 = 0
			this._a32 = 0
			this._a48 = 0
		} else if (n >= 32) {
			n -= 32
			this._a00 = ( (this._a32 >> n) | (this._a48 << (16-n)) ) & 0xFFFF
			this._a16 = (this._a48 >> n) & 0xFFFF
			this._a32 = 0
			this._a48 = 0
		} else if (n >= 16) {
			n -= 16
			this._a00 = ( (this._a16 >> n) | (this._a32 << (16-n)) ) & 0xFFFF
			this._a16 = ( (this._a32 >> n) | (this._a48 << (16-n)) ) & 0xFFFF
			this._a32 = (this._a48 >> n) & 0xFFFF
			this._a48 = 0
		} else {
			this._a00 = ( (this._a00 >> n) | (this._a16 << (16-n)) ) & 0xFFFF
			this._a16 = ( (this._a16 >> n) | (this._a32 << (16-n)) ) & 0xFFFF
			this._a32 = ( (this._a32 >> n) | (this._a48 << (16-n)) ) & 0xFFFF
			this._a48 = (this._a48 >> n) & 0xFFFF
		}

		return this
	}

	/**
	 * Bitwise shift left
	 * @method shiftLeft
	 * @param {Number} number of bits to shift
	 * @param {Boolean} allow overflow
	 * @return ThisExpression
	 */
	UINT64.prototype.shiftLeft = UINT64.prototype.shiftl = function (n, allowOverflow) {
		n %= 64
		if (n >= 48) {
			this._a48 = this._a00 << (n - 48)
			this._a32 = 0
			this._a16 = 0
			this._a00 = 0
		} else if (n >= 32) {
			n -= 32
			this._a48 = (this._a16 << n) | (this._a00 >> (16-n))
			this._a32 = (this._a00 << n) & 0xFFFF
			this._a16 = 0
			this._a00 = 0
		} else if (n >= 16) {
			n -= 16
			this._a48 = (this._a32 << n) | (this._a16 >> (16-n))
			this._a32 = ( (this._a16 << n) | (this._a00 >> (16-n)) ) & 0xFFFF
			this._a16 = (this._a00 << n) & 0xFFFF
			this._a00 = 0
		} else {
			this._a48 = (this._a48 << n) | (this._a32 >> (16-n))
			this._a32 = ( (this._a32 << n) | (this._a16 >> (16-n)) ) & 0xFFFF
			this._a16 = ( (this._a16 << n) | (this._a00 >> (16-n)) ) & 0xFFFF
			this._a00 = (this._a00 << n) & 0xFFFF
		}
		if (!allowOverflow) {
			this._a48 &= 0xFFFF
		}

		return this
	}

	/**
	 * Bitwise rotate left
	 * @method rotl
	 * @param {Number} number of bits to rotate
	 * @return ThisExpression
	 */
	UINT64.prototype.rotateLeft = UINT64.prototype.rotl = function (n) {
		n %= 64
		if (n == 0) return this
		if (n >= 32) {
			// A.B.C.D
			// B.C.D.A rotl(16)
			// C.D.A.B rotl(32)
			var v = this._a00
			this._a00 = this._a32
			this._a32 = v
			v = this._a48
			this._a48 = this._a16
			this._a16 = v
			if (n == 32) return this
			n -= 32
		}

		var high = (this._a48 << 16) | this._a32
		var low = (this._a16 << 16) | this._a00

		var _high = (high << n) | (low >>> (32 - n))
		var _low = (low << n) | (high >>> (32 - n))

		this._a00 = _low & 0xFFFF
		this._a16 = _low >>> 16
		this._a32 = _high & 0xFFFF
		this._a48 = _high >>> 16

		return this
	}

	/**
	 * Bitwise rotate right
	 * @method rotr
	 * @param {Number} number of bits to rotate
	 * @return ThisExpression
	 */
	UINT64.prototype.rotateRight = UINT64.prototype.rotr = function (n) {
		n %= 64
		if (n == 0) return this
		if (n >= 32) {
			// A.B.C.D
			// D.A.B.C rotr(16)
			// C.D.A.B rotr(32)
			var v = this._a00
			this._a00 = this._a32
			this._a32 = v
			v = this._a48
			this._a48 = this._a16
			this._a16 = v
			if (n == 32) return this
			n -= 32
		}

		var high = (this._a48 << 16) | this._a32
		var low = (this._a16 << 16) | this._a00

		var _high = (high >>> n) | (low << (32 - n))
		var _low = (low >>> n) | (high << (32 - n))

		this._a00 = _low & 0xFFFF
		this._a16 = _low >>> 16
		this._a32 = _high & 0xFFFF
		this._a48 = _high >>> 16

		return this
	}

	/**
	 * Clone the current _UINT64_
	 * @method clone
	 * @return {Object} cloned UINT64
	 */
	UINT64.prototype.clone = function () {
		return new UINT64(this._a00, this._a16, this._a32, this._a48)
	}

	if (true) {
		// AMD / RequireJS
		!(__WEBPACK_AMD_DEFINE_ARRAY__ = [], __WEBPACK_AMD_DEFINE_RESULT__ = function () {
			return UINT64
		}.apply(exports, __WEBPACK_AMD_DEFINE_ARRAY__),
				__WEBPACK_AMD_DEFINE_RESULT__ !== undefined && (module.exports = __WEBPACK_AMD_DEFINE_RESULT__))
	} else if (typeof module != 'undefined' && module.exports) {
		// Node.js
		module.exports = UINT64
	} else {
		// Browser
		root['UINT64'] = UINT64
	}

})(this)


/***/ }),
/* 52 */
/***/ (function(module, exports) {

exports.read = function (buffer, offset, isLE, mLen, nBytes) {
  var e, m
  var eLen = (nBytes * 8) - mLen - 1
  var eMax = (1 << eLen) - 1
  var eBias = eMax >> 1
  var nBits = -7
  var i = isLE ? (nBytes - 1) : 0
  var d = isLE ? -1 : 1
  var s = buffer[offset + i]

  i += d

  e = s & ((1 << (-nBits)) - 1)
  s >>= (-nBits)
  nBits += eLen
  for (; nBits > 0; e = (e * 256) + buffer[offset + i], i += d, nBits -= 8) {}

  m = e & ((1 << (-nBits)) - 1)
  e >>= (-nBits)
  nBits += mLen
  for (; nBits > 0; m = (m * 256) + buffer[offset + i], i += d, nBits -= 8) {}

  if (e === 0) {
    e = 1 - eBias
  } else if (e === eMax) {
    return m ? NaN : ((s ? -1 : 1) * Infinity)
  } else {
    m = m + Math.pow(2, mLen)
    e = e - eBias
  }
  return (s ? -1 : 1) * m * Math.pow(2, e - mLen)
}

exports.write = function (buffer, value, offset, isLE, mLen, nBytes) {
  var e, m, c
  var eLen = (nBytes * 8) - mLen - 1
  var eMax = (1 << eLen) - 1
  var eBias = eMax >> 1
  var rt = (mLen === 23 ? Math.pow(2, -24) - Math.pow(2, -77) : 0)
  var i = isLE ? 0 : (nBytes - 1)
  var d = isLE ? 1 : -1
  var s = value < 0 || (value === 0 && 1 / value < 0) ? 1 : 0

  value = Math.abs(value)

  if (isNaN(value) || value === Infinity) {
    m = isNaN(value) ? 1 : 0
    e = eMax
  } else {
    e = Math.floor(Math.log(value) / Math.LN2)
    if (value * (c = Math.pow(2, -e)) < 1) {
      e--
      c *= 2
    }
    if (e + eBias >= 1) {
      value += rt / c
    } else {
      value += rt * Math.pow(2, 1 - eBias)
    }
    if (value * c >= 2) {
      e++
      c /= 2
    }

    if (e + eBias >= eMax) {
      m = 0
      e = eMax
    } else if (e + eBias >= 1) {
      m = ((value * c) - 1) * Math.pow(2, mLen)
      e = e + eBias
    } else {
      m = value * Math.pow(2, eBias - 1) * Math.pow(2, mLen)
      e = 0
    }
  }

  for (; mLen >= 8; buffer[offset + i] = m & 0xff, i += d, m /= 256, mLen -= 8) {}

  e = (e << mLen) | m
  eLen += mLen
  for (; eLen > 0; buffer[offset + i] = e & 0xff, i += d, e /= 256, eLen -= 8) {}

  buffer[offset + i - d] |= s * 128
}


/***/ }),
/* 53 */
/***/ (function(module, exports, __webpack_require__) {

module.exports = __webpack_require__(6);


/***/ }),
/* 54 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";
// Copyright Joyent, Inc. and other Node contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.

// a passthrough stream.
// basically just the most minimal sort of Transform stream.
// Every written chunk gets output as-is.



module.exports = PassThrough;

var Transform = __webpack_require__(19);

/*<replacement>*/
var util = __webpack_require__(10);
util.inherits = __webpack_require__(8);
/*</replacement>*/

util.inherits(PassThrough, Transform);

function PassThrough(options) {
  if (!(this instanceof PassThrough)) return new PassThrough(options);

  Transform.call(this, options);
}

PassThrough.prototype._transform = function (chunk, encoding, cb) {
  cb(null, chunk);
};

/***/ }),
/* 55 */
/***/ (function(module, exports, __webpack_require__) {

"use strict";


function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

var Buffer = __webpack_require__(12).Buffer;
var util = __webpack_require__(66);

function copyBuffer(src, target, offset) {
  src.copy(target, offset);
}

module.exports = function () {
  function BufferList() {
    _classCallCheck(this, BufferList);

    this.head = null;
    this.tail = null;
    this.length = 0;
  }

  BufferList.prototype.push = function push(v) {
    var entry = { data: v, next: null };
    if (this.length > 0) this.tail.next = entry;else this.head = entry;
    this.tail = entry;
    ++this.length;
  };

  BufferList.prototype.unshift = function unshift(v) {
    var entry = { data: v, next: this.head };
    if (this.length === 0) this.tail = entry;
    this.head = entry;
    ++this.length;
  };

  BufferList.prototype.shift = function shift() {
    if (this.length === 0) return;
    var ret = this.head.data;
    if (this.length === 1) this.head = this.tail = null;else this.head = this.head.next;
    --this.length;
    return ret;
  };

  BufferList.prototype.clear = function clear() {
    this.head = this.tail = null;
    this.length = 0;
  };

  BufferList.prototype.join = function join(s) {
    if (this.length === 0) return '';
    var p = this.head;
    var ret = '' + p.data;
    while (p = p.next) {
      ret += s + p.data;
    }return ret;
  };

  BufferList.prototype.concat = function concat(n) {
    if (this.length === 0) return Buffer.alloc(0);
    if (this.length === 1) return this.head.data;
    var ret = Buffer.allocUnsafe(n >>> 0);
    var p = this.head;
    var i = 0;
    while (p) {
      copyBuffer(p.data, ret, i);
      i += p.data.length;
      p = p.next;
    }
    return ret;
  };

  return BufferList;
}();

if (util && util.inspect && util.inspect.custom) {
  module.exports.prototype[util.inspect.custom] = function () {
    var obj = util.inspect({ length: this.length });
    return this.constructor.name + ' ' + obj;
  };
}

/***/ }),
/* 56 */
/***/ (function(module, exports, __webpack_require__) {

module.exports = __webpack_require__(16).PassThrough


/***/ }),
/* 57 */
/***/ (function(module, exports, __webpack_require__) {

module.exports = __webpack_require__(16).Transform


/***/ }),
/* 58 */
/***/ (function(module, exports, __webpack_require__) {

module.exports = __webpack_require__(15);


/***/ }),
/* 59 */
/***/ (function(module, exports, __webpack_require__) {

/* WEBPACK VAR INJECTION */(function(global, process) {(function (global, undefined) {
    "use strict";

    if (global.setImmediate) {
        return;
    }

    var nextHandle = 1; // Spec says greater than zero
    var tasksByHandle = {};
    var currentlyRunningATask = false;
    var doc = global.document;
    var registerImmediate;

    function setImmediate(callback) {
      // Callback can either be a function or a string
      if (typeof callback !== "function") {
        callback = new Function("" + callback);
      }
      // Copy function arguments
      var args = new Array(arguments.length - 1);
      for (var i = 0; i < args.length; i++) {
          args[i] = arguments[i + 1];
      }
      // Store and register the task
      var task = { callback: callback, args: args };
      tasksByHandle[nextHandle] = task;
      registerImmediate(nextHandle);
      return nextHandle++;
    }

    function clearImmediate(handle) {
        delete tasksByHandle[handle];
    }

    function run(task) {
        var callback = task.callback;
        var args = task.args;
        switch (args.length) {
        case 0:
            callback();
            break;
        case 1:
            callback(args[0]);
            break;
        case 2:
            callback(args[0], args[1]);
            break;
        case 3:
            callback(args[0], args[1], args[2]);
            break;
        default:
            callback.apply(undefined, args);
            break;
        }
    }

    function runIfPresent(handle) {
        // From the spec: "Wait until any invocations of this algorithm started before this one have completed."
        // So if we're currently running a task, we'll need to delay this invocation.
        if (currentlyRunningATask) {
            // Delay by doing a setTimeout. setImmediate was tried instead, but in Firefox 7 it generated a
            // "too much recursion" error.
            setTimeout(runIfPresent, 0, handle);
        } else {
            var task = tasksByHandle[handle];
            if (task) {
                currentlyRunningATask = true;
                try {
                    run(task);
                } finally {
                    clearImmediate(handle);
                    currentlyRunningATask = false;
                }
            }
        }
    }

    function installNextTickImplementation() {
        registerImmediate = function(handle) {
            process.nextTick(function () { runIfPresent(handle); });
        };
    }

    function canUsePostMessage() {
        // The test against `importScripts` prevents this implementation from being installed inside a web worker,
        // where `global.postMessage` means something completely different and can't be used for this purpose.
        if (global.postMessage && !global.importScripts) {
            var postMessageIsAsynchronous = true;
            var oldOnMessage = global.onmessage;
            global.onmessage = function() {
                postMessageIsAsynchronous = false;
            };
            global.postMessage("", "*");
            global.onmessage = oldOnMessage;
            return postMessageIsAsynchronous;
        }
    }

    function installPostMessageImplementation() {
        // Installs an event handler on `global` for the `message` event: see
        // * https://developer.mozilla.org/en/DOM/window.postMessage
        // * http://www.whatwg.org/specs/web-apps/current-work/multipage/comms.html#crossDocumentMessages

        var messagePrefix = "setImmediate$" + Math.random() + "$";
        var onGlobalMessage = function(event) {
            if (event.source === global &&
                typeof event.data === "string" &&
                event.data.indexOf(messagePrefix) === 0) {
                runIfPresent(+event.data.slice(messagePrefix.length));
            }
        };

        if (global.addEventListener) {
            global.addEventListener("message", onGlobalMessage, false);
        } else {
            global.attachEvent("onmessage", onGlobalMessage);
        }

        registerImmediate = function(handle) {
            global.postMessage(messagePrefix + handle, "*");
        };
    }

    function installMessageChannelImplementation() {
        var channel = new MessageChannel();
        channel.port1.onmessage = function(event) {
            var handle = event.data;
            runIfPresent(handle);
        };

        registerImmediate = function(handle) {
            channel.port2.postMessage(handle);
        };
    }

    function installReadyStateChangeImplementation() {
        var html = doc.documentElement;
        registerImmediate = function(handle) {
            // Create a <script> element; its readystatechange event will be fired asynchronously once it is inserted
            // into the document. Do so, thus queuing up the task. Remember to clean up once it's been called.
            var script = doc.createElement("script");
            script.onreadystatechange = function () {
                runIfPresent(handle);
                script.onreadystatechange = null;
                html.removeChild(script);
                script = null;
            };
            html.appendChild(script);
        };
    }

    function installSetTimeoutImplementation() {
        registerImmediate = function(handle) {
            setTimeout(runIfPresent, 0, handle);
        };
    }

    // If supported, we should attach to the prototype of global, since that is where setTimeout et al. live.
    var attachTo = Object.getPrototypeOf && Object.getPrototypeOf(global);
    attachTo = attachTo && attachTo.setTimeout ? attachTo : global;

    // Don't get fooled by e.g. browserify environments.
    if ({}.toString.call(global.process) === "[object process]") {
        // For Node.js before 0.9
        installNextTickImplementation();

    } else if (canUsePostMessage()) {
        // For non-IE10 modern browsers
        installPostMessageImplementation();

    } else if (global.MessageChannel) {
        // For web workers, where supported
        installMessageChannelImplementation();

    } else if (doc && "onreadystatechange" in doc.createElement("script")) {
        // For IE 6–8
        installReadyStateChangeImplementation();

    } else {
        // For older browsers
        installSetTimeoutImplementation();
    }

    attachTo.setImmediate = setImmediate;
    attachTo.clearImmediate = clearImmediate;
}(typeof self === "undefined" ? typeof global === "undefined" ? this : global : self));

/* WEBPACK VAR INJECTION */}.call(exports, __webpack_require__(5), __webpack_require__(9)))

/***/ }),
/* 60 */
/***/ (function(module, exports, __webpack_require__) {

/* WEBPACK VAR INJECTION */(function(global) {var scope = (typeof global !== "undefined" && global) ||
            (typeof self !== "undefined" && self) ||
            window;
var apply = Function.prototype.apply;

// DOM APIs, for completeness

exports.setTimeout = function() {
  return new Timeout(apply.call(setTimeout, scope, arguments), clearTimeout);
};
exports.setInterval = function() {
  return new Timeout(apply.call(setInterval, scope, arguments), clearInterval);
};
exports.clearTimeout =
exports.clearInterval = function(timeout) {
  if (timeout) {
    timeout.close();
  }
};

function Timeout(id, clearFn) {
  this._id = id;
  this._clearFn = clearFn;
}
Timeout.prototype.unref = Timeout.prototype.ref = function() {};
Timeout.prototype.close = function() {
  this._clearFn.call(scope, this._id);
};

// Does not start the time, just sets up the members needed.
exports.enroll = function(item, msecs) {
  clearTimeout(item._idleTimeoutId);
  item._idleTimeout = msecs;
};

exports.unenroll = function(item) {
  clearTimeout(item._idleTimeoutId);
  item._idleTimeout = -1;
};

exports._unrefActive = exports.active = function(item) {
  clearTimeout(item._idleTimeoutId);

  var msecs = item._idleTimeout;
  if (msecs >= 0) {
    item._idleTimeoutId = setTimeout(function onTimeout() {
      if (item._onTimeout)
        item._onTimeout();
    }, msecs);
  }
};

// setimmediate attaches itself to the global object
__webpack_require__(59);
// On some exotic environments, it's not clear which object `setimmediate` was
// able to install onto.  Search each possibility in the same order as the
// `setimmediate` library.
exports.setImmediate = (typeof self !== "undefined" && self.setImmediate) ||
                       (typeof global !== "undefined" && global.setImmediate) ||
                       (this && this.setImmediate);
exports.clearImmediate = (typeof self !== "undefined" && self.clearImmediate) ||
                         (typeof global !== "undefined" && global.clearImmediate) ||
                         (this && this.clearImmediate);

/* WEBPACK VAR INJECTION */}.call(exports, __webpack_require__(5)))

/***/ }),
/* 61 */
/***/ (function(module, exports, __webpack_require__) {

/* WEBPACK VAR INJECTION */(function(global) {
/**
 * Module exports.
 */

module.exports = deprecate;

/**
 * Mark that a method should not be used.
 * Returns a modified function which warns once by default.
 *
 * If `localStorage.noDeprecation = true` is set, then it is a no-op.
 *
 * If `localStorage.throwDeprecation = true` is set, then deprecated functions
 * will throw an Error when invoked.
 *
 * If `localStorage.traceDeprecation = true` is set, then deprecated functions
 * will invoke `console.trace()` instead of `console.error()`.
 *
 * @param {Function} fn - the function to deprecate
 * @param {String} msg - the string to print to the console when `fn` is invoked
 * @returns {Function} a new "deprecated" version of `fn`
 * @api public
 */

function deprecate (fn, msg) {
  if (config('noDeprecation')) {
    return fn;
  }

  var warned = false;
  function deprecated() {
    if (!warned) {
      if (config('throwDeprecation')) {
        throw new Error(msg);
      } else if (config('traceDeprecation')) {
        console.trace(msg);
      } else {
        console.warn(msg);
      }
      warned = true;
    }
    return fn.apply(this, arguments);
  }

  return deprecated;
}

/**
 * Checks `localStorage` for boolean values for the given `name`.
 *
 * @param {String} name
 * @returns {Boolean}
 * @api private
 */

function config (name) {
  // accessing global.localStorage can trigger a DOMException in sandboxed iframes
  try {
    if (!global.localStorage) return false;
  } catch (_) {
    return false;
  }
  var val = global.localStorage[name];
  if (null == val) return false;
  return String(val).toLowerCase() === 'true';
}

/* WEBPACK VAR INJECTION */}.call(exports, __webpack_require__(5)))

/***/ }),
/* 62 */
/***/ (function(module, exports) {

if (typeof Object.create === 'function') {
  // implementation from standard node.js 'util' module
  module.exports = function inherits(ctor, superCtor) {
    ctor.super_ = superCtor
    ctor.prototype = Object.create(superCtor.prototype, {
      constructor: {
        value: ctor,
        enumerable: false,
        writable: true,
        configurable: true
      }
    });
  };
} else {
  // old school shim for old browsers
  module.exports = function inherits(ctor, superCtor) {
    ctor.super_ = superCtor
    var TempCtor = function () {}
    TempCtor.prototype = superCtor.prototype
    ctor.prototype = new TempCtor()
    ctor.prototype.constructor = ctor
  }
}


/***/ }),
/* 63 */
/***/ (function(module, exports) {

module.exports = function isBuffer(arg) {
  return arg && typeof arg === 'object'
    && typeof arg.copy === 'function'
    && typeof arg.fill === 'function'
    && typeof arg.readUInt8 === 'function';
}

/***/ }),
/* 64 */
/***/ (function(module, exports, __webpack_require__) {

/* WEBPACK VAR INJECTION */(function(global, process) {// Copyright Joyent, Inc. and other Node contributors.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.

var formatRegExp = /%[sdj%]/g;
exports.format = function(f) {
  if (!isString(f)) {
    var objects = [];
    for (var i = 0; i < arguments.length; i++) {
      objects.push(inspect(arguments[i]));
    }
    return objects.join(' ');
  }

  var i = 1;
  var args = arguments;
  var len = args.length;
  var str = String(f).replace(formatRegExp, function(x) {
    if (x === '%%') return '%';
    if (i >= len) return x;
    switch (x) {
      case '%s': return String(args[i++]);
      case '%d': return Number(args[i++]);
      case '%j':
        try {
          return JSON.stringify(args[i++]);
        } catch (_) {
          return '[Circular]';
        }
      default:
        return x;
    }
  });
  for (var x = args[i]; i < len; x = args[++i]) {
    if (isNull(x) || !isObject(x)) {
      str += ' ' + x;
    } else {
      str += ' ' + inspect(x);
    }
  }
  return str;
};


// Mark that a method should not be used.
// Returns a modified function which warns once by default.
// If --no-deprecation is set, then it is a no-op.
exports.deprecate = function(fn, msg) {
  // Allow for deprecating things in the process of starting up.
  if (isUndefined(global.process)) {
    return function() {
      return exports.deprecate(fn, msg).apply(this, arguments);
    };
  }

  if (process.noDeprecation === true) {
    return fn;
  }

  var warned = false;
  function deprecated() {
    if (!warned) {
      if (process.throwDeprecation) {
        throw new Error(msg);
      } else if (process.traceDeprecation) {
        console.trace(msg);
      } else {
        console.error(msg);
      }
      warned = true;
    }
    return fn.apply(this, arguments);
  }

  return deprecated;
};


var debugs = {};
var debugEnviron;
exports.debuglog = function(set) {
  if (isUndefined(debugEnviron))
    debugEnviron = process.env.NODE_DEBUG || '';
  set = set.toUpperCase();
  if (!debugs[set]) {
    if (new RegExp('\\b' + set + '\\b', 'i').test(debugEnviron)) {
      var pid = process.pid;
      debugs[set] = function() {
        var msg = exports.format.apply(exports, arguments);
        console.error('%s %d: %s', set, pid, msg);
      };
    } else {
      debugs[set] = function() {};
    }
  }
  return debugs[set];
};


/**
 * Echos the value of a value. Trys to print the value out
 * in the best way possible given the different types.
 *
 * @param {Object} obj The object to print out.
 * @param {Object} opts Optional options object that alters the output.
 */
/* legacy: obj, showHidden, depth, colors*/
function inspect(obj, opts) {
  // default options
  var ctx = {
    seen: [],
    stylize: stylizeNoColor
  };
  // legacy...
  if (arguments.length >= 3) ctx.depth = arguments[2];
  if (arguments.length >= 4) ctx.colors = arguments[3];
  if (isBoolean(opts)) {
    // legacy...
    ctx.showHidden = opts;
  } else if (opts) {
    // got an "options" object
    exports._extend(ctx, opts);
  }
  // set default options
  if (isUndefined(ctx.showHidden)) ctx.showHidden = false;
  if (isUndefined(ctx.depth)) ctx.depth = 2;
  if (isUndefined(ctx.colors)) ctx.colors = false;
  if (isUndefined(ctx.customInspect)) ctx.customInspect = true;
  if (ctx.colors) ctx.stylize = stylizeWithColor;
  return formatValue(ctx, obj, ctx.depth);
}
exports.inspect = inspect;


// http://en.wikipedia.org/wiki/ANSI_escape_code#graphics
inspect.colors = {
  'bold' : [1, 22],
  'italic' : [3, 23],
  'underline' : [4, 24],
  'inverse' : [7, 27],
  'white' : [37, 39],
  'grey' : [90, 39],
  'black' : [30, 39],
  'blue' : [34, 39],
  'cyan' : [36, 39],
  'green' : [32, 39],
  'magenta' : [35, 39],
  'red' : [31, 39],
  'yellow' : [33, 39]
};

// Don't use 'blue' not visible on cmd.exe
inspect.styles = {
  'special': 'cyan',
  'number': 'yellow',
  'boolean': 'yellow',
  'undefined': 'grey',
  'null': 'bold',
  'string': 'green',
  'date': 'magenta',
  // "name": intentionally not styling
  'regexp': 'red'
};


function stylizeWithColor(str, styleType) {
  var style = inspect.styles[styleType];

  if (style) {
    return '\u001b[' + inspect.colors[style][0] + 'm' + str +
           '\u001b[' + inspect.colors[style][1] + 'm';
  } else {
    return str;
  }
}


function stylizeNoColor(str, styleType) {
  return str;
}


function arrayToHash(array) {
  var hash = {};

  array.forEach(function(val, idx) {
    hash[val] = true;
  });

  return hash;
}


function formatValue(ctx, value, recurseTimes) {
  // Provide a hook for user-specified inspect functions.
  // Check that value is an object with an inspect function on it
  if (ctx.customInspect &&
      value &&
      isFunction(value.inspect) &&
      // Filter out the util module, it's inspect function is special
      value.inspect !== exports.inspect &&
      // Also filter out any prototype objects using the circular check.
      !(value.constructor && value.constructor.prototype === value)) {
    var ret = value.inspect(recurseTimes, ctx);
    if (!isString(ret)) {
      ret = formatValue(ctx, ret, recurseTimes);
    }
    return ret;
  }

  // Primitive types cannot have properties
  var primitive = formatPrimitive(ctx, value);
  if (primitive) {
    return primitive;
  }

  // Look up the keys of the object.
  var keys = Object.keys(value);
  var visibleKeys = arrayToHash(keys);

  if (ctx.showHidden) {
    keys = Object.getOwnPropertyNames(value);
  }

  // IE doesn't make error fields non-enumerable
  // http://msdn.microsoft.com/en-us/library/ie/dww52sbt(v=vs.94).aspx
  if (isError(value)
      && (keys.indexOf('message') >= 0 || keys.indexOf('description') >= 0)) {
    return formatError(value);
  }

  // Some type of object without properties can be shortcutted.
  if (keys.length === 0) {
    if (isFunction(value)) {
      var name = value.name ? ': ' + value.name : '';
      return ctx.stylize('[Function' + name + ']', 'special');
    }
    if (isRegExp(value)) {
      return ctx.stylize(RegExp.prototype.toString.call(value), 'regexp');
    }
    if (isDate(value)) {
      return ctx.stylize(Date.prototype.toString.call(value), 'date');
    }
    if (isError(value)) {
      return formatError(value);
    }
  }

  var base = '', array = false, braces = ['{', '}'];

  // Make Array say that they are Array
  if (isArray(value)) {
    array = true;
    braces = ['[', ']'];
  }

  // Make functions say that they are functions
  if (isFunction(value)) {
    var n = value.name ? ': ' + value.name : '';
    base = ' [Function' + n + ']';
  }

  // Make RegExps say that they are RegExps
  if (isRegExp(value)) {
    base = ' ' + RegExp.prototype.toString.call(value);
  }

  // Make dates with properties first say the date
  if (isDate(value)) {
    base = ' ' + Date.prototype.toUTCString.call(value);
  }

  // Make error with message first say the error
  if (isError(value)) {
    base = ' ' + formatError(value);
  }

  if (keys.length === 0 && (!array || value.length == 0)) {
    return braces[0] + base + braces[1];
  }

  if (recurseTimes < 0) {
    if (isRegExp(value)) {
      return ctx.stylize(RegExp.prototype.toString.call(value), 'regexp');
    } else {
      return ctx.stylize('[Object]', 'special');
    }
  }

  ctx.seen.push(value);

  var output;
  if (array) {
    output = formatArray(ctx, value, recurseTimes, visibleKeys, keys);
  } else {
    output = keys.map(function(key) {
      return formatProperty(ctx, value, recurseTimes, visibleKeys, key, array);
    });
  }

  ctx.seen.pop();

  return reduceToSingleString(output, base, braces);
}


function formatPrimitive(ctx, value) {
  if (isUndefined(value))
    return ctx.stylize('undefined', 'undefined');
  if (isString(value)) {
    var simple = '\'' + JSON.stringify(value).replace(/^"|"$/g, '')
                                             .replace(/'/g, "\\'")
                                             .replace(/\\"/g, '"') + '\'';
    return ctx.stylize(simple, 'string');
  }
  if (isNumber(value))
    return ctx.stylize('' + value, 'number');
  if (isBoolean(value))
    return ctx.stylize('' + value, 'boolean');
  // For some reason typeof null is "object", so special case here.
  if (isNull(value))
    return ctx.stylize('null', 'null');
}


function formatError(value) {
  return '[' + Error.prototype.toString.call(value) + ']';
}


function formatArray(ctx, value, recurseTimes, visibleKeys, keys) {
  var output = [];
  for (var i = 0, l = value.length; i < l; ++i) {
    if (hasOwnProperty(value, String(i))) {
      output.push(formatProperty(ctx, value, recurseTimes, visibleKeys,
          String(i), true));
    } else {
      output.push('');
    }
  }
  keys.forEach(function(key) {
    if (!key.match(/^\d+$/)) {
      output.push(formatProperty(ctx, value, recurseTimes, visibleKeys,
          key, true));
    }
  });
  return output;
}


function formatProperty(ctx, value, recurseTimes, visibleKeys, key, array) {
  var name, str, desc;
  desc = Object.getOwnPropertyDescriptor(value, key) || { value: value[key] };
  if (desc.get) {
    if (desc.set) {
      str = ctx.stylize('[Getter/Setter]', 'special');
    } else {
      str = ctx.stylize('[Getter]', 'special');
    }
  } else {
    if (desc.set) {
      str = ctx.stylize('[Setter]', 'special');
    }
  }
  if (!hasOwnProperty(visibleKeys, key)) {
    name = '[' + key + ']';
  }
  if (!str) {
    if (ctx.seen.indexOf(desc.value) < 0) {
      if (isNull(recurseTimes)) {
        str = formatValue(ctx, desc.value, null);
      } else {
        str = formatValue(ctx, desc.value, recurseTimes - 1);
      }
      if (str.indexOf('\n') > -1) {
        if (array) {
          str = str.split('\n').map(function(line) {
            return '  ' + line;
          }).join('\n').substr(2);
        } else {
          str = '\n' + str.split('\n').map(function(line) {
            return '   ' + line;
          }).join('\n');
        }
      }
    } else {
      str = ctx.stylize('[Circular]', 'special');
    }
  }
  if (isUndefined(name)) {
    if (array && key.match(/^\d+$/)) {
      return str;
    }
    name = JSON.stringify('' + key);
    if (name.match(/^"([a-zA-Z_][a-zA-Z_0-9]*)"$/)) {
      name = name.substr(1, name.length - 2);
      name = ctx.stylize(name, 'name');
    } else {
      name = name.replace(/'/g, "\\'")
                 .replace(/\\"/g, '"')
                 .replace(/(^"|"$)/g, "'");
      name = ctx.stylize(name, 'string');
    }
  }

  return name + ': ' + str;
}


function reduceToSingleString(output, base, braces) {
  var numLinesEst = 0;
  var length = output.reduce(function(prev, cur) {
    numLinesEst++;
    if (cur.indexOf('\n') >= 0) numLinesEst++;
    return prev + cur.replace(/\u001b\[\d\d?m/g, '').length + 1;
  }, 0);

  if (length > 60) {
    return braces[0] +
           (base === '' ? '' : base + '\n ') +
           ' ' +
           output.join(',\n  ') +
           ' ' +
           braces[1];
  }

  return braces[0] + base + ' ' + output.join(', ') + ' ' + braces[1];
}


// NOTE: These type checking functions intentionally don't use `instanceof`
// because it is fragile and can be easily faked with `Object.create()`.
function isArray(ar) {
  return Array.isArray(ar);
}
exports.isArray = isArray;

function isBoolean(arg) {
  return typeof arg === 'boolean';
}
exports.isBoolean = isBoolean;

function isNull(arg) {
  return arg === null;
}
exports.isNull = isNull;

function isNullOrUndefined(arg) {
  return arg == null;
}
exports.isNullOrUndefined = isNullOrUndefined;

function isNumber(arg) {
  return typeof arg === 'number';
}
exports.isNumber = isNumber;

function isString(arg) {
  return typeof arg === 'string';
}
exports.isString = isString;

function isSymbol(arg) {
  return typeof arg === 'symbol';
}
exports.isSymbol = isSymbol;

function isUndefined(arg) {
  return arg === void 0;
}
exports.isUndefined = isUndefined;

function isRegExp(re) {
  return isObject(re) && objectToString(re) === '[object RegExp]';
}
exports.isRegExp = isRegExp;

function isObject(arg) {
  return typeof arg === 'object' && arg !== null;
}
exports.isObject = isObject;

function isDate(d) {
  return isObject(d) && objectToString(d) === '[object Date]';
}
exports.isDate = isDate;

function isError(e) {
  return isObject(e) &&
      (objectToString(e) === '[object Error]' || e instanceof Error);
}
exports.isError = isError;

function isFunction(arg) {
  return typeof arg === 'function';
}
exports.isFunction = isFunction;

function isPrimitive(arg) {
  return arg === null ||
         typeof arg === 'boolean' ||
         typeof arg === 'number' ||
         typeof arg === 'string' ||
         typeof arg === 'symbol' ||  // ES6 symbol
         typeof arg === 'undefined';
}
exports.isPrimitive = isPrimitive;

exports.isBuffer = __webpack_require__(63);

function objectToString(o) {
  return Object.prototype.toString.call(o);
}


function pad(n) {
  return n < 10 ? '0' + n.toString(10) : n.toString(10);
}


var months = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep',
              'Oct', 'Nov', 'Dec'];

// 26 Feb 16:19:34
function timestamp() {
  var d = new Date();
  var time = [pad(d.getHours()),
              pad(d.getMinutes()),
              pad(d.getSeconds())].join(':');
  return [d.getDate(), months[d.getMonth()], time].join(' ');
}


// log is just a thin wrapper to console.log that prepends a timestamp
exports.log = function() {
  console.log('%s - %s', timestamp(), exports.format.apply(exports, arguments));
};


/**
 * Inherit the prototype methods from one constructor into another.
 *
 * The Function.prototype.inherits from lang.js rewritten as a standalone
 * function (not on Function.prototype). NOTE: If this file is to be loaded
 * during bootstrapping this function needs to be rewritten using some native
 * functions as prototype setup using normal JavaScript does not work as
 * expected during bootstrapping (see mirror.js in r114903).
 *
 * @param {function} ctor Constructor function which needs to inherit the
 *     prototype.
 * @param {function} superCtor Constructor function to inherit prototype from.
 */
exports.inherits = __webpack_require__(62);

exports._extend = function(origin, add) {
  // Don't do anything if add isn't an object
  if (!add || !isObject(add)) return origin;

  var keys = Object.keys(add);
  var i = keys.length;
  while (i--) {
    origin[keys[i]] = add[keys[i]];
  }
  return origin;
};

function hasOwnProperty(obj, prop) {
  return Object.prototype.hasOwnProperty.call(obj, prop);
}

/* WEBPACK VAR INJECTION */}.call(exports, __webpack_require__(5), __webpack_require__(9)))

/***/ }),
/* 65 */
/***/ (function(module, exports) {

/* (ignored) */

/***/ }),
/* 66 */
/***/ (function(module, exports) {

/* (ignored) */

/***/ })
/******/ ]);