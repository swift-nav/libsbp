// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.nio.charset.Charset;

public class Settings extends KaitaiStruct {
    public static Settings fromFile(String fileName) throws IOException {
        return new Settings(new ByteBufferKaitaiStream(fileName));
    }

    public Settings(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Settings(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Settings(KaitaiStream _io, KaitaiStruct _parent, Settings _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
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
    public static class MsgSettingsReadResp extends KaitaiStruct {
        public static MsgSettingsReadResp fromFile(String fileName) throws IOException {
            return new MsgSettingsReadResp(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSettingsReadResp(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSettingsReadResp(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSettingsReadResp(KaitaiStream _io, Sbp.Message _parent, Settings _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.setting = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private String setting;
        private Settings _root;
        private Sbp.Message _parent;

        /**
         * A NULL-terminated and NULL-delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE\0"
         */
        public String setting() { return setting; }
        public Settings _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Return the status of a write request with the new value of the setting.
     * If the requested value is rejected, the current value will be returned.
     * The string field is a NULL-terminated and NULL-delimited string with
     * contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape
     * sequence denotes the NULL character and where quotation marks are
     * omitted. An example string that could be sent from device is
     * "solution\0soln_freq\010\0".
     */
    public static class MsgSettingsWriteResp extends KaitaiStruct {
        public static MsgSettingsWriteResp fromFile(String fileName) throws IOException {
            return new MsgSettingsWriteResp(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSettingsWriteResp(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSettingsWriteResp(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSettingsWriteResp(KaitaiStream _io, Sbp.Message _parent, Settings _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.status = this._io.readU1();
            this.setting = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private int status;
        private String setting;
        private Settings _root;
        private Sbp.Message _parent;

        /**
         * Write status
         */
        public int status() { return status; }

        /**
         * A NULL-terminated and delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE\0"
         */
        public String setting() { return setting; }
        public Settings _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message responds to setting registration with the effective value.
     * The effective value shall differ from the given default value if setting
     * was already registered or is available in the permanent setting storage
     * and had a different value.
     */
    public static class MsgSettingsRegisterResp extends KaitaiStruct {
        public static MsgSettingsRegisterResp fromFile(String fileName) throws IOException {
            return new MsgSettingsRegisterResp(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSettingsRegisterResp(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSettingsRegisterResp(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSettingsRegisterResp(KaitaiStream _io, Sbp.Message _parent, Settings _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.status = this._io.readU1();
            this.setting = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private int status;
        private String setting;
        private Settings _root;
        private Sbp.Message _parent;

        /**
         * Register status
         */
        public int status() { return status; }

        /**
         * A NULL-terminated and delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
         * according to the status field.
         */
        public String setting() { return setting; }
        public Settings _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

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
    public static class MsgSettingsReadByIndexResp extends KaitaiStruct {
        public static MsgSettingsReadByIndexResp fromFile(String fileName) throws IOException {
            return new MsgSettingsReadByIndexResp(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSettingsReadByIndexResp(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSettingsReadByIndexResp(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSettingsReadByIndexResp(KaitaiStream _io, Sbp.Message _parent, Settings _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.index = this._io.readU2le();
            this.setting = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private int index;
        private String setting;
        private Settings _root;
        private Sbp.Message _parent;

        /**
         * An index into the device settings, with values ranging from 0 to
         * length(settings)
         */
        public int index() { return index; }

        /**
         * A NULL-terminated and delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
         */
        public String setting() { return setting; }
        public Settings _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

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
    public static class MsgSettingsReadReq extends KaitaiStruct {
        public static MsgSettingsReadReq fromFile(String fileName) throws IOException {
            return new MsgSettingsReadReq(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSettingsReadReq(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSettingsReadReq(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSettingsReadReq(KaitaiStream _io, Sbp.Message _parent, Settings _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.setting = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private String setting;
        private Settings _root;
        private Sbp.Message _parent;

        /**
         * A NULL-terminated and NULL-delimited string with contents
         * "SECTION_SETTING\0SETTING\0"
         */
        public String setting() { return setting; }
        public Settings _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The save settings message persists the device's current settings
     * configuration to its onboard flash memory file system.
     */
    public static class MsgSettingsSave extends KaitaiStruct {
        public static MsgSettingsSave fromFile(String fileName) throws IOException {
            return new MsgSettingsSave(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSettingsSave(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSettingsSave(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSettingsSave(KaitaiStream _io, Sbp.Message _parent, Settings _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
        }
        private Settings _root;
        private Sbp.Message _parent;
        public Settings _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message registers the presence and default value of a setting with
     * a settings daemon.  The host should reply with MSG_SETTINGS_WRITE for
     * this setting to set the initial value.
     */
    public static class MsgSettingsRegister extends KaitaiStruct {
        public static MsgSettingsRegister fromFile(String fileName) throws IOException {
            return new MsgSettingsRegister(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSettingsRegister(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSettingsRegister(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSettingsRegister(KaitaiStream _io, Sbp.Message _parent, Settings _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.setting = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private String setting;
        private Settings _root;
        private Sbp.Message _parent;

        /**
         * A NULL-terminated and delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE".
         */
        public String setting() { return setting; }
        public Settings _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The settings message for iterating through the settings values. A device
     * will respond to this message with a "MSG_SETTINGS_READ_BY_INDEX_RESP".
     */
    public static class MsgSettingsReadByIndexReq extends KaitaiStruct {
        public static MsgSettingsReadByIndexReq fromFile(String fileName) throws IOException {
            return new MsgSettingsReadByIndexReq(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSettingsReadByIndexReq(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSettingsReadByIndexReq(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSettingsReadByIndexReq(KaitaiStream _io, Sbp.Message _parent, Settings _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.index = this._io.readU2le();
        }
        private int index;
        private Settings _root;
        private Sbp.Message _parent;

        /**
         * An index into the device settings, with values ranging from 0 to
         * length(settings).
         */
        public int index() { return index; }
        public Settings _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The settings message for indicating end of the settings values.
     */
    public static class MsgSettingsReadByIndexDone extends KaitaiStruct {
        public static MsgSettingsReadByIndexDone fromFile(String fileName) throws IOException {
            return new MsgSettingsReadByIndexDone(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSettingsReadByIndexDone(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSettingsReadByIndexDone(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSettingsReadByIndexDone(KaitaiStream _io, Sbp.Message _parent, Settings _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
        }
        private Settings _root;
        private Sbp.Message _parent;
        public Settings _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
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
    public static class MsgSettingsWrite extends KaitaiStruct {
        public static MsgSettingsWrite fromFile(String fileName) throws IOException {
            return new MsgSettingsWrite(new ByteBufferKaitaiStream(fileName));
        }

        public MsgSettingsWrite(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgSettingsWrite(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgSettingsWrite(KaitaiStream _io, Sbp.Message _parent, Settings _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.setting = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private String setting;
        private Settings _root;
        private Sbp.Message _parent;

        /**
         * A NULL-terminated and NULL-delimited string with contents
         * "SECTION_SETTING\0SETTING\0VALUE\0"
         */
        public String setting() { return setting; }
        public Settings _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Settings _root;
    private KaitaiStruct _parent;
    public Settings _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
