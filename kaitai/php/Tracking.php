<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Tracking extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Tracking $_root = null) {
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

namespace Tracking {
    class MsgTrackingStateDetailedDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Tracking $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_recvTime = $this->_io->readU8le();
            $this->_m_tot = new \Gnss\GpsTimeDep($this->_io, $this, $this->_root);
            $this->_m_p = $this->_io->readU4le();
            $this->_m_pStd = $this->_io->readU2le();
            $this->_m_l = new \Gnss\CarrierPhase($this->_io, $this, $this->_root);
            $this->_m_cn0 = $this->_io->readU1();
            $this->_m_lock = $this->_io->readU2le();
            $this->_m_sid = new \Gnss\GnssSignalDep($this->_io, $this, $this->_root);
            $this->_m_doppler = $this->_io->readS4le();
            $this->_m_dopplerStd = $this->_io->readU2le();
            $this->_m_uptime = $this->_io->readU4le();
            $this->_m_clockOffset = $this->_io->readS2le();
            $this->_m_clockDrift = $this->_io->readS2le();
            $this->_m_corrSpacing = $this->_io->readU2le();
            $this->_m_acceleration = $this->_io->readS1();
            $this->_m_syncFlags = $this->_io->readU1();
            $this->_m_towFlags = $this->_io->readU1();
            $this->_m_trackFlags = $this->_io->readU1();
            $this->_m_navFlags = $this->_io->readU1();
            $this->_m_psetFlags = $this->_io->readU1();
            $this->_m_miscFlags = $this->_io->readU1();
        }
        protected $_m_recvTime;
        protected $_m_tot;
        protected $_m_p;
        protected $_m_pStd;
        protected $_m_l;
        protected $_m_cn0;
        protected $_m_lock;
        protected $_m_sid;
        protected $_m_doppler;
        protected $_m_dopplerStd;
        protected $_m_uptime;
        protected $_m_clockOffset;
        protected $_m_clockDrift;
        protected $_m_corrSpacing;
        protected $_m_acceleration;
        protected $_m_syncFlags;
        protected $_m_towFlags;
        protected $_m_trackFlags;
        protected $_m_navFlags;
        protected $_m_psetFlags;
        protected $_m_miscFlags;

        /**
         * Receiver clock time.
         */
        public function recvTime() { return $this->_m_recvTime; }

        /**
         * Time of transmission of signal from satellite. TOW only valid when
         * TOW status is decoded or propagated. WN only valid when week number
         * valid flag is set.
         */
        public function tot() { return $this->_m_tot; }

        /**
         * Pseudorange observation. Valid only when pseudorange valid flag is
         * set.
         */
        public function p() { return $this->_m_p; }

        /**
         * Pseudorange observation standard deviation. Valid only when
         * pseudorange valid flag is set.
         */
        public function pStd() { return $this->_m_pStd; }

        /**
         * Carrier phase observation with typical sign convention. Valid only
         * when PLL pessimistic lock is achieved.
         */
        public function l() { return $this->_m_l; }

        /**
         * Carrier-to-Noise density
         */
        public function cn0() { return $this->_m_cn0; }

        /**
         * Lock time. It is encoded according to DF402 from the RTCM 10403.2
         * Amendment 2 specification. Valid values range from 0 to 15.
         */
        public function lock() { return $this->_m_lock; }

        /**
         * GNSS signal identifier.
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Carrier Doppler frequency.
         */
        public function doppler() { return $this->_m_doppler; }

        /**
         * Carrier Doppler frequency standard deviation.
         */
        public function dopplerStd() { return $this->_m_dopplerStd; }

        /**
         * Number of seconds of continuous tracking. Specifies how much time
         * signal is in continuous track.
         */
        public function uptime() { return $this->_m_uptime; }

        /**
         * TCXO clock offset. Valid only when valid clock valid flag is set.
         */
        public function clockOffset() { return $this->_m_clockOffset; }

        /**
         * TCXO clock drift. Valid only when valid clock valid flag is set.
         */
        public function clockDrift() { return $this->_m_clockDrift; }

        /**
         * Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
         */
        public function corrSpacing() { return $this->_m_corrSpacing; }

        /**
         * Acceleration. Valid only when acceleration valid flag is set.
         */
        public function acceleration() { return $this->_m_acceleration; }

        /**
         * Synchronization status flags.
         */
        public function syncFlags() { return $this->_m_syncFlags; }

        /**
         * TOW status flags.
         */
        public function towFlags() { return $this->_m_towFlags; }

        /**
         * Tracking loop status flags.
         */
        public function trackFlags() { return $this->_m_trackFlags; }

        /**
         * Navigation data status flags.
         */
        public function navFlags() { return $this->_m_navFlags; }

        /**
         * Parameters sets flags.
         */
        public function psetFlags() { return $this->_m_psetFlags; }

        /**
         * Miscellaneous flags.
         */
        public function miscFlags() { return $this->_m_miscFlags; }
    }
}

/**
 * Deprecated.
 */

namespace Tracking {
    class TrackingChannelStateDepB extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Tracking\MsgTrackingStateDepB $_parent = null, \Tracking $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_state = $this->_io->readU1();
            $this->_m_sid = new \Gnss\GnssSignalDep($this->_io, $this, $this->_root);
            $this->_m_cn0 = $this->_io->readF4le();
        }
        protected $_m_state;
        protected $_m_sid;
        protected $_m_cn0;

        /**
         * Status of tracking channel
         */
        public function state() { return $this->_m_state; }

        /**
         * GNSS signal being tracked
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Carrier-to-noise density
         */
        public function cn0() { return $this->_m_cn0; }
    }
}

/**
 * Tracking channel state for a specific satellite signal and measured
 * signal power.
 */

namespace Tracking {
    class TrackingChannelState extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Tracking\MsgTrackingState $_parent = null, \Tracking $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_fcn = $this->_io->readU1();
            $this->_m_cn0 = $this->_io->readU1();
        }
        protected $_m_sid;
        protected $_m_fcn;
        protected $_m_cn0;

        /**
         * GNSS signal being tracked
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Frequency channel number (GLONASS only)
         */
        public function fcn() { return $this->_m_fcn; }

        /**
         * Carrier-to-Noise density.  Zero implies invalid cn0.
         */
        public function cn0() { return $this->_m_cn0; }
    }
}

/**
 * The tracking message returns a variable-length array of tracking channel
 * states. It reports status and carrier-to-noise density measurements for
 * all tracked satellites.
 */

namespace Tracking {
    class MsgTrackingState extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Tracking $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_states = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_states[] = new \Tracking\TrackingChannelState($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_states;

        /**
         * Signal tracking channel state
         */
        public function states() { return $this->_m_states; }
    }
}

/**
 * Deprecated.
 */

namespace Tracking {
    class TrackingChannelStateDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Tracking\MsgTrackingStateDepA $_parent = null, \Tracking $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_state = $this->_io->readU1();
            $this->_m_prn = $this->_io->readU1();
            $this->_m_cn0 = $this->_io->readF4le();
        }
        protected $_m_state;
        protected $_m_prn;
        protected $_m_cn0;

        /**
         * Status of tracking channel
         */
        public function state() { return $this->_m_state; }

        /**
         * PRN-1 being tracked
         */
        public function prn() { return $this->_m_prn; }

        /**
         * Carrier-to-noise density
         */
        public function cn0() { return $this->_m_cn0; }
    }
}

/**
 * Deprecated.
 */

namespace Tracking {
    class MsgTrackingIqDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Tracking $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_channel = $this->_io->readU1();
            $this->_m_sid = new \Gnss\GnssSignalDep($this->_io, $this, $this->_root);
            $this->_m_corrs = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_corrs[] = $this->_io->readU8le();
            }
        }
        protected $_m_channel;
        protected $_m_sid;
        protected $_m_corrs;

        /**
         * Tracking channel of origin
         */
        public function channel() { return $this->_m_channel; }

        /**
         * GNSS signal identifier
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Early, Prompt and Late correlations
         */
        public function corrs() { return $this->_m_corrs; }
    }
}

/**
 * Structure containing in-phase and quadrature correlation components.
 */

namespace Tracking {
    class TrackingChannelCorrelationDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Tracking $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_i = $this->_io->readS4le();
            $this->_m_q = $this->_io->readS4le();
        }
        protected $_m_i;
        protected $_m_q;

        /**
         * In-phase correlation
         */
        public function i() { return $this->_m_i; }

        /**
         * Quadrature correlation
         */
        public function q() { return $this->_m_q; }
    }
}

/**
 * Deprecated.
 */

namespace Tracking {
    class MsgTrackingStateDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Tracking $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_states = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_states[] = new \Tracking\TrackingChannelStateDepA($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_states;

        /**
         * Satellite tracking channel state
         */
        public function states() { return $this->_m_states; }
    }
}

/**
 * The tracking message returns a variable-length array of tracking channel
 * states. It reports status and carrier-to-noise density measurements for
 * all tracked satellites.
 */

namespace Tracking {
    class MsgMeasurementState extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Tracking $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_states = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_states[] = new \Tracking\MeasurementState($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_states;

        /**
         * ME signal tracking channel state
         */
        public function states() { return $this->_m_states; }
    }
}

/**
 * Structure containing in-phase and quadrature correlation components.
 */

namespace Tracking {
    class TrackingChannelCorrelation extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Tracking $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_i = $this->_io->readS2le();
            $this->_m_q = $this->_io->readS2le();
        }
        protected $_m_i;
        protected $_m_q;

        /**
         * In-phase correlation
         */
        public function i() { return $this->_m_i; }

        /**
         * Quadrature correlation
         */
        public function q() { return $this->_m_q; }
    }
}

/**
 * When enabled, a tracking channel can output the correlations at each
 * update interval.
 */

namespace Tracking {
    class MsgTrackingIq extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Tracking $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_channel = $this->_io->readU1();
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_corrs = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_corrs[] = $this->_io->readU8le();
            }
        }
        protected $_m_channel;
        protected $_m_sid;
        protected $_m_corrs;

        /**
         * Tracking channel of origin
         */
        public function channel() { return $this->_m_channel; }

        /**
         * GNSS signal identifier
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Early, Prompt and Late correlations
         */
        public function corrs() { return $this->_m_corrs; }
    }
}

/**
 * The tracking message returns a set tracking channel parameters for a
 * single tracking channel useful for debugging issues.
 */

namespace Tracking {
    class MsgTrackingStateDetailedDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Tracking $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_recvTime = $this->_io->readU8le();
            $this->_m_tot = new \Gnss\GpsTime($this->_io, $this, $this->_root);
            $this->_m_p = $this->_io->readU4le();
            $this->_m_pStd = $this->_io->readU2le();
            $this->_m_l = new \Gnss\CarrierPhase($this->_io, $this, $this->_root);
            $this->_m_cn0 = $this->_io->readU1();
            $this->_m_lock = $this->_io->readU2le();
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_doppler = $this->_io->readS4le();
            $this->_m_dopplerStd = $this->_io->readU2le();
            $this->_m_uptime = $this->_io->readU4le();
            $this->_m_clockOffset = $this->_io->readS2le();
            $this->_m_clockDrift = $this->_io->readS2le();
            $this->_m_corrSpacing = $this->_io->readU2le();
            $this->_m_acceleration = $this->_io->readS1();
            $this->_m_syncFlags = $this->_io->readU1();
            $this->_m_towFlags = $this->_io->readU1();
            $this->_m_trackFlags = $this->_io->readU1();
            $this->_m_navFlags = $this->_io->readU1();
            $this->_m_psetFlags = $this->_io->readU1();
            $this->_m_miscFlags = $this->_io->readU1();
        }
        protected $_m_recvTime;
        protected $_m_tot;
        protected $_m_p;
        protected $_m_pStd;
        protected $_m_l;
        protected $_m_cn0;
        protected $_m_lock;
        protected $_m_sid;
        protected $_m_doppler;
        protected $_m_dopplerStd;
        protected $_m_uptime;
        protected $_m_clockOffset;
        protected $_m_clockDrift;
        protected $_m_corrSpacing;
        protected $_m_acceleration;
        protected $_m_syncFlags;
        protected $_m_towFlags;
        protected $_m_trackFlags;
        protected $_m_navFlags;
        protected $_m_psetFlags;
        protected $_m_miscFlags;

        /**
         * Receiver clock time.
         */
        public function recvTime() { return $this->_m_recvTime; }

        /**
         * Time of transmission of signal from satellite. TOW only valid when
         * TOW status is decoded or propagated. WN only valid when week number
         * valid flag is set.
         */
        public function tot() { return $this->_m_tot; }

        /**
         * Pseudorange observation. Valid only when pseudorange valid flag is
         * set.
         */
        public function p() { return $this->_m_p; }

        /**
         * Pseudorange observation standard deviation. Valid only when
         * pseudorange valid flag is set.
         */
        public function pStd() { return $this->_m_pStd; }

        /**
         * Carrier phase observation with typical sign convention. Valid only
         * when PLL pessimistic lock is achieved.
         */
        public function l() { return $this->_m_l; }

        /**
         * Carrier-to-Noise density
         */
        public function cn0() { return $this->_m_cn0; }

        /**
         * Lock time. It is encoded according to DF402 from the RTCM 10403.2
         * Amendment 2 specification. Valid values range from 0 to 15.
         */
        public function lock() { return $this->_m_lock; }

        /**
         * GNSS signal identifier.
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Carrier Doppler frequency.
         */
        public function doppler() { return $this->_m_doppler; }

        /**
         * Carrier Doppler frequency standard deviation.
         */
        public function dopplerStd() { return $this->_m_dopplerStd; }

        /**
         * Number of seconds of continuous tracking. Specifies how much time
         * signal is in continuous track.
         */
        public function uptime() { return $this->_m_uptime; }

        /**
         * TCXO clock offset. Valid only when valid clock valid flag is set.
         */
        public function clockOffset() { return $this->_m_clockOffset; }

        /**
         * TCXO clock drift. Valid only when valid clock valid flag is set.
         */
        public function clockDrift() { return $this->_m_clockDrift; }

        /**
         * Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
         */
        public function corrSpacing() { return $this->_m_corrSpacing; }

        /**
         * Acceleration. Valid only when acceleration valid flag is set.
         */
        public function acceleration() { return $this->_m_acceleration; }

        /**
         * Synchronization status flags.
         */
        public function syncFlags() { return $this->_m_syncFlags; }

        /**
         * TOW status flags.
         */
        public function towFlags() { return $this->_m_towFlags; }

        /**
         * Tracking loop status flags.
         */
        public function trackFlags() { return $this->_m_trackFlags; }

        /**
         * Navigation data status flags.
         */
        public function navFlags() { return $this->_m_navFlags; }

        /**
         * Parameters sets flags.
         */
        public function psetFlags() { return $this->_m_psetFlags; }

        /**
         * Miscellaneous flags.
         */
        public function miscFlags() { return $this->_m_miscFlags; }
    }
}

/**
 * Deprecated.
 */

namespace Tracking {
    class MsgTrackingStateDepB extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Tracking $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_states = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_states[] = new \Tracking\TrackingChannelStateDepB($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_states;

        /**
         * Signal tracking channel state
         */
        public function states() { return $this->_m_states; }
    }
}

/**
 * Measurement Engine tracking channel state for a specific satellite
 * signal and measured signal power. The mesid field for Glonass can either
 * carry the FCN as 100 + FCN where FCN is in [-7, +6] or the Slot ID (from
 * 1 to 28).
 */

namespace Tracking {
    class MeasurementState extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Tracking\MsgMeasurementState $_parent = null, \Tracking $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_mesid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_cn0 = $this->_io->readU1();
        }
        protected $_m_mesid;
        protected $_m_cn0;

        /**
         * Measurement Engine GNSS signal being tracked (carries either Glonass
         * FCN or SLOT)
         */
        public function mesid() { return $this->_m_mesid; }

        /**
         * Carrier-to-Noise density.  Zero implies invalid cn0.
         */
        public function cn0() { return $this->_m_cn0; }
    }
}

/**
 * When enabled, a tracking channel can output the correlations at each
 * update interval.
 */

namespace Tracking {
    class MsgTrackingIqDepB extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Tracking $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_channel = $this->_io->readU1();
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
            $this->_m_corrs = [];
            $n = 3;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_corrs[] = $this->_io->readU8le();
            }
        }
        protected $_m_channel;
        protected $_m_sid;
        protected $_m_corrs;

        /**
         * Tracking channel of origin
         */
        public function channel() { return $this->_m_channel; }

        /**
         * GNSS signal identifier
         */
        public function sid() { return $this->_m_sid; }

        /**
         * Early, Prompt and Late correlations
         */
        public function corrs() { return $this->_m_corrs; }
    }
}
