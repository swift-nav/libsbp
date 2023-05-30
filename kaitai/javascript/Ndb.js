// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Ndb = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Ndb = (function() {
  function Ndb(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Ndb.prototype._read = function() {
  }

  /**
   * This message is sent out when an object is stored into NDB. If needed
   * message could also be sent out when fetching an object from NDB.
   */

  var MsgNdbEvent = Ndb.MsgNdbEvent = (function() {
    function MsgNdbEvent(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgNdbEvent.prototype._read = function() {
      this.recvTime = this._io.readU8le();
      this.event = this._io.readU1();
      this.objectType = this._io.readU1();
      this.result = this._io.readU1();
      this.dataSource = this._io.readU1();
      this.objectSid = new Gnss.GnssSignal(this._io, this, this._root);
      this.srcSid = new Gnss.GnssSignal(this._io, this, this._root);
      this.originalSender = this._io.readU2le();
    }

    /**
     * HW time in milliseconds.
     */

    /**
     * Event type.
     */

    /**
     * Event object type.
     */

    /**
     * Event result.
     */

    /**
     * Data source for STORE event, reserved for other events.
     */

    /**
     * GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid
     * indicates for which signal the object belongs to. Reserved in other
     * cases.
     */

    /**
     * GNSS signal identifier, If object_type is Almanac, Almanac WN, Iono
     * OR L2C capabilities AND data_source is NDB_DS_RECEIVER sid indicates
     * from which SV data was decoded. Reserved in other cases.
     */

    /**
     * A unique identifier of the sending hardware. For v1.0, set to the 2
     * least significant bytes of the device serial number, valid only if
     * data_source is NDB_DS_SBP. Reserved in case of other data_source.
     */

    return MsgNdbEvent;
  })();

  return Ndb;
})();
return Ndb;
}));
