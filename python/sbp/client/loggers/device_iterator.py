# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from base_logger import LogIterator
from ...client.handler import Handler
from ...table import dispatch
import calendar
import time
from Queue import Queue, Empty

class DeviceIterator(LogIterator):
  """
  LogIterator

  The :class: `DeviceIterator` provides an abstract interface for reading
  from a handle and appending messages to a queue, and reading the queue
  in an iterable fashion

  Parameters
  ----------
  handler : Handler
    SBP handler
  timeout : float
    number of seconds to block when reading queue before
    raising stop iteration

  """

  def _enqueue(self, msg):
    """
    Called with each receipt of the message
    Note: dispatch is necessary but perhaps should be handled in handler
    """
    try:
      data = self.dispatcher(msg)
    except KeyError:
      data = msg
    self.queue.put(data, True)

  def __init__(self, handler, timeout=0, maxsize=0, dispatcher=dispatch):

    self.handler = handler
    self.queue = Queue(maxsize)
    self.handler.add_callback(self._enqueue)
    self.timeout = timeout
    self.base_time = time.time()
    self.dispatcher = dispatcher

  def __iter__(self):
    return self

  def delta(self):
    return time.time() - self.base_time

  def timestamp(self):
    """
    Timestamp generator.
    """
    return calendar.timegm(time.gmtime())

  def next(self):
    """Return the next record tuple from the log file. If an unknown SBP
    message type is found, it'll return the raw SBP. If the queue is empty,
    It throws the StopIteration exception

    Returns
    -------
    (float, float, object)
      (elapsed msec since beginning of log, UTC timestamp, msg)

    """
    try:
      msg = self.queue.get(True, self.timeout)
      return (self.delta(), self.timestamp(), msg)
    except Empty:
      raise StopIteration





