#!/usr/bin/env python
# Copyright (C) 2011-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
Define some basic data shape schema on Python dictionaries parsed
from Yaml.

"""

from voluptuous import Coerce
from voluptuous import Optional
from voluptuous import Schema

SBP_EXTENSION = "/*.yaml"

filename = Schema(str)
identifier = Coerce(str)
description = Schema(str)
include = Schema([filename])
bit = Coerce(int)
type_identifier = Schema(str)
sbp_identifier = Schema(int)
units = Coerce(str)
bitmask = Coerce(str)
size = Schema(int)
encoding = Schema(str)

bitfield = Schema([{Optional(bitmask):
                           {Optional('units'): units,
                            Optional('values'): [{bit: description}],
                            Optional('desc'): description}}])
field = Schema({identifier:
                {Optional('units'): units,
                 'type': type_identifier,
                 Optional('desc'): description,
                 Optional('map_by'): identifier,
                 Optional('fill'): identifier,
                 Optional('size'): size,
                 Optional('encoding'): encoding,
                 Optional('size_fn'): identifier,
                 Optional('fields'): bitfield}})
definition = Schema({identifier:
                     {Optional('id'): sbp_identifier,
                      Optional('friendly_name'): description,
                      Optional('short_desc'): description,
                      Optional('desc'): description,
                      Optional('replaced_by'): [identifier],
                      Optional('public'): bool,
                      Optional('size'): size,
                      Optional('type'): type_identifier,
                      Optional('embedded_type'): bool,
                      Optional('fields'): [field]}})
package_schema = Schema({Optional('package'): identifier,
                         Optional('description'): description,
                         Optional('render_source'): bool,
                         Optional('stable'): bool,
                         Optional('public'): bool,
                         Optional('include'): include,
                         Optional('definitions'): [definition]})
