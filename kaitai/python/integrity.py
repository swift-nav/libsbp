from .gnss import *
# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Integrity(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgSsrFlagSatellites(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.obs_time = Gnss.GpsTimeSec(self._io, self, self._root)
            self.num_msgs = self._io.read_u1()
            self.seq_num = self._io.read_u1()
            self.ssr_sol_id = self._io.read_u1()
            self.chain_id = self._io.read_u1()
            self.const_id = self._io.read_u1()
            self.n_faulty_sats = self._io.read_u1()
            self.faulty_sats = []
            i = 0
            while not self._io.is_eof():
                self.faulty_sats.append(self._io.read_u1())
                i += 1



    class MsgSsrFlagIonoTileSatLos(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Integrity.IntegritySsrHeader(self._io, self, self._root)
            self.n_faulty_los = self._io.read_u1()
            self.faulty_los = []
            i = 0
            while not self._io.is_eof():
                self.faulty_los.append(Gnss.SvId(self._io, self, self._root))
                i += 1



    class MsgSsrFlagIonoGridPointSatLos(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Integrity.IntegritySsrHeader(self._io, self, self._root)
            self.grid_point_id = self._io.read_u2le()
            self.n_faulty_los = self._io.read_u1()
            self.faulty_los = []
            i = 0
            while not self._io.is_eof():
                self.faulty_los.append(Gnss.SvId(self._io, self, self._root))
                i += 1



    class IntegritySsrHeader(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.obs_time = Gnss.GpsTimeSec(self._io, self, self._root)
            self.num_msgs = self._io.read_u1()
            self.seq_num = self._io.read_u1()
            self.ssr_sol_id = self._io.read_u1()
            self.tile_set_id = self._io.read_u2le()
            self.tile_id = self._io.read_u2le()
            self.chain_id = self._io.read_u1()


    class MsgAcknowledge(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.request_id = self._io.read_u1()
            self.area_id = self._io.read_u4le()
            self.response_code = self._io.read_u1()
            self.correction_mask_on_demand = self._io.read_u2le()
            self.correction_mask_stream = self._io.read_u2le()
            self.solution_id = self._io.read_u1()


    class MsgSsrFlagIonoGridPoints(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Integrity.IntegritySsrHeader(self._io, self, self._root)
            self.n_faulty_points = self._io.read_u1()
            self.faulty_points = []
            i = 0
            while not self._io.is_eof():
                self.faulty_points.append(self._io.read_u2le())
                i += 1



    class MsgSsrFlagTropoGridPoints(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.header = Integrity.IntegritySsrHeader(self._io, self, self._root)
            self.n_faulty_points = self._io.read_u1()
            self.faulty_points = []
            i = 0
            while not self._io.is_eof():
                self.faulty_points.append(self._io.read_u2le())
                i += 1



    class MsgSsrFlagHighLevel(KaitaiStruct):
        """Integrity monitoring flags for multiple aggregated elements. An element
        could be a satellite, SSR grid point, or SSR tile. A group of aggregated
        elements being monitored for integrity could refer to:
        
        - Satellites in a particular {GPS, GAL, BDS} constellation.
        
        - Satellites in the line-of-sight of a particular SSR tile.
        
        - Satellites in the line-of-sight of a particular SSR grid point.
        
        The integrity usage for a group of aggregated elements varies according
        to the integrity flag of the satellites comprising that group.
        
        SSR_INTEGRITY_USAGE_NOMINAL: All satellites received passed the
        integrity check and have flag INTEGRITY_FLAG_OK.
        
        SSR_INTEGRITY_USAGE_WARNING: A limited number of elements in the group
        failed the integrity check. Refer to more granular integrity messages
        for details on the specific failing elements.
        
        SSR_INTEGRITY_USAGE_ALERT: Most elements in the group failed the
        integrity check, do not use for positioning.
        
        SSR_INTEGRITY_USAGE_NOT_MONITORED: Unable to verify the integrity flag
        of elements in the group.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.obs_time = Gnss.GpsTimeSec(self._io, self, self._root)
            self.corr_time = Gnss.GpsTimeSec(self._io, self, self._root)
            self.ssr_sol_id = self._io.read_u1()
            self.tile_set_id = self._io.read_u2le()
            self.tile_id = self._io.read_u2le()
            self.chain_id = self._io.read_u1()
            self.use_gps_sat = self._io.read_u1()
            self.use_gal_sat = self._io.read_u1()
            self.use_bds_sat = self._io.read_u1()
            self.reserved = []
            for i in range(6):
                self.reserved.append(self._io.read_u1())

            self.use_tropo_grid_points = self._io.read_u1()
            self.use_iono_grid_points = self._io.read_u1()
            self.use_iono_tile_sat_los = self._io.read_u1()
            self.use_iono_grid_point_sat_los = self._io.read_u1()



