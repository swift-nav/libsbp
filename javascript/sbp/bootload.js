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

/**********************
 * Automatically generated from piksi/yaml/swiftnav/sbp/bootload.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages for the bootloading configuration on the device.  Note that some of
 * these messages share the same message type ID for both the host request and the
 * device response.
***********************/

var SBP = require('./sbp');
var Parser = require('binary-parser').Parser;

/**
 * SBP class for message MSG_BOOTLOADER_HANDSHAKE_REQ (0x00B3).
 *
 * The handshake message request from the host establishes a handshake between the
 * device bootloader and the host. The response from the device is
 * MSG_BOOTLOADER_HANDSHAKE_RESP.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBootloaderHandshakeReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BOOTLOADER_HANDSHAKE_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBootloaderHandshakeReq.prototype = Object.create(SBP.prototype);
MsgBootloaderHandshakeReq.prototype.messageType = "MSG_BOOTLOADER_HANDSHAKE_REQ";
MsgBootloaderHandshakeReq.prototype.msg_type = 0x00B3;
MsgBootloaderHandshakeReq.prototype.constructor = MsgBootloaderHandshakeReq;
MsgBootloaderHandshakeReq.prototype.parser = new Parser()
  .endianess('little');
MsgBootloaderHandshakeReq.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_BOOTLOADER_HANDSHAKE_RESP (0x00B4).
 *
 * The handshake message response from the device establishes a handshake between
 * the device bootloader and the host. The request from the host is
 * MSG_BOOTLOADER_HANDSHAKE_REQ.  The payload contains the bootloader version
 * number and the SBP protocol version number.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field flags number (unsigned 32-bit int, 4 bytes) Bootloader flags
 * @field version string Bootloader version number
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBootloaderHandshakeResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BOOTLOADER_HANDSHAKE_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBootloaderHandshakeResp.prototype = Object.create(SBP.prototype);
MsgBootloaderHandshakeResp.prototype.messageType = "MSG_BOOTLOADER_HANDSHAKE_RESP";
MsgBootloaderHandshakeResp.prototype.msg_type = 0x00B4;
MsgBootloaderHandshakeResp.prototype.constructor = MsgBootloaderHandshakeResp;
MsgBootloaderHandshakeResp.prototype.parser = new Parser()
  .endianess('little')
  .uint32('flags')
  .string('version', { greedy: true });
MsgBootloaderHandshakeResp.prototype.fieldSpec = [];
MsgBootloaderHandshakeResp.prototype.fieldSpec.push(['flags', 'writeUInt32LE', 4]);
MsgBootloaderHandshakeResp.prototype.fieldSpec.push(['version', 'string']);

/**
 * SBP class for message MSG_BOOTLOADER_JUMP_TO_APP (0x00B1).
 *
 * The host initiates the bootloader to jump to the application.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field jump number (unsigned 8-bit int, 1 byte) Ignored by the device
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBootloaderJumpToApp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BOOTLOADER_JUMP_TO_APP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBootloaderJumpToApp.prototype = Object.create(SBP.prototype);
MsgBootloaderJumpToApp.prototype.messageType = "MSG_BOOTLOADER_JUMP_TO_APP";
MsgBootloaderJumpToApp.prototype.msg_type = 0x00B1;
MsgBootloaderJumpToApp.prototype.constructor = MsgBootloaderJumpToApp;
MsgBootloaderJumpToApp.prototype.parser = new Parser()
  .endianess('little')
  .uint8('jump');
MsgBootloaderJumpToApp.prototype.fieldSpec = [];
MsgBootloaderJumpToApp.prototype.fieldSpec.push(['jump', 'writeUInt8', 1]);

/**
 * SBP class for message MSG_NAP_DEVICE_DNA_REQ (0x00DE).
 *
 * The device message from the host reads a unique device identifier from the
 * SwiftNAP, an FPGA. The host requests the ID by sending a MSG_NAP_DEVICE_DNA_REQ
 * message. The device responds with a MSG_NAP_DEVICE_DNA_RESP message with the
 * device ID in the payload. Note that this ID is tied to the FPGA, and not related
 * to the Piksi's serial number.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgNapDeviceDnaReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_NAP_DEVICE_DNA_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgNapDeviceDnaReq.prototype = Object.create(SBP.prototype);
MsgNapDeviceDnaReq.prototype.messageType = "MSG_NAP_DEVICE_DNA_REQ";
MsgNapDeviceDnaReq.prototype.msg_type = 0x00DE;
MsgNapDeviceDnaReq.prototype.constructor = MsgNapDeviceDnaReq;
MsgNapDeviceDnaReq.prototype.parser = new Parser()
  .endianess('little');
MsgNapDeviceDnaReq.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_NAP_DEVICE_DNA_RESP (0x00DD).
 *
 * The device message from the host reads a unique device identifier from the
 * SwiftNAP, an FPGA. The host requests the ID by sending a MSG_NAP_DEVICE_DNA_REQ
 * message. The device responds with a MSG_NAP_DEVICE_DNA_RESP messagage with the
 * device ID in the payload. Note that this ID is tied to the FPGA, and not related
 * to the Piksi's serial number.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field dna array 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the right.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgNapDeviceDnaResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_NAP_DEVICE_DNA_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgNapDeviceDnaResp.prototype = Object.create(SBP.prototype);
MsgNapDeviceDnaResp.prototype.messageType = "MSG_NAP_DEVICE_DNA_RESP";
MsgNapDeviceDnaResp.prototype.msg_type = 0x00DD;
MsgNapDeviceDnaResp.prototype.constructor = MsgNapDeviceDnaResp;
MsgNapDeviceDnaResp.prototype.parser = new Parser()
  .endianess('little')
  .array('dna', { length: 8, type: 'uint8' });
MsgNapDeviceDnaResp.prototype.fieldSpec = [];
MsgNapDeviceDnaResp.prototype.fieldSpec.push(['dna', 'array', 'writeUInt8', function () { return 1; }]);

/**
 * SBP class for message MSG_BOOTLOADER_HANDSHAKE_DEP_A (0x00B0).
 *
 * Deprecated.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field handshake array Version number string (not NULL terminated)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgBootloaderHandshakeDepA = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_BOOTLOADER_HANDSHAKE_DEP_A";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgBootloaderHandshakeDepA.prototype = Object.create(SBP.prototype);
MsgBootloaderHandshakeDepA.prototype.messageType = "MSG_BOOTLOADER_HANDSHAKE_DEP_A";
MsgBootloaderHandshakeDepA.prototype.msg_type = 0x00B0;
MsgBootloaderHandshakeDepA.prototype.constructor = MsgBootloaderHandshakeDepA;
MsgBootloaderHandshakeDepA.prototype.parser = new Parser()
  .endianess('little')
  .array('handshake', { type: 'uint8', readUntil: 'eof' });
MsgBootloaderHandshakeDepA.prototype.fieldSpec = [];
MsgBootloaderHandshakeDepA.prototype.fieldSpec.push(['handshake', 'array', 'writeUInt8', function () { return 1; }]);

module.exports = {
  0x00B3: MsgBootloaderHandshakeReq,
  MsgBootloaderHandshakeReq: MsgBootloaderHandshakeReq,
  0x00B4: MsgBootloaderHandshakeResp,
  MsgBootloaderHandshakeResp: MsgBootloaderHandshakeResp,
  0x00B1: MsgBootloaderJumpToApp,
  MsgBootloaderJumpToApp: MsgBootloaderJumpToApp,
  0x00DE: MsgNapDeviceDnaReq,
  MsgNapDeviceDnaReq: MsgNapDeviceDnaReq,
  0x00DD: MsgNapDeviceDnaResp,
  MsgNapDeviceDnaResp: MsgNapDeviceDnaResp,
  0x00B0: MsgBootloaderHandshakeDepA,
  MsgBootloaderHandshakeDepA: MsgBootloaderHandshakeDepA,
}