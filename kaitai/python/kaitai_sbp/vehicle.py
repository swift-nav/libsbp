# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Vehicle(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgOdometry(KaitaiStruct):
        """Message representing the x component of vehicle velocity in the user
        frame at the odometry reference point(s) specified by the user. The
        offset for the odometry reference point and the definition and origin of
        the user frame are defined through the device settings interface. There
        are 4 possible user-defined sources of this message which are labeled
        arbitrarily source 0 through 3.
        If using "processor time" time tags, the receiving end will expect
        either  `MSG_GNSS_TIME_OFFSET` or `MSG_PPS_TIME` to sync incoming
        odometry data to GNSS time.  Processor time shall roll over to zero
        after one week.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.velocity = self._io.read_s4le()
            self.flags = self._io.read_u1()


    class MsgWheeltick(KaitaiStruct):
        """Message containing the accumulated distance travelled by a wheel located
        at an odometry reference point defined by the user. The offset for the
        odometry reference point and the definition and origin of the user frame
        are defined through the device settings interface. The source of this
        message is identified by the source field, which is an integer ranging
        from 0 to 255. The timestamp associated with this message should
        represent the time when the accumulated tick count reached the value
        given by the contents of this message as accurately as possible. If
        using "local CPU time" time tags, the receiving end will also expect
        either `MSG_GNSS_TIME_OFFSET` or `MSG_PPS_TIME` to sync incoming
        wheeltick data to GNSS time.
        Local CPU time shall roll over to zero after one week.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.time = self._io.read_u8le()
            self.flags = self._io.read_u1()
            self.source = self._io.read_u1()
            self.ticks = self._io.read_s4le()



