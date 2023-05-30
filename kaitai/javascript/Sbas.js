// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Sbas = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Sbas = (function() {
  function Sbas(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Sbas.prototype._read = function() {
  }

  /**
   * This message is sent once per second per SBAS satellite. ME checks the
   * parity of the data block and sends only blocks that pass the check.
   */

  var MsgSbasRaw = Sbas.MsgSbasRaw = (function() {
    function MsgSbasRaw(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSbasRaw.prototype._read = function() {
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.tow = this._io.readU4le();
      this.messageType = this._io.readU1();
      this.data = [];
      for (var i = 0; i < 27; i++) {
        this.data.push(this._io.readU1());
      }
    }

    /**
     * GNSS signal identifier.
     */

    /**
     * GPS time-of-week at the start of the data block.
     */

    /**
     * SBAS message type (0-63)
     */

    /**
     * Raw SBAS data field of 212 bits (last byte padded with zeros).
     */

    return MsgSbasRaw;
  })();

  return Sbas;
})();
return Sbas;
}));
