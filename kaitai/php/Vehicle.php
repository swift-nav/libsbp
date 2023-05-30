<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Vehicle extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Vehicle $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * Message representing the x component of vehicle velocity in the user
 * frame at the odometry reference point(s) specified by the user. The
 * offset for the odometry reference point and the definition and origin of
 * the user frame are defined through the device settings interface. There
 * are 4 possible user-defined sources of this message which are labeled
 * arbitrarily source 0 through 3. If using "processor time" time tags, the
 * receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix
 * becomes available to synchronise odometry measurements with GNSS.
 * Processor time shall roll over to zero after one week.
 */

namespace Vehicle {
    class MsgOdometry extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Vehicle $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_velocity = $this->_io->readS4le();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_velocity;
        protected $_m_flags;

        /**
         * Time field representing either milliseconds in the GPS Week or local
         * CPU time from the producing system in milliseconds.  See the
         * tow_source flag for the exact source of this timestamp.
         */
        public function tow() { return $this->_m_tow; }

        /**
         * The signed forward component of vehicle velocity.
         */
        public function velocity() { return $this->_m_velocity; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * Message containing the accumulated distance travelled by a wheel located
 * at an odometry reference point defined by the user. The offset for the
 * odometry reference point and the definition and origin of the user frame
 * are defined through the device settings interface. The source of this
 * message is identified by the source field, which is an integer ranging
 * from 0 to 255. The timestamp associated with this message should
 * represent the time when the accumulated tick count reached the value
 * given by the contents of this message as accurately as possible. If
 * using "local CPU time" time tags, the receiving end will expect a
 * `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to synchronise
 * wheeltick measurements with GNSS. Local CPU time shall roll over to zero
 * after one week.
 */

namespace Vehicle {
    class MsgWheeltick extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Vehicle $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_time = $this->_io->readU8le();
            $this->_m_flags = $this->_io->readU1();
            $this->_m_source = $this->_io->readU1();
            $this->_m_ticks = $this->_io->readS4le();
        }
        protected $_m_time;
        protected $_m_flags;
        protected $_m_source;
        protected $_m_ticks;

        /**
         * Time field representing either microseconds since the last PPS,
         * microseconds in the GPS Week or local CPU time from the producing
         * system in microseconds. See the synch_type field for the exact
         * meaning of this timestamp.
         */
        public function time() { return $this->_m_time; }

        /**
         * Field indicating the type of timestamp contained in the time field.
         */
        public function flags() { return $this->_m_flags; }

        /**
         * ID of the sensor producing this message
         */
        public function source() { return $this->_m_source; }

        /**
         * Free-running counter of the accumulated distance for this sensor.
         * The counter should be incrementing if travelling into one direction
         * and decrementing when travelling in the opposite direction.
         */
        public function ticks() { return $this->_m_ticks; }
    }
}
