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
the :mod:`sbp.client.examples.udp` module contains an example of reading SBP
messages from a serial port and sending them to a UDP socket.
"""

from ..drivers.pyserial_driver import PySerialDriver
from ..handler                 import Handler

import socket
import struct
import time

DEFAULT_SERIAL_PORT = "/dev/ttyUSB0"
DEFAULT_SERIAL_BAUD = 1000000

DEFAULT_UDP_ADDRESS = "127.0.0.1"
DEFAULT_UDP_PORT    = 13320

DEFAULT_LOG_FILENAME = time.strftime("sbp-%Y%m%d-%H%M%S.log")

def get_args():
  """
  Get and parse arguments.
  """
  import argparse
  parser = argparse.ArgumentParser(description="Swift Navigation SBP Example.")
  parser.add_argument("-s", "--serial-port",
                      default=[DEFAULT_SERIAL_PORT], nargs=1,
                      help="specify the serial port to use.")
  parser.add_argument("-b", "--baud",
                      default=[DEFAULT_SERIAL_BAUD], nargs=1,
                      help="specify the baud rate to use.")
  parser.add_argument("-a", "--address",
                      default=[DEFAULT_UDP_ADDRESS], nargs=1,
                      help="specify the serial port to use.")
  parser.add_argument("-p", "--udp-port",
                      default=[DEFAULT_UDP_PORT], nargs=1,
                      help="specify the baud rate to use.")
  return parser.parse_args()

def send_udp_callback_generator(udp, args):
  def send_udp_callback(msg):
    s = ""
    s += struct.pack("<BHHB", 0x55, msg.msg_type, msg.sender, msg.length)
    s += msg.payload
    s += struct.pack("<H", msg.crc)
    udp.sendto(s, (args.address[0], args.udp_port[0]))

  return send_udp_callback

def main():
  args = get_args()

  with PySerialDriver(args.serial_port[0], args.baud[0]) as driver:
    with Handler(driver.read, driver.write, args.verbose) as handler:
      udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
      handler.add_callback(send_udp_callback_generator(udp, args))
      handler.start()

      try:
        while True:
          time.sleep(0.1)
      except KeyboardInterrupt:
        pass

if __name__ == "__main__":
  main()

