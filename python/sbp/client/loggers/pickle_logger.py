# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from .base_logger import BaseLogger, LogIterator
import cPickle as pickle

class PickleLogger(BaseLogger):
  """
  PickleLogger

  The :class:`PickleLogger` logs pickled structures.
  """
  def __call__(self, msg):
    self.call(msg)

  def fmt_msg(self, msg):
    return (self.delta(), self.timestamp(), msg)

  def call(self, msg):
    pickle.dump(self.fmt_msg(msg), self.handle, 2)


class PickleLogIterator(LogIterator):
  """
  PickleLogIterator

  The :class:`PickleLogIterator` is an iterator for reading pickled logs
  of SBP data.

  Parameters
  ----------
  handle : File-like handle
    Any file-like handle providing SBP messages.

  """

  def next(self):
    """
    Return the next record tuple from log file containing
    Pickle SBP. If an unknown SBP message type is found,
    it'll return the raw SBP. If EOF, throws exception and then
    returns to start of file. If unpickling error, it tells you
    when and on what the error occured but keeps iterating.

    Returns
    -------
    (float, float, object)
      (elapsed msec since beginning of log, UTC timestamp, msg)

    """
    try:
      while True:
        delta, timestamp, item = pickle.load(self.handle)
        try:
          yield (delta, timestamp, self.dispatcher(item))
        except KeyError:
          yield (delta, timestamp, item)
    except EOFError:
      self.handle.seek(0, 0)
      raise StopIteration
    except pickle.UnpicklingError:
      import warnings 
      error_string = ("Unpickling error for item {0} at delta time" +\
                     " {1} and timestamp {2}.").format(item,delta,timestamp) 
      warnings.warn(error_string)

