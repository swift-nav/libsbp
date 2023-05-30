// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.User = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var User = (function() {
  function User(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  User.prototype._read = function() {
  }

  /**
   * This message can contain any application specific user data up to a
   * maximum length of 255 bytes per message.
   */

  var MsgUserData = User.MsgUserData = (function() {
    function MsgUserData(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgUserData.prototype._read = function() {
      this.contents = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.contents.push(this._io.readU1());
        i++;
      }
    }

    /**
     * User data payload
     */

    return MsgUserData;
  })();

  return User;
})();
return User;
}));
