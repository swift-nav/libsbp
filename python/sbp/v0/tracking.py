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
Satellite code and carrier-phase tracking messages from the device.

"""

from construct import *
import json
from sbp.msg import SBP
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
import six

# Automatically generated from piksi/yaml/swiftnav/sbp/tracking.yaml with generate.py.
# Please do not hand edit!


class TrackingChannelState(object):
  """TrackingChannelState.
  
  Tracking channel state for a specific satellite PRN and measured
signal power.

  
  Parameters
  ----------
  state : int
    Status of tracking channel
  prn : int
    PRN-1 being tracked
  cn0 : float
    Carrier-to-noise density

  """
  _parser = Embedded(Struct("TrackingChannelState",
                     ULInt8('state'),
                     ULInt8('prn'),
                     LFloat32('cn0'),))

  def __init__(self, payload):
    self.from_binary(payload)

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = TrackingChannelState._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    return TrackingChannelState.build(self.__dict__)
    
SBP_MSG_TRACKING_STATE = 0x0016
class MsgTrackingState(SBP):
  """SBP class for message MSG_TRACKING_STATE (0x0016).

  You can have MSG_TRACKING_STATE inherent its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  The tracking message returns a variable-length array of tracking
channel states. It reports status and snr power measurements for
all tracked satellites.


  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  states : array
    Satellite tracking channel state
  sender : int
    Optional sender ID, defaults to 0

  """
  _parser = Struct("MsgTrackingState",
                   OptionalGreedyRange(Struct('states', TrackingChannelState._parser)),)

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      self.__dict__.update(sbp.__dict__)
      self.from_binary(sbp.payload)
    else:
      super( MsgTrackingState, self).__init__()
      self.msg_type = SBP_MSG_TRACKING_STATE
      self.sender = kwargs.pop('sender', 0)
      self.states = kwargs.pop('states')

  def __repr__(self):
    return fmt_repr(self)
 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgTrackingState._parser.parse(d)
    self.__dict__.update(dict(p.viewitems()))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgTrackingState._parser.build(c)
    return self.pack()

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    sbp = SBP.from_json_dict(d)
    return MsgTrackingState(sbp)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTrackingState, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0016: MsgTrackingState,
}