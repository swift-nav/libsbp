# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import json

from base_logger import BaseLogger

class JSONLogger(BaseLogger):
  """
  JSONLogger
  
  The :class:`JSONLogger` logs JSON records.
  """
  def __call__(self, msg):
    self.call(msg)

  def fmt_msg(self, msg):
    return {"delta": self.delta(), "timestamp": self.timestamp(), "data": msg.to_json_dict()}
  
  def call(self, msg):
    self.handle.write(json.dumps(self.fmt_msg(msg)) + "\n")
