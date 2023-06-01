// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild



namespace Kaitai
{
    public partial class Vehicle : KaitaiStruct
    {
        public static Vehicle FromFile(string fileName)
        {
            return new Vehicle(new KaitaiStream(fileName));
        }

        public Vehicle(KaitaiStream p__io, KaitaiStruct p__parent = null, Vehicle p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// Message representing the x component of vehicle velocity in the user
        /// frame at the odometry reference point(s) specified by the user. The
        /// offset for the odometry reference point and the definition and origin of
        /// the user frame are defined through the device settings interface. There
        /// are 4 possible user-defined sources of this message which are labeled
        /// arbitrarily source 0 through 3. If using &quot;processor time&quot; time tags, the
        /// receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix
        /// becomes available to synchronise odometry measurements with GNSS.
        /// Processor time shall roll over to zero after one week.
        /// </summary>
        public partial class MsgOdometry : KaitaiStruct
        {
            public static MsgOdometry FromFile(string fileName)
            {
                return new MsgOdometry(new KaitaiStream(fileName));
            }

            public MsgOdometry(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Vehicle p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _velocity = m_io.ReadS4le();
                _flags = m_io.ReadU1();
            }
            private uint _tow;
            private int _velocity;
            private byte _flags;
            private Vehicle m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Time field representing either milliseconds in the GPS Week or local
            /// CPU time from the producing system in milliseconds.  See the
            /// tow_source flag for the exact source of this timestamp.
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// The signed forward component of vehicle velocity.
            /// </summary>
            public int Velocity { get { return _velocity; } }

            /// <summary>
            /// Status flags
            /// </summary>
            public byte Flags { get { return _flags; } }
            public Vehicle M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Message containing the accumulated distance travelled by a wheel located
        /// at an odometry reference point defined by the user. The offset for the
        /// odometry reference point and the definition and origin of the user frame
        /// are defined through the device settings interface. The source of this
        /// message is identified by the source field, which is an integer ranging
        /// from 0 to 255. The timestamp associated with this message should
        /// represent the time when the accumulated tick count reached the value
        /// given by the contents of this message as accurately as possible. If
        /// using &quot;local CPU time&quot; time tags, the receiving end will expect a
        /// `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to synchronise
        /// wheeltick measurements with GNSS. Local CPU time shall roll over to zero
        /// after one week.
        /// </summary>
        public partial class MsgWheeltick : KaitaiStruct
        {
            public static MsgWheeltick FromFile(string fileName)
            {
                return new MsgWheeltick(new KaitaiStream(fileName));
            }

            public MsgWheeltick(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Vehicle p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _time = m_io.ReadU8le();
                _flags = m_io.ReadU1();
                _source = m_io.ReadU1();
                _ticks = m_io.ReadS4le();
            }
            private ulong _time;
            private byte _flags;
            private byte _source;
            private int _ticks;
            private Vehicle m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// Time field representing either microseconds since the last PPS,
            /// microseconds in the GPS Week or local CPU time from the producing
            /// system in microseconds. See the synch_type field for the exact
            /// meaning of this timestamp.
            /// </summary>
            public ulong Time { get { return _time; } }

            /// <summary>
            /// Field indicating the type of timestamp contained in the time field.
            /// </summary>
            public byte Flags { get { return _flags; } }

            /// <summary>
            /// ID of the sensor producing this message
            /// </summary>
            public byte Source { get { return _source; } }

            /// <summary>
            /// Free-running counter of the accumulated distance for this sensor.
            /// The counter should be incrementing if travelling into one direction
            /// and decrementing when travelling in the opposite direction.
            /// </summary>
            public int Ticks { get { return _ticks; } }
            public Vehicle M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }
        private Vehicle m_root;
        private KaitaiStruct m_parent;
        public Vehicle M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
