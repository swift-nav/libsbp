#!/usr/bin/env python

# Copyright (C) 2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
Generator for C++ target.
"""

import re
import stringcase
from sbpg.targets.templating import *
from sbpg.utils import markdown_links
from sbpg import ReleaseVersion

MESSAGES_TEMPLATE_NAME = 'sbp_messages_template.hpp'
VERSION_TEMPLATE_NAME = 'sbp_version_template.hpp'

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

def mk_template(message, all_messages):
  field_sizeof = []
  for field in message.fields:
    if not is_zero_array(field) and not is_templated_field(field, all_messages):
      if field.type_id == 'string' or field.type_id == 'array':
        name = '{}[{}]'.format(mk_id(field), field.options.get('size').value)
      else:
        name = mk_id(field)
      field_sizeof.append('sizeof({})'.format(name))

  template_content = None

  for field in message.fields:
    if is_zero_array(field):
      template_content = 'size_t {} = (SBP_MAX_PAYLOAD_LEN - ({})) / sizeof({})'.format(
        '{}_COUNT'.format(screaming_snake_case(field.identifier)),
        ' + '.join(field_sizeof + ['0']),
        mk_id(field)
      )
    elif is_templated_field(field, all_messages):
      template_content = 'size_t {}_COUNT'.format(screaming_snake_case(field.identifier))

  if template_content:
    return 'template<{}>'.format(template_content)
  else:
    return ''

def is_zero_array(field):
  return (field.type_id == 'array' or field.type_id == 'string') and not field.options.get('size', None)

def is_templated_field(field, all_messages):
  field_id = mk_id(field)
  if field_id not in CONSTRUCT_CODE:
    field_message = list([message for message in all_messages if pascal_case(message.identifier) == field_id])
    return field_message and extract_template_fields(field_message[0], all_messages)
  else:
    return False;

def extract_template_fields(message, all_messages):
  template_fields = []
  for field in message.fields:
    if is_zero_array(field):
      template_fields.append(field)
    elif is_templated_field(field, all_messages):
      template_fields.append(field)

  return template_fields

def mk_field(field, all_messages):
  field_id = mk_id(field)
  field_size = mk_size(field)

  if is_templated_field(field, all_messages):
    return '{}<{}_COUNT> {}'.format(field_id, screaming_snake_case(field.identifier), field_size)
  else:
    return '{} {}'.format(field_id, field_size)

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

def mk_size(field):
  name = field.type_id
  if name == 'string' and field.options.get('size', None):
    return '%s[%d];' % (field.identifier, field.options.get('size').value)
  elif name == 'string':
    return '%s[%s];' % (field.identifier, '{}_COUNT'.format(screaming_snake_case(field.identifier)))
  elif name == 'array' and field.options.get('size', None):
    return '%s[%d];' % (field.identifier, field.options.get('size').value)
  elif name == 'array':
    return '%s[%s];' % (field.identifier, '{}_COUNT'.format(screaming_snake_case(field.identifier)))
  else:
    return '%s;' % field.identifier

def commentify(value, indent=0):
  value = markdown_links(value)
  if value is None:
    return
  if len(value.split('\n')) == 1:
    return value
  else:
    return ('\n' + (' ' * indent) + ' * ').join([l for l in value.split('\n')[:-1]])

def extensions(includes):
  return [''.join([i.split('.')[0], '.h']) for i in includes if i.split(".")[0] != 'types']

JENV.filters['pascal_case'] = pascal_case
JENV.filters['snake_case'] = snake_case
JENV.filters['screaming_snake_case'] = screaming_snake_case
JENV.filters['mk_template'] = mk_template
JENV.filters['mk_field'] = mk_field
JENV.filters['commentify'] = commentify
JENV.filters['is_zero_array'] = is_zero_array
JENV.filters['is_templated_field'] = is_templated_field


def render_source(output_dir, package_spec, all_specs):
  path, name = package_spec.filepath
  destination_filename = '%s/cpp/%s.h' % (output_dir, name)
  py_template = JENV.get_template(MESSAGES_TEMPLATE_NAME)

  all_messages = []
  for spec in all_specs:
    all_messages.extend(spec.definitions)

  with open(destination_filename, 'w') as f:
    f.write(py_template.render(all_messages=all_messages,
                               package_messages=package_spec.definitions,
                               pkg_name=name,
                               filepath='/'.join(package_spec.filepath) + '.yaml',
                               max_msgid_len=package_spec.max_msgid_len,
                               description=package_spec.description,
                               timestamp=package_spec.creation_timestamp,
                               extract_template_fields=extract_template_fields,
                               include=extensions(package_spec.includes)))

def render_version(output_dir, release: ReleaseVersion):
  destination_filename = '%s/cpp/version.h' % output_dir
  py_template = JENV.get_template(VERSION_TEMPLATE_NAME)
  with open(destination_filename, 'w') as output_file:
    output_file.write(py_template.render(major=release.major,
                                         minor=release.minor,
                                         patch=release.patch,
                                         full_version=release.full_version))