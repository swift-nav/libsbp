#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Swift Engineering <dev@swiftnav.com>
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
import json
import os

from sbpg.targets.templating import *

TEMPLATE_NAME = 'message_template.jsonschema.j2'

TYPE_MAP = {
  'u8': 'integer',
  'u16': 'integer',
  'u32': 'integer',
  'u64': 'integer',
  's8': 'integer',
  's16': 'integer',
  's32': 'integer',
  's64': 'integer',
  'float': 'number',
  'double': 'number',
  'string': 'string',
}


def to_comment(value):
  """
  Builds a comment.
  """
  if value is None:
    return
  else:
    comment = []
    lines = value.strip().splitlines()
    for index, line in enumerate(lines):
        comment.append(line)
        if index+1 != len(lines):
            comment.append(",\n")
        else:
            comment.append("\n")
    return json.dumps(str.join('', comment))


def classnameify(s):
  """
  Makes a classname.
  """
  if s.startswith('GPS'):
      s = 'Gps' + s[3:]
  return ''.join(w if w in ACRONYMS else w.title() for w in s.split('_')) if '_' in s else s


def to_member_name(member):
    return member

def to_type(f, type_map=TYPE_MAP):
    name = f.type_id
    if name.startswith('GPS'):
        name = 'Gps' + name[3:]
    if type_map.get(name, None) is not None:
        return '{"type": "%s"}' % type_map.get(name, None)
    elif name == 'array':
        fill = f.options['fill'].value
        f_ = copy.copy(f)
        f_.type_id = fill
        return '{"type": "array", "items": %s}' % to_type(f_)
    return '{"$ref": "%s.json"}' % name

def to_title(s):
    return s.title()

JENV.filters['schema_to_identifier'] = classnameify
JENV.filters['schema_to_type'] = to_type
JENV.filters['schema_to_comment'] = to_comment
JENV.filters['schema_to_title'] = to_title
JENV.filters['schema_to_member_name'] = to_member_name

def render_source(output_dir, package_spec):
    """
    Render and output to a directory given a package specification.
    """
    jsonschema_template = JENV.get_template(TEMPLATE_NAME)
    for msg in package_spec.definitions:
        if 'Dep' in msg.identifier or 'DEP' in msg.identifier:
            continue
        msg_name = classnameify(msg.identifier) if msg.sbp_id else classnameify(msg.identifier)
        destination_filename = "%s/%s.json" % (output_dir, msg_name)
        with open(destination_filename, 'w+') as output_fp:
            print(destination_filename)
            output_fp.write(jsonschema_template.render(message=msg))
