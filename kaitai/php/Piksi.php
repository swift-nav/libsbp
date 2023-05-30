<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Piksi extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * The state of a network interface on the Piksi. Data is made to reflect
 * output of ifaddrs struct returned by getifaddrs in c.
 */

namespace Piksi {
    class MsgNetworkStateResp extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_ipv4Address = [];
            $n = 4;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_ipv4Address[] = $this->_io->readU1();
            }
            $this->_m_ipv4MaskSize = $this->_io->readU1();
            $this->_m_ipv6Address = [];
            $n = 16;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_ipv6Address[] = $this->_io->readU1();
            }
            $this->_m_ipv6MaskSize = $this->_io->readU1();
            $this->_m_rxBytes = $this->_io->readU4le();
            $this->_m_txBytes = $this->_io->readU4le();
            $this->_m_interfaceName = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
            $this->_m_flags = $this->_io->readU4le();
        }
        protected $_m_ipv4Address;
        protected $_m_ipv4MaskSize;
        protected $_m_ipv6Address;
        protected $_m_ipv6MaskSize;
        protected $_m_rxBytes;
        protected $_m_txBytes;
        protected $_m_interfaceName;
        protected $_m_flags;

        /**
         * IPv4 address (all zero when unavailable)
         */
        public function ipv4Address() { return $this->_m_ipv4Address; }

        /**
         * IPv4 netmask CIDR notation
         */
        public function ipv4MaskSize() { return $this->_m_ipv4MaskSize; }

        /**
         * IPv6 address (all zero when unavailable)
         */
        public function ipv6Address() { return $this->_m_ipv6Address; }

        /**
         * IPv6 netmask CIDR notation
         */
        public function ipv6MaskSize() { return $this->_m_ipv6MaskSize; }

        /**
         * Number of Rx bytes
         */
        public function rxBytes() { return $this->_m_rxBytes; }

        /**
         * Number of Tx bytes
         */
        public function txBytes() { return $this->_m_txBytes; }

        /**
         * Interface Name
         */
        public function interfaceName() { return $this->_m_interfaceName; }

        /**
         * Interface flags from SIOCGIFFLAGS
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * The bandwidth usage for each interface can be reported within this
 * struct and utilize multiple fields to fully specify the type of traffic
 * that is being tracked. As either the interval of collection or the
 * collection time may vary, both a timestamp and period field is provided,
 * though may not necessarily be populated with a value.
 */

namespace Piksi {
    class NetworkUsage extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Piksi\MsgNetworkBandwidthUsage $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_duration = $this->_io->readU8le();
            $this->_m_totalBytes = $this->_io->readU8le();
            $this->_m_rxBytes = $this->_io->readU4le();
            $this->_m_txBytes = $this->_io->readU4le();
            $this->_m_interfaceName = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_duration;
        protected $_m_totalBytes;
        protected $_m_rxBytes;
        protected $_m_txBytes;
        protected $_m_interfaceName;

        /**
         * Duration over which the measurement was collected
         */
        public function duration() { return $this->_m_duration; }

        /**
         * Number of bytes handled in total within period
         */
        public function totalBytes() { return $this->_m_totalBytes; }

        /**
         * Number of bytes transmitted within period
         */
        public function rxBytes() { return $this->_m_rxBytes; }

        /**
         * Number of bytes received within period
         */
        public function txBytes() { return $this->_m_txBytes; }

        /**
         * Interface Name
         */
        public function interfaceName() { return $this->_m_interfaceName; }
    }
}

/**
 * The response to MSG_COMMAND_REQ with the return code of the command.  A
 * return code of zero indicates success.
 */

namespace Piksi {
    class MsgCommandResp extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sequence = $this->_io->readU4le();
            $this->_m_code = $this->_io->readS4le();
        }
        protected $_m_sequence;
        protected $_m_code;

        /**
         * Sequence number
         */
        public function sequence() { return $this->_m_sequence; }

        /**
         * Exit code
         */
        public function code() { return $this->_m_code; }
    }
}

/**
 * Returns the standard output and standard error of the command requested
 * by MSG_COMMAND_REQ. The sequence number can be used to filter for
 * filtering the correct command.
 */

namespace Piksi {
    class MsgCommandOutput extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sequence = $this->_io->readU4le();
            $this->_m_line = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_sequence;
        protected $_m_line;

        /**
         * Sequence number
         */
        public function sequence() { return $this->_m_sequence; }

        /**
         * Line of standard output or standard error
         */
        public function line() { return $this->_m_line; }
    }
}

/**
 * Statistics on the latency of observations received from the base
 * station. As observation packets are received their GPS time is compared
 * to the current GPS time calculated locally by the receiver to give a
 * precise measurement of the end-to-end communication latency in the
 * system.
 */

namespace Piksi {
    class Latency extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_avg = $this->_io->readS4le();
            $this->_m_lmin = $this->_io->readS4le();
            $this->_m_lmax = $this->_io->readS4le();
            $this->_m_current = $this->_io->readS4le();
        }
        protected $_m_avg;
        protected $_m_lmin;
        protected $_m_lmax;
        protected $_m_current;

        /**
         * Average latency
         */
        public function avg() { return $this->_m_avg; }

        /**
         * Minimum latency
         */
        public function lmin() { return $this->_m_lmin; }

        /**
         * Maximum latency
         */
        public function lmax() { return $this->_m_lmax; }

        /**
         * Smoothed estimate of the current latency
         */
        public function current() { return $this->_m_current; }
    }
}

/**
 * The thread usage message from the device reports real-time operating
 * system (RTOS) thread usage statistics for the named thread. The reported
 * percentage values must be normalized.
 */

namespace Piksi {
    class MsgThreadState extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_name = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
            $this->_m_cpu = $this->_io->readU2le();
            $this->_m_stackFree = $this->_io->readU4le();
        }
        protected $_m_name;
        protected $_m_cpu;
        protected $_m_stackFree;

        /**
         * Thread name (NULL terminated)
         */
        public function name() { return $this->_m_name; }

        /**
         * Percentage cpu use for this thread. Values range from 0 - 1000 and
         * needs to be renormalized to 100
         */
        public function cpu() { return $this->_m_cpu; }

        /**
         * Free stack space for this thread
         */
        public function stackFree() { return $this->_m_stackFree; }
    }
}

/**
 * Deprecated
 */

namespace Piksi {
    class MsgUartStateDepa extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_uartA = new \Piksi\UartChannel($this->_io, $this, $this->_root);
            $this->_m_uartB = new \Piksi\UartChannel($this->_io, $this, $this->_root);
            $this->_m_uartFtdi = new \Piksi\UartChannel($this->_io, $this, $this->_root);
            $this->_m_latency = new \Piksi\Latency($this->_io, $this, $this->_root);
        }
        protected $_m_uartA;
        protected $_m_uartB;
        protected $_m_uartFtdi;
        protected $_m_latency;

        /**
         * State of UART A
         */
        public function uartA() { return $this->_m_uartA; }

        /**
         * State of UART B
         */
        public function uartB() { return $this->_m_uartB; }

        /**
         * State of UART FTDI (USB logger)
         */
        public function uartFtdi() { return $this->_m_uartFtdi; }

        /**
         * UART communication latency
         */
        public function latency() { return $this->_m_latency; }
    }
}

/**
 * Request state of Piksi network interfaces. Output will be sent in
 * MSG_NETWORK_STATE_RESP messages.
 */

namespace Piksi {
    class MsgNetworkStateReq extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * This message contains temperature and voltage level measurements from
 * the processor's monitoring system and the RF frontend die temperature if
 * available.
 */

namespace Piksi {
    class MsgDeviceMonitor extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_devVin = $this->_io->readS2le();
            $this->_m_cpuVint = $this->_io->readS2le();
            $this->_m_cpuVaux = $this->_io->readS2le();
            $this->_m_cpuTemperature = $this->_io->readS2le();
            $this->_m_feTemperature = $this->_io->readS2le();
        }
        protected $_m_devVin;
        protected $_m_cpuVint;
        protected $_m_cpuVaux;
        protected $_m_cpuTemperature;
        protected $_m_feTemperature;

        /**
         * Device V_in
         */
        public function devVin() { return $this->_m_devVin; }

        /**
         * Processor V_int
         */
        public function cpuVint() { return $this->_m_cpuVint; }

        /**
         * Processor V_aux
         */
        public function cpuVaux() { return $this->_m_cpuVaux; }

        /**
         * Processor temperature
         */
        public function cpuTemperature() { return $this->_m_cpuTemperature; }

        /**
         * Frontend temperature (if available)
         */
        public function feTemperature() { return $this->_m_feTemperature; }
    }
}

/**
 * Deprecated.
 */

namespace Piksi {
    class MsgMaskSatelliteDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_mask = $this->_io->readU1();
            $this->_m_sid = new \Gnss\GnssSignalDep($this->_io, $this, $this->_root);
        }
        protected $_m_mask;
        protected $_m_sid;

        /**
         * Mask of systems that should ignore this satellite.
         */
        public function mask() { return $this->_m_mask; }

        /**
         * GNSS signal for which the mask is applied
         */
        public function sid() { return $this->_m_sid; }
    }
}

/**
 * The UART message reports data latency and throughput of the UART
 * channels providing SBP I/O. On the default Piksi configuration, UARTs A
 * and B are used for telemetry radios, but can also be host access ports
 * for embedded hosts, or other interfaces in future. The reported
 * percentage values must be normalized. Observations latency and period
 * can be used to assess the health of the differential corrections link.
 * Latency provides the timeliness of received base observations while the
 * period indicates their likelihood of transmission.
 */

namespace Piksi {
    class MsgUartState extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_uartA = new \Piksi\UartChannel($this->_io, $this, $this->_root);
            $this->_m_uartB = new \Piksi\UartChannel($this->_io, $this, $this->_root);
            $this->_m_uartFtdi = new \Piksi\UartChannel($this->_io, $this, $this->_root);
            $this->_m_latency = new \Piksi\Latency($this->_io, $this, $this->_root);
            $this->_m_obsPeriod = new \Piksi\Period($this->_io, $this, $this->_root);
        }
        protected $_m_uartA;
        protected $_m_uartB;
        protected $_m_uartFtdi;
        protected $_m_latency;
        protected $_m_obsPeriod;

        /**
         * State of UART A
         */
        public function uartA() { return $this->_m_uartA; }

        /**
         * State of UART B
         */
        public function uartB() { return $this->_m_uartB; }

        /**
         * State of UART FTDI (USB logger)
         */
        public function uartFtdi() { return $this->_m_uartFtdi; }

        /**
         * UART communication latency
         */
        public function latency() { return $this->_m_latency; }

        /**
         * Observation receipt period
         */
        public function obsPeriod() { return $this->_m_obsPeriod; }
    }
}

/**
 * Spectrum analyzer packet.
 */

namespace Piksi {
    class MsgSpecan extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_channelTag = $this->_io->readU2le();
            $this->_m_t = new \Gnss\GpsTime($this->_io, $this, $this->_root);
            $this->_m_freqRef = $this->_io->readF4le();
            $this->_m_freqStep = $this->_io->readF4le();
            $this->_m_amplitudeRef = $this->_io->readF4le();
            $this->_m_amplitudeUnit = $this->_io->readF4le();
            $this->_m_amplitudeValue = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_amplitudeValue[] = $this->_io->readU1();
                $i++;
            }
        }
        protected $_m_channelTag;
        protected $_m_t;
        protected $_m_freqRef;
        protected $_m_freqStep;
        protected $_m_amplitudeRef;
        protected $_m_amplitudeUnit;
        protected $_m_amplitudeValue;

        /**
         * Channel ID
         */
        public function channelTag() { return $this->_m_channelTag; }

        /**
         * Receiver time of this observation
         */
        public function t() { return $this->_m_t; }

        /**
         * Reference frequency of this packet
         */
        public function freqRef() { return $this->_m_freqRef; }

        /**
         * Frequency step of points in this packet
         */
        public function freqStep() { return $this->_m_freqStep; }

        /**
         * Reference amplitude of this packet
         */
        public function amplitudeRef() { return $this->_m_amplitudeRef; }

        /**
         * Amplitude unit value of points in this packet
         */
        public function amplitudeUnit() { return $this->_m_amplitudeUnit; }

        /**
         * Amplitude values (in the above units) of points in this packet
         */
        public function amplitudeValue() { return $this->_m_amplitudeValue; }
    }
}

/**
 * This message reports the state of the Integer Ambiguity Resolution (IAR)
 * process, which resolves unknown integer ambiguities from double-
 * differenced carrier-phase measurements from satellite observations.
 */

namespace Piksi {
    class MsgIarState extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_numHyps = $this->_io->readU4le();
        }
        protected $_m_numHyps;

        /**
         * Number of integer ambiguity hypotheses remaining
         */
        public function numHyps() { return $this->_m_numHyps; }
    }
}

/**
 * This is a legacy message for sending and loading a satellite alamanac
 * onto the Piksi's flash memory from the host.
 */

namespace Piksi {
    class MsgAlmanac extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * This message resets either the DGNSS Kalman filters or Integer Ambiguity
 * Resolution (IAR) process.
 */

namespace Piksi {
    class MsgResetFilters extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_filter = $this->_io->readU1();
        }
        protected $_m_filter;

        /**
         * Filter flags
         */
        public function filter() { return $this->_m_filter; }
    }
}

/**
 * Throughput, utilization, and error counts on the RX/TX buffers of this
 * UART channel. The reported percentage values must be normalized.
 */

namespace Piksi {
    class UartChannel extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_txThroughput = $this->_io->readF4le();
            $this->_m_rxThroughput = $this->_io->readF4le();
            $this->_m_crcErrorCount = $this->_io->readU2le();
            $this->_m_ioErrorCount = $this->_io->readU2le();
            $this->_m_txBufferLevel = $this->_io->readU1();
            $this->_m_rxBufferLevel = $this->_io->readU1();
        }
        protected $_m_txThroughput;
        protected $_m_rxThroughput;
        protected $_m_crcErrorCount;
        protected $_m_ioErrorCount;
        protected $_m_txBufferLevel;
        protected $_m_rxBufferLevel;

        /**
         * UART transmit throughput
         */
        public function txThroughput() { return $this->_m_txThroughput; }

        /**
         * UART receive throughput
         */
        public function rxThroughput() { return $this->_m_rxThroughput; }

        /**
         * UART CRC error count
         */
        public function crcErrorCount() { return $this->_m_crcErrorCount; }

        /**
         * UART IO error count
         */
        public function ioErrorCount() { return $this->_m_ioErrorCount; }

        /**
         * UART transmit buffer percentage utilization (ranges from 0 to 255)
         */
        public function txBufferLevel() { return $this->_m_txBufferLevel; }

        /**
         * UART receive buffer percentage utilization (ranges from 0 to 255)
         */
        public function rxBufferLevel() { return $this->_m_rxBufferLevel; }
    }
}

/**
 * Request the recipient to execute an command. Output will be sent in
 * MSG_LOG messages, and the exit code will be returned with
 * MSG_COMMAND_RESP.
 */

namespace Piksi {
    class MsgCommandReq extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sequence = $this->_io->readU4le();
            $this->_m_command = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_sequence;
        protected $_m_command;

        /**
         * Sequence number
         */
        public function sequence() { return $this->_m_sequence; }

        /**
         * Command line to execute
         */
        public function command() { return $this->_m_command; }
    }
}

/**
 * This message allows setting a mask to prevent a particular satellite
 * from being used in various Piksi subsystems.
 */

namespace Piksi {
    class MsgMaskSatellite extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_mask = $this->_io->readU1();
            $this->_m_sid = new \Gnss\GnssSignal($this->_io, $this, $this->_root);
        }
        protected $_m_mask;
        protected $_m_sid;

        /**
         * Mask of systems that should ignore this satellite.
         */
        public function mask() { return $this->_m_mask; }

        /**
         * GNSS signal for which the mask is applied
         */
        public function sid() { return $this->_m_sid; }
    }
}

/**
 * The bandwidth usage, a list of usage by interface.
 */

namespace Piksi {
    class MsgNetworkBandwidthUsage extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_interfaces = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_interfaces[] = new \Piksi\NetworkUsage($this->_io, $this, $this->_root);
                $i++;
            }
        }
        protected $_m_interfaces;

        /**
         * Usage measurement array
         */
        public function interfaces() { return $this->_m_interfaces; }
    }
}

/**
 * This message from the host resets the Piksi back into the bootloader.
 */

namespace Piksi {
    class MsgReset extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_flags = $this->_io->readU4le();
        }
        protected $_m_flags;

        /**
         * Reset flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * If a cell modem is present on a piksi device, this message will be send
 * periodically to update the host on the status of the modem and its
 * various parameters.
 */

namespace Piksi {
    class MsgCellModemStatus extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_signalStrength = $this->_io->readS1();
            $this->_m_signalErrorRate = $this->_io->readF4le();
            $this->_m_reserved = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_reserved[] = $this->_io->readU1();
                $i++;
            }
        }
        protected $_m_signalStrength;
        protected $_m_signalErrorRate;
        protected $_m_reserved;

        /**
         * Received cell signal strength in dBm, zero translates to unknown
         */
        public function signalStrength() { return $this->_m_signalStrength; }

        /**
         * BER as reported by the modem, zero translates to unknown
         */
        public function signalErrorRate() { return $this->_m_signalErrorRate; }

        /**
         * Unspecified data TBD for this schema
         */
        public function reserved() { return $this->_m_reserved; }
    }
}

/**
 * This message describes the gain of each channel in the receiver
 * frontend. Each gain is encoded as a non-dimensional percentage relative
 * to the maximum range possible for the gain stage of the frontend. By
 * convention, each gain array has 8 entries and the index of the array
 * corresponding to the index of the rf channel in the frontend. A gain of
 * 127 percent encodes that rf channel is not present in the hardware. A
 * negative value implies an error for the particular gain stage as
 * reported by the frontend.
 */

namespace Piksi {
    class MsgFrontEndGain extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_rfGain = [];
            $n = 8;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_rfGain[] = $this->_io->readS1();
            }
            $this->_m_ifGain = [];
            $n = 8;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_ifGain[] = $this->_io->readS1();
            }
        }
        protected $_m_rfGain;
        protected $_m_ifGain;

        /**
         * RF gain for each frontend channel
         */
        public function rfGain() { return $this->_m_rfGain; }

        /**
         * Intermediate frequency gain for each frontend channel
         */
        public function ifGain() { return $this->_m_ifGain; }
    }
}

/**
 * This message from the host resets the Piksi back into the bootloader.
 */

namespace Piksi {
    class MsgResetDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * This message sets up timing functionality using a coarse GPS time
 * estimate sent by the host.
 */

namespace Piksi {
    class MsgSetTime extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * This is an unused legacy message for result reporting from the CW
 * interference channel on the SwiftNAP. This message will be removed in a
 * future release.
 */

namespace Piksi {
    class MsgCwResults extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
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

namespace Piksi {
    class MsgSpecanDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_channelTag = $this->_io->readU2le();
            $this->_m_t = new \Gnss\GpsTimeDep($this->_io, $this, $this->_root);
            $this->_m_freqRef = $this->_io->readF4le();
            $this->_m_freqStep = $this->_io->readF4le();
            $this->_m_amplitudeRef = $this->_io->readF4le();
            $this->_m_amplitudeUnit = $this->_io->readF4le();
            $this->_m_amplitudeValue = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_amplitudeValue[] = $this->_io->readU1();
                $i++;
            }
        }
        protected $_m_channelTag;
        protected $_m_t;
        protected $_m_freqRef;
        protected $_m_freqStep;
        protected $_m_amplitudeRef;
        protected $_m_amplitudeUnit;
        protected $_m_amplitudeValue;

        /**
         * Channel ID
         */
        public function channelTag() { return $this->_m_channelTag; }

        /**
         * Receiver time of this observation
         */
        public function t() { return $this->_m_t; }

        /**
         * Reference frequency of this packet
         */
        public function freqRef() { return $this->_m_freqRef; }

        /**
         * Frequency step of points in this packet
         */
        public function freqStep() { return $this->_m_freqStep; }

        /**
         * Reference amplitude of this packet
         */
        public function amplitudeRef() { return $this->_m_amplitudeRef; }

        /**
         * Amplitude unit value of points in this packet
         */
        public function amplitudeUnit() { return $this->_m_amplitudeUnit; }

        /**
         * Amplitude values (in the above units) of points in this packet
         */
        public function amplitudeValue() { return $this->_m_amplitudeValue; }
    }
}

/**
 * Deprecated
 */

namespace Piksi {
    class MsgInitBaseDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * Statistics on the period of observations received from the base station.
 * As complete observation sets are received, their time of reception is
 * compared with the prior set''s time of reception. This measurement
 * provides a proxy for link quality as incomplete or missing sets will
 * increase the period.  Long periods can cause momentary RTK solution
 * outages.
 */

namespace Piksi {
    class Period extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Piksi\MsgUartState $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_avg = $this->_io->readS4le();
            $this->_m_pmin = $this->_io->readS4le();
            $this->_m_pmax = $this->_io->readS4le();
            $this->_m_current = $this->_io->readS4le();
        }
        protected $_m_avg;
        protected $_m_pmin;
        protected $_m_pmax;
        protected $_m_current;

        /**
         * Average period
         */
        public function avg() { return $this->_m_avg; }

        /**
         * Minimum period
         */
        public function pmin() { return $this->_m_pmin; }

        /**
         * Maximum period
         */
        public function pmax() { return $this->_m_pmax; }

        /**
         * Smoothed estimate of the current period
         */
        public function current() { return $this->_m_current; }
    }
}

/**
 * This is an unused legacy message from the host for starting the CW
 * interference channel on the SwiftNAP. This message will be removed in a
 * future release.
 */

namespace Piksi {
    class MsgCwStart extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Piksi $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}
