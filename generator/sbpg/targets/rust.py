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
MESSAGES_MOD_TEMPLATE_NAME = "sbp_messages_mod.rs"

import re
def camel_case(s):
  """
  Makes a classname.
  """
  if '_' not in s: return s
  s = re.sub('([a-z])([A-Z])', r'\1_\2', s)
  return ''.join(w if w in ACRONYMS else w.title() for w in s.split('_'))

def commentify(value):
  """
  Builds a comment.
  """
  value = markdown_links(value)
  if value is None:
    return
  if len(value.split('\n')) == 1:
    return "/// " + value
  else:
    return '\n'.join(['/// ' + l for l in value.split('\n')[:-1]])

TYPE_MAP = {'u8': 'u8',
            'u16': 'u16',
            'u32': 'u32',
            'u64': 'u64',
            's8': 'i8',
            's16': 'i16',
            's32': 'i32',
            's64': 'i64',
            'float': 'f32',
            'double': 'f64',
            'string': 'String'}

def type_map(field):
  if field.type_id in TYPE_MAP:
    return TYPE_MAP[field.type_id]
  elif field.type_id == 'array':
    t = field.options['fill'].value
    return "Vec<{}>".format(TYPE_MAP.get(t, t))
  else:
    return field.type_id

def mod_name(x):
    return x.split('.', 2)[2]

def parse_type(field):
  """
  Function to pull a type from the binary payload.
  """
  if field.type_id == 'string':
    if 'size' in field.options:
      return "crate::parser::read_string_limit(_buf, %s)" % field.options['size'].value
    else:
      return "crate::parser::read_string(_buf)"
  elif field.type_id == 'u8':
    return '_buf.read_u8()'
  elif field.type_id == 's8':
    return '_buf.read_i8()'
  elif field.type_id in TYPE_MAP.keys():
    # Primitive java types have extractor methods in SBPMessage.Parser
    return '_buf.read_%s::<LittleEndian>()' % TYPE_MAP[field.type_id]
  if field.type_id == 'array':
    # Call function to build array
    t = field.options['fill'].value
    if t in TYPE_MAP.keys():
      if 'size' in field.options:
        return 'crate::parser::read_%s_array_limit(_buf, %d)' % (t, field.options['size'].value)
      else:
        return 'crate::parser::read_%s_array(_buf)' % t
    else:
      if 'size' in field.options:
        return '%s::parse_array_limit(_buf, %d)' % (t, field.options['size'].value)
      else:
        return '%s::parse_array(_buf)' % t
  else:
    # This is an inner class, call default constructor
    return "%s::parse(_buf)" % field.type_id

JENV.filters['camel_case'] = camel_case
JENV.filters['commentify'] = commentify
JENV.filters['type_map'] = type_map
JENV.filters['mod_name'] = mod_name
JENV.filters['parse_type'] = parse_type

def render_source(output_dir, package_spec):
  """
  Render and output to a directory given a package specification.
  """
  path, name = package_spec.filepath
  destination_filename = "%s/sbp/src/messages/%s.rs" % (output_dir, name)
  py_template = JENV.get_template(MESSAGES_TEMPLATE_NAME)
  includes = [x.rsplit('.', 1)[0] for x in package_spec.includes]
  if 'types' in includes:
    del includes[includes.index('types')]
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(msgs=sorted(package_spec.definitions, key=lambda msg: msg.identifier),
                               pkg_name=name,
                               filepath="/".join(package_spec.filepath) + ".yaml",
                               description=package_spec.description,
                               timestamp=package_spec.creation_timestamp,
                               includes=includes))

def render_mod(output_dir, package_specs):
  msgs = []
  mods = []
  for package_spec in package_specs:
    if not package_spec.render_source:
      continue
    name = package_spec.identifier.split('.', 2)[2]
    if name != 'types':
      mods.append(name)
    for m in package_spec.definitions:
      if m.static and m.sbp_id:
        msgs.append(m)
  destination_filename = "%s/sbp/src/messages/mod.rs" % output_dir
  py_template = JENV.get_template(MESSAGES_MOD_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(packages=package_specs,
                               mods=mods,
                               msgs=sorted(msgs, key=lambda msg: msg.sbp_id)))
