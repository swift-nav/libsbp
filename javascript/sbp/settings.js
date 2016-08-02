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
 * Automatically generated from piksi/yaml/swiftnav/sbp/settings.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 * Messages for reading and writing the device's device settings.  Note that some
 * of these messages share the same message type ID for both the host request and
 * the device response. See the accompanying document for descriptions of settings
 * configurations and examples:  https://github.com/swift-
 * nav/piksi\_firmware/blob/master/docs/settings.pdf
***********************/

var SBP = require('./sbp');
var Parser = require('binary-parser').Parser;

/**
 * SBP class for message MSG_SETTINGS_SAVE (0x00A1).
 *
 * The save settings message persists the device's current settings configuration
 * to its onboard flash memory file system.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsSave = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_SAVE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsSave.prototype = Object.create(SBP.prototype);
MsgSettingsSave.prototype.messageType = "MSG_SETTINGS_SAVE";
MsgSettingsSave.prototype.msg_type = 0x00A1;
MsgSettingsSave.prototype.constructor = MsgSettingsSave;
MsgSettingsSave.prototype.parser = new Parser()
  .endianess('little');
MsgSettingsSave.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_SETTINGS_WRITE (0x00A0).
 *
 * The setting message writes the device configuration.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field setting string A NULL-terminated and delimited string with contents [SECTION_SETTING, SETTING,
 *   VALUE]. A device will only process to this message when it is received from
 *   sender ID 0x42.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsWrite = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_WRITE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsWrite.prototype = Object.create(SBP.prototype);
MsgSettingsWrite.prototype.messageType = "MSG_SETTINGS_WRITE";
MsgSettingsWrite.prototype.msg_type = 0x00A0;
MsgSettingsWrite.prototype.constructor = MsgSettingsWrite;
MsgSettingsWrite.prototype.parser = new Parser()
  .endianess('little')
  .string('setting', { greedy: true });
MsgSettingsWrite.prototype.fieldSpec = [];
MsgSettingsWrite.prototype.fieldSpec.push(['setting', 'string']);

/**
 * SBP class for message MSG_SETTINGS_READ_REQ (0x00A4).
 *
 * The setting message reads the device configuration.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field setting string A NULL-terminated and delimited string with contents [SECTION_SETTING, SETTING].
 *   A device will only respond to this message when it is received from sender ID
 *   0x42.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsReadReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_READ_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsReadReq.prototype = Object.create(SBP.prototype);
MsgSettingsReadReq.prototype.messageType = "MSG_SETTINGS_READ_REQ";
MsgSettingsReadReq.prototype.msg_type = 0x00A4;
MsgSettingsReadReq.prototype.constructor = MsgSettingsReadReq;
MsgSettingsReadReq.prototype.parser = new Parser()
  .endianess('little')
  .string('setting', { greedy: true });
MsgSettingsReadReq.prototype.fieldSpec = [];
MsgSettingsReadReq.prototype.fieldSpec.push(['setting', 'string']);

/**
 * SBP class for message MSG_SETTINGS_READ_RESP (0x00A5).
 *
 * The setting message reads the device configuration.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field setting string A NULL-terminated and delimited string with contents [SECTION_SETTING, SETTING,
 *   VALUE].
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsReadResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_READ_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsReadResp.prototype = Object.create(SBP.prototype);
MsgSettingsReadResp.prototype.messageType = "MSG_SETTINGS_READ_RESP";
MsgSettingsReadResp.prototype.msg_type = 0x00A5;
MsgSettingsReadResp.prototype.constructor = MsgSettingsReadResp;
MsgSettingsReadResp.prototype.parser = new Parser()
  .endianess('little')
  .string('setting', { greedy: true });
MsgSettingsReadResp.prototype.fieldSpec = [];
MsgSettingsReadResp.prototype.fieldSpec.push(['setting', 'string']);

/**
 * SBP class for message MSG_SETTINGS_READ_BY_INDEX_REQ (0x00A2).
 *
 * The settings message for iterating through the settings values. It will read the
 * setting at an index, returning a NULL-terminated and delimited string with
 * contents [SECTION_SETTING, SETTING, VALUE]. A device will only respond to this
 * message when it is received from sender ID 0x42.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field index number (unsigned 16-bit int, 2 bytes) An index into the device settings, with values ranging from 0 to
 *   length(settings)
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsReadByIndexReq = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_READ_BY_INDEX_REQ";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsReadByIndexReq.prototype = Object.create(SBP.prototype);
MsgSettingsReadByIndexReq.prototype.messageType = "MSG_SETTINGS_READ_BY_INDEX_REQ";
MsgSettingsReadByIndexReq.prototype.msg_type = 0x00A2;
MsgSettingsReadByIndexReq.prototype.constructor = MsgSettingsReadByIndexReq;
MsgSettingsReadByIndexReq.prototype.parser = new Parser()
  .endianess('little')
  .uint16('index');
MsgSettingsReadByIndexReq.prototype.fieldSpec = [];
MsgSettingsReadByIndexReq.prototype.fieldSpec.push(['index', 'writeUInt16LE', 2]);

/**
 * SBP class for message MSG_SETTINGS_READ_BY_INDEX_RESP (0x00A7).
 *
 * The settings message for iterating through the settings values. It will read the
 * setting at an index, returning a NULL-terminated and delimited string with
 * contents [SECTION_SETTING, SETTING, VALUE].
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field index number (unsigned 16-bit int, 2 bytes) An index into the device settings, with values ranging from 0 to
 *   length(settings)
 * @field setting string A NULL-terminated and delimited string with contents [SECTION_SETTING, SETTING,
 *   VALUE].
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsReadByIndexResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_READ_BY_INDEX_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsReadByIndexResp.prototype = Object.create(SBP.prototype);
MsgSettingsReadByIndexResp.prototype.messageType = "MSG_SETTINGS_READ_BY_INDEX_RESP";
MsgSettingsReadByIndexResp.prototype.msg_type = 0x00A7;
MsgSettingsReadByIndexResp.prototype.constructor = MsgSettingsReadByIndexResp;
MsgSettingsReadByIndexResp.prototype.parser = new Parser()
  .endianess('little')
  .uint16('index')
  .string('setting', { greedy: true });
MsgSettingsReadByIndexResp.prototype.fieldSpec = [];
MsgSettingsReadByIndexResp.prototype.fieldSpec.push(['index', 'writeUInt16LE', 2]);
MsgSettingsReadByIndexResp.prototype.fieldSpec.push(['setting', 'string']);

/**
 * SBP class for message MSG_SETTINGS_READ_BY_INDEX_DONE (0x00A6).
 *
 * The settings message for indicating end of the settings values.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsReadByIndexDone = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_READ_BY_INDEX_DONE";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsReadByIndexDone.prototype = Object.create(SBP.prototype);
MsgSettingsReadByIndexDone.prototype.messageType = "MSG_SETTINGS_READ_BY_INDEX_DONE";
MsgSettingsReadByIndexDone.prototype.msg_type = 0x00A6;
MsgSettingsReadByIndexDone.prototype.constructor = MsgSettingsReadByIndexDone;
MsgSettingsReadByIndexDone.prototype.parser = new Parser()
  .endianess('little');
MsgSettingsReadByIndexDone.prototype.fieldSpec = [];

/**
 * SBP class for message MSG_SETTINGS_REGISTER (0x00AE).
 *
 * This message registers the presence and default value of a setting with a
 * settings daemon.  The host should reply with MSG_SETTINGS_WRITE for this setting
 * to set the initial value.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field setting string A NULL-terminated and delimited string with contents [SECTION_SETTING, SETTING,
 *   VALUE].
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsRegister = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_REGISTER";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsRegister.prototype = Object.create(SBP.prototype);
MsgSettingsRegister.prototype.messageType = "MSG_SETTINGS_REGISTER";
MsgSettingsRegister.prototype.msg_type = 0x00AE;
MsgSettingsRegister.prototype.constructor = MsgSettingsRegister;
MsgSettingsRegister.prototype.parser = new Parser()
  .endianess('little')
  .string('setting', { greedy: true });
MsgSettingsRegister.prototype.fieldSpec = [];
MsgSettingsRegister.prototype.fieldSpec.push(['setting', 'string']);

module.exports = {
  0x00A1: MsgSettingsSave,
  MsgSettingsSave: MsgSettingsSave,
  0x00A0: MsgSettingsWrite,
  MsgSettingsWrite: MsgSettingsWrite,
  0x00A4: MsgSettingsReadReq,
  MsgSettingsReadReq: MsgSettingsReadReq,
  0x00A5: MsgSettingsReadResp,
  MsgSettingsReadResp: MsgSettingsReadResp,
  0x00A2: MsgSettingsReadByIndexReq,
  MsgSettingsReadByIndexReq: MsgSettingsReadByIndexReq,
  0x00A7: MsgSettingsReadByIndexResp,
  MsgSettingsReadByIndexResp: MsgSettingsReadByIndexResp,
  0x00A6: MsgSettingsReadByIndexDone,
  MsgSettingsReadByIndexDone: MsgSettingsReadByIndexDone,
  0x00AE: MsgSettingsRegister,
  MsgSettingsRegister: MsgSettingsRegister,
}