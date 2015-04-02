# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from .base_driver import BaseDriver

class FileDriver(BaseDriver):
  """
  FileDriver

  The :class:`FileDriver` class uses a file as an IO source of SBP messages.

  Parameters
  ----------
  filename : string
    Path to file to read SBP messages from.
  """
  def __init__(self, filename):
    handle = open(filename, "r")
    super(FileDriver, self).__init__(handle)

  def __iter__(self):
    return self

  def seek(self, pos, whence=0):
    """
    Wrapper around file seek.

    Parameters
    ----------
    pos : int
      Position of the read/write pointer within the file.
    whence : int
      Optional and defaults to 0 which means absolute file
      positioning, other values are 1 which means seek relative to the
      current position and 2 means seek relative to the file's end

    """
    self.handle.seek(pos, whence)

  def next(self):
    """
    Call handle's iterator.

    """
    line = self.handle.readline()
    if not line:
      raise StopIteration
    return line

  def readline(self):
    """
    Readline wrapper: read a line which is terminated with end-of-line
    (EOL) character ('\n' by default), or until timeout.

    """
    return self.handle.readline()
