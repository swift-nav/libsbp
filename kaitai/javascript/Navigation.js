// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Navigation = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Navigation = (function() {
  function Navigation(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Navigation.prototype._read = function() {
  }

  /**
   * This position solution message reports the absolute geodetic coordinates
   * and the status (single point vs pseudo-absolute RTK) of the position
   * solution. If the rover receiver knows the surveyed position of the base
   * station and has an RTK solution, this reports a pseudo-absolute position
   * solution using the base station position and the rover's RTK baseline
   * vector. The full GPS time is given by the preceding MSG_GPS_TIME with
   * the matching time-of-week (tow).
   */

  var MsgPosLlhDepA = Navigation.MsgPosLlhDepA = (function() {
    function MsgPosLlhDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgPosLlhDepA.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.lat = this._io.readF8le();
      this.lon = this._io.readF8le();
      this.height = this._io.readF8le();
      this.hAccuracy = this._io.readU2le();
      this.vAccuracy = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Latitude
     */

    /**
     * Longitude
     */

    /**
     * Height
     */

    /**
     * Horizontal position accuracy estimate (not implemented). Defaults to
     * 0.
     */

    /**
     * Vertical position accuracy estimate (not implemented). Defaults to
     * 0.
     */

    /**
     * Number of satellites used in solution.
     */

    /**
     * Status flags
     */

    return MsgPosLlhDepA;
  })();

  /**
   * This message reports the local vertical and horizontal protection levels
   * associated with a given LLH position solution. The full GPS time is
   * given by the preceding MSG_GPS_TIME with the matching time-of-week
   * (tow).
   */

  var MsgProtectionLevelDepA = Navigation.MsgProtectionLevelDepA = (function() {
    function MsgProtectionLevelDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgProtectionLevelDepA.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.vpl = this._io.readU2le();
      this.hpl = this._io.readU2le();
      this.lat = this._io.readF8le();
      this.lon = this._io.readF8le();
      this.height = this._io.readF8le();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Vertical protection level
     */

    /**
     * Horizontal protection level
     */

    /**
     * Latitude
     */

    /**
     * Longitude
     */

    /**
     * Height
     */

    /**
     * Status flags
     */

    return MsgProtectionLevelDepA;
  })();

  /**
   * This position solution message reports the absolute geodetic coordinates
   * and the status (single point vs pseudo-absolute RTK) of the position
   * solution as well as the upper triangle of the 3x3 covariance matrix.
   * The position information and Fix Mode flags follow the MSG_POS_LLH
   * message.  Since the covariance matrix is computed in the local-level
   * North, East, Down frame, the covariance terms follow that convention.
   * Thus, covariances are reported against the "downward" measurement and
   * care should be taken with the sign convention.
   */

  var MsgPosLlhCov = Navigation.MsgPosLlhCov = (function() {
    function MsgPosLlhCov(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgPosLlhCov.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.lat = this._io.readF8le();
      this.lon = this._io.readF8le();
      this.height = this._io.readF8le();
      this.covNN = this._io.readF4le();
      this.covNE = this._io.readF4le();
      this.covND = this._io.readF4le();
      this.covEE = this._io.readF4le();
      this.covED = this._io.readF4le();
      this.covDD = this._io.readF4le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Latitude
     */

    /**
     * Longitude
     */

    /**
     * Height above WGS84 ellipsoid
     */

    /**
     * Estimated variance of northing
     */

    /**
     * Covariance of northing and easting
     */

    /**
     * Covariance of northing and downward measurement
     */

    /**
     * Estimated variance of easting
     */

    /**
     * Covariance of easting and downward measurement
     */

    /**
     * Estimated variance of downward measurement
     */

    /**
     * Number of satellites used in solution.
     */

    /**
     * Status flags
     */

    return MsgPosLlhCov;
  })();

  /**
   * This message reports the velocity in local North East Down (NED)
   * coordinates. The NED coordinate system is defined as the local WGS84
   * tangent plane centered at the current position. The full GPS time is
   * given by the preceding MSG_GPS_TIME with the matching time-of-week
   * (tow).
   */

  var MsgVelNedDepA = Navigation.MsgVelNedDepA = (function() {
    function MsgVelNedDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgVelNedDepA.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.n = this._io.readS4le();
      this.e = this._io.readS4le();
      this.d = this._io.readS4le();
      this.hAccuracy = this._io.readU2le();
      this.vAccuracy = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Velocity North coordinate
     */

    /**
     * Velocity East coordinate
     */

    /**
     * Velocity Down coordinate
     */

    /**
     * Horizontal velocity accuracy estimate (not implemented). Defaults to
     * 0.
     */

    /**
     * Vertical velocity accuracy estimate (not implemented). Defaults to
     * 0.
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags (reserved)
     */

    return MsgVelNedDepA;
  })();

  /**
   * This message reports the velocity in local North East Down (NED)
   * coordinates. The NED coordinate system is defined as the local WGS84
   * tangent plane centered at the current position. The full GPS time is
   * given by the preceding MSG_GPS_TIME with the matching time-of-week
   * (tow). This message is similar to the MSG_VEL_NED, but it includes the
   * upper triangular portion of the 3x3 covariance matrix.
   */

  var MsgVelNedCov = Navigation.MsgVelNedCov = (function() {
    function MsgVelNedCov(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgVelNedCov.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.n = this._io.readS4le();
      this.e = this._io.readS4le();
      this.d = this._io.readS4le();
      this.covNN = this._io.readF4le();
      this.covNE = this._io.readF4le();
      this.covND = this._io.readF4le();
      this.covEE = this._io.readF4le();
      this.covED = this._io.readF4le();
      this.covDD = this._io.readF4le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Velocity North coordinate
     */

    /**
     * Velocity East coordinate
     */

    /**
     * Velocity Down coordinate
     */

    /**
     * Estimated variance of northward measurement
     */

    /**
     * Covariance of northward and eastward measurement
     */

    /**
     * Covariance of northward and downward measurement
     */

    /**
     * Estimated variance of eastward measurement
     */

    /**
     * Covariance of eastward and downward measurement
     */

    /**
     * Estimated variance of downward measurement
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgVelNedCov;
  })();

  /**
   * This message reports the Universal Coordinated Time (UTC).  Note the
   * flags which indicate the source of the UTC offset value and source of
   * the time fix.
   */

  var MsgUtcTime = Navigation.MsgUtcTime = (function() {
    function MsgUtcTime(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgUtcTime.prototype._read = function() {
      this.flags = this._io.readU1();
      this.tow = this._io.readU4le();
      this.year = this._io.readU2le();
      this.month = this._io.readU1();
      this.day = this._io.readU1();
      this.hours = this._io.readU1();
      this.minutes = this._io.readU1();
      this.seconds = this._io.readU1();
      this.ns = this._io.readU4le();
    }

    /**
     * Indicates source and time validity
     */

    /**
     * GPS time of week rounded to the nearest millisecond
     */

    /**
     * Year
     */

    /**
     * Month (range 1 .. 12)
     */

    /**
     * days in the month (range 1-31)
     */

    /**
     * hours of day (range 0-23)
     */

    /**
     * minutes of hour (range 0-59)
     */

    /**
     * seconds of minute (range 0-60) rounded down
     */

    /**
     * nanoseconds of second (range 0-999999999)
     */

    return MsgUtcTime;
  })();

  /**
   * The position solution message reports absolute Earth Centered Earth
   * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
   * RTK) of the position solution. The message also reports the upper
   * triangular portion of the 3x3 covariance matrix. If the receiver knows
   * the surveyed position of the base station and has an RTK solution, this
   * reports a pseudo-absolute position solution using the base station
   * position and the rover's RTK baseline vector. The full GPS time is given
   * by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */

  var MsgPosEcefCovGnss = Navigation.MsgPosEcefCovGnss = (function() {
    function MsgPosEcefCovGnss(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgPosEcefCovGnss.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.x = this._io.readF8le();
      this.y = this._io.readF8le();
      this.z = this._io.readF8le();
      this.covXX = this._io.readF4le();
      this.covXY = this._io.readF4le();
      this.covXZ = this._io.readF4le();
      this.covYY = this._io.readF4le();
      this.covYZ = this._io.readF4le();
      this.covZZ = this._io.readF4le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * ECEF X coordinate
     */

    /**
     * ECEF Y coordinate
     */

    /**
     * ECEF Z coordinate
     */

    /**
     * Estimated variance of x
     */

    /**
     * Estimated covariance of x and y
     */

    /**
     * Estimated covariance of x and z
     */

    /**
     * Estimated variance of y
     */

    /**
     * Estimated covariance of y and z
     */

    /**
     * Estimated variance of z
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgPosEcefCovGnss;
  })();

  /**
   * This message reports the velocity in local North East Down (NED)
   * coordinates. The NED coordinate system is defined as the local WGS84
   * tangent plane centered at the current position. The full GPS time is
   * given by the preceding MSG_GPS_TIME with the matching time-of-week
   * (tow).
   */

  var MsgVelNedGnss = Navigation.MsgVelNedGnss = (function() {
    function MsgVelNedGnss(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgVelNedGnss.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.n = this._io.readS4le();
      this.e = this._io.readS4le();
      this.d = this._io.readS4le();
      this.hAccuracy = this._io.readU2le();
      this.vAccuracy = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Velocity North coordinate
     */

    /**
     * Velocity East coordinate
     */

    /**
     * Velocity Down coordinate
     */

    /**
     * Horizontal velocity estimated standard deviation
     */

    /**
     * Vertical velocity estimated standard deviation
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgVelNedGnss;
  })();

  /**
   * This message reports the velocity in local North East Down (NED)
   * coordinates. The NED coordinate system is defined as the local WGS84
   * tangent plane centered at the current position. The full GPS time is
   * given by the preceding MSG_GPS_TIME with the matching time-of-week
   * (tow). This message is similar to the MSG_VEL_NED, but it includes the
   * upper triangular portion of the 3x3 covariance matrix.
   */

  var MsgVelNedCovGnss = Navigation.MsgVelNedCovGnss = (function() {
    function MsgVelNedCovGnss(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgVelNedCovGnss.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.n = this._io.readS4le();
      this.e = this._io.readS4le();
      this.d = this._io.readS4le();
      this.covNN = this._io.readF4le();
      this.covNE = this._io.readF4le();
      this.covND = this._io.readF4le();
      this.covEE = this._io.readF4le();
      this.covED = this._io.readF4le();
      this.covDD = this._io.readF4le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Velocity North coordinate
     */

    /**
     * Velocity East coordinate
     */

    /**
     * Velocity Down coordinate
     */

    /**
     * Estimated variance of northward measurement
     */

    /**
     * Covariance of northward and eastward measurement
     */

    /**
     * Covariance of northward and downward measurement
     */

    /**
     * Estimated variance of eastward measurement
     */

    /**
     * Covariance of eastward and downward measurement
     */

    /**
     * Estimated variance of downward measurement
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgVelNedCovGnss;
  })();

  /**
   * This message reports the baseline solution in North East Down (NED)
   * coordinates. This baseline is the relative vector distance from the base
   * station to the rover receiver, and NED coordinate system is defined at
   * the local WGS84 tangent plane centered at the base station position.
   * The full GPS time is given by the preceding MSG_GPS_TIME with the
   * matching time-of-week (tow).
   */

  var MsgBaselineNedDepA = Navigation.MsgBaselineNedDepA = (function() {
    function MsgBaselineNedDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgBaselineNedDepA.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.n = this._io.readS4le();
      this.e = this._io.readS4le();
      this.d = this._io.readS4le();
      this.hAccuracy = this._io.readU2le();
      this.vAccuracy = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Baseline North coordinate
     */

    /**
     * Baseline East coordinate
     */

    /**
     * Baseline Down coordinate
     */

    /**
     * Horizontal position accuracy estimate (not implemented). Defaults to
     * 0.
     */

    /**
     * Vertical position accuracy estimate (not implemented). Defaults to
     * 0.
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgBaselineNedDepA;
  })();

  /**
   * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
   * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
   * with the matching time-of-week (tow).
   */

  var MsgVelEcefDepA = Navigation.MsgVelEcefDepA = (function() {
    function MsgVelEcefDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgVelEcefDepA.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.x = this._io.readS4le();
      this.y = this._io.readS4le();
      this.z = this._io.readS4le();
      this.accuracy = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Velocity ECEF X coordinate
     */

    /**
     * Velocity ECEF Y coordinate
     */

    /**
     * Velocity ECEF Z coordinate
     */

    /**
     * Velocity accuracy estimate (not implemented). Defaults to 0.
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags (reserved)
     */

    return MsgVelEcefDepA;
  })();

  var MsgReferenceFrameParam = Navigation.MsgReferenceFrameParam = (function() {
    function MsgReferenceFrameParam(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgReferenceFrameParam.prototype._read = function() {
      this.ssrIod = this._io.readU1();
      this.sn = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
      this.tn = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
      this.sin = this._io.readU1();
      this.utn = this._io.readU2le();
      this.reT0 = this._io.readU2le();
      this.deltaX0 = this._io.readS4le();
      this.deltaY0 = this._io.readS4le();
      this.deltaZ0 = this._io.readS4le();
      this.theta01 = this._io.readS4le();
      this.theta02 = this._io.readS4le();
      this.theta03 = this._io.readS4le();
      this.scale = this._io.readS4le();
      this.dotDeltaX0 = this._io.readS4le();
      this.dotDeltaY0 = this._io.readS4le();
      this.dotDeltaZ0 = this._io.readS4le();
      this.dotTheta01 = this._io.readS4le();
      this.dotTheta02 = this._io.readS4le();
      this.dotTheta03 = this._io.readS4le();
      this.dotScale = this._io.readS2le();
    }

    /**
     * SSR IOD parameter.
     */

    /**
     * Name of source coordinate-system.
     */

    /**
     * Name of target coordinate-system.
     */

    /**
     * System Identification Number.
     */

    /**
     * Utilized Transformation Message.
     */

    /**
     * Reference Epoch t0 for transformation parameter set given as
     * Modified Julian Day (MJD) Number minus 44244 days.
     */

    /**
     * Translation in X for Reference Epoch t0.
     */

    /**
     * Translation in Y for Reference Epoch t0.
     */

    /**
     * Translation in Z for Reference Epoch t0.
     */

    /**
     * Rotation around the X-axis for Reference Epoch t0.
     */

    /**
     * Rotation around the Y-axis for Reference Epoch t0.
     */

    /**
     * Rotation around the Z-axis for Reference Epoch t0.
     */

    /**
     * Scale correction for Reference Epoch t0.
     */

    /**
     * Rate of change of translation in X.
     */

    /**
     * Rate of change of translation in Y.
     */

    /**
     * Rate of change of translation in Z.
     */

    /**
     * Rate of change of rotation around the X-axis.
     */

    /**
     * Rate of change of rotation around the Y-axis.
     */

    /**
     * Rate of change of rotation around the Z-axis.
     */

    /**
     * Rate of change of scale correction.
     */

    return MsgReferenceFrameParam;
  })();

  /**
   * This solution message reports the relative pose of a sensor between two
   * time instances. The relative pose comprises of a rotation and a
   * translation which relates the sensor (e.g. camera) frame at a given time
   * (first keyframe) to the sensor frame at another time (second keyframe).
   * The relative translations is a 3x1 vector described in the first
   * keyframe.  Relative rotation is described by a quaternion from second
   * keyframe to the first keyframe.
   */

  var MsgPoseRelative = Navigation.MsgPoseRelative = (function() {
    function MsgPoseRelative(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgPoseRelative.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.sensorId = this._io.readU1();
      this.timestamp1 = this._io.readU4le();
      this.timestamp2 = this._io.readU4le();
      this.trans = [];
      for (var i = 0; i < 3; i++) {
        this.trans.push(this._io.readS4le());
      }
      this.w = this._io.readS4le();
      this.x = this._io.readS4le();
      this.y = this._io.readS4le();
      this.z = this._io.readS4le();
      this.covRXX = this._io.readF4le();
      this.covRXY = this._io.readF4le();
      this.covRXZ = this._io.readF4le();
      this.covRYY = this._io.readF4le();
      this.covRYZ = this._io.readF4le();
      this.covRZZ = this._io.readF4le();
      this.covCXX = this._io.readF4le();
      this.covCXY = this._io.readF4le();
      this.covCXZ = this._io.readF4le();
      this.covCYY = this._io.readF4le();
      this.covCYZ = this._io.readF4le();
      this.covCZZ = this._io.readF4le();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * ID of the sensor producing this message
     */

    /**
     * Timestamp of first keyframe
     */

    /**
     * Timestamp of second keyframe
     */

    /**
     * Relative translation [x,y,z] described in first keyframe
     */

    /**
     * Real component of quaternion to describe relative rotation (second
     * to first keyframe)
     */

    /**
     * 1st imaginary component of quaternion to describe relative rotation
     * (second to first keyframe)
     */

    /**
     * 2nd imaginary component of quaternion to describe relative rotation
     * (second to first keyframe)
     */

    /**
     * 3rd imaginary component of quaternion to describe relative rotation
     * (second to first keyframe)
     */

    /**
     * Estimated variance of x (relative translation)
     */

    /**
     * Covariance of x and y (relative translation)
     */

    /**
     * Covariance of x and z (relative translation)
     */

    /**
     * Estimated variance of y (relative translation)
     */

    /**
     * Covariance of y and z (relative translation)
     */

    /**
     * Estimated variance of z (relative translation)
     */

    /**
     * Estimated variance of x (relative rotation)
     */

    /**
     * Covariance of x and y (relative rotation)
     */

    /**
     * Covariance of x and z (relative rotation)
     */

    /**
     * Estimated variance of y (relative rotation)
     */

    /**
     * Covariance of y and z (relative rotation)
     */

    /**
     * Estimated variance of z (relative rotation)
     */

    /**
     * Status flags of relative translation and rotation
     */

    return MsgPoseRelative;
  })();

  /**
   * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
   * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
   * with the matching time-of-week (tow).
   */

  var MsgVelEcefCov = Navigation.MsgVelEcefCov = (function() {
    function MsgVelEcefCov(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgVelEcefCov.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.x = this._io.readS4le();
      this.y = this._io.readS4le();
      this.z = this._io.readS4le();
      this.covXX = this._io.readF4le();
      this.covXY = this._io.readF4le();
      this.covXZ = this._io.readF4le();
      this.covYY = this._io.readF4le();
      this.covYZ = this._io.readF4le();
      this.covZZ = this._io.readF4le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Velocity ECEF X coordinate
     */

    /**
     * Velocity ECEF Y coordinate
     */

    /**
     * Velocity ECEF Z coordinate
     */

    /**
     * Estimated variance of x
     */

    /**
     * Estimated covariance of x and y
     */

    /**
     * Estimated covariance of x and z
     */

    /**
     * Estimated variance of y
     */

    /**
     * Estimated covariance of y and z
     */

    /**
     * Estimated variance of z
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgVelEcefCov;
  })();

  /**
   * This message reports the velocity in the Vehicle Body Frame. By
   * convention, the x-axis should point out the nose of the vehicle and
   * represent the forward direction, while as the y-axis should point out
   * the right hand side of the vehicle. Since this is a right handed system,
   * z should point out the bottom of the vehicle. The orientation and origin
   * of the Vehicle Body Frame are specified via the device settings. The
   * full GPS time is given by the preceding MSG_GPS_TIME with the matching
   * time-of-week (tow). This message is only produced by inertial versions
   * of Swift products and is not available from Piksi Multi or Duro.
   */

  var MsgVelBody = Navigation.MsgVelBody = (function() {
    function MsgVelBody(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgVelBody.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.x = this._io.readS4le();
      this.y = this._io.readS4le();
      this.z = this._io.readS4le();
      this.covXX = this._io.readF4le();
      this.covXY = this._io.readF4le();
      this.covXZ = this._io.readF4le();
      this.covYY = this._io.readF4le();
      this.covYZ = this._io.readF4le();
      this.covZZ = this._io.readF4le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Velocity in x direction
     */

    /**
     * Velocity in y direction
     */

    /**
     * Velocity in z direction
     */

    /**
     * Estimated variance of x
     */

    /**
     * Covariance of x and y
     */

    /**
     * Covariance of x and z
     */

    /**
     * Estimated variance of y
     */

    /**
     * Covariance of y and z
     */

    /**
     * Estimated variance of z
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgVelBody;
  })();

  /**
   * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
   * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
   * with the matching time-of-week (tow).
   */

  var MsgVelEcefGnss = Navigation.MsgVelEcefGnss = (function() {
    function MsgVelEcefGnss(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgVelEcefGnss.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.x = this._io.readS4le();
      this.y = this._io.readS4le();
      this.z = this._io.readS4le();
      this.accuracy = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Velocity ECEF X coordinate
     */

    /**
     * Velocity ECEF Y coordinate
     */

    /**
     * Velocity ECEF Z coordinate
     */

    /**
     * Velocity estimated standard deviation
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgVelEcefGnss;
  })();

  /**
   * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
   * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
   * with the matching time-of-week (tow).
   */

  var MsgVelEcef = Navigation.MsgVelEcef = (function() {
    function MsgVelEcef(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgVelEcef.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.x = this._io.readS4le();
      this.y = this._io.readS4le();
      this.z = this._io.readS4le();
      this.accuracy = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Velocity ECEF X coordinate
     */

    /**
     * Velocity ECEF Y coordinate
     */

    /**
     * Velocity ECEF Z coordinate
     */

    /**
     * Velocity estimated standard deviation
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgVelEcef;
  })();

  /**
   * This position solution message reports the absolute geodetic coordinates
   * and the status (single point vs pseudo-absolute RTK) of the position
   * solution as well as the upper triangle of the 3x3 covariance matrix.
   * The position information and Fix Mode flags should follow the
   * MSG_POS_LLH message.  Since the covariance matrix is computed in the
   * local-level North, East, Down frame, the covariance terms follow with
   * that convention. Thus, covariances are reported against the "downward"
   * measurement and care should be taken with the sign convention.
   */

  var MsgPosLlhCovGnss = Navigation.MsgPosLlhCovGnss = (function() {
    function MsgPosLlhCovGnss(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgPosLlhCovGnss.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.lat = this._io.readF8le();
      this.lon = this._io.readF8le();
      this.height = this._io.readF8le();
      this.covNN = this._io.readF4le();
      this.covNE = this._io.readF4le();
      this.covND = this._io.readF4le();
      this.covEE = this._io.readF4le();
      this.covED = this._io.readF4le();
      this.covDD = this._io.readF4le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Latitude
     */

    /**
     * Longitude
     */

    /**
     * Height above WGS84 ellipsoid
     */

    /**
     * Estimated variance of northing
     */

    /**
     * Covariance of northing and easting
     */

    /**
     * Covariance of northing and downward measurement
     */

    /**
     * Estimated variance of easting
     */

    /**
     * Covariance of easting and downward measurement
     */

    /**
     * Estimated variance of downward measurement
     */

    /**
     * Number of satellites used in solution.
     */

    /**
     * Status flags
     */

    return MsgPosLlhCovGnss;
  })();

  /**
   * This message reports the baseline solution in Earth Centered Earth Fixed
   * (ECEF) coordinates. This baseline is the relative vector distance from
   * the base station to the rover receiver. The full GPS time is given by
   * the preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */

  var MsgBaselineEcef = Navigation.MsgBaselineEcef = (function() {
    function MsgBaselineEcef(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgBaselineEcef.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.x = this._io.readS4le();
      this.y = this._io.readS4le();
      this.z = this._io.readS4le();
      this.accuracy = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Baseline ECEF X coordinate
     */

    /**
     * Baseline ECEF Y coordinate
     */

    /**
     * Baseline ECEF Z coordinate
     */

    /**
     * Position estimated standard deviation
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgBaselineEcef;
  })();

  /**
   * This dilution of precision (DOP) message describes the effect of
   * navigation satellite geometry on positional measurement precision.
   */

  var MsgDopsDepA = Navigation.MsgDopsDepA = (function() {
    function MsgDopsDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgDopsDepA.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.gdop = this._io.readU2le();
      this.pdop = this._io.readU2le();
      this.tdop = this._io.readU2le();
      this.hdop = this._io.readU2le();
      this.vdop = this._io.readU2le();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Geometric Dilution of Precision
     */

    /**
     * Position Dilution of Precision
     */

    /**
     * Time Dilution of Precision
     */

    /**
     * Horizontal Dilution of Precision
     */

    /**
     * Vertical Dilution of Precision
     */

    return MsgDopsDepA;
  })();

  /**
   * The position solution message reports absolute Earth Centered Earth
   * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
   * RTK) of the position solution. If the rover receiver knows the surveyed
   * position of the base station and has an RTK solution, this reports a
   * pseudo-absolute position solution using the base station position and
   * the rover's RTK baseline vector. The full GPS time is given by the
   * preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */

  var MsgPosEcef = Navigation.MsgPosEcef = (function() {
    function MsgPosEcef(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgPosEcef.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.x = this._io.readF8le();
      this.y = this._io.readF8le();
      this.z = this._io.readF8le();
      this.accuracy = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * ECEF X coordinate
     */

    /**
     * ECEF Y coordinate
     */

    /**
     * ECEF Z coordinate
     */

    /**
     * Position estimated standard deviation
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgPosEcef;
  })();

  /**
   * This message reports the Age of the corrections used for the current
   * Differential solution.
   */

  var MsgAgeCorrections = Navigation.MsgAgeCorrections = (function() {
    function MsgAgeCorrections(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgAgeCorrections.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.age = this._io.readU2le();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Age of the corrections (0xFFFF indicates invalid)
     */

    return MsgAgeCorrections;
  })();

  /**
   * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
   * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
   * with the matching time-of-week (tow).
   */

  var MsgVelEcefCovGnss = Navigation.MsgVelEcefCovGnss = (function() {
    function MsgVelEcefCovGnss(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgVelEcefCovGnss.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.x = this._io.readS4le();
      this.y = this._io.readS4le();
      this.z = this._io.readS4le();
      this.covXX = this._io.readF4le();
      this.covXY = this._io.readF4le();
      this.covXZ = this._io.readF4le();
      this.covYY = this._io.readF4le();
      this.covYZ = this._io.readF4le();
      this.covZZ = this._io.readF4le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Velocity ECEF X coordinate
     */

    /**
     * Velocity ECEF Y coordinate
     */

    /**
     * Velocity ECEF Z coordinate
     */

    /**
     * Estimated variance of x
     */

    /**
     * Estimated covariance of x and y
     */

    /**
     * Estimated covariance of x and z
     */

    /**
     * Estimated variance of y
     */

    /**
     * Estimated covariance of y and z
     */

    /**
     * Estimated variance of z
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgVelEcefCovGnss;
  })();

  /**
   * This message reports the protection levels associated to the given state
   * estimate. The full GPS time is given by the preceding MSG_GPS_TIME with
   * the matching time-of-week (tow).
   */

  var MsgProtectionLevel = Navigation.MsgProtectionLevel = (function() {
    function MsgProtectionLevel(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgProtectionLevel.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.wn = this._io.readS2le();
      this.hpl = this._io.readU2le();
      this.vpl = this._io.readU2le();
      this.atpl = this._io.readU2le();
      this.ctpl = this._io.readU2le();
      this.hvpl = this._io.readU2le();
      this.vvpl = this._io.readU2le();
      this.hopl = this._io.readU2le();
      this.popl = this._io.readU2le();
      this.ropl = this._io.readU2le();
      this.lat = this._io.readF8le();
      this.lon = this._io.readF8le();
      this.height = this._io.readF8le();
      this.vX = this._io.readS4le();
      this.vY = this._io.readS4le();
      this.vZ = this._io.readS4le();
      this.roll = this._io.readS4le();
      this.pitch = this._io.readS4le();
      this.heading = this._io.readS4le();
      this.flags = this._io.readU4le();
    }

    /**
     * GPS Time of Week
     */

    /**
     * GPS week number
     */

    /**
     * Horizontal protection level
     */

    /**
     * Vertical protection level
     */

    /**
     * Along-track position error protection level
     */

    /**
     * Cross-track position error protection level
     */

    /**
     * Protection level for the error vector between estimated and true
     * along/cross track velocity vector
     */

    /**
     * Protection level for the velocity in vehicle upright direction
     * (different from vertical direction if on a slope)
     */

    /**
     * Heading orientation protection level
     */

    /**
     * Pitch orientation protection level
     */

    /**
     * Roll orientation protection level
     */

    /**
     * Latitude
     */

    /**
     * Longitude
     */

    /**
     * Height
     */

    /**
     * Velocity in vehicle x direction
     */

    /**
     * Velocity in vehicle y direction
     */

    /**
     * Velocity in vehicle z direction
     */

    /**
     * Roll angle
     */

    /**
     * Pitch angle
     */

    /**
     * Heading angle
     */

    /**
     * Status flags
     */

    return MsgProtectionLevel;
  })();

  /**
   * The position solution message reports absolute Earth Centered Earth
   * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
   * RTK) of the position solution. The message also reports the upper
   * triangular portion of the 3x3 covariance matrix. If the receiver knows
   * the surveyed position of the base station and has an RTK solution, this
   * reports a pseudo-absolute position solution using the base station
   * position and the rover's RTK baseline vector. The full GPS time is given
   * by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */

  var MsgPosEcefCov = Navigation.MsgPosEcefCov = (function() {
    function MsgPosEcefCov(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgPosEcefCov.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.x = this._io.readF8le();
      this.y = this._io.readF8le();
      this.z = this._io.readF8le();
      this.covXX = this._io.readF4le();
      this.covXY = this._io.readF4le();
      this.covXZ = this._io.readF4le();
      this.covYY = this._io.readF4le();
      this.covYZ = this._io.readF4le();
      this.covZZ = this._io.readF4le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * ECEF X coordinate
     */

    /**
     * ECEF Y coordinate
     */

    /**
     * ECEF Z coordinate
     */

    /**
     * Estimated variance of x
     */

    /**
     * Estimated covariance of x and y
     */

    /**
     * Estimated covariance of x and z
     */

    /**
     * Estimated variance of y
     */

    /**
     * Estimated covariance of y and z
     */

    /**
     * Estimated variance of z
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgPosEcefCov;
  })();

  /**
   * The position solution message reports absolute Earth Centered Earth
   * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
   * RTK) of the position solution. If the rover receiver knows the surveyed
   * position of the base station and has an RTK solution, this reports a
   * pseudo-absolute position solution using the base station position and
   * the rover's RTK baseline vector. The full GPS time is given by the
   * preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */

  var MsgPosEcefGnss = Navigation.MsgPosEcefGnss = (function() {
    function MsgPosEcefGnss(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgPosEcefGnss.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.x = this._io.readF8le();
      this.y = this._io.readF8le();
      this.z = this._io.readF8le();
      this.accuracy = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * ECEF X coordinate
     */

    /**
     * ECEF Y coordinate
     */

    /**
     * ECEF Z coordinate
     */

    /**
     * Position estimated standard deviation
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgPosEcefGnss;
  })();

  /**
   * This message reports the velocity in local North East Down (NED)
   * coordinates. The NED coordinate system is defined as the local WGS84
   * tangent plane centered at the current position. The full GPS time is
   * given by the preceding MSG_GPS_TIME with the matching time-of-week
   * (tow).
   */

  var MsgVelNed = Navigation.MsgVelNed = (function() {
    function MsgVelNed(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgVelNed.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.n = this._io.readS4le();
      this.e = this._io.readS4le();
      this.d = this._io.readS4le();
      this.hAccuracy = this._io.readU2le();
      this.vAccuracy = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Velocity North coordinate
     */

    /**
     * Velocity East coordinate
     */

    /**
     * Velocity Down coordinate
     */

    /**
     * Horizontal velocity estimated standard deviation
     */

    /**
     * Vertical velocity estimated standard deviation
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgVelNed;
  })();

  /**
   * UTC-GPST leap seconds before and after the most recent (past, or future,
   * for announced insertions) UTC leap second insertion.
   */

  var MsgUtcLeapSecond = Navigation.MsgUtcLeapSecond = (function() {
    function MsgUtcLeapSecond(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgUtcLeapSecond.prototype._read = function() {
      this.reserved0 = this._io.readS2le();
      this.reserved1 = this._io.readS2le();
      this.reserved2 = this._io.readS1();
      this.countBefore = this._io.readS1();
      this.reserved3 = this._io.readU2le();
      this.reserved4 = this._io.readU2le();
      this.refWn = this._io.readU2le();
      this.refDn = this._io.readU1();
      this.countAfter = this._io.readS1();
    }

    /**
     * Reserved.
     */

    /**
     * Reserved.
     */

    /**
     * Reserved.
     */

    /**
     * Leap second count before insertion.
     */

    /**
     * Reserved.
     */

    /**
     * Reserved.
     */

    /**
     * Leap second reference GPS week number.
     */

    /**
     * Leap second reference day number.
     */

    /**
     * Leap second count after insertion.
     */

    return MsgUtcLeapSecond;
  })();

  /**
   * This message reports the GPS time, representing the time since the GPS
   * epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
   * and seconds of the week. The weeks begin at the Saturday/Sunday
   * transition. GPS week 0 began at the beginning of the GPS time scale.
   * 
   * Within each week number, the GPS time of the week is between between 0
   * and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
   * leap seconds, and as of now, has a small offset from UTC. In a message
   * stream, this message precedes a set of other navigation messages
   * referenced to the same time (but lacking the ns field) and indicates a
   * more precise time of these messages.
   */

  var MsgGpsTimeDepA = Navigation.MsgGpsTimeDepA = (function() {
    function MsgGpsTimeDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgGpsTimeDepA.prototype._read = function() {
      this.wn = this._io.readU2le();
      this.tow = this._io.readU4le();
      this.nsResidual = this._io.readS4le();
      this.flags = this._io.readU1();
    }

    /**
     * GPS week number
     */

    /**
     * GPS time of week rounded to the nearest millisecond
     */

    /**
     * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
     * to 500000)
     */

    /**
     * Status flags (reserved)
     */

    return MsgGpsTimeDepA;
  })();

  /**
   * This position solution message reports the absolute geodetic coordinates
   * and the status (single point vs pseudo-absolute RTK) of the position
   * solution. If the rover receiver knows the surveyed position of the base
   * station and has an RTK solution, this reports a pseudo-absolute position
   * solution using the base station position and the rover's RTK baseline
   * vector. The full GPS time is given by the preceding MSG_GPS_TIME with
   * the matching time-of-week (tow).
   */

  var MsgPosLlhGnss = Navigation.MsgPosLlhGnss = (function() {
    function MsgPosLlhGnss(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgPosLlhGnss.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.lat = this._io.readF8le();
      this.lon = this._io.readF8le();
      this.height = this._io.readF8le();
      this.hAccuracy = this._io.readU2le();
      this.vAccuracy = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Latitude
     */

    /**
     * Longitude
     */

    /**
     * Height above WGS84 ellipsoid
     */

    /**
     * Horizontal position estimated standard deviation
     */

    /**
     * Vertical position estimated standard deviation
     */

    /**
     * Number of satellites used in solution.
     */

    /**
     * Status flags
     */

    return MsgPosLlhGnss;
  })();

  /**
   * This message reports the Universal Coordinated Time (UTC).  Note the
   * flags which indicate the source of the UTC offset value and source of
   * the time fix.
   */

  var MsgUtcTimeGnss = Navigation.MsgUtcTimeGnss = (function() {
    function MsgUtcTimeGnss(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgUtcTimeGnss.prototype._read = function() {
      this.flags = this._io.readU1();
      this.tow = this._io.readU4le();
      this.year = this._io.readU2le();
      this.month = this._io.readU1();
      this.day = this._io.readU1();
      this.hours = this._io.readU1();
      this.minutes = this._io.readU1();
      this.seconds = this._io.readU1();
      this.ns = this._io.readU4le();
    }

    /**
     * Indicates source and time validity
     */

    /**
     * GPS time of week rounded to the nearest millisecond
     */

    /**
     * Year
     */

    /**
     * Month (range 1 .. 12)
     */

    /**
     * days in the month (range 1-31)
     */

    /**
     * hours of day (range 0-23)
     */

    /**
     * minutes of hour (range 0-59)
     */

    /**
     * seconds of minute (range 0-60) rounded down
     */

    /**
     * nanoseconds of second (range 0-999999999)
     */

    return MsgUtcTimeGnss;
  })();

  /**
   * This message reports the receiver course over ground (COG) and speed
   * over  ground (SOG) based on the horizontal (N-E) components of the NED
   * velocity  vector. It also includes the vertical velocity coordinate. A
   * flag is provided to indicate whether the COG value has been frozen. When
   * the flag is set to true, the COG field is set to its last valid value
   * until  the system exceeds a minimum velocity threshold. No other fields
   * are  affected by this flag.  The NED coordinate system is defined as the
   * local WGS84 tangent  plane centered at the current position. The full
   * GPS time is given by the  preceding MSG_GPS_TIME with the matching time-
   * of-week (tow). Note: course over ground represents the receiver's
   * direction of travel,  but not necessarily the device heading.
   */

  var MsgVelCog = Navigation.MsgVelCog = (function() {
    function MsgVelCog(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgVelCog.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.cog = this._io.readU4le();
      this.sog = this._io.readU4le();
      this.vUp = this._io.readS4le();
      this.cogAccuracy = this._io.readU4le();
      this.sogAccuracy = this._io.readU4le();
      this.vUpAccuracy = this._io.readU4le();
      this.flags = this._io.readU2le();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Course over ground relative to north direction
     */

    /**
     * Speed over ground (based on horizontal velocity)
     */

    /**
     * Vertical velocity component (positive up)
     */

    /**
     * Course over ground estimated standard deviation
     */

    /**
     * Speed over ground estimated standard deviation
     */

    /**
     * Vertical velocity estimated standard deviation
     */

    /**
     * Status flags
     */

    return MsgVelCog;
  })();

  /**
   * This message reports the baseline solution in North East Down (NED)
   * coordinates. This baseline is the relative vector distance from the base
   * station to the rover receiver, and NED coordinate system is defined at
   * the local WGS84 tangent plane centered at the base station position.
   * The full GPS time is given by the preceding MSG_GPS_TIME with the
   * matching time-of-week (tow).
   */

  var MsgBaselineNed = Navigation.MsgBaselineNed = (function() {
    function MsgBaselineNed(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgBaselineNed.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.n = this._io.readS4le();
      this.e = this._io.readS4le();
      this.d = this._io.readS4le();
      this.hAccuracy = this._io.readU2le();
      this.vAccuracy = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Baseline North coordinate
     */

    /**
     * Baseline East coordinate
     */

    /**
     * Baseline Down coordinate
     */

    /**
     * Horizontal position estimated standard deviation
     */

    /**
     * Vertical position estimated standard deviation
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgBaselineNed;
  })();

  /**
   * This position solution message reports the absolute geodetic coordinates
   * and the status (single point vs pseudo-absolute RTK) of the position
   * solution. If the rover receiver knows the surveyed position of the base
   * station and has an RTK solution, this reports a pseudo-absolute position
   * solution using the base station position and the rover's RTK baseline
   * vector. The full GPS time is given by the preceding MSG_GPS_TIME with
   * the matching time-of-week (tow).
   */

  var MsgPosLlh = Navigation.MsgPosLlh = (function() {
    function MsgPosLlh(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgPosLlh.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.lat = this._io.readF8le();
      this.lon = this._io.readF8le();
      this.height = this._io.readF8le();
      this.hAccuracy = this._io.readU2le();
      this.vAccuracy = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Latitude
     */

    /**
     * Longitude
     */

    /**
     * Height above WGS84 ellipsoid
     */

    /**
     * Horizontal position estimated standard deviation
     */

    /**
     * Vertical position estimated standard deviation
     */

    /**
     * Number of satellites used in solution.
     */

    /**
     * Status flags
     */

    return MsgPosLlh;
  })();

  /**
   * This message reports the baseline heading pointing from the base station
   * to the rover relative to True North. The full GPS time is given by the
   * preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */

  var MsgBaselineHeadingDepA = Navigation.MsgBaselineHeadingDepA = (function() {
    function MsgBaselineHeadingDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgBaselineHeadingDepA.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.heading = this._io.readU4le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Heading
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgBaselineHeadingDepA;
  })();

  /**
   * This message reports the GPS time, representing the time since the GPS
   * epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
   * and seconds of the week. The weeks begin at the Saturday/Sunday
   * transition. GPS week 0 began at the beginning of the GPS time scale.
   * 
   * Within each week number, the GPS time of the week is between between 0
   * and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
   * leap seconds, and as of now, has a small offset from UTC. In a message
   * stream, this message precedes a set of other navigation messages
   * referenced to the same time (but lacking the ns field) and indicates a
   * more precise time of these messages.
   */

  var MsgGpsTimeGnss = Navigation.MsgGpsTimeGnss = (function() {
    function MsgGpsTimeGnss(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgGpsTimeGnss.prototype._read = function() {
      this.wn = this._io.readU2le();
      this.tow = this._io.readU4le();
      this.nsResidual = this._io.readS4le();
      this.flags = this._io.readU1();
    }

    /**
     * GPS week number
     */

    /**
     * GPS time of week rounded to the nearest millisecond
     */

    /**
     * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
     * to 500000)
     */

    /**
     * Status flags (reserved)
     */

    return MsgGpsTimeGnss;
  })();

  /**
   * This message reports the baseline solution in Earth Centered Earth Fixed
   * (ECEF) coordinates. This baseline is the relative vector distance from
   * the base station to the rover receiver. The full GPS time is given by
   * the preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */

  var MsgBaselineEcefDepA = Navigation.MsgBaselineEcefDepA = (function() {
    function MsgBaselineEcefDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgBaselineEcefDepA.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.x = this._io.readS4le();
      this.y = this._io.readS4le();
      this.z = this._io.readS4le();
      this.accuracy = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Baseline ECEF X coordinate
     */

    /**
     * Baseline ECEF Y coordinate
     */

    /**
     * Baseline ECEF Z coordinate
     */

    /**
     * Position accuracy estimate
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgBaselineEcefDepA;
  })();

  /**
   * This message reports the GPS time, representing the time since the GPS
   * epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
   * and seconds of the week. The weeks begin at the Saturday/Sunday
   * transition. GPS week 0 began at the beginning of the GPS time scale.
   * 
   * Within each week number, the GPS time of the week is between between 0
   * and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
   * leap seconds, and as of now, has a small offset from UTC. In a message
   * stream, this message precedes a set of other navigation messages
   * referenced to the same time (but lacking the ns field) and indicates a
   * more precise time of these messages.
   */

  var MsgGpsTime = Navigation.MsgGpsTime = (function() {
    function MsgGpsTime(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgGpsTime.prototype._read = function() {
      this.wn = this._io.readU2le();
      this.tow = this._io.readU4le();
      this.nsResidual = this._io.readS4le();
      this.flags = this._io.readU1();
    }

    /**
     * GPS week number
     */

    /**
     * GPS time of week rounded to the nearest millisecond
     */

    /**
     * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
     * to 500000)
     */

    /**
     * Status flags (reserved)
     */

    return MsgGpsTime;
  })();

  /**
   * This dilution of precision (DOP) message describes the effect of
   * navigation satellite geometry on positional measurement precision.  The
   * flags field indicated whether the DOP reported corresponds to
   * differential or SPP solution.
   */

  var MsgDops = Navigation.MsgDops = (function() {
    function MsgDops(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgDops.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.gdop = this._io.readU2le();
      this.pdop = this._io.readU2le();
      this.tdop = this._io.readU2le();
      this.hdop = this._io.readU2le();
      this.vdop = this._io.readU2le();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Geometric Dilution of Precision
     */

    /**
     * Position Dilution of Precision
     */

    /**
     * Time Dilution of Precision
     */

    /**
     * Horizontal Dilution of Precision
     */

    /**
     * Vertical Dilution of Precision
     */

    /**
     * Indicates the position solution with which the DOPS message
     * corresponds
     */

    return MsgDops;
  })();

  /**
   * The position solution message reports absolute Earth Centered Earth
   * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
   * RTK) of the position solution. If the rover receiver knows the surveyed
   * position of the base station and has an RTK solution, this reports a
   * pseudo-absolute position solution using the base station position and
   * the rover's RTK baseline vector. The full GPS time is given by the
   * preceding MSG_GPS_TIME with the matching time-of-week (tow).
   */

  var MsgPosEcefDepA = Navigation.MsgPosEcefDepA = (function() {
    function MsgPosEcefDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgPosEcefDepA.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.x = this._io.readF8le();
      this.y = this._io.readF8le();
      this.z = this._io.readF8le();
      this.accuracy = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * ECEF X coordinate
     */

    /**
     * ECEF Y coordinate
     */

    /**
     * ECEF Z coordinate
     */

    /**
     * Position accuracy estimate (not implemented). Defaults to 0.
     */

    /**
     * Number of satellites used in solution
     */

    /**
     * Status flags
     */

    return MsgPosEcefDepA;
  })();

  var EstimatedHorizontalErrorEllipse = Navigation.EstimatedHorizontalErrorEllipse = (function() {
    function EstimatedHorizontalErrorEllipse(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    EstimatedHorizontalErrorEllipse.prototype._read = function() {
      this.semiMajor = this._io.readF4le();
      this.semiMinor = this._io.readF4le();
      this.orientation = this._io.readF4le();
    }

    /**
     * The semi major axis of the estimated horizontal error ellipse at the
     * user-configured confidence level; zero implies invalid.
     */

    /**
     * The semi minor axis of the estimated horizontal error ellipse at the
     * user-configured confidence level; zero implies invalid.
     */

    /**
     * The orientation of the semi major axis of the estimated horizontal
     * error ellipse with respect to North.
     */

    return EstimatedHorizontalErrorEllipse;
  })();

  /**
   * This position solution message reports the absolute geodetic coordinates
   * and the status (single point vs pseudo-absolute RTK) of the position
   * solution as well as the estimated horizontal, vertical, cross-track and
   * along-track errors.  The position information and Fix Mode flags  follow
   * the MSG_POS_LLH message. Since the covariance matrix is computed in the
   * local-level North, East, Down frame, the estimated error terms follow
   * that convention.
   * 
   * The estimated errors are reported at a user-configurable confidence
   * level. The user-configured percentile is encoded in the percentile
   * field.
   */

  var MsgPosLlhAcc = Navigation.MsgPosLlhAcc = (function() {
    function MsgPosLlhAcc(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgPosLlhAcc.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.lat = this._io.readF8le();
      this.lon = this._io.readF8le();
      this.height = this._io.readF8le();
      this.orthometricHeight = this._io.readF8le();
      this.hAccuracy = this._io.readF4le();
      this.vAccuracy = this._io.readF4le();
      this.ctAccuracy = this._io.readF4le();
      this.atAccuracy = this._io.readF4le();
      this.hEllipse = new EstimatedHorizontalErrorEllipse(this._io, this, this._root);
      this.confidenceAndGeoid = this._io.readU1();
      this.nSats = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Latitude
     */

    /**
     * Longitude
     */

    /**
     * Height above WGS84 ellipsoid
     */

    /**
     * Height above the geoid (i.e. height above mean sea level). See
     * confidence_and_geoid for geoid model used.
     */

    /**
     * Estimated horizontal error at the user-configured confidence level;
     * zero implies invalid.
     */

    /**
     * Estimated vertical error at the user-configured confidence level;
     * zero implies invalid.
     */

    /**
     * Estimated cross-track error at the user-configured confidence level;
     * zero implies invalid.
     */

    /**
     * Estimated along-track error at the user-configured confidence level;
     * zero implies invalid.
     */

    /**
     * The estimated horizontal error ellipse at the user-configured
     * confidence level.
     */

    /**
     * The lower bits describe the configured confidence level for the
     * estimated position error. The middle bits describe the geoid model
     * used to calculate the orthometric height.
     */

    /**
     * Number of satellites used in solution.
     */

    /**
     * Status flags
     */

    return MsgPosLlhAcc;
  })();

  return Navigation;
})();
return Navigation;
}));
