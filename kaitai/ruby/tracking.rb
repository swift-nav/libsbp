# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Tracking < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # Deprecated.
  class MsgTrackingStateDetailedDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @recv_time = @_io.read_u8le
      @tot = Gnss::GpsTimeDep.new(@_io, self, @_root)
      @p = @_io.read_u4le
      @p_std = @_io.read_u2le
      @l = Gnss::CarrierPhase.new(@_io, self, @_root)
      @cn0 = @_io.read_u1
      @lock = @_io.read_u2le
      @sid = Gnss::GnssSignalDep.new(@_io, self, @_root)
      @doppler = @_io.read_s4le
      @doppler_std = @_io.read_u2le
      @uptime = @_io.read_u4le
      @clock_offset = @_io.read_s2le
      @clock_drift = @_io.read_s2le
      @corr_spacing = @_io.read_u2le
      @acceleration = @_io.read_s1
      @sync_flags = @_io.read_u1
      @tow_flags = @_io.read_u1
      @track_flags = @_io.read_u1
      @nav_flags = @_io.read_u1
      @pset_flags = @_io.read_u1
      @misc_flags = @_io.read_u1
      self
    end

    ##
    # Receiver clock time.
    attr_reader :recv_time

    ##
    # Time of transmission of signal from satellite. TOW only valid when
    # TOW status is decoded or propagated. WN only valid when week number
    # valid flag is set.
    attr_reader :tot

    ##
    # Pseudorange observation. Valid only when pseudorange valid flag is
    # set.
    attr_reader :p

    ##
    # Pseudorange observation standard deviation. Valid only when
    # pseudorange valid flag is set.
    attr_reader :p_std

    ##
    # Carrier phase observation with typical sign convention. Valid only
    # when PLL pessimistic lock is achieved.
    attr_reader :l

    ##
    # Carrier-to-Noise density
    attr_reader :cn0

    ##
    # Lock time. It is encoded according to DF402 from the RTCM 10403.2
    # Amendment 2 specification. Valid values range from 0 to 15.
    attr_reader :lock

    ##
    # GNSS signal identifier.
    attr_reader :sid

    ##
    # Carrier Doppler frequency.
    attr_reader :doppler

    ##
    # Carrier Doppler frequency standard deviation.
    attr_reader :doppler_std

    ##
    # Number of seconds of continuous tracking. Specifies how much time
    # signal is in continuous track.
    attr_reader :uptime

    ##
    # TCXO clock offset. Valid only when valid clock valid flag is set.
    attr_reader :clock_offset

    ##
    # TCXO clock drift. Valid only when valid clock valid flag is set.
    attr_reader :clock_drift

    ##
    # Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
    attr_reader :corr_spacing

    ##
    # Acceleration. Valid only when acceleration valid flag is set.
    attr_reader :acceleration

    ##
    # Synchronization status flags.
    attr_reader :sync_flags

    ##
    # TOW status flags.
    attr_reader :tow_flags

    ##
    # Tracking loop status flags.
    attr_reader :track_flags

    ##
    # Navigation data status flags.
    attr_reader :nav_flags

    ##
    # Parameters sets flags.
    attr_reader :pset_flags

    ##
    # Miscellaneous flags.
    attr_reader :misc_flags
  end

  ##
  # Deprecated.
  class TrackingChannelStateDepB < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @state = @_io.read_u1
      @sid = Gnss::GnssSignalDep.new(@_io, self, @_root)
      @cn0 = @_io.read_f4le
      self
    end

    ##
    # Status of tracking channel
    attr_reader :state

    ##
    # GNSS signal being tracked
    attr_reader :sid

    ##
    # Carrier-to-noise density
    attr_reader :cn0
  end

  ##
  # Tracking channel state for a specific satellite signal and measured
  # signal power.
  class TrackingChannelState < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @fcn = @_io.read_u1
      @cn0 = @_io.read_u1
      self
    end

    ##
    # GNSS signal being tracked
    attr_reader :sid

    ##
    # Frequency channel number (GLONASS only)
    attr_reader :fcn

    ##
    # Carrier-to-Noise density.  Zero implies invalid cn0.
    attr_reader :cn0
  end

  ##
  # The tracking message returns a variable-length array of tracking channel
  # states. It reports status and carrier-to-noise density measurements for
  # all tracked satellites.
  class MsgTrackingState < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @states = []
      i = 0
      while not @_io.eof?
        @states << TrackingChannelState.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Signal tracking channel state
    attr_reader :states
  end

  ##
  # Deprecated.
  class TrackingChannelStateDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @state = @_io.read_u1
      @prn = @_io.read_u1
      @cn0 = @_io.read_f4le
      self
    end

    ##
    # Status of tracking channel
    attr_reader :state

    ##
    # PRN-1 being tracked
    attr_reader :prn

    ##
    # Carrier-to-noise density
    attr_reader :cn0
  end

  ##
  # Deprecated.
  class MsgTrackingIqDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @channel = @_io.read_u1
      @sid = Gnss::GnssSignalDep.new(@_io, self, @_root)
      @corrs = []
      (3).times { |i|
        @corrs << @_io.read_u8le
      }
      self
    end

    ##
    # Tracking channel of origin
    attr_reader :channel

    ##
    # GNSS signal identifier
    attr_reader :sid

    ##
    # Early, Prompt and Late correlations
    attr_reader :corrs
  end

  ##
  # Structure containing in-phase and quadrature correlation components.
  class TrackingChannelCorrelationDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @i = @_io.read_s4le
      @q = @_io.read_s4le
      self
    end

    ##
    # In-phase correlation
    attr_reader :i

    ##
    # Quadrature correlation
    attr_reader :q
  end

  ##
  # Deprecated.
  class MsgTrackingStateDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @states = []
      i = 0
      while not @_io.eof?
        @states << TrackingChannelStateDepA.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Satellite tracking channel state
    attr_reader :states
  end

  ##
  # The tracking message returns a variable-length array of tracking channel
  # states. It reports status and carrier-to-noise density measurements for
  # all tracked satellites.
  class MsgMeasurementState < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @states = []
      i = 0
      while not @_io.eof?
        @states << MeasurementState.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # ME signal tracking channel state
    attr_reader :states
  end

  ##
  # Structure containing in-phase and quadrature correlation components.
  class TrackingChannelCorrelation < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @i = @_io.read_s2le
      @q = @_io.read_s2le
      self
    end

    ##
    # In-phase correlation
    attr_reader :i

    ##
    # Quadrature correlation
    attr_reader :q
  end

  ##
  # When enabled, a tracking channel can output the correlations at each
  # update interval.
  class MsgTrackingIq < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @channel = @_io.read_u1
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @corrs = []
      (3).times { |i|
        @corrs << @_io.read_u8le
      }
      self
    end

    ##
    # Tracking channel of origin
    attr_reader :channel

    ##
    # GNSS signal identifier
    attr_reader :sid

    ##
    # Early, Prompt and Late correlations
    attr_reader :corrs
  end

  ##
  # The tracking message returns a set tracking channel parameters for a
  # single tracking channel useful for debugging issues.
  class MsgTrackingStateDetailedDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @recv_time = @_io.read_u8le
      @tot = Gnss::GpsTime.new(@_io, self, @_root)
      @p = @_io.read_u4le
      @p_std = @_io.read_u2le
      @l = Gnss::CarrierPhase.new(@_io, self, @_root)
      @cn0 = @_io.read_u1
      @lock = @_io.read_u2le
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @doppler = @_io.read_s4le
      @doppler_std = @_io.read_u2le
      @uptime = @_io.read_u4le
      @clock_offset = @_io.read_s2le
      @clock_drift = @_io.read_s2le
      @corr_spacing = @_io.read_u2le
      @acceleration = @_io.read_s1
      @sync_flags = @_io.read_u1
      @tow_flags = @_io.read_u1
      @track_flags = @_io.read_u1
      @nav_flags = @_io.read_u1
      @pset_flags = @_io.read_u1
      @misc_flags = @_io.read_u1
      self
    end

    ##
    # Receiver clock time.
    attr_reader :recv_time

    ##
    # Time of transmission of signal from satellite. TOW only valid when
    # TOW status is decoded or propagated. WN only valid when week number
    # valid flag is set.
    attr_reader :tot

    ##
    # Pseudorange observation. Valid only when pseudorange valid flag is
    # set.
    attr_reader :p

    ##
    # Pseudorange observation standard deviation. Valid only when
    # pseudorange valid flag is set.
    attr_reader :p_std

    ##
    # Carrier phase observation with typical sign convention. Valid only
    # when PLL pessimistic lock is achieved.
    attr_reader :l

    ##
    # Carrier-to-Noise density
    attr_reader :cn0

    ##
    # Lock time. It is encoded according to DF402 from the RTCM 10403.2
    # Amendment 2 specification. Valid values range from 0 to 15.
    attr_reader :lock

    ##
    # GNSS signal identifier.
    attr_reader :sid

    ##
    # Carrier Doppler frequency.
    attr_reader :doppler

    ##
    # Carrier Doppler frequency standard deviation.
    attr_reader :doppler_std

    ##
    # Number of seconds of continuous tracking. Specifies how much time
    # signal is in continuous track.
    attr_reader :uptime

    ##
    # TCXO clock offset. Valid only when valid clock valid flag is set.
    attr_reader :clock_offset

    ##
    # TCXO clock drift. Valid only when valid clock valid flag is set.
    attr_reader :clock_drift

    ##
    # Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
    attr_reader :corr_spacing

    ##
    # Acceleration. Valid only when acceleration valid flag is set.
    attr_reader :acceleration

    ##
    # Synchronization status flags.
    attr_reader :sync_flags

    ##
    # TOW status flags.
    attr_reader :tow_flags

    ##
    # Tracking loop status flags.
    attr_reader :track_flags

    ##
    # Navigation data status flags.
    attr_reader :nav_flags

    ##
    # Parameters sets flags.
    attr_reader :pset_flags

    ##
    # Miscellaneous flags.
    attr_reader :misc_flags
  end

  ##
  # Deprecated.
  class MsgTrackingStateDepB < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @states = []
      i = 0
      while not @_io.eof?
        @states << TrackingChannelStateDepB.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Signal tracking channel state
    attr_reader :states
  end

  ##
  # Measurement Engine tracking channel state for a specific satellite
  # signal and measured signal power. The mesid field for Glonass can either
  # carry the FCN as 100 + FCN where FCN is in [-7, +6] or the Slot ID (from
  # 1 to 28).
  class MeasurementState < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @mesid = Gnss::GnssSignal.new(@_io, self, @_root)
      @cn0 = @_io.read_u1
      self
    end

    ##
    # Measurement Engine GNSS signal being tracked (carries either Glonass
    # FCN or SLOT)
    attr_reader :mesid

    ##
    # Carrier-to-Noise density.  Zero implies invalid cn0.
    attr_reader :cn0
  end

  ##
  # Deprecated.
  class MsgTrackingIqDepB < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @channel = @_io.read_u1
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @corrs = []
      (3).times { |i|
        @corrs << @_io.read_u8le
      }
      self
    end

    ##
    # Tracking channel of origin
    attr_reader :channel

    ##
    # GNSS signal identifier
    attr_reader :sid

    ##
    # Early, Prompt and Late correlations
    attr_reader :corrs
  end
end
