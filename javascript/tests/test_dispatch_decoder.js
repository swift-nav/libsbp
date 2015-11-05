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

var fs = require('fs');
var path = require('path');
var assert = require('assert');
var yaml = require('js-yaml');
var Readable = require('stream').Readable;
var dispatch = require(path.resolve(__dirname, '../sbp/')).dispatch;
var utils = require('./utils');

var yamlDir = path.resolve(__dirname, '../../spec/tests/yaml/swiftnav/sbp');
var yamlFiles = fs.readdirSync(yamlDir);

describe('test packages based on YAML descriptors, through the dispatcher', function () {
  yamlFiles.map(function (filename) {
    var fullpath = path.resolve(yamlDir, filename);

    describe(filename, function () {
      var yamlConfig = yaml.safeLoad(fs.readFileSync(fullpath));
      yamlConfig.tests.map(function (testSpec, i) {
        describe('test spec '+i, function () {
          it('should parse binary sbp and payload', function (done) {
            var rs = new Readable();
            rs.push(new Buffer(testSpec['raw_packet'], 'base64'));
            rs.push(null);
            dispatch(rs, function (err, msg) {
              assert.equal(err, null);
              utils.verifyFields(testSpec.sbp, msg.sbp);
              utils.verifyFields(testSpec.msg.fields, msg.fields);
              done();
            });
          });

          it('should parse binary sbp and payload with leading extra preamble', function (done) {
            var rs = new Readable();
            rs.push(new Buffer([0x55]));
            rs.push(new Buffer(testSpec['raw_packet'], 'base64'));
            rs.push(null);
            dispatch(rs, function (err, msg) {
              assert.equal(err, null);
              utils.verifyFields(testSpec.sbp, msg.sbp);
              utils.verifyFields(testSpec.msg.fields, msg.fields);
              done();
            });
          });

          it('should parse binary sbp and payload with leading truncated message', function (done) {
            var rs = new Readable();
            var packetBuf = new Buffer(testSpec['raw_packet'], 'base64');
            rs.push(packetBuf.slice(0,packetBuf.length-5));
            rs.push(packetBuf);
            rs.push(null);
            dispatch(rs, function (err, msg) {
              assert.equal(err, null);
              utils.verifyFields(testSpec.sbp, msg.sbp);
              utils.verifyFields(testSpec.msg.fields, msg.fields);
              done();
            });
          });
        });
      });
    });
  });
});
