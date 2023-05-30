-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")
local str_decode = require("string_decode")

Navigation = class.class(KaitaiStruct)

function Navigation:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation:_read()
end


-- 
-- This position solution message reports the absolute geodetic coordinates
-- and the status (single point vs pseudo-absolute RTK) of the position
-- solution. If the rover receiver knows the surveyed position of the base
-- station and has an RTK solution, this reports a pseudo-absolute position
-- solution using the base station position and the rover's RTK baseline
-- vector. The full GPS time is given by the preceding MSG_GPS_TIME with
-- the matching time-of-week (tow).
Navigation.MsgPosLlhDepA = class.class(KaitaiStruct)

function Navigation.MsgPosLlhDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgPosLlhDepA:_read()
  self.tow = self._io:read_u4le()
  self.lat = self._io:read_f8le()
  self.lon = self._io:read_f8le()
  self.height = self._io:read_f8le()
  self.h_accuracy = self._io:read_u2le()
  self.v_accuracy = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Latitude
-- 
-- Longitude
-- 
-- Height
-- 
-- Horizontal position accuracy estimate (not implemented). Defaults to
-- 0.
-- 
-- Vertical position accuracy estimate (not implemented). Defaults to
-- 0.
-- 
-- Number of satellites used in solution.
-- 
-- Status flags

-- 
-- This message reports the local vertical and horizontal protection levels
-- associated with a given LLH position solution. The full GPS time is
-- given by the preceding MSG_GPS_TIME with the matching time-of-week
-- (tow).
Navigation.MsgProtectionLevelDepA = class.class(KaitaiStruct)

function Navigation.MsgProtectionLevelDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgProtectionLevelDepA:_read()
  self.tow = self._io:read_u4le()
  self.vpl = self._io:read_u2le()
  self.hpl = self._io:read_u2le()
  self.lat = self._io:read_f8le()
  self.lon = self._io:read_f8le()
  self.height = self._io:read_f8le()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Vertical protection level
-- 
-- Horizontal protection level
-- 
-- Latitude
-- 
-- Longitude
-- 
-- Height
-- 
-- Status flags

-- 
-- This position solution message reports the absolute geodetic coordinates
-- and the status (single point vs pseudo-absolute RTK) of the position
-- solution as well as the upper triangle of the 3x3 covariance matrix.
-- The position information and Fix Mode flags follow the MSG_POS_LLH
-- message.  Since the covariance matrix is computed in the local-level
-- North, East, Down frame, the covariance terms follow that convention.
-- Thus, covariances are reported against the "downward" measurement and
-- care should be taken with the sign convention.
Navigation.MsgPosLlhCov = class.class(KaitaiStruct)

function Navigation.MsgPosLlhCov:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgPosLlhCov:_read()
  self.tow = self._io:read_u4le()
  self.lat = self._io:read_f8le()
  self.lon = self._io:read_f8le()
  self.height = self._io:read_f8le()
  self.cov_n_n = self._io:read_f4le()
  self.cov_n_e = self._io:read_f4le()
  self.cov_n_d = self._io:read_f4le()
  self.cov_e_e = self._io:read_f4le()
  self.cov_e_d = self._io:read_f4le()
  self.cov_d_d = self._io:read_f4le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Latitude
-- 
-- Longitude
-- 
-- Height above WGS84 ellipsoid
-- 
-- Estimated variance of northing
-- 
-- Covariance of northing and easting
-- 
-- Covariance of northing and downward measurement
-- 
-- Estimated variance of easting
-- 
-- Covariance of easting and downward measurement
-- 
-- Estimated variance of downward measurement
-- 
-- Number of satellites used in solution.
-- 
-- Status flags

-- 
-- This message reports the velocity in local North East Down (NED)
-- coordinates. The NED coordinate system is defined as the local WGS84
-- tangent plane centered at the current position. The full GPS time is
-- given by the preceding MSG_GPS_TIME with the matching time-of-week
-- (tow).
Navigation.MsgVelNedDepA = class.class(KaitaiStruct)

function Navigation.MsgVelNedDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgVelNedDepA:_read()
  self.tow = self._io:read_u4le()
  self.n = self._io:read_s4le()
  self.e = self._io:read_s4le()
  self.d = self._io:read_s4le()
  self.h_accuracy = self._io:read_u2le()
  self.v_accuracy = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Velocity North coordinate
-- 
-- Velocity East coordinate
-- 
-- Velocity Down coordinate
-- 
-- Horizontal velocity accuracy estimate (not implemented). Defaults to
-- 0.
-- 
-- Vertical velocity accuracy estimate (not implemented). Defaults to
-- 0.
-- 
-- Number of satellites used in solution
-- 
-- Status flags (reserved)

-- 
-- This message reports the velocity in local North East Down (NED)
-- coordinates. The NED coordinate system is defined as the local WGS84
-- tangent plane centered at the current position. The full GPS time is
-- given by the preceding MSG_GPS_TIME with the matching time-of-week
-- (tow). This message is similar to the MSG_VEL_NED, but it includes the
-- upper triangular portion of the 3x3 covariance matrix.
Navigation.MsgVelNedCov = class.class(KaitaiStruct)

function Navigation.MsgVelNedCov:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgVelNedCov:_read()
  self.tow = self._io:read_u4le()
  self.n = self._io:read_s4le()
  self.e = self._io:read_s4le()
  self.d = self._io:read_s4le()
  self.cov_n_n = self._io:read_f4le()
  self.cov_n_e = self._io:read_f4le()
  self.cov_n_d = self._io:read_f4le()
  self.cov_e_e = self._io:read_f4le()
  self.cov_e_d = self._io:read_f4le()
  self.cov_d_d = self._io:read_f4le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Velocity North coordinate
-- 
-- Velocity East coordinate
-- 
-- Velocity Down coordinate
-- 
-- Estimated variance of northward measurement
-- 
-- Covariance of northward and eastward measurement
-- 
-- Covariance of northward and downward measurement
-- 
-- Estimated variance of eastward measurement
-- 
-- Covariance of eastward and downward measurement
-- 
-- Estimated variance of downward measurement
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- This message reports the Universal Coordinated Time (UTC).  Note the
-- flags which indicate the source of the UTC offset value and source of
-- the time fix.
Navigation.MsgUtcTime = class.class(KaitaiStruct)

function Navigation.MsgUtcTime:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgUtcTime:_read()
  self.flags = self._io:read_u1()
  self.tow = self._io:read_u4le()
  self.year = self._io:read_u2le()
  self.month = self._io:read_u1()
  self.day = self._io:read_u1()
  self.hours = self._io:read_u1()
  self.minutes = self._io:read_u1()
  self.seconds = self._io:read_u1()
  self.ns = self._io:read_u4le()
end

-- 
-- Indicates source and time validity
-- 
-- GPS time of week rounded to the nearest millisecond
-- 
-- Year
-- 
-- Month (range 1 .. 12)
-- 
-- days in the month (range 1-31)
-- 
-- hours of day (range 0-23)
-- 
-- minutes of hour (range 0-59)
-- 
-- seconds of minute (range 0-60) rounded down
-- 
-- nanoseconds of second (range 0-999999999)

-- 
-- The position solution message reports absolute Earth Centered Earth
-- Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
-- RTK) of the position solution. The message also reports the upper
-- triangular portion of the 3x3 covariance matrix. If the receiver knows
-- the surveyed position of the base station and has an RTK solution, this
-- reports a pseudo-absolute position solution using the base station
-- position and the rover's RTK baseline vector. The full GPS time is given
-- by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
Navigation.MsgPosEcefCovGnss = class.class(KaitaiStruct)

function Navigation.MsgPosEcefCovGnss:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgPosEcefCovGnss:_read()
  self.tow = self._io:read_u4le()
  self.x = self._io:read_f8le()
  self.y = self._io:read_f8le()
  self.z = self._io:read_f8le()
  self.cov_x_x = self._io:read_f4le()
  self.cov_x_y = self._io:read_f4le()
  self.cov_x_z = self._io:read_f4le()
  self.cov_y_y = self._io:read_f4le()
  self.cov_y_z = self._io:read_f4le()
  self.cov_z_z = self._io:read_f4le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- ECEF X coordinate
-- 
-- ECEF Y coordinate
-- 
-- ECEF Z coordinate
-- 
-- Estimated variance of x
-- 
-- Estimated covariance of x and y
-- 
-- Estimated covariance of x and z
-- 
-- Estimated variance of y
-- 
-- Estimated covariance of y and z
-- 
-- Estimated variance of z
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- This message reports the velocity in local North East Down (NED)
-- coordinates. The NED coordinate system is defined as the local WGS84
-- tangent plane centered at the current position. The full GPS time is
-- given by the preceding MSG_GPS_TIME with the matching time-of-week
-- (tow).
Navigation.MsgVelNedGnss = class.class(KaitaiStruct)

function Navigation.MsgVelNedGnss:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgVelNedGnss:_read()
  self.tow = self._io:read_u4le()
  self.n = self._io:read_s4le()
  self.e = self._io:read_s4le()
  self.d = self._io:read_s4le()
  self.h_accuracy = self._io:read_u2le()
  self.v_accuracy = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Velocity North coordinate
-- 
-- Velocity East coordinate
-- 
-- Velocity Down coordinate
-- 
-- Horizontal velocity estimated standard deviation
-- 
-- Vertical velocity estimated standard deviation
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- This message reports the velocity in local North East Down (NED)
-- coordinates. The NED coordinate system is defined as the local WGS84
-- tangent plane centered at the current position. The full GPS time is
-- given by the preceding MSG_GPS_TIME with the matching time-of-week
-- (tow). This message is similar to the MSG_VEL_NED, but it includes the
-- upper triangular portion of the 3x3 covariance matrix.
Navigation.MsgVelNedCovGnss = class.class(KaitaiStruct)

function Navigation.MsgVelNedCovGnss:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgVelNedCovGnss:_read()
  self.tow = self._io:read_u4le()
  self.n = self._io:read_s4le()
  self.e = self._io:read_s4le()
  self.d = self._io:read_s4le()
  self.cov_n_n = self._io:read_f4le()
  self.cov_n_e = self._io:read_f4le()
  self.cov_n_d = self._io:read_f4le()
  self.cov_e_e = self._io:read_f4le()
  self.cov_e_d = self._io:read_f4le()
  self.cov_d_d = self._io:read_f4le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Velocity North coordinate
-- 
-- Velocity East coordinate
-- 
-- Velocity Down coordinate
-- 
-- Estimated variance of northward measurement
-- 
-- Covariance of northward and eastward measurement
-- 
-- Covariance of northward and downward measurement
-- 
-- Estimated variance of eastward measurement
-- 
-- Covariance of eastward and downward measurement
-- 
-- Estimated variance of downward measurement
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- This message reports the baseline solution in North East Down (NED)
-- coordinates. This baseline is the relative vector distance from the base
-- station to the rover receiver, and NED coordinate system is defined at
-- the local WGS84 tangent plane centered at the base station position.
-- The full GPS time is given by the preceding MSG_GPS_TIME with the
-- matching time-of-week (tow).
Navigation.MsgBaselineNedDepA = class.class(KaitaiStruct)

function Navigation.MsgBaselineNedDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgBaselineNedDepA:_read()
  self.tow = self._io:read_u4le()
  self.n = self._io:read_s4le()
  self.e = self._io:read_s4le()
  self.d = self._io:read_s4le()
  self.h_accuracy = self._io:read_u2le()
  self.v_accuracy = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Baseline North coordinate
-- 
-- Baseline East coordinate
-- 
-- Baseline Down coordinate
-- 
-- Horizontal position accuracy estimate (not implemented). Defaults to
-- 0.
-- 
-- Vertical position accuracy estimate (not implemented). Defaults to
-- 0.
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- This message reports the velocity in Earth Centered Earth Fixed (ECEF)
-- coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
-- with the matching time-of-week (tow).
Navigation.MsgVelEcefDepA = class.class(KaitaiStruct)

function Navigation.MsgVelEcefDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgVelEcefDepA:_read()
  self.tow = self._io:read_u4le()
  self.x = self._io:read_s4le()
  self.y = self._io:read_s4le()
  self.z = self._io:read_s4le()
  self.accuracy = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Velocity ECEF X coordinate
-- 
-- Velocity ECEF Y coordinate
-- 
-- Velocity ECEF Z coordinate
-- 
-- Velocity accuracy estimate (not implemented). Defaults to 0.
-- 
-- Number of satellites used in solution
-- 
-- Status flags (reserved)

Navigation.MsgReferenceFrameParam = class.class(KaitaiStruct)

function Navigation.MsgReferenceFrameParam:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgReferenceFrameParam:_read()
  self.ssr_iod = self._io:read_u1()
  self.sn = str_decode.decode(self._io:read_bytes_full(), "ascii")
  self.tn = str_decode.decode(self._io:read_bytes_full(), "ascii")
  self.sin = self._io:read_u1()
  self.utn = self._io:read_u2le()
  self.re_t0 = self._io:read_u2le()
  self.delta_x0 = self._io:read_s4le()
  self.delta_y0 = self._io:read_s4le()
  self.delta_z0 = self._io:read_s4le()
  self.theta_01 = self._io:read_s4le()
  self.theta_02 = self._io:read_s4le()
  self.theta_03 = self._io:read_s4le()
  self.scale = self._io:read_s4le()
  self.dot_delta_x0 = self._io:read_s4le()
  self.dot_delta_y0 = self._io:read_s4le()
  self.dot_delta_z0 = self._io:read_s4le()
  self.dot_theta_01 = self._io:read_s4le()
  self.dot_theta_02 = self._io:read_s4le()
  self.dot_theta_03 = self._io:read_s4le()
  self.dot_scale = self._io:read_s2le()
end

-- 
-- SSR IOD parameter.
-- 
-- Name of source coordinate-system.
-- 
-- Name of target coordinate-system.
-- 
-- System Identification Number.
-- 
-- Utilized Transformation Message.
-- 
-- Reference Epoch t0 for transformation parameter set given as
-- Modified Julian Day (MJD) Number minus 44244 days.
-- 
-- Translation in X for Reference Epoch t0.
-- 
-- Translation in Y for Reference Epoch t0.
-- 
-- Translation in Z for Reference Epoch t0.
-- 
-- Rotation around the X-axis for Reference Epoch t0.
-- 
-- Rotation around the Y-axis for Reference Epoch t0.
-- 
-- Rotation around the Z-axis for Reference Epoch t0.
-- 
-- Scale correction for Reference Epoch t0.
-- 
-- Rate of change of translation in X.
-- 
-- Rate of change of translation in Y.
-- 
-- Rate of change of translation in Z.
-- 
-- Rate of change of rotation around the X-axis.
-- 
-- Rate of change of rotation around the Y-axis.
-- 
-- Rate of change of rotation around the Z-axis.
-- 
-- Rate of change of scale correction.

-- 
-- This solution message reports the relative pose of a sensor between two
-- time instances. The relative pose comprises of a rotation and a
-- translation which relates the sensor (e.g. camera) frame at a given time
-- (first keyframe) to the sensor frame at another time (second keyframe).
-- The relative translations is a 3x1 vector described in the first
-- keyframe.  Relative rotation is described by a quaternion from second
-- keyframe to the first keyframe.
Navigation.MsgPoseRelative = class.class(KaitaiStruct)

function Navigation.MsgPoseRelative:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgPoseRelative:_read()
  self.tow = self._io:read_u4le()
  self.sensor_id = self._io:read_u1()
  self.timestamp_1 = self._io:read_u4le()
  self.timestamp_2 = self._io:read_u4le()
  self.trans = {}
  for i = 0, 3 - 1 do
    self.trans[i + 1] = self._io:read_s4le()
  end
  self.w = self._io:read_s4le()
  self.x = self._io:read_s4le()
  self.y = self._io:read_s4le()
  self.z = self._io:read_s4le()
  self.cov_r_x_x = self._io:read_f4le()
  self.cov_r_x_y = self._io:read_f4le()
  self.cov_r_x_z = self._io:read_f4le()
  self.cov_r_y_y = self._io:read_f4le()
  self.cov_r_y_z = self._io:read_f4le()
  self.cov_r_z_z = self._io:read_f4le()
  self.cov_c_x_x = self._io:read_f4le()
  self.cov_c_x_y = self._io:read_f4le()
  self.cov_c_x_z = self._io:read_f4le()
  self.cov_c_y_y = self._io:read_f4le()
  self.cov_c_y_z = self._io:read_f4le()
  self.cov_c_z_z = self._io:read_f4le()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- ID of the sensor producing this message
-- 
-- Timestamp of first keyframe
-- 
-- Timestamp of second keyframe
-- 
-- Relative translation [x,y,z] described in first keyframe
-- 
-- Real component of quaternion to describe relative rotation (second
-- to first keyframe)
-- 
-- 1st imaginary component of quaternion to describe relative rotation
-- (second to first keyframe)
-- 
-- 2nd imaginary component of quaternion to describe relative rotation
-- (second to first keyframe)
-- 
-- 3rd imaginary component of quaternion to describe relative rotation
-- (second to first keyframe)
-- 
-- Estimated variance of x (relative translation)
-- 
-- Covariance of x and y (relative translation)
-- 
-- Covariance of x and z (relative translation)
-- 
-- Estimated variance of y (relative translation)
-- 
-- Covariance of y and z (relative translation)
-- 
-- Estimated variance of z (relative translation)
-- 
-- Estimated variance of x (relative rotation)
-- 
-- Covariance of x and y (relative rotation)
-- 
-- Covariance of x and z (relative rotation)
-- 
-- Estimated variance of y (relative rotation)
-- 
-- Covariance of y and z (relative rotation)
-- 
-- Estimated variance of z (relative rotation)
-- 
-- Status flags of relative translation and rotation

-- 
-- This message reports the velocity in Earth Centered Earth Fixed (ECEF)
-- coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
-- with the matching time-of-week (tow).
Navigation.MsgVelEcefCov = class.class(KaitaiStruct)

function Navigation.MsgVelEcefCov:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgVelEcefCov:_read()
  self.tow = self._io:read_u4le()
  self.x = self._io:read_s4le()
  self.y = self._io:read_s4le()
  self.z = self._io:read_s4le()
  self.cov_x_x = self._io:read_f4le()
  self.cov_x_y = self._io:read_f4le()
  self.cov_x_z = self._io:read_f4le()
  self.cov_y_y = self._io:read_f4le()
  self.cov_y_z = self._io:read_f4le()
  self.cov_z_z = self._io:read_f4le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Velocity ECEF X coordinate
-- 
-- Velocity ECEF Y coordinate
-- 
-- Velocity ECEF Z coordinate
-- 
-- Estimated variance of x
-- 
-- Estimated covariance of x and y
-- 
-- Estimated covariance of x and z
-- 
-- Estimated variance of y
-- 
-- Estimated covariance of y and z
-- 
-- Estimated variance of z
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- This message reports the velocity in the Vehicle Body Frame. By
-- convention, the x-axis should point out the nose of the vehicle and
-- represent the forward direction, while as the y-axis should point out
-- the right hand side of the vehicle. Since this is a right handed system,
-- z should point out the bottom of the vehicle. The orientation and origin
-- of the Vehicle Body Frame are specified via the device settings. The
-- full GPS time is given by the preceding MSG_GPS_TIME with the matching
-- time-of-week (tow). This message is only produced by inertial versions
-- of Swift products and is not available from Piksi Multi or Duro.
Navigation.MsgVelBody = class.class(KaitaiStruct)

function Navigation.MsgVelBody:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgVelBody:_read()
  self.tow = self._io:read_u4le()
  self.x = self._io:read_s4le()
  self.y = self._io:read_s4le()
  self.z = self._io:read_s4le()
  self.cov_x_x = self._io:read_f4le()
  self.cov_x_y = self._io:read_f4le()
  self.cov_x_z = self._io:read_f4le()
  self.cov_y_y = self._io:read_f4le()
  self.cov_y_z = self._io:read_f4le()
  self.cov_z_z = self._io:read_f4le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Velocity in x direction
-- 
-- Velocity in y direction
-- 
-- Velocity in z direction
-- 
-- Estimated variance of x
-- 
-- Covariance of x and y
-- 
-- Covariance of x and z
-- 
-- Estimated variance of y
-- 
-- Covariance of y and z
-- 
-- Estimated variance of z
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- This message reports the velocity in Earth Centered Earth Fixed (ECEF)
-- coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
-- with the matching time-of-week (tow).
Navigation.MsgVelEcefGnss = class.class(KaitaiStruct)

function Navigation.MsgVelEcefGnss:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgVelEcefGnss:_read()
  self.tow = self._io:read_u4le()
  self.x = self._io:read_s4le()
  self.y = self._io:read_s4le()
  self.z = self._io:read_s4le()
  self.accuracy = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Velocity ECEF X coordinate
-- 
-- Velocity ECEF Y coordinate
-- 
-- Velocity ECEF Z coordinate
-- 
-- Velocity estimated standard deviation
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- This message reports the velocity in Earth Centered Earth Fixed (ECEF)
-- coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
-- with the matching time-of-week (tow).
Navigation.MsgVelEcef = class.class(KaitaiStruct)

function Navigation.MsgVelEcef:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgVelEcef:_read()
  self.tow = self._io:read_u4le()
  self.x = self._io:read_s4le()
  self.y = self._io:read_s4le()
  self.z = self._io:read_s4le()
  self.accuracy = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Velocity ECEF X coordinate
-- 
-- Velocity ECEF Y coordinate
-- 
-- Velocity ECEF Z coordinate
-- 
-- Velocity estimated standard deviation
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- This position solution message reports the absolute geodetic coordinates
-- and the status (single point vs pseudo-absolute RTK) of the position
-- solution as well as the upper triangle of the 3x3 covariance matrix.
-- The position information and Fix Mode flags should follow the
-- MSG_POS_LLH message.  Since the covariance matrix is computed in the
-- local-level North, East, Down frame, the covariance terms follow with
-- that convention. Thus, covariances are reported against the "downward"
-- measurement and care should be taken with the sign convention.
Navigation.MsgPosLlhCovGnss = class.class(KaitaiStruct)

function Navigation.MsgPosLlhCovGnss:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgPosLlhCovGnss:_read()
  self.tow = self._io:read_u4le()
  self.lat = self._io:read_f8le()
  self.lon = self._io:read_f8le()
  self.height = self._io:read_f8le()
  self.cov_n_n = self._io:read_f4le()
  self.cov_n_e = self._io:read_f4le()
  self.cov_n_d = self._io:read_f4le()
  self.cov_e_e = self._io:read_f4le()
  self.cov_e_d = self._io:read_f4le()
  self.cov_d_d = self._io:read_f4le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Latitude
-- 
-- Longitude
-- 
-- Height above WGS84 ellipsoid
-- 
-- Estimated variance of northing
-- 
-- Covariance of northing and easting
-- 
-- Covariance of northing and downward measurement
-- 
-- Estimated variance of easting
-- 
-- Covariance of easting and downward measurement
-- 
-- Estimated variance of downward measurement
-- 
-- Number of satellites used in solution.
-- 
-- Status flags

-- 
-- This message reports the baseline solution in Earth Centered Earth Fixed
-- (ECEF) coordinates. This baseline is the relative vector distance from
-- the base station to the rover receiver. The full GPS time is given by
-- the preceding MSG_GPS_TIME with the matching time-of-week (tow).
Navigation.MsgBaselineEcef = class.class(KaitaiStruct)

function Navigation.MsgBaselineEcef:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgBaselineEcef:_read()
  self.tow = self._io:read_u4le()
  self.x = self._io:read_s4le()
  self.y = self._io:read_s4le()
  self.z = self._io:read_s4le()
  self.accuracy = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Baseline ECEF X coordinate
-- 
-- Baseline ECEF Y coordinate
-- 
-- Baseline ECEF Z coordinate
-- 
-- Position estimated standard deviation
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- This dilution of precision (DOP) message describes the effect of
-- navigation satellite geometry on positional measurement precision.
Navigation.MsgDopsDepA = class.class(KaitaiStruct)

function Navigation.MsgDopsDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgDopsDepA:_read()
  self.tow = self._io:read_u4le()
  self.gdop = self._io:read_u2le()
  self.pdop = self._io:read_u2le()
  self.tdop = self._io:read_u2le()
  self.hdop = self._io:read_u2le()
  self.vdop = self._io:read_u2le()
end

-- 
-- GPS Time of Week
-- 
-- Geometric Dilution of Precision
-- 
-- Position Dilution of Precision
-- 
-- Time Dilution of Precision
-- 
-- Horizontal Dilution of Precision
-- 
-- Vertical Dilution of Precision

-- 
-- The position solution message reports absolute Earth Centered Earth
-- Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
-- RTK) of the position solution. If the rover receiver knows the surveyed
-- position of the base station and has an RTK solution, this reports a
-- pseudo-absolute position solution using the base station position and
-- the rover's RTK baseline vector. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow).
Navigation.MsgPosEcef = class.class(KaitaiStruct)

function Navigation.MsgPosEcef:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgPosEcef:_read()
  self.tow = self._io:read_u4le()
  self.x = self._io:read_f8le()
  self.y = self._io:read_f8le()
  self.z = self._io:read_f8le()
  self.accuracy = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- ECEF X coordinate
-- 
-- ECEF Y coordinate
-- 
-- ECEF Z coordinate
-- 
-- Position estimated standard deviation
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- This message reports the Age of the corrections used for the current
-- Differential solution.
Navigation.MsgAgeCorrections = class.class(KaitaiStruct)

function Navigation.MsgAgeCorrections:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgAgeCorrections:_read()
  self.tow = self._io:read_u4le()
  self.age = self._io:read_u2le()
end

-- 
-- GPS Time of Week
-- 
-- Age of the corrections (0xFFFF indicates invalid)

-- 
-- This message reports the velocity in Earth Centered Earth Fixed (ECEF)
-- coordinates. The full GPS time is given by the preceding MSG_GPS_TIME
-- with the matching time-of-week (tow).
Navigation.MsgVelEcefCovGnss = class.class(KaitaiStruct)

function Navigation.MsgVelEcefCovGnss:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgVelEcefCovGnss:_read()
  self.tow = self._io:read_u4le()
  self.x = self._io:read_s4le()
  self.y = self._io:read_s4le()
  self.z = self._io:read_s4le()
  self.cov_x_x = self._io:read_f4le()
  self.cov_x_y = self._io:read_f4le()
  self.cov_x_z = self._io:read_f4le()
  self.cov_y_y = self._io:read_f4le()
  self.cov_y_z = self._io:read_f4le()
  self.cov_z_z = self._io:read_f4le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Velocity ECEF X coordinate
-- 
-- Velocity ECEF Y coordinate
-- 
-- Velocity ECEF Z coordinate
-- 
-- Estimated variance of x
-- 
-- Estimated covariance of x and y
-- 
-- Estimated covariance of x and z
-- 
-- Estimated variance of y
-- 
-- Estimated covariance of y and z
-- 
-- Estimated variance of z
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- This message reports the protection levels associated to the given state
-- estimate. The full GPS time is given by the preceding MSG_GPS_TIME with
-- the matching time-of-week (tow).
Navigation.MsgProtectionLevel = class.class(KaitaiStruct)

function Navigation.MsgProtectionLevel:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgProtectionLevel:_read()
  self.tow = self._io:read_u4le()
  self.wn = self._io:read_s2le()
  self.hpl = self._io:read_u2le()
  self.vpl = self._io:read_u2le()
  self.atpl = self._io:read_u2le()
  self.ctpl = self._io:read_u2le()
  self.hvpl = self._io:read_u2le()
  self.vvpl = self._io:read_u2le()
  self.hopl = self._io:read_u2le()
  self.popl = self._io:read_u2le()
  self.ropl = self._io:read_u2le()
  self.lat = self._io:read_f8le()
  self.lon = self._io:read_f8le()
  self.height = self._io:read_f8le()
  self.v_x = self._io:read_s4le()
  self.v_y = self._io:read_s4le()
  self.v_z = self._io:read_s4le()
  self.roll = self._io:read_s4le()
  self.pitch = self._io:read_s4le()
  self.heading = self._io:read_s4le()
  self.flags = self._io:read_u4le()
end

-- 
-- GPS Time of Week
-- 
-- GPS week number
-- 
-- Horizontal protection level
-- 
-- Vertical protection level
-- 
-- Along-track position error protection level
-- 
-- Cross-track position error protection level
-- 
-- Protection level for the error vector between estimated and true
-- along/cross track velocity vector
-- 
-- Protection level for the velocity in vehicle upright direction
-- (different from vertical direction if on a slope)
-- 
-- Heading orientation protection level
-- 
-- Pitch orientation protection level
-- 
-- Roll orientation protection level
-- 
-- Latitude
-- 
-- Longitude
-- 
-- Height
-- 
-- Velocity in vehicle x direction
-- 
-- Velocity in vehicle y direction
-- 
-- Velocity in vehicle z direction
-- 
-- Roll angle
-- 
-- Pitch angle
-- 
-- Heading angle
-- 
-- Status flags

-- 
-- The position solution message reports absolute Earth Centered Earth
-- Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
-- RTK) of the position solution. The message also reports the upper
-- triangular portion of the 3x3 covariance matrix. If the receiver knows
-- the surveyed position of the base station and has an RTK solution, this
-- reports a pseudo-absolute position solution using the base station
-- position and the rover's RTK baseline vector. The full GPS time is given
-- by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
Navigation.MsgPosEcefCov = class.class(KaitaiStruct)

function Navigation.MsgPosEcefCov:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgPosEcefCov:_read()
  self.tow = self._io:read_u4le()
  self.x = self._io:read_f8le()
  self.y = self._io:read_f8le()
  self.z = self._io:read_f8le()
  self.cov_x_x = self._io:read_f4le()
  self.cov_x_y = self._io:read_f4le()
  self.cov_x_z = self._io:read_f4le()
  self.cov_y_y = self._io:read_f4le()
  self.cov_y_z = self._io:read_f4le()
  self.cov_z_z = self._io:read_f4le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- ECEF X coordinate
-- 
-- ECEF Y coordinate
-- 
-- ECEF Z coordinate
-- 
-- Estimated variance of x
-- 
-- Estimated covariance of x and y
-- 
-- Estimated covariance of x and z
-- 
-- Estimated variance of y
-- 
-- Estimated covariance of y and z
-- 
-- Estimated variance of z
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- The position solution message reports absolute Earth Centered Earth
-- Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
-- RTK) of the position solution. If the rover receiver knows the surveyed
-- position of the base station and has an RTK solution, this reports a
-- pseudo-absolute position solution using the base station position and
-- the rover's RTK baseline vector. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow).
Navigation.MsgPosEcefGnss = class.class(KaitaiStruct)

function Navigation.MsgPosEcefGnss:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgPosEcefGnss:_read()
  self.tow = self._io:read_u4le()
  self.x = self._io:read_f8le()
  self.y = self._io:read_f8le()
  self.z = self._io:read_f8le()
  self.accuracy = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- ECEF X coordinate
-- 
-- ECEF Y coordinate
-- 
-- ECEF Z coordinate
-- 
-- Position estimated standard deviation
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- This message reports the velocity in local North East Down (NED)
-- coordinates. The NED coordinate system is defined as the local WGS84
-- tangent plane centered at the current position. The full GPS time is
-- given by the preceding MSG_GPS_TIME with the matching time-of-week
-- (tow).
Navigation.MsgVelNed = class.class(KaitaiStruct)

function Navigation.MsgVelNed:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgVelNed:_read()
  self.tow = self._io:read_u4le()
  self.n = self._io:read_s4le()
  self.e = self._io:read_s4le()
  self.d = self._io:read_s4le()
  self.h_accuracy = self._io:read_u2le()
  self.v_accuracy = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Velocity North coordinate
-- 
-- Velocity East coordinate
-- 
-- Velocity Down coordinate
-- 
-- Horizontal velocity estimated standard deviation
-- 
-- Vertical velocity estimated standard deviation
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- UTC-GPST leap seconds before and after the most recent (past, or future,
-- for announced insertions) UTC leap second insertion.
Navigation.MsgUtcLeapSecond = class.class(KaitaiStruct)

function Navigation.MsgUtcLeapSecond:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgUtcLeapSecond:_read()
  self.reserved_0 = self._io:read_s2le()
  self.reserved_1 = self._io:read_s2le()
  self.reserved_2 = self._io:read_s1()
  self.count_before = self._io:read_s1()
  self.reserved_3 = self._io:read_u2le()
  self.reserved_4 = self._io:read_u2le()
  self.ref_wn = self._io:read_u2le()
  self.ref_dn = self._io:read_u1()
  self.count_after = self._io:read_s1()
end

-- 
-- Reserved.
-- 
-- Reserved.
-- 
-- Reserved.
-- 
-- Leap second count before insertion.
-- 
-- Reserved.
-- 
-- Reserved.
-- 
-- Leap second reference GPS week number.
-- 
-- Leap second reference day number.
-- 
-- Leap second count after insertion.

-- 
-- This message reports the GPS time, representing the time since the GPS
-- epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
-- and seconds of the week. The weeks begin at the Saturday/Sunday
-- transition. GPS week 0 began at the beginning of the GPS time scale.
-- 
-- Within each week number, the GPS time of the week is between between 0
-- and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
-- leap seconds, and as of now, has a small offset from UTC. In a message
-- stream, this message precedes a set of other navigation messages
-- referenced to the same time (but lacking the ns field) and indicates a
-- more precise time of these messages.
Navigation.MsgGpsTimeDepA = class.class(KaitaiStruct)

function Navigation.MsgGpsTimeDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgGpsTimeDepA:_read()
  self.wn = self._io:read_u2le()
  self.tow = self._io:read_u4le()
  self.ns_residual = self._io:read_s4le()
  self.flags = self._io:read_u1()
end

-- 
-- GPS week number
-- 
-- GPS time of week rounded to the nearest millisecond
-- 
-- Nanosecond residual of millisecond-rounded TOW (ranges from -500000
-- to 500000)
-- 
-- Status flags (reserved)

-- 
-- This position solution message reports the absolute geodetic coordinates
-- and the status (single point vs pseudo-absolute RTK) of the position
-- solution. If the rover receiver knows the surveyed position of the base
-- station and has an RTK solution, this reports a pseudo-absolute position
-- solution using the base station position and the rover's RTK baseline
-- vector. The full GPS time is given by the preceding MSG_GPS_TIME with
-- the matching time-of-week (tow).
Navigation.MsgPosLlhGnss = class.class(KaitaiStruct)

function Navigation.MsgPosLlhGnss:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgPosLlhGnss:_read()
  self.tow = self._io:read_u4le()
  self.lat = self._io:read_f8le()
  self.lon = self._io:read_f8le()
  self.height = self._io:read_f8le()
  self.h_accuracy = self._io:read_u2le()
  self.v_accuracy = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Latitude
-- 
-- Longitude
-- 
-- Height above WGS84 ellipsoid
-- 
-- Horizontal position estimated standard deviation
-- 
-- Vertical position estimated standard deviation
-- 
-- Number of satellites used in solution.
-- 
-- Status flags

-- 
-- This message reports the Universal Coordinated Time (UTC).  Note the
-- flags which indicate the source of the UTC offset value and source of
-- the time fix.
Navigation.MsgUtcTimeGnss = class.class(KaitaiStruct)

function Navigation.MsgUtcTimeGnss:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgUtcTimeGnss:_read()
  self.flags = self._io:read_u1()
  self.tow = self._io:read_u4le()
  self.year = self._io:read_u2le()
  self.month = self._io:read_u1()
  self.day = self._io:read_u1()
  self.hours = self._io:read_u1()
  self.minutes = self._io:read_u1()
  self.seconds = self._io:read_u1()
  self.ns = self._io:read_u4le()
end

-- 
-- Indicates source and time validity
-- 
-- GPS time of week rounded to the nearest millisecond
-- 
-- Year
-- 
-- Month (range 1 .. 12)
-- 
-- days in the month (range 1-31)
-- 
-- hours of day (range 0-23)
-- 
-- minutes of hour (range 0-59)
-- 
-- seconds of minute (range 0-60) rounded down
-- 
-- nanoseconds of second (range 0-999999999)

-- 
-- This message reports the receiver course over ground (COG) and speed
-- over  ground (SOG) based on the horizontal (N-E) components of the NED
-- velocity  vector. It also includes the vertical velocity coordinate. A
-- flag is provided to indicate whether the COG value has been frozen. When
-- the flag is set to true, the COG field is set to its last valid value
-- until  the system exceeds a minimum velocity threshold. No other fields
-- are  affected by this flag.  The NED coordinate system is defined as the
-- local WGS84 tangent  plane centered at the current position. The full
-- GPS time is given by the  preceding MSG_GPS_TIME with the matching time-
-- of-week (tow). Note: course over ground represents the receiver's
-- direction of travel,  but not necessarily the device heading.
Navigation.MsgVelCog = class.class(KaitaiStruct)

function Navigation.MsgVelCog:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgVelCog:_read()
  self.tow = self._io:read_u4le()
  self.cog = self._io:read_u4le()
  self.sog = self._io:read_u4le()
  self.v_up = self._io:read_s4le()
  self.cog_accuracy = self._io:read_u4le()
  self.sog_accuracy = self._io:read_u4le()
  self.v_up_accuracy = self._io:read_u4le()
  self.flags = self._io:read_u2le()
end

-- 
-- GPS Time of Week
-- 
-- Course over ground relative to north direction
-- 
-- Speed over ground (based on horizontal velocity)
-- 
-- Vertical velocity component (positive up)
-- 
-- Course over ground estimated standard deviation
-- 
-- Speed over ground estimated standard deviation
-- 
-- Vertical velocity estimated standard deviation
-- 
-- Status flags

-- 
-- This message reports the baseline solution in North East Down (NED)
-- coordinates. This baseline is the relative vector distance from the base
-- station to the rover receiver, and NED coordinate system is defined at
-- the local WGS84 tangent plane centered at the base station position.
-- The full GPS time is given by the preceding MSG_GPS_TIME with the
-- matching time-of-week (tow).
Navigation.MsgBaselineNed = class.class(KaitaiStruct)

function Navigation.MsgBaselineNed:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgBaselineNed:_read()
  self.tow = self._io:read_u4le()
  self.n = self._io:read_s4le()
  self.e = self._io:read_s4le()
  self.d = self._io:read_s4le()
  self.h_accuracy = self._io:read_u2le()
  self.v_accuracy = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Baseline North coordinate
-- 
-- Baseline East coordinate
-- 
-- Baseline Down coordinate
-- 
-- Horizontal position estimated standard deviation
-- 
-- Vertical position estimated standard deviation
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- This position solution message reports the absolute geodetic coordinates
-- and the status (single point vs pseudo-absolute RTK) of the position
-- solution. If the rover receiver knows the surveyed position of the base
-- station and has an RTK solution, this reports a pseudo-absolute position
-- solution using the base station position and the rover's RTK baseline
-- vector. The full GPS time is given by the preceding MSG_GPS_TIME with
-- the matching time-of-week (tow).
Navigation.MsgPosLlh = class.class(KaitaiStruct)

function Navigation.MsgPosLlh:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgPosLlh:_read()
  self.tow = self._io:read_u4le()
  self.lat = self._io:read_f8le()
  self.lon = self._io:read_f8le()
  self.height = self._io:read_f8le()
  self.h_accuracy = self._io:read_u2le()
  self.v_accuracy = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Latitude
-- 
-- Longitude
-- 
-- Height above WGS84 ellipsoid
-- 
-- Horizontal position estimated standard deviation
-- 
-- Vertical position estimated standard deviation
-- 
-- Number of satellites used in solution.
-- 
-- Status flags

-- 
-- This message reports the baseline heading pointing from the base station
-- to the rover relative to True North. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow).
Navigation.MsgBaselineHeadingDepA = class.class(KaitaiStruct)

function Navigation.MsgBaselineHeadingDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgBaselineHeadingDepA:_read()
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
-- This message reports the GPS time, representing the time since the GPS
-- epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
-- and seconds of the week. The weeks begin at the Saturday/Sunday
-- transition. GPS week 0 began at the beginning of the GPS time scale.
-- 
-- Within each week number, the GPS time of the week is between between 0
-- and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
-- leap seconds, and as of now, has a small offset from UTC. In a message
-- stream, this message precedes a set of other navigation messages
-- referenced to the same time (but lacking the ns field) and indicates a
-- more precise time of these messages.
Navigation.MsgGpsTimeGnss = class.class(KaitaiStruct)

function Navigation.MsgGpsTimeGnss:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgGpsTimeGnss:_read()
  self.wn = self._io:read_u2le()
  self.tow = self._io:read_u4le()
  self.ns_residual = self._io:read_s4le()
  self.flags = self._io:read_u1()
end

-- 
-- GPS week number
-- 
-- GPS time of week rounded to the nearest millisecond
-- 
-- Nanosecond residual of millisecond-rounded TOW (ranges from -500000
-- to 500000)
-- 
-- Status flags (reserved)

-- 
-- This message reports the baseline solution in Earth Centered Earth Fixed
-- (ECEF) coordinates. This baseline is the relative vector distance from
-- the base station to the rover receiver. The full GPS time is given by
-- the preceding MSG_GPS_TIME with the matching time-of-week (tow).
Navigation.MsgBaselineEcefDepA = class.class(KaitaiStruct)

function Navigation.MsgBaselineEcefDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgBaselineEcefDepA:_read()
  self.tow = self._io:read_u4le()
  self.x = self._io:read_s4le()
  self.y = self._io:read_s4le()
  self.z = self._io:read_s4le()
  self.accuracy = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Baseline ECEF X coordinate
-- 
-- Baseline ECEF Y coordinate
-- 
-- Baseline ECEF Z coordinate
-- 
-- Position accuracy estimate
-- 
-- Number of satellites used in solution
-- 
-- Status flags

-- 
-- This message reports the GPS time, representing the time since the GPS
-- epoch began on midnight January 6, 1980 UTC. GPS time counts the weeks
-- and seconds of the week. The weeks begin at the Saturday/Sunday
-- transition. GPS week 0 began at the beginning of the GPS time scale.
-- 
-- Within each week number, the GPS time of the week is between between 0
-- and 604800 seconds (=60*60*24*7). Note that GPS time does not accumulate
-- leap seconds, and as of now, has a small offset from UTC. In a message
-- stream, this message precedes a set of other navigation messages
-- referenced to the same time (but lacking the ns field) and indicates a
-- more precise time of these messages.
Navigation.MsgGpsTime = class.class(KaitaiStruct)

function Navigation.MsgGpsTime:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgGpsTime:_read()
  self.wn = self._io:read_u2le()
  self.tow = self._io:read_u4le()
  self.ns_residual = self._io:read_s4le()
  self.flags = self._io:read_u1()
end

-- 
-- GPS week number
-- 
-- GPS time of week rounded to the nearest millisecond
-- 
-- Nanosecond residual of millisecond-rounded TOW (ranges from -500000
-- to 500000)
-- 
-- Status flags (reserved)

-- 
-- This dilution of precision (DOP) message describes the effect of
-- navigation satellite geometry on positional measurement precision.  The
-- flags field indicated whether the DOP reported corresponds to
-- differential or SPP solution.
Navigation.MsgDops = class.class(KaitaiStruct)

function Navigation.MsgDops:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgDops:_read()
  self.tow = self._io:read_u4le()
  self.gdop = self._io:read_u2le()
  self.pdop = self._io:read_u2le()
  self.tdop = self._io:read_u2le()
  self.hdop = self._io:read_u2le()
  self.vdop = self._io:read_u2le()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Geometric Dilution of Precision
-- 
-- Position Dilution of Precision
-- 
-- Time Dilution of Precision
-- 
-- Horizontal Dilution of Precision
-- 
-- Vertical Dilution of Precision
-- 
-- Indicates the position solution with which the DOPS message
-- corresponds

-- 
-- The position solution message reports absolute Earth Centered Earth
-- Fixed (ECEF) coordinates and the status (single point vs pseudo-absolute
-- RTK) of the position solution. If the rover receiver knows the surveyed
-- position of the base station and has an RTK solution, this reports a
-- pseudo-absolute position solution using the base station position and
-- the rover's RTK baseline vector. The full GPS time is given by the
-- preceding MSG_GPS_TIME with the matching time-of-week (tow).
Navigation.MsgPosEcefDepA = class.class(KaitaiStruct)

function Navigation.MsgPosEcefDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgPosEcefDepA:_read()
  self.tow = self._io:read_u4le()
  self.x = self._io:read_f8le()
  self.y = self._io:read_f8le()
  self.z = self._io:read_f8le()
  self.accuracy = self._io:read_u2le()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- ECEF X coordinate
-- 
-- ECEF Y coordinate
-- 
-- ECEF Z coordinate
-- 
-- Position accuracy estimate (not implemented). Defaults to 0.
-- 
-- Number of satellites used in solution
-- 
-- Status flags

Navigation.EstimatedHorizontalErrorEllipse = class.class(KaitaiStruct)

function Navigation.EstimatedHorizontalErrorEllipse:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.EstimatedHorizontalErrorEllipse:_read()
  self.semi_major = self._io:read_f4le()
  self.semi_minor = self._io:read_f4le()
  self.orientation = self._io:read_f4le()
end

-- 
-- The semi major axis of the estimated horizontal error ellipse at the
-- user-configured confidence level; zero implies invalid.
-- 
-- The semi minor axis of the estimated horizontal error ellipse at the
-- user-configured confidence level; zero implies invalid.
-- 
-- The orientation of the semi major axis of the estimated horizontal
-- error ellipse with respect to North.

-- 
-- This position solution message reports the absolute geodetic coordinates
-- and the status (single point vs pseudo-absolute RTK) of the position
-- solution as well as the estimated horizontal, vertical, cross-track and
-- along-track errors.  The position information and Fix Mode flags  follow
-- the MSG_POS_LLH message. Since the covariance matrix is computed in the
-- local-level North, East, Down frame, the estimated error terms follow
-- that convention.
-- 
-- The estimated errors are reported at a user-configurable confidence
-- level. The user-configured percentile is encoded in the percentile
-- field.
Navigation.MsgPosLlhAcc = class.class(KaitaiStruct)

function Navigation.MsgPosLlhAcc:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Navigation.MsgPosLlhAcc:_read()
  self.tow = self._io:read_u4le()
  self.lat = self._io:read_f8le()
  self.lon = self._io:read_f8le()
  self.height = self._io:read_f8le()
  self.orthometric_height = self._io:read_f8le()
  self.h_accuracy = self._io:read_f4le()
  self.v_accuracy = self._io:read_f4le()
  self.ct_accuracy = self._io:read_f4le()
  self.at_accuracy = self._io:read_f4le()
  self.h_ellipse = Navigation.EstimatedHorizontalErrorEllipse(self._io, self, self._root)
  self.confidence_and_geoid = self._io:read_u1()
  self.n_sats = self._io:read_u1()
  self.flags = self._io:read_u1()
end

-- 
-- GPS Time of Week
-- 
-- Latitude
-- 
-- Longitude
-- 
-- Height above WGS84 ellipsoid
-- 
-- Height above the geoid (i.e. height above mean sea level). See
-- confidence_and_geoid for geoid model used.
-- 
-- Estimated horizontal error at the user-configured confidence level;
-- zero implies invalid.
-- 
-- Estimated vertical error at the user-configured confidence level;
-- zero implies invalid.
-- 
-- Estimated cross-track error at the user-configured confidence level;
-- zero implies invalid.
-- 
-- Estimated along-track error at the user-configured confidence level;
-- zero implies invalid.
-- 
-- The estimated horizontal error ellipse at the user-configured
-- confidence level.
-- 
-- The lower bits describe the configured confidence level for the
-- estimated position error. The middle bits describe the geoid model
-- used to calculate the orthometric height.
-- 
-- Number of satellites used in solution.
-- 
-- Status flags

