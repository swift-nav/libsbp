#!/usr/bin/env python
# Copyright (C) 2018-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
Generator for rust target.
"""

from jinja2.environment import Environment
from jinja2.utils import pass_environment

from sbpg.targets.templating import JENV, ACRONYMS, LOWER_ACRONYMS, indented_wordwrap
from sbpg import ReleaseVersion

SBP_CARGO_TEMPLATE = "rust/sbp_cargo.toml"
SBP2JSON_CARGO_TEMPLATE = "rust/sbp2json_cargo.toml"
MESSAGES_TEMPLATE_NAME = "rust/sbp_messages_template.rs"
MESSAGES_MOD_TEMPLATE_NAME = "rust/sbp_messages_mod.rs"


GPS_TIME = """
let tow_s = (self.tow as f64) / 1000.0;
#[allow(clippy::useless_conversion)]
let wn: i16 = match self.wn.try_into() {
    Ok(wn) => wn,
    Err(e) => return Some(Err(e.into())),
};
let gps_time = match time::GpsTime::new(wn, tow_s) {
    Ok(gps_time) => gps_time,
    Err(e) => return Some(Err(e.into())),
};
""".strip()
GPS_TIME_HEADER = """
let tow_s = (self.header.t.tow as f64) / 1000.0;
let wn: i16 = match self.header.t.wn.try_into() {
    Ok(wn) => wn,
    Err(e) => return Some(Err(e.into())),
};
let gps_time = match time::GpsTime::new(wn, tow_s) {
    Ok(gps_time) => gps_time,
    Err(e) => return Some(Err(e.into())),
};
""".strip()
GPS_TIME_ONLY_TOW = """
let tow_s = (self.tow as f64) / 1000.0;
let gps_time = match time::GpsTime::new(0, tow_s) {
    Ok(gps_time) => gps_time.tow(),
    Err(e) => return Some(Err(e.into())),
};
""".strip()

BASE_TIME_MSGS = ["MSG_OBS", "MSG_OSR", "MSG_SSR"]

CUSTOM_GPS_TIME_MSGS = {
    "MSG_IMU_RAW": """
const IMU_RAW_TIME_STATUS_MASK: u32 = (1 << 30) | (1 << 31);
if self.tow & IMU_RAW_TIME_STATUS_MASK != 0 {
    return None;
}
let tow_s = (self.tow as f64) / 1000.0;
let gps_time = match time::GpsTime::new(0, tow_s) {
    Ok(gps_time) => gps_time.tow(),
    Err(e) => return Some(Err(e.into())),
};
""".strip(),
    "MSG_WHEELTICK": """
// only consider wheelticks with synchronization type value "microsec in GPS week"
if self.flags != 1 {
    return None;
}
let tow_s = (self.time as f64) / 1000000.0;
let gps_time = match time::GpsTime::new(0, tow_s) {
    Ok(gps_time) => gps_time.tow(),
    Err(e) => return Some(Err(e.into())),
};
""".strip(),
}

import re


def camel_case(s):
    """
    Makes a classname.
    """
    if "_" not in s:
        if s[0].islower():
            s = s[0].upper() + s[1:]
        return lower_acronyms(s)
    s = re.sub("([a-z])([A-Z])", r"\1_\2", s)
    return "".join(w.title() for w in s.split("_"))


def snake_case(s):
    if "_" in s:
        return "_".join(snake_case(p) for p in s.split("_"))
    if len(s) == 1:
        return s.lower()
    s = re.sub("(.)([A-Z][a-z]+)", r"\1_\2", s)
    return re.sub("([a-z0-9])([A-Z])", r"\1_\2", s).lower()


def camel_case_split(identifier):
    # https://stackoverflow.com/a/29920015
    matches = re.finditer('.+?(?:(?<=[a-z])(?=[A-Z])|(?<=[A-Z])(?=[A-Z][a-z])|$)', identifier)
    return [m.group(0) for m in matches]

def lower_acronyms(s):
    if s.isupper() and s.isalpha():
        return s.title()
    acronyms = ACRONYMS + ["GNSS", "IMU", "GAL", "BDS"]
    lower_acronyms = LOWER_ACRONYMS + ["Gnss", "Imu", "Gal", "Bds"]
    result = []
    for word in camel_case_split(s):
        idx = acronyms.index(word) if word in acronyms else None
        if idx is not None:
            result.append(lower_acronyms[idx])
        else:
            result.append(word)
    return "".join(result)


def wrap_urls(s):
    urls = re.findall(r"\(?https?://[^\s\)]+\)?", s)
    for url in urls:
        if url.startswith("(") and url.endswith(")"):
            continue
        if url.endswith(")"):
            s = s.replace(url, "<" + url[:-1] + ">)")
        else:
            s = s.replace(url, "<" + url + ">")
    return s


def escape_braces(s):
    groups = re.findall(r"(\[[^\]]+\])[^\(]", s)
    for group in groups:
        s = s.replace(group, "\\" + group[:-1] + "\]")
    return s


@pass_environment
def commentify(
    environment: Environment, value: str, indent: int = 0, prefix: str = "/// "
):
    """
    Builds a comment.
    """
    value = indented_wordwrap(
        environment, value, indent=(" " * indent) + prefix, first=False, markdown=True
    )
    value = wrap_urls(value)
    value = escape_braces(value)
    return value


JENV.filters["commentify"] = commentify


TYPE_MAP = {
    "u8": "u8",
    "u16": "u16",
    "u32": "u32",
    "u64": "u64",
    "s8": "i8",
    "s16": "i16",
    "s32": "i32",
    "s64": "i64",
    "float": "f32",
    "double": "f64",
}


def type_map(field):
    if field.type_id in TYPE_MAP:
        return TYPE_MAP[field.type_id]

    if field.type_id == "array":
        t = field.options["fill"].value
        if "size" in field.options:
            return "[{}; {}]".format(TYPE_MAP.get(t, t), field.options["size"].value)
        else:
            return "Vec<{}>".format(TYPE_MAP.get(t, t))

    if field.type_id == "string":
        if "encoding" in field.options:
            e = field.options["encoding"].value
            if e == "unterminated":
                encoding = "Unterminated"
            elif e == "null_terminated":
                encoding = "NullTerminated"
            elif e == "multipart":
                encoding = "Multipart"
            elif e == "double_null_terminated":
                encoding = "DoubleNullTerminated"
        else:
            encoding = "Unterminated"
        if "size" in field.options:
            return "SbpString<[u8; {}], {}>".format(
                field.options["size"].value, encoding
            )
        else:
            return "SbpString<Vec<u8>, {}>".format(encoding)

    return lower_acronyms(field.type_id)


def gps_time_fn(msg):
    def gen_body():
        if msg.identifier in CUSTOM_GPS_TIME_MSGS:
            return CUSTOM_GPS_TIME_MSGS[msg.identifier]
        tow = False
        wn = False
        for f in msg.fields:
            if f.has_gps_time:
                return GPS_TIME_HEADER
            elif f.identifier == "tow":
                assert f.units == "ms"
                tow = True
            elif f.identifier == "wn":
                wn = True
        if tow and wn:
            return GPS_TIME
        elif tow:
            return GPS_TIME_ONLY_TOW
        else:
            return None

    def gen_ret():
        name = "Base" if msg.identifier in BASE_TIME_MSGS else "Rover"
        return f"Some(Ok(time::MessageTime::{name}(gps_time.into())))"

    if not msg.is_real_message:
        return ""
    body = gen_body()
    if body is None:
        return ""
    ret = gen_ret()
    return f"""
  #[cfg(feature = "swiftnav")]
  fn gps_time(&self) -> Option<std::result::Result<time::MessageTime, time::GpsTimeError>> {{
      {body}
      {ret}
  }}
  """.strip()


def get_bitfield_basename(item, field):
    if item.get("desc", False):
        basename = camel_case(item.get("desc", "").replace(" ", "_"))
    else:
        basename = camel_case(field.identifier)
    basename = re.sub("[^A-Za-z0-9_]+", "", basename)
    return basename


def calc_item_size(item, field):
    int_types = [8, 16, 32, 64]
    length = int(item.get("len")) - 1
    for i in int_types:
        if i >= length:
            return f"u{i}"


def get_bitfield_values(item):
    vals = []
    for val in item.get("vals", []):
        name = val.get("desc", None)
        name = re.sub(r"\([^)]*\)", "", name)
        name = re.sub("[ \-]+", "_", name.strip())
        name = re.sub("[^A-Za-z0-9_]+", "", name)
        name = camel_case(name)
        if name.lower() == "reserved":
            continue
        if name[0].isnumeric():
            name = "_" + name
        vals.append(
            {
                "name": name,
                "value": int(val.get("value")),
                "desc": val.get("desc", ""),
            }
        )
    return vals


def get_bitfield(field):
    items = []
    for item in field.options["fields"].value:
        type_name = get_bitfield_basename(item, field)
        if type_name.endswith("Reserved"):
            continue
        vals = get_bitfield_values(item)
        if len(vals) == 0:
            type_name = field.type
        if item.get("desc", False):
            field_name = snake_case(item.get("desc", "").replace(" ", "_"))
            field_name = re.sub("[^A-Za-z0-9_]+", "", field_name)
        else:
            field_name = snake_case(field.identifier)
        field_name = re.sub("__", "_", field_name)
        bitrange = item.get("range").split(":")
        is_bool = False
        if len(bitrange) == 1:
            msb = int(bitrange[0])
            lsb = msb
            is_bool = len(vals) == 0
        else:
            msb = int(bitrange[1])
            lsb = int(bitrange[0])
        items.append(
            {
                "desc": item.get("desc"),
                "field": field.field_name,
                "msb": msb,
                "lsb": lsb,
                "type_name": type_name,
                "type": "bool" if is_bool else calc_item_size(item, field),
                "bitrange_name": field_name,
                "vals": vals,
            }
        )
    return items


class FieldItem(object):
    def __init__(self, msg, package_specs, field):
        self.identifier = field.identifier
        self.type_id = field.type_id
        self.units = field.units
        self.desc = field.desc
        self.options = field.options
        self.field_name = snake_case(self.identifier)
        self.type = type_map(field)
        self.has_gps_time = False
        self.msg = msg
        for pkg in package_specs:
            for m in pkg.definitions:
                if m.identifier == self.type_id and any(
                    f.identifier == "t" for f in m.fields
                ):
                    self.has_gps_time = True
        self.bitfield = []
        if self.options.get("fields", False):
            self.bitfield = get_bitfield(self)


class MsgItem(object):
    def __init__(self, msg, package, package_specs):
        self.msg_name = camel_case(msg.identifier)
        self.parent_mod_name = package.mod_name
        self.mod_name = snake_case(msg.identifier)
        self.identifier = msg.identifier
        self.sbp_id = msg.sbp_id
        self.desc = msg.desc
        self.short_desc = msg.short_desc
        self.is_real_message = msg.is_real_message
        self.fields = []
        self.has_bitfield = False
        for f in msg.fields:
            field = FieldItem(msg, package_specs, f)
            self.fields.append(field)
            if len(field.bitfield) > 0:
                self.has_bitfield = True
        self.gps_time_fn = gps_time_fn(self)


class PackageItem(object):
    def __init__(self, package, package_specs):
        self.identifier = package.identifier
        self.description = package.description
        self.creation_timestamp = package.creation_timestamp
        self.mod_name = package.identifier.split(".", 2)[2]
        self.filepath = package.filepath
        self.includes = [inc.rsplit(".", 1)[0] for inc in package.includes]
        if "types" in self.includes:
            del self.includes[self.includes.index("types")]
        self.msgs = []
        for msg in sorted(package.definitions, key=lambda pkg: pkg.identifier):
            msg = MsgItem(msg, self, package_specs)
            self.msgs.append(msg)


def render_all(output_dir, package_specs, release: ReleaseVersion):
    pkgs = []
    msgs = []
    for package_spec in package_specs:
        if not package_spec.render_source:
            continue
        pkg = PackageItem(package_spec, package_specs)
        if pkg.mod_name == "types" or pkg.mod_name == "base":
            continue
        pkgs.append(pkg)
        for m in pkg.msgs:
            if m.is_real_message:
                msgs.append(m)
    for pkg in pkgs:
        render_file(
            MESSAGES_TEMPLATE_NAME,
            f"{output_dir}/sbp/src/messages/{pkg.mod_name}.rs",
            {
                "msgs": pkg.msgs,
                "filepath": "/".join(pkg.filepath) + ".yaml",
                "description": pkg.description,
                "timestamp": pkg.creation_timestamp,
                "includes": pkg.includes,
            },
        )
    render_file(
        MESSAGES_MOD_TEMPLATE_NAME,
        f"{output_dir}/sbp/src/messages/mod.rs",
        {
            "mods": [pkg.mod_name for pkg in pkgs],
            "msgs": sorted(msgs, key=lambda msg: msg.sbp_id),
        },
    )
    render_file(
        SBP_CARGO_TEMPLATE,
        f"{output_dir}/sbp/Cargo.toml",
        {"release": release.full_version},
    )
    if "-alpha" not in release.full_version:
        version = f"{release.full_version}-unreleased"
    else:
        version = release.full_version
    render_file(
        SBP2JSON_CARGO_TEMPLATE,
        f"{output_dir}/sbp2json/Cargo.toml",
        {"release": version},
    )


def render_file(template, destination_filename, args):
    py_template = JENV.get_template(template)
    with open(destination_filename, "w") as f:
        f.write(py_template.render(**args))
