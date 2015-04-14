#!/usr/bin/env python
# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Fergus Noble <fergus@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.


"""
Logging and debugging messages from the Piksi. These are in the
implementation-defined range (0x0000-0x00FF).

"""

from construct import *
import json
from sbp import SBP
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/logging.yaml
# with generate.py at 2015-04-14 12:12:07.025289. Please do not hand edit!


SBP_MSG_PRINT = 0x0010
class MsgPrint(SBP):
  """SBP class for message MSG_PRINT (0x0010).

  You can have MSG_PRINT inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message contains a human-reabable payload string from the
Piksi containing errors, warnings and informational messages at
ERROR, WARNING, DEBUG, INFO logging levels. These message may
also contain information tagged by filename, as well as debug
info on function entry/exit when enabled within the firmware.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  text : string
    Informative, human-readable string

  """
  _parser = Struct("MsgPrint",
                   CString('text', six.b('\n')),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      self.text = kwargs.pop('text')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgPrint._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = Container(**exclude_fields(self))
    self.payload = MsgPrint._parser.build(c)
    return self.pack()

  def to_json(self):
    """Produce a JSON-encoded SBP message.

    """
    d = super( MsgPrint, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return json.dumps(d)

  @staticmethod
  def from_json(data):
    """Given a JSON-encoded message, build an object.

    """
    d = json.loads(data)
    sbp = SBP.from_json_dict(d)
    return MsgPrint(sbp)
    
SBP_MSG_DEBUG_VAR = 0x0011
class MsgDebugVar(SBP):
  """SBP class for message MSG_DEBUG_VAR (0x0011).

  You can have MSG_DEBUG_VAR inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This is an unused legacy message for tracing variable values
within the Piksi firmware and streaming those back to the host.


  """

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    

msg_classes = {
  0x0010: MsgPrint,
  0x0011: MsgDebugVar,
}