#!/usr/bin/env python
# Copyright (C) 2011-2014 Swift Navigation Inc.
# Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
Single dispatch of available SBP messages, keyed by msg_type.

"""

from construct.core import FieldError
import acquisition as acq
import navigation as nav
import observation as obs
import piksi as piksi
import standard as std
import tracking as track
import warnings

_SBP_TABLE = dict(nav.msg_classes.items() \
                  + obs.msg_classes.items() \
                  + acq.msg_classes.items() \
                  + track.msg_classes.items() \
                  + piksi.msg_classes.items() \
                  + std.msg_classes.items())

class InvalidSBPMessageType(NotImplementedError):
  """
  Base exception for messages with invalid message types.
  """

def dispatch(msg, table=_SBP_TABLE):
  """
  Dispatch an SBP message type based on its `msg_type` and parse its
  payload.

  Parameters
  ----------
  driver : :class:`SBP`
    A parsed SBP object.
  table : dict
    Any table mapping unique SBP message type IDs to SBP message
    constructors.

  Returns
  ----------
  SBP message with a parsed payload.

  """
  try:
    return table[msg.msg_type](msg)
  except KeyError:
    error_msg = "No message found for msg_type id %d for msg %s." \
                % (msg.msg_type, msg)
    raise InvalidSBPMessageType(error_msg)
  except FieldError:
    warnings.warn("SBP payload deserialization error! 0x%x" % msg.msg_type,
                  RuntimeWarning)
    return msg
