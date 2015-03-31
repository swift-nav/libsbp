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

import jinja2
import os
from sbp.targets.templating import *

TEMPLATE_NAME = "sbp_messages_template.h"

def commentify(value):
  """
  Builds a comment.
  """
  if value is None:
    return
  return '\n'.join([' * ' + l for l in value.split('\n')[:-1]])

def extensions(includes):
  """
  """
  return ["".join([i.split(".")[0], ".h"]) for i in includes if i.split(".")[0] != "types"]

import re

CONSTRUCT_CODE = set(['u8', 'u16', 'u32', 'u64', 's8', 's16', 's32', 's64', 'float', 'double'])

def convert(value):
  s1 = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', value)
  return re.sub('([a-z0-9])([A-Z])', r'\1_\2', s1).lower()+"_t"

def mk_id(field):
  name = field.type_id
  if name == "string":
    return "%s[%d]" % ("char", field.options['size'].value)
  elif name == "array":
    return "%s*" % convert(field.options['fill'].value)
  elif name not in CONSTRUCT_CODE:
    return convert(name)
  else:
    return name

JENV.filters['commentify'] = commentify
JENV.filters['mk_id'] = mk_id
JENV.filters['convert'] = convert

def render_source(output_dir, package_spec):
  """
  Render and output
  """
  path, name = package_spec.filepath
  directory = "/".join([output_dir, path])
  if not os.path.exists(directory):
    os.makedirs(directory)
  destination_filename = "%s/%s.h" % (output_dir, name)
  py_template = JENV.get_template(TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(msgs=package_spec.definitions,
                               pkg_name=name,
                               max_msgid_len=package_spec.max_msgid_len,
                               timestamp=package_spec.creation_timestamp,
                               include=extensions(package_spec.includes)))
