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

from sbp.msg import SBP
from sbp.client.loggers.base_logger import LogIterator
from sbp.client.loggers.json_logger import JSONLogIterator
from sbp.client.loggers.rotating_logger import RotatingFileLogger
from sbp.client.loggers.udp_logger import UdpLogger
from sbp.acquisition import MsgAcqResultDepA
from sbp.logging import MsgPrintDep
from sbp.table import _SBP_TABLE, dispatch
from sbp.table import InvalidSBPMessageType
import pytest
import six
from six.moves import socketserver
import threading
import os, tempfile, time
import warnings

def test_log():
  """
  Abstract interface won't work
  """
  log_datafile = "./data/serial_link_log_20150310-115522-test.log.dat"
  with open(log_datafile, 'r') as infile:
    with LogIterator(infile) as log:
      with pytest.raises(NotImplementedError) as exc_info:
        for msg, metadata in next(log):
          pass
  assert exc_info.value.args[0] == "next() not implemented!"

def _json_log(conventional, fetch_next):
  log_datafile = "./data/serial_link_log_20150310-115522-test.log.dat"
  count = 0
  with warnings.catch_warnings(record=True) as w:
    with open(log_datafile, 'r') as infile:
      with JSONLogIterator(infile, conventional=conventional) as log:
        for msg, metadata in fetch_next(log):
          assert type(metadata['time']) == six.text_type
          assert isinstance(msg, SBP) or issubclass(type(msg), SBP)
          count += 1
        warnings.simplefilter("always")
        assert len(w) == 0
  assert count == 2650

def test_json_log():
  """
  JSON log iterator sanity tests.
  """
  _json_log(conventional=False, fetch_next = lambda x : next(x))
  _json_log(conventional=True, fetch_next = lambda x : x)

def _non_utf8_json_log(conventional, fetch_next):
  log_datafile = "./data/serial_link_non_utf8.log.dat"

  with warnings.catch_warnings(record=True) as w:
    with open(log_datafile, 'r') as infile:
      with JSONLogIterator(infile, conventional=conventional) as log:
        for _, _ in fetch_next(log):
          pass
        warnings.simplefilter("always")
        assert len(w) == 1

def test_non_utf8_json_log():
  """
  JSON log iterator sanity tests.
  """
  _non_utf8_json_log(conventional=False, fetch_next = lambda x : next(x))
  _non_utf8_json_log(conventional=True, fetch_next = lambda x : x)

def _msg_print(conventional, fetch_next):
  log_datafile = "./data/serial_link_log_20150428-084729.log.dat"
  with open(log_datafile, 'r') as infile:
    with JSONLogIterator(infile, conventional=conventional) as log:
      with warnings.catch_warnings(record=True) as w:
        for _, _ in fetch_next(log):
          pass
        warnings.simplefilter("always")
        # Check for warnings.
        assert len(w) == 1
        assert issubclass(w[0].category, RuntimeWarning)
        assert str(w[0].message).startswith('Bad message parsing for line')

@pytest.mark.xfail
def test_msg_print():
  """
  """
  _msg_print(conventional=False, fetch_next = lambda x : next(x))
  _msg_print(conventional=True, fetch_next = lambda x : x)

def udp_handler(data):
  class MockRequestHandler(socketserver.BaseRequestHandler):
    def handle(self):
      assert data == self.request[0].strip()
  return MockRequestHandler

class MockServer(socketserver.ThreadingMixIn, socketserver.UDPServer):
  pass

def udp_server(handler):
  server = MockServer(("localhost", 0), handler)
  ip, port = server.server_address
  server_thread = threading.Thread(target=server.serve_forever)
  server_thread.daemon = True
  server_thread.start()
  return (ip, port)

def test_udp_logger():
  msg = SBP(1, 2, 3, b'abc', 4)
  handler = udp_handler(msg.pack())
  ip, port = udp_server(handler)
  with UdpLogger(ip, port) as udp:
    udp(msg)

def _rolling_json_log(conventional, fetch_next):
  """
  Rolling JSON log iterator sanity tests.
  """
  # Duration of test
  test_interval = 6
  # Rotating interval
  r_interval = 2
  try:
    with tempfile.NamedTemporaryFile(mode='w', delete=False) as tf:
      #print tf.name
      with RotatingFileLogger(tf.name, when='S', interval=r_interval) as log:
        t0 = time.time()
        t = time.time()
        msg = SBP(0x10, 2, 3, b'abc\n', 4)
        msgs = []
        while t - t0 < test_interval:
          log(msg, delta=t-t0, timestamp=t)
          if t - t0 <= r_interval:
            msgs.append(msg)
          t = time.time()
      i = 0
      with open(tf.name, 'r') as infile:
        with JSONLogIterator(infile, conventional=conventional) as log:
          for msg, _ in fetch_next(log):
            assert isinstance(msg, MsgPrintDep)
            assert msg.text == b"abc\n"
            i += 1
      assert i > 0
      assert i <= len(msgs)
  except Exception:
    raise
  finally:
    os.unlink(tf.name)

@pytest.mark.slow
def test_rolling_json_log():
  """
  Rolling JSON log iterator sanity tests.
  """
  _rolling_json_log(conventional=False, fetch_next = lambda x : next(x))
  _rolling_json_log(conventional=True, fetch_next = lambda x : x)
