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
Generator for c target.
"""

import re

from jinja2.environment import Environment
from jinja2.utils import pass_environment

from sbpg.targets.templating import JENV, indented_wordwrap
from sbpg import ReleaseVersion

MESSAGES_TEMPLATE_NAME = "sbp_messages_template.h"
VERSION_TEMPLATE_NAME = "sbp_version_template.h"
MESSAGE_TRAITS_TEMPLATE_NAME = "sbp_message_traits_template.h"


@pass_environment
def commentify(environment: Environment,
               value: str):
  """
  Builds a comment.
  """
  return indented_wordwrap(environment, value, indent=" * ", first=True, markdown=True)


@pass_environment
def commentify_field(environment: Environment,
                     value: str,
                     field, message):
  """
  Builds a comment.
  """
  if value is None:
    return
  f_size_len = len(mk_size(field).ljust(message.max_fid_len+4))
  indent = len("  ") + f_size_len + len(" ") + len(mk_id(field)) + len(" /**< ")
  return indented_wordwrap(environment, value, indent=" " * indent, first=False)


def extensions(includes):
  """Formats a list of header files to include.
  """
  return ["".join([i.split(".")[0], ".h"]) for i in includes if i.split(".")[0] != "types"]


CONSTRUCT_CODE = set(['u8', 'u16', 'u32', 'u64', 's8', 's16', 's32',
                      's64', 'float', 'double'])

COLLISIONS = set(['GnssSignal', 'GPSTime'])

def convert(value):
  """Converts to a C language appropriate identifier format.

  """
  s0 = "Sbp" + value if value in COLLISIONS else value
  s1 = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', s0)
  return re.sub('([a-z0-9])([A-Z])', r'\1_\2', s1).lower() + "_t"

def mk_id(field):
  """Builds an identifier from a field.
  """
  name = field.type_id
  if name == "string":
    return "%s" % ("char")
  elif name == "array" and field.size:
    if field.options['fill'].value not in CONSTRUCT_CODE:
      return "%s" % convert(field.options['fill'].value)
    else:
      return "%s" % field.options['fill'].value
  elif name == "array":
    return "%s" % convert(field.options['fill'].value)
  elif name not in CONSTRUCT_CODE:
    return convert(name)
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
          # backwards compatibility
          if base_string in ["SBP_IMU_AUX_GYROSCOPE_RANGE", "SBP_IMU_AUX_ACCELEROMETER_RANGE", "SBP_STARTUP", "SBP_PPS_TIME_TIME_UNCERTAINTY"]:
            ret_list.append("#define {}_{} ({})".format(base_string, value_description,
                                                        value_numerical))
          base_string = re.sub('__+', '_', base_string).strip('_')
          value_description = re.sub('__+', '_', value_description).strip('_')
          ret_list.append("#define {}_{} ({})".format(base_string, value_description,
                                                      value_numerical))
  return "\n".join(ret_list)

JENV.filters['commentify'] = commentify
JENV.filters['commentify_field'] = commentify_field
JENV.filters['mk_id'] = mk_id
JENV.filters['mk_size'] = mk_size
JENV.filters['convert'] = convert
JENV.filters['create_bitfield_macros'] = create_bitfield_macros

def render_source(output_dir, package_spec):
  """
  Render and output to a directory given a package specification.
  """
  path, name = package_spec.filepath
  destination_filename = "%s/%s.h" % (output_dir, name)
  py_template = JENV.get_template(MESSAGES_TEMPLATE_NAME)
  with open(destination_filename, 'w') as f:
    f.write(py_template.render(msgs=package_spec.definitions,
                               pkg_name=name,
                               filepath="/".join(package_spec.filepath) + ".yaml",
                               max_msgid_len=package_spec.max_msgid_len,
                               description=package_spec.description,
                               timestamp=package_spec.creation_timestamp,
                               include=extensions(package_spec.includes)))

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
