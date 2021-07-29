#!/usr/bin/env python
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
Utilities for running YAML-defined unit tests.
"""

import base64
import os.path
import json
import sys
import unittest

import yaml

from sbp.msg import SBP
from sbp.table import dispatch, _SBP_TABLE

HERE = os.path.dirname(__file__)
PYTHON_ROOT = os.path.join(HERE, "..", "..")
SPEC_ROOT = os.path.join(PYTHON_ROOT, "..", "spec", "yaml", "swiftnav", "sbp")
_SPECS = {}

def flatten_array(a):
  """Return a mapping from a yaml array of mappings."""
  return dict((next(iter(item.keys())), item[next(iter(item.keys()))]) for item in a)

def load_msg_field_classes(msg):
  """Return a mapping of msg field names to custom classes."""
  # any_case is only available on Python 3.6+
  try:
    from any_case import to_snake_case
  except ImportError:
    return {}

  module_name = msg.__class__.__module__
  msg_name = msg.__class__.__name__
  if module_name not in _SPECS:
    sbp_module_name = module_name.rsplit(".", 1)[-1]
    module_filename = os.path.join(SPEC_ROOT, sbp_module_name + ".yaml")
    if not os.path.exists(module_filename):
      raise RuntimeError(module_filename, msg)
    with open(module_filename) as f:
      _SPECS[module_name] = yaml.load(f.read(), Loader=yaml.FullLoader)
  definitions = flatten_array(_SPECS[module_name]["definitions"])
  msg_key = to_snake_case(msg_name).upper()
  obj_fields = flatten_array(definitions[msg_key]["fields"])
  field_classes = {}
  for field_name, field in obj_fields.items():
    if field["type"] in definitions:
      mod = sys.modules[module_name]
      cls = getattr(mod, field["type"])
      field_classes[field_name] = cls

  return field_classes

def _encoded_string(s):
  """Encode the string-like argument as bytes if suitable"""
  return s.encode('ascii') if hasattr(s, 'encode') else s

def _assert_unsorted_equal(a, b):
  """
  Perform unittest.TestCase.assertCountEqual.
  """
  # pytest does not have a similar feature
  # https://github.com/pytest-dev/pytest/issues/5548
  # This is intentionally inside the function so that it is not collected as a test class
  class UnitTestCase(unittest.TestCase):
    def runTest(self):
      pass
    if not hasattr(unittest.TestCase, "assertCountEqual"):
      def assertCountEqual(self, *args, **kw):
        return self.assertItemsEqual(*args, **kw)  # pylint: disable=no-member
  case = UnitTestCase()
  case.assertCountEqual(a, b)

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
  assert base64.standard_b64encode(sbp.payload) == _encoded_string(test_case['payload']), \
    "Invalid payload."

def deep_encode(e, encoding='ascii'):
  """
  Encodes all strings using encoding, default ascii.
  """
  if isinstance(e, dict):
    return dict((i, deep_encode(j, encoding)) for (i, j) in e.items())
  elif isinstance(e, list):
    return [deep_encode(i, encoding) for i in e]
  elif isinstance(e, str):
    e = e.encode(encoding)
  return e

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
    return all(field_eq(p[i], j) for (i, j) in iter(e.items()))
  elif isinstance(e, list):
    return all(field_eq(p[i], j) for (i, j) in enumerate(e))
  elif isinstance(e, str) and isinstance(p, bytes) and p.endswith(b'\x00'):
    e = e.encode('ascii')
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
  assert msg.__class__.__name__ == test_case['name'], (
    "test case name {} loaded class name {}".format(test_case['name'], msg.__class__.__name__))
  if test_case['fields']:
    for field_name, field_value in test_case['fields'].items():
      assert field_eq(getattr(msg, field_name), _encoded_string(field_value)), \
        "Unequal field values (name: %s): got %r, but expected %r!" \
        % (field_name, getattr(msg, field_name), field_value)

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
  encoding = base64.standard_b64encode(msg.to_binary())
  assert encoding == _encoded_string(raw_packet)

def _assert_msg_roundtrip_json(msg, raw_json):
  """
  Asserts that a msg gets serialized back into JSON with the
  expected value, as well as gets serialized from JSON into
  an expected object.
  """
  to_json = json.loads(msg.to_json())
  from_json = json.loads(raw_json)
  assert sorted(to_json.items()) == sorted(from_json.items())
  assert msg == msg.from_json(raw_json)

def _assert_materialization(msg, sbp, raw_json):
  """Asserts that a message materialized will get serialized into the
  right JSON object.

  """
  fields = msg['fields'] or dict()
  live_msg = _SBP_TABLE[sbp.msg_type](sbp, **fields)
  assert isinstance(live_msg.to_json_dict(), dict)
  assert live_msg.to_json_dict() == json.loads(raw_json)

  fields = deep_encode(fields)
  live_msg = _SBP_TABLE[sbp.msg_type](sbp=None, **fields)
  assert isinstance(live_msg.to_json_dict(), dict)
  assert sorted(live_msg.to_json_dict().keys()) == sorted(live_msg.to_json_dict().keys())
  _assert_unsorted_equal(live_msg.to_json_dict(), live_msg.to_json_dict())

  assert msg['module']
  assert msg['name']

  # Locate the classes for any fields that use one from the same
  # module as the test case
  if not fields:
    return
  field_class_map = load_msg_field_classes(live_msg)
  if not field_class_map:
    return

  # Instantiate fields as classes and then instantiate msg using those objects
  member_fields = {}
  for name, value in fields.items():
    if name in field_class_map:
      assert isinstance(value, dict)
      member_fields[name] = field_class_map[name](sbp=None, **value)
    else:
      member_fields[name] = value
  live_msg = _SBP_TABLE[sbp.msg_type](sbp=None, **member_fields)
  _assert_unsorted_equal(live_msg.to_json_dict(), json.loads(raw_json))

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
  assert len(pkg['tests']) > 0, "Package has no tests!"

def load_test_package(test_filename):
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
  pkg_name = os.path.basename(test_filename)
  with open(test_filename, 'r') as f:
    pkg = yaml.load(f.read(), Loader=yaml.FullLoader)
    try:
      _assert_sane_package(pkg_name, pkg)
    except Exception as e:
      raise RuntimeError("Loading {} failed: {}".format(test_filename, e))
    return pkg

def assert_package(test_filename):
    pkg = load_test_package(test_filename)
    for test_case in pkg['tests']:
      sbp = SBP.unpack(base64.standard_b64decode(test_case['raw_packet']))
      _assert_sbp(sbp, test_case['sbp'])
      _assert_msg(dispatch(sbp), test_case['msg'])
      _assert_msg_roundtrip(dispatch(sbp), test_case['raw_packet'])
      _assert_msg_roundtrip_json(dispatch(sbp), test_case['raw_json'])
      _assert_materialization(test_case['msg'], sbp, test_case['raw_json'])
