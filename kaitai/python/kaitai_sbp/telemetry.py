# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
from .gnss import *

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Telemetry(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class TelemetrySv(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.az = self._io.read_u1()
            self.el = self._io.read_s1()
            self.availability_flags = self._io.read_u1()
            self.pseudorange_residual = self._io.read_s2le()
            self.phase_residual = self._io.read_s2le()
            self.outlier_flags = self._io.read_u1()
            self.ephemeris_flags = self._io.read_u1()
            self.correction_flags = self._io.read_u1()
            self.sid = Gnss.GnssSignal(self._io, self, self._root)


    class MsgTelSv(KaitaiStruct):
        """This message includes telemetry pertinent to satellite signals available
        to Starling.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.wn = self._io.read_u2le()
            self.tow = self._io.read_u4le()
            self.n_obs = self._io.read_u1()
            self.origin_flags = self._io.read_u1()
            self.sv_tel = []
            i = 0
            while not self._io.is_eof():
                self.sv_tel.append(Telemetry.TelemetrySv(self._io, self, self._root))
                i += 1




