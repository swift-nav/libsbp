// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.nio.charset.Charset;
import java.util.ArrayList;

public class FileIo extends KaitaiStruct {
    public static FileIo fromFile(String fileName) throws IOException {
        return new FileIo(new ByteBufferKaitaiStream(fileName));
    }

    public FileIo(KaitaiStream _io) {
        this(_io, null, null);
    }

    public FileIo(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public FileIo(KaitaiStream _io, KaitaiStruct _parent, FileIo _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * The file write message writes a certain length (up to 255 bytes) of data
     * to a file at a given offset. Returns a copy of the original
     * MSG_FILEIO_WRITE_RESP message to check integrity of the write. The
     * sequence number in the request will be returned in the response. If
     * message is invalid, a followup MSG_PRINT message will print "Invalid
     * fileio write message". A device will only process this message when it
     * is received from sender ID 0x42.
     */
    public static class MsgFileioWriteReq extends KaitaiStruct {
        public static MsgFileioWriteReq fromFile(String fileName) throws IOException {
            return new MsgFileioWriteReq(new ByteBufferKaitaiStream(fileName));
        }

        public MsgFileioWriteReq(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgFileioWriteReq(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgFileioWriteReq(KaitaiStream _io, Sbp.Message _parent, FileIo _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sequence = this._io.readU4le();
            this.offset = this._io.readU4le();
            this.filename = new String(this._io.readBytesFull(), Charset.forName("ascii"));
            this.data = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.data.add(this._io.readU1());
                    i++;
                }
            }
        }
        private long sequence;
        private long offset;
        private String filename;
        private ArrayList<Integer> data;
        private FileIo _root;
        private Sbp.Message _parent;

        /**
         * Write sequence number
         */
        public long sequence() { return sequence; }

        /**
         * Offset into the file at which to start writing in bytes
         */
        public long offset() { return offset; }

        /**
         * Name of the file to write to
         */
        public String filename() { return filename; }

        /**
         * Variable-length array of data to write
         */
        public ArrayList<Integer> data() { return data; }
        public FileIo _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The advice on the optimal configuration for a FileIO transfer.  Newer
     * version of FileIO can support greater throughput by supporting a large
     * window of FileIO data that can be in-flight during read or write
     * operations.
     */
    public static class MsgFileioConfigResp extends KaitaiStruct {
        public static MsgFileioConfigResp fromFile(String fileName) throws IOException {
            return new MsgFileioConfigResp(new ByteBufferKaitaiStream(fileName));
        }

        public MsgFileioConfigResp(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgFileioConfigResp(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgFileioConfigResp(KaitaiStream _io, Sbp.Message _parent, FileIo _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sequence = this._io.readU4le();
            this.windowSize = this._io.readU4le();
            this.batchSize = this._io.readU4le();
            this.fileioVersion = this._io.readU4le();
        }
        private long sequence;
        private long windowSize;
        private long batchSize;
        private long fileioVersion;
        private FileIo _root;
        private Sbp.Message _parent;

        /**
         * Advice sequence number
         */
        public long sequence() { return sequence; }

        /**
         * The number of SBP packets in the data in-flight window
         */
        public long windowSize() { return windowSize; }

        /**
         * The number of SBP packets sent in one PDU
         */
        public long batchSize() { return batchSize; }

        /**
         * The version of FileIO that is supported
         */
        public long fileioVersion() { return fileioVersion; }
        public FileIo _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The file remove message deletes a file from the file system. If the
     * message is invalid, a followup MSG_PRINT message will print "Invalid
     * fileio remove message". A device will only process this message when it
     * is received from sender ID 0x42.
     */
    public static class MsgFileioRemove extends KaitaiStruct {
        public static MsgFileioRemove fromFile(String fileName) throws IOException {
            return new MsgFileioRemove(new ByteBufferKaitaiStream(fileName));
        }

        public MsgFileioRemove(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgFileioRemove(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgFileioRemove(KaitaiStream _io, Sbp.Message _parent, FileIo _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.filename = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private String filename;
        private FileIo _root;
        private Sbp.Message _parent;

        /**
         * Name of the file to delete
         */
        public String filename() { return filename; }
        public FileIo _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Requests advice on the optimal configuration for a FileIO transfer.
     * Newer version of FileIO can support greater throughput by supporting a
     * large window of FileIO data that can be in-flight during read or write
     * operations.
     */
    public static class MsgFileioConfigReq extends KaitaiStruct {
        public static MsgFileioConfigReq fromFile(String fileName) throws IOException {
            return new MsgFileioConfigReq(new ByteBufferKaitaiStream(fileName));
        }

        public MsgFileioConfigReq(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgFileioConfigReq(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgFileioConfigReq(KaitaiStream _io, Sbp.Message _parent, FileIo _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sequence = this._io.readU4le();
        }
        private long sequence;
        private FileIo _root;
        private Sbp.Message _parent;

        /**
         * Advice sequence number
         */
        public long sequence() { return sequence; }
        public FileIo _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The read directory message lists the files in a directory on the
     * device's onboard flash file system.  The offset parameter can be used to
     * skip the first n elements of the file list. Returns a
     * MSG_FILEIO_READ_DIR_RESP message containing the directory listings as a
     * NULL delimited list. The listing is chunked over multiple SBP packets.
     * The sequence number in the request will be returned in the response.  If
     * message is invalid, a followup MSG_PRINT message will print "Invalid
     * fileio read message". A device will only respond to this message when it
     * is received from sender ID 0x42.
     */
    public static class MsgFileioReadDirReq extends KaitaiStruct {
        public static MsgFileioReadDirReq fromFile(String fileName) throws IOException {
            return new MsgFileioReadDirReq(new ByteBufferKaitaiStream(fileName));
        }

        public MsgFileioReadDirReq(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgFileioReadDirReq(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgFileioReadDirReq(KaitaiStream _io, Sbp.Message _parent, FileIo _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sequence = this._io.readU4le();
            this.offset = this._io.readU4le();
            this.dirname = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private long sequence;
        private long offset;
        private String dirname;
        private FileIo _root;
        private Sbp.Message _parent;

        /**
         * Read sequence number
         */
        public long sequence() { return sequence; }

        /**
         * The offset to skip the first n elements of the file list
         */
        public long offset() { return offset; }

        /**
         * Name of the directory to list
         */
        public String dirname() { return dirname; }
        public FileIo _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The file write message writes a certain length (up to 255 bytes) of data
     * to a file at a given offset. The message is a copy of the original
     * MSG_FILEIO_WRITE_REQ message to check integrity of the write. The
     * sequence number in the response is preserved from the request.
     */
    public static class MsgFileioWriteResp extends KaitaiStruct {
        public static MsgFileioWriteResp fromFile(String fileName) throws IOException {
            return new MsgFileioWriteResp(new ByteBufferKaitaiStream(fileName));
        }

        public MsgFileioWriteResp(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgFileioWriteResp(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgFileioWriteResp(KaitaiStream _io, Sbp.Message _parent, FileIo _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sequence = this._io.readU4le();
        }
        private long sequence;
        private FileIo _root;
        private Sbp.Message _parent;

        /**
         * Write sequence number
         */
        public long sequence() { return sequence; }
        public FileIo _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The read directory message lists the files in a directory on the
     * device's onboard flash file system. Message contains the directory
     * listings as a NULL delimited list. The listing is chunked over multiple
     * SBP packets and the end of the list is identified by an packet with no
     * entries. The sequence number in the response is preserved from the
     * request.
     */
    public static class MsgFileioReadDirResp extends KaitaiStruct {
        public static MsgFileioReadDirResp fromFile(String fileName) throws IOException {
            return new MsgFileioReadDirResp(new ByteBufferKaitaiStream(fileName));
        }

        public MsgFileioReadDirResp(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgFileioReadDirResp(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgFileioReadDirResp(KaitaiStream _io, Sbp.Message _parent, FileIo _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sequence = this._io.readU4le();
            this.contents = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.contents.add(this._io.readU1());
                    i++;
                }
            }
        }
        private long sequence;
        private ArrayList<Integer> contents;
        private FileIo _root;
        private Sbp.Message _parent;

        /**
         * Read sequence number
         */
        public long sequence() { return sequence; }

        /**
         * Contents of read directory
         */
        public ArrayList<Integer> contents() { return contents; }
        public FileIo _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The file read message reads a certain length (up to 255 bytes) from a
     * given offset into a file, and returns the data in a MSG_FILEIO_READ_RESP
     * message where the message length field indicates how many bytes were
     * successfully read. The sequence number in the request will be returned
     * in the response. If the message is invalid, a followup MSG_PRINT message
     * will print "Invalid fileio read message". A device will only respond to
     * this message when it is received from sender ID 0x42.
     */
    public static class MsgFileioReadReq extends KaitaiStruct {
        public static MsgFileioReadReq fromFile(String fileName) throws IOException {
            return new MsgFileioReadReq(new ByteBufferKaitaiStream(fileName));
        }

        public MsgFileioReadReq(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgFileioReadReq(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgFileioReadReq(KaitaiStream _io, Sbp.Message _parent, FileIo _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sequence = this._io.readU4le();
            this.offset = this._io.readU4le();
            this.chunkSize = this._io.readU1();
            this.filename = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private long sequence;
        private long offset;
        private int chunkSize;
        private String filename;
        private FileIo _root;
        private Sbp.Message _parent;

        /**
         * Read sequence number
         */
        public long sequence() { return sequence; }

        /**
         * File offset
         */
        public long offset() { return offset; }

        /**
         * Chunk size to read
         */
        public int chunkSize() { return chunkSize; }

        /**
         * Name of the file to read from
         */
        public String filename() { return filename; }
        public FileIo _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * The file read message reads a certain length (up to 255 bytes) from a
     * given offset into a file, and returns the data in a message where the
     * message length field indicates how many bytes were successfully read.
     * The sequence number in the response is preserved from the request.
     */
    public static class MsgFileioReadResp extends KaitaiStruct {
        public static MsgFileioReadResp fromFile(String fileName) throws IOException {
            return new MsgFileioReadResp(new ByteBufferKaitaiStream(fileName));
        }

        public MsgFileioReadResp(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgFileioReadResp(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgFileioReadResp(KaitaiStream _io, Sbp.Message _parent, FileIo _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sequence = this._io.readU4le();
            this.contents = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.contents.add(this._io.readU1());
                    i++;
                }
            }
        }
        private long sequence;
        private ArrayList<Integer> contents;
        private FileIo _root;
        private Sbp.Message _parent;

        /**
         * Read sequence number
         */
        public long sequence() { return sequence; }

        /**
         * Contents of read file
         */
        public ArrayList<Integer> contents() { return contents; }
        public FileIo _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private FileIo _root;
    private KaitaiStruct _parent;
    public FileIo _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
