// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class Piksi : KaitaiStruct
    {
        public static Piksi FromFile(string fileName)
        {
            return new Piksi(new KaitaiStream(fileName));
        }

        public Piksi(KaitaiStream p__io, KaitaiStruct p__parent = null, Piksi p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// The state of a network interface on the Piksi. Data is made to reflect
        /// output of ifaddrs struct returned by getifaddrs in c.
        /// </summary>
        public partial class MsgNetworkStateResp : KaitaiStruct
        {
            public static MsgNetworkStateResp FromFile(string fileName)
            {
                return new MsgNetworkStateResp(new KaitaiStream(fileName));
            }

            public MsgNetworkStateResp(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _ipv4Address = new List<byte>();
                for (var i = 0; i < 4; i++)
                {
                    _ipv4Address.Add(m_io.ReadU1());
                }
                _ipv4MaskSize = m_io.ReadU1();
                _ipv6Address = new List<byte>();
                for (var i = 0; i < 16; i++)
                {
                    _ipv6Address.Add(m_io.ReadU1());
                }
                _ipv6MaskSize = m_io.ReadU1();
                _rxBytes = m_io.ReadU4le();
                _txBytes = m_io.ReadU4le();
                _interfaceName = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytes(16));
                _flags = m_io.ReadU4le();
            }
            private List<byte> _ipv4Address;
            private byte _ipv4MaskSize;
            private List<byte> _ipv6Address;
            private byte _ipv6MaskSize;
            private uint _rxBytes;
            private uint _txBytes;
            private string _interfaceName;
            private uint _flags;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// IPv4 address (all zero when unavailable)
            /// </summary>
            public List<byte> Ipv4Address { get { return _ipv4Address; } }

            /// <summary>
            /// IPv4 netmask CIDR notation
            /// </summary>
            public byte Ipv4MaskSize { get { return _ipv4MaskSize; } }

            /// <summary>
            /// IPv6 address (all zero when unavailable)
            /// </summary>
            public List<byte> Ipv6Address { get { return _ipv6Address; } }

            /// <summary>
            /// IPv6 netmask CIDR notation
            /// </summary>
            public byte Ipv6MaskSize { get { return _ipv6MaskSize; } }

            /// <summary>
            /// Number of Rx bytes
            /// </summary>
            public uint RxBytes { get { return _rxBytes; } }

            /// <summary>
            /// Number of Tx bytes
            /// </summary>
            public uint TxBytes { get { return _txBytes; } }

            /// <summary>
            /// Interface Name
            /// </summary>
            public string InterfaceName { get { return _interfaceName; } }

            /// <summary>
            /// Interface flags from SIOCGIFFLAGS
            /// </summary>
            public uint Flags { get { return _flags; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The bandwidth usage for each interface can be reported within this
        /// struct and utilize multiple fields to fully specify the type of traffic
        /// that is being tracked. As either the interval of collection or the
        /// collection time may vary, both a timestamp and period field is provided,
        /// though may not necessarily be populated with a value.
        /// </summary>
        public partial class NetworkUsage : KaitaiStruct
        {
            public static NetworkUsage FromFile(string fileName)
            {
                return new NetworkUsage(new KaitaiStream(fileName));
            }

            public NetworkUsage(KaitaiStream p__io, Piksi.MsgNetworkBandwidthUsage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _duration = m_io.ReadU8le();
                _totalBytes = m_io.ReadU8le();
                _rxBytes = m_io.ReadU4le();
                _txBytes = m_io.ReadU4le();
                _interfaceName = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytes(16));
            }
            private ulong _duration;
            private ulong _totalBytes;
            private uint _rxBytes;
            private uint _txBytes;
            private string _interfaceName;
            private Piksi m_root;
            private Piksi.MsgNetworkBandwidthUsage m_parent;

            /// <summary>
            /// Duration over which the measurement was collected
            /// </summary>
            public ulong Duration { get { return _duration; } }

            /// <summary>
            /// Number of bytes handled in total within period
            /// </summary>
            public ulong TotalBytes { get { return _totalBytes; } }

            /// <summary>
            /// Number of bytes transmitted within period
            /// </summary>
            public uint RxBytes { get { return _rxBytes; } }

            /// <summary>
            /// Number of bytes received within period
            /// </summary>
            public uint TxBytes { get { return _txBytes; } }

            /// <summary>
            /// Interface Name
            /// </summary>
            public string InterfaceName { get { return _interfaceName; } }
            public Piksi M_Root { get { return m_root; } }
            public Piksi.MsgNetworkBandwidthUsage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The response to MSG_COMMAND_REQ with the return code of the command.  A
        /// return code of zero indicates success.
        /// </summary>
        public partial class MsgCommandResp : KaitaiStruct
        {
            public static MsgCommandResp FromFile(string fileName)
            {
                return new MsgCommandResp(new KaitaiStream(fileName));
            }

            public MsgCommandResp(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sequence = m_io.ReadU4le();
                _code = m_io.ReadS4le();
            }
            private uint _sequence;
            private int _code;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Sequence number
            /// </summary>
            public uint Sequence { get { return _sequence; } }

            /// <summary>
            /// Exit code
            /// </summary>
            public int Code { get { return _code; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Returns the standard output and standard error of the command requested
        /// by MSG_COMMAND_REQ. The sequence number can be used to filter for
        /// filtering the correct command.
        /// </summary>
        public partial class MsgCommandOutput : KaitaiStruct
        {
            public static MsgCommandOutput FromFile(string fileName)
            {
                return new MsgCommandOutput(new KaitaiStream(fileName));
            }

            public MsgCommandOutput(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sequence = m_io.ReadU4le();
                _line = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private uint _sequence;
            private string _line;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Sequence number
            /// </summary>
            public uint Sequence { get { return _sequence; } }

            /// <summary>
            /// Line of standard output or standard error
            /// </summary>
            public string Line { get { return _line; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Statistics on the latency of observations received from the base
        /// station. As observation packets are received their GPS time is compared
        /// to the current GPS time calculated locally by the receiver to give a
        /// precise measurement of the end-to-end communication latency in the
        /// system.
        /// </summary>
        public partial class Latency : KaitaiStruct
        {
            public static Latency FromFile(string fileName)
            {
                return new Latency(new KaitaiStream(fileName));
            }

            public Latency(KaitaiStream p__io, KaitaiStruct p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _avg = m_io.ReadS4le();
                _lmin = m_io.ReadS4le();
                _lmax = m_io.ReadS4le();
                _current = m_io.ReadS4le();
            }
            private int _avg;
            private int _lmin;
            private int _lmax;
            private int _current;
            private Piksi m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// Average latency
            /// </summary>
            public int Avg { get { return _avg; } }

            /// <summary>
            /// Minimum latency
            /// </summary>
            public int Lmin { get { return _lmin; } }

            /// <summary>
            /// Maximum latency
            /// </summary>
            public int Lmax { get { return _lmax; } }

            /// <summary>
            /// Smoothed estimate of the current latency
            /// </summary>
            public int Current { get { return _current; } }
            public Piksi M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The thread usage message from the device reports real-time operating
        /// system (RTOS) thread usage statistics for the named thread. The reported
        /// percentage values must be normalized.
        /// </summary>
        public partial class MsgThreadState : KaitaiStruct
        {
            public static MsgThreadState FromFile(string fileName)
            {
                return new MsgThreadState(new KaitaiStream(fileName));
            }

            public MsgThreadState(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _name = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytes(20));
                _cpu = m_io.ReadU2le();
                _stackFree = m_io.ReadU4le();
            }
            private string _name;
            private ushort _cpu;
            private uint _stackFree;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Thread name (NULL terminated)
            /// </summary>
            public string Name { get { return _name; } }

            /// <summary>
            /// Percentage cpu use for this thread. Values range from 0 - 1000 and
            /// needs to be renormalized to 100
            /// </summary>
            public ushort Cpu { get { return _cpu; } }

            /// <summary>
            /// Free stack space for this thread
            /// </summary>
            public uint StackFree { get { return _stackFree; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgUartStateDepa : KaitaiStruct
        {
            public static MsgUartStateDepa FromFile(string fileName)
            {
                return new MsgUartStateDepa(new KaitaiStream(fileName));
            }

            public MsgUartStateDepa(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _uartA = new UartChannel(m_io, this, m_root);
                _uartB = new UartChannel(m_io, this, m_root);
                _uartFtdi = new UartChannel(m_io, this, m_root);
                _latency = new Latency(m_io, this, m_root);
            }
            private UartChannel _uartA;
            private UartChannel _uartB;
            private UartChannel _uartFtdi;
            private Latency _latency;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// State of UART A
            /// </summary>
            public UartChannel UartA { get { return _uartA; } }

            /// <summary>
            /// State of UART B
            /// </summary>
            public UartChannel UartB { get { return _uartB; } }

            /// <summary>
            /// State of UART FTDI (USB logger)
            /// </summary>
            public UartChannel UartFtdi { get { return _uartFtdi; } }

            /// <summary>
            /// UART communication latency
            /// </summary>
            public Latency Latency { get { return _latency; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Request state of Piksi network interfaces. Output will be sent in
        /// MSG_NETWORK_STATE_RESP messages.
        /// </summary>
        public partial class MsgNetworkStateReq : KaitaiStruct
        {
            public static MsgNetworkStateReq FromFile(string fileName)
            {
                return new MsgNetworkStateReq(new KaitaiStream(fileName));
            }

            public MsgNetworkStateReq(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
            }
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message contains temperature and voltage level measurements from
        /// the processor's monitoring system and the RF frontend die temperature if
        /// available.
        /// </summary>
        public partial class MsgDeviceMonitor : KaitaiStruct
        {
            public static MsgDeviceMonitor FromFile(string fileName)
            {
                return new MsgDeviceMonitor(new KaitaiStream(fileName));
            }

            public MsgDeviceMonitor(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _devVin = m_io.ReadS2le();
                _cpuVint = m_io.ReadS2le();
                _cpuVaux = m_io.ReadS2le();
                _cpuTemperature = m_io.ReadS2le();
                _feTemperature = m_io.ReadS2le();
            }
            private short _devVin;
            private short _cpuVint;
            private short _cpuVaux;
            private short _cpuTemperature;
            private short _feTemperature;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Device V_in
            /// </summary>
            public short DevVin { get { return _devVin; } }

            /// <summary>
            /// Processor V_int
            /// </summary>
            public short CpuVint { get { return _cpuVint; } }

            /// <summary>
            /// Processor V_aux
            /// </summary>
            public short CpuVaux { get { return _cpuVaux; } }

            /// <summary>
            /// Processor temperature
            /// </summary>
            public short CpuTemperature { get { return _cpuTemperature; } }

            /// <summary>
            /// Frontend temperature (if available)
            /// </summary>
            public short FeTemperature { get { return _feTemperature; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgMaskSatelliteDep : KaitaiStruct
        {
            public static MsgMaskSatelliteDep FromFile(string fileName)
            {
                return new MsgMaskSatelliteDep(new KaitaiStream(fileName));
            }

            public MsgMaskSatelliteDep(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _mask = m_io.ReadU1();
                _sid = new Gnss.GnssSignalDep(m_io, this, m_root);
            }
            private byte _mask;
            private Gnss.GnssSignalDep _sid;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Mask of systems that should ignore this satellite.
            /// </summary>
            public byte Mask { get { return _mask; } }

            /// <summary>
            /// GNSS signal for which the mask is applied
            /// </summary>
            public Gnss.GnssSignalDep Sid { get { return _sid; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The UART message reports data latency and throughput of the UART
        /// channels providing SBP I/O. On the default Piksi configuration, UARTs A
        /// and B are used for telemetry radios, but can also be host access ports
        /// for embedded hosts, or other interfaces in future. The reported
        /// percentage values must be normalized. Observations latency and period
        /// can be used to assess the health of the differential corrections link.
        /// Latency provides the timeliness of received base observations while the
        /// period indicates their likelihood of transmission.
        /// </summary>
        public partial class MsgUartState : KaitaiStruct
        {
            public static MsgUartState FromFile(string fileName)
            {
                return new MsgUartState(new KaitaiStream(fileName));
            }

            public MsgUartState(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _uartA = new UartChannel(m_io, this, m_root);
                _uartB = new UartChannel(m_io, this, m_root);
                _uartFtdi = new UartChannel(m_io, this, m_root);
                _latency = new Latency(m_io, this, m_root);
                _obsPeriod = new Period(m_io, this, m_root);
            }
            private UartChannel _uartA;
            private UartChannel _uartB;
            private UartChannel _uartFtdi;
            private Latency _latency;
            private Period _obsPeriod;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// State of UART A
            /// </summary>
            public UartChannel UartA { get { return _uartA; } }

            /// <summary>
            /// State of UART B
            /// </summary>
            public UartChannel UartB { get { return _uartB; } }

            /// <summary>
            /// State of UART FTDI (USB logger)
            /// </summary>
            public UartChannel UartFtdi { get { return _uartFtdi; } }

            /// <summary>
            /// UART communication latency
            /// </summary>
            public Latency Latency { get { return _latency; } }

            /// <summary>
            /// Observation receipt period
            /// </summary>
            public Period ObsPeriod { get { return _obsPeriod; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Spectrum analyzer packet.
        /// </summary>
        public partial class MsgSpecan : KaitaiStruct
        {
            public static MsgSpecan FromFile(string fileName)
            {
                return new MsgSpecan(new KaitaiStream(fileName));
            }

            public MsgSpecan(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _channelTag = m_io.ReadU2le();
                _t = new Gnss.GpsTime(m_io, this, m_root);
                _freqRef = m_io.ReadF4le();
                _freqStep = m_io.ReadF4le();
                _amplitudeRef = m_io.ReadF4le();
                _amplitudeUnit = m_io.ReadF4le();
                _amplitudeValue = new List<byte>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _amplitudeValue.Add(m_io.ReadU1());
                        i++;
                    }
                }
            }
            private ushort _channelTag;
            private Gnss.GpsTime _t;
            private float _freqRef;
            private float _freqStep;
            private float _amplitudeRef;
            private float _amplitudeUnit;
            private List<byte> _amplitudeValue;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Channel ID
            /// </summary>
            public ushort ChannelTag { get { return _channelTag; } }

            /// <summary>
            /// Receiver time of this observation
            /// </summary>
            public Gnss.GpsTime T { get { return _t; } }

            /// <summary>
            /// Reference frequency of this packet
            /// </summary>
            public float FreqRef { get { return _freqRef; } }

            /// <summary>
            /// Frequency step of points in this packet
            /// </summary>
            public float FreqStep { get { return _freqStep; } }

            /// <summary>
            /// Reference amplitude of this packet
            /// </summary>
            public float AmplitudeRef { get { return _amplitudeRef; } }

            /// <summary>
            /// Amplitude unit value of points in this packet
            /// </summary>
            public float AmplitudeUnit { get { return _amplitudeUnit; } }

            /// <summary>
            /// Amplitude values (in the above units) of points in this packet
            /// </summary>
            public List<byte> AmplitudeValue { get { return _amplitudeValue; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the state of the Integer Ambiguity Resolution (IAR)
        /// process, which resolves unknown integer ambiguities from double-
        /// differenced carrier-phase measurements from satellite observations.
        /// </summary>
        public partial class MsgIarState : KaitaiStruct
        {
            public static MsgIarState FromFile(string fileName)
            {
                return new MsgIarState(new KaitaiStream(fileName));
            }

            public MsgIarState(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _numHyps = m_io.ReadU4le();
            }
            private uint _numHyps;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Number of integer ambiguity hypotheses remaining
            /// </summary>
            public uint NumHyps { get { return _numHyps; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This is a legacy message for sending and loading a satellite alamanac
        /// onto the Piksi's flash memory from the host.
        /// </summary>
        public partial class MsgAlmanac : KaitaiStruct
        {
            public static MsgAlmanac FromFile(string fileName)
            {
                return new MsgAlmanac(new KaitaiStream(fileName));
            }

            public MsgAlmanac(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
            }
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message resets either the DGNSS Kalman filters or Integer Ambiguity
        /// Resolution (IAR) process.
        /// </summary>
        public partial class MsgResetFilters : KaitaiStruct
        {
            public static MsgResetFilters FromFile(string fileName)
            {
                return new MsgResetFilters(new KaitaiStream(fileName));
            }

            public MsgResetFilters(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _filter = m_io.ReadU1();
            }
            private byte _filter;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Filter flags
            /// </summary>
            public byte Filter { get { return _filter; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Throughput, utilization, and error counts on the RX/TX buffers of this
        /// UART channel. The reported percentage values must be normalized.
        /// </summary>
        public partial class UartChannel : KaitaiStruct
        {
            public static UartChannel FromFile(string fileName)
            {
                return new UartChannel(new KaitaiStream(fileName));
            }

            public UartChannel(KaitaiStream p__io, KaitaiStruct p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _txThroughput = m_io.ReadF4le();
                _rxThroughput = m_io.ReadF4le();
                _crcErrorCount = m_io.ReadU2le();
                _ioErrorCount = m_io.ReadU2le();
                _txBufferLevel = m_io.ReadU1();
                _rxBufferLevel = m_io.ReadU1();
            }
            private float _txThroughput;
            private float _rxThroughput;
            private ushort _crcErrorCount;
            private ushort _ioErrorCount;
            private byte _txBufferLevel;
            private byte _rxBufferLevel;
            private Piksi m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// UART transmit throughput
            /// </summary>
            public float TxThroughput { get { return _txThroughput; } }

            /// <summary>
            /// UART receive throughput
            /// </summary>
            public float RxThroughput { get { return _rxThroughput; } }

            /// <summary>
            /// UART CRC error count
            /// </summary>
            public ushort CrcErrorCount { get { return _crcErrorCount; } }

            /// <summary>
            /// UART IO error count
            /// </summary>
            public ushort IoErrorCount { get { return _ioErrorCount; } }

            /// <summary>
            /// UART transmit buffer percentage utilization (ranges from 0 to 255)
            /// </summary>
            public byte TxBufferLevel { get { return _txBufferLevel; } }

            /// <summary>
            /// UART receive buffer percentage utilization (ranges from 0 to 255)
            /// </summary>
            public byte RxBufferLevel { get { return _rxBufferLevel; } }
            public Piksi M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Request the recipient to execute an command. Output will be sent in
        /// MSG_LOG messages, and the exit code will be returned with
        /// MSG_COMMAND_RESP.
        /// </summary>
        public partial class MsgCommandReq : KaitaiStruct
        {
            public static MsgCommandReq FromFile(string fileName)
            {
                return new MsgCommandReq(new KaitaiStream(fileName));
            }

            public MsgCommandReq(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sequence = m_io.ReadU4le();
                _command = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private uint _sequence;
            private string _command;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Sequence number
            /// </summary>
            public uint Sequence { get { return _sequence; } }

            /// <summary>
            /// Command line to execute
            /// </summary>
            public string Command { get { return _command; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message allows setting a mask to prevent a particular satellite
        /// from being used in various Piksi subsystems.
        /// </summary>
        public partial class MsgMaskSatellite : KaitaiStruct
        {
            public static MsgMaskSatellite FromFile(string fileName)
            {
                return new MsgMaskSatellite(new KaitaiStream(fileName));
            }

            public MsgMaskSatellite(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _mask = m_io.ReadU1();
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
            }
            private byte _mask;
            private Gnss.GnssSignal _sid;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Mask of systems that should ignore this satellite.
            /// </summary>
            public byte Mask { get { return _mask; } }

            /// <summary>
            /// GNSS signal for which the mask is applied
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The bandwidth usage, a list of usage by interface.
        /// </summary>
        public partial class MsgNetworkBandwidthUsage : KaitaiStruct
        {
            public static MsgNetworkBandwidthUsage FromFile(string fileName)
            {
                return new MsgNetworkBandwidthUsage(new KaitaiStream(fileName));
            }

            public MsgNetworkBandwidthUsage(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _interfaces = new List<NetworkUsage>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _interfaces.Add(new NetworkUsage(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private List<NetworkUsage> _interfaces;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Usage measurement array
            /// </summary>
            public List<NetworkUsage> Interfaces { get { return _interfaces; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message from the host resets the Piksi back into the bootloader.
        /// </summary>
        public partial class MsgReset : KaitaiStruct
        {
            public static MsgReset FromFile(string fileName)
            {
                return new MsgReset(new KaitaiStream(fileName));
            }

            public MsgReset(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _flags = m_io.ReadU4le();
            }
            private uint _flags;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Reset flags
            /// </summary>
            public uint Flags { get { return _flags; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// If a cell modem is present on a piksi device, this message will be send
        /// periodically to update the host on the status of the modem and its
        /// various parameters.
        /// </summary>
        public partial class MsgCellModemStatus : KaitaiStruct
        {
            public static MsgCellModemStatus FromFile(string fileName)
            {
                return new MsgCellModemStatus(new KaitaiStream(fileName));
            }

            public MsgCellModemStatus(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _signalStrength = m_io.ReadS1();
                _signalErrorRate = m_io.ReadF4le();
                _reserved = new List<byte>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _reserved.Add(m_io.ReadU1());
                        i++;
                    }
                }
            }
            private sbyte _signalStrength;
            private float _signalErrorRate;
            private List<byte> _reserved;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Received cell signal strength in dBm, zero translates to unknown
            /// </summary>
            public sbyte SignalStrength { get { return _signalStrength; } }

            /// <summary>
            /// BER as reported by the modem, zero translates to unknown
            /// </summary>
            public float SignalErrorRate { get { return _signalErrorRate; } }

            /// <summary>
            /// Unspecified data TBD for this schema
            /// </summary>
            public List<byte> Reserved { get { return _reserved; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message describes the gain of each channel in the receiver
        /// frontend. Each gain is encoded as a non-dimensional percentage relative
        /// to the maximum range possible for the gain stage of the frontend. By
        /// convention, each gain array has 8 entries and the index of the array
        /// corresponding to the index of the rf channel in the frontend. A gain of
        /// 127 percent encodes that rf channel is not present in the hardware. A
        /// negative value implies an error for the particular gain stage as
        /// reported by the frontend.
        /// </summary>
        public partial class MsgFrontEndGain : KaitaiStruct
        {
            public static MsgFrontEndGain FromFile(string fileName)
            {
                return new MsgFrontEndGain(new KaitaiStream(fileName));
            }

            public MsgFrontEndGain(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _rfGain = new List<sbyte>();
                for (var i = 0; i < 8; i++)
                {
                    _rfGain.Add(m_io.ReadS1());
                }
                _ifGain = new List<sbyte>();
                for (var i = 0; i < 8; i++)
                {
                    _ifGain.Add(m_io.ReadS1());
                }
            }
            private List<sbyte> _rfGain;
            private List<sbyte> _ifGain;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// RF gain for each frontend channel
            /// </summary>
            public List<sbyte> RfGain { get { return _rfGain; } }

            /// <summary>
            /// Intermediate frequency gain for each frontend channel
            /// </summary>
            public List<sbyte> IfGain { get { return _ifGain; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgResetDep : KaitaiStruct
        {
            public static MsgResetDep FromFile(string fileName)
            {
                return new MsgResetDep(new KaitaiStream(fileName));
            }

            public MsgResetDep(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
            }
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message sets up timing functionality using a coarse GPS time
        /// estimate sent by the host.
        /// </summary>
        public partial class MsgSetTime : KaitaiStruct
        {
            public static MsgSetTime FromFile(string fileName)
            {
                return new MsgSetTime(new KaitaiStream(fileName));
            }

            public MsgSetTime(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
            }
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This is an unused legacy message for result reporting from the CW
        /// interference channel on the SwiftNAP. This message will be removed in a
        /// future release.
        /// </summary>
        public partial class MsgCwResults : KaitaiStruct
        {
            public static MsgCwResults FromFile(string fileName)
            {
                return new MsgCwResults(new KaitaiStream(fileName));
            }

            public MsgCwResults(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
            }
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgSpecanDep : KaitaiStruct
        {
            public static MsgSpecanDep FromFile(string fileName)
            {
                return new MsgSpecanDep(new KaitaiStream(fileName));
            }

            public MsgSpecanDep(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _channelTag = m_io.ReadU2le();
                _t = new Gnss.GpsTimeDep(m_io, this, m_root);
                _freqRef = m_io.ReadF4le();
                _freqStep = m_io.ReadF4le();
                _amplitudeRef = m_io.ReadF4le();
                _amplitudeUnit = m_io.ReadF4le();
                _amplitudeValue = new List<byte>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _amplitudeValue.Add(m_io.ReadU1());
                        i++;
                    }
                }
            }
            private ushort _channelTag;
            private Gnss.GpsTimeDep _t;
            private float _freqRef;
            private float _freqStep;
            private float _amplitudeRef;
            private float _amplitudeUnit;
            private List<byte> _amplitudeValue;
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Channel ID
            /// </summary>
            public ushort ChannelTag { get { return _channelTag; } }

            /// <summary>
            /// Receiver time of this observation
            /// </summary>
            public Gnss.GpsTimeDep T { get { return _t; } }

            /// <summary>
            /// Reference frequency of this packet
            /// </summary>
            public float FreqRef { get { return _freqRef; } }

            /// <summary>
            /// Frequency step of points in this packet
            /// </summary>
            public float FreqStep { get { return _freqStep; } }

            /// <summary>
            /// Reference amplitude of this packet
            /// </summary>
            public float AmplitudeRef { get { return _amplitudeRef; } }

            /// <summary>
            /// Amplitude unit value of points in this packet
            /// </summary>
            public float AmplitudeUnit { get { return _amplitudeUnit; } }

            /// <summary>
            /// Amplitude values (in the above units) of points in this packet
            /// </summary>
            public List<byte> AmplitudeValue { get { return _amplitudeValue; } }
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgInitBaseDep : KaitaiStruct
        {
            public static MsgInitBaseDep FromFile(string fileName)
            {
                return new MsgInitBaseDep(new KaitaiStream(fileName));
            }

            public MsgInitBaseDep(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
            }
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Statistics on the period of observations received from the base station.
        /// As complete observation sets are received, their time of reception is
        /// compared with the prior set''s time of reception. This measurement
        /// provides a proxy for link quality as incomplete or missing sets will
        /// increase the period.  Long periods can cause momentary RTK solution
        /// outages.
        /// </summary>
        public partial class Period : KaitaiStruct
        {
            public static Period FromFile(string fileName)
            {
                return new Period(new KaitaiStream(fileName));
            }

            public Period(KaitaiStream p__io, Piksi.MsgUartState p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _avg = m_io.ReadS4le();
                _pmin = m_io.ReadS4le();
                _pmax = m_io.ReadS4le();
                _current = m_io.ReadS4le();
            }
            private int _avg;
            private int _pmin;
            private int _pmax;
            private int _current;
            private Piksi m_root;
            private Piksi.MsgUartState m_parent;

            /// <summary>
            /// Average period
            /// </summary>
            public int Avg { get { return _avg; } }

            /// <summary>
            /// Minimum period
            /// </summary>
            public int Pmin { get { return _pmin; } }

            /// <summary>
            /// Maximum period
            /// </summary>
            public int Pmax { get { return _pmax; } }

            /// <summary>
            /// Smoothed estimate of the current period
            /// </summary>
            public int Current { get { return _current; } }
            public Piksi M_Root { get { return m_root; } }
            public Piksi.MsgUartState M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This is an unused legacy message from the host for starting the CW
        /// interference channel on the SwiftNAP. This message will be removed in a
        /// future release.
        /// </summary>
        public partial class MsgCwStart : KaitaiStruct
        {
            public static MsgCwStart FromFile(string fileName)
            {
                return new MsgCwStart(new KaitaiStream(fileName));
            }

            public MsgCwStart(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Piksi p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
            }
            private Piksi m_root;
            private Sbp.SbpMessage m_parent;
            public Piksi M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }
        private Piksi m_root;
        private KaitaiStruct m_parent;
        public Piksi M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
