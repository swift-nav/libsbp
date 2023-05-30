// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class Sbas : KaitaiStruct
    {
        public static Sbas FromFile(string fileName)
        {
            return new Sbas(new KaitaiStream(fileName));
        }

        public Sbas(KaitaiStream p__io, KaitaiStruct p__parent = null, Sbas p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// This message is sent once per second per SBAS satellite. ME checks the
        /// parity of the data block and sends only blocks that pass the check.
        /// </summary>
        public partial class MsgSbasRaw : KaitaiStruct
        {
            public static MsgSbasRaw FromFile(string fileName)
            {
                return new MsgSbasRaw(new KaitaiStream(fileName));
            }

            public MsgSbasRaw(KaitaiStream p__io, Sbp.Message p__parent = null, Sbas p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _tow = m_io.ReadU4le();
                _messageType = m_io.ReadU1();
                _data = new List<byte>();
                for (var i = 0; i < 27; i++)
                {
                    _data.Add(m_io.ReadU1());
                }
            }
            private Gnss.GnssSignal _sid;
            private uint _tow;
            private byte _messageType;
            private List<byte> _data;
            private Sbas m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GNSS signal identifier.
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// GPS time-of-week at the start of the data block.
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// SBAS message type (0-63)
            /// </summary>
            public byte MessageType { get { return _messageType; } }

            /// <summary>
            /// Raw SBAS data field of 212 bits (last byte padded with zeros).
            /// </summary>
            public List<byte> Data { get { return _data; } }
            public Sbas M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        private Sbas m_root;
        private KaitaiStruct m_parent;
        public Sbas M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
