# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Navigation < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # This position solution message reports the absolute geodetic coordinates
  # and the status (single point vs pseudo-absolute RTK) of the position
  # solution. If the rover receiver knows the surveyed position of the base
  # station and has an RTK solution, this reports a pseudo-absolute position
  # solution using the base station position and the rover's RTK baseline
  # vector. The full GPS time is given by the preceding MSG_GPS_TIME with
  # the matching time-of-week (tow).
  class MsgPosLlhDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @lat = @_io.read_f8le
      @lon = @_io.read_f8le
      @height = @_io.read_f8le
      @h_accuracy = @_io.read_u2le
      @v_accuracy = @_io.read_u2le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Latitude
    attr_reader :lat

    ##
    # Longitude
    attr_reader :lon

    ##
    # Height
    attr_reader :height

    ##
    # Horizontal position accuracy estimate (not implemented). Defaults to
    # 0.
    attr_reader :h_accuracy

    ##
    # Vertical position accuracy estimate (not implemented). Defaults to
    # 0.
    attr_reader :v_accuracy

    ##
    # Number of satellites used in solution.
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the local vertical and horizontal protection levels
  # associated with a given LLH position solution. The full GPS time is
  # given by the preceding MSG_GPS_TIME with the matching time-of-week
  # (tow).
  class MsgProtectionLevelDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @vpl = @_io.read_u2le
      @hpl = @_io.read_u2le
      @lat = @_io.read_f8le
      @lon = @_io.read_f8le
      @height = @_io.read_f8le
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Vertical protection level
    attr_reader :vpl

    ##
    # Horizontal protection level
    attr_reader :hpl

    ##
    # Latitude
    attr_reader :lat

    ##
    # Longitude
    attr_reader :lon

    ##
    # Height
    attr_reader :height

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This position solution message reports the absolute geodetic coordinates
  # and the status (single point vs pseudo-absolute RTK) of the position
  # solution as well as the upper triangle of the 3x3 covariance matrix.
  # The position information and Fix Mode flags follow the MSG_POS_LLH
  # message.  Since the covariance matrix is computed in the local-level
  # North, East, Down frame, the covariance terms follow that convention.
  # Thus, covariances are reported against the "downward" measurement and
  # care should be taken with the sign convention.
  class MsgPosLlhCov < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @lat = @_io.read_f8le
      @lon = @_io.read_f8le
      @height = @_io.read_f8le
      @cov_n_n = @_io.read_f4le
      @cov_n_e = @_io.read_f4le
      @cov_n_d = @_io.read_f4le
      @cov_e_e = @_io.read_f4le
      @cov_e_d = @_io.read_f4le
      @cov_d_d = @_io.read_f4le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Latitude
    attr_reader :lat

    ##
    # Longitude
    attr_reader :lon

    ##
    # Height above WGS84 ellipsoid
    attr_reader :height

    ##
    # Estimated variance of northing
    attr_reader :cov_n_n

    ##
    # Covariance of northing and easting
    attr_reader :cov_n_e

    ##
    # Covariance of northing and downward measurement
    attr_reader :cov_n_d

    ##
    # Estimated variance of easting
    attr_reader :cov_e_e

    ##
    # Covariance of easting and downward measurement
    attr_reader :cov_e_d

    ##
    # Estimated variance of downward measurement
    attr_reader :cov_d_d

    ##
    # Number of satellites used in solution.
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the velocity in local North East Down (NED)
  # coordinates. The NED coordinate system is defined as the local WGS84
  # tangent plane centered at the current position. The full GPS time is
  # given by the preceding MSG_GPS_TIME with the matching time-of-week
  # (tow).
  class MsgVelNedDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @n = @_io.read_s4le
      @e = @_io.read_s4le
      @d = @_io.read_s4le
      @h_accuracy = @_io.read_u2le
      @v_accuracy = @_io.read_u2le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Velocity North coordinate
    attr_reader :n

    ##
    # Velocity East coordinate
    attr_reader :e

    ##
    # Velocity Down coordinate
    attr_reader :d

    ##
    # Horizontal velocity accuracy estimate (not implemented). Defaults to
    # 0.
    attr_reader :h_accuracy

    ##
    # Vertical velocity accuracy estimate (not implemented). Defaults to
    # 0.
    attr_reader :v_accuracy

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags (reserved)
    attr_reader :flags
  end

  ##
  # This message reports the velocity in local North East Down (NED)
  # coordinates. The NED coordinate system is defined as the local WGS84
  # tangent plane centered at the current position. The full GPS time is
  # given by the preceding MSG_GPS_TIME with the matching time-of-week
  # (tow). This message is similar to the MSG_VEL_NED, but it includes the
  # upper triangular portion of the 3x3 covariance matrix.
  class MsgVelNedCov < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @n = @_io.read_s4le
      @e = @_io.read_s4le
      @d = @_io.read_s4le
      @cov_n_n = @_io.read_f4le
      @cov_n_e = @_io.read_f4le
      @cov_n_d = @_io.read_f4le
      @cov_e_e = @_io.read_f4le
      @cov_e_d = @_io.read_f4le
      @cov_d_d = @_io.read_f4le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Velocity North coordinate
    attr_reader :n

    ##
    # Velocity East coordinate
    attr_reader :e

    ##
    # Velocity Down coordinate
    attr_reader :d

    ##
    # Estimated variance of northward measurement
    attr_reader :cov_n_n

    ##
    # Covariance of northward and eastward measurement
    attr_reader :cov_n_e

    ##
    # Covariance of northward and downward measurement
    attr_reader :cov_n_d

    ##
    # Estimated variance of eastward measurement
    attr_reader :cov_e_e

    ##
    # Covariance of eastward and downward measurement
    attr_reader :cov_e_d

    ##
    # Estimated variance of downward measurement
    attr_reader :cov_d_d

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the Universal Coordinated Time (UTC).  Note the
  # flags which indicate the source of the UTC offset value and source of
  # the time fix.
  class MsgUtcTime < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @flags = @_io.read_u1
      @tow = @_io.read_u4le
      @year = @_io.read_u2le
      @month = @_io.read_u1
      @day = @_io.read_u1
      @hours = @_io.read_u1
      @minutes = @_io.read_u1
      @seconds = @_io.read_u1
      @ns = @_io.read_u4le
      self
    end

    ##
    # Indicates source and time validity
    attr_reader :flags

    ##
    # GPS time of week rounded to the nearest millisecond
    attr_reader :tow

    ##
    # Year
    attr_reader :year

    ##
    # Month (range 1 .. 12)
    attr_reader :month

    ##
    # days in the month (range 1-31)
    attr_reader :day

    ##
    # hours of day (range 0-23)
    attr_reader :hours

    ##
    # minutes of hour (range 0-59)
    attr_reader :minutes

    ##
    # seconds of minute (range 0-60) rounded down
    attr_reader :seconds

    ##
    # nanoseconds of second (range 0-999999999)
    attr_reader :ns
  end

  ##
  # The position solution message reports absolute Earth Centered Earth
  # Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
  # RTK) of the position solution. The message also reports the upper
  # triangular portion of the 3x3 covariance matrix. If the receiver knows
  # the surveyed position of the base station and has an RTK solution, this
  # reports a pseudo-absolute position solution using the base station
  # position and the rover's RTK baseline vector. The full GPS time is given
  # by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
  class MsgPosEcefCovGnss < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @x = @_io.read_f8le
      @y = @_io.read_f8le
      @z = @_io.read_f8le
      @cov_x_x = @_io.read_f4le
      @cov_x_y = @_io.read_f4le
      @cov_x_z = @_io.read_f4le
      @cov_y_y = @_io.read_f4le
      @cov_y_z = @_io.read_f4le
      @cov_z_z = @_io.read_f4le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # ECEF X coordinate
    attr_reader :x

    ##
    # ECEF Y coordinate
    attr_reader :y

    ##
    # ECEF Z coordinate
    attr_reader :z

    ##
    # Estimated variance of x
    attr_reader :cov_x_x

    ##
    # Estimated covariance of x and y
    attr_reader :cov_x_y

    ##
    # Estimated covariance of x and z
    attr_reader :cov_x_z

    ##
    # Estimated variance of y
    attr_reader :cov_y_y

    ##
    # Estimated covariance of y and z
    attr_reader :cov_y_z

    ##
    # Estimated variance of z
    attr_reader :cov_z_z

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the velocity in local North East Down (NED)
  # coordinates. The NED coordinate system is defined as the local WGS84
  # tangent plane centered at the current position. The full GPS time is
  # given by the preceding MSG_GPS_TIME with the matching time-of-week
  # (tow).
  class MsgVelNedGnss < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @n = @_io.read_s4le
      @e = @_io.read_s4le
      @d = @_io.read_s4le
      @h_accuracy = @_io.read_u2le
      @v_accuracy = @_io.read_u2le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Velocity North coordinate
    attr_reader :n

    ##
    # Velocity East coordinate
    attr_reader :e

    ##
    # Velocity Down coordinate
    attr_reader :d

    ##
    # Horizontal velocity estimated standard deviation
    attr_reader :h_accuracy

    ##
    # Vertical velocity estimated standard deviation
    attr_reader :v_accuracy

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the velocity in local North East Down (NED)
  # coordinates. The NED coordinate system is defined as the local WGS84
  # tangent plane centered at the current position. The full GPS time is
  # given by the preceding MSG_GPS_TIME with the matching time-of-week
  # (tow). This message is similar to the MSG_VEL_NED, but it includes the
  # upper triangular portion of the 3x3 covariance matrix.
  class MsgVelNedCovGnss < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @n = @_io.read_s4le
      @e = @_io.read_s4le
      @d = @_io.read_s4le
      @cov_n_n = @_io.read_f4le
      @cov_n_e = @_io.read_f4le
      @cov_n_d = @_io.read_f4le
      @cov_e_e = @_io.read_f4le
      @cov_e_d = @_io.read_f4le
      @cov_d_d = @_io.read_f4le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Velocity North coordinate
    attr_reader :n

    ##
    # Velocity East coordinate
    attr_reader :e

    ##
    # Velocity Down coordinate
    attr_reader :d

    ##
    # Estimated variance of northward measurement
    attr_reader :cov_n_n

    ##
    # Covariance of northward and eastward measurement
    attr_reader :cov_n_e

    ##
    # Covariance of northward and downward measurement
    attr_reader :cov_n_d

    ##
    # Estimated variance of eastward measurement
    attr_reader :cov_e_e

    ##
    # Covariance of eastward and downward measurement
    attr_reader :cov_e_d

    ##
    # Estimated variance of downward measurement
    attr_reader :cov_d_d

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the baseline solution in North East Down (NED)
  # coordinates. This baseline is the relative vector distance from the base
  # station to the rover receiver, and NED coordinate system is defined at
  # the local WGS84 tangent plane centered at the base station position.
  # The full GPS time is given by the preceding MSG_GPS_TIME with the
  # matching time-of-week (tow).
  class MsgBaselineNedDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @n = @_io.read_s4le
      @e = @_io.read_s4le
      @d = @_io.read_s4le
      @h_accuracy = @_io.read_u2le
      @v_accuracy = @_io.read_u2le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Baseline North coordinate
    attr_reader :n

    ##
    # Baseline East coordinate
    attr_reader :e

    ##
    # Baseline Down coordinate
    attr_reader :d

    ##
    # Horizontal position accuracy estimate (not implemented). Defaults to
    # 0.
    attr_reader :h_accuracy

    ##
    # Vertical position accuracy estimate (not implemented). Defaults to
    # 0.
    attr_reader :v_accuracy

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the velocity in Earth Centered Earth Fixed (ECEF)
  # coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
  # with the matching time-of-week (tow).
  class MsgVelEcefDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @x = @_io.read_s4le
      @y = @_io.read_s4le
      @z = @_io.read_s4le
      @accuracy = @_io.read_u2le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Velocity ECEF X coordinate
    attr_reader :x

    ##
    # Velocity ECEF Y coordinate
    attr_reader :y

    ##
    # Velocity ECEF Z coordinate
    attr_reader :z

    ##
    # Velocity accuracy estimate (not implemented). Defaults to 0.
    attr_reader :accuracy

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags (reserved)
    attr_reader :flags
  end
  class MsgReferenceFrameParam < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @ssr_iod = @_io.read_u1
      @sn = (@_io.read_bytes_full).force_encoding("ascii")
      @tn = (@_io.read_bytes_full).force_encoding("ascii")
      @sin = @_io.read_u1
      @utn = @_io.read_u2le
      @re_t0 = @_io.read_u2le
      @delta_x0 = @_io.read_s4le
      @delta_y0 = @_io.read_s4le
      @delta_z0 = @_io.read_s4le
      @theta_01 = @_io.read_s4le
      @theta_02 = @_io.read_s4le
      @theta_03 = @_io.read_s4le
      @scale = @_io.read_s4le
      @dot_delta_x0 = @_io.read_s4le
      @dot_delta_y0 = @_io.read_s4le
      @dot_delta_z0 = @_io.read_s4le
      @dot_theta_01 = @_io.read_s4le
      @dot_theta_02 = @_io.read_s4le
      @dot_theta_03 = @_io.read_s4le
      @dot_scale = @_io.read_s2le
      self
    end

    ##
    # SSR IOD parameter.
    attr_reader :ssr_iod

    ##
    # Name of source coordinate-system.
    attr_reader :sn

    ##
    # Name of target coordinate-system.
    attr_reader :tn

    ##
    # System Identification Number.
    attr_reader :sin

    ##
    # Utilized Transformation Message.
    attr_reader :utn

    ##
    # Reference Epoch t0 for transformation parameter set given as
    # Modified Julian Day (MJD) Number minus 44244 days.
    attr_reader :re_t0

    ##
    # Translation in X for Reference Epoch t0.
    attr_reader :delta_x0

    ##
    # Translation in Y for Reference Epoch t0.
    attr_reader :delta_y0

    ##
    # Translation in Z for Reference Epoch t0.
    attr_reader :delta_z0

    ##
    # Rotation around the X-axis for Reference Epoch t0.
    attr_reader :theta_01

    ##
    # Rotation around the Y-axis for Reference Epoch t0.
    attr_reader :theta_02

    ##
    # Rotation around the Z-axis for Reference Epoch t0.
    attr_reader :theta_03

    ##
    # Scale correction for Reference Epoch t0.
    attr_reader :scale

    ##
    # Rate of change of translation in X.
    attr_reader :dot_delta_x0

    ##
    # Rate of change of translation in Y.
    attr_reader :dot_delta_y0

    ##
    # Rate of change of translation in Z.
    attr_reader :dot_delta_z0

    ##
    # Rate of change of rotation around the X-axis.
    attr_reader :dot_theta_01

    ##
    # Rate of change of rotation around the Y-axis.
    attr_reader :dot_theta_02

    ##
    # Rate of change of rotation around the Z-axis.
    attr_reader :dot_theta_03

    ##
    # Rate of change of scale correction.
    attr_reader :dot_scale
  end

  ##
  # This solution message reports the relative pose of a sensor between two
  # time instances. The relative pose comprises of a rotation and a
  # translation which relates the sensor (e.g. camera) frame at a given time
  # (first keyframe) to the sensor frame at another time (second keyframe).
  # The relative translations is a 3x1 vector described in the first
  # keyframe.  Relative rotation is described by a quaternion from second
  # keyframe to the first keyframe.
  class MsgPoseRelative < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @sensor_id = @_io.read_u1
      @timestamp_1 = @_io.read_u4le
      @timestamp_2 = @_io.read_u4le
      @trans = []
      (3).times { |i|
        @trans << @_io.read_s4le
      }
      @w = @_io.read_s4le
      @x = @_io.read_s4le
      @y = @_io.read_s4le
      @z = @_io.read_s4le
      @cov_r_x_x = @_io.read_f4le
      @cov_r_x_y = @_io.read_f4le
      @cov_r_x_z = @_io.read_f4le
      @cov_r_y_y = @_io.read_f4le
      @cov_r_y_z = @_io.read_f4le
      @cov_r_z_z = @_io.read_f4le
      @cov_c_x_x = @_io.read_f4le
      @cov_c_x_y = @_io.read_f4le
      @cov_c_x_z = @_io.read_f4le
      @cov_c_y_y = @_io.read_f4le
      @cov_c_y_z = @_io.read_f4le
      @cov_c_z_z = @_io.read_f4le
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # ID of the sensor producing this message
    attr_reader :sensor_id

    ##
    # Timestamp of first keyframe
    attr_reader :timestamp_1

    ##
    # Timestamp of second keyframe
    attr_reader :timestamp_2

    ##
    # Relative translation [x,y,z] described in first keyframe
    attr_reader :trans

    ##
    # Real component of quaternion to describe relative rotation (second
    # to first keyframe)
    attr_reader :w

    ##
    # 1st imaginary component of quaternion to describe relative rotation
    # (second to first keyframe)
    attr_reader :x

    ##
    # 2nd imaginary component of quaternion to describe relative rotation
    # (second to first keyframe)
    attr_reader :y

    ##
    # 3rd imaginary component of quaternion to describe relative rotation
    # (second to first keyframe)
    attr_reader :z

    ##
    # Estimated variance of x (relative translation)
    attr_reader :cov_r_x_x

    ##
    # Covariance of x and y (relative translation)
    attr_reader :cov_r_x_y

    ##
    # Covariance of x and z (relative translation)
    attr_reader :cov_r_x_z

    ##
    # Estimated variance of y (relative translation)
    attr_reader :cov_r_y_y

    ##
    # Covariance of y and z (relative translation)
    attr_reader :cov_r_y_z

    ##
    # Estimated variance of z (relative translation)
    attr_reader :cov_r_z_z

    ##
    # Estimated variance of x (relative rotation)
    attr_reader :cov_c_x_x

    ##
    # Covariance of x and y (relative rotation)
    attr_reader :cov_c_x_y

    ##
    # Covariance of x and z (relative rotation)
    attr_reader :cov_c_x_z

    ##
    # Estimated variance of y (relative rotation)
    attr_reader :cov_c_y_y

    ##
    # Covariance of y and z (relative rotation)
    attr_reader :cov_c_y_z

    ##
    # Estimated variance of z (relative rotation)
    attr_reader :cov_c_z_z

    ##
    # Status flags of relative translation and rotation
    attr_reader :flags
  end

  ##
  # This message reports the velocity in Earth Centered Earth Fixed (ECEF)
  # coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
  # with the matching time-of-week (tow).
  class MsgVelEcefCov < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @x = @_io.read_s4le
      @y = @_io.read_s4le
      @z = @_io.read_s4le
      @cov_x_x = @_io.read_f4le
      @cov_x_y = @_io.read_f4le
      @cov_x_z = @_io.read_f4le
      @cov_y_y = @_io.read_f4le
      @cov_y_z = @_io.read_f4le
      @cov_z_z = @_io.read_f4le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Velocity ECEF X coordinate
    attr_reader :x

    ##
    # Velocity ECEF Y coordinate
    attr_reader :y

    ##
    # Velocity ECEF Z coordinate
    attr_reader :z

    ##
    # Estimated variance of x
    attr_reader :cov_x_x

    ##
    # Estimated covariance of x and y
    attr_reader :cov_x_y

    ##
    # Estimated covariance of x and z
    attr_reader :cov_x_z

    ##
    # Estimated variance of y
    attr_reader :cov_y_y

    ##
    # Estimated covariance of y and z
    attr_reader :cov_y_z

    ##
    # Estimated variance of z
    attr_reader :cov_z_z

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the velocity in the Vehicle Body Frame. By
  # convention, the x-axis should point out the nose of the vehicle and
  # represent the forward direction, while as the y-axis should point out
  # the right hand side of the vehicle. Since this is a right handed system,
  # z should point out the bottom of the vehicle. The orientation and origin
  # of the Vehicle Body Frame are specified via the device settings. The
  # full GPS time is given by the preceding MSG_GPS_TIME with the matching
  # time-of-week (tow). This message is only produced by inertial versions
  # of Swift products and is not available from Piksi Multi or Duro.
  class MsgVelBody < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @x = @_io.read_s4le
      @y = @_io.read_s4le
      @z = @_io.read_s4le
      @cov_x_x = @_io.read_f4le
      @cov_x_y = @_io.read_f4le
      @cov_x_z = @_io.read_f4le
      @cov_y_y = @_io.read_f4le
      @cov_y_z = @_io.read_f4le
      @cov_z_z = @_io.read_f4le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Velocity in x direction
    attr_reader :x

    ##
    # Velocity in y direction
    attr_reader :y

    ##
    # Velocity in z direction
    attr_reader :z

    ##
    # Estimated variance of x
    attr_reader :cov_x_x

    ##
    # Covariance of x and y
    attr_reader :cov_x_y

    ##
    # Covariance of x and z
    attr_reader :cov_x_z

    ##
    # Estimated variance of y
    attr_reader :cov_y_y

    ##
    # Covariance of y and z
    attr_reader :cov_y_z

    ##
    # Estimated variance of z
    attr_reader :cov_z_z

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the velocity in Earth Centered Earth Fixed (ECEF)
  # coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
  # with the matching time-of-week (tow).
  class MsgVelEcefGnss < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @x = @_io.read_s4le
      @y = @_io.read_s4le
      @z = @_io.read_s4le
      @accuracy = @_io.read_u2le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Velocity ECEF X coordinate
    attr_reader :x

    ##
    # Velocity ECEF Y coordinate
    attr_reader :y

    ##
    # Velocity ECEF Z coordinate
    attr_reader :z

    ##
    # Velocity estimated standard deviation
    attr_reader :accuracy

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the velocity in Earth Centered Earth Fixed (ECEF)
  # coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
  # with the matching time-of-week (tow).
  class MsgVelEcef < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @x = @_io.read_s4le
      @y = @_io.read_s4le
      @z = @_io.read_s4le
      @accuracy = @_io.read_u2le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Velocity ECEF X coordinate
    attr_reader :x

    ##
    # Velocity ECEF Y coordinate
    attr_reader :y

    ##
    # Velocity ECEF Z coordinate
    attr_reader :z

    ##
    # Velocity estimated standard deviation
    attr_reader :accuracy

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This position solution message reports the absolute geodetic coordinates
  # and the status (single point vs pseudo-absolute RTK) of the position
  # solution as well as the upper triangle of the 3x3 covariance matrix.
  # The position information and Fix Mode flags should follow the
  # MSG_POS_LLH message.  Since the covariance matrix is computed in the
  # local-level North, East, Down frame, the covariance terms follow with
  # that convention. Thus, covariances are reported against the "downward"
  # measurement and care should be taken with the sign convention.
  class MsgPosLlhCovGnss < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @lat = @_io.read_f8le
      @lon = @_io.read_f8le
      @height = @_io.read_f8le
      @cov_n_n = @_io.read_f4le
      @cov_n_e = @_io.read_f4le
      @cov_n_d = @_io.read_f4le
      @cov_e_e = @_io.read_f4le
      @cov_e_d = @_io.read_f4le
      @cov_d_d = @_io.read_f4le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Latitude
    attr_reader :lat

    ##
    # Longitude
    attr_reader :lon

    ##
    # Height above WGS84 ellipsoid
    attr_reader :height

    ##
    # Estimated variance of northing
    attr_reader :cov_n_n

    ##
    # Covariance of northing and easting
    attr_reader :cov_n_e

    ##
    # Covariance of northing and downward measurement
    attr_reader :cov_n_d

    ##
    # Estimated variance of easting
    attr_reader :cov_e_e

    ##
    # Covariance of easting and downward measurement
    attr_reader :cov_e_d

    ##
    # Estimated variance of downward measurement
    attr_reader :cov_d_d

    ##
    # Number of satellites used in solution.
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the baseline solution in Earth Centered Earth Fixed
  # (ECEF) coordinates. This baseline is the relative vector distance from
  # the base station to the rover receiver. The full GPS time is given by
  # the preceding MSG_GPS_TIME with the matching time-of-week (tow).
  class MsgBaselineEcef < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @x = @_io.read_s4le
      @y = @_io.read_s4le
      @z = @_io.read_s4le
      @accuracy = @_io.read_u2le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Baseline ECEF X coordinate
    attr_reader :x

    ##
    # Baseline ECEF Y coordinate
    attr_reader :y

    ##
    # Baseline ECEF Z coordinate
    attr_reader :z

    ##
    # Position estimated standard deviation
    attr_reader :accuracy

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This dilution of precision (DOP) message describes the effect of
  # navigation satellite geometry on positional measurement precision.
  class MsgDopsDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @gdop = @_io.read_u2le
      @pdop = @_io.read_u2le
      @tdop = @_io.read_u2le
      @hdop = @_io.read_u2le
      @vdop = @_io.read_u2le
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Geometric Dilution of Precision
    attr_reader :gdop

    ##
    # Position Dilution of Precision
    attr_reader :pdop

    ##
    # Time Dilution of Precision
    attr_reader :tdop

    ##
    # Horizontal Dilution of Precision
    attr_reader :hdop

    ##
    # Vertical Dilution of Precision
    attr_reader :vdop
  end

  ##
  # The position solution message reports absolute Earth Centered Earth
  # Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
  # RTK) of the position solution. If the rover receiver knows the surveyed
  # position of the base station and has an RTK solution, this reports a
  # pseudo-absolute position solution using the base station position and
  # the rover's RTK baseline vector. The full GPS time is given by the
  # preceding MSG_GPS_TIME with the matching time-of-week (tow).
  class MsgPosEcef < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @x = @_io.read_f8le
      @y = @_io.read_f8le
      @z = @_io.read_f8le
      @accuracy = @_io.read_u2le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # ECEF X coordinate
    attr_reader :x

    ##
    # ECEF Y coordinate
    attr_reader :y

    ##
    # ECEF Z coordinate
    attr_reader :z

    ##
    # Position estimated standard deviation
    attr_reader :accuracy

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the Age of the corrections used for the current
  # Differential solution.
  class MsgAgeCorrections < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @age = @_io.read_u2le
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Age of the corrections (0xFFFF indicates invalid)
    attr_reader :age
  end

  ##
  # This message reports the velocity in Earth Centered Earth Fixed (ECEF)
  # coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
  # with the matching time-of-week (tow).
  class MsgVelEcefCovGnss < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @x = @_io.read_s4le
      @y = @_io.read_s4le
      @z = @_io.read_s4le
      @cov_x_x = @_io.read_f4le
      @cov_x_y = @_io.read_f4le
      @cov_x_z = @_io.read_f4le
      @cov_y_y = @_io.read_f4le
      @cov_y_z = @_io.read_f4le
      @cov_z_z = @_io.read_f4le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Velocity ECEF X coordinate
    attr_reader :x

    ##
    # Velocity ECEF Y coordinate
    attr_reader :y

    ##
    # Velocity ECEF Z coordinate
    attr_reader :z

    ##
    # Estimated variance of x
    attr_reader :cov_x_x

    ##
    # Estimated covariance of x and y
    attr_reader :cov_x_y

    ##
    # Estimated covariance of x and z
    attr_reader :cov_x_z

    ##
    # Estimated variance of y
    attr_reader :cov_y_y

    ##
    # Estimated covariance of y and z
    attr_reader :cov_y_z

    ##
    # Estimated variance of z
    attr_reader :cov_z_z

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the protection levels associated to the given state
  # estimate. The full GPS time is given by the preceding MSG_GPS_TIME with
  # the matching time-of-week (tow).
  class MsgProtectionLevel < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @wn = @_io.read_s2le
      @hpl = @_io.read_u2le
      @vpl = @_io.read_u2le
      @atpl = @_io.read_u2le
      @ctpl = @_io.read_u2le
      @hvpl = @_io.read_u2le
      @vvpl = @_io.read_u2le
      @hopl = @_io.read_u2le
      @popl = @_io.read_u2le
      @ropl = @_io.read_u2le
      @lat = @_io.read_f8le
      @lon = @_io.read_f8le
      @height = @_io.read_f8le
      @v_x = @_io.read_s4le
      @v_y = @_io.read_s4le
      @v_z = @_io.read_s4le
      @roll = @_io.read_s4le
      @pitch = @_io.read_s4le
      @heading = @_io.read_s4le
      @flags = @_io.read_u4le
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # GPS week number
    attr_reader :wn

    ##
    # Horizontal protection level
    attr_reader :hpl

    ##
    # Vertical protection level
    attr_reader :vpl

    ##
    # Along-track position error protection level
    attr_reader :atpl

    ##
    # Cross-track position error protection level
    attr_reader :ctpl

    ##
    # Protection level for the error vector between estimated and true
    # along/cross track velocity vector
    attr_reader :hvpl

    ##
    # Protection level for the velocity in vehicle upright direction
    # (different from vertical direction if on a slope)
    attr_reader :vvpl

    ##
    # Heading orientation protection level
    attr_reader :hopl

    ##
    # Pitch orientation protection level
    attr_reader :popl

    ##
    # Roll orientation protection level
    attr_reader :ropl

    ##
    # Latitude
    attr_reader :lat

    ##
    # Longitude
    attr_reader :lon

    ##
    # Height
    attr_reader :height

    ##
    # Velocity in vehicle x direction
    attr_reader :v_x

    ##
    # Velocity in vehicle y direction
    attr_reader :v_y

    ##
    # Velocity in vehicle z direction
    attr_reader :v_z

    ##
    # Roll angle
    attr_reader :roll

    ##
    # Pitch angle
    attr_reader :pitch

    ##
    # Heading angle
    attr_reader :heading

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # The position solution message reports absolute Earth Centered Earth
  # Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
  # RTK) of the position solution. The message also reports the upper
  # triangular portion of the 3x3 covariance matrix. If the receiver knows
  # the surveyed position of the base station and has an RTK solution, this
  # reports a pseudo-absolute position solution using the base station
  # position and the rover's RTK baseline vector. The full GPS time is given
  # by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
  class MsgPosEcefCov < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @x = @_io.read_f8le
      @y = @_io.read_f8le
      @z = @_io.read_f8le
      @cov_x_x = @_io.read_f4le
      @cov_x_y = @_io.read_f4le
      @cov_x_z = @_io.read_f4le
      @cov_y_y = @_io.read_f4le
      @cov_y_z = @_io.read_f4le
      @cov_z_z = @_io.read_f4le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # ECEF X coordinate
    attr_reader :x

    ##
    # ECEF Y coordinate
    attr_reader :y

    ##
    # ECEF Z coordinate
    attr_reader :z

    ##
    # Estimated variance of x
    attr_reader :cov_x_x

    ##
    # Estimated covariance of x and y
    attr_reader :cov_x_y

    ##
    # Estimated covariance of x and z
    attr_reader :cov_x_z

    ##
    # Estimated variance of y
    attr_reader :cov_y_y

    ##
    # Estimated covariance of y and z
    attr_reader :cov_y_z

    ##
    # Estimated variance of z
    attr_reader :cov_z_z

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # The position solution message reports absolute Earth Centered Earth
  # Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
  # RTK) of the position solution. If the rover receiver knows the surveyed
  # position of the base station and has an RTK solution, this reports a
  # pseudo-absolute position solution using the base station position and
  # the rover's RTK baseline vector. The full GPS time is given by the
  # preceding MSG_GPS_TIME with the matching time-of-week (tow).
  class MsgPosEcefGnss < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @x = @_io.read_f8le
      @y = @_io.read_f8le
      @z = @_io.read_f8le
      @accuracy = @_io.read_u2le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # ECEF X coordinate
    attr_reader :x

    ##
    # ECEF Y coordinate
    attr_reader :y

    ##
    # ECEF Z coordinate
    attr_reader :z

    ##
    # Position estimated standard deviation
    attr_reader :accuracy

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the velocity in local North East Down (NED)
  # coordinates. The NED coordinate system is defined as the local WGS84
  # tangent plane centered at the current position. The full GPS time is
  # given by the preceding MSG_GPS_TIME with the matching time-of-week
  # (tow).
  class MsgVelNed < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @n = @_io.read_s4le
      @e = @_io.read_s4le
      @d = @_io.read_s4le
      @h_accuracy = @_io.read_u2le
      @v_accuracy = @_io.read_u2le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Velocity North coordinate
    attr_reader :n

    ##
    # Velocity East coordinate
    attr_reader :e

    ##
    # Velocity Down coordinate
    attr_reader :d

    ##
    # Horizontal velocity estimated standard deviation
    attr_reader :h_accuracy

    ##
    # Vertical velocity estimated standard deviation
    attr_reader :v_accuracy

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # UTC-GPST leap seconds before and after the most recent (past, or future,
  # for announced insertions) UTC leap second insertion.
  class MsgUtcLeapSecond < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @reserved_0 = @_io.read_s2le
      @reserved_1 = @_io.read_s2le
      @reserved_2 = @_io.read_s1
      @count_before = @_io.read_s1
      @reserved_3 = @_io.read_u2le
      @reserved_4 = @_io.read_u2le
      @ref_wn = @_io.read_u2le
      @ref_dn = @_io.read_u1
      @count_after = @_io.read_s1
      self
    end

    ##
    # Reserved.
    attr_reader :reserved_0

    ##
    # Reserved.
    attr_reader :reserved_1

    ##
    # Reserved.
    attr_reader :reserved_2

    ##
    # Leap second count before insertion.
    attr_reader :count_before

    ##
    # Reserved.
    attr_reader :reserved_3

    ##
    # Reserved.
    attr_reader :reserved_4

    ##
    # Leap second reference GPS week number.
    attr_reader :ref_wn

    ##
    # Leap second reference day number.
    attr_reader :ref_dn

    ##
    # Leap second count after insertion.
    attr_reader :count_after
  end

  ##
  # This message reports the GPS time, representing the time since the GPS
  # epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
  # and seconds of the week. The weeks begin at the Saturday/Sunday
  # transition. GPS week 0 began at the beginning of the GPS time scale.
  # 
  # Within each week number, the GPS time of the week is between between 0
  # and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
  # leap seconds, and as of now, has a small offset from UTC. In a message
  # stream, this message precedes a set of other navigation messages
  # referenced to the same time (but lacking the ns field) and indicates a
  # more precise time of these messages.
  class MsgGpsTimeDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @wn = @_io.read_u2le
      @tow = @_io.read_u4le
      @ns_residual = @_io.read_s4le
      @flags = @_io.read_u1
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
    # Status flags (reserved)
    attr_reader :flags
  end

  ##
  # This position solution message reports the absolute geodetic coordinates
  # and the status (single point vs pseudo-absolute RTK) of the position
  # solution. If the rover receiver knows the surveyed position of the base
  # station and has an RTK solution, this reports a pseudo-absolute position
  # solution using the base station position and the rover's RTK baseline
  # vector. The full GPS time is given by the preceding MSG_GPS_TIME with
  # the matching time-of-week (tow).
  class MsgPosLlhGnss < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @lat = @_io.read_f8le
      @lon = @_io.read_f8le
      @height = @_io.read_f8le
      @h_accuracy = @_io.read_u2le
      @v_accuracy = @_io.read_u2le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Latitude
    attr_reader :lat

    ##
    # Longitude
    attr_reader :lon

    ##
    # Height above WGS84 ellipsoid
    attr_reader :height

    ##
    # Horizontal position estimated standard deviation
    attr_reader :h_accuracy

    ##
    # Vertical position estimated standard deviation
    attr_reader :v_accuracy

    ##
    # Number of satellites used in solution.
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the Universal Coordinated Time (UTC).  Note the
  # flags which indicate the source of the UTC offset value and source of
  # the time fix.
  class MsgUtcTimeGnss < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @flags = @_io.read_u1
      @tow = @_io.read_u4le
      @year = @_io.read_u2le
      @month = @_io.read_u1
      @day = @_io.read_u1
      @hours = @_io.read_u1
      @minutes = @_io.read_u1
      @seconds = @_io.read_u1
      @ns = @_io.read_u4le
      self
    end

    ##
    # Indicates source and time validity
    attr_reader :flags

    ##
    # GPS time of week rounded to the nearest millisecond
    attr_reader :tow

    ##
    # Year
    attr_reader :year

    ##
    # Month (range 1 .. 12)
    attr_reader :month

    ##
    # days in the month (range 1-31)
    attr_reader :day

    ##
    # hours of day (range 0-23)
    attr_reader :hours

    ##
    # minutes of hour (range 0-59)
    attr_reader :minutes

    ##
    # seconds of minute (range 0-60) rounded down
    attr_reader :seconds

    ##
    # nanoseconds of second (range 0-999999999)
    attr_reader :ns
  end

  ##
  # This message reports the receiver course over ground (COG) and speed
  # over  ground (SOG) based on the horizontal (N-E) components of the NED
  # velocity  vector. It also includes the vertical velocity coordinate. A
  # flag is provided to indicate whether the COG value has been frozen. When
  # the flag is set to true, the COG field is set to its last valid value
  # until  the system exceeds a minimum velocity threshold. No other fields
  # are  affected by this flag.  The NED coordinate system is defined as the
  # local WGS84 tangent  plane centered at the current position. The full
  # GPS time is given by the  preceding MSG_GPS_TIME with the matching time-
  # of-week (tow). Note: course over ground represents the receiver's
  # direction of travel,  but not necessarily the device heading.
  class MsgVelCog < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @cog = @_io.read_u4le
      @sog = @_io.read_u4le
      @v_up = @_io.read_s4le
      @cog_accuracy = @_io.read_u4le
      @sog_accuracy = @_io.read_u4le
      @v_up_accuracy = @_io.read_u4le
      @flags = @_io.read_u2le
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Course over ground relative to north direction
    attr_reader :cog

    ##
    # Speed over ground (based on horizontal velocity)
    attr_reader :sog

    ##
    # Vertical velocity component (positive up)
    attr_reader :v_up

    ##
    # Course over ground estimated standard deviation
    attr_reader :cog_accuracy

    ##
    # Speed over ground estimated standard deviation
    attr_reader :sog_accuracy

    ##
    # Vertical velocity estimated standard deviation
    attr_reader :v_up_accuracy

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the baseline solution in North East Down (NED)
  # coordinates. This baseline is the relative vector distance from the base
  # station to the rover receiver, and NED coordinate system is defined at
  # the local WGS84 tangent plane centered at the base station position.
  # The full GPS time is given by the preceding MSG_GPS_TIME with the
  # matching time-of-week (tow).
  class MsgBaselineNed < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @n = @_io.read_s4le
      @e = @_io.read_s4le
      @d = @_io.read_s4le
      @h_accuracy = @_io.read_u2le
      @v_accuracy = @_io.read_u2le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Baseline North coordinate
    attr_reader :n

    ##
    # Baseline East coordinate
    attr_reader :e

    ##
    # Baseline Down coordinate
    attr_reader :d

    ##
    # Horizontal position estimated standard deviation
    attr_reader :h_accuracy

    ##
    # Vertical position estimated standard deviation
    attr_reader :v_accuracy

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This position solution message reports the absolute geodetic coordinates
  # and the status (single point vs pseudo-absolute RTK) of the position
  # solution. If the rover receiver knows the surveyed position of the base
  # station and has an RTK solution, this reports a pseudo-absolute position
  # solution using the base station position and the rover's RTK baseline
  # vector. The full GPS time is given by the preceding MSG_GPS_TIME with
  # the matching time-of-week (tow).
  class MsgPosLlh < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @lat = @_io.read_f8le
      @lon = @_io.read_f8le
      @height = @_io.read_f8le
      @h_accuracy = @_io.read_u2le
      @v_accuracy = @_io.read_u2le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Latitude
    attr_reader :lat

    ##
    # Longitude
    attr_reader :lon

    ##
    # Height above WGS84 ellipsoid
    attr_reader :height

    ##
    # Horizontal position estimated standard deviation
    attr_reader :h_accuracy

    ##
    # Vertical position estimated standard deviation
    attr_reader :v_accuracy

    ##
    # Number of satellites used in solution.
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the baseline heading pointing from the base station
  # to the rover relative to True North. The full GPS time is given by the
  # preceding MSG_GPS_TIME with the matching time-of-week (tow).
  class MsgBaselineHeadingDepA < Kaitai::Struct::Struct
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
  # This message reports the GPS time, representing the time since the GPS
  # epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
  # and seconds of the week. The weeks begin at the Saturday/Sunday
  # transition. GPS week 0 began at the beginning of the GPS time scale.
  # 
  # Within each week number, the GPS time of the week is between between 0
  # and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
  # leap seconds, and as of now, has a small offset from UTC. In a message
  # stream, this message precedes a set of other navigation messages
  # referenced to the same time (but lacking the ns field) and indicates a
  # more precise time of these messages.
  class MsgGpsTimeGnss < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @wn = @_io.read_u2le
      @tow = @_io.read_u4le
      @ns_residual = @_io.read_s4le
      @flags = @_io.read_u1
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
    # Status flags (reserved)
    attr_reader :flags
  end

  ##
  # This message reports the baseline solution in Earth Centered Earth Fixed
  # (ECEF) coordinates. This baseline is the relative vector distance from
  # the base station to the rover receiver. The full GPS time is given by
  # the preceding MSG_GPS_TIME with the matching time-of-week (tow).
  class MsgBaselineEcefDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @x = @_io.read_s4le
      @y = @_io.read_s4le
      @z = @_io.read_s4le
      @accuracy = @_io.read_u2le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Baseline ECEF X coordinate
    attr_reader :x

    ##
    # Baseline ECEF Y coordinate
    attr_reader :y

    ##
    # Baseline ECEF Z coordinate
    attr_reader :z

    ##
    # Position accuracy estimate
    attr_reader :accuracy

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end

  ##
  # This message reports the GPS time, representing the time since the GPS
  # epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
  # and seconds of the week. The weeks begin at the Saturday/Sunday
  # transition. GPS week 0 began at the beginning of the GPS time scale.
  # 
  # Within each week number, the GPS time of the week is between between 0
  # and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
  # leap seconds, and as of now, has a small offset from UTC. In a message
  # stream, this message precedes a set of other navigation messages
  # referenced to the same time (but lacking the ns field) and indicates a
  # more precise time of these messages.
  class MsgGpsTime < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @wn = @_io.read_u2le
      @tow = @_io.read_u4le
      @ns_residual = @_io.read_s4le
      @flags = @_io.read_u1
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
    # Status flags (reserved)
    attr_reader :flags
  end

  ##
  # This dilution of precision (DOP) message describes the effect of
  # navigation satellite geometry on positional measurement precision.  The
  # flags field indicated whether the DOP reported corresponds to
  # differential or SPP solution.
  class MsgDops < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @gdop = @_io.read_u2le
      @pdop = @_io.read_u2le
      @tdop = @_io.read_u2le
      @hdop = @_io.read_u2le
      @vdop = @_io.read_u2le
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Geometric Dilution of Precision
    attr_reader :gdop

    ##
    # Position Dilution of Precision
    attr_reader :pdop

    ##
    # Time Dilution of Precision
    attr_reader :tdop

    ##
    # Horizontal Dilution of Precision
    attr_reader :hdop

    ##
    # Vertical Dilution of Precision
    attr_reader :vdop

    ##
    # Indicates the position solution with which the DOPS message
    # corresponds
    attr_reader :flags
  end

  ##
  # The position solution message reports absolute Earth Centered Earth
  # Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
  # RTK) of the position solution. If the rover receiver knows the surveyed
  # position of the base station and has an RTK solution, this reports a
  # pseudo-absolute position solution using the base station position and
  # the rover's RTK baseline vector. The full GPS time is given by the
  # preceding MSG_GPS_TIME with the matching time-of-week (tow).
  class MsgPosEcefDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @x = @_io.read_f8le
      @y = @_io.read_f8le
      @z = @_io.read_f8le
      @accuracy = @_io.read_u2le
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # ECEF X coordinate
    attr_reader :x

    ##
    # ECEF Y coordinate
    attr_reader :y

    ##
    # ECEF Z coordinate
    attr_reader :z

    ##
    # Position accuracy estimate (not implemented). Defaults to 0.
    attr_reader :accuracy

    ##
    # Number of satellites used in solution
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end
  class EstimatedHorizontalErrorEllipse < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @semi_major = @_io.read_f4le
      @semi_minor = @_io.read_f4le
      @orientation = @_io.read_f4le
      self
    end

    ##
    # The semi major axis of the estimated horizontal error ellipse at the
    # user-configured confidence level; zero implies invalid.
    attr_reader :semi_major

    ##
    # The semi minor axis of the estimated horizontal error ellipse at the
    # user-configured confidence level; zero implies invalid.
    attr_reader :semi_minor

    ##
    # The orientation of the semi major axis of the estimated horizontal
    # error ellipse with respect to North.
    attr_reader :orientation
  end

  ##
  # This position solution message reports the absolute geodetic coordinates
  # and the status (single point vs pseudo-absolute RTK) of the position
  # solution as well as the estimated horizontal, vertical, cross-track and
  # along-track errors.  The position information and Fix Mode flags  follow
  # the MSG_POS_LLH message. Since the covariance matrix is computed in the
  # local-level North, East, Down frame, the estimated error terms follow
  # that convention.
  # 
  # The estimated errors are reported at a user-configurable confidence
  # level. The user-configured percentile is encoded in the percentile
  # field.
  class MsgPosLlhAcc < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @lat = @_io.read_f8le
      @lon = @_io.read_f8le
      @height = @_io.read_f8le
      @orthometric_height = @_io.read_f8le
      @h_accuracy = @_io.read_f4le
      @v_accuracy = @_io.read_f4le
      @ct_accuracy = @_io.read_f4le
      @at_accuracy = @_io.read_f4le
      @h_ellipse = EstimatedHorizontalErrorEllipse.new(@_io, self, @_root)
      @confidence_and_geoid = @_io.read_u1
      @n_sats = @_io.read_u1
      @flags = @_io.read_u1
      self
    end

    ##
    # GPS Time of Week
    attr_reader :tow

    ##
    # Latitude
    attr_reader :lat

    ##
    # Longitude
    attr_reader :lon

    ##
    # Height above WGS84 ellipsoid
    attr_reader :height

    ##
    # Height above the geoid (i.e. height above mean sea level). See
    # confidence_and_geoid for geoid model used.
    attr_reader :orthometric_height

    ##
    # Estimated horizontal error at the user-configured confidence level;
    # zero implies invalid.
    attr_reader :h_accuracy

    ##
    # Estimated vertical error at the user-configured confidence level;
    # zero implies invalid.
    attr_reader :v_accuracy

    ##
    # Estimated cross-track error at the user-configured confidence level;
    # zero implies invalid.
    attr_reader :ct_accuracy

    ##
    # Estimated along-track error at the user-configured confidence level;
    # zero implies invalid.
    attr_reader :at_accuracy

    ##
    # The estimated horizontal error ellipse at the user-configured
    # confidence level.
    attr_reader :h_ellipse

    ##
    # The lower bits describe the configured confidence level for the
    # estimated position error. The middle bits describe the geoid model
    # used to calculate the orthometric height.
    attr_reader :confidence_and_geoid

    ##
    # Number of satellites used in solution.
    attr_reader :n_sats

    ##
    # Status flags
    attr_reader :flags
  end
end
