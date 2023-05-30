<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class SolutionMeta extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \SolutionMeta $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * Metadata around the GNSS sensors involved in the fuzed solution.
 * Accessible through sol_in[N].flags in a MSG_SOLN_META.
 */

namespace SolutionMeta {
    class GnssInputType extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \SolutionMeta $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_flags;

        /**
         * flags that store all relevant info specific to this sensor type.
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message contains all metadata about the sensors received and/or
 * used in computing the sensorfusion solution. It focuses primarily, but
 * not only, on GNSS metadata. Regarding the age of the last received valid
 * GNSS solution, the highest two bits are time status, indicating whether
 * age gnss can or can not be used to retrieve time of measurement (noted
 * TOM, also known as time of validity) If it can, subtract 'age gnss' from
 * 'tow' in navigation messages to get TOM. Can be used before alignment is
 * complete in the Fusion Engine, when output solution is the last received
 * valid GNSS solution and its tow is not a TOM.
 */

namespace SolutionMeta {
    class MsgSolnMeta extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \SolutionMeta $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_pdop = $this->_io->readU2le();
            $this->_m_hdop = $this->_io->readU2le();
            $this->_m_vdop = $this->_io->readU2le();
            $this->_m_ageCorrections = $this->_io->readU2le();
            $this->_m_ageGnss = $this->_io->readU4le();
            $this->_m_solIn = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_solIn[] = new \SolutionMeta\SolutionInputType($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_tow;
        protected $_m_pdop;
        protected $_m_hdop;
        protected $_m_vdop;
        protected $_m_ageCorrections;
        protected $_m_ageGnss;
        protected $_m_solIn;

        /**
         * GPS time of week rounded to the nearest millisecond
         */
        public function tow() { return $this->_m_tow; }

        /**
         * Position Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        public function pdop() { return $this->_m_pdop; }

        /**
         * Horizontal Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        public function hdop() { return $this->_m_hdop; }

        /**
         * Vertical Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        public function vdop() { return $this->_m_vdop; }

        /**
         * Age of corrections as per last available AGE_CORRECTIONS from PVT
         * engine (0xFFFF indicates invalid)
         */
        public function ageCorrections() { return $this->_m_ageCorrections; }

        /**
         * Age and Time Status of the last received valid GNSS solution.
         */
        public function ageGnss() { return $this->_m_ageGnss; }

        /**
         * Array of Metadata describing the sensors potentially involved in the
         * solution. Each element in the array represents a single sensor type
         * and consists of flags containing (meta)data pertaining to that
         * specific single sensor. Refer to each (XX)InputType descriptor in
         * the present doc.
         */
        public function solIn() { return $this->_m_solIn; }
    }
}

/**
 * Deprecated.
 * 
 * This message contains all metadata about the sensors received and/or
 * used in computing the Fuzed Solution. It focuses primarily, but not
 * only, on GNSS metadata.
 */

namespace SolutionMeta {
    class MsgSolnMetaDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \SolutionMeta $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_pdop = $this->_io->readU2le();
            $this->_m_hdop = $this->_io->readU2le();
            $this->_m_vdop = $this->_io->readU2le();
            $this->_m_nSats = $this->_io->readU1();
            $this->_m_ageCorrections = $this->_io->readU2le();
            $this->_m_alignmentStatus = $this->_io->readU1();
            $this->_m_lastUsedGnssPosTow = $this->_io->readU4le();
            $this->_m_lastUsedGnssVelTow = $this->_io->readU4le();
            $this->_m_solIn = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_solIn[] = new \SolutionMeta\SolutionInputType($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_pdop;
        protected $_m_hdop;
        protected $_m_vdop;
        protected $_m_nSats;
        protected $_m_ageCorrections;
        protected $_m_alignmentStatus;
        protected $_m_lastUsedGnssPosTow;
        protected $_m_lastUsedGnssVelTow;
        protected $_m_solIn;

        /**
         * Position Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        public function pdop() { return $this->_m_pdop; }

        /**
         * Horizontal Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        public function hdop() { return $this->_m_hdop; }

        /**
         * Vertical Dilution of Precision as per last available DOPS from PVT
         * engine (0xFFFF indicates invalid)
         */
        public function vdop() { return $this->_m_vdop; }

        /**
         * Number of satellites as per last available solution from PVT engine
         */
        public function nSats() { return $this->_m_nSats; }

        /**
         * Age of corrections as per last available AGE_CORRECTIONS from PVT
         * engine (0xFFFF indicates invalid)
         */
        public function ageCorrections() { return $this->_m_ageCorrections; }

        /**
         * State of alignment and the status and receipt of the alignment
         * inputs
         */
        public function alignmentStatus() { return $this->_m_alignmentStatus; }

        /**
         * Tow of last-used GNSS position measurement
         */
        public function lastUsedGnssPosTow() { return $this->_m_lastUsedGnssPosTow; }

        /**
         * Tow of last-used GNSS velocity measurement
         */
        public function lastUsedGnssVelTow() { return $this->_m_lastUsedGnssVelTow; }

        /**
         * Array of Metadata describing the sensors potentially involved in the
         * solution. Each element in the array represents a single sensor type
         * and consists of flags containing (meta)data pertaining to that
         * specific single sensor. Refer to each (XX)InputType descriptor in
         * the present doc.
         */
        public function solIn() { return $this->_m_solIn; }
    }
}

/**
 * Metadata around the IMU sensors involved in the fuzed solution.
 * Accessible through sol_in[N].flags in a MSG_SOLN_META.
 */

namespace SolutionMeta {
    class ImuInputType extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \SolutionMeta $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_flags;

        /**
         * Instrument time, grade, and architecture for a sensor.
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * Metadata around the Odometry sensors involved in the fuzed solution.
 * Accessible through sol_in[N].flags in a MSG_SOLN_META.
 */

namespace SolutionMeta {
    class OdoInputType extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \SolutionMeta $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_flags;

        /**
         * Instrument ODO rate, grade, and quality.
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * Metadata describing which sensors were involved in the solution. The
 * structure is fixed no matter what the actual sensor type is. The
 * sensor_type field tells you which sensor we are talking about. It also
 * tells you whether the sensor data was actually used or not. The flags
 * field, always a u8, contains the sensor-specific data. The content of
 * flags, for each sensor type, is described in the relevant structures in
 * this section.
 */

namespace SolutionMeta {
    class SolutionInputType extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \SolutionMeta $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sensorType = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_sensorType;
        protected $_m_flags;

        /**
         * The type of sensor
         */
        public function sensorType() { return $this->_m_sensorType; }

        /**
         * Refer to each InputType description
         */
        public function flags() { return $this->_m_flags; }
    }
}
