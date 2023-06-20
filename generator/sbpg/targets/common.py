#!/usr/bin/env python
# Copyright (C) 2019-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import base64
import re
import json

def string_type(value):
    return type(value) == str

def array_type(value):
    return type(value) == list

def dict_type(value):
    return type(value) == dict

def float_type(value):
    return type(value) == float

def is_empty(value):
    return len(value) == 0

def to_str(value):
    return str(value)

def b64_decode(field):
    return base64.standard_b64decode(field)

# convert CamelCase to snake_case
def snake_case(s):
    if "_" in s:
        return "_".join(snake_case(p) for p in s.split("_"))
    if len(s) == 1:
        return s.lower()
    s = re.sub("(.)([A-Z][a-z]+)", r"\1_\2", s)
    return re.sub("([a-z0-9])([A-Z])", r"\1_\2", s).lower()

# convert snake_case to CamelCase
def camel_case(s):
    s = re.sub("([a-z])([A-Z])", r"\1_\2", s)
    return "".join(w.title() for w in s.split("_"))

# convert all keys in a dict to snake_case
def snake_case_keys(x):
    if isinstance(x, list):
        return [snake_case_keys(v) for v in x]
    elif isinstance(x, dict):
        return dict((snake_case(k), snake_case_keys(v)) for k, v in x.items())
    else:
        return x

# convert JSON to dict
def decode_json(x):
    return json.loads(x)

# Convert dict to canonical JSON representation
def encode_json(x):
    return json.dumps(x, allow_nan=False, sort_keys=True, separators=(',', ':'))

# escape non-printable characters
def str_escape(x):
    return repr(x)[1:-1]
