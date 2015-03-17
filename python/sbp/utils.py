#!/usr/bin/env python
# Copyright (C) 2011-2014 Swift Navigation Inc.
# Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""Shared utility functions.

"""

import pprint

TO_REMOVE = ['sender','msg_type','crc','length', 'preamble']

def fmt_repr(obj):
  """Print a orphaned string representation of an object without the
  clutter of its parent object.

  """
  items = {k: v for k, v in obj.__dict__.items() if k not in TO_REMOVE}
  items = ["%s = %r" % (k, v) for k, v in items.items()]
  return "<%s: {%s}>" % (obj.__class__.__name__, ', '.join(items))
