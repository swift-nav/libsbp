// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Orientation = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Orientation = (function() {
  function Orientation(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Orientation.prototype._read = function() {
  }

  /**
   * This message reports the baseline heading pointing from the base station
   * to the rover relative to True North. The full GPS time is given by the
   * preceding MSG_GPS_TIME with the matching time-of-week (tow). It is
   * intended that time-matched RTK mode is used when the base station is
   * moving.
   */

  var MsgBaselineHeading = Orientation.MsgBaselineHeading = (function() {
    function MsgBaselineHeading(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgBaselineHeading.prototype._read = function() {
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

    return MsgBaselineHeading;
  })();

  /**
   * This message reports the quaternion vector describing the vehicle body
   * frame's orientation with respect to a local-level NED frame. The
   * components of the vector should sum to a unit vector assuming that the
   * LSB of each component as a value of 2^-31. This message will only be
   * available in future INS versions of Swift Products and is not produced
   * by Piksi Multi or Duro.
   */

  var MsgOrientQuat = Orientation.MsgOrientQuat = (function() {
    function MsgOrientQuat(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgOrientQuat.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.w = this._io.readS4le();
      this.x = this._io.readS4le();
      this.y = this._io.readS4le();
      this.z = this._io.readS4le();
      this.wAccuracy = this._io.readF4le();
      this.xAccuracy = this._io.readF4le();
      this.yAccuracy = this._io.readF4le();
      this.zAccuracy = this._io.readF4le();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * Real component
     */

    /**
     * 1st imaginary component
     */

    /**
     * 2nd imaginary component
     */

    /**
     * 3rd imaginary component
     */

    /**
     * Estimated standard deviation of w
     */

    /**
     * Estimated standard deviation of x
     */

    /**
     * Estimated standard deviation of y
     */

    /**
     * Estimated standard deviation of z
     */

    /**
     * Status flags
     */

    return MsgOrientQuat;
  })();

  /**
   * This message reports the yaw, pitch, and roll angles of the vehicle body
   * frame. The rotations should applied intrinsically in the order yaw,
   * pitch, and roll in order to rotate the from a frame aligned with the
   * local-level NED frame to the vehicle body frame.  This message will only
   * be available in future INS versions of Swift Products and is not
   * produced by Piksi Multi or Duro.
   */

  var MsgOrientEuler = Orientation.MsgOrientEuler = (function() {
    function MsgOrientEuler(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgOrientEuler.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.roll = this._io.readS4le();
      this.pitch = this._io.readS4le();
      this.yaw = this._io.readS4le();
      this.rollAccuracy = this._io.readF4le();
      this.pitchAccuracy = this._io.readF4le();
      this.yawAccuracy = this._io.readF4le();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * rotation about the forward axis of the vehicle
     */

    /**
     * rotation about the rightward axis of the vehicle
     */

    /**
     * rotation about the downward axis of the vehicle
     */

    /**
     * Estimated standard deviation of roll
     */

    /**
     * Estimated standard deviation of pitch
     */

    /**
     * Estimated standard deviation of yaw
     */

    /**
     * Status flags
     */

    return MsgOrientEuler;
  })();

  /**
   * This message reports the orientation rates in the vehicle body frame.
   * The values represent the measurements a strapped down gyroscope would
   * make and are not equivalent to the time derivative of the Euler angles.
   * The orientation and origin of the user frame is specified via device
   * settings. By convention, the vehicle x-axis is expected to be aligned
   * with the forward direction, while the vehicle y-axis is expected to be
   * aligned with the right direction, and the vehicle z-axis should be
   * aligned with the down direction. This message will only be available in
   * future INS versions of Swift Products and is not produced by Piksi Multi
   * or Duro.
   */

  var MsgAngularRate = Orientation.MsgAngularRate = (function() {
    function MsgAngularRate(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgAngularRate.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.x = this._io.readS4le();
      this.y = this._io.readS4le();
      this.z = this._io.readS4le();
      this.flags = this._io.readU1();
    }

    /**
     * GPS Time of Week
     */

    /**
     * angular rate about x axis
     */

    /**
     * angular rate about y axis
     */

    /**
     * angular rate about z axis
     */

    /**
     * Status flags
     */

    return MsgAngularRate;
  })();

  return Orientation;
})();
return Orientation;
}));
