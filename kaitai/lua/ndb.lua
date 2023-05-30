-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

Ndb = class.class(KaitaiStruct)

function Ndb:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ndb:_read()
end


-- 
-- This message is sent out when an object is stored into NDB. If needed
-- message could also be sent out when fetching an object from NDB.
Ndb.MsgNdbEvent = class.class(KaitaiStruct)

function Ndb.MsgNdbEvent:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Ndb.MsgNdbEvent:_read()
  self.recv_time = self._io:read_u8le()
  self.event = self._io:read_u1()
  self.object_type = self._io:read_u1()
  self.result = self._io:read_u1()
  self.data_source = self._io:read_u1()
  self.object_sid = Gnss.GnssSignal(self._io, self, self._root)
  self.src_sid = Gnss.GnssSignal(self._io, self, self._root)
  self.original_sender = self._io:read_u2le()
end

-- 
-- HW time in milliseconds.
-- 
-- Event type.
-- 
-- Event object type.
-- 
-- Event result.
-- 
-- Data source for STORE event, reserved for other events.
-- 
-- GNSS signal identifier, If object_type is Ephemeris OR Almanac, sid
-- indicates for which signal the object belongs to. Reserved in other
-- cases.
-- 
-- GNSS signal identifier, If object_type is Almanac, Almanac WN, Iono
-- OR L2C capabilities AND data_source is NDB_DS_RECEIVER sid indicates
-- from which SV data was decoded. Reserved in other cases.
-- 
-- A unique identifier of the sending hardware. For v1.0, set to the 2
-- least significant bytes of the device serial number, valid only if
-- data_source is NDB_DS_SBP. Reserved in case of other data_source.

