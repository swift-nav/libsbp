# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Orientation < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # This message reports the baseline heading pointing from the base station
  # to the rover relative to True North. The full GPS time is given by the
  # preceding MSG_GPS_TIME with the matching time-of-week (tow). It is
  # intended that time-matched RTK mode is used when the base station is
  # moving.
  class MsgBaselineHeading < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @heading = @_io.read_u4le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Heading
    attr_reader :heading

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the quaternion vector describing the vehicle body
  # frame's orientation with respect to a local-level NED frame. The
  # components of the vector should sum to a unit vector assuming that the
  # LSB of each component as a value of 2^-31. This message will only be
  # available in future INS versions of Swift Products and is not produced
  # by Piksi Multi or Duro.
  class MsgOrientQuat < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @w = @_io.read_s4le
      @x = @_io.read_s4le
      @y = @_io.read_s4le
      @z = @_io.read_s4le
      @w_accuracy = @_io.read_f4le
      @x_accuracy = @_io.read_f4le
      @y_accuracy = @_io.read_f4le
      @z_accuracy = @_io.read_f4le
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Real component
    attr_reader :w

    ##
    # 1st imaginary component
    attr_reader :x

    ##
    # 2nd imaginary component
    attr_reader :y

    ##
    # 3rd imaginary component
    attr_reader :z

    ##
    # Estimated standard deviation of w
    attr_reader :w_accuracy

    ##
    # Estimated standard deviation of x
    attr_reader :x_accuracy

    ##
    # Estimated standard deviation of y
    attr_reader :y_accuracy

    ##
    # Estimated standard deviation of z
    attr_reader :z_accuracy

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the yaw, pitch, and roll angles of the vehicle body
  # frame. The rotations should applied intrinsically in the order yaw,
  # pitch, and roll in order to rotate the from a frame aligned with the
  # local-level NED frame to the vehicle body frame.  This message will only
  # be available in future INS versions of Swift Products and is not
  # produced by Piksi Multi or Duro.
  class MsgOrientEuler < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @roll = @_io.read_s4le
      @pitch = @_io.read_s4le
      @yaw = @_io.read_s4le
      @roll_accuracy = @_io.read_f4le
      @pitch_accuracy = @_io.read_f4le
      @yaw_accuracy = @_io.read_f4le
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # rotation about the forward axis of the vehicle
    attr_reader :roll

    ##
    # rotation about the rightward axis of the vehicle
    attr_reader :pitch

    ##
    # rotation about the downward axis of the vehicle
    attr_reader :yaw

    ##
    # Estimated standard deviation of roll
    attr_reader :roll_accuracy

    ##
    # Estimated standard deviation of pitch
    attr_reader :pitch_accuracy

    ##
    # Estimated standard deviation of yaw
    attr_reader :yaw_accuracy

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the orientation rates in the vehicle body frame.
  # The values represent the measurements a strapped down gyroscope would
  # make and are not equivalent to the time derivative of the Euler angles.
  # The orientation and origin of the user frame is specified via device
  # settings. By convention, the vehicle x-axis is expected to be aligned
  # with the forward direction, while the vehicle y-axis is expected to be
  # aligned with the right direction, and the vehicle z-axis should be
  # aligned with the down direction. This message will only be available in
  # future INS versions of Swift Products and is not produced by Piksi Multi
  # or Duro.
  class MsgAngularRate < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @x = @_io.read_s4le
      @y = @_io.read_s4le
      @z = @_io.read_s4le
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # angular rate about x axis
    attr_reader :x

    ##
    # angular rate about y axis
    attr_reader :y

    ##
    # angular rate about z axis
    attr_reader :z

    ##
    # Status flags
    attr_reader :flags
  end
end
