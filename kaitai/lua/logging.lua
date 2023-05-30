-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")
local str_decode = require("string_decode")

Logging = class.class(KaitaiStruct)

function Logging:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Logging:_read()
end


-- 
-- This message contains a human-readable payload string from the device
-- containing errors, warnings and informational messages at ERROR,
-- WARNING, DEBUG, INFO logging levels.
Logging.MsgLog = class.class(KaitaiStruct)

function Logging.MsgLog:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Logging.MsgLog:_read()
  self.level = self._io:read_u1()
  self.text = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- Logging level
-- 
-- Human-readable string

-- 
-- This message provides the ability to forward messages over SBP.  This
-- may take the form of wrapping up SBP messages received by Piksi for
-- logging purposes or wrapping another protocol with SBP.
-- 
-- The source identifier indicates from what interface a forwarded stream
-- derived. The protocol identifier identifies what the expected protocol
-- the forwarded msg contains. Protocol 0 represents SBP and the remaining
-- values are implementation defined.
Logging.MsgFwd = class.class(KaitaiStruct)

function Logging.MsgFwd:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Logging.MsgFwd:_read()
  self.source = self._io:read_u1()
  self.protocol = self._io:read_u1()
  self.fwd_payload = {}
  local i = 0
  while not self._io:is_eof() do
    self.fwd_payload[i + 1] = self._io:read_u1()
    i = i + 1
  end
end

-- 
-- source identifier
-- 
-- protocol identifier
-- 
-- variable length wrapped binary message

-- 
-- Deprecated.
Logging.MsgPrintDep = class.class(KaitaiStruct)

function Logging.MsgPrintDep:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Logging.MsgPrintDep:_read()
  self.text = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- Human-readable string

