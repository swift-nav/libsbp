// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class User : KaitaiStruct
    {
        public static User FromFile(string fileName)
        {
            return new User(new KaitaiStream(fileName));
        }

        public User(KaitaiStream p__io, KaitaiStruct p__parent = null, User p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// This message can contain any application specific user data up to a
        /// maximum length of 255 bytes per message.
        /// </summary>
        public partial class MsgUserData : KaitaiStruct
        {
            public static MsgUserData FromFile(string fileName)
            {
                return new MsgUserData(new KaitaiStream(fileName));
            }

            public MsgUserData(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, User p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _contents = new List<byte>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _contents.Add(m_io.ReadU1());
                        i++;
                    }
                }
            }
            private List<byte> _contents;
            private User m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// User data payload
            /// </summary>
            public List<byte> Contents { get { return _contents; } }
            public User M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }
        private User m_root;
        private KaitaiStruct m_parent;
        public User M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
