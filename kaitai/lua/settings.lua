-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")
local str_decode = require("string_decode")

Settings = class.class(KaitaiStruct)

function Settings:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Settings:_read()
end


-- 
-- The setting message with which the device responds after a
-- MSG_SETTING_READ_REQ is sent to device. The string field is a NULL-
-- terminated and NULL-delimited string with contents
-- "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
-- denotes the NULL character and where quotation marks are omitted. An
-- example string that could be sent from device is
-- "solution\0soln_freq\010\0".
Settings.MsgSettingsReadResp = class.class(KaitaiStruct)

function Settings.MsgSettingsReadResp:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Settings.MsgSettingsReadResp:_read()
  self.setting = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- A NULL-terminated and NULL-delimited string with contents
-- "SECTION_SETTING\0SETTING\0VALUE\0"

-- 
-- Return the status of a write request with the new value of the setting.
-- If the requested value is rejected, the current value will be returned.
-- The string field is a NULL-terminated and NULL-delimited string with
-- contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape
-- sequence denotes the NULL character and where quotation marks are
-- omitted. An example string that could be sent from device is
-- "solution\0soln_freq\010\0".
Settings.MsgSettingsWriteResp = class.class(KaitaiStruct)

function Settings.MsgSettingsWriteResp:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Settings.MsgSettingsWriteResp:_read()
  self.status = self._io:read_u1()
  self.setting = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- Write status
-- 
-- A NULL-terminated and delimited string with contents
-- "SECTION_SETTING\0SETTING\0VALUE\0"

-- 
-- This message responds to setting registration with the effective value.
-- The effective value shall differ from the given default value if setting
-- was already registered or is available in the permanent setting storage
-- and had a different value.
Settings.MsgSettingsRegisterResp = class.class(KaitaiStruct)

function Settings.MsgSettingsRegisterResp:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Settings.MsgSettingsRegisterResp:_read()
  self.status = self._io:read_u1()
  self.setting = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- Register status
-- 
-- A NULL-terminated and delimited string with contents
-- "SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
-- according to the status field.

-- 
-- The settings message that reports the value of a setting at an index.
-- 
-- In the string field, it reports NULL-terminated and delimited string
-- with contents "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where
-- the '\0' escape sequence denotes the NULL character and where quotation
-- marks are omitted. The FORMAT_TYPE field is optional and denotes
-- possible string values of the setting as a hint to the user. If
-- included, the format type portion of the string has the format
-- "enum:value1,value2,value3". An example string that could be sent from
-- the device is "simulator\0enabled\0True\0enum:True,False\0".
Settings.MsgSettingsReadByIndexResp = class.class(KaitaiStruct)

function Settings.MsgSettingsReadByIndexResp:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Settings.MsgSettingsReadByIndexResp:_read()
  self.index = self._io:read_u2le()
  self.setting = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- An index into the device settings, with values ranging from 0 to
-- length(settings)
-- 
-- A NULL-terminated and delimited string with contents
-- "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"

-- 
-- The setting message that reads the device configuration. The string
-- field is a NULL-terminated and NULL-delimited string with contents
-- "SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the
-- NULL character and where quotation marks are omitted. An example string
-- that could be sent to a device is "solution\0soln_freq\0". A device will
-- only respond to this message when it is received from sender ID 0x42. A
-- device should respond with a MSG_SETTINGS_READ_RESP message (msg_id
-- 0x00A5).
Settings.MsgSettingsReadReq = class.class(KaitaiStruct)

function Settings.MsgSettingsReadReq:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Settings.MsgSettingsReadReq:_read()
  self.setting = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- A NULL-terminated and NULL-delimited string with contents
-- "SECTION_SETTING\0SETTING\0"

-- 
-- The save settings message persists the device's current settings
-- configuration to its onboard flash memory file system.
Settings.MsgSettingsSave = class.class(KaitaiStruct)

function Settings.MsgSettingsSave:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Settings.MsgSettingsSave:_read()
end


-- 
-- This message registers the presence and default value of a setting with
-- a settings daemon.  The host should reply with MSG_SETTINGS_WRITE for
-- this setting to set the initial value.
Settings.MsgSettingsRegister = class.class(KaitaiStruct)

function Settings.MsgSettingsRegister:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Settings.MsgSettingsRegister:_read()
  self.setting = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- A NULL-terminated and delimited string with contents
-- "SECTION_SETTING\0SETTING\0VALUE".

-- 
-- The settings message for iterating through the settings values. A device
-- will respond to this message with a "MSG_SETTINGS_READ_BY_INDEX_RESP".
Settings.MsgSettingsReadByIndexReq = class.class(KaitaiStruct)

function Settings.MsgSettingsReadByIndexReq:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Settings.MsgSettingsReadByIndexReq:_read()
  self.index = self._io:read_u2le()
end

-- 
-- An index into the device settings, with values ranging from 0 to
-- length(settings).

-- 
-- The settings message for indicating end of the settings values.
Settings.MsgSettingsReadByIndexDone = class.class(KaitaiStruct)

function Settings.MsgSettingsReadByIndexDone:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Settings.MsgSettingsReadByIndexDone:_read()
end


-- 
-- The setting message writes the device configuration for a particular
-- setting via A NULL-terminated and NULL-delimited string with contents
-- "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
-- denotes the NULL character and where quotation marks are omitted. A
-- device will only process to this message when it is received from sender
-- ID 0x42. An example string that could be sent to a device is
-- "solution\0soln_freq\010\0".
Settings.MsgSettingsWrite = class.class(KaitaiStruct)

function Settings.MsgSettingsWrite:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Settings.MsgSettingsWrite:_read()
  self.setting = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- A NULL-terminated and NULL-delimited string with contents
-- "SECTION_SETTING\0SETTING\0VALUE\0"

