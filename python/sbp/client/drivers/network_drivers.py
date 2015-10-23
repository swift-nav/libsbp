# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""TCP and HTTP networking client components.

"""

from .base_driver import BaseDriver
from requests.adapters import DEFAULT_POOLBLOCK, DEFAULT_POOLSIZE, HTTPAdapter
from requests.packages.urllib3.util import Retry
import requests
import socket
import threading

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


class HTTPException(Exception):
  pass

DEFAULT_CONNECT_TIMEOUT = 10
DEFAULT_READ_TIMEOUT = 10
DEFAULT_TIMEOUT = (DEFAULT_CONNECT_TIMEOUT, DEFAULT_READ_TIMEOUT)
MAX_CONNECT_RETRIES = 10
MAX_READ_RETRIES = 10
DEFAULT_RETRIES = (MAX_CONNECT_RETRIES, MAX_READ_RETRIES)
MAX_REDIRECTS = 0
DEFAULT_BACKOFF_FACTOR = 0.2

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
  retries : tuple
    Configure connect and read retry count. Defaults to
    (MAX_CONNECT_RETRIES, MAX_READ_RETRIES).
  timeout : tuple
    Configure connect and read timeouts. Defaults to
    (DEFAULT_CONNECT_TIMEOUT, DEFAULT_READ_TIMEOUT).

  """

  def __init__(self,
               device_uid,
               url="http://broker.testing.skylark.swiftnav.com",
               retries=DEFAULT_RETRIES,
               timeout=DEFAULT_TIMEOUT):
    self.session = requests.Session()
    retry = Retry(connect=DEFAULT_RETRIES[0],
                  read=DEFAULT_RETRIES[1],
                  redirect=MAX_REDIRECTS,
                  status_forcelist=[500],
                  backoff_factor=DEFAULT_BACKOFF_FACTOR)
    self.session.mount("http://",
                       HTTPAdapter(pool_connections=DEFAULT_POOLSIZE,
                                   pool_maxsize=DEFAULT_POOLSIZE,
                                   pool_block=DEFAULT_POOLBLOCK,
                                   max_retries=retry))
    self.device_uid = device_uid
    self.timeout = timeout
    headers = {'Device-Uid': self.device_uid,
               'Accept': 'application/vnd.swiftnav.broker.v1+sbp'}
    try:
      self.read_response = self.session.get(url,
                                            stream=True,
                                            headers=headers,
                                            timeout=self.timeout)
    except requests.exceptions.ConnectionError:
      msg = "Invalid request to %s with headers %s." % (url, headers)
      raise HTTPException(msg)
    except requests.exceptions.ConnectTimeout:
      raise HTTPException(msg)
    except requests.exceptions.RetryError:
      raise HTTPException(msg)
    except requests.exceptions.ReadTimeout:
      msg = "Invalid request to %s with headers %s." % (url, headers)
      raise HTTPException(msg)

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
      msg = "Request failed! With code %s: %s " \
            % (self.read_response.status_code, self.read_response.text)
      raise RuntimeError(msg)
    return self.read_response.raw.read(size)
