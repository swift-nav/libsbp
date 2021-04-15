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

SKIP_MESSAGE_IDS = ['MSG_FILEIO_WRITE_REQ']

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
  return stringcase.snakecase(value)

def screaming_snake_case(value):
  return stringcase.snakecase(value).upper()

def mk_field(field):
  return '{} {}'.format(mk_id(field), mk_size(field))

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
    return field.identifier

def mk_template(message, all_messages):
  normal_field_types = []
  zero_array_field = None

  for field in message.fields:
    field_type = mk_id(field)
    field_name = field.identifier

    if (field.type_id == 'array' or field.type_id == 'string') and not field.options.get('size', None):
      zero_array_field = (field_type, field_name)
    else:
      normal_field_types.append(field_type)

  if zero_array_field:
    normal_field_sizeof = ' + '.join(list(['sizeof({})'.format(field_type) for field_type in normal_field_types]) + ['0'])
    return 'template<size_t {} = (SBP_MAX_PAYLOAD_LEN - {}) / sizeof({})>'.format('{}_COUNT'.format(screaming_snake_case(zero_array_field[1])), normal_field_sizeof, zero_array_field[0])
  else:
    return ''

def get_bitfield_basename(msg, item):
    bitfield_name = item.get('desc', '').replace(' ', '_').upper()
    base_string = 'SBP_{}_{}'.format(msg.upper().replace('MSG_', ''), bitfield_name)
    base_string = re.sub('[^A-Za-z0-9_]+', '', base_string)
    return base_string

def create_bitfield_macros(field, msg):
  ret_list = []
  for item in field.options['fields'].value:
    base_string = get_bitfield_basename(msg, item)
    if not base_string.endswith('RESERVED'):
      nbits = item.get('len')
      bitrange = (item.get('range')).split(':')
      start_bit = int(bitrange[0])
      ret_list.append('#define {}_MASK ({})'.format(base_string, hex((1 << nbits) - 1)))
      ret_list.append('#define {}_SHIFT ({}u)'.format(base_string, start_bit))
      ret_list.append("""#define {}_GET(flags) \\
                             (((flags) >> {}_SHIFT) \\
                             & {}_MASK)""".format(base_string, base_string, base_string))
      ret_list.append("""#define {}_SET(flags, val) \\
                             do {{((flags) |= \\
                             (((val) & ({}_MASK)) \\
                             << ({}_SHIFT)));}} while(0)
                             """.format(base_string, base_string, base_string))
      ret_list.append('')
      for value_obj in item.get('vals', []):
        value_numerical = int(value_obj.get('value'))
        value_description = value_obj.get('desc', None).upper()
        value_description = re.sub(r'\([^)]*\)', '', value_description)
        value_description = re.sub('[ \-]+', '_', value_description.strip())
        value_description = re.sub('[^A-Za-z0-9_]+', '', value_description)
        if value_description and value_description.upper() != 'RESERVED':
          ret_list.append('#define {}_{} ({})'.format(base_string, value_description,
                                                      value_numerical))
  return '\n'.join(ret_list)

JENV.filters['commentify'] = commentify
JENV.filters['mk_field'] = mk_field
JENV.filters['pascal_case'] = pascal_case
JENV.filters['snake_case'] = snake_case
JENV.filters['create_bitfield_macros'] = create_bitfield_macros
JENV.filters['mk_template'] = mk_template

def render_source(output_dir, package_spec, all_specs):
  path, name = package_spec.filepath
  destination_filename = '%s/cpp/%s.h' % (output_dir, name)
  py_template = JENV.get_template(MESSAGES_TEMPLATE_NAME)

  all_messages = []
  for spec in all_specs:
    all_messages.extend(package_spec.definitions)

  with open(destination_filename, 'w') as f:
    f.write(py_template.render(all_messages=all_messages,
                               package_messages=package_spec.definitions,
                               pkg_name=name,
                               filepath='/'.join(package_spec.filepath) + '.yaml',
                               max_msgid_len=package_spec.max_msgid_len,
                               description=package_spec.description,
                               timestamp=package_spec.creation_timestamp,
                               skip_message=skip_message,
                               include=extensions(package_spec.includes)))

def render_version(output_dir, release: ReleaseVersion):
  destination_filename = '%s/cpp/version.h' % output_dir
  py_template = JENV.get_template(VERSION_TEMPLATE_NAME)
  with open(destination_filename, 'w') as output_file:
    output_file.write(py_template.render(major=release.major,
                                         minor=release.minor,
                                         patch=release.patch,
                                         full_version=release.full_version))