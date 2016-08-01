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
var path = require('path');
var constructMsg = require(path.resolve(__dirname, '../sbp/construct'));
var sbpPiksi = require(path.resolve(__dirname, '../sbp/piksi'));
var MsgReset = sbpPiksi.MsgReset;

var decode = require(path.resolve(__dirname, '../sbp/')).decode;

describe('encode and decode a MSG_RESET message', function () {
  it('should encode, and round-trip a MSG_RESET message', function () {
    var msg = constructMsg(MsgReset, {});
    var msgBuffer = msg.toBuffer();

    assert(msgBuffer instanceof Buffer);
    assert(msgBuffer.equals(decode(msgBuffer).toBuffer()));
  });
});
