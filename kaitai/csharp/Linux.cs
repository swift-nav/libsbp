// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class Linux : KaitaiStruct
    {
        public static Linux FromFile(string fileName)
        {
            return new Linux(new KaitaiStream(fileName));
        }

        public Linux(KaitaiStream p__io, KaitaiStruct p__parent = null, Linux p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// Summaries the socket usage across the system.
        /// </summary>
        public partial class MsgLinuxSocketUsage : KaitaiStruct
        {
            public static MsgLinuxSocketUsage FromFile(string fileName)
            {
                return new MsgLinuxSocketUsage(new KaitaiStream(fileName));
            }

            public MsgLinuxSocketUsage(KaitaiStream p__io, Sbp.Message p__parent = null, Linux p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _avgQueueDepth = m_io.ReadU4le();
                _maxQueueDepth = m_io.ReadU4le();
                _socketStateCounts = new List<ushort>();
                for (var i = 0; i < 16; i++)
                {
                    _socketStateCounts.Add(m_io.ReadU2le());
                }
                _socketTypeCounts = new List<ushort>();
                for (var i = 0; i < 16; i++)
                {
                    _socketTypeCounts.Add(m_io.ReadU2le());
                }
            }
            private uint _avgQueueDepth;
            private uint _maxQueueDepth;
            private List<ushort> _socketStateCounts;
            private List<ushort> _socketTypeCounts;
            private Linux m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// average socket queue depths across all sockets on the system
            /// </summary>
            public uint AvgQueueDepth { get { return _avgQueueDepth; } }

            /// <summary>
            /// the max queue depth seen within the reporting period
            /// </summary>
            public uint MaxQueueDepth { get { return _maxQueueDepth; } }

            /// <summary>
            /// A count for each socket type reported in the `socket_types_reported`
            /// field, the first entry corresponds to the first enabled bit in
            /// `types_reported`.
            /// </summary>
            public List<ushort> SocketStateCounts { get { return _socketStateCounts; } }

            /// <summary>
            /// A count for each socket type reported in the `socket_types_reported`
            /// field, the first entry corresponds to the first enabled bit in
            /// `types_reported`.
            /// </summary>
            public List<ushort> SocketTypeCounts { get { return _socketTypeCounts; } }
            public Linux M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This presents a summary of CPU and memory utilization, including a
        /// timestamp.
        /// </summary>
        public partial class MsgLinuxSysState : KaitaiStruct
        {
            public static MsgLinuxSysState FromFile(string fileName)
            {
                return new MsgLinuxSysState(new KaitaiStream(fileName));
            }

            public MsgLinuxSysState(KaitaiStream p__io, Sbp.Message p__parent = null, Linux p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _memTotal = m_io.ReadU2le();
                _pcpu = m_io.ReadU1();
                _pmem = m_io.ReadU1();
                _procsStarting = m_io.ReadU2le();
                _procsStopping = m_io.ReadU2le();
                _pidCount = m_io.ReadU2le();
                _time = m_io.ReadU4le();
                _flags = m_io.ReadU1();
            }
            private ushort _memTotal;
            private byte _pcpu;
            private byte _pmem;
            private ushort _procsStarting;
            private ushort _procsStopping;
            private ushort _pidCount;
            private uint _time;
            private byte _flags;
            private Linux m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// total system memory, in MiB
            /// </summary>
            public ushort MemTotal { get { return _memTotal; } }

            /// <summary>
            /// percent of CPU used, expressed as a fraction of 256
            /// </summary>
            public byte Pcpu { get { return _pcpu; } }

            /// <summary>
            /// percent of memory used, expressed as a fraction of 256
            /// </summary>
            public byte Pmem { get { return _pmem; } }

            /// <summary>
            /// number of processes that started during collection phase
            /// </summary>
            public ushort ProcsStarting { get { return _procsStarting; } }

            /// <summary>
            /// number of processes that stopped during collection phase
            /// </summary>
            public ushort ProcsStopping { get { return _procsStopping; } }

            /// <summary>
            /// the count of processes on the system
            /// </summary>
            public ushort PidCount { get { return _pidCount; } }

            /// <summary>
            /// timestamp of message, refer to flags field for how to interpret
            /// </summary>
            public uint Time { get { return _time; } }

            /// <summary>
            /// flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Linux M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgLinuxCpuStateDepA : KaitaiStruct
        {
            public static MsgLinuxCpuStateDepA FromFile(string fileName)
            {
                return new MsgLinuxCpuStateDepA(new KaitaiStream(fileName));
            }

            public MsgLinuxCpuStateDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Linux p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _index = m_io.ReadU1();
                _pid = m_io.ReadU2le();
                _pcpu = m_io.ReadU1();
                _tname = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytes(15));
                _cmdline = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private byte _index;
            private ushort _pid;
            private byte _pcpu;
            private string _tname;
            private string _cmdline;
            private Linux m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// sequence of this status message, values from 0-9
            /// </summary>
            public byte Index { get { return _index; } }

            /// <summary>
            /// the PID of the process
            /// </summary>
            public ushort Pid { get { return _pid; } }

            /// <summary>
            /// percent of cpu used, expressed as a fraction of 256
            /// </summary>
            public byte Pcpu { get { return _pcpu; } }

            /// <summary>
            /// fixed length string representing the thread name
            /// </summary>
            public string Tname { get { return _tname; } }

            /// <summary>
            /// the command line (as much as it fits in the remaining packet)
            /// </summary>
            public string Cmdline { get { return _cmdline; } }
            public Linux M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message indicates the process state of the top 10 heaviest
        /// consumers of memory on the system, including a timestamp.
        /// </summary>
        public partial class MsgLinuxMemState : KaitaiStruct
        {
            public static MsgLinuxMemState FromFile(string fileName)
            {
                return new MsgLinuxMemState(new KaitaiStream(fileName));
            }

            public MsgLinuxMemState(KaitaiStream p__io, Sbp.Message p__parent = null, Linux p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _index = m_io.ReadU1();
                _pid = m_io.ReadU2le();
                _pmem = m_io.ReadU1();
                _time = m_io.ReadU4le();
                _flags = m_io.ReadU1();
                _tname = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytes(15));
                _cmdline = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private byte _index;
            private ushort _pid;
            private byte _pmem;
            private uint _time;
            private byte _flags;
            private string _tname;
            private string _cmdline;
            private Linux m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// sequence of this status message, values from 0-9
            /// </summary>
            public byte Index { get { return _index; } }

            /// <summary>
            /// the PID of the process
            /// </summary>
            public ushort Pid { get { return _pid; } }

            /// <summary>
            /// percent of memory used, expressed as a fraction of 256
            /// </summary>
            public byte Pmem { get { return _pmem; } }

            /// <summary>
            /// timestamp of message, refer to flags field for how to interpret
            /// </summary>
            public uint Time { get { return _time; } }

            /// <summary>
            /// flags
            /// </summary>
            public byte Flags { get { return _flags; } }

            /// <summary>
            /// fixed length string representing the thread name
            /// </summary>
            public string Tname { get { return _tname; } }

            /// <summary>
            /// the command line (as much as it fits in the remaining packet)
            /// </summary>
            public string Cmdline { get { return _cmdline; } }
            public Linux M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Top 10 list of processes with a large number of open file descriptors.
        /// </summary>
        public partial class MsgLinuxProcessFdCount : KaitaiStruct
        {
            public static MsgLinuxProcessFdCount FromFile(string fileName)
            {
                return new MsgLinuxProcessFdCount(new KaitaiStream(fileName));
            }

            public MsgLinuxProcessFdCount(KaitaiStream p__io, Sbp.Message p__parent = null, Linux p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _index = m_io.ReadU1();
                _pid = m_io.ReadU2le();
                _fdCount = m_io.ReadU2le();
                _cmdline = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private byte _index;
            private ushort _pid;
            private ushort _fdCount;
            private string _cmdline;
            private Linux m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// sequence of this status message, values from 0-9
            /// </summary>
            public byte Index { get { return _index; } }

            /// <summary>
            /// the PID of the process in question
            /// </summary>
            public ushort Pid { get { return _pid; } }

            /// <summary>
            /// a count of the number of file descriptors opened by the process
            /// </summary>
            public ushort FdCount { get { return _fdCount; } }

            /// <summary>
            /// the command line of the process in question
            /// </summary>
            public string Cmdline { get { return _cmdline; } }
            public Linux M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgLinuxMemStateDepA : KaitaiStruct
        {
            public static MsgLinuxMemStateDepA FromFile(string fileName)
            {
                return new MsgLinuxMemStateDepA(new KaitaiStream(fileName));
            }

            public MsgLinuxMemStateDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Linux p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _index = m_io.ReadU1();
                _pid = m_io.ReadU2le();
                _pmem = m_io.ReadU1();
                _tname = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytes(15));
                _cmdline = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private byte _index;
            private ushort _pid;
            private byte _pmem;
            private string _tname;
            private string _cmdline;
            private Linux m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// sequence of this status message, values from 0-9
            /// </summary>
            public byte Index { get { return _index; } }

            /// <summary>
            /// the PID of the process
            /// </summary>
            public ushort Pid { get { return _pid; } }

            /// <summary>
            /// percent of memory used, expressed as a fraction of 256
            /// </summary>
            public byte Pmem { get { return _pmem; } }

            /// <summary>
            /// fixed length string representing the thread name
            /// </summary>
            public string Tname { get { return _tname; } }

            /// <summary>
            /// the command line (as much as it fits in the remaining packet)
            /// </summary>
            public string Cmdline { get { return _cmdline; } }
            public Linux M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Top 10 list of sockets with deep queues.
        /// </summary>
        public partial class MsgLinuxProcessSocketQueues : KaitaiStruct
        {
            public static MsgLinuxProcessSocketQueues FromFile(string fileName)
            {
                return new MsgLinuxProcessSocketQueues(new KaitaiStream(fileName));
            }

            public MsgLinuxProcessSocketQueues(KaitaiStream p__io, Sbp.Message p__parent = null, Linux p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _index = m_io.ReadU1();
                _pid = m_io.ReadU2le();
                _recvQueued = m_io.ReadU2le();
                _sendQueued = m_io.ReadU2le();
                _socketTypes = m_io.ReadU2le();
                _socketStates = m_io.ReadU2le();
                _addressOfLargest = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytes(64));
                _cmdline = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private byte _index;
            private ushort _pid;
            private ushort _recvQueued;
            private ushort _sendQueued;
            private ushort _socketTypes;
            private ushort _socketStates;
            private string _addressOfLargest;
            private string _cmdline;
            private Linux m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// sequence of this status message, values from 0-9
            /// </summary>
            public byte Index { get { return _index; } }

            /// <summary>
            /// the PID of the process in question
            /// </summary>
            public ushort Pid { get { return _pid; } }

            /// <summary>
            /// the total amount of receive data queued for this process
            /// </summary>
            public ushort RecvQueued { get { return _recvQueued; } }

            /// <summary>
            /// the total amount of send data queued for this process
            /// </summary>
            public ushort SendQueued { get { return _sendQueued; } }

            /// <summary>
            /// A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
            /// 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
            /// (unknown)
            /// </summary>
            public ushort SocketTypes { get { return _socketTypes; } }

            /// <summary>
            /// A bitfield indicating the socket states: 0x1 (established), 0x2
            /// (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
            /// 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
            /// ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
            /// 0x8000 (unknown)
            /// </summary>
            public ushort SocketStates { get { return _socketStates; } }

            /// <summary>
            /// Address of the largest queue, remote or local depending on the
            /// directionality of the connection.
            /// </summary>
            public string AddressOfLargest { get { return _addressOfLargest; } }

            /// <summary>
            /// the command line of the process in question
            /// </summary>
            public string Cmdline { get { return _cmdline; } }
            public Linux M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgLinuxSysStateDepA : KaitaiStruct
        {
            public static MsgLinuxSysStateDepA FromFile(string fileName)
            {
                return new MsgLinuxSysStateDepA(new KaitaiStream(fileName));
            }

            public MsgLinuxSysStateDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Linux p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _memTotal = m_io.ReadU2le();
                _pcpu = m_io.ReadU1();
                _pmem = m_io.ReadU1();
                _procsStarting = m_io.ReadU2le();
                _procsStopping = m_io.ReadU2le();
                _pidCount = m_io.ReadU2le();
            }
            private ushort _memTotal;
            private byte _pcpu;
            private byte _pmem;
            private ushort _procsStarting;
            private ushort _procsStopping;
            private ushort _pidCount;
            private Linux m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// total system memory
            /// </summary>
            public ushort MemTotal { get { return _memTotal; } }

            /// <summary>
            /// percent of total cpu currently utilized
            /// </summary>
            public byte Pcpu { get { return _pcpu; } }

            /// <summary>
            /// percent of total memory currently utilized
            /// </summary>
            public byte Pmem { get { return _pmem; } }

            /// <summary>
            /// number of processes that started during collection phase
            /// </summary>
            public ushort ProcsStarting { get { return _procsStarting; } }

            /// <summary>
            /// number of processes that stopped during collection phase
            /// </summary>
            public ushort ProcsStopping { get { return _procsStopping; } }

            /// <summary>
            /// the count of processes on the system
            /// </summary>
            public ushort PidCount { get { return _pidCount; } }
            public Linux M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Summary of open file descriptors on the system.
        /// </summary>
        public partial class MsgLinuxProcessFdSummary : KaitaiStruct
        {
            public static MsgLinuxProcessFdSummary FromFile(string fileName)
            {
                return new MsgLinuxProcessFdSummary(new KaitaiStream(fileName));
            }

            public MsgLinuxProcessFdSummary(KaitaiStream p__io, Sbp.Message p__parent = null, Linux p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sysFdCount = m_io.ReadU4le();
                _mostOpened = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private uint _sysFdCount;
            private string _mostOpened;
            private Linux m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// count of total FDs open on the system
            /// </summary>
            public uint SysFdCount { get { return _sysFdCount; } }

            /// <summary>
            /// A null delimited list of strings which alternates between a string
            /// representation of the process count and the file name whose count it
            /// being reported.  That is, in C string syntax
            /// &quot;32\0/var/log/syslog\012\0/tmp/foo\0&quot; with the end of the list being
            /// 2 NULL terminators in a row.
            /// </summary>
            public string MostOpened { get { return _mostOpened; } }
            public Linux M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message indicates the process state of the top 10 heaviest
        /// consumers of CPU on the system, including a timestamp.
        /// </summary>
        public partial class MsgLinuxCpuState : KaitaiStruct
        {
            public static MsgLinuxCpuState FromFile(string fileName)
            {
                return new MsgLinuxCpuState(new KaitaiStream(fileName));
            }

            public MsgLinuxCpuState(KaitaiStream p__io, Sbp.Message p__parent = null, Linux p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _index = m_io.ReadU1();
                _pid = m_io.ReadU2le();
                _pcpu = m_io.ReadU1();
                _time = m_io.ReadU4le();
                _flags = m_io.ReadU1();
                _tname = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytes(15));
                _cmdline = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private byte _index;
            private ushort _pid;
            private byte _pcpu;
            private uint _time;
            private byte _flags;
            private string _tname;
            private string _cmdline;
            private Linux m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// sequence of this status message, values from 0-9
            /// </summary>
            public byte Index { get { return _index; } }

            /// <summary>
            /// the PID of the process
            /// </summary>
            public ushort Pid { get { return _pid; } }

            /// <summary>
            /// percent of CPU used, expressed as a fraction of 256
            /// </summary>
            public byte Pcpu { get { return _pcpu; } }

            /// <summary>
            /// timestamp of message, refer to flags field for how to interpret
            /// </summary>
            public uint Time { get { return _time; } }

            /// <summary>
            /// flags
            /// </summary>
            public byte Flags { get { return _flags; } }

            /// <summary>
            /// fixed length string representing the thread name
            /// </summary>
            public string Tname { get { return _tname; } }

            /// <summary>
            /// the command line (as much as it fits in the remaining packet)
            /// </summary>
            public string Cmdline { get { return _cmdline; } }
            public Linux M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Top 10 list of processes with high socket counts.
        /// </summary>
        public partial class MsgLinuxProcessSocketCounts : KaitaiStruct
        {
            public static MsgLinuxProcessSocketCounts FromFile(string fileName)
            {
                return new MsgLinuxProcessSocketCounts(new KaitaiStream(fileName));
            }

            public MsgLinuxProcessSocketCounts(KaitaiStream p__io, Sbp.Message p__parent = null, Linux p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _index = m_io.ReadU1();
                _pid = m_io.ReadU2le();
                _socketCount = m_io.ReadU2le();
                _socketTypes = m_io.ReadU2le();
                _socketStates = m_io.ReadU2le();
                _cmdline = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private byte _index;
            private ushort _pid;
            private ushort _socketCount;
            private ushort _socketTypes;
            private ushort _socketStates;
            private string _cmdline;
            private Linux m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// sequence of this status message, values from 0-9
            /// </summary>
            public byte Index { get { return _index; } }

            /// <summary>
            /// the PID of the process in question
            /// </summary>
            public ushort Pid { get { return _pid; } }

            /// <summary>
            /// the number of sockets the process is using
            /// </summary>
            public ushort SocketCount { get { return _socketCount; } }

            /// <summary>
            /// A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
            /// 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
            /// (unknown)
            /// </summary>
            public ushort SocketTypes { get { return _socketTypes; } }

            /// <summary>
            /// A bitfield indicating the socket states: 0x1 (established), 0x2
            /// (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
            /// 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
            /// ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
            /// 0x8000 (unknown)
            /// </summary>
            public ushort SocketStates { get { return _socketStates; } }

            /// <summary>
            /// the command line of the process in question
            /// </summary>
            public string Cmdline { get { return _cmdline; } }
            public Linux M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        private Linux m_root;
        private KaitaiStruct m_parent;
        public Linux M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
