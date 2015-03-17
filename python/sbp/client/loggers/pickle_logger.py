# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import cPickle as pickle

from base_logger import BaseLogger

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
