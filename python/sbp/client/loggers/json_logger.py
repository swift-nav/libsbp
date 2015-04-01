# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from ... import SBP
from .base_logger import BaseLogger, LogIterator
import json

class JSONLogger(BaseLogger):
  """
  JSONLogger

  The :class:`JSONLogger` logs JSON records.
  """
  def __call__(self, msg):
    self.call(msg)

  def fmt_msg(self, msg):
    return {"delta": self.delta(),
            "timestamp": self.timestamp(),
            "data": msg.to_json_dict()}

  def call(self, msg):
    with self.lock:
      self.handle.write(json.dumps(self.fmt_msg(msg)) + "\n")


class JSONLogIterator(LogIterator):
  """
  JSONLogIterator

  The :class:`JSONLogIterator` is an iterator for reading JSON logs
  of SBP data.

  Parameters
  ----------
  handle : File-like handle
    Any file-like handle providing SBP messages.

  """

  def next(self):
    """
    Return the next record tuple from log file containing
    JSON-serialized SBP. If an unknown SBP message type is found,
    it'll return the raw SBP. If EOF, throws exception and then
    returns to start of file.

    Returns
    -------
    (float, float, object)
      (elapsed msec since beginning of log, UTC timestamp, msg)

    """
    with self.lock:
      for line in self.handle:
        data = json.loads(line)
        delta = data['delta']
        timestamp = data['timestamp']
        item = SBP.from_json_dict(data['data'])
        try:
          yield (delta, timestamp, self.dispatcher(item))
        except KeyError:
          yield (delta, timestamp, item)
      self.handle.seek(0, 0)
      raise StopIteration
