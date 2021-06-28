#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
Generator for c tests target.
"""

from sbpg.targets.legacy_c import convert
from sbpg.targets.common import array_type, dict_type, float_type, is_empty, string_type, to_str
from sbpg.targets.templating import JENV

TEST_TEMPLATE_NAME = "c/test/legacy/sbp_c_test.c.j2"
CPP_TEST_TEMPLATE_NAME = "c/test/legacy/sbp_cpp_test.cc.j2"

def str_escape(value):
    return ",".join(["(char)" + str(ord(ch)) for ch in value])

JENV.filters['str_escape'] = str_escape
JENV.filters['to_str'] = to_str
JENV.filters['sorted'] = sorted
JENV.filters['convert'] = convert

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
  destination_filename = "%s/legacy/%s.c" % (output_dir, name)
  py_template = JENV.get_template(TEST_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(s=package_spec,
                               description=package_spec.description,
                               pkg_name=package_spec.package,
                               include=package_spec.package.split('.')[1],
                               filepath="/".join(package_spec.filepath) + ".yaml"))
  destination_filename = "%s/legacy/cpp/%s.cc" % (output_dir, name)
  py_template = JENV.get_template(CPP_TEST_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(s=package_spec,
                               description=package_spec.description,
                               pkg_name=package_spec.package,
                               include=package_spec.package.split('.')[1],
                               filepath="/".join(package_spec.filepath) + ".yaml"))
