// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class System : KaitaiStruct
    {
        public static System FromFile(string fileName)
        {
            return new System(new KaitaiStream(fileName));
        }

        public System(KaitaiStream p__io, KaitaiStruct p__parent = null, System p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// The heartbeat message is sent periodically to inform the host or other
        /// attached devices that the system is running. It is used to monitor
        /// system malfunctions. It also contains status flags that indicate to the
        /// host the status of the system and whether it is operating correctly.
        /// Currently, the expected heartbeat interval is 1 sec.
        /// 
        /// The system error flag is used to indicate that an error has occurred in
        /// the system. To determine the source of the error, the remaining error
        /// flags should be inspected.
        /// </summary>
        public partial class MsgHeartbeat : KaitaiStruct
        {
            public static MsgHeartbeat FromFile(string fileName)
            {
                return new MsgHeartbeat(new KaitaiStream(fileName));
            }

            public MsgHeartbeat(KaitaiStream p__io, Sbp.Message p__parent = null, System p__root = null) : base(p__io)
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
            private System m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Status flags
            /// </summary>
            public uint Flags { get { return _flags; } }
            public System M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The status journal message contains past status reports (see
        /// MSG_STATUS_REPORT) and functions as a error/event storage for telemetry
        /// purposes.
        /// </summary>
        public partial class MsgStatusJournal : KaitaiStruct
        {
            public static MsgStatusJournal FromFile(string fileName)
            {
                return new MsgStatusJournal(new KaitaiStream(fileName));
            }

            public MsgStatusJournal(KaitaiStream p__io, Sbp.Message p__parent = null, System p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _reportingSystem = m_io.ReadU2le();
                _sbpVersion = m_io.ReadU2le();
                _totalStatusReports = m_io.ReadU4le();
                _sequenceDescriptor = m_io.ReadU1();
                _journal = new List<StatusJournalItem>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _journal.Add(new StatusJournalItem(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private ushort _reportingSystem;
            private ushort _sbpVersion;
            private uint _totalStatusReports;
            private byte _sequenceDescriptor;
            private List<StatusJournalItem> _journal;
            private System m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Identity of reporting system
            /// </summary>
            public ushort ReportingSystem { get { return _reportingSystem; } }

            /// <summary>
            /// SBP protocol version
            /// </summary>
            public ushort SbpVersion { get { return _sbpVersion; } }

            /// <summary>
            /// Total number of status reports sent since system startup
            /// </summary>
            public uint TotalStatusReports { get { return _totalStatusReports; } }

            /// <summary>
            /// Index and number of messages in this sequence. First nibble is the
            /// size of the sequence (n), second nibble is the zero-indexed counter
            /// (ith packet of n)
            /// </summary>
            public byte SequenceDescriptor { get { return _sequenceDescriptor; } }

            /// <summary>
            /// Status journal
            /// </summary>
            public List<StatusJournalItem> Journal { get { return _journal; } }
            public System M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The INS status message describes the state of the operation and
        /// initialization of the inertial navigation system.
        /// </summary>
        public partial class MsgInsStatus : KaitaiStruct
        {
            public static MsgInsStatus FromFile(string fileName)
            {
                return new MsgInsStatus(new KaitaiStream(fileName));
            }

            public MsgInsStatus(KaitaiStream p__io, Sbp.Message p__parent = null, System p__root = null) : base(p__io)
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
            private System m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Status flags
            /// </summary>
            public uint Flags { get { return _flags; } }
            public System M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The GNSS time offset message contains the information that is needed to
        /// translate messages tagged with a local timestamp (e.g. IMU or wheeltick
        /// messages) to GNSS time for the sender producing this message.
        /// </summary>
        public partial class MsgGnssTimeOffset : KaitaiStruct
        {
            public static MsgGnssTimeOffset FromFile(string fileName)
            {
                return new MsgGnssTimeOffset(new KaitaiStream(fileName));
            }

            public MsgGnssTimeOffset(KaitaiStream p__io, Sbp.Message p__parent = null, System p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _weeks = m_io.ReadS2le();
                _milliseconds = m_io.ReadS4le();
                _microseconds = m_io.ReadS2le();
                _flags = m_io.ReadU1();
            }
            private short _weeks;
            private int _milliseconds;
            private short _microseconds;
            private byte _flags;
            private System m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Weeks portion of the time offset
            /// </summary>
            public short Weeks { get { return _weeks; } }

            /// <summary>
            /// Milliseconds portion of the time offset
            /// </summary>
            public int Milliseconds { get { return _milliseconds; } }

            /// <summary>
            /// Microseconds portion of the time offset
            /// </summary>
            public short Microseconds { get { return _microseconds; } }

            /// <summary>
            /// Status flags (reserved)
            /// </summary>
            public byte Flags { get { return _flags; } }
            public System M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The CSAC telemetry message has an implementation defined telemetry
        /// string from a device. It is not produced or available on general Swift
        /// Products. It is intended to be a low rate message for status purposes.
        /// </summary>
        public partial class MsgCsacTelemetry : KaitaiStruct
        {
            public static MsgCsacTelemetry FromFile(string fileName)
            {
                return new MsgCsacTelemetry(new KaitaiStream(fileName));
            }

            public MsgCsacTelemetry(KaitaiStream p__io, Sbp.Message p__parent = null, System p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _id = m_io.ReadU1();
                _telemetry = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private byte _id;
            private string _telemetry;
            private System m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Index representing the type of telemetry in use.  It is
            /// implementation defined.
            /// </summary>
            public byte Id { get { return _id; } }

            /// <summary>
            /// Comma separated list of values as defined by the index
            /// </summary>
            public string Telemetry { get { return _telemetry; } }
            public System M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The PPS time message contains the value of the sender's local time in
        /// microseconds at the moment a pulse is detected on the PPS input. This is
        /// to be used for syncronisation of sensor data sampled with a local
        /// timestamp (e.g. IMU or wheeltick messages) where GNSS time is unknown to
        /// the sender.
        /// 
        /// The local time used to timestamp the PPS pulse must be generated by the
        /// same clock which is used to timestamp the IMU/wheel sensor data and
        /// should follow the same roll-over rules.  A separate MSG_PPS_TIME message
        /// should be sent for each source of sensor data which uses PPS-relative
        /// timestamping.  The sender ID for each of these MSG_PPS_TIME messages
        /// should match the sender ID of the respective sensor data.
        /// </summary>
        public partial class MsgPpsTime : KaitaiStruct
        {
            public static MsgPpsTime FromFile(string fileName)
            {
                return new MsgPpsTime(new KaitaiStream(fileName));
            }

            public MsgPpsTime(KaitaiStream p__io, Sbp.Message p__parent = null, System p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _time = m_io.ReadU8le();
                _flags = m_io.ReadU1();
            }
            private ulong _time;
            private byte _flags;
            private System m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Local time in microseconds
            /// </summary>
            public ulong Time { get { return _time; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public System M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The INS update status message contains information about executed and
        /// rejected INS updates. This message is expected to be extended in the
        /// future as new types of measurements are being added.
        /// </summary>
        public partial class MsgInsUpdates : KaitaiStruct
        {
            public static MsgInsUpdates FromFile(string fileName)
            {
                return new MsgInsUpdates(new KaitaiStream(fileName));
            }

            public MsgInsUpdates(KaitaiStream p__io, Sbp.Message p__parent = null, System p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _gnsspos = m_io.ReadU1();
                _gnssvel = m_io.ReadU1();
                _wheelticks = m_io.ReadU1();
                _speed = m_io.ReadU1();
                _nhc = m_io.ReadU1();
                _zerovel = m_io.ReadU1();
            }
            private uint _tow;
            private byte _gnsspos;
            private byte _gnssvel;
            private byte _wheelticks;
            private byte _speed;
            private byte _nhc;
            private byte _zerovel;
            private System m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// GNSS position update status flags
            /// </summary>
            public byte Gnsspos { get { return _gnsspos; } }

            /// <summary>
            /// GNSS velocity update status flags
            /// </summary>
            public byte Gnssvel { get { return _gnssvel; } }

            /// <summary>
            /// Wheelticks update status flags
            /// </summary>
            public byte Wheelticks { get { return _wheelticks; } }

            /// <summary>
            /// Wheelticks update status flags
            /// </summary>
            public byte Speed { get { return _speed; } }

            /// <summary>
            /// NHC update status flags
            /// </summary>
            public byte Nhc { get { return _nhc; } }

            /// <summary>
            /// Zero velocity update status flags
            /// </summary>
            public byte Zerovel { get { return _zerovel; } }
            public System M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message provides information about the receipt of Differential
        /// corrections.  It is expected to be sent with each receipt of a complete
        /// corrections packet.
        /// </summary>
        public partial class MsgDgnssStatus : KaitaiStruct
        {
            public static MsgDgnssStatus FromFile(string fileName)
            {
                return new MsgDgnssStatus(new KaitaiStream(fileName));
            }

            public MsgDgnssStatus(KaitaiStream p__io, Sbp.Message p__parent = null, System p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _flags = m_io.ReadU1();
                _latency = m_io.ReadU2le();
                _numSignals = m_io.ReadU1();
                _source = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private byte _flags;
            private ushort _latency;
            private byte _numSignals;
            private string _source;
            private System m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }

            /// <summary>
            /// Latency of observation receipt
            /// </summary>
            public ushort Latency { get { return _latency; } }

            /// <summary>
            /// Number of signals from base station
            /// </summary>
            public byte NumSignals { get { return _numSignals; } }

            /// <summary>
            /// Corrections source string
            /// </summary>
            public string Source { get { return _source; } }
            public System M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The CSAC telemetry message provides labels for each member of the string
        /// produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a
        /// lower rate than the MSG_CSAC_TELEMETRY.
        /// </summary>
        public partial class MsgCsacTelemetryLabels : KaitaiStruct
        {
            public static MsgCsacTelemetryLabels FromFile(string fileName)
            {
                return new MsgCsacTelemetryLabels(new KaitaiStream(fileName));
            }

            public MsgCsacTelemetryLabels(KaitaiStream p__io, Sbp.Message p__parent = null, System p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _id = m_io.ReadU1();
                _telemetryLabels = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytesFull());
            }
            private byte _id;
            private string _telemetryLabels;
            private System m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Index representing the type of telemetry in use.  It is
            /// implementation defined.
            /// </summary>
            public byte Id { get { return _id; } }

            /// <summary>
            /// Comma separated list of telemetry field values
            /// </summary>
            public string TelemetryLabels { get { return _telemetryLabels; } }
            public System M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The system start-up message is sent once on system start-up. It notifies
        /// the host or other attached devices that the system has started and is
        /// now ready to respond to commands or configuration requests.
        /// </summary>
        public partial class MsgStartup : KaitaiStruct
        {
            public static MsgStartup FromFile(string fileName)
            {
                return new MsgStartup(new KaitaiStream(fileName));
            }

            public MsgStartup(KaitaiStream p__io, Sbp.Message p__parent = null, System p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _cause = m_io.ReadU1();
                _startupType = m_io.ReadU1();
                _reserved = m_io.ReadU2le();
            }
            private byte _cause;
            private byte _startupType;
            private ushort _reserved;
            private System m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Cause of startup
            /// </summary>
            public byte Cause { get { return _cause; } }

            /// <summary>
            /// Startup type
            /// </summary>
            public byte StartupType { get { return _startupType; } }

            /// <summary>
            /// Reserved
            /// </summary>
            public ushort Reserved { get { return _reserved; } }
            public System M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This leading message lists the time metadata of the Solution Group. It
        /// also lists the atomic contents (i.e. types of messages included) of the
        /// Solution Group.
        /// </summary>
        public partial class MsgGroupMeta : KaitaiStruct
        {
            public static MsgGroupMeta FromFile(string fileName)
            {
                return new MsgGroupMeta(new KaitaiStream(fileName));
            }

            public MsgGroupMeta(KaitaiStream p__io, Sbp.Message p__parent = null, System p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _groupId = m_io.ReadU1();
                _flags = m_io.ReadU1();
                _nGroupMsgs = m_io.ReadU1();
                _groupMsgs = new List<ushort>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _groupMsgs.Add(m_io.ReadU2le());
                        i++;
                    }
                }
            }
            private byte _groupId;
            private byte _flags;
            private byte _nGroupMsgs;
            private List<ushort> _groupMsgs;
            private System m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss
            /// </summary>
            public byte GroupId { get { return _groupId; } }

            /// <summary>
            /// Status flags (reserved)
            /// </summary>
            public byte Flags { get { return _flags; } }

            /// <summary>
            /// Size of list group_msgs
            /// </summary>
            public byte NGroupMsgs { get { return _nGroupMsgs; } }

            /// <summary>
            /// An in-order list of message types included in the Solution Group,
            /// including GROUP_META itself
            /// </summary>
            public List<ushort> GroupMsgs { get { return _groupMsgs; } }
            public System M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This diagnostic message contains state and update status information for
        /// all sensors that are being used by the fusion engine. This message will
        /// be generated asynchronously to the solution messages and will be emitted
        /// anytime a sensor update is being processed.
        /// </summary>
        public partial class MsgSensorAidEvent : KaitaiStruct
        {
            public static MsgSensorAidEvent FromFile(string fileName)
            {
                return new MsgSensorAidEvent(new KaitaiStream(fileName));
            }

            public MsgSensorAidEvent(KaitaiStream p__io, Sbp.Message p__parent = null, System p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _time = m_io.ReadU4le();
                _sensorType = m_io.ReadU1();
                _sensorId = m_io.ReadU2le();
                _sensorState = m_io.ReadU1();
                _nAvailableMeas = m_io.ReadU1();
                _nAttemptedMeas = m_io.ReadU1();
                _nAcceptedMeas = m_io.ReadU1();
                _flags = m_io.ReadU4le();
            }
            private uint _time;
            private byte _sensorType;
            private ushort _sensorId;
            private byte _sensorState;
            private byte _nAvailableMeas;
            private byte _nAttemptedMeas;
            private byte _nAcceptedMeas;
            private uint _flags;
            private System m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Update timestamp in milliseconds.
            /// </summary>
            public uint Time { get { return _time; } }

            /// <summary>
            /// Sensor type
            /// </summary>
            public byte SensorType { get { return _sensorType; } }

            /// <summary>
            /// Sensor identifier
            /// </summary>
            public ushort SensorId { get { return _sensorId; } }

            /// <summary>
            /// Reserved for future use
            /// </summary>
            public byte SensorState { get { return _sensorState; } }

            /// <summary>
            /// Number of available measurements in this epoch
            /// </summary>
            public byte NAvailableMeas { get { return _nAvailableMeas; } }

            /// <summary>
            /// Number of attempted measurements in this epoch
            /// </summary>
            public byte NAttemptedMeas { get { return _nAttemptedMeas; } }

            /// <summary>
            /// Number of accepted measurements in this epoch
            /// </summary>
            public byte NAcceptedMeas { get { return _nAcceptedMeas; } }

            /// <summary>
            /// Reserved for future use
            /// </summary>
            public uint Flags { get { return _flags; } }
            public System M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Report the general and specific state of a subsystem.  If the generic
        /// state is reported as initializing, the specific state should be ignored.
        /// </summary>
        public partial class SubSystemReport : KaitaiStruct
        {
            public static SubSystemReport FromFile(string fileName)
            {
                return new SubSystemReport(new KaitaiStream(fileName));
            }

            public SubSystemReport(KaitaiStream p__io, KaitaiStruct p__parent = null, System p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _component = m_io.ReadU2le();
                _generic = m_io.ReadU1();
                _specific = m_io.ReadU1();
            }
            private ushort _component;
            private byte _generic;
            private byte _specific;
            private System m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// Identity of reporting subsystem
            /// </summary>
            public ushort Component { get { return _component; } }

            /// <summary>
            /// Generic form status report
            /// </summary>
            public byte Generic { get { return _generic; } }

            /// <summary>
            /// Subsystem specific status code
            /// </summary>
            public byte Specific { get { return _specific; } }
            public System M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The status report is sent periodically to inform the host or other
        /// attached devices that the system is running. It is used to monitor
        /// system malfunctions. It contains status reports that indicate to the
        /// host the status of each subsystem and whether it is operating correctly.
        /// 
        /// Interpretation of the subsystem specific status code is product
        /// dependent, but if the generic status code is initializing, it should be
        /// ignored.  Refer to product documentation for details.
        /// </summary>
        public partial class MsgStatusReport : KaitaiStruct
        {
            public static MsgStatusReport FromFile(string fileName)
            {
                return new MsgStatusReport(new KaitaiStream(fileName));
            }

            public MsgStatusReport(KaitaiStream p__io, Sbp.Message p__parent = null, System p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _reportingSystem = m_io.ReadU2le();
                _sbpVersion = m_io.ReadU2le();
                _sequence = m_io.ReadU4le();
                _uptime = m_io.ReadU4le();
                _status = new List<SubSystemReport>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _status.Add(new SubSystemReport(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private ushort _reportingSystem;
            private ushort _sbpVersion;
            private uint _sequence;
            private uint _uptime;
            private List<SubSystemReport> _status;
            private System m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Identity of reporting system
            /// </summary>
            public ushort ReportingSystem { get { return _reportingSystem; } }

            /// <summary>
            /// SBP protocol version
            /// </summary>
            public ushort SbpVersion { get { return _sbpVersion; } }

            /// <summary>
            /// Increments on each status report sent
            /// </summary>
            public uint Sequence { get { return _sequence; } }

            /// <summary>
            /// Number of seconds since system start-up
            /// </summary>
            public uint Uptime { get { return _uptime; } }

            /// <summary>
            /// Reported status of individual subsystems
            /// </summary>
            public List<SubSystemReport> Status { get { return _status; } }
            public System M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Reports the uptime and the state of a subsystem via generic and specific
        /// status codes.  If the generic state is reported as initializing, the
        /// specific state should be ignored.
        /// </summary>
        public partial class StatusJournalItem : KaitaiStruct
        {
            public static StatusJournalItem FromFile(string fileName)
            {
                return new StatusJournalItem(new KaitaiStream(fileName));
            }

            public StatusJournalItem(KaitaiStream p__io, System.MsgStatusJournal p__parent = null, System p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _uptime = m_io.ReadU4le();
                _report = new SubSystemReport(m_io, this, m_root);
            }
            private uint _uptime;
            private SubSystemReport _report;
            private System m_root;
            private System.MsgStatusJournal m_parent;

            /// <summary>
            /// Milliseconds since system startup
            /// </summary>
            public uint Uptime { get { return _uptime; } }
            public SubSystemReport Report { get { return _report; } }
            public System M_Root { get { return m_root; } }
            public System.MsgStatusJournal M_Parent { get { return m_parent; } }
        }
        private System m_root;
        private KaitaiStruct m_parent;
        public System M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
