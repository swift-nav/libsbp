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

import os
import re
import subprocess

from operator import attrgetter

from sbpg.targets.templating import ACRONYMS, JENV
from sbpg import ReleaseVersion


# We sometimes need to remove underscores.  This will remove the latex
# safe underscore character and replace with a space
NO_UNDERSCORE = re.compile(r'_')

def no_us(value):
  """Removes underscores from strings.
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

TEMPLATE_NAME = "sbp_messages_desc.tex"

LATEX_SUBS_MIN = (
    (re.compile(r'([{}_#%&$])'), r'\\\1'),
    (re.compile(r'@@(\S+)\[([^\]]+)\]'), r'\\href{\1}{\2}'),
    (re.compile(r'~'), r'\~{}'),
    (re.compile(r'\^'), r'\^{}'),
    (re.compile(r'"'), r"''"),
    (re.compile(r'\.\.\.+'), r'\\ldots'),
)

LATEX_SUBS_ALL = (
    (re.compile(r'\\'), r'\\textbackslash'),
) + LATEX_SUBS_MIN

MAX_NAME_LENGTH = 27


def append_signals_table(value):
    return value + " (see pg. ~\\pageref{sec:signals})"


def _escape_tex(value, subs):
    for pattern, replacement in subs:
        value = pattern.sub(replacement, value)
    return value


def escape_tex(value):
    """
    Make text tex safe
    """
    return _escape_tex(value, LATEX_SUBS_ALL)


def escape_table_name(value):
    if len(value) > MAX_NAME_LENGTH:
        value = value[:MAX_NAME_LENGTH] + " \\newline " + value[MAX_NAME_LENGTH:]
    return _escape_tex(value, LATEX_SUBS_MIN)


def classnameify(s):
  """
  Makes a classname
  """
  return ''.join(w if w in ACRONYMS else w.title() for w in s.split('_'))


def header_write(v):
  return re.sub('Io', 'IO', v)


def packagenameify(s):
  """
  Makes a package name
  """
  return ''.join(w if w in ACRONYMS else w.title() for w in s.split('.')[-1:])


def nobrackets(v):
  """
  Remove brackets
  """
  return v.replace('[', '').replace(']', '')


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


def remove_dir(v):
  """
  Clean up array name
  """
  return v.split("(host")[0]


def get_size(v):
  """
  Clean up array name
  """
  return field_sizes[v] if field_sizes.get(v, None) else "---"


JENV.filters['append_signals_table'] = append_signals_table
JENV.filters['escape_tex'] = escape_tex
JENV.filters['escape_table_name'] = escape_table_name
JENV.filters['classnameify'] = classnameify
JENV.filters['packagenameify'] = packagenameify
JENV.filters['nobrackets'] = nobrackets
JENV.filters['removearray'] = removearray
JENV.filters['removedir'] = remove_dir
JENV.filters['getsize'] = get_size
JENV.filters['no_us'] = no_us
JENV.filters['header_write'] = header_write

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

CONSTRUCT_CODE = set(['u8', 'u16', 'u32', 'u64', 's8', 's16',
                      's32', 's64', 'float', 'double'])


class TableItem(object):
  """Message
  """

  def __init__(self, pkg, name, sbp_id, short_desc,
               desc, size, fields, stable=False, pkg_desc=None, is_real_message=True,
               embedded_type=False):
    self.pkg = pkg
    self.name = name
    self.sbp_id = sbp_id
    self.short_desc = short_desc or ""
    self.desc = desc or ""
    self.size = size
    self.fields = fields
    self.stable = stable
    self.pkg_desc = pkg_desc
    self.embedded_type = embedded_type
    self.is_real_message = is_real_message


class FieldItem (object):
  """Field contents for a message in a LaTeX table.
  """

  def __init__(self, name, fmt, offset, size, units, desc, n_with_values, bitfields, type_id):
    self.name = name
    self.fmt = fmt
    self.offset = offset
    self.size = size
    self.units = units
    self.desc = desc or ""
    self.n_with_values = n_with_values
    self.bitfields = bitfields
    self.type_id = type_id


  @property
  def is_gnss_signal(self):
      return self.type_id == "GnssSignal" and self.bitfields


def handle_fields(definitions, fields, prefix, offset, multiplier, type_id = None):
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
        adj_offset = "%dN+%d" % (multiplier, offset) if multiplier else offset
        item = FieldItem(prefix_name, name, adj_offset, size,
                         str(f.units), f.desc, n_with_values, bitfields, type_id)
        items.append(item)
        offset += size
      else:
        name = "%s[%s]" % (f.options['fill'].value, "N")
        multiplier = field_sizes[f.options['fill'].value]
        size = field_sizes[f.options['fill'].value] * 1
        item = FieldItem(prefix_name, name, offset, "N",
                         str(f.units), f.desc, n_with_values, bitfields, type_id)
        items.append(item)
        offset += size
    elif f.type_id == "string":
      prefix_name = '.'.join([prefix, f.identifier]) if prefix else f.identifier
      n_with_values = f.options['n_with_values'].value
      bitfields = f.options['fields'].value if n_with_values > 0 else None
      if 'size' in f.options:
        name = "string"
        size = field_sizes['u8'] * f.options['size'].value
        adj_offset = "%dN+%d" % (multiplier, offset) if multiplier else offset
        item = FieldItem(prefix_name, name, adj_offset, size,
                         str(f.units), f.desc, n_with_values, bitfields, type_id)
        items.append(item)
        offset += size
      else:
        name = "string"
        size = field_sizes['u8']
        multiplier = 1
        item = FieldItem(prefix_name, name, offset, "N",
                         str(f.units), f.desc, n_with_values, bitfields, type_id)
        items.append(item)
        offset += size
    elif f.type_id == "array":
      name = f.options['fill'].value
      definition = next(d for d in definitions if name == d.identifier)
      prefix_name = '.'.join([prefix, f.identifier]) if prefix else f.identifier
      (_, new_offset, _) \
        = handle_fields(definitions,
                        definition.fields,
                        prefix_name + "[N]",
                        offset,
                        multiplier)
      multiplier = new_offset - offset
      (newer_items, newer_offset, _) \
        = handle_fields(definitions,
                        definition.fields,
                        prefix_name + "[N]", offset,
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
                        multiplier, f.type_id)
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
      item = FieldItem(prefix_name, name, adj_offset, size, str(f.units), f.desc, n_with_values, bitfields, type_id)
      items.append(item)
      offset += size
  return (items, offset, multiplier)

def render_source(output_dir, package_specs, version: ReleaseVersion):
  """
  Render and output
  """
  destination_filename = "%s/sbp_out.tex" % output_dir
  py_template = JENV.get_template(TEMPLATE_NAME)
  stable_msgs = []
  unstable_msgs = []
  prims = []
  for p in sorted(package_specs, key=attrgetter('identifier')):
    pkg_name = p.identifier
    stable = p.stable

    # build list of required definitions (this package plus includes)
    # TODO: recursively include files
    definitions = p.definitions
    for inc in p.includes:
      inc_basename = inc.split(".")[0]
      for pkg in package_specs:
        if pkg.identifier.endswith(inc_basename):
          definitions += pkg.definitions

    if pkg_name == "swiftnav.sbp.types":
      prims = p.definitions
    for d in p.definitions:
      if d.public and (d.is_real_message or d.embedded_type):
        items, size, multiplier \
          = handle_fields(definitions, d.fields, "", 0, None)
        adj_size = ""
        if multiplier == 1:
          adj_size = "N+%d" % (size - 1) if size > 1 else "N"
        elif multiplier:
           if multiplier == size:
             adj_size = "%dN" % multiplier
           else:
             adj_size = "%dN+%d" % (multiplier, size - multiplier)
        else:
          adj_size = "%d" % size
        ti = TableItem(pkg_name, d.identifier, d.sbp_id,
                       d.short_desc, d.desc, adj_size, items, p.stable,
                       pkg_desc=p.description,
                       is_real_message=d.is_real_message,
                       embedded_type=d.embedded_type)
        pkg_name = ""
        if stable:
          stable_msgs.append(ti)
        else:
          unstable_msgs.append(ti)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(msgs=stable_msgs,
                               umsgs=unstable_msgs,
                               prims=prims,
                               version=version.full_version))
  os.chdir(output_dir)
  if "TEXMFVAR" not in os.environ:
    os.environ["TEXMFVAR"] = "/tmp"
  subprocess.check_call(["pdflatex", "--enable-write18",
                         "-shell-escape", "sbp_out.tex"])
  subprocess.check_call(["mv", "sbp_out.pdf", "../docs/sbp.pdf"])
