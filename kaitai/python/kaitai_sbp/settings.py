# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Settings(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgSettingsReadResp(KaitaiStruct):
        """The setting message with which the device responds after a
        MSG_SETTING_READ_REQ is sent to device. The string field is a NULL-
        terminated and NULL-delimited string with contents
        "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
        denotes the NULL character and where quotation marks are omitted. An
        example string that could be sent from device is
        "solution\0soln_freq\010\0".
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.setting = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgSettingsWriteResp(KaitaiStruct):
        """Return the status of a write request with the new value of the setting.
        If the requested value is rejected, the current value will be returned.
        The string field is a NULL-terminated and NULL-delimited string with
        contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape
        sequence denotes the NULL character and where quotation marks are
        omitted. An example string that could be sent from device is
        "solution\0soln_freq\010\0".
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.status = self._io.read_u1()
            self.setting = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgSettingsRegisterResp(KaitaiStruct):
        """This message responds to setting registration with the effective value.
        The effective value shall differ from the given default value if setting
        was already registered or is available in the permanent setting storage
        and had a different value.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.status = self._io.read_u1()
            self.setting = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgSettingsReadByIndexResp(KaitaiStruct):
        """The settings message that reports the value of a setting at an index.
        
        In the string field, it reports NULL-terminated and delimited string
        with contents "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where
        the '\0' escape sequence denotes the NULL character and where quotation
        marks are omitted. The FORMAT_TYPE field is optional and denotes
        possible string values of the setting as a hint to the user. If
        included, the format type portion of the string has the format
        "enum:value1,value2,value3". An example string that could be sent from
        the device is "simulator\0enabled\0True\0enum:True,False\0".
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.index = self._io.read_u2le()
            self.setting = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgSettingsReadReq(KaitaiStruct):
        """The setting message that reads the device configuration. The string
        field is a NULL-terminated and NULL-delimited string with contents
        "SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the
        NULL character and where quotation marks are omitted. An example string
        that could be sent to a device is "solution\0soln_freq\0". A device will
        only respond to this message when it is received from sender ID 0x42. A
        device should respond with a MSG_SETTINGS_READ_RESP message (msg_id
        0x00A5).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.setting = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgSettingsSave(KaitaiStruct):
        """The save settings message persists the device's current settings
        configuration to its onboard flash memory file system.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            pass


    class MsgSettingsRegister(KaitaiStruct):
        """This message registers the presence and default value of a setting with
        a settings daemon.  The host should reply with MSG_SETTINGS_WRITE for
        this setting to set the initial value.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.setting = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgSettingsReadByIndexReq(KaitaiStruct):
        """The settings message for iterating through the settings values. A device
        will respond to this message with a "MSG_SETTINGS_READ_BY_INDEX_RESP".
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.index = self._io.read_u2le()


    class MsgSettingsReadByIndexDone(KaitaiStruct):
        """The settings message for indicating end of the settings values.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            pass


    class MsgSettingsWrite(KaitaiStruct):
        """The setting message writes the device configuration for a particular
        setting via A NULL-terminated and NULL-delimited string with contents
        "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence
        denotes the NULL character and where quotation marks are omitted. A
        device will only process to this message when it is received from sender
        ID 0x42. An example string that could be sent to a device is
        "solution\0soln_freq\010\0".
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.setting = (self._io.read_bytes_full()).decode(u"ascii")



