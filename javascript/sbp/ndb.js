/**
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/**********************
 * Automatically generated from piksi/yaml/swiftnav/sbp/ndb.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages for logging NDB events.
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;
var GnssSignal = require("./gnss").GnssSignal;
var GnssSignalDep = require("./gnss").GnssSignalDep;
var GPSTime = require("./gnss").GPSTime;
var CarrierPhase = require("./gnss").CarrierPhase;
var GPSTime = require("./gnss").GPSTime;
var GPSTimeSec = require("./gnss").GPSTimeSec;
var GPSTimeDep = require("./gnss").GPSTimeDep;
var SvId = require("./gnss").SvId;

/**
 * SBP class for message MSG_NDB_EVENT (0x0400).
 *
 * This message is sent out when an object is stored into NDB. If needed message
 * could also be sent out when fetching an object from NDB.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field recv_time number (unsigned 64-bit int, 8 bytes) HW time in milliseconds.
 * @field event number (unsigned 8-bit int, 1 byte) Event type.
 * @field object_type number (unsigned 8-bit int, 1 byte) Event object type.
 * @field result number (unsigned 8-bit int, 1 byte) Event result.
 * @field data_source number (unsigned 8-bit int, 1 byte) Data source for STORE event, reserved for other events.
 * @field object_sid GnssSignal GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid indicates
 *   for which signal the object belongs to. Reserved in other cases.
 * @field src_sid GnssSignal GNSS signal identifier, If object_type is Almanac, Almanac WN, Iono OR L2C
 *   capabilities AND data_source is NDB_DS_RECEIVER sid indicates from which SV data
 *   was decoded. Reserved in other cases.
 * @field original_sender number (unsigned 16-bit int, 2 bytes) A unique identifier of the sending hardware. For v1.0, set to the 2 least
 *   significant bytes of the device serial number, valid only if data_source is
 *   NDB_DS_SBP. Reserved in case of other data_source.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgNdbEvent = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_NDB_EVENT";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgNdbEvent.prototype = Object.create(SBP.prototype);
MsgNdbEvent.prototype.messageType = "MSG_NDB_EVENT";
MsgNdbEvent.prototype.msg_type = 0x0400;
MsgNdbEvent.prototype.constructor = MsgNdbEvent;
MsgNdbEvent.prototype.parser = new Parser()
  .endianess('little')
  .uint64('recv_time')
  .uint8('event')
  .uint8('object_type')
  .uint8('result')
  .uint8('data_source')
  .nest('object_sid', { type: GnssSignal.prototype.parser })
  .nest('src_sid', { type: GnssSignal.prototype.parser })
  .uint16('original_sender');
MsgNdbEvent.prototype.fieldSpec = [];
MsgNdbEvent.prototype.fieldSpec.push(['recv_time', 'writeUInt64LE', 8]);
MsgNdbEvent.prototype.fieldSpec.push(['event', 'writeUInt8', 1]);
MsgNdbEvent.prototype.fieldSpec.push(['object_type', 'writeUInt8', 1]);
MsgNdbEvent.prototype.fieldSpec.push(['result', 'writeUInt8', 1]);
MsgNdbEvent.prototype.fieldSpec.push(['data_source', 'writeUInt8', 1]);
MsgNdbEvent.prototype.fieldSpec.push(['object_sid', GnssSignal.prototype.fieldSpec]);
MsgNdbEvent.prototype.fieldSpec.push(['src_sid', GnssSignal.prototype.fieldSpec]);
MsgNdbEvent.prototype.fieldSpec.push(['original_sender', 'writeUInt16LE', 2]);

module.exports = {
  0x0400: MsgNdbEvent,
  MsgNdbEvent: MsgNdbEvent,
}