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

from sbp.client.drivers.network_drivers import TCPDriver
from sbp.client import Handler, Framer
from sbp.logging import MsgPrintDep, MsgLog, SBP_MSG_PRINT_DEP
import pytest
from six.moves import socketserver
import threading
import time
import socket

def tcp_handler(data):
  class MockRequestHandler(socketserver.BaseRequestHandler):
    def handle(self):
      self.request.sendall(data)
  return MockRequestHandler

class MockServer(socketserver.ThreadingMixIn, socketserver.TCPServer):
  pass

def tcp_server(handler):
  server = MockServer((socket.gethostbyname("localhost"), 0), handler)
  ip, port = server.server_address
  server_thread = threading.Thread(target=server.serve_forever)
  server_thread.daemon = True
  server_thread.start()
  time.sleep(1)  # wait for server to start
  return (ip, port)

def test_tcp_logger():
  handler = tcp_handler(MsgPrintDep(text=b'abc').to_binary())
  ip, port = tcp_server(handler)
  t0 = time.time()
  sleep = 0.1
  timeout = 5.0
  cb_context = {'assert_logger_called': False}
  def assert_logger(s, **metadata):
    cb_context['assert_logger_called'] = True
    assert s.preamble==0x55
    assert s.msg_type==0x10
    assert s.sender==66
    assert s.length==3
    assert s.payload==b'abc'
    assert s.crc==0xDAEE
  with TCPDriver(ip, port) as driver:
    with Handler(Framer(driver.read, None, verbose=False), autostart=False) as link:
      link.add_callback(assert_logger)
      link.start()
      while True:
        if time.time() - t0 > timeout or cb_context['assert_logger_called']:
          break
        time.sleep(sleep)
  assert cb_context['assert_logger_called'], "SBP msg callback function was not called"
