#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
Generator for Python target.
"""

import os
from sbp.targets.templating import JENV, ACRONYMS

TEMPLATE_NAME = "sbp_messages_template.py.j2"
TEMPLATE_NAME22 = "sbp_construct_template.py.j2"
PYSTRUCT_CODE = {
  'u8': 'B',
  'u16': 'H',
  'u32': 'I',
  'u64': 'Q',
  's8': 'b',
  's16': 'h',
  's32': 'i',
  's64': 'q',
  'float': 'f',
  'double': 'd',
}

CONSTRUCT_CODE = {
  'u8': 'ULInt8',
  'u16': 'ULInt16',
  'u32': 'ULInt32',
  'u64': 'ULInt64',
  's8': 'SLInt8',
  's16': 'SLInt16',
  's32': 'SLInt32',
  's64': 'SLInt64',
  'float': 'LFloat16',
  'double': 'LFloat32',
}

PYDOC_CODE = {
  'u8': 'int',
  'u16': 'int',
  'u32': 'int',
  'u64': 'int',
  's8': 'int',
  's16': 'int',
  's32': 'int',
  's64': 'int',
  'float': 'float',
  'double': 'double',
}

def pystruct_format(fields):
  """
  Formats for PyStruct.
  """
  try:
    return '<' + ''.join(PYSTRUCT_CODE[getattr(f, 'type_id')] for f in fields)
  except:
    return "NOPE"

def construct_format(fields):
  """
  Formats for PyStruct.
  """
  formatted = ""
  for f in fields:
    if CONSTRUCT_CODE.get(f.type_id, None):
      return "%s()" % CONSTRUCT_CODE.get(f.type_id)
    elif is_array(f):
      return "Array()"
    elif
  return formatted

PascalString = Struct("PascalString", UBInt8("length"), Bytes("data", lambda ctx: ctx.length))


def pydoc_format(type_id):
  """
  Formats type for pydoc..
  """
  return PYDOC_CODE.get(type_id, type_id)

def classnameify(s):
  """
  Makes a classname.
  """
  return ''.join(w if w in ACRONYMS else w.title() for w in s.split('_'))

JENV.filters['pystruct'] = pystruct_format
JENV.filters['classnameify'] = classnameify
JENV.filters['pydoc'] = pydoc_format

# TODO (Buro): parametrize

def render_source(output_dir, package_spec):
  """
  Render and output
  """
  path, name = package_spec.filepath
  directory = "/".join([output_dir, path])
  if not os.path.exists(directory):
    os.makedirs(directory)
  destination_filename = "%s/%s.py" % (directory, name)
  py_template = JENV.get_template(TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(msgs=package_spec.definitions))
