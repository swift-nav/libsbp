/**
 * Copyright (C) 2016 Swift Navigation Inc.
 * Contact: Joshua Gross <josh@swift-nav.com>
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

var Parser = require('binary-parser').Parser;

/**
 * Add `uint64` to Parser prototype.
 */
Parser.prototype.uint64 = function uint64 (fieldName, options) {
  return this.setNextParser('uint64', fieldName, Object.assign({}, options, {
    formatter: function (recv_time) {
      var UInt64 = require('cuint').UINT64;
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
    var _require = function (x) { if (x === 'cuint') return require('cuint'); throw new Error('Unknown module required: ' + x); };

    // Needed for browser support. Webpack will polyfill Buffer, but we need it to
    // be accessible in this eval'd context.
    if (typeof window !== 'undefined' && typeof window.Buffer === 'undefined') window.Buffer = Buffer;

    return (new Function('buffer', 'callback', 'constructorFn', 'require', compiledCode)).call(this, buffer, callback, constructorFn, _require);
  };
};

module.exports = Parser;
