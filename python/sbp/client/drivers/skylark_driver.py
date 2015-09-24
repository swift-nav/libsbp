# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import requests

from .base_driver import BaseDriver

class SkylarkDriver(BaseDriver):
  """SkylarkDriver

  The :class:`SkylarkDriver` class reads SBP messages from Skylark for
  a device.

  Parameters
  ----------
  device_uid : uid
    Device unique id.

  """
  def __init__(self, device_uid):
    url = 'http://skylark.swiftnav.com'
    headers = {'Device-Uid': device_uid, 'Accept': 'application/sbp'}
    self.response = requests.get(url, stream=True, headers=headers)

  def read(self, size):
    return self.response.raw.read(size)
