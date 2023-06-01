// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild



namespace Kaitai
{
    public partial class ExtEvents : KaitaiStruct
    {
        public static ExtEvents FromFile(string fileName)
        {
            return new ExtEvents(new KaitaiStream(fileName));
        }

        public ExtEvents(KaitaiStream p__io, KaitaiStruct p__parent = null, ExtEvents p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// Reports detection of an external event, the GPS time it occurred, which
        /// pin it was and whether it was rising or falling.
        /// </summary>
        public partial class MsgExtEvent : KaitaiStruct
        {
            public static MsgExtEvent FromFile(string fileName)
            {
                return new MsgExtEvent(new KaitaiStream(fileName));
            }

            public MsgExtEvent(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, ExtEvents p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _wn = m_io.ReadU2le();
                _tow = m_io.ReadU4le();
                _nsResidual = m_io.ReadS4le();
                _flags = m_io.ReadU1();
                _pin = m_io.ReadU1();
            }
            private ushort _wn;
            private uint _tow;
            private int _nsResidual;
            private byte _flags;
            private byte _pin;
            private ExtEvents m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// GPS week number
            /// </summary>
            public ushort Wn { get { return _wn; } }

            /// <summary>
            /// GPS time of week rounded to the nearest millisecond
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000
            /// to 500000)
            /// </summary>
            public int NsResidual { get { return _nsResidual; } }

            /// <summary>
            /// Flags
            /// </summary>
            public byte Flags { get { return _flags; } }

            /// <summary>
            /// Pin number.  0..9 = DEBUG0..9.
            /// </summary>
            public byte Pin { get { return _pin; } }
            public ExtEvents M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }
        private ExtEvents m_root;
        private KaitaiStruct m_parent;
        public ExtEvents M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
