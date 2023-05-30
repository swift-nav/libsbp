from .gnss import *
# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Ndb(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgNdbEvent(KaitaiStruct):
        """This message is sent out when an object is stored into NDB. If needed
        message could also be sent out when fetching an object from NDB.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.recv_time = self._io.read_u8le()
            self.event = self._io.read_u1()
            self.object_type = self._io.read_u1()
            self.result = self._io.read_u1()
            self.data_source = self._io.read_u1()
            self.object_sid = Gnss.GnssSignal(self._io, self, self._root)
            self.src_sid = Gnss.GnssSignal(self._io, self, self._root)
            self.original_sender = self._io.read_u2le()



