# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from ...table import dispatch
from construct.core import ConstructError
import calendar
import time
import warnings

class BaseLogger(object):
  """
  BaseLogger

  The :class:`BaseLogger` provides log helper functions and context management.

  Parameters
  ----------
  filename : string
    File to log to.
  """
  def __init__(self, filename, mode="w", tags={}, dispatcher=None):
    if filename:
      self.handle = open(filename, mode)
    self.dispatcher = dispatcher
    self.base_time = time.time()
    self.tags = tags

  def __enter__(self):
    return self

  def __exit__(self, *args):
    self.flush()
    self.close()

  def flush(self):
    self.handle.flush()

  def close(self):
    self.handle.close()

  def dispatch(self, msg):
    if self.dispatcher is None:
      return msg
    try:
      data = self.dispatcher(msg)
    except KeyError:
      warn = "Unknown message type"
      warnings.warn(warn, RuntimeWarning)
      data = msg
    except ConstructError:
      warn = "Bad message parsing"
      warnings.warn(warn, RuntimeWarning)
      data = msg
    return data

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


class LogIterator(object):
  """
  LogIterator

  The :class: `LogIterator` provides an abstract interface for reading
  serialized logs of SBP data.

  Parameters
  ----------
  filename : string
    Path to file to read SBP messages from.

  """
  def __init__(self, filename, dispatcher=dispatch):
    self.handle = open(filename, "r")
    self.dispatcher = dispatcher

  def __enter__(self):
    return self

  def __exit__(self, *args):
    self.flush()
    self.close()

  def __iter__(self):
    return self

  def flush(self):
    self.handle.flush()

  def close(self):
    self.handle.close()

  def dispatch(self, msg, line=None):
    try:
      data = self.dispatcher(msg)
    except KeyError:
      warn = "Unknown message type"
      if line is not None:
        warn += " for line %s" % line
      warnings.warn(warn, RuntimeWarning)
      data = msg
    except ConstructError:
      warn = "Bad message parsing"
      if line is not None:
        warn += " for line %s" % line
      warnings.warn(warn, RuntimeWarning)
      data = msg
    return data

  def next(self):
    """Return the next record tuple from the log file. If an unknown SBP
    message type is found, it'll return the raw SBP. If EOF, throws
    exception and then returns to start of file.

    Returns
    -------
    (float, float, object)
      (elapsed msec since beginning of log, UTC timestamp, msg)

    """
    raise NotImplementedError("next() not implemented!")
