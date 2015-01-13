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
Generator for Python target.
"""

import jinja2

SIZES = {
  'uint8': 1,
  'uint16': 2,
  'uint32': 4,
  'uint64': 8,
  'int8': 1,
  'int16': 2,
  'int32': 4,
  'int64': 8,
  'float': 4,
  'double': 8,
}

PYSTRUCT_CODE = {
  'uint8': 'B',
  'uint16': 'H',
  'uint32': 'I',
  'uint64': 'Q',
  'int8': 'b',
  'int16': 'h',
  'int32': 'i',
  'int64': 'q',
  'float': 'f',
  'double': 'd',
}

JENV = jinja2.Environment(
    block_start_string = '((*',
    block_end_string = '*))',
    variable_start_string = '(((',
    variable_end_string = ')))',
    comment_start_string = '((=',
    comment_end_string = '=))',
    loader=jinja2.FileSystemLoader("./templates/")
)

ACRONYMS = ['GPS', 'ECEF', 'LLH', 'NED']

def commentify(value):
  """
  Builds a comment.
  """
  return '\n'.join([' * ' + l for l in value.split('\n')[:-1]])

def classnameify(s):
  """
  Makes a classname.
  """
  return ''.join(w if w in ACRONYMS else w.title() for w in s.split('_'))

def pystruct_format(fields):
  """
  Formats for PyStruct.
  """
  return '<' + ''.join(PYSTRUCT_CODE[f['type']] for f in fields)

def render_source():
  """
  """
  pass
