-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

Telemetry = class.class(KaitaiStruct)

function Telemetry:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Telemetry:_read()
end


Telemetry.TelemetrySv = class.class(KaitaiStruct)

function Telemetry.TelemetrySv:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Telemetry.TelemetrySv:_read()
  self.az = self._io:read_u1()
  self.el = self._io:read_s1()
  self.availability_flags = self._io:read_u1()
  self.pseudorange_residual = self._io:read_s2le()
  self.phase_residual = self._io:read_s2le()
  self.outlier_flags = self._io:read_u1()
  self.ephemeris_flags = self._io:read_u1()
  self.correction_flags = self._io:read_u1()
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
end

-- 
-- Azimuth angle (range 0..179)
-- 
-- Elevation angle (range -90..90)
-- 
-- Observation availability at filter update
-- 
-- Pseudorange observation residual
-- 
-- Carrier-phase or carrier-phase-derived observation residual
-- 
-- Reports if observation is marked as an outlier and is excluded from
-- the update
-- 
-- Ephemeris metadata
-- 
-- Reserved
-- 
-- GNSS signal identifier (16 bit)

-- 
-- This message includes telemetry pertinent to satellite signals available
-- to Starling.
Telemetry.MsgTelSv = class.class(KaitaiStruct)

function Telemetry.MsgTelSv:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Telemetry.MsgTelSv:_read()
  self.wn = self._io:read_u2le()
  self.tow = self._io:read_u4le()
  self.n_obs = self._io:read_u1()
  self.origin_flags = self._io:read_u1()
  self.sv_tel = {}
  local i = 0
  while not self._io:is_eof() do
    self.sv_tel[i + 1] = Telemetry.TelemetrySv(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- GPS week number
-- 
-- GPS Time of Week
-- 
-- Total number of observations. First nibble is the size of the
-- sequence (n), second nibble is the zero-indexed counter (ith packet
-- of n)
-- 
-- Flags to identify the filter type from which the telemetry is
-- reported from
-- 
-- Array of per-signal telemetry entries

