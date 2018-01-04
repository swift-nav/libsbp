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
Generator for c target.
"""

from sbpg.targets.templating import *
import os

SBP2JSON_TEMPLATE = "sbp2json_template.c"
MESSAGES_TEMPLATE_NAME = "sbp_messages_template.h"
VERSION_TEMPLATE_NAME = "sbp_version_template.h"

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


def extensions(includes):
  """Formats a list of header files to include.
  """
  return ["".join([i.split(".")[0], ".h"]) for i in includes if i.split(".")[0] != "types"]

import re

CONSTRUCT_CODE = ['u8', 'u16', 'u32', 'u64', 's8', 's16', 's32',
                      's64', 'float', 'double', 'string', 'char']

FORMAT_STR = ['%hhu', '%hu', '%u', '%lu', '%hhd', '%hd', '%d',
                      '%ld', '%f', '%f', r'\"%s\"', r'\"%s\"']
FORMAT_DICT = {x:y for x,y in zip(CONSTRUCT_CODE,FORMAT_STR)}
COLLISIONS = set(['GnssSignal', 'GPSTime'])

def convert(value):
  """Converts to a C language appropriate identifier format.

  """
  s0 = "Sbp" + value if value in COLLISIONS else value
  s1 = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', s0)
  return re.sub('([a-z0-9])([A-Z])', r'\1_\2', s1).lower() + "_t"

def mk_id(field):
  """Builds an identifier from a field.
  """
  name = field.type_id
  if name == "string":
    return "%s" % ("char")
  elif name == "array" and field.size:
    if field.options['fill'].value not in CONSTRUCT_CODE:
      return "%s" % convert(field.options['fill'].value)
    else:
      return "%s" % field.options['fill'].value
  elif name == "array":
    return "%s" % convert(field.options['fill'].value)
  elif name not in CONSTRUCT_CODE:
    return convert(name)
  else:
    return name

def is_string(f):
  if f == 'string' or f == 'char':
    return True
  else:
    return False

def is_simple(f):
  if f in CONSTRUCT_CODE and not is_string(f):
    return True
  else:
    return False

def entirely_simple(struct):
  is_simple_list = [is_simple(f.type_id) for f in struct.fields]
  if all(is_simple_list) or len(is_simple_list) == 0:
    return True
  else:
    return False

def mk_str_format_msg(struct):
  """Builds a sprintf string from a msg or class.
  """
  out_str = "\"{"
  json = []
  json.append(r"\"msg_type\": %u")
  json.append(r"\"sender\": %u")
  json.append(r"\"length\": %u")
  if entirely_simple(struct):
    for field in struct.fields:
      json.append(str(r"\"" + field.identifier + r"\": " + FORMAT_DICT[mk_id(field)]))
  out_str += ", ".join(json)
  out_str += "}\""
  return out_str

def mk_str_format(struct):
  """Builds a sprintf string from a msg or class.
  """
  out_str = "\"{"
  json = []
  if entirely_simple(struct):
    for field in struct.fields:
      json.append(str(r"\"" + field.identifier + r"\": " + FORMAT_DICT[mk_id(field)]))
  out_str += ", ".join(json)
  out_str += "}\""
  return out_str

def get_format_str(f):
  return FORMAT_DICT[mk_id(f)]

def mk_arg_list_msg(struct):
  """Builds the arg list for a sprintf like command.
  """
  args = []
  args.append("msg_type")
  args.append("sender_id")
  args.append("msg_len")
  if entirely_simple(struct):
    for field in struct.fields:
      args.append(str("in->" + field.identifier))
  return ", ".join(args)

def mk_arg_list(struct):
  """Builds the arg list for a sprintf like command.
  """
  args = []
  if entirely_simple(struct):
    for field in struct.fields:
      args.append(str("in->" + field.identifier))
  return ", ".join(args)

def mk_size(field):
  """Builds an identifier for a container type.
  """
  name = field.type_id
  if name == "string" and field.options.get('size', None):
    return "%s[%d];" % (field.identifier, field.options.get('size').value)
  elif name == "string":
    return "%s[0];" % field.identifier
  elif name == "array" and field.options.get('size', None):
    return "%s[%d];" % (field.identifier, field.options.get('size').value)
  elif name == "array":
    return "%s[0];" % field.identifier
  else:
    return '%s;' % field.identifier

JENV.filters['commentify'] = commentify
JENV.filters['mk_id'] = mk_id
JENV.filters['mk_size'] = mk_size
JENV.filters['convert'] = convert
JENV.filters['mk_str_format'] = mk_str_format
JENV.filters['mk_arg_list'] = mk_arg_list
JENV.filters['mk_str_format_msg'] = mk_str_format_msg
JENV.filters['mk_arg_list_msg'] = mk_arg_list_msg
JENV.filters['entirely_simple'] = mk_arg_list
JENV.filters['is_simple'] = is_simple
JENV.filters['is_string'] = is_string
JENV.filters['get_format_str'] = get_format_str

def render_source(output_dir, package_spec):
  """
  Render and output to a directory given a package specification.
  """
  path, name = package_spec.filepath
  destination_filename = "%s/%s.h" % (output_dir, name)
  py_template = JENV.get_template(MESSAGES_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(msgs=package_spec.definitions,
                               pkg_name=name,
                               filepath="/".join(package_spec.filepath) + ".yaml",
                               max_msgid_len=package_spec.max_msgid_len,
                               description=package_spec.description,
                               timestamp=package_spec.creation_timestamp,
                               include=extensions(package_spec.includes)))

def render_c2json(output_dir, all_package_specs):
  """
  Render and output to a directory given a package specification.
  """
  destination_filename = os.path.abspath("%s/../../src/sbp2json.c" % (output_dir))
  source_specs = [spec for spec in all_package_specs if spec.render_source]
  py_template = JENV.get_template(SBP2JSON_TEMPLATE)
  with open(destination_filename, 'w') as f:
    headers = [spec.filepath[1] + ".h" for spec in source_specs]
    f.write(py_template.render(includes=headers,
                               package_specs=source_specs))

def render_version(output_dir, release):
  destination_filename = "%s/version.h" % output_dir
  major, minor = release.split('.')[:2]
  py_template = JENV.get_template(VERSION_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(major=major, minor=minor))
