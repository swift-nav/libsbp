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
import sbp.targets.c as c
import sbp.targets.python as py
import sbp.specs.yaml2 as yaml


def get_args():
  parser = argparse.ArgumentParser(description='Swift Nav SBP generator.')
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
    assert args.python or args.c, "Please specify a target language."
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
    exit()
    for fname, spec in file_index.items():
      if args.python:
        py.render_source(output_dir, yaml.parse_spec(spec))
      elif args.c:
        c.render_source(output_dir, yaml.parse_spec(spec))
  except KeyboardInterrupt:
    pass

if __name__ == '__main__':
  main()
