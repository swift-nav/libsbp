#!/usr/bin/python

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
Main executable.
"""

import argparse
import os
import pprint
import sbpg.specs.yaml2 as yaml
import sbpg.targets.c as c
import sbpg.targets.java as java
import sbpg.targets.latex as tex
import sbpg.targets.haskell as hs
import sbpg.targets.python as py

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
  parser.add_argument('--c',
                      action="store_true",
                      help='Target language: C.')
  parser.add_argument('--haskell',
                      action="store_true",
                      help='Target language: Haskell.')
  parser.add_argument('--java',
                      action="store_true",
                      help='Target language: Java!')
  parser.add_argument('--latex',
                      action="store_true",
                      help='Target language: LaTeX.')
  parser.add_argument('-r',
                      '--release',
                      nargs=1,
                      required=True,
                      help='Release version.')
  parser.add_argument('-v',
                      '--verbose',
                      action="store_true",
                      help='Print debugging info.')
  return parser


def main():
  try:
    # Parse and validate arguments.
    args = get_args().parse_args()
    verbose = args.verbose
    assert args.python or args.c or args.haskell or args.latex or args.java, \
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
    file_index = yaml.resolve_deps(*yaml.get_files(input_file))
    if verbose:
      print "Reading files..."
      pprint.pprint(file_index.keys())
      print "Writing to %s" % output_dir
    if args.latex:
      parsed = [yaml.parse_spec(spec) for spec in file_index.values()]
      tex.render_source(output_dir, parsed)
    else:
      for fname, spec in file_index.items():
        parsed = yaml.parse_spec(spec)
        if not parsed.render_source:
          continue
        if args.python:
          py.render_source(output_dir, parsed)
        elif args.c:
          c.render_source(output_dir, parsed)
        elif args.haskell:
          hs.render_source(output_dir, parsed)
        elif args.java:
          java.render_source(output_dir, parsed)
      if args.c:
        c.render_version(output_dir, args.release[0])
      elif args.haskell:
        parsed = [yaml.parse_spec(spec) for spec in file_index.values()]
        hs.render_cabal(output_dir, parsed, args.release[0])
        hs.render_sbp(output_dir, parsed)
      elif args.java:
        parsed = [yaml.parse_spec(spec) for spec in file_index.values()]
        java.render_table(output_dir, parsed)
  except KeyboardInterrupt:
    pass

if __name__ == '__main__':
  main()
