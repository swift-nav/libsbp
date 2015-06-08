# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from ...msg import SBP
from ...table import dispatch
from .base_logger import BaseLogger, LogIterator
from construct.core import ConstructError
import json
import warnings
from boto.s3.connection import S3Connection
from gzip import GzipFile
from operator import itemgetter
from cStringIO import StringIO

class JSONLogger(BaseLogger):
  """
  JSONLogger

  The :class:`JSONLogger` logs JSON records.
  """
  def __call__(self, msg):
    self.call(msg)

  def fmt_msg(self, msg):
    try:
      data = self.dispatcher(msg).to_json_dict()
    except KeyError:
      data = msg.to_json_dict()
    return {"delta": self.delta(),
            "timestamp": self.timestamp(),
            "data": data,
            "metadata": self.tags}

  def call(self, msg):
    try:
      self.handle.write(json.dumps(self.fmt_msg(msg), allow_nan=False) + "\n")
    except ValueError:
      warn = "Bad values in JSON encoding for msg_type %d for msg %s" \
             % (msg.msg_type, msg)
      warnings.warn(warn, RuntimeWarning)

class JSONLogIterator(LogIterator):
  """
  JSONLogIterator

  The :class:`JSONLogIterator` is an iterator for reading JSON logs
  of SBP data.

  Parameters
  ----------
  filename : string
    Path to file to read SBP messages from.

  """
  def _process(self, data):
    delta = data['delta']
    timestamp = data['timestamp']
    item = SBP.from_json_dict(data['data'])
    try:
      yield (delta, timestamp, self.dispatcher(item))
    except KeyError:
      yield (delta, timestamp, item)

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
    for line in self.handle:
      try:
        data = json.loads(line)
        delta = data['delta']
        timestamp = data['timestamp']
        item = SBP.from_json_dict(data['data'])
        try:
          yield (delta, timestamp, self.dispatcher(item))
        except (KeyError, ConstructError):
          warn = "Bad message parsing for line %s" % line
          warnings.warn(warn, RuntimeWarning)
          yield (delta, timestamp, item)
      except ValueError:
        warn = "Bad JSON decoding for line %s" % line
        warnings.warn(warn, RuntimeWarning)
    self.handle.seek(0, 0)
    raise StopIteration

class MultiJSONLogIterator(JSONLogIterator):
  """
  MultiJSONLogIterator

  The :class:`MultiJSONLogIterator` is an iterator for reading JSON logs
  of SBP data out of multiple handles.

  Parameters
  ----------
  handler : [handles]
    List of handles

  """
  def __init__(self, handles, dispatcher=dispatch):
    self.handles = handles
    self.dispatcher = dispatcher

  def flush(self):
    for handle in self.handles:
      handle.flush()

  def close(self):
    for handle in self.handles:
      handle.close()

  def next(self):
    """
    Return the next record tuple from log files containing
    JSON-serialized SBP. If an unknown SBP message type
    is found, it'll return the raw SBP. If EOF, throws
    exception and then returns to start of file.

    Returns
    -------
    (float, float, object)
      (elapsed msec since beginning of log, UTC timestamp, msg)

    """
    datas = []
    for handle in self.handles:
      for line in handle:
        try:
          datas.append(json.loads(line))
        except ValueError:
          warn = "Bad JSON decoding for line %s" % line
          warnings.warn(warn, RuntimeWarning)

    for data in sorted(datas, key=itemgetter('timestamp')):
      delta = data['delta']
      timestamp = data['timestamp']
      metadata = data['metadata']
      item = SBP.from_json_dict(data['data'])
      try:
        yield (delta, timestamp, metadata, self.dispatcher(item))
      except KeyError:
        yield (delta, timestamp, metadata, item)

    for handle in self.handles:
      handle.seek(0, 0)
      raise StopIteration

  @staticmethod
  def s3_handles(aws_access_key, aws_secret_key, bucket, keys):
    """
    Return handles for S3 objects matching keys in bucket.

    Parameters
    ----------
    aws_access_key : string
      AWS access key from credentials.
    aws_secret_key : string
      AWS secret key from credentials.
    bucket : string
      S3 bucket to read objects from.
    keys : [string]
      List of keys in bucket to iterate over.

    """
    handles = []
    bucket = S3Connection(aws_access_key, aws_secret_key).get_bucket(bucket)
    for key in keys:
      for k in bucket.list(prefix=key):
        s = k.get_contents_as_string()
        gz = GzipFile(fileobj=StringIO(s))
        handles.append(StringIO(gz.read()))
    return handles
