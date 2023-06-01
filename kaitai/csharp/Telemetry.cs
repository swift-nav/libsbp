// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class Telemetry : KaitaiStruct
    {
        public static Telemetry FromFile(string fileName)
        {
            return new Telemetry(new KaitaiStream(fileName));
        }

        public Telemetry(KaitaiStream p__io, KaitaiStruct p__parent = null, Telemetry p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }
        public partial class TelemetrySv : KaitaiStruct
        {
            public static TelemetrySv FromFile(string fileName)
            {
                return new TelemetrySv(new KaitaiStream(fileName));
            }

            public TelemetrySv(KaitaiStream p__io, Telemetry.MsgTelSv p__parent = null, Telemetry p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _az = m_io.ReadU1();
                _el = m_io.ReadS1();
                _availabilityFlags = m_io.ReadU1();
                _pseudorangeResidual = m_io.ReadS2le();
                _phaseResidual = m_io.ReadS2le();
                _outlierFlags = m_io.ReadU1();
                _ephemerisFlags = m_io.ReadU1();
                _correctionFlags = m_io.ReadU1();
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
            }
            private byte _az;
            private sbyte _el;
            private byte _availabilityFlags;
            private short _pseudorangeResidual;
            private short _phaseResidual;
            private byte _outlierFlags;
            private byte _ephemerisFlags;
            private byte _correctionFlags;
            private Gnss.GnssSignal _sid;
            private Telemetry m_root;
            private Telemetry.MsgTelSv m_parent;

            /// <summary>
            /// Azimuth angle (range 0..179)
            /// </summary>
            public byte Az { get { return _az; } }

            /// <summary>
            /// Elevation angle (range -90..90)
            /// </summary>
            public sbyte El { get { return _el; } }

            /// <summary>
            /// Observation availability at filter update
            /// </summary>
            public byte AvailabilityFlags { get { return _availabilityFlags; } }

            /// <summary>
            /// Pseudorange observation residual
            /// </summary>
            public short PseudorangeResidual { get { return _pseudorangeResidual; } }

            /// <summary>
            /// Carrier-phase or carrier-phase-derived observation residual
            /// </summary>
            public short PhaseResidual { get { return _phaseResidual; } }

            /// <summary>
            /// Reports if observation is marked as an outlier and is excluded from
            /// the update
            /// </summary>
            public byte OutlierFlags { get { return _outlierFlags; } }

            /// <summary>
            /// Ephemeris metadata
            /// </summary>
            public byte EphemerisFlags { get { return _ephemerisFlags; } }

            /// <summary>
            /// Reserved
            /// </summary>
            public byte CorrectionFlags { get { return _correctionFlags; } }

            /// <summary>
            /// GNSS signal identifier (16 bit)
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }
            public Telemetry M_Root { get { return m_root; } }
            public Telemetry.MsgTelSv M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message includes telemetry pertinent to satellite signals available
        /// to Starling.
        /// </summary>
        public partial class MsgTelSv : KaitaiStruct
        {
            public static MsgTelSv FromFile(string fileName)
            {
                return new MsgTelSv(new KaitaiStream(fileName));
            }

            public MsgTelSv(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Telemetry p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _wn = m_io.ReadU2le();
                _tow = m_io.ReadU4le();
                _nObs = m_io.ReadU1();
                _originFlags = m_io.ReadU1();
                _svTel = new List<TelemetrySv>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _svTel.Add(new TelemetrySv(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private ushort _wn;
            private uint _tow;
            private byte _nObs;
            private byte _originFlags;
            private List<TelemetrySv> _svTel;
            private Telemetry m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// GPS week number
            /// </summary>
            public ushort Wn { get { return _wn; } }

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Total number of observations. First nibble is the size of the
            /// sequence (n), second nibble is the zero-indexed counter (ith packet
            /// of n)
            /// </summary>
            public byte NObs { get { return _nObs; } }

            /// <summary>
            /// Flags to identify the filter type from which the telemetry is
            /// reported from
            /// </summary>
            public byte OriginFlags { get { return _originFlags; } }

            /// <summary>
            /// Array of per-signal telemetry entries
            /// </summary>
            public List<TelemetrySv> SvTel { get { return _svTel; } }
            public Telemetry M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }
        private Telemetry m_root;
        private KaitaiStruct m_parent;
        public Telemetry M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
