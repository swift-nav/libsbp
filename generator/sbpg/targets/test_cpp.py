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

CONSTRUCT_CODE = set(['u8', 'u16', 'u32', 'u64', 's8', 's16', 's32',
                      's64', 'float', 'double'])

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

def screaming_snake_case(value):
  return stringcase.snakecase(value).upper()

def mk_id(field):
  name = field.type_id
  if name == 'string':
    return 'char'
  elif name == 'array':
    if field.options['fill'].value in CONSTRUCT_CODE:
      return field.options['fill'].value
    else:
      return pascal_case(field.options['fill'].value)
  else:
    if name in CONSTRUCT_CODE:
      return name
    else:
      return pascal_case(name)

def is_zero_array(field):
  return (field.type_id == 'array' or field.type_id == 'string') and not field.options.get('size', None)

def is_templated_field(field, all_messages):
  field_id = mk_id(field)
  if field_id not in CONSTRUCT_CODE:
    field_message = list([message for message in all_messages if pascal_case(message.identifier) == field_id])
    return field_message and extract_template_fields(field_message[0], all_messages)
  else:
    return False

def extract_template_fields(message, all_messages):
  template_fields = []
  for field in message.fields:
    if is_zero_array(field):
      template_fields.append(field)
    elif is_templated_field(field, all_messages):
      template_fields.append(field)

  return template_fields

def is_zero_array_message(message):
  for field in message.fields:
    if is_zero_array(field):
      return True
  return False

def is_templated_field_message(message, all_messages):
  for field in message.fields:
    if is_templated_field(field, all_messages):
      return True
  return False

JENV.filters['snake_case'] = snake_case
JENV.filters['pascal_case'] = pascal_case

def render_source(output_dir, package_spec, all_specs):
  """
  Render and output to a directory given a package specification.
  """
  path, name = package_spec.filepath
  destination_filename = "%s/auto_%s.cc" % (output_dir, name)
  py_template = JENV.get_template(TEST_TEMPLATE_NAME)

  all_messages = []
  for spec in all_specs:
    all_messages.extend(spec.definitions)

  with open(destination_filename, 'w') as file:
    file.write(py_template.render(all_messages=all_messages,
                                  package_messages=package_spec.definitions,
                                  pkg_name=name,
                                  extract_template_fields=extract_template_fields,
                                  is_zero_array_message=is_zero_array_message,
                                  is_templated_field_message=is_templated_field_message))
