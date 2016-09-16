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
var Readable = require('stream').Readable;
var dispatch = require(path.resolve(__dirname, '../sbp/')).dispatch;
var MsgPosLlh = require(path.resolve(__dirname, '../sbp/navigation')).MsgPosLlh;
var MsgVelEcef = require(path.resolve(__dirname, '../sbp/navigation')).MsgVelEcef;

var framedMessage =                 [0x55, 0x02, 0x02, 0xcc, 0x04, 0x14, 0x70, 0x3d, 0xd0, 0x18, 0xcf, 0xef, 0xff, 0xff, 0xef, 0xe8, 0xff, 0xff, 0xf0, 0x18, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x43, 0x94];
var corruptedMessageTooShort =      [0x55, 0x02, 0x02, 0xcc, 0x04, 0x12, 0x70, 0x3d, 0xd0, 0x18, 0xcf, 0xef, 0xff, 0xff, 0xef, 0xe8, 0xff, 0xff, 0xf0, 0x18, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x43, 0x94];
var corruptedMessageTooLong =       [0x55, 0x02, 0x02, 0xcc, 0x04, 0x16, 0x70, 0x3d, 0xd0, 0x18, 0xcf, 0xef, 0xff, 0xff, 0xef, 0xe8, 0xff, 0xff, 0xf0, 0x18, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x43, 0x94];
var corruptedMessageExtraPreamble = [0x55, 0x55, 0x02, 0x02, 0xcc, 0x04, 0x14, 0x70, 0x3d, 0xd0, 0x18, 0xcf, 0xef, 0xff, 0xff, 0xef, 0xe8, 0xff, 0xff, 0xf0, 0x18, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x43, 0x94];

describe('dispatcher', function () {
  it('should read stream of bytes and dispatch callback for single framed message', function (done) {
    var rs = new Readable();
    rs.push(new Buffer(framedMessage));
    rs.push(null);

    var callbacks = 0;
    var validMessages = 0;
    dispatch(rs, function (err, framedMessage) {
      if (framedMessage && framedMessage.fields && framedMessage.fields.tow) {
        validMessages++;
      }
      if ((++callbacks) === 1) {
        assert.equal(validMessages, 1);
        done();
      }
    });
  });

  it('should read stream of bytes and dispatch callback for two framed message', function (done) {
    var rs = new Readable();
    rs.push(new Buffer(framedMessage));
    rs.push(new Buffer(framedMessage));
    rs.push(null);

    var callbacks = 0;
    var validMessages = 0;
    dispatch(rs, function (err, framedMessage) {
      if (framedMessage && framedMessage.fields && framedMessage.fields.tow) {
        validMessages++;
      }
      if ((++callbacks) === 2) {
        assert.equal(validMessages, 2);
        done();
      }
    });
  });

  it('should read stream of bytes and dispatch callback for two framed message, with garbage in between', function (done) {
    var rs = new Readable();
    rs.push(new Buffer(framedMessage));
    rs.push(new Buffer([0x54, 0x53, 0x00, 0x01]));
    rs.push(new Buffer(framedMessage));
    rs.push(null);

    var callbacks = 0;
    var validMessages = 0;
    dispatch(rs, function (err, framedMessage) {
      if (framedMessage && framedMessage.fields && framedMessage.fields.tow) {
        validMessages++;
      }
      if ((++callbacks) === 2) {
        assert.equal(validMessages, 2);
        done();
      }
    });
  });

  it('should read stream of bytes and dispatch callback for three framed messages, with garbage before first message and last', function (done) {
    var rs = new Readable();
    rs.push(new Buffer(framedMessage.slice(2)));
    rs.push(new Buffer(framedMessage));
    rs.push(new Buffer(framedMessage.slice(1)));
    rs.push(new Buffer(framedMessage));
    rs.push(new Buffer(framedMessage.slice(3)));
    rs.push(new Buffer(framedMessage));
    rs.push(new Buffer(framedMessage.slice(4)));
    rs.push(null);

    var callbacks = 0;
    var validMessages = 0;
    dispatch(rs, function (err, framedMessage) {
      if (framedMessage && framedMessage.fields && framedMessage.fields.tow) {
        validMessages++;
      }
      if ((++callbacks) === 3) {
        assert.equal(validMessages, 3);
        done();
      }
    });
  });

  it('should read stream of bytes and dispatch callback for one valid message, ignore corrupt message', function (done) {
    var rs = new Readable();
    rs.push(new Buffer(corruptedMessageTooShort));
    rs.push(new Buffer(framedMessage));
    rs.push(new Buffer(corruptedMessageTooLong));
    rs.push(null);

    var callbacks = 0;
    var validMessages = 0;
    dispatch(rs, function (err, framedMessage) {
      if (framedMessage && framedMessage.fields && framedMessage.fields.tow) {
        validMessages++;
      }
      if ((++callbacks) === 1) {
        assert.equal(validMessages, 1);
        done();
      }
    });
  });


  it('should read stream of bytes and dispatch callback for one valid message, ignore corrupt preamble', function (done) {
    var rs = new Readable();
    rs.push(new Buffer(corruptedMessageExtraPreamble));
    rs.push(null);

    var callbacks = 0;
    var validMessages = 0;
    dispatch(rs, function (err, framedMessage) {
      if (framedMessage && framedMessage.fields && framedMessage.fields.tow) {
        validMessages++;
      }
      if ((++callbacks) === 1) {
        assert.equal(validMessages, 1);
        done();
      }
    });
  });

  it('should whitelist messages properly - no whitelist', function (done) {
    var msgLlhPayload = new Buffer('VQEC9tciFC4nAPod4rrrtkJAE8szxBiLXsAfnaDoenNRQAAAAAAJAOyL', 'base64');
    var msgVelEcefPayload = new Buffer('VQQC9tcUFC4nANoLAACG9f//o/z//wAACQBQ7A==', 'base64');

    var rs = new Readable();
    rs.push(msgLlhPayload);
    rs.push(msgVelEcefPayload);
    rs.push(null);

    var callbacks = 0;
    var validMessages = 0;
    dispatch(rs, function (err, framedMessage) {
      if (framedMessage && framedMessage.fields && framedMessage.fields.tow) {
        validMessages++;
      }
      if ((++callbacks) === 2) {
        assert.equal(validMessages, 2);
        done();
      }
    });
  });

  it('should whitelist messages properly - array whitelist', function (done) {
    var msgLlhPayload = new Buffer('VQEC9tciFC4nAPod4rrrtkJAE8szxBiLXsAfnaDoenNRQAAAAAAJAOyL', 'base64');
    var msgVelEcefPayload = new Buffer('VQQC9tcUFC4nANoLAACG9f//o/z//wAACQBQ7A==', 'base64');

    var rs = new Readable();
    rs.push(msgVelEcefPayload);
    rs.push(msgLlhPayload);
    rs.push(null);

    var callbacks = 0;
    var validMessages = 0;
    dispatch(rs, [MsgPosLlh.prototype.msg_type], function (err, framedMessage) {
      assert.equal(framedMessage.msg_type, MsgPosLlh.prototype.msg_type);
      if (framedMessage && framedMessage.fields && framedMessage.fields.tow) {
        validMessages++;
      }
      if ((++callbacks) === 1) {
        assert.equal(validMessages, 1);
        done();
      }
    });
  });

  it('should whitelist messages properly - mask whitelist', function (done) {
    var msgLlhPayload = new Buffer('VQEC9tciFC4nAPod4rrrtkJAE8szxBiLXsAfnaDoenNRQAAAAAAJAOyL', 'base64');
    var msgVelEcefPayload = new Buffer('VQQC9tcUFC4nANoLAACG9f//o/z//wAACQBQ7A==', 'base64');

    var rs = new Readable();
    rs.push(msgVelEcefPayload);
    rs.push(msgLlhPayload);
    rs.push(null);

    var callbacks = 0;
    var validMessages = 0;
    dispatch(rs, ~MsgVelEcef.prototype.msg_type, function (err, framedMessage) {
      assert.equal(framedMessage.msg_type, MsgPosLlh.prototype.msg_type);
      if (framedMessage && framedMessage.fields && framedMessage.fields.tow) {
        validMessages++;
      }
      if ((++callbacks) === 1) {
        assert.equal(validMessages, 1);
        done();
      }
    });
  });

  it('should whitelist messages properly - function whitelist', function (done) {
    var msgLlhPayload = new Buffer('VQEC9tciFC4nAPod4rrrtkJAE8szxBiLXsAfnaDoenNRQAAAAAAJAOyL', 'base64');
    var msgVelEcefPayload = new Buffer('VQQC9tcUFC4nANoLAACG9f//o/z//wAACQBQ7A==', 'base64');

    var rs = new Readable();
    rs.push(msgVelEcefPayload);
    rs.push(msgLlhPayload);
    rs.push(null);

    var callbacks = 0;
    var validMessages = 0;
    var whitelist = function (msgType) {
      return msgType === MsgVelEcef.prototype.msg_type;
    };
    dispatch(rs, whitelist, function (err, framedMessage) {
      assert.equal(framedMessage.msg_type, MsgVelEcef.prototype.msg_type);
      if (framedMessage && framedMessage.fields && framedMessage.fields.tow) {
        validMessages++;
      }
      if ((++callbacks) === 1) {
        assert.equal(validMessages, 1);
        done();
      }
    });
  });
});
