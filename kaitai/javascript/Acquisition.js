// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Acquisition = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Acquisition = (function() {
  function Acquisition(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Acquisition.prototype._read = function() {
  }

  /**
   * Deprecated.
   */

  var MsgAcqResultDepC = Acquisition.MsgAcqResultDepC = (function() {
    function MsgAcqResultDepC(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgAcqResultDepC.prototype._read = function() {
      this.cn0 = this._io.readF4le();
      this.cp = this._io.readF4le();
      this.cf = this._io.readF4le();
      this.sid = new Gnss.GnssSignalDep(this._io, this, this._root);
    }

    /**
     * CN/0 of best point
     */

    /**
     * Code phase of best point
     */

    /**
     * Carrier frequency of best point
     */

    /**
     * GNSS signal for which acquisition was attempted
     */

    return MsgAcqResultDepC;
  })();

  /**
   * Deprecated.
   */

  var MsgAcqResultDepB = Acquisition.MsgAcqResultDepB = (function() {
    function MsgAcqResultDepB(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgAcqResultDepB.prototype._read = function() {
      this.snr = this._io.readF4le();
      this.cp = this._io.readF4le();
      this.cf = this._io.readF4le();
      this.sid = new Gnss.GnssSignalDep(this._io, this, this._root);
    }

    /**
     * SNR of best point. Currently in arbitrary SNR points, but will be in
     * units of dB Hz in a later revision of this message.
     */

    /**
     * Code phase of best point
     */

    /**
     * Carrier frequency of best point
     */

    /**
     * GNSS signal for which acquisition was attempted
     */

    return MsgAcqResultDepB;
  })();

  /**
   * Profile for a specific SV for debugging purposes. The message describes
   * SV profile during acquisition time. The message is used to debug and
   * measure the performance.
   */

  var AcqSvProfile = Acquisition.AcqSvProfile = (function() {
    function AcqSvProfile(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    AcqSvProfile.prototype._read = function() {
      this.jobType = this._io.readU1();
      this.status = this._io.readU1();
      this.cn0 = this._io.readU2le();
      this.intTime = this._io.readU1();
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.binWidth = this._io.readU2le();
      this.timestamp = this._io.readU4le();
      this.timeSpent = this._io.readU4le();
      this.cfMin = this._io.readS4le();
      this.cfMax = this._io.readS4le();
      this.cf = this._io.readS4le();
      this.cp = this._io.readU4le();
    }

    /**
     * SV search job type (deep, fallback, etc)
     */

    /**
     * Acquisition status 1 is Success, 0 is Failure
     */

    /**
     * CN0 value. Only valid if status is '1'
     */

    /**
     * Acquisition integration time
     */

    /**
     * GNSS signal for which acquisition was attempted
     */

    /**
     * Acq frequency bin width
     */

    /**
     * Timestamp of the job complete event
     */

    /**
     * Time spent to search for sid.code
     */

    /**
     * Doppler range lowest frequency
     */

    /**
     * Doppler range highest frequency
     */

    /**
     * Doppler value of detected peak. Only valid if status is '1'
     */

    /**
     * Codephase of detected peak. Only valid if status is '1'
     */

    return AcqSvProfile;
  })();

  /**
   * The message describes all SV profiles during acquisition time. The
   * message is used to debug and measure the performance.
   */

  var MsgAcqSvProfile = Acquisition.MsgAcqSvProfile = (function() {
    function MsgAcqSvProfile(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgAcqSvProfile.prototype._read = function() {
      this.acqSvProfile = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.acqSvProfile.push(new AcqSvProfile(this._io, this, this._root));
        i++;
      }
    }

    /**
     * SV profiles during acquisition time
     */

    return MsgAcqSvProfile;
  })();

  /**
   * Deprecated.
   */

  var AcqSvProfileDep = Acquisition.AcqSvProfileDep = (function() {
    function AcqSvProfileDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    AcqSvProfileDep.prototype._read = function() {
      this.jobType = this._io.readU1();
      this.status = this._io.readU1();
      this.cn0 = this._io.readU2le();
      this.intTime = this._io.readU1();
      this.sid = new Gnss.GnssSignalDep(this._io, this, this._root);
      this.binWidth = this._io.readU2le();
      this.timestamp = this._io.readU4le();
      this.timeSpent = this._io.readU4le();
      this.cfMin = this._io.readS4le();
      this.cfMax = this._io.readS4le();
      this.cf = this._io.readS4le();
      this.cp = this._io.readU4le();
    }

    /**
     * SV search job type (deep, fallback, etc)
     */

    /**
     * Acquisition status 1 is Success, 0 is Failure
     */

    /**
     * CN0 value. Only valid if status is '1'
     */

    /**
     * Acquisition integration time
     */

    /**
     * GNSS signal for which acquisition was attempted
     */

    /**
     * Acq frequency bin width
     */

    /**
     * Timestamp of the job complete event
     */

    /**
     * Time spent to search for sid.code
     */

    /**
     * Doppler range lowest frequency
     */

    /**
     * Doppler range highest frequency
     */

    /**
     * Doppler value of detected peak. Only valid if status is '1'
     */

    /**
     * Codephase of detected peak. Only valid if status is '1'
     */

    return AcqSvProfileDep;
  })();

  /**
   * This message describes the results from an attempted GPS signal
   * acquisition search for a satellite PRN over a code phase/carrier
   * frequency range. It contains the parameters of the point in the
   * acquisition search space with the best carrier-to-noise (CN/0) ratio.
   */

  var MsgAcqResult = Acquisition.MsgAcqResult = (function() {
    function MsgAcqResult(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgAcqResult.prototype._read = function() {
      this.cn0 = this._io.readF4le();
      this.cp = this._io.readF4le();
      this.cf = this._io.readF4le();
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
    }

    /**
     * CN/0 of best point
     */

    /**
     * Code phase of best point
     */

    /**
     * Carrier frequency of best point
     */

    /**
     * GNSS signal for which acquisition was attempted
     */

    return MsgAcqResult;
  })();

  /**
   * Deprecated.
   */

  var MsgAcqResultDepA = Acquisition.MsgAcqResultDepA = (function() {
    function MsgAcqResultDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgAcqResultDepA.prototype._read = function() {
      this.snr = this._io.readF4le();
      this.cp = this._io.readF4le();
      this.cf = this._io.readF4le();
      this.prn = this._io.readU1();
    }

    /**
     * SNR of best point. Currently dimensionless, but will have units of
     * dB Hz in the revision of this message.
     */

    /**
     * Code phase of best point
     */

    /**
     * Carrier frequency of best point
     */

    /**
     * PRN-1 identifier of the satellite signal for which acquisition was
     * attempted
     */

    return MsgAcqResultDepA;
  })();

  /**
   * Deprecated.
   */

  var MsgAcqSvProfileDep = Acquisition.MsgAcqSvProfileDep = (function() {
    function MsgAcqSvProfileDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgAcqSvProfileDep.prototype._read = function() {
      this.acqSvProfile = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.acqSvProfile.push(new AcqSvProfileDep(this._io, this, this._root));
        i++;
      }
    }

    /**
     * SV profiles during acquisition time
     */

    return MsgAcqSvProfileDep;
  })();

  return Acquisition;
})();
return Acquisition;
}));
