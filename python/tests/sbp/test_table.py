# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from sbp import SBP
from sbp.table import _SBP_TABLE, dispatch
from sbp.table import InvalidSBPMessageType
import pytest
import sbp.acquisition as acq
import sbp.logging as log
import warnings

def test_table_count():
  """
  Test number of available messages to deserialize.

  """
  number_of_messages = 47
  assert len(_SBP_TABLE) == number_of_messages

def test_available_messages():
  """
  Simple example with a limited dispatch table.

  """
  table = {acq.SBP_MSG_ACQ_RESULT: acq.MsgAcqResult,
           log.SBP_MSG_PRINT: log.MsgPrint}
  msg = SBP(msg_type=0x15, sender=1219, length=13,
            payload='\x92$yA\x00\x00\xbcC\x81\xc1\xf9\xc5\x1d')
  # TODO (Buro): Replace this message constructor once generated SBP
  # can support kwargs for constructor, instead of requiring SBP
  # object.
  assert dispatch(msg, table) == acq.MsgAcqResult(msg)
  msg = SBP(msg_type=0xB0, sender=1219, length=4, payload='v1.2', crc=0xCE01)
  with warnings.catch_warnings(record=True) as w:
    dispatch(msg, table)
    warnings.simplefilter("always")
    assert len(w) == 1
    assert issubclass(w[0].category, RuntimeWarning)
    assert str(w[0].message).find("No message found for msg_type id 176 for msg*")
