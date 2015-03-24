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
Command line utility for reading an SBP log and generating somes
YAML-formatted unit test data. This largely samples a set messages
from a existing log, gathers them by module, formats them to YAML, and
writes them out to files.

Running this command from the top level,

  python tests/sbp/build_test_data.py --log_file <log_file>,

will produce test_<module name>.yaml files in directory the command is
written. The produced file looks like:

description: Unit tests for swiftnav.sbp.acquisition v.0.23.
generated_on: 2015-03-22 17:40:06.567183
package: sbp.acquisition
tests:
- msg:
    fields:
      cf: -7742.43212890625
      cp: 272.0
      prn: 24
      snr: 18.77777862548828
    module: sbp.acquisition
    name: MsgAcqResult
  msg_type: '0x15'
  raw_packet: VRUAzAQN5DiWQQAAiEN18/HFGLWs
  sbp:
    crc: '0xacb5'
    length: 13
    msg_type: '0x15'
    payload: 5DiWQQAAiEN18/HFGA==
    preamble: '0x55'
    sender: '0x4cc'

For the sake of readability, some of the fields that are typically
displayed as hex, such as SBP message type, crc, and preamble are cast
as into hex strings.

"""

from sbp.table import _SBP_TABLE
from sbp.client.loggers.pickle_logger import PickleLogIterator
import base64
import datetime
import sbp
import warnings
import yaml

def _to_readable_dict(msg):
  """
  Format an SBP message's attributes for a preferred YAML output.

  Parameters
  ----------
  msg : :class: `SBP`
    A parsed SBP message.

  Returns
  ----------
  dict

  """
  return {'preamble': hex(msg.preamble),
          'msg_type': hex(msg.msg_type),
          'sender': hex(msg.sender),
          'length': msg.length,
          'payload': base64.standard_b64encode(msg.payload),
          'crc': hex(msg.crc)}

def walk_json_dict(coll):
  """
  Flatten a parsed SBP object into a dicts and lists, which are
  compatible for YAML output.

  Parameters
  ----------
  test_map : dict

  """
  if isinstance(coll, dict):
    return dict((k, walk_json_dict(v)) for (k, v) in coll.iteritems())
  elif hasattr(coll, '__iter__'):
    return [walk_json_dict(dict(seq.items())) for seq in coll]
  else:
    return coll

def dump_modules_to_yaml(test_map):
  """
  Take unit test data data from test, format as YAML, and write to
  local files.

  Parameters
  ----------
  test_map : dict
    Dictionary mapping SBP message type to instances of SBP object to be used
    for making unit test cases.

  """
  for k, v in test_map.iteritems():
    item = {'package': k,
            'description': "Unit tests for swiftnav.%s v.%s." \
              % (k, sbp.__version__),
            'generated_on': datetime.datetime.now(),
            'version': sbp.__version__,
            'tests': v}
    d = yaml.dump(item, explicit_start=True,
                  default_flow_style=False,
                  explicit_end=True)
    filename = "test_"+k.split(".")[-1]+".yaml"
    with open(filename, 'w') as f:
      f.write(d.replace('\n- ', '\n\n- '))

def gather_by_module(test_table):
  """
  Join accumulated unit test data by module.

  Parameters
  ----------
  test_map : dict
    A dict mapping an SBP message type to a list of parsed SBP
    objects.

  Returns
  ----------
  A dict mapping an SBP module to a list of parsed SBP objects.

  """
  output = {}
  for k, v in test_table.iteritems():
    if not v:
      continue
    module = v[0]['msg']['module']
    if output.get(module, None):
      output[module] += v
    else:
      output[module] = v
  return output

_TO_REMOVE=['preamble', 'msg_type', 'sender', 'length', 'payload', 'crc']

def mk_readable_msg(msg, keys=_TO_REMOVE):
  """
  Produces a unit test case from a parsed SBP message. The case
  includes the raw output, the SBP message with unparsed payload, and
  the parsed SBP message

  Parameters
  ----------
  msg : Subclass of :class: `SBP`.
    Parsed SBP message.
  keys : list
    List of keys to remove from the rendered

  Returns
  ----------
  A dict formatted for a unit test case.

  """
  f = walk_json_dict(msg.__dict__)
  # Message includes fields from the SBP message it inherits from, so
  # remove those.
  for k in keys:
    del f[k]
  i = {'raw_packet' : base64.standard_b64encode(msg.pack()),
       'msg_type'   : hex(msg.msg_type),
       'sbp'        : _to_readable_dict(msg),
       'msg'        : { 'module' : msg.__class__.__module__,
                        'name' : msg.__class__.__name__,
                        'fields' : f if f else None}}
  return i

def get_args():
  """
  Get and parse command line arguments.
  """
  import argparse
  parser = argparse.ArgumentParser(description="Swift Navigation SBP Client.")
  parser.add_argument("-l", "--log_file",
                      default=[None], nargs=1,
                      help="use input file to read SBP messages from.")
  parser.add_argument("-j", "--json",
                      action="store_true",
                      help="JSON serialize SBP messages.")
  parser.add_argument("-v", "--verbose",
                      action="store_true",
                      help="print extra debugging information.")
  return parser.parse_args()

def main():
  """
  Get command line configuration, read log data, and write out
  YAML-formatted unit test data.

  """
  args = get_args()
  log_datafile = args.log_file[0]
  json = args.json
  verbose = args.verbose
  if json:
    assert False, "JSON formatted log input not implemented yet."
  if verbose:
    assert False, "Verbose output not implemented yet."
  # Build
  num_test_cases = 5
  message_table = _SBP_TABLE
  test_table = dict((k, []) for (k, v) in message_table.copy().iteritems())
  with open(log_datafile, 'r+') as f:
    with PickleLogIterator(f) as log:
      for delta, timestamp, msg in log.next():
        try:
          i = mk_readable_msg(msg)
        except TypeError as ex_info:
          # Note data errors as they come up, but don't crash the test
          # generation.
          out = "Warning! %s for message 0x00%x." % (ex_info.message, msg.msg_type)
          warnings.warn(out, RuntimeWarning)
          continue
        # For a given SBP message type, sample only num_test_cases
        # hopefully unique cases. Assume that messages that are likely
        # to be identical are consecutive, so coompare any new message
        # with the most recent one.
        if len(test_table[msg.msg_type]) <= num_test_cases:
          if len(test_table[msg.msg_type]) == 0:
            test_table[msg.msg_type].append(i)
          elif test_table[msg.msg_type][-1] != i:
            test_table[msg.msg_type].append(i)
  dump_modules_to_yaml(gather_by_module(test_table))

if __name__ == "__main__":
  main()
