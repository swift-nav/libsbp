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

from construct import *
from sbp import SBP
from sbp.utils import fmt_repr
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/logging.yaml
# with generate.py at 2015-04-06 23:40:11.124135. Please do not hand edit!


SBP_MSG_PRINT = 0x0010
class MsgPrint(SBP):
  """SBP class for message MSG_PRINT (0x0010).
  
  This message contains a human-reabable payload string from the
Piksi containing errors, warnings and informational messages at
ERROR, WARNING, DEBUG, INFO logging levels. These message may
also contain information tagged by filename, as well as debug
info on function entry/exit when enabled within the firmware.


  Parameters
  ----------
  text : string
    Informative, human-readable string.

  """
  _parser = Struct("MsgPrint",
                   CString('text', six.b('\n')),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgPrint._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgPrint.build(self.__dict__)
    
SBP_MSG_DEBUG_VAR = 0x0011
class MsgDebugVar(SBP):
  """SBP class for message MSG_DEBUG_VAR (0x0011).
  
  This is an unused legacy message for tracing variable values
within the Piksi firmware and streaming those back to the host.


  """

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.payload = sbp.payload

  def __repr__(self):
    return fmt_repr(self)
 
    

msg_classes = {
  0x0010: MsgPrint,
  0x0011: MsgDebugVar,
}