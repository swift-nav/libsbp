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

"""Generator for JavaScript target.

This module consumes the YAML spec and generates some message classes
files.

"""

from sbpg.targets.templating import JENV
from sbpg.utils import comment_links
import copy
import textwrap


TEMPLATE_NAME = "sbp_js.js.j2"

CONSTRUCT_CODE = {
  'u8': 'uint8',
  'u16': 'uint16',
  'u32': 'uint32',
  'u64': 'uint64',
  's8': 'int8',
  's16': 'int16',
  's32': 'int32',
  's64': 'int64',
  'float': 'floatle',
  'double': 'doublele',
}

WRITE_BUFFER_CODE = {
  'u8': 'writeUInt8',
  'u16': 'writeUInt16LE',
  'u32': 'writeUInt32LE',
  'u64': 'writeUInt64LE', # only supports up to 48 bits of accuracy
  's8': 'writeInt8',
  's16': 'writeInt16LE',
  's32': 'writeInt32LE',
  's64': 'writeInt64LE', # only supports up to 48 bits of accuracy
  'float': 'writeFloatLE',
  'double': 'writeDoubleLE',
}

BUFFER_SIZE_MAP = {
  'u8': 1,
  'u16': 2,
  'u32': 4,
  'u64': 8,
  's8': 1,
  's16': 2,
  's32': 4,
  's64': 8,
  'float': 4,
  'double': 8
}

# lol
JSDOC_CODE = {
  'u8': 'number (unsigned 8-bit int, 1 byte)',
  'u16': 'number (unsigned 16-bit int, 2 bytes)',
  'u32': 'number (unsigned 32-bit int, 4 bytes)',
  'u64': 'number (unsigned 64-bit int, 8 bytes)',
  's8': 'number (signed 8-bit int, 1 byte)',
  's16': 'number (signed 16-bit int, 2 bytes)',
  's32': 'number (signed 32-bit int, 4 bytes)',
  's64': 'number (signed 64-bit int, 4 bytes)',
  'float': 'number (float, 4 bytes)',
  'double': 'number (float, 8 bytes)',
}

def is_array():
  return False


def builtin_type(type_id, type_map=WRITE_BUFFER_CODE):
  return type_map.get(type_id, None) is not None


def write_buffer(type_id, type_map=WRITE_BUFFER_CODE):
  return type_map.get(type_id, None)


def buffer_size(type_id, type_map=BUFFER_SIZE_MAP):
  if not type_map.get(type_id, None) is None:
    return type_map.get(type_id, None)
  elif type(type_id) == str:
    return "this.fields.%s.length" % type_id
  else:
    return "this.fields.%s.length" % type_id.identifier

def array_fill_size(f):
  if builtin_type(f.options['fill'].value):
    return buffer_size(f.options['fill'].value)
  else:
    return buffer_size(f.type_id)

def array_length(f):
  if 'size' in f.options:
    return f.options.get('size').value
  if 'size_fn' in f.options:
    return "'%s'" % f.options.get('size_fn').value
  return 'null'

def jsdoc_format(type_id, jsdoc=JSDOC_CODE):
  """
  Formats type for jsdoc.
  """
  return jsdoc.get(type_id, type_id)


def construct_format(f, type_map=CONSTRUCT_CODE):
  """
  Formats for binary-parser library.
  """
  formatted = ""
  if type_map.get(f.type_id, None):
    return "%s('%s')" % (type_map.get(f.type_id), f.identifier)
  elif f.type_id == 'string' and f.options.get('size', None):
    return "string('%s', { length: %d })" % (f.identifier, f.options['size'].value)
  elif f.type_id == 'string':
    return "string('%s', { greedy: true })" % (f.identifier)
  elif f.type_id == 'array':
    fill = f.options['fill'].value
    f_ = copy.copy(f)
    f_.type_id = fill
    size = f.options.get('size', None)
    size_fn = f.options.get('size_fn', None)
    field_type = type_map.get(f_.type_id, None)
    if field_type is None:
      field_type = "%s.prototype.parser" % f_.type_id
    else:
      field_type = "'%s'" % field_type
    if size is not None:
      d = { "'uint16'" : "'uint16le'", "'uint32'" : "'uint32le'", "'uint64'" : "'uint16le'",
            "'int16'" : "'int16le'", "'int32'" : "'int32le'", "'int64'" : "'int16le'" }
      field_type_arr = d.get(field_type, field_type)
      return "array('%s', { length: %d, type: %s })" % (f.identifier, size.value, field_type_arr)
    elif f.options.get('size_fn') is not None:
      return "array('%s', { type: %s, length: '%s' })" % (f_.identifier, field_type, size_fn.value)
    else:
      return "array('%s', { type: %s, readUntil: 'eof' })" % (f_.identifier, field_type)
  else:
    return "nest('%s', { type: %s.prototype.parser })" % (f.identifier, f.type_id)
  return formatted


def js_classnameify(s):
  """
  Makes a classname.
  """
  if not '_' in s:
    return s
  return ''.join(w[0].upper() + w[1:].lower() for w in s.split('_'))

def star_wordwrap(s):
  return "\n * ".join(textwrap.wrap(' '.join(s.split('\n')), 80))

def star_wordwrap_indent(s):
  return "\n *   ".join(textwrap.wrap(' '.join(s.split('\n')), 80))

def islist(x):
  return isinstance(x, list)

JENV.tests['builtinType'] = builtin_type
JENV.tests['list'] = islist

JENV.filters['js_classnameify'] = js_classnameify
JENV.filters['writeBuffer'] = write_buffer
JENV.filters['bufferSize'] = buffer_size
JENV.filters['arrayFillSize'] = array_fill_size
JENV.filters['arrayLength'] = array_length
JENV.filters['construct_js'] = construct_format
JENV.filters['jsdoc'] = jsdoc_format
JENV.filters['comment_links'] = comment_links
JENV.filters['starWordWrap'] = star_wordwrap
JENV.filters['starWordWrapIndent'] = star_wordwrap_indent


def render_source(output_dir, package_spec, jenv=JENV):
  """
  Render and output
  """
  path, name = package_spec.filepath
  directory = output_dir
  destination_filename = "%s/%s.js" % (directory, name)
  py_template = jenv.get_template(TEMPLATE_NAME)
  module_path = ".".join(package_spec.identifier.split(".")[1:-1])
  includeMap = {'gnss': ['GnssSignal', 'GnssSignalDep', 'GPSTime', 'CarrierPhase', 'GPSTime', 'GPSTimeSec', 'GPSTimeDep', 'SvId'] }
  includes = [".".join(i.split(".")[:-1]) for i in package_spec.includes]
  includes = [(i, includeMap.get(i)) for i in includes if i != "types"]
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(msgs=package_spec.definitions,
                               filepath="/".join(package_spec.filepath) + ".yaml",
                               module_path=module_path,
                               include=includes,
                               timestamp=package_spec.creation_timestamp,
                               description=package_spec.description))
