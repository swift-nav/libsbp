-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

Vehicle = class.class(KaitaiStruct)

function Vehicle:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Vehicle:_read()
end


-- 
-- Message representing the x component of vehicle velocity in the user
-- frame at the odometry reference point(s) specified by the user. The
-- offset for the odometry reference point and the definition and origin of
-- the user frame are defined through the device settings interface. There
-- are 4 possible user-defined sources of this message which are labeled
-- arbitrarily source 0 through 3. If using "processor time" time tags, the
-- receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix
-- becomes available to synchronise odometry measurements with GNSS.
-- Processor time shall roll over to zero after one week.
Vehicle.MsgOdometry = class.class(KaitaiStruct)

function Vehicle.MsgOdometry:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Vehicle.MsgOdometry:_read()
  self.tow = self._io:read_u4le()
  self.velocity = self._io:read_s4le()
  self.flags = self._io:read_u1()
end

-- 
-- Time field representing either milliseconds in the GPS Week or local
-- CPU time from the producing system in milliseconds.  See the
-- tow_source flag for the exact source of this timestamp.
-- 
-- The signed forward component of vehicle velocity.
-- 
-- Status flags

-- 
-- Message containing the accumulated distance travelled by a wheel located
-- at an odometry reference point defined by the user. The offset for the
-- odometry reference point and the definition and origin of the user frame
-- are defined through the device settings interface. The source of this
-- message is identified by the source field, which is an integer ranging
-- from 0 to 255. The timestamp associated with this message should
-- represent the time when the accumulated tick count reached the value
-- given by the contents of this message as accurately as possible. If
-- using "local CPU time" time tags, the receiving end will expect a
-- `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to synchronise
-- wheeltick measurements with GNSS. Local CPU time shall roll over to zero
-- after one week.
Vehicle.MsgWheeltick = class.class(KaitaiStruct)

function Vehicle.MsgWheeltick:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Vehicle.MsgWheeltick:_read()
  self.time = self._io:read_u8le()
  self.flags = self._io:read_u1()
  self.source = self._io:read_u1()
  self.ticks = self._io:read_s4le()
end

-- 
-- Time field representing either microseconds since the last PPS,
-- microseconds in the GPS Week or local CPU time from the producing
-- system in microseconds. See the synch_type field for the exact
-- meaning of this timestamp.
-- 
-- Field indicating the type of timestamp contained in the time field.
-- 
-- ID of the sensor producing this message
-- 
-- Free-running counter of the accumulated distance for this sensor.
-- The counter should be incrementing if travelling into one direction
-- and decrementing when travelling in the opposite direction.

