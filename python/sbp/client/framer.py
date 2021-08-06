# Copyright (C) 2015-2021 Swift Navigation Inc.
# Contact: https://support.swiftnav.com
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
import uuid
import six
import warnings


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
    verbose: boolean
      Increased verbosity of stdout / stderr. Default False
    dispatcher: function
      function to call on each deframed message
    skip_medata: boolean
      do not add "time" and "session-uuid" metadata
    sender_id_filter: list
      list of integer sender_ids to frame, with the exclusion of all others
    """

    def __init__(self,
                 read,
                 write,
                 verbose=False,
                 dispatcher=dispatch,
                 into_buffer=True,
                 skip_metadata=False,
                 sender_id_filter_list=[]):
        self._read = read
        self._write = write
        self._verbose = verbose
        self._broken = False
        self._dispatch = dispatcher
        self._session = str(uuid.uuid4())
        self._buffer = bytearray(16*1024)
        self._into_buffer = into_buffer
        self._skip_metadata = skip_metadata
        self._sender_id_filter_list = sender_id_filter_list

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

    def _readall(self, size):
        """
        Read until all bytes are collected.

        Parameters
        ----------
        size : int
          Number of bytes to read.
        """
        data = b""
        while len(data) < size:
            d = self._read(size - len(data))
            if not d or self._broken:
                raise StopIteration
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
                print("Host Side Unhandled byte: 0x%02x" % ord(preamble))
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
            if self._verbose:
                print("crc mismatch: 0x%04X 0x%04X" % (msg_crc, crc))
            return None
        if (len(self._sender_id_filter_list) == 0 or sender in self._sender_id_filter_list):
            msg = SBP(msg_type, sender, msg_len, data, crc)
            try:
                msg = self._dispatch(msg)
            except Exception as exc:
                warnings.warn("SBP dispatch error: %s" % (exc,))
            return msg
        else:
            return None

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
