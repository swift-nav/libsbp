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


def pystruct_format(fields):
  """
  Formats for PyStruct.
  """
  try:
    return '<' + ''.join(PYSTRUCT_CODE[getattr(f, 'type_id')] for f in fields)
  except:
    return "NOPE"

def classnameify(s):
  """
  Makes a classname.
  """
  return ''.join(w if w in ACRONYMS else w.title() for w in s.split('_'))

JENV.filters['pystruct'] = pystruct_format
JENV.filters['classnameify'] = classnameify

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
