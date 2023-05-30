<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Linux extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Linux $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

/**
 * Summaries the socket usage across the system.
 */

namespace Linux {
    class MsgLinuxSocketUsage extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Linux $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_avgQueueDepth = $this->_io->readU4le();
            $this->_m_maxQueueDepth = $this->_io->readU4le();
            $this->_m_socketStateCounts = [];
            $n = 16;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_socketStateCounts[] = $this->_io->readU2le();
            }
            $this->_m_socketTypeCounts = [];
            $n = 16;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_socketTypeCounts[] = $this->_io->readU2le();
            }
        }
        protected $_m_avgQueueDepth;
        protected $_m_maxQueueDepth;
        protected $_m_socketStateCounts;
        protected $_m_socketTypeCounts;

        /**
         * average socket queue depths across all sockets on the system
         */
        public function avgQueueDepth() { return $this->_m_avgQueueDepth; }

        /**
         * the max queue depth seen within the reporting period
         */
        public function maxQueueDepth() { return $this->_m_maxQueueDepth; }

        /**
         * A count for each socket type reported in the `socket_types_reported`
         * field, the first entry corresponds to the first enabled bit in
         * `types_reported`.
         */
        public function socketStateCounts() { return $this->_m_socketStateCounts; }

        /**
         * A count for each socket type reported in the `socket_types_reported`
         * field, the first entry corresponds to the first enabled bit in
         * `types_reported`.
         */
        public function socketTypeCounts() { return $this->_m_socketTypeCounts; }
    }
}

/**
 * This presents a summary of CPU and memory utilization, including a
 * timestamp.
 */

namespace Linux {
    class MsgLinuxSysState extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Linux $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_memTotal = $this->_io->readU2le();
            $this->_m_pcpu = $this->_io->readU1();
            $this->_m_pmem = $this->_io->readU1();
            $this->_m_procsStarting = $this->_io->readU2le();
            $this->_m_procsStopping = $this->_io->readU2le();
            $this->_m_pidCount = $this->_io->readU2le();
            $this->_m_time = $this->_io->readU4le();
            $this->_m_flags = $this->_io->readU1();
        }
        protected $_m_memTotal;
        protected $_m_pcpu;
        protected $_m_pmem;
        protected $_m_procsStarting;
        protected $_m_procsStopping;
        protected $_m_pidCount;
        protected $_m_time;
        protected $_m_flags;

        /**
         * total system memory, in MiB
         */
        public function memTotal() { return $this->_m_memTotal; }

        /**
         * percent of CPU used, expressed as a fraction of 256
         */
        public function pcpu() { return $this->_m_pcpu; }

        /**
         * percent of memory used, expressed as a fraction of 256
         */
        public function pmem() { return $this->_m_pmem; }

        /**
         * number of processes that started during collection phase
         */
        public function procsStarting() { return $this->_m_procsStarting; }

        /**
         * number of processes that stopped during collection phase
         */
        public function procsStopping() { return $this->_m_procsStopping; }

        /**
         * the count of processes on the system
         */
        public function pidCount() { return $this->_m_pidCount; }

        /**
         * timestamp of message, refer to flags field for how to interpret
         */
        public function time() { return $this->_m_time; }

        /**
         * flags
         */
        public function flags() { return $this->_m_flags; }
    }
}

/**
 * This message indicates the process state of the top 10 heaviest
 * consumers of CPU on the system.
 */

namespace Linux {
    class MsgLinuxCpuStateDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Linux $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_index = $this->_io->readU1();
            $this->_m_pid = $this->_io->readU2le();
            $this->_m_pcpu = $this->_io->readU1();
            $this->_m_tname = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
            $this->_m_cmdline = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_index;
        protected $_m_pid;
        protected $_m_pcpu;
        protected $_m_tname;
        protected $_m_cmdline;

        /**
         * sequence of this status message, values from 0-9
         */
        public function index() { return $this->_m_index; }

        /**
         * the PID of the process
         */
        public function pid() { return $this->_m_pid; }

        /**
         * percent of cpu used, expressed as a fraction of 256
         */
        public function pcpu() { return $this->_m_pcpu; }

        /**
         * fixed length string representing the thread name
         */
        public function tname() { return $this->_m_tname; }

        /**
         * the command line (as much as it fits in the remaining packet)
         */
        public function cmdline() { return $this->_m_cmdline; }
    }
}

/**
 * This message indicates the process state of the top 10 heaviest
 * consumers of memory on the system, including a timestamp.
 */

namespace Linux {
    class MsgLinuxMemState extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Linux $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_index = $this->_io->readU1();
            $this->_m_pid = $this->_io->readU2le();
            $this->_m_pmem = $this->_io->readU1();
            $this->_m_time = $this->_io->readU4le();
            $this->_m_flags = $this->_io->readU1();
            $this->_m_tname = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
            $this->_m_cmdline = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_index;
        protected $_m_pid;
        protected $_m_pmem;
        protected $_m_time;
        protected $_m_flags;
        protected $_m_tname;
        protected $_m_cmdline;

        /**
         * sequence of this status message, values from 0-9
         */
        public function index() { return $this->_m_index; }

        /**
         * the PID of the process
         */
        public function pid() { return $this->_m_pid; }

        /**
         * percent of memory used, expressed as a fraction of 256
         */
        public function pmem() { return $this->_m_pmem; }

        /**
         * timestamp of message, refer to flags field for how to interpret
         */
        public function time() { return $this->_m_time; }

        /**
         * flags
         */
        public function flags() { return $this->_m_flags; }

        /**
         * fixed length string representing the thread name
         */
        public function tname() { return $this->_m_tname; }

        /**
         * the command line (as much as it fits in the remaining packet)
         */
        public function cmdline() { return $this->_m_cmdline; }
    }
}

/**
 * Top 10 list of processes with a large number of open file descriptors.
 */

namespace Linux {
    class MsgLinuxProcessFdCount extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Linux $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_index = $this->_io->readU1();
            $this->_m_pid = $this->_io->readU2le();
            $this->_m_fdCount = $this->_io->readU2le();
            $this->_m_cmdline = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_index;
        protected $_m_pid;
        protected $_m_fdCount;
        protected $_m_cmdline;

        /**
         * sequence of this status message, values from 0-9
         */
        public function index() { return $this->_m_index; }

        /**
         * the PID of the process in question
         */
        public function pid() { return $this->_m_pid; }

        /**
         * a count of the number of file descriptors opened by the process
         */
        public function fdCount() { return $this->_m_fdCount; }

        /**
         * the command line of the process in question
         */
        public function cmdline() { return $this->_m_cmdline; }
    }
}

/**
 * This message indicates the process state of the top 10 heaviest
 * consumers of memory on the system.
 */

namespace Linux {
    class MsgLinuxMemStateDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Linux $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_index = $this->_io->readU1();
            $this->_m_pid = $this->_io->readU2le();
            $this->_m_pmem = $this->_io->readU1();
            $this->_m_tname = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
            $this->_m_cmdline = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_index;
        protected $_m_pid;
        protected $_m_pmem;
        protected $_m_tname;
        protected $_m_cmdline;

        /**
         * sequence of this status message, values from 0-9
         */
        public function index() { return $this->_m_index; }

        /**
         * the PID of the process
         */
        public function pid() { return $this->_m_pid; }

        /**
         * percent of memory used, expressed as a fraction of 256
         */
        public function pmem() { return $this->_m_pmem; }

        /**
         * fixed length string representing the thread name
         */
        public function tname() { return $this->_m_tname; }

        /**
         * the command line (as much as it fits in the remaining packet)
         */
        public function cmdline() { return $this->_m_cmdline; }
    }
}

/**
 * Top 10 list of sockets with deep queues.
 */

namespace Linux {
    class MsgLinuxProcessSocketQueues extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Linux $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_index = $this->_io->readU1();
            $this->_m_pid = $this->_io->readU2le();
            $this->_m_recvQueued = $this->_io->readU2le();
            $this->_m_sendQueued = $this->_io->readU2le();
            $this->_m_socketTypes = $this->_io->readU2le();
            $this->_m_socketStates = $this->_io->readU2le();
            $this->_m_addressOfLargest = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
            $this->_m_cmdline = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_index;
        protected $_m_pid;
        protected $_m_recvQueued;
        protected $_m_sendQueued;
        protected $_m_socketTypes;
        protected $_m_socketStates;
        protected $_m_addressOfLargest;
        protected $_m_cmdline;

        /**
         * sequence of this status message, values from 0-9
         */
        public function index() { return $this->_m_index; }

        /**
         * the PID of the process in question
         */
        public function pid() { return $this->_m_pid; }

        /**
         * the total amount of receive data queued for this process
         */
        public function recvQueued() { return $this->_m_recvQueued; }

        /**
         * the total amount of send data queued for this process
         */
        public function sendQueued() { return $this->_m_sendQueued; }

        /**
         * A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
         * 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
         * (unknown)
         */
        public function socketTypes() { return $this->_m_socketTypes; }

        /**
         * A bitfield indicating the socket states: 0x1 (established), 0x2
         * (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
         * 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
         * ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
         * 0x8000 (unknown)
         */
        public function socketStates() { return $this->_m_socketStates; }

        /**
         * Address of the largest queue, remote or local depending on the
         * directionality of the connection.
         */
        public function addressOfLargest() { return $this->_m_addressOfLargest; }

        /**
         * the command line of the process in question
         */
        public function cmdline() { return $this->_m_cmdline; }
    }
}

/**
 * This presents a summary of CPU and memory utilization.
 */

namespace Linux {
    class MsgLinuxSysStateDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Linux $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_memTotal = $this->_io->readU2le();
            $this->_m_pcpu = $this->_io->readU1();
            $this->_m_pmem = $this->_io->readU1();
            $this->_m_procsStarting = $this->_io->readU2le();
            $this->_m_procsStopping = $this->_io->readU2le();
            $this->_m_pidCount = $this->_io->readU2le();
        }
        protected $_m_memTotal;
        protected $_m_pcpu;
        protected $_m_pmem;
        protected $_m_procsStarting;
        protected $_m_procsStopping;
        protected $_m_pidCount;

        /**
         * total system memory
         */
        public function memTotal() { return $this->_m_memTotal; }

        /**
         * percent of total cpu currently utilized
         */
        public function pcpu() { return $this->_m_pcpu; }

        /**
         * percent of total memory currently utilized
         */
        public function pmem() { return $this->_m_pmem; }

        /**
         * number of processes that started during collection phase
         */
        public function procsStarting() { return $this->_m_procsStarting; }

        /**
         * number of processes that stopped during collection phase
         */
        public function procsStopping() { return $this->_m_procsStopping; }

        /**
         * the count of processes on the system
         */
        public function pidCount() { return $this->_m_pidCount; }
    }
}

/**
 * Summary of open file descriptors on the system.
 */

namespace Linux {
    class MsgLinuxProcessFdSummary extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Linux $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_sysFdCount = $this->_io->readU4le();
            $this->_m_mostOpened = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_sysFdCount;
        protected $_m_mostOpened;

        /**
         * count of total FDs open on the system
         */
        public function sysFdCount() { return $this->_m_sysFdCount; }

        /**
         * A null delimited list of strings which alternates between a string
         * representation of the process count and the file name whose count it
         * being reported.  That is, in C string syntax
         * "32\0/var/log/syslog\012\0/tmp/foo\0" with the end of the list being
         * 2 NULL terminators in a row.
         */
        public function mostOpened() { return $this->_m_mostOpened; }
    }
}

/**
 * This message indicates the process state of the top 10 heaviest
 * consumers of CPU on the system, including a timestamp.
 */

namespace Linux {
    class MsgLinuxCpuState extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Linux $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_index = $this->_io->readU1();
            $this->_m_pid = $this->_io->readU2le();
            $this->_m_pcpu = $this->_io->readU1();
            $this->_m_time = $this->_io->readU4le();
            $this->_m_flags = $this->_io->readU1();
            $this->_m_tname = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
            $this->_m_cmdline = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_index;
        protected $_m_pid;
        protected $_m_pcpu;
        protected $_m_time;
        protected $_m_flags;
        protected $_m_tname;
        protected $_m_cmdline;

        /**
         * sequence of this status message, values from 0-9
         */
        public function index() { return $this->_m_index; }

        /**
         * the PID of the process
         */
        public function pid() { return $this->_m_pid; }

        /**
         * percent of CPU used, expressed as a fraction of 256
         */
        public function pcpu() { return $this->_m_pcpu; }

        /**
         * timestamp of message, refer to flags field for how to interpret
         */
        public function time() { return $this->_m_time; }

        /**
         * flags
         */
        public function flags() { return $this->_m_flags; }

        /**
         * fixed length string representing the thread name
         */
        public function tname() { return $this->_m_tname; }

        /**
         * the command line (as much as it fits in the remaining packet)
         */
        public function cmdline() { return $this->_m_cmdline; }
    }
}

/**
 * Top 10 list of processes with high socket counts.
 */

namespace Linux {
    class MsgLinuxProcessSocketCounts extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Linux $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_index = $this->_io->readU1();
            $this->_m_pid = $this->_io->readU2le();
            $this->_m_socketCount = $this->_io->readU2le();
            $this->_m_socketTypes = $this->_io->readU2le();
            $this->_m_socketStates = $this->_io->readU2le();
            $this->_m_cmdline = \Kaitai\Struct\Stream::bytesToStr($this->_io->readBytesFull(), "ascii");
        }
        protected $_m_index;
        protected $_m_pid;
        protected $_m_socketCount;
        protected $_m_socketTypes;
        protected $_m_socketStates;
        protected $_m_cmdline;

        /**
         * sequence of this status message, values from 0-9
         */
        public function index() { return $this->_m_index; }

        /**
         * the PID of the process in question
         */
        public function pid() { return $this->_m_pid; }

        /**
         * the number of sockets the process is using
         */
        public function socketCount() { return $this->_m_socketCount; }

        /**
         * A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
         * 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
         * (unknown)
         */
        public function socketTypes() { return $this->_m_socketTypes; }

        /**
         * A bitfield indicating the socket states: 0x1 (established), 0x2
         * (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
         * 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
         * ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
         * 0x8000 (unknown)
         */
        public function socketStates() { return $this->_m_socketStates; }

        /**
         * the command line of the process in question
         */
        public function cmdline() { return $this->_m_cmdline; }
    }
}
