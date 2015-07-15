# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import serial

def PySerialHandle(object):
  """
  PySerialSource

  The :class:`PySerialSource` class reads SBP messages from a serial port
  using the pyserial source.

  Parameters
  ----------
  port : string
    Path to port to read SBP messages from.
  baud : int
    Baud rate of serial port.
  timeout : int | float
    Timeout to serial source
  """
  return serial.Serial(port, baud, timeout)
