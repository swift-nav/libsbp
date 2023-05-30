<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Acquisition extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Acquisition $_root = null) {
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

namespace Acquisition {
    class MsgAcqResultDepC extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Acquisition $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_cn0 = $this->_io->readF4le();
            $this->_m_cp = $this->_io->readF4le();
            $this->_m_cf = $this->_io->readF4le();
            $this->_m_sid = new \Gnss\GnssSignalDep($this->_io, $this, $this->_root);
        }
        protected $_m_cn0;
        protected $_m_cp;
        protected $_m_cf;
        protected $_m_sid;

        /**
         * CN/0 of best point
         */
        public function cn0() { return $this->_m_cn0; }

        /**
         * Code phase of best point
         */
        public function cp() { return $this->_m_cp; }

        /**
         * Carrier frequency of best point
         */
        public function cf() { return $this->_m_cf; }

        /**
         * GNSS signal for which acquisition was attempted
         */
        public function sid() { return $this->_m_sid; }
    }
}

/**
 * Deprecated.
 */

namespace Acquisition {
    class MsgAcqResultDepB extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Acquisition $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_snr = $this->_io->readF4le();
            $this->_m_cp = $this->_io->readF4le();
            $this->_m_cf = $this->_io->readF4le();
            $this->_m_sid = new \Gnss\GnssSignalDep($this->_io, $this, $this->_root);
        }
        protected $_m_snr;
        protected $_m_cp;
        protected $_m_cf;
        protected $_m_sid;

        /**
         * SNR of best point. Currently in arbitrary SNR points, but will be in
         * units of dB Hz in a later revision of this message.
         */
        public function snr() { return $this->_m_snr; }

        /**
         * Code phase of best point
         */
        public function cp() { return $this->_m_cp; }

        /**
         * Carrier frequency of best point
         */
        public function cf() { return $this->_m_cf; }

        /**
         * GNSS signal for which acquisition was attempted
         */
        public function sid() { return $this->_m_sid; }
    }
}

/**
 * Profile for a specific SV for debugging purposes. The message describes
 * SV profile during acquisition time. The message is used to debug and
 * measure the performance.
 */

namespace Acquisition {
    class AcqSvProfile extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Acquisition\MsgAcqSvProfile $_parent = null, \Acquisition $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_jobType = $this->_io->readU1();
            $this->_m_status = $this->_io->readU1();
            $this->_m_cn0 = $this->_io->readU2le();
            $this->_m_intTime = $this->_io->readU1();
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_binWidth = $this->_io->readU2le();
            $this->_m_timestamp = $this->_io->readU4le();
            $this->_m_timeSpent = $this->_io->readU4le();
            $this->_m_cfMin = $this->_io->readS4le();
            $this->_m_cfMax = $this->_io->readS4le();
            $this->_m_cf = $this->_io->readS4le();
            $this->_m_cp = $this->_io->readU4le();
        }
        protected $_m_jobType;
        protected $_m_status;
        protected $_m_cn0;
        protected $_m_intTime;
        protected $_m_sid;
        protected $_m_binWidth;
        protected $_m_timestamp;
        protected $_m_timeSpent;
        protected $_m_cfMin;
        protected $_m_cfMax;
        protected $_m_cf;
        protected $_m_cp;

        /**
         * SV search job type (deep, fallback, etc)
         */
        public function jobType() { return $this->_m_jobType; }

        /**
         * Acquisition status 1 is Success, 0 is Failure
         */
        public function status() { return $this->_m_status; }

        /**
         * CN0 value. Only valid if status is '1'
         */
        public function cn0() { return $this->_m_cn0; }

        /**
         * Acquisition integration time
         */
        public function intTime() { return $this->_m_intTime; }

        /**
         * GNSS signal for which acquisition was attempted
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Acq frequency bin width
         */
        public function binWidth() { return $this->_m_binWidth; }

        /**
         * Timestamp of the job complete event
         */
        public function timestamp() { return $this->_m_timestamp; }

        /**
         * Time spent to search for sid.code
         */
        public function timeSpent() { return $this->_m_timeSpent; }

        /**
         * Doppler range lowest frequency
         */
        public function cfMin() { return $this->_m_cfMin; }

        /**
         * Doppler range highest frequency
         */
        public function cfMax() { return $this->_m_cfMax; }

        /**
         * Doppler value of detected peak. Only valid if status is '1'
         */
        public function cf() { return $this->_m_cf; }

        /**
         * Codephase of detected peak. Only valid if status is '1'
         */
        public function cp() { return $this->_m_cp; }
    }
}

/**
 * The message describes all SV profiles during acquisition time. The
 * message is used to debug and measure the performance.
 */

namespace Acquisition {
    class MsgAcqSvProfile extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Acquisition $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_acqSvProfile = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_acqSvProfile[] = new \Acquisition\AcqSvProfile($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_acqSvProfile;

        /**
         * SV profiles during acquisition time
         */
        public function acqSvProfile() { return $this->_m_acqSvProfile; }
    }
}

/**
 * Deprecated.
 */

namespace Acquisition {
    class AcqSvProfileDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Acquisition\MsgAcqSvProfileDep $_parent = null, \Acquisition $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_jobType = $this->_io->readU1();
            $this->_m_status = $this->_io->readU1();
            $this->_m_cn0 = $this->_io->readU2le();
            $this->_m_intTime = $this->_io->readU1();
            $this->_m_sid = new \Gnss\GnssSignalDep($this->_io, $this, $this->_root);
            $this->_m_binWidth = $this->_io->readU2le();
            $this->_m_timestamp = $this->_io->readU4le();
            $this->_m_timeSpent = $this->_io->readU4le();
            $this->_m_cfMin = $this->_io->readS4le();
            $this->_m_cfMax = $this->_io->readS4le();
            $this->_m_cf = $this->_io->readS4le();
            $this->_m_cp = $this->_io->readU4le();
        }
        protected $_m_jobType;
        protected $_m_status;
        protected $_m_cn0;
        protected $_m_intTime;
        protected $_m_sid;
        protected $_m_binWidth;
        protected $_m_timestamp;
        protected $_m_timeSpent;
        protected $_m_cfMin;
        protected $_m_cfMax;
        protected $_m_cf;
        protected $_m_cp;

        /**
         * SV search job type (deep, fallback, etc)
         */
        public function jobType() { return $this->_m_jobType; }

        /**
         * Acquisition status 1 is Success, 0 is Failure
         */
        public function status() { return $this->_m_status; }

        /**
         * CN0 value. Only valid if status is '1'
         */
        public function cn0() { return $this->_m_cn0; }

        /**
         * Acquisition integration time
         */
        public function intTime() { return $this->_m_intTime; }

        /**
         * GNSS signal for which acquisition was attempted
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Acq frequency bin width
         */
        public function binWidth() { return $this->_m_binWidth; }

        /**
         * Timestamp of the job complete event
         */
        public function timestamp() { return $this->_m_timestamp; }

        /**
         * Time spent to search for sid.code
         */
        public function timeSpent() { return $this->_m_timeSpent; }

        /**
         * Doppler range lowest frequency
         */
        public function cfMin() { return $this->_m_cfMin; }

        /**
         * Doppler range highest frequency
         */
        public function cfMax() { return $this->_m_cfMax; }

        /**
         * Doppler value of detected peak. Only valid if status is '1'
         */
        public function cf() { return $this->_m_cf; }

        /**
         * Codephase of detected peak. Only valid if status is '1'
         */
        public function cp() { return $this->_m_cp; }
    }
}

/**
 * This message describes the results from an attempted GPS signal
 * acquisition search for a satellite PRN over a code phase/carrier
 * frequency range. It contains the parameters of the point in the
 * acquisition search space with the best carrier-to-noise (CN/0) ratio.
 */

namespace Acquisition {
    class MsgAcqResult extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Acquisition $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_cn0 = $this->_io->readF4le();
            $this->_m_cp = $this->_io->readF4le();
            $this->_m_cf = $this->_io->readF4le();
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
        }
        protected $_m_cn0;
        protected $_m_cp;
        protected $_m_cf;
        protected $_m_sid;

        /**
         * CN/0 of best point
         */
        public function cn0() { return $this->_m_cn0; }

        /**
         * Code phase of best point
         */
        public function cp() { return $this->_m_cp; }

        /**
         * Carrier frequency of best point
         */
        public function cf() { return $this->_m_cf; }

        /**
         * GNSS signal for which acquisition was attempted
         */
        public function sid() { return $this->_m_sid; }
    }
}

/**
 * Deprecated.
 */

namespace Acquisition {
    class MsgAcqResultDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Acquisition $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_snr = $this->_io->readF4le();
            $this->_m_cp = $this->_io->readF4le();
            $this->_m_cf = $this->_io->readF4le();
            $this->_m_prn = $this->_io->readU1();
        }
        protected $_m_snr;
        protected $_m_cp;
        protected $_m_cf;
        protected $_m_prn;

        /**
         * SNR of best point. Currently dimensionless, but will have units of
         * dB Hz in the revision of this message.
         */
        public function snr() { return $this->_m_snr; }

        /**
         * Code phase of best point
         */
        public function cp() { return $this->_m_cp; }

        /**
         * Carrier frequency of best point
         */
        public function cf() { return $this->_m_cf; }

        /**
         * PRN-1 identifier of the satellite signal for which acquisition was
         * attempted
         */
        public function prn() { return $this->_m_prn; }
    }
}

/**
 * Deprecated.
 */

namespace Acquisition {
    class MsgAcqSvProfileDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Acquisition $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_acqSvProfile = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_acqSvProfile[] = new \Acquisition\AcqSvProfileDep($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_acqSvProfile;

        /**
         * SV profiles during acquisition time
         */
        public function acqSvProfile() { return $this->_m_acqSvProfile; }
    }
}
