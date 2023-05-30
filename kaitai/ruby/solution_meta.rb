# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class SolutionMeta < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # Metadata around the GNSS sensors involved in the fuzed solution.
  # Accessible through sol_in[N].flags in a MSG_SOLN_META.
  class GnssInputType < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @flags = @_io.read_u1
      self
    end

    ##
    # flags that store all relevant info specific to this sensor type.
    attr_reader :flags
  end

  ##
  # This message contains all metadata about the sensors received and/or
  # used in computing the sensorfusion solution. It focuses primarily, but
  # not only, on GNSS metadata. Regarding the age of the last received valid
  # GNSS solution, the highest two bits are time status, indicating whether
  # age gnss can or can not be used to retrieve time of measurement (noted
  # TOM, also known as time of validity) If it can, subtract 'age gnss' from
  # 'tow' in navigation messages to get TOM. Can be used before alignment is
  # complete in the Fusion Engine, when output solution is the last received
  # valid GNSS solution and its tow is not a TOM.
  class MsgSolnMeta < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @pdop = @_io.read_u2le
      @hdop = @_io.read_u2le
      @vdop = @_io.read_u2le
      @age_corrections = @_io.read_u2le
      @age_gnss = @_io.read_u4le
      @sol_in = []
      i = 0
      while not @_io.eof?
        @sol_in << SolutionInputType.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # GPS time of week rounded to the nearest millisecond
    attr_reader :tow

    ##
    # Position Dilution of Precision as per last available DOPS from PVT
    # engine (0xFFFF indicates invalid)
    attr_reader :pdop

    ##
    # Horizontal Dilution of Precision as per last available DOPS from PVT
    # engine (0xFFFF indicates invalid)
    attr_reader :hdop

    ##
    # Vertical Dilution of Precision as per last available DOPS from PVT
    # engine (0xFFFF indicates invalid)
    attr_reader :vdop

    ##
    # Age of corrections as per last available AGE_CORRECTIONS from PVT
    # engine (0xFFFF indicates invalid)
    attr_reader :age_corrections

    ##
    # Age and Time Status of the last received valid GNSS solution.
    attr_reader :age_gnss

    ##
    # Array of Metadata describing the sensors potentially involved in the
    # solution. Each element in the array represents a single sensor type
    # and consists of flags containing (meta)data pertaining to that
    # specific single sensor. Refer to each (XX)InputType descriptor in
    # the present doc.
    attr_reader :sol_in
  end

  ##
  # Deprecated.
  # 
  # This message contains all metadata about the sensors received and/or
  # used in computing the Fuzed Solution. It focuses primarily, but not
  # only, on GNSS metadata.
  class MsgSolnMetaDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @pdop = @_io.read_u2le
      @hdop = @_io.read_u2le
      @vdop = @_io.read_u2le
      @n_sats = @_io.read_u1
      @age_corrections = @_io.read_u2le
      @alignment_status = @_io.read_u1
      @last_used_gnss_pos_tow = @_io.read_u4le
      @last_used_gnss_vel_tow = @_io.read_u4le
      @sol_in = []
      i = 0
      while not @_io.eof?
        @sol_in << SolutionInputType.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Position Dilution of Precision as per last available DOPS from PVT
    # engine (0xFFFF indicates invalid)
    attr_reader :pdop

    ##
    # Horizontal Dilution of Precision as per last available DOPS from PVT
    # engine (0xFFFF indicates invalid)
    attr_reader :hdop

    ##
    # Vertical Dilution of Precision as per last available DOPS from PVT
    # engine (0xFFFF indicates invalid)
    attr_reader :vdop

    ##
    # Number of satellites as per last available solution from PVT engine
    attr_reader :n_sats

    ##
    # Age of corrections as per last available AGE_CORRECTIONS from PVT
    # engine (0xFFFF indicates invalid)
    attr_reader :age_corrections

    ##
    # State of alignment and the status and receipt of the alignment
    # inputs
    attr_reader :alignment_status

    ##
    # Tow of last-used GNSS position measurement
    attr_reader :last_used_gnss_pos_tow

    ##
    # Tow of last-used GNSS velocity measurement
    attr_reader :last_used_gnss_vel_tow

    ##
    # Array of Metadata describing the sensors potentially involved in the
    # solution. Each element in the array represents a single sensor type
    # and consists of flags containing (meta)data pertaining to that
    # specific single sensor. Refer to each (XX)InputType descriptor in
    # the present doc.
    attr_reader :sol_in
  end

  ##
  # Metadata around the IMU sensors involved in the fuzed solution.
  # Accessible through sol_in[N].flags in a MSG_SOLN_META.
  class ImuInputType < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @flags = @_io.read_u1
      self
    end

    ##
    # Instrument time, grade, and architecture for a sensor.
    attr_reader :flags
  end

  ##
  # Metadata around the Odometry sensors involved in the fuzed solution.
  # Accessible through sol_in[N].flags in a MSG_SOLN_META.
  class OdoInputType < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @flags = @_io.read_u1
      self
    end

    ##
    # Instrument ODO rate, grade, and quality.
    attr_reader :flags
  end

  ##
  # Metadata describing which sensors were involved in the solution. The
  # structure is fixed no matter what the actual sensor type is. The
  # sensor_type field tells you which sensor we are talking about. It also
  # tells you whether the sensor data was actually used or not. The flags
  # field, always a u8, contains the sensor-specific data. The content of
  # flags, for each sensor type, is described in the relevant structures in
  # this section.
  class SolutionInputType < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sensor_type = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # The type of sensor
    attr_reader :sensor_type

    ##
    # Refer to each InputType description
    attr_reader :flags
  end
end
