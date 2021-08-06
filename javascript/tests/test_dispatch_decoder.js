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

var fs = require('fs');
var path = require('path');
var assert = require('assert');
var yaml = require('js-yaml');
var Readable = require('stream').Readable;
var dispatch = require(path.resolve(__dirname, '../sbp/')).dispatch;
var utils = require('./utils');

var yamlTestFiles = utils.getYamlTests();

function dispatchee(err, msg) {
  assert.equal(err, null);
  utils.verifyFields(this.testSpec.sbp, msg.sbp);
  utils.verifyFields(this.testSpec.msg.fields, msg.fields);
  this.callbacks++;
  if (this.callbacks === this.expectedCalls) {
    this.done();
  }
}

describe('test packages based on YAML descriptors, through the dispatcher', function () {
  yamlTestFiles.forEach(function (filename) {
    describe(filename, function () {
      var yamlConfig = yaml.safeLoad(fs.readFileSync(filename));
      yamlConfig.tests.map(function (testSpec, i) {
        describe('test spec '+i, function () {
          it('should parse binary sbp and payload', function (done) {
            var rs = new Readable();
            rs.push(new Buffer(testSpec['raw_packet'], 'base64'));
            rs.push(null);
            let ctx = {
              testSpec,
              done,
              expectedCalls: 1,
              callbacks: 0,
            };
            dispatch(rs, dispatchee.bind(ctx));
          });

          it('should parse binary sbp and payload with leading extra preamble', function (done) {
            var rs = new Readable();
            rs.push(new Buffer([0x55]));
            let expectedCalls = 0
            let bufLength = 0;
            while (bufLength < 500) {
              var buf = new Buffer(testSpec['raw_packet'], 'base64');
              rs.push(buf);
              bufLength += buf.length;
              expectedCalls++
            }
            rs.push(null);

            let ctx = {
              testSpec,
              done,
              expectedCalls,
              callbacks: 0,
            };
            dispatch(rs, dispatchee.bind(ctx));
          });

          // For both "corrupt preamble" tests, the corrupt "length" field could be much longer than the actual message.
          // In a real-world case we will have a constant stream of data which will allow us to read that
          //  full length, and reframe after discovering that it's a corrupt preamble.
          // In these cases, we just repeat the message several times to create an arbitrarily long stream.
          it('should parse binary sbp and payload with leading extra preamble (2)', function (done) {
            var rs = new Readable();
            var bigBuf = new Buffer(0);
            let expectedCalls = 0;
            while (bigBuf.length < 500) {
              bigBuf = Buffer.concat([bigBuf, new Buffer(testSpec['raw_packet'], 'base64')]);
              expectedCalls++
            }
            rs.push(Buffer.concat([new Buffer([0x55]), bigBuf]));
            rs.push(null);

            let ctx = {
              testSpec,
              done,
              expectedCalls,
              callbacks: 0,
            };
            dispatch(rs, dispatchee.bind(ctx));
          });

          it('should parse binary sbp and payload with leading truncated message', function (done) {
            var rs = new Readable();
            var packetBuf = new Buffer(testSpec['raw_packet'], 'base64');
            rs.push(packetBuf.slice(0,packetBuf.length-5));

            var requiredCalls = 1;

            // `length` is longer than one full buffer for these corrupted messages
            // similar issue to the above tests
            if (filename.indexOf('test_MsgUartState.yaml') !== -1) {
              requiredCalls = 10;
            }

            var expectedCalls;
            for (expectedCalls = 0; expectedCalls < requiredCalls; expectedCalls++) {
              rs.push(packetBuf);
            }
            rs.push(null);

            let ctx = {
              testSpec,
              done,
              expectedCalls,
              callbacks: 0,
            };
            dispatch(rs, dispatchee.bind(ctx));
          });
        });
      });
    });
  });
});
