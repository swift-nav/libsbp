-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

Gnss = class.class(KaitaiStruct)

function Gnss:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Gnss:_read()
end


-- 
-- Deprecated.
Gnss.GnssSignalDep = class.class(KaitaiStruct)

function Gnss.GnssSignalDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Gnss.GnssSignalDep:_read()
  self.sat = self._io:read_u2le()
  self.code = self._io:read_u1()
  self.reserved = self._io:read_u1()
end

-- 
-- Constellation-specific satellite identifier.
-- 
-- Note: unlike GnssSignal, GPS satellites are encoded as (PRN - 1).
-- Other constellations do not have this offset.
-- 
-- Signal constellation, band and code
-- 
-- Reserved

-- 
-- Carrier phase measurement in cycles represented as a 40-bit fixed point
-- number with Q32.8 layout, i.e. 32-bits of whole cycles and 8-bits of
-- fractional cycles. This phase has the same sign as the pseudorange.
Gnss.CarrierPhase = class.class(KaitaiStruct)

function Gnss.CarrierPhase:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Gnss.CarrierPhase:_read()
  self.i = self._io:read_s4le()
  self.f = self._io:read_u1()
end

-- 
-- Carrier phase whole cycles
-- 
-- Carrier phase fractional part

-- 
-- A wire-appropriate GPS time, defined as the number of milliseconds since
-- beginning of the week on the Saturday/Sunday transition.
Gnss.GpsTimeDep = class.class(KaitaiStruct)

function Gnss.GpsTimeDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Gnss.GpsTimeDep:_read()
  self.tow = self._io:read_u4le()
  self.wn = self._io:read_u2le()
end

-- 
-- Milliseconds since start of GPS week
-- 
-- GPS week number

-- 
-- Signal identifier containing constellation, band, and satellite
-- identifier.
Gnss.GnssSignal = class.class(KaitaiStruct)

function Gnss.GnssSignal:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Gnss.GnssSignal:_read()
  self.sat = self._io:read_u1()
  self.code = self._io:read_u1()
end

-- 
-- Constellation-specific satellite id. For GLO can either be (100+FCN)
-- where FCN is in [-7,+6] or the Slot ID in [1,28].
-- 
-- Signal constellation, band and code

-- 
-- A wire-appropriate receiver clock time, defined as the time since the
-- beginning of the week on the Saturday/Sunday transition. In most cases,
-- observations are epoch aligned so ns field will be 0.
Gnss.GpsTime = class.class(KaitaiStruct)

function Gnss.GpsTime:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Gnss.GpsTime:_read()
  self.tow = self._io:read_u4le()
  self.ns_residual = self._io:read_s4le()
  self.wn = self._io:read_u2le()
end

-- 
-- Milliseconds since start of GPS week
-- 
-- Nanosecond residual of millisecond-rounded TOW (ranges from -500000
-- to 500000)
-- 
-- GPS week number

-- 
-- A GPS time, defined as the number of seconds since beginning of the week
-- on the Saturday/Sunday transition.
Gnss.GpsTimeSec = class.class(KaitaiStruct)

function Gnss.GpsTimeSec:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Gnss.GpsTimeSec:_read()
  self.tow = self._io:read_u4le()
  self.wn = self._io:read_u2le()
end

-- 
-- Seconds since start of GPS week
-- 
-- GPS week number

-- 
-- A (Constellation ID, satellite ID) tuple that uniquely identifies a
-- space vehicle.
Gnss.SvId = class.class(KaitaiStruct)

function Gnss.SvId:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Gnss.SvId:_read()
  self.sat_id = self._io:read_u1()
  self.constellation = self._io:read_u1()
end

-- 
-- Constellation-specific satellite id. For GLO can either be (100+FCN)
-- where FCN is in [-7,+6] or the Slot ID in [1,28].
-- 
-- Constellation ID to which the SV belongs

