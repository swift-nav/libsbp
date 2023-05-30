// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.SolutionMeta = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var SolutionMeta = (function() {
  function SolutionMeta(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  SolutionMeta.prototype._read = function() {
  }

  /**
   * Metadata around the GNSS sensors involved in the fuzed solution.
   * Accessible through sol_in[N].flags in a MSG_SOLN_META.
   */

  var GnssInputType = SolutionMeta.GnssInputType = (function() {
    function GnssInputType(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    GnssInputType.prototype._read = function() {
      this.flags = this._io.readU1();
    }

    /**
     * flags that store all relevant info specific to this sensor type.
     */

    return GnssInputType;
  })();

  /**
   * This message contains all metadata about the sensors received and/or
   * used in computing the sensorfusion solution. It focuses primarily, but
   * not only, on GNSS metadata. Regarding the age of the last received valid
   * GNSS solution, the highest two bits are time status, indicating whether
   * age gnss can or can not be used to retrieve time of measurement (noted
   * TOM, also known as time of validity) If it can, subtract 'age gnss' from
   * 'tow' in navigation messages to get TOM. Can be used before alignment is
   * complete in the Fusion Engine, when output solution is the last received
   * valid GNSS solution and its tow is not a TOM.
   */

  var MsgSolnMeta = SolutionMeta.MsgSolnMeta = (function() {
    function MsgSolnMeta(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSolnMeta.prototype._read = function() {
      this.tow = this._io.readU4le();
      this.pdop = this._io.readU2le();
      this.hdop = this._io.readU2le();
      this.vdop = this._io.readU2le();
      this.ageCorrections = this._io.readU2le();
      this.ageGnss = this._io.readU4le();
      this.solIn = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.solIn.push(new SolutionInputType(this._io, this, this._root));
        i++;
      }
    }

    /**
     * GPS time of week rounded to the nearest millisecond
     */

    /**
     * Position Dilution of Precision as per last available DOPS from PVT
     * engine (0xFFFF indicates invalid)
     */

    /**
     * Horizontal Dilution of Precision as per last available DOPS from PVT
     * engine (0xFFFF indicates invalid)
     */

    /**
     * Vertical Dilution of Precision as per last available DOPS from PVT
     * engine (0xFFFF indicates invalid)
     */

    /**
     * Age of corrections as per last available AGE_CORRECTIONS from PVT
     * engine (0xFFFF indicates invalid)
     */

    /**
     * Age and Time Status of the last received valid GNSS solution.
     */

    /**
     * Array of Metadata describing the sensors potentially involved in the
     * solution. Each element in the array represents a single sensor type
     * and consists of flags containing (meta)data pertaining to that
     * specific single sensor. Refer to each (XX)InputType descriptor in
     * the present doc.
     */

    return MsgSolnMeta;
  })();

  /**
   * Deprecated.
   * 
   * This message contains all metadata about the sensors received and/or
   * used in computing the Fuzed Solution. It focuses primarily, but not
   * only, on GNSS metadata.
   */

  var MsgSolnMetaDepA = SolutionMeta.MsgSolnMetaDepA = (function() {
    function MsgSolnMetaDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSolnMetaDepA.prototype._read = function() {
      this.pdop = this._io.readU2le();
      this.hdop = this._io.readU2le();
      this.vdop = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.ageCorrections = this._io.readU2le();
      this.alignmentStatus = this._io.readU1();
      this.lastUsedGnssPosTow = this._io.readU4le();
      this.lastUsedGnssVelTow = this._io.readU4le();
      this.solIn = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.solIn.push(new SolutionInputType(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Position Dilution of Precision as per last available DOPS from PVT
     * engine (0xFFFF indicates invalid)
     */

    /**
     * Horizontal Dilution of Precision as per last available DOPS from PVT
     * engine (0xFFFF indicates invalid)
     */

    /**
     * Vertical Dilution of Precision as per last available DOPS from PVT
     * engine (0xFFFF indicates invalid)
     */

    /**
     * Number of satellites as per last available solution from PVT engine
     */

    /**
     * Age of corrections as per last available AGE_CORRECTIONS from PVT
     * engine (0xFFFF indicates invalid)
     */

    /**
     * State of alignment and the status and receipt of the alignment
     * inputs
     */

    /**
     * Tow of last-used GNSS position measurement
     */

    /**
     * Tow of last-used GNSS velocity measurement
     */

    /**
     * Array of Metadata describing the sensors potentially involved in the
     * solution. Each element in the array represents a single sensor type
     * and consists of flags containing (meta)data pertaining to that
     * specific single sensor. Refer to each (XX)InputType descriptor in
     * the present doc.
     */

    return MsgSolnMetaDepA;
  })();

  /**
   * Metadata around the IMU sensors involved in the fuzed solution.
   * Accessible through sol_in[N].flags in a MSG_SOLN_META.
   */

  var ImuInputType = SolutionMeta.ImuInputType = (function() {
    function ImuInputType(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    ImuInputType.prototype._read = function() {
      this.flags = this._io.readU1();
    }

    /**
     * Instrument time, grade, and architecture for a sensor.
     */

    return ImuInputType;
  })();

  /**
   * Metadata around the Odometry sensors involved in the fuzed solution.
   * Accessible through sol_in[N].flags in a MSG_SOLN_META.
   */

  var OdoInputType = SolutionMeta.OdoInputType = (function() {
    function OdoInputType(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    OdoInputType.prototype._read = function() {
      this.flags = this._io.readU1();
    }

    /**
     * Instrument ODO rate, grade, and quality.
     */

    return OdoInputType;
  })();

  /**
   * Metadata describing which sensors were involved in the solution. The
   * structure is fixed no matter what the actual sensor type is. The
   * sensor_type field tells you which sensor we are talking about. It also
   * tells you whether the sensor data was actually used or not. The flags
   * field, always a u8, contains the sensor-specific data. The content of
   * flags, for each sensor type, is described in the relevant structures in
   * this section.
   */

  var SolutionInputType = SolutionMeta.SolutionInputType = (function() {
    function SolutionInputType(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    SolutionInputType.prototype._read = function() {
      this.sensorType = this._io.readU1();
      this.flags = this._io.readU1();
    }

    /**
     * The type of sensor
     */

    /**
     * Refer to each InputType description
     */

    return SolutionInputType;
  })();

  return SolutionMeta;
})();
return SolutionMeta;
}));
