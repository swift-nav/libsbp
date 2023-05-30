<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Flash extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Flash $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * This message defines success or failure codes for a variety of flash
 * memory requests from the host to the device. Flash read and write
 * messages, such as MSG_FLASH_READ_REQ, or MSG_FLASH_PROGRAM, may return
 * this message on failure.
 */

namespace Flash {
    class MsgFlashDone extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Flash $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_response = $this->_io->readU1();
        }
        protected $_m_response;

        /**
         * Response flags
         */
        public function response() { return $this->_m_response; }
    }
}

/**
 * The flash status message writes to the 8-bit M25 flash status register.
 * The device replies with a MSG_FLASH_DONE message.
 */

namespace Flash {
    class MsgM25FlashWriteStatus extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Flash $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_status = [];
            $n = 1;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_status[] = $this->_io->readU1();
            }
        }
        protected $_m_status;

        /**
         * Byte to write to the M25 flash status register
         */
        public function status() { return $this->_m_status; }
    }
}

/**
 * The flash read message reads a set of addresses of either the STM or M25
 * onboard flash. The device replies with a MSG_FLASH_READ_RESP message
 * containing either the read data on success or a MSG_FLASH_DONE message
 * containing the return code FLASH_INVALID_LEN (2) if the maximum read
 * size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
 * the allowed range.
 */

namespace Flash {
    class MsgFlashReadResp extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Flash $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_target = $this->_io->readU1();
            $this->_m_addrStart = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_addrStart[] = $this->_io->readU1();
            }
            $this->_m_addrLen = $this->_io->readU1();
        }
        protected $_m_target;
        protected $_m_addrStart;
        protected $_m_addrLen;

        /**
         * Target flags
         */
        public function target() { return $this->_m_target; }

        /**
         * Starting address offset to read from
         */
        public function addrStart() { return $this->_m_addrStart; }

        /**
         * Length of set of addresses to read, counting up from starting
         * address
         */
        public function addrLen() { return $this->_m_addrLen; }
    }
}

/**
 * The flash erase message from the host erases a sector of either the STM
 * or M25 onboard flash memory. The device will reply with a MSG_FLASH_DONE
 * message containing the return code - FLASH_OK (0) on success or
 * FLASH_INVALID_FLASH (1) if the flash specified is invalid.
 */

namespace Flash {
    class MsgFlashErase extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Flash $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_target = $this->_io->readU1();
            $this->_m_sectorNum = $this->_io->readU4le();
        }
        protected $_m_target;
        protected $_m_sectorNum;

        /**
         * Target flags
         */
        public function target() { return $this->_m_target; }

        /**
         * Flash sector number to erase (0-11 for the STM, 0-15 for the M25)
         */
        public function sectorNum() { return $this->_m_sectorNum; }
    }
}

/**
 * This message reads the device's hard-coded unique ID. The host requests
 * the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
 * MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
 */

namespace Flash {
    class MsgStmUniqueIdResp extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Flash $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_stmId = [];
            $n = 12;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_stmId[] = $this->_io->readU1();
            }
        }
        protected $_m_stmId;

        /**
         * Device unique ID
         */
        public function stmId() { return $this->_m_stmId; }
    }
}

/**
 * This message reads the device's hard-coded unique ID. The host requests
 * the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
 * MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
 */

namespace Flash {
    class MsgStmUniqueIdReq extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Flash $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * The flash program message programs a set of addresses of either the STM
 * or M25 flash. The device replies with either a MSG_FLASH_DONE message
 * containing the return code FLASH_OK (0) on success, or FLASH_INVALID_LEN
 * (2) if the maximum write size is exceeded. Note that the sector-
 * containing addresses must be erased before addresses can be programmed.
 */

namespace Flash {
    class MsgFlashProgram extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Flash $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_target = $this->_io->readU1();
            $this->_m_addrStart = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_addrStart[] = $this->_io->readU1();
            }
            $this->_m_addrLen = $this->_io->readU1();
            $this->_m_data = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_data[] = $this->_io->readU1();
                $i++;
            }
        }
        protected $_m_target;
        protected $_m_addrStart;
        protected $_m_addrLen;
        protected $_m_data;

        /**
         * Target flags
         */
        public function target() { return $this->_m_target; }

        /**
         * Starting address offset to program
         */
        public function addrStart() { return $this->_m_addrStart; }

        /**
         * Length of set of addresses to program, counting up from starting
         * address
         */
        public function addrLen() { return $this->_m_addrLen; }

        /**
         * Data to program addresses with, with length N=addr_len
         */
        public function data() { return $this->_m_data; }
    }
}

/**
 * The flash read message reads a set of addresses of either the STM or M25
 * onboard flash. The device replies with a MSG_FLASH_READ_RESP message
 * containing either the read data on success or a MSG_FLASH_DONE message
 * containing the return code FLASH_INVALID_LEN (2) if the maximum read
 * size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
 * the allowed range.
 */

namespace Flash {
    class MsgFlashReadReq extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Flash $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_target = $this->_io->readU1();
            $this->_m_addrStart = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_addrStart[] = $this->_io->readU1();
            }
            $this->_m_addrLen = $this->_io->readU1();
        }
        protected $_m_target;
        protected $_m_addrStart;
        protected $_m_addrLen;

        /**
         * Target flags
         */
        public function target() { return $this->_m_target; }

        /**
         * Starting address offset to read from
         */
        public function addrStart() { return $this->_m_addrStart; }

        /**
         * Length of set of addresses to read, counting up from starting
         * address
         */
        public function addrLen() { return $this->_m_addrLen; }
    }
}

/**
 * The flash unlock message unlocks a sector of the STM flash memory. The
 * device replies with a MSG_FLASH_DONE message.
 */

namespace Flash {
    class MsgStmFlashUnlockSector extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Flash $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sector = $this->_io->readU4le();
        }
        protected $_m_sector;

        /**
         * Flash sector number to unlock
         */
        public function sector() { return $this->_m_sector; }
    }
}

/**
 * The flash lock message locks a sector of the STM flash memory. The
 * device replies with a MSG_FLASH_DONE message.
 */

namespace Flash {
    class MsgStmFlashLockSector extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Flash $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sector = $this->_io->readU4le();
        }
        protected $_m_sector;

        /**
         * Flash sector number to lock
         */
        public function sector() { return $this->_m_sector; }
    }
}
