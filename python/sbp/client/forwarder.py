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
  def __init__(self, source, sink):
    Thread.__init__(self, name="SBP Forwarder")
    self.daemon = True
    self._broken = False
    self._source = source
    self._sink = sink

  def run(self):
    for msg in self._source:
      if self._broken:
        break
      self._sink(*msg)

  def stop():
    self._broken = True
    try:
      self._source.breakiter()
    except: pass

