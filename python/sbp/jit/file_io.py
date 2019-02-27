#!/usr/bin/env python
# Copyright (C) 2015-2018 Swift Navigation Inc.
# Contact: Swift Navigation <dev@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.


"""
Messages for using device's onboard flash filesystem
functionality. This allows data to be stored persistently in the
device's program flash with wear-levelling using a simple filesystem
interface. The file system interface (CFS) defines an abstract API
for reading directories and for reading and writing files.

Note that some of these messages share the same message type ID for both the
host request and the device response.

"""

import json

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64
from sbp.jit.msg import get_string, get_fixed_string
from sbp.jit.msg import get_array, get_fixed_array

# Automatically generated from piksi/yaml/swiftnav/sbp/file_io.yaml with generate.py.
# Please do not hand edit!
SBP_MSG_FILEIO_READ_REQ = 0x00A8
class MsgFileioReadReq(SBP):
  """SBP class for message MSG_FILEIO_READ_REQ (0x00A8).

  You can have MSG_FILEIO_READ_REQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The file read message reads a certain length (up to 255 bytes)
from a given offset into a file, and returns the data in a
MSG_FILEIO_READ_RESP message where the message length field
indicates how many bytes were succesfully read.The sequence
number in the request will be returned in the response.
If the message is invalid, a followup MSG_PRINT message will
print "Invalid fileio read message". A device will only respond
to this message when it is received from sender ID 0x42.


  """
  __slots__ = ['sequence',
               'offset',
               'chunk_size',
               'filename',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__sequence, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__offset, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__chunk_size, offset, length) = offset, get_u8(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__filename, offset, length) = offset, get_string(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'sequence' : __sequence,
      'offset' : __offset,
      'chunk_size' : __chunk_size,
      'filename' : __filename,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sequence = res['sequence']
    self.offset = res['offset']
    self.chunk_size = res['chunk_size']
    self.filename = res['filename']
    return res, off, length
  
SBP_MSG_FILEIO_READ_RESP = 0x00A3
class MsgFileioReadResp(SBP):
  """SBP class for message MSG_FILEIO_READ_RESP (0x00A3).

  You can have MSG_FILEIO_READ_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The file read message reads a certain length (up to 255 bytes)
from a given offset into a file, and returns the data in a
message where the message length field indicates how many bytes
were succesfully read. The sequence number in the response is
preserved from the request.


  """
  __slots__ = ['sequence',
               'contents',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__sequence, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__contents, offset, length) = offset, get_array(get_u8)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'sequence' : __sequence,
      'contents' : __contents,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sequence = res['sequence']
    self.contents = res['contents']
    return res, off, length
  
SBP_MSG_FILEIO_READ_DIR_REQ = 0x00A9
class MsgFileioReadDirReq(SBP):
  """SBP class for message MSG_FILEIO_READ_DIR_REQ (0x00A9).

  You can have MSG_FILEIO_READ_DIR_REQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The read directory message lists the files in a directory on the
device's onboard flash file system.  The offset parameter can be
used to skip the first n elements of the file list. Returns a
MSG_FILEIO_READ_DIR_RESP message containing the directory
listings as a NULL delimited list. The listing is chunked over
multiple SBP packets. The sequence number in the request will be
returned in the response.  If message is invalid, a followup
MSG_PRINT message will print "Invalid fileio read message".
A device will only respond to this message when it is received
from sender ID 0x42.


  """
  __slots__ = ['sequence',
               'offset',
               'dirname',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__sequence, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__offset, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__dirname, offset, length) = offset, get_string(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'sequence' : __sequence,
      'offset' : __offset,
      'dirname' : __dirname,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sequence = res['sequence']
    self.offset = res['offset']
    self.dirname = res['dirname']
    return res, off, length
  
SBP_MSG_FILEIO_READ_DIR_RESP = 0x00AA
class MsgFileioReadDirResp(SBP):
  """SBP class for message MSG_FILEIO_READ_DIR_RESP (0x00AA).

  You can have MSG_FILEIO_READ_DIR_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The read directory message lists the files in a directory on the
device's onboard flash file system. Message contains the directory
listings as a NULL delimited list. The listing is chunked over
multiple SBP packets and the end of the list is identified by an
entry containing just the character 0xFF. The sequence number in
the response is preserved from the request.


  """
  __slots__ = ['sequence',
               'contents',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__sequence, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__contents, offset, length) = offset, get_array(get_u8)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'sequence' : __sequence,
      'contents' : __contents,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sequence = res['sequence']
    self.contents = res['contents']
    return res, off, length
  
SBP_MSG_FILEIO_REMOVE = 0x00AC
class MsgFileioRemove(SBP):
  """SBP class for message MSG_FILEIO_REMOVE (0x00AC).

  You can have MSG_FILEIO_REMOVE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The file remove message deletes a file from the file system.
If the message is invalid, a followup MSG_PRINT message will
print "Invalid fileio remove message". A device will only
process this message when it is received from sender ID 0x42.


  """
  __slots__ = ['filename',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__filename, offset, length) = offset, get_string(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'filename' : __filename,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.filename = res['filename']
    return res, off, length
  
SBP_MSG_FILEIO_WRITE_REQ = 0x00AD
class MsgFileioWriteReq(SBP):
  """SBP class for message MSG_FILEIO_WRITE_REQ (0x00AD).

  You can have MSG_FILEIO_WRITE_REQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The file write message writes a certain length (up to 255 bytes)
of data to a file at a given offset. Returns a copy of the
original MSG_FILEIO_WRITE_RESP message to check integrity of
the write. The sequence number in the request will be returned
in the response. If message is invalid, a followup MSG_PRINT
message will print "Invalid fileio write message". A device will
only  process this message when it is received from sender ID
0x42.


  """
  __slots__ = ['sequence',
               'offset',
               'filename',
               'data',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__sequence, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__offset, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__filename, offset, length) = offset, get_string(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__data, offset, length) = offset, get_array(get_u8)(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'sequence' : __sequence,
      'offset' : __offset,
      'filename' : __filename,
      'data' : __data,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sequence = res['sequence']
    self.offset = res['offset']
    self.filename = res['filename']
    self.data = res['data']
    return res, off, length
  
SBP_MSG_FILEIO_WRITE_RESP = 0x00AB
class MsgFileioWriteResp(SBP):
  """SBP class for message MSG_FILEIO_WRITE_RESP (0x00AB).

  You can have MSG_FILEIO_WRITE_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The file write message writes a certain length (up to 255 bytes)
of data to a file at a given offset. The message is a copy of the
original MSG_FILEIO_WRITE_REQ message to check integrity of the
write. The sequence number in the response is preserved from the
request.


  """
  __slots__ = ['sequence',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__sequence, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'sequence' : __sequence,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sequence = res['sequence']
    return res, off, length
  
SBP_MSG_FILEIO_CONFIG_REQ = 0x1001
class MsgFileioConfigReq(SBP):
  """SBP class for message MSG_FILEIO_CONFIG_REQ (0x1001).

  You can have MSG_FILEIO_CONFIG_REQ inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  Requests advice on the optimal configuration for a FileIO 
transfer.  Newer version of FileIO can support greater
throughput by supporting a large window of FileIO data
that can be in-flight during read or write operations.


  """
  __slots__ = ['sequence',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__sequence, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'sequence' : __sequence,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sequence = res['sequence']
    return res, off, length
  
SBP_MSG_FILEIO_CONFIG_RESP = 0x1002
class MsgFileioConfigResp(SBP):
  """SBP class for message MSG_FILEIO_CONFIG_RESP (0x1002).

  You can have MSG_FILEIO_CONFIG_RESP inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The advice on the optimal configuration for a FileIO
transfer.  Newer version of FileIO can support greater
throughput by supporting a large window of FileIO data
that can be in-flight during read or write operations.


  """
  __slots__ = ['sequence',
               'window_size',
               'batch_size',
               'fileio_version',
               ]
  @classmethod
  def parse_members(cls, buf, offset, length):
    o_0 = offset
    o_1, (__sequence, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__window_size, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__batch_size, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    o_1, (__fileio_version, offset, length) = offset, get_u32(buf, offset, length)
    if o_1 == offset:
      return {}, o_0, length
    return {
      'sequence' : __sequence,
      'window_size' : __window_size,
      'batch_size' : __batch_size,
      'fileio_version' : __fileio_version,
    }, offset, length

  def _unpack_members(self, buf, offset, length):
    res, off, length = self.parse_members(buf, offset, length)
    if off == offset:
      return {}, offset, length
    self.sequence = res['sequence']
    self.window_size = res['window_size']
    self.batch_size = res['batch_size']
    self.fileio_version = res['fileio_version']
    return res, off, length
  

msg_classes = {
  0x00A8: MsgFileioReadReq,
  0x00A3: MsgFileioReadResp,
  0x00A9: MsgFileioReadDirReq,
  0x00AA: MsgFileioReadDirResp,
  0x00AC: MsgFileioRemove,
  0x00AD: MsgFileioWriteReq,
  0x00AB: MsgFileioWriteResp,
  0x1001: MsgFileioConfigReq,
  0x1002: MsgFileioConfigResp,
}