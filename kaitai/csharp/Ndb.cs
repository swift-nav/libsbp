// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild



namespace Kaitai
{
    public partial class Ndb : KaitaiStruct
    {
        public static Ndb FromFile(string fileName)
        {
            return new Ndb(new KaitaiStream(fileName));
        }

        public Ndb(KaitaiStream p__io, KaitaiStruct p__parent = null, Ndb p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// This message is sent out when an object is stored into NDB. If needed
        /// message could also be sent out when fetching an object from NDB.
        /// </summary>
        public partial class MsgNdbEvent : KaitaiStruct
        {
            public static MsgNdbEvent FromFile(string fileName)
            {
                return new MsgNdbEvent(new KaitaiStream(fileName));
            }

            public MsgNdbEvent(KaitaiStream p__io, Sbp.Message p__parent = null, Ndb p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _recvTime = m_io.ReadU8le();
                _event = m_io.ReadU1();
                _objectType = m_io.ReadU1();
                _result = m_io.ReadU1();
                _dataSource = m_io.ReadU1();
                _objectSid = new Gnss.GnssSignal(m_io, this, m_root);
                _srcSid = new Gnss.GnssSignal(m_io, this, m_root);
                _originalSender = m_io.ReadU2le();
            }
            private ulong _recvTime;
            private byte _event;
            private byte _objectType;
            private byte _result;
            private byte _dataSource;
            private Gnss.GnssSignal _objectSid;
            private Gnss.GnssSignal _srcSid;
            private ushort _originalSender;
            private Ndb m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// HW time in milliseconds.
            /// </summary>
            public ulong RecvTime { get { return _recvTime; } }

            /// <summary>
            /// Event type.
            /// </summary>
            public byte Event { get { return _event; } }

            /// <summary>
            /// Event object type.
            /// </summary>
            public byte ObjectType { get { return _objectType; } }

            /// <summary>
            /// Event result.
            /// </summary>
            public byte Result { get { return _result; } }

            /// <summary>
            /// Data source for STORE event, reserved for other events.
            /// </summary>
            public byte DataSource { get { return _dataSource; } }

            /// <summary>
            /// GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid
            /// indicates for which signal the object belongs to. Reserved in other
            /// cases.
            /// </summary>
            public Gnss.GnssSignal ObjectSid { get { return _objectSid; } }

            /// <summary>
            /// GNSS signal identifier, If object_type is Almanac, Almanac WN, Iono
            /// OR L2C capabilities AND data_source is NDB_DS_RECEIVER sid indicates
            /// from which SV data was decoded. Reserved in other cases.
            /// </summary>
            public Gnss.GnssSignal SrcSid { get { return _srcSid; } }

            /// <summary>
            /// A unique identifier of the sending hardware. For v1.0, set to the 2
            /// least significant bytes of the device serial number, valid only if
            /// data_source is NDB_DS_SBP. Reserved in case of other data_source.
            /// </summary>
            public ushort OriginalSender { get { return _originalSender; } }
            public Ndb M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        private Ndb m_root;
        private KaitaiStruct m_parent;
        public Ndb M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
