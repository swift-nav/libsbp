# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Orientation(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgBaselineHeading(KaitaiStruct):
        """This message reports the baseline heading pointing from the base station
        to the rover relative to True North. The full GPS time is given by the
        preceding MSG_GPS_TIME with the matching time-of-week (tow). It is
        intended that time-matched RTK mode is used when the base station is
        moving.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.heading = self._io.read_u4le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgOrientQuat(KaitaiStruct):
        """This message reports the quaternion vector describing the vehicle body
        frame's orientation with respect to a local-level NED frame. The
        components of the vector should sum to a unit vector assuming that the
        LSB of each component as a value of 2^-31. This message will only be
        available in future INS versions of Swift Products and is not produced
        by Piksi Multi or Duro.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.w = self._io.read_s4le()
            self.x = self._io.read_s4le()
            self.y = self._io.read_s4le()
            self.z = self._io.read_s4le()
            self.w_accuracy = self._io.read_f4le()
            self.x_accuracy = self._io.read_f4le()
            self.y_accuracy = self._io.read_f4le()
            self.z_accuracy = self._io.read_f4le()
            self.flags = self._io.read_u1()


    class MsgOrientEuler(KaitaiStruct):
        """This message reports the yaw, pitch, and roll angles of the vehicle body
        frame. The rotations should applied intrinsically in the order yaw,
        pitch, and roll in order to rotate the from a frame aligned with the
        local-level NED frame to the vehicle body frame.  This message will only
        be available in future INS versions of Swift Products and is not
        produced by Piksi Multi or Duro.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.roll = self._io.read_s4le()
            self.pitch = self._io.read_s4le()
            self.yaw = self._io.read_s4le()
            self.roll_accuracy = self._io.read_f4le()
            self.pitch_accuracy = self._io.read_f4le()
            self.yaw_accuracy = self._io.read_f4le()
            self.flags = self._io.read_u1()


    class MsgAngularRate(KaitaiStruct):
        """This message reports the orientation rates in the vehicle body frame.
        The values represent the measurements a strapped down gyroscope would
        make and are not equivalent to the time derivative of the Euler angles.
        The orientation and origin of the user frame is specified via device
        settings. By convention, the vehicle x-axis is expected to be aligned
        with the forward direction, while the vehicle y-axis is expected to be
        aligned with the right direction, and the vehicle z-axis should be
        aligned with the down direction. This message will only be available in
        future INS versions of Swift Products and is not produced by Piksi Multi
        or Duro.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.x = self._io.read_s4le()
            self.y = self._io.read_s4le()
            self.z = self._io.read_s4le()
            self.flags = self._io.read_u1()



