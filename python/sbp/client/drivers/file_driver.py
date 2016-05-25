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
    try:
      handle = open(filename, "rb")
      super(FileDriver, self).__init__(handle)
    except (IOError) as e:
      print
      print "Error opening file '%s':" % filename
      print e
      print
      raise SystemExit

  def __iter__(self):
    return self

  def read(self, size):
    """
    Read wrapper.
    raises IOError at end of file.

    Parameters
    ----------
    size : int
      Number of bytes to read.
    """
    try:
      return self.handle.read(size)
    except (IOError):
      print
      print "FileDriver read error"
      print e
      print
      raise IOError

  def write(self, s):
    """
    Write wrapper.
    The :class:`FileDriver` class does not support write and will raise an IOError.

    Parameters
    ----------
    s : bytes
      Bytes to write
    """
    print
    print "FileDriver does not support writing"
    print
    raise IOError
