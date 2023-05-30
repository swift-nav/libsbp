<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Sbas extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Sbas $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * This message is sent once per second per SBAS satellite. ME checks the
 * parity of the data block and sends only blocks that pass the check.
 */

namespace Sbas {
    class MsgSbasRaw extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Sbas $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_messageType = $this->_io->readU1();
            $this->_m_data = [];
            $n = 27;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_data[] = $this->_io->readU1();
            }
        }
        protected $_m_sid;
        protected $_m_tow;
        protected $_m_messageType;
        protected $_m_data;

        /**
         * GNSS signal identifier.
         */
        public function sid() { return $this->_m_sid; }

        /**
         * GPS time-of-week at the start of the data block.
         */
        public function tow() { return $this->_m_tow; }

        /**
         * SBAS message type (0-63)
         */
        public function messageType() { return $this->_m_messageType; }

        /**
         * Raw SBAS data field of 212 bits (last byte padded with zeros).
         */
        public function data() { return $this->_m_data; }
    }
}
