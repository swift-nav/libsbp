# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

import time

from sbp.client.drivers.pyserial_driver import PySerialDriver
from sbp.client.loggers.byte_logger     import ByteLogger
from sbp.client.handler                 import Handler

DEFAULT_SERIAL_PORT  = "/dev/ttyUSB0"
DEFAULT_SERIAL_BAUD  = 1000000
DEFAULT_LOG_FILENAME = time.strftime("sbp-%Y%m%d-%H%M%S.log")

def get_args():
  """
  Get and parse arguments.
  """
  import argparse
  parser = argparse.ArgumentParser(description="Swift Navigation SBP Bytes Example.")
  parser.add_argument("-s", "--serial-port",
                      default=[DEFAULT_SERIAL_PORT], nargs=1,
                      help="specify the serial port to use.")
  parser.add_argument("-b", "--baud",
                      default=[DEFAULT_SERIAL_BAUD], nargs=1,
                      help="specify the baud rate to use.")
  parser.add_argument("-f", "--filename",
                      default=[DEFAULT_LOG_FILENAME], nargs=1,
                      help="specify the filename to write to.")
  return parser.parse_args()

def main():
  args = get_args()

  with PySerialDriver(args.serial_port[0], args.baud[0]) as driver:
    with Handler(driver.read, driver.write) as link:
      with ByteLogger(args.filename[0]) as logger:
        link.add_callback(logger)
        link.start

        try:
          while True:
            time.sleep(0.1)
        except KeyboardInterrupt:
          pass

if __name__ == "__main__":
  main()
