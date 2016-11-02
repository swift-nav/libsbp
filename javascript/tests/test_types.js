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
var decode = require(path.resolve(__dirname, '../sbp/')).decode;
var messageTypesTable = require(path.resolve(__dirname, '../sbp/')).sbpMessageTypesTable;
var constructMsg = require(path.resolve(__dirname, '../sbp/construct'));
var utils = require('./utils');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;

function getFieldValuesFromSpecType (fieldType, line, previousValues) {
  if (Array.isArray(fieldType)) {
    return getFieldValuesFromSpec(fieldType);
  } else if (fieldType === 'writeFloatLE') {
    return (Math.random()*1000000) + Math.random();
  } else if (fieldType === 'writeDoubleLE') {
    return (Math.random()*1000000) + Math.random();
  } else if (fieldType === 'writeInt32LE') {
    return Math.floor(Math.random() * (Math.pow(2, 31) - 1)) * (Math.random() > 0.5 ? 1 : -1);
  } else if (fieldType === 'writeInt16LE') {
    return Math.floor(Math.random() * (Math.pow(2, 15) - 1)) * (Math.random() > 0.5 ? 1 : -1);
  } else if (fieldType === 'writeUInt64LE') {
    var int1 = Math.floor(Math.random() * (Math.pow(2, 24) - 1));
    var int2 = Math.floor(Math.random() * (Math.pow(2, 24) - 1));
    return new UInt64(int1, int2);
  } else if (fieldType === 'writeUInt32LE') {
    return Math.floor(Math.random() * (Math.pow(2, 32) - 1));
  } else if (fieldType === 'writeUInt16LE') {
    return Math.floor(Math.random() * (Math.pow(2, 16) - 1));
  } else if (fieldType === 'writeInt8') {
    return Math.floor(Math.random() * (Math.pow(2, 7) - 1)) * (Math.random() > 0.5 ? 1 : -1);
  } else if (fieldType === 'writeUInt8') {
    // we keep uint8s artificially small, because they often represent lengths of arrays
    return Math.floor(Math.random() * 10);
  } else if (fieldType === 'string') {
    var strLength = line[2];
    if (!strLength) {
      return 'foobar';
    }

    var str = '';
    for (var i = 0; i < strLength; i++) {
      str += 'x';
    }
    return str;
  } else if (fieldType === 'array') {
    var sizeField = line[4];
    var randomSize = (Math.floor(Math.random() * 3) + 2);
    var numElements = (typeof sizeField === 'number' ? sizeField : (typeof sizeField === 'string' ? previousValues[sizeField] : randomSize));
    var elements = [];
    for (var i = 0; i < numElements; i++) {
      elements.push(getFieldValuesFromSpecType(line[2]));
    }
    return elements;
  } else {
    throw new Error('unknown type: ' + fieldType);
  }
}

function getFieldValuesFromSpec (spec) {
  return spec.reduce(function (acc, line) {
    var fieldName = line[0];
    var fieldType = line[1];

    acc[fieldName] = getFieldValuesFromSpecType(fieldType, line, acc);

    return acc;
  }, {});
}

function assertFieldsMatch (spec, fields1, fields2) {
  spec.forEach(function (fieldSpec) {
    var fieldName = fieldSpec[0];
    var fieldType = fieldSpec[1];

    var v1 = fields1[fieldName];
    var v2 = fields2[fieldName];

    assert(typeof v1 !== 'undefined');
    assert(typeof v2 !== 'undefined');

    if (Array.isArray(fieldType)) {
      return assertFieldsMatch(fieldType, v1, v2);
    } else if (fieldType === 'array') {
    } else if (fieldType.toLowerCase().indexOf('float') !== -1 || fieldType.toLowerCase().indexOf('float') !== -1) {
    } else if (fieldType === 'writeUInt64LE') {
      assert.equal(v1.toString(), v2.toString());
    } else {
      assert.equal(v1, v2);
    }
  });
}

describe('test packages based on descriptors of types', function () {
  var testMsgTypes = Object.keys(messageTypesTable).filter(function (msgType) {
    return (
      // this message type has a greedy string followed by a greedy array, which is hard to test well
      msgType !== 'MSG_FILEIO_WRITE_REQ'
    );
 });

  testMsgTypes.forEach(function (k) {
    it('should test ' + k, function () {
      var msgLabel = k;
      var msgConstructor = messageTypesTable[k];
      if (!msgConstructor.prototype.msg_type) {
        return;
      }

      var fieldSpec = msgConstructor.prototype.fieldSpec;
      var fields = getFieldValuesFromSpec(fieldSpec);
      var msg = constructMsg(msgConstructor, fields);

      // decode msg from binary
      var decoded = decode(msg.toBuffer());
      var decodedFields = decoded.fields;

      // compare fields
      assertFieldsMatch(fieldSpec, fields, decodedFields);
    });
  });
});
