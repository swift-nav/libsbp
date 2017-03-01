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

"""Generator for C# target.

This module consumes the YAML spec and generates C# code in the
target directory.

"""


import os
import os.path
from sbpg.targets.templating import JENV, ACRONYMS


TEMPLATE_NAME = "Message.cs.j2"
TEMPLATE_TABLE_NAME = "MessageTable.cs.j2"

CSHARP_TYPE_MAP = {'u8': 'byte',
                   'u16': 'ushort',
                   'u32': 'uint',
                   'u64': 'ulong',
                   's8': 'sbyte',
                   's16': 'short',
                   's32': 'int',
                   's64': 'long',
                   'float': 'float',
                   'double': 'double',
                   'string': 'String'}

def classnameify(s):
  """
  Makes a classname.
  """
  return ''.join(w if w in ACRONYMS else w.title() for w in s.split('_'))


def commentify(value):
  """
  Builds a comment.
  """
  if value is None:
    return
  if len(value.split('\n')) == 1:
    return "* " + value
  else:
    return '\n'.join([' * ' + l for l in value.split('\n')[:-1]])

def type_map(field):
  if CSHARP_TYPE_MAP.has_key(field.type_id):
    return CSHARP_TYPE_MAP[field.type_id]
  elif field.type_id == 'array':
    t = field.options['fill'].value
    return CSHARP_TYPE_MAP.get(t, t) + '[]'
  else:
    return field.type_id

def parse_type(field):
  """
  Function to pull a type from the binary payload.
  """
  if field.type_id == 'string':
    if field.options.has_key('size'):
      return "parser.getString(%d)" % field.options['size'].value
    else:
      return "parser.getString()"
  elif field.type_id in CSHARP_TYPE_MAP.keys():
    # Primitive csharp types have extractor methods in SBPMessage.Parser
    return "parser.get" + field.type_id.capitalize() + "()"
  if field.type_id == 'array':
    # Call function to build array
    t = field.options['fill'].value
    if t in CSHARP_TYPE_MAP.keys():
      if field.options.has_key('size'):
        return "parser.getArrayof%s(%d)" % (t.capitalize(), field.options['size'].value)
      else:
        return "parser.getArrayof%s()" % t.capitalize()
    else:
      if field.options.has_key('size'):
        return "parser.getArray(%s.class, %d)" % (t, field.options['size'].value)
      else:
        return "parser.getArray(%s.class)" % t
  else:
    # This is an inner class, call default constructor
    return "new %s().parse(parser)" % field.type_id

def build_type(field):
  """
  Function to pack a type into the binary payload.
  """
  if field.type_id == 'string':
    if field.options.has_key('size'):
      return "builder.putString(%s, %d)" % (field.identifier, field.options['size'].value)
    else:
      return "builder.putString(%s)" % field.identifier
  elif field.type_id in CSHARP_TYPE_MAP.keys():
    # Primitive csharp types have extractor methods in SBPMessage.Builder
    return "builder.put%s(%s)" % (field.type_id.capitalize(), field.identifier)
  if field.type_id == 'array':
    # Call function to build array
    t = field.options['fill'].value
    if t in CSHARP_TYPE_MAP.keys():
      if field.options.has_key('size'):
        return "builder.putArrayof%s(%s, %d)" % (t.capitalize(),
                                                 field.identifier,
                                                 field.options['size'].value)
      else:
        return "builder.putArrayof%s(%s)" % (t.capitalize(), field.identifier)
    else:
      if field.options.has_key('size'):
        return "builder.putArray(%s, %d)" % (field.identifier, field.options['size'].value)
      else:
        return "builder.putArray(%s)" % field.identifier
  else:
    return "%s.build(builder)" % field.identifier

def jsonify(field):
  if field.type_id in CSHARP_TYPE_MAP.keys():
    return field.identifier
  elif field.type_id == 'array':
    if field.options['fill'].value in CSHARP_TYPE_MAP.keys():
      return "new JSONArray(%s)" % field.identifier
    else:
      return "SBPStruct.toJSONArray(%s)" % field.identifier
  else:
    return field.identifier + ".toJSON()"

JENV.filters['classnameify'] = classnameify
JENV.filters['commentify'] = commentify
JENV.filters['type_map'] = type_map
JENV.filters['parse_type'] = parse_type
JENV.filters['build_type'] = build_type
JENV.filters['jsonify'] = jsonify

def render_source(output_dir, package_spec, jenv=JENV):
  """
  Render and output
  """
  path, module_name = package_spec.filepath
  csharp_template = jenv.get_template(TEMPLATE_NAME)
  module_path = "com." + package_spec.identifier
  yaml_filepath = "/".join(package_spec.filepath) + ".yaml"
  includes = [".".join(i.split(".")[:-1]) for i in package_spec.includes]
  includes = [i for i in includes if i != "types"]
  for msg in package_spec.definitions:
    msg_name = classnameify(msg.identifier) if msg.sbp_id else msg.identifier
    l = "/".join(package_spec.filepath)
    destination_filename = "%s/%s.cs" % (output_dir, msg_name)

    # Create the output directory if it doesn't exist
    if not os.path.exists(os.path.dirname(destination_filename)):
      os.mkdir(os.path.dirname(destination_filename))

    with open(destination_filename, 'w+') as f:
        print destination_filename
        f.write(csharp_template.render(m=msg,
                                       filepath=yaml_filepath,
                                       module_path=module_path,
                                       include=includes,
                                       description=package_spec.description))

def render_table(output_dir, packages, jenv=JENV):
  """
  Render and output dispatch table
  """
  destination_filename = output_dir + "/MessageTable.cs"
  with open(destination_filename, 'w+') as f:
      print destination_filename
      f.write(jenv.get_template(TEMPLATE_TABLE_NAME).render(packages=packages))

