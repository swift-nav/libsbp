// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class SolutionMeta : KaitaiStruct
    {
        public static SolutionMeta FromFile(string fileName)
        {
            return new SolutionMeta(new KaitaiStream(fileName));
        }

        public SolutionMeta(KaitaiStream p__io, KaitaiStruct p__parent = null, SolutionMeta p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }

        /// <summary>
        /// Metadata around the GNSS sensors involved in the fuzed solution.
        /// Accessible through sol_in[N].flags in a MSG_SOLN_META.
        /// </summary>
        public partial class GnssInputType : KaitaiStruct
        {
            public static GnssInputType FromFile(string fileName)
            {
                return new GnssInputType(new KaitaiStream(fileName));
            }

            public GnssInputType(KaitaiStream p__io, KaitaiStruct p__parent = null, SolutionMeta p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _flags = m_io.ReadU1();
            }
            private byte _flags;
            private SolutionMeta m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// flags that store all relevant info specific to this sensor type.
            /// </summary>
            public byte Flags { get { return _flags; } }
            public SolutionMeta M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message contains all metadata about the sensors received and/or
        /// used in computing the sensorfusion solution. It focuses primarily, but
        /// not only, on GNSS metadata. Regarding the age of the last received valid
        /// GNSS solution, the highest two bits are time status, indicating whether
        /// age gnss can or can not be used to retrieve time of measurement (noted
        /// TOM, also known as time of validity) If it can, subtract 'age gnss' from
        /// 'tow' in navigation messages to get TOM. Can be used before alignment is
        /// complete in the Fusion Engine, when output solution is the last received
        /// valid GNSS solution and its tow is not a TOM.
        /// </summary>
        public partial class MsgSolnMeta : KaitaiStruct
        {
            public static MsgSolnMeta FromFile(string fileName)
            {
                return new MsgSolnMeta(new KaitaiStream(fileName));
            }

            public MsgSolnMeta(KaitaiStream p__io, Sbp.Message p__parent = null, SolutionMeta p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _tow = m_io.ReadU4le();
                _pdop = m_io.ReadU2le();
                _hdop = m_io.ReadU2le();
                _vdop = m_io.ReadU2le();
                _ageCorrections = m_io.ReadU2le();
                _ageGnss = m_io.ReadU4le();
                _solIn = new List<SolutionInputType>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _solIn.Add(new SolutionInputType(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private uint _tow;
            private ushort _pdop;
            private ushort _hdop;
            private ushort _vdop;
            private ushort _ageCorrections;
            private uint _ageGnss;
            private List<SolutionInputType> _solIn;
            private SolutionMeta m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// GPS time of week rounded to the nearest millisecond
            /// </summary>
            public uint Tow { get { return _tow; } }

            /// <summary>
            /// Position Dilution of Precision as per last available DOPS from PVT
            /// engine (0xFFFF indicates invalid)
            /// </summary>
            public ushort Pdop { get { return _pdop; } }

            /// <summary>
            /// Horizontal Dilution of Precision as per last available DOPS from PVT
            /// engine (0xFFFF indicates invalid)
            /// </summary>
            public ushort Hdop { get { return _hdop; } }

            /// <summary>
            /// Vertical Dilution of Precision as per last available DOPS from PVT
            /// engine (0xFFFF indicates invalid)
            /// </summary>
            public ushort Vdop { get { return _vdop; } }

            /// <summary>
            /// Age of corrections as per last available AGE_CORRECTIONS from PVT
            /// engine (0xFFFF indicates invalid)
            /// </summary>
            public ushort AgeCorrections { get { return _ageCorrections; } }

            /// <summary>
            /// Age and Time Status of the last received valid GNSS solution.
            /// </summary>
            public uint AgeGnss { get { return _ageGnss; } }

            /// <summary>
            /// Array of Metadata describing the sensors potentially involved in the
            /// solution. Each element in the array represents a single sensor type
            /// and consists of flags containing (meta)data pertaining to that
            /// specific single sensor. Refer to each (XX)InputType descriptor in
            /// the present doc.
            /// </summary>
            public List<SolutionInputType> SolIn { get { return _solIn; } }
            public SolutionMeta M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgSolnMetaDepA : KaitaiStruct
        {
            public static MsgSolnMetaDepA FromFile(string fileName)
            {
                return new MsgSolnMetaDepA(new KaitaiStream(fileName));
            }

            public MsgSolnMetaDepA(KaitaiStream p__io, Sbp.Message p__parent = null, SolutionMeta p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _pdop = m_io.ReadU2le();
                _hdop = m_io.ReadU2le();
                _vdop = m_io.ReadU2le();
                _nSats = m_io.ReadU1();
                _ageCorrections = m_io.ReadU2le();
                _alignmentStatus = m_io.ReadU1();
                _lastUsedGnssPosTow = m_io.ReadU4le();
                _lastUsedGnssVelTow = m_io.ReadU4le();
                _solIn = new List<SolutionInputType>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _solIn.Add(new SolutionInputType(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private ushort _pdop;
            private ushort _hdop;
            private ushort _vdop;
            private byte _nSats;
            private ushort _ageCorrections;
            private byte _alignmentStatus;
            private uint _lastUsedGnssPosTow;
            private uint _lastUsedGnssVelTow;
            private List<SolutionInputType> _solIn;
            private SolutionMeta m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Position Dilution of Precision as per last available DOPS from PVT
            /// engine (0xFFFF indicates invalid)
            /// </summary>
            public ushort Pdop { get { return _pdop; } }

            /// <summary>
            /// Horizontal Dilution of Precision as per last available DOPS from PVT
            /// engine (0xFFFF indicates invalid)
            /// </summary>
            public ushort Hdop { get { return _hdop; } }

            /// <summary>
            /// Vertical Dilution of Precision as per last available DOPS from PVT
            /// engine (0xFFFF indicates invalid)
            /// </summary>
            public ushort Vdop { get { return _vdop; } }

            /// <summary>
            /// Number of satellites as per last available solution from PVT engine
            /// </summary>
            public byte NSats { get { return _nSats; } }

            /// <summary>
            /// Age of corrections as per last available AGE_CORRECTIONS from PVT
            /// engine (0xFFFF indicates invalid)
            /// </summary>
            public ushort AgeCorrections { get { return _ageCorrections; } }

            /// <summary>
            /// State of alignment and the status and receipt of the alignment
            /// inputs
            /// </summary>
            public byte AlignmentStatus { get { return _alignmentStatus; } }

            /// <summary>
            /// Tow of last-used GNSS position measurement
            /// </summary>
            public uint LastUsedGnssPosTow { get { return _lastUsedGnssPosTow; } }

            /// <summary>
            /// Tow of last-used GNSS velocity measurement
            /// </summary>
            public uint LastUsedGnssVelTow { get { return _lastUsedGnssVelTow; } }

            /// <summary>
            /// Array of Metadata describing the sensors potentially involved in the
            /// solution. Each element in the array represents a single sensor type
            /// and consists of flags containing (meta)data pertaining to that
            /// specific single sensor. Refer to each (XX)InputType descriptor in
            /// the present doc.
            /// </summary>
            public List<SolutionInputType> SolIn { get { return _solIn; } }
            public SolutionMeta M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Metadata around the IMU sensors involved in the fuzed solution.
        /// Accessible through sol_in[N].flags in a MSG_SOLN_META.
        /// </summary>
        public partial class ImuInputType : KaitaiStruct
        {
            public static ImuInputType FromFile(string fileName)
            {
                return new ImuInputType(new KaitaiStream(fileName));
            }

            public ImuInputType(KaitaiStream p__io, KaitaiStruct p__parent = null, SolutionMeta p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _flags = m_io.ReadU1();
            }
            private byte _flags;
            private SolutionMeta m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// Instrument time, grade, and architecture for a sensor.
            /// </summary>
            public byte Flags { get { return _flags; } }
            public SolutionMeta M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Metadata around the Odometry sensors involved in the fuzed solution.
        /// Accessible through sol_in[N].flags in a MSG_SOLN_META.
        /// </summary>
        public partial class OdoInputType : KaitaiStruct
        {
            public static OdoInputType FromFile(string fileName)
            {
                return new OdoInputType(new KaitaiStream(fileName));
            }

            public OdoInputType(KaitaiStream p__io, KaitaiStruct p__parent = null, SolutionMeta p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _flags = m_io.ReadU1();
            }
            private byte _flags;
            private SolutionMeta m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// Instrument ODO rate, grade, and quality.
            /// </summary>
            public byte Flags { get { return _flags; } }
            public SolutionMeta M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Metadata describing which sensors were involved in the solution. The
        /// structure is fixed no matter what the actual sensor type is. The
        /// sensor_type field tells you which sensor we are talking about. It also
        /// tells you whether the sensor data was actually used or not. The flags
        /// field, always a u8, contains the sensor-specific data. The content of
        /// flags, for each sensor type, is described in the relevant structures in
        /// this section.
        /// </summary>
        public partial class SolutionInputType : KaitaiStruct
        {
            public static SolutionInputType FromFile(string fileName)
            {
                return new SolutionInputType(new KaitaiStream(fileName));
            }

            public SolutionInputType(KaitaiStream p__io, KaitaiStruct p__parent = null, SolutionMeta p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _sensorType = m_io.ReadU1();
                _flags = m_io.ReadU1();
            }
            private byte _sensorType;
            private byte _flags;
            private SolutionMeta m_root;
            private KaitaiStruct m_parent;

            /// <summary>
            /// The type of sensor
            /// </summary>
            public byte SensorType { get { return _sensorType; } }

            /// <summary>
            /// Refer to each InputType description
            /// </summary>
            public byte Flags { get { return _flags; } }
            public SolutionMeta M_Root { get { return m_root; } }
            public KaitaiStruct M_Parent { get { return m_parent; } }
        }
        private SolutionMeta m_root;
        private KaitaiStruct m_parent;
        public SolutionMeta M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
