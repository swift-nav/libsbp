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
from boto.s3.connection import S3Connection
from cStringIO import StringIO
from gzip import GzipFile
from operator import itemgetter
import json
import warnings

class JSONLogger(BaseLogger):
  """
  JSONLogger

  The :class:`JSONLogger` logs JSON records.
  """
  def fmt_msg(self, data, **metadata):
    metadata.update(self.tags)
    metadata['data'] = data
    return metadata

  def dump(self, msg, **metadata):
    try:
      data = self.dispatch(msg).to_json_dict()
      return json.dumps(self.fmt_msg(data, **metadata), allow_nan=False)
    except (ValueError, UnicodeDecodeError):
      try:
        warn = "Bad values in JSON encoding for msg_type %d for msg %s" \
               % (msg.msg_type, msg)
        warnings.warn(warn, RuntimeWarning)
        return json.dumps(self.fmt_msg(msg.to_json_dict(), **metadata))
      except (ValueError, UnicodeDecodeError):
        return None

  def __call__(self, msg, **metadata):
    output = self.dump(msg, **metadata)
    if output:
      self.handle.write(output + "\n")

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

  def next(self):
    """
    Return the next record tuple from log file containing
    JSON-serialized SBP. If an unknown SBP message type is found,
    it'll return the raw SBP. If EOF, throws exception and then
    returns to start of file.

    Returns
    -------
    Tuple(sbp MSG object, {'time':'ISO 8601 time'})
      Second item is for metadata. There used to be multiple fields and
      there could be more in the future.

    Notes
    -----
    In practice it seems like a lot of times JSONLogIterator objects return
    iterators instead of tuples due to weird usage of the class.

    """
    for line in self.handle:
      try:
        data = json.loads(line)
        item = SBP.from_json_dict(data.pop('data', data))
        msg = self.dispatch(item, line)
        yield (msg, data)
      except (ValueError, UnicodeDecodeError):
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
    Tuple(sbp MSG object, {'time':'ISO 8601 time'})
      Second item is for metadata. There used to be multiple fields and
      there could be more in the future.

    """
    datas = []
    for handle in self.handles:
      for line in handle:
        try:
          datas.append(json.loads(line))
        except (ValueError, UnicodeDecodeError):
          warn = "Bad JSON decoding for line %s" % line
          warnings.warn(warn, RuntimeWarning)

    for data in sorted(datas, key=itemgetter('time')):
      item = SBP.from_json_dict(data.pop('data'))
      msg = self.dispatch(item)
      yield (msg, data)

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
