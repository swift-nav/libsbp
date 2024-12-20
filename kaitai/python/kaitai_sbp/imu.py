# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Imu(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgImuRaw(KaitaiStruct):
        """Raw data from the Inertial Measurement Unit, containing accelerometer
        and gyroscope readings. The sense of the measurements are to be aligned
        with the indications on the device itself. Measurement units, which are
        specific to the device hardware and settings, are communicated via the
        MSG_IMU_AUX message. If using "time since startup" local time tags, the
        receiving end will expect either a MSG_GNSS_TIME_OFFSET or MSG_PPS_TIME
        to establish the relationship between IMU time and GNSS time.
        Regardless of the timestamping mode, the timestamp is required to roll
        over to zero when reaching one week (604800 seconds, or 604800000
        milliseconds).
        The time-tagging mode should not change throughout a run.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.tow_f = self._io.read_u1()
            self.acc_x = self._io.read_s2le()
            self.acc_y = self._io.read_s2le()
            self.acc_z = self._io.read_s2le()
            self.gyr_x = self._io.read_s2le()
            self.gyr_y = self._io.read_s2le()
            self.gyr_z = self._io.read_s2le()


    class MsgImuAux(KaitaiStruct):
        """Auxiliary data specific to a particular IMU. The `imu_type` field will
        always be consistent but the rest of the payload is device specific and
        depends on the value of `imu_type`.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.imu_type = self._io.read_u1()
            self.temp = self._io.read_s2le()
            self.imu_conf = self._io.read_u1()


    class MsgImuComp(KaitaiStruct):
        """Data from the Inertial Measurement Unit, containing accelerometer and
        gyroscope readings compensated for estimated errors and constant
        physical effects. The output is valid for inertially referenced center
        of navigation (IMU body frame) represented in vehicle body frame.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.time = self._io.read_u8le()
            self.flags = self._io.read_u2le()
            self.acc_comp_x = self._io.read_s4le()
            self.acc_comp_y = self._io.read_s4le()
            self.acc_comp_z = self._io.read_s4le()
            self.gyr_comp_x = self._io.read_s4le()
            self.gyr_comp_y = self._io.read_s4le()
            self.gyr_comp_z = self._io.read_s4le()



