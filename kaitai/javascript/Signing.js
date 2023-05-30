// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

(function (root, factory) {
  if (typeof define === 'function' && define.amd) {
    define(['kaitai-struct/KaitaiStream'], factory);
  } else if (typeof module === 'object' && module.exports) {
    module.exports = factory(require('kaitai-struct/KaitaiStream'));
  } else {
    root.Signing = factory(root.KaitaiStream);
  }
}(typeof self !== 'undefined' ? self : this, function (KaitaiStream) {
var Signing = (function() {
  function Signing(_io, _parent, _root) {
    this._io = _io;
    this._parent = _parent;
    this._root = _root || this;

    this._read();
  }
  Signing.prototype._read = function() {
  }

  var MsgEd25519SignatureDepB = Signing.MsgEd25519SignatureDepB = (function() {
    function MsgEd25519SignatureDepB(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEd25519SignatureDepB.prototype._read = function() {
      this.streamCounter = this._io.readU1();
      this.onDemandCounter = this._io.readU1();
      this.signature = [];
      for (var i = 0; i < 64; i++) {
        this.signature.push(this._io.readU1());
      }
      this.fingerprint = [];
      for (var i = 0; i < 20; i++) {
        this.fingerprint.push(this._io.readU1());
      }
      this.signedMessages = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.signedMessages.push(this._io.readU4le());
        i++;
      }
    }

    /**
     * Signature message counter. Zero indexed and incremented with each
     * signature message.  The counter will not increment if this message
     * was in response to an on demand request.  The counter will roll over
     * after 256 messages. Upon connection, the value of the counter may
     * not initially be zero.
     */

    /**
     * On demand message counter. Zero indexed and incremented with each
     * signature message sent in response to an on demand message. The
     * counter will roll over after 256 messages.  Upon connection, the
     * value of the counter may not initially be zero.
     */

    /**
     * ED25519 signature for messages.
     */

    /**
     * SHA-1 fingerprint of the associated certificate.
     */

    /**
     * CRCs of signed messages.
     */

    return MsgEd25519SignatureDepB;
  })();

  var MsgEd25519CertificateDep = Signing.MsgEd25519CertificateDep = (function() {
    function MsgEd25519CertificateDep(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEd25519CertificateDep.prototype._read = function() {
      this.nMsg = this._io.readU1();
      this.fingerprint = [];
      for (var i = 0; i < 20; i++) {
        this.fingerprint.push(this._io.readU1());
      }
      this.certificateBytes = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.certificateBytes.push(this._io.readU1());
        i++;
      }
    }

    /**
     * Total number messages that make up the certificate. First nibble is
     * the size of the sequence (n), second nibble is the zero-indexed
     * counter (ith packet of n)
     */

    /**
     * SHA-1 fingerprint of the associated certificate.
     */

    /**
     * ED25519 certificate bytes.
     */

    return MsgEd25519CertificateDep;
  })();

  var UtcTime = Signing.UtcTime = (function() {
    function UtcTime(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    UtcTime.prototype._read = function() {
      this.year = this._io.readU2le();
      this.month = this._io.readU1();
      this.day = this._io.readU1();
      this.hours = this._io.readU1();
      this.minutes = this._io.readU1();
      this.seconds = this._io.readU1();
      this.ns = this._io.readU4le();
    }

    /**
     * Year
     */

    /**
     * Month (range 1 .. 12)
     */

    /**
     * days in the month (range 1-31)
     */

    /**
     * hours of day (range 0-23)
     */

    /**
     * minutes of hour (range 0-59)
     */

    /**
     * seconds of minute (range 0-60) rounded down
     */

    /**
     * nanoseconds of second (range 0-999999999)
     */

    return UtcTime;
  })();

  var MsgEd25519SignatureDepA = Signing.MsgEd25519SignatureDepA = (function() {
    function MsgEd25519SignatureDepA(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEd25519SignatureDepA.prototype._read = function() {
      this.signature = [];
      for (var i = 0; i < 64; i++) {
        this.signature.push(this._io.readU1());
      }
      this.fingerprint = [];
      for (var i = 0; i < 20; i++) {
        this.fingerprint.push(this._io.readU1());
      }
      this.signedMessages = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.signedMessages.push(this._io.readU4le());
        i++;
      }
    }

    /**
     * ED25519 signature for messages.
     */

    /**
     * SHA-1 fingerprint of the associated certificate.
     */

    /**
     * CRCs of signed messages.
     */

    return MsgEd25519SignatureDepA;
  })();

  var MsgCertificateChain = Signing.MsgCertificateChain = (function() {
    function MsgCertificateChain(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgCertificateChain.prototype._read = function() {
      this.rootCertificate = [];
      for (var i = 0; i < 20; i++) {
        this.rootCertificate.push(this._io.readU1());
      }
      this.intermediateCertificate = [];
      for (var i = 0; i < 20; i++) {
        this.intermediateCertificate.push(this._io.readU1());
      }
      this.correctionsCertificate = [];
      for (var i = 0; i < 20; i++) {
        this.correctionsCertificate.push(this._io.readU1());
      }
      this.expiration = new UtcTime(this._io, this, this._root);
      this.signature = [];
      for (var i = 0; i < 64; i++) {
        this.signature.push(this._io.readU1());
      }
    }

    /**
     * SHA-1 fingerprint of the root certificate
     */

    /**
     * SHA-1 fingerprint of the intermediate certificate
     */

    /**
     * SHA-1 fingerprint of the corrections certificate
     */

    /**
     * The certificate chain comprised of three fingerprints: root
     * certificate, intermediate certificate and corrections certificate.
     */

    /**
     * An ECDSA signature (created by the root certificate) over the
     * concatenation of the SBP payload bytes preceding this field. That
     * is, the concatenation of `root_certificate`,
     * `intermediate_certificate`, `corrections_certificate` and
     * `expiration`.  This certificate chain (allow list) can also be
     * validated by fetching it from `http(s)://certs.swiftnav.com/chain`.
     */

    return MsgCertificateChain;
  })();

  /**
   * A DER encoded x.509 ECDSA-256 certificate (using curve secp256r1).
   */

  var MsgEcdsaCertificate = Signing.MsgEcdsaCertificate = (function() {
    function MsgEcdsaCertificate(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEcdsaCertificate.prototype._read = function() {
      this.nMsg = this._io.readU1();
      this.certificateId = [];
      for (var i = 0; i < 4; i++) {
        this.certificateId.push(this._io.readU1());
      }
      this.flags = this._io.readU1();
      this.certificateBytes = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.certificateBytes.push(this._io.readU1());
        i++;
      }
    }

    /**
     * Total number messages that make up the certificate. The first nibble
     * (mask 0xF0 or left shifted by 4 bits) is the size of the sequence
     * (n), second nibble (mask 0x0F) is the zero-indexed counter (ith
     * packet of n).
     */

    /**
     * The last 4 bytes of the certificate's SHA-1 fingerprint
     */

    /**
     * DER encoded x.509 ECDSA certificate bytes
     */

    return MsgEcdsaCertificate;
  })();

  /**
   * An ECDSA-256 signature using SHA-256 as the message digest algorithm.
   */

  var MsgEcdsaSignature = Signing.MsgEcdsaSignature = (function() {
    function MsgEcdsaSignature(_io, _parent, _root) {
      this._io = _io;
      this._parent = _parent;
      this._root = _root || this;

      this._read();
    }
    MsgEcdsaSignature.prototype._read = function() {
      this.flags = this._io.readU1();
      this.streamCounter = this._io.readU1();
      this.onDemandCounter = this._io.readU1();
      this.certificateId = [];
      for (var i = 0; i < 4; i++) {
        this.certificateId.push(this._io.readU1());
      }
      this.signature = [];
      for (var i = 0; i < 64; i++) {
        this.signature.push(this._io.readU1());
      }
      this.signedMessages = [];
      var i = 0;
      while (!this._io.isEof()) {
        this.signedMessages.push(this._io.readU1());
        i++;
      }
    }

    /**
     * Describes the format of the `signed\_messages` field below.
     */

    /**
     * Signature message counter. Zero indexed and incremented with each
     * signature message.  The counter will not increment if this message
     * was in response to an on demand request.  The counter will roll over
     * after 256 messages. Upon connection, the value of the counter may
     * not initially be zero.
     */

    /**
     * On demand message counter. Zero indexed and incremented with each
     * signature message sent in response to an on demand message. The
     * counter will roll over after 256 messages.  Upon connection, the
     * value of the counter may not initially be zero.
     */

    /**
     * The last 4 bytes of the certificate's SHA-1 fingerprint
     */

    /**
     * ECDSA signature for the messages using SHA-256 as the digest
     * algorithm.
     */

    /**
     * CRCs of the messages covered by this signature.  For Skylark, which
     * delivers SBP messages wrapped in Swift's proprietary RTCM message,
     * these are the 24-bit CRCs from the RTCM message framing. For SBP
     * only streams, this will be 16-bit CRCs from the SBP framing.  See
     * the `flags` field to determine the type of CRCs covered.
     */

    return MsgEcdsaSignature;
  })();

  return Signing;
})();
return Signing;
}));
