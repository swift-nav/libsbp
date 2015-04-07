#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Fergus Noble <fergus@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from construct import *
from sbp import SBP
from sbp.utils import fmt_repr
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/file_io.yaml
# with generate.py at 2015-04-06 23:40:11.122858. Please do not hand edit!


SBP_MSG_FILEIO_READ = 0x00A8
class MsgFileioRead(SBP):
  """SBP class for message MSG_FILEIO_READ (0x00A8).
  
  The file read message reads a certain length (up to 255 bytes)
from a given offset into a file, and returns the data in a
MSG_FILEIO_READ message where the message length field indicates
how many bytes were succesfully read. If the message is invalid,
a followup MsgPrint message will print "Invalid fileio read
message".


  Parameters
  ----------
  offset : int
    File offset.
  chunk_size : int
    Chunk size to read.
  filename : string
    Name of the file to read from (NULL terminated).

  """
  _parser = Struct("MsgFileioRead",
                   ULInt32('offset'),
                   ULInt8('chunk_size'),
                   String('filename', 20),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgFileioRead._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgFileioRead.build(self.__dict__)
    
SBP_MSG_FILEIO_READ_DIR = 0x00A9
class MsgFileioReadDir(SBP):
  """SBP class for message MSG_FILEIO_READ_DIR (0x00A9).
  
  The read directory message lists the files in a directory on the
Piksi's onboard flash file system.  The offset parameter can be
used to skip the first n elements of the file list. Returns a
MSG_FILEIO_READ_DIR message containing the directory listings as
a NULL delimited list. The listing is chunked over multiple SBP
packets and the end of the list is identified by an entry
containing just the character 0xFF. If message is invalid, a
followup MsgPrint message will print "Invalid fileio read
message".


  Parameters
  ----------
  offset : int
    The offset to skip the first n elements of the file list.

  dirname : string
    Name of the directory to list.

  """
  _parser = Struct("MsgFileioReadDir",
                   ULInt32('offset'),
                   String('dirname', 20),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgFileioReadDir._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgFileioReadDir.build(self.__dict__)
    
SBP_MSG_FILEIO_REMOVE = 0x00AC
class MsgFileioRemove(SBP):
  """SBP class for message MSG_FILEIO_REMOVE (0x00AC).
  
  The file remove message deletes a file from the file system. If
message is invalid, a followup MsgPrint message will print
"Invalid fileio remove message".


  Parameters
  ----------
  filename : string
    Name of the file to delete (NULL terminated)

  """
  _parser = Struct("MsgFileioRemove",
                   String('filename', 20),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgFileioRemove._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgFileioRemove.build(self.__dict__)
    
SBP_MSG_FILEIO_WRITE = 0x00AD
class MsgFileioWrite(SBP):
  """SBP class for message MSG_FILEIO_WRITE (0x00AD).
  
  The file write message writes a certain length (up to 255 bytes)
of data to a file at a given offset. Returns a copy of the
original MSG_FILEIO_WRITE message to check integrity of the
write. If message is invalid, a followup MsgPrint message will
print "Invalid fileio write message".


  Parameters
  ----------
  filename : string
    Name of the file to write to (NULL terminated)
  offset : int
    Offset into the file at which to start writing in bytes
  data : array
    Data to write

  """
  _parser = Struct("MsgFileioWrite",
                   String('filename', 20),
                   ULInt32('offset'),
                   OptionalGreedyRange(Struct('data', ULInt8('data'))),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgFileioWrite._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgFileioWrite.build(self.__dict__)
    

msg_classes = {
  0x00A8: MsgFileioRead,
  0x00A9: MsgFileioReadDir,
  0x00AC: MsgFileioRemove,
  0x00AD: MsgFileioWrite,
}