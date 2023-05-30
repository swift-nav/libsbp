// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Bootload = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Bootload = (function() {
  function Bootload(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Bootload.prototype._read = function() {
  }

  /**
   * The device message from the host reads a unique device identifier from
   * the SwiftNAP, an FPGA. The host requests the ID by sending a
   * MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
   * MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
   * that this ID is tied to the FPGA, and not related to the Piksi's serial
   * number.
   */

  var MsgNapDeviceDnaReq = Bootload.MsgNapDeviceDnaReq = (function() {
    function MsgNapDeviceDnaReq(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgNapDeviceDnaReq.prototype._read = function() {
    }

    return MsgNapDeviceDnaReq;
  })();

  /**
   * The host initiates the bootloader to jump to the application.
   */

  var MsgBootloaderJumpToApp = Bootload.MsgBootloaderJumpToApp = (function() {
    function MsgBootloaderJumpToApp(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgBootloaderJumpToApp.prototype._read = function() {
      this.jump = this._io.readU1();
    }

    /**
     * Ignored by the device
     */

    return MsgBootloaderJumpToApp;
  })();

  /**
   * The handshake message response from the device establishes a handshake
   * between the device bootloader and the host. The request from the host is
   * MSG_BOOTLOADER_HANDSHAKE_REQ.  The payload contains the bootloader
   * version number and the SBP protocol version number.
   */

  var MsgBootloaderHandshakeResp = Bootload.MsgBootloaderHandshakeResp = (function() {
    function MsgBootloaderHandshakeResp(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgBootloaderHandshakeResp.prototype._read = function() {
      this.flags = this._io.readU4le();
      this.version = KaitaiStream.bytesToStr(this._io.readBytesFull(), "ascii");
    }

    /**
     * Bootloader flags
     */

    /**
     * Bootloader version number
     */

    return MsgBootloaderHandshakeResp;
  })();

  /**
   * The device message from the host reads a unique device identifier from
   * the SwiftNAP, an FPGA. The host requests the ID by sending a
   * MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
   * MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
   * that this ID is tied to the FPGA, and not related to the Piksi's serial
   * number.
   */

  var MsgNapDeviceDnaResp = Bootload.MsgNapDeviceDnaResp = (function() {
    function MsgNapDeviceDnaResp(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgNapDeviceDnaResp.prototype._read = function() {
      this.dna = [];
      for (var i = 0; i < 8; i++) {
        this.dna.push(this._io.readU1());
      }
    }

    /**
     * 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the
     * right.
     */

    return MsgNapDeviceDnaResp;
  })();

  /**
   * The handshake message request from the host establishes a handshake
   * between the device bootloader and the host. The response from the device
   * is MSG_BOOTLOADER_HANDSHAKE_RESP.
   */

  var MsgBootloaderHandshakeReq = Bootload.MsgBootloaderHandshakeReq = (function() {
    function MsgBootloaderHandshakeReq(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgBootloaderHandshakeReq.prototype._read = function() {
    }

    return MsgBootloaderHandshakeReq;
  })();

  /**
   * Deprecated.
   */

  var MsgBootloaderHandshakeDepA = Bootload.MsgBootloaderHandshakeDepA = (function() {
    function MsgBootloaderHandshakeDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgBootloaderHandshakeDepA.prototype._read = function() {
      this.handshake = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.handshake.push(this._io.readU1());
        i++;
      }
    }

    /**
     * Version number string (not NULL terminated)
     */

    return MsgBootloaderHandshakeDepA;
  })();

  return Bootload;
})();
return Bootload;
}));
