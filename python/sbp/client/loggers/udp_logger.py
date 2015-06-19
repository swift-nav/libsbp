# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import socket
import struct

from .base_logger import BaseLogger

class UdpLogger(BaseLogger):
  """
  UdpLogger

  The :class:`UdpLogger` logs SBP messages over UDP.

  Parameters
  ----------
  address : string
    IP Address to send UDP packets to.
  port : int
    IP Port to send UDP packets to.
  """
  def __init__(self, address, port):
    self.handle = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    self.address = address
    self.port = port

  def __call__(self, msg):
    self.call(msg)

  def fmt_msg(self, msg):
    s = ""
    s += struct.pack("<BHHB", 0x55, msg.msg_type, msg.sender, msg.length)
    s += msg.payload
    s += struct.pack("<H", msg.crc)
    return s

  def flush(self):
    pass

  def call(self, msg):
    self.handle.sendto(self.fmt_msg(msg), (self.address, self.port))
