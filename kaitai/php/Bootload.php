<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Bootload extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Bootload $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * The device message from the host reads a unique device identifier from
 * the SwiftNAP, an FPGA. The host requests the ID by sending a
 * MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
 * MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
 * that this ID is tied to the FPGA, and not related to the Piksi's serial
 * number.
 */

namespace Bootload {
    class MsgNapDeviceDnaReq extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Bootload $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * The host initiates the bootloader to jump to the application.
 */

namespace Bootload {
    class MsgBootloaderJumpToApp extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Bootload $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_jump = $this->_io->readU1();
        }
        protected $_m_jump;

        /**
         * Ignored by the device
         */
        public function jump() { return $this->_m_jump; }
    }
}

/**
 * The handshake message response from the device establishes a handshake
 * between the device bootloader and the host. The request from the host is
 * MSG_BOOTLOADER_HANDSHAKE_REQ.  The payload contains the bootloader
 * version number and the SBP protocol version number.
 */

namespace Bootload {
    class MsgBootloaderHandshakeResp extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Bootload $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_flags = $this->_io->readU4le();
            $this->_m_version = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_flags;
        protected $_m_version;

        /**
         * Bootloader flags
         */
        public function flags() { return $this->_m_flags; }

        /**
         * Bootloader version number
         */
        public function version() { return $this->_m_version; }
    }
}

/**
 * The device message from the host reads a unique device identifier from
 * the SwiftNAP, an FPGA. The host requests the ID by sending a
 * MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
 * MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
 * that this ID is tied to the FPGA, and not related to the Piksi's serial
 * number.
 */

namespace Bootload {
    class MsgNapDeviceDnaResp extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Bootload $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_dna = [];
            $n = 8;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_dna[] = $this->_io->readU1();
            }
        }
        protected $_m_dna;

        /**
         * 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the
         * right.
         */
        public function dna() { return $this->_m_dna; }
    }
}

/**
 * The handshake message request from the host establishes a handshake
 * between the device bootloader and the host. The response from the device
 * is MSG_BOOTLOADER_HANDSHAKE_RESP.
 */

namespace Bootload {
    class MsgBootloaderHandshakeReq extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Bootload $_root = null) {
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

namespace Bootload {
    class MsgBootloaderHandshakeDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Bootload $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_handshake = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_handshake[] = $this->_io->readU1();
                $i++;
            }
        }
        protected $_m_handshake;

        /**
         * Version number string (not NULL terminated)
         */
        public function handshake() { return $this->_m_handshake; }
    }
}
