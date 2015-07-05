# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from logging.handlers import TimedRotatingFileHandler
from sbp.client.loggers.json_logger import JSONLogger
from sbp.table import dispatch
import Queue
import logging
import threading
import time

# TODO (Buro): Replace _mk_async_emit with a function using from
# logutils.queue: QueueHandler, QueueListener.
# TODO (Buro): Add a real benchmark after integration testing.

def _mk_async_emit(handler):
  """Make a synchronous handler asynchronous.

  Parameters
  ----------
  handler : logging.handlers Handler

  Returns
  ----------
  Async logging.handlers Handler

  """
  emit = handler.emit
  # Yes, the queue size is unbounded (Buro)
  queue = Queue.Queue(maxsize=-1)
  def loop():
    while True:
      record = queue.get(True)
      try :
        emit(record)
      except:
        pass
  thread = threading.Thread(target=loop)
  thread.daemon = True
  thread.start()
  def async_emit(record):
    queue.put(record)
  handler.emit = async_emit
  return handler


class RotatingFileLogger(JSONLogger):
  """RotatingFileLogger

  The :class:`RotatingFileLogger` JSON logs SBP messages to a rotating
  file handler that's turned over at a specified time interval
  (defaults to 30 minutes). Intended to be a very low-overhead,
  cross-platform rolling logger for field testing.

  Parameters
  ----------
  filename : string
    Path to file to write SBP messages to.
  when : str
    Specifies a type of interval
  interval : int
    Specifies length of interval
  backupCount : int
    Number of backups to keep around
  tags : dict
    Tags to add to SBP message envelope
  dispatcher: dict
    SBP dispatch table

  """

  def __init__(self, filename, when='M', interval=30, backupCount=3,
               tags={}, dispatcher=dispatch):
    self.handler = TimedRotatingFileHandler(filename, when, interval,
                                            backupCount)
    self.logger = logging.getLogger("Rotating Log")
    self.logger.setLevel(logging.INFO)
    self.logger.addHandler(_mk_async_emit(self.handler))
    self.dispatcher = dispatcher
    self.base_time = time.time()
    self.tags = tags

  def __call__(self, msg):
    self.call(msg)

  def flush(self):
    self.handler.flush()

  def close(self):
    self.handler.close()

  def call(self, msg):
    self.logger.info(self.dump(msg))
