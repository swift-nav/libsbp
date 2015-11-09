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

var yamlFiles = utils.getYamlSpecs();

describe('test packages based on YAML descriptors, through the dispatcher', function () {
  yamlFiles.map(function (filename) {
    describe(filename, function () {
      var yamlConfig = yaml.safeLoad(fs.readFileSync(filename));
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

          // For both "corrupt preamble" tests, the corrupt "length" field could be much longer than the actual message.
          // In a real-world case we will have a constant stream of data which will allow us to read that
          //  full length, and reframe after discovering that it's a corrupt preamble.
          // In these cases, we just repeat the message several times to create an arbitrarily long stream.
          it('should parse binary sbp and payload with leading extra preamble', function (done) {
            var rs = new Readable();
            rs.push(new Buffer([0x55]));
            rs.push(new Buffer(testSpec['raw_packet'], 'base64'));
            rs.push(new Buffer(testSpec['raw_packet'], 'base64'));
            rs.push(new Buffer(testSpec['raw_packet'], 'base64'));
            rs.push(new Buffer(testSpec['raw_packet'], 'base64'));
            rs.push(new Buffer(testSpec['raw_packet'], 'base64'));
            rs.push(new Buffer(testSpec['raw_packet'], 'base64'));
            rs.push(new Buffer(testSpec['raw_packet'], 'base64'));
            rs.push(null);

            var calls = 0;
            dispatch(rs, function (err, msg) {
              calls++;
              assert.equal(err, null);
              utils.verifyFields(testSpec.sbp, msg.sbp);
              utils.verifyFields(testSpec.msg.fields, msg.fields);
              if (calls === 7) {
                done();
              }
            });
          });

          // For both "corrupt preamble" tests, the corrupt "length" field could be much longer than the actual message.
          // In a real-world case we will have a constant stream of data which will allow us to read that
          //  full length, and reframe after discovering that it's a corrupt preamble.
          // In these cases, we just repeat the message several times to create an arbitrarily long stream.
          it('should parse binary sbp and payload with leading extra preamble (2)', function (done) {
            var rs = new Readable();
            rs.push(Buffer.concat([new Buffer([0x55]),
              new Buffer(testSpec['raw_packet'], 'base64'),
              new Buffer(testSpec['raw_packet'], 'base64'),
              new Buffer(testSpec['raw_packet'], 'base64'),
              new Buffer(testSpec['raw_packet'], 'base64'),
              new Buffer(testSpec['raw_packet'], 'base64'),
              new Buffer(testSpec['raw_packet'], 'base64'),
              new Buffer(testSpec['raw_packet'], 'base64')
            ]));
            rs.push(null);

            var calls = 0;
            dispatch(rs, function (err, msg) {
              calls++;
              assert.equal(err, null);
              utils.verifyFields(testSpec.sbp, msg.sbp);
              utils.verifyFields(testSpec.msg.fields, msg.fields);
              if (calls === 7) {
                done();
              }
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
