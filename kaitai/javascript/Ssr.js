// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Ssr = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Ssr = (function() {
  function Ssr(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Ssr.prototype._read = function() {
  }

  /**
   * Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes
   * an RLE encoded validity list.
   */

  var GridDefinitionHeaderDepA = Ssr.GridDefinitionHeaderDepA = (function() {
    function GridDefinitionHeaderDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    GridDefinitionHeaderDepA.prototype._read = function() {
      this.regionSizeInverse = this._io.readU1();
      this.areaWidth = this._io.readU2le();
      this.latNwCornerEnc = this._io.readU2le();
      this.lonNwCornerEnc = this._io.readU2le();
      this.numMsgs = this._io.readU1();
      this.seqNum = this._io.readU1();
    }

    /**
     * region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
     */

    /**
     * grid height (deg) = grid width (deg) = area_width / region_size 0 is
     * an invalid value.
     */

    /**
     * North-West corner latitude (deg) = region_size * lat_nw_corner_enc -
     * 90
     */

    /**
     * North-West corner longitude (deg) = region_size * lon_nw_corner_enc
     * - 180
     */

    /**
     * Number of messages in the dataset
     */

    /**
     * Position of this message in the dataset
     */

    return GridDefinitionHeaderDepA;
  })();

  /**
   * STEC residual for the given satellite at the grid point.
   */

  var StecResidualNoStd = Ssr.StecResidualNoStd = (function() {
    function StecResidualNoStd(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    StecResidualNoStd.prototype._read = function() {
      this.svId = new Gnss.SvId(this._io, this, this._root);
      this.residual = this._io.readS2le();
    }

    /**
     * space vehicle identifier
     */

    /**
     * STEC residual
     */

    return StecResidualNoStd;
  })();

  /**
   * Troposphere vertical delays at the grid point.
   */

  var TroposphericDelayCorrectionNoStd = Ssr.TroposphericDelayCorrectionNoStd = (function() {
    function TroposphericDelayCorrectionNoStd(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    TroposphericDelayCorrectionNoStd.prototype._read = function() {
      this.hydro = this._io.readS2le();
      this.wet = this._io.readS1();
    }

    /**
     * Hydrostatic vertical delay
     */

    /**
     * Wet vertical delay
     */

    return TroposphericDelayCorrectionNoStd;
  })();

  /**
   * The Slant Total Electron Content per space vehicle, given as polynomial
   * approximation for a given tile. This should be combined with the
   * MSG_SSR_GRIDDED_CORRECTION message to get the state space representation
   * of the atmospheric delay.
   * 
   * It is typically equivalent to the QZSS CLAS Sub Type 8 messages.
   */

  var MsgSsrStecCorrectionDep = Ssr.MsgSsrStecCorrectionDep = (function() {
    function MsgSsrStecCorrectionDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrStecCorrectionDep.prototype._read = function() {
      this.header = new StecHeader(this._io, this, this._root);
      this.stecSatList = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.stecSatList.push(new StecSatElement(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Header of a STEC polynomial coefficient message.
     */

    /**
     * Array of STEC polynomial coefficients for each space vehicle.
     */

    return MsgSsrStecCorrectionDep;
  })();

  /**
   * STEC polynomial and bounds for the given satellite.
   */

  var StecSatElementIntegrity = Ssr.StecSatElementIntegrity = (function() {
    function StecSatElementIntegrity(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    StecSatElementIntegrity.prototype._read = function() {
      this.stecResidual = new StecResidual(this._io, this, this._root);
      this.stecBoundMu = this._io.readU1();
      this.stecBoundSig = this._io.readU1();
      this.stecBoundMuDot = this._io.readU1();
      this.stecBoundSigDot = this._io.readU1();
    }

    /**
     * STEC residuals (mean, stddev)
     */

    /**
     * Error Bound Mean. See Note 1.
     */

    /**
     * Error Bound StDev. See Note 1.
     */

    /**
     * Error Bound Mean First derivative.
     */

    /**
     * Error Bound StDev First derivative.
     */

    return StecSatElementIntegrity;
  })();

  var MsgSsrOrbitClockDepA = Ssr.MsgSsrOrbitClockDepA = (function() {
    function MsgSsrOrbitClockDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrOrbitClockDepA.prototype._read = function() {
      this.time = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.updateInterval = this._io.readU1();
      this.iodSsr = this._io.readU1();
      this.iod = this._io.readU1();
      this.radial = this._io.readS4le();
      this.along = this._io.readS4le();
      this.cross = this._io.readS4le();
      this.dotRadial = this._io.readS4le();
      this.dotAlong = this._io.readS4le();
      this.dotCross = this._io.readS4le();
      this.c0 = this._io.readS4le();
      this.c1 = this._io.readS4le();
      this.c2 = this._io.readS4le();
    }

    /**
     * GNSS reference time of the correction
     */

    /**
     * GNSS signal identifier (16 bit)
     */

    /**
     * Update interval between consecutive corrections. Encoded following
     * RTCM DF391 specification.
     */

    /**
     * IOD of the SSR correction. A change of Issue Of Data SSR is used to
     * indicate a change in the SSR generating configuration
     */

    /**
     * Issue of broadcast ephemeris data
     */

    /**
     * Orbit radial delta correction
     */

    /**
     * Orbit along delta correction
     */

    /**
     * Orbit along delta correction
     */

    /**
     * Velocity of orbit radial delta correction
     */

    /**
     * Velocity of orbit along delta correction
     */

    /**
     * Velocity of orbit cross delta correction
     */

    /**
     * C0 polynomial coefficient for correction of broadcast satellite
     * clock
     */

    /**
     * C1 polynomial coefficient for correction of broadcast satellite
     * clock
     */

    /**
     * C2 polynomial coefficient for correction of broadcast satellite
     * clock
     */

    return MsgSsrOrbitClockDepA;
  })();

  var MsgSsrStecCorrection = Ssr.MsgSsrStecCorrection = (function() {
    function MsgSsrStecCorrection(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrStecCorrection.prototype._read = function() {
      this.header = new BoundsHeader(this._io, this, this._root);
      this.ssrIodAtmo = this._io.readU1();
      this.tileSetId = this._io.readU2le();
      this.tileId = this._io.readU2le();
      this.nSats = this._io.readU1();
      this.stecSatList = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.stecSatList.push(new StecSatElement(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Header of a STEC correction with bounds message.
     */

    /**
     * IOD of the SSR atmospheric correction
     */

    /**
     * Tile set ID
     */

    /**
     * Tile ID
     */

    /**
     * Number of satellites.
     */

    /**
     * Array of STEC polynomial coefficients for each space vehicle.
     */

    return MsgSsrStecCorrection;
  })();

  /**
   * The precise orbit and clock correction message is to be applied as a
   * delta correction to broadcast ephemeris and is an equivalent to the 1060
   * /1066 RTCM message types.
   */

  var MsgSsrOrbitClock = Ssr.MsgSsrOrbitClock = (function() {
    function MsgSsrOrbitClock(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrOrbitClock.prototype._read = function() {
      this.time = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.updateInterval = this._io.readU1();
      this.iodSsr = this._io.readU1();
      this.iod = this._io.readU4le();
      this.radial = this._io.readS4le();
      this.along = this._io.readS4le();
      this.cross = this._io.readS4le();
      this.dotRadial = this._io.readS4le();
      this.dotAlong = this._io.readS4le();
      this.dotCross = this._io.readS4le();
      this.c0 = this._io.readS4le();
      this.c1 = this._io.readS4le();
      this.c2 = this._io.readS4le();
    }

    /**
     * GNSS reference time of the correction
     */

    /**
     * GNSS signal identifier (16 bit)
     */

    /**
     * Update interval between consecutive corrections. Encoded following
     * RTCM DF391 specification.
     */

    /**
     * IOD of the SSR correction. A change of Issue Of Data SSR is used to
     * indicate a change in the SSR generating configuration
     */

    /**
     * Issue of broadcast ephemeris data or IODCRC (Beidou)
     */

    /**
     * Orbit radial delta correction
     */

    /**
     * Orbit along delta correction
     */

    /**
     * Orbit along delta correction
     */

    /**
     * Velocity of orbit radial delta correction
     */

    /**
     * Velocity of orbit along delta correction
     */

    /**
     * Velocity of orbit cross delta correction
     */

    /**
     * C0 polynomial coefficient for correction of broadcast satellite
     * clock
     */

    /**
     * C1 polynomial coefficient for correction of broadcast satellite
     * clock
     */

    /**
     * C2 polynomial coefficient for correction of broadcast satellite
     * clock
     */

    return MsgSsrOrbitClock;
  })();

  var BoundsHeader = Ssr.BoundsHeader = (function() {
    function BoundsHeader(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    BoundsHeader.prototype._read = function() {
      this.time = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.numMsgs = this._io.readU1();
      this.seqNum = this._io.readU1();
      this.updateInterval = this._io.readU1();
      this.solId = this._io.readU1();
    }

    /**
     * GNSS reference time of the bound
     */

    /**
     * Number of messages in the dataset
     */

    /**
     * Position of this message in the dataset
     */

    /**
     * Update interval between consecutive bounds. Similar to RTCM DF391.
     */

    /**
     * SSR Solution ID.
     */

    return BoundsHeader;
  })();

  /**
   * STEC residuals are per space vehicle, troposphere is not.
   * 
   * It is typically equivalent to the QZSS CLAS Sub Type 9 messages.
   */

  var MsgSsrGriddedCorrection = Ssr.MsgSsrGriddedCorrection = (function() {
    function MsgSsrGriddedCorrection(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrGriddedCorrection.prototype._read = function() {
      this.header = new GriddedCorrectionHeader(this._io, this, this._root);
      this.index = this._io.readU2le();
      this.tropoDelayCorrection = new TroposphericDelayCorrection(this._io, this, this._root);
      this.stecResiduals = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.stecResiduals.push(new StecResidual(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Header of a gridded correction message
     */

    /**
     * Index of the grid point.
     */

    /**
     * Wet and hydrostatic vertical delays (mean, stddev).
     */

    /**
     * STEC residuals for each satellite (mean, stddev).
     */

    return MsgSsrGriddedCorrection;
  })();

  /**
   * STEC residual (mean and standard deviation) for the given satellite at
   * the grid point.
   */

  var StecResidual = Ssr.StecResidual = (function() {
    function StecResidual(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    StecResidual.prototype._read = function() {
      this.svId = new Gnss.SvId(this._io, this, this._root);
      this.residual = this._io.readS2le();
      this.stddev = this._io.readU1();
    }

    /**
     * space vehicle identifier
     */

    /**
     * STEC residual
     */

    /**
     * Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
     * value/16) - 1) * 10
     */

    return StecResidual;
  })();

  var CodePhaseBiasesSatSig = Ssr.CodePhaseBiasesSatSig = (function() {
    function CodePhaseBiasesSatSig(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    CodePhaseBiasesSatSig.prototype._read = function() {
      this.satId = this._io.readU1();
      this.signalId = this._io.readU1();
      this.codeBiasBoundMu = this._io.readU1();
      this.codeBiasBoundSig = this._io.readU1();
      this.phaseBiasBoundMu = this._io.readU1();
      this.phaseBiasBoundSig = this._io.readU1();
    }

    /**
     * Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
     * or DF488 (BDS) depending on the constellation.
     */

    /**
     * Signal and Tracking Mode Identifier. Similar to either RTCM DF380
     * (GPS), DF382 (Galileo) or DF467 (BDS) depending on the
     * constellation.
     */

    /**
     * Code Bias Mean. Range: 0-1.275 m
     */

    /**
     * Code Bias Standard Deviation.  Range: 0-1.275 m
     */

    /**
     * Phase Bias Mean. Range: 0-1.275 m
     */

    /**
     * Phase Bias Standard Deviation.  Range: 0-1.275 m
     */

    return CodePhaseBiasesSatSig;
  })();

  /**
   * Contains phase center offset and elevation variation corrections for one
   * signal on a satellite.
   */

  var SatelliteApc = Ssr.SatelliteApc = (function() {
    function SatelliteApc(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    SatelliteApc.prototype._read = function() {
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.satInfo = this._io.readU1();
      this.svn = this._io.readU2le();
      this.pco = [];
      for (var i = 0; i < 3; i++) {
        this.pco.push(this._io.readS2le());
      }
      this.pcv = [];
      for (var i = 0; i < 21; i++) {
        this.pcv.push(this._io.readS1());
      }
    }

    /**
     * GNSS signal identifier (16 bit)
     */

    /**
     * Additional satellite information
     */

    /**
     * Satellite Code, as defined by IGS. Typically the space vehicle
     * number.
     */

    /**
     * Mean phase center offset, X Y and Z axes. See IGS ANTEX file format
     * description for coordinate system definition.
     */

    /**
     * Elevation dependent phase center variations. First element is 0
     * degrees separation from the Z axis, subsequent elements represent
     * elevation variations in 1 degree increments.
     */

    return SatelliteApc;
  })();

  /**
   * The LPP message contains nested variable length arrays which are not
   * supported in SBP, so each grid point will be identified by the index.
   */

  var GriddedCorrectionHeader = Ssr.GriddedCorrectionHeader = (function() {
    function GriddedCorrectionHeader(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    GriddedCorrectionHeader.prototype._read = function() {
      this.tileSetId = this._io.readU2le();
      this.tileId = this._io.readU2le();
      this.time = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.numMsgs = this._io.readU2le();
      this.seqNum = this._io.readU2le();
      this.updateInterval = this._io.readU1();
      this.iodAtmo = this._io.readU1();
      this.tropoQualityIndicator = this._io.readU1();
    }

    /**
     * Unique identifier of the tile set this tile belongs to.
     */

    /**
     * Unique identifier of this tile in the tile set.
     */

    /**
     * GNSS reference time of the correction
     */

    /**
     * Number of messages in the dataset
     */

    /**
     * Position of this message in the dataset
     */

    /**
     * Update interval between consecutive corrections. Encoded following
     * RTCM DF391 specification.
     */

    /**
     * IOD of the SSR atmospheric correction
     */

    /**
     * Quality of the troposphere data. Encoded following RTCM DF389
     * specification in units of m.
     */

    return GriddedCorrectionHeader;
  })();

  /**
   * STEC polynomial for the given satellite.
   */

  var StecSatElement = Ssr.StecSatElement = (function() {
    function StecSatElement(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    StecSatElement.prototype._read = function() {
      this.svId = new Gnss.SvId(this._io, this, this._root);
      this.stecQualityIndicator = this._io.readU1();
      this.stecCoeff = [];
      for (var i = 0; i < 4; i++) {
        this.stecCoeff.push(this._io.readS2le());
      }
    }

    /**
     * Unique space vehicle identifier
     */

    /**
     * Quality of the STEC data. Encoded following RTCM DF389 specification
     * but in units of TECU instead of m.
     */

    /**
     * Coefficients of the STEC polynomial in the order of C00, C01, C10,
     * C11. C00 = 0.05 TECU, C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2
     */

    return StecSatElement;
  })();

  /**
   * A full set of STEC information will likely span multiple SBP messages,
   * since SBP message a limited to 255 bytes.  The header is used to tie
   * multiple SBP messages into a sequence.
   */

  var StecHeaderDepA = Ssr.StecHeaderDepA = (function() {
    function StecHeaderDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    StecHeaderDepA.prototype._read = function() {
      this.time = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.numMsgs = this._io.readU1();
      this.seqNum = this._io.readU1();
      this.updateInterval = this._io.readU1();
      this.iodAtmo = this._io.readU1();
    }

    /**
     * GNSS reference time of the correction
     */

    /**
     * Number of messages in the dataset
     */

    /**
     * Position of this message in the dataset
     */

    /**
     * Update interval between consecutive corrections. Encoded following
     * RTCM DF391 specification.
     */

    /**
     * IOD of the SSR atmospheric correction
     */

    return StecHeaderDepA;
  })();

  /**
   * A full set of STEC information will likely span multiple SBP messages,
   * since SBP message a limited to 255 bytes.  The header is used to tie
   * multiple SBP messages into a sequence.
   */

  var StecHeader = Ssr.StecHeader = (function() {
    function StecHeader(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    StecHeader.prototype._read = function() {
      this.tileSetId = this._io.readU2le();
      this.tileId = this._io.readU2le();
      this.time = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.numMsgs = this._io.readU1();
      this.seqNum = this._io.readU1();
      this.updateInterval = this._io.readU1();
      this.iodAtmo = this._io.readU1();
    }

    /**
     * Unique identifier of the tile set this tile belongs to.
     */

    /**
     * Unique identifier of this tile in the tile set.
     */

    /**
     * GNSS reference time of the correction
     */

    /**
     * Number of messages in the dataset
     */

    /**
     * Position of this message in the dataset
     */

    /**
     * Update interval between consecutive corrections. Encoded following
     * RTCM DF391 specification.
     */

    /**
     * IOD of the SSR atmospheric correction
     */

    return StecHeader;
  })();

  var MsgSsrStecCorrectionDepA = Ssr.MsgSsrStecCorrectionDepA = (function() {
    function MsgSsrStecCorrectionDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrStecCorrectionDepA.prototype._read = function() {
      this.header = new StecHeaderDepA(this._io, this, this._root);
      this.stecSatList = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.stecSatList.push(new StecSatElement(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Header of a STEC message
     */

    /**
     * Array of STEC information for each space vehicle
     */

    return MsgSsrStecCorrectionDepA;
  })();

  /**
   * The 3GPP message contains nested variable length arrays which are not
   * supported in SBP, so each grid point will be identified by the index.
   */

  var GriddedCorrectionHeaderDepA = Ssr.GriddedCorrectionHeaderDepA = (function() {
    function GriddedCorrectionHeaderDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    GriddedCorrectionHeaderDepA.prototype._read = function() {
      this.time = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.numMsgs = this._io.readU2le();
      this.seqNum = this._io.readU2le();
      this.updateInterval = this._io.readU1();
      this.iodAtmo = this._io.readU1();
      this.tropoQualityIndicator = this._io.readU1();
    }

    /**
     * GNSS reference time of the correction
     */

    /**
     * Number of messages in the dataset
     */

    /**
     * Position of this message in the dataset
     */

    /**
     * Update interval between consecutive corrections. Encoded following
     * RTCM DF391 specification.
     */

    /**
     * IOD of the SSR atmospheric correction
     */

    /**
     * Quality of the troposphere data. Encoded following RTCM DF389
     * specification in units of m.
     */

    return GriddedCorrectionHeaderDepA;
  })();

  /**
   * Note 1: Range: 0-17.5 m. i<=200, mean=0.01i; 200<i<=230,
   * mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
   * 
   * Note 2: Range: 0-17.5 m. i<=200, std=0.01i; 200<i<=230, std=2+0.1(i-200)
   * i>230, std=5+0.5(i-230).
   */

  var MsgSsrOrbitClockBounds = Ssr.MsgSsrOrbitClockBounds = (function() {
    function MsgSsrOrbitClockBounds(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrOrbitClockBounds.prototype._read = function() {
      this.header = new BoundsHeader(this._io, this, this._root);
      this.ssrIod = this._io.readU1();
      this.constId = this._io.readU1();
      this.nSats = this._io.readU1();
      this.orbitClockBounds = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.orbitClockBounds.push(new OrbitClockBound(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Header of a bounds message.
     */

    /**
     * IOD of the SSR bound.
     */

    /**
     * Constellation ID to which the SVs belong.
     */

    /**
     * Number of satellites.
     */

    /**
     * Orbit and Clock Bounds per Satellite
     */

    return MsgSsrOrbitClockBounds;
  })();

  /**
   * Note 1: Range: 0-17.5 m. i<= 200, mean = 0.01i; 200<i<=230,
   * mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
   */

  var MsgSsrGriddedCorrectionBounds = Ssr.MsgSsrGriddedCorrectionBounds = (function() {
    function MsgSsrGriddedCorrectionBounds(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrGriddedCorrectionBounds.prototype._read = function() {
      this.header = new BoundsHeader(this._io, this, this._root);
      this.ssrIodAtmo = this._io.readU1();
      this.tileSetId = this._io.readU2le();
      this.tileId = this._io.readU2le();
      this.tropoQi = this._io.readU1();
      this.gridPointId = this._io.readU2le();
      this.tropoDelayCorrection = new TroposphericDelayCorrection(this._io, this, this._root);
      this.tropoVHydroBoundMu = this._io.readU1();
      this.tropoVHydroBoundSig = this._io.readU1();
      this.tropoVWetBoundMu = this._io.readU1();
      this.tropoVWetBoundSig = this._io.readU1();
      this.nSats = this._io.readU1();
      this.stecSatList = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.stecSatList.push(new StecSatElementIntegrity(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Header of a bounds message.
     */

    /**
     * IOD of the correction.
     */

    /**
     * Set this tile belongs to.
     */

    /**
     * Unique identifier of this tile in the tile set.
     */

    /**
     * Tropo Quality Indicator. Similar to RTCM DF389.
     */

    /**
     * Index of the Grid Point.
     */

    /**
     * Tropospheric delay at grid point.
     */

    /**
     * Vertical Hydrostatic Error Bound Mean.
     */

    /**
     * Vertical Hydrostatic Error Bound StDev.
     */

    /**
     * Vertical Wet Error Bound Mean.
     */

    /**
     * Vertical Wet Error Bound StDev.
     */

    /**
     * Number of satellites.
     */

    /**
     * Array of STEC polynomial coefficients and its bounds for each space
     * vehicle.
     */

    return MsgSsrGriddedCorrectionBounds;
  })();

  var MsgSsrGridDefinitionDepA = Ssr.MsgSsrGridDefinitionDepA = (function() {
    function MsgSsrGridDefinitionDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrGridDefinitionDepA.prototype._read = function() {
      this.header = new GridDefinitionHeaderDepA(this._io, this, this._root);
      this.rleList = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.rleList.push(this._io.readU1());
        i++;
      }
    }

    /**
     * Header of a Gridded Correction message
     */

    /**
     * Run Length Encode list of quadrants that contain valid data. The
     * spec describes the encoding scheme in detail, but essentially the
     * index of the quadrants that contain transitions between valid and
     * invalid (and vice versa) are encoded as u8 integers.
     */

    return MsgSsrGridDefinitionDepA;
  })();

  /**
   * Code biases are to be added to pseudorange. The corrections conform with
   * RTCMv3 MT 1059 / 1065.
   */

  var CodeBiasesContent = Ssr.CodeBiasesContent = (function() {
    function CodeBiasesContent(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    CodeBiasesContent.prototype._read = function() {
      this.code = this._io.readU1();
      this.value = this._io.readS2le();
    }

    /**
     * Signal encoded following RTCM specifications (DF380, DF381, DF382
     * and DF467).
     */

    /**
     * Code bias value
     */

    return CodeBiasesContent;
  })();

  var MsgSsrSatelliteApc = Ssr.MsgSsrSatelliteApc = (function() {
    function MsgSsrSatelliteApc(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrSatelliteApc.prototype._read = function() {
      this.time = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.updateInterval = this._io.readU1();
      this.solId = this._io.readU1();
      this.iodSsr = this._io.readU1();
      this.apc = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.apc.push(new SatelliteApc(this._io, this, this._root));
        i++;
      }
    }

    /**
     * GNSS reference time of the correction
     */

    /**
     * Update interval between consecutive corrections. Encoded following
     * RTCM DF391 specification.
     */

    /**
     * SSR Solution ID. Similar to RTCM DF415.
     */

    /**
     * IOD of the SSR correction. A change of Issue Of Data SSR is used to
     * indicate a change in the SSR generating configuration
     */

    /**
     * Satellite antenna phase center corrections
     */

    return MsgSsrSatelliteApc;
  })();

  /**
   * Phase biases are to be added to carrier phase measurements.
   */

  var PhaseBiasesContent = Ssr.PhaseBiasesContent = (function() {
    function PhaseBiasesContent(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    PhaseBiasesContent.prototype._read = function() {
      this.code = this._io.readU1();
      this.integerIndicator = this._io.readU1();
      this.widelaneIntegerIndicator = this._io.readU1();
      this.discontinuityCounter = this._io.readU1();
      this.bias = this._io.readS4le();
    }

    /**
     * Signal encoded following RTCM specifications (DF380, DF381, DF382
     * and DF467)
     */

    /**
     * Indicator for integer property
     */

    /**
     * Indicator for two groups of Wide-Lane(s) integer property
     */

    /**
     * Signal phase discontinuity counter. Increased for every
     * discontinuity in phase.
     */

    /**
     * Phase bias for specified signal
     */

    return PhaseBiasesContent;
  })();

  /**
   * Provides the correction point coordinates for the atmospheric correction
   * values in the MSG_SSR_STEC_CORRECTION_DEP and MSG_SSR_GRIDDED_CORRECTION
   * messages.
   * 
   * Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
   * element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
   * correction points, not lists of points.
   */

  var MsgSsrTileDefinitionDepA = Ssr.MsgSsrTileDefinitionDepA = (function() {
    function MsgSsrTileDefinitionDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrTileDefinitionDepA.prototype._read = function() {
      this.tileSetId = this._io.readU2le();
      this.tileId = this._io.readU2le();
      this.cornerNwLat = this._io.readS2le();
      this.cornerNwLon = this._io.readS2le();
      this.spacingLat = this._io.readU2le();
      this.spacingLon = this._io.readU2le();
      this.rows = this._io.readU2le();
      this.cols = this._io.readU2le();
      this.bitmask = this._io.readU8le();
    }

    /**
     * Unique identifier of the tile set this tile belongs to.
     */

    /**
     * Unique identifier of this tile in the tile set.
     * See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
     */

    /**
     * North-West corner correction point latitude.
     * 
     * The relation between the latitude X in the range [-90, 90] and the
     * coded number N is:
     * 
     * N = floor((X / 90) * 2^14)
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
     */

    /**
     * North-West corner correction point longitude.
     * 
     * The relation between the longitude X in the range [-180, 180] and
     * the coded number N is:
     * 
     * N = floor((X / 180) * 2^15)
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
     */

    /**
     * Spacing of the correction points in the latitude direction.
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
     */

    /**
     * Spacing of the correction points in the longitude direction.
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
     */

    /**
     * Number of steps in the latitude direction.
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
     */

    /**
     * Number of steps in the longitude direction.
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
     */

    /**
     * Specifies the availability of correction data at the correction
     * points in the array.
     * 
     * If a specific bit is enabled (set to 1), the correction is not
     * available. Only the first rows * cols bits are used, the remainder
     * are set to 0. If there are more then 64 correction points the
     * remaining corrections are always available.
     * 
     * Starting with the northwest corner of the array (top left on a north
     * oriented map) the correction points are enumerated with row
     * precedence - first row west to east, second row west to east, until
     * last row west to east - ending with the southeast corner of the
     * array.
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
     * the definition of the bits is inverted.
     */

    return MsgSsrTileDefinitionDepA;
  })();

  /**
   * Orbit and clock bound.
   */

  var OrbitClockBound = Ssr.OrbitClockBound = (function() {
    function OrbitClockBound(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    OrbitClockBound.prototype._read = function() {
      this.satId = this._io.readU1();
      this.orbRadialBoundMu = this._io.readU1();
      this.orbAlongBoundMu = this._io.readU1();
      this.orbCrossBoundMu = this._io.readU1();
      this.orbRadialBoundSig = this._io.readU1();
      this.orbAlongBoundSig = this._io.readU1();
      this.orbCrossBoundSig = this._io.readU1();
      this.clockBoundMu = this._io.readU1();
      this.clockBoundSig = this._io.readU1();
    }

    /**
     * Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
     * or DF488 (BDS) depending on the constellation.
     */

    /**
     * Mean Radial. See Note 1.
     */

    /**
     * Mean Along-Track. See Note 1.
     */

    /**
     * Mean Cross-Track. See Note 1.
     */

    /**
     * Standard Deviation Radial. See Note 2.
     */

    /**
     * Standard Deviation Along-Track. See Note 2.
     */

    /**
     * Standard Deviation Cross-Track. See Note 2.
     */

    /**
     * Clock Bound Mean. See Note 1.
     */

    /**
     * Clock Bound Standard Deviation. See Note 2.
     */

    return OrbitClockBound;
  })();

  var MsgSsrGriddedCorrectionDepA = Ssr.MsgSsrGriddedCorrectionDepA = (function() {
    function MsgSsrGriddedCorrectionDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrGriddedCorrectionDepA.prototype._read = function() {
      this.header = new GriddedCorrectionHeaderDepA(this._io, this, this._root);
      this.index = this._io.readU2le();
      this.tropoDelayCorrection = new TroposphericDelayCorrection(this._io, this, this._root);
      this.stecResiduals = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.stecResiduals.push(new StecResidual(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Header of a Gridded Correction message
     */

    /**
     * Index of the grid point
     */

    /**
     * Wet and hydrostatic vertical delays (mean, stddev)
     */

    /**
     * STEC residuals for each satellite (mean, stddev)
     */

    return MsgSsrGriddedCorrectionDepA;
  })();

  var MsgSsrOrbitClockBoundsDegradation = Ssr.MsgSsrOrbitClockBoundsDegradation = (function() {
    function MsgSsrOrbitClockBoundsDegradation(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrOrbitClockBoundsDegradation.prototype._read = function() {
      this.header = new BoundsHeader(this._io, this, this._root);
      this.ssrIod = this._io.readU1();
      this.constId = this._io.readU1();
      this.satBitmask = this._io.readU8le();
      this.orbitClockBoundsDegradation = new OrbitClockBoundDegradation(this._io, this, this._root);
    }

    /**
     * Header of a bounds message.
     */

    /**
     * IOD of the SSR bound degradation parameter.
     */

    /**
     * Constellation ID to which the SVs belong.
     */

    /**
     * Satellite Bit Mask. Put 1 for each satellite where the following
     * degradation parameters are applicable, 0 otherwise. Encoded
     * following RTCM DF394 specification.
     */

    /**
     * Orbit and Clock Bounds Degradation Parameters
     */

    return MsgSsrOrbitClockBoundsDegradation;
  })();

  var MsgSsrGriddedCorrectionNoStdDepA = Ssr.MsgSsrGriddedCorrectionNoStdDepA = (function() {
    function MsgSsrGriddedCorrectionNoStdDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrGriddedCorrectionNoStdDepA.prototype._read = function() {
      this.header = new GriddedCorrectionHeaderDepA(this._io, this, this._root);
      this.index = this._io.readU2le();
      this.tropoDelayCorrection = new TroposphericDelayCorrectionNoStd(this._io, this, this._root);
      this.stecResiduals = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.stecResiduals.push(new StecResidualNoStd(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Header of a Gridded Correction message
     */

    /**
     * Index of the grid point
     */

    /**
     * Wet and hydrostatic vertical delays
     */

    /**
     * STEC residuals for each satellite
     */

    return MsgSsrGriddedCorrectionNoStdDepA;
  })();

  var MsgSsrCodePhaseBiasesBounds = Ssr.MsgSsrCodePhaseBiasesBounds = (function() {
    function MsgSsrCodePhaseBiasesBounds(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrCodePhaseBiasesBounds.prototype._read = function() {
      this.header = new BoundsHeader(this._io, this, this._root);
      this.ssrIod = this._io.readU1();
      this.constId = this._io.readU1();
      this.nSatsSignals = this._io.readU1();
      this.satellitesSignals = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.satellitesSignals.push(new CodePhaseBiasesSatSig(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Header of a bounds message.
     */

    /**
     * IOD of the SSR bound.
     */

    /**
     * Constellation ID to which the SVs belong.
     */

    /**
     * Number of satellite-signal couples.
     */

    /**
     * Code and Phase Biases Bounds per Satellite-Signal couple.
     */

    return MsgSsrCodePhaseBiasesBounds;
  })();

  /**
   * The precise code biases message is to be added to the pseudorange of the
   * corresponding signal to get corrected pseudorange. It is an equivalent
   * to the 1059 / 1065 RTCM message types.
   */

  var MsgSsrCodeBiases = Ssr.MsgSsrCodeBiases = (function() {
    function MsgSsrCodeBiases(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrCodeBiases.prototype._read = function() {
      this.time = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.updateInterval = this._io.readU1();
      this.iodSsr = this._io.readU1();
      this.biases = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.biases.push(new CodeBiasesContent(this._io, this, this._root));
        i++;
      }
    }

    /**
     * GNSS reference time of the correction
     */

    /**
     * GNSS signal identifier (16 bit)
     */

    /**
     * Update interval between consecutive corrections. Encoded following
     * RTCM DF391 specification.
     */

    /**
     * IOD of the SSR correction. A change of Issue Of Data SSR is used to
     * indicate a change in the SSR generating configuration
     */

    /**
     * Code biases for the different satellite signals
     */

    return MsgSsrCodeBiases;
  })();

  /**
   * Provides the correction point coordinates for the atmospheric correction
   * values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
   * messages.
   * 
   * Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
   * element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
   * correction points, not lists of points.
   */

  var MsgSsrTileDefinition = Ssr.MsgSsrTileDefinition = (function() {
    function MsgSsrTileDefinition(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrTileDefinition.prototype._read = function() {
      this.time = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.updateInterval = this._io.readU1();
      this.solId = this._io.readU1();
      this.iodAtmo = this._io.readU1();
      this.tileSetId = this._io.readU2le();
      this.tileId = this._io.readU2le();
      this.cornerNwLat = this._io.readS2le();
      this.cornerNwLon = this._io.readS2le();
      this.spacingLat = this._io.readU2le();
      this.spacingLon = this._io.readU2le();
      this.rows = this._io.readU2le();
      this.cols = this._io.readU2le();
      this.bitmask = this._io.readU8le();
    }

    /**
     * GNSS reference time of the correction
     */

    /**
     * Update interval between consecutive corrections. Encoded following
     * RTCM DF391 specification.
     */

    /**
     * SSR Solution ID. Similar to RTCM DF415.
     */

    /**
     * IOD of the SSR atmospheric correction.
     */

    /**
     * Unique identifier of the tile set this tile belongs to.
     */

    /**
     * Unique identifier of this tile in the tile set.
     * See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
     */

    /**
     * North-West corner correction point latitude.
     * 
     * The relation between the latitude X in the range [-90, 90] and the
     * coded number N is:  N = floor((X / 90) * 2^14)
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
     */

    /**
     * North-West corner correction point longitude.
     * 
     * The relation between the longitude X in the range [-180, 180] and
     * the coded number N is: N = floor((X / 180) * 2^15)
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
     */

    /**
     * Spacing of the correction points in the latitude direction.
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
     */

    /**
     * Spacing of the correction points in the longitude direction.
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
     */

    /**
     * Number of steps in the latitude direction.
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
     */

    /**
     * Number of steps in the longitude direction.
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
     */

    /**
     * Specifies the absence of correction data at the correction points in
     * the array (grid).
     * 
     * Only the first rows * cols bits are used, and if a specific bit is
     * enabled (set to 1), the correction is not available. If there are
     * more than 64 correction points the remaining corrections are always
     * available.
     * 
     * The correction points are packed by rows, starting with the
     * northwest corner of the array (top-left on a north oriented map),
     * with each row spanning west to east, ending with the southeast
     * corner of the array.
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
     * the definition of the bits is inverted.
     */

    return MsgSsrTileDefinition;
  })();

  /**
   * Orbit and clock bound degradation.
   */

  var OrbitClockBoundDegradation = Ssr.OrbitClockBoundDegradation = (function() {
    function OrbitClockBoundDegradation(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    OrbitClockBoundDegradation.prototype._read = function() {
      this.orbRadialBoundMuDot = this._io.readU1();
      this.orbAlongBoundMuDot = this._io.readU1();
      this.orbCrossBoundMuDot = this._io.readU1();
      this.orbRadialBoundSigDot = this._io.readU1();
      this.orbAlongBoundSigDot = this._io.readU1();
      this.orbCrossBoundSigDot = this._io.readU1();
      this.clockBoundMuDot = this._io.readU1();
      this.clockBoundSigDot = this._io.readU1();
    }

    /**
     * Orbit Bound Mean Radial First derivative. Range: 0-0.255 m/s
     */

    /**
     * Orbit Bound Mean Along-Track First derivative. Range: 0-0.255 m/s
     */

    /**
     * Orbit Bound Mean Cross-Track First derivative. Range: 0-0.255 m/s
     */

    /**
     * Orbit Bound Standard Deviation Radial First derivative. Range:
     * 0-0.255 m/s
     */

    /**
     * Orbit Bound Standard Deviation Along-Track First derivative. Range:
     * 0-0.255 m/s
     */

    /**
     * Orbit Bound Standard Deviation Cross-Track First derivative. Range:
     * 0-0.255 m/s
     */

    /**
     * Clock Bound Mean First derivative. Range: 0-0.255 m/s
     */

    /**
     * Clock Bound Standard Deviation First derivative. Range: 0-0.255 m/s
     */

    return OrbitClockBoundDegradation;
  })();

  var MsgSsrSatelliteApcDep = Ssr.MsgSsrSatelliteApcDep = (function() {
    function MsgSsrSatelliteApcDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrSatelliteApcDep.prototype._read = function() {
      this.apc = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.apc.push(new SatelliteApc(this._io, this, this._root));
        i++;
      }
    }

    /**
     * Satellite antenna phase center corrections
     */

    return MsgSsrSatelliteApcDep;
  })();

  /**
   * Troposphere vertical delays (mean and standard deviation) at the grid
   * point.
   */

  var TroposphericDelayCorrection = Ssr.TroposphericDelayCorrection = (function() {
    function TroposphericDelayCorrection(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    TroposphericDelayCorrection.prototype._read = function() {
      this.hydro = this._io.readS2le();
      this.wet = this._io.readS1();
      this.stddev = this._io.readU1();
    }

    /**
     * Hydrostatic vertical delay. Add 2.3 m to get actual value.
     */

    /**
     * Wet vertical delay. Add 0.252 m to get actual value.
     */

    /**
     * Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
     * value/16) - 1)
     */

    return TroposphericDelayCorrection;
  })();

  /**
   * Provides the correction point coordinates for the atmospheric correction
   * values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
   * messages.
   * 
   * Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
   * element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
   * correction points, not lists of points.
   */

  var MsgSsrTileDefinitionDepB = Ssr.MsgSsrTileDefinitionDepB = (function() {
    function MsgSsrTileDefinitionDepB(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrTileDefinitionDepB.prototype._read = function() {
      this.ssrSolId = this._io.readU1();
      this.tileSetId = this._io.readU2le();
      this.tileId = this._io.readU2le();
      this.cornerNwLat = this._io.readS2le();
      this.cornerNwLon = this._io.readS2le();
      this.spacingLat = this._io.readU2le();
      this.spacingLon = this._io.readU2le();
      this.rows = this._io.readU2le();
      this.cols = this._io.readU2le();
      this.bitmask = this._io.readU8le();
    }

    /**
     * SSR Solution ID.
     */

    /**
     * Unique identifier of the tile set this tile belongs to.
     */

    /**
     * Unique identifier of this tile in the tile set.
     * See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
     */

    /**
     * North-West corner correction point latitude.
     * 
     * The relation between the latitude X in the range [-90, 90] and the
     * coded number N is:
     * 
     * N = floor((X / 90) * 2^14)
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
     */

    /**
     * North-West corner correction point longitude.
     * 
     * The relation between the longitude X in the range [-180, 180] and
     * the coded number N is:
     * 
     * N = floor((X / 180) * 2^15)
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
     */

    /**
     * Spacing of the correction points in the latitude direction.
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
     */

    /**
     * Spacing of the correction points in the longitude direction.
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
     */

    /**
     * Number of steps in the latitude direction.
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
     */

    /**
     * Number of steps in the longitude direction.
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
     */

    /**
     * Specifies the availability of correction data at the correction
     * points in the array.
     * 
     * If a specific bit is enabled (set to 1), the correction is not
     * available. Only the first rows * cols bits are used, the remainder
     * are set to 0. If there are more then 64 correction points the
     * remaining corrections are always available.
     * 
     * Starting with the northwest corner of the array (top left on a north
     * oriented map) the correction points are enumerated with row
     * precedence - first row west to east, second row west to east, until
     * last row west to east - ending with the southeast corner of the
     * array.
     * 
     * See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
     * the definition of the bits is inverted.
     */

    return MsgSsrTileDefinitionDepB;
  })();

  /**
   * The precise phase biases message contains the biases to be added to the
   * carrier phase of the corresponding signal to get corrected carrier phase
   * measurement, as well as the satellite yaw angle to be applied to compute
   * the phase wind-up correction. It is typically an equivalent to the 1265
   * RTCM message types.
   */

  var MsgSsrPhaseBiases = Ssr.MsgSsrPhaseBiases = (function() {
    function MsgSsrPhaseBiases(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgSsrPhaseBiases.prototype._read = function() {
      this.time = new Gnss.GpsTimeSec(this._io, this, this._root);
      this.sid = new Gnss.GnssSignal(this._io, this, this._root);
      this.updateInterval = this._io.readU1();
      this.iodSsr = this._io.readU1();
      this.dispersiveBias = this._io.readU1();
      this.mwConsistency = this._io.readU1();
      this.yaw = this._io.readU2le();
      this.yawRate = this._io.readS1();
      this.biases = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.biases.push(new PhaseBiasesContent(this._io, this, this._root));
        i++;
      }
    }

    /**
     * GNSS reference time of the correction
     */

    /**
     * GNSS signal identifier (16 bit)
     */

    /**
     * Update interval between consecutive corrections. Encoded following
     * RTCM DF391 specification.
     */

    /**
     * IOD of the SSR correction. A change of Issue Of Data SSR is used to
     * indicate a change in the SSR generating configuration
     */

    /**
     * Indicator for the dispersive phase biases property.
     */

    /**
     * Consistency indicator for Melbourne-Wubbena linear combinations
     */

    /**
     * Satellite yaw angle
     */

    /**
     * Satellite yaw angle rate
     */

    /**
     * Phase biases corrections for a satellite being tracked.
     */

    return MsgSsrPhaseBiases;
  })();

  return Ssr;
})();
return Ssr;
}));
