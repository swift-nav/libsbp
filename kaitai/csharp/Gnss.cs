// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild



namespace Kaitai
{
    public partial class Gnss : KaitaiStruct
    {
        public static Gnss FromFile(string fileName)
        {
            return new Gnss(new KaitaiStream(fileName));
        }

        public Gnss(KaitaiStream p__io, KaitaiStruct p__parent = null, Gnss p__root = null) : base(p__io)
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
        public partial class GnssSignalDep : KaitaiStruct
        {
            public static GnssSignalDep FromFile(string fileName)
            {
                return new GnssSignalDep(new KaitaiStream(fileName));
            }

            public GnssSignalDep(KaitaiStream p__io, KaitaiStruct p__parent = null, Gnss p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sat = m_io.ReadU2le();
                _code = m_io.ReadU1();
                _reserved = m_io.ReadU1();
            }
            private ushort _sat;
            private byte _code;
            private byte _reserved;
            private Gnss m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// Constellation-specific satellite identifier.
            /// 
            /// Note: unlike GnssSignal, GPS satellites are encoded as (PRN - 1).
            /// Other constellations do not have this offset.
            /// </summary>
            public ushort Sat { get { return _sat; } }

            /// <summary>
            /// Signal constellation, band and code
            /// </summary>
            public byte Code { get { return _code; } }

            /// <summary>
            /// Reserved
            /// </summary>
            public byte Reserved { get { return _reserved; } }
            public Gnss M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Carrier phase measurement in cycles represented as a 40-bit fixed point
        /// number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
        /// fractional cycles. This phase has the same sign as the pseudorange.
        /// </summary>
        public partial class CarrierPhase : KaitaiStruct
        {
            public static CarrierPhase FromFile(string fileName)
            {
                return new CarrierPhase(new KaitaiStream(fileName));
            }

            public CarrierPhase(KaitaiStream p__io, KaitaiStruct p__parent = null, Gnss p__root = null) : base(p__io)
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
            private Gnss m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// Carrier phase whole cycles
            /// </summary>
            public int I { get { return _i; } }

            /// <summary>
            /// Carrier phase fractional part
            /// </summary>
            public byte F { get { return _f; } }
            public Gnss M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// A wire-appropriate GPS time, defined as the number of milliseconds since
        /// beginning of the week on the Saturday/Sunday transition.
        /// </summary>
        public partial class GpsTimeDep : KaitaiStruct
        {
            public static GpsTimeDep FromFile(string fileName)
            {
                return new GpsTimeDep(new KaitaiStream(fileName));
            }

            public GpsTimeDep(KaitaiStream p__io, KaitaiStruct p__parent = null, Gnss p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _wn = m_io.ReadU2le();
            }
            private uint _tow;
            private ushort _wn;
            private Gnss m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// Milliseconds since start of GPS week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// GPS week number
            /// </summary>
            public ushort Wn { get { return _wn; } }
            public Gnss M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Signal identifier containing constellation, band, and satellite
        /// identifier.
        /// </summary>
        public partial class GnssSignal : KaitaiStruct
        {
            public static GnssSignal FromFile(string fileName)
            {
                return new GnssSignal(new KaitaiStream(fileName));
            }

            public GnssSignal(KaitaiStream p__io, KaitaiStruct p__parent = null, Gnss p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sat = m_io.ReadU1();
                _code = m_io.ReadU1();
            }
            private byte _sat;
            private byte _code;
            private Gnss m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// Constellation-specific satellite id. For GLO can either be (100+FCN)
            /// where FCN is in [-7,+6] or the Slot ID in [1,28].
            /// </summary>
            public byte Sat { get { return _sat; } }

            /// <summary>
            /// Signal constellation, band and code
            /// </summary>
            public byte Code { get { return _code; } }
            public Gnss M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// A wire-appropriate receiver clock time, defined as the time since the
        /// beginning of the week on the Saturday/Sunday transition. In most cases,
        /// observations are epoch aligned so ns field will be 0.
        /// </summary>
        public partial class GpsTime : KaitaiStruct
        {
            public static GpsTime FromFile(string fileName)
            {
                return new GpsTime(new KaitaiStream(fileName));
            }

            public GpsTime(KaitaiStream p__io, KaitaiStruct p__parent = null, Gnss p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _nsResidual = m_io.ReadS4le();
                _wn = m_io.ReadU2le();
            }
            private uint _tow;
            private int _nsResidual;
            private ushort _wn;
            private Gnss m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// Milliseconds since start of GPS week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000
            /// to 500000)
            /// </summary>
            public int NsResidual { get { return _nsResidual; } }

            /// <summary>
            /// GPS week number
            /// </summary>
            public ushort Wn { get { return _wn; } }
            public Gnss M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// A GPS time, defined as the number of seconds since beginning of the week
        /// on the Saturday/Sunday transition.
        /// </summary>
        public partial class GpsTimeSec : KaitaiStruct
        {
            public static GpsTimeSec FromFile(string fileName)
            {
                return new GpsTimeSec(new KaitaiStream(fileName));
            }

            public GpsTimeSec(KaitaiStream p__io, KaitaiStruct p__parent = null, Gnss p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _wn = m_io.ReadU2le();
            }
            private uint _tow;
            private ushort _wn;
            private Gnss m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// Seconds since start of GPS week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// GPS week number
            /// </summary>
            public ushort Wn { get { return _wn; } }
            public Gnss M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// A (Constellation ID, satellite ID) tuple that uniquely identifies a
        /// space vehicle.
        /// </summary>
        public partial class SvId : KaitaiStruct
        {
            public static SvId FromFile(string fileName)
            {
                return new SvId(new KaitaiStream(fileName));
            }

            public SvId(KaitaiStream p__io, KaitaiStruct p__parent = null, Gnss p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _satId = m_io.ReadU1();
                _constellation = m_io.ReadU1();
            }
            private byte _satId;
            private byte _constellation;
            private Gnss m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// Constellation-specific satellite id. For GLO can either be (100+FCN)
            /// where FCN is in [-7,+6] or the Slot ID in [1,28].
            /// </summary>
            public byte SatId { get { return _satId; } }

            /// <summary>
            /// Constellation ID to which the SV belongs
            /// </summary>
            public byte Constellation { get { return _constellation; } }
            public Gnss M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }
        private Gnss m_root;
        private KaitaiStruct m_parent;
        public Gnss M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
