# Copyright (C) 2015-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from .base_logger import BaseLogger
import socket


class UdpLogger(BaseLogger):
    """
    UdpLogger

    The :class:`UdpLogger` logs SBP messages over UDP.

    Parameters
    ----------
    address : string
      IP Address to send UDP packets to.
    port : int
      IP Port to send UDP packets to.
    """

    def __init__(self, address, port):
        self.handle = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.address = address
        self.port = port

    def __call__(self, msg, **metadata):
        self.call(msg, **metadata)

    def fmt_msg(self, msg, **metadata):
        return msg.pack()

    def flush(self):
        pass

    def call(self, msg, **metadata):
        self.handle.sendto(
            self.fmt_msg(msg, **metadata), (self.address, self.port))
