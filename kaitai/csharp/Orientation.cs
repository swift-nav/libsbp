// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild



namespace Kaitai
{
    public partial class Orientation : KaitaiStruct
    {
        public static Orientation FromFile(string fileName)
        {
            return new Orientation(new KaitaiStream(fileName));
        }

        public Orientation(KaitaiStream p__io, KaitaiStruct p__parent = null, Orientation p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// This message reports the baseline heading pointing from the base station
        /// to the rover relative to True North. The full GPS time is given by the
        /// preceding MSG_GPS_TIME with the matching time-of-week (tow). It is
        /// intended that time-matched RTK mode is used when the base station is
        /// moving.
        /// </summary>
        public partial class MsgBaselineHeading : KaitaiStruct
        {
            public static MsgBaselineHeading FromFile(string fileName)
            {
                return new MsgBaselineHeading(new KaitaiStream(fileName));
            }

            public MsgBaselineHeading(KaitaiStream p__io, Sbp.Message p__parent = null, Orientation p__root = null) : base(p__io)
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
            private Orientation m_root;
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
            public Orientation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the quaternion vector describing the vehicle body
        /// frame's orientation with respect to a local-level NED frame. The
        /// components of the vector should sum to a unit vector assuming that the
        /// LSB of each component as a value of 2^-31. This message will only be
        /// available in future INS versions of Swift Products and is not produced
        /// by Piksi Multi or Duro.
        /// </summary>
        public partial class MsgOrientQuat : KaitaiStruct
        {
            public static MsgOrientQuat FromFile(string fileName)
            {
                return new MsgOrientQuat(new KaitaiStream(fileName));
            }

            public MsgOrientQuat(KaitaiStream p__io, Sbp.Message p__parent = null, Orientation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _w = m_io.ReadS4le();
                _x = m_io.ReadS4le();
                _y = m_io.ReadS4le();
                _z = m_io.ReadS4le();
                _wAccuracy = m_io.ReadF4le();
                _xAccuracy = m_io.ReadF4le();
                _yAccuracy = m_io.ReadF4le();
                _zAccuracy = m_io.ReadF4le();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _w;
            private int _x;
            private int _y;
            private int _z;
            private float _wAccuracy;
            private float _xAccuracy;
            private float _yAccuracy;
            private float _zAccuracy;
            private byte _flags;
            private Orientation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Real component
            /// </summary>
            public int W { get { return _w; } }

            /// <summary>
            /// 1st imaginary component
            /// </summary>
            public int X { get { return _x; } }

            /// <summary>
            /// 2nd imaginary component
            /// </summary>
            public int Y { get { return _y; } }

            /// <summary>
            /// 3rd imaginary component
            /// </summary>
            public int Z { get { return _z; } }

            /// <summary>
            /// Estimated standard deviation of w
            /// </summary>
            public float WAccuracy { get { return _wAccuracy; } }

            /// <summary>
            /// Estimated standard deviation of x
            /// </summary>
            public float XAccuracy { get { return _xAccuracy; } }

            /// <summary>
            /// Estimated standard deviation of y
            /// </summary>
            public float YAccuracy { get { return _yAccuracy; } }

            /// <summary>
            /// Estimated standard deviation of z
            /// </summary>
            public float ZAccuracy { get { return _zAccuracy; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Orientation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the yaw, pitch, and roll angles of the vehicle body
        /// frame. The rotations should applied intrinsically in the order yaw,
        /// pitch, and roll in order to rotate the from a frame aligned with the
        /// local-level NED frame to the vehicle body frame.  This message will only
        /// be available in future INS versions of Swift Products and is not
        /// produced by Piksi Multi or Duro.
        /// </summary>
        public partial class MsgOrientEuler : KaitaiStruct
        {
            public static MsgOrientEuler FromFile(string fileName)
            {
                return new MsgOrientEuler(new KaitaiStream(fileName));
            }

            public MsgOrientEuler(KaitaiStream p__io, Sbp.Message p__parent = null, Orientation p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _roll = m_io.ReadS4le();
                _pitch = m_io.ReadS4le();
                _yaw = m_io.ReadS4le();
                _rollAccuracy = m_io.ReadF4le();
                _pitchAccuracy = m_io.ReadF4le();
                _yawAccuracy = m_io.ReadF4le();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _roll;
            private int _pitch;
            private int _yaw;
            private float _rollAccuracy;
            private float _pitchAccuracy;
            private float _yawAccuracy;
            private byte _flags;
            private Orientation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// rotation about the forward axis of the vehicle
            /// </summary>
            public int Roll { get { return _roll; } }

            /// <summary>
            /// rotation about the rightward axis of the vehicle
            /// </summary>
            public int Pitch { get { return _pitch; } }

            /// <summary>
            /// rotation about the downward axis of the vehicle
            /// </summary>
            public int Yaw { get { return _yaw; } }

            /// <summary>
            /// Estimated standard deviation of roll
            /// </summary>
            public float RollAccuracy { get { return _rollAccuracy; } }

            /// <summary>
            /// Estimated standard deviation of pitch
            /// </summary>
            public float PitchAccuracy { get { return _pitchAccuracy; } }

            /// <summary>
            /// Estimated standard deviation of yaw
            /// </summary>
            public float YawAccuracy { get { return _yawAccuracy; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Orientation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message reports the orientation rates in the vehicle body frame.
        /// The values represent the measurements a strapped down gyroscope would
        /// make and are not equivalent to the time derivative of the Euler angles.
        /// The orientation and origin of the user frame is specified via device
        /// settings. By convention, the vehicle x-axis is expected to be aligned
        /// with the forward direction, while the vehicle y-axis is expected to be
        /// aligned with the right direction, and the vehicle z-axis should be
        /// aligned with the down direction. This message will only be available in
        /// future INS versions of Swift Products and is not produced by Piksi Multi
        /// or Duro.
        /// </summary>
        public partial class MsgAngularRate : KaitaiStruct
        {
            public static MsgAngularRate FromFile(string fileName)
            {
                return new MsgAngularRate(new KaitaiStream(fileName));
            }

            public MsgAngularRate(KaitaiStream p__io, Sbp.Message p__parent = null, Orientation p__root = null) : base(p__io)
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
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _x;
            private int _y;
            private int _z;
            private byte _flags;
            private Orientation m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS Time of Week
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// angular rate about x axis
            /// </summary>
            public int X { get { return _x; } }

            /// <summary>
            /// angular rate about y axis
            /// </summary>
            public int Y { get { return _y; } }

            /// <summary>
            /// angular rate about z axis
            /// </summary>
            public int Z { get { return _z; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Orientation M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        private Orientation m_root;
        private KaitaiStruct m_parent;
        public Orientation M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
