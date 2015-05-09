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

"""Generator for Java target.

This module consumes the YAML spec and generates Java code in the
target directory.

"""


import os
from sbpg.targets.templating import JENV, ACRONYMS


TEMPLATE_NAME = "sbp_java.java.j2"

PREON_MAP = {'u8': 'ULInt8',
             'u16': 'ULInt16',
             'u32': 'ULInt32',
             'u64': 'ULInt64',
             's8': 'SLInt8',
             's16': 'SLInt16',
             's32': 'SLInt32',
             's64': 'SLInt64',
             'float': 'LFloat32',
             'double': 'LFloat64'}

JAVA_TYPE_MAP = {'u8': 'int',
                 'u16': 'int',
                 'u32': 'int',
                 'u64': 'int',
                 's8': 'int',
                 's16': 'int',
                 's32': 'int',
                 's64': 'int',
                 'float': 'float',
                 'double': 'double'}


def classnameify(s):
  """
  Makes a classname.
  """
  return ''.join(w if w in ACRONYMS else w.title() for w in s.split('_'))


def preon_format(f, type_map=JAVA_TYPE_MAP, parsing_map=PREON_MAP):
  """
  Formats for Preon.
  """
  formatted = ""
  if type_map.get(f.type_id, None):
    return "BoundNumber()"
    return "%s('%s')" % (type_map.get(f.type_id), f.identifier)
  elif f.type_id == 'string' and f.options.get('size', None):
    return "BoundString()"
  elif f.type_id == 'string':
    return "BoundString()"
  elif f.type_id == 'array' and f.options.get('size', None):
    return "BoundString()"
  elif f.type_id == 'array':
    return "BoundString()"
  else:
    return "BoundString()"
  return formatted

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


JENV.filters['preon_format'] = preon_format
JENV.filters['classnameify'] = classnameify
JENV.filters['commentify'] = commentify
JENV.filters['type_map'] = lambda x: JAVA_TYPE_MAP.get(x, None)


def render_source(output_dir, package_spec, jenv=JENV):
  """
  Render and output
  """
  path, module_name = package_spec.filepath
  java_template = jenv.get_template(TEMPLATE_NAME)
  module_path = package_spec.identifier
  includes = [".".join(i.split(".")[:-1]) for i in package_spec.includes]
  includes = [i for i in includes if i != "types"]
  yaml_filepath = "/".join(package_spec.filepath) + ".yaml"
  for msg in package_spec.definitions:
    msg_name = classnameify(msg.identifier) if msg.sbp_id else msg.identifier
    l = "/".join(package_spec.filepath)
    destination_filename = "%s/%s/%s.java" % (output_dir, l , msg_name)
    with open(destination_filename, 'w+') as f:
        print destination_filename
        f.write(java_template.render(m=msg,
                                     filepath=yaml_filepath,
                                     module_path=module_path,
                                     include=includes,
                                     description=package_spec.description))
