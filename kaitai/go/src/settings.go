// Code generated by kaitai-struct-compiler from a .ksy source file. DO NOT EDIT.

import "github.com/kaitai-io/kaitai_struct_go_runtime/kaitai"

type Settings struct {
	_io *kaitai.Stream
	_root *Settings
	_parent interface{}
}
func NewSettings() *Settings {
	return &Settings{
	}
}

func (this *Settings) Read(io *kaitai.Stream, parent interface{}, root *Settings) (err error) {
	this._io = io
	this._parent = parent
	this._root = root

	return err
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
type Settings_MsgSettingsReadResp struct {
	Setting string
	_io *kaitai.Stream
	_root *Settings
	_parent *Sbp_Message
}
func NewSettings_MsgSettingsReadResp() *Settings_MsgSettingsReadResp {
	return &Settings_MsgSettingsReadResp{
	}
}

func (this *Settings_MsgSettingsReadResp) Read(io *kaitai.Stream, parent *Sbp_Message, root *Settings) (err error) {
	this._io = io
	this._parent = parent
	this._root = root

	tmp1, err := this._io.ReadBytesFull()
	if err != nil {
		return err
	}
	tmp1 = tmp1
	this.Setting = string(tmp1)
	return err
}

/**
 * A NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0"
 */

/**
 * Return the status of a write request with the new value of the setting.
 * If the requested value is rejected, the current value will be returned.
 * The string field is a NULL-terminated and NULL-delimited string with
 * contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape
 * sequence denotes the NULL character and where quotation marks are
 * omitted. An example string that could be sent from device is
 * "solution\0soln_freq\010\0".
 */
type Settings_MsgSettingsWriteResp struct {
	Status uint8
	Setting string
	_io *kaitai.Stream
	_root *Settings
	_parent *Sbp_Message
}
func NewSettings_MsgSettingsWriteResp() *Settings_MsgSettingsWriteResp {
	return &Settings_MsgSettingsWriteResp{
	}
}

func (this *Settings_MsgSettingsWriteResp) Read(io *kaitai.Stream, parent *Sbp_Message, root *Settings) (err error) {
	this._io = io
	this._parent = parent
	this._root = root

	tmp2, err := this._io.ReadU1()
	if err != nil {
		return err
	}
	this.Status = tmp2
	tmp3, err := this._io.ReadBytesFull()
	if err != nil {
		return err
	}
	tmp3 = tmp3
	this.Setting = string(tmp3)
	return err
}

/**
 * Write status
 */

/**
 * A NULL-terminated and delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0"
 */

/**
 * This message responds to setting registration with the effective value.
 * The effective value shall differ from the given default value if setting
 * was already registered or is available in the permanent setting storage
 * and had a different value.
 */
type Settings_MsgSettingsRegisterResp struct {
	Status uint8
	Setting string
	_io *kaitai.Stream
	_root *Settings
	_parent *Sbp_Message
}
func NewSettings_MsgSettingsRegisterResp() *Settings_MsgSettingsRegisterResp {
	return &Settings_MsgSettingsRegisterResp{
	}
}

func (this *Settings_MsgSettingsRegisterResp) Read(io *kaitai.Stream, parent *Sbp_Message, root *Settings) (err error) {
	this._io = io
	this._parent = parent
	this._root = root

	tmp4, err := this._io.ReadU1()
	if err != nil {
		return err
	}
	this.Status = tmp4
	tmp5, err := this._io.ReadBytesFull()
	if err != nil {
		return err
	}
	tmp5 = tmp5
	this.Setting = string(tmp5)
	return err
}

/**
 * Register status
 */

/**
 * A NULL-terminated and delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
 * according to the status field.
 */

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
type Settings_MsgSettingsReadByIndexResp struct {
	Index uint16
	Setting string
	_io *kaitai.Stream
	_root *Settings
	_parent *Sbp_Message
}
func NewSettings_MsgSettingsReadByIndexResp() *Settings_MsgSettingsReadByIndexResp {
	return &Settings_MsgSettingsReadByIndexResp{
	}
}

func (this *Settings_MsgSettingsReadByIndexResp) Read(io *kaitai.Stream, parent *Sbp_Message, root *Settings) (err error) {
	this._io = io
	this._parent = parent
	this._root = root

	tmp6, err := this._io.ReadU2le()
	if err != nil {
		return err
	}
	this.Index = uint16(tmp6)
	tmp7, err := this._io.ReadBytesFull()
	if err != nil {
		return err
	}
	tmp7 = tmp7
	this.Setting = string(tmp7)
	return err
}

/**
 * An index into the device settings, with values ranging from 0 to
 * length(settings)
 */

/**
 * A NULL-terminated and delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
 */

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
type Settings_MsgSettingsReadReq struct {
	Setting string
	_io *kaitai.Stream
	_root *Settings
	_parent *Sbp_Message
}
func NewSettings_MsgSettingsReadReq() *Settings_MsgSettingsReadReq {
	return &Settings_MsgSettingsReadReq{
	}
}

func (this *Settings_MsgSettingsReadReq) Read(io *kaitai.Stream, parent *Sbp_Message, root *Settings) (err error) {
	this._io = io
	this._parent = parent
	this._root = root

	tmp8, err := this._io.ReadBytesFull()
	if err != nil {
		return err
	}
	tmp8 = tmp8
	this.Setting = string(tmp8)
	return err
}

/**
 * A NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0"
 */

/**
 * The save settings message persists the device's current settings
 * configuration to its onboard flash memory file system.
 */
type Settings_MsgSettingsSave struct {
	_io *kaitai.Stream
	_root *Settings
	_parent *Sbp_Message
}
func NewSettings_MsgSettingsSave() *Settings_MsgSettingsSave {
	return &Settings_MsgSettingsSave{
	}
}

func (this *Settings_MsgSettingsSave) Read(io *kaitai.Stream, parent *Sbp_Message, root *Settings) (err error) {
	this._io = io
	this._parent = parent
	this._root = root

	return err
}

/**
 * This message registers the presence and default value of a setting with
 * a settings daemon.  The host should reply with MSG_SETTINGS_WRITE for
 * this setting to set the initial value.
 */
type Settings_MsgSettingsRegister struct {
	Setting string
	_io *kaitai.Stream
	_root *Settings
	_parent *Sbp_Message
}
func NewSettings_MsgSettingsRegister() *Settings_MsgSettingsRegister {
	return &Settings_MsgSettingsRegister{
	}
}

func (this *Settings_MsgSettingsRegister) Read(io *kaitai.Stream, parent *Sbp_Message, root *Settings) (err error) {
	this._io = io
	this._parent = parent
	this._root = root

	tmp9, err := this._io.ReadBytesFull()
	if err != nil {
		return err
	}
	tmp9 = tmp9
	this.Setting = string(tmp9)
	return err
}

/**
 * A NULL-terminated and delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE".
 */

/**
 * The settings message for iterating through the settings values. A device
 * will respond to this message with a "MSG_SETTINGS_READ_BY_INDEX_RESP".
 */
type Settings_MsgSettingsReadByIndexReq struct {
	Index uint16
	_io *kaitai.Stream
	_root *Settings
	_parent *Sbp_Message
}
func NewSettings_MsgSettingsReadByIndexReq() *Settings_MsgSettingsReadByIndexReq {
	return &Settings_MsgSettingsReadByIndexReq{
	}
}

func (this *Settings_MsgSettingsReadByIndexReq) Read(io *kaitai.Stream, parent *Sbp_Message, root *Settings) (err error) {
	this._io = io
	this._parent = parent
	this._root = root

	tmp10, err := this._io.ReadU2le()
	if err != nil {
		return err
	}
	this.Index = uint16(tmp10)
	return err
}

/**
 * An index into the device settings, with values ranging from 0 to
 * length(settings).
 */

/**
 * The settings message for indicating end of the settings values.
 */
type Settings_MsgSettingsReadByIndexDone struct {
	_io *kaitai.Stream
	_root *Settings
	_parent *Sbp_Message
}
func NewSettings_MsgSettingsReadByIndexDone() *Settings_MsgSettingsReadByIndexDone {
	return &Settings_MsgSettingsReadByIndexDone{
	}
}

func (this *Settings_MsgSettingsReadByIndexDone) Read(io *kaitai.Stream, parent *Sbp_Message, root *Settings) (err error) {
	this._io = io
	this._parent = parent
	this._root = root

	return err
}

/**
 * The setting message writes the device configuration for a particular
 * setting via A NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
 * denotes the NULL character and where quotation marks are omitted. A
 * device will only process to this message when it is received from sender
 * ID 0x42. An example string that could be sent to a device is
 * "solution\0soln_freq\010\0".
 */
type Settings_MsgSettingsWrite struct {
	Setting string
	_io *kaitai.Stream
	_root *Settings
	_parent *Sbp_Message
}
func NewSettings_MsgSettingsWrite() *Settings_MsgSettingsWrite {
	return &Settings_MsgSettingsWrite{
	}
}

func (this *Settings_MsgSettingsWrite) Read(io *kaitai.Stream, parent *Sbp_Message, root *Settings) (err error) {
	this._io = io
	this._parent = parent
	this._root = root

	tmp11, err := this._io.ReadBytesFull()
	if err != nil {
		return err
	}
	tmp11 = tmp11
	this.Setting = string(tmp11)
	return err
}

/**
 * A NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0"
 */