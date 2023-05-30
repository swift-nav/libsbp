from .gnss import *
# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Ssr(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class GridDefinitionHeaderDepA(KaitaiStruct):
        """Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes
        an RLE encoded validity list.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.region_size_inverse = self._io.read_u1()
            self.area_width = self._io.read_u2le()
            self.lat_nw_corner_enc = self._io.read_u2le()
            self.lon_nw_corner_enc = self._io.read_u2le()
            self.num_msgs = self._io.read_u1()
            self.seq_num = self._io.read_u1()


    class StecResidualNoStd(KaitaiStruct):
        """STEC residual for the given satellite at the grid point.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sv_id = Gnss.SvId(self._io, self, self._root)
            self.residual = self._io.read_s2le()


    class TroposphericDelayCorrectionNoStd(KaitaiStruct):
        """Troposphere vertical delays at the grid point.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.hydro = self._io.read_s2le()
            self.wet = self._io.read_s1()


    class MsgSsrStecCorrectionDep(KaitaiStruct):
        """The Slant Total Electron Content per space vehicle, given as polynomial
        approximation for a given tile. This should be combined with the
        MSG_SSR_GRIDDED_CORRECTION message to get the state space representation
        of the atmospheric delay.
        
        It is typically equivalent to the QZSS CLAS Sub Type 8 messages.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Ssr.StecHeader(self._io, self, self._root)
            self.stec_sat_list = []
            i = 0
            while not self._io.is_eof():
                self.stec_sat_list.append(Ssr.StecSatElement(self._io, self, self._root))
                i += 1



    class StecSatElementIntegrity(KaitaiStruct):
        """STEC polynomial and bounds for the given satellite.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.stec_residual = Ssr.StecResidual(self._io, self, self._root)
            self.stec_bound_mu = self._io.read_u1()
            self.stec_bound_sig = self._io.read_u1()
            self.stec_bound_mu_dot = self._io.read_u1()
            self.stec_bound_sig_dot = self._io.read_u1()


    class MsgSsrOrbitClockDepA(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.time = Gnss.GpsTimeSec(self._io, self, self._root)
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.update_interval = self._io.read_u1()
            self.iod_ssr = self._io.read_u1()
            self.iod = self._io.read_u1()
            self.radial = self._io.read_s4le()
            self.along = self._io.read_s4le()
            self.cross = self._io.read_s4le()
            self.dot_radial = self._io.read_s4le()
            self.dot_along = self._io.read_s4le()
            self.dot_cross = self._io.read_s4le()
            self.c0 = self._io.read_s4le()
            self.c1 = self._io.read_s4le()
            self.c2 = self._io.read_s4le()


    class MsgSsrStecCorrection(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Ssr.BoundsHeader(self._io, self, self._root)
            self.ssr_iod_atmo = self._io.read_u1()
            self.tile_set_id = self._io.read_u2le()
            self.tile_id = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.stec_sat_list = []
            i = 0
            while not self._io.is_eof():
                self.stec_sat_list.append(Ssr.StecSatElement(self._io, self, self._root))
                i += 1



    class MsgSsrOrbitClock(KaitaiStruct):
        """The precise orbit and clock correction message is to be applied as a
        delta correction to broadcast ephemeris and is an equivalent to the 1060
        /1066 RTCM message types.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.time = Gnss.GpsTimeSec(self._io, self, self._root)
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.update_interval = self._io.read_u1()
            self.iod_ssr = self._io.read_u1()
            self.iod = self._io.read_u4le()
            self.radial = self._io.read_s4le()
            self.along = self._io.read_s4le()
            self.cross = self._io.read_s4le()
            self.dot_radial = self._io.read_s4le()
            self.dot_along = self._io.read_s4le()
            self.dot_cross = self._io.read_s4le()
            self.c0 = self._io.read_s4le()
            self.c1 = self._io.read_s4le()
            self.c2 = self._io.read_s4le()


    class BoundsHeader(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.time = Gnss.GpsTimeSec(self._io, self, self._root)
            self.num_msgs = self._io.read_u1()
            self.seq_num = self._io.read_u1()
            self.update_interval = self._io.read_u1()
            self.sol_id = self._io.read_u1()


    class MsgSsrGriddedCorrection(KaitaiStruct):
        """STEC residuals are per space vehicle, troposphere is not.
        
        It is typically equivalent to the QZSS CLAS Sub Type 9 messages.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Ssr.GriddedCorrectionHeader(self._io, self, self._root)
            self.index = self._io.read_u2le()
            self.tropo_delay_correction = Ssr.TroposphericDelayCorrection(self._io, self, self._root)
            self.stec_residuals = []
            i = 0
            while not self._io.is_eof():
                self.stec_residuals.append(Ssr.StecResidual(self._io, self, self._root))
                i += 1



    class StecResidual(KaitaiStruct):
        """STEC residual (mean and standard deviation) for the given satellite at
        the grid point.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sv_id = Gnss.SvId(self._io, self, self._root)
            self.residual = self._io.read_s2le()
            self.stddev = self._io.read_u1()


    class CodePhaseBiasesSatSig(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sat_id = self._io.read_u1()
            self.signal_id = self._io.read_u1()
            self.code_bias_bound_mu = self._io.read_u1()
            self.code_bias_bound_sig = self._io.read_u1()
            self.phase_bias_bound_mu = self._io.read_u1()
            self.phase_bias_bound_sig = self._io.read_u1()


    class SatelliteApc(KaitaiStruct):
        """Contains phase center offset and elevation variation corrections for one
        signal on a satellite.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.sat_info = self._io.read_u1()
            self.svn = self._io.read_u2le()
            self.pco = []
            for i in range(3):
                self.pco.append(self._io.read_s2le())

            self.pcv = []
            for i in range(21):
                self.pcv.append(self._io.read_s1())



    class GriddedCorrectionHeader(KaitaiStruct):
        """The LPP message contains nested variable length arrays which are not
        supported in SBP, so each grid point will be identified by the index.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tile_set_id = self._io.read_u2le()
            self.tile_id = self._io.read_u2le()
            self.time = Gnss.GpsTimeSec(self._io, self, self._root)
            self.num_msgs = self._io.read_u2le()
            self.seq_num = self._io.read_u2le()
            self.update_interval = self._io.read_u1()
            self.iod_atmo = self._io.read_u1()
            self.tropo_quality_indicator = self._io.read_u1()


    class StecSatElement(KaitaiStruct):
        """STEC polynomial for the given satellite.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sv_id = Gnss.SvId(self._io, self, self._root)
            self.stec_quality_indicator = self._io.read_u1()
            self.stec_coeff = []
            for i in range(4):
                self.stec_coeff.append(self._io.read_s2le())



    class StecHeaderDepA(KaitaiStruct):
        """A full set of STEC information will likely span multiple SBP messages,
        since SBP message a limited to 255 bytes.  The header is used to tie
        multiple SBP messages into a sequence.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.time = Gnss.GpsTimeSec(self._io, self, self._root)
            self.num_msgs = self._io.read_u1()
            self.seq_num = self._io.read_u1()
            self.update_interval = self._io.read_u1()
            self.iod_atmo = self._io.read_u1()


    class StecHeader(KaitaiStruct):
        """A full set of STEC information will likely span multiple SBP messages,
        since SBP message a limited to 255 bytes.  The header is used to tie
        multiple SBP messages into a sequence.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tile_set_id = self._io.read_u2le()
            self.tile_id = self._io.read_u2le()
            self.time = Gnss.GpsTimeSec(self._io, self, self._root)
            self.num_msgs = self._io.read_u1()
            self.seq_num = self._io.read_u1()
            self.update_interval = self._io.read_u1()
            self.iod_atmo = self._io.read_u1()


    class MsgSsrStecCorrectionDepA(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Ssr.StecHeaderDepA(self._io, self, self._root)
            self.stec_sat_list = []
            i = 0
            while not self._io.is_eof():
                self.stec_sat_list.append(Ssr.StecSatElement(self._io, self, self._root))
                i += 1



    class GriddedCorrectionHeaderDepA(KaitaiStruct):
        """The 3GPP message contains nested variable length arrays which are not
        supported in SBP, so each grid point will be identified by the index.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.time = Gnss.GpsTimeSec(self._io, self, self._root)
            self.num_msgs = self._io.read_u2le()
            self.seq_num = self._io.read_u2le()
            self.update_interval = self._io.read_u1()
            self.iod_atmo = self._io.read_u1()
            self.tropo_quality_indicator = self._io.read_u1()


    class MsgSsrOrbitClockBounds(KaitaiStruct):
        """Note 1: Range: 0-17.5 m. i<=200, mean=0.01i; 200<i<=230,
        mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
        
        Note 2: Range: 0-17.5 m. i<=200, std=0.01i; 200<i<=230, std=2+0.1(i-200)
        i>230, std=5+0.5(i-230).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Ssr.BoundsHeader(self._io, self, self._root)
            self.ssr_iod = self._io.read_u1()
            self.const_id = self._io.read_u1()
            self.n_sats = self._io.read_u1()
            self.orbit_clock_bounds = []
            i = 0
            while not self._io.is_eof():
                self.orbit_clock_bounds.append(Ssr.OrbitClockBound(self._io, self, self._root))
                i += 1



    class MsgSsrGriddedCorrectionBounds(KaitaiStruct):
        """Note 1: Range: 0-17.5 m. i<= 200, mean = 0.01i; 200<i<=230,
        mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Ssr.BoundsHeader(self._io, self, self._root)
            self.ssr_iod_atmo = self._io.read_u1()
            self.tile_set_id = self._io.read_u2le()
            self.tile_id = self._io.read_u2le()
            self.tropo_qi = self._io.read_u1()
            self.grid_point_id = self._io.read_u2le()
            self.tropo_delay_correction = Ssr.TroposphericDelayCorrection(self._io, self, self._root)
            self.tropo_v_hydro_bound_mu = self._io.read_u1()
            self.tropo_v_hydro_bound_sig = self._io.read_u1()
            self.tropo_v_wet_bound_mu = self._io.read_u1()
            self.tropo_v_wet_bound_sig = self._io.read_u1()
            self.n_sats = self._io.read_u1()
            self.stec_sat_list = []
            i = 0
            while not self._io.is_eof():
                self.stec_sat_list.append(Ssr.StecSatElementIntegrity(self._io, self, self._root))
                i += 1



    class MsgSsrGridDefinitionDepA(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Ssr.GridDefinitionHeaderDepA(self._io, self, self._root)
            self.rle_list = []
            i = 0
            while not self._io.is_eof():
                self.rle_list.append(self._io.read_u1())
                i += 1



    class CodeBiasesContent(KaitaiStruct):
        """Code biases are to be added to pseudorange. The corrections conform with
        RTCMv3 MT 1059 / 1065.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.code = self._io.read_u1()
            self.value = self._io.read_s2le()


    class MsgSsrSatelliteApc(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.time = Gnss.GpsTimeSec(self._io, self, self._root)
            self.update_interval = self._io.read_u1()
            self.sol_id = self._io.read_u1()
            self.iod_ssr = self._io.read_u1()
            self.apc = []
            i = 0
            while not self._io.is_eof():
                self.apc.append(Ssr.SatelliteApc(self._io, self, self._root))
                i += 1



    class PhaseBiasesContent(KaitaiStruct):
        """Phase biases are to be added to carrier phase measurements.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.code = self._io.read_u1()
            self.integer_indicator = self._io.read_u1()
            self.widelane_integer_indicator = self._io.read_u1()
            self.discontinuity_counter = self._io.read_u1()
            self.bias = self._io.read_s4le()


    class MsgSsrTileDefinitionDepA(KaitaiStruct):
        """Provides the correction point coordinates for the atmospheric correction
        values in the MSG_SSR_STEC_CORRECTION_DEP and MSG_SSR_GRIDDED_CORRECTION
        messages.
        
        Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
        element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
        correction points, not lists of points.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tile_set_id = self._io.read_u2le()
            self.tile_id = self._io.read_u2le()
            self.corner_nw_lat = self._io.read_s2le()
            self.corner_nw_lon = self._io.read_s2le()
            self.spacing_lat = self._io.read_u2le()
            self.spacing_lon = self._io.read_u2le()
            self.rows = self._io.read_u2le()
            self.cols = self._io.read_u2le()
            self.bitmask = self._io.read_u8le()


    class OrbitClockBound(KaitaiStruct):
        """Orbit and clock bound.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sat_id = self._io.read_u1()
            self.orb_radial_bound_mu = self._io.read_u1()
            self.orb_along_bound_mu = self._io.read_u1()
            self.orb_cross_bound_mu = self._io.read_u1()
            self.orb_radial_bound_sig = self._io.read_u1()
            self.orb_along_bound_sig = self._io.read_u1()
            self.orb_cross_bound_sig = self._io.read_u1()
            self.clock_bound_mu = self._io.read_u1()
            self.clock_bound_sig = self._io.read_u1()


    class MsgSsrGriddedCorrectionDepA(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Ssr.GriddedCorrectionHeaderDepA(self._io, self, self._root)
            self.index = self._io.read_u2le()
            self.tropo_delay_correction = Ssr.TroposphericDelayCorrection(self._io, self, self._root)
            self.stec_residuals = []
            i = 0
            while not self._io.is_eof():
                self.stec_residuals.append(Ssr.StecResidual(self._io, self, self._root))
                i += 1



    class MsgSsrOrbitClockBoundsDegradation(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Ssr.BoundsHeader(self._io, self, self._root)
            self.ssr_iod = self._io.read_u1()
            self.const_id = self._io.read_u1()
            self.sat_bitmask = self._io.read_u8le()
            self.orbit_clock_bounds_degradation = Ssr.OrbitClockBoundDegradation(self._io, self, self._root)


    class MsgSsrGriddedCorrectionNoStdDepA(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Ssr.GriddedCorrectionHeaderDepA(self._io, self, self._root)
            self.index = self._io.read_u2le()
            self.tropo_delay_correction = Ssr.TroposphericDelayCorrectionNoStd(self._io, self, self._root)
            self.stec_residuals = []
            i = 0
            while not self._io.is_eof():
                self.stec_residuals.append(Ssr.StecResidualNoStd(self._io, self, self._root))
                i += 1



    class MsgSsrCodePhaseBiasesBounds(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Ssr.BoundsHeader(self._io, self, self._root)
            self.ssr_iod = self._io.read_u1()
            self.const_id = self._io.read_u1()
            self.n_sats_signals = self._io.read_u1()
            self.satellites_signals = []
            i = 0
            while not self._io.is_eof():
                self.satellites_signals.append(Ssr.CodePhaseBiasesSatSig(self._io, self, self._root))
                i += 1



    class MsgSsrCodeBiases(KaitaiStruct):
        """The precise code biases message is to be added to the pseudorange of the
        corresponding signal to get corrected pseudorange. It is an equivalent
        to the 1059 / 1065 RTCM message types.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.time = Gnss.GpsTimeSec(self._io, self, self._root)
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.update_interval = self._io.read_u1()
            self.iod_ssr = self._io.read_u1()
            self.biases = []
            i = 0
            while not self._io.is_eof():
                self.biases.append(Ssr.CodeBiasesContent(self._io, self, self._root))
                i += 1



    class MsgSsrTileDefinition(KaitaiStruct):
        """Provides the correction point coordinates for the atmospheric correction
        values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
        messages.
        
        Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
        element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
        correction points, not lists of points.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.time = Gnss.GpsTimeSec(self._io, self, self._root)
            self.update_interval = self._io.read_u1()
            self.sol_id = self._io.read_u1()
            self.iod_atmo = self._io.read_u1()
            self.tile_set_id = self._io.read_u2le()
            self.tile_id = self._io.read_u2le()
            self.corner_nw_lat = self._io.read_s2le()
            self.corner_nw_lon = self._io.read_s2le()
            self.spacing_lat = self._io.read_u2le()
            self.spacing_lon = self._io.read_u2le()
            self.rows = self._io.read_u2le()
            self.cols = self._io.read_u2le()
            self.bitmask = self._io.read_u8le()


    class OrbitClockBoundDegradation(KaitaiStruct):
        """Orbit and clock bound degradation.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.orb_radial_bound_mu_dot = self._io.read_u1()
            self.orb_along_bound_mu_dot = self._io.read_u1()
            self.orb_cross_bound_mu_dot = self._io.read_u1()
            self.orb_radial_bound_sig_dot = self._io.read_u1()
            self.orb_along_bound_sig_dot = self._io.read_u1()
            self.orb_cross_bound_sig_dot = self._io.read_u1()
            self.clock_bound_mu_dot = self._io.read_u1()
            self.clock_bound_sig_dot = self._io.read_u1()


    class MsgSsrSatelliteApcDep(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.apc = []
            i = 0
            while not self._io.is_eof():
                self.apc.append(Ssr.SatelliteApc(self._io, self, self._root))
                i += 1



    class TroposphericDelayCorrection(KaitaiStruct):
        """Troposphere vertical delays (mean and standard deviation) at the grid
        point.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.hydro = self._io.read_s2le()
            self.wet = self._io.read_s1()
            self.stddev = self._io.read_u1()


    class MsgSsrTileDefinitionDepB(KaitaiStruct):
        """Provides the correction point coordinates for the atmospheric correction
        values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
        messages.
        
        Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
        element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
        correction points, not lists of points.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.ssr_sol_id = self._io.read_u1()
            self.tile_set_id = self._io.read_u2le()
            self.tile_id = self._io.read_u2le()
            self.corner_nw_lat = self._io.read_s2le()
            self.corner_nw_lon = self._io.read_s2le()
            self.spacing_lat = self._io.read_u2le()
            self.spacing_lon = self._io.read_u2le()
            self.rows = self._io.read_u2le()
            self.cols = self._io.read_u2le()
            self.bitmask = self._io.read_u8le()


    class MsgSsrPhaseBiases(KaitaiStruct):
        """The precise phase biases message contains the biases to be added to the
        carrier phase of the corresponding signal to get corrected carrier phase
        measurement, as well as the satellite yaw angle to be applied to compute
        the phase wind-up correction. It is typically an equivalent to the 1265
        RTCM message types.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.time = Gnss.GpsTimeSec(self._io, self, self._root)
            self.sid = Gnss.GnssSignal(self._io, self, self._root)
            self.update_interval = self._io.read_u1()
            self.iod_ssr = self._io.read_u1()
            self.dispersive_bias = self._io.read_u1()
            self.mw_consistency = self._io.read_u1()
            self.yaw = self._io.read_u2le()
            self.yaw_rate = self._io.read_s1()
            self.biases = []
            i = 0
            while not self._io.is_eof():
                self.biases.append(Ssr.PhaseBiasesContent(self._io, self, self._root))
                i += 1




