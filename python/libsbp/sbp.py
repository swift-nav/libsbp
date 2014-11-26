#!/usr/bin/env python
# Copyright (C) 2011-2014 Swift Navigation Inc.
# Contact: Fergus Noble <fergus@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

SBP_PREAMBLE = 0x55

class SBP(object):
  def __init__(self, msg_type=None, sender=None, length=None, payload=None, crc=None):
    self.preamble = SBP_PREAMBLE
    self.msg_type = msg_type
    self.sender = sender
    self.length = length
    self.payload = payload
    self.crc = crc

  def __repr__(self):
    p = (self.preamble, self.msg_type, self.sender, self.length,
         self.payload, self.crc)
    fmt = "<SBP (preamble=0x%X, msg_type=0x%X, sender=%s, length=%d, payload=%s, crc=0x%X)>"
    return fmt % p
