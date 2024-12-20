#!/usr/bin/env python
# Copyright (C) 2011-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
Parsing YAML specifications of SBP.
"""

import glob
import inspect
import itertools
import os
import string
import sys

import yaml

import sbpg.specs.yaml_schema as s
import sbpg.specs.yaml_test_schema as t
import sbpg.syntax as sbp
import sbpg.test_structs as sbp_test

##############################################################################
#


def read_spec(filename, verbose=False):
  """
  Read an SBP specification.

  Parameters
  ----------
  filename : str
    Local filename for specification.
  verbose : bool
    Print out some debugging info

  Returns
  ----------

  Raises
  ----------
  ValueError
    On empty file.
  yaml.YAMLError
    On Yaml parsing error
  voluptuous.Invalid
    On invalid SBP schema
  """
  contents = None
  with open(filename, 'r') as f:
    contents = yaml.safe_load(f)
    if contents is None:
      raise ValueError("Empty yaml file: %s." % filename)
    try:
      s.package_schema(contents)
    except Exception as e:
      sys.stderr.write("Invalid SBP YAML specification: %s.\n" % filename)
      raise e
  return contents

def read_test_spec(filename, verbose=False):
  """
  Read an SBP test specification.

  Parameters
  ----------
  filename : str
    Local filename for specification.
  verbose : bool
    Print out some debugging info

  Returns
  ----------

  Raises
  ----------
  ValueError
    On empty file.
  yaml.YAMLError
    On Yaml parsing error
  voluptuous.Invalid
    On invalid SBP schema
  """
  contents = None
  with open(filename, 'r') as f:
    contents = yaml.safe_load(f)
    if contents is None:
      raise ValueError("Empty yaml file: %s." % filename)
    try:
      t.test_schema(contents)
    except Exception as e:
      sys.stderr.write("Invalid SBP test YAML specification: %s.\n" % filename)
      raise e
  return contents

def get_files(input_file):
  """
  Initializes an index of files to generate, returns the base
  directory and index.

  """
  file_index = {}
  base_dir = None
  if os.path.isfile(input_file):
    file_index[input_file] = None
    base_dir = os.path.dirname(input_file)
  elif os.path.isdir(input_file):
    base_dir = input_file
    for inf in glob.glob(input_file + s.SBP_EXTENSION):
      file_index[os.path.abspath(inf)] = None
    for inf in glob.glob(input_file + '/*'):
      base, index = get_files(os.path.abspath(inf))
      z = file_index.copy()
      z.update(index)
      file_index = z
  return (base_dir, file_index)

def resolve_test_deps(base_dir, file_index):
  """
  Given a base directory and an initial set of files, retrieves
  dependencies and adds them to the file_index.

  """
  def flatten(tree, index = {}):
    for include in tree.get('include', []):
      fname = base_dir + "/" + include
      assert os.path.exists(fname), "File %s does not exist." % fname
      if fname not in index:
        index[fname] = read_test_spec(fname)
        index.update(flatten(index[fname], file_index))
    return index
  for fname, contents in file_index.items():
    file_index[fname] = read_test_spec(fname)
    file_index.update(flatten(file_index[fname], file_index))
  return file_index

# TODO (Buro): I imagine we'd want to do a basic toposort of the
# package and type dependencies to properly resolve types and detect
# circular dependencies.
def resolve_deps(base_dir, file_index):
  """
  Given a base directory and an initial set of files, retrieves
  dependencies and adds them to the file_index.

  """
  def flatten(tree, index = {}):
    for include in tree.get('include', []):
      fname = base_dir + "/" + include
      assert os.path.exists(fname), "File %s does not exist." % fname
      if fname not in index:
        index[fname] = read_spec(fname)
        index.update(flatten(index[fname], file_index))
    return index
  for fname, contents in file_index.items():
    file_index[fname] = read_spec(fname)
    file_index.update(flatten(file_index[fname], file_index))
  return file_index

def parse_spec(contents):
  return mk_package(contents)

def parse_test_spec(fname, contents, spec_no):
  return mk_package_test_suite(fname, contents, spec_no)

##############################################################################
#

def mk_package_test_suite(fname, contents, spec_no):
  """Instantiates a package test specification from a parsed "AST" of a
  package test.

  Parameters
  ----------
  contents : dict

  Returns
  ----------
  PackageTestSpecification

  """
  package = contents.get('package', None)
  description = contents.get('description', None)
  generated_on = contents.get('generated_on', None)
  tests = contents.get('tests', [])
  resolved = [mk_test(test) for test in tests]
  test_structs = contents.get('struct_tests', [])
  resolved_structs = [mk_test_struct(test) for test in test_structs]

  # Get current directory, root directory, and then strip root directory from test suite filename
  curr_file_dir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
  root_libsbp_dir = os.path.realpath(os.path.join(curr_file_dir, '../../../'))
  fname = str.replace(fname, root_libsbp_dir+'/', '')

  return sbp_test.PackageTestSpecification(package=package,
                                  src_filename=fname,
                                  suite_no=spec_no,
                                  description=description,
                                  generated_on=generated_on,
                                  tests=resolved,
                                  test_structs=resolved_structs)

def mk_test(test):
  """Instantiates a test for a particular SBP message.

  """
  assert len(test) == 5
  return sbp_test.TestSpecification(raw_packet=test.get('raw_packet', None),
                                    msg_type=test.get('msg_type', None),
                                    raw_json=test.get('raw_json', None),
                                    msg=test.get('msg', None),
                                    sbp=test.get('sbp', None))

def mk_test_struct(spec):
    """Instantiates a test for a particular SBP struct.

    """
    assert len(spec) == 4
    return sbp_test.TestStructSpecification(spec)

def mk_package(contents):
  """Instantiates a package specification from a parsed "AST" of a
  package.

  Parameters
  ----------
  contents : dict

  Returns
  ----------
  PackageSpecification

  """
  package = contents.get('package', None)
  description = contents.get('description', None)
  include = contents.get('include', [])
  definitions = contents.get('definitions', [])
  resolved = [mk_definition(defn) for defn in definitions]
  return sbp.PackageSpecification(identifier=package,
                                  description=description,
                                  includes=include,
                                  definitions=resolved,
                                  render_source=contents.get('render_source', True),
                                  stable=contents.get('stable', False),
                                  public=contents.get('public', True))
def mk_definition(defn):
  """Instantiates a struct or SBP message specification from a parsed
  "AST" of a struct or message.

  Parameters
  ----------
  defn : dict

  Returns
  ----------
  A Definition or a specialization of a definition, like a Struct

  """
  assert len(defn) == 1
  identifier, contents = next(iter(defn.items()))
  fs = [mk_field(f) for f in contents.get('fields', [])]
  type_id = contents.get('type')
  desc = contents.get('desc', None)
  if desc and type_id not in ["collection", "primitive"]:
    desc = desc.strip()
    if not desc.upper() == "DEPRECATED":
      assert desc.endswith("."), f"{identifier}: Append . to: `{desc}`"
    assert all(x in string.printable for x in desc), f"Unprintable: {desc}"
    lines = desc.splitlines()
    assert all(line.strip() == line for line in lines), f"Extra whitespace:\n{lines}"
    odd_lines = list(itertools.islice(lines,1,len(lines),2))
    if any(line for line in odd_lines):
      print(f"Warning: Multi-line desc contains single blank lines (use two):\n{lines}")
  short_desc = contents.get("short_desc", None)
  if short_desc:
    assert not short_desc.endswith("."), f"{identifier}: Remove . from: `{short_desc}`"
    assert all(x in string.printable for x in short_desc), f"Unprintable: {short_desc}"
    assert len(short_desc.splitlines()) == 1, f"Multi-line short_desc: {short_desc}"
  return sbp.resolve_type(sbp.Definition(identifier=identifier,
                                         sbp_id=contents.get('id', None),
                                         short_desc=short_desc,
                                         desc=desc,
                                         type_id=type_id,
                                         fields=fs,
                                         public=contents.get('public', True),
                                         embedded_type=contents.get('embedded_type', False),
                                         ))

def mk_field(field):
  """Instantiates a field specification from a parsed "AST" of a
  field.

  Parameters
  ----------
  field : dict

  Returns
  ----------
  A Field or a specialization of a field, like a bitfield.

  """
  assert len(field) == 1
  identifier, contents = next(iter(field.items()))
  contents = dict(list({'units': '', 'n_with_values': 0}.items()) + list(contents.items()))
  return sbp.resolve_type(sbp.Field(identifier=identifier,
                                    type_id=contents.pop('type'),
                                    options=contents))
