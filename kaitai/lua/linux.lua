-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")
local str_decode = require("string_decode")

Linux = class.class(KaitaiStruct)

function Linux:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Linux:_read()
end


-- 
-- Summaries the socket usage across the system.
Linux.MsgLinuxSocketUsage = class.class(KaitaiStruct)

function Linux.MsgLinuxSocketUsage:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Linux.MsgLinuxSocketUsage:_read()
  self.avg_queue_depth = self._io:read_u4le()
  self.max_queue_depth = self._io:read_u4le()
  self.socket_state_counts = {}
  for i = 0, 16 - 1 do
    self.socket_state_counts[i + 1] = self._io:read_u2le()
  end
  self.socket_type_counts = {}
  for i = 0, 16 - 1 do
    self.socket_type_counts[i + 1] = self._io:read_u2le()
  end
end

-- 
-- average socket queue depths across all sockets on the system
-- 
-- the max queue depth seen within the reporting period
-- 
-- A count for each socket type reported in the `socket_types_reported`
-- field, the first entry corresponds to the first enabled bit in
-- `types_reported`.
-- 
-- A count for each socket type reported in the `socket_types_reported`
-- field, the first entry corresponds to the first enabled bit in
-- `types_reported`.

-- 
-- This presents a summary of CPU and memory utilization, including a
-- timestamp.
Linux.MsgLinuxSysState = class.class(KaitaiStruct)

function Linux.MsgLinuxSysState:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Linux.MsgLinuxSysState:_read()
  self.mem_total = self._io:read_u2le()
  self.pcpu = self._io:read_u1()
  self.pmem = self._io:read_u1()
  self.procs_starting = self._io:read_u2le()
  self.procs_stopping = self._io:read_u2le()
  self.pid_count = self._io:read_u2le()
  self.time = self._io:read_u4le()
  self.flags = self._io:read_u1()
end

-- 
-- total system memory, in MiB
-- 
-- percent of CPU used, expressed as a fraction of 256
-- 
-- percent of memory used, expressed as a fraction of 256
-- 
-- number of processes that started during collection phase
-- 
-- number of processes that stopped during collection phase
-- 
-- the count of processes on the system
-- 
-- timestamp of message, refer to flags field for how to interpret
-- 
-- flags

-- 
-- This message indicates the process state of the top 10 heaviest
-- consumers of CPU on the system.
Linux.MsgLinuxCpuStateDepA = class.class(KaitaiStruct)

function Linux.MsgLinuxCpuStateDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Linux.MsgLinuxCpuStateDepA:_read()
  self.index = self._io:read_u1()
  self.pid = self._io:read_u2le()
  self.pcpu = self._io:read_u1()
  self.tname = str_decode.decode(self._io:read_bytes(15), "ascii")
  self.cmdline = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- sequence of this status message, values from 0-9
-- 
-- the PID of the process
-- 
-- percent of cpu used, expressed as a fraction of 256
-- 
-- fixed length string representing the thread name
-- 
-- the command line (as much as it fits in the remaining packet)

-- 
-- This message indicates the process state of the top 10 heaviest
-- consumers of memory on the system, including a timestamp.
Linux.MsgLinuxMemState = class.class(KaitaiStruct)

function Linux.MsgLinuxMemState:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Linux.MsgLinuxMemState:_read()
  self.index = self._io:read_u1()
  self.pid = self._io:read_u2le()
  self.pmem = self._io:read_u1()
  self.time = self._io:read_u4le()
  self.flags = self._io:read_u1()
  self.tname = str_decode.decode(self._io:read_bytes(15), "ascii")
  self.cmdline = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- sequence of this status message, values from 0-9
-- 
-- the PID of the process
-- 
-- percent of memory used, expressed as a fraction of 256
-- 
-- timestamp of message, refer to flags field for how to interpret
-- 
-- flags
-- 
-- fixed length string representing the thread name
-- 
-- the command line (as much as it fits in the remaining packet)

-- 
-- Top 10 list of processes with a large number of open file descriptors.
Linux.MsgLinuxProcessFdCount = class.class(KaitaiStruct)

function Linux.MsgLinuxProcessFdCount:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Linux.MsgLinuxProcessFdCount:_read()
  self.index = self._io:read_u1()
  self.pid = self._io:read_u2le()
  self.fd_count = self._io:read_u2le()
  self.cmdline = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- sequence of this status message, values from 0-9
-- 
-- the PID of the process in question
-- 
-- a count of the number of file descriptors opened by the process
-- 
-- the command line of the process in question

-- 
-- This message indicates the process state of the top 10 heaviest
-- consumers of memory on the system.
Linux.MsgLinuxMemStateDepA = class.class(KaitaiStruct)

function Linux.MsgLinuxMemStateDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Linux.MsgLinuxMemStateDepA:_read()
  self.index = self._io:read_u1()
  self.pid = self._io:read_u2le()
  self.pmem = self._io:read_u1()
  self.tname = str_decode.decode(self._io:read_bytes(15), "ascii")
  self.cmdline = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- sequence of this status message, values from 0-9
-- 
-- the PID of the process
-- 
-- percent of memory used, expressed as a fraction of 256
-- 
-- fixed length string representing the thread name
-- 
-- the command line (as much as it fits in the remaining packet)

-- 
-- Top 10 list of sockets with deep queues.
Linux.MsgLinuxProcessSocketQueues = class.class(KaitaiStruct)

function Linux.MsgLinuxProcessSocketQueues:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Linux.MsgLinuxProcessSocketQueues:_read()
  self.index = self._io:read_u1()
  self.pid = self._io:read_u2le()
  self.recv_queued = self._io:read_u2le()
  self.send_queued = self._io:read_u2le()
  self.socket_types = self._io:read_u2le()
  self.socket_states = self._io:read_u2le()
  self.address_of_largest = str_decode.decode(self._io:read_bytes(64), "ascii")
  self.cmdline = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- sequence of this status message, values from 0-9
-- 
-- the PID of the process in question
-- 
-- the total amount of receive data queued for this process
-- 
-- the total amount of send data queued for this process
-- 
-- A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
-- 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
-- (unknown)
-- 
-- A bitfield indicating the socket states: 0x1 (established), 0x2
-- (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
-- 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
-- ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
-- 0x8000 (unknown)
-- 
-- Address of the largest queue, remote or local depending on the
-- directionality of the connection.
-- 
-- the command line of the process in question

-- 
-- This presents a summary of CPU and memory utilization.
Linux.MsgLinuxSysStateDepA = class.class(KaitaiStruct)

function Linux.MsgLinuxSysStateDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Linux.MsgLinuxSysStateDepA:_read()
  self.mem_total = self._io:read_u2le()
  self.pcpu = self._io:read_u1()
  self.pmem = self._io:read_u1()
  self.procs_starting = self._io:read_u2le()
  self.procs_stopping = self._io:read_u2le()
  self.pid_count = self._io:read_u2le()
end

-- 
-- total system memory
-- 
-- percent of total cpu currently utilized
-- 
-- percent of total memory currently utilized
-- 
-- number of processes that started during collection phase
-- 
-- number of processes that stopped during collection phase
-- 
-- the count of processes on the system

-- 
-- Summary of open file descriptors on the system.
Linux.MsgLinuxProcessFdSummary = class.class(KaitaiStruct)

function Linux.MsgLinuxProcessFdSummary:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Linux.MsgLinuxProcessFdSummary:_read()
  self.sys_fd_count = self._io:read_u4le()
  self.most_opened = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- count of total FDs open on the system
-- 
-- A null delimited list of strings which alternates between a string
-- representation of the process count and the file name whose count it
-- being reported.  That is, in C string syntax
-- "32\0/var/log/syslog\012\0/tmp/foo\0" with the end of the list being
-- 2 NULL terminators in a row.

-- 
-- This message indicates the process state of the top 10 heaviest
-- consumers of CPU on the system, including a timestamp.
Linux.MsgLinuxCpuState = class.class(KaitaiStruct)

function Linux.MsgLinuxCpuState:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Linux.MsgLinuxCpuState:_read()
  self.index = self._io:read_u1()
  self.pid = self._io:read_u2le()
  self.pcpu = self._io:read_u1()
  self.time = self._io:read_u4le()
  self.flags = self._io:read_u1()
  self.tname = str_decode.decode(self._io:read_bytes(15), "ascii")
  self.cmdline = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- sequence of this status message, values from 0-9
-- 
-- the PID of the process
-- 
-- percent of CPU used, expressed as a fraction of 256
-- 
-- timestamp of message, refer to flags field for how to interpret
-- 
-- flags
-- 
-- fixed length string representing the thread name
-- 
-- the command line (as much as it fits in the remaining packet)

-- 
-- Top 10 list of processes with high socket counts.
Linux.MsgLinuxProcessSocketCounts = class.class(KaitaiStruct)

function Linux.MsgLinuxProcessSocketCounts:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Linux.MsgLinuxProcessSocketCounts:_read()
  self.index = self._io:read_u1()
  self.pid = self._io:read_u2le()
  self.socket_count = self._io:read_u2le()
  self.socket_types = self._io:read_u2le()
  self.socket_states = self._io:read_u2le()
  self.cmdline = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- sequence of this status message, values from 0-9
-- 
-- the PID of the process in question
-- 
-- the number of sockets the process is using
-- 
-- A bitfield indicating the socket types used: 0x1 (tcp), 0x2 (udp),
-- 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink), and 0x8000
-- (unknown)
-- 
-- A bitfield indicating the socket states: 0x1 (established), 0x2
-- (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1), 0x10 (fin-wait-2),
-- 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait), 0x100 (last-
-- ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected), and
-- 0x8000 (unknown)
-- 
-- the command line of the process in question

