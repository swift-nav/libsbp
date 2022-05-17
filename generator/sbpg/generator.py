#!/usr/bin/python

# Copyright (C) 2015-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
Main executable.
"""

import argparse
import os
import pprint
import sbpg.specs.yaml2 as yaml

from sbpg import ReleaseVersion

def get_args():
  parser = argparse.ArgumentParser(description='Swift Navigation SBP generator.')
  parser.add_argument('-i',
                      '--input_file',
                      nargs=1,
                      required=True,
                      help='Input spec file or directory.')
  parser.add_argument('-o',
                      '--output_dir',
                      nargs=1,
                      required=True,
                      help='Output directory.')
  parser.add_argument('--python',
                      action="store_true",
                      help='Target language: Python.')
  parser.add_argument('--javascript',
                      action="store_true",
                      help='Target language: JavaScript.')
  parser.add_argument('--c',
                      action="store_true",
                      help='Target language: C.')
  parser.add_argument('--test-c',
                      action="store_true",
                      help='Target language: C tests.')
  parser.add_argument('--c-sources',
                      action="store_true",
                      help='Target language: C sources.')
  parser.add_argument('--haskell',
                      action="store_true",
                      help='Target language: Haskell.')
  parser.add_argument('--java',
                      action="store_true",
                      help='Target language: Java.')
  parser.add_argument('--test-java',
                      action="store_true",
                      help='Target language: Java tests.')
  parser.add_argument('--rust',
                      action="store_true",
                      help='Target language: Rust.')
  parser.add_argument('--test-rust',
                      action="store_true",
                      help='Target language: Rust tests.')
  parser.add_argument('--latex',
                      action="store_true",
                      help='Target language: LaTeX.')
  parser.add_argument('--protobuf',
                      action="store_true",
                      help='Target language: Protocol Buffers.')
  parser.add_argument('--jsonschema',
                      action="store_true",
                      help='Target language: JSON Schema.')
  parser.add_argument('-r',
                      '--release',
                      nargs=1,
                      required=True,
                      help='Release version.')
  parser.add_argument('-s',
                      '--staging',
                      action="store_true",
                      help='Is a staging branch')
  parser.add_argument('-v',
                      '--verbose',
                      action="store_true",
                      help='Print debugging info.')
  return parser


def parse_release_version(release: str, staging: bool) -> ReleaseVersion:
  major, minor, patch = release.split('.')[:3]
  major = major.lstrip('v')
  if '-' in patch:
    patch = patch.split('-')[0]
    patch_pre = '{}-alpha'.format(int(patch.split('-')[0]) + 1)
    full_version = "{}.{}.{}".format(major, minor, patch_pre)
  else:
    patch_pre = patch
    full_version = "{}.{}.{}".format(major, minor, patch)
  if staging:
    full_version += '-staging'
  return ReleaseVersion(major=major,
                        minor=minor,
                        patch=patch,
                        patch_pre=patch_pre,
                        full_version=full_version,
                        is_staging=int(staging),)

def main():
  try:
    # Parse and validate arguments.
    args = get_args().parse_args()
    verbose = args.verbose
    assert args.jsonschema or args.python or args.javascript or args.c or args.test_c or args.c_sources or args.haskell or args.latex or args.protobuf or args.java or args.test_java or args.rust or args.test_rust, \
        "Please specify a target language."
    input_file = os.path.abspath(args.input_file[0])
    assert len(args.input_file) == 1
    assert os.path.exists(input_file), \
        "Invalid input file: %s. Exiting!" % input_file
    output_dir = os.path.abspath(args.output_dir[0])
    assert len(args.output_dir) == 1, "Only 1 output directory at a time."
    assert os.path.exists(output_dir), \
        "Invalid output directory: %s. Exiting!" % output_dir
    # Ingest, parse, and validate.
    test_mode = args.test_c or args.test_rust or args.test_java

    if test_mode:
      file_index = yaml.resolve_test_deps(*yaml.get_files(input_file))
    else:
      file_index = yaml.resolve_deps(*yaml.get_files(input_file))

    # Sort the files - we need them to be in a stable order for some test generation
    file_index_items = sorted(file_index.items(), key=lambda f: f[0])
    release = parse_release_version(args.release[0], args.staging)
    if verbose:
      print("Reading files...")
      pprint.pprint(list(file_index.keys()))
      print("Writing to %s" % output_dir)
    if args.latex:
      import sbpg.targets.latex as tex
      parsed = [yaml.parse_spec(spec) for spec in file_index.values()]
      tex.render_source(output_dir, parsed, release)
    else:
      spec_no = 0
      all_specs = []
      for fname, spec in file_index_items:
        spec_no = spec_no + 1
        if test_mode:
          parsed = yaml.parse_test_spec(fname, spec, spec_no)
        else:
          parsed = yaml.parse_spec(spec)
        all_specs.append(parsed)
        if not parsed.render_source:
          continue
        if args.python:
          import sbpg.targets.python as py
          py.render_source(output_dir, parsed)
        elif args.javascript:
          import sbpg.targets.javascript as js
          with open(os.path.join(output_dir, "RELEASE-VERSION"), 'w') as ver_file:
              ver_file.write(release.full_version)
          js.render_source(output_dir, parsed)
        elif args.c:
          import sbpg.targets.legacy_c as legacy_c
          legacy_c.render_source(output_dir + "/include/libsbp", parsed)
        elif args.test_c:
          import sbpg.targets.test_legacy_c as test_legacy_c
          test_legacy_c.render_source(output_dir, parsed)
          import sbpg.targets.test_c as test_c
          test_c.render_source(output_dir, parsed)
        elif args.haskell:
          import sbpg.targets.haskell as hs
          hs.render_source(output_dir, parsed)
        elif args.java:
          import sbpg.targets.java as java
          java.render_source(output_dir, parsed)
        elif args.test_java:
          import sbpg.targets.test_java as test_java
          test_java.render_source(output_dir, parsed)
        elif args.test_rust:
          import sbpg.targets.test_rust as test_rs
          test_rs.render_source(output_dir, parsed)
        elif args.protobuf:
          import sbpg.targets.protobuf as pb
          pb.render_source(output_dir, parsed)
        elif args.jsonschema:
          import sbpg.targets.jsonschema as jsonschema
          jsonschema.render_source(output_dir, parsed)
      all_specs = sorted(all_specs)
      if args.c:
        import sbpg.targets.c as c
        c.render_version(output_dir, release)
        parsed = [yaml.parse_spec(spec) for _, spec in file_index_items]
        legacy_c.render_traits(output_dir + "/include/libsbp", parsed)
        c.render_all(output_dir, parsed)
      elif args.python:
        py.render_version(output_dir, release)
      elif args.haskell:
        parsed = [yaml.parse_spec(spec) for spec in file_index.values()]
        hs.render_cabal(output_dir, parsed, release)
        hs.render_sbp(output_dir, parsed)
      elif args.java:
        parsed = [yaml.parse_spec(spec) for _, spec in file_index_items]
        java.render_table(output_dir, parsed)
      elif args.rust:
        import sbpg.targets.rust as rs
        parsed = [yaml.parse_spec(spec) for spec in file_index.values()]
        rs.render_all(output_dir, parsed, release)
      elif args.test_c:
        test_c.render_check_suites(output_dir, all_specs)
        test_c.render_check_main(output_dir, all_specs)
      if args.test_rust:
        import sbpg.targets.test_rust as test_rs
        test_rs.render_main(output_dir, all_specs)


  except KeyboardInterrupt:
    pass


if __name__ == '__main__':
  main()
