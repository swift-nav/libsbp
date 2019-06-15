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

from sbp.jit import acquisition as acq
from sbp.jit import bootload as boot
from sbp.jit import file_io as file_io
from sbp.jit import flash as flash
from sbp.jit import linux as linux
from sbp.jit import logging as log
from sbp.jit import navigation as nav
from sbp.jit import observation as obs
from sbp.jit import piksi as piksi
from sbp.jit import settings as settings
from sbp.jit import system as sys
from sbp.jit import tracking as trac
from sbp.jit import ext_events as ext_events
from sbp.jit import user as user
from sbp.jit import imu as imu
from sbp.jit import mag as mag
from sbp.jit import ndb as ndb
from sbp.jit import vehicle as vehicle
from sbp.jit import orientation as orientation
from sbp.jit import sbas as sbas
from sbp.jit import ssr as ssr


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


def dispatch(msg_type, table=_SBP_TABLE):
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
    return table[msg_type]
