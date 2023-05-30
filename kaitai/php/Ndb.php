<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Ndb extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Ndb $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * This message is sent out when an object is stored into NDB. If needed
 * message could also be sent out when fetching an object from NDB.
 */

namespace Ndb {
    class MsgNdbEvent extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Ndb $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_recvTime = $this->_io->readU8le();
            $this->_m_event = $this->_io->readU1();
            $this->_m_objectType = $this->_io->readU1();
            $this->_m_result = $this->_io->readU1();
            $this->_m_dataSource = $this->_io->readU1();
            $this->_m_objectSid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_srcSid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_originalSender = $this->_io->readU2le();
        }
        protected $_m_recvTime;
        protected $_m_event;
        protected $_m_objectType;
        protected $_m_result;
        protected $_m_dataSource;
        protected $_m_objectSid;
        protected $_m_srcSid;
        protected $_m_originalSender;

        /**
         * HW time in milliseconds.
         */
        public function recvTime() { return $this->_m_recvTime; }

        /**
         * Event type.
         */
        public function event() { return $this->_m_event; }

        /**
         * Event object type.
         */
        public function objectType() { return $this->_m_objectType; }

        /**
         * Event result.
         */
        public function result() { return $this->_m_result; }

        /**
         * Data source for STORE event, reserved for other events.
         */
        public function dataSource() { return $this->_m_dataSource; }

        /**
         * GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid
         * indicates for which signal the object belongs to. Reserved in other
         * cases.
         */
        public function objectSid() { return $this->_m_objectSid; }

        /**
         * GNSS signal identifier, If object_type is Almanac, Almanac WN, Iono
         * OR L2C capabilities AND data_source is NDB_DS_RECEIVER sid indicates
         * from which SV data was decoded. Reserved in other cases.
         */
        public function srcSid() { return $this->_m_srcSid; }

        /**
         * A unique identifier of the sending hardware. For v1.0, set to the 2
         * least significant bytes of the device serial number, valid only if
         * data_source is NDB_DS_SBP. Reserved in case of other data_source.
         */
        public function originalSender() { return $this->_m_originalSender; }
    }
}
