#!/usr/bin/env python
# Copyright (C) 2015-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from voluptuous import Any, Coerce, IsFalse, Schema

SBP_EXTENSION = "/*.yaml"

msg = Schema({
  'fields': Any(Schema({ Coerce(str): Coerce(str) }), IsFalse),
  'c_decoded_fields': Any(Schema({ Coerce(str): Coerce(str) }), IsFalse),
  'c_string_fields': Any(Schema({ Coerce(str): Coerce(str) }), IsFalse),
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

struct_test = Schema({
    'encoded': Coerce(str),
    'fields': Any(Schema({ Coerce(str): Coerce(str) }), IsFalse),
    'c_decoded_fields': Any(Schema({ Coerce(str): Coerce(str) }), IsFalse),
    'module': Coerce(str),
    'name': Coerce(str)
})

tests = Schema([test])
struct_tests = Schema([struct_test])

test_schema = Schema({
  'package': Schema(str),
  'description': Schema(str),
  'version': Coerce(str),
  'generated_on': Coerce(str),
  'tests': tests,
  'struct_tests': struct_tests
})
