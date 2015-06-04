#!/usr/bin/env python
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
from sbp.client.loggers.base_logger import LogIterator
from sbp.client.loggers.json_logger import JSONLogIterator, MultiJSONLogIterator
from sbp.client.loggers.pickle_logger import PickleLogIterator
from sbp.client.loggers.device_iterator import DeviceIterator
from sbp.logging import SBP_MSG_PRINT
from sbp.acquisition import SBP_MSG_ACQ_RESULT, MsgAcqResult
from sbp.table import _SBP_TABLE, dispatch
from sbp.table import InvalidSBPMessageType
from sbp.client.handler import Handler
import pytest
import warnings

# Apparently the log tests were actually saved in their dispatched
# types instead of raw SBP objects.
#
# def rewrite():
#   import cPickle as pickle
#   log_datafile = "./data/serial_link_log_20141125-150750_test1.log.dat"
#   new_datafile = open("./data/serial_link_log_20141125-150750_test2.log.dat", 'w')
#   protocol = 2
#   with PickleLogIterator(log_datafile) as log:
#     for delta, timestamp, msg in log.next():
#       sbp = SBP(msg.msg_type, msg.sender, msg.length, msg.payload, msg.crc)
#       pickle.dump((delta, timestamp, sbp), new_datafile, protocol)
#   print "Done!"
# rewrite()

def test_log():
  """
  Abstract interface won't work
  """
  log_datafile = "./data/serial_link_log_20141125-150750_test2.log.dat"
  with LogIterator(log_datafile) as log:
    with pytest.raises(NotImplementedError) as exc_info:
      for delta, timestamp, msg in log.next():
        pass
  assert exc_info.value.message == "next() not implemented!"

def test_pickle_log():
  """
  pickle log iterator sanity tests.
  """
  log_datafile = "./data/serial_link_log_20141125-150750_test2.log.dat"
  count = 0
  with PickleLogIterator(log_datafile) as log:
    with warnings.catch_warnings(record=True) as w:
      for delta, timestamp, msg in log.next():
        assert type(delta) == int
        assert type(timestamp) == int
        assert isinstance(msg, SBP)
        count += 1
      warnings.simplefilter("always")
      # Check for warnings.
      assert len(w) == 1
      assert issubclass(w[0].category, RuntimeWarning)
      assert "SBP payload deserialization error! 0x18" in w[0].message
    assert count == 1111

def test_basic_pickle_log():
  """
  pickle log iterator sanity tests with a normal handle.
  """
  log_datafile = "./data/serial_link_log_20141125-150750_test2.log.dat"
  count = 0
  with PickleLogIterator(log_datafile) as log:
    for delta, timestamp, msg in log.next():
      assert type(delta) == int
      assert type(timestamp) == int
      assert isinstance(msg, SBP)
      count += 1
  assert count == 1111

def test_json_log():
  """
  JSON log iterator sanity tests.
  """
  log_datafile = "./data/serial_link_log_20150310-115522-test.log.dat"
  count = 0
  with warnings.catch_warnings(record=True) as w:
    with JSONLogIterator(log_datafile) as log:
      for delta, timestamp, msg in log.next():
        assert type(delta) == int
        assert type(timestamp) == int
        assert isinstance(msg, SBP) or issubclass(type(msg), SBP)
        count += 1
      warnings.simplefilter("always")
      assert len(w) == 0
  assert count == 2650

def test_pickle_log_missing():
  """
  Remove a key from the dispatch and make sure that the iterator
  chokes.

  """
  log_datafile = "./data/serial_link_log_20141125-150750_test2.log.dat"
  new_table = _SBP_TABLE.copy()
  new_table.pop(SBP_MSG_PRINT, None)
  d = lambda msg: dispatch(msg, table=new_table)
  with PickleLogIterator(log_datafile, dispatcher=d) as log:
    with warnings.catch_warnings(record=True) as w:
      for delta, timestamp, msg in log.next():
        pass
    warnings.simplefilter("always")
    assert len(w) == 13
    for x in w:
      assert issubclass(x.category, RuntimeWarning)
      assert str(x.message).find("No message found for msg_type id 16*")

def test_multi_json_log():
  """
  Multi JSON log iterator sanity tests.
  """
  log_datafiles = ['./data/serial_link_log_20150310-115522-test.log.dat',
                   './data/serial_link_log_20150423-154336_test.log.dat']
  handles = [open(f, 'r') for f in log_datafiles]
  count = 0
  past = 0
  with warnings.catch_warnings(record=True) as w:
    with MultiJSONLogIterator(handles) as log:
      for delta, timestamp, metadata, msg in log.next():
        assert type(delta) == int
        assert type(timestamp) == int
        assert isinstance(msg, SBP) or issubclass(type(msg), SBP)
        assert type(metadata) == dict
        assert not metadata
        assert timestamp >= past
        past = timestamp
        count += 1
      warnings.simplefilter("always")
      assert len(w) == 0
  assert count == 2650 + 1451

def test_msg_print():
  """
  """
  log_datafile = "./data/serial_link_log_20150428-084729.log.dat"
  with JSONLogIterator(log_datafile) as log:
    with warnings.catch_warnings(record=True) as w:
      for delta, timestamp, msg in log.next():
        pass
      warnings.simplefilter("always")
      # Check for warnings.
      assert len(w) == 1
      assert issubclass(w[0].category, RuntimeWarning)
      assert str(w[0].message).startswith('Bad message parsing for line')

def test_device_iterator():
  """
  device iterator sanity tests.
  """
  log_datafile = "data/one_msg.bin"
  handle = open(log_datafile, 'r')
  myhandler = Handler(handle.read, None, verbose=True)
  mydevice_iterator = DeviceIterator(myhandler, 0.5)
  myhandler.start()
  for delta, timestamp, msg in mydevice_iterator:
    assert delta > 0
    assert timestamp >0
    assert type(msg) == MsgAcqResult
