-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

ExtEvents = class.class(KaitaiStruct)

function ExtEvents:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function ExtEvents:_read()
end


-- 
-- Reports detection of an external event, the GPS time it occurred, which
-- pin it was and whether it was rising or falling.
ExtEvents.MsgExtEvent = class.class(KaitaiStruct)

function ExtEvents.MsgExtEvent:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function ExtEvents.MsgExtEvent:_read()
  self.wn = self._io:read_u2le()
  self.tow = self._io:read_u4le()
  self.ns_residual = self._io:read_s4le()
  self.flags = self._io:read_u1()
  self.pin = self._io:read_u1()
end

-- 
-- GPS week number
-- 
-- GPS time of week rounded to the nearest millisecond
-- 
-- Nanosecond residual of millisecond-rounded TOW (ranges from -500000
-- to 500000)
-- 
-- Flags
-- 
-- Pin number.  0..9 = DEBUG0..9.

