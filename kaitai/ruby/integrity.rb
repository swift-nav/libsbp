# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Integrity < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end
  class MsgSsrFlagSatellites < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @obs_time = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @num_msgs = @_io.read_u1
      @seq_num = @_io.read_u1
      @ssr_sol_id = @_io.read_u1
      @chain_id = @_io.read_u1
      @const_id = @_io.read_u1
      @n_faulty_sats = @_io.read_u1
      @faulty_sats = []
      i = 0
      while not @_io.eof?
        @faulty_sats << @_io.read_u1
        i += 1
      end
      self
    end

    ##
    # GNSS reference time of the observation used to generate the flag.
    attr_reader :obs_time

    ##
    # Number of messages in the dataset
    attr_reader :num_msgs

    ##
    # Position of this message in the dataset
    attr_reader :seq_num

    ##
    # SSR Solution ID.
    attr_reader :ssr_sol_id

    ##
    # Chain and type of flag.
    attr_reader :chain_id

    ##
    # Constellation ID.
    attr_reader :const_id

    ##
    # Number of faulty satellites.
    attr_reader :n_faulty_sats

    ##
    # List of faulty satellites.
    attr_reader :faulty_sats
  end
  class MsgSsrFlagIonoTileSatLos < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = IntegritySsrHeader.new(@_io, self, @_root)
      @n_faulty_los = @_io.read_u1
      @faulty_los = []
      i = 0
      while not @_io.eof?
        @faulty_los << Gnss::SvId.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Header of an integrity message.
    attr_reader :header

    ##
    # Number of faulty LOS.
    attr_reader :n_faulty_los

    ##
    # List of faulty LOS
    attr_reader :faulty_los
  end
  class MsgSsrFlagIonoGridPointSatLos < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = IntegritySsrHeader.new(@_io, self, @_root)
      @grid_point_id = @_io.read_u2le
      @n_faulty_los = @_io.read_u1
      @faulty_los = []
      i = 0
      while not @_io.eof?
        @faulty_los << Gnss::SvId.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Header of an integrity message.
    attr_reader :header

    ##
    # Index of the grid point.
    attr_reader :grid_point_id

    ##
    # Number of faulty LOS.
    attr_reader :n_faulty_los

    ##
    # List of faulty LOS
    attr_reader :faulty_los
  end
  class IntegritySsrHeader < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @obs_time = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @num_msgs = @_io.read_u1
      @seq_num = @_io.read_u1
      @ssr_sol_id = @_io.read_u1
      @tile_set_id = @_io.read_u2le
      @tile_id = @_io.read_u2le
      @chain_id = @_io.read_u1
      self
    end

    ##
    # GNSS reference time of the observation used to generate the flag.
    attr_reader :obs_time

    ##
    # Number of messages in the dataset
    attr_reader :num_msgs

    ##
    # Position of this message in the dataset
    attr_reader :seq_num

    ##
    # SSR Solution ID.
    attr_reader :ssr_sol_id

    ##
    # Unique identifier of the set this tile belongs to.
    attr_reader :tile_set_id

    ##
    # Unique identifier of this tile in the tile set.
    attr_reader :tile_id

    ##
    # Chain and type of flag.
    attr_reader :chain_id
  end
  class MsgAcknowledge < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @request_id = @_io.read_u1
      @area_id = @_io.read_u4le
      @response_code = @_io.read_u1
      @correction_mask_on_demand = @_io.read_u2le
      @correction_mask_stream = @_io.read_u2le
      @solution_id = @_io.read_u1
      self
    end

    ##
    # Echo of the request ID field from the corresponding CRA message, or
    # 255 if no request ID was provided.
    attr_reader :request_id

    ##
    # Echo of the Area ID field from the corresponding CRA message.
    attr_reader :area_id

    ##
    # Reported status of the request.
    attr_reader :response_code

    ##
    # Contains the message group(s) that will be sent in response from the
    # corresponding CRA correction mask. An echo of the correction mask
    # field from the corresponding CRA message.
    attr_reader :correction_mask_on_demand

    ##
    # For future expansion. Always set to 0.
    attr_reader :correction_mask_stream

    ##
    # The solution ID of the instance providing the corrections.
    attr_reader :solution_id
  end
  class MsgSsrFlagIonoGridPoints < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = IntegritySsrHeader.new(@_io, self, @_root)
      @n_faulty_points = @_io.read_u1
      @faulty_points = []
      i = 0
      while not @_io.eof?
        @faulty_points << @_io.read_u2le
        i += 1
      end
      self
    end

    ##
    # Header of an integrity message.
    attr_reader :header

    ##
    # Number of faulty grid points.
    attr_reader :n_faulty_points

    ##
    # List of faulty grid points.
    attr_reader :faulty_points
  end
  class MsgSsrFlagTropoGridPoints < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = IntegritySsrHeader.new(@_io, self, @_root)
      @n_faulty_points = @_io.read_u1
      @faulty_points = []
      i = 0
      while not @_io.eof?
        @faulty_points << @_io.read_u2le
        i += 1
      end
      self
    end

    ##
    # Header of an integrity message.
    attr_reader :header

    ##
    # Number of faulty grid points.
    attr_reader :n_faulty_points

    ##
    # List of faulty grid points.
    attr_reader :faulty_points
  end

  ##
  # Integrity monitoring flags for multiple aggregated elements. An element
  # could be a satellite, SSR grid point, or SSR tile. A group of aggregated
  # elements being monitored for integrity could refer to:
  # 
  # - Satellites in a particular {GPS, GAL, BDS} constellation.
  # 
  # - Satellites in the line-of-sight of a particular SSR tile.
  # 
  # - Satellites in the line-of-sight of a particular SSR grid point.
  # 
  # The integrity usage for a group of aggregated elements varies according
  # to the integrity flag of the satellites comprising that group.
  # 
  # SSR_INTEGRITY_USAGE_NOMINAL: All satellites received passed the
  # integrity check and have flag INTEGRITY_FLAG_OK.
  # 
  # SSR_INTEGRITY_USAGE_WARNING: A limited number of elements in the group
  # failed the integrity check. Refer to more granular integrity messages
  # for details on the specific failing elements.
  # 
  # SSR_INTEGRITY_USAGE_ALERT: Most elements in the group failed the
  # integrity check, do not use for positioning.
  # 
  # SSR_INTEGRITY_USAGE_NOT_MONITORED: Unable to verify the integrity flag
  # of elements in the group.
  class MsgSsrFlagHighLevel < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @obs_time = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @corr_time = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @ssr_sol_id = @_io.read_u1
      @tile_set_id = @_io.read_u2le
      @tile_id = @_io.read_u2le
      @chain_id = @_io.read_u1
      @use_gps_sat = @_io.read_u1
      @use_gal_sat = @_io.read_u1
      @use_bds_sat = @_io.read_u1
      @reserved = []
      (6).times { |i|
        @reserved << @_io.read_u1
      }
      @use_tropo_grid_points = @_io.read_u1
      @use_iono_grid_points = @_io.read_u1
      @use_iono_tile_sat_los = @_io.read_u1
      @use_iono_grid_point_sat_los = @_io.read_u1
      self
    end

    ##
    # GNSS reference time of the observation used to generate the flag.
    attr_reader :obs_time

    ##
    # GNSS reference time of the correction associated to the flag.
    attr_reader :corr_time

    ##
    # SSR Solution ID.
    attr_reader :ssr_sol_id

    ##
    # Unique identifier of the set this tile belongs to.
    attr_reader :tile_set_id

    ##
    # Unique identifier of this tile in the tile set.
    attr_reader :tile_id

    ##
    # Chain and type of flag.
    attr_reader :chain_id

    ##
    # Use GPS satellites.
    attr_reader :use_gps_sat

    ##
    # Use GAL satellites.
    attr_reader :use_gal_sat

    ##
    # Use BDS satellites.
    attr_reader :use_bds_sat

    ##
    # Reserved
    attr_reader :reserved

    ##
    # Use tropo grid points.
    attr_reader :use_tropo_grid_points

    ##
    # Use iono grid points.
    attr_reader :use_iono_grid_points

    ##
    # Use iono tile satellite LoS.
    attr_reader :use_iono_tile_sat_los

    ##
    # Use iono grid point satellite LoS.
    attr_reader :use_iono_grid_point_sat_los
  end
end
