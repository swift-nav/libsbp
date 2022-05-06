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
Defines a really basic syntax declaration for a collection of SBP
message tests.

"""

import base64
import json
import os.path

from binascii import unhexlify

import yaml

##############################################################################
#

def _to_unicode(s):
  """Decode the string-like argument to unicode if suitable"""
  return s.decode('utf-8') if hasattr(s, 'decode') else s


class PackageTestSpecification(object):
  """Package is a collection of messages to generate tests for.

  """

  def __init__(self, src_filename=None, package="", suite_no=0, description=None, generated_on=None, tests=None):
    self.src_filename = src_filename
    self.package = package
    self.suite_no = suite_no
    self.description = description
    self.generated_on = generated_on
    self.tests = tests or []
    self.render_source = True

  def __lt__(self, other):
    return (self.package, self.suite_no).__lt__((other.package, other.suite_no))

  @property
  def suite_name(self):
    _, name = self.filepath
    return name

  @property
  def filepath(self):
    # Remove 'test_' and '.yaml'
    test_name_suffix = os.path.basename(self.src_filename)[5:-5]
    split = ("auto_check_" + self.package + "_" + test_name_suffix).split(".")
    filepath, filename = "/".join(split[:-1]), "_".join(split[-2:])
    return (filepath, filename)

  def to_json(self):
    return {
      'description': self.description,
      'generated_on': self.generated_on,
      'package': self.package,
      'tests': [test.to_json() for test in self.tests],
    }

  def write(self, filename, exists_ok=False):
    file_exists = os.path.exists(filename)
    assert exists_ok or not file_exists
    data = self.to_json()
    try:
      with open(filename, "w") as f:
        yaml.dump(data, f)
    except Exception:
      os.remove(filename)

class TestSpecification(object):
  """A message description to generate tests for.
  """

  def __init__(self, raw_packet, msg_type, raw_json, msg, sbp, test_msg_data=None):
    self.raw_packet = raw_packet
    self.raw_json = raw_json
    self.raw_json_obj = json.loads(raw_json)
    self.packet = base64.standard_b64decode(self.raw_packet)
    self.packet_as_byte_array = list(bytearray(self.packet))
    self.msg_type = msg_type
    self.msg = msg
    self.sbp = sbp
    self.test_msg_data = test_msg_data

  @classmethod
  def from_msg(cls, msg_instance, test_msg_data):
    msg = msg_instance
    sbp = {
      "crc": "0x{:X}".format(msg.crc),
      "length": msg.length,
      "msg_type": "0x{:X}".format(msg.msg_type),
      "payload": _to_unicode(base64.standard_b64encode(msg.payload)),
      "preamble": "0x{:X}".format(msg.preamble),
      "sender": "0x{:X}".format(msg.sender),
    }
    return cls(
      _to_unicode(base64.standard_b64encode(msg.to_binary())),
      msg.msg_type,
      msg.to_json(),
      msg,
      sbp,
      test_msg_data=test_msg_data,
    )

  def __repr__(self):
    return "TestSpecification.from_msg({})".format(self.msg)

  def to_json(self):
    return {
      "msg": self.test_msg_data,
      "msg_type": "0x{:X}".format(self.msg_type),
      "raw_json": self.raw_json,
      "raw_packet": self.raw_packet,
      "sbp": self.sbp,
    }

  def __lt__(self, other: "TestSpecification"):
    return self.raw_packet.__lt__(other.raw_packet)

  @property
  def msg_type_name(self):
    return self.msg.get('name', None)

  @property
  def fields(self):
    return self.msg.get('fields', None) or []

  @property
  def fieldskeys(self):
    return sorted(self.msg.get('fields', None) or [])

  @property
  def c_decoded_fields(self):
    fields = self.msg.get('fields', None) or {}
    if 'c_decoded_fields' in self.msg:
      fields.update(self.msg['c_decoded_fields'])
    return fields

  @property
  def c_decoded_fieldskeys(self):
    fields = self.msg.get('fields', None) or {}
    if 'c_decoded_fields' in self.msg:
      fields.update(self.msg['c_decoded_fields'])
    return sorted(fields)


