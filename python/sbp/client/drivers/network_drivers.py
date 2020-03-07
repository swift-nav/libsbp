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

import sys
import errno
import socket
import threading
import time

from functools import partial

from .base_driver import BaseDriver


MAX_RECONNECT_RETRIES = 30
RECONNECT_SLEEP_S = 1


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

    def __init__(self,
                 host,
                 port,
                 timeout=5,
                 raise_initial_timeout=False,
                 reconnect=False,
                 max_reconnect=MAX_RECONNECT_RETRIES):
        self._address = (host, port)
        self._create_connection = partial(socket.create_connection,
                                          (host, port),
                                          timeout=timeout
                                          )
        self._connect(timeout_raises=raise_initial_timeout)
        super(TCPDriver, self).__init__(self.handle)
        self._write_lock = threading.Lock()
        self._reconnect_count = 0
        self._reconnect_supported = reconnect
        self._max_reconnect = max_reconnect

    def _connect(self, timeout_raises=False):
        while True:
            try:
                self.handle = self._create_connection()
                return
            except socket.timeout:
                if timeout_raises:
                    raise

    def _reconnect(self, exc):
        if not self._reconnect_supported:
            raise exc
        while True:
            if self._reconnect_count >= self._max_reconnect:
                raise exc
            try:
                self._connect(timeout_raises=True)
                self._reconnect_count = 0
            except socket.error:
                self._reconnect_count += 1
                time.sleep(RECONNECT_SLEEP_S)
                continue
            break

    def _read(self, size):
        """
        Read wrapper.

        Parameters
        ----------
        size : int
          Number of bytes to read
        """
        data = ''
        while True:
            try:
                data = self.handle.recv(size)
            except socket.timeout as socket_error:
                self._reconnect(socket_error)
            except socket.error as socket_error:
                # this is fine, just retry
                if socket_error.errno == errno.EINTR:
                    continue
                self._reconnect(IOError)
            if not data:
                self._reconnect(IOError)
            break
        return data

    def flush(self):
        pass

    def _write(self, s):
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
        except socket.timeout:
            self._connect()
        except socket.error:
            raise IOError
        finally:
            self._write_lock.release()
