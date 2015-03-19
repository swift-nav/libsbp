# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from .base_driver import BaseDriver

class PyFTDIDriver(BaseDriver):
  """
  PyFTDIDriver

  The :class:`PyFTDIDriver` class reads SBP messages from a serial port
  using the pyftdi driver.

  Parameters
  ----------
  port : string
    Path to port to read SBP messages from.
  baud : int
    Baud rate of serial port.
  """
  def __init__(self, baud):
    import pylibftdi
    try:
      handle = pylibftdi.Device()
      handle.baudrate = baud
      super(PyFTDIDriver, self).__init__(handle)
    except pylibftdi.FtdiError:
      raise
