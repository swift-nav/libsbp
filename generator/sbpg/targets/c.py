#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
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

import re
from sbpg.targets.templating import *
from sbpg.utils import markdown_links
from sbpg import ReleaseVersion

PACKED_HEADER_TEMPLATE_NAME = "packed_sbp_messages_template.h"
UNPACKED_HEADER_TEMPLATE_NAME = "unpacked_sbp_messages_template.h"
UNPACKED_UNION_TEMPLATE_NAME = "unpacked_union_template.h"
VERSION_TEMPLATE_NAME = "sbp_version_template.h"
MESSAGE_TRAITS_TEMPLATE_NAME = "sbp_message_traits_template.h"
PACKERS_TEMPLATE_NAME = "packers_sbp_messages_template.h"
OPERATORS_TEMPLATE_NAME = "operators_sbp_messages_template.h"

PRIMITIVE_TYPES = set(['u8', 'u16', 'u32', 'u64', 's8', 's16', 's32',
                      's64', 'float', 'double', 'char'])
PRIMITIVE_SIZES = {
        'u8' : 1,
        'u16': 2,
        'u32': 4,
        'u64': 8,
        's8' : 1,
        's16': 2,
        's32': 4,
        's64': 8,
        'float': 4,
        'double': 8,
        'char': 1
        }

COLLISIONS = set(['GnssSignal', 'GPSTime'])

def sanitise_path(value):
    return re.sub('[->.\\[\\]]', '', value)

def commentify(value):
  """
  Builds a comment.
  """
  value = markdown_links(value)
  if value is None:
    return
  if len(value.split('\n')) == 1:
    return "* " + value
  else:
    return '\n'.join([' * ' + l for l in value.split('\n')[:-1]])


def mk_packed_id(field):
  """Builds an identifier from a field.
  """
  name = field.type_id
  if name == "string":
    return "%s" % ("char")
  elif name == "array" and field.size:
    if field.options['fill'].value not in PRIMITIVE_TYPES:
      return "%s" % convert_packed(field.options['fill'].value)
    else:
      return "%s" % field.options['fill'].value
  elif name == "array":
    return "%s" % convert_packed(field.options['fill'].value)
  elif name not in PRIMITIVE_TYPES:
    return convert_packed(name)
  else:
    return name

def mk_size(field):
  """Builds an identifier for a container type.
  """
  name = field.type_id
  if name == "string" and field.options.get('size', None):
    return "%s[%d];" % (field.identifier, field.options.get('size').value)
  elif name == "string":
    return "%s[0];" % field.identifier
  elif name == "array" and field.options.get('size', None):
    return "%s[%d];" % (field.identifier, field.options.get('size').value)
  elif name == "array":
    return "%s[0];" % field.identifier
  else:
    return '%s;' % field.identifier


def convert_packed(value):
  """Converts to a C language appropriate identifier format.

  """
  s0 = "Sbp" + value if value in COLLISIONS else value
  s1 = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', s0)
  return re.sub('([a-z0-9])([A-Z])', r'\1_\2', s1).lower() + "_t"

def convert_unpacked(value):
  """Converts to a C language appropriate identifier format.

  """
  return "sbp_" + convert_packed(value)


def get_bitfield_basename(msg, item):
    bitfield_name = item.get('desc', '').replace(" ", "_").upper()
    base_string = "SBP_{}_{}".format(msg.upper().replace('MSG_', ''), bitfield_name)
    base_string = re.sub('[^A-Za-z0-9_]+', '', base_string)
    return base_string


def create_bitfield_macros(field, msg):
  ret_list = []
  for item in field.options['fields'].value:
    base_string = get_bitfield_basename(msg, item)
    if not base_string.endswith("RESERVED"):
      nbits = item.get('len')
      bitrange = (item.get('range')).split(':')
      start_bit = int(bitrange[0])
      ret_list.append("#define {}_MASK ({})".format(base_string, hex((1 << nbits) - 1)))
      ret_list.append("#define {}_SHIFT ({}u)".format(base_string, start_bit))
      ret_list.append("""#define {}_GET(flags) \\
                             (((flags) >> {}_SHIFT) \\
                             & {}_MASK)""".format(base_string, base_string, base_string))
      ret_list.append("""#define {}_SET(flags, val) \\
                             do {{((flags) |= \\
                             (((val) & ({}_MASK)) \\
                             << ({}_SHIFT)));}} while(0)
                             """.format(base_string, base_string, base_string))
      ret_list.append("")
      for value_obj in item.get('vals', []):
        value_numerical = int(value_obj.get('value'))
        value_description = value_obj.get('desc', None).upper()
        value_description = re.sub(r'\([^)]*\)', '', value_description)
        value_description = re.sub('[ \-]+', '_', value_description.strip())
        value_description = re.sub('[^A-Za-z0-9_]+', '', value_description)
        if value_description and value_description.upper() != 'RESERVED':
          ret_list.append("#define {}_{} ({})".format(base_string, value_description,
                                                      value_numerical))
  return "\n".join(ret_list)

def extensions(includes):
    """Format a list of header files to include.
    """
    return ["".join([i.split(".")[0], ".h"]) for i in includes if i.split(".")[0] != "types"]

class BasetypeItem(object):
    """ PrimitiveItem
    """

    def __init__(self, msg, package_specs, type_id, packed_offset):
        self.name = type_id
        print("Creating basetype item %s" % type_id)
        if type_id in PRIMITIVE_TYPES:
            self.packed_size = PRIMITIVE_SIZES[type_id]
            self.is_primitive = True
        else:
            self.fields = []
            self.packed_size = 0
            self.is_primitive = False
            self.generate_as_nested = False
            for package in package_specs:
                for definition in package.definitions:
                    if definition.identifier == type_id:
                        for f in definition.fields:
                            new_field = FieldItem(msg, package_specs, f, packed_offset)
                            packed_offset += new_field.packed_size
                            self.packed_size += new_field.packed_size
                            self.fields.append(new_field)
                            if new_field.generate_as_nested:
                                self.generate_as_nested = True
                        return
            print("Can't find basetype %s" % type_id)
            raise "assert"

class FieldItem(object):
    """FieldItem
    """

    def __init__(self, msg, package_specs, field, packed_offset):
        self.name = field.identifier
        print("Creating field %s" % self.name)
        type_id = field.type_id
        
        self.packed_size = 0
        self.units = field.units
        self.desc = field.desc
        self.generate_as_nested = False
        if type_id == "string" and 'size' in field.options:
            self.order = "fixed-array"
            self.basetype = BasetypeItem(msg, package_specs, 'char', packed_offset)
            self.max_items = field.options['size'].value
            self.packed_size = field.options['size'].value
            self.options = field.options
        elif type_id == "string":
            self.order = "variable-array"
            self.basetype = BasetypeItem(msg, package_specs, 'char', packed_offset)
            self.max_items = int((255 - packed_offset) / self.basetype.packed_size)
            self.packed_size = 0
            self.options = field.options
            if 'size_fn' in field.options:
                self.size_fn = field.options['size_fn'].value
            self.generate_as_nested = True
        elif type_id == "array" and 'size' in field.options:
            self.order = "fixed-array"
            self.basetype = BasetypeItem(msg, package_specs, field.options['fill'].value, packed_offset)
            self.max_items = field.options['size'].value
            self.packed_size = field.options['size'].value * self.basetype.packed_size
            self.options = field.options
        elif type_id == "array":
            self.order = "variable-array"
            self.basetype = BasetypeItem(msg, package_specs, field.options['fill'].value, packed_offset)
            self.max_items = int((255 - packed_offset) / self.basetype.packed_size)
            self.packed_size = 0
            self.options = field.options
            if 'size_fn' in field.options:
                self.size_fn = field.options['size_fn'].value
            self.generate_as_nested = True
        else:
            self.order = "single"
            self.basetype = BasetypeItem(msg, package_specs, type_id, packed_offset)
            self.max_items = 1
            self.packed_size = self.basetype.packed_size
            self.options = field.options


class MsgItem(object):
    """MsgItem
    """

    def __init__(self, msg, package_specs):
        self.name = msg.identifier
        self.sbp_id = msg.sbp_id
        self.desc = msg.desc
        self.short_desc = msg.short_desc
        self.fields = []
        self.generate_as_nested = False
        self.is_real_message = msg.is_real_message
        packed_offset = 0
        print("Creating message %s" % self.name)
        for f in msg.fields:
            new_field = FieldItem(msg, package_specs, f, packed_offset)
            packed_offset += new_field.packed_size
            self.fields.append(new_field)

JENV.filters['convert_packed'] = convert_packed
JENV.filters['convert_unpacked'] = convert_unpacked
JENV.filters['mk_packed_id'] = mk_packed_id
JENV.filters['mk_size'] = mk_size
JENV.filters['commentify'] = commentify
JENV.filters['sanitise_path'] = sanitise_path
JENV.filters['create_bitfield_macros'] = create_bitfield_macros

def render_packed_headers(output_dir, package_spec):
  """
  Render and output to a directory given a package specification.
  """
  path, name = package_spec.filepath
  destination_filename = "%s/%s.h" % (output_dir, name)
  py_template = JENV.get_template(PACKED_HEADER_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(msgs=package_spec.definitions,
                               pkg_name=name,
                               filepath="/".join(package_spec.filepath) + ".yaml",
                               max_msgid_len=package_spec.max_msgid_len,
                               description=package_spec.description,
                               timestamp=package_spec.creation_timestamp,
                               include=extensions(package_spec.includes)))


def render_unpacked_headers(include_dir, package_specs):
    print("new_c::render_unpacked_headers")
    all_msgs = []
    all_packages = []
    msg_msgid_len =0
    for package_spec in package_specs:
        msgs = []
        msg_msgid_len = package_spec.max_msgid_len
        if not package_spec.render_source:
            continue
        name = package_spec.identifier.split('.', 2)[2]
        if name == 'types' or name == 'base':
            continue                                                                                          
        all_packages.append(name)                                                                             
        for m in package_spec.definitions:                                                                    
            new_msg = MsgItem(m, package_specs)                                                           
            if m.is_real_message:
                all_msgs.append(new_msg.name)                                                                 
            if not new_msg.generate_as_nested:
                msgs.append(new_msg)                                                                          
        destination_filename = "%s/unpacked/%s.h" % (include_dir, name)
        py_template = JENV.get_template(UNPACKED_HEADER_TEMPLATE_NAME)
        with open(destination_filename, 'w') as f:
            f.write(py_template.render(msgs = msgs,
                pkg_name = name,
                filepath="/".join(package_spec.filepath) + ".yaml",
                max_msgid_len=package_spec.max_msgid_len,
                include=extensions(package_spec.includes)))
        destination_filename = "%s/unpacked/%s_packers.h" % (include_dir, name)
        py_template = JENV.get_template(PACKERS_TEMPLATE_NAME)
        with open(destination_filename, 'w') as f:
            f.write(py_template.render(msgs = msgs,
                pkg_name = name,
                filepath="/".join(package_spec.filepath) + ".yaml",
                max_msgid_len=package_spec.max_msgid_len,
                include=extensions(package_spec.includes)))
        destination_filename = "%s/unpacked/%s_operators.h" % (include_dir, name)
        py_template = JENV.get_template(OPERATORS_TEMPLATE_NAME)
        with open(destination_filename, 'w') as f:
            f.write(py_template.render(msgs = msgs,
                pkg_name = name,
                filepath="/".join(package_spec.filepath) + ".yaml",
                max_msgid_len=package_spec.max_msgid_len,
                include=extensions(package_spec.includes)))
    destination_filename = "%s/unpacked/sbp_msg.h" % (include_dir)
    py_template = JENV.get_template(UNPACKED_UNION_TEMPLATE_NAME)
    with open(destination_filename, 'w') as f:
        f.write(py_template.render(msgs = all_msgs,
            include=extensions(all_packages),
            filepath="/".join(package_spec.filepath) + ".yaml",
            max_msgid_len=msg_msgid_len))

def render_version(output_dir, release: ReleaseVersion):
  destination_filename = "%s/version.h" % output_dir
  py_template = JENV.get_template(VERSION_TEMPLATE_NAME)
  with open(destination_filename, 'w') as output_file:
    output_file.write(py_template.render(major=release.major,
                                         minor=release.minor,
                                         patch=release.patch,
                                         full_version=release.full_version))

def render_traits(output_dir, package_specs):
  msgs = []
  includes = []
  for package_spec in package_specs:
    if not package_spec.render_source:
      continue
    name = package_spec.identifier.split('.', 2)[2]
    if name != 'types' and name != 'base':
      includes.append(name)
    for m in package_spec.definitions:
      if m.is_real_message:
        msgs.append(m)
  destination_filename = "%s/cpp/message_traits.h" % output_dir
  py_template = JENV.get_template(MESSAGE_TRAITS_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(packages=package_specs,
                               msgs=sorted(msgs, key=lambda msg: msg.sbp_id),
                               includes=sorted(includes)))
