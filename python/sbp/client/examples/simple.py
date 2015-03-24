# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Fergus Noble <fergus@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
the :mod:`sbp.client.examples.simple` module contains a basic example of
reading SBP messages from a serial port, decoding BASELINE_NED messages and
printing them out.
"""

from sbp.client.drivers.pyserial_driver import PySerialDriver
from sbp.client.handler import Handler
from sbp.navigation import SBP_MSG_BASELINE_NED, MsgBaselineNED

import time

def baseline_callback(msg):
  # This function is called every time we receive a BASELINE_NED message

  # First decode the SBP message in "msg" into a python object, the sbp library
  # has functions that do this for all the message types defined in the
  # specification.
  b = MsgBaselineNED(msg)

  # b now contains the decoded baseline information and
  # has fields with the same names as in the SBP docs

  # Print out the N, E, D coordinates of the baseline
  print "%.4f,%.4f,%.4f" % \
    (b.n * 1e-3, b.e * 1e-3, b.d * 1e-3)

def main():

  import argparse
  parser = argparse.ArgumentParser(description="Swift Navigation SBP Example.")
  parser.add_argument("-p", "--port",
                      default=['/dev/ttyUSB0'], nargs=1,
                      help="specify the serial port to use.")
  args = parser.parse_args()

  # Open a connection to Piksi using the default baud rate (1Mbaud)
  with PySerialDriver(args.port[0], 1000000) as driver:
    # Create a handler to connect our Piksi driver to our callbacks
    with Handler(driver.read, driver.write, True) as handler:
      # Add a callback for BASELINE_NED messages
      handler.add_callback(baseline_callback, msg_type=SBP_MSG_BASELINE_NED)
      handler.start()

      # Sleep until the user presses Ctrl-C
      try:
        while True:
          time.sleep(0.1)
      except KeyboardInterrupt:
        pass

if __name__ == "__main__":
  main()

