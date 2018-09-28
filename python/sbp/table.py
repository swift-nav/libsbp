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

from construct.core import FormatFieldError
from . import acquisition as acq
from . import bootload as boot
from . import file_io as file_io
from . import flash as flash
from . import linux as linux
from . import logging as log
from . import navigation as nav
from . import observation as obs
from . import piksi as piksi
from . import settings as settings
from . import system as sys
from . import tracking as trac
from . import ext_events as ext_events
from . import user as user
from . import imu as imu
from . import mag as mag
from . import ndb as ndb
from . import vehicle as vehicle
from . import orientation as orientation
from . import sbas as sbas
from . import ssr as ssr

import warnings

_SBP_TABLE = dict(list(acq.msg_classes.items())
                  + list(boot.msg_classes.items())
                  + list(file_io.msg_classes.items())
                  + list(flash.msg_classes.items())
                  + list(linux.msg_classes.items())
                  + list(log.msg_classes.items())
                  + list(nav.msg_classes.items())
                  + list(obs.msg_classes.items())
                  + list(piksi.msg_classes.items())
                  + list(settings.msg_classes.items())
                  + list(sys.msg_classes.items())
                  + list(trac.msg_classes.items())
                  + list(user.msg_classes.items())
                  + list(imu.msg_classes.items())
                  + list(mag.msg_classes.items())
                  + list(ext_events.msg_classes.items())
                  + list(ndb.msg_classes.items())
                  + list(vehicle.msg_classes.items())
                  + list(orientation.msg_classes.items())
                  + list(sbas.msg_classes.items())
                  + list(ssr.msg_classes.items())
                  )

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
    warn = "No message found for msg_type id %d for msg %s." \
           % (msg.msg_type, msg)
    warnings.warn(warn, RuntimeWarning)
    return msg
  except FormatFieldError:
    warnings.warn("SBP payload deserialization error! 0x%x" % msg.msg_type,
                  RuntimeWarning)
    return msg
