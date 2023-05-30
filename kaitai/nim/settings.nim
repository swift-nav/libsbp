import kaitai_struct_nim_runtime
import options

type
  Settings* = ref object of KaitaiStruct
    `parent`*: KaitaiStruct
  Settings_MsgSettingsReadResp* = ref object of KaitaiStruct
    `setting`*: string
    `parent`*: Sbp_Message
  Settings_MsgSettingsWriteResp* = ref object of KaitaiStruct
    `status`*: uint8
    `setting`*: string
    `parent`*: Sbp_Message
  Settings_MsgSettingsRegisterResp* = ref object of KaitaiStruct
    `status`*: uint8
    `setting`*: string
    `parent`*: Sbp_Message
  Settings_MsgSettingsReadByIndexResp* = ref object of KaitaiStruct
    `index`*: uint16
    `setting`*: string
    `parent`*: Sbp_Message
  Settings_MsgSettingsReadReq* = ref object of KaitaiStruct
    `setting`*: string
    `parent`*: Sbp_Message
  Settings_MsgSettingsSave* = ref object of KaitaiStruct
    `parent`*: Sbp_Message
  Settings_MsgSettingsRegister* = ref object of KaitaiStruct
    `setting`*: string
    `parent`*: Sbp_Message
  Settings_MsgSettingsReadByIndexReq* = ref object of KaitaiStruct
    `index`*: uint16
    `parent`*: Sbp_Message
  Settings_MsgSettingsReadByIndexDone* = ref object of KaitaiStruct
    `parent`*: Sbp_Message
  Settings_MsgSettingsWrite* = ref object of KaitaiStruct
    `setting`*: string
    `parent`*: Sbp_Message

proc read*(_: typedesc[Settings], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Settings
proc read*(_: typedesc[Settings_MsgSettingsReadResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsReadResp
proc read*(_: typedesc[Settings_MsgSettingsWriteResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsWriteResp
proc read*(_: typedesc[Settings_MsgSettingsRegisterResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsRegisterResp
proc read*(_: typedesc[Settings_MsgSettingsReadByIndexResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsReadByIndexResp
proc read*(_: typedesc[Settings_MsgSettingsReadReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsReadReq
proc read*(_: typedesc[Settings_MsgSettingsSave], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsSave
proc read*(_: typedesc[Settings_MsgSettingsRegister], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsRegister
proc read*(_: typedesc[Settings_MsgSettingsReadByIndexReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsReadByIndexReq
proc read*(_: typedesc[Settings_MsgSettingsReadByIndexDone], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsReadByIndexDone
proc read*(_: typedesc[Settings_MsgSettingsWrite], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsWrite


proc read*(_: typedesc[Settings], io: KaitaiStream, root: KaitaiStruct, parent: KaitaiStruct): Settings =
  template this: untyped = result
  this = new(Settings)
  let root = if root == nil: cast[Settings](this) else: cast[Settings](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Settings], filename: string): Settings =
  Settings.read(newKaitaiFileStream(filename), nil, nil)


##[
The setting message with which the device responds after a
MSG_SETTING_READ_REQ is sent to device. The string field is a NULL-
terminated and NULL-delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
denotes the NULL character and where quotation marks are omitted. An
example string that could be sent from device is
"solution\0soln_freq\010\0".

]##
proc read*(_: typedesc[Settings_MsgSettingsReadResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsReadResp =
  template this: untyped = result
  this = new(Settings_MsgSettingsReadResp)
  let root = if root == nil: cast[Settings](this) else: cast[Settings](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  A NULL-terminated and NULL-delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0"

  ]##
  let settingExpr = encode(this.io.readBytesFull(), "ascii")
  this.setting = settingExpr

proc fromFile*(_: typedesc[Settings_MsgSettingsReadResp], filename: string): Settings_MsgSettingsReadResp =
  Settings_MsgSettingsReadResp.read(newKaitaiFileStream(filename), nil, nil)


##[
Return the status of a write request with the new value of the setting.
If the requested value is rejected, the current value will be returned.
The string field is a NULL-terminated and NULL-delimited string with
contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape
sequence denotes the NULL character and where quotation marks are
omitted. An example string that could be sent from device is
"solution\0soln_freq\010\0".

]##
proc read*(_: typedesc[Settings_MsgSettingsWriteResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsWriteResp =
  template this: untyped = result
  this = new(Settings_MsgSettingsWriteResp)
  let root = if root == nil: cast[Settings](this) else: cast[Settings](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Write status

  ]##
  let statusExpr = this.io.readU1()
  this.status = statusExpr

  ##[
  A NULL-terminated and delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0"

  ]##
  let settingExpr = encode(this.io.readBytesFull(), "ascii")
  this.setting = settingExpr

proc fromFile*(_: typedesc[Settings_MsgSettingsWriteResp], filename: string): Settings_MsgSettingsWriteResp =
  Settings_MsgSettingsWriteResp.read(newKaitaiFileStream(filename), nil, nil)


##[
This message responds to setting registration with the effective value.
The effective value shall differ from the given default value if setting
was already registered or is available in the permanent setting storage
and had a different value.

]##
proc read*(_: typedesc[Settings_MsgSettingsRegisterResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsRegisterResp =
  template this: untyped = result
  this = new(Settings_MsgSettingsRegisterResp)
  let root = if root == nil: cast[Settings](this) else: cast[Settings](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  Register status

  ]##
  let statusExpr = this.io.readU1()
  this.status = statusExpr

  ##[
  A NULL-terminated and delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
according to the status field.

  ]##
  let settingExpr = encode(this.io.readBytesFull(), "ascii")
  this.setting = settingExpr

proc fromFile*(_: typedesc[Settings_MsgSettingsRegisterResp], filename: string): Settings_MsgSettingsRegisterResp =
  Settings_MsgSettingsRegisterResp.read(newKaitaiFileStream(filename), nil, nil)


##[
The settings message that reports the value of a setting at an index.

In the string field, it reports NULL-terminated and delimited string
with contents "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where
the '\0' escape sequence denotes the NULL character and where quotation
marks are omitted. The FORMAT_TYPE field is optional and denotes
possible string values of the setting as a hint to the user. If
included, the format type portion of the string has the format
"enum:value1,value2,value3". An example string that could be sent from
the device is "simulator\0enabled\0True\0enum:True,False\0".

]##
proc read*(_: typedesc[Settings_MsgSettingsReadByIndexResp], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsReadByIndexResp =
  template this: untyped = result
  this = new(Settings_MsgSettingsReadByIndexResp)
  let root = if root == nil: cast[Settings](this) else: cast[Settings](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  An index into the device settings, with values ranging from 0 to
length(settings)

  ]##
  let indexExpr = this.io.readU2le()
  this.index = indexExpr

  ##[
  A NULL-terminated and delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"

  ]##
  let settingExpr = encode(this.io.readBytesFull(), "ascii")
  this.setting = settingExpr

proc fromFile*(_: typedesc[Settings_MsgSettingsReadByIndexResp], filename: string): Settings_MsgSettingsReadByIndexResp =
  Settings_MsgSettingsReadByIndexResp.read(newKaitaiFileStream(filename), nil, nil)


##[
The setting message that reads the device configuration. The string
field is a NULL-terminated and NULL-delimited string with contents
"SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the
NULL character and where quotation marks are omitted. An example string
that could be sent to a device is "solution\0soln_freq\0". A device will
only respond to this message when it is received from sender ID 0x42. A
device should respond with a MSG_SETTINGS_READ_RESP message (msg_id
0x00A5).

]##
proc read*(_: typedesc[Settings_MsgSettingsReadReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsReadReq =
  template this: untyped = result
  this = new(Settings_MsgSettingsReadReq)
  let root = if root == nil: cast[Settings](this) else: cast[Settings](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  A NULL-terminated and NULL-delimited string with contents
"SECTION_SETTING\0SETTING\0"

  ]##
  let settingExpr = encode(this.io.readBytesFull(), "ascii")
  this.setting = settingExpr

proc fromFile*(_: typedesc[Settings_MsgSettingsReadReq], filename: string): Settings_MsgSettingsReadReq =
  Settings_MsgSettingsReadReq.read(newKaitaiFileStream(filename), nil, nil)


##[
The save settings message persists the device's current settings
configuration to its onboard flash memory file system.

]##
proc read*(_: typedesc[Settings_MsgSettingsSave], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsSave =
  template this: untyped = result
  this = new(Settings_MsgSettingsSave)
  let root = if root == nil: cast[Settings](this) else: cast[Settings](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Settings_MsgSettingsSave], filename: string): Settings_MsgSettingsSave =
  Settings_MsgSettingsSave.read(newKaitaiFileStream(filename), nil, nil)


##[
This message registers the presence and default value of a setting with
a settings daemon.  The host should reply with MSG_SETTINGS_WRITE for
this setting to set the initial value.

]##
proc read*(_: typedesc[Settings_MsgSettingsRegister], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsRegister =
  template this: untyped = result
  this = new(Settings_MsgSettingsRegister)
  let root = if root == nil: cast[Settings](this) else: cast[Settings](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  A NULL-terminated and delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE".

  ]##
  let settingExpr = encode(this.io.readBytesFull(), "ascii")
  this.setting = settingExpr

proc fromFile*(_: typedesc[Settings_MsgSettingsRegister], filename: string): Settings_MsgSettingsRegister =
  Settings_MsgSettingsRegister.read(newKaitaiFileStream(filename), nil, nil)


##[
The settings message for iterating through the settings values. A device
will respond to this message with a "MSG_SETTINGS_READ_BY_INDEX_RESP".

]##
proc read*(_: typedesc[Settings_MsgSettingsReadByIndexReq], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsReadByIndexReq =
  template this: untyped = result
  this = new(Settings_MsgSettingsReadByIndexReq)
  let root = if root == nil: cast[Settings](this) else: cast[Settings](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  An index into the device settings, with values ranging from 0 to
length(settings).

  ]##
  let indexExpr = this.io.readU2le()
  this.index = indexExpr

proc fromFile*(_: typedesc[Settings_MsgSettingsReadByIndexReq], filename: string): Settings_MsgSettingsReadByIndexReq =
  Settings_MsgSettingsReadByIndexReq.read(newKaitaiFileStream(filename), nil, nil)


##[
The settings message for indicating end of the settings values.

]##
proc read*(_: typedesc[Settings_MsgSettingsReadByIndexDone], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsReadByIndexDone =
  template this: untyped = result
  this = new(Settings_MsgSettingsReadByIndexDone)
  let root = if root == nil: cast[Settings](this) else: cast[Settings](root)
  this.io = io
  this.root = root
  this.parent = parent


proc fromFile*(_: typedesc[Settings_MsgSettingsReadByIndexDone], filename: string): Settings_MsgSettingsReadByIndexDone =
  Settings_MsgSettingsReadByIndexDone.read(newKaitaiFileStream(filename), nil, nil)


##[
The setting message writes the device configuration for a particular
setting via A NULL-terminated and NULL-delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
denotes the NULL character and where quotation marks are omitted. A
device will only process to this message when it is received from sender
ID 0x42. An example string that could be sent to a device is
"solution\0soln_freq\010\0".

]##
proc read*(_: typedesc[Settings_MsgSettingsWrite], io: KaitaiStream, root: KaitaiStruct, parent: Sbp_Message): Settings_MsgSettingsWrite =
  template this: untyped = result
  this = new(Settings_MsgSettingsWrite)
  let root = if root == nil: cast[Settings](this) else: cast[Settings](root)
  this.io = io
  this.root = root
  this.parent = parent


  ##[
  A NULL-terminated and NULL-delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0"

  ]##
  let settingExpr = encode(this.io.readBytesFull(), "ascii")
  this.setting = settingExpr

proc fromFile*(_: typedesc[Settings_MsgSettingsWrite], filename: string): Settings_MsgSettingsWrite =
  Settings_MsgSettingsWrite.read(newKaitaiFileStream(filename), nil, nil)

