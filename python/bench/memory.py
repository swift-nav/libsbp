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

from guppy import hpy

def sbp_nav():
  import sbp.navigation as nav
  ll = []
  for i in range(0, 100000):
    ll.append(nav.MsgBaselineECEF(sender=0x42,
                                  tow=100,
                                  x=10,
                                  y=10,
                                  z=10,
                                  accuracy=0,
                                  n_sats=10,
                                  flags=1))
  print len(ll)
  h = hpy()
  print h.heap()

if __name__ == '__main__':
  sbp_nav()
