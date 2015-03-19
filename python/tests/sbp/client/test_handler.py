# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import io

from sbp.client.handler import *
from sbp                import SBP

class TestCallbackCounter(object):
  """
  Callable counter to count callbacks.
  """
  def __init__(self):
    self.value = 0

  def __call__(self, msg):
    self.call(msg)

  def call(self, msg):
    self.value += 1

def test_framer_receive_empty():
  source = io.BytesIO(b"")
  framer = Framer(source.read, None)
  assert framer.receive() == None

def test_framer_receive_bad_preamble():
  source = io.BytesIO(b"\x01")
  framer = Framer(source.read, None)
  assert framer.receive() == None

def test_framer_bad_crc():
  source = io.BytesIO(b"\x55\x15\x00\xda\x05\x0d\x9a\x99\x81\x41\x00\x40\xbb\x43\x51\x89\xda\x44\x0e\xeb\x00")
  framer = Framer(source.read, None)
  assert framer.receive() == None

def test_framer_ok():
  source = io.BytesIO(b"\x55\x15\x00\xda\x05\x0d\x9a\x99\x81\x41\x00\x40\xbb\x43\x51\x89\xda\x44\x0e\xeb\x4f")
  framer = Framer(source.read, None)
  msg = framer.receive()
  assert msg.msg_type == 0x15
  assert msg.sender == 1498
  assert msg.length == 13
  assert msg.crc == 0x4feb

def test_listener_thread_ok():
  counter = TestCallbackCounter()
  listener_thread = ReceiveThread(lambda: SBP(True, None, None, None, None), counter)
  listener_thread.start()
  assert listener_thread.is_alive()
  assert counter.value > 0
  listener_thread.stop()
  while listener_thread.is_alive():
    pass
  value = counter.value
  assert counter.value == value

def test_handler_callbacks():
  handler = Handler(None, None)
  global_counter1 = TestCallbackCounter()
  global_counter2 = TestCallbackCounter()
  msg_type_counter1 = TestCallbackCounter()
  msg_type_counter2 = TestCallbackCounter()
  handler.add_callback(global_counter1)
  handler.add_callback(global_counter2)
  handler.add_callback(global_counter2)
  handler.add_callback(msg_type_counter1, 0x55)
  handler.add_callback(msg_type_counter1, 0x55)
  handler.add_callback(msg_type_counter2, 0x66)
  handler.call(SBP(0x11, None, None, None, None))
  handler.call(SBP(0x55, None, None, None, None))
  assert global_counter1.value == 2
  assert global_counter2.value == 2
  assert msg_type_counter1.value == 1
  assert msg_type_counter2.value == 0
