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
Generator for Haskell target.
"""

import string
import copy
from sbpg.targets.templating import *

MESSAGES_TEMPLATE_NAME = "SbpMessagesTemplate.hs"
CABAL_TEMPLATE_NAME = "sbp-template.cabal"

CONSTRUCT_CODE = {
  'u8': 'Word8',
  'u16': 'Word16',
  'u32': 'Word32',
  'u64': 'Word64',
  's8': 'Int8',
  's16': 'Int16',
  's32': 'Int32',
  's64': 'Int64',
  'float': 'Float',
  'double': 'Double',
  'string': 'Text',
}

def camel_case(s):
  """
  Convert snake_case to camel_case.
  """
  return "".join([string.capitalize(i) for i in s.split("_")])

def to_global(s):
  """
  Format a global variable name.
  """
  if '_' in s:
    s = "".join([string.capitalize(i) for i in s.split("_")])
  return s[0].lower() + s[1:]

def to_data(s):
  """
  Format a data variable name.
  """
  if '_' in s:
    return "".join([string.capitalize(i) for i in s.split("_")])
  return s

def to_type(f, type_map=CONSTRUCT_CODE):
  """
  Format a the proper type.
  """
  name = f.type_id
  if type_map.get(name, None):
    return type_map.get(name, None)
  elif name == 'array':
    fill = f.options['fill'].value
    f_ = copy.copy(f)
    f_.type_id = fill
    return "[%s]" % to_type(f_)
  return name

def max_fid_len(m):
  """
  Max field id length.
  """
  return len(to_global(m.identifier)) + m.max_fid_len

JENV.filters['to_global'] = to_global
JENV.filters['to_data'] = to_data
JENV.filters['to_type'] = to_type
JENV.filters['max_fid_len'] = max_fid_len
JENV.filters['camel_case'] = camel_case

def render_source(output_dir, package_spec):
  """
  Render and output to a directory given a package specification.
  """
  path, name = package_spec.filepath
  module_prefix = "SwiftNav.SBP"
  module_name = camel_case(name)
  full_module_name = ".".join([module_prefix, module_name])
  destination_filename = "%s/src/SwiftNav/SBP/%s.hs" % (output_dir, module_name)
  py_template = JENV.get_template(MESSAGES_TEMPLATE_NAME)
  module_includes = [".".join([module_prefix] + [camel_case(j) for j in i.split(".")[:-1]])
                     for i in package_spec.includes]
  print module_name, module_includes
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(msgs=package_spec.definitions,
                               module_name=full_module_name))

def render_cabal(output_dir, package_specs, release):
  modules = []
  module_prefix = "SwiftNav.SBP"
  for package_spec in package_specs:
    if not package_spec.render_source:
      continue
    path, name = package_spec.filepath
    module_name = camel_case(name)
    full_module_name = ".".join([module_prefix, module_name])
    modules.append(full_module_name)
  destination_filename = "%s/sbp.cabal" % output_dir
  py_template = JENV.get_template(CABAL_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(modules=sorted(modules), release=release))
