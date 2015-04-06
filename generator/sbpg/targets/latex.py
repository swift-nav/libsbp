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

from operator import attrgetter
from sbpg.specs.settings_list import SettingsList
from sbpg.targets.templating import *
from sbpg.utils import fmt_repr
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

TEMPLATE_NAME = "sbp_settings.tex"

LATEX_SUBS = (
    (re.compile(r'\\'), r'\\textbackslash'),
    (re.compile(r'([{}_#%&$])'), r'\\\1'),
    (re.compile(r'~'), r'\~{}'),
    (re.compile(r'\^'), r'\^{}'),
    (re.compile(r'_'), r'_'),
    (re.compile(r'"'), r"''"),
    (re.compile(r'\.\.\.+'), r'\\ldots'),
)

def escape_tex(value):
  """
  Make text tex safe
  """
  newval = value
  for pattern, replacement in LATEX_SUBS:
    newval = pattern.sub(replacement, newval)
  return newval

def classnameify(s):
  """
  Makes a classname
  """
  return ''.join(w if w in ACRONYMS else w.title() for w in s.split('_'))

def packagenameify(s):
  """
  Makes a package name
  """
  return ''.join(w if w in ACRONYMS else w.title() for w in s.split('.')[-1:])

def nobrackets(v):
  """
  Remove empty brackets
  """
  return v.translate(None, '[]')

def removearray(v):
  """
  Clean up array name
  """
  return re.sub('^[a-z]*\[N\]\.', '', v)

def removehost(v):
  """
  Clean up array name
  """
  return re.sub('^[a-z]*\[N\]\.', '', v)

re1 = '(\\()'
re2 = '(Host)'
re3 = '(.)'
re4 = '(=)'
re5 = '.*?'
re6 = '(Piksi)'
re7 = '(\\)).*'

def remove_dir(v):
  """
  Clean up array name
  """
  return v.split("(Host")[0]

def get_size(v):
  """
  Clean up array name
  """
  return field_sizes[v] if field_sizes.get(v, None) else "---"

JENV.filters['escape_tex'] = escape_tex
JENV.filters['classnameify'] = classnameify
JENV.filters['packagenameify'] = packagenameify
JENV.filters['nobrackets'] = nobrackets
JENV.filters['removearray'] = removearray
JENV.filters['removedir'] = remove_dir
JENV.filters['getsize'] = get_size

field_sizes = {
    'u8'     : 1,
    'u16'    : 2,
    'u32'    : 4,
    'u64'    : 8,
    's8'     : 1,
    's16'    : 2,
    's32'    : 4,
    's64'    : 8,
    'float'  : 4,
    'double' : 8,
}

CONSTRUCT_CODE = set(['u8', 'u16', 'u32', 'u64', 's8',
                      's16', 's32', 's64', 'float', 'double'])

class TableItem(object):
  """
  """

  def __init__(self, pkg, name, sbp_id, short_desc,
               desc, size, fields, stable=False, pkg_desc=None):
    self.pkg = pkg
    self.name = name
    self.sbp_id = sbp_id
    self.short_desc = short_desc or ""
    self.desc = desc or ""
    self.size = size
    self.fields = fields
    self.stable = stable
    self.pkg_desc = pkg_desc


class FieldItem (object):
  """
  """

  def __init__(self, name, fmt, offset, size, units, desc, n_with_values, bitfields):
    self.name = name
    self.fmt = fmt
    self.offset = offset
    self.size = size
    self.units = units
    self.desc = desc or ""
    self.n_with_values = n_with_values
    self.bitfields = bitfields


def handle_fields(definitions, fields, prefix, offset, multiplier):
  """
  Helper for handling naming and sizing of fields. It's terrible.
  """
  items = []
  for f in fields:
    if f.type_id == "array" and f.options['fill'].value in CONSTRUCT_CODE:
      prefix_name = '.'.join([prefix, f.identifier]) if prefix else f.identifier
      n_with_values = f.options['n_with_values'].value
      bitfields = f.options['fields'].value if n_with_values > 0 else None
      if 'size' in f.options:
        name = "%s[%s]" % (f.options['fill'].value, str(f.options['size'].value))
        size = field_sizes[f.options['fill'].value] * f.options['size'].value
        item = FieldItem(prefix_name, name, offset, size, str(f.units), f.desc, n_with_values, bitfields)
        items.append(item)
        offset += size
    elif f.type_id == "string":
      prefix_name = '.'.join([prefix, f.identifier]) if prefix else f.identifier
      n_with_values = f.options['n_with_values'].value
      bitfields = f.options['fields'].value if n_with_values > 0 else None
      if 'size' in f.options:
        name = "string"
        size = field_sizes['u8'] * f.options['size'].value
        item = FieldItem(prefix_name, name, offset, size, str(f.units), f.desc, n_with_values, bitfields)
        items.append(item)
        offset += size
      else:
        name = "string"
        size = field_sizes['u8']
        item = FieldItem(prefix_name, name, offset, size,
                         str(f.units), f.desc, n_with_values, bitfields)
        items.append(item)
        offset += size
    elif f.type_id == "array":
      name = f.options['fill'].value
      definition = next(d for d in definitions if name == d.identifier)
      prefix_name = '.'.join([prefix, f.identifier]) if prefix else f.identifier
      (new_items, new_offset, new_multiplier) \
        = handle_fields(definitions,
                        definition.fields,
                        prefix_name + "[*N*]",
                        offset,
                        multiplier)
      multiplier = new_offset - offset
      (newer_items, newer_offset, newer_multiplier) \
        = handle_fields(definitions,
                        definition.fields,
                        prefix_name + "[*N*]", offset,
                        multiplier)
      items += newer_items
      offset = newer_offset
    elif f.type_id not in CONSTRUCT_CODE:
      name = f.type_id
      definition = next(d for d in definitions if name == d.identifier)
      prefix_name = '.'.join([prefix, f.identifier]) if prefix else f.identifier
      (new_items, new_offset, new_multiplier) \
        = handle_fields(definitions,
                        definition.fields,
                        prefix_name,
                        offset,
                        multiplier)
      items += new_items
      offset = new_offset
      multiplier = new_multiplier
    else:
      size = field_sizes[f.type_id]
      name = f.type_id
      adj_offset = "%dN+%d" % (multiplier, offset) if multiplier else offset
      prefix_name = '.'.join([prefix, f.identifier]) if prefix else f.identifier
      n_with_values = f.options['n_with_values'].value
      bitfields = f.options['fields'].value if n_with_values > 0 else None
      item = FieldItem(prefix_name, name, adj_offset, size, str(f.units), f.desc, n_with_values, bitfields)
      items.append(item)
      offset += size
  return (items, offset, multiplier)


def render_source(output_dir, package_specs, settings_file):
  """
  Render and output
  """
  setting = SettingsList(settings_file)
  groups = sorted(setting.return_groups())
  setting = sorted(setting.list_of_dicts)
  destination_filename = "%s/sbp_out.tex" % output_dir
  py_template = JENV.get_template(TEMPLATE_NAME)
  stable_msgs = []
  unstable_msgs = []
  prims = []
  for p in sorted(package_specs, key=attrgetter('identifier')):
    pkg_name = p.identifier
    stable = p.stable
    if pkg_name == "swiftnav.sbp.types":
      prims = p.definitions
    for d in p.definitions:
      if d.public and d.static and d.sbp_id:
        items, size, multiplier \
          = handle_fields(p.definitions, d.fields, "", 0, None)
        adj_size = "%dN+%d" % (multiplier, size) if multiplier else size
        ti = TableItem(pkg_name, d.identifier, d.sbp_id,
                       d.short_desc, d.desc, adj_size, items, p.stable,
                       p.description)
        pkg_name = ""
        if stable:
          stable_msgs.append(ti)
        else:
          unstable_msgs.append(ti)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(msgs=stable_msgs,
                               umsgs=unstable_msgs,
                               groups=groups,
                               setting=setting,
                               prims=prims))
  import subprocess
  import os
  os.chdir(output_dir)
  subprocess.call(["pdflatex", "sbp_out.tex"])
  subprocess.call(["mv", "sbp_out.pdf", "../docs/sbp.pdf"])
