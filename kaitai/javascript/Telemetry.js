// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Telemetry = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Telemetry = (function() {
  function Telemetry(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Telemetry.prototype._read = function() {
  }

  var TelemetrySv = Telemetry.TelemetrySv = (function() {
    function TelemetrySv(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    TelemetrySv.prototype._read = function() {
      this.az = this._io.readU1();
      this.el = this._io.readS1();
      this.availabilityFlags = this._io.readU1();
      this.pseudorangeResidual = this._io.readS2le();
      this.phaseResidual = this._io.readS2le();
      this.outlierFlags = this._io.readU1();
      this.ephemerisFlags = this._io.readU1();
      this.correctionFlags = this._io.readU1();
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
    }

    /**
     * Azimuth angle (range 0..179)
     */

    /**
     * Elevation angle (range -90..90)
     */

    /**
     * Observation availability at filter update
     */

    /**
     * Pseudorange observation residual
     */

    /**
     * Carrier-phase or carrier-phase-derived observation residual
     */

    /**
     * Reports if observation is marked as an outlier and is excluded from
     * the update
     */

    /**
     * Ephemeris metadata
     */

    /**
     * Reserved
     */

    /**
     * GNSS signal identifier (16 bit)
     */

    return TelemetrySv;
  })();

  /**
   * This message includes telemetry pertinent to satellite signals available
   * to Starling.
   */

  var MsgTelSv = Telemetry.MsgTelSv = (function() {
    function MsgTelSv(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgTelSv.prototype._read = function() {
      this.wn = this._io.readU2le();
      this.tow = this._io.readU4le();
      this.nObs = this._io.readU1();
      this.originFlags = this._io.readU1();
      this.svTel = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.svTel.push(new TelemetrySv(this._io, this, this._root));
        i++;
      }
    }

    /**
     * GPS week number
     */

    /**
     * GPS Time of Week
     */

    /**
     * Total number of observations. First nibble is the size of the
     * sequence (n), second nibble is the zero-indexed counter (ith packet
     * of n)
     */

    /**
     * Flags to identify the filter type from which the telemetry is
     * reported from
     */

    /**
     * Array of per-signal telemetry entries
     */

    return MsgTelSv;
  })();

  return Telemetry;
})();
return Telemetry;
}));
