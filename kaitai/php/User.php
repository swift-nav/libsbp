<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class User extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \User $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * This message can contain any application specific user data up to a
 * maximum length of 255 bytes per message.
 */

namespace User {
    class MsgUserData extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \User $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_contents = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_contents[] = $this->_io->readU1();
                $i++;
            }
        }
        protected $_m_contents;

        /**
         * User data payload
         */
        public function contents() { return $this->_m_contents; }
    }
}
