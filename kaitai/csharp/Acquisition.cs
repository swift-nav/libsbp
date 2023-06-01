// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class Acquisition : KaitaiStruct
    {
        public static Acquisition FromFile(string fileName)
        {
            return new Acquisition(new KaitaiStream(fileName));
        }

        public Acquisition(KaitaiStream p__io, KaitaiStruct p__parent = null, Acquisition p__root = null) : base(p__io)
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
        public partial class MsgAcqResultDepC : KaitaiStruct
        {
            public static MsgAcqResultDepC FromFile(string fileName)
            {
                return new MsgAcqResultDepC(new KaitaiStream(fileName));
            }

            public MsgAcqResultDepC(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Acquisition p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _cn0 = m_io.ReadF4le();
                _cp = m_io.ReadF4le();
                _cf = m_io.ReadF4le();
                _sid = new Gnss.GnssSignalDep(m_io, this, m_root);
            }
            private float _cn0;
            private float _cp;
            private float _cf;
            private Gnss.GnssSignalDep _sid;
            private Acquisition m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// CN/0 of best point
            /// </summary>
            public float Cn0 { get { return _cn0; } }

            /// <summary>
            /// Code phase of best point
            /// </summary>
            public float Cp { get { return _cp; } }

            /// <summary>
            /// Carrier frequency of best point
            /// </summary>
            public float Cf { get { return _cf; } }

            /// <summary>
            /// GNSS signal for which acquisition was attempted
            /// </summary>
            public Gnss.GnssSignalDep Sid { get { return _sid; } }
            public Acquisition M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgAcqResultDepB : KaitaiStruct
        {
            public static MsgAcqResultDepB FromFile(string fileName)
            {
                return new MsgAcqResultDepB(new KaitaiStream(fileName));
            }

            public MsgAcqResultDepB(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Acquisition p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _snr = m_io.ReadF4le();
                _cp = m_io.ReadF4le();
                _cf = m_io.ReadF4le();
                _sid = new Gnss.GnssSignalDep(m_io, this, m_root);
            }
            private float _snr;
            private float _cp;
            private float _cf;
            private Gnss.GnssSignalDep _sid;
            private Acquisition m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// SNR of best point. Currently in arbitrary SNR points, but will be in
            /// units of dB Hz in a later revision of this message.
            /// </summary>
            public float Snr { get { return _snr; } }

            /// <summary>
            /// Code phase of best point
            /// </summary>
            public float Cp { get { return _cp; } }

            /// <summary>
            /// Carrier frequency of best point
            /// </summary>
            public float Cf { get { return _cf; } }

            /// <summary>
            /// GNSS signal for which acquisition was attempted
            /// </summary>
            public Gnss.GnssSignalDep Sid { get { return _sid; } }
            public Acquisition M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Profile for a specific SV for debugging purposes. The message describes
        /// SV profile during acquisition time. The message is used to debug and
        /// measure the performance.
        /// </summary>
        public partial class AcqSvProfile : KaitaiStruct
        {
            public static AcqSvProfile FromFile(string fileName)
            {
                return new AcqSvProfile(new KaitaiStream(fileName));
            }

            public AcqSvProfile(KaitaiStream p__io, Acquisition.MsgAcqSvProfile p__parent = null, Acquisition p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _jobType = m_io.ReadU1();
                _status = m_io.ReadU1();
                _cn0 = m_io.ReadU2le();
                _intTime = m_io.ReadU1();
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
                _binWidth = m_io.ReadU2le();
                _timestamp = m_io.ReadU4le();
                _timeSpent = m_io.ReadU4le();
                _cfMin = m_io.ReadS4le();
                _cfMax = m_io.ReadS4le();
                _cf = m_io.ReadS4le();
                _cp = m_io.ReadU4le();
            }
            private byte _jobType;
            private byte _status;
            private ushort _cn0;
            private byte _intTime;
            private Gnss.GnssSignal _sid;
            private ushort _binWidth;
            private uint _timestamp;
            private uint _timeSpent;
            private int _cfMin;
            private int _cfMax;
            private int _cf;
            private uint _cp;
            private Acquisition m_root;
            private Acquisition.MsgAcqSvProfile m_parent;

            /// <summary>
            /// SV search job type (deep, fallback, etc)
            /// </summary>
            public byte JobType { get { return _jobType; } }

            /// <summary>
            /// Acquisition status 1 is Success, 0 is Failure
            /// </summary>
            public byte Status { get { return _status; } }

            /// <summary>
            /// CN0 value. Only valid if status is '1'
            /// </summary>
            public ushort Cn0 { get { return _cn0; } }

            /// <summary>
            /// Acquisition integration time
            /// </summary>
            public byte IntTime { get { return _intTime; } }

            /// <summary>
            /// GNSS signal for which acquisition was attempted
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }

            /// <summary>
            /// Acq frequency bin width
            /// </summary>
            public ushort BinWidth { get { return _binWidth; } }

            /// <summary>
            /// Timestamp of the job complete event
            /// </summary>
            public uint Timestamp { get { return _timestamp; } }

            /// <summary>
            /// Time spent to search for sid.code
            /// </summary>
            public uint TimeSpent { get { return _timeSpent; } }

            /// <summary>
            /// Doppler range lowest frequency
            /// </summary>
            public int CfMin { get { return _cfMin; } }

            /// <summary>
            /// Doppler range highest frequency
            /// </summary>
            public int CfMax { get { return _cfMax; } }

            /// <summary>
            /// Doppler value of detected peak. Only valid if status is '1'
            /// </summary>
            public int Cf { get { return _cf; } }

            /// <summary>
            /// Codephase of detected peak. Only valid if status is '1'
            /// </summary>
            public uint Cp { get { return _cp; } }
            public Acquisition M_Root { get { return m_root; } }
            public Acquisition.MsgAcqSvProfile M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// The message describes all SV profiles during acquisition time. The
        /// message is used to debug and measure the performance.
        /// </summary>
        public partial class MsgAcqSvProfile : KaitaiStruct
        {
            public static MsgAcqSvProfile FromFile(string fileName)
            {
                return new MsgAcqSvProfile(new KaitaiStream(fileName));
            }

            public MsgAcqSvProfile(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Acquisition p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _acqSvProfile = new List<AcqSvProfile>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _acqSvProfile.Add(new AcqSvProfile(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private List<AcqSvProfile> _acqSvProfile;
            private Acquisition m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// SV profiles during acquisition time
            /// </summary>
            public List<AcqSvProfile> AcqSvProfile { get { return _acqSvProfile; } }
            public Acquisition M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class AcqSvProfileDep : KaitaiStruct
        {
            public static AcqSvProfileDep FromFile(string fileName)
            {
                return new AcqSvProfileDep(new KaitaiStream(fileName));
            }

            public AcqSvProfileDep(KaitaiStream p__io, Acquisition.MsgAcqSvProfileDep p__parent = null, Acquisition p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _jobType = m_io.ReadU1();
                _status = m_io.ReadU1();
                _cn0 = m_io.ReadU2le();
                _intTime = m_io.ReadU1();
                _sid = new Gnss.GnssSignalDep(m_io, this, m_root);
                _binWidth = m_io.ReadU2le();
                _timestamp = m_io.ReadU4le();
                _timeSpent = m_io.ReadU4le();
                _cfMin = m_io.ReadS4le();
                _cfMax = m_io.ReadS4le();
                _cf = m_io.ReadS4le();
                _cp = m_io.ReadU4le();
            }
            private byte _jobType;
            private byte _status;
            private ushort _cn0;
            private byte _intTime;
            private Gnss.GnssSignalDep _sid;
            private ushort _binWidth;
            private uint _timestamp;
            private uint _timeSpent;
            private int _cfMin;
            private int _cfMax;
            private int _cf;
            private uint _cp;
            private Acquisition m_root;
            private Acquisition.MsgAcqSvProfileDep m_parent;

            /// <summary>
            /// SV search job type (deep, fallback, etc)
            /// </summary>
            public byte JobType { get { return _jobType; } }

            /// <summary>
            /// Acquisition status 1 is Success, 0 is Failure
            /// </summary>
            public byte Status { get { return _status; } }

            /// <summary>
            /// CN0 value. Only valid if status is '1'
            /// </summary>
            public ushort Cn0 { get { return _cn0; } }

            /// <summary>
            /// Acquisition integration time
            /// </summary>
            public byte IntTime { get { return _intTime; } }

            /// <summary>
            /// GNSS signal for which acquisition was attempted
            /// </summary>
            public Gnss.GnssSignalDep Sid { get { return _sid; } }

            /// <summary>
            /// Acq frequency bin width
            /// </summary>
            public ushort BinWidth { get { return _binWidth; } }

            /// <summary>
            /// Timestamp of the job complete event
            /// </summary>
            public uint Timestamp { get { return _timestamp; } }

            /// <summary>
            /// Time spent to search for sid.code
            /// </summary>
            public uint TimeSpent { get { return _timeSpent; } }

            /// <summary>
            /// Doppler range lowest frequency
            /// </summary>
            public int CfMin { get { return _cfMin; } }

            /// <summary>
            /// Doppler range highest frequency
            /// </summary>
            public int CfMax { get { return _cfMax; } }

            /// <summary>
            /// Doppler value of detected peak. Only valid if status is '1'
            /// </summary>
            public int Cf { get { return _cf; } }

            /// <summary>
            /// Codephase of detected peak. Only valid if status is '1'
            /// </summary>
            public uint Cp { get { return _cp; } }
            public Acquisition M_Root { get { return m_root; } }
            public Acquisition.MsgAcqSvProfileDep M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// This message describes the results from an attempted GPS signal
        /// acquisition search for a satellite PRN over a code phase/carrier
        /// frequency range. It contains the parameters of the point in the
        /// acquisition search space with the best carrier-to-noise (CN/0) ratio.
        /// </summary>
        public partial class MsgAcqResult : KaitaiStruct
        {
            public static MsgAcqResult FromFile(string fileName)
            {
                return new MsgAcqResult(new KaitaiStream(fileName));
            }

            public MsgAcqResult(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Acquisition p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _cn0 = m_io.ReadF4le();
                _cp = m_io.ReadF4le();
                _cf = m_io.ReadF4le();
                _sid = new Gnss.GnssSignal(m_io, this, m_root);
            }
            private float _cn0;
            private float _cp;
            private float _cf;
            private Gnss.GnssSignal _sid;
            private Acquisition m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// CN/0 of best point
            /// </summary>
            public float Cn0 { get { return _cn0; } }

            /// <summary>
            /// Code phase of best point
            /// </summary>
            public float Cp { get { return _cp; } }

            /// <summary>
            /// Carrier frequency of best point
            /// </summary>
            public float Cf { get { return _cf; } }

            /// <summary>
            /// GNSS signal for which acquisition was attempted
            /// </summary>
            public Gnss.GnssSignal Sid { get { return _sid; } }
            public Acquisition M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgAcqResultDepA : KaitaiStruct
        {
            public static MsgAcqResultDepA FromFile(string fileName)
            {
                return new MsgAcqResultDepA(new KaitaiStream(fileName));
            }

            public MsgAcqResultDepA(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Acquisition p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _snr = m_io.ReadF4le();
                _cp = m_io.ReadF4le();
                _cf = m_io.ReadF4le();
                _prn = m_io.ReadU1();
            }
            private float _snr;
            private float _cp;
            private float _cf;
            private byte _prn;
            private Acquisition m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// SNR of best point. Currently dimensionless, but will have units of
            /// dB Hz in the revision of this message.
            /// </summary>
            public float Snr { get { return _snr; } }

            /// <summary>
            /// Code phase of best point
            /// </summary>
            public float Cp { get { return _cp; } }

            /// <summary>
            /// Carrier frequency of best point
            /// </summary>
            public float Cf { get { return _cf; } }

            /// <summary>
            /// PRN-1 identifier of the satellite signal for which acquisition was
            /// attempted
            /// </summary>
            public byte Prn { get { return _prn; } }
            public Acquisition M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// Deprecated.
        /// </summary>
        public partial class MsgAcqSvProfileDep : KaitaiStruct
        {
            public static MsgAcqSvProfileDep FromFile(string fileName)
            {
                return new MsgAcqSvProfileDep(new KaitaiStream(fileName));
            }

            public MsgAcqSvProfileDep(KaitaiStream p__io, Sbp.SbpMessage p__parent = null, Acquisition p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _acqSvProfile = new List<AcqSvProfileDep>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _acqSvProfile.Add(new AcqSvProfileDep(m_io, this, m_root));
                        i++;
                    }
                }
            }
            private List<AcqSvProfileDep> _acqSvProfile;
            private Acquisition m_root;
            private Sbp.SbpMessage m_parent;

            /// <summary>
            /// SV profiles during acquisition time
            /// </summary>
            public List<AcqSvProfileDep> AcqSvProfile { get { return _acqSvProfile; } }
            public Acquisition M_Root { get { return m_root; } }
            public Sbp.SbpMessage M_Parent { get { return m_parent; } }
        }
        private Acquisition m_root;
        private KaitaiStruct m_parent;
        public Acquisition M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
