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

SBP_CARGO_TEMPLATE = "sbp-cargo.toml"
SBP2JSON_CARGO_TEMPLATE = "sbp2json-cargo.toml"

MESSAGES_TEMPLATE_NAME = "sbp_messages_template.rs"
MESSAGES_MOD_TEMPLATE_NAME = "sbp_messages_mod.rs"

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
  if '_' not in s: return lower_acronyms(s)
  s = re.sub('([a-z])([A-Z])', r'\1_\2', s)
  return ''.join(w.title() for w in s.split('_'))

def snake_case(s):
  if "_" in s:
    return "_".join(snake_case(p) for p in s.split('_'))
  if len(s) == 1:
    return s.lower()
  s = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', s)
  return re.sub('([a-z0-9])([A-Z])', r'\1_\2', s).lower()

def lower_acronyms(s):
  acronyms = ACRONYMS + ["GNSS", "IMU"]
  lower_acronyms = LOWER_ACRONYMS + ["Gnss", "Imu"]
  for (i, a) in enumerate(acronyms):
    s = s.replace(a, lower_acronyms[i])
  return s

@pass_environment
def commentify(environment: Environment,
               value: str,
               indent: int=0,
               prefix: str="/// "):
  """
  Builds a comment.
  """
  value = indented_wordwrap(environment, value, indent=(" " * indent) + prefix, first=False, markdown=True)
  value = wrap_urls(value)
  value = escape_braces(value)
  return value

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

TYPE_MAP = {'u8': 'u8',
            'u16': 'u16',
            'u32': 'u32',
            'u64': 'u64',
            's8': 'i8',
            's16': 'i16',
            's32': 'i32',
            's64': 'i64',
            'float': 'f32',
            'double': 'f64'}

def type_map(field):
  if field.type_id in TYPE_MAP:
    return TYPE_MAP[field.type_id]

  if field.type_id == 'array':
    t = field.options['fill'].value
    if 'size' in field.options:
      return "[{}; {}]".format(TYPE_MAP.get(t, t), field.options['size'].value)
    else:
      return "Vec<{}>".format(TYPE_MAP.get(t, t))

  if field.type_id == "string":
    if 'encoding' in field.options:
      e = field.options['encoding'].value
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
    if 'size' in field.options:
      return "SbpString<[u8; {}], {}>".format(field.options['size'].value, encoding)
    else:
      return "SbpString<Vec<u8>, {}>".format(encoding)

  return lower_acronyms(field.type_id)

def mod_name(x):
    return x.split('.', 2)[2]

def gps_time(msg, all_messages):
    def time_aware_header(type_id):
        for m in all_messages:
            if m.identifier == type_id:
                return any([f.identifier == "t" for f in m.fields])
        return False

    def gen_body():
        if msg.identifier in CUSTOM_GPS_TIME_MSGS:
          return CUSTOM_GPS_TIME_MSGS[msg.identifier]

        header = False
        tow = False
        wn = False

        for f in msg.fields:
            if f.identifier == "header" and time_aware_header(f.type_id):
                header = True
            elif f.identifier == "tow":
                assert f.units == "ms"
                tow = True
            elif f.identifier == "wn":
                wn = True

        if header:
            return GPS_TIME_HEADER
        elif tow and wn:
            return GPS_TIME
        elif tow:
            return GPS_TIME_ONLY_TOW
        else:
            return None

    def gen_ret():
        name = "Base" if msg.identifier in BASE_TIME_MSGS else "Rover"
        return f"Some(Ok(time::MessageTime::{name}(gps_time.into())))"

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


JENV.filters['camel_case'] = camel_case
JENV.filters['commentify'] = commentify
JENV.filters['type_map'] = type_map
JENV.filters['mod_name'] = mod_name
JENV.filters['gps_time'] = gps_time
JENV.filters['wrap_urls'] = wrap_urls
JENV.filters['snake_case'] = snake_case

def render_source(output_dir, package_spec):
  """
  Render and output to a directory given a package specification.
  """
  _, name = package_spec.filepath
  destination_filename = "%s/sbp/src/messages/%s.rs" % (output_dir, name)
  py_template = JENV.get_template(MESSAGES_TEMPLATE_NAME)
  includes = [x.rsplit('.', 1)[0] for x in package_spec.includes]
  if 'types' in includes:
    del includes[includes.index('types')]
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(msgs=sorted(package_spec.definitions, key=lambda msg: msg.identifier),
                               pkg_name=name,
                               filepath="/".join(package_spec.filepath) + ".yaml",
                               description=package_spec.description,
                               timestamp=package_spec.creation_timestamp,
                               includes=includes))

def render_mod(output_dir, package_specs):
  msgs = []
  mods = []
  for package_spec in package_specs:
    if not package_spec.render_source:
      continue
    name = package_spec.identifier.split('.', 2)[2]
    if name != 'types':
      mods.append(name)
    for m in package_spec.definitions:
      if m.is_real_message:
        msgs.append(m)
  destination_filename = "%s/sbp/src/messages/mod.rs" % output_dir
  py_template = JENV.get_template(MESSAGES_MOD_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(packages=package_specs,
                               mods=mods,
                               msgs=sorted(msgs, key=lambda msg: msg.sbp_id)))


def render_sbp_cargo_toml(output_dir, release: ReleaseVersion):
  destination_filename = "%s/sbp/Cargo.toml" % output_dir
  py_template = JENV.get_template(SBP_CARGO_TEMPLATE)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(release=release.full_version))


def render_sbp2json_cargo_toml(output_dir, release: ReleaseVersion):
  destination_filename = "%s/sbp2json/Cargo.toml" % output_dir
  py_template = JENV.get_template(SBP2JSON_CARGO_TEMPLATE)
  if '-alpha' not in release.full_version:
    version = "%s-unreleased" % (release.full_version,)
  else:
    version = release.full_version
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(release=version))
