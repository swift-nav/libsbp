#!/usr/bin/env python
# Copyright (C) 2015-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
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

import copy

from jinja2.environment import Environment
from jinja2.utils import pass_environment

from sbpg.targets.templating import ACRONYMS, INCLUDE_MAP, JENV, indented_wordwrap, is_list
from sbpg.utils import comment_links
from sbpg import ReleaseVersion

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


def construct_format(f, type_map=CONSTRUCT_CODE):
  """
  Formats for Construct.
  """
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
    if type_map.get(fill):
      return "'%s' / construct.GreedyRange(%s)" % (f.identifier, type_map.get(fill))
    else:
      return "'%s' / construct.GreedyRange(%s._parser)" % (f.identifier, fill)
  else:
    return "'%s' / %s._parser" % (f.identifier, f.type_id)


@pass_environment
def commentify(environment: Environment,
               value: str, width=76, indent=2):
  """
  Builds a comment.
  """
  return indented_wordwrap(environment, value, width=width, indent=" " * indent, first=False)


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


def has_real_message(l):
  """
  Determine if module has any real messages.
  """
  return any(m.static and m.is_real_message for m in l)


def needs_raw_docstring(m):
  if m.desc and "\\0" in m.desc:
    return True
  return any(f.desc and "\\0" in f.desc for f in m.fields)


JENV.filters['has_real_message'] = has_real_message
JENV.filters['construct_py'] = construct_format
JENV.filters['classnameify'] = classnameify
JENV.filters['commentify'] = commentify
JENV.filters['pydoc'] = pydoc_format
JENV.filters['comment_links'] = comment_links

JENV.tests['list'] = is_list
JENV.tests['needs_raw_docstring'] = needs_raw_docstring


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
  includes = [(i, INCLUDE_MAP.get(i)) for i in includes if i != "types"]
  print(destination_filename, includes)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(msgs=package_spec.definitions,
                               filepath="/".join(package_spec.filepath) + ".yaml",
                               module_path=module_path,
                               include=includes,
                               timestamp=package_spec.creation_timestamp,
                               description=package_spec.description))


def render_version(output_dir, release: ReleaseVersion):
  destination_filename = "%s/RELEASE-VERSION" % output_dir
  print(destination_filename)
  py_template = JENV.get_template(VERSION_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(major=release.major,
                               minor=release.minor,
                               patch=release.patch_pre))
