<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class System extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \System $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * The heartbeat message is sent periodically to inform the host or other
 * attached devices that the system is running. It is used to monitor
 * system malfunctions. It also contains status flags that indicate to the
 * host the status of the system and whether it is operating correctly.
 * Currently, the expected heartbeat interval is 1 sec.
 * 
 * The system error flag is used to indicate that an error has occurred in
 * the system. To determine the source of the error, the remaining error
 * flags should be inspected.
 */

namespace System {
    class MsgHeartbeat extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \System $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_flags = $this->_io->readU4le();
        }
        protected $_m_flags;

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * The status journal message contains past status reports (see
 * MSG_STATUS_REPORT) and functions as a error/event storage for telemetry
 * purposes.
 */

namespace System {
    class MsgStatusJournal extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \System $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_reportingSystem = $this->_io->readU2le();
            $this->_m_sbpVersion = $this->_io->readU2le();
            $this->_m_totalStatusReports = $this->_io->readU4le();
            $this->_m_sequenceDescriptor = $this->_io->readU1();
            $this->_m_journal = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_journal[] = new \System\StatusJournalItem($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_reportingSystem;
        protected $_m_sbpVersion;
        protected $_m_totalStatusReports;
        protected $_m_sequenceDescriptor;
        protected $_m_journal;

        /**
         * Identity of reporting system
         */
        public function reportingSystem() { return $this->_m_reportingSystem; }

        /**
         * SBP protocol version
         */
        public function sbpVersion() { return $this->_m_sbpVersion; }

        /**
         * Total number of status reports sent since system startup
         */
        public function totalStatusReports() { return $this->_m_totalStatusReports; }

        /**
         * Index and number of messages in this sequence. First nibble is the
         * size of the sequence (n), second nibble is the zero-indexed counter
         * (ith packet of n)
         */
        public function sequenceDescriptor() { return $this->_m_sequenceDescriptor; }

        /**
         * Status journal
         */
        public function journal() { return $this->_m_journal; }
    }
}

/**
 * The INS status message describes the state of the operation and
 * initialization of the inertial navigation system.
 */

namespace System {
    class MsgInsStatus extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \System $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_flags = $this->_io->readU4le();
        }
        protected $_m_flags;

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * The GNSS time offset message contains the information that is needed to
 * translate messages tagged with a local timestamp (e.g. IMU or wheeltick
 * messages) to GNSS time for the sender producing this message.
 */

namespace System {
    class MsgGnssTimeOffset extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \System $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_weeks = $this->_io->readS2le();
            $this->_m_milliseconds = $this->_io->readS4le();
            $this->_m_microseconds = $this->_io->readS2le();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_weeks;
        protected $_m_milliseconds;
        protected $_m_microseconds;
        protected $_m_flags;

        /**
         * Weeks portion of the time offset
         */
        public function weeks() { return $this->_m_weeks; }

        /**
         * Milliseconds portion of the time offset
         */
        public function milliseconds() { return $this->_m_milliseconds; }

        /**
         * Microseconds portion of the time offset
         */
        public function microseconds() { return $this->_m_microseconds; }

        /**
         * Status flags (reserved)
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * The CSAC telemetry message has an implementation defined telemetry
 * string from a device. It is not produced or available on general Swift
 * Products. It is intended to be a low rate message for status purposes.
 */

namespace System {
    class MsgCsacTelemetry extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \System $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_id = $this->_io->readU1();
            $this->_m_telemetry = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_id;
        protected $_m_telemetry;

        /**
         * Index representing the type of telemetry in use.  It is
         * implementation defined.
         */
        public function id() { return $this->_m_id; }

        /**
         * Comma separated list of values as defined by the index
         */
        public function telemetry() { return $this->_m_telemetry; }
    }
}

/**
 * The PPS time message contains the value of the sender's local time in
 * microseconds at the moment a pulse is detected on the PPS input. This is
 * to be used for syncronisation of sensor data sampled with a local
 * timestamp (e.g. IMU or wheeltick messages) where GNSS time is unknown to
 * the sender.
 * 
 * The local time used to timestamp the PPS pulse must be generated by the
 * same clock which is used to timestamp the IMU/wheel sensor data and
 * should follow the same roll-over rules.  A separate MSG_PPS_TIME message
 * should be sent for each source of sensor data which uses PPS-relative
 * timestamping.  The sender ID for each of these MSG_PPS_TIME messages
 * should match the sender ID of the respective sensor data.
 */

namespace System {
    class MsgPpsTime extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \System $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_time = $this->_io->readU8le();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_time;
        protected $_m_flags;

        /**
         * Local time in microseconds
         */
        public function time() { return $this->_m_time; }

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * The INS update status message contains information about executed and
 * rejected INS updates. This message is expected to be extended in the
 * future as new types of measurements are being added.
 */

namespace System {
    class MsgInsUpdates extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \System $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_tow = $this->_io->readU4le();
            $this->_m_gnsspos = $this->_io->readU1();
            $this->_m_gnssvel = $this->_io->readU1();
            $this->_m_wheelticks = $this->_io->readU1();
            $this->_m_speed = $this->_io->readU1();
            $this->_m_nhc = $this->_io->readU1();
            $this->_m_zerovel = $this->_io->readU1();
        }
        protected $_m_tow;
        protected $_m_gnsspos;
        protected $_m_gnssvel;
        protected $_m_wheelticks;
        protected $_m_speed;
        protected $_m_nhc;
        protected $_m_zerovel;

        /**
         * GPS Time of Week
         */
        public function tow() { return $this->_m_tow; }

        /**
         * GNSS position update status flags
         */
        public function gnsspos() { return $this->_m_gnsspos; }

        /**
         * GNSS velocity update status flags
         */
        public function gnssvel() { return $this->_m_gnssvel; }

        /**
         * Wheelticks update status flags
         */
        public function wheelticks() { return $this->_m_wheelticks; }

        /**
         * Wheelticks update status flags
         */
        public function speed() { return $this->_m_speed; }

        /**
         * NHC update status flags
         */
        public function nhc() { return $this->_m_nhc; }

        /**
         * Zero velocity update status flags
         */
        public function zerovel() { return $this->_m_zerovel; }
    }
}

/**
 * This message provides information about the receipt of Differential
 * corrections.  It is expected to be sent with each receipt of a complete
 * corrections packet.
 */

namespace System {
    class MsgDgnssStatus extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \System $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_flags = $this->_io->readU1();
            $this->_m_latency = $this->_io->readU2le();
            $this->_m_numSignals = $this->_io->readU1();
            $this->_m_source = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_flags;
        protected $_m_latency;
        protected $_m_numSignals;
        protected $_m_source;

        /**
         * Status flags
         */
        public function flags() { return $this->_m_flags; }

        /**
         * Latency of observation receipt
         */
        public function latency() { return $this->_m_latency; }

        /**
         * Number of signals from base station
         */
        public function numSignals() { return $this->_m_numSignals; }

        /**
         * Corrections source string
         */
        public function source() { return $this->_m_source; }
    }
}

/**
 * The CSAC telemetry message provides labels for each member of the string
 * produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a
 * lower rate than the MSG_CSAC_TELEMETRY.
 */

namespace System {
    class MsgCsacTelemetryLabels extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \System $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_id = $this->_io->readU1();
            $this->_m_telemetryLabels = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_id;
        protected $_m_telemetryLabels;

        /**
         * Index representing the type of telemetry in use.  It is
         * implementation defined.
         */
        public function id() { return $this->_m_id; }

        /**
         * Comma separated list of telemetry field values
         */
        public function telemetryLabels() { return $this->_m_telemetryLabels; }
    }
}

/**
 * The system start-up message is sent once on system start-up. It notifies
 * the host or other attached devices that the system has started and is
 * now ready to respond to commands or configuration requests.
 */

namespace System {
    class MsgStartup extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \System $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_cause = $this->_io->readU1();
            $this->_m_startupType = $this->_io->readU1();
            $this->_m_reserved = $this->_io->readU2le();
        }
        protected $_m_cause;
        protected $_m_startupType;
        protected $_m_reserved;

        /**
         * Cause of startup
         */
        public function cause() { return $this->_m_cause; }

        /**
         * Startup type
         */
        public function startupType() { return $this->_m_startupType; }

        /**
         * Reserved
         */
        public function reserved() { return $this->_m_reserved; }
    }
}

/**
 * This leading message lists the time metadata of the Solution Group. It
 * also lists the atomic contents (i.e. types of messages included) of the
 * Solution Group.
 */

namespace System {
    class MsgGroupMeta extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \System $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_groupId = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU1();
            $this->_m_nGroupMsgs = $this->_io->readU1();
            $this->_m_groupMsgs = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_groupMsgs[] = $this->_io->readU2le();
                $i++;
            }
        }
        protected $_m_groupId;
        protected $_m_flags;
        protected $_m_nGroupMsgs;
        protected $_m_groupMsgs;

        /**
         * Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss
         */
        public function groupId() { return $this->_m_groupId; }

        /**
         * Status flags (reserved)
         */
        public function flags() { return $this->_m_flags; }

        /**
         * Size of list group_msgs
         */
        public function nGroupMsgs() { return $this->_m_nGroupMsgs; }

        /**
         * An in-order list of message types included in the Solution Group,
         * including GROUP_META itself
         */
        public function groupMsgs() { return $this->_m_groupMsgs; }
    }
}

/**
 * This diagnostic message contains state and update status information for
 * all sensors that are being used by the fusion engine. This message will
 * be generated asynchronously to the solution messages and will be emitted
 * anytime a sensor update is being processed.
 */

namespace System {
    class MsgSensorAidEvent extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \System $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_time = $this->_io->readU4le();
            $this->_m_sensorType = $this->_io->readU1();
            $this->_m_sensorId = $this->_io->readU2le();
            $this->_m_sensorState = $this->_io->readU1();
            $this->_m_nAvailableMeas = $this->_io->readU1();
            $this->_m_nAttemptedMeas = $this->_io->readU1();
            $this->_m_nAcceptedMeas = $this->_io->readU1();
            $this->_m_flags = $this->_io->readU4le();
        }
        protected $_m_time;
        protected $_m_sensorType;
        protected $_m_sensorId;
        protected $_m_sensorState;
        protected $_m_nAvailableMeas;
        protected $_m_nAttemptedMeas;
        protected $_m_nAcceptedMeas;
        protected $_m_flags;

        /**
         * Update timestamp in milliseconds.
         */
        public function time() { return $this->_m_time; }

        /**
         * Sensor type
         */
        public function sensorType() { return $this->_m_sensorType; }

        /**
         * Sensor identifier
         */
        public function sensorId() { return $this->_m_sensorId; }

        /**
         * Reserved for future use
         */
        public function sensorState() { return $this->_m_sensorState; }

        /**
         * Number of available measurements in this epoch
         */
        public function nAvailableMeas() { return $this->_m_nAvailableMeas; }

        /**
         * Number of attempted measurements in this epoch
         */
        public function nAttemptedMeas() { return $this->_m_nAttemptedMeas; }

        /**
         * Number of accepted measurements in this epoch
         */
        public function nAcceptedMeas() { return $this->_m_nAcceptedMeas; }

        /**
         * Reserved for future use
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * Report the general and specific state of a subsystem.  If the generic
 * state is reported as initializing, the specific state should be ignored.
 */

namespace System {
    class SubSystemReport extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \System $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_component = $this->_io->readU2le();
            $this->_m_generic = $this->_io->readU1();
            $this->_m_specific = $this->_io->readU1();
        }
        protected $_m_component;
        protected $_m_generic;
        protected $_m_specific;

        /**
         * Identity of reporting subsystem
         */
        public function component() { return $this->_m_component; }

        /**
         * Generic form status report
         */
        public function generic() { return $this->_m_generic; }

        /**
         * Subsystem specific status code
         */
        public function specific() { return $this->_m_specific; }
    }
}

/**
 * The status report is sent periodically to inform the host or other
 * attached devices that the system is running. It is used to monitor
 * system malfunctions. It contains status reports that indicate to the
 * host the status of each subsystem and whether it is operating correctly.
 * 
 * Interpretation of the subsystem specific status code is product
 * dependent, but if the generic status code is initializing, it should be
 * ignored.  Refer to product documentation for details.
 */

namespace System {
    class MsgStatusReport extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \System $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_reportingSystem = $this->_io->readU2le();
            $this->_m_sbpVersion = $this->_io->readU2le();
            $this->_m_sequence = $this->_io->readU4le();
            $this->_m_uptime = $this->_io->readU4le();
            $this->_m_status = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_status[] = new \System\SubSystemReport($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_reportingSystem;
        protected $_m_sbpVersion;
        protected $_m_sequence;
        protected $_m_uptime;
        protected $_m_status;

        /**
         * Identity of reporting system
         */
        public function reportingSystem() { return $this->_m_reportingSystem; }

        /**
         * SBP protocol version
         */
        public function sbpVersion() { return $this->_m_sbpVersion; }

        /**
         * Increments on each status report sent
         */
        public function sequence() { return $this->_m_sequence; }

        /**
         * Number of seconds since system start-up
         */
        public function uptime() { return $this->_m_uptime; }

        /**
         * Reported status of individual subsystems
         */
        public function status() { return $this->_m_status; }
    }
}

/**
 * Reports the uptime and the state of a subsystem via generic and specific
 * status codes.  If the generic state is reported as initializing, the
 * specific state should be ignored.
 */

namespace System {
    class StatusJournalItem extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \System\MsgStatusJournal $_parent = null, \System $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_uptime = $this->_io->readU4le();
            $this->_m_report = new \System\SubSystemReport($this->_io, $this, $this->_root);
        }
        protected $_m_uptime;
        protected $_m_report;

        /**
         * Milliseconds since system startup
         */
        public function uptime() { return $this->_m_uptime; }
        public function report() { return $this->_m_report; }
    }
}
