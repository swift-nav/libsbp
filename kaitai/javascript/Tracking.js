// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Tracking = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Tracking = (function() {
  function Tracking(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Tracking.prototype._read = function() {
  }

  /**
   * Deprecated.
   */

  var MsgTrackingStateDetailedDep = Tracking.MsgTrackingStateDetailedDep = (function() {
    function MsgTrackingStateDetailedDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgTrackingStateDetailedDep.prototype._read = function() {
      this.recvTime = this._io.readU8le();
      this.tot = new Gnss.GpsTimeDep(this._io, this, this._root);
      this.p = this._io.readU4le();
      this.pStd = this._io.readU2le();
      this.l = new Gnss.CarrierPhase(this._io, this, this._root);
      this.cn0 = this._io.readU1();
      this.lock = this._io.readU2le();
      this.sid = new Gnss.GnssSignalDep(this._io, this, this._root);
      this.doppler = this._io.readS4le();
      this.dopplerStd = this._io.readU2le();
      this.uptime = this._io.readU4le();
      this.clockOffset = this._io.readS2le();
      this.clockDrift = this._io.readS2le();
      this.corrSpacing = this._io.readU2le();
      this.acceleration = this._io.readS1();
      this.syncFlags = this._io.readU1();
      this.towFlags = this._io.readU1();
      this.trackFlags = this._io.readU1();
      this.navFlags = this._io.readU1();
      this.psetFlags = this._io.readU1();
      this.miscFlags = this._io.readU1();
    }

    /**
     * Receiver clock time.
     */

    /**
     * Time of transmission of signal from satellite. TOW only valid when
     * TOW status is decoded or propagated. WN only valid when week number
     * valid flag is set.
     */

    /**
     * Pseudorange observation. Valid only when pseudorange valid flag is
     * set.
     */

    /**
     * Pseudorange observation standard deviation. Valid only when
     * pseudorange valid flag is set.
     */

    /**
     * Carrier phase observation with typical sign convention. Valid only
     * when PLL pessimistic lock is achieved.
     */

    /**
     * Carrier-to-Noise density
     */

    /**
     * Lock time. It is encoded according to DF402 from the RTCM 10403.2
     * Amendment 2 specification. Valid values range from 0 to 15.
     */

    /**
     * GNSS signal identifier.
     */

    /**
     * Carrier Doppler frequency.
     */

    /**
     * Carrier Doppler frequency standard deviation.
     */

    /**
     * Number of seconds of continuous tracking. Specifies how much time
     * signal is in continuous track.
     */

    /**
     * TCXO clock offset. Valid only when valid clock valid flag is set.
     */

    /**
     * TCXO clock drift. Valid only when valid clock valid flag is set.
     */

    /**
     * Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
     */

    /**
     * Acceleration. Valid only when acceleration valid flag is set.
     */

    /**
     * Synchronization status flags.
     */

    /**
     * TOW status flags.
     */

    /**
     * Tracking loop status flags.
     */

    /**
     * Navigation data status flags.
     */

    /**
     * Parameters sets flags.
     */

    /**
     * Miscellaneous flags.
     */

    return MsgTrackingStateDetailedDep;
  })();

  /**
   * Deprecated.
   */

  var TrackingChannelStateDepB = Tracking.TrackingChannelStateDepB = (function() {
    function TrackingChannelStateDepB(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    TrackingChannelStateDepB.prototype._read = function() {
      this.state = this._io.readU1();
      this.sid = new Gnss.GnssSignalDep(this._io, this, this._root);
      this.cn0 = this._io.readF4le();
    }

    /**
     * Status of tracking channel
     */

    /**
     * GNSS signal being tracked
     */

    /**
     * Carrier-to-noise density
     */

    return TrackingChannelStateDepB;
  })();

  /**
   * Tracking channel state for a specific satellite signal and measured
   * signal power.
   */

  var TrackingChannelState = Tracking.TrackingChannelState = (function() {
    function TrackingChannelState(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    TrackingChannelState.prototype._read = function() {
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.fcn = this._io.readU1();
      this.cn0 = this._io.readU1();
    }

    /**
     * GNSS signal being tracked
     */

    /**
     * Frequency channel number (GLONASS only)
     */

    /**
     * Carrier-to-Noise density.  Zero implies invalid cn0.
     */

    return TrackingChannelState;
  })();

  /**
   * The tracking message returns a variable-length array of tracking channel
   * states. It reports status and carrier-to-noise density measurements for
   * all tracked satellites.
   */

  var MsgTrackingState = Tracking.MsgTrackingState = (function() {
    function MsgTrackingState(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgTrackingState.prototype._read = function() {
      this.states = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.states.push(new TrackingChannelState(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Signal tracking channel state
     */

    return MsgTrackingState;
  })();

  /**
   * Deprecated.
   */

  var TrackingChannelStateDepA = Tracking.TrackingChannelStateDepA = (function() {
    function TrackingChannelStateDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    TrackingChannelStateDepA.prototype._read = function() {
      this.state = this._io.readU1();
      this.prn = this._io.readU1();
      this.cn0 = this._io.readF4le();
    }

    /**
     * Status of tracking channel
     */

    /**
     * PRN-1 being tracked
     */

    /**
     * Carrier-to-noise density
     */

    return TrackingChannelStateDepA;
  })();

  /**
   * Deprecated.
   */

  var MsgTrackingIqDepA = Tracking.MsgTrackingIqDepA = (function() {
    function MsgTrackingIqDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgTrackingIqDepA.prototype._read = function() {
      this.channel = this._io.readU1();
      this.sid = new Gnss.GnssSignalDep(this._io, this, this._root);
      this.corrs = [];
      for (var i = 0; i < 3; i++) {
        this.corrs.push(this._io.readU8le());
      }
    }

    /**
     * Tracking channel of origin
     */

    /**
     * GNSS signal identifier
     */

    /**
     * Early, Prompt and Late correlations
     */

    return MsgTrackingIqDepA;
  })();

  /**
   * Structure containing in-phase and quadrature correlation components.
   */

  var TrackingChannelCorrelationDep = Tracking.TrackingChannelCorrelationDep = (function() {
    function TrackingChannelCorrelationDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    TrackingChannelCorrelationDep.prototype._read = function() {
      this.i = this._io.readS4le();
      this.q = this._io.readS4le();
    }

    /**
     * In-phase correlation
     */

    /**
     * Quadrature correlation
     */

    return TrackingChannelCorrelationDep;
  })();

  /**
   * Deprecated.
   */

  var MsgTrackingStateDepA = Tracking.MsgTrackingStateDepA = (function() {
    function MsgTrackingStateDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgTrackingStateDepA.prototype._read = function() {
      this.states = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.states.push(new TrackingChannelStateDepA(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Satellite tracking channel state
     */

    return MsgTrackingStateDepA;
  })();

  /**
   * The tracking message returns a variable-length array of tracking channel
   * states. It reports status and carrier-to-noise density measurements for
   * all tracked satellites.
   */

  var MsgMeasurementState = Tracking.MsgMeasurementState = (function() {
    function MsgMeasurementState(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgMeasurementState.prototype._read = function() {
      this.states = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.states.push(new MeasurementState(this._io, this, this._root));
        i++;
      }
    }

    /**
     * ME signal tracking channel state
     */

    return MsgMeasurementState;
  })();

  /**
   * Structure containing in-phase and quadrature correlation components.
   */

  var TrackingChannelCorrelation = Tracking.TrackingChannelCorrelation = (function() {
    function TrackingChannelCorrelation(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    TrackingChannelCorrelation.prototype._read = function() {
      this.i = this._io.readS2le();
      this.q = this._io.readS2le();
    }

    /**
     * In-phase correlation
     */

    /**
     * Quadrature correlation
     */

    return TrackingChannelCorrelation;
  })();

  /**
   * When enabled, a tracking channel can output the correlations at each
   * update interval.
   */

  var MsgTrackingIq = Tracking.MsgTrackingIq = (function() {
    function MsgTrackingIq(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgTrackingIq.prototype._read = function() {
      this.channel = this._io.readU1();
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.corrs = [];
      for (var i = 0; i < 3; i++) {
        this.corrs.push(this._io.readU8le());
      }
    }

    /**
     * Tracking channel of origin
     */

    /**
     * GNSS signal identifier
     */

    /**
     * Early, Prompt and Late correlations
     */

    return MsgTrackingIq;
  })();

  /**
   * The tracking message returns a set tracking channel parameters for a
   * single tracking channel useful for debugging issues.
   */

  var MsgTrackingStateDetailedDepA = Tracking.MsgTrackingStateDetailedDepA = (function() {
    function MsgTrackingStateDetailedDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgTrackingStateDetailedDepA.prototype._read = function() {
      this.recvTime = this._io.readU8le();
      this.tot = new Gnss.GpsTime(this._io, this, this._root);
      this.p = this._io.readU4le();
      this.pStd = this._io.readU2le();
      this.l = new Gnss.CarrierPhase(this._io, this, this._root);
      this.cn0 = this._io.readU1();
      this.lock = this._io.readU2le();
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.doppler = this._io.readS4le();
      this.dopplerStd = this._io.readU2le();
      this.uptime = this._io.readU4le();
      this.clockOffset = this._io.readS2le();
      this.clockDrift = this._io.readS2le();
      this.corrSpacing = this._io.readU2le();
      this.acceleration = this._io.readS1();
      this.syncFlags = this._io.readU1();
      this.towFlags = this._io.readU1();
      this.trackFlags = this._io.readU1();
      this.navFlags = this._io.readU1();
      this.psetFlags = this._io.readU1();
      this.miscFlags = this._io.readU1();
    }

    /**
     * Receiver clock time.
     */

    /**
     * Time of transmission of signal from satellite. TOW only valid when
     * TOW status is decoded or propagated. WN only valid when week number
     * valid flag is set.
     */

    /**
     * Pseudorange observation. Valid only when pseudorange valid flag is
     * set.
     */

    /**
     * Pseudorange observation standard deviation. Valid only when
     * pseudorange valid flag is set.
     */

    /**
     * Carrier phase observation with typical sign convention. Valid only
     * when PLL pessimistic lock is achieved.
     */

    /**
     * Carrier-to-Noise density
     */

    /**
     * Lock time. It is encoded according to DF402 from the RTCM 10403.2
     * Amendment 2 specification. Valid values range from 0 to 15.
     */

    /**
     * GNSS signal identifier.
     */

    /**
     * Carrier Doppler frequency.
     */

    /**
     * Carrier Doppler frequency standard deviation.
     */

    /**
     * Number of seconds of continuous tracking. Specifies how much time
     * signal is in continuous track.
     */

    /**
     * TCXO clock offset. Valid only when valid clock valid flag is set.
     */

    /**
     * TCXO clock drift. Valid only when valid clock valid flag is set.
     */

    /**
     * Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
     */

    /**
     * Acceleration. Valid only when acceleration valid flag is set.
     */

    /**
     * Synchronization status flags.
     */

    /**
     * TOW status flags.
     */

    /**
     * Tracking loop status flags.
     */

    /**
     * Navigation data status flags.
     */

    /**
     * Parameters sets flags.
     */

    /**
     * Miscellaneous flags.
     */

    return MsgTrackingStateDetailedDepA;
  })();

  /**
   * Deprecated.
   */

  var MsgTrackingStateDepB = Tracking.MsgTrackingStateDepB = (function() {
    function MsgTrackingStateDepB(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgTrackingStateDepB.prototype._read = function() {
      this.states = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.states.push(new TrackingChannelStateDepB(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Signal tracking channel state
     */

    return MsgTrackingStateDepB;
  })();

  /**
   * Measurement Engine tracking channel state for a specific satellite
   * signal and measured signal power. The mesid field for Glonass can either
   * carry the FCN as 100 + FCN where FCN is in [-7, +6] or the Slot ID (from
   * 1 to 28).
   */

  var MeasurementState = Tracking.MeasurementState = (function() {
    function MeasurementState(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MeasurementState.prototype._read = function() {
      this.mesid = new Gnss.GnssSignal(this._io, this, this._root);
      this.cn0 = this._io.readU1();
    }

    /**
     * Measurement Engine GNSS signal being tracked (carries either Glonass
     * FCN or SLOT)
     */

    /**
     * Carrier-to-Noise density.  Zero implies invalid cn0.
     */

    return MeasurementState;
  })();

  /**
   * When enabled, a tracking channel can output the correlations at each
   * update interval.
   */

  var MsgTrackingIqDepB = Tracking.MsgTrackingIqDepB = (function() {
    function MsgTrackingIqDepB(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgTrackingIqDepB.prototype._read = function() {
      this.channel = this._io.readU1();
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.corrs = [];
      for (var i = 0; i < 3; i++) {
        this.corrs.push(this._io.readU8le());
      }
    }

    /**
     * Tracking channel of origin
     */

    /**
     * GNSS signal identifier
     */

    /**
     * Early, Prompt and Late correlations
     */

    return MsgTrackingIqDepB;
  })();

  return Tracking;
})();
return Tracking;
}));
