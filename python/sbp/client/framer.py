# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from ..msg import crc16, SBP, SBP_PREAMBLE
from ..table import dispatch

import struct
import calendar
import time

class Framer(object):
  """
  Framer

  The :class:`Framer` class frames bytes into SBP messages.
  Implements the Python iterator protocol for received messages.

  Parameters
  ----------
  read : port
    Stream of bytes to read from.
  write : port
    Stream of bytes to write to.
  """
  def __init__(self, read, write, verbose=False, dispatcher=dispatch):
    self._read = read
    self._write = write
    self._verbose = verbose
    self._broken = False
    self._base_time = self._timestamp()
    self._dispatch = dispatcher

  def __iter__(self):
    self._broken = False
    return self

  def breakiter(self):
    """
    Break out of message iteration.
    May be called from another thread when some thread is blocked in next().
    """
    self._broken = True

  def _timestamp(self):
    """
    Timestamp generator.
    """
    return calendar.timegm(time.gmtime())

  def _delta(self):
    """
    Relevant time differential generator.
    """
    return int((time.time() - self._base_time) * 1000)

  def next(self):
    msg = None
    while msg is None:
      try:
        msg = self._receive()
        if self._broken:
          raise StopIteration
      except IOError:
        raise StopIteration
    return (msg, {'delta':self._delta(), 'timestamp':self._timestamp()})

  def _readall(self, size):
    """
    Read until all bytes are collected.

    Parameters
    ----------
    size : int
      Number of bytes to read.
    """
    data = ""
    while len(data) < size:
      data += self._read(size - len(data))
      if self._broken:
        return data
    return data

  def _receive(self):
    """
    Read and build SBP message.
    """
    # preamble - not readall(1) to allow breaking before messages, empty input
    preamble = self._read(1)
    if not preamble:
      return None
    elif ord(preamble) != SBP_PREAMBLE:
      if self._verbose:
        print "Host Side Unhandled byte: 0x%02x" % ord(preamble)
      return None
    # hdr
    hdr = self._readall(5)
    msg_crc = crc16(hdr)
    msg_type, sender, msg_len = struct.unpack("<HHB", hdr)
    # data
    data = self._readall(msg_len)
    msg_crc = crc16(data, msg_crc)
    # crc
    crc = self._readall(2)
    crc, = struct.unpack("<H", crc)
    if crc != msg_crc:
      print "crc mismatch: 0x%04X 0x%04X" % (msg_crc, crc)
      return None
    msg = SBP(msg_type, sender, msg_len, data, crc)
    try:
      msg = self._dispatch(msg)
    except:
      pass
    return msg

  def __call__(self, msg, **metadata):
    """
    Build and write SBP message.

    Parameters
    ----------
    delta : float
      Ignored
    time : float
      Ignored
    msg : SBP message
      SBP message to send.
    """
    self._write(msg.to_binary())

