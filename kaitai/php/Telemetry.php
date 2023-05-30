<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Telemetry extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Telemetry $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

namespace Telemetry {
    class TelemetrySv extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Telemetry\MsgTelSv $_parent = null, \Telemetry $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_az = $this->_io->readU1();
            $this->_m_el = $this->_io->readS1();
            $this->_m_availabilityFlags = $this->_io->readU1();
            $this->_m_pseudorangeResidual = $this->_io->readS2le();
            $this->_m_phaseResidual = $this->_io->readS2le();
            $this->_m_outlierFlags = $this->_io->readU1();
            $this->_m_ephemerisFlags = $this->_io->readU1();
            $this->_m_correctionFlags = $this->_io->readU1();
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
        }
        protected $_m_az;
        protected $_m_el;
        protected $_m_availabilityFlags;
        protected $_m_pseudorangeResidual;
        protected $_m_phaseResidual;
        protected $_m_outlierFlags;
        protected $_m_ephemerisFlags;
        protected $_m_correctionFlags;
        protected $_m_sid;

        /**
         * Azimuth angle (range 0..179)
         */
        public function az() { return $this->_m_az; }

        /**
         * Elevation angle (range -90..90)
         */
        public function el() { return $this->_m_el; }

        /**
         * Observation availability at filter update
         */
        public function availabilityFlags() { return $this->_m_availabilityFlags; }

        /**
         * Pseudorange observation residual
         */
        public function pseudorangeResidual() { return $this->_m_pseudorangeResidual; }

        /**
         * Carrier-phase or carrier-phase-derived observation residual
         */
        public function phaseResidual() { return $this->_m_phaseResidual; }

        /**
         * Reports if observation is marked as an outlier and is excluded from
         * the update
         */
        public function outlierFlags() { return $this->_m_outlierFlags; }

        /**
         * Ephemeris metadata
         */
        public function ephemerisFlags() { return $this->_m_ephemerisFlags; }

        /**
         * Reserved
         */
        public function correctionFlags() { return $this->_m_correctionFlags; }

        /**
         * GNSS signal identifier (16 bit)
         */
        public function sid() { return $this->_m_sid; }
    }
}

/**
 * This message includes telemetry pertinent to satellite signals available
 * to Starling.
 */

namespace Telemetry {
    class MsgTelSv extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Telemetry $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_wn = $this->_io->readU2le();
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_nObs = $this->_io->readU1();
            $this->_m_originFlags = $this->_io->readU1();
            $this->_m_svTel = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_svTel[] = new \Telemetry\TelemetrySv($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_wn;
        protected $_m_tow;
        protected $_m_nObs;
        protected $_m_originFlags;
        protected $_m_svTel;

        /**
         * GPS week number
         */
        public function wn() { return $this->_m_wn; }

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Total number of observations. First nibble is the size of the
         * sequence (n), second nibble is the zero-indexed counter (ith packet
         * of n)
         */
        public function nObs() { return $this->_m_nObs; }

        /**
         * Flags to identify the filter type from which the telemetry is
         * reported from
         */
        public function originFlags() { return $this->_m_originFlags; }

        /**
         * Array of per-signal telemetry entries
         */
        public function svTel() { return $this->_m_svTel; }
    }
}
