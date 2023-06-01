-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

SolutionMeta = class.class(KaitaiStruct)

function SolutionMeta:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function SolutionMeta:_read()
end


-- 
-- Metadata around the GNSS sensors involved in the fuzed solution.
-- Accessible through sol_in[N].flags in a MSG_SOLN_META.
SolutionMeta.GnssInputType = class.class(KaitaiStruct)

function SolutionMeta.GnssInputType:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function SolutionMeta.GnssInputType:_read()
  self.flags = self._io:read_u1()
end

-- 
-- flags that store all relevant info specific to this sensor type.

-- 
-- This message contains all metadata about the sensors received and/or
-- used in computing the sensorfusion solution. It focuses primarily, but
-- not only, on GNSS metadata. Regarding the age of the last received valid
-- GNSS solution, the highest two bits are time status, indicating whether
-- age gnss can or can not be used to retrieve time of measurement (noted
-- TOM, also known as time of validity) If it can, subtract 'age gnss' from
-- 'tow' in navigation messages to get TOM. Can be used before alignment is
-- complete in the Fusion Engine, when output solution is the last received
-- valid GNSS solution and its tow is not a TOM.
SolutionMeta.MsgSolnMeta = class.class(KaitaiStruct)

function SolutionMeta.MsgSolnMeta:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function SolutionMeta.MsgSolnMeta:_read()
  self.tow = self._io:read_u4le()
  self.pdop = self._io:read_u2le()
  self.hdop = self._io:read_u2le()
  self.vdop = self._io:read_u2le()
  self.age_corrections = self._io:read_u2le()
  self.age_gnss = self._io:read_u4le()
  self.sol_in = {}
  local i = 0
  while not self._io:is_eof() do
    self.sol_in[i + 1] = SolutionMeta.SolutionInputType(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- GPS time of week rounded to the nearest millisecond
-- 
-- Position Dilution of Precision as per last available DOPS from PVT
-- engine (0xFFFF indicates invalid)
-- 
-- Horizontal Dilution of Precision as per last available DOPS from PVT
-- engine (0xFFFF indicates invalid)
-- 
-- Vertical Dilution of Precision as per last available DOPS from PVT
-- engine (0xFFFF indicates invalid)
-- 
-- Age of corrections as per last available AGE_CORRECTIONS from PVT
-- engine (0xFFFF indicates invalid)
-- 
-- Age and Time Status of the last received valid GNSS solution.
-- 
-- Array of Metadata describing the sensors potentially involved in the
-- solution. Each element in the array represents a single sensor type
-- and consists of flags containing (meta)data pertaining to that
-- specific single sensor. Refer to each (XX)InputType descriptor in
-- the present doc.

-- 
-- Deprecated.
SolutionMeta.MsgSolnMetaDepA = class.class(KaitaiStruct)

function SolutionMeta.MsgSolnMetaDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function SolutionMeta.MsgSolnMetaDepA:_read()
  self.pdop = self._io:read_u2le()
  self.hdop = self._io:read_u2le()
  self.vdop = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.age_corrections = self._io:read_u2le()
  self.alignment_status = self._io:read_u1()
  self.last_used_gnss_pos_tow = self._io:read_u4le()
  self.last_used_gnss_vel_tow = self._io:read_u4le()
  self.sol_in = {}
  local i = 0
  while not self._io:is_eof() do
    self.sol_in[i + 1] = SolutionMeta.SolutionInputType(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Position Dilution of Precision as per last available DOPS from PVT
-- engine (0xFFFF indicates invalid)
-- 
-- Horizontal Dilution of Precision as per last available DOPS from PVT
-- engine (0xFFFF indicates invalid)
-- 
-- Vertical Dilution of Precision as per last available DOPS from PVT
-- engine (0xFFFF indicates invalid)
-- 
-- Number of satellites as per last available solution from PVT engine
-- 
-- Age of corrections as per last available AGE_CORRECTIONS from PVT
-- engine (0xFFFF indicates invalid)
-- 
-- State of alignment and the status and receipt of the alignment
-- inputs
-- 
-- Tow of last-used GNSS position measurement
-- 
-- Tow of last-used GNSS velocity measurement
-- 
-- Array of Metadata describing the sensors potentially involved in the
-- solution. Each element in the array represents a single sensor type
-- and consists of flags containing (meta)data pertaining to that
-- specific single sensor. Refer to each (XX)InputType descriptor in
-- the present doc.

-- 
-- Metadata around the IMU sensors involved in the fuzed solution.
-- Accessible through sol_in[N].flags in a MSG_SOLN_META.
SolutionMeta.ImuInputType = class.class(KaitaiStruct)

function SolutionMeta.ImuInputType:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function SolutionMeta.ImuInputType:_read()
  self.flags = self._io:read_u1()
end

-- 
-- Instrument time, grade, and architecture for a sensor.

-- 
-- Metadata around the Odometry sensors involved in the fuzed solution.
-- Accessible through sol_in[N].flags in a MSG_SOLN_META.
SolutionMeta.OdoInputType = class.class(KaitaiStruct)

function SolutionMeta.OdoInputType:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function SolutionMeta.OdoInputType:_read()
  self.flags = self._io:read_u1()
end

-- 
-- Instrument ODO rate, grade, and quality.

-- 
-- Metadata describing which sensors were involved in the solution. The
-- structure is fixed no matter what the actual sensor type is. The
-- sensor_type field tells you which sensor we are talking about. It also
-- tells you whether the sensor data was actually used or not. The flags
-- field, always a u8, contains the sensor-specific data. The content of
-- flags, for each sensor type, is described in the relevant structures in
-- this section.
SolutionMeta.SolutionInputType = class.class(KaitaiStruct)

function SolutionMeta.SolutionInputType:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function SolutionMeta.SolutionInputType:_read()
  self.sensor_type = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- The type of sensor
-- 
-- Refer to each InputType description

