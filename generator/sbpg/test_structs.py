#!/usr/bin/env python

# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Joshua Gross <josh@swiftnav.com>
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

import datetime
import json
import base64
from binascii import unhexlify

##############################################################################
#

class PackageTestSpecification(object):
  """Package is a collection of messages to generate tests for.

  """

  def __init__(self, src_filename=None, package="", suite_no=0, description=None, generated_on=None, tests=[]):
    self.src_filename = src_filename
    self.package = package
    self.suite_no = suite_no
    self.description = description
    self.generated_on = generated_on
    self.tests = tests
    self.render_source = True


  @property
  def suite_name(self):
    _, name = self.filepath
    return name

  @property
  def filepath(self):
    split = ("auto_check_" + self.package + "_" + str(self.suite_no)).split(".")
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

  @property
  def msg_type_name(self):
    return self.msg.get('name', None)

  @property
  def fields(self):
    return self.msg.get('fields', None) or []

  @property
  def fieldskeys(self):
    return sorted(self.msg.get('fields', None) or [])

