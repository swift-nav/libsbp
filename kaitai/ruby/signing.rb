# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Signing < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # Deprecated.
  class MsgCertificateChainDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @root_certificate = []
      (20).times { |i|
        @root_certificate << @_io.read_u1
      }
      @intermediate_certificate = []
      (20).times { |i|
        @intermediate_certificate << @_io.read_u1
      }
      @corrections_certificate = []
      (20).times { |i|
        @corrections_certificate << @_io.read_u1
      }
      @expiration = UtcTime.new(@_io, self, @_root)
      @signature = []
      (64).times { |i|
        @signature << @_io.read_u1
      }
      self
    end

    ##
    # SHA-1 fingerprint of the root certificate
    attr_reader :root_certificate

    ##
    # SHA-1 fingerprint of the intermediate certificate
    attr_reader :intermediate_certificate

    ##
    # SHA-1 fingerprint of the corrections certificate
    attr_reader :corrections_certificate

    ##
    # The certificate chain comprised of three fingerprints: root
    # certificate, intermediate certificate and corrections certificate.
    attr_reader :expiration

    ##
    # An ECDSA signature (created by the root certificate) over the
    # concatenation of the SBP payload bytes preceding this field. That
    # is, the concatenation of `root_certificate`,
    # `intermediate_certificate`, `corrections_certificate` and
    # `expiration`.  This certificate chain (allow list) can also be
    # validated by fetching it from `http(s)://certs.swiftnav.com/chain`.
    attr_reader :signature
  end

  ##
  # Deprecated.
  class MsgEd25519SignatureDepB < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @stream_counter = @_io.read_u1
      @on_demand_counter = @_io.read_u1
      @signature = []
      (64).times { |i|
        @signature << @_io.read_u1
      }
      @fingerprint = []
      (20).times { |i|
        @fingerprint << @_io.read_u1
      }
      @signed_messages = []
      i = 0
      while not @_io.eof?
        @signed_messages << @_io.read_u4le
        i += 1
      end
      self
    end

    ##
    # Signature message counter. Zero indexed and incremented with each
    # signature message.  The counter will not increment if this message
    # was in response to an on demand request.  The counter will roll over
    # after 256 messages. Upon connection, the value of the counter may
    # not initially be zero.
    attr_reader :stream_counter

    ##
    # On demand message counter. Zero indexed and incremented with each
    # signature message sent in response to an on demand message. The
    # counter will roll over after 256 messages.  Upon connection, the
    # value of the counter may not initially be zero.
    attr_reader :on_demand_counter

    ##
    # ED25519 signature for messages.
    attr_reader :signature

    ##
    # SHA-1 fingerprint of the associated certificate.
    attr_reader :fingerprint

    ##
    # CRCs of signed messages.
    attr_reader :signed_messages
  end

  ##
  # Deprecated.
  class MsgEd25519CertificateDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @n_msg = @_io.read_u1
      @fingerprint = []
      (20).times { |i|
        @fingerprint << @_io.read_u1
      }
      @certificate_bytes = []
      i = 0
      while not @_io.eof?
        @certificate_bytes << @_io.read_u1
        i += 1
      end
      self
    end

    ##
    # Total number messages that make up the certificate. First nibble is
    # the size of the sequence (n), second nibble is the zero-indexed
    # counter (ith packet of n)
    attr_reader :n_msg

    ##
    # SHA-1 fingerprint of the associated certificate.
    attr_reader :fingerprint

    ##
    # ED25519 certificate bytes.
    attr_reader :certificate_bytes
  end
  class UtcTime < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @year = @_io.read_u2le
      @month = @_io.read_u1
      @day = @_io.read_u1
      @hours = @_io.read_u1
      @minutes = @_io.read_u1
      @seconds = @_io.read_u1
      @ns = @_io.read_u4le
      self
    end

    ##
    # Year
    attr_reader :year

    ##
    # Month (range 1 .. 12)
    attr_reader :month

    ##
    # days in the month (range 1-31)
    attr_reader :day

    ##
    # hours of day (range 0-23)
    attr_reader :hours

    ##
    # minutes of hour (range 0-59)
    attr_reader :minutes

    ##
    # seconds of minute (range 0-60) rounded down
    attr_reader :seconds

    ##
    # nanoseconds of second (range 0-999999999)
    attr_reader :ns
  end
  class EcdsaSignature < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @len = @_io.read_u1
      @data = []
      (72).times { |i|
        @data << @_io.read_u1
      }
      self
    end

    ##
    # Number of bytes to use of the signature field.  The DER encoded
    # signature has a maximum size of 72 bytes but can vary between 70 and
    # 72 bytes in length.
    attr_reader :len

    ##
    # DER encoded ECDSA signature for the messages using SHA-256 as the
    # digest algorithm.
    attr_reader :data
  end

  ##
  # Deprecated.
  class MsgEd25519SignatureDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @signature = []
      (64).times { |i|
        @signature << @_io.read_u1
      }
      @fingerprint = []
      (20).times { |i|
        @fingerprint << @_io.read_u1
      }
      @signed_messages = []
      i = 0
      while not @_io.eof?
        @signed_messages << @_io.read_u4le
        i += 1
      end
      self
    end

    ##
    # ED25519 signature for messages.
    attr_reader :signature

    ##
    # SHA-1 fingerprint of the associated certificate.
    attr_reader :fingerprint

    ##
    # CRCs of signed messages.
    attr_reader :signed_messages
  end
  class MsgCertificateChain < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @root_certificate = []
      (20).times { |i|
        @root_certificate << @_io.read_u1
      }
      @intermediate_certificate = []
      (20).times { |i|
        @intermediate_certificate << @_io.read_u1
      }
      @corrections_certificate = []
      (20).times { |i|
        @corrections_certificate << @_io.read_u1
      }
      @expiration = UtcTime.new(@_io, self, @_root)
      @signature = EcdsaSignature.new(@_io, self, @_root)
      self
    end

    ##
    # SHA-1 fingerprint of the root certificate
    attr_reader :root_certificate

    ##
    # SHA-1 fingerprint of the intermediate certificate
    attr_reader :intermediate_certificate

    ##
    # SHA-1 fingerprint of the corrections certificate
    attr_reader :corrections_certificate

    ##
    # The time after which the signature given is no longer valid.
    # Implementors should consult a time source (such as GNSS) to check if
    # the current time is later than the expiration time, if the condition
    # is true, signatures in the stream should not be considered valid.
    attr_reader :expiration

    ##
    # Signature (created by the root certificate) over the concatenation
    # of the SBP payload bytes preceding this field. That is, the
    # concatenation of `root_certificate`, `intermediate_certificate`,
    # `corrections_certificate` and `expiration`.  This certificate chain
    # (allow list) can also be validated by fetching it from
    # `http(s)://certs.swiftnav.com/chain`.
    attr_reader :signature
  end

  ##
  # A DER encoded x.509 ECDSA-256 certificate (using curve secp256r1).
  class MsgEcdsaCertificate < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @n_msg = @_io.read_u1
      @certificate_id = []
      (4).times { |i|
        @certificate_id << @_io.read_u1
      }
      @flags = @_io.read_u1
      @certificate_bytes = []
      i = 0
      while not @_io.eof?
        @certificate_bytes << @_io.read_u1
        i += 1
      end
      self
    end

    ##
    # Total number messages that make up the certificate. The first nibble
    # (mask 0xF0 or left shifted by 4 bits) is the size of the sequence
    # (n), second nibble (mask 0x0F) is the zero-indexed counter (ith
    # packet of n).
    attr_reader :n_msg

    ##
    # The last 4 bytes of the certificate's SHA-1 fingerprint
    attr_reader :certificate_id
    attr_reader :flags

    ##
    # DER encoded x.509 ECDSA certificate bytes
    attr_reader :certificate_bytes
  end

  ##
  # Deprecated.
  class MsgEcdsaSignatureDepB < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @flags = @_io.read_u1
      @stream_counter = @_io.read_u1
      @on_demand_counter = @_io.read_u1
      @certificate_id = []
      (4).times { |i|
        @certificate_id << @_io.read_u1
      }
      @n_signature_bytes = @_io.read_u1
      @signature = []
      (72).times { |i|
        @signature << @_io.read_u1
      }
      @signed_messages = []
      i = 0
      while not @_io.eof?
        @signed_messages << @_io.read_u1
        i += 1
      end
      self
    end

    ##
    # Describes the format of the `signed\_messages` field below.
    attr_reader :flags

    ##
    # Signature message counter. Zero indexed and incremented with each
    # signature message.  The counter will not increment if this message
    # was in response to an on demand request.  The counter will roll over
    # after 256 messages. Upon connection, the value of the counter may
    # not initially be zero.
    attr_reader :stream_counter

    ##
    # On demand message counter. Zero indexed and incremented with each
    # signature message sent in response to an on demand message. The
    # counter will roll over after 256 messages.  Upon connection, the
    # value of the counter may not initially be zero.
    attr_reader :on_demand_counter

    ##
    # The last 4 bytes of the certificate's SHA-1 fingerprint
    attr_reader :certificate_id

    ##
    # Number of bytes to use of the signature field.  The DER encoded
    # signature has a maximum size of 72 bytes but can vary between 70 and
    # 72 bytes in length.
    attr_reader :n_signature_bytes

    ##
    # DER encoded ECDSA signature for the messages using SHA-256 as the
    # digest algorithm.
    attr_reader :signature

    ##
    # CRCs of the messages covered by this signature.  For Skylark, which
    # delivers SBP messages wrapped in Swift's proprietary RTCM message,
    # these are the 24-bit CRCs from the RTCM message framing. For SBP
    # only streams, this will be 16-bit CRCs from the SBP framing.  See
    # the `flags` field to determine the type of CRCs covered.
    attr_reader :signed_messages
  end

  ##
  # An ECDSA-256 signature using SHA-256 as the message digest algorithm.
  class MsgEcdsaSignature < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @flags = @_io.read_u1
      @stream_counter = @_io.read_u1
      @on_demand_counter = @_io.read_u1
      @certificate_id = []
      (4).times { |i|
        @certificate_id << @_io.read_u1
      }
      @signature = EcdsaSignature.new(@_io, self, @_root)
      @signed_messages = []
      i = 0
      while not @_io.eof?
        @signed_messages << @_io.read_u1
        i += 1
      end
      self
    end

    ##
    # Describes the format of the `signed\_messages` field below.
    attr_reader :flags

    ##
    # Signature message counter. Zero indexed and incremented with each
    # signature message.  The counter will not increment if this message
    # was in response to an on demand request.  The counter will roll over
    # after 256 messages. Upon connection, the value of the counter may
    # not initially be zero.
    attr_reader :stream_counter

    ##
    # On demand message counter. Zero indexed and incremented with each
    # signature message sent in response to an on demand message. The
    # counter will roll over after 256 messages.  Upon connection, the
    # value of the counter may not initially be zero.
    attr_reader :on_demand_counter

    ##
    # The last 4 bytes of the certificate's SHA-1 fingerprint
    attr_reader :certificate_id

    ##
    # Signature over the frames of this message group.
    attr_reader :signature

    ##
    # CRCs of the messages covered by this signature.  For Skylark, which
    # delivers SBP messages wrapped in Swift's proprietary RTCM message,
    # these are the 24-bit CRCs from the RTCM message framing. For SBP
    # only streams, this will be 16-bit CRCs from the SBP framing.  See
    # the `flags` field to determine the type of CRCs covered.
    attr_reader :signed_messages
  end

  ##
  # Deprecated.
  class MsgEcdsaSignatureDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @flags = @_io.read_u1
      @stream_counter = @_io.read_u1
      @on_demand_counter = @_io.read_u1
      @certificate_id = []
      (4).times { |i|
        @certificate_id << @_io.read_u1
      }
      @signature = []
      (64).times { |i|
        @signature << @_io.read_u1
      }
      @signed_messages = []
      i = 0
      while not @_io.eof?
        @signed_messages << @_io.read_u1
        i += 1
      end
      self
    end

    ##
    # Describes the format of the `signed\_messages` field below.
    attr_reader :flags

    ##
    # Signature message counter. Zero indexed and incremented with each
    # signature message.  The counter will not increment if this message
    # was in response to an on demand request.  The counter will roll over
    # after 256 messages. Upon connection, the value of the counter may
    # not initially be zero.
    attr_reader :stream_counter

    ##
    # On demand message counter. Zero indexed and incremented with each
    # signature message sent in response to an on demand message. The
    # counter will roll over after 256 messages.  Upon connection, the
    # value of the counter may not initially be zero.
    attr_reader :on_demand_counter

    ##
    # The last 4 bytes of the certificate's SHA-1 fingerprint
    attr_reader :certificate_id

    ##
    # ECDSA signature for the messages using SHA-256 as the digest
    # algorithm.
    attr_reader :signature

    ##
    # CRCs of the messages covered by this signature.  For Skylark, which
    # delivers SBP messages wrapped in Swift's proprietary RTCM message,
    # these are the 24-bit CRCs from the RTCM message framing. For SBP
    # only streams, this will be 16-bit CRCs from the SBP framing.  See
    # the `flags` field to determine the type of CRCs covered.
    attr_reader :signed_messages
  end
end
