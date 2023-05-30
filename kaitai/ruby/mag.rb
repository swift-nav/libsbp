# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Mag < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # Raw data from the magnetometer.
  class MsgMagRaw < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @tow_f = @_io.read_u1
      @mag_x = @_io.read_s2le
      @mag_y = @_io.read_s2le
      @mag_z = @_io.read_s2le
      self
    end

    ##
    # Milliseconds since start of GPS week. If the high bit is set, the
    # time is unknown or invalid.
    attr_reader :tow

    ##
    # Milliseconds since start of GPS week, fractional part
    attr_reader :tow_f

    ##
    # Magnetic field in the body frame X axis
    attr_reader :mag_x

    ##
    # Magnetic field in the body frame Y axis
    attr_reader :mag_y

    ##
    # Magnetic field in the body frame Z axis
    attr_reader :mag_z
  end
end
