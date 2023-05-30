# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Acquisition < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # Deprecated.
  class MsgAcqResultDepC < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @cn0 = @_io.read_f4le
      @cp = @_io.read_f4le
      @cf = @_io.read_f4le
      @sid = Gnss::GnssSignalDep.new(@_io, self, @_root)
      self
    end

    ##
    # CN/0 of best point
    attr_reader :cn0

    ##
    # Code phase of best point
    attr_reader :cp

    ##
    # Carrier frequency of best point
    attr_reader :cf

    ##
    # GNSS signal for which acquisition was attempted
    attr_reader :sid
  end

  ##
  # Deprecated.
  class MsgAcqResultDepB < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @snr = @_io.read_f4le
      @cp = @_io.read_f4le
      @cf = @_io.read_f4le
      @sid = Gnss::GnssSignalDep.new(@_io, self, @_root)
      self
    end

    ##
    # SNR of best point. Currently in arbitrary SNR points, but will be in
    # units of dB Hz in a later revision of this message.
    attr_reader :snr

    ##
    # Code phase of best point
    attr_reader :cp

    ##
    # Carrier frequency of best point
    attr_reader :cf

    ##
    # GNSS signal for which acquisition was attempted
    attr_reader :sid
  end

  ##
  # Profile for a specific SV for debugging purposes. The message describes
  # SV profile during acquisition time. The message is used to debug and
  # measure the performance.
  class AcqSvProfile < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @job_type = @_io.read_u1
      @status = @_io.read_u1
      @cn0 = @_io.read_u2le
      @int_time = @_io.read_u1
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @bin_width = @_io.read_u2le
      @timestamp = @_io.read_u4le
      @time_spent = @_io.read_u4le
      @cf_min = @_io.read_s4le
      @cf_max = @_io.read_s4le
      @cf = @_io.read_s4le
      @cp = @_io.read_u4le
      self
    end

    ##
    # SV search job type (deep, fallback, etc)
    attr_reader :job_type

    ##
    # Acquisition status 1 is Success, 0 is Failure
    attr_reader :status

    ##
    # CN0 value. Only valid if status is '1'
    attr_reader :cn0

    ##
    # Acquisition integration time
    attr_reader :int_time

    ##
    # GNSS signal for which acquisition was attempted
    attr_reader :sid

    ##
    # Acq frequency bin width
    attr_reader :bin_width

    ##
    # Timestamp of the job complete event
    attr_reader :timestamp

    ##
    # Time spent to search for sid.code
    attr_reader :time_spent

    ##
    # Doppler range lowest frequency
    attr_reader :cf_min

    ##
    # Doppler range highest frequency
    attr_reader :cf_max

    ##
    # Doppler value of detected peak. Only valid if status is '1'
    attr_reader :cf

    ##
    # Codephase of detected peak. Only valid if status is '1'
    attr_reader :cp
  end

  ##
  # The message describes all SV profiles during acquisition time. The
  # message is used to debug and measure the performance.
  class MsgAcqSvProfile < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @acq_sv_profile = []
      i = 0
      while not @_io.eof?
        @acq_sv_profile << AcqSvProfile.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # SV profiles during acquisition time
    attr_reader :acq_sv_profile
  end

  ##
  # Deprecated.
  class AcqSvProfileDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @job_type = @_io.read_u1
      @status = @_io.read_u1
      @cn0 = @_io.read_u2le
      @int_time = @_io.read_u1
      @sid = Gnss::GnssSignalDep.new(@_io, self, @_root)
      @bin_width = @_io.read_u2le
      @timestamp = @_io.read_u4le
      @time_spent = @_io.read_u4le
      @cf_min = @_io.read_s4le
      @cf_max = @_io.read_s4le
      @cf = @_io.read_s4le
      @cp = @_io.read_u4le
      self
    end

    ##
    # SV search job type (deep, fallback, etc)
    attr_reader :job_type

    ##
    # Acquisition status 1 is Success, 0 is Failure
    attr_reader :status

    ##
    # CN0 value. Only valid if status is '1'
    attr_reader :cn0

    ##
    # Acquisition integration time
    attr_reader :int_time

    ##
    # GNSS signal for which acquisition was attempted
    attr_reader :sid

    ##
    # Acq frequency bin width
    attr_reader :bin_width

    ##
    # Timestamp of the job complete event
    attr_reader :timestamp

    ##
    # Time spent to search for sid.code
    attr_reader :time_spent

    ##
    # Doppler range lowest frequency
    attr_reader :cf_min

    ##
    # Doppler range highest frequency
    attr_reader :cf_max

    ##
    # Doppler value of detected peak. Only valid if status is '1'
    attr_reader :cf

    ##
    # Codephase of detected peak. Only valid if status is '1'
    attr_reader :cp
  end

  ##
  # This message describes the results from an attempted GPS signal
  # acquisition search for a satellite PRN over a code phase/carrier
  # frequency range. It contains the parameters of the point in the
  # acquisition search space with the best carrier-to-noise (CN/0) ratio.
  class MsgAcqResult < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @cn0 = @_io.read_f4le
      @cp = @_io.read_f4le
      @cf = @_io.read_f4le
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      self
    end

    ##
    # CN/0 of best point
    attr_reader :cn0

    ##
    # Code phase of best point
    attr_reader :cp

    ##
    # Carrier frequency of best point
    attr_reader :cf

    ##
    # GNSS signal for which acquisition was attempted
    attr_reader :sid
  end

  ##
  # Deprecated.
  class MsgAcqResultDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @snr = @_io.read_f4le
      @cp = @_io.read_f4le
      @cf = @_io.read_f4le
      @prn = @_io.read_u1
      self
    end

    ##
    # SNR of best point. Currently dimensionless, but will have units of
    # dB Hz in the revision of this message.
    attr_reader :snr

    ##
    # Code phase of best point
    attr_reader :cp

    ##
    # Carrier frequency of best point
    attr_reader :cf

    ##
    # PRN-1 identifier of the satellite signal for which acquisition was
    # attempted
    attr_reader :prn
  end

  ##
  # Deprecated.
  class MsgAcqSvProfileDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @acq_sv_profile = []
      i = 0
      while not @_io.eof?
        @acq_sv_profile << AcqSvProfileDep.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # SV profiles during acquisition time
    attr_reader :acq_sv_profile
  end
end
