// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild



namespace Kaitai
{
    public partial class Imu : KaitaiStruct
    {
        public static Imu FromFile(string fileName)
        {
            return new Imu(new KaitaiStream(fileName));
        }

        public Imu(KaitaiStream p__io, KaitaiStruct p__parent = null, Imu p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// Raw data from the Inertial Measurement Unit, containing accelerometer
        /// and gyroscope readings. The sense of the measurements are to be aligned
        /// with the indications on the device itself. Measurement units, which are
        /// specific to the device hardware and settings, are communicated via the
        /// MSG_IMU_AUX message. If using &quot;time since startup&quot; time tags, the
        /// receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix
        /// becomes available to synchronise IMU measurements with GNSS. The
        /// timestamp must wrap around to zero when reaching one week (604800
        /// seconds).
        /// 
        /// The time-tagging mode should not change throughout a run.
        /// </summary>
        public partial class MsgImuRaw : KaitaiStruct
        {
            public static MsgImuRaw FromFile(string fileName)
            {
                return new MsgImuRaw(new KaitaiStream(fileName));
            }

            public MsgImuRaw(KaitaiStream p__io, Sbp.Message p__parent = null, Imu p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _towF = m_io.ReadU1();
                _accX = m_io.ReadS2le();
                _accY = m_io.ReadS2le();
                _accZ = m_io.ReadS2le();
                _gyrX = m_io.ReadS2le();
                _gyrY = m_io.ReadS2le();
                _gyrZ = m_io.ReadS2le();
            }
            private uint _tow;
            private byte _towF;
            private short _accX;
            private short _accY;
            private short _accZ;
            private short _gyrX;
            private short _gyrY;
            private short _gyrZ;
            private Imu m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Milliseconds since reference epoch and time status.
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Milliseconds since reference epoch, fractional part
            /// </summary>
            public byte TowF { get { return _towF; } }

            /// <summary>
            /// Acceleration in the IMU frame X axis
            /// </summary>
            public short AccX { get { return _accX; } }

            /// <summary>
            /// Acceleration in the IMU frame Y axis
            /// </summary>
            public short AccY { get { return _accY; } }

            /// <summary>
            /// Acceleration in the IMU frame Z axis
            /// </summary>
            public short AccZ { get { return _accZ; } }

            /// <summary>
            /// Angular rate around IMU frame X axis
            /// </summary>
            public short GyrX { get { return _gyrX; } }

            /// <summary>
            /// Angular rate around IMU frame Y axis
            /// </summary>
            public short GyrY { get { return _gyrY; } }

            /// <summary>
            /// Angular rate around IMU frame Z axis
            /// </summary>
            public short GyrZ { get { return _gyrZ; } }
            public Imu M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Auxiliary data specific to a particular IMU. The `imu_type` field will
        /// always be consistent but the rest of the payload is device specific and
        /// depends on the value of `imu_type`.
        /// </summary>
        public partial class MsgImuAux : KaitaiStruct
        {
            public static MsgImuAux FromFile(string fileName)
            {
                return new MsgImuAux(new KaitaiStream(fileName));
            }

            public MsgImuAux(KaitaiStream p__io, Sbp.Message p__parent = null, Imu p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _imuType = m_io.ReadU1();
                _temp = m_io.ReadS2le();
                _imuConf = m_io.ReadU1();
            }
            private byte _imuType;
            private short _temp;
            private byte _imuConf;
            private Imu m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// IMU type
            /// </summary>
            public byte ImuType { get { return _imuType; } }

            /// <summary>
            /// Raw IMU temperature
            /// </summary>
            public short Temp { get { return _temp; } }

            /// <summary>
            /// IMU configuration
            /// </summary>
            public byte ImuConf { get { return _imuConf; } }
            public Imu M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        private Imu m_root;
        private KaitaiStruct m_parent;
        public Imu M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
