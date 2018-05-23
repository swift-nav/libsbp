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

"""Generator for Protocol Buffers target.

This module consumes the YAML spec and generates some message class
files.

"""

import copy
from sbpg.targets.templating import *
from sbpg.utils import markdown_links

MESSAGES_TEMPLATE_NAME = 'message_template.proto.j2'

TYPE_MAP = {
  'u8': 'uint32',
  'u16': 'uint32',
  'u32': 'uint32',
  'u64': 'uint64',
  's8': 'sint32',
  's16': 'sint32',
  's32': 'sint32',
  's64': 'sint64',
  'float': 'float',
  'double': 'double',
  'string': 'string',
}

def to_comment(value):
  """
  Builds a comment.
  """
  if value is None:
    return
  if len(value.split('\n')) == 1:
    return "* " + value
  else:
    return '\n'.join([' * ' + l for l in value.split('\n')[:-1]])

def to_identifier(s):
  """
  Convert snake_case to camel_case.
  """
  if s.startswith('GPS'):
      s = 'Gps' + s[3:]
  return ''.join([i.capitalize() for i in s.split('_')]) if '_' in s else s

def to_type(f, type_map=TYPE_MAP):
    name = f.type_id
    if name.startswith('GPS'):
        name = 'Gps' + name[3:]
    if type_map.get(name, None):
        return type_map.get(name, None)
    elif name == 'array':
        fill = f.options['fill'].value
        f_ = copy.copy(f)
        f_.type_id = fill
        return "repeated %s" % to_type(f_)
    elif name in [ 'GnssSignal', 'GpsTimeSec', 'GpsTime', 'CarrierPhase' ]:
        name = 'gnss.' + name
    return name

def to_title(s):
    return s.title()

JENV.filters['pb_to_identifier'] = to_identifier
JENV.filters['pb_to_type'] = to_type
JENV.filters['pb_to_comment'] = to_comment
JENV.filters['pb_to_title'] = to_title

def render_source(output_dir, package_spec):
    """
    Render and output to a directory given a package specification.
    """
    path, name = package_spec.filepath
    destination_filename = '%s/%s.proto' % (output_dir, name)
    pb_template = JENV.get_template(MESSAGES_TEMPLATE_NAME)
    includes = [include[:-5] if include.endswith('.yaml') else include for include in package_spec.includes]
    if 'types' in includes:
        includes.remove('types')
    with open(destination_filename, 'w') as f:
        f.write(pb_template.render(
            name=name,
            package=package_spec.identifier,
            messages=package_spec.definitions,
            includes=includes,
            description=package_spec.description,
        ))
