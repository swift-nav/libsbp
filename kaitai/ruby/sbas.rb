# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Sbas < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # This message is sent once per second per SBAS satellite. ME checks the
  # parity of the data block and sends only blocks that pass the check.
  class MsgSbasRaw < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @tow = @_io.read_u4le
      @message_type = @_io.read_u1
      @data = []
      (27).times { |i|
        @data << @_io.read_u1
      }
      self
    end

    ##
    # GNSS signal identifier.
    attr_reader :sid

    ##
    # GPS time-of-week at the start of the data block.
    attr_reader :tow

    ##
    # SBAS message type (0-63)
    attr_reader :message_type

    ##
    # Raw SBAS data field of 212 bits (last byte padded with zeros).
    attr_reader :data
  end
end
