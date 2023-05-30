-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

Integrity = class.class(KaitaiStruct)

function Integrity:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Integrity:_read()
end


Integrity.MsgSsrFlagSatellites = class.class(KaitaiStruct)

function Integrity.MsgSsrFlagSatellites:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Integrity.MsgSsrFlagSatellites:_read()
  self.obs_time = Gnss.GpsTimeSec(self._io, self, self._root)
  self.num_msgs = self._io:read_u1()
  self.seq_num = self._io:read_u1()
  self.ssr_sol_id = self._io:read_u1()
  self.chain_id = self._io:read_u1()
  self.const_id = self._io:read_u1()
  self.n_faulty_sats = self._io:read_u1()
  self.faulty_sats = {}
  local i = 0
  while not self._io:is_eof() do
    self.faulty_sats[i + 1] = self._io:read_u1()
    i = i + 1
  end
end

-- 
-- GNSS reference time of the observation used to generate the flag.
-- 
-- Number of messages in the dataset
-- 
-- Position of this message in the dataset
-- 
-- SSR Solution ID.
-- 
-- Chain and type of flag.
-- 
-- Constellation ID.
-- 
-- Number of faulty satellites.
-- 
-- List of faulty satellites.

Integrity.MsgSsrFlagIonoTileSatLos = class.class(KaitaiStruct)

function Integrity.MsgSsrFlagIonoTileSatLos:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Integrity.MsgSsrFlagIonoTileSatLos:_read()
  self.header = Integrity.IntegritySsrHeader(self._io, self, self._root)
  self.n_faulty_los = self._io:read_u1()
  self.faulty_los = {}
  local i = 0
  while not self._io:is_eof() do
    self.faulty_los[i + 1] = Gnss.SvId(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Header of an integrity message.
-- 
-- Number of faulty LOS.
-- 
-- List of faulty LOS

Integrity.MsgSsrFlagIonoGridPointSatLos = class.class(KaitaiStruct)

function Integrity.MsgSsrFlagIonoGridPointSatLos:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Integrity.MsgSsrFlagIonoGridPointSatLos:_read()
  self.header = Integrity.IntegritySsrHeader(self._io, self, self._root)
  self.grid_point_id = self._io:read_u2le()
  self.n_faulty_los = self._io:read_u1()
  self.faulty_los = {}
  local i = 0
  while not self._io:is_eof() do
    self.faulty_los[i + 1] = Gnss.SvId(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Header of an integrity message.
-- 
-- Index of the grid point.
-- 
-- Number of faulty LOS.
-- 
-- List of faulty LOS

Integrity.IntegritySsrHeader = class.class(KaitaiStruct)

function Integrity.IntegritySsrHeader:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Integrity.IntegritySsrHeader:_read()
  self.obs_time = Gnss.GpsTimeSec(self._io, self, self._root)
  self.num_msgs = self._io:read_u1()
  self.seq_num = self._io:read_u1()
  self.ssr_sol_id = self._io:read_u1()
  self.tile_set_id = self._io:read_u2le()
  self.tile_id = self._io:read_u2le()
  self.chain_id = self._io:read_u1()
end

-- 
-- GNSS reference time of the observation used to generate the flag.
-- 
-- Number of messages in the dataset
-- 
-- Position of this message in the dataset
-- 
-- SSR Solution ID.
-- 
-- Unique identifier of the set this tile belongs to.
-- 
-- Unique identifier of this tile in the tile set.
-- 
-- Chain and type of flag.

Integrity.MsgAcknowledge = class.class(KaitaiStruct)

function Integrity.MsgAcknowledge:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Integrity.MsgAcknowledge:_read()
  self.request_id = self._io:read_u1()
  self.area_id = self._io:read_u4le()
  self.response_code = self._io:read_u1()
  self.correction_mask_on_demand = self._io:read_u2le()
  self.correction_mask_stream = self._io:read_u2le()
  self.solution_id = self._io:read_u1()
end

-- 
-- Echo of the request ID field from the corresponding CRA message, or
-- 255 if no request ID was provided.
-- 
-- Echo of the Area ID field from the corresponding CRA message.
-- 
-- Reported status of the request.
-- 
-- Contains the message group(s) that will be sent in response from the
-- corresponding CRA correction mask. An echo of the correction mask
-- field from the corresponding CRA message.
-- 
-- For future expansion. Always set to 0.
-- 
-- The solution ID of the instance providing the corrections.

Integrity.MsgSsrFlagIonoGridPoints = class.class(KaitaiStruct)

function Integrity.MsgSsrFlagIonoGridPoints:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Integrity.MsgSsrFlagIonoGridPoints:_read()
  self.header = Integrity.IntegritySsrHeader(self._io, self, self._root)
  self.n_faulty_points = self._io:read_u1()
  self.faulty_points = {}
  local i = 0
  while not self._io:is_eof() do
    self.faulty_points[i + 1] = self._io:read_u2le()
    i = i + 1
  end
end

-- 
-- Header of an integrity message.
-- 
-- Number of faulty grid points.
-- 
-- List of faulty grid points.

Integrity.MsgSsrFlagTropoGridPoints = class.class(KaitaiStruct)

function Integrity.MsgSsrFlagTropoGridPoints:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Integrity.MsgSsrFlagTropoGridPoints:_read()
  self.header = Integrity.IntegritySsrHeader(self._io, self, self._root)
  self.n_faulty_points = self._io:read_u1()
  self.faulty_points = {}
  local i = 0
  while not self._io:is_eof() do
    self.faulty_points[i + 1] = self._io:read_u2le()
    i = i + 1
  end
end

-- 
-- Header of an integrity message.
-- 
-- Number of faulty grid points.
-- 
-- List of faulty grid points.

-- 
-- Integrity monitoring flags for multiple aggregated elements. An element
-- could be a satellite, SSR grid point, or SSR tile. A group of aggregated
-- elements being monitored for integrity could refer to:
-- 
-- - Satellites in a particular {GPS, GAL, BDS} constellation.
-- 
-- - Satellites in the line-of-sight of a particular SSR tile.
-- 
-- - Satellites in the line-of-sight of a particular SSR grid point.
-- 
-- The integrity usage for a group of aggregated elements varies according
-- to the integrity flag of the satellites comprising that group.
-- 
-- SSR_INTEGRITY_USAGE_NOMINAL: All satellites received passed the
-- integrity check and have flag INTEGRITY_FLAG_OK.
-- 
-- SSR_INTEGRITY_USAGE_WARNING: A limited number of elements in the group
-- failed the integrity check. Refer to more granular integrity messages
-- for details on the specific failing elements.
-- 
-- SSR_INTEGRITY_USAGE_ALERT: Most elements in the group failed the
-- integrity check, do not use for positioning.
-- 
-- SSR_INTEGRITY_USAGE_NOT_MONITORED: Unable to verify the integrity flag
-- of elements in the group.
Integrity.MsgSsrFlagHighLevel = class.class(KaitaiStruct)

function Integrity.MsgSsrFlagHighLevel:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Integrity.MsgSsrFlagHighLevel:_read()
  self.obs_time = Gnss.GpsTimeSec(self._io, self, self._root)
  self.corr_time = Gnss.GpsTimeSec(self._io, self, self._root)
  self.ssr_sol_id = self._io:read_u1()
  self.tile_set_id = self._io:read_u2le()
  self.tile_id = self._io:read_u2le()
  self.chain_id = self._io:read_u1()
  self.use_gps_sat = self._io:read_u1()
  self.use_gal_sat = self._io:read_u1()
  self.use_bds_sat = self._io:read_u1()
  self.reserved = {}
  for i = 0, 6 - 1 do
    self.reserved[i + 1] = self._io:read_u1()
  end
  self.use_tropo_grid_points = self._io:read_u1()
  self.use_iono_grid_points = self._io:read_u1()
  self.use_iono_tile_sat_los = self._io:read_u1()
  self.use_iono_grid_point_sat_los = self._io:read_u1()
end

-- 
-- GNSS reference time of the observation used to generate the flag.
-- 
-- GNSS reference time of the correction associated to the flag.
-- 
-- SSR Solution ID.
-- 
-- Unique identifier of the set this tile belongs to.
-- 
-- Unique identifier of this tile in the tile set.
-- 
-- Chain and type of flag.
-- 
-- Use GPS satellites.
-- 
-- Use GAL satellites.
-- 
-- Use BDS satellites.
-- 
-- Reserved
-- 
-- Use tropo grid points.
-- 
-- Use iono grid points.
-- 
-- Use iono tile satellite LoS.
-- 
-- Use iono grid point satellite LoS.

