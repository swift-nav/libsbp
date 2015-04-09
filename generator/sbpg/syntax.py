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

from sbpg.utils import fmt_repr, rejig_bitfields
import datetime

##############################################################################
#

class PackageSpecification(object):
  """Package is a collection of messages and types to generate code
  for.

  """

  def __init__(self, identifier=None, description=None, includes=[],
               definitions=[], render_source=True, stable=False, public=False):
    self.identifier = identifier
    self.description = description
    self.includes = includes
    self.definitions = definitions
    self.render_source = render_source
    self.stable = stable
    self.public = public
    self.creation_timestamp = str(datetime.datetime.now())

  @property
  def filepath(self):
    """
    """
    split = self.identifier.split(".")
    filepath, filename = "/".join(split[:-1]), split[-1]
    return (filepath, filename)

  @property
  def max_msgid_len(self):
    return max([0] + [len(d.identifier) for d in self.definitions if is_message(d)])

  def __repr__(self):
    return fmt_repr(self)


class Dependency(object):
  """Container for package dependencies, at this point, basic links to
  other packages.

  """

  def __init__(self, includes=[]):
    self.includes = includes

  def __repr__(self):
    return fmt_repr(self)


class Definition(object):
  def __init__(self, identifier=None,
               sbp_id=None, short_desc=None, desc=None, type_id=None,
               fields=[], public=False):
    self.identifier = identifier
    self.sbp_id = sbp_id
    self.short_desc = short_desc
    self.desc = desc
    self.type_id = type_id
    self.fields = fields
    self.public = public
    self.static = True

  @property
  def max_type_len(self):
    return max([0]+[len(f.type_id) for f in self.fields])

  @property
  def max_fid_len(self):
    return max([0]+[len(f.identifier) for f in self.fields])

  def __repr__(self):
    return fmt_repr(self)

class FieldOption(object):
  def __init__(self, identifier, value):
    self.identifier = identifier
    self.value = value

  def __repr__(self):
    return "<Field Option: %s=%s>" % (self.identifier, self.value)

class Field(object):
  def __init__(self, identifier=None, type_id=None, options={}):
    self.identifier = identifier
    self.type_id = type_id
    self.options = dict([(k, FieldOption(k, v)) for k, v in options.items()])

  @property
  def desc(self):
    if self.options.get('desc', None):
      return self.options['desc'].value
    else:
      return None

  @property
  def units(self):
    if self.options.get('units', None):
      return self.options['units'].value
    else:
      return None

  def __repr__(self):
    return fmt_repr(self)

##############################################################################
#

class Message(Definition):
  def __init__(self, defn):
    self.__dict__.update(defn.__dict__)

  @property
  def static(self):
    return True

  def __repr__(self):
    return fmt_repr(self)

class Struct(Definition):
  def __init__(self, defn):
    self.__dict__.update(defn.__dict__)

  @property
  def static(self):
    return True

  def __repr__(self):
    return fmt_repr(self)

class Primitive(Definition):
  def __init__(self, defn):
    self.__dict__.update(defn.__dict__)

  def __repr__(self):
    return fmt_repr(self)

class Array(Field):
  def __init__(self, defn):
    self.__dict__.update(defn.__dict__)

  @property
  def size(self):
    return self.options['fill'].value

  @property
  def static(self):
    return

  def __repr__(self):
    return fmt_repr(self)

class BitField(Field):
  def __init__(self, defn):
    self.__dict__.update(defn.__dict__)
    self.options['fields'].value, n = rejig_bitfields(self.options['fields'].value)
    self.options['n_with_values'].value = n

  @property
  def static(self):
    return True

  def __repr__(self):
    return fmt_repr(self)

class Literal(Field):
  def __init__(self, defn):
    self.__dict__.update(defn.__dict__)

  @property
  def static(self):
    return

  def __repr__(self):
    return fmt_repr(self)

##############################################################################
#

def is_message(obj):
  return isinstance(obj, Definition) and getattr(obj, 'sbp_id', None)

def is_struct(obj):
  return not is_message(obj) and not is_primitive(obj) and not isinstance(obj, Field)

def is_primitive(obj):
  return isinstance(obj, Definition) and (getattr(obj, 'type_id', None) == 'primitive')

def is_array(obj):
  return isinstance(obj, Field) and obj.type_id == 'array'

def is_bitfield(obj):
  return isinstance(obj, Field) and obj.options.get('fields', [])

def is_field(obj):
  return isinstance(obj, Field)

def resolve_type(defn):
  if not defn:
    return None
  if is_primitive(defn):
    return Primitive(defn)
  elif is_message(defn):
    return Message(defn)
  elif is_struct(defn):
    return Struct(defn)
  elif is_array(defn):
    return Array(defn)
  elif is_bitfield(defn):
    return BitField(defn)
  elif is_field(defn):
    return defn
  else:
    raise Exception("Problem!")
