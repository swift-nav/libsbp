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
var Readable = require('stream').Readable;
var dispatch = require(path.resolve(__dirname, '../sbp/')).dispatch;
var MsgPosLlhDepA = require(path.resolve(__dirname, '../sbp/navigation')).MsgPosLlhDepA;
var MsgVelEcefDepA = require(path.resolve(__dirname, '../sbp/navigation')).MsgVelEcefDepA;

var goodMessage =                   [0x55, 0x02, 0x02, 0xcc, 0x04, 0x14, 0x70, 0x3d, 0xd0, 0x18, 0xcf, 0xef, 0xff, 0xff, 0xef, 0xe8, 0xff, 0xff, 0xf0, 0x18, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x43, 0x94];
var corruptedMessageTooShort =      [0x55, 0x02, 0x02, 0xcc, 0x04, 0x12, 0x70, 0x3d, 0xd0, 0x18, 0xcf, 0xef, 0xff, 0xff, 0xef, 0xe8, 0xff, 0xff, 0xf0, 0x18, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x43, 0x94];
var corruptedMessageTooLong =       [0x55, 0x02, 0x02, 0xcc, 0x04, 0x16, 0x70, 0x3d, 0xd0, 0x18, 0xcf, 0xef, 0xff, 0xff, 0xef, 0xe8, 0xff, 0xff, 0xf0, 0x18, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x43, 0x94];
var corruptedMessageExtraPreamble = [0x55, 0x55, 0x02, 0x02, 0xcc, 0x04, 0x14, 0x70, 0x3d, 0xd0, 0x18, 0xcf, 0xef, 0xff, 0xff, 0xef, 0xe8, 0xff, 0xff, 0xf0, 0x18, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x43, 0x94];

function dispatchee(err, msg) {
  if (msg && msg.fields && msg.fields.tow) {
    this.validMessages++;
  }
  this.msgType = msg.msg_type;
  this.callbacks++;
}

function assertCallbacks(stream, done, validMessages, whitelist, msgType) {
  let ctx = {
    callbacks: 0,
    validMessages: 0,
  };
  dispatch(stream, whitelist, dispatchee.bind(ctx));
  stream.on("end", function () {
    assert.equal(ctx.callbacks, validMessages);
    assert.equal(ctx.validMessages, validMessages);
    if (msgType) {
      assert.equal(ctx.msgType, msgType);
    }
    done();
  });
}

describe('dispatcher', function () {
  it('should read stream of bytes and dispatch callback for single framed message', function (done) {
    var rs = new Readable();
    rs.push(new Buffer(goodMessage));
    rs.push(null);

    assertCallbacks(rs, done, 1);
  });

  it('should read stream of bytes and dispatch callback for two framed message', function (done) {
    var rs = new Readable();
    rs.push(new Buffer(goodMessage));
    rs.push(new Buffer(goodMessage));
    rs.push(null);

    assertCallbacks(rs, done, 2);
  });

  it('should read stream of bytes and dispatch callback for two framed message, with garbage in between', function (done) {
    var rs = new Readable();
    rs.push(new Buffer(goodMessage));
    rs.push(new Buffer([0x54, 0x53, 0x00, 0x01]));
    rs.push(new Buffer(goodMessage));
    rs.push(null);

    assertCallbacks(rs, done, 2);
  });

  it('should read stream of bytes and dispatch callback for three framed messages, with garbage before first message and last', function (done) {
    var rs = new Readable();
    rs.push(new Buffer(goodMessage.slice(2)));
    rs.push(new Buffer(goodMessage));
    rs.push(new Buffer(goodMessage.slice(1)));
    rs.push(new Buffer(goodMessage));
    rs.push(new Buffer(goodMessage.slice(3)));
    rs.push(new Buffer(goodMessage));
    rs.push(new Buffer(goodMessage.slice(4)));
    rs.push(null);

    assertCallbacks(rs, done, 3);
  });

  it('should read stream of bytes and dispatch callback for one valid message, ignore corrupt message', function (done) {
    var rs = new Readable();
    rs.push(new Buffer(corruptedMessageTooShort));
    rs.push(new Buffer(goodMessage));
    rs.push(new Buffer(corruptedMessageTooLong));
    rs.push(null);

    assertCallbacks(rs, done, 1);
  });


  it('should read stream of bytes and dispatch callback for one valid message, ignore corrupt preamble', function (done) {
    var rs = new Readable();
    rs.push(new Buffer(corruptedMessageExtraPreamble));
    rs.push(null);

    let ctx = {
      callbacks: 0,
      validMessages: 0,
    };
    dispatch(rs, dispatchee.bind(ctx));
    rs.on("close", function () {
      // the resume logic in dispatch uses setTimeout
      // See https://swift-nav.atlassian.net/browse/DEVINFRA-507
      setTimeout(function () {
        assert.equal(ctx.validMessages, 1);
        done();
      }, 1);
    });
  });

  it('should whitelist messages properly - no whitelist', function (done) {
    var msgLlhPayload = new Buffer('VQEC9tciFC4nAPod4rrrtkJAE8szxBiLXsAfnaDoenNRQAAAAAAJAOyL', 'base64');
    var msgVelEcefPayload = new Buffer('VQQC9tcUFC4nANoLAACG9f//o/z//wAACQBQ7A==', 'base64');

    var rs = new Readable();
    rs.push(msgLlhPayload);
    rs.push(msgVelEcefPayload);
    rs.push(null);

    assertCallbacks(rs, done, 2);
  });

  it('should whitelist messages properly - array whitelist', function (done) {
    var msgLlhPayload = new Buffer('VQEC9tciFC4nAPod4rrrtkJAE8szxBiLXsAfnaDoenNRQAAAAAAJAOyL', 'base64');
    var msgVelEcefPayload = new Buffer('VQQC9tcUFC4nANoLAACG9f//o/z//wAACQBQ7A==', 'base64');

    var rs = new Readable();
    rs.push(msgVelEcefPayload);
    rs.push(msgLlhPayload);
    rs.push(null);

    const whitelist = [MsgPosLlhDepA.prototype.msg_type]
    assertCallbacks(rs, done, 1, whitelist, MsgPosLlhDepA.prototype.msg_type);
  });

  it('should whitelist messages properly - mask whitelist', function (done) {
    var msgLlhPayload = new Buffer('VQEC9tciFC4nAPod4rrrtkJAE8szxBiLXsAfnaDoenNRQAAAAAAJAOyL', 'base64');
    var msgVelEcefPayload = new Buffer('VQQC9tcUFC4nANoLAACG9f//o/z//wAACQBQ7A==', 'base64');

    var rs = new Readable();
    rs.push(msgVelEcefPayload);
    rs.push(msgLlhPayload);
    rs.push(null);

    const whitelist = ~MsgVelEcefDepA.prototype.msg_type

    assertCallbacks(rs, done, 1, whitelist, MsgPosLlhDepA.prototype.msg_type);
  });

  it('should whitelist messages properly - function whitelist', function (done) {
    var msgLlhPayload = new Buffer('VQEC9tciFC4nAPod4rrrtkJAE8szxBiLXsAfnaDoenNRQAAAAAAJAOyL', 'base64');
    var msgVelEcefPayload = new Buffer('VQQC9tcUFC4nANoLAACG9f//o/z//wAACQBQ7A==', 'base64');

    var rs = new Readable();
    rs.push(msgVelEcefPayload);
    rs.push(msgLlhPayload);
    rs.push(null);

    const whitelist = function (msgType) {
      return msgType === MsgVelEcefDepA.prototype.msg_type;
    };

    assertCallbacks(rs, done, 1, whitelist, MsgVelEcefDepA.prototype.msg_type);
  });
});
