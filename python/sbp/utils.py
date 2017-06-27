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

EXCLUDE = ['sender', 'msg_type', 'crc', 'length', 'preamble', 'payload']

from construct import Container


def exclude_fields(obj, exclude=EXCLUDE):
  """
  Return dict of object without parent attrs.
  """
  return dict([(k, getattr(obj, k)) for k in obj.__slots__ if k not in exclude])


def walk_json_dict(coll):
  """
  Flatten a parsed SBP object into a dicts and lists, which are
  compatible for JSON output.

  Parameters
  ----------
  coll : dict

  """
  if isinstance(coll, dict):
    return dict((k, walk_json_dict(v)) for (k, v) in coll.iteritems())
  elif hasattr(coll, '__iter__'):
    return [walk_json_dict(seq) for seq in coll]
  else:
    return coll


def containerize(coll):
  """Walk attribute fields passed from an SBP message and convert to
  Containers where appropriate. Needed for Construct proper
  serialization.

  Parameters
  ----------
  coll : dict

  """
  if isinstance(coll, Container):
    [setattr(coll, k, containerize(v)) for (k, v) in coll.iteritems()]
    return coll
  elif isinstance(coll, dict):
    return containerize(Container(**coll))
  elif isinstance(coll, list):
    for j, i in enumerate(coll):
      if isinstance(i, dict):
        coll[j] = containerize(Container(**i))
    return coll
  else:
    return coll


def fmt_repr(obj):
  """Print a orphaned string representation of an object without the
  clutter of its parent object.

  """
  items = ["%s = %r" % (k, v) for k, v in exclude_fields(obj).items()]
  return "<%s: {%s}>" % (obj.__class__.__name__, ', '.join(items))
