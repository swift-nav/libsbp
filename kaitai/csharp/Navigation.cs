// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class Navigation : KaitaiStruct
    {
        public static Navigation FromFile(string fileName)
        {
            return new Navigation(new KaitaiStream(fileName));
        }

        public Navigation(KaitaiStream p__io, KaitaiStruct p__parent = null, Navigation p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// This position solution message reports the absolute geodetic coordinates
        /// and the status (single point vs pseudo-absolute RTK) of the position
        /// solution. If the rover receiver knows the surveyed position of the base
        /// station and has an RTK solution, this reports a pseudo-absolute position
        /// solution using the base station position and the rover's RTK baseline
        /// vector. The full GPS time is given by the preceding MSG_GPS_TIME with
        /// the matching time-of-week (tow).
        /// </summary>
        public partial class MsgPosLlhDepA : KaitaiStruct
        {
            public static MsgPosLlhDepA FromFile(string fileName)
            {
                return new MsgPosLlhDepA(new KaitaiStream(fileName));
            }

            public MsgPosLlhDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _lat = m_io.ReadF8le();
                _lon = m_io.ReadF8le();
                _height = m_io.ReadF8le();
                _hAccuracy = m_io.ReadU2le();
                _vAccuracy = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private double _lat;
            private double _lon;
            private double _height;
            private ushort _hAccuracy;
            private ushort _vAccuracy;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

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

            /// <summary>
            /// Horizontal position accuracy estimate (not implemented). Defaults to
            /// 0.
            /// </summary>
            public ushort HAccuracy { get { return _hAccuracy; } }

            /// <summary>
            /// Vertical position accuracy estimate (not implemented). Defaults to
            /// 0.
            /// </summary>
            public ushort VAccuracy { get { return _vAccuracy; } }

            /// <summary>
            /// Number of satellites used in solution.
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the local vertical and horizontal protection levels
        /// associated with a given LLH position solution. The full GPS time is
        /// given by the preceding MSG_GPS_TIME with the matching time-of-week
        /// (tow).
        /// </summary>
        public partial class MsgProtectionLevelDepA : KaitaiStruct
        {
            public static MsgProtectionLevelDepA FromFile(string fileName)
            {
                return new MsgProtectionLevelDepA(new KaitaiStream(fileName));
            }

            public MsgProtectionLevelDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _vpl = m_io.ReadU2le();
                _hpl = m_io.ReadU2le();
                _lat = m_io.ReadF8le();
                _lon = m_io.ReadF8le();
                _height = m_io.ReadF8le();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private ushort _vpl;
            private ushort _hpl;
            private double _lat;
            private double _lon;
            private double _height;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Vertical protection level
            /// </summary>
            public ushort Vpl { get { return _vpl; } }

            /// <summary>
            /// Horizontal protection level
            /// </summary>
            public ushort Hpl { get { return _hpl; } }

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

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This position solution message reports the absolute geodetic coordinates
        /// and the status (single point vs pseudo-absolute RTK) of the position
        /// solution as well as the upper triangle of the 3x3 covariance matrix.
        /// The position information and Fix Mode flags follow the MSG_POS_LLH
        /// message.  Since the covariance matrix is computed in the local-level
        /// North, East, Down frame, the covariance terms follow that convention.
        /// Thus, covariances are reported against the &quot;downward&quot; measurement and
        /// care should be taken with the sign convention.
        /// </summary>
        public partial class MsgPosLlhCov : KaitaiStruct
        {
            public static MsgPosLlhCov FromFile(string fileName)
            {
                return new MsgPosLlhCov(new KaitaiStream(fileName));
            }

            public MsgPosLlhCov(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _lat = m_io.ReadF8le();
                _lon = m_io.ReadF8le();
                _height = m_io.ReadF8le();
                _covNN = m_io.ReadF4le();
                _covNE = m_io.ReadF4le();
                _covND = m_io.ReadF4le();
                _covEE = m_io.ReadF4le();
                _covED = m_io.ReadF4le();
                _covDD = m_io.ReadF4le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private double _lat;
            private double _lon;
            private double _height;
            private float _covNN;
            private float _covNE;
            private float _covND;
            private float _covEE;
            private float _covED;
            private float _covDD;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Latitude
            /// </summary>
            public double Lat { get { return _lat; } }

            /// <summary>
            /// Longitude
            /// </summary>
            public double Lon { get { return _lon; } }

            /// <summary>
            /// Height above WGS84 ellipsoid
            /// </summary>
            public double Height { get { return _height; } }

            /// <summary>
            /// Estimated variance of northing
            /// </summary>
            public float CovNN { get { return _covNN; } }

            /// <summary>
            /// Covariance of northing and easting
            /// </summary>
            public float CovNE { get { return _covNE; } }

            /// <summary>
            /// Covariance of northing and downward measurement
            /// </summary>
            public float CovND { get { return _covND; } }

            /// <summary>
            /// Estimated variance of easting
            /// </summary>
            public float CovEE { get { return _covEE; } }

            /// <summary>
            /// Covariance of easting and downward measurement
            /// </summary>
            public float CovED { get { return _covED; } }

            /// <summary>
            /// Estimated variance of downward measurement
            /// </summary>
            public float CovDD { get { return _covDD; } }

            /// <summary>
            /// Number of satellites used in solution.
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the velocity in local North East Down (NED)
        /// coordinates. The NED coordinate system is defined as the local WGS84
        /// tangent plane centered at the current position. The full GPS time is
        /// given by the preceding MSG_GPS_TIME with the matching time-of-week
        /// (tow).
        /// </summary>
        public partial class MsgVelNedDepA : KaitaiStruct
        {
            public static MsgVelNedDepA FromFile(string fileName)
            {
                return new MsgVelNedDepA(new KaitaiStream(fileName));
            }

            public MsgVelNedDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _n = m_io.ReadS4le();
                _e = m_io.ReadS4le();
                _d = m_io.ReadS4le();
                _hAccuracy = m_io.ReadU2le();
                _vAccuracy = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _n;
            private int _e;
            private int _d;
            private ushort _hAccuracy;
            private ushort _vAccuracy;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Velocity North coordinate
            /// </summary>
            public int N { get { return _n; } }

            /// <summary>
            /// Velocity East coordinate
            /// </summary>
            public int E { get { return _e; } }

            /// <summary>
            /// Velocity Down coordinate
            /// </summary>
            public int D { get { return _d; } }

            /// <summary>
            /// Horizontal velocity accuracy estimate (not implemented). Defaults to
            /// 0.
            /// </summary>
            public ushort HAccuracy { get { return _hAccuracy; } }

            /// <summary>
            /// Vertical velocity accuracy estimate (not implemented). Defaults to
            /// 0.
            /// </summary>
            public ushort VAccuracy { get { return _vAccuracy; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags (reserved)
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the velocity in local North East Down (NED)
        /// coordinates. The NED coordinate system is defined as the local WGS84
        /// tangent plane centered at the current position. The full GPS time is
        /// given by the preceding MSG_GPS_TIME with the matching time-of-week
        /// (tow). This message is similar to the MSG_VEL_NED, but it includes the
        /// upper triangular portion of the 3x3 covariance matrix.
        /// </summary>
        public partial class MsgVelNedCov : KaitaiStruct
        {
            public static MsgVelNedCov FromFile(string fileName)
            {
                return new MsgVelNedCov(new KaitaiStream(fileName));
            }

            public MsgVelNedCov(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _n = m_io.ReadS4le();
                _e = m_io.ReadS4le();
                _d = m_io.ReadS4le();
                _covNN = m_io.ReadF4le();
                _covNE = m_io.ReadF4le();
                _covND = m_io.ReadF4le();
                _covEE = m_io.ReadF4le();
                _covED = m_io.ReadF4le();
                _covDD = m_io.ReadF4le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _n;
            private int _e;
            private int _d;
            private float _covNN;
            private float _covNE;
            private float _covND;
            private float _covEE;
            private float _covED;
            private float _covDD;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Velocity North coordinate
            /// </summary>
            public int N { get { return _n; } }

            /// <summary>
            /// Velocity East coordinate
            /// </summary>
            public int E { get { return _e; } }

            /// <summary>
            /// Velocity Down coordinate
            /// </summary>
            public int D { get { return _d; } }

            /// <summary>
            /// Estimated variance of northward measurement
            /// </summary>
            public float CovNN { get { return _covNN; } }

            /// <summary>
            /// Covariance of northward and eastward measurement
            /// </summary>
            public float CovNE { get { return _covNE; } }

            /// <summary>
            /// Covariance of northward and downward measurement
            /// </summary>
            public float CovND { get { return _covND; } }

            /// <summary>
            /// Estimated variance of eastward measurement
            /// </summary>
            public float CovEE { get { return _covEE; } }

            /// <summary>
            /// Covariance of eastward and downward measurement
            /// </summary>
            public float CovED { get { return _covED; } }

            /// <summary>
            /// Estimated variance of downward measurement
            /// </summary>
            public float CovDD { get { return _covDD; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the Universal Coordinated Time (UTC).  Note the
        /// flags which indicate the source of the UTC offset value and source of
        /// the time fix.
        /// </summary>
        public partial class MsgUtcTime : KaitaiStruct
        {
            public static MsgUtcTime FromFile(string fileName)
            {
                return new MsgUtcTime(new KaitaiStream(fileName));
            }

            public MsgUtcTime(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _flags = m_io.ReadU1();
                _tow = m_io.ReadU4le();
                _year = m_io.ReadU2le();
                _month = m_io.ReadU1();
                _day = m_io.ReadU1();
                _hours = m_io.ReadU1();
                _minutes = m_io.ReadU1();
                _seconds = m_io.ReadU1();
                _ns = m_io.ReadU4le();
            }
            private byte _flags;
            private uint _tow;
            private ushort _year;
            private byte _month;
            private byte _day;
            private byte _hours;
            private byte _minutes;
            private byte _seconds;
            private uint _ns;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Indicates source and time validity
            /// </summary>
            public byte Flags { get { return _flags; } }

            /// <summary>
            /// GPS time of week rounded to the nearest millisecond
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Year
            /// </summary>
            public ushort Year { get { return _year; } }

            /// <summary>
            /// Month (range 1 .. 12)
            /// </summary>
            public byte Month { get { return _month; } }

            /// <summary>
            /// days in the month (range 1-31)
            /// </summary>
            public byte Day { get { return _day; } }

            /// <summary>
            /// hours of day (range 0-23)
            /// </summary>
            public byte Hours { get { return _hours; } }

            /// <summary>
            /// minutes of hour (range 0-59)
            /// </summary>
            public byte Minutes { get { return _minutes; } }

            /// <summary>
            /// seconds of minute (range 0-60) rounded down
            /// </summary>
            public byte Seconds { get { return _seconds; } }

            /// <summary>
            /// nanoseconds of second (range 0-999999999)
            /// </summary>
            public uint Ns { get { return _ns; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The position solution message reports absolute Earth Centered Earth
        /// Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
        /// RTK) of the position solution. The message also reports the upper
        /// triangular portion of the 3x3 covariance matrix. If the receiver knows
        /// the surveyed position of the base station and has an RTK solution, this
        /// reports a pseudo-absolute position solution using the base station
        /// position and the rover's RTK baseline vector. The full GPS time is given
        /// by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
        /// </summary>
        public partial class MsgPosEcefCovGnss : KaitaiStruct
        {
            public static MsgPosEcefCovGnss FromFile(string fileName)
            {
                return new MsgPosEcefCovGnss(new KaitaiStream(fileName));
            }

            public MsgPosEcefCovGnss(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _x = m_io.ReadF8le();
                _y = m_io.ReadF8le();
                _z = m_io.ReadF8le();
                _covXX = m_io.ReadF4le();
                _covXY = m_io.ReadF4le();
                _covXZ = m_io.ReadF4le();
                _covYY = m_io.ReadF4le();
                _covYZ = m_io.ReadF4le();
                _covZZ = m_io.ReadF4le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private double _x;
            private double _y;
            private double _z;
            private float _covXX;
            private float _covXY;
            private float _covXZ;
            private float _covYY;
            private float _covYZ;
            private float _covZZ;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

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

            /// <summary>
            /// Estimated variance of x
            /// </summary>
            public float CovXX { get { return _covXX; } }

            /// <summary>
            /// Estimated covariance of x and y
            /// </summary>
            public float CovXY { get { return _covXY; } }

            /// <summary>
            /// Estimated covariance of x and z
            /// </summary>
            public float CovXZ { get { return _covXZ; } }

            /// <summary>
            /// Estimated variance of y
            /// </summary>
            public float CovYY { get { return _covYY; } }

            /// <summary>
            /// Estimated covariance of y and z
            /// </summary>
            public float CovYZ { get { return _covYZ; } }

            /// <summary>
            /// Estimated variance of z
            /// </summary>
            public float CovZZ { get { return _covZZ; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the velocity in local North East Down (NED)
        /// coordinates. The NED coordinate system is defined as the local WGS84
        /// tangent plane centered at the current position. The full GPS time is
        /// given by the preceding MSG_GPS_TIME with the matching time-of-week
        /// (tow).
        /// </summary>
        public partial class MsgVelNedGnss : KaitaiStruct
        {
            public static MsgVelNedGnss FromFile(string fileName)
            {
                return new MsgVelNedGnss(new KaitaiStream(fileName));
            }

            public MsgVelNedGnss(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _n = m_io.ReadS4le();
                _e = m_io.ReadS4le();
                _d = m_io.ReadS4le();
                _hAccuracy = m_io.ReadU2le();
                _vAccuracy = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _n;
            private int _e;
            private int _d;
            private ushort _hAccuracy;
            private ushort _vAccuracy;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Velocity North coordinate
            /// </summary>
            public int N { get { return _n; } }

            /// <summary>
            /// Velocity East coordinate
            /// </summary>
            public int E { get { return _e; } }

            /// <summary>
            /// Velocity Down coordinate
            /// </summary>
            public int D { get { return _d; } }

            /// <summary>
            /// Horizontal velocity estimated standard deviation
            /// </summary>
            public ushort HAccuracy { get { return _hAccuracy; } }

            /// <summary>
            /// Vertical velocity estimated standard deviation
            /// </summary>
            public ushort VAccuracy { get { return _vAccuracy; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the velocity in local North East Down (NED)
        /// coordinates. The NED coordinate system is defined as the local WGS84
        /// tangent plane centered at the current position. The full GPS time is
        /// given by the preceding MSG_GPS_TIME with the matching time-of-week
        /// (tow). This message is similar to the MSG_VEL_NED, but it includes the
        /// upper triangular portion of the 3x3 covariance matrix.
        /// </summary>
        public partial class MsgVelNedCovGnss : KaitaiStruct
        {
            public static MsgVelNedCovGnss FromFile(string fileName)
            {
                return new MsgVelNedCovGnss(new KaitaiStream(fileName));
            }

            public MsgVelNedCovGnss(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _n = m_io.ReadS4le();
                _e = m_io.ReadS4le();
                _d = m_io.ReadS4le();
                _covNN = m_io.ReadF4le();
                _covNE = m_io.ReadF4le();
                _covND = m_io.ReadF4le();
                _covEE = m_io.ReadF4le();
                _covED = m_io.ReadF4le();
                _covDD = m_io.ReadF4le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _n;
            private int _e;
            private int _d;
            private float _covNN;
            private float _covNE;
            private float _covND;
            private float _covEE;
            private float _covED;
            private float _covDD;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Velocity North coordinate
            /// </summary>
            public int N { get { return _n; } }

            /// <summary>
            /// Velocity East coordinate
            /// </summary>
            public int E { get { return _e; } }

            /// <summary>
            /// Velocity Down coordinate
            /// </summary>
            public int D { get { return _d; } }

            /// <summary>
            /// Estimated variance of northward measurement
            /// </summary>
            public float CovNN { get { return _covNN; } }

            /// <summary>
            /// Covariance of northward and eastward measurement
            /// </summary>
            public float CovNE { get { return _covNE; } }

            /// <summary>
            /// Covariance of northward and downward measurement
            /// </summary>
            public float CovND { get { return _covND; } }

            /// <summary>
            /// Estimated variance of eastward measurement
            /// </summary>
            public float CovEE { get { return _covEE; } }

            /// <summary>
            /// Covariance of eastward and downward measurement
            /// </summary>
            public float CovED { get { return _covED; } }

            /// <summary>
            /// Estimated variance of downward measurement
            /// </summary>
            public float CovDD { get { return _covDD; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the baseline solution in North East Down (NED)
        /// coordinates. This baseline is the relative vector distance from the base
        /// station to the rover receiver, and NED coordinate system is defined at
        /// the local WGS84 tangent plane centered at the base station position.
        /// The full GPS time is given by the preceding MSG_GPS_TIME with the
        /// matching time-of-week (tow).
        /// </summary>
        public partial class MsgBaselineNedDepA : KaitaiStruct
        {
            public static MsgBaselineNedDepA FromFile(string fileName)
            {
                return new MsgBaselineNedDepA(new KaitaiStream(fileName));
            }

            public MsgBaselineNedDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _n = m_io.ReadS4le();
                _e = m_io.ReadS4le();
                _d = m_io.ReadS4le();
                _hAccuracy = m_io.ReadU2le();
                _vAccuracy = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _n;
            private int _e;
            private int _d;
            private ushort _hAccuracy;
            private ushort _vAccuracy;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Baseline North coordinate
            /// </summary>
            public int N { get { return _n; } }

            /// <summary>
            /// Baseline East coordinate
            /// </summary>
            public int E { get { return _e; } }

            /// <summary>
            /// Baseline Down coordinate
            /// </summary>
            public int D { get { return _d; } }

            /// <summary>
            /// Horizontal position accuracy estimate (not implemented). Defaults to
            /// 0.
            /// </summary>
            public ushort HAccuracy { get { return _hAccuracy; } }

            /// <summary>
            /// Vertical position accuracy estimate (not implemented). Defaults to
            /// 0.
            /// </summary>
            public ushort VAccuracy { get { return _vAccuracy; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
        /// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
        /// with the matching time-of-week (tow).
        /// </summary>
        public partial class MsgVelEcefDepA : KaitaiStruct
        {
            public static MsgVelEcefDepA FromFile(string fileName)
            {
                return new MsgVelEcefDepA(new KaitaiStream(fileName));
            }

            public MsgVelEcefDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _x = m_io.ReadS4le();
                _y = m_io.ReadS4le();
                _z = m_io.ReadS4le();
                _accuracy = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _x;
            private int _y;
            private int _z;
            private ushort _accuracy;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Velocity ECEF X coordinate
            /// </summary>
            public int X { get { return _x; } }

            /// <summary>
            /// Velocity ECEF Y coordinate
            /// </summary>
            public int Y { get { return _y; } }

            /// <summary>
            /// Velocity ECEF Z coordinate
            /// </summary>
            public int Z { get { return _z; } }

            /// <summary>
            /// Velocity accuracy estimate (not implemented). Defaults to 0.
            /// </summary>
            public ushort Accuracy { get { return _accuracy; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags (reserved)
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        public partial class MsgReferenceFrameParam : KaitaiStruct
        {
            public static MsgReferenceFrameParam FromFile(string fileName)
            {
                return new MsgReferenceFrameParam(new KaitaiStream(fileName));
            }

            public MsgReferenceFrameParam(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _ssrIod = m_io.ReadU1();
                _sn = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytes(32));
                _tn = System.Text.Encoding.GetEncoding("ascii").GetString(m_io.ReadBytes(32));
                _sin = m_io.ReadU1();
                _utn = m_io.ReadU2le();
                _reT0 = m_io.ReadU2le();
                _deltaX0 = m_io.ReadS4le();
                _deltaY0 = m_io.ReadS4le();
                _deltaZ0 = m_io.ReadS4le();
                _theta01 = m_io.ReadS4le();
                _theta02 = m_io.ReadS4le();
                _theta03 = m_io.ReadS4le();
                _scale = m_io.ReadS4le();
                _dotDeltaX0 = m_io.ReadS4le();
                _dotDeltaY0 = m_io.ReadS4le();
                _dotDeltaZ0 = m_io.ReadS4le();
                _dotTheta01 = m_io.ReadS4le();
                _dotTheta02 = m_io.ReadS4le();
                _dotTheta03 = m_io.ReadS4le();
                _dotScale = m_io.ReadS2le();
            }
            private byte _ssrIod;
            private string _sn;
            private string _tn;
            private byte _sin;
            private ushort _utn;
            private ushort _reT0;
            private int _deltaX0;
            private int _deltaY0;
            private int _deltaZ0;
            private int _theta01;
            private int _theta02;
            private int _theta03;
            private int _scale;
            private int _dotDeltaX0;
            private int _dotDeltaY0;
            private int _dotDeltaZ0;
            private int _dotTheta01;
            private int _dotTheta02;
            private int _dotTheta03;
            private short _dotScale;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// SSR IOD parameter.
            /// </summary>
            public byte SsrIod { get { return _ssrIod; } }

            /// <summary>
            /// Name of source coordinate-system.
            /// </summary>
            public string Sn { get { return _sn; } }

            /// <summary>
            /// Name of target coordinate-system.
            /// </summary>
            public string Tn { get { return _tn; } }

            /// <summary>
            /// System Identification Number.
            /// </summary>
            public byte Sin { get { return _sin; } }

            /// <summary>
            /// Utilized Transformation Message.
            /// </summary>
            public ushort Utn { get { return _utn; } }

            /// <summary>
            /// Reference Epoch t0 for transformation parameter set given as
            /// Modified Julian Day (MJD) Number minus 44244 days.
            /// </summary>
            public ushort ReT0 { get { return _reT0; } }

            /// <summary>
            /// Translation in X for Reference Epoch t0.
            /// </summary>
            public int DeltaX0 { get { return _deltaX0; } }

            /// <summary>
            /// Translation in Y for Reference Epoch t0.
            /// </summary>
            public int DeltaY0 { get { return _deltaY0; } }

            /// <summary>
            /// Translation in Z for Reference Epoch t0.
            /// </summary>
            public int DeltaZ0 { get { return _deltaZ0; } }

            /// <summary>
            /// Rotation around the X-axis for Reference Epoch t0.
            /// </summary>
            public int Theta01 { get { return _theta01; } }

            /// <summary>
            /// Rotation around the Y-axis for Reference Epoch t0.
            /// </summary>
            public int Theta02 { get { return _theta02; } }

            /// <summary>
            /// Rotation around the Z-axis for Reference Epoch t0.
            /// </summary>
            public int Theta03 { get { return _theta03; } }

            /// <summary>
            /// Scale correction for Reference Epoch t0.
            /// </summary>
            public int Scale { get { return _scale; } }

            /// <summary>
            /// Rate of change of translation in X.
            /// </summary>
            public int DotDeltaX0 { get { return _dotDeltaX0; } }

            /// <summary>
            /// Rate of change of translation in Y.
            /// </summary>
            public int DotDeltaY0 { get { return _dotDeltaY0; } }

            /// <summary>
            /// Rate of change of translation in Z.
            /// </summary>
            public int DotDeltaZ0 { get { return _dotDeltaZ0; } }

            /// <summary>
            /// Rate of change of rotation around the X-axis.
            /// </summary>
            public int DotTheta01 { get { return _dotTheta01; } }

            /// <summary>
            /// Rate of change of rotation around the Y-axis.
            /// </summary>
            public int DotTheta02 { get { return _dotTheta02; } }

            /// <summary>
            /// Rate of change of rotation around the Z-axis.
            /// </summary>
            public int DotTheta03 { get { return _dotTheta03; } }

            /// <summary>
            /// Rate of change of scale correction.
            /// </summary>
            public short DotScale { get { return _dotScale; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This solution message reports the relative pose of a sensor between two
        /// time instances. The relative pose comprises of a rotation and a
        /// translation which relates the sensor (e.g. camera) frame at a given time
        /// (first keyframe) to the sensor frame at another time (second keyframe).
        /// The relative translations is a 3x1 vector described in the first
        /// keyframe.  Relative rotation is described by a quaternion from second
        /// keyframe to the first keyframe.
        /// </summary>
        public partial class MsgPoseRelative : KaitaiStruct
        {
            public static MsgPoseRelative FromFile(string fileName)
            {
                return new MsgPoseRelative(new KaitaiStream(fileName));
            }

            public MsgPoseRelative(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _sensorId = m_io.ReadU1();
                _timestamp1 = m_io.ReadU4le();
                _timestamp2 = m_io.ReadU4le();
                _trans = new List<int>();
                for (var i = 0; i < 3; i++)
                {
                    _trans.Add(m_io.ReadS4le());
                }
                _w = m_io.ReadS4le();
                _x = m_io.ReadS4le();
                _y = m_io.ReadS4le();
                _z = m_io.ReadS4le();
                _covRXX = m_io.ReadF4le();
                _covRXY = m_io.ReadF4le();
                _covRXZ = m_io.ReadF4le();
                _covRYY = m_io.ReadF4le();
                _covRYZ = m_io.ReadF4le();
                _covRZZ = m_io.ReadF4le();
                _covCXX = m_io.ReadF4le();
                _covCXY = m_io.ReadF4le();
                _covCXZ = m_io.ReadF4le();
                _covCYY = m_io.ReadF4le();
                _covCYZ = m_io.ReadF4le();
                _covCZZ = m_io.ReadF4le();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private byte _sensorId;
            private uint _timestamp1;
            private uint _timestamp2;
            private List<int> _trans;
            private int _w;
            private int _x;
            private int _y;
            private int _z;
            private float _covRXX;
            private float _covRXY;
            private float _covRXZ;
            private float _covRYY;
            private float _covRYZ;
            private float _covRZZ;
            private float _covCXX;
            private float _covCXY;
            private float _covCXZ;
            private float _covCYY;
            private float _covCYZ;
            private float _covCZZ;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// ID of the sensor producing this message
            /// </summary>
            public byte SensorId { get { return _sensorId; } }

            /// <summary>
            /// Timestamp of first keyframe
            /// </summary>
            public uint Timestamp1 { get { return _timestamp1; } }

            /// <summary>
            /// Timestamp of second keyframe
            /// </summary>
            public uint Timestamp2 { get { return _timestamp2; } }

            /// <summary>
            /// Relative translation [x,y,z] described in first keyframe
            /// </summary>
            public List<int> Trans { get { return _trans; } }

            /// <summary>
            /// Real component of quaternion to describe relative rotation (second
            /// to first keyframe)
            /// </summary>
            public int W { get { return _w; } }

            /// <summary>
            /// 1st imaginary component of quaternion to describe relative rotation
            /// (second to first keyframe)
            /// </summary>
            public int X { get { return _x; } }

            /// <summary>
            /// 2nd imaginary component of quaternion to describe relative rotation
            /// (second to first keyframe)
            /// </summary>
            public int Y { get { return _y; } }

            /// <summary>
            /// 3rd imaginary component of quaternion to describe relative rotation
            /// (second to first keyframe)
            /// </summary>
            public int Z { get { return _z; } }

            /// <summary>
            /// Estimated variance of x (relative translation)
            /// </summary>
            public float CovRXX { get { return _covRXX; } }

            /// <summary>
            /// Covariance of x and y (relative translation)
            /// </summary>
            public float CovRXY { get { return _covRXY; } }

            /// <summary>
            /// Covariance of x and z (relative translation)
            /// </summary>
            public float CovRXZ { get { return _covRXZ; } }

            /// <summary>
            /// Estimated variance of y (relative translation)
            /// </summary>
            public float CovRYY { get { return _covRYY; } }

            /// <summary>
            /// Covariance of y and z (relative translation)
            /// </summary>
            public float CovRYZ { get { return _covRYZ; } }

            /// <summary>
            /// Estimated variance of z (relative translation)
            /// </summary>
            public float CovRZZ { get { return _covRZZ; } }

            /// <summary>
            /// Estimated variance of x (relative rotation)
            /// </summary>
            public float CovCXX { get { return _covCXX; } }

            /// <summary>
            /// Covariance of x and y (relative rotation)
            /// </summary>
            public float CovCXY { get { return _covCXY; } }

            /// <summary>
            /// Covariance of x and z (relative rotation)
            /// </summary>
            public float CovCXZ { get { return _covCXZ; } }

            /// <summary>
            /// Estimated variance of y (relative rotation)
            /// </summary>
            public float CovCYY { get { return _covCYY; } }

            /// <summary>
            /// Covariance of y and z (relative rotation)
            /// </summary>
            public float CovCYZ { get { return _covCYZ; } }

            /// <summary>
            /// Estimated variance of z (relative rotation)
            /// </summary>
            public float CovCZZ { get { return _covCZZ; } }

            /// <summary>
            /// Status flags of relative translation and rotation
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
        /// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
        /// with the matching time-of-week (tow).
        /// </summary>
        public partial class MsgVelEcefCov : KaitaiStruct
        {
            public static MsgVelEcefCov FromFile(string fileName)
            {
                return new MsgVelEcefCov(new KaitaiStream(fileName));
            }

            public MsgVelEcefCov(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _x = m_io.ReadS4le();
                _y = m_io.ReadS4le();
                _z = m_io.ReadS4le();
                _covXX = m_io.ReadF4le();
                _covXY = m_io.ReadF4le();
                _covXZ = m_io.ReadF4le();
                _covYY = m_io.ReadF4le();
                _covYZ = m_io.ReadF4le();
                _covZZ = m_io.ReadF4le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _x;
            private int _y;
            private int _z;
            private float _covXX;
            private float _covXY;
            private float _covXZ;
            private float _covYY;
            private float _covYZ;
            private float _covZZ;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Velocity ECEF X coordinate
            /// </summary>
            public int X { get { return _x; } }

            /// <summary>
            /// Velocity ECEF Y coordinate
            /// </summary>
            public int Y { get { return _y; } }

            /// <summary>
            /// Velocity ECEF Z coordinate
            /// </summary>
            public int Z { get { return _z; } }

            /// <summary>
            /// Estimated variance of x
            /// </summary>
            public float CovXX { get { return _covXX; } }

            /// <summary>
            /// Estimated covariance of x and y
            /// </summary>
            public float CovXY { get { return _covXY; } }

            /// <summary>
            /// Estimated covariance of x and z
            /// </summary>
            public float CovXZ { get { return _covXZ; } }

            /// <summary>
            /// Estimated variance of y
            /// </summary>
            public float CovYY { get { return _covYY; } }

            /// <summary>
            /// Estimated covariance of y and z
            /// </summary>
            public float CovYZ { get { return _covYZ; } }

            /// <summary>
            /// Estimated variance of z
            /// </summary>
            public float CovZZ { get { return _covZZ; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the velocity in the Vehicle Body Frame. By
        /// convention, the x-axis should point out the nose of the vehicle and
        /// represent the forward direction, while as the y-axis should point out
        /// the right hand side of the vehicle. Since this is a right handed system,
        /// z should point out the bottom of the vehicle. The orientation and origin
        /// of the Vehicle Body Frame are specified via the device settings. The
        /// full GPS time is given by the preceding MSG_GPS_TIME with the matching
        /// time-of-week (tow). This message is only produced by inertial versions
        /// of Swift products and is not available from Piksi Multi or Duro.
        /// </summary>
        public partial class MsgVelBody : KaitaiStruct
        {
            public static MsgVelBody FromFile(string fileName)
            {
                return new MsgVelBody(new KaitaiStream(fileName));
            }

            public MsgVelBody(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _x = m_io.ReadS4le();
                _y = m_io.ReadS4le();
                _z = m_io.ReadS4le();
                _covXX = m_io.ReadF4le();
                _covXY = m_io.ReadF4le();
                _covXZ = m_io.ReadF4le();
                _covYY = m_io.ReadF4le();
                _covYZ = m_io.ReadF4le();
                _covZZ = m_io.ReadF4le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _x;
            private int _y;
            private int _z;
            private float _covXX;
            private float _covXY;
            private float _covXZ;
            private float _covYY;
            private float _covYZ;
            private float _covZZ;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Velocity in x direction
            /// </summary>
            public int X { get { return _x; } }

            /// <summary>
            /// Velocity in y direction
            /// </summary>
            public int Y { get { return _y; } }

            /// <summary>
            /// Velocity in z direction
            /// </summary>
            public int Z { get { return _z; } }

            /// <summary>
            /// Estimated variance of x
            /// </summary>
            public float CovXX { get { return _covXX; } }

            /// <summary>
            /// Covariance of x and y
            /// </summary>
            public float CovXY { get { return _covXY; } }

            /// <summary>
            /// Covariance of x and z
            /// </summary>
            public float CovXZ { get { return _covXZ; } }

            /// <summary>
            /// Estimated variance of y
            /// </summary>
            public float CovYY { get { return _covYY; } }

            /// <summary>
            /// Covariance of y and z
            /// </summary>
            public float CovYZ { get { return _covYZ; } }

            /// <summary>
            /// Estimated variance of z
            /// </summary>
            public float CovZZ { get { return _covZZ; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
        /// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
        /// with the matching time-of-week (tow).
        /// </summary>
        public partial class MsgVelEcefGnss : KaitaiStruct
        {
            public static MsgVelEcefGnss FromFile(string fileName)
            {
                return new MsgVelEcefGnss(new KaitaiStream(fileName));
            }

            public MsgVelEcefGnss(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _x = m_io.ReadS4le();
                _y = m_io.ReadS4le();
                _z = m_io.ReadS4le();
                _accuracy = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _x;
            private int _y;
            private int _z;
            private ushort _accuracy;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Velocity ECEF X coordinate
            /// </summary>
            public int X { get { return _x; } }

            /// <summary>
            /// Velocity ECEF Y coordinate
            /// </summary>
            public int Y { get { return _y; } }

            /// <summary>
            /// Velocity ECEF Z coordinate
            /// </summary>
            public int Z { get { return _z; } }

            /// <summary>
            /// Velocity estimated standard deviation
            /// </summary>
            public ushort Accuracy { get { return _accuracy; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
        /// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
        /// with the matching time-of-week (tow).
        /// </summary>
        public partial class MsgVelEcef : KaitaiStruct
        {
            public static MsgVelEcef FromFile(string fileName)
            {
                return new MsgVelEcef(new KaitaiStream(fileName));
            }

            public MsgVelEcef(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _x = m_io.ReadS4le();
                _y = m_io.ReadS4le();
                _z = m_io.ReadS4le();
                _accuracy = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _x;
            private int _y;
            private int _z;
            private ushort _accuracy;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Velocity ECEF X coordinate
            /// </summary>
            public int X { get { return _x; } }

            /// <summary>
            /// Velocity ECEF Y coordinate
            /// </summary>
            public int Y { get { return _y; } }

            /// <summary>
            /// Velocity ECEF Z coordinate
            /// </summary>
            public int Z { get { return _z; } }

            /// <summary>
            /// Velocity estimated standard deviation
            /// </summary>
            public ushort Accuracy { get { return _accuracy; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This position solution message reports the absolute geodetic coordinates
        /// and the status (single point vs pseudo-absolute RTK) of the position
        /// solution as well as the upper triangle of the 3x3 covariance matrix.
        /// The position information and Fix Mode flags should follow the
        /// MSG_POS_LLH message.  Since the covariance matrix is computed in the
        /// local-level North, East, Down frame, the covariance terms follow with
        /// that convention. Thus, covariances are reported against the &quot;downward&quot;
        /// measurement and care should be taken with the sign convention.
        /// </summary>
        public partial class MsgPosLlhCovGnss : KaitaiStruct
        {
            public static MsgPosLlhCovGnss FromFile(string fileName)
            {
                return new MsgPosLlhCovGnss(new KaitaiStream(fileName));
            }

            public MsgPosLlhCovGnss(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _lat = m_io.ReadF8le();
                _lon = m_io.ReadF8le();
                _height = m_io.ReadF8le();
                _covNN = m_io.ReadF4le();
                _covNE = m_io.ReadF4le();
                _covND = m_io.ReadF4le();
                _covEE = m_io.ReadF4le();
                _covED = m_io.ReadF4le();
                _covDD = m_io.ReadF4le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private double _lat;
            private double _lon;
            private double _height;
            private float _covNN;
            private float _covNE;
            private float _covND;
            private float _covEE;
            private float _covED;
            private float _covDD;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Latitude
            /// </summary>
            public double Lat { get { return _lat; } }

            /// <summary>
            /// Longitude
            /// </summary>
            public double Lon { get { return _lon; } }

            /// <summary>
            /// Height above WGS84 ellipsoid
            /// </summary>
            public double Height { get { return _height; } }

            /// <summary>
            /// Estimated variance of northing
            /// </summary>
            public float CovNN { get { return _covNN; } }

            /// <summary>
            /// Covariance of northing and easting
            /// </summary>
            public float CovNE { get { return _covNE; } }

            /// <summary>
            /// Covariance of northing and downward measurement
            /// </summary>
            public float CovND { get { return _covND; } }

            /// <summary>
            /// Estimated variance of easting
            /// </summary>
            public float CovEE { get { return _covEE; } }

            /// <summary>
            /// Covariance of easting and downward measurement
            /// </summary>
            public float CovED { get { return _covED; } }

            /// <summary>
            /// Estimated variance of downward measurement
            /// </summary>
            public float CovDD { get { return _covDD; } }

            /// <summary>
            /// Number of satellites used in solution.
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the baseline solution in Earth Centered Earth Fixed
        /// (ECEF) coordinates. This baseline is the relative vector distance from
        /// the base station to the rover receiver. The full GPS time is given by
        /// the preceding MSG_GPS_TIME with the matching time-of-week (tow).
        /// </summary>
        public partial class MsgBaselineEcef : KaitaiStruct
        {
            public static MsgBaselineEcef FromFile(string fileName)
            {
                return new MsgBaselineEcef(new KaitaiStream(fileName));
            }

            public MsgBaselineEcef(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _x = m_io.ReadS4le();
                _y = m_io.ReadS4le();
                _z = m_io.ReadS4le();
                _accuracy = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _x;
            private int _y;
            private int _z;
            private ushort _accuracy;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Baseline ECEF X coordinate
            /// </summary>
            public int X { get { return _x; } }

            /// <summary>
            /// Baseline ECEF Y coordinate
            /// </summary>
            public int Y { get { return _y; } }

            /// <summary>
            /// Baseline ECEF Z coordinate
            /// </summary>
            public int Z { get { return _z; } }

            /// <summary>
            /// Position estimated standard deviation
            /// </summary>
            public ushort Accuracy { get { return _accuracy; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This dilution of precision (DOP) message describes the effect of
        /// navigation satellite geometry on positional measurement precision.
        /// </summary>
        public partial class MsgDopsDepA : KaitaiStruct
        {
            public static MsgDopsDepA FromFile(string fileName)
            {
                return new MsgDopsDepA(new KaitaiStream(fileName));
            }

            public MsgDopsDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _gdop = m_io.ReadU2le();
                _pdop = m_io.ReadU2le();
                _tdop = m_io.ReadU2le();
                _hdop = m_io.ReadU2le();
                _vdop = m_io.ReadU2le();
            }
            private uint _tow;
            private ushort _gdop;
            private ushort _pdop;
            private ushort _tdop;
            private ushort _hdop;
            private ushort _vdop;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Geometric Dilution of Precision
            /// </summary>
            public ushort Gdop { get { return _gdop; } }

            /// <summary>
            /// Position Dilution of Precision
            /// </summary>
            public ushort Pdop { get { return _pdop; } }

            /// <summary>
            /// Time Dilution of Precision
            /// </summary>
            public ushort Tdop { get { return _tdop; } }

            /// <summary>
            /// Horizontal Dilution of Precision
            /// </summary>
            public ushort Hdop { get { return _hdop; } }

            /// <summary>
            /// Vertical Dilution of Precision
            /// </summary>
            public ushort Vdop { get { return _vdop; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The position solution message reports absolute Earth Centered Earth
        /// Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
        /// RTK) of the position solution. If the rover receiver knows the surveyed
        /// position of the base station and has an RTK solution, this reports a
        /// pseudo-absolute position solution using the base station position and
        /// the rover's RTK baseline vector. The full GPS time is given by the
        /// preceding MSG_GPS_TIME with the matching time-of-week (tow).
        /// </summary>
        public partial class MsgPosEcef : KaitaiStruct
        {
            public static MsgPosEcef FromFile(string fileName)
            {
                return new MsgPosEcef(new KaitaiStream(fileName));
            }

            public MsgPosEcef(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _x = m_io.ReadF8le();
                _y = m_io.ReadF8le();
                _z = m_io.ReadF8le();
                _accuracy = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private double _x;
            private double _y;
            private double _z;
            private ushort _accuracy;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

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

            /// <summary>
            /// Position estimated standard deviation
            /// </summary>
            public ushort Accuracy { get { return _accuracy; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the Age of the corrections used for the current
        /// Differential solution.
        /// </summary>
        public partial class MsgAgeCorrections : KaitaiStruct
        {
            public static MsgAgeCorrections FromFile(string fileName)
            {
                return new MsgAgeCorrections(new KaitaiStream(fileName));
            }

            public MsgAgeCorrections(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _age = m_io.ReadU2le();
            }
            private uint _tow;
            private ushort _age;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Age of the corrections (0xFFFF indicates invalid)
            /// </summary>
            public ushort Age { get { return _age; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the velocity in Earth Centered Earth Fixed (ECEF)
        /// coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
        /// with the matching time-of-week (tow).
        /// </summary>
        public partial class MsgVelEcefCovGnss : KaitaiStruct
        {
            public static MsgVelEcefCovGnss FromFile(string fileName)
            {
                return new MsgVelEcefCovGnss(new KaitaiStream(fileName));
            }

            public MsgVelEcefCovGnss(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _x = m_io.ReadS4le();
                _y = m_io.ReadS4le();
                _z = m_io.ReadS4le();
                _covXX = m_io.ReadF4le();
                _covXY = m_io.ReadF4le();
                _covXZ = m_io.ReadF4le();
                _covYY = m_io.ReadF4le();
                _covYZ = m_io.ReadF4le();
                _covZZ = m_io.ReadF4le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _x;
            private int _y;
            private int _z;
            private float _covXX;
            private float _covXY;
            private float _covXZ;
            private float _covYY;
            private float _covYZ;
            private float _covZZ;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Velocity ECEF X coordinate
            /// </summary>
            public int X { get { return _x; } }

            /// <summary>
            /// Velocity ECEF Y coordinate
            /// </summary>
            public int Y { get { return _y; } }

            /// <summary>
            /// Velocity ECEF Z coordinate
            /// </summary>
            public int Z { get { return _z; } }

            /// <summary>
            /// Estimated variance of x
            /// </summary>
            public float CovXX { get { return _covXX; } }

            /// <summary>
            /// Estimated covariance of x and y
            /// </summary>
            public float CovXY { get { return _covXY; } }

            /// <summary>
            /// Estimated covariance of x and z
            /// </summary>
            public float CovXZ { get { return _covXZ; } }

            /// <summary>
            /// Estimated variance of y
            /// </summary>
            public float CovYY { get { return _covYY; } }

            /// <summary>
            /// Estimated covariance of y and z
            /// </summary>
            public float CovYZ { get { return _covYZ; } }

            /// <summary>
            /// Estimated variance of z
            /// </summary>
            public float CovZZ { get { return _covZZ; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the protection levels associated to the given state
        /// estimate. The full GPS time is given by the preceding MSG_GPS_TIME with
        /// the matching time-of-week (tow).
        /// </summary>
        public partial class MsgProtectionLevel : KaitaiStruct
        {
            public static MsgProtectionLevel FromFile(string fileName)
            {
                return new MsgProtectionLevel(new KaitaiStream(fileName));
            }

            public MsgProtectionLevel(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _wn = m_io.ReadS2le();
                _hpl = m_io.ReadU2le();
                _vpl = m_io.ReadU2le();
                _atpl = m_io.ReadU2le();
                _ctpl = m_io.ReadU2le();
                _hvpl = m_io.ReadU2le();
                _vvpl = m_io.ReadU2le();
                _hopl = m_io.ReadU2le();
                _popl = m_io.ReadU2le();
                _ropl = m_io.ReadU2le();
                _lat = m_io.ReadF8le();
                _lon = m_io.ReadF8le();
                _height = m_io.ReadF8le();
                _vX = m_io.ReadS4le();
                _vY = m_io.ReadS4le();
                _vZ = m_io.ReadS4le();
                _roll = m_io.ReadS4le();
                _pitch = m_io.ReadS4le();
                _heading = m_io.ReadS4le();
                _flags = m_io.ReadU4le();
            }
            private uint _tow;
            private short _wn;
            private ushort _hpl;
            private ushort _vpl;
            private ushort _atpl;
            private ushort _ctpl;
            private ushort _hvpl;
            private ushort _vvpl;
            private ushort _hopl;
            private ushort _popl;
            private ushort _ropl;
            private double _lat;
            private double _lon;
            private double _height;
            private int _vX;
            private int _vY;
            private int _vZ;
            private int _roll;
            private int _pitch;
            private int _heading;
            private uint _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// GPS week number
            /// </summary>
            public short Wn { get { return _wn; } }

            /// <summary>
            /// Horizontal protection level
            /// </summary>
            public ushort Hpl { get { return _hpl; } }

            /// <summary>
            /// Vertical protection level
            /// </summary>
            public ushort Vpl { get { return _vpl; } }

            /// <summary>
            /// Along-track position error protection level
            /// </summary>
            public ushort Atpl { get { return _atpl; } }

            /// <summary>
            /// Cross-track position error protection level
            /// </summary>
            public ushort Ctpl { get { return _ctpl; } }

            /// <summary>
            /// Protection level for the error vector between estimated and true
            /// along/cross track velocity vector
            /// </summary>
            public ushort Hvpl { get { return _hvpl; } }

            /// <summary>
            /// Protection level for the velocity in vehicle upright direction
            /// (different from vertical direction if on a slope)
            /// </summary>
            public ushort Vvpl { get { return _vvpl; } }

            /// <summary>
            /// Heading orientation protection level
            /// </summary>
            public ushort Hopl { get { return _hopl; } }

            /// <summary>
            /// Pitch orientation protection level
            /// </summary>
            public ushort Popl { get { return _popl; } }

            /// <summary>
            /// Roll orientation protection level
            /// </summary>
            public ushort Ropl { get { return _ropl; } }

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

            /// <summary>
            /// Velocity in vehicle x direction
            /// </summary>
            public int VX { get { return _vX; } }

            /// <summary>
            /// Velocity in vehicle y direction
            /// </summary>
            public int VY { get { return _vY; } }

            /// <summary>
            /// Velocity in vehicle z direction
            /// </summary>
            public int VZ { get { return _vZ; } }

            /// <summary>
            /// Roll angle
            /// </summary>
            public int Roll { get { return _roll; } }

            /// <summary>
            /// Pitch angle
            /// </summary>
            public int Pitch { get { return _pitch; } }

            /// <summary>
            /// Heading angle
            /// </summary>
            public int Heading { get { return _heading; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public uint Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The position solution message reports absolute Earth Centered Earth
        /// Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
        /// RTK) of the position solution. The message also reports the upper
        /// triangular portion of the 3x3 covariance matrix. If the receiver knows
        /// the surveyed position of the base station and has an RTK solution, this
        /// reports a pseudo-absolute position solution using the base station
        /// position and the rover's RTK baseline vector. The full GPS time is given
        /// by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
        /// </summary>
        public partial class MsgPosEcefCov : KaitaiStruct
        {
            public static MsgPosEcefCov FromFile(string fileName)
            {
                return new MsgPosEcefCov(new KaitaiStream(fileName));
            }

            public MsgPosEcefCov(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _x = m_io.ReadF8le();
                _y = m_io.ReadF8le();
                _z = m_io.ReadF8le();
                _covXX = m_io.ReadF4le();
                _covXY = m_io.ReadF4le();
                _covXZ = m_io.ReadF4le();
                _covYY = m_io.ReadF4le();
                _covYZ = m_io.ReadF4le();
                _covZZ = m_io.ReadF4le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private double _x;
            private double _y;
            private double _z;
            private float _covXX;
            private float _covXY;
            private float _covXZ;
            private float _covYY;
            private float _covYZ;
            private float _covZZ;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

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

            /// <summary>
            /// Estimated variance of x
            /// </summary>
            public float CovXX { get { return _covXX; } }

            /// <summary>
            /// Estimated covariance of x and y
            /// </summary>
            public float CovXY { get { return _covXY; } }

            /// <summary>
            /// Estimated covariance of x and z
            /// </summary>
            public float CovXZ { get { return _covXZ; } }

            /// <summary>
            /// Estimated variance of y
            /// </summary>
            public float CovYY { get { return _covYY; } }

            /// <summary>
            /// Estimated covariance of y and z
            /// </summary>
            public float CovYZ { get { return _covYZ; } }

            /// <summary>
            /// Estimated variance of z
            /// </summary>
            public float CovZZ { get { return _covZZ; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The position solution message reports absolute Earth Centered Earth
        /// Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
        /// RTK) of the position solution. If the rover receiver knows the surveyed
        /// position of the base station and has an RTK solution, this reports a
        /// pseudo-absolute position solution using the base station position and
        /// the rover's RTK baseline vector. The full GPS time is given by the
        /// preceding MSG_GPS_TIME with the matching time-of-week (tow).
        /// </summary>
        public partial class MsgPosEcefGnss : KaitaiStruct
        {
            public static MsgPosEcefGnss FromFile(string fileName)
            {
                return new MsgPosEcefGnss(new KaitaiStream(fileName));
            }

            public MsgPosEcefGnss(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _x = m_io.ReadF8le();
                _y = m_io.ReadF8le();
                _z = m_io.ReadF8le();
                _accuracy = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private double _x;
            private double _y;
            private double _z;
            private ushort _accuracy;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

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

            /// <summary>
            /// Position estimated standard deviation
            /// </summary>
            public ushort Accuracy { get { return _accuracy; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the velocity in local North East Down (NED)
        /// coordinates. The NED coordinate system is defined as the local WGS84
        /// tangent plane centered at the current position. The full GPS time is
        /// given by the preceding MSG_GPS_TIME with the matching time-of-week
        /// (tow).
        /// </summary>
        public partial class MsgVelNed : KaitaiStruct
        {
            public static MsgVelNed FromFile(string fileName)
            {
                return new MsgVelNed(new KaitaiStream(fileName));
            }

            public MsgVelNed(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _n = m_io.ReadS4le();
                _e = m_io.ReadS4le();
                _d = m_io.ReadS4le();
                _hAccuracy = m_io.ReadU2le();
                _vAccuracy = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _n;
            private int _e;
            private int _d;
            private ushort _hAccuracy;
            private ushort _vAccuracy;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Velocity North coordinate
            /// </summary>
            public int N { get { return _n; } }

            /// <summary>
            /// Velocity East coordinate
            /// </summary>
            public int E { get { return _e; } }

            /// <summary>
            /// Velocity Down coordinate
            /// </summary>
            public int D { get { return _d; } }

            /// <summary>
            /// Horizontal velocity estimated standard deviation
            /// </summary>
            public ushort HAccuracy { get { return _hAccuracy; } }

            /// <summary>
            /// Vertical velocity estimated standard deviation
            /// </summary>
            public ushort VAccuracy { get { return _vAccuracy; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// UTC-GPST leap seconds before and after the most recent (past, or future,
        /// for announced insertions) UTC leap second insertion.
        /// </summary>
        public partial class MsgUtcLeapSecond : KaitaiStruct
        {
            public static MsgUtcLeapSecond FromFile(string fileName)
            {
                return new MsgUtcLeapSecond(new KaitaiStream(fileName));
            }

            public MsgUtcLeapSecond(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _reserved0 = m_io.ReadS2le();
                _reserved1 = m_io.ReadS2le();
                _reserved2 = m_io.ReadS1();
                _countBefore = m_io.ReadS1();
                _reserved3 = m_io.ReadU2le();
                _reserved4 = m_io.ReadU2le();
                _refWn = m_io.ReadU2le();
                _refDn = m_io.ReadU1();
                _countAfter = m_io.ReadS1();
            }
            private short _reserved0;
            private short _reserved1;
            private sbyte _reserved2;
            private sbyte _countBefore;
            private ushort _reserved3;
            private ushort _reserved4;
            private ushort _refWn;
            private byte _refDn;
            private sbyte _countAfter;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Reserved.
            /// </summary>
            public short Reserved0 { get { return _reserved0; } }

            /// <summary>
            /// Reserved.
            /// </summary>
            public short Reserved1 { get { return _reserved1; } }

            /// <summary>
            /// Reserved.
            /// </summary>
            public sbyte Reserved2 { get { return _reserved2; } }

            /// <summary>
            /// Leap second count before insertion.
            /// </summary>
            public sbyte CountBefore { get { return _countBefore; } }

            /// <summary>
            /// Reserved.
            /// </summary>
            public ushort Reserved3 { get { return _reserved3; } }

            /// <summary>
            /// Reserved.
            /// </summary>
            public ushort Reserved4 { get { return _reserved4; } }

            /// <summary>
            /// Leap second reference GPS week number.
            /// </summary>
            public ushort RefWn { get { return _refWn; } }

            /// <summary>
            /// Leap second reference day number.
            /// </summary>
            public byte RefDn { get { return _refDn; } }

            /// <summary>
            /// Leap second count after insertion.
            /// </summary>
            public sbyte CountAfter { get { return _countAfter; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the GPS time, representing the time since the GPS
        /// epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
        /// and seconds of the week. The weeks begin at the Saturday/Sunday
        /// transition. GPS week 0 began at the beginning of the GPS time scale.
        /// 
        /// Within each week number, the GPS time of the week is between between 0
        /// and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
        /// leap seconds, and as of now, has a small offset from UTC. In a message
        /// stream, this message precedes a set of other navigation messages
        /// referenced to the same time (but lacking the ns field) and indicates a
        /// more precise time of these messages.
        /// </summary>
        public partial class MsgGpsTimeDepA : KaitaiStruct
        {
            public static MsgGpsTimeDepA FromFile(string fileName)
            {
                return new MsgGpsTimeDepA(new KaitaiStream(fileName));
            }

            public MsgGpsTimeDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _wn = m_io.ReadU2le();
                _tow = m_io.ReadU4le();
                _nsResidual = m_io.ReadS4le();
                _flags = m_io.ReadU1();
            }
            private ushort _wn;
            private uint _tow;
            private int _nsResidual;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS week number
            /// </summary>
            public ushort Wn { get { return _wn; } }

            /// <summary>
            /// GPS time of week rounded to the nearest millisecond
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000
            /// to 500000)
            /// </summary>
            public int NsResidual { get { return _nsResidual; } }

            /// <summary>
            /// Status flags (reserved)
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This position solution message reports the absolute geodetic coordinates
        /// and the status (single point vs pseudo-absolute RTK) of the position
        /// solution. If the rover receiver knows the surveyed position of the base
        /// station and has an RTK solution, this reports a pseudo-absolute position
        /// solution using the base station position and the rover's RTK baseline
        /// vector. The full GPS time is given by the preceding MSG_GPS_TIME with
        /// the matching time-of-week (tow).
        /// </summary>
        public partial class MsgPosLlhGnss : KaitaiStruct
        {
            public static MsgPosLlhGnss FromFile(string fileName)
            {
                return new MsgPosLlhGnss(new KaitaiStream(fileName));
            }

            public MsgPosLlhGnss(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _lat = m_io.ReadF8le();
                _lon = m_io.ReadF8le();
                _height = m_io.ReadF8le();
                _hAccuracy = m_io.ReadU2le();
                _vAccuracy = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private double _lat;
            private double _lon;
            private double _height;
            private ushort _hAccuracy;
            private ushort _vAccuracy;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Latitude
            /// </summary>
            public double Lat { get { return _lat; } }

            /// <summary>
            /// Longitude
            /// </summary>
            public double Lon { get { return _lon; } }

            /// <summary>
            /// Height above WGS84 ellipsoid
            /// </summary>
            public double Height { get { return _height; } }

            /// <summary>
            /// Horizontal position estimated standard deviation
            /// </summary>
            public ushort HAccuracy { get { return _hAccuracy; } }

            /// <summary>
            /// Vertical position estimated standard deviation
            /// </summary>
            public ushort VAccuracy { get { return _vAccuracy; } }

            /// <summary>
            /// Number of satellites used in solution.
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the Universal Coordinated Time (UTC).  Note the
        /// flags which indicate the source of the UTC offset value and source of
        /// the time fix.
        /// </summary>
        public partial class MsgUtcTimeGnss : KaitaiStruct
        {
            public static MsgUtcTimeGnss FromFile(string fileName)
            {
                return new MsgUtcTimeGnss(new KaitaiStream(fileName));
            }

            public MsgUtcTimeGnss(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _flags = m_io.ReadU1();
                _tow = m_io.ReadU4le();
                _year = m_io.ReadU2le();
                _month = m_io.ReadU1();
                _day = m_io.ReadU1();
                _hours = m_io.ReadU1();
                _minutes = m_io.ReadU1();
                _seconds = m_io.ReadU1();
                _ns = m_io.ReadU4le();
            }
            private byte _flags;
            private uint _tow;
            private ushort _year;
            private byte _month;
            private byte _day;
            private byte _hours;
            private byte _minutes;
            private byte _seconds;
            private uint _ns;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Indicates source and time validity
            /// </summary>
            public byte Flags { get { return _flags; } }

            /// <summary>
            /// GPS time of week rounded to the nearest millisecond
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Year
            /// </summary>
            public ushort Year { get { return _year; } }

            /// <summary>
            /// Month (range 1 .. 12)
            /// </summary>
            public byte Month { get { return _month; } }

            /// <summary>
            /// days in the month (range 1-31)
            /// </summary>
            public byte Day { get { return _day; } }

            /// <summary>
            /// hours of day (range 0-23)
            /// </summary>
            public byte Hours { get { return _hours; } }

            /// <summary>
            /// minutes of hour (range 0-59)
            /// </summary>
            public byte Minutes { get { return _minutes; } }

            /// <summary>
            /// seconds of minute (range 0-60) rounded down
            /// </summary>
            public byte Seconds { get { return _seconds; } }

            /// <summary>
            /// nanoseconds of second (range 0-999999999)
            /// </summary>
            public uint Ns { get { return _ns; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the receiver course over ground (COG) and speed
        /// over  ground (SOG) based on the horizontal (N-E) components of the NED
        /// velocity  vector. It also includes the vertical velocity coordinate. A
        /// flag is provided to indicate whether the COG value has been frozen. When
        /// the flag is set to true, the COG field is set to its last valid value
        /// until  the system exceeds a minimum velocity threshold. No other fields
        /// are  affected by this flag.  The NED coordinate system is defined as the
        /// local WGS84 tangent  plane centered at the current position. The full
        /// GPS time is given by the  preceding MSG_GPS_TIME with the matching time-
        /// of-week (tow). Note: course over ground represents the receiver's
        /// direction of travel,  but not necessarily the device heading.
        /// </summary>
        public partial class MsgVelCog : KaitaiStruct
        {
            public static MsgVelCog FromFile(string fileName)
            {
                return new MsgVelCog(new KaitaiStream(fileName));
            }

            public MsgVelCog(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _cog = m_io.ReadU4le();
                _sog = m_io.ReadU4le();
                _vUp = m_io.ReadS4le();
                _cogAccuracy = m_io.ReadU4le();
                _sogAccuracy = m_io.ReadU4le();
                _vUpAccuracy = m_io.ReadU4le();
                _flags = m_io.ReadU2le();
            }
            private uint _tow;
            private uint _cog;
            private uint _sog;
            private int _vUp;
            private uint _cogAccuracy;
            private uint _sogAccuracy;
            private uint _vUpAccuracy;
            private ushort _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Course over ground relative to north direction
            /// </summary>
            public uint Cog { get { return _cog; } }

            /// <summary>
            /// Speed over ground (based on horizontal velocity)
            /// </summary>
            public uint Sog { get { return _sog; } }

            /// <summary>
            /// Vertical velocity component (positive up)
            /// </summary>
            public int VUp { get { return _vUp; } }

            /// <summary>
            /// Course over ground estimated standard deviation
            /// </summary>
            public uint CogAccuracy { get { return _cogAccuracy; } }

            /// <summary>
            /// Speed over ground estimated standard deviation
            /// </summary>
            public uint SogAccuracy { get { return _sogAccuracy; } }

            /// <summary>
            /// Vertical velocity estimated standard deviation
            /// </summary>
            public uint VUpAccuracy { get { return _vUpAccuracy; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public ushort Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the baseline solution in North East Down (NED)
        /// coordinates. This baseline is the relative vector distance from the base
        /// station to the rover receiver, and NED coordinate system is defined at
        /// the local WGS84 tangent plane centered at the base station position.
        /// The full GPS time is given by the preceding MSG_GPS_TIME with the
        /// matching time-of-week (tow).
        /// </summary>
        public partial class MsgBaselineNed : KaitaiStruct
        {
            public static MsgBaselineNed FromFile(string fileName)
            {
                return new MsgBaselineNed(new KaitaiStream(fileName));
            }

            public MsgBaselineNed(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _n = m_io.ReadS4le();
                _e = m_io.ReadS4le();
                _d = m_io.ReadS4le();
                _hAccuracy = m_io.ReadU2le();
                _vAccuracy = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _n;
            private int _e;
            private int _d;
            private ushort _hAccuracy;
            private ushort _vAccuracy;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Baseline North coordinate
            /// </summary>
            public int N { get { return _n; } }

            /// <summary>
            /// Baseline East coordinate
            /// </summary>
            public int E { get { return _e; } }

            /// <summary>
            /// Baseline Down coordinate
            /// </summary>
            public int D { get { return _d; } }

            /// <summary>
            /// Horizontal position estimated standard deviation
            /// </summary>
            public ushort HAccuracy { get { return _hAccuracy; } }

            /// <summary>
            /// Vertical position estimated standard deviation
            /// </summary>
            public ushort VAccuracy { get { return _vAccuracy; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This position solution message reports the absolute geodetic coordinates
        /// and the status (single point vs pseudo-absolute RTK) of the position
        /// solution. If the rover receiver knows the surveyed position of the base
        /// station and has an RTK solution, this reports a pseudo-absolute position
        /// solution using the base station position and the rover's RTK baseline
        /// vector. The full GPS time is given by the preceding MSG_GPS_TIME with
        /// the matching time-of-week (tow).
        /// </summary>
        public partial class MsgPosLlh : KaitaiStruct
        {
            public static MsgPosLlh FromFile(string fileName)
            {
                return new MsgPosLlh(new KaitaiStream(fileName));
            }

            public MsgPosLlh(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _lat = m_io.ReadF8le();
                _lon = m_io.ReadF8le();
                _height = m_io.ReadF8le();
                _hAccuracy = m_io.ReadU2le();
                _vAccuracy = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private double _lat;
            private double _lon;
            private double _height;
            private ushort _hAccuracy;
            private ushort _vAccuracy;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Latitude
            /// </summary>
            public double Lat { get { return _lat; } }

            /// <summary>
            /// Longitude
            /// </summary>
            public double Lon { get { return _lon; } }

            /// <summary>
            /// Height above WGS84 ellipsoid
            /// </summary>
            public double Height { get { return _height; } }

            /// <summary>
            /// Horizontal position estimated standard deviation
            /// </summary>
            public ushort HAccuracy { get { return _hAccuracy; } }

            /// <summary>
            /// Vertical position estimated standard deviation
            /// </summary>
            public ushort VAccuracy { get { return _vAccuracy; } }

            /// <summary>
            /// Number of satellites used in solution.
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the baseline heading pointing from the base station
        /// to the rover relative to True North. The full GPS time is given by the
        /// preceding MSG_GPS_TIME with the matching time-of-week (tow).
        /// </summary>
        public partial class MsgBaselineHeadingDepA : KaitaiStruct
        {
            public static MsgBaselineHeadingDepA FromFile(string fileName)
            {
                return new MsgBaselineHeadingDepA(new KaitaiStream(fileName));
            }

            public MsgBaselineHeadingDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _heading = m_io.ReadU4le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private uint _heading;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Heading
            /// </summary>
            public uint Heading { get { return _heading; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the GPS time, representing the time since the GPS
        /// epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
        /// and seconds of the week. The weeks begin at the Saturday/Sunday
        /// transition. GPS week 0 began at the beginning of the GPS time scale.
        /// 
        /// Within each week number, the GPS time of the week is between between 0
        /// and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
        /// leap seconds, and as of now, has a small offset from UTC. In a message
        /// stream, this message precedes a set of other navigation messages
        /// referenced to the same time (but lacking the ns field) and indicates a
        /// more precise time of these messages.
        /// </summary>
        public partial class MsgGpsTimeGnss : KaitaiStruct
        {
            public static MsgGpsTimeGnss FromFile(string fileName)
            {
                return new MsgGpsTimeGnss(new KaitaiStream(fileName));
            }

            public MsgGpsTimeGnss(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _wn = m_io.ReadU2le();
                _tow = m_io.ReadU4le();
                _nsResidual = m_io.ReadS4le();
                _flags = m_io.ReadU1();
            }
            private ushort _wn;
            private uint _tow;
            private int _nsResidual;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS week number
            /// </summary>
            public ushort Wn { get { return _wn; } }

            /// <summary>
            /// GPS time of week rounded to the nearest millisecond
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000
            /// to 500000)
            /// </summary>
            public int NsResidual { get { return _nsResidual; } }

            /// <summary>
            /// Status flags (reserved)
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the baseline solution in Earth Centered Earth Fixed
        /// (ECEF) coordinates. This baseline is the relative vector distance from
        /// the base station to the rover receiver. The full GPS time is given by
        /// the preceding MSG_GPS_TIME with the matching time-of-week (tow).
        /// </summary>
        public partial class MsgBaselineEcefDepA : KaitaiStruct
        {
            public static MsgBaselineEcefDepA FromFile(string fileName)
            {
                return new MsgBaselineEcefDepA(new KaitaiStream(fileName));
            }

            public MsgBaselineEcefDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _x = m_io.ReadS4le();
                _y = m_io.ReadS4le();
                _z = m_io.ReadS4le();
                _accuracy = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _x;
            private int _y;
            private int _z;
            private ushort _accuracy;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Baseline ECEF X coordinate
            /// </summary>
            public int X { get { return _x; } }

            /// <summary>
            /// Baseline ECEF Y coordinate
            /// </summary>
            public int Y { get { return _y; } }

            /// <summary>
            /// Baseline ECEF Z coordinate
            /// </summary>
            public int Z { get { return _z; } }

            /// <summary>
            /// Position accuracy estimate
            /// </summary>
            public ushort Accuracy { get { return _accuracy; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the GPS time, representing the time since the GPS
        /// epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
        /// and seconds of the week. The weeks begin at the Saturday/Sunday
        /// transition. GPS week 0 began at the beginning of the GPS time scale.
        /// 
        /// Within each week number, the GPS time of the week is between between 0
        /// and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
        /// leap seconds, and as of now, has a small offset from UTC. In a message
        /// stream, this message precedes a set of other navigation messages
        /// referenced to the same time (but lacking the ns field) and indicates a
        /// more precise time of these messages.
        /// </summary>
        public partial class MsgGpsTime : KaitaiStruct
        {
            public static MsgGpsTime FromFile(string fileName)
            {
                return new MsgGpsTime(new KaitaiStream(fileName));
            }

            public MsgGpsTime(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _wn = m_io.ReadU2le();
                _tow = m_io.ReadU4le();
                _nsResidual = m_io.ReadS4le();
                _flags = m_io.ReadU1();
            }
            private ushort _wn;
            private uint _tow;
            private int _nsResidual;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS week number
            /// </summary>
            public ushort Wn { get { return _wn; } }

            /// <summary>
            /// GPS time of week rounded to the nearest millisecond
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Nanosecond residual of millisecond-rounded TOW (ranges from -500000
            /// to 500000)
            /// </summary>
            public int NsResidual { get { return _nsResidual; } }

            /// <summary>
            /// Status flags (reserved)
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This dilution of precision (DOP) message describes the effect of
        /// navigation satellite geometry on positional measurement precision.  The
        /// flags field indicated whether the DOP reported corresponds to
        /// differential or SPP solution.
        /// </summary>
        public partial class MsgDops : KaitaiStruct
        {
            public static MsgDops FromFile(string fileName)
            {
                return new MsgDops(new KaitaiStream(fileName));
            }

            public MsgDops(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _gdop = m_io.ReadU2le();
                _pdop = m_io.ReadU2le();
                _tdop = m_io.ReadU2le();
                _hdop = m_io.ReadU2le();
                _vdop = m_io.ReadU2le();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private ushort _gdop;
            private ushort _pdop;
            private ushort _tdop;
            private ushort _hdop;
            private ushort _vdop;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Geometric Dilution of Precision
            /// </summary>
            public ushort Gdop { get { return _gdop; } }

            /// <summary>
            /// Position Dilution of Precision
            /// </summary>
            public ushort Pdop { get { return _pdop; } }

            /// <summary>
            /// Time Dilution of Precision
            /// </summary>
            public ushort Tdop { get { return _tdop; } }

            /// <summary>
            /// Horizontal Dilution of Precision
            /// </summary>
            public ushort Hdop { get { return _hdop; } }

            /// <summary>
            /// Vertical Dilution of Precision
            /// </summary>
            public ushort Vdop { get { return _vdop; } }

            /// <summary>
            /// Indicates the position solution with which the DOPS message
            /// corresponds
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The position solution message reports absolute Earth Centered Earth
        /// Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
        /// RTK) of the position solution. If the rover receiver knows the surveyed
        /// position of the base station and has an RTK solution, this reports a
        /// pseudo-absolute position solution using the base station position and
        /// the rover's RTK baseline vector. The full GPS time is given by the
        /// preceding MSG_GPS_TIME with the matching time-of-week (tow).
        /// </summary>
        public partial class MsgPosEcefDepA : KaitaiStruct
        {
            public static MsgPosEcefDepA FromFile(string fileName)
            {
                return new MsgPosEcefDepA(new KaitaiStream(fileName));
            }

            public MsgPosEcefDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _x = m_io.ReadF8le();
                _y = m_io.ReadF8le();
                _z = m_io.ReadF8le();
                _accuracy = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private double _x;
            private double _y;
            private double _z;
            private ushort _accuracy;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

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

            /// <summary>
            /// Position accuracy estimate (not implemented). Defaults to 0.
            /// </summary>
            public ushort Accuracy { get { return _accuracy; } }

            /// <summary>
            /// Number of satellites used in solution
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        public partial class EstimatedHorizontalErrorEllipse : KaitaiStruct
        {
            public static EstimatedHorizontalErrorEllipse FromFile(string fileName)
            {
                return new EstimatedHorizontalErrorEllipse(new KaitaiStream(fileName));
            }

            public EstimatedHorizontalErrorEllipse(KaitaiStream p__io, Navigation.MsgPosLlhAcc p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _semiMajor = m_io.ReadF4le();
                _semiMinor = m_io.ReadF4le();
                _orientation = m_io.ReadF4le();
            }
            private float _semiMajor;
            private float _semiMinor;
            private float _orientation;
            private Navigation m_root;
            private Navigation.MsgPosLlhAcc m_parent;

            /// <summary>
            /// The semi major axis of the estimated horizontal error ellipse at the
            /// user-configured confidence level; zero implies invalid.
            /// </summary>
            public float SemiMajor { get { return _semiMajor; } }

            /// <summary>
            /// The semi minor axis of the estimated horizontal error ellipse at the
            /// user-configured confidence level; zero implies invalid.
            /// </summary>
            public float SemiMinor { get { return _semiMinor; } }

            /// <summary>
            /// The orientation of the semi major axis of the estimated horizontal
            /// error ellipse with respect to North.
            /// </summary>
            public float Orientation { get { return _orientation; } }
            public Navigation M_Root { get { return m_root; } }
            public Navigation.MsgPosLlhAcc M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This position solution message reports the absolute geodetic coordinates
        /// and the status (single point vs pseudo-absolute RTK) of the position
        /// solution as well as the estimated horizontal, vertical, cross-track and
        /// along-track errors.  The position information and Fix Mode flags  follow
        /// the MSG_POS_LLH message. Since the covariance matrix is computed in the
        /// local-level North, East, Down frame, the estimated error terms follow
        /// that convention.
        /// 
        /// The estimated errors are reported at a user-configurable confidence
        /// level. The user-configured percentile is encoded in the percentile
        /// field.
        /// </summary>
        public partial class MsgPosLlhAcc : KaitaiStruct
        {
            public static MsgPosLlhAcc FromFile(string fileName)
            {
                return new MsgPosLlhAcc(new KaitaiStream(fileName));
            }

            public MsgPosLlhAcc(KaitaiStream p__io, Sbp.Message p__parent = null, Navigation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _lat = m_io.ReadF8le();
                _lon = m_io.ReadF8le();
                _height = m_io.ReadF8le();
                _orthometricHeight = m_io.ReadF8le();
                _hAccuracy = m_io.ReadF4le();
                _vAccuracy = m_io.ReadF4le();
                _ctAccuracy = m_io.ReadF4le();
                _atAccuracy = m_io.ReadF4le();
                _hEllipse = new EstimatedHorizontalErrorEllipse(m_io, this, m_root);
                _confidenceAndGeoid = m_io.ReadU1();
                _nSats = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private double _lat;
            private double _lon;
            private double _height;
            private double _orthometricHeight;
            private float _hAccuracy;
            private float _vAccuracy;
            private float _ctAccuracy;
            private float _atAccuracy;
            private EstimatedHorizontalErrorEllipse _hEllipse;
            private byte _confidenceAndGeoid;
            private byte _nSats;
            private byte _flags;
            private Navigation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Latitude
            /// </summary>
            public double Lat { get { return _lat; } }

            /// <summary>
            /// Longitude
            /// </summary>
            public double Lon { get { return _lon; } }

            /// <summary>
            /// Height above WGS84 ellipsoid
            /// </summary>
            public double Height { get { return _height; } }

            /// <summary>
            /// Height above the geoid (i.e. height above mean sea level). See
            /// confidence_and_geoid for geoid model used.
            /// </summary>
            public double OrthometricHeight { get { return _orthometricHeight; } }

            /// <summary>
            /// Estimated horizontal error at the user-configured confidence level;
            /// zero implies invalid.
            /// </summary>
            public float HAccuracy { get { return _hAccuracy; } }

            /// <summary>
            /// Estimated vertical error at the user-configured confidence level;
            /// zero implies invalid.
            /// </summary>
            public float VAccuracy { get { return _vAccuracy; } }

            /// <summary>
            /// Estimated cross-track error at the user-configured confidence level;
            /// zero implies invalid.
            /// </summary>
            public float CtAccuracy { get { return _ctAccuracy; } }

            /// <summary>
            /// Estimated along-track error at the user-configured confidence level;
            /// zero implies invalid.
            /// </summary>
            public float AtAccuracy { get { return _atAccuracy; } }

            /// <summary>
            /// The estimated horizontal error ellipse at the user-configured
            /// confidence level.
            /// </summary>
            public EstimatedHorizontalErrorEllipse HEllipse { get { return _hEllipse; } }

            /// <summary>
            /// The lower bits describe the configured confidence level for the
            /// estimated position error. The middle bits describe the geoid model
            /// used to calculate the orthometric height.
            /// </summary>
            public byte ConfidenceAndGeoid { get { return _confidenceAndGeoid; } }

            /// <summary>
            /// Number of satellites used in solution.
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Navigation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        private Navigation m_root;
        private KaitaiStruct m_parent;
        public Navigation M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
