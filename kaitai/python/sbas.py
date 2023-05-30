from .gnss import *
# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Sbas(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgSbasRaw(KaitaiStruct):
        """This message is sent once per second per SBAS satellite. ME checks the
        parity of the data block and sends only blocks that pass the check.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.tow = self._io.read_u4le()
            self.message_type = self._io.read_u1()
            self.data = []
            for i in range(27):
                self.data.append(self._io.read_u1())




