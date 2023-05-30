// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.util.ArrayList;
import java.nio.charset.Charset;

public class Linux extends KaitaiStruct {
    public static Linux fromFile(String fileName) throws IOException {
        return new Linux(new ByteBufferKaitaiStream(fileName));
    }

    public Linux(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Linux(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Linux(KaitaiStream _io, KaitaiStruct _parent, Linux _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }

    /**
     * Summaries the socket usage across the system.
     */
    public static class MsgLinuxSocketUsage extends KaitaiStruct {
        public static MsgLinuxSocketUsage fromFile(String fileName) throws IOException {
            return new MsgLinuxSocketUsage(new ByteBufferKaitaiStream(fileName));
        }

        public MsgLinuxSocketUsage(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgLinuxSocketUsage(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgLinuxSocketUsage(KaitaiStream _io, Sbp.Message _parent, Linux _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.avgQueueDepth = this._io.readU4le();
            this.maxQueueDepth = this._io.readU4le();
            this.socketStateCounts = new ArrayList<Integer>();
            for (int i = 0; i < 16; i++) {
                this.socketStateCounts.add(this._io.readU2le());
            }
            this.socketTypeCounts = new ArrayList<Integer>();
            for (int i = 0; i < 16; i++) {
                this.socketTypeCounts.add(this._io.readU2le());
            }
        }
        private long avgQueueDepth;
        private long maxQueueDepth;
        private ArrayList<Integer> socketStateCounts;
        private ArrayList<Integer> socketTypeCounts;
        private Linux _root;
        private Sbp.Message _parent;

        /**
         * average socket queue depths across all sockets on the system
         */
        public long avgQueueDepth() { return avgQueueDepth; }

        /**
         * the max queue depth seen within the reporting period
         */
        public long maxQueueDepth() { return maxQueueDepth; }

        /**
         * A count for each socket type reported in the `socket_types_reported`
         * field, the first entry corresponds to the first enabled bit in
         * `types_reported`.
         */
        public ArrayList<Integer> socketStateCounts() { return socketStateCounts; }

        /**
         * A count for each socket type reported in the `socket_types_reported`
         * field, the first entry corresponds to the first enabled bit in
         * `types_reported`.
         */
        public ArrayList<Integer> socketTypeCounts() { return socketTypeCounts; }
        public Linux _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This presents a summary of CPU and memory utilization, including a
     * timestamp.
     */
    public static class MsgLinuxSysState extends KaitaiStruct {
        public static MsgLinuxSysState fromFile(String fileName) throws IOException {
            return new MsgLinuxSysState(new ByteBufferKaitaiStream(fileName));
        }

        public MsgLinuxSysState(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgLinuxSysState(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgLinuxSysState(KaitaiStream _io, Sbp.Message _parent, Linux _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.memTotal = this._io.readU2le();
            this.pcpu = this._io.readU1();
            this.pmem = this._io.readU1();
            this.procsStarting = this._io.readU2le();
            this.procsStopping = this._io.readU2le();
            this.pidCount = this._io.readU2le();
            this.time = this._io.readU4le();
            this.flags = this._io.readU1();
        }
        private int memTotal;
        private int pcpu;
        private int pmem;
        private int procsStarting;
        private int procsStopping;
        private int pidCount;
        private long time;
        private int flags;
        private Linux _root;
        private Sbp.Message _parent;

        /**
         * total system memory, in MiB
         */
        public int memTotal() { return memTotal; }

        /**
         * percent of CPU used, expressed as a fraction of 256
         */
        public int pcpu() { return pcpu; }

        /**
         * percent of memory used, expressed as a fraction of 256
         */
        public int pmem() { return pmem; }

        /**
         * number of processes that started during collection phase
         */
        public int procsStarting() { return procsStarting; }

        /**
         * number of processes that stopped during collection phase
         */
        public int procsStopping() { return procsStopping; }

        /**
         * the count of processes on the system
         */
        public int pidCount() { return pidCount; }

        /**
         * timestamp of message, refer to flags field for how to interpret
         */
        public long time() { return time; }

        /**
         * flags
         */
        public int flags() { return flags; }
        public Linux _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message indicates the process state of the top 10 heaviest
     * consumers of CPU on the system.
     */
    public static class MsgLinuxCpuStateDepA extends KaitaiStruct {
        public static MsgLinuxCpuStateDepA fromFile(String fileName) throws IOException {
            return new MsgLinuxCpuStateDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgLinuxCpuStateDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgLinuxCpuStateDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgLinuxCpuStateDepA(KaitaiStream _io, Sbp.Message _parent, Linux _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.index = this._io.readU1();
            this.pid = this._io.readU2le();
            this.pcpu = this._io.readU1();
            this.tname = new String(this._io.readBytesFull(), Charset.forName("ascii"));
            this.cmdline = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private int index;
        private int pid;
        private int pcpu;
        private String tname;
        private String cmdline;
        private Linux _root;
        private Sbp.Message _parent;

        /**
         * sequence of this status message, values from 0-9
         */
        public int index() { return index; }

        /**
         * the PID of the process
         */
        public int pid() { return pid; }

        /**
         * percent of cpu used, expressed as a fraction of 256
         */
        public int pcpu() { return pcpu; }

        /**
         * fixed length string representing the thread name
         */
        public String tname() { return tname; }

        /**
         * the command line (as much as it fits in the remaining packet)
         */
        public String cmdline() { return cmdline; }
        public Linux _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message indicates the process state of the top 10 heaviest
     * consumers of memory on the system, including a timestamp.
     */
    public static class MsgLinuxMemState extends KaitaiStruct {
        public static MsgLinuxMemState fromFile(String fileName) throws IOException {
            return new MsgLinuxMemState(new ByteBufferKaitaiStream(fileName));
        }

        public MsgLinuxMemState(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgLinuxMemState(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgLinuxMemState(KaitaiStream _io, Sbp.Message _parent, Linux _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.index = this._io.readU1();
            this.pid = this._io.readU2le();
            this.pmem = this._io.readU1();
            this.time = this._io.readU4le();
            this.flags = this._io.readU1();
            this.tname = new String(this._io.readBytesFull(), Charset.forName("ascii"));
            this.cmdline = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private int index;
        private int pid;
        private int pmem;
        private long time;
        private int flags;
        private String tname;
        private String cmdline;
        private Linux _root;
        private Sbp.Message _parent;

        /**
         * sequence of this status message, values from 0-9
         */
        public int index() { return index; }

        /**
         * the PID of the process
         */
        public int pid() { return pid; }

        /**
         * percent of memory used, expressed as a fraction of 256
         */
        public int pmem() { return pmem; }

        /**
         * timestamp of message, refer to flags field for how to interpret
         */
        public long time() { return time; }

        /**
         * flags
         */
        public int flags() { return flags; }

        /**
         * fixed length string representing the thread name
         */
        public String tname() { return tname; }

        /**
         * the command line (as much as it fits in the remaining packet)
         */
        public String cmdline() { return cmdline; }
        public Linux _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Top 10 list of processes with a large number of open file descriptors.
     */
    public static class MsgLinuxProcessFdCount extends KaitaiStruct {
        public static MsgLinuxProcessFdCount fromFile(String fileName) throws IOException {
            return new MsgLinuxProcessFdCount(new ByteBufferKaitaiStream(fileName));
        }

        public MsgLinuxProcessFdCount(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgLinuxProcessFdCount(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgLinuxProcessFdCount(KaitaiStream _io, Sbp.Message _parent, Linux _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.index = this._io.readU1();
            this.pid = this._io.readU2le();
            this.fdCount = this._io.readU2le();
            this.cmdline = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private int index;
        private int pid;
        private int fdCount;
        private String cmdline;
        private Linux _root;
        private Sbp.Message _parent;

        /**
         * sequence of this status message, values from 0-9
         */
        public int index() { return index; }

        /**
         * the PID of the process in question
         */
        public int pid() { return pid; }

        /**
         * a count of the number of file descriptors opened by the process
         */
        public int fdCount() { return fdCount; }

        /**
         * the command line of the process in question
         */
        public String cmdline() { return cmdline; }
        public Linux _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message indicates the process state of the top 10 heaviest
     * consumers of memory on the system.
     */
    public static class MsgLinuxMemStateDepA extends KaitaiStruct {
        public static MsgLinuxMemStateDepA fromFile(String fileName) throws IOException {
            return new MsgLinuxMemStateDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgLinuxMemStateDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgLinuxMemStateDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgLinuxMemStateDepA(KaitaiStream _io, Sbp.Message _parent, Linux _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.index = this._io.readU1();
            this.pid = this._io.readU2le();
            this.pmem = this._io.readU1();
            this.tname = new String(this._io.readBytesFull(), Charset.forName("ascii"));
            this.cmdline = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private int index;
        private int pid;
        private int pmem;
        private String tname;
        private String cmdline;
        private Linux _root;
        private Sbp.Message _parent;

        /**
         * sequence of this status message, values from 0-9
         */
        public int index() { return index; }

        /**
         * the PID of the process
         */
        public int pid() { return pid; }

        /**
         * percent of memory used, expressed as a fraction of 256
         */
        public int pmem() { return pmem; }

        /**
         * fixed length string representing the thread name
         */
        public String tname() { return tname; }

        /**
         * the command line (as much as it fits in the remaining packet)
         */
        public String cmdline() { return cmdline; }
        public Linux _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Top 10 list of sockets with deep queues.
     */
    public static class MsgLinuxProcessSocketQueues extends KaitaiStruct {
        public static MsgLinuxProcessSocketQueues fromFile(String fileName) throws IOException {
            return new MsgLinuxProcessSocketQueues(new ByteBufferKaitaiStream(fileName));
        }

        public MsgLinuxProcessSocketQueues(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgLinuxProcessSocketQueues(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgLinuxProcessSocketQueues(KaitaiStream _io, Sbp.Message _parent, Linux _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.index = this._io.readU1();
            this.pid = this._io.readU2le();
            this.recvQueued = this._io.readU2le();
            this.sendQueued = this._io.readU2le();
            this.socketTypes = this._io.readU2le();
            this.socketStates = this._io.readU2le();
            this.addressOfLargest = new String(this._io.readBytesFull(), Charset.forName("ascii"));
            this.cmdline = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private int index;
        private int pid;
        private int recvQueued;
        private int sendQueued;
        private int socketTypes;
        private int socketStates;
        private String addressOfLargest;
        private String cmdline;
        private Linux _root;
        private Sbp.Message _parent;

        /**
         * sequence of this status message, values from 0-9
         */
        public int index() { return index; }

        /**
         * the PID of the process in question
         */
        public int pid() { return pid; }

        /**
         * the total amount of receive data queued for this process
         */
        public int recvQueued() { return recvQueued; }

        /**
         * the total amount of send data queued for this process
         */
        public int sendQueued() { return sendQueued; }

        /**
         * A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
         * 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
         * (unknown)
         */
        public int socketTypes() { return socketTypes; }

        /**
         * A bitfield indicating the socket states: 0x1 (established), 0x2
         * (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
         * 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
         * ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
         * 0x8000 (unknown)
         */
        public int socketStates() { return socketStates; }

        /**
         * Address of the largest queue, remote or local depending on the
         * directionality of the connection.
         */
        public String addressOfLargest() { return addressOfLargest; }

        /**
         * the command line of the process in question
         */
        public String cmdline() { return cmdline; }
        public Linux _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This presents a summary of CPU and memory utilization.
     */
    public static class MsgLinuxSysStateDepA extends KaitaiStruct {
        public static MsgLinuxSysStateDepA fromFile(String fileName) throws IOException {
            return new MsgLinuxSysStateDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgLinuxSysStateDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgLinuxSysStateDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgLinuxSysStateDepA(KaitaiStream _io, Sbp.Message _parent, Linux _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.memTotal = this._io.readU2le();
            this.pcpu = this._io.readU1();
            this.pmem = this._io.readU1();
            this.procsStarting = this._io.readU2le();
            this.procsStopping = this._io.readU2le();
            this.pidCount = this._io.readU2le();
        }
        private int memTotal;
        private int pcpu;
        private int pmem;
        private int procsStarting;
        private int procsStopping;
        private int pidCount;
        private Linux _root;
        private Sbp.Message _parent;

        /**
         * total system memory
         */
        public int memTotal() { return memTotal; }

        /**
         * percent of total cpu currently utilized
         */
        public int pcpu() { return pcpu; }

        /**
         * percent of total memory currently utilized
         */
        public int pmem() { return pmem; }

        /**
         * number of processes that started during collection phase
         */
        public int procsStarting() { return procsStarting; }

        /**
         * number of processes that stopped during collection phase
         */
        public int procsStopping() { return procsStopping; }

        /**
         * the count of processes on the system
         */
        public int pidCount() { return pidCount; }
        public Linux _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Summary of open file descriptors on the system.
     */
    public static class MsgLinuxProcessFdSummary extends KaitaiStruct {
        public static MsgLinuxProcessFdSummary fromFile(String fileName) throws IOException {
            return new MsgLinuxProcessFdSummary(new ByteBufferKaitaiStream(fileName));
        }

        public MsgLinuxProcessFdSummary(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgLinuxProcessFdSummary(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgLinuxProcessFdSummary(KaitaiStream _io, Sbp.Message _parent, Linux _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.sysFdCount = this._io.readU4le();
            this.mostOpened = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private long sysFdCount;
        private String mostOpened;
        private Linux _root;
        private Sbp.Message _parent;

        /**
         * count of total FDs open on the system
         */
        public long sysFdCount() { return sysFdCount; }

        /**
         * A null delimited list of strings which alternates between a string
         * representation of the process count and the file name whose count it
         * being reported.  That is, in C string syntax
         * "32\0/var/log/syslog\012\0/tmp/foo\0" with the end of the list being
         * 2 NULL terminators in a row.
         */
        public String mostOpened() { return mostOpened; }
        public Linux _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * This message indicates the process state of the top 10 heaviest
     * consumers of CPU on the system, including a timestamp.
     */
    public static class MsgLinuxCpuState extends KaitaiStruct {
        public static MsgLinuxCpuState fromFile(String fileName) throws IOException {
            return new MsgLinuxCpuState(new ByteBufferKaitaiStream(fileName));
        }

        public MsgLinuxCpuState(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgLinuxCpuState(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgLinuxCpuState(KaitaiStream _io, Sbp.Message _parent, Linux _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.index = this._io.readU1();
            this.pid = this._io.readU2le();
            this.pcpu = this._io.readU1();
            this.time = this._io.readU4le();
            this.flags = this._io.readU1();
            this.tname = new String(this._io.readBytesFull(), Charset.forName("ascii"));
            this.cmdline = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private int index;
        private int pid;
        private int pcpu;
        private long time;
        private int flags;
        private String tname;
        private String cmdline;
        private Linux _root;
        private Sbp.Message _parent;

        /**
         * sequence of this status message, values from 0-9
         */
        public int index() { return index; }

        /**
         * the PID of the process
         */
        public int pid() { return pid; }

        /**
         * percent of CPU used, expressed as a fraction of 256
         */
        public int pcpu() { return pcpu; }

        /**
         * timestamp of message, refer to flags field for how to interpret
         */
        public long time() { return time; }

        /**
         * flags
         */
        public int flags() { return flags; }

        /**
         * fixed length string representing the thread name
         */
        public String tname() { return tname; }

        /**
         * the command line (as much as it fits in the remaining packet)
         */
        public String cmdline() { return cmdline; }
        public Linux _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * Top 10 list of processes with high socket counts.
     */
    public static class MsgLinuxProcessSocketCounts extends KaitaiStruct {
        public static MsgLinuxProcessSocketCounts fromFile(String fileName) throws IOException {
            return new MsgLinuxProcessSocketCounts(new ByteBufferKaitaiStream(fileName));
        }

        public MsgLinuxProcessSocketCounts(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgLinuxProcessSocketCounts(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgLinuxProcessSocketCounts(KaitaiStream _io, Sbp.Message _parent, Linux _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.index = this._io.readU1();
            this.pid = this._io.readU2le();
            this.socketCount = this._io.readU2le();
            this.socketTypes = this._io.readU2le();
            this.socketStates = this._io.readU2le();
            this.cmdline = new String(this._io.readBytesFull(), Charset.forName("ascii"));
        }
        private int index;
        private int pid;
        private int socketCount;
        private int socketTypes;
        private int socketStates;
        private String cmdline;
        private Linux _root;
        private Sbp.Message _parent;

        /**
         * sequence of this status message, values from 0-9
         */
        public int index() { return index; }

        /**
         * the PID of the process in question
         */
        public int pid() { return pid; }

        /**
         * the number of sockets the process is using
         */
        public int socketCount() { return socketCount; }

        /**
         * A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
         * 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
         * (unknown)
         */
        public int socketTypes() { return socketTypes; }

        /**
         * A bitfield indicating the socket states: 0x1 (established), 0x2
         * (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
         * 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
         * ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
         * 0x8000 (unknown)
         */
        public int socketStates() { return socketStates; }

        /**
         * the command line of the process in question
         */
        public String cmdline() { return cmdline; }
        public Linux _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Linux _root;
    private KaitaiStruct _parent;
    public Linux _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
