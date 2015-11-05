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

var assert = require('assert');

module.exports = {
  verifyFields: function (spec, msg) {
    for (var k in spec) {
      var v = spec[k];

      if (v.indexOf && v.indexOf('0x') === 0) {
        v = parseInt(v);
      }
      if (typeof v === 'string' && msg[k] instanceof Buffer) {
        v = new Buffer(v, 'base64');
      }

      if (msg[k] instanceof Buffer && v.compare) {
        assert.equal(v.compare(msg[k]), 0); // Node v4ish
      } else if (msg[k] instanceof Buffer) {
        assert.equal(v.toString(), msg[k].toString()); // Node v0.10ish
      } else {
        assert.deepEqual(v, msg[k]);
      }
    }
  }
};
