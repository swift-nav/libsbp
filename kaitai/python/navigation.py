# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 9):
    raise Exception("Incompatible Kaitai Struct Python API: 0.9 or later is required, but you have %s" % (kaitaistruct.__version__))

class Navigation(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        self._io = _io
        self._parent = _parent
        self._root = _root if _root else self
        self._read()

    def _read(self):
        pass

    class MsgPosLlhDepA(KaitaiStruct):
        """This position solution message reports the absolute geodetic coordinates
        and the status (single point vs pseudo-absolute RTK) of the position
        solution. If the rover receiver knows the surveyed position of the base
        station and has an RTK solution, this reports a pseudo-absolute position
        solution using the base station position and the rover's RTK baseline
        vector. The full GPS time is given by the preceding MSG_GPS_TIME with
        the matching time-of-week (tow).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.lat = self._io.read_f8le()
            self.lon = self._io.read_f8le()
            self.height = self._io.read_f8le()
            self.h_accuracy = self._io.read_u2le()
            self.v_accuracy = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgProtectionLevelDepA(KaitaiStruct):
        """This message reports the local vertical and horizontal protection levels
        associated with a given LLH position solution. The full GPS time is
        given by the preceding MSG_GPS_TIME with the matching time-of-week
        (tow).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.vpl = self._io.read_u2le()
            self.hpl = self._io.read_u2le()
            self.lat = self._io.read_f8le()
            self.lon = self._io.read_f8le()
            self.height = self._io.read_f8le()
            self.flags = self._io.read_u1()


    class MsgPosLlhCov(KaitaiStruct):
        """This position solution message reports the absolute geodetic coordinates
        and the status (single point vs pseudo-absolute RTK) of the position
        solution as well as the upper triangle of the 3x3 covariance matrix.
        The position information and Fix Mode flags follow the MSG_POS_LLH
        message.  Since the covariance matrix is computed in the local-level
        North, East, Down frame, the covariance terms follow that convention.
        Thus, covariances are reported against the "downward" measurement and
        care should be taken with the sign convention.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.lat = self._io.read_f8le()
            self.lon = self._io.read_f8le()
            self.height = self._io.read_f8le()
            self.cov_n_n = self._io.read_f4le()
            self.cov_n_e = self._io.read_f4le()
            self.cov_n_d = self._io.read_f4le()
            self.cov_e_e = self._io.read_f4le()
            self.cov_e_d = self._io.read_f4le()
            self.cov_d_d = self._io.read_f4le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgVelNedDepA(KaitaiStruct):
        """This message reports the velocity in local North East Down (NED)
        coordinates. The NED coordinate system is defined as the local WGS84
        tangent plane centered at the current position. The full GPS time is
        given by the preceding MSG_GPS_TIME with the matching time-of-week
        (tow).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.n = self._io.read_s4le()
            self.e = self._io.read_s4le()
            self.d = self._io.read_s4le()
            self.h_accuracy = self._io.read_u2le()
            self.v_accuracy = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgVelNedCov(KaitaiStruct):
        """This message reports the velocity in local North East Down (NED)
        coordinates. The NED coordinate system is defined as the local WGS84
        tangent plane centered at the current position. The full GPS time is
        given by the preceding MSG_GPS_TIME with the matching time-of-week
        (tow). This message is similar to the MSG_VEL_NED, but it includes the
        upper triangular portion of the 3x3 covariance matrix.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.n = self._io.read_s4le()
            self.e = self._io.read_s4le()
            self.d = self._io.read_s4le()
            self.cov_n_n = self._io.read_f4le()
            self.cov_n_e = self._io.read_f4le()
            self.cov_n_d = self._io.read_f4le()
            self.cov_e_e = self._io.read_f4le()
            self.cov_e_d = self._io.read_f4le()
            self.cov_d_d = self._io.read_f4le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgUtcTime(KaitaiStruct):
        """This message reports the Universal Coordinated Time (UTC).  Note the
        flags which indicate the source of the UTC offset value and source of
        the time fix.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.flags = self._io.read_u1()
            self.tow = self._io.read_u4le()
            self.year = self._io.read_u2le()
            self.month = self._io.read_u1()
            self.day = self._io.read_u1()
            self.hours = self._io.read_u1()
            self.minutes = self._io.read_u1()
            self.seconds = self._io.read_u1()
            self.ns = self._io.read_u4le()


    class MsgPosEcefCovGnss(KaitaiStruct):
        """The position solution message reports absolute Earth Centered Earth
        Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
        RTK) of the position solution. The message also reports the upper
        triangular portion of the 3x3 covariance matrix. If the receiver knows
        the surveyed position of the base station and has an RTK solution, this
        reports a pseudo-absolute position solution using the base station
        position and the rover's RTK baseline vector. The full GPS time is given
        by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.x = self._io.read_f8le()
            self.y = self._io.read_f8le()
            self.z = self._io.read_f8le()
            self.cov_x_x = self._io.read_f4le()
            self.cov_x_y = self._io.read_f4le()
            self.cov_x_z = self._io.read_f4le()
            self.cov_y_y = self._io.read_f4le()
            self.cov_y_z = self._io.read_f4le()
            self.cov_z_z = self._io.read_f4le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgVelNedGnss(KaitaiStruct):
        """This message reports the velocity in local North East Down (NED)
        coordinates. The NED coordinate system is defined as the local WGS84
        tangent plane centered at the current position. The full GPS time is
        given by the preceding MSG_GPS_TIME with the matching time-of-week
        (tow).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.n = self._io.read_s4le()
            self.e = self._io.read_s4le()
            self.d = self._io.read_s4le()
            self.h_accuracy = self._io.read_u2le()
            self.v_accuracy = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgVelNedCovGnss(KaitaiStruct):
        """This message reports the velocity in local North East Down (NED)
        coordinates. The NED coordinate system is defined as the local WGS84
        tangent plane centered at the current position. The full GPS time is
        given by the preceding MSG_GPS_TIME with the matching time-of-week
        (tow). This message is similar to the MSG_VEL_NED, but it includes the
        upper triangular portion of the 3x3 covariance matrix.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.n = self._io.read_s4le()
            self.e = self._io.read_s4le()
            self.d = self._io.read_s4le()
            self.cov_n_n = self._io.read_f4le()
            self.cov_n_e = self._io.read_f4le()
            self.cov_n_d = self._io.read_f4le()
            self.cov_e_e = self._io.read_f4le()
            self.cov_e_d = self._io.read_f4le()
            self.cov_d_d = self._io.read_f4le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgBaselineNedDepA(KaitaiStruct):
        """This message reports the baseline solution in North East Down (NED)
        coordinates. This baseline is the relative vector distance from the base
        station to the rover receiver, and NED coordinate system is defined at
        the local WGS84 tangent plane centered at the base station position.
        The full GPS time is given by the preceding MSG_GPS_TIME with the
        matching time-of-week (tow).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.n = self._io.read_s4le()
            self.e = self._io.read_s4le()
            self.d = self._io.read_s4le()
            self.h_accuracy = self._io.read_u2le()
            self.v_accuracy = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgVelEcefDepA(KaitaiStruct):
        """This message reports the velocity in Earth Centered Earth Fixed (ECEF)
        coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
        with the matching time-of-week (tow).
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
            self.accuracy = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgReferenceFrameParam(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.ssr_iod = self._io.read_u1()
            self.sn = (self._io.read_bytes_full()).decode(u"ascii")
            self.tn = (self._io.read_bytes_full()).decode(u"ascii")
            self.sin = self._io.read_u1()
            self.utn = self._io.read_u2le()
            self.re_t0 = self._io.read_u2le()
            self.delta_x0 = self._io.read_s4le()
            self.delta_y0 = self._io.read_s4le()
            self.delta_z0 = self._io.read_s4le()
            self.theta_01 = self._io.read_s4le()
            self.theta_02 = self._io.read_s4le()
            self.theta_03 = self._io.read_s4le()
            self.scale = self._io.read_s4le()
            self.dot_delta_x0 = self._io.read_s4le()
            self.dot_delta_y0 = self._io.read_s4le()
            self.dot_delta_z0 = self._io.read_s4le()
            self.dot_theta_01 = self._io.read_s4le()
            self.dot_theta_02 = self._io.read_s4le()
            self.dot_theta_03 = self._io.read_s4le()
            self.dot_scale = self._io.read_s2le()


    class MsgPoseRelative(KaitaiStruct):
        """This solution message reports the relative pose of a sensor between two
        time instances. The relative pose comprises of a rotation and a
        translation which relates the sensor (e.g. camera) frame at a given time
        (first keyframe) to the sensor frame at another time (second keyframe).
        The relative translations is a 3x1 vector described in the first
        keyframe.  Relative rotation is described by a quaternion from second
        keyframe to the first keyframe.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.sensor_id = self._io.read_u1()
            self.timestamp_1 = self._io.read_u4le()
            self.timestamp_2 = self._io.read_u4le()
            self.trans = []
            for i in range(3):
                self.trans.append(self._io.read_s4le())

            self.w = self._io.read_s4le()
            self.x = self._io.read_s4le()
            self.y = self._io.read_s4le()
            self.z = self._io.read_s4le()
            self.cov_r_x_x = self._io.read_f4le()
            self.cov_r_x_y = self._io.read_f4le()
            self.cov_r_x_z = self._io.read_f4le()
            self.cov_r_y_y = self._io.read_f4le()
            self.cov_r_y_z = self._io.read_f4le()
            self.cov_r_z_z = self._io.read_f4le()
            self.cov_c_x_x = self._io.read_f4le()
            self.cov_c_x_y = self._io.read_f4le()
            self.cov_c_x_z = self._io.read_f4le()
            self.cov_c_y_y = self._io.read_f4le()
            self.cov_c_y_z = self._io.read_f4le()
            self.cov_c_z_z = self._io.read_f4le()
            self.flags = self._io.read_u1()


    class MsgVelEcefCov(KaitaiStruct):
        """This message reports the velocity in Earth Centered Earth Fixed (ECEF)
        coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
        with the matching time-of-week (tow).
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
            self.cov_x_x = self._io.read_f4le()
            self.cov_x_y = self._io.read_f4le()
            self.cov_x_z = self._io.read_f4le()
            self.cov_y_y = self._io.read_f4le()
            self.cov_y_z = self._io.read_f4le()
            self.cov_z_z = self._io.read_f4le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgVelBody(KaitaiStruct):
        """This message reports the velocity in the Vehicle Body Frame. By
        convention, the x-axis should point out the nose of the vehicle and
        represent the forward direction, while as the y-axis should point out
        the right hand side of the vehicle. Since this is a right handed system,
        z should point out the bottom of the vehicle. The orientation and origin
        of the Vehicle Body Frame are specified via the device settings. The
        full GPS time is given by the preceding MSG_GPS_TIME with the matching
        time-of-week (tow). This message is only produced by inertial versions
        of Swift products and is not available from Piksi Multi or Duro.
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
            self.cov_x_x = self._io.read_f4le()
            self.cov_x_y = self._io.read_f4le()
            self.cov_x_z = self._io.read_f4le()
            self.cov_y_y = self._io.read_f4le()
            self.cov_y_z = self._io.read_f4le()
            self.cov_z_z = self._io.read_f4le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgVelEcefGnss(KaitaiStruct):
        """This message reports the velocity in Earth Centered Earth Fixed (ECEF)
        coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
        with the matching time-of-week (tow).
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
            self.accuracy = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgVelEcef(KaitaiStruct):
        """This message reports the velocity in Earth Centered Earth Fixed (ECEF)
        coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
        with the matching time-of-week (tow).
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
            self.accuracy = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgPosLlhCovGnss(KaitaiStruct):
        """This position solution message reports the absolute geodetic coordinates
        and the status (single point vs pseudo-absolute RTK) of the position
        solution as well as the upper triangle of the 3x3 covariance matrix.
        The position information and Fix Mode flags should follow the
        MSG_POS_LLH message.  Since the covariance matrix is computed in the
        local-level North, East, Down frame, the covariance terms follow with
        that convention. Thus, covariances are reported against the "downward"
        measurement and care should be taken with the sign convention.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.lat = self._io.read_f8le()
            self.lon = self._io.read_f8le()
            self.height = self._io.read_f8le()
            self.cov_n_n = self._io.read_f4le()
            self.cov_n_e = self._io.read_f4le()
            self.cov_n_d = self._io.read_f4le()
            self.cov_e_e = self._io.read_f4le()
            self.cov_e_d = self._io.read_f4le()
            self.cov_d_d = self._io.read_f4le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgBaselineEcef(KaitaiStruct):
        """This message reports the baseline solution in Earth Centered Earth Fixed
        (ECEF) coordinates. This baseline is the relative vector distance from
        the base station to the rover receiver. The full GPS time is given by
        the preceding MSG_GPS_TIME with the matching time-of-week (tow).
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
            self.accuracy = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgDopsDepA(KaitaiStruct):
        """This dilution of precision (DOP) message describes the effect of
        navigation satellite geometry on positional measurement precision.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.gdop = self._io.read_u2le()
            self.pdop = self._io.read_u2le()
            self.tdop = self._io.read_u2le()
            self.hdop = self._io.read_u2le()
            self.vdop = self._io.read_u2le()


    class MsgPosEcef(KaitaiStruct):
        """The position solution message reports absolute Earth Centered Earth
        Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
        RTK) of the position solution. If the rover receiver knows the surveyed
        position of the base station and has an RTK solution, this reports a
        pseudo-absolute position solution using the base station position and
        the rover's RTK baseline vector. The full GPS time is given by the
        preceding MSG_GPS_TIME with the matching time-of-week (tow).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.x = self._io.read_f8le()
            self.y = self._io.read_f8le()
            self.z = self._io.read_f8le()
            self.accuracy = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgAgeCorrections(KaitaiStruct):
        """This message reports the Age of the corrections used for the current
        Differential solution.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.age = self._io.read_u2le()


    class MsgVelEcefCovGnss(KaitaiStruct):
        """This message reports the velocity in Earth Centered Earth Fixed (ECEF)
        coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
        with the matching time-of-week (tow).
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
            self.cov_x_x = self._io.read_f4le()
            self.cov_x_y = self._io.read_f4le()
            self.cov_x_z = self._io.read_f4le()
            self.cov_y_y = self._io.read_f4le()
            self.cov_y_z = self._io.read_f4le()
            self.cov_z_z = self._io.read_f4le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgProtectionLevel(KaitaiStruct):
        """This message reports the protection levels associated to the given state
        estimate. The full GPS time is given by the preceding MSG_GPS_TIME with
        the matching time-of-week (tow).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.wn = self._io.read_s2le()
            self.hpl = self._io.read_u2le()
            self.vpl = self._io.read_u2le()
            self.atpl = self._io.read_u2le()
            self.ctpl = self._io.read_u2le()
            self.hvpl = self._io.read_u2le()
            self.vvpl = self._io.read_u2le()
            self.hopl = self._io.read_u2le()
            self.popl = self._io.read_u2le()
            self.ropl = self._io.read_u2le()
            self.lat = self._io.read_f8le()
            self.lon = self._io.read_f8le()
            self.height = self._io.read_f8le()
            self.v_x = self._io.read_s4le()
            self.v_y = self._io.read_s4le()
            self.v_z = self._io.read_s4le()
            self.roll = self._io.read_s4le()
            self.pitch = self._io.read_s4le()
            self.heading = self._io.read_s4le()
            self.flags = self._io.read_u4le()


    class MsgPosEcefCov(KaitaiStruct):
        """The position solution message reports absolute Earth Centered Earth
        Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
        RTK) of the position solution. The message also reports the upper
        triangular portion of the 3x3 covariance matrix. If the receiver knows
        the surveyed position of the base station and has an RTK solution, this
        reports a pseudo-absolute position solution using the base station
        position and the rover's RTK baseline vector. The full GPS time is given
        by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.x = self._io.read_f8le()
            self.y = self._io.read_f8le()
            self.z = self._io.read_f8le()
            self.cov_x_x = self._io.read_f4le()
            self.cov_x_y = self._io.read_f4le()
            self.cov_x_z = self._io.read_f4le()
            self.cov_y_y = self._io.read_f4le()
            self.cov_y_z = self._io.read_f4le()
            self.cov_z_z = self._io.read_f4le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgPosEcefGnss(KaitaiStruct):
        """The position solution message reports absolute Earth Centered Earth
        Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
        RTK) of the position solution. If the rover receiver knows the surveyed
        position of the base station and has an RTK solution, this reports a
        pseudo-absolute position solution using the base station position and
        the rover's RTK baseline vector. The full GPS time is given by the
        preceding MSG_GPS_TIME with the matching time-of-week (tow).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.x = self._io.read_f8le()
            self.y = self._io.read_f8le()
            self.z = self._io.read_f8le()
            self.accuracy = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgVelNed(KaitaiStruct):
        """This message reports the velocity in local North East Down (NED)
        coordinates. The NED coordinate system is defined as the local WGS84
        tangent plane centered at the current position. The full GPS time is
        given by the preceding MSG_GPS_TIME with the matching time-of-week
        (tow).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.n = self._io.read_s4le()
            self.e = self._io.read_s4le()
            self.d = self._io.read_s4le()
            self.h_accuracy = self._io.read_u2le()
            self.v_accuracy = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgUtcLeapSecond(KaitaiStruct):
        """UTC-GPST leap seconds before and after the most recent (past, or future,
        for announced insertions) UTC leap second insertion.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.reserved_0 = self._io.read_s2le()
            self.reserved_1 = self._io.read_s2le()
            self.reserved_2 = self._io.read_s1()
            self.count_before = self._io.read_s1()
            self.reserved_3 = self._io.read_u2le()
            self.reserved_4 = self._io.read_u2le()
            self.ref_wn = self._io.read_u2le()
            self.ref_dn = self._io.read_u1()
            self.count_after = self._io.read_s1()


    class MsgGpsTimeDepA(KaitaiStruct):
        """This message reports the GPS time, representing the time since the GPS
        epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
        and seconds of the week. The weeks begin at the Saturday/Sunday
        transition. GPS week 0 began at the beginning of the GPS time scale.
        
        Within each week number, the GPS time of the week is between between 0
        and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
        leap seconds, and as of now, has a small offset from UTC. In a message
        stream, this message precedes a set of other navigation messages
        referenced to the same time (but lacking the ns field) and indicates a
        more precise time of these messages.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.wn = self._io.read_u2le()
            self.tow = self._io.read_u4le()
            self.ns_residual = self._io.read_s4le()
            self.flags = self._io.read_u1()


    class MsgPosLlhGnss(KaitaiStruct):
        """This position solution message reports the absolute geodetic coordinates
        and the status (single point vs pseudo-absolute RTK) of the position
        solution. If the rover receiver knows the surveyed position of the base
        station and has an RTK solution, this reports a pseudo-absolute position
        solution using the base station position and the rover's RTK baseline
        vector. The full GPS time is given by the preceding MSG_GPS_TIME with
        the matching time-of-week (tow).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.lat = self._io.read_f8le()
            self.lon = self._io.read_f8le()
            self.height = self._io.read_f8le()
            self.h_accuracy = self._io.read_u2le()
            self.v_accuracy = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgUtcTimeGnss(KaitaiStruct):
        """This message reports the Universal Coordinated Time (UTC).  Note the
        flags which indicate the source of the UTC offset value and source of
        the time fix.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.flags = self._io.read_u1()
            self.tow = self._io.read_u4le()
            self.year = self._io.read_u2le()
            self.month = self._io.read_u1()
            self.day = self._io.read_u1()
            self.hours = self._io.read_u1()
            self.minutes = self._io.read_u1()
            self.seconds = self._io.read_u1()
            self.ns = self._io.read_u4le()


    class MsgVelCog(KaitaiStruct):
        """This message reports the receiver course over ground (COG) and speed
        over  ground (SOG) based on the horizontal (N-E) components of the NED
        velocity  vector. It also includes the vertical velocity coordinate. A
        flag is provided to indicate whether the COG value has been frozen. When
        the flag is set to true, the COG field is set to its last valid value
        until  the system exceeds a minimum velocity threshold. No other fields
        are  affected by this flag.  The NED coordinate system is defined as the
        local WGS84 tangent  plane centered at the current position. The full
        GPS time is given by the  preceding MSG_GPS_TIME with the matching time-
        of-week (tow). Note: course over ground represents the receiver's
        direction of travel,  but not necessarily the device heading.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.cog = self._io.read_u4le()
            self.sog = self._io.read_u4le()
            self.v_up = self._io.read_s4le()
            self.cog_accuracy = self._io.read_u4le()
            self.sog_accuracy = self._io.read_u4le()
            self.v_up_accuracy = self._io.read_u4le()
            self.flags = self._io.read_u2le()


    class MsgBaselineNed(KaitaiStruct):
        """This message reports the baseline solution in North East Down (NED)
        coordinates. This baseline is the relative vector distance from the base
        station to the rover receiver, and NED coordinate system is defined at
        the local WGS84 tangent plane centered at the base station position.
        The full GPS time is given by the preceding MSG_GPS_TIME with the
        matching time-of-week (tow).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.n = self._io.read_s4le()
            self.e = self._io.read_s4le()
            self.d = self._io.read_s4le()
            self.h_accuracy = self._io.read_u2le()
            self.v_accuracy = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgPosLlh(KaitaiStruct):
        """This position solution message reports the absolute geodetic coordinates
        and the status (single point vs pseudo-absolute RTK) of the position
        solution. If the rover receiver knows the surveyed position of the base
        station and has an RTK solution, this reports a pseudo-absolute position
        solution using the base station position and the rover's RTK baseline
        vector. The full GPS time is given by the preceding MSG_GPS_TIME with
        the matching time-of-week (tow).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.lat = self._io.read_f8le()
            self.lon = self._io.read_f8le()
            self.height = self._io.read_f8le()
            self.h_accuracy = self._io.read_u2le()
            self.v_accuracy = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgBaselineHeadingDepA(KaitaiStruct):
        """This message reports the baseline heading pointing from the base station
        to the rover relative to True North. The full GPS time is given by the
        preceding MSG_GPS_TIME with the matching time-of-week (tow).
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


    class MsgGpsTimeGnss(KaitaiStruct):
        """This message reports the GPS time, representing the time since the GPS
        epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
        and seconds of the week. The weeks begin at the Saturday/Sunday
        transition. GPS week 0 began at the beginning of the GPS time scale.
        
        Within each week number, the GPS time of the week is between between 0
        and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
        leap seconds, and as of now, has a small offset from UTC. In a message
        stream, this message precedes a set of other navigation messages
        referenced to the same time (but lacking the ns field) and indicates a
        more precise time of these messages.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.wn = self._io.read_u2le()
            self.tow = self._io.read_u4le()
            self.ns_residual = self._io.read_s4le()
            self.flags = self._io.read_u1()


    class MsgBaselineEcefDepA(KaitaiStruct):
        """This message reports the baseline solution in Earth Centered Earth Fixed
        (ECEF) coordinates. This baseline is the relative vector distance from
        the base station to the rover receiver. The full GPS time is given by
        the preceding MSG_GPS_TIME with the matching time-of-week (tow).
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
            self.accuracy = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class MsgGpsTime(KaitaiStruct):
        """This message reports the GPS time, representing the time since the GPS
        epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
        and seconds of the week. The weeks begin at the Saturday/Sunday
        transition. GPS week 0 began at the beginning of the GPS time scale.
        
        Within each week number, the GPS time of the week is between between 0
        and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
        leap seconds, and as of now, has a small offset from UTC. In a message
        stream, this message precedes a set of other navigation messages
        referenced to the same time (but lacking the ns field) and indicates a
        more precise time of these messages.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.wn = self._io.read_u2le()
            self.tow = self._io.read_u4le()
            self.ns_residual = self._io.read_s4le()
            self.flags = self._io.read_u1()


    class MsgDops(KaitaiStruct):
        """This dilution of precision (DOP) message describes the effect of
        navigation satellite geometry on positional measurement precision.  The
        flags field indicated whether the DOP reported corresponds to
        differential or SPP solution.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.gdop = self._io.read_u2le()
            self.pdop = self._io.read_u2le()
            self.tdop = self._io.read_u2le()
            self.hdop = self._io.read_u2le()
            self.vdop = self._io.read_u2le()
            self.flags = self._io.read_u1()


    class MsgPosEcefDepA(KaitaiStruct):
        """The position solution message reports absolute Earth Centered Earth
        Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
        RTK) of the position solution. If the rover receiver knows the surveyed
        position of the base station and has an RTK solution, this reports a
        pseudo-absolute position solution using the base station position and
        the rover's RTK baseline vector. The full GPS time is given by the
        preceding MSG_GPS_TIME with the matching time-of-week (tow).
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.x = self._io.read_f8le()
            self.y = self._io.read_f8le()
            self.z = self._io.read_f8le()
            self.accuracy = self._io.read_u2le()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()


    class EstimatedHorizontalErrorEllipse(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.semi_major = self._io.read_f4le()
            self.semi_minor = self._io.read_f4le()
            self.orientation = self._io.read_f4le()


    class MsgPosLlhAcc(KaitaiStruct):
        """This position solution message reports the absolute geodetic coordinates
        and the status (single point vs pseudo-absolute RTK) of the position
        solution as well as the estimated horizontal, vertical, cross-track and
        along-track errors.  The position information and Fix Mode flags  follow
        the MSG_POS_LLH message. Since the covariance matrix is computed in the
        local-level North, East, Down frame, the estimated error terms follow
        that convention.
        
        The estimated errors are reported at a user-configurable confidence
        level. The user-configured percentile is encoded in the percentile
        field.
        """
        def __init__(self, _io, _parent=None, _root=None):
            self._io = _io
            self._parent = _parent
            self._root = _root if _root else self
            self._read()

        def _read(self):
            self.tow = self._io.read_u4le()
            self.lat = self._io.read_f8le()
            self.lon = self._io.read_f8le()
            self.height = self._io.read_f8le()
            self.orthometric_height = self._io.read_f8le()
            self.h_accuracy = self._io.read_f4le()
            self.v_accuracy = self._io.read_f4le()
            self.ct_accuracy = self._io.read_f4le()
            self.at_accuracy = self._io.read_f4le()
            self.h_ellipse = Navigation.EstimatedHorizontalErrorEllipse(self._io, self, self._root)
            self.confidence_and_geoid = self._io.read_u1()
            self.n_sats = self._io.read_u1()
            self.flags = self._io.read_u1()



