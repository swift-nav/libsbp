# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

class NullLogger(object):
  """
  NullLogger

  The :class:`NullLogger` does not log records.
  """
  def __call__(self, msg, **metadata):
    pass

  def __enter__(self):
    return self

  def flush(self):
    pass

  def read(self, s=None):
    pass

  def write(self, s=None):
    pass

  def close(self):
    pass

  def __exit__(self, *args):
    pass
