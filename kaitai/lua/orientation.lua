-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

Orientation = class.class(KaitaiStruct)

function Orientation:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Orientation:_read()
end


-- 
-- This message reports the baseline heading pointing from the base station
-- to the rover relative to True North. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow). It is
-- intended that time-matched RTK mode is used when the base station is
-- moving.
Orientation.MsgBaselineHeading = class.class(KaitaiStruct)

function Orientation.MsgBaselineHeading:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Orientation.MsgBaselineHeading:_read()
  self.tow = self._io:read_u4le()
  self.heading = self._io:read_u4le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Heading
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- This message reports the quaternion vector describing the vehicle body
-- frame's orientation with respect to a local-level NED frame. The
-- components of the vector should sum to a unit vector assuming that the
-- LSB of each component as a value of 2^-31. This message will only be
-- available in future INS versions of Swift Products and is not produced
-- by Piksi Multi or Duro.
Orientation.MsgOrientQuat = class.class(KaitaiStruct)

function Orientation.MsgOrientQuat:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Orientation.MsgOrientQuat:_read()
  self.tow = self._io:read_u4le()
  self.w = self._io:read_s4le()
  self.x = self._io:read_s4le()
  self.y = self._io:read_s4le()
  self.z = self._io:read_s4le()
  self.w_accuracy = self._io:read_f4le()
  self.x_accuracy = self._io:read_f4le()
  self.y_accuracy = self._io:read_f4le()
  self.z_accuracy = self._io:read_f4le()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Real component
-- 
-- 1st imaginary component
-- 
-- 2nd imaginary component
-- 
-- 3rd imaginary component
-- 
-- Estimated standard deviation of w
-- 
-- Estimated standard deviation of x
-- 
-- Estimated standard deviation of y
-- 
-- Estimated standard deviation of z
-- 
-- Status flags

-- 
-- This message reports the yaw, pitch, and roll angles of the vehicle body
-- frame. The rotations should applied intrinsically in the order yaw,
-- pitch, and roll in order to rotate the from a frame aligned with the
-- local-level NED frame to the vehicle body frame.  This message will only
-- be available in future INS versions of Swift Products and is not
-- produced by Piksi Multi or Duro.
Orientation.MsgOrientEuler = class.class(KaitaiStruct)

function Orientation.MsgOrientEuler:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Orientation.MsgOrientEuler:_read()
  self.tow = self._io:read_u4le()
  self.roll = self._io:read_s4le()
  self.pitch = self._io:read_s4le()
  self.yaw = self._io:read_s4le()
  self.roll_accuracy = self._io:read_f4le()
  self.pitch_accuracy = self._io:read_f4le()
  self.yaw_accuracy = self._io:read_f4le()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- rotation about the forward axis of the vehicle
-- 
-- rotation about the rightward axis of the vehicle
-- 
-- rotation about the downward axis of the vehicle
-- 
-- Estimated standard deviation of roll
-- 
-- Estimated standard deviation of pitch
-- 
-- Estimated standard deviation of yaw
-- 
-- Status flags

-- 
-- This message reports the orientation rates in the vehicle body frame.
-- The values represent the measurements a strapped down gyroscope would
-- make and are not equivalent to the time derivative of the Euler angles.
-- The orientation and origin of the user frame is specified via device
-- settings. By convention, the vehicle x-axis is expected to be aligned
-- with the forward direction, while the vehicle y-axis is expected to be
-- aligned with the right direction, and the vehicle z-axis should be
-- aligned with the down direction. This message will only be available in
-- future INS versions of Swift Products and is not produced by Piksi Multi
-- or Duro.
Orientation.MsgAngularRate = class.class(KaitaiStruct)

function Orientation.MsgAngularRate:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Orientation.MsgAngularRate:_read()
  self.tow = self._io:read_u4le()
  self.x = self._io:read_s4le()
  self.y = self._io:read_s4le()
  self.z = self._io:read_s4le()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- angular rate about x axis
-- 
-- angular rate about y axis
-- 
-- angular rate about z axis
-- 
-- Status flags

