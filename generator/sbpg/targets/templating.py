#!/usr/bin/env python
# Copyright (C) 2011-2014 Swift Navigation Inc.
# Contact: Fergus Noble <fergus@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""

"""

import jinja2

JENV = jinja2.Environment(block_start_string = '((*',
                          block_end_string = '*))',
                          variable_start_string = '(((',
                          variable_end_string = ')))',
                          comment_start_string = '((=',
                          comment_end_string = '=))',
                          loader=jinja2.FileSystemLoader("./sbpg/targets/resources/"))

ACRONYMS = ['GPS', 'ECEF', 'LLH', 'NED', 'IO']
