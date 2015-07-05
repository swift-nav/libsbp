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
Utilities for running YAML-defined unit tests.
"""

from sbp.msg import SBP
from sbp.table import dispatch, _SBP_TABLE
import base64
import json
import yaml

def _assert_sbp(sbp, test_case):
  """
  Assert that a proper SBP parsing from a raw package of data.

  Parameters
  ----------
  sbp : :class: `SBP`
    SBP message parsed from unit test's raw packet.
  test_case : dict
    Unit test case parsed from YAML.

  """
  assert sbp.crc == int(test_case['crc'], 0), "Invalid crc."
  assert sbp.msg_type == int(test_case['msg_type'], 0), "Invalid msg_type."
  assert sbp.sender == int(test_case['sender'], 0), "Invalid sender."
  assert sbp.length == test_case['length'], "Invalid length."
  assert base64.standard_b64encode(sbp.payload) == test_case['payload'], \
    "Invalid payload."

def field_eq(p, e):
  """
  Checks the field values of a parsed message for equality against
  some ground truth value.

  Parameters
  ----------
  p : object with dict-like attributed access
    Parsed field contents.
  e : object with dict-like attributed access
    Expected field contents.

  Returns
  ----------
  True if fields are equal, else False.

  """
  if isinstance(e, dict):
    return all(field_eq(p[i], j) for (i, j) in e.iteritems())
  elif isinstance(e, list):
    return all(field_eq(p[i], j) for (i, j) in enumerate(e))
  else:
    return p == e

def _assert_msg(msg, test_case):
  """
  Asserts that the parsed payload of an SBP message has the expected
  field values.

  Parameters
  ----------
  msg : Parsed SBP message.
    Parsed SBP message.
  test_case : dict
    Unit test case for this message.

  """
  assert msg.__class__.__name__ == test_case['name']
  if test_case['fields']:
    for field_name, field_value in test_case['fields'].iteritems():
      assert field_eq(getattr(msg, field_name), field_value), \
        "Unequal field values: got %s, but expected %s!" \
        % (getattr(msg, field_name), field_value)

def _assert_msg_roundtrip(msg, raw_packet):
  """
  Asserts that a msg gets serialized back into binary with the
  expected value.

  Parameters
  ----------
  msg : Parsed SBP message.
    Parsed SBP message.
  raw_packet : dict
    Unit test case for this message.

  """
  assert base64.standard_b64encode(msg.to_binary()) == raw_packet

def _assert_msg_roundtrip_json(msg, raw_json):
  """
  Asserts that a msg gets serialized back into JSON with the
  expected value, as well as gets serialized from JSON into
  an expected object.
  """
  assert json.loads(msg.to_json()) == json.loads(raw_json)
  assert msg == msg.from_json(raw_json)

def _assert_materialization(msg, sbp, raw_json):
  """Asserts that a message materialized will get serialized into the
  right JSON object.

  """
  fields = msg['fields']
  fields.update({'sender': sbp.sender})
  live_msg = _SBP_TABLE[sbp.msg_type](**fields)
  assert isinstance(live_msg.to_json_dict(), dict)
  assert live_msg.to_json_dict() == json.loads(raw_json)

def _assert_sane_package(pkg_name, pkg):
  """
  Sanity check the package collection of tests before actually
  running the tests.

  Parameters
  ----------
  pkg_name : str
    Name of package to test
  pkg : dict
    Parsed contents of YAML file.

  """
  assert pkg_name in pkg['description'], "Not the right package!"
  assert pkg_name in pkg['package'], "Not the right package!"
  assert len(pkg['tests']) > 0, "Package has no tests!"

def assert_package(test_filename, pkg_name):
  """
  Runs unit tests for message bindings by reading a YAML unit test
  specification, parsing a raw packet for each test, and then
  asserting that SBP messages and parsed payloads have their intended
  values.

  Parameters
  ----------
  test_filename : str
    Filepath to unit test specifications
  pkg_name : str
    Name of package to test

  """
  with open(test_filename, 'r') as f:
    pkg = yaml.load(f.read())
    _assert_sane_package(pkg_name, pkg)
    for test_case in pkg['tests']:
      sbp = SBP.unpack(base64.standard_b64decode(test_case['raw_packet']))
      _assert_sbp(sbp, test_case['sbp'])
      _assert_msg(dispatch(sbp), test_case['msg'])
      _assert_msg_roundtrip(dispatch(sbp), test_case['raw_packet'])
      _assert_msg_roundtrip_json(dispatch(sbp), test_case['raw_json'])
      _assert_materialization(test_case['msg'], sbp, test_case['raw_json'])
