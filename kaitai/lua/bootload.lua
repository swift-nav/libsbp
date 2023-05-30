-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")
local str_decode = require("string_decode")

Bootload = class.class(KaitaiStruct)

function Bootload:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Bootload:_read()
end


-- 
-- The device message from the host reads a unique device identifier from
-- the SwiftNAP, an FPGA. The host requests the ID by sending a
-- MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
-- MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
-- that this ID is tied to the FPGA, and not related to the Piksi's serial
-- number.
Bootload.MsgNapDeviceDnaReq = class.class(KaitaiStruct)

function Bootload.MsgNapDeviceDnaReq:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Bootload.MsgNapDeviceDnaReq:_read()
end


-- 
-- The host initiates the bootloader to jump to the application.
Bootload.MsgBootloaderJumpToApp = class.class(KaitaiStruct)

function Bootload.MsgBootloaderJumpToApp:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Bootload.MsgBootloaderJumpToApp:_read()
  self.jump = self._io:read_u1()
end

-- 
-- Ignored by the device

-- 
-- The handshake message response from the device establishes a handshake
-- between the device bootloader and the host. The request from the host is
-- MSG_BOOTLOADER_HANDSHAKE_REQ.  The payload contains the bootloader
-- version number and the SBP protocol version number.
Bootload.MsgBootloaderHandshakeResp = class.class(KaitaiStruct)

function Bootload.MsgBootloaderHandshakeResp:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Bootload.MsgBootloaderHandshakeResp:_read()
  self.flags = self._io:read_u4le()
  self.version = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- Bootloader flags
-- 
-- Bootloader version number

-- 
-- The device message from the host reads a unique device identifier from
-- the SwiftNAP, an FPGA. The host requests the ID by sending a
-- MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
-- MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note
-- that this ID is tied to the FPGA, and not related to the Piksi's serial
-- number.
Bootload.MsgNapDeviceDnaResp = class.class(KaitaiStruct)

function Bootload.MsgNapDeviceDnaResp:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Bootload.MsgNapDeviceDnaResp:_read()
  self.dna = {}
  for i = 0, 8 - 1 do
    self.dna[i + 1] = self._io:read_u1()
  end
end

-- 
-- 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the
-- right.

-- 
-- The handshake message request from the host establishes a handshake
-- between the device bootloader and the host. The response from the device
-- is MSG_BOOTLOADER_HANDSHAKE_RESP.
Bootload.MsgBootloaderHandshakeReq = class.class(KaitaiStruct)

function Bootload.MsgBootloaderHandshakeReq:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Bootload.MsgBootloaderHandshakeReq:_read()
end


-- 
-- Deprecated.
Bootload.MsgBootloaderHandshakeDepA = class.class(KaitaiStruct)

function Bootload.MsgBootloaderHandshakeDepA:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Bootload.MsgBootloaderHandshakeDepA:_read()
  self.handshake = {}
  local i = 0
  while not self._io:is_eof() do
    self.handshake[i + 1] = self._io:read_u1()
    i = i + 1
  end
end

-- 
-- Version number string (not NULL terminated)

