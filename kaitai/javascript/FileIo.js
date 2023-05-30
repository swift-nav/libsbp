// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.FileIo = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var FileIo = (function() {
  function FileIo(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  FileIo.prototype._read = function() {
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

  var MsgFileioWriteReq = FileIo.MsgFileioWriteReq = (function() {
    function MsgFileioWriteReq(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgFileioWriteReq.prototype._read = function() {
      this.sequence = this._io.readU4le();
      this.offset = this._io.readU4le();
      this.filename = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
      this.data = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.data.push(this._io.readU1());
        i++;
      }
    }

    /**
     * Write sequence number
     */

    /**
     * Offset into the file at which to start writing in bytes
     */

    /**
     * Name of the file to write to
     */

    /**
     * Variable-length array of data to write
     */

    return MsgFileioWriteReq;
  })();

  /**
   * The advice on the optimal configuration for a FileIO transfer.  Newer
   * version of FileIO can support greater throughput by supporting a large
   * window of FileIO data that can be in-flight during read or write
   * operations.
   */

  var MsgFileioConfigResp = FileIo.MsgFileioConfigResp = (function() {
    function MsgFileioConfigResp(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgFileioConfigResp.prototype._read = function() {
      this.sequence = this._io.readU4le();
      this.windowSize = this._io.readU4le();
      this.batchSize = this._io.readU4le();
      this.fileioVersion = this._io.readU4le();
    }

    /**
     * Advice sequence number
     */

    /**
     * The number of SBP packets in the data in-flight window
     */

    /**
     * The number of SBP packets sent in one PDU
     */

    /**
     * The version of FileIO that is supported
     */

    return MsgFileioConfigResp;
  })();

  /**
   * The file remove message deletes a file from the file system. If the
   * message is invalid, a followup MSG_PRINT message will print "Invalid
   * fileio remove message". A device will only process this message when it
   * is received from sender ID 0x42.
   */

  var MsgFileioRemove = FileIo.MsgFileioRemove = (function() {
    function MsgFileioRemove(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgFileioRemove.prototype._read = function() {
      this.filename = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * Name of the file to delete
     */

    return MsgFileioRemove;
  })();

  /**
   * Requests advice on the optimal configuration for a FileIO transfer.
   * Newer version of FileIO can support greater throughput by supporting a
   * large window of FileIO data that can be in-flight during read or write
   * operations.
   */

  var MsgFileioConfigReq = FileIo.MsgFileioConfigReq = (function() {
    function MsgFileioConfigReq(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgFileioConfigReq.prototype._read = function() {
      this.sequence = this._io.readU4le();
    }

    /**
     * Advice sequence number
     */

    return MsgFileioConfigReq;
  })();

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

  var MsgFileioReadDirReq = FileIo.MsgFileioReadDirReq = (function() {
    function MsgFileioReadDirReq(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgFileioReadDirReq.prototype._read = function() {
      this.sequence = this._io.readU4le();
      this.offset = this._io.readU4le();
      this.dirname = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * Read sequence number
     */

    /**
     * The offset to skip the first n elements of the file list
     */

    /**
     * Name of the directory to list
     */

    return MsgFileioReadDirReq;
  })();

  /**
   * The file write message writes a certain length (up to 255 bytes) of data
   * to a file at a given offset. The message is a copy of the original
   * MSG_FILEIO_WRITE_REQ message to check integrity of the write. The
   * sequence number in the response is preserved from the request.
   */

  var MsgFileioWriteResp = FileIo.MsgFileioWriteResp = (function() {
    function MsgFileioWriteResp(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgFileioWriteResp.prototype._read = function() {
      this.sequence = this._io.readU4le();
    }

    /**
     * Write sequence number
     */

    return MsgFileioWriteResp;
  })();

  /**
   * The read directory message lists the files in a directory on the
   * device's onboard flash file system. Message contains the directory
   * listings as a NULL delimited list. The listing is chunked over multiple
   * SBP packets and the end of the list is identified by an packet with no
   * entries. The sequence number in the response is preserved from the
   * request.
   */

  var MsgFileioReadDirResp = FileIo.MsgFileioReadDirResp = (function() {
    function MsgFileioReadDirResp(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgFileioReadDirResp.prototype._read = function() {
      this.sequence = this._io.readU4le();
      this.contents = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.contents.push(this._io.readU1());
        i++;
      }
    }

    /**
     * Read sequence number
     */

    /**
     * Contents of read directory
     */

    return MsgFileioReadDirResp;
  })();

  /**
   * The file read message reads a certain length (up to 255 bytes) from a
   * given offset into a file, and returns the data in a MSG_FILEIO_READ_RESP
   * message where the message length field indicates how many bytes were
   * successfully read. The sequence number in the request will be returned
   * in the response. If the message is invalid, a followup MSG_PRINT message
   * will print "Invalid fileio read message". A device will only respond to
   * this message when it is received from sender ID 0x42.
   */

  var MsgFileioReadReq = FileIo.MsgFileioReadReq = (function() {
    function MsgFileioReadReq(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgFileioReadReq.prototype._read = function() {
      this.sequence = this._io.readU4le();
      this.offset = this._io.readU4le();
      this.chunkSize = this._io.readU1();
      this.filename = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * Read sequence number
     */

    /**
     * File offset
     */

    /**
     * Chunk size to read
     */

    /**
     * Name of the file to read from
     */

    return MsgFileioReadReq;
  })();

  /**
   * The file read message reads a certain length (up to 255 bytes) from a
   * given offset into a file, and returns the data in a message where the
   * message length field indicates how many bytes were successfully read.
   * The sequence number in the response is preserved from the request.
   */

  var MsgFileioReadResp = FileIo.MsgFileioReadResp = (function() {
    function MsgFileioReadResp(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgFileioReadResp.prototype._read = function() {
      this.sequence = this._io.readU4le();
      this.contents = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.contents.push(this._io.readU1());
        i++;
      }
    }

    /**
     * Read sequence number
     */

    /**
     * Contents of read file
     */

    return MsgFileioReadResp;
  })();

  return FileIo;
})();
return FileIo;
}));
