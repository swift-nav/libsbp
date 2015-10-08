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
import requests
import socket
import sys
import threading
import warnings

# TODO (Buro): Consider making a basic, standard library async tcp
# client: http://pymotw.com/2/asyncore/.

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
  def __init__(self, host, port):
    self.handle = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    self.handle.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    try:
      self.handle.connect((host, port))
    except socket.error, msg:
      pass
    super(TCPDriver, self).__init__(self.handle)
    self._write_lock = threading.Lock()

  def read(self, size):
    """
    Read wrapper.

    Parameters
    ----------
    size : int
      Number of bytes to read
    """
    try:
      data = self.handle.recv(size)
      if not data:
        raise IOError
      return data
    except socket.error, msg:
      raise IOError

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
      raise IOError
    finally:
      self._write_lock.release()


class HTTPDriver(BaseDriver):
  """HTTPDriver

  The :class:`HTTPDriver` class reads SBP messages from an HTTP
  service for a device.

  Parameters
  ----------
  device_uid : uid
    Device unique id
  url : str
    HTTP endpoint

  """

  def __init__(self, device_uid, url='http://skylark.swiftnav.com'):
    self.device_uid = device_uid
    headers = {'Device-Uid': self.device_uid,
               'Accept': 'application/sbp'}
    self.read_response = requests.get(url, stream=True, headers=headers)

  def flush(self):
    """
    File-flush wrapper (noop).
    """
    pass

  def close(self):
    """
    File-handle close wrapper (noop).
    """
    pass

  def write(self, data):
    """
    Write wrapper (noop).
    """
    pass

  def read(self, size):
    """
    Read wrapper.

    Parameters
    ----------
    size : int
      Size to read (in bytes).
    """
    if not self.read_response.ok:
      warnings.warn("Request failed! With code %s: %s " \
                    % (self.read_response.status_code, self.read_response.text))
      return
    return self.read_response.raw.read(size)
