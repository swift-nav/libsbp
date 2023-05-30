# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Vehicle < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # Message representing the x component of vehicle velocity in the user
  # frame at the odometry reference point(s) specified by the user. The
  # offset for the odometry reference point and the definition and origin of
  # the user frame are defined through the device settings interface. There
  # are 4 possible user-defined sources of this message which are labeled
  # arbitrarily source 0 through 3. If using "processor time" time tags, the
  # receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix
  # becomes available to synchronise odometry measurements with GNSS.
  # Processor time shall roll over to zero after one week.
  class MsgOdometry < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @velocity = @_io.read_s4le
      @flags = @_io.read_u1
      self
    end

    ##
    # Time field representing either milliseconds in the GPS Week or local
    # CPU time from the producing system in milliseconds.  See the
    # tow_source flag for the exact source of this timestamp.
    attr_reader :tow

    ##
    # The signed forward component of vehicle velocity.
    attr_reader :velocity

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # Message containing the accumulated distance travelled by a wheel located
  # at an odometry reference point defined by the user. The offset for the
  # odometry reference point and the definition and origin of the user frame
  # are defined through the device settings interface. The source of this
  # message is identified by the source field, which is an integer ranging
  # from 0 to 255. The timestamp associated with this message should
  # represent the time when the accumulated tick count reached the value
  # given by the contents of this message as accurately as possible. If
  # using "local CPU time" time tags, the receiving end will expect a
  # `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to synchronise
  # wheeltick measurements with GNSS. Local CPU time shall roll over to zero
  # after one week.
  class MsgWheeltick < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @time = @_io.read_u8le
      @flags = @_io.read_u1
      @source = @_io.read_u1
      @ticks = @_io.read_s4le
      self
    end

    ##
    # Time field representing either microseconds since the last PPS,
    # microseconds in the GPS Week or local CPU time from the producing
    # system in microseconds. See the synch_type field for the exact
    # meaning of this timestamp.
    attr_reader :time

    ##
    # Field indicating the type of timestamp contained in the time field.
    attr_reader :flags

    ##
    # ID of the sensor producing this message
    attr_reader :source

    ##
    # Free-running counter of the accumulated distance for this sensor.
    # The counter should be incrementing if travelling into one direction
    # and decrementing when travelling in the opposite direction.
    attr_reader :ticks
  end
end
