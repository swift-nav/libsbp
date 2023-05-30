<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class FileIo extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \FileIo $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
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

namespace FileIo {
    class MsgFileioWriteReq extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \FileIo $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sequence = $this->_io->readU4le();
            $this->_m_offset = $this->_io->readU4le();
            $this->_m_filename = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
            $this->_m_data = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_data[] = $this->_io->readU1();
                $i++;
            }
        }
        protected $_m_sequence;
        protected $_m_offset;
        protected $_m_filename;
        protected $_m_data;

        /**
         * Write sequence number
         */
        public function sequence() { return $this->_m_sequence; }

        /**
         * Offset into the file at which to start writing in bytes
         */
        public function offset() { return $this->_m_offset; }

        /**
         * Name of the file to write to
         */
        public function filename() { return $this->_m_filename; }

        /**
         * Variable-length array of data to write
         */
        public function data() { return $this->_m_data; }
    }
}

/**
 * The advice on the optimal configuration for a FileIO transfer.  Newer
 * version of FileIO can support greater throughput by supporting a large
 * window of FileIO data that can be in-flight during read or write
 * operations.
 */

namespace FileIo {
    class MsgFileioConfigResp extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \FileIo $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sequence = $this->_io->readU4le();
            $this->_m_windowSize = $this->_io->readU4le();
            $this->_m_batchSize = $this->_io->readU4le();
            $this->_m_fileioVersion = $this->_io->readU4le();
        }
        protected $_m_sequence;
        protected $_m_windowSize;
        protected $_m_batchSize;
        protected $_m_fileioVersion;

        /**
         * Advice sequence number
         */
        public function sequence() { return $this->_m_sequence; }

        /**
         * The number of SBP packets in the data in-flight window
         */
        public function windowSize() { return $this->_m_windowSize; }

        /**
         * The number of SBP packets sent in one PDU
         */
        public function batchSize() { return $this->_m_batchSize; }

        /**
         * The version of FileIO that is supported
         */
        public function fileioVersion() { return $this->_m_fileioVersion; }
    }
}

/**
 * The file remove message deletes a file from the file system. If the
 * message is invalid, a followup MSG_PRINT message will print "Invalid
 * fileio remove message". A device will only process this message when it
 * is received from sender ID 0x42.
 */

namespace FileIo {
    class MsgFileioRemove extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \FileIo $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_filename = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_filename;

        /**
         * Name of the file to delete
         */
        public function filename() { return $this->_m_filename; }
    }
}

/**
 * Requests advice on the optimal configuration for a FileIO transfer.
 * Newer version of FileIO can support greater throughput by supporting a
 * large window of FileIO data that can be in-flight during read or write
 * operations.
 */

namespace FileIo {
    class MsgFileioConfigReq extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \FileIo $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sequence = $this->_io->readU4le();
        }
        protected $_m_sequence;

        /**
         * Advice sequence number
         */
        public function sequence() { return $this->_m_sequence; }
    }
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

namespace FileIo {
    class MsgFileioReadDirReq extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \FileIo $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sequence = $this->_io->readU4le();
            $this->_m_offset = $this->_io->readU4le();
            $this->_m_dirname = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_sequence;
        protected $_m_offset;
        protected $_m_dirname;

        /**
         * Read sequence number
         */
        public function sequence() { return $this->_m_sequence; }

        /**
         * The offset to skip the first n elements of the file list
         */
        public function offset() { return $this->_m_offset; }

        /**
         * Name of the directory to list
         */
        public function dirname() { return $this->_m_dirname; }
    }
}

/**
 * The file write message writes a certain length (up to 255 bytes) of data
 * to a file at a given offset. The message is a copy of the original
 * MSG_FILEIO_WRITE_REQ message to check integrity of the write. The
 * sequence number in the response is preserved from the request.
 */

namespace FileIo {
    class MsgFileioWriteResp extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \FileIo $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sequence = $this->_io->readU4le();
        }
        protected $_m_sequence;

        /**
         * Write sequence number
         */
        public function sequence() { return $this->_m_sequence; }
    }
}

/**
 * The read directory message lists the files in a directory on the
 * device's onboard flash file system. Message contains the directory
 * listings as a NULL delimited list. The listing is chunked over multiple
 * SBP packets and the end of the list is identified by an packet with no
 * entries. The sequence number in the response is preserved from the
 * request.
 */

namespace FileIo {
    class MsgFileioReadDirResp extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \FileIo $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sequence = $this->_io->readU4le();
            $this->_m_contents = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_contents[] = $this->_io->readU1();
                $i++;
            }
        }
        protected $_m_sequence;
        protected $_m_contents;

        /**
         * Read sequence number
         */
        public function sequence() { return $this->_m_sequence; }

        /**
         * Contents of read directory
         */
        public function contents() { return $this->_m_contents; }
    }
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

namespace FileIo {
    class MsgFileioReadReq extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \FileIo $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sequence = $this->_io->readU4le();
            $this->_m_offset = $this->_io->readU4le();
            $this->_m_chunkSize = $this->_io->readU1();
            $this->_m_filename = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_sequence;
        protected $_m_offset;
        protected $_m_chunkSize;
        protected $_m_filename;

        /**
         * Read sequence number
         */
        public function sequence() { return $this->_m_sequence; }

        /**
         * File offset
         */
        public function offset() { return $this->_m_offset; }

        /**
         * Chunk size to read
         */
        public function chunkSize() { return $this->_m_chunkSize; }

        /**
         * Name of the file to read from
         */
        public function filename() { return $this->_m_filename; }
    }
}

/**
 * The file read message reads a certain length (up to 255 bytes) from a
 * given offset into a file, and returns the data in a message where the
 * message length field indicates how many bytes were successfully read.
 * The sequence number in the response is preserved from the request.
 */

namespace FileIo {
    class MsgFileioReadResp extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \FileIo $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sequence = $this->_io->readU4le();
            $this->_m_contents = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_contents[] = $this->_io->readU1();
                $i++;
            }
        }
        protected $_m_sequence;
        protected $_m_contents;

        /**
         * Read sequence number
         */
        public function sequence() { return $this->_m_sequence; }

        /**
         * Contents of read file
         */
        public function contents() { return $this->_m_contents; }
    }
}
