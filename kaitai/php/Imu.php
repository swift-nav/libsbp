<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Imu extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Imu $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * Raw data from the Inertial Measurement Unit, containing accelerometer
 * and gyroscope readings. The sense of the measurements are to be aligned
 * with the indications on the device itself. Measurement units, which are
 * specific to the device hardware and settings, are communicated via the
 * MSG_IMU_AUX message. If using "time since startup" time tags, the
 * receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix
 * becomes available to synchronise IMU measurements with GNSS. The
 * timestamp must wrap around to zero when reaching one week (604800
 * seconds).
 * 
 * The time-tagging mode should not change throughout a run.
 */

namespace Imu {
    class MsgImuRaw extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Imu $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_towF = $this->_io->readU1();
            $this->_m_accX = $this->_io->readS2le();
            $this->_m_accY = $this->_io->readS2le();
            $this->_m_accZ = $this->_io->readS2le();
            $this->_m_gyrX = $this->_io->readS2le();
            $this->_m_gyrY = $this->_io->readS2le();
            $this->_m_gyrZ = $this->_io->readS2le();
        }
        protected $_m_tow;
        protected $_m_towF;
        protected $_m_accX;
        protected $_m_accY;
        protected $_m_accZ;
        protected $_m_gyrX;
        protected $_m_gyrY;
        protected $_m_gyrZ;

        /**
         * Milliseconds since reference epoch and time status.
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Milliseconds since reference epoch, fractional part
         */
        public function towF() { return $this->_m_towF; }

        /**
         * Acceleration in the IMU frame X axis
         */
        public function accX() { return $this->_m_accX; }

        /**
         * Acceleration in the IMU frame Y axis
         */
        public function accY() { return $this->_m_accY; }

        /**
         * Acceleration in the IMU frame Z axis
         */
        public function accZ() { return $this->_m_accZ; }

        /**
         * Angular rate around IMU frame X axis
         */
        public function gyrX() { return $this->_m_gyrX; }

        /**
         * Angular rate around IMU frame Y axis
         */
        public function gyrY() { return $this->_m_gyrY; }

        /**
         * Angular rate around IMU frame Z axis
         */
        public function gyrZ() { return $this->_m_gyrZ; }
    }
}

/**
 * Auxiliary data specific to a particular IMU. The `imu_type` field will
 * always be consistent but the rest of the payload is device specific and
 * depends on the value of `imu_type`.
 */

namespace Imu {
    class MsgImuAux extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Imu $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_imuType = $this->_io->readU1();
            $this->_m_temp = $this->_io->readS2le();
            $this->_m_imuConf = $this->_io->readU1();
        }
        protected $_m_imuType;
        protected $_m_temp;
        protected $_m_imuConf;

        /**
         * IMU type
         */
        public function imuType() { return $this->_m_imuType; }

        /**
         * Raw IMU temperature
         */
        public function temp() { return $this->_m_temp; }

        /**
         * IMU configuration
         */
        public function imuConf() { return $this->_m_imuConf; }
    }
}
