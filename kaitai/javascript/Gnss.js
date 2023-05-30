// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Gnss = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Gnss = (function() {
  function Gnss(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Gnss.prototype._read = function() {
  }

  /**
   * Deprecated.
   */

  var GnssSignalDep = Gnss.GnssSignalDep = (function() {
    function GnssSignalDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    GnssSignalDep.prototype._read = function() {
      this.sat = this._io.readU2le();
      this.code = this._io.readU1();
      this.reserved = this._io.readU1();
    }

    /**
     * Constellation-specific satellite identifier.
     * 
     * Note: unlike GnssSignal, GPS satellites are encoded as (PRN - 1).
     * Other constellations do not have this offset.
     */

    /**
     * Signal constellation, band and code
     */

    /**
     * Reserved
     */

    return GnssSignalDep;
  })();

  /**
   * Carrier phase measurement in cycles represented as a 40-bit fixed point
   * number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
   * fractional cycles. This phase has the same sign as the pseudorange.
   */

  var CarrierPhase = Gnss.CarrierPhase = (function() {
    function CarrierPhase(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    CarrierPhase.prototype._read = function() {
      this.i = this._io.readS4le();
      this.f = this._io.readU1();
    }

    /**
     * Carrier phase whole cycles
     */

    /**
     * Carrier phase fractional part
     */

    return CarrierPhase;
  })();

  /**
   * A wire-appropriate GPS time, defined as the number of milliseconds since
   * beginning of the week on the Saturday/Sunday transition.
   */

  var GpsTimeDep = Gnss.GpsTimeDep = (function() {
    function GpsTimeDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    GpsTimeDep.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.wn = this._io.readU2le();
    }

    /**
     * Milliseconds since start of GPS week
     */

    /**
     * GPS week number
     */

    return GpsTimeDep;
  })();

  /**
   * Signal identifier containing constellation, band, and satellite
   * identifier.
   */

  var GnssSignal = Gnss.GnssSignal = (function() {
    function GnssSignal(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    GnssSignal.prototype._read = function() {
      this.sat = this._io.readU1();
      this.code = this._io.readU1();
    }

    /**
     * Constellation-specific satellite id. For GLO can either be (100+FCN)
     * where FCN is in [-7,+6] or the Slot ID in [1,28].
     */

    /**
     * Signal constellation, band and code
     */

    return GnssSignal;
  })();

  /**
   * A wire-appropriate receiver clock time, defined as the time since the
   * beginning of the week on the Saturday/Sunday transition. In most cases,
   * observations are epoch aligned so ns field will be 0.
   */

  var GpsTime = Gnss.GpsTime = (function() {
    function GpsTime(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    GpsTime.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.nsResidual = this._io.readS4le();
      this.wn = this._io.readU2le();
    }

    /**
     * Milliseconds since start of GPS week
     */

    /**
     * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
     * to 500000)
     */

    /**
     * GPS week number
     */

    return GpsTime;
  })();

  /**
   * A GPS time, defined as the number of seconds since beginning of the week
   * on the Saturday/Sunday transition.
   */

  var GpsTimeSec = Gnss.GpsTimeSec = (function() {
    function GpsTimeSec(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    GpsTimeSec.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.wn = this._io.readU2le();
    }

    /**
     * Seconds since start of GPS week
     */

    /**
     * GPS week number
     */

    return GpsTimeSec;
  })();

  /**
   * A (Constellation ID, satellite ID) tuple that uniquely identifies a
   * space vehicle.
   */

  var SvId = Gnss.SvId = (function() {
    function SvId(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    SvId.prototype._read = function() {
      this.satId = this._io.readU1();
      this.constellation = this._io.readU1();
    }

    /**
     * Constellation-specific satellite id. For GLO can either be (100+FCN)
     * where FCN is in [-7,+6] or the Slot ID in [1,28].
     */

    /**
     * Constellation ID to which the SV belongs
     */

    return SvId;
  })();

  return Gnss;
})();
return Gnss;
}));
