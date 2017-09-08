# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

from ..msg import crc16, SBP, SBP_PREAMBLE
from ..table import dispatch

import struct
import datetime
import time
import uuid


class Framer(object):
    """
    Framer

    The :class:`Framer` class frames bytes into SBP messages.
    Implements the Python iterator protocol for received messages.

    Parameters
    ----------
    read : port
      Stream of bytes to read from.
    write : port
      Stream of bytes to write to.
    """

    def __init__(self, read, write, verbose=False, dispatcher=dispatch):
        self._read = read
        self._write = write
        self._verbose = verbose
        self._broken = False
        self._dispatch = dispatcher
        self._session = str(uuid.uuid4())

    def __iter__(self):
        self._broken = False
        return self

    def breakiter(self):
        """
        Break out of message iteration.
        May be called from another thread when some thread is blocked in next().
        """
        self._broken = True

    def _time(self):
        """
        Timestamp generator.

        Returns
        -------
        str : ISO 8601 format timestamp
        """
        return datetime.datetime.utcnow().isoformat()

    def next(self):
        msg = None
        while msg is None:
            try:
                msg = self._receive()
                if self._broken:
                    raise StopIteration
            except IOError:
                raise StopIteration
        return (msg, {'time': self._time(), 'session-uid': self._session})

    def _readall(self, size):
        """
        Read until all bytes are collected.

        Parameters
        ----------
        size : int
          Number of bytes to read.
        """
        data = ""
        while len(data) < size:
            d = self._read(size - len(data))
            if self._broken:
                raise StopIteration
            if not d:
                # NOTE (Buro/jgross): Force a yield here to another thread. In
                # case the stream fails midstream, the spinning here causes
                # the UI thread to lock up without yielding.
                time.sleep(0)
                continue
            data += d
        return data

    def _receive(self):
        """
        Read and build SBP message.
        """
        # preamble - not readall(1) to allow breaking before messages,
        # empty input
        preamble = self._read(1)
        if not preamble:
            return None
        elif ord(preamble) != SBP_PREAMBLE:
            if self._verbose:
                print "Host Side Unhandled byte: 0x%02x" % ord(preamble)
            return None
        # hdr
        hdr = self._readall(5)
        msg_crc = crc16(hdr)
        msg_type, sender, msg_len = struct.unpack("<HHB", hdr)
        # data
        data = self._readall(msg_len)
        msg_crc = crc16(data, msg_crc)
        # crc
        crc = self._readall(2)
        crc, = struct.unpack("<H", crc)
        if crc != msg_crc:
            print "crc mismatch: 0x%04X 0x%04X" % (msg_crc, crc)
            return None
        msg = SBP(msg_type, sender, msg_len, data, crc)
        try:
            msg = self._dispatch(msg)
        except:
            pass
        return msg

    def __call__(self, msg, **metadata):
        """
        Build and write SBP message.

        Parameters
        ----------
        msg : SBP message
          SBP message to send.
        metadata : dict
          {'time': 'ISO 8601 str'} (ignored for now)
        """
        self._write(msg.to_binary())
