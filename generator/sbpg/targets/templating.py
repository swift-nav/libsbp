#!/usr/bin/env python
# Copyright (C) 2011-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
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
from jinja2.environment import Environment
from jinja2.filters import do_indent, do_wordwrap

from sbpg.utils import comment_links, markdown_links

JENV = jinja2.Environment(block_start_string = '((*',
                          block_end_string = '*))',
                          variable_start_string = '(((',
                          variable_end_string = ')))',
                          comment_start_string = '((=',
                          comment_end_string = '=))',
                          loader=jinja2.PackageLoader('sbpg',
                                                      'targets/resources'),
                          )

ACRONYMS = ['GPS', 'ECEF', 'LLH', 'NED', 'IO']
INCLUDE_MAP = {
    "gnss": [
        "CarrierPhase",
        "GnssSignal",
        "GnssSignalDep",
        "GPSTime",
        "GPSTimeDep",
        "GPSTimeSec",
        "SvId",
    ],
}


def is_list(x):
    return isinstance(x, list)


def indented_wordwrap(
    environment: Environment,
    value: str,
    indent: str,
    width: int = None,
    first: bool = True,
    markdown: bool = False,
):
    """
    Build a indented and word-wrapped comment.
    """
    if not value:
        return
    if not width:
        width = 78 - len(indent)
    if "https://" in value:
        if markdown:
            value = markdown_links(value)
        else:
            value = comment_links(value)
        value = do_wordwrap(
            environment,
            value,
            width=width,
            break_long_words=False,
            break_on_hyphens=False,
        )
    else:
        # While breaking on long lines is helpful for the Jinja output,
        # it inhibits language style specific formatters from reformatting
        # as they dont know to re-join words which have been split.
        value = do_wordwrap(
            environment,
            value,
            width=width,
            break_long_words=False,
            break_on_hyphens=True,
        )
    # If the indent contains characters, it should be shown for blank lines.
    blank = indent.strip() != ""
    value = do_indent(value, indent, first=first, blank=blank)
    value = "\n".join([line.rstrip() for line in value.splitlines()])
    return value
