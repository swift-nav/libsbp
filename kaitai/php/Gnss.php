<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Gnss extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Gnss $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * Deprecated.
 */

namespace Gnss {
    class GnssSignalDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Gnss $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sat = $this->_io->readU2le();
            $this->_m_code = $this->_io->readU1();
            $this->_m_reserved = $this->_io->readU1();
        }
        protected $_m_sat;
        protected $_m_code;
        protected $_m_reserved;

        /**
         * Constellation-specific satellite identifier.
         * 
         * Note: unlike GnssSignal, GPS satellites are encoded as (PRN - 1).
         * Other constellations do not have this offset.
         */
        public function sat() { return $this->_m_sat; }

        /**
         * Signal constellation, band and code
         */
        public function code() { return $this->_m_code; }

        /**
         * Reserved
         */
        public function reserved() { return $this->_m_reserved; }
    }
}

/**
 * Carrier phase measurement in cycles represented as a 40-bit fixed point
 * number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
 * fractional cycles. This phase has the same sign as the pseudorange.
 */

namespace Gnss {
    class CarrierPhase extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Gnss $_root = null) {
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
 * A wire-appropriate GPS time, defined as the number of milliseconds since
 * beginning of the week on the Saturday/Sunday transition.
 */

namespace Gnss {
    class GpsTimeDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Gnss $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_wn = $this->_io->readU2le();
        }
        protected $_m_tow;
        protected $_m_wn;

        /**
         * Milliseconds since start of GPS week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * GPS week number
         */
        public function wn() { return $this->_m_wn; }
    }
}

/**
 * Signal identifier containing constellation, band, and satellite
 * identifier.
 */

namespace Gnss {
    class GnssSignal extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Gnss $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sat = $this->_io->readU1();
            $this->_m_code = $this->_io->readU1();
        }
        protected $_m_sat;
        protected $_m_code;

        /**
         * Constellation-specific satellite id. For GLO can either be (100+FCN)
         * where FCN is in [-7,+6] or the Slot ID in [1,28].
         */
        public function sat() { return $this->_m_sat; }

        /**
         * Signal constellation, band and code
         */
        public function code() { return $this->_m_code; }
    }
}

/**
 * A wire-appropriate receiver clock time, defined as the time since the
 * beginning of the week on the Saturday/Sunday transition. In most cases,
 * observations are epoch aligned so ns field will be 0.
 */

namespace Gnss {
    class GpsTime extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Gnss $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_nsResidual = $this->_io->readS4le();
            $this->_m_wn = $this->_io->readU2le();
        }
        protected $_m_tow;
        protected $_m_nsResidual;
        protected $_m_wn;

        /**
         * Milliseconds since start of GPS week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Nanosecond residual of millisecond-rounded TOW (ranges from -500000
         * to 500000)
         */
        public function nsResidual() { return $this->_m_nsResidual; }

        /**
         * GPS week number
         */
        public function wn() { return $this->_m_wn; }
    }
}

/**
 * A GPS time, defined as the number of seconds since beginning of the week
 * on the Saturday/Sunday transition.
 */

namespace Gnss {
    class GpsTimeSec extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Gnss $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_wn = $this->_io->readU2le();
        }
        protected $_m_tow;
        protected $_m_wn;

        /**
         * Seconds since start of GPS week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * GPS week number
         */
        public function wn() { return $this->_m_wn; }
    }
}

/**
 * A (Constellation ID, satellite ID) tuple that uniquely identifies a
 * space vehicle.
 */

namespace Gnss {
    class SvId extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Gnss $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_satId = $this->_io->readU1();
            $this->_m_constellation = $this->_io->readU1();
        }
        protected $_m_satId;
        protected $_m_constellation;

        /**
         * Constellation-specific satellite id. For GLO can either be (100+FCN)
         * where FCN is in [-7,+6] or the Slot ID in [1,28].
         */
        public function satId() { return $this->_m_satId; }

        /**
         * Constellation ID to which the SV belongs
         */
        public function constellation() { return $this->_m_constellation; }
    }
}
