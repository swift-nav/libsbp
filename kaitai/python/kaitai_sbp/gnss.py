# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Gnss(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class GnssSignalDep(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sat = self._io.read_u2le()
            self.code = self._io.read_u1()
            self.reserved = self._io.read_u1()


    class CarrierPhase(KaitaiStruct):
        """Carrier phase measurement in cycles represented as a 40-bit fixed point
        number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
        fractional cycles. This phase has the same sign as the pseudorange.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.i = self._io.read_s4le()
            self.f = self._io.read_u1()


    class GpsTimeDep(KaitaiStruct):
        """A wire-appropriate GPS time, defined as the number of milliseconds since
        beginning of the week on the Saturday/Sunday transition.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.wn = self._io.read_u2le()


    class GnssSignal(KaitaiStruct):
        """Signal identifier containing constellation, band, and satellite
        identifier.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sat = self._io.read_u1()
            self.code = self._io.read_u1()


    class GpsTime(KaitaiStruct):
        """A wire-appropriate receiver clock time, defined as the time since the
        beginning of the week on the Saturday/Sunday transition. In most cases,
        observations are epoch aligned so ns field will be 0.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.ns_residual = self._io.read_s4le()
            self.wn = self._io.read_u2le()


    class GpsTimeSec(KaitaiStruct):
        """A GPS time, defined as the number of seconds since beginning of the week
        on the Saturday/Sunday transition.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.wn = self._io.read_u2le()


    class SvId(KaitaiStruct):
        """A (Constellation ID, satellite ID) tuple that uniquely identifies a
        space vehicle.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sat_id = self._io.read_u1()
            self.constellation = self._io.read_u1()



