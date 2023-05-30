// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Integrity = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Integrity = (function() {
  function Integrity(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Integrity.prototype._read = function() {
  }

  var MsgSsrFlagSatellites = Integrity.MsgSsrFlagSatellites = (function() {
    function MsgSsrFlagSatellites(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrFlagSatellites.prototype._read = function() {
      this.obsTime = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.numMsgs = this._io.readU1();
      this.seqNum = this._io.readU1();
      this.ssrSolId = this._io.readU1();
      this.chainId = this._io.readU1();
      this.constId = this._io.readU1();
      this.nFaultySats = this._io.readU1();
      this.faultySats = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.faultySats.push(this._io.readU1());
        i++;
      }
    }

    /**
     * GNSS reference time of the observation used to generate the flag.
     */

    /**
     * Number of messages in the dataset
     */

    /**
     * Position of this message in the dataset
     */

    /**
     * SSR Solution ID.
     */

    /**
     * Chain and type of flag.
     */

    /**
     * Constellation ID.
     */

    /**
     * Number of faulty satellites.
     */

    /**
     * List of faulty satellites.
     */

    return MsgSsrFlagSatellites;
  })();

  var MsgSsrFlagIonoTileSatLos = Integrity.MsgSsrFlagIonoTileSatLos = (function() {
    function MsgSsrFlagIonoTileSatLos(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrFlagIonoTileSatLos.prototype._read = function() {
      this.header = new IntegritySsrHeader(this._io, this, this._root);
      this.nFaultyLos = this._io.readU1();
      this.faultyLos = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.faultyLos.push(new Gnss.SvId(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Header of an integrity message.
     */

    /**
     * Number of faulty LOS.
     */

    /**
     * List of faulty LOS
     */

    return MsgSsrFlagIonoTileSatLos;
  })();

  var MsgSsrFlagIonoGridPointSatLos = Integrity.MsgSsrFlagIonoGridPointSatLos = (function() {
    function MsgSsrFlagIonoGridPointSatLos(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrFlagIonoGridPointSatLos.prototype._read = function() {
      this.header = new IntegritySsrHeader(this._io, this, this._root);
      this.gridPointId = this._io.readU2le();
      this.nFaultyLos = this._io.readU1();
      this.faultyLos = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.faultyLos.push(new Gnss.SvId(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Header of an integrity message.
     */

    /**
     * Index of the grid point.
     */

    /**
     * Number of faulty LOS.
     */

    /**
     * List of faulty LOS
     */

    return MsgSsrFlagIonoGridPointSatLos;
  })();

  var IntegritySsrHeader = Integrity.IntegritySsrHeader = (function() {
    function IntegritySsrHeader(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    IntegritySsrHeader.prototype._read = function() {
      this.obsTime = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.numMsgs = this._io.readU1();
      this.seqNum = this._io.readU1();
      this.ssrSolId = this._io.readU1();
      this.tileSetId = this._io.readU2le();
      this.tileId = this._io.readU2le();
      this.chainId = this._io.readU1();
    }

    /**
     * GNSS reference time of the observation used to generate the flag.
     */

    /**
     * Number of messages in the dataset
     */

    /**
     * Position of this message in the dataset
     */

    /**
     * SSR Solution ID.
     */

    /**
     * Unique identifier of the set this tile belongs to.
     */

    /**
     * Unique identifier of this tile in the tile set.
     */

    /**
     * Chain and type of flag.
     */

    return IntegritySsrHeader;
  })();

  var MsgAcknowledge = Integrity.MsgAcknowledge = (function() {
    function MsgAcknowledge(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgAcknowledge.prototype._read = function() {
      this.requestId = this._io.readU1();
      this.areaId = this._io.readU4le();
      this.responseCode = this._io.readU1();
      this.correctionMaskOnDemand = this._io.readU2le();
      this.correctionMaskStream = this._io.readU2le();
      this.solutionId = this._io.readU1();
    }

    /**
     * Echo of the request ID field from the corresponding CRA message, or
     * 255 if no request ID was provided.
     */

    /**
     * Echo of the Area ID field from the corresponding CRA message.
     */

    /**
     * Reported status of the request.
     */

    /**
     * Contains the message group(s) that will be sent in response from the
     * corresponding CRA correction mask. An echo of the correction mask
     * field from the corresponding CRA message.
     */

    /**
     * For future expansion. Always set to 0.
     */

    /**
     * The solution ID of the instance providing the corrections.
     */

    return MsgAcknowledge;
  })();

  var MsgSsrFlagIonoGridPoints = Integrity.MsgSsrFlagIonoGridPoints = (function() {
    function MsgSsrFlagIonoGridPoints(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrFlagIonoGridPoints.prototype._read = function() {
      this.header = new IntegritySsrHeader(this._io, this, this._root);
      this.nFaultyPoints = this._io.readU1();
      this.faultyPoints = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.faultyPoints.push(this._io.readU2le());
        i++;
      }
    }

    /**
     * Header of an integrity message.
     */

    /**
     * Number of faulty grid points.
     */

    /**
     * List of faulty grid points.
     */

    return MsgSsrFlagIonoGridPoints;
  })();

  var MsgSsrFlagTropoGridPoints = Integrity.MsgSsrFlagTropoGridPoints = (function() {
    function MsgSsrFlagTropoGridPoints(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrFlagTropoGridPoints.prototype._read = function() {
      this.header = new IntegritySsrHeader(this._io, this, this._root);
      this.nFaultyPoints = this._io.readU1();
      this.faultyPoints = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.faultyPoints.push(this._io.readU2le());
        i++;
      }
    }

    /**
     * Header of an integrity message.
     */

    /**
     * Number of faulty grid points.
     */

    /**
     * List of faulty grid points.
     */

    return MsgSsrFlagTropoGridPoints;
  })();

  /**
   * Integrity monitoring flags for multiple aggregated elements. An element
   * could be a satellite, SSR grid point, or SSR tile. A group of aggregated
   * elements being monitored for integrity could refer to:
   * 
   * - Satellites in a particular {GPS, GAL, BDS} constellation.
   * 
   * - Satellites in the line-of-sight of a particular SSR tile.
   * 
   * - Satellites in the line-of-sight of a particular SSR grid point.
   * 
   * The integrity usage for a group of aggregated elements varies according
   * to the integrity flag of the satellites comprising that group.
   * 
   * SSR_INTEGRITY_USAGE_NOMINAL: All satellites received passed the
   * integrity check and have flag INTEGRITY_FLAG_OK.
   * 
   * SSR_INTEGRITY_USAGE_WARNING: A limited number of elements in the group
   * failed the integrity check. Refer to more granular integrity messages
   * for details on the specific failing elements.
   * 
   * SSR_INTEGRITY_USAGE_ALERT: Most elements in the group failed the
   * integrity check, do not use for positioning.
   * 
   * SSR_INTEGRITY_USAGE_NOT_MONITORED: Unable to verify the integrity flag
   * of elements in the group.
   */

  var MsgSsrFlagHighLevel = Integrity.MsgSsrFlagHighLevel = (function() {
    function MsgSsrFlagHighLevel(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrFlagHighLevel.prototype._read = function() {
      this.obsTime = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.corrTime = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.ssrSolId = this._io.readU1();
      this.tileSetId = this._io.readU2le();
      this.tileId = this._io.readU2le();
      this.chainId = this._io.readU1();
      this.useGpsSat = this._io.readU1();
      this.useGalSat = this._io.readU1();
      this.useBdsSat = this._io.readU1();
      this.reserved = [];
      for (var i = 0; i < 6; i++) {
        this.reserved.push(this._io.readU1());
      }
      this.useTropoGridPoints = this._io.readU1();
      this.useIonoGridPoints = this._io.readU1();
      this.useIonoTileSatLos = this._io.readU1();
      this.useIonoGridPointSatLos = this._io.readU1();
    }

    /**
     * GNSS reference time of the observation used to generate the flag.
     */

    /**
     * GNSS reference time of the correction associated to the flag.
     */

    /**
     * SSR Solution ID.
     */

    /**
     * Unique identifier of the set this tile belongs to.
     */

    /**
     * Unique identifier of this tile in the tile set.
     */

    /**
     * Chain and type of flag.
     */

    /**
     * Use GPS satellites.
     */

    /**
     * Use GAL satellites.
     */

    /**
     * Use BDS satellites.
     */

    /**
     * Reserved
     */

    /**
     * Use tropo grid points.
     */

    /**
     * Use iono grid points.
     */

    /**
     * Use iono tile satellite LoS.
     */

    /**
     * Use iono grid point satellite LoS.
     */

    return MsgSsrFlagHighLevel;
  })();

  return Integrity;
})();
return Integrity;
}));
