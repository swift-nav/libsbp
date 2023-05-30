-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")

User = class.class(KaitaiStruct)

function User:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function User:_read()
end


-- 
-- This message can contain any application specific user data up to a
-- maximum length of 255 bytes per message.
User.MsgUserData = class.class(KaitaiStruct)

function User.MsgUserData:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function User.MsgUserData:_read()
  self.contents = {}
  local i = 0
  while not self._io:is_eof() do
    self.contents[i + 1] = self._io:read_u1()
    i = i + 1
  end
end

-- 
-- User data payload

