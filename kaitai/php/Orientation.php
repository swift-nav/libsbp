<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Orientation extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Orientation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * This message reports the baseline heading pointing from the base station
 * to the rover relative to True North. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow). It is
 * intended that time-matched RTK mode is used when the base station is
 * moving.
 */

namespace Orientation {
    class MsgBaselineHeading extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Orientation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_heading = $this->_io->readU4le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_heading;
        protected $_m_nSats;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Heading
         */
        public function heading() { return $this->_m_heading; }

        /**
         * Number of satellites used in solution
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the quaternion vector describing the vehicle body
 * frame's orientation with respect to a local-level NED frame. The
 * components of the vector should sum to a unit vector assuming that the
 * LSB of each component as a value of 2^-31. This message will only be
 * available in future INS versions of Swift Products and is not produced
 * by Piksi Multi or Duro.
 */

namespace Orientation {
    class MsgOrientQuat extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Orientation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_w = $this->_io->readS4le();
            $this->_m_x = $this->_io->readS4le();
            $this->_m_y = $this->_io->readS4le();
            $this->_m_z = $this->_io->readS4le();
            $this->_m_wAccuracy = $this->_io->readF4le();
            $this->_m_xAccuracy = $this->_io->readF4le();
            $this->_m_yAccuracy = $this->_io->readF4le();
            $this->_m_zAccuracy = $this->_io->readF4le();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_w;
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;
        protected $_m_wAccuracy;
        protected $_m_xAccuracy;
        protected $_m_yAccuracy;
        protected $_m_zAccuracy;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Real component
         */
        public function w() { return $this->_m_w; }

        /**
         * 1st imaginary component
         */
        public function x() { return $this->_m_x; }

        /**
         * 2nd imaginary component
         */
        public function y() { return $this->_m_y; }

        /**
         * 3rd imaginary component
         */
        public function z() { return $this->_m_z; }

        /**
         * Estimated standard deviation of w
         */
        public function wAccuracy() { return $this->_m_wAccuracy; }

        /**
         * Estimated standard deviation of x
         */
        public function xAccuracy() { return $this->_m_xAccuracy; }

        /**
         * Estimated standard deviation of y
         */
        public function yAccuracy() { return $this->_m_yAccuracy; }

        /**
         * Estimated standard deviation of z
         */
        public function zAccuracy() { return $this->_m_zAccuracy; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the yaw, pitch, and roll angles of the vehicle body
 * frame. The rotations should applied intrinsically in the order yaw,
 * pitch, and roll in order to rotate the from a frame aligned with the
 * local-level NED frame to the vehicle body frame.  This message will only
 * be available in future INS versions of Swift Products and is not
 * produced by Piksi Multi or Duro.
 */

namespace Orientation {
    class MsgOrientEuler extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Orientation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_roll = $this->_io->readS4le();
            $this->_m_pitch = $this->_io->readS4le();
            $this->_m_yaw = $this->_io->readS4le();
            $this->_m_rollAccuracy = $this->_io->readF4le();
            $this->_m_pitchAccuracy = $this->_io->readF4le();
            $this->_m_yawAccuracy = $this->_io->readF4le();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_roll;
        protected $_m_pitch;
        protected $_m_yaw;
        protected $_m_rollAccuracy;
        protected $_m_pitchAccuracy;
        protected $_m_yawAccuracy;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * rotation about the forward axis of the vehicle
         */
        public function roll() { return $this->_m_roll; }

        /**
         * rotation about the rightward axis of the vehicle
         */
        public function pitch() { return $this->_m_pitch; }

        /**
         * rotation about the downward axis of the vehicle
         */
        public function yaw() { return $this->_m_yaw; }

        /**
         * Estimated standard deviation of roll
         */
        public function rollAccuracy() { return $this->_m_rollAccuracy; }

        /**
         * Estimated standard deviation of pitch
         */
        public function pitchAccuracy() { return $this->_m_pitchAccuracy; }

        /**
         * Estimated standard deviation of yaw
         */
        public function yawAccuracy() { return $this->_m_yawAccuracy; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message reports the orientation rates in the vehicle body frame.
 * The values represent the measurements a strapped down gyroscope would
 * make and are not equivalent to the time derivative of the Euler angles.
 * The orientation and origin of the user frame is specified via device
 * settings. By convention, the vehicle x-axis is expected to be aligned
 * with the forward direction, while the vehicle y-axis is expected to be
 * aligned with the right direction, and the vehicle z-axis should be
 * aligned with the down direction. This message will only be available in
 * future INS versions of Swift Products and is not produced by Piksi Multi
 * or Duro.
 */

namespace Orientation {
    class MsgAngularRate extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Orientation $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_x = $this->_io->readS4le();
            $this->_m_y = $this->_io->readS4le();
            $this->_m_z = $this->_io->readS4le();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_x;
        protected $_m_y;
        protected $_m_z;
        protected $_m_flags;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * angular rate about x axis
         */
        public function x() { return $this->_m_x; }

        /**
         * angular rate about y axis
         */
        public function y() { return $this->_m_y; }

        /**
         * angular rate about z axis
         */
        public function z() { return $this->_m_z; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}
