-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")
local str_decode = require("string_decode")

Piksi = class.class(KaitaiStruct)

function Piksi:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi:_read()
end


-- 
-- The state of a network interface on the Piksi. Data is made to reflect
-- output of ifaddrs struct returned by getifaddrs in c.
Piksi.MsgNetworkStateResp = class.class(KaitaiStruct)

function Piksi.MsgNetworkStateResp:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgNetworkStateResp:_read()
  self.ipv4_address = {}
  for i = 0, 4 - 1 do
    self.ipv4_address[i + 1] = self._io:read_u1()
  end
  self.ipv4_mask_size = self._io:read_u1()
  self.ipv6_address = {}
  for i = 0, 16 - 1 do
    self.ipv6_address[i + 1] = self._io:read_u1()
  end
  self.ipv6_mask_size = self._io:read_u1()
  self.rx_bytes = self._io:read_u4le()
  self.tx_bytes = self._io:read_u4le()
  self.interface_name = str_decode.decode(self._io:read_bytes(16), "ascii")
  self.flags = self._io:read_u4le()
end

-- 
-- IPv4 address (all zero when unavailable)
-- 
-- IPv4 netmask CIDR notation
-- 
-- IPv6 address (all zero when unavailable)
-- 
-- IPv6 netmask CIDR notation
-- 
-- Number of Rx bytes
-- 
-- Number of Tx bytes
-- 
-- Interface Name
-- 
-- Interface flags from SIOCGIFFLAGS

-- 
-- The bandwidth usage for each interface can be reported within this
-- struct and utilize multiple fields to fully specify the type of traffic
-- that is being tracked. As either the interval of collection or the
-- collection time may vary, both a timestamp and period field is provided,
-- though may not necessarily be populated with a value.
Piksi.NetworkUsage = class.class(KaitaiStruct)

function Piksi.NetworkUsage:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.NetworkUsage:_read()
  self.duration = self._io:read_u8le()
  self.total_bytes = self._io:read_u8le()
  self.rx_bytes = self._io:read_u4le()
  self.tx_bytes = self._io:read_u4le()
  self.interface_name = str_decode.decode(self._io:read_bytes(16), "ascii")
end

-- 
-- Duration over which the measurement was collected
-- 
-- Number of bytes handled in total within period
-- 
-- Number of bytes transmitted within period
-- 
-- Number of bytes received within period
-- 
-- Interface Name

-- 
-- The response to MSG_COMMAND_REQ with the return code of the command.  A
-- return code of zero indicates success.
Piksi.MsgCommandResp = class.class(KaitaiStruct)

function Piksi.MsgCommandResp:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgCommandResp:_read()
  self.sequence = self._io:read_u4le()
  self.code = self._io:read_s4le()
end

-- 
-- Sequence number
-- 
-- Exit code

-- 
-- Returns the standard output and standard error of the command requested
-- by MSG_COMMAND_REQ. The sequence number can be used to filter for
-- filtering the correct command.
Piksi.MsgCommandOutput = class.class(KaitaiStruct)

function Piksi.MsgCommandOutput:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgCommandOutput:_read()
  self.sequence = self._io:read_u4le()
  self.line = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- Sequence number
-- 
-- Line of standard output or standard error

-- 
-- Statistics on the latency of observations received from the base
-- station. As observation packets are received their GPS time is compared
-- to the current GPS time calculated locally by the receiver to give a
-- precise measurement of the end-to-end communication latency in the
-- system.
Piksi.Latency = class.class(KaitaiStruct)

function Piksi.Latency:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.Latency:_read()
  self.avg = self._io:read_s4le()
  self.lmin = self._io:read_s4le()
  self.lmax = self._io:read_s4le()
  self.current = self._io:read_s4le()
end

-- 
-- Average latency
-- 
-- Minimum latency
-- 
-- Maximum latency
-- 
-- Smoothed estimate of the current latency

-- 
-- The thread usage message from the device reports real-time operating
-- system (RTOS) thread usage statistics for the named thread. The reported
-- percentage values must be normalized.
Piksi.MsgThreadState = class.class(KaitaiStruct)

function Piksi.MsgThreadState:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgThreadState:_read()
  self.name = str_decode.decode(self._io:read_bytes(20), "ascii")
  self.cpu = self._io:read_u2le()
  self.stack_free = self._io:read_u4le()
end

-- 
-- Thread name (NULL terminated)
-- 
-- Percentage cpu use for this thread. Values range from 0 - 1000 and
-- needs to be renormalized to 100
-- 
-- Free stack space for this thread

-- 
-- Deprecated
Piksi.MsgUartStateDepa = class.class(KaitaiStruct)

function Piksi.MsgUartStateDepa:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgUartStateDepa:_read()
  self.uart_a = Piksi.UartChannel(self._io, self, self._root)
  self.uart_b = Piksi.UartChannel(self._io, self, self._root)
  self.uart_ftdi = Piksi.UartChannel(self._io, self, self._root)
  self.latency = Piksi.Latency(self._io, self, self._root)
end

-- 
-- State of UART A
-- 
-- State of UART B
-- 
-- State of UART FTDI (USB logger)
-- 
-- UART communication latency

-- 
-- Request state of Piksi network interfaces. Output will be sent in
-- MSG_NETWORK_STATE_RESP messages.
Piksi.MsgNetworkStateReq = class.class(KaitaiStruct)

function Piksi.MsgNetworkStateReq:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgNetworkStateReq:_read()
end


-- 
-- This message contains temperature and voltage level measurements from
-- the processor's monitoring system and the RF frontend die temperature if
-- available.
Piksi.MsgDeviceMonitor = class.class(KaitaiStruct)

function Piksi.MsgDeviceMonitor:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgDeviceMonitor:_read()
  self.dev_vin = self._io:read_s2le()
  self.cpu_vint = self._io:read_s2le()
  self.cpu_vaux = self._io:read_s2le()
  self.cpu_temperature = self._io:read_s2le()
  self.fe_temperature = self._io:read_s2le()
end

-- 
-- Device V_in
-- 
-- Processor V_int
-- 
-- Processor V_aux
-- 
-- Processor temperature
-- 
-- Frontend temperature (if available)

-- 
-- Deprecated.
Piksi.MsgMaskSatelliteDep = class.class(KaitaiStruct)

function Piksi.MsgMaskSatelliteDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgMaskSatelliteDep:_read()
  self.mask = self._io:read_u1()
  self.sid = Gnss.GnssSignalDep(self._io, self, self._root)
end

-- 
-- Mask of systems that should ignore this satellite.
-- 
-- GNSS signal for which the mask is applied

-- 
-- The UART message reports data latency and throughput of the UART
-- channels providing SBP I/O. On the default Piksi configuration, UARTs A
-- and B are used for telemetry radios, but can also be host access ports
-- for embedded hosts, or other interfaces in future. The reported
-- percentage values must be normalized. Observations latency and period
-- can be used to assess the health of the differential corrections link.
-- Latency provides the timeliness of received base observations while the
-- period indicates their likelihood of transmission.
Piksi.MsgUartState = class.class(KaitaiStruct)

function Piksi.MsgUartState:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgUartState:_read()
  self.uart_a = Piksi.UartChannel(self._io, self, self._root)
  self.uart_b = Piksi.UartChannel(self._io, self, self._root)
  self.uart_ftdi = Piksi.UartChannel(self._io, self, self._root)
  self.latency = Piksi.Latency(self._io, self, self._root)
  self.obs_period = Piksi.Period(self._io, self, self._root)
end

-- 
-- State of UART A
-- 
-- State of UART B
-- 
-- State of UART FTDI (USB logger)
-- 
-- UART communication latency
-- 
-- Observation receipt period

-- 
-- Spectrum analyzer packet.
Piksi.MsgSpecan = class.class(KaitaiStruct)

function Piksi.MsgSpecan:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgSpecan:_read()
  self.channel_tag = self._io:read_u2le()
  self.t = Gnss.GpsTime(self._io, self, self._root)
  self.freq_ref = self._io:read_f4le()
  self.freq_step = self._io:read_f4le()
  self.amplitude_ref = self._io:read_f4le()
  self.amplitude_unit = self._io:read_f4le()
  self.amplitude_value = {}
  local i = 0
  while not self._io:is_eof() do
    self.amplitude_value[i + 1] = self._io:read_u1()
    i = i + 1
  end
end

-- 
-- Channel ID
-- 
-- Receiver time of this observation
-- 
-- Reference frequency of this packet
-- 
-- Frequency step of points in this packet
-- 
-- Reference amplitude of this packet
-- 
-- Amplitude unit value of points in this packet
-- 
-- Amplitude values (in the above units) of points in this packet

-- 
-- This message reports the state of the Integer Ambiguity Resolution (IAR)
-- process, which resolves unknown integer ambiguities from double-
-- differenced carrier-phase measurements from satellite observations.
Piksi.MsgIarState = class.class(KaitaiStruct)

function Piksi.MsgIarState:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgIarState:_read()
  self.num_hyps = self._io:read_u4le()
end

-- 
-- Number of integer ambiguity hypotheses remaining

-- 
-- This is a legacy message for sending and loading a satellite alamanac
-- onto the Piksi's flash memory from the host.
Piksi.MsgAlmanac = class.class(KaitaiStruct)

function Piksi.MsgAlmanac:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgAlmanac:_read()
end


-- 
-- This message resets either the DGNSS Kalman filters or Integer Ambiguity
-- Resolution (IAR) process.
Piksi.MsgResetFilters = class.class(KaitaiStruct)

function Piksi.MsgResetFilters:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgResetFilters:_read()
  self.filter = self._io:read_u1()
end

-- 
-- Filter flags

-- 
-- Throughput, utilization, and error counts on the RX/TX buffers of this
-- UART channel. The reported percentage values must be normalized.
Piksi.UartChannel = class.class(KaitaiStruct)

function Piksi.UartChannel:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.UartChannel:_read()
  self.tx_throughput = self._io:read_f4le()
  self.rx_throughput = self._io:read_f4le()
  self.crc_error_count = self._io:read_u2le()
  self.io_error_count = self._io:read_u2le()
  self.tx_buffer_level = self._io:read_u1()
  self.rx_buffer_level = self._io:read_u1()
end

-- 
-- UART transmit throughput
-- 
-- UART receive throughput
-- 
-- UART CRC error count
-- 
-- UART IO error count
-- 
-- UART transmit buffer percentage utilization (ranges from 0 to 255)
-- 
-- UART receive buffer percentage utilization (ranges from 0 to 255)

-- 
-- Request the recipient to execute an command. Output will be sent in
-- MSG_LOG messages, and the exit code will be returned with
-- MSG_COMMAND_RESP.
Piksi.MsgCommandReq = class.class(KaitaiStruct)

function Piksi.MsgCommandReq:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgCommandReq:_read()
  self.sequence = self._io:read_u4le()
  self.command = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- Sequence number
-- 
-- Command line to execute

-- 
-- This message allows setting a mask to prevent a particular satellite
-- from being used in various Piksi subsystems.
Piksi.MsgMaskSatellite = class.class(KaitaiStruct)

function Piksi.MsgMaskSatellite:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgMaskSatellite:_read()
  self.mask = self._io:read_u1()
  self.sid = Gnss.GnssSignal(self._io, self, self._root)
end

-- 
-- Mask of systems that should ignore this satellite.
-- 
-- GNSS signal for which the mask is applied

-- 
-- The bandwidth usage, a list of usage by interface.
Piksi.MsgNetworkBandwidthUsage = class.class(KaitaiStruct)

function Piksi.MsgNetworkBandwidthUsage:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgNetworkBandwidthUsage:_read()
  self.interfaces = {}
  local i = 0
  while not self._io:is_eof() do
    self.interfaces[i + 1] = Piksi.NetworkUsage(self._io, self, self._root)
    i = i + 1
  end
end

-- 
-- Usage measurement array

-- 
-- This message from the host resets the Piksi back into the bootloader.
Piksi.MsgReset = class.class(KaitaiStruct)

function Piksi.MsgReset:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgReset:_read()
  self.flags = self._io:read_u4le()
end

-- 
-- Reset flags

-- 
-- If a cell modem is present on a piksi device, this message will be send
-- periodically to update the host on the status of the modem and its
-- various parameters.
Piksi.MsgCellModemStatus = class.class(KaitaiStruct)

function Piksi.MsgCellModemStatus:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgCellModemStatus:_read()
  self.signal_strength = self._io:read_s1()
  self.signal_error_rate = self._io:read_f4le()
  self.reserved = {}
  local i = 0
  while not self._io:is_eof() do
    self.reserved[i + 1] = self._io:read_u1()
    i = i + 1
  end
end

-- 
-- Received cell signal strength in dBm, zero translates to unknown
-- 
-- BER as reported by the modem, zero translates to unknown
-- 
-- Unspecified data TBD for this schema

-- 
-- This message describes the gain of each channel in the receiver
-- frontend. Each gain is encoded as a non-dimensional percentage relative
-- to the maximum range possible for the gain stage of the frontend. By
-- convention, each gain array has 8 entries and the index of the array
-- corresponding to the index of the rf channel in the frontend. A gain of
-- 127 percent encodes that rf channel is not present in the hardware. A
-- negative value implies an error for the particular gain stage as
-- reported by the frontend.
Piksi.MsgFrontEndGain = class.class(KaitaiStruct)

function Piksi.MsgFrontEndGain:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgFrontEndGain:_read()
  self.rf_gain = {}
  for i = 0, 8 - 1 do
    self.rf_gain[i + 1] = self._io:read_s1()
  end
  self.if_gain = {}
  for i = 0, 8 - 1 do
    self.if_gain[i + 1] = self._io:read_s1()
  end
end

-- 
-- RF gain for each frontend channel
-- 
-- Intermediate frequency gain for each frontend channel

-- 
-- This message from the host resets the Piksi back into the bootloader.
Piksi.MsgResetDep = class.class(KaitaiStruct)

function Piksi.MsgResetDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgResetDep:_read()
end


-- 
-- This message sets up timing functionality using a coarse GPS time
-- estimate sent by the host.
Piksi.MsgSetTime = class.class(KaitaiStruct)

function Piksi.MsgSetTime:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgSetTime:_read()
end


-- 
-- This is an unused legacy message for result reporting from the CW
-- interference channel on the SwiftNAP. This message will be removed in a
-- future release.
Piksi.MsgCwResults = class.class(KaitaiStruct)

function Piksi.MsgCwResults:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgCwResults:_read()
end


-- 
-- Deprecated.
Piksi.MsgSpecanDep = class.class(KaitaiStruct)

function Piksi.MsgSpecanDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgSpecanDep:_read()
  self.channel_tag = self._io:read_u2le()
  self.t = Gnss.GpsTimeDep(self._io, self, self._root)
  self.freq_ref = self._io:read_f4le()
  self.freq_step = self._io:read_f4le()
  self.amplitude_ref = self._io:read_f4le()
  self.amplitude_unit = self._io:read_f4le()
  self.amplitude_value = {}
  local i = 0
  while not self._io:is_eof() do
    self.amplitude_value[i + 1] = self._io:read_u1()
    i = i + 1
  end
end

-- 
-- Channel ID
-- 
-- Receiver time of this observation
-- 
-- Reference frequency of this packet
-- 
-- Frequency step of points in this packet
-- 
-- Reference amplitude of this packet
-- 
-- Amplitude unit value of points in this packet
-- 
-- Amplitude values (in the above units) of points in this packet

-- 
-- Deprecated
Piksi.MsgInitBaseDep = class.class(KaitaiStruct)

function Piksi.MsgInitBaseDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgInitBaseDep:_read()
end


-- 
-- Statistics on the period of observations received from the base station.
-- As complete observation sets are received, their time of reception is
-- compared with the prior set''s time of reception. This measurement
-- provides a proxy for link quality as incomplete or missing sets will
-- increase the period.  Long periods can cause momentary RTK solution
-- outages.
Piksi.Period = class.class(KaitaiStruct)

function Piksi.Period:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.Period:_read()
  self.avg = self._io:read_s4le()
  self.pmin = self._io:read_s4le()
  self.pmax = self._io:read_s4le()
  self.current = self._io:read_s4le()
end

-- 
-- Average period
-- 
-- Minimum period
-- 
-- Maximum period
-- 
-- Smoothed estimate of the current period

-- 
-- This is an unused legacy message from the host for starting the CW
-- interference channel on the SwiftNAP. This message will be removed in a
-- future release.
Piksi.MsgCwStart = class.class(KaitaiStruct)

function Piksi.MsgCwStart:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Piksi.MsgCwStart:_read()
end


