// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class Tracking : KaitaiStruct
    {
        public static Tracking FromFile(string fileName)
        {
            return new Tracking(new KaitaiStream(fileName));
        }

        public Tracking(KaitaiStream p__io, KaitaiStruct p__parent = null, Tracking p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgTrackingStateDetailedDep : KaitaiStruct
        {
            public static MsgTrackingStateDetailedDep FromFile(string fileName)
            {
                return new MsgTrackingStateDetailedDep(new KaitaiStream(fileName));
            }

            public MsgTrackingStateDetailedDep(KaitaiStream p__io, Sbp.Message p__parent = null, Tracking p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _recvTime = m_io.ReadU8le();
                _tot = new Gnss.GpsTimeDep(m_io, this, m_root);
                _p = m_io.ReadU4le();
                _pStd = m_io.ReadU2le();
                _l = new Gnss.CarrierPhase(m_io, this, m_root);
                _cn0 = m_io.ReadU1();
                _lock = m_io.ReadU2le();
                _sid = new Gnss.GnssSignalDep(m_io, this, m_root);
                _doppler = m_io.ReadS4le();
                _dopplerStd = m_io.ReadU2le();
                _uptime = m_io.ReadU4le();
                _clockOffset = m_io.ReadS2le();
                _clockDrift = m_io.ReadS2le();
                _corrSpacing = m_io.ReadU2le();
                _acceleration = m_io.ReadS1();
                _syncFlags = m_io.ReadU1();
                _towFlags = m_io.ReadU1();
                _trackFlags = m_io.ReadU1();
                _navFlags = m_io.ReadU1();
                _psetFlags = m_io.ReadU1();
                _miscFlags = m_io.ReadU1();
            }
            private ulong _recvTime;
            private Gnss.GpsTimeDep _tot;
            private uint _p;
            private ushort _pStd;
            private Gnss.CarrierPhase _l;
            private byte _cn0;
            private ushort _lock;
            private Gnss.GnssSignalDep _sid;
            private int _doppler;
            private ushort _dopplerStd;
            private uint _uptime;
            private short _clockOffset;
            private short _clockDrift;
            private ushort _corrSpacing;
            private sbyte _acceleration;
            private byte _syncFlags;
            private byte _towFlags;
            private byte _trackFlags;
            private byte _navFlags;
            private byte _psetFlags;
            private byte _miscFlags;
            private Tracking m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Receiver clock time.
            /// </summary>
            public ulong RecvTime { get { return _recvTime; } }

            /// <summary>
            /// Time of transmission of signal from satellite. TOW only valid when
            /// TOW status is decoded or propagated. WN only valid when week number
            /// valid flag is set.
            /// </summary>
            public Gnss.GpsTimeDep Tot { get { return _tot; } }

            /// <summary>
            /// Pseudorange observation. Valid only when pseudorange valid flag is
            /// set.
            /// </summary>
            public uint P { get { return _p; } }

            /// <summary>
            /// Pseudorange observation standard deviation. Valid only when
            /// pseudorange valid flag is set.
            /// </summary>
            public ushort PStd { get { return _pStd; } }

            /// <summary>
            /// Carrier phase observation with typical sign convention. Valid only
            /// when PLL pessimistic lock is achieved.
            /// </summary>
            public Gnss.CarrierPhase L { get { return _l; } }

            /// <summary>
            /// Carrier-to-Noise density
            /// </summary>
            public byte Cn0 { get { return _cn0; } }

            /// <summary>
            /// Lock time. It is encoded according to DF402 from the RTCM 10403.2
            /// Amendment 2 specification. Valid values range from 0 to 15.
            /// </summary>
            public ushort Lock { get { return _lock; } }

            /// <summary>
            /// GNSS signal identifier.
            /// </summary>
            public Gnss.GnssSignalDep Sid { get { return _sid; } }

            /// <summary>
            /// Carrier Doppler frequency.
            /// </summary>
            public int Doppler { get { return _doppler; } }

            /// <summary>
            /// Carrier Doppler frequency standard deviation.
            /// </summary>
            public ushort DopplerStd { get { return _dopplerStd; } }

            /// <summary>
            /// Number of seconds of continuous tracking. Specifies how much time
            /// signal is in continuous track.
            /// </summary>
            public uint Uptime { get { return _uptime; } }

            /// <summary>
            /// TCXO clock offset. Valid only when valid clock valid flag is set.
            /// </summary>
            public short ClockOffset { get { return _clockOffset; } }

            /// <summary>
            /// TCXO clock drift. Valid only when valid clock valid flag is set.
            /// </summary>
            public short ClockDrift { get { return _clockDrift; } }

            /// <summary>
            /// Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
            /// </summary>
            public ushort CorrSpacing { get { return _corrSpacing; } }

            /// <summary>
            /// Acceleration. Valid only when acceleration valid flag is set.
            /// </summary>
            public sbyte Acceleration { get { return _acceleration; } }

            /// <summary>
            /// Synchronization status flags.
            /// </summary>
            public byte SyncFlags { get { return _syncFlags; } }

            /// <summary>
            /// TOW status flags.
            /// </summary>
            public byte TowFlags { get { return _towFlags; } }

            /// <summary>
            /// Tracking loop status flags.
            /// </summary>
            public byte TrackFlags { get { return _trackFlags; } }

            /// <summary>
            /// Navigation data status flags.
            /// </summary>
            public byte NavFlags { get { return _navFlags; } }

            /// <summary>
            /// Parameters sets flags.
            /// </summary>
            public byte PsetFlags { get { return _psetFlags; } }

            /// <summary>
            /// Miscellaneous flags.
            /// </summary>
            public byte MiscFlags { get { return _miscFlags; } }
            public Tracking M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class TrackingChannelStateDepB : KaitaiStruct
        {
            public static TrackingChannelStateDepB FromFile(string fileName)
            {
                return new TrackingChannelStateDepB(new KaitaiStream(fileName));
            }

            public TrackingChannelStateDepB(KaitaiStream p__io, Tracking.MsgTrackingStateDepB p__parent = null, Tracking p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _state = m_io.ReadU1();
                _sid = new Gnss.GnssSignalDep(m_io, this, m_root);
                _cn0 = m_io.ReadF4le();
            }
            private byte _state;
            private Gnss.GnssSignalDep _sid;
            private float _cn0;
            private Tracking m_root;
            private Tracking.MsgTrackingStateDepB m_parent;

            /// <summary>
            /// Status of tracking channel
            /// </summary>
            public byte State { get { return _state; } }

            /// <summary>
            /// GNSS signal being tracked
            /// </summary>
            public Gnss.GnssSignalDep Sid { get { return _sid; } }

            /// <summary>
            /// Carrier-to-noise density
            /// </summary>
            public float Cn0 { get { return _cn0; } }
            public Tracking M_Root { get { return m_root; } }
            public Tracking.MsgTrackingStateDepB M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Tracking channel state for a specific satellite signal and measured
        /// signal power.
        /// </summary>
        public partial class TrackingChannelState : KaitaiStruct
        {
            public static TrackingChannelState FromFile(string fileName)
            {
                return new TrackingChannelState(new KaitaiStream(fileName));
            }

            public TrackingChannelState(KaitaiStream p__io, Tracking.MsgTrackingState p__parent = null, Tracking p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _fcn = m_io.ReadU1();
                _cn0 = m_io.ReadU1();
            }
            private Gnss.GnssSignal _sid;
            private byte _fcn;
            private byte _cn0;
            private Tracking m_root;
            private Tracking.MsgTrackingState m_parent;

            /// <summary>
            /// GNSS signal being tracked
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// Frequency channel number (GLONASS only)
            /// </summary>
            public byte Fcn { get { return _fcn; } }

            /// <summary>
            /// Carrier-to-Noise density.  Zero implies invalid cn0.
            /// </summary>
            public byte Cn0 { get { return _cn0; } }
            public Tracking M_Root { get { return m_root; } }
            public Tracking.MsgTrackingState M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The tracking message returns a variable-length array of tracking channel
        /// states. It reports status and carrier-to-noise density measurements for
        /// all tracked satellites.
        /// </summary>
        public partial class MsgTrackingState : KaitaiStruct
        {
            public static MsgTrackingState FromFile(string fileName)
            {
                return new MsgTrackingState(new KaitaiStream(fileName));
            }

            public MsgTrackingState(KaitaiStream p__io, Sbp.Message p__parent = null, Tracking p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _states = new List<TrackingChannelState>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _states.Add(new TrackingChannelState(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private List<TrackingChannelState> _states;
            private Tracking m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Signal tracking channel state
            /// </summary>
            public List<TrackingChannelState> States { get { return _states; } }
            public Tracking M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class TrackingChannelStateDepA : KaitaiStruct
        {
            public static TrackingChannelStateDepA FromFile(string fileName)
            {
                return new TrackingChannelStateDepA(new KaitaiStream(fileName));
            }

            public TrackingChannelStateDepA(KaitaiStream p__io, Tracking.MsgTrackingStateDepA p__parent = null, Tracking p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _state = m_io.ReadU1();
                _prn = m_io.ReadU1();
                _cn0 = m_io.ReadF4le();
            }
            private byte _state;
            private byte _prn;
            private float _cn0;
            private Tracking m_root;
            private Tracking.MsgTrackingStateDepA m_parent;

            /// <summary>
            /// Status of tracking channel
            /// </summary>
            public byte State { get { return _state; } }

            /// <summary>
            /// PRN-1 being tracked
            /// </summary>
            public byte Prn { get { return _prn; } }

            /// <summary>
            /// Carrier-to-noise density
            /// </summary>
            public float Cn0 { get { return _cn0; } }
            public Tracking M_Root { get { return m_root; } }
            public Tracking.MsgTrackingStateDepA M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgTrackingIqDepA : KaitaiStruct
        {
            public static MsgTrackingIqDepA FromFile(string fileName)
            {
                return new MsgTrackingIqDepA(new KaitaiStream(fileName));
            }

            public MsgTrackingIqDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Tracking p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _channel = m_io.ReadU1();
                _sid = new Gnss.GnssSignalDep(m_io, this, m_root);
                _corrs = new List<ulong>();
                for (var i = 0; i < 3; i++)
                {
                    _corrs.Add(m_io.ReadU8le());
                }
            }
            private byte _channel;
            private Gnss.GnssSignalDep _sid;
            private List<ulong> _corrs;
            private Tracking m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Tracking channel of origin
            /// </summary>
            public byte Channel { get { return _channel; } }

            /// <summary>
            /// GNSS signal identifier
            /// </summary>
            public Gnss.GnssSignalDep Sid { get { return _sid; } }

            /// <summary>
            /// Early, Prompt and Late correlations
            /// </summary>
            public List<ulong> Corrs { get { return _corrs; } }
            public Tracking M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Structure containing in-phase and quadrature correlation components.
        /// </summary>
        public partial class TrackingChannelCorrelationDep : KaitaiStruct
        {
            public static TrackingChannelCorrelationDep FromFile(string fileName)
            {
                return new TrackingChannelCorrelationDep(new KaitaiStream(fileName));
            }

            public TrackingChannelCorrelationDep(KaitaiStream p__io, KaitaiStruct p__parent = null, Tracking p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _i = m_io.ReadS4le();
                _q = m_io.ReadS4le();
            }
            private int _i;
            private int _q;
            private Tracking m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// In-phase correlation
            /// </summary>
            public int I { get { return _i; } }

            /// <summary>
            /// Quadrature correlation
            /// </summary>
            public int Q { get { return _q; } }
            public Tracking M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgTrackingStateDepA : KaitaiStruct
        {
            public static MsgTrackingStateDepA FromFile(string fileName)
            {
                return new MsgTrackingStateDepA(new KaitaiStream(fileName));
            }

            public MsgTrackingStateDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Tracking p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _states = new List<TrackingChannelStateDepA>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _states.Add(new TrackingChannelStateDepA(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private List<TrackingChannelStateDepA> _states;
            private Tracking m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Satellite tracking channel state
            /// </summary>
            public List<TrackingChannelStateDepA> States { get { return _states; } }
            public Tracking M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The tracking message returns a variable-length array of tracking channel
        /// states. It reports status and carrier-to-noise density measurements for
        /// all tracked satellites.
        /// </summary>
        public partial class MsgMeasurementState : KaitaiStruct
        {
            public static MsgMeasurementState FromFile(string fileName)
            {
                return new MsgMeasurementState(new KaitaiStream(fileName));
            }

            public MsgMeasurementState(KaitaiStream p__io, Sbp.Message p__parent = null, Tracking p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _states = new List<MeasurementState>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _states.Add(new MeasurementState(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private List<MeasurementState> _states;
            private Tracking m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// ME signal tracking channel state
            /// </summary>
            public List<MeasurementState> States { get { return _states; } }
            public Tracking M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Structure containing in-phase and quadrature correlation components.
        /// </summary>
        public partial class TrackingChannelCorrelation : KaitaiStruct
        {
            public static TrackingChannelCorrelation FromFile(string fileName)
            {
                return new TrackingChannelCorrelation(new KaitaiStream(fileName));
            }

            public TrackingChannelCorrelation(KaitaiStream p__io, KaitaiStruct p__parent = null, Tracking p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _i = m_io.ReadS2le();
                _q = m_io.ReadS2le();
            }
            private short _i;
            private short _q;
            private Tracking m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// In-phase correlation
            /// </summary>
            public short I { get { return _i; } }

            /// <summary>
            /// Quadrature correlation
            /// </summary>
            public short Q { get { return _q; } }
            public Tracking M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// When enabled, a tracking channel can output the correlations at each
        /// update interval.
        /// </summary>
        public partial class MsgTrackingIq : KaitaiStruct
        {
            public static MsgTrackingIq FromFile(string fileName)
            {
                return new MsgTrackingIq(new KaitaiStream(fileName));
            }

            public MsgTrackingIq(KaitaiStream p__io, Sbp.Message p__parent = null, Tracking p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _channel = m_io.ReadU1();
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _corrs = new List<ulong>();
                for (var i = 0; i < 3; i++)
                {
                    _corrs.Add(m_io.ReadU8le());
                }
            }
            private byte _channel;
            private Gnss.GnssSignal _sid;
            private List<ulong> _corrs;
            private Tracking m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Tracking channel of origin
            /// </summary>
            public byte Channel { get { return _channel; } }

            /// <summary>
            /// GNSS signal identifier
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// Early, Prompt and Late correlations
            /// </summary>
            public List<ulong> Corrs { get { return _corrs; } }
            public Tracking M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The tracking message returns a set tracking channel parameters for a
        /// single tracking channel useful for debugging issues.
        /// </summary>
        public partial class MsgTrackingStateDetailedDepA : KaitaiStruct
        {
            public static MsgTrackingStateDetailedDepA FromFile(string fileName)
            {
                return new MsgTrackingStateDetailedDepA(new KaitaiStream(fileName));
            }

            public MsgTrackingStateDetailedDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Tracking p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _recvTime = m_io.ReadU8le();
                _tot = new Gnss.GpsTime(m_io, this, m_root);
                _p = m_io.ReadU4le();
                _pStd = m_io.ReadU2le();
                _l = new Gnss.CarrierPhase(m_io, this, m_root);
                _cn0 = m_io.ReadU1();
                _lock = m_io.ReadU2le();
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _doppler = m_io.ReadS4le();
                _dopplerStd = m_io.ReadU2le();
                _uptime = m_io.ReadU4le();
                _clockOffset = m_io.ReadS2le();
                _clockDrift = m_io.ReadS2le();
                _corrSpacing = m_io.ReadU2le();
                _acceleration = m_io.ReadS1();
                _syncFlags = m_io.ReadU1();
                _towFlags = m_io.ReadU1();
                _trackFlags = m_io.ReadU1();
                _navFlags = m_io.ReadU1();
                _psetFlags = m_io.ReadU1();
                _miscFlags = m_io.ReadU1();
            }
            private ulong _recvTime;
            private Gnss.GpsTime _tot;
            private uint _p;
            private ushort _pStd;
            private Gnss.CarrierPhase _l;
            private byte _cn0;
            private ushort _lock;
            private Gnss.GnssSignal _sid;
            private int _doppler;
            private ushort _dopplerStd;
            private uint _uptime;
            private short _clockOffset;
            private short _clockDrift;
            private ushort _corrSpacing;
            private sbyte _acceleration;
            private byte _syncFlags;
            private byte _towFlags;
            private byte _trackFlags;
            private byte _navFlags;
            private byte _psetFlags;
            private byte _miscFlags;
            private Tracking m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Receiver clock time.
            /// </summary>
            public ulong RecvTime { get { return _recvTime; } }

            /// <summary>
            /// Time of transmission of signal from satellite. TOW only valid when
            /// TOW status is decoded or propagated. WN only valid when week number
            /// valid flag is set.
            /// </summary>
            public Gnss.GpsTime Tot { get { return _tot; } }

            /// <summary>
            /// Pseudorange observation. Valid only when pseudorange valid flag is
            /// set.
            /// </summary>
            public uint P { get { return _p; } }

            /// <summary>
            /// Pseudorange observation standard deviation. Valid only when
            /// pseudorange valid flag is set.
            /// </summary>
            public ushort PStd { get { return _pStd; } }

            /// <summary>
            /// Carrier phase observation with typical sign convention. Valid only
            /// when PLL pessimistic lock is achieved.
            /// </summary>
            public Gnss.CarrierPhase L { get { return _l; } }

            /// <summary>
            /// Carrier-to-Noise density
            /// </summary>
            public byte Cn0 { get { return _cn0; } }

            /// <summary>
            /// Lock time. It is encoded according to DF402 from the RTCM 10403.2
            /// Amendment 2 specification. Valid values range from 0 to 15.
            /// </summary>
            public ushort Lock { get { return _lock; } }

            /// <summary>
            /// GNSS signal identifier.
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// Carrier Doppler frequency.
            /// </summary>
            public int Doppler { get { return _doppler; } }

            /// <summary>
            /// Carrier Doppler frequency standard deviation.
            /// </summary>
            public ushort DopplerStd { get { return _dopplerStd; } }

            /// <summary>
            /// Number of seconds of continuous tracking. Specifies how much time
            /// signal is in continuous track.
            /// </summary>
            public uint Uptime { get { return _uptime; } }

            /// <summary>
            /// TCXO clock offset. Valid only when valid clock valid flag is set.
            /// </summary>
            public short ClockOffset { get { return _clockOffset; } }

            /// <summary>
            /// TCXO clock drift. Valid only when valid clock valid flag is set.
            /// </summary>
            public short ClockDrift { get { return _clockDrift; } }

            /// <summary>
            /// Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
            /// </summary>
            public ushort CorrSpacing { get { return _corrSpacing; } }

            /// <summary>
            /// Acceleration. Valid only when acceleration valid flag is set.
            /// </summary>
            public sbyte Acceleration { get { return _acceleration; } }

            /// <summary>
            /// Synchronization status flags.
            /// </summary>
            public byte SyncFlags { get { return _syncFlags; } }

            /// <summary>
            /// TOW status flags.
            /// </summary>
            public byte TowFlags { get { return _towFlags; } }

            /// <summary>
            /// Tracking loop status flags.
            /// </summary>
            public byte TrackFlags { get { return _trackFlags; } }

            /// <summary>
            /// Navigation data status flags.
            /// </summary>
            public byte NavFlags { get { return _navFlags; } }

            /// <summary>
            /// Parameters sets flags.
            /// </summary>
            public byte PsetFlags { get { return _psetFlags; } }

            /// <summary>
            /// Miscellaneous flags.
            /// </summary>
            public byte MiscFlags { get { return _miscFlags; } }
            public Tracking M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgTrackingStateDepB : KaitaiStruct
        {
            public static MsgTrackingStateDepB FromFile(string fileName)
            {
                return new MsgTrackingStateDepB(new KaitaiStream(fileName));
            }

            public MsgTrackingStateDepB(KaitaiStream p__io, Sbp.Message p__parent = null, Tracking p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _states = new List<TrackingChannelStateDepB>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _states.Add(new TrackingChannelStateDepB(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private List<TrackingChannelStateDepB> _states;
            private Tracking m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Signal tracking channel state
            /// </summary>
            public List<TrackingChannelStateDepB> States { get { return _states; } }
            public Tracking M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Measurement Engine tracking channel state for a specific satellite
        /// signal and measured signal power. The mesid field for Glonass can either
        /// carry the FCN as 100 + FCN where FCN is in [-7, +6] or the Slot ID (from
        /// 1 to 28).
        /// </summary>
        public partial class MeasurementState : KaitaiStruct
        {
            public static MeasurementState FromFile(string fileName)
            {
                return new MeasurementState(new KaitaiStream(fileName));
            }

            public MeasurementState(KaitaiStream p__io, Tracking.MsgMeasurementState p__parent = null, Tracking p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _mesid = new Gnss.GnssSignal(m_io, this, m_root);
                _cn0 = m_io.ReadU1();
            }
            private Gnss.GnssSignal _mesid;
            private byte _cn0;
            private Tracking m_root;
            private Tracking.MsgMeasurementState m_parent;

            /// <summary>
            /// Measurement Engine GNSS signal being tracked (carries either Glonass
            /// FCN or SLOT)
            /// </summary>
            public Gnss.GnssSignal Mesid { get { return _mesid; } }

            /// <summary>
            /// Carrier-to-Noise density.  Zero implies invalid cn0.
            /// </summary>
            public byte Cn0 { get { return _cn0; } }
            public Tracking M_Root { get { return m_root; } }
            public Tracking.MsgMeasurementState M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// When enabled, a tracking channel can output the correlations at each
        /// update interval.
        /// </summary>
        public partial class MsgTrackingIqDepB : KaitaiStruct
        {
            public static MsgTrackingIqDepB FromFile(string fileName)
            {
                return new MsgTrackingIqDepB(new KaitaiStream(fileName));
            }

            public MsgTrackingIqDepB(KaitaiStream p__io, Sbp.Message p__parent = null, Tracking p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _channel = m_io.ReadU1();
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _corrs = new List<ulong>();
                for (var i = 0; i < 3; i++)
                {
                    _corrs.Add(m_io.ReadU8le());
                }
            }
            private byte _channel;
            private Gnss.GnssSignal _sid;
            private List<ulong> _corrs;
            private Tracking m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Tracking channel of origin
            /// </summary>
            public byte Channel { get { return _channel; } }

            /// <summary>
            /// GNSS signal identifier
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// Early, Prompt and Late correlations
            /// </summary>
            public List<ulong> Corrs { get { return _corrs; } }
            public Tracking M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        private Tracking m_root;
        private KaitaiStruct m_parent;
        public Tracking M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
