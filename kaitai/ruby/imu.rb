# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Imu < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # Raw data from the Inertial Measurement Unit, containing accelerometer
  # and gyroscope readings. The sense of the measurements are to be aligned
  # with the indications on the device itself. Measurement units, which are
  # specific to the device hardware and settings, are communicated via the
  # MSG_IMU_AUX message. If using "time since startup" local time tags, the
  # receiving end will expect a `MSG_PPS_TIME` regardless of GNSS fix state.
  # This also requires that the MSG_PPS_TIME message be sent prior to any
  # IMU RAW messages that are based on the current (as measured at the PPS
  # edge) local time timestamps. The local time (as defined in the
  # MSG_PPS_TIME message) must wrap around to zero when reaching the extent
  # of the u64 "Local time in microseconds" parameter.
  # The time-tagging mode should not change throughout a run.
  class MsgImuRaw < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tow = @_io.read_u4le
      @tow_f = @_io.read_u1
      @acc_x = @_io.read_s2le
      @acc_y = @_io.read_s2le
      @acc_z = @_io.read_s2le
      @gyr_x = @_io.read_s2le
      @gyr_y = @_io.read_s2le
      @gyr_z = @_io.read_s2le
      self
    end

    ##
    # Milliseconds since reference epoch and time status.
    attr_reader :tow

    ##
    # Milliseconds since reference epoch, fractional part
    attr_reader :tow_f

    ##
    # Acceleration in the IMU frame X axis
    attr_reader :acc_x

    ##
    # Acceleration in the IMU frame Y axis
    attr_reader :acc_y

    ##
    # Acceleration in the IMU frame Z axis
    attr_reader :acc_z

    ##
    # Angular rate around IMU frame X axis
    attr_reader :gyr_x

    ##
    # Angular rate around IMU frame Y axis
    attr_reader :gyr_y

    ##
    # Angular rate around IMU frame Z axis
    attr_reader :gyr_z
  end

  ##
  # Auxiliary data specific to a particular IMU. The `imu_type` field will
  # always be consistent but the rest of the payload is device specific and
  # depends on the value of `imu_type`.
  class MsgImuAux < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @imu_type = @_io.read_u1
      @temp = @_io.read_s2le
      @imu_conf = @_io.read_u1
      self
    end

    ##
    # IMU type
    attr_reader :imu_type

    ##
    # Raw IMU temperature
    attr_reader :temp

    ##
    # IMU configuration
    attr_reader :imu_conf
  end
end
