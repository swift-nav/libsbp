# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
from .gnss import *

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Acquisition(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgAcqResultDepC(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.cn0 = self._io.read_f4le()
            self.cp = self._io.read_f4le()
            self.cf = self._io.read_f4le()
            self.sid = Gnss.GnssSignalDep(self._io, self, self._root)


    class MsgAcqResultDepB(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.snr = self._io.read_f4le()
            self.cp = self._io.read_f4le()
            self.cf = self._io.read_f4le()
            self.sid = Gnss.GnssSignalDep(self._io, self, self._root)


    class AcqSvProfile(KaitaiStruct):
        """Profile for a specific SV for debugging purposes. The message describes
        SV profile during acquisition time. The message is used to debug and
        measure the performance.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.job_type = self._io.read_u1()
            self.status = self._io.read_u1()
            self.cn0 = self._io.read_u2le()
            self.int_time = self._io.read_u1()
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.bin_width = self._io.read_u2le()
            self.timestamp = self._io.read_u4le()
            self.time_spent = self._io.read_u4le()
            self.cf_min = self._io.read_s4le()
            self.cf_max = self._io.read_s4le()
            self.cf = self._io.read_s4le()
            self.cp = self._io.read_u4le()


    class MsgAcqSvProfile(KaitaiStruct):
        """The message describes all SV profiles during acquisition time. The
        message is used to debug and measure the performance.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.acq_sv_profile = []
            i = 0
            while not self._io.is_eof():
                self.acq_sv_profile.append(Acquisition.AcqSvProfile(self._io, self, self._root))
                i += 1



    class AcqSvProfileDep(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.job_type = self._io.read_u1()
            self.status = self._io.read_u1()
            self.cn0 = self._io.read_u2le()
            self.int_time = self._io.read_u1()
            self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
            self.bin_width = self._io.read_u2le()
            self.timestamp = self._io.read_u4le()
            self.time_spent = self._io.read_u4le()
            self.cf_min = self._io.read_s4le()
            self.cf_max = self._io.read_s4le()
            self.cf = self._io.read_s4le()
            self.cp = self._io.read_u4le()


    class MsgAcqResult(KaitaiStruct):
        """This message describes the results from an attempted GPS signal
        acquisition search for a satellite PRN over a code phase/carrier
        frequency range. It contains the parameters of the point in the
        acquisition search space with the best carrier-to-noise (CN/0) ratio.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.cn0 = self._io.read_f4le()
            self.cp = self._io.read_f4le()
            self.cf = self._io.read_f4le()
            self.sid = Gnss.GnssSignal(self._io, self, self._root)


    class MsgAcqResultDepA(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.snr = self._io.read_f4le()
            self.cp = self._io.read_f4le()
            self.cf = self._io.read_f4le()
            self.prn = self._io.read_u1()


    class MsgAcqSvProfileDep(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.acq_sv_profile = []
            i = 0
            while not self._io.is_eof():
                self.acq_sv_profile.append(Acquisition.AcqSvProfileDep(self._io, self, self._root))
                i += 1




