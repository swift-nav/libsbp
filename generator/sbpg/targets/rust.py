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

from sbpg.targets.templating import JENV, ACRONYMS, indented_wordwrap
from sbpg import ReleaseVersion

SBP_CARGO_TEMPLATE = "sbp-cargo.toml"
SBP2JSON_CARGO_TEMPLATE = "sbp2json-cargo.toml"

MESSAGES_TEMPLATE_NAME = "sbp_messages_template.rs"
MESSAGES_MOD_TEMPLATE_NAME = "sbp_messages_mod.rs"

GPS_TIME = """
let tow_s = (self.tow as f64) / 1000.0;
let wn = match i16::try_from(self.wn) {
    Ok(wn) => wn,
    Err(e) => return Some(Err(e.into())),
};
let gps_time = match crate::time::GpsTime::new(wn, tow_s) {
    Ok(gps_time) => gps_time,
    Err(e) => return Some(Err(e.into())),
};
""".strip()
GPS_TIME_HEADER = """
let tow_s = (self.header.t.tow as f64) / 1000.0;
let wn = match i16::try_from(self.header.t.wn) {
    Ok(wn) => wn,
    Err(e) => return Some(Err(e.into())),
};
let gps_time = match crate::time::GpsTime::new(wn, tow_s) {
    Ok(gps_time) => gps_time,
    Err(e) => return Some(Err(e.into())),
};
""".strip()
GPS_TIME_ONLY_TOW = """
let tow_s = (self.tow as f64) / 1000.0;
let gps_time = match crate::time::GpsTime::new(0, tow_s) {
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
let gps_time = match crate::time::GpsTime::new(0, tow_s) {
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
let gps_time = match crate::time::GpsTime::new(0, tow_s) {
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
  if '_' not in s: return s
  s = re.sub('([a-z])([A-Z])', r'\1_\2', s)
  return ''.join(w if w in ACRONYMS else w.title() for w in s.split('_'))

@pass_environment
def commentify(environment: Environment,
               value: str,
               indent: int=0,
               prefix: str="/// "):
  """
  Builds a comment.
  """
  return indented_wordwrap(environment, value, indent=(" " * indent) + prefix, first=False, markdown=True)

TYPE_MAP = {'u8': 'u8',
            'u16': 'u16',
            'u32': 'u32',
            'u64': 'u64',
            's8': 'i8',
            's16': 'i16',
            's32': 'i32',
            's64': 'i64',
            'float': 'f32',
            'double': 'f64',
            'string': 'SbpString'}

def type_map(field):
  if field.type_id in TYPE_MAP:
    return TYPE_MAP[field.type_id]
  elif field.type_id == 'array':
    t = field.options['fill'].value
    return "Vec<{}>".format(TYPE_MAP.get(t, t))
  else:
    return field.type_id

def mod_name(x):
    return x.split('.', 2)[2]

def parse_type(field):
  """
  Function to pull a type from the binary payload.
  """
  if field.type_id == 'string':
    if 'size' in field.options:
      return "crate::parser::read_string_limit(_buf, %s)" % field.options['size'].value
    else:
      return "crate::parser::read_string(_buf)"
  elif field.type_id == 'u8':
    return '_buf.read_u8()'
  elif field.type_id == 's8':
    return '_buf.read_i8()'
  elif field.type_id in TYPE_MAP.keys():
    # Primitive java types have extractor methods in SBPMessage.Parser
    return '_buf.read_%s::<LittleEndian>()' % TYPE_MAP[field.type_id]
  if field.type_id == 'array':
    # Call function to build array
    t = field.options['fill'].value
    if t in TYPE_MAP.keys():
      if 'size' in field.options:
        return 'crate::parser::read_%s_array_limit(_buf, %d)' % (t, field.options['size'].value)
      else:
        return 'crate::parser::read_%s_array(_buf)' % t
    else:
      if 'size' in field.options:
        return '%s::parse_array_limit(_buf, %d)' % (t, field.options['size'].value)
      else:
        return '%s::parse_array(_buf)' % t
  else:
    # This is an inner class, call default constructor
    return "%s::parse(_buf)" % field.type_id

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
        return f"Some(Ok(crate::time::MessageTime::{name}(gps_time.into())))"

    body = gen_body()
    if body is None:
        return ""

    ret = gen_ret()

    return f"""
  #[cfg(feature = "swiftnav-rs")]
  fn gps_time(&self) -> Option<std::result::Result<crate::time::MessageTime, crate::time::GpsTimeError>> {{
      {body}
      {ret}
  }}
  """.strip()

JENV.filters['camel_case'] = camel_case
JENV.filters['commentify'] = commentify
JENV.filters['type_map'] = type_map
JENV.filters['mod_name'] = mod_name
JENV.filters['parse_type'] = parse_type
JENV.filters['gps_time'] = gps_time

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
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(release=release.full_version))
