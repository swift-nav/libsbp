# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

require 'kaitai/struct/struct'

unless Gem::Version.new(Kaitai::Struct::VERSION) >= Gem::Version.new('0.9')
  raise "Incompatible Kaitai Struct Ruby API: 0.9 or later is required, but you have #{Kaitai::Struct::VERSION}"
end

class Observation < Kaitai::Struct::Struct
  def initialize(_io, _parent = nil, _root = self)
    super(_io, _parent, _root)
    _read
  end

  def _read
    self
  end

  ##
  # Azimuth and elevation angles of all the visible satellites that the
  # device does have ephemeris or almanac for.
  class MsgSvAzEl < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @azel = []
      i = 0
      while not @_io.eof?
        @azel << SvAzEl.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Azimuth and elevation per satellite
    attr_reader :azel
  end
  class GnssCapb < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @gps_active = @_io.read_u8le
      @gps_l2c = @_io.read_u8le
      @gps_l5 = @_io.read_u8le
      @glo_active = @_io.read_u4le
      @glo_l2of = @_io.read_u4le
      @glo_l3 = @_io.read_u4le
      @sbas_active = @_io.read_u8le
      @sbas_l5 = @_io.read_u8le
      @bds_active = @_io.read_u8le
      @bds_d2nav = @_io.read_u8le
      @bds_b2 = @_io.read_u8le
      @bds_b2a = @_io.read_u8le
      @qzss_active = @_io.read_u4le
      @gal_active = @_io.read_u8le
      @gal_e5 = @_io.read_u8le
      self
    end

    ##
    # GPS SV active mask
    attr_reader :gps_active

    ##
    # GPS L2C active mask
    attr_reader :gps_l2c

    ##
    # GPS L5 active mask
    attr_reader :gps_l5

    ##
    # GLO active mask
    attr_reader :glo_active

    ##
    # GLO L2OF active mask
    attr_reader :glo_l2of

    ##
    # GLO L3 active mask
    attr_reader :glo_l3

    ##
    # SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
    # https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
    attr_reader :sbas_active

    ##
    # SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
    # https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
    attr_reader :sbas_l5

    ##
    # BDS active mask
    attr_reader :bds_active

    ##
    # BDS D2NAV active mask
    attr_reader :bds_d2nav

    ##
    # BDS B2 active mask
    attr_reader :bds_b2

    ##
    # BDS B2A active mask
    attr_reader :bds_b2a

    ##
    # QZSS active mask
    attr_reader :qzss_active

    ##
    # GAL active mask
    attr_reader :gal_active

    ##
    # GAL E5 active mask
    attr_reader :gal_e5
  end

  ##
  # Deprecated.
  class MsgGroupDelayDepB < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @t_op = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @sid = Gnss::GnssSignalDep.new(@_io, self, @_root)
      @valid = @_io.read_u1
      @tgd = @_io.read_s2le
      @isc_l1ca = @_io.read_s2le
      @isc_l2c = @_io.read_s2le
      self
    end

    ##
    # Data Predict Time of Week
    attr_reader :t_op

    ##
    # GNSS signal identifier
    attr_reader :sid

    ##
    # bit-field indicating validity of the values, LSB indicating tgd
    # validity etc. 1 = value is valid, 0 = value is not valid.
    attr_reader :valid
    attr_reader :tgd
    attr_reader :isc_l1ca
    attr_reader :isc_l2c
  end

  ##
  # Header of a GPS observation message.
  class ObservationHeaderDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @t = Gnss::GpsTimeDep.new(@_io, self, @_root)
      @n_obs = @_io.read_u1
      self
    end

    ##
    # GPS time of this observation
    attr_reader :t

    ##
    # Total number of observations. First nibble is the size of the
    # sequence (n), second nibble is the zero-indexed counter (ith packet
    # of n)
    attr_reader :n_obs
  end
  class AlmanacCommonContentDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sid = Gnss::GnssSignalDep.new(@_io, self, @_root)
      @toa = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @ura = @_io.read_f8le
      @fit_interval = @_io.read_u4le
      @valid = @_io.read_u1
      @health_bits = @_io.read_u1
      self
    end

    ##
    # GNSS signal identifier
    attr_reader :sid

    ##
    # Reference time of almanac
    attr_reader :toa

    ##
    # User Range Accuracy
    attr_reader :ura

    ##
    # Curve fit interval
    attr_reader :fit_interval

    ##
    # Status of almanac, 1 = valid, 0 = invalid
    attr_reader :valid

    ##
    # Satellite health status for GPS:
    #   - bits 5-7: NAV data health status. See IS-GPS-200H
    #     Table 20-VII: NAV Data Health Indications.
    #   - bits 0-4: Signal health status. See IS-GPS-200H
    #     Table 20-VIII. Codes for Health of SV Signal
    #     Components.
    # Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for
    # details):
    #   - bit 0: C(n), "unhealthy" flag that is transmitted within
    #     non-immediate data and indicates overall constellation status
    #     at the moment of almanac uploading.
    #     '0' indicates malfunction of n-satellite.
    #     '1' indicates that n-satellite is operational.
    #   - bit 1: Bn(ln), '0' indicates the satellite is operational
    #     and suitable for navigation.
    attr_reader :health_bits
  end
  class EphemerisCommonContentDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sid = Gnss::GnssSignalDep.new(@_io, self, @_root)
      @toe = Gnss::GpsTimeDep.new(@_io, self, @_root)
      @ura = @_io.read_f8le
      @fit_interval = @_io.read_u4le
      @valid = @_io.read_u1
      @health_bits = @_io.read_u1
      self
    end

    ##
    # GNSS signal identifier
    attr_reader :sid

    ##
    # Time of Ephemerides
    attr_reader :toe

    ##
    # User Range Accuracy
    attr_reader :ura

    ##
    # Curve fit interval
    attr_reader :fit_interval

    ##
    # Status of ephemeris, 1 = valid, 0 = invalid
    attr_reader :valid

    ##
    # Satellite health status.
    # GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
    # SBAS: 0 = valid, non-zero = invalid
    # GLO: 0 = valid, non-zero = invalid
    attr_reader :health_bits
  end
  class EphemerisCommonContent < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @toe = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @ura = @_io.read_f4le
      @fit_interval = @_io.read_u4le
      @valid = @_io.read_u1
      @health_bits = @_io.read_u1
      self
    end

    ##
    # GNSS signal identifier (16 bit)
    attr_reader :sid

    ##
    # Time of Ephemerides
    attr_reader :toe

    ##
    # User Range Accuracy
    attr_reader :ura

    ##
    # Curve fit interval
    attr_reader :fit_interval

    ##
    # Status of ephemeris, 1 = valid, 0 = invalid
    attr_reader :valid

    ##
    # Satellite health status.
    # GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
    # SBAS: 0 = valid, non-zero = invalid
    # GLO: 0 = valid, non-zero = invalid
    attr_reader :health_bits
  end

  ##
  # Pseudorange and carrier phase observation for a satellite being tracked.
  # The observations are be interoperable with 3rd party receivers and
  # conform with typical RTCMv3 GNSS observations.
  class PackedObsContentDepC < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @p = @_io.read_u4le
      @l = Gnss::CarrierPhase.new(@_io, self, @_root)
      @cn0 = @_io.read_u1
      @lock = @_io.read_u2le
      @sid = Gnss::GnssSignalDep.new(@_io, self, @_root)
      self
    end

    ##
    # Pseudorange observation
    attr_reader :p

    ##
    # Carrier phase observation with typical sign convention.
    attr_reader :l

    ##
    # Carrier-to-Noise density
    attr_reader :cn0

    ##
    # Lock indicator. This value changes whenever a satellite signal has
    # lost and regained lock, indicating that the carrier phase ambiguity
    # may have changed.
    attr_reader :lock

    ##
    # GNSS signal identifier
    attr_reader :sid
  end

  ##
  # This observation message has been deprecated in favor of ephemeris
  # message using floats for size reduction.
  class MsgEphemerisGloDepD < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = EphemerisCommonContentDepB.new(@_io, self, @_root)
      @gamma = @_io.read_f8le
      @tau = @_io.read_f8le
      @d_tau = @_io.read_f8le
      @pos = []
      (3).times { |i|
        @pos << @_io.read_f8le
      }
      @vel = []
      (3).times { |i|
        @vel << @_io.read_f8le
      }
      @acc = []
      (3).times { |i|
        @acc << @_io.read_f8le
      }
      @fcn = @_io.read_u1
      @iod = @_io.read_u1
      self
    end

    ##
    # Values common for all ephemeris types
    attr_reader :common

    ##
    # Relative deviation of predicted carrier frequency from nominal
    attr_reader :gamma

    ##
    # Correction to the SV time
    attr_reader :tau

    ##
    # Equipment delay between L1 and L2
    attr_reader :d_tau

    ##
    # Position of the SV at tb in PZ-90.02 coordinates system
    attr_reader :pos

    ##
    # Velocity vector of the SV at tb in PZ-90.02 coordinates system
    attr_reader :vel

    ##
    # Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    attr_reader :acc

    ##
    # Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
    attr_reader :fcn

    ##
    # Issue of data. Equal to the 7 bits of the immediate data word t_b
    attr_reader :iod
  end

  ##
  # Deprecated.
  class MsgObsDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = ObservationHeaderDep.new(@_io, self, @_root)
      @obs = []
      i = 0
      while not @_io.eof?
        @obs << PackedObsContentDepA.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Header of a GPS observation message
    attr_reader :header

    ##
    # Pseudorange and carrier phase observation for a satellite being
    # tracked.
    attr_reader :obs
  end

  ##
  # Deprecated.
  class MsgEphemerisDepB < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tgd = @_io.read_f8le
      @c_rs = @_io.read_f8le
      @c_rc = @_io.read_f8le
      @c_uc = @_io.read_f8le
      @c_us = @_io.read_f8le
      @c_ic = @_io.read_f8le
      @c_is = @_io.read_f8le
      @dn = @_io.read_f8le
      @m0 = @_io.read_f8le
      @ecc = @_io.read_f8le
      @sqrta = @_io.read_f8le
      @omega0 = @_io.read_f8le
      @omegadot = @_io.read_f8le
      @w = @_io.read_f8le
      @inc = @_io.read_f8le
      @inc_dot = @_io.read_f8le
      @af0 = @_io.read_f8le
      @af1 = @_io.read_f8le
      @af2 = @_io.read_f8le
      @toe_tow = @_io.read_f8le
      @toe_wn = @_io.read_u2le
      @toc_tow = @_io.read_f8le
      @toc_wn = @_io.read_u2le
      @valid = @_io.read_u1
      @healthy = @_io.read_u1
      @prn = @_io.read_u1
      @iode = @_io.read_u1
      self
    end

    ##
    # Group delay differential between L1 and L2
    attr_reader :tgd

    ##
    # Amplitude of the sine harmonic correction term to the orbit radius
    attr_reader :c_rs

    ##
    # Amplitude of the cosine harmonic correction term to the orbit radius
    attr_reader :c_rc

    ##
    # Amplitude of the cosine harmonic correction term to the argument of
    # latitude
    attr_reader :c_uc

    ##
    # Amplitude of the sine harmonic correction term to the argument of
    # latitude
    attr_reader :c_us

    ##
    # Amplitude of the cosine harmonic correction term to the angle of
    # inclination
    attr_reader :c_ic

    ##
    # Amplitude of the sine harmonic correction term to the angle of
    # inclination
    attr_reader :c_is

    ##
    # Mean motion difference
    attr_reader :dn

    ##
    # Mean anomaly at reference time
    attr_reader :m0

    ##
    # Eccentricity of satellite orbit
    attr_reader :ecc

    ##
    # Square root of the semi-major axis of orbit
    attr_reader :sqrta

    ##
    # Longitude of ascending node of orbit plane at weekly epoch
    attr_reader :omega0

    ##
    # Rate of right ascension
    attr_reader :omegadot

    ##
    # Argument of perigee
    attr_reader :w

    ##
    # Inclination
    attr_reader :inc

    ##
    # Inclination first derivative
    attr_reader :inc_dot

    ##
    # Polynomial clock correction coefficient (clock bias)
    attr_reader :af0

    ##
    # Polynomial clock correction coefficient (clock drift)
    attr_reader :af1

    ##
    # Polynomial clock correction coefficient (rate of clock drift)
    attr_reader :af2

    ##
    # Time of week
    attr_reader :toe_tow

    ##
    # Week number
    attr_reader :toe_wn

    ##
    # Clock reference time of week
    attr_reader :toc_tow

    ##
    # Clock reference week number
    attr_reader :toc_wn

    ##
    # Is valid?
    attr_reader :valid

    ##
    # Satellite is healthy?
    attr_reader :healthy

    ##
    # PRN being tracked
    attr_reader :prn

    ##
    # Issue of ephemeris data
    attr_reader :iode
  end

  ##
  # The GPS observations message reports all the raw pseudorange and carrier
  # phase observations for the satellites being tracked by the device.
  # Carrier phase observation here is represented as a 40-bit fixed point
  # number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
  # fractional cycles). The observations are be interoperable with 3rd party
  # receivers and conform with typical RTCMv3 GNSS observations.
  class MsgObs < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = ObservationHeader.new(@_io, self, @_root)
      @obs = []
      i = 0
      while not @_io.eof?
        @obs << PackedObsContent.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Header of a GPS observation message
    attr_reader :header

    ##
    # Pseudorange and carrier phase observation for a satellite being
    # tracked.
    attr_reader :obs
  end

  ##
  # Doppler measurement in Hz represented as a 24-bit fixed point number
  # with Q16.8 layout, i.e. 16-bits of whole doppler and 8-bits of
  # fractional doppler. This doppler is defined as positive for approaching
  # satellites.
  class Doppler < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @i = @_io.read_s2le
      @f = @_io.read_u1
      self
    end

    ##
    # Doppler whole Hz
    attr_reader :i

    ##
    # Doppler fractional part
    attr_reader :f
  end

  ##
  # Deprecated.
  class MsgAlmanacGloDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = AlmanacCommonContentDep.new(@_io, self, @_root)
      @lambda_na = @_io.read_f8le
      @t_lambda_na = @_io.read_f8le
      @i = @_io.read_f8le
      @t = @_io.read_f8le
      @t_dot = @_io.read_f8le
      @epsilon = @_io.read_f8le
      @omega = @_io.read_f8le
      self
    end

    ##
    # Values common for all almanac types
    attr_reader :common

    ##
    # Longitude of the first ascending node of the orbit in PZ-90.02
    # coordinate system
    attr_reader :lambda_na

    ##
    # Time of the first ascending node passage
    attr_reader :t_lambda_na

    ##
    # Value of inclination at instant of t_lambda
    attr_reader :i

    ##
    # Value of Draconian period at instant of t_lambda
    attr_reader :t

    ##
    # Rate of change of the Draconian period
    attr_reader :t_dot

    ##
    # Eccentricity at instant of t_lambda
    attr_reader :epsilon

    ##
    # Argument of perigee at instant of t_lambda
    attr_reader :omega
  end

  ##
  # Deprecated.
  class MsgAlmanacGpsDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = AlmanacCommonContentDep.new(@_io, self, @_root)
      @m0 = @_io.read_f8le
      @ecc = @_io.read_f8le
      @sqrta = @_io.read_f8le
      @omega0 = @_io.read_f8le
      @omegadot = @_io.read_f8le
      @w = @_io.read_f8le
      @inc = @_io.read_f8le
      @af0 = @_io.read_f8le
      @af1 = @_io.read_f8le
      self
    end

    ##
    # Values common for all almanac types
    attr_reader :common

    ##
    # Mean anomaly at reference time
    attr_reader :m0

    ##
    # Eccentricity of satellite orbit
    attr_reader :ecc

    ##
    # Square root of the semi-major axis of orbit
    attr_reader :sqrta

    ##
    # Longitude of ascending node of orbit plane at weekly epoch
    attr_reader :omega0

    ##
    # Rate of right ascension
    attr_reader :omegadot

    ##
    # Argument of perigee
    attr_reader :w

    ##
    # Inclination
    attr_reader :inc

    ##
    # Polynomial clock correction coefficient (clock bias)
    attr_reader :af0

    ##
    # Polynomial clock correction coefficient (clock drift)
    attr_reader :af1
  end

  ##
  # Satellite azimuth and elevation.
  class SvAzEl < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @az = @_io.read_u1
      @el = @_io.read_s1
      self
    end

    ##
    # GNSS signal identifier
    attr_reader :sid

    ##
    # Azimuth angle (range 0..179)
    attr_reader :az

    ##
    # Elevation angle (range -90..90)
    attr_reader :el
  end

  ##
  # The GLONASS L1/L2 Code-Phase biases allows to perform GPS+GLONASS
  # integer ambiguity resolution for baselines with mixed receiver types
  # (e.g. receiver of different manufacturers).
  class MsgGloBiases < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @mask = @_io.read_u1
      @l1ca_bias = @_io.read_s2le
      @l1p_bias = @_io.read_s2le
      @l2ca_bias = @_io.read_s2le
      @l2p_bias = @_io.read_s2le
      self
    end

    ##
    # GLONASS FDMA signals mask
    attr_reader :mask

    ##
    # GLONASS L1 C/A Code-Phase Bias
    attr_reader :l1ca_bias

    ##
    # GLONASS L1 P Code-Phase Bias
    attr_reader :l1p_bias

    ##
    # GLONASS L2 C/A Code-Phase Bias
    attr_reader :l2ca_bias

    ##
    # GLONASS L2 P Code-Phase Bias
    attr_reader :l2p_bias
  end

  ##
  # Deprecated.
  class MsgEphemerisSbasDepB < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = EphemerisCommonContentDepB.new(@_io, self, @_root)
      @pos = []
      (3).times { |i|
        @pos << @_io.read_f8le
      }
      @vel = []
      (3).times { |i|
        @vel << @_io.read_f8le
      }
      @acc = []
      (3).times { |i|
        @acc << @_io.read_f8le
      }
      @a_gf0 = @_io.read_f8le
      @a_gf1 = @_io.read_f8le
      self
    end

    ##
    # Values common for all ephemeris types
    attr_reader :common

    ##
    # Position of the GEO at time toe
    attr_reader :pos

    ##
    # Velocity of the GEO at time toe
    attr_reader :vel

    ##
    # Acceleration of the GEO at time toe
    attr_reader :acc

    ##
    # Time offset of the GEO clock w.r.t. SBAS Network Time
    attr_reader :a_gf0

    ##
    # Drift of the GEO clock w.r.t. SBAS Network Time
    attr_reader :a_gf1
  end

  ##
  # Deprecated.
  class MsgEphemerisGpsDepE < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = EphemerisCommonContentDepA.new(@_io, self, @_root)
      @tgd = @_io.read_f8le
      @c_rs = @_io.read_f8le
      @c_rc = @_io.read_f8le
      @c_uc = @_io.read_f8le
      @c_us = @_io.read_f8le
      @c_ic = @_io.read_f8le
      @c_is = @_io.read_f8le
      @dn = @_io.read_f8le
      @m0 = @_io.read_f8le
      @ecc = @_io.read_f8le
      @sqrta = @_io.read_f8le
      @omega0 = @_io.read_f8le
      @omegadot = @_io.read_f8le
      @w = @_io.read_f8le
      @inc = @_io.read_f8le
      @inc_dot = @_io.read_f8le
      @af0 = @_io.read_f8le
      @af1 = @_io.read_f8le
      @af2 = @_io.read_f8le
      @toc = Gnss::GpsTimeDep.new(@_io, self, @_root)
      @iode = @_io.read_u1
      @iodc = @_io.read_u2le
      self
    end

    ##
    # Values common for all ephemeris types
    attr_reader :common

    ##
    # Group delay differential between L1 and L2
    attr_reader :tgd

    ##
    # Amplitude of the sine harmonic correction term to the orbit radius
    attr_reader :c_rs

    ##
    # Amplitude of the cosine harmonic correction term to the orbit radius
    attr_reader :c_rc

    ##
    # Amplitude of the cosine harmonic correction term to the argument of
    # latitude
    attr_reader :c_uc

    ##
    # Amplitude of the sine harmonic correction term to the argument of
    # latitude
    attr_reader :c_us

    ##
    # Amplitude of the cosine harmonic correction term to the angle of
    # inclination
    attr_reader :c_ic

    ##
    # Amplitude of the sine harmonic correction term to the angle of
    # inclination
    attr_reader :c_is

    ##
    # Mean motion difference
    attr_reader :dn

    ##
    # Mean anomaly at reference time
    attr_reader :m0

    ##
    # Eccentricity of satellite orbit
    attr_reader :ecc

    ##
    # Square root of the semi-major axis of orbit
    attr_reader :sqrta

    ##
    # Longitude of ascending node of orbit plane at weekly epoch
    attr_reader :omega0

    ##
    # Rate of right ascension
    attr_reader :omegadot

    ##
    # Argument of perigee
    attr_reader :w

    ##
    # Inclination
    attr_reader :inc

    ##
    # Inclination first derivative
    attr_reader :inc_dot

    ##
    # Polynomial clock correction coefficient (clock bias)
    attr_reader :af0

    ##
    # Polynomial clock correction coefficient (clock drift)
    attr_reader :af1

    ##
    # Polynomial clock correction coefficient (rate of clock drift)
    attr_reader :af2

    ##
    # Clock reference
    attr_reader :toc

    ##
    # Issue of ephemeris data
    attr_reader :iode

    ##
    # Issue of clock data
    attr_reader :iodc
  end

  ##
  # Bit masks of signal capabilities for each GNSS satellite PRN.
  # Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
  class MsgGnssCapb < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @t_nmct = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @gc = GnssCapb.new(@_io, self, @_root)
      self
    end

    ##
    # Navigation Message Correction Table Validity Time
    attr_reader :t_nmct

    ##
    # GNSS capabilities masks
    attr_reader :gc
  end

  ##
  # The almanac message returns a set of satellite orbit parameters. Almanac
  # data is not very precise and is considered valid for up to several
  # months. Please see the Navstar GPS Space Segment/Navigation user
  # interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more
  # details.
  class MsgAlmanacGps < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = AlmanacCommonContent.new(@_io, self, @_root)
      @m0 = @_io.read_f8le
      @ecc = @_io.read_f8le
      @sqrta = @_io.read_f8le
      @omega0 = @_io.read_f8le
      @omegadot = @_io.read_f8le
      @w = @_io.read_f8le
      @inc = @_io.read_f8le
      @af0 = @_io.read_f8le
      @af1 = @_io.read_f8le
      self
    end

    ##
    # Values common for all almanac types
    attr_reader :common

    ##
    # Mean anomaly at reference time
    attr_reader :m0

    ##
    # Eccentricity of satellite orbit
    attr_reader :ecc

    ##
    # Square root of the semi-major axis of orbit
    attr_reader :sqrta

    ##
    # Longitude of ascending node of orbit plane at weekly epoch
    attr_reader :omega0

    ##
    # Rate of right ascension
    attr_reader :omegadot

    ##
    # Argument of perigee
    attr_reader :w

    ##
    # Inclination
    attr_reader :inc

    ##
    # Polynomial clock correction coefficient (clock bias)
    attr_reader :af0

    ##
    # Polynomial clock correction coefficient (clock drift)
    attr_reader :af1
  end

  ##
  # The ephemeris message returns a set of satellite orbit parameters that
  # is used to calculate QZSS satellite position, velocity, and clock
  # offset.
  class MsgEphemerisQzss < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = EphemerisCommonContent.new(@_io, self, @_root)
      @tgd = @_io.read_f4le
      @c_rs = @_io.read_f4le
      @c_rc = @_io.read_f4le
      @c_uc = @_io.read_f4le
      @c_us = @_io.read_f4le
      @c_ic = @_io.read_f4le
      @c_is = @_io.read_f4le
      @dn = @_io.read_f8le
      @m0 = @_io.read_f8le
      @ecc = @_io.read_f8le
      @sqrta = @_io.read_f8le
      @omega0 = @_io.read_f8le
      @omegadot = @_io.read_f8le
      @w = @_io.read_f8le
      @inc = @_io.read_f8le
      @inc_dot = @_io.read_f8le
      @af0 = @_io.read_f4le
      @af1 = @_io.read_f4le
      @af2 = @_io.read_f4le
      @toc = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @iode = @_io.read_u1
      @iodc = @_io.read_u2le
      self
    end

    ##
    # Values common for all ephemeris types
    attr_reader :common

    ##
    # Group delay differential between L1 and L2
    attr_reader :tgd

    ##
    # Amplitude of the sine harmonic correction term to the orbit radius
    attr_reader :c_rs

    ##
    # Amplitude of the cosine harmonic correction term to the orbit radius
    attr_reader :c_rc

    ##
    # Amplitude of the cosine harmonic correction term to the argument of
    # latitude
    attr_reader :c_uc

    ##
    # Amplitude of the sine harmonic correction term to the argument of
    # latitude
    attr_reader :c_us

    ##
    # Amplitude of the cosine harmonic correction term to the angle of
    # inclination
    attr_reader :c_ic

    ##
    # Amplitude of the sine harmonic correction term to the angle of
    # inclination
    attr_reader :c_is

    ##
    # Mean motion difference
    attr_reader :dn

    ##
    # Mean anomaly at reference time
    attr_reader :m0

    ##
    # Eccentricity of satellite orbit
    attr_reader :ecc

    ##
    # Square root of the semi-major axis of orbit
    attr_reader :sqrta

    ##
    # Longitude of ascending node of orbit plane at weekly epoch
    attr_reader :omega0

    ##
    # Rate of right ascension
    attr_reader :omegadot

    ##
    # Argument of perigee
    attr_reader :w

    ##
    # Inclination
    attr_reader :inc

    ##
    # Inclination first derivative
    attr_reader :inc_dot

    ##
    # Polynomial clock correction coefficient (clock bias)
    attr_reader :af0

    ##
    # Polynomial clock correction coefficient (clock drift)
    attr_reader :af1

    ##
    # Polynomial clock correction coefficient (rate of clock drift)
    attr_reader :af2

    ##
    # Clock reference
    attr_reader :toc

    ##
    # Issue of ephemeris data
    attr_reader :iode

    ##
    # Issue of clock data
    attr_reader :iodc
  end

  ##
  # Deprecated.
  class MsgGroupDelayDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @t_op = Gnss::GpsTimeDep.new(@_io, self, @_root)
      @prn = @_io.read_u1
      @valid = @_io.read_u1
      @tgd = @_io.read_s2le
      @isc_l1ca = @_io.read_s2le
      @isc_l2c = @_io.read_s2le
      self
    end

    ##
    # Data Predict Time of Week
    attr_reader :t_op

    ##
    # Satellite number
    attr_reader :prn

    ##
    # bit-field indicating validity of the values, LSB indicating tgd
    # validity etc. 1 = value is valid, 0 = value is not valid.
    attr_reader :valid
    attr_reader :tgd
    attr_reader :isc_l1ca
    attr_reader :isc_l2c
  end

  ##
  # Deprecated.
  class MsgEphemerisDepC < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tgd = @_io.read_f8le
      @c_rs = @_io.read_f8le
      @c_rc = @_io.read_f8le
      @c_uc = @_io.read_f8le
      @c_us = @_io.read_f8le
      @c_ic = @_io.read_f8le
      @c_is = @_io.read_f8le
      @dn = @_io.read_f8le
      @m0 = @_io.read_f8le
      @ecc = @_io.read_f8le
      @sqrta = @_io.read_f8le
      @omega0 = @_io.read_f8le
      @omegadot = @_io.read_f8le
      @w = @_io.read_f8le
      @inc = @_io.read_f8le
      @inc_dot = @_io.read_f8le
      @af0 = @_io.read_f8le
      @af1 = @_io.read_f8le
      @af2 = @_io.read_f8le
      @toe_tow = @_io.read_f8le
      @toe_wn = @_io.read_u2le
      @toc_tow = @_io.read_f8le
      @toc_wn = @_io.read_u2le
      @valid = @_io.read_u1
      @healthy = @_io.read_u1
      @sid = Gnss::GnssSignalDep.new(@_io, self, @_root)
      @iode = @_io.read_u1
      @iodc = @_io.read_u2le
      @reserved = @_io.read_u4le
      self
    end

    ##
    # Group delay differential between L1 and L2
    attr_reader :tgd

    ##
    # Amplitude of the sine harmonic correction term to the orbit radius
    attr_reader :c_rs

    ##
    # Amplitude of the cosine harmonic correction term to the orbit radius
    attr_reader :c_rc

    ##
    # Amplitude of the cosine harmonic correction term to the argument of
    # latitude
    attr_reader :c_uc

    ##
    # Amplitude of the sine harmonic correction term to the argument of
    # latitude
    attr_reader :c_us

    ##
    # Amplitude of the cosine harmonic correction term to the angle of
    # inclination
    attr_reader :c_ic

    ##
    # Amplitude of the sine harmonic correction term to the angle of
    # inclination
    attr_reader :c_is

    ##
    # Mean motion difference
    attr_reader :dn

    ##
    # Mean anomaly at reference time
    attr_reader :m0

    ##
    # Eccentricity of satellite orbit
    attr_reader :ecc

    ##
    # Square root of the semi-major axis of orbit
    attr_reader :sqrta

    ##
    # Longitude of ascending node of orbit plane at weekly epoch
    attr_reader :omega0

    ##
    # Rate of right ascension
    attr_reader :omegadot

    ##
    # Argument of perigee
    attr_reader :w

    ##
    # Inclination
    attr_reader :inc

    ##
    # Inclination first derivative
    attr_reader :inc_dot

    ##
    # Polynomial clock correction coefficient (clock bias)
    attr_reader :af0

    ##
    # Polynomial clock correction coefficient (clock drift)
    attr_reader :af1

    ##
    # Polynomial clock correction coefficient (rate of clock drift)
    attr_reader :af2

    ##
    # Time of week
    attr_reader :toe_tow

    ##
    # Week number
    attr_reader :toe_wn

    ##
    # Clock reference time of week
    attr_reader :toc_tow

    ##
    # Clock reference week number
    attr_reader :toc_wn

    ##
    # Is valid?
    attr_reader :valid

    ##
    # Satellite is healthy?
    attr_reader :healthy

    ##
    # GNSS signal identifier
    attr_reader :sid

    ##
    # Issue of ephemeris data
    attr_reader :iode

    ##
    # Issue of clock data
    attr_reader :iodc

    ##
    # Reserved field
    attr_reader :reserved
  end

  ##
  # Carrier phase measurement in cycles represented as a 40-bit fixed point
  # number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
  # fractional cycles. This has the opposite sign convention than a typical
  # GPS receiver and the phase has the opposite sign as the pseudorange.
  class CarrierPhaseDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @i = @_io.read_s4le
      @f = @_io.read_u1
      self
    end

    ##
    # Carrier phase whole cycles
    attr_reader :i

    ##
    # Carrier phase fractional part
    attr_reader :f
  end

  ##
  # The ephemeris message returns a set of satellite orbit parameters that
  # is used to calculate Galileo satellite position, velocity, and clock
  # offset. Please see the Signal In Space ICD OS SIS ICD, Issue 1.3,
  # December 2016 for more details.
  class MsgEphemerisGal < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = EphemerisCommonContent.new(@_io, self, @_root)
      @bgd_e1e5a = @_io.read_f4le
      @bgd_e1e5b = @_io.read_f4le
      @c_rs = @_io.read_f4le
      @c_rc = @_io.read_f4le
      @c_uc = @_io.read_f4le
      @c_us = @_io.read_f4le
      @c_ic = @_io.read_f4le
      @c_is = @_io.read_f4le
      @dn = @_io.read_f8le
      @m0 = @_io.read_f8le
      @ecc = @_io.read_f8le
      @sqrta = @_io.read_f8le
      @omega0 = @_io.read_f8le
      @omegadot = @_io.read_f8le
      @w = @_io.read_f8le
      @inc = @_io.read_f8le
      @inc_dot = @_io.read_f8le
      @af0 = @_io.read_f8le
      @af1 = @_io.read_f8le
      @af2 = @_io.read_f4le
      @toc = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @iode = @_io.read_u2le
      @iodc = @_io.read_u2le
      @source = @_io.read_u1
      self
    end

    ##
    # Values common for all ephemeris types
    attr_reader :common

    ##
    # E1-E5a Broadcast Group Delay
    attr_reader :bgd_e1e5a

    ##
    # E1-E5b Broadcast Group Delay
    attr_reader :bgd_e1e5b

    ##
    # Amplitude of the sine harmonic correction term to the orbit radius
    attr_reader :c_rs

    ##
    # Amplitude of the cosine harmonic correction term to the orbit radius
    attr_reader :c_rc

    ##
    # Amplitude of the cosine harmonic correction term to the argument of
    # latitude
    attr_reader :c_uc

    ##
    # Amplitude of the sine harmonic correction term to the argument of
    # latitude
    attr_reader :c_us

    ##
    # Amplitude of the cosine harmonic correction term to the angle of
    # inclination
    attr_reader :c_ic

    ##
    # Amplitude of the sine harmonic correction term to the angle of
    # inclination
    attr_reader :c_is

    ##
    # Mean motion difference
    attr_reader :dn

    ##
    # Mean anomaly at reference time
    attr_reader :m0

    ##
    # Eccentricity of satellite orbit
    attr_reader :ecc

    ##
    # Square root of the semi-major axis of orbit
    attr_reader :sqrta

    ##
    # Longitude of ascending node of orbit plane at weekly epoch
    attr_reader :omega0

    ##
    # Rate of right ascension
    attr_reader :omegadot

    ##
    # Argument of perigee
    attr_reader :w

    ##
    # Inclination
    attr_reader :inc

    ##
    # Inclination first derivative
    attr_reader :inc_dot

    ##
    # Polynomial clock correction coefficient (clock bias)
    attr_reader :af0

    ##
    # Polynomial clock correction coefficient (clock drift)
    attr_reader :af1

    ##
    # Polynomial clock correction coefficient (rate of clock drift)
    attr_reader :af2

    ##
    # Clock reference
    attr_reader :toc

    ##
    # Issue of data (IODnav)
    attr_reader :iode

    ##
    # Issue of data (IODnav). Always equal to iode
    attr_reader :iodc

    ##
    # 0=I/NAV, 1=F/NAV
    attr_reader :source
  end

  ##
  # Pseudorange and carrier phase network corrections for a satellite
  # signal.
  class PackedOsrContent < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @p = @_io.read_u4le
      @l = Gnss::CarrierPhase.new(@_io, self, @_root)
      @lock = @_io.read_u1
      @flags = @_io.read_u1
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @iono_std = @_io.read_u2le
      @tropo_std = @_io.read_u2le
      @range_std = @_io.read_u2le
      self
    end

    ##
    # Pseudorange observation
    attr_reader :p

    ##
    # Carrier phase observation with typical sign convention.
    attr_reader :l

    ##
    # Lock timer. This value gives an indication of the time for which a
    # signal has maintained continuous phase lock. Whenever a signal has
    # lost and regained lock, this value is reset to zero. It is encoded
    # according to DF402 from the RTCM 10403.2 Amendment 2 specification.
    # Valid values range from 0 to 15 and the most significant nibble is
    # reserved for future use.
    attr_reader :lock

    ##
    # Correction flags.
    attr_reader :flags

    ##
    # GNSS signal identifier (16 bit)
    attr_reader :sid

    ##
    # Slant ionospheric correction standard deviation
    attr_reader :iono_std

    ##
    # Slant tropospheric correction standard deviation
    attr_reader :tropo_std

    ##
    # Orbit/clock/bias correction projected on range standard deviation
    attr_reader :range_std
  end

  ##
  # The ephemeris message returns a set of satellite orbit parameters that
  # is used to calculate BDS satellite position, velocity, and clock offset.
  # Please see the BeiDou Navigation Satellite System SIS-ICD Version 2.1,
  # Table 5-9 for more details.
  class MsgEphemerisBds < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = EphemerisCommonContent.new(@_io, self, @_root)
      @tgd1 = @_io.read_f4le
      @tgd2 = @_io.read_f4le
      @c_rs = @_io.read_f4le
      @c_rc = @_io.read_f4le
      @c_uc = @_io.read_f4le
      @c_us = @_io.read_f4le
      @c_ic = @_io.read_f4le
      @c_is = @_io.read_f4le
      @dn = @_io.read_f8le
      @m0 = @_io.read_f8le
      @ecc = @_io.read_f8le
      @sqrta = @_io.read_f8le
      @omega0 = @_io.read_f8le
      @omegadot = @_io.read_f8le
      @w = @_io.read_f8le
      @inc = @_io.read_f8le
      @inc_dot = @_io.read_f8le
      @af0 = @_io.read_f8le
      @af1 = @_io.read_f4le
      @af2 = @_io.read_f4le
      @toc = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @iode = @_io.read_u1
      @iodc = @_io.read_u2le
      self
    end

    ##
    # Values common for all ephemeris types
    attr_reader :common

    ##
    # Group delay differential for B1
    attr_reader :tgd1

    ##
    # Group delay differential for B2
    attr_reader :tgd2

    ##
    # Amplitude of the sine harmonic correction term to the orbit radius
    attr_reader :c_rs

    ##
    # Amplitude of the cosine harmonic correction term to the orbit radius
    attr_reader :c_rc

    ##
    # Amplitude of the cosine harmonic correction term to the argument of
    # latitude
    attr_reader :c_uc

    ##
    # Amplitude of the sine harmonic correction term to the argument of
    # latitude
    attr_reader :c_us

    ##
    # Amplitude of the cosine harmonic correction term to the angle of
    # inclination
    attr_reader :c_ic

    ##
    # Amplitude of the sine harmonic correction term to the angle of
    # inclination
    attr_reader :c_is

    ##
    # Mean motion difference
    attr_reader :dn

    ##
    # Mean anomaly at reference time
    attr_reader :m0

    ##
    # Eccentricity of satellite orbit
    attr_reader :ecc

    ##
    # Square root of the semi-major axis of orbit
    attr_reader :sqrta

    ##
    # Longitude of ascending node of orbit plane at weekly epoch
    attr_reader :omega0

    ##
    # Rate of right ascension
    attr_reader :omegadot

    ##
    # Argument of perigee
    attr_reader :w

    ##
    # Inclination
    attr_reader :inc

    ##
    # Inclination first derivative
    attr_reader :inc_dot

    ##
    # Polynomial clock correction coefficient (clock bias)
    attr_reader :af0

    ##
    # Polynomial clock correction coefficient (clock drift)
    attr_reader :af1

    ##
    # Polynomial clock correction coefficient (rate of clock drift)
    attr_reader :af2

    ##
    # Clock reference
    attr_reader :toc

    ##
    # Issue of ephemeris data
    # Calculated from the navigation data parameter t_oe per RTCM/CSNO
    # recommendation: IODE = mod (t_oe / 720, 240)
    attr_reader :iode

    ##
    # Issue of clock data
    # Calculated from the navigation data parameter t_oe per RTCM/CSNO
    # recommendation: IODE = mod (t_oc / 720, 240)
    attr_reader :iodc
  end

  ##
  # Deprecated.
  class MsgEphemerisGpsDepF < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = EphemerisCommonContentDepB.new(@_io, self, @_root)
      @tgd = @_io.read_f8le
      @c_rs = @_io.read_f8le
      @c_rc = @_io.read_f8le
      @c_uc = @_io.read_f8le
      @c_us = @_io.read_f8le
      @c_ic = @_io.read_f8le
      @c_is = @_io.read_f8le
      @dn = @_io.read_f8le
      @m0 = @_io.read_f8le
      @ecc = @_io.read_f8le
      @sqrta = @_io.read_f8le
      @omega0 = @_io.read_f8le
      @omegadot = @_io.read_f8le
      @w = @_io.read_f8le
      @inc = @_io.read_f8le
      @inc_dot = @_io.read_f8le
      @af0 = @_io.read_f8le
      @af1 = @_io.read_f8le
      @af2 = @_io.read_f8le
      @toc = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @iode = @_io.read_u1
      @iodc = @_io.read_u2le
      self
    end

    ##
    # Values common for all ephemeris types
    attr_reader :common

    ##
    # Group delay differential between L1 and L2
    attr_reader :tgd

    ##
    # Amplitude of the sine harmonic correction term to the orbit radius
    attr_reader :c_rs

    ##
    # Amplitude of the cosine harmonic correction term to the orbit radius
    attr_reader :c_rc

    ##
    # Amplitude of the cosine harmonic correction term to the argument of
    # latitude
    attr_reader :c_uc

    ##
    # Amplitude of the sine harmonic correction term to the argument of
    # latitude
    attr_reader :c_us

    ##
    # Amplitude of the cosine harmonic correction term to the angle of
    # inclination
    attr_reader :c_ic

    ##
    # Amplitude of the sine harmonic correction term to the angle of
    # inclination
    attr_reader :c_is

    ##
    # Mean motion difference
    attr_reader :dn

    ##
    # Mean anomaly at reference time
    attr_reader :m0

    ##
    # Eccentricity of satellite orbit
    attr_reader :ecc

    ##
    # Square root of the semi-major axis of orbit
    attr_reader :sqrta

    ##
    # Longitude of ascending node of orbit plane at weekly epoch
    attr_reader :omega0

    ##
    # Rate of right ascension
    attr_reader :omegadot

    ##
    # Argument of perigee
    attr_reader :w

    ##
    # Inclination
    attr_reader :inc

    ##
    # Inclination first derivative
    attr_reader :inc_dot

    ##
    # Polynomial clock correction coefficient (clock bias)
    attr_reader :af0

    ##
    # Polynomial clock correction coefficient (clock drift)
    attr_reader :af1

    ##
    # Polynomial clock correction coefficient (rate of clock drift)
    attr_reader :af2

    ##
    # Clock reference
    attr_reader :toc

    ##
    # Issue of ephemeris data
    attr_reader :iode

    ##
    # Issue of clock data
    attr_reader :iodc
  end

  ##
  # Header of a GNSS observation message.
  class ObservationHeader < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @t = Gnss::GpsTime.new(@_io, self, @_root)
      @n_obs = @_io.read_u1
      self
    end

    ##
    # GNSS time of this observation
    attr_reader :t

    ##
    # Total number of observations. First nibble is the size of the
    # sequence (n), second nibble is the zero-indexed counter (ith packet
    # of n)
    attr_reader :n_obs
  end

  ##
  # Deprecated.
  class MsgEphemerisSbasDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = EphemerisCommonContentDepA.new(@_io, self, @_root)
      @pos = []
      (3).times { |i|
        @pos << @_io.read_f8le
      }
      @vel = []
      (3).times { |i|
        @vel << @_io.read_f8le
      }
      @acc = []
      (3).times { |i|
        @acc << @_io.read_f8le
      }
      @a_gf0 = @_io.read_f8le
      @a_gf1 = @_io.read_f8le
      self
    end

    ##
    # Values common for all ephemeris types
    attr_reader :common

    ##
    # Position of the GEO at time toe
    attr_reader :pos

    ##
    # Velocity of the GEO at time toe
    attr_reader :vel

    ##
    # Acceleration of the GEO at time toe
    attr_reader :acc

    ##
    # Time offset of the GEO clock w.r.t. SBAS Network Time
    attr_reader :a_gf0

    ##
    # Drift of the GEO clock w.r.t. SBAS Network Time
    attr_reader :a_gf1
  end

  ##
  # Pseudorange and carrier phase observation for a satellite being tracked.
  # The observations are interoperable with 3rd party receivers and conform
  # with typical RTCM 3.1 message GPS/GLO observations.
  # 
  # Carrier phase observations are not guaranteed to be aligned to the RINEX
  # 3 or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are
  # currently performed.
  class PackedObsContent < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @p = @_io.read_u4le
      @l = Gnss::CarrierPhase.new(@_io, self, @_root)
      @d = Doppler.new(@_io, self, @_root)
      @cn0 = @_io.read_u1
      @lock = @_io.read_u1
      @flags = @_io.read_u1
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      self
    end

    ##
    # Pseudorange observation
    attr_reader :p

    ##
    # Carrier phase observation with typical sign convention.
    attr_reader :l

    ##
    # Doppler observation with typical sign convention.
    attr_reader :d

    ##
    # Carrier-to-Noise density.  Zero implies invalid cn0.
    attr_reader :cn0

    ##
    # Lock timer. This value gives an indication of the time for which a
    # signal has maintained continuous phase lock. Whenever a signal has
    # lost and regained lock, this value is reset to zero. It is encoded
    # according to DF402 from the RTCM 10403.2 Amendment 2 specification.
    # Valid values range from 0 to 15 and the most significant nibble is
    # reserved for future use.
    attr_reader :lock

    ##
    # Measurement status flags. A bit field of flags providing the status
    # of this observation.  If this field is 0 it means only the Cn0
    # estimate for the signal is valid.
    attr_reader :flags

    ##
    # GNSS signal identifier (16 bit)
    attr_reader :sid
  end

  ##
  # The base station position message is the position reported by the base
  # station itself in absolute Earth Centered Earth Fixed coordinates. It is
  # used for pseudo-absolute RTK positioning, and is required to be a high-
  # accuracy surveyed location of the base station. Any error here will
  # result in an error in the pseudo-absolute position output.
  class MsgBasePosEcef < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @x = @_io.read_f8le
      @y = @_io.read_f8le
      @z = @_io.read_f8le
      self
    end

    ##
    # ECEF X coordinate
    attr_reader :x

    ##
    # ECEF Y coordinate
    attr_reader :y

    ##
    # ECEF Z coordinate
    attr_reader :z
  end

  ##
  # Deprecated.
  class MsgEphemerisGloDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = EphemerisCommonContentDepA.new(@_io, self, @_root)
      @gamma = @_io.read_f8le
      @tau = @_io.read_f8le
      @pos = []
      (3).times { |i|
        @pos << @_io.read_f8le
      }
      @vel = []
      (3).times { |i|
        @vel << @_io.read_f8le
      }
      @acc = []
      (3).times { |i|
        @acc << @_io.read_f8le
      }
      self
    end

    ##
    # Values common for all ephemeris types
    attr_reader :common

    ##
    # Relative deviation of predicted carrier frequency from nominal
    attr_reader :gamma

    ##
    # Correction to the SV time
    attr_reader :tau

    ##
    # Position of the SV at tb in PZ-90.02 coordinates system
    attr_reader :pos

    ##
    # Velocity vector of the SV at tb in PZ-90.02 coordinates system
    attr_reader :vel

    ##
    # Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    attr_reader :acc
  end

  ##
  # Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
  class MsgGroupDelay < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @t_op = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @valid = @_io.read_u1
      @tgd = @_io.read_s2le
      @isc_l1ca = @_io.read_s2le
      @isc_l2c = @_io.read_s2le
      self
    end

    ##
    # Data Predict Time of Week
    attr_reader :t_op

    ##
    # GNSS signal identifier
    attr_reader :sid

    ##
    # bit-field indicating validity of the values, LSB indicating tgd
    # validity etc. 1 = value is valid, 0 = value is not valid.
    attr_reader :valid
    attr_reader :tgd
    attr_reader :isc_l1ca
    attr_reader :isc_l2c
  end

  ##
  # The almanac message returns a set of satellite orbit parameters. Almanac
  # data is not very precise and is considered valid for up to several
  # months. Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate
  # information and almanac" for details.
  class MsgAlmanacGlo < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = AlmanacCommonContent.new(@_io, self, @_root)
      @lambda_na = @_io.read_f8le
      @t_lambda_na = @_io.read_f8le
      @i = @_io.read_f8le
      @t = @_io.read_f8le
      @t_dot = @_io.read_f8le
      @epsilon = @_io.read_f8le
      @omega = @_io.read_f8le
      self
    end

    ##
    # Values common for all almanac types
    attr_reader :common

    ##
    # Longitude of the first ascending node of the orbit in PZ-90.02
    # coordinate system
    attr_reader :lambda_na

    ##
    # Time of the first ascending node passage
    attr_reader :t_lambda_na

    ##
    # Value of inclination at instant of t_lambda
    attr_reader :i

    ##
    # Value of Draconian period at instant of t_lambda
    attr_reader :t

    ##
    # Rate of change of the Draconian period
    attr_reader :t_dot

    ##
    # Eccentricity at instant of t_lambda
    attr_reader :epsilon

    ##
    # Argument of perigee at instant of t_lambda
    attr_reader :omega
  end

  ##
  # Deprecated.
  class MsgEphemerisGalDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = EphemerisCommonContent.new(@_io, self, @_root)
      @bgd_e1e5a = @_io.read_f4le
      @bgd_e1e5b = @_io.read_f4le
      @c_rs = @_io.read_f4le
      @c_rc = @_io.read_f4le
      @c_uc = @_io.read_f4le
      @c_us = @_io.read_f4le
      @c_ic = @_io.read_f4le
      @c_is = @_io.read_f4le
      @dn = @_io.read_f8le
      @m0 = @_io.read_f8le
      @ecc = @_io.read_f8le
      @sqrta = @_io.read_f8le
      @omega0 = @_io.read_f8le
      @omegadot = @_io.read_f8le
      @w = @_io.read_f8le
      @inc = @_io.read_f8le
      @inc_dot = @_io.read_f8le
      @af0 = @_io.read_f8le
      @af1 = @_io.read_f8le
      @af2 = @_io.read_f4le
      @toc = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @iode = @_io.read_u2le
      @iodc = @_io.read_u2le
      self
    end

    ##
    # Values common for all ephemeris types
    attr_reader :common

    ##
    # E1-E5a Broadcast Group Delay
    attr_reader :bgd_e1e5a

    ##
    # E1-E5b Broadcast Group Delay
    attr_reader :bgd_e1e5b

    ##
    # Amplitude of the sine harmonic correction term to the orbit radius
    attr_reader :c_rs

    ##
    # Amplitude of the cosine harmonic correction term to the orbit radius
    attr_reader :c_rc

    ##
    # Amplitude of the cosine harmonic correction term to the argument of
    # latitude
    attr_reader :c_uc

    ##
    # Amplitude of the sine harmonic correction term to the argument of
    # latitude
    attr_reader :c_us

    ##
    # Amplitude of the cosine harmonic correction term to the angle of
    # inclination
    attr_reader :c_ic

    ##
    # Amplitude of the sine harmonic correction term to the angle of
    # inclination
    attr_reader :c_is

    ##
    # Mean motion difference
    attr_reader :dn

    ##
    # Mean anomaly at reference time
    attr_reader :m0

    ##
    # Eccentricity of satellite orbit
    attr_reader :ecc

    ##
    # Square root of the semi-major axis of orbit
    attr_reader :sqrta

    ##
    # Longitude of ascending node of orbit plane at weekly epoch
    attr_reader :omega0

    ##
    # Rate of right ascension
    attr_reader :omegadot

    ##
    # Argument of perigee
    attr_reader :w

    ##
    # Inclination
    attr_reader :inc

    ##
    # Inclination first derivative
    attr_reader :inc_dot

    ##
    # Polynomial clock correction coefficient (clock bias)
    attr_reader :af0

    ##
    # Polynomial clock correction coefficient (clock drift)
    attr_reader :af1

    ##
    # Polynomial clock correction coefficient (rate of clock drift)
    attr_reader :af2

    ##
    # Clock reference
    attr_reader :toc

    ##
    # Issue of data (IODnav)
    attr_reader :iode

    ##
    # Issue of data (IODnav). Always equal to iode
    attr_reader :iodc
  end

  ##
  # Deprecated.
  class MsgObsDepB < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = ObservationHeaderDep.new(@_io, self, @_root)
      @obs = []
      i = 0
      while not @_io.eof?
        @obs << PackedObsContentDepB.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Header of a GPS observation message
    attr_reader :header

    ##
    # Pseudorange and carrier phase observation for a satellite being
    # tracked.
    attr_reader :obs
  end

  ##
  # Deprecated.
  class PackedObsContentDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @p = @_io.read_u4le
      @l = CarrierPhaseDepA.new(@_io, self, @_root)
      @cn0 = @_io.read_u1
      @lock = @_io.read_u2le
      @prn = @_io.read_u1
      self
    end

    ##
    # Pseudorange observation
    attr_reader :p

    ##
    # Carrier phase observation with opposite sign from typical convention
    attr_reader :l

    ##
    # Carrier-to-Noise density
    attr_reader :cn0

    ##
    # Lock indicator. This value changes whenever a satellite signal has
    # lost and regained lock, indicating that the carrier phase ambiguity
    # may have changed.
    attr_reader :lock

    ##
    # PRN-1 identifier of the satellite signal
    attr_reader :prn
  end

  ##
  # The ephemeris message returns a set of satellite orbit parameters that
  # is used to calculate GLO satellite position, velocity, and clock offset.
  # Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
  # immediate information (ephemeris parameters)" for more details.
  class MsgEphemerisGlo < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = EphemerisCommonContent.new(@_io, self, @_root)
      @gamma = @_io.read_f4le
      @tau = @_io.read_f4le
      @d_tau = @_io.read_f4le
      @pos = []
      (3).times { |i|
        @pos << @_io.read_f8le
      }
      @vel = []
      (3).times { |i|
        @vel << @_io.read_f8le
      }
      @acc = []
      (3).times { |i|
        @acc << @_io.read_f4le
      }
      @fcn = @_io.read_u1
      @iod = @_io.read_u1
      self
    end

    ##
    # Values common for all ephemeris types
    attr_reader :common

    ##
    # Relative deviation of predicted carrier frequency from nominal
    attr_reader :gamma

    ##
    # Correction to the SV time
    attr_reader :tau

    ##
    # Equipment delay between L1 and L2
    attr_reader :d_tau

    ##
    # Position of the SV at tb in PZ-90.02 coordinates system
    attr_reader :pos

    ##
    # Velocity vector of the SV at tb in PZ-90.02 coordinates system
    attr_reader :vel

    ##
    # Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    attr_reader :acc

    ##
    # Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
    attr_reader :fcn

    ##
    # Issue of data. Equal to the 7 bits of the immediate data word t_b
    attr_reader :iod
  end

  ##
  # The ionospheric parameters which allow the "L1 only" or "L2 only" user
  # to utilize the ionospheric model for computation of the ionospheric
  # delay. Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
  class MsgIono < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @t_nmct = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @a0 = @_io.read_f8le
      @a1 = @_io.read_f8le
      @a2 = @_io.read_f8le
      @a3 = @_io.read_f8le
      @b0 = @_io.read_f8le
      @b1 = @_io.read_f8le
      @b2 = @_io.read_f8le
      @b3 = @_io.read_f8le
      self
    end

    ##
    # Navigation Message Correction Table Validity Time
    attr_reader :t_nmct
    attr_reader :a0
    attr_reader :a1
    attr_reader :a2
    attr_reader :a3
    attr_reader :b0
    attr_reader :b1
    attr_reader :b2
    attr_reader :b3
  end

  ##
  # Deprecated.
  class MsgEphemerisDepD < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tgd = @_io.read_f8le
      @c_rs = @_io.read_f8le
      @c_rc = @_io.read_f8le
      @c_uc = @_io.read_f8le
      @c_us = @_io.read_f8le
      @c_ic = @_io.read_f8le
      @c_is = @_io.read_f8le
      @dn = @_io.read_f8le
      @m0 = @_io.read_f8le
      @ecc = @_io.read_f8le
      @sqrta = @_io.read_f8le
      @omega0 = @_io.read_f8le
      @omegadot = @_io.read_f8le
      @w = @_io.read_f8le
      @inc = @_io.read_f8le
      @inc_dot = @_io.read_f8le
      @af0 = @_io.read_f8le
      @af1 = @_io.read_f8le
      @af2 = @_io.read_f8le
      @toe_tow = @_io.read_f8le
      @toe_wn = @_io.read_u2le
      @toc_tow = @_io.read_f8le
      @toc_wn = @_io.read_u2le
      @valid = @_io.read_u1
      @healthy = @_io.read_u1
      @sid = Gnss::GnssSignalDep.new(@_io, self, @_root)
      @iode = @_io.read_u1
      @iodc = @_io.read_u2le
      @reserved = @_io.read_u4le
      self
    end

    ##
    # Group delay differential between L1 and L2
    attr_reader :tgd

    ##
    # Amplitude of the sine harmonic correction term to the orbit radius
    attr_reader :c_rs

    ##
    # Amplitude of the cosine harmonic correction term to the orbit radius
    attr_reader :c_rc

    ##
    # Amplitude of the cosine harmonic correction term to the argument of
    # latitude
    attr_reader :c_uc

    ##
    # Amplitude of the sine harmonic correction term to the argument of
    # latitude
    attr_reader :c_us

    ##
    # Amplitude of the cosine harmonic correction term to the angle of
    # inclination
    attr_reader :c_ic

    ##
    # Amplitude of the sine harmonic correction term to the angle of
    # inclination
    attr_reader :c_is

    ##
    # Mean motion difference
    attr_reader :dn

    ##
    # Mean anomaly at reference time
    attr_reader :m0

    ##
    # Eccentricity of satellite orbit
    attr_reader :ecc

    ##
    # Square root of the semi-major axis of orbit
    attr_reader :sqrta

    ##
    # Longitude of ascending node of orbit plane at weekly epoch
    attr_reader :omega0

    ##
    # Rate of right ascension
    attr_reader :omegadot

    ##
    # Argument of perigee
    attr_reader :w

    ##
    # Inclination
    attr_reader :inc

    ##
    # Inclination first derivative
    attr_reader :inc_dot

    ##
    # Polynomial clock correction coefficient (clock bias)
    attr_reader :af0

    ##
    # Polynomial clock correction coefficient (clock drift)
    attr_reader :af1

    ##
    # Polynomial clock correction coefficient (rate of clock drift)
    attr_reader :af2

    ##
    # Time of week
    attr_reader :toe_tow

    ##
    # Week number
    attr_reader :toe_wn

    ##
    # Clock reference time of week
    attr_reader :toc_tow

    ##
    # Clock reference week number
    attr_reader :toc_wn

    ##
    # Is valid?
    attr_reader :valid

    ##
    # Satellite is healthy?
    attr_reader :healthy

    ##
    # GNSS signal identifier
    attr_reader :sid

    ##
    # Issue of ephemeris data
    attr_reader :iode

    ##
    # Issue of clock data
    attr_reader :iodc

    ##
    # Reserved field
    attr_reader :reserved
  end

  ##
  # The ephemeris message returns a set of satellite orbit parameters that
  # is used to calculate GPS satellite position, velocity, and clock offset.
  # Please see the Navstar GPS Space Segment/Navigation user interfaces
  # (ICD-GPS-200, Table 20-III) for more details.
  class MsgEphemerisGps < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = EphemerisCommonContent.new(@_io, self, @_root)
      @tgd = @_io.read_f4le
      @c_rs = @_io.read_f4le
      @c_rc = @_io.read_f4le
      @c_uc = @_io.read_f4le
      @c_us = @_io.read_f4le
      @c_ic = @_io.read_f4le
      @c_is = @_io.read_f4le
      @dn = @_io.read_f8le
      @m0 = @_io.read_f8le
      @ecc = @_io.read_f8le
      @sqrta = @_io.read_f8le
      @omega0 = @_io.read_f8le
      @omegadot = @_io.read_f8le
      @w = @_io.read_f8le
      @inc = @_io.read_f8le
      @inc_dot = @_io.read_f8le
      @af0 = @_io.read_f4le
      @af1 = @_io.read_f4le
      @af2 = @_io.read_f4le
      @toc = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @iode = @_io.read_u1
      @iodc = @_io.read_u2le
      self
    end

    ##
    # Values common for all ephemeris types
    attr_reader :common

    ##
    # Group delay differential between L1 and L2
    attr_reader :tgd

    ##
    # Amplitude of the sine harmonic correction term to the orbit radius
    attr_reader :c_rs

    ##
    # Amplitude of the cosine harmonic correction term to the orbit radius
    attr_reader :c_rc

    ##
    # Amplitude of the cosine harmonic correction term to the argument of
    # latitude
    attr_reader :c_uc

    ##
    # Amplitude of the sine harmonic correction term to the argument of
    # latitude
    attr_reader :c_us

    ##
    # Amplitude of the cosine harmonic correction term to the angle of
    # inclination
    attr_reader :c_ic

    ##
    # Amplitude of the sine harmonic correction term to the angle of
    # inclination
    attr_reader :c_is

    ##
    # Mean motion difference
    attr_reader :dn

    ##
    # Mean anomaly at reference time
    attr_reader :m0

    ##
    # Eccentricity of satellite orbit
    attr_reader :ecc

    ##
    # Square root of the semi-major axis of orbit
    attr_reader :sqrta

    ##
    # Longitude of ascending node of orbit plane at weekly epoch
    attr_reader :omega0

    ##
    # Rate of right ascension
    attr_reader :omegadot

    ##
    # Argument of perigee
    attr_reader :w

    ##
    # Inclination
    attr_reader :inc

    ##
    # Inclination first derivative
    attr_reader :inc_dot

    ##
    # Polynomial clock correction coefficient (clock bias)
    attr_reader :af0

    ##
    # Polynomial clock correction coefficient (clock drift)
    attr_reader :af1

    ##
    # Polynomial clock correction coefficient (rate of clock drift)
    attr_reader :af2

    ##
    # Clock reference
    attr_reader :toc

    ##
    # Issue of ephemeris data
    attr_reader :iode

    ##
    # Issue of clock data
    attr_reader :iodc
  end

  ##
  # The base station position message is the position reported by the base
  # station itself. It is used for pseudo-absolute RTK positioning, and is
  # required to be a high-accuracy surveyed location of the base station.
  # Any error here will result in an error in the pseudo-absolute position
  # output.
  class MsgBasePosLlh < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @lat = @_io.read_f8le
      @lon = @_io.read_f8le
      @height = @_io.read_f8le
      self
    end

    ##
    # Latitude
    attr_reader :lat

    ##
    # Longitude
    attr_reader :lon

    ##
    # Height
    attr_reader :height
  end
  class AlmanacCommonContent < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @toa = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @ura = @_io.read_f8le
      @fit_interval = @_io.read_u4le
      @valid = @_io.read_u1
      @health_bits = @_io.read_u1
      self
    end

    ##
    # GNSS signal identifier
    attr_reader :sid

    ##
    # Reference time of almanac
    attr_reader :toa

    ##
    # User Range Accuracy
    attr_reader :ura

    ##
    # Curve fit interval
    attr_reader :fit_interval

    ##
    # Status of almanac, 1 = valid, 0 = invalid
    attr_reader :valid

    ##
    # Satellite health status for GPS:
    #   - bits 5-7: NAV data health status. See IS-GPS-200H
    #     Table 20-VII: NAV Data Health Indications.
    #   - bits 0-4: Signal health status. See IS-GPS-200H
    #     Table 20-VIII. Codes for Health of SV Signal
    #     Components.
    # Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for
    # details):
    #   - bit 0: C(n), "unhealthy" flag that is transmitted within
    #     non-immediate data and indicates overall constellation status
    #     at the moment of almanac uploading.
    #     '0' indicates malfunction of n-satellite.
    #     '1' indicates that n-satellite is operational.
    #   - bit 1: Bn(ln), '0' indicates the satellite is operational
    #     and suitable for navigation.
    attr_reader :health_bits
  end

  ##
  # The OSR message contains network corrections in an observation-like
  # format.
  class MsgOsr < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = ObservationHeader.new(@_io, self, @_root)
      @obs = []
      i = 0
      while not @_io.eof?
        @obs << PackedOsrContent.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Header of a GPS observation message
    attr_reader :header

    ##
    # Network correction for a satellite signal.
    attr_reader :obs
  end

  ##
  # The ephemeris message returns a set of satellite orbit parameters that
  # is used to calculate GLO satellite position, velocity, and clock offset.
  # Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
  # immediate information (ephemeris parameters)" for more details.
  class MsgEphemerisGloDepC < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = EphemerisCommonContentDepB.new(@_io, self, @_root)
      @gamma = @_io.read_f8le
      @tau = @_io.read_f8le
      @d_tau = @_io.read_f8le
      @pos = []
      (3).times { |i|
        @pos << @_io.read_f8le
      }
      @vel = []
      (3).times { |i|
        @vel << @_io.read_f8le
      }
      @acc = []
      (3).times { |i|
        @acc << @_io.read_f8le
      }
      @fcn = @_io.read_u1
      self
    end

    ##
    # Values common for all ephemeris types
    attr_reader :common

    ##
    # Relative deviation of predicted carrier frequency from nominal
    attr_reader :gamma

    ##
    # Correction to the SV time
    attr_reader :tau

    ##
    # Equipment delay between L1 and L2
    attr_reader :d_tau

    ##
    # Position of the SV at tb in PZ-90.02 coordinates system
    attr_reader :pos

    ##
    # Velocity vector of the SV at tb in PZ-90.02 coordinates system
    attr_reader :vel

    ##
    # Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    attr_reader :acc

    ##
    # Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
    attr_reader :fcn
  end

  ##
  # Deprecated.
  class MsgEphemerisGloDepB < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = EphemerisCommonContentDepB.new(@_io, self, @_root)
      @gamma = @_io.read_f8le
      @tau = @_io.read_f8le
      @pos = []
      (3).times { |i|
        @pos << @_io.read_f8le
      }
      @vel = []
      (3).times { |i|
        @vel << @_io.read_f8le
      }
      @acc = []
      (3).times { |i|
        @acc << @_io.read_f8le
      }
      self
    end

    ##
    # Values common for all ephemeris types
    attr_reader :common

    ##
    # Relative deviation of predicted carrier frequency from nominal
    attr_reader :gamma

    ##
    # Correction to the SV time
    attr_reader :tau

    ##
    # Position of the SV at tb in PZ-90.02 coordinates system
    attr_reader :pos

    ##
    # Velocity vector of the SV at tb in PZ-90.02 coordinates system
    attr_reader :vel

    ##
    # Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
    attr_reader :acc
  end

  ##
  # Deprecated.
  class MsgSvConfigurationGpsDep < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @t_nmct = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @l2c_mask = @_io.read_u4le
      self
    end

    ##
    # Navigation Message Correction Table Validity Time
    attr_reader :t_nmct

    ##
    # L2C capability mask, SV32 bit being MSB, SV1 bit being LSB
    attr_reader :l2c_mask
  end
  class MsgEphemerisSbas < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @common = EphemerisCommonContent.new(@_io, self, @_root)
      @pos = []
      (3).times { |i|
        @pos << @_io.read_f8le
      }
      @vel = []
      (3).times { |i|
        @vel << @_io.read_f4le
      }
      @acc = []
      (3).times { |i|
        @acc << @_io.read_f4le
      }
      @a_gf0 = @_io.read_f4le
      @a_gf1 = @_io.read_f4le
      self
    end

    ##
    # Values common for all ephemeris types
    attr_reader :common

    ##
    # Position of the GEO at time toe
    attr_reader :pos

    ##
    # Velocity of the GEO at time toe
    attr_reader :vel

    ##
    # Acceleration of the GEO at time toe
    attr_reader :acc

    ##
    # Time offset of the GEO clock w.r.t. SBAS Network Time
    attr_reader :a_gf0

    ##
    # Drift of the GEO clock w.r.t. SBAS Network Time
    attr_reader :a_gf1
  end

  ##
  # Pseudorange and carrier phase observation for a satellite being tracked.
  # Pseudoranges are referenced to a nominal pseudorange.
  class PackedObsContentDepB < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @p = @_io.read_u4le
      @l = CarrierPhaseDepA.new(@_io, self, @_root)
      @cn0 = @_io.read_u1
      @lock = @_io.read_u2le
      @sid = Gnss::GnssSignalDep.new(@_io, self, @_root)
      self
    end

    ##
    # Pseudorange observation
    attr_reader :p

    ##
    # Carrier phase observation with opposite sign from typical
    # convention.
    attr_reader :l

    ##
    # Carrier-to-Noise density
    attr_reader :cn0

    ##
    # Lock indicator. This value changes whenever a satellite signal has
    # lost and regained lock, indicating that the carrier phase ambiguity
    # may have changed.
    attr_reader :lock

    ##
    # GNSS signal identifier
    attr_reader :sid
  end

  ##
  # Deprecated.
  class MsgObsDepC < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @header = ObservationHeaderDep.new(@_io, self, @_root)
      @obs = []
      i = 0
      while not @_io.eof?
        @obs << PackedObsContentDepC.new(@_io, self, @_root)
        i += 1
      end
      self
    end

    ##
    # Header of a GPS observation message
    attr_reader :header

    ##
    # Pseudorange and carrier phase observation for a satellite being
    # tracked.
    attr_reader :obs
  end

  ##
  # Deprecated.
  class MsgEphemerisDepA < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @tgd = @_io.read_f8le
      @c_rs = @_io.read_f8le
      @c_rc = @_io.read_f8le
      @c_uc = @_io.read_f8le
      @c_us = @_io.read_f8le
      @c_ic = @_io.read_f8le
      @c_is = @_io.read_f8le
      @dn = @_io.read_f8le
      @m0 = @_io.read_f8le
      @ecc = @_io.read_f8le
      @sqrta = @_io.read_f8le
      @omega0 = @_io.read_f8le
      @omegadot = @_io.read_f8le
      @w = @_io.read_f8le
      @inc = @_io.read_f8le
      @inc_dot = @_io.read_f8le
      @af0 = @_io.read_f8le
      @af1 = @_io.read_f8le
      @af2 = @_io.read_f8le
      @toe_tow = @_io.read_f8le
      @toe_wn = @_io.read_u2le
      @toc_tow = @_io.read_f8le
      @toc_wn = @_io.read_u2le
      @valid = @_io.read_u1
      @healthy = @_io.read_u1
      @prn = @_io.read_u1
      self
    end

    ##
    # Group delay differential between L1 and L2
    attr_reader :tgd

    ##
    # Amplitude of the sine harmonic correction term to the orbit radius
    attr_reader :c_rs

    ##
    # Amplitude of the cosine harmonic correction term to the orbit radius
    attr_reader :c_rc

    ##
    # Amplitude of the cosine harmonic correction term to the argument of
    # latitude
    attr_reader :c_uc

    ##
    # Amplitude of the sine harmonic correction term to the argument of
    # latitude
    attr_reader :c_us

    ##
    # Amplitude of the cosine harmonic correction term to the angle of
    # inclination
    attr_reader :c_ic

    ##
    # Amplitude of the sine harmonic correction term to the angle of
    # inclination
    attr_reader :c_is

    ##
    # Mean motion difference
    attr_reader :dn

    ##
    # Mean anomaly at reference time
    attr_reader :m0

    ##
    # Eccentricity of satellite orbit
    attr_reader :ecc

    ##
    # Square root of the semi-major axis of orbit
    attr_reader :sqrta

    ##
    # Longitude of ascending node of orbit plane at weekly epoch
    attr_reader :omega0

    ##
    # Rate of right ascension
    attr_reader :omegadot

    ##
    # Argument of perigee
    attr_reader :w

    ##
    # Inclination
    attr_reader :inc

    ##
    # Inclination first derivative
    attr_reader :inc_dot

    ##
    # Polynomial clock correction coefficient (clock bias)
    attr_reader :af0

    ##
    # Polynomial clock correction coefficient (clock drift)
    attr_reader :af1

    ##
    # Polynomial clock correction coefficient (rate of clock drift)
    attr_reader :af2

    ##
    # Time of week
    attr_reader :toe_tow

    ##
    # Week number
    attr_reader :toe_wn

    ##
    # Clock reference time of week
    attr_reader :toc_tow

    ##
    # Clock reference week number
    attr_reader :toc_wn

    ##
    # Is valid?
    attr_reader :valid

    ##
    # Satellite is healthy?
    attr_reader :healthy

    ##
    # PRN being tracked
    attr_reader :prn
  end
  class EphemerisCommonContentDepB < Kaitai::Struct::Struct
    def initialize(_io, _parent = nil, _root = self)
      super(_io, _parent, _root)
      _read
    end

    def _read
      @sid = Gnss::GnssSignal.new(@_io, self, @_root)
      @toe = Gnss::GpsTimeSec.new(@_io, self, @_root)
      @ura = @_io.read_f8le
      @fit_interval = @_io.read_u4le
      @valid = @_io.read_u1
      @health_bits = @_io.read_u1
      self
    end

    ##
    # GNSS signal identifier (16 bit)
    attr_reader :sid

    ##
    # Time of Ephemerides
    attr_reader :toe

    ##
    # User Range Accuracy
    attr_reader :ura

    ##
    # Curve fit interval
    attr_reader :fit_interval

    ##
    # Status of ephemeris, 1 = valid, 0 = invalid
    attr_reader :valid

    ##
    # Satellite health status.
    # GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
    # Others: 0 = valid, non-zero = invalid
    attr_reader :health_bits
  end
end
