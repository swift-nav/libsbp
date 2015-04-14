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
The :mod:`sbp.client.watchdog` module contains watchdog alarm functionality.
"""

import threading

class Watchdog:
  """
  Watchdog wraps a timer with a callback that can rearm the timer.

  Parameters
  ----------
  timeout : float
    timeout of timer in seconds
  alarm : callback
    function to call when/if timer expires
  """
  def __init__(self, timeout, alarm):
    self.timeout = timeout
    self.alarm = alarm
    self.timer = None

  def __call__(self, *args):
    self.call()

  def call(self):
    """
    Rearm the timer.
    """
    if self.timer:
      self.timer.cancel()
    self.timer = threading.Timer(self.timeout, self.alarm)
    self.timer.daemon = True
    self.timer.start()

