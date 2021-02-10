# Copyright (C) 2015 - 2016 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from sbp.msg import SBP
from sbp.table import _SBP_TABLE, dispatch
from sbp.table import InvalidSBPMessageType
from sbp import acquisition as acq
from sbp import bootload as boot
from sbp import file_io as file_io
from sbp import flash as flash
from sbp import linux as linux
from sbp import logging as log
from sbp import navigation as nav
from sbp import observation as obs
from sbp import piksi as piksi
from sbp import settings as settings
from sbp import system as sys
from sbp import tracking as trac
from sbp import user as user
from sbp import imu as imu
from sbp import ext_events as ext_events
from sbp import ndb as ndb
from sbp import mag as mag
from sbp import vehicle as vehicle
from sbp import orientation as orientation
from sbp import sbas as sbas
from sbp import ssr as ssr
from sbp import solution_meta as solmeta

import pytest
import sbp.acquisition as acq
import sbp.logging as log
import warnings

def test_table_count():
  """
  Test number of available messages to deserialize.

  """
  number_of_messages = 195
  assert len(_SBP_TABLE) == number_of_messages

def test_table_unqiue_count():
  """
  Test number of messages in packages equals total number of messages.
  """
  number_of_messages = (len(acq.msg_classes)
                        + len(boot.msg_classes)
                        + len(file_io.msg_classes)
                        + len(flash.msg_classes)
                        + len(linux.msg_classes)
                        + len(log.msg_classes)
                        + len(nav.msg_classes)
                        + len(obs.msg_classes)
                        + len(piksi.msg_classes)
                        + len(settings.msg_classes)
                        + len(sys.msg_classes)
                        + len(trac.msg_classes)
                        + len(user.msg_classes)
                        + len(imu.msg_classes)
                        + len(ext_events.msg_classes)
                        + len(ndb.msg_classes)
                        + len(mag.msg_classes)
                        + len(vehicle.msg_classes)
                        + len(orientation.msg_classes)
                        + len(sbas.msg_classes)
                        + len(ssr.msg_classes)
                        + len(solmeta.msg_classes)
                         )
  assert len(_SBP_TABLE) == number_of_messages

def test_available_messages():
  """
  Simple example with a limited dispatch table.

  """
  table = {acq.SBP_MSG_ACQ_RESULT_DEP_A: acq.MsgAcqResultDepA,
           log.SBP_MSG_PRINT_DEP: log.MsgPrintDep}
  msg = SBP(msg_type=0x15, sender=1219, length=13,
            payload=b'\x92$yA\x00\x00\xbcC\x81\xc1\xf9\xc5\x1d')
  # TODO (Buro): Replace this message constructor once generated SBP
  # can support kwargs for constructor, instead of requiring SBP
  # object.
  assert dispatch(msg, table) == acq.MsgAcqResultDepA(msg)
  msg = SBP(msg_type=0xB0, sender=1219, length=4, payload='v1.2', crc=0xCE01)
  with warnings.catch_warnings(record=True) as w:
    dispatch(msg, table)
    warnings.simplefilter("always")
    assert len(w) == 1
    assert issubclass(w[0].category, RuntimeWarning)
    assert str(w[0].message).find("No message found for msg_type id 176 for msg*")
