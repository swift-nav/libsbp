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

from httpretty import activate, is_enabled, GET, PUT, register_uri, Response
from sbp.client.drivers.network_drivers import HTTPDriver
from sbp.client.drivers.network_drivers import HTTPException
from sbp.client.drivers.pyserial_driver import PySerialDriver
from sbp.client import Handler, Framer
from sbp.logging import MsgPrintDep, MsgLog, SBP_MSG_PRINT_DEP
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
               content_type="application/vnd.swiftnav.broker.v1+sbp2")
  register_uri(PUT,
               BASE_STATION_URI,
               '',
               content_type="application/vnd.swiftnav.broker.v1+sbp2")
  with HTTPDriver(device_uid="Swift22", url=BASE_STATION_URI) as driver:
    assert not driver.read_ok
    assert driver.connect_read()
    assert driver.read_ok
    assert driver.read(size=255) == msg.to_binary()
    with pytest.raises(IOError):
      assert driver.read(size=255)
    assert not driver.read_close()
    assert driver.read_response is None
    assert not driver.read_ok
    with pytest.raises(ValueError):
      driver.read(size=255)
  with HTTPDriver(device_uid="Swift22", url=BASE_STATION_URI) as http:
    with Handler(Framer(http.read, http.write, False)) as link:
      def tester(sbp_msg, **metadata):
        assert sbp_msg.payload == msg.payload
      link.add_callback(SBP_MSG_PRINT_DEP, tester)
      t0 = time.time()
      sleep = 0.1
      while True:
        if time.time() - t0 < sleep:
          break

@activate
def test_http_test_fail():
  assert is_enabled()
  msg = MsgPrintDep(text='abcd')
  register_uri(GET,
               BASE_STATION_URI,
               msg.to_binary(),
               content_type="application/vnd.swiftnav.broker.v1+sbp2",
               status=400)
  register_uri(PUT,
               BASE_STATION_URI,
               '',
               content_type="application/vnd.swiftnav.broker.v1+sbp2",
               status=400)
  with HTTPDriver(device_uid="Swift22", url=BASE_STATION_URI) as driver:
    assert not driver.connect_read()
    assert not driver.read_ok
    with pytest.raises(IOError):
      driver.read(size=255)

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
               content_type="application/vnd.swiftnav.broker.v1+sbp2",
               streaming=True)
  register_uri(PUT,
               BASE_STATION_URI,
               body='',
               content_type="application/vnd.swiftnav.broker.v1+sbp2",
               streaming=True)
  with HTTPDriver(device_uid="Swift22", url=BASE_STATION_URI) as driver:
    assert driver.connect_read()
    assert driver.read_ok
    assert driver.read(size=255) == ''.join([m.to_binary() for m in msgs])
    assert driver.read(size=255) == ''
    assert not driver.read_close()
    assert driver.read_response is None
    assert not driver.read_ok
    with pytest.raises(ValueError):
      driver.read(size=255)

@activate
def test_http_test_pass_retry():
  assert is_enabled()
  msg = MsgPrintDep(text='abcd')
  get_responses = [Response(body="first response",
                            status=500,
                            content_type="application/vnd.swiftnav.broker.v1+sbp2"),
                   Response(body='second and last response',
                            status=200,
                            content_type="application/vnd.swiftnav.broker.v1+sbp2")]
  post_responses = [Response(body="",
                             status=500,
                             content_type="application/vnd.swiftnav.broker.v1+sbp2"),
                    Response(body='',
                             status=200,
                             content_type="application/vnd.swiftnav.broker.v1+sbp2")]
  register_uri(GET, BASE_STATION_URI, get_responses)
  register_uri(PUT, BASE_STATION_URI, post_responses)
  with HTTPDriver(device_uid="Swift22", url=BASE_STATION_URI) as driver:
    with pytest.raises(ValueError):
      driver.read(size=255)
    assert driver.connect_read()
    assert driver.read(size=255)
