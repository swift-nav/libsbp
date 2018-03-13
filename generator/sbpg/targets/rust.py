#!/usr/bin/env python
# Copyright (C) 2018 Swift Navigation Inc.
# Contact: Gareth McMullin <gareth@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
Generator for rust target.
"""

from sbpg.targets.templating import *
from sbpg.utils import markdown_links

MESSAGES_TEMPLATE_NAME = "sbp_messages_template.rs"

def camel_case(s):
  """
  Makes a classname.
  """
  return ''.join(w if w in ACRONYMS else w.title() for w in s.split('_'))

def commentify(value):
  """
  Builds a comment.
  """
  value = markdown_links(value)
  if value is None:
    return
  if len(value.split('\n')) == 1:
    return "// " + value
  else:
    return '\n'.join(['// ' + l for l in value.split('\n')[:-1]])

TYPE_MAP = {'s8': 'i8',
            's16': 'i16',
            's32': 'i32',
            's64': 'i64',
            'float': 'f32',
            'double': 'f64',
            'string': 'String'}

def type_map(field):
  if TYPE_MAP.has_key(field.type_id):
    return TYPE_MAP[field.type_id]
  elif field.type_id == 'array':
    t = field.options['fill'].value
    return "Vec<{}>".format(TYPE_MAP.get(t, t))
  else:
    return field.type_id

JENV.filters['camel_case'] = camel_case
JENV.filters['commentify'] = commentify
JENV.filters['type_map'] = type_map

def render_source(output_dir, package_spec):
  """
  Render and output to a directory given a package specification.
  """
  path, name = package_spec.filepath
  destination_filename = "%s/sbp/src/messages/%s.rs" % (output_dir, name)
  py_template = JENV.get_template(MESSAGES_TEMPLATE_NAME)
  includes = [x.rsplit('.')[0] for x in package_spec.includes]
  if 'types' in includes:
    del includes[includes.index('types')]
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(msgs=package_spec.definitions,
                               pkg_name=name,
                               filepath="/".join(package_spec.filepath) + ".yaml",
                               description=package_spec.description,
                               timestamp=package_spec.creation_timestamp,
                               includes=includes))
