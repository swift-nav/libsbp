#!/usr/bin/env python
# Copyright (C) 2015-2023 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
Generator for Kaitai Struct target.

This module consumes the SBP YAML spec and generates message class files plus
a top-level main file.
"""

import copy

from jinja2.environment import Environment
from jinja2.utils import pass_environment

from sbpg.targets.templating import INCLUDE_MAP, JENV, indented_wordwrap
from sbpg.targets.common import snake_case, camel_case
from sbpg import ReleaseVersion
from sbpg.utils import comment_links
import textwrap
import os
import subprocess
import fileinput

TEMPLATE_TYPES = "kaitai/types.ksy.j2"
TEMPLATE_MAIN = "kaitai/main.ksy.j2"
TEMPLATE_PYTHON_TABLE = "kaitai/table_python.py.j2"
TEMPLATE_PERL_TABLE = "kaitai/table_perl.pm.j2"

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
  Formats for Kaitai Struct description file
  """
  if f.type_id in type_map:
    return type_map[f.type_id]
  elif f.type_id == 'string':
      ret = """str
        encoding: ascii"""
      if 'size' in f.options:
        ret += """
        size: {}""".format(f.options['size'].value)
      else:
        ret += """
        size-eos: true"""
# would be nice to have, but this prevents us from producing identical output
# to the existing construct-based implementation of sbp2json
#      if 'encoding' in f.options:
#        e = f.options["encoding"].value
#        if e == 'null_terminated' or e == 'double_null_terminated':
#          ret += """
#        terminator: 0"""
      return ret
  elif f.type_id == 'array':
    fill = f.options['fill'].value
    if 'size' in f.options:
      f_ = copy.copy(f)
      f_.type_id = fill
      s = f.options['size'].value
      return """{}
        repeat: expr
        repeat-expr: {}""".format(type_map.get(f_.type_id, get_custom_type(fill)), s)
    else:
      return """{}
        repeat: eos""".format(type_map.get(fill, get_custom_type(fill)))
  else:
    return get_custom_type(f.type_id)


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
JENV.filters['camel_case'] = camel_case
JENV.filters['commentify'] = commentify
JENV.filters['comment_links'] = comment_links
JENV.filters['hashWordWrap'] = hash_wordwrap
JENV.filters['module_name'] = get_module_name


# apply fix-ups to generated python code to work around missing imports
# issue in kaitai-struct-compiler 0.10, see
# https://github.com/kaitai-io/kaitai_struct/issues/703 for details
def fix_python_output(output_dir, specs):
  def add_python_imports(basename, imports):
    # nothing to do
    if len(imports) == 0:
      return

    # check if file exists
    py_file = os.path.join(output_dir, "python", "kaitai_sbp", basename + ".py")
    with fileinput.input(files=(py_file), inplace=True) as f:
      # copy comment line
      line = f.readline()
      print(line, end='')
      for module in imports:
        print("from .{} import *".format(module))
      for line in f:
        print(line, end='')

  # add imports for individual types
  for package_spec in specs:
    imports = get_imports(package_spec)
    add_python_imports(package_spec.filepath[1], imports)

  # add imports for main file
  add_python_imports("sbp", [get_module_name(spec.identifier) for spec in specs])


# apply fix-ups to generated perl code to work around incorrectly initialised
# arrays issue in kaitai-struct-compiler 0.10, see
# https://github.com/kaitai-io/kaitai_struct_compiler/pull/251 for details
def fix_perl_output(output_dir, specs):
  files = [os.path.join(output_dir, "perl", "KaitaiSbp", camel_case(package_spec.filepath[1]) + ".pm") for package_spec in specs]
  with fileinput.input(files=files, inplace=True) as f:
    for line in f:
      if line.endswith("= ();\n"):
        line = line[:-4] + "[];\n";
      print(line, end='')

  def add_perl_imports(basename, imports):
    # nothing to do
    if len(imports) == 0:
      return

    # check if file exists
    pm_file = os.path.join(output_dir, "perl", "KaitaiSbp", camel_case(basename) + ".pm")
    with fileinput.input(files=(pm_file), inplace=True) as f:
      # copy comment line
      line = f.readline()
      print(line, end='')
      for module in imports:
        print("use KaitaiSbp::{};".format(camel_case(module)))
      for line in f:
        print(line, end='')

  # add imports for individual types
  for package_spec in specs:
    imports = get_imports(package_spec)
    add_perl_imports(package_spec.filepath[1], imports)

  # add imports for main file
  add_perl_imports("Sbp", [get_module_name(spec.identifier) for spec in specs])


# create table-based version of SBP message for faster parsing
def render_python_table(output_dir, specs, jenv):
  destination_filename = os.path.join(output_dir, "python", "kaitai_sbp", "table.py")
  ksy_template = jenv.get_template(TEMPLATE_PYTHON_TABLE)
  with open(destination_filename, 'w') as f:
    f.write(ksy_template.render(specs=specs))


# create table-based version of SBP message for faster parsing
def render_perl_table(output_dir, specs, jenv):
  destination_filename = os.path.join(output_dir, "perl", "KaitaiSbp", "Table.pm")
  ksy_template = jenv.get_template(TEMPLATE_PERL_TABLE)
  with open(destination_filename, 'w') as f:
    f.write(ksy_template.render(specs=specs))


def render_source(output_dir, package_spec, jenv=JENV):
  """
  Render and output a KSY file containing types
  """
  path, name = package_spec.filepath
  destination_filename = os.path.join(output_dir, "ksy", name + ".ksy")
  ksy_template = jenv.get_template(TEMPLATE_TYPES)
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
  Render and output the top-level KSY file, then run kaitai-struct-compiler
  """
  destination_filename = os.path.join(output_dir, "ksy", "sbp.ksy")
  ksy_template = jenv.get_template(TEMPLATE_MAIN)
  specs = [spec for spec in all_package_specs if spec.render_source]

  with open(destination_filename, 'w') as f:
    f.write(ksy_template.render(specs=specs,
                               version=release.full_version))

  render_python_table(output_dir, specs, jenv)
  render_perl_table(output_dir, specs, jenv)

  # run kaitai-struct-compiler to generate bindings
  subprocess.check_call(["kaitai-struct-compiler", "ksy/sbp.ksy", "--target", "python", "--outdir", "python/kaitai_sbp"], cwd=output_dir)
  subprocess.check_call(["kaitai-struct-compiler", "ksy/sbp.ksy", "--target", "perl", "--outdir", "perl/KaitaiSbp"], cwd=output_dir)

  fix_python_output(output_dir, specs)
  fix_perl_output(output_dir, specs)
