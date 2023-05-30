// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class Observation : KaitaiStruct
    {
        public static Observation FromFile(string fileName)
        {
            return new Observation(new KaitaiStream(fileName));
        }

        public Observation(KaitaiStream p__io, KaitaiStruct p__parent = null, Observation p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// Azimuth and elevation angles of all the visible satellites that the
        /// device does have ephemeris or almanac for.
        /// </summary>
        public partial class MsgSvAzEl : KaitaiStruct
        {
            public static MsgSvAzEl FromFile(string fileName)
            {
                return new MsgSvAzEl(new KaitaiStream(fileName));
            }

            public MsgSvAzEl(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _azel = new List<SvAzEl>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _azel.Add(new SvAzEl(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private List<SvAzEl> _azel;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Azimuth and elevation per satellite
            /// </summary>
            public List<SvAzEl> Azel { get { return _azel; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        public partial class GnssCapb : KaitaiStruct
        {
            public static GnssCapb FromFile(string fileName)
            {
                return new GnssCapb(new KaitaiStream(fileName));
            }

            public GnssCapb(KaitaiStream p__io, Observation.MsgGnssCapb p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _gpsActive = m_io.ReadU8le();
                _gpsL2c = m_io.ReadU8le();
                _gpsL5 = m_io.ReadU8le();
                _gloActive = m_io.ReadU4le();
                _gloL2of = m_io.ReadU4le();
                _gloL3 = m_io.ReadU4le();
                _sbasActive = m_io.ReadU8le();
                _sbasL5 = m_io.ReadU8le();
                _bdsActive = m_io.ReadU8le();
                _bdsD2nav = m_io.ReadU8le();
                _bdsB2 = m_io.ReadU8le();
                _bdsB2a = m_io.ReadU8le();
                _qzssActive = m_io.ReadU4le();
                _galActive = m_io.ReadU8le();
                _galE5 = m_io.ReadU8le();
            }
            private ulong _gpsActive;
            private ulong _gpsL2c;
            private ulong _gpsL5;
            private uint _gloActive;
            private uint _gloL2of;
            private uint _gloL3;
            private ulong _sbasActive;
            private ulong _sbasL5;
            private ulong _bdsActive;
            private ulong _bdsD2nav;
            private ulong _bdsB2;
            private ulong _bdsB2a;
            private uint _qzssActive;
            private ulong _galActive;
            private ulong _galE5;
            private Observation m_root;
            private Observation.MsgGnssCapb m_parent;

            /// <summary>
            /// GPS SV active mask
            /// </summary>
            public ulong GpsActive { get { return _gpsActive; } }

            /// <summary>
            /// GPS L2C active mask
            /// </summary>
            public ulong GpsL2c { get { return _gpsL2c; } }

            /// <summary>
            /// GPS L5 active mask
            /// </summary>
            public ulong GpsL5 { get { return _gpsL5; } }

            /// <summary>
            /// GLO active mask
            /// </summary>
            public uint GloActive { get { return _gloActive; } }

            /// <summary>
            /// GLO L2OF active mask
            /// </summary>
            public uint GloL2of { get { return _gloL2of; } }

            /// <summary>
            /// GLO L3 active mask
            /// </summary>
            public uint GloL3 { get { return _gloL3; } }

            /// <summary>
            /// SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
            /// https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
            /// </summary>
            public ulong SbasActive { get { return _sbasActive; } }

            /// <summary>
            /// SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
            /// https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
            /// </summary>
            public ulong SbasL5 { get { return _sbasL5; } }

            /// <summary>
            /// BDS active mask
            /// </summary>
            public ulong BdsActive { get { return _bdsActive; } }

            /// <summary>
            /// BDS D2NAV active mask
            /// </summary>
            public ulong BdsD2nav { get { return _bdsD2nav; } }

            /// <summary>
            /// BDS B2 active mask
            /// </summary>
            public ulong BdsB2 { get { return _bdsB2; } }

            /// <summary>
            /// BDS B2A active mask
            /// </summary>
            public ulong BdsB2a { get { return _bdsB2a; } }

            /// <summary>
            /// QZSS active mask
            /// </summary>
            public uint QzssActive { get { return _qzssActive; } }

            /// <summary>
            /// GAL active mask
            /// </summary>
            public ulong GalActive { get { return _galActive; } }

            /// <summary>
            /// GAL E5 active mask
            /// </summary>
            public ulong GalE5 { get { return _galE5; } }
            public Observation M_Root { get { return m_root; } }
            public Observation.MsgGnssCapb M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
        /// </summary>
        public partial class MsgGroupDelayDepB : KaitaiStruct
        {
            public static MsgGroupDelayDepB FromFile(string fileName)
            {
                return new MsgGroupDelayDepB(new KaitaiStream(fileName));
            }

            public MsgGroupDelayDepB(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tOp = new Gnss.GpsTimeSec(m_io, this, m_root);
                _sid = new Gnss.GnssSignalDep(m_io, this, m_root);
                _valid = m_io.ReadU1();
                _tgd = m_io.ReadS2le();
                _iscL1ca = m_io.ReadS2le();
                _iscL2c = m_io.ReadS2le();
            }
            private Gnss.GpsTimeSec _tOp;
            private Gnss.GnssSignalDep _sid;
            private byte _valid;
            private short _tgd;
            private short _iscL1ca;
            private short _iscL2c;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Data Predict Time of Week
            /// </summary>
            public Gnss.GpsTimeSec TOp { get { return _tOp; } }

            /// <summary>
            /// GNSS signal identifier
            /// </summary>
            public Gnss.GnssSignalDep Sid { get { return _sid; } }

            /// <summary>
            /// bit-field indicating validity of the values, LSB indicating tgd
            /// validity etc. 1 = value is valid, 0 = value is not valid.
            /// </summary>
            public byte Valid { get { return _valid; } }
            public short Tgd { get { return _tgd; } }
            public short IscL1ca { get { return _iscL1ca; } }
            public short IscL2c { get { return _iscL2c; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Header of a GPS observation message.
        /// </summary>
        public partial class ObservationHeaderDep : KaitaiStruct
        {
            public static ObservationHeaderDep FromFile(string fileName)
            {
                return new ObservationHeaderDep(new KaitaiStream(fileName));
            }

            public ObservationHeaderDep(KaitaiStream p__io, KaitaiStruct p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _t = new Gnss.GpsTimeDep(m_io, this, m_root);
                _nObs = m_io.ReadU1();
            }
            private Gnss.GpsTimeDep _t;
            private byte _nObs;
            private Observation m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// GPS time of this observation
            /// </summary>
            public Gnss.GpsTimeDep T { get { return _t; } }

            /// <summary>
            /// Total number of observations. First nibble is the size of the
            /// sequence (n), second nibble is the zero-indexed counter (ith packet
            /// of n)
            /// </summary>
            public byte NObs { get { return _nObs; } }
            public Observation M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }
        public partial class AlmanacCommonContentDep : KaitaiStruct
        {
            public static AlmanacCommonContentDep FromFile(string fileName)
            {
                return new AlmanacCommonContentDep(new KaitaiStream(fileName));
            }

            public AlmanacCommonContentDep(KaitaiStream p__io, KaitaiStruct p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sid = new Gnss.GnssSignalDep(m_io, this, m_root);
                _toa = new Gnss.GpsTimeSec(m_io, this, m_root);
                _ura = m_io.ReadF8le();
                _fitInterval = m_io.ReadU4le();
                _valid = m_io.ReadU1();
                _healthBits = m_io.ReadU1();
            }
            private Gnss.GnssSignalDep _sid;
            private Gnss.GpsTimeSec _toa;
            private double _ura;
            private uint _fitInterval;
            private byte _valid;
            private byte _healthBits;
            private Observation m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// GNSS signal identifier
            /// </summary>
            public Gnss.GnssSignalDep Sid { get { return _sid; } }

            /// <summary>
            /// Reference time of almanac
            /// </summary>
            public Gnss.GpsTimeSec Toa { get { return _toa; } }

            /// <summary>
            /// User Range Accuracy
            /// </summary>
            public double Ura { get { return _ura; } }

            /// <summary>
            /// Curve fit interval
            /// </summary>
            public uint FitInterval { get { return _fitInterval; } }

            /// <summary>
            /// Status of almanac, 1 = valid, 0 = invalid
            /// </summary>
            public byte Valid { get { return _valid; } }

            /// <summary>
            /// Satellite health status for GPS:
            ///   - bits 5-7: NAV data health status. See IS-GPS-200H
            ///     Table 20-VII: NAV Data Health Indications.
            ///   - bits 0-4: Signal health status. See IS-GPS-200H
            ///     Table 20-VIII. Codes for Health of SV Signal
            ///     Components.
            /// Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for
            /// details):
            ///   - bit 0: C(n), &quot;unhealthy&quot; flag that is transmitted within
            ///     non-immediate data and indicates overall constellation status
            ///     at the moment of almanac uploading.
            ///     '0' indicates malfunction of n-satellite.
            ///     '1' indicates that n-satellite is operational.
            ///   - bit 1: Bn(ln), '0' indicates the satellite is operational
            ///     and suitable for navigation.
            /// </summary>
            public byte HealthBits { get { return _healthBits; } }
            public Observation M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }
        public partial class EphemerisCommonContentDepA : KaitaiStruct
        {
            public static EphemerisCommonContentDepA FromFile(string fileName)
            {
                return new EphemerisCommonContentDepA(new KaitaiStream(fileName));
            }

            public EphemerisCommonContentDepA(KaitaiStream p__io, KaitaiStruct p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sid = new Gnss.GnssSignalDep(m_io, this, m_root);
                _toe = new Gnss.GpsTimeDep(m_io, this, m_root);
                _ura = m_io.ReadF8le();
                _fitInterval = m_io.ReadU4le();
                _valid = m_io.ReadU1();
                _healthBits = m_io.ReadU1();
            }
            private Gnss.GnssSignalDep _sid;
            private Gnss.GpsTimeDep _toe;
            private double _ura;
            private uint _fitInterval;
            private byte _valid;
            private byte _healthBits;
            private Observation m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// GNSS signal identifier
            /// </summary>
            public Gnss.GnssSignalDep Sid { get { return _sid; } }

            /// <summary>
            /// Time of Ephemerides
            /// </summary>
            public Gnss.GpsTimeDep Toe { get { return _toe; } }

            /// <summary>
            /// User Range Accuracy
            /// </summary>
            public double Ura { get { return _ura; } }

            /// <summary>
            /// Curve fit interval
            /// </summary>
            public uint FitInterval { get { return _fitInterval; } }

            /// <summary>
            /// Status of ephemeris, 1 = valid, 0 = invalid
            /// </summary>
            public byte Valid { get { return _valid; } }

            /// <summary>
            /// Satellite health status.
            /// GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
            /// SBAS: 0 = valid, non-zero = invalid
            /// GLO: 0 = valid, non-zero = invalid
            /// </summary>
            public byte HealthBits { get { return _healthBits; } }
            public Observation M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }
        public partial class EphemerisCommonContent : KaitaiStruct
        {
            public static EphemerisCommonContent FromFile(string fileName)
            {
                return new EphemerisCommonContent(new KaitaiStream(fileName));
            }

            public EphemerisCommonContent(KaitaiStream p__io, KaitaiStruct p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _toe = new Gnss.GpsTimeSec(m_io, this, m_root);
                _ura = m_io.ReadF4le();
                _fitInterval = m_io.ReadU4le();
                _valid = m_io.ReadU1();
                _healthBits = m_io.ReadU1();
            }
            private Gnss.GnssSignal _sid;
            private Gnss.GpsTimeSec _toe;
            private float _ura;
            private uint _fitInterval;
            private byte _valid;
            private byte _healthBits;
            private Observation m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// GNSS signal identifier (16 bit)
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// Time of Ephemerides
            /// </summary>
            public Gnss.GpsTimeSec Toe { get { return _toe; } }

            /// <summary>
            /// User Range Accuracy
            /// </summary>
            public float Ura { get { return _ura; } }

            /// <summary>
            /// Curve fit interval
            /// </summary>
            public uint FitInterval { get { return _fitInterval; } }

            /// <summary>
            /// Status of ephemeris, 1 = valid, 0 = invalid
            /// </summary>
            public byte Valid { get { return _valid; } }

            /// <summary>
            /// Satellite health status.
            /// GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
            /// SBAS: 0 = valid, non-zero = invalid
            /// GLO: 0 = valid, non-zero = invalid
            /// </summary>
            public byte HealthBits { get { return _healthBits; } }
            public Observation M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Pseudorange and carrier phase observation for a satellite being tracked.
        /// The observations are be interoperable with 3rd party receivers and
        /// conform with typical RTCMv3 GNSS observations.
        /// </summary>
        public partial class PackedObsContentDepC : KaitaiStruct
        {
            public static PackedObsContentDepC FromFile(string fileName)
            {
                return new PackedObsContentDepC(new KaitaiStream(fileName));
            }

            public PackedObsContentDepC(KaitaiStream p__io, Observation.MsgObsDepC p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _p = m_io.ReadU4le();
                _l = new Gnss.CarrierPhase(m_io, this, m_root);
                _cn0 = m_io.ReadU1();
                _lock = m_io.ReadU2le();
                _sid = new Gnss.GnssSignalDep(m_io, this, m_root);
            }
            private uint _p;
            private Gnss.CarrierPhase _l;
            private byte _cn0;
            private ushort _lock;
            private Gnss.GnssSignalDep _sid;
            private Observation m_root;
            private Observation.MsgObsDepC m_parent;

            /// <summary>
            /// Pseudorange observation
            /// </summary>
            public uint P { get { return _p; } }

            /// <summary>
            /// Carrier phase observation with typical sign convention.
            /// </summary>
            public Gnss.CarrierPhase L { get { return _l; } }

            /// <summary>
            /// Carrier-to-Noise density
            /// </summary>
            public byte Cn0 { get { return _cn0; } }

            /// <summary>
            /// Lock indicator. This value changes whenever a satellite signal has
            /// lost and regained lock, indicating that the carrier phase ambiguity
            /// may have changed.
            /// </summary>
            public ushort Lock { get { return _lock; } }

            /// <summary>
            /// GNSS signal identifier
            /// </summary>
            public Gnss.GnssSignalDep Sid { get { return _sid; } }
            public Observation M_Root { get { return m_root; } }
            public Observation.MsgObsDepC M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This observation message has been deprecated in favor of ephemeris
        /// message using floats for size reduction.
        /// </summary>
        public partial class MsgEphemerisGloDepD : KaitaiStruct
        {
            public static MsgEphemerisGloDepD FromFile(string fileName)
            {
                return new MsgEphemerisGloDepD(new KaitaiStream(fileName));
            }

            public MsgEphemerisGloDepD(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new EphemerisCommonContentDepB(m_io, this, m_root);
                _gamma = m_io.ReadF8le();
                _tau = m_io.ReadF8le();
                _dTau = m_io.ReadF8le();
                _pos = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _pos.Add(m_io.ReadF8le());
                }
                _vel = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _vel.Add(m_io.ReadF8le());
                }
                _acc = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _acc.Add(m_io.ReadF8le());
                }
                _fcn = m_io.ReadU1();
                _iod = m_io.ReadU1();
            }
            private EphemerisCommonContentDepB _common;
            private double _gamma;
            private double _tau;
            private double _dTau;
            private List<double> _pos;
            private List<double> _vel;
            private List<double> _acc;
            private byte _fcn;
            private byte _iod;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all ephemeris types
            /// </summary>
            public EphemerisCommonContentDepB Common { get { return _common; } }

            /// <summary>
            /// Relative deviation of predicted carrier frequency from nominal
            /// </summary>
            public double Gamma { get { return _gamma; } }

            /// <summary>
            /// Correction to the SV time
            /// </summary>
            public double Tau { get { return _tau; } }

            /// <summary>
            /// Equipment delay between L1 and L2
            /// </summary>
            public double DTau { get { return _dTau; } }

            /// <summary>
            /// Position of the SV at tb in PZ-90.02 coordinates system
            /// </summary>
            public List<double> Pos { get { return _pos; } }

            /// <summary>
            /// Velocity vector of the SV at tb in PZ-90.02 coordinates system
            /// </summary>
            public List<double> Vel { get { return _vel; } }

            /// <summary>
            /// Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
            /// </summary>
            public List<double> Acc { get { return _acc; } }

            /// <summary>
            /// Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
            /// </summary>
            public byte Fcn { get { return _fcn; } }

            /// <summary>
            /// Issue of data. Equal to the 7 bits of the immediate data word t_b
            /// </summary>
            public byte Iod { get { return _iod; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgObsDepA : KaitaiStruct
        {
            public static MsgObsDepA FromFile(string fileName)
            {
                return new MsgObsDepA(new KaitaiStream(fileName));
            }

            public MsgObsDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new ObservationHeaderDep(m_io, this, m_root);
                _obs = new List<PackedObsContentDepA>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _obs.Add(new PackedObsContentDepA(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private ObservationHeaderDep _header;
            private List<PackedObsContentDepA> _obs;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Header of a GPS observation message
            /// </summary>
            public ObservationHeaderDep Header { get { return _header; } }

            /// <summary>
            /// Pseudorange and carrier phase observation for a satellite being
            /// tracked.
            /// </summary>
            public List<PackedObsContentDepA> Obs { get { return _obs; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgEphemerisDepB : KaitaiStruct
        {
            public static MsgEphemerisDepB FromFile(string fileName)
            {
                return new MsgEphemerisDepB(new KaitaiStream(fileName));
            }

            public MsgEphemerisDepB(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tgd = m_io.ReadF8le();
                _cRs = m_io.ReadF8le();
                _cRc = m_io.ReadF8le();
                _cUc = m_io.ReadF8le();
                _cUs = m_io.ReadF8le();
                _cIc = m_io.ReadF8le();
                _cIs = m_io.ReadF8le();
                _dn = m_io.ReadF8le();
                _m0 = m_io.ReadF8le();
                _ecc = m_io.ReadF8le();
                _sqrta = m_io.ReadF8le();
                _omega0 = m_io.ReadF8le();
                _omegadot = m_io.ReadF8le();
                _w = m_io.ReadF8le();
                _inc = m_io.ReadF8le();
                _incDot = m_io.ReadF8le();
                _af0 = m_io.ReadF8le();
                _af1 = m_io.ReadF8le();
                _af2 = m_io.ReadF8le();
                _toeTow = m_io.ReadF8le();
                _toeWn = m_io.ReadU2le();
                _tocTow = m_io.ReadF8le();
                _tocWn = m_io.ReadU2le();
                _valid = m_io.ReadU1();
                _healthy = m_io.ReadU1();
                _prn = m_io.ReadU1();
                _iode = m_io.ReadU1();
            }
            private double _tgd;
            private double _cRs;
            private double _cRc;
            private double _cUc;
            private double _cUs;
            private double _cIc;
            private double _cIs;
            private double _dn;
            private double _m0;
            private double _ecc;
            private double _sqrta;
            private double _omega0;
            private double _omegadot;
            private double _w;
            private double _inc;
            private double _incDot;
            private double _af0;
            private double _af1;
            private double _af2;
            private double _toeTow;
            private ushort _toeWn;
            private double _tocTow;
            private ushort _tocWn;
            private byte _valid;
            private byte _healthy;
            private byte _prn;
            private byte _iode;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Group delay differential between L1 and L2
            /// </summary>
            public double Tgd { get { return _tgd; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the orbit radius
            /// </summary>
            public double CRs { get { return _cRs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the orbit radius
            /// </summary>
            public double CRc { get { return _cRc; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public double CUc { get { return _cUc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public double CUs { get { return _cUs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public double CIc { get { return _cIc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public double CIs { get { return _cIs; } }

            /// <summary>
            /// Mean motion difference
            /// </summary>
            public double Dn { get { return _dn; } }

            /// <summary>
            /// Mean anomaly at reference time
            /// </summary>
            public double M0 { get { return _m0; } }

            /// <summary>
            /// Eccentricity of satellite orbit
            /// </summary>
            public double Ecc { get { return _ecc; } }

            /// <summary>
            /// Square root of the semi-major axis of orbit
            /// </summary>
            public double Sqrta { get { return _sqrta; } }

            /// <summary>
            /// Longitude of ascending node of orbit plane at weekly epoch
            /// </summary>
            public double Omega0 { get { return _omega0; } }

            /// <summary>
            /// Rate of right ascension
            /// </summary>
            public double Omegadot { get { return _omegadot; } }

            /// <summary>
            /// Argument of perigee
            /// </summary>
            public double W { get { return _w; } }

            /// <summary>
            /// Inclination
            /// </summary>
            public double Inc { get { return _inc; } }

            /// <summary>
            /// Inclination first derivative
            /// </summary>
            public double IncDot { get { return _incDot; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock bias)
            /// </summary>
            public double Af0 { get { return _af0; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock drift)
            /// </summary>
            public double Af1 { get { return _af1; } }

            /// <summary>
            /// Polynomial clock correction coefficient (rate of clock drift)
            /// </summary>
            public double Af2 { get { return _af2; } }

            /// <summary>
            /// Time of week
            /// </summary>
            public double ToeTow { get { return _toeTow; } }

            /// <summary>
            /// Week number
            /// </summary>
            public ushort ToeWn { get { return _toeWn; } }

            /// <summary>
            /// Clock reference time of week
            /// </summary>
            public double TocTow { get { return _tocTow; } }

            /// <summary>
            /// Clock reference week number
            /// </summary>
            public ushort TocWn { get { return _tocWn; } }

            /// <summary>
            /// Is valid?
            /// </summary>
            public byte Valid { get { return _valid; } }

            /// <summary>
            /// Satellite is healthy?
            /// </summary>
            public byte Healthy { get { return _healthy; } }

            /// <summary>
            /// PRN being tracked
            /// </summary>
            public byte Prn { get { return _prn; } }

            /// <summary>
            /// Issue of ephemeris data
            /// </summary>
            public byte Iode { get { return _iode; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The GPS observations message reports all the raw pseudorange and carrier
        /// phase observations for the satellites being tracked by the device.
        /// Carrier phase observation here is represented as a 40-bit fixed point
        /// number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
        /// fractional cycles). The observations are be interoperable with 3rd party
        /// receivers and conform with typical RTCMv3 GNSS observations.
        /// </summary>
        public partial class MsgObs : KaitaiStruct
        {
            public static MsgObs FromFile(string fileName)
            {
                return new MsgObs(new KaitaiStream(fileName));
            }

            public MsgObs(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new ObservationHeader(m_io, this, m_root);
                _obs = new List<PackedObsContent>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _obs.Add(new PackedObsContent(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private ObservationHeader _header;
            private List<PackedObsContent> _obs;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Header of a GPS observation message
            /// </summary>
            public ObservationHeader Header { get { return _header; } }

            /// <summary>
            /// Pseudorange and carrier phase observation for a satellite being
            /// tracked.
            /// </summary>
            public List<PackedObsContent> Obs { get { return _obs; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Doppler measurement in Hz represented as a 24-bit fixed point number
        /// with Q16.8 layout, i.e. 16-bits of whole doppler and 8-bits of
        /// fractional doppler. This doppler is defined as positive for approaching
        /// satellites.
        /// </summary>
        public partial class Doppler : KaitaiStruct
        {
            public static Doppler FromFile(string fileName)
            {
                return new Doppler(new KaitaiStream(fileName));
            }

            public Doppler(KaitaiStream p__io, Observation.PackedObsContent p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _i = m_io.ReadS2le();
                _f = m_io.ReadU1();
            }
            private short _i;
            private byte _f;
            private Observation m_root;
            private Observation.PackedObsContent m_parent;

            /// <summary>
            /// Doppler whole Hz
            /// </summary>
            public short I { get { return _i; } }

            /// <summary>
            /// Doppler fractional part
            /// </summary>
            public byte F { get { return _f; } }
            public Observation M_Root { get { return m_root; } }
            public Observation.PackedObsContent M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The almanac message returns a set of satellite orbit parameters. Almanac
        /// data is not very precise and is considered valid for up to several
        /// months. Please see the GLO ICD 5.1 &quot;Chapter 4.5 Non-immediate
        /// information and almanac&quot; for details.
        /// </summary>
        public partial class MsgAlmanacGloDep : KaitaiStruct
        {
            public static MsgAlmanacGloDep FromFile(string fileName)
            {
                return new MsgAlmanacGloDep(new KaitaiStream(fileName));
            }

            public MsgAlmanacGloDep(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new AlmanacCommonContentDep(m_io, this, m_root);
                _lambdaNa = m_io.ReadF8le();
                _tLambdaNa = m_io.ReadF8le();
                _i = m_io.ReadF8le();
                _t = m_io.ReadF8le();
                _tDot = m_io.ReadF8le();
                _epsilon = m_io.ReadF8le();
                _omega = m_io.ReadF8le();
            }
            private AlmanacCommonContentDep _common;
            private double _lambdaNa;
            private double _tLambdaNa;
            private double _i;
            private double _t;
            private double _tDot;
            private double _epsilon;
            private double _omega;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all almanac types
            /// </summary>
            public AlmanacCommonContentDep Common { get { return _common; } }

            /// <summary>
            /// Longitude of the first ascending node of the orbit in PZ-90.02
            /// coordinate system
            /// </summary>
            public double LambdaNa { get { return _lambdaNa; } }

            /// <summary>
            /// Time of the first ascending node passage
            /// </summary>
            public double TLambdaNa { get { return _tLambdaNa; } }

            /// <summary>
            /// Value of inclination at instant of t_lambda
            /// </summary>
            public double I { get { return _i; } }

            /// <summary>
            /// Value of Draconian period at instant of t_lambda
            /// </summary>
            public double T { get { return _t; } }

            /// <summary>
            /// Rate of change of the Draconian period
            /// </summary>
            public double TDot { get { return _tDot; } }

            /// <summary>
            /// Eccentricity at instant of t_lambda
            /// </summary>
            public double Epsilon { get { return _epsilon; } }

            /// <summary>
            /// Argument of perigee at instant of t_lambda
            /// </summary>
            public double Omega { get { return _omega; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The almanac message returns a set of satellite orbit parameters. Almanac
        /// data is not very precise and is considered valid for up to several
        /// months. Please see the Navstar GPS Space Segment/Navigation user
        /// interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more
        /// details.
        /// </summary>
        public partial class MsgAlmanacGpsDep : KaitaiStruct
        {
            public static MsgAlmanacGpsDep FromFile(string fileName)
            {
                return new MsgAlmanacGpsDep(new KaitaiStream(fileName));
            }

            public MsgAlmanacGpsDep(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new AlmanacCommonContentDep(m_io, this, m_root);
                _m0 = m_io.ReadF8le();
                _ecc = m_io.ReadF8le();
                _sqrta = m_io.ReadF8le();
                _omega0 = m_io.ReadF8le();
                _omegadot = m_io.ReadF8le();
                _w = m_io.ReadF8le();
                _inc = m_io.ReadF8le();
                _af0 = m_io.ReadF8le();
                _af1 = m_io.ReadF8le();
            }
            private AlmanacCommonContentDep _common;
            private double _m0;
            private double _ecc;
            private double _sqrta;
            private double _omega0;
            private double _omegadot;
            private double _w;
            private double _inc;
            private double _af0;
            private double _af1;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all almanac types
            /// </summary>
            public AlmanacCommonContentDep Common { get { return _common; } }

            /// <summary>
            /// Mean anomaly at reference time
            /// </summary>
            public double M0 { get { return _m0; } }

            /// <summary>
            /// Eccentricity of satellite orbit
            /// </summary>
            public double Ecc { get { return _ecc; } }

            /// <summary>
            /// Square root of the semi-major axis of orbit
            /// </summary>
            public double Sqrta { get { return _sqrta; } }

            /// <summary>
            /// Longitude of ascending node of orbit plane at weekly epoch
            /// </summary>
            public double Omega0 { get { return _omega0; } }

            /// <summary>
            /// Rate of right ascension
            /// </summary>
            public double Omegadot { get { return _omegadot; } }

            /// <summary>
            /// Argument of perigee
            /// </summary>
            public double W { get { return _w; } }

            /// <summary>
            /// Inclination
            /// </summary>
            public double Inc { get { return _inc; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock bias)
            /// </summary>
            public double Af0 { get { return _af0; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock drift)
            /// </summary>
            public double Af1 { get { return _af1; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Satellite azimuth and elevation.
        /// </summary>
        public partial class SvAzEl : KaitaiStruct
        {
            public static SvAzEl FromFile(string fileName)
            {
                return new SvAzEl(new KaitaiStream(fileName));
            }

            public SvAzEl(KaitaiStream p__io, Observation.MsgSvAzEl p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _az = m_io.ReadU1();
                _el = m_io.ReadS1();
            }
            private Gnss.GnssSignal _sid;
            private byte _az;
            private sbyte _el;
            private Observation m_root;
            private Observation.MsgSvAzEl m_parent;

            /// <summary>
            /// GNSS signal identifier
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// Azimuth angle (range 0..179)
            /// </summary>
            public byte Az { get { return _az; } }

            /// <summary>
            /// Elevation angle (range -90..90)
            /// </summary>
            public sbyte El { get { return _el; } }
            public Observation M_Root { get { return m_root; } }
            public Observation.MsgSvAzEl M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The GLONASS L1/L2 Code-Phase biases allows to perform GPS+GLONASS
        /// integer ambiguity resolution for baselines with mixed receiver types
        /// (e.g. receiver of different manufacturers).
        /// </summary>
        public partial class MsgGloBiases : KaitaiStruct
        {
            public static MsgGloBiases FromFile(string fileName)
            {
                return new MsgGloBiases(new KaitaiStream(fileName));
            }

            public MsgGloBiases(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _mask = m_io.ReadU1();
                _l1caBias = m_io.ReadS2le();
                _l1pBias = m_io.ReadS2le();
                _l2caBias = m_io.ReadS2le();
                _l2pBias = m_io.ReadS2le();
            }
            private byte _mask;
            private short _l1caBias;
            private short _l1pBias;
            private short _l2caBias;
            private short _l2pBias;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GLONASS FDMA signals mask
            /// </summary>
            public byte Mask { get { return _mask; } }

            /// <summary>
            /// GLONASS L1 C/A Code-Phase Bias
            /// </summary>
            public short L1caBias { get { return _l1caBias; } }

            /// <summary>
            /// GLONASS L1 P Code-Phase Bias
            /// </summary>
            public short L1pBias { get { return _l1pBias; } }

            /// <summary>
            /// GLONASS L2 C/A Code-Phase Bias
            /// </summary>
            public short L2caBias { get { return _l2caBias; } }

            /// <summary>
            /// GLONASS L2 P Code-Phase Bias
            /// </summary>
            public short L2pBias { get { return _l2pBias; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This observation message has been deprecated in favor of ephemeris
        /// message using floats for size reduction.
        /// </summary>
        public partial class MsgEphemerisSbasDepB : KaitaiStruct
        {
            public static MsgEphemerisSbasDepB FromFile(string fileName)
            {
                return new MsgEphemerisSbasDepB(new KaitaiStream(fileName));
            }

            public MsgEphemerisSbasDepB(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new EphemerisCommonContentDepB(m_io, this, m_root);
                _pos = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _pos.Add(m_io.ReadF8le());
                }
                _vel = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _vel.Add(m_io.ReadF8le());
                }
                _acc = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _acc.Add(m_io.ReadF8le());
                }
                _aGf0 = m_io.ReadF8le();
                _aGf1 = m_io.ReadF8le();
            }
            private EphemerisCommonContentDepB _common;
            private List<double> _pos;
            private List<double> _vel;
            private List<double> _acc;
            private double _aGf0;
            private double _aGf1;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all ephemeris types
            /// </summary>
            public EphemerisCommonContentDepB Common { get { return _common; } }

            /// <summary>
            /// Position of the GEO at time toe
            /// </summary>
            public List<double> Pos { get { return _pos; } }

            /// <summary>
            /// Velocity of the GEO at time toe
            /// </summary>
            public List<double> Vel { get { return _vel; } }

            /// <summary>
            /// Acceleration of the GEO at time toe
            /// </summary>
            public List<double> Acc { get { return _acc; } }

            /// <summary>
            /// Time offset of the GEO clock w.r.t. SBAS Network Time
            /// </summary>
            public double AGf0 { get { return _aGf0; } }

            /// <summary>
            /// Drift of the GEO clock w.r.t. SBAS Network Time
            /// </summary>
            public double AGf1 { get { return _aGf1; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The ephemeris message returns a set of satellite orbit parameters that
        /// is used to calculate GPS satellite position, velocity, and clock offset.
        /// Please see the Navstar GPS Space Segment/Navigation user interfaces
        /// (ICD-GPS-200, Table 20-III) for more details.
        /// </summary>
        public partial class MsgEphemerisGpsDepE : KaitaiStruct
        {
            public static MsgEphemerisGpsDepE FromFile(string fileName)
            {
                return new MsgEphemerisGpsDepE(new KaitaiStream(fileName));
            }

            public MsgEphemerisGpsDepE(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new EphemerisCommonContentDepA(m_io, this, m_root);
                _tgd = m_io.ReadF8le();
                _cRs = m_io.ReadF8le();
                _cRc = m_io.ReadF8le();
                _cUc = m_io.ReadF8le();
                _cUs = m_io.ReadF8le();
                _cIc = m_io.ReadF8le();
                _cIs = m_io.ReadF8le();
                _dn = m_io.ReadF8le();
                _m0 = m_io.ReadF8le();
                _ecc = m_io.ReadF8le();
                _sqrta = m_io.ReadF8le();
                _omega0 = m_io.ReadF8le();
                _omegadot = m_io.ReadF8le();
                _w = m_io.ReadF8le();
                _inc = m_io.ReadF8le();
                _incDot = m_io.ReadF8le();
                _af0 = m_io.ReadF8le();
                _af1 = m_io.ReadF8le();
                _af2 = m_io.ReadF8le();
                _toc = new Gnss.GpsTimeDep(m_io, this, m_root);
                _iode = m_io.ReadU1();
                _iodc = m_io.ReadU2le();
            }
            private EphemerisCommonContentDepA _common;
            private double _tgd;
            private double _cRs;
            private double _cRc;
            private double _cUc;
            private double _cUs;
            private double _cIc;
            private double _cIs;
            private double _dn;
            private double _m0;
            private double _ecc;
            private double _sqrta;
            private double _omega0;
            private double _omegadot;
            private double _w;
            private double _inc;
            private double _incDot;
            private double _af0;
            private double _af1;
            private double _af2;
            private Gnss.GpsTimeDep _toc;
            private byte _iode;
            private ushort _iodc;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all ephemeris types
            /// </summary>
            public EphemerisCommonContentDepA Common { get { return _common; } }

            /// <summary>
            /// Group delay differential between L1 and L2
            /// </summary>
            public double Tgd { get { return _tgd; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the orbit radius
            /// </summary>
            public double CRs { get { return _cRs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the orbit radius
            /// </summary>
            public double CRc { get { return _cRc; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public double CUc { get { return _cUc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public double CUs { get { return _cUs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public double CIc { get { return _cIc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public double CIs { get { return _cIs; } }

            /// <summary>
            /// Mean motion difference
            /// </summary>
            public double Dn { get { return _dn; } }

            /// <summary>
            /// Mean anomaly at reference time
            /// </summary>
            public double M0 { get { return _m0; } }

            /// <summary>
            /// Eccentricity of satellite orbit
            /// </summary>
            public double Ecc { get { return _ecc; } }

            /// <summary>
            /// Square root of the semi-major axis of orbit
            /// </summary>
            public double Sqrta { get { return _sqrta; } }

            /// <summary>
            /// Longitude of ascending node of orbit plane at weekly epoch
            /// </summary>
            public double Omega0 { get { return _omega0; } }

            /// <summary>
            /// Rate of right ascension
            /// </summary>
            public double Omegadot { get { return _omegadot; } }

            /// <summary>
            /// Argument of perigee
            /// </summary>
            public double W { get { return _w; } }

            /// <summary>
            /// Inclination
            /// </summary>
            public double Inc { get { return _inc; } }

            /// <summary>
            /// Inclination first derivative
            /// </summary>
            public double IncDot { get { return _incDot; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock bias)
            /// </summary>
            public double Af0 { get { return _af0; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock drift)
            /// </summary>
            public double Af1 { get { return _af1; } }

            /// <summary>
            /// Polynomial clock correction coefficient (rate of clock drift)
            /// </summary>
            public double Af2 { get { return _af2; } }

            /// <summary>
            /// Clock reference
            /// </summary>
            public Gnss.GpsTimeDep Toc { get { return _toc; } }

            /// <summary>
            /// Issue of ephemeris data
            /// </summary>
            public byte Iode { get { return _iode; } }

            /// <summary>
            /// Issue of clock data
            /// </summary>
            public ushort Iodc { get { return _iodc; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        public partial class MsgGnssCapb : KaitaiStruct
        {
            public static MsgGnssCapb FromFile(string fileName)
            {
                return new MsgGnssCapb(new KaitaiStream(fileName));
            }

            public MsgGnssCapb(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tNmct = new Gnss.GpsTimeSec(m_io, this, m_root);
                _gc = new GnssCapb(m_io, this, m_root);
            }
            private Gnss.GpsTimeSec _tNmct;
            private GnssCapb _gc;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Navigation Message Correction Table Validity Time
            /// </summary>
            public Gnss.GpsTimeSec TNmct { get { return _tNmct; } }

            /// <summary>
            /// GNSS capabilities masks
            /// </summary>
            public GnssCapb Gc { get { return _gc; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The almanac message returns a set of satellite orbit parameters. Almanac
        /// data is not very precise and is considered valid for up to several
        /// months. Please see the Navstar GPS Space Segment/Navigation user
        /// interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more
        /// details.
        /// </summary>
        public partial class MsgAlmanacGps : KaitaiStruct
        {
            public static MsgAlmanacGps FromFile(string fileName)
            {
                return new MsgAlmanacGps(new KaitaiStream(fileName));
            }

            public MsgAlmanacGps(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new AlmanacCommonContent(m_io, this, m_root);
                _m0 = m_io.ReadF8le();
                _ecc = m_io.ReadF8le();
                _sqrta = m_io.ReadF8le();
                _omega0 = m_io.ReadF8le();
                _omegadot = m_io.ReadF8le();
                _w = m_io.ReadF8le();
                _inc = m_io.ReadF8le();
                _af0 = m_io.ReadF8le();
                _af1 = m_io.ReadF8le();
            }
            private AlmanacCommonContent _common;
            private double _m0;
            private double _ecc;
            private double _sqrta;
            private double _omega0;
            private double _omegadot;
            private double _w;
            private double _inc;
            private double _af0;
            private double _af1;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all almanac types
            /// </summary>
            public AlmanacCommonContent Common { get { return _common; } }

            /// <summary>
            /// Mean anomaly at reference time
            /// </summary>
            public double M0 { get { return _m0; } }

            /// <summary>
            /// Eccentricity of satellite orbit
            /// </summary>
            public double Ecc { get { return _ecc; } }

            /// <summary>
            /// Square root of the semi-major axis of orbit
            /// </summary>
            public double Sqrta { get { return _sqrta; } }

            /// <summary>
            /// Longitude of ascending node of orbit plane at weekly epoch
            /// </summary>
            public double Omega0 { get { return _omega0; } }

            /// <summary>
            /// Rate of right ascension
            /// </summary>
            public double Omegadot { get { return _omegadot; } }

            /// <summary>
            /// Argument of perigee
            /// </summary>
            public double W { get { return _w; } }

            /// <summary>
            /// Inclination
            /// </summary>
            public double Inc { get { return _inc; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock bias)
            /// </summary>
            public double Af0 { get { return _af0; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock drift)
            /// </summary>
            public double Af1 { get { return _af1; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The ephemeris message returns a set of satellite orbit parameters that
        /// is used to calculate QZSS satellite position, velocity, and clock
        /// offset.
        /// </summary>
        public partial class MsgEphemerisQzss : KaitaiStruct
        {
            public static MsgEphemerisQzss FromFile(string fileName)
            {
                return new MsgEphemerisQzss(new KaitaiStream(fileName));
            }

            public MsgEphemerisQzss(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new EphemerisCommonContent(m_io, this, m_root);
                _tgd = m_io.ReadF4le();
                _cRs = m_io.ReadF4le();
                _cRc = m_io.ReadF4le();
                _cUc = m_io.ReadF4le();
                _cUs = m_io.ReadF4le();
                _cIc = m_io.ReadF4le();
                _cIs = m_io.ReadF4le();
                _dn = m_io.ReadF8le();
                _m0 = m_io.ReadF8le();
                _ecc = m_io.ReadF8le();
                _sqrta = m_io.ReadF8le();
                _omega0 = m_io.ReadF8le();
                _omegadot = m_io.ReadF8le();
                _w = m_io.ReadF8le();
                _inc = m_io.ReadF8le();
                _incDot = m_io.ReadF8le();
                _af0 = m_io.ReadF4le();
                _af1 = m_io.ReadF4le();
                _af2 = m_io.ReadF4le();
                _toc = new Gnss.GpsTimeSec(m_io, this, m_root);
                _iode = m_io.ReadU1();
                _iodc = m_io.ReadU2le();
            }
            private EphemerisCommonContent _common;
            private float _tgd;
            private float _cRs;
            private float _cRc;
            private float _cUc;
            private float _cUs;
            private float _cIc;
            private float _cIs;
            private double _dn;
            private double _m0;
            private double _ecc;
            private double _sqrta;
            private double _omega0;
            private double _omegadot;
            private double _w;
            private double _inc;
            private double _incDot;
            private float _af0;
            private float _af1;
            private float _af2;
            private Gnss.GpsTimeSec _toc;
            private byte _iode;
            private ushort _iodc;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all ephemeris types
            /// </summary>
            public EphemerisCommonContent Common { get { return _common; } }

            /// <summary>
            /// Group delay differential between L1 and L2
            /// </summary>
            public float Tgd { get { return _tgd; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the orbit radius
            /// </summary>
            public float CRs { get { return _cRs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the orbit radius
            /// </summary>
            public float CRc { get { return _cRc; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public float CUc { get { return _cUc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public float CUs { get { return _cUs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public float CIc { get { return _cIc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public float CIs { get { return _cIs; } }

            /// <summary>
            /// Mean motion difference
            /// </summary>
            public double Dn { get { return _dn; } }

            /// <summary>
            /// Mean anomaly at reference time
            /// </summary>
            public double M0 { get { return _m0; } }

            /// <summary>
            /// Eccentricity of satellite orbit
            /// </summary>
            public double Ecc { get { return _ecc; } }

            /// <summary>
            /// Square root of the semi-major axis of orbit
            /// </summary>
            public double Sqrta { get { return _sqrta; } }

            /// <summary>
            /// Longitude of ascending node of orbit plane at weekly epoch
            /// </summary>
            public double Omega0 { get { return _omega0; } }

            /// <summary>
            /// Rate of right ascension
            /// </summary>
            public double Omegadot { get { return _omegadot; } }

            /// <summary>
            /// Argument of perigee
            /// </summary>
            public double W { get { return _w; } }

            /// <summary>
            /// Inclination
            /// </summary>
            public double Inc { get { return _inc; } }

            /// <summary>
            /// Inclination first derivative
            /// </summary>
            public double IncDot { get { return _incDot; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock bias)
            /// </summary>
            public float Af0 { get { return _af0; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock drift)
            /// </summary>
            public float Af1 { get { return _af1; } }

            /// <summary>
            /// Polynomial clock correction coefficient (rate of clock drift)
            /// </summary>
            public float Af2 { get { return _af2; } }

            /// <summary>
            /// Clock reference
            /// </summary>
            public Gnss.GpsTimeSec Toc { get { return _toc; } }

            /// <summary>
            /// Issue of ephemeris data
            /// </summary>
            public byte Iode { get { return _iode; } }

            /// <summary>
            /// Issue of clock data
            /// </summary>
            public ushort Iodc { get { return _iodc; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
        /// </summary>
        public partial class MsgGroupDelayDepA : KaitaiStruct
        {
            public static MsgGroupDelayDepA FromFile(string fileName)
            {
                return new MsgGroupDelayDepA(new KaitaiStream(fileName));
            }

            public MsgGroupDelayDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tOp = new Gnss.GpsTimeDep(m_io, this, m_root);
                _prn = m_io.ReadU1();
                _valid = m_io.ReadU1();
                _tgd = m_io.ReadS2le();
                _iscL1ca = m_io.ReadS2le();
                _iscL2c = m_io.ReadS2le();
            }
            private Gnss.GpsTimeDep _tOp;
            private byte _prn;
            private byte _valid;
            private short _tgd;
            private short _iscL1ca;
            private short _iscL2c;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Data Predict Time of Week
            /// </summary>
            public Gnss.GpsTimeDep TOp { get { return _tOp; } }

            /// <summary>
            /// Satellite number
            /// </summary>
            public byte Prn { get { return _prn; } }

            /// <summary>
            /// bit-field indicating validity of the values, LSB indicating tgd
            /// validity etc. 1 = value is valid, 0 = value is not valid.
            /// </summary>
            public byte Valid { get { return _valid; } }
            public short Tgd { get { return _tgd; } }
            public short IscL1ca { get { return _iscL1ca; } }
            public short IscL2c { get { return _iscL2c; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The ephemeris message returns a set of satellite orbit parameters that
        /// is used to calculate GPS satellite position, velocity, and clock offset.
        /// Please see the Navstar GPS Space Segment/Navigation user interfaces
        /// (ICD-GPS-200, Table 20-III) for more details.
        /// </summary>
        public partial class MsgEphemerisDepC : KaitaiStruct
        {
            public static MsgEphemerisDepC FromFile(string fileName)
            {
                return new MsgEphemerisDepC(new KaitaiStream(fileName));
            }

            public MsgEphemerisDepC(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tgd = m_io.ReadF8le();
                _cRs = m_io.ReadF8le();
                _cRc = m_io.ReadF8le();
                _cUc = m_io.ReadF8le();
                _cUs = m_io.ReadF8le();
                _cIc = m_io.ReadF8le();
                _cIs = m_io.ReadF8le();
                _dn = m_io.ReadF8le();
                _m0 = m_io.ReadF8le();
                _ecc = m_io.ReadF8le();
                _sqrta = m_io.ReadF8le();
                _omega0 = m_io.ReadF8le();
                _omegadot = m_io.ReadF8le();
                _w = m_io.ReadF8le();
                _inc = m_io.ReadF8le();
                _incDot = m_io.ReadF8le();
                _af0 = m_io.ReadF8le();
                _af1 = m_io.ReadF8le();
                _af2 = m_io.ReadF8le();
                _toeTow = m_io.ReadF8le();
                _toeWn = m_io.ReadU2le();
                _tocTow = m_io.ReadF8le();
                _tocWn = m_io.ReadU2le();
                _valid = m_io.ReadU1();
                _healthy = m_io.ReadU1();
                _sid = new Gnss.GnssSignalDep(m_io, this, m_root);
                _iode = m_io.ReadU1();
                _iodc = m_io.ReadU2le();
                _reserved = m_io.ReadU4le();
            }
            private double _tgd;
            private double _cRs;
            private double _cRc;
            private double _cUc;
            private double _cUs;
            private double _cIc;
            private double _cIs;
            private double _dn;
            private double _m0;
            private double _ecc;
            private double _sqrta;
            private double _omega0;
            private double _omegadot;
            private double _w;
            private double _inc;
            private double _incDot;
            private double _af0;
            private double _af1;
            private double _af2;
            private double _toeTow;
            private ushort _toeWn;
            private double _tocTow;
            private ushort _tocWn;
            private byte _valid;
            private byte _healthy;
            private Gnss.GnssSignalDep _sid;
            private byte _iode;
            private ushort _iodc;
            private uint _reserved;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Group delay differential between L1 and L2
            /// </summary>
            public double Tgd { get { return _tgd; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the orbit radius
            /// </summary>
            public double CRs { get { return _cRs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the orbit radius
            /// </summary>
            public double CRc { get { return _cRc; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public double CUc { get { return _cUc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public double CUs { get { return _cUs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public double CIc { get { return _cIc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public double CIs { get { return _cIs; } }

            /// <summary>
            /// Mean motion difference
            /// </summary>
            public double Dn { get { return _dn; } }

            /// <summary>
            /// Mean anomaly at reference time
            /// </summary>
            public double M0 { get { return _m0; } }

            /// <summary>
            /// Eccentricity of satellite orbit
            /// </summary>
            public double Ecc { get { return _ecc; } }

            /// <summary>
            /// Square root of the semi-major axis of orbit
            /// </summary>
            public double Sqrta { get { return _sqrta; } }

            /// <summary>
            /// Longitude of ascending node of orbit plane at weekly epoch
            /// </summary>
            public double Omega0 { get { return _omega0; } }

            /// <summary>
            /// Rate of right ascension
            /// </summary>
            public double Omegadot { get { return _omegadot; } }

            /// <summary>
            /// Argument of perigee
            /// </summary>
            public double W { get { return _w; } }

            /// <summary>
            /// Inclination
            /// </summary>
            public double Inc { get { return _inc; } }

            /// <summary>
            /// Inclination first derivative
            /// </summary>
            public double IncDot { get { return _incDot; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock bias)
            /// </summary>
            public double Af0 { get { return _af0; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock drift)
            /// </summary>
            public double Af1 { get { return _af1; } }

            /// <summary>
            /// Polynomial clock correction coefficient (rate of clock drift)
            /// </summary>
            public double Af2 { get { return _af2; } }

            /// <summary>
            /// Time of week
            /// </summary>
            public double ToeTow { get { return _toeTow; } }

            /// <summary>
            /// Week number
            /// </summary>
            public ushort ToeWn { get { return _toeWn; } }

            /// <summary>
            /// Clock reference time of week
            /// </summary>
            public double TocTow { get { return _tocTow; } }

            /// <summary>
            /// Clock reference week number
            /// </summary>
            public ushort TocWn { get { return _tocWn; } }

            /// <summary>
            /// Is valid?
            /// </summary>
            public byte Valid { get { return _valid; } }

            /// <summary>
            /// Satellite is healthy?
            /// </summary>
            public byte Healthy { get { return _healthy; } }

            /// <summary>
            /// GNSS signal identifier
            /// </summary>
            public Gnss.GnssSignalDep Sid { get { return _sid; } }

            /// <summary>
            /// Issue of ephemeris data
            /// </summary>
            public byte Iode { get { return _iode; } }

            /// <summary>
            /// Issue of clock data
            /// </summary>
            public ushort Iodc { get { return _iodc; } }

            /// <summary>
            /// Reserved field
            /// </summary>
            public uint Reserved { get { return _reserved; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Carrier phase measurement in cycles represented as a 40-bit fixed point
        /// number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
        /// fractional cycles. This has the opposite sign convention than a typical
        /// GPS receiver and the phase has the opposite sign as the pseudorange.
        /// </summary>
        public partial class CarrierPhaseDepA : KaitaiStruct
        {
            public static CarrierPhaseDepA FromFile(string fileName)
            {
                return new CarrierPhaseDepA(new KaitaiStream(fileName));
            }

            public CarrierPhaseDepA(KaitaiStream p__io, KaitaiStruct p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _i = m_io.ReadS4le();
                _f = m_io.ReadU1();
            }
            private int _i;
            private byte _f;
            private Observation m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// Carrier phase whole cycles
            /// </summary>
            public int I { get { return _i; } }

            /// <summary>
            /// Carrier phase fractional part
            /// </summary>
            public byte F { get { return _f; } }
            public Observation M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The ephemeris message returns a set of satellite orbit parameters that
        /// is used to calculate Galileo satellite position, velocity, and clock
        /// offset. Please see the Signal In Space ICD OS SIS ICD, Issue 1.3,
        /// December 2016 for more details.
        /// </summary>
        public partial class MsgEphemerisGal : KaitaiStruct
        {
            public static MsgEphemerisGal FromFile(string fileName)
            {
                return new MsgEphemerisGal(new KaitaiStream(fileName));
            }

            public MsgEphemerisGal(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new EphemerisCommonContent(m_io, this, m_root);
                _bgdE1e5a = m_io.ReadF4le();
                _bgdE1e5b = m_io.ReadF4le();
                _cRs = m_io.ReadF4le();
                _cRc = m_io.ReadF4le();
                _cUc = m_io.ReadF4le();
                _cUs = m_io.ReadF4le();
                _cIc = m_io.ReadF4le();
                _cIs = m_io.ReadF4le();
                _dn = m_io.ReadF8le();
                _m0 = m_io.ReadF8le();
                _ecc = m_io.ReadF8le();
                _sqrta = m_io.ReadF8le();
                _omega0 = m_io.ReadF8le();
                _omegadot = m_io.ReadF8le();
                _w = m_io.ReadF8le();
                _inc = m_io.ReadF8le();
                _incDot = m_io.ReadF8le();
                _af0 = m_io.ReadF8le();
                _af1 = m_io.ReadF8le();
                _af2 = m_io.ReadF4le();
                _toc = new Gnss.GpsTimeSec(m_io, this, m_root);
                _iode = m_io.ReadU2le();
                _iodc = m_io.ReadU2le();
                _source = m_io.ReadU1();
            }
            private EphemerisCommonContent _common;
            private float _bgdE1e5a;
            private float _bgdE1e5b;
            private float _cRs;
            private float _cRc;
            private float _cUc;
            private float _cUs;
            private float _cIc;
            private float _cIs;
            private double _dn;
            private double _m0;
            private double _ecc;
            private double _sqrta;
            private double _omega0;
            private double _omegadot;
            private double _w;
            private double _inc;
            private double _incDot;
            private double _af0;
            private double _af1;
            private float _af2;
            private Gnss.GpsTimeSec _toc;
            private ushort _iode;
            private ushort _iodc;
            private byte _source;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all ephemeris types
            /// </summary>
            public EphemerisCommonContent Common { get { return _common; } }

            /// <summary>
            /// E1-E5a Broadcast Group Delay
            /// </summary>
            public float BgdE1e5a { get { return _bgdE1e5a; } }

            /// <summary>
            /// E1-E5b Broadcast Group Delay
            /// </summary>
            public float BgdE1e5b { get { return _bgdE1e5b; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the orbit radius
            /// </summary>
            public float CRs { get { return _cRs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the orbit radius
            /// </summary>
            public float CRc { get { return _cRc; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public float CUc { get { return _cUc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public float CUs { get { return _cUs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public float CIc { get { return _cIc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public float CIs { get { return _cIs; } }

            /// <summary>
            /// Mean motion difference
            /// </summary>
            public double Dn { get { return _dn; } }

            /// <summary>
            /// Mean anomaly at reference time
            /// </summary>
            public double M0 { get { return _m0; } }

            /// <summary>
            /// Eccentricity of satellite orbit
            /// </summary>
            public double Ecc { get { return _ecc; } }

            /// <summary>
            /// Square root of the semi-major axis of orbit
            /// </summary>
            public double Sqrta { get { return _sqrta; } }

            /// <summary>
            /// Longitude of ascending node of orbit plane at weekly epoch
            /// </summary>
            public double Omega0 { get { return _omega0; } }

            /// <summary>
            /// Rate of right ascension
            /// </summary>
            public double Omegadot { get { return _omegadot; } }

            /// <summary>
            /// Argument of perigee
            /// </summary>
            public double W { get { return _w; } }

            /// <summary>
            /// Inclination
            /// </summary>
            public double Inc { get { return _inc; } }

            /// <summary>
            /// Inclination first derivative
            /// </summary>
            public double IncDot { get { return _incDot; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock bias)
            /// </summary>
            public double Af0 { get { return _af0; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock drift)
            /// </summary>
            public double Af1 { get { return _af1; } }

            /// <summary>
            /// Polynomial clock correction coefficient (rate of clock drift)
            /// </summary>
            public float Af2 { get { return _af2; } }

            /// <summary>
            /// Clock reference
            /// </summary>
            public Gnss.GpsTimeSec Toc { get { return _toc; } }

            /// <summary>
            /// Issue of data (IODnav)
            /// </summary>
            public ushort Iode { get { return _iode; } }

            /// <summary>
            /// Issue of data (IODnav). Always equal to iode
            /// </summary>
            public ushort Iodc { get { return _iodc; } }

            /// <summary>
            /// 0=I/NAV, 1=F/NAV
            /// </summary>
            public byte Source { get { return _source; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Pseudorange and carrier phase network corrections for a satellite
        /// signal.
        /// </summary>
        public partial class PackedOsrContent : KaitaiStruct
        {
            public static PackedOsrContent FromFile(string fileName)
            {
                return new PackedOsrContent(new KaitaiStream(fileName));
            }

            public PackedOsrContent(KaitaiStream p__io, Observation.MsgOsr p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _p = m_io.ReadU4le();
                _l = new Gnss.CarrierPhase(m_io, this, m_root);
                _lock = m_io.ReadU1();
                _flags = m_io.ReadU1();
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _ionoStd = m_io.ReadU2le();
                _tropoStd = m_io.ReadU2le();
                _rangeStd = m_io.ReadU2le();
            }
            private uint _p;
            private Gnss.CarrierPhase _l;
            private byte _lock;
            private byte _flags;
            private Gnss.GnssSignal _sid;
            private ushort _ionoStd;
            private ushort _tropoStd;
            private ushort _rangeStd;
            private Observation m_root;
            private Observation.MsgOsr m_parent;

            /// <summary>
            /// Pseudorange observation
            /// </summary>
            public uint P { get { return _p; } }

            /// <summary>
            /// Carrier phase observation with typical sign convention.
            /// </summary>
            public Gnss.CarrierPhase L { get { return _l; } }

            /// <summary>
            /// Lock timer. This value gives an indication of the time for which a
            /// signal has maintained continuous phase lock. Whenever a signal has
            /// lost and regained lock, this value is reset to zero. It is encoded
            /// according to DF402 from the RTCM 10403.2 Amendment 2 specification.
            /// Valid values range from 0 to 15 and the most significant nibble is
            /// reserved for future use.
            /// </summary>
            public byte Lock { get { return _lock; } }

            /// <summary>
            /// Correction flags.
            /// </summary>
            public byte Flags { get { return _flags; } }

            /// <summary>
            /// GNSS signal identifier (16 bit)
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// Slant ionospheric correction standard deviation
            /// </summary>
            public ushort IonoStd { get { return _ionoStd; } }

            /// <summary>
            /// Slant tropospheric correction standard deviation
            /// </summary>
            public ushort TropoStd { get { return _tropoStd; } }

            /// <summary>
            /// Orbit/clock/bias correction projected on range standard deviation
            /// </summary>
            public ushort RangeStd { get { return _rangeStd; } }
            public Observation M_Root { get { return m_root; } }
            public Observation.MsgOsr M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The ephemeris message returns a set of satellite orbit parameters that
        /// is used to calculate BDS satellite position, velocity, and clock offset.
        /// Please see the BeiDou Navigation Satellite System SIS-ICD Version 2.1,
        /// Table 5-9 for more details.
        /// </summary>
        public partial class MsgEphemerisBds : KaitaiStruct
        {
            public static MsgEphemerisBds FromFile(string fileName)
            {
                return new MsgEphemerisBds(new KaitaiStream(fileName));
            }

            public MsgEphemerisBds(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new EphemerisCommonContent(m_io, this, m_root);
                _tgd1 = m_io.ReadF4le();
                _tgd2 = m_io.ReadF4le();
                _cRs = m_io.ReadF4le();
                _cRc = m_io.ReadF4le();
                _cUc = m_io.ReadF4le();
                _cUs = m_io.ReadF4le();
                _cIc = m_io.ReadF4le();
                _cIs = m_io.ReadF4le();
                _dn = m_io.ReadF8le();
                _m0 = m_io.ReadF8le();
                _ecc = m_io.ReadF8le();
                _sqrta = m_io.ReadF8le();
                _omega0 = m_io.ReadF8le();
                _omegadot = m_io.ReadF8le();
                _w = m_io.ReadF8le();
                _inc = m_io.ReadF8le();
                _incDot = m_io.ReadF8le();
                _af0 = m_io.ReadF8le();
                _af1 = m_io.ReadF4le();
                _af2 = m_io.ReadF4le();
                _toc = new Gnss.GpsTimeSec(m_io, this, m_root);
                _iode = m_io.ReadU1();
                _iodc = m_io.ReadU2le();
            }
            private EphemerisCommonContent _common;
            private float _tgd1;
            private float _tgd2;
            private float _cRs;
            private float _cRc;
            private float _cUc;
            private float _cUs;
            private float _cIc;
            private float _cIs;
            private double _dn;
            private double _m0;
            private double _ecc;
            private double _sqrta;
            private double _omega0;
            private double _omegadot;
            private double _w;
            private double _inc;
            private double _incDot;
            private double _af0;
            private float _af1;
            private float _af2;
            private Gnss.GpsTimeSec _toc;
            private byte _iode;
            private ushort _iodc;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all ephemeris types
            /// </summary>
            public EphemerisCommonContent Common { get { return _common; } }

            /// <summary>
            /// Group delay differential for B1
            /// </summary>
            public float Tgd1 { get { return _tgd1; } }

            /// <summary>
            /// Group delay differential for B2
            /// </summary>
            public float Tgd2 { get { return _tgd2; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the orbit radius
            /// </summary>
            public float CRs { get { return _cRs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the orbit radius
            /// </summary>
            public float CRc { get { return _cRc; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public float CUc { get { return _cUc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public float CUs { get { return _cUs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public float CIc { get { return _cIc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public float CIs { get { return _cIs; } }

            /// <summary>
            /// Mean motion difference
            /// </summary>
            public double Dn { get { return _dn; } }

            /// <summary>
            /// Mean anomaly at reference time
            /// </summary>
            public double M0 { get { return _m0; } }

            /// <summary>
            /// Eccentricity of satellite orbit
            /// </summary>
            public double Ecc { get { return _ecc; } }

            /// <summary>
            /// Square root of the semi-major axis of orbit
            /// </summary>
            public double Sqrta { get { return _sqrta; } }

            /// <summary>
            /// Longitude of ascending node of orbit plane at weekly epoch
            /// </summary>
            public double Omega0 { get { return _omega0; } }

            /// <summary>
            /// Rate of right ascension
            /// </summary>
            public double Omegadot { get { return _omegadot; } }

            /// <summary>
            /// Argument of perigee
            /// </summary>
            public double W { get { return _w; } }

            /// <summary>
            /// Inclination
            /// </summary>
            public double Inc { get { return _inc; } }

            /// <summary>
            /// Inclination first derivative
            /// </summary>
            public double IncDot { get { return _incDot; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock bias)
            /// </summary>
            public double Af0 { get { return _af0; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock drift)
            /// </summary>
            public float Af1 { get { return _af1; } }

            /// <summary>
            /// Polynomial clock correction coefficient (rate of clock drift)
            /// </summary>
            public float Af2 { get { return _af2; } }

            /// <summary>
            /// Clock reference
            /// </summary>
            public Gnss.GpsTimeSec Toc { get { return _toc; } }

            /// <summary>
            /// Issue of ephemeris data
            /// Calculated from the navigation data parameter t_oe per RTCM/CSNO
            /// recommendation: IODE = mod (t_oe / 720, 240)
            /// </summary>
            public byte Iode { get { return _iode; } }

            /// <summary>
            /// Issue of clock data
            /// Calculated from the navigation data parameter t_oe per RTCM/CSNO
            /// recommendation: IODE = mod (t_oc / 720, 240)
            /// </summary>
            public ushort Iodc { get { return _iodc; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This observation message has been deprecated in favor of ephemeris
        /// message using floats for size reduction.
        /// </summary>
        public partial class MsgEphemerisGpsDepF : KaitaiStruct
        {
            public static MsgEphemerisGpsDepF FromFile(string fileName)
            {
                return new MsgEphemerisGpsDepF(new KaitaiStream(fileName));
            }

            public MsgEphemerisGpsDepF(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new EphemerisCommonContentDepB(m_io, this, m_root);
                _tgd = m_io.ReadF8le();
                _cRs = m_io.ReadF8le();
                _cRc = m_io.ReadF8le();
                _cUc = m_io.ReadF8le();
                _cUs = m_io.ReadF8le();
                _cIc = m_io.ReadF8le();
                _cIs = m_io.ReadF8le();
                _dn = m_io.ReadF8le();
                _m0 = m_io.ReadF8le();
                _ecc = m_io.ReadF8le();
                _sqrta = m_io.ReadF8le();
                _omega0 = m_io.ReadF8le();
                _omegadot = m_io.ReadF8le();
                _w = m_io.ReadF8le();
                _inc = m_io.ReadF8le();
                _incDot = m_io.ReadF8le();
                _af0 = m_io.ReadF8le();
                _af1 = m_io.ReadF8le();
                _af2 = m_io.ReadF8le();
                _toc = new Gnss.GpsTimeSec(m_io, this, m_root);
                _iode = m_io.ReadU1();
                _iodc = m_io.ReadU2le();
            }
            private EphemerisCommonContentDepB _common;
            private double _tgd;
            private double _cRs;
            private double _cRc;
            private double _cUc;
            private double _cUs;
            private double _cIc;
            private double _cIs;
            private double _dn;
            private double _m0;
            private double _ecc;
            private double _sqrta;
            private double _omega0;
            private double _omegadot;
            private double _w;
            private double _inc;
            private double _incDot;
            private double _af0;
            private double _af1;
            private double _af2;
            private Gnss.GpsTimeSec _toc;
            private byte _iode;
            private ushort _iodc;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all ephemeris types
            /// </summary>
            public EphemerisCommonContentDepB Common { get { return _common; } }

            /// <summary>
            /// Group delay differential between L1 and L2
            /// </summary>
            public double Tgd { get { return _tgd; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the orbit radius
            /// </summary>
            public double CRs { get { return _cRs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the orbit radius
            /// </summary>
            public double CRc { get { return _cRc; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public double CUc { get { return _cUc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public double CUs { get { return _cUs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public double CIc { get { return _cIc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public double CIs { get { return _cIs; } }

            /// <summary>
            /// Mean motion difference
            /// </summary>
            public double Dn { get { return _dn; } }

            /// <summary>
            /// Mean anomaly at reference time
            /// </summary>
            public double M0 { get { return _m0; } }

            /// <summary>
            /// Eccentricity of satellite orbit
            /// </summary>
            public double Ecc { get { return _ecc; } }

            /// <summary>
            /// Square root of the semi-major axis of orbit
            /// </summary>
            public double Sqrta { get { return _sqrta; } }

            /// <summary>
            /// Longitude of ascending node of orbit plane at weekly epoch
            /// </summary>
            public double Omega0 { get { return _omega0; } }

            /// <summary>
            /// Rate of right ascension
            /// </summary>
            public double Omegadot { get { return _omegadot; } }

            /// <summary>
            /// Argument of perigee
            /// </summary>
            public double W { get { return _w; } }

            /// <summary>
            /// Inclination
            /// </summary>
            public double Inc { get { return _inc; } }

            /// <summary>
            /// Inclination first derivative
            /// </summary>
            public double IncDot { get { return _incDot; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock bias)
            /// </summary>
            public double Af0 { get { return _af0; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock drift)
            /// </summary>
            public double Af1 { get { return _af1; } }

            /// <summary>
            /// Polynomial clock correction coefficient (rate of clock drift)
            /// </summary>
            public double Af2 { get { return _af2; } }

            /// <summary>
            /// Clock reference
            /// </summary>
            public Gnss.GpsTimeSec Toc { get { return _toc; } }

            /// <summary>
            /// Issue of ephemeris data
            /// </summary>
            public byte Iode { get { return _iode; } }

            /// <summary>
            /// Issue of clock data
            /// </summary>
            public ushort Iodc { get { return _iodc; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Header of a GNSS observation message.
        /// </summary>
        public partial class ObservationHeader : KaitaiStruct
        {
            public static ObservationHeader FromFile(string fileName)
            {
                return new ObservationHeader(new KaitaiStream(fileName));
            }

            public ObservationHeader(KaitaiStream p__io, KaitaiStruct p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _t = new Gnss.GpsTime(m_io, this, m_root);
                _nObs = m_io.ReadU1();
            }
            private Gnss.GpsTime _t;
            private byte _nObs;
            private Observation m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// GNSS time of this observation
            /// </summary>
            public Gnss.GpsTime T { get { return _t; } }

            /// <summary>
            /// Total number of observations. First nibble is the size of the
            /// sequence (n), second nibble is the zero-indexed counter (ith packet
            /// of n)
            /// </summary>
            public byte NObs { get { return _nObs; } }
            public Observation M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }
        public partial class MsgEphemerisSbasDepA : KaitaiStruct
        {
            public static MsgEphemerisSbasDepA FromFile(string fileName)
            {
                return new MsgEphemerisSbasDepA(new KaitaiStream(fileName));
            }

            public MsgEphemerisSbasDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new EphemerisCommonContentDepA(m_io, this, m_root);
                _pos = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _pos.Add(m_io.ReadF8le());
                }
                _vel = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _vel.Add(m_io.ReadF8le());
                }
                _acc = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _acc.Add(m_io.ReadF8le());
                }
                _aGf0 = m_io.ReadF8le();
                _aGf1 = m_io.ReadF8le();
            }
            private EphemerisCommonContentDepA _common;
            private List<double> _pos;
            private List<double> _vel;
            private List<double> _acc;
            private double _aGf0;
            private double _aGf1;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all ephemeris types
            /// </summary>
            public EphemerisCommonContentDepA Common { get { return _common; } }

            /// <summary>
            /// Position of the GEO at time toe
            /// </summary>
            public List<double> Pos { get { return _pos; } }

            /// <summary>
            /// Velocity of the GEO at time toe
            /// </summary>
            public List<double> Vel { get { return _vel; } }

            /// <summary>
            /// Acceleration of the GEO at time toe
            /// </summary>
            public List<double> Acc { get { return _acc; } }

            /// <summary>
            /// Time offset of the GEO clock w.r.t. SBAS Network Time
            /// </summary>
            public double AGf0 { get { return _aGf0; } }

            /// <summary>
            /// Drift of the GEO clock w.r.t. SBAS Network Time
            /// </summary>
            public double AGf1 { get { return _aGf1; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Pseudorange and carrier phase observation for a satellite being tracked.
        /// The observations are interoperable with 3rd party receivers and conform
        /// with typical RTCM 3.1 message GPS/GLO observations.
        /// 
        /// Carrier phase observations are not guaranteed to be aligned to the RINEX
        /// 3 or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are
        /// currently performed.
        /// </summary>
        public partial class PackedObsContent : KaitaiStruct
        {
            public static PackedObsContent FromFile(string fileName)
            {
                return new PackedObsContent(new KaitaiStream(fileName));
            }

            public PackedObsContent(KaitaiStream p__io, Observation.MsgObs p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _p = m_io.ReadU4le();
                _l = new Gnss.CarrierPhase(m_io, this, m_root);
                _d = new Doppler(m_io, this, m_root);
                _cn0 = m_io.ReadU1();
                _lock = m_io.ReadU1();
                _flags = m_io.ReadU1();
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
            }
            private uint _p;
            private Gnss.CarrierPhase _l;
            private Doppler _d;
            private byte _cn0;
            private byte _lock;
            private byte _flags;
            private Gnss.GnssSignal _sid;
            private Observation m_root;
            private Observation.MsgObs m_parent;

            /// <summary>
            /// Pseudorange observation
            /// </summary>
            public uint P { get { return _p; } }

            /// <summary>
            /// Carrier phase observation with typical sign convention.
            /// </summary>
            public Gnss.CarrierPhase L { get { return _l; } }

            /// <summary>
            /// Doppler observation with typical sign convention.
            /// </summary>
            public Doppler D { get { return _d; } }

            /// <summary>
            /// Carrier-to-Noise density.  Zero implies invalid cn0.
            /// </summary>
            public byte Cn0 { get { return _cn0; } }

            /// <summary>
            /// Lock timer. This value gives an indication of the time for which a
            /// signal has maintained continuous phase lock. Whenever a signal has
            /// lost and regained lock, this value is reset to zero. It is encoded
            /// according to DF402 from the RTCM 10403.2 Amendment 2 specification.
            /// Valid values range from 0 to 15 and the most significant nibble is
            /// reserved for future use.
            /// </summary>
            public byte Lock { get { return _lock; } }

            /// <summary>
            /// Measurement status flags. A bit field of flags providing the status
            /// of this observation.  If this field is 0 it means only the Cn0
            /// estimate for the signal is valid.
            /// </summary>
            public byte Flags { get { return _flags; } }

            /// <summary>
            /// GNSS signal identifier (16 bit)
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }
            public Observation M_Root { get { return m_root; } }
            public Observation.MsgObs M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The base station position message is the position reported by the base
        /// station itself in absolute Earth Centered Earth Fixed coordinates. It is
        /// used for pseudo-absolute RTK positioning, and is required to be a high-
        /// accuracy surveyed location of the base station. Any error here will
        /// result in an error in the pseudo-absolute position output.
        /// </summary>
        public partial class MsgBasePosEcef : KaitaiStruct
        {
            public static MsgBasePosEcef FromFile(string fileName)
            {
                return new MsgBasePosEcef(new KaitaiStream(fileName));
            }

            public MsgBasePosEcef(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _x = m_io.ReadF8le();
                _y = m_io.ReadF8le();
                _z = m_io.ReadF8le();
            }
            private double _x;
            private double _y;
            private double _z;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// ECEF X coordinate
            /// </summary>
            public double X { get { return _x; } }

            /// <summary>
            /// ECEF Y coordinate
            /// </summary>
            public double Y { get { return _y; } }

            /// <summary>
            /// ECEF Z coordinate
            /// </summary>
            public double Z { get { return _z; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The ephemeris message returns a set of satellite orbit parameters that
        /// is used to calculate GLO satellite position, velocity, and clock offset.
        /// Please see the GLO ICD 5.1 &quot;Table 4.5 Characteristics of words of
        /// immediate information (ephemeris parameters)&quot; for more details.
        /// </summary>
        public partial class MsgEphemerisGloDepA : KaitaiStruct
        {
            public static MsgEphemerisGloDepA FromFile(string fileName)
            {
                return new MsgEphemerisGloDepA(new KaitaiStream(fileName));
            }

            public MsgEphemerisGloDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new EphemerisCommonContentDepA(m_io, this, m_root);
                _gamma = m_io.ReadF8le();
                _tau = m_io.ReadF8le();
                _pos = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _pos.Add(m_io.ReadF8le());
                }
                _vel = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _vel.Add(m_io.ReadF8le());
                }
                _acc = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _acc.Add(m_io.ReadF8le());
                }
            }
            private EphemerisCommonContentDepA _common;
            private double _gamma;
            private double _tau;
            private List<double> _pos;
            private List<double> _vel;
            private List<double> _acc;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all ephemeris types
            /// </summary>
            public EphemerisCommonContentDepA Common { get { return _common; } }

            /// <summary>
            /// Relative deviation of predicted carrier frequency from nominal
            /// </summary>
            public double Gamma { get { return _gamma; } }

            /// <summary>
            /// Correction to the SV time
            /// </summary>
            public double Tau { get { return _tau; } }

            /// <summary>
            /// Position of the SV at tb in PZ-90.02 coordinates system
            /// </summary>
            public List<double> Pos { get { return _pos; } }

            /// <summary>
            /// Velocity vector of the SV at tb in PZ-90.02 coordinates system
            /// </summary>
            public List<double> Vel { get { return _vel; } }

            /// <summary>
            /// Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
            /// </summary>
            public List<double> Acc { get { return _acc; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
        /// </summary>
        public partial class MsgGroupDelay : KaitaiStruct
        {
            public static MsgGroupDelay FromFile(string fileName)
            {
                return new MsgGroupDelay(new KaitaiStream(fileName));
            }

            public MsgGroupDelay(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tOp = new Gnss.GpsTimeSec(m_io, this, m_root);
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _valid = m_io.ReadU1();
                _tgd = m_io.ReadS2le();
                _iscL1ca = m_io.ReadS2le();
                _iscL2c = m_io.ReadS2le();
            }
            private Gnss.GpsTimeSec _tOp;
            private Gnss.GnssSignal _sid;
            private byte _valid;
            private short _tgd;
            private short _iscL1ca;
            private short _iscL2c;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Data Predict Time of Week
            /// </summary>
            public Gnss.GpsTimeSec TOp { get { return _tOp; } }

            /// <summary>
            /// GNSS signal identifier
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// bit-field indicating validity of the values, LSB indicating tgd
            /// validity etc. 1 = value is valid, 0 = value is not valid.
            /// </summary>
            public byte Valid { get { return _valid; } }
            public short Tgd { get { return _tgd; } }
            public short IscL1ca { get { return _iscL1ca; } }
            public short IscL2c { get { return _iscL2c; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The almanac message returns a set of satellite orbit parameters. Almanac
        /// data is not very precise and is considered valid for up to several
        /// months. Please see the GLO ICD 5.1 &quot;Chapter 4.5 Non-immediate
        /// information and almanac&quot; for details.
        /// </summary>
        public partial class MsgAlmanacGlo : KaitaiStruct
        {
            public static MsgAlmanacGlo FromFile(string fileName)
            {
                return new MsgAlmanacGlo(new KaitaiStream(fileName));
            }

            public MsgAlmanacGlo(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new AlmanacCommonContent(m_io, this, m_root);
                _lambdaNa = m_io.ReadF8le();
                _tLambdaNa = m_io.ReadF8le();
                _i = m_io.ReadF8le();
                _t = m_io.ReadF8le();
                _tDot = m_io.ReadF8le();
                _epsilon = m_io.ReadF8le();
                _omega = m_io.ReadF8le();
            }
            private AlmanacCommonContent _common;
            private double _lambdaNa;
            private double _tLambdaNa;
            private double _i;
            private double _t;
            private double _tDot;
            private double _epsilon;
            private double _omega;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all almanac types
            /// </summary>
            public AlmanacCommonContent Common { get { return _common; } }

            /// <summary>
            /// Longitude of the first ascending node of the orbit in PZ-90.02
            /// coordinate system
            /// </summary>
            public double LambdaNa { get { return _lambdaNa; } }

            /// <summary>
            /// Time of the first ascending node passage
            /// </summary>
            public double TLambdaNa { get { return _tLambdaNa; } }

            /// <summary>
            /// Value of inclination at instant of t_lambda
            /// </summary>
            public double I { get { return _i; } }

            /// <summary>
            /// Value of Draconian period at instant of t_lambda
            /// </summary>
            public double T { get { return _t; } }

            /// <summary>
            /// Rate of change of the Draconian period
            /// </summary>
            public double TDot { get { return _tDot; } }

            /// <summary>
            /// Eccentricity at instant of t_lambda
            /// </summary>
            public double Epsilon { get { return _epsilon; } }

            /// <summary>
            /// Argument of perigee at instant of t_lambda
            /// </summary>
            public double Omega { get { return _omega; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This observation message has been deprecated in favor of an ephemeris
        /// message with explicit source of NAV data.
        /// </summary>
        public partial class MsgEphemerisGalDepA : KaitaiStruct
        {
            public static MsgEphemerisGalDepA FromFile(string fileName)
            {
                return new MsgEphemerisGalDepA(new KaitaiStream(fileName));
            }

            public MsgEphemerisGalDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new EphemerisCommonContent(m_io, this, m_root);
                _bgdE1e5a = m_io.ReadF4le();
                _bgdE1e5b = m_io.ReadF4le();
                _cRs = m_io.ReadF4le();
                _cRc = m_io.ReadF4le();
                _cUc = m_io.ReadF4le();
                _cUs = m_io.ReadF4le();
                _cIc = m_io.ReadF4le();
                _cIs = m_io.ReadF4le();
                _dn = m_io.ReadF8le();
                _m0 = m_io.ReadF8le();
                _ecc = m_io.ReadF8le();
                _sqrta = m_io.ReadF8le();
                _omega0 = m_io.ReadF8le();
                _omegadot = m_io.ReadF8le();
                _w = m_io.ReadF8le();
                _inc = m_io.ReadF8le();
                _incDot = m_io.ReadF8le();
                _af0 = m_io.ReadF8le();
                _af1 = m_io.ReadF8le();
                _af2 = m_io.ReadF4le();
                _toc = new Gnss.GpsTimeSec(m_io, this, m_root);
                _iode = m_io.ReadU2le();
                _iodc = m_io.ReadU2le();
            }
            private EphemerisCommonContent _common;
            private float _bgdE1e5a;
            private float _bgdE1e5b;
            private float _cRs;
            private float _cRc;
            private float _cUc;
            private float _cUs;
            private float _cIc;
            private float _cIs;
            private double _dn;
            private double _m0;
            private double _ecc;
            private double _sqrta;
            private double _omega0;
            private double _omegadot;
            private double _w;
            private double _inc;
            private double _incDot;
            private double _af0;
            private double _af1;
            private float _af2;
            private Gnss.GpsTimeSec _toc;
            private ushort _iode;
            private ushort _iodc;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all ephemeris types
            /// </summary>
            public EphemerisCommonContent Common { get { return _common; } }

            /// <summary>
            /// E1-E5a Broadcast Group Delay
            /// </summary>
            public float BgdE1e5a { get { return _bgdE1e5a; } }

            /// <summary>
            /// E1-E5b Broadcast Group Delay
            /// </summary>
            public float BgdE1e5b { get { return _bgdE1e5b; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the orbit radius
            /// </summary>
            public float CRs { get { return _cRs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the orbit radius
            /// </summary>
            public float CRc { get { return _cRc; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public float CUc { get { return _cUc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public float CUs { get { return _cUs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public float CIc { get { return _cIc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public float CIs { get { return _cIs; } }

            /// <summary>
            /// Mean motion difference
            /// </summary>
            public double Dn { get { return _dn; } }

            /// <summary>
            /// Mean anomaly at reference time
            /// </summary>
            public double M0 { get { return _m0; } }

            /// <summary>
            /// Eccentricity of satellite orbit
            /// </summary>
            public double Ecc { get { return _ecc; } }

            /// <summary>
            /// Square root of the semi-major axis of orbit
            /// </summary>
            public double Sqrta { get { return _sqrta; } }

            /// <summary>
            /// Longitude of ascending node of orbit plane at weekly epoch
            /// </summary>
            public double Omega0 { get { return _omega0; } }

            /// <summary>
            /// Rate of right ascension
            /// </summary>
            public double Omegadot { get { return _omegadot; } }

            /// <summary>
            /// Argument of perigee
            /// </summary>
            public double W { get { return _w; } }

            /// <summary>
            /// Inclination
            /// </summary>
            public double Inc { get { return _inc; } }

            /// <summary>
            /// Inclination first derivative
            /// </summary>
            public double IncDot { get { return _incDot; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock bias)
            /// </summary>
            public double Af0 { get { return _af0; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock drift)
            /// </summary>
            public double Af1 { get { return _af1; } }

            /// <summary>
            /// Polynomial clock correction coefficient (rate of clock drift)
            /// </summary>
            public float Af2 { get { return _af2; } }

            /// <summary>
            /// Clock reference
            /// </summary>
            public Gnss.GpsTimeSec Toc { get { return _toc; } }

            /// <summary>
            /// Issue of data (IODnav)
            /// </summary>
            public ushort Iode { get { return _iode; } }

            /// <summary>
            /// Issue of data (IODnav). Always equal to iode
            /// </summary>
            public ushort Iodc { get { return _iodc; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This observation message has been deprecated in favor of observations
        /// that are more interoperable. This message should be used for
        /// observations referenced to a nominal pseudorange which are not
        /// interoperable with most 3rd party GNSS receivers or typical RTCMv3
        /// observations.
        /// </summary>
        public partial class MsgObsDepB : KaitaiStruct
        {
            public static MsgObsDepB FromFile(string fileName)
            {
                return new MsgObsDepB(new KaitaiStream(fileName));
            }

            public MsgObsDepB(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new ObservationHeaderDep(m_io, this, m_root);
                _obs = new List<PackedObsContentDepB>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _obs.Add(new PackedObsContentDepB(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private ObservationHeaderDep _header;
            private List<PackedObsContentDepB> _obs;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Header of a GPS observation message
            /// </summary>
            public ObservationHeaderDep Header { get { return _header; } }

            /// <summary>
            /// Pseudorange and carrier phase observation for a satellite being
            /// tracked.
            /// </summary>
            public List<PackedObsContentDepB> Obs { get { return _obs; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class PackedObsContentDepA : KaitaiStruct
        {
            public static PackedObsContentDepA FromFile(string fileName)
            {
                return new PackedObsContentDepA(new KaitaiStream(fileName));
            }

            public PackedObsContentDepA(KaitaiStream p__io, Observation.MsgObsDepA p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _p = m_io.ReadU4le();
                _l = new CarrierPhaseDepA(m_io, this, m_root);
                _cn0 = m_io.ReadU1();
                _lock = m_io.ReadU2le();
                _prn = m_io.ReadU1();
            }
            private uint _p;
            private CarrierPhaseDepA _l;
            private byte _cn0;
            private ushort _lock;
            private byte _prn;
            private Observation m_root;
            private Observation.MsgObsDepA m_parent;

            /// <summary>
            /// Pseudorange observation
            /// </summary>
            public uint P { get { return _p; } }

            /// <summary>
            /// Carrier phase observation with opposite sign from typical convention
            /// </summary>
            public CarrierPhaseDepA L { get { return _l; } }

            /// <summary>
            /// Carrier-to-Noise density
            /// </summary>
            public byte Cn0 { get { return _cn0; } }

            /// <summary>
            /// Lock indicator. This value changes whenever a satellite signal has
            /// lost and regained lock, indicating that the carrier phase ambiguity
            /// may have changed.
            /// </summary>
            public ushort Lock { get { return _lock; } }

            /// <summary>
            /// PRN-1 identifier of the satellite signal
            /// </summary>
            public byte Prn { get { return _prn; } }
            public Observation M_Root { get { return m_root; } }
            public Observation.MsgObsDepA M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The ephemeris message returns a set of satellite orbit parameters that
        /// is used to calculate GLO satellite position, velocity, and clock offset.
        /// Please see the GLO ICD 5.1 &quot;Table 4.5 Characteristics of words of
        /// immediate information (ephemeris parameters)&quot; for more details.
        /// </summary>
        public partial class MsgEphemerisGlo : KaitaiStruct
        {
            public static MsgEphemerisGlo FromFile(string fileName)
            {
                return new MsgEphemerisGlo(new KaitaiStream(fileName));
            }

            public MsgEphemerisGlo(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new EphemerisCommonContent(m_io, this, m_root);
                _gamma = m_io.ReadF4le();
                _tau = m_io.ReadF4le();
                _dTau = m_io.ReadF4le();
                _pos = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _pos.Add(m_io.ReadF8le());
                }
                _vel = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _vel.Add(m_io.ReadF8le());
                }
                _acc = new List<float>();
                for (var i = 0; i < 3; i++)
                {
                    _acc.Add(m_io.ReadF4le());
                }
                _fcn = m_io.ReadU1();
                _iod = m_io.ReadU1();
            }
            private EphemerisCommonContent _common;
            private float _gamma;
            private float _tau;
            private float _dTau;
            private List<double> _pos;
            private List<double> _vel;
            private List<float> _acc;
            private byte _fcn;
            private byte _iod;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all ephemeris types
            /// </summary>
            public EphemerisCommonContent Common { get { return _common; } }

            /// <summary>
            /// Relative deviation of predicted carrier frequency from nominal
            /// </summary>
            public float Gamma { get { return _gamma; } }

            /// <summary>
            /// Correction to the SV time
            /// </summary>
            public float Tau { get { return _tau; } }

            /// <summary>
            /// Equipment delay between L1 and L2
            /// </summary>
            public float DTau { get { return _dTau; } }

            /// <summary>
            /// Position of the SV at tb in PZ-90.02 coordinates system
            /// </summary>
            public List<double> Pos { get { return _pos; } }

            /// <summary>
            /// Velocity vector of the SV at tb in PZ-90.02 coordinates system
            /// </summary>
            public List<double> Vel { get { return _vel; } }

            /// <summary>
            /// Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
            /// </summary>
            public List<float> Acc { get { return _acc; } }

            /// <summary>
            /// Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
            /// </summary>
            public byte Fcn { get { return _fcn; } }

            /// <summary>
            /// Issue of data. Equal to the 7 bits of the immediate data word t_b
            /// </summary>
            public byte Iod { get { return _iod; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The ionospheric parameters which allow the &quot;L1 only&quot; or &quot;L2 only&quot; user
        /// to utilize the ionospheric model for computation of the ionospheric
        /// delay. Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
        /// </summary>
        public partial class MsgIono : KaitaiStruct
        {
            public static MsgIono FromFile(string fileName)
            {
                return new MsgIono(new KaitaiStream(fileName));
            }

            public MsgIono(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tNmct = new Gnss.GpsTimeSec(m_io, this, m_root);
                _a0 = m_io.ReadF8le();
                _a1 = m_io.ReadF8le();
                _a2 = m_io.ReadF8le();
                _a3 = m_io.ReadF8le();
                _b0 = m_io.ReadF8le();
                _b1 = m_io.ReadF8le();
                _b2 = m_io.ReadF8le();
                _b3 = m_io.ReadF8le();
            }
            private Gnss.GpsTimeSec _tNmct;
            private double _a0;
            private double _a1;
            private double _a2;
            private double _a3;
            private double _b0;
            private double _b1;
            private double _b2;
            private double _b3;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Navigation Message Correction Table Validity Time
            /// </summary>
            public Gnss.GpsTimeSec TNmct { get { return _tNmct; } }
            public double A0 { get { return _a0; } }
            public double A1 { get { return _a1; } }
            public double A2 { get { return _a2; } }
            public double A3 { get { return _a3; } }
            public double B0 { get { return _b0; } }
            public double B1 { get { return _b1; } }
            public double B2 { get { return _b2; } }
            public double B3 { get { return _b3; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The ephemeris message returns a set of satellite orbit parameters that
        /// is used to calculate GPS satellite position, velocity, and clock offset.
        /// Please see the Navstar GPS Space Segment/Navigation user interfaces
        /// (ICD-GPS-200, Table 20-III) for more details.
        /// </summary>
        public partial class MsgEphemerisDepD : KaitaiStruct
        {
            public static MsgEphemerisDepD FromFile(string fileName)
            {
                return new MsgEphemerisDepD(new KaitaiStream(fileName));
            }

            public MsgEphemerisDepD(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tgd = m_io.ReadF8le();
                _cRs = m_io.ReadF8le();
                _cRc = m_io.ReadF8le();
                _cUc = m_io.ReadF8le();
                _cUs = m_io.ReadF8le();
                _cIc = m_io.ReadF8le();
                _cIs = m_io.ReadF8le();
                _dn = m_io.ReadF8le();
                _m0 = m_io.ReadF8le();
                _ecc = m_io.ReadF8le();
                _sqrta = m_io.ReadF8le();
                _omega0 = m_io.ReadF8le();
                _omegadot = m_io.ReadF8le();
                _w = m_io.ReadF8le();
                _inc = m_io.ReadF8le();
                _incDot = m_io.ReadF8le();
                _af0 = m_io.ReadF8le();
                _af1 = m_io.ReadF8le();
                _af2 = m_io.ReadF8le();
                _toeTow = m_io.ReadF8le();
                _toeWn = m_io.ReadU2le();
                _tocTow = m_io.ReadF8le();
                _tocWn = m_io.ReadU2le();
                _valid = m_io.ReadU1();
                _healthy = m_io.ReadU1();
                _sid = new Gnss.GnssSignalDep(m_io, this, m_root);
                _iode = m_io.ReadU1();
                _iodc = m_io.ReadU2le();
                _reserved = m_io.ReadU4le();
            }
            private double _tgd;
            private double _cRs;
            private double _cRc;
            private double _cUc;
            private double _cUs;
            private double _cIc;
            private double _cIs;
            private double _dn;
            private double _m0;
            private double _ecc;
            private double _sqrta;
            private double _omega0;
            private double _omegadot;
            private double _w;
            private double _inc;
            private double _incDot;
            private double _af0;
            private double _af1;
            private double _af2;
            private double _toeTow;
            private ushort _toeWn;
            private double _tocTow;
            private ushort _tocWn;
            private byte _valid;
            private byte _healthy;
            private Gnss.GnssSignalDep _sid;
            private byte _iode;
            private ushort _iodc;
            private uint _reserved;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Group delay differential between L1 and L2
            /// </summary>
            public double Tgd { get { return _tgd; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the orbit radius
            /// </summary>
            public double CRs { get { return _cRs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the orbit radius
            /// </summary>
            public double CRc { get { return _cRc; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public double CUc { get { return _cUc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public double CUs { get { return _cUs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public double CIc { get { return _cIc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public double CIs { get { return _cIs; } }

            /// <summary>
            /// Mean motion difference
            /// </summary>
            public double Dn { get { return _dn; } }

            /// <summary>
            /// Mean anomaly at reference time
            /// </summary>
            public double M0 { get { return _m0; } }

            /// <summary>
            /// Eccentricity of satellite orbit
            /// </summary>
            public double Ecc { get { return _ecc; } }

            /// <summary>
            /// Square root of the semi-major axis of orbit
            /// </summary>
            public double Sqrta { get { return _sqrta; } }

            /// <summary>
            /// Longitude of ascending node of orbit plane at weekly epoch
            /// </summary>
            public double Omega0 { get { return _omega0; } }

            /// <summary>
            /// Rate of right ascension
            /// </summary>
            public double Omegadot { get { return _omegadot; } }

            /// <summary>
            /// Argument of perigee
            /// </summary>
            public double W { get { return _w; } }

            /// <summary>
            /// Inclination
            /// </summary>
            public double Inc { get { return _inc; } }

            /// <summary>
            /// Inclination first derivative
            /// </summary>
            public double IncDot { get { return _incDot; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock bias)
            /// </summary>
            public double Af0 { get { return _af0; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock drift)
            /// </summary>
            public double Af1 { get { return _af1; } }

            /// <summary>
            /// Polynomial clock correction coefficient (rate of clock drift)
            /// </summary>
            public double Af2 { get { return _af2; } }

            /// <summary>
            /// Time of week
            /// </summary>
            public double ToeTow { get { return _toeTow; } }

            /// <summary>
            /// Week number
            /// </summary>
            public ushort ToeWn { get { return _toeWn; } }

            /// <summary>
            /// Clock reference time of week
            /// </summary>
            public double TocTow { get { return _tocTow; } }

            /// <summary>
            /// Clock reference week number
            /// </summary>
            public ushort TocWn { get { return _tocWn; } }

            /// <summary>
            /// Is valid?
            /// </summary>
            public byte Valid { get { return _valid; } }

            /// <summary>
            /// Satellite is healthy?
            /// </summary>
            public byte Healthy { get { return _healthy; } }

            /// <summary>
            /// GNSS signal identifier
            /// </summary>
            public Gnss.GnssSignalDep Sid { get { return _sid; } }

            /// <summary>
            /// Issue of ephemeris data
            /// </summary>
            public byte Iode { get { return _iode; } }

            /// <summary>
            /// Issue of clock data
            /// </summary>
            public ushort Iodc { get { return _iodc; } }

            /// <summary>
            /// Reserved field
            /// </summary>
            public uint Reserved { get { return _reserved; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The ephemeris message returns a set of satellite orbit parameters that
        /// is used to calculate GPS satellite position, velocity, and clock offset.
        /// Please see the Navstar GPS Space Segment/Navigation user interfaces
        /// (ICD-GPS-200, Table 20-III) for more details.
        /// </summary>
        public partial class MsgEphemerisGps : KaitaiStruct
        {
            public static MsgEphemerisGps FromFile(string fileName)
            {
                return new MsgEphemerisGps(new KaitaiStream(fileName));
            }

            public MsgEphemerisGps(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new EphemerisCommonContent(m_io, this, m_root);
                _tgd = m_io.ReadF4le();
                _cRs = m_io.ReadF4le();
                _cRc = m_io.ReadF4le();
                _cUc = m_io.ReadF4le();
                _cUs = m_io.ReadF4le();
                _cIc = m_io.ReadF4le();
                _cIs = m_io.ReadF4le();
                _dn = m_io.ReadF8le();
                _m0 = m_io.ReadF8le();
                _ecc = m_io.ReadF8le();
                _sqrta = m_io.ReadF8le();
                _omega0 = m_io.ReadF8le();
                _omegadot = m_io.ReadF8le();
                _w = m_io.ReadF8le();
                _inc = m_io.ReadF8le();
                _incDot = m_io.ReadF8le();
                _af0 = m_io.ReadF4le();
                _af1 = m_io.ReadF4le();
                _af2 = m_io.ReadF4le();
                _toc = new Gnss.GpsTimeSec(m_io, this, m_root);
                _iode = m_io.ReadU1();
                _iodc = m_io.ReadU2le();
            }
            private EphemerisCommonContent _common;
            private float _tgd;
            private float _cRs;
            private float _cRc;
            private float _cUc;
            private float _cUs;
            private float _cIc;
            private float _cIs;
            private double _dn;
            private double _m0;
            private double _ecc;
            private double _sqrta;
            private double _omega0;
            private double _omegadot;
            private double _w;
            private double _inc;
            private double _incDot;
            private float _af0;
            private float _af1;
            private float _af2;
            private Gnss.GpsTimeSec _toc;
            private byte _iode;
            private ushort _iodc;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all ephemeris types
            /// </summary>
            public EphemerisCommonContent Common { get { return _common; } }

            /// <summary>
            /// Group delay differential between L1 and L2
            /// </summary>
            public float Tgd { get { return _tgd; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the orbit radius
            /// </summary>
            public float CRs { get { return _cRs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the orbit radius
            /// </summary>
            public float CRc { get { return _cRc; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public float CUc { get { return _cUc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public float CUs { get { return _cUs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public float CIc { get { return _cIc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public float CIs { get { return _cIs; } }

            /// <summary>
            /// Mean motion difference
            /// </summary>
            public double Dn { get { return _dn; } }

            /// <summary>
            /// Mean anomaly at reference time
            /// </summary>
            public double M0 { get { return _m0; } }

            /// <summary>
            /// Eccentricity of satellite orbit
            /// </summary>
            public double Ecc { get { return _ecc; } }

            /// <summary>
            /// Square root of the semi-major axis of orbit
            /// </summary>
            public double Sqrta { get { return _sqrta; } }

            /// <summary>
            /// Longitude of ascending node of orbit plane at weekly epoch
            /// </summary>
            public double Omega0 { get { return _omega0; } }

            /// <summary>
            /// Rate of right ascension
            /// </summary>
            public double Omegadot { get { return _omegadot; } }

            /// <summary>
            /// Argument of perigee
            /// </summary>
            public double W { get { return _w; } }

            /// <summary>
            /// Inclination
            /// </summary>
            public double Inc { get { return _inc; } }

            /// <summary>
            /// Inclination first derivative
            /// </summary>
            public double IncDot { get { return _incDot; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock bias)
            /// </summary>
            public float Af0 { get { return _af0; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock drift)
            /// </summary>
            public float Af1 { get { return _af1; } }

            /// <summary>
            /// Polynomial clock correction coefficient (rate of clock drift)
            /// </summary>
            public float Af2 { get { return _af2; } }

            /// <summary>
            /// Clock reference
            /// </summary>
            public Gnss.GpsTimeSec Toc { get { return _toc; } }

            /// <summary>
            /// Issue of ephemeris data
            /// </summary>
            public byte Iode { get { return _iode; } }

            /// <summary>
            /// Issue of clock data
            /// </summary>
            public ushort Iodc { get { return _iodc; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The base station position message is the position reported by the base
        /// station itself. It is used for pseudo-absolute RTK positioning, and is
        /// required to be a high-accuracy surveyed location of the base station.
        /// Any error here will result in an error in the pseudo-absolute position
        /// output.
        /// </summary>
        public partial class MsgBasePosLlh : KaitaiStruct
        {
            public static MsgBasePosLlh FromFile(string fileName)
            {
                return new MsgBasePosLlh(new KaitaiStream(fileName));
            }

            public MsgBasePosLlh(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _lat = m_io.ReadF8le();
                _lon = m_io.ReadF8le();
                _height = m_io.ReadF8le();
            }
            private double _lat;
            private double _lon;
            private double _height;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Latitude
            /// </summary>
            public double Lat { get { return _lat; } }

            /// <summary>
            /// Longitude
            /// </summary>
            public double Lon { get { return _lon; } }

            /// <summary>
            /// Height
            /// </summary>
            public double Height { get { return _height; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        public partial class AlmanacCommonContent : KaitaiStruct
        {
            public static AlmanacCommonContent FromFile(string fileName)
            {
                return new AlmanacCommonContent(new KaitaiStream(fileName));
            }

            public AlmanacCommonContent(KaitaiStream p__io, KaitaiStruct p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _toa = new Gnss.GpsTimeSec(m_io, this, m_root);
                _ura = m_io.ReadF8le();
                _fitInterval = m_io.ReadU4le();
                _valid = m_io.ReadU1();
                _healthBits = m_io.ReadU1();
            }
            private Gnss.GnssSignal _sid;
            private Gnss.GpsTimeSec _toa;
            private double _ura;
            private uint _fitInterval;
            private byte _valid;
            private byte _healthBits;
            private Observation m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// GNSS signal identifier
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// Reference time of almanac
            /// </summary>
            public Gnss.GpsTimeSec Toa { get { return _toa; } }

            /// <summary>
            /// User Range Accuracy
            /// </summary>
            public double Ura { get { return _ura; } }

            /// <summary>
            /// Curve fit interval
            /// </summary>
            public uint FitInterval { get { return _fitInterval; } }

            /// <summary>
            /// Status of almanac, 1 = valid, 0 = invalid
            /// </summary>
            public byte Valid { get { return _valid; } }

            /// <summary>
            /// Satellite health status for GPS:
            ///   - bits 5-7: NAV data health status. See IS-GPS-200H
            ///     Table 20-VII: NAV Data Health Indications.
            ///   - bits 0-4: Signal health status. See IS-GPS-200H
            ///     Table 20-VIII. Codes for Health of SV Signal
            ///     Components.
            /// Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for
            /// details):
            ///   - bit 0: C(n), &quot;unhealthy&quot; flag that is transmitted within
            ///     non-immediate data and indicates overall constellation status
            ///     at the moment of almanac uploading.
            ///     '0' indicates malfunction of n-satellite.
            ///     '1' indicates that n-satellite is operational.
            ///   - bit 1: Bn(ln), '0' indicates the satellite is operational
            ///     and suitable for navigation.
            /// </summary>
            public byte HealthBits { get { return _healthBits; } }
            public Observation M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The OSR message contains network corrections in an observation-like
        /// format.
        /// </summary>
        public partial class MsgOsr : KaitaiStruct
        {
            public static MsgOsr FromFile(string fileName)
            {
                return new MsgOsr(new KaitaiStream(fileName));
            }

            public MsgOsr(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new ObservationHeader(m_io, this, m_root);
                _obs = new List<PackedOsrContent>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _obs.Add(new PackedOsrContent(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private ObservationHeader _header;
            private List<PackedOsrContent> _obs;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Header of a GPS observation message
            /// </summary>
            public ObservationHeader Header { get { return _header; } }

            /// <summary>
            /// Network correction for a satellite signal.
            /// </summary>
            public List<PackedOsrContent> Obs { get { return _obs; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The ephemeris message returns a set of satellite orbit parameters that
        /// is used to calculate GLO satellite position, velocity, and clock offset.
        /// Please see the GLO ICD 5.1 &quot;Table 4.5 Characteristics of words of
        /// immediate information (ephemeris parameters)&quot; for more details.
        /// </summary>
        public partial class MsgEphemerisGloDepC : KaitaiStruct
        {
            public static MsgEphemerisGloDepC FromFile(string fileName)
            {
                return new MsgEphemerisGloDepC(new KaitaiStream(fileName));
            }

            public MsgEphemerisGloDepC(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new EphemerisCommonContentDepB(m_io, this, m_root);
                _gamma = m_io.ReadF8le();
                _tau = m_io.ReadF8le();
                _dTau = m_io.ReadF8le();
                _pos = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _pos.Add(m_io.ReadF8le());
                }
                _vel = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _vel.Add(m_io.ReadF8le());
                }
                _acc = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _acc.Add(m_io.ReadF8le());
                }
                _fcn = m_io.ReadU1();
            }
            private EphemerisCommonContentDepB _common;
            private double _gamma;
            private double _tau;
            private double _dTau;
            private List<double> _pos;
            private List<double> _vel;
            private List<double> _acc;
            private byte _fcn;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all ephemeris types
            /// </summary>
            public EphemerisCommonContentDepB Common { get { return _common; } }

            /// <summary>
            /// Relative deviation of predicted carrier frequency from nominal
            /// </summary>
            public double Gamma { get { return _gamma; } }

            /// <summary>
            /// Correction to the SV time
            /// </summary>
            public double Tau { get { return _tau; } }

            /// <summary>
            /// Equipment delay between L1 and L2
            /// </summary>
            public double DTau { get { return _dTau; } }

            /// <summary>
            /// Position of the SV at tb in PZ-90.02 coordinates system
            /// </summary>
            public List<double> Pos { get { return _pos; } }

            /// <summary>
            /// Velocity vector of the SV at tb in PZ-90.02 coordinates system
            /// </summary>
            public List<double> Vel { get { return _vel; } }

            /// <summary>
            /// Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
            /// </summary>
            public List<double> Acc { get { return _acc; } }

            /// <summary>
            /// Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
            /// </summary>
            public byte Fcn { get { return _fcn; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The ephemeris message returns a set of satellite orbit parameters that
        /// is used to calculate GLO satellite position, velocity, and clock offset.
        /// Please see the GLO ICD 5.1 &quot;Table 4.5 Characteristics of words of
        /// immediate information (ephemeris parameters)&quot; for more details.
        /// </summary>
        public partial class MsgEphemerisGloDepB : KaitaiStruct
        {
            public static MsgEphemerisGloDepB FromFile(string fileName)
            {
                return new MsgEphemerisGloDepB(new KaitaiStream(fileName));
            }

            public MsgEphemerisGloDepB(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new EphemerisCommonContentDepB(m_io, this, m_root);
                _gamma = m_io.ReadF8le();
                _tau = m_io.ReadF8le();
                _pos = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _pos.Add(m_io.ReadF8le());
                }
                _vel = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _vel.Add(m_io.ReadF8le());
                }
                _acc = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _acc.Add(m_io.ReadF8le());
                }
            }
            private EphemerisCommonContentDepB _common;
            private double _gamma;
            private double _tau;
            private List<double> _pos;
            private List<double> _vel;
            private List<double> _acc;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all ephemeris types
            /// </summary>
            public EphemerisCommonContentDepB Common { get { return _common; } }

            /// <summary>
            /// Relative deviation of predicted carrier frequency from nominal
            /// </summary>
            public double Gamma { get { return _gamma; } }

            /// <summary>
            /// Correction to the SV time
            /// </summary>
            public double Tau { get { return _tau; } }

            /// <summary>
            /// Position of the SV at tb in PZ-90.02 coordinates system
            /// </summary>
            public List<double> Pos { get { return _pos; } }

            /// <summary>
            /// Velocity vector of the SV at tb in PZ-90.02 coordinates system
            /// </summary>
            public List<double> Vel { get { return _vel; } }

            /// <summary>
            /// Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
            /// </summary>
            public List<double> Acc { get { return _acc; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
        /// </summary>
        public partial class MsgSvConfigurationGpsDep : KaitaiStruct
        {
            public static MsgSvConfigurationGpsDep FromFile(string fileName)
            {
                return new MsgSvConfigurationGpsDep(new KaitaiStream(fileName));
            }

            public MsgSvConfigurationGpsDep(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tNmct = new Gnss.GpsTimeSec(m_io, this, m_root);
                _l2cMask = m_io.ReadU4le();
            }
            private Gnss.GpsTimeSec _tNmct;
            private uint _l2cMask;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Navigation Message Correction Table Validity Time
            /// </summary>
            public Gnss.GpsTimeSec TNmct { get { return _tNmct; } }

            /// <summary>
            /// L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
            /// </summary>
            public uint L2cMask { get { return _l2cMask; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        public partial class MsgEphemerisSbas : KaitaiStruct
        {
            public static MsgEphemerisSbas FromFile(string fileName)
            {
                return new MsgEphemerisSbas(new KaitaiStream(fileName));
            }

            public MsgEphemerisSbas(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _common = new EphemerisCommonContent(m_io, this, m_root);
                _pos = new List<double>();
                for (var i = 0; i < 3; i++)
                {
                    _pos.Add(m_io.ReadF8le());
                }
                _vel = new List<float>();
                for (var i = 0; i < 3; i++)
                {
                    _vel.Add(m_io.ReadF4le());
                }
                _acc = new List<float>();
                for (var i = 0; i < 3; i++)
                {
                    _acc.Add(m_io.ReadF4le());
                }
                _aGf0 = m_io.ReadF4le();
                _aGf1 = m_io.ReadF4le();
            }
            private EphemerisCommonContent _common;
            private List<double> _pos;
            private List<float> _vel;
            private List<float> _acc;
            private float _aGf0;
            private float _aGf1;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Values common for all ephemeris types
            /// </summary>
            public EphemerisCommonContent Common { get { return _common; } }

            /// <summary>
            /// Position of the GEO at time toe
            /// </summary>
            public List<double> Pos { get { return _pos; } }

            /// <summary>
            /// Velocity of the GEO at time toe
            /// </summary>
            public List<float> Vel { get { return _vel; } }

            /// <summary>
            /// Acceleration of the GEO at time toe
            /// </summary>
            public List<float> Acc { get { return _acc; } }

            /// <summary>
            /// Time offset of the GEO clock w.r.t. SBAS Network Time
            /// </summary>
            public float AGf0 { get { return _aGf0; } }

            /// <summary>
            /// Drift of the GEO clock w.r.t. SBAS Network Time
            /// </summary>
            public float AGf1 { get { return _aGf1; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Pseudorange and carrier phase observation for a satellite being tracked.
        /// Pseudoranges are referenced to a nominal pseudorange.
        /// </summary>
        public partial class PackedObsContentDepB : KaitaiStruct
        {
            public static PackedObsContentDepB FromFile(string fileName)
            {
                return new PackedObsContentDepB(new KaitaiStream(fileName));
            }

            public PackedObsContentDepB(KaitaiStream p__io, Observation.MsgObsDepB p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _p = m_io.ReadU4le();
                _l = new CarrierPhaseDepA(m_io, this, m_root);
                _cn0 = m_io.ReadU1();
                _lock = m_io.ReadU2le();
                _sid = new Gnss.GnssSignalDep(m_io, this, m_root);
            }
            private uint _p;
            private CarrierPhaseDepA _l;
            private byte _cn0;
            private ushort _lock;
            private Gnss.GnssSignalDep _sid;
            private Observation m_root;
            private Observation.MsgObsDepB m_parent;

            /// <summary>
            /// Pseudorange observation
            /// </summary>
            public uint P { get { return _p; } }

            /// <summary>
            /// Carrier phase observation with opposite sign from typical
            /// convention.
            /// </summary>
            public CarrierPhaseDepA L { get { return _l; } }

            /// <summary>
            /// Carrier-to-Noise density
            /// </summary>
            public byte Cn0 { get { return _cn0; } }

            /// <summary>
            /// Lock indicator. This value changes whenever a satellite signal has
            /// lost and regained lock, indicating that the carrier phase ambiguity
            /// may have changed.
            /// </summary>
            public ushort Lock { get { return _lock; } }

            /// <summary>
            /// GNSS signal identifier
            /// </summary>
            public Gnss.GnssSignalDep Sid { get { return _sid; } }
            public Observation M_Root { get { return m_root; } }
            public Observation.MsgObsDepB M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The GPS observations message reports all the raw pseudorange and carrier
        /// phase observations for the satellites being tracked by the device.
        /// Carrier phase observation here is represented as a 40-bit fixed point
        /// number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
        /// fractional cycles). The observations are interoperable with 3rd party
        /// receivers and conform with typical RTCMv3 GNSS observations.
        /// </summary>
        public partial class MsgObsDepC : KaitaiStruct
        {
            public static MsgObsDepC FromFile(string fileName)
            {
                return new MsgObsDepC(new KaitaiStream(fileName));
            }

            public MsgObsDepC(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new ObservationHeaderDep(m_io, this, m_root);
                _obs = new List<PackedObsContentDepC>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _obs.Add(new PackedObsContentDepC(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private ObservationHeaderDep _header;
            private List<PackedObsContentDepC> _obs;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Header of a GPS observation message
            /// </summary>
            public ObservationHeaderDep Header { get { return _header; } }

            /// <summary>
            /// Pseudorange and carrier phase observation for a satellite being
            /// tracked.
            /// </summary>
            public List<PackedObsContentDepC> Obs { get { return _obs; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgEphemerisDepA : KaitaiStruct
        {
            public static MsgEphemerisDepA FromFile(string fileName)
            {
                return new MsgEphemerisDepA(new KaitaiStream(fileName));
            }

            public MsgEphemerisDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tgd = m_io.ReadF8le();
                _cRs = m_io.ReadF8le();
                _cRc = m_io.ReadF8le();
                _cUc = m_io.ReadF8le();
                _cUs = m_io.ReadF8le();
                _cIc = m_io.ReadF8le();
                _cIs = m_io.ReadF8le();
                _dn = m_io.ReadF8le();
                _m0 = m_io.ReadF8le();
                _ecc = m_io.ReadF8le();
                _sqrta = m_io.ReadF8le();
                _omega0 = m_io.ReadF8le();
                _omegadot = m_io.ReadF8le();
                _w = m_io.ReadF8le();
                _inc = m_io.ReadF8le();
                _incDot = m_io.ReadF8le();
                _af0 = m_io.ReadF8le();
                _af1 = m_io.ReadF8le();
                _af2 = m_io.ReadF8le();
                _toeTow = m_io.ReadF8le();
                _toeWn = m_io.ReadU2le();
                _tocTow = m_io.ReadF8le();
                _tocWn = m_io.ReadU2le();
                _valid = m_io.ReadU1();
                _healthy = m_io.ReadU1();
                _prn = m_io.ReadU1();
            }
            private double _tgd;
            private double _cRs;
            private double _cRc;
            private double _cUc;
            private double _cUs;
            private double _cIc;
            private double _cIs;
            private double _dn;
            private double _m0;
            private double _ecc;
            private double _sqrta;
            private double _omega0;
            private double _omegadot;
            private double _w;
            private double _inc;
            private double _incDot;
            private double _af0;
            private double _af1;
            private double _af2;
            private double _toeTow;
            private ushort _toeWn;
            private double _tocTow;
            private ushort _tocWn;
            private byte _valid;
            private byte _healthy;
            private byte _prn;
            private Observation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Group delay differential between L1 and L2
            /// </summary>
            public double Tgd { get { return _tgd; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the orbit radius
            /// </summary>
            public double CRs { get { return _cRs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the orbit radius
            /// </summary>
            public double CRc { get { return _cRc; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public double CUc { get { return _cUc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the argument of
            /// latitude
            /// </summary>
            public double CUs { get { return _cUs; } }

            /// <summary>
            /// Amplitude of the cosine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public double CIc { get { return _cIc; } }

            /// <summary>
            /// Amplitude of the sine harmonic correction term to the angle of
            /// inclination
            /// </summary>
            public double CIs { get { return _cIs; } }

            /// <summary>
            /// Mean motion difference
            /// </summary>
            public double Dn { get { return _dn; } }

            /// <summary>
            /// Mean anomaly at reference time
            /// </summary>
            public double M0 { get { return _m0; } }

            /// <summary>
            /// Eccentricity of satellite orbit
            /// </summary>
            public double Ecc { get { return _ecc; } }

            /// <summary>
            /// Square root of the semi-major axis of orbit
            /// </summary>
            public double Sqrta { get { return _sqrta; } }

            /// <summary>
            /// Longitude of ascending node of orbit plane at weekly epoch
            /// </summary>
            public double Omega0 { get { return _omega0; } }

            /// <summary>
            /// Rate of right ascension
            /// </summary>
            public double Omegadot { get { return _omegadot; } }

            /// <summary>
            /// Argument of perigee
            /// </summary>
            public double W { get { return _w; } }

            /// <summary>
            /// Inclination
            /// </summary>
            public double Inc { get { return _inc; } }

            /// <summary>
            /// Inclination first derivative
            /// </summary>
            public double IncDot { get { return _incDot; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock bias)
            /// </summary>
            public double Af0 { get { return _af0; } }

            /// <summary>
            /// Polynomial clock correction coefficient (clock drift)
            /// </summary>
            public double Af1 { get { return _af1; } }

            /// <summary>
            /// Polynomial clock correction coefficient (rate of clock drift)
            /// </summary>
            public double Af2 { get { return _af2; } }

            /// <summary>
            /// Time of week
            /// </summary>
            public double ToeTow { get { return _toeTow; } }

            /// <summary>
            /// Week number
            /// </summary>
            public ushort ToeWn { get { return _toeWn; } }

            /// <summary>
            /// Clock reference time of week
            /// </summary>
            public double TocTow { get { return _tocTow; } }

            /// <summary>
            /// Clock reference week number
            /// </summary>
            public ushort TocWn { get { return _tocWn; } }

            /// <summary>
            /// Is valid?
            /// </summary>
            public byte Valid { get { return _valid; } }

            /// <summary>
            /// Satellite is healthy?
            /// </summary>
            public byte Healthy { get { return _healthy; } }

            /// <summary>
            /// PRN being tracked
            /// </summary>
            public byte Prn { get { return _prn; } }
            public Observation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        public partial class EphemerisCommonContentDepB : KaitaiStruct
        {
            public static EphemerisCommonContentDepB FromFile(string fileName)
            {
                return new EphemerisCommonContentDepB(new KaitaiStream(fileName));
            }

            public EphemerisCommonContentDepB(KaitaiStream p__io, KaitaiStruct p__parent = null, Observation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _toe = new Gnss.GpsTimeSec(m_io, this, m_root);
                _ura = m_io.ReadF8le();
                _fitInterval = m_io.ReadU4le();
                _valid = m_io.ReadU1();
                _healthBits = m_io.ReadU1();
            }
            private Gnss.GnssSignal _sid;
            private Gnss.GpsTimeSec _toe;
            private double _ura;
            private uint _fitInterval;
            private byte _valid;
            private byte _healthBits;
            private Observation m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// GNSS signal identifier (16 bit)
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// Time of Ephemerides
            /// </summary>
            public Gnss.GpsTimeSec Toe { get { return _toe; } }

            /// <summary>
            /// User Range Accuracy
            /// </summary>
            public double Ura { get { return _ura; } }

            /// <summary>
            /// Curve fit interval
            /// </summary>
            public uint FitInterval { get { return _fitInterval; } }

            /// <summary>
            /// Status of ephemeris, 1 = valid, 0 = invalid
            /// </summary>
            public byte Valid { get { return _valid; } }

            /// <summary>
            /// Satellite health status.
            /// GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
            /// Others: 0 = valid, non-zero = invalid
            /// </summary>
            public byte HealthBits { get { return _healthBits; } }
            public Observation M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }
        private Observation m_root;
        private KaitaiStruct m_parent;
        public Observation M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
