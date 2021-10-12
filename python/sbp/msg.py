#!/usr/bin/env python
# Copyright (C) 2011-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import binascii
import copy
import json
import struct
try:
  import pybase64 as base64
except ImportError:
  import base64

from sbp.constants import SENDER_ID as _SENDER_ID
from sbp.constants import SBP_PREAMBLE as _SBP_PREAMBLE


SENDER_ID = _SENDER_ID
SBP_PREAMBLE = _SBP_PREAMBLE

_HEADER_FMT = '<BHHB'
_HEADER_LEN = struct.calcsize(_HEADER_FMT)
_HEADER_PARSER = struct.Struct(_HEADER_FMT)

_CRC_FMT = '<H'
_CRC_LEN = struct.calcsize(_CRC_FMT)
_CRC_PARSER = struct.Struct(_CRC_FMT)


def try_import_jit():
  from warnings import warn

  warn("sbp.jit has been removed", UserWarning, stacklevel=1)
  return None


class UnpackError(ValueError):
  pass


def crc16(d, s=0):
  return binascii.crc_hqx(d, s)


class _StreamPayload(object):

  def __init__(self):
    self.length = None
    self.buffer = None
    self.offset = None

  def reset(self, buffer_, offset):
    self.length = 0
    self.buffer = buffer_
    self.offset = offset

  def write(self, data):
    length = len(data)
    self.buffer[self.offset:self.offset + length] = bytearray(data)
    self.length += length
    self.offset += length
    return length


class SBP(object):
  """Swift Binary Protocol container.

  """

  __slots__ = ['preamble',
               'msg_type',
               'sender',
               'length',
               'payload',
               'crc',
               'stream_payload',
               'parser']

  def __init__(self, msg_type=None, sender=SENDER_ID,
               length=None, payload=None, crc=None):
    self.preamble = SBP_PREAMBLE
    self.msg_type = msg_type
    self.sender = sender
    self.length = length
    self.payload = payload
    self.crc = crc
    self.stream_payload = _StreamPayload()
    self.parser = None

  def __eq__(self, other):
    try:
      if self is other:
        return True
      elif not isinstance(self, type(other)):
        return False
      elif self.__slots__ != other.__slots__:
        return False
      else:
        return all(getattr(self, s) == getattr(other, s) for s in self.__slots__)
    except AttributeError:
      return False

  def __update(self):
    raise NotImplementedError("Internal update used by children.")

  def _copy_payload(self, buf, offset, payload):
    length = len(payload)
    end_offset = offset + length
    buf[offset:end_offset] = bytearray(payload)
    return length

  def _get_framed(self, buf, offset, insert_payload):
    """Returns the framed message and updates the CRC.

    """
    header_offset = offset + _HEADER_LEN
    self.length = insert_payload(buf, header_offset, self.payload)
    _HEADER_PARSER.pack_into(buf,
                             offset,
                             self.preamble,
                             self.msg_type,
                             self.sender,
                             self.length)
    crc_offset = header_offset + self.length
    preamble_bytes = 1
    crc_over_len = _HEADER_LEN + self.length - preamble_bytes
    self.crc = crc16(buf[1+offset:1+offset+crc_over_len])
    _CRC_PARSER.pack_into(buf, crc_offset, self.crc)
    length = preamble_bytes + crc_over_len + _CRC_LEN
    return length

  def pack(self):
    """Pack to framed binary message."""
    buf = bytearray(512)
    packed_len = self._get_framed(buf, 0, self._copy_payload)
    return bytes(buf[:packed_len])

  def pack_into(self, buf, offset, write_payload):
    """Pack to framed binary message."""
    return self._get_framed(buf, offset, write_payload)

  @staticmethod
  def calc_crc(msg_type, sender, payload):
    msgbuf = bytearray(256)
    _HEADER_PARSER.pack_into(msgbuf, 0, SBP_PREAMBLE, msg_type, sender, len(payload))
    msgbuf[_HEADER_LEN:_HEADER_LEN+len(payload)] = payload
    return crc16(msgbuf[1:_HEADER_LEN+len(payload)])

  @staticmethod
  def unpack(d):
    """Unpack and return a framed binary message."""
    try:
      preamble, msg_type, sender, length = _HEADER_PARSER.unpack(d[:_HEADER_LEN])
    except struct.error:
      raise UnpackError("invalid header")
    assert preamble == SBP_PREAMBLE, "Invalid preamble 0x%x." % preamble
    payload = d[_HEADER_LEN:_HEADER_LEN+length]
    try:
      (crc,) = _CRC_PARSER.unpack(d[_HEADER_LEN+length:_HEADER_LEN+length+_CRC_LEN])
    except struct.error:
      raise UnpackError("invalid CRC")
    computed_crc = SBP.calc_crc(msg_type, sender, payload)
    if crc != computed_crc:
      exc = UnpackError("CRC error: computed {}, parsed {}".format(computed_crc, crc))
      exc.malformed_msg = SBP(msg_type, sender, length, payload, crc)
      raise exc
    return SBP(msg_type, sender, length, payload, crc)

  def copy(self):
    return copy.deepcopy(self)

  def __repr__(self):
    p = (self.preamble, self.msg_type, self.sender, self.length,
         repr(self.payload), self.crc)
    fmt = "<SBP (preamble=0x%X, msg_type=0x%X, sender=%s, length=%d, payload=%s, crc=0x%X)>"
    return fmt % p

  def to_binary(self):
    ret = _HEADER_PARSER.pack(SBP_PREAMBLE, self.msg_type, self.sender, len(self.payload))
    ret += self.payload
    crc = crc16(ret[1:])
    ret += _CRC_PARSER.pack(crc)
    return ret

  def to_json(self, sort_keys=False):
    """Produce a JSON-encoded SBP message."""
    d = self.to_json_dict()
    return json.dumps(d, sort_keys=sort_keys)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded message, build an object."""
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return sbp

  @staticmethod
  def from_json_dict(d):
    sbp = SBP()
    sbp.msg_type = d.pop('msg_type')
    sbp.sender = d.pop('sender')
    sbp.length = d.pop('length')
    sbp.payload = base64.standard_b64decode(d.pop('payload'))
    sbp.crc = d.pop('crc')
    return sbp

  def to_json_dict(self):
    d = {'preamble': self.preamble,
         'msg_type': self.msg_type,
         'sender': self.sender,
         'length': self.length,
         'payload': base64.standard_b64encode(self.payload).decode('ascii'),
         'crc': self.crc}
    return d

  def _build_payload(self, buf, offset, payload):
    self.stream_payload.reset(buf, offset)
    self.parser.build_stream(payload, self.stream_payload)
    return self.stream_payload.length

  def _write_payload(self, buf, offset, payload):
    self.stream_payload.reset(buf, offset)
    self.stream_payload.write(payload)
    return self.stream_payload.length

  def into_buffer(self, buf, offset):
    if self.payload:
      return self.pack_into(buf, offset, self._write_payload)
    else:
      def _empty_payload(_buf, _offset, _payload):
        return 0
      return self.pack_into(buf, offset, _empty_payload)
