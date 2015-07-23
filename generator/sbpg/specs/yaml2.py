#!/usr/bin/env python
# Copyright (C) 2011-2014 Swift Navigation Inc.
# Contact: Fergus Noble <fergus@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
Parsing YAML specifications of SBP.
"""

import glob
import os
import sbpg.specs.yaml_schema as s
import sbpg.syntax as sbp
import sys
import yaml

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
  Exception
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
      raise Exception("Empty yaml file: %s." % filename)
    try:
      s.package_schema(contents)
    except Exception as e:
      sys.stderr.write("Invalid SBP YAML specification: %s.\n" % filename)
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
  return (base_dir, file_index)

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

##############################################################################
#

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
  identifier, contents = defn.items()[0]
  fs = [mk_field(f) for f in contents.get('fields', [])]
  return sbp.resolve_type(sbp.Definition(identifier=identifier,
                                         sbp_id=contents.get('id', None),
                                         short_desc=contents.get('short_desc', None),
                                         desc=contents.get('desc', None),
                                         type_id=contents.get('type'),
                                         fields=fs,
                                         public=contents.get('public', True)))

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
  identifier, contents = field.items()[0]
  contents = dict({'units': '', 'n_with_values': 0}.items() + contents.items())
  return sbp.resolve_type(sbp.Field(identifier=identifier,
                                    type_id=contents.pop('type'),
                                    options=contents))
