// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class Integrity : KaitaiStruct
    {
        public static Integrity FromFile(string fileName)
        {
            return new Integrity(new KaitaiStream(fileName));
        }

        public Integrity(KaitaiStream p__io, KaitaiStruct p__parent = null, Integrity p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }
        public partial class MsgSsrFlagSatellites : KaitaiStruct
        {
            public static MsgSsrFlagSatellites FromFile(string fileName)
            {
                return new MsgSsrFlagSatellites(new KaitaiStream(fileName));
            }

            public MsgSsrFlagSatellites(KaitaiStream p__io, Sbp.Message p__parent = null, Integrity p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _obsTime = new Gnss.GpsTimeSec(m_io, this, m_root);
                _numMsgs = m_io.ReadU1();
                _seqNum = m_io.ReadU1();
                _ssrSolId = m_io.ReadU1();
                _chainId = m_io.ReadU1();
                _constId = m_io.ReadU1();
                _nFaultySats = m_io.ReadU1();
                _faultySats = new List<byte>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _faultySats.Add(m_io.ReadU1());
                        i++;
                    }
                }
            }
            private Gnss.GpsTimeSec _obsTime;
            private byte _numMsgs;
            private byte _seqNum;
            private byte _ssrSolId;
            private byte _chainId;
            private byte _constId;
            private byte _nFaultySats;
            private List<byte> _faultySats;
            private Integrity m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GNSS reference time of the observation used to generate the flag.
            /// </summary>
            public Gnss.GpsTimeSec ObsTime { get { return _obsTime; } }

            /// <summary>
            /// Number of messages in the dataset
            /// </summary>
            public byte NumMsgs { get { return _numMsgs; } }

            /// <summary>
            /// Position of this message in the dataset
            /// </summary>
            public byte SeqNum { get { return _seqNum; } }

            /// <summary>
            /// SSR Solution ID.
            /// </summary>
            public byte SsrSolId { get { return _ssrSolId; } }

            /// <summary>
            /// Chain and type of flag.
            /// </summary>
            public byte ChainId { get { return _chainId; } }

            /// <summary>
            /// Constellation ID.
            /// </summary>
            public byte ConstId { get { return _constId; } }

            /// <summary>
            /// Number of faulty satellites.
            /// </summary>
            public byte NFaultySats { get { return _nFaultySats; } }

            /// <summary>
            /// List of faulty satellites.
            /// </summary>
            public List<byte> FaultySats { get { return _faultySats; } }
            public Integrity M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        public partial class MsgSsrFlagIonoTileSatLos : KaitaiStruct
        {
            public static MsgSsrFlagIonoTileSatLos FromFile(string fileName)
            {
                return new MsgSsrFlagIonoTileSatLos(new KaitaiStream(fileName));
            }

            public MsgSsrFlagIonoTileSatLos(KaitaiStream p__io, Sbp.Message p__parent = null, Integrity p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new IntegritySsrHeader(m_io, this, m_root);
                _nFaultyLos = m_io.ReadU1();
                _faultyLos = new List<Gnss.SvId>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _faultyLos.Add(new Gnss.SvId(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private IntegritySsrHeader _header;
            private byte _nFaultyLos;
            private List<Gnss.SvId> _faultyLos;
            private Integrity m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Header of an integrity message.
            /// </summary>
            public IntegritySsrHeader Header { get { return _header; } }

            /// <summary>
            /// Number of faulty LOS.
            /// </summary>
            public byte NFaultyLos { get { return _nFaultyLos; } }

            /// <summary>
            /// List of faulty LOS
            /// </summary>
            public List<Gnss.SvId> FaultyLos { get { return _faultyLos; } }
            public Integrity M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        public partial class MsgSsrFlagIonoGridPointSatLos : KaitaiStruct
        {
            public static MsgSsrFlagIonoGridPointSatLos FromFile(string fileName)
            {
                return new MsgSsrFlagIonoGridPointSatLos(new KaitaiStream(fileName));
            }

            public MsgSsrFlagIonoGridPointSatLos(KaitaiStream p__io, Sbp.Message p__parent = null, Integrity p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new IntegritySsrHeader(m_io, this, m_root);
                _gridPointId = m_io.ReadU2le();
                _nFaultyLos = m_io.ReadU1();
                _faultyLos = new List<Gnss.SvId>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _faultyLos.Add(new Gnss.SvId(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private IntegritySsrHeader _header;
            private ushort _gridPointId;
            private byte _nFaultyLos;
            private List<Gnss.SvId> _faultyLos;
            private Integrity m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Header of an integrity message.
            /// </summary>
            public IntegritySsrHeader Header { get { return _header; } }

            /// <summary>
            /// Index of the grid point.
            /// </summary>
            public ushort GridPointId { get { return _gridPointId; } }

            /// <summary>
            /// Number of faulty LOS.
            /// </summary>
            public byte NFaultyLos { get { return _nFaultyLos; } }

            /// <summary>
            /// List of faulty LOS
            /// </summary>
            public List<Gnss.SvId> FaultyLos { get { return _faultyLos; } }
            public Integrity M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        public partial class IntegritySsrHeader : KaitaiStruct
        {
            public static IntegritySsrHeader FromFile(string fileName)
            {
                return new IntegritySsrHeader(new KaitaiStream(fileName));
            }

            public IntegritySsrHeader(KaitaiStream p__io, KaitaiStruct p__parent = null, Integrity p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _obsTime = new Gnss.GpsTimeSec(m_io, this, m_root);
                _numMsgs = m_io.ReadU1();
                _seqNum = m_io.ReadU1();
                _ssrSolId = m_io.ReadU1();
                _tileSetId = m_io.ReadU2le();
                _tileId = m_io.ReadU2le();
                _chainId = m_io.ReadU1();
            }
            private Gnss.GpsTimeSec _obsTime;
            private byte _numMsgs;
            private byte _seqNum;
            private byte _ssrSolId;
            private ushort _tileSetId;
            private ushort _tileId;
            private byte _chainId;
            private Integrity m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// GNSS reference time of the observation used to generate the flag.
            /// </summary>
            public Gnss.GpsTimeSec ObsTime { get { return _obsTime; } }

            /// <summary>
            /// Number of messages in the dataset
            /// </summary>
            public byte NumMsgs { get { return _numMsgs; } }

            /// <summary>
            /// Position of this message in the dataset
            /// </summary>
            public byte SeqNum { get { return _seqNum; } }

            /// <summary>
            /// SSR Solution ID.
            /// </summary>
            public byte SsrSolId { get { return _ssrSolId; } }

            /// <summary>
            /// Unique identifier of the set this tile belongs to.
            /// </summary>
            public ushort TileSetId { get { return _tileSetId; } }

            /// <summary>
            /// Unique identifier of this tile in the tile set.
            /// </summary>
            public ushort TileId { get { return _tileId; } }

            /// <summary>
            /// Chain and type of flag.
            /// </summary>
            public byte ChainId { get { return _chainId; } }
            public Integrity M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }
        public partial class MsgAcknowledge : KaitaiStruct
        {
            public static MsgAcknowledge FromFile(string fileName)
            {
                return new MsgAcknowledge(new KaitaiStream(fileName));
            }

            public MsgAcknowledge(KaitaiStream p__io, Sbp.Message p__parent = null, Integrity p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _requestId = m_io.ReadU1();
                _areaId = m_io.ReadU4le();
                _responseCode = m_io.ReadU1();
                _correctionMaskOnDemand = m_io.ReadU2le();
                _correctionMaskStream = m_io.ReadU2le();
                _solutionId = m_io.ReadU1();
            }
            private byte _requestId;
            private uint _areaId;
            private byte _responseCode;
            private ushort _correctionMaskOnDemand;
            private ushort _correctionMaskStream;
            private byte _solutionId;
            private Integrity m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Echo of the request ID field from the corresponding CRA message, or
            /// 255 if no request ID was provided.
            /// </summary>
            public byte RequestId { get { return _requestId; } }

            /// <summary>
            /// Echo of the Area ID field from the corresponding CRA message.
            /// </summary>
            public uint AreaId { get { return _areaId; } }

            /// <summary>
            /// Reported status of the request.
            /// </summary>
            public byte ResponseCode { get { return _responseCode; } }

            /// <summary>
            /// Contains the message group(s) that will be sent in response from the
            /// corresponding CRA correction mask. An echo of the correction mask
            /// field from the corresponding CRA message.
            /// </summary>
            public ushort CorrectionMaskOnDemand { get { return _correctionMaskOnDemand; } }

            /// <summary>
            /// For future expansion. Always set to 0.
            /// </summary>
            public ushort CorrectionMaskStream { get { return _correctionMaskStream; } }

            /// <summary>
            /// The solution ID of the instance providing the corrections.
            /// </summary>
            public byte SolutionId { get { return _solutionId; } }
            public Integrity M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        public partial class MsgSsrFlagIonoGridPoints : KaitaiStruct
        {
            public static MsgSsrFlagIonoGridPoints FromFile(string fileName)
            {
                return new MsgSsrFlagIonoGridPoints(new KaitaiStream(fileName));
            }

            public MsgSsrFlagIonoGridPoints(KaitaiStream p__io, Sbp.Message p__parent = null, Integrity p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new IntegritySsrHeader(m_io, this, m_root);
                _nFaultyPoints = m_io.ReadU1();
                _faultyPoints = new List<ushort>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _faultyPoints.Add(m_io.ReadU2le());
                        i++;
                    }
                }
            }
            private IntegritySsrHeader _header;
            private byte _nFaultyPoints;
            private List<ushort> _faultyPoints;
            private Integrity m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Header of an integrity message.
            /// </summary>
            public IntegritySsrHeader Header { get { return _header; } }

            /// <summary>
            /// Number of faulty grid points.
            /// </summary>
            public byte NFaultyPoints { get { return _nFaultyPoints; } }

            /// <summary>
            /// List of faulty grid points.
            /// </summary>
            public List<ushort> FaultyPoints { get { return _faultyPoints; } }
            public Integrity M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        public partial class MsgSsrFlagTropoGridPoints : KaitaiStruct
        {
            public static MsgSsrFlagTropoGridPoints FromFile(string fileName)
            {
                return new MsgSsrFlagTropoGridPoints(new KaitaiStream(fileName));
            }

            public MsgSsrFlagTropoGridPoints(KaitaiStream p__io, Sbp.Message p__parent = null, Integrity p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _header = new IntegritySsrHeader(m_io, this, m_root);
                _nFaultyPoints = m_io.ReadU1();
                _faultyPoints = new List<ushort>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _faultyPoints.Add(m_io.ReadU2le());
                        i++;
                    }
                }
            }
            private IntegritySsrHeader _header;
            private byte _nFaultyPoints;
            private List<ushort> _faultyPoints;
            private Integrity m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Header of an integrity message.
            /// </summary>
            public IntegritySsrHeader Header { get { return _header; } }

            /// <summary>
            /// Number of faulty grid points.
            /// </summary>
            public byte NFaultyPoints { get { return _nFaultyPoints; } }

            /// <summary>
            /// List of faulty grid points.
            /// </summary>
            public List<ushort> FaultyPoints { get { return _faultyPoints; } }
            public Integrity M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Integrity monitoring flags for multiple aggregated elements. An element
        /// could be a satellite, SSR grid point, or SSR tile. A group of aggregated
        /// elements being monitored for integrity could refer to:
        /// 
        /// - Satellites in a particular {GPS, GAL, BDS} constellation.
        /// 
        /// - Satellites in the line-of-sight of a particular SSR tile.
        /// 
        /// - Satellites in the line-of-sight of a particular SSR grid point.
        /// 
        /// The integrity usage for a group of aggregated elements varies according
        /// to the integrity flag of the satellites comprising that group.
        /// 
        /// SSR_INTEGRITY_USAGE_NOMINAL: All satellites received passed the
        /// integrity check and have flag INTEGRITY_FLAG_OK.
        /// 
        /// SSR_INTEGRITY_USAGE_WARNING: A limited number of elements in the group
        /// failed the integrity check. Refer to more granular integrity messages
        /// for details on the specific failing elements.
        /// 
        /// SSR_INTEGRITY_USAGE_ALERT: Most elements in the group failed the
        /// integrity check, do not use for positioning.
        /// 
        /// SSR_INTEGRITY_USAGE_NOT_MONITORED: Unable to verify the integrity flag
        /// of elements in the group.
        /// </summary>
        public partial class MsgSsrFlagHighLevel : KaitaiStruct
        {
            public static MsgSsrFlagHighLevel FromFile(string fileName)
            {
                return new MsgSsrFlagHighLevel(new KaitaiStream(fileName));
            }

            public MsgSsrFlagHighLevel(KaitaiStream p__io, Sbp.Message p__parent = null, Integrity p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _obsTime = new Gnss.GpsTimeSec(m_io, this, m_root);
                _corrTime = new Gnss.GpsTimeSec(m_io, this, m_root);
                _ssrSolId = m_io.ReadU1();
                _tileSetId = m_io.ReadU2le();
                _tileId = m_io.ReadU2le();
                _chainId = m_io.ReadU1();
                _useGpsSat = m_io.ReadU1();
                _useGalSat = m_io.ReadU1();
                _useBdsSat = m_io.ReadU1();
                _reserved = new List<byte>();
                for (var i = 0; i < 6; i++)
                {
                    _reserved.Add(m_io.ReadU1());
                }
                _useTropoGridPoints = m_io.ReadU1();
                _useIonoGridPoints = m_io.ReadU1();
                _useIonoTileSatLos = m_io.ReadU1();
                _useIonoGridPointSatLos = m_io.ReadU1();
            }
            private Gnss.GpsTimeSec _obsTime;
            private Gnss.GpsTimeSec _corrTime;
            private byte _ssrSolId;
            private ushort _tileSetId;
            private ushort _tileId;
            private byte _chainId;
            private byte _useGpsSat;
            private byte _useGalSat;
            private byte _useBdsSat;
            private List<byte> _reserved;
            private byte _useTropoGridPoints;
            private byte _useIonoGridPoints;
            private byte _useIonoTileSatLos;
            private byte _useIonoGridPointSatLos;
            private Integrity m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GNSS reference time of the observation used to generate the flag.
            /// </summary>
            public Gnss.GpsTimeSec ObsTime { get { return _obsTime; } }

            /// <summary>
            /// GNSS reference time of the correction associated to the flag.
            /// </summary>
            public Gnss.GpsTimeSec CorrTime { get { return _corrTime; } }

            /// <summary>
            /// SSR Solution ID.
            /// </summary>
            public byte SsrSolId { get { return _ssrSolId; } }

            /// <summary>
            /// Unique identifier of the set this tile belongs to.
            /// </summary>
            public ushort TileSetId { get { return _tileSetId; } }

            /// <summary>
            /// Unique identifier of this tile in the tile set.
            /// </summary>
            public ushort TileId { get { return _tileId; } }

            /// <summary>
            /// Chain and type of flag.
            /// </summary>
            public byte ChainId { get { return _chainId; } }

            /// <summary>
            /// Use GPS satellites.
            /// </summary>
            public byte UseGpsSat { get { return _useGpsSat; } }

            /// <summary>
            /// Use GAL satellites.
            /// </summary>
            public byte UseGalSat { get { return _useGalSat; } }

            /// <summary>
            /// Use BDS satellites.
            /// </summary>
            public byte UseBdsSat { get { return _useBdsSat; } }

            /// <summary>
            /// Reserved
            /// </summary>
            public List<byte> Reserved { get { return _reserved; } }

            /// <summary>
            /// Use tropo grid points.
            /// </summary>
            public byte UseTropoGridPoints { get { return _useTropoGridPoints; } }

            /// <summary>
            /// Use iono grid points.
            /// </summary>
            public byte UseIonoGridPoints { get { return _useIonoGridPoints; } }

            /// <summary>
            /// Use iono tile satellite LoS.
            /// </summary>
            public byte UseIonoTileSatLos { get { return _useIonoTileSatLos; } }

            /// <summary>
            /// Use iono grid point satellite LoS.
            /// </summary>
            public byte UseIonoGridPointSatLos { get { return _useIonoGridPointSatLos; } }
            public Integrity M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        private Integrity m_root;
        private KaitaiStruct m_parent;
        public Integrity M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
