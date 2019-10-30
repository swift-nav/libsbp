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
Generator for c tests target.
"""

from sbpg.targets.templating import *
from sbpg.targets.rust import *
import base64

TEST_TEMPLATE_NAME = "sbp_tests_template.rs"
#CHECK_SUITES_TEMPLATE_NAME = "sbp_c_suites.h.j2"
#CHECK_MAIN_TEMPLATE_NAME = "sbp_c_main.c.j2"

def b64_decode(field):
    print("Decoding '{}'".format(field))
    b = base64.standard_b64decode(field)
    return [ str(ord(ch)) for ch in b ]

def stringType(value):
    return type(value) == str

def arrayType(value):
    return type(value) == list

def dictType(value):
    return type(value) == dict

def floatType(value):
    return type(value) == float

def isEmpty(value):
    return len(value) == 0

def strEscape(value):
    return "\"{}\".to_string()".format(value)

def toStr(value):
    return str(value)

def modName(value):
    return value.split('.')[1]

JENV.filters['b64_decode'] = b64_decode
JENV.filters['toStr'] = toStr
JENV.filters['str_escape'] = strEscape
JENV.filters['sorted'] = sorted
JENV.filters['modName'] = modName

JENV.tests['stringType'] = stringType
JENV.tests['arrayType'] = arrayType
JENV.tests['dictType'] = dictType
JENV.tests['floatType'] = floatType
JENV.tests['empty'] = isEmpty

def render_source(output_dir, package_spec):
  """
  Render and output to a directory given a package specification.
  """
  path, name = package_spec.filepath
  destination_filename = "%s/%s.rs" % (output_dir, name)
  py_template = JENV.get_template(TEST_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(s=package_spec,
                               description=package_spec.description,
                               pkg_name=package_spec.package,
                               include=package_spec.package.split('.')[1],
                               filepath="/".join(package_spec.filepath) + ".yaml"))


#def render_check_suites(output_dir, all_package_specs):
#  destination_filename = "%s/%s.h" % (output_dir, "check_suites")
#  py_template = JENV.get_template(CHECK_SUITES_TEMPLATE_NAME)
#  with open(destination_filename, 'w') as f:
#    f.write(py_template.render(package_suites=all_package_specs))


#def render_check_main(output_dir, all_package_specs):
#  destination_filename = "%s/%s.c" % (output_dir, "check_main")
#  py_template = JENV.get_template(CHECK_MAIN_TEMPLATE_NAME)
#  with open(destination_filename, 'w') as f:
#    f.write(py_template.render(package_suites=all_package_specs))

