-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

Imu = class.class(KaitaiStruct)

function Imu:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Imu:_read()
end


-- 
-- Raw data from the Inertial Measurement Unit, containing accelerometer
-- and gyroscope readings. The sense of the measurements are to be aligned
-- with the indications on the device itself. Measurement units, which are
-- specific to the device hardware and settings, are communicated via the
-- MSG_IMU_AUX message. If using "time since startup" time tags, the
-- receiving end will expect a `MSG_GNSS_TIME_OFFSET` when a PVT fix
-- becomes available to synchronise IMU measurements with GNSS. The
-- timestamp must wrap around to zero when reaching one week (604800
-- seconds).
-- 
-- The time-tagging mode should not change throughout a run.
Imu.MsgImuRaw = class.class(KaitaiStruct)

function Imu.MsgImuRaw:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Imu.MsgImuRaw:_read()
  self.tow = self._io:read_u4le()
  self.tow_f = self._io:read_u1()
  self.acc_x = self._io:read_s2le()
  self.acc_y = self._io:read_s2le()
  self.acc_z = self._io:read_s2le()
  self.gyr_x = self._io:read_s2le()
  self.gyr_y = self._io:read_s2le()
  self.gyr_z = self._io:read_s2le()
end

-- 
-- Milliseconds since reference epoch and time status.
-- 
-- Milliseconds since reference epoch, fractional part
-- 
-- Acceleration in the IMU frame X axis
-- 
-- Acceleration in the IMU frame Y axis
-- 
-- Acceleration in the IMU frame Z axis
-- 
-- Angular rate around IMU frame X axis
-- 
-- Angular rate around IMU frame Y axis
-- 
-- Angular rate around IMU frame Z axis

-- 
-- Auxiliary data specific to a particular IMU. The `imu_type` field will
-- always be consistent but the rest of the payload is device specific and
-- depends on the value of `imu_type`.
Imu.MsgImuAux = class.class(KaitaiStruct)

function Imu.MsgImuAux:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Imu.MsgImuAux:_read()
  self.imu_type = self._io:read_u1()
  self.temp = self._io:read_s2le()
  self.imu_conf = self._io:read_u1()
end

-- 
-- IMU type
-- 
-- Raw IMU temperature
-- 
-- IMU configuration

