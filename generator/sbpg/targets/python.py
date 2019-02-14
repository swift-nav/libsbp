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

TEMPLATE_NAME = "sbp_construct_template.py.j2"
VERSION_TEMPLATE_NAME = "sbp_python_relver_template.j2"

CONSTRUCT_CODE = {
  'u8': 'construct.Int8ul',
  'u16': 'construct.Int16ul',
  'u32': 'construct.Int32ul',
  'u64': 'construct.Int64ul',
  's8': 'construct.Int8sl',
  's16': 'construct.Int16sl',
  's32': 'construct.Int32sl',
  's64': 'construct.Int64sl',
  'float': 'construct.Float32l',
  'double': 'construct.Float64l',
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


def construct_format(f, type_map=CONSTRUCT_CODE):
  """
  Formats for Construct.
  """
  formatted = ""
  if type_map.get(f.type_id, None):
    return "'{identifier}' / {type_id}".format(type_id=type_map.get(f.type_id),
                                             identifier=f.identifier)
  elif f.type_id == 'string' and f.options.get('size', None):
    return "'{id}'/ construct.Bytes({size})".format(id=f.identifier,
                                                   size=f.options['size'].value)
  elif f.type_id == 'string':
    return "'{id}' / construct.GreedyBytes".format(id=f.identifier)
  elif f.type_id == 'array' and f.options.get('size', None):
    fill = f.options['fill'].value
    f_ = copy.copy(f)
    f_.type_id = fill
    s = f.options.get('size', None).value
    return "'{id}' / construct.Array({size}, {type})".format(id=f.identifier, size=s, type=type_map.get(f_.type_id, 'construct.Byte'))
  elif f.type_id == 'array':
    fill = f.options['fill'].value
    f_ = copy.copy(f)
    f_.type_id = fill
    return "construct.GreedyRange(%s)" % construct_format(f_)
  else:
    return "'%s' / construct.Struct(%s._parser)" % (f.identifier, f.type_id)
  return formatted


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

JENV.filters['construct_py'] = construct_format
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


def render_version(output_dir, release):
  destination_filename = "%s/RELEASE-VERSION" % output_dir
  print(destination_filename)
  major, minor, patch = release.split('.')[:3]
  py_template = JENV.get_template(VERSION_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(major=major, minor=minor, patch=patch))
