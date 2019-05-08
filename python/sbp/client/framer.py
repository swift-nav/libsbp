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
import six
import sys
import traceback
import warnings

import numpy as np

if (sys.version_info > (3, 0)):
    _SBP_PREAMBLE = SBP_PREAMBLE
else:
    # In Python 2, memoryview index is presented as 'str'
    _SBP_PREAMBLE = chr(SBP_PREAMBLE)


class Framer(six.Iterator):
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

    def __init__(self,
                 read,
                 write,
                 readinto=None,
                 verbose=False,
                 dispatcher=dispatch,
                 into_buffer=True,
                 skip_metadata=False,
                 greedy=False):
        self._read = read
        self._readinto = readinto
        self._write = write
        self._verbose = verbose
        self._broken = False
        self._dispatch = dispatcher
        self._session = str(uuid.uuid4())
        self._buffer = np.zeros(16*1024, dtype=np.uint8)
        self._rx_buf = np.zeros(16*1024, dtype=np.uint8)
        self._rx_buf_unprocessed = 0
        self._rx_buf_idx = 0
        self._greedy = greedy
        self._into_buffer = into_buffer
        self._skip_metadata = skip_metadata

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
        return datetime.datetime.utcnow().isoformat() + 'Z'

    def __next__(self):
        msg = None
        while msg is None:
            try:
                msg = self._receive()
                if self._broken:
                    raise StopIteration
            except IOError:
                raise StopIteration

        metadata = {}
        if not self._skip_metadata:
            metadata['time'] = self._time()
            metadata['session-uid'] = self._session

        return (msg, metadata)

    def _readall(self, size, allow_empty=False):
        if getattr(self, '_readinto', None):
            return self._collect_into(size, allow_empty)
        else:
            return self._collect(size, allow_empty)

    @staticmethod
    def _shift(buf, n):
        """
        Optimized version of numpy.roll().

        From https://stackoverflow.com/a/42642326

        Parameters
        ----------
        buf : numpy array
        Buffer to shift.

        n : int
        The number of places by which elements are shifted.
        """
        res = np.empty_like(buf)
        if n > 0:
            res[n:] = buf[:-n]
        elif n < 0:
            res[:n] = buf[-n:]
        else:
            return buf

        return res

    def _collect(self, size, allow_empty=False):
        """
        Read until all bytes are collected.

        Parameters
        ----------
        size : int
          Number of bytes to read.
        """
        if self._rx_buf_unprocessed < size:
            if self._greedy:
                data = self._read(len(self._rx_buf) - self._rx_buf_unprocessed)
            else:
                data = self._read(size)

            l = len(data)

            while l < size:
                d = self._read(size - len(data))
                if not d or self._broken:
                    if allow_empty:
                        return None
                    raise StopIteration
                data += d

            #self._rx_buf = np.roll(self._rx_buf, -1 * self._rx_buf_idx)
            self._rx_buf = self._shift(self._rx_buf, -self._rx_buf_idx)
            self._rx_buf_idx = 0
            l = len(data)
            self._rx_buf[self._rx_buf_unprocessed:self._rx_buf_unprocessed + l] = bytearray(data)
            self._rx_buf_unprocessed += l

        mv = memoryview(self._rx_buf)[self._rx_buf_idx:self._rx_buf_idx + size]
        self._rx_buf_unprocessed -= size
        self._rx_buf_idx += size

        return mv

    def _collect_into(self, size, allow_empty=False):
        """
        Read until all bytes are collected.

        Parameters
        ----------
        size : int
          Number of bytes to read.
        """
        if self._rx_buf_unprocessed < size:
            if self._greedy:
                to_read = len(self._rx_buf) - self._rx_buf_unprocessed
            else:
                to_read = size - self._rx_buf_unprocessed

            # Bytes are read into the tail of the buffer. If the index is too
            # far to fit the new data, buffer needs to be rolled.
            free_tail = len(self._rx_buf) - self._rx_buf_idx
            if free_tail < to_read:
                self._rx_buf = self._shift(self._rx_buf, -self._rx_buf_idx)
                self._rx_buf_idx = 0

            while self._rx_buf_unprocessed < size:
                free_idx = self._rx_buf_idx + self._rx_buf_unprocessed
                mv = memoryview(self._rx_buf)[free_idx:free_idx + to_read]
                bytes_read = self._readinto(mv)
                if not bytes_read or self._broken:
                    if allow_empty:
                        return None
                    raise StopIteration
                self._rx_buf_unprocessed += bytes_read
                to_read -= bytes_read

        mv = memoryview(self._rx_buf)[self._rx_buf_idx:self._rx_buf_idx + size]
        self._rx_buf_unprocessed -= size
        self._rx_buf_idx += size
        return mv

    def _receive(self):
        """
        Read and build SBP message.
        """
        # preamble - allow empty to allow breaking before messages,
        # empty input
        preamble = self._readall(1, True)
        if not preamble:
            return None

        preamble = preamble[0]

        if preamble != _SBP_PREAMBLE:
            if self._verbose:
                print("Preamble failure")
            return None

        # hdr
        hdr = self._readall(5)
        msg_crc = crc16(hdr)
        msg_type, sender, msg_len = struct.unpack_from("<HHB", hdr, 0)
        try:
            # data + crc. Read them together so there's no chance of memoryview
            # changes in case the CRC is just at the edge of the internal buffer
            # roll.
            data_crc = self._readall(msg_len + 2)
            payload = data_crc[:-2]
            crc = data_crc[-2:]
            msg_crc = crc16(payload, msg_crc)
            crc, = struct.unpack_from("<H", crc, 0)
            if crc != msg_crc:
                if self._verbose:
                    print("crc mismatch: 0x%04X 0x%04X" % (msg_crc, crc))
                return None
            msg = self._dispatch(msg_type=msg_type)(sbp=None, sender=sender)
            # NOTE: This is a ref to memoryview, if payload is to be used
            #       after view has changed, you'd want a real copy of the data.
            msg.payload = payload
            msg.length = msg_len
            msg.crc = msg_crc
            msg.from_binary(msg.payload)
        except Exception as exc:
            warnings.warn("SBP dispatch error: %s" % (exc,))
            return None

        return msg

    def __call__(self, *msgs, **metadata):
        """
        Build and write SBP message.

        Parameters
        ----------
        msgs : SBP messages
          SBP messages to send.  Multiple messages are sent in one batch.
        metadata : dict
          Metadata for this batch of messages, e.g. `{'time': 'ISO 8601 str'}`
          (ignored for now).
        """
        index = 0
        if self._into_buffer:
            for msg in msgs:
                index += msg.into_buffer(self._buffer, index)
        else:
            for msg in msgs:
                msg_buff = msg.to_binary()
                buff_len = len(msg_buff)
                self._buffer[index:(index+buff_len)] = bytearray(msg_buff)
                index += buff_len
        self._write(memoryview(self._buffer)[:index])
