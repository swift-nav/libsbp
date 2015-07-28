# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from threading import Thread

class Forwarder(Thread):
  """Forwarder

  The :class:`Forwarder` connects an iterable source of incoming
  SBP messages to a callable sink of outgoing SBP messages.  The source
  will typically be a :class:`Handler` which provides queueing and message
  filtering.  The :class:`Forwarder` runs its own thread iterating over the
  source messages and delivering them to the sink.  The thread is run in
  daemon mode and will be destroyed when the main thread exits, or the
  source stops iteration.

  Parameters
  ----------
  source : iterable of tuple(SBP, dict)
    Source of SBP messages.
  sink : callable (SBP, **metadata)
    Callable sink of SBP messages.

  """
  def __init__(self, source, sink):
    Thread.__init__(self, name="SBP Forwarder")
    self.daemon = True
    self._broken = False
    self._source = source
    self._sink = sink

  def run(self):
    for msg, metadata in self._source:
      if self._broken:
        break
      self._sink(msg, **metadata)

  def stop():
    self._broken = True
    try:
      self._source.breakiter()
    except:
      pass

