# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Logging < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # This message contains a human-readable payload string from the device
  # containing errors, warnings and informational messages at ERROR,
  # WARNING, DEBUG, INFO logging levels.
  class MsgLog < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @level = @_io.read_u1
      @text = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # Logging level
    attr_reader :level

    ##
    # Human-readable string
    attr_reader :text
  end

  ##
  # This message provides the ability to forward messages over SBP.  This
  # may take the form of wrapping up SBP messages received by Piksi for
  # logging purposes or wrapping another protocol with SBP.
  # 
  # The source identifier indicates from what interface a forwarded stream
  # derived. The protocol identifier identifies what the expected protocol
  # the forwarded msg contains. Protocol 0 represents SBP and the remaining
  # values are implementation defined.
  class MsgFwd < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @source = @_io.read_u1
      @protocol = @_io.read_u1
      @fwd_payload = []
      i = 0
      while not @_io.eof?
        @fwd_payload << @_io.read_u1
        i += 1
      end
      self
    end

    ##
    # source identifier
    attr_reader :source

    ##
    # protocol identifier
    attr_reader :protocol

    ##
    # variable length wrapped binary message
    attr_reader :fwd_payload
  end

  ##
  # Deprecated.
  class MsgPrintDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @text = (@_io.read_bytes_full).force_encoding("ascii")
      self
    end

    ##
    # Human-readable string
    attr_reader :text
  end
end
