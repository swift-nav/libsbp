#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Dennis Zollo <dzollo@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from sbpg.targets.templating import *
from settings_list import SettingsList
import os
import re

# We sometimes need to remove underscores.  This will remove the latex
# safe underscore character and replace with a space
NO_UNDERSCORE = re.compile(r'_')


def no_us(value):
  """
  """
  newval = value
  try:
    return NO_UNDERSCORE.sub(' ', newval)
  except TypeError:
    pass
  return None

# Note, these reg exps will not replace the '^' character to allow
# exponents in the units text field
LATEX_SUBS_ALLOW_EXPONENTS = (
    (re.compile(r'\\'), r'\\textbackslash'),
    (re.compile(r'([{}_#%&$])'), r'\\\1'),
    (re.compile(r'~'), r'\~{}'),
    (re.compile(r'_'), r'_'),
    (re.compile(r'"'), r"''"),
    (re.compile(r'\.\.\.+'), r'\\ldots'),
    (re.compile(r'\n'), r'\\newline ')
)


def escape_tex_exp(value):
  """
  """
  newval = value
  try:
    for pattern, replacement in LATEX_SUBS_ALLOW_EXPONENTS:
      newval = pattern.sub(replacement, newval)
    return newval
  except TypeError:
    pass
  return None

JENV.filters['escape_tex_exp'] = escape_tex_exp
JENV.filters['no_us'] = no_us


def get_settings(sf=SETTINGS_FILE):
  """
  """
  settings = SettingsList(sf)
  groups = settings.return_groups()
  return (settings, groups)


def render_source(groups, settings):
  """
  Render and output
  """
  return latex_template.render(groups=sorted(groups),
                               setting=sorted(settings.list_of_dicts),
                               version='v0.15')
