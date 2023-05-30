<?php
// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

namespace {
    class Signing extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Kaitai\Struct\Struct $_parent = null, \Signing $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
        }
    }
}

namespace Signing {
    class MsgEd25519SignatureDepB extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Signing $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_streamCounter = $this->_io->readU1();
            $this->_m_onDemandCounter = $this->_io->readU1();
            $this->_m_signature = [];
            $n = 64;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_signature[] = $this->_io->readU1();
            }
            $this->_m_fingerprint = [];
            $n = 20;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_fingerprint[] = $this->_io->readU1();
            }
            $this->_m_signedMessages = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_signedMessages[] = $this->_io->readU4le();
                $i++;
            }
        }
        protected $_m_streamCounter;
        protected $_m_onDemandCounter;
        protected $_m_signature;
        protected $_m_fingerprint;
        protected $_m_signedMessages;

        /**
         * Signature message counter. Zero indexed and incremented with each
         * signature message.  The counter will not increment if this message
         * was in response to an on demand request.  The counter will roll over
         * after 256 messages. Upon connection, the value of the counter may
         * not initially be zero.
         */
        public function streamCounter() { return $this->_m_streamCounter; }

        /**
         * On demand message counter. Zero indexed and incremented with each
         * signature message sent in response to an on demand message. The
         * counter will roll over after 256 messages.  Upon connection, the
         * value of the counter may not initially be zero.
         */
        public function onDemandCounter() { return $this->_m_onDemandCounter; }

        /**
         * ED25519 signature for messages.
         */
        public function signature() { return $this->_m_signature; }

        /**
         * SHA-1 fingerprint of the associated certificate.
         */
        public function fingerprint() { return $this->_m_fingerprint; }

        /**
         * CRCs of signed messages.
         */
        public function signedMessages() { return $this->_m_signedMessages; }
    }
}

namespace Signing {
    class MsgEd25519CertificateDep extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Signing $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_nMsg = $this->_io->readU1();
            $this->_m_fingerprint = [];
            $n = 20;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_fingerprint[] = $this->_io->readU1();
            }
            $this->_m_certificateBytes = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_certificateBytes[] = $this->_io->readU1();
                $i++;
            }
        }
        protected $_m_nMsg;
        protected $_m_fingerprint;
        protected $_m_certificateBytes;

        /**
         * Total number messages that make up the certificate. First nibble is
         * the size of the sequence (n), second nibble is the zero-indexed
         * counter (ith packet of n)
         */
        public function nMsg() { return $this->_m_nMsg; }

        /**
         * SHA-1 fingerprint of the associated certificate.
         */
        public function fingerprint() { return $this->_m_fingerprint; }

        /**
         * ED25519 certificate bytes.
         */
        public function certificateBytes() { return $this->_m_certificateBytes; }
    }
}

namespace Signing {
    class UtcTime extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Signing\MsgCertificateChain $_parent = null, \Signing $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_year = $this->_io->readU2le();
            $this->_m_month = $this->_io->readU1();
            $this->_m_day = $this->_io->readU1();
            $this->_m_hours = $this->_io->readU1();
            $this->_m_minutes = $this->_io->readU1();
            $this->_m_seconds = $this->_io->readU1();
            $this->_m_ns = $this->_io->readU4le();
        }
        protected $_m_year;
        protected $_m_month;
        protected $_m_day;
        protected $_m_hours;
        protected $_m_minutes;
        protected $_m_seconds;
        protected $_m_ns;

        /**
         * Year
         */
        public function year() { return $this->_m_year; }

        /**
         * Month (range 1 .. 12)
         */
        public function month() { return $this->_m_month; }

        /**
         * days in the month (range 1-31)
         */
        public function day() { return $this->_m_day; }

        /**
         * hours of day (range 0-23)
         */
        public function hours() { return $this->_m_hours; }

        /**
         * minutes of hour (range 0-59)
         */
        public function minutes() { return $this->_m_minutes; }

        /**
         * seconds of minute (range 0-60) rounded down
         */
        public function seconds() { return $this->_m_seconds; }

        /**
         * nanoseconds of second (range 0-999999999)
         */
        public function ns() { return $this->_m_ns; }
    }
}

namespace Signing {
    class MsgEd25519SignatureDepA extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Signing $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_signature = [];
            $n = 64;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_signature[] = $this->_io->readU1();
            }
            $this->_m_fingerprint = [];
            $n = 20;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_fingerprint[] = $this->_io->readU1();
            }
            $this->_m_signedMessages = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_signedMessages[] = $this->_io->readU4le();
                $i++;
            }
        }
        protected $_m_signature;
        protected $_m_fingerprint;
        protected $_m_signedMessages;

        /**
         * ED25519 signature for messages.
         */
        public function signature() { return $this->_m_signature; }

        /**
         * SHA-1 fingerprint of the associated certificate.
         */
        public function fingerprint() { return $this->_m_fingerprint; }

        /**
         * CRCs of signed messages.
         */
        public function signedMessages() { return $this->_m_signedMessages; }
    }
}

namespace Signing {
    class MsgCertificateChain extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Signing $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_rootCertificate = [];
            $n = 20;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_rootCertificate[] = $this->_io->readU1();
            }
            $this->_m_intermediateCertificate = [];
            $n = 20;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_intermediateCertificate[] = $this->_io->readU1();
            }
            $this->_m_correctionsCertificate = [];
            $n = 20;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_correctionsCertificate[] = $this->_io->readU1();
            }
            $this->_m_expiration = new \Signing\UtcTime($this->_io, $this, $this->_root);
            $this->_m_signature = [];
            $n = 64;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_signature[] = $this->_io->readU1();
            }
        }
        protected $_m_rootCertificate;
        protected $_m_intermediateCertificate;
        protected $_m_correctionsCertificate;
        protected $_m_expiration;
        protected $_m_signature;

        /**
         * SHA-1 fingerprint of the root certificate
         */
        public function rootCertificate() { return $this->_m_rootCertificate; }

        /**
         * SHA-1 fingerprint of the intermediate certificate
         */
        public function intermediateCertificate() { return $this->_m_intermediateCertificate; }

        /**
         * SHA-1 fingerprint of the corrections certificate
         */
        public function correctionsCertificate() { return $this->_m_correctionsCertificate; }

        /**
         * The certificate chain comprised of three fingerprints: root
         * certificate, intermediate certificate and corrections certificate.
         */
        public function expiration() { return $this->_m_expiration; }

        /**
         * An ECDSA signature (created by the root certificate) over the
         * concatenation of the SBP payload bytes preceding this field. That
         * is, the concatenation of `root_certificate`,
         * `intermediate_certificate`, `corrections_certificate` and
         * `expiration`.  This certificate chain (allow list) can also be
         * validated by fetching it from `http(s)://certs.swiftnav.com/chain`.
         */
        public function signature() { return $this->_m_signature; }
    }
}

/**
 * A DER encoded x.509 ECDSA-256 certificate (using curve secp256r1).
 */

namespace Signing {
    class MsgEcdsaCertificate extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Signing $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_nMsg = $this->_io->readU1();
            $this->_m_certificateId = [];
            $n = 4;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_certificateId[] = $this->_io->readU1();
            }
            $this->_m_flags = $this->_io->readU1();
            $this->_m_certificateBytes = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_certificateBytes[] = $this->_io->readU1();
                $i++;
            }
        }
        protected $_m_nMsg;
        protected $_m_certificateId;
        protected $_m_flags;
        protected $_m_certificateBytes;

        /**
         * Total number messages that make up the certificate. The first nibble
         * (mask 0xF0 or left shifted by 4 bits) is the size of the sequence
         * (n), second nibble (mask 0x0F) is the zero-indexed counter (ith
         * packet of n).
         */
        public function nMsg() { return $this->_m_nMsg; }

        /**
         * The last 4 bytes of the certificate's SHA-1 fingerprint
         */
        public function certificateId() { return $this->_m_certificateId; }
        public function flags() { return $this->_m_flags; }

        /**
         * DER encoded x.509 ECDSA certificate bytes
         */
        public function certificateBytes() { return $this->_m_certificateBytes; }
    }
}

/**
 * An ECDSA-256 signature using SHA-256 as the message digest algorithm.
 */

namespace Signing {
    class MsgEcdsaSignature extends \Kaitai\Struct\Struct {
        public function __construct(\Kaitai\Struct\Stream $_io, \Sbp\Message $_parent = null, \Signing $_root = null) {
            parent::__construct($_io, $_parent, $_root);
            $this->_read();
        }

        private function _read() {
            $this->_m_flags = $this->_io->readU1();
            $this->_m_streamCounter = $this->_io->readU1();
            $this->_m_onDemandCounter = $this->_io->readU1();
            $this->_m_certificateId = [];
            $n = 4;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_certificateId[] = $this->_io->readU1();
            }
            $this->_m_signature = [];
            $n = 64;
            for ($i = 0; $i < $n; $i++) {
                $this->_m_signature[] = $this->_io->readU1();
            }
            $this->_m_signedMessages = [];
            $i = 0;
            while (!$this->_io->isEof()) {
                $this->_m_signedMessages[] = $this->_io->readU1();
                $i++;
            }
        }
        protected $_m_flags;
        protected $_m_streamCounter;
        protected $_m_onDemandCounter;
        protected $_m_certificateId;
        protected $_m_signature;
        protected $_m_signedMessages;

        /**
         * Describes the format of the `signed\_messages` field below.
         */
        public function flags() { return $this->_m_flags; }

        /**
         * Signature message counter. Zero indexed and incremented with each
         * signature message.  The counter will not increment if this message
         * was in response to an on demand request.  The counter will roll over
         * after 256 messages. Upon connection, the value of the counter may
         * not initially be zero.
         */
        public function streamCounter() { return $this->_m_streamCounter; }

        /**
         * On demand message counter. Zero indexed and incremented with each
         * signature message sent in response to an on demand message. The
         * counter will roll over after 256 messages.  Upon connection, the
         * value of the counter may not initially be zero.
         */
        public function onDemandCounter() { return $this->_m_onDemandCounter; }

        /**
         * The last 4 bytes of the certificate's SHA-1 fingerprint
         */
        public function certificateId() { return $this->_m_certificateId; }

        /**
         * ECDSA signature for the messages using SHA-256 as the digest
         * algorithm.
         */
        public function signature() { return $this->_m_signature; }

        /**
         * CRCs of the messages covered by this signature.  For Skylark, which
         * delivers SBP messages wrapped in Swift's proprietary RTCM message,
         * these are the 24-bit CRCs from the RTCM message framing. For SBP
         * only streams, this will be 16-bit CRCs from the SBP framing.  See
         * the `flags` field to determine the type of CRCs covered.
         */
        public function signedMessages() { return $this->_m_signedMessages; }
    }
}
