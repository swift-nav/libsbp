# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
The :mod:`sbp.client.handler` module contains classes related to
SBP message handling.
"""

import collections
import struct
import threading

from ..msg import crc16, SBP, SBP_PREAMBLE

class Framer(object):
  """
  Framer

  The :class:`Framer` class frames bytes into SBP messages.

  Parameters
  ----------
  read : port
    Stream of bytes to read from.
  write : port
    Stream of bytes to write to.
  """
  def __init__(self, read, write, verbose=False):
    self.read = read
    self.write = write
    self.verbose = verbose

  def readall(self, size):
    """
    Read until all bytes are collected.

    Parameters
    ----------
    size : int
      Number of bytes to read.
    """
    data = ""
    while len(data) < size:
      data += self.read(size - len(data))
    return data

  def receive(self):
    """
    Read and build SBP message.
    """
    # preamble - not readall(1) to allow breaking before messages, empty input
    preamble = self.read(1)
    if not preamble:
      return None
    elif ord(preamble) != SBP_PREAMBLE:
      if self.verbose:
        print "Host Side Unhandled byte: 0x%02x" % ord(preamble)
      return None

    # hdr
    hdr = self.readall(5)
    msg_crc = crc16(hdr)
    msg_type, sender, msg_len = struct.unpack("<HHB", hdr)

    # data
    data = self.readall(msg_len)
    msg_crc = crc16(data, msg_crc)

    # crc
    crc = self.readall(2)
    crc, = struct.unpack("<H", crc)
    if crc != msg_crc:
      print "crc mismatch: 0x%04X 0x%04X" % (msg_crc, crc)
      return None

    return SBP(msg_type, sender, msg_len, data, crc)

  def send(self, msg_type, data, sender):
    """
    Build and write SBP message.

    Parameters
    ----------
    msg_type : int
      SBP message type.
    data : string
      SBP message payload.
    sender : int
      SBP sender id.
    """
    msg = struct.pack("<BHHB", SBP_PREAMBLE, msg_type, sender, len(data))
    msg += data
    crc = crc16(msg[1:])
    msg += struct.pack("<H", crc)
    self.write(msg)

class ReceiveThread(threading.Thread):
  """
  ReceiveThread

  The :class:`ReceiveThread` class provides a processing thread for
  framing and handling SBP messages.

  Parameters
  ----------
  receive : fn
    Receiving function returns SBP messages.
  call : fn
    Callback functions.
  """
  def __init__(self, receive, call):
    super(ReceiveThread, self).__init__()
    self.receive = receive
    self.call = call
    self.daemon = True
    self.stopping = False

  def stop(self):
    """
    Stop the thread before the next message.
    """
    self.stopping = True

  def run(self):
    """
    Reading and handling loop.
    """
    while not self.stopping:
      try:
        msg = self.receive()
        if msg is not None:
          if msg.msg_type:
            self.call(msg)
      except SystemExit:
        break
      except:
        import traceback
        traceback.print_exc()

class Handler(object):
  """
  Handler

  The :class:`Handler` class provides an interface for connecting handlers
  to a driver providing SBP messages.

  Parameters
  ----------
  read : port
    Stream of bytes to read from.
  write : port
    Stream of bytes to write to.
  verbose : bool
    Print out errors.
  """
  def __init__(self, read, write, verbose=False):
    self.callbacks = collections.defaultdict(set)
    self.framer = Framer(read, write, verbose)
    self.receive_thread = ReceiveThread(self.framer.receive, self.call)

  def __enter__(self):
    self.start()
    return self

  def __exit__(self, *args):
    self.stop()

  def add_callback(self, callback, msg_type=None):
    """
    Add per message type or global callback.

    Parameters
    ----------
    callback : fn
      Callback function
    msg_type : int
      Message type to register callback against. Default `None` means global callback.
    """
    self.callbacks[msg_type].add(callback)

  def remove_callback(self, callback, msg_type=None):
    """
    Remove per message type of global callback.

    Parameters
    ----------
    callback : fn
      Callback function
    msg_type : int
      Message type to remove callback from. Default `None` means global callback.
    """
    self.callbacks[msg_type].remove(callback)

  def get_callbacks(self, msg_type):
    """
    Return all callbacks (global and per message type) for a message type.

    Parameters
    ----------
    msg_type : int
      Message type to return callbacks for.
    """
    return self.callbacks[None] | self.callbacks[msg_type]

  def call(self, msg):
    """
    Process message with all callbacks (global and per message type).
    """
    if msg.msg_type:
      for callback in self.get_callbacks(msg.msg_type):
        callback(msg)

  def start(self):
    """
    Start processing SBP messages with handlers.
    """
    self.receive_thread.start()

  def stop(self):
    """
    Stop processing SBP messages.
    """
    self.receive_thread.stop()

  def send(self, msg_type, data, sender=0x42):
    """
    Build and write SBP message.

    Parameters
    ----------
    msg_type : int
      SBP message type.
    data : string
      SBP message payload.
    sender : int
      SBP sender id.
    """
    self.framer.send(msg_type, data, sender)

  def wait(self, msg_type, timeout):
    """
    Wait for a SBP message.

    Parameters
    ----------
    msg_type : int
      SBP message type.
    timeout : float
      Waiting period
    """
    event = threading.Event()
    payload = None
    def cb(sbp_msg):
      payload = sbp_msg.payload
    self.add_callback(cb, msg_type)
    event.wait(timeout)
    self.remove(cb, msg_type)
    return payload
