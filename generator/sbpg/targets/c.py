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

CONSTRUCT_CODE = set(['u8', 'u16', 'u32', 'u64', 's8', 's16', 's32',
                      's64', 'float', 'double'])


def convert(value):
  """Converts to a C language appropriate identifier format.

  """
  s1 = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', value)
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

def render_version(output_dir, release):
  destination_filename = "%s/version.h" % output_dir
  major, minor = release.split('.')[:2]
  py_template = JENV.get_template(VERSION_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(major=major, minor=minor))
