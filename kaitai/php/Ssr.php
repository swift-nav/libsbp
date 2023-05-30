<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Ssr extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes
 * an RLE encoded validity list.
 */

namespace Ssr {
    class GridDefinitionHeaderDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Ssr\MsgSsrGridDefinitionDepA $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_regionSizeInverse = $this->_io->readU1();
            $this->_m_areaWidth = $this->_io->readU2le();
            $this->_m_latNwCornerEnc = $this->_io->readU2le();
            $this->_m_lonNwCornerEnc = $this->_io->readU2le();
            $this->_m_numMsgs = $this->_io->readU1();
            $this->_m_seqNum = $this->_io->readU1();
        }
        protected $_m_regionSizeInverse;
        protected $_m_areaWidth;
        protected $_m_latNwCornerEnc;
        protected $_m_lonNwCornerEnc;
        protected $_m_numMsgs;
        protected $_m_seqNum;

        /**
         * region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
         */
        public function regionSizeInverse() { return $this->_m_regionSizeInverse; }

        /**
         * grid height (deg) = grid width (deg) = area_width / region_size 0 is
         * an invalid value.
         */
        public function areaWidth() { return $this->_m_areaWidth; }

        /**
         * North-West corner latitude (deg) = region_size * lat_nw_corner_enc -
         * 90
         */
        public function latNwCornerEnc() { return $this->_m_latNwCornerEnc; }

        /**
         * North-West corner longitude (deg) = region_size * lon_nw_corner_enc
         * - 180
         */
        public function lonNwCornerEnc() { return $this->_m_lonNwCornerEnc; }

        /**
         * Number of messages in the dataset
         */
        public function numMsgs() { return $this->_m_numMsgs; }

        /**
         * Position of this message in the dataset
         */
        public function seqNum() { return $this->_m_seqNum; }
    }
}

/**
 * STEC residual for the given satellite at the grid point.
 */

namespace Ssr {
    class StecResidualNoStd extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Ssr\MsgSsrGriddedCorrectionNoStdDepA $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_svId = new \Gnss\SvId($this->_io, $this, $this->_root);
            $this->_m_residual = $this->_io->readS2le();
        }
        protected $_m_svId;
        protected $_m_residual;

        /**
         * space vehicle identifier
         */
        public function svId() { return $this->_m_svId; }

        /**
         * STEC residual
         */
        public function residual() { return $this->_m_residual; }
    }
}

/**
 * Troposphere vertical delays at the grid point.
 */

namespace Ssr {
    class TroposphericDelayCorrectionNoStd extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Ssr\MsgSsrGriddedCorrectionNoStdDepA $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_hydro = $this->_io->readS2le();
            $this->_m_wet = $this->_io->readS1();
        }
        protected $_m_hydro;
        protected $_m_wet;

        /**
         * Hydrostatic vertical delay
         */
        public function hydro() { return $this->_m_hydro; }

        /**
         * Wet vertical delay
         */
        public function wet() { return $this->_m_wet; }
    }
}

/**
 * The Slant Total Electron Content per space vehicle, given as polynomial
 * approximation for a given tile. This should be combined with the
 * MSG_SSR_GRIDDED_CORRECTION message to get the state space representation
 * of the atmospheric delay.
 * 
 * It is typically equivalent to the QZSS CLAS Sub Type 8 messages.
 */

namespace Ssr {
    class MsgSsrStecCorrectionDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Ssr\StecHeader($this->_io, $this, $this->_root);
            $this->_m_stecSatList = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_stecSatList[] = new \Ssr\StecSatElement($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_stecSatList;

        /**
         * Header of a STEC polynomial coefficient message.
         */
        public function header() { return $this->_m_header; }

        /**
         * Array of STEC polynomial coefficients for each space vehicle.
         */
        public function stecSatList() { return $this->_m_stecSatList; }
    }
}

/**
 * STEC polynomial and bounds for the given satellite.
 */

namespace Ssr {
    class StecSatElementIntegrity extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Ssr\MsgSsrGriddedCorrectionBounds $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_stecResidual = new \Ssr\StecResidual($this->_io, $this, $this->_root);
            $this->_m_stecBoundMu = $this->_io->readU1();
            $this->_m_stecBoundSig = $this->_io->readU1();
            $this->_m_stecBoundMuDot = $this->_io->readU1();
            $this->_m_stecBoundSigDot = $this->_io->readU1();
        }
        protected $_m_stecResidual;
        protected $_m_stecBoundMu;
        protected $_m_stecBoundSig;
        protected $_m_stecBoundMuDot;
        protected $_m_stecBoundSigDot;

        /**
         * STEC residuals (mean, stddev)
         */
        public function stecResidual() { return $this->_m_stecResidual; }

        /**
         * Error Bound Mean. See Note 1.
         */
        public function stecBoundMu() { return $this->_m_stecBoundMu; }

        /**
         * Error Bound StDev. See Note 1.
         */
        public function stecBoundSig() { return $this->_m_stecBoundSig; }

        /**
         * Error Bound Mean First derivative.
         */
        public function stecBoundMuDot() { return $this->_m_stecBoundMuDot; }

        /**
         * Error Bound StDev First derivative.
         */
        public function stecBoundSigDot() { return $this->_m_stecBoundSigDot; }
    }
}

namespace Ssr {
    class MsgSsrOrbitClockDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_time = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_updateInterval = $this->_io->readU1();
            $this->_m_iodSsr = $this->_io->readU1();
            $this->_m_iod = $this->_io->readU1();
            $this->_m_radial = $this->_io->readS4le();
            $this->_m_along = $this->_io->readS4le();
            $this->_m_cross = $this->_io->readS4le();
            $this->_m_dotRadial = $this->_io->readS4le();
            $this->_m_dotAlong = $this->_io->readS4le();
            $this->_m_dotCross = $this->_io->readS4le();
            $this->_m_c0 = $this->_io->readS4le();
            $this->_m_c1 = $this->_io->readS4le();
            $this->_m_c2 = $this->_io->readS4le();
        }
        protected $_m_time;
        protected $_m_sid;
        protected $_m_updateInterval;
        protected $_m_iodSsr;
        protected $_m_iod;
        protected $_m_radial;
        protected $_m_along;
        protected $_m_cross;
        protected $_m_dotRadial;
        protected $_m_dotAlong;
        protected $_m_dotCross;
        protected $_m_c0;
        protected $_m_c1;
        protected $_m_c2;

        /**
         * GNSS reference time of the correction
         */
        public function time() { return $this->_m_time; }

        /**
         * GNSS signal identifier (16 bit)
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public function updateInterval() { return $this->_m_updateInterval; }

        /**
         * IOD of the SSR correction. A change of Issue Of Data SSR is used to
         * indicate a change in the SSR generating configuration
         */
        public function iodSsr() { return $this->_m_iodSsr; }

        /**
         * Issue of broadcast ephemeris data
         */
        public function iod() { return $this->_m_iod; }

        /**
         * Orbit radial delta correction
         */
        public function radial() { return $this->_m_radial; }

        /**
         * Orbit along delta correction
         */
        public function along() { return $this->_m_along; }

        /**
         * Orbit along delta correction
         */
        public function cross() { return $this->_m_cross; }

        /**
         * Velocity of orbit radial delta correction
         */
        public function dotRadial() { return $this->_m_dotRadial; }

        /**
         * Velocity of orbit along delta correction
         */
        public function dotAlong() { return $this->_m_dotAlong; }

        /**
         * Velocity of orbit cross delta correction
         */
        public function dotCross() { return $this->_m_dotCross; }

        /**
         * C0 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        public function c0() { return $this->_m_c0; }

        /**
         * C1 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        public function c1() { return $this->_m_c1; }

        /**
         * C2 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        public function c2() { return $this->_m_c2; }
    }
}

namespace Ssr {
    class MsgSsrStecCorrection extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Ssr\BoundsHeader($this->_io, $this, $this->_root);
            $this->_m_ssrIodAtmo = $this->_io->readU1();
            $this->_m_tileSetId = $this->_io->readU2le();
            $this->_m_tileId = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_stecSatList = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_stecSatList[] = new \Ssr\StecSatElement($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_ssrIodAtmo;
        protected $_m_tileSetId;
        protected $_m_tileId;
        protected $_m_nSats;
        protected $_m_stecSatList;

        /**
         * Header of a STEC correction with bounds message.
         */
        public function header() { return $this->_m_header; }

        /**
         * IOD of the SSR atmospheric correction
         */
        public function ssrIodAtmo() { return $this->_m_ssrIodAtmo; }

        /**
         * Tile set ID
         */
        public function tileSetId() { return $this->_m_tileSetId; }

        /**
         * Tile ID
         */
        public function tileId() { return $this->_m_tileId; }

        /**
         * Number of satellites.
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Array of STEC polynomial coefficients for each space vehicle.
         */
        public function stecSatList() { return $this->_m_stecSatList; }
    }
}

/**
 * The precise orbit and clock correction message is to be applied as a
 * delta correction to broadcast ephemeris and is an equivalent to the 1060
 * /1066 RTCM message types.
 */

namespace Ssr {
    class MsgSsrOrbitClock extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_time = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_updateInterval = $this->_io->readU1();
            $this->_m_iodSsr = $this->_io->readU1();
            $this->_m_iod = $this->_io->readU4le();
            $this->_m_radial = $this->_io->readS4le();
            $this->_m_along = $this->_io->readS4le();
            $this->_m_cross = $this->_io->readS4le();
            $this->_m_dotRadial = $this->_io->readS4le();
            $this->_m_dotAlong = $this->_io->readS4le();
            $this->_m_dotCross = $this->_io->readS4le();
            $this->_m_c0 = $this->_io->readS4le();
            $this->_m_c1 = $this->_io->readS4le();
            $this->_m_c2 = $this->_io->readS4le();
        }
        protected $_m_time;
        protected $_m_sid;
        protected $_m_updateInterval;
        protected $_m_iodSsr;
        protected $_m_iod;
        protected $_m_radial;
        protected $_m_along;
        protected $_m_cross;
        protected $_m_dotRadial;
        protected $_m_dotAlong;
        protected $_m_dotCross;
        protected $_m_c0;
        protected $_m_c1;
        protected $_m_c2;

        /**
         * GNSS reference time of the correction
         */
        public function time() { return $this->_m_time; }

        /**
         * GNSS signal identifier (16 bit)
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public function updateInterval() { return $this->_m_updateInterval; }

        /**
         * IOD of the SSR correction. A change of Issue Of Data SSR is used to
         * indicate a change in the SSR generating configuration
         */
        public function iodSsr() { return $this->_m_iodSsr; }

        /**
         * Issue of broadcast ephemeris data or IODCRC (Beidou)
         */
        public function iod() { return $this->_m_iod; }

        /**
         * Orbit radial delta correction
         */
        public function radial() { return $this->_m_radial; }

        /**
         * Orbit along delta correction
         */
        public function along() { return $this->_m_along; }

        /**
         * Orbit along delta correction
         */
        public function cross() { return $this->_m_cross; }

        /**
         * Velocity of orbit radial delta correction
         */
        public function dotRadial() { return $this->_m_dotRadial; }

        /**
         * Velocity of orbit along delta correction
         */
        public function dotAlong() { return $this->_m_dotAlong; }

        /**
         * Velocity of orbit cross delta correction
         */
        public function dotCross() { return $this->_m_dotCross; }

        /**
         * C0 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        public function c0() { return $this->_m_c0; }

        /**
         * C1 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        public function c1() { return $this->_m_c1; }

        /**
         * C2 polynomial coefficient for correction of broadcast satellite
         * clock
         */
        public function c2() { return $this->_m_c2; }
    }
}

namespace Ssr {
    class BoundsHeader extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_time = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_numMsgs = $this->_io->readU1();
            $this->_m_seqNum = $this->_io->readU1();
            $this->_m_updateInterval = $this->_io->readU1();
            $this->_m_solId = $this->_io->readU1();
        }
        protected $_m_time;
        protected $_m_numMsgs;
        protected $_m_seqNum;
        protected $_m_updateInterval;
        protected $_m_solId;

        /**
         * GNSS reference time of the bound
         */
        public function time() { return $this->_m_time; }

        /**
         * Number of messages in the dataset
         */
        public function numMsgs() { return $this->_m_numMsgs; }

        /**
         * Position of this message in the dataset
         */
        public function seqNum() { return $this->_m_seqNum; }

        /**
         * Update interval between consecutive bounds. Similar to RTCM DF391.
         */
        public function updateInterval() { return $this->_m_updateInterval; }

        /**
         * SSR Solution ID.
         */
        public function solId() { return $this->_m_solId; }
    }
}

/**
 * STEC residuals are per space vehicle, troposphere is not.
 * 
 * It is typically equivalent to the QZSS CLAS Sub Type 9 messages.
 */

namespace Ssr {
    class MsgSsrGriddedCorrection extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Ssr\GriddedCorrectionHeader($this->_io, $this, $this->_root);
            $this->_m_index = $this->_io->readU2le();
            $this->_m_tropoDelayCorrection = new \Ssr\TroposphericDelayCorrection($this->_io, $this, $this->_root);
            $this->_m_stecResiduals = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_stecResiduals[] = new \Ssr\StecResidual($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_index;
        protected $_m_tropoDelayCorrection;
        protected $_m_stecResiduals;

        /**
         * Header of a gridded correction message
         */
        public function header() { return $this->_m_header; }

        /**
         * Index of the grid point.
         */
        public function index() { return $this->_m_index; }

        /**
         * Wet and hydrostatic vertical delays (mean, stddev).
         */
        public function tropoDelayCorrection() { return $this->_m_tropoDelayCorrection; }

        /**
         * STEC residuals for each satellite (mean, stddev).
         */
        public function stecResiduals() { return $this->_m_stecResiduals; }
    }
}

/**
 * STEC residual (mean and standard deviation) for the given satellite at
 * the grid point.
 */

namespace Ssr {
    class StecResidual extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_svId = new \Gnss\SvId($this->_io, $this, $this->_root);
            $this->_m_residual = $this->_io->readS2le();
            $this->_m_stddev = $this->_io->readU1();
        }
        protected $_m_svId;
        protected $_m_residual;
        protected $_m_stddev;

        /**
         * space vehicle identifier
         */
        public function svId() { return $this->_m_svId; }

        /**
         * STEC residual
         */
        public function residual() { return $this->_m_residual; }

        /**
         * Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
         * value/16) - 1) * 10
         */
        public function stddev() { return $this->_m_stddev; }
    }
}

namespace Ssr {
    class CodePhaseBiasesSatSig extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Ssr\MsgSsrCodePhaseBiasesBounds $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_satId = $this->_io->readU1();
            $this->_m_signalId = $this->_io->readU1();
            $this->_m_codeBiasBoundMu = $this->_io->readU1();
            $this->_m_codeBiasBoundSig = $this->_io->readU1();
            $this->_m_phaseBiasBoundMu = $this->_io->readU1();
            $this->_m_phaseBiasBoundSig = $this->_io->readU1();
        }
        protected $_m_satId;
        protected $_m_signalId;
        protected $_m_codeBiasBoundMu;
        protected $_m_codeBiasBoundSig;
        protected $_m_phaseBiasBoundMu;
        protected $_m_phaseBiasBoundSig;

        /**
         * Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
         * or DF488 (BDS) depending on the constellation.
         */
        public function satId() { return $this->_m_satId; }

        /**
         * Signal and Tracking Mode Identifier. Similar to either RTCM DF380
         * (GPS), DF382 (Galileo) or DF467 (BDS) depending on the
         * constellation.
         */
        public function signalId() { return $this->_m_signalId; }

        /**
         * Code Bias Mean. Range: 0-1.275 m
         */
        public function codeBiasBoundMu() { return $this->_m_codeBiasBoundMu; }

        /**
         * Code Bias Standard Deviation.  Range: 0-1.275 m
         */
        public function codeBiasBoundSig() { return $this->_m_codeBiasBoundSig; }

        /**
         * Phase Bias Mean. Range: 0-1.275 m
         */
        public function phaseBiasBoundMu() { return $this->_m_phaseBiasBoundMu; }

        /**
         * Phase Bias Standard Deviation.  Range: 0-1.275 m
         */
        public function phaseBiasBoundSig() { return $this->_m_phaseBiasBoundSig; }
    }
}

/**
 * Contains phase center offset and elevation variation corrections for one
 * signal on a satellite.
 */

namespace Ssr {
    class SatelliteApc extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_satInfo = $this->_io->readU1();
            $this->_m_svn = $this->_io->readU2le();
            $this->_m_pco = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_pco[] = $this->_io->readS2le();
            }
            $this->_m_pcv = [];
            $n = 21;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_pcv[] = $this->_io->readS1();
            }
        }
        protected $_m_sid;
        protected $_m_satInfo;
        protected $_m_svn;
        protected $_m_pco;
        protected $_m_pcv;

        /**
         * GNSS signal identifier (16 bit)
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Additional satellite information
         */
        public function satInfo() { return $this->_m_satInfo; }

        /**
         * Satellite Code, as defined by IGS. Typically the space vehicle
         * number.
         */
        public function svn() { return $this->_m_svn; }

        /**
         * Mean phase center offset, X Y and Z axes. See IGS ANTEX file format
         * description for coordinate system definition.
         */
        public function pco() { return $this->_m_pco; }

        /**
         * Elevation dependent phase center variations. First element is 0
         * degrees separation from the Z axis, subsequent elements represent
         * elevation variations in 1 degree increments.
         */
        public function pcv() { return $this->_m_pcv; }
    }
}

/**
 * The LPP message contains nested variable length arrays which are not
 * supported in SBP, so each grid point will be identified by the index.
 */

namespace Ssr {
    class GriddedCorrectionHeader extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Ssr\MsgSsrGriddedCorrection $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tileSetId = $this->_io->readU2le();
            $this->_m_tileId = $this->_io->readU2le();
            $this->_m_time = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_numMsgs = $this->_io->readU2le();
            $this->_m_seqNum = $this->_io->readU2le();
            $this->_m_updateInterval = $this->_io->readU1();
            $this->_m_iodAtmo = $this->_io->readU1();
            $this->_m_tropoQualityIndicator = $this->_io->readU1();
        }
        protected $_m_tileSetId;
        protected $_m_tileId;
        protected $_m_time;
        protected $_m_numMsgs;
        protected $_m_seqNum;
        protected $_m_updateInterval;
        protected $_m_iodAtmo;
        protected $_m_tropoQualityIndicator;

        /**
         * Unique identifier of the tile set this tile belongs to.
         */
        public function tileSetId() { return $this->_m_tileSetId; }

        /**
         * Unique identifier of this tile in the tile set.
         */
        public function tileId() { return $this->_m_tileId; }

        /**
         * GNSS reference time of the correction
         */
        public function time() { return $this->_m_time; }

        /**
         * Number of messages in the dataset
         */
        public function numMsgs() { return $this->_m_numMsgs; }

        /**
         * Position of this message in the dataset
         */
        public function seqNum() { return $this->_m_seqNum; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public function updateInterval() { return $this->_m_updateInterval; }

        /**
         * IOD of the SSR atmospheric correction
         */
        public function iodAtmo() { return $this->_m_iodAtmo; }

        /**
         * Quality of the troposphere data. Encoded following RTCM DF389
         * specification in units of m.
         */
        public function tropoQualityIndicator() { return $this->_m_tropoQualityIndicator; }
    }
}

/**
 * STEC polynomial for the given satellite.
 */

namespace Ssr {
    class StecSatElement extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_svId = new \Gnss\SvId($this->_io, $this, $this->_root);
            $this->_m_stecQualityIndicator = $this->_io->readU1();
            $this->_m_stecCoeff = [];
            $n = 4;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_stecCoeff[] = $this->_io->readS2le();
            }
        }
        protected $_m_svId;
        protected $_m_stecQualityIndicator;
        protected $_m_stecCoeff;

        /**
         * Unique space vehicle identifier
         */
        public function svId() { return $this->_m_svId; }

        /**
         * Quality of the STEC data. Encoded following RTCM DF389 specification
         * but in units of TECU instead of m.
         */
        public function stecQualityIndicator() { return $this->_m_stecQualityIndicator; }

        /**
         * Coefficients of the STEC polynomial in the order of C00, C01, C10,
         * C11. C00 = 0.05 TECU, C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2
         */
        public function stecCoeff() { return $this->_m_stecCoeff; }
    }
}

/**
 * A full set of STEC information will likely span multiple SBP messages,
 * since SBP message a limited to 255 bytes.  The header is used to tie
 * multiple SBP messages into a sequence.
 */

namespace Ssr {
    class StecHeaderDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Ssr\MsgSsrStecCorrectionDepA $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_time = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_numMsgs = $this->_io->readU1();
            $this->_m_seqNum = $this->_io->readU1();
            $this->_m_updateInterval = $this->_io->readU1();
            $this->_m_iodAtmo = $this->_io->readU1();
        }
        protected $_m_time;
        protected $_m_numMsgs;
        protected $_m_seqNum;
        protected $_m_updateInterval;
        protected $_m_iodAtmo;

        /**
         * GNSS reference time of the correction
         */
        public function time() { return $this->_m_time; }

        /**
         * Number of messages in the dataset
         */
        public function numMsgs() { return $this->_m_numMsgs; }

        /**
         * Position of this message in the dataset
         */
        public function seqNum() { return $this->_m_seqNum; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public function updateInterval() { return $this->_m_updateInterval; }

        /**
         * IOD of the SSR atmospheric correction
         */
        public function iodAtmo() { return $this->_m_iodAtmo; }
    }
}

/**
 * A full set of STEC information will likely span multiple SBP messages,
 * since SBP message a limited to 255 bytes.  The header is used to tie
 * multiple SBP messages into a sequence.
 */

namespace Ssr {
    class StecHeader extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Ssr\MsgSsrStecCorrectionDep $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tileSetId = $this->_io->readU2le();
            $this->_m_tileId = $this->_io->readU2le();
            $this->_m_time = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_numMsgs = $this->_io->readU1();
            $this->_m_seqNum = $this->_io->readU1();
            $this->_m_updateInterval = $this->_io->readU1();
            $this->_m_iodAtmo = $this->_io->readU1();
        }
        protected $_m_tileSetId;
        protected $_m_tileId;
        protected $_m_time;
        protected $_m_numMsgs;
        protected $_m_seqNum;
        protected $_m_updateInterval;
        protected $_m_iodAtmo;

        /**
         * Unique identifier of the tile set this tile belongs to.
         */
        public function tileSetId() { return $this->_m_tileSetId; }

        /**
         * Unique identifier of this tile in the tile set.
         */
        public function tileId() { return $this->_m_tileId; }

        /**
         * GNSS reference time of the correction
         */
        public function time() { return $this->_m_time; }

        /**
         * Number of messages in the dataset
         */
        public function numMsgs() { return $this->_m_numMsgs; }

        /**
         * Position of this message in the dataset
         */
        public function seqNum() { return $this->_m_seqNum; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public function updateInterval() { return $this->_m_updateInterval; }

        /**
         * IOD of the SSR atmospheric correction
         */
        public function iodAtmo() { return $this->_m_iodAtmo; }
    }
}

namespace Ssr {
    class MsgSsrStecCorrectionDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Ssr\StecHeaderDepA($this->_io, $this, $this->_root);
            $this->_m_stecSatList = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_stecSatList[] = new \Ssr\StecSatElement($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_stecSatList;

        /**
         * Header of a STEC message
         */
        public function header() { return $this->_m_header; }

        /**
         * Array of STEC information for each space vehicle
         */
        public function stecSatList() { return $this->_m_stecSatList; }
    }
}

/**
 * The 3GPP message contains nested variable length arrays which are not
 * supported in SBP, so each grid point will be identified by the index.
 */

namespace Ssr {
    class GriddedCorrectionHeaderDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_time = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_numMsgs = $this->_io->readU2le();
            $this->_m_seqNum = $this->_io->readU2le();
            $this->_m_updateInterval = $this->_io->readU1();
            $this->_m_iodAtmo = $this->_io->readU1();
            $this->_m_tropoQualityIndicator = $this->_io->readU1();
        }
        protected $_m_time;
        protected $_m_numMsgs;
        protected $_m_seqNum;
        protected $_m_updateInterval;
        protected $_m_iodAtmo;
        protected $_m_tropoQualityIndicator;

        /**
         * GNSS reference time of the correction
         */
        public function time() { return $this->_m_time; }

        /**
         * Number of messages in the dataset
         */
        public function numMsgs() { return $this->_m_numMsgs; }

        /**
         * Position of this message in the dataset
         */
        public function seqNum() { return $this->_m_seqNum; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public function updateInterval() { return $this->_m_updateInterval; }

        /**
         * IOD of the SSR atmospheric correction
         */
        public function iodAtmo() { return $this->_m_iodAtmo; }

        /**
         * Quality of the troposphere data. Encoded following RTCM DF389
         * specification in units of m.
         */
        public function tropoQualityIndicator() { return $this->_m_tropoQualityIndicator; }
    }
}

/**
 * Note 1: Range: 0-17.5 m. i<=200, mean=0.01i; 200<i<=230,
 * mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
 * 
 * Note 2: Range: 0-17.5 m. i<=200, std=0.01i; 200<i<=230, std=2+0.1(i-200)
 * i>230, std=5+0.5(i-230).
 */

namespace Ssr {
    class MsgSsrOrbitClockBounds extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Ssr\BoundsHeader($this->_io, $this, $this->_root);
            $this->_m_ssrIod = $this->_io->readU1();
            $this->_m_constId = $this->_io->readU1();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_orbitClockBounds = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_orbitClockBounds[] = new \Ssr\OrbitClockBound($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_ssrIod;
        protected $_m_constId;
        protected $_m_nSats;
        protected $_m_orbitClockBounds;

        /**
         * Header of a bounds message.
         */
        public function header() { return $this->_m_header; }

        /**
         * IOD of the SSR bound.
         */
        public function ssrIod() { return $this->_m_ssrIod; }

        /**
         * Constellation ID to which the SVs belong.
         */
        public function constId() { return $this->_m_constId; }

        /**
         * Number of satellites.
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Orbit and Clock Bounds per Satellite
         */
        public function orbitClockBounds() { return $this->_m_orbitClockBounds; }
    }
}

/**
 * Note 1: Range: 0-17.5 m. i<= 200, mean = 0.01i; 200<i<=230,
 * mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
 */

namespace Ssr {
    class MsgSsrGriddedCorrectionBounds extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Ssr\BoundsHeader($this->_io, $this, $this->_root);
            $this->_m_ssrIodAtmo = $this->_io->readU1();
            $this->_m_tileSetId = $this->_io->readU2le();
            $this->_m_tileId = $this->_io->readU2le();
            $this->_m_tropoQi = $this->_io->readU1();
            $this->_m_gridPointId = $this->_io->readU2le();
            $this->_m_tropoDelayCorrection = new \Ssr\TroposphericDelayCorrection($this->_io, $this, $this->_root);
            $this->_m_tropoVHydroBoundMu = $this->_io->readU1();
            $this->_m_tropoVHydroBoundSig = $this->_io->readU1();
            $this->_m_tropoVWetBoundMu = $this->_io->readU1();
            $this->_m_tropoVWetBoundSig = $this->_io->readU1();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_stecSatList = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_stecSatList[] = new \Ssr\StecSatElementIntegrity($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_ssrIodAtmo;
        protected $_m_tileSetId;
        protected $_m_tileId;
        protected $_m_tropoQi;
        protected $_m_gridPointId;
        protected $_m_tropoDelayCorrection;
        protected $_m_tropoVHydroBoundMu;
        protected $_m_tropoVHydroBoundSig;
        protected $_m_tropoVWetBoundMu;
        protected $_m_tropoVWetBoundSig;
        protected $_m_nSats;
        protected $_m_stecSatList;

        /**
         * Header of a bounds message.
         */
        public function header() { return $this->_m_header; }

        /**
         * IOD of the correction.
         */
        public function ssrIodAtmo() { return $this->_m_ssrIodAtmo; }

        /**
         * Set this tile belongs to.
         */
        public function tileSetId() { return $this->_m_tileSetId; }

        /**
         * Unique identifier of this tile in the tile set.
         */
        public function tileId() { return $this->_m_tileId; }

        /**
         * Tropo Quality Indicator. Similar to RTCM DF389.
         */
        public function tropoQi() { return $this->_m_tropoQi; }

        /**
         * Index of the Grid Point.
         */
        public function gridPointId() { return $this->_m_gridPointId; }

        /**
         * Tropospheric delay at grid point.
         */
        public function tropoDelayCorrection() { return $this->_m_tropoDelayCorrection; }

        /**
         * Vertical Hydrostatic Error Bound Mean.
         */
        public function tropoVHydroBoundMu() { return $this->_m_tropoVHydroBoundMu; }

        /**
         * Vertical Hydrostatic Error Bound StDev.
         */
        public function tropoVHydroBoundSig() { return $this->_m_tropoVHydroBoundSig; }

        /**
         * Vertical Wet Error Bound Mean.
         */
        public function tropoVWetBoundMu() { return $this->_m_tropoVWetBoundMu; }

        /**
         * Vertical Wet Error Bound StDev.
         */
        public function tropoVWetBoundSig() { return $this->_m_tropoVWetBoundSig; }

        /**
         * Number of satellites.
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Array of STEC polynomial coefficients and its bounds for each space
         * vehicle.
         */
        public function stecSatList() { return $this->_m_stecSatList; }
    }
}

namespace Ssr {
    class MsgSsrGridDefinitionDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Ssr\GridDefinitionHeaderDepA($this->_io, $this, $this->_root);
            $this->_m_rleList = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_rleList[] = $this->_io->readU1();
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_rleList;

        /**
         * Header of a Gridded Correction message
         */
        public function header() { return $this->_m_header; }

        /**
         * Run Length Encode list of quadrants that contain valid data. The
         * spec describes the encoding scheme in detail, but essentially the
         * index of the quadrants that contain transitions between valid and
         * invalid (and vice versa) are encoded as u8 integers.
         */
        public function rleList() { return $this->_m_rleList; }
    }
}

/**
 * Code biases are to be added to pseudorange. The corrections conform with
 * RTCMv3 MT 1059 / 1065.
 */

namespace Ssr {
    class CodeBiasesContent extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Ssr\MsgSsrCodeBiases $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_code = $this->_io->readU1();
            $this->_m_value = $this->_io->readS2le();
        }
        protected $_m_code;
        protected $_m_value;

        /**
         * Signal encoded following RTCM specifications (DF380, DF381, DF382
         * and DF467).
         */
        public function code() { return $this->_m_code; }

        /**
         * Code bias value
         */
        public function value() { return $this->_m_value; }
    }
}

namespace Ssr {
    class MsgSsrSatelliteApc extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_time = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_updateInterval = $this->_io->readU1();
            $this->_m_solId = $this->_io->readU1();
            $this->_m_iodSsr = $this->_io->readU1();
            $this->_m_apc = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_apc[] = new \Ssr\SatelliteApc($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_time;
        protected $_m_updateInterval;
        protected $_m_solId;
        protected $_m_iodSsr;
        protected $_m_apc;

        /**
         * GNSS reference time of the correction
         */
        public function time() { return $this->_m_time; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public function updateInterval() { return $this->_m_updateInterval; }

        /**
         * SSR Solution ID. Similar to RTCM DF415.
         */
        public function solId() { return $this->_m_solId; }

        /**
         * IOD of the SSR correction. A change of Issue Of Data SSR is used to
         * indicate a change in the SSR generating configuration
         */
        public function iodSsr() { return $this->_m_iodSsr; }

        /**
         * Satellite antenna phase center corrections
         */
        public function apc() { return $this->_m_apc; }
    }
}

/**
 * Phase biases are to be added to carrier phase measurements.
 */

namespace Ssr {
    class PhaseBiasesContent extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Ssr\MsgSsrPhaseBiases $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_code = $this->_io->readU1();
            $this->_m_integerIndicator = $this->_io->readU1();
            $this->_m_widelaneIntegerIndicator = $this->_io->readU1();
            $this->_m_discontinuityCounter = $this->_io->readU1();
            $this->_m_bias = $this->_io->readS4le();
        }
        protected $_m_code;
        protected $_m_integerIndicator;
        protected $_m_widelaneIntegerIndicator;
        protected $_m_discontinuityCounter;
        protected $_m_bias;

        /**
         * Signal encoded following RTCM specifications (DF380, DF381, DF382
         * and DF467)
         */
        public function code() { return $this->_m_code; }

        /**
         * Indicator for integer property
         */
        public function integerIndicator() { return $this->_m_integerIndicator; }

        /**
         * Indicator for two groups of Wide-Lane(s) integer property
         */
        public function widelaneIntegerIndicator() { return $this->_m_widelaneIntegerIndicator; }

        /**
         * Signal phase discontinuity counter. Increased for every
         * discontinuity in phase.
         */
        public function discontinuityCounter() { return $this->_m_discontinuityCounter; }

        /**
         * Phase bias for specified signal
         */
        public function bias() { return $this->_m_bias; }
    }
}

/**
 * Provides the correction point coordinates for the atmospheric correction
 * values in the MSG_SSR_STEC_CORRECTION_DEP and MSG_SSR_GRIDDED_CORRECTION
 * messages.
 * 
 * Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
 * element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
 * correction points, not lists of points.
 */

namespace Ssr {
    class MsgSsrTileDefinitionDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tileSetId = $this->_io->readU2le();
            $this->_m_tileId = $this->_io->readU2le();
            $this->_m_cornerNwLat = $this->_io->readS2le();
            $this->_m_cornerNwLon = $this->_io->readS2le();
            $this->_m_spacingLat = $this->_io->readU2le();
            $this->_m_spacingLon = $this->_io->readU2le();
            $this->_m_rows = $this->_io->readU2le();
            $this->_m_cols = $this->_io->readU2le();
            $this->_m_bitmask = $this->_io->readU8le();
        }
        protected $_m_tileSetId;
        protected $_m_tileId;
        protected $_m_cornerNwLat;
        protected $_m_cornerNwLon;
        protected $_m_spacingLat;
        protected $_m_spacingLon;
        protected $_m_rows;
        protected $_m_cols;
        protected $_m_bitmask;

        /**
         * Unique identifier of the tile set this tile belongs to.
         */
        public function tileSetId() { return $this->_m_tileSetId; }

        /**
         * Unique identifier of this tile in the tile set.
         * See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
         */
        public function tileId() { return $this->_m_tileId; }

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
        public function cornerNwLat() { return $this->_m_cornerNwLat; }

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
        public function cornerNwLon() { return $this->_m_cornerNwLon; }

        /**
         * Spacing of the correction points in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
         */
        public function spacingLat() { return $this->_m_spacingLat; }

        /**
         * Spacing of the correction points in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
         */
        public function spacingLon() { return $this->_m_spacingLon; }

        /**
         * Number of steps in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
         */
        public function rows() { return $this->_m_rows; }

        /**
         * Number of steps in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
         */
        public function cols() { return $this->_m_cols; }

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
        public function bitmask() { return $this->_m_bitmask; }
    }
}

/**
 * Orbit and clock bound.
 */

namespace Ssr {
    class OrbitClockBound extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Ssr\MsgSsrOrbitClockBounds $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_satId = $this->_io->readU1();
            $this->_m_orbRadialBoundMu = $this->_io->readU1();
            $this->_m_orbAlongBoundMu = $this->_io->readU1();
            $this->_m_orbCrossBoundMu = $this->_io->readU1();
            $this->_m_orbRadialBoundSig = $this->_io->readU1();
            $this->_m_orbAlongBoundSig = $this->_io->readU1();
            $this->_m_orbCrossBoundSig = $this->_io->readU1();
            $this->_m_clockBoundMu = $this->_io->readU1();
            $this->_m_clockBoundSig = $this->_io->readU1();
        }
        protected $_m_satId;
        protected $_m_orbRadialBoundMu;
        protected $_m_orbAlongBoundMu;
        protected $_m_orbCrossBoundMu;
        protected $_m_orbRadialBoundSig;
        protected $_m_orbAlongBoundSig;
        protected $_m_orbCrossBoundSig;
        protected $_m_clockBoundMu;
        protected $_m_clockBoundSig;

        /**
         * Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
         * or DF488 (BDS) depending on the constellation.
         */
        public function satId() { return $this->_m_satId; }

        /**
         * Mean Radial. See Note 1.
         */
        public function orbRadialBoundMu() { return $this->_m_orbRadialBoundMu; }

        /**
         * Mean Along-Track. See Note 1.
         */
        public function orbAlongBoundMu() { return $this->_m_orbAlongBoundMu; }

        /**
         * Mean Cross-Track. See Note 1.
         */
        public function orbCrossBoundMu() { return $this->_m_orbCrossBoundMu; }

        /**
         * Standard Deviation Radial. See Note 2.
         */
        public function orbRadialBoundSig() { return $this->_m_orbRadialBoundSig; }

        /**
         * Standard Deviation Along-Track. See Note 2.
         */
        public function orbAlongBoundSig() { return $this->_m_orbAlongBoundSig; }

        /**
         * Standard Deviation Cross-Track. See Note 2.
         */
        public function orbCrossBoundSig() { return $this->_m_orbCrossBoundSig; }

        /**
         * Clock Bound Mean. See Note 1.
         */
        public function clockBoundMu() { return $this->_m_clockBoundMu; }

        /**
         * Clock Bound Standard Deviation. See Note 2.
         */
        public function clockBoundSig() { return $this->_m_clockBoundSig; }
    }
}

namespace Ssr {
    class MsgSsrGriddedCorrectionDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Ssr\GriddedCorrectionHeaderDepA($this->_io, $this, $this->_root);
            $this->_m_index = $this->_io->readU2le();
            $this->_m_tropoDelayCorrection = new \Ssr\TroposphericDelayCorrection($this->_io, $this, $this->_root);
            $this->_m_stecResiduals = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_stecResiduals[] = new \Ssr\StecResidual($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_index;
        protected $_m_tropoDelayCorrection;
        protected $_m_stecResiduals;

        /**
         * Header of a Gridded Correction message
         */
        public function header() { return $this->_m_header; }

        /**
         * Index of the grid point
         */
        public function index() { return $this->_m_index; }

        /**
         * Wet and hydrostatic vertical delays (mean, stddev)
         */
        public function tropoDelayCorrection() { return $this->_m_tropoDelayCorrection; }

        /**
         * STEC residuals for each satellite (mean, stddev)
         */
        public function stecResiduals() { return $this->_m_stecResiduals; }
    }
}

namespace Ssr {
    class MsgSsrOrbitClockBoundsDegradation extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Ssr\BoundsHeader($this->_io, $this, $this->_root);
            $this->_m_ssrIod = $this->_io->readU1();
            $this->_m_constId = $this->_io->readU1();
            $this->_m_satBitmask = $this->_io->readU8le();
            $this->_m_orbitClockBoundsDegradation = new \Ssr\OrbitClockBoundDegradation($this->_io, $this, $this->_root);
        }
        protected $_m_header;
        protected $_m_ssrIod;
        protected $_m_constId;
        protected $_m_satBitmask;
        protected $_m_orbitClockBoundsDegradation;

        /**
         * Header of a bounds message.
         */
        public function header() { return $this->_m_header; }

        /**
         * IOD of the SSR bound degradation parameter.
         */
        public function ssrIod() { return $this->_m_ssrIod; }

        /**
         * Constellation ID to which the SVs belong.
         */
        public function constId() { return $this->_m_constId; }

        /**
         * Satellite Bit Mask. Put 1 for each satellite where the following
         * degradation parameters are applicable, 0 otherwise. Encoded
         * following RTCM DF394 specification.
         */
        public function satBitmask() { return $this->_m_satBitmask; }

        /**
         * Orbit and Clock Bounds Degradation Parameters
         */
        public function orbitClockBoundsDegradation() { return $this->_m_orbitClockBoundsDegradation; }
    }
}

namespace Ssr {
    class MsgSsrGriddedCorrectionNoStdDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Ssr\GriddedCorrectionHeaderDepA($this->_io, $this, $this->_root);
            $this->_m_index = $this->_io->readU2le();
            $this->_m_tropoDelayCorrection = new \Ssr\TroposphericDelayCorrectionNoStd($this->_io, $this, $this->_root);
            $this->_m_stecResiduals = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_stecResiduals[] = new \Ssr\StecResidualNoStd($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_index;
        protected $_m_tropoDelayCorrection;
        protected $_m_stecResiduals;

        /**
         * Header of a Gridded Correction message
         */
        public function header() { return $this->_m_header; }

        /**
         * Index of the grid point
         */
        public function index() { return $this->_m_index; }

        /**
         * Wet and hydrostatic vertical delays
         */
        public function tropoDelayCorrection() { return $this->_m_tropoDelayCorrection; }

        /**
         * STEC residuals for each satellite
         */
        public function stecResiduals() { return $this->_m_stecResiduals; }
    }
}

namespace Ssr {
    class MsgSsrCodePhaseBiasesBounds extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Ssr\BoundsHeader($this->_io, $this, $this->_root);
            $this->_m_ssrIod = $this->_io->readU1();
            $this->_m_constId = $this->_io->readU1();
            $this->_m_nSatsSignals = $this->_io->readU1();
            $this->_m_satellitesSignals = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_satellitesSignals[] = new \Ssr\CodePhaseBiasesSatSig($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_ssrIod;
        protected $_m_constId;
        protected $_m_nSatsSignals;
        protected $_m_satellitesSignals;

        /**
         * Header of a bounds message.
         */
        public function header() { return $this->_m_header; }

        /**
         * IOD of the SSR bound.
         */
        public function ssrIod() { return $this->_m_ssrIod; }

        /**
         * Constellation ID to which the SVs belong.
         */
        public function constId() { return $this->_m_constId; }

        /**
         * Number of satellite-signal couples.
         */
        public function nSatsSignals() { return $this->_m_nSatsSignals; }

        /**
         * Code and Phase Biases Bounds per Satellite-Signal couple.
         */
        public function satellitesSignals() { return $this->_m_satellitesSignals; }
    }
}

/**
 * The precise code biases message is to be added to the pseudorange of the
 * corresponding signal to get corrected pseudorange. It is an equivalent
 * to the 1059 / 1065 RTCM message types.
 */

namespace Ssr {
    class MsgSsrCodeBiases extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_time = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_updateInterval = $this->_io->readU1();
            $this->_m_iodSsr = $this->_io->readU1();
            $this->_m_biases = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_biases[] = new \Ssr\CodeBiasesContent($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_time;
        protected $_m_sid;
        protected $_m_updateInterval;
        protected $_m_iodSsr;
        protected $_m_biases;

        /**
         * GNSS reference time of the correction
         */
        public function time() { return $this->_m_time; }

        /**
         * GNSS signal identifier (16 bit)
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public function updateInterval() { return $this->_m_updateInterval; }

        /**
         * IOD of the SSR correction. A change of Issue Of Data SSR is used to
         * indicate a change in the SSR generating configuration
         */
        public function iodSsr() { return $this->_m_iodSsr; }

        /**
         * Code biases for the different satellite signals
         */
        public function biases() { return $this->_m_biases; }
    }
}

/**
 * Provides the correction point coordinates for the atmospheric correction
 * values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
 * messages.
 * 
 * Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
 * element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
 * correction points, not lists of points.
 */

namespace Ssr {
    class MsgSsrTileDefinition extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_time = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_updateInterval = $this->_io->readU1();
            $this->_m_solId = $this->_io->readU1();
            $this->_m_iodAtmo = $this->_io->readU1();
            $this->_m_tileSetId = $this->_io->readU2le();
            $this->_m_tileId = $this->_io->readU2le();
            $this->_m_cornerNwLat = $this->_io->readS2le();
            $this->_m_cornerNwLon = $this->_io->readS2le();
            $this->_m_spacingLat = $this->_io->readU2le();
            $this->_m_spacingLon = $this->_io->readU2le();
            $this->_m_rows = $this->_io->readU2le();
            $this->_m_cols = $this->_io->readU2le();
            $this->_m_bitmask = $this->_io->readU8le();
        }
        protected $_m_time;
        protected $_m_updateInterval;
        protected $_m_solId;
        protected $_m_iodAtmo;
        protected $_m_tileSetId;
        protected $_m_tileId;
        protected $_m_cornerNwLat;
        protected $_m_cornerNwLon;
        protected $_m_spacingLat;
        protected $_m_spacingLon;
        protected $_m_rows;
        protected $_m_cols;
        protected $_m_bitmask;

        /**
         * GNSS reference time of the correction
         */
        public function time() { return $this->_m_time; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public function updateInterval() { return $this->_m_updateInterval; }

        /**
         * SSR Solution ID. Similar to RTCM DF415.
         */
        public function solId() { return $this->_m_solId; }

        /**
         * IOD of the SSR atmospheric correction.
         */
        public function iodAtmo() { return $this->_m_iodAtmo; }

        /**
         * Unique identifier of the tile set this tile belongs to.
         */
        public function tileSetId() { return $this->_m_tileSetId; }

        /**
         * Unique identifier of this tile in the tile set.
         * See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
         */
        public function tileId() { return $this->_m_tileId; }

        /**
         * North-West corner correction point latitude.
         * 
         * The relation between the latitude X in the range [-90, 90] and the
         * coded number N is:  N = floor((X / 90) * 2^14)
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
         */
        public function cornerNwLat() { return $this->_m_cornerNwLat; }

        /**
         * North-West corner correction point longitude.
         * 
         * The relation between the longitude X in the range [-180, 180] and
         * the coded number N is: N = floor((X / 180) * 2^15)
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
         */
        public function cornerNwLon() { return $this->_m_cornerNwLon; }

        /**
         * Spacing of the correction points in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
         */
        public function spacingLat() { return $this->_m_spacingLat; }

        /**
         * Spacing of the correction points in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
         */
        public function spacingLon() { return $this->_m_spacingLon; }

        /**
         * Number of steps in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
         */
        public function rows() { return $this->_m_rows; }

        /**
         * Number of steps in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
         */
        public function cols() { return $this->_m_cols; }

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
        public function bitmask() { return $this->_m_bitmask; }
    }
}

/**
 * Orbit and clock bound degradation.
 */

namespace Ssr {
    class OrbitClockBoundDegradation extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Ssr\MsgSsrOrbitClockBoundsDegradation $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_orbRadialBoundMuDot = $this->_io->readU1();
            $this->_m_orbAlongBoundMuDot = $this->_io->readU1();
            $this->_m_orbCrossBoundMuDot = $this->_io->readU1();
            $this->_m_orbRadialBoundSigDot = $this->_io->readU1();
            $this->_m_orbAlongBoundSigDot = $this->_io->readU1();
            $this->_m_orbCrossBoundSigDot = $this->_io->readU1();
            $this->_m_clockBoundMuDot = $this->_io->readU1();
            $this->_m_clockBoundSigDot = $this->_io->readU1();
        }
        protected $_m_orbRadialBoundMuDot;
        protected $_m_orbAlongBoundMuDot;
        protected $_m_orbCrossBoundMuDot;
        protected $_m_orbRadialBoundSigDot;
        protected $_m_orbAlongBoundSigDot;
        protected $_m_orbCrossBoundSigDot;
        protected $_m_clockBoundMuDot;
        protected $_m_clockBoundSigDot;

        /**
         * Orbit Bound Mean Radial First derivative. Range: 0-0.255 m/s
         */
        public function orbRadialBoundMuDot() { return $this->_m_orbRadialBoundMuDot; }

        /**
         * Orbit Bound Mean Along-Track First derivative. Range: 0-0.255 m/s
         */
        public function orbAlongBoundMuDot() { return $this->_m_orbAlongBoundMuDot; }

        /**
         * Orbit Bound Mean Cross-Track First derivative. Range: 0-0.255 m/s
         */
        public function orbCrossBoundMuDot() { return $this->_m_orbCrossBoundMuDot; }

        /**
         * Orbit Bound Standard Deviation Radial First derivative. Range:
         * 0-0.255 m/s
         */
        public function orbRadialBoundSigDot() { return $this->_m_orbRadialBoundSigDot; }

        /**
         * Orbit Bound Standard Deviation Along-Track First derivative. Range:
         * 0-0.255 m/s
         */
        public function orbAlongBoundSigDot() { return $this->_m_orbAlongBoundSigDot; }

        /**
         * Orbit Bound Standard Deviation Cross-Track First derivative. Range:
         * 0-0.255 m/s
         */
        public function orbCrossBoundSigDot() { return $this->_m_orbCrossBoundSigDot; }

        /**
         * Clock Bound Mean First derivative. Range: 0-0.255 m/s
         */
        public function clockBoundMuDot() { return $this->_m_clockBoundMuDot; }

        /**
         * Clock Bound Standard Deviation First derivative. Range: 0-0.255 m/s
         */
        public function clockBoundSigDot() { return $this->_m_clockBoundSigDot; }
    }
}

namespace Ssr {
    class MsgSsrSatelliteApcDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_apc = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_apc[] = new \Ssr\SatelliteApc($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_apc;

        /**
         * Satellite antenna phase center corrections
         */
        public function apc() { return $this->_m_apc; }
    }
}

/**
 * Troposphere vertical delays (mean and standard deviation) at the grid
 * point.
 */

namespace Ssr {
    class TroposphericDelayCorrection extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_hydro = $this->_io->readS2le();
            $this->_m_wet = $this->_io->readS1();
            $this->_m_stddev = $this->_io->readU1();
        }
        protected $_m_hydro;
        protected $_m_wet;
        protected $_m_stddev;

        /**
         * Hydrostatic vertical delay. Add 2.3 m to get actual value.
         */
        public function hydro() { return $this->_m_hydro; }

        /**
         * Wet vertical delay. Add 0.252 m to get actual value.
         */
        public function wet() { return $this->_m_wet; }

        /**
         * Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
         * value/16) - 1)
         */
        public function stddev() { return $this->_m_stddev; }
    }
}

/**
 * Provides the correction point coordinates for the atmospheric correction
 * values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
 * messages.
 * 
 * Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
 * element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
 * correction points, not lists of points.
 */

namespace Ssr {
    class MsgSsrTileDefinitionDepB extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_ssrSolId = $this->_io->readU1();
            $this->_m_tileSetId = $this->_io->readU2le();
            $this->_m_tileId = $this->_io->readU2le();
            $this->_m_cornerNwLat = $this->_io->readS2le();
            $this->_m_cornerNwLon = $this->_io->readS2le();
            $this->_m_spacingLat = $this->_io->readU2le();
            $this->_m_spacingLon = $this->_io->readU2le();
            $this->_m_rows = $this->_io->readU2le();
            $this->_m_cols = $this->_io->readU2le();
            $this->_m_bitmask = $this->_io->readU8le();
        }
        protected $_m_ssrSolId;
        protected $_m_tileSetId;
        protected $_m_tileId;
        protected $_m_cornerNwLat;
        protected $_m_cornerNwLon;
        protected $_m_spacingLat;
        protected $_m_spacingLon;
        protected $_m_rows;
        protected $_m_cols;
        protected $_m_bitmask;

        /**
         * SSR Solution ID.
         */
        public function ssrSolId() { return $this->_m_ssrSolId; }

        /**
         * Unique identifier of the tile set this tile belongs to.
         */
        public function tileSetId() { return $this->_m_tileSetId; }

        /**
         * Unique identifier of this tile in the tile set.
         * See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
         */
        public function tileId() { return $this->_m_tileId; }

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
        public function cornerNwLat() { return $this->_m_cornerNwLat; }

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
        public function cornerNwLon() { return $this->_m_cornerNwLon; }

        /**
         * Spacing of the correction points in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
         */
        public function spacingLat() { return $this->_m_spacingLat; }

        /**
         * Spacing of the correction points in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
         */
        public function spacingLon() { return $this->_m_spacingLon; }

        /**
         * Number of steps in the latitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
         */
        public function rows() { return $this->_m_rows; }

        /**
         * Number of steps in the longitude direction.
         * 
         * See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
         */
        public function cols() { return $this->_m_cols; }

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
        public function bitmask() { return $this->_m_bitmask; }
    }
}

/**
 * The precise phase biases message contains the biases to be added to the
 * carrier phase of the corresponding signal to get corrected carrier phase
 * measurement, as well as the satellite yaw angle to be applied to compute
 * the phase wind-up correction. It is typically an equivalent to the 1265
 * RTCM message types.
 */

namespace Ssr {
    class MsgSsrPhaseBiases extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ssr $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_time = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_updateInterval = $this->_io->readU1();
            $this->_m_iodSsr = $this->_io->readU1();
            $this->_m_dispersiveBias = $this->_io->readU1();
            $this->_m_mwConsistency = $this->_io->readU1();
            $this->_m_yaw = $this->_io->readU2le();
            $this->_m_yawRate = $this->_io->readS1();
            $this->_m_biases = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_biases[] = new \Ssr\PhaseBiasesContent($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_time;
        protected $_m_sid;
        protected $_m_updateInterval;
        protected $_m_iodSsr;
        protected $_m_dispersiveBias;
        protected $_m_mwConsistency;
        protected $_m_yaw;
        protected $_m_yawRate;
        protected $_m_biases;

        /**
         * GNSS reference time of the correction
         */
        public function time() { return $this->_m_time; }

        /**
         * GNSS signal identifier (16 bit)
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Update interval between consecutive corrections. Encoded following
         * RTCM DF391 specification.
         */
        public function updateInterval() { return $this->_m_updateInterval; }

        /**
         * IOD of the SSR correction. A change of Issue Of Data SSR is used to
         * indicate a change in the SSR generating configuration
         */
        public function iodSsr() { return $this->_m_iodSsr; }

        /**
         * Indicator for the dispersive phase biases property.
         */
        public function dispersiveBias() { return $this->_m_dispersiveBias; }

        /**
         * Consistency indicator for Melbourne-Wubbena linear combinations
         */
        public function mwConsistency() { return $this->_m_mwConsistency; }

        /**
         * Satellite yaw angle
         */
        public function yaw() { return $this->_m_yaw; }

        /**
         * Satellite yaw angle rate
         */
        public function yawRate() { return $this->_m_yawRate; }

        /**
         * Phase biases corrections for a satellite being tracked.
         */
        public function biases() { return $this->_m_biases; }
    }
}
