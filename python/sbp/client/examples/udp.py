# Copyright (C) 2015-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
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

from sbp.client.drivers.pyserial_driver import PySerialDriver
from sbp.client import Handler, Framer
from sbp.client.loggers.udp_logger import UdpLogger

import time

DEFAULT_SERIAL_PORT = "/dev/ttyUSB0"
DEFAULT_SERIAL_BAUD = 1000000

DEFAULT_UDP_ADDRESS = "127.0.0.1"
DEFAULT_UDP_PORT = 13320

DEFAULT_LOG_FILENAME = time.strftime("sbp-%Y%m%d-%H%M%S.log")


def get_args():
    """
    Get and parse arguments.
    """
    import argparse
    parser = argparse.ArgumentParser(
        description="Swift Navigation SBP Example.")
    parser.add_argument(
        "-s",
        "--serial-port",
        default=[DEFAULT_SERIAL_PORT],
        nargs=1,
        help="specify the serial port to use.")
    parser.add_argument(
        "-b",
        "--baud",
        default=[DEFAULT_SERIAL_BAUD],
        nargs=1,
        help="specify the baud rate to use.")
    parser.add_argument(
        "-a",
        "--address",
        default=[DEFAULT_UDP_ADDRESS],
        nargs=1,
        help="specify the serial port to use.")
    parser.add_argument(
        "-p",
        "--udp-port",
        default=[DEFAULT_UDP_PORT],
        nargs=1,
        help="specify the baud rate to use.")
    return parser.parse_args()


def main():
    args = get_args()
    address = args.address[0]
    udp_port = args.udp_port[0]

    with PySerialDriver(args.serial_port[0], args.baud[0]) as driver:
        with Handler(Framer(driver.read, driver.write)) as handler:
            with UdpLogger(address, udp_port) as udp:
                handler.add_callback(udp)

                try:
                    while True:
                        time.sleep(0.1)
                except KeyboardInterrupt:
                    pass


if __name__ == "__main__":
    main()
