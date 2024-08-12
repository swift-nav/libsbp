#!/usr/bin/env python
# Copyright (C) 2015-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.


"""
Telemetry messages reported by Starling engine. The messages include various
byproducts of state estimation and other logic across Starling and are aimed
at efficient issue diagnostics.
"""

import json

import construct

from sbp.msg import SBP, SENDER_ID
from sbp.utils import fmt_repr, exclude_fields, walk_json_dict, containerize
from sbp.gnss import GnssSignal

# Automatically generated from piksi/yaml/swiftnav/sbp/telemetry.yaml with generate.py.
# Please do not hand edit!


class TelemetrySV(object):
  """TelemetrySV.
  
  
  Parameters
  ----------
  az : int
    Azimuth angle (range 0..179)
  el : int
    Elevation angle (range -90..90)
  availability_flags : int
    Observation availability at filter update
  pseudorange_residual : int
    Pseudorange observation residual
  phase_residual : int
    Carrier-phase or carrier-phase-derived observation residual
  outlier_flags : int
    Reports if observation is marked as an outlier and is excluded from the
    update
  ephemeris_flags : int
    Ephemeris metadata
  correction_flags : int
    Reserved
  sid : GnssSignal
    GNSS signal identifier (16 bit)

  """
  _parser = construct.Struct(
                     'az' / construct.Int8ul,
                     'el' / construct.Int8sl,
                     'availability_flags' / construct.Int8ul,
                     'pseudorange_residual' / construct.Int16sl,
                     'phase_residual' / construct.Int16sl,
                     'outlier_flags' / construct.Int8ul,
                     'ephemeris_flags' / construct.Int8ul,
                     'correction_flags' / construct.Int8ul,
                     'sid' / GnssSignal._parser,)
  __slots__ = [
               'az',
               'el',
               'availability_flags',
               'pseudorange_residual',
               'phase_residual',
               'outlier_flags',
               'ephemeris_flags',
               'correction_flags',
               'sid',
              ]

  def __init__(self, payload=None, **kwargs):
    if payload:
      self.from_binary(payload)
    else:
      self.az = kwargs.pop('az')
      self.el = kwargs.pop('el')
      self.availability_flags = kwargs.pop('availability_flags')
      self.pseudorange_residual = kwargs.pop('pseudorange_residual')
      self.phase_residual = kwargs.pop('phase_residual')
      self.outlier_flags = kwargs.pop('outlier_flags')
      self.ephemeris_flags = kwargs.pop('ephemeris_flags')
      self.correction_flags = kwargs.pop('correction_flags')
      self.sid = kwargs.pop('sid')

  def __repr__(self):
    return fmt_repr(self)
  
  def from_binary(self, d):
    p = TelemetrySV._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))
    
SBP_MSG_TEL_SV = 0x0120
class MsgTelSv(SBP):
  """SBP class for message MSG_TEL_SV (0x0120).

  You can have MSG_TEL_SV inherit its fields directly
  from an inherited SBP object, or construct it inline using a dict
  of its fields.

  
  This message includes telemetry pertinent to satellite signals available to
  Starling.

  Parameters
  ----------
  sbp : SBP
    SBP parent object to inherit from.
  wn : int
    GPS week number
  tow : int
    GPS Time of Week
  n_obs : int
    Total number of observations. First nibble is the size of the sequence
    (n), second nibble is the zero-indexed counter (ith packet of n)
  origin_flags : int
    Flags to identify the filter type from which the telemetry is reported
    from
  sv_tel : array
    Array of per-signal telemetry entries
  sender : int
    Optional sender ID, defaults to SENDER_ID (see sbp/msg.py).

  """
  _parser = construct.Struct(
                   'wn' / construct.Int16ul,
                   'tow' / construct.Int32ul,
                   'n_obs' / construct.Int8ul,
                   'origin_flags' / construct.Int8ul,
                   'sv_tel' / construct.GreedyRange(TelemetrySV._parser),)
  __slots__ = [
               'wn',
               'tow',
               'n_obs',
               'origin_flags',
               'sv_tel',
              ]

  def __init__(self, sbp=None, **kwargs):
    if sbp:
      super( MsgTelSv,
             self).__init__(sbp.msg_type, sbp.sender, sbp.length,
                            sbp.payload, sbp.crc)
      self.from_binary(sbp.payload)
    else:
      super( MsgTelSv, self).__init__()
      self.msg_type = SBP_MSG_TEL_SV
      self.sender = kwargs.pop('sender', SENDER_ID)
      self.wn = kwargs.pop('wn')
      self.tow = kwargs.pop('tow')
      self.n_obs = kwargs.pop('n_obs')
      self.origin_flags = kwargs.pop('origin_flags')
      self.sv_tel = kwargs.pop('sv_tel')

  def __repr__(self):
    return fmt_repr(self)

  @staticmethod
  def from_json(s):
    """Given a JSON-encoded string s, build a message object.

    """
    d = json.loads(s)
    return MsgTelSv.from_json_dict(d)

  @staticmethod
  def from_json_dict(d):
    sbp = SBP.from_json_dict(d)
    return MsgTelSv(sbp, **d)

 
  def from_binary(self, d):
    """Given a binary payload d, update the appropriate payload fields of
    the message.

    """
    p = MsgTelSv._parser.parse(d)
    for n in self.__class__.__slots__:
      setattr(self, n, getattr(p, n))

  def to_binary(self):
    """Produce a framed/packed SBP message.

    """
    c = containerize(exclude_fields(self))
    self.payload = MsgTelSv._parser.build(c)
    return self.pack()

  def friendly_name(self):
    """Produces friendly human-readable name for this message

    """
    return "TEL SV"

  def into_buffer(self, buf, offset):
    """Produce a framed/packed SBP message into the provided buffer and offset.

    """
    self.payload = containerize(exclude_fields(self))
    self.parser = MsgTelSv._parser
    self.stream_payload.reset(buf, offset)
    return self.pack_into(buf, offset, self._build_payload)

  def to_json_dict(self):
    self.to_binary()
    d = super( MsgTelSv, self).to_json_dict()
    j = walk_json_dict(exclude_fields(self))
    d.update(j)
    return d
    

msg_classes = {
  0x0120: MsgTelSv,
}