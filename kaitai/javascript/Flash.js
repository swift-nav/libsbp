// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Flash = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Flash = (function() {
  function Flash(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Flash.prototype._read = function() {
  }

  /**
   * This message defines success or failure codes for a variety of flash
   * memory requests from the host to the device. Flash read and write
   * messages, such as MSG_FLASH_READ_REQ, or MSG_FLASH_PROGRAM, may return
   * this message on failure.
   */

  var MsgFlashDone = Flash.MsgFlashDone = (function() {
    function MsgFlashDone(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgFlashDone.prototype._read = function() {
      this.response = this._io.readU1();
    }

    /**
     * Response flags
     */

    return MsgFlashDone;
  })();

  /**
   * The flash status message writes to the 8-bit M25 flash status register.
   * The device replies with a MSG_FLASH_DONE message.
   */

  var MsgM25FlashWriteStatus = Flash.MsgM25FlashWriteStatus = (function() {
    function MsgM25FlashWriteStatus(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgM25FlashWriteStatus.prototype._read = function() {
      this.status = [];
      for (var i = 0; i < 1; i++) {
        this.status.push(this._io.readU1());
      }
    }

    /**
     * Byte to write to the M25 flash status register
     */

    return MsgM25FlashWriteStatus;
  })();

  /**
   * The flash read message reads a set of addresses of either the STM or M25
   * onboard flash. The device replies with a MSG_FLASH_READ_RESP message
   * containing either the read data on success or a MSG_FLASH_DONE message
   * containing the return code FLASH_INVALID_LEN (2) if the maximum read
   * size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
   * the allowed range.
   */

  var MsgFlashReadResp = Flash.MsgFlashReadResp = (function() {
    function MsgFlashReadResp(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgFlashReadResp.prototype._read = function() {
      this.target = this._io.readU1();
      this.addrStart = [];
      for (var i = 0; i < 3; i++) {
        this.addrStart.push(this._io.readU1());
      }
      this.addrLen = this._io.readU1();
    }

    /**
     * Target flags
     */

    /**
     * Starting address offset to read from
     */

    /**
     * Length of set of addresses to read, counting up from starting
     * address
     */

    return MsgFlashReadResp;
  })();

  /**
   * The flash erase message from the host erases a sector of either the STM
   * or M25 onboard flash memory. The device will reply with a MSG_FLASH_DONE
   * message containing the return code - FLASH_OK (0) on success or
   * FLASH_INVALID_FLASH (1) if the flash specified is invalid.
   */

  var MsgFlashErase = Flash.MsgFlashErase = (function() {
    function MsgFlashErase(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgFlashErase.prototype._read = function() {
      this.target = this._io.readU1();
      this.sectorNum = this._io.readU4le();
    }

    /**
     * Target flags
     */

    /**
     * Flash sector number to erase (0-11 for the STM, 0-15 for the M25)
     */

    return MsgFlashErase;
  })();

  /**
   * This message reads the device's hard-coded unique ID. The host requests
   * the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
   * MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
   */

  var MsgStmUniqueIdResp = Flash.MsgStmUniqueIdResp = (function() {
    function MsgStmUniqueIdResp(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgStmUniqueIdResp.prototype._read = function() {
      this.stmId = [];
      for (var i = 0; i < 12; i++) {
        this.stmId.push(this._io.readU1());
      }
    }

    /**
     * Device unique ID
     */

    return MsgStmUniqueIdResp;
  })();

  /**
   * This message reads the device's hard-coded unique ID. The host requests
   * the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
   * MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
   */

  var MsgStmUniqueIdReq = Flash.MsgStmUniqueIdReq = (function() {
    function MsgStmUniqueIdReq(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgStmUniqueIdReq.prototype._read = function() {
    }

    return MsgStmUniqueIdReq;
  })();

  /**
   * The flash program message programs a set of addresses of either the STM
   * or M25 flash. The device replies with either a MSG_FLASH_DONE message
   * containing the return code FLASH_OK (0) on success, or FLASH_INVALID_LEN
   * (2) if the maximum write size is exceeded. Note that the sector-
   * containing addresses must be erased before addresses can be programmed.
   */

  var MsgFlashProgram = Flash.MsgFlashProgram = (function() {
    function MsgFlashProgram(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgFlashProgram.prototype._read = function() {
      this.target = this._io.readU1();
      this.addrStart = [];
      for (var i = 0; i < 3; i++) {
        this.addrStart.push(this._io.readU1());
      }
      this.addrLen = this._io.readU1();
      this.data = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.data.push(this._io.readU1());
        i++;
      }
    }

    /**
     * Target flags
     */

    /**
     * Starting address offset to program
     */

    /**
     * Length of set of addresses to program, counting up from starting
     * address
     */

    /**
     * Data to program addresses with, with length N=addr_len
     */

    return MsgFlashProgram;
  })();

  /**
   * The flash read message reads a set of addresses of either the STM or M25
   * onboard flash. The device replies with a MSG_FLASH_READ_RESP message
   * containing either the read data on success or a MSG_FLASH_DONE message
   * containing the return code FLASH_INVALID_LEN (2) if the maximum read
   * size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
   * the allowed range.
   */

  var MsgFlashReadReq = Flash.MsgFlashReadReq = (function() {
    function MsgFlashReadReq(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgFlashReadReq.prototype._read = function() {
      this.target = this._io.readU1();
      this.addrStart = [];
      for (var i = 0; i < 3; i++) {
        this.addrStart.push(this._io.readU1());
      }
      this.addrLen = this._io.readU1();
    }

    /**
     * Target flags
     */

    /**
     * Starting address offset to read from
     */

    /**
     * Length of set of addresses to read, counting up from starting
     * address
     */

    return MsgFlashReadReq;
  })();

  /**
   * The flash unlock message unlocks a sector of the STM flash memory. The
   * device replies with a MSG_FLASH_DONE message.
   */

  var MsgStmFlashUnlockSector = Flash.MsgStmFlashUnlockSector = (function() {
    function MsgStmFlashUnlockSector(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgStmFlashUnlockSector.prototype._read = function() {
      this.sector = this._io.readU4le();
    }

    /**
     * Flash sector number to unlock
     */

    return MsgStmFlashUnlockSector;
  })();

  /**
   * The flash lock message locks a sector of the STM flash memory. The
   * device replies with a MSG_FLASH_DONE message.
   */

  var MsgStmFlashLockSector = Flash.MsgStmFlashLockSector = (function() {
    function MsgStmFlashLockSector(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgStmFlashLockSector.prototype._read = function() {
      this.sector = this._io.readU4le();
    }

    /**
     * Flash sector number to lock
     */

    return MsgStmFlashLockSector;
  })();

  return Flash;
})();
return Flash;
}));
