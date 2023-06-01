// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class FileIo : KaitaiStruct
    {
        public static FileIo FromFile(string fileName)
        {
            return new FileIo(new KaitaiStream(fileName));
        }

        public FileIo(KaitaiStream p__io, KaitaiStruct p__parent = null, FileIo p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// The file write message writes a certain length (up to 255 bytes) of data
        /// to a file at a given offset. Returns a copy of the original
        /// MSG_FILEIO_WRITE_RESP message to check integrity of the write. The
        /// sequence number in the request will be returned in the response. If
        /// message is invalid, a followup MSG_PRINT message will print &quot;Invalid
        /// fileio write message&quot;. A device will only process this message when it
        /// is received from sender ID 0x42.
        /// </summary>
        public partial class MsgFileioWriteReq : KaitaiStruct
        {
            public static MsgFileioWriteReq FromFile(string fileName)
            {
                return new MsgFileioWriteReq(new KaitaiStream(fileName));
            }

            public MsgFileioWriteReq(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, FileIo p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sequence = m_io.ReadU4le();
                _offset = m_io.ReadU4le();
                _filename = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
                _data = new List<byte>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _data.Add(m_io.ReadU1());
                        i++;
                    }
                }
            }
            private uint _sequence;
            private uint _offset;
            private string _filename;
            private List<byte> _data;
            private FileIo m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Write sequence number
            /// </summary>
            public uint Sequence { get { return _sequence; } }

            /// <summary>
            /// Offset into the file at which to start writing in bytes
            /// </summary>
            public uint Offset { get { return _offset; } }

            /// <summary>
            /// Name of the file to write to
            /// </summary>
            public string Filename { get { return _filename; } }

            /// <summary>
            /// Variable-length array of data to write
            /// </summary>
            public List<byte> Data { get { return _data; } }
            public FileIo M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The advice on the optimal configuration for a FileIO transfer.  Newer
        /// version of FileIO can support greater throughput by supporting a large
        /// window of FileIO data that can be in-flight during read or write
        /// operations.
        /// </summary>
        public partial class MsgFileioConfigResp : KaitaiStruct
        {
            public static MsgFileioConfigResp FromFile(string fileName)
            {
                return new MsgFileioConfigResp(new KaitaiStream(fileName));
            }

            public MsgFileioConfigResp(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, FileIo p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sequence = m_io.ReadU4le();
                _windowSize = m_io.ReadU4le();
                _batchSize = m_io.ReadU4le();
                _fileioVersion = m_io.ReadU4le();
            }
            private uint _sequence;
            private uint _windowSize;
            private uint _batchSize;
            private uint _fileioVersion;
            private FileIo m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Advice sequence number
            /// </summary>
            public uint Sequence { get { return _sequence; } }

            /// <summary>
            /// The number of SBP packets in the data in-flight window
            /// </summary>
            public uint WindowSize { get { return _windowSize; } }

            /// <summary>
            /// The number of SBP packets sent in one PDU
            /// </summary>
            public uint BatchSize { get { return _batchSize; } }

            /// <summary>
            /// The version of FileIO that is supported
            /// </summary>
            public uint FileioVersion { get { return _fileioVersion; } }
            public FileIo M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The file remove message deletes a file from the file system. If the
        /// message is invalid, a followup MSG_PRINT message will print &quot;Invalid
        /// fileio remove message&quot;. A device will only process this message when it
        /// is received from sender ID 0x42.
        /// </summary>
        public partial class MsgFileioRemove : KaitaiStruct
        {
            public static MsgFileioRemove FromFile(string fileName)
            {
                return new MsgFileioRemove(new KaitaiStream(fileName));
            }

            public MsgFileioRemove(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, FileIo p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _filename = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private string _filename;
            private FileIo m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Name of the file to delete
            /// </summary>
            public string Filename { get { return _filename; } }
            public FileIo M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Requests advice on the optimal configuration for a FileIO transfer.
        /// Newer version of FileIO can support greater throughput by supporting a
        /// large window of FileIO data that can be in-flight during read or write
        /// operations.
        /// </summary>
        public partial class MsgFileioConfigReq : KaitaiStruct
        {
            public static MsgFileioConfigReq FromFile(string fileName)
            {
                return new MsgFileioConfigReq(new KaitaiStream(fileName));
            }

            public MsgFileioConfigReq(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, FileIo p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sequence = m_io.ReadU4le();
            }
            private uint _sequence;
            private FileIo m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Advice sequence number
            /// </summary>
            public uint Sequence { get { return _sequence; } }
            public FileIo M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The read directory message lists the files in a directory on the
        /// device's onboard flash file system.  The offset parameter can be used to
        /// skip the first n elements of the file list. Returns a
        /// MSG_FILEIO_READ_DIR_RESP message containing the directory listings as a
        /// NULL delimited list. The listing is chunked over multiple SBP packets.
        /// The sequence number in the request will be returned in the response.  If
        /// message is invalid, a followup MSG_PRINT message will print &quot;Invalid
        /// fileio read message&quot;. A device will only respond to this message when it
        /// is received from sender ID 0x42.
        /// </summary>
        public partial class MsgFileioReadDirReq : KaitaiStruct
        {
            public static MsgFileioReadDirReq FromFile(string fileName)
            {
                return new MsgFileioReadDirReq(new KaitaiStream(fileName));
            }

            public MsgFileioReadDirReq(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, FileIo p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sequence = m_io.ReadU4le();
                _offset = m_io.ReadU4le();
                _dirname = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private uint _sequence;
            private uint _offset;
            private string _dirname;
            private FileIo m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Read sequence number
            /// </summary>
            public uint Sequence { get { return _sequence; } }

            /// <summary>
            /// The offset to skip the first n elements of the file list
            /// </summary>
            public uint Offset { get { return _offset; } }

            /// <summary>
            /// Name of the directory to list
            /// </summary>
            public string Dirname { get { return _dirname; } }
            public FileIo M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The file write message writes a certain length (up to 255 bytes) of data
        /// to a file at a given offset. The message is a copy of the original
        /// MSG_FILEIO_WRITE_REQ message to check integrity of the write. The
        /// sequence number in the response is preserved from the request.
        /// </summary>
        public partial class MsgFileioWriteResp : KaitaiStruct
        {
            public static MsgFileioWriteResp FromFile(string fileName)
            {
                return new MsgFileioWriteResp(new KaitaiStream(fileName));
            }

            public MsgFileioWriteResp(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, FileIo p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sequence = m_io.ReadU4le();
            }
            private uint _sequence;
            private FileIo m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Write sequence number
            /// </summary>
            public uint Sequence { get { return _sequence; } }
            public FileIo M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The read directory message lists the files in a directory on the
        /// device's onboard flash file system. Message contains the directory
        /// listings as a NULL delimited list. The listing is chunked over multiple
        /// SBP packets and the end of the list is identified by an packet with no
        /// entries. The sequence number in the response is preserved from the
        /// request.
        /// </summary>
        public partial class MsgFileioReadDirResp : KaitaiStruct
        {
            public static MsgFileioReadDirResp FromFile(string fileName)
            {
                return new MsgFileioReadDirResp(new KaitaiStream(fileName));
            }

            public MsgFileioReadDirResp(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, FileIo p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sequence = m_io.ReadU4le();
                _contents = new List<byte>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _contents.Add(m_io.ReadU1());
                        i++;
                    }
                }
            }
            private uint _sequence;
            private List<byte> _contents;
            private FileIo m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Read sequence number
            /// </summary>
            public uint Sequence { get { return _sequence; } }

            /// <summary>
            /// Contents of read directory
            /// </summary>
            public List<byte> Contents { get { return _contents; } }
            public FileIo M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The file read message reads a certain length (up to 255 bytes) from a
        /// given offset into a file, and returns the data in a MSG_FILEIO_READ_RESP
        /// message where the message length field indicates how many bytes were
        /// successfully read. The sequence number in the request will be returned
        /// in the response. If the message is invalid, a followup MSG_PRINT message
        /// will print &quot;Invalid fileio read message&quot;. A device will only respond to
        /// this message when it is received from sender ID 0x42.
        /// </summary>
        public partial class MsgFileioReadReq : KaitaiStruct
        {
            public static MsgFileioReadReq FromFile(string fileName)
            {
                return new MsgFileioReadReq(new KaitaiStream(fileName));
            }

            public MsgFileioReadReq(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, FileIo p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sequence = m_io.ReadU4le();
                _offset = m_io.ReadU4le();
                _chunkSize = m_io.ReadU1();
                _filename = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private uint _sequence;
            private uint _offset;
            private byte _chunkSize;
            private string _filename;
            private FileIo m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Read sequence number
            /// </summary>
            public uint Sequence { get { return _sequence; } }

            /// <summary>
            /// File offset
            /// </summary>
            public uint Offset { get { return _offset; } }

            /// <summary>
            /// Chunk size to read
            /// </summary>
            public byte ChunkSize { get { return _chunkSize; } }

            /// <summary>
            /// Name of the file to read from
            /// </summary>
            public string Filename { get { return _filename; } }
            public FileIo M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The file read message reads a certain length (up to 255 bytes) from a
        /// given offset into a file, and returns the data in a message where the
        /// message length field indicates how many bytes were successfully read.
        /// The sequence number in the response is preserved from the request.
        /// </summary>
        public partial class MsgFileioReadResp : KaitaiStruct
        {
            public static MsgFileioReadResp FromFile(string fileName)
            {
                return new MsgFileioReadResp(new KaitaiStream(fileName));
            }

            public MsgFileioReadResp(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, FileIo p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sequence = m_io.ReadU4le();
                _contents = new List<byte>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _contents.Add(m_io.ReadU1());
                        i++;
                    }
                }
            }
            private uint _sequence;
            private List<byte> _contents;
            private FileIo m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Read sequence number
            /// </summary>
            public uint Sequence { get { return _sequence; } }

            /// <summary>
            /// Contents of read file
            /// </summary>
            public List<byte> Contents { get { return _contents; } }
            public FileIo M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }
        private FileIo m_root;
        private KaitaiStruct m_parent;
        public FileIo M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
