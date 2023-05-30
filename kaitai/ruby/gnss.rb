# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Gnss < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # Deprecated.
  class GnssSignalDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sat = @_io.read_u2le
      @code = @_io.read_u1
      @reserved = @_io.read_u1
      self
    end

    ##
    # Constellation-specific satellite identifier.
    # 
    # Note: unlike GnssSignal, GPS satellites are encoded as (PRN - 1).
    # Other constellations do not have this offset.
    attr_reader :sat

    ##
    # Signal constellation, band and code
    attr_reader :code

    ##
    # Reserved
    attr_reader :reserved
  end

  ##
  # Carrier phase measurement in cycles represented as a 40-bit fixed point
  # number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
  # fractional cycles. This phase has the same sign as the pseudorange.
  class CarrierPhase < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @i = @_io.read_s4le
      @f = @_io.read_u1
      self
    end

    ##
    # Carrier phase whole cycles
    attr_reader :i

    ##
    # Carrier phase fractional part
    attr_reader :f
  end

  ##
  # A wire-appropriate GPS time, defined as the number of milliseconds since
  # beginning of the week on the Saturday/Sunday transition.
  class GpsTimeDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @wn = @_io.read_u2le
      self
    end

    ##
    # Milliseconds since start of GPS week
    attr_reader :tow

    ##
    # GPS week number
    attr_reader :wn
  end

  ##
  # Signal identifier containing constellation, band, and satellite
  # identifier.
  class GnssSignal < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sat = @_io.read_u1
      @code = @_io.read_u1
      self
    end

    ##
    # Constellation-specific satellite id. For GLO can either be (100+FCN)
    # where FCN is in [-7,+6] or the Slot ID in [1,28].
    attr_reader :sat

    ##
    # Signal constellation, band and code
    attr_reader :code
  end

  ##
  # A wire-appropriate receiver clock time, defined as the time since the
  # beginning of the week on the Saturday/Sunday transition. In most cases,
  # observations are epoch aligned so ns field will be 0.
  class GpsTime < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @ns_residual = @_io.read_s4le
      @wn = @_io.read_u2le
      self
    end

    ##
    # Milliseconds since start of GPS week
    attr_reader :tow

    ##
    # Nanosecond residual of millisecond-rounded TOW (ranges from -500000
    # to 500000)
    attr_reader :ns_residual

    ##
    # GPS week number
    attr_reader :wn
  end

  ##
  # A GPS time, defined as the number of seconds since beginning of the week
  # on the Saturday/Sunday transition.
  class GpsTimeSec < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @wn = @_io.read_u2le
      self
    end

    ##
    # Seconds since start of GPS week
    attr_reader :tow

    ##
    # GPS week number
    attr_reader :wn
  end

  ##
  # A (Constellation ID, satellite ID) tuple that uniquely identifies a
  # space vehicle.
  class SvId < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sat_id = @_io.read_u1
      @constellation = @_io.read_u1
      self
    end

    ##
    # Constellation-specific satellite id. For GLO can either be (100+FCN)
    # where FCN is in [-7,+6] or the Slot ID in [1,28].
    attr_reader :sat_id

    ##
    # Constellation ID to which the SV belongs
    attr_reader :constellation
  end
end
