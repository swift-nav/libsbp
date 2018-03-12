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

"""Generator for Protocol Buffers target.

This module consumes the YAML spec and generates some message class
files.

"""

from sbpg.targets.templating import *

MESSAGES_TEMPLATE_NAME = "message_template.proto.j2"

def camel_case(s):
  """
  Convert snake_case to camel_case.
  """
  return ''.join([i.capitalize() for i in s.split('_')]) if '_' in s else s

JENV.filters['camel_case'] = camel_case

def render_source(output_dir, package_spec):
    """
    Render and output to a directory given a package specification.
    """
    path, name = package_spec.filepath
    destination_filename = "%s/%s.proto" % (output_dir, name)
    pb_template = JENV.get_template(MESSAGES_TEMPLATE_NAME)
    with open(destination_filename, 'w') as f:
        f.write(pb_template.render(
            package=package_spec.identifier,
            messages=package_spec.definitions
        ))
