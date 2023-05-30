# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class ExtEvents < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # Reports detection of an external event, the GPS time it occurred, which
  # pin it was and whether it was rising or falling.
  class MsgExtEvent < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @wn = @_io.read_u2le
      @tow = @_io.read_u4le
      @ns_residual = @_io.read_s4le
      @flags = @_io.read_u1
      @pin = @_io.read_u1
      self
    end

    ##
    # GPS week number
    attr_reader :wn

    ##
    # GPS time of week rounded to the nearest millisecond
    attr_reader :tow

    ##
    # Nanosecond residual of millisecond-rounded TOW (ranges from -500000
    # to 500000)
    attr_reader :ns_residual

    ##
    # Flags
    attr_reader :flags

    ##
    # Pin number.  0..9 = DEBUG0..9.
    attr_reader :pin
  end
end
