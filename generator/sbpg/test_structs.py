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

##############################################################################
#

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


class TestSpecification(object):
  """Package is a collection of messages to generate tests for.

  """

  def __init__(self, raw_packet, msg_type, raw_json, msg, sbp):
    self.raw_packet = raw_packet
    self.raw_json = raw_json
    self.raw_json_obj = json.loads(raw_json)
    self.packet = base64.standard_b64decode(self.raw_packet)
    self.packet_as_byte_array = list(bytearray(self.packet))
    self.msg_type = msg_type
    self.msg = msg
    self.sbp = sbp

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

