// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Vehicle = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Vehicle = (function() {
  function Vehicle(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Vehicle.prototype._read = function() {
  }

  /**
   * Message representing the x component of vehicle velocity in the user
   * frame at the odometry reference point(s) specified by the user. The
   * offset for the odometry reference point and the definition and origin of
   * the user frame are defined through the device settings interface. There
   * are 4 possible user-defined sources of this message which are labeled
   * arbitrarily source 0 through 3. If using "processor time" time tags, the
   * receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix
   * becomes available to synchronise odometry measurements with GNSS.
   * Processor time shall roll over to zero after one week.
   */

  var MsgOdometry = Vehicle.MsgOdometry = (function() {
    function MsgOdometry(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgOdometry.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.velocity = this._io.readS4le();
      this.flags = this._io.readU1();
    }

    /**
     * Time field representing either milliseconds in the GPS Week or local
     * CPU time from the producing system in milliseconds.  See the
     * tow_source flag for the exact source of this timestamp.
     */

    /**
     * The signed forward component of vehicle velocity.
     */

    /**
     * Status flags
     */

    return MsgOdometry;
  })();

  /**
   * Message containing the accumulated distance travelled by a wheel located
   * at an odometry reference point defined by the user. The offset for the
   * odometry reference point and the definition and origin of the user frame
   * are defined through the device settings interface. The source of this
   * message is identified by the source field, which is an integer ranging
   * from 0 to 255. The timestamp associated with this message should
   * represent the time when the accumulated tick count reached the value
   * given by the contents of this message as accurately as possible. If
   * using "local CPU time" time tags, the receiving end will expect a
   * `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to synchronise
   * wheeltick measurements with GNSS. Local CPU time shall roll over to zero
   * after one week.
   */

  var MsgWheeltick = Vehicle.MsgWheeltick = (function() {
    function MsgWheeltick(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgWheeltick.prototype._read = function() {
      this.time = this._io.readU8le();
      this.flags = this._io.readU1();
      this.source = this._io.readU1();
      this.ticks = this._io.readS4le();
    }

    /**
     * Time field representing either microseconds since the last PPS,
     * microseconds in the GPS Week or local CPU time from the producing
     * system in microseconds. See the synch_type field for the exact
     * meaning of this timestamp.
     */

    /**
     * Field indicating the type of timestamp contained in the time field.
     */

    /**
     * ID of the sensor producing this message
     */

    /**
     * Free-running counter of the accumulated distance for this sensor.
     * The counter should be incrementing if travelling into one direction
     * and decrementing when travelling in the opposite direction.
     */

    return MsgWheeltick;
  })();

  return Vehicle;
})();
return Vehicle;
}));
