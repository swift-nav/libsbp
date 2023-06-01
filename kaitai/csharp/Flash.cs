// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class Flash : KaitaiStruct
    {
        public static Flash FromFile(string fileName)
        {
            return new Flash(new KaitaiStream(fileName));
        }

        public Flash(KaitaiStream p__io, KaitaiStruct p__parent = null, Flash p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// This message defines success or failure codes for a variety of flash
        /// memory requests from the host to the device. Flash read and write
        /// messages, such as MSG_FLASH_READ_REQ, or MSG_FLASH_PROGRAM, may return
        /// this message on failure.
        /// </summary>
        public partial class MsgFlashDone : KaitaiStruct
        {
            public static MsgFlashDone FromFile(string fileName)
            {
                return new MsgFlashDone(new KaitaiStream(fileName));
            }

            public MsgFlashDone(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Flash p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _response = m_io.ReadU1();
            }
            private byte _response;
            private Flash m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Response flags
            /// </summary>
            public byte Response { get { return _response; } }
            public Flash M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The flash status message writes to the 8-bit M25 flash status register.
        /// The device replies with a MSG_FLASH_DONE message.
        /// </summary>
        public partial class MsgM25FlashWriteStatus : KaitaiStruct
        {
            public static MsgM25FlashWriteStatus FromFile(string fileName)
            {
                return new MsgM25FlashWriteStatus(new KaitaiStream(fileName));
            }

            public MsgM25FlashWriteStatus(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Flash p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _status = new List<byte>();
                for (var i = 0; i < 1; i++)
                {
                    _status.Add(m_io.ReadU1());
                }
            }
            private List<byte> _status;
            private Flash m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Byte to write to the M25 flash status register
            /// </summary>
            public List<byte> Status { get { return _status; } }
            public Flash M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The flash read message reads a set of addresses of either the STM or M25
        /// onboard flash. The device replies with a MSG_FLASH_READ_RESP message
        /// containing either the read data on success or a MSG_FLASH_DONE message
        /// containing the return code FLASH_INVALID_LEN (2) if the maximum read
        /// size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
        /// the allowed range.
        /// </summary>
        public partial class MsgFlashReadResp : KaitaiStruct
        {
            public static MsgFlashReadResp FromFile(string fileName)
            {
                return new MsgFlashReadResp(new KaitaiStream(fileName));
            }

            public MsgFlashReadResp(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Flash p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _target = m_io.ReadU1();
                _addrStart = new List<byte>();
                for (var i = 0; i < 3; i++)
                {
                    _addrStart.Add(m_io.ReadU1());
                }
                _addrLen = m_io.ReadU1();
            }
            private byte _target;
            private List<byte> _addrStart;
            private byte _addrLen;
            private Flash m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Target flags
            /// </summary>
            public byte Target { get { return _target; } }

            /// <summary>
            /// Starting address offset to read from
            /// </summary>
            public List<byte> AddrStart { get { return _addrStart; } }

            /// <summary>
            /// Length of set of addresses to read, counting up from starting
            /// address
            /// </summary>
            public byte AddrLen { get { return _addrLen; } }
            public Flash M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The flash erase message from the host erases a sector of either the STM
        /// or M25 onboard flash memory. The device will reply with a MSG_FLASH_DONE
        /// message containing the return code - FLASH_OK (0) on success or
        /// FLASH_INVALID_FLASH (1) if the flash specified is invalid.
        /// </summary>
        public partial class MsgFlashErase : KaitaiStruct
        {
            public static MsgFlashErase FromFile(string fileName)
            {
                return new MsgFlashErase(new KaitaiStream(fileName));
            }

            public MsgFlashErase(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Flash p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _target = m_io.ReadU1();
                _sectorNum = m_io.ReadU4le();
            }
            private byte _target;
            private uint _sectorNum;
            private Flash m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Target flags
            /// </summary>
            public byte Target { get { return _target; } }

            /// <summary>
            /// Flash sector number to erase (0-11 for the STM, 0-15 for the M25)
            /// </summary>
            public uint SectorNum { get { return _sectorNum; } }
            public Flash M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reads the device's hard-coded unique ID. The host requests
        /// the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
        /// MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
        /// </summary>
        public partial class MsgStmUniqueIdResp : KaitaiStruct
        {
            public static MsgStmUniqueIdResp FromFile(string fileName)
            {
                return new MsgStmUniqueIdResp(new KaitaiStream(fileName));
            }

            public MsgStmUniqueIdResp(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Flash p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _stmId = new List<byte>();
                for (var i = 0; i < 12; i++)
                {
                    _stmId.Add(m_io.ReadU1());
                }
            }
            private List<byte> _stmId;
            private Flash m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Device unique ID
            /// </summary>
            public List<byte> StmId { get { return _stmId; } }
            public Flash M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reads the device's hard-coded unique ID. The host requests
        /// the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
        /// MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
        /// </summary>
        public partial class MsgStmUniqueIdReq : KaitaiStruct
        {
            public static MsgStmUniqueIdReq FromFile(string fileName)
            {
                return new MsgStmUniqueIdReq(new KaitaiStream(fileName));
            }

            public MsgStmUniqueIdReq(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Flash p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
            }
            private Flash m_root;
            private Sbp.SbpMessage m_parent;
            public Flash M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The flash program message programs a set of addresses of either the STM
        /// or M25 flash. The device replies with either a MSG_FLASH_DONE message
        /// containing the return code FLASH_OK (0) on success, or FLASH_INVALID_LEN
        /// (2) if the maximum write size is exceeded. Note that the sector-
        /// containing addresses must be erased before addresses can be programmed.
        /// </summary>
        public partial class MsgFlashProgram : KaitaiStruct
        {
            public static MsgFlashProgram FromFile(string fileName)
            {
                return new MsgFlashProgram(new KaitaiStream(fileName));
            }

            public MsgFlashProgram(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Flash p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _target = m_io.ReadU1();
                _addrStart = new List<byte>();
                for (var i = 0; i < 3; i++)
                {
                    _addrStart.Add(m_io.ReadU1());
                }
                _addrLen = m_io.ReadU1();
                _data = new List<byte>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _data.Add(m_io.ReadU1());
                        i++;
                    }
                }
            }
            private byte _target;
            private List<byte> _addrStart;
            private byte _addrLen;
            private List<byte> _data;
            private Flash m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Target flags
            /// </summary>
            public byte Target { get { return _target; } }

            /// <summary>
            /// Starting address offset to program
            /// </summary>
            public List<byte> AddrStart { get { return _addrStart; } }

            /// <summary>
            /// Length of set of addresses to program, counting up from starting
            /// address
            /// </summary>
            public byte AddrLen { get { return _addrLen; } }

            /// <summary>
            /// Data to program addresses with, with length N=addr_len
            /// </summary>
            public List<byte> Data { get { return _data; } }
            public Flash M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The flash read message reads a set of addresses of either the STM or M25
        /// onboard flash. The device replies with a MSG_FLASH_READ_RESP message
        /// containing either the read data on success or a MSG_FLASH_DONE message
        /// containing the return code FLASH_INVALID_LEN (2) if the maximum read
        /// size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
        /// the allowed range.
        /// </summary>
        public partial class MsgFlashReadReq : KaitaiStruct
        {
            public static MsgFlashReadReq FromFile(string fileName)
            {
                return new MsgFlashReadReq(new KaitaiStream(fileName));
            }

            public MsgFlashReadReq(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Flash p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _target = m_io.ReadU1();
                _addrStart = new List<byte>();
                for (var i = 0; i < 3; i++)
                {
                    _addrStart.Add(m_io.ReadU1());
                }
                _addrLen = m_io.ReadU1();
            }
            private byte _target;
            private List<byte> _addrStart;
            private byte _addrLen;
            private Flash m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Target flags
            /// </summary>
            public byte Target { get { return _target; } }

            /// <summary>
            /// Starting address offset to read from
            /// </summary>
            public List<byte> AddrStart { get { return _addrStart; } }

            /// <summary>
            /// Length of set of addresses to read, counting up from starting
            /// address
            /// </summary>
            public byte AddrLen { get { return _addrLen; } }
            public Flash M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The flash unlock message unlocks a sector of the STM flash memory. The
        /// device replies with a MSG_FLASH_DONE message.
        /// </summary>
        public partial class MsgStmFlashUnlockSector : KaitaiStruct
        {
            public static MsgStmFlashUnlockSector FromFile(string fileName)
            {
                return new MsgStmFlashUnlockSector(new KaitaiStream(fileName));
            }

            public MsgStmFlashUnlockSector(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Flash p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sector = m_io.ReadU4le();
            }
            private uint _sector;
            private Flash m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Flash sector number to unlock
            /// </summary>
            public uint Sector { get { return _sector; } }
            public Flash M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The flash lock message locks a sector of the STM flash memory. The
        /// device replies with a MSG_FLASH_DONE message.
        /// </summary>
        public partial class MsgStmFlashLockSector : KaitaiStruct
        {
            public static MsgStmFlashLockSector FromFile(string fileName)
            {
                return new MsgStmFlashLockSector(new KaitaiStream(fileName));
            }

            public MsgStmFlashLockSector(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Flash p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sector = m_io.ReadU4le();
            }
            private uint _sector;
            private Flash m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Flash sector number to lock
            /// </summary>
            public uint Sector { get { return _sector; } }
            public Flash M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }
        private Flash m_root;
        private KaitaiStruct m_parent;
        public Flash M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
