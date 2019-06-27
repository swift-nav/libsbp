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

"""Generator for Python target.

This module consumes the YAML spec and generates some message class
files.

"""

from sbpg.targets.templating import JENV, ACRONYMS
from sbpg.utils import comment_links
import copy

TEMPLATE_NAME = "sbp_numba.py.j2"

NUMPY_TYPE = {
  'u8': 'uint8',
  'u16': 'uint16',
  'u32': 'uint32',
  'u64': 'uint64',
  's8': 'int8',
  's16': 'int16',
  's32': 'int32',
  's64': 'int64',
  'float': 'float32',
  'double': 'float64',
}

NUMBA_GET_FN = {
  'u8': 'get_u8',
  'u16': 'get_u16',
  'u32': 'get_u32',
  'u64': 'get_u64',
  's8': 'get_s8',
  's16': 'get_s16',
  's32': 'get_s32',
  's64': 'get_s64',
  'float': 'get_f32',
  'double': 'get_f64',
}

NUMBA_TY_BYTES = {
  'u8': 1,
  'u16': 2,
  'u32': 4,
  'u64': 8,
  's8': 1,
  's16': 2,
  's32': 4,
  's64': 8,
  'float': 4,
  'double': 8,
}

PYDOC_CODE = {
  'u8': 'int',
  'u16': 'int',
  'u32': 'int',
  'u64': 'int',
  's8': 'int',
  's16': 'int',
  's32': 'int',
  's64': 'int',
  'float': 'float',
  'double': 'double',
}


def is_array():
  return False


def numba_type(f):
  if f.type_id == 'float':
    return 'judicious_round(np.' + NUMPY_TYPE[f.type_id] + \
      '(__' + f.identifier + ')) if SBP.judicious_rounding else __' + f.identifier
  else:
    return '__' + f.identifier


def numba_size(f):
  # the worst case 255 - 6 (header) - 2 (crc)
  UNKNOWN_LEN = 255 - 6 - 2

  if f.type_id in NUMBA_TY_BYTES:
    return NUMBA_TY_BYTES[f.type_id]
  elif f.type_id == 'string':
    if f.options.get('size', None) is not None:
      return f.options.get('size', None).value
    return UNKNOWN_LEN
  elif f.type_id == 'array':
    # NOTE: arrays of arrays are not supported
    t = f.options['fill'].value
    count = f.options.get('size', None)
    if count:
      if t in NUMBA_TY_BYTES:
        return "%d * %d" % (NUMBA_TY_BYTES[t], count.value)
      else:
        return t + "._payload_size() * %d" % (count.value)
    else:
      return UNKNOWN_LEN
  else:
    return f.type_id + '._payload_size()'


def numba_format(f):
  if NUMBA_GET_FN.get(f.type_id, None):
    return NUMBA_GET_FN.get(f.type_id)
  elif f.type_id == 'string' and f.identifier == 'setting' and not f.options.get('size', None):
    # setting string with null delimiters as a special case
    return 'get_setting'
  elif f.type_id == 'string' and f.options.get('size', None):
    s = f.options.get('size', None).value
    return 'get_fixed_string(%d)' % (s,)
  elif f.type_id == 'string' and not f.options.get('size', None):
    return 'get_string'
  elif f.type_id == 'array' and f.options.get('size', None):
    count = f.options.get('size', None).value
    t = f.options['fill'].value
    if t in NUMBA_GET_FN:
      fill_func = NUMBA_GET_FN[t]
      el_size = NUMBA_TY_BYTES[t]
      if f.options['fill'].value == 'float':
        return "get_fixed_array(%s, %d, %d, %s if SBP.judicious_rounding else None)" \
          % (fill_func, count, el_size, 'np.float32')
      else:
        return "get_fixed_array(%s, %d, %d)" % (fill_func, count, el_size)
    else:
      fill_func = f.options['fill'].value + '._unpack_members'
      el_size = f.options['fill'].value + '._payload_size()'
      return "get_fixed_array(%s, %d, %s)" % (fill_func, count, el_size)
  elif f.type_id == 'array':
    fill = f.options['fill'].value
    f_ = copy.copy(f)
    f_.type_id = fill
    return "get_array(%s)" % (numba_format(f_),)
  else:
    return '%s.parse_members' % (f.type_id)
  raise NotImplementedError()


def pydoc_format(type_id, pydoc=PYDOC_CODE):
  """
  Formats type for pydoc.
  """
  return pydoc.get(type_id, type_id)


def classnameify(s):
  """
  Makes a classname.
  """
  return ''.join(w if w in ACRONYMS else w.title() for w in s.split('_'))


JENV.filters['numba_py'] = numba_format
JENV.filters['numba_type'] = numba_type
JENV.filters['numba_size'] = numba_size
JENV.filters['classnameify'] = classnameify
JENV.filters['pydoc'] = pydoc_format
JENV.filters['comment_links'] = comment_links


def render_source(output_dir, package_spec, jenv=JENV):
  """
  Render and output
  """
  path, name = package_spec.filepath
  directory = output_dir
  destination_filename = "%s/%s.py" % (directory, name)
  py_template = jenv.get_template(TEMPLATE_NAME)
  module_path = ".".join(package_spec.identifier.split(".")[1:-1])
  includes = [".".join(i.split(".")[:-1]) for i in package_spec.includes]
  includes = [i for i in includes if i != "types"]
  print(destination_filename, includes)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(msgs=package_spec.definitions,
                               filepath="/".join(package_spec.filepath) + ".yaml",
                               module_path=module_path,
                               include=includes,
                               timestamp=package_spec.creation_timestamp,
                               description=package_spec.description))
