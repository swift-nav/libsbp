// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Imu = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Imu = (function() {
  function Imu(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Imu.prototype._read = function() {
  }

  /**
   * Raw data from the Inertial Measurement Unit, containing accelerometer
   * and gyroscope readings. The sense of the measurements are to be aligned
   * with the indications on the device itself. Measurement units, which are
   * specific to the device hardware and settings, are communicated via the
   * MSG_IMU_AUX message. If using "time since startup" time tags, the
   * receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix
   * becomes available to synchronise IMU measurements with GNSS. The
   * timestamp must wrap around to zero when reaching one week (604800
   * seconds).
   * 
   * The time-tagging mode should not change throughout a run.
   */

  var MsgImuRaw = Imu.MsgImuRaw = (function() {
    function MsgImuRaw(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgImuRaw.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.towF = this._io.readU1();
      this.accX = this._io.readS2le();
      this.accY = this._io.readS2le();
      this.accZ = this._io.readS2le();
      this.gyrX = this._io.readS2le();
      this.gyrY = this._io.readS2le();
      this.gyrZ = this._io.readS2le();
    }

    /**
     * Milliseconds since reference epoch and time status.
     */

    /**
     * Milliseconds since reference epoch, fractional part
     */

    /**
     * Acceleration in the IMU frame X axis
     */

    /**
     * Acceleration in the IMU frame Y axis
     */

    /**
     * Acceleration in the IMU frame Z axis
     */

    /**
     * Angular rate around IMU frame X axis
     */

    /**
     * Angular rate around IMU frame Y axis
     */

    /**
     * Angular rate around IMU frame Z axis
     */

    return MsgImuRaw;
  })();

  /**
   * Auxiliary data specific to a particular IMU. The `imu_type` field will
   * always be consistent but the rest of the payload is device specific and
   * depends on the value of `imu_type`.
   */

  var MsgImuAux = Imu.MsgImuAux = (function() {
    function MsgImuAux(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgImuAux.prototype._read = function() {
      this.imuType = this._io.readU1();
      this.temp = this._io.readS2le();
      this.imuConf = this._io.readU1();
    }

    /**
     * IMU type
     */

    /**
     * Raw IMU temperature
     */

    /**
     * IMU configuration
     */

    return MsgImuAux;
  })();

  return Imu;
})();
return Imu;
}));
