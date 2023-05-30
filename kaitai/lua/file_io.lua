-- This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
--
-- This file is compatible with Lua 5.3

local class = require("class")
require("kaitaistruct")
local str_decode = require("string_decode")

FileIo = class.class(KaitaiStruct)

function FileIo:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function FileIo:_read()
end


-- 
-- The file write message writes a certain length (up to 255 bytes) of data
-- to a file at a given offset. Returns a copy of the original
-- MSG_FILEIO_WRITE_RESP message to check integrity of the write. The
-- sequence number in the request will be returned in the response. If
-- message is invalid, a followup MSG_PRINT message will print "Invalid
-- fileio write message". A device will only process this message when it
-- is received from sender ID 0x42.
FileIo.MsgFileioWriteReq = class.class(KaitaiStruct)

function FileIo.MsgFileioWriteReq:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function FileIo.MsgFileioWriteReq:_read()
  self.sequence = self._io:read_u4le()
  self.offset = self._io:read_u4le()
  self.filename = str_decode.decode(self._io:read_bytes_full(), "ascii")
  self.data = {}
  local i = 0
  while not self._io:is_eof() do
    self.data[i + 1] = self._io:read_u1()
    i = i + 1
  end
end

-- 
-- Write sequence number
-- 
-- Offset into the file at which to start writing in bytes
-- 
-- Name of the file to write to
-- 
-- Variable-length array of data to write

-- 
-- The advice on the optimal configuration for a FileIO transfer.  Newer
-- version of FileIO can support greater throughput by supporting a large
-- window of FileIO data that can be in-flight during read or write
-- operations.
FileIo.MsgFileioConfigResp = class.class(KaitaiStruct)

function FileIo.MsgFileioConfigResp:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function FileIo.MsgFileioConfigResp:_read()
  self.sequence = self._io:read_u4le()
  self.window_size = self._io:read_u4le()
  self.batch_size = self._io:read_u4le()
  self.fileio_version = self._io:read_u4le()
end

-- 
-- Advice sequence number
-- 
-- The number of SBP packets in the data in-flight window
-- 
-- The number of SBP packets sent in one PDU
-- 
-- The version of FileIO that is supported

-- 
-- The file remove message deletes a file from the file system. If the
-- message is invalid, a followup MSG_PRINT message will print "Invalid
-- fileio remove message". A device will only process this message when it
-- is received from sender ID 0x42.
FileIo.MsgFileioRemove = class.class(KaitaiStruct)

function FileIo.MsgFileioRemove:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function FileIo.MsgFileioRemove:_read()
  self.filename = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- Name of the file to delete

-- 
-- Requests advice on the optimal configuration for a FileIO transfer.
-- Newer version of FileIO can support greater throughput by supporting a
-- large window of FileIO data that can be in-flight during read or write
-- operations.
FileIo.MsgFileioConfigReq = class.class(KaitaiStruct)

function FileIo.MsgFileioConfigReq:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function FileIo.MsgFileioConfigReq:_read()
  self.sequence = self._io:read_u4le()
end

-- 
-- Advice sequence number

-- 
-- The read directory message lists the files in a directory on the
-- device's onboard flash file system.  The offset parameter can be used to
-- skip the first n elements of the file list. Returns a
-- MSG_FILEIO_READ_DIR_RESP message containing the directory listings as a
-- NULL delimited list. The listing is chunked over multiple SBP packets.
-- The sequence number in the request will be returned in the response.  If
-- message is invalid, a followup MSG_PRINT message will print "Invalid
-- fileio read message". A device will only respond to this message when it
-- is received from sender ID 0x42.
FileIo.MsgFileioReadDirReq = class.class(KaitaiStruct)

function FileIo.MsgFileioReadDirReq:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function FileIo.MsgFileioReadDirReq:_read()
  self.sequence = self._io:read_u4le()
  self.offset = self._io:read_u4le()
  self.dirname = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- Read sequence number
-- 
-- The offset to skip the first n elements of the file list
-- 
-- Name of the directory to list

-- 
-- The file write message writes a certain length (up to 255 bytes) of data
-- to a file at a given offset. The message is a copy of the original
-- MSG_FILEIO_WRITE_REQ message to check integrity of the write. The
-- sequence number in the response is preserved from the request.
FileIo.MsgFileioWriteResp = class.class(KaitaiStruct)

function FileIo.MsgFileioWriteResp:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function FileIo.MsgFileioWriteResp:_read()
  self.sequence = self._io:read_u4le()
end

-- 
-- Write sequence number

-- 
-- The read directory message lists the files in a directory on the
-- device's onboard flash file system. Message contains the directory
-- listings as a NULL delimited list. The listing is chunked over multiple
-- SBP packets and the end of the list is identified by an packet with no
-- entries. The sequence number in the response is preserved from the
-- request.
FileIo.MsgFileioReadDirResp = class.class(KaitaiStruct)

function FileIo.MsgFileioReadDirResp:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function FileIo.MsgFileioReadDirResp:_read()
  self.sequence = self._io:read_u4le()
  self.contents = {}
  local i = 0
  while not self._io:is_eof() do
    self.contents[i + 1] = self._io:read_u1()
    i = i + 1
  end
end

-- 
-- Read sequence number
-- 
-- Contents of read directory

-- 
-- The file read message reads a certain length (up to 255 bytes) from a
-- given offset into a file, and returns the data in a MSG_FILEIO_READ_RESP
-- message where the message length field indicates how many bytes were
-- successfully read. The sequence number in the request will be returned
-- in the response. If the message is invalid, a followup MSG_PRINT message
-- will print "Invalid fileio read message". A device will only respond to
-- this message when it is received from sender ID 0x42.
FileIo.MsgFileioReadReq = class.class(KaitaiStruct)

function FileIo.MsgFileioReadReq:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function FileIo.MsgFileioReadReq:_read()
  self.sequence = self._io:read_u4le()
  self.offset = self._io:read_u4le()
  self.chunk_size = self._io:read_u1()
  self.filename = str_decode.decode(self._io:read_bytes_full(), "ascii")
end

-- 
-- Read sequence number
-- 
-- File offset
-- 
-- Chunk size to read
-- 
-- Name of the file to read from

-- 
-- The file read message reads a certain length (up to 255 bytes) from a
-- given offset into a file, and returns the data in a message where the
-- message length field indicates how many bytes were successfully read.
-- The sequence number in the response is preserved from the request.
FileIo.MsgFileioReadResp = class.class(KaitaiStruct)

function FileIo.MsgFileioReadResp:_init(io, parent, root)
  KaitaiStruct._init(self, io)
  self._parent = parent
  self._root = root or self
  self:_read()
end

function FileIo.MsgFileioReadResp:_read()
  self.sequence = self._io:read_u4le()
  self.contents = {}
  local i = 0
  while not self._io:is_eof() do
    self.contents[i + 1] = self._io:read_u1()
    i = i + 1
  end
end

-- 
-- Read sequence number
-- 
-- Contents of read file

