# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Profiling(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgMeasurementPoint(KaitaiStruct):
        """Tracks execution time of certain code paths in specially built products.
        This message should only be expected and processed on the direction of
        Swift's engineering teams.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.total_time = self._io.read_u4le()
            self.num_executions = self._io.read_u2le()
            self.min = self._io.read_u4le()
            self.max = self._io.read_u4le()
            self.return_addr = self._io.read_u8le()
            self.id = self._io.read_u8le()
            self.slice_time = self._io.read_u8le()
            self.line = self._io.read_u2le()
            self.func = (self._io.read_bytes_full()).decode(u"ascii")



