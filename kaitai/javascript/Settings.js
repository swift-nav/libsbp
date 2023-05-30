// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Settings = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Settings = (function() {
  function Settings(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Settings.prototype._read = function() {
  }

  /**
   * The setting message with which the device responds after a
   * MSG_SETTING_READ_REQ is sent to device. The string field is a NULL-
   * terminated and NULL-delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
   * denotes the NULL character and where quotation marks are omitted. An
   * example string that could be sent from device is
   * "solution\0soln_freq\010\0".
   */

  var MsgSettingsReadResp = Settings.MsgSettingsReadResp = (function() {
    function MsgSettingsReadResp(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSettingsReadResp.prototype._read = function() {
      this.setting = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * A NULL-terminated and NULL-delimited string with contents
     * "SECTION_SETTING\0SETTING\0VALUE\0"
     */

    return MsgSettingsReadResp;
  })();

  /**
   * Return the status of a write request with the new value of the setting.
   * If the requested value is rejected, the current value will be returned.
   * The string field is a NULL-terminated and NULL-delimited string with
   * contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape
   * sequence denotes the NULL character and where quotation marks are
   * omitted. An example string that could be sent from device is
   * "solution\0soln_freq\010\0".
   */

  var MsgSettingsWriteResp = Settings.MsgSettingsWriteResp = (function() {
    function MsgSettingsWriteResp(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSettingsWriteResp.prototype._read = function() {
      this.status = this._io.readU1();
      this.setting = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * Write status
     */

    /**
     * A NULL-terminated and delimited string with contents
     * "SECTION_SETTING\0SETTING\0VALUE\0"
     */

    return MsgSettingsWriteResp;
  })();

  /**
   * This message responds to setting registration with the effective value.
   * The effective value shall differ from the given default value if setting
   * was already registered or is available in the permanent setting storage
   * and had a different value.
   */

  var MsgSettingsRegisterResp = Settings.MsgSettingsRegisterResp = (function() {
    function MsgSettingsRegisterResp(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSettingsRegisterResp.prototype._read = function() {
      this.status = this._io.readU1();
      this.setting = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * Register status
     */

    /**
     * A NULL-terminated and delimited string with contents
     * "SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
     * according to the status field.
     */

    return MsgSettingsRegisterResp;
  })();

  /**
   * The settings message that reports the value of a setting at an index.
   * 
   * In the string field, it reports NULL-terminated and delimited string
   * with contents "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where
   * the '\0' escape sequence denotes the NULL character and where quotation
   * marks are omitted. The FORMAT_TYPE field is optional and denotes
   * possible string values of the setting as a hint to the user. If
   * included, the format type portion of the string has the format
   * "enum:value1,value2,value3". An example string that could be sent from
   * the device is "simulator\0enabled\0True\0enum:True,False\0".
   */

  var MsgSettingsReadByIndexResp = Settings.MsgSettingsReadByIndexResp = (function() {
    function MsgSettingsReadByIndexResp(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSettingsReadByIndexResp.prototype._read = function() {
      this.index = this._io.readU2le();
      this.setting = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * An index into the device settings, with values ranging from 0 to
     * length(settings)
     */

    /**
     * A NULL-terminated and delimited string with contents
     * "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
     */

    return MsgSettingsReadByIndexResp;
  })();

  /**
   * The setting message that reads the device configuration. The string
   * field is a NULL-terminated and NULL-delimited string with contents
   * "SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the
   * NULL character and where quotation marks are omitted. An example string
   * that could be sent to a device is "solution\0soln_freq\0". A device will
   * only respond to this message when it is received from sender ID 0x42. A
   * device should respond with a MSG_SETTINGS_READ_RESP message (msg_id
   * 0x00A5).
   */

  var MsgSettingsReadReq = Settings.MsgSettingsReadReq = (function() {
    function MsgSettingsReadReq(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSettingsReadReq.prototype._read = function() {
      this.setting = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * A NULL-terminated and NULL-delimited string with contents
     * "SECTION_SETTING\0SETTING\0"
     */

    return MsgSettingsReadReq;
  })();

  /**
   * The save settings message persists the device's current settings
   * configuration to its onboard flash memory file system.
   */

  var MsgSettingsSave = Settings.MsgSettingsSave = (function() {
    function MsgSettingsSave(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSettingsSave.prototype._read = function() {
    }

    return MsgSettingsSave;
  })();

  /**
   * This message registers the presence and default value of a setting with
   * a settings daemon.  The host should reply with MSG_SETTINGS_WRITE for
   * this setting to set the initial value.
   */

  var MsgSettingsRegister = Settings.MsgSettingsRegister = (function() {
    function MsgSettingsRegister(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSettingsRegister.prototype._read = function() {
      this.setting = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * A NULL-terminated and delimited string with contents
     * "SECTION_SETTING\0SETTING\0VALUE".
     */

    return MsgSettingsRegister;
  })();

  /**
   * The settings message for iterating through the settings values. A device
   * will respond to this message with a "MSG_SETTINGS_READ_BY_INDEX_RESP".
   */

  var MsgSettingsReadByIndexReq = Settings.MsgSettingsReadByIndexReq = (function() {
    function MsgSettingsReadByIndexReq(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSettingsReadByIndexReq.prototype._read = function() {
      this.index = this._io.readU2le();
    }

    /**
     * An index into the device settings, with values ranging from 0 to
     * length(settings).
     */

    return MsgSettingsReadByIndexReq;
  })();

  /**
   * The settings message for indicating end of the settings values.
   */

  var MsgSettingsReadByIndexDone = Settings.MsgSettingsReadByIndexDone = (function() {
    function MsgSettingsReadByIndexDone(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSettingsReadByIndexDone.prototype._read = function() {
    }

    return MsgSettingsReadByIndexDone;
  })();

  /**
   * The setting message writes the device configuration for a particular
   * setting via A NULL-terminated and NULL-delimited string with contents
   * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
   * denotes the NULL character and where quotation marks are omitted. A
   * device will only process to this message when it is received from sender
   * ID 0x42. An example string that could be sent to a device is
   * "solution\0soln_freq\010\0".
   */

  var MsgSettingsWrite = Settings.MsgSettingsWrite = (function() {
    function MsgSettingsWrite(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSettingsWrite.prototype._read = function() {
      this.setting = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * A NULL-terminated and NULL-delimited string with contents
     * "SECTION_SETTING\0SETTING\0VALUE\0"
     */

    return MsgSettingsWrite;
  })();

  return Settings;
})();
return Settings;
}));
