#!/usr/bin/env python
# Copyright (C) 2019-2021 Swift Navigation Inc.
# Contact: Swift NAvigation <dev@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
Generator for rust tests target.
"""

import re

from sbpg.targets.common import array_type, dict_type, float_type, is_empty, string_type, to_str
from sbpg.targets.templating import JENV
from sbpg.targets.rust import lower_acronyms, snake_case

TEST_TEMPLATE_NAME = "rust/test/sbp_tests_template.rs"
TEST_MAIN_TEMPLATE_NAME = "rust/test/sbp_tests_main_template.rs"

def str_escape(value):
    return "\"{}\".to_string()".format(value)

def mod_name(value):
    return value.split('.')[1]

JENV.filters['to_str'] = to_str
JENV.filters['str_escape'] = str_escape
JENV.filters['sorted'] = sorted
JENV.filters['mod_name'] = mod_name
JENV.filters['lower_acronyms'] = lower_acronyms
JENV.filters['snake_case'] = snake_case

JENV.tests['string_type'] = string_type
JENV.tests['array_type'] = array_type
JENV.tests['dict_type'] = dict_type
JENV.tests['float_type'] = float_type
JENV.tests['empty'] = is_empty

def render_source(output_dir, package_spec):
  """
  Render and output to a directory given a package specification.
  """
  path, name = package_spec.filepath
  destination_filename = "%s/integration/%s.rs" % (output_dir, snake_case(name))
  py_template = JENV.get_template(TEST_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(s=package_spec,
                               description=package_spec.description,
                               pkg_name=package_spec.package,
                               include=package_spec.package.split('.')[1],
                               filepath="/".join(package_spec.filepath) + ".yaml"))

def render_main(output_dir, package_specs):
  destination_filename = "%s/integration/main.rs" % output_dir
  py_template = JENV.get_template(TEST_MAIN_TEMPLATE_NAME)
  test_names = [snake_case(p.filepath[1]) for p in package_specs]
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(test_names=test_names))
