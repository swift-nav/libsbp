// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

import io.kaitai.struct.ByteBufferKaitaiStream;
import io.kaitai.struct.KaitaiStruct;
import io.kaitai.struct.KaitaiStream;
import java.io.IOException;
import java.util.ArrayList;

public class Signing extends KaitaiStruct {
    public static Signing fromFile(String fileName) throws IOException {
        return new Signing(new ByteBufferKaitaiStream(fileName));
    }

    public Signing(KaitaiStream _io) {
        this(_io, null, null);
    }

    public Signing(KaitaiStream _io, KaitaiStruct _parent) {
        this(_io, _parent, null);
    }

    public Signing(KaitaiStream _io, KaitaiStruct _parent, Signing _root) {
        super(_io);
        this._parent = _parent;
        this._root = _root == null ? this : _root;
        _read();
    }
    private void _read() {
    }
    public static class MsgEd25519SignatureDepB extends KaitaiStruct {
        public static MsgEd25519SignatureDepB fromFile(String fileName) throws IOException {
            return new MsgEd25519SignatureDepB(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEd25519SignatureDepB(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEd25519SignatureDepB(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEd25519SignatureDepB(KaitaiStream _io, Sbp.Message _parent, Signing _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.streamCounter = this._io.readU1();
            this.onDemandCounter = this._io.readU1();
            this.signature = new ArrayList<Integer>();
            for (int i = 0; i < 64; i++) {
                this.signature.add(this._io.readU1());
            }
            this.fingerprint = new ArrayList<Integer>();
            for (int i = 0; i < 20; i++) {
                this.fingerprint.add(this._io.readU1());
            }
            this.signedMessages = new ArrayList<Long>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.signedMessages.add(this._io.readU4le());
                    i++;
                }
            }
        }
        private int streamCounter;
        private int onDemandCounter;
        private ArrayList<Integer> signature;
        private ArrayList<Integer> fingerprint;
        private ArrayList<Long> signedMessages;
        private Signing _root;
        private Sbp.Message _parent;

        /**
         * Signature message counter. Zero indexed and incremented with each
         * signature message.  The counter will not increment if this message
         * was in response to an on demand request.  The counter will roll over
         * after 256 messages. Upon connection, the value of the counter may
         * not initially be zero.
         */
        public int streamCounter() { return streamCounter; }

        /**
         * On demand message counter. Zero indexed and incremented with each
         * signature message sent in response to an on demand message. The
         * counter will roll over after 256 messages.  Upon connection, the
         * value of the counter may not initially be zero.
         */
        public int onDemandCounter() { return onDemandCounter; }

        /**
         * ED25519 signature for messages.
         */
        public ArrayList<Integer> signature() { return signature; }

        /**
         * SHA-1 fingerprint of the associated certificate.
         */
        public ArrayList<Integer> fingerprint() { return fingerprint; }

        /**
         * CRCs of signed messages.
         */
        public ArrayList<Long> signedMessages() { return signedMessages; }
        public Signing _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class MsgEd25519CertificateDep extends KaitaiStruct {
        public static MsgEd25519CertificateDep fromFile(String fileName) throws IOException {
            return new MsgEd25519CertificateDep(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEd25519CertificateDep(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEd25519CertificateDep(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEd25519CertificateDep(KaitaiStream _io, Sbp.Message _parent, Signing _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.nMsg = this._io.readU1();
            this.fingerprint = new ArrayList<Integer>();
            for (int i = 0; i < 20; i++) {
                this.fingerprint.add(this._io.readU1());
            }
            this.certificateBytes = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.certificateBytes.add(this._io.readU1());
                    i++;
                }
            }
        }
        private int nMsg;
        private ArrayList<Integer> fingerprint;
        private ArrayList<Integer> certificateBytes;
        private Signing _root;
        private Sbp.Message _parent;

        /**
         * Total number messages that make up the certificate. First nibble is
         * the size of the sequence (n), second nibble is the zero-indexed
         * counter (ith packet of n)
         */
        public int nMsg() { return nMsg; }

        /**
         * SHA-1 fingerprint of the associated certificate.
         */
        public ArrayList<Integer> fingerprint() { return fingerprint; }

        /**
         * ED25519 certificate bytes.
         */
        public ArrayList<Integer> certificateBytes() { return certificateBytes; }
        public Signing _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class UtcTime extends KaitaiStruct {
        public static UtcTime fromFile(String fileName) throws IOException {
            return new UtcTime(new ByteBufferKaitaiStream(fileName));
        }

        public UtcTime(KaitaiStream _io) {
            this(_io, null, null);
        }

        public UtcTime(KaitaiStream _io, Signing.MsgCertificateChain _parent) {
            this(_io, _parent, null);
        }

        public UtcTime(KaitaiStream _io, Signing.MsgCertificateChain _parent, Signing _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.year = this._io.readU2le();
            this.month = this._io.readU1();
            this.day = this._io.readU1();
            this.hours = this._io.readU1();
            this.minutes = this._io.readU1();
            this.seconds = this._io.readU1();
            this.ns = this._io.readU4le();
        }
        private int year;
        private int month;
        private int day;
        private int hours;
        private int minutes;
        private int seconds;
        private long ns;
        private Signing _root;
        private Signing.MsgCertificateChain _parent;

        /**
         * Year
         */
        public int year() { return year; }

        /**
         * Month (range 1 .. 12)
         */
        public int month() { return month; }

        /**
         * days in the month (range 1-31)
         */
        public int day() { return day; }

        /**
         * hours of day (range 0-23)
         */
        public int hours() { return hours; }

        /**
         * minutes of hour (range 0-59)
         */
        public int minutes() { return minutes; }

        /**
         * seconds of minute (range 0-60) rounded down
         */
        public int seconds() { return seconds; }

        /**
         * nanoseconds of second (range 0-999999999)
         */
        public long ns() { return ns; }
        public Signing _root() { return _root; }
        public Signing.MsgCertificateChain _parent() { return _parent; }
    }
    public static class MsgEd25519SignatureDepA extends KaitaiStruct {
        public static MsgEd25519SignatureDepA fromFile(String fileName) throws IOException {
            return new MsgEd25519SignatureDepA(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEd25519SignatureDepA(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEd25519SignatureDepA(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEd25519SignatureDepA(KaitaiStream _io, Sbp.Message _parent, Signing _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.signature = new ArrayList<Integer>();
            for (int i = 0; i < 64; i++) {
                this.signature.add(this._io.readU1());
            }
            this.fingerprint = new ArrayList<Integer>();
            for (int i = 0; i < 20; i++) {
                this.fingerprint.add(this._io.readU1());
            }
            this.signedMessages = new ArrayList<Long>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.signedMessages.add(this._io.readU4le());
                    i++;
                }
            }
        }
        private ArrayList<Integer> signature;
        private ArrayList<Integer> fingerprint;
        private ArrayList<Long> signedMessages;
        private Signing _root;
        private Sbp.Message _parent;

        /**
         * ED25519 signature for messages.
         */
        public ArrayList<Integer> signature() { return signature; }

        /**
         * SHA-1 fingerprint of the associated certificate.
         */
        public ArrayList<Integer> fingerprint() { return fingerprint; }

        /**
         * CRCs of signed messages.
         */
        public ArrayList<Long> signedMessages() { return signedMessages; }
        public Signing _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    public static class MsgCertificateChain extends KaitaiStruct {
        public static MsgCertificateChain fromFile(String fileName) throws IOException {
            return new MsgCertificateChain(new ByteBufferKaitaiStream(fileName));
        }

        public MsgCertificateChain(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgCertificateChain(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgCertificateChain(KaitaiStream _io, Sbp.Message _parent, Signing _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.rootCertificate = new ArrayList<Integer>();
            for (int i = 0; i < 20; i++) {
                this.rootCertificate.add(this._io.readU1());
            }
            this.intermediateCertificate = new ArrayList<Integer>();
            for (int i = 0; i < 20; i++) {
                this.intermediateCertificate.add(this._io.readU1());
            }
            this.correctionsCertificate = new ArrayList<Integer>();
            for (int i = 0; i < 20; i++) {
                this.correctionsCertificate.add(this._io.readU1());
            }
            this.expiration = new UtcTime(this._io, this, _root);
            this.signature = new ArrayList<Integer>();
            for (int i = 0; i < 64; i++) {
                this.signature.add(this._io.readU1());
            }
        }
        private ArrayList<Integer> rootCertificate;
        private ArrayList<Integer> intermediateCertificate;
        private ArrayList<Integer> correctionsCertificate;
        private UtcTime expiration;
        private ArrayList<Integer> signature;
        private Signing _root;
        private Sbp.Message _parent;

        /**
         * SHA-1 fingerprint of the root certificate
         */
        public ArrayList<Integer> rootCertificate() { return rootCertificate; }

        /**
         * SHA-1 fingerprint of the intermediate certificate
         */
        public ArrayList<Integer> intermediateCertificate() { return intermediateCertificate; }

        /**
         * SHA-1 fingerprint of the corrections certificate
         */
        public ArrayList<Integer> correctionsCertificate() { return correctionsCertificate; }

        /**
         * The certificate chain comprised of three fingerprints: root
         * certificate, intermediate certificate and corrections certificate.
         */
        public UtcTime expiration() { return expiration; }

        /**
         * An ECDSA signature (created by the root certificate) over the
         * concatenation of the SBP payload bytes preceding this field. That
         * is, the concatenation of `root_certificate`,
         * `intermediate_certificate`, `corrections_certificate` and
         * `expiration`.  This certificate chain (allow list) can also be
         * validated by fetching it from `http(s)://certs.swiftnav.com/chain`.
         */
        public ArrayList<Integer> signature() { return signature; }
        public Signing _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * A DER encoded x.509 ECDSA-256 certificate (using curve secp256r1).
     */
    public static class MsgEcdsaCertificate extends KaitaiStruct {
        public static MsgEcdsaCertificate fromFile(String fileName) throws IOException {
            return new MsgEcdsaCertificate(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEcdsaCertificate(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEcdsaCertificate(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEcdsaCertificate(KaitaiStream _io, Sbp.Message _parent, Signing _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.nMsg = this._io.readU1();
            this.certificateId = new ArrayList<Integer>();
            for (int i = 0; i < 4; i++) {
                this.certificateId.add(this._io.readU1());
            }
            this.flags = this._io.readU1();
            this.certificateBytes = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.certificateBytes.add(this._io.readU1());
                    i++;
                }
            }
        }
        private int nMsg;
        private ArrayList<Integer> certificateId;
        private int flags;
        private ArrayList<Integer> certificateBytes;
        private Signing _root;
        private Sbp.Message _parent;

        /**
         * Total number messages that make up the certificate. The first nibble
         * (mask 0xF0 or left shifted by 4 bits) is the size of the sequence
         * (n), second nibble (mask 0x0F) is the zero-indexed counter (ith
         * packet of n).
         */
        public int nMsg() { return nMsg; }

        /**
         * The last 4 bytes of the certificate's SHA-1 fingerprint
         */
        public ArrayList<Integer> certificateId() { return certificateId; }
        public int flags() { return flags; }

        /**
         * DER encoded x.509 ECDSA certificate bytes
         */
        public ArrayList<Integer> certificateBytes() { return certificateBytes; }
        public Signing _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }

    /**
     * An ECDSA-256 signature using SHA-256 as the message digest algorithm.
     */
    public static class MsgEcdsaSignature extends KaitaiStruct {
        public static MsgEcdsaSignature fromFile(String fileName) throws IOException {
            return new MsgEcdsaSignature(new ByteBufferKaitaiStream(fileName));
        }

        public MsgEcdsaSignature(KaitaiStream _io) {
            this(_io, null, null);
        }

        public MsgEcdsaSignature(KaitaiStream _io, Sbp.Message _parent) {
            this(_io, _parent, null);
        }

        public MsgEcdsaSignature(KaitaiStream _io, Sbp.Message _parent, Signing _root) {
            super(_io);
            this._parent = _parent;
            this._root = _root;
            _read();
        }
        private void _read() {
            this.flags = this._io.readU1();
            this.streamCounter = this._io.readU1();
            this.onDemandCounter = this._io.readU1();
            this.certificateId = new ArrayList<Integer>();
            for (int i = 0; i < 4; i++) {
                this.certificateId.add(this._io.readU1());
            }
            this.signature = new ArrayList<Integer>();
            for (int i = 0; i < 64; i++) {
                this.signature.add(this._io.readU1());
            }
            this.signedMessages = new ArrayList<Integer>();
            {
                int i = 0;
                while (!this._io.isEof()) {
                    this.signedMessages.add(this._io.readU1());
                    i++;
                }
            }
        }
        private int flags;
        private int streamCounter;
        private int onDemandCounter;
        private ArrayList<Integer> certificateId;
        private ArrayList<Integer> signature;
        private ArrayList<Integer> signedMessages;
        private Signing _root;
        private Sbp.Message _parent;

        /**
         * Describes the format of the `signed\_messages` field below.
         */
        public int flags() { return flags; }

        /**
         * Signature message counter. Zero indexed and incremented with each
         * signature message.  The counter will not increment if this message
         * was in response to an on demand request.  The counter will roll over
         * after 256 messages. Upon connection, the value of the counter may
         * not initially be zero.
         */
        public int streamCounter() { return streamCounter; }

        /**
         * On demand message counter. Zero indexed and incremented with each
         * signature message sent in response to an on demand message. The
         * counter will roll over after 256 messages.  Upon connection, the
         * value of the counter may not initially be zero.
         */
        public int onDemandCounter() { return onDemandCounter; }

        /**
         * The last 4 bytes of the certificate's SHA-1 fingerprint
         */
        public ArrayList<Integer> certificateId() { return certificateId; }

        /**
         * ECDSA signature for the messages using SHA-256 as the digest
         * algorithm.
         */
        public ArrayList<Integer> signature() { return signature; }

        /**
         * CRCs of the messages covered by this signature.  For Skylark, which
         * delivers SBP messages wrapped in Swift's proprietary RTCM message,
         * these are the 24-bit CRCs from the RTCM message framing. For SBP
         * only streams, this will be 16-bit CRCs from the SBP framing.  See
         * the `flags` field to determine the type of CRCs covered.
         */
        public ArrayList<Integer> signedMessages() { return signedMessages; }
        public Signing _root() { return _root; }
        public Sbp.Message _parent() { return _parent; }
    }
    private Signing _root;
    private KaitaiStruct _parent;
    public Signing _root() { return _root; }
    public KaitaiStruct _parent() { return _parent; }
}
