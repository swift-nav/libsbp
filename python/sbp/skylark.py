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
Messages from the Skylark corrections service.
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize

# Automatically generated from piksi/yaml/swiftnav/sbp/skylark.yaml with generate.py.
# Please do not hand edit!


SBP_MSG_ACKNOWLEDGE = 0x0FA0
class MsgAcknowledge(SBP):
  """SBP class for message MSG_ACKNOWLEDGE (0x0FA0).

  You can have MSG_ACKNOWLEDGE inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  request_id : int
    Echo of the request ID field from the corresponding CRA message, or 255 if
    no request ID was provided.
  area_id : int
    Echo of the Area ID field from the corresponding CRA message.
  response_code : int
    Reported status of the request.
  correction_mask_on_demand : int
    Contains the message group(s) that will be sent in response from the
    corresponding CRA correction mask. An echo of the correction mask field
    from the corresponding CRA message.
  correction_mask_stream : int
    For future expansion. Always set to 0.
  solution_id : int
    The solution ID of the instance providing the corrections.
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'request_id' / construct.Int8ul,
                   'area_id' / construct.Int32ul,
                   'response_code' / construct.Int8ul,
                   'correction_mask_on_demand' / construct.Int16ul,
                   'correction_mask_stream' / construct.Int16ul,
                   'solution_id' / construct.Int8ul,)
  __slots__ = [
               'request_id',
               'area_id',
               'response_code',
               'correction_mask_on_demand',
               'correction_mask_stream',
               'solution_id',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgAcknowledge,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgAcknowledge, self).__init__()
      self.msg_type = SBP_MSG_ACKNOWLEDGE
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.request_id = kwargs.pop('request_id')
      self.area_id = kwargs.pop('area_id')
      self.response_code = kwargs.pop('response_code')
      self.correction_mask_on_demand = kwargs.pop('correction_mask_on_demand')
      self.correction_mask_stream = kwargs.pop('correction_mask_stream')
      self.solution_id = kwargs.pop('solution_id')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgAcknowledge.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgAcknowledge(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgAcknowledge._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgAcknowledge._parser.build(c)
    return self.pack()

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgAcknowledge._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgAcknowledge, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0FA0: MsgAcknowledge,
}