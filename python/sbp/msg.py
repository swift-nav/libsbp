#!/usr/bin/env python
# Copyright (C) 2011-2014 Swift Navigation Inc.
# Contact: Fergus Noble <fergus@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import base64
import copy
import json
import struct

import construct

from sbp.constants import SENDER_ID as _SENDER_ID
from sbp.constants import SBP_PREAMBLE as _SBP_PREAMBLE
from sbp.constants import crc16_tab


from pkgutil import iter_modules

import sys

SENDER_ID = _SENDER_ID
SBP_PREAMBLE = _SBP_PREAMBLE

NOJIT = False
NONUMPY = False

try:
  import importlib
  import numpy as np
except ImportError:
  NONUMPY = True

parse_jit_crc16 = None
parse_jit = None


def try_import_jit():
  '''
  Try to import the pre-compiled version of the "jit" libraries for parsing SBP data.
  This should only fail on systems that do not have support for Numba (or LLVM).  For
  system where it does fail, we fall back to parsing without the pre-compile (or JIT
  compiled) module.
  '''
  parse_jit_name = "parse_jit_py{}".format(str(sys.version_info[0]) + str(sys.version_info[1]))
  if parse_jit_name in (name for loader, name, ispkg in iter_modules()):
    # found in sys.path
    parse_jit = importlib.import_module(parse_jit_name)
  elif parse_jit_name in (name for loader, name, ispkg in iter_modules(['sbp/jit'])):
    # found in sbp.jit
    parse_jit = importlib.import_module('sbp.jit.' + parse_jit_name)
  else:
    # not found -> compile
    try:
      from sbp.jit import parse
      parse.compile()
      parse_jit = importlib.import_module('sbp.jit.' + parse_jit_name)
    except ImportError:
      return None
  return parse_jit


def no_jit_fallback():
  global parse_jit_crc16
  global np_crc16_tab
  global crc_buffer
  global parse_jit
  np_crc16_tab = None
  crc_buffer = None
  parse_jit = None
  def _parse_jit_crc16(buf, offset, crc, l):
    _crc_buffer = bytearray(buf[offset:(offset+l)])
    return crc16_nojit(_crc_buffer, crc)
  parse_jit_crc16 = _parse_jit_crc16


if not NONUMPY:
  np_crc16_tab = np.array(crc16_tab, dtype=np.uint16)
  crc_buffer = np.zeros(512, dtype=np.uint8)
  parse_jit = try_import_jit()
  if parse_jit is not None:
    parse_jit_crc16 = parse_jit.crc16jit
  else:
    NOJIT = True
    no_jit_fallback()
else:
  no_jit_fallback()


def crc16(s, crc=0):
  if NONUMPY or NOJIT:
    return crc16_nojit(s, crc)
  crc_buffer[:len(s)] = bytearray(s)
  return parse_jit.crc16jit(crc_buffer, 0, crc, len(s))


def crc16_nojit(s, crc=0):
  """CRC16 implementation acording to CCITT standards."""
  for ch in bytearray(s):  # bytearray's elements are integers in both python 2 and 3
    crc = ((crc << 8) & 0xFFFF) ^ crc16_tab[((crc >> 8) & 0xFF) ^ (ch & 0xFF)]
    crc &= 0xFFFF
  return crc


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

  _parser = construct.Struct(
                   'preamble'/construct.Int8ul,
                   'msg_type'/construct.Int16ul,
                   'sender'/construct.Int16ul,
                   'length'/construct.Int8ul,
                   'payload'/construct.Bytes(lambda ctx: ctx.length),
                   'crc'/construct.Int16ul,)
  __slots__ = ['preamble',
               'msg_type',
               'sender',
               'length',
               'payload',
               'crc',
               'stream_payload',
               'parser']

  _header_fmt = '<BHHB'
  _header_len = struct.calcsize(_header_fmt)

  _crc_fmt = '<H'
  _crc_len = struct.calcsize(_crc_fmt)

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
    header_offset = offset + self._header_len
    self.length = insert_payload(buf, header_offset, self.payload)
    struct.pack_into(self._header_fmt,
                     buf,
                     offset,
                     self.preamble,
                     self.msg_type,
                     self.sender,
                     self.length)
    crc_offset = header_offset + self.length
    preamble_bytes = 1
    crc_over_len = self._header_len + self.length - preamble_bytes
    self.crc = parse_jit_crc16(buf, offset+1, 0, crc_over_len)
    struct.pack_into(self._crc_fmt, buf, crc_offset, self.crc)
    length = preamble_bytes + crc_over_len + self._crc_len
    return length

  def pack(self):
    """Pack to framed binary message.

    """
    if NONUMPY:
      buf = bytearray(512)
      packed_len = self._get_framed(buf, 0, self._copy_payload)
      return bytes(buf[:packed_len])
    else:
      buf = np.zeros(512, dtype=np.uint8)
      packed_len = self._get_framed(buf, 0, self._copy_payload)
      d = buf[:packed_len]
      return d.tobytes()

  def pack_into(self, buf, offset, write_payload):
    """Pack to framed binary message.

    """
    return self._get_framed(buf, offset, write_payload)

  @staticmethod
  def calc_crc(msg):
    ret = struct.pack("<BHHB", SBP_PREAMBLE, msg.msg_type, msg.sender, len(msg.payload))
    ret += msg.payload
    return crc16(ret[1:])

  @staticmethod
  def unpack(d):
    """Unpack and return a framed binary message.

    """
    p = SBP._parser.parse(d)

    assert p.preamble == SBP_PREAMBLE, "Invalid preamble 0x%x." % p.preamble

    if p.crc != SBP.calc_crc(p):
      exc = ValueError("CRC error")
      exc.malformed_msg = SBP(p.msg_type, p.sender, p.length, p.payload, p.crc)
      raise exc

    return SBP(p.msg_type, p.sender, p.length, p.payload, p.crc)

  def copy(self):
    return copy.deepcopy(self)

  def __repr__(self):
    p = (self.preamble, self.msg_type, self.sender, self.length,
         repr(self.payload), self.crc)
    fmt = "<SBP (preamble=0x%X, msg_type=0x%X, sender=%s, length=%d, payload=%s, crc=0x%X)>"
    return fmt % p

  def to_binary(self):
    ret = struct.pack("<BHHB", SBP_PREAMBLE,
                      self.msg_type, self.sender, len(self.payload))
    ret += self.payload
    crc = crc16(ret[1:])
    ret += struct.pack("<H", crc)
    return ret

  def to_json(self, sort_keys=False):
    """Produce a JSON-encoded SBP message.

    """
    d = self.to_json_dict()
    return json.dumps(d, sort_keys=sort_keys)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded message, build an object.

    """
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
