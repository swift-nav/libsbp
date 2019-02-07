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
 * Automatically generated from piksi/yaml/swiftnav/sbp/settings.yaml with generate.py.
 * Don't edit this by hand!
 **********************
 * Package description:
 *
 *  Messages for reading, writing, and discovering device settings. Settings with a
 * "string" field have multiple values in this field delimited with a null
 * character (the c style null terminator).  For instance, when querying the
 * 'firmware_version' setting in the 'system_info' section, the following array of
 * characters needs to be sent for the string field in MSG_SETTINGS_READ:
 * "system_info\0firmware_version\0", where the delimiting  null characters are
 * specified with the escape sequence '\0' and all quotation marks should be
 * omitted.    In the message descriptions below, the generic strings
 * SECTION_SETTING and SETTING are used to refer to the two strings that comprise
 * the identifier of an individual setting.In firmware_version example above,
 * SECTION_SETTING is the 'system_info', and the SETTING portion is
 * 'firmware_version'.   See the "Software Settings Manual" on support.swiftnav.com
 * for detailed documentation about all settings and sections available for each
 * Swift firmware version. Settings manuals are available for each firmware version
 * at the following link:
 * https://support.swiftnav.com/customer/en/portal/articles/2628580-piksi-multi-
 * specifications#settings. The latest settings document is also available at the
 * following link:  http://swiftnav.com/latest/piksi-multi-settings . See lastly
 * https://github.com/swift-nav/piksi_tools/blob/master/piksi_tools/settings.py ,
 * the open source python command line utility for reading, writing, and saving
 * settings in the piksi_tools repository on github as a helpful reference and
 * example.
***********************/

var SBP = require('./sbp');
var Parser = require('./parser');
var Int64 = require('node-int64');
var UInt64 = require('cuint').UINT64;

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
 * The setting message writes the device configuration for a particular setting via
 * A NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes  the
 * NULL character and where quotation marks are omitted. A device will only process
 * to this message when it is received from sender ID 0x42. An example string that
 * could be sent to a device is "solution\0soln_freq\010\0".
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field setting string A NULL-terminated and NULL-delimited string with contents
 *   "SECTION_SETTING\0SETTING\0VALUE\0"
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
MsgSettingsWrite.prototype.fieldSpec.push(['setting', 'string', null]);

/**
 * SBP class for message MSG_SETTINGS_WRITE_RESP (0x00AF).
 *
 * Return the status of a write request with the new value of the setting.  If the
 * requested value is rejected, the current value will be returned. The string
 * field is a NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes the
 * NULL character and where quotation marks are omitted. An example string that
 * could be sent from device is "solution\0soln_freq\010\0".
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field status number (unsigned 8-bit int, 1 byte) Write status
 * @field setting string A NULL-terminated and delimited string with contents
 *   "SECTION_SETTING\0SETTING\0VALUE\0"
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsWriteResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_WRITE_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsWriteResp.prototype = Object.create(SBP.prototype);
MsgSettingsWriteResp.prototype.messageType = "MSG_SETTINGS_WRITE_RESP";
MsgSettingsWriteResp.prototype.msg_type = 0x00AF;
MsgSettingsWriteResp.prototype.constructor = MsgSettingsWriteResp;
MsgSettingsWriteResp.prototype.parser = new Parser()
  .endianess('little')
  .uint8('status')
  .string('setting', { greedy: true });
MsgSettingsWriteResp.prototype.fieldSpec = [];
MsgSettingsWriteResp.prototype.fieldSpec.push(['status', 'writeUInt8', 1]);
MsgSettingsWriteResp.prototype.fieldSpec.push(['setting', 'string', null]);

/**
 * SBP class for message MSG_SETTINGS_READ_REQ (0x00A4).
 *
 * The setting message that reads the device configuration. The string field is a
 * NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the NULL
 * character and where quotation marks are omitted. An example string that could be
 * sent to a device is "solution\0soln_freq\0". A device will only respond to this
 * message when it is received from sender ID 0x42. A device should respond with a
 * MSG_SETTINGS_READ_RESP message (msg_id 0x00A5).
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field setting string A NULL-terminated and NULL-delimited string with contents
 *   "SECTION_SETTING\0SETTING\0"
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
MsgSettingsReadReq.prototype.fieldSpec.push(['setting', 'string', null]);

/**
 * SBP class for message MSG_SETTINGS_READ_RESP (0x00A5).
 *
 * The setting message wich which the device responds after a MSG_SETTING_READ_REQ
 * is sent to device. The string field is a NULL-terminated and NULL-delimited
 * string with contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape
 * sequence denotes the NULL character and where quotation marks are omitted. An
 * example string that could be sent from device is "solution\0soln_freq\010\0".
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field setting string A NULL-terminated and NULL-delimited string with contents
 *   "SECTION_SETTING\0SETTING\0VALUE\0"
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
MsgSettingsReadResp.prototype.fieldSpec.push(['setting', 'string', null]);

/**
 * SBP class for message MSG_SETTINGS_READ_BY_INDEX_REQ (0x00A2).
 *
 * The settings message for iterating through the settings values. A device will
 * respond to this message with a  "MSG_SETTINGS_READ_BY_INDEX_RESP".
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
 * The settings message that reports the value of a setting at an index.  In the
 * string field, it reports NULL-terminated and delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where the '\0' escape sequence
 * denotes the NULL character and where quotation marks are omitted. The
 * FORMAT_TYPE field is optional and denotes possible string values of the setting
 * as a hint to the user. If included, the format type portion of the string has
 * the format "enum:value1,value2,value3". An example string that could be sent
 * from the device is "simulator\0enabled\0True\0enum:True,False\0"
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field index number (unsigned 16-bit int, 2 bytes) An index into the device settings, with values ranging from 0 to
 *   length(settings)
 * @field setting string A NULL-terminated and delimited string with contents
 *   "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
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
MsgSettingsReadByIndexResp.prototype.fieldSpec.push(['setting', 'string', null]);

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
 * @field setting string A NULL-terminated and delimited string with contents
 *   "SECTION_SETTING\0SETTING\0VALUE".
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
MsgSettingsRegister.prototype.fieldSpec.push(['setting', 'string', null]);

/**
 * SBP class for message MSG_SETTINGS_REGISTER_RESP (0x01AF).
 *
 * This message responds to setting registration with the effective value. The
 * effective value shall differ from the given default value if setting was already
 * registered or is available in the permanent setting storage and had a different
 * value.
 *
 * Fields in the SBP payload (`sbp.payload`):
 * @field status number (unsigned 8-bit int, 1 byte) Register status
 * @field setting string A NULL-terminated and delimited string with contents
 *   "SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined according to
 *   the status field.
 *
 * @param sbp An SBP object with a payload to be decoded.
 */
var MsgSettingsRegisterResp = function (sbp, fields) {
  SBP.call(this, sbp);
  this.messageType = "MSG_SETTINGS_REGISTER_RESP";
  this.fields = (fields || this.parser.parse(sbp.payload));

  return this;
};
MsgSettingsRegisterResp.prototype = Object.create(SBP.prototype);
MsgSettingsRegisterResp.prototype.messageType = "MSG_SETTINGS_REGISTER_RESP";
MsgSettingsRegisterResp.prototype.msg_type = 0x01AF;
MsgSettingsRegisterResp.prototype.constructor = MsgSettingsRegisterResp;
MsgSettingsRegisterResp.prototype.parser = new Parser()
  .endianess('little')
  .uint8('status')
  .string('setting', { greedy: true });
MsgSettingsRegisterResp.prototype.fieldSpec = [];
MsgSettingsRegisterResp.prototype.fieldSpec.push(['status', 'writeUInt8', 1]);
MsgSettingsRegisterResp.prototype.fieldSpec.push(['setting', 'string', null]);

module.exports = {
  0x00A1: MsgSettingsSave,
  MsgSettingsSave: MsgSettingsSave,
  0x00A0: MsgSettingsWrite,
  MsgSettingsWrite: MsgSettingsWrite,
  0x00AF: MsgSettingsWriteResp,
  MsgSettingsWriteResp: MsgSettingsWriteResp,
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
  0x01AF: MsgSettingsRegisterResp,
  MsgSettingsRegisterResp: MsgSettingsRegisterResp,
}