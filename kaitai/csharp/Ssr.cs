// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class Ssr : KaitaiStruct
    {
        public static Ssr FromFile(string fileName)
        {
            return new Ssr(new KaitaiStream(fileName));
        }

        public Ssr(KaitaiStream p__io, KaitaiStruct p__parent = null, Ssr p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes
        /// an RLE encoded validity list.
        /// </summary>
        public partial class GridDefinitionHeaderDepA : KaitaiStruct
        {
            public static GridDefinitionHeaderDepA FromFile(string fileName)
            {
                return new GridDefinitionHeaderDepA(new KaitaiStream(fileName));
            }

            public GridDefinitionHeaderDepA(KaitaiStream p__io, Ssr.MsgSsrGridDefinitionDepA p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _regionSizeInverse = m_io.ReadU1();
                _areaWidth = m_io.ReadU2le();
                _latNwCornerEnc = m_io.ReadU2le();
                _lonNwCornerEnc = m_io.ReadU2le();
                _numMsgs = m_io.ReadU1();
                _seqNum = m_io.ReadU1();
            }
            private byte _regionSizeInverse;
            private ushort _areaWidth;
            private ushort _latNwCornerEnc;
            private ushort _lonNwCornerEnc;
            private byte _numMsgs;
            private byte _seqNum;
            private Ssr m_root;
            private Ssr.MsgSsrGridDefinitionDepA m_parent;

            /// <summary>
            /// region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
            /// </summary>
            public byte RegionSizeInverse { get { return _regionSizeInverse; } }

            /// <summary>
            /// grid height (deg) = grid width (deg) = area_width / region_size 0 is
            /// an invalid value.
            /// </summary>
            public ushort AreaWidth { get { return _areaWidth; } }

            /// <summary>
            /// North-West corner latitude (deg) = region_size * lat_nw_corner_enc -
            /// 90
            /// </summary>
            public ushort LatNwCornerEnc { get { return _latNwCornerEnc; } }

            /// <summary>
            /// North-West corner longitude (deg) = region_size * lon_nw_corner_enc
            /// - 180
            /// </summary>
            public ushort LonNwCornerEnc { get { return _lonNwCornerEnc; } }

            /// <summary>
            /// Number of messages in the dataset
            /// </summary>
            public byte NumMsgs { get { return _numMsgs; } }

            /// <summary>
            /// Position of this message in the dataset
            /// </summary>
            public byte SeqNum { get { return _seqNum; } }
            public Ssr M_Root { get { return m_root; } }
            public Ssr.MsgSsrGridDefinitionDepA M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// STEC residual for the given satellite at the grid point.
        /// </summary>
        public partial class StecResidualNoStd : KaitaiStruct
        {
            public static StecResidualNoStd FromFile(string fileName)
            {
                return new StecResidualNoStd(new KaitaiStream(fileName));
            }

            public StecResidualNoStd(KaitaiStream p__io, Ssr.MsgSsrGriddedCorrectionNoStdDepA p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _svId = new Gnss.SvId(m_io, this, m_root);
                _residual = m_io.ReadS2le();
            }
            private Gnss.SvId _svId;
            private short _residual;
            private Ssr m_root;
            private Ssr.MsgSsrGriddedCorrectionNoStdDepA m_parent;

            /// <summary>
            /// space vehicle identifier
            /// </summary>
            public Gnss.SvId SvId { get { return _svId; } }

            /// <summary>
            /// STEC residual
            /// </summary>
            public short Residual { get { return _residual; } }
            public Ssr M_Root { get { return m_root; } }
            public Ssr.MsgSsrGriddedCorrectionNoStdDepA M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Troposphere vertical delays at the grid point.
        /// </summary>
        public partial class TroposphericDelayCorrectionNoStd : KaitaiStruct
        {
            public static TroposphericDelayCorrectionNoStd FromFile(string fileName)
            {
                return new TroposphericDelayCorrectionNoStd(new KaitaiStream(fileName));
            }

            public TroposphericDelayCorrectionNoStd(KaitaiStream p__io, Ssr.MsgSsrGriddedCorrectionNoStdDepA p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _hydro = m_io.ReadS2le();
                _wet = m_io.ReadS1();
            }
            private short _hydro;
            private sbyte _wet;
            private Ssr m_root;
            private Ssr.MsgSsrGriddedCorrectionNoStdDepA m_parent;

            /// <summary>
            /// Hydrostatic vertical delay
            /// </summary>
            public short Hydro { get { return _hydro; } }

            /// <summary>
            /// Wet vertical delay
            /// </summary>
            public sbyte Wet { get { return _wet; } }
            public Ssr M_Root { get { return m_root; } }
            public Ssr.MsgSsrGriddedCorrectionNoStdDepA M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgSsrStecCorrectionDep : KaitaiStruct
        {
            public static MsgSsrStecCorrectionDep FromFile(string fileName)
            {
                return new MsgSsrStecCorrectionDep(new KaitaiStream(fileName));
            }

            public MsgSsrStecCorrectionDep(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new StecHeader(m_io, this, m_root);
                _stecSatList = new List<StecSatElement>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _stecSatList.Add(new StecSatElement(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private StecHeader _header;
            private List<StecSatElement> _stecSatList;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Header of a STEC polynomial coefficient message.
            /// </summary>
            public StecHeader Header { get { return _header; } }

            /// <summary>
            /// Array of STEC polynomial coefficients for each space vehicle.
            /// </summary>
            public List<StecSatElement> StecSatList { get { return _stecSatList; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// STEC polynomial and bounds for the given satellite.
        /// </summary>
        public partial class StecSatElementIntegrity : KaitaiStruct
        {
            public static StecSatElementIntegrity FromFile(string fileName)
            {
                return new StecSatElementIntegrity(new KaitaiStream(fileName));
            }

            public StecSatElementIntegrity(KaitaiStream p__io, Ssr.MsgSsrGriddedCorrectionBounds p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _stecResidual = new StecResidual(m_io, this, m_root);
                _stecBoundMu = m_io.ReadU1();
                _stecBoundSig = m_io.ReadU1();
                _stecBoundMuDot = m_io.ReadU1();
                _stecBoundSigDot = m_io.ReadU1();
            }
            private StecResidual _stecResidual;
            private byte _stecBoundMu;
            private byte _stecBoundSig;
            private byte _stecBoundMuDot;
            private byte _stecBoundSigDot;
            private Ssr m_root;
            private Ssr.MsgSsrGriddedCorrectionBounds m_parent;

            /// <summary>
            /// STEC residuals (mean, stddev)
            /// </summary>
            public StecResidual StecResidual { get { return _stecResidual; } }

            /// <summary>
            /// Error Bound Mean. See Note 1.
            /// </summary>
            public byte StecBoundMu { get { return _stecBoundMu; } }

            /// <summary>
            /// Error Bound StDev. See Note 1.
            /// </summary>
            public byte StecBoundSig { get { return _stecBoundSig; } }

            /// <summary>
            /// Error Bound Mean First derivative.
            /// </summary>
            public byte StecBoundMuDot { get { return _stecBoundMuDot; } }

            /// <summary>
            /// Error Bound StDev First derivative.
            /// </summary>
            public byte StecBoundSigDot { get { return _stecBoundSigDot; } }
            public Ssr M_Root { get { return m_root; } }
            public Ssr.MsgSsrGriddedCorrectionBounds M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgSsrOrbitClockDepA : KaitaiStruct
        {
            public static MsgSsrOrbitClockDepA FromFile(string fileName)
            {
                return new MsgSsrOrbitClockDepA(new KaitaiStream(fileName));
            }

            public MsgSsrOrbitClockDepA(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _time = new Gnss.GpsTimeSec(m_io, this, m_root);
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _updateInterval = m_io.ReadU1();
                _iodSsr = m_io.ReadU1();
                _iod = m_io.ReadU1();
                _radial = m_io.ReadS4le();
                _along = m_io.ReadS4le();
                _cross = m_io.ReadS4le();
                _dotRadial = m_io.ReadS4le();
                _dotAlong = m_io.ReadS4le();
                _dotCross = m_io.ReadS4le();
                _c0 = m_io.ReadS4le();
                _c1 = m_io.ReadS4le();
                _c2 = m_io.ReadS4le();
            }
            private Gnss.GpsTimeSec _time;
            private Gnss.GnssSignal _sid;
            private byte _updateInterval;
            private byte _iodSsr;
            private byte _iod;
            private int _radial;
            private int _along;
            private int _cross;
            private int _dotRadial;
            private int _dotAlong;
            private int _dotCross;
            private int _c0;
            private int _c1;
            private int _c2;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// GNSS reference time of the correction
            /// </summary>
            public Gnss.GpsTimeSec Time { get { return _time; } }

            /// <summary>
            /// GNSS signal identifier (16 bit)
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// Update interval between consecutive corrections. Encoded following
            /// RTCM DF391 specification.
            /// </summary>
            public byte UpdateInterval { get { return _updateInterval; } }

            /// <summary>
            /// IOD of the SSR correction. A change of Issue Of Data SSR is used to
            /// indicate a change in the SSR generating configuration
            /// </summary>
            public byte IodSsr { get { return _iodSsr; } }

            /// <summary>
            /// Issue of broadcast ephemeris data
            /// </summary>
            public byte Iod { get { return _iod; } }

            /// <summary>
            /// Orbit radial delta correction
            /// </summary>
            public int Radial { get { return _radial; } }

            /// <summary>
            /// Orbit along delta correction
            /// </summary>
            public int Along { get { return _along; } }

            /// <summary>
            /// Orbit along delta correction
            /// </summary>
            public int Cross { get { return _cross; } }

            /// <summary>
            /// Velocity of orbit radial delta correction
            /// </summary>
            public int DotRadial { get { return _dotRadial; } }

            /// <summary>
            /// Velocity of orbit along delta correction
            /// </summary>
            public int DotAlong { get { return _dotAlong; } }

            /// <summary>
            /// Velocity of orbit cross delta correction
            /// </summary>
            public int DotCross { get { return _dotCross; } }

            /// <summary>
            /// C0 polynomial coefficient for correction of broadcast satellite
            /// clock
            /// </summary>
            public int C0 { get { return _c0; } }

            /// <summary>
            /// C1 polynomial coefficient for correction of broadcast satellite
            /// clock
            /// </summary>
            public int C1 { get { return _c1; } }

            /// <summary>
            /// C2 polynomial coefficient for correction of broadcast satellite
            /// clock
            /// </summary>
            public int C2 { get { return _c2; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }
        public partial class MsgSsrStecCorrection : KaitaiStruct
        {
            public static MsgSsrStecCorrection FromFile(string fileName)
            {
                return new MsgSsrStecCorrection(new KaitaiStream(fileName));
            }

            public MsgSsrStecCorrection(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new BoundsHeader(m_io, this, m_root);
                _ssrIodAtmo = m_io.ReadU1();
                _tileSetId = m_io.ReadU2le();
                _tileId = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _stecSatList = new List<StecSatElement>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _stecSatList.Add(new StecSatElement(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private BoundsHeader _header;
            private byte _ssrIodAtmo;
            private ushort _tileSetId;
            private ushort _tileId;
            private byte _nSats;
            private List<StecSatElement> _stecSatList;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Header of a STEC correction with bounds message.
            /// </summary>
            public BoundsHeader Header { get { return _header; } }

            /// <summary>
            /// IOD of the SSR atmospheric correction
            /// </summary>
            public byte SsrIodAtmo { get { return _ssrIodAtmo; } }

            /// <summary>
            /// Tile set ID
            /// </summary>
            public ushort TileSetId { get { return _tileSetId; } }

            /// <summary>
            /// Tile ID
            /// </summary>
            public ushort TileId { get { return _tileId; } }

            /// <summary>
            /// Number of satellites.
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Array of STEC polynomial coefficients for each space vehicle.
            /// </summary>
            public List<StecSatElement> StecSatList { get { return _stecSatList; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The precise orbit and clock correction message is to be applied as a
        /// delta correction to broadcast ephemeris and is an equivalent to the 1060
        /// /1066 RTCM message types.
        /// </summary>
        public partial class MsgSsrOrbitClock : KaitaiStruct
        {
            public static MsgSsrOrbitClock FromFile(string fileName)
            {
                return new MsgSsrOrbitClock(new KaitaiStream(fileName));
            }

            public MsgSsrOrbitClock(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _time = new Gnss.GpsTimeSec(m_io, this, m_root);
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _updateInterval = m_io.ReadU1();
                _iodSsr = m_io.ReadU1();
                _iod = m_io.ReadU4le();
                _radial = m_io.ReadS4le();
                _along = m_io.ReadS4le();
                _cross = m_io.ReadS4le();
                _dotRadial = m_io.ReadS4le();
                _dotAlong = m_io.ReadS4le();
                _dotCross = m_io.ReadS4le();
                _c0 = m_io.ReadS4le();
                _c1 = m_io.ReadS4le();
                _c2 = m_io.ReadS4le();
            }
            private Gnss.GpsTimeSec _time;
            private Gnss.GnssSignal _sid;
            private byte _updateInterval;
            private byte _iodSsr;
            private uint _iod;
            private int _radial;
            private int _along;
            private int _cross;
            private int _dotRadial;
            private int _dotAlong;
            private int _dotCross;
            private int _c0;
            private int _c1;
            private int _c2;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// GNSS reference time of the correction
            /// </summary>
            public Gnss.GpsTimeSec Time { get { return _time; } }

            /// <summary>
            /// GNSS signal identifier (16 bit)
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// Update interval between consecutive corrections. Encoded following
            /// RTCM DF391 specification.
            /// </summary>
            public byte UpdateInterval { get { return _updateInterval; } }

            /// <summary>
            /// IOD of the SSR correction. A change of Issue Of Data SSR is used to
            /// indicate a change in the SSR generating configuration
            /// </summary>
            public byte IodSsr { get { return _iodSsr; } }

            /// <summary>
            /// Issue of broadcast ephemeris data or IODCRC (Beidou)
            /// </summary>
            public uint Iod { get { return _iod; } }

            /// <summary>
            /// Orbit radial delta correction
            /// </summary>
            public int Radial { get { return _radial; } }

            /// <summary>
            /// Orbit along delta correction
            /// </summary>
            public int Along { get { return _along; } }

            /// <summary>
            /// Orbit along delta correction
            /// </summary>
            public int Cross { get { return _cross; } }

            /// <summary>
            /// Velocity of orbit radial delta correction
            /// </summary>
            public int DotRadial { get { return _dotRadial; } }

            /// <summary>
            /// Velocity of orbit along delta correction
            /// </summary>
            public int DotAlong { get { return _dotAlong; } }

            /// <summary>
            /// Velocity of orbit cross delta correction
            /// </summary>
            public int DotCross { get { return _dotCross; } }

            /// <summary>
            /// C0 polynomial coefficient for correction of broadcast satellite
            /// clock
            /// </summary>
            public int C0 { get { return _c0; } }

            /// <summary>
            /// C1 polynomial coefficient for correction of broadcast satellite
            /// clock
            /// </summary>
            public int C1 { get { return _c1; } }

            /// <summary>
            /// C2 polynomial coefficient for correction of broadcast satellite
            /// clock
            /// </summary>
            public int C2 { get { return _c2; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }
        public partial class BoundsHeader : KaitaiStruct
        {
            public static BoundsHeader FromFile(string fileName)
            {
                return new BoundsHeader(new KaitaiStream(fileName));
            }

            public BoundsHeader(KaitaiStream p__io, KaitaiStruct p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _time = new Gnss.GpsTimeSec(m_io, this, m_root);
                _numMsgs = m_io.ReadU1();
                _seqNum = m_io.ReadU1();
                _updateInterval = m_io.ReadU1();
                _solId = m_io.ReadU1();
            }
            private Gnss.GpsTimeSec _time;
            private byte _numMsgs;
            private byte _seqNum;
            private byte _updateInterval;
            private byte _solId;
            private Ssr m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// GNSS reference time of the bound
            /// </summary>
            public Gnss.GpsTimeSec Time { get { return _time; } }

            /// <summary>
            /// Number of messages in the dataset
            /// </summary>
            public byte NumMsgs { get { return _numMsgs; } }

            /// <summary>
            /// Position of this message in the dataset
            /// </summary>
            public byte SeqNum { get { return _seqNum; } }

            /// <summary>
            /// Update interval between consecutive bounds. Similar to RTCM DF391.
            /// </summary>
            public byte UpdateInterval { get { return _updateInterval; } }

            /// <summary>
            /// SSR Solution ID.
            /// </summary>
            public byte SolId { get { return _solId; } }
            public Ssr M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// STEC residuals are per space vehicle, troposphere is not.
        /// 
        /// It is typically equivalent to the QZSS CLAS Sub Type 9 messages.
        /// </summary>
        public partial class MsgSsrGriddedCorrection : KaitaiStruct
        {
            public static MsgSsrGriddedCorrection FromFile(string fileName)
            {
                return new MsgSsrGriddedCorrection(new KaitaiStream(fileName));
            }

            public MsgSsrGriddedCorrection(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new GriddedCorrectionHeader(m_io, this, m_root);
                _index = m_io.ReadU2le();
                _tropoDelayCorrection = new TroposphericDelayCorrection(m_io, this, m_root);
                _stecResiduals = new List<StecResidual>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _stecResiduals.Add(new StecResidual(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private GriddedCorrectionHeader _header;
            private ushort _index;
            private TroposphericDelayCorrection _tropoDelayCorrection;
            private List<StecResidual> _stecResiduals;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Header of a gridded correction message
            /// </summary>
            public GriddedCorrectionHeader Header { get { return _header; } }

            /// <summary>
            /// Index of the grid point.
            /// </summary>
            public ushort Index { get { return _index; } }

            /// <summary>
            /// Wet and hydrostatic vertical delays (mean, stddev).
            /// </summary>
            public TroposphericDelayCorrection TropoDelayCorrection { get { return _tropoDelayCorrection; } }

            /// <summary>
            /// STEC residuals for each satellite (mean, stddev).
            /// </summary>
            public List<StecResidual> StecResiduals { get { return _stecResiduals; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// STEC residual (mean and standard deviation) for the given satellite at
        /// the grid point.
        /// </summary>
        public partial class StecResidual : KaitaiStruct
        {
            public static StecResidual FromFile(string fileName)
            {
                return new StecResidual(new KaitaiStream(fileName));
            }

            public StecResidual(KaitaiStream p__io, KaitaiStruct p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _svId = new Gnss.SvId(m_io, this, m_root);
                _residual = m_io.ReadS2le();
                _stddev = m_io.ReadU1();
            }
            private Gnss.SvId _svId;
            private short _residual;
            private byte _stddev;
            private Ssr m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// space vehicle identifier
            /// </summary>
            public Gnss.SvId SvId { get { return _svId; } }

            /// <summary>
            /// STEC residual
            /// </summary>
            public short Residual { get { return _residual; } }

            /// <summary>
            /// Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
            /// value/16) - 1) * 10
            /// </summary>
            public byte Stddev { get { return _stddev; } }
            public Ssr M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }
        public partial class CodePhaseBiasesSatSig : KaitaiStruct
        {
            public static CodePhaseBiasesSatSig FromFile(string fileName)
            {
                return new CodePhaseBiasesSatSig(new KaitaiStream(fileName));
            }

            public CodePhaseBiasesSatSig(KaitaiStream p__io, Ssr.MsgSsrCodePhaseBiasesBounds p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _satId = m_io.ReadU1();
                _signalId = m_io.ReadU1();
                _codeBiasBoundMu = m_io.ReadU1();
                _codeBiasBoundSig = m_io.ReadU1();
                _phaseBiasBoundMu = m_io.ReadU1();
                _phaseBiasBoundSig = m_io.ReadU1();
            }
            private byte _satId;
            private byte _signalId;
            private byte _codeBiasBoundMu;
            private byte _codeBiasBoundSig;
            private byte _phaseBiasBoundMu;
            private byte _phaseBiasBoundSig;
            private Ssr m_root;
            private Ssr.MsgSsrCodePhaseBiasesBounds m_parent;

            /// <summary>
            /// Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
            /// or DF488 (BDS) depending on the constellation.
            /// </summary>
            public byte SatId { get { return _satId; } }

            /// <summary>
            /// Signal and Tracking Mode Identifier. Similar to either RTCM DF380
            /// (GPS), DF382 (Galileo) or DF467 (BDS) depending on the
            /// constellation.
            /// </summary>
            public byte SignalId { get { return _signalId; } }

            /// <summary>
            /// Code Bias Mean. Range: 0-1.275 m
            /// </summary>
            public byte CodeBiasBoundMu { get { return _codeBiasBoundMu; } }

            /// <summary>
            /// Code Bias Standard Deviation. Range: 0-1.275 m
            /// </summary>
            public byte CodeBiasBoundSig { get { return _codeBiasBoundSig; } }

            /// <summary>
            /// Phase Bias Mean. Range: 0-1.275 m
            /// </summary>
            public byte PhaseBiasBoundMu { get { return _phaseBiasBoundMu; } }

            /// <summary>
            /// Phase Bias Standard Deviation. Range: 0-1.275 m
            /// </summary>
            public byte PhaseBiasBoundSig { get { return _phaseBiasBoundSig; } }
            public Ssr M_Root { get { return m_root; } }
            public Ssr.MsgSsrCodePhaseBiasesBounds M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Contains phase center offset and elevation variation corrections for one
        /// signal on a satellite.
        /// </summary>
        public partial class SatelliteApc : KaitaiStruct
        {
            public static SatelliteApc FromFile(string fileName)
            {
                return new SatelliteApc(new KaitaiStream(fileName));
            }

            public SatelliteApc(KaitaiStream p__io, KaitaiStruct p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _satInfo = m_io.ReadU1();
                _svn = m_io.ReadU2le();
                _pco = new List<short>();
                for (var i = 0; i < 3; i++)
                {
                    _pco.Add(m_io.ReadS2le());
                }
                _pcv = new List<sbyte>();
                for (var i = 0; i < 21; i++)
                {
                    _pcv.Add(m_io.ReadS1());
                }
            }
            private Gnss.GnssSignal _sid;
            private byte _satInfo;
            private ushort _svn;
            private List<short> _pco;
            private List<sbyte> _pcv;
            private Ssr m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// GNSS signal identifier (16 bit)
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// Additional satellite information
            /// </summary>
            public byte SatInfo { get { return _satInfo; } }

            /// <summary>
            /// Satellite Code, as defined by IGS. Typically the space vehicle
            /// number.
            /// </summary>
            public ushort Svn { get { return _svn; } }

            /// <summary>
            /// Mean phase center offset, X Y and Z axes. See IGS ANTEX file format
            /// description for coordinate system definition.
            /// </summary>
            public List<short> Pco { get { return _pco; } }

            /// <summary>
            /// Elevation dependent phase center variations. First element is 0
            /// degrees separation from the Z axis, subsequent elements represent
            /// elevation variations in 1 degree increments.
            /// </summary>
            public List<sbyte> Pcv { get { return _pcv; } }
            public Ssr M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The LPP message contains nested variable length arrays which are not
        /// supported in SBP, so each grid point will be identified by the index.
        /// </summary>
        public partial class GriddedCorrectionHeader : KaitaiStruct
        {
            public static GriddedCorrectionHeader FromFile(string fileName)
            {
                return new GriddedCorrectionHeader(new KaitaiStream(fileName));
            }

            public GriddedCorrectionHeader(KaitaiStream p__io, Ssr.MsgSsrGriddedCorrection p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tileSetId = m_io.ReadU2le();
                _tileId = m_io.ReadU2le();
                _time = new Gnss.GpsTimeSec(m_io, this, m_root);
                _numMsgs = m_io.ReadU2le();
                _seqNum = m_io.ReadU2le();
                _updateInterval = m_io.ReadU1();
                _iodAtmo = m_io.ReadU1();
                _tropoQualityIndicator = m_io.ReadU1();
            }
            private ushort _tileSetId;
            private ushort _tileId;
            private Gnss.GpsTimeSec _time;
            private ushort _numMsgs;
            private ushort _seqNum;
            private byte _updateInterval;
            private byte _iodAtmo;
            private byte _tropoQualityIndicator;
            private Ssr m_root;
            private Ssr.MsgSsrGriddedCorrection m_parent;

            /// <summary>
            /// Unique identifier of the tile set this tile belongs to.
            /// </summary>
            public ushort TileSetId { get { return _tileSetId; } }

            /// <summary>
            /// Unique identifier of this tile in the tile set.
            /// </summary>
            public ushort TileId { get { return _tileId; } }

            /// <summary>
            /// GNSS reference time of the correction
            /// </summary>
            public Gnss.GpsTimeSec Time { get { return _time; } }

            /// <summary>
            /// Number of messages in the dataset
            /// </summary>
            public ushort NumMsgs { get { return _numMsgs; } }

            /// <summary>
            /// Position of this message in the dataset
            /// </summary>
            public ushort SeqNum { get { return _seqNum; } }

            /// <summary>
            /// Update interval between consecutive corrections. Encoded following
            /// RTCM DF391 specification.
            /// </summary>
            public byte UpdateInterval { get { return _updateInterval; } }

            /// <summary>
            /// IOD of the SSR atmospheric correction
            /// </summary>
            public byte IodAtmo { get { return _iodAtmo; } }

            /// <summary>
            /// Quality of the troposphere data. Encoded following RTCM DF389
            /// specification in units of m.
            /// </summary>
            public byte TropoQualityIndicator { get { return _tropoQualityIndicator; } }
            public Ssr M_Root { get { return m_root; } }
            public Ssr.MsgSsrGriddedCorrection M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// STEC polynomial for the given satellite.
        /// </summary>
        public partial class StecSatElement : KaitaiStruct
        {
            public static StecSatElement FromFile(string fileName)
            {
                return new StecSatElement(new KaitaiStream(fileName));
            }

            public StecSatElement(KaitaiStream p__io, KaitaiStruct p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _svId = new Gnss.SvId(m_io, this, m_root);
                _stecQualityIndicator = m_io.ReadU1();
                _stecCoeff = new List<short>();
                for (var i = 0; i < 4; i++)
                {
                    _stecCoeff.Add(m_io.ReadS2le());
                }
            }
            private Gnss.SvId _svId;
            private byte _stecQualityIndicator;
            private List<short> _stecCoeff;
            private Ssr m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// Unique space vehicle identifier
            /// </summary>
            public Gnss.SvId SvId { get { return _svId; } }

            /// <summary>
            /// Quality of the STEC data. Encoded following RTCM DF389 specification
            /// but in units of TECU instead of m.
            /// </summary>
            public byte StecQualityIndicator { get { return _stecQualityIndicator; } }

            /// <summary>
            /// Coefficients of the STEC polynomial in the order of C00, C01, C10,
            /// C11. C00 = 0.05 TECU, C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2
            /// </summary>
            public List<short> StecCoeff { get { return _stecCoeff; } }
            public Ssr M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// A full set of STEC information will likely span multiple SBP messages,
        /// since SBP message a limited to 255 bytes.  The header is used to tie
        /// multiple SBP messages into a sequence.
        /// </summary>
        public partial class StecHeaderDepA : KaitaiStruct
        {
            public static StecHeaderDepA FromFile(string fileName)
            {
                return new StecHeaderDepA(new KaitaiStream(fileName));
            }

            public StecHeaderDepA(KaitaiStream p__io, Ssr.MsgSsrStecCorrectionDepA p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _time = new Gnss.GpsTimeSec(m_io, this, m_root);
                _numMsgs = m_io.ReadU1();
                _seqNum = m_io.ReadU1();
                _updateInterval = m_io.ReadU1();
                _iodAtmo = m_io.ReadU1();
            }
            private Gnss.GpsTimeSec _time;
            private byte _numMsgs;
            private byte _seqNum;
            private byte _updateInterval;
            private byte _iodAtmo;
            private Ssr m_root;
            private Ssr.MsgSsrStecCorrectionDepA m_parent;

            /// <summary>
            /// GNSS reference time of the correction
            /// </summary>
            public Gnss.GpsTimeSec Time { get { return _time; } }

            /// <summary>
            /// Number of messages in the dataset
            /// </summary>
            public byte NumMsgs { get { return _numMsgs; } }

            /// <summary>
            /// Position of this message in the dataset
            /// </summary>
            public byte SeqNum { get { return _seqNum; } }

            /// <summary>
            /// Update interval between consecutive corrections. Encoded following
            /// RTCM DF391 specification.
            /// </summary>
            public byte UpdateInterval { get { return _updateInterval; } }

            /// <summary>
            /// IOD of the SSR atmospheric correction
            /// </summary>
            public byte IodAtmo { get { return _iodAtmo; } }
            public Ssr M_Root { get { return m_root; } }
            public Ssr.MsgSsrStecCorrectionDepA M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// A full set of STEC information will likely span multiple SBP messages,
        /// since SBP message a limited to 255 bytes.  The header is used to tie
        /// multiple SBP messages into a sequence.
        /// </summary>
        public partial class StecHeader : KaitaiStruct
        {
            public static StecHeader FromFile(string fileName)
            {
                return new StecHeader(new KaitaiStream(fileName));
            }

            public StecHeader(KaitaiStream p__io, Ssr.MsgSsrStecCorrectionDep p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tileSetId = m_io.ReadU2le();
                _tileId = m_io.ReadU2le();
                _time = new Gnss.GpsTimeSec(m_io, this, m_root);
                _numMsgs = m_io.ReadU1();
                _seqNum = m_io.ReadU1();
                _updateInterval = m_io.ReadU1();
                _iodAtmo = m_io.ReadU1();
            }
            private ushort _tileSetId;
            private ushort _tileId;
            private Gnss.GpsTimeSec _time;
            private byte _numMsgs;
            private byte _seqNum;
            private byte _updateInterval;
            private byte _iodAtmo;
            private Ssr m_root;
            private Ssr.MsgSsrStecCorrectionDep m_parent;

            /// <summary>
            /// Unique identifier of the tile set this tile belongs to.
            /// </summary>
            public ushort TileSetId { get { return _tileSetId; } }

            /// <summary>
            /// Unique identifier of this tile in the tile set.
            /// </summary>
            public ushort TileId { get { return _tileId; } }

            /// <summary>
            /// GNSS reference time of the correction
            /// </summary>
            public Gnss.GpsTimeSec Time { get { return _time; } }

            /// <summary>
            /// Number of messages in the dataset
            /// </summary>
            public byte NumMsgs { get { return _numMsgs; } }

            /// <summary>
            /// Position of this message in the dataset
            /// </summary>
            public byte SeqNum { get { return _seqNum; } }

            /// <summary>
            /// Update interval between consecutive corrections. Encoded following
            /// RTCM DF391 specification.
            /// </summary>
            public byte UpdateInterval { get { return _updateInterval; } }

            /// <summary>
            /// IOD of the SSR atmospheric correction
            /// </summary>
            public byte IodAtmo { get { return _iodAtmo; } }
            public Ssr M_Root { get { return m_root; } }
            public Ssr.MsgSsrStecCorrectionDep M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgSsrStecCorrectionDepA : KaitaiStruct
        {
            public static MsgSsrStecCorrectionDepA FromFile(string fileName)
            {
                return new MsgSsrStecCorrectionDepA(new KaitaiStream(fileName));
            }

            public MsgSsrStecCorrectionDepA(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new StecHeaderDepA(m_io, this, m_root);
                _stecSatList = new List<StecSatElement>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _stecSatList.Add(new StecSatElement(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private StecHeaderDepA _header;
            private List<StecSatElement> _stecSatList;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Header of a STEC message
            /// </summary>
            public StecHeaderDepA Header { get { return _header; } }

            /// <summary>
            /// Array of STEC information for each space vehicle
            /// </summary>
            public List<StecSatElement> StecSatList { get { return _stecSatList; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The 3GPP message contains nested variable length arrays which are not
        /// supported in SBP, so each grid point will be identified by the index.
        /// </summary>
        public partial class GriddedCorrectionHeaderDepA : KaitaiStruct
        {
            public static GriddedCorrectionHeaderDepA FromFile(string fileName)
            {
                return new GriddedCorrectionHeaderDepA(new KaitaiStream(fileName));
            }

            public GriddedCorrectionHeaderDepA(KaitaiStream p__io, KaitaiStruct p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _time = new Gnss.GpsTimeSec(m_io, this, m_root);
                _numMsgs = m_io.ReadU2le();
                _seqNum = m_io.ReadU2le();
                _updateInterval = m_io.ReadU1();
                _iodAtmo = m_io.ReadU1();
                _tropoQualityIndicator = m_io.ReadU1();
            }
            private Gnss.GpsTimeSec _time;
            private ushort _numMsgs;
            private ushort _seqNum;
            private byte _updateInterval;
            private byte _iodAtmo;
            private byte _tropoQualityIndicator;
            private Ssr m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// GNSS reference time of the correction
            /// </summary>
            public Gnss.GpsTimeSec Time { get { return _time; } }

            /// <summary>
            /// Number of messages in the dataset
            /// </summary>
            public ushort NumMsgs { get { return _numMsgs; } }

            /// <summary>
            /// Position of this message in the dataset
            /// </summary>
            public ushort SeqNum { get { return _seqNum; } }

            /// <summary>
            /// Update interval between consecutive corrections. Encoded following
            /// RTCM DF391 specification.
            /// </summary>
            public byte UpdateInterval { get { return _updateInterval; } }

            /// <summary>
            /// IOD of the SSR atmospheric correction
            /// </summary>
            public byte IodAtmo { get { return _iodAtmo; } }

            /// <summary>
            /// Quality of the troposphere data. Encoded following RTCM DF389
            /// specification in units of m.
            /// </summary>
            public byte TropoQualityIndicator { get { return _tropoQualityIndicator; } }
            public Ssr M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Note 1: Range: 0-17.5 m. i&lt;=200, mean=0.01i; 200&lt;i&lt;=230,
        /// mean=2+0.1(i-200); i&gt;230, mean=5+0.5(i-230).
        /// 
        /// Note 2: Range: 0-17.5 m. i&lt;=200, std=0.01i; 200&lt;i&lt;=230, std=2+0.1(i-200)
        /// i&gt;230, std=5+0.5(i-230).
        /// </summary>
        public partial class MsgSsrOrbitClockBounds : KaitaiStruct
        {
            public static MsgSsrOrbitClockBounds FromFile(string fileName)
            {
                return new MsgSsrOrbitClockBounds(new KaitaiStream(fileName));
            }

            public MsgSsrOrbitClockBounds(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new BoundsHeader(m_io, this, m_root);
                _ssrIod = m_io.ReadU1();
                _constId = m_io.ReadU1();
                _nSats = m_io.ReadU1();
                _orbitClockBounds = new List<OrbitClockBound>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _orbitClockBounds.Add(new OrbitClockBound(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private BoundsHeader _header;
            private byte _ssrIod;
            private byte _constId;
            private byte _nSats;
            private List<OrbitClockBound> _orbitClockBounds;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Header of a bounds message.
            /// </summary>
            public BoundsHeader Header { get { return _header; } }

            /// <summary>
            /// IOD of the SSR bound.
            /// </summary>
            public byte SsrIod { get { return _ssrIod; } }

            /// <summary>
            /// Constellation ID to which the SVs belong.
            /// </summary>
            public byte ConstId { get { return _constId; } }

            /// <summary>
            /// Number of satellites.
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Orbit and Clock Bounds per Satellite
            /// </summary>
            public List<OrbitClockBound> OrbitClockBounds { get { return _orbitClockBounds; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Note 1: Range: 0-17.5 m. i&lt;= 200, mean = 0.01i; 200&lt;i&lt;=230,
        /// mean=2+0.1(i-200); i&gt;230, mean=5+0.5(i-230).
        /// </summary>
        public partial class MsgSsrGriddedCorrectionBounds : KaitaiStruct
        {
            public static MsgSsrGriddedCorrectionBounds FromFile(string fileName)
            {
                return new MsgSsrGriddedCorrectionBounds(new KaitaiStream(fileName));
            }

            public MsgSsrGriddedCorrectionBounds(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new BoundsHeader(m_io, this, m_root);
                _ssrIodAtmo = m_io.ReadU1();
                _tileSetId = m_io.ReadU2le();
                _tileId = m_io.ReadU2le();
                _tropoQi = m_io.ReadU1();
                _gridPointId = m_io.ReadU2le();
                _tropoDelayCorrection = new TroposphericDelayCorrection(m_io, this, m_root);
                _tropoVHydroBoundMu = m_io.ReadU1();
                _tropoVHydroBoundSig = m_io.ReadU1();
                _tropoVWetBoundMu = m_io.ReadU1();
                _tropoVWetBoundSig = m_io.ReadU1();
                _nSats = m_io.ReadU1();
                _stecSatList = new List<StecSatElementIntegrity>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _stecSatList.Add(new StecSatElementIntegrity(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private BoundsHeader _header;
            private byte _ssrIodAtmo;
            private ushort _tileSetId;
            private ushort _tileId;
            private byte _tropoQi;
            private ushort _gridPointId;
            private TroposphericDelayCorrection _tropoDelayCorrection;
            private byte _tropoVHydroBoundMu;
            private byte _tropoVHydroBoundSig;
            private byte _tropoVWetBoundMu;
            private byte _tropoVWetBoundSig;
            private byte _nSats;
            private List<StecSatElementIntegrity> _stecSatList;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Header of a bounds message.
            /// </summary>
            public BoundsHeader Header { get { return _header; } }

            /// <summary>
            /// IOD of the correction.
            /// </summary>
            public byte SsrIodAtmo { get { return _ssrIodAtmo; } }

            /// <summary>
            /// Set this tile belongs to.
            /// </summary>
            public ushort TileSetId { get { return _tileSetId; } }

            /// <summary>
            /// Unique identifier of this tile in the tile set.
            /// </summary>
            public ushort TileId { get { return _tileId; } }

            /// <summary>
            /// Tropo Quality Indicator. Similar to RTCM DF389.
            /// </summary>
            public byte TropoQi { get { return _tropoQi; } }

            /// <summary>
            /// Index of the Grid Point.
            /// </summary>
            public ushort GridPointId { get { return _gridPointId; } }

            /// <summary>
            /// Tropospheric delay at grid point.
            /// </summary>
            public TroposphericDelayCorrection TropoDelayCorrection { get { return _tropoDelayCorrection; } }

            /// <summary>
            /// Vertical Hydrostatic Error Bound Mean.
            /// </summary>
            public byte TropoVHydroBoundMu { get { return _tropoVHydroBoundMu; } }

            /// <summary>
            /// Vertical Hydrostatic Error Bound StDev.
            /// </summary>
            public byte TropoVHydroBoundSig { get { return _tropoVHydroBoundSig; } }

            /// <summary>
            /// Vertical Wet Error Bound Mean.
            /// </summary>
            public byte TropoVWetBoundMu { get { return _tropoVWetBoundMu; } }

            /// <summary>
            /// Vertical Wet Error Bound StDev.
            /// </summary>
            public byte TropoVWetBoundSig { get { return _tropoVWetBoundSig; } }

            /// <summary>
            /// Number of satellites.
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Array of STEC polynomial coefficients and its bounds for each space
            /// vehicle.
            /// </summary>
            public List<StecSatElementIntegrity> StecSatList { get { return _stecSatList; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgSsrGridDefinitionDepA : KaitaiStruct
        {
            public static MsgSsrGridDefinitionDepA FromFile(string fileName)
            {
                return new MsgSsrGridDefinitionDepA(new KaitaiStream(fileName));
            }

            public MsgSsrGridDefinitionDepA(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new GridDefinitionHeaderDepA(m_io, this, m_root);
                _rleList = new List<byte>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _rleList.Add(m_io.ReadU1());
                        i++;
                    }
                }
            }
            private GridDefinitionHeaderDepA _header;
            private List<byte> _rleList;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Header of a Gridded Correction message
            /// </summary>
            public GridDefinitionHeaderDepA Header { get { return _header; } }

            /// <summary>
            /// Run Length Encode list of quadrants that contain valid data. The
            /// spec describes the encoding scheme in detail, but essentially the
            /// index of the quadrants that contain transitions between valid and
            /// invalid (and vice versa) are encoded as u8 integers.
            /// </summary>
            public List<byte> RleList { get { return _rleList; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Code biases are to be added to pseudorange. The corrections conform with
        /// RTCMv3 MT 1059 / 1065.
        /// </summary>
        public partial class CodeBiasesContent : KaitaiStruct
        {
            public static CodeBiasesContent FromFile(string fileName)
            {
                return new CodeBiasesContent(new KaitaiStream(fileName));
            }

            public CodeBiasesContent(KaitaiStream p__io, Ssr.MsgSsrCodeBiases p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _code = m_io.ReadU1();
                _value = m_io.ReadS2le();
            }
            private byte _code;
            private short _value;
            private Ssr m_root;
            private Ssr.MsgSsrCodeBiases m_parent;

            /// <summary>
            /// Signal encoded following RTCM specifications (DF380, DF381, DF382
            /// and DF467).
            /// </summary>
            public byte Code { get { return _code; } }

            /// <summary>
            /// Code bias value
            /// </summary>
            public short Value { get { return _value; } }
            public Ssr M_Root { get { return m_root; } }
            public Ssr.MsgSsrCodeBiases M_Parent { get { return m_parent; } }
        }
        public partial class MsgSsrSatelliteApc : KaitaiStruct
        {
            public static MsgSsrSatelliteApc FromFile(string fileName)
            {
                return new MsgSsrSatelliteApc(new KaitaiStream(fileName));
            }

            public MsgSsrSatelliteApc(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _time = new Gnss.GpsTimeSec(m_io, this, m_root);
                _updateInterval = m_io.ReadU1();
                _solId = m_io.ReadU1();
                _iodSsr = m_io.ReadU1();
                _apc = new List<SatelliteApc>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _apc.Add(new SatelliteApc(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private Gnss.GpsTimeSec _time;
            private byte _updateInterval;
            private byte _solId;
            private byte _iodSsr;
            private List<SatelliteApc> _apc;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// GNSS reference time of the correction
            /// </summary>
            public Gnss.GpsTimeSec Time { get { return _time; } }

            /// <summary>
            /// Update interval between consecutive corrections. Encoded following
            /// RTCM DF391 specification.
            /// </summary>
            public byte UpdateInterval { get { return _updateInterval; } }

            /// <summary>
            /// SSR Solution ID. Similar to RTCM DF415.
            /// </summary>
            public byte SolId { get { return _solId; } }

            /// <summary>
            /// IOD of the SSR correction. A change of Issue Of Data SSR is used to
            /// indicate a change in the SSR generating configuration
            /// </summary>
            public byte IodSsr { get { return _iodSsr; } }

            /// <summary>
            /// Satellite antenna phase center corrections
            /// </summary>
            public List<SatelliteApc> Apc { get { return _apc; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Phase biases are to be added to carrier phase measurements.
        /// </summary>
        public partial class PhaseBiasesContent : KaitaiStruct
        {
            public static PhaseBiasesContent FromFile(string fileName)
            {
                return new PhaseBiasesContent(new KaitaiStream(fileName));
            }

            public PhaseBiasesContent(KaitaiStream p__io, Ssr.MsgSsrPhaseBiases p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _code = m_io.ReadU1();
                _integerIndicator = m_io.ReadU1();
                _widelaneIntegerIndicator = m_io.ReadU1();
                _discontinuityCounter = m_io.ReadU1();
                _bias = m_io.ReadS4le();
            }
            private byte _code;
            private byte _integerIndicator;
            private byte _widelaneIntegerIndicator;
            private byte _discontinuityCounter;
            private int _bias;
            private Ssr m_root;
            private Ssr.MsgSsrPhaseBiases m_parent;

            /// <summary>
            /// Signal encoded following RTCM specifications (DF380, DF381, DF382
            /// and DF467)
            /// </summary>
            public byte Code { get { return _code; } }

            /// <summary>
            /// Indicator for integer property
            /// </summary>
            public byte IntegerIndicator { get { return _integerIndicator; } }

            /// <summary>
            /// Indicator for two groups of Wide-Lane(s) integer property
            /// </summary>
            public byte WidelaneIntegerIndicator { get { return _widelaneIntegerIndicator; } }

            /// <summary>
            /// Signal phase discontinuity counter. Increased for every
            /// discontinuity in phase.
            /// </summary>
            public byte DiscontinuityCounter { get { return _discontinuityCounter; } }

            /// <summary>
            /// Phase bias for specified signal
            /// </summary>
            public int Bias { get { return _bias; } }
            public Ssr M_Root { get { return m_root; } }
            public Ssr.MsgSsrPhaseBiases M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgSsrTileDefinitionDepA : KaitaiStruct
        {
            public static MsgSsrTileDefinitionDepA FromFile(string fileName)
            {
                return new MsgSsrTileDefinitionDepA(new KaitaiStream(fileName));
            }

            public MsgSsrTileDefinitionDepA(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tileSetId = m_io.ReadU2le();
                _tileId = m_io.ReadU2le();
                _cornerNwLat = m_io.ReadS2le();
                _cornerNwLon = m_io.ReadS2le();
                _spacingLat = m_io.ReadU2le();
                _spacingLon = m_io.ReadU2le();
                _rows = m_io.ReadU2le();
                _cols = m_io.ReadU2le();
                _bitmask = m_io.ReadU8le();
            }
            private ushort _tileSetId;
            private ushort _tileId;
            private short _cornerNwLat;
            private short _cornerNwLon;
            private ushort _spacingLat;
            private ushort _spacingLon;
            private ushort _rows;
            private ushort _cols;
            private ulong _bitmask;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Unique identifier of the tile set this tile belongs to.
            /// </summary>
            public ushort TileSetId { get { return _tileSetId; } }

            /// <summary>
            /// Unique identifier of this tile in the tile set.
            /// See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
            /// </summary>
            public ushort TileId { get { return _tileId; } }

            /// <summary>
            /// North-West corner correction point latitude.
            /// 
            /// The relation between the latitude X in the range [-90, 90] and the
            /// coded number N is:
            /// 
            /// N = floor((X / 90) * 2^14)
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
            /// </summary>
            public short CornerNwLat { get { return _cornerNwLat; } }

            /// <summary>
            /// North-West corner correction point longitude.
            /// 
            /// The relation between the longitude X in the range [-180, 180] and
            /// the coded number N is:
            /// 
            /// N = floor((X / 180) * 2^15)
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
            /// </summary>
            public short CornerNwLon { get { return _cornerNwLon; } }

            /// <summary>
            /// Spacing of the correction points in the latitude direction.
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
            /// </summary>
            public ushort SpacingLat { get { return _spacingLat; } }

            /// <summary>
            /// Spacing of the correction points in the longitude direction.
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
            /// </summary>
            public ushort SpacingLon { get { return _spacingLon; } }

            /// <summary>
            /// Number of steps in the latitude direction.
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
            /// </summary>
            public ushort Rows { get { return _rows; } }

            /// <summary>
            /// Number of steps in the longitude direction.
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
            /// </summary>
            public ushort Cols { get { return _cols; } }

            /// <summary>
            /// Specifies the availability of correction data at the correction
            /// points in the array.
            /// 
            /// If a specific bit is enabled (set to 1), the correction is not
            /// available. Only the first rows * cols bits are used, the remainder
            /// are set to 0. If there are more then 64 correction points the
            /// remaining corrections are always available.
            /// 
            /// Starting with the northwest corner of the array (top left on a north
            /// oriented map) the correction points are enumerated with row
            /// precedence - first row west to east, second row west to east, until
            /// last row west to east - ending with the southeast corner of the
            /// array.
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
            /// the definition of the bits is inverted.
            /// </summary>
            public ulong Bitmask { get { return _bitmask; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Orbit and clock bound.
        /// </summary>
        public partial class OrbitClockBound : KaitaiStruct
        {
            public static OrbitClockBound FromFile(string fileName)
            {
                return new OrbitClockBound(new KaitaiStream(fileName));
            }

            public OrbitClockBound(KaitaiStream p__io, Ssr.MsgSsrOrbitClockBounds p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _satId = m_io.ReadU1();
                _orbRadialBoundMu = m_io.ReadU1();
                _orbAlongBoundMu = m_io.ReadU1();
                _orbCrossBoundMu = m_io.ReadU1();
                _orbRadialBoundSig = m_io.ReadU1();
                _orbAlongBoundSig = m_io.ReadU1();
                _orbCrossBoundSig = m_io.ReadU1();
                _clockBoundMu = m_io.ReadU1();
                _clockBoundSig = m_io.ReadU1();
            }
            private byte _satId;
            private byte _orbRadialBoundMu;
            private byte _orbAlongBoundMu;
            private byte _orbCrossBoundMu;
            private byte _orbRadialBoundSig;
            private byte _orbAlongBoundSig;
            private byte _orbCrossBoundSig;
            private byte _clockBoundMu;
            private byte _clockBoundSig;
            private Ssr m_root;
            private Ssr.MsgSsrOrbitClockBounds m_parent;

            /// <summary>
            /// Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
            /// or DF488 (BDS) depending on the constellation.
            /// </summary>
            public byte SatId { get { return _satId; } }

            /// <summary>
            /// Mean Radial. See Note 1.
            /// </summary>
            public byte OrbRadialBoundMu { get { return _orbRadialBoundMu; } }

            /// <summary>
            /// Mean Along-Track. See Note 1.
            /// </summary>
            public byte OrbAlongBoundMu { get { return _orbAlongBoundMu; } }

            /// <summary>
            /// Mean Cross-Track. See Note 1.
            /// </summary>
            public byte OrbCrossBoundMu { get { return _orbCrossBoundMu; } }

            /// <summary>
            /// Standard Deviation Radial. See Note 2.
            /// </summary>
            public byte OrbRadialBoundSig { get { return _orbRadialBoundSig; } }

            /// <summary>
            /// Standard Deviation Along-Track. See Note 2.
            /// </summary>
            public byte OrbAlongBoundSig { get { return _orbAlongBoundSig; } }

            /// <summary>
            /// Standard Deviation Cross-Track. See Note 2.
            /// </summary>
            public byte OrbCrossBoundSig { get { return _orbCrossBoundSig; } }

            /// <summary>
            /// Clock Bound Mean. See Note 1.
            /// </summary>
            public byte ClockBoundMu { get { return _clockBoundMu; } }

            /// <summary>
            /// Clock Bound Standard Deviation. See Note 2.
            /// </summary>
            public byte ClockBoundSig { get { return _clockBoundSig; } }
            public Ssr M_Root { get { return m_root; } }
            public Ssr.MsgSsrOrbitClockBounds M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgSsrGriddedCorrectionDepA : KaitaiStruct
        {
            public static MsgSsrGriddedCorrectionDepA FromFile(string fileName)
            {
                return new MsgSsrGriddedCorrectionDepA(new KaitaiStream(fileName));
            }

            public MsgSsrGriddedCorrectionDepA(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new GriddedCorrectionHeaderDepA(m_io, this, m_root);
                _index = m_io.ReadU2le();
                _tropoDelayCorrection = new TroposphericDelayCorrection(m_io, this, m_root);
                _stecResiduals = new List<StecResidual>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _stecResiduals.Add(new StecResidual(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private GriddedCorrectionHeaderDepA _header;
            private ushort _index;
            private TroposphericDelayCorrection _tropoDelayCorrection;
            private List<StecResidual> _stecResiduals;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Header of a Gridded Correction message
            /// </summary>
            public GriddedCorrectionHeaderDepA Header { get { return _header; } }

            /// <summary>
            /// Index of the grid point
            /// </summary>
            public ushort Index { get { return _index; } }

            /// <summary>
            /// Wet and hydrostatic vertical delays (mean, stddev)
            /// </summary>
            public TroposphericDelayCorrection TropoDelayCorrection { get { return _tropoDelayCorrection; } }

            /// <summary>
            /// STEC residuals for each satellite (mean, stddev)
            /// </summary>
            public List<StecResidual> StecResiduals { get { return _stecResiduals; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }
        public partial class MsgSsrOrbitClockBoundsDegradation : KaitaiStruct
        {
            public static MsgSsrOrbitClockBoundsDegradation FromFile(string fileName)
            {
                return new MsgSsrOrbitClockBoundsDegradation(new KaitaiStream(fileName));
            }

            public MsgSsrOrbitClockBoundsDegradation(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new BoundsHeader(m_io, this, m_root);
                _ssrIod = m_io.ReadU1();
                _constId = m_io.ReadU1();
                _satBitmask = m_io.ReadU8le();
                _orbitClockBoundsDegradation = new OrbitClockBoundDegradation(m_io, this, m_root);
            }
            private BoundsHeader _header;
            private byte _ssrIod;
            private byte _constId;
            private ulong _satBitmask;
            private OrbitClockBoundDegradation _orbitClockBoundsDegradation;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Header of a bounds message.
            /// </summary>
            public BoundsHeader Header { get { return _header; } }

            /// <summary>
            /// IOD of the SSR bound degradation parameter.
            /// </summary>
            public byte SsrIod { get { return _ssrIod; } }

            /// <summary>
            /// Constellation ID to which the SVs belong.
            /// </summary>
            public byte ConstId { get { return _constId; } }

            /// <summary>
            /// Satellite Bit Mask. Put 1 for each satellite where the following
            /// degradation parameters are applicable, 0 otherwise. Encoded
            /// following RTCM DF394 specification.
            /// </summary>
            public ulong SatBitmask { get { return _satBitmask; } }

            /// <summary>
            /// Orbit and Clock Bounds Degradation Parameters
            /// </summary>
            public OrbitClockBoundDegradation OrbitClockBoundsDegradation { get { return _orbitClockBoundsDegradation; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgSsrGriddedCorrectionNoStdDepA : KaitaiStruct
        {
            public static MsgSsrGriddedCorrectionNoStdDepA FromFile(string fileName)
            {
                return new MsgSsrGriddedCorrectionNoStdDepA(new KaitaiStream(fileName));
            }

            public MsgSsrGriddedCorrectionNoStdDepA(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new GriddedCorrectionHeaderDepA(m_io, this, m_root);
                _index = m_io.ReadU2le();
                _tropoDelayCorrection = new TroposphericDelayCorrectionNoStd(m_io, this, m_root);
                _stecResiduals = new List<StecResidualNoStd>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _stecResiduals.Add(new StecResidualNoStd(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private GriddedCorrectionHeaderDepA _header;
            private ushort _index;
            private TroposphericDelayCorrectionNoStd _tropoDelayCorrection;
            private List<StecResidualNoStd> _stecResiduals;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Header of a Gridded Correction message
            /// </summary>
            public GriddedCorrectionHeaderDepA Header { get { return _header; } }

            /// <summary>
            /// Index of the grid point
            /// </summary>
            public ushort Index { get { return _index; } }

            /// <summary>
            /// Wet and hydrostatic vertical delays
            /// </summary>
            public TroposphericDelayCorrectionNoStd TropoDelayCorrection { get { return _tropoDelayCorrection; } }

            /// <summary>
            /// STEC residuals for each satellite
            /// </summary>
            public List<StecResidualNoStd> StecResiduals { get { return _stecResiduals; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }
        public partial class MsgSsrCodePhaseBiasesBounds : KaitaiStruct
        {
            public static MsgSsrCodePhaseBiasesBounds FromFile(string fileName)
            {
                return new MsgSsrCodePhaseBiasesBounds(new KaitaiStream(fileName));
            }

            public MsgSsrCodePhaseBiasesBounds(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new BoundsHeader(m_io, this, m_root);
                _ssrIod = m_io.ReadU1();
                _constId = m_io.ReadU1();
                _nSatsSignals = m_io.ReadU1();
                _satellitesSignals = new List<CodePhaseBiasesSatSig>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _satellitesSignals.Add(new CodePhaseBiasesSatSig(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private BoundsHeader _header;
            private byte _ssrIod;
            private byte _constId;
            private byte _nSatsSignals;
            private List<CodePhaseBiasesSatSig> _satellitesSignals;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Header of a bounds message.
            /// </summary>
            public BoundsHeader Header { get { return _header; } }

            /// <summary>
            /// IOD of the SSR bound.
            /// </summary>
            public byte SsrIod { get { return _ssrIod; } }

            /// <summary>
            /// Constellation ID to which the SVs belong.
            /// </summary>
            public byte ConstId { get { return _constId; } }

            /// <summary>
            /// Number of satellite-signal couples.
            /// </summary>
            public byte NSatsSignals { get { return _nSatsSignals; } }

            /// <summary>
            /// Code and Phase Biases Bounds per Satellite-Signal couple.
            /// </summary>
            public List<CodePhaseBiasesSatSig> SatellitesSignals { get { return _satellitesSignals; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The precise code biases message is to be added to the pseudorange of the
        /// corresponding signal to get corrected pseudorange. It is an equivalent
        /// to the 1059 / 1065 RTCM message types.
        /// </summary>
        public partial class MsgSsrCodeBiases : KaitaiStruct
        {
            public static MsgSsrCodeBiases FromFile(string fileName)
            {
                return new MsgSsrCodeBiases(new KaitaiStream(fileName));
            }

            public MsgSsrCodeBiases(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _time = new Gnss.GpsTimeSec(m_io, this, m_root);
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _updateInterval = m_io.ReadU1();
                _iodSsr = m_io.ReadU1();
                _biases = new List<CodeBiasesContent>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _biases.Add(new CodeBiasesContent(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private Gnss.GpsTimeSec _time;
            private Gnss.GnssSignal _sid;
            private byte _updateInterval;
            private byte _iodSsr;
            private List<CodeBiasesContent> _biases;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// GNSS reference time of the correction
            /// </summary>
            public Gnss.GpsTimeSec Time { get { return _time; } }

            /// <summary>
            /// GNSS signal identifier (16 bit)
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// Update interval between consecutive corrections. Encoded following
            /// RTCM DF391 specification.
            /// </summary>
            public byte UpdateInterval { get { return _updateInterval; } }

            /// <summary>
            /// IOD of the SSR correction. A change of Issue Of Data SSR is used to
            /// indicate a change in the SSR generating configuration
            /// </summary>
            public byte IodSsr { get { return _iodSsr; } }

            /// <summary>
            /// Code biases for the different satellite signals
            /// </summary>
            public List<CodeBiasesContent> Biases { get { return _biases; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Provides the correction point coordinates for the atmospheric correction
        /// values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
        /// messages.
        /// 
        /// Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
        /// element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
        /// correction points, not lists of points.
        /// </summary>
        public partial class MsgSsrTileDefinition : KaitaiStruct
        {
            public static MsgSsrTileDefinition FromFile(string fileName)
            {
                return new MsgSsrTileDefinition(new KaitaiStream(fileName));
            }

            public MsgSsrTileDefinition(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _time = new Gnss.GpsTimeSec(m_io, this, m_root);
                _updateInterval = m_io.ReadU1();
                _solId = m_io.ReadU1();
                _iodAtmo = m_io.ReadU1();
                _tileSetId = m_io.ReadU2le();
                _tileId = m_io.ReadU2le();
                _cornerNwLat = m_io.ReadS2le();
                _cornerNwLon = m_io.ReadS2le();
                _spacingLat = m_io.ReadU2le();
                _spacingLon = m_io.ReadU2le();
                _rows = m_io.ReadU2le();
                _cols = m_io.ReadU2le();
                _bitmask = m_io.ReadU8le();
            }
            private Gnss.GpsTimeSec _time;
            private byte _updateInterval;
            private byte _solId;
            private byte _iodAtmo;
            private ushort _tileSetId;
            private ushort _tileId;
            private short _cornerNwLat;
            private short _cornerNwLon;
            private ushort _spacingLat;
            private ushort _spacingLon;
            private ushort _rows;
            private ushort _cols;
            private ulong _bitmask;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// GNSS reference time of the correction
            /// </summary>
            public Gnss.GpsTimeSec Time { get { return _time; } }

            /// <summary>
            /// Update interval between consecutive corrections. Encoded following
            /// RTCM DF391 specification.
            /// </summary>
            public byte UpdateInterval { get { return _updateInterval; } }

            /// <summary>
            /// SSR Solution ID. Similar to RTCM DF415.
            /// </summary>
            public byte SolId { get { return _solId; } }

            /// <summary>
            /// IOD of the SSR atmospheric correction.
            /// </summary>
            public byte IodAtmo { get { return _iodAtmo; } }

            /// <summary>
            /// Unique identifier of the tile set this tile belongs to.
            /// </summary>
            public ushort TileSetId { get { return _tileSetId; } }

            /// <summary>
            /// Unique identifier of this tile in the tile set.
            /// See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
            /// </summary>
            public ushort TileId { get { return _tileId; } }

            /// <summary>
            /// North-West corner correction point latitude.
            /// 
            /// The relation between the latitude X in the range [-90, 90] and the
            /// coded number N is:  N = floor((X / 90) * 2^14)
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
            /// </summary>
            public short CornerNwLat { get { return _cornerNwLat; } }

            /// <summary>
            /// North-West corner correction point longitude.
            /// 
            /// The relation between the longitude X in the range [-180, 180] and
            /// the coded number N is: N = floor((X / 180) * 2^15)
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
            /// </summary>
            public short CornerNwLon { get { return _cornerNwLon; } }

            /// <summary>
            /// Spacing of the correction points in the latitude direction.
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
            /// </summary>
            public ushort SpacingLat { get { return _spacingLat; } }

            /// <summary>
            /// Spacing of the correction points in the longitude direction.
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
            /// </summary>
            public ushort SpacingLon { get { return _spacingLon; } }

            /// <summary>
            /// Number of steps in the latitude direction.
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
            /// </summary>
            public ushort Rows { get { return _rows; } }

            /// <summary>
            /// Number of steps in the longitude direction.
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
            /// </summary>
            public ushort Cols { get { return _cols; } }

            /// <summary>
            /// Specifies the absence of correction data at the correction points in
            /// the array (grid).
            /// 
            /// Only the first rows * cols bits are used, and if a specific bit is
            /// enabled (set to 1), the correction is not available. If there are
            /// more than 64 correction points the remaining corrections are always
            /// available.
            /// 
            /// The correction points are packed by rows, starting with the
            /// northwest corner of the array (top-left on a north oriented map),
            /// with each row spanning west to east, ending with the southeast
            /// corner of the array.
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
            /// the definition of the bits is inverted.
            /// </summary>
            public ulong Bitmask { get { return _bitmask; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Orbit and clock bound degradation.
        /// </summary>
        public partial class OrbitClockBoundDegradation : KaitaiStruct
        {
            public static OrbitClockBoundDegradation FromFile(string fileName)
            {
                return new OrbitClockBoundDegradation(new KaitaiStream(fileName));
            }

            public OrbitClockBoundDegradation(KaitaiStream p__io, Ssr.MsgSsrOrbitClockBoundsDegradation p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _orbRadialBoundMuDot = m_io.ReadU1();
                _orbAlongBoundMuDot = m_io.ReadU1();
                _orbCrossBoundMuDot = m_io.ReadU1();
                _orbRadialBoundSigDot = m_io.ReadU1();
                _orbAlongBoundSigDot = m_io.ReadU1();
                _orbCrossBoundSigDot = m_io.ReadU1();
                _clockBoundMuDot = m_io.ReadU1();
                _clockBoundSigDot = m_io.ReadU1();
            }
            private byte _orbRadialBoundMuDot;
            private byte _orbAlongBoundMuDot;
            private byte _orbCrossBoundMuDot;
            private byte _orbRadialBoundSigDot;
            private byte _orbAlongBoundSigDot;
            private byte _orbCrossBoundSigDot;
            private byte _clockBoundMuDot;
            private byte _clockBoundSigDot;
            private Ssr m_root;
            private Ssr.MsgSsrOrbitClockBoundsDegradation m_parent;

            /// <summary>
            /// Orbit Bound Mean Radial First derivative. Range: 0-0.255 m/s
            /// </summary>
            public byte OrbRadialBoundMuDot { get { return _orbRadialBoundMuDot; } }

            /// <summary>
            /// Orbit Bound Mean Along-Track First derivative. Range: 0-0.255 m/s
            /// </summary>
            public byte OrbAlongBoundMuDot { get { return _orbAlongBoundMuDot; } }

            /// <summary>
            /// Orbit Bound Mean Cross-Track First derivative. Range: 0-0.255 m/s
            /// </summary>
            public byte OrbCrossBoundMuDot { get { return _orbCrossBoundMuDot; } }

            /// <summary>
            /// Orbit Bound Standard Deviation Radial First derivative. Range:
            /// 0-0.255 m/s
            /// </summary>
            public byte OrbRadialBoundSigDot { get { return _orbRadialBoundSigDot; } }

            /// <summary>
            /// Orbit Bound Standard Deviation Along-Track First derivative. Range:
            /// 0-0.255 m/s
            /// </summary>
            public byte OrbAlongBoundSigDot { get { return _orbAlongBoundSigDot; } }

            /// <summary>
            /// Orbit Bound Standard Deviation Cross-Track First derivative. Range:
            /// 0-0.255 m/s
            /// </summary>
            public byte OrbCrossBoundSigDot { get { return _orbCrossBoundSigDot; } }

            /// <summary>
            /// Clock Bound Mean First derivative. Range: 0-0.255 m/s
            /// </summary>
            public byte ClockBoundMuDot { get { return _clockBoundMuDot; } }

            /// <summary>
            /// Clock Bound Standard Deviation First derivative. Range: 0-0.255 m/s
            /// </summary>
            public byte ClockBoundSigDot { get { return _clockBoundSigDot; } }
            public Ssr M_Root { get { return m_root; } }
            public Ssr.MsgSsrOrbitClockBoundsDegradation M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgSsrSatelliteApcDep : KaitaiStruct
        {
            public static MsgSsrSatelliteApcDep FromFile(string fileName)
            {
                return new MsgSsrSatelliteApcDep(new KaitaiStream(fileName));
            }

            public MsgSsrSatelliteApcDep(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _apc = new List<SatelliteApc>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _apc.Add(new SatelliteApc(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private List<SatelliteApc> _apc;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Satellite antenna phase center corrections
            /// </summary>
            public List<SatelliteApc> Apc { get { return _apc; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Troposphere vertical delays (mean and standard deviation) at the grid
        /// point.
        /// </summary>
        public partial class TroposphericDelayCorrection : KaitaiStruct
        {
            public static TroposphericDelayCorrection FromFile(string fileName)
            {
                return new TroposphericDelayCorrection(new KaitaiStream(fileName));
            }

            public TroposphericDelayCorrection(KaitaiStream p__io, KaitaiStruct p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _hydro = m_io.ReadS2le();
                _wet = m_io.ReadS1();
                _stddev = m_io.ReadU1();
            }
            private short _hydro;
            private sbyte _wet;
            private byte _stddev;
            private Ssr m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// Hydrostatic vertical delay. Add 2.3 m to get actual value.
            /// </summary>
            public short Hydro { get { return _hydro; } }

            /// <summary>
            /// Wet vertical delay. Add 0.252 m to get actual value.
            /// </summary>
            public sbyte Wet { get { return _wet; } }

            /// <summary>
            /// Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
            /// value/16) - 1)
            /// </summary>
            public byte Stddev { get { return _stddev; } }
            public Ssr M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgSsrTileDefinitionDepB : KaitaiStruct
        {
            public static MsgSsrTileDefinitionDepB FromFile(string fileName)
            {
                return new MsgSsrTileDefinitionDepB(new KaitaiStream(fileName));
            }

            public MsgSsrTileDefinitionDepB(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _ssrSolId = m_io.ReadU1();
                _tileSetId = m_io.ReadU2le();
                _tileId = m_io.ReadU2le();
                _cornerNwLat = m_io.ReadS2le();
                _cornerNwLon = m_io.ReadS2le();
                _spacingLat = m_io.ReadU2le();
                _spacingLon = m_io.ReadU2le();
                _rows = m_io.ReadU2le();
                _cols = m_io.ReadU2le();
                _bitmask = m_io.ReadU8le();
            }
            private byte _ssrSolId;
            private ushort _tileSetId;
            private ushort _tileId;
            private short _cornerNwLat;
            private short _cornerNwLon;
            private ushort _spacingLat;
            private ushort _spacingLon;
            private ushort _rows;
            private ushort _cols;
            private ulong _bitmask;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// SSR Solution ID.
            /// </summary>
            public byte SsrSolId { get { return _ssrSolId; } }

            /// <summary>
            /// Unique identifier of the tile set this tile belongs to.
            /// </summary>
            public ushort TileSetId { get { return _tileSetId; } }

            /// <summary>
            /// Unique identifier of this tile in the tile set.
            /// See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
            /// </summary>
            public ushort TileId { get { return _tileId; } }

            /// <summary>
            /// North-West corner correction point latitude.
            /// 
            /// The relation between the latitude X in the range [-90, 90] and the
            /// coded number N is:
            /// 
            /// N = floor((X / 90) * 2^14)
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
            /// </summary>
            public short CornerNwLat { get { return _cornerNwLat; } }

            /// <summary>
            /// North-West corner correction point longitude.
            /// 
            /// The relation between the longitude X in the range [-180, 180] and
            /// the coded number N is:
            /// 
            /// N = floor((X / 180) * 2^15)
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
            /// </summary>
            public short CornerNwLon { get { return _cornerNwLon; } }

            /// <summary>
            /// Spacing of the correction points in the latitude direction.
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
            /// </summary>
            public ushort SpacingLat { get { return _spacingLat; } }

            /// <summary>
            /// Spacing of the correction points in the longitude direction.
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
            /// </summary>
            public ushort SpacingLon { get { return _spacingLon; } }

            /// <summary>
            /// Number of steps in the latitude direction.
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
            /// </summary>
            public ushort Rows { get { return _rows; } }

            /// <summary>
            /// Number of steps in the longitude direction.
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
            /// </summary>
            public ushort Cols { get { return _cols; } }

            /// <summary>
            /// Specifies the availability of correction data at the correction
            /// points in the array.
            /// 
            /// If a specific bit is enabled (set to 1), the correction is not
            /// available. Only the first rows * cols bits are used, the remainder
            /// are set to 0. If there are more then 64 correction points the
            /// remaining corrections are always available.
            /// 
            /// Starting with the northwest corner of the array (top left on a north
            /// oriented map) the correction points are enumerated with row
            /// precedence - first row west to east, second row west to east, until
            /// last row west to east - ending with the southeast corner of the
            /// array.
            /// 
            /// See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
            /// the definition of the bits is inverted.
            /// </summary>
            public ulong Bitmask { get { return _bitmask; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The precise phase biases message contains the biases to be added to the
        /// carrier phase of the corresponding signal to get corrected carrier phase
        /// measurement, as well as the satellite yaw angle to be applied to compute
        /// the phase wind-up correction. It is typically an equivalent to the 1265
        /// RTCM message types.
        /// </summary>
        public partial class MsgSsrPhaseBiases : KaitaiStruct
        {
            public static MsgSsrPhaseBiases FromFile(string fileName)
            {
                return new MsgSsrPhaseBiases(new KaitaiStream(fileName));
            }

            public MsgSsrPhaseBiases(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Ssr p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _time = new Gnss.GpsTimeSec(m_io, this, m_root);
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _updateInterval = m_io.ReadU1();
                _iodSsr = m_io.ReadU1();
                _dispersiveBias = m_io.ReadU1();
                _mwConsistency = m_io.ReadU1();
                _yaw = m_io.ReadU2le();
                _yawRate = m_io.ReadS1();
                _biases = new List<PhaseBiasesContent>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _biases.Add(new PhaseBiasesContent(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private Gnss.GpsTimeSec _time;
            private Gnss.GnssSignal _sid;
            private byte _updateInterval;
            private byte _iodSsr;
            private byte _dispersiveBias;
            private byte _mwConsistency;
            private ushort _yaw;
            private sbyte _yawRate;
            private List<PhaseBiasesContent> _biases;
            private Ssr m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// GNSS reference time of the correction
            /// </summary>
            public Gnss.GpsTimeSec Time { get { return _time; } }

            /// <summary>
            /// GNSS signal identifier (16 bit)
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// Update interval between consecutive corrections. Encoded following
            /// RTCM DF391 specification.
            /// </summary>
            public byte UpdateInterval { get { return _updateInterval; } }

            /// <summary>
            /// IOD of the SSR correction. A change of Issue Of Data SSR is used to
            /// indicate a change in the SSR generating configuration
            /// </summary>
            public byte IodSsr { get { return _iodSsr; } }

            /// <summary>
            /// Indicator for the dispersive phase biases property.
            /// </summary>
            public byte DispersiveBias { get { return _dispersiveBias; } }

            /// <summary>
            /// Consistency indicator for Melbourne-Wubbena linear combinations
            /// </summary>
            public byte MwConsistency { get { return _mwConsistency; } }

            /// <summary>
            /// Satellite yaw angle
            /// </summary>
            public ushort Yaw { get { return _yaw; } }

            /// <summary>
            /// Satellite yaw angle rate
            /// </summary>
            public sbyte YawRate { get { return _yawRate; } }

            /// <summary>
            /// Phase biases corrections for a satellite being tracked.
            /// </summary>
            public List<PhaseBiasesContent> Biases { get { return _biases; } }
            public Ssr M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }
        private Ssr m_root;
        private KaitaiStruct m_parent;
        public Ssr M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
