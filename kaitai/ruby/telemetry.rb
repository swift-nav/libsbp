# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Telemetry < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end
  class TelemetrySv < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @az = @_io.read_u1
      @el = @_io.read_s1
      @availability_flags = @_io.read_u1
      @pseudorange_residual = @_io.read_s2le
      @phase_residual = @_io.read_s2le
      @outlier_flags = @_io.read_u1
      @ephemeris_flags = @_io.read_u1
      @correction_flags = @_io.read_u1
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      self
    end

    ##
    # Azimuth angle (range 0..179)
    attr_reader :az

    ##
    # Elevation angle (range -90..90)
    attr_reader :el

    ##
    # Observation availability at filter update
    attr_reader :availability_flags

    ##
    # Pseudorange observation residual
    attr_reader :pseudorange_residual

    ##
    # Carrier-phase or carrier-phase-derived observation residual
    attr_reader :phase_residual

    ##
    # Reports if observation is marked as an outlier and is excluded from
    # the update
    attr_reader :outlier_flags

    ##
    # Ephemeris metadata
    attr_reader :ephemeris_flags

    ##
    # Reserved
    attr_reader :correction_flags

    ##
    # GNSS signal identifier (16 bit)
    attr_reader :sid
  end

  ##
  # This message includes telemetry pertinent to satellite signals available
  # to Starling.
  class MsgTelSv < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @wn = @_io.read_u2le
      @tow = @_io.read_u4le
      @n_obs = @_io.read_u1
      @origin_flags = @_io.read_u1
      @sv_tel = []
      i = 0
      while not @_io.eof?
        @sv_tel << TelemetrySv.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # GPS week number
    attr_reader :wn

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Total number of observations. First nibble is the size of the
    # sequence (n), second nibble is the zero-indexed counter (ith packet
    # of n)
    attr_reader :n_obs

    ##
    # Flags to identify the filter type from which the telemetry is
    # reported from
    attr_reader :origin_flags

    ##
    # Array of per-signal telemetry entries
    attr_reader :sv_tel
  end
end
