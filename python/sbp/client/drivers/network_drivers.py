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
from concurrent.futures import ThreadPoolExecutor
from requests.adapters import DEFAULT_POOLBLOCK, DEFAULT_POOLSIZE, HTTPAdapter
from requests.packages.urllib3.util import Retry
from requests_futures.sessions import FuturesSession
import requests
import socket
import threading
import time
import warnings

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

DEFAULT_CONNECT_TIMEOUT = 30
DEFAULT_READ_TIMEOUT = 120
DEFAULT_TIMEOUT = (DEFAULT_CONNECT_TIMEOUT, DEFAULT_READ_TIMEOUT)
MAX_CONNECT_RETRIES = 5
MAX_READ_RETRIES = 3
DEFAULT_RETRIES = (MAX_CONNECT_RETRIES, MAX_READ_RETRIES)
MAX_REDIRECTS = 0
DEFAULT_BACKOFF_FACTOR = 0.2
BROKER_SBP_TYPE = 'application/vnd.swiftnav.broker.v1+sbp2'

class HTTPDriver(BaseDriver):
  """HTTPDriver

  The :class:`HTTPDriver` class reads SBP messages from an HTTP
  service for a device and writes out to a stream. This driver is like
  a file-handle with read and writes over two separately HTTP
  connections, but can also be enabled and disabled by its consumer.

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
               device_uid=None,
               url="https://broker.staging.skylark.swiftnav.com",
               retries=DEFAULT_RETRIES,
               timeout=DEFAULT_TIMEOUT,):
    self._retry = Retry(connect=DEFAULT_RETRIES[0],
                        read=DEFAULT_RETRIES[1],
                        redirect=MAX_REDIRECTS,
                        status_forcelist=[500],
                        backoff_factor=DEFAULT_BACKOFF_FACTOR)
    self.url = url
    self.read_session = requests.Session()
    self.read_session.mount("http://",
                            HTTPAdapter(pool_connections=DEFAULT_POOLSIZE,
                                        pool_maxsize=DEFAULT_POOLSIZE,
                                        pool_block=DEFAULT_POOLBLOCK,
                                        max_retries=self._retry))
    self.read_session.mount("https://",
                            HTTPAdapter(pool_connections=DEFAULT_POOLSIZE,
                                        pool_maxsize=DEFAULT_POOLSIZE,
                                        pool_block=DEFAULT_POOLBLOCK,
                                        max_retries=self._retry))
    self.write_session = None
    self.device_uid = device_uid
    self.timeout = timeout
    self.read_response = None
    self.write_response = None
    self.source = None

  def flush(self):
    """File-flush wrapper (noop).

    """
    pass

  def close(self):
    """File-handle close wrapper (noop).

    """
    try:
      self.read_close()
      self.write_close()
    except:
      pass

  @property
  def write_ok(self):
    """
    Are we connected for writes?
    """
    # Note that self.write_response is either None or a Response
    # object, which cast to False for 4xx and 5xx HTTP codes.
    return bool(self.write_response)

  def connect_write(self, source, whitelist, device_uid=None, pragma=None):
    """Initialize a streaming write HTTP response. Manually connects the
    underlying file-handle. In the event of a network disconnection,
    use to manually reinitiate an HTTP session.

    Parameters
    ----------
    source : sbp.client.handler.Handler
      Iterable source of SBP messages.
    whitelist : [int]
      Whitelist of messages to write

    """
    header_device_uid = device_uid or self.device_uid
    headers = {'Device-Uid': header_device_uid, 'Content-Type': BROKER_SBP_TYPE, 'Pragma': pragma}
    if not pragma:
      del headers['Pragma']
    try:
      self.executor = ThreadPoolExecutor(max_workers=DEFAULT_POOLSIZE)
      self.write_session = FuturesSession(executor=self.executor)
      self.write_session.mount("http://",
                               HTTPAdapter(pool_connections=DEFAULT_POOLSIZE,
                                           pool_maxsize=DEFAULT_POOLSIZE,
                                           pool_block=DEFAULT_POOLBLOCK,
                                           max_retries=self._retry))
      self.write_session.mount("https://",
                               HTTPAdapter(pool_connections=DEFAULT_POOLSIZE,
                                           pool_maxsize=DEFAULT_POOLSIZE,
                                           pool_block=DEFAULT_POOLBLOCK,
                                           max_retries=self._retry))
      self.source = source.filter(whitelist)
      gen = (msg.pack() for msg, _ in self.source)
      self.write_session.put(self.url, data=gen, headers=headers)
      self.write_response = True
    except requests.exceptions.ConnectionError as err:
      msg = "Client connection error to %s with [PUT] headers %s: msg=%s" \
            % (self.url, headers, err.message)
      warnings.warn(msg)
    except requests.exceptions.ConnectTimeout as err:
      msg = "Client connection timeout to %s with [PUT] headers %s: msg=%s" \
            % (self.url, headers, err.message)
      warnings.warn(msg)
    except requests.exceptions.RetryError:
      msg = "Client retry error to %s with [PUT] headers %s: msg=%s" \
            % (self.url, headers, err.message)
      warnings.warn(msg)
    except requests.exceptions.ReadTimeout:
      msg = "Client read timeout to %s with [PUT] headers %s: msg=%s" \
            % (self.url, headers, err.message)
      warnings.warn(msg)
    return self.write_ok

  def write(self, data):
    """Write wrapper (noop). Actual stream is initiated by the write
    connection.

    Parameters
    ----------
    data : object
      Data to write.

    """
    pass

  def write_close(self):
    """File-handle close wrapper (noop).

    """
    try:
      self.write_session.close()
      self.executor.shutdown(wait=False)
      self.source.breakiter()
      self.source = None
      self.executor = None
      self.write_session = None
    except:
      pass

  @property
  def read_ok(self):
    """
    Are we connected for reads?
    """
    return bool(self.read_response)

  def connect_read(self, device_uid=None, pragma=None):
    """Initialize a streaming read/write HTTP response. Manually connects
    the underlying file-handle. In the event of a network
    disconnection, use to manually reinitiate an HTTP session.

    """
    header_device_uid = device_uid or self.device_uid
    headers = {'Device-Uid': header_device_uid, 'Accept': BROKER_SBP_TYPE, 'Pragma': pragma}
    if not pragma:
      del headers['Pragma']
    try:
      self.read_response = self.read_session.get(self.url,
                                                 stream=True,
                                                 headers=headers,
                                                 timeout=self.timeout)
    except requests.exceptions.ConnectionError as err:
      msg = "Client connection error to %s with [GET] headers %s: msg=%s" \
            % (self.url, headers, err.message)
      warnings.warn(msg)
    except requests.exceptions.ConnectTimeout as err:
      msg = "Client connection timeout to %s with [GET] headers %s: msg=%s" \
            % (self.url, headers, err.message)
      warnings.warn(msg)
    except requests.exceptions.RetryError:
      msg = "Client retry error to %s with [GET] headers %s: msg=%s" \
            % (self.url, headers, err.message)
      warnings.warn(msg)
    except requests.exceptions.ReadTimeout:
      msg = "Client read timeout to %s with [GET] headers %s: msg=%s" \
            % (self.url, headers, err.message)
      warnings.warn(msg)
    return self.read_ok

  def read(self, size):
    """Read wrapper. If the client connection is closed or some other
    exception is thrown, raises an IOError.

    Parameters
    ----------
    size : int
      Size to read (in bytes).

    Returns
    ----------
    bytearray, or None

    """
    if self.read_response is None or not self.device_uid:
      raise ValueError("Invalid/insufficient HTTP request parameters!")
    elif not self.read_ok or self.read_response.raw.closed:
      raise IOError("HTTP read closed?!")
    try:
      return self.read_response.raw.read(size)
    except:
      raise IOError("HTTP read error!")

  def read_close(self):
    """File-handle close wrapper (noop).

    """
    try:
      self.read_response.close()
      self.read_response = None
    except:
      pass
