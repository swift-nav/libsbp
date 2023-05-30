// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild



namespace Kaitai
{
    public partial class Mag : KaitaiStruct
    {
        public static Mag FromFile(string fileName)
        {
            return new Mag(new KaitaiStream(fileName));
        }

        public Mag(KaitaiStream p__io, KaitaiStruct p__parent = null, Mag p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// Raw data from the magnetometer.
        /// </summary>
        public partial class MsgMagRaw : KaitaiStruct
        {
            public static MsgMagRaw FromFile(string fileName)
            {
                return new MsgMagRaw(new KaitaiStream(fileName));
            }

            public MsgMagRaw(KaitaiStream p__io, Sbp.Message p__parent = null, Mag p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _towF = m_io.ReadU1();
                _magX = m_io.ReadS2le();
                _magY = m_io.ReadS2le();
                _magZ = m_io.ReadS2le();
            }
            private uint _tow;
            private byte _towF;
            private short _magX;
            private short _magY;
            private short _magZ;
            private Mag m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Milliseconds since start of GPS week. If the high bit is set, the
            /// time is unknown or invalid.
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Milliseconds since start of GPS week, fractional part
            /// </summary>
            public byte TowF { get { return _towF; } }

            /// <summary>
            /// Magnetic field in the body frame X axis
            /// </summary>
            public short MagX { get { return _magX; } }

            /// <summary>
            /// Magnetic field in the body frame Y axis
            /// </summary>
            public short MagY { get { return _magY; } }

            /// <summary>
            /// Magnetic field in the body frame Z axis
            /// </summary>
            public short MagZ { get { return _magZ; } }
            public Mag M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        private Mag m_root;
        private KaitaiStruct m_parent;
        public Mag M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
