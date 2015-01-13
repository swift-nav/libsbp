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

"""
Defines a really basic syntax declaration for a collection of SBP
messages.

"""


class PackageSpecification(object):
  """
  Package is a collection of messages and types to generate code for.
  """

  def __init__(self, identifier=None,
               description=None, includes=[], definitions=[]):
    self.identifer = identifier
    self.description = description
    self.include = include
    self.definitions = definitions


class Dependency(object):
  """
  Container for package dependencies, at this point, basic links to
  other packages.

  """

  def __init__(self, includes=[]):
    self.includes = includes


class Definition(object):
  """
  """

  def __init__(self, identifier=None
               sbp_id=None, short_desc=None, desc=None, type_id=None,
               fields=[]):
    self.identifer = identifer
    self.sbp_id = sbp_id
    self.short_desc = short_desc
    self.desc = desc
    self.type_id = type_id
    self.fields = fields


class FieldOption(object):
  """

  """

  def __init__(self):
    pass


class Field(object):
  """
  Field is
  """

  def __init__(self, identifier=None,
               units=None, type_id=None, desc=None, map_by=None, fill=None,
               size=None, size_fn=None, fields=[]):
    self.identifier = identifier
    self.units = units
    self.type_id = type_id
    self.desc = desc
    self.map_by = map_by
    self.fill = fill
    self.size = size
    self.size_fn = size_fn
    self.fields = fields

# Accessible primitive types
prim_types = Enum(['bool', 'float', 'double', 'uint8',
                   'uint16', 'uint32', 'int8', 'int16', 'int32'])


class Primitive(Field):
  """
  Primitive field. Typically, one of:
  'bool', 'float', 'double', 'uint8',
  'uint16', 'uint32', 'int8', 'int16', 'int32'

  """

  def __init__(self, name):
    super(Primitive, self).__init__(123)
    pass


class Array(Field):
  """
  Array of primitives.


  """

  def __init__(self, name=None, size=0, size_fn=None):
    assert not (size and size_fn), ""
    super(Array, self).__init__()
    self.size = size
    self.size_fn = size_rn


class BitField(Field):
  """
  Bitfield encoded in a primitive type.

  """

  def __init__(self, bitmask=None, units=None, values=None, desc=None):
    super(Array, self).__init__()
    self.bitmask = bitmask
    self.units = units
    self.values = values
    self.desc = desc
