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


"""
Messages for using device's onboard flash filesystem
functionality. This allows data to be stored persistently in the
device's program flash with wear-levelling using a simple filesystem
interface. The file system interface (CFS) defines an abstract API
for reading directories and for reading and writing files.

These are in the implementation-defined range (0x0000-0x00FF), and
intended for internal-use only. Note that some of these messages
share the same message type ID for both the host request and the
device response.

"""

from construct import *
import json
from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/file_io.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_FILEIO_READ_REQUEST = 0x00A8
class MsgFileioReadRequest(SBP):
  """SBP class for message MSG_FILEIO_READ_REQUEST (0x00A8).

  You can have MSG_FILEIO_READ_REQUEST inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The file read message reads a certain length (up to 255 bytes)
from a given offset into a file, and returns the data in a
MSG_FILEIO_READ_RESPONSE message where the message length field
indicates how many bytes were succesfully read. If the message is
invalid, a followup MSG_PRINT message will print "Invalid fileio
read message".


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  offset : int
    File offset
  chunk_size : int
    Chunk size to read
  filename : string
    Name of the file to read from (NULL padded)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgFileioReadRequest",
                   ULInt32('offset'),
                   ULInt8('chunk_size'),
                   String('filename', 20),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgFileioReadRequest, self).__init__()
      self.msg_type = SBP_MSG_FILEIO_READ_REQUEST
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.offset = kwargs.pop('offset')
      self.chunk_size = kwargs.pop('chunk_size')
      self.filename = kwargs.pop('filename')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFileioReadRequest._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgFileioReadRequest._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgFileioReadRequest(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgFileioReadRequest, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_FILEIO_READ_RESPONSE = 0x00A3
class MsgFileioReadResponse(SBP):
  """SBP class for message MSG_FILEIO_READ_RESPONSE (0x00A3).

  You can have MSG_FILEIO_READ_RESPONSE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The file read message reads a certain length (up to 255 bytes)
from a given offset into a file, and returns the data in a
message where the message length field indicates how many bytes
were succesfully read.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  offset : int
    File offset
  chunk_size : int
    Chunk size read
  filename : string
    Name of the file read from (NULL padded)
  contents : array
    Contents of read file
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgFileioReadResponse",
                   ULInt32('offset'),
                   ULInt8('chunk_size'),
                   String('filename', 20),
                   OptionalGreedyRange(ULInt8('contents')),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgFileioReadResponse, self).__init__()
      self.msg_type = SBP_MSG_FILEIO_READ_RESPONSE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.offset = kwargs.pop('offset')
      self.chunk_size = kwargs.pop('chunk_size')
      self.filename = kwargs.pop('filename')
      self.contents = kwargs.pop('contents')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFileioReadResponse._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgFileioReadResponse._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgFileioReadResponse(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgFileioReadResponse, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_FILEIO_READ_DIR_REQUEST = 0x00A9
class MsgFileioReadDirRequest(SBP):
  """SBP class for message MSG_FILEIO_READ_DIR_REQUEST (0x00A9).

  You can have MSG_FILEIO_READ_DIR_REQUEST inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The read directory message lists the files in a directory on the
device's onboard flash file system.  The offset parameter can be
used to skip the first n elements of the file list. Returns a
MSG_FILEIO_READ_DIR_RESPONSE message containing the directory
listings as a NULL delimited list. The listing is chunked over
multiple SBP packets and the end of the list is identified by an
entry containing just the character 0xFF. If message is invalid, a
followup MSG_PRINT message will print "Invalid fileio read
message".


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  offset : int
    The offset to skip the first n elements of the file list

  dirname : string
    Name of the directory to list (NULL padded)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgFileioReadDirRequest",
                   ULInt32('offset'),
                   String('dirname', 20),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgFileioReadDirRequest, self).__init__()
      self.msg_type = SBP_MSG_FILEIO_READ_DIR_REQUEST
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.offset = kwargs.pop('offset')
      self.dirname = kwargs.pop('dirname')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFileioReadDirRequest._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgFileioReadDirRequest._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgFileioReadDirRequest(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgFileioReadDirRequest, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_FILEIO_READ_DIR_RESPONSE = 0x00AA
class MsgFileioReadDirResponse(SBP):
  """SBP class for message MSG_FILEIO_READ_DIR_RESPONSE (0x00AA).

  You can have MSG_FILEIO_READ_DIR_RESPONSE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The read directory message lists the files in a directory on the
device's onboard flash file system.  The offset parameter can be
used to skip the first n elements of the file list. Message contains
the directory listings as a NULL delimited list. The listing is
chunked over multiple SBP packets and the end of the list is
identified by an entry containing just the character 0xFF.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  offset : int
    The offset to skip the first n elements of the file list

  dirname : string
    Name of the directory to list (NULL padded)
  contents : array
    Contents of read directory
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgFileioReadDirResponse",
                   ULInt32('offset'),
                   String('dirname', 20),
                   OptionalGreedyRange(ULInt8('contents')),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgFileioReadDirResponse, self).__init__()
      self.msg_type = SBP_MSG_FILEIO_READ_DIR_RESPONSE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.offset = kwargs.pop('offset')
      self.dirname = kwargs.pop('dirname')
      self.contents = kwargs.pop('contents')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFileioReadDirResponse._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgFileioReadDirResponse._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgFileioReadDirResponse(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgFileioReadDirResponse, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_FILEIO_REMOVE = 0x00AC
class MsgFileioRemove(SBP):
  """SBP class for message MSG_FILEIO_REMOVE (0x00AC).

  You can have MSG_FILEIO_REMOVE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The file remove message deletes a file from the file system. If
message is invalid, a followup MSG_PRINT message will print
"Invalid fileio remove message".


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  filename : string
    Name of the file to delete (NULL padded)
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgFileioRemove",
                   String('filename', 20),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgFileioRemove, self).__init__()
      self.msg_type = SBP_MSG_FILEIO_REMOVE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.filename = kwargs.pop('filename')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFileioRemove._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgFileioRemove._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgFileioRemove(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgFileioRemove, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_FILEIO_WRITE_REQUEST = 0x00AD
class MsgFileioWriteRequest(SBP):
  """SBP class for message MSG_FILEIO_WRITE_REQUEST (0x00AD).

  You can have MSG_FILEIO_WRITE_REQUEST inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The file write message writes a certain length (up to 255 bytes)
of data to a file at a given offset. Returns a copy of the
original MSG_FILEIO_WRITE_RESPONSE message to check integrity of
the write. If message is invalid, a followup MSG_PRINT message
will print "Invalid fileio write message".


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  filename : string
    Name of the file to write to (NULL padded)
  offset : int
    Offset into the file at which to start writing in bytes
  data : array
    Variable-length array of data to write
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgFileioWriteRequest",
                   String('filename', 20),
                   ULInt32('offset'),
                   OptionalGreedyRange(ULInt8('data')),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgFileioWriteRequest, self).__init__()
      self.msg_type = SBP_MSG_FILEIO_WRITE_REQUEST
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.filename = kwargs.pop('filename')
      self.offset = kwargs.pop('offset')
      self.data = kwargs.pop('data')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFileioWriteRequest._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgFileioWriteRequest._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgFileioWriteRequest(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgFileioWriteRequest, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    
SBP_MSG_FILEIO_WRITE_RESPONSE = 0x00AB
class MsgFileioWriteResponse(SBP):
  """SBP class for message MSG_FILEIO_WRITE_RESPONSE (0x00AB).

  You can have MSG_FILEIO_WRITE_RESPONSE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The file write message writes a certain length (up to 255 bytes)
of data to a file at a given offset. The message is a copy of the
original MSG_FILEIO_WRITE_REQUEST message to check integrity of the
write.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  filename : string
    Name of the file to write to (NULL padded)
  offset : int
    Offset into the file at which to start writing in bytes
  data : array
    Variable-length array of data to write
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = Struct("MsgFileioWriteResponse",
                   String('filename', 20),
                   ULInt32('offset'),
                   OptionalGreedyRange(ULInt8('data')),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgFileioWriteResponse, self).__init__()
      self.msg_type = SBP_MSG_FILEIO_WRITE_RESPONSE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.filename = kwargs.pop('filename')
      self.offset = kwargs.pop('offset')
      self.data = kwargs.pop('data')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgFileioWriteResponse._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgFileioWriteResponse._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgFileioWriteResponse(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgFileioWriteResponse, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x00A8: MsgFileioReadRequest,
  0x00A3: MsgFileioReadResponse,
  0x00A9: MsgFileioReadDirRequest,
  0x00AA: MsgFileioReadDirResponse,
  0x00AC: MsgFileioRemove,
  0x00AD: MsgFileioWriteRequest,
  0x00AB: MsgFileioWriteResponse,
}