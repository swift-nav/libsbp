# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import threading

class BaseDriver(object):
  """
  BaseDriver

  The :class:`BaseDriver` class wraps IO sources of SBP messages and provides
  context management.

  Parameters
  ----------
  handle : port
    Stream of bytes to read from and write to.
  """
  def __init__(self, handle):
    self.handle = handle
    self.lock = threading.RLock()

  def __enter__(self):
    self.flush()
    return self

  def __exit__(self, *args):
    self.flush()
    self.close()

  def read(self, size):
    """
    Read wrapper.

    Parameters
    ----------
    size : int
      Number of bytes to read.
    """
    with self.lock:
      return self.handle.read(size)

  def write(self, s):
    """
    Write wrapper.

    Parameters
    ----------
    s : bytes
      Bytes to write
    """
    with self.lock:
      return self.handle.write(s)

  def flush(self):
    """
    Flush wrapper.
    """
    with self.lock:
      self.handle.flush()

  def close(self):
    """
    Close wrapper.
    """
    with self.lock:
      self.handle.close()
