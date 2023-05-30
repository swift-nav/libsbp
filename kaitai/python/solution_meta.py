# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class SolutionMeta(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class GnssInputType(KaitaiStruct):
        """Metadata around the GNSS sensors involved in the fuzed solution.
        Accessible through sol_in[N].flags in a MSG_SOLN_META.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.flags = self._io.read_u1()


    class MsgSolnMeta(KaitaiStruct):
        """This message contains all metadata about the sensors received and/or
        used in computing the sensorfusion solution. It focuses primarily, but
        not only, on GNSS metadata. Regarding the age of the last received valid
        GNSS solution, the highest two bits are time status, indicating whether
        age gnss can or can not be used to retrieve time of measurement (noted
        TOM, also known as time of validity) If it can, subtract 'age gnss' from
        'tow' in navigation messages to get TOM. Can be used before alignment is
        complete in the Fusion Engine, when output solution is the last received
        valid GNSS solution and its tow is not a TOM.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.pdop = self._io.read_u2le()
            self.hdop = self._io.read_u2le()
            self.vdop = self._io.read_u2le()
            self.age_corrections = self._io.read_u2le()
            self.age_gnss = self._io.read_u4le()
            self.sol_in = []
            i = 0
            while not self._io.is_eof():
                self.sol_in.append(SolutionMeta.SolutionInputType(self._io, self, self._root))
                i += 1



    class MsgSolnMetaDepA(KaitaiStruct):
        """Deprecated.
        
        This message contains all metadata about the sensors received and/or
        used in computing the Fuzed Solution. It focuses primarily, but not
        only, on GNSS metadata.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.pdop = self._io.read_u2le()
            self.hdop = self._io.read_u2le()
            self.vdop = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.age_corrections = self._io.read_u2le()
            self.alignment_status = self._io.read_u1()
            self.last_used_gnss_pos_tow = self._io.read_u4le()
            self.last_used_gnss_vel_tow = self._io.read_u4le()
            self.sol_in = []
            i = 0
            while not self._io.is_eof():
                self.sol_in.append(SolutionMeta.SolutionInputType(self._io, self, self._root))
                i += 1



    class ImuInputType(KaitaiStruct):
        """Metadata around the IMU sensors involved in the fuzed solution.
        Accessible through sol_in[N].flags in a MSG_SOLN_META.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.flags = self._io.read_u1()


    class OdoInputType(KaitaiStruct):
        """Metadata around the Odometry sensors involved in the fuzed solution.
        Accessible through sol_in[N].flags in a MSG_SOLN_META.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.flags = self._io.read_u1()


    class SolutionInputType(KaitaiStruct):
        """Metadata describing which sensors were involved in the solution. The
        structure is fixed no matter what the actual sensor type is. The
        sensor_type field tells you which sensor we are talking about. It also
        tells you whether the sensor data was actually used or not. The flags
        field, always a u8, contains the sensor-specific data. The content of
        flags, for each sensor type, is described in the relevant structures in
        this section.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.sensor_type = self._io.read_u1()
            self.flags = self._io.read_u1()



