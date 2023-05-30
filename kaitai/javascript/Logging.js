// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Logging = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Logging = (function() {
  function Logging(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Logging.prototype._read = function() {
  }

  /**
   * This message contains a human-readable payload string from the device
   * containing errors, warnings and informational messages at ERROR,
   * WARNING, DEBUG, INFO logging levels.
   */

  var MsgLog = Logging.MsgLog = (function() {
    function MsgLog(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgLog.prototype._read = function() {
      this.level = this._io.readU1();
      this.text = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * Logging level
     */

    /**
     * Human-readable string
     */

    return MsgLog;
  })();

  /**
   * This message provides the ability to forward messages over SBP.  This
   * may take the form of wrapping up SBP messages received by Piksi for
   * logging purposes or wrapping another protocol with SBP.
   * 
   * The source identifier indicates from what interface a forwarded stream
   * derived. The protocol identifier identifies what the expected protocol
   * the forwarded msg contains. Protocol 0 represents SBP and the remaining
   * values are implementation defined.
   */

  var MsgFwd = Logging.MsgFwd = (function() {
    function MsgFwd(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgFwd.prototype._read = function() {
      this.source = this._io.readU1();
      this.protocol = this._io.readU1();
      this.fwdPayload = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.fwdPayload.push(this._io.readU1());
        i++;
      }
    }

    /**
     * source identifier
     */

    /**
     * protocol identifier
     */

    /**
     * variable length wrapped binary message
     */

    return MsgFwd;
  })();

  /**
   * Deprecated.
   */

  var MsgPrintDep = Logging.MsgPrintDep = (function() {
    function MsgPrintDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgPrintDep.prototype._read = function() {
      this.text = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * Human-readable string
     */

    return MsgPrintDep;
  })();

  return Logging;
})();
return Logging;
}));
