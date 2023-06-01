-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

Observation = class.class(KaitaiStruct)

function Observation:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation:_read()
end


-- 
-- Azimuth and elevation angles of all the visible satellites that the
-- device does have ephemeris or almanac for.
Observation.MsgSvAzEl = class.class(KaitaiStruct)

function Observation.MsgSvAzEl:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgSvAzEl:_read()
  self.azel = {}
  local i = 0
  while not self._io:is_eof() do
    self.azel[i + 1] = Observation.SvAzEl(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Azimuth and elevation per satellite

Observation.GnssCapb = class.class(KaitaiStruct)

function Observation.GnssCapb:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.GnssCapb:_read()
  self.gps_active = self._io:read_u8le()
  self.gps_l2c = self._io:read_u8le()
  self.gps_l5 = self._io:read_u8le()
  self.glo_active = self._io:read_u4le()
  self.glo_l2of = self._io:read_u4le()
  self.glo_l3 = self._io:read_u4le()
  self.sbas_active = self._io:read_u8le()
  self.sbas_l5 = self._io:read_u8le()
  self.bds_active = self._io:read_u8le()
  self.bds_d2nav = self._io:read_u8le()
  self.bds_b2 = self._io:read_u8le()
  self.bds_b2a = self._io:read_u8le()
  self.qzss_active = self._io:read_u4le()
  self.gal_active = self._io:read_u8le()
  self.gal_e5 = self._io:read_u8le()
end

-- 
-- GPS SV active mask
-- 
-- GPS L2C active mask
-- 
-- GPS L5 active mask
-- 
-- GLO active mask
-- 
-- GLO L2OF active mask
-- 
-- GLO L3 active mask
-- 
-- SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
-- https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
-- 
-- SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
-- https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
-- 
-- BDS active mask
-- 
-- BDS D2NAV active mask
-- 
-- BDS B2 active mask
-- 
-- BDS B2A active mask
-- 
-- QZSS active mask
-- 
-- GAL active mask
-- 
-- GAL E5 active mask

-- 
-- Deprecated.
Observation.MsgGroupDelayDepB = class.class(KaitaiStruct)

function Observation.MsgGroupDelayDepB:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgGroupDelayDepB:_read()
  self.t_op = Gnss.GpsTimeSec(self._io, self, self._root)
  self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
  self.valid = self._io:read_u1()
  self.tgd = self._io:read_s2le()
  self.isc_l1ca = self._io:read_s2le()
  self.isc_l2c = self._io:read_s2le()
end

-- 
-- Data Predict Time of Week
-- 
-- GNSS signal identifier
-- 
-- bit-field indicating validity of the values, LSB indicating tgd
-- validity etc. 1 = value is valid, 0 = value is not valid.

-- 
-- Header of a GPS observation message.
Observation.ObservationHeaderDep = class.class(KaitaiStruct)

function Observation.ObservationHeaderDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.ObservationHeaderDep:_read()
  self.t = Gnss.GpsTimeDep(self._io, self, self._root)
  self.n_obs = self._io:read_u1()
end

-- 
-- GPS time of this observation
-- 
-- Total number of observations. First nibble is the size of the
-- sequence (n), second nibble is the zero-indexed counter (ith packet
-- of n)

Observation.AlmanacCommonContentDep = class.class(KaitaiStruct)

function Observation.AlmanacCommonContentDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.AlmanacCommonContentDep:_read()
  self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
  self.toa = Gnss.GpsTimeSec(self._io, self, self._root)
  self.ura = self._io:read_f8le()
  self.fit_interval = self._io:read_u4le()
  self.valid = self._io:read_u1()
  self.health_bits = self._io:read_u1()
end

-- 
-- GNSS signal identifier
-- 
-- Reference time of almanac
-- 
-- User Range Accuracy
-- 
-- Curve fit interval
-- 
-- Status of almanac, 1 = valid, 0 = invalid
-- 
-- Satellite health status for GPS:
--   - bits 5-7: NAV data health status. See IS-GPS-200H
--     Table 20-VII: NAV Data Health Indications.
--   - bits 0-4: Signal health status. See IS-GPS-200H
--     Table 20-VIII. Codes for Health of SV Signal
--     Components.
-- Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for
-- details):
--   - bit 0: C(n), "unhealthy" flag that is transmitted within
--     non-immediate data and indicates overall constellation status
--     at the moment of almanac uploading.
--     '0' indicates malfunction of n-satellite.
--     '1' indicates that n-satellite is operational.
--   - bit 1: Bn(ln), '0' indicates the satellite is operational
--     and suitable for navigation.

Observation.EphemerisCommonContentDepA = class.class(KaitaiStruct)

function Observation.EphemerisCommonContentDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.EphemerisCommonContentDepA:_read()
  self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
  self.toe = Gnss.GpsTimeDep(self._io, self, self._root)
  self.ura = self._io:read_f8le()
  self.fit_interval = self._io:read_u4le()
  self.valid = self._io:read_u1()
  self.health_bits = self._io:read_u1()
end

-- 
-- GNSS signal identifier
-- 
-- Time of Ephemerides
-- 
-- User Range Accuracy
-- 
-- Curve fit interval
-- 
-- Status of ephemeris, 1 = valid, 0 = invalid
-- 
-- Satellite health status.
-- GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
-- SBAS: 0 = valid, non-zero = invalid
-- GLO: 0 = valid, non-zero = invalid

Observation.EphemerisCommonContent = class.class(KaitaiStruct)

function Observation.EphemerisCommonContent:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.EphemerisCommonContent:_read()
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.toe = Gnss.GpsTimeSec(self._io, self, self._root)
  self.ura = self._io:read_f4le()
  self.fit_interval = self._io:read_u4le()
  self.valid = self._io:read_u1()
  self.health_bits = self._io:read_u1()
end

-- 
-- GNSS signal identifier (16 bit)
-- 
-- Time of Ephemerides
-- 
-- User Range Accuracy
-- 
-- Curve fit interval
-- 
-- Status of ephemeris, 1 = valid, 0 = invalid
-- 
-- Satellite health status.
-- GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
-- SBAS: 0 = valid, non-zero = invalid
-- GLO: 0 = valid, non-zero = invalid

-- 
-- Pseudorange and carrier phase observation for a satellite being tracked.
-- The observations are be interoperable with 3rd party receivers and
-- conform with typical RTCMv3 GNSS observations.
Observation.PackedObsContentDepC = class.class(KaitaiStruct)

function Observation.PackedObsContentDepC:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.PackedObsContentDepC:_read()
  self.p = self._io:read_u4le()
  self.l = Gnss.CarrierPhase(self._io, self, self._root)
  self.cn0 = self._io:read_u1()
  self.lock = self._io:read_u2le()
  self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
end

-- 
-- Pseudorange observation
-- 
-- Carrier phase observation with typical sign convention.
-- 
-- Carrier-to-Noise density
-- 
-- Lock indicator. This value changes whenever a satellite signal has
-- lost and regained lock, indicating that the carrier phase ambiguity
-- may have changed.
-- 
-- GNSS signal identifier

-- 
-- This observation message has been deprecated in favor of ephemeris
-- message using floats for size reduction.
Observation.MsgEphemerisGloDepD = class.class(KaitaiStruct)

function Observation.MsgEphemerisGloDepD:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisGloDepD:_read()
  self.common = Observation.EphemerisCommonContentDepB(self._io, self, self._root)
  self.gamma = self._io:read_f8le()
  self.tau = self._io:read_f8le()
  self.d_tau = self._io:read_f8le()
  self.pos = {}
  for i = 0, 3 - 1 do
    self.pos[i + 1] = self._io:read_f8le()
  end
  self.vel = {}
  for i = 0, 3 - 1 do
    self.vel[i + 1] = self._io:read_f8le()
  end
  self.acc = {}
  for i = 0, 3 - 1 do
    self.acc[i + 1] = self._io:read_f8le()
  end
  self.fcn = self._io:read_u1()
  self.iod = self._io:read_u1()
end

-- 
-- Values common for all ephemeris types
-- 
-- Relative deviation of predicted carrier frequency from nominal
-- 
-- Correction to the SV time
-- 
-- Equipment delay between L1 and L2
-- 
-- Position of the SV at tb in PZ-90.02 coordinates system
-- 
-- Velocity vector of the SV at tb in PZ-90.02 coordinates system
-- 
-- Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
-- 
-- Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
-- 
-- Issue of data. Equal to the 7 bits of the immediate data word t_b

-- 
-- Deprecated.
Observation.MsgObsDepA = class.class(KaitaiStruct)

function Observation.MsgObsDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgObsDepA:_read()
  self.header = Observation.ObservationHeaderDep(self._io, self, self._root)
  self.obs = {}
  local i = 0
  while not self._io:is_eof() do
    self.obs[i + 1] = Observation.PackedObsContentDepA(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Header of a GPS observation message
-- 
-- Pseudorange and carrier phase observation for a satellite being
-- tracked.

-- 
-- Deprecated.
Observation.MsgEphemerisDepB = class.class(KaitaiStruct)

function Observation.MsgEphemerisDepB:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisDepB:_read()
  self.tgd = self._io:read_f8le()
  self.c_rs = self._io:read_f8le()
  self.c_rc = self._io:read_f8le()
  self.c_uc = self._io:read_f8le()
  self.c_us = self._io:read_f8le()
  self.c_ic = self._io:read_f8le()
  self.c_is = self._io:read_f8le()
  self.dn = self._io:read_f8le()
  self.m0 = self._io:read_f8le()
  self.ecc = self._io:read_f8le()
  self.sqrta = self._io:read_f8le()
  self.omega0 = self._io:read_f8le()
  self.omegadot = self._io:read_f8le()
  self.w = self._io:read_f8le()
  self.inc = self._io:read_f8le()
  self.inc_dot = self._io:read_f8le()
  self.af0 = self._io:read_f8le()
  self.af1 = self._io:read_f8le()
  self.af2 = self._io:read_f8le()
  self.toe_tow = self._io:read_f8le()
  self.toe_wn = self._io:read_u2le()
  self.toc_tow = self._io:read_f8le()
  self.toc_wn = self._io:read_u2le()
  self.valid = self._io:read_u1()
  self.healthy = self._io:read_u1()
  self.prn = self._io:read_u1()
  self.iode = self._io:read_u1()
end

-- 
-- Group delay differential between L1 and L2
-- 
-- Amplitude of the sine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the sine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the cosine harmonic correction term to the angle of
-- inclination
-- 
-- Amplitude of the sine harmonic correction term to the angle of
-- inclination
-- 
-- Mean motion difference
-- 
-- Mean anomaly at reference time
-- 
-- Eccentricity of satellite orbit
-- 
-- Square root of the semi-major axis of orbit
-- 
-- Longitude of ascending node of orbit plane at weekly epoch
-- 
-- Rate of right ascension
-- 
-- Argument of perigee
-- 
-- Inclination
-- 
-- Inclination first derivative
-- 
-- Polynomial clock correction coefficient (clock bias)
-- 
-- Polynomial clock correction coefficient (clock drift)
-- 
-- Polynomial clock correction coefficient (rate of clock drift)
-- 
-- Time of week
-- 
-- Week number
-- 
-- Clock reference time of week
-- 
-- Clock reference week number
-- 
-- Is valid?
-- 
-- Satellite is healthy?
-- 
-- PRN being tracked
-- 
-- Issue of ephemeris data

-- 
-- The GPS observations message reports all the raw pseudorange and carrier
-- phase observations for the satellites being tracked by the device.
-- Carrier phase observation here is represented as a 40-bit fixed point
-- number with Q32.8 layout (i.e. 32-bits of whole cycles and 8-bits of
-- fractional cycles). The observations are be interoperable with 3rd party
-- receivers and conform with typical RTCMv3 GNSS observations.
Observation.MsgObs = class.class(KaitaiStruct)

function Observation.MsgObs:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgObs:_read()
  self.header = Observation.ObservationHeader(self._io, self, self._root)
  self.obs = {}
  local i = 0
  while not self._io:is_eof() do
    self.obs[i + 1] = Observation.PackedObsContent(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Header of a GPS observation message
-- 
-- Pseudorange and carrier phase observation for a satellite being
-- tracked.

-- 
-- Doppler measurement in Hz represented as a 24-bit fixed point number
-- with Q16.8 layout, i.e. 16-bits of whole doppler and 8-bits of
-- fractional doppler. This doppler is defined as positive for approaching
-- satellites.
Observation.Doppler = class.class(KaitaiStruct)

function Observation.Doppler:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.Doppler:_read()
  self.i = self._io:read_s2le()
  self.f = self._io:read_u1()
end

-- 
-- Doppler whole Hz
-- 
-- Doppler fractional part

-- 
-- Deprecated.
Observation.MsgAlmanacGloDep = class.class(KaitaiStruct)

function Observation.MsgAlmanacGloDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgAlmanacGloDep:_read()
  self.common = Observation.AlmanacCommonContentDep(self._io, self, self._root)
  self.lambda_na = self._io:read_f8le()
  self.t_lambda_na = self._io:read_f8le()
  self.i = self._io:read_f8le()
  self.t = self._io:read_f8le()
  self.t_dot = self._io:read_f8le()
  self.epsilon = self._io:read_f8le()
  self.omega = self._io:read_f8le()
end

-- 
-- Values common for all almanac types
-- 
-- Longitude of the first ascending node of the orbit in PZ-90.02
-- coordinate system
-- 
-- Time of the first ascending node passage
-- 
-- Value of inclination at instant of t_lambda
-- 
-- Value of Draconian period at instant of t_lambda
-- 
-- Rate of change of the Draconian period
-- 
-- Eccentricity at instant of t_lambda
-- 
-- Argument of perigee at instant of t_lambda

-- 
-- Deprecated.
Observation.MsgAlmanacGpsDep = class.class(KaitaiStruct)

function Observation.MsgAlmanacGpsDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgAlmanacGpsDep:_read()
  self.common = Observation.AlmanacCommonContentDep(self._io, self, self._root)
  self.m0 = self._io:read_f8le()
  self.ecc = self._io:read_f8le()
  self.sqrta = self._io:read_f8le()
  self.omega0 = self._io:read_f8le()
  self.omegadot = self._io:read_f8le()
  self.w = self._io:read_f8le()
  self.inc = self._io:read_f8le()
  self.af0 = self._io:read_f8le()
  self.af1 = self._io:read_f8le()
end

-- 
-- Values common for all almanac types
-- 
-- Mean anomaly at reference time
-- 
-- Eccentricity of satellite orbit
-- 
-- Square root of the semi-major axis of orbit
-- 
-- Longitude of ascending node of orbit plane at weekly epoch
-- 
-- Rate of right ascension
-- 
-- Argument of perigee
-- 
-- Inclination
-- 
-- Polynomial clock correction coefficient (clock bias)
-- 
-- Polynomial clock correction coefficient (clock drift)

-- 
-- Satellite azimuth and elevation.
Observation.SvAzEl = class.class(KaitaiStruct)

function Observation.SvAzEl:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.SvAzEl:_read()
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.az = self._io:read_u1()
  self.el = self._io:read_s1()
end

-- 
-- GNSS signal identifier
-- 
-- Azimuth angle (range 0..179)
-- 
-- Elevation angle (range -90..90)

-- 
-- The GLONASS L1/L2 Code-Phase biases allows to perform GPS+GLONASS
-- integer ambiguity resolution for baselines with mixed receiver types
-- (e.g. receiver of different manufacturers).
Observation.MsgGloBiases = class.class(KaitaiStruct)

function Observation.MsgGloBiases:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgGloBiases:_read()
  self.mask = self._io:read_u1()
  self.l1ca_bias = self._io:read_s2le()
  self.l1p_bias = self._io:read_s2le()
  self.l2ca_bias = self._io:read_s2le()
  self.l2p_bias = self._io:read_s2le()
end

-- 
-- GLONASS FDMA signals mask
-- 
-- GLONASS L1 C/A Code-Phase Bias
-- 
-- GLONASS L1 P Code-Phase Bias
-- 
-- GLONASS L2 C/A Code-Phase Bias
-- 
-- GLONASS L2 P Code-Phase Bias

-- 
-- Deprecated.
Observation.MsgEphemerisSbasDepB = class.class(KaitaiStruct)

function Observation.MsgEphemerisSbasDepB:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisSbasDepB:_read()
  self.common = Observation.EphemerisCommonContentDepB(self._io, self, self._root)
  self.pos = {}
  for i = 0, 3 - 1 do
    self.pos[i + 1] = self._io:read_f8le()
  end
  self.vel = {}
  for i = 0, 3 - 1 do
    self.vel[i + 1] = self._io:read_f8le()
  end
  self.acc = {}
  for i = 0, 3 - 1 do
    self.acc[i + 1] = self._io:read_f8le()
  end
  self.a_gf0 = self._io:read_f8le()
  self.a_gf1 = self._io:read_f8le()
end

-- 
-- Values common for all ephemeris types
-- 
-- Position of the GEO at time toe
-- 
-- Velocity of the GEO at time toe
-- 
-- Acceleration of the GEO at time toe
-- 
-- Time offset of the GEO clock w.r.t. SBAS Network Time
-- 
-- Drift of the GEO clock w.r.t. SBAS Network Time

-- 
-- Deprecated.
Observation.MsgEphemerisGpsDepE = class.class(KaitaiStruct)

function Observation.MsgEphemerisGpsDepE:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisGpsDepE:_read()
  self.common = Observation.EphemerisCommonContentDepA(self._io, self, self._root)
  self.tgd = self._io:read_f8le()
  self.c_rs = self._io:read_f8le()
  self.c_rc = self._io:read_f8le()
  self.c_uc = self._io:read_f8le()
  self.c_us = self._io:read_f8le()
  self.c_ic = self._io:read_f8le()
  self.c_is = self._io:read_f8le()
  self.dn = self._io:read_f8le()
  self.m0 = self._io:read_f8le()
  self.ecc = self._io:read_f8le()
  self.sqrta = self._io:read_f8le()
  self.omega0 = self._io:read_f8le()
  self.omegadot = self._io:read_f8le()
  self.w = self._io:read_f8le()
  self.inc = self._io:read_f8le()
  self.inc_dot = self._io:read_f8le()
  self.af0 = self._io:read_f8le()
  self.af1 = self._io:read_f8le()
  self.af2 = self._io:read_f8le()
  self.toc = Gnss.GpsTimeDep(self._io, self, self._root)
  self.iode = self._io:read_u1()
  self.iodc = self._io:read_u2le()
end

-- 
-- Values common for all ephemeris types
-- 
-- Group delay differential between L1 and L2
-- 
-- Amplitude of the sine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the sine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the cosine harmonic correction term to the angle of
-- inclination
-- 
-- Amplitude of the sine harmonic correction term to the angle of
-- inclination
-- 
-- Mean motion difference
-- 
-- Mean anomaly at reference time
-- 
-- Eccentricity of satellite orbit
-- 
-- Square root of the semi-major axis of orbit
-- 
-- Longitude of ascending node of orbit plane at weekly epoch
-- 
-- Rate of right ascension
-- 
-- Argument of perigee
-- 
-- Inclination
-- 
-- Inclination first derivative
-- 
-- Polynomial clock correction coefficient (clock bias)
-- 
-- Polynomial clock correction coefficient (clock drift)
-- 
-- Polynomial clock correction coefficient (rate of clock drift)
-- 
-- Clock reference
-- 
-- Issue of ephemeris data
-- 
-- Issue of clock data

-- 
-- Bit masks of signal capabilities for each GNSS satellite PRN.
-- Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
Observation.MsgGnssCapb = class.class(KaitaiStruct)

function Observation.MsgGnssCapb:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgGnssCapb:_read()
  self.t_nmct = Gnss.GpsTimeSec(self._io, self, self._root)
  self.gc = Observation.GnssCapb(self._io, self, self._root)
end

-- 
-- Navigation Message Correction Table Validity Time
-- 
-- GNSS capabilities masks

-- 
-- The almanac message returns a set of satellite orbit parameters. Almanac
-- data is not very precise and is considered valid for up to several
-- months. Please see the Navstar GPS Space Segment/Navigation user
-- interfaces (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more
-- details.
Observation.MsgAlmanacGps = class.class(KaitaiStruct)

function Observation.MsgAlmanacGps:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgAlmanacGps:_read()
  self.common = Observation.AlmanacCommonContent(self._io, self, self._root)
  self.m0 = self._io:read_f8le()
  self.ecc = self._io:read_f8le()
  self.sqrta = self._io:read_f8le()
  self.omega0 = self._io:read_f8le()
  self.omegadot = self._io:read_f8le()
  self.w = self._io:read_f8le()
  self.inc = self._io:read_f8le()
  self.af0 = self._io:read_f8le()
  self.af1 = self._io:read_f8le()
end

-- 
-- Values common for all almanac types
-- 
-- Mean anomaly at reference time
-- 
-- Eccentricity of satellite orbit
-- 
-- Square root of the semi-major axis of orbit
-- 
-- Longitude of ascending node of orbit plane at weekly epoch
-- 
-- Rate of right ascension
-- 
-- Argument of perigee
-- 
-- Inclination
-- 
-- Polynomial clock correction coefficient (clock bias)
-- 
-- Polynomial clock correction coefficient (clock drift)

-- 
-- The ephemeris message returns a set of satellite orbit parameters that
-- is used to calculate QZSS satellite position, velocity, and clock
-- offset.
Observation.MsgEphemerisQzss = class.class(KaitaiStruct)

function Observation.MsgEphemerisQzss:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisQzss:_read()
  self.common = Observation.EphemerisCommonContent(self._io, self, self._root)
  self.tgd = self._io:read_f4le()
  self.c_rs = self._io:read_f4le()
  self.c_rc = self._io:read_f4le()
  self.c_uc = self._io:read_f4le()
  self.c_us = self._io:read_f4le()
  self.c_ic = self._io:read_f4le()
  self.c_is = self._io:read_f4le()
  self.dn = self._io:read_f8le()
  self.m0 = self._io:read_f8le()
  self.ecc = self._io:read_f8le()
  self.sqrta = self._io:read_f8le()
  self.omega0 = self._io:read_f8le()
  self.omegadot = self._io:read_f8le()
  self.w = self._io:read_f8le()
  self.inc = self._io:read_f8le()
  self.inc_dot = self._io:read_f8le()
  self.af0 = self._io:read_f4le()
  self.af1 = self._io:read_f4le()
  self.af2 = self._io:read_f4le()
  self.toc = Gnss.GpsTimeSec(self._io, self, self._root)
  self.iode = self._io:read_u1()
  self.iodc = self._io:read_u2le()
end

-- 
-- Values common for all ephemeris types
-- 
-- Group delay differential between L1 and L2
-- 
-- Amplitude of the sine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the sine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the cosine harmonic correction term to the angle of
-- inclination
-- 
-- Amplitude of the sine harmonic correction term to the angle of
-- inclination
-- 
-- Mean motion difference
-- 
-- Mean anomaly at reference time
-- 
-- Eccentricity of satellite orbit
-- 
-- Square root of the semi-major axis of orbit
-- 
-- Longitude of ascending node of orbit plane at weekly epoch
-- 
-- Rate of right ascension
-- 
-- Argument of perigee
-- 
-- Inclination
-- 
-- Inclination first derivative
-- 
-- Polynomial clock correction coefficient (clock bias)
-- 
-- Polynomial clock correction coefficient (clock drift)
-- 
-- Polynomial clock correction coefficient (rate of clock drift)
-- 
-- Clock reference
-- 
-- Issue of ephemeris data
-- 
-- Issue of clock data

-- 
-- Deprecated.
Observation.MsgGroupDelayDepA = class.class(KaitaiStruct)

function Observation.MsgGroupDelayDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgGroupDelayDepA:_read()
  self.t_op = Gnss.GpsTimeDep(self._io, self, self._root)
  self.prn = self._io:read_u1()
  self.valid = self._io:read_u1()
  self.tgd = self._io:read_s2le()
  self.isc_l1ca = self._io:read_s2le()
  self.isc_l2c = self._io:read_s2le()
end

-- 
-- Data Predict Time of Week
-- 
-- Satellite number
-- 
-- bit-field indicating validity of the values, LSB indicating tgd
-- validity etc. 1 = value is valid, 0 = value is not valid.

-- 
-- Deprecated.
Observation.MsgEphemerisDepC = class.class(KaitaiStruct)

function Observation.MsgEphemerisDepC:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisDepC:_read()
  self.tgd = self._io:read_f8le()
  self.c_rs = self._io:read_f8le()
  self.c_rc = self._io:read_f8le()
  self.c_uc = self._io:read_f8le()
  self.c_us = self._io:read_f8le()
  self.c_ic = self._io:read_f8le()
  self.c_is = self._io:read_f8le()
  self.dn = self._io:read_f8le()
  self.m0 = self._io:read_f8le()
  self.ecc = self._io:read_f8le()
  self.sqrta = self._io:read_f8le()
  self.omega0 = self._io:read_f8le()
  self.omegadot = self._io:read_f8le()
  self.w = self._io:read_f8le()
  self.inc = self._io:read_f8le()
  self.inc_dot = self._io:read_f8le()
  self.af0 = self._io:read_f8le()
  self.af1 = self._io:read_f8le()
  self.af2 = self._io:read_f8le()
  self.toe_tow = self._io:read_f8le()
  self.toe_wn = self._io:read_u2le()
  self.toc_tow = self._io:read_f8le()
  self.toc_wn = self._io:read_u2le()
  self.valid = self._io:read_u1()
  self.healthy = self._io:read_u1()
  self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
  self.iode = self._io:read_u1()
  self.iodc = self._io:read_u2le()
  self.reserved = self._io:read_u4le()
end

-- 
-- Group delay differential between L1 and L2
-- 
-- Amplitude of the sine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the sine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the cosine harmonic correction term to the angle of
-- inclination
-- 
-- Amplitude of the sine harmonic correction term to the angle of
-- inclination
-- 
-- Mean motion difference
-- 
-- Mean anomaly at reference time
-- 
-- Eccentricity of satellite orbit
-- 
-- Square root of the semi-major axis of orbit
-- 
-- Longitude of ascending node of orbit plane at weekly epoch
-- 
-- Rate of right ascension
-- 
-- Argument of perigee
-- 
-- Inclination
-- 
-- Inclination first derivative
-- 
-- Polynomial clock correction coefficient (clock bias)
-- 
-- Polynomial clock correction coefficient (clock drift)
-- 
-- Polynomial clock correction coefficient (rate of clock drift)
-- 
-- Time of week
-- 
-- Week number
-- 
-- Clock reference time of week
-- 
-- Clock reference week number
-- 
-- Is valid?
-- 
-- Satellite is healthy?
-- 
-- GNSS signal identifier
-- 
-- Issue of ephemeris data
-- 
-- Issue of clock data
-- 
-- Reserved field

-- 
-- Carrier phase measurement in cycles represented as a 40-bit fixed point
-- number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
-- fractional cycles. This has the opposite sign convention than a typical
-- GPS receiver and the phase has the opposite sign as the pseudorange.
Observation.CarrierPhaseDepA = class.class(KaitaiStruct)

function Observation.CarrierPhaseDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.CarrierPhaseDepA:_read()
  self.i = self._io:read_s4le()
  self.f = self._io:read_u1()
end

-- 
-- Carrier phase whole cycles
-- 
-- Carrier phase fractional part

-- 
-- The ephemeris message returns a set of satellite orbit parameters that
-- is used to calculate Galileo satellite position, velocity, and clock
-- offset. Please see the Signal In Space ICD OS SIS ICD, Issue 1.3,
-- December 2016 for more details.
Observation.MsgEphemerisGal = class.class(KaitaiStruct)

function Observation.MsgEphemerisGal:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisGal:_read()
  self.common = Observation.EphemerisCommonContent(self._io, self, self._root)
  self.bgd_e1e5a = self._io:read_f4le()
  self.bgd_e1e5b = self._io:read_f4le()
  self.c_rs = self._io:read_f4le()
  self.c_rc = self._io:read_f4le()
  self.c_uc = self._io:read_f4le()
  self.c_us = self._io:read_f4le()
  self.c_ic = self._io:read_f4le()
  self.c_is = self._io:read_f4le()
  self.dn = self._io:read_f8le()
  self.m0 = self._io:read_f8le()
  self.ecc = self._io:read_f8le()
  self.sqrta = self._io:read_f8le()
  self.omega0 = self._io:read_f8le()
  self.omegadot = self._io:read_f8le()
  self.w = self._io:read_f8le()
  self.inc = self._io:read_f8le()
  self.inc_dot = self._io:read_f8le()
  self.af0 = self._io:read_f8le()
  self.af1 = self._io:read_f8le()
  self.af2 = self._io:read_f4le()
  self.toc = Gnss.GpsTimeSec(self._io, self, self._root)
  self.iode = self._io:read_u2le()
  self.iodc = self._io:read_u2le()
  self.source = self._io:read_u1()
end

-- 
-- Values common for all ephemeris types
-- 
-- E1-E5a Broadcast Group Delay
-- 
-- E1-E5b Broadcast Group Delay
-- 
-- Amplitude of the sine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the sine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the cosine harmonic correction term to the angle of
-- inclination
-- 
-- Amplitude of the sine harmonic correction term to the angle of
-- inclination
-- 
-- Mean motion difference
-- 
-- Mean anomaly at reference time
-- 
-- Eccentricity of satellite orbit
-- 
-- Square root of the semi-major axis of orbit
-- 
-- Longitude of ascending node of orbit plane at weekly epoch
-- 
-- Rate of right ascension
-- 
-- Argument of perigee
-- 
-- Inclination
-- 
-- Inclination first derivative
-- 
-- Polynomial clock correction coefficient (clock bias)
-- 
-- Polynomial clock correction coefficient (clock drift)
-- 
-- Polynomial clock correction coefficient (rate of clock drift)
-- 
-- Clock reference
-- 
-- Issue of data (IODnav)
-- 
-- Issue of data (IODnav). Always equal to iode
-- 
-- 0=I/NAV, 1=F/NAV

-- 
-- Pseudorange and carrier phase network corrections for a satellite
-- signal.
Observation.PackedOsrContent = class.class(KaitaiStruct)

function Observation.PackedOsrContent:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.PackedOsrContent:_read()
  self.p = self._io:read_u4le()
  self.l = Gnss.CarrierPhase(self._io, self, self._root)
  self.lock = self._io:read_u1()
  self.flags = self._io:read_u1()
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.iono_std = self._io:read_u2le()
  self.tropo_std = self._io:read_u2le()
  self.range_std = self._io:read_u2le()
end

-- 
-- Pseudorange observation
-- 
-- Carrier phase observation with typical sign convention.
-- 
-- Lock timer. This value gives an indication of the time for which a
-- signal has maintained continuous phase lock. Whenever a signal has
-- lost and regained lock, this value is reset to zero. It is encoded
-- according to DF402 from the RTCM 10403.2 Amendment 2 specification.
-- Valid values range from 0 to 15 and the most significant nibble is
-- reserved for future use.
-- 
-- Correction flags.
-- 
-- GNSS signal identifier (16 bit)
-- 
-- Slant ionospheric correction standard deviation
-- 
-- Slant tropospheric correction standard deviation
-- 
-- Orbit/clock/bias correction projected on range standard deviation

-- 
-- The ephemeris message returns a set of satellite orbit parameters that
-- is used to calculate BDS satellite position, velocity, and clock offset.
-- Please see the BeiDou Navigation Satellite System SIS-ICD Version 2.1,
-- Table 5-9 for more details.
Observation.MsgEphemerisBds = class.class(KaitaiStruct)

function Observation.MsgEphemerisBds:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisBds:_read()
  self.common = Observation.EphemerisCommonContent(self._io, self, self._root)
  self.tgd1 = self._io:read_f4le()
  self.tgd2 = self._io:read_f4le()
  self.c_rs = self._io:read_f4le()
  self.c_rc = self._io:read_f4le()
  self.c_uc = self._io:read_f4le()
  self.c_us = self._io:read_f4le()
  self.c_ic = self._io:read_f4le()
  self.c_is = self._io:read_f4le()
  self.dn = self._io:read_f8le()
  self.m0 = self._io:read_f8le()
  self.ecc = self._io:read_f8le()
  self.sqrta = self._io:read_f8le()
  self.omega0 = self._io:read_f8le()
  self.omegadot = self._io:read_f8le()
  self.w = self._io:read_f8le()
  self.inc = self._io:read_f8le()
  self.inc_dot = self._io:read_f8le()
  self.af0 = self._io:read_f8le()
  self.af1 = self._io:read_f4le()
  self.af2 = self._io:read_f4le()
  self.toc = Gnss.GpsTimeSec(self._io, self, self._root)
  self.iode = self._io:read_u1()
  self.iodc = self._io:read_u2le()
end

-- 
-- Values common for all ephemeris types
-- 
-- Group delay differential for B1
-- 
-- Group delay differential for B2
-- 
-- Amplitude of the sine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the sine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the cosine harmonic correction term to the angle of
-- inclination
-- 
-- Amplitude of the sine harmonic correction term to the angle of
-- inclination
-- 
-- Mean motion difference
-- 
-- Mean anomaly at reference time
-- 
-- Eccentricity of satellite orbit
-- 
-- Square root of the semi-major axis of orbit
-- 
-- Longitude of ascending node of orbit plane at weekly epoch
-- 
-- Rate of right ascension
-- 
-- Argument of perigee
-- 
-- Inclination
-- 
-- Inclination first derivative
-- 
-- Polynomial clock correction coefficient (clock bias)
-- 
-- Polynomial clock correction coefficient (clock drift)
-- 
-- Polynomial clock correction coefficient (rate of clock drift)
-- 
-- Clock reference
-- 
-- Issue of ephemeris data
-- Calculated from the navigation data parameter t_oe per RTCM/CSNO
-- recommendation: IODE = mod (t_oe / 720, 240)
-- 
-- Issue of clock data
-- Calculated from the navigation data parameter t_oe per RTCM/CSNO
-- recommendation: IODE = mod (t_oc / 720, 240)

-- 
-- Deprecated.
Observation.MsgEphemerisGpsDepF = class.class(KaitaiStruct)

function Observation.MsgEphemerisGpsDepF:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisGpsDepF:_read()
  self.common = Observation.EphemerisCommonContentDepB(self._io, self, self._root)
  self.tgd = self._io:read_f8le()
  self.c_rs = self._io:read_f8le()
  self.c_rc = self._io:read_f8le()
  self.c_uc = self._io:read_f8le()
  self.c_us = self._io:read_f8le()
  self.c_ic = self._io:read_f8le()
  self.c_is = self._io:read_f8le()
  self.dn = self._io:read_f8le()
  self.m0 = self._io:read_f8le()
  self.ecc = self._io:read_f8le()
  self.sqrta = self._io:read_f8le()
  self.omega0 = self._io:read_f8le()
  self.omegadot = self._io:read_f8le()
  self.w = self._io:read_f8le()
  self.inc = self._io:read_f8le()
  self.inc_dot = self._io:read_f8le()
  self.af0 = self._io:read_f8le()
  self.af1 = self._io:read_f8le()
  self.af2 = self._io:read_f8le()
  self.toc = Gnss.GpsTimeSec(self._io, self, self._root)
  self.iode = self._io:read_u1()
  self.iodc = self._io:read_u2le()
end

-- 
-- Values common for all ephemeris types
-- 
-- Group delay differential between L1 and L2
-- 
-- Amplitude of the sine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the sine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the cosine harmonic correction term to the angle of
-- inclination
-- 
-- Amplitude of the sine harmonic correction term to the angle of
-- inclination
-- 
-- Mean motion difference
-- 
-- Mean anomaly at reference time
-- 
-- Eccentricity of satellite orbit
-- 
-- Square root of the semi-major axis of orbit
-- 
-- Longitude of ascending node of orbit plane at weekly epoch
-- 
-- Rate of right ascension
-- 
-- Argument of perigee
-- 
-- Inclination
-- 
-- Inclination first derivative
-- 
-- Polynomial clock correction coefficient (clock bias)
-- 
-- Polynomial clock correction coefficient (clock drift)
-- 
-- Polynomial clock correction coefficient (rate of clock drift)
-- 
-- Clock reference
-- 
-- Issue of ephemeris data
-- 
-- Issue of clock data

-- 
-- Header of a GNSS observation message.
Observation.ObservationHeader = class.class(KaitaiStruct)

function Observation.ObservationHeader:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.ObservationHeader:_read()
  self.t = Gnss.GpsTime(self._io, self, self._root)
  self.n_obs = self._io:read_u1()
end

-- 
-- GNSS time of this observation
-- 
-- Total number of observations. First nibble is the size of the
-- sequence (n), second nibble is the zero-indexed counter (ith packet
-- of n)

-- 
-- Deprecated.
Observation.MsgEphemerisSbasDepA = class.class(KaitaiStruct)

function Observation.MsgEphemerisSbasDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisSbasDepA:_read()
  self.common = Observation.EphemerisCommonContentDepA(self._io, self, self._root)
  self.pos = {}
  for i = 0, 3 - 1 do
    self.pos[i + 1] = self._io:read_f8le()
  end
  self.vel = {}
  for i = 0, 3 - 1 do
    self.vel[i + 1] = self._io:read_f8le()
  end
  self.acc = {}
  for i = 0, 3 - 1 do
    self.acc[i + 1] = self._io:read_f8le()
  end
  self.a_gf0 = self._io:read_f8le()
  self.a_gf1 = self._io:read_f8le()
end

-- 
-- Values common for all ephemeris types
-- 
-- Position of the GEO at time toe
-- 
-- Velocity of the GEO at time toe
-- 
-- Acceleration of the GEO at time toe
-- 
-- Time offset of the GEO clock w.r.t. SBAS Network Time
-- 
-- Drift of the GEO clock w.r.t. SBAS Network Time

-- 
-- Pseudorange and carrier phase observation for a satellite being tracked.
-- The observations are interoperable with 3rd party receivers and conform
-- with typical RTCM 3.1 message GPS/GLO observations.
-- 
-- Carrier phase observations are not guaranteed to be aligned to the RINEX
-- 3 or RTCM 3.3 MSM reference signal and no 1/4 cycle adjustments are
-- currently performed.
Observation.PackedObsContent = class.class(KaitaiStruct)

function Observation.PackedObsContent:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.PackedObsContent:_read()
  self.p = self._io:read_u4le()
  self.l = Gnss.CarrierPhase(self._io, self, self._root)
  self.d = Observation.Doppler(self._io, self, self._root)
  self.cn0 = self._io:read_u1()
  self.lock = self._io:read_u1()
  self.flags = self._io:read_u1()
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
end

-- 
-- Pseudorange observation
-- 
-- Carrier phase observation with typical sign convention.
-- 
-- Doppler observation with typical sign convention.
-- 
-- Carrier-to-Noise density.  Zero implies invalid cn0.
-- 
-- Lock timer. This value gives an indication of the time for which a
-- signal has maintained continuous phase lock. Whenever a signal has
-- lost and regained lock, this value is reset to zero. It is encoded
-- according to DF402 from the RTCM 10403.2 Amendment 2 specification.
-- Valid values range from 0 to 15 and the most significant nibble is
-- reserved for future use.
-- 
-- Measurement status flags. A bit field of flags providing the status
-- of this observation.  If this field is 0 it means only the Cn0
-- estimate for the signal is valid.
-- 
-- GNSS signal identifier (16 bit)

-- 
-- The base station position message is the position reported by the base
-- station itself in absolute Earth Centered Earth Fixed coordinates. It is
-- used for pseudo-absolute RTK positioning, and is required to be a high-
-- accuracy surveyed location of the base station. Any error here will
-- result in an error in the pseudo-absolute position output.
Observation.MsgBasePosEcef = class.class(KaitaiStruct)

function Observation.MsgBasePosEcef:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgBasePosEcef:_read()
  self.x = self._io:read_f8le()
  self.y = self._io:read_f8le()
  self.z = self._io:read_f8le()
end

-- 
-- ECEF X coordinate
-- 
-- ECEF Y coordinate
-- 
-- ECEF Z coordinate

-- 
-- Deprecated.
Observation.MsgEphemerisGloDepA = class.class(KaitaiStruct)

function Observation.MsgEphemerisGloDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisGloDepA:_read()
  self.common = Observation.EphemerisCommonContentDepA(self._io, self, self._root)
  self.gamma = self._io:read_f8le()
  self.tau = self._io:read_f8le()
  self.pos = {}
  for i = 0, 3 - 1 do
    self.pos[i + 1] = self._io:read_f8le()
  end
  self.vel = {}
  for i = 0, 3 - 1 do
    self.vel[i + 1] = self._io:read_f8le()
  end
  self.acc = {}
  for i = 0, 3 - 1 do
    self.acc[i + 1] = self._io:read_f8le()
  end
end

-- 
-- Values common for all ephemeris types
-- 
-- Relative deviation of predicted carrier frequency from nominal
-- 
-- Correction to the SV time
-- 
-- Position of the SV at tb in PZ-90.02 coordinates system
-- 
-- Velocity vector of the SV at tb in PZ-90.02 coordinates system
-- 
-- Acceleration vector of the SV at tb in PZ-90.02 coordinates sys

-- 
-- Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
Observation.MsgGroupDelay = class.class(KaitaiStruct)

function Observation.MsgGroupDelay:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgGroupDelay:_read()
  self.t_op = Gnss.GpsTimeSec(self._io, self, self._root)
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.valid = self._io:read_u1()
  self.tgd = self._io:read_s2le()
  self.isc_l1ca = self._io:read_s2le()
  self.isc_l2c = self._io:read_s2le()
end

-- 
-- Data Predict Time of Week
-- 
-- GNSS signal identifier
-- 
-- bit-field indicating validity of the values, LSB indicating tgd
-- validity etc. 1 = value is valid, 0 = value is not valid.

-- 
-- The almanac message returns a set of satellite orbit parameters. Almanac
-- data is not very precise and is considered valid for up to several
-- months. Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate
-- information and almanac" for details.
Observation.MsgAlmanacGlo = class.class(KaitaiStruct)

function Observation.MsgAlmanacGlo:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgAlmanacGlo:_read()
  self.common = Observation.AlmanacCommonContent(self._io, self, self._root)
  self.lambda_na = self._io:read_f8le()
  self.t_lambda_na = self._io:read_f8le()
  self.i = self._io:read_f8le()
  self.t = self._io:read_f8le()
  self.t_dot = self._io:read_f8le()
  self.epsilon = self._io:read_f8le()
  self.omega = self._io:read_f8le()
end

-- 
-- Values common for all almanac types
-- 
-- Longitude of the first ascending node of the orbit in PZ-90.02
-- coordinate system
-- 
-- Time of the first ascending node passage
-- 
-- Value of inclination at instant of t_lambda
-- 
-- Value of Draconian period at instant of t_lambda
-- 
-- Rate of change of the Draconian period
-- 
-- Eccentricity at instant of t_lambda
-- 
-- Argument of perigee at instant of t_lambda

-- 
-- Deprecated.
Observation.MsgEphemerisGalDepA = class.class(KaitaiStruct)

function Observation.MsgEphemerisGalDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisGalDepA:_read()
  self.common = Observation.EphemerisCommonContent(self._io, self, self._root)
  self.bgd_e1e5a = self._io:read_f4le()
  self.bgd_e1e5b = self._io:read_f4le()
  self.c_rs = self._io:read_f4le()
  self.c_rc = self._io:read_f4le()
  self.c_uc = self._io:read_f4le()
  self.c_us = self._io:read_f4le()
  self.c_ic = self._io:read_f4le()
  self.c_is = self._io:read_f4le()
  self.dn = self._io:read_f8le()
  self.m0 = self._io:read_f8le()
  self.ecc = self._io:read_f8le()
  self.sqrta = self._io:read_f8le()
  self.omega0 = self._io:read_f8le()
  self.omegadot = self._io:read_f8le()
  self.w = self._io:read_f8le()
  self.inc = self._io:read_f8le()
  self.inc_dot = self._io:read_f8le()
  self.af0 = self._io:read_f8le()
  self.af1 = self._io:read_f8le()
  self.af2 = self._io:read_f4le()
  self.toc = Gnss.GpsTimeSec(self._io, self, self._root)
  self.iode = self._io:read_u2le()
  self.iodc = self._io:read_u2le()
end

-- 
-- Values common for all ephemeris types
-- 
-- E1-E5a Broadcast Group Delay
-- 
-- E1-E5b Broadcast Group Delay
-- 
-- Amplitude of the sine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the sine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the cosine harmonic correction term to the angle of
-- inclination
-- 
-- Amplitude of the sine harmonic correction term to the angle of
-- inclination
-- 
-- Mean motion difference
-- 
-- Mean anomaly at reference time
-- 
-- Eccentricity of satellite orbit
-- 
-- Square root of the semi-major axis of orbit
-- 
-- Longitude of ascending node of orbit plane at weekly epoch
-- 
-- Rate of right ascension
-- 
-- Argument of perigee
-- 
-- Inclination
-- 
-- Inclination first derivative
-- 
-- Polynomial clock correction coefficient (clock bias)
-- 
-- Polynomial clock correction coefficient (clock drift)
-- 
-- Polynomial clock correction coefficient (rate of clock drift)
-- 
-- Clock reference
-- 
-- Issue of data (IODnav)
-- 
-- Issue of data (IODnav). Always equal to iode

-- 
-- Deprecated.
Observation.MsgObsDepB = class.class(KaitaiStruct)

function Observation.MsgObsDepB:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgObsDepB:_read()
  self.header = Observation.ObservationHeaderDep(self._io, self, self._root)
  self.obs = {}
  local i = 0
  while not self._io:is_eof() do
    self.obs[i + 1] = Observation.PackedObsContentDepB(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Header of a GPS observation message
-- 
-- Pseudorange and carrier phase observation for a satellite being
-- tracked.

-- 
-- Deprecated.
Observation.PackedObsContentDepA = class.class(KaitaiStruct)

function Observation.PackedObsContentDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.PackedObsContentDepA:_read()
  self.p = self._io:read_u4le()
  self.l = Observation.CarrierPhaseDepA(self._io, self, self._root)
  self.cn0 = self._io:read_u1()
  self.lock = self._io:read_u2le()
  self.prn = self._io:read_u1()
end

-- 
-- Pseudorange observation
-- 
-- Carrier phase observation with opposite sign from typical convention
-- 
-- Carrier-to-Noise density
-- 
-- Lock indicator. This value changes whenever a satellite signal has
-- lost and regained lock, indicating that the carrier phase ambiguity
-- may have changed.
-- 
-- PRN-1 identifier of the satellite signal

-- 
-- The ephemeris message returns a set of satellite orbit parameters that
-- is used to calculate GLO satellite position, velocity, and clock offset.
-- Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
-- immediate information (ephemeris parameters)" for more details.
Observation.MsgEphemerisGlo = class.class(KaitaiStruct)

function Observation.MsgEphemerisGlo:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisGlo:_read()
  self.common = Observation.EphemerisCommonContent(self._io, self, self._root)
  self.gamma = self._io:read_f4le()
  self.tau = self._io:read_f4le()
  self.d_tau = self._io:read_f4le()
  self.pos = {}
  for i = 0, 3 - 1 do
    self.pos[i + 1] = self._io:read_f8le()
  end
  self.vel = {}
  for i = 0, 3 - 1 do
    self.vel[i + 1] = self._io:read_f8le()
  end
  self.acc = {}
  for i = 0, 3 - 1 do
    self.acc[i + 1] = self._io:read_f4le()
  end
  self.fcn = self._io:read_u1()
  self.iod = self._io:read_u1()
end

-- 
-- Values common for all ephemeris types
-- 
-- Relative deviation of predicted carrier frequency from nominal
-- 
-- Correction to the SV time
-- 
-- Equipment delay between L1 and L2
-- 
-- Position of the SV at tb in PZ-90.02 coordinates system
-- 
-- Velocity vector of the SV at tb in PZ-90.02 coordinates system
-- 
-- Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
-- 
-- Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid
-- 
-- Issue of data. Equal to the 7 bits of the immediate data word t_b

-- 
-- The ionospheric parameters which allow the "L1 only" or "L2 only" user
-- to utilize the ionospheric model for computation of the ionospheric
-- delay. Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
Observation.MsgIono = class.class(KaitaiStruct)

function Observation.MsgIono:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgIono:_read()
  self.t_nmct = Gnss.GpsTimeSec(self._io, self, self._root)
  self.a0 = self._io:read_f8le()
  self.a1 = self._io:read_f8le()
  self.a2 = self._io:read_f8le()
  self.a3 = self._io:read_f8le()
  self.b0 = self._io:read_f8le()
  self.b1 = self._io:read_f8le()
  self.b2 = self._io:read_f8le()
  self.b3 = self._io:read_f8le()
end

-- 
-- Navigation Message Correction Table Validity Time

-- 
-- Deprecated.
Observation.MsgEphemerisDepD = class.class(KaitaiStruct)

function Observation.MsgEphemerisDepD:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisDepD:_read()
  self.tgd = self._io:read_f8le()
  self.c_rs = self._io:read_f8le()
  self.c_rc = self._io:read_f8le()
  self.c_uc = self._io:read_f8le()
  self.c_us = self._io:read_f8le()
  self.c_ic = self._io:read_f8le()
  self.c_is = self._io:read_f8le()
  self.dn = self._io:read_f8le()
  self.m0 = self._io:read_f8le()
  self.ecc = self._io:read_f8le()
  self.sqrta = self._io:read_f8le()
  self.omega0 = self._io:read_f8le()
  self.omegadot = self._io:read_f8le()
  self.w = self._io:read_f8le()
  self.inc = self._io:read_f8le()
  self.inc_dot = self._io:read_f8le()
  self.af0 = self._io:read_f8le()
  self.af1 = self._io:read_f8le()
  self.af2 = self._io:read_f8le()
  self.toe_tow = self._io:read_f8le()
  self.toe_wn = self._io:read_u2le()
  self.toc_tow = self._io:read_f8le()
  self.toc_wn = self._io:read_u2le()
  self.valid = self._io:read_u1()
  self.healthy = self._io:read_u1()
  self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
  self.iode = self._io:read_u1()
  self.iodc = self._io:read_u2le()
  self.reserved = self._io:read_u4le()
end

-- 
-- Group delay differential between L1 and L2
-- 
-- Amplitude of the sine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the sine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the cosine harmonic correction term to the angle of
-- inclination
-- 
-- Amplitude of the sine harmonic correction term to the angle of
-- inclination
-- 
-- Mean motion difference
-- 
-- Mean anomaly at reference time
-- 
-- Eccentricity of satellite orbit
-- 
-- Square root of the semi-major axis of orbit
-- 
-- Longitude of ascending node of orbit plane at weekly epoch
-- 
-- Rate of right ascension
-- 
-- Argument of perigee
-- 
-- Inclination
-- 
-- Inclination first derivative
-- 
-- Polynomial clock correction coefficient (clock bias)
-- 
-- Polynomial clock correction coefficient (clock drift)
-- 
-- Polynomial clock correction coefficient (rate of clock drift)
-- 
-- Time of week
-- 
-- Week number
-- 
-- Clock reference time of week
-- 
-- Clock reference week number
-- 
-- Is valid?
-- 
-- Satellite is healthy?
-- 
-- GNSS signal identifier
-- 
-- Issue of ephemeris data
-- 
-- Issue of clock data
-- 
-- Reserved field

-- 
-- The ephemeris message returns a set of satellite orbit parameters that
-- is used to calculate GPS satellite position, velocity, and clock offset.
-- Please see the Navstar GPS Space Segment/Navigation user interfaces
-- (ICD-GPS-200, Table 20-III) for more details.
Observation.MsgEphemerisGps = class.class(KaitaiStruct)

function Observation.MsgEphemerisGps:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisGps:_read()
  self.common = Observation.EphemerisCommonContent(self._io, self, self._root)
  self.tgd = self._io:read_f4le()
  self.c_rs = self._io:read_f4le()
  self.c_rc = self._io:read_f4le()
  self.c_uc = self._io:read_f4le()
  self.c_us = self._io:read_f4le()
  self.c_ic = self._io:read_f4le()
  self.c_is = self._io:read_f4le()
  self.dn = self._io:read_f8le()
  self.m0 = self._io:read_f8le()
  self.ecc = self._io:read_f8le()
  self.sqrta = self._io:read_f8le()
  self.omega0 = self._io:read_f8le()
  self.omegadot = self._io:read_f8le()
  self.w = self._io:read_f8le()
  self.inc = self._io:read_f8le()
  self.inc_dot = self._io:read_f8le()
  self.af0 = self._io:read_f4le()
  self.af1 = self._io:read_f4le()
  self.af2 = self._io:read_f4le()
  self.toc = Gnss.GpsTimeSec(self._io, self, self._root)
  self.iode = self._io:read_u1()
  self.iodc = self._io:read_u2le()
end

-- 
-- Values common for all ephemeris types
-- 
-- Group delay differential between L1 and L2
-- 
-- Amplitude of the sine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the sine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the cosine harmonic correction term to the angle of
-- inclination
-- 
-- Amplitude of the sine harmonic correction term to the angle of
-- inclination
-- 
-- Mean motion difference
-- 
-- Mean anomaly at reference time
-- 
-- Eccentricity of satellite orbit
-- 
-- Square root of the semi-major axis of orbit
-- 
-- Longitude of ascending node of orbit plane at weekly epoch
-- 
-- Rate of right ascension
-- 
-- Argument of perigee
-- 
-- Inclination
-- 
-- Inclination first derivative
-- 
-- Polynomial clock correction coefficient (clock bias)
-- 
-- Polynomial clock correction coefficient (clock drift)
-- 
-- Polynomial clock correction coefficient (rate of clock drift)
-- 
-- Clock reference
-- 
-- Issue of ephemeris data
-- 
-- Issue of clock data

-- 
-- The base station position message is the position reported by the base
-- station itself. It is used for pseudo-absolute RTK positioning, and is
-- required to be a high-accuracy surveyed location of the base station.
-- Any error here will result in an error in the pseudo-absolute position
-- output.
Observation.MsgBasePosLlh = class.class(KaitaiStruct)

function Observation.MsgBasePosLlh:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgBasePosLlh:_read()
  self.lat = self._io:read_f8le()
  self.lon = self._io:read_f8le()
  self.height = self._io:read_f8le()
end

-- 
-- Latitude
-- 
-- Longitude
-- 
-- Height

Observation.AlmanacCommonContent = class.class(KaitaiStruct)

function Observation.AlmanacCommonContent:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.AlmanacCommonContent:_read()
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.toa = Gnss.GpsTimeSec(self._io, self, self._root)
  self.ura = self._io:read_f8le()
  self.fit_interval = self._io:read_u4le()
  self.valid = self._io:read_u1()
  self.health_bits = self._io:read_u1()
end

-- 
-- GNSS signal identifier
-- 
-- Reference time of almanac
-- 
-- User Range Accuracy
-- 
-- Curve fit interval
-- 
-- Status of almanac, 1 = valid, 0 = invalid
-- 
-- Satellite health status for GPS:
--   - bits 5-7: NAV data health status. See IS-GPS-200H
--     Table 20-VII: NAV Data Health Indications.
--   - bits 0-4: Signal health status. See IS-GPS-200H
--     Table 20-VIII. Codes for Health of SV Signal
--     Components.
-- Satellite health status for GLO (see GLO ICD 5.1 table 5.1 for
-- details):
--   - bit 0: C(n), "unhealthy" flag that is transmitted within
--     non-immediate data and indicates overall constellation status
--     at the moment of almanac uploading.
--     '0' indicates malfunction of n-satellite.
--     '1' indicates that n-satellite is operational.
--   - bit 1: Bn(ln), '0' indicates the satellite is operational
--     and suitable for navigation.

-- 
-- The OSR message contains network corrections in an observation-like
-- format.
Observation.MsgOsr = class.class(KaitaiStruct)

function Observation.MsgOsr:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgOsr:_read()
  self.header = Observation.ObservationHeader(self._io, self, self._root)
  self.obs = {}
  local i = 0
  while not self._io:is_eof() do
    self.obs[i + 1] = Observation.PackedOsrContent(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Header of a GPS observation message
-- 
-- Network correction for a satellite signal.

-- 
-- The ephemeris message returns a set of satellite orbit parameters that
-- is used to calculate GLO satellite position, velocity, and clock offset.
-- Please see the GLO ICD 5.1 "Table 4.5 Characteristics of words of
-- immediate information (ephemeris parameters)" for more details.
Observation.MsgEphemerisGloDepC = class.class(KaitaiStruct)

function Observation.MsgEphemerisGloDepC:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisGloDepC:_read()
  self.common = Observation.EphemerisCommonContentDepB(self._io, self, self._root)
  self.gamma = self._io:read_f8le()
  self.tau = self._io:read_f8le()
  self.d_tau = self._io:read_f8le()
  self.pos = {}
  for i = 0, 3 - 1 do
    self.pos[i + 1] = self._io:read_f8le()
  end
  self.vel = {}
  for i = 0, 3 - 1 do
    self.vel[i + 1] = self._io:read_f8le()
  end
  self.acc = {}
  for i = 0, 3 - 1 do
    self.acc[i + 1] = self._io:read_f8le()
  end
  self.fcn = self._io:read_u1()
end

-- 
-- Values common for all ephemeris types
-- 
-- Relative deviation of predicted carrier frequency from nominal
-- 
-- Correction to the SV time
-- 
-- Equipment delay between L1 and L2
-- 
-- Position of the SV at tb in PZ-90.02 coordinates system
-- 
-- Velocity vector of the SV at tb in PZ-90.02 coordinates system
-- 
-- Acceleration vector of the SV at tb in PZ-90.02 coordinates sys
-- 
-- Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid

-- 
-- Deprecated.
Observation.MsgEphemerisGloDepB = class.class(KaitaiStruct)

function Observation.MsgEphemerisGloDepB:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisGloDepB:_read()
  self.common = Observation.EphemerisCommonContentDepB(self._io, self, self._root)
  self.gamma = self._io:read_f8le()
  self.tau = self._io:read_f8le()
  self.pos = {}
  for i = 0, 3 - 1 do
    self.pos[i + 1] = self._io:read_f8le()
  end
  self.vel = {}
  for i = 0, 3 - 1 do
    self.vel[i + 1] = self._io:read_f8le()
  end
  self.acc = {}
  for i = 0, 3 - 1 do
    self.acc[i + 1] = self._io:read_f8le()
  end
end

-- 
-- Values common for all ephemeris types
-- 
-- Relative deviation of predicted carrier frequency from nominal
-- 
-- Correction to the SV time
-- 
-- Position of the SV at tb in PZ-90.02 coordinates system
-- 
-- Velocity vector of the SV at tb in PZ-90.02 coordinates system
-- 
-- Acceleration vector of the SV at tb in PZ-90.02 coordinates sys

-- 
-- Deprecated.
Observation.MsgSvConfigurationGpsDep = class.class(KaitaiStruct)

function Observation.MsgSvConfigurationGpsDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgSvConfigurationGpsDep:_read()
  self.t_nmct = Gnss.GpsTimeSec(self._io, self, self._root)
  self.l2c_mask = self._io:read_u4le()
end

-- 
-- Navigation Message Correction Table Validity Time
-- 
-- L2C capability mask, SV32 bit being MSB, SV1 bit being LSB

Observation.MsgEphemerisSbas = class.class(KaitaiStruct)

function Observation.MsgEphemerisSbas:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisSbas:_read()
  self.common = Observation.EphemerisCommonContent(self._io, self, self._root)
  self.pos = {}
  for i = 0, 3 - 1 do
    self.pos[i + 1] = self._io:read_f8le()
  end
  self.vel = {}
  for i = 0, 3 - 1 do
    self.vel[i + 1] = self._io:read_f4le()
  end
  self.acc = {}
  for i = 0, 3 - 1 do
    self.acc[i + 1] = self._io:read_f4le()
  end
  self.a_gf0 = self._io:read_f4le()
  self.a_gf1 = self._io:read_f4le()
end

-- 
-- Values common for all ephemeris types
-- 
-- Position of the GEO at time toe
-- 
-- Velocity of the GEO at time toe
-- 
-- Acceleration of the GEO at time toe
-- 
-- Time offset of the GEO clock w.r.t. SBAS Network Time
-- 
-- Drift of the GEO clock w.r.t. SBAS Network Time

-- 
-- Pseudorange and carrier phase observation for a satellite being tracked.
-- Pseudoranges are referenced to a nominal pseudorange.
Observation.PackedObsContentDepB = class.class(KaitaiStruct)

function Observation.PackedObsContentDepB:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.PackedObsContentDepB:_read()
  self.p = self._io:read_u4le()
  self.l = Observation.CarrierPhaseDepA(self._io, self, self._root)
  self.cn0 = self._io:read_u1()
  self.lock = self._io:read_u2le()
  self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
end

-- 
-- Pseudorange observation
-- 
-- Carrier phase observation with opposite sign from typical
-- convention.
-- 
-- Carrier-to-Noise density
-- 
-- Lock indicator. This value changes whenever a satellite signal has
-- lost and regained lock, indicating that the carrier phase ambiguity
-- may have changed.
-- 
-- GNSS signal identifier

-- 
-- Deprecated.
Observation.MsgObsDepC = class.class(KaitaiStruct)

function Observation.MsgObsDepC:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgObsDepC:_read()
  self.header = Observation.ObservationHeaderDep(self._io, self, self._root)
  self.obs = {}
  local i = 0
  while not self._io:is_eof() do
    self.obs[i + 1] = Observation.PackedObsContentDepC(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Header of a GPS observation message
-- 
-- Pseudorange and carrier phase observation for a satellite being
-- tracked.

-- 
-- Deprecated.
Observation.MsgEphemerisDepA = class.class(KaitaiStruct)

function Observation.MsgEphemerisDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.MsgEphemerisDepA:_read()
  self.tgd = self._io:read_f8le()
  self.c_rs = self._io:read_f8le()
  self.c_rc = self._io:read_f8le()
  self.c_uc = self._io:read_f8le()
  self.c_us = self._io:read_f8le()
  self.c_ic = self._io:read_f8le()
  self.c_is = self._io:read_f8le()
  self.dn = self._io:read_f8le()
  self.m0 = self._io:read_f8le()
  self.ecc = self._io:read_f8le()
  self.sqrta = self._io:read_f8le()
  self.omega0 = self._io:read_f8le()
  self.omegadot = self._io:read_f8le()
  self.w = self._io:read_f8le()
  self.inc = self._io:read_f8le()
  self.inc_dot = self._io:read_f8le()
  self.af0 = self._io:read_f8le()
  self.af1 = self._io:read_f8le()
  self.af2 = self._io:read_f8le()
  self.toe_tow = self._io:read_f8le()
  self.toe_wn = self._io:read_u2le()
  self.toc_tow = self._io:read_f8le()
  self.toc_wn = self._io:read_u2le()
  self.valid = self._io:read_u1()
  self.healthy = self._io:read_u1()
  self.prn = self._io:read_u1()
end

-- 
-- Group delay differential between L1 and L2
-- 
-- Amplitude of the sine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the orbit radius
-- 
-- Amplitude of the cosine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the sine harmonic correction term to the argument of
-- latitude
-- 
-- Amplitude of the cosine harmonic correction term to the angle of
-- inclination
-- 
-- Amplitude of the sine harmonic correction term to the angle of
-- inclination
-- 
-- Mean motion difference
-- 
-- Mean anomaly at reference time
-- 
-- Eccentricity of satellite orbit
-- 
-- Square root of the semi-major axis of orbit
-- 
-- Longitude of ascending node of orbit plane at weekly epoch
-- 
-- Rate of right ascension
-- 
-- Argument of perigee
-- 
-- Inclination
-- 
-- Inclination first derivative
-- 
-- Polynomial clock correction coefficient (clock bias)
-- 
-- Polynomial clock correction coefficient (clock drift)
-- 
-- Polynomial clock correction coefficient (rate of clock drift)
-- 
-- Time of week
-- 
-- Week number
-- 
-- Clock reference time of week
-- 
-- Clock reference week number
-- 
-- Is valid?
-- 
-- Satellite is healthy?
-- 
-- PRN being tracked

Observation.EphemerisCommonContentDepB = class.class(KaitaiStruct)

function Observation.EphemerisCommonContentDepB:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Observation.EphemerisCommonContentDepB:_read()
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.toe = Gnss.GpsTimeSec(self._io, self, self._root)
  self.ura = self._io:read_f8le()
  self.fit_interval = self._io:read_u4le()
  self.valid = self._io:read_u1()
  self.health_bits = self._io:read_u1()
end

-- 
-- GNSS signal identifier (16 bit)
-- 
-- Time of Ephemerides
-- 
-- User Range Accuracy
-- 
-- Curve fit interval
-- 
-- Status of ephemeris, 1 = valid, 0 = invalid
-- 
-- Satellite health status.
-- GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
-- Others: 0 = valid, non-zero = invalid

