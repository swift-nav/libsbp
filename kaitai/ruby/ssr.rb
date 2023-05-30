# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Ssr < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes
  # an RLE encoded validity list.
  class GridDefinitionHeaderDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @region_size_inverse = @_io.read_u1
      @area_width = @_io.read_u2le
      @lat_nw_corner_enc = @_io.read_u2le
      @lon_nw_corner_enc = @_io.read_u2le
      @num_msgs = @_io.read_u1
      @seq_num = @_io.read_u1
      self
    end

    ##
    # region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
    attr_reader :region_size_inverse

    ##
    # grid height (deg) = grid width (deg) = area_width / region_size 0 is
    # an invalid value.
    attr_reader :area_width

    ##
    # North-West corner latitude (deg) = region_size * lat_nw_corner_enc -
    # 90
    attr_reader :lat_nw_corner_enc

    ##
    # North-West corner longitude (deg) = region_size * lon_nw_corner_enc
    # - 180
    attr_reader :lon_nw_corner_enc

    ##
    # Number of messages in the dataset
    attr_reader :num_msgs

    ##
    # Position of this message in the dataset
    attr_reader :seq_num
  end

  ##
  # STEC residual for the given satellite at the grid point.
  class StecResidualNoStd < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sv_id = Gnss::SvId.new(@_io, self, @_root)
      @residual = @_io.read_s2le
      self
    end

    ##
    # space vehicle identifier
    attr_reader :sv_id

    ##
    # STEC residual
    attr_reader :residual
  end

  ##
  # Troposphere vertical delays at the grid point.
  class TroposphericDelayCorrectionNoStd < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @hydro = @_io.read_s2le
      @wet = @_io.read_s1
      self
    end

    ##
    # Hydrostatic vertical delay
    attr_reader :hydro

    ##
    # Wet vertical delay
    attr_reader :wet
  end

  ##
  # The Slant Total Electron Content per space vehicle, given as polynomial
  # approximation for a given tile. This should be combined with the
  # MSG_SSR_GRIDDED_CORRECTION message to get the state space representation
  # of the atmospheric delay.
  # 
  # It is typically equivalent to the QZSS CLAS Sub Type 8 messages.
  class MsgSsrStecCorrectionDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = StecHeader.new(@_io, self, @_root)
      @stec_sat_list = []
      i = 0
      while not @_io.eof?
        @stec_sat_list << StecSatElement.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Header of a STEC polynomial coefficient message.
    attr_reader :header

    ##
    # Array of STEC polynomial coefficients for each space vehicle.
    attr_reader :stec_sat_list
  end

  ##
  # STEC polynomial and bounds for the given satellite.
  class StecSatElementIntegrity < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @stec_residual = StecResidual.new(@_io, self, @_root)
      @stec_bound_mu = @_io.read_u1
      @stec_bound_sig = @_io.read_u1
      @stec_bound_mu_dot = @_io.read_u1
      @stec_bound_sig_dot = @_io.read_u1
      self
    end

    ##
    # STEC residuals (mean, stddev)
    attr_reader :stec_residual

    ##
    # Error Bound Mean. See Note 1.
    attr_reader :stec_bound_mu

    ##
    # Error Bound StDev. See Note 1.
    attr_reader :stec_bound_sig

    ##
    # Error Bound Mean First derivative.
    attr_reader :stec_bound_mu_dot

    ##
    # Error Bound StDev First derivative.
    attr_reader :stec_bound_sig_dot
  end
  class MsgSsrOrbitClockDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @time = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @update_interval = @_io.read_u1
      @iod_ssr = @_io.read_u1
      @iod = @_io.read_u1
      @radial = @_io.read_s4le
      @along = @_io.read_s4le
      @cross = @_io.read_s4le
      @dot_radial = @_io.read_s4le
      @dot_along = @_io.read_s4le
      @dot_cross = @_io.read_s4le
      @c0 = @_io.read_s4le
      @c1 = @_io.read_s4le
      @c2 = @_io.read_s4le
      self
    end

    ##
    # GNSS reference time of the correction
    attr_reader :time

    ##
    # GNSS signal identifier (16 bit)
    attr_reader :sid

    ##
    # Update interval between consecutive corrections. Encoded following
    # RTCM DF391 specification.
    attr_reader :update_interval

    ##
    # IOD of the SSR correction. A change of Issue Of Data SSR is used to
    # indicate a change in the SSR generating configuration
    attr_reader :iod_ssr

    ##
    # Issue of broadcast ephemeris data
    attr_reader :iod

    ##
    # Orbit radial delta correction
    attr_reader :radial

    ##
    # Orbit along delta correction
    attr_reader :along

    ##
    # Orbit along delta correction
    attr_reader :cross

    ##
    # Velocity of orbit radial delta correction
    attr_reader :dot_radial

    ##
    # Velocity of orbit along delta correction
    attr_reader :dot_along

    ##
    # Velocity of orbit cross delta correction
    attr_reader :dot_cross

    ##
    # C0 polynomial coefficient for correction of broadcast satellite
    # clock
    attr_reader :c0

    ##
    # C1 polynomial coefficient for correction of broadcast satellite
    # clock
    attr_reader :c1

    ##
    # C2 polynomial coefficient for correction of broadcast satellite
    # clock
    attr_reader :c2
  end
  class MsgSsrStecCorrection < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = BoundsHeader.new(@_io, self, @_root)
      @ssr_iod_atmo = @_io.read_u1
      @tile_set_id = @_io.read_u2le
      @tile_id = @_io.read_u2le
      @n_sats = @_io.read_u1
      @stec_sat_list = []
      i = 0
      while not @_io.eof?
        @stec_sat_list << StecSatElement.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Header of a STEC correction with bounds message.
    attr_reader :header

    ##
    # IOD of the SSR atmospheric correction
    attr_reader :ssr_iod_atmo

    ##
    # Tile set ID
    attr_reader :tile_set_id

    ##
    # Tile ID
    attr_reader :tile_id

    ##
    # Number of satellites.
    attr_reader :n_sats

    ##
    # Array of STEC polynomial coefficients for each space vehicle.
    attr_reader :stec_sat_list
  end

  ##
  # The precise orbit and clock correction message is to be applied as a
  # delta correction to broadcast ephemeris and is an equivalent to the 1060
  # /1066 RTCM message types.
  class MsgSsrOrbitClock < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @time = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @update_interval = @_io.read_u1
      @iod_ssr = @_io.read_u1
      @iod = @_io.read_u4le
      @radial = @_io.read_s4le
      @along = @_io.read_s4le
      @cross = @_io.read_s4le
      @dot_radial = @_io.read_s4le
      @dot_along = @_io.read_s4le
      @dot_cross = @_io.read_s4le
      @c0 = @_io.read_s4le
      @c1 = @_io.read_s4le
      @c2 = @_io.read_s4le
      self
    end

    ##
    # GNSS reference time of the correction
    attr_reader :time

    ##
    # GNSS signal identifier (16 bit)
    attr_reader :sid

    ##
    # Update interval between consecutive corrections. Encoded following
    # RTCM DF391 specification.
    attr_reader :update_interval

    ##
    # IOD of the SSR correction. A change of Issue Of Data SSR is used to
    # indicate a change in the SSR generating configuration
    attr_reader :iod_ssr

    ##
    # Issue of broadcast ephemeris data or IODCRC (Beidou)
    attr_reader :iod

    ##
    # Orbit radial delta correction
    attr_reader :radial

    ##
    # Orbit along delta correction
    attr_reader :along

    ##
    # Orbit along delta correction
    attr_reader :cross

    ##
    # Velocity of orbit radial delta correction
    attr_reader :dot_radial

    ##
    # Velocity of orbit along delta correction
    attr_reader :dot_along

    ##
    # Velocity of orbit cross delta correction
    attr_reader :dot_cross

    ##
    # C0 polynomial coefficient for correction of broadcast satellite
    # clock
    attr_reader :c0

    ##
    # C1 polynomial coefficient for correction of broadcast satellite
    # clock
    attr_reader :c1

    ##
    # C2 polynomial coefficient for correction of broadcast satellite
    # clock
    attr_reader :c2
  end
  class BoundsHeader < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @time = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @num_msgs = @_io.read_u1
      @seq_num = @_io.read_u1
      @update_interval = @_io.read_u1
      @sol_id = @_io.read_u1
      self
    end

    ##
    # GNSS reference time of the bound
    attr_reader :time

    ##
    # Number of messages in the dataset
    attr_reader :num_msgs

    ##
    # Position of this message in the dataset
    attr_reader :seq_num

    ##
    # Update interval between consecutive bounds. Similar to RTCM DF391.
    attr_reader :update_interval

    ##
    # SSR Solution ID.
    attr_reader :sol_id
  end

  ##
  # STEC residuals are per space vehicle, troposphere is not.
  # 
  # It is typically equivalent to the QZSS CLAS Sub Type 9 messages.
  class MsgSsrGriddedCorrection < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = GriddedCorrectionHeader.new(@_io, self, @_root)
      @index = @_io.read_u2le
      @tropo_delay_correction = TroposphericDelayCorrection.new(@_io, self, @_root)
      @stec_residuals = []
      i = 0
      while not @_io.eof?
        @stec_residuals << StecResidual.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Header of a gridded correction message
    attr_reader :header

    ##
    # Index of the grid point.
    attr_reader :index

    ##
    # Wet and hydrostatic vertical delays (mean, stddev).
    attr_reader :tropo_delay_correction

    ##
    # STEC residuals for each satellite (mean, stddev).
    attr_reader :stec_residuals
  end

  ##
  # STEC residual (mean and standard deviation) for the given satellite at
  # the grid point.
  class StecResidual < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sv_id = Gnss::SvId.new(@_io, self, @_root)
      @residual = @_io.read_s2le
      @stddev = @_io.read_u1
      self
    end

    ##
    # space vehicle identifier
    attr_reader :sv_id

    ##
    # STEC residual
    attr_reader :residual

    ##
    # Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
    # value/16) - 1) * 10
    attr_reader :stddev
  end
  class CodePhaseBiasesSatSig < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sat_id = @_io.read_u1
      @signal_id = @_io.read_u1
      @code_bias_bound_mu = @_io.read_u1
      @code_bias_bound_sig = @_io.read_u1
      @phase_bias_bound_mu = @_io.read_u1
      @phase_bias_bound_sig = @_io.read_u1
      self
    end

    ##
    # Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
    # or DF488 (BDS) depending on the constellation.
    attr_reader :sat_id

    ##
    # Signal and Tracking Mode Identifier. Similar to either RTCM DF380
    # (GPS), DF382 (Galileo) or DF467 (BDS) depending on the
    # constellation.
    attr_reader :signal_id

    ##
    # Code Bias Mean. Range: 0-1.275 m
    attr_reader :code_bias_bound_mu

    ##
    # Code Bias Standard Deviation.  Range: 0-1.275 m
    attr_reader :code_bias_bound_sig

    ##
    # Phase Bias Mean. Range: 0-1.275 m
    attr_reader :phase_bias_bound_mu

    ##
    # Phase Bias Standard Deviation.  Range: 0-1.275 m
    attr_reader :phase_bias_bound_sig
  end

  ##
  # Contains phase center offset and elevation variation corrections for one
  # signal on a satellite.
  class SatelliteApc < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @sat_info = @_io.read_u1
      @svn = @_io.read_u2le
      @pco = []
      (3).times { |i|
        @pco << @_io.read_s2le
      }
      @pcv = []
      (21).times { |i|
        @pcv << @_io.read_s1
      }
      self
    end

    ##
    # GNSS signal identifier (16 bit)
    attr_reader :sid

    ##
    # Additional satellite information
    attr_reader :sat_info

    ##
    # Satellite Code, as defined by IGS. Typically the space vehicle
    # number.
    attr_reader :svn

    ##
    # Mean phase center offset, X Y and Z axes. See IGS ANTEX file format
    # description for coordinate system definition.
    attr_reader :pco

    ##
    # Elevation dependent phase center variations. First element is 0
    # degrees separation from the Z axis, subsequent elements represent
    # elevation variations in 1 degree increments.
    attr_reader :pcv
  end

  ##
  # The LPP message contains nested variable length arrays which are not
  # supported in SBP, so each grid point will be identified by the index.
  class GriddedCorrectionHeader < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tile_set_id = @_io.read_u2le
      @tile_id = @_io.read_u2le
      @time = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @num_msgs = @_io.read_u2le
      @seq_num = @_io.read_u2le
      @update_interval = @_io.read_u1
      @iod_atmo = @_io.read_u1
      @tropo_quality_indicator = @_io.read_u1
      self
    end

    ##
    # Unique identifier of the tile set this tile belongs to.
    attr_reader :tile_set_id

    ##
    # Unique identifier of this tile in the tile set.
    attr_reader :tile_id

    ##
    # GNSS reference time of the correction
    attr_reader :time

    ##
    # Number of messages in the dataset
    attr_reader :num_msgs

    ##
    # Position of this message in the dataset
    attr_reader :seq_num

    ##
    # Update interval between consecutive corrections. Encoded following
    # RTCM DF391 specification.
    attr_reader :update_interval

    ##
    # IOD of the SSR atmospheric correction
    attr_reader :iod_atmo

    ##
    # Quality of the troposphere data. Encoded following RTCM DF389
    # specification in units of m.
    attr_reader :tropo_quality_indicator
  end

  ##
  # STEC polynomial for the given satellite.
  class StecSatElement < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sv_id = Gnss::SvId.new(@_io, self, @_root)
      @stec_quality_indicator = @_io.read_u1
      @stec_coeff = []
      (4).times { |i|
        @stec_coeff << @_io.read_s2le
      }
      self
    end

    ##
    # Unique space vehicle identifier
    attr_reader :sv_id

    ##
    # Quality of the STEC data. Encoded following RTCM DF389 specification
    # but in units of TECU instead of m.
    attr_reader :stec_quality_indicator

    ##
    # Coefficients of the STEC polynomial in the order of C00, C01, C10,
    # C11. C00 = 0.05 TECU, C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2
    attr_reader :stec_coeff
  end

  ##
  # A full set of STEC information will likely span multiple SBP messages,
  # since SBP message a limited to 255 bytes.  The header is used to tie
  # multiple SBP messages into a sequence.
  class StecHeaderDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @time = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @num_msgs = @_io.read_u1
      @seq_num = @_io.read_u1
      @update_interval = @_io.read_u1
      @iod_atmo = @_io.read_u1
      self
    end

    ##
    # GNSS reference time of the correction
    attr_reader :time

    ##
    # Number of messages in the dataset
    attr_reader :num_msgs

    ##
    # Position of this message in the dataset
    attr_reader :seq_num

    ##
    # Update interval between consecutive corrections. Encoded following
    # RTCM DF391 specification.
    attr_reader :update_interval

    ##
    # IOD of the SSR atmospheric correction
    attr_reader :iod_atmo
  end

  ##
  # A full set of STEC information will likely span multiple SBP messages,
  # since SBP message a limited to 255 bytes.  The header is used to tie
  # multiple SBP messages into a sequence.
  class StecHeader < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tile_set_id = @_io.read_u2le
      @tile_id = @_io.read_u2le
      @time = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @num_msgs = @_io.read_u1
      @seq_num = @_io.read_u1
      @update_interval = @_io.read_u1
      @iod_atmo = @_io.read_u1
      self
    end

    ##
    # Unique identifier of the tile set this tile belongs to.
    attr_reader :tile_set_id

    ##
    # Unique identifier of this tile in the tile set.
    attr_reader :tile_id

    ##
    # GNSS reference time of the correction
    attr_reader :time

    ##
    # Number of messages in the dataset
    attr_reader :num_msgs

    ##
    # Position of this message in the dataset
    attr_reader :seq_num

    ##
    # Update interval between consecutive corrections. Encoded following
    # RTCM DF391 specification.
    attr_reader :update_interval

    ##
    # IOD of the SSR atmospheric correction
    attr_reader :iod_atmo
  end
  class MsgSsrStecCorrectionDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = StecHeaderDepA.new(@_io, self, @_root)
      @stec_sat_list = []
      i = 0
      while not @_io.eof?
        @stec_sat_list << StecSatElement.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Header of a STEC message
    attr_reader :header

    ##
    # Array of STEC information for each space vehicle
    attr_reader :stec_sat_list
  end

  ##
  # The 3GPP message contains nested variable length arrays which are not
  # supported in SBP, so each grid point will be identified by the index.
  class GriddedCorrectionHeaderDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @time = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @num_msgs = @_io.read_u2le
      @seq_num = @_io.read_u2le
      @update_interval = @_io.read_u1
      @iod_atmo = @_io.read_u1
      @tropo_quality_indicator = @_io.read_u1
      self
    end

    ##
    # GNSS reference time of the correction
    attr_reader :time

    ##
    # Number of messages in the dataset
    attr_reader :num_msgs

    ##
    # Position of this message in the dataset
    attr_reader :seq_num

    ##
    # Update interval between consecutive corrections. Encoded following
    # RTCM DF391 specification.
    attr_reader :update_interval

    ##
    # IOD of the SSR atmospheric correction
    attr_reader :iod_atmo

    ##
    # Quality of the troposphere data. Encoded following RTCM DF389
    # specification in units of m.
    attr_reader :tropo_quality_indicator
  end

  ##
  # Note 1: Range: 0-17.5 m. i<=200, mean=0.01i; 200<i<=230,
  # mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
  # 
  # Note 2: Range: 0-17.5 m. i<=200, std=0.01i; 200<i<=230, std=2+0.1(i-200)
  # i>230, std=5+0.5(i-230).
  class MsgSsrOrbitClockBounds < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = BoundsHeader.new(@_io, self, @_root)
      @ssr_iod = @_io.read_u1
      @const_id = @_io.read_u1
      @n_sats = @_io.read_u1
      @orbit_clock_bounds = []
      i = 0
      while not @_io.eof?
        @orbit_clock_bounds << OrbitClockBound.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Header of a bounds message.
    attr_reader :header

    ##
    # IOD of the SSR bound.
    attr_reader :ssr_iod

    ##
    # Constellation ID to which the SVs belong.
    attr_reader :const_id

    ##
    # Number of satellites.
    attr_reader :n_sats

    ##
    # Orbit and Clock Bounds per Satellite
    attr_reader :orbit_clock_bounds
  end

  ##
  # Note 1: Range: 0-17.5 m. i<= 200, mean = 0.01i; 200<i<=230,
  # mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
  class MsgSsrGriddedCorrectionBounds < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = BoundsHeader.new(@_io, self, @_root)
      @ssr_iod_atmo = @_io.read_u1
      @tile_set_id = @_io.read_u2le
      @tile_id = @_io.read_u2le
      @tropo_qi = @_io.read_u1
      @grid_point_id = @_io.read_u2le
      @tropo_delay_correction = TroposphericDelayCorrection.new(@_io, self, @_root)
      @tropo_v_hydro_bound_mu = @_io.read_u1
      @tropo_v_hydro_bound_sig = @_io.read_u1
      @tropo_v_wet_bound_mu = @_io.read_u1
      @tropo_v_wet_bound_sig = @_io.read_u1
      @n_sats = @_io.read_u1
      @stec_sat_list = []
      i = 0
      while not @_io.eof?
        @stec_sat_list << StecSatElementIntegrity.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Header of a bounds message.
    attr_reader :header

    ##
    # IOD of the correction.
    attr_reader :ssr_iod_atmo

    ##
    # Set this tile belongs to.
    attr_reader :tile_set_id

    ##
    # Unique identifier of this tile in the tile set.
    attr_reader :tile_id

    ##
    # Tropo Quality Indicator. Similar to RTCM DF389.
    attr_reader :tropo_qi

    ##
    # Index of the Grid Point.
    attr_reader :grid_point_id

    ##
    # Tropospheric delay at grid point.
    attr_reader :tropo_delay_correction

    ##
    # Vertical Hydrostatic Error Bound Mean.
    attr_reader :tropo_v_hydro_bound_mu

    ##
    # Vertical Hydrostatic Error Bound StDev.
    attr_reader :tropo_v_hydro_bound_sig

    ##
    # Vertical Wet Error Bound Mean.
    attr_reader :tropo_v_wet_bound_mu

    ##
    # Vertical Wet Error Bound StDev.
    attr_reader :tropo_v_wet_bound_sig

    ##
    # Number of satellites.
    attr_reader :n_sats

    ##
    # Array of STEC polynomial coefficients and its bounds for each space
    # vehicle.
    attr_reader :stec_sat_list
  end
  class MsgSsrGridDefinitionDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = GridDefinitionHeaderDepA.new(@_io, self, @_root)
      @rle_list = []
      i = 0
      while not @_io.eof?
        @rle_list << @_io.read_u1
        i += 1
      end
      self
    end

    ##
    # Header of a Gridded Correction message
    attr_reader :header

    ##
    # Run Length Encode list of quadrants that contain valid data. The
    # spec describes the encoding scheme in detail, but essentially the
    # index of the quadrants that contain transitions between valid and
    # invalid (and vice versa) are encoded as u8 integers.
    attr_reader :rle_list
  end

  ##
  # Code biases are to be added to pseudorange. The corrections conform with
  # RTCMv3 MT 1059 / 1065.
  class CodeBiasesContent < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @code = @_io.read_u1
      @value = @_io.read_s2le
      self
    end

    ##
    # Signal encoded following RTCM specifications (DF380, DF381, DF382
    # and DF467).
    attr_reader :code

    ##
    # Code bias value
    attr_reader :value
  end
  class MsgSsrSatelliteApc < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @time = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @update_interval = @_io.read_u1
      @sol_id = @_io.read_u1
      @iod_ssr = @_io.read_u1
      @apc = []
      i = 0
      while not @_io.eof?
        @apc << SatelliteApc.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # GNSS reference time of the correction
    attr_reader :time

    ##
    # Update interval between consecutive corrections. Encoded following
    # RTCM DF391 specification.
    attr_reader :update_interval

    ##
    # SSR Solution ID. Similar to RTCM DF415.
    attr_reader :sol_id

    ##
    # IOD of the SSR correction. A change of Issue Of Data SSR is used to
    # indicate a change in the SSR generating configuration
    attr_reader :iod_ssr

    ##
    # Satellite antenna phase center corrections
    attr_reader :apc
  end

  ##
  # Phase biases are to be added to carrier phase measurements.
  class PhaseBiasesContent < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @code = @_io.read_u1
      @integer_indicator = @_io.read_u1
      @widelane_integer_indicator = @_io.read_u1
      @discontinuity_counter = @_io.read_u1
      @bias = @_io.read_s4le
      self
    end

    ##
    # Signal encoded following RTCM specifications (DF380, DF381, DF382
    # and DF467)
    attr_reader :code

    ##
    # Indicator for integer property
    attr_reader :integer_indicator

    ##
    # Indicator for two groups of Wide-Lane(s) integer property
    attr_reader :widelane_integer_indicator

    ##
    # Signal phase discontinuity counter. Increased for every
    # discontinuity in phase.
    attr_reader :discontinuity_counter

    ##
    # Phase bias for specified signal
    attr_reader :bias
  end

  ##
  # Provides the correction point coordinates for the atmospheric correction
  # values in the MSG_SSR_STEC_CORRECTION_DEP and MSG_SSR_GRIDDED_CORRECTION
  # messages.
  # 
  # Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
  # element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
  # correction points, not lists of points.
  class MsgSsrTileDefinitionDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tile_set_id = @_io.read_u2le
      @tile_id = @_io.read_u2le
      @corner_nw_lat = @_io.read_s2le
      @corner_nw_lon = @_io.read_s2le
      @spacing_lat = @_io.read_u2le
      @spacing_lon = @_io.read_u2le
      @rows = @_io.read_u2le
      @cols = @_io.read_u2le
      @bitmask = @_io.read_u8le
      self
    end

    ##
    # Unique identifier of the tile set this tile belongs to.
    attr_reader :tile_set_id

    ##
    # Unique identifier of this tile in the tile set.
    # See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
    attr_reader :tile_id

    ##
    # North-West corner correction point latitude.
    # 
    # The relation between the latitude X in the range [-90, 90] and the
    # coded number N is:
    # 
    # N = floor((X / 90) * 2^14)
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
    attr_reader :corner_nw_lat

    ##
    # North-West corner correction point longitude.
    # 
    # The relation between the longitude X in the range [-180, 180] and
    # the coded number N is:
    # 
    # N = floor((X / 180) * 2^15)
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
    attr_reader :corner_nw_lon

    ##
    # Spacing of the correction points in the latitude direction.
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
    attr_reader :spacing_lat

    ##
    # Spacing of the correction points in the longitude direction.
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
    attr_reader :spacing_lon

    ##
    # Number of steps in the latitude direction.
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
    attr_reader :rows

    ##
    # Number of steps in the longitude direction.
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
    attr_reader :cols

    ##
    # Specifies the availability of correction data at the correction
    # points in the array.
    # 
    # If a specific bit is enabled (set to 1), the correction is not
    # available. Only the first rows * cols bits are used, the remainder
    # are set to 0. If there are more then 64 correction points the
    # remaining corrections are always available.
    # 
    # Starting with the northwest corner of the array (top left on a north
    # oriented map) the correction points are enumerated with row
    # precedence - first row west to east, second row west to east, until
    # last row west to east - ending with the southeast corner of the
    # array.
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
    # the definition of the bits is inverted.
    attr_reader :bitmask
  end

  ##
  # Orbit and clock bound.
  class OrbitClockBound < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sat_id = @_io.read_u1
      @orb_radial_bound_mu = @_io.read_u1
      @orb_along_bound_mu = @_io.read_u1
      @orb_cross_bound_mu = @_io.read_u1
      @orb_radial_bound_sig = @_io.read_u1
      @orb_along_bound_sig = @_io.read_u1
      @orb_cross_bound_sig = @_io.read_u1
      @clock_bound_mu = @_io.read_u1
      @clock_bound_sig = @_io.read_u1
      self
    end

    ##
    # Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
    # or DF488 (BDS) depending on the constellation.
    attr_reader :sat_id

    ##
    # Mean Radial. See Note 1.
    attr_reader :orb_radial_bound_mu

    ##
    # Mean Along-Track. See Note 1.
    attr_reader :orb_along_bound_mu

    ##
    # Mean Cross-Track. See Note 1.
    attr_reader :orb_cross_bound_mu

    ##
    # Standard Deviation Radial. See Note 2.
    attr_reader :orb_radial_bound_sig

    ##
    # Standard Deviation Along-Track. See Note 2.
    attr_reader :orb_along_bound_sig

    ##
    # Standard Deviation Cross-Track. See Note 2.
    attr_reader :orb_cross_bound_sig

    ##
    # Clock Bound Mean. See Note 1.
    attr_reader :clock_bound_mu

    ##
    # Clock Bound Standard Deviation. See Note 2.
    attr_reader :clock_bound_sig
  end
  class MsgSsrGriddedCorrectionDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = GriddedCorrectionHeaderDepA.new(@_io, self, @_root)
      @index = @_io.read_u2le
      @tropo_delay_correction = TroposphericDelayCorrection.new(@_io, self, @_root)
      @stec_residuals = []
      i = 0
      while not @_io.eof?
        @stec_residuals << StecResidual.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Header of a Gridded Correction message
    attr_reader :header

    ##
    # Index of the grid point
    attr_reader :index

    ##
    # Wet and hydrostatic vertical delays (mean, stddev)
    attr_reader :tropo_delay_correction

    ##
    # STEC residuals for each satellite (mean, stddev)
    attr_reader :stec_residuals
  end
  class MsgSsrOrbitClockBoundsDegradation < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = BoundsHeader.new(@_io, self, @_root)
      @ssr_iod = @_io.read_u1
      @const_id = @_io.read_u1
      @sat_bitmask = @_io.read_u8le
      @orbit_clock_bounds_degradation = OrbitClockBoundDegradation.new(@_io, self, @_root)
      self
    end

    ##
    # Header of a bounds message.
    attr_reader :header

    ##
    # IOD of the SSR bound degradation parameter.
    attr_reader :ssr_iod

    ##
    # Constellation ID to which the SVs belong.
    attr_reader :const_id

    ##
    # Satellite Bit Mask. Put 1 for each satellite where the following
    # degradation parameters are applicable, 0 otherwise. Encoded
    # following RTCM DF394 specification.
    attr_reader :sat_bitmask

    ##
    # Orbit and Clock Bounds Degradation Parameters
    attr_reader :orbit_clock_bounds_degradation
  end
  class MsgSsrGriddedCorrectionNoStdDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = GriddedCorrectionHeaderDepA.new(@_io, self, @_root)
      @index = @_io.read_u2le
      @tropo_delay_correction = TroposphericDelayCorrectionNoStd.new(@_io, self, @_root)
      @stec_residuals = []
      i = 0
      while not @_io.eof?
        @stec_residuals << StecResidualNoStd.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Header of a Gridded Correction message
    attr_reader :header

    ##
    # Index of the grid point
    attr_reader :index

    ##
    # Wet and hydrostatic vertical delays
    attr_reader :tropo_delay_correction

    ##
    # STEC residuals for each satellite
    attr_reader :stec_residuals
  end
  class MsgSsrCodePhaseBiasesBounds < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = BoundsHeader.new(@_io, self, @_root)
      @ssr_iod = @_io.read_u1
      @const_id = @_io.read_u1
      @n_sats_signals = @_io.read_u1
      @satellites_signals = []
      i = 0
      while not @_io.eof?
        @satellites_signals << CodePhaseBiasesSatSig.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Header of a bounds message.
    attr_reader :header

    ##
    # IOD of the SSR bound.
    attr_reader :ssr_iod

    ##
    # Constellation ID to which the SVs belong.
    attr_reader :const_id

    ##
    # Number of satellite-signal couples.
    attr_reader :n_sats_signals

    ##
    # Code and Phase Biases Bounds per Satellite-Signal couple.
    attr_reader :satellites_signals
  end

  ##
  # The precise code biases message is to be added to the pseudorange of the
  # corresponding signal to get corrected pseudorange. It is an equivalent
  # to the 1059 / 1065 RTCM message types.
  class MsgSsrCodeBiases < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @time = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @update_interval = @_io.read_u1
      @iod_ssr = @_io.read_u1
      @biases = []
      i = 0
      while not @_io.eof?
        @biases << CodeBiasesContent.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # GNSS reference time of the correction
    attr_reader :time

    ##
    # GNSS signal identifier (16 bit)
    attr_reader :sid

    ##
    # Update interval between consecutive corrections. Encoded following
    # RTCM DF391 specification.
    attr_reader :update_interval

    ##
    # IOD of the SSR correction. A change of Issue Of Data SSR is used to
    # indicate a change in the SSR generating configuration
    attr_reader :iod_ssr

    ##
    # Code biases for the different satellite signals
    attr_reader :biases
  end

  ##
  # Provides the correction point coordinates for the atmospheric correction
  # values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
  # messages.
  # 
  # Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
  # element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
  # correction points, not lists of points.
  class MsgSsrTileDefinition < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @time = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @update_interval = @_io.read_u1
      @sol_id = @_io.read_u1
      @iod_atmo = @_io.read_u1
      @tile_set_id = @_io.read_u2le
      @tile_id = @_io.read_u2le
      @corner_nw_lat = @_io.read_s2le
      @corner_nw_lon = @_io.read_s2le
      @spacing_lat = @_io.read_u2le
      @spacing_lon = @_io.read_u2le
      @rows = @_io.read_u2le
      @cols = @_io.read_u2le
      @bitmask = @_io.read_u8le
      self
    end

    ##
    # GNSS reference time of the correction
    attr_reader :time

    ##
    # Update interval between consecutive corrections. Encoded following
    # RTCM DF391 specification.
    attr_reader :update_interval

    ##
    # SSR Solution ID. Similar to RTCM DF415.
    attr_reader :sol_id

    ##
    # IOD of the SSR atmospheric correction.
    attr_reader :iod_atmo

    ##
    # Unique identifier of the tile set this tile belongs to.
    attr_reader :tile_set_id

    ##
    # Unique identifier of this tile in the tile set.
    # See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
    attr_reader :tile_id

    ##
    # North-West corner correction point latitude.
    # 
    # The relation between the latitude X in the range [-90, 90] and the
    # coded number N is:  N = floor((X / 90) * 2^14)
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
    attr_reader :corner_nw_lat

    ##
    # North-West corner correction point longitude.
    # 
    # The relation between the longitude X in the range [-180, 180] and
    # the coded number N is: N = floor((X / 180) * 2^15)
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
    attr_reader :corner_nw_lon

    ##
    # Spacing of the correction points in the latitude direction.
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
    attr_reader :spacing_lat

    ##
    # Spacing of the correction points in the longitude direction.
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
    attr_reader :spacing_lon

    ##
    # Number of steps in the latitude direction.
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
    attr_reader :rows

    ##
    # Number of steps in the longitude direction.
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
    attr_reader :cols

    ##
    # Specifies the absence of correction data at the correction points in
    # the array (grid).
    # 
    # Only the first rows * cols bits are used, and if a specific bit is
    # enabled (set to 1), the correction is not available. If there are
    # more than 64 correction points the remaining corrections are always
    # available.
    # 
    # The correction points are packed by rows, starting with the
    # northwest corner of the array (top-left on a north oriented map),
    # with each row spanning west to east, ending with the southeast
    # corner of the array.
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
    # the definition of the bits is inverted.
    attr_reader :bitmask
  end

  ##
  # Orbit and clock bound degradation.
  class OrbitClockBoundDegradation < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @orb_radial_bound_mu_dot = @_io.read_u1
      @orb_along_bound_mu_dot = @_io.read_u1
      @orb_cross_bound_mu_dot = @_io.read_u1
      @orb_radial_bound_sig_dot = @_io.read_u1
      @orb_along_bound_sig_dot = @_io.read_u1
      @orb_cross_bound_sig_dot = @_io.read_u1
      @clock_bound_mu_dot = @_io.read_u1
      @clock_bound_sig_dot = @_io.read_u1
      self
    end

    ##
    # Orbit Bound Mean Radial First derivative. Range: 0-0.255 m/s
    attr_reader :orb_radial_bound_mu_dot

    ##
    # Orbit Bound Mean Along-Track First derivative. Range: 0-0.255 m/s
    attr_reader :orb_along_bound_mu_dot

    ##
    # Orbit Bound Mean Cross-Track First derivative. Range: 0-0.255 m/s
    attr_reader :orb_cross_bound_mu_dot

    ##
    # Orbit Bound Standard Deviation Radial First derivative. Range:
    # 0-0.255 m/s
    attr_reader :orb_radial_bound_sig_dot

    ##
    # Orbit Bound Standard Deviation Along-Track First derivative. Range:
    # 0-0.255 m/s
    attr_reader :orb_along_bound_sig_dot

    ##
    # Orbit Bound Standard Deviation Cross-Track First derivative. Range:
    # 0-0.255 m/s
    attr_reader :orb_cross_bound_sig_dot

    ##
    # Clock Bound Mean First derivative. Range: 0-0.255 m/s
    attr_reader :clock_bound_mu_dot

    ##
    # Clock Bound Standard Deviation First derivative. Range: 0-0.255 m/s
    attr_reader :clock_bound_sig_dot
  end
  class MsgSsrSatelliteApcDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @apc = []
      i = 0
      while not @_io.eof?
        @apc << SatelliteApc.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Satellite antenna phase center corrections
    attr_reader :apc
  end

  ##
  # Troposphere vertical delays (mean and standard deviation) at the grid
  # point.
  class TroposphericDelayCorrection < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @hydro = @_io.read_s2le
      @wet = @_io.read_s1
      @stddev = @_io.read_u1
      self
    end

    ##
    # Hydrostatic vertical delay. Add 2.3 m to get actual value.
    attr_reader :hydro

    ##
    # Wet vertical delay. Add 0.252 m to get actual value.
    attr_reader :wet

    ##
    # Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
    # value/16) - 1)
    attr_reader :stddev
  end

  ##
  # Provides the correction point coordinates for the atmospheric correction
  # values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
  # messages.
  # 
  # Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
  # element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
  # correction points, not lists of points.
  class MsgSsrTileDefinitionDepB < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @ssr_sol_id = @_io.read_u1
      @tile_set_id = @_io.read_u2le
      @tile_id = @_io.read_u2le
      @corner_nw_lat = @_io.read_s2le
      @corner_nw_lon = @_io.read_s2le
      @spacing_lat = @_io.read_u2le
      @spacing_lon = @_io.read_u2le
      @rows = @_io.read_u2le
      @cols = @_io.read_u2le
      @bitmask = @_io.read_u8le
      self
    end

    ##
    # SSR Solution ID.
    attr_reader :ssr_sol_id

    ##
    # Unique identifier of the tile set this tile belongs to.
    attr_reader :tile_set_id

    ##
    # Unique identifier of this tile in the tile set.
    # See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
    attr_reader :tile_id

    ##
    # North-West corner correction point latitude.
    # 
    # The relation between the latitude X in the range [-90, 90] and the
    # coded number N is:
    # 
    # N = floor((X / 90) * 2^14)
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
    attr_reader :corner_nw_lat

    ##
    # North-West corner correction point longitude.
    # 
    # The relation between the longitude X in the range [-180, 180] and
    # the coded number N is:
    # 
    # N = floor((X / 180) * 2^15)
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
    attr_reader :corner_nw_lon

    ##
    # Spacing of the correction points in the latitude direction.
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
    attr_reader :spacing_lat

    ##
    # Spacing of the correction points in the longitude direction.
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
    attr_reader :spacing_lon

    ##
    # Number of steps in the latitude direction.
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
    attr_reader :rows

    ##
    # Number of steps in the longitude direction.
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
    attr_reader :cols

    ##
    # Specifies the availability of correction data at the correction
    # points in the array.
    # 
    # If a specific bit is enabled (set to 1), the correction is not
    # available. Only the first rows * cols bits are used, the remainder
    # are set to 0. If there are more then 64 correction points the
    # remaining corrections are always available.
    # 
    # Starting with the northwest corner of the array (top left on a north
    # oriented map) the correction points are enumerated with row
    # precedence - first row west to east, second row west to east, until
    # last row west to east - ending with the southeast corner of the
    # array.
    # 
    # See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
    # the definition of the bits is inverted.
    attr_reader :bitmask
  end

  ##
  # The precise phase biases message contains the biases to be added to the
  # carrier phase of the corresponding signal to get corrected carrier phase
  # measurement, as well as the satellite yaw angle to be applied to compute
  # the phase wind-up correction. It is typically an equivalent to the 1265
  # RTCM message types.
  class MsgSsrPhaseBiases < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @time = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @update_interval = @_io.read_u1
      @iod_ssr = @_io.read_u1
      @dispersive_bias = @_io.read_u1
      @mw_consistency = @_io.read_u1
      @yaw = @_io.read_u2le
      @yaw_rate = @_io.read_s1
      @biases = []
      i = 0
      while not @_io.eof?
        @biases << PhaseBiasesContent.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # GNSS reference time of the correction
    attr_reader :time

    ##
    # GNSS signal identifier (16 bit)
    attr_reader :sid

    ##
    # Update interval between consecutive corrections. Encoded following
    # RTCM DF391 specification.
    attr_reader :update_interval

    ##
    # IOD of the SSR correction. A change of Issue Of Data SSR is used to
    # indicate a change in the SSR generating configuration
    attr_reader :iod_ssr

    ##
    # Indicator for the dispersive phase biases property.
    attr_reader :dispersive_bias

    ##
    # Consistency indicator for Melbourne-Wubbena linear combinations
    attr_reader :mw_consistency

    ##
    # Satellite yaw angle
    attr_reader :yaw

    ##
    # Satellite yaw angle rate
    attr_reader :yaw_rate

    ##
    # Phase biases corrections for a satellite being tracked.
    attr_reader :biases
  end
end
