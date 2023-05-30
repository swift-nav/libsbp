-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

Flash = class.class(KaitaiStruct)

function Flash:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Flash:_read()
end


-- 
-- This message defines success or failure codes for a variety of flash
-- memory requests from the host to the device. Flash read and write
-- messages, such as MSG_FLASH_READ_REQ, or MSG_FLASH_PROGRAM, may return
-- this message on failure.
Flash.MsgFlashDone = class.class(KaitaiStruct)

function Flash.MsgFlashDone:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Flash.MsgFlashDone:_read()
  self.response = self._io:read_u1()
end

-- 
-- Response flags

-- 
-- The flash status message writes to the 8-bit M25 flash status register.
-- The device replies with a MSG_FLASH_DONE message.
Flash.MsgM25FlashWriteStatus = class.class(KaitaiStruct)

function Flash.MsgM25FlashWriteStatus:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Flash.MsgM25FlashWriteStatus:_read()
  self.status = {}
  for i = 0, 1 - 1 do
    self.status[i + 1] = self._io:read_u1()
  end
end

-- 
-- Byte to write to the M25 flash status register

-- 
-- The flash read message reads a set of addresses of either the STM or M25
-- onboard flash. The device replies with a MSG_FLASH_READ_RESP message
-- containing either the read data on success or a MSG_FLASH_DONE message
-- containing the return code FLASH_INVALID_LEN (2) if the maximum read
-- size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
-- the allowed range.
Flash.MsgFlashReadResp = class.class(KaitaiStruct)

function Flash.MsgFlashReadResp:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Flash.MsgFlashReadResp:_read()
  self.target = self._io:read_u1()
  self.addr_start = {}
  for i = 0, 3 - 1 do
    self.addr_start[i + 1] = self._io:read_u1()
  end
  self.addr_len = self._io:read_u1()
end

-- 
-- Target flags
-- 
-- Starting address offset to read from
-- 
-- Length of set of addresses to read, counting up from starting
-- address

-- 
-- The flash erase message from the host erases a sector of either the STM
-- or M25 onboard flash memory. The device will reply with a MSG_FLASH_DONE
-- message containing the return code - FLASH_OK (0) on success or
-- FLASH_INVALID_FLASH (1) if the flash specified is invalid.
Flash.MsgFlashErase = class.class(KaitaiStruct)

function Flash.MsgFlashErase:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Flash.MsgFlashErase:_read()
  self.target = self._io:read_u1()
  self.sector_num = self._io:read_u4le()
end

-- 
-- Target flags
-- 
-- Flash sector number to erase (0-11 for the STM, 0-15 for the M25)

-- 
-- This message reads the device's hard-coded unique ID. The host requests
-- the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
-- MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
Flash.MsgStmUniqueIdResp = class.class(KaitaiStruct)

function Flash.MsgStmUniqueIdResp:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Flash.MsgStmUniqueIdResp:_read()
  self.stm_id = {}
  for i = 0, 12 - 1 do
    self.stm_id[i + 1] = self._io:read_u1()
  end
end

-- 
-- Device unique ID

-- 
-- This message reads the device's hard-coded unique ID. The host requests
-- the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device responds with a
-- MSG_STM_UNIQUE_ID_RESP with the 12-byte unique ID in the payload.
Flash.MsgStmUniqueIdReq = class.class(KaitaiStruct)

function Flash.MsgStmUniqueIdReq:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Flash.MsgStmUniqueIdReq:_read()
end


-- 
-- The flash program message programs a set of addresses of either the STM
-- or M25 flash. The device replies with either a MSG_FLASH_DONE message
-- containing the return code FLASH_OK (0) on success, or FLASH_INVALID_LEN
-- (2) if the maximum write size is exceeded. Note that the sector-
-- containing addresses must be erased before addresses can be programmed.
Flash.MsgFlashProgram = class.class(KaitaiStruct)

function Flash.MsgFlashProgram:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Flash.MsgFlashProgram:_read()
  self.target = self._io:read_u1()
  self.addr_start = {}
  for i = 0, 3 - 1 do
    self.addr_start[i + 1] = self._io:read_u1()
  end
  self.addr_len = self._io:read_u1()
  self.data = {}
  local i = 0
  while not self._io:is_eof() do
    self.data[i + 1] = self._io:read_u1()
    i = i + 1
  end
end

-- 
-- Target flags
-- 
-- Starting address offset to program
-- 
-- Length of set of addresses to program, counting up from starting
-- address
-- 
-- Data to program addresses with, with length N=addr_len

-- 
-- The flash read message reads a set of addresses of either the STM or M25
-- onboard flash. The device replies with a MSG_FLASH_READ_RESP message
-- containing either the read data on success or a MSG_FLASH_DONE message
-- containing the return code FLASH_INVALID_LEN (2) if the maximum read
-- size is exceeded or FLASH_INVALID_ADDR (3) if the address is outside of
-- the allowed range.
Flash.MsgFlashReadReq = class.class(KaitaiStruct)

function Flash.MsgFlashReadReq:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Flash.MsgFlashReadReq:_read()
  self.target = self._io:read_u1()
  self.addr_start = {}
  for i = 0, 3 - 1 do
    self.addr_start[i + 1] = self._io:read_u1()
  end
  self.addr_len = self._io:read_u1()
end

-- 
-- Target flags
-- 
-- Starting address offset to read from
-- 
-- Length of set of addresses to read, counting up from starting
-- address

-- 
-- The flash unlock message unlocks a sector of the STM flash memory. The
-- device replies with a MSG_FLASH_DONE message.
Flash.MsgStmFlashUnlockSector = class.class(KaitaiStruct)

function Flash.MsgStmFlashUnlockSector:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Flash.MsgStmFlashUnlockSector:_read()
  self.sector = self._io:read_u4le()
end

-- 
-- Flash sector number to unlock

-- 
-- The flash lock message locks a sector of the STM flash memory. The
-- device replies with a MSG_FLASH_DONE message.
Flash.MsgStmFlashLockSector = class.class(KaitaiStruct)

function Flash.MsgStmFlashLockSector:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function Flash.MsgStmFlashLockSector:_read()
  self.sector = self._io:read_u4le()
end

-- 
-- Flash sector number to lock

