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

TO_GNSS = {
    "MSG_GPS_TIME" : "MSG_GPS_TIME_GNSS",
    "MSG_UTC_TIME" : "MSG_UTC_TIME_GNSS",
    "MSG_POS_LLH" : "MSG_POS_LLH_GNSS",
    "MSG_POS_ECEF" : "MSG_POS_ECEF_GNSS",
    "MSG_VEL_NED" : "MSG_VEL_NED_GNSS",
    "MSG_VEL_ECEF" : "MSG_VEL_ECEF_GNSS",
    "MSG_POS_ECEF_COV" : "MSG_POS_ECEF_COV_GNSS",
    "MSG_VEL_ECEF_COV" : "MSG_VEL_ECEF_COV_GNSS",
    "MSG_POS_LLH_COV" : "MSG_POS_LLH_COV_GNSS",
    "MSG_VEL_NED_COV" : "MSG_VEL_NED_COV_GNSS"
    }

TO_NON_GNSS = {v: k for k, v in TO_GNSS.items()}

COLLISIONS = set(["GnssSignal", "GPSTime"])


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
    s2 = "sbp_v4_" + s1 if identifier in COLLISIONS else "sbp_" + s1
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


def get_legacy_typename(identifier):
    """
    Convert an SBP spec identifier in to the correct typename according to the legacy API
    """
    typename = get_v4_typename(identifier)
    if typename[:7] == "sbp_v4_":
        return "sbp_" + typename[7:]
    assert typename[:4] == "sbp_"
    return typename[4:]


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


def get_encoded_len_macro(typename, is_fixed_size):
    """
    Get the macro name which specified the encoded length of a given type
    """
    if typename in PRIMITIVE_TYPES:
        return "SBP_ENCODED_LEN_" + typename.upper()
    assert typename[-2:] == "_t"
    if is_fixed_size:
        return typename[:-2].upper() + "_ENCODED_LEN"
    return typename[:-2].upper() + "_ENCODED_OVERHEAD"


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


def get_max_possible_items_macro(msg, field):
    """
    Get the name of the macro which will define the maximum number of items that can be stored in a field
    """
    assert field.type_id == "array" or field.type_id == "string"
    macro_name = get_v4_basename(msg.identifier)
    if macro_name[:7] == "sbp_v4_":
        macro_name = "sbp_" + macro_name[7:]
    macro_name = macro_name + "_" + field.identifier + "_MAX"
    return macro_name.upper()


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
                "#define {}_MASK ({}u)".format(base_string, hex((1 << nbits) - 1))
            )
            ret_list.append("#define {}_SHIFT ({}u)".format(base_string, start_bit))
            ret_list.append(
                """#define {}_GET(flags) \\
                             (({})(({})((flags) >> {}_SHIFT) \\
                             & {}_MASK))""".format(
                    base_string, field.basetype, field.basetype, base_string, base_string
                )
            )
            ret_list.append(
                """#define {}_SET(flags, val) \\
                             do {{(flags) = ({})((flags & (~({}_MASK << {}_SHIFT))) | \\
                             (((val) & ({}_MASK)) \\
                             << ({}_SHIFT)));}} while(0)
                             """.format(
                    base_string, field.basetype, base_string, base_string, base_string, base_string
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
                    # backwards compatibility
                    if base_string in [
                        "SBP_IMU_AUX_GYROSCOPE_RANGE",
                        "SBP_IMU_AUX_ACCELEROMETER_RANGE",
                        "SBP_STARTUP",
                        "SBP_PPS_TIME_TIME_UNCERTAINTY",
                    ]:
                        ret_list.append(
                            "#define {}_{} ({})".format(
                                base_string, value_description, value_numerical
                            )
                        )
                    base_string = re.sub("__+", "_", base_string).strip("_")
                    value_description = re.sub("__+", "_", value_description).strip("_")
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
            self.is_fixed_size = True
            self.encode_fn = get_internal_encode_fn(self.basetype)
            self.decode_fn = get_internal_decode_fn(self.basetype)
            self.encoded_len_macro = get_encoded_len_macro(self.basetype, True)
            self.encoded_len_value = get_encoded_len_value(self.basetype, package_specs)
            self.cmp_fn = get_cmp_fn(self.basetype)
            self.max_items = field.options["size"].value
            self.max_items_macro = get_max_possible_items_macro(msg, field)
            self.options = field.options
        elif type_id == "string" or "encoding" in field.options:
            self.packing = "packed-string"
            self.basetype = "char"
            self.max_items = get_max_possible_items(msg, field, package_specs)
            self.max_items_macro = get_max_possible_items_macro(msg, field)
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
            self.is_fixed_size = True
            self.encoded_len_macro = get_encoded_len_macro(self.basetype, True)
            self.encoded_len_value = get_encoded_len_value(self.basetype, package_specs)
            self.max_items = field.options["size"].value
            self.max_items_macro = get_max_possible_items_macro(msg, field)
            self.options = field.options
        elif type_id == "array":
            self.packing = "variable-array"
            self.basetype_from_spec = field.options["fill"].value
            self.basetype = get_v4_typename(field.options["fill"].value)
            self.encode_fn = get_internal_encode_fn(self.basetype)
            self.decode_fn = get_internal_decode_fn(self.basetype)
            self.cmp_fn = get_cmp_fn(self.basetype)
            self.is_fixed_size = False
            self.encoded_len_macro = get_encoded_len_macro(self.basetype, True)
            self.encoded_len_value = get_encoded_len_value(self.basetype, package_specs)
            self.max_items = get_max_possible_items(msg, field, package_specs)
            self.max_items_macro = get_max_possible_items_macro(msg, field)
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
            self.is_fixed_size = True
            self.encoded_len_macro = get_encoded_len_macro(self.basetype, True)
            self.encoded_len_value = get_encoded_len_value(self.basetype, package_specs)
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

    A message is a single type definition from an SBP YAML spec file. It contains
    all information required to generate the C source and headers related to a
    single type.
    """

    def __init__(self, msg, package, package_specs):
        self.name = msg.identifier
        self.basename = get_v4_basename(msg.identifier)
        self.type_name = get_v4_typename(msg.identifier)
        self.legacy_type_name = get_legacy_typename(msg.identifier)
        self.is_real_message = msg.is_real_message
        self.package_name = package.name
        self.package_filepath = package.filepath
        self.package_includes = package.includes
        if self.is_real_message:
            self.v4_msg_type = get_v4_msg_type(msg.identifier)
            self.legacy_msg_type = get_legacy_msg_type(msg.identifier)
            self.union_member_name = get_union_member_name(msg.identifier)
            self.send_fn = get_send_fn(self.type_name)
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
        self.type_include = []
        self.is_fixed_size = True
        self.gnss_type_name = ""
        self.non_gnss_type_name = ""
        self.return_union_member_name = ""
        if self.name in TO_GNSS:
            self.gnss_type_name = get_v4_typename(TO_GNSS[self.name])
            self.return_union_member_name = get_union_member_name(TO_GNSS[self.name])
        if self.name in TO_NON_GNSS:
            self.non_gnss_type_name = get_v4_typename(TO_NON_GNSS[self.name])
            self.return_union_member_name = get_union_member_name(TO_NON_GNSS[self.name])
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
                self.type_include.append(
                    find_package(package_specs, new_field.basetype_from_spec)
                    + "/"
                    + new_field.basetype_from_spec
                )
        self.encoded_len_macro = get_encoded_len_macro(
            self.type_name, self.is_fixed_size
        )
        self.encoded_len_value = get_encoded_len_value(self.type_name, package_specs)

    def render(self, output_dir):
        # Public header for V4 API - include/libsbp/v4/<package>/<type>.h
        destination_filename = "%s/include/libsbp/v4/%s/%s.h" % (
            output_dir,
            self.package_name,
            self.name,
        )
        render_file(
            SBP_MESSAGES_TEMPLATE_NAME,
            destination_filename,
            {
                "m": self,
            },
        )


class PackageItem(object):
    """
    Described an SBP package

    A package is a collection of SBP types defined by a single YAML input. Each type
    from the SBP is represented as an instance of MsgItem
    """

    def __init__(self, package, package_specs):
        self.identifier = package.identifier
        self.name = package.identifier.split(".", 2)[2]
        if self.name == "types" or self.name == "base":
            return
        self.filepath = "/".join(package.filepath) + ".yaml"
        self.includes = [i.split(".")[0] for i in package.includes if i != "types.yaml"]
        self.msgs = []
        for msg_spec in package.definitions:
            new_msg = MsgItem(msg_spec, self, package_specs)
            self.msgs.append(new_msg)

    def render(self, output_dir):
        # Public headers for all types in this package
        for m in self.msgs:
            m.render(output_dir)

        # Public header for the package - include/libsbp/v4/<package>.h
        # Includes all public message headers, include/libsbp/v4/<package>/*.h
        destination_filename = "%s/include/libsbp/v4/%s.h" % (output_dir, self.name)
        render_file(
            SBP_PACKAGE_TEMPLATE_NAME,
            destination_filename,
            {
                "package": self,
            },
        )

        # Public macros header - include/libsbp/<package>_macros.h
        # Declares certain symbols shared between legacy and V4 APIs such as
        # message type #define and bitfield macros
        destination_filename = "%s/include/libsbp/%s_macros.h" % (output_dir, self.name)
        render_file(
            SBP_MESSAGES_MACROS_TEMPLATE_NAME,
            destination_filename,
            {
                "package": self,
            },
        )

        # Internal header for the package - src/include/libsbp/internal/v4/<package>.h
        # Declares internal encode/decode functions for all types defined in this package
        destination_filename = "%s/src/include/libsbp/internal/v4/%s.h" % (
            output_dir,
            self.name,
        )
        render_file(
            SBP_MESSAGES_PRIVATE_HEADER_TEMPLATE_NAME,
            destination_filename,
            {
                "package": self,
            },
        )

        # Source for for the package - src/v4/<package>.h
        # Implements internal and public encode/decode functions for all types defined in this package
        destination_filename = "%s/src/v4/%s.c" % (output_dir, self.name)
        render_file(
            SBP_MESSAGES_SOURCE_TEMPLATE_NAME,
            destination_filename,
            {
                "package": self,
            },
        )


JENV.filters["commentify"] = commentify
JENV.filters["create_bitfield_macros"] = create_bitfield_macros


def render_file(template, destination_filename, args):
    """
    Render a file using specific arguments
    """
    py_template = JENV.get_template(template)
    with open(destination_filename, "w") as f:
        f.write(py_template.render(**args))


def render_all(output_dir, package_specs):
    real_messages = []
    all_packages = []

    for package_spec in package_specs:
        new_package = PackageItem(package_spec, package_specs)
        if new_package.name == "types" or new_package.name == "base":
            continue
        all_packages.append(new_package)
        for m in new_package.msgs:
            if m.is_real_message:
                real_messages.append(m)

    real_messages = sorted(real_messages, key=lambda k: k.type_name)

    # Built the entire schema, now render everything
    for p in all_packages:
        p.render(output_dir)

    # Render sbp_msg_t type, union of all real messages in V4 API
    destination_filename = "%s/include/libsbp/v4/sbp_msg.h" % (output_dir)
    render_file(
        SBP_MSG_TEMPLATE_NAME,
        destination_filename,
        {
            "real_messages": real_messages,
            "packages": all_packages,
        },
    )

    # Render sbp_msg_type_t type, V4 message type enum
    destination_filename = "%s/include/libsbp/sbp_msg_type.h" % (output_dir)
    render_file(
        SBP_MSG_TYPE_TEMPLATE_NAME,
        destination_filename,
        {
            "real_messages": real_messages,
            "packages": all_packages,
        },
    )

    # C++ message traits for V4 API
    destination_filename = "%s/include/libsbp/cpp/message_traits.h" % (output_dir)
    render_file(
        MESSAGE_TRAITS_TEMPLATE_NAME,
        destination_filename,
        {
            "packages": all_packages,
            "real_messages": real_messages,
        },
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
                is_staging=release.is_staging,
            )
        )
