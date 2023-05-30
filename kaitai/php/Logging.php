<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Logging extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Logging $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * This message contains a human-readable payload string from the device
 * containing errors, warnings and informational messages at ERROR,
 * WARNING, DEBUG, INFO logging levels.
 */

namespace Logging {
    class MsgLog extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Logging $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_level = $this->_io->readU1();
            $this->_m_text = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_level;
        protected $_m_text;

        /**
         * Logging level
         */
        public function level() { return $this->_m_level; }

        /**
         * Human-readable string
         */
        public function text() { return $this->_m_text; }
    }
}

/**
 * This message provides the ability to forward messages over SBP.  This
 * may take the form of wrapping up SBP messages received by Piksi for
 * logging purposes or wrapping another protocol with SBP.
 * 
 * The source identifier indicates from what interface a forwarded stream
 * derived. The protocol identifier identifies what the expected protocol
 * the forwarded msg contains. Protocol 0 represents SBP and the remaining
 * values are implementation defined.
 */

namespace Logging {
    class MsgFwd extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Logging $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_source = $this->_io->readU1();
            $this->_m_protocol = $this->_io->readU1();
            $this->_m_fwdPayload = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_fwdPayload[] = $this->_io->readU1();
                $i++;
            }
        }
        protected $_m_source;
        protected $_m_protocol;
        protected $_m_fwdPayload;

        /**
         * source identifier
         */
        public function source() { return $this->_m_source; }

        /**
         * protocol identifier
         */
        public function protocol() { return $this->_m_protocol; }

        /**
         * variable length wrapped binary message
         */
        public function fwdPayload() { return $this->_m_fwdPayload; }
    }
}

/**
 * Deprecated.
 */

namespace Logging {
    class MsgPrintDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Logging $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_text = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_text;

        /**
         * Human-readable string
         */
        public function text() { return $this->_m_text; }
    }
}
