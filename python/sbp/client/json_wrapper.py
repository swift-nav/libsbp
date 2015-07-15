# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

class JSONWrapper(object):
  """
  JSONHandle

  The :class:`JSONHandle` deals with JSON records.
  """
  def __init__(self, handle, dispatch):
    self.handle = handle
    self.dispatch = dispatch

  def _fmt(self, msg):
    data = self.dispatch(msg).to_json_dict()
  return {"data": data}

  def _dump(self, msg):
    return json.dumps(self._fmt(msg), allow_nan=False)

  def call(self, msg):
    self.handle.write(self._dump(msg) + "\n")

  def next(self):
    datas = []
    for line in self.handle:
      data = json.loads(line)
      item = SBP.from_json_dict(data['data'])
      msg = self.dispatch(item)
      yield msg
    raise StopIteration
