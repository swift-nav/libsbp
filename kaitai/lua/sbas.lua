-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

Sbas = class.class(KaitaiStruct)

function Sbas:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Sbas:_read()
end


-- 
-- This message is sent once per second per SBAS satellite. ME checks the
-- parity of the data block and sends only blocks that pass the check.
Sbas.MsgSbasRaw = class.class(KaitaiStruct)

function Sbas.MsgSbasRaw:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Sbas.MsgSbasRaw:_read()
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.tow = self._io:read_u4le()
  self.message_type = self._io:read_u1()
  self.data = {}
  for i = 0, 27 - 1 do
    self.data[i + 1] = self._io:read_u1()
  end
end

-- 
-- GNSS signal identifier.
-- 
-- GPS time-of-week at the start of the data block.
-- 
-- SBAS message type (0-63)
-- 
-- Raw SBAS data field of 212 bits (last byte padded with zeros).

