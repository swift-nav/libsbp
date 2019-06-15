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

from voluptuous import Coerce
from voluptuous import Optional
from voluptuous import Schema
from voluptuous import Any
from voluptuous import IsFalse

SBP_EXTENSION = "/*.yaml"

msg = Schema({
  'fields': Any(Schema({ Coerce(str): Coerce(str) }), IsFalse),
  'module': Coerce(str),
  'name': Coerce(str)
})

test = Schema({
  'msg': msg,
  'msg_type': Schema(str),
  'raw_json': Schema(str),
  'raw_packet': Coerce(str),
  'sbp': Schema({ Coerce(str): Coerce(str) }),
})

tests = Schema([test])

test_schema = Schema({
  'package': Schema(str),
  'description': Schema(str),
  'version': Coerce(str),
  'generated_on': Coerce(str),
  'tests': tests
})
