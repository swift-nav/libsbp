from .gnss import *
# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Tracking(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgTrackingStateDetailedDep(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.recv_time = self._io.read_u8le()
            self.tot = Gnss.GpsTimeDep(self._io, self, self._root)
            self.p = self._io.read_u4le()
            self.p_std = self._io.read_u2le()
            self.l = Gnss.CarrierPhase(self._io, self, self._root)
            self.cn0 = self._io.read_u1()
            self.lock = self._io.read_u2le()
            self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
            self.doppler = self._io.read_s4le()
            self.doppler_std = self._io.read_u2le()
            self.uptime = self._io.read_u4le()
            self.clock_offset = self._io.read_s2le()
            self.clock_drift = self._io.read_s2le()
            self.corr_spacing = self._io.read_u2le()
            self.acceleration = self._io.read_s1()
            self.sync_flags = self._io.read_u1()
            self.tow_flags = self._io.read_u1()
            self.track_flags = self._io.read_u1()
            self.nav_flags = self._io.read_u1()
            self.pset_flags = self._io.read_u1()
            self.misc_flags = self._io.read_u1()


    class TrackingChannelStateDepB(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.state = self._io.read_u1()
            self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
            self.cn0 = self._io.read_f4le()


    class TrackingChannelState(KaitaiStruct):
        """Tracking channel state for a specific satellite signal and measured
        signal power.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.fcn = self._io.read_u1()
            self.cn0 = self._io.read_u1()


    class MsgTrackingState(KaitaiStruct):
        """The tracking message returns a variable-length array of tracking channel
        states. It reports status and carrier-to-noise density measurements for
        all tracked satellites.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.states = []
            i = 0
            while not self._io.is_eof():
                self.states.append(Tracking.TrackingChannelState(self._io, self, self._root))
                i += 1



    class TrackingChannelStateDepA(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.state = self._io.read_u1()
            self.prn = self._io.read_u1()
            self.cn0 = self._io.read_f4le()


    class MsgTrackingIqDepA(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.channel = self._io.read_u1()
            self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
            self.corrs = []
            for i in range(3):
                self.corrs.append(self._io.read_u8le())



    class TrackingChannelCorrelationDep(KaitaiStruct):
        """Structure containing in-phase and quadrature correlation components.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.i = self._io.read_s4le()
            self.q = self._io.read_s4le()


    class MsgTrackingStateDepA(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.states = []
            i = 0
            while not self._io.is_eof():
                self.states.append(Tracking.TrackingChannelStateDepA(self._io, self, self._root))
                i += 1



    class MsgMeasurementState(KaitaiStruct):
        """The tracking message returns a variable-length array of tracking channel
        states. It reports status and carrier-to-noise density measurements for
        all tracked satellites.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.states = []
            i = 0
            while not self._io.is_eof():
                self.states.append(Tracking.MeasurementState(self._io, self, self._root))
                i += 1



    class TrackingChannelCorrelation(KaitaiStruct):
        """Structure containing in-phase and quadrature correlation components.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.i = self._io.read_s2le()
            self.q = self._io.read_s2le()


    class MsgTrackingIq(KaitaiStruct):
        """When enabled, a tracking channel can output the correlations at each
        update interval.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.channel = self._io.read_u1()
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.corrs = []
            for i in range(3):
                self.corrs.append(self._io.read_u8le())



    class MsgTrackingStateDetailedDepA(KaitaiStruct):
        """The tracking message returns a set tracking channel parameters for a
        single tracking channel useful for debugging issues.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.recv_time = self._io.read_u8le()
            self.tot = Gnss.GpsTime(self._io, self, self._root)
            self.p = self._io.read_u4le()
            self.p_std = self._io.read_u2le()
            self.l = Gnss.CarrierPhase(self._io, self, self._root)
            self.cn0 = self._io.read_u1()
            self.lock = self._io.read_u2le()
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.doppler = self._io.read_s4le()
            self.doppler_std = self._io.read_u2le()
            self.uptime = self._io.read_u4le()
            self.clock_offset = self._io.read_s2le()
            self.clock_drift = self._io.read_s2le()
            self.corr_spacing = self._io.read_u2le()
            self.acceleration = self._io.read_s1()
            self.sync_flags = self._io.read_u1()
            self.tow_flags = self._io.read_u1()
            self.track_flags = self._io.read_u1()
            self.nav_flags = self._io.read_u1()
            self.pset_flags = self._io.read_u1()
            self.misc_flags = self._io.read_u1()


    class MsgTrackingStateDepB(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.states = []
            i = 0
            while not self._io.is_eof():
                self.states.append(Tracking.TrackingChannelStateDepB(self._io, self, self._root))
                i += 1



    class MeasurementState(KaitaiStruct):
        """Measurement Engine tracking channel state for a specific satellite
        signal and measured signal power. The mesid field for Glonass can either
        carry the FCN as 100 + FCN where FCN is in [-7, +6] or the Slot ID (from
        1 to 28).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.mesid = Gnss.GnssSignal(self._io, self, self._root)
            self.cn0 = self._io.read_u1()


    class MsgTrackingIqDepB(KaitaiStruct):
        """When enabled, a tracking channel can output the correlations at each
        update interval.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.channel = self._io.read_u1()
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.corrs = []
            for i in range(3):
                self.corrs.append(self._io.read_u8le())




