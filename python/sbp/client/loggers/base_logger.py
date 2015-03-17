# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import calendar
import time

class BaseLogger(object):
  """
  BaseLogger

  The :class:`BaseLogger` provides log helper functions and context management.

  Parameters
  ----------
  filename : string
    File to log to.
  """
  def __init__(self, filename):
    self.handle = open(filename, "w+")
    self.base_time = time.time()

  def __enter__(self):
    return self

  def __exit__(self, *args):
    self.close()

  def close(self):
    self.handle.close()

  def timestamp(self):
    """
    Timestamp generator.
    """
    return calendar.timegm(time.gmtime())

  def delta(self):
    """
    Relevant time differential generator.
    """
    return int((time.time() - self.base_time) * 1000)

