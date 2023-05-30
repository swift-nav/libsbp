// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class Logging : KaitaiStruct
    {
        public static Logging FromFile(string fileName)
        {
            return new Logging(new KaitaiStream(fileName));
        }

        public Logging(KaitaiStream p__io, KaitaiStruct p__parent = null, Logging p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// This message contains a human-readable payload string from the device
        /// containing errors, warnings and informational messages at ERROR,
        /// WARNING, DEBUG, INFO logging levels.
        /// </summary>
        public partial class MsgLog : KaitaiStruct
        {
            public static MsgLog FromFile(string fileName)
            {
                return new MsgLog(new KaitaiStream(fileName));
            }

            public MsgLog(KaitaiStream p__io, Sbp.Message p__parent = null, Logging p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _level = m_io.ReadU1();
                _text = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private byte _level;
            private string _text;
            private Logging m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Logging level
            /// </summary>
            public byte Level { get { return _level; } }

            /// <summary>
            /// Human-readable string
            /// </summary>
            public string Text { get { return _text; } }
            public Logging M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message provides the ability to forward messages over SBP.  This
        /// may take the form of wrapping up SBP messages received by Piksi for
        /// logging purposes or wrapping another protocol with SBP.
        /// 
        /// The source identifier indicates from what interface a forwarded stream
        /// derived. The protocol identifier identifies what the expected protocol
        /// the forwarded msg contains. Protocol 0 represents SBP and the remaining
        /// values are implementation defined.
        /// </summary>
        public partial class MsgFwd : KaitaiStruct
        {
            public static MsgFwd FromFile(string fileName)
            {
                return new MsgFwd(new KaitaiStream(fileName));
            }

            public MsgFwd(KaitaiStream p__io, Sbp.Message p__parent = null, Logging p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _source = m_io.ReadU1();
                _protocol = m_io.ReadU1();
                _fwdPayload = new List<byte>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _fwdPayload.Add(m_io.ReadU1());
                        i++;
                    }
                }
            }
            private byte _source;
            private byte _protocol;
            private List<byte> _fwdPayload;
            private Logging m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// source identifier
            /// </summary>
            public byte Source { get { return _source; } }

            /// <summary>
            /// protocol identifier
            /// </summary>
            public byte Protocol { get { return _protocol; } }

            /// <summary>
            /// variable length wrapped binary message
            /// </summary>
            public List<byte> FwdPayload { get { return _fwdPayload; } }
            public Logging M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgPrintDep : KaitaiStruct
        {
            public static MsgPrintDep FromFile(string fileName)
            {
                return new MsgPrintDep(new KaitaiStream(fileName));
            }

            public MsgPrintDep(KaitaiStream p__io, Sbp.Message p__parent = null, Logging p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _text = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private string _text;
            private Logging m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Human-readable string
            /// </summary>
            public string Text { get { return _text; } }
            public Logging M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        private Logging m_root;
        private KaitaiStruct m_parent;
        public Logging M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
