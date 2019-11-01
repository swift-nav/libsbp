#!/usr/bin/env python
# Copyright (C) 2019 Swift Navigation Inc.
# Contact: Swift Navigation <dev@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

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

