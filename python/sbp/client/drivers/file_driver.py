# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from base_driver import BaseDriver

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
