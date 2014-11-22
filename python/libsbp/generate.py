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

import jinja2
from libsbp.nav_types import *
import yaml

SIZES = {
  'u8': 1,
  'u16': 2,
  'u32': 4,
  'u64': 8,
  's8': 1,
  's16': 2,
  's32': 4,
  's64': 8,
  'float': 4,
  'double': 8,
}

PYSTRUCT_CODE = {
  'u8': 'B',
  'u16': 'H',
  'u32': 'I',
  'u64': 'Q',
  's8': 'b',
  's16': 'h',
  's32': 'i',
  's64': 'q',
  'float': 'f',
  'double': 'd',
}

COMPLEX_PYSTRUCT_CODE = {
  'latency_t': lambda d: Latency(d),
  'carrier_phase_t': lambda d: CarrierPhase(d),
  'uart_state_t': lambda d: UARTState(d),
  'gps_time_t': lambda d: GPSTime
}

ACRONYMS = ['GPS', 'ECEF', 'LLH', 'NED']

JENV = jinja2.Environment(
    block_start_string = '((*',
    block_end_string = '*))',
    variable_start_string = '(((',
    variable_end_string = ')))',
    comment_start_string = '((=',
    comment_end_string = '=))',
    loader=jinja2.FileSystemLoader("./templates/")
)

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

JENV.filters['commentify'] = commentify
JENV.filters['classnameify'] = classnameify
JENV.filters['pystruct'] = pystruct_format

def rejig_values(values):
  """
  Rejigs
  """
  new_values = []
  for v in values:
    value, desc = v.iteritems().next()
    new_values.append({'value': value, 'desc': desc})
    return new_values

def rejig_bitfields(bfs):
  """
  Rejigs some more.
  """
  new_bfs = []
  n_with_values = 0
  for bf in bfs:
    rng, info = bf.iteritems().next()
    if 'values' in info:
      n_with_values += 1
      info['vals'] = rejig_values(info['values'])
      del info['values']
    rng = map(int, str(rng).split('-'))
    if len(rng) == 1:
      lsb = rng[0]
      bf_len = 1
    else:
      lsb, msb = rng
      bf_len = msb + 1 - lsb
      rng = ':'.join(map(str, rng))
      new_bfs.append(dict(info, **{
        'lsb': lsb,
        'range': rng,
        'len': bf_len,
      }))
  return new_bfs, n_with_values

def render(spec_filename, template_filename, destination_filename):
  """
  Render a Python class given a specification.

  Parameters
  ----------
  sock : socket
    Open network socket
  msg : str
    Command string

  Returns
  ----------
  """
  ds = None
  with open(spec_filename, 'r') as f:
    ds = yaml.load(f)
  msgs = [[dict({'name': k}, **v) for k, v in d.iteritems()][0] for d in ds]
  for m in msgs:
    fields = []
    offset = 0
    max_type_len = 0
    max_name_len = 0
    if 'fields' in m:
      for f in m['fields']:
        name, info = f.iteritems().next()
        if not 'units' in info:
          info.update({'units': ''})
        info['n_with_values'] = 0
        if 'fields' in info:
          info['fields'], info['n_with_values'] = rejig_bitfields(info['fields'])
        fields.append(dict(info, **{
          'name': name,
          'offset': offset,
          'size': SIZES[info['type']],
         }))
      offset += SIZES[info['type']]
      max_type_len = max(max_type_len, len(info['type']))
      max_name_len = max(max_name_len, len(name))
    m['max_type_len'] = max_type_len
    m['max_name_len'] = max_name_len
    m['fields'] = fields
    m['size'] = offset
  py_template = JENV.get_template(template_filename)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(msgs=msgs))

if __name__ == "__main__":
  spec = "../spec/piksi.yaml"
  template = "sbp_messages_template.py.j2"
  destination = "./libsbp/piksi_messages.py"
  render(spec, template, destination)
  spec = "../spec/standard.yaml"
  destination = "./libsbp/nav_messages.py"
  #render(spec, template, destination)
