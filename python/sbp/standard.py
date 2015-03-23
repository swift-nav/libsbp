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

# Automatically generated from piksi/yaml/swiftnav/sbp/standard.yaml
# with generate.py at 2015-03-23 14:30:01.613492. Please do not hand edit!


SBP_MSG_STARTUP = 0xFF00
class MsgStartup(SBP):
  """SBP class for message MSG_STARTUP (0xFF00).
  
  The system start-up message is sent once on system start-up. It is
intended to be used to notify the host or other attached devices that
the system has started and is now ready to respond to commands or
configuration requests.


  Parameters
  ----------
  reserved : int
    Reserved

  """
  _parser = Struct("MsgStartup",
                   ULInt32('reserved'),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgStartup._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgStartup.build(self.__dict__)
    
SBP_MSG_HEARTBEAT = 0xFFFF
class MsgHeartbeat(SBP):
  """SBP class for message MSG_HEARTBEAT (0xFFFF).
  
  The heartbeat message is sent periodically to inform the host or
other attached devices that the system is running. It is intended to
be used to monitor for system malfunctions and also contains
status flags that indicate to the host the status of the system and
if it is operating correctly.

The system error flag is used to indicate that an error has occurred in
the system. To determine the source of the error the remaining error
flags should be inspected.


  Parameters
  ----------
  flags : int
    Status flags

  """
  _parser = Struct("MsgHeartbeat",
                   ULInt32('flags'),)

  def __init__(self, sbp):
    self.__dict__.update(sbp.__dict__)
    self.from_binary(sbp.payload)

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    p = MsgHeartbeat._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return MsgHeartbeat.build(self.__dict__)
    

msg_classes = {
  0xFF00: MsgStartup,
  0xFFFF: MsgHeartbeat,
}

def sbp_decode(t, d):
  return msg_classes[t](d)