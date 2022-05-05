/**
 * Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swift-nav.com>
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

var assert = require('assert');
var path = require('path');
var fs = require('fs');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;

function walkYAML (dir) {
  var results = [];
  var list = fs.readdirSync(dir);
  list.forEach(function(file) {
    file = dir + '/' + file;
    var stat = fs.statSync(file);
    if (stat && stat.isDirectory()) {
      results = results.concat(walkYAML(file));
    } else if (file.match(/\.yaml$/)) {
      results.push(path.resolve(dir, file));
    }
  });
  return results;
}

function fieldEq(p, e) {
  if (typeof p == 'object' && typeof e == 'object') {
    for (const property in p) {
      fieldEq(p[property], e[property]);
    }
  } else {
    assert.equal(p, e);
  }
}

module.exports = {
  getYamlTests: function () {
    return walkYAML(path.resolve(__dirname, '../../spec/tests/yaml'));
  },
  getYamlSpecs: function () {
    return walkYAML(path.resolve(__dirname, '../../spec/yaml/swiftnav/sbp'));
  },
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
      } else if (msg[k] instanceof UInt64) {
        assert.equal(msg[k].toString(), ''+v);
      } else {
        fieldEq(v, msg[k]);
      }
    }
  }
};
