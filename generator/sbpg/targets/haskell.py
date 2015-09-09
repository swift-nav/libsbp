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
SBP_TEMPLATE_NAME = "SbpTemplate.hs"

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
  'string': 'ByteString',
}

GET_CONSTRUCT_CODE = {
  'u8': 'getWord8',
  'u16': 'getWord16le',
  'u32': 'getWord32le',
  'u64': 'getWord64le',
  's8': 'liftM fromIntegral getWord8',
  's16': 'liftM fromIntegral getWord16le',
  's32': 'liftM fromIntegral getWord32le',
  's64': 'liftM fromIntegral getWord64le',
  'float': 'getFloat32le',
  'double': 'getFloat64le',
}

PUT_CONSTRUCT_CODE = {
  'u8': 'putWord8',
  'u16': 'putWord16le',
  'u32': 'putWord32le',
  'u64': 'putWord64le',
  's8': 'putWord8 $ fromIntegral',
  's16': 'putWord16le $ fromIntegral',
  's32': 'putWord32le $ fromIntegral',
  's64': 'putWord64le $ fromIntegral',
  'float': 'putFloat32le',
  'double': 'putFloat64le',
  'string': 'putByteString',
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

def to_get(f, type_map=GET_CONSTRUCT_CODE):
  name = f.type_id
  if type_map.get(name, None):
    return type_map.get(name, None)
  elif name == 'string' and f.options.get('size', None):
    return "getByteString %s" % f.options.get('size').value
  elif name == 'string':
    return "liftM toStrict getRemainingLazyByteString"
  elif name == 'array' and f.options.get('size', None):
    fill = f.options['fill'].value
    f_ = copy.copy(f)
    f_.type_id = fill
    s = f.options.get('size', None).value
    return "replicateM %d %s" % (s, to_get(f_, type_map))
  elif name == 'array':
    fill = f.options['fill'].value
    f_ = copy.copy(f)
    f_.type_id = fill
    return "whileM (liftM not isEmpty) %s" % to_get(f_, type_map)
  return type_map.get(name, "get")

def to_put(f, type_map=PUT_CONSTRUCT_CODE):
  name = f.type_id
  if type_map.get(name, None):
    return type_map.get(name, None)
  elif name == 'array':
    fill = f.options['fill'].value
    f_ = copy.copy(f)
    f_.type_id = fill
    return "mapM_ %s" % to_put(f_, type_map)
  return type_map.get(name, "put")

def max_fid_len(m):
  """
  Max field id length.
  """
  return len(to_global(m.identifier)) + m.max_fid_len

JENV.filters['to_global'] = to_global
JENV.filters['to_data'] = to_data
JENV.filters['to_type'] = to_type
JENV.filters['to_get'] = to_get
JENV.filters['to_put'] = to_put
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
                               description=package_spec.description,
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
    f.write(py_template.render(modules=sorted(modules),
                               release=release))

def render_sbp(output_dir, package_specs):
  modules = []
  msgs = []
  module_prefix = "SwiftNav.SBP"
  for package_spec in package_specs:
    if not package_spec.render_source:
      continue
    path, name = package_spec.filepath
    module_name = camel_case(name)
    full_module_name = ".".join([module_prefix, module_name])
    modules.append(full_module_name)
    for m in package_spec.definitions:
      if m.static and m.sbp_id:
        msgs.append(to_data(m.identifier))
  print sorted(msgs)
  destination_filename = "%s/src/SwiftNav/SBP.hs" % output_dir
  py_template = JENV.get_template(SBP_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(modules=sorted(modules),
                               pkgs=package_specs,
                               msgs=sorted(msgs)))
