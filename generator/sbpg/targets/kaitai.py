#!/usr/bin/env python
# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""Generator for Kaitai Struct target.

This module consumes the YAML spec and generates some message class
files.

"""

import copy

from jinja2.environment import Environment
from jinja2.utils import pass_environment

from sbpg.targets.templating import INCLUDE_MAP, JENV, indented_wordwrap
from sbpg import ReleaseVersion
from sbpg.utils import comment_links
import textwrap
import os
import re
import subprocess

TEMPLATE_TYPES_NAME = "sbp_kaitai_types.ksy.j2"
TEMPLATE_MAIN_NAME = "sbp_kaitai_main.ksy.j2"

KAITAI_CODE = {
  'u8': 'u1',
  'u16': 'u2',
  'u32': 'u4',
  'u64': 'u8',
  's8': 's1',
  's16': 's2',
  's32': 's4',
  's64': 's8',
  'float': 'f4',
  'double': 'f8'
}

OUTPUT_LANGUAGES = [
  'graphviz',
  'csharp',
  #'rust',
  'perl',
  'java',
  'go',
  'cpp_stl',
  'php',
  'lua',
  'python',
  'nim',
  'html',
  'ruby',
  #'construct',
  'javascript'
]

def get_custom_type(type_id):
  # check if this type originates from an imported module
  prefix = None
  for module in INCLUDE_MAP.keys():
      if type_id in INCLUDE_MAP[module]:
          prefix = module

  if prefix is not None:
    return "{}::{}".format(snake_case(prefix), snake_case(type_id))
  else:
    return snake_case(type_id)


def get_type(f, type_map=KAITAI_CODE):
  """
  Formats for binary-parser library
  """
  if f.type_id in type_map:
    return type_map[f.type_id]
  elif f.type_id == 'string':
      return """str
        encoding: ascii
        size-eos: true"""
  elif f.type_id == 'array' and f.options.get('size', None):
    fill = f.options['fill'].value
    f_ = copy.copy(f)
    f_.type_id = fill
    s = f.options.get('size', None).value
    return """{}
        repeat: expr
        repeat-expr: {}""".format(type_map.get(f_.type_id, 'u8'), s)
  elif f.type_id == 'array':
    fill = f.options['fill'].value
    return """{}
        repeat: eos""".format(type_map.get(fill, get_custom_type(fill)))
  else:
    return get_custom_type(f.type_id)


def snake_case(s):
  """
  Convert CamelCase to snake_case
  """
  if "_" in s:
    return "_".join(snake_case(p) for p in s.split("_"))
  if len(s) == 1:
    return s.lower()
  s = re.sub("(.)([A-Z][a-z]+)", r"\1_\2", s)
  return re.sub("([a-z0-9])([A-Z])", r"\1_\2", s).lower()


@pass_environment
def commentify(environment: Environment,
               value: str, width=76, indent=2):
  """
  Builds a comment
  """
  return indented_wordwrap(environment, value, width=width, indent=" " * indent, first=False)


def hash_wordwrap(s):
  return "\n# ".join(textwrap.wrap(' '.join(s.split('\n')), 80))


def get_imports(package_spec):
  includes = [".".join(i.split(".")[:-1]) for i in package_spec.includes]
  return [i for i in includes if i != "types"]


def get_module_name(identifier):
  return identifier.split(".")[-1]


JENV.filters['get_type'] = get_type
JENV.filters['snake_case'] = snake_case
JENV.filters['commentify'] = commentify
JENV.filters['comment_links'] = comment_links
JENV.filters['hashWordWrap'] = hash_wordwrap
JENV.filters['module_name'] = get_module_name


# apply fix-ups to generated python code to work-around missing imports
# issue described in kaitai-struct-compiler 0.10,
# see https://github.com/kaitai-io/kaitai_struct/issues/703 for details
def fix_python_output(specs):
  def add_python_imports(basename, imports):
    # nothing to do
    if len(imports) == 0:
      return

    # check if file exists
    py_file = "python/{}.py".format(basename)
    if not os.path.exists(py_file):
      return

    # read file
    code = None
    with open(py_file, 'r') as f:
      code = f.read()
    if code is None:
      return

    # overwrite file
    with open(py_file, 'w') as f:
      for module in imports:
        f.write("from .{} import *\n".format(module))
      f.write(code)

  # add imports for individual types
  for package_spec in specs:
    imports = get_imports(package_spec)
    add_python_imports(package_spec.filepath[1], imports)

  # add imports for main file
  add_python_imports("sbp", [get_module_name(spec.identifier) for spec in specs])


def render_source(output_dir, package_spec, jenv=JENV):
  """
  Render and output KSY file containing types
  """
  path, name = package_spec.filepath
  destination_filename = "{}/ksy/{}.ksy".format(output_dir, name)
  ksy_template = jenv.get_template(TEMPLATE_TYPES_NAME)
  imports = ','.join(get_imports(package_spec))

  with open(destination_filename, 'w') as f:
    f.write(ksy_template.render(name=name,
                               msgs=package_spec.definitions,
                               filepath="/".join(package_spec.filepath) + ".yaml",
                               imports=imports,
                               timestamp=package_spec.creation_timestamp,
                               description=package_spec.description))


def render_main(output_dir, all_package_specs, release: ReleaseVersion, jenv=JENV):
  """
  Render and output top-level KSY file, then run kaitai-struct-compiler
  """
  directory = output_dir
  destination_filename = "{}/ksy/sbp.ksy".format(output_dir)
  ksy_template = jenv.get_template(TEMPLATE_MAIN_NAME)
  specs = [spec for spec in all_package_specs if spec.render_source]

  with open(destination_filename, 'w') as f:
    f.write(ksy_template.render(specs=specs,
                               version=release.full_version))

  # run kaitai-struct-compiler to generate parsing code for all suported
  # languages
  os.chdir(output_dir)
  targets = [x for y in [[ "--target", lang ] for lang in OUTPUT_LANGUAGES] for x in y]
  subprocess.check_call(["kaitai-struct-compiler", "ksy/sbp.ksy"] + targets)

  fix_python_output(specs)