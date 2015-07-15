# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

class Sink(object):
  """
  Sink

  The :class:`Sink` provides log helper functions and context management.

  Parameters
  ----------
  handle : handle
    handle to write to.
  """
  def __init__(self, handle):
    self.handle = handle

  def __enter__(self):
    return self

  def __exit__(self, *args):
    self.flush()
    self.close()

  def __call__(self, msg):
    self.call(msg)

  def write(self, s):
    """
    Write wrapper.

    Parameters
    ----------
    s : bytes
      Bytes to write
    """
    return self.handle.write(s)

  def flush(self):
    """
    Flush wrapper.
    """
    self.handle.flush()

  def close(self):
    """
    Close wrapper.
    """
    self.handle.close()
