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

from sbp.client.drivers.pyserial_driver import PySerialDriver
from sbp.client import Handler, Framer
from sbp.logging import MsgPrintDep
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
        if (time.time() - t0) < sleep:
          break
