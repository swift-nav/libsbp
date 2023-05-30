from .gnss import *
# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Observation(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgSvAzEl(KaitaiStruct):
        """Azimuth and elevation angles of all the visible satellites that the
        device does have ephemeris or almanac for.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.azel = []
            i = 0
            while not self._io.is_eof():
                self.azel.append(Observation.SvAzEl(self._io, self, self._root))
                i += 1



    class GnssCapb(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.gps_active = self._io.read_u8le()
            self.gps_l2c = self._io.read_u8le()
            self.gps_l5 = self._io.read_u8le()
            self.glo_active = self._io.read_u4le()
            self.glo_l2of = self._io.read_u4le()
            self.glo_l3 = self._io.read_u4le()
            self.sbas_active = self._io.read_u8le()
            self.sbas_l5 = self._io.read_u8le()
            self.bds_active = self._io.read_u8le()
            self.bds_d2nav = self._io.read_u8le()
            self.bds_b2 = self._io.read_u8le()
            self.bds_b2a = self._io.read_u8le()
            self.qzss_active = self._io.read_u4le()
            self.gal_active = self._io.read_u8le()
            self.gal_e5 = self._io.read_u8le()


    class MsgGroupDelayDepB(KaitaiStruct):
        """Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.t_op = Gnss.GpsTimeSec(self._io, self, self._root)
            self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
            self.valid = self._io.read_u1()
            self.tgd = self._io.read_s2le()
            self.isc_l1ca = self._io.read_s2le()
            self.isc_l2c = self._io.read_s2le()


    class ObservationHeaderDep(KaitaiStruct):
        """Header of a GPS observation message.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.t = Gnss.GpsTimeDep(self._io, self, self._root)
            self.n_obs = self._io.read_u1()


    class AlmanacCommonContentDep(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
            self.toa = Gnss.GpsTimeSec(self._io, self, self._root)
            self.ura = self._io.read_f8le()
            self.fit_interval = self._io.read_u4le()
            self.valid = self._io.read_u1()
            self.health_bits = self._io.read_u1()


    class EphemerisCommonContentDepA(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
            self.toe = Gnss.GpsTimeDep(self._io, self, self._root)
            self.ura = self._io.read_f8le()
            self.fit_interval = self._io.read_u4le()
            self.valid = self._io.read_u1()
            self.health_bits = self._io.read_u1()


    class EphemerisCommonContent(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.toe = Gnss.GpsTimeSec(self._io, self, self._root)
            self.ura = self._io.read_f4le()
            self.fit_interval = self._io.read_u4le()
            self.valid = self._io.read_u1()
            self.health_bits = self._io.read_u1()


    class PackedObsContentDepC(KaitaiStruct):
        """Pseudorange and carrier phase observation for a satellite being tracked.
        The observations are be interoperable with 3rd party receivers and
        conform with typical RTCMv3 GNSS observations.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.p = self._io.read_u4le()
            self.l = Gnss.CarrierPhase(self._io, self, self._root)
            self.cn0 = self._io.read_u1()
            self.lock = self._io.read_u2le()
            self.sid = Gnss.GnssSignalDep(self._io, self, self._root)


    class MsgEphemerisGloDepD(KaitaiStruct):
        """This observation message has been deprecated in favor of ephemeris
        message using floats for size reduction.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.EphemerisCommonContentDepB(self._io, self, self._root)
            self.gamma = self._io.read_f8le()
            self.tau = self._io.read_f8le()
            self.d_tau = self._io.read_f8le()
            self.pos = []
            for i in range(3):
                self.pos.append(self._io.read_f8le())

            self.vel = []
            for i in range(3):
                self.vel.append(self._io.read_f8le())

            self.acc = []
            for i in range(3):
                self.acc.append(self._io.read_f8le())

            self.fcn = self._io.read_u1()
            self.iod = self._io.read_u1()


    class MsgObsDepA(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Observation.ObservationHeaderDep(self._io, self, self._root)
            self.obs = []
            i = 0
            while not self._io.is_eof():
                self.obs.append(Observation.PackedObsContentDepA(self._io, self, self._root))
                i += 1



    class MsgEphemerisDepB(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tgd = self._io.read_f8le()
            self.c_rs = self._io.read_f8le()
            self.c_rc = self._io.read_f8le()
            self.c_uc = self._io.read_f8le()
            self.c_us = self._io.read_f8le()
            self.c_ic = self._io.read_f8le()
            self.c_is = self._io.read_f8le()
            self.dn = self._io.read_f8le()
            self.m0 = self._io.read_f8le()
            self.ecc = self._io.read_f8le()
            self.sqrta = self._io.read_f8le()
            self.omega0 = self._io.read_f8le()
            self.omegadot = self._io.read_f8le()
            self.w = self._io.read_f8le()
            self.inc = self._io.read_f8le()
            self.inc_dot = self._io.read_f8le()
            self.af0 = self._io.read_f8le()
            self.af1 = self._io.read_f8le()
            self.af2 = self._io.read_f8le()
            self.toe_tow = self._io.read_f8le()
            self.toe_wn = self._io.read_u2le()
            self.toc_tow = self._io.read_f8le()
            self.toc_wn = self._io.read_u2le()
            self.valid = self._io.read_u1()
            self.healthy = self._io.read_u1()
            self.prn = self._io.read_u1()
            self.iode = self._io.read_u1()


    class MsgObs(KaitaiStruct):
        """The GPS observations message reports all the raw pseudorange and carrier
        phase observations for the satellites being tracked by the device.
        Carrier phase observation here is represented as a 40-bit fixed point
        number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
        fractional cycles). The observations are be interoperable with 3rd party
        receivers and conform with typical RTCMv3 GNSS observations.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Observation.ObservationHeader(self._io, self, self._root)
            self.obs = []
            i = 0
            while not self._io.is_eof():
                self.obs.append(Observation.PackedObsContent(self._io, self, self._root))
                i += 1



    class Doppler(KaitaiStruct):
        """Doppler measurement in Hz represented as a 24-bit fixed point number
        with Q16.8 layout, i.e. 16-bits of whole doppler and 8-bits of
        fractional doppler. This doppler is defined as positive for approaching
        satellites.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.i = self._io.read_s2le()
            self.f = self._io.read_u1()


    class MsgAlmanacGloDep(KaitaiStruct):
        """The almanac message returns a set of satellite orbit parameters. Almanac
        data is not very precise and is considered valid for up to several
        months. Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate
        information and almanac" for details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.AlmanacCommonContentDep(self._io, self, self._root)
            self.lambda_na = self._io.read_f8le()
            self.t_lambda_na = self._io.read_f8le()
            self.i = self._io.read_f8le()
            self.t = self._io.read_f8le()
            self.t_dot = self._io.read_f8le()
            self.epsilon = self._io.read_f8le()
            self.omega = self._io.read_f8le()


    class MsgAlmanacGpsDep(KaitaiStruct):
        """The almanac message returns a set of satellite orbit parameters. Almanac
        data is not very precise and is considered valid for up to several
        months. Please see the Navstar GPS Space Segment/Navigation user
        interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more
        details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.AlmanacCommonContentDep(self._io, self, self._root)
            self.m0 = self._io.read_f8le()
            self.ecc = self._io.read_f8le()
            self.sqrta = self._io.read_f8le()
            self.omega0 = self._io.read_f8le()
            self.omegadot = self._io.read_f8le()
            self.w = self._io.read_f8le()
            self.inc = self._io.read_f8le()
            self.af0 = self._io.read_f8le()
            self.af1 = self._io.read_f8le()


    class SvAzEl(KaitaiStruct):
        """Satellite azimuth and elevation.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.az = self._io.read_u1()
            self.el = self._io.read_s1()


    class MsgGloBiases(KaitaiStruct):
        """The GLONASS L1/L2 Code-Phase biases allows to perform GPS+GLONASS
        integer ambiguity resolution for baselines with mixed receiver types
        (e.g. receiver of different manufacturers).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.mask = self._io.read_u1()
            self.l1ca_bias = self._io.read_s2le()
            self.l1p_bias = self._io.read_s2le()
            self.l2ca_bias = self._io.read_s2le()
            self.l2p_bias = self._io.read_s2le()


    class MsgEphemerisSbasDepB(KaitaiStruct):
        """This observation message has been deprecated in favor of ephemeris
        message using floats for size reduction.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.EphemerisCommonContentDepB(self._io, self, self._root)
            self.pos = []
            for i in range(3):
                self.pos.append(self._io.read_f8le())

            self.vel = []
            for i in range(3):
                self.vel.append(self._io.read_f8le())

            self.acc = []
            for i in range(3):
                self.acc.append(self._io.read_f8le())

            self.a_gf0 = self._io.read_f8le()
            self.a_gf1 = self._io.read_f8le()


    class MsgEphemerisGpsDepE(KaitaiStruct):
        """The ephemeris message returns a set of satellite orbit parameters that
        is used to calculate GPS satellite position, velocity, and clock offset.
        Please see the Navstar GPS Space Segment/Navigation user interfaces
        (ICD-GPS-200, Table 20-III) for more details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.EphemerisCommonContentDepA(self._io, self, self._root)
            self.tgd = self._io.read_f8le()
            self.c_rs = self._io.read_f8le()
            self.c_rc = self._io.read_f8le()
            self.c_uc = self._io.read_f8le()
            self.c_us = self._io.read_f8le()
            self.c_ic = self._io.read_f8le()
            self.c_is = self._io.read_f8le()
            self.dn = self._io.read_f8le()
            self.m0 = self._io.read_f8le()
            self.ecc = self._io.read_f8le()
            self.sqrta = self._io.read_f8le()
            self.omega0 = self._io.read_f8le()
            self.omegadot = self._io.read_f8le()
            self.w = self._io.read_f8le()
            self.inc = self._io.read_f8le()
            self.inc_dot = self._io.read_f8le()
            self.af0 = self._io.read_f8le()
            self.af1 = self._io.read_f8le()
            self.af2 = self._io.read_f8le()
            self.toc = Gnss.GpsTimeDep(self._io, self, self._root)
            self.iode = self._io.read_u1()
            self.iodc = self._io.read_u2le()


    class MsgGnssCapb(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.t_nmct = Gnss.GpsTimeSec(self._io, self, self._root)
            self.gc = Observation.GnssCapb(self._io, self, self._root)


    class MsgAlmanacGps(KaitaiStruct):
        """The almanac message returns a set of satellite orbit parameters. Almanac
        data is not very precise and is considered valid for up to several
        months. Please see the Navstar GPS Space Segment/Navigation user
        interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more
        details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.AlmanacCommonContent(self._io, self, self._root)
            self.m0 = self._io.read_f8le()
            self.ecc = self._io.read_f8le()
            self.sqrta = self._io.read_f8le()
            self.omega0 = self._io.read_f8le()
            self.omegadot = self._io.read_f8le()
            self.w = self._io.read_f8le()
            self.inc = self._io.read_f8le()
            self.af0 = self._io.read_f8le()
            self.af1 = self._io.read_f8le()


    class MsgEphemerisQzss(KaitaiStruct):
        """The ephemeris message returns a set of satellite orbit parameters that
        is used to calculate QZSS satellite position, velocity, and clock
        offset.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.EphemerisCommonContent(self._io, self, self._root)
            self.tgd = self._io.read_f4le()
            self.c_rs = self._io.read_f4le()
            self.c_rc = self._io.read_f4le()
            self.c_uc = self._io.read_f4le()
            self.c_us = self._io.read_f4le()
            self.c_ic = self._io.read_f4le()
            self.c_is = self._io.read_f4le()
            self.dn = self._io.read_f8le()
            self.m0 = self._io.read_f8le()
            self.ecc = self._io.read_f8le()
            self.sqrta = self._io.read_f8le()
            self.omega0 = self._io.read_f8le()
            self.omegadot = self._io.read_f8le()
            self.w = self._io.read_f8le()
            self.inc = self._io.read_f8le()
            self.inc_dot = self._io.read_f8le()
            self.af0 = self._io.read_f4le()
            self.af1 = self._io.read_f4le()
            self.af2 = self._io.read_f4le()
            self.toc = Gnss.GpsTimeSec(self._io, self, self._root)
            self.iode = self._io.read_u1()
            self.iodc = self._io.read_u2le()


    class MsgGroupDelayDepA(KaitaiStruct):
        """Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.t_op = Gnss.GpsTimeDep(self._io, self, self._root)
            self.prn = self._io.read_u1()
            self.valid = self._io.read_u1()
            self.tgd = self._io.read_s2le()
            self.isc_l1ca = self._io.read_s2le()
            self.isc_l2c = self._io.read_s2le()


    class MsgEphemerisDepC(KaitaiStruct):
        """The ephemeris message returns a set of satellite orbit parameters that
        is used to calculate GPS satellite position, velocity, and clock offset.
        Please see the Navstar GPS Space Segment/Navigation user interfaces
        (ICD-GPS-200, Table 20-III) for more details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tgd = self._io.read_f8le()
            self.c_rs = self._io.read_f8le()
            self.c_rc = self._io.read_f8le()
            self.c_uc = self._io.read_f8le()
            self.c_us = self._io.read_f8le()
            self.c_ic = self._io.read_f8le()
            self.c_is = self._io.read_f8le()
            self.dn = self._io.read_f8le()
            self.m0 = self._io.read_f8le()
            self.ecc = self._io.read_f8le()
            self.sqrta = self._io.read_f8le()
            self.omega0 = self._io.read_f8le()
            self.omegadot = self._io.read_f8le()
            self.w = self._io.read_f8le()
            self.inc = self._io.read_f8le()
            self.inc_dot = self._io.read_f8le()
            self.af0 = self._io.read_f8le()
            self.af1 = self._io.read_f8le()
            self.af2 = self._io.read_f8le()
            self.toe_tow = self._io.read_f8le()
            self.toe_wn = self._io.read_u2le()
            self.toc_tow = self._io.read_f8le()
            self.toc_wn = self._io.read_u2le()
            self.valid = self._io.read_u1()
            self.healthy = self._io.read_u1()
            self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
            self.iode = self._io.read_u1()
            self.iodc = self._io.read_u2le()
            self.reserved = self._io.read_u4le()


    class CarrierPhaseDepA(KaitaiStruct):
        """Carrier phase measurement in cycles represented as a 40-bit fixed point
        number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
        fractional cycles. This has the opposite sign convention than a typical
        GPS receiver and the phase has the opposite sign as the pseudorange.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.i = self._io.read_s4le()
            self.f = self._io.read_u1()


    class MsgEphemerisGal(KaitaiStruct):
        """The ephemeris message returns a set of satellite orbit parameters that
        is used to calculate Galileo satellite position, velocity, and clock
        offset. Please see the Signal In Space ICD OS SIS ICD, Issue 1.3,
        December 2016 for more details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.EphemerisCommonContent(self._io, self, self._root)
            self.bgd_e1e5a = self._io.read_f4le()
            self.bgd_e1e5b = self._io.read_f4le()
            self.c_rs = self._io.read_f4le()
            self.c_rc = self._io.read_f4le()
            self.c_uc = self._io.read_f4le()
            self.c_us = self._io.read_f4le()
            self.c_ic = self._io.read_f4le()
            self.c_is = self._io.read_f4le()
            self.dn = self._io.read_f8le()
            self.m0 = self._io.read_f8le()
            self.ecc = self._io.read_f8le()
            self.sqrta = self._io.read_f8le()
            self.omega0 = self._io.read_f8le()
            self.omegadot = self._io.read_f8le()
            self.w = self._io.read_f8le()
            self.inc = self._io.read_f8le()
            self.inc_dot = self._io.read_f8le()
            self.af0 = self._io.read_f8le()
            self.af1 = self._io.read_f8le()
            self.af2 = self._io.read_f4le()
            self.toc = Gnss.GpsTimeSec(self._io, self, self._root)
            self.iode = self._io.read_u2le()
            self.iodc = self._io.read_u2le()
            self.source = self._io.read_u1()


    class PackedOsrContent(KaitaiStruct):
        """Pseudorange and carrier phase network corrections for a satellite
        signal.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.p = self._io.read_u4le()
            self.l = Gnss.CarrierPhase(self._io, self, self._root)
            self.lock = self._io.read_u1()
            self.flags = self._io.read_u1()
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.iono_std = self._io.read_u2le()
            self.tropo_std = self._io.read_u2le()
            self.range_std = self._io.read_u2le()


    class MsgEphemerisBds(KaitaiStruct):
        """The ephemeris message returns a set of satellite orbit parameters that
        is used to calculate BDS satellite position, velocity, and clock offset.
        Please see the BeiDou Navigation Satellite System SIS-ICD Version 2.1,
        Table 5-9 for more details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.EphemerisCommonContent(self._io, self, self._root)
            self.tgd1 = self._io.read_f4le()
            self.tgd2 = self._io.read_f4le()
            self.c_rs = self._io.read_f4le()
            self.c_rc = self._io.read_f4le()
            self.c_uc = self._io.read_f4le()
            self.c_us = self._io.read_f4le()
            self.c_ic = self._io.read_f4le()
            self.c_is = self._io.read_f4le()
            self.dn = self._io.read_f8le()
            self.m0 = self._io.read_f8le()
            self.ecc = self._io.read_f8le()
            self.sqrta = self._io.read_f8le()
            self.omega0 = self._io.read_f8le()
            self.omegadot = self._io.read_f8le()
            self.w = self._io.read_f8le()
            self.inc = self._io.read_f8le()
            self.inc_dot = self._io.read_f8le()
            self.af0 = self._io.read_f8le()
            self.af1 = self._io.read_f4le()
            self.af2 = self._io.read_f4le()
            self.toc = Gnss.GpsTimeSec(self._io, self, self._root)
            self.iode = self._io.read_u1()
            self.iodc = self._io.read_u2le()


    class MsgEphemerisGpsDepF(KaitaiStruct):
        """This observation message has been deprecated in favor of ephemeris
        message using floats for size reduction.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.EphemerisCommonContentDepB(self._io, self, self._root)
            self.tgd = self._io.read_f8le()
            self.c_rs = self._io.read_f8le()
            self.c_rc = self._io.read_f8le()
            self.c_uc = self._io.read_f8le()
            self.c_us = self._io.read_f8le()
            self.c_ic = self._io.read_f8le()
            self.c_is = self._io.read_f8le()
            self.dn = self._io.read_f8le()
            self.m0 = self._io.read_f8le()
            self.ecc = self._io.read_f8le()
            self.sqrta = self._io.read_f8le()
            self.omega0 = self._io.read_f8le()
            self.omegadot = self._io.read_f8le()
            self.w = self._io.read_f8le()
            self.inc = self._io.read_f8le()
            self.inc_dot = self._io.read_f8le()
            self.af0 = self._io.read_f8le()
            self.af1 = self._io.read_f8le()
            self.af2 = self._io.read_f8le()
            self.toc = Gnss.GpsTimeSec(self._io, self, self._root)
            self.iode = self._io.read_u1()
            self.iodc = self._io.read_u2le()


    class ObservationHeader(KaitaiStruct):
        """Header of a GNSS observation message.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.t = Gnss.GpsTime(self._io, self, self._root)
            self.n_obs = self._io.read_u1()


    class MsgEphemerisSbasDepA(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.EphemerisCommonContentDepA(self._io, self, self._root)
            self.pos = []
            for i in range(3):
                self.pos.append(self._io.read_f8le())

            self.vel = []
            for i in range(3):
                self.vel.append(self._io.read_f8le())

            self.acc = []
            for i in range(3):
                self.acc.append(self._io.read_f8le())

            self.a_gf0 = self._io.read_f8le()
            self.a_gf1 = self._io.read_f8le()


    class PackedObsContent(KaitaiStruct):
        """Pseudorange and carrier phase observation for a satellite being tracked.
        The observations are interoperable with 3rd party receivers and conform
        with typical RTCM 3.1 message GPS/GLO observations.
        
        Carrier phase observations are not guaranteed to be aligned to the RINEX
        3 or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are
        currently performed.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.p = self._io.read_u4le()
            self.l = Gnss.CarrierPhase(self._io, self, self._root)
            self.d = Observation.Doppler(self._io, self, self._root)
            self.cn0 = self._io.read_u1()
            self.lock = self._io.read_u1()
            self.flags = self._io.read_u1()
            self.sid = Gnss.GnssSignal(self._io, self, self._root)


    class MsgBasePosEcef(KaitaiStruct):
        """The base station position message is the position reported by the base
        station itself in absolute Earth Centered Earth Fixed coordinates. It is
        used for pseudo-absolute RTK positioning, and is required to be a high-
        accuracy surveyed location of the base station. Any error here will
        result in an error in the pseudo-absolute position output.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.x = self._io.read_f8le()
            self.y = self._io.read_f8le()
            self.z = self._io.read_f8le()


    class MsgEphemerisGloDepA(KaitaiStruct):
        """The ephemeris message returns a set of satellite orbit parameters that
        is used to calculate GLO satellite position, velocity, and clock offset.
        Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
        immediate information (ephemeris parameters)" for more details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.EphemerisCommonContentDepA(self._io, self, self._root)
            self.gamma = self._io.read_f8le()
            self.tau = self._io.read_f8le()
            self.pos = []
            for i in range(3):
                self.pos.append(self._io.read_f8le())

            self.vel = []
            for i in range(3):
                self.vel.append(self._io.read_f8le())

            self.acc = []
            for i in range(3):
                self.acc.append(self._io.read_f8le())



    class MsgGroupDelay(KaitaiStruct):
        """Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.t_op = Gnss.GpsTimeSec(self._io, self, self._root)
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.valid = self._io.read_u1()
            self.tgd = self._io.read_s2le()
            self.isc_l1ca = self._io.read_s2le()
            self.isc_l2c = self._io.read_s2le()


    class MsgAlmanacGlo(KaitaiStruct):
        """The almanac message returns a set of satellite orbit parameters. Almanac
        data is not very precise and is considered valid for up to several
        months. Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate
        information and almanac" for details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.AlmanacCommonContent(self._io, self, self._root)
            self.lambda_na = self._io.read_f8le()
            self.t_lambda_na = self._io.read_f8le()
            self.i = self._io.read_f8le()
            self.t = self._io.read_f8le()
            self.t_dot = self._io.read_f8le()
            self.epsilon = self._io.read_f8le()
            self.omega = self._io.read_f8le()


    class MsgEphemerisGalDepA(KaitaiStruct):
        """This observation message has been deprecated in favor of an ephemeris
        message with explicit source of NAV data.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.EphemerisCommonContent(self._io, self, self._root)
            self.bgd_e1e5a = self._io.read_f4le()
            self.bgd_e1e5b = self._io.read_f4le()
            self.c_rs = self._io.read_f4le()
            self.c_rc = self._io.read_f4le()
            self.c_uc = self._io.read_f4le()
            self.c_us = self._io.read_f4le()
            self.c_ic = self._io.read_f4le()
            self.c_is = self._io.read_f4le()
            self.dn = self._io.read_f8le()
            self.m0 = self._io.read_f8le()
            self.ecc = self._io.read_f8le()
            self.sqrta = self._io.read_f8le()
            self.omega0 = self._io.read_f8le()
            self.omegadot = self._io.read_f8le()
            self.w = self._io.read_f8le()
            self.inc = self._io.read_f8le()
            self.inc_dot = self._io.read_f8le()
            self.af0 = self._io.read_f8le()
            self.af1 = self._io.read_f8le()
            self.af2 = self._io.read_f4le()
            self.toc = Gnss.GpsTimeSec(self._io, self, self._root)
            self.iode = self._io.read_u2le()
            self.iodc = self._io.read_u2le()


    class MsgObsDepB(KaitaiStruct):
        """This observation message has been deprecated in favor of observations
        that are more interoperable. This message should be used for
        observations referenced to a nominal pseudorange which are not
        interoperable with most 3rd party GNSS receivers or typical RTCMv3
        observations.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Observation.ObservationHeaderDep(self._io, self, self._root)
            self.obs = []
            i = 0
            while not self._io.is_eof():
                self.obs.append(Observation.PackedObsContentDepB(self._io, self, self._root))
                i += 1



    class PackedObsContentDepA(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.p = self._io.read_u4le()
            self.l = Observation.CarrierPhaseDepA(self._io, self, self._root)
            self.cn0 = self._io.read_u1()
            self.lock = self._io.read_u2le()
            self.prn = self._io.read_u1()


    class MsgEphemerisGlo(KaitaiStruct):
        """The ephemeris message returns a set of satellite orbit parameters that
        is used to calculate GLO satellite position, velocity, and clock offset.
        Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
        immediate information (ephemeris parameters)" for more details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.EphemerisCommonContent(self._io, self, self._root)
            self.gamma = self._io.read_f4le()
            self.tau = self._io.read_f4le()
            self.d_tau = self._io.read_f4le()
            self.pos = []
            for i in range(3):
                self.pos.append(self._io.read_f8le())

            self.vel = []
            for i in range(3):
                self.vel.append(self._io.read_f8le())

            self.acc = []
            for i in range(3):
                self.acc.append(self._io.read_f4le())

            self.fcn = self._io.read_u1()
            self.iod = self._io.read_u1()


    class MsgIono(KaitaiStruct):
        """The ionospheric parameters which allow the "L1 only" or "L2 only" user
        to utilize the ionospheric model for computation of the ionospheric
        delay. Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.t_nmct = Gnss.GpsTimeSec(self._io, self, self._root)
            self.a0 = self._io.read_f8le()
            self.a1 = self._io.read_f8le()
            self.a2 = self._io.read_f8le()
            self.a3 = self._io.read_f8le()
            self.b0 = self._io.read_f8le()
            self.b1 = self._io.read_f8le()
            self.b2 = self._io.read_f8le()
            self.b3 = self._io.read_f8le()


    class MsgEphemerisDepD(KaitaiStruct):
        """The ephemeris message returns a set of satellite orbit parameters that
        is used to calculate GPS satellite position, velocity, and clock offset.
        Please see the Navstar GPS Space Segment/Navigation user interfaces
        (ICD-GPS-200, Table 20-III) for more details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tgd = self._io.read_f8le()
            self.c_rs = self._io.read_f8le()
            self.c_rc = self._io.read_f8le()
            self.c_uc = self._io.read_f8le()
            self.c_us = self._io.read_f8le()
            self.c_ic = self._io.read_f8le()
            self.c_is = self._io.read_f8le()
            self.dn = self._io.read_f8le()
            self.m0 = self._io.read_f8le()
            self.ecc = self._io.read_f8le()
            self.sqrta = self._io.read_f8le()
            self.omega0 = self._io.read_f8le()
            self.omegadot = self._io.read_f8le()
            self.w = self._io.read_f8le()
            self.inc = self._io.read_f8le()
            self.inc_dot = self._io.read_f8le()
            self.af0 = self._io.read_f8le()
            self.af1 = self._io.read_f8le()
            self.af2 = self._io.read_f8le()
            self.toe_tow = self._io.read_f8le()
            self.toe_wn = self._io.read_u2le()
            self.toc_tow = self._io.read_f8le()
            self.toc_wn = self._io.read_u2le()
            self.valid = self._io.read_u1()
            self.healthy = self._io.read_u1()
            self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
            self.iode = self._io.read_u1()
            self.iodc = self._io.read_u2le()
            self.reserved = self._io.read_u4le()


    class MsgEphemerisGps(KaitaiStruct):
        """The ephemeris message returns a set of satellite orbit parameters that
        is used to calculate GPS satellite position, velocity, and clock offset.
        Please see the Navstar GPS Space Segment/Navigation user interfaces
        (ICD-GPS-200, Table 20-III) for more details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.EphemerisCommonContent(self._io, self, self._root)
            self.tgd = self._io.read_f4le()
            self.c_rs = self._io.read_f4le()
            self.c_rc = self._io.read_f4le()
            self.c_uc = self._io.read_f4le()
            self.c_us = self._io.read_f4le()
            self.c_ic = self._io.read_f4le()
            self.c_is = self._io.read_f4le()
            self.dn = self._io.read_f8le()
            self.m0 = self._io.read_f8le()
            self.ecc = self._io.read_f8le()
            self.sqrta = self._io.read_f8le()
            self.omega0 = self._io.read_f8le()
            self.omegadot = self._io.read_f8le()
            self.w = self._io.read_f8le()
            self.inc = self._io.read_f8le()
            self.inc_dot = self._io.read_f8le()
            self.af0 = self._io.read_f4le()
            self.af1 = self._io.read_f4le()
            self.af2 = self._io.read_f4le()
            self.toc = Gnss.GpsTimeSec(self._io, self, self._root)
            self.iode = self._io.read_u1()
            self.iodc = self._io.read_u2le()


    class MsgBasePosLlh(KaitaiStruct):
        """The base station position message is the position reported by the base
        station itself. It is used for pseudo-absolute RTK positioning, and is
        required to be a high-accuracy surveyed location of the base station.
        Any error here will result in an error in the pseudo-absolute position
        output.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.lat = self._io.read_f8le()
            self.lon = self._io.read_f8le()
            self.height = self._io.read_f8le()


    class AlmanacCommonContent(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.toa = Gnss.GpsTimeSec(self._io, self, self._root)
            self.ura = self._io.read_f8le()
            self.fit_interval = self._io.read_u4le()
            self.valid = self._io.read_u1()
            self.health_bits = self._io.read_u1()


    class MsgOsr(KaitaiStruct):
        """The OSR message contains network corrections in an observation-like
        format.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Observation.ObservationHeader(self._io, self, self._root)
            self.obs = []
            i = 0
            while not self._io.is_eof():
                self.obs.append(Observation.PackedOsrContent(self._io, self, self._root))
                i += 1



    class MsgEphemerisGloDepC(KaitaiStruct):
        """The ephemeris message returns a set of satellite orbit parameters that
        is used to calculate GLO satellite position, velocity, and clock offset.
        Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
        immediate information (ephemeris parameters)" for more details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.EphemerisCommonContentDepB(self._io, self, self._root)
            self.gamma = self._io.read_f8le()
            self.tau = self._io.read_f8le()
            self.d_tau = self._io.read_f8le()
            self.pos = []
            for i in range(3):
                self.pos.append(self._io.read_f8le())

            self.vel = []
            for i in range(3):
                self.vel.append(self._io.read_f8le())

            self.acc = []
            for i in range(3):
                self.acc.append(self._io.read_f8le())

            self.fcn = self._io.read_u1()


    class MsgEphemerisGloDepB(KaitaiStruct):
        """The ephemeris message returns a set of satellite orbit parameters that
        is used to calculate GLO satellite position, velocity, and clock offset.
        Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
        immediate information (ephemeris parameters)" for more details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.EphemerisCommonContentDepB(self._io, self, self._root)
            self.gamma = self._io.read_f8le()
            self.tau = self._io.read_f8le()
            self.pos = []
            for i in range(3):
                self.pos.append(self._io.read_f8le())

            self.vel = []
            for i in range(3):
                self.vel.append(self._io.read_f8le())

            self.acc = []
            for i in range(3):
                self.acc.append(self._io.read_f8le())



    class MsgSvConfigurationGpsDep(KaitaiStruct):
        """Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.t_nmct = Gnss.GpsTimeSec(self._io, self, self._root)
            self.l2c_mask = self._io.read_u4le()


    class MsgEphemerisSbas(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.common = Observation.EphemerisCommonContent(self._io, self, self._root)
            self.pos = []
            for i in range(3):
                self.pos.append(self._io.read_f8le())

            self.vel = []
            for i in range(3):
                self.vel.append(self._io.read_f4le())

            self.acc = []
            for i in range(3):
                self.acc.append(self._io.read_f4le())

            self.a_gf0 = self._io.read_f4le()
            self.a_gf1 = self._io.read_f4le()


    class PackedObsContentDepB(KaitaiStruct):
        """Pseudorange and carrier phase observation for a satellite being tracked.
        Pseudoranges are referenced to a nominal pseudorange.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.p = self._io.read_u4le()
            self.l = Observation.CarrierPhaseDepA(self._io, self, self._root)
            self.cn0 = self._io.read_u1()
            self.lock = self._io.read_u2le()
            self.sid = Gnss.GnssSignalDep(self._io, self, self._root)


    class MsgObsDepC(KaitaiStruct):
        """The GPS observations message reports all the raw pseudorange and carrier
        phase observations for the satellites being tracked by the device.
        Carrier phase observation here is represented as a 40-bit fixed point
        number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
        fractional cycles). The observations are interoperable with 3rd party
        receivers and conform with typical RTCMv3 GNSS observations.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Observation.ObservationHeaderDep(self._io, self, self._root)
            self.obs = []
            i = 0
            while not self._io.is_eof():
                self.obs.append(Observation.PackedObsContentDepC(self._io, self, self._root))
                i += 1



    class MsgEphemerisDepA(KaitaiStruct):
        """Deprecated.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tgd = self._io.read_f8le()
            self.c_rs = self._io.read_f8le()
            self.c_rc = self._io.read_f8le()
            self.c_uc = self._io.read_f8le()
            self.c_us = self._io.read_f8le()
            self.c_ic = self._io.read_f8le()
            self.c_is = self._io.read_f8le()
            self.dn = self._io.read_f8le()
            self.m0 = self._io.read_f8le()
            self.ecc = self._io.read_f8le()
            self.sqrta = self._io.read_f8le()
            self.omega0 = self._io.read_f8le()
            self.omegadot = self._io.read_f8le()
            self.w = self._io.read_f8le()
            self.inc = self._io.read_f8le()
            self.inc_dot = self._io.read_f8le()
            self.af0 = self._io.read_f8le()
            self.af1 = self._io.read_f8le()
            self.af2 = self._io.read_f8le()
            self.toe_tow = self._io.read_f8le()
            self.toe_wn = self._io.read_u2le()
            self.toc_tow = self._io.read_f8le()
            self.toc_wn = self._io.read_u2le()
            self.valid = self._io.read_u1()
            self.healthy = self._io.read_u1()
            self.prn = self._io.read_u1()


    class EphemerisCommonContentDepB(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.toe = Gnss.GpsTimeSec(self._io, self, self._root)
            self.ura = self._io.read_f8le()
            self.fit_interval = self._io.read_u4le()
            self.valid = self._io.read_u1()
            self.health_bits = self._io.read_u1()



