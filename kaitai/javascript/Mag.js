// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Mag = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Mag = (function() {
  function Mag(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Mag.prototype._read = function() {
  }

  /**
   * Raw data from the magnetometer.
   */

  var MsgMagRaw = Mag.MsgMagRaw = (function() {
    function MsgMagRaw(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgMagRaw.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.towF = this._io.readU1();
      this.magX = this._io.readS2le();
      this.magY = this._io.readS2le();
      this.magZ = this._io.readS2le();
    }

    /**
     * Milliseconds since start of GPS week. If the high bit is set, the
     * time is unknown or invalid.
     */

    /**
     * Milliseconds since start of GPS week, fractional part
     */

    /**
     * Magnetic field in the body frame X axis
     */

    /**
     * Magnetic field in the body frame Y axis
     */

    /**
     * Magnetic field in the body frame Z axis
     */

    return MsgMagRaw;
  })();

  return Mag;
})();
return Mag;
}));
