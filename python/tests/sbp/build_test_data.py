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
Command line utility for reading an SBP log and generating
YAML-formatted unit test data. This largely samples a set messages
from a existing log, gathers them by module, formats them to YAML, and
writes them out to files.

Running this command from the top level,

  python tests/sbp/build_test_data.py --log_file <log_file>,

produces <module_name>/test_<message_name>.yaml files in directory the command is
written. The produced file looks like:

description: Unit tests for swiftnav.sbp.acquisition v0.23.
generated_on: 2015-03-22 17:40:06.567183
package: sbp.acquisition
tests:
- msg:
    fields:
      cf: 8241.943359375
      cp: 727.0
      prn: 8
      snr: 14.5
    module: sbp.acquisition
    name: MsgAcqResult
  msg_type: '0x15'
  raw_json: '{"sender": 1219, "msg_type": 21, "prn": 8, "cf": 8241.943359375, "crc":
    17410, "length": 13, "snr": 14.5, "cp": 727.0, "preamble": 85, "payload": "AABoQQDANUTGxwBGCA=="}'
  raw_packet: VRUAwwQNAABoQQDANUTGxwBGCAJE
  sbp:
    crc: '0x4402'
    length: 13
    msg_type: '0x15'
    payload: AABoQQDANUTGxwBGCA==
    preamble: '0x55'
    sender: '0x4c3'

For the sake of readability, some of the fields that are typically
displayed as hex, such as SBP message type, crc, and preamble are cast
into hex strings.

"""

import sbp
from sbp.table import _SBP_TABLE
from sbp.utils import walk_json_dict
import base64
import datetime
import warnings
import os
from ruamel.yaml import YAML

yaml = YAML(typ='safe')

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

def dump_modules_to_yaml(test_map, version):
  """
  Take unit test data data from test, format as YAML, and write to
  local files. Each file is stored in a directory structure consisting
  of components of its package name, 
  e.g. sbp/acquisition/test_MsgAcqResult.yaml

  Parameters
  ----------
  test_map : dict
    Dictionary mapping SBP message name to instances of SBP object to be used
    for making unit test cases.

  """
  for k, v in test_map.iteritems():
    if not v:
      continue
    package = v[0]['msg']['module']
    item = {'package': package,
            'description': "Unit tests for swiftnav.%s %s v%s." % (package, k, version),
            'generated_on': datetime.datetime.now(),
            'version': version,
            'tests': v}
    d = yaml.dump(item, explicit_start=True,
                  default_flow_style=False,
                  explicit_end=True)

    path = ""
    components = package.split(".")
    for component in components:
      path = os.path.join(path, component)
      if not os.path.isdir(path):
        os.makedirs(path)


    filename = "test_"+k+".yaml"
    filepath = os.path.join(path, filename)
    with open(filepath, 'w') as f:
      f.write(d.replace('\n- ', '\n\n- '))

def mk_readable_msg(msg):
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
  f = walk_json_dict(dict([(k, getattr(msg, k)) for k in msg.__slots__]))
  # Message includes fields from the SBP message it inherits from, so
  # remove those.
  i = {'raw_packet' : base64.standard_b64encode(msg.pack()),
       'raw_json'   : msg.to_json(),
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
  parser.add_argument("-p", "--pickle",
                      action="store_true",
                      help="use legacy pickle log functionality.")
  parser.add_argument("-s", "--version",
                      default=[None], nargs=1,
                      help="SBP version number (e.g. 0.29).")
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
  version = args.version[0]
  pickle = args.pickle
  verbose = args.verbose
  if pickle:
    from sbp.client.loggers.pickle_logger import PickleLogIterator as Iterator
  else:
    from sbp.client.loggers.json_logger import JSONLogIterator as Iterator
  if verbose:
    assert False, "Verbose output not implemented yet."
  # Build
  num_test_cases = 5
  message_table = _SBP_TABLE
  test_table = dict((k, []) for (k, v) in message_table.copy().iteritems())
  with Iterator(log_datafile) as log:
    for msg, metadata in log.next():
      try:
        i = mk_readable_msg(msg)
      except TypeError as ex_info:
        # Note data errors as they come up, but don't crash the test
        # generation.
        out = "Warning! %s for message 0x00%x." \
              % (ex_info.message, msg.msg_type)
        warnings.warn(out, RuntimeWarning)
        continue
      # For a given SBP message type, sample only num_test_cases
      # hopefully unique cases. Assume that messages that are likely
      # to be identical are consecutive, so coompare any new message
      # with the most recent one.
      name = i['msg']['name']
      if not name in test_table:
        test_table[name] = [i];      
      elif len(test_table[name]) < num_test_cases and test_table[name][-1] != i:
        test_table[name].append(i)
  dump_modules_to_yaml(test_table, version)

if __name__ == "__main__":
  main()
