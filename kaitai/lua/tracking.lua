-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

Tracking = class.class(KaitaiStruct)

function Tracking:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Tracking:_read()
end


-- 
-- Deprecated.
Tracking.MsgTrackingStateDetailedDep = class.class(KaitaiStruct)

function Tracking.MsgTrackingStateDetailedDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Tracking.MsgTrackingStateDetailedDep:_read()
  self.recv_time = self._io:read_u8le()
  self.tot = Gnss.GpsTimeDep(self._io, self, self._root)
  self.p = self._io:read_u4le()
  self.p_std = self._io:read_u2le()
  self.l = Gnss.CarrierPhase(self._io, self, self._root)
  self.cn0 = self._io:read_u1()
  self.lock = self._io:read_u2le()
  self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
  self.doppler = self._io:read_s4le()
  self.doppler_std = self._io:read_u2le()
  self.uptime = self._io:read_u4le()
  self.clock_offset = self._io:read_s2le()
  self.clock_drift = self._io:read_s2le()
  self.corr_spacing = self._io:read_u2le()
  self.acceleration = self._io:read_s1()
  self.sync_flags = self._io:read_u1()
  self.tow_flags = self._io:read_u1()
  self.track_flags = self._io:read_u1()
  self.nav_flags = self._io:read_u1()
  self.pset_flags = self._io:read_u1()
  self.misc_flags = self._io:read_u1()
end

-- 
-- Receiver clock time.
-- 
-- Time of transmission of signal from satellite. TOW only valid when
-- TOW status is decoded or propagated. WN only valid when week number
-- valid flag is set.
-- 
-- Pseudorange observation. Valid only when pseudorange valid flag is
-- set.
-- 
-- Pseudorange observation standard deviation. Valid only when
-- pseudorange valid flag is set.
-- 
-- Carrier phase observation with typical sign convention. Valid only
-- when PLL pessimistic lock is achieved.
-- 
-- Carrier-to-Noise density
-- 
-- Lock time. It is encoded according to DF402 from the RTCM 10403.2
-- Amendment 2 specification. Valid values range from 0 to 15.
-- 
-- GNSS signal identifier.
-- 
-- Carrier Doppler frequency.
-- 
-- Carrier Doppler frequency standard deviation.
-- 
-- Number of seconds of continuous tracking. Specifies how much time
-- signal is in continuous track.
-- 
-- TCXO clock offset. Valid only when valid clock valid flag is set.
-- 
-- TCXO clock drift. Valid only when valid clock valid flag is set.
-- 
-- Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
-- 
-- Acceleration. Valid only when acceleration valid flag is set.
-- 
-- Synchronization status flags.
-- 
-- TOW status flags.
-- 
-- Tracking loop status flags.
-- 
-- Navigation data status flags.
-- 
-- Parameters sets flags.
-- 
-- Miscellaneous flags.

-- 
-- Deprecated.
Tracking.TrackingChannelStateDepB = class.class(KaitaiStruct)

function Tracking.TrackingChannelStateDepB:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Tracking.TrackingChannelStateDepB:_read()
  self.state = self._io:read_u1()
  self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
  self.cn0 = self._io:read_f4le()
end

-- 
-- Status of tracking channel
-- 
-- GNSS signal being tracked
-- 
-- Carrier-to-noise density

-- 
-- Tracking channel state for a specific satellite signal and measured
-- signal power.
Tracking.TrackingChannelState = class.class(KaitaiStruct)

function Tracking.TrackingChannelState:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Tracking.TrackingChannelState:_read()
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.fcn = self._io:read_u1()
  self.cn0 = self._io:read_u1()
end

-- 
-- GNSS signal being tracked
-- 
-- Frequency channel number (GLONASS only)
-- 
-- Carrier-to-Noise density.  Zero implies invalid cn0.

-- 
-- The tracking message returns a variable-length array of tracking channel
-- states. It reports status and carrier-to-noise density measurements for
-- all tracked satellites.
Tracking.MsgTrackingState = class.class(KaitaiStruct)

function Tracking.MsgTrackingState:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Tracking.MsgTrackingState:_read()
  self.states = {}
  local i = 0
  while not self._io:is_eof() do
    self.states[i + 1] = Tracking.TrackingChannelState(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Signal tracking channel state

-- 
-- Deprecated.
Tracking.TrackingChannelStateDepA = class.class(KaitaiStruct)

function Tracking.TrackingChannelStateDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Tracking.TrackingChannelStateDepA:_read()
  self.state = self._io:read_u1()
  self.prn = self._io:read_u1()
  self.cn0 = self._io:read_f4le()
end

-- 
-- Status of tracking channel
-- 
-- PRN-1 being tracked
-- 
-- Carrier-to-noise density

-- 
-- Deprecated.
Tracking.MsgTrackingIqDepA = class.class(KaitaiStruct)

function Tracking.MsgTrackingIqDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Tracking.MsgTrackingIqDepA:_read()
  self.channel = self._io:read_u1()
  self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
  self.corrs = {}
  for i = 0, 3 - 1 do
    self.corrs[i + 1] = self._io:read_u8le()
  end
end

-- 
-- Tracking channel of origin
-- 
-- GNSS signal identifier
-- 
-- Early, Prompt and Late correlations

-- 
-- Structure containing in-phase and quadrature correlation components.
Tracking.TrackingChannelCorrelationDep = class.class(KaitaiStruct)

function Tracking.TrackingChannelCorrelationDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Tracking.TrackingChannelCorrelationDep:_read()
  self.i = self._io:read_s4le()
  self.q = self._io:read_s4le()
end

-- 
-- In-phase correlation
-- 
-- Quadrature correlation

-- 
-- Deprecated.
Tracking.MsgTrackingStateDepA = class.class(KaitaiStruct)

function Tracking.MsgTrackingStateDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Tracking.MsgTrackingStateDepA:_read()
  self.states = {}
  local i = 0
  while not self._io:is_eof() do
    self.states[i + 1] = Tracking.TrackingChannelStateDepA(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Satellite tracking channel state

-- 
-- The tracking message returns a variable-length array of tracking channel
-- states. It reports status and carrier-to-noise density measurements for
-- all tracked satellites.
Tracking.MsgMeasurementState = class.class(KaitaiStruct)

function Tracking.MsgMeasurementState:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Tracking.MsgMeasurementState:_read()
  self.states = {}
  local i = 0
  while not self._io:is_eof() do
    self.states[i + 1] = Tracking.MeasurementState(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- ME signal tracking channel state

-- 
-- Structure containing in-phase and quadrature correlation components.
Tracking.TrackingChannelCorrelation = class.class(KaitaiStruct)

function Tracking.TrackingChannelCorrelation:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Tracking.TrackingChannelCorrelation:_read()
  self.i = self._io:read_s2le()
  self.q = self._io:read_s2le()
end

-- 
-- In-phase correlation
-- 
-- Quadrature correlation

-- 
-- When enabled, a tracking channel can output the correlations at each
-- update interval.
Tracking.MsgTrackingIq = class.class(KaitaiStruct)

function Tracking.MsgTrackingIq:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Tracking.MsgTrackingIq:_read()
  self.channel = self._io:read_u1()
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.corrs = {}
  for i = 0, 3 - 1 do
    self.corrs[i + 1] = self._io:read_u8le()
  end
end

-- 
-- Tracking channel of origin
-- 
-- GNSS signal identifier
-- 
-- Early, Prompt and Late correlations

-- 
-- The tracking message returns a set tracking channel parameters for a
-- single tracking channel useful for debugging issues.
Tracking.MsgTrackingStateDetailedDepA = class.class(KaitaiStruct)

function Tracking.MsgTrackingStateDetailedDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Tracking.MsgTrackingStateDetailedDepA:_read()
  self.recv_time = self._io:read_u8le()
  self.tot = Gnss.GpsTime(self._io, self, self._root)
  self.p = self._io:read_u4le()
  self.p_std = self._io:read_u2le()
  self.l = Gnss.CarrierPhase(self._io, self, self._root)
  self.cn0 = self._io:read_u1()
  self.lock = self._io:read_u2le()
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.doppler = self._io:read_s4le()
  self.doppler_std = self._io:read_u2le()
  self.uptime = self._io:read_u4le()
  self.clock_offset = self._io:read_s2le()
  self.clock_drift = self._io:read_s2le()
  self.corr_spacing = self._io:read_u2le()
  self.acceleration = self._io:read_s1()
  self.sync_flags = self._io:read_u1()
  self.tow_flags = self._io:read_u1()
  self.track_flags = self._io:read_u1()
  self.nav_flags = self._io:read_u1()
  self.pset_flags = self._io:read_u1()
  self.misc_flags = self._io:read_u1()
end

-- 
-- Receiver clock time.
-- 
-- Time of transmission of signal from satellite. TOW only valid when
-- TOW status is decoded or propagated. WN only valid when week number
-- valid flag is set.
-- 
-- Pseudorange observation. Valid only when pseudorange valid flag is
-- set.
-- 
-- Pseudorange observation standard deviation. Valid only when
-- pseudorange valid flag is set.
-- 
-- Carrier phase observation with typical sign convention. Valid only
-- when PLL pessimistic lock is achieved.
-- 
-- Carrier-to-Noise density
-- 
-- Lock time. It is encoded according to DF402 from the RTCM 10403.2
-- Amendment 2 specification. Valid values range from 0 to 15.
-- 
-- GNSS signal identifier.
-- 
-- Carrier Doppler frequency.
-- 
-- Carrier Doppler frequency standard deviation.
-- 
-- Number of seconds of continuous tracking. Specifies how much time
-- signal is in continuous track.
-- 
-- TCXO clock offset. Valid only when valid clock valid flag is set.
-- 
-- TCXO clock drift. Valid only when valid clock valid flag is set.
-- 
-- Early-Prompt (EP) and Prompt-Late (PL) correlators spacing.
-- 
-- Acceleration. Valid only when acceleration valid flag is set.
-- 
-- Synchronization status flags.
-- 
-- TOW status flags.
-- 
-- Tracking loop status flags.
-- 
-- Navigation data status flags.
-- 
-- Parameters sets flags.
-- 
-- Miscellaneous flags.

-- 
-- Deprecated.
Tracking.MsgTrackingStateDepB = class.class(KaitaiStruct)

function Tracking.MsgTrackingStateDepB:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Tracking.MsgTrackingStateDepB:_read()
  self.states = {}
  local i = 0
  while not self._io:is_eof() do
    self.states[i + 1] = Tracking.TrackingChannelStateDepB(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Signal tracking channel state

-- 
-- Measurement Engine tracking channel state for a specific satellite
-- signal and measured signal power. The mesid field for Glonass can either
-- carry the FCN as 100 + FCN where FCN is in [-7, +6] or the Slot ID (from
-- 1 to 28).
Tracking.MeasurementState = class.class(KaitaiStruct)

function Tracking.MeasurementState:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Tracking.MeasurementState:_read()
  self.mesid = Gnss.GnssSignal(self._io, self, self._root)
  self.cn0 = self._io:read_u1()
end

-- 
-- Measurement Engine GNSS signal being tracked (carries either Glonass
-- FCN or SLOT)
-- 
-- Carrier-to-Noise density.  Zero implies invalid cn0.

-- 
-- Deprecated.
Tracking.MsgTrackingIqDepB = class.class(KaitaiStruct)

function Tracking.MsgTrackingIqDepB:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Tracking.MsgTrackingIqDepB:_read()
  self.channel = self._io:read_u1()
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.corrs = {}
  for i = 0, 3 - 1 do
    self.corrs[i + 1] = self._io:read_u8le()
  end
end

-- 
-- Tracking channel of origin
-- 
-- GNSS signal identifier
-- 
-- Early, Prompt and Late correlations

