// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class Bootload : KaitaiStruct
    {
        public static Bootload FromFile(string fileName)
        {
            return new Bootload(new KaitaiStream(fileName));
        }

        public Bootload(KaitaiStream p__io, KaitaiStruct p__parent = null, Bootload p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// The device message from the host reads a unique device identifier from
        /// the SwiftNAP, an FPGA. The host requests the ID by sending a
        /// MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
        /// MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
        /// that this ID is tied to the FPGA, and not related to the Piksi's serial
        /// number.
        /// </summary>
        public partial class MsgNapDeviceDnaReq : KaitaiStruct
        {
            public static MsgNapDeviceDnaReq FromFile(string fileName)
            {
                return new MsgNapDeviceDnaReq(new KaitaiStream(fileName));
            }

            public MsgNapDeviceDnaReq(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Bootload p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
            }
            private Bootload m_root;
            private Sbp.SbpMessage m_parent;
            public Bootload M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The host initiates the bootloader to jump to the application.
        /// </summary>
        public partial class MsgBootloaderJumpToApp : KaitaiStruct
        {
            public static MsgBootloaderJumpToApp FromFile(string fileName)
            {
                return new MsgBootloaderJumpToApp(new KaitaiStream(fileName));
            }

            public MsgBootloaderJumpToApp(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Bootload p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _jump = m_io.ReadU1();
            }
            private byte _jump;
            private Bootload m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Ignored by the device
            /// </summary>
            public byte Jump { get { return _jump; } }
            public Bootload M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The handshake message response from the device establishes a handshake
        /// between the device bootloader and the host. The request from the host is
        /// MSG_BOOTLOADER_HANDSHAKE_REQ.  The payload contains the bootloader
        /// version number and the SBP protocol version number.
        /// </summary>
        public partial class MsgBootloaderHandshakeResp : KaitaiStruct
        {
            public static MsgBootloaderHandshakeResp FromFile(string fileName)
            {
                return new MsgBootloaderHandshakeResp(new KaitaiStream(fileName));
            }

            public MsgBootloaderHandshakeResp(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Bootload p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _flags = m_io.ReadU4le();
                _version = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private uint _flags;
            private string _version;
            private Bootload m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Bootloader flags
            /// </summary>
            public uint Flags { get { return _flags; } }

            /// <summary>
            /// Bootloader version number
            /// </summary>
            public string Version { get { return _version; } }
            public Bootload M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The device message from the host reads a unique device identifier from
        /// the SwiftNAP, an FPGA. The host requests the ID by sending a
        /// MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
        /// MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
        /// that this ID is tied to the FPGA, and not related to the Piksi's serial
        /// number.
        /// </summary>
        public partial class MsgNapDeviceDnaResp : KaitaiStruct
        {
            public static MsgNapDeviceDnaResp FromFile(string fileName)
            {
                return new MsgNapDeviceDnaResp(new KaitaiStream(fileName));
            }

            public MsgNapDeviceDnaResp(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Bootload p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _dna = new List<byte>();
                for (var i = 0; i < 8; i++)
                {
                    _dna.Add(m_io.ReadU1());
                }
            }
            private List<byte> _dna;
            private Bootload m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the
            /// right.
            /// </summary>
            public List<byte> Dna { get { return _dna; } }
            public Bootload M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The handshake message request from the host establishes a handshake
        /// between the device bootloader and the host. The response from the device
        /// is MSG_BOOTLOADER_HANDSHAKE_RESP.
        /// </summary>
        public partial class MsgBootloaderHandshakeReq : KaitaiStruct
        {
            public static MsgBootloaderHandshakeReq FromFile(string fileName)
            {
                return new MsgBootloaderHandshakeReq(new KaitaiStream(fileName));
            }

            public MsgBootloaderHandshakeReq(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Bootload p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
            }
            private Bootload m_root;
            private Sbp.SbpMessage m_parent;
            public Bootload M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgBootloaderHandshakeDepA : KaitaiStruct
        {
            public static MsgBootloaderHandshakeDepA FromFile(string fileName)
            {
                return new MsgBootloaderHandshakeDepA(new KaitaiStream(fileName));
            }

            public MsgBootloaderHandshakeDepA(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Bootload p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _handshake = new List<byte>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _handshake.Add(m_io.ReadU1());
                        i++;
                    }
                }
            }
            private List<byte> _handshake;
            private Bootload m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Version number string (not NULL terminated)
            /// </summary>
            public List<byte> Handshake { get { return _handshake; } }
            public Bootload M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }
        private Bootload m_root;
        private KaitaiStruct m_parent;
        public Bootload M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
