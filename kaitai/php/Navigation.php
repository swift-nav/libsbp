<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Navigation extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * This position solution message reports the absolute geodetic coordinates
 * and the status (single point vs pseudo-absolute RTK) of the position
 * solution. If the rover receiver knows the surveyed position of the base
 * station and has an RTK solution, this reports a pseudo-absolute position
 * solution using the base station position and the rover's RTK baseline
 * vector. The full GPS time is given by the preceding MSG_GPS_TIME with
 * the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgPosLlhDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_lat = $this->_io->readF8le();
            $this->_m_lon = $this->_io->readF8le();
            $this->_m_height = $this->_io->readF8le();
            $this->_m_hAccuracy = $this->_io->readU2le();
            $this->_m_vAccuracy = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_lat;
        protected $_m_lon;
        protected $_m_height;
        protected $_m_hAccuracy;
        protected $_m_vAccuracy;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

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

        /**
         * Horizontal position accuracy estimate (not implemented). Defaults to
         * 0.
         */
        public function hAccuracy() { return $this->_m_hAccuracy; }

        /**
         * Vertical position accuracy estimate (not implemented). Defaults to
         * 0.
         */
        public function vAccuracy() { return $this->_m_vAccuracy; }

        /**
         * Number of satellites used in solution.
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the local vertical and horizontal protection levels
 * associated with a given LLH position solution. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week
 * (tow).
 */

namespace Navigation {
    class MsgProtectionLevelDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_vpl = $this->_io->readU2le();
            $this->_m_hpl = $this->_io->readU2le();
            $this->_m_lat = $this->_io->readF8le();
            $this->_m_lon = $this->_io->readF8le();
            $this->_m_height = $this->_io->readF8le();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_vpl;
        protected $_m_hpl;
        protected $_m_lat;
        protected $_m_lon;
        protected $_m_height;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Vertical protection level
         */
        public function vpl() { return $this->_m_vpl; }

        /**
         * Horizontal protection level
         */
        public function hpl() { return $this->_m_hpl; }

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

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This position solution message reports the absolute geodetic coordinates
 * and the status (single point vs pseudo-absolute RTK) of the position
 * solution as well as the upper triangle of the 3x3 covariance matrix.
 * The position information and Fix Mode flags follow the MSG_POS_LLH
 * message.  Since the covariance matrix is computed in the local-level
 * North, East, Down frame, the covariance terms follow that convention.
 * Thus, covariances are reported against the "downward" measurement and
 * care should be taken with the sign convention.
 */

namespace Navigation {
    class MsgPosLlhCov extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_lat = $this->_io->readF8le();
            $this->_m_lon = $this->_io->readF8le();
            $this->_m_height = $this->_io->readF8le();
            $this->_m_covNN = $this->_io->readF4le();
            $this->_m_covNE = $this->_io->readF4le();
            $this->_m_covND = $this->_io->readF4le();
            $this->_m_covEE = $this->_io->readF4le();
            $this->_m_covED = $this->_io->readF4le();
            $this->_m_covDD = $this->_io->readF4le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_lat;
        protected $_m_lon;
        protected $_m_height;
        protected $_m_covNN;
        protected $_m_covNE;
        protected $_m_covND;
        protected $_m_covEE;
        protected $_m_covED;
        protected $_m_covDD;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Latitude
         */
        public function lat() { return $this->_m_lat; }

        /**
         * Longitude
         */
        public function lon() { return $this->_m_lon; }

        /**
         * Height above WGS84 ellipsoid
         */
        public function height() { return $this->_m_height; }

        /**
         * Estimated variance of northing
         */
        public function covNN() { return $this->_m_covNN; }

        /**
         * Covariance of northing and easting
         */
        public function covNE() { return $this->_m_covNE; }

        /**
         * Covariance of northing and downward measurement
         */
        public function covND() { return $this->_m_covND; }

        /**
         * Estimated variance of easting
         */
        public function covEE() { return $this->_m_covEE; }

        /**
         * Covariance of easting and downward measurement
         */
        public function covED() { return $this->_m_covED; }

        /**
         * Estimated variance of downward measurement
         */
        public function covDD() { return $this->_m_covDD; }

        /**
         * Number of satellites used in solution.
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week
 * (tow).
 */

namespace Navigation {
    class MsgVelNedDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_n = $this->_io->readS4le();
            $this->_m_e = $this->_io->readS4le();
            $this->_m_d = $this->_io->readS4le();
            $this->_m_hAccuracy = $this->_io->readU2le();
            $this->_m_vAccuracy = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_n;
        protected $_m_e;
        protected $_m_d;
        protected $_m_hAccuracy;
        protected $_m_vAccuracy;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Velocity North coordinate
         */
        public function n() { return $this->_m_n; }

        /**
         * Velocity East coordinate
         */
        public function e() { return $this->_m_e; }

        /**
         * Velocity Down coordinate
         */
        public function d() { return $this->_m_d; }

        /**
         * Horizontal velocity accuracy estimate (not implemented). Defaults to
         * 0.
         */
        public function hAccuracy() { return $this->_m_hAccuracy; }

        /**
         * Vertical velocity accuracy estimate (not implemented). Defaults to
         * 0.
         */
        public function vAccuracy() { return $this->_m_vAccuracy; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags (reserved)
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week
 * (tow). This message is similar to the MSG_VEL_NED, but it includes the
 * upper triangular portion of the 3x3 covariance matrix.
 */

namespace Navigation {
    class MsgVelNedCov extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_n = $this->_io->readS4le();
            $this->_m_e = $this->_io->readS4le();
            $this->_m_d = $this->_io->readS4le();
            $this->_m_covNN = $this->_io->readF4le();
            $this->_m_covNE = $this->_io->readF4le();
            $this->_m_covND = $this->_io->readF4le();
            $this->_m_covEE = $this->_io->readF4le();
            $this->_m_covED = $this->_io->readF4le();
            $this->_m_covDD = $this->_io->readF4le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_n;
        protected $_m_e;
        protected $_m_d;
        protected $_m_covNN;
        protected $_m_covNE;
        protected $_m_covND;
        protected $_m_covEE;
        protected $_m_covED;
        protected $_m_covDD;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Velocity North coordinate
         */
        public function n() { return $this->_m_n; }

        /**
         * Velocity East coordinate
         */
        public function e() { return $this->_m_e; }

        /**
         * Velocity Down coordinate
         */
        public function d() { return $this->_m_d; }

        /**
         * Estimated variance of northward measurement
         */
        public function covNN() { return $this->_m_covNN; }

        /**
         * Covariance of northward and eastward measurement
         */
        public function covNE() { return $this->_m_covNE; }

        /**
         * Covariance of northward and downward measurement
         */
        public function covND() { return $this->_m_covND; }

        /**
         * Estimated variance of eastward measurement
         */
        public function covEE() { return $this->_m_covEE; }

        /**
         * Covariance of eastward and downward measurement
         */
        public function covED() { return $this->_m_covED; }

        /**
         * Estimated variance of downward measurement
         */
        public function covDD() { return $this->_m_covDD; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the Universal Coordinated Time (UTC).  Note the
 * flags which indicate the source of the UTC offset value and source of
 * the time fix.
 */

namespace Navigation {
    class MsgUtcTime extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_flags = $this->_io->readU1();
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_year = $this->_io->readU2le();
            $this->_m_month = $this->_io->readU1();
            $this->_m_day = $this->_io->readU1();
            $this->_m_hours = $this->_io->readU1();
            $this->_m_minutes = $this->_io->readU1();
            $this->_m_seconds = $this->_io->readU1();
            $this->_m_ns = $this->_io->readU4le();
        }
        protected $_m_flags;
        protected $_m_tow;
        protected $_m_year;
        protected $_m_month;
        protected $_m_day;
        protected $_m_hours;
        protected $_m_minutes;
        protected $_m_seconds;
        protected $_m_ns;

        /**
         * Indicates source and time validity
         */
        public function flags() { return $this->_m_flags; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Year
         */
        public function year() { return $this->_m_year; }

        /**
         * Month (range 1 .. 12)
         */
        public function month() { return $this->_m_month; }

        /**
         * days in the month (range 1-31)
         */
        public function day() { return $this->_m_day; }

        /**
         * hours of day (range 0-23)
         */
        public function hours() { return $this->_m_hours; }

        /**
         * minutes of hour (range 0-59)
         */
        public function minutes() { return $this->_m_minutes; }

        /**
         * seconds of minute (range 0-60) rounded down
         */
        public function seconds() { return $this->_m_seconds; }

        /**
         * nanoseconds of second (range 0-999999999)
         */
        public function ns() { return $this->_m_ns; }
    }
}

/**
 * The position solution message reports absolute Earth Centered Earth
 * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
 * RTK) of the position solution. The message also reports the upper
 * triangular portion of the 3x3 covariance matrix. If the receiver knows
 * the surveyed position of the base station and has an RTK solution, this
 * reports a pseudo-absolute position solution using the base station
 * position and the rover's RTK baseline vector. The full GPS time is given
 * by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgPosEcefCovGnss extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_x = $this->_io->readF8le();
            $this->_m_y = $this->_io->readF8le();
            $this->_m_z = $this->_io->readF8le();
            $this->_m_covXX = $this->_io->readF4le();
            $this->_m_covXY = $this->_io->readF4le();
            $this->_m_covXZ = $this->_io->readF4le();
            $this->_m_covYY = $this->_io->readF4le();
            $this->_m_covYZ = $this->_io->readF4le();
            $this->_m_covZZ = $this->_io->readF4le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;
        protected $_m_covXX;
        protected $_m_covXY;
        protected $_m_covXZ;
        protected $_m_covYY;
        protected $_m_covYZ;
        protected $_m_covZZ;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

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

        /**
         * Estimated variance of x
         */
        public function covXX() { return $this->_m_covXX; }

        /**
         * Estimated covariance of x and y
         */
        public function covXY() { return $this->_m_covXY; }

        /**
         * Estimated covariance of x and z
         */
        public function covXZ() { return $this->_m_covXZ; }

        /**
         * Estimated variance of y
         */
        public function covYY() { return $this->_m_covYY; }

        /**
         * Estimated covariance of y and z
         */
        public function covYZ() { return $this->_m_covYZ; }

        /**
         * Estimated variance of z
         */
        public function covZZ() { return $this->_m_covZZ; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week
 * (tow).
 */

namespace Navigation {
    class MsgVelNedGnss extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_n = $this->_io->readS4le();
            $this->_m_e = $this->_io->readS4le();
            $this->_m_d = $this->_io->readS4le();
            $this->_m_hAccuracy = $this->_io->readU2le();
            $this->_m_vAccuracy = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_n;
        protected $_m_e;
        protected $_m_d;
        protected $_m_hAccuracy;
        protected $_m_vAccuracy;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Velocity North coordinate
         */
        public function n() { return $this->_m_n; }

        /**
         * Velocity East coordinate
         */
        public function e() { return $this->_m_e; }

        /**
         * Velocity Down coordinate
         */
        public function d() { return $this->_m_d; }

        /**
         * Horizontal velocity estimated standard deviation
         */
        public function hAccuracy() { return $this->_m_hAccuracy; }

        /**
         * Vertical velocity estimated standard deviation
         */
        public function vAccuracy() { return $this->_m_vAccuracy; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week
 * (tow). This message is similar to the MSG_VEL_NED, but it includes the
 * upper triangular portion of the 3x3 covariance matrix.
 */

namespace Navigation {
    class MsgVelNedCovGnss extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_n = $this->_io->readS4le();
            $this->_m_e = $this->_io->readS4le();
            $this->_m_d = $this->_io->readS4le();
            $this->_m_covNN = $this->_io->readF4le();
            $this->_m_covNE = $this->_io->readF4le();
            $this->_m_covND = $this->_io->readF4le();
            $this->_m_covEE = $this->_io->readF4le();
            $this->_m_covED = $this->_io->readF4le();
            $this->_m_covDD = $this->_io->readF4le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_n;
        protected $_m_e;
        protected $_m_d;
        protected $_m_covNN;
        protected $_m_covNE;
        protected $_m_covND;
        protected $_m_covEE;
        protected $_m_covED;
        protected $_m_covDD;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Velocity North coordinate
         */
        public function n() { return $this->_m_n; }

        /**
         * Velocity East coordinate
         */
        public function e() { return $this->_m_e; }

        /**
         * Velocity Down coordinate
         */
        public function d() { return $this->_m_d; }

        /**
         * Estimated variance of northward measurement
         */
        public function covNN() { return $this->_m_covNN; }

        /**
         * Covariance of northward and eastward measurement
         */
        public function covNE() { return $this->_m_covNE; }

        /**
         * Covariance of northward and downward measurement
         */
        public function covND() { return $this->_m_covND; }

        /**
         * Estimated variance of eastward measurement
         */
        public function covEE() { return $this->_m_covEE; }

        /**
         * Covariance of eastward and downward measurement
         */
        public function covED() { return $this->_m_covED; }

        /**
         * Estimated variance of downward measurement
         */
        public function covDD() { return $this->_m_covDD; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the baseline solution in North East Down (NED)
 * coordinates. This baseline is the relative vector distance from the base
 * station to the rover receiver, and NED coordinate system is defined at
 * the local WGS84 tangent plane centered at the base station position.
 * The full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */

namespace Navigation {
    class MsgBaselineNedDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_n = $this->_io->readS4le();
            $this->_m_e = $this->_io->readS4le();
            $this->_m_d = $this->_io->readS4le();
            $this->_m_hAccuracy = $this->_io->readU2le();
            $this->_m_vAccuracy = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_n;
        protected $_m_e;
        protected $_m_d;
        protected $_m_hAccuracy;
        protected $_m_vAccuracy;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Baseline North coordinate
         */
        public function n() { return $this->_m_n; }

        /**
         * Baseline East coordinate
         */
        public function e() { return $this->_m_e; }

        /**
         * Baseline Down coordinate
         */
        public function d() { return $this->_m_d; }

        /**
         * Horizontal position accuracy estimate (not implemented). Defaults to
         * 0.
         */
        public function hAccuracy() { return $this->_m_hAccuracy; }

        /**
         * Vertical position accuracy estimate (not implemented). Defaults to
         * 0.
         */
        public function vAccuracy() { return $this->_m_vAccuracy; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
 * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
 * with the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgVelEcefDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_x = $this->_io->readS4le();
            $this->_m_y = $this->_io->readS4le();
            $this->_m_z = $this->_io->readS4le();
            $this->_m_accuracy = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;
        protected $_m_accuracy;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Velocity ECEF X coordinate
         */
        public function x() { return $this->_m_x; }

        /**
         * Velocity ECEF Y coordinate
         */
        public function y() { return $this->_m_y; }

        /**
         * Velocity ECEF Z coordinate
         */
        public function z() { return $this->_m_z; }

        /**
         * Velocity accuracy estimate (not implemented). Defaults to 0.
         */
        public function accuracy() { return $this->_m_accuracy; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags (reserved)
         */
        public function flags() { return $this->_m_flags; }
    }
}

namespace Navigation {
    class MsgReferenceFrameParam extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_ssrIod = $this->_io->readU1();
            $this->_m_sn = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytes(32), "ascii");
            $this->_m_tn = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytes(32), "ascii");
            $this->_m_sin = $this->_io->readU1();
            $this->_m_utn = $this->_io->readU2le();
            $this->_m_reT0 = $this->_io->readU2le();
            $this->_m_deltaX0 = $this->_io->readS4le();
            $this->_m_deltaY0 = $this->_io->readS4le();
            $this->_m_deltaZ0 = $this->_io->readS4le();
            $this->_m_theta01 = $this->_io->readS4le();
            $this->_m_theta02 = $this->_io->readS4le();
            $this->_m_theta03 = $this->_io->readS4le();
            $this->_m_scale = $this->_io->readS4le();
            $this->_m_dotDeltaX0 = $this->_io->readS4le();
            $this->_m_dotDeltaY0 = $this->_io->readS4le();
            $this->_m_dotDeltaZ0 = $this->_io->readS4le();
            $this->_m_dotTheta01 = $this->_io->readS4le();
            $this->_m_dotTheta02 = $this->_io->readS4le();
            $this->_m_dotTheta03 = $this->_io->readS4le();
            $this->_m_dotScale = $this->_io->readS2le();
        }
        protected $_m_ssrIod;
        protected $_m_sn;
        protected $_m_tn;
        protected $_m_sin;
        protected $_m_utn;
        protected $_m_reT0;
        protected $_m_deltaX0;
        protected $_m_deltaY0;
        protected $_m_deltaZ0;
        protected $_m_theta01;
        protected $_m_theta02;
        protected $_m_theta03;
        protected $_m_scale;
        protected $_m_dotDeltaX0;
        protected $_m_dotDeltaY0;
        protected $_m_dotDeltaZ0;
        protected $_m_dotTheta01;
        protected $_m_dotTheta02;
        protected $_m_dotTheta03;
        protected $_m_dotScale;

        /**
         * SSR IOD parameter.
         */
        public function ssrIod() { return $this->_m_ssrIod; }

        /**
         * Name of source coordinate-system.
         */
        public function sn() { return $this->_m_sn; }

        /**
         * Name of target coordinate-system.
         */
        public function tn() { return $this->_m_tn; }

        /**
         * System Identification Number.
         */
        public function sin() { return $this->_m_sin; }

        /**
         * Utilized Transformation Message.
         */
        public function utn() { return $this->_m_utn; }

        /**
         * Reference Epoch t0 for transformation parameter set given as
         * Modified Julian Day (MJD) Number minus 44244 days.
         */
        public function reT0() { return $this->_m_reT0; }

        /**
         * Translation in X for Reference Epoch t0.
         */
        public function deltaX0() { return $this->_m_deltaX0; }

        /**
         * Translation in Y for Reference Epoch t0.
         */
        public function deltaY0() { return $this->_m_deltaY0; }

        /**
         * Translation in Z for Reference Epoch t0.
         */
        public function deltaZ0() { return $this->_m_deltaZ0; }

        /**
         * Rotation around the X-axis for Reference Epoch t0.
         */
        public function theta01() { return $this->_m_theta01; }

        /**
         * Rotation around the Y-axis for Reference Epoch t0.
         */
        public function theta02() { return $this->_m_theta02; }

        /**
         * Rotation around the Z-axis for Reference Epoch t0.
         */
        public function theta03() { return $this->_m_theta03; }

        /**
         * Scale correction for Reference Epoch t0.
         */
        public function scale() { return $this->_m_scale; }

        /**
         * Rate of change of translation in X.
         */
        public function dotDeltaX0() { return $this->_m_dotDeltaX0; }

        /**
         * Rate of change of translation in Y.
         */
        public function dotDeltaY0() { return $this->_m_dotDeltaY0; }

        /**
         * Rate of change of translation in Z.
         */
        public function dotDeltaZ0() { return $this->_m_dotDeltaZ0; }

        /**
         * Rate of change of rotation around the X-axis.
         */
        public function dotTheta01() { return $this->_m_dotTheta01; }

        /**
         * Rate of change of rotation around the Y-axis.
         */
        public function dotTheta02() { return $this->_m_dotTheta02; }

        /**
         * Rate of change of rotation around the Z-axis.
         */
        public function dotTheta03() { return $this->_m_dotTheta03; }

        /**
         * Rate of change of scale correction.
         */
        public function dotScale() { return $this->_m_dotScale; }
    }
}

/**
 * This solution message reports the relative pose of a sensor between two
 * time instances. The relative pose comprises of a rotation and a
 * translation which relates the sensor (e.g. camera) frame at a given time
 * (first keyframe) to the sensor frame at another time (second keyframe).
 * The relative translations is a 3x1 vector described in the first
 * keyframe.  Relative rotation is described by a quaternion from second
 * keyframe to the first keyframe.
 */

namespace Navigation {
    class MsgPoseRelative extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_sensorId = $this->_io->readU1();
            $this->_m_timestamp1 = $this->_io->readU4le();
            $this->_m_timestamp2 = $this->_io->readU4le();
            $this->_m_trans = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_trans[] = $this->_io->readS4le();
            }
            $this->_m_w = $this->_io->readS4le();
            $this->_m_x = $this->_io->readS4le();
            $this->_m_y = $this->_io->readS4le();
            $this->_m_z = $this->_io->readS4le();
            $this->_m_covRXX = $this->_io->readF4le();
            $this->_m_covRXY = $this->_io->readF4le();
            $this->_m_covRXZ = $this->_io->readF4le();
            $this->_m_covRYY = $this->_io->readF4le();
            $this->_m_covRYZ = $this->_io->readF4le();
            $this->_m_covRZZ = $this->_io->readF4le();
            $this->_m_covCXX = $this->_io->readF4le();
            $this->_m_covCXY = $this->_io->readF4le();
            $this->_m_covCXZ = $this->_io->readF4le();
            $this->_m_covCYY = $this->_io->readF4le();
            $this->_m_covCYZ = $this->_io->readF4le();
            $this->_m_covCZZ = $this->_io->readF4le();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_sensorId;
        protected $_m_timestamp1;
        protected $_m_timestamp2;
        protected $_m_trans;
        protected $_m_w;
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;
        protected $_m_covRXX;
        protected $_m_covRXY;
        protected $_m_covRXZ;
        protected $_m_covRYY;
        protected $_m_covRYZ;
        protected $_m_covRZZ;
        protected $_m_covCXX;
        protected $_m_covCXY;
        protected $_m_covCXZ;
        protected $_m_covCYY;
        protected $_m_covCYZ;
        protected $_m_covCZZ;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * ID of the sensor producing this message
         */
        public function sensorId() { return $this->_m_sensorId; }

        /**
         * Timestamp of first keyframe
         */
        public function timestamp1() { return $this->_m_timestamp1; }

        /**
         * Timestamp of second keyframe
         */
        public function timestamp2() { return $this->_m_timestamp2; }

        /**
         * Relative translation [x,y,z] described in first keyframe
         */
        public function trans() { return $this->_m_trans; }

        /**
         * Real component of quaternion to describe relative rotation (second
         * to first keyframe)
         */
        public function w() { return $this->_m_w; }

        /**
         * 1st imaginary component of quaternion to describe relative rotation
         * (second to first keyframe)
         */
        public function x() { return $this->_m_x; }

        /**
         * 2nd imaginary component of quaternion to describe relative rotation
         * (second to first keyframe)
         */
        public function y() { return $this->_m_y; }

        /**
         * 3rd imaginary component of quaternion to describe relative rotation
         * (second to first keyframe)
         */
        public function z() { return $this->_m_z; }

        /**
         * Estimated variance of x (relative translation)
         */
        public function covRXX() { return $this->_m_covRXX; }

        /**
         * Covariance of x and y (relative translation)
         */
        public function covRXY() { return $this->_m_covRXY; }

        /**
         * Covariance of x and z (relative translation)
         */
        public function covRXZ() { return $this->_m_covRXZ; }

        /**
         * Estimated variance of y (relative translation)
         */
        public function covRYY() { return $this->_m_covRYY; }

        /**
         * Covariance of y and z (relative translation)
         */
        public function covRYZ() { return $this->_m_covRYZ; }

        /**
         * Estimated variance of z (relative translation)
         */
        public function covRZZ() { return $this->_m_covRZZ; }

        /**
         * Estimated variance of x (relative rotation)
         */
        public function covCXX() { return $this->_m_covCXX; }

        /**
         * Covariance of x and y (relative rotation)
         */
        public function covCXY() { return $this->_m_covCXY; }

        /**
         * Covariance of x and z (relative rotation)
         */
        public function covCXZ() { return $this->_m_covCXZ; }

        /**
         * Estimated variance of y (relative rotation)
         */
        public function covCYY() { return $this->_m_covCYY; }

        /**
         * Covariance of y and z (relative rotation)
         */
        public function covCYZ() { return $this->_m_covCYZ; }

        /**
         * Estimated variance of z (relative rotation)
         */
        public function covCZZ() { return $this->_m_covCZZ; }

        /**
         * Status flags of relative translation and rotation
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
 * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
 * with the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgVelEcefCov extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_x = $this->_io->readS4le();
            $this->_m_y = $this->_io->readS4le();
            $this->_m_z = $this->_io->readS4le();
            $this->_m_covXX = $this->_io->readF4le();
            $this->_m_covXY = $this->_io->readF4le();
            $this->_m_covXZ = $this->_io->readF4le();
            $this->_m_covYY = $this->_io->readF4le();
            $this->_m_covYZ = $this->_io->readF4le();
            $this->_m_covZZ = $this->_io->readF4le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;
        protected $_m_covXX;
        protected $_m_covXY;
        protected $_m_covXZ;
        protected $_m_covYY;
        protected $_m_covYZ;
        protected $_m_covZZ;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Velocity ECEF X coordinate
         */
        public function x() { return $this->_m_x; }

        /**
         * Velocity ECEF Y coordinate
         */
        public function y() { return $this->_m_y; }

        /**
         * Velocity ECEF Z coordinate
         */
        public function z() { return $this->_m_z; }

        /**
         * Estimated variance of x
         */
        public function covXX() { return $this->_m_covXX; }

        /**
         * Estimated covariance of x and y
         */
        public function covXY() { return $this->_m_covXY; }

        /**
         * Estimated covariance of x and z
         */
        public function covXZ() { return $this->_m_covXZ; }

        /**
         * Estimated variance of y
         */
        public function covYY() { return $this->_m_covYY; }

        /**
         * Estimated covariance of y and z
         */
        public function covYZ() { return $this->_m_covYZ; }

        /**
         * Estimated variance of z
         */
        public function covZZ() { return $this->_m_covZZ; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the velocity in the Vehicle Body Frame. By
 * convention, the x-axis should point out the nose of the vehicle and
 * represent the forward direction, while as the y-axis should point out
 * the right hand side of the vehicle. Since this is a right handed system,
 * z should point out the bottom of the vehicle. The orientation and origin
 * of the Vehicle Body Frame are specified via the device settings. The
 * full GPS time is given by the preceding MSG_GPS_TIME with the matching
 * time-of-week (tow). This message is only produced by inertial versions
 * of Swift products and is not available from Piksi Multi or Duro.
 */

namespace Navigation {
    class MsgVelBody extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_x = $this->_io->readS4le();
            $this->_m_y = $this->_io->readS4le();
            $this->_m_z = $this->_io->readS4le();
            $this->_m_covXX = $this->_io->readF4le();
            $this->_m_covXY = $this->_io->readF4le();
            $this->_m_covXZ = $this->_io->readF4le();
            $this->_m_covYY = $this->_io->readF4le();
            $this->_m_covYZ = $this->_io->readF4le();
            $this->_m_covZZ = $this->_io->readF4le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;
        protected $_m_covXX;
        protected $_m_covXY;
        protected $_m_covXZ;
        protected $_m_covYY;
        protected $_m_covYZ;
        protected $_m_covZZ;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Velocity in x direction
         */
        public function x() { return $this->_m_x; }

        /**
         * Velocity in y direction
         */
        public function y() { return $this->_m_y; }

        /**
         * Velocity in z direction
         */
        public function z() { return $this->_m_z; }

        /**
         * Estimated variance of x
         */
        public function covXX() { return $this->_m_covXX; }

        /**
         * Covariance of x and y
         */
        public function covXY() { return $this->_m_covXY; }

        /**
         * Covariance of x and z
         */
        public function covXZ() { return $this->_m_covXZ; }

        /**
         * Estimated variance of y
         */
        public function covYY() { return $this->_m_covYY; }

        /**
         * Covariance of y and z
         */
        public function covYZ() { return $this->_m_covYZ; }

        /**
         * Estimated variance of z
         */
        public function covZZ() { return $this->_m_covZZ; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
 * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
 * with the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgVelEcefGnss extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_x = $this->_io->readS4le();
            $this->_m_y = $this->_io->readS4le();
            $this->_m_z = $this->_io->readS4le();
            $this->_m_accuracy = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;
        protected $_m_accuracy;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Velocity ECEF X coordinate
         */
        public function x() { return $this->_m_x; }

        /**
         * Velocity ECEF Y coordinate
         */
        public function y() { return $this->_m_y; }

        /**
         * Velocity ECEF Z coordinate
         */
        public function z() { return $this->_m_z; }

        /**
         * Velocity estimated standard deviation
         */
        public function accuracy() { return $this->_m_accuracy; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
 * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
 * with the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgVelEcef extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_x = $this->_io->readS4le();
            $this->_m_y = $this->_io->readS4le();
            $this->_m_z = $this->_io->readS4le();
            $this->_m_accuracy = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;
        protected $_m_accuracy;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Velocity ECEF X coordinate
         */
        public function x() { return $this->_m_x; }

        /**
         * Velocity ECEF Y coordinate
         */
        public function y() { return $this->_m_y; }

        /**
         * Velocity ECEF Z coordinate
         */
        public function z() { return $this->_m_z; }

        /**
         * Velocity estimated standard deviation
         */
        public function accuracy() { return $this->_m_accuracy; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This position solution message reports the absolute geodetic coordinates
 * and the status (single point vs pseudo-absolute RTK) of the position
 * solution as well as the upper triangle of the 3x3 covariance matrix.
 * The position information and Fix Mode flags should follow the
 * MSG_POS_LLH message.  Since the covariance matrix is computed in the
 * local-level North, East, Down frame, the covariance terms follow with
 * that convention. Thus, covariances are reported against the "downward"
 * measurement and care should be taken with the sign convention.
 */

namespace Navigation {
    class MsgPosLlhCovGnss extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_lat = $this->_io->readF8le();
            $this->_m_lon = $this->_io->readF8le();
            $this->_m_height = $this->_io->readF8le();
            $this->_m_covNN = $this->_io->readF4le();
            $this->_m_covNE = $this->_io->readF4le();
            $this->_m_covND = $this->_io->readF4le();
            $this->_m_covEE = $this->_io->readF4le();
            $this->_m_covED = $this->_io->readF4le();
            $this->_m_covDD = $this->_io->readF4le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_lat;
        protected $_m_lon;
        protected $_m_height;
        protected $_m_covNN;
        protected $_m_covNE;
        protected $_m_covND;
        protected $_m_covEE;
        protected $_m_covED;
        protected $_m_covDD;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Latitude
         */
        public function lat() { return $this->_m_lat; }

        /**
         * Longitude
         */
        public function lon() { return $this->_m_lon; }

        /**
         * Height above WGS84 ellipsoid
         */
        public function height() { return $this->_m_height; }

        /**
         * Estimated variance of northing
         */
        public function covNN() { return $this->_m_covNN; }

        /**
         * Covariance of northing and easting
         */
        public function covNE() { return $this->_m_covNE; }

        /**
         * Covariance of northing and downward measurement
         */
        public function covND() { return $this->_m_covND; }

        /**
         * Estimated variance of easting
         */
        public function covEE() { return $this->_m_covEE; }

        /**
         * Covariance of easting and downward measurement
         */
        public function covED() { return $this->_m_covED; }

        /**
         * Estimated variance of downward measurement
         */
        public function covDD() { return $this->_m_covDD; }

        /**
         * Number of satellites used in solution.
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the baseline solution in Earth Centered Earth Fixed
 * (ECEF) coordinates. This baseline is the relative vector distance from
 * the base station to the rover receiver. The full GPS time is given by
 * the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgBaselineEcef extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_x = $this->_io->readS4le();
            $this->_m_y = $this->_io->readS4le();
            $this->_m_z = $this->_io->readS4le();
            $this->_m_accuracy = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;
        protected $_m_accuracy;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Baseline ECEF X coordinate
         */
        public function x() { return $this->_m_x; }

        /**
         * Baseline ECEF Y coordinate
         */
        public function y() { return $this->_m_y; }

        /**
         * Baseline ECEF Z coordinate
         */
        public function z() { return $this->_m_z; }

        /**
         * Position estimated standard deviation
         */
        public function accuracy() { return $this->_m_accuracy; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This dilution of precision (DOP) message describes the effect of
 * navigation satellite geometry on positional measurement precision.
 */

namespace Navigation {
    class MsgDopsDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_gdop = $this->_io->readU2le();
            $this->_m_pdop = $this->_io->readU2le();
            $this->_m_tdop = $this->_io->readU2le();
            $this->_m_hdop = $this->_io->readU2le();
            $this->_m_vdop = $this->_io->readU2le();
        }
        protected $_m_tow;
        protected $_m_gdop;
        protected $_m_pdop;
        protected $_m_tdop;
        protected $_m_hdop;
        protected $_m_vdop;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Geometric Dilution of Precision
         */
        public function gdop() { return $this->_m_gdop; }

        /**
         * Position Dilution of Precision
         */
        public function pdop() { return $this->_m_pdop; }

        /**
         * Time Dilution of Precision
         */
        public function tdop() { return $this->_m_tdop; }

        /**
         * Horizontal Dilution of Precision
         */
        public function hdop() { return $this->_m_hdop; }

        /**
         * Vertical Dilution of Precision
         */
        public function vdop() { return $this->_m_vdop; }
    }
}

/**
 * The position solution message reports absolute Earth Centered Earth
 * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
 * RTK) of the position solution. If the rover receiver knows the surveyed
 * position of the base station and has an RTK solution, this reports a
 * pseudo-absolute position solution using the base station position and
 * the rover's RTK baseline vector. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgPosEcef extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_x = $this->_io->readF8le();
            $this->_m_y = $this->_io->readF8le();
            $this->_m_z = $this->_io->readF8le();
            $this->_m_accuracy = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;
        protected $_m_accuracy;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

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

        /**
         * Position estimated standard deviation
         */
        public function accuracy() { return $this->_m_accuracy; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the Age of the corrections used for the current
 * Differential solution.
 */

namespace Navigation {
    class MsgAgeCorrections extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_age = $this->_io->readU2le();
        }
        protected $_m_tow;
        protected $_m_age;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Age of the corrections (0xFFFF indicates invalid)
         */
        public function age() { return $this->_m_age; }
    }
}

/**
 * This message reports the velocity in Earth Centered Earth Fixed (ECEF)
 * coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
 * with the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgVelEcefCovGnss extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_x = $this->_io->readS4le();
            $this->_m_y = $this->_io->readS4le();
            $this->_m_z = $this->_io->readS4le();
            $this->_m_covXX = $this->_io->readF4le();
            $this->_m_covXY = $this->_io->readF4le();
            $this->_m_covXZ = $this->_io->readF4le();
            $this->_m_covYY = $this->_io->readF4le();
            $this->_m_covYZ = $this->_io->readF4le();
            $this->_m_covZZ = $this->_io->readF4le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;
        protected $_m_covXX;
        protected $_m_covXY;
        protected $_m_covXZ;
        protected $_m_covYY;
        protected $_m_covYZ;
        protected $_m_covZZ;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Velocity ECEF X coordinate
         */
        public function x() { return $this->_m_x; }

        /**
         * Velocity ECEF Y coordinate
         */
        public function y() { return $this->_m_y; }

        /**
         * Velocity ECEF Z coordinate
         */
        public function z() { return $this->_m_z; }

        /**
         * Estimated variance of x
         */
        public function covXX() { return $this->_m_covXX; }

        /**
         * Estimated covariance of x and y
         */
        public function covXY() { return $this->_m_covXY; }

        /**
         * Estimated covariance of x and z
         */
        public function covXZ() { return $this->_m_covXZ; }

        /**
         * Estimated variance of y
         */
        public function covYY() { return $this->_m_covYY; }

        /**
         * Estimated covariance of y and z
         */
        public function covYZ() { return $this->_m_covYZ; }

        /**
         * Estimated variance of z
         */
        public function covZZ() { return $this->_m_covZZ; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the protection levels associated to the given state
 * estimate. The full GPS time is given by the preceding MSG_GPS_TIME with
 * the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgProtectionLevel extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_wn = $this->_io->readS2le();
            $this->_m_hpl = $this->_io->readU2le();
            $this->_m_vpl = $this->_io->readU2le();
            $this->_m_atpl = $this->_io->readU2le();
            $this->_m_ctpl = $this->_io->readU2le();
            $this->_m_hvpl = $this->_io->readU2le();
            $this->_m_vvpl = $this->_io->readU2le();
            $this->_m_hopl = $this->_io->readU2le();
            $this->_m_popl = $this->_io->readU2le();
            $this->_m_ropl = $this->_io->readU2le();
            $this->_m_lat = $this->_io->readF8le();
            $this->_m_lon = $this->_io->readF8le();
            $this->_m_height = $this->_io->readF8le();
            $this->_m_vX = $this->_io->readS4le();
            $this->_m_vY = $this->_io->readS4le();
            $this->_m_vZ = $this->_io->readS4le();
            $this->_m_roll = $this->_io->readS4le();
            $this->_m_pitch = $this->_io->readS4le();
            $this->_m_heading = $this->_io->readS4le();
            $this->_m_flags = $this->_io->readU4le();
        }
        protected $_m_tow;
        protected $_m_wn;
        protected $_m_hpl;
        protected $_m_vpl;
        protected $_m_atpl;
        protected $_m_ctpl;
        protected $_m_hvpl;
        protected $_m_vvpl;
        protected $_m_hopl;
        protected $_m_popl;
        protected $_m_ropl;
        protected $_m_lat;
        protected $_m_lon;
        protected $_m_height;
        protected $_m_vX;
        protected $_m_vY;
        protected $_m_vZ;
        protected $_m_roll;
        protected $_m_pitch;
        protected $_m_heading;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * GPS week number
         */
        public function wn() { return $this->_m_wn; }

        /**
         * Horizontal protection level
         */
        public function hpl() { return $this->_m_hpl; }

        /**
         * Vertical protection level
         */
        public function vpl() { return $this->_m_vpl; }

        /**
         * Along-track position error protection level
         */
        public function atpl() { return $this->_m_atpl; }

        /**
         * Cross-track position error protection level
         */
        public function ctpl() { return $this->_m_ctpl; }

        /**
         * Protection level for the error vector between estimated and true
         * along/cross track velocity vector
         */
        public function hvpl() { return $this->_m_hvpl; }

        /**
         * Protection level for the velocity in vehicle upright direction
         * (different from vertical direction if on a slope)
         */
        public function vvpl() { return $this->_m_vvpl; }

        /**
         * Heading orientation protection level
         */
        public function hopl() { return $this->_m_hopl; }

        /**
         * Pitch orientation protection level
         */
        public function popl() { return $this->_m_popl; }

        /**
         * Roll orientation protection level
         */
        public function ropl() { return $this->_m_ropl; }

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

        /**
         * Velocity in vehicle x direction
         */
        public function vX() { return $this->_m_vX; }

        /**
         * Velocity in vehicle y direction
         */
        public function vY() { return $this->_m_vY; }

        /**
         * Velocity in vehicle z direction
         */
        public function vZ() { return $this->_m_vZ; }

        /**
         * Roll angle
         */
        public function roll() { return $this->_m_roll; }

        /**
         * Pitch angle
         */
        public function pitch() { return $this->_m_pitch; }

        /**
         * Heading angle
         */
        public function heading() { return $this->_m_heading; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * The position solution message reports absolute Earth Centered Earth
 * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
 * RTK) of the position solution. The message also reports the upper
 * triangular portion of the 3x3 covariance matrix. If the receiver knows
 * the surveyed position of the base station and has an RTK solution, this
 * reports a pseudo-absolute position solution using the base station
 * position and the rover's RTK baseline vector. The full GPS time is given
 * by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgPosEcefCov extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_x = $this->_io->readF8le();
            $this->_m_y = $this->_io->readF8le();
            $this->_m_z = $this->_io->readF8le();
            $this->_m_covXX = $this->_io->readF4le();
            $this->_m_covXY = $this->_io->readF4le();
            $this->_m_covXZ = $this->_io->readF4le();
            $this->_m_covYY = $this->_io->readF4le();
            $this->_m_covYZ = $this->_io->readF4le();
            $this->_m_covZZ = $this->_io->readF4le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;
        protected $_m_covXX;
        protected $_m_covXY;
        protected $_m_covXZ;
        protected $_m_covYY;
        protected $_m_covYZ;
        protected $_m_covZZ;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

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

        /**
         * Estimated variance of x
         */
        public function covXX() { return $this->_m_covXX; }

        /**
         * Estimated covariance of x and y
         */
        public function covXY() { return $this->_m_covXY; }

        /**
         * Estimated covariance of x and z
         */
        public function covXZ() { return $this->_m_covXZ; }

        /**
         * Estimated variance of y
         */
        public function covYY() { return $this->_m_covYY; }

        /**
         * Estimated covariance of y and z
         */
        public function covYZ() { return $this->_m_covYZ; }

        /**
         * Estimated variance of z
         */
        public function covZZ() { return $this->_m_covZZ; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * The position solution message reports absolute Earth Centered Earth
 * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
 * RTK) of the position solution. If the rover receiver knows the surveyed
 * position of the base station and has an RTK solution, this reports a
 * pseudo-absolute position solution using the base station position and
 * the rover's RTK baseline vector. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgPosEcefGnss extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_x = $this->_io->readF8le();
            $this->_m_y = $this->_io->readF8le();
            $this->_m_z = $this->_io->readF8le();
            $this->_m_accuracy = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;
        protected $_m_accuracy;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

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

        /**
         * Position estimated standard deviation
         */
        public function accuracy() { return $this->_m_accuracy; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week
 * (tow).
 */

namespace Navigation {
    class MsgVelNed extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_n = $this->_io->readS4le();
            $this->_m_e = $this->_io->readS4le();
            $this->_m_d = $this->_io->readS4le();
            $this->_m_hAccuracy = $this->_io->readU2le();
            $this->_m_vAccuracy = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_n;
        protected $_m_e;
        protected $_m_d;
        protected $_m_hAccuracy;
        protected $_m_vAccuracy;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Velocity North coordinate
         */
        public function n() { return $this->_m_n; }

        /**
         * Velocity East coordinate
         */
        public function e() { return $this->_m_e; }

        /**
         * Velocity Down coordinate
         */
        public function d() { return $this->_m_d; }

        /**
         * Horizontal velocity estimated standard deviation
         */
        public function hAccuracy() { return $this->_m_hAccuracy; }

        /**
         * Vertical velocity estimated standard deviation
         */
        public function vAccuracy() { return $this->_m_vAccuracy; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * UTC-GPST leap seconds before and after the most recent (past, or future,
 * for announced insertions) UTC leap second insertion.
 */

namespace Navigation {
    class MsgUtcLeapSecond extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_reserved0 = $this->_io->readS2le();
            $this->_m_reserved1 = $this->_io->readS2le();
            $this->_m_reserved2 = $this->_io->readS1();
            $this->_m_countBefore = $this->_io->readS1();
            $this->_m_reserved3 = $this->_io->readU2le();
            $this->_m_reserved4 = $this->_io->readU2le();
            $this->_m_refWn = $this->_io->readU2le();
            $this->_m_refDn = $this->_io->readU1();
            $this->_m_countAfter = $this->_io->readS1();
        }
        protected $_m_reserved0;
        protected $_m_reserved1;
        protected $_m_reserved2;
        protected $_m_countBefore;
        protected $_m_reserved3;
        protected $_m_reserved4;
        protected $_m_refWn;
        protected $_m_refDn;
        protected $_m_countAfter;

        /**
         * Reserved.
         */
        public function reserved0() { return $this->_m_reserved0; }

        /**
         * Reserved.
         */
        public function reserved1() { return $this->_m_reserved1; }

        /**
         * Reserved.
         */
        public function reserved2() { return $this->_m_reserved2; }

        /**
         * Leap second count before insertion.
         */
        public function countBefore() { return $this->_m_countBefore; }

        /**
         * Reserved.
         */
        public function reserved3() { return $this->_m_reserved3; }

        /**
         * Reserved.
         */
        public function reserved4() { return $this->_m_reserved4; }

        /**
         * Leap second reference GPS week number.
         */
        public function refWn() { return $this->_m_refWn; }

        /**
         * Leap second reference day number.
         */
        public function refDn() { return $this->_m_refDn; }

        /**
         * Leap second count after insertion.
         */
        public function countAfter() { return $this->_m_countAfter; }
    }
}

/**
 * This message reports the GPS time, representing the time since the GPS
 * epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
 * and seconds of the week. The weeks begin at the Saturday/Sunday
 * transition. GPS week 0 began at the beginning of the GPS time scale.
 * 
 * Within each week number, the GPS time of the week is between between 0
 * and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
 * leap seconds, and as of now, has a small offset from UTC. In a message
 * stream, this message precedes a set of other navigation messages
 * referenced to the same time (but lacking the ns field) and indicates a
 * more precise time of these messages.
 */

namespace Navigation {
    class MsgGpsTimeDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_wn = $this->_io->readU2le();
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_nsResidual = $this->_io->readS4le();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_wn;
        protected $_m_tow;
        protected $_m_nsResidual;
        protected $_m_flags;

        /**
         * GPS week number
         */
        public function wn() { return $this->_m_wn; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
         * to 500000)
         */
        public function nsResidual() { return $this->_m_nsResidual; }

        /**
         * Status flags (reserved)
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This position solution message reports the absolute geodetic coordinates
 * and the status (single point vs pseudo-absolute RTK) of the position
 * solution. If the rover receiver knows the surveyed position of the base
 * station and has an RTK solution, this reports a pseudo-absolute position
 * solution using the base station position and the rover's RTK baseline
 * vector. The full GPS time is given by the preceding MSG_GPS_TIME with
 * the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgPosLlhGnss extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_lat = $this->_io->readF8le();
            $this->_m_lon = $this->_io->readF8le();
            $this->_m_height = $this->_io->readF8le();
            $this->_m_hAccuracy = $this->_io->readU2le();
            $this->_m_vAccuracy = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_lat;
        protected $_m_lon;
        protected $_m_height;
        protected $_m_hAccuracy;
        protected $_m_vAccuracy;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Latitude
         */
        public function lat() { return $this->_m_lat; }

        /**
         * Longitude
         */
        public function lon() { return $this->_m_lon; }

        /**
         * Height above WGS84 ellipsoid
         */
        public function height() { return $this->_m_height; }

        /**
         * Horizontal position estimated standard deviation
         */
        public function hAccuracy() { return $this->_m_hAccuracy; }

        /**
         * Vertical position estimated standard deviation
         */
        public function vAccuracy() { return $this->_m_vAccuracy; }

        /**
         * Number of satellites used in solution.
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the Universal Coordinated Time (UTC).  Note the
 * flags which indicate the source of the UTC offset value and source of
 * the time fix.
 */

namespace Navigation {
    class MsgUtcTimeGnss extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_flags = $this->_io->readU1();
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_year = $this->_io->readU2le();
            $this->_m_month = $this->_io->readU1();
            $this->_m_day = $this->_io->readU1();
            $this->_m_hours = $this->_io->readU1();
            $this->_m_minutes = $this->_io->readU1();
            $this->_m_seconds = $this->_io->readU1();
            $this->_m_ns = $this->_io->readU4le();
        }
        protected $_m_flags;
        protected $_m_tow;
        protected $_m_year;
        protected $_m_month;
        protected $_m_day;
        protected $_m_hours;
        protected $_m_minutes;
        protected $_m_seconds;
        protected $_m_ns;

        /**
         * Indicates source and time validity
         */
        public function flags() { return $this->_m_flags; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Year
         */
        public function year() { return $this->_m_year; }

        /**
         * Month (range 1 .. 12)
         */
        public function month() { return $this->_m_month; }

        /**
         * days in the month (range 1-31)
         */
        public function day() { return $this->_m_day; }

        /**
         * hours of day (range 0-23)
         */
        public function hours() { return $this->_m_hours; }

        /**
         * minutes of hour (range 0-59)
         */
        public function minutes() { return $this->_m_minutes; }

        /**
         * seconds of minute (range 0-60) rounded down
         */
        public function seconds() { return $this->_m_seconds; }

        /**
         * nanoseconds of second (range 0-999999999)
         */
        public function ns() { return $this->_m_ns; }
    }
}

/**
 * This message reports the receiver course over ground (COG) and speed
 * over  ground (SOG) based on the horizontal (N-E) components of the NED
 * velocity  vector. It also includes the vertical velocity coordinate. A
 * flag is provided to indicate whether the COG value has been frozen. When
 * the flag is set to true, the COG field is set to its last valid value
 * until  the system exceeds a minimum velocity threshold. No other fields
 * are  affected by this flag.  The NED coordinate system is defined as the
 * local WGS84 tangent  plane centered at the current position. The full
 * GPS time is given by the  preceding MSG_GPS_TIME with the matching time-
 * of-week (tow). Note: course over ground represents the receiver's
 * direction of travel,  but not necessarily the device heading.
 */

namespace Navigation {
    class MsgVelCog extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_cog = $this->_io->readU4le();
            $this->_m_sog = $this->_io->readU4le();
            $this->_m_vUp = $this->_io->readS4le();
            $this->_m_cogAccuracy = $this->_io->readU4le();
            $this->_m_sogAccuracy = $this->_io->readU4le();
            $this->_m_vUpAccuracy = $this->_io->readU4le();
            $this->_m_flags = $this->_io->readU2le();
        }
        protected $_m_tow;
        protected $_m_cog;
        protected $_m_sog;
        protected $_m_vUp;
        protected $_m_cogAccuracy;
        protected $_m_sogAccuracy;
        protected $_m_vUpAccuracy;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Course over ground relative to north direction
         */
        public function cog() { return $this->_m_cog; }

        /**
         * Speed over ground (based on horizontal velocity)
         */
        public function sog() { return $this->_m_sog; }

        /**
         * Vertical velocity component (positive up)
         */
        public function vUp() { return $this->_m_vUp; }

        /**
         * Course over ground estimated standard deviation
         */
        public function cogAccuracy() { return $this->_m_cogAccuracy; }

        /**
         * Speed over ground estimated standard deviation
         */
        public function sogAccuracy() { return $this->_m_sogAccuracy; }

        /**
         * Vertical velocity estimated standard deviation
         */
        public function vUpAccuracy() { return $this->_m_vUpAccuracy; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the baseline solution in North East Down (NED)
 * coordinates. This baseline is the relative vector distance from the base
 * station to the rover receiver, and NED coordinate system is defined at
 * the local WGS84 tangent plane centered at the base station position.
 * The full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */

namespace Navigation {
    class MsgBaselineNed extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_n = $this->_io->readS4le();
            $this->_m_e = $this->_io->readS4le();
            $this->_m_d = $this->_io->readS4le();
            $this->_m_hAccuracy = $this->_io->readU2le();
            $this->_m_vAccuracy = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_n;
        protected $_m_e;
        protected $_m_d;
        protected $_m_hAccuracy;
        protected $_m_vAccuracy;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Baseline North coordinate
         */
        public function n() { return $this->_m_n; }

        /**
         * Baseline East coordinate
         */
        public function e() { return $this->_m_e; }

        /**
         * Baseline Down coordinate
         */
        public function d() { return $this->_m_d; }

        /**
         * Horizontal position estimated standard deviation
         */
        public function hAccuracy() { return $this->_m_hAccuracy; }

        /**
         * Vertical position estimated standard deviation
         */
        public function vAccuracy() { return $this->_m_vAccuracy; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This position solution message reports the absolute geodetic coordinates
 * and the status (single point vs pseudo-absolute RTK) of the position
 * solution. If the rover receiver knows the surveyed position of the base
 * station and has an RTK solution, this reports a pseudo-absolute position
 * solution using the base station position and the rover's RTK baseline
 * vector. The full GPS time is given by the preceding MSG_GPS_TIME with
 * the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgPosLlh extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_lat = $this->_io->readF8le();
            $this->_m_lon = $this->_io->readF8le();
            $this->_m_height = $this->_io->readF8le();
            $this->_m_hAccuracy = $this->_io->readU2le();
            $this->_m_vAccuracy = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_lat;
        protected $_m_lon;
        protected $_m_height;
        protected $_m_hAccuracy;
        protected $_m_vAccuracy;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Latitude
         */
        public function lat() { return $this->_m_lat; }

        /**
         * Longitude
         */
        public function lon() { return $this->_m_lon; }

        /**
         * Height above WGS84 ellipsoid
         */
        public function height() { return $this->_m_height; }

        /**
         * Horizontal position estimated standard deviation
         */
        public function hAccuracy() { return $this->_m_hAccuracy; }

        /**
         * Vertical position estimated standard deviation
         */
        public function vAccuracy() { return $this->_m_vAccuracy; }

        /**
         * Number of satellites used in solution.
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the baseline heading pointing from the base station
 * to the rover relative to True North. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgBaselineHeadingDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_heading = $this->_io->readU4le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_heading;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Heading
         */
        public function heading() { return $this->_m_heading; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the GPS time, representing the time since the GPS
 * epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
 * and seconds of the week. The weeks begin at the Saturday/Sunday
 * transition. GPS week 0 began at the beginning of the GPS time scale.
 * 
 * Within each week number, the GPS time of the week is between between 0
 * and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
 * leap seconds, and as of now, has a small offset from UTC. In a message
 * stream, this message precedes a set of other navigation messages
 * referenced to the same time (but lacking the ns field) and indicates a
 * more precise time of these messages.
 */

namespace Navigation {
    class MsgGpsTimeGnss extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_wn = $this->_io->readU2le();
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_nsResidual = $this->_io->readS4le();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_wn;
        protected $_m_tow;
        protected $_m_nsResidual;
        protected $_m_flags;

        /**
         * GPS week number
         */
        public function wn() { return $this->_m_wn; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
         * to 500000)
         */
        public function nsResidual() { return $this->_m_nsResidual; }

        /**
         * Status flags (reserved)
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the baseline solution in Earth Centered Earth Fixed
 * (ECEF) coordinates. This baseline is the relative vector distance from
 * the base station to the rover receiver. The full GPS time is given by
 * the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgBaselineEcefDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_x = $this->_io->readS4le();
            $this->_m_y = $this->_io->readS4le();
            $this->_m_z = $this->_io->readS4le();
            $this->_m_accuracy = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;
        protected $_m_accuracy;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Baseline ECEF X coordinate
         */
        public function x() { return $this->_m_x; }

        /**
         * Baseline ECEF Y coordinate
         */
        public function y() { return $this->_m_y; }

        /**
         * Baseline ECEF Z coordinate
         */
        public function z() { return $this->_m_z; }

        /**
         * Position accuracy estimate
         */
        public function accuracy() { return $this->_m_accuracy; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the GPS time, representing the time since the GPS
 * epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
 * and seconds of the week. The weeks begin at the Saturday/Sunday
 * transition. GPS week 0 began at the beginning of the GPS time scale.
 * 
 * Within each week number, the GPS time of the week is between between 0
 * and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
 * leap seconds, and as of now, has a small offset from UTC. In a message
 * stream, this message precedes a set of other navigation messages
 * referenced to the same time (but lacking the ns field) and indicates a
 * more precise time of these messages.
 */

namespace Navigation {
    class MsgGpsTime extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_wn = $this->_io->readU2le();
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_nsResidual = $this->_io->readS4le();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_wn;
        protected $_m_tow;
        protected $_m_nsResidual;
        protected $_m_flags;

        /**
         * GPS week number
         */
        public function wn() { return $this->_m_wn; }

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
         * to 500000)
         */
        public function nsResidual() { return $this->_m_nsResidual; }

        /**
         * Status flags (reserved)
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This dilution of precision (DOP) message describes the effect of
 * navigation satellite geometry on positional measurement precision.  The
 * flags field indicated whether the DOP reported corresponds to
 * differential or SPP solution.
 */

namespace Navigation {
    class MsgDops extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_gdop = $this->_io->readU2le();
            $this->_m_pdop = $this->_io->readU2le();
            $this->_m_tdop = $this->_io->readU2le();
            $this->_m_hdop = $this->_io->readU2le();
            $this->_m_vdop = $this->_io->readU2le();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_gdop;
        protected $_m_pdop;
        protected $_m_tdop;
        protected $_m_hdop;
        protected $_m_vdop;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Geometric Dilution of Precision
         */
        public function gdop() { return $this->_m_gdop; }

        /**
         * Position Dilution of Precision
         */
        public function pdop() { return $this->_m_pdop; }

        /**
         * Time Dilution of Precision
         */
        public function tdop() { return $this->_m_tdop; }

        /**
         * Horizontal Dilution of Precision
         */
        public function hdop() { return $this->_m_hdop; }

        /**
         * Vertical Dilution of Precision
         */
        public function vdop() { return $this->_m_vdop; }

        /**
         * Indicates the position solution with which the DOPS message
         * corresponds
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * The position solution message reports absolute Earth Centered Earth
 * Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
 * RTK) of the position solution. If the rover receiver knows the surveyed
 * position of the base station and has an RTK solution, this reports a
 * pseudo-absolute position solution using the base station position and
 * the rover's RTK baseline vector. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */

namespace Navigation {
    class MsgPosEcefDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_x = $this->_io->readF8le();
            $this->_m_y = $this->_io->readF8le();
            $this->_m_z = $this->_io->readF8le();
            $this->_m_accuracy = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;
        protected $_m_accuracy;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

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

        /**
         * Position accuracy estimate (not implemented). Defaults to 0.
         */
        public function accuracy() { return $this->_m_accuracy; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

namespace Navigation {
    class EstimatedHorizontalErrorEllipse extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Navigation\MsgPosLlhAcc $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_semiMajor = $this->_io->readF4le();
            $this->_m_semiMinor = $this->_io->readF4le();
            $this->_m_orientation = $this->_io->readF4le();
        }
        protected $_m_semiMajor;
        protected $_m_semiMinor;
        protected $_m_orientation;

        /**
         * The semi major axis of the estimated horizontal error ellipse at the
         * user-configured confidence level; zero implies invalid.
         */
        public function semiMajor() { return $this->_m_semiMajor; }

        /**
         * The semi minor axis of the estimated horizontal error ellipse at the
         * user-configured confidence level; zero implies invalid.
         */
        public function semiMinor() { return $this->_m_semiMinor; }

        /**
         * The orientation of the semi major axis of the estimated horizontal
         * error ellipse with respect to North.
         */
        public function orientation() { return $this->_m_orientation; }
    }
}

/**
 * This position solution message reports the absolute geodetic coordinates
 * and the status (single point vs pseudo-absolute RTK) of the position
 * solution as well as the estimated horizontal, vertical, cross-track and
 * along-track errors.  The position information and Fix Mode flags  follow
 * the MSG_POS_LLH message. Since the covariance matrix is computed in the
 * local-level North, East, Down frame, the estimated error terms follow
 * that convention.
 * 
 * The estimated errors are reported at a user-configurable confidence
 * level. The user-configured percentile is encoded in the percentile
 * field.
 */

namespace Navigation {
    class MsgPosLlhAcc extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Navigation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_lat = $this->_io->readF8le();
            $this->_m_lon = $this->_io->readF8le();
            $this->_m_height = $this->_io->readF8le();
            $this->_m_orthometricHeight = $this->_io->readF8le();
            $this->_m_hAccuracy = $this->_io->readF4le();
            $this->_m_vAccuracy = $this->_io->readF4le();
            $this->_m_ctAccuracy = $this->_io->readF4le();
            $this->_m_atAccuracy = $this->_io->readF4le();
            $this->_m_hEllipse = new \Navigation\EstimatedHorizontalErrorEllipse($this->_io, $this, $this->_root);
            $this->_m_confidenceAndGeoid = $this->_io->readU1();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_lat;
        protected $_m_lon;
        protected $_m_height;
        protected $_m_orthometricHeight;
        protected $_m_hAccuracy;
        protected $_m_vAccuracy;
        protected $_m_ctAccuracy;
        protected $_m_atAccuracy;
        protected $_m_hEllipse;
        protected $_m_confidenceAndGeoid;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Latitude
         */
        public function lat() { return $this->_m_lat; }

        /**
         * Longitude
         */
        public function lon() { return $this->_m_lon; }

        /**
         * Height above WGS84 ellipsoid
         */
        public function height() { return $this->_m_height; }

        /**
         * Height above the geoid (i.e. height above mean sea level). See
         * confidence_and_geoid for geoid model used.
         */
        public function orthometricHeight() { return $this->_m_orthometricHeight; }

        /**
         * Estimated horizontal error at the user-configured confidence level;
         * zero implies invalid.
         */
        public function hAccuracy() { return $this->_m_hAccuracy; }

        /**
         * Estimated vertical error at the user-configured confidence level;
         * zero implies invalid.
         */
        public function vAccuracy() { return $this->_m_vAccuracy; }

        /**
         * Estimated cross-track error at the user-configured confidence level;
         * zero implies invalid.
         */
        public function ctAccuracy() { return $this->_m_ctAccuracy; }

        /**
         * Estimated along-track error at the user-configured confidence level;
         * zero implies invalid.
         */
        public function atAccuracy() { return $this->_m_atAccuracy; }

        /**
         * The estimated horizontal error ellipse at the user-configured
         * confidence level.
         */
        public function hEllipse() { return $this->_m_hEllipse; }

        /**
         * The lower bits describe the configured confidence level for the
         * estimated position error. The middle bits describe the geoid model
         * used to calculate the orthometric height.
         */
        public function confidenceAndGeoid() { return $this->_m_confidenceAndGeoid; }

        /**
         * Number of satellites used in solution.
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}
