# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from .base_driver import BaseDriver
import socket
import sys
import threading

# TODO (Buro): Consider making a basic, standard library async tcp
# client: http://pymotw.com/2/asyncore/.

DEFAULT_RECV_SIZE = 1024

class TCPDriver(BaseDriver):
  """TCPDriver

  The :class:`TCPDriver` class reads SBP messages to and from a TCP
  socket.

  Parameters
  ----------
  port : string
    Path to port to read SBP messages from.
  baud : int
    Baud rate of serial port.

  """
  def __init__(self, host, port, size=DEFAULT_RECV_SIZE):
    self.handle = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    self.handle.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    self.handle.setblocking(0)
    try:
      self.handle.connect((host, port))
    except socket.error, msg:
      pass
    super(TCPDriver, self).__init__(self.handle)
    self._write_lock = threading.Lock()
    self.recv_size = size

  def read(self, size=None):
    """
    Read wrapper.

    Parameters
    ----------
    size : int
      Number of bytes to read
    """
    try:
      data = self.handle.recv(self.recv_size)
      return data
    except socket.error, msg:
      pass

  def flush(self):
    pass

  def write(self, s):
    """
    Write wrapper.

    Parameters
    ----------
    s : bytes
      Bytes to write
    """
    try:
      self._write_lock.acquire()
      self.handle.sendall(s)
    except socket.error, msg:
      pass
    finally:
      self._write_lock.release()
