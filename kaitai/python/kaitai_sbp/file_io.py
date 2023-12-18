# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class FileIo(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgFileioWriteReq(KaitaiStruct):
        """The file write message writes a certain length (up to 255 bytes) of data
        to a file at a given offset. Returns a copy of the original
        MSG_FILEIO_WRITE_RESP message to check integrity of the write. The
        sequence number in the request will be returned in the response. If
        message is invalid, a followup MSG_PRINT message will print "Invalid
        fileio write message". A device will only process this message when it
        is received from sender ID 0x42.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sequence = self._io.read_u4le()
            self.offset = self._io.read_u4le()
            self.filename = (self._io.read_bytes_full()).decode(u"ascii")
            self.data = []
            i = 0
            while not self._io.is_eof():
                self.data.append(self._io.read_u1())
                i += 1



    class MsgFileioConfigResp(KaitaiStruct):
        """The advice on the optimal configuration for a FileIO transfer.  Newer
        version of FileIO can support greater throughput by supporting a large
        window of FileIO data that can be in-flight during read or write
        operations.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sequence = self._io.read_u4le()
            self.window_size = self._io.read_u4le()
            self.batch_size = self._io.read_u4le()
            self.fileio_version = self._io.read_u4le()


    class MsgFileioRemove(KaitaiStruct):
        """The file remove message deletes a file from the file system. If the
        message is invalid, a followup MSG_PRINT message will print "Invalid
        fileio remove message". A device will only process this message when it
        is received from sender ID 0x42.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.filename = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgFileioConfigReq(KaitaiStruct):
        """Requests advice on the optimal configuration for a FileIO transfer.
        Newer version of FileIO can support greater throughput by supporting a
        large window of FileIO data that can be in-flight during read or write
        operations.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sequence = self._io.read_u4le()


    class MsgFileioReadDirReq(KaitaiStruct):
        """The read directory message lists the files in a directory on the
        device's onboard flash file system.  The offset parameter can be used to
        skip the first n elements of the file list. Returns a
        MSG_FILEIO_READ_DIR_RESP message containing the directory listings as a
        NULL delimited list. The listing is chunked over multiple SBP packets.
        The sequence number in the request will be returned in the response.  If
        message is invalid, a followup MSG_PRINT message will print "Invalid
        fileio read message". A device will only respond to this message when it
        is received from sender ID 0x42.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sequence = self._io.read_u4le()
            self.offset = self._io.read_u4le()
            self.dirname = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgFileioWriteResp(KaitaiStruct):
        """The file write message writes a certain length (up to 255 bytes) of data
        to a file at a given offset. The message is a copy of the original
        MSG_FILEIO_WRITE_REQ message to check integrity of the write. The
        sequence number in the response is preserved from the request.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sequence = self._io.read_u4le()


    class MsgFileioReadDirResp(KaitaiStruct):
        """The read directory message lists the files in a directory on the
        device's onboard flash file system. Message contains the directory
        listings as a NULL delimited list. The listing is chunked over multiple
        SBP packets and the end of the list is identified by an packet with no
        entries. The sequence number in the response is preserved from the
        request.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sequence = self._io.read_u4le()
            self.contents = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgFileioReadReq(KaitaiStruct):
        """The file read message reads a certain length (up to 255 bytes) from a
        given offset into a file, and returns the data in a MSG_FILEIO_READ_RESP
        message where the message length field indicates how many bytes were
        successfully read. The sequence number in the request will be returned
        in the response. If the message is invalid, a followup MSG_PRINT message
        will print "Invalid fileio read message". A device will only respond to
        this message when it is received from sender ID 0x42.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sequence = self._io.read_u4le()
            self.offset = self._io.read_u4le()
            self.chunk_size = self._io.read_u1()
            self.filename = (self._io.read_bytes_full()).decode(u"ascii")


    class MsgFileioReadResp(KaitaiStruct):
        """The file read message reads a certain length (up to 255 bytes) from a
        given offset into a file, and returns the data in a message where the
        message length field indicates how many bytes were successfully read.
        The sequence number in the response is preserved from the request.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sequence = self._io.read_u4le()
            self.contents = []
            i = 0
            while not self._io.is_eof():
                self.contents.append(self._io.read_u1())
                i += 1




