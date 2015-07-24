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
import itertools
import time
import threading
import gc

from sbp.client import *
from sbp.msg            import SBP
from sbp.logging import MsgLog

class TestCallbackCounter(object):
  """
  Callable counter to count callbacks.
  """
  def __init__(self):
    self.value = 0

  def __call__(self, d, t, msg):
    self.call(msg)

  def call(self, msg):
    self.value += 1

class TestCallbackSemaphore(object):
  """
  Callable semaphore for callbacks.
  """
  def __init__(self):
    self.sema = threading.Semaphore(0)

  def __call__(self, msg):
    self.call(msg)

  def call(self, msg):
    self.sema.release()

def test_framer_receive_empty():
  source = io.BytesIO(b"")
  framer = FrameReceiver(source.read, None)
  assert framer._receive() == None

def test_framer_receive_bad_preamble():
  source = io.BytesIO(b"\x01")
  framer = FrameReceiver(source.read, None)
  assert framer._receive() == None

def test_framer_bad_crc():
  source = io.BytesIO(b"\x55\x15\x00\xda\x05\x0d\x9a\x99\x81\x41\x00\x40\xbb\x43\x51\x89\xda\x44\x0e\xeb\x00")
  framer = FrameReceiver(source.read, None)
  assert framer._receive() == None

def test_framer_ok():
  source = io.BytesIO(b"\x55\x15\x00\xda\x05\x0d\x9a\x99\x81\x41\x00\x40\xbb\x43\x51\x89\xda\x44\x0e\xeb\x4f")
  framer = FrameReceiver(source.read, None)
  msg = framer._receive()
  assert msg.msg_type == 0x15
  assert msg.sender == 1498
  assert msg.length == 13
  assert msg.crc == 0x4feb

def until(p, limit=1000):
  for i in itertools.count():
    if p():
      break
    time.sleep(0.1)
    assert i < limit

def test_handler_callbacks():
  handler = ReceiveHandler(())
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
  handler._call(0, 0, SBP(0x11, None, None, None, None))
  handler._call(0, 0, SBP(0x55, None, None, None, None))
  assert global_counter1.value == 2
  assert global_counter2.value == 2
  assert msg_type_counter1.value == 1
  assert msg_type_counter2.value == 0
  handler.remove_callback(global_counter1)
  handler.remove_callback(global_counter2)
  handler.remove_callback(msg_type_counter1, 0x55)
  handler.remove_callback(msg_type_counter2, 0x66)
  handler._call(0, 0, SBP(0x11, None, None, None, None))
  handler._call(0, 0, SBP(0x55, None, None, None, None))
  assert global_counter1.value == 2
  assert global_counter2.value == 2
  assert msg_type_counter1.value == 1
  assert msg_type_counter2.value == 0

def test_multiple_handler_callbacks():
  handler = ReceiveHandler(())
  msg_type_counter1 = TestCallbackCounter()
  msg_type_counter2 = TestCallbackCounter()
  handler.add_callback(msg_type_counter1, [0x55, 0x66])
  handler.add_callback(msg_type_counter2, [0x11, 0x55])
  handler._call(0, 0, SBP(0x11, None, None, None, None))
  handler._call(0, 0, SBP(0x55, None, None, None, None))
  assert msg_type_counter1.value == 1
  assert msg_type_counter2.value == 2
  handler.remove_callback(msg_type_counter1, [0x55, 0x66])
  handler.remove_callback(msg_type_counter2, [0x11, 0x55])
  handler._call(0, 0, SBP(0x11, None, None, None, None))
  handler._call(0, 0, SBP(0x55, None, None, None, None))
  assert msg_type_counter1.value == 1
  assert msg_type_counter2.value == 2

def test_child_iter():
  msgs = ((0, 0, MsgLog(level=1, text="Hello")),
          (0, 0, MsgLog(level=1, text="Hello")),
          (0, 0, MsgLog(level=1, text="Hello")))
  handler = ReceiveHandler(msgs)
  def latestart():
    time.sleep(0.1)
    handler.start()
  threading.Thread(target=latestart).start()
  recvd = tuple(handler)
  assert recvd == msgs

def test_filter():
  msgs = ((0, 0, SBP(0x11, None, None, None, None)),
          (0, 0, SBP(0x33, None, None, None, None)),
          (0, 0, SBP(0x55, None, None, None, None)))
  handler = ReceiveHandler(msgs)
  def latestart():
    time.sleep(0.1)
    handler.start()
  threading.Thread(target=latestart).start()
  middle = tuple(handler.filter(0x33))
  assert len(middle) == 1
  assert middle[0] == msgs[1]

def test_dead_gc():
  handler = ReceiveHandler(((0, 0, SBP(0x11, None, None, None, None)),))
  def latestart():
    time.sleep(0.1)
    handler.start()
  thread = threading.Thread(target=latestart)
  thread.start()
  iter(handler) # Dead iterator, should be gc'd
  xx = iter(handler)
  thread.join()
  handler._receive_thread.join()
  gc.collect()
  assert [sink() for sink in handler._sinks] == [xx]

def test_late_iter():
  handler = ReceiveHandler(())
  handler.start()
  assert tuple(handler) == ()

