-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

Mag = class.class(KaitaiStruct)

function Mag:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Mag:_read()
end


-- 
-- Raw data from the magnetometer.
Mag.MsgMagRaw = class.class(KaitaiStruct)

function Mag.MsgMagRaw:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Mag.MsgMagRaw:_read()
  self.tow = self._io:read_u4le()
  self.tow_f = self._io:read_u1()
  self.mag_x = self._io:read_s2le()
  self.mag_y = self._io:read_s2le()
  self.mag_z = self._io:read_s2le()
end

-- 
-- Milliseconds since start of GPS week. If the high bit is set, the
-- time is unknown or invalid.
-- 
-- Milliseconds since start of GPS week, fractional part
-- 
-- Magnetic field in the body frame X axis
-- 
-- Magnetic field in the body frame Y axis
-- 
-- Magnetic field in the body frame Z axis

