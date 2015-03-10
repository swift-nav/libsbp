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
"""

import jinja2
import re
import subprocess
from sbp.targets.templating import *

JENV.filters['escape_tex'] = escape_tex

jenv = jinja2.Environment(
    block_start_string = '((*',
    block_end_string = '*))',
    variable_start_string = '(((',
    variable_end_string = ')))',
    comment_start_string = '((=',
    comment_end_string = '=))',
    loader=jinja2.FileSystemLoader("./")
)

def escape_tex(value):
    newval = value
    for pattern, replacement in LATEX_SUBS:
        newval = pattern.sub(replacement, newval)
    return newval

jenv.filters['escape_tex'] = escape_tex
jenv.filters['commentify'] = commentify
jenv.filters['classnameify'] = classnameify

LATEX_SUBS = (
    (re.compile(r'\\'), r'\\textbackslash'),
    (re.compile(r'([{}_#%&$])'), r'\\\1'),
    (re.compile(r'~'), r'\~{}'),
    (re.compile(r'\^'), r'\^{}'),
    (re.compile(r'_'), r'_'),
    (re.compile(r'"'), r"''"),
    (re.compile(r'\.\.\.+'), r'\\ldots'),
)

latex_template = jenv.get_template('message_descs.tex')
with open("sbp_out.tex", 'w') as f:
    f.write(latex_template.render(msgs=msgs))

subprocess.call(["pdflatex" , "sbp_out.tex"])
subprocess.call(["mv" , "sbp_out.pdf", "../docs/sbp.pdf"])
