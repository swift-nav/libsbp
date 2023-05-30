-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

Acquisition = class.class(KaitaiStruct)

function Acquisition:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Acquisition:_read()
end


-- 
-- Deprecated.
Acquisition.MsgAcqResultDepC = class.class(KaitaiStruct)

function Acquisition.MsgAcqResultDepC:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Acquisition.MsgAcqResultDepC:_read()
  self.cn0 = self._io:read_f4le()
  self.cp = self._io:read_f4le()
  self.cf = self._io:read_f4le()
  self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
end

-- 
-- CN/0 of best point
-- 
-- Code phase of best point
-- 
-- Carrier frequency of best point
-- 
-- GNSS signal for which acquisition was attempted

-- 
-- Deprecated.
Acquisition.MsgAcqResultDepB = class.class(KaitaiStruct)

function Acquisition.MsgAcqResultDepB:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Acquisition.MsgAcqResultDepB:_read()
  self.snr = self._io:read_f4le()
  self.cp = self._io:read_f4le()
  self.cf = self._io:read_f4le()
  self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
end

-- 
-- SNR of best point. Currently in arbitrary SNR points, but will be in
-- units of dB Hz in a later revision of this message.
-- 
-- Code phase of best point
-- 
-- Carrier frequency of best point
-- 
-- GNSS signal for which acquisition was attempted

-- 
-- Profile for a specific SV for debugging purposes. The message describes
-- SV profile during acquisition time. The message is used to debug and
-- measure the performance.
Acquisition.AcqSvProfile = class.class(KaitaiStruct)

function Acquisition.AcqSvProfile:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Acquisition.AcqSvProfile:_read()
  self.job_type = self._io:read_u1()
  self.status = self._io:read_u1()
  self.cn0 = self._io:read_u2le()
  self.int_time = self._io:read_u1()
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
  self.bin_width = self._io:read_u2le()
  self.timestamp = self._io:read_u4le()
  self.time_spent = self._io:read_u4le()
  self.cf_min = self._io:read_s4le()
  self.cf_max = self._io:read_s4le()
  self.cf = self._io:read_s4le()
  self.cp = self._io:read_u4le()
end

-- 
-- SV search job type (deep, fallback, etc)
-- 
-- Acquisition status 1 is Success, 0 is Failure
-- 
-- CN0 value. Only valid if status is '1'
-- 
-- Acquisition integration time
-- 
-- GNSS signal for which acquisition was attempted
-- 
-- Acq frequency bin width
-- 
-- Timestamp of the job complete event
-- 
-- Time spent to search for sid.code
-- 
-- Doppler range lowest frequency
-- 
-- Doppler range highest frequency
-- 
-- Doppler value of detected peak. Only valid if status is '1'
-- 
-- Codephase of detected peak. Only valid if status is '1'

-- 
-- The message describes all SV profiles during acquisition time. The
-- message is used to debug and measure the performance.
Acquisition.MsgAcqSvProfile = class.class(KaitaiStruct)

function Acquisition.MsgAcqSvProfile:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Acquisition.MsgAcqSvProfile:_read()
  self.acq_sv_profile = {}
  local i = 0
  while not self._io:is_eof() do
    self.acq_sv_profile[i + 1] = Acquisition.AcqSvProfile(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- SV profiles during acquisition time

-- 
-- Deprecated.
Acquisition.AcqSvProfileDep = class.class(KaitaiStruct)

function Acquisition.AcqSvProfileDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Acquisition.AcqSvProfileDep:_read()
  self.job_type = self._io:read_u1()
  self.status = self._io:read_u1()
  self.cn0 = self._io:read_u2le()
  self.int_time = self._io:read_u1()
  self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
  self.bin_width = self._io:read_u2le()
  self.timestamp = self._io:read_u4le()
  self.time_spent = self._io:read_u4le()
  self.cf_min = self._io:read_s4le()
  self.cf_max = self._io:read_s4le()
  self.cf = self._io:read_s4le()
  self.cp = self._io:read_u4le()
end

-- 
-- SV search job type (deep, fallback, etc)
-- 
-- Acquisition status 1 is Success, 0 is Failure
-- 
-- CN0 value. Only valid if status is '1'
-- 
-- Acquisition integration time
-- 
-- GNSS signal for which acquisition was attempted
-- 
-- Acq frequency bin width
-- 
-- Timestamp of the job complete event
-- 
-- Time spent to search for sid.code
-- 
-- Doppler range lowest frequency
-- 
-- Doppler range highest frequency
-- 
-- Doppler value of detected peak. Only valid if status is '1'
-- 
-- Codephase of detected peak. Only valid if status is '1'

-- 
-- This message describes the results from an attempted GPS signal
-- acquisition search for a satellite PRN over a code phase/carrier
-- frequency range. It contains the parameters of the point in the
-- acquisition search space with the best carrier-to-noise (CN/0) ratio.
Acquisition.MsgAcqResult = class.class(KaitaiStruct)

function Acquisition.MsgAcqResult:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Acquisition.MsgAcqResult:_read()
  self.cn0 = self._io:read_f4le()
  self.cp = self._io:read_f4le()
  self.cf = self._io:read_f4le()
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
end

-- 
-- CN/0 of best point
-- 
-- Code phase of best point
-- 
-- Carrier frequency of best point
-- 
-- GNSS signal for which acquisition was attempted

-- 
-- Deprecated.
Acquisition.MsgAcqResultDepA = class.class(KaitaiStruct)

function Acquisition.MsgAcqResultDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Acquisition.MsgAcqResultDepA:_read()
  self.snr = self._io:read_f4le()
  self.cp = self._io:read_f4le()
  self.cf = self._io:read_f4le()
  self.prn = self._io:read_u1()
end

-- 
-- SNR of best point. Currently dimensionless, but will have units of
-- dB Hz in the revision of this message.
-- 
-- Code phase of best point
-- 
-- Carrier frequency of best point
-- 
-- PRN-1 identifier of the satellite signal for which acquisition was
-- attempted

-- 
-- Deprecated.
Acquisition.MsgAcqSvProfileDep = class.class(KaitaiStruct)

function Acquisition.MsgAcqSvProfileDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Acquisition.MsgAcqSvProfileDep:_read()
  self.acq_sv_profile = {}
  local i = 0
  while not self._io:is_eof() do
    self.acq_sv_profile[i + 1] = Acquisition.AcqSvProfileDep(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- SV profiles during acquisition time

