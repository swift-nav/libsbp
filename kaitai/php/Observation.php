<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Observation extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * Azimuth and elevation angles of all the visible satellites that the
 * device does have ephemeris or almanac for.
 */

namespace Observation {
    class MsgSvAzEl extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_azel = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_azel[] = new \Observation\SvAzEl($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_azel;

        /**
         * Azimuth and elevation per satellite
         */
        public function azel() { return $this->_m_azel; }
    }
}

namespace Observation {
    class GnssCapb extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Observation\MsgGnssCapb $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_gpsActive = $this->_io->readU8le();
            $this->_m_gpsL2c = $this->_io->readU8le();
            $this->_m_gpsL5 = $this->_io->readU8le();
            $this->_m_gloActive = $this->_io->readU4le();
            $this->_m_gloL2of = $this->_io->readU4le();
            $this->_m_gloL3 = $this->_io->readU4le();
            $this->_m_sbasActive = $this->_io->readU8le();
            $this->_m_sbasL5 = $this->_io->readU8le();
            $this->_m_bdsActive = $this->_io->readU8le();
            $this->_m_bdsD2nav = $this->_io->readU8le();
            $this->_m_bdsB2 = $this->_io->readU8le();
            $this->_m_bdsB2a = $this->_io->readU8le();
            $this->_m_qzssActive = $this->_io->readU4le();
            $this->_m_galActive = $this->_io->readU8le();
            $this->_m_galE5 = $this->_io->readU8le();
        }
        protected $_m_gpsActive;
        protected $_m_gpsL2c;
        protected $_m_gpsL5;
        protected $_m_gloActive;
        protected $_m_gloL2of;
        protected $_m_gloL3;
        protected $_m_sbasActive;
        protected $_m_sbasL5;
        protected $_m_bdsActive;
        protected $_m_bdsD2nav;
        protected $_m_bdsB2;
        protected $_m_bdsB2a;
        protected $_m_qzssActive;
        protected $_m_galActive;
        protected $_m_galE5;

        /**
         * GPS SV active mask
         */
        public function gpsActive() { return $this->_m_gpsActive; }

        /**
         * GPS L2C active mask
         */
        public function gpsL2c() { return $this->_m_gpsL2c; }

        /**
         * GPS L5 active mask
         */
        public function gpsL5() { return $this->_m_gpsL5; }

        /**
         * GLO active mask
         */
        public function gloActive() { return $this->_m_gloActive; }

        /**
         * GLO L2OF active mask
         */
        public function gloL2of() { return $this->_m_gloL2of; }

        /**
         * GLO L3 active mask
         */
        public function gloL3() { return $this->_m_gloL3; }

        /**
         * SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
         * https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
         */
        public function sbasActive() { return $this->_m_sbasActive; }

        /**
         * SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
         * https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
         */
        public function sbasL5() { return $this->_m_sbasL5; }

        /**
         * BDS active mask
         */
        public function bdsActive() { return $this->_m_bdsActive; }

        /**
         * BDS D2NAV active mask
         */
        public function bdsD2nav() { return $this->_m_bdsD2nav; }

        /**
         * BDS B2 active mask
         */
        public function bdsB2() { return $this->_m_bdsB2; }

        /**
         * BDS B2A active mask
         */
        public function bdsB2a() { return $this->_m_bdsB2a; }

        /**
         * QZSS active mask
         */
        public function qzssActive() { return $this->_m_qzssActive; }

        /**
         * GAL active mask
         */
        public function galActive() { return $this->_m_galActive; }

        /**
         * GAL E5 active mask
         */
        public function galE5() { return $this->_m_galE5; }
    }
}

/**
 * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 */

namespace Observation {
    class MsgGroupDelayDepB extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tOp = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_sid = new \Gnss\GnssSignalDep($this->_io, $this, $this->_root);
            $this->_m_valid = $this->_io->readU1();
            $this->_m_tgd = $this->_io->readS2le();
            $this->_m_iscL1ca = $this->_io->readS2le();
            $this->_m_iscL2c = $this->_io->readS2le();
        }
        protected $_m_tOp;
        protected $_m_sid;
        protected $_m_valid;
        protected $_m_tgd;
        protected $_m_iscL1ca;
        protected $_m_iscL2c;

        /**
         * Data Predict Time of Week
         */
        public function tOp() { return $this->_m_tOp; }

        /**
         * GNSS signal identifier
         */
        public function sid() { return $this->_m_sid; }

        /**
         * bit-field indicating validity of the values, LSB indicating tgd
         * validity etc. 1 = value is valid, 0 = value is not valid.
         */
        public function valid() { return $this->_m_valid; }
        public function tgd() { return $this->_m_tgd; }
        public function iscL1ca() { return $this->_m_iscL1ca; }
        public function iscL2c() { return $this->_m_iscL2c; }
    }
}

/**
 * Header of a GPS observation message.
 */

namespace Observation {
    class ObservationHeaderDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_t = new \Gnss\GpsTimeDep($this->_io, $this, $this->_root);
            $this->_m_nObs = $this->_io->readU1();
        }
        protected $_m_t;
        protected $_m_nObs;

        /**
         * GPS time of this observation
         */
        public function t() { return $this->_m_t; }

        /**
         * Total number of observations. First nibble is the size of the
         * sequence (n), second nibble is the zero-indexed counter (ith packet
         * of n)
         */
        public function nObs() { return $this->_m_nObs; }
    }
}

namespace Observation {
    class AlmanacCommonContentDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sid = new \Gnss\GnssSignalDep($this->_io, $this, $this->_root);
            $this->_m_toa = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_ura = $this->_io->readF8le();
            $this->_m_fitInterval = $this->_io->readU4le();
            $this->_m_valid = $this->_io->readU1();
            $this->_m_healthBits = $this->_io->readU1();
        }
        protected $_m_sid;
        protected $_m_toa;
        protected $_m_ura;
        protected $_m_fitInterval;
        protected $_m_valid;
        protected $_m_healthBits;

        /**
         * GNSS signal identifier
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Reference time of almanac
         */
        public function toa() { return $this->_m_toa; }

        /**
         * User Range Accuracy
         */
        public function ura() { return $this->_m_ura; }

        /**
         * Curve fit interval
         */
        public function fitInterval() { return $this->_m_fitInterval; }

        /**
         * Status of almanac, 1 = valid, 0 = invalid
         */
        public function valid() { return $this->_m_valid; }

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
        public function healthBits() { return $this->_m_healthBits; }
    }
}

namespace Observation {
    class EphemerisCommonContentDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sid = new \Gnss\GnssSignalDep($this->_io, $this, $this->_root);
            $this->_m_toe = new \Gnss\GpsTimeDep($this->_io, $this, $this->_root);
            $this->_m_ura = $this->_io->readF8le();
            $this->_m_fitInterval = $this->_io->readU4le();
            $this->_m_valid = $this->_io->readU1();
            $this->_m_healthBits = $this->_io->readU1();
        }
        protected $_m_sid;
        protected $_m_toe;
        protected $_m_ura;
        protected $_m_fitInterval;
        protected $_m_valid;
        protected $_m_healthBits;

        /**
         * GNSS signal identifier
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Time of Ephemerides
         */
        public function toe() { return $this->_m_toe; }

        /**
         * User Range Accuracy
         */
        public function ura() { return $this->_m_ura; }

        /**
         * Curve fit interval
         */
        public function fitInterval() { return $this->_m_fitInterval; }

        /**
         * Status of ephemeris, 1 = valid, 0 = invalid
         */
        public function valid() { return $this->_m_valid; }

        /**
         * Satellite health status.
         * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
         * SBAS: 0 = valid, non-zero = invalid
         * GLO: 0 = valid, non-zero = invalid
         */
        public function healthBits() { return $this->_m_healthBits; }
    }
}

namespace Observation {
    class EphemerisCommonContent extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_toe = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_ura = $this->_io->readF4le();
            $this->_m_fitInterval = $this->_io->readU4le();
            $this->_m_valid = $this->_io->readU1();
            $this->_m_healthBits = $this->_io->readU1();
        }
        protected $_m_sid;
        protected $_m_toe;
        protected $_m_ura;
        protected $_m_fitInterval;
        protected $_m_valid;
        protected $_m_healthBits;

        /**
         * GNSS signal identifier (16 bit)
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Time of Ephemerides
         */
        public function toe() { return $this->_m_toe; }

        /**
         * User Range Accuracy
         */
        public function ura() { return $this->_m_ura; }

        /**
         * Curve fit interval
         */
        public function fitInterval() { return $this->_m_fitInterval; }

        /**
         * Status of ephemeris, 1 = valid, 0 = invalid
         */
        public function valid() { return $this->_m_valid; }

        /**
         * Satellite health status.
         * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
         * SBAS: 0 = valid, non-zero = invalid
         * GLO: 0 = valid, non-zero = invalid
         */
        public function healthBits() { return $this->_m_healthBits; }
    }
}

/**
 * Pseudorange and carrier phase observation for a satellite being tracked.
 * The observations are be interoperable with 3rd party receivers and
 * conform with typical RTCMv3 GNSS observations.
 */

namespace Observation {
    class PackedObsContentDepC extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Observation\MsgObsDepC $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_p = $this->_io->readU4le();
            $this->_m_l = new \Gnss\CarrierPhase($this->_io, $this, $this->_root);
            $this->_m_cn0 = $this->_io->readU1();
            $this->_m_lock = $this->_io->readU2le();
            $this->_m_sid = new \Gnss\GnssSignalDep($this->_io, $this, $this->_root);
        }
        protected $_m_p;
        protected $_m_l;
        protected $_m_cn0;
        protected $_m_lock;
        protected $_m_sid;

        /**
         * Pseudorange observation
         */
        public function p() { return $this->_m_p; }

        /**
         * Carrier phase observation with typical sign convention.
         */
        public function l() { return $this->_m_l; }

        /**
         * Carrier-to-Noise density
         */
        public function cn0() { return $this->_m_cn0; }

        /**
         * Lock indicator. This value changes whenever a satellite signal has
         * lost and regained lock, indicating that the carrier phase ambiguity
         * may have changed.
         */
        public function lock() { return $this->_m_lock; }

        /**
         * GNSS signal identifier
         */
        public function sid() { return $this->_m_sid; }
    }
}

/**
 * This observation message has been deprecated in favor of ephemeris
 * message using floats for size reduction.
 */

namespace Observation {
    class MsgEphemerisGloDepD extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\EphemerisCommonContentDepB($this->_io, $this, $this->_root);
            $this->_m_gamma = $this->_io->readF8le();
            $this->_m_tau = $this->_io->readF8le();
            $this->_m_dTau = $this->_io->readF8le();
            $this->_m_pos = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_pos[] = $this->_io->readF8le();
            }
            $this->_m_vel = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_vel[] = $this->_io->readF8le();
            }
            $this->_m_acc = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_acc[] = $this->_io->readF8le();
            }
            $this->_m_fcn = $this->_io->readU1();
            $this->_m_iod = $this->_io->readU1();
        }
        protected $_m_common;
        protected $_m_gamma;
        protected $_m_tau;
        protected $_m_dTau;
        protected $_m_pos;
        protected $_m_vel;
        protected $_m_acc;
        protected $_m_fcn;
        protected $_m_iod;

        /**
         * Values common for all ephemeris types
         */
        public function common() { return $this->_m_common; }

        /**
         * Relative deviation of predicted carrier frequency from nominal
         */
        public function gamma() { return $this->_m_gamma; }

        /**
         * Correction to the SV time
         */
        public function tau() { return $this->_m_tau; }

        /**
         * Equipment delay between L1 and L2
         */
        public function dTau() { return $this->_m_dTau; }

        /**
         * Position of the SV at tb in PZ-90.02 coordinates system
         */
        public function pos() { return $this->_m_pos; }

        /**
         * Velocity vector of the SV at tb in PZ-90.02 coordinates system
         */
        public function vel() { return $this->_m_vel; }

        /**
         * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
         */
        public function acc() { return $this->_m_acc; }

        /**
         * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
         */
        public function fcn() { return $this->_m_fcn; }

        /**
         * Issue of data. Equal to the 7 bits of the immediate data word t_b
         */
        public function iod() { return $this->_m_iod; }
    }
}

/**
 * Deprecated.
 */

namespace Observation {
    class MsgObsDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Observation\ObservationHeaderDep($this->_io, $this, $this->_root);
            $this->_m_obs = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_obs[] = new \Observation\PackedObsContentDepA($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_obs;

        /**
         * Header of a GPS observation message
         */
        public function header() { return $this->_m_header; }

        /**
         * Pseudorange and carrier phase observation for a satellite being
         * tracked.
         */
        public function obs() { return $this->_m_obs; }
    }
}

/**
 * Deprecated.
 */

namespace Observation {
    class MsgEphemerisDepB extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tgd = $this->_io->readF8le();
            $this->_m_cRs = $this->_io->readF8le();
            $this->_m_cRc = $this->_io->readF8le();
            $this->_m_cUc = $this->_io->readF8le();
            $this->_m_cUs = $this->_io->readF8le();
            $this->_m_cIc = $this->_io->readF8le();
            $this->_m_cIs = $this->_io->readF8le();
            $this->_m_dn = $this->_io->readF8le();
            $this->_m_m0 = $this->_io->readF8le();
            $this->_m_ecc = $this->_io->readF8le();
            $this->_m_sqrta = $this->_io->readF8le();
            $this->_m_omega0 = $this->_io->readF8le();
            $this->_m_omegadot = $this->_io->readF8le();
            $this->_m_w = $this->_io->readF8le();
            $this->_m_inc = $this->_io->readF8le();
            $this->_m_incDot = $this->_io->readF8le();
            $this->_m_af0 = $this->_io->readF8le();
            $this->_m_af1 = $this->_io->readF8le();
            $this->_m_af2 = $this->_io->readF8le();
            $this->_m_toeTow = $this->_io->readF8le();
            $this->_m_toeWn = $this->_io->readU2le();
            $this->_m_tocTow = $this->_io->readF8le();
            $this->_m_tocWn = $this->_io->readU2le();
            $this->_m_valid = $this->_io->readU1();
            $this->_m_healthy = $this->_io->readU1();
            $this->_m_prn = $this->_io->readU1();
            $this->_m_iode = $this->_io->readU1();
        }
        protected $_m_tgd;
        protected $_m_cRs;
        protected $_m_cRc;
        protected $_m_cUc;
        protected $_m_cUs;
        protected $_m_cIc;
        protected $_m_cIs;
        protected $_m_dn;
        protected $_m_m0;
        protected $_m_ecc;
        protected $_m_sqrta;
        protected $_m_omega0;
        protected $_m_omegadot;
        protected $_m_w;
        protected $_m_inc;
        protected $_m_incDot;
        protected $_m_af0;
        protected $_m_af1;
        protected $_m_af2;
        protected $_m_toeTow;
        protected $_m_toeWn;
        protected $_m_tocTow;
        protected $_m_tocWn;
        protected $_m_valid;
        protected $_m_healthy;
        protected $_m_prn;
        protected $_m_iode;

        /**
         * Group delay differential between L1 and L2
         */
        public function tgd() { return $this->_m_tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public function cRs() { return $this->_m_cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public function cRc() { return $this->_m_cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public function cUc() { return $this->_m_cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public function cUs() { return $this->_m_cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public function cIc() { return $this->_m_cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public function cIs() { return $this->_m_cIs; }

        /**
         * Mean motion difference
         */
        public function dn() { return $this->_m_dn; }

        /**
         * Mean anomaly at reference time
         */
        public function m0() { return $this->_m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public function ecc() { return $this->_m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public function sqrta() { return $this->_m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public function omega0() { return $this->_m_omega0; }

        /**
         * Rate of right ascension
         */
        public function omegadot() { return $this->_m_omegadot; }

        /**
         * Argument of perigee
         */
        public function w() { return $this->_m_w; }

        /**
         * Inclination
         */
        public function inc() { return $this->_m_inc; }

        /**
         * Inclination first derivative
         */
        public function incDot() { return $this->_m_incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public function af0() { return $this->_m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public function af1() { return $this->_m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public function af2() { return $this->_m_af2; }

        /**
         * Time of week
         */
        public function toeTow() { return $this->_m_toeTow; }

        /**
         * Week number
         */
        public function toeWn() { return $this->_m_toeWn; }

        /**
         * Clock reference time of week
         */
        public function tocTow() { return $this->_m_tocTow; }

        /**
         * Clock reference week number
         */
        public function tocWn() { return $this->_m_tocWn; }

        /**
         * Is valid?
         */
        public function valid() { return $this->_m_valid; }

        /**
         * Satellite is healthy?
         */
        public function healthy() { return $this->_m_healthy; }

        /**
         * PRN being tracked
         */
        public function prn() { return $this->_m_prn; }

        /**
         * Issue of ephemeris data
         */
        public function iode() { return $this->_m_iode; }
    }
}

/**
 * The GPS observations message reports all the raw pseudorange and carrier
 * phase observations for the satellites being tracked by the device.
 * Carrier phase observation here is represented as a 40-bit fixed point
 * number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
 * fractional cycles). The observations are be interoperable with 3rd party
 * receivers and conform with typical RTCMv3 GNSS observations.
 */

namespace Observation {
    class MsgObs extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Observation\ObservationHeader($this->_io, $this, $this->_root);
            $this->_m_obs = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_obs[] = new \Observation\PackedObsContent($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_obs;

        /**
         * Header of a GPS observation message
         */
        public function header() { return $this->_m_header; }

        /**
         * Pseudorange and carrier phase observation for a satellite being
         * tracked.
         */
        public function obs() { return $this->_m_obs; }
    }
}

/**
 * Doppler measurement in Hz represented as a 24-bit fixed point number
 * with Q16.8 layout, i.e. 16-bits of whole doppler and 8-bits of
 * fractional doppler. This doppler is defined as positive for approaching
 * satellites.
 */

namespace Observation {
    class Doppler extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Observation\PackedObsContent $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_i = $this->_io->readS2le();
            $this->_m_f = $this->_io->readU1();
        }
        protected $_m_i;
        protected $_m_f;

        /**
         * Doppler whole Hz
         */
        public function i() { return $this->_m_i; }

        /**
         * Doppler fractional part
         */
        public function f() { return $this->_m_f; }
    }
}

/**
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several
 * months. Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate
 * information and almanac" for details.
 */

namespace Observation {
    class MsgAlmanacGloDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\AlmanacCommonContentDep($this->_io, $this, $this->_root);
            $this->_m_lambdaNa = $this->_io->readF8le();
            $this->_m_tLambdaNa = $this->_io->readF8le();
            $this->_m_i = $this->_io->readF8le();
            $this->_m_t = $this->_io->readF8le();
            $this->_m_tDot = $this->_io->readF8le();
            $this->_m_epsilon = $this->_io->readF8le();
            $this->_m_omega = $this->_io->readF8le();
        }
        protected $_m_common;
        protected $_m_lambdaNa;
        protected $_m_tLambdaNa;
        protected $_m_i;
        protected $_m_t;
        protected $_m_tDot;
        protected $_m_epsilon;
        protected $_m_omega;

        /**
         * Values common for all almanac types
         */
        public function common() { return $this->_m_common; }

        /**
         * Longitude of the first ascending node of the orbit in PZ-90.02
         * coordinate system
         */
        public function lambdaNa() { return $this->_m_lambdaNa; }

        /**
         * Time of the first ascending node passage
         */
        public function tLambdaNa() { return $this->_m_tLambdaNa; }

        /**
         * Value of inclination at instant of t_lambda
         */
        public function i() { return $this->_m_i; }

        /**
         * Value of Draconian period at instant of t_lambda
         */
        public function t() { return $this->_m_t; }

        /**
         * Rate of change of the Draconian period
         */
        public function tDot() { return $this->_m_tDot; }

        /**
         * Eccentricity at instant of t_lambda
         */
        public function epsilon() { return $this->_m_epsilon; }

        /**
         * Argument of perigee at instant of t_lambda
         */
        public function omega() { return $this->_m_omega; }
    }
}

/**
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several
 * months. Please see the Navstar GPS Space Segment/Navigation user
 * interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more
 * details.
 */

namespace Observation {
    class MsgAlmanacGpsDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\AlmanacCommonContentDep($this->_io, $this, $this->_root);
            $this->_m_m0 = $this->_io->readF8le();
            $this->_m_ecc = $this->_io->readF8le();
            $this->_m_sqrta = $this->_io->readF8le();
            $this->_m_omega0 = $this->_io->readF8le();
            $this->_m_omegadot = $this->_io->readF8le();
            $this->_m_w = $this->_io->readF8le();
            $this->_m_inc = $this->_io->readF8le();
            $this->_m_af0 = $this->_io->readF8le();
            $this->_m_af1 = $this->_io->readF8le();
        }
        protected $_m_common;
        protected $_m_m0;
        protected $_m_ecc;
        protected $_m_sqrta;
        protected $_m_omega0;
        protected $_m_omegadot;
        protected $_m_w;
        protected $_m_inc;
        protected $_m_af0;
        protected $_m_af1;

        /**
         * Values common for all almanac types
         */
        public function common() { return $this->_m_common; }

        /**
         * Mean anomaly at reference time
         */
        public function m0() { return $this->_m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public function ecc() { return $this->_m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public function sqrta() { return $this->_m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public function omega0() { return $this->_m_omega0; }

        /**
         * Rate of right ascension
         */
        public function omegadot() { return $this->_m_omegadot; }

        /**
         * Argument of perigee
         */
        public function w() { return $this->_m_w; }

        /**
         * Inclination
         */
        public function inc() { return $this->_m_inc; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public function af0() { return $this->_m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public function af1() { return $this->_m_af1; }
    }
}

/**
 * Satellite azimuth and elevation.
 */

namespace Observation {
    class SvAzEl extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Observation\MsgSvAzEl $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_az = $this->_io->readU1();
            $this->_m_el = $this->_io->readS1();
        }
        protected $_m_sid;
        protected $_m_az;
        protected $_m_el;

        /**
         * GNSS signal identifier
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Azimuth angle (range 0..179)
         */
        public function az() { return $this->_m_az; }

        /**
         * Elevation angle (range -90..90)
         */
        public function el() { return $this->_m_el; }
    }
}

/**
 * The GLONASS L1/L2 Code-Phase biases allows to perform GPS+GLONASS
 * integer ambiguity resolution for baselines with mixed receiver types
 * (e.g. receiver of different manufacturers).
 */

namespace Observation {
    class MsgGloBiases extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_mask = $this->_io->readU1();
            $this->_m_l1caBias = $this->_io->readS2le();
            $this->_m_l1pBias = $this->_io->readS2le();
            $this->_m_l2caBias = $this->_io->readS2le();
            $this->_m_l2pBias = $this->_io->readS2le();
        }
        protected $_m_mask;
        protected $_m_l1caBias;
        protected $_m_l1pBias;
        protected $_m_l2caBias;
        protected $_m_l2pBias;

        /**
         * GLONASS FDMA signals mask
         */
        public function mask() { return $this->_m_mask; }

        /**
         * GLONASS L1 C/A Code-Phase Bias
         */
        public function l1caBias() { return $this->_m_l1caBias; }

        /**
         * GLONASS L1 P Code-Phase Bias
         */
        public function l1pBias() { return $this->_m_l1pBias; }

        /**
         * GLONASS L2 C/A Code-Phase Bias
         */
        public function l2caBias() { return $this->_m_l2caBias; }

        /**
         * GLONASS L2 P Code-Phase Bias
         */
        public function l2pBias() { return $this->_m_l2pBias; }
    }
}

/**
 * This observation message has been deprecated in favor of ephemeris
 * message using floats for size reduction.
 */

namespace Observation {
    class MsgEphemerisSbasDepB extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\EphemerisCommonContentDepB($this->_io, $this, $this->_root);
            $this->_m_pos = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_pos[] = $this->_io->readF8le();
            }
            $this->_m_vel = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_vel[] = $this->_io->readF8le();
            }
            $this->_m_acc = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_acc[] = $this->_io->readF8le();
            }
            $this->_m_aGf0 = $this->_io->readF8le();
            $this->_m_aGf1 = $this->_io->readF8le();
        }
        protected $_m_common;
        protected $_m_pos;
        protected $_m_vel;
        protected $_m_acc;
        protected $_m_aGf0;
        protected $_m_aGf1;

        /**
         * Values common for all ephemeris types
         */
        public function common() { return $this->_m_common; }

        /**
         * Position of the GEO at time toe
         */
        public function pos() { return $this->_m_pos; }

        /**
         * Velocity of the GEO at time toe
         */
        public function vel() { return $this->_m_vel; }

        /**
         * Acceleration of the GEO at time toe
         */
        public function acc() { return $this->_m_acc; }

        /**
         * Time offset of the GEO clock w.r.t. SBAS Network Time
         */
        public function aGf0() { return $this->_m_aGf0; }

        /**
         * Drift of the GEO clock w.r.t. SBAS Network Time
         */
        public function aGf1() { return $this->_m_aGf1; }
    }
}

/**
 * The ephemeris message returns a set of satellite orbit parameters that
 * is used to calculate GPS satellite position, velocity, and clock offset.
 * Please see the Navstar GPS Space Segment/Navigation user interfaces
 * (ICD-GPS-200, Table 20-III) for more details.
 */

namespace Observation {
    class MsgEphemerisGpsDepE extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\EphemerisCommonContentDepA($this->_io, $this, $this->_root);
            $this->_m_tgd = $this->_io->readF8le();
            $this->_m_cRs = $this->_io->readF8le();
            $this->_m_cRc = $this->_io->readF8le();
            $this->_m_cUc = $this->_io->readF8le();
            $this->_m_cUs = $this->_io->readF8le();
            $this->_m_cIc = $this->_io->readF8le();
            $this->_m_cIs = $this->_io->readF8le();
            $this->_m_dn = $this->_io->readF8le();
            $this->_m_m0 = $this->_io->readF8le();
            $this->_m_ecc = $this->_io->readF8le();
            $this->_m_sqrta = $this->_io->readF8le();
            $this->_m_omega0 = $this->_io->readF8le();
            $this->_m_omegadot = $this->_io->readF8le();
            $this->_m_w = $this->_io->readF8le();
            $this->_m_inc = $this->_io->readF8le();
            $this->_m_incDot = $this->_io->readF8le();
            $this->_m_af0 = $this->_io->readF8le();
            $this->_m_af1 = $this->_io->readF8le();
            $this->_m_af2 = $this->_io->readF8le();
            $this->_m_toc = new \Gnss\GpsTimeDep($this->_io, $this, $this->_root);
            $this->_m_iode = $this->_io->readU1();
            $this->_m_iodc = $this->_io->readU2le();
        }
        protected $_m_common;
        protected $_m_tgd;
        protected $_m_cRs;
        protected $_m_cRc;
        protected $_m_cUc;
        protected $_m_cUs;
        protected $_m_cIc;
        protected $_m_cIs;
        protected $_m_dn;
        protected $_m_m0;
        protected $_m_ecc;
        protected $_m_sqrta;
        protected $_m_omega0;
        protected $_m_omegadot;
        protected $_m_w;
        protected $_m_inc;
        protected $_m_incDot;
        protected $_m_af0;
        protected $_m_af1;
        protected $_m_af2;
        protected $_m_toc;
        protected $_m_iode;
        protected $_m_iodc;

        /**
         * Values common for all ephemeris types
         */
        public function common() { return $this->_m_common; }

        /**
         * Group delay differential between L1 and L2
         */
        public function tgd() { return $this->_m_tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public function cRs() { return $this->_m_cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public function cRc() { return $this->_m_cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public function cUc() { return $this->_m_cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public function cUs() { return $this->_m_cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public function cIc() { return $this->_m_cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public function cIs() { return $this->_m_cIs; }

        /**
         * Mean motion difference
         */
        public function dn() { return $this->_m_dn; }

        /**
         * Mean anomaly at reference time
         */
        public function m0() { return $this->_m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public function ecc() { return $this->_m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public function sqrta() { return $this->_m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public function omega0() { return $this->_m_omega0; }

        /**
         * Rate of right ascension
         */
        public function omegadot() { return $this->_m_omegadot; }

        /**
         * Argument of perigee
         */
        public function w() { return $this->_m_w; }

        /**
         * Inclination
         */
        public function inc() { return $this->_m_inc; }

        /**
         * Inclination first derivative
         */
        public function incDot() { return $this->_m_incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public function af0() { return $this->_m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public function af1() { return $this->_m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public function af2() { return $this->_m_af2; }

        /**
         * Clock reference
         */
        public function toc() { return $this->_m_toc; }

        /**
         * Issue of ephemeris data
         */
        public function iode() { return $this->_m_iode; }

        /**
         * Issue of clock data
         */
        public function iodc() { return $this->_m_iodc; }
    }
}

namespace Observation {
    class MsgGnssCapb extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tNmct = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_gc = new \Observation\GnssCapb($this->_io, $this, $this->_root);
        }
        protected $_m_tNmct;
        protected $_m_gc;

        /**
         * Navigation Message Correction Table Validity Time
         */
        public function tNmct() { return $this->_m_tNmct; }

        /**
         * GNSS capabilities masks
         */
        public function gc() { return $this->_m_gc; }
    }
}

/**
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several
 * months. Please see the Navstar GPS Space Segment/Navigation user
 * interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more
 * details.
 */

namespace Observation {
    class MsgAlmanacGps extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\AlmanacCommonContent($this->_io, $this, $this->_root);
            $this->_m_m0 = $this->_io->readF8le();
            $this->_m_ecc = $this->_io->readF8le();
            $this->_m_sqrta = $this->_io->readF8le();
            $this->_m_omega0 = $this->_io->readF8le();
            $this->_m_omegadot = $this->_io->readF8le();
            $this->_m_w = $this->_io->readF8le();
            $this->_m_inc = $this->_io->readF8le();
            $this->_m_af0 = $this->_io->readF8le();
            $this->_m_af1 = $this->_io->readF8le();
        }
        protected $_m_common;
        protected $_m_m0;
        protected $_m_ecc;
        protected $_m_sqrta;
        protected $_m_omega0;
        protected $_m_omegadot;
        protected $_m_w;
        protected $_m_inc;
        protected $_m_af0;
        protected $_m_af1;

        /**
         * Values common for all almanac types
         */
        public function common() { return $this->_m_common; }

        /**
         * Mean anomaly at reference time
         */
        public function m0() { return $this->_m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public function ecc() { return $this->_m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public function sqrta() { return $this->_m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public function omega0() { return $this->_m_omega0; }

        /**
         * Rate of right ascension
         */
        public function omegadot() { return $this->_m_omegadot; }

        /**
         * Argument of perigee
         */
        public function w() { return $this->_m_w; }

        /**
         * Inclination
         */
        public function inc() { return $this->_m_inc; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public function af0() { return $this->_m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public function af1() { return $this->_m_af1; }
    }
}

/**
 * The ephemeris message returns a set of satellite orbit parameters that
 * is used to calculate QZSS satellite position, velocity, and clock
 * offset.
 */

namespace Observation {
    class MsgEphemerisQzss extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\EphemerisCommonContent($this->_io, $this, $this->_root);
            $this->_m_tgd = $this->_io->readF4le();
            $this->_m_cRs = $this->_io->readF4le();
            $this->_m_cRc = $this->_io->readF4le();
            $this->_m_cUc = $this->_io->readF4le();
            $this->_m_cUs = $this->_io->readF4le();
            $this->_m_cIc = $this->_io->readF4le();
            $this->_m_cIs = $this->_io->readF4le();
            $this->_m_dn = $this->_io->readF8le();
            $this->_m_m0 = $this->_io->readF8le();
            $this->_m_ecc = $this->_io->readF8le();
            $this->_m_sqrta = $this->_io->readF8le();
            $this->_m_omega0 = $this->_io->readF8le();
            $this->_m_omegadot = $this->_io->readF8le();
            $this->_m_w = $this->_io->readF8le();
            $this->_m_inc = $this->_io->readF8le();
            $this->_m_incDot = $this->_io->readF8le();
            $this->_m_af0 = $this->_io->readF4le();
            $this->_m_af1 = $this->_io->readF4le();
            $this->_m_af2 = $this->_io->readF4le();
            $this->_m_toc = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_iode = $this->_io->readU1();
            $this->_m_iodc = $this->_io->readU2le();
        }
        protected $_m_common;
        protected $_m_tgd;
        protected $_m_cRs;
        protected $_m_cRc;
        protected $_m_cUc;
        protected $_m_cUs;
        protected $_m_cIc;
        protected $_m_cIs;
        protected $_m_dn;
        protected $_m_m0;
        protected $_m_ecc;
        protected $_m_sqrta;
        protected $_m_omega0;
        protected $_m_omegadot;
        protected $_m_w;
        protected $_m_inc;
        protected $_m_incDot;
        protected $_m_af0;
        protected $_m_af1;
        protected $_m_af2;
        protected $_m_toc;
        protected $_m_iode;
        protected $_m_iodc;

        /**
         * Values common for all ephemeris types
         */
        public function common() { return $this->_m_common; }

        /**
         * Group delay differential between L1 and L2
         */
        public function tgd() { return $this->_m_tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public function cRs() { return $this->_m_cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public function cRc() { return $this->_m_cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public function cUc() { return $this->_m_cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public function cUs() { return $this->_m_cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public function cIc() { return $this->_m_cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public function cIs() { return $this->_m_cIs; }

        /**
         * Mean motion difference
         */
        public function dn() { return $this->_m_dn; }

        /**
         * Mean anomaly at reference time
         */
        public function m0() { return $this->_m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public function ecc() { return $this->_m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public function sqrta() { return $this->_m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public function omega0() { return $this->_m_omega0; }

        /**
         * Rate of right ascension
         */
        public function omegadot() { return $this->_m_omegadot; }

        /**
         * Argument of perigee
         */
        public function w() { return $this->_m_w; }

        /**
         * Inclination
         */
        public function inc() { return $this->_m_inc; }

        /**
         * Inclination first derivative
         */
        public function incDot() { return $this->_m_incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public function af0() { return $this->_m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public function af1() { return $this->_m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public function af2() { return $this->_m_af2; }

        /**
         * Clock reference
         */
        public function toc() { return $this->_m_toc; }

        /**
         * Issue of ephemeris data
         */
        public function iode() { return $this->_m_iode; }

        /**
         * Issue of clock data
         */
        public function iodc() { return $this->_m_iodc; }
    }
}

/**
 * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 */

namespace Observation {
    class MsgGroupDelayDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tOp = new \Gnss\GpsTimeDep($this->_io, $this, $this->_root);
            $this->_m_prn = $this->_io->readU1();
            $this->_m_valid = $this->_io->readU1();
            $this->_m_tgd = $this->_io->readS2le();
            $this->_m_iscL1ca = $this->_io->readS2le();
            $this->_m_iscL2c = $this->_io->readS2le();
        }
        protected $_m_tOp;
        protected $_m_prn;
        protected $_m_valid;
        protected $_m_tgd;
        protected $_m_iscL1ca;
        protected $_m_iscL2c;

        /**
         * Data Predict Time of Week
         */
        public function tOp() { return $this->_m_tOp; }

        /**
         * Satellite number
         */
        public function prn() { return $this->_m_prn; }

        /**
         * bit-field indicating validity of the values, LSB indicating tgd
         * validity etc. 1 = value is valid, 0 = value is not valid.
         */
        public function valid() { return $this->_m_valid; }
        public function tgd() { return $this->_m_tgd; }
        public function iscL1ca() { return $this->_m_iscL1ca; }
        public function iscL2c() { return $this->_m_iscL2c; }
    }
}

/**
 * The ephemeris message returns a set of satellite orbit parameters that
 * is used to calculate GPS satellite position, velocity, and clock offset.
 * Please see the Navstar GPS Space Segment/Navigation user interfaces
 * (ICD-GPS-200, Table 20-III) for more details.
 */

namespace Observation {
    class MsgEphemerisDepC extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tgd = $this->_io->readF8le();
            $this->_m_cRs = $this->_io->readF8le();
            $this->_m_cRc = $this->_io->readF8le();
            $this->_m_cUc = $this->_io->readF8le();
            $this->_m_cUs = $this->_io->readF8le();
            $this->_m_cIc = $this->_io->readF8le();
            $this->_m_cIs = $this->_io->readF8le();
            $this->_m_dn = $this->_io->readF8le();
            $this->_m_m0 = $this->_io->readF8le();
            $this->_m_ecc = $this->_io->readF8le();
            $this->_m_sqrta = $this->_io->readF8le();
            $this->_m_omega0 = $this->_io->readF8le();
            $this->_m_omegadot = $this->_io->readF8le();
            $this->_m_w = $this->_io->readF8le();
            $this->_m_inc = $this->_io->readF8le();
            $this->_m_incDot = $this->_io->readF8le();
            $this->_m_af0 = $this->_io->readF8le();
            $this->_m_af1 = $this->_io->readF8le();
            $this->_m_af2 = $this->_io->readF8le();
            $this->_m_toeTow = $this->_io->readF8le();
            $this->_m_toeWn = $this->_io->readU2le();
            $this->_m_tocTow = $this->_io->readF8le();
            $this->_m_tocWn = $this->_io->readU2le();
            $this->_m_valid = $this->_io->readU1();
            $this->_m_healthy = $this->_io->readU1();
            $this->_m_sid = new \Gnss\GnssSignalDep($this->_io, $this, $this->_root);
            $this->_m_iode = $this->_io->readU1();
            $this->_m_iodc = $this->_io->readU2le();
            $this->_m_reserved = $this->_io->readU4le();
        }
        protected $_m_tgd;
        protected $_m_cRs;
        protected $_m_cRc;
        protected $_m_cUc;
        protected $_m_cUs;
        protected $_m_cIc;
        protected $_m_cIs;
        protected $_m_dn;
        protected $_m_m0;
        protected $_m_ecc;
        protected $_m_sqrta;
        protected $_m_omega0;
        protected $_m_omegadot;
        protected $_m_w;
        protected $_m_inc;
        protected $_m_incDot;
        protected $_m_af0;
        protected $_m_af1;
        protected $_m_af2;
        protected $_m_toeTow;
        protected $_m_toeWn;
        protected $_m_tocTow;
        protected $_m_tocWn;
        protected $_m_valid;
        protected $_m_healthy;
        protected $_m_sid;
        protected $_m_iode;
        protected $_m_iodc;
        protected $_m_reserved;

        /**
         * Group delay differential between L1 and L2
         */
        public function tgd() { return $this->_m_tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public function cRs() { return $this->_m_cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public function cRc() { return $this->_m_cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public function cUc() { return $this->_m_cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public function cUs() { return $this->_m_cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public function cIc() { return $this->_m_cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public function cIs() { return $this->_m_cIs; }

        /**
         * Mean motion difference
         */
        public function dn() { return $this->_m_dn; }

        /**
         * Mean anomaly at reference time
         */
        public function m0() { return $this->_m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public function ecc() { return $this->_m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public function sqrta() { return $this->_m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public function omega0() { return $this->_m_omega0; }

        /**
         * Rate of right ascension
         */
        public function omegadot() { return $this->_m_omegadot; }

        /**
         * Argument of perigee
         */
        public function w() { return $this->_m_w; }

        /**
         * Inclination
         */
        public function inc() { return $this->_m_inc; }

        /**
         * Inclination first derivative
         */
        public function incDot() { return $this->_m_incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public function af0() { return $this->_m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public function af1() { return $this->_m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public function af2() { return $this->_m_af2; }

        /**
         * Time of week
         */
        public function toeTow() { return $this->_m_toeTow; }

        /**
         * Week number
         */
        public function toeWn() { return $this->_m_toeWn; }

        /**
         * Clock reference time of week
         */
        public function tocTow() { return $this->_m_tocTow; }

        /**
         * Clock reference week number
         */
        public function tocWn() { return $this->_m_tocWn; }

        /**
         * Is valid?
         */
        public function valid() { return $this->_m_valid; }

        /**
         * Satellite is healthy?
         */
        public function healthy() { return $this->_m_healthy; }

        /**
         * GNSS signal identifier
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Issue of ephemeris data
         */
        public function iode() { return $this->_m_iode; }

        /**
         * Issue of clock data
         */
        public function iodc() { return $this->_m_iodc; }

        /**
         * Reserved field
         */
        public function reserved() { return $this->_m_reserved; }
    }
}

/**
 * Carrier phase measurement in cycles represented as a 40-bit fixed point
 * number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
 * fractional cycles. This has the opposite sign convention than a typical
 * GPS receiver and the phase has the opposite sign as the pseudorange.
 */

namespace Observation {
    class CarrierPhaseDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_i = $this->_io->readS4le();
            $this->_m_f = $this->_io->readU1();
        }
        protected $_m_i;
        protected $_m_f;

        /**
         * Carrier phase whole cycles
         */
        public function i() { return $this->_m_i; }

        /**
         * Carrier phase fractional part
         */
        public function f() { return $this->_m_f; }
    }
}

/**
 * The ephemeris message returns a set of satellite orbit parameters that
 * is used to calculate Galileo satellite position, velocity, and clock
 * offset. Please see the Signal In Space ICD OS SIS ICD, Issue 1.3,
 * December 2016 for more details.
 */

namespace Observation {
    class MsgEphemerisGal extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\EphemerisCommonContent($this->_io, $this, $this->_root);
            $this->_m_bgdE1e5a = $this->_io->readF4le();
            $this->_m_bgdE1e5b = $this->_io->readF4le();
            $this->_m_cRs = $this->_io->readF4le();
            $this->_m_cRc = $this->_io->readF4le();
            $this->_m_cUc = $this->_io->readF4le();
            $this->_m_cUs = $this->_io->readF4le();
            $this->_m_cIc = $this->_io->readF4le();
            $this->_m_cIs = $this->_io->readF4le();
            $this->_m_dn = $this->_io->readF8le();
            $this->_m_m0 = $this->_io->readF8le();
            $this->_m_ecc = $this->_io->readF8le();
            $this->_m_sqrta = $this->_io->readF8le();
            $this->_m_omega0 = $this->_io->readF8le();
            $this->_m_omegadot = $this->_io->readF8le();
            $this->_m_w = $this->_io->readF8le();
            $this->_m_inc = $this->_io->readF8le();
            $this->_m_incDot = $this->_io->readF8le();
            $this->_m_af0 = $this->_io->readF8le();
            $this->_m_af1 = $this->_io->readF8le();
            $this->_m_af2 = $this->_io->readF4le();
            $this->_m_toc = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_iode = $this->_io->readU2le();
            $this->_m_iodc = $this->_io->readU2le();
            $this->_m_source = $this->_io->readU1();
        }
        protected $_m_common;
        protected $_m_bgdE1e5a;
        protected $_m_bgdE1e5b;
        protected $_m_cRs;
        protected $_m_cRc;
        protected $_m_cUc;
        protected $_m_cUs;
        protected $_m_cIc;
        protected $_m_cIs;
        protected $_m_dn;
        protected $_m_m0;
        protected $_m_ecc;
        protected $_m_sqrta;
        protected $_m_omega0;
        protected $_m_omegadot;
        protected $_m_w;
        protected $_m_inc;
        protected $_m_incDot;
        protected $_m_af0;
        protected $_m_af1;
        protected $_m_af2;
        protected $_m_toc;
        protected $_m_iode;
        protected $_m_iodc;
        protected $_m_source;

        /**
         * Values common for all ephemeris types
         */
        public function common() { return $this->_m_common; }

        /**
         * E1-E5a Broadcast Group Delay
         */
        public function bgdE1e5a() { return $this->_m_bgdE1e5a; }

        /**
         * E1-E5b Broadcast Group Delay
         */
        public function bgdE1e5b() { return $this->_m_bgdE1e5b; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public function cRs() { return $this->_m_cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public function cRc() { return $this->_m_cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public function cUc() { return $this->_m_cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public function cUs() { return $this->_m_cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public function cIc() { return $this->_m_cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public function cIs() { return $this->_m_cIs; }

        /**
         * Mean motion difference
         */
        public function dn() { return $this->_m_dn; }

        /**
         * Mean anomaly at reference time
         */
        public function m0() { return $this->_m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public function ecc() { return $this->_m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public function sqrta() { return $this->_m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public function omega0() { return $this->_m_omega0; }

        /**
         * Rate of right ascension
         */
        public function omegadot() { return $this->_m_omegadot; }

        /**
         * Argument of perigee
         */
        public function w() { return $this->_m_w; }

        /**
         * Inclination
         */
        public function inc() { return $this->_m_inc; }

        /**
         * Inclination first derivative
         */
        public function incDot() { return $this->_m_incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public function af0() { return $this->_m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public function af1() { return $this->_m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public function af2() { return $this->_m_af2; }

        /**
         * Clock reference
         */
        public function toc() { return $this->_m_toc; }

        /**
         * Issue of data (IODnav)
         */
        public function iode() { return $this->_m_iode; }

        /**
         * Issue of data (IODnav). Always equal to iode
         */
        public function iodc() { return $this->_m_iodc; }

        /**
         * 0=I/NAV, 1=F/NAV
         */
        public function source() { return $this->_m_source; }
    }
}

/**
 * Pseudorange and carrier phase network corrections for a satellite
 * signal.
 */

namespace Observation {
    class PackedOsrContent extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Observation\MsgOsr $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_p = $this->_io->readU4le();
            $this->_m_l = new \Gnss\CarrierPhase($this->_io, $this, $this->_root);
            $this->_m_lock = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_ionoStd = $this->_io->readU2le();
            $this->_m_tropoStd = $this->_io->readU2le();
            $this->_m_rangeStd = $this->_io->readU2le();
        }
        protected $_m_p;
        protected $_m_l;
        protected $_m_lock;
        protected $_m_flags;
        protected $_m_sid;
        protected $_m_ionoStd;
        protected $_m_tropoStd;
        protected $_m_rangeStd;

        /**
         * Pseudorange observation
         */
        public function p() { return $this->_m_p; }

        /**
         * Carrier phase observation with typical sign convention.
         */
        public function l() { return $this->_m_l; }

        /**
         * Lock timer. This value gives an indication of the time for which a
         * signal has maintained continuous phase lock. Whenever a signal has
         * lost and regained lock, this value is reset to zero. It is encoded
         * according to DF402 from the RTCM 10403.2 Amendment 2 specification.
         * Valid values range from 0 to 15 and the most significant nibble is
         * reserved for future use.
         */
        public function lock() { return $this->_m_lock; }

        /**
         * Correction flags.
         */
        public function flags() { return $this->_m_flags; }

        /**
         * GNSS signal identifier (16 bit)
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Slant ionospheric correction standard deviation
         */
        public function ionoStd() { return $this->_m_ionoStd; }

        /**
         * Slant tropospheric correction standard deviation
         */
        public function tropoStd() { return $this->_m_tropoStd; }

        /**
         * Orbit/clock/bias correction projected on range standard deviation
         */
        public function rangeStd() { return $this->_m_rangeStd; }
    }
}

/**
 * The ephemeris message returns a set of satellite orbit parameters that
 * is used to calculate BDS satellite position, velocity, and clock offset.
 * Please see the BeiDou Navigation Satellite System SIS-ICD Version 2.1,
 * Table 5-9 for more details.
 */

namespace Observation {
    class MsgEphemerisBds extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\EphemerisCommonContent($this->_io, $this, $this->_root);
            $this->_m_tgd1 = $this->_io->readF4le();
            $this->_m_tgd2 = $this->_io->readF4le();
            $this->_m_cRs = $this->_io->readF4le();
            $this->_m_cRc = $this->_io->readF4le();
            $this->_m_cUc = $this->_io->readF4le();
            $this->_m_cUs = $this->_io->readF4le();
            $this->_m_cIc = $this->_io->readF4le();
            $this->_m_cIs = $this->_io->readF4le();
            $this->_m_dn = $this->_io->readF8le();
            $this->_m_m0 = $this->_io->readF8le();
            $this->_m_ecc = $this->_io->readF8le();
            $this->_m_sqrta = $this->_io->readF8le();
            $this->_m_omega0 = $this->_io->readF8le();
            $this->_m_omegadot = $this->_io->readF8le();
            $this->_m_w = $this->_io->readF8le();
            $this->_m_inc = $this->_io->readF8le();
            $this->_m_incDot = $this->_io->readF8le();
            $this->_m_af0 = $this->_io->readF8le();
            $this->_m_af1 = $this->_io->readF4le();
            $this->_m_af2 = $this->_io->readF4le();
            $this->_m_toc = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_iode = $this->_io->readU1();
            $this->_m_iodc = $this->_io->readU2le();
        }
        protected $_m_common;
        protected $_m_tgd1;
        protected $_m_tgd2;
        protected $_m_cRs;
        protected $_m_cRc;
        protected $_m_cUc;
        protected $_m_cUs;
        protected $_m_cIc;
        protected $_m_cIs;
        protected $_m_dn;
        protected $_m_m0;
        protected $_m_ecc;
        protected $_m_sqrta;
        protected $_m_omega0;
        protected $_m_omegadot;
        protected $_m_w;
        protected $_m_inc;
        protected $_m_incDot;
        protected $_m_af0;
        protected $_m_af1;
        protected $_m_af2;
        protected $_m_toc;
        protected $_m_iode;
        protected $_m_iodc;

        /**
         * Values common for all ephemeris types
         */
        public function common() { return $this->_m_common; }

        /**
         * Group delay differential for B1
         */
        public function tgd1() { return $this->_m_tgd1; }

        /**
         * Group delay differential for B2
         */
        public function tgd2() { return $this->_m_tgd2; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public function cRs() { return $this->_m_cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public function cRc() { return $this->_m_cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public function cUc() { return $this->_m_cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public function cUs() { return $this->_m_cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public function cIc() { return $this->_m_cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public function cIs() { return $this->_m_cIs; }

        /**
         * Mean motion difference
         */
        public function dn() { return $this->_m_dn; }

        /**
         * Mean anomaly at reference time
         */
        public function m0() { return $this->_m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public function ecc() { return $this->_m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public function sqrta() { return $this->_m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public function omega0() { return $this->_m_omega0; }

        /**
         * Rate of right ascension
         */
        public function omegadot() { return $this->_m_omegadot; }

        /**
         * Argument of perigee
         */
        public function w() { return $this->_m_w; }

        /**
         * Inclination
         */
        public function inc() { return $this->_m_inc; }

        /**
         * Inclination first derivative
         */
        public function incDot() { return $this->_m_incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public function af0() { return $this->_m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public function af1() { return $this->_m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public function af2() { return $this->_m_af2; }

        /**
         * Clock reference
         */
        public function toc() { return $this->_m_toc; }

        /**
         * Issue of ephemeris data
         * Calculated from the navigation data parameter t_oe per RTCM/CSNO
         * recommendation: IODE = mod (t_oe / 720, 240)
         */
        public function iode() { return $this->_m_iode; }

        /**
         * Issue of clock data
         * Calculated from the navigation data parameter t_oe per RTCM/CSNO
         * recommendation: IODE = mod (t_oc / 720, 240)
         */
        public function iodc() { return $this->_m_iodc; }
    }
}

/**
 * This observation message has been deprecated in favor of ephemeris
 * message using floats for size reduction.
 */

namespace Observation {
    class MsgEphemerisGpsDepF extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\EphemerisCommonContentDepB($this->_io, $this, $this->_root);
            $this->_m_tgd = $this->_io->readF8le();
            $this->_m_cRs = $this->_io->readF8le();
            $this->_m_cRc = $this->_io->readF8le();
            $this->_m_cUc = $this->_io->readF8le();
            $this->_m_cUs = $this->_io->readF8le();
            $this->_m_cIc = $this->_io->readF8le();
            $this->_m_cIs = $this->_io->readF8le();
            $this->_m_dn = $this->_io->readF8le();
            $this->_m_m0 = $this->_io->readF8le();
            $this->_m_ecc = $this->_io->readF8le();
            $this->_m_sqrta = $this->_io->readF8le();
            $this->_m_omega0 = $this->_io->readF8le();
            $this->_m_omegadot = $this->_io->readF8le();
            $this->_m_w = $this->_io->readF8le();
            $this->_m_inc = $this->_io->readF8le();
            $this->_m_incDot = $this->_io->readF8le();
            $this->_m_af0 = $this->_io->readF8le();
            $this->_m_af1 = $this->_io->readF8le();
            $this->_m_af2 = $this->_io->readF8le();
            $this->_m_toc = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_iode = $this->_io->readU1();
            $this->_m_iodc = $this->_io->readU2le();
        }
        protected $_m_common;
        protected $_m_tgd;
        protected $_m_cRs;
        protected $_m_cRc;
        protected $_m_cUc;
        protected $_m_cUs;
        protected $_m_cIc;
        protected $_m_cIs;
        protected $_m_dn;
        protected $_m_m0;
        protected $_m_ecc;
        protected $_m_sqrta;
        protected $_m_omega0;
        protected $_m_omegadot;
        protected $_m_w;
        protected $_m_inc;
        protected $_m_incDot;
        protected $_m_af0;
        protected $_m_af1;
        protected $_m_af2;
        protected $_m_toc;
        protected $_m_iode;
        protected $_m_iodc;

        /**
         * Values common for all ephemeris types
         */
        public function common() { return $this->_m_common; }

        /**
         * Group delay differential between L1 and L2
         */
        public function tgd() { return $this->_m_tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public function cRs() { return $this->_m_cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public function cRc() { return $this->_m_cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public function cUc() { return $this->_m_cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public function cUs() { return $this->_m_cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public function cIc() { return $this->_m_cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public function cIs() { return $this->_m_cIs; }

        /**
         * Mean motion difference
         */
        public function dn() { return $this->_m_dn; }

        /**
         * Mean anomaly at reference time
         */
        public function m0() { return $this->_m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public function ecc() { return $this->_m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public function sqrta() { return $this->_m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public function omega0() { return $this->_m_omega0; }

        /**
         * Rate of right ascension
         */
        public function omegadot() { return $this->_m_omegadot; }

        /**
         * Argument of perigee
         */
        public function w() { return $this->_m_w; }

        /**
         * Inclination
         */
        public function inc() { return $this->_m_inc; }

        /**
         * Inclination first derivative
         */
        public function incDot() { return $this->_m_incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public function af0() { return $this->_m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public function af1() { return $this->_m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public function af2() { return $this->_m_af2; }

        /**
         * Clock reference
         */
        public function toc() { return $this->_m_toc; }

        /**
         * Issue of ephemeris data
         */
        public function iode() { return $this->_m_iode; }

        /**
         * Issue of clock data
         */
        public function iodc() { return $this->_m_iodc; }
    }
}

/**
 * Header of a GNSS observation message.
 */

namespace Observation {
    class ObservationHeader extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_t = new \Gnss\GpsTime($this->_io, $this, $this->_root);
            $this->_m_nObs = $this->_io->readU1();
        }
        protected $_m_t;
        protected $_m_nObs;

        /**
         * GNSS time of this observation
         */
        public function t() { return $this->_m_t; }

        /**
         * Total number of observations. First nibble is the size of the
         * sequence (n), second nibble is the zero-indexed counter (ith packet
         * of n)
         */
        public function nObs() { return $this->_m_nObs; }
    }
}

namespace Observation {
    class MsgEphemerisSbasDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\EphemerisCommonContentDepA($this->_io, $this, $this->_root);
            $this->_m_pos = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_pos[] = $this->_io->readF8le();
            }
            $this->_m_vel = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_vel[] = $this->_io->readF8le();
            }
            $this->_m_acc = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_acc[] = $this->_io->readF8le();
            }
            $this->_m_aGf0 = $this->_io->readF8le();
            $this->_m_aGf1 = $this->_io->readF8le();
        }
        protected $_m_common;
        protected $_m_pos;
        protected $_m_vel;
        protected $_m_acc;
        protected $_m_aGf0;
        protected $_m_aGf1;

        /**
         * Values common for all ephemeris types
         */
        public function common() { return $this->_m_common; }

        /**
         * Position of the GEO at time toe
         */
        public function pos() { return $this->_m_pos; }

        /**
         * Velocity of the GEO at time toe
         */
        public function vel() { return $this->_m_vel; }

        /**
         * Acceleration of the GEO at time toe
         */
        public function acc() { return $this->_m_acc; }

        /**
         * Time offset of the GEO clock w.r.t. SBAS Network Time
         */
        public function aGf0() { return $this->_m_aGf0; }

        /**
         * Drift of the GEO clock w.r.t. SBAS Network Time
         */
        public function aGf1() { return $this->_m_aGf1; }
    }
}

/**
 * Pseudorange and carrier phase observation for a satellite being tracked.
 * The observations are interoperable with 3rd party receivers and conform
 * with typical RTCM 3.1 message GPS/GLO observations.
 * 
 * Carrier phase observations are not guaranteed to be aligned to the RINEX
 * 3 or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are
 * currently performed.
 */

namespace Observation {
    class PackedObsContent extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Observation\MsgObs $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_p = $this->_io->readU4le();
            $this->_m_l = new \Gnss\CarrierPhase($this->_io, $this, $this->_root);
            $this->_m_d = new \Observation\Doppler($this->_io, $this, $this->_root);
            $this->_m_cn0 = $this->_io->readU1();
            $this->_m_lock = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
        }
        protected $_m_p;
        protected $_m_l;
        protected $_m_d;
        protected $_m_cn0;
        protected $_m_lock;
        protected $_m_flags;
        protected $_m_sid;

        /**
         * Pseudorange observation
         */
        public function p() { return $this->_m_p; }

        /**
         * Carrier phase observation with typical sign convention.
         */
        public function l() { return $this->_m_l; }

        /**
         * Doppler observation with typical sign convention.
         */
        public function d() { return $this->_m_d; }

        /**
         * Carrier-to-Noise density.  Zero implies invalid cn0.
         */
        public function cn0() { return $this->_m_cn0; }

        /**
         * Lock timer. This value gives an indication of the time for which a
         * signal has maintained continuous phase lock. Whenever a signal has
         * lost and regained lock, this value is reset to zero. It is encoded
         * according to DF402 from the RTCM 10403.2 Amendment 2 specification.
         * Valid values range from 0 to 15 and the most significant nibble is
         * reserved for future use.
         */
        public function lock() { return $this->_m_lock; }

        /**
         * Measurement status flags. A bit field of flags providing the status
         * of this observation.  If this field is 0 it means only the Cn0
         * estimate for the signal is valid.
         */
        public function flags() { return $this->_m_flags; }

        /**
         * GNSS signal identifier (16 bit)
         */
        public function sid() { return $this->_m_sid; }
    }
}

/**
 * The base station position message is the position reported by the base
 * station itself in absolute Earth Centered Earth Fixed coordinates. It is
 * used for pseudo-absolute RTK positioning, and is required to be a high-
 * accuracy surveyed location of the base station. Any error here will
 * result in an error in the pseudo-absolute position output.
 */

namespace Observation {
    class MsgBasePosEcef extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_x = $this->_io->readF8le();
            $this->_m_y = $this->_io->readF8le();
            $this->_m_z = $this->_io->readF8le();
        }
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;

        /**
         * ECEF X coordinate
         */
        public function x() { return $this->_m_x; }

        /**
         * ECEF Y coordinate
         */
        public function y() { return $this->_m_y; }

        /**
         * ECEF Z coordinate
         */
        public function z() { return $this->_m_z; }
    }
}

/**
 * The ephemeris message returns a set of satellite orbit parameters that
 * is used to calculate GLO satellite position, velocity, and clock offset.
 * Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
 * immediate information (ephemeris parameters)" for more details.
 */

namespace Observation {
    class MsgEphemerisGloDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\EphemerisCommonContentDepA($this->_io, $this, $this->_root);
            $this->_m_gamma = $this->_io->readF8le();
            $this->_m_tau = $this->_io->readF8le();
            $this->_m_pos = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_pos[] = $this->_io->readF8le();
            }
            $this->_m_vel = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_vel[] = $this->_io->readF8le();
            }
            $this->_m_acc = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_acc[] = $this->_io->readF8le();
            }
        }
        protected $_m_common;
        protected $_m_gamma;
        protected $_m_tau;
        protected $_m_pos;
        protected $_m_vel;
        protected $_m_acc;

        /**
         * Values common for all ephemeris types
         */
        public function common() { return $this->_m_common; }

        /**
         * Relative deviation of predicted carrier frequency from nominal
         */
        public function gamma() { return $this->_m_gamma; }

        /**
         * Correction to the SV time
         */
        public function tau() { return $this->_m_tau; }

        /**
         * Position of the SV at tb in PZ-90.02 coordinates system
         */
        public function pos() { return $this->_m_pos; }

        /**
         * Velocity vector of the SV at tb in PZ-90.02 coordinates system
         */
        public function vel() { return $this->_m_vel; }

        /**
         * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
         */
        public function acc() { return $this->_m_acc; }
    }
}

/**
 * Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 */

namespace Observation {
    class MsgGroupDelay extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tOp = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_valid = $this->_io->readU1();
            $this->_m_tgd = $this->_io->readS2le();
            $this->_m_iscL1ca = $this->_io->readS2le();
            $this->_m_iscL2c = $this->_io->readS2le();
        }
        protected $_m_tOp;
        protected $_m_sid;
        protected $_m_valid;
        protected $_m_tgd;
        protected $_m_iscL1ca;
        protected $_m_iscL2c;

        /**
         * Data Predict Time of Week
         */
        public function tOp() { return $this->_m_tOp; }

        /**
         * GNSS signal identifier
         */
        public function sid() { return $this->_m_sid; }

        /**
         * bit-field indicating validity of the values, LSB indicating tgd
         * validity etc. 1 = value is valid, 0 = value is not valid.
         */
        public function valid() { return $this->_m_valid; }
        public function tgd() { return $this->_m_tgd; }
        public function iscL1ca() { return $this->_m_iscL1ca; }
        public function iscL2c() { return $this->_m_iscL2c; }
    }
}

/**
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several
 * months. Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate
 * information and almanac" for details.
 */

namespace Observation {
    class MsgAlmanacGlo extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\AlmanacCommonContent($this->_io, $this, $this->_root);
            $this->_m_lambdaNa = $this->_io->readF8le();
            $this->_m_tLambdaNa = $this->_io->readF8le();
            $this->_m_i = $this->_io->readF8le();
            $this->_m_t = $this->_io->readF8le();
            $this->_m_tDot = $this->_io->readF8le();
            $this->_m_epsilon = $this->_io->readF8le();
            $this->_m_omega = $this->_io->readF8le();
        }
        protected $_m_common;
        protected $_m_lambdaNa;
        protected $_m_tLambdaNa;
        protected $_m_i;
        protected $_m_t;
        protected $_m_tDot;
        protected $_m_epsilon;
        protected $_m_omega;

        /**
         * Values common for all almanac types
         */
        public function common() { return $this->_m_common; }

        /**
         * Longitude of the first ascending node of the orbit in PZ-90.02
         * coordinate system
         */
        public function lambdaNa() { return $this->_m_lambdaNa; }

        /**
         * Time of the first ascending node passage
         */
        public function tLambdaNa() { return $this->_m_tLambdaNa; }

        /**
         * Value of inclination at instant of t_lambda
         */
        public function i() { return $this->_m_i; }

        /**
         * Value of Draconian period at instant of t_lambda
         */
        public function t() { return $this->_m_t; }

        /**
         * Rate of change of the Draconian period
         */
        public function tDot() { return $this->_m_tDot; }

        /**
         * Eccentricity at instant of t_lambda
         */
        public function epsilon() { return $this->_m_epsilon; }

        /**
         * Argument of perigee at instant of t_lambda
         */
        public function omega() { return $this->_m_omega; }
    }
}

/**
 * This observation message has been deprecated in favor of an ephemeris
 * message with explicit source of NAV data.
 */

namespace Observation {
    class MsgEphemerisGalDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\EphemerisCommonContent($this->_io, $this, $this->_root);
            $this->_m_bgdE1e5a = $this->_io->readF4le();
            $this->_m_bgdE1e5b = $this->_io->readF4le();
            $this->_m_cRs = $this->_io->readF4le();
            $this->_m_cRc = $this->_io->readF4le();
            $this->_m_cUc = $this->_io->readF4le();
            $this->_m_cUs = $this->_io->readF4le();
            $this->_m_cIc = $this->_io->readF4le();
            $this->_m_cIs = $this->_io->readF4le();
            $this->_m_dn = $this->_io->readF8le();
            $this->_m_m0 = $this->_io->readF8le();
            $this->_m_ecc = $this->_io->readF8le();
            $this->_m_sqrta = $this->_io->readF8le();
            $this->_m_omega0 = $this->_io->readF8le();
            $this->_m_omegadot = $this->_io->readF8le();
            $this->_m_w = $this->_io->readF8le();
            $this->_m_inc = $this->_io->readF8le();
            $this->_m_incDot = $this->_io->readF8le();
            $this->_m_af0 = $this->_io->readF8le();
            $this->_m_af1 = $this->_io->readF8le();
            $this->_m_af2 = $this->_io->readF4le();
            $this->_m_toc = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_iode = $this->_io->readU2le();
            $this->_m_iodc = $this->_io->readU2le();
        }
        protected $_m_common;
        protected $_m_bgdE1e5a;
        protected $_m_bgdE1e5b;
        protected $_m_cRs;
        protected $_m_cRc;
        protected $_m_cUc;
        protected $_m_cUs;
        protected $_m_cIc;
        protected $_m_cIs;
        protected $_m_dn;
        protected $_m_m0;
        protected $_m_ecc;
        protected $_m_sqrta;
        protected $_m_omega0;
        protected $_m_omegadot;
        protected $_m_w;
        protected $_m_inc;
        protected $_m_incDot;
        protected $_m_af0;
        protected $_m_af1;
        protected $_m_af2;
        protected $_m_toc;
        protected $_m_iode;
        protected $_m_iodc;

        /**
         * Values common for all ephemeris types
         */
        public function common() { return $this->_m_common; }

        /**
         * E1-E5a Broadcast Group Delay
         */
        public function bgdE1e5a() { return $this->_m_bgdE1e5a; }

        /**
         * E1-E5b Broadcast Group Delay
         */
        public function bgdE1e5b() { return $this->_m_bgdE1e5b; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public function cRs() { return $this->_m_cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public function cRc() { return $this->_m_cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public function cUc() { return $this->_m_cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public function cUs() { return $this->_m_cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public function cIc() { return $this->_m_cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public function cIs() { return $this->_m_cIs; }

        /**
         * Mean motion difference
         */
        public function dn() { return $this->_m_dn; }

        /**
         * Mean anomaly at reference time
         */
        public function m0() { return $this->_m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public function ecc() { return $this->_m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public function sqrta() { return $this->_m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public function omega0() { return $this->_m_omega0; }

        /**
         * Rate of right ascension
         */
        public function omegadot() { return $this->_m_omegadot; }

        /**
         * Argument of perigee
         */
        public function w() { return $this->_m_w; }

        /**
         * Inclination
         */
        public function inc() { return $this->_m_inc; }

        /**
         * Inclination first derivative
         */
        public function incDot() { return $this->_m_incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public function af0() { return $this->_m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public function af1() { return $this->_m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public function af2() { return $this->_m_af2; }

        /**
         * Clock reference
         */
        public function toc() { return $this->_m_toc; }

        /**
         * Issue of data (IODnav)
         */
        public function iode() { return $this->_m_iode; }

        /**
         * Issue of data (IODnav). Always equal to iode
         */
        public function iodc() { return $this->_m_iodc; }
    }
}

/**
 * This observation message has been deprecated in favor of observations
 * that are more interoperable. This message should be used for
 * observations referenced to a nominal pseudorange which are not
 * interoperable with most 3rd party GNSS receivers or typical RTCMv3
 * observations.
 */

namespace Observation {
    class MsgObsDepB extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Observation\ObservationHeaderDep($this->_io, $this, $this->_root);
            $this->_m_obs = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_obs[] = new \Observation\PackedObsContentDepB($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_obs;

        /**
         * Header of a GPS observation message
         */
        public function header() { return $this->_m_header; }

        /**
         * Pseudorange and carrier phase observation for a satellite being
         * tracked.
         */
        public function obs() { return $this->_m_obs; }
    }
}

/**
 * Deprecated.
 */

namespace Observation {
    class PackedObsContentDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Observation\MsgObsDepA $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_p = $this->_io->readU4le();
            $this->_m_l = new \Observation\CarrierPhaseDepA($this->_io, $this, $this->_root);
            $this->_m_cn0 = $this->_io->readU1();
            $this->_m_lock = $this->_io->readU2le();
            $this->_m_prn = $this->_io->readU1();
        }
        protected $_m_p;
        protected $_m_l;
        protected $_m_cn0;
        protected $_m_lock;
        protected $_m_prn;

        /**
         * Pseudorange observation
         */
        public function p() { return $this->_m_p; }

        /**
         * Carrier phase observation with opposite sign from typical convention
         */
        public function l() { return $this->_m_l; }

        /**
         * Carrier-to-Noise density
         */
        public function cn0() { return $this->_m_cn0; }

        /**
         * Lock indicator. This value changes whenever a satellite signal has
         * lost and regained lock, indicating that the carrier phase ambiguity
         * may have changed.
         */
        public function lock() { return $this->_m_lock; }

        /**
         * PRN-1 identifier of the satellite signal
         */
        public function prn() { return $this->_m_prn; }
    }
}

/**
 * The ephemeris message returns a set of satellite orbit parameters that
 * is used to calculate GLO satellite position, velocity, and clock offset.
 * Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
 * immediate information (ephemeris parameters)" for more details.
 */

namespace Observation {
    class MsgEphemerisGlo extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\EphemerisCommonContent($this->_io, $this, $this->_root);
            $this->_m_gamma = $this->_io->readF4le();
            $this->_m_tau = $this->_io->readF4le();
            $this->_m_dTau = $this->_io->readF4le();
            $this->_m_pos = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_pos[] = $this->_io->readF8le();
            }
            $this->_m_vel = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_vel[] = $this->_io->readF8le();
            }
            $this->_m_acc = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_acc[] = $this->_io->readF4le();
            }
            $this->_m_fcn = $this->_io->readU1();
            $this->_m_iod = $this->_io->readU1();
        }
        protected $_m_common;
        protected $_m_gamma;
        protected $_m_tau;
        protected $_m_dTau;
        protected $_m_pos;
        protected $_m_vel;
        protected $_m_acc;
        protected $_m_fcn;
        protected $_m_iod;

        /**
         * Values common for all ephemeris types
         */
        public function common() { return $this->_m_common; }

        /**
         * Relative deviation of predicted carrier frequency from nominal
         */
        public function gamma() { return $this->_m_gamma; }

        /**
         * Correction to the SV time
         */
        public function tau() { return $this->_m_tau; }

        /**
         * Equipment delay between L1 and L2
         */
        public function dTau() { return $this->_m_dTau; }

        /**
         * Position of the SV at tb in PZ-90.02 coordinates system
         */
        public function pos() { return $this->_m_pos; }

        /**
         * Velocity vector of the SV at tb in PZ-90.02 coordinates system
         */
        public function vel() { return $this->_m_vel; }

        /**
         * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
         */
        public function acc() { return $this->_m_acc; }

        /**
         * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
         */
        public function fcn() { return $this->_m_fcn; }

        /**
         * Issue of data. Equal to the 7 bits of the immediate data word t_b
         */
        public function iod() { return $this->_m_iod; }
    }
}

/**
 * The ionospheric parameters which allow the "L1 only" or "L2 only" user
 * to utilize the ionospheric model for computation of the ionospheric
 * delay. Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
 */

namespace Observation {
    class MsgIono extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tNmct = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_a0 = $this->_io->readF8le();
            $this->_m_a1 = $this->_io->readF8le();
            $this->_m_a2 = $this->_io->readF8le();
            $this->_m_a3 = $this->_io->readF8le();
            $this->_m_b0 = $this->_io->readF8le();
            $this->_m_b1 = $this->_io->readF8le();
            $this->_m_b2 = $this->_io->readF8le();
            $this->_m_b3 = $this->_io->readF8le();
        }
        protected $_m_tNmct;
        protected $_m_a0;
        protected $_m_a1;
        protected $_m_a2;
        protected $_m_a3;
        protected $_m_b0;
        protected $_m_b1;
        protected $_m_b2;
        protected $_m_b3;

        /**
         * Navigation Message Correction Table Validity Time
         */
        public function tNmct() { return $this->_m_tNmct; }
        public function a0() { return $this->_m_a0; }
        public function a1() { return $this->_m_a1; }
        public function a2() { return $this->_m_a2; }
        public function a3() { return $this->_m_a3; }
        public function b0() { return $this->_m_b0; }
        public function b1() { return $this->_m_b1; }
        public function b2() { return $this->_m_b2; }
        public function b3() { return $this->_m_b3; }
    }
}

/**
 * The ephemeris message returns a set of satellite orbit parameters that
 * is used to calculate GPS satellite position, velocity, and clock offset.
 * Please see the Navstar GPS Space Segment/Navigation user interfaces
 * (ICD-GPS-200, Table 20-III) for more details.
 */

namespace Observation {
    class MsgEphemerisDepD extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tgd = $this->_io->readF8le();
            $this->_m_cRs = $this->_io->readF8le();
            $this->_m_cRc = $this->_io->readF8le();
            $this->_m_cUc = $this->_io->readF8le();
            $this->_m_cUs = $this->_io->readF8le();
            $this->_m_cIc = $this->_io->readF8le();
            $this->_m_cIs = $this->_io->readF8le();
            $this->_m_dn = $this->_io->readF8le();
            $this->_m_m0 = $this->_io->readF8le();
            $this->_m_ecc = $this->_io->readF8le();
            $this->_m_sqrta = $this->_io->readF8le();
            $this->_m_omega0 = $this->_io->readF8le();
            $this->_m_omegadot = $this->_io->readF8le();
            $this->_m_w = $this->_io->readF8le();
            $this->_m_inc = $this->_io->readF8le();
            $this->_m_incDot = $this->_io->readF8le();
            $this->_m_af0 = $this->_io->readF8le();
            $this->_m_af1 = $this->_io->readF8le();
            $this->_m_af2 = $this->_io->readF8le();
            $this->_m_toeTow = $this->_io->readF8le();
            $this->_m_toeWn = $this->_io->readU2le();
            $this->_m_tocTow = $this->_io->readF8le();
            $this->_m_tocWn = $this->_io->readU2le();
            $this->_m_valid = $this->_io->readU1();
            $this->_m_healthy = $this->_io->readU1();
            $this->_m_sid = new \Gnss\GnssSignalDep($this->_io, $this, $this->_root);
            $this->_m_iode = $this->_io->readU1();
            $this->_m_iodc = $this->_io->readU2le();
            $this->_m_reserved = $this->_io->readU4le();
        }
        protected $_m_tgd;
        protected $_m_cRs;
        protected $_m_cRc;
        protected $_m_cUc;
        protected $_m_cUs;
        protected $_m_cIc;
        protected $_m_cIs;
        protected $_m_dn;
        protected $_m_m0;
        protected $_m_ecc;
        protected $_m_sqrta;
        protected $_m_omega0;
        protected $_m_omegadot;
        protected $_m_w;
        protected $_m_inc;
        protected $_m_incDot;
        protected $_m_af0;
        protected $_m_af1;
        protected $_m_af2;
        protected $_m_toeTow;
        protected $_m_toeWn;
        protected $_m_tocTow;
        protected $_m_tocWn;
        protected $_m_valid;
        protected $_m_healthy;
        protected $_m_sid;
        protected $_m_iode;
        protected $_m_iodc;
        protected $_m_reserved;

        /**
         * Group delay differential between L1 and L2
         */
        public function tgd() { return $this->_m_tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public function cRs() { return $this->_m_cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public function cRc() { return $this->_m_cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public function cUc() { return $this->_m_cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public function cUs() { return $this->_m_cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public function cIc() { return $this->_m_cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public function cIs() { return $this->_m_cIs; }

        /**
         * Mean motion difference
         */
        public function dn() { return $this->_m_dn; }

        /**
         * Mean anomaly at reference time
         */
        public function m0() { return $this->_m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public function ecc() { return $this->_m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public function sqrta() { return $this->_m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public function omega0() { return $this->_m_omega0; }

        /**
         * Rate of right ascension
         */
        public function omegadot() { return $this->_m_omegadot; }

        /**
         * Argument of perigee
         */
        public function w() { return $this->_m_w; }

        /**
         * Inclination
         */
        public function inc() { return $this->_m_inc; }

        /**
         * Inclination first derivative
         */
        public function incDot() { return $this->_m_incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public function af0() { return $this->_m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public function af1() { return $this->_m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public function af2() { return $this->_m_af2; }

        /**
         * Time of week
         */
        public function toeTow() { return $this->_m_toeTow; }

        /**
         * Week number
         */
        public function toeWn() { return $this->_m_toeWn; }

        /**
         * Clock reference time of week
         */
        public function tocTow() { return $this->_m_tocTow; }

        /**
         * Clock reference week number
         */
        public function tocWn() { return $this->_m_tocWn; }

        /**
         * Is valid?
         */
        public function valid() { return $this->_m_valid; }

        /**
         * Satellite is healthy?
         */
        public function healthy() { return $this->_m_healthy; }

        /**
         * GNSS signal identifier
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Issue of ephemeris data
         */
        public function iode() { return $this->_m_iode; }

        /**
         * Issue of clock data
         */
        public function iodc() { return $this->_m_iodc; }

        /**
         * Reserved field
         */
        public function reserved() { return $this->_m_reserved; }
    }
}

/**
 * The ephemeris message returns a set of satellite orbit parameters that
 * is used to calculate GPS satellite position, velocity, and clock offset.
 * Please see the Navstar GPS Space Segment/Navigation user interfaces
 * (ICD-GPS-200, Table 20-III) for more details.
 */

namespace Observation {
    class MsgEphemerisGps extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\EphemerisCommonContent($this->_io, $this, $this->_root);
            $this->_m_tgd = $this->_io->readF4le();
            $this->_m_cRs = $this->_io->readF4le();
            $this->_m_cRc = $this->_io->readF4le();
            $this->_m_cUc = $this->_io->readF4le();
            $this->_m_cUs = $this->_io->readF4le();
            $this->_m_cIc = $this->_io->readF4le();
            $this->_m_cIs = $this->_io->readF4le();
            $this->_m_dn = $this->_io->readF8le();
            $this->_m_m0 = $this->_io->readF8le();
            $this->_m_ecc = $this->_io->readF8le();
            $this->_m_sqrta = $this->_io->readF8le();
            $this->_m_omega0 = $this->_io->readF8le();
            $this->_m_omegadot = $this->_io->readF8le();
            $this->_m_w = $this->_io->readF8le();
            $this->_m_inc = $this->_io->readF8le();
            $this->_m_incDot = $this->_io->readF8le();
            $this->_m_af0 = $this->_io->readF4le();
            $this->_m_af1 = $this->_io->readF4le();
            $this->_m_af2 = $this->_io->readF4le();
            $this->_m_toc = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_iode = $this->_io->readU1();
            $this->_m_iodc = $this->_io->readU2le();
        }
        protected $_m_common;
        protected $_m_tgd;
        protected $_m_cRs;
        protected $_m_cRc;
        protected $_m_cUc;
        protected $_m_cUs;
        protected $_m_cIc;
        protected $_m_cIs;
        protected $_m_dn;
        protected $_m_m0;
        protected $_m_ecc;
        protected $_m_sqrta;
        protected $_m_omega0;
        protected $_m_omegadot;
        protected $_m_w;
        protected $_m_inc;
        protected $_m_incDot;
        protected $_m_af0;
        protected $_m_af1;
        protected $_m_af2;
        protected $_m_toc;
        protected $_m_iode;
        protected $_m_iodc;

        /**
         * Values common for all ephemeris types
         */
        public function common() { return $this->_m_common; }

        /**
         * Group delay differential between L1 and L2
         */
        public function tgd() { return $this->_m_tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public function cRs() { return $this->_m_cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public function cRc() { return $this->_m_cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public function cUc() { return $this->_m_cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public function cUs() { return $this->_m_cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public function cIc() { return $this->_m_cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public function cIs() { return $this->_m_cIs; }

        /**
         * Mean motion difference
         */
        public function dn() { return $this->_m_dn; }

        /**
         * Mean anomaly at reference time
         */
        public function m0() { return $this->_m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public function ecc() { return $this->_m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public function sqrta() { return $this->_m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public function omega0() { return $this->_m_omega0; }

        /**
         * Rate of right ascension
         */
        public function omegadot() { return $this->_m_omegadot; }

        /**
         * Argument of perigee
         */
        public function w() { return $this->_m_w; }

        /**
         * Inclination
         */
        public function inc() { return $this->_m_inc; }

        /**
         * Inclination first derivative
         */
        public function incDot() { return $this->_m_incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public function af0() { return $this->_m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public function af1() { return $this->_m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public function af2() { return $this->_m_af2; }

        /**
         * Clock reference
         */
        public function toc() { return $this->_m_toc; }

        /**
         * Issue of ephemeris data
         */
        public function iode() { return $this->_m_iode; }

        /**
         * Issue of clock data
         */
        public function iodc() { return $this->_m_iodc; }
    }
}

/**
 * The base station position message is the position reported by the base
 * station itself. It is used for pseudo-absolute RTK positioning, and is
 * required to be a high-accuracy surveyed location of the base station.
 * Any error here will result in an error in the pseudo-absolute position
 * output.
 */

namespace Observation {
    class MsgBasePosLlh extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_lat = $this->_io->readF8le();
            $this->_m_lon = $this->_io->readF8le();
            $this->_m_height = $this->_io->readF8le();
        }
        protected $_m_lat;
        protected $_m_lon;
        protected $_m_height;

        /**
         * Latitude
         */
        public function lat() { return $this->_m_lat; }

        /**
         * Longitude
         */
        public function lon() { return $this->_m_lon; }

        /**
         * Height
         */
        public function height() { return $this->_m_height; }
    }
}

namespace Observation {
    class AlmanacCommonContent extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_toa = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_ura = $this->_io->readF8le();
            $this->_m_fitInterval = $this->_io->readU4le();
            $this->_m_valid = $this->_io->readU1();
            $this->_m_healthBits = $this->_io->readU1();
        }
        protected $_m_sid;
        protected $_m_toa;
        protected $_m_ura;
        protected $_m_fitInterval;
        protected $_m_valid;
        protected $_m_healthBits;

        /**
         * GNSS signal identifier
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Reference time of almanac
         */
        public function toa() { return $this->_m_toa; }

        /**
         * User Range Accuracy
         */
        public function ura() { return $this->_m_ura; }

        /**
         * Curve fit interval
         */
        public function fitInterval() { return $this->_m_fitInterval; }

        /**
         * Status of almanac, 1 = valid, 0 = invalid
         */
        public function valid() { return $this->_m_valid; }

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
        public function healthBits() { return $this->_m_healthBits; }
    }
}

/**
 * The OSR message contains network corrections in an observation-like
 * format.
 */

namespace Observation {
    class MsgOsr extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Observation\ObservationHeader($this->_io, $this, $this->_root);
            $this->_m_obs = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_obs[] = new \Observation\PackedOsrContent($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_obs;

        /**
         * Header of a GPS observation message
         */
        public function header() { return $this->_m_header; }

        /**
         * Network correction for a satellite signal.
         */
        public function obs() { return $this->_m_obs; }
    }
}

/**
 * The ephemeris message returns a set of satellite orbit parameters that
 * is used to calculate GLO satellite position, velocity, and clock offset.
 * Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
 * immediate information (ephemeris parameters)" for more details.
 */

namespace Observation {
    class MsgEphemerisGloDepC extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\EphemerisCommonContentDepB($this->_io, $this, $this->_root);
            $this->_m_gamma = $this->_io->readF8le();
            $this->_m_tau = $this->_io->readF8le();
            $this->_m_dTau = $this->_io->readF8le();
            $this->_m_pos = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_pos[] = $this->_io->readF8le();
            }
            $this->_m_vel = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_vel[] = $this->_io->readF8le();
            }
            $this->_m_acc = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_acc[] = $this->_io->readF8le();
            }
            $this->_m_fcn = $this->_io->readU1();
        }
        protected $_m_common;
        protected $_m_gamma;
        protected $_m_tau;
        protected $_m_dTau;
        protected $_m_pos;
        protected $_m_vel;
        protected $_m_acc;
        protected $_m_fcn;

        /**
         * Values common for all ephemeris types
         */
        public function common() { return $this->_m_common; }

        /**
         * Relative deviation of predicted carrier frequency from nominal
         */
        public function gamma() { return $this->_m_gamma; }

        /**
         * Correction to the SV time
         */
        public function tau() { return $this->_m_tau; }

        /**
         * Equipment delay between L1 and L2
         */
        public function dTau() { return $this->_m_dTau; }

        /**
         * Position of the SV at tb in PZ-90.02 coordinates system
         */
        public function pos() { return $this->_m_pos; }

        /**
         * Velocity vector of the SV at tb in PZ-90.02 coordinates system
         */
        public function vel() { return $this->_m_vel; }

        /**
         * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
         */
        public function acc() { return $this->_m_acc; }

        /**
         * Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
         */
        public function fcn() { return $this->_m_fcn; }
    }
}

/**
 * The ephemeris message returns a set of satellite orbit parameters that
 * is used to calculate GLO satellite position, velocity, and clock offset.
 * Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
 * immediate information (ephemeris parameters)" for more details.
 */

namespace Observation {
    class MsgEphemerisGloDepB extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\EphemerisCommonContentDepB($this->_io, $this, $this->_root);
            $this->_m_gamma = $this->_io->readF8le();
            $this->_m_tau = $this->_io->readF8le();
            $this->_m_pos = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_pos[] = $this->_io->readF8le();
            }
            $this->_m_vel = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_vel[] = $this->_io->readF8le();
            }
            $this->_m_acc = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_acc[] = $this->_io->readF8le();
            }
        }
        protected $_m_common;
        protected $_m_gamma;
        protected $_m_tau;
        protected $_m_pos;
        protected $_m_vel;
        protected $_m_acc;

        /**
         * Values common for all ephemeris types
         */
        public function common() { return $this->_m_common; }

        /**
         * Relative deviation of predicted carrier frequency from nominal
         */
        public function gamma() { return $this->_m_gamma; }

        /**
         * Correction to the SV time
         */
        public function tau() { return $this->_m_tau; }

        /**
         * Position of the SV at tb in PZ-90.02 coordinates system
         */
        public function pos() { return $this->_m_pos; }

        /**
         * Velocity vector of the SV at tb in PZ-90.02 coordinates system
         */
        public function vel() { return $this->_m_vel; }

        /**
         * Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
         */
        public function acc() { return $this->_m_acc; }
    }
}

/**
 * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
 */

namespace Observation {
    class MsgSvConfigurationGpsDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tNmct = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_l2cMask = $this->_io->readU4le();
        }
        protected $_m_tNmct;
        protected $_m_l2cMask;

        /**
         * Navigation Message Correction Table Validity Time
         */
        public function tNmct() { return $this->_m_tNmct; }

        /**
         * L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
         */
        public function l2cMask() { return $this->_m_l2cMask; }
    }
}

namespace Observation {
    class MsgEphemerisSbas extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_common = new \Observation\EphemerisCommonContent($this->_io, $this, $this->_root);
            $this->_m_pos = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_pos[] = $this->_io->readF8le();
            }
            $this->_m_vel = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_vel[] = $this->_io->readF4le();
            }
            $this->_m_acc = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_acc[] = $this->_io->readF4le();
            }
            $this->_m_aGf0 = $this->_io->readF4le();
            $this->_m_aGf1 = $this->_io->readF4le();
        }
        protected $_m_common;
        protected $_m_pos;
        protected $_m_vel;
        protected $_m_acc;
        protected $_m_aGf0;
        protected $_m_aGf1;

        /**
         * Values common for all ephemeris types
         */
        public function common() { return $this->_m_common; }

        /**
         * Position of the GEO at time toe
         */
        public function pos() { return $this->_m_pos; }

        /**
         * Velocity of the GEO at time toe
         */
        public function vel() { return $this->_m_vel; }

        /**
         * Acceleration of the GEO at time toe
         */
        public function acc() { return $this->_m_acc; }

        /**
         * Time offset of the GEO clock w.r.t. SBAS Network Time
         */
        public function aGf0() { return $this->_m_aGf0; }

        /**
         * Drift of the GEO clock w.r.t. SBAS Network Time
         */
        public function aGf1() { return $this->_m_aGf1; }
    }
}

/**
 * Pseudorange and carrier phase observation for a satellite being tracked.
 * Pseudoranges are referenced to a nominal pseudorange.
 */

namespace Observation {
    class PackedObsContentDepB extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Observation\MsgObsDepB $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_p = $this->_io->readU4le();
            $this->_m_l = new \Observation\CarrierPhaseDepA($this->_io, $this, $this->_root);
            $this->_m_cn0 = $this->_io->readU1();
            $this->_m_lock = $this->_io->readU2le();
            $this->_m_sid = new \Gnss\GnssSignalDep($this->_io, $this, $this->_root);
        }
        protected $_m_p;
        protected $_m_l;
        protected $_m_cn0;
        protected $_m_lock;
        protected $_m_sid;

        /**
         * Pseudorange observation
         */
        public function p() { return $this->_m_p; }

        /**
         * Carrier phase observation with opposite sign from typical
         * convention.
         */
        public function l() { return $this->_m_l; }

        /**
         * Carrier-to-Noise density
         */
        public function cn0() { return $this->_m_cn0; }

        /**
         * Lock indicator. This value changes whenever a satellite signal has
         * lost and regained lock, indicating that the carrier phase ambiguity
         * may have changed.
         */
        public function lock() { return $this->_m_lock; }

        /**
         * GNSS signal identifier
         */
        public function sid() { return $this->_m_sid; }
    }
}

/**
 * The GPS observations message reports all the raw pseudorange and carrier
 * phase observations for the satellites being tracked by the device.
 * Carrier phase observation here is represented as a 40-bit fixed point
 * number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
 * fractional cycles). The observations are interoperable with 3rd party
 * receivers and conform with typical RTCMv3 GNSS observations.
 */

namespace Observation {
    class MsgObsDepC extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_header = new \Observation\ObservationHeaderDep($this->_io, $this, $this->_root);
            $this->_m_obs = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_obs[] = new \Observation\PackedObsContentDepC($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_header;
        protected $_m_obs;

        /**
         * Header of a GPS observation message
         */
        public function header() { return $this->_m_header; }

        /**
         * Pseudorange and carrier phase observation for a satellite being
         * tracked.
         */
        public function obs() { return $this->_m_obs; }
    }
}

/**
 * Deprecated.
 */

namespace Observation {
    class MsgEphemerisDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tgd = $this->_io->readF8le();
            $this->_m_cRs = $this->_io->readF8le();
            $this->_m_cRc = $this->_io->readF8le();
            $this->_m_cUc = $this->_io->readF8le();
            $this->_m_cUs = $this->_io->readF8le();
            $this->_m_cIc = $this->_io->readF8le();
            $this->_m_cIs = $this->_io->readF8le();
            $this->_m_dn = $this->_io->readF8le();
            $this->_m_m0 = $this->_io->readF8le();
            $this->_m_ecc = $this->_io->readF8le();
            $this->_m_sqrta = $this->_io->readF8le();
            $this->_m_omega0 = $this->_io->readF8le();
            $this->_m_omegadot = $this->_io->readF8le();
            $this->_m_w = $this->_io->readF8le();
            $this->_m_inc = $this->_io->readF8le();
            $this->_m_incDot = $this->_io->readF8le();
            $this->_m_af0 = $this->_io->readF8le();
            $this->_m_af1 = $this->_io->readF8le();
            $this->_m_af2 = $this->_io->readF8le();
            $this->_m_toeTow = $this->_io->readF8le();
            $this->_m_toeWn = $this->_io->readU2le();
            $this->_m_tocTow = $this->_io->readF8le();
            $this->_m_tocWn = $this->_io->readU2le();
            $this->_m_valid = $this->_io->readU1();
            $this->_m_healthy = $this->_io->readU1();
            $this->_m_prn = $this->_io->readU1();
        }
        protected $_m_tgd;
        protected $_m_cRs;
        protected $_m_cRc;
        protected $_m_cUc;
        protected $_m_cUs;
        protected $_m_cIc;
        protected $_m_cIs;
        protected $_m_dn;
        protected $_m_m0;
        protected $_m_ecc;
        protected $_m_sqrta;
        protected $_m_omega0;
        protected $_m_omegadot;
        protected $_m_w;
        protected $_m_inc;
        protected $_m_incDot;
        protected $_m_af0;
        protected $_m_af1;
        protected $_m_af2;
        protected $_m_toeTow;
        protected $_m_toeWn;
        protected $_m_tocTow;
        protected $_m_tocWn;
        protected $_m_valid;
        protected $_m_healthy;
        protected $_m_prn;

        /**
         * Group delay differential between L1 and L2
         */
        public function tgd() { return $this->_m_tgd; }

        /**
         * Amplitude of the sine harmonic correction term to the orbit radius
         */
        public function cRs() { return $this->_m_cRs; }

        /**
         * Amplitude of the cosine harmonic correction term to the orbit radius
         */
        public function cRc() { return $this->_m_cRc; }

        /**
         * Amplitude of the cosine harmonic correction term to the argument of
         * latitude
         */
        public function cUc() { return $this->_m_cUc; }

        /**
         * Amplitude of the sine harmonic correction term to the argument of
         * latitude
         */
        public function cUs() { return $this->_m_cUs; }

        /**
         * Amplitude of the cosine harmonic correction term to the angle of
         * inclination
         */
        public function cIc() { return $this->_m_cIc; }

        /**
         * Amplitude of the sine harmonic correction term to the angle of
         * inclination
         */
        public function cIs() { return $this->_m_cIs; }

        /**
         * Mean motion difference
         */
        public function dn() { return $this->_m_dn; }

        /**
         * Mean anomaly at reference time
         */
        public function m0() { return $this->_m_m0; }

        /**
         * Eccentricity of satellite orbit
         */
        public function ecc() { return $this->_m_ecc; }

        /**
         * Square root of the semi-major axis of orbit
         */
        public function sqrta() { return $this->_m_sqrta; }

        /**
         * Longitude of ascending node of orbit plane at weekly epoch
         */
        public function omega0() { return $this->_m_omega0; }

        /**
         * Rate of right ascension
         */
        public function omegadot() { return $this->_m_omegadot; }

        /**
         * Argument of perigee
         */
        public function w() { return $this->_m_w; }

        /**
         * Inclination
         */
        public function inc() { return $this->_m_inc; }

        /**
         * Inclination first derivative
         */
        public function incDot() { return $this->_m_incDot; }

        /**
         * Polynomial clock correction coefficient (clock bias)
         */
        public function af0() { return $this->_m_af0; }

        /**
         * Polynomial clock correction coefficient (clock drift)
         */
        public function af1() { return $this->_m_af1; }

        /**
         * Polynomial clock correction coefficient (rate of clock drift)
         */
        public function af2() { return $this->_m_af2; }

        /**
         * Time of week
         */
        public function toeTow() { return $this->_m_toeTow; }

        /**
         * Week number
         */
        public function toeWn() { return $this->_m_toeWn; }

        /**
         * Clock reference time of week
         */
        public function tocTow() { return $this->_m_tocTow; }

        /**
         * Clock reference week number
         */
        public function tocWn() { return $this->_m_tocWn; }

        /**
         * Is valid?
         */
        public function valid() { return $this->_m_valid; }

        /**
         * Satellite is healthy?
         */
        public function healthy() { return $this->_m_healthy; }

        /**
         * PRN being tracked
         */
        public function prn() { return $this->_m_prn; }
    }
}

namespace Observation {
    class EphemerisCommonContentDepB extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Observation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_toe = new \Gnss\GpsTimeSec($this->_io, $this, $this->_root);
            $this->_m_ura = $this->_io->readF8le();
            $this->_m_fitInterval = $this->_io->readU4le();
            $this->_m_valid = $this->_io->readU1();
            $this->_m_healthBits = $this->_io->readU1();
        }
        protected $_m_sid;
        protected $_m_toe;
        protected $_m_ura;
        protected $_m_fitInterval;
        protected $_m_valid;
        protected $_m_healthBits;

        /**
         * GNSS signal identifier (16 bit)
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Time of Ephemerides
         */
        public function toe() { return $this->_m_toe; }

        /**
         * User Range Accuracy
         */
        public function ura() { return $this->_m_ura; }

        /**
         * Curve fit interval
         */
        public function fitInterval() { return $this->_m_fitInterval; }

        /**
         * Status of ephemeris, 1 = valid, 0 = invalid
         */
        public function valid() { return $this->_m_valid; }

        /**
         * Satellite health status.
         * GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
         * Others: 0 = valid, non-zero = invalid
         */
        public function healthBits() { return $this->_m_healthBits; }
    }
}
