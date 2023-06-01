-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

Ssr = class.class(KaitaiStruct)

function Ssr:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr:_read()
end


-- 
-- Defines the grid for MSG_SSR_GRIDDED_CORRECTION messages. Also includes
-- an RLE encoded validity list.
Ssr.GridDefinitionHeaderDepA = class.class(KaitaiStruct)

function Ssr.GridDefinitionHeaderDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.GridDefinitionHeaderDepA:_read()
  self.region_size_inverse = self._io:read_u1()
  self.area_width = self._io:read_u2le()
  self.lat_nw_corner_enc = self._io:read_u2le()
  self.lon_nw_corner_enc = self._io:read_u2le()
  self.num_msgs = self._io:read_u1()
  self.seq_num = self._io:read_u1()
end

-- 
-- region_size (deg) = 10 / region_size_inverse 0 is an invalid value.
-- 
-- grid height (deg) = grid width (deg) = area_width / region_size 0 is
-- an invalid value.
-- 
-- North-West corner latitude (deg) = region_size * lat_nw_corner_enc -
-- 90
-- 
-- North-West corner longitude (deg) = region_size * lon_nw_corner_enc
-- - 180
-- 
-- Number of messages in the dataset
-- 
-- Position of this message in the dataset

-- 
-- STEC residual for the given satellite at the grid point.
Ssr.StecResidualNoStd = class.class(KaitaiStruct)

function Ssr.StecResidualNoStd:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.StecResidualNoStd:_read()
  self.sv_id = Gnss.SvId(self._io, self, self._root)
  self.residual = self._io:read_s2le()
end

-- 
-- space vehicle identifier
-- 
-- STEC residual

-- 
-- Troposphere vertical delays at the grid point.
Ssr.TroposphericDelayCorrectionNoStd = class.class(KaitaiStruct)

function Ssr.TroposphericDelayCorrectionNoStd:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.TroposphericDelayCorrectionNoStd:_read()
  self.hydro = self._io:read_s2le()
  self.wet = self._io:read_s1()
end

-- 
-- Hydrostatic vertical delay
-- 
-- Wet vertical delay

-- 
-- Deprecated.
Ssr.MsgSsrStecCorrectionDep = class.class(KaitaiStruct)

function Ssr.MsgSsrStecCorrectionDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrStecCorrectionDep:_read()
  self.header = Ssr.StecHeader(self._io, self, self._root)
  self.stec_sat_list = {}
  local i = 0
  while not self._io:is_eof() do
    self.stec_sat_list[i + 1] = Ssr.StecSatElement(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Header of a STEC polynomial coefficient message.
-- 
-- Array of STEC polynomial coefficients for each space vehicle.

-- 
-- STEC polynomial and bounds for the given satellite.
Ssr.StecSatElementIntegrity = class.class(KaitaiStruct)

function Ssr.StecSatElementIntegrity:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.StecSatElementIntegrity:_read()
  self.stec_residual = Ssr.StecResidual(self._io, self, self._root)
  self.stec_bound_mu = self._io:read_u1()
  self.stec_bound_sig = self._io:read_u1()
  self.stec_bound_mu_dot = self._io:read_u1()
  self.stec_bound_sig_dot = self._io:read_u1()
end

-- 
-- STEC residuals (mean, stddev)
-- 
-- Error Bound Mean. See Note 1.
-- 
-- Error Bound StDev. See Note 1.
-- 
-- Error Bound Mean First derivative.
-- 
-- Error Bound StDev First derivative.

-- 
-- Deprecated.
Ssr.MsgSsrOrbitClockDepA = class.class(KaitaiStruct)

function Ssr.MsgSsrOrbitClockDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrOrbitClockDepA:_read()
  self.time = Gnss.GpsTimeSec(self._io, self, self._root)
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.update_interval = self._io:read_u1()
  self.iod_ssr = self._io:read_u1()
  self.iod = self._io:read_u1()
  self.radial = self._io:read_s4le()
  self.along = self._io:read_s4le()
  self.cross = self._io:read_s4le()
  self.dot_radial = self._io:read_s4le()
  self.dot_along = self._io:read_s4le()
  self.dot_cross = self._io:read_s4le()
  self.c0 = self._io:read_s4le()
  self.c1 = self._io:read_s4le()
  self.c2 = self._io:read_s4le()
end

-- 
-- GNSS reference time of the correction
-- 
-- GNSS signal identifier (16 bit)
-- 
-- Update interval between consecutive corrections. Encoded following
-- RTCM DF391 specification.
-- 
-- IOD of the SSR correction. A change of Issue Of Data SSR is used to
-- indicate a change in the SSR generating configuration
-- 
-- Issue of broadcast ephemeris data
-- 
-- Orbit radial delta correction
-- 
-- Orbit along delta correction
-- 
-- Orbit along delta correction
-- 
-- Velocity of orbit radial delta correction
-- 
-- Velocity of orbit along delta correction
-- 
-- Velocity of orbit cross delta correction
-- 
-- C0 polynomial coefficient for correction of broadcast satellite
-- clock
-- 
-- C1 polynomial coefficient for correction of broadcast satellite
-- clock
-- 
-- C2 polynomial coefficient for correction of broadcast satellite
-- clock

Ssr.MsgSsrStecCorrection = class.class(KaitaiStruct)

function Ssr.MsgSsrStecCorrection:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrStecCorrection:_read()
  self.header = Ssr.BoundsHeader(self._io, self, self._root)
  self.ssr_iod_atmo = self._io:read_u1()
  self.tile_set_id = self._io:read_u2le()
  self.tile_id = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.stec_sat_list = {}
  local i = 0
  while not self._io:is_eof() do
    self.stec_sat_list[i + 1] = Ssr.StecSatElement(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Header of a STEC correction with bounds message.
-- 
-- IOD of the SSR atmospheric correction
-- 
-- Tile set ID
-- 
-- Tile ID
-- 
-- Number of satellites.
-- 
-- Array of STEC polynomial coefficients for each space vehicle.

-- 
-- The precise orbit and clock correction message is to be applied as a
-- delta correction to broadcast ephemeris and is an equivalent to the 1060
-- /1066 RTCM message types.
Ssr.MsgSsrOrbitClock = class.class(KaitaiStruct)

function Ssr.MsgSsrOrbitClock:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrOrbitClock:_read()
  self.time = Gnss.GpsTimeSec(self._io, self, self._root)
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.update_interval = self._io:read_u1()
  self.iod_ssr = self._io:read_u1()
  self.iod = self._io:read_u4le()
  self.radial = self._io:read_s4le()
  self.along = self._io:read_s4le()
  self.cross = self._io:read_s4le()
  self.dot_radial = self._io:read_s4le()
  self.dot_along = self._io:read_s4le()
  self.dot_cross = self._io:read_s4le()
  self.c0 = self._io:read_s4le()
  self.c1 = self._io:read_s4le()
  self.c2 = self._io:read_s4le()
end

-- 
-- GNSS reference time of the correction
-- 
-- GNSS signal identifier (16 bit)
-- 
-- Update interval between consecutive corrections. Encoded following
-- RTCM DF391 specification.
-- 
-- IOD of the SSR correction. A change of Issue Of Data SSR is used to
-- indicate a change in the SSR generating configuration
-- 
-- Issue of broadcast ephemeris data or IODCRC (Beidou)
-- 
-- Orbit radial delta correction
-- 
-- Orbit along delta correction
-- 
-- Orbit along delta correction
-- 
-- Velocity of orbit radial delta correction
-- 
-- Velocity of orbit along delta correction
-- 
-- Velocity of orbit cross delta correction
-- 
-- C0 polynomial coefficient for correction of broadcast satellite
-- clock
-- 
-- C1 polynomial coefficient for correction of broadcast satellite
-- clock
-- 
-- C2 polynomial coefficient for correction of broadcast satellite
-- clock

Ssr.BoundsHeader = class.class(KaitaiStruct)

function Ssr.BoundsHeader:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.BoundsHeader:_read()
  self.time = Gnss.GpsTimeSec(self._io, self, self._root)
  self.num_msgs = self._io:read_u1()
  self.seq_num = self._io:read_u1()
  self.update_interval = self._io:read_u1()
  self.sol_id = self._io:read_u1()
end

-- 
-- GNSS reference time of the bound
-- 
-- Number of messages in the dataset
-- 
-- Position of this message in the dataset
-- 
-- Update interval between consecutive bounds. Similar to RTCM DF391.
-- 
-- SSR Solution ID.

-- 
-- STEC residuals are per space vehicle, troposphere is not.
-- 
-- It is typically equivalent to the QZSS CLAS Sub Type 9 messages.
Ssr.MsgSsrGriddedCorrection = class.class(KaitaiStruct)

function Ssr.MsgSsrGriddedCorrection:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrGriddedCorrection:_read()
  self.header = Ssr.GriddedCorrectionHeader(self._io, self, self._root)
  self.index = self._io:read_u2le()
  self.tropo_delay_correction = Ssr.TroposphericDelayCorrection(self._io, self, self._root)
  self.stec_residuals = {}
  local i = 0
  while not self._io:is_eof() do
    self.stec_residuals[i + 1] = Ssr.StecResidual(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Header of a gridded correction message
-- 
-- Index of the grid point.
-- 
-- Wet and hydrostatic vertical delays (mean, stddev).
-- 
-- STEC residuals for each satellite (mean, stddev).

-- 
-- STEC residual (mean and standard deviation) for the given satellite at
-- the grid point.
Ssr.StecResidual = class.class(KaitaiStruct)

function Ssr.StecResidual:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.StecResidual:_read()
  self.sv_id = Gnss.SvId(self._io, self, self._root)
  self.residual = self._io:read_s2le()
  self.stddev = self._io:read_u1()
end

-- 
-- space vehicle identifier
-- 
-- STEC residual
-- 
-- Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
-- value/16) - 1) * 10

Ssr.CodePhaseBiasesSatSig = class.class(KaitaiStruct)

function Ssr.CodePhaseBiasesSatSig:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.CodePhaseBiasesSatSig:_read()
  self.sat_id = self._io:read_u1()
  self.signal_id = self._io:read_u1()
  self.code_bias_bound_mu = self._io:read_u1()
  self.code_bias_bound_sig = self._io:read_u1()
  self.phase_bias_bound_mu = self._io:read_u1()
  self.phase_bias_bound_sig = self._io:read_u1()
end

-- 
-- Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
-- or DF488 (BDS) depending on the constellation.
-- 
-- Signal and Tracking Mode Identifier. Similar to either RTCM DF380
-- (GPS), DF382 (Galileo) or DF467 (BDS) depending on the
-- constellation.
-- 
-- Code Bias Mean. Range: 0-1.275 m
-- 
-- Code Bias Standard Deviation. Range: 0-1.275 m
-- 
-- Phase Bias Mean. Range: 0-1.275 m
-- 
-- Phase Bias Standard Deviation. Range: 0-1.275 m

-- 
-- Contains phase center offset and elevation variation corrections for one
-- signal on a satellite.
Ssr.SatelliteApc = class.class(KaitaiStruct)

function Ssr.SatelliteApc:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.SatelliteApc:_read()
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.sat_info = self._io:read_u1()
  self.svn = self._io:read_u2le()
  self.pco = {}
  for i = 0, 3 - 1 do
    self.pco[i + 1] = self._io:read_s2le()
  end
  self.pcv = {}
  for i = 0, 21 - 1 do
    self.pcv[i + 1] = self._io:read_s1()
  end
end

-- 
-- GNSS signal identifier (16 bit)
-- 
-- Additional satellite information
-- 
-- Satellite Code, as defined by IGS. Typically the space vehicle
-- number.
-- 
-- Mean phase center offset, X Y and Z axes. See IGS ANTEX file format
-- description for coordinate system definition.
-- 
-- Elevation dependent phase center variations. First element is 0
-- degrees separation from the Z axis, subsequent elements represent
-- elevation variations in 1 degree increments.

-- 
-- The LPP message contains nested variable length arrays which are not
-- supported in SBP, so each grid point will be identified by the index.
Ssr.GriddedCorrectionHeader = class.class(KaitaiStruct)

function Ssr.GriddedCorrectionHeader:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.GriddedCorrectionHeader:_read()
  self.tile_set_id = self._io:read_u2le()
  self.tile_id = self._io:read_u2le()
  self.time = Gnss.GpsTimeSec(self._io, self, self._root)
  self.num_msgs = self._io:read_u2le()
  self.seq_num = self._io:read_u2le()
  self.update_interval = self._io:read_u1()
  self.iod_atmo = self._io:read_u1()
  self.tropo_quality_indicator = self._io:read_u1()
end

-- 
-- Unique identifier of the tile set this tile belongs to.
-- 
-- Unique identifier of this tile in the tile set.
-- 
-- GNSS reference time of the correction
-- 
-- Number of messages in the dataset
-- 
-- Position of this message in the dataset
-- 
-- Update interval between consecutive corrections. Encoded following
-- RTCM DF391 specification.
-- 
-- IOD of the SSR atmospheric correction
-- 
-- Quality of the troposphere data. Encoded following RTCM DF389
-- specification in units of m.

-- 
-- STEC polynomial for the given satellite.
Ssr.StecSatElement = class.class(KaitaiStruct)

function Ssr.StecSatElement:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.StecSatElement:_read()
  self.sv_id = Gnss.SvId(self._io, self, self._root)
  self.stec_quality_indicator = self._io:read_u1()
  self.stec_coeff = {}
  for i = 0, 4 - 1 do
    self.stec_coeff[i + 1] = self._io:read_s2le()
  end
end

-- 
-- Unique space vehicle identifier
-- 
-- Quality of the STEC data. Encoded following RTCM DF389 specification
-- but in units of TECU instead of m.
-- 
-- Coefficients of the STEC polynomial in the order of C00, C01, C10,
-- C11. C00 = 0.05 TECU, C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2

-- 
-- A full set of STEC information will likely span multiple SBP messages,
-- since SBP message a limited to 255 bytes.  The header is used to tie
-- multiple SBP messages into a sequence.
Ssr.StecHeaderDepA = class.class(KaitaiStruct)

function Ssr.StecHeaderDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.StecHeaderDepA:_read()
  self.time = Gnss.GpsTimeSec(self._io, self, self._root)
  self.num_msgs = self._io:read_u1()
  self.seq_num = self._io:read_u1()
  self.update_interval = self._io:read_u1()
  self.iod_atmo = self._io:read_u1()
end

-- 
-- GNSS reference time of the correction
-- 
-- Number of messages in the dataset
-- 
-- Position of this message in the dataset
-- 
-- Update interval between consecutive corrections. Encoded following
-- RTCM DF391 specification.
-- 
-- IOD of the SSR atmospheric correction

-- 
-- A full set of STEC information will likely span multiple SBP messages,
-- since SBP message a limited to 255 bytes.  The header is used to tie
-- multiple SBP messages into a sequence.
Ssr.StecHeader = class.class(KaitaiStruct)

function Ssr.StecHeader:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.StecHeader:_read()
  self.tile_set_id = self._io:read_u2le()
  self.tile_id = self._io:read_u2le()
  self.time = Gnss.GpsTimeSec(self._io, self, self._root)
  self.num_msgs = self._io:read_u1()
  self.seq_num = self._io:read_u1()
  self.update_interval = self._io:read_u1()
  self.iod_atmo = self._io:read_u1()
end

-- 
-- Unique identifier of the tile set this tile belongs to.
-- 
-- Unique identifier of this tile in the tile set.
-- 
-- GNSS reference time of the correction
-- 
-- Number of messages in the dataset
-- 
-- Position of this message in the dataset
-- 
-- Update interval between consecutive corrections. Encoded following
-- RTCM DF391 specification.
-- 
-- IOD of the SSR atmospheric correction

-- 
-- Deprecated.
Ssr.MsgSsrStecCorrectionDepA = class.class(KaitaiStruct)

function Ssr.MsgSsrStecCorrectionDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrStecCorrectionDepA:_read()
  self.header = Ssr.StecHeaderDepA(self._io, self, self._root)
  self.stec_sat_list = {}
  local i = 0
  while not self._io:is_eof() do
    self.stec_sat_list[i + 1] = Ssr.StecSatElement(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Header of a STEC message
-- 
-- Array of STEC information for each space vehicle

-- 
-- The 3GPP message contains nested variable length arrays which are not
-- supported in SBP, so each grid point will be identified by the index.
Ssr.GriddedCorrectionHeaderDepA = class.class(KaitaiStruct)

function Ssr.GriddedCorrectionHeaderDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.GriddedCorrectionHeaderDepA:_read()
  self.time = Gnss.GpsTimeSec(self._io, self, self._root)
  self.num_msgs = self._io:read_u2le()
  self.seq_num = self._io:read_u2le()
  self.update_interval = self._io:read_u1()
  self.iod_atmo = self._io:read_u1()
  self.tropo_quality_indicator = self._io:read_u1()
end

-- 
-- GNSS reference time of the correction
-- 
-- Number of messages in the dataset
-- 
-- Position of this message in the dataset
-- 
-- Update interval between consecutive corrections. Encoded following
-- RTCM DF391 specification.
-- 
-- IOD of the SSR atmospheric correction
-- 
-- Quality of the troposphere data. Encoded following RTCM DF389
-- specification in units of m.

-- 
-- Note 1: Range: 0-17.5 m. i<=200, mean=0.01i; 200<i<=230,
-- mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
-- 
-- Note 2: Range: 0-17.5 m. i<=200, std=0.01i; 200<i<=230, std=2+0.1(i-200)
-- i>230, std=5+0.5(i-230).
Ssr.MsgSsrOrbitClockBounds = class.class(KaitaiStruct)

function Ssr.MsgSsrOrbitClockBounds:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrOrbitClockBounds:_read()
  self.header = Ssr.BoundsHeader(self._io, self, self._root)
  self.ssr_iod = self._io:read_u1()
  self.const_id = self._io:read_u1()
  self.n_sats = self._io:read_u1()
  self.orbit_clock_bounds = {}
  local i = 0
  while not self._io:is_eof() do
    self.orbit_clock_bounds[i + 1] = Ssr.OrbitClockBound(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Header of a bounds message.
-- 
-- IOD of the SSR bound.
-- 
-- Constellation ID to which the SVs belong.
-- 
-- Number of satellites.
-- 
-- Orbit and Clock Bounds per Satellite

-- 
-- Note 1: Range: 0-17.5 m. i<= 200, mean = 0.01i; 200<i<=230,
-- mean=2+0.1(i-200); i>230, mean=5+0.5(i-230).
Ssr.MsgSsrGriddedCorrectionBounds = class.class(KaitaiStruct)

function Ssr.MsgSsrGriddedCorrectionBounds:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrGriddedCorrectionBounds:_read()
  self.header = Ssr.BoundsHeader(self._io, self, self._root)
  self.ssr_iod_atmo = self._io:read_u1()
  self.tile_set_id = self._io:read_u2le()
  self.tile_id = self._io:read_u2le()
  self.tropo_qi = self._io:read_u1()
  self.grid_point_id = self._io:read_u2le()
  self.tropo_delay_correction = Ssr.TroposphericDelayCorrection(self._io, self, self._root)
  self.tropo_v_hydro_bound_mu = self._io:read_u1()
  self.tropo_v_hydro_bound_sig = self._io:read_u1()
  self.tropo_v_wet_bound_mu = self._io:read_u1()
  self.tropo_v_wet_bound_sig = self._io:read_u1()
  self.n_sats = self._io:read_u1()
  self.stec_sat_list = {}
  local i = 0
  while not self._io:is_eof() do
    self.stec_sat_list[i + 1] = Ssr.StecSatElementIntegrity(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Header of a bounds message.
-- 
-- IOD of the correction.
-- 
-- Set this tile belongs to.
-- 
-- Unique identifier of this tile in the tile set.
-- 
-- Tropo Quality Indicator. Similar to RTCM DF389.
-- 
-- Index of the Grid Point.
-- 
-- Tropospheric delay at grid point.
-- 
-- Vertical Hydrostatic Error Bound Mean.
-- 
-- Vertical Hydrostatic Error Bound StDev.
-- 
-- Vertical Wet Error Bound Mean.
-- 
-- Vertical Wet Error Bound StDev.
-- 
-- Number of satellites.
-- 
-- Array of STEC polynomial coefficients and its bounds for each space
-- vehicle.

-- 
-- Deprecated.
Ssr.MsgSsrGridDefinitionDepA = class.class(KaitaiStruct)

function Ssr.MsgSsrGridDefinitionDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrGridDefinitionDepA:_read()
  self.header = Ssr.GridDefinitionHeaderDepA(self._io, self, self._root)
  self.rle_list = {}
  local i = 0
  while not self._io:is_eof() do
    self.rle_list[i + 1] = self._io:read_u1()
    i = i + 1
  end
end

-- 
-- Header of a Gridded Correction message
-- 
-- Run Length Encode list of quadrants that contain valid data. The
-- spec describes the encoding scheme in detail, but essentially the
-- index of the quadrants that contain transitions between valid and
-- invalid (and vice versa) are encoded as u8 integers.

-- 
-- Code biases are to be added to pseudorange. The corrections conform with
-- RTCMv3 MT 1059 / 1065.
Ssr.CodeBiasesContent = class.class(KaitaiStruct)

function Ssr.CodeBiasesContent:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.CodeBiasesContent:_read()
  self.code = self._io:read_u1()
  self.value = self._io:read_s2le()
end

-- 
-- Signal encoded following RTCM specifications (DF380, DF381, DF382
-- and DF467).
-- 
-- Code bias value

Ssr.MsgSsrSatelliteApc = class.class(KaitaiStruct)

function Ssr.MsgSsrSatelliteApc:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrSatelliteApc:_read()
  self.time = Gnss.GpsTimeSec(self._io, self, self._root)
  self.update_interval = self._io:read_u1()
  self.sol_id = self._io:read_u1()
  self.iod_ssr = self._io:read_u1()
  self.apc = {}
  local i = 0
  while not self._io:is_eof() do
    self.apc[i + 1] = Ssr.SatelliteApc(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- GNSS reference time of the correction
-- 
-- Update interval between consecutive corrections. Encoded following
-- RTCM DF391 specification.
-- 
-- SSR Solution ID. Similar to RTCM DF415.
-- 
-- IOD of the SSR correction. A change of Issue Of Data SSR is used to
-- indicate a change in the SSR generating configuration
-- 
-- Satellite antenna phase center corrections

-- 
-- Phase biases are to be added to carrier phase measurements.
Ssr.PhaseBiasesContent = class.class(KaitaiStruct)

function Ssr.PhaseBiasesContent:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.PhaseBiasesContent:_read()
  self.code = self._io:read_u1()
  self.integer_indicator = self._io:read_u1()
  self.widelane_integer_indicator = self._io:read_u1()
  self.discontinuity_counter = self._io:read_u1()
  self.bias = self._io:read_s4le()
end

-- 
-- Signal encoded following RTCM specifications (DF380, DF381, DF382
-- and DF467)
-- 
-- Indicator for integer property
-- 
-- Indicator for two groups of Wide-Lane(s) integer property
-- 
-- Signal phase discontinuity counter. Increased for every
-- discontinuity in phase.
-- 
-- Phase bias for specified signal

-- 
-- Deprecated.
Ssr.MsgSsrTileDefinitionDepA = class.class(KaitaiStruct)

function Ssr.MsgSsrTileDefinitionDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrTileDefinitionDepA:_read()
  self.tile_set_id = self._io:read_u2le()
  self.tile_id = self._io:read_u2le()
  self.corner_nw_lat = self._io:read_s2le()
  self.corner_nw_lon = self._io:read_s2le()
  self.spacing_lat = self._io:read_u2le()
  self.spacing_lon = self._io:read_u2le()
  self.rows = self._io:read_u2le()
  self.cols = self._io:read_u2le()
  self.bitmask = self._io:read_u8le()
end

-- 
-- Unique identifier of the tile set this tile belongs to.
-- 
-- Unique identifier of this tile in the tile set.
-- See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
-- 
-- North-West corner correction point latitude.
-- 
-- The relation between the latitude X in the range [-90, 90] and the
-- coded number N is:
-- 
-- N = floor((X / 90) * 2^14)
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
-- 
-- North-West corner correction point longitude.
-- 
-- The relation between the longitude X in the range [-180, 180] and
-- the coded number N is:
-- 
-- N = floor((X / 180) * 2^15)
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
-- 
-- Spacing of the correction points in the latitude direction.
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
-- 
-- Spacing of the correction points in the longitude direction.
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
-- 
-- Number of steps in the latitude direction.
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
-- 
-- Number of steps in the longitude direction.
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
-- 
-- Specifies the availability of correction data at the correction
-- points in the array.
-- 
-- If a specific bit is enabled (set to 1), the correction is not
-- available. Only the first rows * cols bits are used, the remainder
-- are set to 0. If there are more then 64 correction points the
-- remaining corrections are always available.
-- 
-- Starting with the northwest corner of the array (top left on a north
-- oriented map) the correction points are enumerated with row
-- precedence - first row west to east, second row west to east, until
-- last row west to east - ending with the southeast corner of the
-- array.
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
-- the definition of the bits is inverted.

-- 
-- Orbit and clock bound.
Ssr.OrbitClockBound = class.class(KaitaiStruct)

function Ssr.OrbitClockBound:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.OrbitClockBound:_read()
  self.sat_id = self._io:read_u1()
  self.orb_radial_bound_mu = self._io:read_u1()
  self.orb_along_bound_mu = self._io:read_u1()
  self.orb_cross_bound_mu = self._io:read_u1()
  self.orb_radial_bound_sig = self._io:read_u1()
  self.orb_along_bound_sig = self._io:read_u1()
  self.orb_cross_bound_sig = self._io:read_u1()
  self.clock_bound_mu = self._io:read_u1()
  self.clock_bound_sig = self._io:read_u1()
end

-- 
-- Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo),
-- or DF488 (BDS) depending on the constellation.
-- 
-- Mean Radial. See Note 1.
-- 
-- Mean Along-Track. See Note 1.
-- 
-- Mean Cross-Track. See Note 1.
-- 
-- Standard Deviation Radial. See Note 2.
-- 
-- Standard Deviation Along-Track. See Note 2.
-- 
-- Standard Deviation Cross-Track. See Note 2.
-- 
-- Clock Bound Mean. See Note 1.
-- 
-- Clock Bound Standard Deviation. See Note 2.

-- 
-- Deprecated.
Ssr.MsgSsrGriddedCorrectionDepA = class.class(KaitaiStruct)

function Ssr.MsgSsrGriddedCorrectionDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrGriddedCorrectionDepA:_read()
  self.header = Ssr.GriddedCorrectionHeaderDepA(self._io, self, self._root)
  self.index = self._io:read_u2le()
  self.tropo_delay_correction = Ssr.TroposphericDelayCorrection(self._io, self, self._root)
  self.stec_residuals = {}
  local i = 0
  while not self._io:is_eof() do
    self.stec_residuals[i + 1] = Ssr.StecResidual(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Header of a Gridded Correction message
-- 
-- Index of the grid point
-- 
-- Wet and hydrostatic vertical delays (mean, stddev)
-- 
-- STEC residuals for each satellite (mean, stddev)

Ssr.MsgSsrOrbitClockBoundsDegradation = class.class(KaitaiStruct)

function Ssr.MsgSsrOrbitClockBoundsDegradation:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrOrbitClockBoundsDegradation:_read()
  self.header = Ssr.BoundsHeader(self._io, self, self._root)
  self.ssr_iod = self._io:read_u1()
  self.const_id = self._io:read_u1()
  self.sat_bitmask = self._io:read_u8le()
  self.orbit_clock_bounds_degradation = Ssr.OrbitClockBoundDegradation(self._io, self, self._root)
end

-- 
-- Header of a bounds message.
-- 
-- IOD of the SSR bound degradation parameter.
-- 
-- Constellation ID to which the SVs belong.
-- 
-- Satellite Bit Mask. Put 1 for each satellite where the following
-- degradation parameters are applicable, 0 otherwise. Encoded
-- following RTCM DF394 specification.
-- 
-- Orbit and Clock Bounds Degradation Parameters

-- 
-- Deprecated.
Ssr.MsgSsrGriddedCorrectionNoStdDepA = class.class(KaitaiStruct)

function Ssr.MsgSsrGriddedCorrectionNoStdDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrGriddedCorrectionNoStdDepA:_read()
  self.header = Ssr.GriddedCorrectionHeaderDepA(self._io, self, self._root)
  self.index = self._io:read_u2le()
  self.tropo_delay_correction = Ssr.TroposphericDelayCorrectionNoStd(self._io, self, self._root)
  self.stec_residuals = {}
  local i = 0
  while not self._io:is_eof() do
    self.stec_residuals[i + 1] = Ssr.StecResidualNoStd(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Header of a Gridded Correction message
-- 
-- Index of the grid point
-- 
-- Wet and hydrostatic vertical delays
-- 
-- STEC residuals for each satellite

Ssr.MsgSsrCodePhaseBiasesBounds = class.class(KaitaiStruct)

function Ssr.MsgSsrCodePhaseBiasesBounds:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrCodePhaseBiasesBounds:_read()
  self.header = Ssr.BoundsHeader(self._io, self, self._root)
  self.ssr_iod = self._io:read_u1()
  self.const_id = self._io:read_u1()
  self.n_sats_signals = self._io:read_u1()
  self.satellites_signals = {}
  local i = 0
  while not self._io:is_eof() do
    self.satellites_signals[i + 1] = Ssr.CodePhaseBiasesSatSig(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Header of a bounds message.
-- 
-- IOD of the SSR bound.
-- 
-- Constellation ID to which the SVs belong.
-- 
-- Number of satellite-signal couples.
-- 
-- Code and Phase Biases Bounds per Satellite-Signal couple.

-- 
-- The precise code biases message is to be added to the pseudorange of the
-- corresponding signal to get corrected pseudorange. It is an equivalent
-- to the 1059 / 1065 RTCM message types.
Ssr.MsgSsrCodeBiases = class.class(KaitaiStruct)

function Ssr.MsgSsrCodeBiases:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrCodeBiases:_read()
  self.time = Gnss.GpsTimeSec(self._io, self, self._root)
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.update_interval = self._io:read_u1()
  self.iod_ssr = self._io:read_u1()
  self.biases = {}
  local i = 0
  while not self._io:is_eof() do
    self.biases[i + 1] = Ssr.CodeBiasesContent(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- GNSS reference time of the correction
-- 
-- GNSS signal identifier (16 bit)
-- 
-- Update interval between consecutive corrections. Encoded following
-- RTCM DF391 specification.
-- 
-- IOD of the SSR correction. A change of Issue Of Data SSR is used to
-- indicate a change in the SSR generating configuration
-- 
-- Code biases for the different satellite signals

-- 
-- Provides the correction point coordinates for the atmospheric correction
-- values in the MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION
-- messages.
-- 
-- Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information
-- element GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of
-- correction points, not lists of points.
Ssr.MsgSsrTileDefinition = class.class(KaitaiStruct)

function Ssr.MsgSsrTileDefinition:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrTileDefinition:_read()
  self.time = Gnss.GpsTimeSec(self._io, self, self._root)
  self.update_interval = self._io:read_u1()
  self.sol_id = self._io:read_u1()
  self.iod_atmo = self._io:read_u1()
  self.tile_set_id = self._io:read_u2le()
  self.tile_id = self._io:read_u2le()
  self.corner_nw_lat = self._io:read_s2le()
  self.corner_nw_lon = self._io:read_s2le()
  self.spacing_lat = self._io:read_u2le()
  self.spacing_lon = self._io:read_u2le()
  self.rows = self._io:read_u2le()
  self.cols = self._io:read_u2le()
  self.bitmask = self._io:read_u8le()
end

-- 
-- GNSS reference time of the correction
-- 
-- Update interval between consecutive corrections. Encoded following
-- RTCM DF391 specification.
-- 
-- SSR Solution ID. Similar to RTCM DF415.
-- 
-- IOD of the SSR atmospheric correction.
-- 
-- Unique identifier of the tile set this tile belongs to.
-- 
-- Unique identifier of this tile in the tile set.
-- See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
-- 
-- North-West corner correction point latitude.
-- 
-- The relation between the latitude X in the range [-90, 90] and the
-- coded number N is:  N = floor((X / 90) * 2^14)
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
-- 
-- North-West corner correction point longitude.
-- 
-- The relation between the longitude X in the range [-180, 180] and
-- the coded number N is: N = floor((X / 180) * 2^15)
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
-- 
-- Spacing of the correction points in the latitude direction.
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
-- 
-- Spacing of the correction points in the longitude direction.
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
-- 
-- Number of steps in the latitude direction.
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
-- 
-- Number of steps in the longitude direction.
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
-- 
-- Specifies the absence of correction data at the correction points in
-- the array (grid).
-- 
-- Only the first rows * cols bits are used, and if a specific bit is
-- enabled (set to 1), the correction is not available. If there are
-- more than 64 correction points the remaining corrections are always
-- available.
-- 
-- The correction points are packed by rows, starting with the
-- northwest corner of the array (top-left on a north oriented map),
-- with each row spanning west to east, ending with the southeast
-- corner of the array.
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
-- the definition of the bits is inverted.

-- 
-- Orbit and clock bound degradation.
Ssr.OrbitClockBoundDegradation = class.class(KaitaiStruct)

function Ssr.OrbitClockBoundDegradation:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.OrbitClockBoundDegradation:_read()
  self.orb_radial_bound_mu_dot = self._io:read_u1()
  self.orb_along_bound_mu_dot = self._io:read_u1()
  self.orb_cross_bound_mu_dot = self._io:read_u1()
  self.orb_radial_bound_sig_dot = self._io:read_u1()
  self.orb_along_bound_sig_dot = self._io:read_u1()
  self.orb_cross_bound_sig_dot = self._io:read_u1()
  self.clock_bound_mu_dot = self._io:read_u1()
  self.clock_bound_sig_dot = self._io:read_u1()
end

-- 
-- Orbit Bound Mean Radial First derivative. Range: 0-0.255 m/s
-- 
-- Orbit Bound Mean Along-Track First derivative. Range: 0-0.255 m/s
-- 
-- Orbit Bound Mean Cross-Track First derivative. Range: 0-0.255 m/s
-- 
-- Orbit Bound Standard Deviation Radial First derivative. Range:
-- 0-0.255 m/s
-- 
-- Orbit Bound Standard Deviation Along-Track First derivative. Range:
-- 0-0.255 m/s
-- 
-- Orbit Bound Standard Deviation Cross-Track First derivative. Range:
-- 0-0.255 m/s
-- 
-- Clock Bound Mean First derivative. Range: 0-0.255 m/s
-- 
-- Clock Bound Standard Deviation First derivative. Range: 0-0.255 m/s

-- 
-- Deprecated.
Ssr.MsgSsrSatelliteApcDep = class.class(KaitaiStruct)

function Ssr.MsgSsrSatelliteApcDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrSatelliteApcDep:_read()
  self.apc = {}
  local i = 0
  while not self._io:is_eof() do
    self.apc[i + 1] = Ssr.SatelliteApc(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Satellite antenna phase center corrections

-- 
-- Troposphere vertical delays (mean and standard deviation) at the grid
-- point.
Ssr.TroposphericDelayCorrection = class.class(KaitaiStruct)

function Ssr.TroposphericDelayCorrection:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.TroposphericDelayCorrection:_read()
  self.hydro = self._io:read_s2le()
  self.wet = self._io:read_s1()
  self.stddev = self._io:read_u1()
end

-- 
-- Hydrostatic vertical delay. Add 2.3 m to get actual value.
-- 
-- Wet vertical delay. Add 0.252 m to get actual value.
-- 
-- Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 +
-- value/16) - 1)

-- 
-- Deprecated.
Ssr.MsgSsrTileDefinitionDepB = class.class(KaitaiStruct)

function Ssr.MsgSsrTileDefinitionDepB:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrTileDefinitionDepB:_read()
  self.ssr_sol_id = self._io:read_u1()
  self.tile_set_id = self._io:read_u2le()
  self.tile_id = self._io:read_u2le()
  self.corner_nw_lat = self._io:read_s2le()
  self.corner_nw_lon = self._io:read_s2le()
  self.spacing_lat = self._io:read_u2le()
  self.spacing_lon = self._io:read_u2le()
  self.rows = self._io:read_u2le()
  self.cols = self._io:read_u2le()
  self.bitmask = self._io:read_u8le()
end

-- 
-- SSR Solution ID.
-- 
-- Unique identifier of the tile set this tile belongs to.
-- 
-- Unique identifier of this tile in the tile set.
-- See GNSS-SSR-ArrayOfCorrectionPoints field correctionPointSetID.
-- 
-- North-West corner correction point latitude.
-- 
-- The relation between the latitude X in the range [-90, 90] and the
-- coded number N is:
-- 
-- N = floor((X / 90) * 2^14)
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
-- 
-- North-West corner correction point longitude.
-- 
-- The relation between the longitude X in the range [-180, 180] and
-- the coded number N is:
-- 
-- N = floor((X / 180) * 2^15)
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
-- 
-- Spacing of the correction points in the latitude direction.
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
-- 
-- Spacing of the correction points in the longitude direction.
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
-- 
-- Number of steps in the latitude direction.
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
-- 
-- Number of steps in the longitude direction.
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
-- 
-- Specifies the availability of correction data at the correction
-- points in the array.
-- 
-- If a specific bit is enabled (set to 1), the correction is not
-- available. Only the first rows * cols bits are used, the remainder
-- are set to 0. If there are more then 64 correction points the
-- remaining corrections are always available.
-- 
-- Starting with the northwest corner of the array (top left on a north
-- oriented map) the correction points are enumerated with row
-- precedence - first row west to east, second row west to east, until
-- last row west to east - ending with the southeast corner of the
-- array.
-- 
-- See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note
-- the definition of the bits is inverted.

-- 
-- The precise phase biases message contains the biases to be added to the
-- carrier phase of the corresponding signal to get corrected carrier phase
-- measurement, as well as the satellite yaw angle to be applied to compute
-- the phase wind-up correction. It is typically an equivalent to the 1265
-- RTCM message types.
Ssr.MsgSsrPhaseBiases = class.class(KaitaiStruct)

function Ssr.MsgSsrPhaseBiases:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ssr.MsgSsrPhaseBiases:_read()
  self.time = Gnss.GpsTimeSec(self._io, self, self._root)
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.update_interval = self._io:read_u1()
  self.iod_ssr = self._io:read_u1()
  self.dispersive_bias = self._io:read_u1()
  self.mw_consistency = self._io:read_u1()
  self.yaw = self._io:read_u2le()
  self.yaw_rate = self._io:read_s1()
  self.biases = {}
  local i = 0
  while not self._io:is_eof() do
    self.biases[i + 1] = Ssr.PhaseBiasesContent(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- GNSS reference time of the correction
-- 
-- GNSS signal identifier (16 bit)
-- 
-- Update interval between consecutive corrections. Encoded following
-- RTCM DF391 specification.
-- 
-- IOD of the SSR correction. A change of Issue Of Data SSR is used to
-- indicate a change in the SSR generating configuration
-- 
-- Indicator for the dispersive phase biases property.
-- 
-- Consistency indicator for Melbourne-Wubbena linear combinations
-- 
-- Satellite yaw angle
-- 
-- Satellite yaw angle rate
-- 
-- Phase biases corrections for a satellite being tracked.

