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
Generator for java tests target.
"""

from sbpg.targets.common import array_type, b64_decode, dict_type, float_type, is_empty, string_type, to_str
from sbpg.targets.templating import JENV

TEST_TEMPLATE_NAME = "MessageTest.java.j2"

def str_escape(value):
    return "\"{}\"".format(value.replace("\n", r"\n"))

JENV.filters['b64_decode'] = b64_decode

JENV.filters['to_str'] = to_str
JENV.filters['str_escape'] = str_escape
JENV.filters['sorted'] = sorted

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
  destination_filename = "%s/%sTest.java" % (output_dir, name)
  py_template = JENV.get_template(TEST_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(s=package_spec,
                               description=package_spec.description,
                               pkg_name=package_spec.package,
                               include=package_spec.package.split('.')[1],
                               filepath="/".join(package_spec.filepath) + ".yaml"))
