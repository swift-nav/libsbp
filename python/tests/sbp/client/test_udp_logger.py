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

import pytest
import SocketServer
import threading

from sbp.client.loggers.udp_logger import UdpLogger

class MockServer(SocketServer.ThreadingMixIn, SocketServer.UDPServer):
  pass

class MockRequestHandler(SocketServer.BaseRequestHandler):
  pass

def setup_udp_server():
  server = MockServer(("localhost", 0), MockRequestHandler)
  ip, port = server.server_address
  server_thread = threading.Thread(target=server.serve_forever)
  server_thread.daemon = True
  server_thread.start()
  return (ip, port)

def test_udp_logger():
  ip, port = setup_udp_server()
  with UdpLogger(ip, port) as udp:
    udp(None)


