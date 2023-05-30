<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class ExtEvents extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \ExtEvents $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * Reports detection of an external event, the GPS time it occurred, which
 * pin it was and whether it was rising or falling.
 */

namespace ExtEvents {
    class MsgExtEvent extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \ExtEvents $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_wn = $this->_io->readU2le();
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_nsResidual = $this->_io->readS4le();
            $this->_m_flags = $this->_io->readU1();
            $this->_m_pin = $this->_io->readU1();
        }
        protected $_m_wn;
        protected $_m_tow;
        protected $_m_nsResidual;
        protected $_m_flags;
        protected $_m_pin;

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
         * Flags
         */
        public function flags() { return $this->_m_flags; }

        /**
         * Pin number.  0..9 = DEBUG0..9.
         */
        public function pin() { return $this->_m_pin; }
    }
}
