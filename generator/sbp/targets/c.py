#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
Generator for c target.
"""

import jinja2
import os
from sbp.targets.templating import *

TEMPLATE_NAME = "sbp_messages_template.h"

def commentify(value):
  """
  Builds a comment.
  """
  if value is None:
    return
  return '\n'.join([' * ' + l for l in value.split('\n')[:-1]])

def extensions(includes):
  """
  """
  return ["".join([i.split(".")[0], ".h"]) for i in includes]

JENV.filters['commentify'] = commentify

def render_source(output_dir, package_spec):
  """
  Render and output
  """
  #import pdb; pdb.set_trace()
  path, name = package_spec.filepath
  #import pdb; pdb.set_trace()
  directory = "/".join([output_dir, path])
  if not os.path.exists(directory):
    os.makedirs(directory)
  destination_filename = "%s/%s.h" % (directory, name)
  py_template = JENV.get_template(TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(msgs=package_spec.definitions,
                               pkg_name=name,
                               max_msgid_len=package_spec.max_msgid_len,
                               include=extensions(package_spec.includes)))
