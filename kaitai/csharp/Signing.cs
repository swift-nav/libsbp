// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

using System.Collections.Generic;

namespace Kaitai
{
    public partial class Signing : KaitaiStruct
    {
        public static Signing FromFile(string fileName)
        {
            return new Signing(new KaitaiStream(fileName));
        }

        public Signing(KaitaiStream p__io, KaitaiStruct p__parent = null, Signing p__root = null) : base(p__io)
        {
            m_parent = p__parent;
            m_root = p__root ?? this;
            _read();
        }
        private void _read()
        {
        }
        public partial class MsgEd25519SignatureDepB : KaitaiStruct
        {
            public static MsgEd25519SignatureDepB FromFile(string fileName)
            {
                return new MsgEd25519SignatureDepB(new KaitaiStream(fileName));
            }

            public MsgEd25519SignatureDepB(KaitaiStream p__io, Sbp.Message p__parent = null, Signing p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _streamCounter = m_io.ReadU1();
                _onDemandCounter = m_io.ReadU1();
                _signature = new List<byte>();
                for (var i = 0; i < 64; i++)
                {
                    _signature.Add(m_io.ReadU1());
                }
                _fingerprint = new List<byte>();
                for (var i = 0; i < 20; i++)
                {
                    _fingerprint.Add(m_io.ReadU1());
                }
                _signedMessages = new List<uint>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _signedMessages.Add(m_io.ReadU4le());
                        i++;
                    }
                }
            }
            private byte _streamCounter;
            private byte _onDemandCounter;
            private List<byte> _signature;
            private List<byte> _fingerprint;
            private List<uint> _signedMessages;
            private Signing m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Signature message counter. Zero indexed and incremented with each
            /// signature message.  The counter will not increment if this message
            /// was in response to an on demand request.  The counter will roll over
            /// after 256 messages. Upon connection, the value of the counter may
            /// not initially be zero.
            /// </summary>
            public byte StreamCounter { get { return _streamCounter; } }

            /// <summary>
            /// On demand message counter. Zero indexed and incremented with each
            /// signature message sent in response to an on demand message. The
            /// counter will roll over after 256 messages.  Upon connection, the
            /// value of the counter may not initially be zero.
            /// </summary>
            public byte OnDemandCounter { get { return _onDemandCounter; } }

            /// <summary>
            /// ED25519 signature for messages.
            /// </summary>
            public List<byte> Signature { get { return _signature; } }

            /// <summary>
            /// SHA-1 fingerprint of the associated certificate.
            /// </summary>
            public List<byte> Fingerprint { get { return _fingerprint; } }

            /// <summary>
            /// CRCs of signed messages.
            /// </summary>
            public List<uint> SignedMessages { get { return _signedMessages; } }
            public Signing M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        public partial class MsgEd25519CertificateDep : KaitaiStruct
        {
            public static MsgEd25519CertificateDep FromFile(string fileName)
            {
                return new MsgEd25519CertificateDep(new KaitaiStream(fileName));
            }

            public MsgEd25519CertificateDep(KaitaiStream p__io, Sbp.Message p__parent = null, Signing p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _nMsg = m_io.ReadU1();
                _fingerprint = new List<byte>();
                for (var i = 0; i < 20; i++)
                {
                    _fingerprint.Add(m_io.ReadU1());
                }
                _certificateBytes = new List<byte>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _certificateBytes.Add(m_io.ReadU1());
                        i++;
                    }
                }
            }
            private byte _nMsg;
            private List<byte> _fingerprint;
            private List<byte> _certificateBytes;
            private Signing m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Total number messages that make up the certificate. First nibble is
            /// the size of the sequence (n), second nibble is the zero-indexed
            /// counter (ith packet of n)
            /// </summary>
            public byte NMsg { get { return _nMsg; } }

            /// <summary>
            /// SHA-1 fingerprint of the associated certificate.
            /// </summary>
            public List<byte> Fingerprint { get { return _fingerprint; } }

            /// <summary>
            /// ED25519 certificate bytes.
            /// </summary>
            public List<byte> CertificateBytes { get { return _certificateBytes; } }
            public Signing M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        public partial class UtcTime : KaitaiStruct
        {
            public static UtcTime FromFile(string fileName)
            {
                return new UtcTime(new KaitaiStream(fileName));
            }

            public UtcTime(KaitaiStream p__io, Signing.MsgCertificateChain p__parent = null, Signing p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _year = m_io.ReadU2le();
                _month = m_io.ReadU1();
                _day = m_io.ReadU1();
                _hours = m_io.ReadU1();
                _minutes = m_io.ReadU1();
                _seconds = m_io.ReadU1();
                _ns = m_io.ReadU4le();
            }
            private ushort _year;
            private byte _month;
            private byte _day;
            private byte _hours;
            private byte _minutes;
            private byte _seconds;
            private uint _ns;
            private Signing m_root;
            private Signing.MsgCertificateChain m_parent;

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
            public Signing M_Root { get { return m_root; } }
            public Signing.MsgCertificateChain M_Parent { get { return m_parent; } }
        }
        public partial class MsgEd25519SignatureDepA : KaitaiStruct
        {
            public static MsgEd25519SignatureDepA FromFile(string fileName)
            {
                return new MsgEd25519SignatureDepA(new KaitaiStream(fileName));
            }

            public MsgEd25519SignatureDepA(KaitaiStream p__io, Sbp.Message p__parent = null, Signing p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _signature = new List<byte>();
                for (var i = 0; i < 64; i++)
                {
                    _signature.Add(m_io.ReadU1());
                }
                _fingerprint = new List<byte>();
                for (var i = 0; i < 20; i++)
                {
                    _fingerprint.Add(m_io.ReadU1());
                }
                _signedMessages = new List<uint>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _signedMessages.Add(m_io.ReadU4le());
                        i++;
                    }
                }
            }
            private List<byte> _signature;
            private List<byte> _fingerprint;
            private List<uint> _signedMessages;
            private Signing m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// ED25519 signature for messages.
            /// </summary>
            public List<byte> Signature { get { return _signature; } }

            /// <summary>
            /// SHA-1 fingerprint of the associated certificate.
            /// </summary>
            public List<byte> Fingerprint { get { return _fingerprint; } }

            /// <summary>
            /// CRCs of signed messages.
            /// </summary>
            public List<uint> SignedMessages { get { return _signedMessages; } }
            public Signing M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        public partial class MsgCertificateChain : KaitaiStruct
        {
            public static MsgCertificateChain FromFile(string fileName)
            {
                return new MsgCertificateChain(new KaitaiStream(fileName));
            }

            public MsgCertificateChain(KaitaiStream p__io, Sbp.Message p__parent = null, Signing p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _rootCertificate = new List<byte>();
                for (var i = 0; i < 20; i++)
                {
                    _rootCertificate.Add(m_io.ReadU1());
                }
                _intermediateCertificate = new List<byte>();
                for (var i = 0; i < 20; i++)
                {
                    _intermediateCertificate.Add(m_io.ReadU1());
                }
                _correctionsCertificate = new List<byte>();
                for (var i = 0; i < 20; i++)
                {
                    _correctionsCertificate.Add(m_io.ReadU1());
                }
                _expiration = new UtcTime(m_io, this, m_root);
                _signature = new List<byte>();
                for (var i = 0; i < 64; i++)
                {
                    _signature.Add(m_io.ReadU1());
                }
            }
            private List<byte> _rootCertificate;
            private List<byte> _intermediateCertificate;
            private List<byte> _correctionsCertificate;
            private UtcTime _expiration;
            private List<byte> _signature;
            private Signing m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// SHA-1 fingerprint of the root certificate
            /// </summary>
            public List<byte> RootCertificate { get { return _rootCertificate; } }

            /// <summary>
            /// SHA-1 fingerprint of the intermediate certificate
            /// </summary>
            public List<byte> IntermediateCertificate { get { return _intermediateCertificate; } }

            /// <summary>
            /// SHA-1 fingerprint of the corrections certificate
            /// </summary>
            public List<byte> CorrectionsCertificate { get { return _correctionsCertificate; } }

            /// <summary>
            /// The certificate chain comprised of three fingerprints: root
            /// certificate, intermediate certificate and corrections certificate.
            /// </summary>
            public UtcTime Expiration { get { return _expiration; } }

            /// <summary>
            /// An ECDSA signature (created by the root certificate) over the
            /// concatenation of the SBP payload bytes preceding this field. That
            /// is, the concatenation of `root_certificate`,
            /// `intermediate_certificate`, `corrections_certificate` and
            /// `expiration`.  This certificate chain (allow list) can also be
            /// validated by fetching it from `http(s)://certs.swiftnav.com/chain`.
            /// </summary>
            public List<byte> Signature { get { return _signature; } }
            public Signing M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// A DER encoded x.509 ECDSA-256 certificate (using curve secp256r1).
        /// </summary>
        public partial class MsgEcdsaCertificate : KaitaiStruct
        {
            public static MsgEcdsaCertificate FromFile(string fileName)
            {
                return new MsgEcdsaCertificate(new KaitaiStream(fileName));
            }

            public MsgEcdsaCertificate(KaitaiStream p__io, Sbp.Message p__parent = null, Signing p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _nMsg = m_io.ReadU1();
                _certificateId = new List<byte>();
                for (var i = 0; i < 4; i++)
                {
                    _certificateId.Add(m_io.ReadU1());
                }
                _flags = m_io.ReadU1();
                _certificateBytes = new List<byte>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _certificateBytes.Add(m_io.ReadU1());
                        i++;
                    }
                }
            }
            private byte _nMsg;
            private List<byte> _certificateId;
            private byte _flags;
            private List<byte> _certificateBytes;
            private Signing m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Total number messages that make up the certificate. The first nibble
            /// (mask 0xF0 or left shifted by 4 bits) is the size of the sequence
            /// (n), second nibble (mask 0x0F) is the zero-indexed counter (ith
            /// packet of n).
            /// </summary>
            public byte NMsg { get { return _nMsg; } }

            /// <summary>
            /// The last 4 bytes of the certificate's SHA-1 fingerprint
            /// </summary>
            public List<byte> CertificateId { get { return _certificateId; } }
            public byte Flags { get { return _flags; } }

            /// <summary>
            /// DER encoded x.509 ECDSA certificate bytes
            /// </summary>
            public List<byte> CertificateBytes { get { return _certificateBytes; } }
            public Signing M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }

        /// <summary>
        /// An ECDSA-256 signature using SHA-256 as the message digest algorithm.
        /// </summary>
        public partial class MsgEcdsaSignature : KaitaiStruct
        {
            public static MsgEcdsaSignature FromFile(string fileName)
            {
                return new MsgEcdsaSignature(new KaitaiStream(fileName));
            }

            public MsgEcdsaSignature(KaitaiStream p__io, Sbp.Message p__parent = null, Signing p__root = null) : base(p__io)
            {
                m_parent = p__parent;
                m_root = p__root;
                _read();
            }
            private void _read()
            {
                _flags = m_io.ReadU1();
                _streamCounter = m_io.ReadU1();
                _onDemandCounter = m_io.ReadU1();
                _certificateId = new List<byte>();
                for (var i = 0; i < 4; i++)
                {
                    _certificateId.Add(m_io.ReadU1());
                }
                _signature = new List<byte>();
                for (var i = 0; i < 64; i++)
                {
                    _signature.Add(m_io.ReadU1());
                }
                _signedMessages = new List<byte>();
                {
                    var i = 0;
                    while (!m_io.IsEof) {
                        _signedMessages.Add(m_io.ReadU1());
                        i++;
                    }
                }
            }
            private byte _flags;
            private byte _streamCounter;
            private byte _onDemandCounter;
            private List<byte> _certificateId;
            private List<byte> _signature;
            private List<byte> _signedMessages;
            private Signing m_root;
            private Sbp.Message m_parent;

            /// <summary>
            /// Describes the format of the `signed\_messages` field below.
            /// </summary>
            public byte Flags { get { return _flags; } }

            /// <summary>
            /// Signature message counter. Zero indexed and incremented with each
            /// signature message.  The counter will not increment if this message
            /// was in response to an on demand request.  The counter will roll over
            /// after 256 messages. Upon connection, the value of the counter may
            /// not initially be zero.
            /// </summary>
            public byte StreamCounter { get { return _streamCounter; } }

            /// <summary>
            /// On demand message counter. Zero indexed and incremented with each
            /// signature message sent in response to an on demand message. The
            /// counter will roll over after 256 messages.  Upon connection, the
            /// value of the counter may not initially be zero.
            /// </summary>
            public byte OnDemandCounter { get { return _onDemandCounter; } }

            /// <summary>
            /// The last 4 bytes of the certificate's SHA-1 fingerprint
            /// </summary>
            public List<byte> CertificateId { get { return _certificateId; } }

            /// <summary>
            /// ECDSA signature for the messages using SHA-256 as the digest
            /// algorithm.
            /// </summary>
            public List<byte> Signature { get { return _signature; } }

            /// <summary>
            /// CRCs of the messages covered by this signature.  For Skylark, which
            /// delivers SBP messages wrapped in Swift's proprietary RTCM message,
            /// these are the 24-bit CRCs from the RTCM message framing. For SBP
            /// only streams, this will be 16-bit CRCs from the SBP framing.  See
            /// the `flags` field to determine the type of CRCs covered.
            /// </summary>
            public List<byte> SignedMessages { get { return _signedMessages; } }
            public Signing M_Root { get { return m_root; } }
            public Sbp.Message M_Parent { get { return m_parent; } }
        }
        private Signing m_root;
        private KaitaiStruct m_parent;
        public Signing M_Root { get { return m_root; } }
        public KaitaiStruct M_Parent { get { return m_parent; } }
    }
}
