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
Generator for c target (V4 API).
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

PRIMITIVE_TYPES = set(
    ["u8", "u16", "u32", "u64", "s8", "s16", "s32", "s64", "float", "double", "char"]
)
PRIMITIVE_SIZES = {
    "u8": 1,
    "u16": 2,
    "u32": 4,
    "u64": 8,
    "s8": 1,
    "s16": 2,
    "s32": 4,
    "s64": 8,
    "float": 4,
    "double": 8,
    "char": 1,
}

COLLISIONS = set(["GnssSignal", "GPSTime"])


def sanitise_path(value):
    return re.sub("[->.\\[\\]]", "", value)


def commentify(value):
    """
    Builds a comment.
    """
    value = markdown_links(value)
    if value is None:
        return
    if len(value.split("\n")) == 1:
        return "* " + value
    else:
        return "\n".join([" * " + l for l in value.split("\n")[:-1]])


def camel_case(value):
    """Convert an identifier to CamelCase"""
    return "".join(ele.title() for ele in value.split("_"))


def get_v4_basename(identifier):
    """
    Convert an identifier from the SBP spec to the base component used to construct other related identifiers in the V4 schema

    The basename is the identifier from the SBP spec convertered to snake_case and prefixed with either:
    "sbp_v4_" for types in the collisions list
    "sbp_" for everything else
    """
    s0 = re.sub("(.)([A-Z][a-z]+)", r"\1_\2", identifier)
    s1 = re.sub("([a-z0-9])([A-Z])", r"\1_\2", s0).lower()
    s2 = "sbp_sbp_" + s1 if identifier in COLLISIONS else "sbp_" + s1
    return s2


def get_union_member_name(identifier):
    """Convert an identifier to the appropriate name for use in the `sbp_msg_t` union
    Only works for real messages, calling this with any other typename will assert
    """
    basename = get_v4_basename(identifier)
    dropped = basename[:8]
    assert dropped == "sbp_msg_"
    return basename[8:]


def get_v4_typename(identifier):
    """
    Convert an SBP spec identifier in to the correct typename according to the V4 API
    """
    if identifier in PRIMITIVE_TYPES:
        return identifier
    return get_v4_basename(identifier) + "_t"


def get_v4_msg_type(identifier):
    """
    Convert an SBP spec identifier to the msg_type identifier according to the V4 API
    Only works for real messages will assert when called for any other type
    """

    assert identifier[:4] == "MSG_"
    return camel_case("sbp_" + identifier.lower())


def get_legacy_msg_type(identifier):
    """
    Convert an SBP spec identifier to the message type #define identifier according to the legacy API
    Only works for real messages, will assert when called for any other type
    """

    assert identifier[:4] == "MSG_"
    return "SBP_" + identifier


def get_public_encode_fn(typename):
    """
    Get the name of the public function which can encode a given type
    Only valid for real messages
    """
    if typename in PRIMITIVE_TYPES:
        return "sbp_" + typename + "_encode"
    assert typename[-2:] == "_t"
    return typename[:-2] + "_encode"


def get_internal_encode_fn(typename):
    """
    Get the name of the internal function which can encode a given type
    """
    if typename in PRIMITIVE_TYPES:
        return "sbp_" + typename + "_encode"
    assert typename[-2:] == "_t"
    return typename[:-2] + "_encode_internal"


def get_public_decode_fn(typename):
    """
    Get the name of the public function which can encode a given type
    Only valid for real messages
    """
    if typename in PRIMITIVE_TYPES:
        return "sbp_" + typename + "_decode"
    assert typename[-2:] == "_t"
    return typename[:-2] + "_decode"


def get_internal_decode_fn(typename):
    """
    Get the name of the internalfunction which can decode a given type
    """
    if typename in PRIMITIVE_TYPES:
        return "sbp_" + typename + "_decode"
    assert typename[-2:] == "_t"
    return typename[:-2] + "_decode_internal"


def get_send_fn(typename):
    """
    Get the name of the public function which can send a given type
    Only valid for real messages
    """
    assert typename[:8] == "sbp_msg_"
    assert typename[-2:] == "_t"
    return typename[:-2] + "_send"


def get_cmp_fn(typename):
    """
    Get the name of the function which can compare 2 instances of a given type
    """
    if typename in PRIMITIVE_TYPES:
        return "sbp_" + typename + "_cmp"
    assert typename[-2:] == "_t"
    return typename[:-2] + "_cmp"


def get_field_encoded_len(field, package_specs):
    """
    Get the encoded length of a message field on the wire
    """
    if field.type_id == "array":
        if "size" in field.options:
            return field.options["size"].value * get_encoded_len_value(
                get_v4_typename(field.options["fill"].value), package_specs
            )
        # Variable length array, can't calculate a length. This will later cause an assert if it's being used from an embedded type
        return 0
    if field.type_id == "string":
        if "size" in field.options:
            return field.options["size"].value
        return 0
    return get_encoded_len_value(get_v4_typename(field.type_id), package_specs)


def get_encoded_len_macro(typename):
    """
    Get the macro name which specified the encoded length of a given type
    """
    if typename in PRIMITIVE_TYPES:
        return "SBP_ENCODED_LEN_" + typename.upper()
    assert typename[-2:] == "_t"
    return "SBP_ENCODED_LEN_" + typename[:-2].upper()


def get_encoded_len_value(typename, package_specs):
    """
    Get the encoded size of a given type on the wire
    """
    if typename in PRIMITIVE_TYPES:
        return PRIMITIVE_SIZES[typename]

    encoded_len = 0
    for package in package_specs:
        for msg in package.definitions:
            if get_v4_typename(msg.identifier) == typename:
                for f in msg.fields:
                    encoded_len = encoded_len + get_field_encoded_len(f, package_specs)
    return encoded_len


def get_encoded_len_fn(typename):
    """
    Get the name of a function which can retrieve the encoded length of a type
    """
    assert typename[:4] == "sbp_"
    assert typename[-2:] == "_t"
    return typename[:-2] + "_encoded_len"


def get_max_possible_items(msg, field, package_specs):
    """
    Calculates the maximum number of items which can be stored in a variable length array or string field

    The given field must be a variable length array or string otherwise this function will assert

    The maximum number of items will be calculated by summing the sizes of all fields which occur in the 
    message before the specified field and dividing the remainder by the encoded size of a single item in the array
    """
    assert field.type_id == "array" or field.type_id == "string"
    assert "size" not in field.options
    used_space = 0
    for f in msg.fields:
        if f.identifier == field.identifier:
            break
        el = get_field_encoded_len(f, package_specs)
        used_space = used_space + el
    available_space = 255 - used_space
    if field.type_id == "string":
        return available_space
    elem_size = get_encoded_len_value(
        get_v4_typename(field.options["fill"].value), package_specs
    )
    return int(available_space / elem_size)


def get_bitfield_basename(msg, item):
    bitfield_name = item.get("desc", "").replace(" ", "_").upper()
    base_string = "SBP_{}_{}".format(msg.upper().replace("MSG_", ""), bitfield_name)
    base_string = re.sub("[^A-Za-z0-9_]+", "", base_string)
    return base_string


def create_bitfield_macros(field, msg):
    ret_list = []
    for item in field.options["fields"].value:
        base_string = get_bitfield_basename(msg, item)
        if not base_string.endswith("RESERVED"):
            nbits = item.get("len")
            bitrange = (item.get("range")).split(":")
            start_bit = int(bitrange[0])
            ret_list.append(
                "#define {}_MASK ({})".format(base_string, hex((1 << nbits) - 1))
            )
            ret_list.append("#define {}_SHIFT ({}u)".format(base_string, start_bit))
            ret_list.append(
                """#define {}_GET(flags) \\
                             (((flags) >> {}_SHIFT) \\
                             & {}_MASK)""".format(
                    base_string, base_string, base_string
                )
            )
            ret_list.append(
                """#define {}_SET(flags, val) \\
                             do {{((flags) |= \\
                             (((val) & ({}_MASK)) \\
                             << ({}_SHIFT)));}} while(0)
                             """.format(
                    base_string, base_string, base_string
                )
            )
            ret_list.append("")
            for value_obj in item.get("vals", []):
                value_numerical = int(value_obj.get("value"))
                value_description = value_obj.get("desc", None).upper()
                value_description = re.sub(r"\([^)]*\)", "", value_description)
                value_description = re.sub("[ \-]+", "_", value_description.strip())
                value_description = re.sub("[^A-Za-z0-9_]+", "", value_description)
                if value_description and value_description.upper() != "RESERVED":
                    ret_list.append(
                        "#define {}_{} ({})".format(
                            base_string, value_description, value_numerical
                        )
                    )
    return "\n".join(ret_list)


def extensions(includes):
    """Format a list of header files to include."""
    return [
        "".join([i.split(".")[0], ".h"]) for i in includes if i.split(".")[0] != "types"
    ]


class FieldItem(object):
    """
    Describes a single field in a message or embedded type
    """

    def __init__(self, msg, package_specs, field):
        self.name = field.identifier
        type_id = field.type_id

        self.units = field.units
        self.desc = field.desc
        self.fn_prefix = get_v4_basename(msg.identifier) + "_" + field.identifier

        if type_id == "string" and "size" in field.options:
            self.packing = "fixed-array"
            self.basetype = "char"
            self.encode_fn = get_internal_encode_fn(self.basetype)
            self.decode_fn = get_internal_decode_fn(self.basetype)
            self.encoded_len_macro = get_encoded_len_macro(self.basetype)
            self.encoded_len_value = get_encoded_len_value(self.basetype, package_specs)
            self.cmp_fn = get_cmp_fn(self.basetype)
            self.max_items = field.options["size"].value
            self.is_fixed_size = True
            self.options = field.options
        elif type_id == "string" or "encoding" in field.options:
            self.packing = "packed-string"
            self.basetype = "char"
            self.max_items = get_max_possible_items(msg, field, package_specs)
            self.options = field.options
            self.encoding = field.options["encoding"].value
            self.is_fixed_size = False
        elif type_id == "array" and "size" in field.options:
            self.packing = "fixed-array"
            self.basetype_from_spec = field.options["fill"].value
            self.basetype = get_v4_typename(field.options["fill"].value)
            self.encode_fn = get_internal_encode_fn(self.basetype)
            self.decode_fn = get_internal_decode_fn(self.basetype)
            self.cmp_fn = get_cmp_fn(self.basetype)
            self.encoded_len_macro = get_encoded_len_macro(self.basetype)
            self.encoded_len_value = get_encoded_len_value(self.basetype, package_specs)
            self.is_fixed_size = True
            self.max_items = field.options["size"].value
            self.options = field.options
        elif type_id == "array":
            self.packing = "variable-array"
            self.basetype_from_spec = field.options["fill"].value
            self.basetype = get_v4_typename(field.options["fill"].value)
            self.encode_fn = get_internal_encode_fn(self.basetype)
            self.decode_fn = get_internal_decode_fn(self.basetype)
            self.cmp_fn = get_cmp_fn(self.basetype)
            self.encoded_len_macro = get_encoded_len_macro(self.basetype)
            self.encoded_len_value = get_encoded_len_value(self.basetype, package_specs)
            self.is_fixed_size = False
            self.max_items = get_max_possible_items(msg, field, package_specs)
            if "size_fn" in field.options:
                self.size_fn = field.options["size_fn"].value
                self.generate_size_fn = False
            else:
                self.size_fn = "n_" + self.name
                self.generate_size_fn = True
            self.options = field.options
        else:
            self.packing = "single"
            self.basetype_from_spec = type_id
            self.basetype = get_v4_typename(type_id)
            self.encode_fn = get_internal_encode_fn(self.basetype)
            self.decode_fn = get_internal_decode_fn(self.basetype)
            self.cmp_fn = get_cmp_fn(self.basetype)
            self.encoded_len_macro = get_encoded_len_macro(self.basetype)
            self.encoded_len_value = get_encoded_len_value(self.basetype, package_specs)
            self.is_fixed_size = True
            self.max_items = 1
            self.options = field.options


def find_package(package_specs, type_id):
    """
    Find the SBP package which defined type_id
    """
    for p in package_specs:
        for m in p.definitions:
            if m.identifier == type_id:
                return p.identifier.split(".", 2)[2]
    raise Exception("Can't find package for type %s" % type_id)


class MsgItem(object):
    """
    Describes a single SBP message or embedded type.

    Contains all the information required to generate C bindings
    """

    def __init__(self, msg, package_specs):
        self.name = msg.identifier
        self.basename = get_v4_basename(msg.identifier)
        self.type_name = get_v4_typename(msg.identifier)
        self.is_real_message = msg.is_real_message
        if self.is_real_message:
            self.v4_msg_type = get_v4_msg_type(msg.identifier)
            self.legacy_msg_type = get_legacy_msg_type(msg.identifier)
            self.union_member_name = get_union_member_name(msg.identifier)
            self.send_fn = get_send_fn(self.type_name)
        self.encoded_len_macro = get_encoded_len_macro(self.type_name)
        self.encoded_len_value = get_encoded_len_value(self.type_name, package_specs)
        self.public_encode_fn = get_public_encode_fn(self.type_name)
        self.public_decode_fn = get_public_decode_fn(self.type_name)
        self.cmp_fn = get_cmp_fn(self.type_name)
        self.encoded_len_fn = get_encoded_len_fn(self.type_name)
        self.internal_encode_fn = get_internal_encode_fn(self.type_name)
        self.internal_decode_fn = get_internal_decode_fn(self.type_name)
        self.sbp_id = msg.sbp_id
        self.desc = msg.desc
        self.short_desc = msg.short_desc
        self.fields = []
        self.sibling_include = []
        self.is_fixed_size = True
        for f in msg.fields:
            new_field = FieldItem(msg, package_specs, f)
            if not new_field.is_fixed_size:
                self.is_fixed_size = False
                if not self.is_real_message:
                    raise Exception(
                        "Field %s in message %s: variable length arrays can only exist in real messages, not in embedded types"
                        % (new_field.name, msg.identifier)
                    )
            self.fields.append(new_field)
            if new_field.basetype not in PRIMITIVE_TYPES:
                self.sibling_include.append(
                    find_package(package_specs, new_field.basetype_from_spec)
                    + "/"
                    + new_field.basetype_from_spec
                )


JENV.filters["commentify"] = commentify
JENV.filters["sanitise_path"] = sanitise_path
JENV.filters["create_bitfield_macros"] = create_bitfield_macros


def render_file(template, destination_filename, args):
    """
    Render a file using specific arguments
    """
    py_template = JENV.get_template(template)
    with open(destination_filename, "w") as f:
        f.write(py_template.render(**args))


def render_all(include_dir, package_specs):
    real_messages = []
    all_packages = []
    msg_msgid_len = 0
    for package_spec in package_specs:
        msgs = []
        msg_msgid_len = package_spec.max_msgid_len
        if not package_spec.render_source:
            continue
        name = package_spec.identifier.split(".", 2)[2]
        if name == "types" or name == "base":
            continue
        all_packages.append(name)
        for m in package_spec.definitions:
            new_msg = MsgItem(m, package_specs)
            msgs.append(new_msg)
            if m.is_real_message:
                real_messages.append(new_msg)
            destination_filename = "%s/include/libsbp/v4/%s/%s.h" % (
                include_dir,
                name,
                new_msg.name,
            )
            render_file(
                SBP_MESSAGES_TEMPLATE_NAME,
                destination_filename,
                {
                    "m": new_msg,
                    "pkg_name": name,
                    "filepath": "/".join(package_spec.filepath) + ".yaml",
                    "sibling_include": new_msg.sibling_include,
                },
            )
        destination_filename = "%s/include/libsbp/v4/%s.h" % (include_dir, name)
        render_file(
            SBP_PACKAGE_TEMPLATE_NAME,
            destination_filename,
            {
                "msgs": msgs,
                "pkg_name": name,
                "filepath": "/".join(package_spec.filepath) + ".yaml"
            },
        )
        destination_filename = "%s/include/libsbp/%s_macros.h" % (include_dir, name)
        render_file(
            SBP_MESSAGES_MACROS_TEMPLATE_NAME,
            destination_filename,
            {
                "msgs": msgs,
                "pkg_name": name,
                "filepath": "/".join(package_spec.filepath) + ".yaml"
            },
        )
        destination_filename = "%s/src/v4/%s.c" % (include_dir, name)
        render_file(
            SBP_MESSAGES_SOURCE_TEMPLATE_NAME,
            destination_filename,
            {
                "msgs": msgs,
                "pkg_name": name,
                "filepath": "/".join(package_spec.filepath) + ".yaml"
            },
        )
        destination_filename = "%s/src/include/libsbp/internal/v4/%s.h" % (
            include_dir,
            name,
        )
        render_file(
            SBP_MESSAGES_PRIVATE_HEADER_TEMPLATE_NAME,
            destination_filename,
            {
                "msgs": msgs,
                "pkg_name": name,
                "include": extensions(package_spec.includes),
                "filepath": "/".join(package_spec.filepath) + ".yaml"
            },
        )
    destination_filename = "%s/include/libsbp/v4/sbp_msg.h" % (include_dir)
    render_file(
        SBP_MSG_TEMPLATE_NAME,
        destination_filename,
        {
            "msgs": sorted(real_messages, key=lambda k: k.type_name),
            "include": extensions(all_packages),
            "filename": "/".join(package_spec.filepath) + ".yaml",
        },
    )
    destination_filename = "%s/include/libsbp/cpp/message_traits.h" % include_dir
    render_file(
        MESSAGE_TRAITS_TEMPLATE_NAME,
        destination_filename,
        {
            "packages": package_specs,
            "includes": extensions(all_packages),
            "msgs": sorted(real_messages, key=lambda k: k.type_name)
        },
    )
    destination_filename = "%s/include/libsbp/sbp_msg_type.h" % include_dir
    render_file(
        SBP_MSG_TYPE_TEMPLATE_NAME,
        destination_filename,
        {"msgs": sorted(real_messages, key=lambda k: k.type_name), "packages": all_packages},
    )


def render_version(output_dir, release: ReleaseVersion):
    destination_filename = "%s/include/libsbp/version.h" % output_dir
    py_template = JENV.get_template(VERSION_TEMPLATE_NAME)
    with open(destination_filename, "w") as output_file:
        output_file.write(
            py_template.render(
                major=release.major,
                minor=release.minor,
                patch=release.patch,
                full_version=release.full_version,
            )
        )
