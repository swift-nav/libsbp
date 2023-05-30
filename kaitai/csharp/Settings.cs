// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild



namespace Kaitai
{
    public partial class Settings : KaitaiStruct
    {
        public static Settings FromFile(string fileName)
        {
            return new Settings(new KaitaiStream(fileName));
        }

        public Settings(KaitaiStream p__io, KaitaiStruct p__parent = null, Settings p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// The setting message with which the device responds after a
        /// MSG_SETTING_READ_REQ is sent to device. The string field is a NULL-
        /// terminated and NULL-delimited string with contents
        /// &quot;SECTION_SETTING\0SETTING\0VALUE\0&quot; where the '\0' escape sequence
        /// denotes the NULL character and where quotation marks are omitted. An
        /// example string that could be sent from device is
        /// &quot;solution\0soln_freq\010\0&quot;.
        /// </summary>
        public partial class MsgSettingsReadResp : KaitaiStruct
        {
            public static MsgSettingsReadResp FromFile(string fileName)
            {
                return new MsgSettingsReadResp(new KaitaiStream(fileName));
            }

            public MsgSettingsReadResp(KaitaiStream p__io, Sbp.Message p__parent = null, Settings p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _setting = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private string _setting;
            private Settings m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// A NULL-terminated and NULL-delimited string with contents
            /// &quot;SECTION_SETTING\0SETTING\0VALUE\0&quot;
            /// </summary>
            public string Setting { get { return _setting; } }
            public Settings M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Return the status of a write request with the new value of the setting.
        /// If the requested value is rejected, the current value will be returned.
        /// The string field is a NULL-terminated and NULL-delimited string with
        /// contents &quot;SECTION_SETTING\0SETTING\0VALUE\0&quot; where the '\0' escape
        /// sequence denotes the NULL character and where quotation marks are
        /// omitted. An example string that could be sent from device is
        /// &quot;solution\0soln_freq\010\0&quot;.
        /// </summary>
        public partial class MsgSettingsWriteResp : KaitaiStruct
        {
            public static MsgSettingsWriteResp FromFile(string fileName)
            {
                return new MsgSettingsWriteResp(new KaitaiStream(fileName));
            }

            public MsgSettingsWriteResp(KaitaiStream p__io, Sbp.Message p__parent = null, Settings p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _status = m_io.ReadU1();
                _setting = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private byte _status;
            private string _setting;
            private Settings m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Write status
            /// </summary>
            public byte Status { get { return _status; } }

            /// <summary>
            /// A NULL-terminated and delimited string with contents
            /// &quot;SECTION_SETTING\0SETTING\0VALUE\0&quot;
            /// </summary>
            public string Setting { get { return _setting; } }
            public Settings M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message responds to setting registration with the effective value.
        /// The effective value shall differ from the given default value if setting
        /// was already registered or is available in the permanent setting storage
        /// and had a different value.
        /// </summary>
        public partial class MsgSettingsRegisterResp : KaitaiStruct
        {
            public static MsgSettingsRegisterResp FromFile(string fileName)
            {
                return new MsgSettingsRegisterResp(new KaitaiStream(fileName));
            }

            public MsgSettingsRegisterResp(KaitaiStream p__io, Sbp.Message p__parent = null, Settings p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _status = m_io.ReadU1();
                _setting = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private byte _status;
            private string _setting;
            private Settings m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Register status
            /// </summary>
            public byte Status { get { return _status; } }

            /// <summary>
            /// A NULL-terminated and delimited string with contents
            /// &quot;SECTION_SETTING\0SETTING\0VALUE&quot;. The meaning of value is defined
            /// according to the status field.
            /// </summary>
            public string Setting { get { return _setting; } }
            public Settings M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The settings message that reports the value of a setting at an index.
        /// 
        /// In the string field, it reports NULL-terminated and delimited string
        /// with contents &quot;SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0&quot;. where
        /// the '\0' escape sequence denotes the NULL character and where quotation
        /// marks are omitted. The FORMAT_TYPE field is optional and denotes
        /// possible string values of the setting as a hint to the user. If
        /// included, the format type portion of the string has the format
        /// &quot;enum:value1,value2,value3&quot;. An example string that could be sent from
        /// the device is &quot;simulator\0enabled\0True\0enum:True,False\0&quot;.
        /// </summary>
        public partial class MsgSettingsReadByIndexResp : KaitaiStruct
        {
            public static MsgSettingsReadByIndexResp FromFile(string fileName)
            {
                return new MsgSettingsReadByIndexResp(new KaitaiStream(fileName));
            }

            public MsgSettingsReadByIndexResp(KaitaiStream p__io, Sbp.Message p__parent = null, Settings p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _index = m_io.ReadU2le();
                _setting = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private ushort _index;
            private string _setting;
            private Settings m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// An index into the device settings, with values ranging from 0 to
            /// length(settings)
            /// </summary>
            public ushort Index { get { return _index; } }

            /// <summary>
            /// A NULL-terminated and delimited string with contents
            /// &quot;SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0&quot;
            /// </summary>
            public string Setting { get { return _setting; } }
            public Settings M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The setting message that reads the device configuration. The string
        /// field is a NULL-terminated and NULL-delimited string with contents
        /// &quot;SECTION_SETTING\0SETTING\0&quot; where the '\0' escape sequence denotes the
        /// NULL character and where quotation marks are omitted. An example string
        /// that could be sent to a device is &quot;solution\0soln_freq\0&quot;. A device will
        /// only respond to this message when it is received from sender ID 0x42. A
        /// device should respond with a MSG_SETTINGS_READ_RESP message (msg_id
        /// 0x00A5).
        /// </summary>
        public partial class MsgSettingsReadReq : KaitaiStruct
        {
            public static MsgSettingsReadReq FromFile(string fileName)
            {
                return new MsgSettingsReadReq(new KaitaiStream(fileName));
            }

            public MsgSettingsReadReq(KaitaiStream p__io, Sbp.Message p__parent = null, Settings p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _setting = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private string _setting;
            private Settings m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// A NULL-terminated and NULL-delimited string with contents
            /// &quot;SECTION_SETTING\0SETTING\0&quot;
            /// </summary>
            public string Setting { get { return _setting; } }
            public Settings M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The save settings message persists the device's current settings
        /// configuration to its onboard flash memory file system.
        /// </summary>
        public partial class MsgSettingsSave : KaitaiStruct
        {
            public static MsgSettingsSave FromFile(string fileName)
            {
                return new MsgSettingsSave(new KaitaiStream(fileName));
            }

            public MsgSettingsSave(KaitaiStream p__io, Sbp.Message p__parent = null, Settings p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
            }
            private Settings m_root;
            private Sbp.Message m_parent;
            public Settings M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message registers the presence and default value of a setting with
        /// a settings daemon.  The host should reply with MSG_SETTINGS_WRITE for
        /// this setting to set the initial value.
        /// </summary>
        public partial class MsgSettingsRegister : KaitaiStruct
        {
            public static MsgSettingsRegister FromFile(string fileName)
            {
                return new MsgSettingsRegister(new KaitaiStream(fileName));
            }

            public MsgSettingsRegister(KaitaiStream p__io, Sbp.Message p__parent = null, Settings p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _setting = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private string _setting;
            private Settings m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// A NULL-terminated and delimited string with contents
            /// &quot;SECTION_SETTING\0SETTING\0VALUE&quot;.
            /// </summary>
            public string Setting { get { return _setting; } }
            public Settings M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The settings message for iterating through the settings values. A device
        /// will respond to this message with a &quot;MSG_SETTINGS_READ_BY_INDEX_RESP&quot;.
        /// </summary>
        public partial class MsgSettingsReadByIndexReq : KaitaiStruct
        {
            public static MsgSettingsReadByIndexReq FromFile(string fileName)
            {
                return new MsgSettingsReadByIndexReq(new KaitaiStream(fileName));
            }

            public MsgSettingsReadByIndexReq(KaitaiStream p__io, Sbp.Message p__parent = null, Settings p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _index = m_io.ReadU2le();
            }
            private ushort _index;
            private Settings m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// An index into the device settings, with values ranging from 0 to
            /// length(settings).
            /// </summary>
            public ushort Index { get { return _index; } }
            public Settings M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The settings message for indicating end of the settings values.
        /// </summary>
        public partial class MsgSettingsReadByIndexDone : KaitaiStruct
        {
            public static MsgSettingsReadByIndexDone FromFile(string fileName)
            {
                return new MsgSettingsReadByIndexDone(new KaitaiStream(fileName));
            }

            public MsgSettingsReadByIndexDone(KaitaiStream p__io, Sbp.Message p__parent = null, Settings p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
            }
            private Settings m_root;
            private Sbp.Message m_parent;
            public Settings M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The setting message writes the device configuration for a particular
        /// setting via A NULL-terminated and NULL-delimited string with contents
        /// &quot;SECTION_SETTING\0SETTING\0VALUE\0&quot; where the '\0' escape sequence
        /// denotes the NULL character and where quotation marks are omitted. A
        /// device will only process to this message when it is received from sender
        /// ID 0x42. An example string that could be sent to a device is
        /// &quot;solution\0soln_freq\010\0&quot;.
        /// </summary>
        public partial class MsgSettingsWrite : KaitaiStruct
        {
            public static MsgSettingsWrite FromFile(string fileName)
            {
                return new MsgSettingsWrite(new KaitaiStream(fileName));
            }

            public MsgSettingsWrite(KaitaiStream p__io, Sbp.Message p__parent = null, Settings p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _setting = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private string _setting;
            private Settings m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// A NULL-terminated and NULL-delimited string with contents
            /// &quot;SECTION_SETTING\0SETTING\0VALUE\0&quot;
            /// </summary>
            public string Setting { get { return _setting; } }
            public Settings M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        private Settings m_root;
        private KaitaiStruct m_parent;
        public Settings M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
