#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
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
from sbpg.targets.c import *
from sbpg.targets.common import *
import stringcase

TEST_TEMPLATE_NAME = "test_sbp_messages.cpp"
SKIP_MESSAGE_IDS = ['MSG_FILEIO_WRITE_REQ']

def skip_message(message):
  return message.identifier in SKIP_MESSAGE_IDS

def pascal_case(value):
  if value.isupper():
    # assuming SCREAMING_SNAKE_CASE
    return stringcase.pascalcase(value.lower())
  else:
    # assuming already in pascal case
    return value

def snake_case(value):
  if value.isupper():
    # assuming SCREAMING_SNAKE_CASE
    return value.lower()
  else:
    return stringcase.snakecase(value)

def is_template(message):
  for field in message.fields:
    if (field.type_id == 'array' or field.type_id == 'string') and not field.options.get('size', None):
      return True

  return False

JENV.filters['snake_case'] = snake_case
JENV.filters['pascal_case'] = pascal_case

def render_source(output_dir, package_spec):
  """
  Render and output to a directory given a package specification.
  """
  path, name = package_spec.filepath
  destination_filename = "%s/auto_%s.cc" % (output_dir, name)
  py_template = JENV.get_template(TEST_TEMPLATE_NAME)
  with open(destination_filename, 'w') as file:
    file.write(py_template.render(package_messages=package_spec.definitions,
                                  pkg_name=name,
                                  skip_message=skip_message,
                                  is_template=is_template))
