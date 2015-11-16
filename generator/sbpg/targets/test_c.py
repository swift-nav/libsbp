#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Joshua Gross <josh@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
Generator for c tests target.
"""

from sbpg.targets.templating import *
import base64

TEST_TEMPLATE_NAME = "sbp_c_test.c.j2"
CHECK_SUITES_TEMPLATE_NAME = "sbp_c_suites.h.j2"
CHECK_MAIN_TEMPLATE_NAME = "sbp_c_main.c.j2"

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

def b64_decode(field):
    return base64.standard_b64decode(field)

def stringType(value):
    return type(value) == str

def arrayType(value):
    return type(value) == list

def dictType(value):
    return type(value) == dict

def isEmpty(value):
    return len(value) == 0

def strEscape(value):
    return "((char []){" + ",".join(["(char)" + str(ord(ch)) for ch in value]) + "})"

JENV.filters['commentify'] = commentify
JENV.filters['mk_id'] = mk_id
JENV.filters['mk_size'] = mk_size
JENV.filters['convert'] = convert
JENV.filters['type'] = type
JENV.filters['str_escape'] = strEscape

JENV.tests['stringType'] = stringType
JENV.tests['arrayType'] = arrayType
JENV.tests['dictType'] = dictType
JENV.tests['empty'] = isEmpty

def render_source(output_dir, package_spec):
  """
  Render and output to a directory given a package specification.
  """
  path, name = package_spec.filepath
  destination_filename = "%s/%s.c" % (output_dir, name)
  py_template = JENV.get_template(TEST_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(s=package_spec,
                               description=package_spec.description,
                               pkg_name=package_spec.package,
                               include=package_spec.package.split('.')[1],
                               filepath="/".join(package_spec.filepath) + ".yaml"))


def render_check_suites(output_dir, all_package_specs):
  destination_filename = "%s/%s.h" % (output_dir, "check_suites")
  py_template = JENV.get_template(CHECK_SUITES_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(package_suites=all_package_specs))


def render_check_main(output_dir, all_package_specs):
  destination_filename = "%s/%s.c" % (output_dir, "check_main")
  py_template = JENV.get_template(CHECK_MAIN_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(package_suites=all_package_specs))
