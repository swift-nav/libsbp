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

class PySerialDriver(BaseDriver):
  """
  PySerialDriver

  The :class:`PySerialDriver` class reads SBP messages from a serial port
  using the pyserial driver.

  Parameters
  ----------
  port : string
    Path to port to read SBP messages from.
  baud : int
    Baud rate of serial port.
  """
  def __init__(self, port, baud):
    import serial
    try:
      handle = serial.Serial(port, baud, timeout=1)
      super(PySerialDriver, self).__init__(handle)
    except (OSError, serial.SerialException):
      print
      print "Serial device '%s' not found" % port
      print "The following serial devices were detected:"
      print
      import serial.tools.list_ports
      for (name, desc, _) in serial.tools.list_ports.comports():
        if desc[0:4] == "ttyS":
          continue
        if name == desc:
          print "\t%s" % name
        else:
          print "\t%s (%s)" % (name, desc)
      print
      raise SystemExit

  def read(self, size):
    """
    Read wrapper.

    Parameters
    ----------
    size : int
      Number of bytes to read.
    """
    import serial
    try:
      return self.handle.read(size)
    except (OSError, serial.SerialException):
      print
      print "Piksi disconnected"
      print
      raise SystemExit
