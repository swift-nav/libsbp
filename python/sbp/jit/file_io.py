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

import numba as nb
import numpy as np

from sbp.jit.msg import SBP, SENDER_ID
from sbp.jit.msg import get_u8, get_u16, get_u32, get_u64
from sbp.jit.msg import get_s8, get_s16, get_s32, get_s64
from sbp.jit.msg import get_f32, get_f64, judicious_round
from sbp.jit.msg import get_string, get_fixed_string, get_setting
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('sequence', 'u4'),
          ('offset', 'u4'),
          ('chunk_size', 'u1'),
          ('filename', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sequence', 'u4'),
          ('offset', 'u4'),
          ('chunk_size', 'u1'),
          ('filename', '|S{}'.format(count)),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype('u1')
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'sequence': int(res['sequence'] if element else res['sequence'][0]),
      'offset': int(res['offset'] if element else res['offset'][0]),
      'chunk_size': int(res['chunk_size'] if element else res['chunk_size'][0]),
      'filename': '' if res['filename'] is None else res['filename'].tostring().decode('ascii'),
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('sequence', 'u4'),
          ('contents', ('u1', (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sequence', 'u4'),
          ('contents', ('u1', (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('contents', 'u1'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'sequence': int(res['sequence'] if element else res['sequence'][0]),
      'contents': [] if res['contents'] is None else [x.item() for x in res['contents'].flatten()],
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('sequence', 'u4'),
          ('offset', 'u4'),
          ('dirname', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sequence', 'u4'),
          ('offset', 'u4'),
          ('dirname', '|S{}'.format(count)),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype('u1')
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'sequence': int(res['sequence'] if element else res['sequence'][0]),
      'offset': int(res['offset'] if element else res['offset'][0]),
      'dirname': '' if res['dirname'] is None else res['dirname'].tostring().decode('ascii'),
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('sequence', 'u4'),
          ('contents', ('u1', (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sequence', 'u4'),
          ('contents', ('u1', (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('contents', 'u1'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'sequence': int(res['sequence'] if element else res['sequence'][0]),
      'contents': [] if res['contents'] is None else [x.item() for x in res['contents'].flatten()],
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('filename', '|S{}'.format(count)),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('filename', '|S{}'.format(count)),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype('u1')
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'filename': '' if res['filename'] is None else res['filename'].tostring().decode('ascii'),
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('sequence', 'u4'),
          ('offset', 'u4'),
          ('filename', '|S{}'.format(count)),
          ('data', ('u1', (count,))),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sequence', 'u4'),
          ('offset', 'u4'),
          ('filename', '|S{}'.format(count)),
          ('data', ('u1', (count,))),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = np.dtype([('data', 'u1'),])
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'sequence': int(res['sequence'] if element else res['sequence'][0]),
      'offset': int(res['offset'] if element else res['offset'][0]),
      'filename': '' if res['filename'] is None else res['filename'].tostring().decode('ascii'),
      'data': [] if res['data'] is None else [x.item() for x in res['data'].flatten()],
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('sequence', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sequence', 'u4'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = None
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'sequence': int(res['sequence'] if element else res['sequence'][0]),
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('sequence', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sequence', 'u4'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = None
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'sequence': int(res['sequence'] if element else res['sequence'][0]),
    }
    return d

  
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
  def parse_members(self, buf, offset, length):
    dtype = self._static_dtype()
    dlength = length
    if len(dtype):
      dlength -= dtype.itemsize

    if dlength:
      ddtype = self._dynamic_dtype()
      count = dlength // ddtype.itemsize
      dtype = self._static_dtype(count)

    res, offset, length = (np.frombuffer(buf, dtype, 1, offset), offset - length, 0)

    return self._unpack_members(res), offset, length

  @classmethod
  def _static_dtype(cls, count=0):
    if count:
      return np.dtype([
          ('sequence', 'u4'),
          ('window_size', 'u4'),
          ('batch_size', 'u4'),
          ('fileio_version', 'u4'),
        ])

    t = getattr(cls, 'static_dtype0', None)
    if not t:
      t = np.dtype([
          ('sequence', 'u4'),
          ('window_size', 'u4'),
          ('batch_size', 'u4'),
          ('fileio_version', 'u4'),
        ])
      cls.static_dtype0 = t
    return t

  @classmethod
  def _dynamic_dtype(cls):
    t = getattr(cls, 'dynamic_dtype', None)
    if not t:    
      t = None
      cls.dynamic_dtype = t
    return t

  @staticmethod
  def _unpack_members(res, element=False):
    d = {
      'sequence': int(res['sequence'] if element else res['sequence'][0]),
      'window_size': int(res['window_size'] if element else res['window_size'][0]),
      'batch_size': int(res['batch_size'] if element else res['batch_size'][0]),
      'fileio_version': int(res['fileio_version'] if element else res['fileio_version'][0]),
    }
    return d

  

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