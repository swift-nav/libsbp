// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.ExtEvents = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var ExtEvents = (function() {
  function ExtEvents(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  ExtEvents.prototype._read = function() {
  }

  /**
   * Reports detection of an external event, the GPS time it occurred, which
   * pin it was and whether it was rising or falling.
   */

  var MsgExtEvent = ExtEvents.MsgExtEvent = (function() {
    function MsgExtEvent(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgExtEvent.prototype._read = function() {
      this.wn = this._io.readU2le();
      this.tow = this._io.readU4le();
      this.nsResidual = this._io.readS4le();
      this.flags = this._io.readU1();
      this.pin = this._io.readU1();
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
     * Flags
     */

    /**
     * Pin number.  0..9 = DEBUG0..9.
     */

    return MsgExtEvent;
  })();

  return ExtEvents;
})();
return ExtEvents;
}));
