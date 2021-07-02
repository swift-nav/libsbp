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

SBP_MESSAGES_TEMPLATE_NAME = "c/v4/sbp_messages_template.h"
SBP_PACKAGE_TEMPLATE_NAME = "c/v4/sbp_package_template.h"
SBP_MSG_TEMPLATE_NAME = "c/v4/sbp_msg_template.h"
VERSION_TEMPLATE_NAME = "c/sbp_version_template.h"
MESSAGE_TRAITS_TEMPLATE_NAME = "c/cpp/message_traits_template.h"
SBP_MESSAGES_SOURCE_TEMPLATE_NAME = "c/src/sbp_messages_template.c"
SBP_MESSAGES_PRIVATE_HEADER_TEMPLATE_NAME = "c/src/sbp_messages_private_template.h"
SBP_MESSAGES_MACROS_TEMPLATE_NAME = "c/sbp_messages_macros_template.h"
SBP_MSG_TYPE_TEMPLATE_NAME = "c/sbp_msg_type_template.h"

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


def convert_packed(value):
  """Converts to a C language appropriate identifier format.

  """
  s0 = "Sbp" + value if value in COLLISIONS else value
  s1 = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', s0)
  return re.sub('([a-z0-9])([A-Z])', r'\1_\2', s1).lower() + "_t"

def convert_unpacked(value):
  """Converts to a C language appropriate identifier format.

  """
  if value in PRIMITIVE_TYPES:
      return value
  return "sbp_" + convert_packed(value)

def convert_unpacked_union(value):
    """
    """
    return value.lower()[4:]


def snake_case(value):
    """
    """
    return convert_unpacked(value)[:-2]

def camel_case(value):
    """
    """
    return "Sbp" + ''.join(ele.title() for ele in value.split('_'))


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

def get_type_packed_size(typename, package_specs):
    """
    """
    if typename in PRIMITIVE_TYPES:
        return PRIMITIVE_SIZES[typename]

    packed_size = 0
    for package in package_specs:
        for msg in package.definitions:
            if msg.identifier == typename:
                for f in msg.fields:
                    packed_size = packed_size + get_field_packed_size(f, package_specs)
    return packed_size

def get_field_packed_size(field, package_specs):
    """
    """
    if field.type_id == "array":
        if "size" in field.options:
            return field.options['size'].value * get_type_packed_size(field.options['fill'].value, package_specs)
        return 0
    if field.type_id == "string":
        if "size" in field.options:
            return field.options['size'].value
        return 0
    return get_type_packed_size(field.type_id, package_specs)


def get_max_possible_items(msg, field, basetype, package_specs):
    """
    """
    used_space = 0
    for f in msg.fields:
        if f.identifier == field.identifier:
            break
        used_space = used_space + get_field_packed_size(f, package_specs)
    available_space = 255 - used_space
    return int(available_space / get_type_packed_size(basetype, package_specs))


def get_basetype_encode(value):
    """
    """
    if value in PRIMITIVE_TYPES:
        return "sbp_" + value + "_encode"
    return convert_unpacked(value)[:-2] + "_encode_internal"


def get_basetype_decode(value):
    """
    """
    if value in PRIMITIVE_TYPES:
        return "sbp_" + value + "_decode"
    return convert_unpacked(value)[:-2] + "_decode_internal"


def get_basetype_encoded_len(value):
    """
    """
    if value in PRIMITIVE_TYPES:
        return "sbp_" + value + "_encoded_len"
    return convert_unpacked(value)[:-2] + "_encoded_len"


def get_basetype_cmp(value):
    """
    """
    if value in PRIMITIVE_TYPES:
        return "sbp_" + value + "_cmp"
    return convert_unpacked(value)[:-2] + "_cmp"


class FieldItem(object):
    """FieldItem
    """

    def __init__(self, msg, package_specs, field):
        self.name = field.identifier
        #print("Creating field %s" % self.name)
        type_id = field.type_id
        
        self.packed_size = 0
        self.units = field.units
        self.desc = field.desc
        self.generate_as_nested = False

        if type_id == "string" and "size" in field.options:
            self.packing = "fixed-array"
            self.basetype = "char"
            self.basetype_encode = get_basetype_encode(self.basetype)
            self.basetype_decode = get_basetype_decode(self.basetype)
            self.basetype_encoded_len = get_type_packed_size(self.basetype, package_specs)
            self.basetype_cmp = get_basetype_cmp(self.basetype)
            self.max_items = field.options['size'].value
            self.packed_size = field.options['size'].value
            self.options = field.options
        elif type_id == "string" or "encoding" in field.options:
            self.packing = "packed-string"
            self.basetype = "char"
            self.max_items = get_max_possible_items(msg, field, self.basetype, package_specs)
            self.packed_size = 0
            self.options = field.options
            self.encoding = field.options['encoding'].value
            if self.encoding == "sequence":
                self.terminator = field.options['terminator'].value
        elif type_id == "array" and "size" in field.options:
            self.packing = "fixed-array"
            self.basetype = field.options['fill'].value
            self.basetype_encode = get_basetype_encode(self.basetype)
            self.basetype_decode = get_basetype_decode(self.basetype)
            self.basetype_encoded_len = get_type_packed_size(self.basetype, package_specs)
            self.basetype_cmp = get_basetype_cmp(self.basetype)
            self.max_items = field.options['size'].value
            self.packed_size = field.options['size'].value * get_type_packed_size(self.basetype, package_specs)
            self.options = field.options
        elif type_id == "array":
            self.packing = "variable-array"
            self.basetype = field.options['fill'].value
            self.basetype_encode = get_basetype_encode(self.basetype)
            self.basetype_decode = get_basetype_decode(self.basetype)
            self.basetype_encoded_len = get_type_packed_size(self.basetype, package_specs)
            self.basetype_cmp = get_basetype_cmp(self.basetype)
            self.max_items = get_max_possible_items(msg, field, self.basetype, package_specs)
            self.packed_size = 0
            if 'size_fn' in field.options:
                self.size_fn = field.options['size_fn'].value
                self.generate_size_fn = False
            else:
                self.size_fn = 'n_' + self.name
                self.generate_size_fn = True
            self.options = field.options
        else:
            self.packing = "single"
            self.basetype = type_id
            self.basetype_encode = get_basetype_encode(self.basetype)
            self.basetype_decode = get_basetype_decode(self.basetype)
            self.basetype_encoded_len = get_type_packed_size(self.basetype, package_specs)
            self.basetype_cmp = get_basetype_cmp(self.basetype)
            self.max_items = 1
            self.packed_size = get_type_packed_size(self.basetype, package_specs)
            self.options = field.options


def find_package(package_specs, type_id):
    for p in package_specs:
        for m in p.definitions:
            if m.identifier == type_id:
                return p.identifier.split('.', 2)[2]
    raise Exception("Can't find package for type %s" % type_id)


class MsgItem(object):
    """MsgItem
    """

    def __init__(self, msg, package_specs):
        self.name = msg.identifier
        self.prefix = snake_case(self.name)
        self.type_name = self.prefix + "_t"
        self.short_name = self.prefix[8:]
        self.enum_name = camel_case(self.name)
        self.sbp_id = msg.sbp_id
        self.desc = msg.desc
        self.short_desc = msg.short_desc
        self.fields = []
        self.is_real_message = msg.is_real_message
        self.sibling_include = []
        self.packed_size = 0
        self.is_fixed_size = True
        #print("Creating message %s" % self.name)
        for f in msg.fields:
            new_field = FieldItem(msg, package_specs, f)
            self.packed_size = self.packed_size + new_field.packed_size
            if new_field.packed_size == 0:
                self.is_fixed_size = False
                if not self.is_real_message:
                    print("Field %s in message %s: variable length arrays can only exist in real messages, not in embedded types" % (new_field.name, msg.identifier))
                    raise "error"
            self.fields.append(new_field)
            if new_field.basetype not in PRIMITIVE_TYPES:
                self.sibling_include.append(find_package(package_specs, new_field.basetype) + "/" + new_field.basetype)

JENV.filters['convert_unpacked'] = convert_unpacked
JENV.filters['convert_unpacked_union'] = convert_unpacked_union
JENV.filters['commentify'] = commentify
JENV.filters['sanitise_path'] = sanitise_path
JENV.filters['create_bitfield_macros'] = create_bitfield_macros


def render_headers(include_dir, package_specs):
    #print("new_c::render_unpacked_headers")
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
            msgs.append(new_msg)
            if m.is_real_message:
                all_msgs.append(new_msg)                                                                 
            destination_filename = "%s/v4/%s/%s.h" % (include_dir, name, new_msg.name)
            py_template = JENV.get_template(SBP_MESSAGES_TEMPLATE_NAME)
            with open(destination_filename, 'w') as f:
                f.write(py_template.render(m = new_msg,
                    pkg_name = name,
                    filepath="/".join(package_spec.filepath) + ".yaml",
                    max_msgid_len=package_spec.max_msgid_len,
                    include=extensions(package_spec.includes),
                    sibling_include=new_msg.sibling_include))
            #print("Adding %s" % new_msg.name)
        destination_filename = "%s/v4/%s.h" % (include_dir, name)
        py_template = JENV.get_template(SBP_PACKAGE_TEMPLATE_NAME)
        with open(destination_filename, 'w') as f:
            f.write(py_template.render(msgs = msgs,
                pkg_name = name,
                filepath="/".join(package_spec.filepath) + ".yaml",
                max_msgid_len=package_spec.max_msgid_len,
                include=extensions(package_spec.includes)))
        destination_filename = "%s/%s_macros.h" % (include_dir, name)
        py_template = JENV.get_template(SBP_MESSAGES_MACROS_TEMPLATE_NAME)
        with open(destination_filename, 'w') as f:
            f.write(py_template.render(msgs = msgs,
                pkg_name = name,
                filepath="/".join(package_spec.filepath) + ".yaml",
                max_msgid_len=package_spec.max_msgid_len,
                include=extensions(package_spec.includes)))
    destination_filename = "%s/v4/sbp_msg.h" % (include_dir)
    py_template = JENV.get_template(SBP_MSG_TEMPLATE_NAME)
    with open(destination_filename, 'w') as f:
        f.write(py_template.render(msgs = sorted(all_msgs, key=lambda k: k.type_name),
            include=extensions(all_packages),
            filepath="/".join(package_spec.filepath) + ".yaml",
            max_msgid_len=msg_msgid_len))
    destination_filename = "%s/cpp/message_traits.h" % include_dir
    py_template = JENV.get_template(MESSAGE_TRAITS_TEMPLATE_NAME)
    with open(destination_filename, 'w') as f:
        f.write(py_template.render(packages=package_specs,
                               msgs=sorted(all_msgs, key=lambda k: k.type_name),
                               includes=extensions(all_packages)))
    destination_filename = "%s/sbp_msg_type.h" % include_dir
    py_template = JENV.get_template(SBP_MSG_TYPE_TEMPLATE_NAME)
    with open(destination_filename, 'w') as f:
        f.write(py_template.render(msgs = sorted(all_msgs, key=lambda k: k.type_name),
                                   packages=all_packages))


def render_sources(output_dir, package_specs):
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
            msgs.append(new_msg)
            if m.is_real_message:
                all_msgs.append(new_msg.name)                                                                 
            #print("Adding %s" % new_msg.name)
        destination_filename = "%s/v4/%s.c" % (output_dir, name)
        py_template = JENV.get_template(SBP_MESSAGES_SOURCE_TEMPLATE_NAME)
        with open(destination_filename, 'w') as f:
            f.write(py_template.render(msgs = msgs,
                pkg_name = name,
                filepath="/".join(package_spec.filepath) + ".yaml",
                max_msgid_len=package_spec.max_msgid_len,
                include=extensions(package_spec.includes)))
        destination_filename = "%s/include/libsbp/internal/v4/%s.h" % (output_dir, name)
        py_template = JENV.get_template(SBP_MESSAGES_PRIVATE_HEADER_TEMPLATE_NAME)
        with open(destination_filename, 'w') as f:
            f.write(py_template.render(msgs = msgs,
                pkg_name = name,
                filepath="/".join(package_spec.filepath) + ".yaml",
                max_msgid_len=package_spec.max_msgid_len,
                include=extensions(package_spec.includes)))


def render_version(output_dir, release: ReleaseVersion):
  destination_filename = "%s/version.h" % output_dir
  py_template = JENV.get_template(VERSION_TEMPLATE_NAME)
  with open(destination_filename, 'w') as output_file:
    output_file.write(py_template.render(major=release.major,
                                         minor=release.minor,
                                         patch=release.patch,
                                         full_version=release.full_version))

