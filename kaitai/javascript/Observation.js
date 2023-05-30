// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Observation = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Observation = (function() {
  function Observation(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Observation.prototype._read = function() {
  }

  /**
   * Azimuth and elevation angles of all the visible satellites that the
   * device does have ephemeris or almanac for.
   */

  var MsgSvAzEl = Observation.MsgSvAzEl = (function() {
    function MsgSvAzEl(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSvAzEl.prototype._read = function() {
      this.azel = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.azel.push(new SvAzEl(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Azimuth and elevation per satellite
     */

    return MsgSvAzEl;
  })();

  var GnssCapb = Observation.GnssCapb = (function() {
    function GnssCapb(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    GnssCapb.prototype._read = function() {
      this.gpsActive = this._io.readU8le();
      this.gpsL2c = this._io.readU8le();
      this.gpsL5 = this._io.readU8le();
      this.gloActive = this._io.readU4le();
      this.gloL2of = this._io.readU4le();
      this.gloL3 = this._io.readU4le();
      this.sbasActive = this._io.readU8le();
      this.sbasL5 = this._io.readU8le();
      this.bdsActive = this._io.readU8le();
      this.bdsD2nav = this._io.readU8le();
      this.bdsB2 = this._io.readU8le();
      this.bdsB2a = this._io.readU8le();
      this.qzssActive = this._io.readU4le();
      this.galActive = this._io.readU8le();
      this.galE5 = this._io.readU8le();
    }

    /**
     * GPS SV active mask
     */

    /**
     * GPS L2C active mask
     */

    /**
     * GPS L5 active mask
     */

    /**
     * GLO active mask
     */

    /**
     * GLO L2OF active mask
     */

    /**
     * GLO L3 active mask
     */

    /**
     * SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
     * https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
     */

    /**
     * SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
     * https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
     */

    /**
     * BDS active mask
     */

    /**
     * BDS D2NAV active mask
     */

    /**
     * BDS B2 active mask
     */

    /**
     * BDS B2A active mask
     */

    /**
     * QZSS active mask
     */

    /**
     * GAL active mask
     */

    /**
     * GAL E5 active mask
     */

    return GnssCapb;
  })();

  /**
   * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
   */

  var MsgGroupDelayDepB = Observation.MsgGroupDelayDepB = (function() {
    function MsgGroupDelayDepB(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgGroupDelayDepB.prototype._read = function() {
      this.tOp = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.sid = new Gnss.GnssSignalDep(this._io, this, this._root);
      this.valid = this._io.readU1();
      this.tgd = this._io.readS2le();
      this.iscL1ca = this._io.readS2le();
      this.iscL2c = this._io.readS2le();
    }

    /**
     * Data Predict Time of Week
     */

    /**
     * GNSS signal identifier
     */

    /**
     * bit-field indicating validity of the values, LSB indicating tgd
     * validity etc. 1 = value is valid, 0 = value is not valid.
     */

    return MsgGroupDelayDepB;
  })();

  /**
   * Header of a GPS observation message.
   */

  var ObservationHeaderDep = Observation.ObservationHeaderDep = (function() {
    function ObservationHeaderDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    ObservationHeaderDep.prototype._read = function() {
      this.t = new Gnss.GpsTimeDep(this._io, this, this._root);
      this.nObs = this._io.readU1();
    }

    /**
     * GPS time of this observation
     */

    /**
     * Total number of observations. First nibble is the size of the
     * sequence (n), second nibble is the zero-indexed counter (ith packet
     * of n)
     */

    return ObservationHeaderDep;
  })();

  var AlmanacCommonContentDep = Observation.AlmanacCommonContentDep = (function() {
    function AlmanacCommonContentDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    AlmanacCommonContentDep.prototype._read = function() {
      this.sid = new Gnss.GnssSignalDep(this._io, this, this._root);
      this.toa = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.ura = this._io.readF8le();
      this.fitInterval = this._io.readU4le();
      this.valid = this._io.readU1();
      this.healthBits = this._io.readU1();
    }

    /**
     * GNSS signal identifier
     */

    /**
     * Reference time of almanac
     */

    /**
     * User Range Accuracy
     */

    /**
     * Curve fit interval
     */

    /**
     * Status of almanac, 1 = valid, 0 = invalid
     */

    /**
     * Satellite health status for GPS:
     *   - bits 5-7: NAV data health status. See IS-GPS-200H
     *     Table 20-VII: NAV Data Health Indications.
     *   - bits 0-4: Signal health status. See IS-GPS-200H
     *     Table 20-VIII. Codes for Health of SV Signal
     *     Components.
     * Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for
     * details):
     *   - bit 0: C(n), "unhealthy" flag that is transmitted within
     *     non-immediate data and indicates overall constellation status
     *     at the moment of almanac uploading.
     *     '0' indicates malfunction of n-satellite.
     *     '1' indicates that n-satellite is operational.
     *   - bit 1: Bn(ln), '0' indicates the satellite is operational
     *     and suitable for navigation.
     */

    return AlmanacCommonContentDep;
  })();

  var EphemerisCommonContentDepA = Observation.EphemerisCommonContentDepA = (function() {
    function EphemerisCommonContentDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    EphemerisCommonContentDepA.prototype._read = function() {
      this.sid = new Gnss.GnssSignalDep(this._io, this, this._root);
      this.toe = new Gnss.GpsTimeDep(this._io, this, this._root);
      this.ura = this._io.readF8le();
      this.fitInterval = this._io.readU4le();
      this.valid = this._io.readU1();
      this.healthBits = this._io.readU1();
    }

    /**
     * GNSS signal identifier
     */

    /**
     * Time of Ephemerides
     */

    /**
     * User Range Accuracy
     */

    /**
     * Curve fit interval
     */

    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */

    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * SBAS: 0 = valid, non-zero = invalid
     * GLO: 0 = valid, non-zero = invalid
     */

    return EphemerisCommonContentDepA;
  })();

  var EphemerisCommonContent = Observation.EphemerisCommonContent = (function() {
    function EphemerisCommonContent(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    EphemerisCommonContent.prototype._read = function() {
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.toe = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.ura = this._io.readF4le();
      this.fitInterval = this._io.readU4le();
      this.valid = this._io.readU1();
      this.healthBits = this._io.readU1();
    }

    /**
     * GNSS signal identifier (16 bit)
     */

    /**
     * Time of Ephemerides
     */

    /**
     * User Range Accuracy
     */

    /**
     * Curve fit interval
     */

    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */

    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * SBAS: 0 = valid, non-zero = invalid
     * GLO: 0 = valid, non-zero = invalid
     */

    return EphemerisCommonContent;
  })();

  /**
   * Pseudorange and carrier phase observation for a satellite being tracked.
   * The observations are be interoperable with 3rd party receivers and
   * conform with typical RTCMv3 GNSS observations.
   */

  var PackedObsContentDepC = Observation.PackedObsContentDepC = (function() {
    function PackedObsContentDepC(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    PackedObsContentDepC.prototype._read = function() {
      this.p = this._io.readU4le();
      this.l = new Gnss.CarrierPhase(this._io, this, this._root);
      this.cn0 = this._io.readU1();
      this.lock = this._io.readU2le();
      this.sid = new Gnss.GnssSignalDep(this._io, this, this._root);
    }

    /**
     * Pseudorange observation
     */

    /**
     * Carrier phase observation with typical sign convention.
     */

    /**
     * Carrier-to-Noise density
     */

    /**
     * Lock indicator. This value changes whenever a satellite signal has
     * lost and regained lock, indicating that the carrier phase ambiguity
     * may have changed.
     */

    /**
     * GNSS signal identifier
     */

    return PackedObsContentDepC;
  })();

  /**
   * This observation message has been deprecated in favor of ephemeris
   * message using floats for size reduction.
   */

  var MsgEphemerisGloDepD = Observation.MsgEphemerisGloDepD = (function() {
    function MsgEphemerisGloDepD(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisGloDepD.prototype._read = function() {
      this.common = new EphemerisCommonContentDepB(this._io, this, this._root);
      this.gamma = this._io.readF8le();
      this.tau = this._io.readF8le();
      this.dTau = this._io.readF8le();
      this.pos = [];
      for (var i = 0; i < 3; i++) {
        this.pos.push(this._io.readF8le());
      }
      this.vel = [];
      for (var i = 0; i < 3; i++) {
        this.vel.push(this._io.readF8le());
      }
      this.acc = [];
      for (var i = 0; i < 3; i++) {
        this.acc.push(this._io.readF8le());
      }
      this.fcn = this._io.readU1();
      this.iod = this._io.readU1();
    }

    /**
     * Values common for all ephemeris types
     */

    /**
     * Relative deviation of predicted carrier frequency from nominal
     */

    /**
     * Correction to the SV time
     */

    /**
     * Equipment delay between L1 and L2
     */

    /**
     * Position of the SV at tb in PZ-90.02 coordinates system
     */

    /**
     * Velocity vector of the SV at tb in PZ-90.02 coordinates system
     */

    /**
     * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
     */

    /**
     * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
     */

    /**
     * Issue of data. Equal to the 7 bits of the immediate data word t_b
     */

    return MsgEphemerisGloDepD;
  })();

  /**
   * Deprecated.
   */

  var MsgObsDepA = Observation.MsgObsDepA = (function() {
    function MsgObsDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgObsDepA.prototype._read = function() {
      this.header = new ObservationHeaderDep(this._io, this, this._root);
      this.obs = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.obs.push(new PackedObsContentDepA(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Header of a GPS observation message
     */

    /**
     * Pseudorange and carrier phase observation for a satellite being
     * tracked.
     */

    return MsgObsDepA;
  })();

  /**
   * Deprecated.
   */

  var MsgEphemerisDepB = Observation.MsgEphemerisDepB = (function() {
    function MsgEphemerisDepB(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisDepB.prototype._read = function() {
      this.tgd = this._io.readF8le();
      this.cRs = this._io.readF8le();
      this.cRc = this._io.readF8le();
      this.cUc = this._io.readF8le();
      this.cUs = this._io.readF8le();
      this.cIc = this._io.readF8le();
      this.cIs = this._io.readF8le();
      this.dn = this._io.readF8le();
      this.m0 = this._io.readF8le();
      this.ecc = this._io.readF8le();
      this.sqrta = this._io.readF8le();
      this.omega0 = this._io.readF8le();
      this.omegadot = this._io.readF8le();
      this.w = this._io.readF8le();
      this.inc = this._io.readF8le();
      this.incDot = this._io.readF8le();
      this.af0 = this._io.readF8le();
      this.af1 = this._io.readF8le();
      this.af2 = this._io.readF8le();
      this.toeTow = this._io.readF8le();
      this.toeWn = this._io.readU2le();
      this.tocTow = this._io.readF8le();
      this.tocWn = this._io.readU2le();
      this.valid = this._io.readU1();
      this.healthy = this._io.readU1();
      this.prn = this._io.readU1();
      this.iode = this._io.readU1();
    }

    /**
     * Group delay differential between L1 and L2
     */

    /**
     * Amplitude of the sine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the sine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the cosine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Amplitude of the sine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Mean motion difference
     */

    /**
     * Mean anomaly at reference time
     */

    /**
     * Eccentricity of satellite orbit
     */

    /**
     * Square root of the semi-major axis of orbit
     */

    /**
     * Longitude of ascending node of orbit plane at weekly epoch
     */

    /**
     * Rate of right ascension
     */

    /**
     * Argument of perigee
     */

    /**
     * Inclination
     */

    /**
     * Inclination first derivative
     */

    /**
     * Polynomial clock correction coefficient (clock bias)
     */

    /**
     * Polynomial clock correction coefficient (clock drift)
     */

    /**
     * Polynomial clock correction coefficient (rate of clock drift)
     */

    /**
     * Time of week
     */

    /**
     * Week number
     */

    /**
     * Clock reference time of week
     */

    /**
     * Clock reference week number
     */

    /**
     * Is valid?
     */

    /**
     * Satellite is healthy?
     */

    /**
     * PRN being tracked
     */

    /**
     * Issue of ephemeris data
     */

    return MsgEphemerisDepB;
  })();

  /**
   * The GPS observations message reports all the raw pseudorange and carrier
   * phase observations for the satellites being tracked by the device.
   * Carrier phase observation here is represented as a 40-bit fixed point
   * number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
   * fractional cycles). The observations are be interoperable with 3rd party
   * receivers and conform with typical RTCMv3 GNSS observations.
   */

  var MsgObs = Observation.MsgObs = (function() {
    function MsgObs(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgObs.prototype._read = function() {
      this.header = new ObservationHeader(this._io, this, this._root);
      this.obs = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.obs.push(new PackedObsContent(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Header of a GPS observation message
     */

    /**
     * Pseudorange and carrier phase observation for a satellite being
     * tracked.
     */

    return MsgObs;
  })();

  /**
   * Doppler measurement in Hz represented as a 24-bit fixed point number
   * with Q16.8 layout, i.e. 16-bits of whole doppler and 8-bits of
   * fractional doppler. This doppler is defined as positive for approaching
   * satellites.
   */

  var Doppler = Observation.Doppler = (function() {
    function Doppler(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    Doppler.prototype._read = function() {
      this.i = this._io.readS2le();
      this.f = this._io.readU1();
    }

    /**
     * Doppler whole Hz
     */

    /**
     * Doppler fractional part
     */

    return Doppler;
  })();

  /**
   * The almanac message returns a set of satellite orbit parameters. Almanac
   * data is not very precise and is considered valid for up to several
   * months. Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate
   * information and almanac" for details.
   */

  var MsgAlmanacGloDep = Observation.MsgAlmanacGloDep = (function() {
    function MsgAlmanacGloDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgAlmanacGloDep.prototype._read = function() {
      this.common = new AlmanacCommonContentDep(this._io, this, this._root);
      this.lambdaNa = this._io.readF8le();
      this.tLambdaNa = this._io.readF8le();
      this.i = this._io.readF8le();
      this.t = this._io.readF8le();
      this.tDot = this._io.readF8le();
      this.epsilon = this._io.readF8le();
      this.omega = this._io.readF8le();
    }

    /**
     * Values common for all almanac types
     */

    /**
     * Longitude of the first ascending node of the orbit in PZ-90.02
     * coordinate system
     */

    /**
     * Time of the first ascending node passage
     */

    /**
     * Value of inclination at instant of t_lambda
     */

    /**
     * Value of Draconian period at instant of t_lambda
     */

    /**
     * Rate of change of the Draconian period
     */

    /**
     * Eccentricity at instant of t_lambda
     */

    /**
     * Argument of perigee at instant of t_lambda
     */

    return MsgAlmanacGloDep;
  })();

  /**
   * The almanac message returns a set of satellite orbit parameters. Almanac
   * data is not very precise and is considered valid for up to several
   * months. Please see the Navstar GPS Space Segment/Navigation user
   * interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more
   * details.
   */

  var MsgAlmanacGpsDep = Observation.MsgAlmanacGpsDep = (function() {
    function MsgAlmanacGpsDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgAlmanacGpsDep.prototype._read = function() {
      this.common = new AlmanacCommonContentDep(this._io, this, this._root);
      this.m0 = this._io.readF8le();
      this.ecc = this._io.readF8le();
      this.sqrta = this._io.readF8le();
      this.omega0 = this._io.readF8le();
      this.omegadot = this._io.readF8le();
      this.w = this._io.readF8le();
      this.inc = this._io.readF8le();
      this.af0 = this._io.readF8le();
      this.af1 = this._io.readF8le();
    }

    /**
     * Values common for all almanac types
     */

    /**
     * Mean anomaly at reference time
     */

    /**
     * Eccentricity of satellite orbit
     */

    /**
     * Square root of the semi-major axis of orbit
     */

    /**
     * Longitude of ascending node of orbit plane at weekly epoch
     */

    /**
     * Rate of right ascension
     */

    /**
     * Argument of perigee
     */

    /**
     * Inclination
     */

    /**
     * Polynomial clock correction coefficient (clock bias)
     */

    /**
     * Polynomial clock correction coefficient (clock drift)
     */

    return MsgAlmanacGpsDep;
  })();

  /**
   * Satellite azimuth and elevation.
   */

  var SvAzEl = Observation.SvAzEl = (function() {
    function SvAzEl(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    SvAzEl.prototype._read = function() {
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.az = this._io.readU1();
      this.el = this._io.readS1();
    }

    /**
     * GNSS signal identifier
     */

    /**
     * Azimuth angle (range 0..179)
     */

    /**
     * Elevation angle (range -90..90)
     */

    return SvAzEl;
  })();

  /**
   * The GLONASS L1/L2 Code-Phase biases allows to perform GPS+GLONASS
   * integer ambiguity resolution for baselines with mixed receiver types
   * (e.g. receiver of different manufacturers).
   */

  var MsgGloBiases = Observation.MsgGloBiases = (function() {
    function MsgGloBiases(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgGloBiases.prototype._read = function() {
      this.mask = this._io.readU1();
      this.l1caBias = this._io.readS2le();
      this.l1pBias = this._io.readS2le();
      this.l2caBias = this._io.readS2le();
      this.l2pBias = this._io.readS2le();
    }

    /**
     * GLONASS FDMA signals mask
     */

    /**
     * GLONASS L1 C/A Code-Phase Bias
     */

    /**
     * GLONASS L1 P Code-Phase Bias
     */

    /**
     * GLONASS L2 C/A Code-Phase Bias
     */

    /**
     * GLONASS L2 P Code-Phase Bias
     */

    return MsgGloBiases;
  })();

  /**
   * This observation message has been deprecated in favor of ephemeris
   * message using floats for size reduction.
   */

  var MsgEphemerisSbasDepB = Observation.MsgEphemerisSbasDepB = (function() {
    function MsgEphemerisSbasDepB(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisSbasDepB.prototype._read = function() {
      this.common = new EphemerisCommonContentDepB(this._io, this, this._root);
      this.pos = [];
      for (var i = 0; i < 3; i++) {
        this.pos.push(this._io.readF8le());
      }
      this.vel = [];
      for (var i = 0; i < 3; i++) {
        this.vel.push(this._io.readF8le());
      }
      this.acc = [];
      for (var i = 0; i < 3; i++) {
        this.acc.push(this._io.readF8le());
      }
      this.aGf0 = this._io.readF8le();
      this.aGf1 = this._io.readF8le();
    }

    /**
     * Values common for all ephemeris types
     */

    /**
     * Position of the GEO at time toe
     */

    /**
     * Velocity of the GEO at time toe
     */

    /**
     * Acceleration of the GEO at time toe
     */

    /**
     * Time offset of the GEO clock w.r.t. SBAS Network Time
     */

    /**
     * Drift of the GEO clock w.r.t. SBAS Network Time
     */

    return MsgEphemerisSbasDepB;
  })();

  /**
   * The ephemeris message returns a set of satellite orbit parameters that
   * is used to calculate GPS satellite position, velocity, and clock offset.
   * Please see the Navstar GPS Space Segment/Navigation user interfaces
   * (ICD-GPS-200, Table 20-III) for more details.
   */

  var MsgEphemerisGpsDepE = Observation.MsgEphemerisGpsDepE = (function() {
    function MsgEphemerisGpsDepE(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisGpsDepE.prototype._read = function() {
      this.common = new EphemerisCommonContentDepA(this._io, this, this._root);
      this.tgd = this._io.readF8le();
      this.cRs = this._io.readF8le();
      this.cRc = this._io.readF8le();
      this.cUc = this._io.readF8le();
      this.cUs = this._io.readF8le();
      this.cIc = this._io.readF8le();
      this.cIs = this._io.readF8le();
      this.dn = this._io.readF8le();
      this.m0 = this._io.readF8le();
      this.ecc = this._io.readF8le();
      this.sqrta = this._io.readF8le();
      this.omega0 = this._io.readF8le();
      this.omegadot = this._io.readF8le();
      this.w = this._io.readF8le();
      this.inc = this._io.readF8le();
      this.incDot = this._io.readF8le();
      this.af0 = this._io.readF8le();
      this.af1 = this._io.readF8le();
      this.af2 = this._io.readF8le();
      this.toc = new Gnss.GpsTimeDep(this._io, this, this._root);
      this.iode = this._io.readU1();
      this.iodc = this._io.readU2le();
    }

    /**
     * Values common for all ephemeris types
     */

    /**
     * Group delay differential between L1 and L2
     */

    /**
     * Amplitude of the sine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the sine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the cosine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Amplitude of the sine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Mean motion difference
     */

    /**
     * Mean anomaly at reference time
     */

    /**
     * Eccentricity of satellite orbit
     */

    /**
     * Square root of the semi-major axis of orbit
     */

    /**
     * Longitude of ascending node of orbit plane at weekly epoch
     */

    /**
     * Rate of right ascension
     */

    /**
     * Argument of perigee
     */

    /**
     * Inclination
     */

    /**
     * Inclination first derivative
     */

    /**
     * Polynomial clock correction coefficient (clock bias)
     */

    /**
     * Polynomial clock correction coefficient (clock drift)
     */

    /**
     * Polynomial clock correction coefficient (rate of clock drift)
     */

    /**
     * Clock reference
     */

    /**
     * Issue of ephemeris data
     */

    /**
     * Issue of clock data
     */

    return MsgEphemerisGpsDepE;
  })();

  var MsgGnssCapb = Observation.MsgGnssCapb = (function() {
    function MsgGnssCapb(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgGnssCapb.prototype._read = function() {
      this.tNmct = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.gc = new GnssCapb(this._io, this, this._root);
    }

    /**
     * Navigation Message Correction Table Validity Time
     */

    /**
     * GNSS capabilities masks
     */

    return MsgGnssCapb;
  })();

  /**
   * The almanac message returns a set of satellite orbit parameters. Almanac
   * data is not very precise and is considered valid for up to several
   * months. Please see the Navstar GPS Space Segment/Navigation user
   * interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more
   * details.
   */

  var MsgAlmanacGps = Observation.MsgAlmanacGps = (function() {
    function MsgAlmanacGps(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgAlmanacGps.prototype._read = function() {
      this.common = new AlmanacCommonContent(this._io, this, this._root);
      this.m0 = this._io.readF8le();
      this.ecc = this._io.readF8le();
      this.sqrta = this._io.readF8le();
      this.omega0 = this._io.readF8le();
      this.omegadot = this._io.readF8le();
      this.w = this._io.readF8le();
      this.inc = this._io.readF8le();
      this.af0 = this._io.readF8le();
      this.af1 = this._io.readF8le();
    }

    /**
     * Values common for all almanac types
     */

    /**
     * Mean anomaly at reference time
     */

    /**
     * Eccentricity of satellite orbit
     */

    /**
     * Square root of the semi-major axis of orbit
     */

    /**
     * Longitude of ascending node of orbit plane at weekly epoch
     */

    /**
     * Rate of right ascension
     */

    /**
     * Argument of perigee
     */

    /**
     * Inclination
     */

    /**
     * Polynomial clock correction coefficient (clock bias)
     */

    /**
     * Polynomial clock correction coefficient (clock drift)
     */

    return MsgAlmanacGps;
  })();

  /**
   * The ephemeris message returns a set of satellite orbit parameters that
   * is used to calculate QZSS satellite position, velocity, and clock
   * offset.
   */

  var MsgEphemerisQzss = Observation.MsgEphemerisQzss = (function() {
    function MsgEphemerisQzss(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisQzss.prototype._read = function() {
      this.common = new EphemerisCommonContent(this._io, this, this._root);
      this.tgd = this._io.readF4le();
      this.cRs = this._io.readF4le();
      this.cRc = this._io.readF4le();
      this.cUc = this._io.readF4le();
      this.cUs = this._io.readF4le();
      this.cIc = this._io.readF4le();
      this.cIs = this._io.readF4le();
      this.dn = this._io.readF8le();
      this.m0 = this._io.readF8le();
      this.ecc = this._io.readF8le();
      this.sqrta = this._io.readF8le();
      this.omega0 = this._io.readF8le();
      this.omegadot = this._io.readF8le();
      this.w = this._io.readF8le();
      this.inc = this._io.readF8le();
      this.incDot = this._io.readF8le();
      this.af0 = this._io.readF4le();
      this.af1 = this._io.readF4le();
      this.af2 = this._io.readF4le();
      this.toc = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.iode = this._io.readU1();
      this.iodc = this._io.readU2le();
    }

    /**
     * Values common for all ephemeris types
     */

    /**
     * Group delay differential between L1 and L2
     */

    /**
     * Amplitude of the sine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the sine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the cosine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Amplitude of the sine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Mean motion difference
     */

    /**
     * Mean anomaly at reference time
     */

    /**
     * Eccentricity of satellite orbit
     */

    /**
     * Square root of the semi-major axis of orbit
     */

    /**
     * Longitude of ascending node of orbit plane at weekly epoch
     */

    /**
     * Rate of right ascension
     */

    /**
     * Argument of perigee
     */

    /**
     * Inclination
     */

    /**
     * Inclination first derivative
     */

    /**
     * Polynomial clock correction coefficient (clock bias)
     */

    /**
     * Polynomial clock correction coefficient (clock drift)
     */

    /**
     * Polynomial clock correction coefficient (rate of clock drift)
     */

    /**
     * Clock reference
     */

    /**
     * Issue of ephemeris data
     */

    /**
     * Issue of clock data
     */

    return MsgEphemerisQzss;
  })();

  /**
   * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
   */

  var MsgGroupDelayDepA = Observation.MsgGroupDelayDepA = (function() {
    function MsgGroupDelayDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgGroupDelayDepA.prototype._read = function() {
      this.tOp = new Gnss.GpsTimeDep(this._io, this, this._root);
      this.prn = this._io.readU1();
      this.valid = this._io.readU1();
      this.tgd = this._io.readS2le();
      this.iscL1ca = this._io.readS2le();
      this.iscL2c = this._io.readS2le();
    }

    /**
     * Data Predict Time of Week
     */

    /**
     * Satellite number
     */

    /**
     * bit-field indicating validity of the values, LSB indicating tgd
     * validity etc. 1 = value is valid, 0 = value is not valid.
     */

    return MsgGroupDelayDepA;
  })();

  /**
   * The ephemeris message returns a set of satellite orbit parameters that
   * is used to calculate GPS satellite position, velocity, and clock offset.
   * Please see the Navstar GPS Space Segment/Navigation user interfaces
   * (ICD-GPS-200, Table 20-III) for more details.
   */

  var MsgEphemerisDepC = Observation.MsgEphemerisDepC = (function() {
    function MsgEphemerisDepC(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisDepC.prototype._read = function() {
      this.tgd = this._io.readF8le();
      this.cRs = this._io.readF8le();
      this.cRc = this._io.readF8le();
      this.cUc = this._io.readF8le();
      this.cUs = this._io.readF8le();
      this.cIc = this._io.readF8le();
      this.cIs = this._io.readF8le();
      this.dn = this._io.readF8le();
      this.m0 = this._io.readF8le();
      this.ecc = this._io.readF8le();
      this.sqrta = this._io.readF8le();
      this.omega0 = this._io.readF8le();
      this.omegadot = this._io.readF8le();
      this.w = this._io.readF8le();
      this.inc = this._io.readF8le();
      this.incDot = this._io.readF8le();
      this.af0 = this._io.readF8le();
      this.af1 = this._io.readF8le();
      this.af2 = this._io.readF8le();
      this.toeTow = this._io.readF8le();
      this.toeWn = this._io.readU2le();
      this.tocTow = this._io.readF8le();
      this.tocWn = this._io.readU2le();
      this.valid = this._io.readU1();
      this.healthy = this._io.readU1();
      this.sid = new Gnss.GnssSignalDep(this._io, this, this._root);
      this.iode = this._io.readU1();
      this.iodc = this._io.readU2le();
      this.reserved = this._io.readU4le();
    }

    /**
     * Group delay differential between L1 and L2
     */

    /**
     * Amplitude of the sine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the sine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the cosine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Amplitude of the sine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Mean motion difference
     */

    /**
     * Mean anomaly at reference time
     */

    /**
     * Eccentricity of satellite orbit
     */

    /**
     * Square root of the semi-major axis of orbit
     */

    /**
     * Longitude of ascending node of orbit plane at weekly epoch
     */

    /**
     * Rate of right ascension
     */

    /**
     * Argument of perigee
     */

    /**
     * Inclination
     */

    /**
     * Inclination first derivative
     */

    /**
     * Polynomial clock correction coefficient (clock bias)
     */

    /**
     * Polynomial clock correction coefficient (clock drift)
     */

    /**
     * Polynomial clock correction coefficient (rate of clock drift)
     */

    /**
     * Time of week
     */

    /**
     * Week number
     */

    /**
     * Clock reference time of week
     */

    /**
     * Clock reference week number
     */

    /**
     * Is valid?
     */

    /**
     * Satellite is healthy?
     */

    /**
     * GNSS signal identifier
     */

    /**
     * Issue of ephemeris data
     */

    /**
     * Issue of clock data
     */

    /**
     * Reserved field
     */

    return MsgEphemerisDepC;
  })();

  /**
   * Carrier phase measurement in cycles represented as a 40-bit fixed point
   * number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
   * fractional cycles. This has the opposite sign convention than a typical
   * GPS receiver and the phase has the opposite sign as the pseudorange.
   */

  var CarrierPhaseDepA = Observation.CarrierPhaseDepA = (function() {
    function CarrierPhaseDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    CarrierPhaseDepA.prototype._read = function() {
      this.i = this._io.readS4le();
      this.f = this._io.readU1();
    }

    /**
     * Carrier phase whole cycles
     */

    /**
     * Carrier phase fractional part
     */

    return CarrierPhaseDepA;
  })();

  /**
   * The ephemeris message returns a set of satellite orbit parameters that
   * is used to calculate Galileo satellite position, velocity, and clock
   * offset. Please see the Signal In Space ICD OS SIS ICD, Issue 1.3,
   * December 2016 for more details.
   */

  var MsgEphemerisGal = Observation.MsgEphemerisGal = (function() {
    function MsgEphemerisGal(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisGal.prototype._read = function() {
      this.common = new EphemerisCommonContent(this._io, this, this._root);
      this.bgdE1e5a = this._io.readF4le();
      this.bgdE1e5b = this._io.readF4le();
      this.cRs = this._io.readF4le();
      this.cRc = this._io.readF4le();
      this.cUc = this._io.readF4le();
      this.cUs = this._io.readF4le();
      this.cIc = this._io.readF4le();
      this.cIs = this._io.readF4le();
      this.dn = this._io.readF8le();
      this.m0 = this._io.readF8le();
      this.ecc = this._io.readF8le();
      this.sqrta = this._io.readF8le();
      this.omega0 = this._io.readF8le();
      this.omegadot = this._io.readF8le();
      this.w = this._io.readF8le();
      this.inc = this._io.readF8le();
      this.incDot = this._io.readF8le();
      this.af0 = this._io.readF8le();
      this.af1 = this._io.readF8le();
      this.af2 = this._io.readF4le();
      this.toc = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.iode = this._io.readU2le();
      this.iodc = this._io.readU2le();
      this.source = this._io.readU1();
    }

    /**
     * Values common for all ephemeris types
     */

    /**
     * E1-E5a Broadcast Group Delay
     */

    /**
     * E1-E5b Broadcast Group Delay
     */

    /**
     * Amplitude of the sine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the sine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the cosine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Amplitude of the sine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Mean motion difference
     */

    /**
     * Mean anomaly at reference time
     */

    /**
     * Eccentricity of satellite orbit
     */

    /**
     * Square root of the semi-major axis of orbit
     */

    /**
     * Longitude of ascending node of orbit plane at weekly epoch
     */

    /**
     * Rate of right ascension
     */

    /**
     * Argument of perigee
     */

    /**
     * Inclination
     */

    /**
     * Inclination first derivative
     */

    /**
     * Polynomial clock correction coefficient (clock bias)
     */

    /**
     * Polynomial clock correction coefficient (clock drift)
     */

    /**
     * Polynomial clock correction coefficient (rate of clock drift)
     */

    /**
     * Clock reference
     */

    /**
     * Issue of data (IODnav)
     */

    /**
     * Issue of data (IODnav). Always equal to iode
     */

    /**
     * 0=I/NAV, 1=F/NAV
     */

    return MsgEphemerisGal;
  })();

  /**
   * Pseudorange and carrier phase network corrections for a satellite
   * signal.
   */

  var PackedOsrContent = Observation.PackedOsrContent = (function() {
    function PackedOsrContent(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    PackedOsrContent.prototype._read = function() {
      this.p = this._io.readU4le();
      this.l = new Gnss.CarrierPhase(this._io, this, this._root);
      this.lock = this._io.readU1();
      this.flags = this._io.readU1();
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.ionoStd = this._io.readU2le();
      this.tropoStd = this._io.readU2le();
      this.rangeStd = this._io.readU2le();
    }

    /**
     * Pseudorange observation
     */

    /**
     * Carrier phase observation with typical sign convention.
     */

    /**
     * Lock timer. This value gives an indication of the time for which a
     * signal has maintained continuous phase lock. Whenever a signal has
     * lost and regained lock, this value is reset to zero. It is encoded
     * according to DF402 from the RTCM 10403.2 Amendment 2 specification.
     * Valid values range from 0 to 15 and the most significant nibble is
     * reserved for future use.
     */

    /**
     * Correction flags.
     */

    /**
     * GNSS signal identifier (16 bit)
     */

    /**
     * Slant ionospheric correction standard deviation
     */

    /**
     * Slant tropospheric correction standard deviation
     */

    /**
     * Orbit/clock/bias correction projected on range standard deviation
     */

    return PackedOsrContent;
  })();

  /**
   * The ephemeris message returns a set of satellite orbit parameters that
   * is used to calculate BDS satellite position, velocity, and clock offset.
   * Please see the BeiDou Navigation Satellite System SIS-ICD Version 2.1,
   * Table 5-9 for more details.
   */

  var MsgEphemerisBds = Observation.MsgEphemerisBds = (function() {
    function MsgEphemerisBds(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisBds.prototype._read = function() {
      this.common = new EphemerisCommonContent(this._io, this, this._root);
      this.tgd1 = this._io.readF4le();
      this.tgd2 = this._io.readF4le();
      this.cRs = this._io.readF4le();
      this.cRc = this._io.readF4le();
      this.cUc = this._io.readF4le();
      this.cUs = this._io.readF4le();
      this.cIc = this._io.readF4le();
      this.cIs = this._io.readF4le();
      this.dn = this._io.readF8le();
      this.m0 = this._io.readF8le();
      this.ecc = this._io.readF8le();
      this.sqrta = this._io.readF8le();
      this.omega0 = this._io.readF8le();
      this.omegadot = this._io.readF8le();
      this.w = this._io.readF8le();
      this.inc = this._io.readF8le();
      this.incDot = this._io.readF8le();
      this.af0 = this._io.readF8le();
      this.af1 = this._io.readF4le();
      this.af2 = this._io.readF4le();
      this.toc = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.iode = this._io.readU1();
      this.iodc = this._io.readU2le();
    }

    /**
     * Values common for all ephemeris types
     */

    /**
     * Group delay differential for B1
     */

    /**
     * Group delay differential for B2
     */

    /**
     * Amplitude of the sine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the sine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the cosine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Amplitude of the sine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Mean motion difference
     */

    /**
     * Mean anomaly at reference time
     */

    /**
     * Eccentricity of satellite orbit
     */

    /**
     * Square root of the semi-major axis of orbit
     */

    /**
     * Longitude of ascending node of orbit plane at weekly epoch
     */

    /**
     * Rate of right ascension
     */

    /**
     * Argument of perigee
     */

    /**
     * Inclination
     */

    /**
     * Inclination first derivative
     */

    /**
     * Polynomial clock correction coefficient (clock bias)
     */

    /**
     * Polynomial clock correction coefficient (clock drift)
     */

    /**
     * Polynomial clock correction coefficient (rate of clock drift)
     */

    /**
     * Clock reference
     */

    /**
     * Issue of ephemeris data
     * Calculated from the navigation data parameter t_oe per RTCM/CSNO
     * recommendation: IODE = mod (t_oe / 720, 240)
     */

    /**
     * Issue of clock data
     * Calculated from the navigation data parameter t_oe per RTCM/CSNO
     * recommendation: IODE = mod (t_oc / 720, 240)
     */

    return MsgEphemerisBds;
  })();

  /**
   * This observation message has been deprecated in favor of ephemeris
   * message using floats for size reduction.
   */

  var MsgEphemerisGpsDepF = Observation.MsgEphemerisGpsDepF = (function() {
    function MsgEphemerisGpsDepF(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisGpsDepF.prototype._read = function() {
      this.common = new EphemerisCommonContentDepB(this._io, this, this._root);
      this.tgd = this._io.readF8le();
      this.cRs = this._io.readF8le();
      this.cRc = this._io.readF8le();
      this.cUc = this._io.readF8le();
      this.cUs = this._io.readF8le();
      this.cIc = this._io.readF8le();
      this.cIs = this._io.readF8le();
      this.dn = this._io.readF8le();
      this.m0 = this._io.readF8le();
      this.ecc = this._io.readF8le();
      this.sqrta = this._io.readF8le();
      this.omega0 = this._io.readF8le();
      this.omegadot = this._io.readF8le();
      this.w = this._io.readF8le();
      this.inc = this._io.readF8le();
      this.incDot = this._io.readF8le();
      this.af0 = this._io.readF8le();
      this.af1 = this._io.readF8le();
      this.af2 = this._io.readF8le();
      this.toc = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.iode = this._io.readU1();
      this.iodc = this._io.readU2le();
    }

    /**
     * Values common for all ephemeris types
     */

    /**
     * Group delay differential between L1 and L2
     */

    /**
     * Amplitude of the sine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the sine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the cosine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Amplitude of the sine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Mean motion difference
     */

    /**
     * Mean anomaly at reference time
     */

    /**
     * Eccentricity of satellite orbit
     */

    /**
     * Square root of the semi-major axis of orbit
     */

    /**
     * Longitude of ascending node of orbit plane at weekly epoch
     */

    /**
     * Rate of right ascension
     */

    /**
     * Argument of perigee
     */

    /**
     * Inclination
     */

    /**
     * Inclination first derivative
     */

    /**
     * Polynomial clock correction coefficient (clock bias)
     */

    /**
     * Polynomial clock correction coefficient (clock drift)
     */

    /**
     * Polynomial clock correction coefficient (rate of clock drift)
     */

    /**
     * Clock reference
     */

    /**
     * Issue of ephemeris data
     */

    /**
     * Issue of clock data
     */

    return MsgEphemerisGpsDepF;
  })();

  /**
   * Header of a GNSS observation message.
   */

  var ObservationHeader = Observation.ObservationHeader = (function() {
    function ObservationHeader(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    ObservationHeader.prototype._read = function() {
      this.t = new Gnss.GpsTime(this._io, this, this._root);
      this.nObs = this._io.readU1();
    }

    /**
     * GNSS time of this observation
     */

    /**
     * Total number of observations. First nibble is the size of the
     * sequence (n), second nibble is the zero-indexed counter (ith packet
     * of n)
     */

    return ObservationHeader;
  })();

  var MsgEphemerisSbasDepA = Observation.MsgEphemerisSbasDepA = (function() {
    function MsgEphemerisSbasDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisSbasDepA.prototype._read = function() {
      this.common = new EphemerisCommonContentDepA(this._io, this, this._root);
      this.pos = [];
      for (var i = 0; i < 3; i++) {
        this.pos.push(this._io.readF8le());
      }
      this.vel = [];
      for (var i = 0; i < 3; i++) {
        this.vel.push(this._io.readF8le());
      }
      this.acc = [];
      for (var i = 0; i < 3; i++) {
        this.acc.push(this._io.readF8le());
      }
      this.aGf0 = this._io.readF8le();
      this.aGf1 = this._io.readF8le();
    }

    /**
     * Values common for all ephemeris types
     */

    /**
     * Position of the GEO at time toe
     */

    /**
     * Velocity of the GEO at time toe
     */

    /**
     * Acceleration of the GEO at time toe
     */

    /**
     * Time offset of the GEO clock w.r.t. SBAS Network Time
     */

    /**
     * Drift of the GEO clock w.r.t. SBAS Network Time
     */

    return MsgEphemerisSbasDepA;
  })();

  /**
   * Pseudorange and carrier phase observation for a satellite being tracked.
   * The observations are interoperable with 3rd party receivers and conform
   * with typical RTCM 3.1 message GPS/GLO observations.
   * 
   * Carrier phase observations are not guaranteed to be aligned to the RINEX
   * 3 or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are
   * currently performed.
   */

  var PackedObsContent = Observation.PackedObsContent = (function() {
    function PackedObsContent(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    PackedObsContent.prototype._read = function() {
      this.p = this._io.readU4le();
      this.l = new Gnss.CarrierPhase(this._io, this, this._root);
      this.d = new Doppler(this._io, this, this._root);
      this.cn0 = this._io.readU1();
      this.lock = this._io.readU1();
      this.flags = this._io.readU1();
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
    }

    /**
     * Pseudorange observation
     */

    /**
     * Carrier phase observation with typical sign convention.
     */

    /**
     * Doppler observation with typical sign convention.
     */

    /**
     * Carrier-to-Noise density.  Zero implies invalid cn0.
     */

    /**
     * Lock timer. This value gives an indication of the time for which a
     * signal has maintained continuous phase lock. Whenever a signal has
     * lost and regained lock, this value is reset to zero. It is encoded
     * according to DF402 from the RTCM 10403.2 Amendment 2 specification.
     * Valid values range from 0 to 15 and the most significant nibble is
     * reserved for future use.
     */

    /**
     * Measurement status flags. A bit field of flags providing the status
     * of this observation.  If this field is 0 it means only the Cn0
     * estimate for the signal is valid.
     */

    /**
     * GNSS signal identifier (16 bit)
     */

    return PackedObsContent;
  })();

  /**
   * The base station position message is the position reported by the base
   * station itself in absolute Earth Centered Earth Fixed coordinates. It is
   * used for pseudo-absolute RTK positioning, and is required to be a high-
   * accuracy surveyed location of the base station. Any error here will
   * result in an error in the pseudo-absolute position output.
   */

  var MsgBasePosEcef = Observation.MsgBasePosEcef = (function() {
    function MsgBasePosEcef(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgBasePosEcef.prototype._read = function() {
      this.x = this._io.readF8le();
      this.y = this._io.readF8le();
      this.z = this._io.readF8le();
    }

    /**
     * ECEF X coordinate
     */

    /**
     * ECEF Y coordinate
     */

    /**
     * ECEF Z coordinate
     */

    return MsgBasePosEcef;
  })();

  /**
   * The ephemeris message returns a set of satellite orbit parameters that
   * is used to calculate GLO satellite position, velocity, and clock offset.
   * Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
   * immediate information (ephemeris parameters)" for more details.
   */

  var MsgEphemerisGloDepA = Observation.MsgEphemerisGloDepA = (function() {
    function MsgEphemerisGloDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisGloDepA.prototype._read = function() {
      this.common = new EphemerisCommonContentDepA(this._io, this, this._root);
      this.gamma = this._io.readF8le();
      this.tau = this._io.readF8le();
      this.pos = [];
      for (var i = 0; i < 3; i++) {
        this.pos.push(this._io.readF8le());
      }
      this.vel = [];
      for (var i = 0; i < 3; i++) {
        this.vel.push(this._io.readF8le());
      }
      this.acc = [];
      for (var i = 0; i < 3; i++) {
        this.acc.push(this._io.readF8le());
      }
    }

    /**
     * Values common for all ephemeris types
     */

    /**
     * Relative deviation of predicted carrier frequency from nominal
     */

    /**
     * Correction to the SV time
     */

    /**
     * Position of the SV at tb in PZ-90.02 coordinates system
     */

    /**
     * Velocity vector of the SV at tb in PZ-90.02 coordinates system
     */

    /**
     * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
     */

    return MsgEphemerisGloDepA;
  })();

  /**
   * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
   */

  var MsgGroupDelay = Observation.MsgGroupDelay = (function() {
    function MsgGroupDelay(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgGroupDelay.prototype._read = function() {
      this.tOp = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.valid = this._io.readU1();
      this.tgd = this._io.readS2le();
      this.iscL1ca = this._io.readS2le();
      this.iscL2c = this._io.readS2le();
    }

    /**
     * Data Predict Time of Week
     */

    /**
     * GNSS signal identifier
     */

    /**
     * bit-field indicating validity of the values, LSB indicating tgd
     * validity etc. 1 = value is valid, 0 = value is not valid.
     */

    return MsgGroupDelay;
  })();

  /**
   * The almanac message returns a set of satellite orbit parameters. Almanac
   * data is not very precise and is considered valid for up to several
   * months. Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate
   * information and almanac" for details.
   */

  var MsgAlmanacGlo = Observation.MsgAlmanacGlo = (function() {
    function MsgAlmanacGlo(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgAlmanacGlo.prototype._read = function() {
      this.common = new AlmanacCommonContent(this._io, this, this._root);
      this.lambdaNa = this._io.readF8le();
      this.tLambdaNa = this._io.readF8le();
      this.i = this._io.readF8le();
      this.t = this._io.readF8le();
      this.tDot = this._io.readF8le();
      this.epsilon = this._io.readF8le();
      this.omega = this._io.readF8le();
    }

    /**
     * Values common for all almanac types
     */

    /**
     * Longitude of the first ascending node of the orbit in PZ-90.02
     * coordinate system
     */

    /**
     * Time of the first ascending node passage
     */

    /**
     * Value of inclination at instant of t_lambda
     */

    /**
     * Value of Draconian period at instant of t_lambda
     */

    /**
     * Rate of change of the Draconian period
     */

    /**
     * Eccentricity at instant of t_lambda
     */

    /**
     * Argument of perigee at instant of t_lambda
     */

    return MsgAlmanacGlo;
  })();

  /**
   * This observation message has been deprecated in favor of an ephemeris
   * message with explicit source of NAV data.
   */

  var MsgEphemerisGalDepA = Observation.MsgEphemerisGalDepA = (function() {
    function MsgEphemerisGalDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisGalDepA.prototype._read = function() {
      this.common = new EphemerisCommonContent(this._io, this, this._root);
      this.bgdE1e5a = this._io.readF4le();
      this.bgdE1e5b = this._io.readF4le();
      this.cRs = this._io.readF4le();
      this.cRc = this._io.readF4le();
      this.cUc = this._io.readF4le();
      this.cUs = this._io.readF4le();
      this.cIc = this._io.readF4le();
      this.cIs = this._io.readF4le();
      this.dn = this._io.readF8le();
      this.m0 = this._io.readF8le();
      this.ecc = this._io.readF8le();
      this.sqrta = this._io.readF8le();
      this.omega0 = this._io.readF8le();
      this.omegadot = this._io.readF8le();
      this.w = this._io.readF8le();
      this.inc = this._io.readF8le();
      this.incDot = this._io.readF8le();
      this.af0 = this._io.readF8le();
      this.af1 = this._io.readF8le();
      this.af2 = this._io.readF4le();
      this.toc = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.iode = this._io.readU2le();
      this.iodc = this._io.readU2le();
    }

    /**
     * Values common for all ephemeris types
     */

    /**
     * E1-E5a Broadcast Group Delay
     */

    /**
     * E1-E5b Broadcast Group Delay
     */

    /**
     * Amplitude of the sine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the sine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the cosine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Amplitude of the sine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Mean motion difference
     */

    /**
     * Mean anomaly at reference time
     */

    /**
     * Eccentricity of satellite orbit
     */

    /**
     * Square root of the semi-major axis of orbit
     */

    /**
     * Longitude of ascending node of orbit plane at weekly epoch
     */

    /**
     * Rate of right ascension
     */

    /**
     * Argument of perigee
     */

    /**
     * Inclination
     */

    /**
     * Inclination first derivative
     */

    /**
     * Polynomial clock correction coefficient (clock bias)
     */

    /**
     * Polynomial clock correction coefficient (clock drift)
     */

    /**
     * Polynomial clock correction coefficient (rate of clock drift)
     */

    /**
     * Clock reference
     */

    /**
     * Issue of data (IODnav)
     */

    /**
     * Issue of data (IODnav). Always equal to iode
     */

    return MsgEphemerisGalDepA;
  })();

  /**
   * This observation message has been deprecated in favor of observations
   * that are more interoperable. This message should be used for
   * observations referenced to a nominal pseudorange which are not
   * interoperable with most 3rd party GNSS receivers or typical RTCMv3
   * observations.
   */

  var MsgObsDepB = Observation.MsgObsDepB = (function() {
    function MsgObsDepB(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgObsDepB.prototype._read = function() {
      this.header = new ObservationHeaderDep(this._io, this, this._root);
      this.obs = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.obs.push(new PackedObsContentDepB(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Header of a GPS observation message
     */

    /**
     * Pseudorange and carrier phase observation for a satellite being
     * tracked.
     */

    return MsgObsDepB;
  })();

  /**
   * Deprecated.
   */

  var PackedObsContentDepA = Observation.PackedObsContentDepA = (function() {
    function PackedObsContentDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    PackedObsContentDepA.prototype._read = function() {
      this.p = this._io.readU4le();
      this.l = new CarrierPhaseDepA(this._io, this, this._root);
      this.cn0 = this._io.readU1();
      this.lock = this._io.readU2le();
      this.prn = this._io.readU1();
    }

    /**
     * Pseudorange observation
     */

    /**
     * Carrier phase observation with opposite sign from typical convention
     */

    /**
     * Carrier-to-Noise density
     */

    /**
     * Lock indicator. This value changes whenever a satellite signal has
     * lost and regained lock, indicating that the carrier phase ambiguity
     * may have changed.
     */

    /**
     * PRN-1 identifier of the satellite signal
     */

    return PackedObsContentDepA;
  })();

  /**
   * The ephemeris message returns a set of satellite orbit parameters that
   * is used to calculate GLO satellite position, velocity, and clock offset.
   * Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
   * immediate information (ephemeris parameters)" for more details.
   */

  var MsgEphemerisGlo = Observation.MsgEphemerisGlo = (function() {
    function MsgEphemerisGlo(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisGlo.prototype._read = function() {
      this.common = new EphemerisCommonContent(this._io, this, this._root);
      this.gamma = this._io.readF4le();
      this.tau = this._io.readF4le();
      this.dTau = this._io.readF4le();
      this.pos = [];
      for (var i = 0; i < 3; i++) {
        this.pos.push(this._io.readF8le());
      }
      this.vel = [];
      for (var i = 0; i < 3; i++) {
        this.vel.push(this._io.readF8le());
      }
      this.acc = [];
      for (var i = 0; i < 3; i++) {
        this.acc.push(this._io.readF4le());
      }
      this.fcn = this._io.readU1();
      this.iod = this._io.readU1();
    }

    /**
     * Values common for all ephemeris types
     */

    /**
     * Relative deviation of predicted carrier frequency from nominal
     */

    /**
     * Correction to the SV time
     */

    /**
     * Equipment delay between L1 and L2
     */

    /**
     * Position of the SV at tb in PZ-90.02 coordinates system
     */

    /**
     * Velocity vector of the SV at tb in PZ-90.02 coordinates system
     */

    /**
     * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
     */

    /**
     * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
     */

    /**
     * Issue of data. Equal to the 7 bits of the immediate data word t_b
     */

    return MsgEphemerisGlo;
  })();

  /**
   * The ionospheric parameters which allow the "L1 only" or "L2 only" user
   * to utilize the ionospheric model for computation of the ionospheric
   * delay. Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
   */

  var MsgIono = Observation.MsgIono = (function() {
    function MsgIono(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgIono.prototype._read = function() {
      this.tNmct = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.a0 = this._io.readF8le();
      this.a1 = this._io.readF8le();
      this.a2 = this._io.readF8le();
      this.a3 = this._io.readF8le();
      this.b0 = this._io.readF8le();
      this.b1 = this._io.readF8le();
      this.b2 = this._io.readF8le();
      this.b3 = this._io.readF8le();
    }

    /**
     * Navigation Message Correction Table Validity Time
     */

    return MsgIono;
  })();

  /**
   * The ephemeris message returns a set of satellite orbit parameters that
   * is used to calculate GPS satellite position, velocity, and clock offset.
   * Please see the Navstar GPS Space Segment/Navigation user interfaces
   * (ICD-GPS-200, Table 20-III) for more details.
   */

  var MsgEphemerisDepD = Observation.MsgEphemerisDepD = (function() {
    function MsgEphemerisDepD(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisDepD.prototype._read = function() {
      this.tgd = this._io.readF8le();
      this.cRs = this._io.readF8le();
      this.cRc = this._io.readF8le();
      this.cUc = this._io.readF8le();
      this.cUs = this._io.readF8le();
      this.cIc = this._io.readF8le();
      this.cIs = this._io.readF8le();
      this.dn = this._io.readF8le();
      this.m0 = this._io.readF8le();
      this.ecc = this._io.readF8le();
      this.sqrta = this._io.readF8le();
      this.omega0 = this._io.readF8le();
      this.omegadot = this._io.readF8le();
      this.w = this._io.readF8le();
      this.inc = this._io.readF8le();
      this.incDot = this._io.readF8le();
      this.af0 = this._io.readF8le();
      this.af1 = this._io.readF8le();
      this.af2 = this._io.readF8le();
      this.toeTow = this._io.readF8le();
      this.toeWn = this._io.readU2le();
      this.tocTow = this._io.readF8le();
      this.tocWn = this._io.readU2le();
      this.valid = this._io.readU1();
      this.healthy = this._io.readU1();
      this.sid = new Gnss.GnssSignalDep(this._io, this, this._root);
      this.iode = this._io.readU1();
      this.iodc = this._io.readU2le();
      this.reserved = this._io.readU4le();
    }

    /**
     * Group delay differential between L1 and L2
     */

    /**
     * Amplitude of the sine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the sine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the cosine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Amplitude of the sine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Mean motion difference
     */

    /**
     * Mean anomaly at reference time
     */

    /**
     * Eccentricity of satellite orbit
     */

    /**
     * Square root of the semi-major axis of orbit
     */

    /**
     * Longitude of ascending node of orbit plane at weekly epoch
     */

    /**
     * Rate of right ascension
     */

    /**
     * Argument of perigee
     */

    /**
     * Inclination
     */

    /**
     * Inclination first derivative
     */

    /**
     * Polynomial clock correction coefficient (clock bias)
     */

    /**
     * Polynomial clock correction coefficient (clock drift)
     */

    /**
     * Polynomial clock correction coefficient (rate of clock drift)
     */

    /**
     * Time of week
     */

    /**
     * Week number
     */

    /**
     * Clock reference time of week
     */

    /**
     * Clock reference week number
     */

    /**
     * Is valid?
     */

    /**
     * Satellite is healthy?
     */

    /**
     * GNSS signal identifier
     */

    /**
     * Issue of ephemeris data
     */

    /**
     * Issue of clock data
     */

    /**
     * Reserved field
     */

    return MsgEphemerisDepD;
  })();

  /**
   * The ephemeris message returns a set of satellite orbit parameters that
   * is used to calculate GPS satellite position, velocity, and clock offset.
   * Please see the Navstar GPS Space Segment/Navigation user interfaces
   * (ICD-GPS-200, Table 20-III) for more details.
   */

  var MsgEphemerisGps = Observation.MsgEphemerisGps = (function() {
    function MsgEphemerisGps(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisGps.prototype._read = function() {
      this.common = new EphemerisCommonContent(this._io, this, this._root);
      this.tgd = this._io.readF4le();
      this.cRs = this._io.readF4le();
      this.cRc = this._io.readF4le();
      this.cUc = this._io.readF4le();
      this.cUs = this._io.readF4le();
      this.cIc = this._io.readF4le();
      this.cIs = this._io.readF4le();
      this.dn = this._io.readF8le();
      this.m0 = this._io.readF8le();
      this.ecc = this._io.readF8le();
      this.sqrta = this._io.readF8le();
      this.omega0 = this._io.readF8le();
      this.omegadot = this._io.readF8le();
      this.w = this._io.readF8le();
      this.inc = this._io.readF8le();
      this.incDot = this._io.readF8le();
      this.af0 = this._io.readF4le();
      this.af1 = this._io.readF4le();
      this.af2 = this._io.readF4le();
      this.toc = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.iode = this._io.readU1();
      this.iodc = this._io.readU2le();
    }

    /**
     * Values common for all ephemeris types
     */

    /**
     * Group delay differential between L1 and L2
     */

    /**
     * Amplitude of the sine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the sine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the cosine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Amplitude of the sine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Mean motion difference
     */

    /**
     * Mean anomaly at reference time
     */

    /**
     * Eccentricity of satellite orbit
     */

    /**
     * Square root of the semi-major axis of orbit
     */

    /**
     * Longitude of ascending node of orbit plane at weekly epoch
     */

    /**
     * Rate of right ascension
     */

    /**
     * Argument of perigee
     */

    /**
     * Inclination
     */

    /**
     * Inclination first derivative
     */

    /**
     * Polynomial clock correction coefficient (clock bias)
     */

    /**
     * Polynomial clock correction coefficient (clock drift)
     */

    /**
     * Polynomial clock correction coefficient (rate of clock drift)
     */

    /**
     * Clock reference
     */

    /**
     * Issue of ephemeris data
     */

    /**
     * Issue of clock data
     */

    return MsgEphemerisGps;
  })();

  /**
   * The base station position message is the position reported by the base
   * station itself. It is used for pseudo-absolute RTK positioning, and is
   * required to be a high-accuracy surveyed location of the base station.
   * Any error here will result in an error in the pseudo-absolute position
   * output.
   */

  var MsgBasePosLlh = Observation.MsgBasePosLlh = (function() {
    function MsgBasePosLlh(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgBasePosLlh.prototype._read = function() {
      this.lat = this._io.readF8le();
      this.lon = this._io.readF8le();
      this.height = this._io.readF8le();
    }

    /**
     * Latitude
     */

    /**
     * Longitude
     */

    /**
     * Height
     */

    return MsgBasePosLlh;
  })();

  var AlmanacCommonContent = Observation.AlmanacCommonContent = (function() {
    function AlmanacCommonContent(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    AlmanacCommonContent.prototype._read = function() {
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.toa = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.ura = this._io.readF8le();
      this.fitInterval = this._io.readU4le();
      this.valid = this._io.readU1();
      this.healthBits = this._io.readU1();
    }

    /**
     * GNSS signal identifier
     */

    /**
     * Reference time of almanac
     */

    /**
     * User Range Accuracy
     */

    /**
     * Curve fit interval
     */

    /**
     * Status of almanac, 1 = valid, 0 = invalid
     */

    /**
     * Satellite health status for GPS:
     *   - bits 5-7: NAV data health status. See IS-GPS-200H
     *     Table 20-VII: NAV Data Health Indications.
     *   - bits 0-4: Signal health status. See IS-GPS-200H
     *     Table 20-VIII. Codes for Health of SV Signal
     *     Components.
     * Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for
     * details):
     *   - bit 0: C(n), "unhealthy" flag that is transmitted within
     *     non-immediate data and indicates overall constellation status
     *     at the moment of almanac uploading.
     *     '0' indicates malfunction of n-satellite.
     *     '1' indicates that n-satellite is operational.
     *   - bit 1: Bn(ln), '0' indicates the satellite is operational
     *     and suitable for navigation.
     */

    return AlmanacCommonContent;
  })();

  /**
   * The OSR message contains network corrections in an observation-like
   * format.
   */

  var MsgOsr = Observation.MsgOsr = (function() {
    function MsgOsr(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgOsr.prototype._read = function() {
      this.header = new ObservationHeader(this._io, this, this._root);
      this.obs = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.obs.push(new PackedOsrContent(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Header of a GPS observation message
     */

    /**
     * Network correction for a satellite signal.
     */

    return MsgOsr;
  })();

  /**
   * The ephemeris message returns a set of satellite orbit parameters that
   * is used to calculate GLO satellite position, velocity, and clock offset.
   * Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
   * immediate information (ephemeris parameters)" for more details.
   */

  var MsgEphemerisGloDepC = Observation.MsgEphemerisGloDepC = (function() {
    function MsgEphemerisGloDepC(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisGloDepC.prototype._read = function() {
      this.common = new EphemerisCommonContentDepB(this._io, this, this._root);
      this.gamma = this._io.readF8le();
      this.tau = this._io.readF8le();
      this.dTau = this._io.readF8le();
      this.pos = [];
      for (var i = 0; i < 3; i++) {
        this.pos.push(this._io.readF8le());
      }
      this.vel = [];
      for (var i = 0; i < 3; i++) {
        this.vel.push(this._io.readF8le());
      }
      this.acc = [];
      for (var i = 0; i < 3; i++) {
        this.acc.push(this._io.readF8le());
      }
      this.fcn = this._io.readU1();
    }

    /**
     * Values common for all ephemeris types
     */

    /**
     * Relative deviation of predicted carrier frequency from nominal
     */

    /**
     * Correction to the SV time
     */

    /**
     * Equipment delay between L1 and L2
     */

    /**
     * Position of the SV at tb in PZ-90.02 coordinates system
     */

    /**
     * Velocity vector of the SV at tb in PZ-90.02 coordinates system
     */

    /**
     * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
     */

    /**
     * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
     */

    return MsgEphemerisGloDepC;
  })();

  /**
   * The ephemeris message returns a set of satellite orbit parameters that
   * is used to calculate GLO satellite position, velocity, and clock offset.
   * Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
   * immediate information (ephemeris parameters)" for more details.
   */

  var MsgEphemerisGloDepB = Observation.MsgEphemerisGloDepB = (function() {
    function MsgEphemerisGloDepB(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisGloDepB.prototype._read = function() {
      this.common = new EphemerisCommonContentDepB(this._io, this, this._root);
      this.gamma = this._io.readF8le();
      this.tau = this._io.readF8le();
      this.pos = [];
      for (var i = 0; i < 3; i++) {
        this.pos.push(this._io.readF8le());
      }
      this.vel = [];
      for (var i = 0; i < 3; i++) {
        this.vel.push(this._io.readF8le());
      }
      this.acc = [];
      for (var i = 0; i < 3; i++) {
        this.acc.push(this._io.readF8le());
      }
    }

    /**
     * Values common for all ephemeris types
     */

    /**
     * Relative deviation of predicted carrier frequency from nominal
     */

    /**
     * Correction to the SV time
     */

    /**
     * Position of the SV at tb in PZ-90.02 coordinates system
     */

    /**
     * Velocity vector of the SV at tb in PZ-90.02 coordinates system
     */

    /**
     * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
     */

    return MsgEphemerisGloDepB;
  })();

  /**
   * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
   */

  var MsgSvConfigurationGpsDep = Observation.MsgSvConfigurationGpsDep = (function() {
    function MsgSvConfigurationGpsDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSvConfigurationGpsDep.prototype._read = function() {
      this.tNmct = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.l2cMask = this._io.readU4le();
    }

    /**
     * Navigation Message Correction Table Validity Time
     */

    /**
     * L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
     */

    return MsgSvConfigurationGpsDep;
  })();

  var MsgEphemerisSbas = Observation.MsgEphemerisSbas = (function() {
    function MsgEphemerisSbas(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisSbas.prototype._read = function() {
      this.common = new EphemerisCommonContent(this._io, this, this._root);
      this.pos = [];
      for (var i = 0; i < 3; i++) {
        this.pos.push(this._io.readF8le());
      }
      this.vel = [];
      for (var i = 0; i < 3; i++) {
        this.vel.push(this._io.readF4le());
      }
      this.acc = [];
      for (var i = 0; i < 3; i++) {
        this.acc.push(this._io.readF4le());
      }
      this.aGf0 = this._io.readF4le();
      this.aGf1 = this._io.readF4le();
    }

    /**
     * Values common for all ephemeris types
     */

    /**
     * Position of the GEO at time toe
     */

    /**
     * Velocity of the GEO at time toe
     */

    /**
     * Acceleration of the GEO at time toe
     */

    /**
     * Time offset of the GEO clock w.r.t. SBAS Network Time
     */

    /**
     * Drift of the GEO clock w.r.t. SBAS Network Time
     */

    return MsgEphemerisSbas;
  })();

  /**
   * Pseudorange and carrier phase observation for a satellite being tracked.
   * Pseudoranges are referenced to a nominal pseudorange.
   */

  var PackedObsContentDepB = Observation.PackedObsContentDepB = (function() {
    function PackedObsContentDepB(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    PackedObsContentDepB.prototype._read = function() {
      this.p = this._io.readU4le();
      this.l = new CarrierPhaseDepA(this._io, this, this._root);
      this.cn0 = this._io.readU1();
      this.lock = this._io.readU2le();
      this.sid = new Gnss.GnssSignalDep(this._io, this, this._root);
    }

    /**
     * Pseudorange observation
     */

    /**
     * Carrier phase observation with opposite sign from typical
     * convention.
     */

    /**
     * Carrier-to-Noise density
     */

    /**
     * Lock indicator. This value changes whenever a satellite signal has
     * lost and regained lock, indicating that the carrier phase ambiguity
     * may have changed.
     */

    /**
     * GNSS signal identifier
     */

    return PackedObsContentDepB;
  })();

  /**
   * The GPS observations message reports all the raw pseudorange and carrier
   * phase observations for the satellites being tracked by the device.
   * Carrier phase observation here is represented as a 40-bit fixed point
   * number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
   * fractional cycles). The observations are interoperable with 3rd party
   * receivers and conform with typical RTCMv3 GNSS observations.
   */

  var MsgObsDepC = Observation.MsgObsDepC = (function() {
    function MsgObsDepC(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgObsDepC.prototype._read = function() {
      this.header = new ObservationHeaderDep(this._io, this, this._root);
      this.obs = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.obs.push(new PackedObsContentDepC(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Header of a GPS observation message
     */

    /**
     * Pseudorange and carrier phase observation for a satellite being
     * tracked.
     */

    return MsgObsDepC;
  })();

  /**
   * Deprecated.
   */

  var MsgEphemerisDepA = Observation.MsgEphemerisDepA = (function() {
    function MsgEphemerisDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEphemerisDepA.prototype._read = function() {
      this.tgd = this._io.readF8le();
      this.cRs = this._io.readF8le();
      this.cRc = this._io.readF8le();
      this.cUc = this._io.readF8le();
      this.cUs = this._io.readF8le();
      this.cIc = this._io.readF8le();
      this.cIs = this._io.readF8le();
      this.dn = this._io.readF8le();
      this.m0 = this._io.readF8le();
      this.ecc = this._io.readF8le();
      this.sqrta = this._io.readF8le();
      this.omega0 = this._io.readF8le();
      this.omegadot = this._io.readF8le();
      this.w = this._io.readF8le();
      this.inc = this._io.readF8le();
      this.incDot = this._io.readF8le();
      this.af0 = this._io.readF8le();
      this.af1 = this._io.readF8le();
      this.af2 = this._io.readF8le();
      this.toeTow = this._io.readF8le();
      this.toeWn = this._io.readU2le();
      this.tocTow = this._io.readF8le();
      this.tocWn = this._io.readU2le();
      this.valid = this._io.readU1();
      this.healthy = this._io.readU1();
      this.prn = this._io.readU1();
    }

    /**
     * Group delay differential between L1 and L2
     */

    /**
     * Amplitude of the sine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the orbit radius
     */

    /**
     * Amplitude of the cosine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the sine harmonic correction term to the argument of
     * latitude
     */

    /**
     * Amplitude of the cosine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Amplitude of the sine harmonic correction term to the angle of
     * inclination
     */

    /**
     * Mean motion difference
     */

    /**
     * Mean anomaly at reference time
     */

    /**
     * Eccentricity of satellite orbit
     */

    /**
     * Square root of the semi-major axis of orbit
     */

    /**
     * Longitude of ascending node of orbit plane at weekly epoch
     */

    /**
     * Rate of right ascension
     */

    /**
     * Argument of perigee
     */

    /**
     * Inclination
     */

    /**
     * Inclination first derivative
     */

    /**
     * Polynomial clock correction coefficient (clock bias)
     */

    /**
     * Polynomial clock correction coefficient (clock drift)
     */

    /**
     * Polynomial clock correction coefficient (rate of clock drift)
     */

    /**
     * Time of week
     */

    /**
     * Week number
     */

    /**
     * Clock reference time of week
     */

    /**
     * Clock reference week number
     */

    /**
     * Is valid?
     */

    /**
     * Satellite is healthy?
     */

    /**
     * PRN being tracked
     */

    return MsgEphemerisDepA;
  })();

  var EphemerisCommonContentDepB = Observation.EphemerisCommonContentDepB = (function() {
    function EphemerisCommonContentDepB(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    EphemerisCommonContentDepB.prototype._read = function() {
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.toe = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.ura = this._io.readF8le();
      this.fitInterval = this._io.readU4le();
      this.valid = this._io.readU1();
      this.healthBits = this._io.readU1();
    }

    /**
     * GNSS signal identifier (16 bit)
     */

    /**
     * Time of Ephemerides
     */

    /**
     * User Range Accuracy
     */

    /**
     * Curve fit interval
     */

    /**
     * Status of ephemeris, 1 = valid, 0 = invalid
     */

    /**
     * Satellite health status.
     * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
     * Others: 0 = valid, non-zero = invalid
     */

    return EphemerisCommonContentDepB;
  })();

  return Observation;
})();
return Observation;
}));
