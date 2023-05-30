<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Mag extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Mag $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * Raw data from the magnetometer.
 */

namespace Mag {
    class MsgMagRaw extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Mag $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_towF = $this->_io->readU1();
            $this->_m_magX = $this->_io->readS2le();
            $this->_m_magY = $this->_io->readS2le();
            $this->_m_magZ = $this->_io->readS2le();
        }
        protected $_m_tow;
        protected $_m_towF;
        protected $_m_magX;
        protected $_m_magY;
        protected $_m_magZ;

        /**
         * Milliseconds since start of GPS week. If the high bit is set, the
         * time is unknown or invalid.
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Milliseconds since start of GPS week, fractional part
         */
        public function towF() { return $this->_m_towF; }

        /**
         * Magnetic field in the body frame X axis
         */
        public function magX() { return $this->_m_magX; }

        /**
         * Magnetic field in the body frame Y axis
         */
        public function magY() { return $this->_m_magY; }

        /**
         * Magnetic field in the body frame Z axis
         */
        public function magZ() { return $this->_m_magZ; }
    }
}
