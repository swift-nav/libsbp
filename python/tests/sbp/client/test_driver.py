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

from httpretty import activate, is_enabled, GET, register_uri, Response
from sbp.client.drivers.network_drivers import HTTPDriver
from sbp.client.drivers.network_drivers import HTTPException
from sbp.client.drivers.pyserial_driver import PySerialDriver
from sbp.client import Handler, Framer
from sbp.logging import MsgPrintDep
import pytest
import SocketServer
import threading
import time

def tcp_handler(data):
  class MockRequestHandler(SocketServer.BaseRequestHandler):
    def handle(self):
      self.request.sendall(data)
  return MockRequestHandler

class MockServer(SocketServer.ThreadingMixIn, SocketServer.TCPServer):
  pass

def tcp_server(handler):
  server = MockServer(("localhost", 0), handler)
  ip, port = server.server_address
  server_thread = threading.Thread(target=server.serve_forever)
  server_thread.daemon = True
  server_thread.start()
  return (ip, port)

def test_tcp_logger():
  handler = tcp_handler(MsgPrintDep(text='abc').to_binary())
  ip, port = tcp_server(handler)
  port = "socket://%s:%s" % (ip, port)
  baud = 115200
  t0 = time.time()
  sleep = 0.1
  def assert_logger(s):
    assert s.preamble==0x55
    assert s.msg_type==0x10
    assert s.sender==66
    assert s.length==3
    assert s.payload=='abc'
    assert s.crc==0xDAEE
  with PySerialDriver(port, baud) as driver:
    with Handler(Framer(driver.read, None, verbose=False)) as link:
      link.add_callback(assert_logger)
      while True:
        if time.time() - t0 < sleep:
          break

BASE_STATION_URI = "http://broker.testing.skylark.swiftnav.com"

@activate
def test_http_test_pass():
  assert is_enabled()
  msg = MsgPrintDep(text='abcd')
  register_uri(GET,
               BASE_STATION_URI,
               msg.to_binary(),
               content_type="application/vnd.swiftnav.broker.v1+sbp")
  with HTTPDriver(device_uid="Swift22", url=BASE_STATION_URI) as driver:
    assert driver.read(size=255) == msg.to_binary()

@activate
def test_http_test_fail():
  assert is_enabled()
  msg = MsgPrintDep(text='abcd')
  register_uri(GET,
               BASE_STATION_URI,
               msg.to_binary(),
               content_type="application/vnd.swiftnav.broker.v1+sbp",
               status=400)
  with HTTPDriver(device_uid="Swift22", url=BASE_STATION_URI) as driver:
    with pytest.raises(RuntimeError) as exc_info:
      driver.read(size=255)
  assert exc_info.value.message.startswith("Request failed! With code 400:")

def mock_streaming_msgs(msgs, interval=0.1):
  for m in msgs:
    time.sleep(interval)
    yield m

@activate
def test_http_test_pass_streaming():
  assert is_enabled()
  msgs = [MsgPrintDep(text='foo'),
          MsgPrintDep(text='bar'),
          MsgPrintDep(text='baz')]
  register_uri(GET,
               BASE_STATION_URI,
               mock_streaming_msgs([m.to_binary() for m in msgs]),
               content_type="application/vnd.swiftnav.broker.v1+sbp",
               streaming=True)
  with HTTPDriver(device_uid="Swift22", url=BASE_STATION_URI) as driver:
    assert driver.read(size=255) == ''.join([m.to_binary() for m in msgs])

@activate
def test_http_test_pass_retry():
  assert is_enabled()
  msg = MsgPrintDep(text='abcd')
  responses = [Response(body="first response",
                        status=500,
                        content_type="application/vnd.swiftnav.broker.v1+sbp"),
               Response(body='second and last response',
                        status=200,
                        content_type="application/vnd.swiftnav.broker.v1+sbp")]
  register_uri(GET, BASE_STATION_URI, responses)
  with HTTPDriver(device_uid="Swift22", url=BASE_STATION_URI) as driver:
    driver.read(size=255)
